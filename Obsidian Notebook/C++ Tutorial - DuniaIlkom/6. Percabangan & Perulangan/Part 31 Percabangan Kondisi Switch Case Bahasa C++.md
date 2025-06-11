---
obsidianUIMode: preview
sumber: duniailkom
level: pemula
bahasa: C++
tanggal_study: 2024-09-27T20:18:00
total_study: 1
tags:
  - Cpp
id: DIF4
---
# Tutorial Belajar C++ Part 31: Percabangan Kondisi Switch Case Bahasa C++

31 Oct 20 

Kondisi **SWITCH CASE** yang akan kita pelajari ini bisa dipandang sebagai alternatif penulisan dari [kondisi logika IF ELSE IF](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-percabangan-kondisi-if-else-if-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 30: Percabangan Kondisi IF ELSE IF Bahasa C++") pada tutorial C++ sebelumnya. Namun tidak semua kondisi IF ELSE IF bisa dikonversi ke dalam bentuk SWITCH CASE yang kita akan bahas dengan lebih detail.

---

### Pengertian SWITCH CASE Bahasa C++

Kondisi **SWITCH CASE** adalah percabangan kode program dimana kita membandingkan isi sebuah variabel dengan beberapa nilai. Jika proses perbandingan tersebut menghasilkan **true**, maka block kode program akan di proses.

Kondisi **SWITCH CASE** terdiri dari 2 bagian, yakni perintah **SWITCH** dimana terdapat nama variabel yang akan diperiksa, serta 1 atau lebih perintah **CASE** untuk setiap nilai yang akan diperiksa.

Berikut format dasar penulisan kondisi **SWITCH CASE** dalam bahasa C++:

```Cpp
switch (nama_variabel) {
  case 'nilai_1':
    // Kode program yang dijalankan jika nama_variabel == nilai_1
    break;
  case 'nilai_2':
    // Kode program yang dijalankan jika nama_variabel == nilai_2
    break;
  case 'nilai_3':
    // Kode program yang dijalankan jika nama_variabel == nilai_3
    break;
  ...
  ...
  default:
     // Kode program yang dijalankan jika tidak ada kondisi yang terpenuhi
}
```

Di awal kode program, terdapat perintah **SWITCH** untuk menginput variabel yang akan diperiksa. Kemudian terdapat beberapa perintah CASE yang diikuti dengan sebuah nilai.

Jika isi dari **nama_variabel** sama dengan salah satu nilai ini, maka blok kode program akan dijalankan. Jika ternyata tidak ada kondisi CASE yang dipenuhi, blok **default** di baris paling bawah-lah yang akan dijalankan.

Di dalam setiap block case, diakhiri dengan perintah **break** agar struktur **CASE** langsung berhenti begitu kondisi terpenuhi. Mari langsung lihat contoh prakteknya.

---

### Contoh Kode Program SWITCH CASE Bahasa C++

Dalam tutorial sebelumnya, terdapat kode program untuk menampilkan nilai dengan struktur **IF ELSE IF**. Kita akan coba konversi menjadi bentuk **SWITCH CASE**.

Berikut saya tampilkan kembali kode program dengan struktur **IF ELSE IF**:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  char nilai;
 
  cout << "Input Nilai Anda (A - E): ";
  cin >> nilai;
 
  if (nilai == 'A' ) {
    cout << "Pertahankan!" << endl;
  }
  else if (nilai == 'B' ) {
    cout << "Harus lebih baik lagi" << endl;
  }
  else if (nilai == 'C' ) {
    cout << "Perbanyak belajar" << endl;
  }
  else if (nilai == 'D' ) {
    cout << "Jangan keseringan main" << endl;
  }
  else if (nilai == 'E' ) {
    cout << "Kebanyakan bolos..." << endl;
  }
  else {
    cout << "Maaf, format nilai tidak sesuai" << endl;
  }
 
  return 0;
}
```

Program yang sama bisa dikonversi ke dalam bentuk **SWITCH CASE** berikut ini:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  char nilai;
 
  cout << "Input Nilai Anda (A - E): ";
  cin >> nilai;
 
  switch (nilai) {
  case 'A':
    cout << "Pertahankan!" << endl;
    break;
  case 'B':
    cout << "Harus lebih baik lagi" << endl;
    break;
  case 'C':
    cout << "Perbanyak belajar" << endl;
    break;
  case 'D':
    cout << "Jangan keseringan main" << endl;
    break;
  case 'E':
    cout << "Kebanyakan bolos..." << endl;
    break;
  default:
    cout << "Maaf, format nilai tidak sesuai" << endl;
  }
 
  return 0;
}
```

Hasil kode program:

```
Input Nilai Anda (A - E): A
Pertahankan!
 
Input Nilai Anda (A - E): D
Jangan keseringan main
 
Input Nilai Anda (A - E): E
Kebanyakan bolos...
 
Input Nilai Anda (A - E): F
Maaf, format nilai tidak sesuai
```

Di baris 10 terdapat perintah untuk meminta user menginput salah satu huruf antara 'A' – 'E'. Nilai huruf ini kemudian disimpan ke dalam variabel **nilai** yang sudah di set ber tipe data **char**.

Kondisi **SWITCH CASE** dimulai pada baris 12. Di sini terdapat perintah **switch (nilai)** yang artinya kita ingin memeriksa isi dari variabel **nilai**. Seluruh block SWITCH berada di dalam tanda kurung kurawal yang dimulai dari baris 12 sampai 30.

Di baris 13 terdapat perintah **case 'A':** Ini artinya jika variabel **nilai** berisi karakter '**A**', maka jalankan isi dari block CASE, yakni perintah **cout << "Pertahankan!" << endl**. Lalu terdapat perintah **break** di baris 15 agar struktur CASE lain tidak perlu di proses lagi.

Di baris 16 terdapat perintah **CASE** kedua, yakni **case 'B':**. Sama seperti sebelumnya, blok ini akan dijalankan jika variabel **nilai** berisi huruf '**B**'. Demikian seterusnya sampai **case 'E' :** di baris 25.

Jika ternyata tidak ada nilai yang sesuai, maka **block default** di baris 28 yang akan di eksekusi.

Struktur SWITCH CASE ini terlihat lebih rapi daripada struktur IF ELSE IF, dan kadang kala bisa lebih efisien. Namun SWITCH CASE juga memiliki batasan, dimana tidak bisa dipakai untuk kondisi yang lebih kompleks seperti perbandingan dengan tanda lebih besar dari " **>** ", maupun penggabungan kondisi.

Kita tidak bisa membuat struktur **CASE** seperti berikut:

```Cpp
// ini akan error
case > '90':
  cout << "Pertahankan!" << endl;
  break;
```

Kondisi perbandingan di atas hanya bisa ditulis menggunakan struktur IF. Sehingga jika kondisi yang diperiksa cukup rumit, maka terpaksa harus menggunakan struktur IF ELSE IF.

Struktur SWITCH CASE yang kita pelajari kali ini hanya cocok untuk operasi perbandingan sederhana, dimana nilai yang diperiksa hanya terdiri dari nilai yang tetap.

---

Dalam tutorial ini kita telah membahas pengertian dan cara penggunaan struktur SWITCH CASE dalam bahasa pemrograman C++. Selanjutnya akan disambung dengan struktur perulangan (loop), yang diawali dengan [perulangan FOR](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-perulangan-for-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 32: Perulangan FOR Bahasa C++") terlebih dahulu.