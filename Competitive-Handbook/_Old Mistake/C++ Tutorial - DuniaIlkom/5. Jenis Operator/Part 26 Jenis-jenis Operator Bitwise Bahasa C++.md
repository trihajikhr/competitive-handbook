---
obsidianUIMode: preview
sumber: duniailkom
level: sulit
bahasa: C++
tanggal_study: 2024-09-27T09:56:00
total_study: 1
tags:
  - Cpp
id: DIE6
---
# Tutorial Belajar C++ Part 26: Jenis-jenis Operator Bitwise Bahasa C++

29 Oct 20 

Melanjutkan pembahasan tentang operator bahasa C++, dalam tutorial ini kita akan mempelajari **Pengertian dan Jenis-jenis Operator Bitwise** dalam bahasa pemrograman C++.

---

### Pengertian Operator Bitwise dalam Bahasa C++

**Bitwise** adalah operator khusus untuk menangani operasi logika bilangan biner dalam bentuk bit.

**Bilangan biner** sendiri merupakan jenis bilangan yang hanya terdiri dari 2 jenis angka, yakni 0 dan 1. Jika nilai asal yang dipakai bukan bilangan biner, akan dikonversi secara otomatis oleh compiler C++ menjadi bilangan biner. Misalnya 7 desimal = 0111 dalam bilangan biner.

Dalam penerapannya, operator bitwise tidak terlalu sering kita pakai, kecuali sedang membuat program yang harus memproses bit-bit komputer. Selain itu operator ini cukup rumit dan harus memiliki pemahaman tentang sistem bilangan biner. Dalam bahasan kali ini saya menganggap pembaca sudah paham beda antara bilangan biner (basis 2) dan bilangan desimal (basis 10).

Bahasa C++ mendukung 6 jenis operator bitwise. Daftar lengkapnya dapat dilihat pada tabel berikut:

|**Operator**|**Nama**|**Contoh**|**Biner**|**Hasil (biner)**|**Hasil (desimal)**|
|---|---|---|---|---|---|
|&|AND|10 & 12|1010 & 1100|1000|8|
|\||OR|10 \| 12|1010 \| 1100|1110|14|
|^|XOR|10 ^ 1|1010 ^ 1100|0110|6|
|~|NOT|~10|~1010|0101|-11 (Two's complement)|
|<<|Left shift|10 << 1|1010 << 1|10100|20|
|>>|Right shift|10 >> 1|1010 >> 1|101|5|

---

### Contoh Kode Program Operator Bitwise Bahasa C++

Berikut contoh kode program operator bitwise dalam bahasa C++:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int a = 181;
  int b = 108;
  int hasil;
 
  hasil = a & b;
  cout << "Hasil dari a & b : " << hasil << endl;
 
  hasil = a | b;
  cout << "Hasil dari a | b : " << hasil << endl;
 
  hasil = a ^ b;
  cout << "Hasil dari a ^ b : " << hasil << endl;
 
  hasil = ~a;
  cout << "Hasil dari ~a : " << hasil << endl;
 
  hasil = a >> 1;
  cout << "Hasil dari a >> 1 : " << hasil << endl;
 
  hasil = b << 2;
  cout << "Hasil dari b << 2 : " << hasil << endl;
 
  return 0;
}
```

Hasil kode program:

```
Hasil dari a & b : 36
Hasil dari a | b : 253
Hasil dari a ^ b : 217
Hasil dari ~a : -182
Hasil dari a >> 1 : 90
Hasil dari b << 2 : 432
```

Dalam contoh di atas saya mendefinisikan 2 variabel: **a** dan **b**. Kemudian memberikan nilai awal **181** dan **108**. Jika di konversi ke dalam bentuk biner, keduanya berisi angka berikut:

```
a = 181 (desimal) = 10110101 (biner) 
b = 108 (desimal) = 01101100 (biner)
```

Di baris 11 saya melakukan operasi **&** (AND) terhadap kedua variabel. Operasi bitwise "and" ini akan memproses bit per bit dari kedua variabel, jika kedua bit sama-sama 1, maka hasilnya juga 1, selain kondisi tersebut, nilai akhirnya adalah 0. Berikut perhitungan bitwise "and":

```
a     = 10110101
b     = 01101100
        --------
a & b = 00100100 = 36 (desimal)
```

Tampilan perintah **cout** di baris 12 memperlihatkan isinya sama dengan perhitungan kita, yakni 36 (dalam bentuk desimal).

Di baris 14 terdapat operasi **|** (OR), hasilnya akan bernilai 0 jika kedua bit bernilai 0, selain itu nilai bit akan di set menjadi 1. Berikut cara perhitungan bitwise "or":

```
a     = 10110101
b     = 01101100
        --------
a | b = 11111101 = 253 (desimal)
```

Di baris 17 terdapat operasi **^** (XOR), hasilnya akan bernilai 1 jika salah satu dari kedua variabel bernilai 1 (namun tidak keduanya). Atau dengan kata lain jika kedua bit berlainan, hasilnya 1 tapi kalau sama-sama 0 atau sama-sama 1, hasilnya 0.

Berikut cara perhitungan bitwise "xor":

```
a       = 10110101
b       = 01101100
          --------
$a ^ $b = 11011001 = 217 (desimal)
```

Di baris 20 saya membuat operasi **~** atau not, yang akan membalikkan nilai bit sebuah variabel dari 0 menjadi 1, dan 1 menjadi nol. Namun perhitungan bit not ini sedikit membingungkan karena jika kita hanya membalikkan seluruh bit saja, hasilnya tidak sesuai dengan apa yang dihitung oleh compiler C++:

```
a  = 10110101
     --------
~a = 01001010 = 74 (desimal) ==> salah ???
```

Dari hasil menjalankan program, dapat dilihat bahwa ~a = -182, dari manakah datangnya angka -182?

Ini berkaitan dengan cara compiler bahasa C++ menyimpan angka biner (dan juga hampir semua bahasa pemrograman komputer modern). Angka biner di dalam bahasa C++ disimpan dalam format "Two's complement". Penjelasan tentang "Two's complement" ini cukup panjang, jika tertarik saya sudah membahasnya lengkap di buku [Pascal Uncover](https://www.duniailkom.com/pascal-uncover-panduan-belajar-pascal-untuk-pemula/), atau bisa ke [Two's complement Wikipedia](https://en.wikipedia.org/wiki/Two%27s_complement).

Secara singkat, rumusnya adalah `-a - 1`, sehingga `~a = -181 - 1 = -182` (desimal)

Di baris 23 terdapat operator **shift right** ">>" dimana bahasa C++ akan menggeser posisi bit dalam variabel a ke kanan sebanyak 1 tempat. Berikut proses yang terjadi:

```
a      = 10110101 = 181
a >> 1 =  1011010 = 90 (desimal)
```

Operator shift right menggeser nilai biner variabel a ke arah kanan, sehingga digit paling kanan akan dihapus. Operator shift right ini akan menghasilkan nilai asal / 2. Dalam contoh kita, hasilnya adalah 180/2 = 90 (dibulatkan). Setiap penggeseran 1 tempat ke kanan akan membagi 2 nilai asal.

Di baris 26 merupakan operator **shift left** "<<" dimana nilai variabel b akan digeser sebanyak 2 digit ke kiri. Berikut proses yang terjadi:

```
b       =   01101100 = 108
b << 1  =  011011000 = 216 (desimal)
b << 2  = 0110110000 = 432 (desimal)
```

Ketika hasil pergeseran ke kiri, digit paling kanan akan diisi angka 0. Setiap penggeseran 1 tempat ke kiri akan mengkali 2 nilai asal. Karena variabel b berisi desimal 108, maka hasil dari << 2 sama dengan 108 * 2 = 216, 216 * 2 = 432.

---

Dalam tutorial kali ini kita telah mempelajari operator bitwise dalam bahasa pemrograman C++. Pada prakteknya, operator bitwise tidak terlalu sering dipakai.

Salah satu implementasi operator bitwise adalah untuk membuat algoritma enkripsi. Misalnya menggunakan operasi **xor** untuk mengacak urutan bit saat proses encrypt, lalu di **xor** kembali saat proses decrypt.

Berikutnya akan masuk ke [Operator Assignment atau Operator Penugasan bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-jenis-jenis-operator-assignment-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 27: Jenis-jenis Operator Penugasan (Assignment) Bahasa C++").