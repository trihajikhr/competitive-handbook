---
obsidianUIMode: preview
sumber: duniailkom
level: pemula
bahasa: C++
tanggal_study: 2024-10-01T18:59:00
total_study: 3
tags:
  - Cpp
id: DID5
---
# Tutorial Belajar C++ Part 15: Tipe Data Boolean Bahasa C++

25 Oct 20 

**Tipe data boolean** bisa dianggap sebagai tipe data paling sederhana di dalam C++. Namun **Boolean** menjadi sangat penting dan selalu ada di setiap bahasa pemrograman komputer. Penggunaan tipe data yang satu ini juga sangat banyak.

Untuk lebih lanjut, kita akan bahas tentang [Tipe Data Boolean dalam Bahasa Pemrograman C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-tipe-data-boolean-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 15: Tipe Data Boolean Bahasa C++").

---

### Pengertian Tipe Data Boolean C++

**Tipe data boolean** adalah tipe data yang hanya bisa diisi salah satu dari 2 nilai: **true** atau **false**. Tipe data **boolean** banyak dipakai untuk percabangan kode program atau untuk memutuskan apa yang mesti dijalankan ketika sebuah kondisi terjadi.

Sebagai contoh, kita bisa membuat kode program untuk menentukan apakah sebuah angka genap atau ganjil berdasarkan input dari pengguna. Untuk keperluan ini kita harus periksa terlebih dahulu apakah angka tersebut bisa dibagi 2 (untuk angka genap), atau tidak bisa dibagi 2 (untuk angka ganjil). Tipe data boolean bisa dipakai untuk menampung kondisi seperti ini, yakni benar atau salah (_True_ atau _False_).

Penggunaan tipe data boolean ini akan lebih jelas saat kita masuk ke kondisi percabangan program seperti **if-else** yang akan dibahas pada tutorial terpisah.

---

### Contoh Kode Program Tipe Data Boolean C++

Untuk membuat tipe data boolean, sebuah variabel harus di deklarasikan dengan keyword **bool**. Berikut contoh kode programnya:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  bool var1 = true;
  bool var2 = false;
 
  cout << "Isi var1 = "  << var1 << endl;
  cout << "Isi var2 = "  << var2 << endl;
 
  return 0;
}
```

Hasil kode program:

```
Isi var1 = 1
Isi var2 = 0
```

Dalam kode program ini saya mendeklarasikan **var1** dan **var2** untuk menampung tipe data **boolean**, kemudian menginput nilai **true** ke **var1** dan nilai **false** ke **var2**.

Pada saat ditampilkan dengan perintah **cout**, nilai boolean **true** akan tampil sebagai angka 1, sedangkan nilai boolean **false** tampil sebagai angka 0.

Penulisan nilai **true** dan **false** dalam bahasa C++ harus dengan huruf kecil semua. Compiler C++ akan menghasilkan error jika nilainya diinput dengan huruf besar atau variasi huruf lain:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  bool var1 = True;
  bool var2 = false;
 
  cout << "Isi var1 = "  << var1 << endl;
  cout << "Isi var2 = "  << var2 << endl;
 
  return 0;
}
```

Hasil kode program:

```
error: 'True' was not declared in this scope
```

Umumnya, tipe data boolean di dapat dari hasil **operasi perbandingan**, seperti apakah sebuah angka sama dengan angka lain, apakah lebih besar atau lebih kecil, dst. Berikut contoh yang dimaksud:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  bool var1, var2, var3;
 
  var1 = 12 < 10;
  var2 = 30 > 25;
  var3 = 'A' == 'a';
 
  cout << "Isi var1 = "  << var1 << endl;
  cout << "Isi var2 = "  << var2 << endl;
  cout << "Isi var3 = "  << var3 << endl;
 
  return 0;
}
```

Hasil kode program:

```
Isi var1 = 0
Isi var2 = 1
Isi var3 = 0
```

Lebih lanjut tentang operasi perbandingan seperti ini akan kita bahas dalam tutorial tersendiri. Namun konsep dasarnya cukup sederhana. Di baris 9 saya melakukan operasi perbandingan, yakni apakah **12 < 10**? tidak, maka hasilnya adalah **false**.

Di baris 10, yang dibandingkan adalah apakah **30 > 25**? benar, maka **var2** akan berisi nilai **true**. Begitu juga di baris 11, yakni apakah **'A' sama dengan 'a'**? tidak, maka var3 akan berisi nilai boolean **false**.

Konsep true dan false ini sangat berguna untuk proses pemeriksaan kondisi **if else**, seperti contoh berikut:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int var1 = 12;
  int var2 = 10;
 
  if (var1 < var2) {
    cout << "var1 lebih kecil daripada var2" << endl;
  }
  else if (var1 > var2) {
    cout << "var1 lebih besar daripada var2" << endl;
  }
  else {
    cout << "var1 sama dengan var2"<< endl;
  }
 
  return 0;
}
```

Hasil kode program:

```
var1 lebih besar daripada var2
```

Materi tentang struktur **if else** memang belum kita bahas. Tapi sebagai gambaran, dalam kode ini saya membandingkan antara angka yang tersimpan di variabel **var1** dengan **var2**. Operasi perbandingan di baris 10 dan 13 akan mengembalikan nilai boolean. Jika hasil perbandingan ini ada yang menghasilkan **true**, maka blok if itulah yang akan diproses.

Dalam contoh ini, variabel **var1** berisi angka 12 yang lebih besar daripada **var2** yang berisi angka 10. Sehingga operasi perbandingan **var1 > var2** di baris 13 akan bernilai **true**. Hasilnya, tampil teks "_var1 lebih besar daripada var2_".

---

Dalam lanjutan tutorial belajar bahasa pemrograman C++ ini kita telah membahas tentang pengertian tipe data **Boolean** beserta contoh kode programnya. Lanjut, kita akan bahas tentang [Tipe Data String dalam Bahasa Pemrograman C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-tipe-data-string-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 16: Tipe Data String Bahasa C++").