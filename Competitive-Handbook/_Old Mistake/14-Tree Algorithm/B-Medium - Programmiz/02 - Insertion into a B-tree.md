---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 14TH-TREE-00B2
nama_algoritma: 
kategori_algoritma: tree algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: programiz.com & chatgpt.com
date_learned: 2025-06-25T11:02:00
tags:
  - tree-algorithm
---
---
# Insertion into a B-tree

Menyisipkan sebuah elemen ke dalam B-tree terdiri dari dua tahap: **mencari node yang tepat untuk penyisipan** dan **membagi node jika diperlukan**. Operasi penyisipan selalu dilakukan dengan pendekatan **bottom-up** (dari bawah ke atas).

Mari kita pahami kedua tahap ini di bawah.

---

## Operasi Penyisipan

1. Jika pohon kosong, alokasikan sebuah node root dan sisipkan key.
    
2. Perbarui jumlah key yang diizinkan dalam node.
    
3. Cari node yang tepat untuk tempat penyisipan.
    
4. Jika node tersebut penuh, ikuti langkah-langkah berikut:
    
    - Sisipkan elemen dalam urutan menaik.
        
    - Sekarang terdapat elemen lebih banyak dari batas yang diperbolehkan, jadi lakukan **pembagian pada median**.
        
    - Dorong key median ke atas dan jadikan key di sebelah kiri sebagai child kiri, serta key di sebelah kanan sebagai child kanan.
        
5. Jika node tidak penuh, ikuti langkah-langkah berikut:
    
    - Sisipkan elemen ke dalam node dalam urutan menaik.
        

---

## Contoh Penyisipan

Mari kita pahami operasi penyisipan melalui ilustrasi berikut.

Elemen-elemen yang akan disisipkan adalah: **8, 9, 10, 11, 15, 20, 17**

![[02 - Insertion into a B-tree-1.png]]

## Algoritma Penyisipan Element

```bash
BreeInsertion(T, k)
r  root[T]
if n[r] = 2t - 1
    s = AllocateNode()
    root[T] = s
    leaf[s] = FALSE
    n[s] <- 0
    c1[s] <- r
    BtreeSplitChild(s, 1, r)
    BtreeInsertNonFull(s, k)
else BtreeInsertNonFull(r, k)
BtreeInsertNonFull(x, k)
i = n[x]
if leaf[x]
    while i ≥ 1 and k < keyi[x]
        keyi+1 [x] = keyi[x]
        i = i - 1
    keyi+1[x] = k
    n[x] = n[x] + 1
else while i ≥ 1 and k < keyi[x]
        i = i - 1
    i = i + 1
    if n[ci[x]] == 2t - 1
        BtreeSplitChild(x, i, ci[x])
        if k &rt; keyi[x]
            i = i + 1
    BtreeInsertNonFull(ci[x], k)
BtreeSplitChild(x, i)
BtreeSplitChild(x, i, y)
z = AllocateNode()
leaf[z] = leaf[y]
n[z] = t - 1
for j = 1 to t - 1
    keyj[z] = keyj+t[y]
if not leaf [y]
    for j = 1 to t
        cj[z] = cj + t[y]
n[y] = t - 1
for j = n[x] + 1 to i + 1
    cj+1[x] = cj[x]
ci+1[x] = z
for j = n[x] to i
    keyj+1[x] = keyj[x]
keyi[x] = keyt[y]
n[x] = n[x] + 1
```

Atau jika disederhanakan lagi, dan dipecah menjadi 3:
### Algoritma Penyisipan Elemen

```bash
BtreeInsertion(T, k)
    r ← root[T]
    if n[r] = 2t - 1
        s ← AllocateNode()
        root[T] ← s
        leaf[s] ← FALSE
        n[s] ← 0
        c₁[s] ← r
        BtreeSplitChild(s, 1, r)
        BtreeInsertNonFull(s, k)
    else
        BtreeInsertNonFull(r, k)
```

---

### BtreeInsertNonFull(x, k)

```bash
    i ← n[x]
    if leaf[x]
        while i ≥ 1 and k < keyᵢ[x]
            keyᵢ₊₁[x] ← keyᵢ[x]
            i ← i - 1
        keyᵢ₊₁[x] ← k
        n[x] ← n[x] + 1
    else
        while i ≥ 1 and k < keyᵢ[x]
            i ← i - 1
        i ← i + 1
        if n[cᵢ[x]] = 2t - 1
            BtreeSplitChild(x, i, cᵢ[x])
            if k > keyᵢ[x]
                i ← i + 1
        BtreeInsertNonFull(cᵢ[x], k)
```

---

### BtreeSplitChild(x, i, y)

```bash
    z ← AllocateNode()
    leaf[z] ← leaf[y]
    n[z] ← t - 1

    for j = 1 to t - 1
        keyⱼ[z] ← keyⱼ₊ₜ[y]

    if not leaf[y]
        for j = 1 to t
            cⱼ[z] ← cⱼ₊ₜ[y]

    n[y] ← t - 1

    for j = n[x] + 1 down to i + 1
        cⱼ₊₁[x] ← cⱼ[x]

    cᵢ₊₁[x] ← z

    for j = n[x] down to i
        keyⱼ₊₁[x] ← keyⱼ[x]

    keyᵢ[x] ← keyₜ[y]
    n[x] ← n[x] + 1
```

---

Algoritma ini terdiri dari 3 fungsi utama:

1. **BtreeInsertion(T, k)**: Fungsi utama untuk menyisipkan `k` ke dalam B-tree `T`.
    
2. **BtreeInsertNonFull(x, k)**: Menyisipkan `k` ke dalam node `x` yang belum penuh.
    
3. **BtreeSplitChild(x, i, y)**: Membagi node `y` yang penuh menjadi dua, lalu naikkan median ke node `x`.
    

## Implementasi Kode

```cpp
// Inserting a key on a B-tree in C++

#include <iostream>
using namespace std;

class Node {
  int *keys;
  int t;
  Node **C;
  int n;
  bool leaf;

   public:
  Node(int _t, bool _leaf);

  void insertNonFull(int k);
  void splitChild(int i, Node *y);
  void traverse();

  friend class BTree;
};

class BTree {
  Node *root;
  int t;

   public:
  BTree(int _t) {
    root = NULL;
    t = _t;
  }

  void traverse() {
    if (root != NULL)
      root->traverse();
  }

  void insert(int k);
};

Node::Node(int t1, bool leaf1) {
  t = t1;
  leaf = leaf1;

  keys = new int[2 * t - 1];
  C = new Node *[2 * t];

  n = 0;
}

// Traverse the nodes
void Node::traverse() {
  int i;
  for (i = 0; i < n; i++) {
    if (leaf == false)
      C[i]->traverse();
    cout << " " << keys[i];
  }

  if (leaf == false)
    C[i]->traverse();
}

// Insert the node
void BTree::insert(int k) {
  if (root == NULL) {
    root = new Node(t, true);
    root->keys[0] = k;
    root->n = 1;
  } else {
    if (root->n == 2 * t - 1) {
      Node *s = new Node(t, false);

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

// Insert non full condition
void Node::insertNonFull(int k) {
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

// split the child
void Node::splitChild(int i, Node *y) {
  Node *z = new Node(y->t, y->leaf);
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
}
```

Berikut penjelasan per blok kode:

---

### 1. Header dan `using namespace`

```cpp
#include <iostream>
using namespace std;
```

- Mengimpor library **`<iostream>`** untuk operasi input/output (`cout`).
    
- `using namespace std;` agar tidak perlu menulis `std::` di depan `cout`, `endl`, dll.
    

---

### 2. Deklarasi kelas `Node`

```cpp
class Node {
  int *keys;        // array untuk menyimpan key
  int t;            // derajat minimum (minimum degree)
  Node **C;         // array pointer ke maksimal 2*t child
  int n;            // jumlah key saat ini di node
  bool leaf;        // true jika node ini leaf (daun)

public:
  Node(int _t, bool _leaf);

  void insertNonFull(int k);
  void splitChild(int i, Node *y);
  void traverse();

  friend class BTree;
};
```

- **`keys`** dan **`n`**: menyimpan key dan jumlahnya.
    
- **`t`**: menentukan kapasitas `keys` (`2*t-1`) dan `C` (`2*t`).
    
- **`C`**: pointer ke child, digunakan saat traversal dan pembagian node.
    
- **`leaf`**: menandai apakah node tidak punya child.
    
- Metode:
    
    - `insertNonFull`: sisipkan key jika node belum penuh.
        
    - `splitChild`: bagi node yang penuh.
        
    - `traverse`: cetak semua key di subtree ini.
        
- `friend class BTree;` memberi akses privat kepada `BTree`.
    

---

### 3. Deklarasi kelas `BTree`

```cpp
class BTree {
  Node *root;   // pointer ke node akar
  int t;        // derajat minimum

public:
  BTree(int _t) {
    root = NULL;
    t = _t;
  }

  void traverse() {
    if (root != NULL)
      root->traverse();
  }

  void insert(int k);
};
```

- **`root`**: akar pohon B-tree.
    
- **`t`**: derajat minimum untuk seluruh pohon.
    
- Konstruktor inisialisasi `root = NULL`.
    
- `traverse()`: jika tidak kosong, delegasikan ke `root->traverse()`.
    
- `insert(int k)`: deklarasi metode penyisipan (definisi di bawah).
    

---

### 4. Konstruktor `Node`

```cpp
Node::Node(int t1, bool leaf1) {
  t = t1;
  leaf = leaf1;

  keys = new int[2 * t - 1];
  C = new Node *[2 * t];

  n = 0;
}
```

- Mengalokasikan array `keys` dengan kapasitas maksimum `2*t - 1`.
    
- Mengalokasikan array `C` untuk pointer child sebanyak `2*t`.
    
- Set `n = 0` artinya node masih kosong.
    

---

### 5. Metode `traverse()`

```cpp
void Node::traverse() {
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

- Melakukan **in-order traversal**:
    
    1. Rekursif ke child `C[0]`, cetak `keys[0]`
        
    2. Rekursif ke `C[1]`, cetak `keys[1]`, … hingga `keys[n-1]`
        
    3. Setelah loop, rekursif ke `C[n]` jika bukan leaf.
        

---

### 6. Metode `BTree::insert(int k)`

```cpp
void BTree::insert(int k) {
  if (root == NULL) {
    // Kasus pohon kosong
    root = new Node(t, true);
    root->keys[0] = k;
    root->n = 1;
  } else {
    // Jika root penuh, split sebelum sisip
    if (root->n == 2 * t - 1) {
      Node *s = new Node(t, false);
      s->C[0] = root;
      s->splitChild(0, root);
      int i = 0;
      if (s->keys[0] < k)
        i++;
      s->C[i]->insertNonFull(k);
      root = s;
    } else {
      // Root belum penuh: langsung sisip
      root->insertNonFull(k);
    }
  }
}
```

- **Pohon kosong**: buat root baru, sisip `k`, set `n=1`.
    
- **Root penuh**:
    
    1. Buat node `s` baru sebagai non-leaf.
        
    2. Jadikan `root` sebagai child pertama `s`.
        
    3. `splitChild(0, root)` membagi node lama.
        
    4. Tentukan child mana (`i`) untuk sisip `k`, lalu `insertNonFull`.
        
    5. Update `root = s`.
        
- **Root tidak penuh**: langsung `insertNonFull`.
    

---

### 7. Metode `insertNonFull(int k)`

```cpp
void Node::insertNonFull(int k) {
  int i = n - 1;

  if (leaf == true) {
    // Sisip ke leaf
    while (i >= 0 && keys[i] > k) {
      keys[i + 1] = keys[i];
      i--;
    }
    keys[i + 1] = k;
    n++;
  } else {
    // Temukan child yang tepat
    while (i >= 0 && keys[i] > k)
      i--;
    // Jika child penuh, split dulu
    if (C[i + 1]->n == 2 * t - 1) {
      splitChild(i + 1, C[i + 1]);
      if (keys[i + 1] < k)
        i++;
    }
    C[i + 1]->insertNonFull(k);
  }
}
```

- **Leaf**: geser key yang lebih besar, sisip `k`, naikkan `n`.
    
- **Internal node**:
    
    1. Tentukan child index `i+1`.
        
    2. Jika child penuh, panggil `splitChild`.
        
    3. Mungkin update `i` jika median berpindah.
        
    4. Rekursif sisip di `C[i+1]`.
        

---

### 8. Metode `splitChild(int i, Node *y)`

```cpp
void Node::splitChild(int i, Node *y) {
  Node *z = new Node(y->t, y->leaf);
  z->n = t - 1;

  // Salin t-1 key terbesar dari y ke z
  for (int j = 0; j < t - 1; j++)
    z->keys[j] = y->keys[j + t];

  // Jika bukan leaf, salin juga t pointer child
  if (y->leaf == false) {
    for (int j = 0; j < t; j++)
      z->C[j] = y->C[j + t];
  }

  // Kurangi jumlah key di y
  y->n = t - 1;

  // Geser pointer child di parent untuk membuka slot
  for (int j = n; j >= i + 1; j--)
    C[j + 1] = C[j];
  C[i + 1] = z;

  // Geser key parent dan sisip median dari y
  for (int j = n - 1; j >= i; j--)
    keys[j + 1] = keys[j];
  keys[i] = y->keys[t - 1];

  n++;
}
```

- Membagi `y` yang penuh menjadi dua node (`y` dan `z`).
    
- **`z`** menerima **t–1 key** terbesar, dan jika ada child, juga menerima **t child** terakhir.
    
- Median `y->keys[t-1]` diangkat ke parent (`this`).
    

---

### 9. Fungsi `main()`

```cpp
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
}
```

- Membuat **B-tree** ber-derajat minimum `t = 3`.
    
- Menyisipkan beberapa key secara berurutan.
    
- Mencetak isi B-tree melalui `traverse()`.
    
