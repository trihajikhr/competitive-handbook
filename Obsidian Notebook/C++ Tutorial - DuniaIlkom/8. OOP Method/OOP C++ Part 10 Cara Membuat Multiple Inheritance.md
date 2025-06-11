---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-12-23T11:18:00
file_tanyaJawab: 
total_study: 1
id: DIOOP10
tags:
  - Cpp
  - OOP
spaced_repetition: true
sr-due: 2024-12-25
sr-interval: 2
sr-ease: 150
---
# Tutorial Belajar OOP C++ Part 10: Cara Membuat Multiple Inheritance

08 Nov 20 

Tutorial kali ini terdengar sangat mirip seperti tutorial sebelumnya tentang [Multilevel Inheritance](https://www.duniailkom.com/tutorial-belajar-oop-c-plus-plus-cara-membuat-multilevel-inheritance/ "Tutorial Belajar OOP C++ Part 9: Cara Membuat Multilevel Inheritance"). Akan tetapi Multiple Inheritance adalah jenis penurunan class yang berbeda. Kita akan bahas dengan lebih detail sesaat lagi.

---

### Pengertian Multiple Inheritance

**Multiple Inheritance** adalah penurunan class dimana sebuah class bisa memiliki lebih dari 1 parent class langsung.

Contohnya adalah class C yang bisa memiliki induk dari class A dan juga class B sekaligus. Efeknya, class C bisa mengakses semua data member dan member function milik class A dan juga class B, selama tidak di set sebagai private.

Berikut struktur dasar contoh **multiple inheritance** dengan class **Laptop**, class **Smartphone** dan class **SmartLaptop**:

```Cpp
#include <iostream>
 
using namespace std;
 
class Laptop {
  // kode untuk class Laptop
};
 
class Smartphone {
  // kode untuk class Smartphone
};
 
class SmartLaptop: public Laptop, public Smartphone{
  // kode untuk class SmartLaptop
};
 
int main()
{
  Laptop laptopAndi;
  Smartphone smartphoneAndi;
  SmartLaptop smartLaptopAndi;
 
  return 0;
}
```

Perhatikan cara penurunan class **SmartLaptop** di baris 13, itulah yang dimaksud dengan **Multiple Inheritance**, dimana class **SmartLaptop** memiliki 2 parent class sekaligus, yakni class **Laptop** dan **Smartphone**.

Dengan penulisan seperti ini, class **SmartLaptop** bisa mengakses semua data member dan member function yang terdapat di class **Laptop** dan **Smartphone**.

> [!NOTE]
> Bahasa C++ merupakan satu dari sedikit bahasa pemrograman yang memiliki fitur multiple Inheritance seperti ini. Dalam bahasa PHP atau Java, kita tidak bisa membuat class yang memiliki 2 parent class sekaligus.
> 
> Salah satu alasannya karena multiple Inheritance bisa menyebabkan "diamond problem", yakni sebuah masalah logika jika ternyata kedua parent class juga diturunkan dari satu class yang sama.

---

### Contoh Kode Program Multiple Inheritance C++

Contoh sebelumnya sudah memperlihatkan struktur dasar multiple inheritance. Berikut modifikasi lanjutan dengan penambahan data member dan member function:

```Cpp
#include <iostream>
 
using namespace std;
 
class Laptop {
  protected:
    string processor = "AMD Ryzen 7";
    string merk = "Lenovo";
    string memory = "8 GB";
 
  public:
    string cekLaptop() {
      return "Ini berasal dari class Laptop";
    }
};
 
class Smartphone {
  protected:
    string jaringan = "3G/4G";
 
  public:
    string cekSmartphone() {
      return "Ini berasal dari class Smartphone";
    }
};
 
class SmartLaptop: public Laptop, public Smartphone{
  public:
    string lihatSpec() {
      return "Merk: " + merk + ", processor: " + processor +
             ", jumlah memory: " + memory + ", jaringan " + jaringan;
    }
    string cekSmartLaptop() {
      return "Ini berasal dari class SmartLaptop";
    }
};
 
int main()
{
  SmartLaptop smartLaptopAndi;
 
  cout << smartLaptopAndi.lihatSpec() << endl;
  cout << smartLaptopAndi.cekLaptop() << endl;
  cout << smartLaptopAndi.cekSmartphone() << endl;
  cout << smartLaptopAndi.cekSmartLaptop() << endl;
 
  return 0;
}
```

Hasil kode program:

[![Contoh Kode Program Multiple Inheritance OOP Cpp](https://www.duniailkom.com/wp-content/uploads/2020/11/Contoh-Kode-Program-Multiple-Inheritance-OOP-Cpp.png)](https://www.duniailkom.com/wp-content/uploads/2020/11/Contoh-Kode-Program-Multiple-Inheritance-OOP-Cpp.png)

Sama seperti tips pada tutorial sebelumnya, untuk kode program yang panjang seperti ini kita akan mulai membaca kode program dari function **main()** terlebih dahulu.

Sebagai perintah pertama, terdapat proses instansiasi class **SmartLaptop** ke dalam object **smartLaptopAndi**. Artinya di dalam kode program harus terdapat kode untuk mendefinisikan class **SmartLaptop**.

Kemudian di baris 42 terdapat perintah **cout << smartLaptopAndi.lihatSpec()**. Perintah ini akan mengakses member function **lihatSpec()** milik class **SmartLaptop**, maka kita mulai berangkat mencarinya ke pendefinisian class tersebut di baris 27 – 36.

Function **lihatSpec()** berisi perintah penggabungan string yang melibatkan data member **merk**, **processor**, **memory**, dan **jaringan**. Ternyata di dalam class SmartLaptop tidak ada pendefinisian data yang dimaksud. Maka kita lihat kembali apakah class ini memiliki parent class atau tidak.

Ternyata class SmartLaptop memiliki 2 parent class, yakni class **Laptop** dan juga class **Smartphone**. Maka akhirnya ditemukan terdapat data member **processor = "AMD Ryzen 7"**, **merk = "Lenovo"**, dan **memory = "8 GB"** di dalam class Laptop, serta data **jaringan = "3G/4G"** di dalam class Smartphone.

Dengan demikian hasil perintah **cout << smartLaptopAndi.lihatSpec()** adalah **Merk: Lenovo, processor: AMD Ryzen 7, jumlah memory: 8 GB, jaringan 3G/4G**.

Kembali ke function main(), selanjutnya terdapat 3 perintah untuk mengakses 3 member function berikut:

```Cpp
cout << smartLaptopAndi.cekLaptop() << endl;
cout << smartLaptopAndi.cekSmartphone() << endl;
cout << smartLaptopAndi.cekSmartLaptop() << endl;
```

Ketiga function ini ada di setiap class terpisah. Karena class **SmartLaptop** adalah turunan dari class **Laptop** dan class **Smartphone**, maka object **smartLaptopAndi** bisa mengakses ketiga member function tersebut, dan hasilnya adalah:

```
Ini berasal dari class Laptop
Ini berasal dari class Smartphone
Ini berasal dari class SmartLaptop
```

Inilah contoh praktek dari **multiple inherintance** dalam bahasa pemrograman C++.

---

Tidak kalah menarik, dalam lanjutan tutorial OOP C++ berikutnya kita akan membahas tentang [Pengertian Function Overriding dalam bahasa pemrograman C++](https://www.duniailkom.com/tutorial-belajar-oop-c-plus-plus-pengertian-function-overriding/ "Tutorial Belajar OOP C++ Part 11: Pengertian Function Overriding").