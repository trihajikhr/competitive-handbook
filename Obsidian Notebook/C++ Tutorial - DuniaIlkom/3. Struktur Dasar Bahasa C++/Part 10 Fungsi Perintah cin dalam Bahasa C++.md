---
obsidianUIMode: preview
sumber: duniailkom
level: pemula
bahasa: C++
tanggal_study: 2024-10-01T10:01:00
total_study: 4
tags:
  - Cpp
id: DIC6
---
# Tutorial Belajar C++ Part 10: Fungsi Perintah cin dalam Bahasa C++

21 Oct 20 

Setelah selesai mempelajari [cara kerja dari perintah cout](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-fungsi-perintah-cout-dalam-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 9: Fungsi Perintah cout dalam Bahasa C++") dalam tutorial sebelumnya, kali ini kita akan lanjut membahas fungsi perintah cin dalam bahasa pemrograman C++

---

### Fungsi Perintah cin C++

Perintah **cin** adalah perintah dasar C++ untuk proses input atau menerima data masukan dari user.

Dengan menggunakan perintah **cin** (di eja sebagai "see-in"), kita bisa membuat program yang lebih interaktif, yakni meminta data dari user / pengguna. Data ini bisa disimpan ke dalam variabel dan diolah lebih lanjut untuk kemudian ditampilkan kembali. Kata **cin** sendiri merupakan singkatan dari **console in**.

Format dasar perintah cin adalah sebagai berikut:

```Cpp
cin >> nama_variabel;
```

Berbeda dengan perintah **cout**, untuk perintah **cin** kita menggunakan tanda kurung siku kanan dua kali, atau tanda lebih besar dua kali, yakni karakter `>>`, kemudian diikuti dengan nama variabel yang akan menampung nilai inputan tersebut.

---

### Contoh Kode Program cin C++

Mari kita liat contoh praktek penggunaan perintah **cin**:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int harga;
 
  cout << "Masukkan harga buku: ";
  cin  >> harga;
 
  cout << "Harga buku C++ adalah: "<< harga << endl;
  return 0;
}
```

Di baris 7, saya mendeklarasikan variabel **harga** dengan tipe data **int**. Ini berarti variabel **harga** bisa diisi dengan angka bulat seperti 1, 4, atau 10000.

Kemudian di baris 9 terdapat perintah **cout** yang akan menampilkan teks "Masukkan harga buku:". Ini adalah instruksi kepada user aplikasi untuk menginput sesuatu.

Perintah **cin >> harga** di baris 10 akan menyebabkan layar console atau cmd berhenti sejenak menunggu user menginput angka. Ketika user mengetik angka dan menekan tombol Enter, maka nilai tersebut akan ditampung ke dalam variabel **harga**.

Terakhir, isi variabel harga saya tampilkan kembali dengan perintah **cout** di baris 12. Silahkan tes jalankan kode program diatas:

[![Contoh Kode Program Penggunaan Perintah cin bahasa C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Penggunaan-Perintah-cin-bahasa-C-1.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Penggunaan-Perintah-cin-bahasa-C-1.png)

Yang juga harus menjadi catatan, jika karakter yang diinput bukan angka, bahasa C++ akan mengkonversi karakter tersebut.

Misalnya diinput angka 2500.25 (pecahan), yang akan di ambil hanya angka 2500 saja. Atau jika diinput teks, akan ditampilkan sebagai 0. Ini karena variabel **harga** bertipe integer sehingga hanya bisa menampung angka bulat.

Hasil proses input yang tersimpan di dalam variabel bisa diolah lebih lanjut, misalnya ditambah dengan angka lain seperti contoh berikut:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int harga;
 
  cout << "Masukkan harga buku: ";
  cin  >> harga;
 
  cout << "Harga buku C++ setelah pajak: "<< (harga + 100) << endl;
  return 0;
}
```

Hasil kode program:

```
Masukkan harga buku: 120000
Harga buku C++ setelah pajak: 120100
```

Ketika ditampilkan di baris 12, saya menambah isi variabel harga dengan angka 100. Maka hasil yang tampil juga akan ditambah 100.

---

### Menginput Banyak Data Dengan cout

Jika kita ingin menginput lebih dari 1 data, cukup siapkan variabel untuk menampung setiap nilai inputan tersebut:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  string nama;
  int umur;
 
  cout << "Masukkan nama: ";
  cin  >> nama;
 
  cout << "Masukkan umur: ";
  cin  >> umur;
 
  cout << "\n";
 
  cout << "Selamat Belajar C++ " << nama << ", Semangat!!" << endl;
  cout << "Usia anda saat ini " << umur << " tahun" << endl;
  return 0;
}
```

Dalam kode program ini saya meminta user untuk menginput 2 data: **nama** dan **umur**. Karena nama berisi teks, maka tipe datanya adalah **string** seperti di baris 7. Berikut hasil kode program di atas:

[![Contoh Kode Program Penggunaan Perintah cin bahasa C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Penggunaan-Perintah-cin-bahasa-C-2.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Penggunaan-Perintah-cin-bahasa-C-2.png)

Tidak ada masalah, nilai **nama** dan **umur** berhasil di input dan ditampilkan kembali.

Namun sebenarnya ada sedikit masalah terkait proses input nama. Jika kita input nama yang mengandung spasi, hasilnya tidak sesuai dengan keinginan:

[![Masalah pada proses input string cin pada C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Masalah-pada-proses-input-string-cin-pada-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Masalah-pada-proses-input-string-cin-pada-C.png)

Sesaat setelah menginput nama "Lisa Lestari Pertiwi" dan menekan enter, program tidak lagi berhenti di inputan umur, tapi langsung menampilkan hasilnya. Nama "Lisa Lestari Pertiwi" hanya ditampilkan sebagai "Lisa" saja, sedangkan nilai umur menjadi 0.

Masalah ini terjadi karena keterbatasan perintah **cin** ketika memproses spasi. Sebagai solusi, kita bisa ganti perintah **cin** menjadi function **getline()**.

---

### Menginput Data String Dengan Function getline()

Dalam bahasa C++, perintah cin tidak bisa memproses nilai inputan teks yang mengandung spasi. Untungnya terdapat solusi praktis untuk masalah ini, yakni dengan function **getline()**.

Berikut contoh penggunaannya:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  string nama;
  int umur;
 
  cout << "Masukkan nama: ";
  getline(cin,nama);
 
  cout << "Masukkan umur: ";
  cin  >> umur;
 
  cout << "\n";
 
  cout << "Selamat Belajar C++ " << nama << ", Semangat!!" << endl;
  cout << "Usia anda saat ini " << umur << " tahun" << endl;
  return 0;
}
```

[![Contoh Kode Program Penggunaan Perintah getline bahasa C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Penggunaan-Perintah-getline-bahasa-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Penggunaan-Perintah-getline-bahasa-C.png)

Perbedaan dengan kode sebelumnya ada di baris 11. Sekarang saya mengganti perintah **cin >> nama** menjadi **getline(cin,nama)**. Dengan perubahan ini, inputan **nama** sudah bisa menerima spasi.

Perintah **getline()** adalah sebuah **function**. Penjelasan tentang apa itu function akan kita bahas di tutorial tersendiri. Tapi seperti yang terlihat, penulisan function **getline()** tidak terlalu rumit.

Di dalam tanda kurung kita cukup menulis "**cin**", lalu tanda koma dan diikuti dengan nama variabel yang akan menampung nilai input, yakni variabel "**nama"** (tanpa tanda kutip). Jika nantinya butuh menginput **alamat**, maka perintahnya menjadi **getline(cin,alamat)**, tentunya setelah mendeklarasikan variabel **alamat** terlebih dahulu.

---

Dalam tutorial kali ini kita telah membahas cara penggunaan perintah cin dalam bahasa pemrograman C++. Penggunaannya cukup sederhana, terlebih jika dibandingkan proses input dalam bahasa C atau Java yang lebih kompleks. Sedikit catatan adalah, jika kita ingin menginput teks dengan spasi, tukar perintah **cin** dengan **getline()**.

Berikutnya tutorial bahasa C++ Duniailkom akan masuk ke sesi pembahasan tentang [Jenis-jenis Tipe Data](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-jenis-jenis-tipe-data-dalam-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 11: Jenis-jenis Tipe Data dalam Bahasa C++").