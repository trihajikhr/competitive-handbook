---
obsidianUIMode: preview
sumber: duniailkom
level: pemula
bahasa: C++
tanggal_study: 2024-10-01T20:23:00
total_study: 4
tags:
  - Cpp
id: DIC1
---
# Tutorial Belajar C++ Part 5: Struktur Dasar Kode Program C++

19 Oct 20 

Pada tutorial sebelumnya kita sudah berhasil [menjalankan dan men-compile kode program bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-cara-menjalankan-kode-c-plus-plus-atau-proses-compile/ "Tutorial Belajar C++ Part 4: Cara Menjalankan Kode C++ (Proses Compile)"). Dalam tutorial kali ini akan dibahas mengenai struktur dasar kode program C++, diantaranya tentang file header **iostream**, function **main**, perintah **std::cout**, serta **using namespace std**.

---

### Struktur Dasar Bahasa Pemrograman C++

Kode program yang kita jalankan sebelumnya sangat sederhana, tapi itu sudah mewakili struktur dasar dari sebuah bahasa pemrograman C++. Berikut saya tampilkan kembali kode program yang dimaksud:

```Cpp
#include <iostream>
 
int main()
{
  std::cout << "Hello World!";
  return 0;
}
```

[![](https://www.duniailkom.com/wp-content/uploads/2020/10/Membuat-kode-program-C-Hello-World.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Membuat-kode-program-C-Hello-World.png)

---

### \#include \<iostream>

Di baris paling awal terdapat kode `#include <iostream>`. Perintah **\#include** dipakai untuk memasukkan sebuah file khusus yang memungkinkan kita mengakses berbagai fitur tambahan dalam bahasa C++.

Dalam contoh diatas, file **iostream** berisi kode program agar nantinya kita bisa mengakses perintah input/output seperti **cout** dan **cin**. **iostream** sendiri merupakan singkatan dari **input output** **stream**.

Dengan kata lain, agar di dalam kode program nanti kita bisa menggunakan perintah **cout**, di bagian paling atas kode program C++ harus terdapat baris **\#include \<iostream>**. File include ini juga sering disebut sebagai **header file**.

Bahasa C++ menerapkan konsep _modular_, dimana fitur-fitur yang ada di pecah ke berbagai file. Jika ingin menggunakan perintah tertentu, panggil header file yang sesuai. Contoh file header lain seperti **\#include \<fstream>** atau **\#include \<cmath>** yang akan dibutuhkan saat ingin membaca file atau menjalankan function matematika.

Hasilnya, ukuran file program yang ditulis dalam bahasa C++ menjadi efisien. Kita hanya perlu menggunakan header file saat dibutuhkan saja. Namun kebalikannya, setiap ingin menggunakan perintah tertentu, harus men-include-kan file header yang dibutuhkan.

---

### int main() { }

Struktur **main()** pada dasarnya merupakan sebuah **fungsi** (_function_). Isi dari function ini diawali dan diakhiri dengan tanda kurung kurawal " { " dan " } ". Di dalam tanda kurung inilah "isi" dari kode program penyusun function **main()** ditulis.

Function **main()** merupakan kode program utama dalam mayoritas aplikasi bahasa C++. Di sinilah kita akan banyak menulis kode program.

Sedikit berbeda dengan bahasa C, function **main()** di dalam file C++ boleh saja tidak ditulis, terutama jika ingin membuat sebuah file header atau file bantu (file yang berisi berbagai function lain). Namun dalam kebanyakan situasi, function **main()** selalu ada dalam kode yang akan kita buat.

Perintah "**int**" sebelum **main()** menandakan **nilai kembalian** atau hasil akhir dari function **main()**. Kode **int** merupakan singkatan dari **integer**, yakni tipe data angka bulat.

Dengan demikian, kode program **main()** yang saya tulis harus menghasilkan sebuah angka bulat (menggunakan perintah **return** yang akan kita bahas sesaat lagi).

---

### std::cout << "Hello World!";

Perintah **std::cout** berguna untuk menampilkan sesuatu ke layar. Perintah ini merupakan bagian dari header **iostream**, sehingga jika kita ingin menggunakannya harus terdapat perintah **\#include \<iostream>** di bagian paling awal kode program bahasa C++.

Teks yang ingin ditampilkan ditulis setelah tanda **<<** dan berada dalam tanda kutip dua, seperti **std::cout << "Hello World!".** Hasil dari perintah ini, akan tampil teks **Hello, World!** di layar.

Di akhir perintah **std::cout** terdapat tanda titik koma (_semi-colon_), yakni tanda " ; ". Setiap perintah bahasa C++ harus diakhiri dengan tanda ini, kecuali beberapa perintah khusus. Lupa menambahkan tanda titik koma di akhir sebuah perintah merupakan error yang sangat sering terjadi.

Sebenarnya, perintah **std::cout** terdiri dari 2 bagian, yakni: _namespace_ **std**, dan perintah **cout**.

**Namespace** adalah fitur penamaan yang biasa ada dalam bahasa pemrograman yang menerapkan konsep **OOP** (_object oriented programming_). Tujuannya supaya berbagai perintah tidak saling bentrok.

Perintah **std::cout** artinya kita menjalankan perintah **cout** "milik" **std** _namespace_. Bisa saja nantinya ada perintah **foo::cout** yang berarti kita menjalankan perintah **cout** kepunyaan namespace **foo**. Dalam contoh ini, bahasa C++ membolehkan ada 2 perintah **cout**, selama dipanggil dari namespace yang berbeda.

Jika kita ingin menampilkan beberapa teks, bisa menulis perintah **std::cout** beberapa kali seperti contoh berikut:

```Cpp
#include <iostream>
 
int main()
{
  std::cout << "Hello World! \n";
  std::cout << "Sedang Belajar Bahasa C++ ";
  std::cout << "di Duniailkom";
  return 0;
}
```

Hasil kode program:

```
Hello World!
Sedang Belajar Bahasa C++ di Duniailkom
```

Tambahan karakter "\n" di akhir perintah **std::cout** pada baris 5 dipakai untuk pindah baris (_new line_). Tujuannya agar teks yang ada di dalam perintah **std::cout** di baris 6 pindah ke baris baru.

Alternatif penulisan lain adalah mendeklarasikan namespace std di bagian awal kode program dengan perintah **using namespace std**:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "Hello World! \n";
  cout << "Sedang Belajar Bahasa C++ ";
  cout << "di Duniailkom";
  return 0;
}
```

Perintah **using namespace std** di baris 3 bertujuan agar kita tidak perlu menulis namaspace **std::** di setiap perintah **cout**.

Tidak ada benar atau salah dari kedua cara penulisan ini, lebih ke kesukaan saja. Namun mayoritas tutorial lebih banyak menggunakan cara penulisan yang kedua, yakni memakai perintah **using namespace std** di awal kode program.

---

### return 0;

Perintah **return 0;** berhubungan dengan kode **int main()** sebelumnya. Disinilah kita menutup _function_ **main()** yang sekaligus mengakhiri kode program bahasa C++.

**Return 0** artinya kembalikan nilai **0** (nol) ke sistem operasi yang menjalankan kode program ini. Nilai 0 menandakan kode program berjalan normal dan tidak ada masalah (EXIT_SUCCESS).

Kita juga bisa menulis return 1, return 99, return -1, dll. Nilai-nilai ini nantinya bisa dipakai oleh sistem operasi atau program lain. Nilai return selain 0 dianggap terjadi error atau sesuatu yang salah (EXIT_FAILURE).

> [!NOTE]
> _Apakah perintah Return 0 ini harus ditulis?_
> 
> **Harus ditulis!** itu jika kita berpatokan ke struktur bahasa C++ yang ideal. Namun beberapa compiler (termasuk **Code:Blocks** yang saya gunakan), akan "memaafkan" jika perintah ini tidak ditulis dan menambahkan perintah return 0 secara otomatis.

---

Dalam tutorial kali ini kita telah melihat Struktur Dasar Kode Program C++. Berikutnya akan dibahas tentang [Aturan Dasar Penulisan Kode Program Bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-aturan-dasar-penulisan-kode-program-c-plus-plus/ "Tutorial Belajar C++ Part 6: Aturan Dasar Penulisan Kode Program C++").