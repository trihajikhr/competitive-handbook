---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 14TH-TREE-00A7
nama_algoritma: 
kategori_algoritma: tree algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: programiz.com & chatgpt.com
date_learned: 2025-06-24T16:17:00
tags:
  - tree-algorithm
---
---
# Balanced Binary Tree
Balanced Binary Tree, atau yang juga dikenal sebagai Height-Balanced Binary Tree, adalah sebuah pohon biner di mana selisih ketinggian antara subtree kiri dan subtree kanan dari setiap node tidak lebih dari 1.

> Untuk mempelajari lebih lanjut tentang tinggi pohon atau tinggi node, lihat kembali materi Tree Data Structure.

#### ✅ Syarat sebuah pohon disebut height-balanced:

1. **Selisih tinggi** antara subtree kiri dan kanan pada setiap node **tidak lebih dari 1**.
    
2. **Subtree kiri** merupakan pohon yang seimbang.
    
3. **Subtree kanan** juga merupakan pohon yang seimbang.

![[07 - Balanced Binary Tree-1.png]]

![[07 - Balanced Binary Tree-2.png]]

## Implementasi Kode

```cpp
// Memeriksa apakah sebuah pohon biner adalah height-balanced dalam C++

#include <iostream>
using namespace std;

#define bool int

class node {
public:
  int item;
  node *left;
  node *right;
};

// Membuat node baru
node *newNode(int item) {
  node *Node = new node();
  Node->item = item;
  Node->left = NULL;
  Node->right = NULL;

  return (Node);
}

// Memeriksa keseimbangan tinggi
bool checkHeightBalance(node *root, int *height) {
  // Basis rekursi: pohon kosong
  int leftHeight = 0, rightHeight = 0;

  int l = 0, r = 0;

  if (root == NULL) {
    *height = 0;
    return 1;
  }

  l = checkHeightBalance(root->left, &leftHeight);
  r = checkHeightBalance(root->right, &rightHeight);

  *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

  // Jika selisih tinggi subtree kiri dan kanan lebih dari 1, tidak seimbang
  if (std::abs(leftHeight - rightHeight) >= 2)
    return 0;

  else
    return l && r;
}

int main() {
  int height = 0;

  node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);

  if (checkHeightBalance(root, &height))
    cout << "Tree ini adalah balanced\n";
  else
    cout << "Tree ini tidak balanced\n";

   return 0;
   
}
```

Berikut ini adalah **penjelasan per blok kode program C++** untuk memeriksa apakah sebuah **binary tree adalah height-balanced**, lengkap dan jelas seperti biasa:

---

### 🔹 1. Header dan Namespace

```cpp
#include <iostream>
using namespace std;

#define bool int
```

📌 Penjelasan:

- `#include <iostream>`: Digunakan agar bisa memakai `cout` untuk menampilkan output ke layar.
    
- `using namespace std;`: Supaya tidak perlu menulis `std::cout`, cukup `cout`.
    
- `#define bool int`: Pendekatan lama agar bisa menggunakan `true` dan `false` sebagai integer (`1` dan `0`). _Di C++ modern seharusnya tidak perlu ini, karena `bool` sudah jadi tipe bawaan._
    

---

### 🔹 2. Definisi Struktur Node

```cpp
class node {
public:
  int item;
  node *left;
  node *right;
};
```

📌 Penjelasan:

- Mendefinisikan sebuah node dalam binary tree.
    
- `item`: nilai/data dari node.
    
- `left` dan `right`: pointer ke anak kiri dan anak kanan node.
    

---

### 🔹 3. Fungsi Membuat Node Baru

```cpp
node *newNode(int item) {
  node *Node = new node();
  Node->item = item;
  Node->left = NULL;
  Node->right = NULL;

  return (Node);
}
```

📌 Penjelasan:

- Fungsi ini mengalokasikan node baru dengan nilai `item`.
    
- Men-set `left` dan `right` ke `NULL` (belum punya anak).
    
- Mengembalikan pointer ke node yang baru dibuat.
    

---

### 🔹 4. Fungsi Memeriksa Keseimbangan Tinggi

```cpp
bool checkHeightBalance(node *root, int *height) {
  int leftHeight = 0, rightHeight = 0;
  int l = 0, r = 0;

  if (root == NULL) {
    *height = 0;
    return 1;
  }

  l = checkHeightBalance(root->left, &leftHeight);
  r = checkHeightBalance(root->right, &rightHeight);

  *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

  if (std::abs(leftHeight - rightHeight) >= 2)
    return 0;

  else
    return l && r;
}
```

📌 Penjelasan langkah demi langkah:

- `leftHeight` dan `rightHeight`: untuk menyimpan tinggi subtree kiri dan kanan.
    
- Basis rekursi: Jika `root == NULL`, maka tingginya 0 dan dianggap seimbang → kembalikan `true`.
    
- Rekursif ke subtree kiri dan kanan untuk menghitung tinggi masing-masing.
    
- Hitung tinggi total node saat ini dengan rumus:
    
    ```cpp
    max(leftHeight, rightHeight) + 1
    ```
    
- Jika selisih tinggi subtree kiri dan kanan ≥ 2, maka tidak seimbang.
    
- Jika selisihnya ≤ 1 **dan** subtree kiri dan kanan juga seimbang → maka node ini seimbang.
    

---

### 🔹 5. Fungsi Utama (`main`)

```cpp
int main() {
  int height = 0;

  node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);

  if (checkHeightBalance(root, &height))
    cout << "Tree ini adalah balanced\n";
  else
    cout << "Tree ini tidak balanced\n";
}
```

📌 Penjelasan:

- Membuat tree manual dengan root = 1, dan beberapa anak kiri/kanan.
    
- Panggil `checkHeightBalance()` untuk memeriksa apakah tree tersebut seimbang.
    
- Cetak hasilnya ke layar.
    

Tree yang dibentuk adalah:

```

        1
       / \
      2   3
     / \
    4   5
    
```

Tree ini seimbang karena selisih tinggi subtree tidak lebih dari 1 di setiap node.

---

### ✅ Kesimpulan

Kode ini:

- Efisien (O(n)) karena tinggi dihitung sambil mengecek keseimbangan.
    
- Sudah sesuai dengan definisi **balanced binary tree**.
    
- Hanya perlu perbaikan kecil di bagian `abs()` yang sudah kamu betulkan sebelumnya.
    

## Aplikasi Balanced Binary Tree

### 📌 1. Pencarian Data yang Efisien

Balanced binary tree digunakan agar operasi pencarian (`search`) bisa dilakukan dalam waktu **logaritmik**, yaitu **O(log n)**. Ini sangat penting saat jumlah data besar.

Contoh:

- **Binary Search Tree (BST)** yang seimbang
    
- **AVL Tree** atau **Red-Black Tree**  
    → digunakan dalam implementasi struktur seperti `std::map`, `std::set` di C++
    

---

### 📌 2. Penyimpanan dan Pengambilan Data Berurutan

Karena traversal `inorder` dari balanced BST akan menghasilkan urutan data yang terurut, tree ini digunakan untuk:

- Menyimpan **data numerik**
    
- Menyortir data dinamis secara efisien
    

---

### 📌 3. Sistem Database dan Indexing

Balanced binary trees digunakan di berbagai sistem database untuk:

- **Indexing cepat**
    
- **Query data secara efisien**  
    Contoh struktur: **B-Trees, AVL Trees, Red-Black Trees**
    

---

### 📌 4. Routing dan Kompresi Data

- Struktur pohon yang seimbang digunakan dalam **routing algorithm** (di jaringan).
    
- Tree yang seimbang dapat juga dimanfaatkan dalam algoritma **kompresi data**, seperti Huffman Tree yang cenderung seimbang untuk efisiensi decoding.
    

---

### 📌 5. Compiler dan Struktur Sintaks

Dalam **compiler**, pohon ekspresi atau pohon sintaks abstrak (AST) sering disusun dengan model pohon yang seimbang agar:

- Parsing lebih mudah
    
- Evaluasi ekspresi lebih cepat
    

---

### 📌 6. Gaming dan AI Decision Tree

Balanced binary tree digunakan dalam:

- Game AI → untuk **Decision Trees** (misalnya, AI lawan mengambil keputusan)
    
- Strategi pencarian gerakan → pencarian efisien menggunakan **Minimax Tree**
    
