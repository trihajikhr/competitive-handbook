---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Tree dengan shared_ptr
sumber: Google.com, AI
date_learned: 2025-06-30T17:56:00
tags:
  - tree-algorithm
---
Link Sumber: 

---
# Tree dengan shared_ptr
## Apa itu `shared_ptr`?
`std::shared_ptr` adalah **smart pointer di C++** yang memungkinkan banyak pointer bersama-sama memiliki satu objek. Berbeda dengan `unique_ptr` yang punya kepemilikan tunggal, `shared_ptr` digunakan saat kamu ingin berbagi kepemilikan terhadap objek yang sama.

### 1 | Analogi Singkat (Padat dan Cepat)

 Bayangkan `shared_ptr` seperti **remote TV universal**:  Banyak orang bisa punya remote yang mengontrol TV yang sama. TV hanya akan mati jika semua remotnya hilang atau dimatikan.
### 2 | Analogi Naratif (Ceritanya Mengalir)

Bayangkan kamu dan dua temanmu menyewa satu **rumah kontrakan** bersama.  
Ketiganya memegang **kunci asli rumah**—bukan salinan, tapi benar-benar sama-sama pemilik rumah itu.

Selama **masih ada satu orang** yang menempati rumah (masih memegang kunci), rumah itu **tetap ada dan aktif**. Tapi begitu **semua orang pindah** dan menyerahkan kunci, **rumah itu dikosongkan dan dibongkar otomatis**.

Nah, `shared_ptr` bekerja seperti itu:

- Selama masih ada yang “memegang kunci” (alias ada `shared_ptr` yang menunjuk ke objek), objek itu tetap hidup.

- Tapi begitu semua `shared_ptr` yang menunjuk ke objek dihancurkan atau di-reset, objeknya **langsung dihapus otomatis** — seperti rumah yang dibongkar karena semua penyewa pergi.

---
## Penjelasan Teknis
### 📌 Ciri Khas `shared_ptr`

- Memungkinkan **banyak pointer** menunjuk ke objek **yang sama**.
    
- Menggunakan **reference counter** internal (disebut `use_count`) untuk melacak berapa banyak `shared_ptr` yang aktif.
    
- Objek dihapus secara otomatis jika `use_count == 0`.

### 🔧 Deklarasi & Inisialisasi

```cpp
#include <memory>
std::shared_ptr<T> p1 = std::make_shared<T>(args...);
```

- Membuat objek `T` di heap menggunakan konstruktor `T(args...)`.
    
- Objek tersebut akan **secara otomatis dimusnahkan** saat semua `shared_ptr` yang mengelolanya telah dihancurkan.

### 🔄 Operasi Dasar

|Operasi|Keterangan|
|---|---|
|`make_shared<T>(...)`|Membuat objek `T` di heap dan dikemas dalam `shared_ptr<T>`|
|`shared_ptr<T> p2 = p1`|Menyalin kepemilikan → `use_count` bertambah|
|`p.use_count()`|Mengembalikan jumlah pemilik aktif (reference count)|
|`p.reset()`|Menghentikan kepemilikan → `use_count` berkurang|
|`p.get()`|Mengembalikan raw pointer ke objek yang dikelola|
|`p == nullptr`|Mengecek apakah pointer tidak mengelola objek|
|`p.unique()`|True jika hanya ada satu pemilik (`use_count() == 1`)|

### 🧹 Destruksi Otomatis

Saat semua `shared_ptr` ke objek tertentu dihancurkan atau di-reset, maka:

- `use_count == 0`
    
- Objek dihapus otomatis dengan `delete`
    
- **Tidak perlu panggil `delete` manual**

### ⚠️ Potensi Masalah: Reference Cycle

Jika dua `shared_ptr` saling menunjuk, seperti pada struktur graf atau linked list melingkar, maka:

- `use_count` **tidak pernah nol**
    
- **Memory leak bisa terjadi**
    

💡 **Solusi:** Gunakan `std::weak_ptr` untuk memutus siklus tersebut.

### 🎯 Kasus Penggunaan Ideal

- Objek yang dimiliki oleh **banyak bagian program secara bersamaan**
    
- Sistem **Observer**, **Callback**, atau **Signal-Slot**
    
- Struktur data seperti **graph**, **DAG**, atau struktur melingkar
    
- Ketika **kepemilikan bersama** dibutuhkan dan kamu **tidak bisa memastikan siapa yang delete**
    


### Keunggulan `shared_ptr`

|Keunggulan|Penjelasan|
|---|---|
|✅ Otomatis dikelola|Tidak perlu manual `delete`|
|🔢 Reference counted|Objek hanya dihapus saat tidak dipakai lagi|
|🔄 Bisa disalin|Mendukung salin dan operasikan seperti pointer biasa|
|🛠️ Cocok untuk graph|Bisa berbagi node tanpa kepemilikan tunggal seperti `unique_ptr`|


### ❗ Kelemahan `shared_ptr`

|Kelemahan|Penjelasan|
|---|---|
|🐢 Sedikit overhead|Karena harus menyimpan dan mengatur reference counter|
|🔁 Risiko memory leak|Bisa terjadi jika reference cycle dibiarkan|
|❌ Kurang cocok untuk tree|Tree cocoknya `unique_ptr` karena tidak butuh berbagi kepemilikan|

---

##  Contoh Sederhana


```cpp
#include <iostream>
#include <memory>
using namespace std;

int main() {
    auto p1 = make_shared<int>(100);  // 1. Buat shared_ptr p1, ref count = 1
    auto p2 = p1;                     // 2. Salin shared_ptr p1 ke p2, ref count = 2

    cout << "Value: " << *p1 << ", Use count: " << p1.use_count() << endl;

    p1.reset();                      // 3. Hapus kepemilikan dari p1, ref count = 1 (masih ada p2)
    cout << "After reset p1, Use count: " << p2.use_count() << endl;

    return 0; // 4. Saat keluar scope, p2 dihancurkan, ref count jadi 0 -> delete otomatis
}
```

### 🧠 Penjelasan:

#### 🔹 `make_shared<int>(100)`

- Mengalokasikan `int` bernilai `100` di heap.
    
- `p1` mengelola objek ini.
    
- Reference count = **1**
    

#### 🔹 `auto p2 = p1`

- `p2` juga menunjuk ke objek yang sama.
    
- Sekarang ada dua `shared_ptr` (`p1`, `p2`) → reference count = **2**
    

#### 🔹 `p1.reset()`

- `p1` berhenti menjadi pemilik → reference count turun menjadi **1**
    
- Objek belum dihapus karena `p2` masih aktif.
    

#### 🔹 Saat keluar dari `main()`

- `p2` keluar dari scope → ref count = 0 → objek `100` dihapus secara otomatis (`delete` dipanggil)

### 🖨️ Output Program:

```
Value: 100, Use count: 2
After reset p1, Use count: 1
```

### 🧾 Ringkasan:

|Pointer|Status Awal|Setelah `reset()`|Keluar `main()`|
|---|---|---|---|
|`p1`|Aktif|Direset (null)|Sudah null|
|`p2`|Aktif|Tetap aktif|Dihapus → delete|

> Program ini mendemonstrasikan **manajemen otomatis memori** oleh `shared_ptr`, serta bagaimana reference count bekerja untuk menghapus objek secara otomatis hanya ketika **semua pemiliknya pergi**.

---
##  Apa Itu `std::weak_ptr`?

`std::weak_ptr` adalah smart pointer di C++ yang **tidak ikut memiliki** objek yang dikelola oleh `std::shared_ptr`, tetapi **mengamati saja**.

> Ia **tidak menambah reference count**, sehingga **tidak mencegah objek dihapus**.

### 🔌 Analogi Singkat

> Bayangkan `shared_ptr` seperti **pemegang kunci rumah kontrakan**:  
> Rumah tetap ada selama ada pemilik.

> Nah, `weak_ptr` seperti **tetangga yang tahu rumah itu ada**, tapi **tidak punya kunci**.  
> Jika semua pemilik pindah, rumahnya tetap akan **dibongkar**, dan tetangga itu akan sadar kalau rumahnya sudah **tidak ada**.

### 📌 Tujuan Utama

Menghindari **reference cycle (siklus referensi)** yang bisa menyebabkan **memory leak** saat dua objek saling menunjuk via `shared_ptr`.

### ⚙️ Cara Kerja `weak_ptr`

- **Dibuat dari shared_ptr**:
    
    ```cpp
    shared_ptr<int> p = make_shared<int>(42);
    weak_ptr<int> wp = p;  // wp tidak menambah use_count
    ```
    
- **Tidak bisa langsung di-dereference**  
    (tidak bisa pakai `*wp` langsung).
    
- Untuk mengakses nilainya, **ubah jadi shared_ptr dulu**:
    
    ```cpp
    if (auto sp = wp.lock()) {
        // Aman digunakan
        cout << *sp << endl;
    }
    ```
    
### 💡 Fungsi Utama

|Fungsi|Deskripsi|
|---|---|
|`lock()`|Mengembalikan `shared_ptr` jika objek masih hidup, atau `nullptr` jika tidak|
|`expired()`|Mengecek apakah objek sudah dihapus (`true` jika sudah hilang)|
|`use_count()`|Mengakses jumlah `shared_ptr` aktif|
|`reset()`|Melepaskan referensi|

### ✅ Contoh Program Sederhana

```cpp
#include <iostream>
#include <memory>
using namespace std;

int main() {
    shared_ptr<int> sp = make_shared<int>(999);
    weak_ptr<int> wp = sp;  // Tidak menambah ref count

    cout << "use_count awal: " << sp.use_count() << "\n"; // = 1

    // Akses nilai melalui weak_ptr
    if (auto locked = wp.lock()) {
        cout << "Nilai: " << *locked << "\n"; // Aman
    }

    sp.reset();  // shared_ptr dihapus → objek dihapus

    // Coba akses lagi
    if (wp.expired()) {
        cout << "Objek sudah dihapus, weak_ptr kosong.\n";
    }

    return 0;
}
```

### 🖨️ Output:

```
use_count awal: 1
Nilai: 999
Objek sudah dihapus, weak_ptr kosong.
```


### 📍 Kapan Harus Pakai `weak_ptr`?

- Saat ingin **menghindari memory leak** karena **reference cycle** (misalnya: `A` menunjuk ke `B`, dan `B` balik menunjuk ke `A`)
    
- Untuk **cache**, **observer**, atau situasi di mana:
    
    - Objek **boleh hilang sewaktu-waktu**, dan
        
    - Kita **tidak ingin mencegah objek tersebut dihapus**
        

---
## Apakah bisa menggunakan `shared_ptr` untuk tree?
Ya, **bisa** menggunakan `std::shared_ptr` untuk membuat **struktur tree** di C++. Bahkan `shared_ptr` cocok dipakai jika:

### ✅ Kamu ingin:

- Node **dapat dimiliki lebih dari satu pihak**, misalnya untuk **graph** atau **DAG** (directed acyclic graph).
    
- **Berbagi kepemilikan** antar node atau modul — misalnya antara parent-child, atau antar subtree yang bisa berpindah tangan.

### 📌 Contoh Tree dengan `shared_ptr`

```cpp
#include <iostream>
#include <memory>
using namespace std;

struct Node {
    int data;
    shared_ptr<Node> left, right;

    Node(int val) : data(val) {}
};

int main() {
    shared_ptr<Node> root = make_shared<Node>(10);
    root->left = make_shared<Node>(5);
    root->right = make_shared<Node>(15);
    root->left->left = make_shared<Node>(3);
    root->left->right = make_shared<Node>(7);

    cout << "Root: " << root->data << endl;
    cout << "Left child: " << root->left->data << endl;
}
```

### 🧠 Tapi Hati-Hati:

Kalau kamu secara **tidak sengaja membuat reference cycle**, seperti:

- parent punya `shared_ptr` ke child,
    
- dan child juga punya `shared_ptr` ke parent,
    

💥 Maka objek **tidak akan pernah dihapus**, karena `use_count` **tidak pernah nol** → **memory leak**.

### 🔓 Solusinya:

Gunakan `std::weak_ptr` **untuk pointer balik (misalnya ke parent)** agar tidak membentuk siklus:

```cpp
struct Node {
    int data;
    shared_ptr<Node> left, right;
    weak_ptr<Node> parent;
};
```

### ✨ Kesimpulan

|🔍 Aspek|shared_ptr ✅|
|---|---|
|Tree dengan satu arah (parent → child)|Bisa dan aman|
|Tree dengan dua arah (child ↔ parent)|Harus hati-hati, gunakan `weak_ptr`|
|Otomatis hapus node saat tak dipakai|Ya|
|Butuh banyak salinan node|Ya|
|Risiko siklus referensi|Ada (hindari dengan `weak_ptr`)|

---
##  Contoh Tree: shared_ptr + weak_ptr (Child ↔ Parent)

Berikut contoh **struktur tree** menggunakan kombinasi `shared_ptr` (untuk **child**) dan `weak_ptr` (untuk **parent**) — agar **aman dari reference cycle**:

```cpp
#include <iostream>
#include <memory>
using namespace std;

struct Node {
    int data;
    shared_ptr<Node> left, right;
    weak_ptr<Node> parent;  // weak_ptr untuk menghindari reference cycle

    Node(int val) : data(val) {}

    void printInfo() {
        cout << "Node: " << data;
        if (auto p = parent.lock()) {
            cout << ", Parent: " << p->data;
        } else {
            cout << ", Parent: null";
        }
        cout << "\n";
    }
};

int main() {
    // Buat root
    shared_ptr<Node> root = make_shared<Node>(10);

    // Buat anak kiri dan kanan
    root->left = make_shared<Node>(5);
    root->right = make_shared<Node>(15);

    // Set parent ke root (pakai weak_ptr)
    root->left->parent = root;
    root->right->parent = root;

    // Tambahkan cucu
    root->left->left = make_shared<Node>(3);
    root->left->right = make_shared<Node>(7);
    root->left->left->parent = root->left;
    root->left->right->parent = root->left;

    // Cetak info
    root->printInfo();
    root->left->printInfo();
    root->left->left->printInfo();

    return 0;
}
```


### 🧾 Output:

```
Node: 10, Parent: null
Node: 5, Parent: 10
Node: 3, Parent: 5
```

### 🔍 Penjelasan:

- `shared_ptr` digunakan untuk child, karena mereka dikelola penuh oleh parent.
    
- `weak_ptr` digunakan untuk parent, karena kita tidak ingin menambah reference count dan menghindari memory leak.
    

### 🔁 Tanpa `weak_ptr`:

Jika kita pakai `shared_ptr` untuk parent, maka akan terbentuk **reference cycle**, dan `use_count` tidak akan pernah 0 → memori tidak akan dibebaskan otomatis.

### ✨ Manfaat Kombinasi Ini:

- Akses ke parent tetap bisa dilakukan (`parent.lock()`).
    
- Tidak ada kebocoran memori.
    
- Struktur tetap fleksibel dan modern.
    
## Contoh tree dengan `shared_ptr` + member function
Fungsi yang akan ditambahkan:

- `setLeft(int val)`
    
- `setRight(int val)`
    
- `setChild(int leftVal, int rightVal)`
    
- `isLeaf()`
    
- `depth()` (jarak dari root)
    
- `printPathFromRoot()`
    

Dan kita tetap gunakan:

- `shared_ptr<Node>` untuk anak,
    
- `weak_ptr<Node>` untuk parent.
    
### 🔧 Kode Lengkap:

```cpp
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

struct Node {
    int data;
    shared_ptr<Node> left, right;
    weak_ptr<Node> parent;

    Node(int val) : data(val) {}

    // Set anak kiri dan hubungkan parent
    shared_ptr<Node> setLeft(int val) {
        left = make_shared<Node>(val);
        left->parent = shared_from_this();
        return left;
    }

    // Set anak kanan dan hubungkan parent
    shared_ptr<Node> setRight(int val) {
        right = make_shared<Node>(val);
        right->parent = shared_from_this();
        return right;
    }

    // Set dua anak sekaligus
    shared_ptr<Node> setChild(int lval, int rval) {
        setLeft(lval);
        setRight(rval);
        return shared_from_this();
    }

    // Cek apakah node ini adalah daun
    bool isLeaf() const {
        return !left && !right;
    }

    // Hitung kedalaman node dari root
    int depth() const {
        int d = 0;
        auto p = parent.lock();
        while (p) {
            d++;
            p = p->parent.lock();
        }
        return d;
    }

    // Cetak path dari root ke node ini
    void printPathFromRoot() const {
        vector<int> path;
        auto curr = shared_from_this();
        while (curr) {
            path.push_back(curr->data);
            curr = curr->parent.lock();
        }
        // Dibalik
        for (auto it = path.rbegin(); it != path.rend(); ++it)
            cout << *it << " ";
        cout << "\n";
    }

    // Info singkat
    void printInfo() const {
        cout << "Node: " << data;
        if (auto p = parent.lock()) cout << ", Parent: " << p->data;
        else cout << ", Parent: null";
        cout << ", Depth: " << depth() << "\n";
    }

    // shared_from_this() harus bisa dipanggil → enable_shared_from_this
    // (lihat di bawah)
};

// Tambahkan inheritance agar bisa memanggil shared_from_this()
struct TreeNode : public Node, public enable_shared_from_this<TreeNode> {
    TreeNode(int val) : Node(val) {}
    shared_ptr<TreeNode> setLeft(int val) {
        left = make_shared<TreeNode>(val);
        left->parent = shared_from_this();
        return static_pointer_cast<TreeNode>(left);
    }

    shared_ptr<TreeNode> setRight(int val) {
        right = make_shared<TreeNode>(val);
        right->parent = shared_from_this();
        return static_pointer_cast<TreeNode>(right);
    }

    shared_ptr<TreeNode> setChild(int lval, int rval) {
        setLeft(lval);
        setRight(rval);
        return shared_from_this();
    }

    shared_ptr<TreeNode> getShared() {
        return shared_from_this();
    }
};

int main() {
    shared_ptr<TreeNode> root = make_shared<TreeNode>(100);
    auto left = root->setLeft(50);
    auto right = root->setRight(150);

    auto leftRight = left->setRight(75);
    leftRight->setLeft(60);

    root->printInfo();
    leftRight->printInfo();

    cout << "Path to 60:\n";
    leftRight->left->printPathFromRoot();

    return 0;
}
```

### 🧠 Catatan Penting

Karena kita memakai `shared_from_this()`, maka:

- Kita harus turunkan `Node` dari `enable_shared_from_this<T>`.
    
- Makanya kita buat `TreeNode` sebagai child dari `Node`, dan semua `make_shared` diarahkan ke `TreeNode`.
    

Kalau tidak, `shared_from_this()` akan menyebabkan undefined behavior.
### ✅ Output Contoh:

```
Node: 100, Parent: null, Depth: 0
Node: 75, Parent: 50, Depth: 2
Path to 60:
100 50 75 60 
```

## Kesimpulan `shared_ptr` untuk Tree

- `shared_ptr` memungkinkan **berbagi kepemilikan node**, cocok jika struktur tree atau graph memiliki banyak pihak yang mengakses node yang sama.
<br/>
- Tree dengan **arah satu** (parent → child) bisa dikelola sepenuhnya dengan `shared_ptr` tanpa masalah.
<br/>
- Jika tree memiliki **pointer balik** (child → parent), kamu **harus** menggunakan `weak_ptr` untuk mencegah **reference cycle** dan **memory leak**.
<br/>
- Otomatis menghapus node ketika tidak ada lagi yang mengakses (reference count = 0), sehingga manajemen memori tetap aman.
<br/>
- Dapat digunakan bersama dengan fitur C++ modern seperti `enable_shared_from_this`, `std::make_shared`, dan `reset()` untuk fleksibilitas dan keamanan yang lebih tinggi.
<br/>
- Sedikit lebih mahal dari `unique_ptr` karena ada **overhead reference counting**, tetapi jauh lebih aman untuk struktur kompleks.
<br/>

# Catatan Penulis
Walaupun `shared_ptr` tidak terlalu cocok untuk tantangan algoritma tree seperti di kompetisi atau sistem dengan batasan memori/kecepatan ketat—karena overhead dari reference counting—mengetahui cara kerjanya tetap berguna. Terutama untuk pengembangan aplikasi skala besar atau sistem yang butuh fleksibilitas manajemen memori otomatis. Kadang bukan soal efisiensi ekstrem, tapi soal menjaga kode tetap aman dan bebas dari bug memori.

Intinya, untuk tantangan algoritma tree, aku lebih nyaman menggunakan `unique_ptr` 😂.

—*Trihaji*