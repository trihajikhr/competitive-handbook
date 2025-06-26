---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 14TH-TREE-00A4
nama_algoritma: 
kategori_algoritma: tree algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: programiz.com & chatgpt.com
date_learned: 2025-06-24T14:54:00
tags:
  - tree-algorithm
---
---
# Full Binary Tree

**Full binary tree** adalah jenis khusus dari binary tree di mana **setiap parent node (atau internal node)** memiliki **tepat dua anak** atau **tidak memiliki anak sama sekali**.

Tree ini juga dikenal dengan istilah lain, yaitu **proper binary tree**.

![[04 - Full Binary Tree-1.png]]

## Teorema pada Full Binary Tree

```
Let, i = the number of internal nodes
       n = be the total number of nodes
       l = number of leaves
      λ = number of levels
```

Misalkan:

- $i$ = jumlah **internal node**
    
- $n$ = jumlah **total node**
    
- $l$ = jumlah **leaf node** (daun)
    
- $λ$ = jumlah **level** (tingkatan)
    

Berikut beberapa sifat penting (teorema) dari **full binary tree**:

1. Jumlah leaf node = $i + 1$
    
2. Jumlah total node = $2i + 1$
    
3. Jumlah internal node = $(n – 1) / 2$
    
4. Jumlah leaf node = $(n + 1) / 2$
    
5. Jumlah total node = $2l – 1$
    
6. Jumlah internal node = $l – 1$
    
7. Jumlah leaf node **maksimal** = $2^λ - 1$
    

---

## Contoh implementasi dalam kode

```cpp
Berikut adalah **terjemahan komentar** dalam kode C++ tersebut ke dalam bahasa Indonesia, tanpa mengubah kode program:

```cpp
// Memeriksa apakah suatu binary tree merupakan full binary tree dalam C++

#include <iostream>
using namespace std;

struct Node {
  int key;
  struct Node *left, *right;
};

// Pembuatan node baru
struct Node *newNode(char k) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->key = k;
  node->right = node->left = NULL;
  return node;
}

bool isFullBinaryTree(struct Node *root) {
  
  // Memeriksa apakah tree kosong
  if (root == NULL)
    return true;

  // Memeriksa keberadaan anak (children)
  if (root->left == NULL && root->right == NULL)
    return true;

  if ((root->left) && (root->right))
    return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));

  return false;
}

int main() {
  struct Node *root = NULL;
  root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->left->right->left = newNode(6);
  root->left->right->right = newNode(7);

  if (isFullBinaryTree(root))
    cout << "Tree ini adalah full binary tree\n";
  else
    cout << "Tree ini bukan full binary tree\n";
}
```

Baik! Berikut adalah **penjelasan per blok kode** dari program untuk **memeriksa apakah sebuah tree adalah full binary tree**, agar kamu bisa memahami cara kerjanya secara menyeluruh:

---

### 🔹 1. Header dan Namespace

```cpp
#include <iostream>
using namespace std;
```

- `#include <iostream>`: Digunakan untuk operasi input/output (`cout`).
    
- `using namespace std;`: Agar kita bisa menggunakan `cout` dan fungsi lainnya tanpa perlu `std::`.
    

---

### 🔹 2. Struktur Node

```cpp
struct Node {
  int key;
  struct Node *left, *right;
};
```

- Membuat struktur `Node` untuk merepresentasikan simpul (node) pada binary tree.
    
- Masing-masing node memiliki:
    
    - `key`: menyimpan nilai data
        
    - `left`: pointer ke anak kiri
        
    - `right`: pointer ke anak kanan
        

---

### 🔹 3. Fungsi `newNode()` – Membuat Node Baru

```cpp
struct Node *newNode(char k) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->key = k;
  node->right = node->left = NULL;
  return node;
}
```

- Membuat sebuah node baru dan mengalokasikan memori menggunakan `malloc()`.
    
- Mengatur nilai `key`, serta menginisialisasi `left` dan `right` ke `NULL`.
    
- Mengembalikan pointer ke node baru tersebut.
    

📝 _Catatan_: Ini menggunakan gaya pemrograman C. Di C++, lebih lazim menggunakan `new` dan constructor.

---

### 🔹 4. Fungsi `isFullBinaryTree()` – Memeriksa Apakah Tree adalah Full Binary Tree

```cpp
bool isFullBinaryTree(struct Node *root) {
  
  // Memeriksa apakah tree kosong
  if (root == NULL)
    return true;

  // Jika node adalah leaf (tidak punya anak kiri maupun kanan)
  if (root->left == NULL && root->right == NULL)
    return true;

  // Jika node punya dua anak, periksa secara rekursif untuk subtree kiri dan kanan
  if ((root->left) && (root->right))
    return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));

  // Jika node hanya punya satu anak, maka bukan full binary tree
  return false;
}
```

Penjelasan logikanya:

- ✅ Jika node kosong → anggap full
    
- ✅ Jika node adalah leaf → anggap full
    
- ✅ Jika punya **dua anak** → periksa subtree kiri dan kanan
    
- ❌ Jika **hanya satu anak**, maka tree **bukan full binary tree**
    

---

### 🔹 5. Fungsi `main()` – Membangun Tree dan Memanggil Fungsi Pengecekan

```cpp
int main() {
  struct Node *root = NULL;
  root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->left->right->left = newNode(6);
  root->left->right->right = newNode(7);
```

- Membuat tree dengan struktur sebagai berikut:
    


```

        1
       / \
      2   3
     / \
    4   5
       / \
      6   7
      
```

Tree ini adalah **full binary tree** karena setiap node internal punya **tepat dua anak**, atau tidak sama sekali (leaf).

---

### 🔹 6. Menampilkan Hasil Pemeriksaan

```cpp
  if (isFullBinaryTree(root))
    cout << "Tree ini adalah full binary tree\n";
  else
    cout << "Tree ini bukan full binary tree\n";
}
```

- Menjalankan fungsi `isFullBinaryTree()` dan mencetak hasilnya ke layar.
    

---

### ✅ Contoh Output

```
Tree ini adalah full binary tree
```

---

Kalau kamu mau, aku bisa bantu:

- Ubah versi malloc jadi versi modern `new`
    
- Tambahkan visualisasi atau simulasi langkah demi langkah bagaimana rekursi bekerja
    
- Tambahkan validasi dari input pengguna
    

Mau lanjut ke mana?

---

Berikut adalah **versi modern C++** dari program sebelumnya, yaitu dengan mengganti `malloc()` dengan `new`, dan menghapus kebutuhan cast dan `stdlib.h`. Kita juga akan sedikit merapikan kode agar lebih sesuai dengan konvensi C++.

---

## ✅ Versi C++ dengan `new` (tanpa `malloc`)

```cpp
#include <iostream>
using namespace std;

struct Node {
  int key;
  Node* left;
  Node* right;

  // Constructor untuk mempermudah pembuatan node
  Node(int k) {
    key = k;
    left = nullptr;
    right = nullptr;
  }
};

// Memeriksa apakah tree adalah full binary tree
bool isFullBinaryTree(Node* root) {
  // Tree kosong dianggap full
  if (root == nullptr)
    return true;

  // Node tanpa anak (leaf)
  if (root->left == nullptr && root->right == nullptr)
    return true;

  // Node dengan dua anak → periksa subtree secara rekursif
  if (root->left && root->right)
    return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);

  // Jika hanya satu anak → bukan full binary tree
  return false;
}

int main() {
  // Membentuk tree
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->left->right->left = new Node(6);
  root->left->right->right = new Node(7);

  // Menampilkan hasil
  if (isFullBinaryTree(root))
    cout << "Tree ini adalah full binary tree\n";
  else
    cout << "Tree ini bukan full binary tree\n";

  return 0;
}
```

---

### ✨ Perbedaan Utama

|Sebelumnya (C-style)|Sekarang (C++ style)|
|---|---|
|`malloc()`|`new`|
|Cast `(struct Node *)`|Tidak perlu casting|
|`NULL`|`nullptr` (lebih aman)|
|Tidak ada constructor|Pakai constructor|

---

Kalau kamu mau, aku bisa bantu juga menambahkan:

- Fungsi untuk **menghapus tree** secara rekursif (agar tidak ada memory leak)
    
- Atau membuat versi **class-based** (dengan method dan encapsulation)
    

Mau lanjut ke salah satu dari itu, atau ke materi baru?