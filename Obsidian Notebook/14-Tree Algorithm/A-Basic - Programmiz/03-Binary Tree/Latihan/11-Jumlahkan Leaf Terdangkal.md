---
obsidianUIMode: preview
note_type: latihan
latihan: Jumlahkan Leaf Terdangkal
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-07-04T19:59:00
---
---
# 🌿 Leaf Terdangkal: Jumlahkan Daunnya

## 🧾 Deskripsi

Diberikan sebuah **binary tree**, tugasmu adalah mencari **semua node daun (leaf)** yang berada pada **level terdangkal**, lalu menjumlahkan nilai-nilainya.

> **Level terdangkal** adalah level pertama dari atas (dekat root) tempat ditemukan daun.

## 📥 Input

Baris pertama berisi sebuah bilangan bulat `n` — jumlah elemen dalam array level-order dari binary tree.

Baris kedua berisi `n` buah bilangan bulat `A[i]` — representasi binary tree secara level-order, di mana:

- Nilai `-1` menandakan **node kosong** (null child).
    
## 📤 Output

Cetak satu bilangan bulat — jumlah dari semua **leaf node yang berada di level terdangkal**.


## 📘 Contoh Input Output

```
15
1 2 3 4 5 6 7 8 9 -1 -1 -1 -1 -1 -1
```

```
18
```

## 📊 Penjelasan

Tree yang terbentuk dari array:

```

               1
            /     \
          2         3
        /   \     /   \
       4     5   6     7
      / \
     8   9
```

- Leaf nodes: `5`, `6`, `7`, `8`, `9`
    
- Leaf nodes pada **level terdangkal** adalah `5`, `6`, dan `7` (level ke-2)
    
- Jadi total = `5 + 6 + 7 = 18`
    

---

## 💡 Batasan

- `1 ≤ n ≤ 1000`
    
- `-1000 ≤ A[i] ≤ 1000`
    

---

## 🎯 Tujuan Pembelajaran

- Penerapan traversal BFS (level-order)
    
- Deteksi node daun (leaf)
    
- Filtering berdasarkan level terdangkal
    

---

Kalau kamu butuh versi lebih susah, misalnya:

- Jumlahkan daun terdangkal **yang bilangan prima**
    
- Atau **jumlahkan produk semua nilai leaf di level terdangkal**
    

...langsung bilang ya, kita naik level! 🚀

# Jawabanku
Berikut adalah jawabanku yang sudah optimal dan benar:

```cpp
#include<iostream>
#include<climits>
#include<memory>
#include<vector>
using namespace std;

#define UQ unique_ptr<Node<T>>
#define MQ make_unique<Node<T>>

template <typename T>
struct Node {
    T data;
    UQ left, right;
    Node (T data): data(data) {}

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

    void travers() const {
        if(left) left->travers();
        cout << data << " ";
        if(right) right->travers();
    }

    bool isLeaf() const {
        return !left && !right;
    }

    int higherLeaf(int lvl=1) {
        int restLeft=INT_MAX, restRight=INT_MAX;
        if(left) restLeft = left->higherLeaf(lvl+1);
        if(right) restRight = right->higherLeaf(lvl+1);
        if(isLeaf()){
            return lvl;
        }
        return min(restLeft, restRight);
    }

    int getSumLowestLevelLeaf(int target, int lvl=1) const {
        int sum=0;
        if(left) sum += left->getSumLowestLevelLeaf(target, lvl+1);
        if(right) sum += right->getSumLowestLevelLeaf(target, lvl+1);
        if(target == lvl){
            if(isLeaf()) sum+=data;
        }
        return sum;
    }

    int sumLowestLevelNode() {
        return getSumLowestLevelLeaf(higherLeaf());
    }

    static UQ buildTress(vector<T>& vec, int idx=0){
        if(idx >= vec.size() || vec[idx] == -1) return nullptr;

        UQ node = MQ(vec[idx]);
        node->left = buildTress(vec, 2*idx+1);
        node->right = buildTress(vec, 2*idx+2);
        return node;
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

    cout << root->sumLowestLevelNode();

    return 0;
}
```

# Editorial
Bagus sekali! Kode kamu sudah sangat rapi dan tepat sasaran. Sekarang, sesuai permintaan sebelumnya, berikut **editorial per blok kode** untuk program ini:

---

## 🧾 Editorial dan Penjelasan Per Blok

### 🔸 1. Header & Namespace

```cpp
#include<iostream>
#include<climits>
#include<memory>
#include<vector>
using namespace std;
```

📌 Digunakan untuk:

- `iostream`: input/output
    
- `climits`: nilai `INT_MAX`
    
- `memory`: `unique_ptr`
    
- `vector`: struktur data dinamis
    

---

### 🔸 2. Macro Pendek untuk Smart Pointer

```cpp
#define UQ unique_ptr<Node<T>>
#define MQ make_unique<Node<T>>
```

📌 Pendekatan untuk menyingkat penulisan `unique_ptr` dan `make_unique`.

---

### 🔸 3. Template Struct Node

```cpp
template <typename T>
struct Node {
    ...
};
```

📌 Struct `Node` menyimpan nilai `data` dan dua pointer ke anak kiri dan kanan (left, right).

---

### 🔸 4. Konstruktor & Setters

```cpp
Node (T data): data(data) {}

Node* setLeft(T val){ ... }
Node* setRight(T val){ ... }
Node* setChild(T a, T b){ ... }
```

📌 Membuat node baru dan menetapkan anak kiri dan kanan.

📝 `setLeft`, `setRight` mengembalikan raw pointer (`Node*`) ke node yang baru dibuat, untuk kemudahan chaining.

---

### 🔸 5. In-order Traversal

```cpp
void travers() const {
    if(left) left->travers();
    cout << data << " ";
    if(right) right->travers();
}
```

📌 Mencetak isi tree secara **in-order** (kiri, akar, kanan) — untuk debugging.

---

### 🔸 6. Mengecek Daun

```cpp
bool isLeaf() const {
    return !left && !right;
}
```

📌 Fungsi utilitas untuk mengecek apakah node ini merupakan leaf.

---

### 🔸 7. Mencari Level Daun Terdangkal

```cpp
int higherLeaf(int lvl=1) {
    ...
}
```

📌 Fungsi ini akan **menemukan level leaf terdangkal** (leaf paling atas).

- Leaf ditemukan ➝ kembalikan level saat ini.
    
- Bukan leaf ➝ cari level terdangkal dari subtree kiri & kanan dan ambil `min()`-nya.
    

---

### 🔸 8. Menjumlahkan Daun di Level Terdangkal

```cpp
int getSumLowestLevelLeaf(int target, int lvl=1) const {
    ...
}
```

📌 Rekursif menjelajah seluruh node dan hanya menambahkan `data` **jika node itu leaf dan berada di level target**.

---

### 🔸 9. Fungsi Kombinasi

```cpp
int sumLowestLevelNode() {
    return getSumLowestLevelLeaf(higherLeaf());
}
```

📌 Fungsi utama yang dipanggil untuk menyelesaikan soal:

- Cari level terdangkal leaf
    
- Jumlahkan semua leaf pada level itu
    

---

### 🔸 10. Membangun Tree dari Vector

```cpp
static UQ buildTress(vector<T>& vec, int idx=0){
    ...
}
```

📌 Membangun binary tree dari array `vec` menggunakan **representasi level-order**.

- Index anak kiri: `2*i + 1`
    
- Index anak kanan: `2*i + 2`
    
- `-1` menandakan node kosong
    

---

### 🔸 11. Fungsi `main()`

```cpp
int main() {
    ...
}
```

📌 Alur utama program:

1. Baca input array tree
    
2. Bangun tree
    
3. Hitung dan cetak jumlah leaf pada level terdangkal
    

---

## ✅ Contoh Input

```
15
1 2 3 4 5 6 7 8 9 -1 -1 -1 -1 -1 -1
```

### 💡 Tree Visual:

```

               1
            /     \
          2         3
        /   \     /   \
       4     5   6     7
      / \
     8   9
```

### 💬 Output:

```
18
```

Karena leaf pada level terdangkal (level 3) adalah: **5, 6, 7** ⇒ `5 + 6 + 7 = 18`

---

Kalau kamu ingin versi lain dari soal ini:

- Jumlahkan leaf terdalam
    
- Hitung jumlah leaf di level `X` (input dari user)
    
- Cari leaf terdalam yang genap  
    ...langsung bilang ya, siap bantuin! 💪