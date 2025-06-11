---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Latihan Kode Program C++ Segitiga Bintang Terbalik
sumber: duniailkom
date_learned: 2025-06-10T18:12:00
tags:
  - basic
---
Link Sumber: [Latihan Kode Program C++ Segitiga Bintang Terbalik](https://www.duniailkom.com/latihan-kode-program-cpp-segitiga-bintang-terbalik/)

---
## Hasil Latihan:
Kode program:

```cpp
#include<iostream>
using namespace std;

int main() {
    cout << "Input tinggi segitiga: ";
    int n; cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout << "* " << " ";
        }
        cout << "\n";
    }
    return 0;
}
```
# Latihan Kode Program C++: Segitiga Bintang Terbalik

Soal membuat segitiga bintang terbalik merupakan modifikasi dari [[3 - Latihan Kode Program C++ Segitiga Bintang]] yang pernah kita bahas sebelumnya. Materi ini menguji pemahaman logika terutama tentang perulangan bersarang (nested loop).

Segitiga bintang sendiri juga banyak variasi lain yang akan dibahas secara terpisah.

---

## Soal Segitiga Bintang Terbalik

Buatlah kode program C++ untuk menampilkan gambar segitiga terbalik dalam bentuk kumpulan tanda bintang (karakter `*`). Kode program butuh satu inputan yang dipakai untuk menentukan tinggi segitiga.

Berikut contoh tampilan akhir yang diinginkan (1) :

```
Input tinggi segitiga: 4
*  *  *  *  
*  *  *
*  *
*
```

Berikut contoh tampilan akhir yang diinginkan (2) :

```
Input tinggi segitiga: 6
*  *  *  *  *  *  
*  *  *  *  *
*  *  *  *
*  *  *
*  *
*
```

---

## Tips Membuat Kode Program Segitiga Bintang Terbalik

Soal ini melatih pemahaman terkait **perulangan bersarang (nested loop)**. Berikut tutorial pendahuluan yang bisa diikuti:

- [[Part 7 Pengertian Variabel dalam Bahasa C++]]
- [[Part 11 Jenis-jenis Tipe Data dalam Bahasa C++]]
- [[Part 32 Perulangan FOR Bahasa C++]]

Kita perlu membuat perulangan bersarang atau nested loop untuk memecahkan soal ini. Perulangan luar (outer loop) dipakai untuk menentukan tinggi segitiga, serta perulangan dalam (inner loop) untuk membuat bentuk segitiga.

Sangat disarankan untuk memahami kode program [[3 - Latihan Kode Program C++ Segitiga Bintang]] terlebih dahulu karena segitiga bintang terbalik ini pada dasarnya adalah modifikasi dari kode program tersebut.

---

## Kode Program C++ Segitiga Bintang Terbalik

Berikut salah satu solusi dari soal membuat segitiga bintang terbalik menggunakan bahasa pemrograman C++:

```cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "##  Program C++ Segitiga Bintang Terbalik  ##" << endl;
  cout << "=============================================" << endl;
  cout << endl;
 
  int tinggi_segitiga,i,j;
 
  cout << "Input tinggi segitiga: ";
  cin >> tinggi_segitiga;
 
  cout << endl;
 
  for(i = 0; i < tinggi_segitiga; i++) {
    for(j = 1; j <= tinggi_segitiga-i; j++) {
      cout << " *";
    }
    cout << endl;
  }
 
  return 0;
}
```

Hasil kode program:

![[4 Latihan Kode Program C++ Segitiga Bintang Terbalik-1.png]]

![[4 Latihan Kode Program C++ Segitiga Bintang Terbalik-2.png]]


Kode program ini meminta satu inputan yang disimpan ke dalam variabel **tinggi_segitiga**. Variabel inilah yang nantinya akan menjadi penentu kondisi akhir dari perulangan for.

Proses menampilkan karakter bintang dilakukan oleh perulangan for di baris 18 – 23. Perulangan luar, yakni dengan variabel counter **i** dipakai untuk membuat tinggi segitiga. Ini dimulai dari `i = 0` hingga `i < tinggi_segitiga`.

Jika pada saat proses input nilai `tinggi_segitiga` berisi angka 6, maka perulangan luar akan dijalankan sebanyak 6 kali.

Dalam setiap iterasi, jalankan perulangan dalam serta sebuah perintah `cout << endl` di baris 22. Perintah `endl` ini dipakai untuk proses pindah baris. Alternatif lain bisa juga menggunakan perintah `cout << "\n"`.

Perbedaan dengan kode program untuk membuat segitiga bintang biasa dengan segitiga bintang terbalik ada di perulangan dalam, yakni for **j**.

Karena kita membuat segitiga terbalik, maka karakter bintang harus dibuat menurun dari `tinggi_segitiga`, lalu secara bertahap dibuat kurang.

Jika `tinggi_segitiga` berisi angka 6, maka perulangan j haruslah mulai dari 6, 5, 4, 3, 2, 1. Proses membuat perulangan menurun ini dilakukan mulai dari `j = 1` hingga `j < tinggi_segitiga-i`.

Dalam setiap iterasi, jalankan perintah `cout << " *"`. Tanda spasi sebelum karakter bintang dipakai agar hasil bintang menjadi lebih rapi.

---

## Segitiga Bintang Terbalik Dengan Perulangan Menurun

Alternatif cara pembuatan lain adalah menggunakan perulangan menurun untuk inner loop. Berikut kode yang dimaksud:

```cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "##  Program C++ Segitiga Bintang Terbalik  ##" << endl;
  cout << "=============================================" << endl;
  cout << endl;
 
  int tinggi_segitiga,i,j;
 
  cout << "Input tinggi segitiga: ";
  cin >> tinggi_segitiga;
 
  cout << endl;
 
  for(i = 0; i < tinggi_segitiga; i++) {
    for(j = tinggi_segitiga; j > i; j--) {
      cout << " *";
    }
    cout << endl;
  }
 
  return 0;
}
```

Perbedaan dari kode program pertama ada di baris 19. Sekarang perulangan for **j** akan mulai dari `j = tinggi_segitiga`, lalu diturunkan 1 angka dalam setiap iterasi dengan perintah `j--` hingga hingga `j > i`.

Variasi ini hanya sekedar pembeda tergantung logika programmer yang membuat kode program.

---

Demikian soal dan jawaban kode program membuat segitiga bintang terbalik dalam bahasa C++.

Latihan soal membuat segitiga bintang punya berbagai variasi lain, misalnya membuat piramida bintang atau belah ketupat bintang. Prinsip dasar dari soal-soal ini akan mirip seperti kode program kita di atas.