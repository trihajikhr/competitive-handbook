---
obsidianUIMode: preview
note_type: latihan
latihan: Cari Node yang Jaraknya K dari Daun
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-07-04T21:04:00
---
---
# Cari Node yang Jaraknya K dari Daun


Diberikan sebuah **binary tree**, cari semua node yang jaraknya **tepat K** dari **setiap daun** (leaf).  
Jika satu node memenuhi kriteria dari lebih dari satu daun, tetap hanya dihitung sekali.


## 🧠 Definisi

- Sebuah **daun** adalah node tanpa anak kiri dan kanan.
    
- **Jarak K** artinya ada **K langkah naik** dari daun ke atas.
    

## 📥 Input Format

- Baris pertama: satu bilangan bulat `n` – jumlah elemen array pembentuk tree.
    
- Baris kedua: `n` bilangan bulat – elemen array tree secara level-order.
    
    - Gunakan `-1` untuk menunjukkan bahwa node kosong (null).
        
- Baris ketiga: bilangan `k` – jarak dari daun yang dimaksud.


## 📤 Output Format

- Cetak node-node yang jaraknya tepat `k` dari **setidaknya satu daun**, dalam urutan naik (sorting).
    
## 📌 Contoh Input

```
15
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 8 9
2
```

### Struktur Tree:

```

              1
            /   \
          2       3
        /   \    /  \
       4     5  6    7
                   / \
                  8   9
```

- Daun: 4, 5, 6, 8, 9
    
- Jarak 2 dari daun:
    
    - dari 4 → 2 → 1 ✅
        
    - dari 5 → 2 → 1 ✅
        
    - dari 6 → 3 → 1 ✅
        
    - dari 8 → 7 → 3 ✅
        
    - dari 9 → 7 → 3 ✅
        
- **Result:** 1, 3
    

### Contoh Output:

```
1 3
```


## 🔧 Hint Solusi

- Gunakan **DFS/postorder traversal** untuk menemukan daun.
    
- Simpan **jalur dari root ke daun** dalam stack/vector.
    
- Ketika sampai di daun, ambil node `k` langkah di atasnya.
    
- Gunakan `set` untuk menghindari duplikasi.
    
# Jawabanku
Berikut adalah jawabanku yang sudah optimal:

```cpp
#include<iostream>
#include<vector>
#include<memory>
#include<set>
using namespace std;

#define UQ unique_ptr<Node<T>>
#define MQ make_unique<Node<T>>

template <typename T>
struct Node {
    T data;
    UQ left, right;
    Node(T data) : data(data) {}

    Node* setLeft(T val){
        left = MQ(val);
        return left.get();
    }
    
    Node* setRight(T val){
        right = MQ(val);
        return right.get();
    }

    Node* setChild(T a, T b){
        setLeft(a); setRight(b);
        return this;
    }

    static UQ buildTress(vector<T>&vec, int idx=0){
        if(idx >= vec.size() || vec[idx]==-1) return nullptr;

        UQ node = MQ(vec[idx]);
        node->left = buildTress(vec, 2*idx+1);
        node->right = buildTress(vec, 2*idx+2);
        return node;
    }

    void trav() const {
        if(left) left->trav();
        cout << data << " ";
        if(right) right->trav();
    }

    // member function jawaban
    bool isLeaf() const {
        return !left && !right;
    }

    void getPathToLeaf(set<T>& daset, int& k, vector<T> curr={}) {
        curr.push_back(data);
        if(left) left->getPathToLeaf(daset,k, curr);
        if(right) right->getPathToLeaf(daset,k, curr);
        if(isLeaf()){
            int j=curr.size()-k-1;
            if(j>=0) daset.insert(curr[j]);
        }
    }

    void getKFromLeaf(int k) {
        set<T> daset;
        getPathToLeaf(daset, k);

        for(const auto& x: daset){
            cout << x << " ";
        }
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    vector<int> vec(n);
    for(auto&x:vec) cin >> x;
    unique_ptr<Node<int>> root = Node<int>::buildTress(vec);
    
    int k; cin >> k;
    root->getKFromLeaf(k);
    return 0;
}
```

# Editorial
Keren banget, kodenya **bersih, efisien, dan tepat sasaran** untuk soal:

> **"Cari Node yang Jaraknya K dari Daun"**

Berikut ini **penjelasan blok demi blok (editorial)** dari implementasi kamu:

---

## 🔧 Struktur Data

```cpp
#define UQ unique_ptr<Node<T>>
#define MQ make_unique<Node<T>>
```

- Shortcut agar deklarasi `unique_ptr` lebih ringkas.
    
- UQ = smart pointer tipe Node
    
- MQ = konstruktor instan node
    

---

## 🧱 Struct Node

```cpp
struct Node {
    T data;
    UQ left, right;
```

- Representasi node biasa.
    
- `data` adalah isi node.
    
- `left` dan `right` adalah anak kiri-kanan.
    

---

## 🏗️ Fungsi `buildTress()`

```cpp
static UQ buildTress(vector<T>& vec, int idx=0);
```

- Membangun tree dari input **level-order array**.
    
- Gunakan rekursi: `2*i+1` untuk kiri, `2*i+2` untuk kanan.
    
- Abaikan node jika bernilai `-1` (artinya null).
    

---

## 🧭 Traversal

```cpp
void trav() const;
```

- Fungsi in-order traversal (kiri–akar–kanan).
    
- Digunakan jika ingin debugging atau cetak struktur tree.
    

---

## 🌿 Fungsi `isLeaf()**`**

```cpp
bool isLeaf() const;
```

- True jika node tidak punya anak kiri dan kanan.
    

---

## 🎯 Core Function: `getPathToLeaf()`

```cpp
void getPathToLeaf(set<T>& daset, int& k, vector<T> curr={});
```

- Melakukan DFS ke seluruh leaf.
    
- `curr` menyimpan jalur dari root ke node saat ini.
    
- Jika ketemu leaf:
    
    - Ambil node yang berjarak `k` ke atas → `curr[size - k - 1]`
        
    - Disimpan dalam `set` agar tidak duplikat.
        

---

## 📌 Wrapper Function: `getKFromLeaf(k)`

```cpp
void getKFromLeaf(int k);
```

- Menyimpan hasil dalam `set`, lalu print hasil akhir secara otomatis terurut.
    

---

## 🚀 Main Function

```cpp
int n; cin >> n;
vector<int> vec(n); ...
int k; cin >> k;
```

- Input array pohon dan nilai `k`, lalu panggil pencarian.
    

---

## ✅ Contoh Output yang Sesuai

**Input:**

```
15
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 8 9
2
```

**Output:**

```
1 3
```

---

## 💡 Saran Peningkatan (Opsional)

1. Bisa tambahkan newline (`\n`) setelah hasil `getKFromLeaf()` agar output lebih rapi.
    
2. Kalau ingin tampil urut dari terkecil ke terbesar, `set` sudah cukup. Kalau ingin urutan DFS ditemukan, bisa pakai `vector + unordered_set`.
    

---

## 🏁 Kesimpulan

Kodenya **sudah sempurna dan optimal**. Tingkat rekursinya tepat, logika jaraknya pas, dan penggunaan `set` menghindari duplikasi.

Kalau sudah siap, tinggal lanjut ke **soal nomor 10**! Mau ide baru atau kamu udah punya bayangan duluan?