---
obsidianUIMode: preview
sumber: duniailkom
level: pemula
bahasa: C++
tanggal_study: 2024-10-01T22:06:00
total_study: 4
tags:
  - Cpp
id: DID1
---
# Tutorial Belajar C++ Part 11: Jenis-jenis Tipe Data dalam Bahasa C++

21 Oct 20 

Dalam lanjutan tutorial bahasa pemrograman C++ di Duniailkom kali ini kita akan membahas pengertian tipe data, jenis-jenis tipe data, serta contoh kode program berbagai tipe data di dalam bahasa C++.

---

### Pengertian Tipe Data

Sebelum sampai ke jenis-jenis tipe data di dalam bahasa C++, ada baiknya membahas sedikit pengertian dari tipe data itu sendiri. _Apa itu tipe data?_

Mengutip dari wikipedia ([Data type](https://en.wikipedia.org/wiki/Data_type)):

_"A data type or simply type is a classification of data which tells the compiler or interpreter how the programmer intends to use the data"._

Terjemahannya:

_"Tipe data atau kadang disingkat dengan 'tipe' saja adalah sebuah pengelompokan data untuk memberitahu compiler atau interpreter bagaimana programmer ingin mengolah data tersebut"_

Secara sederhana, **tipe data adalah cara kita memberitahu komputer untuk mengelompokkan data berdasarkan apa yang dipahami oleh komputer.**

Sebagai contoh, misalkan saya memiliki data berupa angka. Agar bisa dipahami oleh compiler C++, data ini harus disimpan ke dalam variabel yang sudah di siapkan agar bisa menyimpan angka seperti tipe data **integer**, **float** dan **double**. Atau jika data yang harus disimpan dalam bentuk teks atau kata, bisa disimpan ke dalam tipe data **string**.

---

### Jenis-jenis Tipe Data dalam Bahasa C++

Secara garis besar, terdapat 2 kelompok tipe data dalam bahasa C++, yakni **tipe data sederhana** (**Primitive data types**), dan tipe data kompleks (**Non-primitive data types**).

**Primitive data type**, terdiri dari tipe data berikut:

1. [Tipe data **Integer**](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-tipe-data-integer-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 13: Tipe Data Integer Bahasa C++"): Tipe data untuk angka bulat seperti 5, 7, atau 48.
2. [Tipe data **Float/Double**](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-tipe-data-float-dan-double-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 14: Tipe Data Float dan Double Bahasa C++"): Tipe data untuk angka pecahan seperti 3.14, 5.55, atau 0.00024.
3. [Tipe data **Boolean**](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-tipe-data-boolean-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 15: Tipe Data Boolean Bahasa C++"): Tipe data yang berisi nilai true atau false.
4. [Tipe data **Char**](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-tipe-data-char-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 12: Tipe Data Char Bahasa C++"): Tipe data untuk 1 karakter, seperti 'a', 'Z' atau '%'.
5. Tipe data **Void**: Tipe data khusus yang menyatakan tidak ada data.

**Non-primitive data type**, di antaranya:

1. [Tipe data **String**](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-tipe-data-string-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 16: Tipe Data String Bahasa C++"): Tipe data untuk kumpulan karakter, seperti "Andi", "Duniailkom", atau "Belajar C++".
2. [Tipe data **Array**](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-tipe-data-array-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 17: Tipe Data Array Bahasa C++"): Tipe data untuk kumpulan tipe data lain yang sejenis.
3. [Tipe data **Structure** (struct)](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-tipe-data-struct-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 18: Tipe Data Struct Bahasa C++"): Tipe data yang terdiri dari kumpulan tipe data dasar. Tipe data tersebut bisa lebih dari 1 jenis.
4. [Tipe data **Enum**](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-tipe-data-enum-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 19: Tipe Data Enum Bahasa C++"): Tipe data bentukan yang dibuat sendiri oleh kita (programmer).
5. [Tipe data **Pointer**](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-tipe-data-pointer-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 20: Tipe Data Pointer Bahasa C++"): Tipe data untuk mengakses alamat memory secara langsung.

Sebagian besar tipe data yang ada di dalam bahasa C++ diturunkan dari bahasa C, oleh karena itu kita akan melihat banyak persamaan dari tipe data ini.

Beberapa perbedaan seperti tipe data **boolean** yang sebelumnya tidak ada di dalam bahasa C, serta tipe data **string** yang sekarang sudah menjadi tipe data utama. Di dalam bahasa C, string  pada dasarnya adalah array dari tipe data char.

---

### Contoh Kode Program Tipe Data Bahasa C++

Sebagai gambaran dasar, berikut contoh penggunaan dari berbagai tipe data dalam bahasa C++:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int     var1 = 56;
  double  var2 = 0.543;
  bool    var3 = true;
  char    var4 = 'A';
  string  var5 = "Belajar C++ di Duniailkom";
  int  var6[5] = {10, 20, 30, 40, 50};
 
  cout << var1 << endl;
  cout << var2 << endl;
  cout << var3 << endl;
  cout << var4 << endl;
  cout << var5 << endl;
  cout << var6[2] << endl;
 
  return 0;
}
```

[![Contoh Kode Program Tipe Data bahasa C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Tipe-Data-bahasa-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Tipe-Data-bahasa-C.png)

Bahasa pemrograman C++ termasuk kelompok **strongly typed programming language**, yang artinya untuk setiap variabel harus ditulis akan berisi tipe data apa. Apakah itu angka bulat (_integer_), angka pecahan (_float_), huruf (_char_), atau yang lain.

Di baris 7 – 12 saya mendeklarasikan 6 variabel dari **var1** sampai **var6**. Semua variabel ini berisi tipe data yang berbeda-beda, yakni **int**, **double**, **boolean**, **char**, **string**, dan **array**.

Penjelasan lebih lengkap dari setiap tipe data akan kita bahas dalam tutorial terpisah, yang akan di mulai dengan [Tipe Data Char dalam Bahasa Pemrograman C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-tipe-data-char-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 12: Tipe Data Char Bahasa C++").