---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Struct Node Member Function
sumber: Google.com, AI
date_learned: 2025-06-28T15:31:00
tags:
  - tree-algorithm
---
Link Sumber: 

---
# 1 | Struct Node Member Function
Berikut daftar member‑function yang **bisa** kamu tambahkan ke `Node` agar strukturnya lebih kaya fitur, terbagi menurut kategori. Tambahkan sesuai kebutuhanmu—semakin banyak, semakin fleksibel!

---

## 1. Manajemen Memori

- **Destructor**  
    Bebaskan subtree otomatis ketika `Node` di-`delete`.
    
    ```cpp
    ~Node(){
        delete left;
        delete right;
    }
    ```
    
- **Copy Constructor & Assignment Operator**  
    Untuk deep–copy seluruh subtree (Rule of Three/Five).
    
    ```cpp
    Node(const Node& other);
    Node& operator=(const Node& other);
    ```
    

---

## 2. Inisialisasi & Modifikasi

- **setLeft / setRight versi pointer**  
    Agar bisa attach subtree yang sudah ada.
    
    ```cpp
    Node* setLeft(Node* subtree);
    Node* setRight(Node* subtree);
    ```
    
- **insertBST**  
    Masukkan `value` dengan aturan Binary Search Tree.
    
    ```cpp
    void insertBST(int value);
    ```
    
- **removeBST**  
    Hapus node bernilai `value` dari BST, return root baru.
    
    ```cpp
    Node* removeBST(int value);
    ```
    

---

## 3. Traversal (Utility)

- **inorder**, **preorder**, **postorder**  
    Cetak data atau callback untuk setiap node.
    
    ```cpp
    void inorder  (std::function<void(int)> visit);
    void preorder (std::function<void(int)> visit);
    void postorder(std::function<void(int)> visit);
    ```
    
- **levelOrder**  
    Traversal per level, pakai queue.
    
    ```cpp
    void levelOrder(std::function<void(int)> visit);
    ```
    

---

## 4. Query & Statistik

- **countNodes**  
    Hitung jumlah node di subtree.
    
    ```cpp
    int countNodes() const;
    ```
    
- **height**  
    Hitung tinggi (height) subtree.
    
    ```cpp
    int height() const;
    ```
    
- **sumValues**  
    Jumlahkan seluruh nilai `data`.
    
    ```cpp
    long long sumValues() const;
    ```
    

---

## 5. Pencarian & Validasi

- **search**  
    Cari apakah `value` ada di subtree (linier atau BST).
    
    ```cpp
    bool search(int value) const;
    ```
    
- **findMin / findMax**  
    Cari nilai terkecil/terbesar di subtree (BST).
    
    ```cpp
    Node* findMin();
    Node* findMax();
    ```
    
- **isBST**  
    Cek apakah subtree mematuhi aturan BST.
    
    ```cpp
    bool isBST(int min = INT_MIN, int max = INT_MAX) const;
    ```
    
- **isBalanced**  
    Cek apakah tree height‑balanced (selisih height ≤ 1).
    
    ```cpp
    bool isBalanced() const;
    ```
    

---

## 6. Transformasi & Utility Lain

- **mirror**  
    Tukar left/right di semua node (mirror image).
    
    ```cpp
    void mirror();
    ```
    
- **clone**  
    Deep–copy subtree, return `Node*` baru.
    
    ```cpp
    Node* clone() const;
    ```
    
- **serialize / deserialize**  
    Ubah tree ke string (preorder dengan null‑marker) dan sebaliknya.
    
    ```cpp
    std::string serialize() const;
    static Node* deserialize(const std::string& data);
    ```
    
- **pathTo**  
    Kembalikan vector path (nilai) dari root ke node `value`, kalau ada.
    
    ```cpp
    std::vector<int> pathTo(int value) const;
    ```
    
- **LCA (Lowest Common Ancestor)**  
    Cari ancestor terendah dari dua nilai.
    
    ```cpp
    Node* lowestCommonAncestor(int a, int b);
    ```
    

---

## 7. Debug & Visualization

- **printTree**  
    Cetak visual tree (sideways) untuk debugging.
    
    ```cpp
    void printTree(int indent = 0) const;
    ```
    
- **toGraphviz**  
    Generate string Graphviz `.dot` untuk digambar di tools eksternal.
    
    ```cpp
    std::string toGraphviz() const;
    ```
    

## 5. Lowerbound dan Upperbound

Mirip konsep di `std::set`:

- **lowerbound**
  `lowerBound`: node pertama dengan `data >= key`

	```cpp
	Node* lowerBound(int value);
	```

- **upperbound**
  `upperBound`: node pertama dengan `data > key`

	```cpp
	Node* upperBound(int value);
	```

Tidak wajib, tapi berguna dalam aplikasi seperti range queries.

---

### Contoh Skeleton Implementasi

```cpp
struct Node {
    int data;
    Node *left, *right;

    explicit Node(int data) : data(data), left(nullptr), right(nullptr) {}
    ~Node(){ delete left; delete right; }

    // Inisialisasi & Modifikasi
    Node* setLeft(Node* subtree){ left = subtree; return left; }
    Node* setRight(Node* subtree){ right = subtree; return right; }
    void insertBST(int value);
    Node* removeBST(int value);

    // Traversal
    void inorder(std::function<void(int)> f) const;
    void preorder(std::function<void(int)> f) const;
    void postorder(std::function<void(int)> f) const;
    void levelOrder(std::function<void(int)> f) const;

    // Query
    int countNodes() const;
    int height() const;
    bool search(int value) const;
    Node* findMin();
    Node* findMax();
    bool isBST(int min, int max) const;
    bool isBalanced() const;
	Node* lowerBound(int value);
	Node* upperBound(int value);

    // Transformasi
    void mirror();
    Node* clone() const;

    // Serialisasi
    std::string serialize() const;
    static Node* deserialize(const std::string&);

    // Debug
    void printTree(int indent = 0) const;
    std::string toGraphviz() const;
};
```

---

Dengan koleksi fungsi di atas, `Node`-mu akan siap untuk hampir semua operasi dasar hingga lanjutan pada binary tree/BST. Kamu tinggal pilih dan implement sesuai skenario penggunaan!

# 2 | Modular Struct Node Member Function
Berikut beberapa **member function** yang sering berguna untuk `Node` agar struktur pohonmu lebih fleksibel, masing‑masing ditulis terpisah supaya kamu bisa pakai yang perlu saja.

---

## 1. `isLeaf()`

Cek apakah node itu daun (tidak punya anak).

```cpp
bool isLeaf() const {
    return left == nullptr && right == nullptr;
}
```

---

## 2. `countNodes()`

Menghitung total node dalam subtree ini.

```cpp
int countNodes() const {
    int cnt = 1;
    if (left)  cnt += left->countNodes();
    if (right) cnt += right->countNodes();
    return cnt;
}
```

---

## 3. `height()`

Menghitung tinggi (height) subtree—jumlah level dari node ini ke daun terdalam.

```cpp
int height() const {
    int hl = left  ? left->height()  : 0;
    int hr = right ? right->height() : 0;
    return 1 + std::max(hl, hr);
}
```

---

## 4. `search(int key)`

Mencari apakah ada nilai `key` di dalam subtree.

```cpp
bool search(int key) const {
    if (data == key) return true;
    if (left && left->search(key))   return true;
    if (right && right->search(key)) return true;
    return false;
}
```

---

## 5. `inorder()` / `preorder()` / `postorder()`

Traversal dasar—kamu bisa pilih salah satu atau semua.

```cpp
void inorder() const {
    if (left)  left->inorder();
    std::cout << data << " ";
    if (right) right->inorder();
}

void preorder() const {
    std::cout << data << " ";
    if (left)  left->preorder();
    if (right) right->preorder();
}

void postorder() const {
    if (left)  left->postorder();
    if (right) right->postorder();
    std::cout << data << " ";
}
```

---

## 6. `minValue()` / `maxValue()`

Cari nilai minimum/maksimum di subtree—berguna untuk BST.

```cpp
int minValue() const {
    const Node* cur = this;
    while (cur->left) cur = cur->left;
    return cur->data;
}

int maxValue() const {
    const Node* cur = this;
    while (cur->right) cur = cur->right;
    return cur->data;
}
```

---

## 7. `clone()`

Menduplikasi seluruh subtree (deep copy).

```cpp
Node* clone() const {
    Node* copy = new Node(data);
    if (left)  copy->left  = left->clone();
    if (right) copy->right = right->clone();
    return copy;
}
```

---

## 8. `mirror()`

Membalik anak kiri/kanan secara rekursif (menjadikan mirror tree).

```cpp
void mirror() {
    std::swap(left, right);
    if (left)  left->mirror();
    if (right) right->mirror();
}
```

---

## 9. `depth(int key, int level = 1)`

Cari kedalaman (depth) node yang punya nilai `key`, atau –1 jika tidak ada.

```cpp
int depth(int key, int level = 1) const {
    if (data == key) return level;
    int d = -1;
    if (left)  d = left->depth(key, level + 1);
    if (d != -1) return d;
    if (right) d = right->depth(key, level + 1);
    return d;
}
```

---

## 10. `isBalanced()`

Cek apakah subtree ini height‑balanced (selisih tinggi anak kiri/kanan ≤ 1).

```cpp
bool isBalanced(int* heightPtr = nullptr) const {
    int lh = 0, rh = 0;
    bool leftBal  = !left  || left->isBalanced(&lh);
    bool rightBal = !right || right->isBalanced(&rh);
    if (heightPtr) *heightPtr = 1 + std::max(lh, rh);
    return leftBal && rightBal && std::abs(lh - rh) <= 1;
}
```

---

Kamu tinggal copy‑paste tiap fungsi yang kamu perlukan ke dalam `struct Node`. Semoga membantu menambah fleksibilitas dan kemampuan pohonmu!

# 3 | Chaining Node

> Apakah bisa menginisialisasi Tree tanpa perlu menuliskan `new Node(val)`?

Kamu sebenarnya bisa tetap “langsung angka” saja—tanpa harus manual `new Node(...)` di luar—dengan menyediakan **dua** overload untuk `setChild` (dan `setLeft`/`setRight`): satu yang menerima `int` dan sekaligus membuat node baru, satu lagi yang menerima `Node*`. Contohnya:

```cpp
struct Node {
    int data;
    Node *left, *right;

    explicit Node(int data)
      : data(data), left(nullptr), right(nullptr) {}

    // —————— Untuk langsung nilai int ——————
    Node* setLeft(int val) {
        // bila mau bebas memory-leak, bisa delete left di sini
        left = new Node(val);
        return left;
    }
    Node* setRight(int val) {
	    // bila mau bebas memory-leak, bisa delete right di sini
        right = new Node(val);
        return right;
    }
    Node* setChild(int a, int b) {
        setLeft(a);
        setRight(b);
        return this;
    }

    // —————— Untuk pasang Node* yang sudah ada ——————
    Node* setLeft(Node* node) {
        left = node;
        return left;
    }
    Node* setRight(Node* node) {
        right = node;
        return right;
    }
    Node* setChild(Node* l, Node* r) {
        left  = l;
        right = r;
        return this;
    }
};
```

### Cara pakai:

```cpp
int main() {
    // 1) buat root
    Node* root = new Node(10);

    // 2) langsung pasang anak dengan nilai int
    //    (di dalamnya otomatis new Node(5) dan new Node(20))
    root->setChild(5, 20)

        // 3) chaining: sekarang root->left adalah Node(5),
        //    kita bisa langsung set anaknya dengan angka juga
        ->left->setChild(3, 8);

    // Jadi kamu tidak perlu menulis `new Node(...)` lagi untuk tiap anak.
}
```

Dengan overload ini:

- Kalau kamu panggil `setChild(5,20)` → si method yang terima `int,int` yang jalan, otomatis `new Node(5)` & `new Node(20)`.
    
- Kalau kamu sudah punya `Node*` dan mau pasang ulang → tinggal panggil `setChild(ptrL, ptrR)`.
    

Sehingga kamu bisa tulis one‑liner `root->setChild(5,20)->left->setChild(3,8);` tanpa repot `new` tiap kali.