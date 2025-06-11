---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-09-28T10:49:00
total_study: 1
tags:
  - Cpp
id: DIG2
---
# Tutorial Belajar C++ Part 38: Pengertian Parameter dan Argumen Fungsi C++

02 Nov 20 

Melanjutkan pembahasan tentang fungsi (function) pada bahasa C++, dalam tutorial kali ini kita akan membahas tentang **pengertian parameter** dan **pengertian argumen fungsi**. Termasuk juga contoh kode program dari keduanya.

---

### Pengertian Parameter dan Argumen Fungsi dalam C++

Dalam tutorial sebelumnya kita telah melihat [cara membuat fungsi dalam bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-cara-membuat-fungsi-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 37: Cara Membuat Fungsi (Function) Bahasa C++"). Biasanya sebuah fungsi bisa menerima nilai masukan atau nilai input. Nilai masukan inilah yang dimaksud dengan **parameter** atau **argumen**.

**Parameter** adalah sebutan untuk nilai inputan fungsi pada saat fungsi itu di definisikan, sedangkan **argumen** adalah sebutan untuk nilai inputan fungsi pada saat fungsi itu dipanggil.

Tergantung kebutuhan, sebuah fungsi bisa menerima 1, 2, atau lebih dari 5 **parameter** atau **argumen**, namun bisa juga tidak memerlukan sama sekali.

Sebenarnya parameter dan argumen sangat mirip dan sering di pertukarkan. Perbedaan dari keduanya hanya di posisi pembuatan saja. **Parameter** merujuk kepada inputan fungsi pada saat pendefinisian, sedangkan **argumen** merujuk ke nilai input fungsi pada saat pemanggilan.

Berikut format dasar fungsi C++ dengan parameter dan argumen:

```Cpp
#include <iostream>
 
using namespace std;
 
tipeDataKembalian namaFunction(tipeData param1, tipeData param2) {
  // Isi function disini...
  // Isi function disini...
  return nilai;
}
 
int main()
{
  // Jalankan function
  namaFunction(arg1, arg2)
     
  return 0;
}
```

Di akhir baris 5, yakni dalam tanda kurung setelah **namaFunction**, adalah tempat untuk penulisan **parameter**. Parameter dalam bahasa C++ ditulis berpasangan antara tipeData dan nama parameter. Dalam contoh diatas, terdapat 2 buah parameter bernama **param1** dan **param2**. Sepanjang isi function, param1 dan param2 bisa diakses sebagaimana variabel biasa.

Ketika memanggil fungsi, kita harus isi kedua nilai seperti di baris 14, yakni dari perintah **namaFunction(arg1, arg2)**. Disini, **arg1** dan **arg2** adalah **argumen**.

Agar lebih mudah dipahami, langsung saja kita lihat contoh prakteknya.

---

### Contoh Kode Program Parameter dan Argumen Fungsi

Di tutorial sebelumnya, kita sudah membuat fungsi **sapaLisa()** yang ketika dipanggil akan menampilkan teks "Hai Lisa". Berikut saya tampilkan kembali kode yang dimaksud:

```Cpp
#include <iostream>
 
using namespace std;
 
void sapaLisa() {
  cout << "Hai Lisa" << endl;
}
 
int main()
{
  sapaLisa();
 
  return 0;
}
```

Hasil kode program:

```
Hai Lisa
```

Fungsi ini sudah berjalan sebagaimana mestinya, akan tetapi bagaimana jika kita ingin menyapa "Putri"? tentu kurang ideal jika harus menulis fungsi terpisah.

Akan lebih fleksibel, saya akan modifikasi fungsi **sapaLisa()** agar bisa menampung sebuah **parameter** dan **argumen**:

```Cpp
#include <iostream>
 
using namespace std;
 
void sapaTeman(string nama) {
  cout << "Hai " << nama << endl;
}
 
int main()
{
  sapaTeman("Lisa");
 
  return 0;
}
```

Hasil kode program:

```
Hai Lisa
```

Pada saat pendefinisian fungsi **sapaTeman()** di baris 5, saya menulis **sapaTeman(string nama)**. Disini, **nama** adalah sebuah **parameter** bertipe **string**.

Di dalam function, parameter bisa diakses sebagai mana layaknya variabel. Parameter **nama** kemudian saya tampikan memakai perintah **cout** seperti di baris 6.

Karena fungsi **sapaTeman()** memiliki 1 parameter, maka pada saat memanggil fungsi ini di baris 11, kita harus mengisi sebuah argumen yang dalam contoh ini adalah string "**Lisa**".

Harap diperhatikan bahwa tipe data argumen ini harus sama dengan tipe data pendefinisian parameter, yakni string.

Ketika dijalankan, argumen "**Lisa**" di baris 11 akan mengisi parameter **nama** di baris 5. Sehingga ketika perintah **cout << "Hai " << nama << endl** yang ada di dalam fungsi **sapaTeman()** di proses, hasilnya adalah "**Hai Lisa**".

Kita bisa menjalankan fungsi **sapaTeman()** dengan argumen yang berbeda-beda, selama bertipe string:

```Cpp
#include <iostream>
 
using namespace std;
 
void sapaTeman(string nama) {
  cout << "Hai " << nama << endl;
}
 
int main()
{
  sapaTeman("Lisa");
  sapaTeman("Sari");
  sapaTeman("Putri");
 
  return 0;
}
```

Hasil kode program:

```
Hai Lisa
Hai Sari
Hai Putri
```

Pendefinisian fungsi **sapaTeman()** masih sama seperti sebelumnya, hanya saja kali ini fungsi tersebut saya jalankan dengan 3 argumen berbeda antara baris 11 – 13. Hasilnya, akan tampil teks yang berbeda-beda.

Kuncinya adalah, **argumen** yang diisi pada saat pemanggilan function, akan di input ke dalam **parameter** function tersebut.

Jumlah dan tipe data argumen juga harus cocok dengan jumlah dan tipe data parameter. Ketiga pemanggilan fungsi **sapaTeman()** berikut akan menghasilkan error:

```Cpp
sapaTeman();               // tanpa argumen
sapaTeman(123);            // argumen berbeda tipe data
sapaTeman("Putri","Lisa"); // jumlah argumen lebih dari 1

```

Contoh pertama akan error karena fungsi **sapaTeman()** harus menerima satu argumen. Contoh kedua juga error karena tipe data argumen harus **string**, sesuai dengan tipe data pada saat pendefinisian parameter. Contoh ketiga kembali error karena fungsi **sapaTeman()** hanya bisa menerima satu argumen saja.

---

### Membuat Fungsi dengan Lebih dari 1 Parameter / Argumen

Kita bisa menginput lebih dari satu argumen ke dalam fungsi selama pendefinisian fungsi tersebut juga ditulis dengan lebih dari satu parameter.

Dalam contoh berikut saya memodifikasi fungsi **sapaTeman()** agar bisa menerima 3 argumen:

```Cpp
#include <iostream>
 
using namespace std;
 
void sapaTeman(string nama1, string nama2, string nama3) {
  cout << "Hai " << nama1 << ", ";
  cout << nama2 << ", dan " << nama3 << endl;
}
 
int main()
{
  sapaTeman("Lisa", "Nova", "Putri");
 
  return 0;
}
```

Hasil kode program:

```
Hai Lisa, Nova, dan Putri
```

Di baris 5, pendefinisian fungsi **sapaTeman()** sekarang punya 3 parameter bertipe **string**, yakni **nama1**, **nama2** dan **nama3**. Maka untuk menjalankan fungsi ini, juga harus diinput dengan 3 argumen bertipe string seperti di baris 12.

---

### Membuat Function hitungLuasSegitiga()

Sebagai contoh terakhir, berikut modifikasi fungsi **hitungLuasSegitiga()** yang bisa menerima 2 argumen bertipe integer:

```Cpp
#include <iostream>
 
using namespace std;
 
void hitungLuasSegitiga(int alas, int tinggi) {
  double luas = (alas * tinggi) / 2.0;
  cout << "Luas segitiga adalah: " << luas << endl;
}
 
int main()
{
  hitungLuasSegitiga(5, 7);
  hitungLuasSegitiga(2, 10);
  hitungLuasSegitiga(191, 357);
 
  return 0;
}
```

Hasil kode program:

```
Luas segitiga adalah: 17.5
Luas segitiga adalah: 10
Luas segitiga adalah: 34093.5
```

Di baris 5, fungsi **hitungLuasSegitiga()** saya definisikan dengan 2 buah parameter bertipe **int**, yakni **alas** dan **tinggi**.

Penamaan parameter boleh bebas, sama mengikuti aturan penamaan variabel / identifier, misalnya tidak boleh ada spasi dan tidak boleh diawali angka.

Antara baris 12 – 14 saya menjalankan fungsi **hitungLuasSegitiga()** sebanyak 3 kali dengan nilai argumen yang berbeda-beda.

Sebagai contoh, ketika compiler C++ memproses perintah **hitungLuasSegitiga(5, 7)**, angka 5 ini akan mengisi parameter **alas**, dan angka 7 akan mengisi parameter **tinggi**. Selanjutnya kedua parameter masuk ke perhitungan **luas** di baris 6. Hasilnya kemudian di tampilkan dari perintah **cout << "Luas segitiga adalah: " << luas << endl**.

---

Dalam tutorial belajar C++ kali ini kita sudah membahas pengertian parameter dan argumen serta melihat perbedaannya. Mudah-mudahan dengan contoh kode program yang ada anda bisa memahami maksud kedua istilah ini.

Lanjut, dalam tutorial berikutnya kita akan pelajari tentang [Fungsi Perintah Return pada Function](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-fungsi-perintah-return-pada-function-c-plus-plus/ "Tutorial Belajar C++ Part 39: Fungsi Perintah Return pada Function C++").