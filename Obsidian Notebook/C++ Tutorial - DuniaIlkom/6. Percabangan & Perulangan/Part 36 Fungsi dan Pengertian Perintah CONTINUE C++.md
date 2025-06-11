---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-09-27T22:13:00
total_study: 1
tags:
  - Cpp
id: DIF9
---
# Tutorial Belajar C++ Part 36: Fungsi dan Pengertian Perintah CONTINUE C++

01 Nov 20 

Pada tutorial belajar bahasa C++ kali ini kita akan membahas Fungsi dan Pengertian Perintah CONTINUE. **Perintah CONTINUE** dipakai untuk mengatur alur perulangan yang mirip seperti perintah BREAK dalam tutorial sebelumnya.

---

### Pengertian Perintah CONTINUE dalam Bahasa C++

Perintah **CONTINUE** mirip seperti perintah **BREAK**, hanya saja jika dalam perintah break perulangan langsung berhenti, untuk perintah continue perulangan hanya melewati 1 kali proses iterasi saja.

Berikut format dasar penggunaan perintah **CONTINUE** dalam perulangan FOR:

```Cpp
for (start; condition_1; increment) 
{
   // kode program
   // kode program
   if (condition_2) {
     continue;
   }
   // kode program lanjutan
}
```

Sebagai contoh, misalnya kita membuat perulangan 1 sampai 10, lalu terdapat kondisi **if (i = 5) { continue; }**, maka ketika nilai variabel counter i sudah mencapai 5, kode program yang ada di bawah perintah **continue** akan di lewati dan proses perulangan lanjut ke iterasi ke 6.

Penjelasan ini akan lebih mudah dengan praktek contoh kode program.

---

### Contoh Kode Program Perintah CONTINUE Bahasa C++

Sama seperti pada tutorial perintah BREAK, berikut perulangan FOR "normal" tanpa perintah continue:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int i;
  for (i = 1; i <= 10; i++) {
    cout << i << " + " << i << " = " << (i+i) << endl;
  }
 
  return 0;
}
```

Hasil kode program:

```
1 + 1 = 2
2 + 2 = 4
3 + 3 = 6
4 + 4 = 8
5 + 5 = 10
6 + 6 = 12
7 + 7 = 14
8 + 8 = 16
9 + 9 = 18
10 + 10 = 20
```

Di sini saya menggunakan perulangan **FOR** untuk membuat daftar penambahan 1 + 1, 2 + 2, dst hingga 10 + 10.

Sekarang kita akan tambah dengan perintah **CONTINUE**:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int i;
  for (i = 1; i <= 10; i++) {
    if (i == 5) {
      continue;
    }
    cout << i << " + " << i << " = " << (i+i) << endl;
  }
 
  return 0;
}
```

Hasil kode program:

```
1 + 1 = 2
2 + 2 = 4
3 + 3 = 6
4 + 4 = 8
6 + 6 = 12
7 + 7 = 14
8 + 8 = 16
9 + 9 = 18
10 + 10 = 20
```

Di dalam kode program, pada baris 9 terdapat kondisi **if (i == 5) { continue; }**. Kondisi ini akan terpenuhi saat variabel counter **i** berisi angka 5. Hasilnya, perintah **cout** di baris 12 akan dilompati dan perulangan langsung pindah ke iterasi berikutnya, yakni variabel **i** akan berisi angka 6. Dalam tampilan akhir bisa terlihat baris 5 + 5 = 10 tidak ada di daftar penambahan.

Selanjutnya, bisakah anda coba jelaskan kenapa perintah **continue** tidak berefek pada kode program berikut?

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int i;
  for (i = 1; i <= 10; i++) {
    cout << i << " + " << i << " = " << (i+i) << endl;
    if (i == 5) {
      continue;
    }
  }
 
  return 0;
}
```

Hasil kode program:

```
1 + 1 = 2
2 + 2 = 4
3 + 3 = 6
4 + 4 = 8
5 + 5 = 10
6 + 6 = 12
7 + 7 = 14
8 + 8 = 16
9 + 9 = 18
10 + 10 = 20
```

Pertanyaannya, kenapa baris **5 + 5 = 10** masih tampil? padahal saya membuat kondisi **if (i == 5) {continue; }** di baris 10.

Kembali, logika yang sama seperti pada perulangan **BREAK** juga berlaku di sini. Dalam kode di atas, perintah **cout** di tulis **sebelum perintah** **continue**. Akibatnya, meskipun perintah **continue** dijalankan saat **i** bernilai 5 (dan kondisi ini terpenuhi), namun perintah **cout** sudah terlanjur di proses terlebih dahulu.

Ini menjadi catatan penting saat merancang kode program yang melibatkan perintah **continue**, karena posisi peletakan perintah sangat berpengaruh ke hasil akhir.

Sebagai tambahan, berikut contoh kode program perintah continue dalam perulangan **DO WHILE**:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int i = 0;
  do {
    i++;
    if (i == 5) {
      continue;
    }
    cout << i << " + " << i << " = " << (i+i) << endl;
 
  } while (i < 10);
 
  return 0;
}
```

Hasil kode program:

```
1 + 1 = 2
2 + 2 = 4
3 + 3 = 6
4 + 4 = 8
6 + 6 = 12
7 + 7 = 14
8 + 8 = 16
9 + 9 = 18
10 + 10 = 20
```

Ketika membuat perintah CONTINUE dengan perulangan **DO WHILE** dan juga perulangan **WHILE**, posisi peletakan perintah _increment_ sangat berpengaruh.

Contoh kasus, tanpa menjalankan kode program dibawah ini bisakah anda menebak hasilnya?

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int i = 0;
  do {
    if (i == 5) {
      continue;
    }
    cout << i << " + " << i << " = " << (i+i) << endl;
    i++;
  } while (i < 10);
 
  return 0;
}
```

Hasilnya sebuah **infinity loop**!, yakni perulangan yang tidak pernah berakhir.

Ini terjadi karena pada saat variabel **i** berisi angka 5, perulangan akan terus berputar-putar antara baris 9 – 11. Perintah increment **i++** yang ada di baris 13 tidak bisa di eksekusi karena di tulis **setelah perintah** **continue** di baris 10.

Jadi, kata kuncinya adalah: **perhatikan logika program** terutama ketika membuat perulangan WHILE dan DO WHILE yang melibatkan perintah **continue**.

Sekedar catatan, jika anda menjalankan kode diatas, akan tampil hasil berikut:

```
0 + 0 = 0
1 + 1 = 2
2 + 2 = 4
3 + 3 = 6
4 + 4 = 8
```

Setelah itu tampil baris kosong yang sebenarnya berupa _infinity loop_ karena perintah **cout** dan increment **i++** di tulis setelah perintah **continue**.

---

Dalam lanjutan tutorial bahasa C++ di duniailkom kali ini kita telah membahas tentang perintah **CONTINUE**. Tutorial ini menutup seri bahasan struktur kondisi dan perulangan di dalam bahasa C++.

Untuk sesi berikutnya kita akan masuk ke pembahasan mengenai **function**, yang dimulai dengan [Cara Membuat Fungsi (Function) Bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-cara-membuat-fungsi-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 37: Cara Membuat Fungsi (Function) Bahasa C++").