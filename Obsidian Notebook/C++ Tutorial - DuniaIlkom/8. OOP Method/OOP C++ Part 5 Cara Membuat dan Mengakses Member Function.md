---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-12-22T19:03:00
file_tanyaJawab: 
total_study: 1
id: DIOOP5
tags:
  - Cpp
  - OOP
spaced_repetition: true
sr-due: 2024-12-24
sr-interval: 2
sr-ease: 150
---
# Tutorial Belajar OOP C++ Part 5: Cara Membuat dan Mengakses Member Function

05 Nov 20 

Melanjutkan seri tutorial belajar OOP C++, kali ini kita akan bahas lebih dalam tentang cara pembuatan member function (atau method) di pemrograman berbasis object C++.

---

### Cara Membuat Member Function dengan Parameter / Argumen

Pada dasarnya sebuah member function adalah function biasa. Semua fitur function bisa kita pakai ke dalam member function, misalnya memberikan **parameter** atau **argumen**:

```Cpp
#include <iostream>
 
using namespace std;
 
class Laptop {
  public:
    void hidupkanLaptop(string pemilik, string merk) {
     cout << "Hidupkan Laptop " << merk << " Milik " << pemilik;
     cout << endl;
   }
};
 
int main()
{
  Laptop laptopAnto, LaptopLisa;
 
  laptopAnto.hidupkanLaptop("Anto","Asus");
  LaptopLisa.hidupkanLaptop("Lisa","Acer");
  return 0;
}
```

Hasil kode program:

```
Hidupkan Laptop Asus Milik Anto
Hidupkan Laptop Acer Milik Lisa
```

Kali ini class Laptop memiliki member function **hidupkanLaptop()** dengan 2 buah parameter, yakni **pemilik** dan **merk**. Kedua parameter ini langsung di **cout** untuk membuat sebuah kalimat panjang.

Bisa diperhatikan juga kali ini member function **hidupkanLaptop()** tidak mengembalikan nilai. Sehingga kita menggunakan tipe data **void** sebelum nama member function.

Di dalam function main, saya membuat 2 buah object class **Laptop**, yakni **laptopAnto** dan **LaptopLisa**. Dari setiap object, dijalankan member function **hidupkanLaptop()** dengan argumen yang berbeda-beda.

---

### Cara Membuat Member Function dengan Default Parameter

Kita juga bisa membuat member function dengan default parameter seperti contoh berikut:

```Cpp
#include <iostream>
  
using namespace std;
  
class Laptop {
  public:
   void hidupkanLaptop(string pemilik = "Fulan", string merk = "Dell")
   {
     cout << "Hidupkan Laptop " << merk << " Milik " << pemilik;
     cout << endl;
   }
};
  
int main()
{
  Laptop laptopSekolah;
  
  laptopSekolah.hidupkanLaptop();
  laptopSekolah.hidupkanLaptop("Anto");
  laptopSekolah.hidupkanLaptop("Lisa","Acer");
  return 0;
}
```

Kali ini saya memodifikasi sedikit function **hidupkanLaptop()** dengan memberikan nilai default untuk parameter **pemilik = "Fulan"** dan parameter **merk = "Dell"**.

Dengan tambahan ini, maka member function **hidupkanLaptop()** bisa dipanggil dengan 2, 1 atau tanpa argumen sama sekali. Inilah yang dijalankan dari object **laptopSekolah** di baris 18 – 20.

---

### Memanggil Member Function Lain

Untuk class yang agak kompleks, sebuah member function bisa memanggil member function lain. Tanpa menjalankan kode program berikut bisakah anda menebak hasilnya?

```Cpp
#include <iostream>
 
using namespace std;
 
class Laptop {
 
  private:
   void hidupkanLaptop(string pemilik = "Fulan", string merk = "Dell")
   {
     cout << "Hidupkan Laptop " << merk << " Milik " << pemilik;
     cout << endl;
   }
 
   void matikanLaptop(string pemilik = "Fulan", string merk = "Dell")
   {
     cout << "Matikan Laptop " << merk << " Milik " << pemilik;
     cout << endl;
   }
 
  public:
   void restartLaptop()
   {
     matikanLaptop();
     hidupkanLaptop();
   }
 
};
 
int main()
{
  Laptop laptopSekolah;
 
  laptopSekolah.restartLaptop();
  return 0;
}
```

Di dalam class Laptop sekarang ada 3 buah member function: **hidupkanLaptop()**, **matikanLaptop()** dan **restartLaptop()**.

Member function **hidupkanLaptop()** dan **matikanLaptop()** memiliki hak akses **private**, sehingga tidak bisa lagi di akses dari luar class Laptop. Akan tetapi member function **restartLaptop()** tetap bisa mengakses kedua member function tersebut.

Di dalam function **main()**, saya men-instansiasi object **laptopSekolah** dari class **Laptop**, lalu menjalankan member function **restartLaptop()**. Berikut hasil yang tampil:

[![Contoh Kode Program Cara Pembuatan Method OOP C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Cara-Pembuatan-Method-OOP-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Cara-Pembuatan-Method-OOP-C.png)

Dari object **laptopSekolah** kita tidak bisa mengakses langsung method **hidupkanLaptop()** dan **matikanLaptop()** karena di proteksi dengan hak akses private.

---

Tutorial OOP C++ kali ini membahas tentang cara pembuatan member function di C++, termasuk penggunaan default parameter serta cara memanggil member function dari dalam member function lain.

Selanjutnya akan dibahas tentang [Pengertian Setter dan Getter dalam OOP C++](https://www.duniailkom.com/tutorial-belajar-oop-c-plus-plus-pengertian-setter-dan-getter/ "Tutorial Belajar OOP C++ Part 6: Pengertian Setter dan Getter").