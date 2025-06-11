---
obsidianUIMode: preview
sumber: duniailkom
level: pemula
bahasa: C++
tanggal_study: 2024-10-01T20:41:00
total_study: 4
tags:
  - Cpp
id: DIC2
---
# Tutorial Belajar C++ Part 6: Aturan Dasar Penulisan Kode Program C++

19 Oct 20 

Dalam lanjutan tutorial belajar bahasa C++ di Duniailkom kali ini kita akan bahas aturan dasar penulisan kode program C++. Aturan ini mencakup **case sensitivity**, **whitespace**, **baris komentar**, **statement**, **keyword**, dan **identifier**.

---

### Perbedaan Huruf Besar / Kecil dalam Bahasa C++

Pengertian sederhana dari **case sensitivity** adalah perbedaan antara huruf besar dan huruf kecil. Istilahnya, bahasa C++ termasuk bahasa yang **case sensitif**. Dalam bahasa C++, huruf besar dan kecil dianggap berbeda. Perintah **cout** tidak bisa ditulis menjadi **Cout**.

Berikut contohnya:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  Cout << "Belajar C++ di Duniailkom";
  return 0;
}
```

Hasil kode program:

```
error: 'Cout' was not declared in this scope
```

Error di atas terjadi karena di baris 7 saya menulis **Cout << "Belajar C++ di Duniailkom"**, dimana seharusnya perintah **cout** ditulis dalam huruf kecil semua, yakni **cout << "Belajar C++ di Duniailkom"**.

Untuk penulisan variabel juga akan berbeda antara huruf besar dan kecil. Variabel **jumlah**, **JUMLAH**, dan **Jumlah** adalah 3 variabel yang berlainan. Aturan ini berbeda jika dibandingkan bahasa pemrograman PASCAL yang bersifat _case insensitif_ (tidak membedakan huruf besar dan kecil).

---

### Cara Penulisan Komentar dalam Bahasa C++

**Komentar** atau _comment_ adalah kode program yang ditambah untuk memberi keterangan / penjelasan mengenai cara kerja program. Komentar tidak akan diproses oleh compiler C++.

Dalam bahasa C++, terdapat 2 cara membuat baris komentar:

1. Komentar singkat dengan karakter forward slash dua kali: **//**.
2. Komentar panjang dengan tanda pembuka **\/*** dan tanda penutup ***\/.**

Untuk komentar singkat dengan tanda //, hanya berlaku untuk satu baris saja. Seluruh teks yang ada setelah tanda tersebut akan diabaikan oleh compiler C++. Berikut contoh penggunaannya:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  // Tampilkan pesan teks
  cout << "Belajar C++ di Duniailkom"; // Hasil: Belajar C++ di Duniailkom
  return 0;
}
```

Teks yang ada di baris 7 dan sebagian baris 8 tidak akan di proses oleh compiler C++.

Baris komentar juga sering dipakai untuk menonaktifkan beberapa perintah:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "Belajar C++ di Duniailkom";
  // cout << "Kode ini di non aktifkan";
  return 0;
}
```

Dengan teknik seperti ini kita bisa mencoba berbagai perintah lain tanpa harus menghapus kode yang sudah ada.

Baris komentar juga sering dipakai untuk membuat semacam copyright kode program yang ditulis pada bagian awal:

```Cpp
// Pembuat : Duniailkom.com
// Tujuan  : Menampilkan pesan menggunakan C++
// Bahasa  : C++
// Tanggal Pembuatan: 19 Oktober 2020
 
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "Belajar C++ di Duniailkom";
  return 0;
}
```

Cara pembuatan baris komentar kedua adalah dengan tanda **\/*** dan ***\/**. Seluruh karakter yang ada diantara kedua tanda ini akan dianggap sebagai komentar dan diabaikan pada saat proses _compiler_.

Berikut contoh penggunaannya:

```Cpp
/* Pembuat : Duniailkom.com
   Tujuan  : Menampilkan pesan menggunakan C++
   Bahasa  : C++
   Tanggal Pembuatan: 19 Oktober 2020  */
 
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "Belajar C++ di Duniailkom";
  /* cout << "Kode ini di non aktifkan";  */
  return 0;
}
```

Baris komentar yang ditulis dengan tanda **\/*** dan ***\/** bisa mencakup banyak baris, dan harus ditulis secara berpasangan.

---

### Pengertian Statement dalam Bahasa Pemrograman C++

**Statement** dalam bahasa C++ adalah sebutan untuk sebuah baris perintah. Setiap _statement_ dalam C++ harus diakhiri dengan tanda titik koma ( ; ).

Berikut beberapa contoh statement dalam bahasa pemrograman C++:

```Cpp
x = 6;              
y = "Duniailkom";    
z = 5+3;            
2+3;                
cout << "Belajar C++ di Duniailkom";
root2 = sqrt(49);
```

Sebuah statement tidak harus mencakup satu baris. Perintah kondisi seperti **if else** dan perulangan (**looping**) bisa terdiri dari beberapa baris, dan ini dianggap sebagai satu statement:

```Cpp
if(x == "Duniailkom") {
 cout << "Belajar C++ di Duniailkom";
}
```

Statement yang terdiri dari beberapa baris seperti ini, biasanya diawali dengan tanda kurung kurawal " **{** " dan diakhiri dengan tanda " **}** ". Bagian ini juga sering disebut sebagai blok kode program.

---

### Pengertian Keyword dalam Bahasa Pemrograman C++

**Keyword** adalah kata kunci yang menjadi dasar perintah bahasa C++. Keyword ini tidak bisa digunakan sebagai **identifier** (_variabel_, _konstanta_ maupun nama dari sebuah _fungsi_).

Sebagai contoh, perhatikan statement berikut:

```Cpp
int jumlah;
return 0;
```

Disini, kata **int** dan **return** merupakan _keyword_ dan memiliki makna tertentu di dalam bahasa C++.

Terdapat beberapa kata kunci (_keyword_) dalam bahasa pemrograman C++, yakni:

|                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |                                                                                                                                                                                                                                                                                                                                                                                                                         |                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| alignas (sejak C++11)  <br>alignof (sejak C++11)  <br>and  <br>and_eq  <br>asm  <br>atomic_cancel  <br>atomic_commit   <br>atomic_noexcept  <br>auto  <br>bitand  <br>bitor  <br>bool  <br>break  <br>case  <br>catch  <br>char  <br>char8_t (sejak C++20)  <br>char16_t (sejak C++11)  <br>char32_t (sejak C++11)  <br>class  <br>compl  <br>concept (sejak C++20)  <br>const  <br>consteval (sejak C++20)  <br>constexpr (sejak C++11)  <br>constinit (sejak C++20)  <br>const_cast  <br>continue  <br>co_await (sejak C++20)  <br>co_return (sejak C++20)  <br>co_yield (sejak C++20)  <br>decltype (sejak C++11) | default  <br>delete  <br>do  <br>double  <br>dynamic_cast  <br>else  <br>enum  <br>explicit  <br>export  <br>extern  <br>false  <br>float  <br>for  <br>friend  <br>goto  <br>if  <br>inline  <br>int  <br>long  <br>mutable  <br>namespace  <br>new  <br>noexcept (sejak C++11)  <br>not  <br>not_eq  <br>nullptr (sejak C++11)  <br>operator  <br>or  <br>or_eq  <br>private  <br>protected  <br>public  <br>reflexpr | register  <br>reinterpret_cast  <br>requires (sejak C++20)  <br>return  <br>short  <br>signed  <br>sizeof  <br>static  <br>static_assert (sejak C++11)  <br>static_cast  <br>struct  <br>switch  <br>synchronized  <br>template  <br>this  <br>thread_local (sejak C++11)  <br>throw  <br>true  <br>try  <br>typedef  <br>typeid  <br>typename  <br>union  <br>unsigned  <br>using(1)  <br>virtual  <br>void  <br>volatile  <br>wchar_t  <br>while  <br>xor  <br>xor_eq |

Seluruh daftar peritnah ini tidak bisa digunakan sebagai nama variabel / konstanta dalam bahasa C++ (sumber: [https://en.cppreference.com/w/cpp/keyword](https://en.cppreference.com/w/cpp/keyword)).

---

### Pengertian Identifier dalam Bahasa Pemrograman C++

**Identifier** adalah nama untuk menandakan "sesuatu" sepanjang kode program. Contoh dari **identifier** adalah _variabel_, _konstanta_ dan _fungsi_.

Perhatikan statement berikut:

```Cpp
int total;
double harga_jual;
```

Disini, **total** dan **harga_jual** adalah _variabel_ dan termasuk ke dalam **identifiers**.

Secara umum, kita bebas ingin menulis nama **identifier**, namun terdapat beberapa aturan:

- **Identifier** harus selain dari _keyword_ (yang terdapat di tabel sebelum ini). Sebagai contoh, kita tidak bisa memakai kata **int** sebagai nama variabel, karena **int** merupakan _keyword_ untuk menandakan tipe data _integer_.
- **Identifier** bisa terdiri dari huruf, angka dan karakter _underscore_ / garis bawah ( _ ).
- Karakter pertama dari **identifier** hanya bisa berupa huruf dan underscore, tidak bisa berupa angka. Meskipun boleh, tapi tidak disarankan memakai karakter underscore sebagai awal dari identifier.
- Beberapa compiler ada yang membatasi panjang **identifier** maksimal 31 karakter.

---

Dalam tutorial bahasa pemrograman bahasa C++ kali ini kita telah membahas beberapa aturan dasar dari bahasa C++. Ini semua menjadi pedoman dalam menulis kode program nantinya.

Tutorial berikutnya akan masuk ke [Pengertian Variabel dalam Bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-pengertian-variabel-dalam-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 7: Pengertian Variabel dalam Bahasa C++").