---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSMP-0003
nama_algoritma: 
kategori_algoritma: data structure
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
sumber: geeksforgeeks.org
date_learned: 2025-06-22T17:31:00
tags:
  - data-structure
  - map
---
---
# Memahami `std::map` di C++: Struktur Data Asosiatif yang Terurut dan Efisien

## 1. Pendahuluan: Apa itu `std::map`?

### Definisi dan Karakteristik Utama

`std::map` adalah salah satu kontainer asosiatif fundamental dalam Standard Template Library (STL) C++. Kontainer ini dirancang untuk menyimpan pasangan kunci-nilai (`key-value pairs`) di mana setiap kunci bersifat unik. Salah satu karakteristik paling menonjol dari `std::map` adalah kemampuannya untuk secara otomatis mengurutkan elemen-elemennya berdasarkan kuncinya. Secara default, pengurutan dilakukan dalam urutan menaik (ascending) menggunakan fungsi perbandingan `std::less<Key>`.

Kunci (`Key`) dan nilai (`T` atau `Mapped Type`) dalam `std::map` dapat berupa tipe data apa pun, mulai dari tipe data primitif seperti `int`, `string`, atau `float`, hingga tipe data buatan pengguna yang lebih kompleks. Setiap elemen dalam `std::map` disimpan sebagai `std::pair<const Key, T>`. Penunjukan `const` pada `Key` memiliki implikasi penting: setelah kunci disisipkan ke dalam `std::map`, nilai kunci tersebut tidak dapat dimodifikasi. Hanya nilai yang terkait (`Mapped Type`) yang dapat diubah. Properti ini memastikan integritas pengurutan internal `std::map`.1 Ketika melakukan iterasi melalui `std::map`, elemen-elemen akan selalu diakses dalam urutan kunci yang menaik, sesuai dengan kriteria perbandingan yang telah ditetapkan.

Untuk dapat menggunakan `std::map` dalam program C++, header `<map>` harus disertakan.

### Peran dalam Standard Template Library (STL) C++

Dalam ekosistem STL, `std::map` menempati posisi penting sebagai kontainer yang efisien untuk pencarian dan pengambilan data berdasarkan kunci. Berbeda dengan kontainer sekuensial seperti `std::vector` atau `std::list` yang memungkinkan akses elemen berdasarkan indeks numerik, `std::map` beroperasi murni berdasarkan nilai kuncinya. Ini menjadikannya pilihan yang ideal untuk skenario di mana data perlu diorganisir dan diakses dengan cepat melalui identifikasi unik.

### Implikasi Kunci `const` dan Pengurutan Otomatis

Properti kunci `const` dalam `std::map` bukan sekadar detail teknis, melainkan sebuah batasan desain fundamental yang secara langsung mendukung jaminan `std::map` untuk menjaga kunci tetap unik dan terurut. Struktur internal `std::map` bergantung pada urutan kunci untuk menjaga keseimbangan dan efisiensi operasinya. Jika kunci dapat dimodifikasi secara langsung setelah penyisipan, urutan yang dipertahankan oleh struktur data internal akan terganggu, yang akan merusak properti dan jaminan kinerja `std::map`. Oleh karena itu, jika sebuah "kunci" perlu diubah secara logis, operasi yang benar secara semantik adalah menghapus elemen lama dengan kunci yang tidak lagi relevan dan kemudian menyisipkan elemen baru dengan kunci yang dimodifikasi. Pendekatan ini memastikan bahwa `std::map` selalu mematuhi prinsip-prinsip pengurutan dan keunikan kuncinya, menjaga integritas strukturalnya.

## 2. Implementasi Internal: Pohon Merah-Hitam (`Red-Black Tree`)

### Penjelasan Mengapa `std::map` Diimplementasikan Menggunakan Red-Black Tree

`std::map` umumnya diimplementasikan sebagai Pohon Merah-Hitam (Red-Black Tree). Pohon Merah-Hitam adalah jenis pohon pencarian biner yang menyeimbangkan diri (`self-balancing binary search tree`). Pilihan implementasi ini sangat strategis karena memastikan bahwa pohon tetap seimbang secara otomatis selama operasi penyisipan dan penghapusan elemen. Keseimbangan ini krusial untuk mencegah skenario terburuk di mana pohon dapat merosot menjadi struktur linear yang menyerupai daftar tertaut, yang akan mengakibatkan penurunan kinerja yang drastis menjadi $O(n)$. Red-Black Tree secara khusus dirancang untuk mempertahankan keseimbangan perkiraan, di mana jalur terpanjang dari root ke leaf tidak akan pernah lebih dari dua kali panjang jalur terpendek.

### Dampak pada Kompleksitas Waktu (`Time Complexity`)

Sifat seimbang yang melekat pada Red-Black Tree secara langsung menjamin kompleksitas waktu logaritmik $(O(\log n)$) untuk semua operasi kunci `std::map`, termasuk pencarian (`find`), penyisipan (`insert`), dan penghapusan (`erase`). Kompleksitas $O(\log n)$ ini adalah faktor yang sangat penting untuk menjaga kinerja yang tinggi, terutama ketika berhadapan dengan dataset yang besar. Ini berarti bahwa waktu yang dibutuhkan untuk melakukan operasi hanya akan tumbuh secara bertahap dan sangat lambat seiring dengan peningkatan jumlah elemen dalam `std::map`, menjadikannya sangat skalabel.

### Keuntungan dari Struktur yang Seimbang dan Kinerja yang Konsisten

Red-Black Tree menawarkan beberapa keuntungan signifikan yang menjadikannya pilihan ideal untuk implementasi `std::map` dalam STL:

- **Kinerja Konsisten:** Pohon Merah-Hitam memberikan jaminan kinerja yang konsisten dan dapat diprediksi. Kompleksitas waktu kasus terburuk untuk penyisipan, penghapusan, dan pencarian tetap $O(\log n)$. Hal ini berbeda dengan beberapa struktur pohon penyeimbang diri lainnya, seperti pohon AVL, yang mungkin memiliki biaya penyeimbangan ulang yang lebih tinggi dan kurang dapat diprediksi dalam skenario tertentu.
<br/>

- **Kesederhanaan dan Efisiensi Implementasi:** Dibandingkan dengan pohon pencarian biner penyeimbang diri lainnya seperti pohon AVL, Red-Black Tree umumnya membutuhkan lebih sedikit rotasi untuk menjaga keseimbangan. Aturan penyeimbangan yang lebih sederhana ini membuat Red-Black Tree lebih mudah dan lebih efisien untuk diimplementasikan, yang merupakan keuntungan besar untuk komponen pustaka standar yang harus andal dan efisien.
<br/>

- **Fleksibilitas:** Standard Template Library (STL) dirancang untuk tujuan umum, yang berarti kontainernya harus berfungsi dengan baik di berbagai aplikasi tanpa memerlukan konfigurasi atau penyetelan yang rumit. Red-Black Tree "bekerja begitu saja" dan berskala dengan baik di berbagai kasus penggunaan tanpa memerlukan penyetelan khusus. Ini sangat kontras dengan tabel hash (yang digunakan oleh `std: :unordered_map`), yang seringkali membutuhkan pemahaman mendalam tentang data dan fungsi hash untuk mencapai kinerja optimal. Red-Black Tree menyediakan struktur yang seimbang yang memastikan kinerja yang konsisten di berbagai kasus penggunaan, menjadikannya pilihan default yang fleksibel dan andal.
<br/>

### Trade-off Desain dan Fleksibilitas STL

Pemilihan Red-Black Tree sebagai dasar `std::map` mencerminkan filosofi desain STL untuk menyediakan kontainer yang andal dengan jaminan kinerja yang kuat dan konsisten ($O(\log n)$) di berbagai skenario, tanpa memerlukan konfigurasi atau penyetelan yang rumit dari pengembang. Filosofi ini mengutamakan prediktabilitas dan keandalan. Hal ini kontras langsung dengan `std::unordered_map`, yang menggunakan tabel hash. Meskipun `std::unordered_map` dapat menawarkan kinerja rata-rata $O(1)$ yang lebih cepat untuk operasi kunci, ia memiliki potensi kasus terburuk $O(n)$ jika terjadi banyak kolisi hash, dan seringkali memerlukan pemahaman yang lebih dalam tentang fungsi hash dan distribusi data untuk mencapai kinerja optimal. Oleh karena itu, `std::map` adalah pilihan yang "aman" dan "fleksibel" yang bekerja dengan baik secara default di banyak aplikasi, terutama ketika urutan data penting dan jaminan kinerja yang konsisten lebih diutamakan daripada kecepatan rata-rata absolut.

## 3. Kegunaan dan Aplikasi `std::map`

### Skenario Penggunaan Ideal untuk `std::map`

`std::map` adalah pilihan struktur data yang sangat baik dalam beberapa skenario penggunaan:

- **Pengurutan Data:** Ketika data perlu disimpan dalam urutan tertentu, seperti abjad, numerik, atau kronologis, dan akses terurut diperlukan. `std::map` secara otomatis menjaga urutan ini.
<br/>

- **Keunikan Kunci:** Ketika keunikan kunci adalah persyaratan mutlak, `std::map` secara inheren mencegah duplikasi kunci.
<br/>

- **Efisiensi Operasi Konsisten:** Ketika pencarian, penyisipan, dan penghapusan elemen harus efisien ($O(\log n)$) dan konsisten, bahkan untuk dataset besar. Jaminan kinerja logaritmik ini sangat berharga dalam aplikasi yang sensitif terhadap waktu.
<br/>

- **Akses Pendahulu/Penerus:** Ketika ada kebutuhan untuk secara efisien mengakses elemen yang mendahului atau mengikuti elemen tertentu dalam urutan terurut.
- <br/>
### Contoh Kasus Nyata

`std::map` memiliki berbagai aplikasi praktis di dunia nyata, berkat karakteristiknya yang unik:

- **Sistem Log Versi Perangkat Lunak:** Dalam pengelolaan changelog untuk rilis perangkat lunak, di mana setiap rilis diidentifikasi oleh string versi unik (misalnya, "1.2.3") dan dikaitkan dengan tanggal serta deskripsinya. Menggunakan `std::map<std::string, VersionDetails>` memungkinkan pengambilan detail versi secara instan dan menjaga versi tetap terurut secara leksikografis, yang sangat efisien dibandingkan pencarian linear pada struktur lain.
<br/>

- **Penghitung Frekuensi (misalnya, Kata dalam Teks):** Untuk memproses teks besar dan menghitung berapa kali setiap kata muncul. `std::map<std::string, int>` (misalnya, `wordCount`) memungkinkan iterasi melalui setiap kata, menambah hitungannya (`wordCount[word]++`), dan secara otomatis mengurutkan kata-kata berdasarkan kuncinya. Ini ideal untuk analisis data tekstual, di mana kata-kata dapat dengan mudah dicetak dalam urutan abjad.
<br/>

- **Manajemen Pengaturan Konfigurasi:** Memuat dan mengelola parameter dari file konfigurasi, di mana nama pengaturan (misalnya, "port", "timeout", "mode") dipetakan ke nilai-nilai terkait. `std::map<std::string, std::string>` memungkinkan akses mudah dan aman ke pengaturan ini, dengan metode seperti `.count()` atau `.find()` untuk memeriksa keberadaan pengaturan.
<br/>

- **Kompresi Data menggunakan Kamus:** `std::map` dapat digunakan untuk mengasosiasikan istilah-istilah panjang dengan kode-kode pendek dalam kamus untuk tujuan kompresi data, memanfaatkan kemampuan pencarian cepatnya.
<br/>

- **Fungsi Memoized:** Untuk mengoptimalkan fungsi rekursif atau komputasi intensif lainnya dengan menyimpan hasil panggilan fungsi sebelumnya. `std::map` dapat memetakan argumen fungsi ke hasil yang dihitung, sehingga menghindari komputasi ulang yang mahal.
v

### Perbandingan `std::map` dengan `std::unordered_map` dan `std::vector`

Pemilihan kontainer STL yang tepat sangat krusial untuk kinerja aplikasi. `std::map` sering dibandingkan dengan `std::unordered_map` dan `std::vector` karena kesamaan fungsionalitasnya dalam menyimpan dan mengakses data.

#### Tabel Perbandingan Kontainer Asosiatif (Map vs. Unordered Map)

| Fitur                              | `std::map`                                                              | `std::unordered_map`                                                    |
| ---------------------------------- | ----------------------------------------------------------------------- | ----------------------------------------------------------------------- |
| **Urutan Elemen**                  | Terurut berdasarkan kunci (ascending default)                           | Tidak ada urutan spesifik (berdasarkan hash value)                      |
| **Implementasi**                   | Red-Black Tree (Self-Balancing BST)                                     | Hash Table                                                              |
| **Kompleksitas Waktu (Rata-rata)** | $O(\log n)$ untuk insert, find, erase                                   | $O(1)$ untuk insert, find, erase                                        |
| **Kompleksitas Waktu (Terburuk)**  | $O(\log n)$ untuk insert, find, erase                                   | $O(n)$ untuk insert, find, erase (kolisi)                               |
| **Penggunaan Memori**              | Cenderung lebih tinggi dari `unordered_map` (overhead node pohon)       | Cenderung lebih rendah dari `map` (overhead hash table bisa bervariasi) |
| **Kasus Penggunaan Ideal**         | Butuh data terurut, akses pendahulu/penerus, jaminan kinerja konsisten  | Butuh akses cepat ($O(1)$ rata-rata), urutan tidak penting              |
| **Kustomisasi**                    | Membutuhkan komparator kustom (`operator<`) untuk tipe data non-standar | Membutuhkan fungsi hash kustom untuk tipe data non-standar              |
| (Sumber: 9)                        |                                                                         |                                                                         |

#### Perbandingan dengan `std::vector`

`std::vector` adalah kontainer sekuensial yang berfungsi sebagai array dinamis. Secara default, `std::vector` dapat berisi elemen duplikat dan tidak menjaga urutan tertentu. Operasi penyisipan di akhir `std::vector` memiliki kompleksitas waktu $O(1)$ amortisasi, namun penyisipan atau penghapusan di tengah kontainer memerlukan pergeseran elemen dan memiliki kompleksitas $O(n).$

Pencarian elemen dalam `std::vector` secara default adalah pencarian linear dengan kompleksitas $O(n)$.

Meskipun `std::vector` dapat diurutkan (misalnya, menggunakan `std: :sort`), yang memungkinkan pencarian biner (seperti `std: :lower_bound` atau `std: :binary_search`) dengan kompleksitas $O(\log n)$, operasi penyisipan dan penghapusan tetap memiliki kompleksitas $O(n)$ karena elemen-elemen harus digeser untuk mempertahankan urutan.  

Dalam hal penggunaan memori, `std::map` umumnya menggunakan lebih banyak memori daripada `std::vector` untuk jumlah elemen yang sama, karena overhead yang terkait dengan node pohon (pointer, warna node, dll.).

#### Beyond Big O - Lokalitas Cache dan Praktikalitas

Meskipun `std::map` menawarkan jaminan kompleksitas waktu $O(\log n)$ yang superior secara teoritis untuk operasi kunci dibandingkan dengan `std::vector` yang diurutkan (yang memiliki $O(n)$ untuk penyisipan dan penghapusan), kinerja dunia nyata dapat sangat dipengaruhi oleh faktor-faktor non-asymptotik seperti konstanta tersembunyi dan lokalitas cache. `std::vector` menyimpan elemen secara berdekatan di memori (contiguous memory), yang memungkinkan CPU untuk memanfaatkan cache dengan lebih baik. Ini berarti bahwa untuk kumpulan data yang lebih kecil atau skenario di mana elemen sering diakses secara berurutan, `std::vector` seringkali mengungguli `std::map` karena data yang disimpan secara berdekatan memanfaatkan cache CPU dengan lebih efisien.

Sebaliknya, `std::map`, karena implementasi berbasis pohonnya, melibatkan "pointer chasing" (melompat-lompat di memori melalui pointer), yang dapat menyebabkan lebih banyak _cache miss_. Ini mengurangi keuntungan teoritis $O(\log n)$ dalam kasus-kasus tertentu. Oleh karena itu, penting untuk tidak hanya mengandalkan notasi Big O, tetapi juga mempertimbangkan karakteristik akses data dan ukuran dataset. 

Seperti yang disarankan oleh Bjarne Stroustrup, "Jangan gunakan `map` kecuali Anda tahu itu lebih cepat. Gunakan saja `vector`," yang menekankan pentingnya melakukan _benchmarking_ untuk kasus penggunaan spesifik Anda sebelum membuat keputusan akhir tentang pemilihan kontainer.

`std::map` unggul ketika ada banyak operasi penyisipan dan penghapusan yang diselingi dengan pencarian, karena mempertahankan kinerja $O(\log n)$ secara konsisten di seluruh operasi.

## 4. Fungsi Anggota (`Member Functions`) `std::map`

`std::map` menyediakan serangkaian fungsi anggota yang kaya untuk mengelola elemen-elemennya secara efisien. Fungsi-fungsi ini dikategorikan berdasarkan tujuan fungsionalnya.

### Konstruktor dan Operator Penugasan

`std::map` menawarkan berbagai konstruktor untuk inisialisasi, termasuk konstruktor default, konstruktor yang mengambil rentang iterator, konstruktor salin (copy constructor), konstruktor pindah (move constructor), dan konstruktor yang menerima `std::initializer_list`.

Selain itu, `operator=` disediakan untuk operasi penugasan, yang memungkinkan penyalinan atau pemindahan konten dari satu `std::map` ke `std::map` lainnya, atau inisialisasi dari `std::initializer_list`. Perilakum `operator=` dapat menjadi kompleks, terutama dalam konteks alokator dan semantik pemindahan di C++ modern. Memahami bagaimana alokator berinteraksi selama operasi penugasan sangat penting untuk manajemen sumber daya dan kinerja yang optimal, karena dapat memengaruhi apakah data disalin atau dipindahkan secara efisien.
### Akses Elemen

Untuk mengakses elemen berdasarkan kuncinya, `std::map` menyediakan dua metode utama:

- `at(key)`: Fungsi ini mengakses elemen yang ditentukan dengan pemeriksaan batas. Jika kunci yang diberikan tidak ditemukan dalam `std::map`, fungsi ini akan melemparkan pengecualian `std::out_of_range`. Ini menjadikannya pilihan yang lebih aman ketika ketidakpastian keberadaan kunci dapat menyebabkan masalah.
<br/>

- `operator[key]`: Operator ini juga mengakses elemen yang ditentukan. Namun, jika kunci tidak ada, ia akan secara implisit menyisipkan elemen baru ke dalam `std::map` dengan kunci tersebut dan nilai default yang dibangun untuk tipe nilai (`Mapped Type`), lalu mengembalikan referensi ke nilai tersebut. Perbedaan perilaku ini sangat penting untuk keamanan kode. Penggunaan `operator` dapat secara tidak sengaja menyisipkan elemen baru, yang mungkin tidak diinginkan dan dapat menyembunyikan bug logis jika pengembang hanya berniat untuk mengakses elemen yang sudah ada.
<br/>
### Iterator

`std::map` menyediakan berbagai iterator untuk traversal elemen:

- `begin()`, `end()`: `begin()` mengembalikan iterator ke elemen pertama dalam map (yaitu, elemen dengan kunci terkecil), sedangkan `end()` mengembalikan iterator ke posisi teoretis setelah elemen terakhir. Iterasi menggunakan `begin()` dan `end()` akan selalu menghasilkan elemen dalam urutan kunci yang menaik.
<br/>

- `rbegin()`, `rend()`: Fungsi-fungsi ini mengembalikan iterator terbalik, memungkinkan iterasi melalui map dalam urutan kunci yang menurun.
<br/>

- `cbegin()`, `cend()`, `crbegin()`, `crend()` (sejak C++11): Ini adalah versi `const` dari iterator standar dan terbalik. Mereka mengembalikan iterator konstan, yang berarti elemen-elemen tidak dapat dimodifikasi melalui iterator ini selama iterasi. `std::map` menyediakan iterator bidireksional 11, yang mendukung traversal maju dan mundur, memberikan fleksibilitas dalam memproses data terurut dan mendukung operasi berbasis rentang.
<br/>
### Kapasitas

Fungsi-fungsi ini memberikan informasi tentang ukuran dan status `std::map`:

- `empty()`: Memeriksa apakah kontainer tidak mengandung elemen apa pun. Mengembalikan `true` jika map kosong, `false` sebaliknya.
<br/>

- `size()`: Mengembalikan jumlah elemen (pasangan kunci-nilai) yang saat ini disimpan dalam map.
<br/>

- `max_size()`: Mengembalikan jumlah maksimum elemen yang mungkin dapat ditampung oleh map, yang biasanya bergantung pada kapasitas memori sistem.
    

### Modifikasi

`std::map` menyediakan berbagai fungsi untuk memodifikasi isinya:

- `insert()`: Fungsi ini menyisipkan elemen atau node baru ke dalam map. Terdapat berbagai overload yang memungkinkan penyisipan pasangan kunci-nilai tunggal, rentang elemen, atau penggunaan hint iterator untuk mengoptimalkan kinerja penyisipan jika posisi perkiraan diketahui.
<br/>

- `emplace()` (sejak C++11): Membangun elemen baru di tempat (`in-place`) di dalam map, menghindari salinan sementara yang tidak perlu. Ini dapat meningkatkan efisiensi untuk tipe data yang kompleks.
<br/>

- `emplace_hint()` (sejak C++11): Mirip dengan `emplace()`, tetapi juga menerima hint iterator untuk membantu map menemukan lokasi penyisipan yang optimal, berpotensi meningkatkan kinerja.
<br/>

- `insert_or_assign()` (sejak C++17): Menyisipkan elemen jika kunci tidak ada, atau menugaskan nilai baru ke elemen yang ada jika kunci sudah ada.
<br/>

- `try_emplace()` (sejak C++17): Menyisipkan elemen di tempat jika kunci tidak ada. Jika kunci sudah ada, fungsi ini tidak melakukan apa-apa dan tidak memodifikasi nilai yang ada.
<br/>

- `erase()`: Fungsi ini menghapus elemen dari map. Dapat digunakan untuk menghapus elemen berdasarkan kunci, berdasarkan iterator yang menunjuk ke elemen, atau untuk menghapus rentang elemen yang ditentukan oleh dua iterator.
    
    - Menghapus berdasarkan kunci memiliki kompleksitas $O(\log n)$ dan mengembalikan jumlah elemen yang dihapus (0 atau 1).
    <br/>
    
    - Menghapus berdasarkan iterator memiliki kompleksitas $O(1)$ dan mengembalikan iterator ke elemen berikutnya.
    <br/>
    
    - Menghapus berdasarkan rentang memiliki kompleksitas $O(k + \log n)$, di mana `k` adalah jumlah elemen yang dihapus.
    <br/>

- `clear()`: Menghapus semua elemen dari map, menyebabkan ukurannya menjadi nol dan membebaskan memori yang dialokasikan.
<br/>

- `swap()`: Menukar konten dua `std::map` dengan tipe yang sama secara efisien, biasanya dalam waktu konstan.
<br/>

- `extract()` (sejak C++17): Mengekstrak node (elemen) dari kontainer tanpa menghancurkannya, memungkinkan transfer kepemilikan node tanpa alokasi atau dealokasi memori.
<br/>

- `merge()` (sejak C++17): Menggabungkan node dari kontainer asosiatif lain (misalnya `std: :map` atau `std: :set`) ke dalam map saat ini. Ini adalah operasi yang efisien karena node dipindahkan, bukan disalin.
<br/>

Penambahan fungsi-fungsi seperti `emplace`, `insert_or_assign`, `try_emplace`, `extract`, dan `merge` dalam standar C++ yang lebih baru (C++11, C++17) menunjukkan evolusi `std::map` menuju efisiensi yang lebih besar dan kontrol yang lebih granular atas alokasi memori dan manipulasi elemen. Fungsi-fungsi ini dirancang untuk mengurangi salinan yang tidak perlu, memungkinkan konstruksi di tempat, dan memfasilitasi operasi yang lebih kompleks seperti penggabungan map secara efisien, yang semuanya krusial untuk pengembangan aplikasi C++ berkinerja tinggi.

### Pencarian (`Lookup`)

Fungsi-fungsi pencarian memungkinkan pengguna untuk menemukan elemen atau rentang elemen berdasarkan kunci:

- `count(key)`: Mengembalikan jumlah elemen yang cocok dengan kunci tertentu. Karena `std::map` hanya menyimpan kunci unik, fungsi ini akan selalu mengembalikan 0 (jika kunci tidak ditemukan) atau 1 (jika kunci ditemukan).
<br/>

- `find(key)`: Mencari elemen dengan kunci tertentu. Jika elemen ditemukan, fungsi ini mengembalikan iterator yang menunjuk ke elemen tersebut; jika tidak, ia mengembalikan iterator ke `end()`.
<br/>

- `contains(key)` (sejak C++20): Fungsi ini memeriksa apakah kontainer berisi elemen dengan kunci tertentu. Ini adalah cara yang lebih ringkas dan seringkali lebih jelas daripada `find()!= end()` hanya untuk memeriksa keberadaan elemen.
<br/>

- `lower_bound(key)`: Mengembalikan iterator ke elemen pertama yang _tidak kurang dari_ kunci yang diberikan. Ini berarti elemen tersebut mungkin sama dengan kunci atau lebih besar dari kunci.
<br/>

- `upper_bound(key)`: Mengembalikan iterator ke elemen pertama yang _lebih besar dari_ kunci yang diberikan.
<br/>

- `equal_range(key)`: Mengembalikan `std::pair` dari dua iterator yang mendefinisikan rentang elemen yang cocok dengan kunci tertentu. Iterator pertama adalah hasil dari `lower_bound()` dan yang kedua adalah hasil dari `upper_bound()` untuk kunci yang sama.
<br/>

Keberadaan fungsi-fungsi seperti `lower_bound()`, `upper_bound()`, dan `equal_range()` adalah bukti nyata dari kekuatan `std::map` sebagai kontainer yang terurut. Fungsi-fungsi ini memungkinkan pencarian yang canggih berdasarkan rentang dan posisi relatif dalam urutan terurut, yang tidak mungkin dilakukan secara efisien dengan kontainer tidak terurut seperti `std::unordered_map`. Ini menjadikan `std::map` pilihan yang tak tergantikan untuk aplikasi yang memerlukan navigasi data berdasarkan urutan kunci, bukan hanya pencarian keberadaan.

### Pengamat (`Observers`)

Fungsi pengamat menyediakan akses ke objek perbandingan yang digunakan oleh map:

- `key_comp()`: Mengembalikan objek fungsi yang digunakan untuk membandingkan kunci (biasanya `std: :less<Key>` secara default).
<br/>

- `value_comp()`: Mengembalikan objek fungsi yang digunakan untuk membandingkan kunci dalam objek `value_type` (pasangan kunci-nilai). Ini berguna jika perbandingan perlu dilakukan pada seluruh pasangan, bukan hanya kunci.

#### Tabel Fungsi Anggota `std::map` (Ringkasan)

| Kategori Fungsi  | Fungsi Anggota                  | Deskripsi                                                       | Kompleksitas Waktu (Rata-rata)           |
| ---------------- | ------------------------------- | --------------------------------------------------------------- | ---------------------------------------- |
| **Konstruktor**  | `map()`                         | Membuat map kosong.                                             | O(1)                                     |
|                  | `map(first, last)`              | Membuat map dari rentang iterator.                              | O(N log N)                               |
| **Akses Elemen** | `at(key)`                       | Mengakses nilai berdasarkan kunci, dengan pemeriksaan batas.    | O(log N)                                 |
|                  | `operator(key)`                 | Mengakses atau menyisipkan nilai berdasarkan kunci.             | O(log N)                                 |
| **Iterator**     | `begin()`, `cbegin()`           | Mengembalikan iterator ke elemen pertama.                       | O(1)                                     |
|                  | `end()`, `cend()`               | Mengembalikan iterator ke elemen setelah yang terakhir.         | O(1)                                     |
|                  | `rbegin()`, `crbegin()`         | Mengembalikan iterator terbalik ke elemen terakhir.             | O(1)                                     |
|                  | `rend()`, `crend()`             | Mengembalikan iterator terbalik ke elemen sebelum yang pertama. | O(1)                                     |
| **Kapasitas**    | `empty()`                       | Memeriksa apakah map kosong.                                    | O(1)                                     |
|                  | `size()`                        | Mengembalikan jumlah elemen dalam map.                          | O(1)                                     |
|                  | `max_size()`                    | Mengembalikan jumlah maksimum elemen yang dapat ditampung.      | O(1)                                     |
| **Modifikasi**   | `insert(pair)`                  | Menyisipkan pasangan kunci-nilai.                               | O(log N)                                 |
|                  | `emplace(args...)`              | Membangun elemen di tempat.                                     | O(log N)                                 |
|                  | `erase(key)`                    | Menghapus elemen berdasarkan kunci.                             | O(log N)                                 |
|                  | `erase(iterator)`               | Menghapus elemen pada posisi iterator.                          | O(1)                                     |
|                  | `erase(first, last)`            | Menghapus rentang elemen.                                       | O(k + log N) (k = jumlah elemen dihapus) |
|                  | `clear()`                       | Menghapus semua elemen.                                         | O(N)                                     |
|                  | `swap(other_map)`               | Menukar konten dengan map lain.                                 | O(1)                                     |
|                  | `extract(key/iterator)` (C++17) | Mengekstrak node dari map.                                      | O(log N) / O(1)                          |
|                  | `merge(other_map)` (C++17)      | Menggabungkan node dari map lain.                               | O(N log N)                               |
| **Pencarian**    | `count(key)`                    | Mengembalikan 1 jika kunci ada, 0 jika tidak.                   | O(log N)                                 |
|                  | `find(key)`                     | Mencari elemen berdasarkan kunci, mengembalikan iterator.       | O(log N)                                 |
|                  | `contains(key)` (C++20)         | Memeriksa keberadaan kunci.                                     | O(log N)                                 |
|                  | `lower_bound(key)`              | Iterator ke elemen pertama yang tidak kurang dari kunci.        | O(log N)                                 |
|                  | `upper_bound(key)`              | Iterator ke elemen pertama yang lebih besar dari kunci.         | O(log N)                                 |
|                  | `equal_range(key)`              | Mengembalikan pasangan iterator untuk rentang kunci.            | O(log N)                                 |
| **Pengamat**     | `key_comp()`                    | Mengembalikan objek perbandingan kunci.                         | O(1)                                     |
|                  | `value_comp()`                  | Mengembalikan objek perbandingan nilai.                         | O(1)                                     |


### Kustomisasi Perbandingan Kunci (`Custom Comparators`)

Untuk tipe data buatan pengguna atau ketika urutan pengurutan default (menaik) tidak diinginkan, `std::map` memungkinkan penggunaan komparator kustom. Secara default, `std::map` menggunakan `std::less<Key>` untuk menentukan urutan elemen. Namun, untuk tipe data buatan pengguna, atau untuk mengimplementasikan pengurutan yang berbeda (misalnya, urutan menurun atau logika perbandingan yang kompleks untuk struktur), komparator kustom harus disediakan.

Komparator kustom paling umum diimplementasikan sebagai `struct` dengan `operator()` yang di-overload. `operator()` ini harus mengambil dua argumen `const` referensi dari tipe kunci dan mengembalikan `bool`. Nilai `bool` yang dikembalikan harus menunjukkan apakah argumen pertama "kurang dari" argumen kedua sesuai dengan urutan kustom yang diinginkan.1 Penting bahwa fungsi perbandingan ini memenuhi persyaratan _strict weak ordering_ untuk memastikan perilaku map yang benar dan konsisten.

Sintaks untuk mendeklarasikan `std::map` dengan komparator kustom adalah `std::map<Key, Value, CustomCompare>`, di mana `CustomCompare` adalah nama `struct` komparator Anda. Sebagai alternatif, `operator<` dapat di-overload langsung untuk tipe data kustom. Namun, functor (objek fungsi) umumnya lebih disukai karena fleksibilitasnya; mereka dapat menyimpan status, mengemas logika perbandingan yang kompleks, dan memberikan pemisahan yang bersih antara definisi kelas dan aturan perbandingannya.

## 5. Kesimpulan

`std::map` di C++ adalah struktur data asosiatif yang kuat dan serbaguna, dirancang untuk mengelola pasangan kunci-nilai unik dalam urutan yang terurut. Implementasinya yang mendasari sebagai Pohon Merah-Hitam memastikan jaminan kinerja logaritmik ($O(\log n)$) yang konsisten untuk operasi kunci seperti penyisipan, pencarian, dan penghapusan, menjadikannya pilihan yang sangat skalabel untuk dataset besar.

Kekuatan utama `std::map` terletak pada kemampuannya untuk mempertahankan urutan elemen secara otomatis berdasarkan kunci, yang memfasilitasi iterasi terurut dan pencarian berbasis rentang yang canggih melalui fungsi-fungsi seperti `lower_bound`, `upper_bound`, dan `equal_range`. Properti kunci `const` adalah batasan desain yang secara fundamental mendukung integritas pengurutan dan keunikan kunci.

Meskipun `std::map` menawarkan jaminan kinerja yang kuat, penting untuk memahami trade-off-nya dibandingkan dengan kontainer lain. `std::unordered_map` mungkin menawarkan kinerja rata-rata $O(1)$ yang lebih cepat ketika urutan tidak relevan, sementara `std::vector` dapat mengungguli `std::map` untuk kumpulan data yang lebih kecil atau pola akses sekuensial karena lokalitas cache yang lebih baik, meskipun dengan kompleksitas yang lebih tinggi untuk penyisipan/penghapusan di tengah.

Pemilihan `std::map` yang tepat bergantung pada kebutuhan spesifik aplikasi. `std::map` adalah pilihan yang sangat baik ketika:

- Urutan data berdasarkan kunci adalah persyaratan penting.
    
- Keunikan kunci harus dijamin.
    
- Pencarian, penyisipan, dan penghapusan memerlukan jaminan kinerja yang konsisten dan dapat diprediksi ($O(\log n)$) terlepas dari distribusi data.
    
- Akses ke elemen pendahulu atau penerus diperlukan.
    

Dengan memahami karakteristik, implementasi, fungsi anggota, dan perbandingannya dengan kontainer STL lainnya, pengembang dapat secara efektif memanfaatkan `std::map` untuk membangun aplikasi C++ yang efisien dan andal.