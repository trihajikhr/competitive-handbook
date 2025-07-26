---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Tree dengan unique_ptr
sumber: Google.com, AI
date_learned: 2025-06-30T16:54:00
tags:
  - tree-algorithm
---
Link Sumber: 

---
# Tree dengan unique_ptr
## Apa itu `unique_ptr`
`std::unique_ptr` adalah **smart pointer** di C++ yang secara otomatis mengelola memori dari objek yang dialokasikan secara dinamis (biasanya di heap). Berbeda dengan pointer biasa (`T*`), `unique_ptr` **hanya boleh memiliki satu pemilik tunggal** untuk satu objek. Saat `unique_ptr` keluar dari scope atau dihancurkan, ia akan otomatis memanggil `delete` pada objek yang dikelolanya, sehingga kamu tidak perlu khawatir lupa membebaskan memori (dan menghindari memory leak).

### Analogi Singkat 

Bayangkan kamu punya satu kunci untuk membuka satu ruangan. Hanya **satu orang** yang boleh memegang kunci itu pada satu waktu. Jika kamu ingin memberikan akses ke orang lain, kamu **harus menyerahkan kunci itu sepenuhnya**. Setelah itu, kamu tidak bisa masuk lagi. Itulah `unique_ptr`—ia menjamin **kepemilikan eksklusif** terhadap satu objek.

### Analogi naratif
Bayangkan kamu sedang menata rak buku yang sangat berharga—setiap buku hanya punya satu tempat di rak, dan begitu kamu meletakkan buku itu, raklah yang bertanggung jawab memastikan buku itu tetap aman hingga kamu memutuskan untuk memindahkannya. Begitu pula `std::unique_ptr` di C++: ia ibarat “rak pintar” yang secara otomatis memegang satu objek di heap, menjaga agar objek itu tidak hilang atau tertinggal begitu saja. Ketika rak—alias variabel `unique_ptr`—itu dibersihkan atau keluar dari lingkup, ia pun dengan tepat “menurunkan” dan memusnahkan buku (objek) yang dipegangnya, tanpa memerlukan perintah terpisah.

Secara sederhana, `unique_ptr` memberikan jaminan bahwa **hanya ada satu pemilik** untuk setiap objek yang dialokasikan di heap. Tidak seperti pointer mentah yang bisa bertebaran dan saling menimpa, `unique_ptr` memastikan tidak ada salinan sembarangan—kalau kamu mencoba menyalinnya, kompilator akan menolak. Kamu bisa memindahkannya (move) ke rak lain, tetapi setelah dipindahkan, rak lama tidak lagi menyimpan apa-apa. Dengan begitu, risiko lupa menghapus atau menghapus dua kali pun hilang, karena manajemen memori sudah tercakup di dalam perilaku `unique_ptr` itu sendiri.

## Penjelasan Teknis 
### 1. Deklarasi & Inisialisasi

```cpp
#include <memory>

// Membuat unique_ptr yang mengelola objek T
std::unique_ptr<T> p1 = std::make_unique<T>(args…);
```

- **`std::make_unique<T>(args…)`**  
    - Membuat objek `T` di heap dengan konstruktor `T(args…)`  
    - Mengembalikan `unique_ptr<T>` yang mengelola objek itu.
	<br/>
    - Membuat objek `T` di heap dan mengembalikannya sebagai `unique_ptr<T>`.

### 2. Eksklusifitas Kepemilikan

```cpp
auto p1 = std::make_unique<int>(42);
// auto p2 = p1;           // ❌ error: unique_ptr tidak bisa disalin
auto p2 = std::move(p1);  // ✅ pindah kepemilikan

// Setelah std::move:
//   - p2 mengelola objek (nilai 42)  
//   - p1 kini nullptr (tidak lagi memegang apa‑apa)
```

- Tidak bisa disalin: `auto p2 = p1;` akan menghasilkan kesalahan kompilasi.
	
- Bisa dipindah: `auto p2 = std::move(p1);` memindahkan kepemilikan, lalu `p1` menjadi `nullptr`.


### 3. Metode Utama

#### ✅ 3.1 `get()`

Mengembalikan **raw pointer (`T*`)** ke objek yang sedang dikelola oleh `unique_ptr`, **tanpa melepaskan kepemilikan**.

- **Kamu tidak perlu `delete`** raw pointer ini.
    
- Berguna jika kamu ingin mengakses fungsi atau API eksternal yang menerima `T*`, tapi kamu tetap ingin `unique_ptr` mengelolanya.
    

**Contoh:**

```cpp
#include <iostream>
#include <memory>
using namespace std;

struct A {
    void hello() { cout << "Halo dari A\n"; }
};

int main() {
    unique_ptr<A> ptr = make_unique<A>();
    A* raw = ptr.get();  // ambil pointer mentah
    raw->hello();        // gunakan pointer mentah
    // ptr tetap memegang kepemilikan
}
```

---

#### ✅ 3.2 `release()`

**Melepaskan kepemilikan** objek yang dikelola dan mengembalikan pointer mentah (`T*`), lalu `unique_ptr` akan menjadi kosong (`nullptr`).

- **Kamu harus delete sendiri** pointer mentahnya jika tidak digunakan oleh smart pointer lain.
    
- Biasanya dipakai kalau kamu ingin mentransfer objek ke pengelola lain (manual atau smart pointer lain).
    

 **Contoh:**

```cpp
#include <iostream>
#include <memory>
using namespace std;

struct A {
    A() { cout << "A dibuat\n"; }
    ~A() { cout << "A dihancurkan\n"; }
};

int main() {
    unique_ptr<A> ptr = make_unique<A>();
    A* raw = ptr.release();  // ambil alih objek, ptr jadi nullptr

    cout << "ptr sekarang = " << ptr.get() << "\n";  // null
    delete raw;  // harus manual delete karena unique_ptr tidak mengelola lagi
}
```

---

#### ✅ 3.3 `reset()`

Mengganti objek yang dikelola dengan objek baru, atau menghapus objek jika dipanggil tanpa argumen.

- Jika `ptr` sedang memegang objek lama, maka `delete` akan dipanggil otomatis sebelum diganti.
    
- Jika kamu ingin mengosongkan `unique_ptr`, panggil `ptr.reset();`
    

**Contoh:**

```cpp
#include <iostream>
#include <memory>
using namespace std;

struct A {
    int val;
    A(int v) : val(v) { cout << "A(" << val << ") dibuat\n"; }
    ~A() { cout << "A(" << val << ") dihancurkan\n"; }
};

int main() {
    unique_ptr<A> ptr = make_unique<A>(1);

    ptr.reset(new A(2));  // hapus A(1), ganti dengan A(2)
    ptr.reset();          // hapus A(2), ptr jadi nullptr
}
```

#### Kesimpulan Singkat:

|Metode|Fungsi Utama|
|---|---|
|`get()`|Mengakses pointer mentah tanpa kehilangan kepemilikan|
|`release()`|Melepas kepemilikan dan mengembalikan pointer mentah|
|`reset(ptr)`|Mengganti objek yang dikelola atau menghapus jika `ptr` kosong|

Gunakan metode-metode ini saat kamu perlu fleksibilitas tambahan dalam mengelola objek dinamis, tetapi tetap ingin memanfaatkan keamanan dan otomatisasi dari `unique_ptr`.

### 4. Destruksi Otomatis

Saat `unique_ptr` keluar dari scope atau di-`reset()`, ia akan secara otomatis memanggil `delete` pada objek yang dikelolanya. Ini berarti destructor dari objek tersebut juga akan dipanggil. Jadi, kamu tidak perlu memanggil `delete` secara manual.


### 5. Contoh Program Lengkap

```cpp
#include <iostream>
#include <memory>
using namespace std;

struct Widget {
    int id;
    Widget(int id) : id(id) {
        cout << "Widget(" << id << ") constructed\n";
    }
    
    ~Widget() {
        cout << "Widget(" << id << ") destroyed\n";
    }
};

int main() {
    // 1) Inisialisasi
    auto p1 = make_unique<Widget>(1);    
    cout << "p1.get() = " << p1.get() << "\n\n";

    // 2) Eksklusifitas & move
    // auto p2 = p1;   // ❌ tidak boleh
    auto p2 = move(p1);                   
    cout << "After move:\n";
    cout << "  p1.get() = " << p1.get() << "\n";
    cout << "  p2.get() = " << p2.get() << "\n\n";

    // 3) Method get(), release(), reset()
    Widget* raw = p2.get();    // raw pointer, tidak melepaskan ownership
    cout << "Raw from get(): " << raw << "\n\n";

    Widget* released = p2.release();     // melepaskan ownership
    cout << "After release:\n";
    cout << "  p2.get()    = " << p2.get() << "\n";
    cout << "  released    = " << released << "\n\n";

    // Karena sudah di-release, kita harus delete manual:
    delete released;                      

    // 4) reset()
    auto p3 = make_unique<Widget>(3);
    cout << "\nBefore reset, p3 manages Widget(3)\n";
    p3.reset(new Widget(4));   // Widget(3) destroyed, ganti dengan Widget(4)
    cout << "After reset, p3 manages Widget(4)\n\n";

    // 5) Destruksi otomatis saat keluar scope
    cout << "End of main, remaining unique_ptr will destroy their Widgets\n";
    return 0;
}
```

#### Output yang Diharapkan

```
Widget(1) constructed
p1.get() = 0x55f9e4f1eeb0

After move:
  p1.get() = 0
  p2.get() = 0x55f9e4f1eeb0

Raw from get(): 0x55f9e4f1eeb0

After release:
  p2.get()    = 0
  released    = 0x55f9e4f1eeb0
Widget(1) destroyed

Widget(3) constructed

Before reset, p3 manages Widget(3)
Widget(4) constructed
Widget(3) destroyed
After reset, p3 manages Widget(4)

End of main, remaining unique_ptr will destroy their Widgets
Widget(4) destroyed
```

---

## Keuntungan Menggunakan `unique_ptr` (terutama via `make_unique`)

### 1. ✅ RAII (Resource Acquisition Is Initialization)

- **Makna**: Saat objek dibuat, resource langsung dimiliki; saat keluar dari scope, resource dilepaskan.
    
- **Manfaat**: Tidak ada memory leak karena memori selalu dibebaskan tepat waktu, bahkan saat terjadi exception.
    
- **Contoh nyata**: Tidak perlu memanggil `delete` sendiri — `unique_ptr` akan otomatis memanggil `delete`.
    
<br/>

### 2. 🔒 Type-Safety (Keamanan Tipe)

- Compiler akan memastikan bahwa pointer yang dikelola sesuai dengan tipe yang benar.
    
- Tidak perlu `void*` atau `reinterpret_cast` seperti pada `malloc`, yang rentan kesalahan.
    
- Kesalahan seperti `delete` tipe yang salah bisa dicegah di compile-time.
    
<br/>

### 3. 🚫 Anti-Memory Leak

- Tidak ada risiko **lupa `delete`** atau **`delete` dua kali**.
    
- `unique_ptr` memastikan hanya ada **satu pemilik** untuk setiap resource.
    
### 4. 💨 Zero-overhead Abstraction

- Meski `unique_ptr` adalah smart pointer, performanya **setara pointer mentah**.
    
- Compiler bisa mengoptimasi `unique_ptr` sebaik mungkin, tanpa beban runtime ekstra.
    
- Memanfaatkan fitur **inline destructor**, **move semantics**, dan **template instantiation**.

### 5. 🧼 Kode Lebih Bersih dan Ringkas

- Dengan `std::make_unique`, kita tak perlu `new`, tak perlu menyebut tipe dua kali, dan tak perlu `delete`.
    
- Mengurangi kode "boilerplate" dan menghindari bug akibat `manual memory management`.
    

```cpp
// Lebih aman dan singkat
auto ptr = std::make_unique<MyClass>();

// Lebih berisiko dan verbose
std::unique_ptr<MyClass> ptr(new MyClass());
// Jika lupa delete → memory leak!
```

### 6. 🛡️ Move-Only = Ownership Jelas

- `unique_ptr` **tidak bisa disalin**, hanya bisa dipindahkan (`std: :move`).
    
- Ini mencegah **kepemilikan ganda** dan kesalahan yang sulit dilacak.
    
- Sangat ideal untuk struktur data seperti **tree**, **graph**, **linked list**, atau **resource handler**.
    
### 7. ⚙️ Fleksibel tapi Aman

- Dapat digunakan dengan **custom deleter** jika kamu perlu menghapus resource non-memori (misalnya `fclose`, `close`, `sqlite3_close`, dll).
    
- Mendukung operasi pointer dasar (`get()`, `reset()`, `release()`) tapi tetap dalam kontrol penuh.

### 8. 🌪️ Exception-Safe

- Saat alokasi terjadi melalui `make_unique`, jika constructor melempar exception, tidak akan terjadi memory leak.
    
- Bandingkan dengan ini:
    

```cpp
auto p = std::unique_ptr<T>(new T(args)); // ❌ jika new sukses, tapi constructor T lempar exception → leak
auto p = std::make_unique<T>(args);       // ✅ aman dari leak
```

---

### 📌 Kesimpulan Akhir

`std::unique_ptr` + `std::make_unique` adalah:

- **Aman** (tidak ada leak, tidak ada `delete` ganda)
    
- **Efisien** (zero overhead, seperti pointer biasa)
    
- **Modern & Bersih** (menurunkan beban programmer)
    
- **Standar Praktik Terbaik** dalam C++ modern


`unique_ptr` membuat hidup programmer C++ lebih aman dan nyaman dalam mengelola memori. Ia adalah langkah pertama dalam menggantikan pointer mentah (`T*`) dengan gaya modern C++ yang lebih aman dan efisien.

Mereka adalah **cara paling direkomendasikan** untuk mengelola resource di C++—baik untuk belajar, produksi, maupun sistem besar.

Kalau kamu sedang menulis kode C++ dan masih menggunakan `new` dan `delete` secara manual, sekarang saatnya **beralih ke smart pointer**.

---
## Apakah `unique_ptr` cocok digunakan pada tree?
Ya, `std::unique_ptr` sangat cocok digunakan untuk tree — bahkan ini adalah salah satu kasus penggunaan paling ideal dari `unique_ptr` dalam C++ modern. Mari kita bahas alasannya secara menyeluruh:

Mengapa `unique_ptr` Cocok untuk Tree?

### 1. 🔒 Kepemilikan Tunggal (Exclusive Ownership)

- Dalam pohon (tree), setiap **node** hanya dimiliki oleh **satu parent**.
    
- Ini sesuai dengan sifat `unique_ptr` yang hanya mengizinkan **satu pemilik** terhadap suatu objek.
    

> Tidak ada dua parent yang boleh memiliki node anak yang sama — `unique_ptr` menjamin ini secara otomatis.

<br/>

### 2. 🧹 Otomatisasi Penghapusan (Automatic Deletion)

- Saat root tree (misalnya `unique_ptr<Node> root`) keluar dari scope, semua anak-anak node akan otomatis dihapus berurutan karena destructor `Node` akan menghapus `left` dan `right`.
    
- Tidak perlu `delete` manual untuk setiap node.
<br/>
### 3. ⚙️ Cocok untuk Struktur Rekursif

- Pohon bersifat rekursif (setiap node bisa punya subtree).
    
- `unique_ptr` bisa digunakan secara rekursif dalam struct Node:
    

```cpp
struct Node {
    int data;
    std::unique_ptr<Node> left, right;
    Node(int val) : data(val) {}
};
```

<br/>

### 4. 💥 Exception-safe

- Jika saat pembuatan node terjadi exception, memori tetap akan dibersihkan otomatis oleh `unique_ptr`.
    
- Tidak perlu `try-catch` manual untuk menghindari memory leak.
    

---

### ✅ Contoh Sederhana Tree dengan `unique_ptr`

```cpp
#include <iostream>
#include <memory>
using namespace std;

struct Node {
    int data;
    unique_ptr<Node> left, right;

    Node(int data) : data(data) {}

    void insert(int val) {
        if (val < data) {
            if (left) left->insert(val);
            else left = make_unique<Node>(val);
        } else {
            if (right) right->insert(val);
            else right = make_unique<Node>(val);
        }
    }

    void inorder() const {
        if (left) left->inorder();
        cout << data << " ";
        if (right) right->inorder();
    }
};

int main() {
    unique_ptr<Node> root = make_unique<Node>(10);
    root->insert(5);
    root->insert(15);
    root->insert(12);

    root->inorder();  // Output: 5 10 12 15
}
```

---

#### ❗ Catatan:

- Jangan gunakan `raw pointer` seperti `Node* left, right` dan `new Node(...)` jika kamu ingin manfaat penuh `RAII`.
    
- Jangan gunakan `shared_ptr` untuk tree, **kecuali** node bisa dimiliki oleh lebih dari satu induk (misal: graph atau DAG).
    

---

### 📌 Kesimpulan

|Alasan|Penjelasan|
|---|---|
|Kepemilikan tunggal|Sesuai dengan sifat pohon|
|Destruksi otomatis|Semua node akan otomatis dihapus dari bawah ke atas|
|Aman dari memory leak|Tidak perlu manual `delete`|
|Elegan dan modern|Mendorong praktik terbaik C++|
|Efisien|Tanpa overhead runtime tambahan|

`unique_ptr` adalah cara terbaik untuk membangun **binary tree**, **n-ary tree**, **expression tree**, dan sejenisnya, jika kamu ingin **aman, modern, dan efisien**.

---
## Contoh lain penggunaan `unique_ptr`

Berikut adalah contoh **penggunaan `std::unique_ptr` dalam struktur tree** lengkap dengan beberapa **member function penting** seperti insert, inorder traversal, pencarian nilai, dan hitung jumlah node:


```cpp
#include <iostream>
#include <memory>
using namespace std;

struct Node {
    int data;
    unique_ptr<Node> left, right;

    Node(int data) : data(data) {}

    // Menyisipkan nilai baru ke dalam BST
    void insert(int val) {
        if (val < data) {
            if (left) left->insert(val);
            else left = make_unique<Node>(val);
        } else {
            if (right) right->insert(val);
            else right = make_unique<Node>(val);
        }
    }

    // Traversal inorder
    void inorder() const {
        if (left) left->inorder();
        cout << data << " ";
        if (right) right->inorder();
    }

    // Mencari nilai di dalam tree
    bool search(int val) const {
        if (data == val) return true;
        if (val < data && left) return left->search(val);
        if (val > data && right) return right->search(val);
        return false;
    }

    // Menghitung jumlah node
    int countNodes() const {
        int leftCount = left ? left->countNodes() : 0;
        int rightCount = right ? right->countNodes() : 0;
        return 1 + leftCount + rightCount;
    }
};

int main() {
    unique_ptr<Node> root = make_unique<Node>(50);
    root->insert(30);
    root->insert(70);
    root->insert(20);
    root->insert(40);
    root->insert(60);
    root->insert(80);

    cout << "Inorder Traversal: ";
    root->inorder(); // Output: 20 30 40 50 60 70 80
    cout << "\n";

    cout << "Search 60: " << (root->search(60) ? "Found" : "Not Found") << "\n";
    cout << "Search 99: " << (root->search(99) ? "Found" : "Not Found") << "\n";

    cout << "Total Nodes: " << root->countNodes() << "\n";

    return 0;
}
```

###  Penjelasan Singkat

|Fungsi|Deskripsi|
|---|---|
|`insert()`|Menambahkan elemen baru ke posisi yang tepat sesuai aturan BST|
|`inorder()`|Menampilkan elemen tree dalam urutan menaik|
|`search()`|Mencari apakah suatu nilai ada di tree|
|`countNodes()`|Menghitung jumlah total node dalam tree|

###  Kenapa `unique_ptr` Digunakan?

- **Otomatis hapus** node saat keluar dari `main()`, tanpa perlu `delete`.
    
- **Tidak perlu raw pointer** seperti `Node*` → lebih aman.
    
- **Tidak ada memory leak** karena semua node dikelola oleh smart pointer.
    


## Kesimpulan Penggunaan `unique_ptr` pada Tree

### 🧠 Konsep Inti

- Tree adalah struktur hierarki di mana **setiap node hanya dimiliki oleh satu parent**.
    
- `std::unique_ptr` sangat sesuai karena sifatnya **eksklusif** (tidak bisa disalin, hanya bisa dipindahkan).
    
- Dengan `unique_ptr`, manajemen memori menjadi **otomatis, aman, dan bersih**.
    

### 🎯 Keuntungan

| Keuntungan                | Penjelasan                                                                 |
| ------------------------- | -------------------------------------------------------------------------- |
| ✅ Kepemilikan Tunggal | Setiap node hanya punya satu pemilik, sesuai dengan sifat tree             |
| 🔁 Rekursif & Modular | Tree dengan `unique_ptr` dapat disusun secara rekursif tanpa manual delete |
| 🧹 Otomatis Dealokasi | Saat root dihapus, seluruh subtree otomatis dibersihkan                    |
| 💥 Exception-safe     | Tidak perlu khawatir tentang memory leak jika terjadi error/throw          |
| 🧪 Type-safe & Modern | Tidak perlu cast atau raw pointer — kode lebih bersih dan aman             |
| 🛠️ Zero-overhead     | Performa sebanding dengan pointer biasa — dioptimasi saat kompilasi        |


### 🚫 Kekurangan atau Bukan Kasus Ideal

|Kekurangan / Catatan|Penjelasan|
|---|---|
|🚫 Tidak bisa disalin|Kamu harus memahami `std::move()` untuk memindahkan ownership|
|🚫 Tidak cocok untuk Graph|Jika node bisa punya banyak parent, gunakan `shared_ptr`|
|⚠️ Tidak cocok untuk pool|Jika manajemen memori dilakukan secara terpusat (misal: memory pool)|

---

### 💡 Penggunaan Ideal

- Struktur rekursif seperti:
    
    - Binary Tree
        
    - AVL Tree
        
    - Expression Tree
        
- Sistem di mana:
    
    - Setiap node **tidak dibagikan ke lebih dari satu induk**
        
    - Kamu ingin manajemen memori **otomatis tanpa `delete` manual**
        

---

### 📌 Ringkasan Singkat

> **Gunakan `unique_ptr` untuk membangun tree jika:**
> 
> - Kamu ingin memori dikelola otomatis
>     
> - Setiap node dimiliki satu entitas (bukan dibagikan)
>     
> - Kamu ingin kode lebih bersih, modern, dan bebas memory leak
>     

---

Kalau kamu membangun **tree yang "hidup sendiri-sendiri" tanpa perlu saling berbagi node**, `unique_ptr` adalah **solusi paling tepat dan idiomatik** dalam C++.

# Catatan Penulis
Menggunakan metode `unique_ptr` lebih disarankan untuk algoritma tree. Dibandingkan dengan menggunakan `malloc` dan juga `new`, apalagi `shared_ptr`, metode ini lebih tepat dan cocok.

Aku sendiri lebih suka dan terbiasa menyelesaikan soal dengan metode `unique_ptr`. Oleh karena itu, beberapa soal yang aku selesaikan, kebanyakan menggunakan metode `unique_ptr`. Apalagi metode ini menawarkan penanganan memory yang lebih baik dan cerdas, tanpa perlu khawatir akan memory leak. 

Beberapa soal latihan pertama masih menggunakan metode `new`, karena aku masih baru belajar algoritma tree, sebelum aku pindah ke metode ini. 