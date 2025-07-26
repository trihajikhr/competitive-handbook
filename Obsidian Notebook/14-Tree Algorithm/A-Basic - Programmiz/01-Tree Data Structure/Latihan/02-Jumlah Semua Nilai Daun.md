---
obsidianUIMode: preview
note_type: latihan
latihan: Jumlah Semua Nilai Daun
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-29T13:34:00
---
---
# Soal 2: Jumlah Semua Nilai Daun (Leaf Nodes)

Buatlah fungsi `int sumOfLeaves(Node* root)` yang menghitung jumlah semua nilai **daun** (leaf nodes) dalam sebuah binary tree.

Leaf node adalah node yang **tidak punya anak kiri maupun kanan**.

---

#### Contoh:

Untuk tree:

```

      10
     /  \
    5   20
   / \
  3   8
```

Daunnya: `3`, `8`, dan `20`  
Maka hasilnya: `3 + 8 + 20 = 31`

---

Kalau sudah kamu kerjakan, kirimkan kodenya di sini ya. Nanti aku periksa dan kasih penjelasannya. Semangat!

# Jawabanku
Berikut adalah jawabanku, yang sebelumnya terdapat minor typo casing, bagian `setLeft`, tapi sudah diperbaiki:

```cpp
#include<iostream>
#include<memory>
using namespace std;

struct Node {
    int data;
    unique_ptr<Node> left, right;
    Node(int data) : data(data) {};

    // chaining
    Node* setLeft(int val){
        left = make_unique<Node>(val);
        return left.get();
    }

    Node* setRight(int val){
        right = make_unique<Node>(val);
        return right.get();
    }

    Node* setChild(int a, int b){
        setLeft(a); setRight(b);
        return this;
    }

    bool isLeaf(){
        return (!left && !right);
    }

    int sumLeaf(){
        int sum=0;
        if(left) sum+= left->sumLeaf();
        if(right) sum+= right->sumLeaf();
        if(isLeaf()) sum+= data;

        return sum;
    }
};

int main() {
    unique_ptr<Node> root = make_unique<Node>(10);
    root->setChild(5,20)->left->setChild(3,8);

    cout << root->sumLeaf() << "\n";
    return 0;
}
```

# Editorial
💯 Jawabanmu **sudah sangat tepat** dan clean secara struktural! Kamu kelihatan makin nyaman dengan gaya OOP dan traversal rekursif. Sekarang mari kita kupas bareng-bareng secara editorial, sambil menggarisbawahi poin penting yang kamu implementasikan dengan baik.

---

## ✅ Pemeriksaan Output

Tree yang kamu buat:

```

      10
     /  \
    5   20
   / \
  3   8
```

Leaf nodes:

- `3` (tidak punya anak)
    
- `8` (tidak punya anak)
    
- `20` (tidak punya anak)
    

Total: `3 + 8 + 20 = 31`  
Program mencetak `31`. **Benar.**

---

## 🧠 Editorial

### 1. Konstruktor & Properti

```cpp
struct Node {
    int data;
    unique_ptr<Node> left, right;
    Node(int data) : data(data) {};
```

Sudah familiar — `unique_ptr` digunakan agar otomatis dikelola tanpa `delete`.

---

### 2. Chaining Builder

```cpp
Node* setleft(int val);
Node* setRight(int val);
Node* setChild(int a, int b);
```

Tidak ada masalah, meskipun ada typo minor pada `setleft` (harusnya `setLeft`, biar konsisten gaya casing-nya). Tapi secara teknis tetap jalan, jadi ini bukan bug.

---

### 3. Fungsi `isLeaf()`

```cpp
bool isLeaf(){
    return (!left && !right);
}
```

Bagus! Ini fungsi bantu yang rapi dan readable. Ceknya simpel dan efisien.

---

### 4. Fungsi `sumLeaf()`

```cpp
int sumLeaf(){
    int sum=0;
    if(left) sum+= left->sumLeaf();
    if(right) sum+= right->sumLeaf();
    if(isLeaf()) sum+= data;
    return sum;
}
```

Ini sangat ideal:

- Post-order traversal (kiri-kanan-akar), cocok untuk akumulasi.
    
- Menambahkan nilai hanya jika `isLeaf()` true.
    
- Penanganan `nullptr` implicit lewat pengecekan `if(left)` dan `if(right)`.
    

---

## ✨ Hal Menarik yang Bisa Ditambahkan (opsional)

Jika kamu ingin eksperimen gaya lain, kamu bisa ubah `sumLeaf()` jadi versi _fungsi luar_ dari `Node`, misalnya:

```cpp
int sumLeaf(const Node* root) {
    if (!root) return 0;
    if (root->isLeaf()) return root->data;
    return sumLeaf(root->left.get()) + sumLeaf(root->right.get());
}
```

Tapi gaya milikmu sudah sangat mantap dan modular.

---

## 🟢 Rangkuman

- ✅ Logika tepat, clean, dan efisien
    
- ✅ Traversal akurat, output benar
    
- ✅ Gaya chaining tetap konsisten
    
- 🟡 Minor: typo casing `setleft` vs `setLeft` (tidak berpengaruh tapi estetika)
    
