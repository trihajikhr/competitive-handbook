---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 14TH-TREE-00A5
nama_algoritma: 
kategori_algoritma: tree algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: programiz.com & chatgpt.com
date_learned: 2025-06-24T15:02:00
tags:
  - tree-algorithm
---
---
# Perfect Binary Tree

**Perfect binary tree** adalah jenis binary tree di mana **setiap internal node memiliki tepat dua anak**, dan **seluruh leaf node berada pada level yang sama**.

Artinya, tidak ada node yang "nanggung": semua cabang lengkap, dan semua daun sejajar.

![[05 - Perfect Binary Tree-1.png]]

Semua **internal node** memiliki **derajat (degree) sebesar 2**.

Secara rekursif, **perfect binary tree** dapat didefinisikan sebagai berikut:

- Jika sebuah node **tidak memiliki anak**, maka itu adalah **perfect binary tree dengan tinggi** `h = 0`.
    
- Jika sebuah node memiliki `h > 0`, maka itu adalah **perfect binary tree** **jika dan hanya jika**:
    
    - **kedua subtreenya** memiliki **tinggi** `h - 1`, dan
        
    - **tidak saling tumpang tindih** (_non-overlapping_).
        

![[05 - Perfect Binary Tree-2.png]]

## Implementasi dalam Kode

```cpp
// Memeriksa apakah suatu binary tree adalah perfect binary tree dalam C++

#include <iostream>
using namespace std;

struct Node {
    int key;
    struct Node *left, *right;
};

// Menghitung kedalaman dengan mempertimbangkan subtree kiri dan kanan
int depth(Node *node) {
    if (node == NULL) {
        return 0;
    }
    int leftDepth = depth(node->left);
    int rightDepth = depth(node->right);
    return max(leftDepth, rightDepth) + 1;
}

// Memeriksa apakah tree merupakan perfect binary tree
bool isPerfectR(struct Node *root, int d, int level = 0) {
    if (root == NULL)
        return true;

    // Jika leaf node, pastikan berada di level yang benar
    if (root->left == NULL && root->right == NULL)
        return (d == level + 1);

    // Jika hanya salah satu anak yang ada, maka bukan perfect
    if (root->left == NULL || root->right == NULL)
        return false;

    // Periksa subtree kiri dan kanan secara rekursif
    return isPerfectR(root->left, d, level + 1) &&
           isPerfectR(root->right, d, level + 1);
}

// Fungsi utama untuk memeriksa perfect binary tree
bool isPerfect(Node *root) {
    int d = depth(root);
    return isPerfectR(root, d);
}

// Membuat node baru
struct Node *newNode(int k) {
    struct Node *node = new Node;
    node->key = k;
    node->right = node->left = NULL;
    return node;
}

int main() {
    struct Node *root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    if (isPerfect(root))
        cout << "Tree ini adalah perfect binary tree\n";
    else
        cout << "Tree ini bukan perfect binary tree\n";

    return 0;
}
```

---
Mantap! Berikut penjelasan **per blok kode** dari program untuk **memeriksa apakah sebuah binary tree adalah perfect binary tree**:

---

### 🔹 1. Header dan Namespace

```cpp
#include <iostream>
using namespace std;
```

- Digunakan untuk input/output standar (`cout`).
    
- `using namespace std;` agar kita bisa menggunakan elemen standar C++ tanpa awalan `std::`.
    

---

### 🔹 2. Struktur Node

```cpp
struct Node {
    int key;
    struct Node *left, *right;
};
```

- Struktur `Node` digunakan untuk menyimpan informasi:
    
    - `key`: nilai data
        
    - `left`: pointer ke anak kiri
        
    - `right`: pointer ke anak kanan
        

---

### 🔹 3. Fungsi `depth()` – Menghitung Kedalaman Maksimum Tree

```cpp
int depth(Node *node) {
    if (node == NULL) {
        return 0;
    }
    int leftDepth = depth(node->left);
    int rightDepth = depth(node->right);
    return max(leftDepth, rightDepth) + 1;
}
```

- Fungsi ini digunakan untuk menghitung **kedalaman (tinggi) tree**.
    
- Dilakukan secara rekursif:
    
    - Hitung kedalaman subtree kiri dan kanan,
        
    - Ambil nilai maksimum,
        
    - Tambah 1 untuk menghitung root sekarang.
        

---

### 🔹 4. Fungsi `isPerfectR()` – Pemeriksaan Rekursif

```cpp
bool isPerfectR(struct Node *root, int d, int level = 0)
```

Fungsi rekursif utama untuk menentukan apakah tree perfect atau tidak. Parameter:

- `root`: pointer ke node saat ini
    
- `d`: kedalaman total tree
    
- `level`: level node saat ini (default = 0 untuk root)
    

Isi fungsinya:

```cpp
if (root == NULL)
    return true;
```

- Jika node kosong, tetap dianggap "perfect".
    

```cpp
if (root->left == NULL && root->right == NULL)
    return (d == level + 1);
```

- Jika node adalah **leaf**, maka harus berada tepat di **level terdalam**.
    

```cpp
if (root->left == NULL || root->right == NULL)
    return false;
```

- Jika node **hanya punya satu anak**, maka langsung bukan perfect.
    

```cpp
return isPerfectR(root->left, d, level + 1) &&
       isPerfectR(root->right, d, level + 1);
```

- Rekursi ke subtree kiri dan kanan.
    
- Keduanya harus valid agar tree tetap dianggap perfect.
    

---

### 🔹 5. Fungsi `isPerfect()` – Fungsi Utama

```cpp
bool isPerfect(Node *root) {
    int d = depth(root);
    return isPerfectR(root, d);
}
```

- Fungsi utama yang dipanggil dari `main()`.
    
- Pertama-tama menghitung kedalaman tree,
    
- Lalu meneruskan pemeriksaan rekursif lewat `isPerfectR()`.
    

---

### 🔹 6. Fungsi `newNode()` – Membuat Node Baru

```cpp
struct Node *newNode(int k) {
    struct Node *node = new Node;
    node->key = k;
    node->right = node->left = NULL;
    return node;
}
```

- Fungsi pembantu untuk membuat node baru.
    
- Menggunakan `new` (bukan `malloc` lagi).
    
- Inisialisasi nilai data dan pointer anak ke `NULL`.
    

---

### 🔹 7. Fungsi `main()` – Membangun Tree dan Menjalankan Pemeriksaan

```cpp
int main() {
    struct Node *root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
```

Tree yang dibentuk adalah:

```

         1
       /   \
      2     3
     / \   / \
    4   5 6   7
    
```

- Ini adalah **perfect binary tree**:
    
    - Semua internal node memiliki **dua anak**.
        
    - Semua leaf node berada di **level yang sama** (level ke-2 dari root).
        

```cpp
    if (isPerfect(root))
        cout << "Tree ini adalah perfect binary tree\n";
    else
        cout << "Tree ini bukan perfect binary tree\n";
```

- Menampilkan hasil dari pemeriksaan.
    

---

### ✅ Output Program

```
Tree ini adalah perfect binary tree
```

---
## Teorema pada Perfect Binary Tree

Beberapa sifat matematis yang penting dari **perfect binary tree**:

1. **Jumlah total node** pada perfect binary tree dengan tinggi $h$ adalah:
    
    $$2^{h+1} - 1$$
    
    Artinya, jika tinggi tree adalah 3, maka total node-nya:  
    
    $$2^{3+1} - 1 = 16 - 1 = 15$$
    
2. **Tinggi** dari perfect binary tree dengan $n$ node adalah:
    
    $$\log_2(n + 1) - 1 = \Theta(\ln(n))$$
    
    Ini menunjukkan bahwa tinggi tree bertumbuh **logaritmik** terhadap jumlah node.
    
3. **Jumlah leaf node** pada perfect binary tree dengan tinggi $h$ adalah:
    
    $$2^h$$
    
    Karena seluruh leaf node berada pada level terakhir, dan level tersebut penuh.
    
4. **Kedalaman rata-rata** sebuah node pada perfect binary tree adalah:
    
    $$\Theta(\ln(n))$$
    
    Artinya secara rata-rata, kita butuh waktu logaritmik untuk mengakses sebuah node dalam tree — sangat efisien!
    
