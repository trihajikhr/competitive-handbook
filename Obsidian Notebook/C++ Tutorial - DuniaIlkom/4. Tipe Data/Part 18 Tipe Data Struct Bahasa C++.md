---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-10-01T22:43:00
total_study: 3
tags:
  - Cpp
id: DID8
---
# Tutorial Belajar C++ Part 18: Tipe Data Struct Bahasa C++

26 Oct 20 

Bahasa pemrograman C++ memiliki tipe data yang cukup kompleks, yakni **struct**. Dalam lanjutan tutorial belajar bahasa C++ di Duniailkom kali ini kita akan bahas lebih dalam tentang Tipe Data Struct Bahasa C++.

---

### Pengertian Tipe Data Struct

Dalam bahasa C++, **struct** adalah tipe data bentukan yang terdiri dari kumpulan tipe data lain.

**Struct** mirip seperti array, tapi struct bisa menampung lebih dari 1 jenis tipe data. Jika sebelumnya anda pernah belajar bahasa pemrograman Pascal, struct dalam bahasa C++ sangat mirip seperti [tipe data record di Pascal](https://www.duniailkom.com/tutorial-belajar-pascal-pengertian-dan-cara-penggunaan-tipe-data-record-pascal/ "Tutorial Belajar Pascal Part 23: Pengertian dan Cara Penggunaan Tipe Data Record Pascal").

Tipe data **struct** cocok dipakai untuk menampung data berkelompok. Misalnya kita ingin membuat biodata siswa, dimana setiap siswa memiliki data **nama**, **nama sekolah** serta jumlah **uang saku**.

Menggunakan cara biasa, ketiga data bisa ditampung ke dalam 3 variabel berikut:

```Cpp
string nama_siswa01 = "Andi Permana Nugroho";
string nama_sekolah_siswa01 = "SMA 1 Lumut Ijo";
unsigned int uang_saku_siswa01 = 10000;
```

Untuk siswa kedua, tinggal membuat penamaan yang sama, yakni **nama_siswa02**, **nama_sekolah_siswa02** dan **uang_saku_siswa02**.

Cara ini tidak salah, namun setiap variabel seolah-olah terpisah satu sama lain. Satu-satunya yang menghubungkan ketiga variabel hanya dari penamaan saja. Kita tidak bisa menggunakan array karena 3 data di atas memiliki tipe data yang berbeda. Dalam kasus seperti inilah tipe data **struct** cocok digunakan.

---

### Cara Penggunaan Tipe Data Struct

Tipe data **struct** adalah tipe data bentukan, dimana kita harus buat dulu seperti apa isi komponen dari **struct**, baru kemudian diakses dari kode program utama.

Kita akan bahas dengan contoh kode program berikut ini:

```Cpp
#include <iostream>
 
using namespace std;
 
struct Siswa {
  string nama;
  string sekolah;
  unsigned int uangSaku;
};
 
int main()
{
  struct Siswa siswa01;
 
  siswa01.nama = "Andi Permana Nugroho";
  siswa01.sekolah = "SMA 1 Lumut Ijo";
  siswa01.uangSaku = 10000;
 
  cout << siswa01.nama <<" bersekolah di " << siswa01.sekolah << endl;
  cout << "dengan uang saku " << siswa01.uangSaku << " per hari" << endl;
 
  return 0;
}
```

Hasil Kode Program:

[![Contoh Kode Program Tipe Data Struct Bahasa C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Tipe-Data-Struct-Bahasa-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Tipe-Data-Struct-Bahasa-C.png)

Proses pembuatan tipe data **struct** ditulis sebelum main(), yang dalam contoh ada di baris 5 – 9.

Setelah keyword _struct_, diikuti dengan nama identitas atau nama tipe data yang kita inginkan. Dalam contoh ini saya membuat tipe data **Siswa**. Tentu saja anda bisa menggunakan nama lain.

Sebuah struct terdiri dari berbagai variabel yang ditulis di antara tanda kurung kurawal. Untuk tipe data struct **Siswa**, saya membuat variabel **nama**, **sekolah** dan **uangSaku**. Setiap variabel tetap ditulis tipe data asalnya.

Perintah di baris 5 – 9 dipakai untuk membuat struktur dasar struct. Agar bisa digunakan, kita harus membuat variabel baru dengan tipe data Siswa, yakni tipe data bentukan dari struct.

Masuk kode kode program utama (**main**), saya mendefinisikan variabel **siswa01** sebagai struct Siswa di baris 13. Sekarang, variabel **siswa01** adalah tipe data bentukan yang terdiri dari 3 element, yakni:

- **siswa01.nama**
- **siswa01.sekolah**
- **siswa01.uangSaku**

Tanda titik dipakai untuk mengakses sub struktur dari **siswa01**. Semua ini sesuai dengan pendefinisian struct **Siswa**. Proses pengisian data ke dalam variabel **siswa01** dilakukan pada baris 15 – 17.

Di bagian akhir kode program, saya menampilkan ketiga data **siswa01**. Caranya sama seperti variabel biasa, hanya saja sekarang kita menggunakan struct **Siswa** sehingga cara aksesnya adalah **siswa01.nama**, **siswa01.sekolah**, dan **siswa01.uangSaku**.

Bagaimana jika ada 3 siswa? Tidak masalah, cukup buat variabel **siswa01**, **siswa02**, dan **siswa03** sebagai struct **Siswa**:

```Cpp
#include <iostream>
 
using namespace std;
 
struct Siswa {
  string nama;
  string sekolah;
  unsigned int uangSaku;
};
 
int main()
{
  struct Siswa siswa01,siswa02, siswa03;
 
  siswa01.nama = "Andi Permana";
  siswa01.sekolah = "SMA 1 Lumut Ijo";
  siswa01.uangSaku = 10000;
 
  siswa02.nama = "Lisa Permata Sari";
  siswa02.sekolah = "SMA 1 Biru Langit";
  siswa02.uangSaku = 30000;
 
  siswa03.nama = "Jessica Stephany";
  siswa03.sekolah = "SMA 1 Merah Jambu";
  siswa03.uangSaku = 75000;
 
  cout << siswa01.nama <<" bersekolah di " << siswa01.sekolah;
  cout << " dengan uang saku " << siswa01.uangSaku << " per hari" << endl;
 
  cout << siswa02.nama <<" bersekolah di " << siswa02.sekolah;
  cout << " dengan uang saku " << siswa02.uangSaku << " per hari" << endl;
 
  cout << siswa03.nama <<" bersekolah di " << siswa03.sekolah;
  cout << " dengan uang saku " << siswa03.uangSaku << " per hari" << endl;
 
  return 0;
}
```

Hasil kode program:

```
Andi Permana bersekolah di SMA 1 Lumut Ijo dengan uang saku 10000 per hari
Lisa Permata Sari bersekolah di SMA 1 Biru Langit dengan uang saku 30000 per hari
Jessica Stephany bersekolah di SMA 1 Merah Jambu dengan uang saku 75000 per hari
```

Kode program diatas memang cukup panjang karena ada 3 data siswa yang harus diisi. Namun ini hanya pengembangan dari kode program kita sebelumnya.

---

### Input Tipe Data Struct Bahasa C++

Agar lebih menarik, bagaimana jika proses input data dilakukan secara interaktif, yakni meminta user menginput data tersebut.

Berikut kode programnya:

```Cpp
#include <iostream>
 
using namespace std;
 
struct Siswa {
  string nama;
  string sekolah;
  unsigned int uangSaku;
};
 
int main()
{
  struct Siswa siswa01;
 
  cout << "==++ Pendaftaran Siswa Baru ++==" << endl;
  cout << "Nama: ";
  getline(cin,siswa01.nama);
 
  cout << "Sekolah: ";
  getline(cin,siswa01.sekolah);
 
  cout << "Uang saku: ";
  cin >> siswa01.uangSaku;
 
  cout << endl;
 
  cout << siswa01.nama <<" bersekolah di " << siswa01.sekolah;
  cout << " dengan uang saku " << siswa01.uangSaku << " per hari" << endl;
 
  return 0;
}
```

Hasil Kode Program:

[![Contoh Kode Program Input Tipe Data Struct Bahasa C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Input-Tipe-Data-Struct-Bahasa-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Input-Tipe-Data-Struct-Bahasa-C.png)

Saya masih menggunakan struct **Siswa** dan juga variabel **siswa01**. Bedanya, proses input dilakukan dari perintah **getline()** dan **cin**.

Ketika program dijalankan, user akan diminta untuk mengisi data **nama**, **sekolah** dan **uangSaku**. Ketiga data ini akan disimpan ke dalam **siswa01.nama**, **siswa01.sekolah**, dan **siswa01.uangSaku** untuk kemudian ditampilkan kembali.

---

Dalam tutorial ini kita telah membahas salah satu tipe data bentukan dalam bahasa C++, yakni **struct**. Berikutnya akan dijelaskan tentang [Tipe Data Enum dalam Bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-tipe-data-enum-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 19: Tipe Data Enum Bahasa C++").