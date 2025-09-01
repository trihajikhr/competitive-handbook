---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSAR-0002
nama_algoritma:
kategori_algoritma: data structure
kesulitan: 🥉 easy
time_complexity:
memory_complexity:
sumber:
  - programiz.com
  - Gemini AI
date_learned: 2025-06-11T13:56:00
tags:
  - data-structure
  - array
---
---
# 1 | Pendahuluan: Memahami Array dalam C++

Array merupakan salah satu struktur data fundamental dalam pemrograman C++ yang berfungsi sebagai wadah untuk menyimpan kumpulan objek atau nilai dengan tipe data yang seragam. Elemen-elemen ini diatur secara berurutan dan menempati area memori yang berdekatan atau kontigu. Dengan demikian, array memungkinkan penyimpanan banyak nilai dalam satu variabel tunggal, yang kemudian dapat diakses secara individual melalui penggunaan indeks.

Keunggulan utama dari array terletak pada efisiensi akses memorinya. Karena semua elemen disimpan secara kontigu di memori, sistem dapat memanfaatkan prinsip _cache locality_ dengan optimal. Ketika satu elemen diakses, elemen-elemen di sekitarnya yang berada di lokasi memori yang berdekatan kemungkinan besar akan secara otomatis dimuat ke dalam _cache_ CPU. Hal ini secara signifikan mempercepat akses berikutnya ke elemen-elemen tersebut. Lebih lanjut, akses ke elemen apa pun dalam array dapat dilakukan dalam waktu konstan, yaitu $O(1)$. Ini terjadi karena alamat memori setiap elemen dapat dihitung secara langsung dari alamat dasar array dan indeksnya (misalnya, `alamat_dasar + indeks * ukuran_tipe_data`), tanpa perlu traversal berurutan. Karakteristik ini menjadikan array sangat efisien untuk operasi yang memerlukan pengambilan data cepat berdasarkan posisinya, seperti pencarian atau iterasi, dan menjadi fondasi bagi banyak struktur data lain yang mengandalkan alokasi memori yang berurutan.

## 1.1 | Karakteristik Utama Array

Array dalam C++ memiliki beberapa karakteristik esensial yang membedakannya dari struktur data lain:

- **Tipe Data Seragam:** Seluruh elemen yang tersimpan dalam sebuah array harus memiliki tipe data yang sama. Sebagai contoh, sebuah array `int` hanya dapat menyimpan bilangan bulat, dan array `double` hanya dapat menyimpan bilangan _floating-point_ presisi ganda.
<br/>

- **Memori Berurutan (Contiguous Memory):** Elemen-elemen array dialokasikan dan disimpan secara berurutan di lokasi memori yang berdekatan. Alamat memori terendah selalu berhubungan dengan elemen pertama (indeks 0), sedangkan alamat tertinggi berhubungan dengan elemen terakhir.
<br/>

- **Indeks Berbasis Nol:** Sistem pengindeksan array di C++ dimulai dari angka nol. Ini berarti elemen pertama array selalu berada pada indeks 0, elemen kedua pada indeks 1, dan seterusnya. Akibatnya, elemen terakhir dari array yang memiliki `n` elemen akan berada pada indeks `n-1`.
<br/>

- **Ukuran Tetap (untuk Array Gaya C):** Salah satu karakteristik paling mendasar dari array gaya C tradisional adalah ukurannya yang tetap. Setelah array dideklarasikan, jumlah elemen yang dapat disimpannya tidak dapat diubah sepanjang masa pakainya. Compiler harus mengetahui secara pasti berapa banyak ruang memori yang perlu dialokasikan pada waktu kompilasi.

Keterbatasan ukuran tetap ini merupakan fitur tingkat rendah yang diwarisi dari bahasa C, yang dirancang untuk memberikan kontrol memori yang sangat langsung. Karena compiler perlu mengetahui ukuran memori yang tepat untuk dialokasikan, baik di _stack_ maupun _heap_, array gaya C mengharuskan ukuran yang pasti saat kompilasi. Akibatnya, kurangnya fleksibilitas ini dapat menyebabkan beberapa tantangan. Jika kebutuhan ukuran data berubah saat program dieksekusi, array tidak dapat diubah ukurannya. Ini bisa mengakibatkan pemborosan memori jika array dialokasikan terlalu besar dari yang dibutuhkan, atau sebaliknya, menyebabkan _buffer overflow_ jika data yang disimpan melebihi kapasitas yang dialokasikan, yang dapat menimbulkan kerentanan keamanan dan _crash_ program.

Namun, di sisi lain, karakteristik ini juga memberikan keuntungan. Array gaya C menawarkan kontrol memori yang sangat langsung dan kinerja yang optimal karena tidak ada _overhead_ untuk manajemen ukuran dinamis. Array semacam ini berfungsi sebagai "blok bangunan" dasar yang efisien untuk struktur data yang lebih kompleks. Munculnya `std::vector` di C++ modern adalah respons langsung terhadap keterbatasan ukuran tetap ini. `std::vector` menawarkan fleksibilitas ukuran dinamis tanpa mengorbankan properti memori kontigu, meskipun dengan sedikit _overhead_ manajemen internal. Ini menunjukkan bagaimana C++ terus berkembang untuk menyeimbangkan kinerja tingkat rendah dengan kemudahan penggunaan dan keamanan yang lebih tinggi.

<br/>

---
# 2 | Deklarasi dan Inisialisasi Array

Penggunaan array dalam C++ dimulai dengan deklarasi dan inisialisasi, yang dapat dilakukan secara statis (ukuran tetap pada waktu kompilasi) atau dinamis (alokasi memori pada waktu eksekusi).

## 2.1 | Array Statis (Ukuran Tetap pada Waktu Kompilasi)

Array statis dideklarasikan dengan ukuran yang telah ditentukan pada waktu kompilasi. Sintaks dasar untuk deklarasi array satu dimensi adalah `tipe_data nama_array[ukuran];`. Ukuran array harus berupa literal integer atau ekspresi konstan yang nilainya sudah diketahui saat kompilasi.

```cpp
// Contoh: Deklarasi array 10 integer
int angka[10];

// Contoh: Ukuran menggunakan constexpr (C++11)
constexpr int UKURAN_MAKS = 5;
double nilai[UKURAN_MAKS];
```

Array dapat diinisialisasi saat deklarasi, baik secara penuh maupun parsial.

- **Inisialisasi Penuh:** Memberikan nilai awal untuk semua elemen menggunakan daftar inisialisasi yang diapit kurung kurawal `{}`. Jika ukuran array dihilangkan dalam deklarasi, compiler akan secara otomatis menentukan ukurannya berdasarkan jumlah elemen yang diberikan dalam daftar inisialisasi.
    
    ```cpp
    int angka[]= {1, 2, 3, 4, 5}; // Ukuran otomatis 5
    int nilai[] = {10, 20, 30, 40, 50}; // Ukuran eksplisit 5
    ```

<br/>

- **Inisialisasi Parsial:** Memberikan nilai hanya untuk sebagian elemen. Elemen yang tidak diinisialisasi secara eksplisit akan diatur ke nilai default (yaitu, 0 untuk tipe numerik, _null pointer_ untuk pointer, dll.).
    
    ```cpp
    int data[5] = {1, 2}; // Data terisi 2 [1,2,0,0,0]
    int nol_array[5] = {0}; // Semua elemen diinisialisasi ke 0 [0,0,0,0,0]
    ```
    

Array statis yang dideklarasikan di dalam fungsi (variabel lokal) dialokasikan di _stack_ memori. Karena _stack_ memiliki ruang yang terbatas, array yang terlalu besar dapat menyebabkan _stack overflow_, yaitu kondisi di mana program mencoba menggunakan lebih banyak ruang _stack_ daripada yang tersedia. Kebutuhan untuk mengetahui ukuran array pada waktu kompilasi adalah konsekuensi langsung dari alokasi _stack_ ini. Hal ini mendorong penggunaan alokasi dinamis atau `std::vector` untuk array dengan ukuran yang tidak diketahui pada waktu kompilasi atau yang berpotensi sangat besar, untuk menghindari batasan _stack_ dan memanfaatkan _heap_ yang lebih luas.

## 2.2 | Array Dinamis (Alokasi Memori pada Waktu Eksekusi)

Untuk skenario di mana ukuran array tidak diketahui pada waktu kompilasi (misalnya, ditentukan oleh input pengguna) atau ketika array terlalu besar untuk dialokasikan di _stack_, memori dapat dialokasikan secara dinamis di _heap_ menggunakan operator `new`.

```cpp
#include <iostream>

void contoh_dinamis(int ukuran) {
    int* arr_dinamis = new int[ukuran]; // Alokasi di heap

    for (int i = 0; i < ukuran; ++i) {
        arr_dinamis[i] = i * 10;
    }

    // ... gunakan array ...
    for (int i = 0; i < ukuran; ++i) {
        std::cout << arr_dinamis[i] << " ";
    }
    std::cout << "\n";

    delete[] arr_dinamis; // ✅ Gunakan delete[] untuk array
    arr_dinamis = nullptr; // Hindari dangling pointer
}

int main() {
    contoh_dinamis(10);
    return 0;
}
```

Penggunaan array dinamis sangat relevan ketika ukuran array harus ditentukan saat program berjalan, seperti saat membaca jumlah elemen dari pengguna. Selain itu, jika array yang dibutuhkan melebihi kapasitas _stack_, alokasi _heap_ menjadi solusi yang tepat.

Namun, manajemen memori manual dengan `new` dan `delete` memperkenalkan kompleksitas tambahan dan rentan terhadap kesalahan. Jika `delete` lupa dipanggil setelah array tidak lagi diperlukan, akan terjadi _memory leak_, di mana memori yang dialokasikan tidak pernah dibebaskan dan tetap tidak dapat digunakan oleh program lain. Sebaliknya, jika pointer digunakan setelah memori yang ditunjuknya dibebaskan (`delete`), akan terjadi _dangling pointer_, yang dapat menyebabkan perilaku tak terduga atau _crash_ program. Kesalahan-kesalahan ini seringkali sulit didiagnosis. Ini adalah alasan utama mengapa `std::vector` sangat direkomendasikan dalam pengembangan C++ modern. `std::vector` mengelola alokasi dan dealokasi memori secara otomatis (mengikuti prinsip RAII - Resource Acquisition Is Initialization), secara drastis mengurangi risiko kesalahan manajemen memori manual.

Berikut adalah perbandingan ringkas antara berbagai jenis array di C++:

### Tabel 1: Perbandingan Tipe Array di C++

|                                    |                                                       |                                                       |                                                   |
| ---------------------------------- | ----------------------------------------------------- | ----------------------------------------------------- | ------------------------------------------------- |
| **Fitur**                          | **Array Gaya C (C-style Array)**                      | **std::array (C++11+)**                               | **std::vector (C++98+)**                          |
| **Ukuran**                         | Tetap, ditentukan saat kompilasi                      | Tetap, ditentukan saat kompilasi                      | Dinamis, dapat diubah saat runtime                |
| **Alokasi Memori**                 | _Stack_ (lokal) atau _Heap_ (dengan `new`)            | _Stack_ (biasanya), tidak ada alokasi _heap_ internal | _Heap_ (otomatis dikelola)                        |
| **Manajemen Memori**               | Manual (dengan `new`/`delete` untuk _heap_)           | Otomatis (tidak perlu `delete`)                       | Otomatis (RAII)                                   |
| **Pemeriksaan Batas (`operator`)** | Tidak ada (Undefined Behavior jika di luar batas)     | Tidak ada (Undefined Behavior jika di luar batas)     | Tidak ada (Undefined Behavior jika di luar batas) |
| **Pemeriksaan Batas (`at()`)**     | Tidak tersedia                                        | Tersedia (melempar `std::out_of_range`)               | Tersedia (melempar `std::out_of_range`)           |
| **Informasi Ukuran**               | Tidak disimpan (hilang saat _decay_)                  | Disimpan (`.size()`)                                  | Disimpan (`.size()`)                              |
| **Fleksibilitas Ukuran**           | Tidak fleksibel                                       | Tidak fleksibel                                       | Fleksibel (dapat diubah)                          |
| **Overhead**                       | Minimal (hampir nol)                                  | Minimal (hampir nol)                                  | Sedikit _overhead_ manajemen memori               |
| **Pointer Decay**                  | Ya, meluruh menjadi pointer saat dilewatkan ke fungsi | Tidak, berperilaku seperti objek biasa                | Tidak, berperilaku seperti objek biasa            |
| **Integrasi STL**                  | Terbatas (membutuhkan iterator manual)                | Baik (mendukung iterator dan algoritma STL)           | Sangat baik (kontainer STL utama)                 |
| **Contoh Deklarasi**               | `int arr;` `int* dyn_arr = new int[size];`            | `std::array<int, 10> arr;`                            | `std::vector<int> vec;`                           |
<br/>

---
# 3 | Mengakses dan Memodifikasi Elemen Array

Elemen-elemen dalam array dapat diakses dan dimodifikasi menggunakan beberapa metode, yang paling umum adalah operator indeks dan aritmatika pointer.

## 3.1 | Menggunakan Operator Indeks 

Metode paling langsung untuk mengakses elemen array adalah dengan menggunakan operator indeks. Indeks elemen ditempatkan di dalam kurung siku setelah nama array. Penting untuk diingat bahwa indeks harus berupa bilangan bulat non-negatif dan harus kurang dari ukuran total array.

```cpp
int angka[] = {10, 20, 30, 40, 50};
int elemen_ketiga = angka[2]; // Mengakses elemen pada indeks 2 (nilai 30)
angka[2] = 35; // Memodifikasi elemen pada indeks 2 menjadi 35 
```

## 3.2 | Akses Elemen dengan Aritmatika Pointer

Dalam C++, nama array tanpa indeks dapat diperlakukan sebagai pointer konstan yang menunjuk ke alamat elemen pertamanya. Oleh karena itu, elemen array juga dapat diakses menggunakan aritmatika pointer. Misalnya, `*(arr + i)` akan mengakses elemen pada indeks `i`.

```cpp
int arr[] = {10, 20, 30};
int* ptr = arr; // ptr menunjuk ke arr
std::cout << *(ptr + 1); // Mengakses elemen kedua (arr = 20)
```

Metode ini memanfaatkan fakta bahwa elemen array disimpan secara kontigu di memori, sehingga elemen berikutnya dapat ditemukan dengan menambahkan ukuran tipe data ke alamat pointer saat ini.

## 3.3 | Pentingnya Pemeriksaan Batas (Bounds Checking)

Salah satu aspek krusial dari array gaya C adalah tidak adanya pemeriksaan batas (_bounds checking_) secara otomatis saat mengakses elemen menggunakan `operator`. Ini berarti bahwa jika program mencoba mengakses indeks di luar batas yang valid (misalnya, `array[ukuran]` atau `array[-1]`), compiler tidak akan memberikan kesalahan pada waktu kompilasi atau _runtime_ secara default. Tindakan ini akan menghasilkan _undefined behavior_ (UB).

_Undefined behavior_ adalah kondisi yang sangat berbahaya dalam pemrograman C++. Ketika UB terjadi, program dapat menunjukkan perilaku yang tidak dapat diprediksi: bisa saja _crash_, menghasilkan output yang salah, atau bahkan tampak berfungsi dengan benar di satu lingkungan kompilasi atau eksekusi tetapi gagal di lingkungan lain. Hal ini membuat _bug_ akibat akses di luar batas sangat sulit dideteksi dan di-debug, serta dapat menjadi sumber kerentanan keamanan yang serius dalam aplikasi.

Sebagai respons terhadap risiko ini, C++ modern memperkenalkan kontainer seperti `std::array` dan `std::vector` yang menyediakan fungsi `at()`. Fungsi `at()` ini secara eksplisit melakukan pemeriksaan batas. Jika indeks yang diberikan tidak valid, `at()` akan melempar `std::out_of_range` _exception_, memberikan mekanisme keamanan yang jauh lebih baik dan membantu dalam proses debugging. Ini adalah contoh bagaimana C++ berusaha menyeimbangkan kinerja tinggi, yang diwarisi dari C, dengan keamanan dan kemudahan debugging, mendorong pengembang untuk memilih alat yang tepat berdasarkan kebutuhan spesifik proyek mereka. Penggunaan `operator` masih tersedia untuk kinerja maksimal ketika pengembang yakin indeks selalu valid, sementara `at()` menjadi pilihan yang lebih aman untuk situasi di mana validitas indeks perlu diverifikasi pada _runtime_.

<br/>

---
# 4 | Array Multidimensi

Array multidimensi adalah perluasan dari konsep array satu dimensi, yang memungkinkan penyimpanan data dalam bentuk matriks (tabel) atau struktur yang lebih kompleks. Array ini pada dasarnya adalah "array dari array".

## 4.1 | Konsep dan Deklarasi Array Dua Dimensi

Array dua dimensi adalah bentuk array multidimensi yang paling sederhana dan paling sering digunakan. Array ini ideal untuk merepresentasikan data dalam format tabular, seperti baris dan kolom. Elemen dalam array dua dimensi diakses menggunakan dua indeks: satu untuk baris dan satu untuk kolom.

```cpp
#include <iostream>
using namespace std;

int main() {
    // Deklarasi dan inisialisasi array 2x3
    int data_matriks[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // Mengakses elemen baris ke-0, kolom ke-1 (indeks [0][1])
    cout << data_matriks[0][1] << "\n"; // Output: 2

    return 0;
}

```

## 4.2 | Contoh Implementasi Array Tiga Dimensi

Array tiga dimensi dapat dibayangkan sebagai kumpulan matriks 2D yang ditumpuk, membentuk sebuah "kubus" data. Elemen diakses dengan tiga indeks: `array[lapisan][baris][kolom]`.

```cpp
#include <iostream>
using namespace std;

int main() {
    // Deklarasi dan inisialisasi array 3 dimensi: 2 lapisan, 2 baris, 2 kolom
    int kubus[2][2][2] = {
        { {1, 2}, {3, 4} },   // Lapisan 0
        { {5, 6}, {7, 8} }    // Lapisan 1
    };

    // Akses elemen pada lapisan 1, baris 0, kolom 1 (yaitu 6)
    cout << kubus[1][0][1] << endl;

    return 0;
}
```

Kemampuan array multidimensi untuk menyimpan data dalam struktur seperti matriks atau kubus sangat berguna untuk memodelkan data yang secara alami memiliki lebih dari satu "dimensi". Contohnya termasuk representasi gambar (piksel dalam baris dan kolom), data geografis (koordinat), atau data ilmiah (sensor pada grid 3D). 

Meskipun array multidimensi gaya C mudah dideklarasikan, manajemen memori dan passing ke fungsi bisa menjadi lebih rumit dibandingkan array satu dimensi. Untuk skenario yang lebih kompleks atau dinamis, penggunaan `std::vector` dari `std::vector`, atau bahkan `std::vector<std::vector<std::vector<T>>>` seringkali lebih disukai karena fleksibilitas dan keamanan yang lebih baik, meskipun dengan sedikit _overhead_ manajemen. Hal ini menunjukkan bahwa pemilihan struktur data harus mempertimbangkan tidak hanya kemudahan deklarasi, tetapi juga kebutuhan manajemen data dan fleksibilitas di masa depan.

<br/>

---
# 5 | Melewatkan Array ke Fungsi

Melewatkan array ke fungsi dalam C++ memiliki karakteristik khusus, terutama terkait dengan bagaimana array gaya C diperlakukan oleh compiler.

## 5.1 | Fenomena "Pointer Decay" dan Implikasinya

Ketika array gaya C dilewatkan sebagai argumen ke sebuah fungsi, ia secara otomatis mengalami fenomena yang dikenal sebagai "pointer decay" atau "peluruhan pointer". Ini berarti bahwa array tersebut tidak lagi diperlakukan sebagai array dengan ukuran spesifik, melainkan secara implisit diubah menjadi pointer ke elemen pertamanya. Sebagai contoh, sebuah array `int arr[];` yang dilewatkan ke fungsi akan diterima sebagai `int* arr;`.

```cpp
void cetak(int arr[]) {
    std::cout << arr[0] << std::endl;
}
```

Fungsi di atas tidak menerima array, tetapi sebenarnya menerima sebuah pointer ke int. Jadi deklarasi ini:

```cpp
void cetak(int arr[]);
```

Sama saja dengan ini:

```cpp
void cetak(int* arr);
```

Konsekuensi langsung dari _pointer decay_ ini adalah fungsi yang menerima array akan kehilangan informasi mengenai ukuran asli array tersebut. Di dalam fungsi, operator `sizeof` yang diterapkan pada parameter array akan mengembalikan ukuran pointer itu sendiri (biasanya 4 atau 8 byte, tergantung arsitektur sistem), bukan ukuran total array asli. Ini berarti fungsi tidak dapat secara mandiri menentukan berapa banyak elemen yang ada dalam array yang diterimanya.

Kita tidak bisa menulis syntax ini di fungsi untuk mengetahui ukurang array:

```cpp
int ukuran = sizeof(arr) / sizeof(arr[0]);
```

Kehilangan informasi ukuran ini menimbulkan kebutuhan akan metadata eksplisit. Tanpa mengetahui ukurannya, fungsi tidak dapat melakukan pemeriksaan batas yang aman atau iterasi yang benar melalui seluruh elemen array. Ini secara signifikan meningkatkan risiko akses di luar batas (_out-of-bounds access_) di dalam fungsi, yang dapat menyebabkan _undefined behavior_ dan _crash_ program. Ini adalah alasan utama mengapa `std::vector` dan `std::array` sangat direkomendasikan dalam C++ modern. Kedua kontainer ini adalah objek yang membawa informasi ukurannya sendiri (`.size()`), memungkinkan fungsi untuk beroperasi dengan aman tanpa memerlukan parameter ukuran tambahan, dan secara efektif mengurangi risiko _bug_ yang terkait dengan _pointer decay_.

## 5.2 | Praktik Terbaik untuk Melewatkan Array (dengan Ukuran)

Mengingat fenomena _pointer decay_, praktik terbaik saat melewatkan array gaya C ke fungsi adalah dengan selalu menyertakan ukuran array sebagai parameter terpisah.

```cpp
#include <iostream>
using namespace std;

// Parameter 'arr' harus berupa pointer (int* arr)
void cetakArray(int arr[], int ukuran) {
    for (int i = 0; i < ukuran; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Array harus diinisialisasi dengan tanda kurung siku []
    int data[] = {10, 20, 30, 40, 50};

    // Hitung ukuran array: total byte dibagi ukuran satu elemen
    int n = sizeof(data) / sizeof(data[0]);

    cetakArray(data, n);
    return 0;
}

```

Untuk kontainer C++ modern seperti `std::array` dan `std::vector`, praktik terbaik adalah melewatkannya berdasarkan referensi konstan (`const &`). Pendekatan ini memiliki dua keuntungan utama: pertama, ia menghindari penyalinan seluruh kontainer, yang bisa mahal untuk array besar, sehingga meningkatkan efisiensi. Kedua, penggunaan `const` memastikan bahwa fungsi tidak dapat memodifikasi data asli array, menjaga integritas data jika modifikasi tidak diinginkan.

```cpp
#include <array>
#include <vector>
#include <iostream>

//...

void cetakStdArray(const std::array<int, 5>& arr) { // Ukuran diketahui oleh std::array itu sendiri
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void cetakVector(const std::vector<int>& vec) { // Ukuran diketahui melalui vec.size()
    for (int x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::array<int, 5> my_arr = {1, 2, 3, 4, 5};
    std::vector<int> my_vec = {6, 7, 8, 9, 10};

    cetakStdArray(my_arr);
    cetakVector(my_vec);

    return 0;
}
```

<br/>

---
# 6 | Kegunaan dan Keuntungan Array

Array merupakan struktur data yang sangat fundamental dan memiliki berbagai kegunaan serta keuntungan dalam pemrograman C++.

## 6.1 | Efisiensi Memori dan Akses Acak Cepat

Salah satu keuntungan terbesar dari array adalah efisiensi memori dan kecepatan aksesnya. Karena elemen-elemen array disimpan secara kontigu di memori, mereka memanfaatkan _cache locality_ dengan sangat baik. Ini berarti bahwa ketika satu elemen diakses, blok memori di sekitarnya yang berisi elemen-elemen array lainnya juga cenderung dimuat ke dalam _cache_ CPU, menghasilkan akses elemen yang sangat cepat ($O(1)$) untuk operasi berikutnya. Selain itu, penggunaan memori array sangat efisien karena tidak ada _overhead_ tambahan untuk pointer per elemen, seperti yang ditemukan pada struktur data lain seperti _linked list_.

Efisiensi akses acak $O(1)$ dan penggunaan memori yang efisien karena penyimpanan kontigu menjadikan array pilihan yang sangat baik untuk aplikasi yang membutuhkan kinerja tinggi dan manipulasi data dalam jumlah besar. Contohnya termasuk pemrosesan gambar, komputasi ilmiah, simulasi fisika, atau sistem _real-time_ di mana kecepatan adalah prioritas utama. Meskipun kontainer STL seperti `std::vector` menambahkan lapisan abstraksi dan manajemen memori otomatis, mereka mempertahankan properti memori kontigu ini, memastikan bahwa keuntungan kinerja fundamental dari array tetap ada. Ini menunjukkan bahwa array, baik dalam bentuk tradisional maupun modern, adalah dasar untuk mencapai kinerja komputasi yang optimal.

## 6.2 | Kemudahan Traversal dan Integrasi dengan Algoritma

Array sangat mudah untuk di-traverse, atau dikunjungi setiap elemennya, menggunakan _loop_ sederhana seperti `for` yang merupakan loop tradisional, atau _range-based for loop_ yang diperkenalkan di C++11. Kesederhanaan ini membuat operasi seperti pencetakan, penjumlahan, atau pencarian elemen menjadi sangat intuitif untuk diimplementasikan.

Selain itu, banyak algoritma dasar dalam ilmu komputer, seperti algoritma pencarian (linear search, binary search) dan algoritma pengurutan (bubble sort, selection sort, insertion sort), secara alami dirancang untuk beroperasi pada array. Struktur kontigu array sangat cocok dengan cara kerja algoritma-algoritma ini, memungkinkan implementasi yang efisien dan langsung.

## 6.3 | Keterbatasan Array Gaya C

Meskipun memiliki keuntungan, array gaya C tradisional memiliki beberapa keterbatasan signifikan:

- **Ukuran Tetap:** Ukuran array gaya C tidak dapat diubah setelah deklarasi. Keterbatasan ini dapat menyebabkan pemborosan memori jika array dialokasikan terlalu besar dari yang dibutuhkan, atau sebaliknya, membatasi kapasitas jika data yang disimpan melebihi ukuran yang telah ditentukan.
<br/>

- **Tidak Ada Pemeriksaan Batas Bawaan:** Seperti yang telah dibahas, akses elemen di luar batas yang valid menggunakan `operator` tidak akan menghasilkan kesalahan pada waktu kompilasi atau _runtime_ secara otomatis, melainkan menyebabkan _undefined behavior_. Hal ini membuat _bug_ sulit dideteksi dan berpotensi menimbulkan kerentanan keamanan.
<br/>

- **Kurangnya Fitur:** Array gaya C tidak memiliki fungsi anggota (seperti `size()`, `empty()`) atau fitur kontainer lain yang ditemukan pada `std::array` atau `std::vector`. Ini berarti pengembang harus mengelola informasi ukuran secara manual dan menggunakan fungsi global atau menulis _loop_ sendiri untuk operasi dasar.

Keterbatasan-keterbatasan ini diwarisi dari bahasa C, yang dirancang untuk kontrol tingkat rendah dan efisiensi absolut. Meskipun efisien, hal ini terbukti menjadi sumber banyak _bug_ dan kesulitan dalam pengembangan perangkat lunak yang lebih besar dan aman. Keterbatasan ini secara langsung memotivasi pengembangan `std::array` dan `std::vector` di C++ Standard Library. Kontainer-kontainer modern ini menawarkan keamanan dan fleksibilitas tanpa mengorbankan kinerja dasar array. Ini mencerminkan filosofi C++ untuk menyediakan abstraksi yang _tidak ada biaya_ (_zero-overhead abstractions_), di mana pengembang tidak perlu membayar _overhead_ kinerja untuk fitur yang tidak mereka gunakan, tetapi memiliki opsi untuk fitur keamanan dan kemudahan penggunaan ketika dibutuhkan.

<br/>

---
# 7 | Aplikasi Array dalam Pemrograman C++

Array, sebagai struktur data fundamental, memiliki aplikasi yang sangat luas dalam berbagai bidang pemrograman dan komputasi, baik sebagai fondasi untuk struktur data yang lebih kompleks maupun dalam skenario dunia nyata.

## 7.1 | Sebagai Fondasi Struktur Data Lain

Array berfungsi sebagai blok bangunan dasar untuk mengimplementasikan berbagai struktur data yang lebih kompleks:

- **Stack dan Queue:** Array dapat digunakan secara efisien untuk mengimplementasikan operasi _push_ (menambahkan elemen) dan _pop_ (menghapus elemen) pada _stack_, serta operasi _enqueue_ (menambahkan) dan _dequeue_ (menghapus) pada _queue_. Implementasi menggunakan array cenderung lebih sederhana dibandingkan dengan _linked list_.
<br/>


- **Hash Table:** Array seringkali menjadi penyimpanan dasar untuk _hash table_, di mana indeks array dihitung dari kunci menggunakan fungsi _hash_. Ini memungkinkan pencarian dan penyisipan data yang sangat cepat.
<br/>

- **Heap:** Struktur data _heap_, terutama _binary heap_, umumnya diimplementasikan menggunakan array karena sifatnya yang dapat direpresentasikan secara efisien dalam memori kontigu.
<br/>

- **String:** Dalam C dan C++, _string_ secara fundamental adalah array karakter. Setiap karakter dalam _string_ disimpan sebagai elemen dalam array.

## 7.2 | Contoh Aplikasi Dunia Nyata

Keberadaan array sangat meresap dalam berbagai aplikasi dunia nyata:

- **Pengolahan Data:** Array digunakan untuk menyimpan dan mengelola data tabular, seperti data penjualan, nilai siswa, data sensor dari perangkat IoT, atau data statistik dalam aplikasi analisis.
<br/>

- **Grafika Komputer dan Pemrosesan Gambar:** Gambar digital sering direpresentasikan sebagai array piksel (matriks 2D) atau array tiga dimensi untuk gambar berwarna (misalnya, RGB). Array memungkinkan manipulasi piksel yang efisien untuk efek grafis atau pemrosesan gambar.
<br/>

- **Sistem Basis Data:** Meskipun sistem basis data modern menggunakan struktur yang lebih kompleks, konsep dasar penyimpanan catatan atau kolom data seringkali mengandalkan array atau struktur serupa yang memanfaatkan memori kontigu.
<br/>

- **Penjadwalan CPU:** Dalam sistem operasi, array dapat digunakan untuk mengelola antrean proses yang menunggu eksekusi. Misalnya, dalam penjadwalan CPU Linux, proses yang dapat dieksekusi ditempatkan dalam _active array_ yang diindeks berdasarkan prioritas. Ketika _time slice_ suatu pekerjaan berakhir, ia dipindahkan ke _expired array_.
<br/>

- **Aplikasi Umum:** Array juga ditemukan dalam aplikasi sehari-hari seperti daftar kontak di ponsel, sistem pemesanan tiket online, inventaris barang di toko, atau representasi papan permainan seperti catur atau tic-tac-toe.
<br/>

Penggunaan array yang meluas ini menunjukkan bahwa meskipun array adalah konsep dasar, prinsip-prinsipnya (memori kontigu, akses indeks) sangat fundamental dan efisien sehingga menjadi pilihan alami untuk berbagai masalah komputasi, dari tingkat rendah hingga aplikasi tingkat tinggi. Pemahaman yang kuat tentang array bukan hanya tentang sintaks C++, tetapi tentang bagaimana data diatur dan diakses secara efisien di memori, yang merupakan keterampilan inti dalam ilmu komputer. Hal ini menegaskan ubiquitas array dalam komputasi modern.

<br/>

---
# 8 | Fungsi dan Algoritma Terkait Array

Array merupakan struktur data yang sangat cocok untuk dioperasikan dengan berbagai fungsi dan algoritma, baik yang diimplementasikan secara manual maupun yang disediakan oleh Standard Library C++.

## 8.1 | Operasi Dasar

Beberapa operasi dasar yang sering dilakukan pada array meliputi:

- **Menghitung Ukuran Array (Gaya C):** Untuk array gaya C, ukuran total dalam byte dapat diperoleh dengan `sizeof(array)`. Untuk mendapatkan jumlah elemen, ukuran total array dibagi dengan ukuran satu elemen: `sizeof(arr) / sizeof(arr[0]);`.

    
    ```cpp
    int arr = {1, 2, 3, 4, 5};
    int ukuran = sizeof(arr) / sizeof(arr[0]); // Hasil: 5
    ```

	<br/>

- **Traversal Array:** Iterasi melalui setiap elemen array adalah operasi yang sangat umum. Ini dapat dilakukan dengan `for` loop tradisional atau, di C++11 dan yang lebih baru, dengan _range-based for loop_ yang lebih ringkas.

	```cpp
	#include <iostream>
	
	int main() {
		int arr[] = {10, 20, 30}; // ✅ array dengan 3 elemen
	
		// Menggunakan for loop tradisional
		for (int i = 0; i < 3; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	
		// Menggunakan range-based for loop (C++11+)
		for (int x : arr) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
	
		return 0;
	}
	````

## 8.2 | Algoritma Pencarian

Algoritma pencarian digunakan untuk menemukan posisi atau keberadaan elemen tertentu dalam array.

- **Linear Search (Pencarian Berurutan):** Ini adalah algoritma pencarian paling sederhana, yang bekerja dengan memeriksa setiap elemen array satu per satu dari awal hingga elemen yang dicari ditemukan atau seluruh array telah diperiksa. Linear search cocok untuk data kecil atau data yang tidak terurut. Kompleksitas waktu rata-ratanya adalah $O(N)$, yang berarti waktu yang dibutuhkan sebanding dengan jumlah elemen dalam array.

    
	```cpp
	#include <algorithm>
	#include <vector>
	#include <iostream>
	#include <iterator>
	
	// Contoh implementasi manual linear search
	int linearSearch(int arr[], int size, int target) {
	    for (int i = 0; i < size; ++i) {
	        if (arr[i] == target) return i;
	    }
	    return -1; // Tidak ditemukan
	}
	
	
	int main() {
		std::vector<int> data = {1, 2, 3, 4, 5};
		
		auto it = std::find(data.begin(), data.end(), 3);
		
		if (it != data.end()) {
		std::cout << "Ditemukan di indeks " << std::distance(data.begin(), it) << std::endl;
		} else {
		std::cout << "Tidak ditemukan" << std::endl;
		}
		
		return 0;
	}
	```
    
	<br/>
	
- **Binary Search (Pencarian Biner):** Algoritma ini jauh lebih efisien dibandingkan linear search, tetapi memiliki prasyarat penting: hanya dapat digunakan pada array yang sudah terurut. Binary search bekerja dengan berulang kali membagi ruang pencarian menjadi dua bagian. Ini membandingkan elemen tengah dengan target; jika tidak cocok, ia akan mengeliminasi setengah dari ruang pencarian dan melanjutkan di setengah yang tersisa. Kompleksitas waktu binary search adalah $O(log \; N)$, yang membuatnya sangat cepat untuk dataset besar.
    
	```cpp
	#include <iostream>
	#include <vector>
	#include <algorithm> // untuk std::binary_search
	
	// Implementasi manual binary search (iteratif)
	int binarySearch(int arr[], int low, int high, int x) {
	    while (low <= high) {
	        int mid = low + (high - low) / 2; // Hindari overflow
	        if (arr[mid] == x) return mid;
	        if (arr[mid] < x) low = mid + 1;
	        else high = mid - 1;
	    }
	    return -1; // Tidak ditemukan
	}
	
	int main() {
	    // Contoh array C-style
	    int arr[] = {1, 2, 3, 4, 5};
	    int size = sizeof(arr) / sizeof(arr[0]);
	    int target = 4;
	
	    // Uji fungsi binary search manual
	    int index = binarySearch(arr, 0, size - 1, target);
	    if (index != -1) {
	        std::cout << "Ditemukan pada indeks " << index << " (manual)" << std::endl;
	    } else {
	        std::cout << "Tidak ditemukan (manual)" << std::endl;
	    }
	
	    // Contoh dengan std::vector dan std::binary_search
	    std::vector<int> data_sorted = {1, 2, 3, 4, 5};
	    if (std::binary_search(data_sorted.begin(), data_sorted.end(), target)) {
	        std::cout << "Ditemukan (std::binary_search)" << std::endl;
	    } else {
	        std::cout << "Tidak ditemukan (std::binary_search)" << std::endl;
	    }
	
	    return 0;
	}
	```

<br/>

Pemilihan algoritma pencarian sangat bergantung pada karakteristik data yang sedang diproses. Jika data sering berubah atau tidak terurut, linear search mungkin menjadi satu-satunya pilihan langsung yang praktis. Namun, jika data terurut atau dapat diurutkan sekali (yang mungkin memerlukan biaya komputasi awal), binary search menawarkan keuntungan kinerja yang signifikan, terutama untuk dataset yang sangat besar. Hal ini menekankan pentingnya memahami sifat data saat memilih algoritma dan struktur data, karena menginvestasikan waktu untuk mengurutkan data bisa menjadi sangat berharga jika diikuti oleh banyak operasi pencarian.

## 8.3 | Algoritma Pengurutan

Algoritma pengurutan digunakan untuk menyusun elemen array dalam urutan tertentu (misalnya, menaik atau menurun).

- **Bubble Sort:** Ini adalah algoritma pengurutan paling sederhana. Bubble sort bekerja dengan berulang kali membandingkan elemen yang berdekatan dan menukarnya jika urutannya salah. Proses ini diulang hingga tidak ada lagi pertukaran yang terjadi, menandakan array sudah terurut. Algoritma ini tidak cocok untuk dataset besar karena kompleksitas waktu rata-rata dan terburuknya adalah $O(N^2)$, menjadikannya sangat lambat seiring bertambahnya ukuran data.
    
	```cpp
	#include <iostream>
	#include <algorithm> // untuk std::swap
	
	// Implementasi manual bubble sort
	void bubbleSort(int arr[], int n) {
	    for (int i = 0; i < n - 1; ++i) {
	        bool swapped = false; // Optimasi: berhenti jika tidak ada pertukaran
	        for (int j = 0; j < n - i - 1; ++j) {
	            if (arr[j] > arr[j + 1]) {
	                std::swap(arr[j], arr[j + 1]);
	                swapped = true;
	            }
	        }
	        if (!swapped) break; // Jika tidak ada pertukaran, array sudah terurut
	    }
	}
	
	int main() {
	    int data[] = {64, 34, 25, 12, 22, 11, 90};
	    int n = sizeof(data) / sizeof(data[0]);
	
	    bubbleSort(data, n);
	
	    std::cout << "Array setelah diurutkan: ";
	    for (int i = 0; i < n; ++i)
	        std::cout << data[i] << " ";
	    std::cout << std::endl;
	
	    return 0;
	}
	```
    
    <br/>
    
- **Selection Sort:** Selection sort adalah algoritma pengurutan yang bekerja dengan berulang kali menemukan elemen minimum (atau maksimum) dari bagian array yang belum terurut dan menukarnya ke posisi yang benar di bagian array yang sudah terurut. Proses ini berlanjut hingga seluruh array terurut. Kompleksitas waktunya juga $O(N^2)$. Keuntungan utamanya adalah jumlah pertukaran (_swaps_) yang minimal, menjadikannya pilihan yang baik jika biaya penulisan memori sangat tinggi.

	```cpp
	#include <iostream>
	#include <algorithm> // untuk std::swap
	
	// Contoh implementasi manual selection sort
	void selectionSort(int arr[], int n) {
	    for (int i = 0; i < n - 1; ++i) {
	        int min_idx = i;
	        for (int j = i + 1; j < n; ++j) {
	            if (arr[j] < arr[min_idx]) {
	                min_idx = j;
	            }
	        }
	        if (min_idx != i) {
	            std::swap(arr[i], arr[min_idx]);
	        }
	    }
	}
	
	int main() {
	    int data[] = {29, 10, 14, 37, 13};
	    int n = sizeof(data) / sizeof(data[0]);
	
	    selectionSort(data, n);
	
	    std::cout << "Array setelah diurutkan: ";
	    for (int i = 0; i < n; ++i) {
	        std::cout << data[i] << " ";
	    }
	    std::cout << std::endl;
	
	    return 0;
	}
	```
	
	<br/>
 
- **Insertion Sort:** Insertion sort membagi array menjadi dua bagian: bagian yang terurut dan bagian yang belum terurut. Dalam setiap iterasi, elemen pertama dari bagian yang belum terurut diambil dan dimasukkan ke posisi yang benar di bagian yang terurut. Kompleksitas waktu terburuk dan rata-ratanya adalah $O(N^2)$, tetapi dalam kasus terbaik (jika array sudah terurut), kompleksitasnya adalah $O(N)$. Algoritma ini cukup efisien untuk dataset kecil atau array yang hampir terurut.

	```cpp
	#include <iostream>
	
	// Contoh implementasi manual insertion sort
	void insertionSort(int arr[], int n) {
	    for (int i = 1; i < n; ++i) {
	        int key = arr[i];
	        int j = i - 1;
	
	        // Geser elemen-elemen yang lebih besar dari key ke kanan
	        while (j >= 0 && arr[j] > key) {
	            arr[j + 1] = arr[j];
	            --j;
	        }
	
	        arr[j + 1] = key; // Tempatkan key di posisi yang benar
	    }
	}
	
	int main() {
	    int data[] = {9, 5, 1, 4, 3};
	    int n = sizeof(data) / sizeof(data[0]);
	
	    insertionSort(data, n);
	
	    std::cout << "Array setelah diurutkan: ";
	    for (int i = 0; i < n; ++i) {
	        std::cout << data[i] << " ";
	    }
	    std::cout << std::endl;
	
	    return 0;
	}
	```

	<br/>

- **`std::sort` (dari `<algorithm>`):** Fungsi pengurutan standar C++ ini adalah pilihan yang sangat efisien dan direkomendasikan untuk sebagian besar kebutuhan pengurutan. `std::sort` biasanya merupakan implementasi dari Introsort, yang merupakan kombinasi dari Quicksort, Heapsort, dan Insertion Sort, sehingga memberikan kinerja yang sangat baik. Kompleksitas waktu rata-ratanya adalah $O(N \;log\; N)$, jauh lebih efisien daripada algoritma $O(N^2)$ untuk dataset besar.

	```cpp
	#include <algorithm> // untuk std::sort
	#include <vector>
	#include <iostream>
	
	int main() {
	    // Mengurutkan std::vector
	    std::vector<int> data = {5, 2, 8, 1, 9};
	    std::sort(data.begin(), data.end());
	    for (int x : data) {
	        std::cout << x << " ";
	    }
	    std::cout << std::endl;
	
	    // Mengurutkan array gaya C
	    int arr_c[] = {5, 4, 1, 2, 3}; // PERBAIKAN: Tambahkan []
	    int n_c = sizeof(arr_c) / sizeof(arr_c[0]); // PERBAIKAN: ukur berdasarkan elemen
	    std::sort(arr_c, arr_c + n_c);
	    for (int i = 0; i < n_c; ++i) {
	        std::cout << arr_c[i] << " ";
	    }
	    std::cout << std::endl;
	
	    return 0;
	}
	```

	<br/>

Pemilihan algoritma pengurutan sangat memengaruhi kinerja program, terutama untuk dataset besar. Algoritma dengan kompleksitas waktu $O(N^2)$ seperti Bubble Sort menjadi tidak praktis untuk jumlah elemen yang besar. Oleh karena itu, `std::sort` adalah pilihan yang sangat dioptimalkan dan direkomendasikan untuk sebagian besar kasus karena kinerjanya yang unggul dan implementasi yang teruji. Memahami algoritma dasar seperti Bubble Sort, Selection Sort, dan Insertion Sort penting untuk tujuan pendidikan dan pemahaman konsep, tetapi dalam praktik, `std::sort` hampir selalu merupakan pilihan yang lebih baik. Hal ini juga menyoroti nilai dari Standard Library dalam menyediakan solusi yang efisien dan andal yang sudah teruji.

<br/>

---
# 9 | Kontainer Array Modern di C++ Standard Library

C++ modern, terutama dengan diperkenalkannya Standard Template Library (STL), menyediakan kontainer array yang lebih aman dan fleksibel dibandingkan array gaya C tradisional. Dua kontainer utama yang relevan adalah `std::array` dan `std::vector`.

## 9.1 | `std::array`: Array Ukuran Tetap dengan Fitur Kontainer

Diperkenalkan di C++11, `std::array` adalah _wrapper_ di sekitar array gaya C ukuran tetap.  Kontainer ini menyediakan manfaat kontainer STL, seperti kemampuan untuk mengetahui ukurannya sendiri (`.size()`), mendukung iterasi menggunakan iterator, dan memiliki fungsi anggota, tanpa _overhead_ alokasi dinamis yang terkait dengan _heap_. Ukuran `std::array` harus berupa konstanta waktu kompilasi, sama seperti array gaya C.

```cpp
#include <array>
#include <iostream>

int main() {
    std::array<int, 5> my_std_array = {1, 2, 3, 4, 5}; // Array berukuran tetap dengan 5 elemen
    std::cout << "Ukuran std::array: " << my_std_array.size() << std::endl; // .size() mengembalikan ukuran tetap
    std::cout << "Elemen pertama: " << my_std_array.front() << std::endl;   // .front() mengakses elemen pertama
    return 0;
}

```

`std::array` berfungsi sebagai jembatan antara efisiensi array gaya C dan keamanan C++ modern. Array gaya C dikenal efisien tetapi rentan terhadap kesalahan (tidak ada pemeriksaan batas, tidak ada informasi ukuran). Sementara itu, `std::vector` aman dan fleksibel tetapi memiliki sedikit _overhead_ dinamis karena alokasi _heap_. `std::array` mengisi celah ini dengan menawarkan efisiensi array gaya C (alokasi _stack_, tidak ada _overhead heap_) dengan keamanan dan kemudahan penggunaan kontainer STL (pemeriksaan batas dengan `at()`, iterator, `size()`, dll.). Ini adalah contoh sempurna dari filosofi C++: "Anda tidak membayar untuk apa yang tidak Anda gunakan." Jika ukuran array diketahui pada waktu kompilasi dan tidak akan berubah, `std::array` adalah pilihan yang lebih baik daripada array gaya C atau `std::vector` karena memberikan keamanan dan fitur tanpa biaya kinerja yang tidak perlu.

## 9.2 | `std::vector`: Array Dinamis yang Fleksibel

`std::vector` adalah _dynamic array_ yang dapat tumbuh dan menyusut ukurannya sesuai kebutuhan. Ini adalah kontainer paling serbaguna di STL dan sering menjadi pilihan _default_ untuk koleksi data dinamis di C++ karena fleksibilitas dan manajemen memori otomatisnya.

```cpp
#include <iostream>
#include <vector> // <== WAJIB untuk std::vector

int main() {
    std::vector<int> my_vector; // Membuat vector kosong
    my_vector.push_back(10);    // Menambahkan elemen ke akhir vector
    my_vector.push_back(20);
    
    my_vector.resize(5);        // Ubah ukuran vector jadi 5 elemen.
                                // Elemen tambahan otomatis bernilai 0.

    std::cout << "Ukuran vector: " << my_vector.size() << std::endl;

    for (int x : my_vector) {   // Cetak semua elemen dengan range-based for loop
        std::cout << x << " ";
    }

    std::cout << std::endl;
    return 0;
}
```

`std::vector` adalah standar emas untuk koleksi data dinamis. Keterbatasan array gaya C (ukuran tetap, manajemen memori manual) membuat mereka tidak cocok untuk banyak skenario dunia nyata di mana ukuran data tidak diketahui sebelumnya atau berubah selama eksekusi program. `std::vector` mengatasi semua keterbatasan ini dengan menyediakan antarmuka yang aman, fleksibel, dan efisien, menjadikannya kontainer yang paling sering digunakan di C++. Penggunaan `std::vector` secara luas mencerminkan pergeseran paradigma dalam C++ modern: dari manajemen memori manual dan struktur data tingkat rendah (array gaya C) ke abstraksi yang lebih tinggi dan aman yang disediakan oleh STL, yang pada akhirnya menghasilkan kode yang lebih andal dan mudah dikelola.

## 9.3 | Fungsi Anggota Penting `std::array` dan `std::vector`

`std::array` dan `std::vector` menyediakan serangkaian fungsi anggota yang kaya dan konsisten, yang meningkatkan kemudahan penggunaan dan keamanan.

- **Akses Elemen:**
    - `at()`: Mengakses elemen pada posisi tertentu dengan pemeriksaan batas. Jika indeks tidak valid, `std::out_of_range` _exception_ akan dilempar.
    - `operator[]` : Mengakses elemen pada posisi tertentu tanpa pemeriksaan batas. Ini lebih cepat tetapi berisiko _undefined behavior_ jika indeks di luar batas.
    - `front()`: Mengakses elemen pertama.
    - `back()`: Mengakses elemen terakhir.
    - `data()`: Mengembalikan pointer langsung ke penyimpanan memori kontigu yang mendasari. Berguna untuk interoperabilitas dengan API gaya C.

<br/>

- **Kapasitas:**
    - `size()`: Mengembalikan jumlah elemen saat ini dalam kontainer.
    - `empty()`: Memeriksa apakah kontainer kosong (yaitu, `size()` adalah 0).
    - `max_size()`: Mengembalikan jumlah maksimum elemen yang dapat ditampung oleh kontainer.

<br/>

- **Operasi:**
    - `fill()`: Mengisi semua elemen dalam `std::array` dengan nilai tertentu.
    - `swap()`: Menukar isi dua kontainer dengan tipe dan ukuran yang sama secara efisien.

<br/>

- **Iterator:**
    - `begin()`, `end()`, `cbegin()`, `cend()`, `rbegin()`, `rend()`, `crbegin()`, `crend()`: Mengembalikan iterator untuk traversal maju, mundur, dan konstan.

Antarmuka standar yang disediakan oleh `std::array` dan `std::vector` ini menciptakan konsistensi yang dapat diprediksi untuk bekerja dengan koleksi data, terlepas dari apakah itu array ukuran tetap atau dinamis. Konsistensi ini memungkinkan pengembang untuk menulis kode generik menggunakan algoritma STL yang dapat bekerja pada berbagai jenis kontainer, meningkatkan reusabilitas kode dan mengurangi kompleksitas. Ini adalah salah satu kekuatan utama dari Standard Template Library.

### Tabel 2: Fungsi Anggota Penting `std::array`

|                    |                                                                                                                                      |
| ------------------ | ------------------------------------------------------------------------------------------------------------------------------------ |
| **Fungsi Anggota** | **Deskripsi**                                                                                                                        |
| `at()`             | Mengakses elemen pada indeks tertentu dengan pemeriksaan batas. Melempar `std::out_of_range` jika indeks tidak valid.                |
| `operator[]`       | Mengakses elemen pada indeks tertentu tanpa pemeriksaan batas. Lebih cepat, tetapi berisiko _undefined behavior_ jika di luar batas. |
| `front()`          | Mengakses elemen pertama dari array.                                                                                                 |
| `back()`           | Mengakses elemen terakhir dari array.                                                                                                |
| `data()`           | Memberikan akses langsung ke penyimpanan memori kontigu yang mendasari sebagai pointer.                                              |
| `size()`           | Mengembalikan jumlah elemen saat ini dalam array.                                                                                    |
| `empty()`          | Memeriksa apakah array kosong (hanya benar jika N=0).                                                                                |
| `fill()`           | Mengisi seluruh array dengan nilai yang ditentukan.                                                                                  |
| `swap()`           | Menukar isi dua objek `std::array` dengan tipe dan ukuran yang sama.                                                                 |
| `begin()`          | Mengembalikan iterator ke awal array.                                                                                                |
| `end()`            | Mengembalikan iterator ke elemen "satu setelah akhir" array.                                                                         |

## 9.4 | Algoritma Standard Library `std::sort`, `std::find`, `std::accumulate`, dll.

Standard Template Library (STL) menyediakan berbagai algoritma yang kuat dan efisien yang didefinisikan dalam header `<algorithm>` dan `<numeric>`. Algoritma-algoritma ini dirancang untuk beroperasi pada rentang elemen yang ditentukan oleh iterator, sehingga sangat cocok untuk digunakan dengan array gaya C, `std::array`, dan `std::vector`.

Beberapa contoh algoritma penting meliputi:

- `std::sort()`: Mengurutkan elemen dalam rentang yang diberikan.
- `std::find()`: Mencari elemen pertama yang cocok dengan nilai tertentu dalam rentang.
- `std::binary_search()`: Memeriksa keberadaan elemen dalam rentang yang sudah terurut.
- `std::accumulate()`: Menghitung jumlah kumulatif atau hasil operasi biner lainnya pada elemen-elemen dalam rentang (ditemukan di `<numeric>`).
- `std::fill()`: Mengisi rentang elemen dengan nilai tertentu.
- `std::copy()`: Menyalin elemen dari satu rentang ke rentang lain.
- `std::for_each()`: Menerapkan fungsi atau objek fungsi ke setiap elemen dalam rentang.

Kekuatan abstraksi dan reusabilitas adalah inti dari algoritma STL. Algoritma-algoritma ini bekerja dengan iterator, bukan secara langsung dengan tipe kontainer spesifik. Ini berarti algoritma yang sama seperti `std::sort`, `std::find`, dll dapat digunakan pada array gaya C, `std::array`, `std::vector`, `std::list`, dan kontainer lainnya, selama mereka menyediakan antarmuka iterator yang sesuai. Desain ini mempromosikan reusabilitas kode yang masif, mengurangi kebutuhan untuk menulis ulang algoritma dasar, dan memastikan bahwa algoritma yang digunakan sudah teruji dan dioptimalkan. Ini adalah salah satu alasan mengapa C++ sangat kuat untuk pengembangan perangkat lunak yang kompleks dan efisien.

### Tabel 3: Algoritma Standard Library Umum untuk Array

|                      |               |                                                                                     |
| -------------------- | ------------- | ----------------------------------------------------------------------------------- |
| **Algoritma**        | **Header**    | **Deskripsi Singkat**                                                               |
| `std::sort`          | `<algorithm>` | Mengurutkan elemen dalam rentang yang ditentukan. Sangat efisien, $O(N \;log \;N)$. |
| `std::find`          | `<algorithm>` | Mencari kemunculan pertama dari nilai tertentu dalam rentang.                       |
| `std::binary_search` | `<algorithm>` | Memeriksa apakah suatu nilai ada dalam rentang yang terurut.                        |
| `std::accumulate`    | `<numeric>`   | Menghitung jumlah elemen dalam rentang.                                             |
| `std::fill`          | `<algorithm>` | Mengisi semua elemen dalam rentang dengan nilai tertentu.                           |
| `std::copy`          | `<algorithm>` | Menyalin elemen dari satu rentang ke rentang lainnya.                               |
| `std::for_each`      | `<algorithm>` | Menerapkan fungsi atau objek fungsi ke setiap elemen dalam rentang.                 |

<br/>

---
# 10 | Kapan Menggunakan Array

Anda sebaiknya menggunakan `std::array` saat ukuran array sudah diketahui saat waktu kompilasi dan Anda ingin performa serta keamanan dari C++ modern.

## 10.1 | Kapan Menggunakan `std::array`?

1. **Ukuran Tetap**: Gunakan `std::array` saat Anda tahu persis berapa banyak elemen yang akan Anda simpan. Contohnya, jika Anda perlu menyimpan nilai dari sensor yang berjumlah 10, atau skor 5 pemain. Karena ukurannya tetap, tidak ada biaya _overhead_ untuk alokasi memori dinamis seperti pada `std::vector`.
<br/>

2. **Performa Tinggi**: `std::array` menyimpan elemennya di **memori stack**, yang jauh lebih cepat daripada memori _heap_ yang digunakan `std::vector`. Ini sangat penting dalam aplikasi yang sensitif terhadap performa, seperti sistem _real-time_ atau _game_.
<br/>

3. **Keamanan dan Fitur STL**: Dibandingkan dengan array C-style (`int arr[10];`), `std::array` lebih aman. Ia menyediakan fungsi `size()` untuk mendapatkan ukurannya dan `at()` untuk akses dengan pemeriksaan batas, sehingga membantu mencegah _buffer overflow_. `std::array` juga dapat bekerja langsung dengan algoritma dari C++ Standard Library (`sort`, `for_each`), membuatnya lebih mudah digunakan dan lebih kuat.

## 10.2 | Perbandingan Singkat

|Fitur|`std::array`|`std::vector`|
|---|---|---|
|**Ukuran**|Tetap (saat kompilasi)|Dinamis (saat _runtime_)|
|**Memori**|Stack (lebih cepat)|Heap (lebih lambat)|
|**Kelebihan**|Performa optimal, aman, fitur STL|Fleksibel, ukuran bisa berubah|

Secara ringkas, `std::array` adalah pilihan terbaik jika Anda menginginkan performa array C-style dengan keamanan dan kemudahan C++ modern.

<br/>

---
# 11 | Kesimpulan

Array adalah struktur data fundamental dalam C++ yang menyimpan koleksi objek dengan tipe data yang sama secara berurutan di lokasi memori yang berdekatan. Karakteristik ini memungkinkan akses elemen yang sangat cepat ($O(1)$) dan efisiensi memori yang tinggi karena memanfaatkan _cache locality_. Indeks berbasis nol adalah fitur kunci, dengan elemen pertama selalu pada indeks 0.

Meskipun array gaya C tradisional menawarkan kontrol tingkat rendah dan kinerja optimal, mereka memiliki keterbatasan signifikan seperti ukuran tetap yang tidak dapat diubah setelah deklarasi, tidak adanya pemeriksaan batas bawaan yang dapat menyebabkan _undefined behavior_, dan kurangnya fitur kontainer modern. Keterbatasan-keterbatasan ini seringkali menjadi sumber _bug_ yang sulit dideteksi dan di-debug, serta membatasi fleksibilitas dalam aplikasi yang membutuhkan ukuran data dinamis. Fenomena "pointer decay" saat melewatkan array gaya C ke fungsi semakin memperumit manajemen ukuran dan keamanan.

Sebagai respons terhadap tantangan ini, C++ Standard Library memperkenalkan kontainer array modern: `std::array` dan `std::vector`. `std::array` menyediakan keamanan dan fitur kontainer STL untuk array ukuran tetap, menjembatani kesenjangan antara efisiensi array gaya C dan kemudahan penggunaan C++ modern. Sementara itu, `std::vector` adalah solusi yang sangat fleksibel dan aman untuk array dinamis, mengelola alokasi dan dealokasi memori secara otomatis, sehingga mengurangi risiko _memory leak_ dan _dangling pointer_.

`std::array` dan `std::vector` juga terintegrasi penuh dengan berbagai algoritma Standard Library seperti  `std::sort`, `std::find`, `std::accumulate`, dll, yang beroperasi pada iterator, memungkinkan kode yang generik, _reusable_, dan sangat efisien. Pemilihan algoritma yang tepat, seperti menggunakan `std::sort` yang efisien $O(N \;log \;N)$ dibandingkan algoritma $O(N^2)$ seperti Bubble Sort, sangat krusial untuk kinerja aplikasi skala besar.

Sebagai kesimpulan, meskipun array gaya C adalah fondasi historis dan penting untuk pemahaman konsep dasar, `std::vector` dan `std::array` adalah pilihan yang jauh lebih disarankan untuk pengembangan C++ modern. Mereka menawarkan kombinasi keamanan, fleksibilitas, dan kinerja yang unggul, serta integrasi yang lebih baik dengan ekosistem Standard Library. Pemilihan struktur data yang tepat—apakah itu array gaya C untuk skenario tingkat rendah yang sangat spesifik, `std::array` untuk koleksi ukuran tetap yang aman, atau `std::vector` untuk kebutuhan dinamis—harus didasarkan pada pertimbangan cermat antara kinerja, fleksibilitas, dan keamanan yang dibutuhkan oleh aplikasi.