---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Penggunaan fungsi get() dalam chaining
sumber: chatgpt.com
date_learned: 2025-07-06T15:55:00
tags:
  - tree-algorithm
---
Link Sumber: 

---
# Penggunaan fungsi get() dalam chaining

> Apa kegunaan fungsi `get()`, dan kenapa penting dalam operasi chaining Node?

Pertanyaanmu mantap — karena memahami `get()` dari `unique_ptr` itu **fondasi penting** dalam pemrograman modern C++ saat berurusan dengan **smart pointers**.

---

## 🔍 Apa itu `get()`?

`get()` adalah fungsi anggota dari `std::unique_ptr<T>` yang:

- Mengembalikan pointer mentah (`T*`) ke objek yang dikelola
    
- Tidak memindahkan ownership
    
- Hanya memberikan akses sementara

### 🧠 Penjelasan Fungsi `get()` (dalam paragraf)

Fungsi `get()` adalah metode milik `std::unique_ptr` yang digunakan untuk **mengambil pointer mentah (raw pointer)** ke objek yang sedang dikelola, **tanpa memindahkan kepemilikan** atas objek tersebut. Artinya, kamu tetap bisa mengakses isi dari `unique_ptr` seolah-olah menggunakan pointer biasa, tetapi tanggung jawab memori **masih tetap dipegang oleh `unique_ptr`**. Ini sangat berguna ketika kamu ingin menggunakan fungsi atau operasi yang memerlukan `T*`, tetapi kamu tidak ingin kehilangan kontrol atau membuat salinan objek yang ada di `unique_ptr`.

### 🔧 Analogi sederhana

Bayangkan `unique_ptr` seperti **brankas pribadi** yang hanya kamu punya kunci satu-satunya. Di dalamnya ada dokumen penting (misalnya data node). Kalau kamu ingin **melihat isinya sebentar**, kamu bisa **mengintip melalui lubang kecil** di brankas — tapi kamu **tidak mengambil dokumennya keluar**. Fungsi `get()` inilah **lubang kecil** itu: kamu bisa melihat dan memakai isi di dalamnya, **tanpa mengeluarkan atau memindahkan dokumen tersebut** dari brankas. Brankas tetap memegang penuh isi tersebut.

### 💡 Dalam konteks chaining

Ketika kamu menulis `setLeft()` lalu ingin langsung melanjutkan ke `->setRight()`, kamu butuh **akses ke node kiri** yang baru dibuat. Di sinilah `get()` digunakan — ia memberimu pointer mentah ke node kiri, **tanpa mengambil alih kepemilikan dari `unique_ptr`**. Jadi kamu bisa lanjut chaining tanpa mengacaukan struktur pohonmu.

---

## 📌 Bentuk umum:

```cpp
std::unique_ptr<Node<T>> ptr = std::make_unique<Node<T>>(val);

Node<T>* raw = ptr.get(); 
// akses pointer mentah tanpa memengaruhi kepemilikan
```

### 🔍 Penjelasan baris demi baris:

#### 1. `std::unique_ptr<Node<T>> ptr = std::make_unique<Node<T>>(val);`

- Di sini kita membuat sebuah `unique_ptr` yang menunjuk ke objek baru `Node<T>`.
    
- `ptr` sekarang **memiliki penuh** objek `Node<T>` di heap — ia akan otomatis menghapusnya ketika keluar dari scope.

#### 2. `Node<T>* raw = ptr.get();`

- `get()` dipanggil untuk **mengambil pointer mentah (`Node<T>*`)** ke objek yang dikelola oleh `ptr`.
    
- **Penting:** Ini _tidak_ memindahkan atau mengambil alih kepemilikan — `ptr` tetap pemilik sah dari objek tersebut.
    
- `raw` hanyalah cara kita **mengakses** atau **mengoper objek itu ke fungsi lain** yang menerima `Node<T>*`.

### 💡 Kenapa ini penting?

1. Kadang kamu butuh akses ke objek dalam `unique_ptr`, misalnya untuk memanggil fungsi atau melakukan chaining.
    
2. Beberapa fungsi lama (atau API pihak ketiga) masih menggunakan `T*`, bukan smart pointer.
    
3. Dengan `get()`, kamu **tidak perlu mengganggu kepemilikan** yang sudah dikelola dengan aman oleh `unique_ptr`.
### ⚠️ Hati-hati: Jangan delete `raw`

Karena objek tersebut **masih dikelola oleh `unique_ptr`**, kamu **tidak boleh** memanggil `delete raw;`. Itu akan menyebabkan _double delete_ atau _undefined behavior_ saat `ptr` nanti ikut menghapusnya.

### ✅ Kesimpulan

`get()` digunakan ketika kamu butuh melihat atau menggunakan objek dalam `unique_ptr` seperti pointer biasa (`T*`), **tanpa mengubah siapa yang bertanggung jawab terhadap memori-nya.**

---


## 🧠 Kenapa `get()` penting dalam operasi chaining Node?

Di dalam implementasi struktur tree modern menggunakan C++, biasanya kita menyimpan anak-anak node menggunakan `std::unique_ptr` untuk **mengatur kepemilikan memori secara otomatis**:

```cpp
std::unique_ptr<Node<T>> left;
```

Ini memastikan bahwa saat parent node dihapus, semua child-nya ikut terhapus tanpa harus menulis `delete` manual — sangat aman dari memory leak.

---

### 🔗 Kasus chaining: `root->setLeft(10)->setRight(20);`

Chaining semacam ini artinya:

1. Kamu memanggil `setLeft(10)` pada `root`, yang membuat node anak di sebelah kiri.
    
2. Kamu **langsung** memanggil `->setRight(20)` pada node yang baru saja dibuat, yaitu `root->left`.
    

Agar ini berhasil, maka `setLeft()` **harus mengembalikan pointer ke node kiri yang baru dibuat**.

---

### ✅ Cara yang benar:

```cpp
Node<T>* setLeft(T val) {
    left = std::make_unique<Node<T>>(val);
    return left.get(); // pointer mentah, tanpa memindahkan kepemilikan
}
```

Penjelasan:

- `left` menyimpan node baru menggunakan `unique_ptr`.
    
- `left.get()` memberikan akses ke objek tersebut **sebagai pointer mentah (`Node<T>*`)**, jadi kamu bisa lanjut chaining ke fungsi berikutnya.
    
- Kepemilikan tetap dipegang oleh `unique_ptr` milik `this->left`.
    

---

### ⚠️ Kenapa tidak `return left;`?

```cpp
Node<T>* setLeft(T val) {
    left = std::make_unique<Node<T>>(val);
    return left; // ❌ SALAH!
}
```

#### 🛑 Penjelasan kenapa ini berbahaya:

- `left` adalah `std::unique_ptr<Node<T>>`, yang **tidak bisa disalin**, hanya bisa **dipindahkan (move)**.
    
- Saat kamu `return left`, kamu **memindahkan ownership keluar dari class Node**.
    
- Akibatnya: `this->left` akan menjadi `nullptr`, dan node kiri hilang dari pohon.
    
- Ini merusak struktur data pohon, karena kamu **secara tidak sengaja mengosongkan anak kiri**.
    

Contoh efeknya:

```cpp
auto child = root->setLeft(10); // ownership dipindah
// root->getLeft() sekarang jadi nullptr! pohon rusak
```

---

### 🔥 Singkatnya:

|Return statement|Apa yang terjadi|
|---|---|
|`return left.get();`|✅ Memberikan pointer ke node kiri, ownership tetap aman|
|`return left;`|❌ Ownership berpindah, `this->left` jadi `nullptr`, pohon rusak|
|`return std::move(left);`|❌ Sama buruknya — ownership pindah keluar|

---

### 🎯 Prinsip yang harus diingat:

> Gunakan `get()` **saat kamu butuh akses** ke objek dalam `unique_ptr`,  
> tapi **tidak ingin memindahkan kepemilikan**.

---

### 🧪 Ilustrasi Analogi:

Bayangkan `unique_ptr` seperti **brankas pribadi** milik sebuah node.

- `left.get()` seperti membuka jendela kecil untuk melihat atau menunjuk isinya.
    
- `return left` itu seperti **mengambil isi brankas dan memberikannya ke orang lain**, lalu brankasmu kosong.
    
- Kalau kamu masih ingin simpan isinya di dalam node, tentu kamu tidak mau `return left` begitu saja.

---

## ✅ Kenapa `get()` ideal:

|Fungsi|Apa yang terjadi|
|---|---|
|`left.get()`|Memberikan akses ke `Node<T>*` tanpa memengaruhi `left`|
|Return untuk chaining|Aman untuk diteruskan ke method chaining berikutnya|
|Akses internal|Bisa pakai di traversal, pencarian, logika tree|
Fungsi ini ideal karena `get()`:

1. Mengembalikan pointer mentah (`T*`) ke objek yang dikelola oleh `unique_ptr`,
    
2. Tanpa memindahkan atau mengubah kepemilikan objek tersebut,
    
3. Sehingga kamu bisa langsung lanjut memanggil method berikutnya pada objek itu (_chaining_),
    
4. Tanpa merusak struktur atau manajemen memori.


### 🔗 Contoh chaining:

```cpp
root->setLeft(10)->setRight(20)->setLeft(5);
```

Agar ekspresi ini berhasil:

- `setLeft(10)` harus mengembalikan `Node<T>*` ke node baru yang dibuat.
    
- Tapi node tersebut disimpan di dalam `std::unique_ptr<Node<T>> left`.
    
- Maka kamu pakai:
    

```cpp
return left.get(); // aman, karena hanya memberi akses, bukan menyerahkan ownership
```


### ⚠️ Alternatif selain `get()` — dan kenapa buruk:

|Alternatif|Masalahnya|
|---|---|
|`return left`|❌ Pindahkan ownership — `left` jadi `nullptr`, pohon rusak|
|`return std::move(left)`|❌ Sama saja — ownership keluar dari node|
|`return &*left`|✅ Sama hasilnya dengan `get()`, tapi lebih rumit & tidak idiomatik|
|`return left.get()`|✅ Paling tepat — idiomatik, aman, jelas|

### 📌 Singkatnya:

> `get()` itu seperti **menunjuk** ke isi `unique_ptr`,  
> bukan **menyerahkannya**.

Inilah mengapa ia **ideal untuk chaining**: kamu bisa lanjut ke pemanggilan method berikutnya, **tanpa mengubah kepemilikan node**, dan tetap menjaga struktur pohon tetap utuh dan aman.

### 🔍 Analogi singkat:

Bayangkan `unique_ptr` seperti rak buku pribadi.  
`get()` itu seperti **menyentuh dan membaca buku**,  
tanpa mengambilnya dan membawanya keluar.  
Tapi kalau kamu `return left`, kamu **memberikan bukunya dan raknya sekalian**, sehingga rakmu kosong.


---

## 📌 Rangkuman penggunaan `get()`

| Situasi                                                                      | Apakah `get()` cocok? | Kenapa                                          |
| ---------------------------------------------------------------------------- | --------------------- | ----------------------------------------------- |
| Ingin akses pointer mentah                                                   | ✅ Ya                  | Memberi akses tanpa mengubah kepemilikan        |
| Ingin chaining (`setLeft()->...`, `setRight()->...)`, dan `setChild()->...`) | ✅ Ya                  | Butuh pointer mentah ke node baru               |
| Ingin menghapus atau pindah ownership                                        | ❌ Tidak               | Gunakan `std::move()` jika memang mau pindahkan |

---

## ✨ Contoh chaining ideal:

Kode class Node dengan Chaining Lengkap (buatan sendiri yang sudah optimal):

```cpp
template<typename T>
class Node {
private:
    T data;
    std::unique_ptr<Node<T>> left, right;

public:
    Node(T data) : data(data) {}

    T getData() const { 
        return data; 
    }

    Node<T>* setLeft(T val) {
        left = std::make_unique<Node<T>>(val);
        return left.get(); // ✅ memungkinkan chaining
    }
    
    Node<T>* setRight(T val) {
        right = std::make_unique<Node<T>>(val);
        return right.get(); // ✅ memungkinkan chaining
    }

    Node<T>* setChild(T a, T b){
        setLeft(a); 
        setRight(b);
        return this; // ✅ mengembalikan node sekarang agar bisa lanjut chaining
    }

    Node<T>* getLeft() const {
        return left.get(); 
    }

    Node<T>* getRight() const {
        return right.get();
    }
};
```

---

## 🔗 Bagaimana Chaining Bekerja di Kode Ini?

### Kamu bisa menulis:

```cpp
auto root = std::make_unique<Node<int>>(1);

root->setChild(2, 3)           // root punya anak kiri 2, kanan 3
     ->getLeft()->setRight(4) // node 2 → kanan 4
     ->setLeft(5);            // node 4 → kiri 5
```

> Karena kita menggunakan class, maka kita perlu menggunakan fungsi `getLeft()` untuk mendapatkan akses ke node 2. Tetapi jika kita membuat fondasi tree dengan struct, penggunaan `left` dan `right` bisa langsung digunakan, karena struct memiliki default public untuk semua data membernya.
> 
> Pembahasan ini dibahas di [[06-Perbedaan Chaining pada Class vs Struct]]

### Penjelasan chaining:

- `setChild(2, 3)` membuat node kiri dan kanan dari root.
    
- `->getLeft()` memberi akses ke node 2.
    
- `->setRight(4)` menambahkan anak kanan node 2.
    
- lalu `->setLeft(5)` dari node 4.
    

---

## ✅ Kenapa desain ini bagus?

|Aspek|Penjelasan|
|---|---|
|`unique_ptr<Node<T>>`|Mengelola memori secara otomatis dan aman|
|Return `Node<T>*` dari setter|Mendukung chaining tanpa memindahkan ownership|
|`get()` digunakan|Mengambil pointer mentah ke node tanpa kehilangan kendali|
|`setChild()` mengembalikan `this`|Bisa melanjutkan chaining dari node yang sama|

---

## 💡 Tambahan Ide (opsional)

Kalau kamu mau fleksibilitas lebih:

- Bisa tambah `setChildLeftOnly()` atau `setChildRightOnly()`
    
- Bisa tambahkan overload `setChild(Node<T>*, Node<T>*)` untuk reuse existing node
    

---

### ✅ Kesimpulan

> Versi yang kamu buat sudah **benar, bersih, dan idiomatik**.  
> Ia sepenuhnya mendukung chaining, aman secara memori, dan mudah digunakan.

Kesimpulanya, penggunaan fungsi `get()` penting ketika kita ingin melakukan operasi chaining node pada tree.
