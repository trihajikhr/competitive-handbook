---
obsidianUIMode: preview
note_type: latihan
latihan: Jumlahkan Semua Daun di Level Tertinggi
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-07-02T16:54:00
---
---

# 🪵 Jumlahkan Semua Nilai pada Daun di Level Tertinggi

Diberikan sebuah **binary tree** dalam bentuk **array level-order** (gunakan `-1` untuk node kosong).  

Tugasmu adalah menghitung **jumlah seluruh leaf node** (daun) yang berada di **level terdalam / tertinggi** dari pohon.


## ✅ Input Format:

1. Satu bilangan bulat `n` — panjang array
    
2. Array `A` dengan `n` elemen — merepresentasikan level-order dari tree
    
## 🧾 Output Format:

Cetak satu bilangan bulat — jumlah semua leaf node yang berada di level terdalam dari pohon.

## 🧪 Contoh Input:

```
15
1 2 3 4 5 6 7 8 9 -1 -1 -1 -1 -1 -1
```

### 🗺️ Representasi Tree:

```

               1
            /     \
          2         3
        /   \     /   \
       4     5   6     7
      / \
     8   9
```

- Leaf nodes = {8, 9, 5, 6, 7}
    
- Level tertinggi/terdalam = level 3
    
- Leaf di level 3: **8, 9**
    
- Jumlah = `8 + 9 = 17`
    

## ✅ Output:

```
17
```

## 🎯 Tujuan Latihan:

- DFS + pencatatan level node
    
- Identifikasi daun
    
- Mengelompokkan daun berdasarkan level
    
- Menyaring hanya level maksimal
    

Kalau kamu mau versi ekstra:

- “Cetak semua node level terdalam, bukan hanya leaf”
    
- “Hitung rata-rata node di level terdalam”
    
- “Cari leaf bernilai terbesar di level terdalam”
    

# Jawabanku
Berikut jawabaku yang sudah benar untuk tantangan ini:

```cpp
#include<iostream>
#include<memory>
#include<vector>
using namespace std;

#define UQ unique_ptr<Node<T>>
#define MQ make_unique<Node<T>>

template <typename T>
struct Node {
    T data;
    UQ left, right;
    Node(T data) : data(data) {};

    UQ setLeft(T val){
        left = MQ(val);
        return left.get();
    }

    UQ setRight(T val){
        right = MQ(val);
        return right.get();
    }

    UQ setChild(T a, T b){
        setLeft(a); setRight(b);
        return this;
    }

    void trav() const {
        if(left) left->trav();
        cout << data << " ";
        if(right) right->trav();
    }

    // mengambil jumlah node leaf terdalam
    int height() const {
        int restLeft, restRight;
        restLeft = left ? left->height() : 0;
        restRight = right ? right->height() : 0;
        return 1 + max(restLeft, restRight);
    }

    int getLevel(int target, int lvl=1) const {
        int sum=0;
        if(left) sum += left->getLevel(target, lvl+1);
        if(right) sum += right->getLevel(target, lvl+1);
        if(target == lvl){
            sum += data;
        }
        return sum;
    }

    int sumDeepestLeaf() {
        return getLevel(height());
    }

    static UQ buildTrees(vector<T>& vec, int idx=0){
        if(idx >= vec.size() || vec[idx]==-1) return nullptr;

        UQ node = MQ(vec[idx]);
        node->left = buildTrees(vec, 2*idx+1);
        node->right = buildTrees(vec, 2*idx+2);
        return node;
    }
};

inline void fastio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    fastio();
    int n; cin >> n;
    vector<int> vec(n);
    for(auto&x:vec) cin >> x;

    unique_ptr<Node<int>> root;
    root = Node<int>::buildTrees(vec);

    int rest = root->sumDeepestLeaf();
    cout << rest << "\n";
    return 0;
}
```

# Editorial
Keren! Kode kamu udah solid banget, dan berhasil menyelesaikan soal "Jumlahkan semua leaf node pada level terdalam" dengan elegan. Sekarang, biar makin mantap, berikut ini editorial per blok kode biar kamu bisa review dan tingkatkan kualitasnya jika perlu.

## 🧠 Editorial – Per Blok Kode

---

### ✅ `#define` dan `template`

```cpp
#define UQ unique_ptr<Node<T>>
#define MQ make_unique<Node<T>>
```

- Ini adalah **macro** untuk mempersingkat penulisan tipe panjang. Praktis, tapi hati-hati karena macro tidak punya _type checking_.
    
- Cocok untuk latihan, tapi di produksi lebih disarankan pakai `using` atau tulis eksplisit.
    

---

### ✅ Struktur Node

```cpp
template <typename T>
struct Node {
    T data;
    UQ left, right;
    Node(T data) : data(data) {};
```

- Struktur dasar pohon biner dengan pointer unik ke anak kiri dan kanan.
    
- Gunakan `unique_ptr` sebagai ownership model — bagus! Artinya kamu menghindari memory leak.
    

---

### ✅ Fungsi Helper untuk Menambahkan Anak

```cpp
UQ setLeft(T val){ left = MQ(val); return left.get(); }
UQ setRight(T val){ right = MQ(val); return right.get(); }
UQ setChild(T a, T b){ setLeft(a); setRight(b); return this; }
```

- Fungsi ini membantu menambahkan node anak ke kiri dan kanan.
    
- Tapi, _note_: Fungsi `setLeft()` dan `setRight()` **mengembalikan `get()`**, tapi ditulis return type-nya `UQ`, padahal `get()` return-nya `Node<T>*`, bukan `UQ`.
    

**💡 Koreksi return type-nya jadi:**

```cpp
Node<T>* setLeft(T val) { ... }
Node<T>* setRight(T val) { ... }
```

---

### ✅ Fungsi Traversal

```cpp
void trav() const {
    if(left) left->trav();
    cout << data << " ";
    if(right) right->trav();
}
```

- In-order traversal.
    
- Sesuai standar. Tidak dipakai dalam logika utama, tapi bagus untuk debugging visual.
    

---

### ✅ Fungsi `height()` untuk Menghitung Tinggi Pohon

```cpp
int height() const {
    int restLeft = left ? left->height() : 0;
    int restRight = right ? right->height() : 0;
    return 1 + max(restLeft, restRight);
}
```

- Mengembalikan tinggi maksimal pohon.
    
- Digunakan untuk mencari level terdalam.
    

---

### ✅ Fungsi `getLevel()` untuk Menjumlahkan Nilai di Level Tertentu

```cpp
int getLevel(int target, int lvl=1) const {
    int sum = 0;
    if(left) sum += left->getLevel(target, lvl+1);
    if(right) sum += right->getLevel(target, lvl+1);
    if(target == lvl){
        sum += data;
    }
    return sum;
}
```

- DFS traversal ke seluruh node.
    
- Jika level saat ini sesuai target, node disumbangkan ke total.
    

---

### ✅ Fungsi Final: `sumDeepestLeaf()`

```cpp
int sumDeepestLeaf() {
    return getLevel(height());
}
```

- Memanggil `height()` dulu → lalu cari semua node di level tersebut.
    
- **Catatan:** Fungsi ini menghitung **semua node di level terdalam**, bukan hanya leaf. Tapi karena leaf pasti di level terdalam dalam complete tree, tetap valid untuk kasus ini.
    

---

### ✅ Build Tree dari Vector (Level Order)

```cpp
static UQ buildTrees(vector<T>& vec, int idx=0){
    if(idx >= vec.size() || vec[idx]==-1) return nullptr;
    ...
}
```

- Fungsi ini mengubah array ke struktur binary tree (asumsikan complete binary tree).
    
- Node `-1` diabaikan.
    

---

### ✅ Fungsi Main

```cpp
fastio(); // Optimalisasi I/O
...
int rest = root->sumDeepestLeaf();
cout << rest << "\n";
```

- Program baca array, bangun tree, dan cetak hasilnya.
    

---

## 🏁 Kesimpulan:

|Aspek|Status|Catatan|
|---|---|---|
|Memory Safety|✅|Pakai `unique_ptr`|
|DFS/Height/Level Sum|✅|Tepat dan efisien|
|Return Type Macro|⚠️|`setLeft()` dan `setRight()` sebaiknya return `Node<T>*`|
|Modularitas|✅|Terbagi rapi per fungsi|
|Readability|✅|Bersih dan to the point|

---

Kalau kamu siap, kita bisa lanjut ke soal berikutnya dari challenge ini:

> **"Jumlahkan node leaf di level terdalam yang genap saja"**, atau  
> **"Berapa banyak node di level terdalam yang bukan leaf?"**

Atau kamu punya ide sendiri? Gas, tinggal bilang aja! 💪