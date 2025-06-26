---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 14TH-TREE-00A6
nama_algoritma: 
kategori_algoritma: tree algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: programiz.com & chatgpt.com
date_learned: 2025-06-24T15:40:00
tags:
  - tree-algorithm
---
---
# Complete Binary Tree

Complete binary tree adalah binary tree di mana seluruh level terisi penuh, kecuali level paling bawah, yang terisi dari kiri ke kanan.

Tree ini mirip dengan full binary tree, namun memiliki dua perbedaan penting:

1. Semua leaf node berada di sisi kiri sebanyak mungkin.
    
2. Leaf node terakhir tidak harus memiliki pasangan (anak kanan). Artinya, complete binary tree tidak harus full.

![[06 - Complete Binary Tree-1.png]]

### 📌 Ringkasan Perbandingan:

|Sifat|Full Binary Tree|Complete Binary Tree|
|---|---|---|
|Semua internal node punya 2 anak|✅ Ya|❌ Tidak wajib|
|Semua level penuh|❌ Tidak selalu|✅ Ya, kecuali level terakhir|
|Level terakhir diisi dari kiri|❌ Tidak wajib|✅ Ya|
## Full Binary Tree vs Complete Binary Tree
![[06 - Complete Binary Tree-2.png]]


![[06 - Complete Binary Tree-3.png]]


![[06 - Complete Binary Tree-4.png]]

![[06 - Complete Binary Tree-5.png]]

---
## Bagaimana Complete Binary Tree Dibentuk?

1. **Pilih elemen pertama dari daftar sebagai root node.**  
    (Jumlah elemen pada level ke-1: 1)
	![[06 - Complete Binary Tree-6.png]]
	Langkah ini adalah dasar dari pembentukan **complete binary tree** dari sebuah array atau daftar. Dalam struktur seperti **heap** (min-heap atau max-heap), ini adalah proses standar, di mana elemen-elemen berikutnya akan diisi level demi level dari kiri ke kanan.

2. **Tempatkan elemen kedua sebagai anak kiri dari root node**, dan **elemen ketiga sebagai anak kanan**.  
    (Jumlah elemen pada level ke-2: 2)
	![[06 - Complete Binary Tree-7.png]]

	📌 Penjelasan:
	
	Setelah root terbentuk dari elemen pertama, kita lanjutkan ke **level kedua**, yang terdiri dari **dua posisi**:
	
	- Posisi kiri diisi terlebih dahulu (anak kiri root),
	    
	- Lalu posisi kanan (anak kanan root).
	    
	
	Ini mengikuti prinsip **pengisian dari kiri ke kanan**, yang merupakan ciri utama **complete binary tree**.
	
	```plaintext
	Input: [1, 2, 3]
	
	       1
	      / \
	     2   3
	```


3. Tempatkan dua elemen berikutnya sebagai anak-anak dari node kiri pada level kedua. Kemudian, tempatkan dua elemen berikutnya sebagai anak-anak dari node kanan pada level kedua.  
   (Jumlah elemen pada level ke-3: 4)
    
4. **Ulangi proses ini sampai semua elemen dalam daftar habis.**
	![[06 - Complete Binary Tree-8.png]]

	📌 **Penjelasan**: 
	
	- Tree diisi **dari atas ke bawah** dan **dari kiri ke kanan**.
	    
	- Setelah level ke-2 terisi (misal node `2` dan `3`), maka:
	    
	    - Elemen ke-4 dan ke-5 menjadi anak dari node `2`
	        
	    - Elemen ke-6 dan ke-7 menjadi anak dari node `3`
	        
	- Level ke-3 bisa menampung 4 elemen karena ada 2 parent node (masing-masing bisa punya 2 anak).
	    
	Contoh:
	
	```plaintext
	Input: [1, 2, 3, 4, 5, 6, 7]
	
	          1
	        /   \
	       2     3
	      / \   / \
	     4   5 6   7
	```
	
	Jika daftar punya lebih banyak elemen, maka level selanjutnya (level-4) akan kembali diisi dari kiri ke kanan, dan begitu seterusnya — **hingga elemen terakhir ditempatkan**.

## Implementasi Kode

```cpp
// Memeriksa apakah sebuah binary tree merupakan complete binary tree dalam C++

#include <iostream>
using namespace std;

struct Node {
  int key;
  struct Node *left, *right;
};

// Membuat node baru
struct Node *newNode(char k) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->key = k;
  node->right = node->left = NULL;
  return node;
}

// Menghitung jumlah total node dalam tree
int countNumNodes(struct Node *root) {
  if (root == NULL)
    return 0;
  return (1 + countNumNodes(root->left) + countNumNodes(root->right));
}

// Memeriksa apakah tree adalah complete binary tree
bool checkComplete(struct Node *root, int index, int numberNodes) {

  // Memeriksa apakah tree kosong
  if (root == NULL)
    return true;

  // Jika indeks sekarang melebihi jumlah node, maka bukan complete
  if (index >= numberNodes)
    return false;

  // Periksa subtree kiri dan kanan secara rekursif
  return (checkComplete(root->left, 2 * index + 1, numberNodes) &&
          checkComplete(root->right, 2 * index + 2, numberNodes));
}

int main() {
  struct Node *root = NULL;
  root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);

  int node_count = countNumNodes(root);
  int index = 0;

  if (checkComplete(root, index, node_count))
    cout << "Tree ini adalah complete binary tree\n";
  else
    cout << "Tree ini bukan complete binary tree\n";

  return 0;
}

```

Baik! Berikut penjelasan **per blok kode program** C++ untuk memeriksa apakah sebuah **binary tree adalah complete binary tree**:

---

### 🔹 1. Header dan Namespace

```cpp
#include <iostream>
using namespace std;
```

- `#include <iostream>`: digunakan untuk input/output standar (`cout`, `cin`).
    
- `using namespace std`: agar bisa menggunakan fungsi C++ tanpa menuliskan `std::` setiap kali.
    

---

### 🔹 2. Struktur Node

```cpp
struct Node {
  int key;
  struct Node *left, *right;
};
```

- Struktur data `Node` merepresentasikan satu simpul (node) dalam binary tree.
    
- Setiap node menyimpan:
    
    - `key`: nilai integer
        
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

- Membuat node baru dengan nilai `k`.
    
- Mengalokasikan memori secara manual dengan `malloc()`.
    
- Menetapkan anak kiri dan kanan ke `NULL` karena node baru belum punya anak.
    

> Catatan: Penggunaan `malloc` di C++ sebaiknya diganti dengan `new` agar lebih modern.

---

### 🔹 4. Fungsi `countNumNodes()` – Menghitung Jumlah Node

```cpp
int countNumNodes(struct Node *root) {
  if (root == NULL)
    return 0;
  return (1 + countNumNodes(root->left) + countNumNodes(root->right));
}
```

- Fungsi rekursif untuk menghitung **jumlah node dalam tree**.
    
- Jika `root` kosong, kembalikan 0.
    
- Jika tidak, jumlahkan 1 (node saat ini) + jumlah node di kiri + jumlah node di kanan.
    

---

### 🔹 5. Fungsi `checkComplete()` – Pemeriksaan Complete Binary Tree

```cpp
bool checkComplete(struct Node *root, int index, int numberNodes) {
  if (root == NULL)
    return true;

  if (index >= numberNodes)
    return false;

  return (checkComplete(root->left, 2 * index + 1, numberNodes) &&
          checkComplete(root->right, 2 * index + 2, numberNodes));
}
```

#### Penjelasan:

- **Parameter**:
    
    - `root`: node yang sedang diperiksa
        
    - `index`: indeks saat ini seolah-olah tree disimpan dalam array
        
    - `numberNodes`: total jumlah node dalam tree
        
- **Logika**:
    
    - Jika `root == NULL`, artinya tidak ada node, maka tetap valid.
        
    - Jika `index >= numberNodes`, berarti ada node yang menempati indeks di luar batas, **maka bukan complete tree**.
        
    - Periksa subtree kiri (`2*i + 1`) dan kanan (`2*i + 2`) secara rekursif.
        

> Prinsip ini mengikuti model array untuk heap:
> 
> - Parent di indeks `i`
>     
> - Anak kiri di `2*i + 1`
>     
> - Anak kanan di `2*i + 2`
>     

---

### 🔹 6. Fungsi `main()` – Menjalankan Program

```cpp
int main() {
  struct Node *root = NULL;
  root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
```

- Tree yang dibentuk seperti ini:
    

```

        1
      /   \
     2     3
    / \   /
   4   5 6
   
```

- Level terakhir (level 3) hanya memiliki 3 node (4,5,6) dan **terisi dari kiri ke kanan**, jadi ini adalah **complete binary tree**.
    

```cpp
  int node_count = countNumNodes(root);
  int index = 0;
```

- Hitung jumlah total node (`node_count`)
    
- Mulai pemeriksaan dari indeks `0` (root)
    

```cpp
  if (checkComplete(root, index, node_count))
    cout << "Tree ini adalah complete binary tree\n";
  else
    cout << "Tree ini bukan complete binary tree\n";

  return 0;
}
```

- Jalankan pengecekan dan tampilkan hasilnya di layar.
    

---

### ✅ Output

```
Tree ini adalah complete binary tree
```

---

Baik! Berikut ini adalah versi **modern C++** dari kode kamu sebelumnya yang **mengganti `malloc` dengan `new`**, serta **menghilangkan kebutuhan casting dan penggunaan header `stdlib.h`**:

---

## ✅ Versi Modern: Memeriksa Complete Binary Tree Menggunakan `new`

```cpp
#include <iostream>
using namespace std;

struct Node {
  int key;
  Node *left, *right;
};

// Membuat node baru menggunakan `new`
Node* newNode(int k) {
  Node* node = new Node;
  node->key = k;
  node->left = node->right = nullptr;
  return node;
}

// Menghitung jumlah node di tree
int countNumNodes(Node* root) {
  if (root == nullptr)
    return 0;
  return 1 + countNumNodes(root->left) + countNumNodes(root->right);
}

// Memeriksa apakah tree merupakan complete binary tree
bool checkComplete(Node* root, int index, int numberNodes) {
  if (root == nullptr)
    return true;

  if (index >= numberNodes)
    return false;

  return checkComplete(root->left, 2 * index + 1, numberNodes) &&
         checkComplete(root->right, 2 * index + 2, numberNodes);
}

int main() {
  Node* root = nullptr;
  root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);

  int node_count = countNumNodes(root);
  int index = 0;

  if (checkComplete(root, index, node_count))
    cout << "Tree ini adalah complete binary tree\n";
  else
    cout << "Tree ini bukan complete binary tree\n";

  return 0;
}
```

---

#### ✅ Perubahan Utama:

| Sebelumnya (lama)                     | Sekarang (modern C++)    |
| ------------------------------------- | ------------------------ |
| `struct Node* node = (Node*)malloc()` | `Node* node = new Node;` |
| `NULL`                                | `nullptr`                |
| Butuh `#include <stdlib.h>`           | ❌ Tidak perlu            |
|                                       |                          |

---
Tentu! Berikut ini adalah **penjelasan per blok kode program** versi modern (menggunakan `new`) untuk memeriksa apakah sebuah **binary tree adalah complete binary tree**:

---

### 🔹 1. Header dan Namespace

```cpp
#include <iostream>
using namespace std;
```

- Mengimpor library untuk input/output (`cout`, `endl`, dll).
    
- `using namespace std;` agar tidak perlu mengetik `std::` berulang kali.
    

---

### 🔹 2. Struktur Node

```cpp
struct Node {
  int key;
  Node *left, *right;
};
```

- Mendefinisikan satu **node** dalam binary tree.
    
- Setiap node memiliki:
    
    - `key`: data (tipe integer)
        
    - `left`: pointer ke anak kiri
        
    - `right`: pointer ke anak kanan
        

---

### 🔹 3. Fungsi `newNode()` – Membuat Node Baru

```cpp
Node* newNode(int k) {
  Node* node = new Node;
  node->key = k;
  node->left = node->right = nullptr;
  return node;
}
```

- Membuat dan menginisialisasi node baru:
    
    - `key` diisi dengan nilai `k`
        
    - `left` dan `right` di-set ke `nullptr` (artinya belum ada anak)
        
- Menggunakan `new` agar sesuai dengan standar C++ modern
    

---

### 🔹 4. Fungsi `countNumNodes()` – Menghitung Total Node

```cpp
int countNumNodes(Node* root) {
  if (root == nullptr)
    return 0;
  return 1 + countNumNodes(root->left) + countNumNodes(root->right);
}
```

- Fungsi rekursif untuk menghitung **jumlah seluruh node dalam tree**.
    
- Base case: jika node kosong (`nullptr`), kembalikan 0.
    
- Rekursi: jumlahkan 1 (node saat ini) + total node di kiri + total node di kanan.
    

---

### 🔹 5. Fungsi `checkComplete()` – Memeriksa Complete Binary Tree

```cpp
bool checkComplete(Node* root, int index, int numberNodes) {
  if (root == nullptr)
    return true;

  if (index >= numberNodes)
    return false;

  return checkComplete(root->left, 2 * index + 1, numberNodes) &&
         checkComplete(root->right, 2 * index + 2, numberNodes);
}
```

#### Penjelasan:

- Tujuan: memeriksa apakah **semua node berada di posisi yang benar** seperti pada array dari complete binary tree.
    
- `index` menunjukkan posisi virtual node seolah-olah tree disimpan dalam array:
    
    - Root: index 0
        
    - Anak kiri: `2*i + 1`
        
    - Anak kanan: `2*i + 2`
        
- **Langkah-langkah**:
    
    1. Jika node kosong, maka valid.
        
    2. Jika `index >= numberNodes`, berarti posisi ini seharusnya kosong, tapi malah ada node → **bukan complete tree**.
        
    3. Lakukan pemeriksaan rekursif pada anak kiri dan kanan.
        

---

### 🔹 6. Fungsi `main()` – Menyusun dan Mengeksekusi Tree

```cpp
int main() {
  Node* root = nullptr;
  root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
```

- Tree yang dibuat:
    

```

        1
      /   \
     2     3
    / \   /
   4   5 6
   
```

- Ini adalah **complete binary tree**, karena semua level terisi penuh, dan level terakhir terisi dari **kiri ke kanan**.
    

---

```cpp
  int node_count = countNumNodes(root);
  int index = 0;
```

- Hitung total node yang dimiliki tree (`node_count`)
    
- Mulai pemeriksaan dari root (index 0)
    

---

```cpp
  if (checkComplete(root, index, node_count))
    cout << "Tree ini adalah complete binary tree\n";
  else
    cout << "Tree ini bukan complete binary tree\n";

  return 0;
}
```

- Hasilkan output sesuai hasil pemeriksaan:
    
    - Jika `true`: tree memenuhi sifat complete binary tree.
        
    - Jika `false`: tidak memenuhi.
        
- Program selesai dengan `return 0`.
    

---

### ✅ Output dari program:

```
Tree ini adalah complete binary tree
```

## Hubungan antara Indeks Array dan Elemen Tree

**Complete Binary Tree** memiliki sifat unik yang memungkinkan kita menemukan **anak** dan **induk** (parent) dari suatu node hanya dengan menggunakan **indeks array**.

📌 Jika indeks suatu elemen dalam array adalah $i$, maka:

- **Anak kiri** (left child) berada di indeks:
    $$2i + 1$$
- **Anak kanan** (right child) berada di indeks:
    
    $$2i + 2$$
- **Induk** (parent) dari elemen di indeks `i` berada di:
    
    $$\left\lfloor \frac{i - 1}{2} \right\rfloor$$
    
    _(dibulatkan ke bawah)_

---
### Mari kita uji:

```
Left child of 1 (index 0)
= element in (2*0+1) index 
= element in 1 index 
= 12


Right child of 1
= element in (2*0+2) index
= element in 2 index 
= 9

Similarly,
Left child of 12 (index 1)
= element in (2*1+1) index
= element in 3 index
= 5

Right child of 12
= element in (2*1+2) index
= element in 4 index
= 6
```

Misalkan kita punya array:  
`[1, 12, 9, 5, 6]`

#### 🔹 Anak dari elemen `1` (di indeks 0):

- Anak kiri = indeks `2*0 + 1` = **1** → elemen `12`
    
- Anak kanan = indeks `2*0 + 2` = **2** → elemen `9`
    

#### 🔹 Anak dari elemen `12` (di indeks 1):

- Anak kiri = indeks `2*1 + 1` = **3** → elemen `5`
    
- Anak kanan = indeks `2*1 + 2` = **4** → elemen `6`
    

#### 🔹 Cek induk:

```
Parent of 9 (position 2) 
= (2-1)/2 
= ½ 
= 0.5
~ 0 index 
= 1

Parent of 12 (position 1) 
= (1-1)/2 
= 0 index 
= 1
```

- Induk dari elemen `9` (indeks 2):
    $$\left\lfloor \frac{2 - 1}{2} \right\rfloor = \left\lfloor 0.5 \right\rfloor = 0 → \text elemen \;1$$
- Induk dari elemen `12` (indeks 1):
    $$\left\lfloor \frac{1 - 1}{2} \right\rfloor = 0 → elemen \;1$$

---

### Mengapa Ini Penting?

📌 Memahami pemetaan antara **indeks array** dan **posisi tree** sangat penting dalam:

- Membangun **struktur data Heap**
    
- Melakukan **Heap Sort**
    

Dengan struktur seperti ini, kita dapat menyimpan **Complete Binary Tree** dalam **array biasa tanpa pointer**, dan navigasi (parent/child) bisa dilakukan menggunakan rumus indeks saja — **efisien dan cepat!**

---

## Aplikasi Complete Binary Tree

- **Struktur data berbasis heap** (Min Heap, Max Heap)
    
- **Heap Sort** (algoritma sorting berbasis heap)
    

---

Kalau kamu mau, kita bisa lanjut ke:

- Penjelasan **Heap (Min/Max)**,
    
- Implementasi **Heap Sort** berbasis array dan complete binary tree,
    
- Atau ke topik binary tree lain seperti **Balanced Binary Tree**.
    

