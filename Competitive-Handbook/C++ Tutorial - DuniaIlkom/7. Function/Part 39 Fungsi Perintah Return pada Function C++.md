---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-09-28T11:13:00
total_study: 1
tags:
  - Cpp
id: DIG3
---
# Tutorial Belajar C++ Part 39: Fungsi Perintah Return pada Function C++

03 Nov 20 

Setelah memahami [Cara Pembuatan Fungsi](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-cara-membuat-fungsi-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 37: Cara Membuat Fungsi (Function) Bahasa C++") serta [Perbedaan Parameter dangan Argumen Fungsi](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-pengertian-parameter-dan-argument-fungsi-c-plus-plus/ "Tutorial Belajar C++ Part 38: Pengertian Parameter dan Argumen Fungsi C++"), pada tutorial belajar bahasa C++ di Duniailkom kali ini kita akan bahas lebih jauh tentang Fungsi Perintah Return di dalam Function.

---

### Pengertian Perintah Return di dalam Function

Pada tutorial sebelumnya kita sudah membuat beberapa function yang ketika di panggil akan langsung menampilkan teks. Berikut contoh yang dimaksud:

```Cpp
#include <iostream>
 
using namespace std;
 
void hitungLuasSegitiga(int alas, int tinggi) {
  double luas = (alas * tinggi) / 2.0;
  cout << "Luas segitiga adalah: " << luas << endl;
}
 
int main()
{
  hitungLuasSegitiga(5, 7);
 
  return 0;
}
```

Hasil kode program:

```
Luas segitiga adalah: 17.5
```

Di baris 12, begitu fungsi **hitungLuasSegitiga(5, 7)** di panggil, akan tampil teks **Luas segitiga adalah: 17.5**

Tidak ada yang salah dari penulisan function seperti ini, hanya saja terasa kurang fleksibel karena tidak selamanya kita ingin menampilkan teks secara langsung.

Dalam banyak situasi, hasil sebuah function perlu disimpan ke dalam variabel terlebih dahulu, untuk kemudian di proses lebih lanjut.

Untuk keperluan inilah kita perlu menambah perintah **return** ke dalam function. Tujuannya, **agar sebuah function bisa mengembalikan nilai**.

Langsung saja kita lihat modifikasi dari function **hitungLuasSegitiga()** dengan penambahan perintah **return**:

```Cpp
#include <iostream>
 
using namespace std;
 
double hitungLuasSegitiga(int alas, int tinggi) {
  double luas = (alas * tinggi) / 2.0;
  return luas;
}
 
int main()
{
  double var1 = hitungLuasSegitiga(5, 7);
  cout << "Luas segitiga adalah: " << var1 << endl;
 
  return 0;
}
```

Hasil kode program:

```
Luas segitiga adalah: 17.5
```

Dalam bahasa C++, tipe data dari nilai yang dikembalikan fungsi harus di tulis di awal pendefinisian. Dalam contoh diatas, tipe data yang dikembalikan oleh function **hitungLuasSegitiga()** ini adalah **double**, yang saya tulis di awal baris 5.

Sebelumnya di awal baris 5 ini terdapat _keyword_ **void** karena function **hitungLuasSegitiga()** tidak memiliki perintah **return**.

Perintah **return** sendiri ada di baris 7, yakni **return luas**. Artinya, kembalikan nilai yang tersimpan di dalam variabel **luas** kepada kode yang akan memanggil function tersebut.

Di baris 12 saya membuat variabel **var1** bertipe _double_ dan mengisinya dari hasil function **hitungLuasSegitiga(5, 7)**. Dengan perintah ini, variabel **var1** akan berisi angka 17.5 yang kemudian ditampilkan dengan perintah **cout**.

Seperti inilah cara penggunaan perintah **return** dalam mengembalikan nilai function.

---

### Mengembalikan Langsung Hasil Operasi

Dalam contoh di atas kita mengembalikan nilai dari variabel. Namun juga bisa langsung mengembalikan nilai yang berasal dari hasil operasi. Perhatikan kode program berikut ini:

```Cpp
#include <iostream>
 
using namespace std;
 
double hitungLuasSegitiga(int alas, int tinggi) {
  return (alas * tinggi) / 2.0;
}
 
int main()
{
  cout << "Luas segitiga adalah: " << hitungLuasSegitiga(5, 7) << endl;
 
  return 0;
}
```

Hasil kode program:

```
Luas segitiga adalah: 17.5
```

Sekarang di baris 6 langsung terdapat perintah **return (alas * tinggi) / 2.0**, tidak perlu lagi menyimpannya ke dalam variabel **luas** terlebih dahulu.

Kemudian di baris 11 pemanggilan function **hitungLuasSegitiga()** juga dilakukan langsung dari dalam perintah cout, yang tidak perlu disimpan ke dalam sebuah variabel.

---

### Hal-hal yang Harus Diperhatikan Untuk Perintah Return

Terdapat beberapa hal yang harus diperhatikan ketika membuat function dengan perintah **return**.

Pertama, tipe data yang dikembalikan **harus sesuai** dengan yang ditulis ketika pendefinisian function. Jika berbeda, akan terjadi error atau (yang sebenarnya lebih parah), dikonversi secara tidak langsung.

Berikut contoh kasusnya:

```Cpp
#include <iostream>
 
using namespace std;
 
int hitungLuasSegitiga(int alas, int tinggi) {
  double luas = (alas * tinggi) / 2.0;
  return luas;
}
 
int main()
{
  cout << "Luas segitiga adalah: " << hitungLuasSegitiga(5, 7) << endl;
 
  return 0;
}
```

Hasil kode program:

```
Luas segitiga adalah: 17
```

Sekarang fungsi **hitungLuasSegitiga** memiliki keyword **int** sebelum penulisan nama fungsi. Ini berarti saya mengharapkan nilai kembalian bertipe **integer**. Akan tetapi variabel **luas** yang di-return bertipe **double**. Maka hasil perhitungan luas akan dikoversi compiler C++ menjadi integer secara bawaan. Dimana **luas** yang seharusnya 17.5 dibulatkan menjadi 17.

Konversi otomatis seperti ini sering menjadi bug karena dalam beberapa aplikasi, perbedaan 0.5 tersebut bisa berakibat fatal. Jadi kita harus hati-hati dengan tipe data kembalian function.

Hal kedua yang harus diperhatikan adalah, perintah **return** berfungsi mirip seperti **break** dalam perulangan. Jika ditemukan perintah **return**, pemrosesan function akan berhenti dan tidak akan mengeksekusi kode dibawahnya:

```Cpp
#include <iostream>
 
using namespace std;
 
double hitungLuasSegitiga(int alas, int tinggi) {
  double luas = (alas * tinggi) / 2.0;
  return luas;
  cout << "Hello Duniailkom";
}
 
int main()
{
  cout << "Luas segitiga adalah: " << hitungLuasSegitiga(5, 7) << endl;
 
  return 0;
}
```

Hasil kode program:

```
Luas segitiga adalah: 17.5
```

Kode program di baris 8 tidak akan pernah dijalankan karena berada setelah perintah **return**.

---

### Contoh Lain Perintah Return C++

Sebagai contoh terakhir, tanpa menjalankan kode program dibawah ini bisakah anda menebak hasil yang tampil?

```Cpp
#include <iostream>
 
using namespace std;
 
int hargaSetelahPajak(int hargaDasar) {
  return hargaDasar + (hargaDasar * 10/100);
}
 
int main()
{
  int hargaCilok = 5000;
  int hargaFinalCilok =  hargaSetelahPajak(hargaCilok);
  cout << "Harga cilok 1 porsi Rp." << hargaFinalCilok << endl;
 
  return 0;
}
```

Di baris 5 – 7 saya mendefinisikan function **hargaSetelahPajak()**. Perintah **int** sebelum nama function menyatakan bahwa function ini akan mengembalikan nilai bertipe **integer**.

Function **hargaSetelahPajak()** butuh 1 parameter **hargaDasar** yang akan di pakai dalam rumus di baris 6, yakni perintah **return hargaDasar + (hargaDasar * 10/100)**. Karena terdapat perintah **return**, maka hasil perhitungan akan dikembalikan kepada kode program yang memanggilnya.

Di function main(), pada baris 11 saya mengisi variabel **hargaCilok** dengan angka **5000**. Selanjutnya di baris 12 juga membuat variabel **hargaFinalCilok** yang diisi dengan hasil dari pemanggilan function **hargaSetelahPajak(hargaCilok)**.

Perintah ini akan mengirim argumen **5000** yang tersimpan di dalam variabel **hargaCilok** ke dalam parameter **hargaDasar** di function **hargaSetelahPajak()**.

Dengan demikian perintah **return** yang dijalankan adalah: **return 5000 + (5000* 10/100)**, yang menghasilkan return **5500** untuk selanjutnya dikembalikan ke variabel **hargaFinalCilok**.

Di baris 12, **hargaFinalCilok** kemudian di input ke dalam perintah **cout** dan menampilkan teks:

```
Harga cilok 1 porsi Rp.5500
```

---

Dalam tutorial C++ kali ini kita telah membahas pengertian perintah return serta contoh penggunaannya.

Mayoritas function akan mengembalikan sebuah nilai, cukup jarang yang langsung menampilkan hasil dalam bentuk teks. Oleh karena itu cara penggunaan perintah return ini wajib untuk dipahami.

Masih membahas tentang function, berikutnya kita akan masuk ke [Pengertian Default Parameter pada Function C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-pengertian-default-parameter-pada-function-c-plus-plus/ "Tutorial Belajar C++ Part 40: Pengertian Default Parameter pada Function C++").