---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-09-26T22:53:00
total_study: 1
tags:
  - Cpp
id: DIE4
---
# Tutorial Belajar C++ Part 24: Jenis-jenis Operator Perbandingan / Relasional Bahasa C++

28 Oct 20 

Menyambung tutorial operator dalam bahasa pemrograman C++, kali ini akan dibahas tentang **Jenis-jenis Operator Perbandingan / Relasional**.

---

### Operator Perbandingan / Relasional Bahasa C++

Operator perbandingan dipakai untuk membandingkan 2 buah nilai, apakah nilai tersebut sama besar, lebih kecil, lebih besar, dst. Hasil dari operator perbandingan ini adalah boolean **true** atau **false.**

Ketika ditampilkan dengan perintah **cout**, true dan false ini akan ditampilkan compiler C++ sebagai integer 1 atau 0.

Tabel berikut merangkum hasil dari operator perbandingan dalam bahasa C++:

|**Operator**|**Penjelasan**|**Contoh**|**Hasil**|
|---|---|---|---|
|==|Sama dengan|5 == 5|1 (true)|
|!=|Tidak sama dengan|5 != 5|0 (false)|
|>|Lebih besar|5 > 6|0 (false)|
|<|Lebih kecil|5 < 6|1 (true)|
|>=|Lebih besar atau sama dengan|5 >= 3|1 (true)|
|<=|Lebih kecil atau sama dengan|5 <= 5|1 (true)|

Operator perbandingan biasa dipakai dalam proses pengambilan keputusan atau percabangan kode program. Sebagai contoh, jika angka pertama lebih besar dari kedua, maka jalankan perintah ini. Atau jika string **password = '123456'** maka berikan hak akses.

Operator perbandingan kadang disebut juga dengan **operator relasional** karena kita membandingkan hubungan (relasi) sebuah nilai dengan nilai lainnya.

---

### Contoh Kode Program Operator Perbandingan C++

Berikut contoh kode program untuk operasi perbandingan dalam bahasa C++:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int a = 10;
  int b = 5;
  bool hasil;
 
  cout << "Isi Variabel a: " << a << endl;
  cout << "Isi Variabel b: " << b << endl;
  cout << endl;
 
  hasil = a == b;
  cout << "Apakah a == b ? " << hasil << endl;
 
  hasil = a != b;
  cout << "Apakah a != b ? " << hasil << endl;
 
  hasil = a > b;
  cout << "Apakah a > b ? " << hasil << endl;
 
  hasil = a < b;
  cout << "Apakah a < b ? " << hasil << endl;
 
  hasil = a >= b;
  cout << "Apakah a >= b ? " << hasil << endl;
 
  hasil = a <= b;
  cout << "Apakah a <= b ? " << hasil << endl;
 
  return 0;
}
```

Hasil kode program:

```
Isi Variabel a: 10
Isi Variabel b: 5
 
Apakah a == b ? 0
Apakah a != b ? 1
Apakah a > b ? 1
Apakah a < b ? 0
Apakah a >= b ? 1
Apakah a <= b ? 0
```

Seperti pembahasan dalam tutorial [tipe data boolean C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-tipe-data-boolean-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 15: Tipe Data Boolean Bahasa C++"), nilai true dan false akan ditampilkan sebagai 1 dan 0.

Operasi perbandingan tidak hanya untuk tipe data angka saja, tapi juga bisa berbagai tipe data lain seperti **char** atau **string**. Berikut contohnya:

```Cpp
include <iostream>
 
using namespace std;
 
int main()
{
  bool hasil;
 
  hasil = 'z' == 'Z';
  cout << "Apakah 'z' == 'Z' ? " << hasil << endl;
 
  hasil = 'z' != 'Z';
  cout << "Apakah 'z' != 'Z' ? " << hasil << endl;
 
  hasil = "Duniailkom" == "duniailkom";
  cout << "Apakah \"Duniailkom\" == \"duniailkom\" ? " << hasil << endl;
 
  hasil = 'A' < 'B';
  cout << "Apakah 'A' < 'B'? " << hasil << endl;
 
  return 0;
}
```

Hasil kode program:

```
Apakah 'z' == 'Z' ? 0
Apakah 'z' != 'Z' ? 1
Apakah "Duniailkom" == "duniailkom" ? 0
Apakah 'A' < 'B'? 1
```

Jika yang dibandingkan berupa karakter, hasilnya dilihat dari urutan karakter ASCII. Dalam tabel ASCII, karakter 'A' memiliki nomor urut yang lebih rendah daripada 'B', sehingga 'A' < 'B' adalah **true**.

Dalam prakteknya, operasi perbandingan baru berguna dalam percabangan kode program seperti struktur **IF**:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int var1;
 
  cout << "Input sembarang angka bulat: ";
  cin >> var1;
 
  if (var1 % 2 != 0) {
    cout << var1 << " adalah angka ganjil" << endl;
  }
  else {
    cout << var1 << " adalah angka genap" << endl;
  }
 
  return 0;
}
```

Hasil kode program:

[![Contoh Kode Program Operator Perbandingan dan Operator Relasional Bahasa C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Operator-Perbandingan-dan-Operator-Relasional-Bahasa-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Operator-Perbandingan-dan-Operator-Relasional-Bahasa-C.png)

Kita memang belum membahas tentang struktur if, tapi konsepnya cukup sederhana. Di awal kode program saya meminta user untuk menginput sebuah angka. Angka ini kemudian disimpan ke dalam variabel **var1** hasil dari perintah **cin >> var1**.

Pada baris 12, saya melakukan sebuah operasi perbandingan: **if (var1 % 2 != 0)**? Yakni apakah **var1** tidak habis dibagi 2? Jika anda ragu dengan tanda %, itu adalah operator modulus yang pernah kita bahas dalam [tutorial operator aritmatika](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-jenis-jenis-operator-aritmatika-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 22: Jenis-jenis Operator Aritmatika Bahasa C++").

Kondisi di atas hanya akan **true** jika **var1** diisi dengan angka ganjil. Jika ini yang terjadi, jalankan perintah **cout << var1 << " adalah angka ganjil" << endl**. Jika hasilnya false, jalankan **cout << var1 << " adalah angka genap" << endl**. Inilah salah satu penerapan dari operasi perbandingan / relasi.

---

Dalam tutorial kali ini kita telah membahas pengertian dan cara penggunaan operator perbandingan dalam bahasa C++. Berikutnya akan disambung dengan [Jenis-jenis Operator Logika dalam bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-jenis-jenis-operator-logika-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 25: Jenis-jenis Operator Logika Bahasa C++").