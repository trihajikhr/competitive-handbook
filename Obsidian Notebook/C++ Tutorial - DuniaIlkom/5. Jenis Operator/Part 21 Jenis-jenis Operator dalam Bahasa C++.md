---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-09-26T18:50:00
total_study: 1
tags:
  - Cpp
id: DIE1
---
# Tutorial Belajar C++ Part 21: Jenis-jenis Operator dalam Bahasa C++

27 Oct 20 

Pada 9 tutorial sebelum ini kita telah membahas apa saja tipe data dalam bahasa pemrograman C++. Untuk mengolah data tersebut, butuh operator. Karena itulah untuk lanjutan tutorial belajar bahasa C++ ini kita akan bahas tentang [Jenis-jenis Operator dalam Bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-jenis-jenis-operator-dalam-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 21: Jenis-jenis Operator dalam Bahasa C++").

Kali ini kita akan lihat secara ringkas apa saja jenis-jenis operator dalam Bahasa C++. Penjelasan lebih lanjut beserta contoh kode program akan dibahas dalam tutorial terpisah.

---

### Pengertian Operand dan Operator

Sebelum masuk ke jenis-jenis operator di dalam bahasa C++, terdapat istilah _operand_ dan _operator_. **Operand** adalah nilai asal yang dipakai dalam sebuah proses operasi. Sedangkan **Operator** adalah instruksi yang diberikan untuk mendapatkan hasil dari proses tersebut.

Biasanya operator berbentuk karakter matematis atau perintah singkat sederhana. Sebagai contoh, pada operasi: 10 + 2. Angka 10 dan 2 disebut sebagai **operand**, sedangkan tanda tambah (karakter +) adalah **operator**.

---

### Operator Unary, Binary dan Ternary

Berdasarkan jumlah operand-nya, operator C++ dibagi menjadi 3 jenis: **Operator Unary**, **Operator Binary** dan **Operator Ternary**.

- **Operator Unary** adalah operator yang hanya terdiri dari 1 operand. Contohnya adalah operator positif (plus): +7, +9, +10.111
- **Operator Binary** adalah operator yang terdiri dari 2 operand. Sebagian besar operator di dalam bahasa C++ termasuk ke dalam operator binary. Contohnya seperti operator aritmatika: 4 + 8, 9 * 2, 8 % 2, dll.
- **Operator Ternary** adalah operator yang terdiri dari 3 operand. Bahasa C++ memiliki 1 operator ternary, yakni " ? : " seperti (a == 1) ? 20: 30.

---

### Jenis-jenis Operator dalam Bahasa Pemrograman C++

Berikut jenis-jenis operator dalam bahasa pemrograman C++:

- **Operator Aritmatika**
- **Operator Increment dan Decrement**
- **Operator Perbandingan / Relasional**
- **Operator Logika / Boolean**
- **Operator Bitwise**
- **Operator Assignment**
- **Operator Lainnya**

Daftar di atas bisa saja berbeda karena cara pengelompokkan yang dipakai, misalnya operator _increment_ atau _decrement_ kadang dimasukkan ke dalam operator artmatika. Kita akan bahas sekilas tentang pengertian dari operator-operator ini.

---

### Operator Aritmatika

**Operator aritmatika** adalah operator yang biasa kita temukan untuk operasi matematika. Aritmatika sendiri merupakan cabang ilmu matematika yang membahas perhitungan sederhana, seperti kali, bagi, tambah dan kurang (kabataku)

Selain keempat operasi tersebut, bahasa C++ juga memiliki operasi _modulo division_, atau operator % yang dipakai untuk mencari sisa hasil bagi.

Tabel berikut merangkum operator aritmatika dalam bahasa pemrograman C++:

|**Operator**|**Penjelasan**|**Contoh**|
|---|---|---|
|+|Penambahan|a = 5 + 2|
|–|Pengurangan|a = 5 – 2|
|*|Perkalian|a = 5 * 2|
|/|Pembagian (real/pecahan)|a = 5 / 2|
|%|Sisa hasil bagi (modulus)|a = 5 % 2|

#### Operator Aritmatika Unary

|**Operator**|**Penjelasan**|**Contoh**|
|---|---|---|
|+|Positif (plus)|+5|
|–|Negatif (min)|-3|

Penjelasan lebih lanjut tentang operator Aritmatika dalam bahasa C++ beserta contoh kode program bisa ke: [Jenis-jenis Operator Aritmatika Bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-jenis-jenis-operator-aritmatika-bahasa-c-plus-plus/).  

---

### Operator Increment dan Decrement

Operator **increment** dan **decrement** adalah sebutan untuk operasi seperti **a++**, dan **a--**. Ini sebenarnya penulisan singkat dari operasi **a = a + 1** serta **a = a – 1**.

**Increment** digunakan untuk menambah variabel sebanyak 1 angka, sedangkan **decrement** digunakan untuk mengurangi variabel sebanyak 1 angka.

Penulisannya menggunakan tanda tambah 2 kali untuk **increment**, dan tanda kurang 2 kali untuk **decrement**. Penempatan tanda tambah atau kurang ini boleh di awal seperti **++a** dan **--a**, atau di akhir variabel seperti **a++** dan **a--**.

Dengan demikian terdapat 4 jenis **increment** dan **decrement** dalam bahasa C++:

|**Operator**|**Contoh**|**Penjelasan**|
|---|---|---|
|Pre-increment|`++a`|Tambah a sebanyak 1 angka, lalu tampilkan hasilnya|
|Post-increment|`a++`|Tampilkan nilai a, lalu tambah a sebanyak 1 angka|
|Pre-decrement|`--a`|Kurangi a sebanyak 1 angka, lalu tampilkan hasilnya|
|Post-decrement|`a--`|Tampilkan nilai a, lalu kurangi a sebanyak 1 angka|

Penjelasan lebih lanjut tentang operator Increment dan Decrement dalam bahasa C++ beserta contoh kode program bisa ke: [Jenis-jenis Operator Increment & Decrement Bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-jenis-jenis-operator-increment-decrement-bahasa-c-plus-plus/).

---

### Operator Perbandingan / Relasional

Operator perbandingan dipakai untuk membandingkan 2 buah nilai, apakah nilai tersebut sama besar, lebih kecil, lebih besar, dll. Hasil dari operator perbandingan ini adalah boolean **true** atau **false**.

Ketika ditampilkan dengan perintah **cout**, true dan false ini akan ditampilkan C++ sebagai integer 1 atau 0.

|**Operator**|**Penjelasan**|**Contoh**|**Hasil**|
|---|---|---|---|
|==|Sama dengan|5 == 5|1 (true)|
|!=|Tidak sama dengan|5 != 5|0 (false)|
|>|Lebih besar|5 > 6|0 (false)|
|<|Lebih kecil|5 < 6|1 (true)|
|>=|Lebih besar atau sama dengan|5 >= 3|1 (true)|
|<=|Lebih kecil atau sama dengan|5 <= 5|1 (true)|

Penjelasan lebih lanjut tentang operator Perbandingan / Relasional beserta contoh kode program bisa ke: [Tutorial C++ Jenis-jenis Operator Perbandingan / Relasional](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-jenis-jenis-operator-perbandingan-relasional-bahasa-c-plus-plus/).

---

### Operator Logika / Boolean

Operator logika dipakai untuk menghasilkan nilai boolean true atau false dari 2 kondisi atau lebih.

|Operator|Nama|Penjelasan|Contoh|
|---|---|---|---|
|&&|And|Akan menghasilkan true jika kedua operand true|true && false, hasilnya: false|
|\||Or|Akan menghasilkan true jika salah satu operand true|true \| false, hasilnya: true|
|!|Not|Akan menghasilkan true jika operand false|!false, hasilnya: true|

Rumus yang dipakai adalah sebagai berikut:

- Operator **&&** hanya akan menghasilkan true jika kedua operand bernilai true, selain itu hasilnya false.
- Operator **||** hanya akan menghasilkan false jika kedua operand bernilai false, selain itu hasilnya true.
- Operator **!** Akan membalikkan logika, !false menjadi true, !true menjadi false.

Penjelasan lebih lanjut tentang operator Operator Logika / Boolean beserta contoh kode program bisa ke: [Tutorial C++ Jenis-jenis Operator Logika Bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-jenis-jenis-operator-logika-bahasa-c-plus-plus/).

---

### Operator Bitwise

**Bitwise** adalah operator khusus untuk menangani operasi logika bilangan biner dalam bentuk bit.

**Bilangan biner** sendiri merupakan jenis bilangan yang hanya terdiri dari 2 jenis angka, yakni 0 dan 1. Jika nilai asal yang dipakai bukan bilangan biner, akan dikonversi secara otomatis oleh compiler C++ menjadi bilangan biner. Misalnya 7 desimal = 0111 dalam bilangan biner.

Bahasa C++ mendukung 6 jenis operator bitwise. Daftar lengkapnya dapat dilihat pada tabel berikut:

|**Operator**|**Nama**|**Contoh**|**Biner**|**Hasil (biner)**|**Hasil (desimal)**|
|---|---|---|---|---|---|
|&|AND|10 & 12|1010 & 1100|1000|8|
|\||OR|10 \| 12|1010 \| 1100|1110|14|
|^|XOR|10 ^ 1|1010 ^ 1100|0110|6|
|~|NOT|~ 5|~0101|1011|-11 (Two's complement)|
|<<|Left shift|10 << 1|1010 << 1|10100|20|
|>>|Right shift|10 >> 1|1010 >> 1|101|5|

Penjelasan lebih lanjut tentang operator bitwise beserta contoh kode program bisa ke: [Tutorial C++ Jenis-jenis Operator Bitwise](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-jenis-jenis-operator-bitwise-bahasa-c-plus-plus/).

---

### Operator Assignment

Operator assignment adalah operator yang digunakan untuk memberikan nilai ke dalam suatu variabel. Di dalam bahasa C++, operator assignment menggunakan tanda sama dengan " = ". Nantinya juga terdapat operator assignment gabungan, seperti " += ", " -= ", dsb.

Penjelasan lebih lanjut tentang operator assignment beserta contoh kode program bisa ke: [Tutorial C++ Jenis-jenis Operator Penugasan (Assignment)](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-jenis-jenis-operator-assignment-bahasa-c-plus-plus/).

---

### Operator Lainnya

Operator Lainnya ini adalah kelompok operator khusus yang tidak termasuk ke dalam kelompok sebelumnya, diantaranya adalah operator **sizeof** dan operator ternary " ? : ".

---

Itulah jenis-jenis operator yang terdapat di dalam bahasa pemrograman C++. Penjelasan lebih detail, termasuk pengertian, cara penggunaan serta contoh kode programnya akan saya bahas pada tutorial terpisah.

Kita akan mulai dengan operator aritmatika terlebih dahulu: [Jenis-jenis Operator Aritmatika Bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-jenis-jenis-operator-aritmatika-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 22: Jenis-jenis Operator Aritmatika Bahasa C++").