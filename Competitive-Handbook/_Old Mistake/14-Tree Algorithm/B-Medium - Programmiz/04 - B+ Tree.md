---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 14TH-TREE-00B4
nama_algoritma: 
kategori_algoritma: tree algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: programiz.com & chatgpt.com
date_learned: 2025-06-25T11:36:00
tags:
  - tree-algorithm
---
Link sumber: [B+ Tree](https://www.programiz.com/dsa/b-plus-tree)

---
# B+ Tree

B+ tree adalah bentuk lanjutan dari pohon penyeimbang-diri (self-balancing tree) di mana semua nilai berada pada level daun.

Satu konsep penting yang harus dipahami sebelum mempelajari B+ tree adalah **pengindeksan bertingkat (multilevel indexing)**. Dalam pengindeksan bertingkat, indeks dari indeks dibuat seperti pada gambar di bawah. Ini membuat pengaksesan data menjadi lebih mudah dan cepat.

![[04 - B+ Tree-1.png]]

## Properti-properti dari B+ Tree  
- Semua *leaf* berada pada level yang sama.
    
- **Root* memiliki setidaknya dua *child*.
    
- Setiap *node* kecuali *root* dapat memiliki maksimum $m$ *children* dan minimum $m/2$ *children*.
    
- Setiap *node* dapat mengandung maksimum $m - 1$ *keys* dan minimum $⌈m/2⌉ - 1$ *keys*.

## Perbandingan antara B-tree dan B+ Tree

![[04 - B+ Tree-2.png]]

![[04 - B+ Tree-3.png]]


**Pointer data** hanya terdapat pada **leaf nodes** di B+ tree, sedangkan **pointer data** terdapat pada **internal**, **leaf**, atau **root nodes** di B-tree.

**Leaves** tidak saling terhubung pada B-tree, sedangkan pada B+ tree, **leaves** saling terhubung satu sama lain.

Operasi-operasi pada B+ tree lebih cepat dibandingkan dengan pada B-tree.

---

## Pencarian pada B+ Tree  
Langkah-langkah berikut dilakukan untuk mencari data pada sebuah **B+ Tree** dengan **orde $m$**. Misalkan data yang akan dicari adalah $k$.

1. Mulai dari **root node**. Bandingkan $k$ dengan **keys** pada **root node** $[k₁, k₂, k₃,......kₘ₋₁]$.
    
2. Jika *$k < k₁$*, pergi ke **left child** dari **root node**.
    
3. Else if $k == k₁$, bandingkan dengan $k₂$. Jika $k < k₂$, maka $k$ berada di antara $k₁$ dan $k₂$. Maka, lakukan pencarian pada left child dari $k₂$.
    
4. Jika $k > k₂$, lanjutkan ke $k₃, k₄, ..., kₘ₋₁$ sesuai dengan langkah 2 dan 3.
    
5. Ulangi langkah-langkah di atas hingga mencapai sebuah **leaf node**.
    
6. Jika $k$ ada pada **leaf node**, kembalikan _true_, else kembalikan _false_.

## Contoh Pencarian pada B+ Tree  
Mari kita cari _k = 45_ pada **B+ Tree** berikut.

![[04 - B+ Tree-4.png]]

1. Bandingkan _k_ dengan **root node**.
   
   ![[04 - B+ Tree-5.png]]
2. Karena _k > 25_, pergi ke **right child**.
   
   ![[04 - B+ Tree-6.png]]
3. Bandingkan _k_ dengan 35. Karena _k > 30_, bandingkan _k_ dengan 45.
   
   ![[04 - B+ Tree-7.png]]
4. Karena _k ≥ 45_, maka pergi ke **right child**.
   
   ![[04 - B+ Tree-8.png]]
5. *k* ditemukan
   
   ![[04 - B+ Tree-9.png]]
---

## Implementasi kode

```cpp
// Searching on a B+ tree in C++

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

// node creation
class Node {
public:
    int order;
    vector<string> values;
    vector<Node*> children; // for internal nodes
    vector<vector<string>> keys; // for leaf nodes
    Node* nextKey;
    Node* parent;
    bool check_leaf;
    Node(int order) {
        this->order = order;
        this->nextKey = nullptr;
        this->parent = nullptr;
        this->check_leaf = false;
    }
    
    // insert at the leaf
    void insert_at_leaf(Node* leaf, string value, string key) {
        if (!values.empty()) {
            for (int i = 0; i < values.size(); i++) {
                if (value == values[i]) {
                    keys[i].push_back(key);
                    break;
                }
                else if (value < values[i]) {
                    values.insert(values.begin() + i, value);
                    keys.insert(keys.begin() + i, vector<string>{key});
                    break;
                }
                else if (i + 1 == values.size()) {
                    values.push_back(value);
                    keys.push_back(vector<string>{key});
                    break;
                }
            }
        }
        else {
            values.push_back(value);
            keys.push_back(vector<string>{key});
        }
    }
};

// B+ tree
class BplusTree {
public:
    Node* root;
    BplusTree(int order) {
        root = new Node(order);
        root->check_leaf = true;
    }
    
    // insert operation
    void insert(string value, string key) {
        Node* old_node = search(value);
        old_node->insert_at_leaf(old_node, value, key);
        if (old_node->values.size() == old_node->order) {
            Node* node1 = new Node(old_node->order);
            node1->check_leaf = true;
            node1->parent = old_node->parent;
            int mid = ceil(old_node->order / 2.0) - 1;
            node1->values.assign(old_node->values.begin() + mid + 1, old_node->values.end());
            node1->keys.assign(old_node->keys.begin() + mid + 1, old_node->keys.end());
            node1->nextKey = old_node->nextKey;
            old_node->values.resize(mid + 1);
            old_node->keys.resize(mid + 1);
            old_node->nextKey = node1;
            insert_in_parent(old_node, node1->values[0], node1);
        }
    }
    
    // search operation for different operations
    Node* search(string value) {
        Node* current_node = root;
        while (!current_node->check_leaf) {
            for (int i = 0; i < current_node->values.size(); i++) {
                if (value == current_node->values[i]) {
                    current_node = current_node->children[i + 1];
                    break;
                }
                else if (value < current_node->values[i]) {
                    current_node = current_node->children[i];
                    break;
                }
                else if (i + 1 == current_node->values.size()) {
                    current_node = current_node->children[i + 1];
                    break;
                }
            }
        }
        return current_node;
    }
    
    // find the node
    bool find(string value, string key) {
        Node* l = search(value);
        for (int i = 0; i < l->values.size(); i++) {
            if (l->values[i] == value) {
                for (int j = 0; j < l->keys[i].size(); j++) {
                    if (l->keys[i][j] == key) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    // inserting at the parent
    void insert_in_parent(Node* n, string value, Node* ndash) {
        if (root == n) {
            Node* rootNode = new Node(n->order);
            rootNode->values.push_back(value);
            rootNode->children.push_back(n);
            rootNode->children.push_back(ndash);
            root = rootNode;
            n->parent = rootNode;
            ndash->parent = rootNode;
            return;
        }
        Node* parentNode = n->parent;
        for (int i = 0; i < parentNode->children.size(); i++) {
            if (parentNode->children[i] == n) {
                parentNode->values.insert(parentNode->values.begin() + i, value);
                parentNode->children.insert(parentNode->children.begin() + i + 1, ndash);
                if (parentNode->children.size() > parentNode->order) {
                    Node* parentdash = new Node(parentNode->order);
                    parentdash->parent = parentNode->parent;
                    int mid = ceil(parentNode->order / 2.0) - 1;
                    parentdash->values.assign(parentNode->values.begin() + mid + 1, parentNode->values.end());
                    parentdash->children.assign(parentNode->children.begin() + mid + 1, parentNode->children.end());
                    string value_ = parentNode->values[mid];
                    parentNode->values.resize(mid);
                    parentNode->children.resize(mid + 1);
                    insert_in_parent(parentNode, value_, parentdash);
                }
                break;
            }
        }
    }
    
    // display the tree
    void printTree(Node* node) {
        if (node == nullptr) return;
        for (int i = 0; i < node->values.size(); i++) {
            cout << node->values[i] << " ";
        }
        cout << endl;
        if (!node->check_leaf) {
            for (int i = 0; i <= node->values.size(); i++) {
                printTree(node->children[i]);
            }
        }
    }
};

int main() {
    int record_len = 3;
    BplusTree bplustree(record_len);
    bplustree.insert("5", "33");
    bplustree.insert("15", "21");
    bplustree.insert("25", "31");
    bplustree.insert("35", "41");
    bplustree.insert("45", "10");
    bplustree.printTree(bplustree.root);
    if (bplustree.find("5", "34")) {
        cout << "Found" << endl;
    } else {
        cout << "Not found" << endl;
    }
    return 0;
}
```

Berikut penjelasan per blok kode untuk implementasi **Searching dan Insertion** pada **B+ Tree** di C++:

---

### 1. Header dan `using namespace`

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
```

- **`<iostream>`**: untuk operasi I/O (`cout`).
    
- **`<vector>`**: menampung daftar `values`, `children`, dan `keys`.
    
- **`<cmath>`**: untuk fungsi `ceil` saat split node.
    
- **`<string>`**: tipe data `string` digunakan untuk `value` dan `key`.
    
- `using namespace std;` menghindarkan prefix `std::`.
    

---

### 2. Kelas `Node`

```cpp
class Node {
public:
    int order;
    vector<string> values;          // keys (separator values) pada internal & leaf
    vector<Node*> children;         // pointer ke child (hanya untuk internal)
    vector<vector<string>> keys;    // kumpulan data pointers pada leaf
    Node* nextKey;                  // pointer ke leaf berikutnya (linked list)
    Node* parent;                   // pointer ke parent (untuk split)
    bool check_leaf;                // menandai apakah node leaf
    Node(int order) { … }
    void insert_at_leaf(Node* leaf, string value, string key) { … }
};
```

- **`order`**: kapasitas maksimum (`m`) jumlah `values` (internal) atau ukuran leaf sebelum split.
    
- **`values`**: di internal berisi separator, di leaf menyimpan nilai input.
    
- **`children`**: hanya dipakai di node internal untuk turun ke subtree.
    
- **`keys`**: di leaf, setiap `values[i]` memiliki daftar `keys[i]` (data pointers).
    
- **`nextKey`**: menghubungkan leaf satu ke leaf berikutnya untuk range scan.
    
- **`parent`**: referensi ke parent node, memudahkan rekursi saat split.
    
- **`check_leaf`**: `true` jika node adalah leaf.
    
- **Konstruktor** menginisialisasi atribut dan menandai node sebagai non-leaf secara default.
    

#### 2.1 `insert_at_leaf`

```cpp
void insert_at_leaf(Node* leaf, string value, string key) {
    if (!values.empty()) {
        // temukan posisi yang tepat untuk `value`
        for (int i = 0; i < values.size(); i++) {
            if (value == values[i]) {
                keys[i].push_back(key);  // jika sudah ada, tambahkan data pointer
                break;
            }
            else if (value < values[i]) {
                values.insert(values.begin()+i, value);
                keys.insert(keys.begin()+i, vector<string>{key});
                break;
            }
            else if (i+1 == values.size()) {
                values.push_back(value);
                keys.push_back(vector<string>{key});
                break;
            }
        }
    } else {
        // leaf masih kosong
        values.push_back(value);
        keys.push_back(vector<string>{key});
    }
}
```

- Menyisipkan pasangan `(value, key)` ke leaf:
    
    - Jika `value` sudah ada, tambahkan `key` ke list di posisi tersebut.
        
    - Jika `value` lebih kecil, sisip sebelum posisi itu.
        
    - Jika terbesar, tambahkan di akhir.
        
- Memastikan `values` dan `keys` selalu sejalan.
    

---

### 3. Kelas `BplusTree`

```cpp
class BplusTree {
public:
    Node* root;
    BplusTree(int order) { … }
    void insert(string value, string key) { … }
    Node* search(string value) { … }
    bool find(string value, string key) { … }
    void insert_in_parent(Node* n, string value, Node* ndash) { … }
    void printTree(Node* node) { … }
};
```

- **`root`**: pointer ke node akar.
    
- Metode utama:
    
    1. **`insert`**: menyisipkan data ke tree.
        
    2. **`search`**: menuruni tree hingga leaf yang sesuai.
        
    3. **`find`**: memeriksa keberadaan `(value, key)` di leaf.
        
    4. **`insert_in_parent`**: menangani split dan promosi separator ke parent.
        
    5. **`printTree`**: menampilkan isi tree secara preorder per level.
        

#### 3.1 Konstruktor

```cpp
BplusTree(int order) {
    root = new Node(order);
    root->check_leaf = true;
}
```

- Membuat satu node leaf kosong sebagai root awal.
    

#### 3.2 Metode `insert`

```cpp
void insert(string value, string key) {
    Node* old_node = search(value);
    old_node->insert_at_leaf(old_node, value, key);
    // jika leaf penuh, split
    if (old_node->values.size() == old_node->order) {
        Node* node1 = new Node(old_node->order);
        node1->check_leaf = true;
        node1->parent = old_node->parent;
        int mid = ceil(old_node->order / 2.0) - 1;
        // pindahkan half nilai ke node1
        node1->values.assign(old_node->values.begin()+mid+1, old_node->values.end());
        node1->keys.assign(old_node->keys.begin()+mid+1, old_node->keys.end());
        node1->nextKey = old_node->nextKey;
        old_node->values.resize(mid+1);
        old_node->keys.resize(mid+1);
        old_node->nextKey = node1;
        // promosi separator ke parent
        insert_in_parent(old_node, node1->values[0], node1);
    }
}
```

- **Langkah**:
    
    1. Cari leaf target via `search`.
        
    2. Sisip `(value, key)` di leaf.
        
    3. Jika overflow (`size == order`), **split** leaf:
        
        - Buat `node1`, pindahkan separuh `values` & `keys`.
            
        - Sambungkan `nextKey` tetap berantai.
            
        - Promosikan separator pertama dari `node1` ke parent via `insert_in_parent`.
            

#### 3.3 Metode `search`

```cpp
Node* search(string value) {
    Node* current_node = root;
    while (!current_node->check_leaf) {
        for (int i = 0; i < current_node->values.size(); i++) {
            if (value == current_node->values[i]) {
                current_node = current_node->children[i+1];
                break;
            }
            else if (value < current_node->values[i]) {
                current_node = current_node->children[i];
                break;
            }
            else if (i+1 == current_node->values.size()) {
                current_node = current_node->children[i+1];
                break;
            }
        }
    }
    return current_node;
}
```

- Menuruni dari root:
    
    - Bandingkan `value` dengan setiap separator di `values`.
        
    - Jika cocok atau lebih kecil, pilih child yang sesuai.
        
    - Terus hingga mencapai leaf, lalu kembalikan leaf tersebut.
        

#### 3.4 Metode `find`

```cpp
bool find(string value, string key) {
    Node* l = search(value);
    for (int i = 0; i < l->values.size(); i++) {
        if (l->values[i] == value) {
            for (int j = 0; j < l->keys[i].size(); j++) {
                if (l->keys[i][j] == key) {
                    return true;
                }
            }
        }
    }
    return false;
}
```

- Memeriksa di leaf `l` hasil `search(value)`:
    
    - Cari index `i` di mana `values[i] == value`.
        
    - Telusuri daftar `keys[i]` untuk mencocokkan `key`.
        

#### 3.5 Metode `insert_in_parent`

```cpp
void insert_in_parent(Node* n, string value, Node* ndash) {
    if (root == n) {
        // root overflow → bikin root baru
        Node* rootNode = new Node(n->order);
        rootNode->values.push_back(value);
        rootNode->children.push_back(n);
        rootNode->children.push_back(ndash);
        root = rootNode;
        n->parent = rootNode;
        ndash->parent = rootNode;
        return;
    }
    Node* parentNode = n->parent;
    // sisip separator & child ke parent
    for (int i = 0; i < parentNode->children.size(); i++) {
        if (parentNode->children[i] == n) {
            parentNode->values.insert(parentNode->values.begin()+i, value);
            parentNode->children.insert(parentNode->children.begin()+i+1, ndash);
            // jika parent overflow → split internal node
            if (parentNode->children.size() > parentNode->order) {
                Node* parentdash = new Node(parentNode->order);
                parentdash->parent = parentNode->parent;
                int mid = ceil(parentNode->order / 2.0) - 1;
                parentdash->values.assign(parentNode->values.begin()+mid+1, parentNode->values.end());
                parentdash->children.assign(parentNode->children.begin()+mid+1, parentNode->children.end());
                string value_ = parentNode->values[mid];
                parentNode->values.resize(mid);
                parentNode->children.resize(mid+1);
                // promosi separator lagi ke atas
                insert_in_parent(parentNode, value_, parentdash);
            }
            break;
        }
    }
}
```

- Jika leaf yang di-split adalah **root**, buat root baru dengan dua child.
    
- Jika bukan root, sisip `value` dan `ndash` di posisi setelah `n`.
    
- Jika overflow, split internal node sama seperti leaf dan terus promosikan separator.
    

#### 3.6 Metode `printTree`

```cpp
void printTree(Node* node) {
    if (node == nullptr) return;
    for (int i = 0; i < node->values.size(); i++)
        cout << node->values[i] << " ";
    cout << endl;
    if (!node->check_leaf) {
        for (int i = 0; i <= node->values.size(); i++)
            printTree(node->children[i]);
    }
}
```

- Menampilkan setiap node:
    
    - Cetak semua `values` di node (internal maupun leaf).
        
    - Jika internal, rekursif ke setiap child.
        

---

### 4. Fungsi `main()`

```cpp
int main() {
    int record_len = 3;
    BplusTree bplustree(record_len);

    // Penyisipan beberapa pasangan (value, key)
    bplustree.insert("5", "33");
    bplustree.insert("15", "21");
    bplustree.insert("25", "31");
    bplustree.insert("35", "41");
    bplustree.insert("45", "10");

    bplustree.printTree(bplustree.root);

    // Pencarian dan pengecekan keberadaan data
    if (bplustree.find("5", "34"))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;

    return 0;
}
```

- **Inisialisasi** B+ tree dengan `order = 3`.
    
- **Insert** lima entri `(value, key)`.
    
- **Print** struktur tree.
    
- **Find** pasangan `("5","34")` dan cetak hasilnya.
    
## 🔍 Search Complexity (Kompleksitas Pencarian)

### ⏱️ _Time Complexity_ (Kompleksitas Waktu):

- Jika **linear search** digunakan **di dalam node**, maka total kompleksitas waktu adalah:
    
    $$\Theta(\log_t n)$$
    
     Artinya, karena tinggi pohon adalah $\log_t n$ dan setiap node dicari secara linear (dengan maksimal $t-1$ elemen), maka kompleksitas totalnya proporsional dengan tinggi pohon.
    
- Jika **binary search** digunakan di dalam node, maka kompleksitasnya menjadi:
    
    $$\Theta(\log_2 t \cdot \log_t n)$$
    
    Ini karena:
    
    - Untuk setiap level, pencarian kunci di dalam node butuh $\log_2 t$ waktu.
        
    - Ada total $\log_t n$ level dari root ke leaf.
        
    - Maka total waktu adalah perkalian keduanya.
        

---

### 💡 B+ Tree Applications (Aplikasi Pohon B+)

1. **Multilevel Indexing (Pengindeksan Multilevel)**
    
    - B+ Tree sering digunakan untuk menyusun indeks bertingkat (seperti dalam sistem file dan database).
        
    - Daun B+ Tree menyimpan pointer ke data aktual, sedangkan node internal menyimpan pointer ke indeks yang lebih spesifik.
        
2. **Faster Operations (Operasi yang Lebih Cepat)**
    
    - Operasi seperti pencarian, penyisipan, dan penghapusan jauh lebih efisien dibanding struktur seperti array atau linked list ketika data dalam jumlah besar.
        
    - Ini karena semua data terstruktur dalam bentuk pohon yang seimbang.
        
3. **Database Indexing (Pengindeksan Basis Data)**
    
    - B+ Tree merupakan struktur utama yang digunakan untuk **indexing pada sistem database** seperti MySQL, Oracle, dan lainnya.
        
    - Karena semua nilai data berada di level daun dan terhubung satu sama lain, **range query** (misalnya `BETWEEN`, `>=`, `<=`) menjadi sangat efisien.
        
