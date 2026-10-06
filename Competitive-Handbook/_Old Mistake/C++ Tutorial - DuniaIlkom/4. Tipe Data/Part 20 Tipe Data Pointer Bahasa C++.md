---
obsidianUIMode: preview
sumber: duniailkom
level: sulit
bahasa: C++
tanggal_study: 2024-10-01T10:43:00
total_study: 2
tags:
  - Cpp
id: DID10
---
# Tutorial Belajar C++ Part 20: Tipe Data Pointer Bahasa C++

27 Oct 20 

**Tipe data pointer** bisa jadi merupakan tipe data paling rumit dalam bahasa pemrograman C++. Namun tipe data ini sekaligus yang paling powerfull karena kita bisa langsung mengakses alamat memory komputer.

Dalam lanjutan tutorial bahasa C++ di Duniailkom kali ini akan dibahas tentang **pengertian tipe data pointer**, **references**, **dereference** serta contoh kode program cara penggunaannya.

---

### Pengertian Reference

Sebelum masuk ke pointer, saya akan bahas tentang pengertian **reference** terlebih dahulu.

Sebagaimana yang kita ketahui, **variabel** adalah 'nama alias' dari sebuah alamat di memory. Pada saat kita membuat variabel **var1**, compiler C++ akan 'membooking' satu alamat di memory komputer untuk menyimpan data yang akan diinput ke dalam variabel tersebut.

Lalu ketika dibuat **var2**, maka akan di booking satu alamat memory lain, dst. Disini, **var1** dan **var2** berada di alamat yang berbeda dan tidak terhubung satu sama lain:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  string var1 = "Belajar C++ di Duniailkom";
  string var2 = "Belajar Java di Duniailkom";
 
  cout << var1 << endl;
  cout << var2 << endl;
 
  return 0;
}
```

Hasil kode program:

```
Belajar C++ di Duniailkom
Belajar Java di Duniailkom
```

Dalam kode ini saya membuat 2 buah variabel: **var1** dan **var2**. Kedua variabel di isi dengan string yang berbeda, dan ditampilkan menggunakan perintah **cout**.

Secara internal, **var1** dan **var2** berada di lokasi memory yang berbeda. Dengan menggunakan **reference**, kita bisa menginstruksikan compiler C++ agar sebuah variabel terhubung ke alamat memory milik variabel lain. Berikut cara pembuatan **reference** dalam bahasa C++:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  string var1 = "Belajar C++ di Duniailkom";
  string &var2 = var1;
 
  cout << var1 << endl;
  cout << var2 << endl;
 
  return 0;
}
```

Hasil kode program:

```
Belajar C++ di Duniailkom
Belajar C++ di Duniailkom
```

Perhatikan tambahan tanda '**&**' di awal penulisan **var2** (baris 8). Inilah cara membuat **reference** di dalam C++.

Perintah **string &var2 = var1** artinya, alamat memory yang dirujuk oleh **var2** akan sama dengan milik **var1**. Atau dengan kata lain, **var1** dan **var2** merujuk ke alamat memory yang sama. Inilah alasan kenapa ketika ditampilkan, **var2** juga berisi string "Belajar C++ di Duniailkom", padahal kita tidak menginput teks ini secara langsung ke dalam **var2**.

Karena merujuk ke alamat memory yang sama, isi teks **var1** bisa diubah dari **var2**:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  string var1 = "Belajar C++ di Duniailkom";
  string &var2 = var1;
 
  cout << var1 << endl;
  cout << var2 << endl;
 
  var2 = "Belajar Java di Duniailkom";
 
  cout << var1 << endl;
  cout << var2 << endl;
 
  return 0;
}
```

Hasil kode program:

```
Belajar C++ di Duniailkom
Belajar C++ di Duniailkom
Belajar Java di Duniailkom
Belajar Java di Duniailkom
```

Setelah mendefinisikan **var2** sebagai reference ke **var1**, di baris 13 saya mencoba mengganti isi teks milik **var2**. Hasilnya, perintah tersebut ikut mengganti isi teks yang tersimpan di **var1**. Karena pada dasarnya baik **var1** dan **var2** merujuk ke 'laci' yang sama di memory komputer.

---

### Menampilkan Alamat Memory

Agar lebih jelas, mari tampilkan alamat memory yang dirujuk oleh sebuah variabel. Caranya, tambah tanda '_ampersand_' atau tanda **&** ketika menampilkan variabel dengan perintah **cout**:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int var1 = 100;
  int var2 = 200;
  int var3 = 300;
 
  cout << var1 << endl;
  cout << var2 << endl;
  cout << var3 << endl;
 
  cout << endl;
 
  cout << &var1 << endl;
  cout << &var2 << endl;
  cout << &var3 << endl;
 
  return 0;
}
```

Hasil kode program:

```
100
200
300
 
0x61fe1c
0x61fe18
0x61fe14
```

Dalam kode program ini saya membuat 3 buah variabel bertipe integer: **var1**, **var2**, dan **var3**. Setiap variabel diisi dengan angka yang berbeda lalu di tampilkan dengan perintah **cout**.

Perhatikan perintah di baris 17 – 19. Inilah cara menampilkan alamat memory dari setiap variabel, yakni dengan cara men-cout **&var1**, **&var2** dan **&var3**.

Hasil **0x61fe1c**, **0x61fe18** dan **0x61fe14** adalah alamat memory yang dipakai untuk menyimpan data milik **var1**, **var2** dan **var3**. Alamat memory ini berbeda-beda, karena ada 3 variabel.

Sekarang kita lihat jika menggunakan **reference**:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int var1 = 100;
  int &var2 = var1;
  int &var3 = var1;
 
  cout << var1 << endl;
  cout << var2 << endl;
  cout << var3 << endl;
 
  cout << endl;
 
  cout << &var1 << endl;
  cout << &var2 << endl;
  cout << &var3 << endl;
 
  return 0;
}
```

Hasil kode program:

```
100
100
100
 
0x61fe0c
0x61fe0c
0x61fe0c
```

Sekarang ketiga variabel: **var1**, **var2** dan **var3** merujuk ke alamat memory yang sama. Sebab di baris 8 – 9 saya mengisi **&var2** dan **&var3** dengan alamat memory milik **var1**.

---

### Pengertian Pointer

Sekarang kita masuk ke materi utama, _pointer_. **Pointer** adalah sebuah variabel yang menyimpan alamat memory. Dalam bahasa pemrograman C++, pointer dibuat menggunakan tanda bintang **\***.

Berikut contoh kode program pembuatan pointer C++:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  string var1 = "Belajar C++ di Duniailkom";
  string* var2 = &var1;
 
  cout << var1 << endl;
  cout << var2 << endl;
 
  return 0;

```

Hasil kode program:

```
Belajar C++ di Duniailkom
0x61fde0
```

Cara pembuatan tipe data pointer ada di baris 8 dengan perintah **string* var2 = &var1**. Ini akan menginput alamat memory milik **var1** ke dalam **var2**. Ketika di cout, yang tampil adalah angka alamat memory tadi.

Pembuatan tipe data pointer ini bisa dilakukan dengan 3 cara berikut:

```
string* var1;
string *var1;
string * var1;
```

Dari ketiga cara ini, yang banyak dipakai adalah perintah pertama, yakni **string* var1**.

Tipe data pointer harus di set dengan tipe data yang sama dengan tipe data asal. Maksudnya jika kita ingin menyimpan alamat memory dari sebuah variabel bertipe **float**, maka tipe data pointernya juga harus **float**:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  float var1 = 9.99;
  string* var2 = &var1;  // error
 
  cout << var1 << endl;
  cout << var2 << endl;
 
  return 0;
}
```

Kode di atas akan menghasilkan error '_cannot convert 'float*' to 'std::__cxx11::string*_' karena seharusnya pointer **var2** juga di deklarasikan sebagai **float**.

---

### Pengertian Dereference

**Deference** adalah cara menampilkan nilai dari alamat memory yang tersimpan di dalam sebuah pointer.

Sebagaimana yang kita lihat dalam praktek sebelumnya, pointer berisi alamat memory. Untuk menampilkan nilai yang tersimpan di dalamnya, bisa menggunakan operator **\*** pada saat di **cout**. Berikut contoh kode program yang dimaksud:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  string var1 = "Belajar C++ di Duniailkom";
  string* var2 = &var1;
 
  cout << var1 << endl;
  cout << var2 << endl;
  cout << *var2 << endl;
 
  return 0;
}
```

Hasil kode program:

[![Contoh Kode Program Tipe Data Pointer Bahasa C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Tipe-Data-Pointer-Bahasa-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Tipe-Data-Pointer-Bahasa-C.png)

Perintah **deference** ada di baris 12, dimana **cout << *var2** akan menampilkan nilai yang tersimpan di dalam alamat pointer **var2**.

---

Dalam tutorial belajar C++ kali ini kita telah membahas cara penggunaan tipe data pointer. Seperti yang terlihat, **tipe data pointer** ini berhubungan dengan cara kerja internal sebuah variabel, termasuk mengakses alamat memory. Ciri khas dari kode program yang menggunakan pointer ada di penggunaan tanda `&` dan `*`.

Pointer juga menjadi salah satu materi untuk belajar **struktur data**. Namun agar tidak terlalu rumit, saya batasi dengan pembahasan dasar pointer saja.

Lanjut, tutorial C++ di Duniailkom akan masuk ke pembahasan tentang [Jenis – Jenis Operator dalam Bahasa Pemrograman C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-jenis-jenis-operator-dalam-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 21: Jenis-jenis Operator dalam Bahasa C++").