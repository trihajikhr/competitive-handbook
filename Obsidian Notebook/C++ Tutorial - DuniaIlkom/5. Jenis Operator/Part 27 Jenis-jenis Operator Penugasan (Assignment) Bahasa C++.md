---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-09-27T10:09:00
total_study: 1
tags:
  - Cpp
id: DIE7
---
# Tutorial Belajar C++ Part 27: Jenis-jenis Operator Penugasan (Assignment) Bahasa C++

29 Oct 20 

Dalam tutorial bahasa pemrograman C++ di Duniailkom kali ini kita akan membahas **Jenis-jenis Operator Assignment atau Operator Penugasan.**

---

### Pengertian Operator Assignment / Penugasan

**Operator assignment** adalah operator untuk memasukkan suatu nilai ke dalam variabel. Operator ini sebenarnya sudah sering kita pakai sepanjang tutorial bahasa C++ di Duniailkom. Dalam bahasa C++, operator assignment menggunakan tanda sama dengan ( = ).

Pembacaan operasi assignment dilakukan dari kanan ke kiri, bukan dari kiri ke kanan seperti yang biasa kita pahami dalam matematika.

Kode berikut:

**a = 1000**

Berarti "masukkan nilai 1000 ke dalam variabel a". Dalam bahasa _pseudo code_ (jika anda membaca buku tentang algoritma), ini biasa ditulis dengan simbol panah ke kiri:

**a < - 1000**

Operator assignment ini disebut juga sebagai **Operator Penugasan**.

---

### Contoh Kode Program Operator Assignment Bahasa C++

Dalam prakteknya, operator assignment juga bisa dipakai bertingkat seperti contoh berikut:

```Cpp
#include <iostream>
  
using namespace std;
  
int main()
{
  int a, b, c, d, e;
  
  a = 5;
  b = 3;
   
  b = b + 1;
  c = a + b;
  d = c + c + a;
  e = (c + d)* a;
  
  cout << "Isi variabel a: " << a << endl;
  cout << "Isi variabel b: " << b << endl;
  cout << "Isi variabel c: " << c << endl;
  cout << "Isi variabel d: " << d << endl;
  cout << "Isi variabel e: " << e << endl;
  
  return 0;
}
```

Hasil kode program:

```
Isi variabel a: 5
Isi variabel b: 4
Isi variabel c: 9
Isi variabel d: 23
Isi variabel e: 160
```

Di awal kode program saya mendefinisikan 5 variabel, yakni **a**, **b**, **c**, **d**, dan **e** sebagai **integer**. Kemudian menginput angka 5 ke dalam variabel a, dan angka 3 ke dalam variabel b.

Di baris 12, perintah **b = b + 1** mungkin bisa membuat bingung. Tapi kuncinya adalah, operator assignment di proses dari kanan ke kiri, jadi operasi tersebut bisa dibaca: "tambah isi variabel b dengan 1, lalu simpan kembali ke dalam variabel b". Karena variabel b sudah berisi angka 3, maka hasil akhirnya variabel b akan bernilai **4**.

Di baris 13, perintah **c = a + b** akan di proses sebagai **c = 5 + 4**, hasilnya c berisi angka **9**.

Di baris 14 perintah **d = c + c + a** akan di proses sebagai **d = 9 + 9 + 5**, hasilnya c berisi angka **23**.

Terakhir di baris 15, perintah **e = (c + d)* a** akan di proses sebagai **e = (9 + 23) * 5**, hasilnya e berisi angka **160**.  

---

### Operator Assignment Gabungan Bahasa C++

Operator **assignment gabungan** adalah cara penulisan singkat operator assignment yang digabung dengan operator lain. Dalam bahasa C++ (dan juga bahasa turunan C lain seperti PHP, dan JavaScript), operator assignment gabungan ini terdiri dari operator assignment dengan operator lain seperti **aritmatika** dan **bitwise**.

Sebagai contoh, operasi **a = a + 1** bisa disingkat (dan digabung) menjadi **a += 1**. Contoh lain operasi **b >>= 1** adalah penulisan singkat dari **b = b >> 1**.

Tidak ada pengaruh apa-apa dari penulisan singkat seperti ini, anda boleh memilih penulisan yang panjang seperti **a = a + 1**, atau di singkat menjadi **a += 1**.

Tabel berikut merangkum semua operator assignment dalam bahasa C++:

|Operator|Contoh|Penjelasan|
|---|---|---|
|+=|a += b|a = a + b|
|-=|a -= b|a = a – b|
|*=|a *= b|a = a * b|
|/=|a /= b|a = a / b|
|%=|a %= b|a = a % b|
|&=|a &= b|a = a & b|
|\|=|a \|= b|a = a \| b|
|^=|a ^= b|a = a ^ b|
|<<=|a <<= b|a = a << b|
|>>=|a >>= b|a = a >> b|

---

### Contoh Kode Program Operator Assignment Gabungan Bahasa C++

Berikut contoh praktek dari operator penugasan gabungan dalam bahasa C++:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int a = 10, b = 10, c = 10, d = 10, e = 10, f = 10;
 
  cout << "Operator assignment gabungan bahasa C++" << endl;
  cout << "========================================" << endl;
  cout << "Variabel a, b, c, d, e, f = 10" << endl;
  cout << endl;
 
  a += 5;
  b -= 3;
  c *= 3;
  d /= 3;
  e %= 3;
  f <<= 2;
 
  cout << "Hasil operasi a += 5: "  << a << endl;
  cout << "Hasil operasi b -= 3: "  << b << endl;
  cout << "Hasil operasi c *= 3: "  << c << endl;
  cout << "Hasil operasi d /= 3: "  << d << endl;
  cout << "Hasil operasi e %= 3: "  << e << endl;
  cout << "Hasil operasi f <<= 2: " << f << endl;
 
  return 0;
}
```

Hasil kode program:

```
Operator assignment gabungan bahasa C++
========================================
Variabel a, b, c, d, e, f = 10
 
Hasil operasi a += 5: 15
Hasil operasi b -= 3: 7
Hasil operasi c *= 3: 30
Hasil operasi d /= 3: 3
Hasil operasi e %= 3: 1
Hasil operasi f <<= 2: 40
```

Dalam kode program ini saya membuat 6 buah operator assignment gabungan. Variabel a, b, c, d, e, dan f semuanya diisi dengan nilai awal 10, kemudian di proses dengan berbagai operator _assignment gabungan_.

---

Tutorial operator assignment dan assignment gabungan kali ini menutup sesi tentang operator bahasa C++. Berikutnya kita akan masuk ke alur kondisi kode program yang diawali dengan [Percabangan Kondisi IF Bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-percabangan-kondisi-if-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 28: Percabangan Kondisi IF Bahasa C++").