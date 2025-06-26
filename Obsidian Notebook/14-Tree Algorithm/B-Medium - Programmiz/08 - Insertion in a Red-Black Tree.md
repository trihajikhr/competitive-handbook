---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 14TH-TREE-00B8
nama_algoritma: 
kategori_algoritma: tree algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: programiz.com & chatgpt.com
date_learned: 2025-06-25T13:49:00
tags:
  - tree-algorithm
---
Link sumber: [Insertion in a Red-Black Tree](https://www.programiz.com/dsa/insertion-in-a-red-black-tree)

---
# Insertion in a Red-Black Tree
Red-Black Tree adalah pohon pencarian biner yang menyeimbangkan diri sendiri, di mana setiap simpul memiliki satu bit tambahan untuk menunjukkan warna simpul, yaitu merah atau hitam.

Sebelum membaca bagian ini, disarankan untuk memahami dulu apa itu Red-Black Tree.

Saat menyisipkan simpul baru, simpul tersebut **selalu dimasukkan sebagai simpul berwarna merah**. Setelah penyisipan, jika pohon melanggar salah satu properti Red-Black Tree, maka dilakukan langkah-langkah berikut:

- Pewarnaan ulang
    
- Rotasi
    

## Algoritma untuk menyisipkan simpul baru:  
Langkah-langkah berikut diikuti untuk menyisipkan elemen baru ke dalam Red-Black Tree:

1. Anggap simpul baru sebagai `newNode`.
   ![[08 - Insertion in a Red-Black Tree-1.png]]
2. Misalkan `y` adalah daun (yaitu, NIL) dan `x` adalah akar dari pohon. Simpul baru akan disisipkan ke dalam pohon berikut.
   
   ![[08 - Insertion in a Red-Black Tree-2.png]]
3. Periksa apakah pohonnya kosong (yaitu, apakah `x` adalah NIL). Jika ya, sisipkan `newNode` sebagai simpul akar dan beri warna hitam.

4. Jika tidak, ulangi langkah-langkah berikut sampai mencapai daun (NIL):
	
	- Bandingkan `newKey` dengan `rootKey`.
	    
	- Jika `newKey` lebih besar dari `rootKey`, telusuri ke subtree kanan.
	    
	- Jika tidak, telusuri ke subtree kiri.
	![[08 - Insertion in a Red-Black Tree-3.png]]
5. Tetapkan induk dari daun sebagai induk dari `newNode`.  
6. Jika `leafKey` lebih besar dari `newKey`, jadikan `newNode` sebagai anak kanan.  
7. Jika tidak, jadikan `newNode` sebagai anak kiri.
   
   ![[08 - Insertion in a Red-Black Tree-4.png]]
8. Tetapkan `NULL` pada `leftChild` dan `rightChild` dari `newNode`.  
9. Tetapkan warna MERAH pada `newNode`.
   
   ![[08 - Insertion in a Red-Black Tree-5.png]]
10. Panggil algoritma InsertFix untuk menjaga agar properti red-black tree tetap terpenuhi jika terjadi pelanggaran.

## Mengapa node yang baru disisipkan dalam red-black tree selalu berwarna merah?

Hal ini karena menyisipkan node berwarna merah tidak melanggar _depth property_ (jumlah node hitam dari akar ke daun) pada red-black tree.

Jika node merah ditempelkan ke node merah lainnya, memang terjadi pelanggaran aturan, tetapi pelanggaran ini **lebih mudah diperbaiki** dibandingkan jika kita menyisipkan node hitam yang bisa menyebabkan pelanggaran pada _depth property_.

## Algoritma untuk Menjaga Properti Red-Black Setelah Penyisipan

Algoritma ini digunakan untuk menjaga properti red-black tree jika penyisipan `newNode` menyebabkan pelanggaran terhadap aturan-aturan red-black.

Lakukan langkah-langkah berikut **selama parent dari `newNode` (disebut `p`) berwarna MERAH**:

Jika `p` adalah anak kiri dari `gP` (grandparent dari `newNode`), maka lakukan:

#### Kasus-I:  
1. Jika warna dari anak kanan `gP` (saudara `p`) adalah MERAH, maka:

	- Ubah warna kedua anak `gP` (baik kiri maupun kanan) menjadi HITAM.
	    
	- Ubah warna `gP` menjadi MERAH.
	    
	- Jadikan `gP` sebagai `newNode` (perbarui `newNode = gP`) dan lanjutkan proses naik ke atas pohon.

	![[08 - Insertion in a Red-Black Tree-6.png]]

2. Tetapkan `gP` (grandparent dari node saat ini) sebagai `newNode`.
   
   ![[08 - Insertion in a Red-Black Tree-7.png]]
#### Kasus-II:  
(Sebelum lanjut ke langkah ini, kondisi pada `while` akan dicek kembali. Jika tidak terpenuhi, maka loop akan dihentikan.)  

Jika `newNode` adalah anak kanan dari `p`, maka tetapkan `p` sebagai `newNode`.

![[08 - Insertion in a Red-Black Tree-8.png]]

Lakukan _Left-Rotate_ (rotasi ke kiri) pada `newNode`.

![[08 - Insertion in a Red-Black Tree-9.png]]

#### Case-III:  
(Sebelum melanjutkan ke langkah ini, perulangan `while` dicek ulang. Jika kondisinya tidak terpenuhi, maka perulangan dihentikan.)  

Atur warna dari `p` menjadi HITAM dan warna dari `gP` menjadi MERAH.

![[08 - Insertion in a Red-Black Tree-10.png]]

Lakukan rotasi-kanan (Right-Rotate) pada simpul `gP`.

![[08 - Insertion in a Red-Black Tree-11.png]]

Jika tidak, lakukan langkah-langkah berikut:

- Jika warna anak kiri dari gP (kakek dari `newNode`) adalah MERAH, ubah warna kedua anak dari gP menjadi HITAM dan ubah warna gP menjadi MERAH.  
- Tetapkan gP sebagai `newNode`.

- Jika tidak, dan jika `newNode` adalah anak kiri dari `p` (parent), maka tetapkan `p` sebagai `newNode` dan lakukan rotasi-kanan (`Right-Rotate`) pada `newNode`.

- Ubah warna `p` menjadi HITAM dan warna `gP` menjadi MERAH.  
- Lakukan rotasi-kiri (`Left-Rotate`) pada `gP`.

- (Langkah ini dilakukan setelah keluar dari loop `while`):  

Tetapkan akar pohon sebagai simpul berwarna HITAM.

![[08 - Insertion in a Red-Black Tree-12.png]]

Tree akhir akan tampak seperti ini:

![[08 - Insertion in a Red-Black Tree-13.png]]

## Implementasi Kode

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