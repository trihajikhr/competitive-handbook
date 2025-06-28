---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: 20 Variasi Struct Node
sumber: Google.com, AI
date_learned: 2025-06-27T11:28:00
tags:
  - tree-algorithm
---
Link Sumber: 

---
# Variasi Awal

Bagus sekali pertanyaannya! Kamu sedang menyusun _best practice_ dari berbagai cara membuat `struct Node` dalam pohon biner—dan itu sangat berguna untuk mengerti evolusi sintaks C++ dari gaya klasik ke gaya modern.

Berikut ini aku rangkum **berbagai versi membuat `struct Node`**, dari gaya lama sampai modern, lengkap dengan penjelasan setiap gaya:

---

## 🧱 1. Versi Klasik / Tradisional

```cpp
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
```

**Keterangan:**

- Tidak ada konstruktor.
    
- Setelah `Node` dibuat, nilainya diisi secara manual.
    
- Ini umum digunakan pada C dan awal C++.
    

Contoh penggunaan:

```cpp
Node* node = new Node;
node->data = 10;
node->left = NULL;
node->right = NULL;
```

---

## ⚒️ 2. Versi dengan Constructor Biasa

```cpp
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
```

**Keterangan:**

- Ada konstruktor untuk inisialisasi langsung saat pembuatan objek.
    
- Sangat populer dalam pengajaran karena eksplisit dan jelas.
    

Contoh penggunaan:

```cpp
Node* root = new Node(10);
```

---

## 🧪 3. Versi Tanpa Kata `struct` dalam Atribut

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
```

**Keterangan:**

- Lebih ringkas, dan umum dipakai dalam C++ modern.
    
- `struct Node*` diganti dengan `Node*` karena C++ mendukung ini tanpa deklarasi eksplisit `struct` lagi.
    

---

## 🚀 4. Versi dengan Constructor Initialization List (Modern)

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
```

**Keterangan:**

- Menggunakan _initializer list_, lebih efisien dan modern.
    
- `nullptr` adalah pengganti modern dari `NULL` sejak C++11.
    
- Disarankan untuk penggunaan di proyek-proyek besar dan _clean code_.
    

---

## 🧠 5. Versi dengan Template (Jika tipe data bisa selain int)

```cpp
template<typename T>
struct Node {
    T data;
    Node* left;
    Node* right;

    Node(T val) : data(val), left(nullptr), right(nullptr) {}
};
```

**Keterangan:**

- Berguna jika ingin menyimpan tipe lain, misalnya `float`, `string`, atau `custom struct`.
    
- Contoh:
    
    ```cpp
    Node<string>* root = new Node<string>("Halo");
    ```
    

---

## ✅ Rangkuman Versi dan Level Modernitas

|Versi|Keterangan|Level Modernitas|
|---|---|---|
|1|Gaya C|🚫 Usang|
|2|Constructor manual|✅ Oke|
|3|Gaya C++ sederhana|✅ Recommended|
|4|Initialization list + `nullptr`|🌟 Modern|
|5|Generic Template|🌟 Advanced|
# Variasi Mid-Advanced
Berikut ini adalah berbagai versi deklarasi `struct Node` dalam pohon biner, dari yang klasik hingga modern dan efisien (termasuk yang sering dipakai dalam _competitive programming_).

---

## 🧱 Versi 1: Klasik / Dasar

```cpp
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
```

**Keterangan:**

- Ciri khas: menggunakan `struct` lengkap.
    
- Kurang efisien karena tidak menyediakan konstruktor untuk inisialisasi langsung.
    
- Cocok untuk materi pembuka atau penjelasan dasar.
    

---

## 🏗️ Versi 2: Klasik dengan Constructor

```cpp
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};
```

**Keterangan:**

- Mudah digunakan.
    
- Lebih singkat saat pembuatan node (`new Node(10)`).
    
- Sangat umum di buku dan tutorial pemula.
    

---

## ⚙️ Versi 3: Constructor Modern (Initialization List)

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};
```

**Keterangan:**

- Menggunakan _initializer list_.
    
- Lebih disarankan dalam konteks modern C++.
    
- Lebih cepat untuk kasus konstruktor kompleks.
    

---

## ⚡ Versi 4: Sering Dipakai dalam Competitive Programming

```cpp
struct Node {
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val) : data(val) {}
};
```

**Keterangan:**

- Field `left` dan `right` langsung diinisialisasi.
    
- Cocok untuk penulisan cepat dan ringkas.
    
- Banyak digunakan di kontes karena praktis.
    

---

## 📦 Versi 5: Menggunakan `shared_ptr` (Smart Pointer)

```cpp
#include <memory>
struct Node {
    int data;
    std::shared_ptr<Node> left = nullptr;
    std::shared_ptr<Node> right = nullptr;
    Node(int val) : data(val) {}
};
```

**Keterangan:**

- Cocok untuk penggunaan C++ modern yang _safe_ dari memory leak.
    
- Tidak perlu `delete` secara manual.
    
- Cocok untuk proyek besar dan long-term.
    

---

## 💡 Versi 6: Dengan Default Arguments (Level Sederhana)

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data = 0, Node* l = nullptr, Node* r = nullptr)
        : data(data), left(l), right(r) {}
};
```

**Keterangan:**

- Bisa dibuat node kosong atau dengan isi lengkap.
    
- Berguna untuk tree yang di-_build_ secara fleksibel atau dinamis.
    

---

## 🧪 Versi 7: Dengan Template

```cpp
template<typename T>
struct Node {
    T data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(T val) : data(val) {}
};
```

**Keterangan:**

- Bisa menampung berbagai jenis data (`int`, `string`, `pair<int,int>`, dll).
    
- Umum digunakan dalam struktur data generik atau library.
    

---

Ya, tentu! Di bawah ini aku tambahkan beberapa **versi lanjutan**, yang lebih **unik**, **ekspresif**, atau **efisien** tergantung konteksnya. Cocok untuk kamu koleksi sebagai referensi lengkap implementasi `struct Node` pada **pohon biner** maupun varian lainnya.

---

## 🧬 Versi 8: Dengan Fungsi Anggota (Method di dalam Struct)

```cpp
struct Node {
    int data;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int val) : data(val) {}

    bool isLeaf() const {
        return left == nullptr && right == nullptr;
    }

    bool hasOnlyOneChild() const {
        return (left != nullptr) ^ (right != nullptr);
    }
};
```

**Kelebihan:**

- Memberikan fungsi bawaan untuk memudahkan pengecekan saat traversal.
    
- Cocok untuk kasus debugging dan logika tree lebih ekspresif.
    

---

## 🧪 Versi 9: Bitfield untuk Efisiensi Memori

```cpp
struct Node {
    unsigned int data : 30;
    Node* left = nullptr;
    Node* right = nullptr;
};
```

**Kelebihan:**

- Membatasi data hanya 30 bit → bisa menghemat memori jika `Node` dalam jumlah besar.
    
- Cocok untuk memory-constrained environments atau embedded.
    

---

## 🧭 Versi 10: Menggunakan Array (Bukan Pointer)

```cpp
struct Node {
    int data;
    Node* child[2] = {nullptr, nullptr};
    Node(int val) : data(val) {}
};
```

**Kelebihan:**

- Cocok untuk menyusun kode lebih umum untuk pohon biner (kiri: `child[0]`, kanan: `child[1]`).
    
- Bisa digunakan sebagai dasar untuk konversi ke _n-ary tree_.
    

---

## 🌐 Versi 11: Untuk N-Ary Tree

```cpp
#include<vector>
struct Node {
    int data;
    std::vector<Node*> children;
    Node(int val) : data(val) {}
};
```

**Kelebihan:**

- Fleksibel untuk pohon general (bukan biner).
    
- Berguna di soal DFS/Trie/Folder/File tree/AST (Abstract Syntax Tree).
    

---

## 🧱 Versi 12: Struct Immutable (Data Konstan)

```cpp
struct Node {
    const int data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val) : data(val) {}
};
```

**Kelebihan:**

- Data tidak bisa diubah setelah pembuatan → menjaga imutabilitas.
    
- Cocok untuk tree yang hanya dibaca (read-only traversal).
    

---

## ⚡ Versi 13: `constexpr` Constructor

```cpp
struct Node {
    int data;
    Node* left = nullptr;
    Node* right = nullptr;

    constexpr Node(int val) : data(val) {}
};
```

**Kelebihan:**

- Jika digunakan dalam konteks `constexpr` (compile-time tree generation), akan disusun lebih awal.
    
- Relevan untuk template metaprogramming.
    

---

## 📦 Versi 14: Dengan `unique_ptr` (Safe Memory Ownership)

```cpp
#include <memory>
struct Node {
    int data;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    Node(int val) : data(val) {}
};
```

**Kelebihan:**

- Tidak perlu `delete` manual.
    
- Jauh lebih aman dari memory leak.
    
- Cocok untuk proyek skala menengah-besar (selain competitive).
    

---

## 🧠 Versi 15: Dengan Parent Pointer

```cpp
struct Node {
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;

    Node(int val) : data(val) {}
};
```

**Kelebihan:**

- Cocok untuk algoritma seperti LCA, path tracking, atau threaded binary tree.
    

---

Berikut tambahan beberapa **versi lanjutan** dari `struct Node`, masing-masing dengan karakteristik khusus yang bisa berguna di konteks berbeda:

---

## ⚙️ Versi 16: Arena-Allocated Nodes (Pointer Pool)

```cpp
// ArenaAllocator.h (simplified)
class Arena {
    static constexpr size_t BLOCK_SIZE = 1 << 20;
    std::vector<char*> blocks;
    char* ptr = nullptr, *end = nullptr;
public:
    ~Arena() { for (auto b : blocks) delete[] b; }
    void* alloc(size_t sz) {
        if (ptr + sz > end) {
            ptr = new char[BLOCK_SIZE];
            end = ptr + BLOCK_SIZE;
            blocks.push_back(ptr);
        }
        void* r = ptr;
        ptr += sz;
        return r;
    }
};

// Usage:
struct Node {
    int data;
    Node* left;
    Node* right;
    // placement-new from arena
    static void* operator new(size_t sz, Arena& arena) {
        return arena.alloc(sz);
    }
    Node(int v): data(v), left(nullptr), right(nullptr) {}
};
```

**Kegunaan:**

- Alokasi super-cepat untuk **juta-an node** di kontes.
    
- Sekali delete arena = delete semua node.
    

---

## 🕸️ Versi 17: Cache-Aligned Nodes (Performance-Critical)

```cpp
#include <cstdint>
#include <new>
struct alignas(64) Node {  // pad ke 64-byte cache line
    int data;
    Node* left;
    Node* right;
    Node(int v): data(v), left(nullptr), right(nullptr) {}
};
```

**Kegunaan:**

- Meminimalkan **cache-miss** saat traversal besar.
    
- Cocok untuk tree sangat besar di aplikasi real-time.
    

---

## 🧩 Versi 18: Operator Overloading & Comparison

```cpp
struct Node {
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int v): data(v) {}

    bool operator<(Node const& o) const {
        return data < o.data;
    }
    bool operator==(Node const& o) const {
        return data == o.data;
    }
};
```

**Kegunaan:**

- Memudahkan menaruh `Node` dalam `std::set<Node>` atau `std::map<Node,…>`.
    
- Bisa juga untuk algoritma yang butuh sorting/comparison antar node.
    

---

## 🌀 Versi 19: Immutable Functional-Style Tree

```cpp
#include <memory>
struct Node {
    int data;
    std::shared_ptr<const Node> left;
    std::shared_ptr<const Node> right;
    Node(int v,
         std::shared_ptr<const Node> l = nullptr,
         std::shared_ptr<const Node> r = nullptr)
      : data(v), left(l), right(r) {}
};
```

**Kegunaan:**

- Setiap modifikasi “membuat” node baru → **persistent data structure**.
    
- Berguna di paradigma fungsional atau undo/redo.
    

---

## ⚛️ Versi 20: Tagged Union untuk Nilai Khusus

```cpp
#include <variant>
struct LeafTag {};
struct InternalTag {};

using NodePtr = struct Node*;
struct Node {
    std::variant<int, LeafTag> data;   // kalau variant berisi LeafTag = leaf
    InternalTag tag;
    NodePtr left = nullptr;
    NodePtr right = nullptr;
    Node(int v): data(v), tag(InternalTag{}) {}
    Node(): data(LeafTag{}), tag(InternalTag{}) {}
};
```

**Kegunaan:**

- Membedakan **leaf** dan **internal** node dengan tipe aman.
    
- Berguna untuk pembuatan **trie** atau **syntax tree**.
    


