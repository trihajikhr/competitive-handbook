---
obsidianUIMode: preview
sumber: duniailkom
level: pemula
bahasa: C++
tanggal_study: 2024-10-01T09:50:00
total_study: 4
tags:
  - Cpp
id: DIC5
---
# Tutorial Belajar C++ Part 9: Fungsi Perintah cout dalam Bahasa C++

20 Oct 20 

Pada dua tutorial sebelum ini kita sudah mendalami [Cara Membuat Variabel](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-pengertian-variabel-dalam-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 7: Pengertian Variabel dalam Bahasa C++") dan [Cara Membuat Konstanta](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-pengertian-konstanta-dalam-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 8: Pengertian Konstanta dalam Bahasa C++") dalam bahasa pemrograman C++. Kali ini akan dilanjutkan dengan bahasan **Fungsi Perintah cout pada Bahasa C++**.

---

### Fungsi Perintah cout Dalam Bahasa C++

Dalam bahasa pemrograman C++, perintah **cout** dipakai untuk menampilkan teks ke layar, yakni salah satu bentuk _output_. Perintah cout sendiri merupakan singkatan dari **console out**.

Perintah **cout** sebenarnya bukan bagian dari inti bahasa C++. Bahasa C++ tidak mempunyai sarana input dan output bawaan. Perintah **cout** berasal dari library atau file header **iostream** yang ditambahkan ke dalam kode C++. Karena itulah kita harus menulis baris `#include <iostream>` di awal setiap kode program yang butuh mengakses perintah **cout**.

Jika kode `#include <iostream>` tidak ditulis, akan menghasilkan error di baris **cout**:

```Cpp
using namespace std;
 
int main()
{
  cout << "Belajar Bahasa C++ di Duniailkom";
 
  return 0;
}
```

Hasil kode program:

```
error: 'cout' was not declared in this scope
```

---

### Cara Penggunaan Perintah cout

Bentuk penggunaan paling sederhana dari perintah **cout** adalah menampilkan sebuah teks. Berikut contoh kode programnya:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "Belajar Bahasa C++ di Duniailkom";
 
  return 0;
}
```

Hasilnya, akan tampil teks **"Belajar Bahasa C++ di Duniailkom"**.

Penulisan perintah **cout** harus diikuti karakter panah siku kiri dua kali, yakni karakter `<<`. Setelah itu barulah kita menulis teks yang ingin ditampilkan. Dalam bahasa C++, teks harus ditulis dalam tanda kutip dua.

> Perintah **cout** berada di dalam namespace **std**, sehingga harus ditulis sebagai **std::cout**. Atau tambahkan perintah **using namespace std** di awal kode program bahasa C++.

Bagaimana dengan membuat 2 buah teks? Tidak ada masalah, tinggal tambah satu lagi perintah **cout**:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "Belajar Bahasa C++ di Duniailkom";
  cout << "Semangat!!!";
 
  return 0;
}
```

[![Contoh Kode Program Penggunaan Perintah cout bahasa C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Penggunaan-Perintah-cout-bahasa-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Penggunaan-Perintah-cout-bahasa-C.png)

Kedua teks sudah tampil, tapi kenapa bersambung dalam 1 baris? Padahal kita menggunakan 2 buah perintah **cout**.

Inilah prilaku bawaan dari hampir semua bahasa pemrograman komputer. Jika kita ingin agar perintah **cout** kedua tampil di baris baru, harus ada instruksi untuk hal tersebut.

---

### Mengenal Escape Character

Di dalam bahasa C++, salah satu cara untuk pindah baris adalah dengan menulis karakter **"\n"**. Mari kita modifikasi kode program sebelumnya:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "Belajar Bahasa C++ di Duniailkom";
  cout << "\n";
  cout << "Semangat!!!";
  cout << "\n";
 
  return 0;
}
```

[![Contoh Kode Program Penggunaan Perintah cout bahasa C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Penggunaan-Perintah-cout-bahasa-C-2.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Penggunaan-Perintah-cout-bahasa-C-2.png)

Sekarang diantara kedua kalimat saya tambah perintah **cout << "\n"**. Hasilnya kedua kalimat akan tampil di baris terpisah. Termasuk baris "_Process returned 0 (0x0)…_" bawaan Code::Block juga terdorong ke arah bawah karena perintah **cout << "\n"** di baris 10.

Sebuah karakter yang diawali dengan tanda _backslash_ "\\" memiliki makna khusus di dalam programming. Kode **"\n"** berarti **new line**, ini adalah kode untuk pindah baris.

Selain itu ada juga kode **"\t"** untuk karakter **tab** dan beberapa kode lain. Kode-kode ini disebut juga sebagai **escape character**, yakni kode khusus untuk mewakili karakter yang tidak bisa ditulis. Berikut daftar lengkapnya:

| **Escape Character** | **Character**           |
| -------------------- | ----------------------- |
| \b                 | Backspace               |
| \f                 | Form feed               |
| \n                 | Newline                 |
| \r                 | Return                  |
| \t                 | Horizontal tab        |
| \v                 | Vertical tab          |
| \\                 | Backslash             |
| \'                 | Single quotation mark |
| \"                 | Double quotation mark |
| \?                 | Question mark         |
| \0                 | Null character        |

Kode "**\n**" tidak harus ditulis secara terpisah, tapi juga bisa digabung ke dalam 1 perintah **cout**:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "\t Belajar Bahasa C++ di Duniailkom \n Semangat!!! \n";
 
  return 0;
}
```

[![Contoh Kode Program Penggunaan Perintah cout bahasa C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Penggunaan-Perintah-cout-bahasa-C-3.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Penggunaan-Perintah-cout-bahasa-C-3.png)

Hasilnya, teks akan bergeser ke kanan karena terdapat karakter **"\t"** sebagai pengganti **tab**. Selain itu perintah diatas akan tampil dalam 2 baris karena terdapat karakter **\n** di tengah-tengah kalimat. Ini sebagai instruksi untuk pindah baris, meskipun hanya ditulis dalam 1 perintah **cout**.

---

### Mengenal Perintah endl

Sebagai alternatif penulisan untuk pindah baris, bahasa C++ juga menyediakan perintah **endl** (singkatan dari _end of line_). Berikut contoh penggunaannya:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "Belajar Bahasa C++ di Duniailkom" << endl;
  cout << "Semangat!!!"  << endl;
 
  return 0;
}
```

Hasil kode program:

```
Belajar Bahasa C++ di Duniailkom
Semangat!!!
```

Secara teknis, perintah **endl** adalah salah satu **manipulator** dalam bahasa C++, yakni perintah bantu untuk mengontrol input / output stream. Cara penggunaannya harus ditulis setelah tanda **<<** milik **cout**.

---

### Menampilkan Variabel dengan cout

Jika kita ingin menampilkan nilai yang tersimpan dalam sebuah variabel, bisa ditulis setelah perintah **cout <<** tanpa tanda kutip. Berikut contohnya:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  string foo = "C++";
  int bar = 45;
 
  cout << foo << endl;
  cout << bar << endl;
  return 0;
}
```

Hasil kode program:

```
C++
45
```

Di baris 7 – 8 saya membuat dua buah variabel bernama **foo** dan **bar**. Keduanya diisi dengan teks "**C++**" serta angka **45**. Isi kedua variabel kemudian ditampilkan dengan perintah **cout** di baris 10 – 11.

Jika kita ingin menggabungkan teks dengan variabel dalam satu perintah **cout**, pisah teks dengan variabel menggunakan tanda `<<`:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  string foo = "C++";
  int bar = 45;
 
  cout << "Belajar Bahasa " << foo << " di Duniailkom" << endl;
  cout << "Semangat "<< bar << endl;
  return 0;
}
```

Hasil kode program:

```
Belajar Bahasa C++ di Duniailkom
Semangat 45
```

Perhatikan cara penulisan perintah **cout** di baris 10 dan 11. Itulah cara menampilkan teks dan variabel dalam satu perintah. Kuncinya adalah, teks harus ditulis dalam tanda kutip dua, sedangkan variabel cukup ditulis namanya saja.

---

### Menampilkan Teks dengan Perintah printf

Bahasa C++ merupakan pengembangan dari bahasa C. Oleh karena itu kita juga bisa menggunakan perintah **printf** milik bahasa C di file C++. Berikut contoh penggunaannya:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  printf("Belajar bahasa C di Duniailkom \n");
  printf("Semangat!!! \n");
 
  return 0;
}
```

Hasil kode program:

```
Belajar Bahasa C++ di Duniailkom
Semangat!!!
```

Jika tertarik mendalami cara penulisan perintah printf ini bisa lanjut ke [Fungsi Perintah printf dalam Bahasa Pemrograman C](https://www.duniailkom.com/tutorial-belajar-c-fungsi-perintah-printf-dalam-bahasa-pemrograman-c/). Namun biasanya di dalam kode program C++ kita akan lebih banyak memakai perintah **cout**.

---

Perintah **cout** yang kita bahas pada tutorial kali ini bisa jadi merupakan perintah bahasa C++ yang akan paling banyak dipakai. Pasangan dari perintah **cout** adalah perintah **cin**, dan inilah yang akan kita bahas dalam tutorial selanjutnya: [Fungsi Perintah cin dalam Bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-fungsi-perintah-cin-dalam-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 10: Fungsi Perintah cin dalam Bahasa C++").