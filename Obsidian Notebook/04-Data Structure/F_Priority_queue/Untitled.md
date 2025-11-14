---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 
nama_algoritma: 
kategori_algoritma: 
kesulitan: 🥉 easy 🥈 medium 🥇 hard
time_complexity: 🟢 O(1) 🔵 O(log n) 🟡 O(√n) 🟠 O(n) 🟤 O(n log n) 🟣 O(n²) 🟧 O(n³) 🔴 O(2ⁿ) ⚫ O(n!) ⚪O(formula)
memory_complexity: 🟢 O(1) 🔵 O(log n) 🟡 O(√n) 🟠 O(n) 🟤 O(n log n) 🟣 O(n²) 🟧 O(n³) 🔴 O(2ⁿ) ⚫ O(n!) ⚪O(formula) ✅ → Stable ❌ → Unstable
sumber: 
date_learned: 
tags:
---
Link sumber: 

---

# Analisis Mendalam Mengenai `std::priority_queue` dalam Pustaka Standar C++ (STL)

Laporan ini menyajikan tinjauan mendalam terhadap struktur data `std::priority_queue` pada C++ Standard Template Library (STL), meliputi definisi konseptual, arsitektur implementasi, fungsi-fungsi yang tersedia, analisis kompleksitas waktu, hingga panduan aplikasi algoritmik terbaik.

## I. Fondasi Konseptual dan Arsitektur STL

`std::priority_queue` adalah salah satu struktur data yang paling kuat dalam C++ untuk mengelola koleksi elemen di mana urutan pemrosesan didikte oleh nilai prioritas, bukan hanya urutan waktu penyisipan.

### 1.1. Konsep Dasar Priority Queue (PQ ADT)

Priority Queue adalah _Abstract Data Type_ (ADT) yang berfungsi mirip dengan antrian atau tumpukan, namun memiliki prinsip layanan yang unik. Berbeda dengan antrian standar (FIFO) atau tumpukan (LIFO), PQ menjamin bahwa elemen dengan prioritas tertinggi selalu dilayani atau diakses terlebih dahulu, terlepas dari kapan elemen tersebut dimasukkan `[1, 2]`.

Secara konsep, terdapat dua varian utama PQ:

1. **Max-Priority Queue:** Elemen dengan nilai numerik terbesar atau nilai tertinggi (berdasarkan kriteria pemesanan) memiliki prioritas tertinggi. Ini adalah perilaku _default_ dalam C++ STL `[2, 3]`.
    
2. **Min-Priority Queue:** Elemen dengan nilai numerik terkecil atau nilai terendah memiliki prioritas tertinggi `[2]`.
    

### 1.2. Peran `std::priority_queue` sebagai Container Adaptor

Dalam C++ STL, `std::priority_queue` bukanlah wadah mandiri (seperti `std::vector` atau `std::list`), melainkan _container adaptor_ `[4, 5]`. Ini berarti ia didefinisikan dalam _header_ `<queue>` dan berfungsi dengan membungkus wadah dasar yang sudah ada (seperti `std::vector`) dan mengadaptasi antarmukanya agar sesuai dengan operasi antrian berbasis prioritas (`push`, `pop`, `top`) `[1, 5]`.

Adaptor ini dirancang untuk membatasi antarmuka yang dapat diakses oleh pengguna. Pembatasan ini, yang hanya mengekspos `top()`, `push()`, dan `pop()`, adalah keputusan desain yang disengaja untuk menjaga integritas properti _heap_ internal `[6]`. Jika akses acak atau iterasi penuh diizinkan, pengembang dapat secara tidak sengaja merusak struktur heap, yang akan menggagalkan jaminan kinerja ![](data:,) pada operasi akses elemen prioritas tertinggi.

### 1.3. Struktur Internal: Wadah Dasar dan Implementasi Heap

Implementasi inti dari `std::priority_queue` memanfaatkan struktur data **Binary Heap** `[2, 5]`. Wadah dasar (disebut _underlying container_) bertanggung jawab untuk menyimpan elemen-elemen heap secara fisik.

- **Wadah Dasar Default:** Secara _default_, PQ menggunakan `std::vector<T>` `[1, 5]`. Wadah ini harus memenuhi persyaratan `SequenceContainer` dan mendukung operasi seperti `front()`, `push_back()`, dan `pop_back()` `[5, 6]`. Selain `std::vector`, `std::deque` juga merupakan wadah yang valid `[5]`.
    
- **Mekanisme Inti:** Implementasi prioritas dikelola dengan menerapkan algoritma heap standar C++ (seperti yang ada di `<algorithm>`) pada wadah dasar `[7]`. Setiap kali elemen disisipkan atau dihapus, algoritma ini dipanggil untuk mengatur ulang elemen-elemen, memastikan elemen prioritas tertinggi selalu berada di akar heap, yang merupakan elemen yang diakses melalui `top()` `[8]`.
    

Pilihan untuk menggunakan `std::vector` sebagai wadah dasar menawarkan keuntungan performa signifikan. Karena heap biner dapat dipetakan secara efisien ke dalam larik (array), penggunaan `std::vector` memastikan bahwa elemen tersimpan dalam memori yang berdekatan (kontigu). Ini memberikan _cache locality_ yang luar biasa. Saat operasi heap (seperti _heapify_) dilakukan, blok data yang besar dapat dimuat ke dalam _cache_ CPU, menghasilkan akses yang jauh lebih cepat dibandingkan dengan struktur berbasis node (seperti pohon biner yang seimbang) yang mungkin memiliki fragmen memori yang tersebar `[7, 9]`.

## II. Deklarasi, Inisialisasi, dan Konfigurasi Dasar

Sintaksis deklarasi `std::priority_queue` memerlukan pemahaman tentang tiga parameter templat utamanya, yang memberikan fleksibilitas tinggi dalam menentukan prioritas.

### 2.1. Sintaksis Template `std::priority_queue`

Deklarasi standar PQ adalah sebagai berikut [1, 5]:

![](data:,)

1. **`T` (Type):** Tipe data elemen yang akan disimpan.
    
2. **`Container` (Wadah Dasar):** Tipe wadah yang digunakan (defaultnya adalah `std::vector<T>`).
    
3. **`Compare` (Comparator):** Objek predikat biner yang mendefinisikan kriteria pemesanan (prioritas). Defaultnya adalah `std::less<T>`.
    

### 2.2. Konfigurasi Max-Heap (Default)

Jika `Container` dan `Compare` dihilangkan, PQ secara _default_ akan bertindak sebagai Max-Heap `[1, 5]`:

C++

```
std::priority_queue<int> max_pq;
```

Perilaku Max-Heap ini didasarkan pada komparator _default_ `std::less<T>`. Meskipun secara intuitif `std::less<T>` (`a < b`) menyarankan urutan menaik, dalam konteks heap, logika ini terbalik. Komparator yang digunakan oleh PQ harus mengembalikan `true` jika elemen pertama (`a`) memiliki **prioritas yang lebih rendah** dan harus diletakkan di bawah elemen kedua (`b`) `[10]`. Karena `std::less<T>` mengembalikan `true` ketika ![](data:,) lebih kecil dari ![](data:,), ini berarti elemen yang lebih kecil dianggap memiliki prioritas lebih rendah dan akan didorong ke bawah pohon. Akibatnya, elemen terbesar naik ke atas, menjadikannya Max-Heap `[11]`.

### 2.3. Implementasi Min-Heap

Untuk mendapatkan Min-Heap (di mana elemen terkecil memiliki prioritas tertinggi), komparator harus dibalik menggunakan `std::greater<T>` `[3, 6]`.

C++

```
std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;
```

Dalam deklarasi Min-Heap, wajib untuk menyebutkan parameter `Container` (`std::vector<int>`) secara eksplisit, meskipun itu adalah _default_. Hal ini dikarenakan C++ template mengharuskan penyediaan parameter kedua jika parameter ketiga (`Compare`) disediakan `[1, 12]`.

### 2.4. Inisialisasi dan Efisiensi

`std::priority_queue` dapat diinisialisasi dengan dua cara utama, dengan perbedaan kompleksitas waktu yang substansial:

1. **Pemasukan Inkremental:** Menyisipkan ![](data:,) elemen satu per satu menggunakan `push()`. Kompleksitas total adalah ![](data:,) `[13]`.
    
2. **Konstruksi Massal dari Range:** Menggunakan konstruktor yang menerima sepasang _iterator_ dari wadah lain (`InputIterator first, InputIterator last`). Konstruksi ini memanfaatkan algoritma _heap-building_ yang efisien, yang dikenal sebagai Algoritma Floyd, untuk membangun heap secara _bottom-up_. Kompleksitas waktu untuk membangun seluruh heap adalah ![](data:,) (linear), yang jauh lebih cepat daripada pemasukan inkremental ![](data:,) `[13]`.
    

## III. Operasi Standar dan Analisis Kompleksitas

Operasi pada `std::priority_queue` sangat terbatas, yang mencerminkan fungsi intinya sebagai struktur data untuk ekstraksi elemen ekstrem yang efisien.

### 3.1. Fungsi Modifikasi Data (`Modifiers`)

Operasi yang memodifikasi isi PQ memiliki kompleksitas waktu logaritmik, sesuai dengan waktu yang dibutuhkan untuk memulihkan properti heap.

- **`push(const value_type& val)`:** Menyisipkan elemen baru. Secara internal, operasi ini melibatkan penambahan elemen ke wadah dasar (`push_back`) dan kemudian memulihkan properti heap melalui algoritma `push_heap`. Kompleksitas waktu: ![](data:,) `[1, 5]`.
    
- **`emplace(Args&&... args)` (Sejak C++11):** Konstruksi elemen baru secara _in-place_, berpotensi mengurangi overhead penyalinan, tetapi dengan kompleksitas waktu yang sama, ![](data:,) `[6]`.
    
- **`pop()`:** Menghapus elemen prioritas tertinggi (yang berada di `top()`). Ini melibatkan pemindahan elemen teratas ke bagian belakang wadah (`pop_heap`) dan kemudian penghapusan fisik dari wadah dasar (`pop_back`). Kompleksitas waktu: ![](data:,) `[5, 8]`.
    

> **Peringatan Kritis:** Fungsi `pop()` mengembalikan `void` dan hanya menghapus elemen. Pengembang harus selalu mengakses nilai elemen melalui `top()` sebelum memanggil `pop()` `[8]`. Memanggil `top()` atau `pop()` pada antrian yang kosong menghasilkan _undefined behavior_ `[14]`.

### 3.2. Fungsi Akses Elemen dan Kapasitas

- **`top()`:** Mengembalikan referensi konstan ke elemen prioritas tertinggi. Kompleksitas waktu: ![](data:,) `[1, 5]`. Ini adalah keunggulan utama PQ, karena elemen yang diinginkan selalu berada di akar heap.
    
- **`empty()`:** Memeriksa apakah antrian kosong. Kompleksitas waktu: ![](data:,) `[5, 15]`.
    
- **`size()`:** Mengembalikan jumlah elemen. Kompleksitas waktu: ![](data:,) `[5, 15]`.
    
- **`swap(priority_queue& other)` (Sejak C++11):** Menukar konten dua PQ dengan tipe yang sama. Kompleksitas waktu: ![](data:,) `[1, 6]`.
    

### 3.3. Jaminan Kompleksitas Waktu (Big O)

Kinerja `std::priority_queue` adalah hasil langsung dari efisiensi operasi _binary heap_ pada wadah dasar array:

|**Operasi**|**Kompleksitas Waktu (Asimtomatik)**|**Keterangan**|
|---|---|---|
|`push()` (Pemasukan)|![](data:,)|Waktu yang diperlukan untuk menaikkan/menurunkan elemen baru.|
|`pop()` (Penghapusan Ekstremitas)|![](data:,)|Waktu yang diperlukan untuk menghapus dan mengatur ulang heap.|
|`top()` (Akses Elemen Ekstrem)|![](data:,)|Elemen prioritas tertinggi selalu berada di posisi pertama.|
|`empty()`, `size()`|![](data:,)|Operasi konstan.|
|Konstruksi dari Range|![](data:,)|Efisiensi linear untuk inisialisasi massal.|

Kompleksitas ![](data:,) untuk operasi modifikasi muncul karena tinggi pohon heap biner adalah ![](data:,). Operasi seperti `push` dan `pop` memerlukan waktu yang sebanding dengan tinggi pohon untuk memulihkan properti heap. Penting untuk dicatat bahwa biaya ![](data:,) ini didominasi oleh operasi _heapify_, sementara operasi wadah dasar (seperti `push_back` pada `std::vector`) biasanya hanya memiliki kompleksitas ![](data:,) yang diamortisasi `[16]`.

## IV. Teknik Kustomisasi Lanjutan dan Comparator Kompleks

Kemampuan untuk menyesuaikan kriteria prioritas adalah fitur krusial dari `std::priority_queue`, memungkinkan PQ digunakan untuk tipe data kustom atau skema pengurutan non-standar.

### 4.1. Filosofi Comparator Kustom

Komparator (parameter templat ketiga, `Compare`) harus berupa predikat biner yang mendefinisikan _Strict Weak Ordering_ `[4]`. Logika yang harus diikuti adalah: fungsi komparator `comp(a, b)` harus mengembalikan `true` jika dan hanya jika elemen ![](data:,) memiliki **prioritas yang lebih rendah** dibandingkan ![](data:,).

Untuk tipe data kustom (seperti `struct` atau `class`), pengembang dapat mendefinisikan prioritas menggunakan salah satu dari tiga metode berikut:

### 4.2. Implementasi dengan Mendefinisikan `operator<` Internal

Jika tipe data kustom dapat dimodifikasi, cara termudah adalah dengan meng-overload operator kurang dari (`operator<`) di dalam definisi kelas/struct `[17]`. Secara _default_, `std::priority_queue` akan menggunakan `std::less<T>`, yang kemudian memanggil `operator<` yang telah dimodifikasi.

C++

```
struct thing { 
    int a; 
    bool operator<(const thing& rhs) const { 
        return a < rhs.a; // Max-Heap akan memilih 'thing' dengan nilai 'a' terbesar
    } 
}; 
std::priority_queue<thing> q;
```

### 4.3. Implementasi dengan Functor (Function Object)

Metode Functor melibatkan pembuatan _struct_ terpisah yang meng-overload `operator()`. Ini berguna ketika tipe data kustom tidak dapat diubah atau ketika logika perbandingan sangat kompleks, melibatkan banyak kunci.

C++

```
struct example { int height; int weight; };
struct comp {
    bool operator()(struct example a, struct example b) {
        // Mengembalikan true jika 'a' prioritasnya lebih rendah dari 'b'
        return (a.height > b.height); // Min-Heap berdasarkan 'height'
    }
};
// Deklarasi:
priority_queue<example, vector<example>, comp> pq;
```

### 4.4. Implementasi dengan Lambda Expression (C++11/14+)

Lambda memberikan cara ringkas untuk mendefinisikan logika perbandingan secara _inline_. Namun, karena tipe data lambda adalah unik dan tidak bernama, deklarasi PQ harus menggunakan `decltype` untuk parameter komparator `[18]`.

C++

```
auto compare =(const Foo& a, const Foo& b) { 
    return a.i > b.i; // Min-Heap berdasarkan Foo::i
};
std::priority_queue<Foo, std::vector<Foo>, decltype(compare)> pq(compare); 
```

### 4.5. Stabilitas Urutan Elemen Prioritas Sama

Penting untuk dipahami bahwa `std::priority_queue` **tidak menjamin stabilitas** urutan pemrosesan untuk elemen-elemen yang memiliki prioritas yang sama `[2]`. Karena implementasi ini berdasarkan heap (yang tidak stabil), elemen dengan prioritas yang identik dapat diekstrak dalam urutan yang sewenang-wenang. Jika urutan FIFO untuk elemen yang setara adalah syarat kritis (misalnya, dalam sistem penjadwalan), pengembang harus menambahkan kunci sekunder (seperti _timestamp_ atau nomor urut) ke dalam komparator kustom untuk menciptakan _total ordering_ dan memastikan stabilitas `[19]`.

## V. Aplikasi Algoritmik Tingkat Tinggi dan Workaround Implementasi

`std::priority_queue` adalah komponen penting dalam banyak algoritma efisien, terutama yang melibatkan optimasi jalur atau penjadwalan.

### 5.1. Kasus Penggunaan Kritis

Aplikasi utama PQ meliputi:

- **Algoritma Graf:** Dijkstra's Shortest Path Algorithm dan Prim's Minimum Spanning Tree Algorithm `[2, 20]`. Kedua algoritma ini secara fundamental bergantung pada Min-Heap untuk selalu mengekstrak simpul dengan kunci (jarak atau bobot) terkecil `[2, 21]`.
    
- **Penjadwalan Sistem:** Penjadwalan CPU atau simulasi _event-driven_, seperti antrian di sistem medis (_triage_) `[1, 20]`.
    
- **Kompresi Data:** Huffman Coding `[20]`.
    
- **Order Statistics:** Masalah untuk menemukan _K Smallest_ atau _K Largest_ elemen dari suatu koleksi data yang besar atau yang sedang berjalan (data stream) `[20, 22]`.
    

### 5.2. Implementasi Algoritma Graf (Dijkstra dan Prim)

Dalam implementasi algoritma graf, PQ harus dikonfigurasi sebagai Min-Heap, biasanya menyimpan pasangan nilai `(prioritas, objek)`, di mana prioritas adalah elemen pertama agar dapat digunakan sebagai kunci pengurutan `[20]`.

Contoh untuk Dijkstra, PQ menyimpan `(distance, vertex)`:

C++

```
// Min-Heap berdasarkan jarak (elemen pertama pair)
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
```

### 5.3. Penanganan Keterbatasan _Decrease-Key_ (Lazy Deletion)

Salah satu keterbatasan desain `std::priority_queue` adalah kurangnya operasi `decrease-key` (memperbarui prioritas elemen yang sudah ada) secara langsung dan efisien ![](data:,) `[23, 24]`. Keterbatasan ini muncul karena sifatnya sebagai _container adaptor_ dengan antarmuka terbatas; ia tidak menyediakan cara untuk mengakses elemen internal di luar `top()` untuk diubah.

Dalam algoritma graf (Dijkstra, Prim), di mana jarak atau kunci simpul mungkin diperbarui menjadi nilai yang lebih rendah, keterbatasan ini diatasi dengan mekanisme **Lazy Deletion** (Penghapusan Malas) atau **Pemasukan Berganda** `[20, 25, 26]`.

1. **Pemasukan Berganda:** Ketika jalur yang lebih pendek ditemukan ke suatu simpul yang sudah ada di PQ, alih-alih memperbarui entri lama, entri baru dengan prioritas yang lebih baik (jarak yang lebih rendah) disisipkan kembali ke antrian `[25, 26]`.
    
2. **Ekstraksi dan Pemeriksaan:** Simpul yang baru disisipkan, karena memiliki prioritas lebih tinggi, akan diekstrak terlebih dahulu. Ketika entri lama (yang memiliki jarak lebih jauh/prioritas lebih rendah) pada akhirnya mencapai `top()`, algoritma akan memeriksa apakah simpul tersebut sudah diproses (misalnya, menggunakan _array_ jarak terpendek yang sudah tercatat). Jika terbukti entri tersebut sudah ketinggalan zaman, entri lama tersebut diabaikan (`continue`) dan dihapus dari PQ (`pop()`)—inilah yang disebut _Lazy Deletion_ `[20]`.
    

Meskipun metode ini menghasilkan _memory footprint_ karena menyimpan entri yang tidak valid, kompleksitas waktu asimptotik algoritma tetap terjaga optimal, ![](data:,), karena total elemen yang dimasukkan ke PQ dibatasi oleh jumlah _edge_ (![](data:,)) dalam graf, dan ![](data:,) sebanding dengan ![](data:,) `[20, 25]`.

## VI. Panduan Penggunaan Optimal: Perbandingan Struktur Data

Menentukan kapan waktu yang paling tepat untuk menggunakan `std::priority_queue` memerlukan perbandingan kritis terhadap struktur data terurut lainnya dalam STL.

### 6.1. Priority Queue vs. `std::vector` Terurut

Jika seluruh data sudah tersedia di awal, inisialisasi massal PQ (![](data:,)) lebih cepat daripada menyortir `std::vector` (![](data:,)) `[7, 13]`.

Namun, perbedaan utama muncul dalam operasi dinamis:

- **PQ Dinamis:** Pemasukan (`push`) dan penghapusan (`pop`) menjaga kompleksitas ![](data:,) `[19]`.
    
- **Vector Dinamis:** Menyisipkan atau menghapus elemen dari `std::vector` yang harus tetap terurut membutuhkan ![](data:,) karena elemen yang tersisa harus digeser di memori.
    

**Kesimpulan Penggunaan Optimal:** PQ adalah pilihan yang jelas dan superior dalam situasi di mana ada banyak operasi pemasukan dan penghapusan elemen prioritas tertinggi secara berkelanjutan, karena ia menjamin kinerja logaritmik, sementara `std::vector` terurut akan melambat menjadi kinerja linear.

### 6.2. Priority Queue vs. `std::set` (Balanced Binary Search Tree)

`std::set` (biasanya diimplementasikan sebagai Pohon Biner Pencarian Berimbang, seperti Red-Black Tree) menawarkan _total ordering_ dan akses ![](data:,) untuk hampir semua operasi.

|**Fitur**|**`std::priority_queue` (Heap)**|**`std::set` (Balanced BST)**|
|---|---|---|
|**Akses Elemen Ekstrem (`top()`)**|![](data:,) (Sangat Cepat)|![](data:,)|
|**Pemasukan/Penghapusan Dinamis**|![](data:,)|![](data:,)|
|**Konstruksi Massal ![](data:,) Elemen**|![](data:,) (Sangat Cepat)|![](data:,)|
|**Dukungan Iterasi/Akses Arbitrer**|Tidak Didukung (Hanya Top)|Ya (![](data:,) untuk pencarian/penghapusan)|
|**Dukungan _Decrease-Key_ Sejati**|Tidak (Hanya _Lazy Deletion_)|Ya (Penghapusan ![](data:,) dan Pemasukan ![](data:,))|
|**Kinerja Cache Locality**|Tinggi (Array Kontigu)|Rendah (Node-based)|

Meskipun kompleksitas asimptotik untuk _push/pop_ serupa (![](data:,)), PQ seringkali lebih unggul secara praktis karena:

1. **Akses Konstan:** Akses ![](data:,) ke elemen tertinggi (`top()`) `[6]`.
    
2. **Konstruksi Cepat:** Keunggulan ![](data:,) untuk inisialisasi `[27]`.
    
3. **Overhead Rendah:** Menggunakan `std::vector` (array) menghasilkan _cache locality_ yang jauh lebih baik, meminimalkan konstanta tersembunyi dalam ![](data:,) dan membuatnya lebih cepat dibandingkan struktur berbasis node `std::set` `[7]`.
    

Namun, `std::set` menjadi pilihan yang lebih unggul ketika kemampuan untuk **menghapus elemen arbitrer** (misalnya, entri lama) sangat dibutuhkan, karena ini memungkinkan simulasi operasi _decrease-key_ yang lebih bersih dalam ![](data:,) tanpa memerlukan _Lazy Deletion_ dan overhead memori terkait `[28]`.

## VII. Kesimpulan dan Rekomendasi Penggunaan Terbaik

Waktu yang paling tepat untuk menggunakan `std::priority_queue` adalah ketika kebutuhan inti dari aplikasi adalah pengelolaan dinamis suatu koleksi data dengan kriteria prioritas, dan hanya elemen ekstrem (tertinggi atau terendah) yang perlu diakses atau dihapus secara berulang.

### 7.1. Rekomendasi Kriteria Keputusan

`std::priority_queue` adalah solusi yang efisien dan optimal dalam kasus-kasus berikut:

1. **Prioritas Dinamis dan Ekstraksi Berulang:** Ketika aplikasi memerlukan akses tercepat (![](data:,)) ke elemen terbaik, diikuti oleh penghapusan dan penyisipan logaritmik (![](data:,)). Contoh klasik adalah simulasi dan penjadwalan.
    
2. **Implementasi Algoritma Graf:** Untuk implementasi standar algoritma Dijkstra dan Prim, di mana mekanisme _Lazy Deletion_ adalah solusi yang dapat diterima dan mempertahankan kompleksitas waktu optimal ![](data:,).
    
3. **Data Statis Awal:** Jika data input tersedia secara massal, memanfaatkan konstruktor _range_ untuk mencapai inisialisasi ![](data:,) adalah keuntungan kinerja yang besar.
    

### 7.2. Keterbatasan Utama

Pengembang harus mempertimbangkan keterbatasan utama `std::priority_queue` sebelum menggunakannya:

- **Tidak Mendukung Akses Penuh:** Tidak memungkinkan iterasi, pencarian, atau penghapusan elemen non-ekstrem.
    
- **Masalah _Decrease-Key_:** Tidak ada operasi pembaruan prioritas yang efisien, memaksa penggunaan _Lazy Deletion_ untuk algoritma seperti Dijkstra `[24]`.
    
- **Ketidakstabilan Urutan Prioritas Sama:** Tidak menjamin bahwa dua elemen dengan prioritas yang sama akan diekstrak berdasarkan urutan penyisipannya (FIFO) `[2]`.
    

Struktur data ini menawarkan keseimbangan sempurna antara kemudahan penggunaan (melalui antarmuka adaptor) dan performa yang optimal secara asimptotik (melalui _binary heap_ berbasis array) untuk semua skenario di mana fokus utamanya adalah akses cepat ke elemen ekstrem.