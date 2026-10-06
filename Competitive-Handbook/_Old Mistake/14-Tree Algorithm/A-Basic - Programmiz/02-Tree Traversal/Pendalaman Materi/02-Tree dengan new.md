---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Tree dengan New
sumber: Google.com, AI
date_learned: 2025-06-30T16:24:00
tags:
  - tree-algorithm
---
Link Sumber: 

---
# Tree dengan new

## Apa Itu `new` di C++?

`new` adalah operator di C++ yang digunakan untuk mengalokasikan memori secara dinamis dan menginisialisasi objek di heap. Berbeda dengan `malloc` di C, `new` memanggil constructor objek dan memastikan inisialisasi berjalan dengan baik.

### Dasar Sintaks

```cpp
int* p = new int;          // alokasi int default (nilainya tidak ditentukan)
int* q = new int(5);       // alokasi int dengan nilai 5
double* r = new double[10]; // alokasi array 10 elemen
```

### Karakteristik `new`

|Karakteristik|Penjelasan|
|---|---|
|Mengalokasikan di heap|Memory hidup hingga `delete` dipanggil|
|Memanggil constructor|Pada objek, `new` otomatis memanggil constructor-nya|
|Mengembalikan pointer|Hasil dari `new` adalah pointer ke tipe yang diminta|
|Bisa alokasi array|Gunakan `new T[n]` untuk membuat array dinamis|
|Harus di-`delete`|Wajib `delete` (untuk 1 objek) atau `delete[]` (untuk array) agar tidak leak|


### Contoh Penggunaan

#### Alokasi variabel tunggal

```cpp
int* p = new int;       // tidak diinisialisasi (garbage value)
int* q = new int(42);   // nilai awal 42

cout << *q << "\n";     // output: 42
```

#### Alokasi array

```cpp
int* arr = new int[5]; // alokasi 5 integer

for(int i = 0; i < 5; ++i) arr[i] = i * 10;
```

#### Menghapus memori

```cpp
delete p;
delete q;
delete[] arr;
```


### Kelebihan `new` dibanding `malloc`

|Fitur|`malloc`|`new`|
|---|---|---|
|Alokasi memori|✅|✅|
|Memanggil constructor|❌|✅|
|Harus cast tipe|✅|❌|
|Dapat overload|❌|✅ (operator new)|
|Ekspresi lebih aman|❌|✅ (type-safe)|


### Kesalahan Umum

|Kesalahan|Penjelasan & Contoh|
|---|---|
|Lupa `delete`|Akan menyebabkan **memory leak**|
|`delete[]` vs `delete`|Untuk array harus `delete[] arr`, bukan `delete arr`|
|Gunakan pointer setelah delete|UB (undefined behavior)|
|Alokasi terus di loop|Tanpa `delete` akan membanjiri heap|


### Advanced: Overloading Operator `new`

Kamu bisa mendefinisikan cara khusus bagaimana objek dialokasikan:

```cpp
void* operator new(size_t size) {
    cout << "Custom new called\n";
    return malloc(size);
}
```


### Variasi `new` Lainnya

|Bentuk|Fungsi|
|---|---|
|`new T`|Alokasi satu objek|
|`new T[n]`|Alokasi array objek|
|`new (std::nothrow) T`|Tidak melempar exception saat gagal alokasi|
|`new T(args...)`|Memanggil constructor dengan argumen|
|Placement new `new (ptr) T`|Menempatkan objek di lokasi yang sudah dialokasikan|


### Catatan Tambahan

- **`new` melempar exception (`std: :bad_alloc`) jika gagal**, kecuali pakai `std::nothrow`.
    
- Jika sudah mulai menggunakan `new`, sebaiknya mulai transisi ke **`std::unique_ptr`** atau **`std::shared_ptr`** untuk manajemen otomatis memori.
    
- Untuk array objek yang memiliki destructor, pastikan selalu gunakan `delete[]`.
    


### Kesimpulan

`new` di C++ adalah pengganti `malloc` yang lebih **aman, elegan, dan idiomatik**, karena:

- Memanggil constructor secara otomatis
    
- Type-safe (tidak perlu casting)
    
- Bisa digunakan untuk polymorphism dan alokasi objek kompleks
    
- Tapi tetap **harus diikuti dengan `delete`** untuk menghindari memory leak

---

## Apakah bisa menggunakan `new` pada tree

🔷 **Ya, tentu saja!**  

Kamu **bisa dan sangat umum** menggunakan `new` untuk membangun **binary tree** (atau jenis tree lain) di C++. Bahkan sebelum `smart pointer` populer, `new` adalah metode utama untuk membuat node-node dalam tree.

### Kenapa `new` Cocok untuk Tree?

Karena setiap node tree biasanya:

- Dibuat satu per satu
    
- Disimpan sebagai **pointer** ke node anak (left & right)
    
- Perlu dikelola secara **dinamis di heap**
    

Dan itulah fungsi utama dari `new`.

### Contoh Sederhana: Tree dengan `new`

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);

    // Traversal singkat
    cout << root->left->right->data << "\n"; // output: 7

    // Jangan lupa delete semua node nanti!
}
```


### ❗ Penting: `delete` Manual Diperlukan

Karena `new` mengalokasikan di heap, kamu **wajib menghapus node satu per satu** (biasanya rekursif):

```cpp
void deleteTree(Node* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}
```


### Perbandingan: `malloc` vs `new` vs `unique_ptr`

|Hal|`malloc`|`new`|`unique_ptr`|
|---|---|---|---|
|Memanggil constructor|❌|✅|✅|
|Type-safe|❌|✅|✅|
|Memory management|Manual (`free`)|Manual (`delete`)|Otomatis (RAII)|
|Rawan memory leak|✅|✅|❌|


### Kesimpulan

- ✅ **`new` bisa dan sangat lazim digunakan untuk tree**
    
- 👍 Praktis dan cocok untuk implementasi manual
    
- ❗ Harus hati-hati dengan `delete` untuk setiap node agar tidak terjadi memory leak
    
- 💡 Untuk proyek besar atau modern, lebih baik pakai `unique_ptr` agar aman dan otomatis
    

---
## Destructor untuk `new` pada tree

### Tujuan

Dengan menambahkan **destructor** ke dalam struct/class `Node`, maka saat kita `delete` root-nya saja, semua node anak akan otomatis ikut dihapus.

### Implementasi Tree dengan Destructor

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) : data(val), left(nullptr), right(nullptr) {}

    // Destructor (rekursif)
    ~Node() {
        delete left;
        delete right;
        cout << "Deleted node: " << data << "\n";
    }
};

int main() {
    // Membangun tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);

    // Saat root di-delete, semua node anak otomatis terhapus
    delete root;

    return 0;
}
```

### Penjelasan

- `~Node()` adalah **destructor**, dipanggil otomatis saat `delete` dijalankan.
    
- `delete left;` dan `delete right;` akan memanggil destructor anak, lalu anak dari anak, dst.
    
- Maka hanya dengan `delete root;`, seluruh tree terhapus dengan benar.
    
- Output:
    
    ```
    Deleted node: 3
    Deleted node: 7
    Deleted node: 5
    Deleted node: 20
    Deleted node: 10
    ```
    


### Catatan Penting

- Jangan gunakan destructor seperti ini jika kamu **berbagi pointer** ke node yang sama dari dua tempat berbeda (karena bisa double free).
    
- Tapi kalau struktur tree kamu adalah **binary tree biasa** dan tiap node dimiliki hanya oleh satu parent, ini **sangat aman** dan efisien.
    

---
## Contoh lain penggunaan `new` pada tree
Berikut contoh implementasi **binary search tree** sederhana di C++ menggunakan `new` untuk alokasi, lengkap dengan **destructor** dan beberapa **member function** (insert, search, inorder traversal, height, countNodes):

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) : data(val), left(nullptr), right(nullptr) {}

    // Destructor: rekursif delete children
    ~Node() {
        delete left;
        delete right;
    }

    // Insert value ke subtree ini (BST property)
    void insert(int val) {
        if (val < data) {
            if (left) left->insert(val);
            else left = new Node(val);
        } else {
            if (right) right->insert(val);
            else right = new Node(val);
        }
    }

    // Cari apakah sebuah nilai ada di subtree ini
    bool search(int val) const {
        if (val == data) return true;
        else if (val < data) return left  ? left->search(val) : false;
        else return right ? right->search(val) : false;
    }

    // Inorder traversal: kiri → akar → kanan
    void inorder() const {
        if (left)  left->inorder();
        cout << data << " ";
        if (right) right->inorder();
    }

    // Hitung jumlah seluruh node di subtree
    int countNodes() const {
        int cnt = 1;
        if (left)  cnt += left->countNodes();
        if (right) cnt += right->countNodes();
        return cnt;
    }

    // Hitung tinggi subtree (daun = level 0)
    int height() const {
        int hl = left  ? left->height() : 0;
        int hr = right ? right->height() : 0;
        return 1 + max(hl, hr);
    }
};

int main() {
    // Buat root
    Node* root = new Node(50);

    // Insert beberapa nilai
    int values[] = {30, 20, 40, 70, 60, 80};
    for (int v : values) {
        root->insert(v);
    }

    // Gunakan member function
    cout << "Inorder traversal: ";
    root->inorder();
    cout << "\n";

    cout << "Search 40: " << 
    (root->search(40) ? "found" : "not found") << "\n";
    
    cout << "Search 25: " << 
    (root->search(25) ? "found" : "not found") << "\n";

    cout << "Total nodes: " << root->countNodes() << "\n";
    cout << "Tree height : " << root->height() << "\n";

    // Hapus seluruh tree (memanggil destructor rekursif)
    delete root;
    return 0;
}
```

**Penjelasan singkat member function**

- `insert(int)`: tambahkan node baru sesuai aturan BST (kiri < data < kanan)
    
- `search(int)`: DFS untuk menemukan nilai, return `true` jika ketemu
    
- `inorder()`: cetak semua node terurut (ascending)
    
- `countNodes()`: hitung total node di subtree
    
- `height()`: kedalaman maksimal subtree, daun beri tinggi 1
    

Karena kita menaruh `delete left; delete right;` di dalam `~Node()`, **memanggil `delete root;`** akan otomatis membersihkan semua node di tree, tanpa perlu fungsi delete terpisah.

## Kesimpulan menggunakan `new` pada tree

1. **Alokasi Dinamis di Heap**
    
    - `new T` dan `new T(args…)` mengalokasikan memori untuk satu objek T dan memanggil konstruktornya.
        
    - `new T[n]` mengalokasikan array berukuran n dan memanggil konstruktor default untuk tiap elemen.
	<br/>
2. **Tipe Pointer-Safe**
    
    - Hasil `new` adalah pointer `T*`; tidak perlu casting seperti di `malloc`.
        
    - Jika alokasi gagal, `new` akan melempar `std::bad_alloc` (kecuali pakai `std: :nothrow`).
    <br/>
3. **Konstruksi & Destruksi Otomatis**
    
    - Objek yang dialokasikan dengan `new` otomatis menjalankan konstruktor.
        
    - Harus dipasangkan dengan `delete` (atau `delete[]` untuk array) agar memanggil destruktor dan membebaskan memori.
     <br/>
4. **Manajemen Memori Manual**
    
    - **Wajib** memanggil `delete ptr;` untuk tiap `ptr = new T`.
        
    - Untuk array, gunakan `delete[] arr;`.
        
    - Lupa `delete` = memory leak; delete berlebih atau salah tipe = undefined behavior.
       <br/>
5. **Overload & Customization**
    
    - Kamu bisa overload `operator new`/`operator delete` untuk strategi alokasi khusus (misalnya arena allocator).
        
    - Tersedia _placement new_ (`new (addr) T`) untuk membangun objek di lokasi memori yang sudah ada.
      <br/>
6. **Keunggulan vs `malloc`**
    
    - **Memanggil konstruktor** → objek siap dipakai.
        
    - **Type-safe** → bebas casting.
        
    - **Bebas dari C-style void***.
       <br/>
7. **Langkah Berikutnya**
    
    - Untuk keamanan dan kemudahan RAII, pertimbangkan **`std::unique_ptr`** atau **`std::shared_ptr`** ketimbang raw pointer.
        
    - `new` masih berguna untuk alokasi manual, tapi smart pointer akan mengurangi risiko leak dan double-free.
    <br/>


Dengan memahami poin-poin di atas, kamu dapat menggunakan `new` secara efektif dan aman dalam proyek C++ modern.

# Catatan Penulis

Menggunakan `new` untuk membuat node bisa jauh lebih baik daripada menggunakan `malloc`. Beberapa alasan dan praktik yang bisa dicatat:

1. **Pemanggilan Konstruktor Otomatis**  
    Dengan `new`, setiap objek `Node` akan menjalankan konstruktor-nya sendiri, sehingga semua inisialisasi (misalnya mengatur `data`, `left = nullptr`, `right = nullptr`) terjadi secara otomatis. Sebaliknya, `malloc` hanya menyediakan blok memori mentah tanpa menjalankan konstruktor, sehingga kamu harus menulis kode inisialisasi secara manual, rentan lupa, dan mudah menimbulkan bug.
<br/>
2. **Type Safety & Readability**  
    `new Node(value)` langsung mengembalikan `Node*` tanpa perlu cast, membuat kode lebih bersih dan meminimalkan kesalahan cast. Sementara `malloc` mengembalikan `void*` yang wajib dicast, menambah kerumitan dan mengurangi keterbacaan.
<br/>
3. **Exception Safety**  
    Jika alokasi gagal, `new` akan melempar `std::bad_alloc`, memudahkan penanganan kesalahan di tingkat yang lebih tinggi (try–catch). Sebaliknya, `malloc` hanya mengembalikan `NULL`, dan jika tidak diperiksa, bisa menyebabkan segfault.
<br/>
4. **Destruksi Otomatis lewat Destructor**  
    Dengan mendefinisikan destructor pada `Node`, memanggil `delete root;` akan secara rekursif menghapus seluruh subtree, memanggil destructor pada setiap node, dan memastikan semua sumber daya dilepaskan dengan benar. Pendekatan ini jauh lebih aman daripada melepas memori satu per satu dengan `free`, yang harus dilakukan secara manual dan rentan terlewat.
<br/>
5. **Integrasi dengan Smart Pointer**  
    Setelah memindahkan alokasi ke `new`, langkah natural selanjutnya adalah menggunakan `std::unique_ptr<Node>` atau `std::shared_ptr<Node>`. Ini membawa keuntungan RAII (Resource Acquisition Is Initialization)—hak milik memori diatur secara otomatis, mencegah memory leak tanpa perlu memanggil `delete` manual.
<br/>
6. **Konsistensi Gaya Modern C++**  
    Penggunaan `new` (dan smart pointer) sejalan dengan idiom C++ modern, memanfaatkan fitur bahasa (constructor/destructor, exception) secara penuh. Ini membuat kode tree menjadi lebih maintainable, mudah diuji, dan siap dikembangkan untuk fitur-fitur lanjutan—misalnya balancing (AVL/Red‑Black), serialization, atau multi‑threaded access.
<br/>

---

> **Tip Praktis**  
> Setelah beralih ke `new`, segera adaptasikan smart pointer:
> 
> ```cpp
> std::unique_ptr<Node> root = std::make_unique<Node>(10);
> ```
> 
> Dengan begitu, kamu sekaligus menghilangkan kebutuhan `delete` dan menambahkan lapisan keamanan memori otomatis.