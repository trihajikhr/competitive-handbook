---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-09-28T11:42:00
total_study: 1
tags:
  - Cpp
id: DIG4
---
# Tutorial Belajar C++ Part 40: Pengertian Default Parameter pada Function C++

03 Nov 20 

Melanjutkan sesi tutorial tentang Function C++, kali ini kita akan membahas Pengertian Default Parameter pada Function C++.

---

### Pengertian Default Parameter dalam C++

**Default Parameter** adalah istilah untuk parameter yang memiliki nilai awal, atau nilai default. Kadang fitur ini disebut juga sebagai **Default Argument**.

Sebagai contoh, misalkan kita membuat fungsi sederhana: **tambah()**. Fungsi ini perlu 2 buah parameter berupa nilai yang ingin ditambahkan. Berikut contoh kode programnya:

```Cpp
#include <iostream>
 
using namespace std;
 
int tambah(int var1, int var2) {
  return var1 + var2;
}
 
int main()
{
  cout << tambah(1, 2) << endl;
  cout << tambah(5, 4) << endl;
 
  return 0;
}
```

Hasil kode program:

```
3
9
```

Dengan **default parameter**, kita bisa memanggil fungsi **tambah()** hanya dengan 1 inputan angka, atau bahkan tidak perlu sama sekali. Berikut perubahannya:

```Cpp
#include <iostream>
 
using namespace std;
 
int tambah(int var1, int var2 = 2) {
  return var1 + var2;
}
 
int main()
{
  cout << tambah(1) << endl;
  cout << tambah(1, 2) << endl;
  cout << tambah(5, 4) << endl;
 
  return 0;
}
```

Perhatikan di dalam pendefinisian function tambah() di baris 5, saya menulis parameter kedua sebagai **int var2 = 2**. Inilah yang dimaksud dengan _default parameter_. Jika parameter **var2** tidak di isi pada saat pemanggilan function **tambah()**, angka 2 akan menjadi nilai awal dari parameter tersebut.

Dengan nilai _default_ ini, kita bisa merancang fungsi dengan parameter yang bersifat **opsional**. Parameter bisa diisi pada saat pemanggilan fungsi, namun boleh juga diabaikan.

Fitur **default parameter** bisa dimanfaatkan untuk membuat fungsi yang fleksibel, karena pada saat pemanggilan fungsi kita tidak harus menginputkan seluruh parameter, tetapi apa yang dianggap perlu saja.

---

### Penempatan Default Parameter

Sebuah fungsi bisa memiliki banyak **default parameter**, namun tidak boleh ada parameter tanpa nilai default yang ditulis setelah parameter dengan nilai default.

Contoh pendefinisian fungsi berikut ini akan menyebabkan error di C++:

```
int tambah(int var1 = 6, int var2) {
  return var1 + var2;
}
```

Ketika dijalankan, akan tampil pesan _error: default argument missing for parameter 2 of 'int tambah(int, int)'_.

Error terjadi karena parameter pertama sudah memiliki nilai default, sehingga parameter kedua, ketiga, dst juga harus memiliki nilai default.

---

### Membuat Fungsi Pemangkatan

Sebagai latihan dari default parameter dan juga pemrograman C++ secara umum, bisakah anda buat fungsi **pangkat()** yang ketika dijalankan akan menampilkan hasil sebagai berikut?

```Cpp
#include <iostream>
 
using namespace std;
 
int pangkat(....) {
  // Kode program function pangkat()
  // Kode program function pangkat()
  // Kode program function pangkat()
}
 
int main()
{
  cout << pangkat(3) << endl;      // 9
  cout << pangkat(5) << endl;      // 15
  cout << pangkat(10) << endl;     // 100
  cout << pangkat(3, 3) << endl;   // 27
  cout << pangkat(5, 4) << endl;   // 625
  cout << pangkat(6, 6) << endl;   // 46656
 
  return 0;
}
```

Dari pemanggilan function **pangkat()** terlihat bahwa function ini bisa diisi dengan 1 atau 2 argumen. Jika diisi satu argumen, dianggap mencari pangkat 2, sedangkan jika diisi dengan 2 argumen, maka argumen kedua akan menentukan berapa kali pangkat yang di inginkan.

Sebagai contoh, **pangkat(3)** sama dengan 3$^2$, yang hasilnya adalah 9. Sedangkan **pangkat(5, 4)** sama dengan 4$^5$ yang hasilnya adalah 625.

Untuk isi function sendiri, akan butuh sebuah perulangan untuk mencari hasil pangkat. Jika dijalankan **pangkat(5, 4)**, maka kita harus jalankan perintah 5 * 5 * 5 * 5. Nilai dari perintah inilah yang nantinya di return.

Silahkan coba sebentar untuk merancang function ini.

Baik, berikut kode program lengkap dari pembuatan function **pangkat()**:

```Cpp
#include <iostream>
 
using namespace std;
 
int pangkat(int angka, int pangkat = 2) {
 
  int hasil = 1;
  for (int i = 1; i <= pangkat; i++ ) {
    hasil = hasil * angka;
  }
  return hasil;
 
}
 
int main()
{
  cout << pangkat(3) << endl;      // 9
  cout << pangkat(5) << endl;      // 25
  cout << pangkat(10) << endl;     // 100
  cout << pangkat(3, 3) << endl;   // 27
  cout << pangkat(5, 4) << endl;   // 625
  cout << pangkat(6, 6) << endl;   // 46656
 
  return 0;
}
```

Function **pangkat()** memiliki 2 buah parameter: **angka** dan **pangkat**. Untuk parameter **pangkat** memiliki nilai default 2, sehingga jika pada saat pemanggilan tidak diisi, nilai 2 ini yang menjadi nilai untuk parameter.

Perhitungan mencari pangkat dilakukan dengan sebuah perulangan **for**. Perulangan akan dilakukan mulai dari 1 hingga nilai yang tersimpan di parameter **pangkat**. Dalam setiap perulangan, kalikan nilai **angka** dan simpan ke dalam variabel **hasil**. Terakhir return isi variabel **hasil**.

---

Dalam tutorial C++ kali ini kita telah mempelajari cara penggunaan **Default parameter**. Fitur ini bisa dimanfaatkan untuk membuat fungsi yang lebih fleksibel, karena cara pemanggilan fungsi dapat dirancang sesuai kebutuhan.

Berikutnya kita akan bahas tentang materi yang sedikit advanced, yakni [Pengertian Function Overloading C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-pengertian-function-overloading-c-plus-plus/ "Tutorial Belajar C++ Part 41: Pengertian Function Overloading C++").