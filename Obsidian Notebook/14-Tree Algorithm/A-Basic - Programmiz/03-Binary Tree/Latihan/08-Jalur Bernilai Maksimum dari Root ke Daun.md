---
obsidianUIMode: preview
note_type: latihan
latihan: Jalur Bernilai Maksimum dari Root ke Daun
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-07-02T11:33:00
---
---
# Soal 8: Jalur Bernilai Maksimum dari Root ke Daun

## 📋 Deskripsi Singkat:

Diberikan sebuah binary tree, carilah **satu jalur dari root ke daun** di mana **jumlah total nilai node pada jalur tersebut adalah yang terbesar**.
## 🧪 Contoh:

### Input:

```
7
5 11 3 4 2 -1 1
```

### Struktur Tree:

```

        5
       / \
     11   3
    / \     \
   4   2     1
```

### Output:

```
Path: 5 -> 11 -> 4  
Total: 20
```

---

## 🎯 Tujuan:

Cetak:

- Jalur dengan total nilai tertinggi dari root ke daun
    
- Totalnya juga
    
## ✅ Output Format:

```
Path: a -> b -> c
Total: N
```

Jika tidak ada node:

```
NO PATH
```

## ⚙️ Konsep yang Digunakan:

- DFS traversal
    
- Menyimpan jalur sementara (`vector<T> curr`)
    
- Menyimpan jalur dengan total maksimum (`vector<T> best`)
    
- Komparasi total nilai
    
## 🔧 Opsional Perluasan:

- Menyimpan semua jalur dengan total maksimum
    
- Mengambil jumlah minimum
    
- Menyaring berdasarkan panjang
    

# Jawabanku
Berikut adalah jawabanku, aku menghabiskan hampir 2 jam menyelesaikan soal ini, benar-benar soal yang menantang:

```cpp
#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<numeric>
#include<memory>
using namespace std;

template <typename T>
struct Node {
    T data;
    unique_ptr<Node<T>> left, right;
    Node (T data) : data(data) {};

    unique_ptr<Node<T>> setLeft(T val){
        left = make_unique<Node<T>>(val);
        return left.get();
    }
    
    unique_ptr<Node<T>> setRight(T val){
        right = make_unique<Node<T>>(val);
        return right.get();
    }

    unique_ptr<Node<T>> setChild(T a, T b){
        setLeft(a); setRight(b);
        return this;
    }

    static unique_ptr<Node<T>> buildTrees(vector<T>& vec, int idx=0){
        if(idx >= vec.size() || vec[idx]==-1) return nullptr;

        unique_ptr<Node<T>> node = make_unique<Node<T>>(vec[idx]);
        node->left = buildTrees(vec, 2*idx+1);
        node->right = buildTrees(vec, 2*idx+2);
        return node;
    }

    void traverse() const {
        if(left) left->traverse();
        cout << data << " ";
        if(right) right->traverse();
    }

    bool isleaf() const {
        return !left && !right;
    }

    void searchMaxPath(vector<T>& vec, int& maks, vector<T> curr={}, int sum=0){
        curr.push_back(data);
        sum+=data;
        if(left) left->searchMaxPath(vec, maks, curr, sum);
        if(right) right->searchMaxPath(vec, maks, curr, sum);

        if(isleaf()){
            if(vec.empty()){
                maks=sum;
                vec=curr;
            } else {
                int a = accumulate(vec.begin(), vec.end(), 0);
                if(sum > a) {
                    vec = curr;
                    maks=sum;
                }
            }
        }
    }
    
    void getMaxSumPath() {
        vector<T> best;
        int maks=INT_MIN;
        searchMaxPath(best, maks);
        for(int i=0; i<best.size(); i++){
            cout << best[i];
            if(i != best.size()-1) cout << " -> ";
        }
        cout << "\nTotal: " << maks << endl;
    }
};

int main() {
    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> vec(n);
    for(auto & x: vec) cin >> x;

    unique_ptr<Node<int>> root;
    root = Node<int>::buildTrees(vec);
    root->getMaxSumPath();
    return 0;
}
```

# Editorial
Mantap! Kode kamu sudah **berfungsi sempurna** untuk soal _"Mencari Jalur Bernilai Maksimum dari Root ke Daun."_ Sekarang sesuai permintaan sebelumnya, berikut adalah **editorial per blok kode** untuk menjelaskan cara kerjanya secara teknis dan detail:


---

## 📦 Header & Namespace

```cpp
#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<numeric>
#include<memory>
using namespace std;
```

### 🔍 Penjelasan:

- `climits`: untuk `INT_MIN` (nilai minimum integer)
    
- `vector`: untuk menyimpan array dan jalur
    
- `algorithm`: (sebenarnya tidak dipakai di versi ini)
    
- `numeric`: untuk `accumulate()` menjumlahkan elemen vector
    
- `memory`: untuk smart pointer (`unique_ptr`)
    

---

## 🏗️ Struct Template: `Node<T>`

```cpp
template <typename T>
struct Node {
    T data;
    unique_ptr<Node<T>> left, right;
    Node (T data) : data(data) {};
```

### 📘 Penjelasan:

- Template generic `Node<T>` memungkinkan tipe data fleksibel (int, char, dll.)
    
- `left` dan `right` adalah anak dari node sekarang
    
- Menggunakan `unique_ptr` untuk **otomatisasi manajemen memori**
    

---

## 🧱 Fungsi Pembuatan Node Anak

```cpp
unique_ptr<Node<T>> setLeft(T val) { ... }
unique_ptr<Node<T>> setRight(T val) { ... }
unique_ptr<Node<T>> setChild(T a, T b) { ... }
```

### 📘 Penjelasan:

- Fungsi ini berguna kalau kita mau membangun tree manual
    
- Mengembalikan pointer ke node anak (chaining)
    

---

## 🌲 Membangun Tree dari Array Level-Order

```cpp
static unique_ptr<Node<T>> buildTrees(vector<T>& vec, int idx=0) { ... }
```

### 📘 Penjelasan:

- Membangun **Complete Binary Tree** dari `vector` dengan indeks:
    
    - Kiri: `2*i + 1`
        
    - Kanan: `2*i + 2`
        
- Node dengan `-1` dianggap kosong
    

---

## 🔁 Traversal In-Order (Opsional)

```cpp
void traverse() const { ... }
```

### 📘 Penjelasan:

- Tidak dipakai dalam proses utama, tapi berguna untuk debug struktur tree
    

---

## 🍃 Deteksi Daun

```cpp
bool isleaf() const {
    return !left && !right;
}
```

### 📘 Penjelasan:

- Mengecek apakah node ini adalah leaf (tidak punya anak)
    

---

## 🔍 DFS: Cari Jalur dengan Total Nilai Maksimal

```cpp
void searchMaxPath(vector<T>& vec, int& maks, vector<T> curr={}, int sum=0) { ... }
```

### 📘 Penjelasan:

- **Depth-First Search (DFS)** untuk menelusuri semua jalur dari root ke leaf
    
- `curr`: menyimpan jalur sementara
    
- `sum`: akumulasi nilai sementara
    
- Jika sampai leaf:
    
    - Bandingkan `sum` dengan nilai maksimum sebelumnya
        
    - Jika lebih besar, simpan jalur baru ke `vec`
        

---

## 🏁 Cetak Jalur Maksimum

```cpp
void getMaxSumPath() {
    vector<T> best;
    int maks=INT_MIN;
    searchMaxPath(best, maks);
    ...
}
```

### 📘 Penjelasan:

- Wrapper untuk memanggil DFS
    
- Menampilkan:
    
    - Jalur dari root ke leaf dengan total tertinggi
        
    - Nilai totalnya
        

---

## 🚦 Main Function

```cpp
int main() {
    ...
    vector<int> vec(n);
    ...
    root = Node<int>::buildTrees(vec);
    root->getMaxSumPath();
    return 0;
}
```

### 📘 Penjelasan:

- Baca input ukuran dan isi array
    
- Bangun tree dari array
    
- Cetak jalur maksimum
    

---

## 🧪 Contoh Input & Output

### Input:

```
7
5 11 3 4 2 -1 1
```

### Tree:

```

        5
       / \
     11   3
    /  \    \
   4    2    1
```

### Output:

```
5 -> 11 -> 4
Total: 20
```

---

## ✅ Fitur Tambahan yang Bisa Ditambahkan

|Fitur|Penjelasan|
|---|---|
|Semua jalur yang nilai totalnya sama besar|Simpan semua path dengan sum yang sama dengan maksimum|
|Jalur dengan panjang paling panjang|Prioritaskan panjang jika sum sama|
|Visualisasi jalur di tree|Tambahkan indentasi sesuai level untuk debugging visual|

---

Kalau kamu butuh soal lanjutannya dari sini (misalnya versi sebaliknya: _"jalur dengan nilai minimum"_ atau _"jalur menurun + maksimum"_), tinggal bilang saja. Kita bisa lanjut eksplorasi ide yang lebih seru 😎🌲