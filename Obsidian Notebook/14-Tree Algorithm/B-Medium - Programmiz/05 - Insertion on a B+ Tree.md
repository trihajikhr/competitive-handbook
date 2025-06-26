---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 14TH-TREE-00B5
nama_algoritma: 
kategori_algoritma: tree algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: programiz.com & chatgpt.com
date_learned: 2025-06-25T11:57:00
tags:
  - tree-algorithm
---
Link sumber: [Insertion on a B+ Tree](https://www.programiz.com/dsa/insertion-on-a-b-plus-tree)

---
# Insertion on a B+ Tree

Penyisipan elemen ke dalam B+ tree terdiri dari tiga peristiwa utama:

1. _Searching_ (pencarian) leaf yang sesuai,
    
2. Penyisipan elemen, dan
    
3. _Balancing_ / _splitting_ pohon (penyeimbangan/pemecahan node).
    

Mari kita pahami masing-masing peristiwa ini.

---

## Operasi Penyisipan

Sebelum menyisipkan elemen ke dalam B+ tree, beberapa properti berikut harus diperhatikan:

- **Root** memiliki minimal dua _children_.
    
- Setiap node **kecuali root** dapat memiliki maksimal $m$ _children_ dan minimal $m/2$ _children_.
    
- Setiap node dapat memuat maksimal $m - 1$ _keys_ dan minimal $⌈m/2⌉ - 1$ _keys_.
    

Langkah-langkah yang diikuti untuk menyisipkan elemen:

1. Karena setiap elemen selalu disisipkan ke node daun (_leaf node_), arahkan ke _leaf node_ yang sesuai.
    
2. Sisipkan _key_ ke dalam _leaf node_.
    

---

### Kasus I

Jika _leaf_ belum penuh, sisipkan _key_ ke dalam _leaf node_ dalam urutan menaik.

### Kasus II

Jika _leaf_ sudah penuh, sisipkan _key_ ke dalam _leaf node_ dalam urutan menaik, dan lakukan penyeimbangan pohon (_tree balancing_) dengan langkah-langkah berikut:

1. Pecah node pada posisi $m/2$.
    
2. Tambahkan _key_ ke-$m/2$ ke **parent node**.
    
3. Jika _parent node_ juga sudah penuh, ulangi langkah 2 dan 3 secara rekursif ke atas.
    

### Contoh Penyisipan
Mari kita pahami operasi penyisipan (_insertion_) dengan ilustrasi di bawah ini.

Elemen-elemen yang akan disisipkan adalah: **5, 15, 25, 35, 45**.

1. Sisipkan 5
   
   ![[05 - Insertion on a B+ Tree-1.png]]
2. Sisipkan 15
   
   ![[05 - Insertion on a B+ Tree-2.png]]
3. Sisipkan 25
   
   ![[05 - Insertion on a B+ Tree-3.png]]
4. Sisipkan 35
   ![[05 - Insertion on a B+ Tree-4.png]]
5. Sisipkan 45
   ![[05 - Insertion on a B+ Tree-5.png]]

## Kode Implementasi

```cpp
// Searching on a B+ tree in C++

#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
int MAX = 3;

// BP node
class Node {
  bool IS_LEAF;
  int *key, size;
  Node **ptr;
  friend class BPTree;

   public:
  Node();
};

// BP tree
class BPTree {
  Node *root;
  void insertInternal(int, Node *, Node *);
  Node *findParent(Node *, Node *);

   public:
  BPTree();
  void search(int);
  void insert(int);
  void display(Node *);
  Node *getRoot();
};

Node::Node() {
  key = new int[MAX];
  ptr = new Node *[MAX + 1];
}

BPTree::BPTree() {
  root = NULL;
}

// Search operation
void BPTree::search(int x) {
  if (root == NULL) {
    cout << "Tree is empty\n";
  } else {
    Node *cursor = root;
    while (cursor->IS_LEAF == false) {
      for (int i = 0; i < cursor->size; i++) {
        if (x < cursor->key[i]) {
          cursor = cursor->ptr[i];
          break;
        }
        if (i == cursor->size - 1) {
          cursor = cursor->ptr[i + 1];
          break;
        }
      }
    }
    for (int i = 0; i < cursor->size; i++) {
      if (cursor->key[i] == x) {
        cout << "Found\n";
        return;
      }
    }
    cout << "Not found\n";
  }
}

// Insert Operation
void BPTree::insert(int x) {
  if (root == NULL) {
    root = new Node;
    root->key[0] = x;
    root->IS_LEAF = true;
    root->size = 1;
  } else {
    Node *cursor = root;
    Node *parent;
    while (cursor->IS_LEAF == false) {
      parent = cursor;
      for (int i = 0; i < cursor->size; i++) {
        if (x < cursor->key[i]) {
          cursor = cursor->ptr[i];
          break;
        }
        if (i == cursor->size - 1) {
          cursor = cursor->ptr[i + 1];
          break;
        }
      }
    }
    if (cursor->size < MAX) {
      int i = 0;
      while (x > cursor->key[i] && i < cursor->size)
        i++;
      for (int j = cursor->size; j > i; j--) {
        cursor->key[j] = cursor->key[j - 1];
      }
      cursor->key[i] = x;
      cursor->size++;
      cursor->ptr[cursor->size] = cursor->ptr[cursor->size - 1];
      cursor->ptr[cursor->size - 1] = NULL;
    } else {
      Node *newLeaf = new Node;
      int virtualNode[MAX + 1];
      for (int i = 0; i < MAX; i++) {
        virtualNode[i] = cursor->key[i];
      }
      int i = 0, j;
      while (x > virtualNode[i] && i < MAX)
        i++;
      for (int j = MAX + 1; j > i; j--) {
        virtualNode[j] = virtualNode[j - 1];
      }
      virtualNode[i] = x;
      newLeaf->IS_LEAF = true;
      cursor->size = (MAX + 1) / 2;
      newLeaf->size = MAX + 1 - (MAX + 1) / 2;
      cursor->ptr[cursor->size] = newLeaf;
      newLeaf->ptr[newLeaf->size] = cursor->ptr[MAX];
      cursor->ptr[MAX] = NULL;
      for (i = 0; i < cursor->size; i++) {
        cursor->key[i] = virtualNode[i];
      }
      for (i = 0, j = cursor->size; i < newLeaf->size; i++, j++) {
        newLeaf->key[i] = virtualNode[j];
      }
      if (cursor == root) {
        Node *newRoot = new Node;
        newRoot->key[0] = newLeaf->key[0];
        newRoot->ptr[0] = cursor;
        newRoot->ptr[1] = newLeaf;
        newRoot->IS_LEAF = false;
        newRoot->size = 1;
        root = newRoot;
      } else {
        insertInternal(newLeaf->key[0], parent, newLeaf);
      }
    }
  }
}

// Insert Operation
void BPTree::insertInternal(int x, Node *cursor, Node *child) {
  if (cursor->size < MAX) {
    int i = 0;
    while (x > cursor->key[i] && i < cursor->size)
      i++;
    for (int j = cursor->size; j > i; j--) {
      cursor->key[j] = cursor->key[j - 1];
    }
    for (int j = cursor->size + 1; j > i + 1; j--) {
      cursor->ptr[j] = cursor->ptr[j - 1];
    }
    cursor->key[i] = x;
    cursor->size++;
    cursor->ptr[i + 1] = child;
  } else {
    Node *newInternal = new Node;
    int virtualKey[MAX + 1];
    Node *virtualPtr[MAX + 2];
    for (int i = 0; i < MAX; i++) {
      virtualKey[i] = cursor->key[i];
    }
    for (int i = 0; i < MAX + 1; i++) {
      virtualPtr[i] = cursor->ptr[i];
    }
    int i = 0, j;
    while (x > virtualKey[i] && i < MAX)
      i++;
    for (int j = MAX + 1; j > i; j--) {
      virtualKey[j] = virtualKey[j - 1];
    }
    virtualKey[i] = x;
    for (int j = MAX + 2; j > i + 1; j--) {
      virtualPtr[j] = virtualPtr[j - 1];
    }
    virtualPtr[i + 1] = child;
    newInternal->IS_LEAF = false;
    cursor->size = (MAX + 1) / 2;
    newInternal->size = MAX - (MAX + 1) / 2;
    for (i = 0, j = cursor->size + 1; i < newInternal->size; i++, j++) {
      newInternal->key[i] = virtualKey[j];
    }
    for (i = 0, j = cursor->size + 1; i < newInternal->size + 1; i++, j++) {
      newInternal->ptr[i] = virtualPtr[j];
    }
    if (cursor == root) {
      Node *newRoot = new Node;
      newRoot->key[0] = virtualKey[cursor->size];
      newRoot->ptr[0] = cursor;
      newRoot->ptr[1] = newInternal;
      newRoot->IS_LEAF = false;
      newRoot->size = 1;
      root = newRoot;
    } else {
      insertInternal(cursor->key[cursor->size], findParent(root, cursor), newInternal);
    }
  }
}

// Find the parent
Node *BPTree::findParent(Node *cursor, Node *child) {
  Node *parent;
  if (cursor->IS_LEAF || (cursor->ptr[0])->IS_LEAF) {
    return NULL;
  }
  for (int i = 0; i < cursor->size + 1; i++) {
    if (cursor->ptr[i] == child) {
      parent = cursor;
      return parent;
    } else {
      parent = findParent(cursor->ptr[i], child);
      if (parent != NULL)
        return parent;
    }
  }
  return parent;
}

// Print the tree
void BPTree::display(Node *cursor) {
  if (cursor != NULL) {
    for (int i = 0; i < cursor->size; i++) {
      cout << cursor->key[i] << " ";
    }
    cout << "\n";
    if (cursor->IS_LEAF != true) {
      for (int i = 0; i < cursor->size + 1; i++) {
        display(cursor->ptr[i]);
      }
    }
  }
}

// Get the root
Node *BPTree::getRoot() {
  return root;
}

int main() {
  BPTree node;
  node.insert(5);
  node.insert(15);
  node.insert(25);
  node.insert(35);
  node.insert(45);
  node.insert(55);
  node.insert(40);
  node.insert(30);
  node.insert(20);
  node.display(node.getRoot());

  node.search(15);
}
```

Berikut adalah penjelasan lengkap per blok kode program untuk **pencarian dan penyisipan pada B+ Tree dalam C++**:

---

### 🔹 Header dan Inisialisasi Awal

```cpp
#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int MAX = 3;
```

- Mengimpor library standar.
    
- `MAX = 3` menyatakan jumlah maksimum key dalam satu node. Maka, node dapat memiliki maksimum `MAX + 1` pointer.
    

---

### 🔹 Definisi Kelas `Node`

```cpp
class Node {
  bool IS_LEAF;
  int *key, size;
  Node **ptr;
  friend class BPTree;

 public:
  Node();
};
```

- `IS_LEAF` menandakan apakah node adalah daun.
    
- `key`: array integer untuk menyimpan kunci.
    
- `ptr`: array pointer ke node anak.
    
- `size`: jumlah elemen `key` dalam node.
    

---

### 🔹 Definisi Kelas `BPTree**`**

```cpp
class BPTree {
  Node *root;
  void insertInternal(int, Node *, Node *);
  Node *findParent(Node *, Node *);

 public:
  BPTree();
  void search(int);
  void insert(int);
  void display(Node *);
  Node *getRoot();
};
```

- `root`: pointer ke node akar.
    
- Fungsi penting: `search()`, `insert()`, `insertInternal()`, `findParent()`, `display()`.
    

---

### 🔹 Konstruktor `Node`

```cpp
Node::Node() {
  key = new int[MAX];
  ptr = new Node *[MAX + 1];
}
```

- Mengalokasikan memori untuk array key dan pointer ke anak (jumlah anak = key + 1).
    

---

### 🔹 Konstruktor `BPTree`

```cpp
BPTree::BPTree() {
  root = NULL;
}
```

- Membuat pohon kosong.
    

---

### 🔹 Fungsi `search(int x)`

```cpp
void BPTree::search(int x) {
  if (root == NULL) {
    cout << "Tree is empty\n";
  } else {
    ...
  }
}
```

- Menavigasi dari akar ke daun.
    
- Mencari `x` dalam key node daun.
    
- Menampilkan apakah ditemukan atau tidak.
    

---

### 🔹 Fungsi `insert(int x)`

- Jika `root` kosong, buat node daun.
    
- Jika tidak, cari daun yang sesuai untuk `x`.
    
- **Jika masih muat**: sisipkan `x` di posisi yang benar.
    
- **Jika penuh**: buat **virtual node** sementara → pisahkan node:
    
    - Buat `newLeaf`, pindahkan separuh key ke `newLeaf`.
        
    - Sisipkan key tengah ke **parent**.
        
    - Jika parent penuh, rekurensif panggil `insertInternal`.
        

---

### 🔹 Fungsi `insertInternal(int x, Node *cursor, Node *child)`

- Menyisipkan key dan pointer anak di node internal.
    
- Jika penuh:
    
    - Buat `virtualKey` dan `virtualPtr`.
        
    - Bagi menjadi dua node internal.
        
    - Key tengah dimasukkan ke parent-nya.
        
    - Jika root, buat root baru.
        

---

### 🔹 Fungsi `findParent(Node *cursor, Node *child)`

- Digunakan saat menyisipkan key ke parent.
    
- Mencari parent dari node `child` dengan traversal DFS dari `cursor`.
    

---

### 🔹 Fungsi `display(Node *cursor)`

- Traversal preorder.
    
- Mencetak isi key di setiap node secara hierarkis.
    

---

### 🔹 Fungsi `getRoot()`

```cpp
Node *BPTree::getRoot() {
  return root;
}
```

- Mengembalikan pointer ke akar B+ tree.
    

---

### 🔹 Fungsi `main()`

```cpp
int main() {
  BPTree node;
  ...
  node.display(node.getRoot());
  node.search(15);
}
```

- Menyisipkan elemen ke dalam B+ tree.
    
- Menampilkan struktur tree.
    
- Mencari nilai `15`.
    
## 🔍 Kompleksitas Penyisipan (Insertion Complexity) pada B+ Tree

- **Notasi Kompleksitas**:
    
    $$\Theta(t \cdot \log_t n)$$

---

### 📌 Penjelasan:

1. $\log_t n$:  
    Merupakan jumlah level pada B+ Tree (karena setiap node internal memiliki hingga `t` anak), sehingga pohon memiliki tinggi $\log_t n$. Ini adalah jumlah langkah traversal dari root ke leaf.
    
2. $t$:  
    Menyatakan jumlah maksimum key yang bisa dimiliki oleh sebuah node. Ketika penyisipan terjadi, bisa saja diperlukan untuk memindahkan atau menyalin hingga `t` elemen (dalam pembelahan node), maka terjadi operasi sebanyak $Θ(t)$ pada level tertentu.
    
3. **Jadi**, total waktu penyisipan adalah:
    
    - traversal: $\Theta(\log_t n)$
        
    - kemungkinan copy/split key: $\Theta(t)$
        
    - total: $\Theta(t \cdot \log_t n)$
        

---

### ⚡ Catatan:

- Jika kita mengasumsikan bahwa `t` adalah konstanta (tidak bergantung pada `n`), maka kompleksitas bisa disederhanakan menjadi:
    
    $\Theta(\log n)$
    
    Namun untuk analisis penuh, tetap ditulis sebagai $\Theta(t \cdot \log_t n)$.
    
