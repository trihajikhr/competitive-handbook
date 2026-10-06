---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Unique_ptr pada Tree
sumber: Google.com, AI
date_learned: 2025-06-28T18:19:00
tags:
  - tree-algorithm
---
Link Sumber: 

---
# Unique_ptr pada Struct Node
Jika kita menggunakan raw pointer, kita mungkin akan membuat struct Node sebagai berikut:

```cpp
#include<iostream>
#include<memory>
using namespace std;

struct Node {
    int data;
    unique_ptr<Node> left, right;
    Node(int data){
        this->data = data;
        left  = nullptr;
        right = nullptr;
    }
};
```

Tapi, apakah ketika menggunakan `unique_ptr`, penulisanya masih sama?

Secara logika dan hasil kompilasi, kode ini benar dan akan bekerja di C++. Tapi ada beberapa peningkatan gaya penulisan (style) dan praktik modern yang bisa membuatnya lebih bersih dan aman.

---

## ✅ Penjelasan per Bagian

### Baris-baris ini:

```cpp
struct Node {
    int data;
    unique_ptr<Node> left, right;
```

- ✅ Benar: kamu memakai `std::unique_ptr<Node>` untuk `left` dan `right`, yang **otomatis akan menghapus child node** saat objek ini dihancurkan.
    

---

### Konstruktor ini:

```cpp
Node(int data){
    this->data = data;
    left  = nullptr;
    right = nullptr;
}
```

- ✅ Secara teknis benar.
    
- ❗Tapi: `unique_ptr` **secara default akan menjadi `nullptr`** saat belum diisi, jadi inisialisasi `left = nullptr` dan `right = nullptr` **tidak wajib dan bisa dihapus**.
    

---

## 💡 Versi yang Lebih Ringkas dan Modern

```cpp
#include <iostream>
#include <memory>
using namespace std;

struct Node {
    int data;
    unique_ptr<Node> left, right;

    // Versi ringkas dan idiomatik
    Node(int data) : data(data) {} 
};
```

### Mengapa ini lebih baik:

- Menggunakan **initializer list** (`: data(data)`) lebih efisien daripada assignment dalam body constructor.
    
- Tidak perlu inisialisasi `left` dan `right`, karena `unique_ptr` otomatis `nullptr` saat dibuat.
    

---

## 🧠 Kesimpulan

|Versi Kamu|✅ Benar, akan jalan|
|---|---|
|Versi Modern & Bersih|✅ Lebih disarankan|
# Unique_ptr pada Main Function

 Dijelaskan bahwa kita bisa mendeklarasikan dan menginisialisasi Node root dengan cara seperti ini:

```cpp
auto root = make_unique<Node>(10);
```

Jika tanpa `auto`, apakah ini penulisan yang benar:

```cpp
int main() {
    unique_ptr<Node> root = make_unique<Node>(10);
    root->setChild(1,2);
    root->left->setChild(4,5);
    root->right->setChild(9, 8);

    root->traversInorder();
    return 0;
}

```


---

Pertanyaanmu sangat tepat! Tapi ada **satu kesalahan sintaks di baris ini:**

```cpp
unique_ptr<Node>(root) = make_unique<Node>(10);
```

❌ **Itu bukan cara yang benar untuk mendeklarasikan dan menginisialisasi `unique_ptr`.**  
C++ akan mengira kamu sedang membuat objek sementara `unique_ptr<Node>(root)` dan tidak menyimpan hasil dari `make_unique`.

---

## ✅ Penulisan yang Benar Tanpa `auto`

Jika kamu **tidak ingin menggunakan `auto`**, maka penulisan yang benar adalah:

```cpp
int main() {
    std::unique_ptr<Node> root = std::make_unique<Node>(10);
    root->setChild(1, 2);
    root->left->setChild(4, 5);
    root->right->setChild(9, 8);

    root->traversInorder();
    return 0;
}
```

 `auto` di C++ digunakan untuk **menghindari penulisan tipe panjang**, dan di kasus ini:

```cpp
auto root = std::make_unique<Node>(10);
```

… secara otomatis berarti:

```cpp
std::unique_ptr<Node> root = std::make_unique<Node>(10);
```

---

## 🧠 Ringkasan

```cpp
auto root = make_unique<Node>(10);
```

- ✅ Benar
- Praktis, ringkas

---
```cpp
unique_ptr<Node> root = make_unique<Node>(10);
```

- ✅ Benar
- Ekspisit, lebih panjang tapi jelas

---

```cpp
unique_ptr<Node>(root) = make_unique<Node>(10);
```

- ❌ Salah
- Bukan cara deklarasi + inisialisasi
