---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Header regex di C++
sumber:
  - google.com
  - gemini.google.com
  - cppreference.com
date_learned: 2025-09-19T15:09:00
tags:
  - STL
---
Link Sumber: [cppreference regex](https://en.cppreference.com/w/cpp/header/regex.html)

---
# 1 | Header regex di C++

Header `regex` di C++ adalah bagian dari Standard Library C++ yang menyediakan fungsionalitas untuk bekerja dengan **ekspresi reguler (regular expressions)**. Ini memungkinkan Anda mencari, mencocokkan, dan memanipulasi teks berdasarkan pola yang kompleks.

Secara sederhana, `regex` adalah alat yang sangat kuat untuk menangani string.

## 1.1 | Apa Itu Ekspresi Reguler (Regex)?

Bayangkan Anda memiliki sebuah buku tebal dan ingin mencari semua nomor telepon, alamat email, atau tanggal lahir di dalamnya. Melakukan pencarian manual akan sangat melelahkan. Di sinilah **ekspresi reguler** atau **regex** berperan. Regex adalah bahasa mini untuk mendeskripsikan **pola teks**. Pola ini bisa sangat sederhana (misalnya, mencari semua kata yang diawali dengan huruf 's') hingga sangat kompleks (misalnya, memvalidasi format alamat IP).

Header `<regex>` di C++ menyediakan alat-alat yang memungkinkan Anda untuk memanfaatkan kekuatan pola-pola ini dalam program Anda.
## 1.2 | Komponen Utama Header `<regex>`

Ada tiga komponen utama yang perlu Anda pahami untuk menguasai `regex` di C++:

1. **`std::regex`**: Ini adalah "pola" atau "blueprint" yang Anda buat. Anda membuat objek `std::regex` dari string yang berisi pola ekspresi reguler. Pola inilah yang akan digunakan untuk mencari atau mencocokkan teks.
    
2. **`std::smatch`**: Ini adalah "wadah" atau "keranjang" tempat Anda menyimpan hasil dari pencarian. Jika pola regex Anda berhasil menemukan kecocokan dalam sebuah string, detail kecocokan tersebut (seperti string yang cocok, posisi, dan sub-grup) akan disimpan dalam objek `std::smatch`.
    
3. **Fungsi-Fungsi Pencocokan**: Ini adalah "aksi" yang Anda lakukan dengan pola regex Anda. Tiga fungsi utama yang sering digunakan adalah:
    
    - **`std::regex_match()`**: Fungsi ini berfungsi seperti "validasi total". Ia akan memeriksa apakah **seluruh string** yang Anda berikan cocok persis dengan pola regex. Jika ada satu karakter pun yang tidak cocok, ia akan mengembalikan `false`. Ini ideal untuk memvalidasi format input.
    <br/>
    
    - **`std::regex_search()`**: Fungsi ini berfungsi seperti "pencari jarum dalam tumpukan jerami". Ia akan mencari **setidaknya satu kecocokan** dari pola regex di dalam string yang lebih besar. Jika ada kecocokan ditemukan di mana pun dalam string, ia akan mengembalikan `true`.
    <br/>
    
    - **`std::regex_replace()`**: Fungsi ini berfungsi seperti "find and replace" yang Anda temukan di editor teks. Ia akan mencari semua kecocokan pola regex dan menggantinya dengan string lain yang Anda tentukan.
        


```ad-hint
Jika melihat ke dokumentasi C++ seperti di [cppreference.com](https://en.cppreference.com/w/cpp/header/regex.html), maka akan ada banyak komponen yang harus dikenali. Apakah perlu menguasai semuanya?

Tenang, jangan bingung. Daftar panjang di cppreference.com itu adalah **semua** yang ada di dalam header `<regex>`, termasuk kelas dasar yang lebih teknis dan fungsi-fungsi pendukung. Sebagian besar dari itu adalah detail internal yang tidak perlu Anda pakai setiap hari.

Untuk pemula, fokuslah pada **tiga fungsi utama** dan **dua kelas kunci** yang sudah saya jelaskan sebelumnya. Ini adalah inti dari header `regex` yang akan memenuhi 99% kebutuhan Anda.

Anda hanya perlu fokus pada **lima komponen utama** ini:

1. **`std::regex`**: Kelas untuk membuat pola ekspresi reguler.
    
2. **`std::smatch`**: Kelas untuk menyimpan hasil pencocokan.
    
3. **`std::regex_match()`**: Fungsi untuk memeriksa kecocokan **seluruh string**.
    
4. **`std::regex_search()`**: Fungsi untuk mencari kecocokan **pertama** di dalam string.
    
5. **`std::regex_replace()`**: Fungsi untuk mengganti kecocokan yang ditemukan.
    

Kuasi dulu lima hal itu, dan Anda sudah bisa menyelesaikan 99% tugas yang melibatkan `regex`. Elemen-elemen lain di dokumentasi adalah detail teknis yang akan Anda pelajari seiring dengan kebutuhan yang lebih kompleks.
```


<br/>

---
# 2 |  Contoh Penggunaan

Lima komponen yang sudah kita diskusikan adalah fondasi utama untuk bekerja dengan `regex` di C++. Untuk pemula, fokus pada lima hal ini adalah pendekatan paling efektif karena mereka mencakup semua fungsionalitas dasar yang paling sering digunakan, tanpa perlu terjebak dalam detail teknis yang lebih dalam.

## 2.1 | `std::regex`

**Fungsi:** Objek `std::regex` adalah representasi dari pola ekspresi reguler Anda. Ini adalah langkah pertama: mendefinisikan apa yang ingin Anda cari.

**Kegunaan:** Anda menggunakannya untuk membuat "aturan" pencarian, seperti "cari semua kata yang dimulai dengan huruf besar" atau "temukan semua angka".

**Cara Pakai:** Cukup buat objek `std::regex` dan berikan string yang berisi pola regex yang Anda inginkan.

```cpp
#include <regex>
regex pola_email("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");
```

## 2.2 | `std::smatch`

**Fungsi:** `std::smatch` adalah tempat untuk menyimpan hasil pencocokan. Jika `regex` berhasil menemukan pola, detail dari temuan tersebut akan dimasukkan ke dalam objek ini.

**Kegunaan:** Setelah Anda menjalankan pencarian, Anda bisa menggunakan `std::smatch` untuk mengakses string yang cocok, posisi di mana ia ditemukan, atau bagian-bagian spesifik dari pola yang Anda tangkap.

**Cara Pakai:** Deklarasikan objek `std::smatch` dan berikan sebagai parameter dalam fungsi pencarian seperti `std::regex_search` atau `std::regex_match`.

```cpp
smatch hasil_cocok;
if (regex_search(teks, hasil_cocok, pola)) {
    // Akses string yang cocok
    cout << hasil_cocok.str() << endl;
}
```

## 2.3 | `std::regex_match()`

**Fungsi:** Fungsi ini memeriksa apakah **seluruh string** cocok persis dengan pola regex yang diberikan.

**Kegunaan:** Sempurna untuk validasi format yang ketat. Contohnya, untuk memvalidasi apakah input pengguna adalah URL yang valid atau nomor kartu kredit yang sesuai.

**Cara Pakai:** Cukup berikan string target dan objek `std::regex` ke fungsi. Ia akan mengembalikan `true` atau `false`.

```cpp
if (regex_match("https://www.google.com", pola_url)) {
    // String adalah URL yang valid
}
```

## 2.4 | `std::regex_search()`

**Fungsi:** Fungsi ini mencari **satu kecocokan pertama** dari pola regex di dalam string.

**Kegunaan:** Cocok untuk menemukan pola di dalam teks yang lebih besar. Misalnya, menemukan kata pertama yang diapit oleh tanda kutip dalam sebuah paragraf.

**Cara Pakai:** Berikan string target, objek `std::smatch` untuk menyimpan hasil, dan objek `std::regex`. Fungsi ini juga mengembalikan `true` jika kecocokan ditemukan.

```cpp
string paragraf = "Saya suka 'kucing' dan 'anjing'.";
regex pola_kata_dalam_kutip("'(.+?)'"); // Pola regex untuk kata di dalam kutip

smatch hasil;
if (regex_search(paragraf, hasil, pola_kata_dalam_kutip)) {
    cout << "Kata yang ditemukan: " << hasil[1].str() << endl; // hasilnya "kucing"
}
```

## 2.5 | `std::regex_replace()`

**Fungsi:** Fungsi ini mencari dan mengganti **semua kecocokan** dari pola regex dengan string pengganti yang Anda tentukan.

**Kegunaan:** Sangat berguna untuk memanipulasi string secara massal, seperti membersihkan data, mengganti kata-kata, atau memformat ulang teks.

**Cara Pakai:** Berikan string target, objek `std::regex`, dan string pengganti. Fungsi ini mengembalikan string baru yang telah dimodifikasi.

```cpp
string teks = "Nomor telepon saya 123-456-7890.";
regex pola_angka("\\d"); // Ganti semua digit
string teks_baru = regex_replace(teks, pola_angka, "#");
// Hasilnya: "Nomor telepon saya ###-###-####."
```