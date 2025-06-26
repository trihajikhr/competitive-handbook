---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 14TH-TREE-00B1
nama_algoritma: 
kategori_algoritma: tree algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: programiz.com & chatgpt.com
date_learned: 2025-06-25T10:39:00
tags:
  - tree-algorithm
---
---
# B-tree

**B-tree** adalah jenis khusus dari _self-balancing search tree_ di mana setiap node dapat memuat lebih dari satu _key_ dan dapat memiliki lebih dari dua _children_. Ini merupakan bentuk generalisasi dari _binary search tree_.

B-tree juga dikenal sebagai _height-balanced m-way tree_.

![[01 - B-tree-1.png]]

---

## Mengapa Kita Membutuhkan Struktur Data B-tree?

Kebutuhan akan B-tree muncul seiring meningkatnya kebutuhan akan waktu akses yang lebih cepat terhadap media penyimpanan fisik seperti _hard disk_. Perangkat penyimpanan sekunder umumnya lebih lambat namun memiliki kapasitas besar. Oleh karena itu, dibutuhkan jenis struktur data yang dapat meminimalkan akses terhadap disk.

Struktur data lain seperti _binary search tree_, _AVL tree_, _red-black tree_, dan sebagainya hanya dapat menyimpan satu _key_ dalam satu _node_. Jika Anda perlu menyimpan banyak _key_, maka tinggi pohon tersebut akan menjadi sangat besar, sehingga waktu akses pun meningkat.

Namun, B-tree dapat menyimpan banyak _key_ dalam satu _node_ dan dapat memiliki banyak _child node_. Ini secara signifikan mengurangi tinggi pohon, yang memungkinkan akses disk menjadi lebih cepat.

---

## Properti B-tree

- Untuk setiap node `x`, _key_ disimpan dalam urutan menaik.
    
- Di setiap node, terdapat nilai boolean `x.leaf` yang bernilai _true_ jika `x` adalah sebuah _leaf_ (daun).
    
- Jika `n` adalah _order_ dari pohon, maka setiap _internal node_ dapat memiliki paling banyak `n - 1` _key_ beserta satu _pointer_ untuk setiap _child_.
    
- Setiap node (kecuali _root_) dapat memiliki paling banyak `n` _children_ dan paling sedikit `n/2` _children_.
    
- Semua _leaf_ berada pada kedalaman yang sama (yaitu pada ketinggian `h` dari pohon).
    
- _Root_ memiliki setidaknya 2 _children_ dan mengandung minimal 1 _key_.
    
- Jika `n ≥ 1`, maka untuk setiap B-tree dengan `n` _key_, ketinggian `h`, dan _minimum degree_ `t ≥ 2`, maka berlaku:
    
    $$h \geq \log_t \left(\frac{n + 1}{2}\right)$$

Berikut terjemahan lengkap dalam bahasa Indonesia untuk bagian **"Operations on a B-tree: Searching an element in a B-tree"** dari materi Programmiz, dengan mempertahankan istilah komputasionalnya:

---

## Operasi pada B-tree

### Mencari Elemen dalam B-tree

Pencarian elemen dalam sebuah **B-tree** adalah bentuk generalisasi dari pencarian elemen dalam **Binary Search Tree**. Langkah-langkah berikut dilakukan:

1. Mulai dari **root node**, bandingkan `k` dengan _key_ pertama dari node.
	Jika `k` = _key_ pertama dari node, maka **kembalikan node tersebut beserta indeksnya**.
    
2. Jika `x.leaf = true`, maka **kembalikan NULL** (artinya elemen tidak ditemukan).
    
3. Jika `k < key pertama` dari node, maka **lakukan pencarian rekursif pada child sebelah kiri dari key tersebut**.
    
4. Jika terdapat lebih dari satu _key_ di dalam node saat ini dan `k > key pertama`, maka:
    
    - Bandingkan `k` dengan _key_ berikutnya dalam node.
        
    - Jika `k < key berikutnya`, maka **lakukan pencarian pada child kiri dari key tersebut** (artinya `k` berada di antara key pertama dan key kedua).
        
    - Jika tidak, **lakukan pencarian pada child kanan dari key tersebut**.
        
5. Ulangi langkah 1 hingga 5 sampai mencapai _leaf_.
    

---

#### Contoh Pencarian

1. Misalkan kita ingin mencari _key_ `k = 17` dalam pohon B-tree di bawah ini dengan _degree_ 3:
   
   ![[01 - B-tree-2.png]]
2. $k$ tidak ditemukan di root, jadi bandingkan dengan key di root.
   
   ![[01 - B-tree-3.png]]
3. Karena $k > 11$, pergi ke child kanan dari node root.
   
   ![[01 - B-tree-4.png]]
4. Bandingkan $k$ dengan 16. Karena $k > 16$, bandingkan $k$ dengan key berikutnya yaitu 18.
   
   ![[01 - B-tree-5.png]]
5. Karena $k < 18$, $k$ berada di antara 16 dan 18. Cari di child kanan dari 16 atau child kiri dari 18. 
   
   ![[01 - B-tree-6.png]]
6. $k$ ditemukan
   
   ![[01 - B-tree-7.png]]
---
## Algoritma untuk Mencari Sebuah Elemen

```
BtreeSearch(x, k)
  i = 1
  while i ≤ n[x] and k ≥ keyᵢ[x]        // n[x] berarti jumlah key dalam node x
      do i = i + 1
  if i ≤ n[x] and k = keyᵢ[x]
      then return (x, i)
  if leaf[x]
      then return NIL
  else
      return BtreeSearch(cᵢ[x], k)
```

Untuk mempelajari lebih lanjut tentang berbagai operasi pada B-tree, silakan kunjungi:

- **Penyisipan pada B-tree (Insertion on B-tree)**
    
- **Penghapusan pada B-tree (Deletion on B-tree)**
    

## Implementasi Kode 

```cpp
// Searching a key on a B-tree in C++

#include <iostream>
using namespace std;

class TreeNode {
  int *keys;
  int t;
  TreeNode **C;
  int n;
  bool leaf;

   public:
  TreeNode(int temp, bool bool_leaf);

  void insertNonFull(int k);
  void splitChild(int i, TreeNode *y);
  void traverse();

  TreeNode *search(int k);

  friend class BTree;
};

class BTree {
  TreeNode *root;
  int t;

   public:
  BTree(int temp) {
    root = NULL;
    t = temp;
  }

  void traverse() {
    if (root != NULL)
      root->traverse();
  }

  TreeNode *search(int k) {
    return (root == NULL) ? NULL : root->search(k);
  }

  void insert(int k);
};

TreeNode::TreeNode(int t1, bool leaf1) {
  t = t1;
  leaf = leaf1;

  keys = new int[2 * t - 1];
  C = new TreeNode *[2 * t];

  n = 0;
}

void TreeNode::traverse() {
  int i;
  for (i = 0; i < n; i++) {
    if (leaf == false)
      C[i]->traverse();
    cout << " " << keys[i];
  }

  if (leaf == false)
    C[i]->traverse();
}

TreeNode *TreeNode::search(int k) {
  int i = 0;
  while (i < n && k > keys[i])
    i++;

  if (keys[i] == k)
    return this;

  if (leaf == true)
    return NULL;

  return C[i]->search(k);
}

void BTree::insert(int k) {
  if (root == NULL) {
    root = new TreeNode(t, true);
    root->keys[0] = k;
    root->n = 1;
  } else {
    if (root->n == 2 * t - 1) {
      TreeNode *s = new TreeNode(t, false);

      s->C[0] = root;

      s->splitChild(0, root);

      int i = 0;
      if (s->keys[0] < k)
        i++;
      s->C[i]->insertNonFull(k);

      root = s;
    } else
      root->insertNonFull(k);
  }
}

void TreeNode::insertNonFull(int k) {
  int i = n - 1;

  if (leaf == true) {
    while (i >= 0 && keys[i] > k) {
      keys[i + 1] = keys[i];
      i--;
    }

    keys[i + 1] = k;
    n = n + 1;
  } else {
    while (i >= 0 && keys[i] > k)
      i--;

    if (C[i + 1]->n == 2 * t - 1) {
      splitChild(i + 1, C[i + 1]);

      if (keys[i + 1] < k)
        i++;
    }
    C[i + 1]->insertNonFull(k);
  }
}

void TreeNode::splitChild(int i, TreeNode *y) {
  TreeNode *z = new TreeNode(y->t, y->leaf);
  z->n = t - 1;

  for (int j = 0; j < t - 1; j++)
    z->keys[j] = y->keys[j + t];

  if (y->leaf == false) {
    for (int j = 0; j < t; j++)
      z->C[j] = y->C[j + t];
  }

  y->n = t - 1;
  for (int j = n; j >= i + 1; j--)
    C[j + 1] = C[j];

  C[i + 1] = z;

  for (int j = n - 1; j >= i; j--)
    keys[j + 1] = keys[j];

  keys[i] = y->keys[t - 1];
  n = n + 1;
}

int main() {
  BTree t(3);
  t.insert(8);
  t.insert(9);
  t.insert(10);
  t.insert(11);
  t.insert(15);
  t.insert(16);
  t.insert(17);
  t.insert(18);
  t.insert(20);
  t.insert(23);

  cout << "The B-tree is: ";
  t.traverse();

  int k = 10;
  (t.search(k) != NULL) ? cout << endl
                 << k << " is found"
              : cout << endl
                 << k << " is not Found";

  k = 2;
  (t.search(k) != NULL) ? cout << endl
                 << k << " is found"
              : cout << endl
                 << k << " is not Found\n";
}
```

Berikut penjelasan per blok kode:

---

### 1. Header dan `using namespace`

```cpp
#include <iostream>
using namespace std;
```

- **`<iostream>`**: diperlukan untuk operasi input/output (`cin`, `cout`).
    
- **`using namespace std;`**: agar tidak perlu menulis `std::` di depan `cout`, `endl`, dll.
    

---

### 2. Deklarasi kelas `TreeNode`

```cpp
class TreeNode {
  int *keys;         // array penyimpan key
  int t;             // minimum degree (orde)
  TreeNode **C;      // array pointer ke child nodes
  int n;             // jumlah key saat ini di node
  bool leaf;         // true jika node ini leaf

public:
  TreeNode(int temp, bool bool_leaf);

  void insertNonFull(int k);
  void splitChild(int i, TreeNode *y);
  void traverse();
  TreeNode *search(int k);

  friend class BTree;
};
```

- **`keys`**, **`n`**: menyimpan key dan jumlahnya.
    
- **`t`**: derajat minimum, menentukan ukuran maksimum/minimum array `keys` dan `C`.
    
- **`C`**: pointer ke maksimal `2*t` child.
    
- **`leaf`**: menandai apakah node tidak memiliki child.
    
- **Metode utama**:
    
    - `insertNonFull`: sisipkan key ke node yang belum penuh.
        
    - `splitChild`: bagi child penuh menjadi dua node.
        
    - `traverse`: cetak inorder semua key di subtree ini.
        
    - `search`: cari key `k` di subtree ini.
        
- **`friend class BTree;`** memberi akses ke anggota privat dari `BTree`.
    

---

### 3. Deklarasi dan konstruktor kelas `BTree`

```cpp
class BTree {
  TreeNode *root;
  int t;            // minimum degree

public:
  BTree(int temp) {
    root = NULL;
    t = temp;
  }

  void traverse() {
    if (root != NULL)
      root->traverse();
  }

  TreeNode *search(int k) {
    return (root == NULL) ? NULL : root->search(k);
  }

  void insert(int k);
};
```

- **`root`**: pointer ke node akar.
    
- **`t`**: derajat minimum dipakai saat membuat node baru.
    
- **`traverse()`**: jika pohon tidak kosong, cetak semua key.
    
- **`search(k)`**: jika kosong kembalikan `NULL`, jika tidak delegasikan ke `root->search(k)`.
    
- **`insert(k)`**: deklarasi fungsi sisipkan (definisi di bawah).
    

---

### 4. Definisi konstruktor `TreeNode`

```cpp
TreeNode::TreeNode(int t1, bool leaf1) {
  t = t1;
  leaf = leaf1;
  keys = new int[2 * t - 1];
  C = new TreeNode *[2 * t];
  n = 0;
}
```

- Alokasi dinamis:
    
    - `keys` berkapasitas maksimum `2*t - 1`.
        
    - `C` untuk pointer child sebanyak `2*t`.
        
- Awalnya `n = 0` (belum ada key).
    

---

### 5. Metode `traverse()` pada `TreeNode`

```cpp
void TreeNode::traverse() {
  int i;
  for (i = 0; i < n; i++) {
    if (leaf == false)
      C[i]->traverse();
    cout << " " << keys[i];
  }
  if (leaf == false)
    C[i]->traverse();
}
```

- **Inorder traversal** untuk B-tree:
    
    1. Rekursif traverse `C[0]`, cetak `keys[0]`.
        
    2. Rekursif traverse `C[1]`, cetak `keys[1]`, … hingga `keys[n-1]`.
        
    3. Setelah loop, traverse `C[n]` terakhir bila bukan leaf.
        

---

### 6. Metode `search(int k)` pada `TreeNode`

```cpp
TreeNode *TreeNode::search(int k) {
  int i = 0;
  while (i < n && k > keys[i])
    i++;
  if (keys[i] == k)
    return this;
  if (leaf == true)
    return NULL;
  return C[i]->search(k);
}
```

- **Langkah pencarian**:
    
    1. Cari posisi pertama `i` di mana `keys[i] ≥ k`.
        
    2. Jika sama, kembalikan pointer ke node ini.
        
    3. Jika leaf dan belum ketemu, return `NULL`.
        
    4. Jika bukan leaf, rekursif ke `C[i]`.
        

---

### 7. Definisi `BTree::insert(int k)`

```cpp
void BTree::insert(int k) {
  if (root == NULL) {
    root = new TreeNode(t, true);
    root->keys[0] = k;
    root->n = 1;
  } else {
    if (root->n == 2 * t - 1) {
      TreeNode *s = new TreeNode(t, false);
      s->C[0] = root;
      s->splitChild(0, root);
      int i = 0;
      if (s->keys[0] < k) i++;
      s->C[i]->insertNonFull(k);
      root = s;
    } else
      root->insertNonFull(k);
  }
}
```

- **Kasus kosong**: buat root baru sebagai leaf, simpan `k`.
    
- **Root penuh** (`n == 2*t-1`):
    
    1. Buat node baru `s` sebagai non-leaf.
        
    2. Jadikan `root` sebagai child pertama `s`.
        
    3. `splitChild(0, root)` membagi node lama.
        
    4. Tentukan cabang mana (`i`) untuk sisip `k` dan panggil `insertNonFull`.
        
    5. Update `root = s`.
        
- **Root belum penuh**: langsung `insertNonFull`.
    

---

### 8. Metode `insertNonFull(int k)`

```cpp
void TreeNode::insertNonFull(int k) {
  int i = n - 1;
  if (leaf == true) {
    while (i >= 0 && keys[i] > k) {
      keys[i + 1] = keys[i];
      i--;
    }
    keys[i + 1] = k;
    n = n + 1;
  } else {
    while (i >= 0 && keys[i] > k)
      i--;
    if (C[i + 1]->n == 2 * t - 1) {
      splitChild(i + 1, C[i + 1]);
      if (keys[i + 1] < k) i++;
    }
    C[i + 1]->insertNonFull(k);
  }
}
```

- **Jika leaf**:
    
    1. Geser semua key > `k` ke kanan.
        
    2. Sisip `k` di posisi yang tepat, increment `n`.
        
- **Jika internal node**:
    
    1. Cari child index `i+1` untuk sisipan.
        
    2. Jika child itu penuh, panggil `splitChild` dulu.
        
    3. Re-evaluasi `i` jika median berpindah.
        
    4. Rekursif `insertNonFull` di child yang sesuai.
        

---

### 9. Metode `splitChild(int i, TreeNode *y)`

```cpp
void TreeNode::splitChild(int i, TreeNode *y) {
  TreeNode *z = new TreeNode(y->t, y->leaf);
  z->n = t - 1;
  for (int j = 0; j < t - 1; j++)
    z->keys[j] = y->keys[j + t];
  if (y->leaf == false) {
    for (int j = 0; j < t; j++)
      z->C[j] = y->C[j + t];
  }
  y->n = t - 1;
  for (int j = n; j >= i + 1; j--)
    C[j + 1] = C[j];
  C[i + 1] = z;
  for (int j = n - 1; j >= i; j--)
    keys[j + 1] = keys[j];
  keys[i] = y->keys[t - 1];
  n = n + 1;
}
```

- **Tujuan**: bagi child `y` yang penuh menjadi `y` dan `z`, serta naikkan median ke parent (`this`).
    
- **Langkah**:
    
    1. Buat `z` (node baru) salin `t-1` key terbesar dari `y`.
        
    2. Jika bukan leaf, salin juga `t` pointer child.
        
    3. Kurangi `y->n` jadi `t-1`.
        
    4. Geser pointer child parent, sisip `z` di `C[i+1]`.
        
    5. Geser key parent, taruh median `y->keys[t-1]` di `keys[i]`.
        
    6. Increment `n` parent.
        

---

### 10. Fungsi `main()`

```cpp
int main() {
  BTree t(3);
  t.insert(8);  t.insert(9);  t.insert(10);
  t.insert(11); t.insert(15); t.insert(16);
  t.insert(17); t.insert(18); t.insert(20);
  t.insert(23);

  cout << "The B-tree is: ";
  t.traverse();

  int k = 10;
  (t.search(k) != NULL) ? cout << endl << k << " is found"
                       : cout << endl << k << " is not Found";
  k = 2;
  (t.search(k) != NULL) ? cout << endl << k << " is found"
                       : cout << endl << k << " is not Found\n";
}
```

- **Inisialisasi** `BTree` dengan `t = 3`.
    
- Lakukan beberapa **`insert`** untuk membangun pohon.
    
- Cetak struktur pohon lewat **`traverse()`**.
    
- Cek pencarian dua nilai (`10` dan `2`), tampilkan hasil `is found` atau `is not Found`.
    
