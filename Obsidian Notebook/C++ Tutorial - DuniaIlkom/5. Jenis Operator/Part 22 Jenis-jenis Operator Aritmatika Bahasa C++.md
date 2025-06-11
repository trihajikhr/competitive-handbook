---
obsidianUIMode: preview
sumber: duniailkom
level: pemula
bahasa: C++
tanggal_study: 2024-09-26T19:05:00
total_study: 1
tags:
  - Cpp
id: DIE2
---
# Tutorial Belajar C++ Part 22: Jenis-jenis Operator Aritmatika Bahasa C++

28 Oct 20 

Operator aritmatika cukup sering dipakai dalam programming dan penggunaannya juga tidak terlalu rumit. Dalam tutorial belajar bahasa C++ kali ini kita akan mempelajari tentang Jenis-jenis Operator Aritmatika dalam Bahasa pemrograman C++.

---

### Pengertian dan Jenis Operator Aritmatika Bahasa C++

**Aritmatika** adalah cabang ilmu matematika yang membahas perhitungan dasar "kabataku", yakni operasi perkalian, pembagian, penambahan dan pengurangan.

Selain keempat operasi di atas, bahasa C++ juga memiliki operasi _modulo division_, atau operator **%** yang dipakai untuk mencari sisa hasil bagi.

Tabel berikut merangkum operator aritmatika dalam bahasa C++:

|Operator|Penjelasan|Contoh|
|---|---|---|
|+|Penambahan|a = 5 + 2|
|–|Pengurangan|a = 5 – 2|
|*|Perkalian|a = 5 * 2|
|/|Pembagian (real/pecahan)|a = 5 / 2|
|%|Sisa hasil bagi (modulus)|a = 5 % 2|

#### Operator Aritmatika Unary

|Operator|Penjelasan|Contoh|
|---|---|---|
|+|Positif (plus)|+5|
|–|Negatif (min)|-3|

Kita akan bahas dengan contoh kode program sesaat lagi.  

---

### Contoh Kode Program Operator Aritmatika Bahasa C++

Berikut contoh kode program penggunaan berbagai operator aritmatika dalam bahasa C++:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int a, b, c, d, e, f;
 
  a = 8 + 4;
  b = 9 - 2;
  c = 2 * 3;
  d = 10 + 3 - 7 * 4;
  e = ( ( 10 +3 ) -7) * 4;
  f = -79;
 
  cout << "Isi variabel a: " << a << endl;
  cout << "Isi variabel b: " << b << endl;
  cout << "Isi variabel c: " << c << endl;
  cout << "Isi variabel d: " << d << endl;
  cout << "Isi variabel e: " << e << endl;
  cout << "Isi variabel f: " << f << endl;
 
  return 0;
}
```

[![Contoh Kode Program Operator Aritmatika Bahasa C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Operator-Aritmatika-Bahasa-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Operator-Aritmatika-Bahasa-C.png)

Dalam contoh ini saya membuat beberapa operasi aritmatika, yakni **penambahan**, **pengurangan** dan **perkalian**.

Aturan prioritas operator berlaku di sini, dimana operator perkalian dan pembagian akan dijalankan terlebih dahulu daripada operator pengurangan dan penambahan. Untuk operator yang sama kuat (seperti penambahan dan pengurangan), akan diproses dari kiri ke kanan.

Tanda kurung bisa dipakai untuk memprioritaskan operator tertentu, seperti untuk menghitung variabel **e** dalam contoh di atas.

Saya sengaja tidak menampilkan operator pembagian karena ada beberapa hal yang akan kita bahas. Perhatikan kode berikut ini:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int a, b, c;
 
  a = 8 / 4;
  b = 8 / 3;
  c = 8 / 2;
 
  cout << "Isi variabel a: " << a << endl;
  cout << "Isi variabel b: " << b << endl;
  cout << "Isi variabel c: " << c << endl;
 
  return 0;
}
```

Hasil kode program:

```
Isi variabel a: 2
Isi variabel b: 2
Isi variabel c: 4
```

Di sini saya membuat 3 variabel integer: **a**, **b**, **c**. Untuk operasi **a** dan **c** tidak ada masalah, hasilnya sesuai dimana 8 / 4 = 2 dan 8 /2 = 4.

Tapi kenapa 8 / 3 menghasilkan angka 2? Mungkin ini karena b di set sebagai **integer**, bukan **float** atau **double**. Mari kita ubah tipe datanya:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  double a;
  a = 8 / 3;
 
  cout << "Isi variabel a: " << a << endl;
 
  return 0;
}
```

Hasil kode program:

```
Isi variabel a: 2
```

Mengapa hasilnya tetap **2**? Ini terjadi karena bahasa C++ melihat tipe data operand yang dipakai. Di sini operand nya adalah **8** dan **3** yang merupakan integer (angka bulat).

Agar operasi pembagian menghasilkan nilai float, kedua operand harus ditulis dalam format pecahan, yakni **8.0** dan **3.0**. Berikut hasilnya:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  double a;
  a = 8.0 / 3.0;
 
  cout << "Isi variabel a: " << a << endl;
 
  return 0;
}
```

Hasil kode program:

```
Isi variabel a: 2.666667
```

Yup, sekarang hasilnya sudah sesuai, dimana 8.0 / 3.0 adalah 2.666667. Untuk memformat tampilan akhir misalnya menjadi 2.66, bisa menggunakan berbagai teknik yang pernah kita bahas pada [Tutorial Tipe Data Float dan Double C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-tipe-data-float-dan-double-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 14: Tipe Data Float dan Double Bahasa C++").

---

### Pengertian Operator Mod (Modulus)

Operator **mod** (singkatan dari _modulo_ atau _modulus_) dipakai untuk mencari nilai sisa pembagian. Operator **mod** perlu penjelasan tersendiri terutama bagi yang baru pertama kali belajar bahasa pemrograman komputer. Operator ini terdengar asing tapi sebenarnya cukup sederhana.

Sebagai contoh:

- `8 mod 5 = 3`, karena 3 adalah angka sisa pembagian.
- `100 mod 7 = 2`, karena hanya 98 yang habis dibagi 7 (bersisa 2).

Berikut contoh kode program penggunaan operator **mod** dalam bahasa C++:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int a, b, c, d;
 
  a = 8 % 4;
  b = 8 % 5;
  c = 10 % 2;
  d = 100 % 7;
 
  cout << "Isi variabel a: " << a << endl;
  cout << "Isi variabel b: " << b << endl;
  cout << "Isi variabel c: " << c << endl;
  cout << "Isi variabel d: " << d << endl;
 
  return 0;
}
```

Hasil kode program:

```
Isi variabel a: 0
Isi variabel b: 3
Isi variabel c: 0
Isi variabel d: 2
```

Operator modulus cukup sering dipakai, misalnya menentukan sebuah bilangan genap atau ganjil. Untuk keperluan ini kita bisa memeriksa apakah **a % 2** menghasilkan 0? Jika iya, maka a berisi bilangan genap.

---

Dalam tutorial bahasa C++ kali ini kita telah membahas cara penggunaan operator aritmatika. Selain itu juga disinggung cara penggunaan operasi pembagian bahasa C++ yang butuh sedikit trik, serta pengertian dari operator **modulus**.

Selanjutnya, kita akan membahas [Operator Increment dan Decrement dalam Bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-jenis-jenis-operator-increment-decrement-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 23: Jenis-jenis Operator Increment & Decrement Bahasa C++").