---
obsidianUIMode: preview
sumber: duniailkom
level: pemula
bahasa: C++
tanggal_study: 2024-10-01T10:06:00
total_study: 4
tags:
  - Cpp
id: DID3
---
# Tutorial Belajar C++ Part 13: Tipe Data Integer Bahasa C++

22 Oct 20 

Tutorial bahasa pemrograman C++ di Duniailkom kali ini akan membahas tentang tipe data **Integer**, mulai dari pengertian, jenis dan contoh kode program tipe data integer bahasa C++.

---

### Pengertian Tipe Integer Bahasa C++

Tipe data **integer** adalah tipe data yang dipakai untuk menampung angka bulat positif maupun negatif, seperti: 1, 45, dan -1945.

Di dalam bahasa C++, terdapat beberapa sub-tipe integer yang dibedakan berdasarkan jangkauan angka yang bisa ditampung. Setidaknya terdapat 4 tipe data integer di dalam bahasa C++:

- **char**
- **short**
- **int**
- **long**

Loh, bukannya **char** adalah tipe data untuk karakter? Kenapa juga ada di dalam integer? Betul, inilah keunikan tipe data **char** di dalam bahasa C / C++.

Secara internal, **char** sebenarnya bertipe **integer**. Untuk membedakan apakah **char** ini berisi karakter atau huruf dilakukan pada saat menampilkannya (akan kita lihat dengan contoh praktek).

Perbedaan dari keempat jenis tipe data diatas adalah dari segi jangkauan angka yang bisa ditampung. Tabel berikut menyajikan data yang lebih lengkap:

|**Jenis Tipe Data**|**Ukuran Memory Penyimpanan**|**Jangkauan**|
|---|---|---|
|**char**|1 byte|-128 hingga 127|
|**short**|2 bytes|-32,768 hingga 32,767|
|**int**|2 bytes|-32,768 hingga 32,767|
|**int**|4 bytes|-2,147,483,648 hingga 2,147,483,647|
|**long**|4 bytes|-2,147,483,648 hingga 2,147,483,647|

_Ukuran Memory Penyimpanan_ adalah jumlah memory yang dibutuhkan untuk menyimpan angka tersebut. Semakin besar jangkauan, semakin banyak juga ruang memory yang dibutuhkan.

Khusus untuk tipe data **int**, bisa terdiri dari 2 byte maupun 4 byte. Ini tergantung sistem komputer dan compiler bahasa C++ yang dipakai.

Jangkauan tipe data diatas adalah untuk angka yang bertanda (_signed_). Maksudnya, setiap tipe data bisa menampung angka positif dan negatif. Kita bisa mengorbankan nilai negatif ini untuk memperbesar jangkauan angka positif dengan menambahkan keyword **_unsigned_** sebelum penulisan tipe data.

Jika tipe data integer di-set sebagai **unsigned** (tidak bertanda), maka tipe data tersebut tidak bisa menampung angka negatif, namun jatah untuk angka negatif akan dialihkan kepada angka positif sehingga jangkauannya menjadi 2 kali lipat.

Berikut tabel jangkauan setiap tipe data **unsigned integer** dalam bahasa C++:

|**Jenis Tipe Data**|**Ukuran Memory Penyimpanan**|**Jangkauan**|
|---|---|---|
|**unsigned char**|1 byte|0 hingga 255|
|**unsigned short**|2 bytes|0 hingga 65,535|
|**unsigned int**|2 bytes|0 hingga 65,535|
|**unsigned int**|4 bytes|0 hingga 4,294,967,295|
|**unsigned long**|4 bytes|0 hingga 4,294,967,295|

Terlihat jangkauan angkanya menjadi lebih besar, tapi tidak bisa menampung angka negatif. Tipe data **unsigned** ini cocok untuk data yang tidak pernah negatif, seperti tinggi badan, berat badan, jumlah orang, dsb.

---

### Contoh Kode Program Tipe Data Integer Bahasa C++

Cukup dengan teori, mari kita masuk ke contoh praktek. Dalam kode program berikut saya menampilkan 3 tipe data **integer** dalam bahasa C++:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  short angka1;
  int   angka2;
  long  angka3;
 
  angka1 = 32767;
  angka2 = 2147483647;
  angka3 = 2147483647;
 
  cout << "Isi variabel angka1 (short): " << angka1 << endl;
  cout << "Isi variabel angka2 (int)  : " << angka2 << endl;
  cout << "Isi variabel angka3 (long) : " << angka3 << endl;
 
  return 0;
}
```

Di awal kode program saya membuat 3 variabel: **angka1**, **angka2**, dan **angka3**. Setiap variabel di-set dengan tipe data yang berbeda-beda, dimana variabel **angka1** sebagai **short**, variabel **angka2** sebagai **int**, dan variabel **angka3** sebagai **long**.

Setelah pendefinisian variabel, setiap variabel diisi dengan angka. Angka yang ada sengaja saya set dengan nilai maksimum untuk setiap tipe data. Terakhir setiap variabel ditampilkan menggunakan perintah **cout**.

Khusus untuk **char**, mendapat perlakuan khusus karena di proses dengan sedikit berbeda. Berikut contoh kasusnya:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  char foo = 65;
  char bar = 'Z';
 
  cout << "Isi variabel foo: " << foo << endl;
  cout << "Isi variabel bar: " << bar << endl;
 
  printf("Isi variabel foo: %d \n",foo);
  printf("Isi variabel bar: %d \n",bar);
 
  return 0;
}
```

Dalam kode program ini saya membuat dua buah variabel bertipe char: **foo** dan **bar**. Untuk variabel **foo** diisi dengan angka 65, sedangkan variabel **bar** diisi dengan karakter 'Z'.

Sekilas kode seperti ini terlihat aneh. Kenapa tipe data **char** bisa diisi angka dan karakter sekaligus? Jawabannya karena secara internal, tipe data char disimpan sebagai angka. Akan tetapi begitu di tampilkan dengan perintah **cout** seperti di baris 10 dan 11, tampil berbentuk karakter.

Ketika variabel **foo** diakses akan tampil huruf 'A'. Dari mana datangnya huruf 'A' ini? Huruf A tersebut berasal dari daftar kode karakter ASCII. Di dalam daftar karakter ASCII, huruf A berada di urutan ke 65. Daftar lengkap karakter ASCII bisa dilihat ke [id.wikipedia.org/wiki/ASCII](https://id.wikipedia.org/wiki/ASCII).

Jika kita ingin mengakses angka yang tersimpan di dalam variabel char, bisa menggunakan perintah **printf** milik bahasa C. Inilah yang saya pakai di baris 13 – 14. Hasilnya, variabel **foo** tampil sebagai angka 65, dan variabel **bar** sebagai angka 90. Angka 90 untuk karakter 'Z' ini juga bisa dilihat dari daftar karakter ASCII.

Mengenai cara kerja perintah **printf** bahasa C, bisa dibaca dalam tutorial [Format Penulisan printf untuk Menampilkan isi Variabel](https://www.duniailkom.com/tutorial-belajar-c-format-penulisan-printf-untuk-menampilkan-isi-variabel/).

---

### Contoh Kode Program Unsigned Integer C++

Di penjelasan sebelumnya, jangkauan angka positif tipe data integer bisa diperbesar dengan menambah keyword **unsigned**. Berikut contoh penggunaannya:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  unsigned char  angka1;
  unsigned short angka2;
  unsigned int   angka3;
  unsigned long  angka4;
 
  angka1 = 255;
  angka2 = 65535;
  angka3 = 4294967295;
  angka4 = 4294967295;
 
  printf("Isi variabel angka1: %d \n",angka1);
 
  cout << "Isi variabel angka2: " << angka2 << endl;
  cout << "Isi variabel angka3: " << angka3 << endl;
  cout << "Isi variabel angka4: " << angka4 << endl;
 
  return 0;
}
```

Hasil kode program:

```
Isi variabel angka1: 255
Isi variabel angka2: 65535
Isi variabel angka3: 4294967295
Isi variabel angka4: 4294967295
```

Sekarang jangkauan setiap tipe data sudah membesar 2 kali lipat dengan mengorbankan angka negatif. Namun, kita tidak bisa lagi menginput angka negatif ke dalam variabel di atas.

Tipe data **char** yang sebelumnya hanya bisa sampai angka 127 sekarang bisa menampung nilai 0 – 255. Begitu juga dengan tipe data unsigned **short** yang bisa menampung 0 – 65535. Serta tipe data **int** dan **long** yang sekarang sampai ke 4294967295.

Apa yang terjadi apabila menginput angka di luar batas maksimum? Mari kita coba:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  unsigned char  angka1;
  unsigned short angka2;
  unsigned int   angka3;
  unsigned long  angka4;
 
  angka1 = 299;
  angka2 = 65599;
  angka3 = 4294967299;
  angka4 = 4294967299;
 
  printf("Isi variabel angka1: %d \n",angka1);
 
  cout << "Isi variabel angka2: " << angka2 << endl;
  cout << "Isi variabel angka3: " << angka3 << endl;
  cout << "Isi variabel angka4: " << angka4 << endl;
 
  return 0;
}
```

[![Contoh Kode Program Tipe Data Integer bahasa C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Tipe-Data-Integer-bahasa-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Tipe-Data-Integer-bahasa-C.png)

Hasilnya, angka yang tersimpan tidak lagi sesuai. Atau untuk beberapa compiler, bisa saja tampil pesan error.

---

### Batas Minimum dan Maksimum Integer Bahasa C++

Sebagai kode program terakhir, saya akan menambah sebuah file header baru, yakni `<limits>`. File header ini berisi berbagai konstanta dan fungsi agar kita bisa melihat berapa sebenarnya nilai maksimum dan minimum dari setiap tipe data. Berikut contoh penggunaannya:

```Cpp
#include <iostream>
#include <limits>
 
using namespace std;
 
int main()
{
 cout << "Ukuran memory tipe data char: "  << sizeof(char) << " byte \n";
 cout << "Ukuran memory tipe data short: " << sizeof(short) << " byte \n";
 cout << "Ukuran memory tipe data int: "   << sizeof(int) << " byte \n";
 cout << "Ukuran memory tipe data long: "  << sizeof(long) << " byte \n";
 
 cout << endl;
 
 cout << "Nilai minimal tipe data char: "  << SCHAR_MIN << endl;
 cout << "Nilai minimal tipe data short: " << SHRT_MIN  << endl;
 cout << "Nilai minimal tipe data int: "   << INT_MIN   << endl;
 cout << "Nilai minimal tipe data long: "  << LONG_MIN  << endl;
 
 cout << endl;
 
 cout << "Nilai maksimal tipe data char: "  << SCHAR_MAX << endl;
 cout << "Nilai maksimal tipe data short: " << SHRT_MAX  << endl;
 cout << "Nilai maksimal tipe data int: "   << INT_MAX   << endl;
 cout << "Nilai maksimal tipe data long: "  << LONG_MAX  << endl;
 
 return 0;
}
```

![[Part 13 Tipe Data Integer Bahasa C++.png]]

Perhatikan tambahan perintah `#include <limits>` di baris kedua. Inilah cara kita menambahkan fungsi-fungsi baru ke dalam kode program C++.

Dengan tambahan perintah ini, kita bisa menggunakan fungsi **sizeof()** untuk melihat berapa jumlah memory yang dipakai untuk setiap tipe data, serta mengakses konstanta seperti **SCHAR_MIN** untuk melihat nilai minimum dari tipe data char, serta **SCHAR_MAX** untuk melihat nilai maksimum tipe data char. Begitu juga dengan tipe data integer lainnya.

---

Dalam tutorial kali ini kita telah membahas pengertian tipe data integer, melihat 4 jenis tipe data integer bahasa C++, serta menjalankan beberapa contoh kode program untuk tipe data integer.

Tipe data integer hanya bisa dipakai untuk menampung angka bulat. Bagaimana dengan angka pecahan? Kita akan bahas dalam tutorial selanjutnya: [Tipe Data Float dan Double Bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-tipe-data-float-dan-double-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 14: Tipe Data Float dan Double Bahasa C++").