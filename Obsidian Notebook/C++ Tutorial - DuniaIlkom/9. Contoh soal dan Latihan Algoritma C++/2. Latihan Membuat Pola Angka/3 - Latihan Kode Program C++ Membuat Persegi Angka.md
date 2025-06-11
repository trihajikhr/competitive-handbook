---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Latihan Kode Program C++ Membuat Persegi Angka
sumber: duniailkom
date_learned: 2025-06-10T19:16:00
tags:
  - basic
---
Link Sumber: [Latihan Kode Program C++ Membuat Persegi Angka](https://www.duniailkom.com/latihan-kode-program-cpp-membuat-persegi-angka/)

---
## Hasil Latihan:
Kode program soal 1:

```cpp
#include<iostream>
using namespace std;

int main() {
    cout << "Input besar persegi: ";
    int n; cin >> n;

    cout << "\n";
    for(int i=1; i<=n; i++){
        for(int j=0; j<n; j++){
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
    cout << "Input besar persegi: ";
    int n; cin >> n;

    cout << "\n";
    for(int i=0; i<n; i++){
        for(int j=1; j<=n; j++){
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
```

Kode program soal 3:

```cpp
#include<iostream>
#include<iomanip>
using namespace std;

int main() {
    cout << "Input besar persegi: ";
    int n; cin >> n;

    int num=1;
    cout << "\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << setw(3) << num++ << " ";
        }
        cout << "\n";
    }
    return 0;
}
```

# Latihan Kode Program C++: Membuat Persegi Angka
Contoh soal membuat persegi angka dalam bahasa C++ cukup sering ditemui. Latihan ini menguji pemahaman logika dasar serta konsep perulangan bersarang (_nested loop_).

---
## Soal Persegi Angka

Buatlah kode program C++ untuk menampilkan gambar persegi dalam bentuk susunan angka. Agar lebih bervariasi, kita akan buat dalam 3 bentuk angka. Kode program butuh satu inputan yang dipakai untuk menentukan besar persegi.

Berikut variasi deret persegi angka pertama (soal 1):

```
Input besar persegi: 5

1 1 1 1 1
2 2 2 2 2
3 3 3 3 3
4 4 4 4 4
5 5 5 5 5
```

Berikut variasi deret persegi angka kedua (soal 2):

```
Input besar persegi: 5

1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5
```

Berikut variasi deret persegi angka ketiga (soal 3):

```
Input besar persegi: 7

  1   2   3   4   5   6   7
  8   9  10  11  12  13  14
 15  16  17  18  19  20  21
 22  23  24  25  26  27  28
 29  30  31  32  33  34  35
 36  37  38  39  40  41  42
 43  44  45  46  47  48  49
```

Variasi angka di setiap bentuk persegi sebenarnya hanya perlu sedikit modifikasi. Ini sangat pas untuk menguji logika bagaimana cara menampilkan setiap angka.

---

## Tips Membuat persegi Angka

Soal ini melatih pemahaman terkait **perulangan bersarang (nested loop)** serta logika dasar programming. Berikut tutorial pendahuluan yang bisa diikuti:

- [[Part 7 Pengertian Variabel dalam Bahasa C++]]
- [[Part 11 Jenis-jenis Tipe Data dalam Bahasa C++]]
- [[Part 32 Perulangan FOR Bahasa C++]]
- [[2 - Latihan Kode Program C++ Persegi Panjang Bintang]]
- [[2 - Latihan Kode Program C++ Membuat Segitiga Angka Terbalik]]

Kita perlu perulangan bersarang atau nested loop untuk memecahkan soal ini. Perulangan luar (outer loop) dipakai untuk menentukan tinggi persegi, serta perulangan dalam (inner loop) untuk membuat lebar persegi.

Jika anda sudah bisa memahami kode program pembuatan segitiga angka, tidak akan kesulitan dalam membuat deret persegi angka ini.

---

## Kode Program C++ Membuat Persegi Angka (1)

Pada soal pertama, deret angka dibuat bersambung pada setiap baris, akan tetapi di baris tersebut angka yang tampil tetap sama.  Berikut salah satu solusi untuk membuatnya:

```cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "##  Program C++ Persegi Angka ##" << endl;
  cout << "================================" << endl;
  cout << endl;
 
  int besar_persegi,i,j;
 
  cout << "Input besar persegi: ";
  cin >> besar_persegi;
 
  cout << endl;
 
  for(i=1; i<=besar_persegi; i++) {
    for(j=1; j<=besar_persegi; j++) {
      cout << i << " ";    }
    cout << endl;
  }
 
  return 0;
}
```

Hasil kode program:

![[3 - Latihan Kode Program C++ Membuat Persegi Angka-1.png]]

Kode program ini meminta satu inputan yang disimpan ke dalam variabel **besar_persegi**. Variabel inilah yang menjadi penentu kondisi akhir dari perulangan for.

Proses menampilkan deret angka dilakukan oleh perulangan for di baris 18 – 23. Perulangan luar, yakni dengan variabel counter **i** dipakai untuk membuat tinggi persegi. Ini dimulai dari `i = 1` hingga `i <= besar_persegi`.

Jika pada saat proses input nilai `besar_persegi` berisi angka 8, maka perulangan luar akan dijalankan sebanyak 8 kali.

Dalam setiap iterasi, jalankan perulangan dalam serta sebuah perintah `cout << endl` di baris 22. Perintah `endl` dipakai untuk proses pindah baris. Alternatif lain bisa juga menggunakan perintah `cout << "\n"`.

Perulangan dalam dengan variabel counter **j** dipakai untuk membuat deret. Dalam setiap iterasi, jalankan perintah `cout << i <<" "`. Tanda spasi setelah variabel **i** dipakai agar angka tidak berdempet satu sama lain.

---

## Kode Program C++ Membuat Persegi Angka (2)

Pada soal kedua, deret angka akan berulang di setiap baris. Untuk membuatnya kita perlu memodifikasi sedikit angka yang ditampilkan:

```cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "##  Program C++ Persegi Angka  ##" << endl;
  cout << "=================================" << endl;
  cout << endl;
 
  int besar_persegi,i,j;
 
  cout << "Input besar persegi: ";
  cin >> besar_persegi;
 
  cout << endl;
 
  for(i=1; i<=besar_persegi; i++) {
    for(j=1; j<=besar_persegi; j++) {
      cout << j << " ";
    }
    cout << endl;
  }
 
  return 0;
}
```

Hasil kode program:

![[3 - Latihan Kode Program C++ Membuat Persegi Angka-2.png]]

Bisakah anda menebak letak perbedaan kode program ini dengan kode kita sebelumnya? Yup, hanya 1 karakter saja, yakni perintah `cout << j <<" "` di baris 20. Sebelumnya yang ditampilkan adalah variabel **i**, sekarang cukup diganti menjadi variabel **j**.

---

## Kode Program C++ Membuat Persegi Angka (3)

Untuk soal ketiga, deret angka bersambung dari angka pertama hingga angka terakhir. Berikut kode yang diperlukan:

```cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "##  Program C++ Persegi Angka  ##" << endl;
  cout << "=================================" << endl;
  cout << endl;
 
  int besar_persegi,i,j,k;
 
  cout << "Input besar persegi: ";
  cin >> besar_persegi;
 
  cout << endl;
 
  for(i=1;i<=besar_persegi;i++) {
    for(j=1;j<=besar_persegi;j++) {
      k++;
      cout << k << " ";
    }
    cout << endl;
  }
 
  return 0;
}
```

Hasil kode program:

![[3 - Latihan Kode Program C++ Membuat Persegi Angka-3.png]]

Modifikasi dari kode sebelumnya berupa penambahan satu variabel baru, yakni **k**.

Variabel **k** akan dinaikkan (di-increment) dalam inner loop dengan perintah **k++** di baris 20. Setelah itu tampilkan dengan perintah `cout << k <<" "`. Hasilnya, isi variabel **k** akan selalu bersambung dalam setiap iterasi.

Sebagai tambahan, bentuk persegi ini sedikit kurang rapi karena saat sampai ke angka yang terdiri dari 2 digit, besar persegi terdorong jauh ke kanan.

Agar tampilan persegi lebih rapi, kita bisa minta set lebar setiap angka menggunakan perintah **setw()** bawaan header `#include <iomanip>`. Berikut kode program hasil modifikasi ini:

```cpp
#include <iostream>
#include <iomanip>
 
using namespace std;
 
int main()
{
  cout << "##  Program C++ Deret Angka Persegi  ##" << endl;
  cout << "=======================================" << endl;
  cout << endl;
 
  int besar_persegi,i,j,k;
 
  cout << "Input besar persegi: ";
  cin >> besar_persegi;
 
  cout << endl;
 
  for(i=1; i<=besar_persegi; i++) {
    for(j=1; j<=besar_persegi; j++) {
      k++;
      cout << setw(3) << k << " ";
    }
    cout << endl;
  }
 
  return 0;
}
```

Maka outputnya adalah sebagai berikut:

![[3 - Latihan Kode Program C++ Membuat Persegi Angka-4.png]]

Perintah `cout << setw(3) << k << " "` di baris 22 dipakai untuk men-set lebar setiap angka sebesar 3 karakter. Hasilnya, tampilan persegi tetap rapi dari angka 1 hingga 49. Syarat lain, header `#include <iomanip>` harus ditambah di baris 2 karena diperlukan untuk perintah **setw()**.

---

Demikian contoh kode program membuat persegi angka dalam bahasa C++. Semoga bisa bermanfaat.