---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: "Latihan Kode Program C++: Persegi Panjang Bintang"
sumber: duniailkom
date_learned: 2025-06-10T13:55:00
tags:
  - basic
---
Link Sumber: [Latihan Kode Program C++ Persegi Panjang Bintang](https://www.duniailkom.com/latihan-kode-program-cpp-persegi-panjang-bintang/)

---
## Hasil Latihan:
Kode program:

```cpp
#include<iostream>
using namespace std;

int main() {
    cout << "Input tinggi persegi: ";
    int t; cin >> t;
    cout << "Input lebar persegi: ";
    int p; cin >> p;

    for(int i=0;i<t;i++){
        for(int j=0;j<p;j++){
            cout << "* " << " ";
        }
        cout << "\n";
    }
    return 0;
}
```
# Latihan Kode Program C++: Persegi Panjang Bintang

Materi soal kode program C++ kali ini akan membahas cara membuat persegi panjang bintangLatihan ini melatih logika program, terutama pemahaman terkait konsep perulangan bersarang (nested loop).

---

## Soal Membuat Persegi Panjang Bintang

Buatlah kode program C++ untuk menampilkan gambar persegi panjang dalam bentuk kumpulan karakter bintang (karakter `*`). Kode program butuh dua buah inputan, yakni tinggi persegi dan lebar persegi.

Berikut contoh tampilan akhir yang diinginkan (1) :

```
Input tinggi persegi: 4
Input lebar persegi: 8

* * * * * * * *
* * * * * * * *
* * * * * * * *
* * * * * * * *
```
Berikut contoh tampilan akhir yang diinginkan (2) :

```
Input tinggi persegi: 4
Input lebar persegi: 8

* * * * * * * * * * * * * * *
* * * * * * * * * * * * * * *
* * * * * * * * * * * * * * *
* * * * * * * * * * * * * * *
* * * * * * * * * * * * * * *
```
---

## Tips Membuat Kode Program Persegi Panjang Bintang

Soal ini melatih pemahaman terkait **perulangan bersarang (nested loop)**. Berikut tutorial pendahuluan yang bisa diikuti:

- [[Part 7 Pengertian Variabel dalam Bahasa C++]]
- [[Part 11 Jenis-jenis Tipe Data dalam Bahasa C++]]
- [[Part 32 Perulangan FOR Bahasa C++]]
- [[1 - Latihan Kode Program C++ Persegi Bintang]]

Kita perlu membuat perulangan bersarang atau nested loop untuk memecahkan soal ini. Perulangan luar (_outer loop_) dipakai untuk membuat tinggi persegi, dan perulangan dalam (_inner loop_) dipakai untuk membuat lebar persegi.

Kode program yang digunakan akan sangat mirip seperti [[1 - Latihan Kode Program C++ Persegi Bintang]], sehingga sangat disarankan untuk dipelajari terlebih dahulu.

---

## Kode Program C++ Persegi Panjang Bintang

Berikut salah satu solusi dari soal membuat persegi panjang bintang menggunakan bahasa pemrograman C++:

```cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "##  Program C++ Persegi Panjang Bintang  ##" << endl;
  cout << "===========================================" << endl;
  cout << endl;
 
  int tinggi_persegi,lebar_persegi,i,j;
 
  cout << "Input tinggi persegi: ";
  cin >> tinggi_persegi;
  cout << "Input lebar persegi: ";
  cin >> lebar_persegi;
 
  cout << endl;
 
  for(i=1;i<=tinggi_persegi;i++) {
    for(j=1;j<=lebar_persegi;j++) {
      cout << " *";
    }
    cout << endl;
  }
 
  return 0;
}
```

Hasil kode program:

![[2 Latihan Kode Program C++ Persegi Panjang Bintang-1.png]]

![[Pasted image 20250610140057.png]]

Kode program ini meminta dua inputan yang disimpan ke dalam variabel **tinggi_persegi** dan **lebar_persegi**. Variabel inilah yang nantinya akan menjadi penentu kondisi akhir dari perulangan for.

Proses menampilkan karakter bintang dilakukan oleh perulangan for di baris 20 – 25. Perulangan luar, yakni dengan variabel counter **i** dipakai untuk membuat tinggi persegi. Ini dimulai dari `i = 1` hingga `i <= tinggi_persegi`.

Jika pada saat proses input nilai `tinggi_persegi` berisi angka 8, maka perulangan luar akan dijalankan sebanyak 8 kali.

Dalam setiap iterasi, jalankan perulangan dalam serta sebuah perintah `cout << endl` di baris 24. Perintah `endl` dipakai untuk proses pindah baris. Alternatif lain bisa juga menggunakan perintah `cout << "\n"`.

Perulangan dalam dengan variabel counter j, dipakai untuk membuat karakter bintang. Karena kita membuat sebuah persegi panjang, maka proses perulangan dilakukan mulai dari `j = 1` hingga `j <= lebar_persegi`.

Dalam setiap iterasi, jalankan perintah `cout << " *"`. Tanda spasi sebelum karakter bintang dipakai agar kotak persegi kita menjadi lebih rapi.

---

Demikian soal dan jawaban kode program membuat persegi panjang bintang dalam bahasa C++.

Latihan soal ini menjadi dasar dari kode program membuat bentuk bintang lain yang lebih kompleks, seperti segitiga bintang dan piramida bintang.