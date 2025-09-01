---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-09-28T12:06:00
total_study: 1
tags:
  - Cpp
id: DIG5
teori_REVERSE:
---
# Tutorial Belajar C++ Part 41: Pengertian Function Overloading C++

03 Nov 20 

Kali ini kita akan membahas materi yang sedikit advanced di C++, yakni tentang Function Overloading beserta contoh kode programnya.

---

### Pengertian Function Overloading C++

Di dalam C++, **Function Overloading** adalah membuat beberapa function dengan nama yang sama, tapi dibedakan dari jumlah dan tipe data parameter.

Umumnya, kita tidak bisa membuat function dengan nama yang sama. Mirip seperti penamaan variabel, compiler C++ akan error jika menemukan terdapat 2 atau lebih function dengan nama yang sama.

Akan tetapi jika jumlah argument atau tipe data argument berbeda, maka akan dianggap sebagai fungsi yang berbeda pula.

---

### Contoh Kode Program Function Overloading C++

Agar lebih mudah dipahami, berikut contoh pembuatan function overloading di bahasa pemrograman C++:

```Cpp
#include <iostream>
 
using namespace std;
 
int tambah(int var1, int var2) {
  return var1 + var2;
}
 
int tambah(int var1, int var2, int var3) {
  return var1 + var2 + var3;
}
 
string tambah(string var1, string var2) {
  return var1 + " tambah " + var2;
}
 
int main()
{
  cout << tambah(1, 2) << endl;
  cout << tambah(5, 4, 3) << endl;
  cout << tambah("satu","dua") << endl;
 
  return 0;
}
```

Hasil kode program:

[![Contoh Kode Program Function Overloading Bahasa C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Function-Overloading-Bahasa-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Function-Overloading-Bahasa-C.png)

Dalam kode program ini saya membuat 3 buah function dengan nama **tambah()**. Ketiga function dibedakan berdasarkan jumlah parameter seperti function **tambah()** pertama dan kedua, serta dengan jenis tipe data parameter seperti contoh function **tambah()** ketiga.

Pada saat di panggil, kita harus menulis function **tambah()** dengan jumlah dan tipe data argument yang sesuai.

Di baris 19 terdapat pemanggilan fungsi **tambah(1, 2)**. Perhatikan bahwa argumen pemanggilan fungsi ini ada 2 dan keduanya bertipe integer. Maka akan cocok dengan definisi fungsi **tambah()** di baris 5 – 7.

Di baris 20 terdapat pemanggilan fungsi **tambah(5, 4, 3)**. Kali ini argumen pemanggilan fungsi tambah() ada 3 dan ketiganya bertipe integer. Maka ini akan cocok dengan definisi fungsi **tambah()** di baris 9 – 11.

Terakhir di baris 21 terdapat pemanggilan fungsi **tambah("satu","dua")**. Sekarang kedua argument bertipe string yang akan cocok dengan definisi fungsi **tambah()** di baris 9 – 11.

Inilah maksud dari function overloading, dimana kita membuat beberapa fungsi dengan nama yang sama.

---

### Tidak Berlaku untuk Tipe Data Kembalian

Sebagai tambahan, tipe data nilai kembalian fungsi tidak termasuk ke dalam pembeda function overloading. Kode program berikut akan menghasilkan error:

```Cpp
#include <iostream>
 
using namespace std;
 
int tambah(int var1, int var2) {
  return var1 + var2;
}
 
string tambah(int var1, int var2) {   // error
  return "test...";
}
 
int main()
{
  cout << tambah(1, 2) << endl;
  cout << tambah(5, 4) << endl;
 
  return 0;
}
```

Hasil kode program:

```
error: ambiguating new declaration of 'std::__cxx11::string tambah(int, int)'

```

Kali ini saya membuat 2 buah function **tambah()** yang dibedakan hanya berdasarkan tipe data kembalian, yakni **int** di baris 5 dan **string** di baris 9.

Hasilnya, akan tetap error karena tipe data kembalian tidak menjadi pembeda pada **function overloading**.

---

Dalam tutorial ini kita telah melihat pengertian function overloading dalam pemrograman C++. Tidak semua bahasa pemrograman punya fitur function overloading, namun penggunaannya memang tidak terlalu banyak karena tetap lebih disarankan untuk membedakan setiap function berdasarkan nama.

Tutorial function overloading ini untuk sementara menutup materi Belajar C++ di Duniailkom, atau lebih tepatnya **tutorial belajar C++ procedural**. Karena kita akan lanjut ke materi tentang pemrograman object atau object oriented programming (OOP) di C++.

Materi ini akan dimulai dengan membahas [Pengertian Pemrograman Berorientasi Objek C++](https://www.duniailkom.com/tutorial-belajar-oop-c-plus-plus-pengertian-pemrograman-berorientasi-objek/ "Tutorial Belajar OOP C++ Part 1: Pengertian Pemrograman Berorientasi Objek").