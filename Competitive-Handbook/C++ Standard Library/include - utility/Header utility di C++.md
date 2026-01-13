---
obsidianUIMode: preview
note_type: book theory
judul_materi: Header utility di C++
sumber:
  - gemini.google.com
  - cplusplus.com
date_learned: 2026-01-13T14:03:00
tags:
  - utility
  - STL
---
Link Sumber: [C++ utility library](https://cplusplus.com/reference/utility/)

---

> [!IMPORTANT]
>  
# Header utility di C++

Header `<utility>` adalah pustaka standar dalam C++ yang berisi kumpulan **komponen pembantu umum**. Header ini tidak fokus pada satu tugas besar (seperti input-output atau matematika), melainkan menyediakan alat-alat kecil yang sering dibutuhkan di hampir seluruh bagian program.

Fungsi utamanya adalah untuk **manajemen objek** dan **efisiensi kode**. Header ini menyediakan struktur data sederhana dan fungsi-fungsi manipulasi objek yang sangat mendasar namun krusial.

Untuk komponen kunci, di dalam header ini, terdapat beberapa fitur yang paling sering digunakan oleh pengembang:

- **Penyimpanan Data:** Menyediakan `std::pair` untuk menggabungkan dua tipe data berbeda.
- **Optimasi (Move Semantics):** Menyediakan `std::move` dan `std::forward` yang sangat penting untuk membuat aplikasi lebih cepat dengan menghindari penyalinan data yang tidak perlu.
- **Manipulasi Objek:** Menyediakan `std::swap` untuk menukar nilai antar variabel secara efisien.
- **Metaprogramming:** Menyediakan alat seperti `std::declval` dan `std::integer_sequence` yang biasanya digunakan dalam pembuatan _template_ yang kompleks.

Mengapa ini penting? Tanpa header ini, Anda harus menulis logika manual untuk hal-hal sederhana seperti menukar nilai atau mengembalikan dua nilai dari fungsi. Dengan `<utility>`, kode Anda menjadi:

- **Lebih Standar:** Mudah dibaca oleh programmer lain.
- **Lebih Aman:** Mengurangi risiko kesalahan logika saat memanipulasi memori atau objek.
- **Lebih Ringan:** Menggunakan teknik modern (seperti _move semantics_) yang menghemat penggunaan RAM.

# Functions Utility
## 1. Fungsi `swap`

`std::swap` adalah fungsi templat yang digunakan untuk menukar nilai atau konten antara dua objek dengan tipe data yang sama. Kegunaan utamanya adalah untuk memindahkan data secara efisien dan aman tanpa harus menulis logika penukaran variabel sementara secara manual di setiap bagian program.

### penerapan kode

```cpp
#include <iostream>
#include <utility>
#include <string>

using namespace std;

int main() {
    int x = 100, y = 500;
    string s1 = "Kiri", s2 = "Kanan";

    // Menukar nilai integer
    swap(x, y);
    // Menukar nilai string
    swap(s1, s2);

    cout << "x: " << x << ", y: " << y << endl;
    cout << "s1: " << s1 << ", s2: " << s2 << endl;

    return 0;
}
```

### kapan menggunakan

Gunakan fungsi ini dalam algoritma pengurutan (seperti *bubble sort* atau *quick sort*) untuk memindahkan posisi elemen. Selain itu, `swap` sangat disarankan saat bekerja dengan objek besar seperti `std::vector` atau `std::string` karena fungsi ini sering kali hanya menukar alamat memori (*pointer*) internalnya saja, sehingga jauh lebih cepat daripada menyalin seluruh isinya.


## 2. Fungsi `make_pair`

`std::make_pair` adalah fungsi templat yang digunakan untuk membuat objek `std::pair` tanpa harus menentukan tipe data secara eksplisit. Kegunaan utamanya adalah menyederhanakan penulisan kode dengan memanfaatkan deduksi tipe otomatis, sehingga memudahkan penggabungan dua nilai berbeda menjadi satu kesatuan.

### penerapan kode

```cpp
#include <iostream>
#include <utility>
#include <string>

using namespace std;

int main() {
    // Membuat pair secara otomatis (int dan string)
    auto data = make_pair(20, "Januari");

    cout << "Angka: " << data.first << endl;
    cout << "Bulan: " << data.second << endl;

    return 0;
}
```

### kapan menggunakan

Gunakan fungsi ini saat Anda ingin mengembalikan dua nilai sekaligus dari sebuah fungsi, atau ketika ingin memasukkan elemen ke dalam struktur data yang membutuhkan pasangan nilai seperti `std::map`. Fungsi ini sangat berguna untuk menjaga kode tetap ringkas dibandingkan memanggil konstruktor `std::pair` secara manual.

## 3. Fungsi `forward`

`std::forward` adalah fungsi templat yang digunakan untuk melakukan *perfect forwarding* (penerusan sempurna). Kegunaan utamanya adalah untuk meneruskan argumen dari satu fungsi ke fungsi lain dengan tetap mempertahankan sifat asli objek tersebut, apakah ia merupakan objek tetap (*lvalue*) atau objek sementara (*rvalue*). Tanpa fungsi ini, argumen yang diteruskan dalam sebuah templat biasanya akan dianggap sebagai *lvalue* biasa.

### penerapan kode

```cpp
#include <iostream>
#include <utility>

using namespace std;

void cek(int& x) { cout << "Lvalue terdeteksi" << endl; }
void cek(int&& x) { cout << "Rvalue terdeteksi" << endl; }

template <typename T>
void pembungkus(T&& arg) {
    // forward memastikan sifat asli arg tetap terjaga
    cek(forward<T>(arg));
}

int main() {
    int a = 10;
    pembungkus(a);    // Mengirim lvalue
    pembungkus(20);   // Mengirim rvalue
    return 0;
}
```

### kapan menggunakan

Gunakan fungsi ini saat Anda membuat fungsi pembungkus (*wrapper*) atau fungsi templat yang harus meneruskan parameter ke fungsi lain tanpa mengubah jenis referensinya. Ini sangat sering digunakan dalam pembuatan *factory pattern* atau konstruktor kelas yang ingin mengoptimalkan performa dengan mendukung *move semantics* secara otomatis.

## 4. Fungsi `move`

`std::move` adalah fungsi templat yang digunakan untuk mengubah sebuah objek menjadi *rvalue reference*. Kegunaan utamanya adalah untuk mengaktifkan **move semantics**, yaitu proses memindahkan hak milik sumber daya (seperti memori dinamis) dari satu objek ke objek lain. Hal ini menghindari proses penyalinan (*copying*) yang lambat dan berat, sehingga meningkatkan performa aplikasi secara signifikan.

### penerapan kode

```cpp
#include <iostream>
#include <utility>
#include <string>
#include <vector>

using namespace std;

int main() {
    string sumber = "Data Penting";
    
    // Memindahkan isi 'sumber' ke 'tujuan'
    string tujuan = move(sumber);

    cout << "Tujuan: " << tujuan << endl;
    cout << "Sumber: " << (sumber.empty() ? "Kosong" : sumber) << endl;

    return 0;
}
```

### kapan menggunakan

Gunakan fungsi ini ketika Anda memiliki objek yang tidak akan digunakan lagi dan ingin memindahkan datanya ke objek baru, seperti saat memasukkan elemen besar ke dalam `std::vector`. Fungsi ini sangat efektif untuk mengoptimalkan transfer objek yang mengelola memori besar (seperti *string*, *vector*, atau *smart pointers*) agar tidak terjadi pemborosan siklus CPU untuk menyalin data yang sama.

## 5. Fungsi `move_if_noexcept`

`std::move_if_noexcept` adalah fungsi kondisional yang akan mengubah objek menjadi *rvalue* hanya jika konstruktor pindah (*move constructor*) dari objek tersebut dijamin tidak akan melempar pengecualian (*noexcept*). Kegunaan utamanya adalah untuk memberikan jaminan keamanan pengecualian (*exception safety*); jika proses pemindahan dianggap berisiko menimbulkan *error*, fungsi ini akan memaksa proses penyalinan (*copy*) biasa sebagai cadangan yang lebih aman.

### penerapan kode

```cpp
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct Data {
    Data() {}
    // Konstruktor pindah dengan jaminan noexcept
    Data(Data&&) noexcept { cout << "Dipindahkan" << endl; }
    // Konstruktor salin
    Data(const Data&) { cout << "Disalin" << endl; }
};

int main() {
    Data d1;
    // Karena Data(Data&&) adalah noexcept, maka akan dipindahkan
    Data d2 = move_if_noexcept(d1);
    
    return 0;
}
```

### kapan menggunakan

Gunakan fungsi ini saat Anda mengimplementasikan struktur data khusus (seperti kontainer dinamis) yang memerlukan operasi pemindahan objek secara massal. Ini sangat penting digunakan untuk menjaga konsistensi data; jika terjadi kegagalan saat memindahkan elemen di tengah jalan, program tetap aman karena data asli tidak rusak atau hilang akibat proses pemindahan yang gagal.

## 6. Fungsi `declval`

`std::declval` adalah fungsi templat yang digunakan untuk memperoleh tipe referensi dari suatu tipe data dalam konteks evaluasi ekspresi, tanpa harus membuat objek nyata atau memanggil konstruktor. Kegunaan utamanya adalah untuk mempermudah pengecekan tipe (*metaprogramming*) pada kelas atau struktur yang tidak memiliki konstruktor standar (default constructor).

### penerapan kode

```cpp
#include <iostream>
#include <utility>

using namespace std;

struct Contoh {
    // Tidak ada konstruktor default
    Contoh(int x) {}
    int ambilNilai() { return 100; }
};

int main() {
    // Mendapatkan tipe data kembalian dari ambilNilai() 
    // tanpa perlu membuat objek 'Contoh' secara nyata
    decltype(declval<Contoh>().ambilNilai()) nilai;

    cout << "Tipe data 'nilai' adalah integer." << endl;
    return 0;
}
```

### kapan menggunakan

Gunakan fungsi ini secara eksklusif di dalam operator `decltype` atau `sizeof` saat melakukan pemrograman templat tingkat lanjut. Fungsi ini sangat membantu ketika Anda perlu mengetahui tipe data kembalian dari sebuah fungsi anggota kelas, namun kelas tersebut sulit atau tidak mungkin diinstansiasi (dibuat objeknya) pada saat kompilasi.

# Types Utility

## 7. Fungsi `pair`

`std::pair` adalah struktur data templat yang digunakan untuk menampung dua objek yang bisa memiliki tipe data berbeda sebagai satu unit tunggal. Kegunaan utamanya adalah untuk mengelompokkan dua data yang saling berhubungan, seperti koordinat ($x$ dan $y$) atau pasangan kunci dan nilai (*key-value pair*), tanpa harus membuat struktur kelas atau *struct* baru secara manual.
### penerapan kode

```cpp
#include <iostream>
#include <utility>
#include <string>

using namespace std;

int main() {
    // Inisialisasi pair dengan tipe int dan string
    pair<int, string> mahasiswa(10, "Budi");

    // Mengakses elemen menggunakan .first dan .second
    cout << "Nomor Absen: " << mahasiswa.first << endl;
    cout << "Nama: " << mahasiswa.second << endl;

    // Mengubah nilai
    mahasiswa.first = 11;
    return 0;
}
```

### kapan menggunakan

Gunakan `std::pair` ketika Anda memerlukan fungsi yang dapat mengembalikan dua nilai sekaligus secara efisien. Selain itu, fungsi ini sangat sering digunakan sebagai elemen dasar dalam kontainer `std::map` untuk menyimpan pasangan kunci dan data, atau saat Anda ingin menyimpan data asosiatif sederhana secara cepat dalam program.

## 8. Fungsi `piecewise_construct_t`

`std::piecewise_construct_t` adalah tipe tag kosong yang digunakan untuk memilih versi konstruktor khusus pada `std::pair`. Kegunaan utamanya adalah untuk memungkinkan pembuatan objek di dalam `pair` (baik elemen pertama maupun kedua) secara langsung di tempat (*in-place*) dengan meneruskan argumen ke konstruktor masing-masing objek, alih-alih membuat objek sementara lalu menyalinnya.

### penerapan kode

```cpp
#include <iostream>
#include <utility>
#include <tuple>
#include <string>

using namespace std;

struct Pesan {
    Pesan(int id, string isi) {
        cout << "Pesan dibuat dengan ID: " << id << " dan Isi: " << isi << endl;
    }
};

int main() {
    // Menggunakan piecewise_construct untuk membangun objek 'Pesan' di dalam pair
    pair<int, Pesan> p(piecewise_construct,
                       forward_as_tuple(1),              // Argumen untuk int
                       forward_as_tuple(101, "Halo"));   // Argumen untuk Pesan

    return 0;
}
```

### kapan menggunakan

Gunakan fungsi ini (bersama dengan konstanta `std: :piecewise_construct`) ketika salah satu atau kedua elemen dalam `pair` adalah objek kompleks yang tidak memiliki konstruktor salin (*copy constructor*) atau ketika Anda ingin menghindari biaya performa dari pembuatan objek sementara. Ini sangat umum digunakan saat memanggil fungsi `emplace` pada kontainer seperti `std::map`.

# Constants Utility

## 9. Fungsi `piecewise_construct`

`std::piecewise_construct` adalah objek konstanta dari tipe `std::piecewise_construct_t` yang berfungsi sebagai sinyal bagi konstruktor `std::pair`. Kegunaan utamanya adalah untuk menginstruksikan `std::pair` agar membangun elemen-elemennya secara langsung menggunakan argumen yang disediakan dalam bentuk `std::tuple`, sehingga menghindari pembuatan objek sementara dan proses penyalinan yang tidak perlu.

### penerapan kode

```cpp
#include <iostream>
#include <utility>
#include <tuple>
#include <string>

using namespace std;

struct Koordinat {
    Koordinat(int x, int y) {
        cout << "Koordinat dibuat: " << x << ", " << y << endl;
    }
};

int main() {
    // Membangun pair secara bertahap tanpa membuat objek Koordinat terlebih dahulu
    pair<string, Koordinat> data(
        piecewise_construct,
        forward_as_tuple("Titik_A"),      // Argumen untuk elemen pertama (string)
        forward_as_tuple(10, 20)          // Argumen untuk elemen kedua (Koordinat)
    );

    return 0;
}

```

### kapan menggunakan

Gunakan fungsi ini ketika Anda bekerja dengan objek di dalam `pair` yang memiliki konstruktor dengan banyak parameter atau objek yang tidak dapat disalin (*non-copyable*). Ini adalah teknik optimasi yang sangat penting saat menggunakan fungsi `emplace` pada kontainer seperti `std::map`, guna memastikan efisiensi memori yang maksimal saat penyisipan data baru.
# Namespaces Utility

## 10. Fungsi `rel_ops`

`std::rel_ops` adalah sebuah *namespace* khusus di dalam header `<utility>` yang berisi templat operator relasional. Kegunaan utamanya adalah untuk secara otomatis menghasilkan operator perbandingan seperti `!=`, `>`, `<=`, dan `>=` hanya dengan mendefinisikan dua operator dasar saja, yaitu $==$ (sama dengan) dan `<` (kurang dari).

### penerapan kode

```cpp
#include <iostream>
#include <utility>

using namespace std;
using namespace std::rel_ops; // Mengaktifkan rel_ops

struct Kotak {
    int sisi;
    // Cukup definisikan dua operator ini
    bool operator==(const Kotak& data) const { return sisi == data.sisi; }
    bool operator<(const Kotak& data) const { return sisi < data.sisi; }
};

int main() {
    Kotak k1 = {10}, k2 = {20};

    // Operator != dan > otomatis tersedia berkat rel_ops
    if (k1 != k2) cout << "Kotak tidak sama" << endl;
    if (k2 > k1)  cout << "Kotak 2 lebih besar" << endl;

    return 0;
}

```

### kapan menggunakan

Gunakan `rel_ops` jika Anda ingin menghemat waktu saat menulis kelas yang memerlukan dukungan perbandingan lengkap namun ingin menghindari penulisan kode berulang untuk setiap operator. Perlu dicatat bahwa dalam C++20 ke atas, penggunaan `rel_ops` mulai digantikan oleh operator *spaceship* (`<=>`), namun `rel_ops` masih sangat berguna pada standar C++ yang lebih lama.