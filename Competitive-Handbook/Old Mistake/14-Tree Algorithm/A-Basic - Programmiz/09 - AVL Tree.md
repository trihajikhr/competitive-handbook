---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 14TH-TREE-00A9
nama_algoritma: 
kategori_algoritma: tree algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: programiz.com & chatgpt.com
date_learned: 2025-06-24T17:47:00
tags:
  - tree-algorithm
---
---
# AVL Tree

AVL tree adalah binary search tree (BST) yang menyeimbangkan dirinya sendiri (self-balancing), di mana setiap node menyimpan informasi tambahan yang disebut balance factor dengan nilai -1, 0, atau +1.

Nama AVL tree diambil dari nama penemunya, yaitu Georgy Adelson-Velsky dan Landis.

---

### ⚖️ Balance Factor

**Balance factor** dari suatu node dalam AVL tree adalah **selisih antara tinggi subtree kiri dan tinggi subtree kanan** dari node tersebut.

$$\text{Balance Factor} = \text{Tinggi Subtree Kiri} - \text{Tinggi Subtree Kanan}$$

atau bisa juga didefinisikan sebaliknya:

$$\text{Balance Factor} = \text{Tinggi Subtree Kanan} - \text{Tinggi Subtree Kiri}$$

Namun, yang umum dipakai adalah:

$$\text{Balance Factor} = \text{Height(left)} - \text{Height(right)}$$

---

### 🔄 Sifat Self-Balancing

Sifat **penyeimbangan otomatis (self-balancing)** dari AVL tree dijaga dengan **balance factor** ini.

- Untuk AVL tree yang **seimbang**, setiap node harus memiliki balance factor **dalam rentang -1 hingga +1**.
    
- Jika ada node yang balance factor-nya di luar rentang tersebut (misalnya ±2), maka tree harus diseimbangkan kembali melalui **rotasi**.
    

 Contoh AVL Tree yang Seimbang:
 
![[09 - AVL Tree-1.png]]

## ⚙️ Operasi pada AVL Tree

Berbagai operasi yang dapat dilakukan pada **AVL tree** antara lain:

Berikut adalah **terjemahan dan penjelasan** dari bagian awal tentang **rotasi pada AVL Tree**:

---

### 🔄 Rotasi Subtree dalam AVL Tree

Dalam operasi **rotasi**, posisi-posisi node dalam sebuah **subtree** akan **dipertukarkan** atau **diatur ulang** untuk mengembalikan keseimbangan tree.

Rotasi ini dilakukan ketika **balance factor** sebuah node keluar dari rentang valid (-1, 0, +1) akibat penyisipan atau penghapusan node.

Ada dua jenis utama rotasi:
#### 1. Left Rotation (Rotasi Kiri)

Pada **left-rotation**, susunan node yang awalnya miring ke **kanan** diubah menjadi miring ke **kiri**.

**Kapan digunakan?**  
Digunakan ketika **subtree kanan** lebih tinggi (balance factor = -2), dan penambahan terjadi pada **anak kanan** dari subtree kanan.

1. Misalkan tree awal adalah
   
   ![[09 - AVL Tree-2.png]]
2. Jika $y$ memiliki subtree kiri, tetapkan $x$ sebagai parent dari subtree kiri milik $y$.
   
   ![[09 - AVL Tree-3.png]]
3. Jika parent dari $x$ adalah `NULL`, tetapkan $y$ sebagai root dari tree.  
4. Jika tidak, jika $x$ adalah anak kiri dari $p$, tetapkan $y$ sebagai anak kiri dari $p$.  
5. Jika tidak, tetapkan $y$ sebagai anak kanan dari $p$.
   
   ![[09 - AVL Tree-4.png]]
6. Tetapkan $y$ sebagai parent dari $x$.
   
   ![[09 - AVL Tree-5.png]]

Berikut adalah **terjemahan dan penjelasan** tentang **Right Rotation** pada AVL Tree:

---

#### 2. Right Rotation (Rotasi Kanan)

Dalam **right-rotation**, susunan node yang awalnya miring ke **kiri** diubah menjadi miring ke **kanan**.

**Kapan digunakan?**

Right rotation digunakan ketika **subtree kiri** lebih tinggi (balance factor = +2), dan penambahan terjadi pada **anak kiri** dari subtree kiri.

1. Misalkan tree awal adalah
   
   ![[09 - AVL Tree-6.png]]
2. Jika $x$ memiliki subtree kanan, tetapkan $y$ sebagai parent dari subtree kanan milik $x$.
   
   ![[09 - AVL Tree-7.png]]
3. Jika parent dari $y$ adalah `NULL`, tetapkan $x$ sebagai root dari tree.  
4. Jika tidak, jika $y$ adalah anak kanan dari parent-nya $p$, tetapkan $x$ sebagai anak kanan dari $p$  
5. Jika tidak, tetapkan $x$ sebagai anak kiri dari $p$.
   
   ![[09 - AVL Tree-8.png]]
6. Tetapkan $x$ sebagai parent dari $y$.
   
   ![[09 - AVL Tree-9.png]]

---
### Rotasi Kiri-Kanan dan Kanan-Kiri  
Dalam rotasi kiri-kanan, susunan pertama-tama digeser ke kiri dan kemudian ke kanan.

1. Lakukan rotasi kiri pada x-y.
   
   ![[09 - AVL Tree-10.png]]
2. Lakukan rotasi kanan pada y-z.
   
   ![[09 - AVL Tree-11.png]]
Dalam rotasi kanan-kiri, susunan pertama-tama digeser ke kanan dan kemudian ke kiri.

3. Lakukan rotasi kanan pada x-y.
   
   ![[09 - AVL Tree-12.png]]
4. Lakukan rotasi kiri pada z-y.
   
   ![[09 - AVL Tree-13.png]]

---
### Algoritma untuk menyisipkan sebuah newNode  
Sebuah `newNode` selalu disisipkan sebagai leaf node dengan balance factor sama dengan 0.

1. Misalkan tree awal adalah:
   
   ![[09 - AVL Tree-14.png]]
   Misalkan node yang akan disisipkan adalah:
   ![[09 - AVL Tree-15.png]]
2. Pergi ke leaf node yang sesuai untuk menyisipkan `newNode` dengan menggunakan langkah-langkah rekursif berikut. Bandingkan` newKey` dengan `rootKey` dari tree saat ini.  
	- Jika $newKey < rootKey$, panggil algoritma penyisipan pada subtree kiri dari node saat ini hingga leaf node tercapai.  
	  <br/>
	- Jika tidak, jika $newKey > rootKey$, panggil algoritma penyisipan pada subtree kanan dari node saat ini hingga leaf node tercapai.  
	  <br/>
	- Jika tidak, kembalikan $leafNode$.
	
	![[09 - AVL Tree-16.png]]
3. Bandingkan $leafKey$ yang diperoleh dari langkah-langkah di atas dengan $newKey$:  
	- Jika $newKey < leafKey$, tetapkan $newNode$ sebagai $leftChild$ dari $leafNode$.  
	<br/>
	- Jika tidak, tetapkan $newNode$ sebagai rightChild dari $leafNode$.
	
	![[09 - AVL Tree-17.png]]
4. Perbarui $balanceFactor$ dari node-node.
   
   ![[09 - AVL Tree-18.png]]
5. Jika node-node tidak seimbang, maka seimbangkan kembali node tersebut.  
	1. Jika $balanceFactor > 1$, artinya tinggi subtree kiri lebih besar daripada subtree kanan. Maka, lakukan rotasi kanan atau rotasi kiri-kanan.  
		<br/>
		- Jika $newNodeKey < leftChildKey$ lakukan rotasi kanan.  
		<br/>
		- Jika tidak, lakukan rotasi kiri-kanan.
		![[09 - AVL Tree-20.png]]
	2. Jika $balanceFactor < -1$, artinya tinggi subtree kanan lebih besar daripada subtree kiri. Maka, lakukan rotasi kanan atau rotasi kanan-kiri. 
		<br/>
		- Jika $newNodeKey > rightChildKey$ lakukan rotasi kiri.  
		<br/>
		- Jika tidak, lakukan rotasi kanan-kiri.
6. Tree akhir adalah:
   ![[09 - AVL Tree-21.png]]
---
### Algoritma untuk Menghapus sebuah node  
Sebuah node selalu dihapus sebagai leaf node. Setelah menghapus node, balance factor dari node-node akan berubah. Untuk menyeimbangkan kembali balance factor tersebut, dilakukan rotasi yang sesuai.

1. Temukan `nodeToBeDeleted` (rekursi digunakan untuk menemukan `nodeToBeDeleted` dalam kode yang digunakan di bawah).
   
   ![[09 - AVL Tree-22.png]]
2. Ada tiga kasus untuk menghapus sebuah node:  
	1. Jika `nodeToBeDeleted` adalah leaf node (yaitu tidak memiliki anak), maka hapus `nodeToBeDeleted`.
	<br/>  
	2. Jika `nodeToBeDeleted` memiliki satu anak, maka gantikan isi dari `nodeToBeDeleted` dengan isi dari anaknya. Hapus anak tersebut.  
	<br/>
	3. Jika `nodeToBeDeleted` memiliki dua anak, temukan inorder successor `w` dari `nodeToBeDeleted` (yaitu node dengan nilai key minimum di subtree kanan).
	
	![[09 - AVL Tree-23.png]]
	A. Gantikan isi dari `nodeToBeDeleted` dengan isi dari `w`.
	
	![[09 - AVL Tree-24.png]]
	B. Hapus leaf node `w`.
	
	![[09 - AVL Tree-25.png]]
3. Perbarui `balanceFactor` dari node-node.
	
	![[09 - AVL Tree-26.png]]
4. Seimbangkan kembali tree jika balance factor dari salah satu node tidak sama dengan -1, 0, atau 1.  
	1. Jika `balanceFactor` dari `currentNode` > 1,  
		- A. Jika `balanceFactor` dari `leftChild` >= 0, lakukan rotasi kanan.
		  
		  ![[09 - AVL Tree-27.png]]
		- B. Jika tidak, lakukan rotasi kiri-kanan.
	2. Jika `balanceFactor` dari `currentNode` < -1,  
		- A. Jika `balanceFactor` dari `rightChild` <= 0, lakukan rotasi kiri.  
		- B. Jika tidak, lakukan rotasi kanan-kiri.  

5. Tree akhir adalah:
   
   ![[09 - AVL Tree-28.png]]
## Implementasi Kode Program

```cpp
// Implementasi AVL tree dalam C++

#include <iostream>
using namespace std;

class Node {
   public:
  int key;
  Node *left;
  Node *right;
  int height;
};

int max(int a, int b);

// Menghitung tinggi
int height(Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

// Pembuatan node baru
Node *newNode(int key) {
  Node *node = new Node();
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

// Rotasi kanan
Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  return x;
}

// Rotasi kiri
Node *leftRotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  return y;
}

// Mendapatkan balance factor dari setiap node
int getBalanceFactor(Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) -
       height(N->right);
}

// Menyisipkan node
Node *insertNode(Node *node, int key) {
  // Menemukan posisi yang tepat dan menyisipkan node
  if (node == NULL)
    return (newNode(key));
  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;

  // Memperbarui balance factor dari setiap node dan
  // menyeimbangkan tree
  node->height = 1 + max(height(node->left),
               height(node->right));
  int balanceFactor = getBalanceFactor(node);
  if (balanceFactor > 1) {
    if (key < node->left->key) {
      return rightRotate(node);
    } else if (key > node->left->key) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
  }
  if (balanceFactor < -1) {
    if (key > node->right->key) {
      return leftRotate(node);
    } else if (key < node->right->key) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
  }
  return node;
}

// Node dengan nilai minimum
Node *nodeWithMimumValue(Node *node) {
  Node *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

// Menghapus node
Node *deleteNode(Node *root, int key) {
  // Menemukan node dan menghapusnya
  if (root == NULL)
    return root;
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if ((root->left == NULL) ||
      (root->right == NULL)) {
      Node *temp = root->left ? root->left : root->right;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      Node *temp = nodeWithMimumValue(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right,
                   temp->key);
    }
  }

  if (root == NULL)
    return root;

  // Memperbarui balance factor dari setiap node dan
  // menyeimbangkan tree
  root->height = 1 + max(height(root->left),
               height(root->right));
  int balanceFactor = getBalanceFactor(root);
  if (balanceFactor > 1) {
    if (getBalanceFactor(root->left) >= 0) {
      return rightRotate(root);
    } else {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }
  if (balanceFactor < -1) {
    if (getBalanceFactor(root->right) <= 0) {
      return leftRotate(root);
    } else {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }
  return root;
}

// Mencetak tree
void printTree(Node *root, string indent, bool last) {
  if (root != nullptr) {
    cout << indent;
    if (last) {
      cout << "R----";
      indent += "   ";
    } else {
      cout << "L----";
      indent += "|  ";
    }
    cout << root->key << endl;
    printTree(root->left, indent, false);
    printTree(root->right, indent, true);
  }
}

int main() {
  Node *root = NULL;
  root = insertNode(root, 33);
  root = insertNode(root, 13);
  root = insertNode(root, 53);
  root = insertNode(root, 9);
  root = insertNode(root, 21);
  root = insertNode(root, 61);
  root = insertNode(root, 8);
  root = insertNode(root, 11);
  printTree(root, "", true);
  root = deleteNode(root, 13);
  cout << "After deleting " << endl;
  printTree(root, "", true);

  return 0;
}
```

Berikut adalah **penjelasan editorial lengkap per blok kode** untuk implementasi AVL Tree di C++ yang kamu berikan:

---

### 1. Header dan Namespace

```cpp
#include <iostream>
using namespace std;
```

- **`#include <iostream>`**: Mengimpor pustaka standar C++ untuk operasi input/output (misalnya `cout`, `endl`).
    
- **`using namespace std;`**: Menghindarkan kita dari penulisan `std::` sebelum `cout`, `string`, dan simbol lainnya.
    

---

### 2. Definisi Kelas Node

```cpp
class Node {
   public:
  int key;
  Node *left;
  Node *right;
  int height;
};
```

- **`int key;`**  
    Menyimpan nilai data pada node.
    
- **`Node *left, *right;`**  
    Pointer ke child kiri dan child kanan—poin utama dalam struktur pohon biner.
    
- **`int height;`**  
    Menyimpan tinggi subtree dengan root di node ini; dipakai untuk menghitung balance factor.
    

---

### 3. Fungsi Bantuan: `max`

```cpp
int max(int a, int b);
```

- **Deklarasi** fungsi `max` yang akan menentukan nilai maksimum antara dua integer.
    
- Definisi lengkap ada di bawah.
    

---

### 4. Menghitung Tinggi (`height`)

```cpp
int height(Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}
```

- Jika `N` adalah `NULL`, tinggi dianggap **0** (tidak ada node).
    
- Jika tidak, kembalikan nilai `N->height` yang sudah disimpan.
    

---

### 5. Implementasi `max`

```cpp
int max(int a, int b) {
  return (a > b) ? a : b;
}
```

- Mengembalikan nilai yang lebih besar di antara `a` dan `b`.
    
- Digunakan untuk memperbarui tinggi node setelah rotasi ataupun penyisipan/penghapusan.
    

---

### 6. Membuat Node Baru (`newNode`)

```cpp
Node *newNode(int key) {
  Node *node = new Node();
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return node;
}
```

- Alokasi dinamis `new Node()`.
    
- Inisialisasi `key` dengan nilai yang disisipkan.
    
- Child kiri dan kanan di-NULL-kan (karena baru leaf).
    
- `height = 1` (node tunggal dianggap memiliki tinggi 1).
    

---

### 7. Rotasi Kanan (`rightRotate`)

```cpp
Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;
  return x;
}
```

- **Input**: node `y` yang tidak seimbang (balance factor > +1).
    
- **Langkah**:
    
    1. `x = y->left` → tentukan pivot kiri.
        
    2. `T2 = x->right` → subtree yang akan “dipindah” menjadi anak kiri `y`.
        
    3. Lakukan pointer swap:
        
        - `x->right = y`
            
        - `y->left = T2`
            
    4. Perbarui tinggi `y` dan `x` (dengan `max(...) + 1`).
        
- **Output**: node `x` sebagai root subtree baru.
    

---

### 8. Rotasi Kiri (`leftRotate`)

```cpp
Node *leftRotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;
  return y;
}
```

- **Input**: node `x` yang tidak seimbang (balance factor < –1).
    
- **Langkah**: kebalikan dari `rightRotate`:
    
    1. `y = x->right` → pivot kanan.
        
    2. `T2 = y->left` → subtree yang dipindah.
        
    3. Pointer swap:
        
        - `y->left = x`
            
        - `x->right = T2`
            
    4. Perbarui tinggi `x` dan `y`.
        
- **Output**: node `y` sebagai root subtree baru.
    

---

### 9. Mendapatkan Balance Factor

```cpp
int getBalanceFactor(Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}
```

- **Balance Factor** = `tinggi(kiri) – tinggi(kanan)`.
    
- Digunakan untuk memeriksa seberapa jauh sebuah node tidak seimbang.
    

---

### 10. Penyisipan Node (`insertNode`)

```cpp
Node *insertNode(Node *node, int key) {
  if (node == NULL)
    return newNode(key);
  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;  // duplicate keys not allowed

  node->height = 1 + max(height(node->left), height(node->right));
  int balanceFactor = getBalanceFactor(node);

  // Kasus Left Left
  if (balanceFactor > 1 && key < node->left->key)
    return rightRotate(node);

  // Kasus Left Right
  if (balanceFactor > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  // Kasus Right Right
  if (balanceFactor < -1 && key > node->right->key)
    return leftRotate(node);

  // Kasus Right Left
  if (balanceFactor < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}
```

1. **Pencarian posisi**: rekursif ke kiri/kanan sesuai perbandingan `key`.
    
2. **Inisialisasi**: jika subtree kosong, buat `newNode`.
    
3. **Update tinggi**: setiap node di-`return` diperbarui `height`–nya.
    
4. **Cek balanceFactor** → tentukan jenis rotasi:
    
    - **Left-Left**, **Left-Right**, **Right-Right**, **Right-Left**.
        
5. **Rotasi sesuai kasus**, lalu kembalikan root subtree yang sudah seimbang.
    

---

### 11. Mencari Node dengan Nilai Minimum

```cpp
Node *nodeWithMimumValue(Node *node) {
  Node *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}
```

- Dipakai dalam **penghapusan** untuk menemukan **inorder successor** (nilai minimum di subtree kanan).
    

---

### 12. Penghapusan Node (`deleteNode`)

```cpp
Node *deleteNode(Node *root, int key) {
  if (root == NULL)
    return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    // Kasus satu anak atau tidak ada anak
    if ((root->left == NULL) || (root->right == NULL)) {
      Node *temp = root->left ? root->left : root->right;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } 
    // Kasus dua anak
    else {
      Node *temp = nodeWithMimumValue(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right, temp->key);
    }
  }

  if (root == NULL)
    return root;

  // Update tinggi & balance
  root->height = 1 + max(height(root->left), height(root->right));
  int balanceFactor = getBalanceFactor(root);

  // Rotasi untuk menyeimbangkan
  if (balanceFactor > 1 && getBalanceFactor(root->left) >= 0)
    return rightRotate(root);
  if (balanceFactor > 1 && getBalanceFactor(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  if (balanceFactor < -1 && getBalanceFactor(root->right) <= 0)
    return leftRotate(root);
  if (balanceFactor < -1 && getBalanceFactor(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}
```

1. **Cari node** dengan `key` yang mau dihapus.
    
2. **Tiga kasus**:
    
    - **0 atau 1 anak**: langsung hapus/ambil anaknya.
        
    - **2 anak**: ganti `key` dengan inorder successor, lalu hapus successor.
        
3. **Update tinggi** setiap node saat “menggelembung” kembali.
    
4. **Periksa balanceFactor** dan lakukan **rotasi** jika diperlukan.
    

---

### 13. Mencetak Pohon (`printTree`)

```cpp
void printTree(Node *root, string indent, bool last) {
  if (root != nullptr) {
    cout << indent;
    if (last) {
      cout << "R----";
      indent += "   ";
    } else {
      cout << "L----";
      indent += "|  ";
    }
    cout << root->key << endl;
    printTree(root->left, indent, false);
    printTree(root->right, indent, true);
  }
}
```

- **Indentasi** menggambarkan level dalam tree;
    
- `L----` menandai branch kiri, `R----` branch kanan;
    
- **Rekursif** mencetak subtree kiri lalu kanan.
    

---

### 14. Fungsi Utama (`main`)

```cpp
int main() {
  Node *root = NULL;
  root = insertNode(root, 33);
  root = insertNode(root, 13);
  root = insertNode(root, 53);
  root = insertNode(root, 9);
  root = insertNode(root, 21);
  root = insertNode(root, 61);
  root = insertNode(root, 8);
  root = insertNode(root, 11);

  printTree(root, "", true);

  root = deleteNode(root, 13);
  cout << "After deleting " << endl;
  printTree(root, "", true);
}
```

1. **Membangun** AVL Tree dengan beberapa `insertNode`.
    
2. **Cetak** struktur awal.
    
3. **Hapus** node `13` dan cetak ulang untuk memverifikasi keseimbangan.
    

---

Dengan penjelasan blok demi blok ini, kamu dapat melihat alur:

1. **Definisi struktur**,
    
2. **Operasi dasar (height, max)**,
    
3. **Rotasi** untuk balancing,
    
4. **Penyisipan & Penghapusan** dengan update dan rotasi,
    
5. **Visualisasi** tree.
    

## Kompleksitas Operasi pada AVL Tree

|Operasi|Kompleksitas Waktu|
|---|---|
|Insertion|O(log n)|
|Deletion|O(log n)|
|Search|O(log n)|

- Karena AVL tree selalu **seimbang secara tinggi**, maka tinggi maksimalnya adalah **O(log n)**, yang membuat semua operasi dasar berjalan efisien.
    

---

## Aplikasi AVL Tree

- Untuk **pengindeksan data berskala besar** dalam sistem basis data.
    
- Untuk **pencarian** dalam basis data besar (AVL tree menjamin efisiensi pencarian karena keseimbangannya).