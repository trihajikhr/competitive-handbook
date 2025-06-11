---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Latihan Kode Program C++ Membuat Segitiga Angka Terbalik
sumber: duniailkom
date_learned: 2025-06-10T18:58:00
tags:
  - basic
---
Link Sumber: [Latihan Kode Program C++ Membuat Segitiga Angka Terbalik](https://www.duniailkom.com/latihan-kode-program-cpp-membuat-segitiga-angka-terbalik/)

---
## Hasil Latihan:
Kode program soal 1:

```cpp
#include<iostream>
using namespace std;

int main() {
    cout << "## Program Bahasa C++ Segitiga Angka Terbalik ##\n";
    cout << "================================================\n";
    cout << "\nInput tinggi segitiga: ";
    int n; cin >> n;

    for(int i=1;i<=n;i++){
        for(int j=0;j<n-i;j++){
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
```

Kode program soal 2:

```cpp
#include<iostream>
using namespace std;

int main() {
    cout << "## Program Bahasa C++ Segitiga Angka Terbalik ##\n";
    cout << "================================================\n";
    cout << "\nInput tinggi segitiga: ";
    int n; cin >> n;

    for(int i=0;i<n;i++){
        for(int j=1;j<=n-i;j++){
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
```

Kode program soal 2:

```cpp
#include<iostream>
#include<iomanip>
using namespace std;

int main() {
    cout << "## Program Bahasa C++ Segitiga Angka Terbalik ##\n";
    cout << "================================================\n";
    cout << "\nInput tinggi segitiga: ";
    int n; cin >> n;

    int num=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i; j++){
            cout << setw(3) << num++ << " ";
        }
        cout << "\n";
    }
    return 0;
}
```

# Latihan Kode Program C++: Membuat Segitiga Angka Terbalik

Latihan kode program bahasa C++ kali ini akan membahas cara membuat segitiga angka terbalik. Soal ini menjadi salah satu materi algoritma yang cukup sering ditemui, karena menguji pemahaman logika serta konsep perulangan bersarang (_nested loop_).

Segitiga angka terbalik punya banyak variasi, kita akan bahas beberapa diantaranya.

---

## Soal Segitiga Angka Terbalik

Buatlah kode program bahasa C++ untuk menampilkan gambar segitiga terbalik dalam bentuk susunan angka. Agar lebih bervariasi, kita akan buat dalam 3 variasi. Kode program butuh satu inputan yang dipakai untuk menentukan tinggi segitiga.

Berikut variasi deret segitiga angka pertama (soal 1):

```
## Program Bahasa C++ Segitiga Angka Terbalik ##
================================================

Input tinggi segitiga: 8
1 1 1 1 1 1 1 
2 2 2 2 2 2
3 3 3 3 3
4 4 4 4
5 5 5
6 6
7
```

Berikut variasi deret segitiga angka kedua (soal 2):

```
## Program Bahasa C++ Segitiga Angka Terbalik ##
================================================

Input tinggi segitiga: 8
1 2 3 4 5 6 7 8 
1 2 3 4 5 6 7 
1 2 3 4 5 6
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1
```

Berikut variasi deret segitiga angka kedua (soal 3):

```
## Program Bahasa C++ Segitiga Angka Terbalik ##
================================================

Input tinggi segitiga: 8
  1   2   3   4   5   6   7   8 
  9  10  11  12  13  14  15
 16  17  18  19  20  21
 22  23  24  25  26
 27  28  29  30
 31  32  33
 34  35
 36
```

Variasi angka di setiap bentuk segitiga sebenarnya hanya perlu sedikit modifikasi. Ini sangat pas untuk menguji logika bagaimana cara menampilkan setiap angka.

---

## Tips Membuat Segitiga Angka Terbalik

Soal ini melatih pemahaman terkait **perulangan bersarang (nested loop)** serta logika dasar programming. Berikut tutorial pendahuluan yang bisa diikuti:

- [[Part 7 Pengertian Variabel dalam Bahasa C++]]
- [[Part 13 Tipe Data Integer Bahasa C++]]
- [[Part 32 Perulangan FOR Bahasa C++]]
- [[1 - Latihan Kode Program C++ Membuat Segitiga Angka]]

Kita perlu perulangan bersarang atau _nested loop_ untuk memecahkan soal ini. Perulangan luar (outer loop) dipakai untuk menentukan tinggi segitiga, serta perulangan dalam (inner loop) untuk membuat bentuk segitiga.

Jika anda sudah bisa memahami kode program pembuatan segitiga bintang terbalik, tidak akan kesulitan dalam membuat deret segitiga angka ini.

---

## Kode Program Bahasa C++ Segitiga Angka Terbalik (1)

Pada soal pertama, deret angka yang dibuat bersambung pada setiap baris, akan tetapi di baris tersebut angka yang tampil tetap sama. Berikut salah satu solusi untuk membuatnya:

```cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "##  Program C++ Segitiga Angka Terbalik  ##" << endl;
  cout << "===========================================" << endl;
  cout << endl;
 
  int tinggi_segitiga,i,j;
 
  cout << "Input tinggi segitiga: ";
  cin >> tinggi_segitiga;
 
  cout << endl;
 
  for(i = 1; i <= tinggi_segitiga; i++) {
    for(j = 0; j <= tinggi_segitiga-i; j++) {
      cout << i << " ";
    }
    cout << endl;
  }
 
  return 0;
}
```

Hasil kode program:

![[2 - Latihan Kode Program C++ Membuat Segitiga Angka Terbalik-1.png]]

Kode program meminta satu inputan yang disimpan ke dalam variabel **tinggi_segitiga**. Variabel inilah yang menjadi penentu akhir dari perulangan for.

Proses menampilkan deret angka dilakukan oleh perulangan for di baris 18 – 23. Perulangan luar dengan variabel counter **i** dipakai untuk membuat tinggi segitiga. Ini dimulai dari `i = 1` hingga `i <= tinggi_segitiga`.

Jika pada saat proses input nilai `tinggi_segitiga` berisi angka 7, maka perulangan luar akan dijalankan sebanyak 7 kali.

Dalam setiap iterasi, jalankan perulangan dalam serta sebuah perintah `cout << endl` di baris 22. Perintah ini dipakai untuk proses pindah baris.

Perulangan dalam dengan variabel counter **j** dipakai untuk membuat deret. Karena kita membuat segitiga terbalik, maka jumlah perulangan harus dibuat menurun mulai dari `tinggi_segitiga` yang secara bertahap terus dikurangi.

Jika `tinggi_segitiga` berisi angka 5, maka perulangan j haruslah mulai dari 5, 4, 3, 2, 1. Proses membuat perulangan menurun ini dilakukan mulai dari `j = 0` hingga `j <= tinggi_segitiga-i`.

Dalam setiap iterasi, jalankan perintah `cout << i << " "`. Tanda spasi setelah variabel **i** dipakai agar angka tidak berdempet satu sama lain.

---

## Kode Program Bahasa C++ Segitiga Angka Terbalik (2)

Pada soal kedua, deret angka akan berulang di setiap baris. Untuk membuatnya kita perlu memodifikasi sedikit angka yang ditampilkan:

```cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "##  Program C++ Segitiga Angka Terbalik  ##" << endl;
  cout << "===========================================" << endl;
  cout << endl;
 
  int tinggi_segitiga,i,j;
 
  cout << "Input tinggi segitiga: ";
  cin >> tinggi_segitiga;
 
  cout << endl;
 
  for(i = 1; i <= tinggi_segitiga; i++) {
    for(j = 0; j <= tinggi_segitiga-i; j++) {
      cout << j + 1 << " ";
    }
    cout << endl;
  }
 
  return 0;
}
```

Hasil kode program:

![[2 - Latihan Kode Program C++ Membuat Segitiga Angka Terbalik-2.png]]

Bisakah anda tebak letak perbedaan kode program ini dengan kode kita sebelumnya? Yup, hanya beberapa karakter saja, yakni perintah `cout << j + 1 << " "` di baris 20. Sebelumnya yang ditampilkan adalah variabel **i**, sekarang cukup diganti menjadi variabel **j+1**.

Tambahan angka 1 di bagian `j+1` bertujuan agar tampil angka 1, 2, 3 dst. Jika tidak ditambah, akan mulai dari 0 karena kondisi awal perulangan j ada di `j = 0`.

---

## Kode Program Bahasa C++ Segitiga Angka Terbalik (3)

Untuk soal ketiga, deret angka bersambung dari angka pertama hingga angka terakhir. Berikut kode yang diperlukan:

```cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "##  Program C++ Segitiga Angka Terbalik  ##" << endl;
  cout << "===========================================" << endl;
  cout << endl;
 
  int tinggi_segitiga,i,j,k;
 
  cout << "Input tinggi segitiga: ";
  cin >> tinggi_segitiga;
 
  cout << endl;
 
  for(i = 1; i <= tinggi_segitiga; i++) {
    for(j = 0; j <= tinggi_segitiga-i; j++) {
      k++;
      cout << k << " ";
    }
    cout << endl;
  }
 
  return 0;
}
```

Hasil kode program:

![[2 - Latihan Kode Program C++ Membuat Segitiga Angka Terbalik-3.png]]

Modifikasi dari kode sebelumnya berupa penambahan satu variabel baru, yakni **k**.

Variabel **k** akan dinaikkan (di-increment) dalam inner loop dengan perintah **k++** di baris 20. Setelah itu tampilkan dengan perintah `cout << k << " "`. Hasilnya, isi variabel k akan selalu bersambung dalam setiap iterasi.

Sebagai tambahan, bentuk persegi ini sedikit kurang rapi karena saat sampai ke angka yang terdiri dari 2 digit, besar persegi terdorong jauh ke kanan.

Agar tampilan persegi lebih rapi, kita bisa minta set lebar setiap angka menggunakan perintah **setw()** bawaan header `#include <iomanip>`. Berikut kode program hasil modifikasi ini:

```cpp
#include <iostream>
#include <iomanip>
 
using namespace std;
 
int main()
{
  cout << "##  Program C++ Segitiga Angka Terbalik  ##" << endl;
  cout << "===========================================" << endl;
  cout << endl;
 
  int tinggi_segitiga,i,j,k;
 
  cout << "Input tinggi segitiga: ";
  cin >> tinggi_segitiga;
 
  cout << endl;
 
  for(i = 1; i <= tinggi_segitiga; i++) {
    for(j = 0; j <= tinggi_segitiga-i; j++) {
      k++;
      cout << setw(3) << k << " ";
    }
    cout << endl;
  }
 
  return 0;
}
```

Sehingga hasilnya menjadi seperti ini:

![[2 - Latihan Kode Program C++ Membuat Segitiga Angka Terbalik-4.png]]

Perintah `cout << setw(3) << k << " "` di baris 22 dipakai untuk men-set lebar setiap angka sebesar 3 karakter. Hasilnya, tampilan persegi tetap rapi dari angka 1 hingga 28. Syarat lain, header `#include <iomanip>` harus ditambah di baris 2 karena diperlukan untuk perintah **setw()**.

---

Demikian contoh kode program membuat segitiga angka terbalik dalam bahasa C++. Semoga bisa bermanfaat.