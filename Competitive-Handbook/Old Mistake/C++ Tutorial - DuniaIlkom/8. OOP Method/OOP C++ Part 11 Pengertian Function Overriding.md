---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-12-23T11:43:00
file_tanyaJawab: 
total_study: 1
id: DIOOP11
tags:
  - Cpp
  - OOP
spaced_repetition: true
sr-due: 2024-12-25
sr-interval: 2
sr-ease: 150
---
# Tutorial Belajar OOP C++ Part 11: Pengertian Function Overriding

09 Nov 20 

Melanjutkan materi tutorial belajar OOP C++, kali ini kita akan berkenalan dengan Function Overriding. Istilah ini terdengar mirip seperti [Function Overloading](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-pengertian-function-overloading-c-plus-plus/ "Tutorial Belajar C++ Part 41: Pengertian Function Overloading C++") yang pernah kita bahas pada tutorial C++ procedural, namun pengertiannya cukup berbeda.

Function overriding ini kadang juga disebut sebagai penimpaan function.

---

### Pengertian Function Overriding

**Function overriding** adalah sebuah situasi dimana member function class turunan menimpa member function milik parent class. Ini bisa terjadi jika terdapat nama function yang sama di child class dan juga parent class.

Berikut contoh situasi yang dimaksud:

```Cpp
#include <iostream>
 
using namespace std;
 
class Komputer {
  public:
    string cekInfo() {
      return "Ini berasal dari class Komputer";
    }
};
 
class Laptop: public Komputer {
  public:
    string cekInfo() {
      return "Ini berasal dari class Laptop";
    }
};
 
int main()
{
  Laptop laptopAndi;
  cout << laptopAndi.cekInfo() << endl;
 
  return 0;
}
```

Pada kode program ini, class **Komputer** diturunkan kepada class **Laptop**. Perhatikan bahwa di dalam kedua class terdapat member function **cekInfo()** dengan hak akses **public**.

Di dalam function main, saya meng-instansiasi class **Laptop** ke dalam variabel **laptopAndi**, lalu menjalankan perintah **cout << laptopAndi.cekInfo()**.

Pertanyaannya, function **cekInfo()** milik siapa yang akan dijalankan? apakah milik class Laptop, atau milik class Komputer?

Saat kode di atas dijalankan, hasilnya adalah sebagai berikut:

```
Ini berasal dari class Laptop
```

Ternyata function cekInfo() milik class Laptop-lah yang dijalankan. Dalam kasus ini sudah terjadi **function overriding**, dimana member function cekInfo() milik class Laptop menimpa member function cekInfo() milik class Komputer.

---

### Cara Mengakses Function Overriding Milik Parent Class

Efek function overriding menyebabkan kita tidak bisa mengakses member function milik parent class.

Namun sebenarnya masih bisa dilakukan melalui operator khusus yang disebut sebagai **scope resolution operator**. Operator ini ditulis dengan tanda titik dua, dua kali "`::`". Berikut contoh penggunaannya:

```Cpp
#include <iostream>
 
using namespace std;
 
class Komputer {
  public:
    string cekInfo() {
      return "Ini berasal dari class Komputer";
    }
};
 
class Laptop: public Komputer {
  public:
    string cekInfo() {
      return "Ini berasal dari class Laptop";
    }
};
 
int main()
{
  Laptop laptopAndi;
  cout << laptopAndi.cekInfo() << endl;
  cout << laptopAndi.Komputer::cekInfo() << endl;
 
  return 0;
}
```

Agar bisa mengakses function **cekInfo()**, saya menggunakan perintah **cout << laptopAndi.Komputer::cekInfo()** seperti di baris 23. Inilah cara mengakses member function yang sudah ter-overridden.

Format penulisan yang dipakai adalah: **namaObject.NamaClass::namaFunction()**.

---

### Cara Mengakses Function Overriding Dari Child Class

Operator scope resolution juga bisa dipakai dari dalam child class ketika kita ingin mengakses function milik parent class yang sudah ter-overridden. Berikut contoh yang dimaksud:

```Cpp
#include <iostream>
 
using namespace std;
 
class Komputer {
  public:
    string cekInfo() {
      return "Ini berasal dari class Komputer";
    }
};
 
class Laptop: public Komputer {
  public:
    string cekInfo() {
      cout << Komputer::cekInfo() << endl;
      return "Ini berasal dari class Laptop";
    }
};
 
int main()
{
  Laptop laptopAndi;
  cout << laptopAndi.cekInfo() << endl;
 
  return 0;
}
```

Hasil kode program:

[![Contoh Kode Program Function Overriding OOP Cpp](https://www.duniailkom.com/wp-content/uploads/2020/11/Contoh-Kode-Program-Function-Overriding-OOP-Cpp.png)](https://www.duniailkom.com/wp-content/uploads/2020/11/Contoh-Kode-Program-Function-Overriding-OOP-Cpp.png)

Sekarang saya mengakses function **cekInfo()** milik class **Komputer** di dalam function **cekInfo()** class Laptop pada baris 15. Hasilnya, akan tampil teks "Ini berasal dari class **Komputer**" milik class **Komputer**.

---

Materi **function overriding** yang kita bahas kali ini merupakan kasus khusus yang bisa terjadi akibat dari penurunan class (_proses inheritance_).

Sebenarnya tetap disarankan untuk selalu menulis nama function yang berbeda pada setiap class agar tidak terjadi penimpaan function. Namun jika itu terjadi, kita bisa mengaksesnya menggunakan **scope resolution operator**.

Lanjut, pada tutorial berikutnya akan dibahas tentang [Cara Mengakses Constructor Parent Class](https://www.duniailkom.com/tutorial-belajar-oop-c-plus-plus-cara-mengakses-constructor-parent-class/ "Tutorial Belajar OOP C++ Part 12: Cara Mengakses Constructor Parent Class").