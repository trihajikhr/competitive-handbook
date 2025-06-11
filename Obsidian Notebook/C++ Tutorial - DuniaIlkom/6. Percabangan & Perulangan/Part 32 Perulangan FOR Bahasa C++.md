---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-09-27T20:32:00
total_study: 1
tags:
  - Cpp
id: DIF5
---
# Tutorial Belajar C++ Part 32: Perulangan FOR Bahasa C++

31 Oct 20 

Dalam bahasa C++ (dan juga bahasa turunan C seperti Java, PHP dan JavaScript), terdapat 3 buah **struktur perulangan** atau **looping**, yakni **perulangan for**, **perulangan while** dan **perulangan do while**.

Dalam tutorial bahasa pemrograman C++ kali ini kita akan bahas perulangan for terlebih dahulu.

---

### Pengertian Struktur Perulangan For Bahasa C++

**Struktur perulangan** (atau dalam bahasa inggris disebut **loop**) adalah instruksi kode program yang bertujuan untuk mengulang beberapa baris perintah.

Dalam merancang perulangan for, setidaknya kita harus mengetahui 3 komponen:

1. Kondisi **awal perulangan**.
2. Kondisi pada **saat perulangan**.
3. Kondisi yang harus dipenuhi agar **perulangan** **berhenti**.

Berikut format dasar struktur perulangan **for** dalam bahasa C++:

```Cpp
for (start; condition; increment) 
{
   // kode program
   // kode program
}
```

**Start** adalah kondisi pada saat awal perulangan. Biasanya kondisi awal ini berisi perintah untuk memberikan nilai kepada **variabel counter**. _Variabel counter_ sendiri adalah sebuah variabel yang menentukan berapa banyak perulangan dilakukan. Kebanyakan programmer menggunakan variabel **i** sebagai variabel counter (ini tidak harus, boleh juga memakai variabel lain).

**Condition** adalah kondisi yang harus dipenuhi agar perulangan berjalan. Selama kondisi ini terpenuhi, maka _compiler_ bahasa C++ akan terus melakukan perulangan. Misalnya _condition_ ini berisi perintah **i < 7**, maka selama _variabel counter_ **i** berisi angka yang kurang dari 7, terus lakukan perulangan.

**Increment** adalah bagian yang dipakai untuk memproses variabel counter agar bisa memenuhi kondisi akhir perulangan. Bagian ini akan selalu di eksekusi di setiap perulangan.

Disebut _increment_ karena biasanya berisi operasi increment seperti **i++**, yang sebenarnya sama dengan **i = i + 1**. Maksudnya, dalam setiap perulangan naikkan variabel i sebanyak 1 angka. Namun kita juga bisa memberikan nilai lain seperti **i = i + 2** sehingga variabel counter akan naik 2 angka setiap perulangan

Sebagai tambahan, terdapat istilah **iterasi** (_iteration_), yang berarti 1 kali perulangan. Istilah ini cukup sering dipakai ketika membahas tentang struktur perulangan.

Baik, cukup dengan teorinya mari kita masuk ke contoh praktek.  

---

### Contoh Kode Program Perulangan For Bahasa C++

Sebagai contoh pertama, saya ingin menampilkan teks  "**Hello World**" sebanyak 5 kali. Berikut kode programnya:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int i;
  for (i = 1; i < 5; i++) {
    cout << "Hello World " << endl;
  }
 
  return 0;
}
```

Di baris 7 saya membuat sebuah variabel **i** yang di set dengan tipe data **integer**. Variabel ini nantinya akan dipakai sebagai **variabel counter**, yakni variabel yang menentukan kondisi akhir perulangan.

Perintah di baris 8, yakni **for (i = 1; i < 5; i++)**, bisa dibaca:

_"Jalankan perulangan, mulai dari variabel **i = 1** sampai **i < 5**. Dalam setiap iterasi, naikkan nilai variabel i sebanyak 1 angka menggunakan perintah **i++**"._

Berikut hasilnya:

```
Hello World
Hello World
Hello World
Hello World
```

Pertanyaannya, kenapa hanya tampil 4 baris "**Hello World**"? Padahal kita mengulang dari **i = 1** sampai **i < 5**.

Ini berkaitan dengan penggunaan tanda. Kondisi akhir perulangan adalah **i < 5**, yang artinya akan selalu bernilai **true** jika i kurang dari 5, tapi jika sudah sampai dengan 5 maka kondisi menjadi **false** dan perulangan berhenti.

Agar teks "**Hello World**" bisa tampil sebanyak 5 kali, ada 2 alternatif. Yakni bisa dengan mengubah kondisi awal menjadi **i = 0**, atau mengubah kondisi akhir menjadi **i <= 5**. Pilihan kedua ini terlihat lebih baik:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int i;
  for (i = 1; i <= 5; i++) {
    cout << "Hello World " << endl;
  }
 
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

Sekarang teks "**Hello World**" sudah tampil sebanyak 5 kali. Sekali lagi, hati-hati dengan menggunakan tanda perbandingan, terutama antara "**<**" dengan "**<=**".

Di dalam perulangan, kita juga bisa mengakses _variabel counter_ seperti contoh berikut:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int i;
  for (i = 1; i <= 5; i++) {
    cout << "Hello World " << i << endl;
  }
 
  return 0;
}
```

Hasil kode program:

```
Hello World 1
Hello World 2
Hello World 3
Hello World 4
Hello World 5
```

Sekarang setelah teks "**Hello World**", tampil angka yang berasal dari nilai variabel i. Karena dalam setiap iterasi variabel counter **i** akan naik 1 angka (proses _increment_), maka ketika ditampilkan juga akan naik 1 angka untuk setiap iterasi.

Variabel counter i juga tidak harus di increment, tapi juga bisa di _decrement_ untuk membuat perulangan menurun. Berikut contohnya:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int i;
  for (i = 5; i >= 1; i--) {
    cout << "Hello World " << i << endl;
  }
 
  return 0;
}
```

Hasil kode program:

```
Hello World 5
Hello World 4
Hello World 3
Hello World 2
Hello World 1
```

Kode kita sangat mirip seperti sebelumnya, tapi perhatikan perintah for di baris 8: **for (i = 5; i >= 1; i–-)**. Ini bisa dibaca:

_"Jalankan perulangan, mulai dari variabel **i = 5** sampai **i >= 1**. Dalam setiap iterasi, turunkan nilai variabel i sebanyak 1 angka menggunakan perintah_ ***i--***_"._

Hasilnya, nilai variabel counter i akan berkurang 1 angka dalam setiap iterasi.

Sebagai contoh terakhir, bisakah anda membuat perulangan untuk menampilkan angka kelipatan 3 sebanyak 10 kali? Hasil akhir yang kita inginkan adalah sebagai berikut:

```
3 6 9 12 15 18 21 24 27 30
```

Terdapat beberapa cara untuk menghasilkan deret ini. Pertama, ubah di sisi block perintah yang akan dijalankan. Dimana variabel counter i tetap naik dari 1 sampai 10:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int i;
  for (i = 1; i <= 10; i++) {
    cout << i*3 << " ";
  }
 
  return 0;
}
```

Agar menghasilkan angka yang naik kelipatan 3, teknik yang dipakai adalah mengalikan nilai variabel counter i dengan angka 3 untuk setiap iterasi.

Cara kedua adalah memodifikasi proses _increment_ dari variabel counter:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int i;
  for (i = 3; i <= 30; i = i + 3) {
    cout << i << " ";
  }
 
  return 0;
}
```

Perhatikan perintah perulangan for di baris 8. Perintah **for (i = 3; i <= 30; i = i + 3)** bisa dibaca:

_"Jalankan perulangan, mulai dari variabel **i = 3** sampai **i <= 30**. Dalam setiap iterasi, naikkan nilai variabel i sebanyak 3 angka menggunakan perintah **i = i + 3**"._

Teknik ini agak jarang dipakai, tapi itu bisa dilakukan.

---

Dalam tutorial kali ini kita telah membahas tentang perulangan (looping) for. Nantinya looping ini bisa dikombinasikan lebih lanjut misalnya untuk membuat perulangan bersarang (_nested loop_).

Tapi untuk tutorial berikutnya kita akan lanjut dulu ke bentuk perulangan kedua dalam bahasa C++, yakni [perulangan WHILE](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-perulangan-while-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 33: Perulangan WHILE Bahasa C++").