---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSLK-LS01
nama_algoritma: 
kategori_algoritma: data structure
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
sumber: programiz.com & chatgpt.com
date_learned: 2025-07-08T13:26:00
tags:
  - linked-list
  - data-structure
---
Link sumber: [Linked List Data Structure](https://www.programiz.com/dsa/linked-list)

---
# Linked list Data Structure

**Linked list** adalah struktur data linier yang terdiri dari serangkaian _node_ yang saling terhubung. Di sini, setiap _node_ menyimpan data dan alamat dari _node_ berikutnya. Sebagai contoh:

![[Linked list - Linked list Data Structure-1.png]]

Kita harus memulai dari suatu titik, jadi alamat dari _node_ pertama diberikan nama khusus yang disebut **HEAD**. Selain itu, _node_ terakhir dalam linked list dapat dikenali karena bagian _next_-nya menunjuk ke **NULL** (kosong).

**Linked list** dapat terdiri dari beberapa jenis: _singly linked list_, _doubly linked list_, dan _circular linked list_. Dalam artikel ini, kita akan fokus pada **singly linked list**. Untuk mempelajari jenis lainnya, kunjungi bagian [Types of Linked List](https://www.programiz.com/dsa/linked-list-types).

> **Catatan:** Kamu mungkin pernah bermain permainan _Treasure Hunt_ (Perburuan Harta Karun), di mana setiap petunjuk berisi informasi tentang petunjuk berikutnya. Nah, seperti itulah cara kerja linked list.

### Penjelasan Tambahan
#### 🔗 Analogi Linked List: Rantai Surat Berantai (Chain Letter)

Bayangkan kamu sedang bermain permainan **surat berantai**.

1. Kamu menerima surat dari temanmu.
    
2. Di dalam surat itu, ada dua hal:
    
    - **Isi surat** (misalnya: "Halo, ini pesan dari Andi.")
        
    - **Alamat teman berikutnya** (misalnya: "Kirim surat ini ke Budi.")
        
3. Kamu membaca surat itu, lalu meneruskan pesan tersebut ke Budi sesuai alamat yang tertera.
    
4. Budi juga akan menerima surat dengan isi baru dan alamat penerus selanjutnya, misalnya ke Citra, dan seterusnya...
    
#### Hubungan dengan Linked List:

|Surat Berantai|Linked List|
|---|---|
|Isi surat|Data di node|
|Alamat teman berikutnya|Pointer ke node berikutnya|
|Surat pertama|HEAD (node pertama)|
|Surat terakhir tanpa alamat lanjut|Node terakhir menunjuk ke NULL|

#### ➕ Menambah Surat Baru (Insert)

Kalau kamu ingin menyisipkan surat baru antara Andi dan Budi:

- Buat surat baru dan isi dengan pesan serta alamat Budi.
    
- Ubah surat dari Andi agar alamat penerusnya menunjuk ke surat baru.
    

#### ❌ Menghapus Surat (Delete)

Kalau kamu ingin menghapus surat dari Budi:

- Ubah surat dari Andi agar langsung menunjuk ke surat setelah Budi (misalnya Citra).
    
- Surat Budi diputus dari rantai, dan tidak akan dibaca lagi.
    

#### Mengapa Ini Berguna?

- Kamu tidak harus menyusun surat-surat dalam satu kotak atau urutan tetap (seperti array).
    
- Kamu hanya butuh tahu **dari siapa surat dimulai**, lalu ikuti **rantainya** satu per satu.
    
- Mudah disisipkan atau dihapus tanpa harus memindahkan semua surat lain.
    


---
## Representasi dari Linked List

Mari kita lihat bagaimana setiap _node_ dalam linked list direpresentasikan. Setiap _node_ terdiri dari:

- Sebuah item data
    
- Sebuah alamat ke _node_ lain
    

Kita membungkus data dan referensi ke _node_ berikutnya ke dalam sebuah `struct`, seperti berikut:

```cpp
struct node {
  int data;
  struct node *next;
};
```

Memahami struktur dari sebuah _node_ pada linked list adalah kunci untuk menguasainya.

Setiap `struct node` memiliki sebuah item data dan sebuah pointer yang menunjuk ke `struct node` lainnya. Mari kita buat sebuah **linked list sederhana** dengan tiga item untuk memahami cara kerjanya.


```cpp
/* Initialize nodes */
struct node *head;
struct node *one = NULL;
struct node *two = NULL;
struct node *three = NULL;

/* Allocate memory */
one = malloc(sizeof(struct node));
two = malloc(sizeof(struct node));
three = malloc(sizeof(struct node));

/* Assign data values */
one->data = 1;
two->data = 2;
three->data=3;

/* Connect nodes */
one->next = two;
two->next = three;
three->next = NULL;

/* Save address of first node in head */
head = one;
```

Jika kamu belum memahami salah satu baris kode di atas, yang kamu butuhkan hanyalah penyegaran tentang [pointers and structs](https://www.programiz.com/c-programming/c-structures-pointers)

Hanya dalam beberapa langkah, kita telah berhasil membuat sebuah **linked list sederhana** dengan tiga _node_.

![[Linked list - Linked list Data Structure-2.png]]

Kekuatan dari **linked list** terletak pada kemampuannya untuk **memutus rantai dan menyambungkannya kembali**. Misalnya, jika kamu ingin menyisipkan elemen **4** di antara **1** dan **2**, langkah-langkahnya adalah:

1. Buat sebuah `struct node` baru dan alokasikan memori untuknya.
    
2. Isi nilai datanya dengan **4**
    
3. Arahkan _pointer next_-nya ke `struct node` yang berisi data **2**
    
4. Ubah _pointer next_ dari node **1** agar menunjuk ke node yang baru saja kita buat.
    

Melakukan hal serupa pada array akan membutuhkan **pergeseran posisi semua elemen setelahnya**.

Dalam **Python** dan **Java**, linked list dapat diimplementasikan menggunakan **class**.

> Penulisan `struct` dan penggunaan pointer pada linked list diatas menggunakan penulisan bahasa C. Metode yang lebih modern dan lebih baik untuk terhindar dari memory leak akan dijelaskan di *materi pendalaman*!

---
## Kegunaan Linked List

**List** adalah salah satu struktur data yang paling populer dan efisien, serta diimplementasikan di hampir semua bahasa pemrograman seperti **C, C++, Python, Java**, dan **C#**.

Selain itu, **linked list** juga merupakan cara yang sangat baik untuk **mempelajari cara kerja pointer**. Dengan berlatih memanipulasi linked list, kamu bisa mempersiapkan diri untuk mempelajari struktur data yang lebih kompleks seperti **graph** dan **tree**.

### Penjelasan Tambahan

#### 1. Alokasi Memori Dinamis

- Linked list **tidak butuh ukuran tetap** di awal seperti array.
    
- Kamu bisa **menambahkan elemen kapan saja** tanpa harus tahu jumlah totalnya.
    
- Cocok untuk program yang datanya tumbuh atau berkurang secara dinamis.
    

> 🧠 Contoh: Saat pengguna menambahkan komentar atau entri baru dalam aplikasi.

#### 2. Struktur Data Stack dan Queue

- **Stack** (tumpukan) dan **Queue** (antrian) sering dibangun menggunakan linked list.
    
- Penyisipan dan penghapusan bisa dilakukan dengan cepat (O(1)).
    

> 📦 Stack: fungsi undo di editor teks.  
> 🚪 Queue: sistem antrian printer.

#### 3. Implementasi Fungsi Undo/Redo

- Fitur **undo** menyimpan histori tindakan sebagai rantai (linked list).
    
- Kamu bisa mundur satu langkah, atau maju (redo) dengan mudah karena data saling terhubung.

#### 4. Struktur Dasar untuk Graph dan Tree

- Linked list adalah dasar untuk **struktur data yang lebih kompleks**, seperti:
    
    - **Graph** (untuk jaringan, peta, koneksi)
        
    - **Tree** (untuk struktur hierarki, seperti file sistem)
        

> 🌳 Contoh: Tree pada direktori file di komputer.  
> 🕸️ Contoh: Graph pada media sosial (siapa berteman dengan siapa).

#### 5. Manajemen Memori Efisien

- Linked list hanya menggunakan **memori sebanyak yang dibutuhkan**, tidak ada ruang kosong seperti array yang sudah dialokasikan penuh.
    
- Sangat membantu di lingkungan dengan **sumber daya terbatas** (misalnya embedded system).

#### 6. Menghindari Operasi Mahal pada Array

- Pada array, menyisipkan atau menghapus elemen di tengah butuh **pergeseran semua elemen** setelahnya.
    
- Pada linked list, cukup **ubah pointer saja**.


---
## Implementasi Linked List

```cpp
// Linked list implementation in C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Creating a node
class Node {
   public:
  int value;
  Node* next;
};

int main() {
  Node* head;
  Node* one = NULL;
  Node* two = NULL;
  Node* three = NULL;

  // allocate 3 nodes in the heap
  one = new Node();
  two = new Node();
  three = new Node();

  // Assign value values
  one->value = 1;
  two->value = 2;
  three->value = 3;

  // Connect nodes
  one->next = two;
  two->next = three;
  three->next = NULL;

  // print the linked list value
  head = one;
  while (head != NULL) {
    cout << head->value;
    head = head->next;
  }
}
```

---
## Kompleksitas Linked List

Kompleksitas Waktu (Time Complexity)

| Operasi                | Kasus Terburuk | Kasus Rata-rata |
| ---------------------- | -------------- | --------------- |
| Pencarian (Search)     | $O(n)$         | $O(n)$          |
| Penyisipan (Insert)    | $O(1)$         | $O(1)$          |
| Penghapusan (Deletion) | $O(1)$         | $O(1)$          |

Kompleksitas Ruang (Space Complexity): $O(n)$

---
## Aplikasi Linked List

### 1. Dynamic Memory Allocation

- Digunakan dalam manajemen memori (seperti `malloc()` di C).
    
- Menyimpan blok memori yang bisa dialokasikan dan dibebaskan secara dinamis.
    

> 📌 _Contoh:_ OS (Operating System) menggunakan linked list untuk melacak blok memori yang kosong atau sedang dipakai.

### 2. Struktur Data Stack dan Queue

- Stack (LIFO) dan Queue (FIFO) bisa diimplementasikan dengan mudah menggunakan linked list.
    
- Tidak perlu menggeser elemen, hanya perlu ubah pointer.
    

> 📌 _Contoh:_ Fitur undo di teks editor (stack), atau sistem antrian di printer (queue).

### 3. Sistem Navigasi (Undo/Redo)

- Fitur undo/redo membutuhkan pelacakan tindakan berurutan.
    
- Linked list cocok karena bisa navigasi ke node sebelumnya atau berikutnya (doubly linked list).
    

> 📌 _Contoh:_ Microsoft Word, Photoshop.

### 4. Representasi Graf dan Tree

- Adjacency list pada graph biasanya menggunakan linked list.
    
- Tree (seperti Binary Tree) dibangun dengan node yang saling menunjuk ke child-nya.
    

> 📌 _Contoh:_ Struktur folder/file komputer, pemetaan jalur, social network graph.

### 5. Hash Table dengan Chaining

- Ketika terjadi collision (dua data pada index hash yang sama), linked list digunakan untuk menyimpan banyak elemen pada satu index.
    

> 📌 _Contoh:_ Implementasi `unordered_map` di C++ atau `HashMap` di Java.

---

## ✅ Kapan Sebaiknya Menggunakan Linked List?

|Kondisi|Mengapa Linked List Cocok|
|---|---|
|✅ Ukuran data tidak diketahui dari awal|Karena linked list bisa tumbuh secara dinamis|
|✅ Banyak operasi insert/delete di awal/tengah|Linked list hanya ubah pointer, tidak perlu geser elemen|
|✅ Terbatas pada sistem dengan memori kecil|Linked list tidak perlu alokasi besar di awal|
|✅ Tidak terlalu sering akses acak (random access)|Karena linked list **lemah** dalam akses langsung ke elemen ke-n|

## ❌ Kapan Sebaiknya **Tidak** Menggunakan Linked List?

|Kondisi|Alternatif Lebih Baik|
|---|---|
|❌ Sering akses acak ke elemen (misalnya data[10])|Gunakan array atau vector|
|❌ Jumlah data kecil dan tetap|Array lebih efisien dan sederhana|
|❌ Butuh cache locality (akses memori berdekatan lebih cepat)|Array lebih baik karena elemen berdampingan di memori|
