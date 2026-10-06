---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Latihan Kode Program C++ Segitiga Bintang
sumber: duniailkom
date_learned: 2025-06-10T14:05:00
tags:
  - basic
---
Link Sumber: [Latihan Kode Program C++: Segitiga Bintang](https://www.duniailkom.com/latihan-kode-program-cpp-segitiga-bintang/)

---
## Hasil Latihan:
Kode Program:

```cpp
#include<iostream>
using namespace std;

int main() {
    cout << "Input tinggi segitiga: ";
    int n; cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout << "* " << " ";
        }
        cout << "\n";
    }
    return 0;
}
```
# Latihan Kode Program C++: Segitiga Bintang

Latihan membuat segitiga bintang menjadi salah satu materi algoritma yang sangat sering digunakan. Ini tidak heran karena untuk membuatnya perlu pemahaman logika serta konsep perulangan bersarang (_nested loop_).

Segitiga bintang juga punya banyak variasi lain yang akan kita bahas secara terpisah. Kali ini akan di jabarkan tentang kode program yang paling dasar terlebih dahulu.

---

## Soal Segitiga Bintang

Buatlah kode program C++ untuk menampilkan gambar segitiga dalam bentuk kumpulan karakter bintang (karakter `*`). Kode program butuh satu inputan yang dipakai untuk menentukan tinggi dari segitiga.

Berikut contoh tampilan akhir yang diinginkan (1) :

```
Input tinggi segitiga: 9
*  
*  *
*  *  *
*  *  *  *
*  *  *  *  *
*  *  *  *  *  *
*  *  *  *  *  *  *
*  *  *  *  *  *  *  *
*  *  *  *  *  *  *  *  *
```

Berikut contoh tampilan akhir yang diinginkan (2) :

```
Input tinggi segitiga: 5
*  
*  *
*  *  *
*  *  *  *
*  *  *  *  *
```
---

## Tips Membuat Kode Program Segitiga Bintang

Soal ini melatih pemahaman terkait **perulangan bersarang (nested loop)**. Berikut tutorial pendahuluan yang bisa diikuti:

- [[Part 7 Pengertian Variabel dalam Bahasa C++]]
- [[Part 11 Jenis-jenis Tipe Data dalam Bahasa C++]]
- [[Part 32 Perulangan FOR Bahasa C++]]
- [[1 - Latihan Kode Program C++ Persegi Bintang]]

Kita perlu membuat perulangan bersarang atau nested loop untuk memecahkan soal ini. Perulangan luar (outer loop) dipakai untuk menentukan tinggi segitiga, serta perulangan dalam (inner loop) untuk membuat bentuk segitiga.

Sangat disarankan agar memahami kode program [[1 - Latihan Kode Program C++ Persegi Bintang]] terlebih dahulu, karena segitiga bintang pada dasarnya adalah modifikasi dari kode program tersebut.

---

## Kode Program C++ Membuat Segitiga Bintang

Berikut salah satu solusi dari soal membuat segitiga bintang menggunakan bahasa pemrograman C++:

```cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "##  Program C++ Segitiga Bintang  ##" << endl;
  cout << "====================================" << endl;
  cout << endl;
 
  int tinggi_segitiga,i,j;
 
  cout << "Input tinggi segitiga: ";
  cin >> tinggi_segitiga;
 
  cout << endl;
 
  for(i=1;i<=tinggi_segitiga;i++) {
    for(j=1;j<=i;j++) {
      cout << " *";
    }
    cout << endl;
  }
 
  return 0;
}
```

Hasil kode program:

![[3 Latihan Kode Program C++ Segitiga Bintang-1.png]]

![[3 Latihan Kode Program C++ Segitiga Bintang-2.png]]

Kode program ini meminta satu inputan yang disimpan ke dalam variabel **tinggi_segitiga**. Variabel inilah yang menjadi penentu kondisi akhir dari perulangan for.

Proses menampilkan karakter bintang dilakukan oleh perulangan for di baris 18 – 23. Perulangan luar, yakni dengan variabel counter **i** dipakai untuk membuat tinggi segitiga. Ini dimulai dari `i = 1` hingga `i <= tinggi_segitiga`.

Jika pada saat proses input nilai `tinggi_segitiga` berisi angka 7, maka perulangan luar ini akan dijalankan sebanyak 7 kali.

Dalam setiap iterasi, jalankan perulangan dalam serta sebuah perintah `cout << endl` di baris 20. Perintah `endl` dipakai untuk proses pindah baris. Alternatif lain bisa juga menggunakan perintah `cout << "\n"`.

Perulangan dalam dengan variabel counter **j** dipakai untuk membuat karakter bintang. Karena kita membuat sebuah segitiga, maka karakter bintang harus dibuat menaik dari 1, 2, 3, dst hingga mencapai `tinggi_segitiga`.

Proses membuat perulangan menaik dilakukan mulai dari `j = 1` hingga `j <= i`. Kuncinya adalah, nilai variabel **i** akan naik mulai dari 1, 2 ,3 dst hingga mencapai nilai **i**.

Dalam setiap iterasi, jalankan perintah `cout << " *"`. Tanda spasi sebelum karakter bintang dipakai agar hasil bintang menjadi lebih rapi.

---

Demikian soal dan jawaban kode program membuat segitiga bintang dalam bahasa C++.

Latihan soal segitiga bintang punya berbagai variasi lain, misalnya segitiga bintang terbalik, piramida bintang, hingga belah ketupat bintang. Prinsip dasar dari soal-soal ini akan mirip seperti kode program kita di atas.