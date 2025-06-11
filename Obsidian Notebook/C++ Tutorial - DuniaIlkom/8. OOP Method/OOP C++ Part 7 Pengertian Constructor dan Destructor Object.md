---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-12-22T22:22:00
file_tanyaJawab: 
total_study: 1
id: DIOOP7
tags:
  - Cpp
  - OOP
spaced_repetition: true
sr-due: 2024-12-24
sr-interval: 2
sr-ease: 150
---
# Tutorial Belajar OOP C++ Part 7: Pengertian Constructor dan Destructor Object

06 Nov 20 

Melanjutkan tutorial belajar Object Oriented Programming (OOP) C++, kali ini kita akan bahas Pengertian Constructor dan Destructor dalam bahasa pemrograman C++.

---

### Pengertian Constructor OOP C++

**Constructor** adalah member function khusus yang dijalankan secara otomatis pada saat sebuah object dibuat, yakni saat proses **instansiasi**.

Constructor biasa dipakai untuk membuat proses awal dalam persiapan object, seperti memberi nilai kepada data member, memanggil member function internal serta beberapa proses lain yang dirasa perlu.

Dalam bahasa C++, constructor dibuat dengan cara menulis sebuah member function yang namanya sama dengan nama class. Sebagai contoh jika kita memiliki **class Laptop**, maka function constructor juga harus bernama **Laptop()**.

Sebuah constructor tidak mengembalikan nilai sehingga tidak perlu menulis tipe data sebelum nama function. Constuctor juga harus di set sebagai **public**, jika tidak kita tidak bisa men-instansiasi class tersebut.

Ciri lain dari constructor adalah, hanya boleh ada satu constuctor di setiap class.

---

### Contoh Kode Program Pembuatan Constructor OOP C++

Berikut contoh kode program cara membuat Constructor dalam bahasa C++:

```Cpp
#include <iostream>
 
using namespace std;
 
class Laptop {
 
  public:
    Laptop() {
      cout << "Satu object Laptop sudah di buat" << endl;
    }
 
};
 
int main()
{
  Laptop laptopAndi;
  Laptop laptopLisa;
  Laptop laptopRudi;
 
  return 0;
}
```

Dalam kode program di atas saya kembali membuat **class** **Laptop**. Class Laptop memiliki 1 constructor **Laptop()** seperti di baris 8 – 10 yang hanya berisi satu perintah **cout**.

Kemudian di dalam kode program main() saya membuat 3 buah object **class** **Laptop**, yakni object **laptopAndi**, **laptopLisa** dan **laptopRudi**.

Pada saat ketiga object di instansiasi oleh compiler C++, secara otomatis constructor akan dijalankan. Hasilnya akan tampil 3 baris teks berikut di jendela cmd:

```
Satu object Laptop sudah di buat
Satu object Laptop sudah di buat
Satu object Laptop sudah di buat
```

Semua teks ini berasal dari perintah **cout** di dalam member function **Laptop()**.

---

### Constructor Sebagai Tempat Inisialisasi Data member

Salah satu fungsi utama dari constructor adalah untuk inisialisasi data member, yakni proses pemberian nilai awal kepada data member yang ada di dalam object:

```Cpp
#include <iostream>
 
using namespace std;
 
class Laptop {
 
  private:
    string pemilik;
    string merk;
 
  public:
    Laptop(string var1, string var2) {
      pemilik = var1;
      merk = var2;
 
      cout << "Object Laptop "<< merk << " punya " << pemilik
           << " sudah dibuat" << endl;
    }
 
};
 
int main()
{
  Laptop laptopAndi("Andi","Asus");
  Laptop laptopLisa("Lisa","Acer");
  Laptop laptopRudi("Rudi","Lenovo");
 
  return 0;
}
```

Hasil kode program:

```
Object Laptop Asus punya Andi sudah dibuat
Object Laptop Acer punya Lisa sudah dibuat
Object Laptop Lenovo punya Rudi sudah dibuat
```

Sekarang class **Laptop** saya tambah dengan 2 buah data member: **pemilik** dan **merk**. Seperti yang pernah kita bahas dalam tutorial tentang [setter dan getter](https://www.duniailkom.com/tutorial-belajar-oop-c-plus-plus-pengertian-setter-dan-getter/ "Tutorial Belajar OOP C++ Part 6: Pengertian Setter dan Getter"), idealnya data member ini di set sebagai **private**.

Proses pemberian nilai awal ke dalam kedua data member dilakukan dari **constructor**. Constructor **Laptop()** sekarang menerima 2 buah parameter: **var1** dan **var2**. Nilai inilah yang kemudian di isi ke dalam data member **pemilik** dan **merk**.

Untuk membuktikaan proses inisialisasi variabel sudah berhasil, saya langsung menampilkannya dengan perintah **cout** dari dalam constructor.

Sewaktu pembuatan object di baris 24 – 26, kita juga harus menulis 2 buah argument pada saat proses instansiasi object, sesuai dengan jumlah parameter yang dibutuhkan constructor.

---

### Pengertian Destructor OOP C++

**Destructor** adalah member function khusus yang dijalankan secara otomatis pada saat sebuah objek dihapus.

Di dalam C++, seluruh objek sebenarnya sudah otomatis dihapus ketika kode selesai diproses. Dengan demikian dalam penggunaan umum, destructor ini relatif jarang dipakai.

Salah satu kasus dimana perlu destructor adalah jika kode program kita mengakses memory komputer secara langsung (menggunakan pointer), maka destructor bisa dipakai untuk "melepaskan" ruang memory tersebut agar tidak terjadi memory leak.

**Memory leak** adalah istilah programming dimana sebuah aplikasi menggunakan memory RAM terlalu besar dan terus membesar sepanjang program berjalan. Memory leak merupakan bug yang harus dihindari, tapi selama kita tidak menggunakan pointer, seharusnya tidak ada masalah.

Dalam C++, destructor dibuat menggunakan nama member function yang sama dengan nama class, tapi diawali dengan karakter tilde " `~` ". Karakter tilde ini biasa berada di sebelah kiri angka 1 keybord dan ditekan dengan tombol SHIFT.

Sebagai contoh jika kita memiliki **class Laptop**, maka function desctructor akan bernama **~Laptop()**.

Mirip seperti **constructor**, **destructor** juga tidak butuh tipe data kembalian. Dan dalam sebuah class hanya bisa terdapat satu member function destructor. Berbeda dengan constructor, destructor tidak bisa menerima parameter / argumen.

---

### Contoh Kode Program Pembuatan Destructor OOP C++

Berikut contoh kode program cara membuat Destructor dalam bahasa C++:

```Cpp
#include <iostream>
 
using namespace std;
 
class Laptop {
 
  public:
    ~Laptop() {
      cout << "Satu object Laptop sudah di hapus" << endl;
    }
};
 
int main()
{
  Laptop laptopAndi;
  Laptop laptopLisa;
  Laptop laptopRudi;
 
  return 0;
}
```

Hasil kode program:

```
Satu object Laptop sudah di hapus
Satu object Laptop sudah di hapus
Satu object Laptop sudah di hapus
```

Pendefinisian member function destructor ada di baris 8 – 10, yakni dari function **~Laptop()**. Isi desctuctor hanya berupa perintah **cout** "Satu object Laptop sudah di hapus".

Di dalam function **main()** saya kembali membuat 3 buah object dari class **Laptop**. Tepat ketika kode program selesai di proses, destructor dari ketiga object akan dipanggil dan tampil 3 kali teks "Satu object Laptop sudah di hapus".

---

### Contoh Kode Program Constructor dan Destructor C++

Sebagai contoh penutup, berikut kode program lengkap dengan menggabungkan constructor dan destructor C++:

```Cpp
#include <iostream>
 
using namespace std;
 
class Laptop {
 
  private:
    string pemilik;
    string merk;
 
  public:
    Laptop(string var1, string var2) {
      pemilik = var1;
      merk = var2;
 
      cout << "Object Laptop " << pemilik << " sudah dibuat" << endl;
    }
 
    ~Laptop() {
      cout << "Object Laptop " << pemilik << " sudah dihapus" << endl;
    }
 
    string hidupkanLaptop() {
      return "Hidupkan Laptop " + merk + " Milik " + pemilik;
    }
 
};
 
int main()
{
  Laptop laptopAndi("Andi","Asus");
  Laptop laptopLisa("Lisa","Acer");
  Laptop laptopRudi("Rudi","Lenovo");
 
  cout << "     ====================     "<< endl;
  cout << laptopAndi.hidupkanLaptop() << endl;
  cout << laptopLisa.hidupkanLaptop() << endl;
  cout << laptopRudi.hidupkanLaptop() << endl;
  cout << "     ====================     "<< endl;
 
  return 0;
}
```

Hasil kode program:

[![Contoh Kode Program Cara Membuat Constructor dan Destructor OOP C++](https://www.duniailkom.com/wp-content/uploads/2020/11/Contoh-Kode-Program-Cara-Membuat-Constructor-dan-Destructor-OOP-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/11/Contoh-Kode-Program-Cara-Membuat-Constructor-dan-Destructor-OOP-C.png)

Silahkan pelajari sejenak kode program di atas dan sesuaikan dengan materi yang sudah kita pelajari. Dalam kode ini saya membuat constuctor, destructor dan juga member function biasa bernama **hidupkanLaptop()**.

Alur yang akan di proses adalah dari constructor **Laptop()** terlebih dahulu, lalu member function **hidupkanLaptop()**, dan terakhir baru destructor **~Laptop()**.

---

Dalam tutorial belajar OOP C++ kali ini kita telah membahas pengertian **constructor** dan juga **destructor**. Kedua konsep ini sangat penting dipahami, terutama **constructor** yang akan sering di pakai. Sedangkan penggunaan destructor sendiri relatif jarang.

Berikutnya dalam lanjutan OOP C++ akan dibahas tentang [Pengertian Inheritance (Pewarisan Class)](https://www.duniailkom.com/tutorial-belajar-oop-c-plus-plus-pengertian-inheritance-pewarisan-class/ "Tutorial Belajar OOP C++ Part 8: Pengertian Inheritance (Pewarisan Class)").