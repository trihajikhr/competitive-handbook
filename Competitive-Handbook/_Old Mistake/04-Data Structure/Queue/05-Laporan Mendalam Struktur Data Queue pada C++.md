---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSQU-E005
nama_algoritma:
kategori_algoritma: data structure
kesulitan: 🥈 medium
time_complexity:
memory_complexity:
sumber:
  - Gemini AI
date_learned: 2025-08-27T15:33:00
tags:
  - data-structure
  - queue
---
Link sumber: 

---

# 1 | Pendahuluan: Memahami Konsep Dasar Queue

Queue atau antrean, atau dikenal sebagai _queue_, adalah salah satu struktur data linear fundamental dalam ilmu komputer yang memodelkan koleksi elemen dengan urutan tertentu. Secara konseptual, queue berfungsi sebagai koleksi entitas yang terurut (`ordered collection of entities`). Nama "queue" itu sendiri merupakan analogi langsung dari fenomena kehidupan sehari-hari, seperti queue orang yang menunggu giliran di kasir bioskop atau queue untuk mendapatkan layanan. Queue juga sering berperan sebagai _buffer_ atau penyimpan data sementara dalam berbagai konteks, baik dalam ilmu komputer maupun bidang lainnya.

```ad-info
Queue adalah bahasa inggris dari antrean!
```
## 1.1 | Definisi dan Prinsip Queue

Prinsip dasar yang menjadi inti dari struktur data queue adalah **FIFO (First-In, First-Out)**, yang berarti "Yang Pertama Masuk, Yang Pertama Keluar". Prinsip ini mengharuskan elemen yang pertama kali ditambahkan ke dalam queue akan menjadi elemen pertama yang dihapus dari queue. Hal ini setara dengan persyaratan bahwa setelah elemen baru ditambahkan, semua elemen yang ditambahkan sebelumnya harus dihapus terlebih dahulu sebelum elemen baru tersebut dapat dihapus.

## 1.2 | Terminologi dan Operasi Kunci

Queue memiliki dua ujung yang berbeda untuk operasinya. Ujung tempat elemen baru ditambahkan disebut bagian **belakang**, **ekor**, atau **`rear`**. Sebaliknya, ujung tempat elemen dihapus dari queue disebut bagian **depan**, **kepala**, atau **`front`**.

Dua operasi utama yang menopang fungsionalitas queue adalah:

- **`Enqueue`**: Operasi ini digunakan untuk menambahkan elemen baru ke bagian belakang queue. Dalam implementasi manual, penambahan elemen ini selalu menggerakkan variabel `rear`.
<br/>

- **`Dequeue`**: Operasi ini bertanggung jawab untuk menghapus elemen dari bagian depan queue.

## 1.3 | Perbedaan dengan Struktur Data Lain

Penting untuk membedakan queue dari struktur data linear lainnya, terutama `stack` (tumpukan). Meskipun keduanya adalah koleksi berurutan, mereka memiliki prinsip akses yang berlawanan. `Stack` beroperasi berdasarkan prinsip **LIFO (Last-In, First-Out)**, di mana elemen yang terakhir ditambahkan adalah yang pertama dihapus. Sebaliknya, queue berpegang pada prinsip FIFO. Perbedaan mendasar ini menentukan peran unik keduanya dalam algoritma dan aplikasi. Queue ideal untuk skenario yang memerlukan pemrosesan sekuensial dan adil, seperti penjadwalan tugas, sementara `stack` cocok untuk kasus seperti pelacakan rekursi pada tumpukan panggilan fungsi. Prinsip yang berlawanan ini menjadikan `stack` dan `queue` sebagai struktur data yang saling melengkapi dalam ilmu komputer.

<br/>

---

# 2 | Operasi-Operasi Fundamental pada Queue dan Kompleksitasnya

Selain operasi wajib `enqueue` dan `dequeue`, ada beberapa operasi tambahan yang penting untuk memanipulasi dan memeriksa kondisi queue. Operasi-operasi ini tersedia baik dalam implementasi manual maupun dalam kelas `std::queue` yang disediakan oleh C++ Standard Template Library (STL).

## 2.1 | Operasi Wajib dan Tambahan yang Penting

```ad-warning
Ini adalah contoh jenis-jenis fungsi general pada data structure queue, bukan untuk untuk bahasa C++! 

Cocok dijadikan panduan jika ingin membuat implementasi queue secara manual.
```

- `enqueue()`: Menyisipkan elemen baru di belakang queue. Operasi ini memastikan elemen yang lebih baru tidak dapat diakses atau dihapus sebelum elemen yang lebih lama.
<br/>

- `dequeue()`: Menghapus elemen dari depan queue. Proses ini efektif mengurangi ukuran queue sebesar satu. Dalam beberapa implementasi, penghapusan ini dapat dilakukan dengan menggeser penunjuk `front` ke elemen berikutnya.
<br/>

- **`front()`**: Mengakses elemen terdepan dari queue tanpa menghapusnya. Operasi ini berguna untuk melihat elemen yang akan dihapus berikutnya.
<br/>

- **`back()`**: Mengakses elemen terbelakang dari queue tanpa menghapusnya. Operasi ini umumnya digunakan untuk melihat elemen terakhir yang ditambahkan ke queue tanpa mengubah strukturnya.
<br/>

- **`size()`**: Mengembalikan jumlah elemen yang ada di dalam queue saat ini. Fungsi ini memungkinkan untuk mengetahui ukuran queue tanpa mengubah isinya.
<br/>

- **`empty()`**: Memeriksa apakah queue kosong atau tidak. Operasi ini seringkali vital untuk mencegah kesalahan seperti _underflow_ (mencoba menghapus elemen dari queue yang sudah kosong).

## 2.2 | Analisis Kompleksitas Waktu

Efisiensi sebuah implementasi queue diukur dari kompleksitas waktu operasi-operasi dasarnya. Sebuah implementasi yang optimal harus mampu melakukan operasi penambahan (`enqueue`) dan penghapusan (`dequeue`) dalam waktu konstan, dilambangkan dengan notasi $O(1)$, terlepas dari ukuran queue saat itu. Hal ini dimungkinkan karena kedua operasi tersebut hanya berinteraksi dengan ujung-ujung queue, bukan elemen di tengahnya.

Berikut adalah ringkasan kompleksitas waktu untuk operasi-operasi umum pada queue yang diimplementasikan secara efisien:

| Operasi                     | Kompleksitas Waktu (Rata-rata) | Kompleksitas Waktu (Terburuk) |
| --------------------------- | ------------------------------ | ----------------------------- |
| `Insert` (`Enqueue`)        | $O(1)$                         | $O(1)$                        |
| `Delete` (`Dequeue`)        | $O(1)$                         | $O(1)$                        |
| `Access` (`front` / `back`) | $O(1)$                         | $O(1)$                        |
| `Search`                    | $O(n)$                         | $O(n)$                        |
| `Traverse` (Iterasi)        | $O(n)$                         | $O(n)$                        |

Kompleksitas $O(n)$ untuk `Search` dan `Traverse` terjadi karena untuk mengakses elemen di tengah, seluruh elemen harus diiterasi satu per satu dari `front` hingga elemen yang diinginkan ditemukan. Ini menegaskan sifat queue sebagai struktur data akses sekuensial, bukan akses acak.

<br/>

---
# 3 | Berbagai Jenis Implementasi Queue dalam C++

Secara fundamental, queue dapat diimplementasikan dari nol menggunakan struktur data lain atau memanfaatkan kelas `std::queue` yang telah tersedia di C++ STL. Setiap pendekatan memiliki kelebihan dan kekurangannya.

## 3.1 | Implementasi Manual (Dari Nol)

### 3.1.1 | Menggunakan Array

Implementasi `queue` menggunakan array adalah metode statis di mana sebuah array dengan ukuran tetap digunakan sebagai wadah. Dua penunjuk, `front` dan `rear`, digunakan untuk melacak posisi elemen pertama dan terakhir dalam array. `front` akan menunjuk ke elemen yang akan dihapus, sementara `rear` menunjuk ke posisi di mana elemen baru akan disisipkan.

Namun, implementasi array sederhana menghadapi tantangan serius. Ketika elemen dihapus dari depan (`dequeue`), ruang kosong akan muncul di awal array. Implementasi naif dapat mencoba menggeser semua elemen ke depan untuk mengisi ruang tersebut, yang membuat operasi `dequeue` menjadi tidak efisien dengan kompleksitas waktu $O(n)$ karena semua elemen harus disalin. Masalah ini dikenal sebagai _Queue Manipulation Issue_.

### 3.1.2 | Solusi: _Circular Queue_

Sebuah solusi yang cerdas dan elegan untuk mengatasi masalah `dequeue` pada array adalah dengan menggunakan konsep _circular queue_ (queue melingkar). Dalam model ini, array diperlakukan sebagai lingkaran tertutup. Penunjuk `front` dan `rear` dibiarkan bergerak di dalam lingkaran tersebut, dan ketika mencapai akhir array, mereka akan "melingkar" kembali ke awal menggunakan operator **modulo** (banyak bahasa program menggunakan `%`). Dengan demikian, operasi `enqueue` dan `dequeue` dapat tetap mempertahankan kompleksitas waktu $O(1)$ yang optimal, karena tidak ada pergeseran elemen yang diperlukan. Meskipun `circular queue` sangat efisien, ia masih terikat pada kapasitas maksimum yang ditentukan di awal.

### 3.1.3 | Menggunakan _Linked List_

Implementasi `queue` dengan _linked list_ (daftar berantai) adalah pendekatan dinamis yang menawarkan fleksibilitas lebih besar. Setiap elemen dalam queue disimpan dalam sebuah simpul (_node_) yang berisi data dan sebuah penunjuk ke simpul berikutnya. Queue itu sendiri memiliki dua penunjuk utama: `front` yang selalu menunjuk ke simpul pertama dan `rear` yang menunjuk ke simpul terakhir.

Keunggulan utama dari implementasi _linked list_ adalah penggunaan memori yang dinamis. Queue dapat tumbuh atau menyusut sesuai kebutuhan tanpa batasan kapasitas yang statis, mengatasi masalah `overflow` pada implementasi array. Selain itu, operasi `enqueue` (menambah di belakang) dan `dequeue` (menghapus dari depan) dapat dilakukan dengan mudah dengan memperbarui penunjuk `front` dan `rear` dalam waktu konstan $O(1)$. Namun, setiap simpul memerlukan ruang tambahan untuk menyimpan penunjuk, yang dapat menyebabkan sedikit overhead memori dibandingkan dengan array.

## 3.2 | Menggunakan `std::queue` di C++ Standard Template Library (STL)

Di C++, cara paling umum dan direkomendasikan untuk menggunakan queue adalah melalui kelas `std::queue` yang merupakan bagian dari STL. `std::queue` bukanlah struktur data mandiri, melainkan sebuah _container adaptor_. Ini berarti ia adalah sebuah kelas yang membungkus atau "mengadaptasi" fungsionalitas dari kelas kontainer lain, yang disebut _underlying container_, untuk menyediakan antarmuka yang spesifik bagi queue.

Secara _default_, `std::queue` menggunakan `std::deque` (double-ended queue) sebagai wadah dasarnya. Pilihan ini sangat strategis karena `std::deque` mendukung operasi penyisipan dan penghapusan yang efisien (konstan $O(1)$) di kedua ujungnya. Wadah lain yang juga memenuhi persyaratan ini adalah `std::list`.

Keunggulan menggunakan `std::queue` adalah kemudahannya dan jaminan kinerja yang optimal, karena implementasi STL telah dioptimalkan dengan baik. Kekurangannya, yang sebenarnya merupakan fitur desain, adalah bahwa `std::queue` tidak menyediakan akses acak ke elemen di tengah.

## 3.3 | Filosofi Desain `std::queue`

Pembatasan akses acak pada `std::queue` adalah keputusan desain yang disengaja untuk menegakkan prinsip Abstract Data Type (ADT) queue. Tujuan `std::queue` adalah untuk menyediakan antarmuka yang hanya memungkinkan operasi yang secara fundamental sesuai dengan definisi queue (FIFO). Mengizinkan akses atau modifikasi elemen di tengah akan melanggar prinsip FIFO dan berpotensi menyebabkan penyalahgunaan. Dengan membatasi antarmuka hanya pada operasi-operasi yang relevan seperti `push`, `pop`, `front`, dan `back`, STL memastikan bahwa struktur ini digunakan sesuai dengan tujuan desainnya, mempromosikan kode yang lebih bersih, aman, dan dapat diandalkan. Ini merupakan contoh bagaimana desain yang "membatasi" sebenarnya dapat meningkatkan utilitas dan keandalan sebuah komponen perangkat lunak.

<br/>

---
# 4 | Fungsi-Fungsi Anggota `std::queue` secara Rinci

Kelas `std::queue` menyediakan serangkaian fungsi anggota yang ringkas namun komprehensif untuk mengelola queue. Fungsi-fungsi ini didefinisikan dalam berkas header `<queue>`.

- **`push()`**: Fungsi ini menyisipkan elemen baru ke bagian belakang queue. Operasi ini memiliki kompleksitas waktu $O(1)$. Sintaksnya adalah

	```cpp
	data.push(val);
	```

    di mana `val` adalah nilai yang akan ditambahkan.

<br/>

- **`pop()`**: Fungsi ini menghapus elemen dari bagian depan queue. Perlu dicatat bahwa `pop()` tidak mengembalikan nilai dari elemen yang dihapus; nilainya harus diakses terlebih dahulu dengan `front()` jika diperlukan. Operasi ini memiliki kompleksitas waktu $O(1)$. Sintaksnya sangat sederhana:
    

	```cpp
	data.pop();
	```

<br/>

- **`front()`**: Fungsi ini mengembalikan referensi ke elemen terdepan dari queue. Elemen tersebut tidak dihapus dari queue. Fungsi ini memiliki kompleksitas waktu $O(1)$.
<br/>

- **`back()`**: Fungsi ini mengembalikan referensi ke elemen terbelakang dari queue. Mirip dengan `front()`, elemen tidak dihapus. Kompleksitas waktunya juga $O(1)$.
<br/>

- **`empty()`**: Fungsi ini memeriksa apakah queue kosong. Ia mengembalikan nilai `true` jika queue tidak memiliki elemen dan `false` jika tidak. Ini adalah cara yang aman untuk memverifikasi kondisi sebelum mencoba menghapus elemen.
<br/>

- **`size()`**: Fungsi ini mengembalikan jumlah elemen yang saat ini ada di dalam queue. Kompleksitas waktu untuk operasi ini adalah $O(1)$.
<br/>

- **Fungsi Anggota Lainnya**: Kelas `std::queue` juga memiliki fungsi seperti `emplace()` yang secara langsung membangun elemen di tempatnya di akhir queue (sejak C++11) dan `swap()` yang menukar isi dua queue (sejak C++11).

## 4.1 | Contoh Kode Lengkap Penggunaan `std::queue`

Berikut adalah contoh kode C++ yang mengilustrasikan penggunaan fungsi-fungsi utama `std::queue`:

```cpp
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    // Membuat sebuah queue
    queue<string> myQueue;

    // Menggunakan push() untuk menambahkan elemen
    myQueue.push("Apel");
    cout << "Ukuran setelah pusah Apel: " << myQueue.size() << endl;
    
    myQueue.push("Pisang");
    cout << "Ukuran setelah pusah Pisang: " << myQueue.size() << endl;
    
    myQueue.push("Jeruk");
    cout << "Ukuran setelah pusah Jeruk: " << myQueue.size() << endl;

    // Menggunakan front() dan back() untuk mengakses elemen
    cout << "Elemen terdepan: " << myQueue.front() << endl;
    cout << "Elemen terbelakang: " << myQueue.back() << endl;

    // Memproses semua elemen menggunakan perulangan
    // dengan empty() dan pop()
    cout << "\nMemproses queue (FIFO):" << endl;
    while (!myQueue.empty()) {
        cout << "  - Menghapus: " << myQueue.front() << endl;
        myQueue.pop(); // Menghapus elemen dari depan
    }

    // Menggunakan empty() untuk memeriksa apakah queue kosong
    cout << "\nKosong? " << (myQueue.empty()? "Ya" : "Tidak") << endl;

    return 0;
}
```

<br/>

---
# 5 | Aplikasi Praktis dan Kasus Penggunaan Queue

Queue adalah salah satu struktur data yang paling sering digunakan dalam pemrograman karena fungsinya yang vital sebagai pengelola urutan dan penyeimbang beban. Kegunaan queue tidak terbatas pada satu bidang, melainkan meluas ke berbagai aplikasi, dari sistem operasi hingga algoritma pencarian.

## 5.1 | Dalam Sistem Komputer dan Operasi

- **Penjadwalan Tugas CPU (_CPU Scheduling_)**
  Sistem operasi menggunakan queue untuk mengelola proses yang menunggu untuk dieksekusi oleh CPU. Prinsip _First Come, First Served_ (FCFS) adalah algoritma penjadwalan yang paling sederhana dan langsung mengimplementasikan konsep queue.
<br/>

- **Queue Pencetakan (_Printer Spooling_)**: Saat beberapa pengguna mengirimkan dokumen untuk dicetak ke satu printer, pekerjaan-pekerjaan ini dimasukkan ke dalam queue. Printer akan mengambil dan memproses setiap pekerjaan satu per satu sesuai dengan urutan penerimaannya.
<br/>

- **Penanganan _Interrupt_**: Ketika perangkat I/O (misalnya, keyboard atau mouse) mengirimkan permintaan interupsi ke CPU, permintaan ini dimasukkan ke dalam sebuah queue untuk diproses oleh CPU dalam urutan kedatangan.
<br/>

- **Manajemen _Buffer_**: Queue berfungsi sebagai _buffer_ dalam transfer data asinkron antara dua proses yang memiliki kecepatan berbeda. Sebagai contoh, data yang diketik pada keyboard disimpan sementara dalam sebuah queue _buffer_ sebelum diproses oleh aplikasi.

## 5.2 | Dalam Jaringan dan Pemrograman Paralel

- **Penerusan Paket Data**: Protokol jaringan seperti TCP dan UDP menggunakan queue untuk memastikan paket data diterima dan diproses dalam urutan yang benar. Queue membantu mengelola aliran data dan mencegah kehilangan paket.
<br/>

- **Model Produsen-Konsumen (_Producer-Consumer Model_)**: Ini adalah salah satu aplikasi paling canggih dalam pemrograman konkuren dan paralel. Dalam model ini, satu atau lebih _thread_ **Produsen** (misalnya, _thread_ yang menerima koneksi klien pada server) menambahkan pekerjaan ke dalam sebuah **Queue Pekerjaan** (_work queue_). Di sisi lain, satu atau lebih _thread_ **Konsumen** (para pekerja) mengambil dan memproses pekerjaan dari queue tersebut.
    

Penggunaan queue dalam model produsen-konsumen sangat penting karena queue menyediakan mekanisme _decoupling_ yang krusial. Produsen dan Konsumen dapat beroperasi secara asinkron; Produsen dapat terus menambahkan pekerjaan ke queue meskipun Konsumen sedang sibuk, dan Konsumen dapat mengambil pekerjaan dari queue pada kecepatannya sendiri. Queue berfungsi sebagai _buffer_ yang menampung pekerjaan saat terjadi lonjakan permintaan, mencegah Produsen menunggu Konsumen dan sebaliknya. Prinsip FIFO pada queue menjamin bahwa pekerjaan diproses sesuai urutan kedatangan, menjaga keadilan dan urutan pemrosesan yang benar. Tanpa queue, sinkronisasi antar _thread_ akan menjadi jauh lebih kompleks dan rawan terhadap kondisi _race condition_.

## 5.3 | Dalam Algoritma

- **Pencarian Lebar-Pertama (_Breadth-First Search_ atau BFS)**: Queue adalah struktur data inti untuk algoritma BFS, yang digunakan untuk menjelajahi simpul-simpul dalam graf atau tree. BFS mengeksplorasi graf secara _level-by-level_ (tingkat demi tingkat). Queue digunakan untuk menyimpan simpul-simpul yang ditemukan pada tingkat saat ini sebelum pindah ke tingkat yang lebih dalam. 
  
  Prinsip FIFO pada queue secara alami menjamin bahwa simpul pada tingkat yang sama akan dikunjungi sebelum simpul pada tingkat yang lebih dalam, yang merupakan jaminan utama dari algoritma BFS. Hal ini sangat kontras dengan algoritma _Depth-First Search_ (DFS) yang menggunakan `stack` atau rekursi untuk menjelajahi graf secara mendalam terlebih dahulu.


Aplikasi-aplikasi seperti BFS dan penjadwalan CPU menunjukkan satu tema mendasar: queue digunakan untuk mempertahankan urutan atau "keadilan" dalam pemrosesan. Dalam BFS, urutan FIFO menjamin bahwa algoritma akan menemukan jalur terpendek dalam graf yang tidak berbobot. Dalam penjadwalan CPU, prinsip FIFO memastikan proses diproses berdasarkan waktu kedatangannya, yang merupakan bentuk keadilan dasar. Ini merupakan konsep mendalam yang menghubungkan berbagai aplikasi yang tampaknya berbeda di bawah satu konsep filosofis: manajemen urutan yang adil.

<br/>

---

# 6 | Perbandingan Komprehensif dan Rekomendasi Penggunaan

Memilih implementasi queue yang tepat bergantung pada kebutuhan spesifik aplikasi. Pemahaman mendalam tentang perbandingan antara implementasi array, _linked list_, dan `std::queue` sangat krusial.

## 6.1 | Perbandingan Implementasi

| Fitur                  | Array Sederhana          | _Circular Array_         | _Linked List_                   | `std::queue` (STL)              |
| ---------------------- | ------------------------ | ------------------------ | ------------------------------- | ------------------------------- |
| Kompleksitas `Enqueue` | $O(1)$                   | $O(1)$                   | $O(1)$                          | $O(1)$                          |
| Kompleksitas `Dequeue` | $O(n)$                   | $O(1)$                   | $O(1)$                          | $O(1)$                          |
| Penggunaan Memori      | Efisien (tanpa pointer)  | Efisien (tanpa pointer)  | Overhead karena pointer         | Sangat efisien, dioptimalkan    |
| Fleksibilitas Ukuran   | Statis, mudah `overflow` | Statis, mudah `overflow` | Dinamis, tidak ada batas statis | Dinamis, tidak ada batas statis |
| Kemudahan Implementasi | Relatif mudah            | Memerlukan logika modulo | Memerlukan manajemen memori     | Sangat mudah, abstrak           |

## 6.2 | Rekomendasi Praktis

Berdasarkan analisis di atas, rekomendasi praktis untuk sebagian besar kasus adalah menggunakan `std::queue` dari C++ STL. `std::queue` adalah pilihan yang paling andal, efisien, dan mudah digunakan. Implementasi di dalamnya telah dioptimalkan secara ketat dan menyediakan jaminan kinerja $O(1)$ yang konsisten untuk operasi `push` dan `pop`.

Implementasi manual, baik menggunakan _circular array_ atau _linked list_, sebaiknya hanya dipertimbangkan jika ada kebutuhan yang sangat spesifik. Misalnya, jika ada batasan memori yang sangat ketat pada sistem tertanam di mana overhead memori dari pointer _linked list_ menjadi masalah. Untuk sebagian besar aplikasi, abstraksi dan keandalan yang ditawarkan oleh `std::queue` menjadikannya pilihan yang paling tepat.

## 6.3 | Keterbatasan dan Alternatif

Keterbatasan utama dari queue adalah kurangnya fitur akses acak. Jika sebuah aplikasi membutuhkan kemampuan untuk mengakses atau memodifikasi elemen di tengah koleksi, struktur data lain seperti `std::deque` atau `std::vector` akan lebih cocok.

Selain itu, jika pemrosesan elemen tidak harus mengikuti urutan kedatangan FIFO, tetapi harus didasarkan pada prioritas, `std::priority_queue` adalah alternatif yang lebih tepat. `std::priority_queue` secara otomatis mengurutkan elemennya sehingga elemen dengan prioritas tertinggi selalu berada di depan, siap untuk diproses.

Dengan demikian, pemahaman yang komprehensif tentang queue melibatkan tidak hanya definisi, fungsi, dan implementasinya, tetapi juga pemahaman yang bernuansa tentang kapan dan mengapa menggunakannya, termasuk kapan harus mencari alternatif yang lebih sesuai dengan kebutuhan spesifik.

<br/>

---
# 7 | Kapan Menggunakan `std::queue`?

Kamu harus menggunakan `std::queue` ketika kamu perlu memproses elemen dalam urutan yang sama saat mereka ditambahkan. Ini adalah skenario yang paling cocok untuk `std::queue`:

- **Pencarian Graf (BFS - Breadth-First Search)**: `std::queue` adalah struktur data inti untuk algoritma BFS. Kamu memulai dari satu node, menambahkan semua node tetangga ke dalam queue, lalu memproses setiap tetangga sebelum pindah ke level yang lebih dalam. Ini memastikan kamu menjelajahi semua node pada tingkat yang sama sebelum beralih ke tingkat berikutnya.
<br/>

- **Penjadwalan Tugas**: Jika kamu memiliki beberapa tugas yang harus dijalankan secara berurutan, kamu bisa memasukkannya ke dalam `std::queue`. Sistem akan mengambil tugas dari depan antrean, memprosesnya, lalu menghapusnya. Ini memastikan tugas yang lebih dulu masuk akan diproses lebih dulu.
<br/>

- **Manajemen Buffering**: Ketika data datang dari _stream_ (seperti dari jaringan atau file) dengan laju yang tidak menentu, kamu bisa menyimpannya sementara di `std::queue`. Data akan dibaca dari antrean secara teratur.
<br/>

- **Simulasi**: Dalam simulasi, seperti simulasi antrean di bank atau supermarket, `std::queue` digunakan untuk meniru perilaku antrean yang sesungguhnya.
    
## 7.1 | Perbedaan dengan Struktur Data Lain

Penting untuk memahami perbedaan `std::queue` dengan struktur data lain agar kamu tahu kapan memilihnya.

| Fitur Utama           | `std::queue`                                                                   | `std::vector`                                               | `std::stack`                                      |
| --------------------- | ------------------------------------------------------------------------------ | ----------------------------------------------------------- | ------------------------------------------------- |
| Prinsip           | **FIFO** (First-In, First-Out)                                                 | Akses acak & array dinamis                                  | **LIFO** (Last-In, First-Out)                     |
| Operasi Cepat     | Menambah di belakang (`push`) dan menghapus di depan (`pop`).                  | Menambah & menghapus di belakang (`push_back`, `pop_back`). | Menambah & menghapus di belakang (`push`, `pop`). |
| Akses Elemen      | Hanya bisa melihat elemen paling depan (`front`) dan paling belakang (`back`). | Akses ke elemen mana pun dengan indeks.                     | Hanya bisa melihat elemen paling atas (`top`).    |
| Contoh Penggunaan | BFS, penjadwalan.                                                              | Menyimpan data yang ukurannya bisa berubah.                 | Algoritma _undo_, ekspresi matematika.            |

Singkatnya, gunakan `std::queue` jika **urutan data sangat penting** dan kamu ingin memprosesnya dari yang pertama masuk. Jika kamu butuh akses acak yang cepat, gunakan `std::vector`. Jika kamu butuh prinsip "yang terakhir masuk, yang pertama keluar", gunakan `std::stack`.

<br/>

---
# 8 | Penggunaan `std::queue` dalam Competitive Programming

Dalam _competitive programming_, `std::queue` biasanya digunakan untuk algoritma yang memproses data atau menjelajahi struktur dalam urutan **FIFO (First-In, First-Out)**. Ini sangat cocok untuk skenario di mana urutan kedatangan data sangat penting.

## 8.1 | Kasus Penggunaan Utama `std::queue`

### 8.1.1 | Breadth-First Search (BFS) pada Graf atau Pohon

Ini adalah penggunaan `queue` yang paling umum dan krusial. BFS adalah algoritma yang digunakan untuk menjelajahi semua simpul (node) pada graf secara sistematis. Algoritma ini menjamin bahwa ia akan mengunjungi semua simpul pada tingkat kedalaman `k` sebelum pindah ke simpul pada tingkat `k+1`.

- **Bagaimana cara kerjanya?**:
    
    - Mulai dari simpul awal, masukkan ke dalam `queue`.
        
    - Selama `queue` tidak kosong:
        
        - Ambil simpul dari depan `queue`.
            
        - Proses simpul tersebut.
            
        - Masukkan semua tetangga yang belum dikunjungi dari simpul tersebut ke dalam `queue`.
            

`queue` memastikan bahwa simpul yang terdekat dengan simpul awal akan diproses lebih dulu, sehingga menjamin pencarian melebar ke luar.

### 8.1.2 | Penjadwalan Tugas (Task Scheduling)

Ketika kamu memiliki daftar tugas yang perlu diproses secara berurutan, `queue` adalah struktur data yang ideal. Tugas yang datang lebih awal akan diproses lebih dulu.

- **Contoh**: Bayangkan simulasi antrean di bank atau restoran. Orang yang datang lebih dulu akan dilayani lebih dulu. `queue` bisa memodelkan antrean ini dengan akurat.
    

## 8.2 | Ringkasan Cepat

| Penggunaan               | Skenario                                                                    | Contoh Soal                                            |
| ------------------------ | --------------------------------------------------------------------------- | ------------------------------------------------------ |
| **BFS**                  | Menemukan jalur terpendek pada graf tak berbobot; menjelajahi semua simpul. | `Shortest Path in Unweighted Graph`, `Maze Traversal`. |
| **Simulasi/Penjadwalan** | Memproses entitas berdasarkan urutan kedatangan.                            | `Elevator Simulation`, `Waiting Queue`.                |
|                          |                                                                             |                                                        |

Jadi, jika masalah membutuhkan pemrosesan data dalam urutan `FIFO`, **`std::queue` adalah pilihan pertama yang harus kamu pertimbangkan.**