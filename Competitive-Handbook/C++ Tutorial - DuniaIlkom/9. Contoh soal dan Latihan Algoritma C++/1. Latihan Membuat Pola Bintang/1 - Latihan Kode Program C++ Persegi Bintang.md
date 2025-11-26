---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Latihan Kode Program C++ Persegi Bintang
sumber: duniailkom
date_learned: 2025-06-10T13:49:00
tags:
  - basic
---
Link Sumber: [Latihan Kode Program C++ Persegi Bintang](https://www.duniailkom.com/latihan-kode-program-cpp-membuat-persegi-bintang/)

---
## Hasil Latihan:
Kode program:

```cpp
#include<iostream>
using namespace std;

int main() {
    cout << "Masukan ukuran psersegi: ";
    int n; cin >> n;

    cout << "\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << "* " << " ";
        }
        cout << "\n";
    }

    return 0;
}
```

# Latihan Kode Program C++: Persegi Bintang
Latihan kode program C++ kali ini akan membahas soal untuk membuat persegi bintang. Materi ini melatih logika program, terutama pemahaman terkait konsep **perulangan bersarang** (_nested loop_).

---

## Soal Membuat Persegi Bintang

Buatlah kode program C++ untuk menampilkan gambar persegi dalam bentuk kumpulan karakter bintang (karakter `*`). Kode program butuh satu nilai input, yakni besar persegi yang diinginkan user.

Sebagai contoh, jika diinput angka 5, maka berikut tampilan hasil kode program:

```
Input besar persegi: 5
* * * * *
* * * * *
* * * * *
* * * * *
* * * * *
```

Atau jika diinput angka 7, maka tampilan akhirnya adalah:

```
Input besar persegi: 7
* * * * * * *
* * * * * * *
* * * * * * *
* * * * * * *
* * * * * * *
```

---

## Tips Membuat Kode Program Persegi Bintang

Soal ini melatih pemahaman terkait **perulangan bersarang (nested loop)**. Berikut tutorial pendahuluan yang bisa diikuti:

- [[Part 7 Pengertian Variabel dalam Bahasa C++]]
- [[Part 11 Jenis-jenis Tipe Data dalam Bahasa C++]]
- [[Part 32 Perulangan FOR Bahasa C++]]

Kita perlu membuat perulangan bersarang atau nested loop untuk memecahkan soal ini. Perulangan luar (_outer loop_) akan dipakai untuk membuat tinggi persegi, dan perulangan dalam (_inner loop_) dipakai untuk membuat lebar persegi.

---

## Kode Program C++ Persegi Bintang

Berikut salah satu solusi dari soal membuat persegi bintang menggunakan bahasa pemrograman C++:

```cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "##  Program C++ Persegi Bintang  ##" << endl;
  cout << "===================================" << endl;
  cout << endl;
 
  int besar_persegi,i,j;
 
  cout << "Input besar persegi: ";
  cin >> besar_persegi;
 
  cout << endl;
 
  for(i=1;i<=besar_persegi;i++) {
    for(j=1;j<=besar_persegi;j++) {
      cout << " *";
    }
    cout << endl;
  }
 
  return 0;
}
```

Hasil kode program:

![[Latihan Kode Program C++ Persegi Bintang-1.png]]

![[Latihan Kode Program C++ Persegi Bintang-2.png]]

Kode program ini meminta satu inputan yang disimpan ke dalam variabel `besar_persegi`. Variabel inilah yang nantinya akan menjadi penentu kondisi akhir dari perulangan for.

Proses menampilkan karakter bintang dilakukan oleh perulangan for di baris 18 – 23. Perulangan luar, yakni dengan variabel counter **i** dipakai untuk membuat tinggi persegi. Ini dimulai dari  `i = 1` hingga `i <= besar_persegi`.

Jika pada saat proses input nilai `besar_persegi` berisi angka 5, maka perulangan luar akan dijalankan sebanyak 5 kali.

Dalam setiap iterasi, jalankan perulangan dalam serta sebuah perintah `cout << endl` di baris 22. Perintah `endl` ini dipakai untuk proses pindah baris. Alternatif lain bisa juga menggunakan perintah `cout << "\n"`.

Perulangan dalam dengan variabel counter j, dipakai untuk membuat karakter bintang. Karena kita membuat sebuah persegi, maka proses perulangan juga dilakukan mulai dari `j = 1` hingga `j <= besar_persegi`.

Dalam setiap iterasi, jalankan perintah `cout << " *"`. Tanda spasi sebelum karakter bintang dipakai agar kotak persegi kita menjadi lebih rapi.

---

Latihan soal ini memang cukup sederhana, tapi menjadi dasar dari kode program membuat bentuk bintang lain yang lebih kompleks seperti persegi panjang bintang, segitiga bintang, hingga piramida bintang.