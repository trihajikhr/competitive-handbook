---
obsidianUIMode: preview
sumber: duniailkom
level: pemula
bahasa: C++
tanggal_study: 2024-10-01T22:44:00
total_study: 4
tags:
  - Cpp
id: DIC3
---
# Tutorial Belajar C++ Part 7: Pengertian Variabel dalam Bahasa C++

19 Oct 20 

Melanjutkan tutorial belajar bahasa pemrograman C++ di Duniailkom, kali ini kita akan bahas **Pengertian Variabel dalam Bahasa C++**. Selain itu akan di jelaskan juga cara penulisan variabel beserta proses deklarasi dan inisialisasi.

---

### Pengertian Variabel dalam Bahasa C++

**Variabel** adalah penanda identitas yang digunakan untuk menampung suatu nilai.

Secara teknis, variabel merujuk ke sebuah alamat di memory komputer (RAM). Ketika kita membuat sebuah variabel, satu 'slot' memory akan disiapkan untuk menampung nilai tersebut. Setiap variabel memiliki nama yang dipakai sebagai identitas variabel.

Sesuai dengan namanya, isi variabel bisa berubah sepanjang kode program. Sebagai contoh, jika saya membuat program menghitung luas persegi, maka bisa menyiapkan variabel **panjang** dan **lebar** yang diisi angka 10 dan 12. Nantinya isi variabel **panjang** dan **lebar** bisa ditukar dengan angka 35, 40, atau angka lain.

Variabel juga biasa dipakai untuk menampung nilai inputan, misalnya jika kita ingin nilai **panjang** dan **lebar** diisi oleh user (pengguna aplikasi). Terkait tentang cara input data ke dalam kode program C++ akan kita bahas dalam tutorial terpisah.

Untuk definisi yang lebih teknis, berikut pengertian **variabel** dari [Wikipedia](https://en.wikipedia.org/wiki/Variable_(computer_science)):

"_Variable is a storage location (identified by a memory address) paired with an associated symbolic name, which contains some known or unknown quantity of information referred to as a value_".

Terjemahan bebas:

"_Variabel adalah lokasi penyimpanan (satu alamat di memory) yang diwaliki oleh sebuah nama. Variabel berisi nilai yang jumlahnya sudah atau belum diketahui_".

---

### Aturan Penamaan Variabel dalam Bahasa C++

Aturan penamaan variabel merujuk ke syarat **identifier** yang pernah kita bahas pada tutorial sebelumnya, yakni [Aturan Dasar Penulisan Kode Program Bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-aturan-dasar-penulisan-kode-program-c-plus-plus/ "Tutorial Belajar C++ Part 6: Aturan Dasar Penulisan Kode Program C++").

Berikut saya sajikan kembali aturan penamaan variabel di dalam bahasa pemrograman C++:

- Variabel bisa terdiri dari huruf, angka dan karakter underscore / garis bawah ( _ ).
- Karakter pertama dari variabel hanya boleh berupa huruf dan underscore ( _ ), tidak bisa berupa angka. Meskipun dibolehkan, sebaiknya tidak menggunakan karakter underscore sebagai awal dari variabel karena bisa bentrok dengan beberapa variabel settingan program.
- Variabel harus selain dari _keyword_. Sebagai contoh, kita tidak bisa memakai kata **int** sebagai nama variabel, karena **int** merupakan _keyword_ untuk menandakan tipe data **integer**.
- Beberapa compiler bahasa C++ ada yang membatasi panjang variabel maksimal 31 karakter. Agar lebih aman, sebaiknya tidak menulis nama variabel yang lebih dari 31 karakter.

---

### Cara Penulisan Variabel di dalam bahasa C++

Untuk menulis variabel, dalam hampir semua bahasa pemrograman terdapat 2 langkah: **deklarasi** dan **inisialisasi**.

**Deklarasi** adalah proses untuk memberitahu _compiler_ C++ bahwa kita akan membuat sebuah variabel. Bahasa C++ termasuk bahasa pemrograman yang menggunakan konsep **strongly typed programming language**, yang artinya untuk setiap variabel harus ditulis akan berisi tipe data apa. Apakah itu angka bulat (_integer_), angka pecahan (_float / double_), huruf (_char_), atau yang lain.

Pembahasan mengenai tipe data yang ada di dalam C++ akan kita bahas dalam tutorial tersendiri, namun berikut tipe data yang sering dipakai:

- **Tipe data integer**, yakni tipe data angka bulat seperti 1, 5 atau 1000. Tipe data integer ditulis dengan keyword **int**.
- **Tipe data double**, yakni tipe data angka pecahan seperti 1.33,  5.90 atau 1000.99. Tipe data double ditulis dengan keyword **double**.
- **Tipe data character**, yakni tipe data huruf seperti 'A', 'a', atau 'Z'. Tipe data character ditulis dengan keyword **char**.
- **Tipe data string**, yakni tipe data untuk menampung kumpulan karakter, seperti "Belajar", "Duniailkom" atau "Belajar bahasa C++ di Duniailkom". Tipe data string ditulis dengan keyword **string**.

Sebagai contoh, dalam kode program berikut saya **mendeklarasikan** 4 buah variabel:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int hasil;
  double ipk;
  char kelas;
  string kegiatan;
 
  return 0;
}
```

Di baris 7, perintah **int hasil** akan membuat variabel **hasil** dengan tipe data **int**. Artinya variabel **hasil** hanya bisa diisi oleh angka bulat.

Kemudian di baris 8 variabel **ipk** bertipe **double**, yang bisa menampung angka pecahan. Di ikuti variabel **kelas** bertipe **char** untuk menampung 1 karakter. Dan terakhir variabel **kegiatan** bertipe **string** yang bisa diisi dengan 1 teks kalimat.

Setelah sebuah variabel di deklarasikan, kita bisa menginput atau memberikan nilai awal ke dalam variabel tersebut. Proses pemberian nilai awal ini dikenal dengan istilah **inisialisasi**.

Nilai yang diberikan harus sesuai dengan tipe data. Misalnya variabel **hasil** bertipe **int**, maka hanya bisa diisi dengan angka bulat saja. Berikut contoh proses **deklarasi** dan **inisialisasi** dari kode sebelumnya:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int hasil;
  double ipk;
  char kelas;
  string kegiatan;
 
  hasil = 10;
  ipk = 2.89;
  kelas = 'B';
  kegiatan = "Belajar Bahasa C++ di Duniailkom";
 
  return 0;
}
```

Sekarang masing-masing variabel sudah berisi nilai (baris 12 – 15).

Tanda sama dengan ( = ) berfungsi sebagai **operator assignment**, yakni operator yang akan mengisi sebuah nilai. Proses assignment dilakukan **dari kanan ke kiri**. Perintah **hasil = 10** artinya memasukkan angka **10** ke dalam variabel **hasil**.

Untuk menampilkan isi dari variabel, kita bisa pakai perintah **cout** seperti contoh berikut:

![[Part 7 Pengertian Variabel dalam Bahasa C++.png]]

Proses deklarasi dan inisialisasi variabel juga bisa dilakukan sekaligus dalam 1 baris statement:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int hasil = 10;
  double ipk = 2.89;
  char kelas = 'B';
  string kegiatan = "Belajar Bahasa C++ di Duniailkom";
 
  cout << hasil;
  cout << "\n";
 
  cout << ipk;
  cout << "\n";
 
  cout << kelas;
  cout << "\n";
 
  cout << kegiatan;
  cout << "\n";
 
  return 0;
}
```

Sekarang setiap variabel sudah berisi nilai awal, yang berasal dari gabungan proses **deklarasi** dan **inisialisasi**.

Kita juga bisa mendeklarasikan beberapa variabel dalam 1 baris perintah, selama variabel tersebut memiliki **tipe data yang sama**:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int a, b, c;
  a = 12;
  b = 3;
  c = 56;
 
  cout << a;
  cout << "\n";
 
  cout << b;
  cout << "\n";
 
  cout << c;
  cout << "\n";
 
  return 0;
}
```

Hasil kode program:

```
12
3
56
```

Setelah variabel di deklarasikan dan diberikan nilai awal, nilai tersebut bisa ditimpa atau ditukar sepanjang kode program:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int a, b, c;
  a = 3;
  b = a;
  a = a + b;
  c = b + b + a;
 
  cout << a;
  cout << "\n";
 
  cout << b;
  cout << "\n";
 
  cout << c;
  cout << "\n";
 
  return 0;
}
```

Bisakah anda tebak apa hasil akhir dari variabel **a**, **b**, dan **c**?

Diawal kode program, saya mendeklarasikan 3 buah variabel: **a**, **b**, dan **c**. Ketiga variabel bertipe **integer** yang bisa menampung angka bulat. Variabel **a** kemudian diisi dengan angka **3** dengan perintah **a = 3**.

Di baris berikutnya terdapat perintah **b = a**, artinya variabel **b** akan diisi dengan nilai dari variabel **a** (ingat, proses assignment berlaku dari kanan ke kiri). Karena variabel **a** berisi angka **3**, maka variabel **b** juga akan berisi angka **3**.

Selanjutnya terdapat perintah **a = a + b**. Kembali, proses pemberian nilai (assignment) akan dilakukan dari sisi kanan tanda sama dengan terlebih dahulu.

Berapakah hasil dari **a + b**? karena **a** dan **b** sama-sama bernilai **3**, maka hasilnya adalah **6**. Angka enam ini akan menjadi nilai baru untuk variabel **a**. Nilai variabel **a** yang sebelumnya **3**, akan tertimpa menjadi **6**.

Proses terakhir adalah  **c = b + b + a**. Kembali, kita selesaikan dulu perhitungan di sisi kanan, yakni **b + b + a**. Variabel **b** saat ini bernilai **3**, sedangkan variabel **a** sudah bernilai **6** akibat perintah sebelumnya. Sehingga proses yang terjadi adalah **3 + 3 + 6 = 12**. Angka **12** ini akan menjadi nilai inputan untuk variabel **c**.

Dari penjelasan diatas, maka variabel **a** akan berisi angka **6**, variabel **b** angka **3**, dan variabel **c** angka **12**. Mari kita buktikan dengan menjalankan kode program tersebut:

![[Part 7 Pengertian Variabel dalam Bahasa C++-1.png]]

Ok, hasilnya sesuai dengan perhitungan.

---

Dalam tutorial kali ini kita telah pelajari pengertian variabel dan cara penulisan variabel dalam bahasa pemrograman C++. Berikutnya saya akan bahas tentang [Pengertian Konstanta dalam Bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-pengertian-konstanta-dalam-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 8: Pengertian Konstanta dalam Bahasa C++").