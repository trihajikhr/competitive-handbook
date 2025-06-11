---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Latihan Kode Program C++ Piramida Bintang Terbalik
sumber: duniailkom
date_learned: 2025-06-10T18:27:00
tags:
  - basic
---
Link Sumber: [Latihan Kode Program C++ Piramida Bintang Terbalik](https://www.duniailkom.com/latihan-kode-program-cpp-piramida-bintang-terbalik/)

---
## Hasil Latihan:
Kode program:

```cpp
#include<iostream>
using namespace std;

int main() {
    cout << "Input tinggi segitiga: ";
    int n; cin >> n;

    cout << "\n";
    for(int i=0;i<n;i++){

        for(int j=0;j<i;j++){
            cout << " ";
        }

        for(int j=0;j<n-i;j++){
            cout << "* ";
        }
        cout << "\n";
    }
    return 0;
}
```
# Latihan Kode Program C++: Piramida Bintang Terbalik

Membuat piramida bintang terbalik merupakan modifikasi dari [[5 - Latihan Kode Program C++ Piramida Bintang]] yang sudah pernah kita bahas sebelumnya.

Latihan ini menguji pemahaman tentang logika program serta penggunaan perulangan bersarang (nested loop). Dalam beberapa soal, piramida bintang terbalik ini disebut juga sebagai segitiga sama sisi terbalik.

---

## Soal Piramida Bintang Terbalik

Buatlah kode program C++ untuk menampilkan gambar piramida terbalik atau segitiga sama sisi terbalik dalam bentuk kumpulan bintang (karakter `*`).

Kode program butuh satu inputan yang dipakai untuk menentukan tinggi dari segitiga.

Berikut contoh tampilan akhir yang diinginkan (1) :

```
Input tinggi segitiga: 6
* * * * * * 
 * * * * *
  * * * *
   * * *
    * *
     *
```

Berikut contoh tampilan akhir yang diinginkan (2) :

```
Input tinggi segitiga: 8
* * * * * * * * 
 * * * * * * *
  * * * * * *
   * * * * *
    * * * *
     * * *
      * *
       *
```
---

## Tips Membuat Kode Program Piramida Bintang Terbalik

Soal ini melatih pemahaman terkait **perulangan bersarang (nested loop)**. Berikut tutorial pendahuluan yang bisa diikuti:

- [[Part 7 Pengertian Variabel dalam Bahasa C++]]
- [[Part 32 Perulangan FOR Bahasa C++]]
- [[Part 13 Tipe Data Integer Bahasa C++]]

Kita perlu membuat perulangan bersarang atau nested loop untuk memecahkan soal ini. Perulangan luar (outer loop) dipakai untuk menentukan tinggi segitiga, serta perulangan dalam (inner loop) untuk membuat bentuk segitiga.

Soal ini merupakan pengembangan dari membuat piramida bintang sebelumnya.

---

## Kode Program C++ Piramida Bintang Terbalik

Berikut salah satu solusi dari soal membuat piramida bintang terbalik menggunakan bahasa pemrograman C++:

```cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "##  Program C++ Piramida Bintang Terbalik  ##" << endl;
  cout << "=============================================" << endl;
  cout << endl;
 
  int tinggi_segitiga,i,j,k;
 
  cout << "Input tinggi segitiga: ";
  cin >> tinggi_segitiga;
 
  cout << endl;
 
  for(i=0; i<tinggi_segitiga; i++) {
 
    for(j=1; j<=i; j++) {
      cout << " ";
    }
 
    for(k=1; k<=tinggi_segitiga-i; k++) {
      cout << " *";
    }
    cout << endl;
  }
 
  return 0;
}
```

Hasil kode program:

![[6 - Latihan Kode Program C++ Piramida Bintang Terbalik-1.png]]

![[6 - Latihan Kode Program C++ Piramida Bintang Terbalik-2.png]]

Kode program ini meminta satu inputan yang disimpan ke dalam variabel **tinggi_segitiga**. Variabel inilah yang nantinya akan menjadi penentu kondisi akhir dari perulangan for.

Proses menampilkan karakter bintang dilakukan oleh perulangan for di baris 18 – 28. Perulangan luar, yakni dengan variabel counter **i** dipakai untuk membuat tinggi segitiga. Ini dimulai dari `i = 0` hingga `i < tinggi_segitiga`. Jika pada saat proses input nilai `tinggi_segitiga` berisi angka 5, maka perulangan luar akan dijalankan sebanyak 5 kali.

Dalam setiap iterasi, jalankan 2 buah perulangan dalam (inner loop) serta sebuah perintah `cout << endl` di baris 27. Perintah `endl` ini dipakai untuk proses pindah baris. Alternatif lain bisa juga menggunakan perintah `cout << "\n"`.

Untuk membuat bentuk piramida terbalik atau segitiga sama sisi terbalik, kita perlu 2 buah perulangan dalam.

Perulangan dalam dengan variabel counter **j** dipakai untuk membuat karakter spasi yang akan mendorong karakter bintang ke arah kanan. Tanda spasi ini perlu dibuat menaik, oleh karena itu perulangan akan mulai dari `j = 1`, hingga `j<=i`.

Perulangan dalam kedua dengan variabel counter **k** dipakai untuk membuat karakter bintang. Sekarang tanda bintang ini perlu dibuat menurun mulai dari `k = 1` hingga `k <= tinggi_segitiga-i`. Dalam setiap iterasi, jalankan perintah `cout << " *"`. Tanda spasi sebelum karakter bintang dipakai agar hasil bintang menjadi lebih rapi.

---

Demikian soal dan jawaban kode program membuat piramida bintang terbalik dalam bahasa C++. Semoga bisa bermanfaat.