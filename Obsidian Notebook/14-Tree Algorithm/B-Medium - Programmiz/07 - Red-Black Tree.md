---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 14TH-TREE-00B7
nama_algoritma: 
kategori_algoritma: tree algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: programiz.com & chatgpt.com
date_learned: 2025-06-25T13:02:00
tags:
  - tree-algorithm
---
---
# Red-Black Tree

Red-Black Tree adalah pohon pencarian biner (binary search tree) yang menyeimbangkan dirinya sendiri dan di mana setiap node memiliki bit tambahan untuk menyimpan warna node, yaitu merah (red) atau hitam (black).

Red-Black Tree harus memenuhi lima properti penting berikut:


1. **Red/Black Property**  
    Setiap node harus berwarna merah atau hitam.
<br/>
2. **Root Property**  
    Akar pohon selalu berwarna hitam.
<br/>
3. **Leaf Property**  
    Semua daun (leaf/NIL/null pointers) dianggap sebagai node hitam.
<br/>
4. **Red Property**  
    Jika sebuah node berwarna merah memiliki anak, maka anak-anaknya selalu berwarna hitam. (Tidak boleh ada dua node merah berturut-turut.)
<br/>
5. **Depth Property (Black-Height / Kedalaman Hitam)**  
    Untuk setiap node, setiap jalur sederhana dari node itu ke descendant leaf mana pun harus memiliki jumlah node hitam yang sama.
<br/>
---

📌 **Catatan Tambahan:**

- Karena aturan-aturan ini, Red-Black Tree menjaga keseimbangan tinggi pohon mendekati `O(log n)`, sehingga operasi pencarian, penyisipan, dan penghapusan tetap efisien.
    
- Perubahan warna dan rotasi (left/right) mungkin dibutuhkan saat `insert` atau `delete`.
    

---

Contoh Visualisasi Red-Black Tree:

![[07 - Red-Black Tree-1.png]]


Setiap node memiliki atribut berikut:

- **`color`** – Warna node, bisa **red** (merah) atau **black** (hitam).
    
- **`key`** – Nilai kunci (digunakan dalam operasi pencarian seperti pada BST).
    
- **`leftChild`** – Pointer ke anak kiri.
    
- **`rightChild`** – Pointer ke anak kanan.
    
- **`parent`** – Pointer ke node induk (tidak berlaku untuk node akar/root).
    

---

## Bagaimana Red-Black Tree Menjaga Properti Self-Balancing?

Warna merah-hitam digunakan **untuk menjaga keseimbangan pohon secara otomatis**.

Pembatasan-pembatasan yang dikenakan pada warna node (misalnya: tidak boleh dua node merah berturut-turut, akar selalu hitam, jumlah node hitam dari akar ke daun harus sama) memastikan bahwa semua jalur sederhana dari akar ke daun memiliki panjang yang terkendali.

**⏳ Secara khusus:**  
Panjang jalur mana pun dari root ke daun tidak akan lebih dari dua kali panjang jalur lainnya di pohon tersebut.

**📈 Artinya:**  
Red-Black Tree menghindari pertumbuhan yang terlalu tinggi atau tidak seimbang seperti pada Binary Search Tree biasa, sehingga tingginya tetap O(log n).
## Operasi pada Red-Black Tree

Berbagai operasi yang dapat dilakukan pada red-black tree adalah:

### 1. Rotasi Subtree dalam Red-Black Tree

Pada operasi **rotasi**, posisi node-node dalam sebuah **subtree dipertukarkan**.

Operasi rotasi digunakan untuk **mempertahankan properti red-black tree** ketika terjadi pelanggaran akibat operasi lain seperti **penyisipan (insertion)** atau **penghapusan (deletion)**.

Ada dua jenis rotasi:

#### Left Rotate (Rotasi Kiri)

Pada **rotasi kiri**, struktur node yang berada di **sebelah kanan** akan diubah menjadi struktur node **sebelah kiri**.

Berikut visualisasi algoritmanya:

1. Misalkan pohon awal seperti ini:
   
   ![[07 - Red-Black Tree-2.png]]
2. Jika $y$ memiliki subtree kiri, tetapkan $x$ sebagai parent dari subtree kiri $y$.
   
   ![[07 - Red-Black Tree-3.png]]
3. Jika parent dari $x$ adalah `NULL`, jadikan $y$ sebagai root dari tree.  
4. Jika tidak, dan $x$ adalah anak kiri dari $p$, jadikan $y$ sebagai anak kiri dari $p$.  
5. Jika tidak, tetapkan $y$ sebagai anak kanan dari $p$.
   
   ![[07 - Red-Black Tree-5.png]]
6. Jadikan $y$ sebagai parent dari $x$.
   
   ![[07 - Red-Black Tree-6.png]]
#### Right Rotate (Putaran Kanan)
Dalam rotasi kanan, susunan node di sebelah kiri diubah menjadi susunan node di sebelah kanan.

1. Misalkan tree awal adalah:
   
   ![[07 - Red-Black Tree-8.png]]
2. Jika `x` memiliki subtree kanan, tetapkan `y` sebagai parent dari subtree kanan `x`.
   
   ![[07 - Red-Black Tree-9.png]]
3. Jika parent dari `y` adalah `NULL`, jadikan `x` sebagai root dari pohon.  
4. Jika tidak, dan `y` adalah anak kanan dari parent-nya `p`, maka jadikan `x` sebagai anak kanan dari `p`.  
5. Jika tidak, tetapkan `x` sebagai anak kiri dari `p`.
   
   ![[07 - Red-Black Tree-10.png]]
6. Jadikan `x` sebagai parent dari `y`.
   
   ![[07 - Red-Black Tree-11.png]]

### Rotasi Kiri-Kanan dan Kanan-Kiri  
Dalam rotasi kiri-kanan (left-right rotation), susunan simpul pertama-tama diputar ke kiri, kemudian diputar ke kanan.

1. Lakukan rotasi kiri pada pasangan simpul x–y.
   
   ![[07 - Red-Black Tree-12.png]]
2. Lakukan rotasi kanan pada pasangan simpul y–z.
   
   ![[07 - Red-Black Tree-13.png]]
Dalam rotasi kanan-kiri (_right-left rotation_), susunan simpul pertama-tama digeser ke kanan lalu ke kiri.

3. Lakukan rotasi kanan pada pasangan simpul x–y.
   ![[07 - Red-Black Tree-14.png]]
4. Lakukan rotasi kiri pada pasangan simpul z–y.
   
   ![[07 - Red-Black Tree-15.png]]
## Menyisipkan Elemen ke dalam Pohon Red-Black

Saat menyisipkan simpul baru, simpul tersebut **selalu dimasukkan sebagai simpul berwarna MERAH**. Setelah penyisipan, jika pohon melanggar sifat-sifat red-black tree, maka dilakukan:

- **Recoloring** (pengubahan warna)
    
- **Rotasi** (rotasi kiri/kanan untuk menyeimbangkan)

## Algoritma Penyisipan Simpul

Langkah-langkah penyisipan elemen ke dalam red-black tree:

1. **Inisialisasi:**
    
    - Biarkan `y` sebagai daun (yaitu `NIL`)
        
    - Biarkan `x` sebagai akar dari pohon
        
2. **Periksa apakah pohon kosong:**
    
    - Jika `x` adalah `NIL`, maka jadikan `newNode` sebagai akar dan beri warna **hitam**.
        
3. **Jika tidak kosong, lakukan traversal sampai ke daun:**
    
    - **Bandingkan** `newKey` dengan `rootKey`.
        
    - Jika `newKey > rootKey`, **traversal ke subtree kanan**
        
    - Jika tidak, **traversal ke subtree kiri**
        
4. **Setelah mencapai posisi daun:**
    
    - Tetapkan **parent dari daun (NIL)** sebagai **parent dari `newNode`**
        
    - Jika `leafKey > newKey`, jadikan `newNode` sebagai `rightChild`
        
    - Jika tidak, jadikan `newNode` sebagai `leftChild`
        
5. **Inisialisasi simpul baru:**
    
    - Tetapkan `leftChild` dan `rightChild` dari `newNode` ke `NULL`
        
    - Beri warna **MERAH** pada `newNode`
        
6. **Perbaikan Struktur (InsertFix):**
    
    - Panggil algoritma `InsertFix()` untuk memastikan semua **sifat red-black tree tetap terjaga**.
        

## Kenapa Simpul yang Baru Disisipkan Selalu Berwarna **Merah** dalam Red-Black Tree?

Karena:

- Menambahkan **simpul merah** **tidak melanggar properti kedalaman (black-depth)** dari red-black tree.
    
- Jika simpul **merah ditempel ke simpul merah**, maka memang terjadi pelanggaran aturan — **namun pelanggaran ini lebih mudah diperbaiki** daripada pelanggaran pada properti kedalaman (misalnya dengan rotasi dan recolor).
    

---
## Algoritma Mempertahankan Properti Red-Black Setelah Penyisipan

Algoritma ini dijalankan jika penyisipan simpul baru (`newNode`) menyebabkan pelanggaran pada properti pohon red-black.

Selama warna parent (`p`) dari `newNode` adalah **MERAH**, lakukan langkah berikut:

#### 🡒 Jika `p` adalah **anak kiri** dari kakek (`gP`) dari `newNode`:

- **Case I** – _Uncle merah_  
    Jika anak kanan dari `gP` berwarna MERAH:
    
    - Ubah warna `p` dan `uncle` menjadi **HITAM**
        
    - Ubah warna `gP` menjadi **MERAH**
        
    - Set `newNode = gP` (naikkan fokus ke atas)
        
- **Case II** – _Uncle hitam + zig-zag (right child of p)_  
    Jika `newNode` adalah anak kanan dari `p`:
    
    - Set `newNode = p`
        
    - **Rotasi kiri** pada `newNode`
        
- **Case III** – _Uncle hitam + straight-line (left child of p)_
    
    - Ubah warna `p` menjadi **HITAM**
        
    - Ubah warna `gP` menjadi **MERAH**
        
    - **Rotasi kanan** pada `gP`
        

---

#### 🡒 Jika `p` adalah **anak kanan** dari `gP`: _(simetris dari di atas)_

- **Case I** – _Uncle merah_  
    Jika anak kiri dari `gP` berwarna MERAH:
    
    - `p` dan `uncle` → **HITAM**, `gP` → **MERAH**
        
    - `newNode = gP`
        
- **Case II** – _Zig-zag (left child of p)_  
    Jika `newNode` adalah anak kiri dari `p`:
    
    - `newNode = p`
        
    - **Rotasi kanan** pada `newNode`
        
- **Case III** – _Straight-line (right child of p)_
    
    - `p` → **HITAM**, `gP` → **MERAH**
        
    - **Rotasi kiri** pada `gP`
        

---

#### 🔚 Terakhir:

- Pastikan **akar pohon** selalu berwarna **HITAM**.
    
Berikut adalah **terjemahan algoritma penghapusan simpul pada Red-Black Tree** secara lengkap dan terstruktur:

---

## 🗑️ Menghapus Elemen dari Red-Black Tree

Operasi ini menghapus sebuah node dari pohon. Setelah penghapusan, properti red-black harus dipulihkan kembali.

### 🔧 Algoritma untuk Menghapus Simpul

1. **Simpan warna node yang akan dihapus** dalam `originalColor`.
    
2. **Jika** anak kiri dari `nodeToBeDeleted` adalah `NULL`:
    
    - Tetapkan `x` sebagai anak kanan dari `nodeToBeDeleted`.
        
    - Gantikan (`transplant`) `nodeToBeDeleted` dengan `x`.
        
3. **Else if** anak kanan dari `nodeToBeDeleted` adalah `NULL`:
    
    - Tetapkan `x` sebagai anak kiri dari `nodeToBeDeleted`.
        
    - Gantikan (`transplant`) `nodeToBeDeleted` dengan `x`.
        
4. **Else** (jika node memiliki dua anak):
    
    - Tetapkan `y` sebagai simpul **minimum** dari **subtree kanan** dari `nodeToBeDeleted`.
        
    - Simpan warna `y` ke dalam `originalColor`.
        
    - Tetapkan `x` sebagai anak kanan dari `y`.
        
    - **Jika** `y` adalah **anak langsung** dari `nodeToBeDeleted`, maka:
        
        - Tetapkan parent dari `x` sebagai `y`.
            
    - **Else**:
        
        - Gantikan (`transplant`) `y` dengan anak kanan `y`.
            
    - Gantikan (`transplant`) `nodeToBeDeleted` dengan `y`.
        
    - Tetapkan warna `y` dengan `originalColor`.
        
5. **Jika** `originalColor` adalah **HITAM**, maka:
    
    - Panggil fungsi `DeleteFix(x)` untuk memulihkan properti red-black.
        

---

💡 _Catatan_:

- Fungsi `transplant(u, v)` berarti menggantikan posisi `u` dalam pohon dengan `v`.
    
- Fungsi `DeleteFix(x)` akan dijelaskan pada bagian selanjutnya untuk menangani pelanggaran properti pohon setelah penghapusan simpul berwarna hitam.
    

## Algoritma untuk Menjaga Properti Red-Black Setelah Penghapusan

Algoritma ini dijalankan **saat node hitam dihapus**, karena hal ini melanggar properti _black-depth_ dari Red-Black Tree.

---

### 🧩 Mengapa Terjadi Pelanggaran?

Pelanggaran ini dianggap terjadi karena node `x` (yang menempati posisi asli dari node yang dihapus) memiliki **"extra black"** (dua kali hitam). Ini menyebabkan `x` tidak berwarna _merah_ maupun _hitam_, tapi "doubly black" (hitam ganda), yang **melanggar aturan pohon red-black**.

Namun, **warna aktual `x` tidak diubah**, melainkan **status hitam ekstra tersebut diwakili** oleh penunjukan `x` terhadap node itu.

---

### 💡 Kapan "extra black" bisa dihapus?

- Jika `x` mencapai **akar** pohon.
    
- Jika `x` menunjuk ke **node berwarna merah** → ubah `x` menjadi hitam.
    
- Jika terjadi **rotasi dan pewarnaan ulang** yang sesuai.
    

---

### 🔁 _Langkah-langkah Algoritma_

Lakukan langkah-langkah berikut **selama `x` bukan akar** dan **warna `x` adalah HITAM**:

1. **Jika `x` adalah anak kiri dari parent-nya:**
    
    - Tetapkan `w` sebagai **saudara kandung** dari `x`.
        
    
    #### ✅ Case I:
    
    - Jika **`w` berwarna MERAH**:
        
        - Ubah warna `w` menjadi HITAM.
            
        - Ubah warna `parent(x)` menjadi MERAH.
            
        - Lakukan **Left-Rotate pada `parent(x)`**.
            
        - Tetapkan `w` sebagai **anak kanan baru** dari `parent(x)`.
            
    
    #### ✅ Case II:
    
    - Jika **anak kiri dan kanan `w` berwarna HITAM**:
        
        - Ubah warna `w` menjadi MERAH.
            
        - Tetapkan `x = parent(x)`.
            
    
    #### ✅ Case III:
    
    - Jika **anak kanan `w` berwarna HITAM**:
        
        - Ubah warna **anak kiri `w` menjadi HITAM**.
            
        - Ubah warna `w` menjadi MERAH.
            
        - Lakukan **Right-Rotate pada `w`**.
            
        - Tetapkan `w` sebagai anak kanan baru dari `parent(x)`.
            
    
    #### ✅ Case IV:
    
    - Ubah warna `w` menjadi warna `parent(x)`.
        
    - Ubah warna `parent(x)` menjadi HITAM.
        
    - Ubah warna anak kanan `w` menjadi HITAM.
        
    - Lakukan **Left-Rotate pada `parent(x)`**.
        
    - Tetapkan `x` sebagai akar pohon.
        
2. **Else (jika `x` adalah anak kanan dari parent-nya):**
    
    - **Lakukan langkah-langkah yang sama**, namun dengan **kanan ↔ kiri ditukar**.
        
3. **Setelah keluar dari perulangan**, tetapkan warna `x` menjadi HITAM.
    

## Implementasi Kode Red Black Tree

```cpp
// Implementing Red-Black Tree in C++

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *parent;
  Node *left;
  Node *right;
  int color;
};

typedef Node *NodePtr;

class RedBlackTree {
   private:
  NodePtr root;
  NodePtr TNULL;

  void initializeNULLNode(NodePtr node, NodePtr parent) {
    node->data = 0;
    node->parent = parent;
    node->left = nullptr;
    node->right = nullptr;
    node->color = 0;
  }

  // Preorder
  void preOrderHelper(NodePtr node) {
    if (node != TNULL) {
      cout << node->data << " ";
      preOrderHelper(node->left);
      preOrderHelper(node->right);
    }
  }

  // Inorder
  void inOrderHelper(NodePtr node) {
    if (node != TNULL) {
      inOrderHelper(node->left);
      cout << node->data << " ";
      inOrderHelper(node->right);
    }
  }

  // Post order
  void postOrderHelper(NodePtr node) {
    if (node != TNULL) {
      postOrderHelper(node->left);
      postOrderHelper(node->right);
      cout << node->data << " ";
    }
  }

  NodePtr searchTreeHelper(NodePtr node, int key) {
    if (node == TNULL || key == node->data) {
      return node;
    }

    if (key < node->data) {
      return searchTreeHelper(node->left, key);
    }
    return searchTreeHelper(node->right, key);
  }

  // For balancing the tree after deletion
  void deleteFix(NodePtr x) {
    NodePtr s;
    while (x != root && x->color == 0) {
      if (x == x->parent->left) {
        s = x->parent->right;
        if (s->color == 1) {
          s->color = 0;
          x->parent->color = 1;
          leftRotate(x->parent);
          s = x->parent->right;
        }

        if (s->left->color == 0 && s->right->color == 0) {
          s->color = 1;
          x = x->parent;
        } else {
          if (s->right->color == 0) {
            s->left->color = 0;
            s->color = 1;
            rightRotate(s);
            s = x->parent->right;
          }

          s->color = x->parent->color;
          x->parent->color = 0;
          s->right->color = 0;
          leftRotate(x->parent);
          x = root;
        }
      } else {
        s = x->parent->left;
        if (s->color == 1) {
          s->color = 0;
          x->parent->color = 1;
          rightRotate(x->parent);
          s = x->parent->left;
        }

        if (s->right->color == 0 && s->right->color == 0) {
          s->color = 1;
          x = x->parent;
        } else {
          if (s->left->color == 0) {
            s->right->color = 0;
            s->color = 1;
            leftRotate(s);
            s = x->parent->left;
          }

          s->color = x->parent->color;
          x->parent->color = 0;
          s->left->color = 0;
          rightRotate(x->parent);
          x = root;
        }
      }
    }
    x->color = 0;
  }

  void rbTransplant(NodePtr u, NodePtr v) {
    if (u->parent == nullptr) {
      root = v;
    } else if (u == u->parent->left) {
      u->parent->left = v;
    } else {
      u->parent->right = v;
    }
    v->parent = u->parent;
  }

  void deleteNodeHelper(NodePtr node, int key) {
    NodePtr z = TNULL;
    NodePtr x, y;
    while (node != TNULL) {
      if (node->data == key) {
        z = node;
      }

      if (node->data <= key) {
        node = node->right;
      } else {
        node = node->left;
      }
    }

    if (z == TNULL) {
      cout << "Key not found in the tree" << endl;
      return;
    }

    y = z;
    int y_original_color = y->color;
    if (z->left == TNULL) {
      x = z->right;
      rbTransplant(z, z->right);
    } else if (z->right == TNULL) {
      x = z->left;
      rbTransplant(z, z->left);
    } else {
      y = minimum(z->right);
      y_original_color = y->color;
      x = y->right;
      if (y->parent == z) {
        x->parent = y;
      } else {
        rbTransplant(y, y->right);
        y->right = z->right;
        y->right->parent = y;
      }

      rbTransplant(z, y);
      y->left = z->left;
      y->left->parent = y;
      y->color = z->color;
    }
    delete z;
    if (y_original_color == 0) {
      deleteFix(x);
    }
  }

  // For balancing the tree after insertion
  void insertFix(NodePtr k) {
    NodePtr u;
    while (k->parent->color == 1) {
      if (k->parent == k->parent->parent->right) {
        u = k->parent->parent->left;
        if (u->color == 1) {
          u->color = 0;
          k->parent->color = 0;
          k->parent->parent->color = 1;
          k = k->parent->parent;
        } else {
          if (k == k->parent->left) {
            k = k->parent;
            rightRotate(k);
          }
          k->parent->color = 0;
          k->parent->parent->color = 1;
          leftRotate(k->parent->parent);
        }
      } else {
        u = k->parent->parent->right;

        if (u->color == 1) {
          u->color = 0;
          k->parent->color = 0;
          k->parent->parent->color = 1;
          k = k->parent->parent;
        } else {
          if (k == k->parent->right) {
            k = k->parent;
            leftRotate(k);
          }
          k->parent->color = 0;
          k->parent->parent->color = 1;
          rightRotate(k->parent->parent);
        }
      }
      if (k == root) {
        break;
      }
    }
    root->color = 0;
  }

  void printHelper(NodePtr root, string indent, bool last) {
    if (root != TNULL) {
      cout << indent;
      if (last) {
        cout << "R----";
        indent += "   ";
      } else {
        cout << "L----";
        indent += "|  ";
      }

      string sColor = root->color ? "RED" : "BLACK";
      cout << root->data << "(" << sColor << ")" << endl;
      printHelper(root->left, indent, false);
      printHelper(root->right, indent, true);
    }
  }

   public:
  RedBlackTree() {
    TNULL = new Node;
    TNULL->color = 0;
    TNULL->left = nullptr;
    TNULL->right = nullptr;
    root = TNULL;
  }

  void preorder() {
    preOrderHelper(this->root);
  }

  void inorder() {
    inOrderHelper(this->root);
  }

  void postorder() {
    postOrderHelper(this->root);
  }

  NodePtr searchTree(int k) {
    return searchTreeHelper(this->root, k);
  }

  NodePtr minimum(NodePtr node) {
    while (node->left != TNULL) {
      node = node->left;
    }
    return node;
  }

  NodePtr maximum(NodePtr node) {
    while (node->right != TNULL) {
      node = node->right;
    }
    return node;
  }

  NodePtr successor(NodePtr x) {
    if (x->right != TNULL) {
      return minimum(x->right);
    }

    NodePtr y = x->parent;
    while (y != TNULL && x == y->right) {
      x = y;
      y = y->parent;
    }
    return y;
  }

  NodePtr predecessor(NodePtr x) {
    if (x->left != TNULL) {
      return maximum(x->left);
    }

    NodePtr y = x->parent;
    while (y != TNULL && x == y->left) {
      x = y;
      y = y->parent;
    }

    return y;
  }

  void leftRotate(NodePtr x) {
    NodePtr y = x->right;
    x->right = y->left;
    if (y->left != TNULL) {
      y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
      this->root = y;
    } else if (x == x->parent->left) {
      x->parent->left = y;
    } else {
      x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
  }

  void rightRotate(NodePtr x) {
    NodePtr y = x->left;
    x->left = y->right;
    if (y->right != TNULL) {
      y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
      this->root = y;
    } else if (x == x->parent->right) {
      x->parent->right = y;
    } else {
      x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
  }

  // Inserting a node
  void insert(int key) {
    NodePtr node = new Node;
    node->parent = nullptr;
    node->data = key;
    node->left = TNULL;
    node->right = TNULL;
    node->color = 1;

    NodePtr y = nullptr;
    NodePtr x = this->root;

    while (x != TNULL) {
      y = x;
      if (node->data < x->data) {
        x = x->left;
      } else {
        x = x->right;
      }
    }

    node->parent = y;
    if (y == nullptr) {
      root = node;
    } else if (node->data < y->data) {
      y->left = node;
    } else {
      y->right = node;
    }

    if (node->parent == nullptr) {
      node->color = 0;
      return;
    }

    if (node->parent->parent == nullptr) {
      return;
    }

    insertFix(node);
  }

  NodePtr getRoot() {
    return this->root;
  }

  void deleteNode(int data) {
    deleteNodeHelper(this->root, data);
  }

  void printTree() {
    if (root) {
      printHelper(this->root, "", true);
    }
  }
};

int main() {
  RedBlackTree bst;
  bst.insert(55);
  bst.insert(40);
  bst.insert(65);
  bst.insert(60);
  bst.insert(75);
  bst.insert(57);

  bst.printTree();
  cout << endl
     << "After deleting" << endl;
  bst.deleteNode(40);
  bst.printTree();
}
```

## 🔧 Aplikasi Red-Black Tree

Red-Black Tree digunakan dalam berbagai sistem dan struktur data penting karena sifatnya yang **self-balancing** dan efisien. Beberapa contoh aplikasinya adalah:

1. ✅ Untuk mengimplementasikan **finite maps** (peta hingga atau peta asosiatif).
    
2. ✅ Digunakan dalam **paket Java** seperti `java.util.TreeMap` dan `java.util.TreeSet`.
    
3. ✅ Diimplementasikan dalam **C++ STL (Standard Template Library)** seperti:
    
    - `multiset`
        
    - `map`
        
    - `multimap`
        
4. ✅ Digunakan dalam **Kernel Linux** sebagai bagian dari berbagai struktur data internal, seperti manajemen memori dan scheduler.
    
