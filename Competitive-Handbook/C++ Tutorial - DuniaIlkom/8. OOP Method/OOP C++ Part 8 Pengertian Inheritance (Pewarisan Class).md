---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-12-23T10:49:00
file_tanyaJawab: 
total_study: 1
id: DIOOP8
tags:
  - Cpp
  - OOP
spaced_repetition: true
sr-due: 2024-12-25
sr-interval: 2
sr-ease: 150
---
# Tutorial Belajar OOP C++ Part 8: Pengertian Inheritance (Pewarisan Class)

06 Nov 20 

Dalam tutorial OOP C++ kali ini kita akan membahas salah satu konsep terpenting dalam OOP, yakni inheritance atau pewarisan class.

---

### Pengertian Inheritance (Pewarisan Class)

**Inheritance** adalah konsep OOP dimana sebuah class dapat menurunkan **data member** dan **member function** yang dimilikinya kepada **class** lain. Konsep **inheritance** dipakai untuk memanfaatkan fitur _code reuse_, yakni menghindari terjadinya duplikasi kode program.

Dalam bahasa Indonesia, inheritance ini disebut juga sebagai pewarisan atau penurunan.

Konsep inheritance membuat sebuah struktur atau hierarki **class** dalam kode program. Class yang akan diturunkan bisa disebut sebagai **class induk (parent class), super class,** atau **base class**.

Sedangkan class yang menerima penurunan bisa disebut sebagai **class anak (child class), sub class, derived class** atau **heir class**.

Dalam tutorial ini saya akan menggunakan istilah **parent class** dan **child class**, tapi seperti yang tertulis diatas, banyak istilah yang bisa dipakai.

Tidak semua **data member** dan **member function** class induk akan diturunkan. Data dan function dengan hak akses **private** tidak akan diturunkan kepada child class. Hanya data dengan hak akses **protected** dan **public** saja yang bisa diakses dari child class.

---

### Cara Menurunkan Class di C++

Untuk menurunkan sebuah class di bahasa pemrograman C++, tulis nama parent class pada saat pendefinisian child class. Berikut contoh kode program yang di maksud:

```Cpp
#include <iostream>
 
using namespace std;
 
class Komputer {
  // kode untuk class Komputer
};
 
class Laptop: public Komputer {
  // kode untuk class Laptop
};
 
int main()
{
  Komputer komputerAndi;
  Laptop laptopAndi;
 
  return 0;
}
```

Dalam kode ini saya membuat dua buah class: **Komputer** dan **Laptop**. Perhatikan perintah di baris 9, itulah cara menurunkan class **Komputer** kepada class **Laptop**. Yakni dengan cara menulis tanda titik dua, diikuti hak akses class yang dalam hal ini **public**, beserta nama **parent class** yang ingin diturunkan.

Setelah perintah tersebut, class **Laptop** adalah anak (child) dari class **Komputer**. Jika class **Komputer** memiliki data member dan member function yang di-set sebagai **public** atau **protected**, juga akan bisa diakses dari class Laptop (prakteknya akan kita lihat sesaat lagi).

Dalam konsep OOP, hubungan antara parent class dan child class seharusnya memiliki makna tertentu. Biasanya hubungan yang terjadi adalah "**is-a**", atau "**adalah sebuah**".

Maksudnya, jika class Laptop adalah turunan dari class Komputer, maka seharusnya **Laptop adalah sebuah Komputer**. Dalam hal ini Laptop adalah bentuk yang lebih khusus dari Laptop. Selain laptop, class Komputer bisa saja memiliki child class lain seperti KomputerDesktop.

Contoh penurunan lain adalah antara class Binatang dengan Kucing. Disini kucing adalah sebuah binatang. Atau class Mobil yang memiliki parent class Kendaraan.

---

### Cara Mengakses Data Parent Class

Contoh sebelumnya masih sangat sederhana, dimana class **Komputer** dan class **Laptop** belum memiliki data apapun. Sekarang kita akan isi dengan beberapa data member (property atau variabel), serta member function (method):

```Cpp
#include <iostream>
 
using namespace std;
 
class Komputer {
  public:
    string processor = "AMD Ryzen 7";
 
    string cekKomputer() {
      return "Ini berasal dari class Komputer";
    }
};
 
class Laptop: public Komputer {
  public:
    string merk = "Lenovo";
 
    string cekLaptop() {
      return "Ini berasal dari class Laptop";
    }
};
 
int main()
{
  Laptop laptopAndi;
 
  cout << laptopAndi.processor << endl;
  cout << laptopAndi.merk << endl;
  cout << laptopAndi.cekKomputer() << endl;
  cout << laptopAndi.cekLaptop() << endl;
 
  return 0;
}
```

Hasil kode program:

```
AMD Ryzen 7
Lenovo
Ini berasal dari class Komputer
Ini berasal dari class Laptop
```

Dalam kode diatas, class **Komputer** memiliki satu data member **processor** dan satu member function **cekKomputer()**. Sedangkan class **Laptop** memiliki data member **merk** dan member function **cekLaptop()**.

Karena class **Laptop** adalah turunan dari class **Komputer**, maka kita bisa mengakses semua isi class **Komputer** dari object class **Laptop**.

Di dalam function main() saya membuat object **laptopAndi** yang di instansiasi dari class **Laptop**. Object **laptopAndi** bisa mengakses semua isi class Komputer, yakni **laptopAndi.processor** dan **laptopAndi.cekKomputer()**. Seolah-olah data dan function ini di definisikan dari dalam class Laptop.

---

### Hak Akses Protected Dalam Inheritance

Perbedaan utama dari hak akses private dengan protected ada ketika sebuah class diturunkan dari class lain.

```Cpp
#include <iostream>
 
using namespace std;
 
class Komputer {
  protected:
    string processor = "AMD Ryzen 7";
    string merk = "Lenovo";
    string memory = "8 GB";
};
 
class Laptop: public Komputer {
  public:
 
    string lihatSpec() {
      return "Merk: " + merk + ", processor: "+ processor +
             ", jumlah memory: " + memory;
    }
};
 
int main()
{
  Laptop laptopAndi;
 
  cout << laptopAndi.lihatSpec() << endl;
  // cout << laptopAndi.processor << endl; // ini akan error
  return 0;
}
```

Hasil kode program:

```
Merk: Lenovo, processor: AMD Ryzen 7, jumlah memory: 8 GB
```

Kali ini class Komputer memiliki 3 data member dengan hak akses **protected**, yakni **processor**, **merk** dan **memory**. Class Komputer kemudian saya turunkan kepada class Laptop.

Di dalam class Laptop terdapat satu member function **lihatSpec()**, yang akan mengakses ketiga data member milik class Komputer. Ini bisa dilakukan karena protected tetap bisa diakses dari class turunan.

Namun data protected tetap tidak bisa diakses dari luar class. Kode di baris 26 akan menghasilkan error, kecuali hak akses ketiga data member milik class Komputer di-set sebagai public.

---

### Mengisi Data Member Menggunakan Constructor

Untuk materi yang sedikit lebih kompleks, dalam kode program berikut saya mengisi ketiga data member milik class **Komputer** dari constructor class **Laptop**. Silahkan pelajari sejenak alur kode program yang terjadi:

```Cpp
#include <iostream>
 
using namespace std;
 
class Komputer {
  protected:
    string processor;
    string merk;
    string memory;
};
 
class Laptop: public Komputer {
  public:
 
    Laptop(string paramProcessor, string paramMerk, string paramMemory) {
      processor = paramProcessor;
      merk = paramMerk;
      memory = paramMemory;
    }
 
    string lihatSpec() {
      return "Merk: " + merk + ", processor: "+ processor +
             ", jumlah memory: " + memory;
    }
};
 
int main()
{
  Laptop laptopAndi("Intel Core i7","HP","16 GB");
  Laptop laptopRudi("Intel Core i3","Asus","4 GB");
 
  cout << laptopAndi.lihatSpec() << endl;
  cout << laptopRudi.lihatSpec() << endl;
  return 0;
}
```

Hasil kode program:

[![Contoh Kode Program Penurunan class atau Inheritance OOP C++](https://www.duniailkom.com/wp-content/uploads/2020/11/Contoh-Kode-Program-Penurunan-class-atau-Inheritance-OOP-C-1.png)](https://www.duniailkom.com/wp-content/uploads/2020/11/Contoh-Kode-Program-Penurunan-class-atau-Inheritance-OOP-C-1.png)

Pendefinisian data member **processor**, **merk** dan **memory** tetap dilakukan dari class **Komputer**. Hanya saja sekarang proses pengisian ketiga data dilakukan oleh constructor class Laptop seperti di baris 15 – 19.

Constructor class **Laptop** butuh 3 buah parameter, yakni **paramProcessor**, **paramMerk** dan **paramMemory**. Ketika parameter ini harus diisi pada saat proses instansiasi class Laptop seperti di baris 29 dan 30.

Hasilnya, ketika method **lihatSpec()** diakses dari object **laptopAndi** dan **laptopRudi**, akan tampil nilai yang berbeda-beda.

> [!NOTE]
> Ketika mempelajari kode yang agak panjang dan melibatkan banyak object seperti diatas, mulailah membaca kode program dari function **main()** terlebih dahulu.
> 
> Jika terdapat proses instansiasi object dengan argument, baru masuk ke dalam pendefinisian class tersebut dan ikuti alur pengiriman argumen hingga mengisi data member dari sebuah class. Apabila kita mulai membaca dari pendefinisian class terlebih dahulu, biasanya memang lebih rumit.

---

**Inheritance** atau proses penurunan class memang menjadi topik yang cukup rumit tapi sangat penting. Untuk kode program yang kompleks, bisa saja ada sebuah class yang diturunkan kepada class lain, dan kemudian di turunkan lagi kepada class selanjutnya.

Inilah yang akan kita bahas dalam lanjutan tutorial OOP C++ di Duniailkom, yakni [Cara Membuat Multilevel Inheritance](https://www.duniailkom.com/tutorial-belajar-oop-c-plus-plus-cara-membuat-multilevel-inheritance/ "Tutorial Belajar OOP C++ Part 9: Cara Membuat Multilevel Inheritance").