---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-10-01T22:48:00
total_study: 3
tags:
  - Cpp
id: DID9
---
# Tutorial Belajar C++ Part 19: Tipe Data Enum Bahasa C++

27 Oct 20 

Melanjutkan tutorial belajar bahasa pemrograman C++, kali ini kita akan bahas tentang **tipe data Enum**, termasuk pengertian dan contoh penggunaan tipe data enum.

---

### Pengertian Tipe Data Enum C++

**Tipe data enum** atau **tipe data enumerated** adalah tipe data khusus yang isinya bisa kita tentukan sendiri. Sebagai contoh, kita bisa membuat tipe enum **warna** yang hanya bisa diisi nilai: merah, kuning, biru dan ungu. Atau tipe enum **nama_hari** yang hanya bisa di isi nama-nama hari seperti _senin_, _selasa_, _rabu_, dst.

Setelah di definisikan, data yang bisa diinput hanya nilai yang telah ditentukan saja, tidak bisa di isi nilai lain.

---

### Format Penulisan Tipe Data Enum C++

Sama seperti tipe data **struct**, tipe data **enum** adalah tipe data bentukan. Kita harus buat dulu seperti apa isi komponen dari **enum**, baru kemudian diakses dari function main().

Tipe data **enum** C++ dibuat menggunakan keyword **enum**. Format dasarnya adalah sebagai berikut:

```Cpp
enum nama_tipe {nilai1, nilai2, nilai3... };
```

Sebagai contoh, jika saya ingin membuat tipe enum **nama_hari** yang berisi nama-nama hari, bisa menggunakan perintah berikut:

```Cpp
enum nama_hari {minggu, senin, selasa, rabu, kamis, jumat, sabtu};
```

Dalam kode diatas, enum **nama_hari** terdiri dari nama seperti **minggu**, **senin**, **selasa**… **sabtu**.

Agar bisa dipakai, tipe data enum harus di deklarasikan oleh sebuah variabel di dalam function **main()**. Penjelasan ini akan lebih mudah dengan contoh kode program.

---

### Contoh Kode Program Tipe Data Enum C++

Melanjutkan contoh enum **nama_hari**, berikut kode program lengkap dari penggunaan tipe data enum tersebut:

```Cpp
#include <iostream>
 
using namespace std;
 
enum nama_hari {minggu, senin,selasa,rabu,kamis,jumat,sabtu};
 
int main()
{
  nama_hari var1;
 
  var1 = senin;
  cout << var1 << endl;
 
  var1 = rabu;
  cout << var1 << endl;
 
  var1 = sabtu;
  cout << var1 << endl;
 
  return 0;
}
```

Hasil kode program:

```
1
3
6
```

Dalam kode program ini pendefinisian enum **nama_hari** dilakukan pada baris 5. Kemudian di dalam function main(), variabel **var1** di deklarasikan agar bertipe data **nama_hari** di baris 9. Cara pendeklarasian ini mirip seperti tipe data biasa, hanya saja sekarang menggunakan tipe data enum **nama_hari**.

Selanjutnya **var1** di isi dengan nilai **senin**, **rabu**, dan **sabtu** secara bergantian. Setelah itu isi variabel **var1** ditampilkan dengan perintah **cout**.

Dari hasil kode program, terlihat bahwa nilai yang tersimpan dalam **var1** adalah angka, atau lebih tepatnya index dari posisi setiap nilai tipe data enum.

Sebagai contoh, pada saat pendefinisian enum **nama_hari,** hari senin berada di posisi kedua, yakni di index 1 (ingat, index mulai dari 0). Maka hasil dari **cout << var1** adalah 1. Begitu juga saat **var1** diisi dengan hari sabtu, perintah **cout** menampilkan angka 6.

Ciri khas dari tipe data enum adalah, kita tidak bisa menginput nilai selain yang sudah didaftarkan. Contoh berikut akan menghasilkan error:

```Cpp
#include <iostream>
 
using namespace std;
 
enum nama_hari {minggu, senin,selasa,rabu,kamis,jumat,sabtu};
 
int main()
{
  nama_hari var1;
 
  var1 = monday;   // error: 'monday' was not declared in this scope
  cout << var1 << endl;
 
  return 0;
}
```

Kode program akan error karena saya mencoba mengisi nilai **monday** ke dalam **var1**.

---

### Mengganti Nilai Default Enum

Secara bawaan tipe data enum berisi nilai angka yang menunjukkan nomor index dari nilai tersebut. Kita juga bisa mengganti nilai ini dengan angka lain. Berikut contoh yang dimaksud:

```Cpp
#include <iostream>
 
using namespace std;
 
enum nama_hari {
    minggu = 0,
    senin  = 10,
    selasa = 20,
    rabu   = 30,
    kamis  = 40,
    jumat  = 50,
    sabtu  = 60
};
 
int main()
{
  nama_hari var1;
 
  var1 = senin;
  cout << var1 << endl;
 
  var1 = rabu;
  cout << var1 << endl;
 
  var1 = sabtu;
  cout << var1 << endl;
 
  return 0;
}
```

Hasil kode program:

[![Contoh Kode Program Tipe Data Enum Bahasa C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Tipe-Data-Enum-Bahasa-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Tipe-Data-Enum-Bahasa-C.png)

Sekarang ketika mendefinisikan tipe data **nama_hari**, saya mengisi nilai baru ke masing-masing nama hari. Pada saat di tampilkan, angka inilah yang menjadi nilai dari **var1**, tidak lagi nomor urut index.

---

Dalam tutorial kali ini kita telah membahas tipe data enum dalam bahasa C++. Tipe data ini relatif jarang dipakai, tapi tidak ada salahnya mengetahui fungsi dan cara kerja **enum**.

Selanjutnya, kita akan masuk ke pembatasan tentang [Tipe Data Pointer dalam Bahasa Pemrograman C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-tipe-data-pointer-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 20: Tipe Data Pointer Bahasa C++").