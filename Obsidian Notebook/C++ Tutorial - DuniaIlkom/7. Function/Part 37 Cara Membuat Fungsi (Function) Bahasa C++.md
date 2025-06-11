---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-09-28T10:22:00
total_study: 1
tags:
  - Cpp
id: DIG1
---
# utorial Belajar C++ Part 37: Cara Membuat Fungsi (Function) Bahasa C++

02 Nov 20 |

Dalam merancang kode program, kadang kita sering membuat kode yang melakukan tugas sama secara berulang-ulang, seperti membaca tabel dari database, menampilkan penjumlahan, dll.

Tugas yang sama ini akan lebih efektif jika dipisahkan dari program utama dan dirancang menjadi sebuah **fungsi** atau **function**.

---

### Pengertian Fungsi (Function) dalam Bahasa C++

Secara sederhana, **fungsi** atau **function** adalah _kode program yang dirancang untuk menyelesaikan sebuah tugas tertentu, dan merupakan bagian dari program utama_. Ketika di sadur ke dalam bahasa indonesia, function ini di sebut juga sebagai **fungsi**.

Berdasarkan siapa yang membuat, fungsi bisa dibedakan ke dalam 2 kelompok:

1. **Built-In Function** 
2. **User Defined Function**

**Built-In Function** adalah sebutan untuk fungsi yang sudah ada secara bawaan dari dalam bahasa pemrograman. Sedangkan **User Defined Function** adalah fungsi yang kita (sebagai programmer) membuatnya sendiri.

Bahasa C++ menyediakan banyak fungsi bawaan, belum termasuk yang bisa diakses dari berbagai library atau package pihak ketiga. Sebagai contoh, **main()** adalah function bawaan C++. Namun dalam tutorial kali ini yang akan kita bahas adalah jenis **User Defined Function**.

---

### Cara Membuat Fungsi dalam Bahasa C++

Berikut format dasar cara penulisan fungsi dalam bahasa C++:

```Cpp
tipeDataKembalian namaFunction() {
  // Isi function disini...
  // Isi function disini...
  return nilai;
}
```

Bagian **tipeDataKembalian** diisi dengan tipe data nilai yang dikembalikan sebuah fungsi. Tipe data ini sudah kita pelajari sebelumnya seperti **int**, **double** atau **string**.

Jika suatu fungsi tidak mengembalikan nilai, **tipeDataKembalian** ditulis sebagai **void**. Sebuah fungsi yang tidak mengembalikan nilai kadang disebut juga sebagai **procedure**.

Penulisan **namaFunction** boleh bebas, tidak ada standar penamaan tertentu untuk fungsi bahasa C++ selama mengikuti aturan penulisan identifier, yakni tidak boleh di awali angka dan tidak boleh mengandung spasi.

Beberapa ada yang menyukai menulis dalam **snake_case**, dimana nama fungsi ditulis dalam huruf kecil semua dan setiap kata dipisah dengan underscore " _ ", contohnya seperti `cari_nama_mahasiswa()`, `proses_form_input()` atau `tampilkan_harga_barang()`.

Beberapa ada yang menyukai gaya **camelCase**,dimana karakter pertama nama fungsi ditulis dengan huruf kecil, kemudian setiap karakter pertama kata berikutnya dalam huruf besar. Antar kata tidak boleh mengandung spasi. Contohnya seperti `cariNamaMahasiswa()`, `prosesFormInput()` atau `tampilkanHargaBarang()`.

Setelah penulisan **namaFunction**, terdapat tanda kurung " `()` ". Nantinya tanda kurung ini bisa diisi dengan **parameter atau argumen** (akan kita bahas dalam tutorial setelah ini).

Isi dari function berada dalam tanda kurung kurawal yang bisa terdiri dari 1 sampai ribuan baris kode program tergantung kompleksitas aplikasi yang dibuat.

Jika fungsi tersebut mengembalikan nilai, maka jalankan perintah `return` seperti di baris 4. Mengenai perintah `return` ini akan kita bahas dalam tutorial terpisah.

Pendefinisian **User Defined Function** harus ditulis di luar function **main()** seperti format berikut:

```Cpp
#include <iostream>
 
using namespace std;
 
tipeDataKembalian namaFunction() {
  // Isi function disini...
  // Isi function disini...
  return nilai;
}
 
int main()
{
  // Jalankan function
  namaFunction()
     
  return 0;
}
```

Dalam contoh format di atas, pendefinisian function ada di baris 5 – 9. Ketika sebuah function di definisikan, function tersebut belum berjalan. Disini kita hanya memberitahu compiler bahasa C++ bahwa sebuah function sudah disiapkan.

Agar bisa berjalan, sebuah function harus "dipanggil" dengan cara menulis nama fungsi tersebut di dalam method **main()**. Inilah yang dilakukan oleh perintah di baris 14.

Mari kita lihat contoh praktek dari cara membuat function di C++.

---

### Contoh Kode Program Fungsi Bahasa C++

Dalam kode program berikut ini saya membuat sebuah fungsi`sapaDuniailkom()` yang ketika dijalankan akan menampilkan teks "Halo Duniailkom":

```Cpp
#include <iostream>
 
using namespace std;
 
void sapaDuniailkom() {
  cout << "Halo Duniailkom" << endl;
}
 
int main()
{
  sapaDuniailkom();
  sapaDuniailkom();
  sapaDuniailkom();
 
  return 0;
}
```

Hasil kode program:

```
Halo Duniailkom
Halo Duniailkom
Halo Duniailkom
```

Function `sapaDuniailkom()` tidak mengembalikan nilai, sehingga tipeDataKembalian diisi dengan keyword **void**. Isi dari fungsi `sapaDuniailkom()` sendiri hanya 1 perintah, yakni `cout << "Halo Duniailkom" << endl` seperti di baris 6.

Setelah di definisikan, sebuah fungsi bisa dijalankan berkali-kali, inilah yang saya lakukan antara baris 11 – 13. Setiap kali perintah `sapaDuniailkom()` dijalankan, akan tampil teks "Halo Duniailkom" di layar.

Sebuah kode program bisa saja memiliki banyak fungsi. Berikut contohnya:

```Cpp
#include <iostream>
 
using namespace std;
 
void sapaLisa() {
  cout << "Hai Lisa" << endl;
}
 
void sapaSari() {
  cout << "Morning, Sari" << endl;
}
 
void sapaRudi() {
  cout << "Halo bro,.." << endl;
}
 
int main()
{
  sapaLisa();
  sapaSari();
  sapaRudi();
 
  return 0;
}
```

Hasil kode program:

```
Hai Lisa
Morning, Sari
Halo bro,..
```

Kali ini saya mendefinisikan 3 fungsi di dalam kode program, yakni function `sapaLisa()`, `sapaSari()` dan `sapaRudi()`. Setiap fungsi berisi perintah **cout** yang berbeda-beda.

---

### Variabel di Dalam Function

Untuk fungsi yang kompleks, kita bisa menulis variabel di dalam fungsi tersebut. Berikut contoh penggunaannya:

```Cpp
#include <iostream>
 
using namespace std;
 
void hitungLuasSegitiga() {
  double alas = 5;
  double tinggi = 7;
  double luas = (alas * tinggi) / 2;
  cout << "Luas segitiga adalah: " << luas << endl;
}
 
int main()
{
  hitungLuasSegitiga();
 
  return 0;
}
```

Hasil kode program:

```
Luas segitiga adalah: 17.5
```

Kali ini saya mendefinisikan function `hitungLuasSegitiga()` di baris 5 – 10. Sesuai dengan namanya, fungsi ini dipakai untuk menghitung luas segitiga.

Di dalam fungsi `hitungLuasSegitiga()` terdapat variabel **alas**, **tinggi** dan **luas** yang semuanya bertipe **double**. Variabel alas diisi angka 5 dan variabel tinggi diisi angka 7. Sedangkan variabel luas akan diisi hasil perhitungan (alas * tinggi) / 2, yakni rumus untuk mencari luas segitiga. Kemudian perintah **cout** di baris 9 akan menampilkan hasil perhitungan.

Untuk menjalankan fungsi ini, harus di panggil dengan perintah `hitungLuasSegitiga()` dari dalam function **main()** seperti di baris 14.

---

Dalam tutorial C++ kali ini kita telah berkenalan dengan fungsi atau function, termasuk membahas pengertian fungsi serta cara pembuatan fungsi dalam bahasa C++.

Berikutnya akan dijelaskan tentang [Pengertian Parameter dan Argumen Fungsi](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-pengertian-parameter-dan-argument-fungsi-c-plus-plus/ "Tutorial Belajar C++ Part 38: Pengertian Parameter dan Argumen Fungsi C++").