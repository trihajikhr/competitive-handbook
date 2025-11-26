---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-12-22T18:45:00
file_tanyaJawab: 
total_study: 1
id: DIOOP4
tags:
  - Cpp
  - OOP
spaced_repetition: true
sr-due: 2024-12-24
sr-interval: 2
sr-ease: 150
---
# Tutorial Belajar OOP C++ Part 4: Pengertian Public, Protected dan Private (Enkapsulasi)

05 Nov 20 

Setelah memahami [Cara Membuat Object Pada Bahasa C++](https://www.duniailkom.com/tutorial-belajar-oop-c-plus-plus-cara-membuat-object-pada-bahasa-c-plus-plus/ "Tutorial Belajar OOP C++ Part 3: Cara Membuat Object Pada Bahasa C++"), dalam tutorial kali ini kita akan membahas salah satu aspek terpenting di OOP, yakni **Enkapsulasi** (bahasa inggris: _Encapsulation_).

Proses enkapsulasi diterapkan dengan menggunakan 3 jenis hak akses: **Public, Protected** dan **Private.**

---

### Pengertian Enkapsulasi (Encapsulation)

**Enkapsulasi** (_encapsulation_) adalah sebuah metode untuk mengatur struktur class dengan cara menyembunyikan alur kerja dari class tersebut.

**Struktur class** yang dimaksud adalah **data member** dan **member function**. Dengan enkapsulasi, kita bisa membuat pembatasan hak akses kepada data member dan member function, sehingga hanya data member dan member function tertentu saja yang bisa diakses dari luar class. Enkapsulasi ini juga dikenal dengan istilah _information hiding_.

Dengan menghalangi kode program lain untuk mengubah data member atau member function tertentu, class menjadi lebih terintegrasi dan menghindari kesalahan ketika seseorang mencoba mengubahnya.

Pembatasan hak akses seperti ini sangat berguna ketika membuat program dengan tim. Setiap anggota tim bisa membuat nama data member dan member function yang sama, selama di class berbeda. Programmer yang merancang _class_ kemudian menyediakan member function khusus yang memang ditujukan untuk diakses dari luar class.

Melanjutkan analogi tentang class **Laptop**, perusahaan pembuat Laptop telah menyediakan member function khusus untuk menghidupkan Laptop, yakni dengan cara menekan tombol **on**.

Di dalam Laptop sendiri, banyak member function lain yang dijalankan ketika kita menyalakan Laptop, seperti mengirim sinyal booting ke processor, mengirim data dari processor ke memory, dan mengirim sinyal listrik ke LED di monitor, dst. Akan tetapi, ini adalah _member function internal_ Laptop, dimana kita sebagai user tidak perlu memahaminya untuk menghidupkan Laptop.

---

### Pengertian Hak Akses Public

Untuk membatasi hak akses **data member** dan **member function**, konsep Object Oriented Programming menyediakan 3 kata kunci, yakni **Public**, **Protected** dan **Private**. Kata kunci ini ditulis sebelum nama data member dan nama member function. Kita akan bahas satu per satu yang dimulai dari hak akses public terlebih dahulu.

Ketika sebuah data member atau member function dinyatakan sebagai **public**, maka seluruh kode program di luar class bisa mengaksesnya, termasuk class turunan. Berikut adalah contoh penulisan **public** data member dan **public** member function dalam C++:

```Cpp
#include <iostream>
 
using namespace std;
 
class Laptop {
  // buat hak akses public
  public:
    string pemilik;
    string hidupkanLaptop() {
      return "Hidupkan Laptop";
    }
};
 
int main()
{
  Laptop laptopAnto;
  laptopAnto.pemilik = "Anto";
 
  cout << laptopAnto.pemilik << endl;
  cout << laptopAnto.hidupkanLaptop() << endl;
  return 0;
}
```

Hasil kode program:

```
Anto
Hidupkan Laptop
```

Kode program ini sebenarnya sama seperti contoh tutorial sebelumnya. Perhatikan penambahan keyword "**public:**" di baris 7, itulah cara penulisan hak akses di OOP C++. Setelah perintah **public:**, maka semua penulisan data member dan member function di bawahnya akan memiliki hak akses **public**, sampai ditemukan perubahan perintah hak akses lain.

Dalam contoh di atas, data member **pemilik** dan member function **hidupkanLaptop()** memiliki hak akses public, sehingga bisa diakses dari luar class seperti yang kita lakukan di baris 17, 19 dan 20.

---

### Pengertian Hak Akses Private

Jika sebuah data member atau member function di-set dengan hak akses **private**, maka data dan function tersebut tidak bisa diakses dari luar class, termasuk juga dari class turunan. Satu-satunya yang bisa mengakses adalah kode program yang ada di dalam class itu sendiri.

Sebagai contoh, berikut hasil yang di dapat jika kita mengakses data member dan member function dengan level **private**:

```Cpp
#include <iostream>
 
using namespace std;
 
class Laptop {
  // buat hak akses private
  private:
    string pemilik;
    string hidupkanLaptop() {
      return "Hidupkan Laptop";
    }
};
 
int main()
{
  Laptop laptopAnto;
  laptopAnto.pemilik = "Anto";                   // error
 
  cout << laptopAnto.pemilik << endl;            // error
  cout << laptopAnto.hidupkanLaptop() << endl;   // error
  return 0;
}
```

Hasil kode program:

```
error: 'std::__cxx11::string Laptop::pemilik' is private within this context

```

Kode program di atas akan error karena di baris 7 sekarang saya menulis keyword "**private:**". Akibatnya, data member **pemilik** dan member function **hidupkanLaptop()** sudah tidak bisa diakses dari luar class.

Data dan function yang di set sebagai **private** memang tidak ditujukan untuk bisa diakses, tapi hanya untuk pemrosesan internal class itu sendiri.

Dalam analogi tentang laptop, user biasa seharusnya tidak bisa mengakses kabel penghubung antara keyboard dengan motherboard laptop karena itu merupakan data member internal laptop. Laptop bisa rusak jika kabel ini di utak-atik.

Fungsi dari membuat sebuah data member atau member function sebagai **private** adalah agar tidak bisa di utak-atik dari luar class. Pada prakteknya, sebuah class bisa saja memiliki puluhan data atau function private, lalu menyediakan 1 atau 2 member function public sebagai sarana komunikasi dengan "dunia luar".

Sebagai contoh lain, berikut kombinasi antara hak akses **private** dengan **public**:

```Cpp
#include <iostream>
 
using namespace std;
 
class Laptop {
  // buat hak akses private
  private:
    string jenisProcessor = "Intel Core i7-10750h 3.6Ghz";
 
  // buat hak akses public
  public:
    string cekProcessor() {
     return jenisProcessor;
   }
};
 
int main()
{
  Laptop laptopAnto;
 
  cout << laptopAnto.cekProcessor() << endl;
  return 0;
}
```

Hasil kode program:

```
Intel Core i7-10750h 3.6Ghz
```

Dalam kode program ini saya membuat data member **jenisProcessor** yang di set sebagai **private**. Data member **jenisProcessor** langsung di isi dengan string "Intel Core i7-10750h 3.6Ghz". Karena memiliki hak akses **private**, data member **jenisProcessor** tidak bisa diakses dari luar class.

Di baris 12 saya membuat member function **cekProcessor()** dengan hak akses **public**. Isi dari member function mengembalikan nilai yang tersimpan di dalam data member **jenisProcessor**. Ini bisa dilakukan karena member function **cekProcessor()** masih berada di dalam class **Laptop** sehingga tetap bisa mengakses data member dengan hak akses **private**.

Setelah proses instansiasi ke dalam object **laptopAnto**, di baris 21 saya mengakses member function **cekProcessor()** dengan perintah **cout**. Hasilnya, isi data **jenisProcessor** bisa ditampilkan tapi harus melalui function **cekProcessor()**.

Teknik seperti ini sering dipakai untuk membuat  function yang disebut sebagai **setter** dan **getter** (akan kita bahas dalam tutorial terpisah).

---

### Pengertian Hak Akses Protected

Sekarang kita akan bahas jenis hak akses ketiga, yakni **protected**.

Jika sebuah data member atau member function dinyatakan sebagai **protected**, maka data member atau member function tersebut tidak bisa diakses dari luar class, namun masih bisa diakses oleh class itu sendiri atau turunan class tersebut.

**Protected** mirip seperti **private**, yakni tidak bisa diakses di luar class. Perbedaannya hanya ketika class itu di turunkan, dimana data member dan member function yang di-set sebagai protected masih bisa diakses oleh class turunan.

Materi tentang turunan class (**inheritance**), memang belum kita bahas, sehingga konsep protected ini mungkin sedikit sulit dipahami.

Pertama, kita akan buktikan bahwa data member dan member function yang di-set sebagai protected tidak bisa diakses dari function **main()**:

```Cpp
#include <iostream>
 
using namespace std;
 
class Laptop {
  // buat hak akses protected
  protected:
    string pemilik;
    string hidupkanLaptop() {
      return "Hidupkan Laptop";
    }
};
 
int main()
{
  Laptop laptopAnto;
  laptopAnto.pemilik = "Anto";                   // error
 
  cout << laptopAnto.pemilik << endl;            // error
  cout << laptopAnto.hidupkanLaptop() << endl;   // error
  return 0;
}
```

Hasil kode program:

```
error: 'std::__cxx11::string Laptop::pemilik' is protected within this context

```

Sama seperti hak akses private, error terjadi karena saya mencoba mengakses data member **pemilik** dan member function **hidupkanLaptop()** di dalam function main().

Dan juga sama seperti private, kita tetap bisa mengakses data dan function **protected** dari dalam class:

```Cpp
#include <iostream>
 
using namespace std;
 
class Laptop {
  // buat hak akses protected
  protected:
    string jenisProcessor = "Intel Core i7-10750h 3.6Ghz";
 
  // buat hak akses public
  public:
    string cekProcessor() {
     return jenisProcessor;
   }
};
 
int main()
{
  Laptop laptopAnto;
 
  cout << laptopAnto.cekProcessor() << endl;
  return 0;
}
```

Hasil kode program:

```
Intel Core i7-10750h 3.6Ghz
```

Contoh kode ini sama seperti pada penjelasan hak akses private, hanya saja sekarang diubah menggunakan hak akses **protected** seperti di baris 7.

Perbedaan antara **private** dan **protected** baru terlihat pada saat class diturunkan. Berikut contohnya:

```Cpp
#include <iostream>
 
using namespace std;
 
class Komputer {
  protected:
    string jenisProcessor = "Intel Core i7-10750h 3.6Ghz";
};
 
class Laptop: public Komputer {
  public:
    string cekProcessor() {
     return jenisProcessor;
   }
};
 
int main()
{
  Laptop laptopAnto;
 
  cout << laptopAnto.cekProcessor() << endl;
  return 0;
}
```

Hasil kode program:

```
Intel Core i7-10750h 3.6Ghz
```

Disini saya membuat 2 buah class, yakni **class Komputer** dan **class Laptop**. Class Komputer memiliki satu data member **jenisProcessor** yang di set dengan hak akses **protected**.

Di baris 10, class Laptop dibuat sebagai turunan dari class Komputer. Class **Laptop** memiliki satu member function public bernama **cekProcessor()** yang di dalamnya mengakses data member **jenisProcessor**.

Hasilnya, perintah **cout << laptopAnto.cekProcessor()** berhasil menampilkan isi data member jenisProcessor. Ini tidak bisa dilakukan jika data member jenisProcessor di class Komputer di set sebagai private.

> Penjelasan lebih lanjut tentang penurunan class (_class inheritance_) akan kita bahas dalam tutorial tersendiri. Jika anda kurang paham dengan kode diatas, silahkan kembali setelah membaca tutorial tentang Pengertian Class Inheritance (Class Turunan) di C++.

---

Pada tutorial kali ini, kita telah membahas tentang konsep **enkapsulasi** dalam **OOP C++**. Teknik enkapsulasi ini didapat dari penggunaan 3 hak akses: **public_,_ protected_,_** dan **private**.

Dalam tutorial belajar OOP C++ berikutnya akan masuk ke [Cara Membuat dan Mengakses Member Function C++](https://www.duniailkom.com/tutorial-belajar-oop-c-plus-plus-cara-membuat-dan-mengakses-member-function/ "Tutorial Belajar OOP C++ Part 5: Cara Membuat dan Mengakses Member Function").