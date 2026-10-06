---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Resiko Memory Leak Pada Tree
sumber: Google.com, AI
date_learned: 2025-06-28T17:33:00
tags:
  - tree-algorithm
---
Link Sumber: 

---
# Resiko Memory Leak Pada Tree

## 1 | Apa itu Memory Leak
Memory leak adalah kondisi di mana program mengalokasikan memori (biasanya dengan `new` atau `malloc`) tetapi tidak pernah melepaskannya (dengan `delete` atau `free`). Pada aplikasi jangka panjang atau data besar, kebocoran ini bisa membuat penggunaan memori membengkak hingga program crash atau sistem jadi lambat.

Dalam konteks **binary tree**, setiap node biasanya dialokasikan secara dinamis. Jika kita tidak menghapus seluruh subtree dengan benar, maka sebagian besar node akan “hilang” di heap tanpa bisa diakses lagi → memory leak.

---

## 2 | Mengapa Binary Tree Rentan Memory Leak

1. **Alokasi Dinamis Banyak**  
    Setiap node (`new Node(...)`) menambah objek di heap. Node dibuat dengan `new`, sehingga perlu dikelola manual.
<br/>
2. **Struktur Rekursif**  
    Node memiliki pointer ke child kiri/kanan, yang juga punya pointer lagi. Kalau kita lupa rekursif `delete`, subtree tertinggal.
<br/>
3. **Operasi Penggantian/Substitusi**  
    Metode seperti `setLeft()` yang `delete` pointer sebelumnya tanpa menghapus subtree, bisa membocorkan memory.
<br/>
---

## 3 | Contoh Kasus Memory Leak

```cpp
struct Node {
    int data;
    Node *left, *right;
    Node(int v): data(v), left(nullptr), right(nullptr) {}
    
    // Berbahaya: delete left tanpa rekursi
    void setLeft(int v) {
        delete left;           // hanya menghapus node root-left,
        left = new Node(v);    // subtree-nya masih menumpuk di heap!
    }
};
```

Pada blok di atas, jika `left` semula memiliki subtree, `delete left` hanya memanggil destructor default (tanpa rekursi), sehingga anak-anaknya tidak dihapus → **leak**.

> Jika `left` sebelumnya memiliki anak, maka `delete left` tidak cukup untuk menghapus seluruh subtree. Anak-anaknya tetap tertinggal di heap dan tidak bisa diakses lagi.

---

## 4 | Cara Mendeteksi Memory Leak

- **Valgrind** (Linux/macOS):
    
    ```bash
    valgrind --leak-check=full ./nama_program
    ```
    
- **Visual Studio Diagnostic Tools** di Windows.
    
- **Sanitizer** (GCC/Clang):
    
    ```bash
    g++ -fsanitize=address -g main.cpp
    ./a.out
    ```
    

---

## 5 | Solusi 1: Destructor Rekursif dan `delete` Manual
### 📌 Apa itu Destructor?

**Destructor** adalah fungsi khusus dalam C++ yang otomatis dipanggil saat suatu objek dihapus (misalnya lewat `delete` atau saat keluar dari scope). Tujuannya adalah untuk **membersihkan resource** seperti memori heap, file, atau koneksi yang digunakan objek tersebut.

Sintaksnya:

```cpp
~NamaClass() {
    // kode pembersihan
}
```

Contoh pada binary tree:

```cpp
~Node() {
    delete left;
    delete right;
}
```

Dengan destructor seperti ini, saat kamu `delete root`, seluruh subtree akan ikut dibersihkan secara rekursif.
### 5.1. Tambahkan Destructor yang Menghapus Subtree

```cpp
struct Node {
    int data;
    Node *left, *right;
    Node(int v): data(v), left(nullptr), right(nullptr) {}
    ~Node() {
        delete left;   // secara rekursif memanggil ~Node() pada subtree
        delete right;
    }
};
```

### 5.2. Hapus Root di `main()`

```cpp
int main() {
    Node* root = new Node(10);
    // … bangun tree …
    delete root;      // memicu penghapusan seluruh node
    return 0;
}
```

Dengan ini, setiap node—dan subtree-nya—akan di-`delete` satu per satu.

### Cara kerja

> Jadi? Cara penggunaanya cukup seperti itu saja?

Cara penggunaannya memang **cukup seperti itu saja** — saat kamu membuat destructor seperti contoh di bawah ini:

```cpp
~Node() {
    delete left;
    delete right;
}
```

… maka kamu tidak perlu lagi menghapus `left` dan `right` secara manual di mana pun, selama kamu memastikan `delete` dipanggil ke root-nya saja.

---

#### Cara Kerja Destructor di Tree (Secara Rekursif)

Bayangkan kamu punya tree seperti ini:

```

      1
     / \
    2   3
   /
  4
  
```

Saat kamu menulis:

```cpp
Node* root = new Node(1);
// lalu menambahkan anak-anak seperti biasa
delete root;
```

Maka prosesnya seperti ini:

- `delete root` → memanggil `~Node()` untuk node 1
    
- Dalam `~Node()` node 1: `delete left` → memanggil `~Node()` untuk node 2
    
- Dalam `~Node()` node 2: `delete left` → memanggil `~Node()` untuk node 4
    
- Dalam `~Node()` node 2: `delete right` → tidak ada (nullptr), aman
    
- Dalam `~Node()` node 1: `delete right` → memanggil `~Node()` untuk node 3
    
- Dan seterusnya...
    

---

#### Kesimpulan Singkat Penggunaan

Untuk tree yang dibangun dengan `new`, kamu cukup:

1. **Buat destructor rekursif** seperti di atas.
    
2. **Panggil `delete root;` di akhir `main()`** atau saat kamu sudah selesai menggunakan tree.
    

Tidak perlu `delete node->left` dan `delete node->right` secara terpisah — destructor akan melakukannya secara otomatis dan aman.

### Penggunaan 

> Jadi, kedua cara diatas harus dilakukan bersama-sama?

Pertanyaan bagus! Jawabannya adalah:

> ✅ **Itu adalah kombinasi yang saling melengkapi**, **bukan pilihan antara salah satu**.

---

#### Penjelasan Singkat:

- **Destructor di dalam struct/class** (`~Node()`) bertugas:
    
    > Menghapus `left` dan `right` **secara rekursif** untuk membersihkan seluruh subtree.
    
- **`delete root;` di `main()`** bertugas:
    
    > Memulai proses pembersihan dengan **memanggil destructor pada node pertama (root)**.
    

---

#### 🔥 Analogi Sederhana:

Bayangkan destructor itu seperti **pemadam kebakaran otomatis di setiap rumah** (node).  
Tapi pemadaman **baru dimulai** kalau kamu **tekan tombol utama** dari kantor pusat (yakni `delete root;`).

Kalau kamu tidak pernah memanggil `delete root`, maka seluruh sistem otomatis pemadam tidak pernah bekerja — walaupun sudah disiapkan dengan baik di dalam rumah-rumah.

---

#### 🧠 Kesimpulan:

|Hal yang Dilakukan|Wajib?|Fungsi|
|---|---|---|
|Tambah destructor di struct|✅ Ya|Supaya subtree ikut dibersihkan saat delete satu node|
|Panggil `delete root` di main|✅ Ya|Supaya proses pembersihan benar-benar dijalankan dari atas|

🔑 **Jadi keduanya harus digunakan bersama-sama** agar binary tree kamu bebas dari memory leak.

Kalau kamu hanya menambahkan destructor tapi tidak pernah memanggil `delete`, maka memory leak tetap terjadi.

---

## 6 | Solusi 2: Smart Pointer (`unique_ptr`)

### 6.1. Keuntungan

#### Otomatis Menghapus Saat Keluar Scope (RAII)

`std::unique_ptr` mengikuti prinsip **RAII** (_Resource Acquisition Is Initialization_), artinya:

- Objek yang dimiliki oleh `unique_ptr` akan **otomatis dihapus** ketika pointer tersebut keluar dari scope-nya, tanpa perlu menulis `delete`.
    

Contoh:

```cpp
{
    std::unique_ptr<Node> root = std::make_unique<Node>(10);
    // Tree dibangun di sini
} // saat keluar dari block, root dan seluruh subtree akan dihapus otomatis
```

#### Tidak Perlu Menulis Destructor Manual

Karena `unique_ptr` sudah mengatur penghapusan resource secara otomatis, kamu **tidak perlu menulis destructor rekursif** di struct/class seperti:

```cpp
~Node() {
    delete left;
    delete right;
}
```

`unique_ptr` akan menghapus anak-anak secara otomatis karena `unique_ptr` dihapus secara rekursif saat objek dimusnahkan.
#### Mencegah Double Delete

Karena `unique_ptr` **tidak dapat disalin (copy disabled)**, maka tidak mungkin ada dua pointer yang menghapus objek yang sama.

- Hanya **satu `unique_ptr`** yang boleh memiliki satu objek.
    
- Ini **menghindari bug berbahaya** seperti `double free` atau `delete twice`.
    
#### Membantu Mencegah Memory Leak

Jika terjadi exception atau `return` lebih awal, `unique_ptr` tetap akan **otomatis membersihkan memori**, sementara raw pointer sering lupa dihapus kalau flow program lompat.

#### Menunjukkan Kepemilikan (Ownership) Secara Jelas

`unique_ptr` menyatakan bahwa suatu objek hanya dimiliki oleh satu entitas. Ini **membuat kode lebih mudah dipahami**, karena kamu tahu dengan jelas siapa yang bertanggung jawab atas penghapusan memori.

#### Mendukung Pindah (Move)

Karena tidak bisa disalin, `unique_ptr` bisa **dipindahkan** (`std: :move`) ke tempat lain jika kamu ingin mengalihkan kepemilikan objek ke bagian lain dari program.

Contoh:

```cpp
std::unique_ptr<Node> left = std::make_unique<Node>(5);
root->left = std::move(left);
```

#### Lebih Ringan daripada `shared_ptr`

- `unique_ptr` tidak memiliki reference count.
    
- Tidak perlu mengelola siklus.
    
- Kinerja lebih cepat dan overhead lebih kecil dibandingkan `shared_ptr`.
    

---

#### Kesimpulan:

`std::unique_ptr` adalah **cara modern, ringan, dan aman** untuk menangani alokasi memori dinamis seperti pada binary tree. Dengan menggunakannya, kamu mendapatkan:

✅ Pembersihan otomatis  
✅ Perlindungan dari leak dan double delete  
✅ Kode lebih bersih dan aman  
✅ Tidak perlu destructor manual

### 6.2. Contoh Implementasi

```cpp
#include <memory>
#include <iostream>

struct Node {
    int data;
    std::unique_ptr<Node> left, right;
    Node(int v): data(v) {}
    Node* setLeft(int v) {
        left = std::make_unique<Node>(v);  // otomatis destroy sebelumnya
        return left.get();
    }
    // … mirip untuk setRight & traversal …
};

int main() {
    auto root = std::make_unique<Node>(10);
    root->setLeft(5);
    // … 
    // Tidak perlu delete
}
```

---

## 7 | Solusi 3: Shared Ownership dengan `std::shared_ptr` dan `std::weak_ptr`

Kadang Anda ingin **shared ownership** (misal node direferensikan dari banyak tempat):

```cpp
#include <memory>
#include <iostream>

struct Node : std::enable_shared_from_this<Node> {
    int data;
    std::shared_ptr<Node> left, right;
    Node(int v): data(v) {}

    std::shared_ptr<Node> setLeft(int v) {
        left = std::make_shared<Node>(v);
        return left;
    }
    // …
};

int main() {
    auto root = std::make_shared<Node>(10);
    root->setLeft(5);
    // …
}
```

### Hindari Cyclic References

Jika anak menunjuk kembali ke parent, gunakan `std::weak_ptr` untuk mematahkan siklus:

```cpp
std::weak_ptr<Node> parent;  // tidak menambah reference count
```

---

`std::weak_ptr<Node> parent;` digunakan untuk mencegah **cyclic reference** ketika kamu punya struktur **parent → child → parent** (loop), yang bisa menyebabkan **memory leak** meskipun kamu sudah pakai `std::shared_ptr`.

Berikut contoh lengkap implementasi **binary tree dengan parent pointer menggunakan `shared_ptr` dan `weak_ptr`** agar kamu bisa melihat bagaimana caranya menghindari cyclic reference.

---

#### Contoh: Binary Tree dengan `shared_ptr` dan `weak_ptr`

```cpp
#include <iostream>
#include <memory>
using namespace std;

struct Node : enable_shared_from_this<Node> {
    int data;
    shared_ptr<Node> left, right;
    weak_ptr<Node> parent; // 🔥 weak_ptr agar tidak menyebabkan cyclic reference

    explicit Node(int data) : data(data) {}

    shared_ptr<Node> setLeft(int val) {
        left = make_shared<Node>(val);
        left->parent = shared_from_this(); // 🔁 relasi ke parent
        return left;
    }

    shared_ptr<Node> setRight(int val) {
        right = make_shared<Node>(val);
        right->parent = shared_from_this(); // 🔁 relasi ke parent
        return right;
    }

    void inorder() {
        if (left) left->inorder();
        cout << data << " ";
        if (right) right->inorder();
    }

    void printParent() {
        if (auto p = parent.lock()) // 🔓 safe convert weak_ptr → shared_ptr
            cout << "Parent of " << data << " is " << p->data << "\n";
        else
            cout << data << " has no parent\n";
    }
};

int main() {
    auto root = make_shared<Node>(1);
    auto L = root->setLeft(2);
    auto R = root->setRight(3);

    L->setLeft(4)->setRight(5);  // subtree kiri

    root->inorder(); cout << "\n";

    // Tes akses parent
    L->printParent();            // Parent of 2 is 1
    L->left->right->printParent(); // Parent of 5 is 4
    root->printParent();         // 1 has no parent

    return 0;
}
```


---

#### Penjelasan Penting

|Elemen|Penjelasan|
|---|---|
|`shared_ptr<Node>`|Memiliki dan mengelola objek Node|
|`weak_ptr<Node>`|Referensi ke Node tapi **tidak** menambah reference count (`use_count`)|
|`shared_from_this()`|Mendapat shared_ptr dari dalam class untuk membuat hubungan balik (`parent`)|
|`parent.lock()`|Mengakses isi `weak_ptr` jika masih hidup (tidak expired)|

Tanpa `weak_ptr`, jika kamu tulis:

```cpp
left->parent = shared_ptr<Node>(this);
```

Atau bahkan:

```cpp
left->parent = root;  // shared_ptr
```

...maka akan terjadi **siklus** yang menyebabkan root tidak pernah dihapus (reference count tidak pernah 0) → memory leak.

---

#### Kesimpulan

- Gunakan `weak_ptr` untuk **relasi balik (parent)** agar tidak menciptakan siklus.
    
- `shared_ptr` cocok untuk relasi satu arah (root → child).
    
- Kombinasi ini membuat struktur tree aman dari memory leak **meskipun ada parent pointer**.
    

Kalau kamu mau aku buatkan visualisasi memori atau `use_count` saat program berjalan, tinggal bilang ya!

### Penjelasan Lengkap

Gunakan `std::shared_ptr` ketika:

- Sebuah node atau objek **perlu dimiliki oleh lebih dari satu pihak (shared ownership)**.
    
- Kamu menyimpan referensi ke node dari **struktur lain** seperti `map`, `vector`, atau cache global.
    
- Kamu butuh pointer ke node tetap hidup **meskipun root tree sudah dihapus**.
    

Contoh:  
Jika kamu menyimpan pointer ke beberapa node tertentu untuk traversal cepat atau memoization, maka `shared_ptr` bisa memastikan node tersebut tetap hidup.

---

#### ✅ Kelebihan `shared_ptr`

1. **Manajemen Memori Otomatis Berbasis Reference Count**  
    Objek akan otomatis dihapus ketika semua `shared_ptr` yang menunjuk ke objek tersebut telah dihancurkan.
    
2. **Mendukung Kepemilikan Bersama**  
    Dua atau lebih `shared_ptr` bisa menunjuk ke objek yang sama tanpa menyebabkan double delete.
    
3. **Fleksibel**  
    Bisa digunakan untuk node yang direferensikan dari banyak tempat sekaligus.
    

---

#### ⚠️ Risiko dan Kekurangan

1. **Overhead Lebih Besar**  
    Karena menggunakan reference count (counter internal), `shared_ptr` sedikit lebih berat dari `unique_ptr`.
    
2. **Bisa Menyebabkan Memory Leak karena Cyclic Reference**  
    Jika dua `shared_ptr` saling menunjuk (misal node child menunjuk ke parent dan sebaliknya), maka reference count tidak akan pernah nol → objek tidak pernah dihapus → memory leak!
    
    **Solusi:** Gunakan `std::weak_ptr` untuk memutus siklus.
    

---

#### 🔄 Contoh Masalah Cyclic Reference

```cpp
struct Node {
    std::shared_ptr<Node> left, right;
    std::shared_ptr<Node> parent;  // 🔴 ini bisa menimbulkan cyclic reference
};
```

Jika `child` punya `shared_ptr` ke `parent`, dan `parent` punya `shared_ptr` ke `child`, maka reference count tidak akan pernah 0 meskipun semua node dilepas.

---

#### ✅ Solusi: Pakai `std::weak_ptr` untuk Parent

```cpp
struct Node : std::enable_shared_from_this<Node> {
    int data;
    std::shared_ptr<Node> left, right;
    std::weak_ptr<Node> parent; // ✅ tidak menaikkan reference count

    void setLeft(std::shared_ptr<Node> child) {
        left = child;
        child->parent = shared_from_this(); // aman karena weak_ptr
    }
};
```

Dengan `weak_ptr`, kamu bisa menyimpan referensi ke `parent` tanpa membuat siklus yang menyebabkan memory leak.

---

#### 🔐 Perbedaan `unique_ptr` vs `shared_ptr` (Ringkasan)

|Aspek|`unique_ptr`|`shared_ptr`|
|---|---|---|
|Ownership|Tunggal (satu pemilik)|Bisa banyak pemilik|
|Copyable?|❌ Tidak bisa dicopy|✅ Bisa dicopy|
|Moveable?|✅ Ya|✅ Ya|
|Overhead|Sangat ringan|Lebih berat (reference counter)|
|Cyclic Reference?|❌ Tidak bisa|⚠️ Bisa (hindari dengan `weak_ptr`)|
|Cocok Untuk Tree?|✅ Sangat cocok|⚠️ Hanya jika butuh referensi silang|

---

#### 💬 Tips Praktis

- Gunakan `shared_ptr` **hanya jika memang perlu** ada banyak pemilik.
    
- Jangan ragu menggunakan `unique_ptr` untuk struktur tree biasa yang hanya punya 1 owner per node.
    
- Selalu gunakan `weak_ptr` untuk relasi balik (seperti parent), agar tidak membentuk siklus.
    
- Hindari menyimpan `shared_ptr` dalam struktur global tanpa pengelolaan lifecycle yang jelas.
    

---

## 8. Best Practices dan Tips

1. **Pilih Smart Pointer** (`unique_ptr` bila mungkin)
    
2. **Hindari `new`/`delete` Manual**
    
3. **Destructor Rekursif** jika masih pakai raw pointer
    
4. **Gunakan Tools** untuk deteksi leak di tahap pengembangan
    
5. **Uji dengan Input Besar** untuk memastikan tidak ada kebocoran
    
6. **Perhatikan Exception Safety**—gunakan RAII agar safe saat exception
    

---

## 9. Kesimpulan

- **Raw pointer** risikonya tinggi: wajib destructor rekursif + `delete root`.
    
- **unique_ptr** adalah solusi modern & ringan untuk tree.
    
- **shared_ptr + weak_ptr** cocok jika butuh shared ownership tapi hati‑hati siklus.
    
- **Selalu** gunakan alat deteksi leak (Valgrind, Sanitizer) sebagai bagian pipeline QA.
    

Dengan mengikuti pola di atas, struktur data binary tree Anda akan **bebas memory leak** dan lebih **aman** untuk digunakan di aplikasi nyata.