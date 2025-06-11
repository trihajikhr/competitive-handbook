---
obsidianUIMode: preview
sumber: duniailkom
level: pemula
bahasa: C++
tanggal_study: 2024-10-01T16:02:00
total_study: 3
tags:
  - Cpp
id: DID4
---
# Tutorial Belajar C++ Part 14: Tipe Data Float dan Double Bahasa C++

24 Oct 20

Tipe data **float** dan **double** adalah tipe data angka pecahan. Dalam lanjutan tutorial belajar bahasa pemrograman C++ di Duniailkom kali ini kita akan bahas tentang pengertian dan perbedaan antara keduanya.

---

### Pengertian Tipe Data Float dan Double C++

Tipe data **float** dan **double** dipakai untuk menampung angka pecahan seperti 3.14, 72.12 atau -0.06463. Sama seperti bahasa pemrograman pada umumnya, kita menggunakan tanda titik sebagai pemisah angka bulat dan pecahan, bukan tanda koma seperti yang kita pakai sehari-hari di Indonesia.

Perbedaan antara **float** dan **double** terletak dari jangkauan angka serta tingkat ketelitian. Berikut tabel perbedaan antara tipe data **float** dan **double** dalam bahasa C++:

| Jenis Tipe Data | Ukuran Memory   | Jangkauan                                   |
| --------------- | --------------- | ------------------------------------------- |
| **float**       | 4 byte (32 bit) | 3.4 \* 10$^{-38}$ hingga 3.4 \* 10$^{38}$   |
| **double**      | 8 byte (64 bit) | 1.7 \* 10$^{-308}$ hingga 1.7 \* 10$^{308}$ |

Sebenarnya masih ada 1 lagi jenis tipe data untuk angka pecahan, yakni **long double** dengan jangkauan yang lebih besar dari double. Namun tidak semua compiler bahasa C++ mendukung tipe data ini.

Penulisan angka pecahan juga bisa menggunakan notasi ilmiah, seperti 3.12e2 atau 4E-3. Tanda e atau E mewakili pangkat 10, sehingga 3.12e2 = 3.12 x 10$^2$ = 312. Sedangkan 4E-3 = 4 x 10$^{-3}$ = 0.004.

Meskipun tipe data **float** dan **double** bisa menyimpan angka yang sangat besar, tapi tipe data ini memiliki kelemahan yang umum di setiap bahasa pemrograman (tidak hanya di bahasa C++ saja). Yakni terdapat batas tingkat ketelitian. Hal ini berhubungan dengan mekanisme penyimpanan di dalam komputer yang berbentuk angka biner.

---

### Contoh Kode Program Tipe Data Float dan Double C++

Sebagai contoh kode program pertama, saya akan buat 2 variabel bertipe **float** dan **double**, menginput angka, lalu menampilkannya:

```Cpp
#include <iostream>

using namespace std;

int main()
{
  float  var1;
  double var2;

  var1 = 3.957;
  var2 = 0.019;

  cout << "Isi var1 = "  << var1 << endl;
  cout << "Isi var2 = "  << var2 << endl;

  return 0;
}
```

Hasil kode program:

```
Isi var1 = 3.957
Isi var2 = 0.019
```

Di awal kode program, saya mendeklarasikan variabel **var1** bertipe **float**, serta variabel **var2** bertipe **double**. Kemudian di baris 10 – 11, kedua variabel ini diisi dengan angka 3.957 dan 0.019.

Nilai untuk tipe data **float** dan **double** juga bisa ditulis dalam format notasi ilmiah (_scientific notation_):

```Cpp
#include <iostream>

using namespace std;

int main()
{
  double var1 = 4.27e5;
  double var2 = 4.27e6;
  double var3 = 7.99E-4;


  cout << "Isi var1 = "  << var1 << endl;
  cout << "Isi var2 = "  << var2 << endl;
  cout << "Isi var3 = "  << var3 << endl;

  return 0;
}
```

Hasil kode program:

```
Isi var1 = 427000
Isi var2 = 4.27e+06
Isi var3 = 0.000799
```

Dari percobaan ini terlihat secara default bahasa C++ menampilkan angka hingga 6 digit. Jika lebih, akan ditampilkan dengan notasi ilmiah. Inilah yang terjadi untuk **var2** yang ditampilkan kembali dengan nilai 4.27e+06.

---

### Mengatur Format Tampilan Float dan Double C++

Dalam banyak situasi, kita ingin membatasi tampilan angka pecahan untuk digit tertentu, misalnya ingin menampilkan 2 tempat desimal atau 3 tempat desimal saja.

Terdapat berbagai solusi untuk membuat tampilan seperti ini, namun kita harus pelajari dulu bagaimana cara kerja bahasa C++ dalam menampilkan angka pecahan.

Secara bawaan (default), bahasa C++ menampilkan angka **float** atau **double** sebanyak 6 digit angka, terlepas apakah angka tersebut berada sebelum atau setelah tanda titik:

```Cpp
#include <iostream>

using namespace std;

int main()
{
  double var1 = 3.1415926;
  double var2 = 1111.1234;
  double var3 = -1000000.11;
  double var4 = 0.00123456789;
  double var5 = -99.99999;

  cout << var1 << endl;
  cout << var2 << endl;
  cout << var3 << endl;
  cout << var4 << endl;
  cout << var5 << endl;

  return 0;
}
```

Hasil kode program:

```Cpp
3.14159
1111.12
-1e+06
0.000123457
-100
```

Pada kode program diatas saya membuat 5 buah variabel bertipe **double**, lalu menginputnya dengan angka yang berbeda-beda.

Ketika ditampilkan, variabel **var1**, **var2** dan **var3** sesuai dengan aturan 6 digit tadi. Jika total lebih dari 6 digit, maka ditampilkan dengan notasi ilmiah seperti isi **var3**. Selain itu angka-angka ini juga dibulatkan agar pas 6 digit, misalnya dari 3.1415926 menjadi 3.14159.

Yang agak berbeda ada di **var4** dan **var5**. Untuk **var4**, nilai yang tersimpan adalah 0.000123457. Total digit ini sudah lebih dari 6 digit, namun tetap ditampilkan utuh. Sedangkan isi **var5**, nilainya dibulatkan menjadi -100.

Jika kita ingin menampilkan setiap angka desimal dengan ketelitian 2 angka di belakang tanda titik, bisa menggunakan modifier **cout << fixed** dan **cout << setprecision(2)**. Berikut contoh penggunaannya:

```Cpp
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  double var1 = 3.1415926;
  double var2 = 1111.1234;
  double var3 = -1000000.11;
  double var4 = 0.00123456789;
  double var5 = -99.99999;

  cout << fixed;
  cout << setprecision(2);

  cout << var1 << endl;
  cout << var2 << endl;
  cout << var3 << endl;
  cout << var4 << endl;
  cout << var5 << endl;

  return 0;
}
```

Hasil kode program:

```
3.14
1111.12
-1000000.11
0.00
-100.00
```

Di awal kode program terdapat tambahan file header `#include <iomanip>`. Ini diperlukan karena kita akan memakai modifier **cout << setprecision(2)** di baris 15. Dengan kode program ini, setiap angka akan tampil dengan pembulatan 2 tempat desimal.

Untuk **var4**, hasilnya menjadi 0.00 karena pembulatan 2 tempat desimal dari 0.00123456789.

Modifier **cout << setprecision(x)** sebenarnya bisa juga di jalankan per baris. Pengaturan tersebut akan efektif sampai ada pengaturan lanjutan. Berikut contoh yang dimaksud:

```Cpp
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  double var1 = 3.1415926;
  cout << fixed;

  cout << setprecision(0) << var1 << endl;
  cout << setprecision(1) << var1 << endl;
  cout << setprecision(2) << var1 << endl;
  cout << setprecision(3) << var1 << endl;
  cout << setprecision(4) << var1 << endl;
  cout << var1 << endl;

  return 0;
}
```

Hasil kode program:

```
3
3.1
3.14
3.142
3.1416
3.1416
```

Dalam kode program ini isi variabel **var1** ditampilkan dengan berbagai tingkat ketelitian. Khusus untuk perintah **cout << var1** di baris 17 akan memakai **setprecision(4)** milik baris sebelumnya, karena itulah pengaturan **setprecision()** paling akhir. Pengaturan ini bisa saja ditimpa jika ada perintah **setprecision()** selanjutnya.

Alternatif cara lain untuk menampilkan angka float dan double adalah dengan perintah **printf** milik bahasa C:

```Cpp
#include <iostream>

using namespace std;

int main()
{
  double var1 = 3.1415926;

  printf("Isi variabel var1: %f \n",var1);
  printf("Isi variabel var1: %15f \n",var1);
  printf("Isi variabel var1: %015f \n",var1);
  printf("Isi variabel var1: %.3f \n",var1);
  printf("Isi variabel var1: %010.3f \n",var1);

  return 0;
}
```

Hasil kode program:

```
Isi variabel var1: 3.141593
Isi variabel var1:        3.141593
Isi variabel var1: 00000003.141593
Isi variabel var1: 3.142
Isi variabel var1: 000003.142
```

Lebih lanjut tentang cara penulisan **prinf** seperti ini bisa ke [Pengertian Tipe Data Float bahasa C](https://www.duniailkom.com/tutorial-belajar-c-pengertian-dan-contoh-kode-program-tipe-data-float/ "Tutorial Belajar C Part 17: Pengertian dan Contoh Kode Program Tipe Data Float").

---

### Batas Minimum dan Maksimum Float Bahasa C++

Sebagai penutup tutorial tentang tipe data **float** dan **double** bahasa C++, kita akan akses file header **<float.h>** yang berisi berbagai konstanta untuk melihat ukuran memory, nilai minimum, nilai maksimum serta jumlah digit ketelitian dari tipe data float dan juga tipe data double:

```Cpp
#include <iostream>
#include <float.h>

using namespace std;

int main()
{
 cout << "Ukuran memory tipe data float: " << sizeof(float) <<" byte \n";
 cout << "Ukuran memory tipe data double: "<< sizeof(double)<<" byte \n";

 cout << endl;

 cout << "Nilai minimal tipe data float: "  << FLT_MIN << endl;
 cout << "Nilai minimal tipe data double: " << DBL_MIN  << endl;

 cout << endl;

 cout << "Nilai maksimal tipe data float: "  << FLT_MAX << endl;
 cout << "Nilai maksimal tipe data double: " << DBL_MAX  << endl;

 cout << endl;

 cout << "Ketelitian float: "  << FLT_DIG << endl;
 cout << "Ketelitian double: "  << DBL_DIG  << endl;

 return 0;
}
```

Hasil kode program:

[![Contoh Kode Program Maksimum dan Minimum Tipe Data Float bahasa C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Maksimum-dan-Minimum-Tipe-Data-Float-bahasa-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Maksimum-dan-Minimum-Tipe-Data-Float-bahasa-C.png)

Dengan kode program ini kita bisa melihat informasi seputar tipe data **float** dan **double**.

---

Dalam tutorial belajar bahasa C++ di Duniailkom kali ini kita sudah membahas banyak hal terkait tipe data **float** dan **double**. Berikutnya akan di bahas tentang [Tipe Data Boolean Bahasa Pemrograman C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-tipe-data-boolean-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 15: Tipe Data Boolean Bahasa C++").