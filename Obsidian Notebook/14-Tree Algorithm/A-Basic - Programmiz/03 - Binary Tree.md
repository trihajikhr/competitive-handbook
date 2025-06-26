---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 14TH-TREE-00A3
nama_algoritma: 
kategori_algoritma: tree algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: programiz.com
date_learned: 2025-06-24T14:37:00
tags:
  - tree-algorithm
---
---
# Binary Tree

Binary tree adalah struktur data tree di mana setiap parent node dapat memiliki maksimal dua anak.

Setiap node dalam sebuah binary tree terdiri dari tiga bagian:

- data item (nilai data)
    
- alamat dari anak kiri (left child)
    
- alamat dari anak kanan (right child)
    
![[03 - Binary Tree-1.png]]

## Jenis-jenis Binary Tree

### 1. Full Binary Tree

Full binary tree adalah jenis khusus dari binary tree di mana setiap parent node (atau internal node) memiliki **tepat dua anak** atau **tidak memiliki anak sama sekali**.

![[03 - Binary Tree-2.png]]

### 2. Perfect Binary Tree

Perfect binary tree adalah jenis binary tree di mana setiap **internal node** memiliki **tepat dua anak**, dan **semua leaf node berada pada level yang sama**.

![[03 - Binary Tree-3.png]]

### 3. Complete Binary Tree

Complete binary tree mirip dengan full binary tree, namun memiliki dua perbedaan utama:

- Setiap level harus **terisi penuh**
    
- Semua leaf node harus **mengarah ke kiri**
    

Leaf node terakhir _boleh saja_ tidak memiliki saudara kanan (right sibling), artinya complete binary tree **tidak harus** menjadi full binary tree.

![[03 - Binary Tree-4.png]]

### 4. Degenerate atau Pathological Tree

Degenerate (atau pathological) tree adalah bentuk tree di mana **setiap node hanya memiliki satu anak**, entah itu anak kiri atau anak kanan saja.

![[03 - Binary Tree-5.png]]

### 5. Skewed Binary Tree

Skewed binary tree adalah bentuk degenerate/pathological tree di mana seluruh struktur tree **didominasi oleh node-node di satu sisi saja**, yaitu kiri atau kanan.

Karena itu, terdapat dua jenis skewed binary tree:

- **Left-skewed binary tree**: semua node anak berada di sisi kiri
    
- **Right-skewed binary tree**: semua node anak berada di sisi kanan
    

![[03 - Binary Tree-6.png]]

### 6. Balanced Binary Tree

Balanced binary tree adalah jenis binary tree di mana **selisih tinggi antara subtree kiri dan subtree kanan dari setiap node** adalah **0 atau 1**.

Tree seperti ini menjaga agar struktur tidak terlalu miring ke satu sisi, sehingga operasi seperti pencarian dan penyisipan tetap efisien. Biasanya AVL Tree dan Red-Black Tree termasuk dalam kategori balanced binary tree.

![[03 - Binary Tree-7.png]]


---
## Representasi Binary Tree

Sebuah **node** pada binary tree direpresentasikan menggunakan **struktur** yang berisi:

- **satu bagian data**, dan
    
- **dua pointer** yang menunjuk ke struktur lain dengan tipe yang sama (untuk anak kiri dan kanan).
    

Berikut adalah bentuk strukturnya dalam C/C++:

```cpp
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
```

Struktur ini memungkinkan pembentukan tree secara rekursif, karena `left` dan `right` menunjuk ke node-node yang juga memiliki struktur yang sama.

![[03 - Binary Tree-8.png]]

## Contoh Kode / Implementasi

Berikut adalah contoh implementasi dengan C++:

```cpp
// Binary Tree dalam C++

#include <stdlib.h>
#include <iostream>
using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
};

// Pembuatan node baru
struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}

// Traversal Preorder
void traversePreOrder(struct node *temp) {
  if (temp != NULL) {
    cout << " " << temp->data;
    traversePreOrder(temp->left);
    traversePreOrder(temp->right);
  }
}

// Traversal Inorder
void traverseInOrder(struct node *temp) {
  if (temp != NULL) {
    traverseInOrder(temp->left);
    cout << " " << temp->data;
    traverseInOrder(temp->right);
  }
}

// Traversal Postorder
void traversePostOrder(struct node *temp) {
  if (temp != NULL) {
    traversePostOrder(temp->left);
    traversePostOrder(temp->right);
    cout << " " << temp->data;
  }
}

int main() {
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);

  cout << "Traversal preorder: ";
  traversePreOrder(root);
  cout << "\nTraversal inorder: ";
  traverseInOrder(root);
  cout << "\nTraversal postorder: ";
  traversePostOrder(root);
}
```

---

### 🔹 1. Header & Namespace

```cpp
#include <stdlib.h>
#include <iostream>
using namespace std;
```

- `stdlib.h` digunakan untuk fungsi `malloc()` (alokasi memori secara manual).
    
- `iostream` untuk input/output (misalnya `cout`).
    
- `using namespace std;` agar tidak perlu menulis `std::cout`.
    

---

### 🔹 2. Struktur Node Binary Tree

```cpp
struct node {
  int data;
  struct node *left;
  struct node *right;
};
```

- Struktur `node` merepresentasikan sebuah simpul (node) pada binary tree.
    
- Setiap node menyimpan:
    
    - `data` (nilai integer),
        
    - `left` (pointer ke anak kiri),
        
    - `right` (pointer ke anak kanan).
        

---

### 🔹 3. Fungsi `newNode()` — Membuat Node Baru

```cpp
struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return (node);
}
```

- Membuat dan mengalokasikan memori untuk node baru menggunakan `malloc`.
    
- Mengisi nilai `data` dengan nilai yang diberikan.
    
- Menyetel `left` dan `right` menjadi `NULL` (belum ada anak).
    
- Mengembalikan pointer ke node baru.
    

---

### 🔹 4. Fungsi Preorder Traversal

```cpp
void traversePreOrder(struct node *temp) {
  if (temp != NULL) {
    cout << " " << temp->data;
    traversePreOrder(temp->left);
    traversePreOrder(temp->right);
  }
}
```

- **Urutan Preorder**: cetak node → kiri → kanan.
    
- Jika node tidak kosong:
    
    - Cetak nilainya,
        
    - Rekursif ke anak kiri,
        
    - Rekursif ke anak kanan.
        

---

### 🔹 5. Fungsi Inorder Traversal

```cpp
void traverseInOrder(struct node *temp) {
  if (temp != NULL) {
    traverseInOrder(temp->left);
    cout << " " << temp->data;
    traverseInOrder(temp->right);
  }
}
```

- **Urutan Inorder**: kiri → cetak node → kanan.
    
- Berguna untuk mendapatkan data secara berurutan jika tree-nya adalah Binary Search Tree (BST).
    

---

### 🔹 6. Fungsi Postorder Traversal

```cpp
void traversePostOrder(struct node *temp) {
  if (temp != NULL) {
    traversePostOrder(temp->left);
    traversePostOrder(temp->right);
    cout << " " << temp->data;
  }
}
```

- **Urutan Postorder**: kiri → kanan → cetak node.
    
- Biasanya digunakan untuk operasi seperti menghapus seluruh tree dari bawah ke atas.
    

---

### 🔹 7. Fungsi `main()` — Membangun Tree & Menjalankan Traversal

```cpp
int main() {
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
```

- Membentuk tree seperti ini:
    

```

        1
       / \
      2   3
     /
    4
    
```

- `root` adalah node utama.
    
- Node `2` adalah anak kiri dari `1`.
    
- Node `3` adalah anak kanan dari `1`.
    
- Node `4` adalah anak kiri dari `2`.
    

---

### 🔹 8. Menjalankan Traversal

```cpp
  cout << "Traversal preorder: ";
  traversePreOrder(root);
  cout << "\nTraversal inorder: ";
  traverseInOrder(root);
  cout << "\nTraversal postorder: ";
  traversePostOrder(root);
}
```

- Menampilkan hasil traversal untuk ketiga metode: preorder, inorder, dan postorder.
    
- Fungsi-fungsi ini akan mencetak urutan nilai yang dikunjungi sesuai jenis traversalnya.
    

---

### 🧾 Output Program (dari tree di atas)

```
Traversal preorder:  1 2 4 3
Traversal inorder:   4 2 1 3
Traversal postorder: 4 2 3 1
```

---

Kalau kamu mau, aku bisa bantu mengubah versi ini menjadi yang memakai `new` (C++ style)!

Oke! Kita ubah program C++ binary tree kamu dari **gaya C (dengan `malloc`)** menjadi **gaya modern C++ (dengan `new`)**, sehingga lebih idiomatis dan rapi.

Berikut versi yang sudah diperbarui:

---

## ✅ Versi C++ Style (menggunakan `new` alih-alih `malloc`)

```cpp
#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;

  // Constructor
  Node(int value) {
    data = value;
    left = nullptr;
    right = nullptr;
  }
};

// Preorder Traversal
void traversePreOrder(Node* node) {
  if (node != nullptr) {
    cout << " " << node->data;
    traversePreOrder(node->left);
    traversePreOrder(node->right);
  }
}

// Inorder Traversal
void traverseInOrder(Node* node) {
  if (node != nullptr) {
    traverseInOrder(node->left);
    cout << " " << node->data;
    traverseInOrder(node->right);
  }
}

// Postorder Traversal
void traversePostOrder(Node* node) {
  if (node != nullptr) {
    traversePostOrder(node->left);
    traversePostOrder(node->right);
    cout << " " << node->data;
  }
}

int main() {
  // Membuat struktur tree
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);

  cout << "Traversal preorder: ";
  traversePreOrder(root);

  cout << "\nTraversal inorder: ";
  traverseInOrder(root);

  cout << "\nTraversal postorder: ";
  traversePostOrder(root);

  return 0;
}
```

---

### 📝 Perubahan dan Keunggulannya:

- ❌ Tidak ada lagi `malloc()` dari C.
    
- ✅ Gunakan `new` dan constructor — lebih sesuai dengan **paradigma OOP** di C++.
    
- ✅ Nama `Node` pakai huruf besar, sesuai konvensi C++.
    
- ✅ Tidak perlu `struct` saat mendeklarasikan variabel, misalnya cukup `Node*` bukan `struct Node*`.
    

---

Kalau kamu mau, aku bisa bantu lanjutkan dengan:

- Visualisasi bagaimana traversal bekerja langkah demi langkah.
    
- Tambahkan destructor/manual delete untuk mencegah memory leak (opsional).
    
- Ubah ke versi dengan class dan encapsulation.
    

## Aplikasi Binary Tree

Binary tree digunakan dalam berbagai bidang karena strukturnya yang efisien. Beberapa aplikasi utamanya antara lain:

- Untuk **akses data yang cepat dan terstruktur**
    
- Dalam **algoritma routing** (seperti pada jaringan komputer)
    
- Untuk mengimplementasikan **struktur data heap** (digunakan dalam heap sort dan priority queue)
    
- Sebagai **syntax tree** dalam kompilator untuk menganalisis struktur program
    
