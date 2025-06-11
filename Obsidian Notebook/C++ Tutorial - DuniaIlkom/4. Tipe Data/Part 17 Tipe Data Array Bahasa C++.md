---
obsidianUIMode: preview
sumber: duniailkom
level: pemula
bahasa: C++
tanggal_study: 2024-10-01T22:16:00
total_study: 3
tags:
  - Cpp
id: DID7
---
# Tutorial Belajar C++ Part 17: Tipe Data Array Bahasa C++

26 Oct 20 

Melanjutkan tutorial belajar bahasa C++ di Duniailkom, kita akan bahas pengertian dari tipe data array dalam bahasa C++ beserta contoh kode program cara penggunaannya.

---

### Pengertian Tipe Data Array C++

**Tipe data array** adalah tipe data yang terdiri dari kumpulan tipe data lain. Dalam bahasa Indonesia, array dikenal juga dengan istilah **Larik**. Dengan array, proses penyimpanan data ke dalam variabel menjadi lebih efisien dan mudah, terutama jika memiliki data dalam jumlah banyak.

Anggota atau isi dari array itu sendiri harus satu jenis tipe data, misalkan terdiri dari kumpulan angka bulat saja (_integer_), kumpulan karakter saja (_char_), maupun kumpulan angka pecahan saja (_double_). Di dalam bahasa C++, kita tidak bisa membuat 1 array dengan berbagai tipe data (harus 1 jenis saja).

Sebagai contoh, misalkan saya ingin menyimpan 5 buah nilai siswa. Tanpa array, maka harus menyiapkan 5 buah variabel:

```
int nilai1, nilai2, nilai3, nilai4, nilai5;
```

Jika menggunakan array, pendefinisian variabel cukup seperti ini:

```
int nilai[5];
```

Atau bagaimana jika ingin 1000 nilai? tidak masalah:

```
int nilai[1000];
```

Tentu jauh lebih efisien dibandingkan membuat 1000 buah variabel.

---

### Format Dasar penulisan Array dalam bahasa C++

Format pendefinisian array di dalam bahasa C++ adalah sebagai berikut:

```
tipe_data nama_variabel[jumlah_element]
```

**Element** adalah sebutan untuk isi atau anggota sebuah array.

Sebagai contoh, jika saya ingin membuat array dengan 100 element yang bisa diisi dengan tipe data _float_, pendefinisiannya adalah sebagai berikut:

```
float bilangan[100];
```

Berikutnya, bagaimana cara mengakses dan mengisi element array ini? Kita tinggal menuliskan nomor urut dari element yang akan akan diakses, nomor urut ini dikenal juga dengan istilah **index**. Berikut contohnya:

```
bilangan[5] = 3.14;
```

Perintah ini artinya kita sedang mengisi angka 3.14 ke index 4 dari array bilangan.

Yang harus perlu diperhatikan adalah, **nomor urut atau index array dimulai dari 0, bukan 1**. Akibatnya jika kita ingin mengakses element pertama dari array **bilangan**, penulisannya adalah **bilangan[0]**. Untuk bisa mengakses element ke-100 dari array bilangan, penulisannya adalah **bilangan[99]**.

Index array yang dimulai dari 0 ini hampir selalu menjadi ciri khas di seluruh bahasa pemrograman modern, termasuk Java, PHP, dan JavaScript.

---

### Contoh Kode Program Tipe Array Bahasa C++

Cukup dengan teori, mari kita lihat contoh praktek dari tipe data array dalam bahasa C++.

Sebagai contoh pertama, saya ingin membuat array **nilai** dengan 5 element bertipe **integer**, lalu mengisi dan menampilkan nilainya menggunakan perintah **cout**:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int nilai[5];
 
  nilai[0] = 23;
  nilai[1] = 50;
  nilai[2] = 34;
  nilai[3] = 78;
  nilai[4] = 90;
 
  cout << "Isi array pertama :" << nilai[0] <<endl;
  cout << "Isi array kedua   :" << nilai[1] <<endl;
  cout << "Isi array ketiga  :" << nilai[2] <<endl;
  cout << "Isi array keempat :" << nilai[3] <<endl;
  cout << "Isi array kelima  :" << nilai[4] <<endl;
 
  return 0;
}
```

Hasil kode program:

```
Isi array pertama :23
Isi array kedua   :50
Isi array ketiga  :34
Isi array keempat :78
Isi array kelima  :90
```

Di awal kode program, baris `int nilai[5]` dipakai untuk membuat sebuah array bernama **nilai** dengan 5 element atau 5 anggota. Array **nilai** ini di set sebagai **int**, yang artinya setiap element array hanya bisa diisi dengan bilangan bulat (_integer_).

Setelah pendefinisian array **nilai**, selanjutnya saya mengisi setiap element array. Kembali diingat bahwa index array dimulai dari 0, sehingga untuk mengakses element pertama dari array **nilai**, penulisannya adalah `nilai[0]`. Serta untuk element kelima diakses dari `nilai[4]`.

Di akhir program, saya menampilkan seluruh element array menggunakan perintah **cout**.

Dalam contoh sebelumnya, pengisian nilai array diproses satu persatu. Namun kita juga bisa mengisi element array langsung pada saat pendefinisian seperti contoh berikut:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  char karakter[5] = {'D', '$', 'o', 'Z', '8'};
 
  cout << "Isi array pertama :" << karakter[0] <<endl;
  cout << "Isi array kedua   :" << karakter[1] <<endl;
  cout << "Isi array ketiga  :" << karakter[2] <<endl;
  cout << "Isi array keempat :" << karakter[3] <<endl;
  cout << "Isi array kelima  :" << karakter[4] <<endl;
 
  return 0;
}
```

Hasil kode program:

```
Isi array pertama :D
Isi array kedua   :$
Isi array ketiga  :o
Isi array keempat :Z
Isi array kelima  :8
```

Dalam contoh ini saya juga mengubah tipe data array menjadi **char**. Selain itu semua isi array diinput sekaligus pada saat pembuatan, yakni dengan perintah **char karakter[5] = {'D', '$', 'o', 'Z', '8'}**. Tanda koma dipakai sebagai pemisah antara satu nilai dengan nilai lain.

Yang cukup unik, kita juga bisa mendefiniskan array tanpa harus menulis jumlah elemen anggotanya seperti contoh berikut:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  char karakter[] = {'D', '$', 'o', 'Z', '8'};
 
  cout << "Isi array pertama :" << karakter[0] <<endl;
  cout << "Isi array kedua   :" << karakter[1] <<endl;
  cout << "Isi array ketiga  :" << karakter[2] <<endl;
  cout << "Isi array keempat :" << karakter[3] <<endl;
  cout << "Isi array kelima  :" << karakter[4] <<endl;
 
  return 0;
}
```

Perhatikan cara pendefinisian array ini, yakni:

```
char karakter[] = {'D', '$', 'o', 'Z', '8'};
```

Disini saya tidak menginput angka apapun sebagai penentu jumlah element. Jumlah element akan digenerate secara otomatis dari banyaknya nilai yang diinput ke dalam array tersebut. Dalam contoh ini terdapat 5 nilai sehingga array **karakter** akan berisi 5 element.

Pembuatan array seperti ini hanya bisa dilakukan jika nilai untuk element array langsung ditulis pada saat pendefinisian. Kita tidak bisa memakai cara diatas jika element array diisi secara terpisah seperti contoh kode program pertama dalam tutorial ini.

Potongan kode program berikut akan menghasilkan error:

```Cpp
int main()
{
  int nilai[];  // error: storage size of 'nilai' isn't known
 
  nilai[0] = 23;
```

Ini terjadi karena kita tidak memberikan jumlah element pada saat deklarasi array, dan juga tidak menulis element array langsung pada saat deklarasi.

---

### Mengubah Isi Element Array

Isi dari element array sama halnya seperti variabel biasa, dimana kita bisa mengubah nilai element array sepanjang program, seperti contoh berikut:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  float pecahan[] = {3.14,-99.01,0.002};
 
  cout << "Isi array pertama : " << pecahan[0] << endl;
  cout << "Isi array kedua   : " << pecahan[1] << endl;
  cout << "Isi array ketiga  : " << pecahan[2] << endl;
  cout << endl;
 
  pecahan[1] = 9.123;
  pecahan[2] = 12.9925;
 
  cout << "Isi array pertama : " << pecahan[0] << endl;
  cout << "Isi array kedua   : " << pecahan[1] << endl;
  cout << "Isi array ketiga  : " << pecahan[2] << endl;
 
  return 0;
}
```

Hasil kode program:

```
Isi array pertama : 3.14
Isi array kedua   : -99.01
Isi array ketiga  : 0.002
 
Isi array pertama : 3.14
Isi array kedua   : 9.123
Isi array ketiga  : 12.9925
```

Setelah proses pendefinisian dan pengisian awal array **pecahan**, di tengah kode program saya mengubah nilai dari **pecahan[1]** dan **pecahan[2]**, akibatnya nilai element array sebelumnya akan tertimpa dengan nilai baru ini.

Pada tutorial sebelumnya tentang tipe data string, sempat dibahas bahwa dalam bahasa C++, string bisa diakses seperti array. Dan kita juga bisa mengubah karakter string dengan mengakses nomor indexnya:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  string var1 = "Belajar PHP di Duniailkom";
 
  var1[8] = 'C';
  var1[9] = '+';
  var1[10] = '+';
 
  cout << var1 << endl;
 
  return 0;
}
```

Hasil kode program:

```
Belajar C++ di Duniailkom
```

Di awal kode program, variabel var1 berisi string "Belajar PHP di Duniailkom". Kemudian karakter dengan nomor index 8, 9 dan 10 saya tukar dengan '**C**', '**+**' dan '**+**', sehingga isi string var1 juga berubah menjadi "Belajar C++ di Duniailkom".

---

Dalam tutorial ini kita telah membahas tipe data Array dalam bahasa pemrograman C++. Berikutnya akan dilanjutkan dengan [tipe data Struct](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-tipe-data-struct-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 18: Tipe Data Struct Bahasa C++").