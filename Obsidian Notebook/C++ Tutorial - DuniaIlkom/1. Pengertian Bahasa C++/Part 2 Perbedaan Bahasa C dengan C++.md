---
obsidianUIMode: preview
sumber: duniailkom
level: pemula
bahasa: C++
tanggal_study: 2024-10-01T19:59:00
total_study: 3
tags:
  - Cpp
id: DIA2
---
# Tutorial Belajar C++ Part 2: Perbedaan Bahasa C dengan C++

16 Oct 20 

Bahasa pemrograman C++ adalah pengembangan dari bahasa pemrograman C. Oleh karena itu sangat menarik untuk melihat apa perbedaan antara kedua bahasa ini.

---

### Perbedaan Paradigma Pemrograman antara C dan C++

Perbedaan paling utama antara bahasa C dengan C++ ada di **paradigma pemrograman**, atau bisa disebut juga sebagai cara penulisan kode program.

Bahasa C menggunakan paradigma **procedural programming**, dimana untuk menulis program yang kompleks, kode akan dipecah menjadi function-function yang saling terpisah untuk kemudian disatukan di dalam kode program utama.

Keunggulan dari procedural programming adalah mudah dipelajari terutama bagi pemula. Namun ketika masuk ke aplikasi yang kompleks, pengelolaan kode program akan menjadi kendala utama.

Misalnya jika kita mendefinisikan variabel bernama **luas_lingkaran** di satu tempat, maka variabel yang sama tidak bisa di tulis di tempat lain. Untuk kode program yang terdiri dari 1000 baris, sangat mungkin tidak sengaja menggunakan nama variabel **luas_lingkaran** di tempat lain.

Inilah yang kemudian di perbaiki dalam bahasa pemrograman C++. Di dalam C++ sebenarnya kita juga tetap bisa menulis dalam bentuk procedural programming seperti di bahasa C, akan tetapi bahasa C++ juga mendukung paradigma **object oriented programming** (**OOP**).

Di dalam OOP, sebuah kode program dipecah ke dalam _class_ dan _object_. Setiap class dan object bisa berkomunikasi satu sama lain tapi tidak bisa saling menimpa. Dengan demikian bisa saja kita membuat variabel **luas_lingkaran** di dalam class A, dan juga variabel **luas_lingkaran** di dalam class B.

Konsep pemrograman object sangat cocok untuk project yang kompleks dan melibatkan tim. Pembatasan class dan object membuat kode program tidak saling bentrok.

Akan tetapi, paradigma OOP memang butuh pendalaman tersendiri dan relatif lebih sulit dipelajari pemula. Nantinya kita akan berkenalan dengan 3 konsep dasar pemrograman object, yakni _encapsulation_, _inheritance_ dan _polymorphism_.

---

### Perbedaan Struktur Dasar Kode Program C dan C++

Di dalam bahasa C, baris pertama biasanya kita butuh perintah `#include <stdio.h>` kemudian menggunakan perintah **printf** untuk menampilkan teks serta perintah **scanf** untuk membaca inputan.

Di dalam bahasa C++, pada baris pertama menggunakan perintah `#include <iostream>`, kemudian menggunakan perintah **cout** untuk menampilkan teks serta perintah **cin** untuk membaca inputan.

Perbedaan lain ada di nama file, dimana kode program bahasa C biasa disimpan dengan extension ***.c**, seperti **hello_world.c**. Sedangkan bahasa C++ menggunakan extension ***.cpp**, seperti **hello_world.cpp**.

Berikut contoh kode program menampilkan teks "Hello World!" menggunakan bahasa C:

```Cpp
#include <stdio.h>
 
int main()
{
  printf("Hello World!");
  return 0;
}
```


Dan berikut contoh kode program menampilkan teks "Hello World!" menggunakan bahasa C++:

```Cpp
#include <iostream>
 
int main() 
{
  std::cout << "Hello World!";
  return 0;
}
```

Struktur kode program bahasa C++ ini akan kita bahas lebih lanjut dalam tutorial terpisah.

---

### Persamaan antara C dan C++

Dari kedua perbedaan di atas, bahasa C dan C++ juga memiliki banyak kesamaan. Ini tidak mengherankan karena C++ pada awalnya di kembangkan dari bahasa C. Jadi pada dasarnya selama tidak diubah, perintah pada bahasa C tetap dipakai oleh bahasa C++.

Misalnya struktur penulisan kondisi **if**, **if else**, dan **switch case** sama di kedua bahasa ini. Begitu pula cara penulisan perulangan **for**, **while** dan **do while**.

Meskipun tidak semua, pada umumnya compiler bahasa C++ juga bisa dipakai untuk menjalankan kode program yang ditulis dalam bahasa C. Sebagai contoh, sesaat lagi kita akan menginstall aplikasi IDE **Code::Block** yang juga saya pakai pada [tutorial bahasa C di Duniailkom](https://www.duniailkom.com/tutorial-belajar-bahasa-pemrograman-c-bagi-pemula/).

Aplikasi Code::Block secara default menggunakan compiler **GNU GCC** yang tersedia di **MinGW-W64 project**. Compiler ini bisa dipakai untuk menjalankan baik kode C dan juga kode C++.

Persamaan lain, bahasa C dan C++ sama-sama dikembangkan pada **AT&T Bell Laboratory**, oleh dua ilmuwan berbeda. Bahasa C rilis pada tahun **1972** oleh **Dennis Ritchie**, sedangkan bahasa C++ di rilis 13 tahun setelah itu di tahun **1985** oleh **Bjarne Stroustrup**.

---

Dalam tutorial ini kita telah membahas perbedaan antara bahasa C dengan bahasa C++. Kedua bahasa ini merupakan "adik-kakak", dimana hampir semua fitur yang ada di bahasa C juga tersedia di bahasa C++, dengan tambahan pemrograman berbasis object.

Bagi pemula, untuk bisa ke C++ tidak harus belajar bahasa C terlebih dahulu. Namun untuk yang sudah paham bahasa C, nantinya akan melihat banyak kemiripan antara bahasa C dan C++.

Pada tutorial berikutnya kita akan install aplikasi yang diperlukan untuk menjalankan kode bahasa pemrograman C++, yakni [Cara Menginstall Code::Block](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-cara-menginstall-codeblock/ "Tutorial Belajar C++ Part 3: Cara Menginstall Code::Block").