---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 14TH-TREE-00A2
nama_algoritma: 
kategori_algoritma: tree algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: programiz.com
date_learned: 2025-06-24T00:08:00
tags:
  - tree-algorithm
---
Link sumber: [Tree Traversal](https://www.programiz.com/dsa/tree-traversal)

---
# Tree Traversal - inorder, preorder and postorder

Traversing sebuah tree berarti mengunjungi setiap node di dalam tree.  

Contohnya, kamu mungkin ingin menjumlahkan semua nilai di dalam tree, atau mencari nilai terbesar. Untuk melakukan operasi-operasi tersebut, kamu harus mengunjungi setiap node dari tree.

Struktur data linear seperti array, stack, queue, dan linked list hanya memiliki satu cara untuk membaca data.  

Namun, struktur data hierarkis seperti tree dapat ditelusuri (traverse) dengan berbagai cara.

![[02 - Tree Traversal - inorder, preorder and postorder-1.png]]

Mari kita pikirkan bagaimana kita bisa membaca elemen-elemen dari **tree** berdasarkan gambar diatas.

Misalnya:

- **Dari atas ke bawah, kiri ke kanan:**  
	```
	1 -> 12 -> 5 -> 6 -> 9
	```
    
- **Dari bawah ke atas, kiri ke kanan:**  
	```
	5 -> 6 -> 12 -> 9 -> 1
	```


Meskipun proses ini terlihat mudah, pendekatan tersebut tidak menghargai hierarki tree, dan hanya memperhatikan kedalaman node saja.

---

Sebagai gantinya, kita menggunakan metode traversal yang mempertimbangkan struktur dasar dari sebuah tree, yaitu:

```cpp
struct node {
    int data;
    struct node* left;
    struct node* right;
};
```

Pointer `left` dan `right` dari struct `node` tersebut bisa jadi menunjuk ke node-node lain yang juga memiliki child `left` dan `right`. Jadi, kita harus menganggapnya sebagai **subtree** (sub-tree), bukan hanya sekadar **sub-node**.

---

Berdasarkan struktur ini, setiap **tree** bisa dipandang sebagai gabungan dari:

- Sebuah **node** yang menyimpan **data**, dan
    
- Dua **subtree** (kiri dan kanan)
    

![[02 - Tree Traversal - inorder, preorder and postorder-2.png]]

Ingat bahwa tujuan kita adalah mengunjungi setiap node, jadi kita perlu mengunjungi semua node di **subtree** kiri, mengunjungi **root node**, dan mengunjungi semua node di **subtree** kanan juga.

Bergantung pada **urutan** kita melakukan hal-hal tersebut, terdapat **tiga jenis traversal utama**:

1. **Inorder Traversal**
    
2. **Preorder Traversal**
    
3. **Postorder Traversal**
    

---
### Inorder Traversal

- Pertama, kunjungi semua node di **subtree kiri**
    
- Kemudian kunjungi **root node**
    
- Lalu kunjungi semua node di **subtree kanan**
    

```cpp
inorder(root->left);
display(root->data);
inorder(root->right);
```

---

### Preorder Traversal

- Kunjungi terlebih dahulu **root node**
    
- Lalu kunjungi semua node di **subtree kiri**
    
- Kemudian kunjungi semua node di **subtree kanan**
    

```cpp
display(root->data);
preorder(root->left);
preorder(root->right);
```

---

### Postorder Traversal

- Kunjungi semua node di **subtree kiri**
    
- Kemudian semua node di **subtree kanan**
    
- Terakhir, kunjungi **root node**
    

```cpp
postorder(root->left);
postorder(root->right);
display(root->data);
```

---
## Visualisasi Traversal

**Mari kita visualisasikan inorder traversal.**  
Kita mulai dari **root node**…

![[02 - Tree Traversal - inorder, preorder and postorder-3.png]]

Kita menelusuri (traverse) terlebih dahulu subtree kiri.  

Namun, kita juga harus mengingat bahwa kita masih perlu mengunjungi root node dan subtree kanan setelah bagian kiri ini selesai.

Untuk itu, mari kita masukkan semua informasi ini ke dalam sebuah **stack**, supaya kita bisa mengingat urutan kunjungan yang tersisa.

![[02 - Tree Traversal - inorder, preorder and postorder-4.png]]

Sekarang, kita **menelusuri subtree** yang ditunjuk oleh **elemen paling atas (TOP)** dari **stack**.

Sekali lagi, kita mengikuti **aturan dasar inorder traversal**:

```
Left subtree -> root -> right subtree
```

Setelah **menelusuri subtree kiri**, kita masih **menyisakan**...

![[02 - Tree Traversal - inorder, preorder and postorder-5.png]]


Karena **node "5"** _tidak memiliki subtree_, maka kita bisa langsung **mencetaknya**.  
Setelah itu, kita **mencetak parent-nya**, yaitu **"12"**, lalu melanjutkan ke **child kanan-nya**, yaitu **"6"**.

Menyimpan semua informasi traversal ke dalam sebuah **stack** ternyata sangat membantu, karena setelah **subtree kiri dari root node** selesai ditelusuri, kita bisa langsung **mencetak root-nya** dan lanjut ke **subtree kanan**.

Setelah semua elemen ditelusuri, kita mendapatkan **hasil inorder traversal** sebagai berikut:

```
5 -> 12 -> 6 -> 1 -> 9
```

Kita tidak perlu membuat stack secara manual dalam implementasi traversal rekursif, karena mekanisme rekursi secara otomatis akan menjaga urutan traversal dengan benar untuk kita.

## Contoh Program C++

```cpp
// Traversal Tree dalam C++

#include <iostream>
using namespace std;

struct Node {
  int data;
  struct Node *left, *right;
  Node(int data) {
    this->data = data;
    left = right = NULL;
  }
};

// Traversal Preorder
void preorderTraversal(struct Node* node) {
  if (node == NULL)
    return;

  cout << node->data << "->";
  preorderTraversal(node->left);
  preorderTraversal(node->right);
}

// Traversal Postorder
void postorderTraversal(struct Node* node) {
  if (node == NULL)
    return;

  postorderTraversal(node->left);
  postorderTraversal(node->right);
  cout << node->data << "->";
}

// Traversal Inorder
void inorderTraversal(struct Node* node) {
  if (node == NULL)
    return;

  inorderTraversal(node->left);
  cout << node->data << "->";
  inorderTraversal(node->right);
}

int main() {
  struct Node* root = new Node(1);
  root->left = new Node(12);
  root->right = new Node(9);
  root->left->left = new Node(5);
  root->left->right = new Node(6);

  cout << "Traversal Inorder ";
  inorderTraversal(root);

  cout << "\nTraversal Preorder ";
  preorderTraversal(root);

  cout << "\nTraversal Postorder ";
  postorderTraversal(root);
  return 0;  
}

```

Sip! Berikut adalah **penjelasan per blok kode program traversal tree dalam C++**, agar kamu benar-benar paham alurnya:

---

### 🔹 1. Header dan namespace

```cpp
#include <iostream>
using namespace std;
```

- Mengimpor library `iostream` untuk keperluan input/output (`cout`).
    
- Menggunakan `namespace std` agar kita bisa menulis `cout` tanpa harus `std::cout`.
    

---

### 🔹 2. Struktur Node

```cpp
struct Node {
  int data;
  struct Node *left, *right;
  Node(int data) {
    this->data = data;
    left = right = NULL;
  }
};
```

- Mendefinisikan struktur `Node` untuk tree.
    
- Setiap node menyimpan:
    
    - `data` (nilai integer),
        
    - pointer `left` ke child kiri,
        
    - pointer `right` ke child kanan.
        
- Konstruktor `Node(int data)` menginisialisasi nilai `data` dan menyetel `left` serta `right` ke `NULL` (belum punya child saat dibuat).
    

---

### 🔹 3. Fungsi Traversal Preorder

```cpp
void preorderTraversal(struct Node* node) {
  if (node == NULL)
    return;

  cout << node->data << "->";
  preorderTraversal(node->left);
  preorderTraversal(node->right);
}
```

- **Urutan Preorder**: root → left → right
    
- Jika `node` kosong (`NULL`), tidak ada yang dilakukan.
    
- Mencetak data node sekarang, lalu lanjut ke subtree kiri dan kanan secara rekursif.
    

---

### 🔹 4. Fungsi Traversal Postorder

```cpp
void postorderTraversal(struct Node* node) {
  if (node == NULL)
    return;

  postorderTraversal(node->left);
  postorderTraversal(node->right);
  cout << node->data << "->";
}
```

- **Urutan Postorder**: left → right → root
    
- Mengunjungi child kiri dan child kanan terlebih dahulu, baru mencetak data node saat ini.
    

---

### 🔹 5. Fungsi Traversal Inorder

```cpp
void inorderTraversal(struct Node* node) {
  if (node == NULL)
    return;

  inorderTraversal(node->left);
  cout << node->data << "->";
  inorderTraversal(node->right);
}
```

- **Urutan Inorder**: left → root → right
    
- Mencetak node _di antara_ child kiri dan child kanan.
    

---

### 🔹 6. Fungsi `main()` – Membangun Tree dan Menjalankan Traversal

```cpp
int main() {
  struct Node* root = new Node(1);
  root->left = new Node(12);
  root->right = new Node(9);
  root->left->left = new Node(5);
  root->left->right = new Node(6);
```

- Membuat tree sebagai berikut:
    

```

        1
       / \
     12   9
    /  \
   5    6
   
```

---

### 🔹 7. Menampilkan Hasil Traversal

```cpp

	cout << "Traversal Inorder ";
	inorderTraversal(root);
	
	cout << "\nTraversal Preorder ";
	preorderTraversal(root);
	
	cout << "\nTraversal Postorder ";
	postorderTraversal(root);
	
```

- Menjalankan dan menampilkan hasil ketiga jenis traversal pada tree yang telah dibentuk.
    

---

### 🔹 8. Program selesai

```cpp
  return 0;  
}
```

- Menandakan akhir program utama.
    

---

### 🧠 Output Program

Berikut hasil traversal dari tree di atas:

```
Traversal Inorder 5->12->6->1->9->
Traversal Preorder 1->12->5->6->9->
Traversal Postorder 5->6->12->9->1->
```

---
