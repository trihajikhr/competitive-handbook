---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-09-26T20:02:00
total_study: 1
tags:
  - Cpp
id: DIE3
---
# Tutorial Belajar C++ Part 23: Jenis-jenis Operator Increment & Decrement Bahasa C++

28 Oct 20 

Melanjutkan materi tentang operator dalam bahasa pemrograman C++, kali ini kita akan membahas Jenis-jenis Operator Increment dan Decrement dalam Bahasa C++.

Beberapa sumber ada yang mengelompokkan operator ini ke dalam operator aritmatika.

---

### Pengertian Increment dan Decrement Bahasa C++

Operator **increment** dan **decrement** adalah sebutan untuk operasi seperti **a++**, dan **a--**. Ini sebenarnya penulisan singkat dari operasi **a = a + 1** serta **a = a – 1**.

**Increment** digunakan untuk menambah variabel sebanyak 1 angka, sedangkan **decrement** digunakan untuk mengurangi variabel sebanyak 1 angka.

Penulisannya menggunakan tanda tambah 2 kali untuk **increment**, dan tanda kurang 2 kali untuk **decrement**. Penempatan tanda tambah atau kurang ini boleh di awal seperti **++a** dan **--a**, atau di akhir variabel seperti **a++** dan **a--**.

Dengan demikian terdapat 4 jenis **increment** dan **decrement** dalam bahasa C++:

|Operator|Contoh|Penjelasan|
|---|---|---|
|Pre-increment|`++a`|Tambah a sebanyak 1 angka, lalu tampilkan hasilnya|
|Post-increment|`a++`|Tampilkan nilai a, lalu tambah a sebanyak 1 angka|
|Pre-decrement|`--a`|Kurangi a sebanyak 1 angka, lalu tampilkan hasilnya|
|Post-decrement|`a--`|Tampilkan nilai a, lalu kurangi a sebanyak 1 angka|

Untuk melihat apa perbedaan dari setiap operator akan kita bahas dengan contoh kode program.  

---

### Contoh Kode Program Increment dan Decrement

Secara umum, penulisan tanda di awal maupun di akhir akan menghasilkan nilai yang sama. Berikut contohnya:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int a = 5;
  a++;
  cout << "Isi variabel a: " << a << endl;
 
  int b = 5;
  ++b;
  cout << "Isi variabel b: " << b << endl;
 
  return 0;
}
```

Hasil kode program:

```
Isi variabel a: 6
Isi variabel b: 6
```

Di sini saya mengisi angka 5 sebagai nilai awal untuk variabel **a** dan **b**. Hasilnya, setelah operasi **a++** dan **++b**, kedua variabel sama-sama berisi angka 6. Artinya variabel **a** dan **b** akan bertambah 1 angka.

Hal yang sama juga berlaku di **decrement**:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int a = 5;
  a--;
  cout << "Isi variabel a: " << a << endl;
 
  int b = 5;
  --b;
  cout << "Isi variabel b: " << b << endl;
 
  return 0;
}
```

Hasil kode program:

```
Isi variabel a: 4
Isi variabel b: 4
```

Saya kembali mengisi angka 5 sebagai nilai awal untuk variabel **a** dan **b**. Hasilnya, setelah operasi **a--** dan **--b**, kedua variabel sama-sama berisi angka 4. Artinya variabel **a** dan **b** akan berkurang 1 angka.

---

### Perbedaan Pre-Increment dengan Post-Increment

Jadi apa beda antara **pre-increment** (**++a**) dengan **post-increment** (**a++**)? Perbedaannya baru terlihat jika kita akses pada saat operasi berlangsung seperti contoh berikut:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int a = 5;
  cout << "Post Increment" << endl;
  cout << "Isi variabel a: " << a << endl;
  cout << "Isi variabel a: " << a++ << endl;
  cout << "Isi variabel a: " << a << endl;
 
  cout << endl;
 
  int b = 5;
  cout << "Pre Increment" << endl;
  cout << "Isi variabel b: " << b << endl;
  cout << "Isi variabel b: " << ++b << endl;
  cout << "Isi variabel b: " << b << endl;
 
  return 0;
}
```

[![Contoh Kode Program Operator Increment Decrement Bahasa C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Operator-Increment-Decrement-Bahasa-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Operator-Increment-Decrement-Bahasa-C.png)

Perbedaannya ada di baris 10 dan 18, yakni ketika kita akses langsung pada saat operasi increment dilakukan.

Terlihat bahwa **post-increment** (`a++`), akan menampilkan hasilnya terlebih dahulu, baru nilai variabel a naik 1 angka, namun dengan **pre-increment** (`++b`), variabel b akan ditambahkan 1 angka, baru nilainya ditampilkan.

Begitu juga hal nya dengan operasi **post-decrement** dan **pre-decrement**:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int a = 5;
  cout << "Post Decrement" << endl;
  cout << "Isi variabel a: " << a << endl;
  cout << "Isi variabel a: " << a-- << endl;
  cout << "Isi variabel a: " << a << endl;
 
  cout << endl;
 
  int b = 5;
  cout << "Pre Decrement" << endl;
  cout << "Isi variabel b: " << b << endl;
  cout << "Isi variabel b: " << --b << endl;
  cout << "Isi variabel b: " << b << endl;
 
  return 0;
}
```

Hasil kode program:

```
Post Decrement
Isi variabel a: 5
Isi variabel a: 5
Isi variabel a: 4
 
Pre Decrement
Isi variabel b: 5
Isi variabel b: 4
Isi variabel b: 4
```

Terlihat bahwa post-decrement (`a--`), akan menampilkan hasilnya terlebih dahulu, baru nilai variabel a dikurangi 1 angka. Sedangkan pre-decrement (`--b`), variabel b langsung dikurangi 1 angka, lalu nilainya ditampilkan.

---

Operator **increment** dan **decrement** yang kita bahas akan banyak di terapkan dalam perulangan (looping). Selain itu kebiasaan banyak programmer lebih sering menggunakan post-increment (`a++`) dan post-decrement (`a--`) dari pada pre-increment (`++a`) dan pre-decrement (`--a`)

Nama bahasa pemrograman **C++** juga terinspirasi dari **post increment** bahasa C, yakni penambahan dari bahasa C.

Berikutnya, kita akan masuk ke [Operator Perbandingan atau Operator Relasional Bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-jenis-jenis-operator-perbandingan-relasional-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 24: Jenis-jenis Operator Perbandingan / Relasional Bahasa C++").