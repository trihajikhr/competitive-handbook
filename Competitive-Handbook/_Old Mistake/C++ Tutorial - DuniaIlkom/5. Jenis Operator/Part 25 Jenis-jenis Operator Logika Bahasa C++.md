---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-09-27T09:28:00
total_study: 1
tags:
  - Cpp
id: DIE5
---
# Tutorial Belajar C++ Part 25: Jenis-jenis Operator Logika Bahasa C++

29 Oct 20 

Dalam tutorial belajar bahasa C++ di duniailkom kali ini kita akan membahas Jenis-jenis Operator Logika. **Operator logika** ini sering juga disebut sebagai **operator boolean**.

---

### Pengertian Operator Logika dalam Bahasa C++

Operator logika dipakai untuk menghasilkan nilai boolean **true** atau **false** dari 2 kondisi atau lebih. Tabel berikut merangkum hasil dari operator logika dalam bahasa C++:

|**Operator**|**Nama**|**Penjelasan**|**Contoh**|
|---|---|---|---|
|&&|And|Menghasilkan true jika kedua operand true|true && false, hasilnya: false|
|\||Or|Menghasilkan true jika salah satu operand true|true \| false, hasilnya: false|
|!|Not|Menghasilkan true jika operand false|!false, hasilnya: true|

Pada prakteknya, operator logika ini banyak dipakai untuk menggabungkan beberapa hasil operasi perbandingan (contohnya akan kita lihat sesaat lagi).

Catatan: operator OR menggunakan karakter **pipe** " | ", bukan huruf L kecil. Karakter pipe ini bergabung dengan tombol "\" dan ditekan menggunakan tombol shift.

---

### Contoh Kode Program Operator Logika Bahasa C++

Dalam bentuk paling sederhana, operator logika bisa diproses untuk boolean true dan false. Berikut contoh kode programnya:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  bool a = true;
  bool b = false;
  bool hasil;
 
  hasil = a && a;
  cout << "Hasil dari a && a : " << hasil << endl;
 
  hasil = a && b;
  cout << "Hasil dari a && b : " << hasil << endl;
 
  hasil = a || b;
  cout << "Hasil dari a || b : " << hasil << endl;
 
  hasil = b || b;
  cout << "Hasil dari b || b : " << hasil << endl;
 
  hasil = !a;
  cout << "Hasil dari !a : " << hasil << endl;
 
  hasil = !b;
  cout << "Hasil dari !b : " << hasil << endl;
 
  return 0;
}
```

Hasil kode program:

```
Hasil dari a && a : 1
Hasil dari a && b : 0
Hasil dari a || b : 1
Hasil dari b || b : 0
Hasil dari !a : 0
Hasil dari !b : 1
```

Seperti pembahasan dalam tutorial [tipe data boolean C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-tipe-data-boolean-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 15: Tipe Data Boolean Bahasa C++"), nilai true dan false akan ditampilkan sebagai 1 dan 0.

Rumus untuk menentukan hasil dari operator logika adalah sebagai berikut:

- Operator **&&** hanya akan menghasilkan true jika kedua operand bernilai true, selain itu hasilnya false.
- Operator **||** hanya akan menghasilkan false jika kedua operand bernilai false, selain itu hasilnya true .
- Operator **!** Akan membalikkan logika, !false menjadi true, !true menjadi false.

Kita juga bisa menggabungkan lebih dari satu operasi seperti contoh berikut:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  bool hasil;
 
  hasil = (false && true) || (true || false);
  cout << "Hasil: " << hasil << endl;
 
  hasil = !false && (false || true);
  cout << "Hasil: " << hasil << endl;
 
  hasil = ((true && true) || (true || false)) && !true;
  cout << "Hasil: " << hasil << endl;
 
  return 0;
}
```

Hasil kode program:

```
Hasil: 1
Hasil: 1
Hasil: 0
```

Untuk operasi seperti ini, akan diproses dari kiri ke kanan, kecuali ditemukan tanda kurung maka itulah yang akan diproses terlebih dahulu.

- Di baris 9, operasi **(false && true) || (true || false)** akan diproses menjadi **false || true**, hasilnya **true** (**1)**.
- Di baris 12, operasi **!false && (false || true)** akan diproses menjadi **true && true**, hasilnya **true** (**1)**.
- Di baris 15, operasi **((true && true) || (true || false)) && !true** akan diproses menjadi **(true || true) && false**, kemudian menjadi **true && false**, hasilnya **false (0)**.

Nilai boolean **true** dan **false** ini biasanya di dapat dari hasil operasi perbandingan. Inilah praktek yang sering dibuat untuk operator logika seperti contoh berikut:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  bool hasil;
 
  hasil = (5 > 4) && (10 > 9);
  cout << "(5 > 4) && (10 > 9) : " << hasil << endl;
 
  hasil = (15 <= 15) && (15 < 15);
  cout << "(15 <= 15) && (15 < 15) : " << hasil << endl;
 
  hasil = ('a' == 'a') || ('a' == 'b');
  cout << "('a' == 'a') || ('a' == 'b') : " << hasil << endl;
 
  hasil = (10 > 7) && ("duniailkom" == "duniailkom");
  cout << "(10 > 7) && (\"duniailkom\" == \"duniailkom\") : "
       << hasil << endl;
 
  return 0;
}
```

Hasil kode program:

[![Contoh Kode Program Operator Logika Bahasa C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Operator-Logika-Bahasa-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Operator-Logika-Bahasa-C.png)

Berikut penjelasan dari operasi logika yang dijalankan:

- Di baris 9, operasi **(5 > 4) && (10 > 9)** akan diproses menjadi **true && true**, hasilnya **true (1)**.
- Di baris 12, operasi **(15 <= 15) && (15 < 15)** akan diproses menjadi **true && false**, hasilnya **false (0)**.
- Di baris 15, operasi **('a'== 'a') || ('a' == 'b')** akan diproses menjadi **true || false**, hasilnya **true (1)**.
- Di baris 18, operasi **(10 > 7) && ('duniailkom' == 'duniailkom')** akan diproses menjadi **true && true**, hasilnya **true (1)**.

Sama seperti operasi perbandingan, operasi logika ini akan banyak dipakai pada percabangan kode program, misalnya untuk bisa login seseorang harus memiliki username **DAN** password yang sesuai. Jika salah satu saja tidak terpenuhi, maka tidak bisa login.

---

Selanjutnya, kita akan lanjut ke akan [Jenis-Jenis Operator Bitwise dalam bahasa Pemrograman C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-jenis-jenis-operator-bitwise-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 26: Jenis-jenis Operator Bitwise Bahasa C++").