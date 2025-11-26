---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSUM-0002
nama_algoritma: 
kategori_algoritma: data structure
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
sumber: programiz.com & gemini AI
date_learned: 2025-06-16T11:30:00
tags:
  - data-structure
  - unordered_map
---
---
# Laporan Teknis: Analisis Mendalam Struktur Data `std::unordered_map` pada C++

`std::unordered_map` merupakan salah satu struktur data fundamental dalam Standard Template Library (STL) C++ yang dirancang untuk mengelola pasangan kunci-nilai (key-value pairs) dengan efisiensi tinggi. Laporan ini akan mengelaborasi definisi, konsep dasar, prinsip hashing, implementasi, kegunaan, dan perbandingannya dengan `std::map`, memberikan pemahaman komprehensif bagi para pengembang.

## Pendahuluan

### Definisi dan Konsep Dasar `std::unordered_map`

`std::unordered_map` adalah sebuah kontainer asosiatif yang menyimpan pasangan kunci-nilai, di mana setiap kunci bersifat unik. Kontainer ini dirancang untuk mencapai kompleksitas waktu rata-rata konstan ($O(1)$) untuk operasi pencarian, penyisipan, dan penghapusan elemen. Secara internal, elemen-elemen dalam `std::unordered_map` tidak diurutkan dalam urutan tertentu. Sebaliknya, mereka diorganisir ke dalam unit-unit yang disebut _buckets_. Penempatan setiap elemen ke dalam _bucket_ tertentu sepenuhnya ditentukan oleh nilai hash dari kuncinya. Kunci-kunci yang menghasilkan kode hash yang sama akan ditempatkan dalam _bucket_ yang sama, yang memungkinkan akses cepat ke elemen individual segera setelah nilai hash dihitung.

![[C++ Unordered Map-2.png|500]]

Sebagai bagian integral dari Standard Template Library (STL) C++, `std::unordered_map` berfungsi sebagai implementasi dari struktur data tabel hash. Setiap elemen dalam kontainer ini secara unik diidentifikasi oleh kuncinya, dan kecepatan akses inilah yang menjadi keunggulan utamanya. Kemampuan untuk melakukan operasi dasar seperti pencarian, penyisipan, dan penghapusan dalam waktu yang hampir konstan, terlepas dari ukuran dataset, merupakan keuntungan kinerja yang sangat penting. Ini memungkinkan pembangunan sistem yang sangat responsif dan skalabel, seperti sistem _caching_ berkinerja tinggi, basis data terdistribusi, atau aplikasi pemrosesan data _real-time_, di mana latensi rendah adalah persyaratan utama. Dengan demikian, `std::unordered_map` tidak hanya sekadar pilihan kontainer, melainkan sebuah alat fundamental yang mendukung arsitektur perangkat lunak berkinerja tinggi dalam pengembangan modern.

### Peran dalam Standard Template Library (STL) C++

Dalam ekosistem STL C++, `std::unordered_map` menempati posisi penting sebagai salah satu dari berbagai kontainer asosiatif, bersanding dengan `std::map`, `std::multimap`, dan `std::unordered_multimap`. STL secara keseluruhan merupakan koleksi kelas template, algoritma, dan iterator yang telah diuji dan dioptimalkan secara ekstensif. Tujuan utamanya adalah untuk memfasilitasi penulisan kode C++ yang lebih bersih, lebih cepat, dan lebih mudah dikelola.

Desain STL didasarkan pada filosofi inti "Anda tidak membayar untuk apa yang tidak Anda gunakan" (`You don't pay for what you don't use`). Penyediaan berbagai kontainer, seperti `std::unordered_map` yang tidak terurut namun cepat, dan `std::map` yang terurut namun dengan kompleksitas logaritmik, mencerminkan filosofi ini. Setiap kontainer dioptimalkan untuk skenario penggunaan tertentu, memungkinkan pengembang untuk memilih struktur data yang paling sesuai dengan kebutuhan spesifik aplikasi mereka tanpa menanggung _overhead_ fitur yang tidak relevan. Oleh karena itu, pemahaman mendalam tentang karakteristik dan _trade-off_ dari setiap kontainer STL adalah esensial untuk merancang sistem yang efisien dan berkinerja optimal. Pemilihan kontainer yang tepat bukan hanya masalah preferensi, melainkan keputusan arsitektural yang memengaruhi skalabilitas dan responsivitas aplikasi secara keseluruhan.

## Prinsip Hashing dan Resolusi Konflik

### Mekanisme Hashing: Bagaimana kunci diubah menjadi nilai hash

Prinsip _hashing_ adalah inti operasional dari `std::unordered_map`. Setiap kunci yang dimasukkan ke dalam unordered map diubah menjadi kode hash numerik oleh sebuah fungsi hash. Kode hash inilah yang kemudian digunakan untuk menentukan lokasi penyimpanan elemen dalam struktur data internal `std::unordered_map`. Fungsi hash didefinisikan sebagai objek fungsi unary (sering disebut _functor_) yang menerima objek bertipe kunci sebagai argumen dan mengembalikan nilai hash bertipe `std::size_t`. Implementasinya dapat berupa kelas yang meng-overload `operator()` atau sebagai _pointer_ ke fungsi.

Secara _default_, `std::unordered_map` menggunakan `std::hash<Key>` yang disediakan oleh STL. Fungsi _default_ ini dirancang untuk menghasilkan nilai hash dengan probabilitas kolisi yang sangat rendah, mendekati batas teoritis. Nilai hash yang dihasilkan oleh fungsi ini adalah kunci bagi `std::unordered_map` untuk mengatur elemen-elemennya secara internal, yang pada gilirannya mempercepat proses pencarian elemen individual.

Kinerja `std::unordered_map` yang diklaim memiliki kompleksitas waktu rata-rata $O(1)$ sangat bergantung pada distribusi elemen yang merata di seluruh _buckets_. Distribusi yang merata ini secara langsung dikendalikan oleh kualitas fungsi hash. Jika fungsi hash yang digunakan buruk, misalnya menghasilkan banyak kolisi atau mengelompokkan elemen di _bucket_ tertentu, banyak elemen akan menumpuk di _bucket_ yang sama. Ketika sebuah _bucket_ menjadi sangat panjang, operasi pencarian, penyisipan, dan penghapusan di dalam _bucket_ tersebut akan memerlukan traversal linear, mengubah kompleksitas efektif dari $O(1)$ menjadi mendekati $O(N)$ (linear) untuk _bucket_ tersebut.  Hal ini menunjukkan bahwa meskipun `std::unordered_map` menawarkan potensi kinerja tinggi, kinerja _real-world_ dapat terdegradasi secara signifikan jika fungsi hash tidak dirancang dengan baik, mengubah keunggulan teoretis menjadi _bottleneck_ praktis.

### Penanganan Konflik (Collision Resolution): Penjelasan tentang _separate chaining_ (rantai terpisah) dan _open addressing_ (pengalamatan terbuka) dalam konteks `std::unordered_map`.

_Hash collision_ adalah fenomena yang terjadi ketika dua kunci yang berbeda menghasilkan nilai hash yang sama, yang berarti keduanya dipetakan ke _bucket_ yang sama. Untuk mengatasi kolisi ini, `std::unordered_map` mengimplementasikan strategi resolusi konflik. Dua strategi yang paling umum adalah _separate chaining_ dan _open addressing_.

Standar C++ secara efektif mensyaratkan implementasi `std::unordered_map` (dan `std: :unordered_set`) untuk menggunakan _separate chaining_. Ini berarti struktur internalnya adalah sebuah array _buckets_, di mana setiap _bucket_ menampung kepala dari sebuah _linked list_. Elemen-elemen yang berkolisi kemudian disimpan dalam _linked list_ yang sesuai dengan _bucket_ mereka. Keunggulan _separate chaining_ meliputi kemampuannya untuk menangani _load factor_ lebih dari 1 (jumlah elemen melebihi jumlah _bucket_) dan toleransinya yang lebih baik terhadap fungsi hash yang kurang ideal. Selain itu, operasi penghapusan cenderung lebih sederhana dalam implementasi _separate chaining_.

Pemilihan _separate chaining_ oleh implementasi STL melibatkan penggunaan _linked list_ (atau struktur data lain seperti pohon) di setiap _bucket_. Pendekatan ini menimbulkan _overhead_ memori tambahan per elemen karena kebutuhan _pointer_ untuk setiap _node_ dalam _linked list_. Namun,_separate chaining_ lebih mudah untuk mengelola operasi penghapusan dan lebih tangguh terhadap distribusi hash yang tidak sempurna atau _load factor_ yang tinggi.

Sebagai perbandingan, _open addressing_ (alternatif) menggunakan satu array tunggal dan mencari slot kosong berikutnya saat kolisi. Metode ini lebih efisien memori tetapi lebih kompleks untuk penghapusan dan kinerjanya dapat menurun drastis jika tabel mendekati penuh. Fakta bahwa STL memilih _separate chaining_ (secara implisit melalui jaminan standar seperti `max_load_factor()` _default_ 1.0 12) menunjukkan prioritas pada fleksibilitas, kemudahan penggunaan, dan ketahanan terhadap skenario _worst-case_ yang tidak terduga, meskipun dengan biaya _overhead_ memori yang sedikit lebih tinggi. Hal ini menyoroti bahwa desain pustaka standar seringkali merupakan hasil kompromi yang cermat antara kinerja teoretis, penggunaan memori, dan kemudahan serta keandalan penggunaan di berbagai aplikasi.

### Fungsi Hash Kustom: Kapan dan bagaimana mengimplementasikan fungsi hash untuk tipe data yang ditentukan pengguna

Ketika pengembang ingin menggunakan tipe data yang ditentukan pengguna (misalnya, _struct_ atau kelas kustom) sebagai kunci dalam `std::unordered_map`, mereka harus menyediakan fungsi hash kustom. Ini dilakukan dengan mendefinisikan sebuah _functor_ — yaitu, sebuah _struct_ atau kelas yang meng-overload `operator()`. _Functor_ ini harus menerima objek bertipe kunci kustom sebagai input dan mengembalikan nilai hash bertipe `std::size_t`. Selain fungsi hash kustom, tipe kunci juga harus mengimplementasikan `operator==` untuk perbandingan kesetaraan, atau pengembang harus menyediakan predikat kesetaraan kustom. `std::unordered_map` menggunakan `operator==` untuk membedakan kunci-kunci yang memiliki nilai hash yang sama (kolisi) tetapi sebenarnya berbeda.

Berikut adalah contoh kode yang mengilustrasikan implementasi fungsi hash kustom untuk tipe data `Point`:


```cpp
#include <iostream>
#include <unordered_map>
#include <functional>
#include <string> // Diperlukan untuk std::hash<int>()

// 1. Definisikan tipe data yang ditentukan pengguna
struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}

    // Diperlukan untuk perbandingan kesetaraan dalam unordered_map
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

// 2. Definisikan fungsi hash kustom untuk tipe Point
struct PointHasher {
    std::size_t operator()(const Point& p) const {
        // Menggabungkan hash dari x dan y menggunakan bitwise XOR
        // Geser satu hash untuk menghindari kolisi jika x dan y ditukar
        return std::hash<int>()(p.x) ^ (std::hash<int>()(p.y) << 1);
    }
};

int main() {
    // 3. Gunakan fungsi hash kustom dalam std::unordered_map
    std::unordered_map<Point, int, PointHasher> point_map;

    point_map[Point(1, 2)] = 10;
    point_map[Point(3, 4)] = 20;
    point_map[Point(5, 6)] = 30;

    std::cout << "Elemen dalam point_map:" << std::endl;
    for (const auto& pair : point_map) {
        std::cout << "Point(" << pair.first.x << ", "
                  << pair.first.y << "): " << pair.second << std::endl;
    }

    // Mengakses elemen
    Point search_point(3, 4);
    if (point_map.count(search_point)) {
        std::cout << "Nilai untuk Point(3,4): " << point_map[search_point] << std::endl;
    } else {
        std::cout << "Point(3,4) tidak ditemukan." << std::endl;
    }

    return 0;
}
```

**Catatan Sedikit**
Untuk hash yang lebih aman terhadap kolisi:
```cpp
return std::hash<int>()(p.x) ^ (std::hash<int>()(p.y) << 1);
```

bisa diganti dengan metode _boost::hash_combine()_ atau versi manual seperti:
```cpp
std::size_t h1 = std::hash<int>()(p.x);
std::size_t h2 = std::hash<int>()(p.y);
return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2)); // teknik hash_combine
```

---

Menggunakan tipe data kustom sebagai kunci `std::unordered_map` menambahkan lapisan kompleksitas karena memerlukan implementasi fungsi hash kustom dan `operator==`. Fungsi hash yang tidak dirancang dengan baik dapat menghasilkan banyak kolisi, yang secara drastis menurunkan kinerja `std::unordered_map` dari $O(1)$ rata-rata menjadi mendekati $O(N)$ dalam kasus terburuk.

Lebih kritis lagi, jika `operator==` tidak konsisten dengan fungsi hash (yaitu, dua kunci yang dianggap sama oleh `operator==` tetapi menghasilkan nilai hash yang berbeda), ini akan menyebabkan perilaku tak terdefinisi (`undefined behavior`), yang merupakan salah satu jenis _bug_ paling sulit untuk didiagnosis dalam C++. Risiko ini tidak ada pada `std::map` karena `std::map` hanya memerlukan perbandingan `<` yang ketat dan tidak bergantung pada fungsi hash. Oleh karena itu, pengembang harus sangat berhati-hati, memahami prinsip-prinsip _hashing_, dan melakukan pengujian unit yang ketat pada fungsi hash kustom dan operator kesetaraan mereka untuk memastikan kebenaran dan kinerja. Ini merupakan tanggung jawab tambahan yang signifikan yang harus dipertimbangkan.

## Deklarasi dan Inisialisasi `std::unordered_map`

### Sintaks Dasar Deklarasi

Untuk dapat menggunakan `std::unordered_map` dalam program C++, _header_ `<unordered_map>` harus disertakan. Sintaks dasar untuk mendeklarasikan sebuah `std::unordered_map` adalah sebagai berikut: `std::unordered_map<KeyType, ValueType> mapName;`. Dalam sintaks ini, `KeyType` menentukan tipe data untuk kunci yang akan digunakan, dan `ValueType` menentukan tipe data untuk nilai yang akan disimpan yang berpasangan dengan kunci tersebut. 

Sebagai contoh, deklarasi `std::unordered_map<std::string, int> myMap;` akan membuat sebuah unordered map di mana kunci adalah `std::string` (misalnya, nama) dan nilai adalah `int` (misalnya, usia).

### Berbagai Metode Inisialisasi

`std::unordered_map` menawarkan beberapa metode untuk inisialisasi, memungkinkan fleksibilitas dalam cara pengembang mengisi kontainer dengan data awal:

- **Inisialisasi Default (Kosong):** Sebuah `unordered_map` dapat dideklarasikan tanpa elemen awal, menghasilkan kontainer kosong. Ini adalah metode inisialisasi paling sederhana ketika data akan ditambahkan nanti dalam program.
    
    
    
    ```cpp
    std::unordered_map<int, std::string> um1; // Membuat unordered_map kosong
    ```
    
    
    
- **Menggunakan `Initializer List`:** `unordered_map` dapat diinisialisasi secara langsung dengan daftar pasangan kunci-nilai yang diapit kurung kurawal `{}`. Ini adalah cara yang ringkas dan mudah dibaca untuk mengisi unordered map saat deklarasi.
    
    
    
    ```cpp
    std::unordered_map<int, std::string> um2 = {{1, "Geeks"}, {2, "For"}, {3, "C++"}};
    // Atau menggunakan uniform initialization (sejak C++11):
    std::unordered_map<std::string, int> unordered_map2 { {"One", 1}, {"Two", 2}, {"Three", 3} };
    ```
    
    
    
- **Penyisipan Satu per Satu (`operator` atau `insert()`):** Elemen dapat ditambahkan ke `unordered_map` setelah deklarasinya menggunakan dua operator utama, yang memiliki perilaku berbeda:
    
    - Menggunakan `operator` (`[]`): Jika kunci yang diberikan belum ada dalam peta, operator ini akan menyisipkan elemen baru dengan kunci tersebut dan nilai yang dikonstruksi secara _default_, lalu mengembalikan referensi ke nilai tersebut. Jika kunci sudah ada, ia akan mengembalikan referensi ke nilai yang sudah ada, memungkinkan pembaruan.
        
        
        
        ```cpp
        std::unordered_map<int, std::string> um;
        um[1] = "Geeks"; // Menyisipkan atau memperbarui nilai untuk kunci 1
        ```
        
        
        
    - Menggunakan `insert()`: Metode ini menyisipkan pasangan kunci-nilai ke dalam unordered map. Penting untuk dicatat bahwa `insert()` hanya akan menyisipkan elemen jika kunci yang diberikan belum ada. Jika kunci sudah ada, `insert()` tidak akan melakukan penyisipan dan tidak akan memperbarui nilai yang ada. Ia akan mengembalikan `std::pair<iterator, bool>` di mana `bool` akan bernilai `false` jika penyisipan tidak terjadi.
        
        
        
        ```cpp
        um.insert({2, "For"}); // Menyisipkan jika kunci 2 belum ada
        um.insert({{3, "C++"}, {4, "STL"}}); // Menyisipkan beberapa elemen sekaligus
        ```
        
        
        
- **Dari Kontainer Lain (Range Constructor):** Sebuah `unordered_map` dapat diinisialisasi dengan menyalin elemen dari rentang yang ditentukan oleh iterator dari kontainer lain (misalnya, `std: :vector` dari `std: :pair`). Ini berguna ketika data sumber sudah ada dalam format yang berbeda.
    
    
    
    ```cpp
    std::vector<std::pair<int, std::string>> v = {{1, "one"}, {2, "two"}};
    std::unordered_map<int, std::string> um_from_vec(v.begin(), v.end());
    ```
    
    
    

Perbedaan semantik antara `operator`(`[]`) dan `insert()` untuk penyisipan adalah hal yang krusial. `std::unordered_map` menyediakan kedua mekanisme ini untuk menambahkan data. Meskipun keduanya dapat menyisipkan elemen, perilaku mereka berbeda secara fundamental ketika kunci sudah ada.

`operator` akan selalu memastikan kunci ada; jika tidak ada, ia akan menyisipkan nilai _default_ dan mengembalikan referensi yang dapat dimodifikasi. 

Sebaliknya, `insert()` adalah operasi "sisipkan-jika-belum-ada"; ia tidak akan memperbarui nilai yang ada jika kunci sudah ditemukan, melainkan hanya mengabaikan penyisipan baru untuk kunci tersebut. Implikasi dari perbedaan ini adalah bahwa pengembang harus memilih metode yang tepat berdasarkan logika aplikasi mereka: 

Gunakan `operator` ketika menginginkan operasi "set atau update" (yaitu, pastikan kunci ada dan atur/perbarui nilainya), dan gunakan `insert()` ketika menginginkan operasi "sisipkan jika tidak ada" (yaitu, hanya tambahkan jika kunci benar-benar baru). Kesalahan dalam pemilihan dapat menyebabkan _bug_ halus, seperti data yang tidak terduga karena penimpaan yang tidak disengaja atau kegagalan untuk menyisipkan elemen baru.

## Fungsi Anggota (Member Functions) `std::unordered_map`

`std::unordered_map` menyediakan serangkaian fungsi anggota yang kaya untuk mengelola elemen, kapasitas, dan interaksi dengan struktur internalnya, memungkinkan manipulasi data yang efisien.

### Operasi Dasar

- **Penyisipan:**
    
    - `insert()`: Fungsi ini menyisipkan satu atau lebih pasangan kunci-nilai ke dalam peta. Penting untuk diingat bahwa `insert()` tidak akan menyisipkan elemen baru jika kunci yang diberikan sudah ada, sehingga menjaga properti kunci unik dari `unordered_map`.
    <br/>
    
    - `operator`(`[]`): Operator ini digunakan untuk mengakses atau menyisipkan elemen. Jika kunci tidak ada dalam unordered map, ia akan menyisipkan elemen baru dengan kunci tersebut dan nilai yang dikonstruksi secara _default_. Jika kunci sudah ada, ia mengembalikan referensi ke nilai yang ada, memungkinkan pembaruan.
    <br/>
    
    - `emplace()` (sejak C++11): Membangun elemen baru secara _in-place_ di dalam unordered map. Ini berarti objek nilai dibuat langsung di lokasi memori yang dialokasikan oleh `unordered_map`, menghindari penyalinan atau pemindahan objek sementara yang mungkin terjadi dengan `insert()`. Ini bisa lebih efisien untuk tipe nilai yang kompleks.
    <br/>
    
    - `try_emplace()` (sejak C++17): Fungsi ini menyisipkan elemen secara _in-place_ hanya jika kunci belum ada dalam peta. Jika kunci sudah ada, tidak ada operasi yang dilakukan, dan nilai yang ada tidak diubah. Fungsi ini mengembalikan `std::pair` yang berisi iterator ke elemen dan `bool` yang menunjukkan apakah penyisipan benar-benar terjadi.
    <br/>
    
    - `insert_or_assign()` (sejak C++17): Fungsi ini menyisipkan elemen baru jika kunci tidak ada, atau menetapkan nilai baru ke elemen yang ada jika kunci sudah ditemukan. Ini adalah kombinasi fungsionalitas `insert()` dan `operator` yang lebih eksplisit dan seringkali lebih jelas dalam niat kode.
    <br/>
    
- **Akses (Lookup):**
    
    - `at()`: Mengembalikan referensi ke nilai yang terkait dengan kunci tertentu. Metode ini melakukan pemeriksaan batas (`bounds checking`) dan akan melempar pengecualian `std::out_of_range` jika kunci tidak ditemukan. Ini memberikan keamanan yang lebih tinggi.
    <br/>
    
    - `operator`(`[]`): Mengembalikan referensi ke nilai yang terkait dengan kunci. Jika kunci tidak ditemukan, ia akan menyisipkan kunci baru dengan nilai yang dikonstruksi secara _default_. Metode ini tidak melakukan pemeriksaan batas, sehingga akses ke kunci yang tidak ada tidak akan melempar pengecualian tetapi dapat menyebabkan penyisipan yang tidak diinginkan.
    <br/>
    
    - `find()`: Mengembalikan iterator ke elemen dengan kunci yang ditentukan. Jika elemen tidak ditemukan, ia mengembalikan iterator ke `end()`, yang merupakan penanda "satu setelah elemen terakhir".
    <br/>
    
    - `count()`: Mengembalikan jumlah elemen dengan kunci yang ditentukan. Karena `std::unordered_map` hanya menyimpan kunci unik, fungsi ini akan selalu mengembalikan 0 (jika kunci tidak ada) atau 1 (jika kunci ada). Ini adalah cara yang efisien untuk memeriksa keberadaan kunci.
    <br/>
    
    - `contains()` (sejak C++20): Sebuah fungsi yang lebih modern dan eksplisit untuk memeriksa keberadaan kunci, mengembalikan `true` atau `false`. Secara fungsional setara dengan `count(key) > 0`.
    <br/>
    
    - `equal_range()`: Mengembalikan sepasang iterator yang mendefinisikan rentang elemen yang cocok dengan kunci tertentu. Karena kunci unik, rentang ini akan berisi nol atau satu elemen.
    <br/>
    
- **Pembaruan Nilai:**

	Nilai yang terkait dengan kunci yang sudah ada dapat diperbarui dengan menggunakan `operator`(`[]`) atau `at()` dan menetapkan nilai baru ke referensi yang dikembalikan. Pemilihan antara `operator` dan `at()` untuk akses dan pembaruan memiliki konsekuensi performa dan keamanan. `operator` menawarkan akses yang lebih cepat karena tidak melakukan pemeriksaan batas. Namun, jika digunakan untuk mengakses kunci yang tidak ada, ia secara implisit akan menyisipkan elemen baru dengan nilai yang dikonstruksi secara _default_. 
	
	Sebaliknya, `at()` menyediakan keamanan yang lebih tinggi dengan melakukan pemeriksaan batas dan melempar pengecualian `std::out_of_range` jika kunci tidak ditemukan. Ini mencegah penyisipan yang tidak disengaja atau perilaku tak terdefinisi.
	
	Pilihan antara kedua metode ini adalah _trade-off_ antara kinerja mentah dan ketahanan kode. Dalam skenario di mana keberadaan kunci sudah dijamin (misalnya, setelah panggilan `find()` atau `count()` yang berhasil), `operator` mungkin lebih disukai untuk kinerja optimal. Namun, untuk akses yang mungkin gagal atau di mana penyisipan implisit tidak diinginkan, `at()` adalah pilihan yang lebih aman karena secara eksplisit mengelola kasus kesalahan melalui pengecualian. Oleh karena itu, pengembang harus secara sadar memilih metode akses berdasarkan ekspektasi tentang keberadaan kunci dan strategi penanganan kesalahan yang diinginkan dalam aplikasi mereka.
    <br/>
- **Penghapusan:**
    
    - `erase()`: Menghapus elemen dari peta. Ini dapat dilakukan dengan menyediakan kunci elemen yang akan dihapus, atau dengan menyediakan iterator ke elemen tersebut.
    <br/>
    - `clear()`: Menghapus semua elemen dari `std::unordered_map`, membuatnya kosong. Operasi ini tidak mengubah kapasitas memori yang dialokasikan, hanya jumlah elemen aktif.
        

### Fungsi Kapasitas dan Informasi

Fungsi-fungsi ini menyediakan informasi tentang status dan alokasi memori internal `std::unordered_map`:

- `size()`: Mengembalikan jumlah elemen saat ini yang disimpan dalam `unordered_map`.
<br/>
- `empty()`: Memeriksa apakah `unordered_map` kosong (yaitu, `size()`-nya nol). Mengembalikan `true` jika kosong, `false` jika tidak.
<br/>
- `max_size()`: Mengembalikan jumlah maksimum elemen yang mungkin dapat ditampung oleh `unordered_map`. Nilai ini biasanya dibatasi oleh memori sistem yang tersedia atau batasan implementasi spesifik.
<br/>
- `load_factor()`: Mengembalikan faktor beban saat ini, yang didefinisikan sebagai rasio `size() / bucket_count()`. Ini merupakan rata-rata jumlah elemen per _bucket_.
<br/>
- `max_load_factor()`: Mengelola faktor beban rata-rata maksimum yang diizinkan. Ketika `load_factor` saat ini melebihi `max_load_factor` yang ditentukan, kontainer secara otomatis akan meningkatkan jumlah _bucket_ dan melakukan _rehashing_ semua elemen.
<br/>
- `rehash()`: Memaksa `unordered_map` untuk meregenerasi tabel hash dengan jumlah _bucket_ minimum yang ditentukan. Fungsi ini dapat digunakan untuk mengoptimalkan kinerja setelah serangkaian penyisipan atau penghapusan yang signifikan, atau untuk mengontrol kapan _rehashing_ terjadi.
<br/>
- `reserve()`: Memesan ruang untuk setidaknya jumlah elemen yang ditentukan. Fungsi ini dapat memicu _rehashing_ untuk memastikan kapasitas yang cukup, membantu mencegah _rehashing_ yang tidak perlu di masa mendatang jika jumlah elemen yang diharapkan diketahui sebelumnya.
<br/>

Manajemen kinerja proaktif melalui kontrol faktor beban sangat penting. Kinerja $O(1)$ rata-rata dari `std::unordered_map` sangat bergantung pada pemeliharaan faktor beban yang rendah, yang menjamin distribusi elemen yang baik dan _bucket_ yang pendek. 

Ketika `load_factor` melebihi `max_load_factor`, `unordered_map` akan secara otomatis melakukan _rehashing_.

_Rehashing_ adalah operasi yang mahal, dengan kompleksitas waktu $O(N)$ (linear terhadap jumlah elemen), karena semua elemen harus di-hash ulang dan dipindahkan ke _bucket_ baru.

Dengan menggunakan `reserve()` atau `rehash()` secara proaktif, pengembang dapat mengontrol kapan _rehashing_ terjadi, menghindari _rehashing_ yang tidak terduga selama operasi kritis waktu atau periode beban tinggi. Hal ini menunjukkan bahwa pemantauan dan manajemen faktor beban adalah praktik terbaik untuk memastikan kinerja yang konsisten dan dapat diprediksi dari `std::unordered_map` dalam aplikasi yang sensitif terhadap latensi, mengubahnya dari perilaku "otomatis" menjadi perilaku yang dikelola secara strategis.

### Iterasi dan Antarmuka Bucket

`std::unordered_map` menyediakan antarmuka untuk iterasi dan inspeksi _bucket_ internalnya:

- `begin()`, `end()`, `cbegin()`, `cend()`: Fungsi-fungsi ini mengembalikan iterator yang dapat digunakan untuk melintasi semua elemen dalam `unordered_map`. Penting untuk diingat bahwa urutan iterasi tidak dijamin dan dapat berubah antar eksekusi atau setelah modifikasi unordered map.
<br/>
- `bucket_count()`: Mengembalikan jumlah _bucket_ yang saat ini digunakan oleh kontainer. Ini memberikan gambaran tentang ukuran tabel hash internal.
<br/>
- `bucket_size(n)`: Mengembalikan jumlah elemen yang disimpan dalam _bucket_ tertentu, yang diidentifikasi oleh indeks `n`.
<br/>
- `bucket(key)`: Mengembalikan indeks _bucket_ tempat elemen dengan kunci `key` berada. Ini memungkinkan pengembang untuk melihat ke _bucket_ mana kunci tertentu dipetakan.
<br/>
- `begin(size_type n)`, `end(size_type n)`: Mengembalikan iterator yang memungkinkan traversal elemen hanya dalam _bucket_ tertentu (`n`). Ini berguna untuk memeriksa isi _bucket_ individual.
<br/>

Pentingnya antarmuka _bucket_ untuk _debugging_ dan optimasi tingkat lanjut tidak dapat diremehkan. Meskipun `std::unordered_map` dirancang sebagai "kotak hitam" yang efisien, antarmuka _bucket_ menyediakan visibilitas ke dalam struktur internalnya. Fungsi-fungsi seperti `bucket_count()`, `bucket_size()`, dan `bucket(key)` memungkinkan pengembang untuk secara langsung mengamati distribusi elemen di seluruh _bucket_. Informasi ini sangat berharga untuk mendiagnosis masalah kinerja yang terkait dengan kolisi hash yang berlebihan, di mana elemen mungkin terkonsentrasi di beberapa _bucket_ saja. 

Dengan menganalisis distribusi _bucket_, pengembang dapat memvalidasi efektivitas fungsi hash kustom atau mengidentifikasi pola data yang menyebabkan kinerja suboptimal. Oleh karena itu, pengetahuan tentang antarmuka _bucket_ mengubah `std::unordered_map` dari struktur data yang hanya dapat digunakan menjadi struktur yang dapat dianalisis secara mendalam, di-_debug_, dan dioptimalkan untuk kasus penggunaan spesifik.

## Kegunaan dan Aplikasi Dunia Nyata

`std::unordered_map` adalah struktur data yang sangat serbaguna dan efisien, menjadikannya pilihan ideal untuk berbagai aplikasi di dunia nyata. Keunggulannya terutama terlihat di mana pengambilan data cepat berdasarkan kunci unik sangat penting, dan urutan data tidak menjadi masalah.

### Studi Kasus Implementasi

- **Kamus dan Tabel Simbol:**
    
    - **Deskripsi:** `std::unordered_map` sering digunakan dalam implementasi kamus bahasa untuk menyimpan definisi kata atau dalam kompilator dan _interpreter_ untuk mengelola tabel simbol. Dalam konteks ini, nama simbol dipetakan ke atribut-atributnya (tipe, _scope_, alamat memori).
    <br/>
    - **Mengapa `unordered_map`:** Memungkinkan pencarian definisi kata atau atribut simbol yang sangat cepat berdasarkan nama (kunci), yang krusial untuk kinerja kompilasi atau pencarian kamus interaktif.
    <br/>
- **Sistem Cache:**
    
    - **Deskripsi:** Menerapkan sistem _cache_ di mana data yang sering diakses disimpan dalam memori untuk pengambilan cepat di kemudian hari. Kunci bisa berupa URL halaman web, ID pengguna, atau ID produk, dan nilai adalah data yang di-_cache_.
        
    - **Mengapa `unordered_map`:** Menyediakan waktu akses $O(1)$ rata-rata, yang sangat penting untuk sistem _cache_ berkinerja tinggi yang bertujuan mengurangi latensi akses data ke sumber yang lebih lambat (misalnya, disk atau jaringan).
    <br/>
- **Penghitungan Frekuensi/Kemunculan:**
    
    - **Deskripsi:** Digunakan secara luas untuk menghitung frekuensi kemunculan item, seperti kata dalam dokumen (_word counting_), karakter dalam _string_, atau suara dalam pemilu. Kunci adalah item yang dihitung, dan nilai adalah hitungannya.
    <br/>
    - **Mengapa `unordered_map`:** Sangat efisien untuk menambahkan item baru dan memperbarui hitungannya (jika item sudah ada), serta untuk mengambil hitungan item tertentu.
    <br/>
    - **Contoh Kode (Penghitungan Suara):**
        
        
        
        ```cpp
        #include <iostream>
        #include <unordered_map>
        #include <string>
        #include <vector>
        
        int main() {
            std::vector<std::string> votes_list = {"Alice", "Bob", "Alice", "Charlie", "Bob", "Alice"}; // Daftar suara yang masuk
            std::unordered_map<std::string, int> vote_counts; // unordered_map untuk menyimpan hitungan suara
        
            // Menghitung suara
            for (const std::string& vote : votes_list) {
                vote_counts[vote]++; // Menambah hitungan untuk setiap suara yang masuk
            }
        
            std::cout << "Hasil Perhitungan Suara:" << std::endl;
            for (const auto& pair : vote_counts) {
                std::cout << pair.first << ": " << pair.second << std::endl;
            }
            return 0;
        }
        ```
        
        
    <br/>
- **Sistem Inventaris:**
    
    - **Deskripsi:** Mengelola inventaris produk di toko atau gudang, di mana nama produk (atau ID produk) dipetakan ke kuantitas yang tersedia.
    <br/>
    - **Mengapa `unordered_map`:** Memungkinkan pencarian dan pembaruan kuantitas produk yang sangat cepat, mendukung operasi _real-time_ seperti penjualan atau penerimaan stok baru.
    <br/>
    - **Contoh Kode (Inventaris Toko):**
        
        
        
        ```cpp
        #include <iostream>
        #include <unordered_map>
        #include <string>
        
        int main() {
            std::unordered_map<std::string, int> store_inventory = {
                {"Apel", 100}, {"Pisang", 80}, {"Jeruk", 90} // Inisialisasi inventaris
            };
        
            store_inventory["Pir"] = 50; // Menambah produk baru
            store_inventory["Apel"] -= 10; // Memperbarui kuantitas
        
            std::cout << "Inventaris Toko:" << std::endl;
            for (const auto& pair : store_inventory) {
                std::cout << pair.first << ": " << pair.second << std::endl;
            }
            return 0;
        }
        ```
        
        
    <br/>
- **Katalog Perpustakaan:**
    
    - **Deskripsi:** Mengelola katalog buku di perpustakaan, di mana ID buku berfungsi sebagai kunci, dan detail buku (seperti judul, penulis, tahun publikasi) disimpan sebagai nilai. Nilai bisa berupa struktur data lain (misalnya, `unordered_map` bersarang atau _struct_ kustom) untuk menyimpan atribut detail.
    <br/>
    - **Mengapa `unordered_map`:** Memungkinkan pengambilan detail buku yang cepat berdasarkan ID uniknya, memfasilitasi sistem pencarian perpustakaan yang responsif.
    <br/>
    - **Contoh Kode (Katalog Perpustakaan):**
        
		```cpp
		#include <iostream>
		#include <unordered_map>
		#include <string>
		
		int main() {
		    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> library_catalog;
		
		    // Detail buku 1
		    std::string book_id_1 = "978-0321765723";
		    std::unordered_map<std::string, std::string> book_details_1;
		    book_details_1["Judul"] = "The C++ Programming Language";
		    book_details_1["Penulis"] = "Bjarne Stroustrup";
		    book_details_1["Tahun"] = "2013"; // ✅ perbaikan: masukkan tahun sebagai entri map
		    library_catalog[book_id_1] = book_details_1;
		
		    // Detail buku 2
		    std::string book_id_2 = "978-0132358867";
		    std::unordered_map<std::string, std::string> book_details_2;
		    book_details_2["Judul"] = "Clean Code";
		    book_details_2["Penulis"] = "Robert C. Martin";
		    book_details_2["Tahun"] = "2008"; // ✅ perbaikan
		    library_catalog[book_id_2] = book_details_2;
		
		    // Mengakses detail buku
		    std::cout << "Detail untuk ID Buku " << book_id_1 << ":\n";
		    if (library_catalog.count(book_id_1)) {
		        for (const auto& detail_pair : library_catalog[book_id_1]) {
		            std::cout << "  " << detail_pair.first << ": " << detail_pair.second << std::endl;
		        }
		    }
		
		    return 0;
		}
		```
        
        
        

### Skenario Penggunaan Umum di mana `std::unordered_map` unggul

`std::unordered_map` secara konsisten menunjukkan kinerja $O(1)$ rata-rata untuk operasi kunci. Banyak skenario aplikasi di dunia nyata, seperti sistem _caching_, _lookup_ ID pengguna, atau penghitungan frekuensi data, tidak memerlukan data yang diurutkan. Dalam kasus-kasus ini, `std::unordered_map` secara inheren lebih cepat dan lebih efisien daripada `std::map` (yang memiliki kompleksitas $O(\log N)$) karena menghindari _overhead_ pengurutan.

Hal ini mengarah pada rekomendasi yang berkembang di komunitas C++ bahwa `std::unordered_map` harus menjadi pilihan _default_ untuk kontainer asosiatif, kecuali ada kebutuhan eksplisit untuk pengurutan kunci atau jika masalah kinerja spesifik yang terkait dengan _hashing_ teridentifikasi. Implikasinya adalah bahwa pengembang modern harus mengubah pola pikir dari `std::map` sebagai _default_ historis, dan secara otomatis mempertimbangkan `std::unordered_map` terlebih dahulu untuk sebagian besar kebutuhan _key-value lookup_. 

Kontainer ini unggul dalam skenario di mana kecepatan pencarian, penyisipan, dan penghapusan adalah prioritas utama, dan urutan elemen tidak relevan atau tidak perlu dipertahankan. Terutama untuk dataset yang besar, keuntungan kinerja $O(1)$ rata-rata secara signifikan lebih baik daripada $O(\log N)$ yang ditawarkan oleh kontainer terurut. Aplikasi lain termasuk implementasi tabel hash dalam sistem basis data, indeks data, atau sistem _parsing_ bahasa pemrograman, serta pencarian cepat berdasarkan kunci dalam struktur data yang kompleks.

## Perbandingan dengan `std::map`

Pemilihan antara `std::unordered_map` dan `std::map` adalah keputusan desain krusial dalam C++ yang sangat memengaruhi kinerja dan perilaku aplikasi. Meskipun keduanya berfungsi sebagai kontainer asosiatif yang menyimpan pasangan kunci-nilai, perbedaan mendasar dalam implementasi internal mereka menghasilkan karakteristik kinerja yang sangat berbeda.

### Perbedaan Implementasi Internal

- **`std::unordered_map`:** Diimplementasikan menggunakan **tabel hash** (_hash table_). Elemen-elemen disimpan dalam _buckets_ yang diatur berdasarkan nilai hash dari kuncinya, tanpa urutan spesifik di antara _buckets_ atau di dalam _bucket_ (kecuali untuk _separate chaining_ yang mempertahankan urutan penyisipan dalam _linked list_).
<br/>
- **`std::map`:** Diimplementasikan menggunakan **pohon biner pencarian seimbang** (_balanced binary search tree_), yang paling umum adalah _Red-Black Tree_. Struktur ini secara otomatis menjaga elemen tetap dalam urutan kunci yang diurutkan.
    

Perbedaan struktur data internal ini memiliki dampak signifikan pada karakteristik kinerja dan memori. Tabel hash (digunakan oleh `unordered_map`) mengandalkan fungsi hash untuk "langsung" memetakan kunci ke lokasi memori (atau _bucket_), yang memungkinkan akses sangat cepat. 

Pohon biner pencarian seimbang (_balanced binary search tree_) (digunakan oleh`map`) mempertahankan urutan dengan menempatkan elemen secara hierarkis, yang memerlukan traversal dari akar ke _node_ yang relevan. Ini menjamin urutan tetapi dengan biaya _overhead_ navigasi. Perbedaan fundamental ini secara langsung menjelaskan mengapa `unordered_map` tidak terurut tetapi mampu mencapai kinerja $O(1)$ rata-rata, sementara `map` terurut tetapi memiliki kompleksitas $O(log N)$. 

Selain itu, struktur _node-based_ `map` dapat menyebabkan _cache locality_ yang lebih buruk untuk traversal karena _node-node_ dapat tersebar di memori, sedangkan _contiguous buckets_ `unordered_map` (jika tidak terlalu penuh) dapat menawarkan _cache locality_ yang lebih baik untuk akses _random_. Implikasinya adalah bahwa pemilihan kontainer bukan hanya tentang kompleksitas waktu asimtotik, tetapi juga tentang bagaimana struktur data internal memengaruhi pola akses memori dan efisiensi _cache_, yang sangat penting dalam aplikasi berkinerja tinggi.

### Analisis Kinerja (Kompleksitas Waktu Rata-rata vs. Logaritmik untuk Operasi Kunci)

- **`std::unordered_map`:**
    
    - Operasi pencarian, penyisipan, dan penghapusan elemen memiliki kompleksitas waktu $O(1)$ rata-rata (konstan). Ini adalah keuntungan signifikan untuk dataset besar.
    <br/>
    - Namun, dalam kasus terburuk (misalnya, fungsi hash yang buruk menghasilkan banyak kolisi atau _hash flooding_ yang disengaja), kompleksitas dapat menurun menjadi $O(N)$ (linear), di mana $N$ adalah jumlah elemen.
    <br/>
- **`std::map`:**
    
    - Operasi pencarian, penyisipan, dan penghapusan elemen memiliki kompleksitas waktu $O(\log N)$ (logaritmik). Ini berarti waktu operasi meningkat secara logaritmik dengan ukuran kontainer.
    <br/>
    - Kompleksitas kasus terburuk juga $O(\log N)$, menjadikannya lebih dapat diprediksi dalam skenario _worst-case_.
    <br/>

Secara asimtotik, $O(1)$ selalu lebih efisien daripada $O(\log N)$ untuk $N$ yang sangat besar. Namun, ini adalah kompleksitas rata-rata, dan faktor konstan sering diabaikan dalam analisis asimtotik. Untuk dataset yang sangat kecil (misalnya, di bawah 100 elemen), _overhead_ awal yang terkait dengan perhitungan hash dan manajemen _bucket_ dalam `std::unordered_map` dapat lebih besar daripada keuntungan $O(1)$. Dalam kasus ini, `std::map` mungkin sebenarnya lebih cepat.

Selain itu, kinerja _cache_ dari `std::map` (karena struktur pohonnya) kadang-kadang bisa lebih baik untuk pola akses tertentu pada data yang lebih kecil, terutama jika memori sangat terfragmentasi atau jika fungsi hash menyebabkan banyak kolisi. Ini berarti bahwa kinerja praktis tidak semata-mata ditentukan oleh kompleksitas asimtotik; faktor-faktor seperti ukuran dataset, faktor konstan, dan pola akses memori memainkan peran yang signifikan.

Berikut adalah tabel perbandingan untuk meringkas perbedaan utama antara `std::map` dan `std::unordered_map`:

| Fitur                              | `std::map`                                              | `std::unordered_map`                                                        |
| ---------------------------------- | ------------------------------------------------------- | --------------------------------------------------------------------------- |
| **Implementasi Internal**          | Pohon Biner Pencarian Seimbang (Red-Black Tree)         | Tabel Hash                                                                  |
| **Urutan Elemen**                  | Terurut berdasarkan kunci                               | Tidak terurut (berdasarkan hash)                                            |
| **Kompleksitas Waktu (Rata-rata)** | $O(log N)$                                              | $O(1)$                                                                      |
| **Kompleksitas Waktu (Terburuk)**  | $O(log N)$                                              | $O(N)$ (dengan kolisi buruk)                                                |
| **Memori**                         | Lebih tinggi per elemen (node overhead)                 | Lebih rendah per elemen (hashing), namun array bucket bisa besar            |
| **Stabilitas Iterator**            | Stabil setelah penyisipan (kecuali elemen yang dihapus) | Dapat menjadi tidak valid setelah penyisipan/penghapusan (jika _rehashing_) |
| **Kebutuhan Kunci**                | Perbandingan `<` (strict weak ordering)                 | Fungsi Hash dan `operator==`                                                |
| **Cache Locality**                 | Mungkin lebih buruk (node tersebar)                     | Mungkin lebih baik (contiguous buckets)                                     |

**Kapan Menggunakan yang Mana:**

- **Gunakan `std::unordered_map` ketika:**
    
    - Kecepatan pencarian, penyisipan, dan penghapusan adalah prioritas utama.
        
    - Urutan elemen tidak relevan atau tidak perlu dipertahankan.
        
    - Menangani dataset yang besar.
        
    - Contoh aplikasi: sistem _cache_, penghitungan frekuensi, tabel simbol.
    <br/>
- **Gunakan `std::map` ketika:**
    
    - Urutan elemen berdasarkan kunci harus dipertahankan.
        
    - Iterasi terurut diperlukan (misalnya, menampilkan data secara abjad atau numerik).
        
    - Kinerja kasus terburuk yang dapat diprediksi lebih penting (meskipun $O(\log N)$).
        
    - Anda tidak dapat menyediakan fungsi hash yang baik atau predikat kesetaraan yang konsisten untuk tipe kunci kustom.
        
    - Contoh aplikasi: peta yang memerlukan iterasi berdasarkan kunci abjad/numerik, atau sebagai struktur data yang mendasari untuk `std::set`.
        

## Kesimpulan

`std::unordered_map` adalah kontainer asosiatif berkinerja tinggi yang disediakan oleh Standard Template Library (STL) C++. Keunggulannya terletak pada kemampuannya untuk melakukan operasi kunci (pencarian, penyisipan, dan penghapusan) dengan kompleksitas waktu rata-rata $O(1)$. Efisiensi ini berasal dari implementasi internalnya sebagai tabel hash yang cerdas, dilengkapi dengan mekanisme resolusi konflik yang efektif, seperti _separate chaining_.

Namun, kinerja optimal dari `std::unordered_map` sangat bergantung pada kualitas fungsi hash yang digunakan. Untuk tipe data kustom, pengembang bertanggung jawab untuk menyediakan fungsi hash dan operator kesetaraan (`operator==`) yang dirancang dengan baik dan konsisten. Kegagalan dalam hal ini dapat menyebabkan penurunan kinerja yang signifikan atau bahkan perilaku tak terdefinisi. Selain itu, pemantauan dan manajemen faktor beban (`load_factor`) secara proaktif melalui fungsi seperti `reserve()` dan `rehash()` adalah praktik terbaik untuk memastikan kinerja yang konsisten dan dapat diprediksi dalam aplikasi yang sensitif terhadap latensi.

`std::unordered_map` sangat cocok untuk aplikasi di mana kecepatan pengambilan data adalah prioritas utama dan urutan elemen tidak relevan, seperti sistem _caching_, penghitungan frekuensi, atau _lookup_ cepat berdasarkan ID. Meskipun `std::map` menawarkan jaminan urutan dan kinerja kasus terburuk yang lebih dapat diprediksi ($O(\log N)$), _overhead_ pengurutan dan _cache locality_ yang berpotensi lebih buruk seringkali menjadikannya pilihan yang kurang efisien untuk sebagian besar skenario _key-value lookup_ umum.

Sebagai rekomendasi, `std::unordered_map` harus menjadi pilihan _default_ untuk kebutuhan _key-value lookup_ dalam pengembangan C++ modern. Namun, keputusan akhir harus selalu didasarkan pada analisis cermat terhadap persyaratan spesifik aplikasi, termasuk kebutuhan akan pengurutan, ukuran dataset, dan pentingnya kinerja kasus terburuk. Pemahaman mendalam tentang karakteristik dan _trade-off_ kedua kontainer ini sangat penting untuk merancang sistem yang efisien, responsif, dan kuat.