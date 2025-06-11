---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-09-27T10:47:00
total_study: 1
tags:
  - Cpp
id: DIF2
---
# Tutorial Belajar C++ Part 29: Percabangan Kondisi IF ELSE Bahasa C++

30 Oct 20 

Melanjutkan tutorial belajar bahasa pemrograman C++ di Duniailkom, kali ini kita akan membahas kondisi percabangan selanjutnya, yakni kondisi **IF ELSE**.

---

### Pengertian Kondisi IF ELSE bahasa C++

Pada dasarnya, kondisi **IF ELSE** merupakan modifikasi tambahan dari kondisi IF yang sudah kita pelajari pada tutorial sebelumnya.

Blok kode program **IF** tetap akan dijalankan ketika kondisi **true**, namun sekarang terdapat tambahan bagian **ELSE** akan dijalankan ketika kondisi **false**.

Berikut format dasarnya:

```Cpp
if (condition)
{
  // Kode program yang akan dijalankan jika condition berisi nilai True
}
else
{
  // Kode program yang akan dijalankan jika condition berisi nilai False
}
```

Bagian **condition** berperan sebagai penentu dari struktur percabangan ini. Jika _condition_ terpenuhi (menghasilkan nilai **true**), blok kode program milik **IF** akan dijalankan. Jika _condition_ tidak terpenuhi (menghasilkan nilai **false**), blok kode program bagian **ELSE**-lah yang akan diproses.

Mari kita lihat contoh praktek dari struktur IF ELSE.

---

### Contoh Kode Program Percabangan IF ELSE C++

Pada tutorial sebelumnya kita membuat program penentu bilangan genap / ganjil menggunakan 2 buah kondisi **IF** sebagai berikut:

```Cpp
if (a % 2 == 0) {
  cout << a << " adalah angka genap" << endl;
}
if (a % 2 == 1) {
  cout << a << " adalah angka ganjil" << endl;
}
```

Alur ini sebenarnya akan lebih sederhana (dan lebih efisien) jika diubah ke dalam struktur **IF ELSE**.

Jika sebuah angka tidak genap, maka pasti itu adalah angka ganjil. Sehingga apabila kondisi **if (a % 2 == 0)** tidak terpenuhi (false), maka variabel **a** haruslah berisi angka ganjil. Dengan demikian kode programnya bisa ditulis ulang sebagai berikut:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int a;
 
  cout << "Input sembarang angka bulat: ";
  cin >> a;
 
  if (a % 2 == 0) {
    cout << a << " adalah angka genap" << endl;
  }
  else {
    cout << a << " adalah angka ganjil" << endl;
  }
 
  return 0;
}
```

Sekarang jika kondisi **if (a % 2 == 0)** menghasilkan **false**, bagian **ELSE** lah yang akan di proses. Kode program akan jadi lebih efisien karena pemeriksaan kondisi hanya perlu dilakukan 1 kali saja.

Berikut contoh lain dari struktur kondisi IF ELSE:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int a;
 
  cout << "Input nilai ujian (0 - 100): ";
  cin >> a;
 
  if (a >= 75) {
    cout <<"Selamat, anda lulus!" << endl;
  }
  else {
    cout << "Maaf, silahkan coba lagi tahun depan" << endl;
  }
 
  return 0;
}
```

Hasil kode program:

```
Input nilai ujian (0 - 100): 66
Maaf, silahkan coba lagi tahun depan
 
Input nilai ujian (0 - 100): 92
Selamat, anda lulus!
 
Input nilai ujian (0 - 100): 75 
Selamat, anda lulus!
 
Input nilai ujian (0 - 100): 74 
Maaf, silahkan coba lagi tahun depan
```

Di sini saya membuat kondisi **if (a >= 75)**, yakni jika variabel a berisi angka lebih besar atau sama dengan 75 maka jalankan perintah **cout <<"Selamat, anda lulus!"**. Jika tidak, blok ELSE lah yang akan di eksekusi, yakni **cout << "Maaf, silahkan coba lagi tahun depan"**.

---

Pada tutorial kali ini kita telah membahas kondisi percabangan IF ELSE bahasa C++ yang cocok dipakai jika terdapat 2 kondisi yang saling bertentangan, yakni "Jika kondisi sesuai jalankan kode ini, jika tidak jalankan kode itu".

Berikutnya akan dibahas [kondisi percabangan IF ELSE IF dalam bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-percabangan-kondisi-if-else-if-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 30: Percabangan Kondisi IF ELSE IF Bahasa C++").