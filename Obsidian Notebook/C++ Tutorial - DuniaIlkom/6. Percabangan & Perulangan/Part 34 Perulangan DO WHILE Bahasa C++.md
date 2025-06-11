---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-09-27T21:11:00
total_study: 1
tags:
  - Cpp
id: DIF7
---
# Tutorial Belajar C++ Part 34: Perulangan DO WHILE Bahasa C++

01 Nov 20 

Perulangan DO WHILE dalam banyak hal mirip seperti [perulangan WHILE](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-perulangan-while-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 33: Perulangan WHILE Bahasa C++") yang sudah kita pelajari sebelumnya, namun dengan 1 kunci perbedaan. Apa itu? dalam lanjutan tutorial bahasa pemrograman C++ di Duniailkom kali ini kita akan bahas dengan lebih detail.

---

### Pengertian Struktur Perulangan DO WHILE Bahasa C++

Perulangan **DO WHILE** merupakan modifikasi dari perulangan WHILE, yakni dengan memindahkan posisi pemeriksaan kondisi ke akhir perulangan. Artinya, lakukan dahulu sebuah perulangan, baru periksa apakah kondisi _variabel counter_ sudah terpenuhi atau belum di akhir perulangan.

Berikut format dasar struktur perulangan **DO WHILE** dalam bahasa C++:

```Cpp
start;
do
{
 // kode program
 // kode program
 increment;
} 
while (condition)
```

Sama seperti perulangan WHILE, di bagian **start** biasanya terdapat perintah inisialisasi variabel counter, misalnya **i = 0**. Kemudian di dalam block **do** ditulis kode program yang akan di ulang, tidak lupa sebuah perintah untuk menaikkan nilai variabel counter, misalnya dengan perintah **i++**.

Di bagian paling bawah, terdapat perintah **while (condition)**. Di sinilah kondisi perulangan akan diperiksa. Selama kondisi ini menghasilkan nilai **true**, maka perulangan akan lanjut ke iterasi berikutnya.

---

### Contoh Kode Program Perulangan Do While Bahasa C++

Agar bisa dibandingkan dengan bahasan di tutorial perulangan FOR dan WHILE, berikut contoh kode program bahasa C++ untuk menampilkan 5 kali teks 'Hello World' menggunakan perulangan DO WHILE:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int i = 1;
  do {
    cout << "Hello World" << endl;
    i++;
  }
  while (i <= 5);
 
  return 0;
}
```

Hasil kode program:

```
Hello World
Hello World
Hello World
Hello World
Hello World
```

Di baris 7 saya mendefinisikan variabel counter **i** dan memberikan nilai awal 1.

Kemudian terdapat block kode program **do** di baris 8 – 11. Inilah kode program yang akan di ulang, yakni berisi sebuah perintah **cout << "Hello World" << endl** untuk menampilkan teks 'Hello World', dan sebuah perintah increment **i++** untuk menaikkan nilai variabel **i** sebanyak 1 angka.

Terakhir di baris 12 terdapat perintah **while (i <= 5)**. Artinya, selama variabel counter i bernilai kurang dari atau sama dengan 5, jalankan kembali perulangan.

Dalam perulangan **DO WHILE** kita juga bisa mengakses variabel counter seperti contoh berikut:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int i = 1;
  do {
    cout << i * 3 << " ";
    i++;
  }
  while (i <= 5);
 
  return 0;
}
```

Tanpa menjalankan kode program ini, bisakah anda menebak hasil yang tampil?

Yup, ini adalah kode program untuk membuat sebuah deret dengan kelipatan 3:

```
3 6 9 12 15
```

Kunci utama yang membedakan perulangan DO WHILE dengan perulangan WHILE adalah **posisi pemeriksaan kondisi**.

Karena dalam perulangan DO WHILE pemeriksaan kondisi di lakukan di akhir, maka perulangan akan **selalu di jalankan minimal 1 kali**, meskipun syarat perulangan sudah tidak dipenuhi.

Berikut contoh kasusnya:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int i = 10;
  do {
    cout << i * 3 << " ";
    i++;
  }
  while (i <= 5);
 
  return 0;
}
```

Hasil kode program: **30**.

Di baris 7 saya mengisi angka 10 ke dalam variabel counter i. Namun syarat kondisi adalah **while (i <= 5)**. Apakah i <=5 ? tidak (**false**). Namun meskipun kondisi ini tidak dipenuhi, perulangan akan tetap dijalankan 1 kali.

Jika kondisi yang sama dibuat menggunakan WHILE, perulangan tidak akan pernah dijalankan karena kondisi di periksa di awal. Inilah yang jadi perbedaan antara perulangan WHILE dan DO WHILE dalam bahasa C++.

---

Dalam tutorial ini kita telah membahas prinsip kerja dari perulangan DO WHILE. Berikutnya akan disambung dengan tutorial tentang [penggunakan perintah BREAK dalam perulangan](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-fungsi-dan-pengertian-perintah-break-c-plus-plus/ "Tutorial Belajar C++ Part 35: Fungsi dan Pengertian Perintah BREAK C++").