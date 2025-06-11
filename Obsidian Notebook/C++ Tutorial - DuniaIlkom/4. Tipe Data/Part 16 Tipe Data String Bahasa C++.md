---
obsidianUIMode: preview
sumber: duniailkom
level: pemula
bahasa: C++
tanggal_study: 2024-10-01T19:15:00
total_study: 3
tags:
  - Cpp
id: DID6
---
# Tutorial Belajar C++ Part 16: Tipe Data String Bahasa C++

26 Oct 20 

Dalam lanjutan tutorial belajar C++ di Duniailkom kali ini kita akan membahas **tipe data String**, mulai dari pengertian, contoh kode program, hingga melihat beberapa method bawaan dari object string.

---

### Pengertian Tipe Data String dalam Bahasa C++

Pengertian umum di bidang programming, **string** adalah tipe data yang menampung kumpulan karakter, seperti "aku", "kamu" atau "Duniailkom". Sebuah kalimat juga terhitung sebagai tipe data _string_ seperti "Sedang belajar bahasa C++ di Duniailkom".

Pada bahasa C++, tipe data string dibuat menggunakan keyword **string**. Selain itu teks string ini harus berada di dalam tanda kutip dua ( "" ).

---

### Contoh Kode Program Tipe Data String C++

Berikut contoh pendeklarasian variabel dengan tipe data **string** di C++:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  string var1 = "Belajar C++ ";
  string var2 = "di Duniailkom";
 
  cout << var1 << var2 << endl;
 
  return 0;
}
```

Hasil kode program:

```
Belajar C++ di Duniailkom
```

Kita juga bisa menyambung beberapa variabel bertipe string menggunakan tanda tambah ( + ). Ini disebut juga sebagai **operasi string concatenation**:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  string var1 = "Belajar C++ ";
  string var2 = "di Duniailkom";
  string var3 = var1 + var2;
 
  cout << var3 << endl;
 
  return 0;
}
```

Hasil kode program:

```
Belajar C++ di Duniailkom
```

Dalam kode program ini saya membuat tiga buah variabel bertipe string, yakni **var1**, **var2 dan var3**. Untuk isi **var3**, di dapat dari hasil penyambungan string yang tersimpan di dalam variabel **var1** dan **var2**.

Proses pembuatan string juga bisa diisi dengan karakter khusus seperti **\"**, **\'** dan **\n** untuk menulis tanda kutip dua, tanda kutip satu dan karakter Enter (_new line_) ke dalam string. Berikut contoh penggunaannya:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  string var1 = "Belajar \nC++ \ndi \"Duniailkom\"";
 
  cout << var1 << endl;
 
  return 0;
}
```

Hasil kode program:

```
Belajar 
C++
di "Duniailkom"
```

Meskipun isi untuk variabel **var1** di tulis dalam 1 baris, tapi hasilnya terpecah menjadi 3 baris teks. Ini karena karakter **\n** akan diterjemahkan menjadi karakter _Enter_, sehingga teks berikutnya pindah ke baris baru.

---

### String Sebagai Array

Dalam bahasa C++, tipe data string bisa dilihat sebagai array dari tipe data char. Pembahasan tipe data array memang baru akan kita bahas pada tutorial setelah ini, tapi dalam kode program berikut saya ingin memperlihatkan bahwa kita bisa mengakses setiap karakter string menggunakan key array:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  string var1 = "Belajar C++ di Duniailkom";
 
  cout << var1[0] << endl;
  cout << var1[1] << endl;
  cout << var1[2] << endl;
  cout << var1[3] << endl;
  cout << var1[4] << endl;
  cout << var1[5] << endl;
  cout << var1[6] << endl;
 
  return 0;
}
```

Hasil kode program:

```
B
e
l
a
j
a
r
```

Setelah menginput string "Belajar C++ di Duniailkom" di baris 7, antara baris 9 – 15 saya mengakses setiap karakter string **var1** dengan menulis nomor key, dimana **var1[0]** merujuk ke karakter pertama, **var1[1]** ke karakter kedua dari variabel **var1**, dst.

---

### Mencari Panjang Sebuah String C++

Salah satu hal yang sering kita lakukan untuk tipe data string adalah mencari tau total jumlah karakter yang ada di dalam sebuah string. Atau disebut juga dengan mencari panjang string.

Dalam bahasa C++, panjang sebuah string bisa didapat dengan mengakses method **length()** atau **size()** seperti contoh berikut:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  string var1 = "Belajar C++ di Duniailkom";
  string var2 = "Semangat!!";
  string var3 = "Belajar demi masa depan yang lebih baik";
 
  cout << "Panjang string var1 adalah " << var1.length() <<endl;
  cout << "Panjang string var2 adalah " << var2.length() <<endl;
  cout << "Panjang string var3 adalah " << var3.size() <<endl;
 
  return 0;
}
```

Hasil kode program:

```
Panjang string var1 adalah 25
Panjang string var2 adalah 10
Panjang string var3 adalah 39
```

Pada kode program ini saya membuat dan mengisi variabel **var1**, **var2** dan **var3** dengan berbagai string. Ketika ditampilkan pada baris 11 – 13, terdapat perintah **var1.length()**, **var2.length()** dan **var3.size()** yang akan menampilkan panjang setiap string.

Tidak ada perbedaan antara method **length()** dan **size()**, hanya alternatif nama saja.

**Method** adalah istilah dalam pemrograman object yang pada dasarnya mirip seperti **function**. Bedanya, method biasa diakses setelah menulis nama variabel dan dipisah dengan tanda titik, seperti **var1.length()**. Sedangkan function berdiri sendiri dan variabel diinput di dalam tanda kurung seperti **length(var1)**.

Lebih lanjut tentang method dan function akan kita bahas dalam tutorial terpisah.

---

Dalam lanjutan tutorial bahasa pemrograman C++ di Duniailkom kali ini kita telah membahas tipe data string. Berikutnya akan disambung dengan [Tipe Data Array C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-tipe-data-array-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 17: Tipe Data Array Bahasa C++").