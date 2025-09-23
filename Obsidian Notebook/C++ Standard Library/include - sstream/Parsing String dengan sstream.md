---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Parsing String dengan sstream
sumber:
  - gemini.google.com
date_learned: 2025-09-19T17:02:00
tags:
  - tips-trick
  - string
---
Link Sumber: 

---
# Parsing String dengan sstream

**Parsing string** adalah proses **menganalisis sebuah string** untuk mengenali struktur dan komponennya berdasarkan aturan tertentu (_grammar_ atau _format_), lalu mengubahnya menjadi representasi data yang lebih terstruktur (misalnya angka, token, atau objek).

Dalam konteks pemrograman:

- **Input**: deretan karakter (string mentah).
- **Proses**: string dianalisis sesuai delimiter/aturan sintaks.
- **Output**: potongan data (_token_) yang siap digunakan (misalnya `int`, `double`, atau kata kunci).

Oke, sekarang mari kita bahas cara mem-parsing string dengan spasi sebagai pemisah, yang merupakan kasus paling sederhana.
## 1 | Parsing String dengan Spasi Menggunakan `std::istringstream`

Untuk memecah string menjadi token-token (kata-kata) berdasarkan spasi, Anda dapat menggunakan kelas **`std::istringstream`** dan operator ekstraksi (`>>`). Operator ini secara default mengenali whitespace (spasi, tab, newline) sebagai pemisah. Ini adalah metode yang paling mudah dan umum digunakan.

### 1.1 | Cara Kerjanya

1. Buat objek `std::istringstream` dan inisialisasikan dengan string yang ingin Anda parsing.
    
2. Gunakan loop `while` yang membaca dari `istringstream` ke dalam variabel string (`string kata`).
    
3. Operator `>>` akan membaca data dari stream hingga menemukan spasi. Bagian string yang dibaca akan disimpan ke variabel `kata`.
    
4. Loop akan terus berjalan selama masih ada data yang berhasil dibaca. Ketika tidak ada lagi kata yang bisa diekstrak, loop akan berhenti secara otomatis.
    
### 1.2 | Contoh Kode Lengkap

Berikut adalah contoh program yang mem-parsing string `salam` dengan spasi.

```cpp
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string kalimat = "Halo nama saya Budi.";
    istringstream iss(kalimat); // Inisialisasi istringstream dengan kalimat
    
    string kata;
    
    // Loop untuk membaca setiap kata dari stream
    while (iss >> kata) {
        cout << "Kata yang dibaca: " << kata << endl;
    }
    
    return 0;
}
```

**Output:**

```
Kata yang dibaca: Halo
Kata yang dibaca: nama
Kata yang dibaca: saya
Kata yang dibaca: Budi.
```

Pada contoh di atas, operator `>>` membaca setiap kata dan menyimpannya ke variabel `kata` hingga string habis. Ini sangat efisien dan merupakan pendekatan terbaik untuk mem-parsing string yang dipisahkan oleh spasi.

## 2 | Parsing String dengan Pemisah Khusus

Sebelumnya kita telah melihat bahwa penggunaan `sstream` untuk memparsing dan membuild string dengan mudah menggunakan operaor `>>` dan `<<` dengan menjadikan spasi  (' ') sebagai pemisahnya. Pertanyaanya sekarang adalah, apakah selain menggunakan spasi sebagai pemisah, bisa juga menggunakan karakter lain?

Jawabanya adalah ya.

Untuk mem-parsing string dengan pemisah selain spasi atau koma, Anda tidak bisa hanya mengandalkan operator `>>` bawaan dari `stringstream`. Ada dua teknik utama yang bisa Anda gunakan:

### 2.1 | Menggunakan `std::getline()`

Ini adalah cara paling umum dan efisien untuk mem-parsing string dengan pemisah apa pun. Fungsi `getline()` mengambil tiga argumen:

- **`std::istream& is`**: Objek stream dari mana data akan dibaca (misalnya, `istringstream`).
    
- **`std::string& str`**: Variabel string tempat data yang telah dipisahkan akan disimpan.
    
- **`char delim`**: Karakter pemisah yang Anda inginkan (misalnya, `;`, `|`, atau `-`).
    

**Contoh:** Parsing string dengan pemisah titik koma (`;`).

```cpp
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string data = "apel;jeruk;pisang";
    istringstream iss(data);
    string buah;

    while (getline(iss, buah, ';')) {
        cout << "Buah: " << buah << endl;
    }
    return 0;
}
```

**Kelebihan:**

- **Sangat efisien**: Ini adalah solusi paling langsung dan berkinerja tinggi untuk tugas ini.
    
- **Sederhana**: Kode yang diperlukan sangat ringkas dan mudah dipahami.
    
- **Kontrol penuh**: Anda memiliki kendali penuh atas karakter pemisah.
    

### 2.2 | Menggabungkan `sstream` dengan `regex`

Untuk skenario yang lebih kompleks, seperti memisahkan string berdasarkan pola yang tidak seragam (misalnya, spasi atau tanda hubung), Anda dapat menggunakan `std::regex_replace()` untuk menstandarisasi string terlebih dahulu sebelum mem-parsingnya.

**Contoh:** Mengubah tanda hubung (`-`) menjadi spasi, lalu mem-parsing string.

```cpp
#include <iostream>
#include <sstream>
#include <string>
#include <regex>
using namespace std;

int main() {
    string data = "umur-25-berat-70";
    // Ganti semua tanda hubung dengan spasi
    string data_bersih = regex_replace(data, regex("-"), " ");

    istringstream iss(data_bersih);
    string kata;

    cout << "Hasil parsing:" << endl;
    while (iss >> kata) {
        cout << kata << endl;
    }
    return 0;
}
```

**Kelebihan:**

- **Fleksibel**: Mampu menangani pola pemisah yang lebih kompleks dan beragam.
    
- **Mudah dibaca**: Memisahkan proses pembersihan string dari proses parsing.
    

Kesimpulan:

Untuk sebagian besar kasus parsing dengan pemisah khusus, `std::getline()` adalah pilihan terbaik. Jika Anda membutuhkan fleksibilitas ekstra untuk membersihkan string dari pola yang lebih rumit, menggabungkannya dengan `regex_replace()` adalah strategi yang sangat kuat.