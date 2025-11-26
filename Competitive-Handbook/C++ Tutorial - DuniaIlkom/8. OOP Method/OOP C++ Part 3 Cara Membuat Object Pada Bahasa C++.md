---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-12-22T17:34:00
file_tanyaJawab: 
total_study: 1
id: DIOOP3
tags:
  - Cpp
  - OOP
spaced_repetition: true
sr-due: 2024-12-24
sr-interval: 2
sr-ease: 150
---
# Tutorial Belajar OOP C++ Part 3: Cara Membuat Object Pada Bahasa C++

04 Nov 20 

Melanjutkan tutorial belajar Objek Oriented Programming (OOP) C++, kali ini akan dibahas tentang Cara Membuat Object Pada Bahasa C++, serta cara mengakses data member dan member function yang terdapat di dalam object tersebut.

---

### Cara Membuat Objek pada Bahasa C++

Istilah **Object** dalam **Object Oriented Programming (OOP) C++**, sebenarnya terdiri dari **class, data member, member function** dan **object**. Keempat istilah ini telah kita pelajari dalam tutorial sebelumnya.

Merangkum apa yang telah dibahas, berikut contoh cara pembuatan objek C++:

```Cpp
#include <iostream>
 
using namespace std;
 
// buat class Laptop
class Laptop {
 
  // buat 3 data member untuk class Laptop
  string pemilik;
  string merk;
  double ukuranLayar;
 
  // buat 2 member function untuk class Laptop
  string hidupkanLaptop() {
    return "Hidupkan Laptop";
  }
 
  string matikanLaptop() {
    return "Matikan Laptop";
  }
};
 
int main()
{
  // buat objek dari class Laptop (instansiasi)
  Laptop LaptopAndi;
  return 0;
}
```

Dalam kode ini saya membuat sebuah **class** dengan nama **Laptop** lengkap dengan 3 **data member** dan 2 **member function**. Kemudian di dalam function main() terdapat perintah untuk membuat 1 **object** class Laptop dengan nama **LaptopAndi**.

Walaupun kita telah membuat object, namun belum menampilkan hasil apa-apa karena class Laptop belum berisi data apapun. Kita akan segera pelajari cara mengakses isi **class** menggunakan kode C++.

> [!NOTE]
> Mungkin anda akan bertanya kenapa kita menggunakan contoh class **Laptop** yang agak jauh dari istilah praktek kode program. Jawabannya agar menyederhanakan penjelasan.
> 
> Object Oriented Programming memiliki aturan dan alur program yang cukup rumit sehingga menggunakan contoh sederhana seperti Laptop bisa mempermudah pemahaman.
> 
> Dalam buku-buku yang membahas **OOP**, jenis class yang aneh ini juga sering digunakan seperti **class** **Mobil**, **class** **Sapi** maupun **class** **Kucing**. Sekali lagi, ini hanya untuk menyederhanakan pemahaman.

---

### Cara Mengakses Objek dalam C++

Cara mengakses objek yang dimaksud disini adalah cara untuk mengakses 'isi' dari sebuah **object**, yakni data member dan member function. Agar lebih mudah dipahami, berikut revisi contoh **class** **Laptop** sebelumnya:

```Cpp
#include <iostream>
 
using namespace std;
 
// buat class Laptop
class Laptop {
  public:
    // buat 3 data member untuk class Laptop
    string pemilik;
    string merk;
    double ukuranLayar;
 
    // buat 2 member function untuk class laptop
    string hidupkanLaptop() {
      return "Hidupkan Laptop";
    }
 
    string matikanLaptop() {
      return "Matikan Laptop";
    }
};
 
int main()
{
  // buat objek dari class Laptop (instansiasi)
  Laptop laptopAnto;
 
  // set data member
  laptopAnto.pemilik = "Anto";
  laptopAnto.merk = "Asus";
  laptopAnto.ukuranLayar = 15.6;
 
  // tampilkan data member
  cout << laptopAnto.pemilik << endl;
  cout << laptopAnto.merk << endl;
  cout << laptopAnto.ukuranLayar << endl;
 
  // tampilkan member function
  cout << laptopAnto.hidupkanLaptop() << endl;
  cout << laptopAnto.matikanLaptop() << endl;
 
  return 0;
}
```

Hasil kode program

```
Anto
Asus
15.6
Hidupkan Laptop
Matikan Laptop
```

Kode ini memang cukup panjang, dan akan kita bahas secara perlahan:

```Cpp
class Laptop {
  public:
```

Ini adalah baris awal pembuatan **class Laptop**. Kurung kurawal menandakan awal dari class. Setelah itu terdapat keyword baru bernama **public**. **Public** adalah salah satu bentuk **access specifiers** yang berfungsi membatasi hak akses ke data member dan member function milik class.

Dengan menulis **public**, maka semua data member dan member function yang akan kita buat bisa diakses dari luar class. Lebih lanjut tentang _access specifiers_ ini akan di bahas dalam tutorial berikutnya.

```Cpp
string pemilik;
string merk;
double ukuranLayar;
```

Tiga baris di atas merupakan pendefinisian variabel **class** atau dikenal dengan istilah **data member** (kadang disebut juga sebagai **property** atau **attribute**). Data member sebenarnya adalah variabel biasa yang berada di dalam class.

```Cpp
string hidupkanLaptop() {
  return "Hidupkan Laptop";
}
 
string matikanLaptop() {
  return "Matikan Laptop";
}
```

Dua buah fungsi ini adalah member function dari **class Laptop** (kadang disebut juga sebagai **method**).

Jika anda telah memahami cara pembuatan **function**, kedua contoh ini hanyalah function C++ biasa yang akan mengembalikan nilai string. Pembahasan tentang cara penggunaan function C++pernah kita bahas pada [Tutorial C++ Cara Membuat Fungsi](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-cara-membuat-fungsi-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 37: Cara Membuat Fungsi (Function) Bahasa C++").

```Cpp
int main()
{
  // buat objek dari class Laptop (instansiasi)
  Laptop laptopAnto;
```

Setelah selesai mendefinisikan **class Laptop**, kita masuk ke function main(). Baris **Laptop laptopAnto** adalah perintah untuk membuat **objek** dari **class** **Laptop**, yakni sebuah proses **instansiasi**.

Perintah **Laptop laptopAnto** akan membuat sebuah variabel laptopAnto yang berisi object dari class Laptop. Kita akan mengakses data member dan member function class Laptop melalui object **laptopAnto** ini.

```Cpp
laptopAnto.pemilik = "Anto";
laptopAnto.merk = "Asus";
laptopAnto.ukuranLayar = 15.6;
```

Ketiga baris di atas adalah cara mengisi nilai ke dalam data member dari **object** **laptopAnto**. Cara pengisiannya sama seperti mengisi nilai ke variabel, yakni dari kanan ke kiri (operasi assignment).

Perhatikan tanda titik untuk mengakses data member dari **objek**. Tanda titik ini adalah operator khusus yang dikenal dengan istilah **Object Operator**.

```Cpp
cout << laptopAnto.pemilik << endl;
cout << laptopAnto.merk << endl;
cout << laptopAnto.ukuranLayar << endl;
```

Kode program di atas dipakai untuk menampilkan nilai data member objek **laptopAnto** yang sebelumnya telah kita set. Sama seperti pada saat men-set nilai data member, kita juga menggunakan titik diikuti dengan nama data member yang ingin di akses. Perintah **cout** ditambahkan agar compiler C++ menampilkan nilai setiap data member.

```Cpp
cout << laptopAnto.hidupkanLaptop() << endl; 
cout << laptopAnto.matikanLaptop() << endl;
```

Kode terakhir ini adalah cara pemanggilan **member function** dari object **laptopAnto**. Cara pengaksesannya sama dengan cara mengakses data member, namun karena member function adalah fungsi, kita harus menambah tanda kurung di akhir pemanggilan.

---

### Object Sebagai Entitas Terpisah

Dalam contoh kode di atas saya hanya menggunakan 1 buah **object** yang berasal dari **class Laptop**.

Namun pada dasarnya sebuah class bisa dipakai untuk membuat banyak object. Setiap objek akan saling terpisah namun tetap memiliki semua data member dan member function yang berasal dari class **Laptop**.

Berikut adalah contoh pembuatan beberapa **object** dari class Laptop:

```Cpp
#include <iostream>
 
using namespace std;
 
class Laptop {
  public:
    string pemilik;
    string hidupkanLaptop() {
      return "Hidupkan Laptop";
    }
};
 
int main()
{
  Laptop laptopAnto;
  Laptop laptopAndi;
  Laptop laptopDina;
 
  laptopAnto.pemilik = "Anto";
  laptopAndi.pemilik = "Andi";
  laptopDina.pemilik = "Dina";
 
  cout << "Pemilik Laptop: " << laptopAnto.pemilik << endl;
  cout << "Pemilik Laptop: " << laptopAndi.pemilik << endl;
  cout << "Pemilik Laptop: " << laptopDina.pemilik << endl;
 
  return 0;
}
```

Hasil kode program:

[![Contoh Kode Program Cara Pembuatan Object C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Cara-Pembuatan-Object-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Cara-Pembuatan-Object-C.png)

**Class** **Laptop** sedikit di sederhanakan agar lebih singkat. Setelah pendefinisian class Laptop di baris 5 – 11, saya membuat 3 buah object dari class Laptop, yakni **laptopAnto**, **laptopAndi** dan **laptopDina**. Ketiga objek memiliki struktur yang sama namun memiliki isi data yang berbeda.

---

Dalam tutorial kali ini kita telah membahas tentang Cara Membuat Object Pada Bahasa C++. Berikutnya di akan bahas tentang [Pengertian Public, Protected dan Private dalam C++](https://www.duniailkom.com/tutorial-belajar-oop-c-plus-plus-pengertian-public-protected-dan-private-enkapsulasi/ "Tutorial Belajar OOP C++ Part 4: Pengertian Public, Protected dan Private (Enkapsulasi)"). Ketiga hak akses ini dipakai untuk membuat fitur Enkapsulasi dalam OOP.