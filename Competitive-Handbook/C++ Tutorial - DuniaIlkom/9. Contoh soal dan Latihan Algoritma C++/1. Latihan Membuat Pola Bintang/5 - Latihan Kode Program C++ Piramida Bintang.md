---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Latihan Kode Program C++ Piramida Bintang
sumber: duniailkom
date_learned: 2025-06-10T18:20:00
tags:
  - basic
---
Link Sumber: [Latihan Kode Program C++ Piramida Bintang](https://www.duniailkom.com/latihan-kode-program-cpp-piramida-bintang/)

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
            cout << " ";
        }

        for(int j=0;j<=i;j++){
            cout << "* ";
        }
        cout << "\n";
    }
    return 0;
}
```
# Latihan Kode Program C++: Piramida Bintang

Membuat piramida bintang menjadi salah satu soal latihan C++ yang cukup sering dipakai. Latihan ini menguji pemahaman tentang logika program serta penggunaan perulangan bersarang (nested loop).

Dalam beberapa soal, piramida bintang ini disebut juga sebagai segitiga bintang sama sisi.

---

## Soal Piramida Bintang

Buatlah kode program C++ untuk menampilkan gambar piramida atau segitiga sama sisi dalam bentuk kumpulan bintang (karakter `*`). Kode program butuh satu inputan yang dipakai untuk menentukan tinggi dari segitiga.

Berikut contoh tampilan akhir yang diinginkan (1) :

```
Input tinggi segitiga: 7
       * 
      * *
     * * *
    * * * *
   * * * * *
  * * * * * *
 * * * * * * *
```

Berikut contoh tampilan akhir yang diinginkan (2) :

```
Input tinggi segitiga: 5
     * 
    * *
   * * *
  * * * *
 * * * * *
```

---

## Tips Membuat Kode Program Piramida Bintang

Soal ini melatih pemahaman terkait **perulangan bersarang (nested loop)**. Berikut tutorial pendahuluan yang bisa diikuti:

- [[Part 7 Pengertian Variabel dalam Bahasa C++]]
- [[Part 13 Tipe Data Integer Bahasa C++]]
- [[Part 32 Perulangan FOR Bahasa C++]]
- [[3 - Latihan Kode Program C++ Segitiga Bintang]]
- [[4 - Latihan Kode Program C++ Segitiga Bintang Terbalik]]

Kita perlu membuat perulangan bersarang atau nested loop untuk memecahkan soal ini. Perulangan luar (outer loop) dipakai untuk menentukan tinggi segitiga, serta perulangan dalam (inner loop) untuk membuat bentuk segitiga.

Soal ini merupakan pengembangan dari membuat segitiga bintang, tapi untuk inner loop akan butuh dua kali perulangan.

---

## Kode Program C++ Piramida Bintang

Berikut salah satu solusi dari soal membuat piramida bintang menggunakan bahasa pemrograman C++:

```cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "##  Program C++ Piramida Bintang  ##" << endl;
  cout << "====================================" << endl;
  cout << endl;
 
  int tinggi_segitiga,i,j,k;
 
  cout << "Input tinggi segitiga: ";
  cin >> tinggi_segitiga;
 
  cout << endl;
 
  for(i=1; i<=tinggi_segitiga; i++) {
 
    for(j=1; j<=tinggi_segitiga-i; j++) {
      cout << " ";
    }
 
    for(k=1; k<=i; k++) {
      cout << " *";
    }
    cout << endl;
  }
 
  return 0;
}
```

Hasil kode program:

![[5 Latihan Kode Program C++ Piramida Bintang-1.png]]


![[5 Latihan Kode Program C++ Piramida Bintang-2.png]]

Kode program ini meminta satu inputan yang disimpan ke dalam variabel **tinggi_segitiga**. Variabel inilah yang nantinya akan menjadi penentu kondisi akhir dari perulangan for.

Proses menampilkan karakter bintang dilakukan oleh perulangan for di baris 18 – 28. Perulangan luar, yakni dengan variabel counter **i** dipakai untuk membuat tinggi segitiga. Ini dimulai dari `i = 1` hingga `i <= tinggi_segitiga`.

Jika pada saat proses input nilai `tinggi_segitiga` berisi angka 9, maka perulangan luar ini akan dijalankan sebanyak 9 kali.

Dalam setiap iterasi, jalankan 2 buah perulangan dalam (inner loop) serta sebuah perintah `cout << endl` di baris 27. Perintah `endl` ini dipakai untuk proses pindah baris. Alternatif lain bisa juga menggunakan perintah `cout << "\n"`.

Untuk membuat bentuk piramida atau segitiga sama sisi, kita perlu 2 buah perulangan dalam.

Perulangan dalam dengan variabel counter **j** dipakai untuk membuat spasi yang akan mendorong karakter bintang ke arah kanan. Tanda spasi ini perlu dibuat menurun setiap kenaikan nilai **i**, oleh karena itu perulangan akan mulai dari `j = 1`, hingga `j<=tinggi_segitiga-i`.

Perulangan dalam kedua dengan variabel counter **k** dipakai untuk menampilkan karakter bintang. Sekarang tanda bintang ini perlu dibuat menaik mulai dari `k = 1` hingga `k <= i`.

Nilai variabel **i** akan naik mulai dari 1, 2 ,3 dst karena berasal dari perulangan luar. Dalam setiap iterasi, jalankan perintah `cout << " *"`. Tanda spasi sebelum karakter bintang dipakai agar hasil bintang menjadi lebih rapi.

---

Demikian soal dan jawaban kode program membuat piramida bintang dalam bahasa C++.

Latihan soal piramida bintang ini masih punya berbagai variasi lain, misalnya membuat piramida bintang terbalik dan belah ketupat bintang. Prinsip dasar dari soal-soal ini akan mirip seperti kode program kita di atas.