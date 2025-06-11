---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-09-27T21:25:00
total_study: 1
tags:
  - Cpp
id: DIF8
---
# Tutorial Belajar C++ Part 35: Fungsi dan Pengertian Perintah BREAK C++

01 Nov 20 


Melanjutkan tutorial belajar bahasa pemrograman C++ di Duniailkom, kali ini kita akan bahas Fungsi dan Pengertian Perintah BREAK. Perintah **BREAK** masih berhubungan dengan perulangan (loop) FOR, WHILE dan DO WHILE yang baru saja di bahas.

---

### Pengertian Perintah BREAK dalam Bahasa C++

Ketika membuat perulangan, kadang kita ingin keluar dari perulangan sebelum waktunya.

Sebagai contoh misalkan kita sedang membuat kode program untuk mencari sebuah nilai dalam array yang terdiri dari 100 element. Jika ternyata nilai sudah ditemukan di posisi ke-43, maka sisa perulangan tidak diperlukan lagi. Akan lebih efisien jika perulangan tersebut langsung berhenti pada saat itu juga, dan inilah fungsi dari perintah **BREAK**.

Secara sederhana, **BREAK** adalah perintah khusus yang dipakai untuk **memaksa sebuah perulangan berhenti sebelum waktunya**. Perintah break ini bisa dipakai dalam semua jenis perulangan, baik itu FOR, WHILE, maupun DO WHILE.

Berikut format dasar penggunaan perintah BREAK dalam perulangan FOR:

```Cpp
for (start; condition_1; increment) 
{
   // kode program
   // kode program
   if (condition_2) {
     break;
   }
}
```

Dalam contoh ini, jika **condition_2** terpenuhi (bernilai **true**), maka perulangan akan langsung berhenti meskipun belum mencapai kondisi akhir di **condition_1**.

Mari kita bahas dengan contoh kode program.

---

### Contoh Kode Program Perintah BREAK Bahasa C++

Sebelum masuk ke perintah **break**, berikut contoh perulangan FOR bahasa C++ untuk menampilkan daftar penambahan angka:

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

Di sini terdapat kode program dengan perulangan **FOR** untuk membuat daftar penambahan 1 + 1, 2 + 2, dst hingga 10 + 10.

Sekarang saya ingin jika variabel counter i sudah mencapai angka 5, maka hentikan perulangan (**break**). Berikut kode programnya:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int i;
  for (i = 1; i <= 10; i++) {
    cout << i << " + " << i << " = " << (i+i) << endl;
    if (i == 5) {
      break;
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
```

Di dalam perulangan FOR, yakni pada baris 10 terdapat pemeriksaan kondisi **if (i == 5)**. Jika kondisi ini terpenuhi (variabel counter i sudah bernilai 5) maka jalankan perintah **break**. Hasilnya, perulangan langsung berhenti begitu variabel **i** mencapai angka 5.

Sebagai tambahan, posisi pemeriksaan kondisi ini bisa berpengaruh kepada tampilan akhir. Perhatikan kode program berikut:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int i;
  for (i = 1; i <= 10; i++) {
    if (i == 5) {
      break;
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
```

Bisakah anda menjelaskan kenapa perulangan kita berhenti pada angka 4 dan bukan di angka 5 seperti sebelumnya? Padahal kondisi yang dipakai tetap sama, yakni **if (i == 5) { break; }**

Ini terjadi karena perubahan posisi perintah **cout**. Dalam contoh pertama, perintah **cout** ditulis sebelum pemeriksaan kondisi **if (i == 5)**. Ini berarti begitu variabel counter i naik menjadi 5, perintah **cout** akan di proses terlebih dahulu, setelah itu barulah perintah **break** di jalankan.

Sedangkan pada kode program kali ini, ketika variabel **i** sampai ke angka 5, maka langsung **break** tanpa sempat menjalankan perintah **cout**. Ini terjadi karena perintah **cout** ditulis **setelah** pemeriksaan kondisi.

Sebagai penutup, berikut contoh penggunaan perintah **break** pada perulangan **WHILE**:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int i = 1;
  while (i <= 10){
    if (i == 5) {
      break;
    }
    cout << i << " + " << i << " = " << (i+i) << endl;
    i++;
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
```

Saya mengkonversi perulangan FOR sebelumnya menjadi WHILE. Dan karena perintah **cout** juga ditulis setelah perintah **break**, maka penambahan yang tampil hanya sampai 4 saja.

---

Dalam tutorial kali ini kita telah membahas cara penggunaan **perintah BREAK**. Berikutnya akan dilanjutkan dengan membahas [perintah CONTINUE dalam bahasa pemrograman C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-fungsi-dan-pengertian-perintah-continue-c-plus-plus/ "Tutorial Belajar C++ Part 36: Fungsi dan Pengertian Perintah CONTINUE C++").