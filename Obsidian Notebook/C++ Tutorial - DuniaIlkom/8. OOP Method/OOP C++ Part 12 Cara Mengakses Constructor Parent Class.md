---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-12-23T13:05:00
file_tanyaJawab: 
total_study: 1
id: DIOOP12
tags:
  - Cpp
  - OOP
spaced_repetition: true
sr-due: 2024-12-25
sr-interval: 2
sr-ease: 150
---
# Tutorial Belajar OOP C++ Part 12: Cara Mengakses Constructor Parent Class

09 Nov 20 

Untuk kode program OOP C++ yang cukup besar, biasanya setiap class memiliki constructor yang dipakai untuk proses pengisian data member atau proses lainnya.

Situasinya menjadi agak rumit jika parent class memiliki constructor yang juga butuh data argumen. Penjelasan tentang kalimat ini akan kita bahas beserta contoh kode program.

---

### Constructor dalam Inheritance

Penjelasan tentang **constructor** sudah kita bahas di tutorial [Pengertian Constructor dan Destructor Object](https://www.duniailkom.com/tutorial-belajar-oop-c-plus-plus-pengertian-constructor-dan-destructor-object/ "Tutorial Belajar OOP C++ Part 7: Pengertian Constructor dan Destructor Object"). Disana dijelaskan bahwa _constructor_ adalah member function khusus yang dijalankan secara otomatis pada saat sebuah object dibuat.

Untuk class yang melibatkan penurunan (**inheritance**), constructor parent class akan dijalankan terlebih dahulu, setelah itu baru constructor child class.

Contoh kode program berikut membuktikan hal ini:

```Cpp
#include <iostream>
 
using namespace std;
 
class Komputer {
  public:
    Komputer(){
      cout << "Constructor class Komputer dijalankan" << endl;
    }
};
 
class Laptop: public Komputer {
  public:
    Laptop(){
      cout << "Constructor class Laptop dijalankan" << endl;
    }
};
 
int main()
{
  Laptop laptopAndi;
 
  return 0;
}
```

Hasil kode program:

```
Constructor class Komputer dijalankan
Constructor class Laptop dijalankan
```

Contoh kali ini masih menggunakan class **Laptop** yang diturunkan dari class **Komputer**. Tapi kali ini kedua class memiliki constructor yang masing-masingnya berisi perintah cout sederhana.

Ketika terjadi proses instansiasi class **Laptop** ke dalam object **laptopAndi** di dalam function main(), maka constructor class **Komputer** akan dijalankan terlebih dahulu, baru setelah itu constructor class **Laptop**.

---

### Constructor dengan Parameter /Argumen

Sekarang kita akan lihat contoh kasus jika constructor class Laptop butuh sebuah parameter atau argumen:

```Cpp
#include <iostream>
 
using namespace std;
 
class Komputer {
  public:
    Komputer(){
      cout << "Constructor class Komputer dijalankan" << endl;
    }
};
 
class Laptop: public Komputer {
  public:
    Laptop(string pemilik){
      cout << "Constructor class Laptop dijalankan" << endl;
      cout << "Laptop ini milik " << pemilik <<endl;
    }
};
 
int main()
{
  Laptop laptopAndi("Andi");
 
  return 0;
}
```

Hasil kode program:

```
Constructor class Komputer dijalankan
Constructor class Laptop dijalankan
Laptop ini milik Andi
```

Pada saat proses pembuatan object **laptopAndi** di baris 22, saya mengirim satu argument bertipe string dengan nilai "**Andi**". Penulisan seperti ini artinya constructor class Laptop akan menerima satu nilai inputan.

Nilai argument "Andi" akan diterima oleh parameter **pemilik** seperti di baris 14. Parameter pemilik ini kemudian langsung di **cout** dalam constructor dengan perintah **cout << "Laptop ini milik " << pemilik**. Hasilnya, akan tampil teks "**Laptop ini milik Andi**".

Jika anda masih kurang paham tentang kode program diatas, boleh dipelajari secara perlahan karena materi setelah ini akan cukup rumit.

---

### Mengirim Argumen ke Constructor Parent Class

Kita berangkat dari kode sebelumnya. Sekarang saya akan membuat constructor class **Komputer** agar bisa menerima satu argumen seperti kode program berikut:

```Cpp
#include <iostream>
 
using namespace std;
 
class Komputer {
  public:
    Komputer(string pemilik){
      cout << "Constructor class Komputer dijalankan" << endl;
      cout << "Komputer ini milik " << pemilik <<endl;
    }
};
 
class Laptop: public Komputer {
  public:
    Laptop(string pemilik){
      cout << "Constructor class Laptop dijalankan" << endl;
      cout << "Laptop ini milik " << pemilik <<endl;
    }
};
 
int main()
{
  Laptop laptopAndi("Andi");
 
  return 0;
}
```

Perubahan ada di dalam class **Komputer** yang sekarang constructor-nya juga memiliki sebuah parameter untuk menampung data **pemilik** (baris 7).

Akan tetapi kode program diatas akan menghasilkan error: _no matching function for call to 'Komputer::Komputer()'_. Ini terjadi karena jika constructor parent class butuh argument, maka kita harus memanggil constructor tersebut secara manual.

Berikut cara pemanggilannya:

```Cpp
#include <iostream>
 
using namespace std;
 
class Komputer {
  public:
    Komputer(string pemilik){
      cout << "Constructor class Komputer dijalankan" << endl;
      cout << "Komputer ini milik " << pemilik <<endl;
    }
};
 
class Laptop: public Komputer {
  public:
    Laptop(string pemilik) : Komputer(pemilik) {
      cout << "Constructor class Laptop dijalankan" << endl;
      cout << "Laptop ini milik " << pemilik <<endl;
    }
};
 
int main()
{
  Laptop laptopAndi("Andi");
 
  return 0;
}
```

Hasil kode program:

```
Constructor class Komputer dijalankan
Komputer ini milik Andi
Constructor class Laptop dijalankan
Laptop ini milik Andi
```

Perhatikan di baris 15. Itulah cara untuk memanggil constructor parent class, yakni dengan format:

```Cpp
NamaChildClass(tipe_data param1, ...) : NamaParentClass(arg1, arg2,...) {
  // isi class 
}
```

Dengan tambahan kode program ini maka kita sudah bisa mengirim nilai argument **pemilik** dari class **Laptop** ke dalam parameter **pemilik** milik constructor class **Komputer**.

---

### Last Exercise…

Sebagai latihan terakhir, bisakah anda memahami alur dari kode program berikut?

```Cpp
#include <iostream>
 
using namespace std;
 
class Komputer {
  protected:
    string processor;
    string merk;
    string memory;
 
  public:
    Komputer(string proc, string mer, string mem){
      processor = proc;
      merk = mer;
      memory = mem;
    }
};
 
class Laptop: public Komputer {
  public:
    Laptop(string proc, string mer, string mem)
    : Komputer(proc, mer, mem) { }
 
    string lihatSpec() {
      return "Merk: " + merk + ", processor: "+ processor +
             ", jumlah memory: " + memory;
    }
};
 
int main()
{
  Laptop laptopAndi("Intel Core i5","Asus","6GB");
  Laptop laptopReza("AMD Rizen 5","Dell","12GB");
 
  cout << laptopAndi.lihatSpec() << endl;
  cout << laptopReza.lihatSpec() << endl;
 
  return 0;
}
```

Hasil kode program:

[![Contoh Kode Program Constructor Parent Class OOP Cpp](https://www.duniailkom.com/wp-content/uploads/2020/11/Contoh-Kode-Program-Constructor-Parent-Class-OOP-Cpp.png)](https://www.duniailkom.com/wp-content/uploads/2020/11/Contoh-Kode-Program-Constructor-Parent-Class-OOP-Cpp.png)

Kode program ini lumayan kompleks dan melibatkan banyak konsep OOP C++ yang kita pelajari sejauh ini. Diantaranya terkait hak akses **private** dan **public** (_encapsulation_), **constructor**, serta penurunan class (_inheritance_).

Kembali, pembacaan kode program sebaiknya dilakukan dari function **main()**, lalu berangkat bertahap menelusuri aliran data.

Di dalam function **main()**, terdapat proses instansiasi untuk 2 buah object dari class **Laptop**. Object yang dibuat adalah **laptopAndi** dan **laptopReza**. Kedua object mengirimkan 3 buah argumen, sehingga bisa dipastikan constructor class **Laptop** juga memiliki 3 parameter untuk menampung nilai-nilai ini.

Pembuatan constructor class **Laptop** ada di baris 21 – 22. Argumen yang dikirim saat pembuatan object akan ditampung oleh parameter **proc**, **mer**, dan **mem**. Ternyata ketiga parameter ini langsung dikirim ke dalam argument constructor class **Komputer**, yakni dengan perintah **: Komputer(proc, mer, mem**).

Di dalam class **Komputer**, ketiga argumen tadi ditampung lagi ke dalam parameter **proc**, **mer**, dan **mem** seperti di baris 12. Isi constructor ini berupa proses inisialisasi data member dengan 3 perintah berikut:

```Cpp
processor = proc;
merk = mer;
memory = mem;
```

Artinya jika pada saat pembuatan object dijalankan perintah **Laptop laptopAndi("Intel Core i5","Asus","6GB")**, maka di dalam constructor class Komputer akan terjadi kode program berikut:

```Cpp
processor = "Intel Core i5";
merk = "Asus";
memory = "6GB";
```

Inilah proses yang terjadi saat pembuatan object laptopAndi. Sehingga ketika di akses perintah **cout << laptopAndi.lihatSpec()** di dalam function main(), function **lihatSpec()** milik class Laptop tinggal mengakses ketiga data member untuk menampilkan hasil: **Merk: Asus, processor: Intel Core i5, jumlah memory: 6GB**.

Hal yang sama juga terjadi untuk object **laptopReza**.

---

Dalam tutorial OOP C++ kali ini kita telah membahas tentang cara mengakses **constructor parent class** secara manual. Cara tersebut diperlukan hanya jika constructor parent class butuh data argumen atau parameter. Namun jika constructor parent class tidak butuh data tersebut, constructor parent class akan dijalankan secara otomatis.

Untuk sementara tutorial ini juga menutup pembahasan tentang OOP C++ di Duniailkom. Mudah-mudahan materi yang ada bisa membantu anda dalam memahami object oriented programming atau pemrograman berorientasi objek C++.

Akhir kata, semoga bermanfaat dan sampai jumpa di tutorial bahasa pemrograman Duniailkom lainnya.