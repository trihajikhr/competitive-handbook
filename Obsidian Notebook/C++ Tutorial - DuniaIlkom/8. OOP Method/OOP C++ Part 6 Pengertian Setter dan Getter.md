---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-12-22T21:57:00
file_tanyaJawab: 
total_study: 1
id: DIOOP6
tags:
  - Cpp
  - OOP
spaced_repetition: true
sr-due: 2024-12-24
sr-interval: 2
sr-ease: 150
---
# Tutorial Belajar OOP C++ Part 6: Pengertian Setter dan Getter

05 Nov 20 

Ketika membahas tentang member function dan enkapsulasi (hak akses **public**, **private** dan **protected**), kadang kita akan bertemu dengan istilah **Setter** dan **Getter**. Dalam lanjutan tutorial OOP C++ kali ini kita akan bahas maksud dari kedua istilah tersebut.

---

### Pengertian Setter dan Getter

**Setter** adalah member function atau method yang dipakai untuk memberikan nilai ke dalam sebuah data member. Sedangkan **Getter** adalah member function yang dipakai untuk menampilkan nilai data member.

Perlunya penggunaan setter dan getter berangkat dari sebuah tips atau saran bahwa semua data member suatu class harusnya di set sebagai **private** (bukan **public**).

Jika semua data member di set sebagai private, maka kita tidak bisa lagi memberikan nilai dan mengakses nilai data member secara langsung.

Berikut contoh kode program yang memberikan nilai dan mengakses nilai data member secara langsung:

```Cpp
#include <iostream>
 
using namespace std;
 
class Laptop {
  public:
   string pemilik;
   double lebarLayar;
};
 
int main()
{
  Laptop laptopAndi;
 
  laptopAndi.pemilik = "Andi";
  laptopAndi.lebarLayar = 14;
 
  cout << laptopAndi.pemilik << endl;
  cout << laptopAndi.lebarLayar << endl;
 
  return 0;
}
```

Hasil kode program:

```
Andi
14
```

**Class Laptop** memiliki 2 data member **public**, yakni **pemilik** dan **lebarLayar**. Karena di set dengan hak akses public, maka kita bisa memberikan nilai ke dalamnya seperti di baris 15 – 16 dan menampilkan nilai data member seperti di baris 18-19.

Sebenarnya tidak ada yang salah dari kode program di atas, hanya saja _best practice_ yang umum berlaku dalam konsep OOP adalah, data member sebaiknya tidak diakses langsung seperti ini. Hak akses data member seharusnya di set sebagai **private** atau **protected**, lalu diakses menggunakan **getter** dan **setter**.

---

### Contoh Kode Program Setter C++

Sebelumnya sudah dibahas bahwa **setter** adalah member function yang dipakai untuk memberikan nilai ke dalam sebuah data member. Nama setter sebenarnya boleh bebas, selama berfungsi untuk men-set nilai data member.

Akan tetapi kebiasaan yang berlaku untuk setter adalah membuat nama member function dengan awalan kata "**set**", lalu diikuti dengan nama data member yang ingin di-set.

Sebagai contoh, jika kita ingin membuat setter untuk data member **pemilik**, maka nama member functionnya menjadi **setPemilik()**. Atau setter untuk data member **lebarLayar** akan menjadi **setLebarLayar()**.

Berikut contoh kode program setter untuk class **Laptop**:

```Cpp
#include <iostream>
 
using namespace std;
 
class Laptop {
 
  private:
   string pemilik;
   double lebarLayar;
 
  public:
    void setPemilik(string var1) {
      pemilik = var1;
    }
 
    void setLebarLayar(double var2) {
      lebarLayar = var2;
    }
};
 
int main()
{
  Laptop laptopAndi;
 
  laptopAndi.setPemilik("Andi");
  laptopAndi.setLebarLayar(14);
 
  return 0;
}
```

Di baris 7 saya sudah mengubah hak akses data member dari **public** menjadi **private**. Akibatnya data member **pemilik** dan **lebarLayar** tidak bisa lagi diakses dari luar class Laptop.

Oleh karena itulah terdapat tambahan setter **setPemilik()** dan **setLebarLayar()** di baris 12 – 18. Kedua member function ini butuh satu parameter yang akan menampung argument inputan. Parameter **var1** akan diinput ke dalam data member **pemilik**, sedangkan parameter **var2** akan diinput ke dalam data member **lebarLayar**.

Kedua setter dipanggil di baris 25 dan 26 menggunakan perintah **laptopAndi.setPemilik("Andi")** dan **laptopAndi.setLebarLayar(14)**. Setelah menjalankan kedua member function ini, maka data member **pemilik** dan **lebarLayar** akan berisi string **"Andi"** dan angka double **14.**

---

### Contoh Kode Program Member function Getter C++

Kita sudah selesai membuat **setter** untuk memberikan nilai ke dalam data member. Kali ini giliran membuat **getter** yang dipakai untuk menampilkan nilai data tersebut.

Jika penamaan setter menggunakan awalan "**set**", maka getter menggunakan awalan "**get**" yang diikuti dengan nama data member yang akan diakses seperti **getPemilik()** atau **getLebarLayar()**.

Berikut contoh kode program getter untuk class **Laptop**:

```Cpp
#include <iostream>
 
using namespace std;
 
class Laptop {
 
  private:
   string pemilik;
   double lebarLayar;
 
  public:
    void setPemilik(string var1) {
      pemilik = var1;
    }
 
    void setLebarLayar(double var2) {
      lebarLayar = var2;
    }
 
    string getPemilik() {
      return pemilik;
    }
 
    double getLebarLayar() {
      return lebarLayar;
    }
};
 
int main()
{
  Laptop laptopAndi;
 
  laptopAndi.setPemilik("Andi");
  laptopAndi.setLebarLayar(14);
 
  cout << laptopAndi.getPemilik() << endl;      // Andi
  cout << laptopAndi.getLebarLayar() << endl;   // 14
 
  return 0;
}
```

Pendefinisian getter ada di baris 20 – 26. Kedua member function ini tidak butuh parameter dan hanya mengembalikan nilai data member **pemilik** dan **lebarLayar**.

Di dalam function main(), getter diakses dengan perintah **cout << laptopAndi.getPemilik()** dan **cout << laptopAndi.getLebarLayar()**.

---

### Kenapa Harus Menggunakan Setter dan Getter?

Pertanyaan umum ketika selesai mempelajari **setter** dan **getter** adalah, kenapa repot-repot seperti ini? bukankah akan lebih mudah jika data member di set saja sebagai public agar bisa langsung diakses?

Salah satu alasannya adalah agar class kita menjadi lebih fleksibel. Dengan menggunakan setter dan getter, kita bisa melakukan pemrosesan atau proses validasi sebelum mengakses data member. Berikut contoh yang dimaksud:

```Cpp
#include <iostream>
 
using namespace std;
 
class Laptop {
 
  private:
   string pemilik;
   double lebarLayar;
 
  public:
    void setPemilik(string var1) {
      pemilik = var1;
    }
 
    void setLebarLayar(double var2) {
      if (var2 < 20) {
        lebarLayar = var2;
      }
      else {
        lebarLayar = 20;
      }
    }
 
    string getPemilik() {
      return "Bapak/Ibu " + pemilik;
    }
 
    double getLebarLayar() {
      return lebarLayar;
    }
};
 
int main()
{
  Laptop laptopAndi;
 
  laptopAndi.setPemilik("Andi");
  laptopAndi.setLebarLayar(31);
 
  cout << laptopAndi.getPemilik() << endl;
  cout << laptopAndi.getLebarLayar() << endl;
 
  return 0;
}
```

Hasil kode program:

[![Contoh Kode Program Cara Pembuatan Setter dan Getter OOP C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Cara-Pembuatan-Setter-dan-Getter-OOP-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Cara-Pembuatan-Setter-dan-Getter-OOP-C.png)

Perhatikan isi setter **setLebarLayar()**. Saya membuat sebuah proses validasi sederhana. Yakni jika nilai parameter **var2** bernilai kurang dari 20, maka input nilai **var2** ke dalam data member **lebarLayar**. Namun jika nilai **var2** lebih dari 20, tetap input nilai 20 ke dalam data member lebarLayar.

Pembatasan seperti ini dilakukan karena sangat jarang ada laptop dengan ukuran layar lebih besar dari 20 inci. Sehingga kita perlu melakukan proses validasi terlebih dahulu.

Sebaliknya, di getter **getPemilik()**, saya menambah awalan "Bapak/Ibu " sebelum nilainya dikirim menggunakan perintah **return**.

Proses seperti ini tidak bisa dilakukan jika data member diakses secara langsung.

---

Dalam tutorial belajar OOP C++ kali ini kita telah membahas pengertian **setter** dan **getter** serta melihat contoh penggunaannya.

Setter dan Getter sebenarnya tidak wajib, dan biasanya lebih disarankan untuk project yang cukup besar dan perlu di _maintenance_ dalam jangka panjang. Untuk kode program sederhana, silahkan saja membuat data member sebagai **public** agar bisa diisi secara langsung.

Lanjut, tutorial setelah ini akan membahas tentang [Pengertian Constructor pada OOP C++](https://www.duniailkom.com/tutorial-belajar-oop-c-plus-plus-pengertian-constructor-dan-destructor-object/ "Tutorial Belajar OOP C++ Part 7: Pengertian Constructor dan Destructor Object").