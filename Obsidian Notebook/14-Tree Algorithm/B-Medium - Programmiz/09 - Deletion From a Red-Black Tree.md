---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 14TH-TREE-00B9
nama_algoritma: 
kategori_algoritma: tree algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: programiz.com & chatgpt.com
date_learned: 2025-06-25T14:37:00
tags:
  - tree-algorithm
---
---
# Deletion From a Red-Black Tree

**Red-Black Tree** adalah _binary search tree_ yang mampu menyeimbangkan dirinya sendiri (_self-balancing_) di mana setiap _node_ memiliki satu bit tambahan untuk menunjukkan warna _node_, yaitu merah (_red_) atau hitam (_black_).

Sebelum membaca artikel ini, silakan merujuk terlebih dahulu ke artikel tentang _Red-Black Tree_.

Menghapus sebuah _node_ mungkin dapat mengganggu atau tidak mengganggu sifat-sifat dasar dari _Red-Black Tree_. Jika penghapusan ini melanggar properti _Red-Black_, maka akan digunakan algoritma perbaikan (_fixing algorithm_) untuk memulihkan kembali properti _Red-Black_.

## Menghapus sebuah elemen dari Red-Black Tree  
Operasi ini bertujuan untuk menghapus sebuah _node_ dari pohon. Setelah _node_ dihapus, sifat-sifat _Red-Black_ akan dikembalikan dan dijaga agar tetap terpenuhi.

1. Misalkan _nodeToBeDeleted_ adalah:
   
   ![[09 - Deletion From a Red-Black Tree-1.png]]
2. Simpan warna dari _nodeToBeDeleted_ ke dalam variabel _originalColor_
   
   ![[09 - Deletion From a Red-Black Tree-2.png]]
3. Jika _left child_ dari _nodeToBeDeleted_ adalah `NULL`,  
	- a. tetapkan _right child_ dari _nodeToBeDeleted_ ke variabel `x`.
	  
	  ![[09 - Deletion From a Red-Black Tree-3.png]]
	- b. Gantikan (_transplant_) _nodeToBeDeleted_ dengan `x`.
	  
	  ![[09 - Deletion From a Red-Black Tree-4.png]]

4. Jika _right child_ dari _nodeToBeDeleted_ adalah `NULL`:

	- a. Tetapkan _left child_ dari _nodeToBeDeleted_ ke dalam variabel `x`.
	    
	- b. Gantikan (_transplant_) _nodeToBeDeleted_ dengan `x`.
    
5. **Else** (_jika kedua anak tidak NULL_):
	
	- a. Tetapkan _node_ minimum dari _right subtree_ milik _nodeToBeDeleted_ ke dalam variabel `y`.
	    
	- b. Simpan warna dari `y` ke dalam `originalColor`.
	    
	- c. Tetapkan _right child_ dari `y` ke dalam variabel `x`.
	    
	- d. Jika `y` adalah anak langsung dari _nodeToBeDeleted_, maka tetapkan _parent_ dari `x` sebagai `y`.
	    
	- e. Jika tidak, gantikan (_transplant_) `y` dengan _right child_ milik `y`.
	    
	- f. Gantikan (_transplant_) _nodeToBeDeleted_ dengan `y`.
	    
	- g. Atur warna `y` dengan nilai `originalColor`.
    
6. Jika `originalColor` adalah `BLACK`, panggil fungsi `DeleteFix(x)`.
    

## Algoritma untuk Mempertahankan Properti Red-Black setelah Penghapusan

Algoritma ini dijalankan ketika sebuah _black node_ dihapus karena penghapusan tersebut melanggar _black depth property_ dari _Red-Black Tree_.

Pelanggaran ini diperbaiki dengan mengasumsikan bahwa _node_ `x` (yang menempati posisi awal dari `y`) memiliki kelebihan warna hitam (_extra black_). Ini membuat _node_ `x` tidak lagi berwarna merah maupun hitam secara normal. Ia menjadi _doubly black_ (dua kali hitam) atau _black-and-red_ (hitam dan merah). Kondisi ini jelas melanggar properti dari _Red-Black Tree_.

Namun, atribut warna dari `x` **tidak diubah** secara langsung. Sebagai gantinya, kelebihan warna hitam (_extra black_) direpresentasikan melalui penunjukan `x` ke _node_ tersebut.

Kelebihan hitam ini dapat dihilangkan jika:

- `x` mencapai _root_ dari pohon, atau
    
- `x` menunjuk ke _node_ merah-hitam (_red-black node_). Dalam hal ini, `x` diwarnai hitam, atau
    
- Dilakukan rotasi dan pewarnaan ulang (_recoloring_) yang sesuai.
    

Algoritma berikut digunakan untuk mempertahankan properti dari sebuah _Red-Black Tree_:

---

Lakukan hal-hal berikut **selama** `x` **bukan** _root_ dari pohon dan warna `x` adalah **BLACK**:

1. Jika `x` adalah _left child_ dari _parent_-nya, maka:
    
    - a. Tetapkan `w` sebagai _sibling_ dari `x`.
      ![[09 - Deletion From a Red-Black Tree-5.png]]
	 - b. Jika _sibling_ dari `x` berwarna **RED**,  
	   <br/>
	   **Kasus-I**:
		- Atur warna dari _right child_ dari _parent_ `x` menjadi **BLACK**.
		    
		- Atur warna dari _parent_ `x` menjadi **RED**.
		  ![[09 - Deletion From a Red-Black Tree-6.png]]
		- Lakukan **Left-Rotate** pada _parent_ dari `x`.
		  ![[09 - Deletion From a Red-Black Tree-7.png]]
		- Tetapkan _right child_ dari _parent_ `x` ke dalam variabel `w`.
		  ![[09 - Deletion From a Red-Black Tree-8.png]]
	- c. Jika warna dari **both** (_right child_ dan _left child_) dari `w` adalah **BLACK**,  
	  <br/>
		**Kasus-II**:
		- Atur warna `w` menjadi **RED**
		    
		- Tetapkan _parent_ dari `x` ke dalam `x` (artinya geser `x` ke atas dalam pohon)
	- d. **Else if** warna dari _right child_ dari `w` adalah **BLACK**,  
	  <br/>
		**Kasus-III**:
		- Atur warna dari _left child_ `w` menjadi **BLACK**
		    
		- Atur warna `w` menjadi **RED**
		  ![[09 - Deletion From a Red-Black Tree-9.png]]
		- Lakukan **Right-Rotate** pada `w`.
		  
		  ![[09 - Deletion From a Red-Black Tree-10.png]]
		- Tetapkan _right child_ dari _parent_ `x` ke dalam variabel `w`.
		  ![[09 - Deletion From a Red-Black Tree-11.png]]
	- e. Jika tidak ada dari kasus-kasus di atas yang terjadi, maka lakukan hal berikut:  
	  <br/>
		**Kasus-IV**:
		- Atur warna `w` sama dengan warna dari _parent_ `x`.
		    
		- Atur warna dari _parent_ dari _parent_ `x` menjadi **BLACK**.
		    
		- Atur warna dari _right child_ `w` menjadi **BLACK**.
		
		![[09 - Deletion From a Red-Black Tree-12.png]]
		- Lakukan **Left-Rotate** pada _parent_ dari `x`. 
		  
		  ![[09 - Deletion From a Red-Black Tree-13.png]]
		- Tetapkan `x` sebagai _root_ dari pohon.
		  ![[09 - Deletion From a Red-Black Tree-14.png]]
2. Jika tidak, lakukan langkah-langkah yang **sama seperti di atas**, namun **gantikan "right" dengan "left" dan sebaliknya**.

3. Atur warna `x` menjadi **BLACK**.

Alur kerja dari kasus-kasus di atas dapat dipahami dengan bantuan _flowchart_ di bawah ini.  
_(visual)_

![[09 - Deletion From a Red-Black Tree-15.png]]


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