---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 14TH-TREE-00A8
nama_algoritma: 
kategori_algoritma: tree algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: programiz.com & chatgpt.com
date_learned: 2025-06-24T16:40:00
tags:
  - tree-algorithm
---
---
# Binary Search Tree (BST)

**Binary Search Tree (BST)** adalah struktur data yang memungkinkan kita **menyimpan daftar angka dalam keadaan terurut** secara efisien.

Mengapa disebut Binary Search Tree?

- Disebut binary tree karena setiap node dalam tree memiliki maksimal dua anak.
    
- Disebut search tree karena dapat digunakan untuk mencari suatu elemen dalam waktu rata-rata O(log n) jika tree seimbang.
    

Properti yang membedakan BST dari binary tree biasa:

1. Semua node di subtree kiri memiliki nilai lebih kecil dari nilai node induknya.
    
2. Semua node di subtree kanan memiliki nilai lebih besar dari nilai node induknya.
    
3. Kedua subtree (kiri dan kanan) dari setiap node juga merupakan BST, yaitu memenuhi dua properti di atas secara rekursif.
    
BST adalah dasar dari banyak struktur data lanjutan seperti AVL Tree dan Red-Black Tree. 

![[08 - Binary Search Tree-1.png]]

Pohon di sebelah kanan **bukan** merupakan Binary Search Tree. Hal ini karena **subtree kanan dari node "3" mengandung nilai yang lebih kecil dari 3**, yang **melanggar aturan BST**.

Dua Operasi Dasar pada Binary Search Tree:
## Operasi Pencarian (Search Operation)

Algoritma pencarian pada Binary Search Tree (BST) bergantung pada sifat bahwa subtree kiri berisi nilai-nilai yang lebih kecil dari root, dan subtree kanan berisi nilai-nilai yang lebih besar.

Jika nilai yang dicari lebih kecil dari nilai root, maka sudah pasti nilainya tidak mungkin ada di subtree kanan. Jadi, kita hanya perlu mencari di subtree kiri.

Sebaliknya, jika nilai yang dicari lebih besar dari root, maka kita cukup mencari di subtree kanan saja.

---

### Algoritma:

```
Jika root == NULL
    kembalikan NULL

Jika number == root->data
    kembalikan root->data

Jika number < root->data
    kembalikan search(root->left)

Jika number > root->data
    kembalikan search(root->right)
```

Mari kita coba memvisualisasikan proses pencarian pada Binary Search Tree (BST) dengan diagram berikut.

![[08 - Binary Search Tree-4.png]]

![[08 - Binary Search Tree-3.png]]

![[08 - Binary Search Tree-5.png]]

![[08 - Binary Search Tree-6.png]]

> programiz

Jika nilai yang dicari ditemukan, kita akan **mengembalikannya** (return), sehingga nilai tersebut akan **dipropagasikan ke atas** dalam setiap langkah rekursi — seperti yang diperlihatkan pada gambar.

---
Artinya:

- Saat fungsi `search()` menemukan nilai di suatu node, maka fungsi tersebut akan segera mengembalikan nilai itu.
    
- Nilai ini akan terus dibawa naik ke pemanggilan fungsi sebelumnya hingga mencapai pemanggilan pertama di `main()` atau fungsi pemanggil lainnya.
    

Contoh sederhana ilustrasinya:

```cpp
int search(Node* root, int target) {
    if (root == nullptr) return -1;
    if (root->data == target) return root->data;

    if (target < root->data)
        return search(root->left, target);
    else
        return search(root->right, target);
}
```

Misalnya kita cari `6`, dan ditemukan di `root->left->right`, maka nilai `6` akan dikembalikan dari fungsi rekursif itu, lalu terus dikembalikan oleh semua pemanggil sebelumnya sampai ke `main()`.

---
> programiz

Jika kamu perhatikan, kita telah memanggil `return search(struct node*)` **empat kali** dalam algoritma pencarian.

Tujuannya adalah agar **nilai yang ditemukan** (baik berupa node yang berisi nilai tersebut atau `NULL` jika tidak ditemukan) **dipropagasikan kembali** ke atas melalui setiap level pemanggilan rekursif.

Jadi ketika kita menulis:

```cpp
return search(root->left);  // atau search(root->right)
```

Hasil dari pencarian di subtree tersebut **langsung dikembalikan** ke fungsi pemanggilnya.

Hal ini akan terus berlangsung hingga fungsi `search(root, number)` yang pertama kali dipanggil **mengembalikan hasil akhir**, baik itu:

- Pointer ke node yang mengandung nilai yang dicari, atau
    
- `NULL` jika nilai tidak ditemukan.
    

Dengan kata lain, kita tidak perlu menyimpan hasilnya ke variabel sementara, karena kita langsung meneruskan (return) hasil rekursinya.

![[08 - Binary Search Tree-7.png]]

> programiz

Jika nilai yang dicari **tidak ditemukan** di dalam Binary Search Tree (BST), maka pencarian akan terus berjalan ke subtree kiri atau kanan — hingga akhirnya mencapai **anak kiri atau anak kanan dari sebuah node daun**, yang **bernilai `NULL`**.

Ketika `NULL` ini ditemukan, maka:

- Fungsi `search()` akan **mengembalikan `NULL`**,
    
- Dan nilai `NULL` ini akan terus **dipropagasikan ke atas** melalui semua pemanggilan fungsi sebelumnya,
    
- Hingga mencapai `search(root, number)` yang pertama kali dipanggil.
    

Dengan begitu, kita tahu bahwa **nilai yang dicari tidak ada di dalam tree**.

Contoh:

Mencari angka `2` dalam tree ini:

```

        8
       / \
      3   10
     / \    \
    1   6    14
    
```

Langkah-langkah:

- 2 < 8 → ke kiri
    
- 2 < 3 → ke kiri
    
- 2 > 1 → ke kanan
    
- `1` tidak punya anak kanan → ketemu `NULL` → return `NULL`
    
- Nilai `NULL` ini naik terus sampai ke pemanggilan awal
    

Hasilnya: `2` tidak ditemukan.

## Insert Operation (Operasi Penyisipan)

Menyisipkan nilai ke dalam Binary Search Tree (BST) **mirip dengan proses pencarian**. Tujuan utamanya adalah **menjaga aturan BST tetap berlaku**, yaitu:

- Nilai di subtree kiri **lebih kecil** dari root
    
- Nilai di subtree kanan **lebih besar** dari root
    

Prosesnya:

1. **Bandingkan nilai baru dengan root**
    
    - Jika lebih kecil → pergi ke **subtree kiri**
        
    - Jika lebih besar → pergi ke **subtree kanan**
        
2. **Ulangi proses** ini secara rekursif hingga kita mencapai node yang anak kirinya atau anak kanannya adalah `NULL`.
    
3. **Sisipkan node baru** di posisi `NULL` tersebut.
    

Dengan kata lain, kita **menyusuri tree** seperti saat mencari, dan ketika kita menemukan tempat kosong (`NULL`), di situlah kita **letakkan node baru**.

### Algoritma Insert ke BST (Binary Search Tree)

Berikut adalah pseudocode untuk menyisipkan nilai ke dalam BST:

```
Jika node == NULL  
    return createNode(data)

Jika data < node->data  
    node->left = insert(node->left, data)

Jika data > node->data  
    node->right = insert(node->right, data)

return node
```

---

### Penjelasan:

- **Jika node saat ini kosong (`NULL`)**, berarti kita sudah menemukan tempat penyisipan. Buat dan kembalikan node baru.
    
- Jika **data lebih kecil**, lanjutkan penyisipan ke **subtree kiri**.
    
- Jika **data lebih besar**, lanjutkan ke **subtree kanan**.
    
- Kembalikan `node` agar rekursi tetap terhubung dengan struktur tree yang benar.
    

---

### Catatan:

Meskipun terlihat sederhana, algoritma ini bersifat **rekursif** dan mengandalkan pemahaman tentang **pengembalian node secara rekursif** agar perubahan tetap terhubung ke struktur utama BST.

---

### Ilustrasi Sederhana:

![[08 - Binary Search Tree-8.png]]

![[08 - Binary Search Tree-9.png]]

![[08 - Binary Search Tree-10.png]]

![[08 - Binary Search Tree-11.png]]

Kita memang sudah menambahkan node baru, **tapi kita masih harus keluar dari fungsi tanpa merusak struktur tree yang lain**.  
Di sinilah peran `return node;` di akhir fungsi menjadi penting.

- **Jika posisi saat ini adalah `NULL`**, maka node baru yang dibuat akan **dikembalikan dan otomatis terhubung ke node induknya**.
    
- Namun jika posisi saat ini **bukan `NULL`**, maka node yang sama dikembalikan **tanpa diubah**, dan proses ini terus berlangsung saat kita kembali naik ke atas hingga ke root.
    

Hal ini memastikan bahwa **saat kita kembali naik dalam proses rekursi**, **koneksi node-node lainnya tetap utuh dan tidak terganggu**.

![[08 - Binary Search Tree-12.png]]


## Operasi Penghapusan (Deletion Operation) 

Saat menghapus sebuah node dari BST, ada **tiga kasus utama** yang perlu dipertimbangkan, tergantung pada jumlah anak dari node yang ingin dihapus.

---

### Kasus 1: Node adalah daun (leaf node)
Dalam kasus pertama, node yang akan dihapus adalah leaf node. Dalam kasus seperti itu, cukup hapus node tersebut dari tree.

![[08 - Binary Search Tree-13.png]]

![[08 - Binary Search Tree-14.png]]

### Kasus 2: Node memiliki satu child
Dalam kasus kedua, node yang akan dihapus memiliki satu child node. Dalam kasus seperti itu, ikuti langkah-langkah berikut:

- Gantikan node tersebut dengan child-nya.
    
- Hapus child node dari posisi asalnya.

![[08 - Binary Search Tree-15.png]]

![[08 - Binary Search Tree-16.png]]

![[08 - Binary Search Tree-17.png]]

### Kasus 3: Node memiliki 2 child  
Dalam kasus ketiga, node yang akan dihapus memiliki dua child. Dalam kasus seperti itu, ikuti langkah-langkah berikut:

- Dapatkan inorder successor dari node tersebut.
    
- Gantikan node tersebut dengan inorder successor.
    
- Hapus inorder successor dari posisi asalnya.

![[08 - Binary Search Tree-18.png]]

![[08 - Binary Search Tree-19.png]]

![[08 - Binary Search Tree-20.png]]

## Implementasi dalam Kode

```cpp
// Operasi Binary Search Tree dalam C++

#include <iostream>
using namespace std;

// Struktur node
struct node {
  int key;
  struct node *left, *right;
};

// Membuat node baru
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Penelusuran inorder
void inorder(struct node *root) {
  if (root != NULL) {
    // Telusuri subtree kiri
    inorder(root->left);

    // Kunjungi root
    cout << root->key << " -> ";

    // Telusuri subtree kanan
    inorder(root->right);
  }
}

// Menyisipkan node
struct node *insert(struct node *node, int key) {
  // Kembalikan node baru jika tree kosong
  if (node == NULL) return newNode(key);

  // Telusuri ke posisi yang tepat dan sisipkan node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Mencari inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Cari node paling kiri (leftmost leaf)
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Menghapus node
struct node *deleteNode(struct node *root, int key) {
  // Kembalikan NULL jika tree kosong
  if (root == NULL) return root;

  // Temukan node yang akan dihapus
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    // Jika node memiliki satu anak atau tidak punya anak
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // Jika node memiliki dua anak
    struct node *temp = minValueNode(root->right);

    // Gantikan key node dengan inorder successor
    root->key = temp->key;

    // Hapus inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

// Kode utama
int main() {
  struct node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);

  cout << "Penelusuran inorder: ";
  inorder(root);

  cout << "\nSetelah menghapus 10\n";
  root = deleteNode(root, 10);
  cout << "Penelusuran inorder: ";
  inorder(root);
}
```

Berikut adalah **penjelasan per blok kode** dari program operasi **Binary Search Tree (BST)** dalam C++:

---

### 🔹 1. Header dan Namespace

```cpp
#include <iostream>
using namespace std;
```

- `#include <iostream>`: Mengimpor pustaka standar untuk input/output.
    
- `using namespace std;`: Agar bisa menggunakan `cout`, `endl`, dll. tanpa perlu menulis `std::`.
    

---

### 🔹 2. Struktur Node

```cpp
struct node {
  int key;
  struct node *left, *right;
};
```

- Mendefinisikan sebuah `struct node` yang merepresentasikan satu simpul (node) dalam BST.
    
- `key`: Menyimpan nilai data (biasanya bertipe `int`).
    
- `left` dan `right`: Pointer ke anak kiri dan anak kanan.
    

---

### 🔹 3. Membuat Node Baru

```cpp
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}
```

- Fungsi `newNode` membuat node baru dengan:
    
    - Menyimpan nilai `item` ke `key`.
        
    - Inisialisasi `left` dan `right` ke `NULL`.
        
- Menggunakan `malloc` (gaya C) untuk alokasi memori dinamis.
    

> **Catatan**: Dalam C++, lebih umum menggunakan `new`, tapi `malloc` masih valid.

---

### 🔹 4. Penelusuran Inorder

```cpp
void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);         // Telusuri anak kiri
    cout << root->key << " -> "; // Cetak nilai node saat ini
    inorder(root->right);        // Telusuri anak kanan
  }
}
```

- Melakukan traversal **inorder** (kiri → akar → kanan), hasilnya akan terurut.
    
- Fungsi rekursif ini mencetak nilai `key` dari setiap node secara berurutan.
    

---

### 🔹 5. Menyisipkan Node

```cpp
struct node *insert(struct node *node, int key) {
  if (node == NULL) return newNode(key); // Jika kosong, buat node baru

  if (key < node->key)                   // Jika lebih kecil, ke kiri
    node->left = insert(node->left, key);
  else                                   // Jika lebih besar/sama, ke kanan
    node->right = insert(node->right, key);

  return node;
}
```

- Fungsi ini menyisipkan nilai `key` ke posisi yang benar dalam BST, mengikuti aturan:
    
    - Lebih kecil → anak kiri.
        
    - Lebih besar atau sama → anak kanan.
        
- Secara rekursif mencari posisi yang tepat dan mengembalikan node root yang diperbarui.
    

---

### 🔹 6. Mencari Inorder Successor

```cpp
struct node *minValueNode(struct node *node) {
  struct node *current = node;
  while (current && current->left != NULL)
    current = current->left;

  return current;
}
```

- Fungsi ini mencari **inorder successor**, yaitu node **paling kiri** dari subtree tertentu.
    
- Dipakai saat menghapus node dengan dua anak: penggantinya adalah node terkecil di subtree kanan.
    

---

### 🔹 7. Menghapus Node

```cpp
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    struct node *temp = minValueNode(root->right);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}
```

🔸 Penjelasan kasus:

- **Jika node tidak ditemukan** (`root == NULL`), kembalikan NULL.
    
- **Jika key < root->key**, terus cari ke subtree kiri.
    
- **Jika key > root->key**, terus cari ke subtree kanan.
    
- **Jika node ditemukan**:
    
    - **Kasus 1 & 2**: node tidak punya anak atau hanya satu anak → gantikan langsung dengan anak yang tersedia.
        
    - **Kasus 3**: node punya dua anak → cari `inorder successor`, salin nilainya ke node sekarang, lalu hapus `inorder successor` dari subtree kanan.
        

---

### 🔹 8. Fungsi Main (Pengujian Program)

```cpp
int main() {
  struct node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);
```

- Membangun tree dengan memasukkan nilai-nilai tersebut ke BST.
    
- Struktur tree (kira-kira):
    

```

        8
       / \
      3   10
     / \     \
    1   6     14
       / \
      4   7
      
```

---

```cpp
  cout << "Penelusuran inorder: ";
  inorder(root);
```

- Melakukan penelusuran inorder (hasil akan terurut menaik).
    

---

```cpp
  cout << "\nSetelah menghapus 10\n";
  root = deleteNode(root, 10);
  cout << "Penelusuran inorder: ";
  inorder(root);
}
```

- Menghapus node `10` dari BST dan mencetak hasil traversal inorder setelah penghapusan.

---

## 📊 Kompleksitas Binary Search Tree

### ⏱️ Kompleksitas Waktu (Time Complexity)

| Operasi                | Best Case Complexity | Average Case Complexity | Worst Case Complexity |
| ---------------------- | -------------------- | ----------------------- | --------------------- |
| Search (Pencarian)     | O(log n)             | O(log n)                | O(n)                  |
| Insertion (Penyisipan) | O(log n)             | O(log n)                | O(n)                  |
| (Deletion) Penghapusan | O(log n)             | O(log n)                | O(n)                  |

> Di sini, `n` adalah jumlah node dalam tree.

📌 **Catatan:**

- Kasus terbaik dan rata-rata mengasumsikan bahwa tree relatif seimbang (balanced).
    
- Kasus terburuk terjadi jika tree berbentuk **linear** (seperti linked list), misalnya jika data dimasukkan dalam urutan yang sudah terurut.
    

---

### 💾 Kompleksitas Ruang (Space Complexity)

- Kompleksitas ruang untuk semua operasi: **O(n)**  
    (karena dalam skenario terburuk, semua node bisa disimpan dalam memori sekaligus, terutama dalam traversal rekursif).
    

---

## 🔧 Aplikasi Binary Search Tree

- Digunakan dalam **multilevel indexing** pada sistem basis data.
    
- Berguna untuk **pengurutan dinamis (dynamic sorting)**.
    
- Dipakai untuk **mengelola area memori virtual** dalam **kernel Unix**.
    
