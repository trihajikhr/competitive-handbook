---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-09-27T20:53:00
total_study: 1
tags:
  - Cpp
id: DIF6
---
# Tutorial Belajar C++ Part 33: Perulangan WHILE Bahasa C++

31 Oct 20 

Melanjutkan tutorial belajar bahasa pemrograman C++ di Duniailkom, kali ini kita akan bahas struktur perulangan (looping) kedua, yakni perulangan **WHILE**.

---

### Pengertian Struktur Perulangan While Bahasa C++

Dalam tutorial sebelumnya tentang [perulangan FOR](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-perulangan-for-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 32: Perulangan FOR Bahasa C++"), kita telah bahas bahwa sebuah perulangan harus memiliki 3 syarat: **kondisi awal perulangan**, **kondisi pada saat perulangan**, dan **kondisi akhir perulangan**.

Dalam perulangan **FOR**, ketiga syarat ini ditulis dalam 1 baris perintah seperti **for (i = 1; i < 5; i++)**. Di dalam perulangan WHILE, ketiga kondisi ini saling terpisah.

Berikut format dasar struktur perulangan **WHILE** dalam bahasa C++:

```Cpp
start;
while (condition) 
{
   // kode program
   // kode program
  increment;
}
```

Di bagian **start** biasanya ditulis perintah inisialisasi variabel counter, misalnya **i = 0**. Di bagian **condition** terdapat kondisi yang harus dipenuhi agar perulangan berjalan, misalnya **i < 5**. Kemudian perintah **increment** harus berada di dalam block perulangan agar bisa menaikkan nilai variabel counter, misalnya dengan perintah **i++**.

Mari kita masuk ke contoh praktek.  

---

### Contoh Kode Program Perulangan While Bahasa C++

Sebagai praktek pertama, berikut kode program perulangan **WHILE** untuk menampilkan teks "**Hello World**" sebanyak 5 kali:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int i = 1;
  while (i <= 5){
    cout << "Hello World" << endl;
    i++;
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

Di baris 7 terdapat perintah untuk menginput angka 1 ke dalam variabel **i**. Nantinya, variabel i ini akan menjadi _variabel counter_ yang dipakai untuk menentukan jumlah perulangan.

Proses perulangan di mulai di baris 8. Perintah **while (i <= 5)** artinya, selama nilai variabel **i** kurang atau sama dengan 5, maka jalankan perulangan.

Di dalam blok perulangan terdapat perintah **cout << "Hello World" << endl** di baris 9. Ini dipakai untuk menampilkan teks "**Hello World**". Kemudian di baris 10 terdapat perintah _increment_, yakni **i++**. Perintah ini akan menaikkan nilai variabel i sebanyak 1 angka dalam setiap iterasi.

Perulangan while akan di ulang sebanyak 5 kali, mulai dari i = 1, i = 2, i = 3, i = 4, hingga i = 5. Ketika nilai _variabel counter_ i sudah mencapai 6, maka kondisi **while (i <= 5)** tidak terpenuhi lagi (**false**), sehingga perulangan berhenti.

Salah satu hal yang harus selalu diingat ketika membuat perulangan while adalah, **jangan lupa membuat perintah increment**. Jika tidak, kondisi akhir tidak akan pernah terpenuhi dan perulangan akan berjalan terus menerus. Ini dikenal dengan istilah **infinity loop**. Berikut contohnya:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int i = 1;
  while (i <= 5){
    cout << "Hello World" << endl;
  }
 
  return 0;
}
```

Jika anda menjalankan kode program di atas, teks "**Hello World**" akan ditampilkan terus menerus, tidak pernah selesai. Penyebabnya adalah karena kondisi **while (i <= 5)** akan selalu bernilai **true**. Di dalam blok perulangan tidak ada perintah yang bisa mengubah nilai variabel i agar kondisi **while (i <= 5)** bernilai **false**.

Untuk menghentikan _infinity loop_, tutup paksa jendela hasil dengan men-klik tanda (x) di sudut kanan atas, atau tekan kombinasi **CTRL + C**.

Sama seperti perulangan **FOR**, di dalam block perulangan **WHILE** kita juga bisa mengakses nilai dari variabel counter **i**:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int i = 1;
  while (i <= 5){
    cout << "Hello World " << i <<endl;
    i++;
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

Bagaimana dengan perulangan menurun? tidak masalah. Kita tinggal mengatur **kondisi awal**, **kondisi akhir**, serta proses **decrement**:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int i = 10;
  while (i > 5){
    cout << "Hello World " << i <<endl;
    i--;
  }
 
  return 0;
}
```

Hasil kode program:

```
Hello World 10
Hello World 9
Hello World 8
Hello World 7
Hello World 6
```

Di sini saya mengisi nilai awal variabel counter **i** dengan angka 10. Kondisi perulangan adalah **while (i > 5)**, artinya selama nilai variabel i di atas 5, jalankan perulangan. Dan karena kita ingin membuat perulangan menurun, maka dipakai perintah decrement **i--** yang akan mengurangi nilai variabel i sebanyak 1 angka dalam setiap iterasi.

Sebagai latihan, silahkan anda coba rancang kode program perulangan **WHILE** untuk membuat deret berikut:

3 6 9 12 15 18 21 24 27 30

Deret ini sudah pernah kita bahasa dalam tutorial perulangan FOR, sekarang tinggal mengkonversinya menjadi perulangan WHILE.

Sebelum menutup tutorial ini, saya ingin membuat tantangan lain. Tanpa menjalankan kode program di bawah ini, bisakah tebak hasilnya?

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int i = 10;
  while (i <= 5){
    cout << "Hello World " << i <<endl;
    i++;
  }
 
  return 0;
}
```

Berapa kali teks "**Hello World**" tampil?

Yup, jawabannya: **Tidak ada**. Alasannya adalah karena kondisi awal perulangan WHILE sudah langsung tidak terpenuhi.

Di baris 7 saya mengisi variabel **i** dengan angka 10. Kemudian terdapat blok perulangan WHILE dengan perintah **while (i <= 5)**. Artinya, selama nilai variabel **i** kurang dari **5**, jalankan perulangan.

Masalahnya, nilai variabel **i** saat ini adalah 10, sehingga **10 <= 5** sudah langsung **false**. Dengan demikian, blok perulangan tidak akan pernah dijalankan.

---

Pada tutorial kali ini kita telah mempelajari cara penggunaan **perulangan while** atau _while_ _loop_ dalam bahasa pemrograman C++. Selanjutnya akan dibahas tentang perulangan ketiga, yakni [Perulangan DO WHILE](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-perulangan-do-while-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 34: Perulangan DO WHILE Bahasa C++").