---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 14TH-TREE-00B3
nama_algoritma: 
kategori_algoritma: tree algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: programiz.com & chatgpt.com
date_learned: 2025-06-25T11:11:00
tags:
  - tree-algorithm
---
---
# Deletion from a B-tree

Menghapus sebuah elemen dari B-tree terdiri dari **tiga tahap utama**:

1. Mencari node tempat key yang akan dihapus berada,
    
2. Menghapus key tersebut, dan
    
3. Menyeimbangkan pohon jika diperlukan.
    

Saat melakukan penghapusan pada pohon, bisa terjadi kondisi yang disebut **underflow**.  
**Underflow** terjadi ketika sebuah node memiliki lebih sedikit key dari jumlah minimum yang seharusnya dimiliki.

Berikut istilah-istilah yang Perlu Dipahami Sebelum Mempelajari Operasi Penghapusan:

**Inorder Predecessor**
- Key terbesar yang berada di **child kiri** dari sebuah node disebut **inorder predecessor**.

**Inorder Successor**
- Key terkecil yang berada di **child kanan** dari sebuah node disebut **inorder successor**.

---

## Operasi Penghapusan

Sebelum mempelajari langkah-langkah penghapusan di bawah ini, penting untuk mengetahui fakta berikut tentang B-tree dengan derajat **m**:

- Sebuah node dapat memiliki **maksimal m anak**. (contoh: m = 3)
    
- Sebuah node dapat memiliki **maksimal $m - 1$ key**. (contoh: 2 key)
    
- Sebuah node harus memiliki **minimal $⌈m / 2⌉$ anak**. (contoh: 2 anak)
    
- Sebuah node (kecuali root) harus memiliki **minimal $⌈m / 2⌉ - 1$ key**. (contoh: 1 key)
    

Berikut adalah tiga Kasus Utama dalam Operasi Penghapusan pada B-tree:

### Kasus I

Key yang akan dihapus **berada di dalam leaf** (daun). Terdapat dua kemungkinan:

1. **Penghapusan key tidak melanggar properti jumlah minimum key** yang harus dimiliki oleh sebuah node.
    
	Contoh, dalam pohon di bawah, menghapus key `32` **tidak** melanggar aturan-aturan di atas.
	
	![[03 - Deletion from a B-tree-1.png]]
	

2. Penghapusan key **melanggar properti jumlah minimum key** yang seharusnya dimiliki oleh sebuah node. Dalam kasus ini, kita **meminjam key dari node saudara terdekat** (sibling) dalam urutan dari kiri ke kanan.

	- Pertama, periksa **saudara kiri** secara langsung.  
	    Jika node saudara kiri memiliki lebih dari jumlah minimum key, maka **pinjam satu key** dari node tersebut.
	    
	- Jika tidak, periksa apakah bisa meminjam dari **saudara kanan** secara langsung.
	    
	
	Pada pohon di bawah, penghapusan key `31` mengakibatkan kondisi seperti di atas.  
	Maka, kita **meminjam satu key dari node saudara kiri**.
	
	![[03 - Deletion from a B-tree-2.png]]
	Jika **kedua node saudara terdekat** (baik kiri maupun kanan) **sudah memiliki jumlah minimum key**, maka node tersebut **digabungkan** (**merge**) dengan salah satu node saudara (kiri atau kanan).  
	Proses penggabungan ini dilakukan **melalui node induk** (parent).
	
	Penghapusan key `30` menghasilkan kasus seperti ini.
	![[03 - Deletion from a B-tree-3.png]]


### Kasus II

Jika **key yang akan dihapus berada di dalam node internal**, maka kemungkinan berikut dapat terjadi:

- **Node internal** yang key-nya dihapus akan **digantikan oleh inorder predecessor** jika **child kiri** dari node tersebut memiliki **lebih dari jumlah minimum key**.

	![[03 - Deletion from a B-tree-4.png]]
	<br/>
	- **Node internal** yang key-nya dihapus akan **digantikan oleh inorder successor** jika **child kanan** dari node tersebut memiliki **lebih dari jumlah minimum key**.
    <br/>
	- Jika **kedua child** (kiri dan kanan) memiliki **jumlah key tepat sebanyak jumlah minimum**, maka dilakukan **penggabungan** (**merge**) antara child kiri dan child kanan.
	  
	![[03 - Deletion from a B-tree-5.png]]
	Setelah penggabungan (merge), **jika node induk (parent)** memiliki **jumlah key kurang dari jumlah minimum**, maka **periksa node saudara (sibling)** seperti pada **Kasus I**.

### Kasus III

Dalam kasus ini, **tinggi pohon akan berkurang**.

Jika key yang menjadi target terletak di dalam node internal, dan penghapusannya menyebabkan jumlah key di node tersebut menjadi kurang dari jumlah minimum yang dibutuhkan, maka:

- Cari inorder predecessor dan inorder successor.
    
- Jika kedua child (kiri dan kanan) hanya memiliki jumlah minimum key, maka tidak bisa melakukan peminjaman.
    
- Ini mengarah ke Kasus II(3), yaitu penggabungan kedua child.
    

Selanjutnya, cari saudara (sibling) untuk meminjam key.

Namun, jika saudara juga hanya memiliki jumlah minimum key, maka:

- Gabungkan node dengan saudara dan juga dengan parent-nya.
    
- Atur child secara urut menaik (increasing order).
    
![[03 - Deletion from a B-tree-6.png]]

## Implementasi Kode


```cpp
// Deleting a key from a B-tree in C++

#include <iostream>
using namespace std;

class BTreeNode {
  int *keys;
  int t;
  BTreeNode **C;
  int n;
  bool leaf;

   public:
  BTreeNode(int _t, bool _leaf);

  void traverse();

  int findKey(int k);
  void insertNonFull(int k);
  void splitChild(int i, BTreeNode *y);
  void deletion(int k);
  void removeFromLeaf(int idx);
  void removeFromNonLeaf(int idx);
  int getPredecessor(int idx);
  int getSuccessor(int idx);
  void fill(int idx);
  void borrowFromPrev(int idx);
  void borrowFromNext(int idx);
  void merge(int idx);
  friend class BTree;
};

class BTree {
  BTreeNode *root;
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

  void insertion(int k);

  void deletion(int k);
};

// B tree node
BTreeNode::BTreeNode(int t1, bool leaf1) {
  t = t1;
  leaf = leaf1;

  keys = new int[2 * t - 1];
  C = new BTreeNode *[2 * t];

  n = 0;
}

// Find the key
int BTreeNode::findKey(int k) {
  int idx = 0;
  while (idx < n && keys[idx] < k)
    ++idx;
  return idx;
}

// Deletion operation
void BTreeNode::deletion(int k) {
  int idx = findKey(k);

  if (idx < n && keys[idx] == k) {
    if (leaf)
      removeFromLeaf(idx);
    else
      removeFromNonLeaf(idx);
  } else {
    if (leaf) {
      cout << "The key " << k << " is does not exist in the tree\n";
      return;
    }

    bool flag = ((idx == n) ? true : false);

    if (C[idx]->n < t)
      fill(idx);

    if (flag && idx > n)
      C[idx - 1]->deletion(k);
    else
      C[idx]->deletion(k);
  }
  return;
}

// Remove from the leaf
void BTreeNode::removeFromLeaf(int idx) {
  for (int i = idx + 1; i < n; ++i)
    keys[i - 1] = keys[i];

  n--;

  return;
}

// Delete from non leaf node
void BTreeNode::removeFromNonLeaf(int idx) {
  int k = keys[idx];

  if (C[idx]->n >= t) {
    int pred = getPredecessor(idx);
    keys[idx] = pred;
    C[idx]->deletion(pred);
  }

  else if (C[idx + 1]->n >= t) {
    int succ = getSuccessor(idx);
    keys[idx] = succ;
    C[idx + 1]->deletion(succ);
  }

  else {
    merge(idx);
    C[idx]->deletion(k);
  }
  return;
}

int BTreeNode::getPredecessor(int idx) {
  BTreeNode *cur = C[idx];
  while (!cur->leaf)
    cur = cur->C[cur->n];

  return cur->keys[cur->n - 1];
}

int BTreeNode::getSuccessor(int idx) {
  BTreeNode *cur = C[idx + 1];
  while (!cur->leaf)
    cur = cur->C[0];

  return cur->keys[0];
}

void BTreeNode::fill(int idx) {
  if (idx != 0 && C[idx - 1]->n >= t)
    borrowFromPrev(idx);

  else if (idx != n && C[idx + 1]->n >= t)
    borrowFromNext(idx);

  else {
    if (idx != n)
      merge(idx);
    else
      merge(idx - 1);
  }
  return;
}

// Borrow from previous
void BTreeNode::borrowFromPrev(int idx) {
  BTreeNode *child = C[idx];
  BTreeNode *sibling = C[idx - 1];

  for (int i = child->n - 1; i >= 0; --i)
    child->keys[i + 1] = child->keys[i];

  if (!child->leaf) {
    for (int i = child->n; i >= 0; --i)
      child->C[i + 1] = child->C[i];
  }

  child->keys[0] = keys[idx - 1];

  if (!child->leaf)
    child->C[0] = sibling->C[sibling->n];

  keys[idx - 1] = sibling->keys[sibling->n - 1];

  child->n += 1;
  sibling->n -= 1;

  return;
}

// Borrow from the next
void BTreeNode::borrowFromNext(int idx) {
  BTreeNode *child = C[idx];
  BTreeNode *sibling = C[idx + 1];

  child->keys[(child->n)] = keys[idx];

  if (!(child->leaf))
    child->C[(child->n) + 1] = sibling->C[0];

  keys[idx] = sibling->keys[0];

  for (int i = 1; i < sibling->n; ++i)
    sibling->keys[i - 1] = sibling->keys[i];

  if (!sibling->leaf) {
    for (int i = 1; i <= sibling->n; ++i)
      sibling->C[i - 1] = sibling->C[i];
  }

  child->n += 1;
  sibling->n -= 1;

  return;
}

// Merge
void BTreeNode::merge(int idx) {
  BTreeNode *child = C[idx];
  BTreeNode *sibling = C[idx + 1];

  child->keys[t - 1] = keys[idx];

  for (int i = 0; i < sibling->n; ++i)
    child->keys[i + t] = sibling->keys[i];

  if (!child->leaf) {
    for (int i = 0; i <= sibling->n; ++i)
      child->C[i + t] = sibling->C[i];
  }

  for (int i = idx + 1; i < n; ++i)
    keys[i - 1] = keys[i];

  for (int i = idx + 2; i <= n; ++i)
    C[i - 1] = C[i];

  child->n += sibling->n + 1;
  n--;

  delete (sibling);
  return;
}

// Insertion operation
void BTree::insertion(int k) {
  if (root == NULL) {
    root = new BTreeNode(t, true);
    root->keys[0] = k;
    root->n = 1;
  } else {
    if (root->n == 2 * t - 1) {
      BTreeNode *s = new BTreeNode(t, false);

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

// Insertion non full
void BTreeNode::insertNonFull(int k) {
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

// Split child
void BTreeNode::splitChild(int i, BTreeNode *y) {
  BTreeNode *z = new BTreeNode(y->t, y->leaf);
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

// Traverse
void BTreeNode::traverse() {
  int i;
  for (i = 0; i < n; i++) {
    if (leaf == false)
      C[i]->traverse();
    cout << " " << keys[i];
  }

  if (leaf == false)
    C[i]->traverse();
}

// Delete Operation
void BTree::deletion(int k) {
  if (!root) {
    cout << "The tree is empty\n";
    return;
  }

  root->deletion(k);

  if (root->n == 0) {
    BTreeNode *tmp = root;
    if (root->leaf)
      root = NULL;
    else
      root = root->C[0];

    delete tmp;
  }
  return;
}

int main() {
  BTree t(3);
  t.insertion(8);
  t.insertion(9);
  t.insertion(10);
  t.insertion(11);
  t.insertion(15);
  t.insertion(16);
  t.insertion(17);
  t.insertion(18);
  t.insertion(20);
  t.insertion(23);

  cout << "The B-tree is: ";
  t.traverse();

  t.deletion(20);

  cout << "\nThe B-tree is: ";
  t.traverse();
}
```

Berikut penjelasan blok demi blok beserta editorial singkat untuk implementasi penghapusan pada B-tree di C++:

---

### 1. Header dan `using namespace`

```cpp
#include <iostream>
using namespace std;
```

- Mengimpor `<iostream>` untuk operasi I/O (`cout`).
    
- `using namespace std;` menghindarkan penulisan `std::` berulang.
    

---

### 2. Deklarasi kelas `BTreeNode`

```cpp
class BTreeNode {
  int *keys;           // array dynamic untuk menyimpan maksimal 2*t-1 key
  int t;               // minimum degree (orde)
  BTreeNode **C;       // array pointer ke maksimal 2*t child
  int n;               // jumlah key saat ini
  bool leaf;           // true jika node adalah leaf

public:
  BTreeNode(int _t, bool _leaf);

  void traverse();
  int findKey(int k);
  void insertNonFull(int k);
  void splitChild(int i, BTreeNode *y);
  void deletion(int k);
  void removeFromLeaf(int idx);
  void removeFromNonLeaf(int idx);
  int getPredecessor(int idx);
  int getSuccessor(int idx);
  void fill(int idx);
  void borrowFromPrev(int idx);
  void borrowFromNext(int idx);
  void merge(int idx);

  friend class BTree;
};
```

- **`keys`**, **`n`**, **`t`**, **`leaf`**, dan **`C`** sama seperti pada struktur B-tree standar.
    
- Metode baru untuk penghapusan:
    
    - `findKey`: cari posisi index untuk key `k`.
        
    - `deletion`: entry point penghapusan.
        
    - `removeFromLeaf` / `removeFromNonLeaf`: dua cara menghapus bergantung node adalah daun atau internal.
        
    - `getPredecessor` / `getSuccessor`: cari pengganti (inorder pred/succ).
        
    - `fill`, `borrowFromPrev`, `borrowFromNext`, `merge`: operasi re-balancing untuk underflow.
        

---

### 3. Deklarasi kelas `BTree`

```cpp
class BTree {
  BTreeNode *root;
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

  void insertion(int k);
  void deletion(int k);
};
```

- Menyimpan pointer `root` dan derajat minimum `t`.
    
- Metode publik: `traverse`, `insertion`, dan `deletion`.
    

---

### 4. Konstruktor `BTreeNode`

```cpp
BTreeNode::BTreeNode(int t1, bool leaf1) {
  t = t1;
  leaf = leaf1;
  keys = new int[2 * t - 1];
  C    = new BTreeNode*[2 * t];
  n = 0;
}
```

- Alokasi dinamis untuk `keys` berkapasitas `2*t-1` dan `C` sebanyak `2*t`.
    
- Inisialisasi `n = 0`.
    

---

### 5. Mencari posisi key: `findKey`

```cpp
int BTreeNode::findKey(int k) {
  int idx = 0;
  while (idx < n && keys[idx] < k)
    ++idx;
  return idx;
}
```

- Mengembalikan posisi pertama `idx` di mana `keys[idx] ≥ k`.
    
- Berguna untuk branch selanjutnya dalam penghapusan.
    

---

### 6. Fungsi utama penghapusan: `deletion`

```cpp
void BTreeNode::deletion(int k) {
  int idx = findKey(k);

  if (idx < n && keys[idx] == k) {
    if (leaf)
      removeFromLeaf(idx);
    else
      removeFromNonLeaf(idx);
  } else {
    if (leaf) {
      cout << "The key " << k << " does not exist in the tree\n";
      return;
    }

    bool flag = (idx == n);
    if (C[idx]->n < t)
      fill(idx);

    if (flag && idx > n)
      C[idx - 1]->deletion(k);
    else
      C[idx]->deletion(k);
  }
}
```

- **Langkah 1**: cari `idx` dengan `findKey`.
    
- **Jika ditemukan di node ini** (`keys[idx] == k`):
    
    - `leaf` → panggil `removeFromLeaf`
        
    - non-leaf → panggil `removeFromNonLeaf`
        
- **Jika tidak ditemukan** di node ini:
    
    - Jika `leaf` → key tidak ada
        
    - Tentukan `flag` menandai pencarian di child terakhir (`idx == n`).
        
    - Jika child `C[idx]` underflow (`< t`), panggil `fill(idx)` untuk perbaikan.
        
    - Lanjutkan rekursi penghapusan di child yang sesuai (sesuaikan `idx` jika `flag`).
        

---

### 7. Hapus pada leaf: `removeFromLeaf`

```cpp
void BTreeNode::removeFromLeaf(int idx) {
  for (int i = idx + 1; i < n; ++i)
    keys[i - 1] = keys[i];
  n--;
}
```

- Geser semua key setelah `idx` ke kiri, kurangi `n`.
    

---

### 8. Hapus pada non-leaf: `removeFromNonLeaf`

```cpp
void BTreeNode::removeFromNonLeaf(int idx) {
  int k = keys[idx];
  if (C[idx]->n >= t) {
    int pred = getPredecessor(idx);
    keys[idx] = pred;
    C[idx]->deletion(pred);
  }
  else if (C[idx+1]->n >= t) {
    int succ = getSuccessor(idx);
    keys[idx] = succ;
    C[idx+1]->deletion(succ);
  }
  else {
    merge(idx);
    C[idx]->deletion(k);
  }
}
```

- **Pilihan pengganti** untuk key di internal node:
    
    1. **Inorder predecessor** (child kiri punya ≥ t key)
        
    2. **Inorder successor** (child kanan punya ≥ t key)
        
    3. **Merge** kedua child jika keduanya hanya punya t−1 key, lalu hapus `k` di child baru.
        

---

### 9. Cari predecessor & successor

```cpp
int BTreeNode::getPredecessor(int idx) {
  BTreeNode *cur = C[idx];
  while (!cur->leaf) cur = cur->C[cur->n];
  return cur->keys[cur->n - 1];
}

int BTreeNode::getSuccessor(int idx) {
  BTreeNode *cur = C[idx + 1];
  while (!cur->leaf) cur = cur->C[0];
  return cur->keys[0];
}
```

- **Pred**: turun ke child kiri, lalu ke paling kanan leaf.
    
- **Succ**: turun ke child kanan, lalu ke paling kiri leaf.
    

---

### 10. Perbaikan underflow: `fill`

```cpp
void BTreeNode::fill(int idx) {
  if (idx != 0 && C[idx-1]->n >= t)
    borrowFromPrev(idx);
  else if (idx != n && C[idx+1]->n >= t)
    borrowFromNext(idx);
  else {
    if (idx != n) merge(idx);
    else merge(idx - 1);
  }
}
```

- **Prioritas peminjaman**:
    
    1. Dari sibling kiri (`borrowFromPrev`)
        
    2. Dari sibling kanan (`borrowFromNext`)
        
- Jika tidak bisa pinjam, **merge** dengan sibling (kanan atau kiri).
    

---

### 11. Peminjaman dari sibling kiri: `borrowFromPrev`

```cpp
void BTreeNode::borrowFromPrev(int idx) {
  BTreeNode *child   = C[idx];
  BTreeNode *sibling = C[idx-1];

  // Geser key dan child child ke kanan di `child`
  for (int i = child->n - 1; i >= 0; --i)
    child->keys[i+1] = child->keys[i];
  if (!child->leaf)
    for (int i = child->n; i >= 0; --i)
      child->C[i+1] = child->C[i];

  // Pinjam key dari parent
  child->keys[0] = keys[idx-1];
  if (!child->leaf)
    child->C[0] = sibling->C[sibling->n];

  // Pindahkan key terakhir sibling ke parent
  keys[idx-1] = sibling->keys[sibling->n - 1];

  child->n += 1;
  sibling->n -= 1;
}
```

- Geser isi `child` untuk membuka slot di depan.
    
- Bawa satu key dari parent ke `child`, dan ambil satu key dari sibling ke parent.
    
- Perbarui `n` child & sibling.
    

---

### 12. Peminjaman dari sibling kanan: `borrowFromNext`

```cpp
void BTreeNode::borrowFromNext(int idx) {
  BTreeNode *child   = C[idx];
  BTreeNode *sibling = C[idx+1];

  // Taruh key parent ke akhir child
  child->keys[child->n] = keys[idx];
  if (!child->leaf)
    child->C[child->n + 1] = sibling->C[0];

  // Geser sibling ke kiri, pindahkan key awal sibling ke parent
  keys[idx] = sibling->keys[0];
  for (int i = 1; i < sibling->n; ++i)
    sibling->keys[i-1] = sibling->keys[i];
  if (!sibling->leaf)
    for (int i = 1; i <= sibling->n; ++i)
      sibling->C[i-1] = sibling->C[i];

  child->n += 1;
  sibling->n -= 1;
}
```

- Simetri dari `borrowFromPrev`, tapi mengambil dari awal sibling kanan.
    

---

### 13. Merge dua child: `merge`

```cpp
void BTreeNode::merge(int idx) {
  BTreeNode *child   = C[idx];
  BTreeNode *sibling = C[idx+1];

  // Tarik key parent[idx] ke tengah child
  child->keys[t-1] = keys[idx];
  // Salin semua key sibling ke child
  for (int i = 0; i < sibling->n; ++i)
    child->keys[i+t] = sibling->keys[i];
  // Jika bukan leaf, salin child pointer sibling
  if (!child->leaf)
    for (int i = 0; i <= sibling->n; ++i)
      child->C[i+t] = sibling->C[i];

  // Geser key dan pointer parent untuk menutup celah
  for (int i = idx+1; i < n; ++i)
    keys[i-1] = keys[i];
  for (int i = idx+2; i <= n; ++i)
    C[i-1] = C[i];

  child->n += sibling->n + 1;
  n--;
  delete sibling;
}
```

- Gabungkan `child` dan `sibling` menjadi satu node, naikkan satu key parent ke child.
    
- Hapus `sibling`, perbaiki parent.
    

---

### 14. Metode sisip dan split (reuse dari kode insertion)

Kode `insertion`, `insertNonFull`, `splitChild`, dan `traverse` identik dengan implementasi sebelumnya pada insertion. Ini memastikan B-tree tetap balanced saat menambah elemen.

---

### 15. Entry point `BTree::deletion`

```cpp
void BTree::deletion(int k) {
  if (!root) {
    cout << "The tree is empty\n";
    return;
  }

  root->deletion(k);

  if (root->n == 0) {
    BTreeNode *tmp = root;
    if (root->leaf)
      root = NULL;
    else
      root = root->C[0];
    delete tmp;
  }
}
```

- Jika pohon kosong: laporkan dan keluar.
    
- Panggil `root->deletion(k)`.
    
- Jika `root` menjadi kosong (`n == 0`), ganti root ke child pertama (atau `NULL` jika leaf), lalu `delete` root lama.
    

---

## Editorial Singkat

1. **Modularisasi**: Setiap langkah penghapusan (leaf vs non-leaf, underflow handling) dipisah jadi fungsi tersendiri, memudahkan pemahaman dan pemeliharaan.
    
2. **Underflow handling**: Urutan check–borrow–merge mengikuti literatur klasik (CLRS).
    
3. **Balancing otomatis**: Setelah setiap penghapusan, struktur B-tree tetap terjaga properti “minimum degree” dan “height-balanced”.
    
4. **Complexity**: Tiap operasi—search, insert, delete—mempunyai kompleksitas `O(t·logₜ n)`, di mana `t` adalah minimum degree dan `n` banyaknya key.
    

## Deletion Complexity

Best case Time complexity: `Θ(log n)`

Average case Space complexity: `Θ(n)`

Worst case Space complexity: `Θ(n)`