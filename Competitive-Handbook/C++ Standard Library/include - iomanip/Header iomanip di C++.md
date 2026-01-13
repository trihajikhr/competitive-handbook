---
obsidianUIMode: preview
note_type: book theory
judul_materi: Header iomanip di C++
sumber:
  - google.com
  - cplusplus.com
  - gemini.google.com
date_learned: 2026-01-13T14:42:00
tags:
  - STL
  - strings
---
Link Sumber: [C++ iomanip library](https://cplusplus.com/reference/iomanip/)

---

> [!IMPORTANT]
>  
# Header iomanip di C++

`iomanip` (singkatan dari *Input/Output Manipulation*) adalah library standar dalam C++ yang digunakan untuk mengontrol format tampilan data pada layar atau file. Jika header `iostream` menyediakan fungsi dasar untuk input-output, maka `iomanip` memberikan kendali presisi atas **bagaimana** data tersebut ditampilkan secara visual kepada pengguna.

Library ini berisi kumpulan fungsi yang disebut **manipulator**. Kegunaan utamanya meliputi:

* **Mengatur Lebar Kolom:** Merapikan data agar sejajar secara vertikal.
* **Mengatur Presisi Desimal:** Menentukan berapa banyak angka di belakang koma untuk tipe data *floating-point*.
* **Mengatur Perataan Teks:** Membuat teks rata kiri, rata kanan, atau mengisi ruang kosong dengan karakter tertentu.
* **Konversi Basis Bilangan:** Menampilkan angka dalam format desimal, heksadesimal, atau oktal secara instan.

Mengapa Ini Penting? Tanpa `iomanip`, tampilan *output* program Anda akan terlihat berantakan karena setiap data memiliki panjang karakter yang berbeda. Library ini sangat krusial dalam pembuatan laporan tabel, aplikasi keuangan yang butuh ketelitian angka, serta antarmuka berbasis teks (CLI) agar terlihat profesional dan mudah dibaca.

# Parametric manipulators
## 1. Fungsi `setiosflags`

`std::setiosflags` adalah manipulator yang digunakan untuk mengaktifkan satu atau lebih format tampilan (*flags*) tertentu pada aliran *output* (stream). Kegunaan utamanya adalah untuk memberikan instruksi format secara spesifik, seperti menampilkan tanda plus pada angka positif, mengatur perataan teks, atau memaksa angka desimal selalu muncul, dengan menggunakan konstanta dari `std::ios_base`.

### penerapan kode

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double angka = 123.45;

    // Mengaktifkan flag 'showpos' (tanda positif) dan 'scientific'
    cout << setiosflags(ios::showpos | ios::scientific);
    cout << angka << endl; // Output: +1.234500e+02

    return 0;
}
```

### kapan menggunakan

Gunakan fungsi ini ketika Anda perlu mengaktifkan beberapa aturan format secara bersamaan dalam satu baris perintah `cout`. Ini sangat berguna dalam aplikasi teknik atau ilmiah yang membutuhkan format angka yang sangat spesifik (seperti notasi sains) yang tidak diaktifkan secara standar oleh C++.

## 2. Fungsi `resetiosflags`

`std::resetiosflags` adalah manipulator yang digunakan untuk mematikan atau mengatur ulang format tampilan (*flags*) yang sebelumnya telah diaktifkan pada aliran *output*. Kegunaan utamanya adalah untuk mengembalikan perilaku standar tampilan data atau menghapus format spesifik (seperti notasi ilmiah atau perataan tertentu) sehingga tidak memengaruhi baris kode *output* berikutnya.

### penerapan kode

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double angka = 12.34;

    // Aktifkan tanda plus (+) dan notasi ilmiah
    cout << setiosflags(ios::showpos | ios::scientific);
    cout << "Format aktif: " << angka << endl;

    // Matikan tanda plus (+) dan notasi ilmiah menggunakan resetiosflags
    cout << resetiosflags(ios::showpos | ios::scientific);
    cout << "Format reset: " << angka << endl;

    return 0;
}
```

### kapan menggunakan

Gunakan fungsi ini ketika Anda ingin membatasi jangkauan format tertentu agar tidak bersifat permanen pada seluruh program. Ini sangat penting dalam aplikasi yang memiliki berbagai jenis tampilan data dalam satu layar, di mana Anda perlu beralih dari format angka akuntansi atau ilmiah kembali ke tampilan angka biasa tanpa harus menutup dan membuka kembali aliran data.

## 3. Fungsi `setbase`

`std::setbase` adalah manipulator yang digunakan untuk mengubah basis bilangan yang digunakan saat menampilkan angka bulat pada aliran *output*. Kegunaan utamanya adalah untuk melakukan konversi tampilan angka secara instan ke dalam basis desimal (basis 10), oktal (basis 8), atau heksadesimal (basis 16) tanpa perlu melakukan perhitungan manual.

### penerapan kode

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int angka = 255;

    cout << "Desimal: " << setbase(10) << angka << endl;
    cout << "Oktal: " << setbase(8) << angka << endl;
    cout << "Heksadesimal: " << setbase(16) << angka << endl;

    return 0;
}
```

### kapan menggunakan

Gunakan fungsi ini saat Anda bekerja dengan pemrograman sistem, debugging alamat memori, atau pengolahan data digital yang memerlukan representasi angka dalam format non-desimal. Fungsi ini lebih fleksibel dibandingkan menggunakan `std::hex` atau `std::oct` jika Anda ingin mengubah basis angka secara dinamis di dalam satu perintah aliran data.

## 4. Fungsi `setfill`

`std::setfill` adalah manipulator yang digunakan untuk menentukan karakter pengisi (padding) pada ruang kosong yang dihasilkan oleh fungsi `setw`. Kegunaan utamanya adalah mengganti karakter spasi standar dengan karakter pilihan Anda (seperti titik, nol, atau tanda hubung) untuk mempercantik atau memperjelas tampilan data pada kolom yang memiliki lebar tetap.

### penerapan kode

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Menampilkan angka dengan awalan angka 0 (seperti pada format waktu)
    cout << setfill('0') << setw(5) << 42 << endl;  // Output: 00042

    // Menampilkan daftar harga dengan titik-titik
    cout << setfill('.') << "Harga" << setw(10) << 5000 << endl; // Output: Harga......5000

    return 0;
}
```

### kapan menggunakan

Gunakan fungsi ini ketika Anda ingin membuat format laporan yang membutuhkan keseragaman visual, seperti mencetak struk belanja, format waktu (jam:menit:detik), atau pengisian nomor seri yang harus memiliki jumlah digit tetap. `setfill` sangat efektif untuk memastikan bahwa data yang lebih pendek tetap sejajar dan memiliki tampilan yang konsisten dengan data lainnya.

## 5. Fungsi `setprecision`

`std::setprecision` adalah manipulator yang digunakan untuk menentukan jumlah digit yang ditampilkan pada nilai pecahan (*floating-point*). Kegunaan utamanya adalah untuk mengontrol tingkat ketelitian angka desimal agar *output* tetap rapi dan sesuai dengan kebutuhan presisi data, baik dalam format jumlah digit total maupun jumlah angka di belakang koma.

### penerapan kode

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double pi = 3.1415926535;

    // Mengatur presisi total (3 digit)
    cout << setprecision(3) << pi << endl; // Output: 3.14

    // Mengatur presisi tetap (fixed) 4 angka di belakang koma
    cout << fixed << setprecision(4) << pi << endl; // Output: 3.1416

    return 0;
}
```

### kapan menggunakan

Gunakan fungsi ini dalam aplikasi keuangan untuk membatasi dua angka di belakang koma (seperti format mata uang), atau dalam aplikasi perhitungan ilmiah yang memerlukan akurasi tinggi. `setprecision` sangat penting untuk mencegah tampilan angka desimal yang terlalu panjang yang dapat merusak tata letak tabel atau antarmuka pengguna.

## 6. Fungsi `setw`

`std::setw` (singkatan dari *set width*) adalah manipulator yang digunakan untuk menetapkan lebar bidang minimum untuk operasi *output* berikutnya. Kegunaan utamanya adalah untuk mengatur jarak atau lebar kolom pada tampilan teks, sehingga data yang berbeda panjangnya dapat ditampilkan secara sejajar dan rapi dalam format tabel atau kolom.

### penerapan kode

```cpp
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    // Membuat header tabel dengan lebar kolom 10 karakter
    cout << left << setw(10) << "NAMA" << setw(10) << "SKOR" << endl;
    cout << setfill('-') << setw(20) << "" << setfill(' ') << endl;

    // Mengisi data tabel
    cout << left << setw(10) << "Budi" << setw(10) << 85 << endl;
    cout << left << setw(10) << "Siti" << setw(10) << 100 << endl;

    return 0;
}
```

### kapan menggunakan

Gunakan fungsi ini setiap kali Anda perlu menampilkan data dalam bentuk daftar atau tabel pada terminal (CLI). `setw` sangat krusial digunakan bersama dengan manipulator perataan seperti `std::left` atau `std::right` untuk memastikan teks dan angka tidak berantakan saat panjang karakter data bervariasi. Perlu diingat bahwa `setw` hanya berlaku untuk satu operasi *output* tepat setelahnya, sehingga harus dipanggil berulang kali untuk setiap kolom.

## 7. Fungsi `get_money`

`std::get_money` adalah manipulator input yang digunakan untuk membaca nilai mata uang dari aliran *input* (*stream*) ke dalam variabel bertipe `long double` atau `std::string`. Kegunaan utamanya adalah untuk memproses input mata uang secara otomatis sesuai dengan aturan lokal (*locale*) yang aktif, termasuk menangani simbol mata uang, pemisah ribuan, dan pemisah desimal.

### penerapan kode

```cpp
#include <iostream>
#include <iomanip>
#include <locale>

using namespace std;

int main() {
    long double jumlah;
    // Mengatur locale ke Amerika Serikat (menggunakan simbol $)
    cin.imbue(locale("en_US.UTF-8"));

    cout << "Masukkan jumlah uang (contoh: $1,234.56): ";
    cin >> get_money(jumlah);

    if (cin.fail()) {
        cout << "Format salah!" << endl;
    } else {
        cout << "Nilai mentah yang dibaca: " << jumlah << endl;
    }

    return 0;
}

```

### kapan menggunakan

Gunakan fungsi ini saat Anda membangun aplikasi keuangan yang membutuhkan input data moneter dari pengguna dalam berbagai format negara. `get_money` sangat efektif karena Anda tidak perlu membedah string secara manual untuk membuang simbol mata uang atau tanda koma; fungsi ini akan mengekstrak nilai numeriknya secara langsung berdasarkan pengaturan *locale* yang Anda tetapkan.

## 8. Fungsi `put_money`

`std::put_money` adalah manipulator output yang digunakan untuk menampilkan nilai numerik ke dalam format mata uang yang sesuai dengan aturan lokal (*locale*). Kegunaan utamanya adalah untuk mengubah angka mentah (seperti `123456`) menjadi tampilan mata uang yang rapi lengkap dengan simbol (seperti `$`, `Rp`), pemisah ribuan, dan posisi desimal sesuai standar negara tertentu.

### penerapan kode

```cpp
#include <iostream>
#include <iomanip>
#include <locale>

using namespace std;

int main() {
    long double nilai = 12345678; // Merepresentasikan 123456.78

    // Menggunakan locale Amerika Serikat (USD)
    cout.imbue(locale("en_US.UTF-8"));
    cout << "Format US: " << put_money(nilai) << endl;

    // Menggunakan locale Jerman (EUR)
    cout.imbue(locale("de_DE.UTF-8"));
    cout << "Format Jerman: " << put_money(nilai) << endl;

    return 0;
}

```

### kapan menggunakan

Gunakan fungsi ini ketika Anda ingin menampilkan laporan keuangan atau harga produk yang mendukung banyak mata uang internasional (*internationalization*). Dengan `put_money`, Anda tidak perlu menulis logika manual untuk menempatkan simbol mata uang atau tanda titik/koma ribuan, karena semuanya sudah diatur secara otomatis oleh sistem berdasarkan lokasi pengguna.

## 9. Fungsi `get_time`

`std::get_time` adalah manipulator input yang digunakan untuk membaca string waktu dan tanggal dari aliran *input* dan menyimpannya ke dalam struktur `std::tm`. Kegunaan utamanya adalah untuk melakukan penguraian (*parsing*) format waktu yang bervariasi (seperti "2026-01-13" atau "14:30") secara otomatis sesuai dengan format yang ditentukan, tanpa perlu memproses string secara manual.

### penerapan kode

```cpp
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int main() {
    struct tm waktu_input = {};
    cout << "Masukkan tanggal (format HH:BB:TTTT): ";
    
    // Membaca input string dan mengubahnya ke struktur tm
    cin >> get_time(&waktu_input, "%d:%m:%Y");

    if (cin.fail()) {
        cout << "Format waktu salah!" << endl;
    } else {
        cout << "Tahun yang dibaca: " << (1900 + waktu_input.tm_year) << endl;
    }

    return 0;
}

```

### kapan menggunakan

Gunakan fungsi ini saat aplikasi Anda memerlukan input tanggal atau jam dari pengguna melalui terminal, seperti sistem reservasi atau pencatatan data log. `get_time` sangat memudahkan validasi input karena jika string yang dimasukkan tidak sesuai dengan pola format (misalnya huruf dimasukkan pada kolom tanggal), fungsi ini akan secara otomatis menandai aliran data sebagai gagal (*fail bit*).

## 10. Fungsi `put_time`

`std::put_time` adalah manipulator output yang digunakan untuk menampilkan isi dari struktur waktu `std::tm` menjadi string teks dengan format yang dapat disesuaikan. Kegunaan utamanya adalah untuk mengubah data waktu mentah dari sistem menjadi format yang mudah dibaca oleh manusia, seperti tanggal lengkap, jam digital, atau nama hari, menggunakan kode format standar (seperti `%Y` untuk tahun atau `%H` untuk jam).

### penerapan kode

```cpp
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int main() {
    // Mendapatkan waktu sistem saat ini
    time_t t = time(nullptr);
    tm* sekarang = localtime(&t);

    // Menampilkan waktu dengan format: Hari, Tanggal Bulan Tahun Jam:Menit:Detik
    cout << "Waktu sekarang: " 
         << put_time(sekarang, "%A, %d %B %Y %H:%M:%S") << endl;

    return 0;
}
```

### kapan menggunakan

Gunakan fungsi ini ketika Anda perlu menampilkan informasi waktu pada laporan, log sistem, atau antarmuka pengguna yang memerlukan estetika tertentu. `put_time` sangat fleksibel karena memungkinkan Anda mengubah tampilan waktu tanpa harus mengubah data aslinya, cukup dengan mengganti kode format string yang digunakan sesuai standar `strftime`.