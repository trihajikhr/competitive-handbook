---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Latihan Kode Program C++ Membuat Segitiga Angka
sumber: duniailkom
date_learned: 2025-06-10T18:48:00
tags:
  - basic
---
Link Sumber: [Latihan Kode Program C++ Membuat Segitiga Angka](https://www.duniailkom.com/latihan-kode-program-cpp-membuat-deret-angka-segitiga/)

---
## Hasil Latihan:
Kode program jawaban 1:

```cpp
#include<iostream>
using namespace std;

int main() {
    cout << "Input tinggi segitiga: ";
    int n; cin >> n;

    for(int i=0;i<=n;i++){
        for(int j=0;j<i; j++){
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
```

Kode program jawaban 2:

```cpp
#include<iostream>
using namespace std;

int main() {
    cout << "Input tinggi segitiga: ";
    int n; cin >> n;

    for(int i=0;i<=n;i++){
        for(int j=1;j<=i; j++){
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
```
# Latihan Kode Program C++: Membuat Segitiga Angka

Latihan membuat segitiga angka menjadi salah satu materi algoritma yang cukup sering ditemui. Salah satunya karena perlu pemahaman logika serta konsep perulangan bersarang (_nested loop_) serta logika matematika.

Segitiga angka punya banyak variasi, kali ini kita akan bahas dalam bentuk yang sederhana saja.

---

## Soal Segitiga Angka

Buatlah kode program C++ untuk menampilkan gambar segitiga dalam bentuk susunan angka. Agar lebih bervariasi, kita akan buat dalam 3 bentuk angka. Kode program butuh satu inputan yang dipakai untuk menentukan tinggi segitiga.

Berikut variasi deret segitiga angka pertama (soal 1):

```
Input tinggi segitiga: 7

1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
6 6 6 6 6 6
7 7 7 7 7 7 7
```

Berikut variasi deret segitiga angka kedua (soal 2):

```
Input tinggi segitiga: 7

1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
1 2 3 4 5 6
1 2 3 4 5 6 7
```

Berikut variasi deret segitiga angka kedua (soal 3):

```
Input tinggi segitiga: 7

1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
16 17 18 19 20 21
22 23 24 25 26 27 28
```

Variasi angka di setiap bentuk segitiga sebenarnya hanya perlu sedikit modifikasi. Ini sangat pas untuk menguji logika bagaimana cara menampilkan setiap angka.

---

## Tips Membuat Segitiga Angka

Soal ini melatih pemahaman terkait **perulangan bersarang (nested loop)** serta logika dasar programming. Berikut tutorial pendahuluan yang bisa diikuti:

- [[Part 7 Pengertian Variabel dalam Bahasa C++]]
- [[Part 11 Jenis-jenis Tipe Data dalam Bahasa C++]]
- [[Part 32 Perulangan FOR Bahasa C++]]
- [[3 - Latihan Kode Program C++ Segitiga Bintang]]

Kita perlu perulangan bersarang atau nested loop untuk memecahkan soal ini. Perulangan luar (outer loop) dipakai untuk menentukan tinggi segitiga, serta perulangan dalam (inner loop) untuk membuat bentuk segitiga.

Jika anda sudah bisa memahami kode program pembuatan segitiga bintang, tidak akan kesulitan dalam membuat deret segitiga angka ini.

---

## Kode Program C++ Membuat Segitiga Angka (1)

Pada soal pertama, deret angka yang dibuat bersambung pada setiap baris, akan tetapi di baris tersebut angka yang tampil tetap sama.  Berikut salah satu solusi untuk membuatnya:

```cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "##  Program C++ Segitiga Angka  ##" << endl;
  cout << "==================================" << endl;
  cout << endl;
 
  int tinggi_segitiga,i,j;
 
  cout << "Input tinggi segitiga: ";
  cin >> tinggi_segitiga;
 
  cout << endl;
 
  for(i=1;i<=tinggi_segitiga;i++) {
    for(j=1;j<=i;j++) {
      cout << i <<" ";
    }
    cout << endl;
  }
 
  return 0;
}
```

Hasil kode program:

![[1 - Latihan Kode Program C++ Membuat Segitiga Angka-1.png]]

Kode program ini meminta satu inputan yang disimpan ke dalam variabel **tinggi_segitiga**. Variabel inilah yang menjadi penentu kondisi akhir dari perulangan for.

Proses menampilkan deret angka dilakukan oleh perulangan for di baris 18 – 23. Perulangan luar, yakni dengan variabel counter **i** dipakai untuk membuat tinggi segitiga. Ini dimulai dari `i = 1` hingga `i <= tinggi_segitiga`.

Jika pada saat proses input nilai `tinggi_segitiga` berisi angka 9, maka perulangan luar akan dijalankan sebanyak 9 kali.

Dalam setiap iterasi, jalankan perulangan dalam serta sebuah perintah `cout << endl` di baris 22. Perintah `endl` dipakai untuk proses pindah baris. Alternatif lain bisa juga menggunakan perintah `cout << "\n"`.

Perulangan dalam dengan variabel counter **j** dipakai untuk membuat deret. Caranya, cukup tampilkan isi variabel **i** yang akan menaik dari 1, 2, 3, dst hingga mencapai `tinggi_segitiga`.

Dalam setiap iterasi, jalankan perintah `cout << i <<" "`. Tanda spasi setelah variabel **i** dipakai agar angka tidak berdempet satu sama lain.

---

## Kode Program C++ Membuat Segitiga Angka (2)

Pada soal kedua, deret angka akan berulang di setiap baris. Untuk membuatnya kita perlu memodifikasi sedikit angka yang ditampilkan:

```cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "##  Program C++ Segitiga Angka  ##" << endl;
  cout << "==================================" << endl;
  cout << endl;
 
  int tinggi_segitiga,i,j;
 
  cout << "Input tinggi segitiga: ";
  cin >> tinggi_segitiga;
 
  cout << endl;
 
  for(i=1;i<=tinggi_segitiga;i++) {
    for(j=1;j<=i;j++) {
      cout << j <<" ";
    }
    cout << endl;
  }
 
  return 0;
}
```

Hasil kode program:

![[1 - Latihan Kode Program C++ Membuat Segitiga Angka-2.png]]

Bisakah anda menebak letak perbedaan kode program ini dengan kode kita sebelumnya? Yup, hanya 1 karakter saja, yakni perintah `cout << j <<" "` di baris 20. Sebelumnya yang ditampilkan adalah variabel **i**, sekarang cukup diganti menjadi variabel **j**.

---

## Kode Program C++ Membuat Segitiga Angka (3)

Untuk soal ketiga, deret angka bersambung dari angka pertama hingga angka terakhir. Berikut kode yang diperlukan:

```cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "##  Program C++ Segitiga Angka  ##" << endl;
  cout << "==================================" << endl;
  cout << endl;
 
  int tinggi_segitiga,i,j,k;
 
  cout << "Input tinggi segitiga: ";
  cin >> tinggi_segitiga;
 
  cout << endl;
 
  for(i=1;i<=tinggi_segitiga;i++) {
    for(j=1;j<=i;j++) {
      k++;
      cout << k <<" ";
    }
    cout << endl;
  }
 
  return 0;
}
```

Hasil kode program:

![[1 - Latihan Kode Program C++ Membuat Segitiga Angka-3.png]]

Modifikasi dari kode sebelumnya berupa penambahan satu variabel baru, yakni **k**.

Variabel **k** akan dinaikkan (di-increment) dalam inner loop dengan perintah **k++** di baris 20. Setelah itu tampilkan dengan perintah `cout << k <<" "`. Hasilnya, isi variabel k akan selalu bersambung dalam setiap iterasi.

Sebagai tambahan, bentuk segitiga ini sedikit kurang rapi karena saat sampai ke angka yang terdiri dari 2 digit, besar segitiga terdorong jauh ke kanan.

Agar tampilan segitiga lebih rapi, kita bisa minta set lebar setiap angka menggunakan perintah **setw()** bawaan header `#include <iomanip>`. Berikut kode program hasil modifikasi ini:

```cpp
#include <iostream>
#include <iomanip>
 
using namespace std;
 
int main()
{
  cout << "##  Program C++ Segitiga Angka  ##" << endl;
  cout << "==================================" << endl;
  cout << endl;
 
  int tinggi_segitiga,i,j,k;
 
  cout << "Input tinggi segitiga: ";
  cin >> tinggi_segitiga;
 
  cout << endl;
 
  for(i=1;i<=tinggi_segitiga;i++) {
    for(j=1;j<=i;j++) {
      k++;
      cout << setw(3) << k << " ";
    }
    cout << endl;
  }
 
  return 0;
}
```

Output:

![[1 - Latihan Kode Program C++ Membuat Segitiga Angka-4.png]]


Perintah `cout << setw(3) << k << " "` di baris 22 dipakai untuk men-set lebar setiap angka sebesar 3 karakter. Hasilnya, tampilan segitiga tetap rapi dari angka 1 hingga 45. Syarat lain, header `#include <iomanip>` harus ditambah di baris 2 karena diperlukan untuk perintah **setw()**.

---

Demikian contoh kode program membuat segitiga angka dalam bahasa C++. Semoga bisa bermanfaat.