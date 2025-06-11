---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-12-22T17:19:00
file_tanyaJawab: 
total_study: 1
id: DIOOP2
tags:
  - OOP
  - Cpp
spaced_repetition: true
sr-due: 2024-12-24
sr-interval: 2
sr-ease: 150
---
`review_history:: 2024-12-22, 2024-12-23`
# Tutorial Belajar OOP C++ Part 2: Pengertian Class dan Object

04 Nov 20 

**Pemrograman Berorientasi Objek** tidak hanya berisi **object** saja, tapi kita juga akan bertemu dengan istilah lain seperti _class_, _data member_ dan juga _member function_.

Dalam tutorial belajar OOP C++ kali ini akan dibahas tentang **Pengertian Class**, **Object**, **Data member** dan **Member function**. Keempat istilah inilah yang menjadi pondasi dasar dari sebuah Object Oriented Programming (OOP).

> Untuk memudahkan pemahaman dan agar sejalan dengan istilah aslinya, saya tetap menggunakan bahasa inggris untuk kata kunci C++, seperti: **class, object, data member** dan **member function**.

---

### Pengertian Class dalam Pemrograman Berorientasi Objek

Class adalah cetak biru atau _blueprint_ dari **object**. Class digunakan hanya untuk membuat kerangka dasar. Yang akan kita pakai nanti adalah hasil cetakan dari class, yakni **object**.

Sebagai analogi, **class** bisa diibaratkan dengan **laptop** atau **notebook**. Kita tahu bahwa _laptop_ memiliki ciri-ciri seperti _merk_, memiliki _keyboard_, memiliki _processor_, dan beberapa ciri khas lain yang menyatakan sebuah benda tersebut adalah _laptop_. Selain memiliki ciri-ciri, sebuah laptop juga bisa dikenakan tindakan, seperti: _menghidupkan laptop_ atau _mematikan laptop_.

_Class_ dalam analogi ini adalah gambaran umum tentang sebuah benda. Di dalam pemrograman nanti, contoh class seperti **User**, **Item**, **Siswa**, **Validate**, dll.

Di dalam C++, penulisan **class** diawali dengan _keyword_ **class**, kemudian diikuti dengan _nama dari class_. Aturan penulisan nama **class** sama seperti aturan penulisan _variabel_ dalam C++ (lebih tepatnya aturan **identifier**), yakni tidak boleh diawali angka dan tidak boleh mengandung spasi.

Kebiasaan programmer C++, nama class ditulis menggunakan **PascalCase** atau **UpperCamelCase**. Yakni cara penulisan dimana setiap kata diawali dengan huruf besar, termasuk kata pertama.

Berikut adalah contoh penulisan **class** dalam C++:

```Cpp
#include <iostream>
 
using namespace std;
 
class Laptop {
  // isi dari class Laptop...
  // isi dari class Laptop...
};
 
int main()
{
  // kode program
  // kode program
  return 0;
}
```

Sama seperti pendefinisian function, pendefinisian class juga harus dilakukan di luar function **main()**.

---

### Pengertian Data Member C++

**Data member** (atau kadang juga dengan _atribut_ atau _properti_) adalah data yang terdapat dalam sebuah **class**. Melanjutkan analogi tentang _laptop_, **data member** dari laptop bisa berupa _merk, warna, jenis processor, ukuran layar_, dan lain-lain.

Jika anda sudah terbiasa dengan program C++, **data member** ini sebenarnya hanyalah variabel yang terletak di dalam class. Seluruh aturan dan tipe data yang biasa diinput ke dalam variabel, juga bisa diinput ke dalam data member. Aturan tata cara penamaan data member sama dengan aturan penamaan variabel.

Berikut adalah contoh penulisan **class** dengan penambahan **data member**:

```Cpp
#include <iostream>
 
using namespace std;
 
class Laptop {
  string pemilik;
  string merk;
  double ukuranLayar;
};
 
int main()
{
  // kode program
  // kode program
  return 0;
}
```

Dari contoh di atas, **pemilik**, **merk** dan **ukuranLayar** adalah data member dari **class Laptop**. Seperti yang bisa kita lihat, penulisan data member di dalam C++ sama dengan cara penulisan variabel biasa, yakni dengan menulis tipe data diikuti dengan nama data member**.**

Sebuah class bisa saja tidak memiliki data member.

---

### Pengertian Member Function C++

**Member function** (kadang disebut juga sebagai _method_) adalah tindakan yang bisa dilakukan di dalam class. Jika menggunakan analogi **class Laptop**, maka contoh member function adalah: _menghidupkan laptop_, _mematikan laptop_, atau _mengganti cover laptop_.

Member function pada dasarnya adalah **_function_** yang berada di dalam **class**. Seluruh sifat function bisa diterapkan ke dalam member function, seperti bisa di isi argumen/parameter, mengembalikan nilai (dengan keyword _return_), dan lain-lain.

Berikut adalah contoh penulisan **class** **Laptop** dengan penambahan member function:

```Cpp
#include <iostream>
 
using namespace std;
 
class Laptop {
  void hidupkanLaptop() {
    //... isi dari member function hidupkanLaptop
  }
 
  string matikanLaptop() {
    //... isi dari member function matikanLaptop
  }
};
 
int main()
{
  // kode program
  // kode program
  return 0;
}
```

Dari contoh di atas, function **hidupkanLaptop()** dan **matikanLaptop()** adalah member function dari class **Laptop**.

Seperti yang kita lihat, penulisan member function di dalam C++ sama saja dengan cara penulisan **function**. Termasuk menulis tipe data kembalian sebelum nama function. Tergantung kebutuhan, sebuah class tidak harus memiliki member function meskipun ini sangat jarang.

---

### Pengertian Object

**Object** atau **Objek** adalah hasil cetak dari **class**, atau bisa juga disebut hasil konkrit dari **class**. Masih menggunakan analogi **class Laptop**, maka objek dari **class Laptop** bisa berupa: laptopAndi, laptopAnto, atau laptopDuniailkom.

Sebuah objek dari **class Laptop** akan memiliki seluruh ciri-ciri laptop, termasuk data member dan member function-nya.

Proses mencetak objek dari class ini disebut dengan **instansiasi** (atau **instantiation**). Pada C++, proses instansiasi dilakukan dengan menulis nama class, lalu diikuti dengan nama variabel di dalam function **main()**.

Ini sebenarnya mirip seperti pembuatan variabel biasa, hanya saja jika dalam variabel biasa kita menulis tipe data terlebih dahulu. Sementara untuk instansiasi object, tipe data ini diganti dengan nama class.

Hasil cetakan **class** akan disimpan dalam variabel untuk selanjutnya digunakan dalam proses program. Variabel inilah yang akan berisi object dari sebuah class.

Sebagai contoh, berikut cara membuat object **laptopAndi** dan **laptopAnto** yang dibuat dari **class Laptop**:

```Cpp
#include <iostream>
 
using namespace std;
 
class Laptop {
  // isi dari class Laptop...
  // isi dari class Laptop...
};
 
int main()
{
  Laptop laptopAndi;
  Laptop laptopAnto;
 
  return 0;
}
```

Dalam contoh ini, **laptopAndi** dan **laptopAnto** merupakan objek dari **class Laptop**. Kedua objek akan memiliki seluruh data member dan member function yang telah dirancang dalam **class Laptop**.

---

Dalam tutorial kali ini kita telah membahas tentang pengertian dan cara pembuatan **class**, **data member**, **member function**, dan juga **object**. Pada tutorial OOP C++ berikutnya akan di bahas lebih dalam tentang [Cara Membuat Object dalam Bahasa Pemrograman C++](https://www.duniailkom.com/tutorial-belajar-oop-c-plus-plus-cara-membuat-object-pada-bahasa-c-plus-plus/ "Tutorial Belajar OOP C++ Part 3: Cara Membuat Object Pada Bahasa C++").