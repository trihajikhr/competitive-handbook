---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-09-27T13:12:00
total_study: 1
tags:
  - Cpp
id: DIF3
---
# Tutorial Belajar C++ Part 30: Percabangan Kondisi IF ELSE IF Bahasa C++

30 Oct 20 

Masih tentang kondisi percabangan kode program dengan perintah IF, kali ini akan kita bahas bentuk yang lebih kompleks, yakni kondisi **IF ELSE IF**. Struktur ini tidak lain terdiri dari gabungan beberapa kondisi IF ELSE yang saling bersambung.

---

### Pengertian Kondisi IF ELSE IF Bahasa C++

Pada dasarnya, kondisi **IF ELSE IF** adalah sebuah struktur logika program yang di dapat dengan cara menyambung beberapa perintah **IF ELSE** menjadi sebuah kesatuan.

Jika kondisi pertama tidak terpenuhi atau bernilai **false**, maka kode program akan lanjut ke kondisi **IF** di bawahnya. Jika ternyata tidak juga terpenuhi, akan lanjut lagi ke kondisi **IF** di bawahnya lagi, dst hingga blok **ELSE** terakhir atau terdapat kondisi **IF** yang menghasilkan nilai **true**.

Berikut format dasar penulisan kondisi **IF ELSE IF** dalam bahasa C++:

```Cpp
if (condition_1) {
  // Kode program yang dijalankan jika condition_1 berisi nilai True
}
else if (condition_2) {
  // Kode program yang dijalankan jika condition_2 berisi nilai True
}
else if (condition_3) { 
  // Kode program yang dijalankan jika condition_3 berisi nilai True 
}
else  { 
  // Kode program yang dijalankan jika semua kondisi tidak terpenuhi
}
```

Mari kita lihat contoh prakteknya.  

---

### Contoh Kode Program Percabangan IF ELSE IF C++

Sebagai contoh pertama, saya ingin membuat kode program untuk menampilkan nilai. User diminta menginput sebuah huruf antara 'A' – 'E'. Kemudian program akan menampilkan hasil yang berbeda-beda untuk setiap huruf, termasuk jika huruf tersebut di luar 'A' – 'E'.

Berikut contoh kode programnya:

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

Di baris 7 saya mendefinisikan sebuah variabel **nilai** sebagai **char**. Variabel **nilai** ini kemudian dipakai untuk menampung input dari perintah **cin >> nilai** di baris 10. Ini adalah proses input nilai char dalam bahasa C++.

Mulai dari baris 12 hingga 29 terdapat 5 kali pemeriksaan kondisi, yakni satu untuk setiap block **IF ELSE**. Dalam setiap kondisi, isi variabel **nilai** akan di diperiksa apakah berisi karakter 'A', 'B', hingga 'E'. Jika salah satu kondisi terpenuhi, maka block kode program yang sesuai akan di eksekusi.

Jika ternyata nilai inputan bukan salah satu dari karakter 'A' – 'E', maka **block ELSE** di baris 28 lah yang akan dijalankan.

Setiap kondisi dari **block IF ELSE IF** bisa diisi dengan perbandingan yang lebih kompleks, seperti contoh berikut:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  short nilai;
 
  cout << "Input Nilai Anda (0 - 100): ";
  cin >> nilai;
 
  if (nilai >= 90 ) {
    cout << "Pertahankan!" << endl;
  }
  else if (nilai >= 80 && nilai < 90) {
    cout << "Harus lebih baik lagi" << endl;
  }
  else if (nilai >= 60 && nilai < 80) {
    cout << "Perbanyak belajar" << endl;
  }
  else if (nilai >= 40 && nilai < 60) {
    cout << "Jangan keseringan main" << endl;;
  }
  else if (nilai < 40) {
    cout << "Kebanyakan bolos..." << endl;
  }
  else {
    cout << "Maaf, format nilai tidak sesuai" << endl;
  }
 
  return 0;
}
```

Di sini saya memodifikasi sedikit kode program sebelumnya. Sekarang nilai inputan berupa angka antara 0 hingga 100.

Angka inputan ini ditampung ke dalam variabel **nilai** yang sekarang di set sebagai tipe data **short** di baris 7. Tipe data **short** adalah salah satu tipe data angka bulat (integer) dalam bahasa C++ yang bisa menampung antara -32,768 hingga +32,767.

Di baris 12, variabel **nilai** di periksa apakah berisi angka yang lebih dari 90. Jika iya, tampilkan teks **"Pertahankan!"**.

Jika kondisi di baris 12 tidak terpenuhi (yang artinya isi variabel **nilai** kurang dari 90), maka kode program akan lanjut ke kondisi **ELSE IF** berikutnya di baris 15. Di sini saya menggabung dua buah kondisi pemeriksaan dengan operator logika **&&** (operator **AND**). Kondisi **if(nilai >= 80 && nilai < 90)** hanya akan terpenuhi jika isi variabel **nilai** berada dalam rentang 80 sampai 89.

Ketika membuat kondisi perbandingan, kita harus hati-hati dengan penggunaan tanda, apakah ingin menggunakan tanda lebih besar saja (>) atau tanda lebih besar sama dengan (>=) karena bisa mempengaruhi hasil akhir.

Jika ternyata kondisi ini tidak dipenuhi juga (artinya isi variabel **nilai** kurang dari 80), program akan lanjut ke kondisi **if(nilai >= 60 && nilai < 80)** di baris 18, yakni apakah isi variabel **nilai** berada dalam rentang 60 – 79. Demikian seterusnya hingga kondisi terakhir **if(nilai < 40)** di baris 24.

Jika semua kondisi tidak terpenuhi, jalankan **block ELSE** di baris 27.

Berikut hasil percobaan dari kode program di atas:

```
Input Nilai Anda (0 - 100): 92
Pertahankan!
 
Input Nilai Anda (0 - 100): 60
Perbanyak belajar
 
Input Nilai Anda (0 - 100): 30
Kebanyakan bolos...
```

Yang cukup unik adalah, jika kita memberikan nilai di luar rentang 0 – 100, akan tetap ditangkap oleh kondisi **IF** di baris 10 atau di baris 22:

```
Input Nilai Anda (0 - 100): 190
Pertahankan!
 
Input Nilai Anda (0 - 100): -100
Kebanyakan bolos...
```

Ini terjadi karena nilai 190 tetap memenuhi syarat **if (nilai >= 90)**, dan nilai -100 juga tetap memenuhi syarat **if (nilai < 40)**. Silahkan anda modifikasi kode program di atas agar ketika diinput angka di luar dari rentang 0 – 100, tampil teks **"Maaf, format nilai tidak sesuai"**. Untuk hal ini kita cuma perlu mengubah / menambah 2 kondisi saja.

---

Dalam tutorial belajar C++ kali ini kita telah membahas konsep struktur **IF ELSE IF** tidak lain terdiri dari beberapa kondisi IF yang saling bersambung.

Berikutnya, akan dilanjutkan ke [struktur kondisi SWITCH](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-percabangan-kondisi-switch-case-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 31: Percabangan Kondisi Switch Case Bahasa C++") yang dalam banyak hal merupakan alternatif penulisan dari kondisi **IF ELSE IF** yang baru saja kita pelajari.