---
tags:
  - introduction
---

# Bahasa dalam Competitive Programming

Dalam competitive programming, beberapa bahasa pemrograman lebih populer dibandingkan yang lain karena kecepatan eksekusi, fleksibilitas, dan dukungan pustaka bawaan. Berikut adalah tiga bahasa utama yang paling sering digunakan, urutan berdasarkan popularitas:

## C++
1. Kecepatan Eksekusi Tinggi
	- C++ adalah bahasa yang dikompilasi (compiled), bukan interpreted seperti Python, sehingga eksekusi program jauh lebih cepat.
	- Dalam kompetisi, sering ada batasan waktu yang ketat, dan C++ memungkinkan peserta menangani batasan waktu lebih baik daripada bahasa lain.

2. STL (Standard Template Library):
	- STL menyediakan struktur data dan algoritma bawaan yang sangat cepat dan optimal.
	- Contohnya:
	    - `vector` → Array dinamis yang fleksibel.
	    - `set` dan `map` → Struktur data berbasis tree untuk pencarian cepat.
	    - `priority_queue` → Implementasi heap yang efisien.
	    - `unordered_map` → Hash table dengan pencarian $O(1)$.
	    - `sort()` → Algoritma sorting yang sangat cepat dengan kompleksitas $O(n \log n)$.

3. Manipulasi Memori yang Efisien:
	- C++ memungkinkan alokasi memori manual dengan pointer dan `malloc()`, yang bisa digunakan untuk optimasi ekstrem.
	- Tidak ada garbage collection seperti di Java atau Python, sehingga lebih cepat.

4. Kompatibilitas dengan Algoritma CP:
	- Banyak algoritma yang diajarkan di CP langsung menggunakan sintaks C++, sehingga peserta lebih mudah menerapkannya.

Namun, seperti banyak hal pada umumnya, tidak ada kelebihan tanpa kekurangan. Berikut kekurangan dari C++:

1. Debugging lebih sulit
	Tidak memiliki error handling bawaan seperti Python.  

2. Sintaks kompleks
	Membutuhkan pemahaman mendalam tentang pointer, reference, dan memory management.

!!! tip
	C++ adalah bahasa yang paling populer dalam CP karena kecepatan dan STL yang sangat kuat.


## Python
1. Sintaks yang lebih mudah dan ringkas
	- Peserta dapat menulis kode yang lebih pendek dan lebih mudah dibaca dibandingkan C++.
	- Contoh sorting dalam Python hanya perlu satu baris:
	    
	    ```python
	    arr.sort()
	    ```
	    
	    Sementara di C++:
	    
	    ```cpp
	    sort(arr.begin(), arr.end());
	    ```
   
2. Dukungan Pustaka yang Kuat
	- Python memiliki pustaka seperti `collections.Counter`, `heapq` (priority queue), dan `itertools` yang bisa membantu menyelesaikan masalah CP dengan lebih sedikit kode.

3. Tipe Data Fleksibel
	- Integer bisa otomatis menjadi besar (Big Integer), sementara di C++ kita harus menggunakan `long long`.
	- List bisa menampung berbagai tipe data sekaligus.

Namun, seperti banyak hal pada umumnya, tidak ada kelebihan tanpa kekurangan. Berikut kekurangan dari Python:

1. Eksekusi Lebih Lambat (10x lebih lambat dari C++)
	- Karena Python adalah bahasa interpreted, tidak secepat C++ dalam eksekusi.
	- Untuk soal yang membutuhkan pengolahan data dalam jumlah besar (misal: 10⁶ operasi), Python bisa TLE (Time Limit Exceeded).

2. Tidak Ada Tipe Data Statis
- Python tidak memiliki deklarasi tipe data seperti `int`, `long long`, atau `double`, sehingga bisa terjadi overhead dalam eksekusi.

!!! tip
	Python cocok untuk debugging dan pemula, tapi kurang optimal untuk soal-soal dengan batasan waktu ketat.

## Java

1. Kecepatan Eksekusi di Tengah-tengah
	- Java lebih lambat dari C++, tetapi lebih cepat dari Python.
	- Java dikompilasi menjadi bytecode yang dieksekusi oleh JVM (Java Virtual Machine), membuatnya cukup cepat.
2. Garbage Collection Otomatis
	- Java secara otomatis mengelola memori, mengurangi kemungkinan kesalahan pointer seperti di C++.
3. Dukungan Struktur Data yang Kuat

	- `ArrayList` → Alternatif `vector` di C++.
	- `TreeSet`, `HashSet` → Untuk pencarian cepat.
	- `PriorityQueue` → Untuk heap seperti `priority_queue` di C++.

Namun, seperti banyak hal pada umumnya, tidak ada kelebihan tanpa kekurangan. Berikut kekurangan dari Java:

1. Sintaks Lebih Panjang
	- Menulis kode lebih panjang dibandingkan C++ dan Python.
	- Contoh deklarasi input di Java:
	    
	    ```java
	    Scanner sc = new Scanner(System.in);
	    int n = sc.nextInt();
	    ```
	    
	    Sementara di C++ cukup:
	    
	    ```cpp
	    int n;
	    cin >> n;
	    ```

2. Startup Time Lebih Lambat
	- JVM membutuhkan waktu tambahan untuk startup, membuatnya lebih lambat dibandingkan C++.

!!! tip
	Kesimpulan → Java cukup kuat untuk CP, tetapi sintaksnya lebih panjang dibandingkan C++.

## Materi tambahan
???+ info
	Materi dari [Competitive Programming Handbook by Antti Laaksonen](https://cses.fi/book.pdf)

Saat ini, bahasa pemrograman yang paling populer digunakan dalam kontes adalah C++, Python, dan Java. Misalnya, dalam **Google Code Jam 2017**, di antara 3.000 peserta terbaik, 79% menggunakan C++, 16% menggunakan Python, dan 8% menggunakan Java. Beberapa peserta juga menggunakan beberapa bahasa.

Banyak orang berpendapat bahwa C++ adalah pilihan terbaik untuk seorang competitive programmer, dan C++ hampir selalu tersedia di sistem kontes. Keuntungan menggunakan C++ adalah bahwa ini adalah bahasa yang sangat efisien dan pustaka standarnya mengandung banyak struktur data dan algoritma.

Di sisi lain, ada baiknya menguasai beberapa bahasa pemrograman dan memahami kekuatannya. Misalnya, jika angka besar dibutuhkan dalam masalah, Python bisa menjadi pilihan yang baik, karena memiliki operasi built-in untuk perhitungan dengan angka besar. Namun, sebagian besar masalah dalam kontes pemrograman disusun sedemikian rupa sehingga penggunaan bahasa pemrograman tertentu tidak memberikan keuntungan yang tidak adil.

Semua contoh program dalam buku ini ditulis dalam C++, dan struktur data serta algoritma dari pustaka standar sering digunakan. Program-program ini mengikuti standar **C++11**, yang dapat digunakan dalam sebagian besar kontes saat ini. Jika kamu belum bisa memrogram menggunakan C++, sekarang adalah waktu yang tepat untuk mulai belajar.