---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 14TH-TREE-00B6
nama_algoritma: 
kategori_algoritma: tree algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: programiz.com & chatgpt.com
date_learned: 2025-06-25T12:24:00
tags:
  - tree-algorithm
---
Link sumber: [Deletion from a B+ Tree](https://www.programiz.com/dsa/deletion-from-a-b-plus-tree)

---
# Penghapusan pada B+ Tree

Menghapus elemen dari B+ Tree terdiri dari tiga langkah utama:

1. **Mencari node** di mana _key_ yang akan dihapus berada.
    
2. **Menghapus key** tersebut.
    
3. **Menyeimbangkan pohon** jika diperlukan.
    

Underflow adalah kondisi ketika suatu node memiliki jumlah _key_ yang **kurang dari jumlah minimum** yang seharusnya dimiliki. Ini adalah situasi yang perlu dihindari atau segera diperbaiki dengan teknik peminjaman (borrowing) atau penggabungan (merging).
## Operasi Penghapusan

Sebelum masuk ke langkah-langkah penghapusan, pahami dulu beberapa aturan penting pada B+ Tree dengan derajat _m_:

- Sebuah node dapat memiliki maksimal **$m$ anak**. (contoh: 3)
    
- Sebuah node dapat memiliki maksimal $m - 1$ key. (contoh: 2)
    
- Sebuah node **harus memiliki minimal $⌈m/2⌉$ anak**. (contoh: 2)
    
- Sebuah node (selain akar) **harus memiliki minimal $⌈m/2⌉ - 1$ key**. (contoh: 1)
    

---

 > Catatan Penting
 > 
 > Dalam B+ Tree, nilai-nilai pada _internal node_ (disebut juga _indeks_) bersifat **redundan**, karena semua data sebenarnya hanya disimpan di _leaf node_. Maka saat menghapus, kita **tidak hanya menghapus dari leaf**, tetapi harus memperhatikan juga apakah _key_ tersebut **terjadi di internal node** dan apakah perlu dihapus/di-update juga.

---

### Kasus I

Key yang akan dihapus hanya terdapat pada leaf node dan tidak terdapat pada indeks (atau node internal). Terdapat dua kasus untuk ini:

1. Terdapat lebih dari jumlah minimum key dalam node tersebut.  
    Cukup hapus key tersebut.
    
    ![[06 - Deletion from a B+ Tree-1.png]]
2. Terdapat tepat sejumlah minimum key dalam node. Hapus key tersebut dan pinjam satu key dari saudara terdekat. Tambahkan key median dari node saudara ke node parent.
   
   ![[06 - Deletion from a B+ Tree-2.png]]
### Kasus II  
Key yang akan dihapus juga terdapat pada node internal. Maka kita juga harus menghapusnya dari node internal. Ada beberapa kemungkinan untuk situasi ini:

1. Jika terdapat lebih dari jumlah minimum key dalam node, cukup hapus key dari node daun dan hapus juga key tersebut dari node internal.
	- Isi ruang kosong pada node internal dengan **inorder successor**.
	![[06 - Deletion from a B+ Tree-4.png]]

2. Jika jumlah key dalam node adalah tepat sebanyak jumlah minimum, maka:
	
	- Hapus key tersebut.
	    
	- Pinjam satu key dari sibling terdekat (melalui node induk).
	    
	- Isi ruang kosong yang terbentuk di index (node internal) dengan key yang dipinjam tersebut.
	![[06 - Deletion from a B+ Tree-5.png]]

3. Kasus ini mirip dengan Case II(1), tetapi di sini ruang kosong terbentuk di atas node induk langsung.
	- Setelah menghapus key, gabungkan ruang kosong tersebut dengan sibling-nya.
	    
	- Isi ruang kosong di node kakek (grandparent) dengan inorder successor.
	![[06 - Deletion from a B+ Tree-6.png]]
### Kasus III

Dalam kasus ini, **tinggi pohon akan menyusut**. Ini sedikit lebih rumit dibandingkan kasus sebelumnya.

Sebagai contoh, **menghapus kunci 55** dari pohon B+ tertentu dapat menyebabkan kondisi ini terjadi.

**Penjelasan Umum:**

- Saat penghapusan menyebabkan **node internal menjadi kosong**, dan tidak bisa lagi mempertahankan minimal jumlah key atau pointer,
    
- Maka **proses penggabungan (merge)** akan merambat ke atas (hingga akar jika perlu),
    
- Sehingga **tinggi pohon bisa berkurang satu tingkat**,
    
- Ini terjadi saat node internal tidak punya cukup key untuk dipinjamkan dan seluruh subtree harus disusun ulang.
    

Contoh ilustrasinya akan menunjukkan bagaimana sebuah node, beserta key dan pointer-nya, **digabungkan ke sibling** dan **pointer ke node tersebut dihapus dari parent**, hingga **akar baru terbentuk dari node di bawahnya**.

![[06 - Deletion from a B+ Tree-7.png]]

## Implementasi Kode

```cpp

// Deletion operation on a B+ Tree in C++

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define MIN_DEGREE 3  // Minimum degree (defines the range for number of keys)

class BPlusTreeNode {
public:
    bool leaf;
    std::vector<int> keys;
    std::vector<BPlusTreeNode*> children;
    BPlusTreeNode* parent;
    int numKeys;

    BPlusTreeNode(bool _leaf) : leaf(_leaf), numKeys(0), parent(nullptr) {}

    void insertNonFull(int key);
    void splitChild(int index, BPlusTreeNode* y);
    void remove(int key);
    void removeFromLeaf(int idx);
    void removeFromNonLeaf(int idx);
    int getPred(int idx);
    int getSucc(int idx);
    void borrowFromPrev(int idx);
    void borrowFromNext(int idx);
    void merge(int idx);

    friend class BPlusTree;
};

class BPlusTree {
    BPlusTreeNode* root;

public:
    BPlusTree() { root = new BPlusTreeNode(true); }

    void insert(int key);
    void remove(int key);
    void traverse() { traverse(root); }

private:
    void traverse(BPlusTreeNode* node);
    BPlusTreeNode* search(BPlusTreeNode* node, int key);
};

void BPlusTreeNode::insertNonFull(int key) {
    int i = numKeys - 1;

    if (leaf) {
        keys.push_back(0);  // Add a dummy value to expand the keys vector
        while (i >= 0 && key < keys[i]) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
        numKeys++;
    } else {
        while (i >= 0 && key < keys[i]) {
            i--;
        }
        i++;

        if (children[i]->numKeys == 2 * MIN_DEGREE - 1) {
            splitChild(i, children[i]);
            if (key > keys[i]) {
                i++;
            }
        }
        children[i]->insertNonFull(key);
    }
}

void BPlusTreeNode::splitChild(int index, BPlusTreeNode* y) {
    BPlusTreeNode* z = new BPlusTreeNode(y->leaf);
    z->numKeys = MIN_DEGREE - 1;

    for (int j = 0; j < MIN_DEGREE - 1; j++) {
        z->keys.push_back(y->keys[j + MIN_DEGREE]);
    }

    if (!y->leaf) {
        for (int j = 0; j < MIN_DEGREE; j++) {
            z->children.push_back(y->children[j + MIN_DEGREE]);
        }
    }

    y->numKeys = MIN_DEGREE - 1;

    children.insert(children.begin() + index + 1, z);
    keys.insert(keys.begin() + index, y->keys[MIN_DEGREE - 1]);
    numKeys++;
}

void BPlusTreeNode::remove(int key) {
    int idx = std::lower_bound(keys.begin(), keys.end(), key) - keys.begin();

    if (idx < numKeys && keys[idx] == key) {
        if (leaf) {
            removeFromLeaf(idx);
        } else {
            removeFromNonLeaf(idx);
        }
    } else {
        if (leaf) {
            std::cout << "The key " << key << " is not present in the tree.\n";
            return;
        }

        bool flag = ((idx == numKeys) ? true : false);

        if (children[idx]->numKeys < MIN_DEGREE) {
            borrowFromPrev(idx);
            children[idx]->remove(key);
        } else {
            children[idx]->remove(key);
        }
    }
}

void BPlusTreeNode::removeFromLeaf(int idx) {
    for (int i = idx + 1; i < numKeys; i++) {
        keys[i - 1] = keys[i];
    }
    keys.pop_back();
    numKeys--;
}

void BPlusTreeNode::removeFromNonLeaf(int idx) {
    int key = keys[idx];

    if (children[idx]->numKeys >= MIN_DEGREE) {
        int pred = getPred(idx);
        keys[idx] = pred;
        children[idx]->remove(pred);
    } else if (children[idx + 1]->numKeys >= MIN_DEGREE) {
        int succ = getSucc(idx);
        keys[idx] = succ;
        children[idx + 1]->remove(succ);
    } else {
        merge(idx);
        children[idx]->remove(key);
    }
}

int BPlusTreeNode::getPred(int idx) {
    BPlusTreeNode* cur = children[idx];
    while (!cur->leaf) {
        cur = cur->children[cur->numKeys];
    }
    return cur->keys[cur->numKeys - 1];
}

int BPlusTreeNode::getSucc(int idx) {
    BPlusTreeNode* cur = children[idx + 1];
    while (!cur->leaf) {
        cur = cur->children[0];
    }
    return cur->keys[0];
}

void BPlusTreeNode::borrowFromPrev(int idx) {
    BPlusTreeNode* child = children[idx];
    BPlusTreeNode* sibling = children[idx - 1];

    for (int i = child->numKeys - 1; i >= 0; i--) {
        child->keys[i + 1] = child->keys[i];
    }

    if (!child->leaf) {
        for (int i = child->numKeys; i >= 0; i--) {
            child->children[i + 1] = child->children[i];
        }
    }

    child->keys[0] = keys[idx - 1];

    if (!leaf) {
        child->children[0] = sibling->children[sibling->numKeys];
    }

    keys[idx - 1] = sibling->keys[sibling->numKeys - 1];

    child->numKeys += 1;
    sibling->numKeys -= 1;
}

void BPlusTreeNode::borrowFromNext(int idx) {
    BPlusTreeNode* child = children[idx];
    BPlusTreeNode* sibling = children[idx + 1];

    child->keys[child->numKeys] = keys[idx];

    if (!(child->leaf)) {
        child->children[child->numKeys + 1] = sibling->children[0];
    }

    keys[idx] = sibling->keys[0];

    for (int i = 1; i < sibling->numKeys; i++) {
        sibling->keys[i - 1] = sibling->keys[i];
    }

    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->numKeys; i++) {
            sibling->children[i - 1] = sibling->children[i];
        }
    }

    child->numKeys += 1;
    sibling->numKeys -= 1;
}

void BPlusTreeNode::merge(int idx) {
    BPlusTreeNode* child = children[idx];
    BPlusTreeNode* sibling = children[idx + 1];

    child->keys[MIN_DEGREE - 1] = keys[idx];

    for (int i = 0; i < sibling->numKeys; i++) {
        child->keys[i + MIN_DEGREE] = sibling->keys[i];
    }

    if (!child->leaf) {
        for (int i = 0; i <= sibling->numKeys; i++) {
            child->children[i + MIN_DEGREE] = sibling->children[i];
        }
    }

    for (int i = idx + 1; i < numKeys; i++) {
        keys[i - 1] = keys[i];
    }

    for (int i = idx + 2; i <= numKeys; i++) {
        children[i - 1] = children[i];
    }

    child->numKeys += sibling->numKeys + 1;
    numKeys--;
    delete sibling;
}

void BPlusTree::insert(int key) {
    BPlusTreeNode* r = root;
    if (r->numKeys == 2 * MIN_DEGREE - 1) {
        BPlusTreeNode* s = new BPlusTreeNode(false);
        root = s;
        s->children.push_back(r);
        s->splitChild(0, r);
        s->insertNonFull(key);
    } else {
        r->insertNonFull(key);
    }
}

void BPlusTree::remove(int key) {
    root->remove(key);
    if (root->numKeys == 0) {
        BPlusTreeNode* oldRoot = root;
        if (root->leaf) {
            root = nullptr;
        } else {
            root = root->children[0];
        }
        delete oldRoot;
    }
}

void BPlusTree::traverse(BPlusTreeNode* node) {
    if (node) {
        int i;
        for (i = 0; i < node->numKeys; i++) {
            if (!node->leaf) {
                traverse(node->children[i]);
            }
            std::cout << node->keys[i] << "";
        }
        if (!node->leaf) {
            traverse(node->children[i]);
        }
    }
}

int main() {
    BPlusTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(15);
    
    std::cout << "Tree after insertions: ";
    tree.traverse();
    std::cout << std::endl;
    
    tree.remove(10);
    std::cout << "Tree after deleting 10: ";
    tree.traverse();
    std::cout << std::endl;
    return 0;
}
```

Berikut penjelasan per blok kode untuk operasi **deletion** (dan juga insert/traverse) pada **B+ Tree** di C++:

---

### 1. Header dan Konstanta

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define MIN_DEGREE 3  // Minimum degree (defines the range for number of keys)
```

- **`<vector>`**: untuk menampung daftar kunci dan pointer anak.
    
- **`MIN_DEGREE`** = _m_: tiap node dapat menyimpan hingga `2*m-1` kunci dan memiliki hingga `2*m` anak.
    

---

### 2. Kelas `BPlusTreeNode`

```cpp
class BPlusTreeNode {
public:
    bool leaf;                       // apakah node ini leaf
    std::vector<int> keys;           // daftar kunci di node
    std::vector<BPlusTreeNode*> children; // pointer ke anak
    BPlusTreeNode* parent;           // pointer ke parent (tidak selalu dipakai)
    int numKeys;                     // jumlah kunci saat ini

    BPlusTreeNode(bool _leaf) : leaf(_leaf), numKeys(0), parent(nullptr) {}

    // operasi dasar:
    void insertNonFull(int key);
    void splitChild(int index, BPlusTreeNode* y);
    void remove(int key);
    void removeFromLeaf(int idx);
    void removeFromNonLeaf(int idx);
    int getPred(int idx);
    int getSucc(int idx);
    void borrowFromPrev(int idx);
    void borrowFromNext(int idx);
    void merge(int idx);

    friend class BPlusTree;
};
```

- Atribut dan konstruktor inisialisasi node baru (leaf atau internal).
    
- Daftar metode mencakup semua langkah penyisipan (insertNonFull, splitChild) dan penghapusan (remove, removeFromLeaf, dll).
    

---

### 3. Kelas `BPlusTree`

```cpp
class BPlusTree {
    BPlusTreeNode* root;

public:
    BPlusTree() { root = new BPlusTreeNode(true); }

    void insert(int key);
    void remove(int key);
    void traverse() { traverse(root); }

private:
    void traverse(BPlusTreeNode* node);
    BPlusTreeNode* search(BPlusTreeNode* node, int key);
};
```

- Menyimpan pointer `root`.
    
- Metode publik: `insert()`, `remove()`, `traverse()`.
    
- Metode privat: `traverse(node)` untuk cetak inorder, `search` (tidak terpakai di kode ini).
    

---

### 4. Penyisipan: `insertNonFull` dan `splitChild`

```cpp
void BPlusTreeNode::insertNonFull(int key) { … }
void BPlusTreeNode::splitChild(int index, BPlusTreeNode* y) { … }
```

- **`insertNonFull`**:
    
    - Jika node leaf, sisip kunci pada posisi yang tepat dan `numKeys++`.
        
    - Jika internal, temukan child yang sesuai, jika penuh panggil `splitChild`, lalu rekursif sisip.
        
- **`splitChild`**:
    
    - Pecah child `y` yang penuh menjadi dua node (`y` dan `z`), masing-masing menyimpan `m-1` kunci.
        
    - Promosikan kunci tengah ke node induk (`this`).
        

> _Penjelasan rinci ada di implementasi sebelumnya (bagian insertion)._

---

### 5. Penghapusan: `remove(int key)`

```cpp
void BPlusTreeNode::remove(int key) {
    int idx = std::lower_bound(keys.begin(), keys.end(), key) - keys.begin();

    if (idx < numKeys && keys[idx] == key) {
        if (leaf) removeFromLeaf(idx);
        else       removeFromNonLeaf(idx);
    } else {
        if (leaf) {
            std::cout << "The key " << key << " is not present in the tree.\n";
            return;
        }

        bool flag = (idx == numKeys);

        if (children[idx]->numKeys < MIN_DEGREE) {
            borrowFromPrev(idx);
            children[idx]->remove(key);
        } else {
            children[idx]->remove(key);
        }
    }
}
```

1. **Cari posisi** `idx` di mana `keys[idx] ≥ key`.
    
2. **Jika ditemukan** di node ini:
    
    - Jika leaf → `removeFromLeaf(idx)`.
        
    - Jika internal → `removeFromNonLeaf(idx)`.
        
3. **Jika tidak ditemukan** di node ini:
    
    - Jika leaf → laporkan “tidak ada”.
        
    - Tentukan child mana (`idx` atau `idx-1` jika flag) →
        
        - Jika child underflow (`numKeys < m`), **pinjam** dari sibling (`borrowFromPrev` atau `borrowFromNext`, implementasinya mirip dengan B-tree), lalu rekursif panggil `remove` di child.
            
        - Jika tidak underflow → rekursif `remove` di child.
            

---

### 6. Menghapus dari Leaf: `removeFromLeaf`

```cpp
void BPlusTreeNode::removeFromLeaf(int idx) {
    for (int i = idx + 1; i < numKeys; i++)
        keys[i - 1] = keys[i];
    keys.pop_back();
    numKeys--;
}
```

- Geser kunci setelah `idx` ke kiri, hapus terakhir, kurangi `numKeys`.
    

---

### 7. Menghapus dari Non-Leaf: `removeFromNonLeaf`

```cpp
void BPlusTreeNode::removeFromNonLeaf(int idx) {
    int key = keys[idx];
    if (children[idx]->numKeys >= MIN_DEGREE) {
        int pred = getPred(idx);
        keys[idx] = pred;
        children[idx]->remove(pred);
    } else if (children[idx+1]->numKeys >= MIN_DEGREE) {
        int succ = getSucc(idx);
        keys[idx] = succ;
        children[idx+1]->remove(succ);
    } else {
        merge(idx);
        children[idx]->remove(key);
    }
}
```

- Jika child kiri cukup besar, ganti kunci dengan **predecessor**, lalu hapus di subtree kiri.
    
- Jika child kanan cukup besar, ganti dengan **successor**, hapus di subtree kanan.
    
- Jika keduanya underflow, **merge** kedua child, lalu hapus di child hasil merge.
    

---

### 8. Predecessor & Successor

```cpp
int BPlusTreeNode::getPred(int idx) { … }
int BPlusTreeNode::getSucc(int idx) { … }
```

- **Predecessor**: turun ke child kiri, lalu terus ke paling kanan leaf.
    
- **Successor**: turun ke child kanan, terus ke paling kiri leaf.
    

---

### 9. Borrowing & Merging

```cpp
void BPlusTreeNode::borrowFromPrev(int idx) { … }
void BPlusTreeNode::borrowFromNext(int idx) { … }
void BPlusTreeNode::merge(int idx) { … }
```

- **`borrowFromPrev(idx)`** / **`borrowFromNext(idx)`**:
    
    - Pindahkan satu kunci dari sibling ke child, update separator di parent.
        
- **`merge(idx)`**:
    
    - Gabungkan child `idx` dan `idx+1`, naikkan satu key parent ke tengah, hapus sibling.
        

---

### 10. Interface `BPlusTree::insert` & `remove`

```cpp
void BPlusTree::insert(int key) { … }
void BPlusTree::remove(int key) {
    root->remove(key);
    if (root->numKeys == 0) {
        BPlusTreeNode* oldRoot = root;
        root = root->leaf ? nullptr : root->children[0];
        delete oldRoot;
    }
}
```

- `insert`: jika root penuh split dahulu, lalu sisip.
    
- `remove`: panggil `root->remove`, jika root jadi kosong ganti root ke `children[0]` atau `nullptr`.
    

---

### 11. Traversal

```cpp
void BPlusTree::traverse(BPlusTreeNode* node) {
    if (node) {
        int i;
        for (i = 0; i < node->numKeys; i++) {
            if (!node->leaf) traverse(node->children[i]);
            std::cout << node->keys[i] << " ";
        }
        if (!node->leaf) traverse(node->children[i]);
    }
}
```

- **In-order traversal**:
    
    - Rekursif ke `children[i]`, cetak `keys[i]`, dan terakhir `children[numKeys]`.
        

---

### 12. `main()`

```cpp
int main() {
    BPlusTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(15);

    std::cout << "Tree after insertions: ";
    tree.traverse();
    std::cout << std::endl;

    tree.remove(10);
    std::cout << "Tree after deleting 10: ";
    tree.traverse();
    std::cout << std::endl;
    return 0;
}
```

- Contoh: sisip beberapa kunci → tampilkan tree → hapus `10` → tampilkan lagi.
    
