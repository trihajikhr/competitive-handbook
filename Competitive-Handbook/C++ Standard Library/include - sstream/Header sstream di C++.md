---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Header sstream di C++
sumber:
  - gemini.google.com
  - google.com
  - cppreference.com
date_learned: 2025-09-19T16:34:00
tags:
  - STL
---
Link Sumber: [Standard library header \<sstream\> - cppreference.com](https://en.cppreference.com/w/cpp/header/sstream.html)

---
# 1 | Header sstream di C++

## 1.1 | Apa itu Header `<sstream>`?

Header `<sstream>` (singkatan dari **String Stream**) adalah bagian dari Standard Library C++ yang menyediakan kelas-kelas untuk melakukan operasi I/O (Input/Output) pada string.  Header ini memungkinkan Anda memperlakukan string seolah-olah mereka adalah **aliran data (stream)** seperti `std::cin` atau `std::cout`. Dengan kata lain, Anda bisa "menulis" data ke dalam sebuah string atau "membaca" data dari sebuah string menggunakan operator `<<` dan `>>`.

Ini sangat berguna untuk **parsing** data dari string atau **memformat** data ke dalam string dengan cara yang familiar dan aman.
## 1.2 | Kelas-Kelas Utama dalam `<sstream>`

Ada tiga kelas utama yang harus Anda ketahui:

1.  **`std::stringstream`**: Ini adalah kelas yang paling sering digunakan. Ia menyediakan aliran data untuk membaca **dan** menulis ke string. Anda bisa memasukkan data ke dalamnya (seperti `cout`) dan mengambil data dari dalamnya (seperti `cin`).

2.  **`std::ostringstream`**: Ini adalah aliran data khusus untuk **menulis** (output) ke string. Jika Anda hanya perlu membuat string dengan menggabungkan beberapa tipe data, ini adalah pilihan yang ideal.

3.  **`std::istringstream`**: Ini adalah aliran data khusus untuk **membaca** (input) dari string. Ini sangat cocok untuk memecah-mecah string menjadi bagian-bagian yang lebih kecil, seperti saat mem-parsing baris data.

<br/>

---
# 2 | Contoh Penggunaan dan Kegunaan Setiap Kelas

## 2.1 | Menggunakan `std::ostringstream` (Output Stream)

**Kegunaan:** Membangun atau memformat sebuah string dari berbagai tipe data (angka, karakter, dll.) dengan mudah dan aman. Ini adalah alternatif yang lebih aman dan fleksibel daripada menggunakan C-style `sprintf`.

**Contoh:** Menggabungkan angka dan teks ke dalam satu string.

```cpp
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    int umur = 30;
    string nama = "Budi";

    ostringstream oss;

    // Menulis data ke dalam stream
    oss << "Nama: " << nama << ", Umur: " << umur << " tahun.";

    // Mendapatkan string hasil
    string hasil_string = oss.str();

    cout << hasil_string << endl;
    // Output: Nama: Budi, Umur: 30 tahun.

    return 0;
}
```

## 2.2 | Menggunakan `std::istringstream` (Input Stream)

**Kegunaan:** Memecah-mecah atau mem-parsing string menjadi token-token (bagian-bagian) berdasarkan spasi atau karakter pemisah lainnya.

**Contoh:** Membaca kata per kata dari sebuah string.

```cpp
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string baris_data = "Apple Orange Banana";
    
    istringstream iss(baris_data);
    string kata;
    
    // Membaca dari stream sampai tidak ada data lagi
    while (iss >> kata) {
        cout << "Kata yang dibaca: " << kata << endl;
    }
    
    return 0;
}
```

**Output:**

```
Kata yang dibaca: Apple
Kata yang dibaca: Orange
Kata yang dibaca: Banana
```

## 2.3 | Menggunakan `std::stringstream` (Input/Output Stream)

**Kegunaan:** Gabungan dari keduanya. Paling sering digunakan ketika Anda perlu memanipulasi string yang sudah ada, seperti membaca data lalu menimpa sebagian darinya.

**Contoh:** Mengonversi string yang berisi angka menjadi tipe data numerik.

```cpp
#include <sstream>
#include <string>
using namespace std;

int main() {
    string str_angka = "12345";
    int angka;

    stringstream ss(str_angka);

    // Membaca string dan memasukkannya ke variabel int
    ss >> angka;

    cout << "String: " << str_angka << ", Tipe data int: " 
         << angka << endl;

    // Menambah 10 ke angka dan memasukkannya kembali ke stream
    ss.str("");  // Membersihkan isi stream
    ss.clear();  // Mengatur ulang status stream
    ss << angka + 10;

    string hasil_akhir = ss.str();
    cout << "Hasil penambahan kembali ke string: " << hasil_akhir 
         << endl;

    return 0;
}
```

Dengan memahami ketiga kelas ini, Anda bisa bekerja dengan manipulasi string dengan cara yang lebih fleksibel dan tipe-safe, menghindari kelemahan dari metode `printf`/`scanf` yang rawan kesalahan.

<br/>

---

# 3 | Fungsi Dalam `sstream`

```ad-faq
oke itu kelasnya, lalu bagaimaan dengan fungsi, apakah ada fungsi atau tidak? dan apakah hanya itu saja yang perlu aku ketahui tentang sstream sebagai awalan?
```

Benar, header `<sstream>` juga memiliki fungsi, tetapi cara kerjanya berbeda dari header seperti `<regex>`. Alih-alih memiliki banyak fungsi global, fungsionalitas utama `<sstream>` justru terintegrasi sebagai **metode** di dalam kelas-kelasnya sendiri (`stringstream`, `ostringstream`, `istringstream`).

Untuk pemula, selain memahami tiga kelas utama tersebut, Anda hanya perlu fokus pada **dua fungsi/metode kunci** yang paling sering digunakan, yaitu `str()` dan `clear()`.
## 3.1 | Fungsi `str()`

**Fungsi:** Metode `str()` digunakan untuk **mengakses** string yang disimpan di dalam objek stream.

- **Untuk `ostringstream` dan `stringstream`**: `str()` mengambil string hasil yang telah Anda bangun di dalam stream.
	
- **Untuk `istringstream`**: `str()` digunakan untuk **mengatur ulang** atau **mengubah** string sumber yang akan dibaca.
	

Contoh:

```cpp
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    // Mengambil string hasil
    ostringstream oss;
    oss << "Hello, " << "World!";
    string hasil = oss.str();  // Mengambil string "Hello, World!"
    cout << hasil << endl;

    // Mengatur ulang string sumber
    istringstream iss("100 200");
    int a, b;
    iss >> a >> b;  // Membaca 100 dan 200
    cout << "Angka 1: " << a << ", Angka 2: " << b << endl;

    // Mengatur ulang string sumber yang akan dibaca
    iss.str("50 60");
    iss.clear();  // Penting! Membersihkan status error.
    int c, d;
    iss >> c >> d;  // Membaca 50 dan 60
    cout << "Angka 3: " << c << ", Angka 4: " << d << endl;

    return 0;
}
```



## 3.2 | Fungsi `clear()`

**Fungsi:** Metode `clear()` digunakan untuk **mengatur ulang status error** dari stream.

**Kegunaan:** Saat Anda melakukan operasi membaca (`>>`), stream bisa memasuki status error (misalnya, saat mencoba membaca `int` dari string yang berisi huruf). Jika ini terjadi, operasi selanjutnya akan gagal. `clear()` akan mengembalikan stream ke kondisi baik, sehingga Anda bisa menggunakan kembali objek yang sama.

**Cara Pakai:** Selalu panggil `clear()` setelah Anda selesai membaca atau jika Anda mengatur ulang string sumber dengan `str()` dan ingin menggunakannya lagi.

Contoh: (Lanjutan dari contoh `str()`)

Tanpa `iss.clear()` setelah `iss.str("50 60")`, pembacaan `iss >> c >> d;` akan gagal karena stream masih dalam kondisi *end-of-file* dari pembacaan sebelumnya.


## 3.3 | Kesimpulan untuk Pemula

Ya, untuk permulaan, cukup itu saja yang perlu Anda ketahui. Fokus pada:

- **Tiga kelas utama** (`ostringstream`, `istringstream`, `stringstream`).
    
- **Dua metode penting** (`str()` dan `clear()`).
    
- **Dua operator dasar** (`<<` untuk menulis dan `>>` untuk membaca).
    

Ini akan memberikan Anda pemahaman yang kuat untuk melakukan konversi tipe data, mem-parsing string, dan memformat teks dengan aman dan efektif.