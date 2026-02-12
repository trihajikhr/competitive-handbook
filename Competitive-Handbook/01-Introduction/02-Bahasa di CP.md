---
obsidianUIMode: preview
note_type: book theory
judul_materi: Bahasa di CP
sumber:
  - geeksforgeeks.org
  - "buku: CP handbook by Antti Laaksonen"
  - gemini.google.com
date_learned: 2026-02-12T22:39:00
tags:
  - introduction
---
Link Sumber: [5 Best Languages for Competitive Programming - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/5-best-languages-for-competitive-programming/)

---

> [!IMPORTANT]
>  

# 1. 5 Bahasa Pemrograman Competitive Programming

> Source: geeksforgeeks.org

Dalam lanskap teknologi informasi yang berkembang pesat menuju tahun 2026, kompetensi dalam Struktur Data dan Algoritma (DSA) tetap menjadi fondasi utama bagi setiap pengembang perangkat lunak, terutama bagi mereka yang terjun dalam arena pemrograman kompetitif (Competitive Programming/CP). Pemilihan bahasa pemrograman dalam konteks ini bukan sekadar masalah estetika sintaksis, melainkan keputusan strategis yang melibatkan perhitungan matang terhadap kecepatan eksekusi, efisiensi memori, ketersediaan pustaka standar, dan kecepatan penulisan kode. Meskipun keterampilan pemecahan masalah dan penguasaan algoritma adalah faktor yang paling menentukan keberhasilan seorang pemrogram, alat yang digunakan—yaitu bahasa pemrograman—memiliki peran krusial dalam menentukan apakah sebuah solusi dapat melewati batasan waktu (time limit) dan memori (memory limit) yang ketat dalam sebuah kontes.

## 1.1. Eksistensi dan Evolusi Bahasa dalam Pemrograman Kompetitif

Dunia pemrograman kompetitif telah menyaksikan dominasi beberapa bahasa utama selama dekade terakhir. Berdasarkan data popularitas dan rekomendasi dari platform terkemuka seperti GeeksforGeeks, Codeforces, dan LeetCode, terdapat lima bahasa yang secara konsisten menonjol: C++, Java, Python, Ruby, dan Kotlin. Setiap bahasa ini membawa filosofi desain yang berbeda, yang pada gilirannya menciptakan pengalaman pengembangan yang unik bagi para penggunanya. Sebagai contoh, C++ menawarkan performa mentah yang hampir setara dengan bahasa mesin, sementara Python memprioritaskan keterbacaan dan produktivitas pengembang di atas kecepatan eksekusi murni.

Tren tahun 2025 menunjukkan bahwa meskipun Python terus mendominasi pasar pendidikan dan kecerdasan buatan, posisi C++ dalam ranah pemrograman kompetitif tingkat tinggi tetap tidak tergoyahkan karena efisiensi performanya. Di sisi lain, munculnya bahasa modern seperti Kotlin memberikan alternatif bagi mereka yang menginginkan stabilitas Java namun dengan sintaksis yang lebih ringkas dan fitur keselamatan yang lebih baik.

|**Bahasa Pemrograman**|**Karakteristik Utama**|**Status dalam CP**|
|---|---|---|
|C++|Performa tinggi, kontrol memori manual, STL kuat|Standar Industri & Dominan|
|Java|Platform-independent, BigInteger, manajemen memori otomatis|Populer di Perusahaan & ICPC|
|Python|Sintaksis ringkas, library luas, eksekusi lambat|Favorit Pemula & Wawancara|
|Ruby|Berorientasi objek murni, fleksibel, ramah pengembang|Niche & Produktif|
|Kotlin|Modern, ringkas, interoperabilitas dengan Java|Tren Meningkat|

## 1.2. C++: Standar Emas untuk Performa dan Efisiensi

C++, yang dikembangkan oleh Bjarne Stroustrup, secara luas diakui sebagai raja dalam dunia pemrograman kompetitif. Alasan utamanya adalah kecepatan eksekusinya yang sangat tinggi karena sifatnya sebagai bahasa yang dikompilasi langsung menjadi kode mesin. Dalam konteks kontes di mana selisih milidetik dapat menentukan peringkat, efisiensi C++ memberikan margin keamanan yang signifikan bagi pengembang untuk menghindari kesalahan _Time Limit Exceeded_ (TLE).

### 1.2.1. Pustaka Templat Standar (Standard Template Library - STL)

Kekuatan utama C++ terletak pada Standard Template Library (STL). STL menyediakan berbagai struktur data dan algoritma yang telah dioptimalkan, yang memungkinkan peserta kontes untuk mengimplementasikan solusi kompleks dengan cepat tanpa harus menulis kode dari dasar. Komponen STL yang paling sering digunakan meliputi:

1. **Container**: Koleksi objek yang disimpan dalam memori, seperti `vector` (array dinamis), `set` (himpunan terurut), `map` (pasangan kunci-nilai), `stack`, `queue`, dan `priority_queue`.
    
2. **Algorithm**: Fungsi global untuk memanipulasi container, termasuk `sort()`, `binary_search()`, `lower_bound()`, dan `next_permutation()`.
    
3. **Iterator**: Objek yang berfungsi seperti pointer untuk menelusuri elemen-elemen dalam container.
    

Penggunaan `std::vector`, misalnya, memberikan fleksibilitas array dinamis dengan kompleksitas waktu akses $O(1)$, sementara `std::priority_queue` sangat penting untuk algoritma graf seperti Dijkstra atau Prim. Keberadaan kontainer terurut seperti `std::set` dan `std::map`, yang biasanya diimplementasikan sebagai Red-Black Tree, memastikan operasi penyisipan dan pencarian tetap dalam batas $O(\log n)$.

### 1.2.2. Policy-Based Data Structures (PBDS)

Selain STL standar, C++ dalam lingkungan GNU (g++) menawarkan Policy-Based Data Structures (PBDS) yang merupakan "permata tersembunyi" bagi pemrogram kompetitif tingkat lanjut. Salah satu fitur unggulannya adalah `ordered_set`, yang memungkinkan pengembang untuk melakukan operasi seperti `find_by_order(k)` (menemukan elemen terkecil ke-$k$) dan `order_of_key(x)` (menghitung jumlah elemen yang lebih kecil dari $x$) dalam waktu logaritmik—operasi yang tidak didukung secara langsung oleh `std::set` standar. PBDS juga mencakup implementasi tabel hash yang sangat cepat seperti `gp_hash_table`, yang sering kali lebih efisien daripada `std::unordered_map` standar dalam menghadapi beban kerja tertentu.

### 1.2.3. Optimasi I/O dan Bit Manipulation

C++ memberikan kontrol tingkat rendah yang memungkinkan optimasi mikro yang krusial. Teknik _Fast I/O_ menggunakan `ios::sync_with_stdio(0); cin.tie(0);` dapat mempercepat pembacaan input secara dramatis, sering kali menjadi perbedaan antara solusi yang diterima (Accepted) dan yang gagal (TLE) pada masalah dengan volume data besar ($>10^5$ baris). Selain itu, dukungan terhadap manipulasi bit tingkat rendah melalui `std::bitset` atau operasi bitwise murni memungkinkan optimasi ruang dan waktu pada algoritma berbasis mask yang sulit dilakukan seefisien itu di bahasa lain.

## 1.3. Java: Stabilitas, Objek, dan Keunggulan BigInteger

Java tetap menjadi pilihan utama bagi banyak pemrogram kompetitif, terutama mereka yang berpartisipasi dalam ajang International Collegiate Programming Contest (ICPC). Filosofi "Write Once, Run Anywhere" yang didukung oleh Java Virtual Machine (JVM) memberikan stabilitas platform yang luar biasa. Meskipun secara historis dianggap lebih lambat daripada C++, optimasi kompilasi Just-In-Time (JIT) modern membuat performa Java sangat kompetitif dalam banyak skenario algoritmik.

### 1.3.1. Penanganan Angka Sangat Besar (BigInteger)

Salah satu keunggulan absolut Java dibandingkan C++ adalah keberadaan kelas `java.math.BigInteger` dan `java.math.BigDecimal`. Dalam masalah matematika yang melibatkan angka dengan ratusan atau ribuan digit—yang sering muncul dalam teori bilangan atau kriptografi—Java memungkinkan pengembang untuk melakukan operasi aritmatika tanpa risiko overflow yang biasanya terjadi pada tipe data primitif 64-bit. Sementara pengguna C++ mungkin harus mengimplementasikan logika angka besar mereka sendiri dari awal, pengguna Java dapat memanggil metode bawaan yang andal.

### 1.3.2. Ekosistem Kontainer dan Pustaka Geometri

Java memiliki koleksi kontainer yang sangat kaya dalam paket `java.util`, termasuk `ArrayList`, `HashMap`, `TreeMap`, dan `PriorityQueue`. Struktur data ini sangat matang dan memiliki dokumentasi yang luar biasa. Selain itu, Java memiliki pustaka geometri standar yang kuat yang dapat membantu dalam menyelesaikan masalah komputasi geometri yang rumit, seperti pencarian convex hull atau perpotongan garis.

### 1.3.3. Tantangan I/O dan Solusi FastScanner

Masalah performa yang paling umum dihadapi pengguna Java dalam CP adalah penggunaan kelas `java.util.Scanner` yang lambat. `Scanner` menggunakan ekspresi reguler secara internal untuk mem-parsing input, yang menyebabkan overhead besar pada dataset yang padat. Untuk mengatasi ini, para ahli merekomendasikan penggunaan `BufferedReader` yang digabungkan dengan `StringTokenizer`, atau bahkan mengimplementasikan kelas `FastReader` kustom.

|**Metode Input Java**|**Kecepatan**|**Kelebihan**|**Kekurangan**|
|---|---|---|---|
|`Scanner`|Lambat|Mudah digunakan, fleksibel|Menyebabkan TLE pada input besar|
|`BufferedReader`|Cepat|Standar industri, efisien|Memerlukan parsing manual|
|`FastReader` (Custom)|Sangat Cepat|Optimal untuk CP|Memerlukan kode boilerplate tambahan|
|`DataInputStream`|Tercepat|Langsung ke byte|Sangat kompleks, sulit diimplementasikan|

Manajemen memori di Java dikelola secara otomatis melalui Garbage Collector (GC). Meskipun ini mencegah kebocoran memori (memory leaks), proses GC terkadang dapat menyebabkan jeda eksekusi yang tidak terduga, yang harus dipertimbangkan ketika bekerja dengan batas waktu yang sangat ketat. Namun, keuntungan keamanan tipe dan penanganan pengecualian (*exception handling*) yang lebih baik sering kali menutupi kekurangan performa kecil tersebut.

## 1.4. Python: Kecepatan Pengembangan dan Fleksibilitas Luar Biasa

Python telah merevolusi cara pemula mendekati pemrograman kompetitif. Sebagai bahasa tingkat tinggi dengan sintaksis yang sangat bersih, Python memungkinkan pengembang untuk mengubah ide menjadi kode dalam waktu yang sangat singkat dibandingkan dengan C++ atau Java. Riset menunjukkan bahwa kode Python biasanya 3 hingga 5 kali lebih pendek daripada kode Java dan 5 hingga 10 kali lebih pendek daripada C++ untuk masalah yang sama.

### 1.4.1. Fitur Intrinsik yang Menguntungkan

Python menawarkan beberapa fitur unik yang sangat bermanfaat dalam kontes algoritma:

1. **Arbitrary Precision Integers**: Secara default, integer di Python 3 tidak memiliki batas ukuran (selama memori tersedia), bertindak seperti `BigInteger` di Java secara otomatis.
    
2. **Multiple Return Values**: Fungsi dapat mengembalikan beberapa nilai sekaligus dalam bentuk tuple, memudahkan penanganan fungsi rekursif yang kompleks.
    
3. **List Comprehensions dan Slicing**: Memungkinkan manipulasi array dan data secara deklaratif dan sangat ringkas.
    
4. **Library Pendukung**: Modul seperti `bisect` untuk pencarian biner, `heapq` untuk antrean prioritas, dan `itertools` untuk menghasilkan permutasi dan kombinasi sangat mempercepat proses koding.
    

### 1.4.2. Kendala Performa dan Pengganda Waktu (Multiplier)

Kelemahan fatal Python adalah kecepatan eksekusinya yang lambat karena statusnya sebagai bahasa yang diinterpretasikan. Python sering kali 10 hingga 100 kali lebih lambat daripada C++ dalam operasi intensif komputasi. Untuk menyeimbangkan ini, banyak platform seperti LeetCode memberikan pengganda waktu (*time limit multiplier*) untuk Python, namun platform lain seperti Codeforces biasanya memberlakukan batas waktu yang sama untuk semua bahasa, yang memaksa pengguna Python untuk menggunakan algoritma dengan kompleksitas waktu yang lebih rendah daripada pengguna C++.

Karena Python lambat dalam iterasi loop, pengembang sering kali harus mengandalkan fungsi bawaan (*built-in functions*) yang diimplementasikan dalam bahasa C di balik layar untuk mencapai performa yang dapat diterima. Penggunaan `collections.deque` sangat disarankan daripada menggunakan list biasa untuk operasi antrean (FIFO) karena performa $O(1)$ pada operasi penyisipan dan penghapusan di kedua ujung.

## 1.5. Ruby: Filosofi Produktivitas dalam Arena Kompetisi

Ruby, meskipun kurang populer dibandingkan "Tiga Besar" (C++, Java, Python), tetap menjadi pilihan yang menarik bagi mereka yang menghargai fleksibilitas dan orientasi objek murni. Ruby mengikuti prinsip "Least Surprise," yang berarti bahasa ini dirancang untuk meminimalkan kebingungan bagi pemrogram.

### 1.5.1. Fleksibilitas dan Ekspresi

Ruby sangat ramah pengguna dan fleksibel. Sebagai bahasa dinamis, Ruby memungkinkan perubahan struktur program pada saat runtime, yang dapat berguna dalam teknik meta-programming tertentu selama kontes. Dukungan Ruby terhadap angka besar (Bignum) juga otomatis, serupa dengan Python, yang mempermudah kalkulasi matematika skala besar.

### 1.5.2. Metode Bawaan dan Penulisan Ringkas

Ruby menyediakan metode bawaan yang sangat kuat untuk koleksi, seperti `.each`, `.map`, `.select`, dan `.inject`. Penggunaan blok dan lambda di Ruby memberikan cara yang sangat elegan untuk menangani iterasi dan transformasi data tanpa memerlukan banyak baris kode boilerplate. Namun, seperti halnya Python, Ruby adalah bahasa skrip yang diinterpretasikan, yang membuatnya tertinggal dalam hal kecepatan dibandingkan bahasa yang dikompilasi seperti C++ atau Java. Hal ini menjadikan Ruby lebih cocok untuk masalah di mana kecepatan pengembangan lebih diutamakan daripada efisiensi runtime murni.

## 1.6. Kotlin: Jembatan Antara Modernitas dan Performa JVM

Kotlin muncul sebagai pesaing baru yang menjanjikan dalam pemrograman kompetitif sejak diperkenalkan oleh JetBrains. Sebagai bahasa yang sepenuhnya interoperabel dengan Java, Kotlin memungkinkan pengembang untuk menggunakan semua pustaka Java yang kuat sambil menikmati fitur bahasa modern yang jauh lebih ringkas.

### 1.6.1. Keunggulan Modern untuk Algoritma

Kotlin menawarkan beberapa fitur yang sangat meningkatkan pengalaman kompetitif:

1. **Null Safety**: Menghilangkan risiko `NullPointerException` melalui sistem tipe yang ketat, yang membantu mengurangi bug selama tekanan waktu kontes.
    
2. **Smart Casts dan Type Inference**: Mengurangi kebutuhan untuk boilerplate casting dan deklarasi tipe yang eksplisit, membuat kode lebih bersih.
    
3. **Extension Functions**: Memungkinkan pengembang untuk menambahkan fungsi baru ke kelas yang sudah ada tanpa harus mewarisinya, sangat berguna untuk membangun pustaka utilitas pribadi untuk CP.
    
4. **Functional Programming Support**: Dukungan kuat untuk paradigma fungsional seperti fungsi tingkat tinggi dan lambda memungkinkan transformasi data yang sangat efisien secara sintaksis.
    

### 1.6.2. Performa dan Implementasi di CP

Kotlin berjalan pada JVM dan menawarkan performa yang hampir identik dengan Java. Meskipun beberapa fitur idiomatik Kotlin mungkin memiliki sedikit overhead dibandingkan kode Java yang setara (seperti penggunaan `copy()` pada data classes), efisiensi koding yang didapat sering kali dianggap sepadan. Platform seperti Codeforces telah memberikan dukungan penuh bagi Kotlin, dan bahkan mengadakan kontes khusus seperti "Kotlin Heroes" untuk mempromosikan penggunaannya dalam komunitas kompetitif.

## 1.7. Analisis Komparatif: Memilih Alat yang Tepat Berdasarkan Kebutuhan

Dalam memilih bahasa pemrograman terbaik untuk tahun 2026, seorang pengembang harus mempertimbangkan tujuan akhir mereka. Apakah tujuannya adalah memenangkan kompetisi tingkat dunia, lulus wawancara di perusahaan FAANG, atau sekadar memperkuat pemahaman tentang struktur data?

### 1.7.1 Perbandingan Kecepatan, Memori, dan Kemudahan

|**Kriteria**|**C++**|**Java**|**Python**|**Kotlin**|**Ruby**|
|---|---|---|---|---|---|
|Kecepatan Eksekusi|Tercepat (1x)|Cepat (1.5x-2x)|Lambat (5x-50x)|Cepat (1.5x-2x)|Lambat (7x-60x)|
|Konsumsi Memori|Sangat Rendah|Sedang/Tinggi|Sedang|Sedang/Tinggi|Sedang|
|Kecepatan Koding|Sedang|Lambat (Verbose)|Sangat Cepat|Cepat|Sangat Cepat|
|Kurva Belajar|Curam/Sulit|Menengah|Sangat Mudah|Menengah|Mudah|
|Library DSA (Bawaan)|STL (Sangat Kuat)|Collections (Kuat)|Standar (Lengkap)|JVM (Sangat Kuat)|Standar (Fleksibel)|

### 1.7.2. Statistik Popularitas dan Tren Global 2024-2025

Berdasarkan data dari Indeks TIOBE dan survei Stack Overflow tahun 2025, Python mempertahankan posisi pertama sebagai bahasa yang paling banyak digunakan secara umum, diikuti oleh JavaScript dan Java. Namun, dalam sub-domain pemrograman kompetitif, C++ tetap memegang pangsa pasar sekitar 90% di kalangan tim peserta ICPC.

- **Python** memimpin dalam indeks PYPL dengan pangsa sekitar 28.97%, menunjukkan dominasinya dalam tutorial dan pembelajaran mandiri.
    
- **C++** menunjukkan tren positif yang stabil, naik ke posisi kedua dalam indeks TIOBE (Februari 2025) melampaui Java dan C.
    
- **Kotlin** terus meningkat secara perlahan, didorong oleh statusnya sebagai bahasa utama pengembangan Android dan fitur-fitur modernnya yang menarik bagi pemrogram Java yang lelah dengan verbositas.
    

## 1.8. Implikasi Praktis dalam Rekayasa Perangkat Lunak dan Karier

Pemilihan bahasa untuk pemrograman kompetitif sering kali memiliki efek riak pada karier profesional seorang pengembang. Pengetahuan mendalam tentang C++ dan manajemen memori manual sangat dihargai di sektor-sektor seperti pengembangan sistem, mesin game (*game engines*), dan perdagangan frekuensi tinggi (*High-Frequency Trading*). Sebaliknya, kefasihan dalam Python sering kali menjadi prasyarat untuk peran dalam Ilmu Data, Pembelajaran Mesin, dan otomatisasi.

Java dan Kotlin tetap menjadi standar emas dalam pengembangan aplikasi tingkat perusahaan dan infrastruktur backend skala besar, di mana stabilitas dan skalabilitas lebih diutamakan daripada performa mentah tingkat mikro. Kemampuan untuk berpindah antar bahasa berdasarkan kebutuhan proyek adalah keterampilan yang membedakan pengembang senior dari pemula.

### 1.8.1. Persiapan Wawancara Teknis (LeetCode & FAANG)

Untuk persiapan wawancara teknis, banyak mentor menyarankan penggunaan **Python** karena keterbacaannya. Pewawancara lebih tertarik pada proses berpikir dan kemampuan pemecahan masalah kandidat daripada kemampuan mereka untuk mengelola memori atau menulis sintaksis yang rumit. Namun, kandidat harus tetap menyadari kompleksitas waktu dari fungsi bawaan Python agar tidak terjebak dalam solusi yang terlihat efisien namun sebenarnya lambat secara internal.

### 1.8.2. Skenario Penggunaan Strategis

1. **Jika tujuan Anda adalah kemenangan murni dalam kontes (Codeforces, AtCoder)**: Gunakan C++. Kecepatan eksekusi dan STL adalah keuntungan yang tidak bisa diabaikan.
    
2. **Jika Anda menghadapi masalah matematika yang melibatkan angka raksasa**: Pertimbangkan Java (untuk BigInteger) atau Python/Ruby yang menanganinya secara transparan.
    
3. **Jika Anda membangun aplikasi Android atau sistem backend modern sambil tetap ingin aktif di CP**: Kotlin adalah pilihan yang sangat seimbang.
    
4. **Jika Anda seorang pemula yang ingin fokus pada logika algoritma tanpa pusing dengan sintaksis**: Mulailah dengan Python.
    

## 1.9. Masa Depan Bahasa Pemrograman Kompetitif: Rust dan AI

Melihat ke depan, munculnya bahasa seperti **Rust** mulai memberikan tekanan pada dominasi C++. Rust menawarkan performa yang sebanding dengan C++ tetapi dengan jaminan keamanan memori (*memory safety*) tanpa garbage collector. Meskipun saat ini Rust belum didukung secara luas di semua ajang kompetisi (seperti ICPC yang masih membatasi penggunaan bahasa tertentu), popularitasnya di kalangan pengembang sistem profesional diperkirakan akan membawa Rust ke panggung kompetitif secara lebih luas dalam beberapa tahun ke depan.

Selain itu, integrasi Kecerdasan Buatan (AI) dalam proses koding—seperti penggunaan asisten AI untuk menghasilkan boilerplate atau membantu debugging—mungkin akan mengurangi kerugian verbositas pada bahasa seperti Java dan memperkuat posisi bahasa yang memiliki ekosistem AI yang kuat seperti Python. Namun, tantangan inti dari pemrograman kompetitif—yaitu merancang algoritma yang benar secara logika dan efisien secara kompleksitas—akan tetap menjadi ujian murni bagi kecerdasan manusia yang melampaui pilihan alat apa pun.

## 1.10. Kesimpulan: Sintesis Pemilihan Bahasa sebagai Keunggulan Kompetitif

Memahami kekuatan dan kelemahan masing-masing bahasa pemrograman adalah bagian integral dari perjalanan seorang pemrogram kompetitif. C++ tetap menjadi alat yang paling tajam untuk performa eksekusi; Java menawarkan ketangguhan dan pustaka kelas angka besar yang tak tertandingi; Python memberikan kecepatan pengembangan yang luar biasa bagi mereka yang dapat mengelola kendala kecepatannya; Ruby menawarkan kebahagiaan dalam ekspresi logika; dan Kotlin menghadirkan modernitas fungsional ke dalam ekosistem JVM.

Seorang profesional yang bijak tidak hanya setia pada satu bahasa, tetapi memahami kapan harus menggunakan instrumen yang tepat untuk masalah yang tepat. Pada akhirnya, penguasaan atas Struktur Data dan Algoritma adalah fondasi yang universal, sementara bahasa hanyalah saluran yang melaluinya kreativitas pemecahan masalah itu diwujudkan ke dalam solusi nyata yang efisien dan elegan. Kesuksesan di tahun 2025 dan masa depan akan bergantung pada kemampuan untuk beradaptasi dengan alat baru sambil tetap berpegang teguh pada prinsip-prinsip dasar ilmu komputer yang tak lekang oleh waktu.


<br/>

---
# 2. Bahasa di Competitive Programming

> Source: Competitive Programming Handbook by Antti Laaksonen

Saat ini, bahasa pemrograman yang paling populer digunakan dalam kontes adalah C++, Python, dan Java. Misalnya, dalam **Google Code Jam 2017**, di antara 3.000 peserta terbaik, 79% menggunakan C++, 16% menggunakan Python, dan 8% menggunakan Java. Beberapa peserta juga menggunakan beberapa bahasa.

Banyak orang berpendapat bahwa C++ adalah pilihan terbaik untuk seorang competitive programmer, dan C++ hampir selalu tersedia di sistem kontes. Keuntungan menggunakan C++ adalah bahwa ini adalah bahasa yang sangat efisien dan pustaka standarnya mengandung banyak struktur data dan algoritma.

Di sisi lain, ada baiknya menguasai beberapa bahasa pemrograman dan memahami kekuatannya. Misalnya, jika angka besar dibutuhkan dalam masalah, Python bisa menjadi pilihan yang baik, karena memiliki operasi built-in untuk perhitungan dengan angka besar. Namun, sebagian besar masalah dalam kontes pemrograman disusun sedemikian rupa sehingga penggunaan bahasa pemrograman tertentu tidak memberikan keuntungan yang tidak adil.

Semua contoh program dalam buku ini ditulis dalam C++, dan struktur data serta algoritma dari pustaka standar sering digunakan. Program-program ini mengikuti standar **C++11**, yang dapat digunakan dalam sebagian besar kontes saat ini. Jika kamu belum bisa memrogram menggunakan C++, sekarang adalah waktu yang tepat untuk mulai belajar.