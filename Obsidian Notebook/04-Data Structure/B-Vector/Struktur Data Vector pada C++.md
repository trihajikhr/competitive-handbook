---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSVC-0002
nama_algoritma:
kategori_algoritma: data structure
kesulitan: 🥉 easy
time_complexity:
memory_complexity:
sumber:
  - programiz.com
  - Gemini AI
date_learned: 2025-06-13T12:39:00
tags:
  - data-structure
  - vector
---
---
# Laporan Komprehensif: Struktur Data `std::vector` pada C++

## 1 | Pengantar `std::vector`

`std::vector` adalah salah satu struktur data paling fundamental dan sering digunakan dalam Standard Template Library (STL) C++. Ini menawarkan kombinasi unik antara efisiensi array tradisional dan fleksibilitas struktur data dinamis, menjadikannya pilihan yang sangat serbaguna untuk berbagai aplikasi pemrograman.

### 1.1 | Definisi dan Konsep Dasar

`std::vector` dapat dipahami sebagai implementasi dari konsep _array dinamis_ pada C++. Ini berarti, tidak seperti array C-style yang ukurannya harus ditentukan pada waktu kompilasi dan bersifat tetap sepanjang siklus hidupnya , `std::vector` memiliki kemampuan untuk mengubah ukurannya secara otomatis (resize) saat elemen dimasukkan atau dihapus. Kemampuan ini memberikan fleksibilitas yang jauh lebih besar dalam pengelolaan data yang ukurannya tidak diketahui saat kompilasi atau yang berubah selama runtime.

Elemen-elemen dalam `std::vector` disimpan dalam _lokasi memori yang berurutan (contiguous memory locations)_. Properti ini sangat penting karena memungkinkan akses elemen yang sangat cepat (random access) menggunakan indeks, mirip dengan array C-style. Penyimpanan yang berurutan juga menguntungkan untuk efisiensi cache CPU, yang berkontribusi pada kinerja tinggi, terutama saat mengakses elemen secara berurutan.

`std::vector` didefinisikan sebagai _template kelas_ `std::vector<T>` dalam file header `<vector>`. `T` adalah parameter template yang menentukan tipe data elemen yang akan disimpan dalam vektor. Desain berbasis template ini memungkinkan `std::vector` untuk menyimpan elemen dari berbagai tipe data, mulai dari tipe primitif seperti `int` atau `char` hingga objek kompleks yang ditentukan pengguna, menjadikannya sangat serbaguna dan dapat digunakan kembali.

Penggunaan `std::vector` menunjukkan bagaimana struktur data modern di C++ berupaya menggabungkan keunggulan dari berbagai pendekatan. Array C-style secara inheren menawarkan akses yang sangat cepat karena sifat memorinya yang berurutan. `std::vector` berhasil mempertahankan kecepatan akses ini karena ia juga menjamin penyimpanan elemen yang berurutan. Namun, di mana array C-style terikat pada ukuran tetap, `std::vector` melampaui batasan ini dengan memperkenalkan kemampuan perubahan ukuran dinamis. Ini berarti pengembang dapat memanfaatkan kinerja akses cepat yang diwarisi dari array sambil mendapatkan fleksibilitas untuk menangani kumpulan data yang ukurannya bervariasi tanpa perlu mengelola alokasi memori secara manual. 

Ini merupakan peningkatan arsitektur yang signifikan, yang memungkinkan pengembang untuk mendapatkan yang terbaik dari kedua dunia untuk banyak kasus penggunaan umum, menghindari jebakan manajemen memori manual dan batasan ukuran tetap dari array mentah, tanpa penalti kinerja yang signifikan untuk akses.

### 1.2 | Mengapa Menggunakan `std::vector` dibandingkan Array C-style dan `std::array`

Pemilihan struktur data yang tepat adalah keputusan krusial dalam pengembangan perangkat lunak. `std::vector` menawarkan sejumlah keunggulan signifikan dibandingkan array C-style tradisional dan bahkan `std::array` (yang merupakan wrapper C++ untuk array berukuran tetap).

- **Manajemen Memori Otomatis:** Salah satu keunggulan terbesar `std::vector` adalah kemampuannya untuk secara otomatis menangani alokasi dan dealokasi memori di _heap_. Ini menghilangkan kebutuhan pengembang untuk secara manual menggunakan operator `new` dan `delete`, yang secara signifikan mengurangi risiko kebocoran memori (`memory leaks`) dan kesalahan terkait memori lainnya yang umum terjadi pada array C-style.
<br/>

- **Ukuran Dinamis:** Keunggulan utama `std::vector` adalah kemampuannya untuk mengubah ukurannya saat runtime. Ini sangat kontras dengan array C-style dan `std::array` yang ukurannya harus ditentukan pada waktu kompilasi dan tidak dapat diubah. Fleksibilitas ini memungkinkan `std::vector` untuk tumbuh atau menyusut sesuai kebutuhan data, mengakomodasi jumlah data yang bervariasi tanpa manajemen memori manual.
<br/>

- **Kesadaran Ukuran (Size Awareness):** Tidak seperti array C-style yang tidak menyimpan informasi ukurannya saat runtime dan dapat mengalami "array decay" saat dilewatkan ke fungsi , `std::vector` memiliki fungsi anggota `size()` yang selalu mengembalikan jumlah elemen saat ini. Fitur bawaan ini menyederhanakan operasi dan mencegah kesalahan umum terkait batas array.
<br/>

- **Pemeriksaan Batas (Bounds Checking):** `std::vector` menawarkan dua cara untuk mengakses elemen: `operator[]` (tanpa pemeriksaan batas yang lebih cepat) dan metode `at()` (dengan pemeriksaan batas, yang akan melempar `std: :out_of_range` exception jika indeks tidak valid). Array C-style tidak memiliki pemeriksaan batas bawaan, yang dapat menyebabkan perilaku tak terdefinisi (Undefined Behavior) jika diakses di luar batas.
<br/>

- **Integrasi STL:** Sebagai bagian integral dari Standard Template Library (STL), `std::vector` berinteraksi dengan mulus dengan berbagai algoritma dan fungsi STL lainnya yang beroperasi menggunakan iterator. Ini memungkinkan penulisan kode yang lebih bersih, lebih cepat, dan lebih mudah dibaca.
<br/>

- **Fleksibilitas dan Kemudahan Penggunaan:** `std::vector` umumnya dianggap sebagai kontainer default untuk sebagian besar kasus penggunaan karena fleksibilitas dan kenyamanannya yang superior.
<br/>

- **Performa yang Dioptimalkan:** Meskipun ada overhead kecil karena fitur dinamis dan pemeriksaan batas, `std::vector` sangat dioptimalkan untuk performa. Dalam skenario dunia nyata, perbedaan performa antara `std::vector` dan array C-style seringkali dapat diabaikan. `std::vector` menyimpan elemen secara berurutan, memungkinkan akses cepat.


Perbandingan antara array C-style dan `std::vector` mencerminkan pergeseran filosofi pemrograman yang mendasar di C++. Array C-style, sebagai "alat dasar" untuk mengalokasikan memori yang berurutan , menawarkan kontrol tingkat rendah yang ekstrem dan alokasi yang sangat cepat di stack. Namun, kontrol ini datang dengan biaya: tidak adanya informasi ukuran bawaan, pemeriksaan batas, dan kemampuan perubahan ukuran dinamis. Kekurangan ini sering menyebabkan bug yang sulit dideteksi seperti akses di luar batas dan pemborosan memori.

`std::vector` mengatasi tantangan ini dengan membungkus memori berurutan tingkat rendah dengan objek yang menyediakan manajemen memori otomatis, kesadaran ukuran, pemeriksaan batas (melalui `at()`), dan perubahan ukuran dinamis. Meskipun ada sedikit overhead yang terkait dengan fitur-fitur dinamis ini, optimasi modern dalam implementasi `std::vector` membuatnya seringkali tidak signifikan dalam skenario dunia nyata.

Ini menunjukkan bahwa C++ telah berkembang dari manipulasi memori tingkat rendah yang rawan kesalahan menuju abstraksi tingkat tinggi yang memprioritaskan keamanan, produktivitas, dan pemeliharaan, seringkali dengan kompromi kinerja yang minimal. Untuk sebagian besar pengembangan C++ tujuan umum, `std::vector` adalah pilihan _default_ yang lebih unggul karena manfaat keamanannya dan "goodies" yang ditawarkannya jauh melebihi potensi penalti kinerja yang seringkali tidak signifikan. Array mentah sebaiknya dicadangkan untuk bagian kode yang sangat khusus, kritis kinerja, dan telah diprofilkan secara menyeluruh, seperti dalam sistem embedded atau saat berinteraksi langsung dengan API C.

---
## 2 | Deklarasi dan Inisialisasi `std::vector`

Mendeklarasikan dan menginisialisasi `std::vector` adalah langkah pertama yang krusial untuk menggunakannya. C++ menyediakan berbagai cara untuk melakukan ini, memberikan fleksibilitas tinggi yang sesuai dengan berbagai kebutuhan dan skenario data.

### 2.1 | Berbagai Cara Deklarasi

Untuk menggunakan `std::vector`, langkah pertama adalah menyertakan file header yang sesuai: `#include <vector>`. Setelah itu, deklarasi dasar untuk membuat `std::vector` kosong adalah dengan menentukan tipe data elemen yang akan disimpan dalam tanda kurung sudut (`<>`) diikuti oleh nama variabelnya. Misalnya, `std::vector<int> myNumbers;` akan mendeklarasikan sebuah vektor yang dapat menyimpan bilangan bulat tetapi saat ini tidak memiliki elemen apa pun.

Desain `std::vector` sebagai _template kelas_ adalah aspek fundamental yang memungkinkan fleksibilitasnya. Parameter template, yang dilambangkan dengan `T` dalam `std::vector<T>`, memungkinkan kelas dan fungsi ditulis tanpa harus menentukan semua tipe data yang akan digunakan. Ini berarti `std::vector` tidak terbatas pada tipe data primitif seperti `int` atau `char`, tetapi dapat menyimpan objek dari _tipe apa pun_, termasuk struktur dan kelas (*struct* dan *class*) yang ditentukan pengguna. Kemampuan ini sangat penting untuk keserbagunaan `std::vector` dan kepatuhannya terhadap paradigma "pemrograman generik" yang menjadi inti dari STL. Desain ini secara signifikan mengurangi duplikasi kode dan mempromosikan keamanan tipe di seluruh aplikasi.

### 2.2 | Metode Inisialisasi

`std::vector` dapat diinisialisasi dengan berbagai cara, memberikan fleksibilitas tinggi tergantung pada sumber data awal dan bagaimana data tersebut tersedia. Ini menunjukkan kemampuan `std::vector` untuk beradaptasi dengan berbagai skenario akuisisi data.

1. **Inisialisasi dengan `Initializer List`:** Ini adalah cara modern dan paling sering digunakan untuk menginisialisasi `std::vector` dengan daftar nilai yang diketahui pada waktu kompilasi. Nilai-nilai ini diapit oleh kurung kurawal `{}`. Compiler dapat menyimpulkan tipe data jika diinisialisasi langsung dari daftar.
	
	```cpp
	#include <vector>
	#include <iostream>
	
	int main() {
		std::vector<int> numbers = {1, 2, 3, 4, 5}; // Inisialisasi dengan daftar nilai
		std::cout << "Inisialisasi dengan Initializer List: ";
		for (int num : numbers) {
			std::cout << num << " ";
		}
		std::cout << std::endl;
		return 0;
	}
	```
	
	Output: 

	```
	Inisialisasi dengan Initializer List: 1 2 3 4 5
	```

<br/>

2. **Inisialisasi Satu per Satu (`push_back()`):** Jika elemen tidak diketahui di awal atau ditambahkan secara bertahap (misalnya, dari input pengguna atau hasil komputasi), Anda dapat membuat `std::vector` kosong dan menambahkan elemen satu per satu menggunakan metode `push_back()`. Metode ini sangat efisien untuk penambahan di akhir.
	
	```cpp
	#include <vector>
	#include <iostream>
	
	int main() {
		std::vector<int> dynamicNumbers;
		dynamicNumbers.push_back(10);
		dynamicNumbers.push_back(20);
		dynamicNumbers.push_back(30);
		std::cout << "Inisialisasi satu per satu (push_back): ";
		for (int num : dynamicNumbers) {
			std::cout << num << " ";
		}
		std::cout << std::endl;
		return 0;
	}
	```
	
	Output: 

	```
	Inisialisasi satu per satu (push_back): 10 20 30
	```

<br/>

3. **Inisialisasi dengan Ukuran dan Nilai Default:** Anda dapat membuat `std::vector` dengan ukuran tertentu (`count`) di mana semua elemen diinisialisasi dengan nilai `value` yang sama. Jika `value` tidak diberikan, elemen akan diinisialisasi dengan nilai default tipe datanya (misalnya, 0 untuk `int`).


	```cpp
	#include <vector>
	#include <iostream>
	
	int main() {
		std::vector<int> filledVector(5, 99); // 5 elemen, semua bernilai 99
		std::cout << "Inisialisasi dengan ukuran dan nilai default: ";
		for (int num : filledVector) {
			std::cout << num << " ";
		}
		std::cout << std::endl;
		return 0;
	}
	```
	
	Output: 

	```
	Inisialisasi dengan ukuran dan nilai default: 99 99 99 99 99
	```

<br/>

4. **Inisialisasi dari Rentang (Array C-style atau Vektor Lain):** `std::vector` dapat diinisialisasi dengan menyalin elemen dari rentang yang ditentukan oleh dua iterator (pointer ke awal dan satu posisi setelah akhir). Ini sangat berguna untuk mengonversi array C-style atau menyalin sebagian/seluruh vektor lain.

	```cpp
	#include <vector>
	#include <iostream>
	#include <numeric> // Untuk iota
	#include <iterator> // Untuk begin() dan end()
	
	using namespace std;
	
	int main() {
	// Perbaikan: array C-style harus menggunakan []
	int arr[] = {100, 200, 300, 400};
	
	// Inisialisasi vector dari array
	vector<int> fromArray(begin(arr), end(arr));
	cout << "Inisialisasi dari Array: ";
	for (int num : fromArray) {
		cout << num << " ";
	}
	cout << endl;
	
	// Inisialisasi dari vektor lain
	vector<int> originalVec = {1, 2, 3, 4, 5};
	vector<int> copiedVec(originalVec.begin(), originalVec.end());
	cout << "Inisialisasi dari Vektor Lain: ";
	for (int num : copiedVec) {
		cout << num << " ";
	}
	cout << endl;
	
	return 0;
	}
	```

	Output:

	```
	Inisialisasi dari Array: 100 200 300 400
	Inisialisasi dari Vektor Lain: 1 2 3 4 5
	```

<br/>

5. **Inisialisasi Menggunakan `std::fill()`:** Fungsi `std::fill()` dari header `<algorithm>` dapat digunakan untuk mengisi seluruh atau sebagian `std::vector` dengan nilai tertentu.

	```cpp
	#include <vector>
	#include <algorithm> // Untuk std::fill
	#include <iostream>
	
	int main() {
		std::vector<int> v(5); // Vektor dengan 5 elemen, nilai tidak terdefinisi
		std::fill(v.begin(), v.end(), 7); // Mengisi semua elemen dengan 7
		std::cout << "Inisialisasi menggunakan std::fill(): ";
		for (int num : v) {
			std::cout << num << " ";
		}
		std::cout << std::endl;
		return 0;
	}
	```
	
	Output:

	```
	Inisialisasi menggunakan std::fill(): 7 7 7 7 7
	```

<br/>

6. **Inisialisasi Menggunakan `std::iota()`:** Fungsi `std::iota()` dari header `<numeric>` dapat menginisialisasi `std::vector` dengan nilai berurutan yang dimulai dari nilai tertentu.

	```cpp
	#include <vector>
	#include <numeric>   // Untuk std::iota
	#include <iostream>
	
	int main() {
		std::vector<int> sequentialNumbers(5);
		std::iota(sequentialNumbers.begin(), sequentialNumbers.end(), 10); // Mulai dari 10
		std::cout << "Inisialisasi menggunakan std::iota(): ";
		for (int num : sequentialNumbers) {
			std::cout << num << " ";
		}
		std::cout << std::endl;
		return 0;
	}
	```

	Output:
	```
	Inisialisasi menggunakan std::iota(): 10 11 12 13 14
	```

<br/>

Banyaknya metode inisialisasi yang tersedia untuk `std::vector` menunjukkan kemampuannya untuk beradaptasi dengan berbagai skenario data. Baik data diketahui pada waktu kompilasi, dihasilkan secara dinamis, disalin dari struktur yang ada, atau di-stream satu per satu, `std::vector` menyediakan cara yang efisien dan idiomatik untuk membangun dan mengisi dirinya sendiri. Desain ini secara signifikan meningkatkan produktivitas pengembang dengan menawarkan solusi yang disesuaikan untuk pola penanganan data umum, mengurangi kebutuhan akan logika transfer data manual yang rawan kesalahan.
    
---
## 3 | Akses dan Modifikasi Elemen `std::vector`

`std::vector` menyediakan serangkaian fungsi anggota yang kaya untuk mengakses, memodifikasi, dan mengelola elemen serta kapasitas memorinya. Memahami fungsi-fungsi ini sangat penting untuk penggunaan `std::vector` yang efisien dan aman.

### 3.1. | Mengakses Elemen

`std::vector` menawarkan beberapa cara untuk mengakses elemennya, masing-masing dengan karakteristik performa dan keamanan yang berbeda.

#### `operator[]` (Subscript Operator):
- **Deskripsi:** Mengakses elemen berdasarkan indeksnya (misalnya, `myVector[index]`). Ini adalah cara tercepat dan paling langsung untuk mengakses elemen, mirip dengan array C-style.
- **Pemeriksaan Batas:** Operator ini _tidak melakukan pemeriksaan batas_ (bounds checking).
- **Perilaku Saat Indeks Invalid:** Mengakses indeks di luar batas yang valid akan menyebabkan _perilaku tak terdefinisi (Undefined Behavior)_, yang bisa berupa crash program, data korup, atau hasil yang tidak terduga.


#### Metode `at()`:
- **Deskripsi:** Mengakses elemen berdasarkan indeksnya (misalnya, `myVector.at(index)`).
- **Pemeriksaan Batas:** Metode ini _melakukan pemeriksaan batas_.
- **Perilaku Saat Indeks Invalid:** Jika indeks di luar jangkauan, `at()` akan melempar `std::out_of_range` exception, yang memungkinkan penanganan kesalahan yang aman dan terprediksi.

#### Metode `front()`: 
Mengembalikan referensi ke elemen _pertama_ dalam vektor. Penggunaan pada vektor kosong akan menghasilkan perilaku tak terdefinisi.
#### Metode `back()`: 
Mengembalikan referensi ke elemen _terakhir_ dalam vektor. Penggunaan pada vektor kosong juga akan menghasilkan perilaku tak terdefinisi.

#### Metode `data()`: 
Mengembalikan pointer langsung ke memori yang mendasari tempat elemen disimpan. Ini sangat berguna untuk berinteraksi dengan API C-style yang memerlukan pointer ke array mentah.

---

Pilihan antara `operator[]` dan metode `at()` adalah contoh bagaimana C++ memberikan kontrol granular kepada pengembang untuk menyeimbangkan performa dan keamanan. `operator[]` lebih cepat karena tidak ada overhead pemeriksaan batas, tetapi berisiko perilaku tak terdefinisi jika indeks tidak valid. Sebaliknya, `at()` lebih lambat tetapi aman karena melempar pengecualian. Dalam kode yang kritis performa di mana indeks dijamin valid (misalnya, setelah iterasi yang aman), `operator[]` lebih disukai. Dalam kode yang membutuhkan ketahanan dan penanganan kesalahan yang jelas (misalnya, input pengguna), `at()` adalah pilihan yang lebih baik. Prinsip "Anda tidak membayar untuk apa yang tidak Anda gunakan" ini adalah landasan desain C++.

**Tabel: Perbandingan Akses Elemen `std::vector`**

|                             |                                                                                 |                                                                                                 |
| --------------------------- | ------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------- |
| **Fitur**                   | **operator (Subscript Operator)**                                               | **at() Method**                                                                                 |
| **Pemeriksaan Batas**       | Tidak ada                                                                       | Ada, yaitu melempar `std::out_of_range` exception                                               |
| **Perilaku Invalid Indeks** | Perilaku Tak Terdefinisi (Undefined Behavior)                                   | Melempar `std::out_of_range` exception                                                          |
| **Kecepatan**               | Lebih cepat                                                                     | Sedikit lebih lambat karena pemeriksaan batas                                                   |
| **Kapan Digunakan**         | Ketika indeks dijamin valid (misalnya, dalam loop yang terdefinisi dengan baik) | Ketika keamanan lebih diprioritaskan atau indeks mungkin tidak valid (misalnya, input pengguna) |

### 3.2 | Mengelola Kapasitas

`std::vector` secara otomatis mengelola alokasi memori internalnya. Namun, ia juga menyediakan fungsi-fungsi untuk mengelola kapasitas ini secara eksplisit, yang memengaruhi kinerja dan penggunaan memori.

- **`size()`:** Mengembalikan jumlah elemen aktual yang saat ini disimpan dalam `std::vector`. Ini adalah ukuran _logis_ dari kontainer.
<br/>

- **`capacity()`:** Mengembalikan jumlah total elemen yang dapat ditampung oleh `std::vector` dalam alokasi memori saat ini tanpa perlu mengalokasikan ulang. Ini adalah ukuran _fisik_ dari blok memori yang dialokasikan, dan `capacity()` selalu lebih besar dari atau sama dengan `size()`.
<br/>

- **`max_size()`:** Mengembalikan jumlah maksimum elemen yang secara teoritis dapat ditampung oleh `std::vector`. Ini biasanya dibatasi oleh memori sistem yang tersedia.
<br/>

- **`reserve(count)`:** Meminta `std::vector` untuk mengalokasikan ruang penyimpanan yang cukup untuk setidaknya `count` elemen. Jika `count` lebih besar dari `capacity()` saat ini, realokasi akan terjadi. Ini adalah optimasi penting untuk mencegah realokasi yang sering dan mahal saat `std::vector` tumbuh.
<br/>

- **`resize(new_size)` / `resize(new_size, value)`:** Mengubah jumlah elemen aktual dalam `std::vector` menjadi `new_size`. Jika `new_size` lebih besar dari `size()` saat ini, elemen baru ditambahkan (diinisialisasi default atau dengan `value`). Jika `new_size` lebih kecil, elemen dari akhir akan dihapus. `resize()` dapat menyebabkan realokasi jika `new_size` melebihi `capacity()` saat ini.
<br/>

- **`shrink_to_fit()`:** Mengurangi `capacity()` `std::vector` ke `size()`-nya saat ini, melepaskan memori yang tidak terpakai. Ini berguna untuk menghemat memori setelah `std::vector` mencapai ukuran akhirnya, atau setelah banyak penghapusan elemen yang membuat kapasitas jauh lebih besar dari ukuran.

Fungsi manajemen kapasitas `std::vector` (`size()`, `capacity()`, `max_size()`, `reserve()`, `resize()`, `shrink_to_fit()`) menyediakan antarmuka yang canggih namun ramah pengguna untuk mengelola memori dinamis. Ketika `std::vector` kehabisan ruang, ia secara otomatis mengalokasikan blok memori baru yang lebih besar, menyalin elemen yang ada, dan mendealokasikan blok lama. Meskipun proses realokasi ini memiliki biaya kinerja yang signifikan, terutama untuk vektor besar atau objek kompleks, `reserve()` memungkinkan pengembang untuk memprediksi kebutuhan ukuran dan meminimalkan realokasi yang mahal. Demikian pula, `shrink_to_fit()` membantu mengelola jejak memori dalam aplikasi yang sadar sumber daya. Keseimbangan antara otomatisasi dan kontrol ini adalah ciri khas kontainer C++ yang dirancang dengan baik, memungkinkan pengembang untuk mengoptimalkan baik kinerja maupun jejak memori berdasarkan kebutuhan spesifik aplikasi.

**Tabel: Fungsi Manajemen Kapasitas `std::vector`**


|   |   |   |   |   |
|---|---|---|---|---|
|**Fungsi**|**Deskripsi**|**Dampak pada size()**|**Dampak pada capacity()**|**Kapan Digunakan**|
|`size()`|Mengembalikan jumlah elemen saat ini|Tidak berubah|Tidak berubah|Untuk mengetahui jumlah elemen yang valid|
|`capacity()`|Mengembalikan jumlah elemen yang dapat ditampung tanpa realokasi|Tidak berubah|Tidak berubah|Untuk memeriksa alokasi memori internal|
|`max_size()`|Mengembalikan jumlah maksimum elemen yang mungkin|Tidak berubah|Tidak berubah|Untuk mengetahui batasan teoritis ukuran vektor|
|`reserve(count)`|Meminta alokasi memori untuk `count` elemen|Tidak berubah|Dapat meningkat hingga `count`|Ketika ukuran akhir vektor diperkirakan untuk menghindari realokasi|
|`resize(new_size)`|Mengubah ukuran logis vektor menjadi `new_size`|Berubah menjadi `new_size`|Dapat meningkat (jika `new_size > capacity()`), atau tetap|Untuk mengubah jumlah elemen yang aktif dalam vektor|
|`shrink_to_fit()`|Mengurangi kapasitas ke ukuran saat ini|Tidak berubah|Dapat menurun hingga `size()`|Untuk membebaskan memori yang tidak terpakai setelah penghapusan|
### 3.3 | Menambah dan Menghapus Elemen

Operasi penambahan dan penghapusan elemen adalah inti dari fleksibilitas `std::vector`. Namun, performa operasi ini sangat bergantung pada posisi modifikasi dalam vektor.

- **`push_back(value)`:** Menambahkan elemen baru ke akhir `std::vector`. Ini adalah operasi yang sangat efisien, biasanya dalam waktu konstan (`O(1)`) secara _amortized_ (rata-rata), karena `std::vector` akan mengalokasikan ulang kapasitasnya saat dibutuhkan.
<br/>

- **`pop_back()`:** Menghapus elemen terakhir dari `std::vector`. Ini juga merupakan operasi yang sangat efisien (`O(1)`).
<br/>

- **`insert(position, value/count/range)`:** Memasukkan satu atau lebih elemen pada posisi tertentu yang ditunjuk oleh iterator. Operasi ini bisa mahal (`O(N)`) karena mungkin memerlukan pergeseran semua elemen setelah posisi penyisipan untuk mempertahankan kontiguitas memori.
<br/>

- **`emplace(position, args...)` / `emplace_back(args...)`:** Fungsi-fungsi ini membangun elemen baru secara langsung di dalam vektor pada posisi tertentu (`emplace`) atau di akhir (`emplace_back`), tanpa membuat objek sementara dan kemudian menyalin atau memindahkannya. Ini dapat memberikan keuntungan kinerja, terutama untuk objek kompleks, karena menghindari salinan/pemindahan yang tidak perlu.
<br/>

- **`erase(position/range)`:** Menghapus satu elemen atau rentang elemen dari posisi tertentu. Seperti `insert()`, ini bisa mahal (`O(N)`) karena elemen-elemen setelah yang dihapus perlu digeser ke depan untuk mengisi celah.
<br/>

- **`clear()`:** Menghapus semua elemen dari `std::vector`, membuat ukurannya menjadi nol. Namun, kapasitas memori yang dialokasikan biasanya tetap tidak berubah.

Perbedaan performa antara `push_back()`/`pop_back()` yang efisien dan `insert()`/`erase()` yang mahal (selain di akhir) disebabkan oleh sifat memori berurutan `std::vector`. Menambahkan atau menghapus di tengah memerlukan pergeseran semua elemen berikutnya untuk mempertahankan kontinuitas memori, yang secara langsung berkorelasi dengan jumlah elemen yang digeser (`N`). Ini berarti `std::vector` sangat cocok untuk skenario di mana penambahan dan penghapusan sebagian besar terjadi di akhir (misalnya, log, buffer data). Namun, jika aplikasi sering memerlukan penyisipan atau penghapusan di tengah atau awal, kontainer lain seperti `std::list` atau `std::deque` mungkin lebih cocok, meskipun mereka mungkin memiliki overhead memori atau performa akses yang berbeda. Pemahaman ini penting untuk pemilihan struktur data yang tepat berdasarkan operasi yang dominan.

### 3.4 | Operasi Lain

Selain modifikasi elemen, `std::vector` juga menyediakan operasi untuk penugasan ulang dan pertukaran konten.

- **`assign(count, value)` / `assign(initializer_list)` / `assign(first, last)`:** Fungsi ini menghapus semua elemen yang ada dalam vektor dan kemudian menggantinya dengan elemen yang ditentukan, baik itu sejumlah salinan dari satu nilai, elemen dari initializer list, atau elemen dari rentang iterator lain. Ini secara efektif menginisialisasi ulang `std::vector` dengan konten baru.
<br/>

- **`swap(other_vector)`:** Menukar seluruh isi dua `std::vector` dengan tipe dan alokator yang sama. Ini adalah operasi yang sangat efisien (`O(1)`) karena hanya menukar pointer internal ke blok memori, bukan menyalin elemen satu per satu.

Efisiensi `std::vector::swap()` adalah konsekuensi langsung dari manajemen memori dasarnya. Karena `std::vector` mengelola blok memori yang berurutan, pertukaran konten antara dua vektor dapat dicapai hanya dengan menukar pointer ke blok memori tersebut, tanpa perlu menyalin data aktual. Ini adalah idiom yang kuat untuk operasi seperti mengimplementasikan operator penugasan copy-and-swap, atau untuk membersihkan vektor sambil mengklaim kembali memori (misalnya `std: :vector<T>().swap(my_vector);`) karena menghindari overhead penyalinan elemen per elemen atau realokasi.

---
## 4. Penggunaan Iterator pada `std::vector`

Iterator adalah konsep kunci dalam Standard Template Library (STL) C++ yang memungkinkan cara yang seragam untuk mengakses elemen dalam berbagai kontainer, termasuk `std::vector`.

### 4.1 | Apa itu Iterator?

Iterator dalam C++ adalah objek yang berperilaku seperti pointer, yang menunjuk ke elemen individual dalam kontainer STL. Tujuan utamanya adalah untuk menyediakan cara standar dan generik untuk melintasi (traverse) dan mengakses elemen-elemen kontainer, tanpa perlu mengetahui detail implementasi internal kontainer tersebut.

Keuntungan signifikan dari iterator adalah kemampuannya untuk membuat algoritma STL independen dari jenis kontainer yang digunakan. Ini berarti algoritma yang sama dapat bekerja dengan `std::vector`, `std::list`, `std::deque`, dan bahkan array C-style, asalkan mereka menyediakan iterator yang kompatibel. Ini adalah lapisan abstraksi yang kuat, memisahkan algoritma dari struktur data dasar yang spesifik. "Antarmuka universal" ini memungkinkan algoritma generik (seperti `sort()`, `find()`) untuk bekerja secara mulus di seluruh koleksi data yang beragam, mempromosikan penggunaan kembali kode dan mengurangi kompleksitas.

### 4.2. | Jenis-jenis Iterator yang Relevan untuk `std::vector`

`std::vector` mendukung jenis iterator yang paling kuat, yaitu _Random Access Iterators_. Ini berarti mereka menawarkan fungsionalitas paling lengkap, mirip dengan pointer biasa, memungkinkan akses langsung ke elemen mana pun dalam waktu konstan.

- **`iterator`:** Iterator standar yang dapat membaca dan memodifikasi nilai elemen yang ditunjuknya. Digunakan untuk traversal dan modifikasi.
<br/>

- **`const_iterator`:** Iterator konstan yang hanya dapat membaca nilai elemen yang ditunjuknya, tidak dapat memodifikasinya. Ini penting untuk fungsi yang menerima kontainer sebagai argumen `const`.
<br/>

- **`reverse_iterator`:** Iterator yang melintasi vektor secara terbalik, dari elemen terakhir ke elemen pertama.
<br/>

- **`const_reverse_iterator`:** Kombinasi dari `const_iterator` dan `reverse_iterator`, memungkinkan traversal terbalik tanpa modifikasi.
### 4.3. Fungsi Anggota yang Mengembalikan Iterator

`std::vector` menyediakan beberapa fungsi anggota untuk mendapatkan iterator yang menunjuk ke lokasi penting dalam vektor, memungkinkan traversal dan manipulasi yang fleksibel.

- **`begin()`:** Mengembalikan `iterator` yang menunjuk ke elemen _pertama_ dari vektor.
<br/>

- **`end()`:** Mengembalikan `iterator` yang menunjuk ke "elemen teoretis setelah elemen terakhir" (past-the-end element). Ini adalah penanda akhir rentang dan _tidak boleh di-dereference_.
<br/>

- **`cbegin()` / `cend()`:** Versi `const` dari `begin()` dan `end()`, masing-masing mengembalikan `const_iterator`. Digunakan ketika pengembang ingin memastikan bahwa elemen tidak akan dimodifikasi.
<br/>

- **`rbegin()` / `rend()`:** Mengembalikan `reverse_iterator` yang menunjuk ke elemen pertama dalam traversal terbalik (yaitu, elemen terakhir dari vektor asli) dan elemen "past-the-end" untuk traversal terbalik (yaitu, satu sebelum elemen pertama vektor asli).
<br/>

- **`crbegin()` / `crend()`:** Versi `const` dari `rbegin()` dan `rend()`.

Konsep "half-open range" 

- **Increment/Decrement (`++it`, `--it`):** Memindahkan iterator ke elemen berikutnya atau sebelumnya. Ada bentuk _pre-increment_ (`++it`) dan _post-increment_ (`it++`).
<br/>

- **Aritmatika Iterator (`it + n`, `it - n`):** Memindahkan iterator sebanyak `n` posisi ke depan atau ke belakang. Ini adalah fitur khusus Random Access Iterators yang memungkinkan akses langsung ke elemen mana pun dalam waktu konstan.
<br/>

- **Pengurangan Iterator (`it1 - it2`):** Menghitung jarak (jumlah elemen) antara dua iterator. Hasilnya adalah `std::ptrdiff_t`.
<br/>

- **Perbandingan Iterator ($==$, `!=`, `<`, `>`, `<=`, `>=`):** Membandingkan dua iterator dari tipe yang sama untuk menentukan hubungannya.
<br/>

- **Fungsi Utilitas Global:** STL juga menyediakan fungsi utilitas global di header `<iterator>` untuk memanipulasi iterator:
	- `std::advance(it, n)`: Memajukan iterator `it` sebanyak `n` posisi.
	- `std::next(it, n)`: Mengembalikan iterator baru yang `n` posisi di depan `it`.
	- `std::prev(it, n)`: Mengembalikan iterator baru yang `n` posisi di belakang `it`.
	- `std::distance(it1, it2)`: Mengembalikan jumlah elemen antara `it1` dan `it2`.

**Tabel: Jenis dan Operasi Iterator `std::vector`**


|   |   |   |   |   |
|---|---|---|---|---|
|**Jenis Iterator**|**Kemampuan Akses**|**Arah Traversal**|**Operasi Umum yang Didukung**|**Fungsi Pengambil**|
|`iterator`|Baca & Tulis|Maju & Mundur|`*it`, `++it`, `--it`, `it+n`, `it-n`, `it1-it2`, Perbandingan|`begin()`, `end()`|
|`const_iterator`|Hanya Baca|Maju & Mundur|`*it`, `++it`, `--it`, `it+n`, `it-n`, `it1-it2`, Perbandingan|`cbegin()`, `cend()`|
|`reverse_iterator`|Baca & Tulis|Mundur|`*rit`, `++rit`, `--rit`, `rit+n`, `rit-n`, `rit1-rit2`, Perbandingan|`rbegin()`, `rend()`|
|`const_reverse_iterator`|Hanya Baca|Mundur|`*crit`, `++crit`, `--crit`, `crit+n`, `crit-n`, `crit1-crit2`, Perbandingan|`crbegin()`, `crend()`|

---
## 5 | Implementasi dan Mekanisme Internal `std::vector`

Memahami bagaimana `std::vector` diimplementasikan secara internal sangat penting untuk mengoptimalkan penggunaannya dan menghindari potensi _bottleneck_ kinerja.

### 5.1 | Alokasi Memori Dinamis

Elemen `std::vector` disimpan dalam blok memori yang berurutan (contiguous memory). Ini berarti semua elemen dialokasikan berdampingan dalam satu blok memori tunggal, mirip dengan array C-style. Namun, tidak seperti array C-style yang sering dialokasikan di stack dengan ukuran tetap, memori untuk `std::vector` dialokasikan secara dinamis di _heap_. Alokasi di heap memungkinkan ukuran `std::vector` tidak diketahui pada waktu kompilasi dan dapat berubah selama runtime.

Penyimpanan elemen dalam memori yang berurutan adalah pilihan desain fundamental untuk `std::vector` yang secara langsung berkontribusi pada kinerja tingginya. Properti ini memungkinkan pemanfaatan cache CPU yang efisien (sering disebut "cache friendliness"), karena data dapat diambil ke dalam cache CPU dalam blok yang lebih besar, mengurangi latensi akses memori. Selain itu, akses acak ke elemen apa pun dalam vektor sangat cepat karena melibatkan aritmatika pointer sederhana. Ini menjadikan `std::vector` sangat cocok untuk algoritma yang mengiterasi elemen, seperti pengurutan atau pencarian, karena data dapat diakses dengan cepat dan efisien. Ini adalah alasan utama mengapa `std::vector` seringkali lebih disukai daripada kontainer dinamis lain seperti `std::list` (yang menggunakan memori tidak berurutan).

### 5.2 | Mekanisme Resizing

Kemampuan `std::vector` untuk mengubah ukurannya secara dinamis adalah fitur utama, tetapi mekanisme di baliknya melibatkan proses yang penting untuk dipahami.

Ketika `std::vector` kehabisan ruang pada lokasi memori saat ini (yaitu, `size()` mencapai `capacity()`), ia melakukan operasi _resizing_. Proses ini melibatkan tiga langkah utama:

1. **Alokasi blok memori baru yang lebih besar:** `std::vector` meminta blok memori baru yang memiliki kapasitas lebih besar dari yang sebelumnya. Umumnya, kapasitas baru ini adalah dua kali lipat dari kapasitas sebelumnya, meskipun implementasi spesifik dapat bervariasi.
<br/>

2. **Pemindahan semua elemen yang ada:** Semua elemen dari lokasi memori lama disalin atau dipindahkan ke blok baru yang dialokasikan. Untuk objek yang mendukung _move semantics_, ini dapat lebih efisien daripada penyalinan penuh.
<br/>

3. **Dealokasi blok memori lama:** Setelah elemen berhasil dipindahkan, blok memori asli yang lebih kecil dibebaskan.

Dampak Performa dari Resizing:

Proses realokasi ini memiliki biaya kinerja yang signifikan ($O(N)$) terutama untuk vektor besar atau objek kompleks, karena melibatkan penyalinan atau pemindahan semua data yang ada. Jika `std::vector` tumbuh hanya dengan sejumlah kecil elemen setiap kali, realokasi yang sering akan menyebabkan kinerja yang buruk secara keseluruhan $(O(N^2)$ untuk $N$ penambahan).

Untuk memitigasi hal ini, `std::vector` menggunakan strategi pertumbuhan eksponensial (misalnya, menggandakan kapasitasnya). Meskipun realokasi tunggal mahal, biaya _amortized_ dari `push_back` tetap `O(1)` karena realokasi menjadi lebih jarang seiring pertumbuhan vektor. Ini berarti bahwa selama urutan banyak operasi `push_back`, total biaya rata-rata menjadi waktu konstan per elemen.

Pengembang dapat secara proaktif mengelola mekanisme ini dengan menggunakan fungsi `reserve(count)` untuk mengalokasikan kapasitas di muka jika perkiraan jumlah elemen yang diharapkan diketahui. Ini mengurangi realokasi yang tidak perlu dan puncaknya kinerja yang tidak terduga. Namun, realokasi berlebihan (`over-reserving`) dapat menyebabkan pemborosan memori jika kapasitas yang dialokasikan tidak sepenuhnya digunakan. 

`std::vector` dengan mekanisme pertumbuhan ini, dikombinasikan dengan kemampuan untuk mengelola kapasitas secara eksplisit, memungkinkan pengembang untuk mencapai keseimbangan optimal antara fleksibilitas, konsumsi memori, dan performa.

---
## 6 | Aplikasi `std::vector` di Dunia Nyata

Fleksibilitas, efisiensi, dan manajemen memori otomatis `std::vector` menjadikannya pilihan yang sangat populer dan serbaguna dalam berbagai aplikasi dunia nyata.

### 6.1 | Pengembangan Grafis dan Game:

`std::vector` sangat berharga dalam industri game dan grafis. Kemampuannya untuk mengubah ukuran secara dinamis dan mempertahankan memori yang berurutan sangat penting untuk mengelola data grafis seperti *vertex buffers* (kumpulan titik yang mendefinisikan bentuk objek 3D), texture data (gambar yang diterapkan pada permukaan objek), dan elemen grafis dinamis lainnya. Data-data ini seringkali perlu diubah atau diperbarui secara real-time, dan `std::vector` menyediakan cara yang efisien untuk melakukannya.

### 6.2 | Komputasi Kinerja Tinggi (High-Performance Computing - HPC):

Dalam aplikasi HPC yang menuntut kinerja tinggi, `std::vector` sangat cocok karena implementasi dasarnya menggunakan blok memori yang berurutan. Properti ini memastikan cache locality yang sangat baik, yang dapat meningkatkan kinerja secara signifikan untuk tugas-tugas intensif data seperti simulasi ilmiah, analisis data besar, dan pemrosesan paralel.

### 6.3 | Sistem Real-time:

Efisiensi dan kemampuan dynamic resizing `std::vector` membuatnya berharga untuk sistem real-time di mana ukuran data dapat berubah dengan cepat. Namun, dalam konteks ini, penting untuk menggunakan `reserve()` secara strategis untuk meminimalkan realokasi yang tidak terduga, yang dapat menyebabkan *latency spikes* yang tidak diinginkan dalam aplikasi yang sensitif terhadap waktu.

### 6.4 | Simulasi Kompleks:

`std::vector` menyediakan efisiensi dan fleksibilitas yang diperlukan untuk mengelola data dinamis dalam simulasi kompleks, seperti simulasi fisika, cuaca, atau ekonomi. Data dalam simulasi ini seringkali tumbuh atau menyusut, dan `std::vector` dapat menangani perubahan tersebut dengan mudah.

Implementasi Struktur Data Lain:

Array (dan oleh karena itu `std: :vector`) adalah blok bangunan fundamental untuk mengimplementasikan berbagai struktur data lain. Misalnya:

- **Stack dan Queue:** `std::vector` dapat digunakan sebagai dasar untuk mengimplementasikan stack (LIFO) dan queue (FIFO) dengan efisien, terutama karena operasi `push_back()` dan `pop_back()` yang cepat.
<br/>

- **Hash Table:** `std::vector` sering digunakan sebagai array dasar untuk tabel hash, di mana setiap elemen vektor dapat menjadi _bucket_ yang menyimpan daftar elemen, misalnya `std::vector<std::list<T>>`.
<br/>

- **List dan Heap:** Meskipun STL menyediakan `std::list` dan `std::priority_queue` (yang sering diimplementasikan dengan heap), `std::vector` juga dapat menjadi dasar untuk implementasi kustom dari struktur data ini.

Kombinasi memori berurutan (untuk kinerja) dan ukuran dinamis (untuk fleksibilitas) menjadikan `std::vector` sebagai struktur data dasar yang penting untuk membangun struktur data yang lebih kompleks dan modern di C++. Daripada mengelola array mentah secara manual untuk implementasi ini, pengembang dapat memanfaatkan `std::vector` untuk mewarisi keamanan, kenyamanan, dan karakteristik kinerja yang dioptimalkan, sehingga mempercepat pengembangan dan mengurangi bug dalam struktur data tingkat tinggi. Ini menempatkan `std::vector` tidak hanya sebagai kontainer, tetapi sebagai komponen penting dalam ekosistem C++ modern untuk membangun sistem yang efisien dan tangguh.

---
## 7 | Algoritma Standard Library dengan `std::vector`

Salah satu kekuatan terbesar `std::vector` adalah integrasinya yang mulus dengan algoritma Standard Template Library (STL). Algoritma STL dirancang untuk beroperasi pada berbagai kontainer, termasuk `std::vector`, melalui penggunaan iterator. Algoritma ini ditemukan di header `<algorithm>` dan `<numeric>`.

### 7.1. | Pencarian

STL menyediakan algoritma pencarian yang efisien yang dapat digunakan dengan `std::vector`.

#### Fungsi `std::find()`:

- **Deskripsi:** Melakukan pencarian linear untuk menemukan kemunculan pertama elemen dalam rentang yang diberikan oleh dua iterator. Mengembalikan iterator ke elemen jika ditemukan, atau `end()` iterator jika tidak.
- **Kompleksitas Waktu:** $O(N)$ (linier). Cocok untuk data kecil atau tidak terurut.
- **Contoh:**

	```cpp
	#include <vector>
	#include <algorithm> // Untuk std::find
	#include <iostream>
	#include <iterator>  // Untuk std::distance
	
	int main() {
		std::vector<int> data = {1, 2, 3, 4, 5};
		int target = 3;
		auto it = std::find(data.begin(), data.end(), target);
		if (it!= data.end()) {
			std::cout << "Elemen " << target << " ditemukan pada indeks: "
					  << std::distance(data.begin(), it) << std::endl;
		} else {
			std::cout << "Elemen " << target << " tidak ditemukan." << std::endl;
		}
		return 0;
	}
	```
	
	Output: 

	```
	Elemen 3 ditemukan pada indeks: 2
	```

#### Fungsi `std::binary_search()`:

- **Deskripsi:** Memeriksa apakah elemen setara dengan nilai yang dicari muncul dalam rentang yang _terurut_. Mengembalikan `true` jika ditemukan, dan `false` jika tidak.
- **Prasyarat:** Rentang harus _terurut_. Jika tidak, perilaku tak terdefinisi dapat terjadi.
- **Kompleksitas Waktu:** $O(\log N)$ (logaritmik). Jauh lebih efisien daripada pencarian linear untuk data besar yang terurut.
- **Contoh:**

	```cpp
	#include <vector>
	#include <algorithm> // Untuk std::binary_search
	#include <iostream>
	
	int main() {
		std::vector<int> data = {1, 2, 3, 4, 5}; // Harus terurut!
		int target = 4;
		if (std::binary_search(data.begin(), data.end(), target)) {
			std::cout << "Elemen " << target << " ada." << std::endl;
		} else {
			std::cout << "Elemen " << target << " tidak ada." << std::endl;
		}
		return 0;
	}
	```
	
	Output: 

	```
	Elemen 4 ada.
	```

	Pilihan algoritma pencarian tidaklah sembarangan, melainkan sangat bergantung pada keadaan data. `std::binary_search` menawarkan kinerja yang jauh lebih baik untuk kumpulan data besar, tetapi hanya jika data sudah terurut. Ini menyoroti prinsip fundamental dalam desain algoritma: algoritma yang lebih cepat seringkali datang dengan prasyarat yang lebih ketat. Pengembang harus memahami prasyarat ini untuk memanfaatkan kekuatan penuh STL secara efisien dan menghindari hasil yang salah atau _bottleneck_ kinerja yang tidak terduga.
    
### 7.2 | Pengurutan dengan `std::sort`

#### Fungsi `std::sort()`:
- **Deskripsi:** Mengurutkan elemen dalam rentang yang diberikan (ditentukan oleh dua iterator). Secara default, ini mengurutkan dalam urutan naik.
- **Implementasi Internal:** Menggunakan algoritma IntroSort, sebuah algoritma hibrida yang menggabungkan quicksort, heapsort, dan insertion sort untuk kinerja optimal.
- **Kompleksitas Waktu:** Rata-rata $O(N \;log\; N)$.
- **Contoh:**

	```cpp
	#include <vector>
	#include <algorithm> // Untuk std::sort
	#include <iostream>
	#include <functional> // Untuk std::greater
	
	int main() {
		std::vector<int> numbers = {5, 3, 9, 1, 6};
		std::sort(numbers.begin(), numbers.end()); // Urutan naik secara default
	
		std::cout << "Vektor terurut (naik): ";
		for (int num : numbers) {
			std::cout << num << " ";
		}
		std::cout << std::endl;
	
		// Mengurutkan dalam urutan turun menggunakan std::greater
		std::vector<int> numbers_desc = {10, 65, 31, 47, 2};
		std::sort(numbers_desc.begin(), numbers_desc.end(), std::greater<int>());
		std::cout << "Vektor terurut (turun): ";
		for (int num : numbers_desc) {
			std::cout << num << " ";
		}
		std::cout << std::endl;
	
		return 0;
	}
	```
	
	Output:

	```
	Vektor terurut (naik): 1 3 5 6 9 
	Vektor terurut (turun): 65 47 31 10 2
	```

	> Kita bisa juga menggunakan `sort(arr.rbegin(), arr.rend())` untuk mengurutkanya dari terbesar ke terkecil!

	Algoritma pengurutan manual seperti Bubble Sort, Selection Sort, dan Insertion Sort, yang sering diajarkan sebagai konsep dasar, umumnya memiliki kompleksitas waktu $O(N^2)$. Sebaliknya, `std::sort` menggunakan algoritma hibrida yang sangat dioptimalkan untuk mencapai kompleksitas $O(N\; log\; N)$. 
	
	Ini berarti `std::sort` (dan algoritma STL lainnya) hampir selalu lebih unggul daripada algoritma pengurutan yang diimplementasikan secara kustom untuk penggunaan tujuan umum. Mereka dioptimalkan secara ketat, diuji secara menyeluruh, dan beradaptasi dengan karakteristik data yang berbeda. Mengandalkan algoritma STL mempromosikan kode yang tangguh, efisien, dan mudah dipelihara, membebaskan pengembang dari mengulang kembali pekerjaan dan berpotensi memperkenalkan bug atau regresi kinerja dengan implementasi manual.
    
### 7.3 | Operasi Numerik dengan `std::accumulate`

#### Fungsi `std::accumulate()`:
- **Deskripsi:** Menghitung jumlah atau nilai akumulasi lainnya dari elemen dalam rentang yang diberikan. Fungsi ini dapat menggunakan operasi biner kustom (misalnya, perkalian, konkatenasi string) selain penjumlahan default.
- **Kompleksitas Waktu:** $O(N)$ (linier).
- **Contoh:**

	
	```cpp
	#include <vector>
	#include <numeric>   // Untuk std::accumulate
	#include <iostream>
	#include <functional> // Untuk std::multiplies
	
	int main() {
		std::vector<int> numbers = {1, 2, 3, 4, 5};
	
		// Jumlah elemen
		int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
		std::cout << "Jumlah: " << sum << std::endl; // Output: 15
	
		// Produk elemen
		int product = std::accumulate(numbers.begin(), numbers.end(), 1, std::multiplies<int>());
		std::cout << "Produk: " << product << std::endl; // Output: 120
	
		return 0;
	}
	```
	
	Output: 

	```
	Jumlah: 15 
	Produk: 120
	```

	`std::accumulate` menunjukkan paradigma pemrograman fungsional dalam STL, memungkinkan pengembang untuk mengekspresikan reduksi data yang kompleks (seperti jumlah, produk, konkatenasi string, agregasi kustom) secara ringkas dan generik. Dengan mengabstraksi operasi dari traversal, ini mempromosikan kode yang sangat dapat digunakan kembali dan mengurangi _boilerplate_, menunjukkan bagaimana algoritma STL menyediakan alat yang ampuh untuk pemrosesan data di luar aritmatika sederhana.

<br/>

**Tabel: Algoritma Standard Library Umum dengan `std::vector`**


|   |   |   |   |   |
|---|---|---|---|---|
|**Algoritma**|**Tujuan**|**Prasyarat**|**Kompleksitas Waktu**|**Contoh Penggunaan Singkat**|
|`std::find()`|Mencari kemunculan pertama elemen|Tidak ada|`O(N)`|`std::find(vec.begin(), vec.end(), value)`|
|`std::binary_search()`|Memeriksa keberadaan elemen|Rentang harus terurut|`O(log N)`|`std::binary_search(vec.begin(), vec.end(), value)`|
|`std::sort()`|Mengurutkan elemen dalam rentang|Random Access Iterators|`O(N log N)` (rata-rata)|`std::sort(vec.begin(), vec.end())`|
|`std::accumulate()`|Menghitung nilai akumulasi (jumlah, produk, dll.)|Tidak ada|`O(N)`|`std::accumulate(vec.begin(), vec.end(), initial_value, binary_op)`|



---
## 8 | Waktu yang Tepat Menggunakan `std::vector`

### 8.1 | Kapan Menggunakan `std::vector`?

Kamu bisa menggunakan `std::vector` ketika: 

* **Kamu tidak tahu berapa banyak data yang akan disimpan.** Ini adalah keunggulan utama `std::vector`. Misalnya, jika kamu membaca data dari file, kamu tidak tahu berapa banyak baris yang ada di file tersebut. Dengan `std::vector`, kamu bisa menambahkan data satu per satu tanpa khawatir kehabisan ruang.
<br/>

* **Kamu perlu sering menambahkan atau menghapus elemen di akhir.** Operasi menambahkan elemen (`push_back`) di akhir `std::vector` sangatlah cepat dan efisien. Jika kamu sering melakukan ini, `std::vector` adalah pilihan yang tepat.
<br/>

* **Kamu butuh akses acak yang cepat ke elemen.** `std::vector` menyimpan elemennya di memori yang berurutan (contiguous memory), mirip dengan array biasa. Ini memungkinkan kamu mengakses elemen apa pun secara langsung menggunakan indeks, misalnya `my_vector[5]`, dengan sangat cepat.
<br/>

* **Kamu perlu array yang ukurannya bisa diubah-ubah.** Saat membuat array biasa (`int my_array[10];`), ukurannya sudah tetap. Kalau kamu butuh lebih banyak ruang, kamu harus membuat array baru dan menyalin semua elemennya. `std::vector` menangani ini secara otomatis dan efisien saat kamu menambah elemen.
<br/>

* **Kamu ingin menggunakan algoritma standar dari `<algorithm>` atau iterasi berbasis rentang (`range-based for loop`).** Kebanyakan algoritma di C++ Standard Library, seperti `std::sort` atau `std::find`, bekerja dengan sangat baik pada `std::vector` karena strukturnya yang sederhana dan standar.

### 8.2 | Contoh Kapan Tidak Menggunakan `std::vector`?

Ada juga beberapa situasi di mana **ada pilihan yang lebih baik** daripada `std::vector`:

* **Kamu sering menyisipkan atau menghapus elemen di tengah atau di awal.** Operasi ini bisa sangat lambat di `std::vector` karena semua elemen setelahnya harus digeser. Untuk kasus ini, `std::list` atau `std::deque` mungkin lebih cocok.
<br/>

* **Kamu punya data dengan ukuran tetap yang sangat kecil.** Untuk data yang ukurannya sudah diketahui dan tidak akan pernah berubah, `std::array` bisa menjadi pilihan yang lebih baik karena lebih hemat memori dan sedikit lebih cepat.
<br/>

* **Kamu perlu menyimpan data yang sangat besar dan sangat sering melakukan alokasi dan dealokasi memori.** Dalam beberapa kasus ekstrem, jika kamu sering menambah dan menghapus elemen dan programmu sangat sensitif terhadap kinerja alokasi memori, mungkin ada struktur data lain yang lebih dioptimalkan. Namun, ini adalah kasus yang jarang terjadi.

Secara umum, sebagai aturan praktis, **mulailah dengan `std::vector`** . Jika kamu menemukan masalah kinerja atau kebutuhan spesifik yang tidak bisa dipenuhi dengan baik oleh `std::vector` (misalnya, sering menyisipkan elemen di tengah), barulah pertimbangkan struktur data lain.

---
## 9 | Kesimpulan

`std::vector` adalah struktur data yang sangat kuat dan serbaguna dalam C++ Standard Template Library. Kemampuannya untuk menyediakan array dinamis dengan manajemen memori otomatis, penyimpanan elemen yang berurutan, dan integrasi yang mulus dengan algoritma STL menjadikannya pilihan default untuk sebagian besar kebutuhan koleksi data dalam pengembangan C++ modern.

Meskipun array C-style masih memiliki tempatnya dalam skenario kinerja ekstrem atau interaksi API tingkat rendah, `std::vector` menawarkan keseimbangan yang jauh lebih baik antara kinerja, keamanan, dan produktivitas pengembang. Fitur-fitur seperti pemeriksaan batas melalui `at()`, manajemen kapasitas yang cerdas dengan `reserve()`, dan operasi penambahan/penghapusan yang dioptimalkan di akhir, secara signifikan mengurangi kompleksitas dan potensi kesalahan yang terkait dengan manipulasi array manual.

Pemahaman mendalam tentang mekanisme internal `std::vector`, termasuk bagaimana ia menangani realokasi memori dan bagaimana iterator bekerja, memberdayakan pengembang untuk menulis kode yang tidak hanya benar tetapi juga efisien. `std::vector` bukan hanya sekadar "array yang lebih baik"; ini adalah fondasi yang memungkinkan pembangunan struktur data yang lebih kompleks dan penerapan algoritma canggih dengan cara yang idiomatik dan aman di C++. Dengan menguasai `std::vector`, pengembang dapat membangun aplikasi yang tangguh, skalabel, dan berkinerja tinggi.