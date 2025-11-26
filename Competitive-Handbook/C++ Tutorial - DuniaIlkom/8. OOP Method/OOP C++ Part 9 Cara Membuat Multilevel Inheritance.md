---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-12-23T11:03:00
file_tanyaJawab: 
total_study: 1
id: DIOOP9
tags:
  - Cpp
  - OOP
spaced_repetition: true
sr-due: 2024-12-25
sr-interval: 2
sr-ease: 150
---
# Tutorial Belajar OOP C++ Part 9: Cara Membuat Multilevel Inheritance

07 Nov 20 

Tutorial OOP C++ kali ini masih membahas tentang inheritance atau penurunan class. Namun kita akan masuk ke materi yang lebih advanced lagi, yakni Cara Membuat Multilevel Inheritance.

---

### Pengertian Multilevel Inheritance

**Multilevel Inheritance** adalah penurunan class berjenjang dari satu class ke class lain. Misalkan kita memiliki class A yang diturunkan kepada class B. Kemudian class B ini juga diturunkan kepada class C, sehingga sudah terjadi sebuah _multilevel inheritance_.

Dalam contoh ini class A adalah kakek atau grand parent dari class C, maka semua data member dan member function dari class A juga bisa diakses dari class C, selama tidak di set sebagai private.

Berikut struktur dasar contoh **multilevel inheritance** dengan class **Komputer**, class **Laptop**, dan class **Netbook**:

```Cpp
#include <iostream>
 
using namespace std;
 
class Komputer {
  // kode untuk class Komputer
};
 
class Laptop: public Komputer {
  // kode untuk class Laptop
};
 
class Netbook: public Laptop {
  // kode untuk class Netbook
};
 
int main()
{
  Komputer komputerAndi;
  Laptop laptopAndi;
  Netbook netbookAndi;
 
  return 0;
}
```

Cara pembuatan multilevel inheritance sebenarnya sama seperti penurunan class biasa, hanya saja setiap class saling terhubung satu sama lain.

> Hubungan "**is-a**" antara child class dengan parent class juga harusnya berlaku dalam multilevel inheritance. Dalam contoh diatas, **Netbook adalah sebuah Laptop**, dan **Laptop adalah sebuah Komputer**. Dengan demikian **Netbook juga adalah sebuah Komputer**.

---

### Contoh Kode Program Multilevel Inheritance C++

Contoh sebelumnya sudah memperlihatkan struktur dasar multilevel inheritance. Berikut modifikasi lanjutan dengan penambahan data member dan member function:

```Cpp
#include <iostream>
 
using namespace std;
 
class Komputer {
  protected:
    string processor = "AMD Ryzen 7";
    string merk = "Lenovo";
    string memory = "8 GB";
 
  public:
    string cekKomputer() {
      return "Ini berasal dari class Komputer";
    }
};
 
class Laptop: public Komputer {
  protected:
    string storage = "SSD 1TB";
 
  public:
    string cekLaptop() {
      return "Ini berasal dari class Laptop";
    }
};
 
class Netbook: public Laptop {
  public:
    string lihatSpec() {
      return "Merk: " + merk + ", processor: "+ processor +
             ", jumlah memory: " + memory + ", storage: "+ storage;
    }
    string cekNetbook() {
      return "Ini berasal dari class Netbook";
    }
};
 
int main()
{
  Netbook netbookAndi;
 
  cout << netbookAndi.lihatSpec() << endl;
  cout << netbookAndi.cekKomputer() << endl;
  cout << netbookAndi.cekLaptop() << endl;
  cout << netbookAndi.cekNetbook() << endl;
 
  return 0;
}
```

Hasil kode program:

[![Contoh Kode Program Multilevel Inheritance OOP C++](https://www.duniailkom.com/wp-content/uploads/2020/11/Contoh-Kode-Program-Multilevel-Inheritance-OOP-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/11/Contoh-Kode-Program-Multilevel-Inheritance-OOP-C.png)

Kode program ini lumayan panjang karena terdapat 3 class yang masing-masingnya memiliki data member dan member function. Agar lebih mudah dipahami, kita mempelajari kode program ini dari function **main()** terlebih dahulu.

Sebagai perintah pertama di dalam function main(), terdapat kode **Netbook netbookAndi**. Ini adalah proses instansiasi pembuatan object class **Netbook** yang disimpan ke dalam variabel **netbookAndi**. Dengan membaca kode ini kita bisa pastikan bahwa harusnya ada kode untuk pendefinisian class **Netbook** sebelum function main.

Perintah kedua dalam function main() adalah **cout << netbookAndi.lihatSpec()**. Maka kita akan lihat apa isi dari function **lihatSpec()**  yang terdapat di dalam class Netbook.

Pendefinisian class **Netbook** ada di baris 27 – 36. Di baris awal terlihat bahwa class Netbook adalah turunan dari class Laptop. Maka member function **lihatSpec()** bisa saja ada di dalam class ini, atau parent classnya.

Ternyata pendefinisian function **lihatSpec()** ada di dalam class Netbook, yang isinya merangkai sebuah string dari 4 data member, yakni **merk**, **processor**, **memory** dan **storage**. Namun di dalam class Netbook tidak ada pendefinisian data ini. Maka kita akan cari ke parent class, yaitu class Laptop.

Pendefinisian class **Laptop** ada di baris 17 – 25. Di baris awal juga terlihat bahwa class ini ternyata juga memiliki parent class, yakni class Komputer. Sehingga bisa saja data member yang kita cari tidak ada di dalam class Laptop.

Dan ternyata di dalam class Laptop hanya ada 1 data member dengan hak akses protected, yakni **storage = "SSD 1TB"**. Maka kita harus cari lagi ke dalam class Komputer.

Pendefinisian class **Komputer** ada di baris 5 – 15. Dan disinilah kita menemukan sisa 3 data member lain, yakni **processor = "AMD Ryzen 7"**, **merk = "Lenovo"** dan **memory = "8 GB"**. Ketiganya memiliki hak akses protected sehingga bisa diakses dari class turunan.

Maka lengkap sudah isi dari pemanggilan member function **netbookAndi.lihatSpec()**, dan hasilnya adalah "**Merk: Lenovo, processor: AMD Ryzen 7, jumlah memory: 8 GB, storage: SSD 1TB**".

Kita kembali ke function main() dan 3 perintah berikutnya adalah mengakses 3 buah member function berikut:

```Cpp
cout << netbookAndi.cekKomputer() << endl;
cout << netbookAndi.cekLaptop() << endl;
cout << netbookAndi.cekNetbook() << endl;
```

Ketiga function ini ada di setiap class terpisah. Karena class Netbook adalah turunan dari class Laptop dan class Laptop sendiri adalah turunan dari class Komputer, maka object **netbookAndi** bisa mengakses ketiga member function tersebut, dan hasilnya adalah:

```
Ini berasal dari class Komputer
Ini berasal dari class Laptop
Ini berasal dari class Netbook
```

Inilah contoh praktek dari multilevel inherintance dalam bahasa pemrograman C++.

---

Masih tentang penurunan atau inheritance, tutorial berikutnya akan membahas tentang [Cara Membuat Multiple Inheritance](https://www.duniailkom.com/tutorial-belajar-oop-c-plus-plus-10-cara-membuat-multiple-inheritance/ "Tutorial Belajar OOP C++ Part 10: Cara Membuat Multiple Inheritance").