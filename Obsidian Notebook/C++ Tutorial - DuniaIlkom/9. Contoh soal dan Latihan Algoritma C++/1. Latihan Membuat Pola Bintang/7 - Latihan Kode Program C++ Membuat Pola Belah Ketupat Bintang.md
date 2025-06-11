---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Latihan Kode Program C++ Membuat Pola Belah Ketupat Bintang
sumber: duniailkom
date_learned: 2025-06-10T18:40:00
tags:
  - basic
---
Link Sumber: [Latihan Kode Program C++ Membuat Pola Belah Ketupat Bintang](https://www.duniailkom.com/latihan-kode-program-cpp-belah-ketupat-bintang/)

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

        for(int j=0;j<n-i;j++){
            cout << " ";
        }

        for(int j=0;j<=i;j++){
            cout << "* ";
        }
        cout << "\n";
    }

    for(int i=0;i<n-1; i++){
        cout << "  ";
        for(int j=0; j<i;j++){
            cout << " ";
        }

        for(int j=0; j<n-i-1;j++){
            cout << "* ";
        }
        cout << "\n";
    }
    return 0;
}
```
# Latihan Kode Program C++: Membuat Pola Belah Ketupat Bintang

Membuat kode program belah ketupat bintang sudah menjadi salah satu soal "legend" dalam latihan algoritma menggunakan bahasa pemrograman C++.

Ini karena kode yang diperlukan cukup kompleks karena setidaknya kita butuh 6 buah perulangan yang saling bersambung satu sama lain.

Latihan ini menguji pemahaman tentang logika program serta penggunaan perulangan bersarang (nested loop). Dalam beberapa soal, belah ketupat bintang ini disebut juga sebagai **diamond bintang**.

---

## Soal Belah Ketupat Bintang

Buatlah kode program C++ untuk menampilkan gambar belah ketupat atau diamond dalam bentuk kumpulan bintang (karakter `*`). Kode program butuh satu inputan yang dipakai untuk menentukan lebar belah ketupat.

Berikut contoh tampilan akhir yang diinginkan (1) :

```
Input tinggi segitiga: 4

    *
   * *
  * * *
 * * * *
  * * *
   * *
    *
```

Berikut contoh tampilan akhir yang diinginkan (2) :

```
Input tinggi segitiga: 6

      *
     * *
    * * *
   * * * *
  * * * * *
 * * * * * *
  * * * * *
   * * * *
    * * *
     * *
      *
```

---

## Tips Membuat Kode Program Belah Ketupat

Soal ini melatih pemahaman terkait **perulangan bersarang (nested loop)**. Berikut tutorial pendahuluan yang bisa diikuti:

- [[Part 7 Pengertian Variabel dalam Bahasa C++]]
- [[Part 11 Jenis-jenis Tipe Data dalam Bahasa C++]]
- [[3 - Latihan Kode Program C++ Segitiga Bintang]]
- [[6 - Latihan Kode Program C++ Piramida Bintang Terbalik]]

Kita perlu membuat perulangan bersarang atau nested loop untuk memecahkan soal ini.

Pada dasarnya belah ketupat bintang adalah gabungan dari piramida bintang dan piramida bintang terbalik dalam satu program. Artinya kita butuh 6 buah perulangan for untuk membuatnya. Karena itu pemahaman tentang kode program membuat piramida bintang sangat diperlukan.

---

## Kode Program C++ Belah Ketupat

Berikut salah satu solusi dari soal membuat belah ketupat menggunakan bahasa pemrograman C++:

```cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "##  Program C++ Belah Ketupat Bintang  ##" << endl;
  cout << "=========================================" << endl;
  cout << endl;
 
  int lebar_belah_ketupat,i,j,k;
 
  cout << "Input lebar belah ketupat: ";
  cin >> lebar_belah_ketupat;
 
  cout << endl;
 
  for(i=1;i<=lebar_belah_ketupat;i++) {
 
    for(j=1;j<=lebar_belah_ketupat-i;j++) {
      cout << " ";
    }
 
    for(k=1;k<=i;k++) {
      cout << " *";
    }
    cout << endl;
  }
 
  for(i=1;i<lebar_belah_ketupat;i++) {
 
    for(j=1;j<=i;j++) {
      cout << " ";
    }
 
    for(k=1;k<=lebar_belah_ketupat-i;k++) {
      cout << " *";
    }
    cout << endl;
  }
 
  return 0;
}
```

Hasil kode program:

![[7 - Latihan Kode Program C++ Membuat Pola Belah Ketupat Bintang-1.png]]

![[7 - Latihan Kode Program C++ Membuat Pola Belah Ketupat Bintang-2.png]]

Kode program ini meminta satu inputan yang disimpan ke dalam variabel `lebar_belah_ketupat`. Variabel inilah yang nantinya akan menjadi penentu kondisi akhir dari perulangan for.

Proses menampilkan karakter bintang dilakukan oleh 6 buah perulangan for antara baris 18 – 40. Seperti yang dijelaskan dalam bagian tips, kode program ini merupakan gabungan dari kode membuat piramida bintang dan piramida bintang terbalik.

Tiga perulangan for pertama antara baris 18 – 28 dipakai untuk membuat sisi atas belah ketupat. Sedangkan tiga perulangan for berikutnya antara baris 30 – 40 dipakai untuk membuat sisi bawah belah ketupat.

Perulangan luar pertama dimulai dari `i = 1` sampai `i <= lebar_belah_ketupat`. Sedangkan perulangan luar kedua dimulai dari `i = 1` sampai `i < lebar_belah_ketupat`. Sedikit perbedaan dari penggunaan tanda `<=` dan `<` adalah agar alas piramida atas tidak berhimpit dengan alas piramida bawah. Dalam setiap perulangan `i`, jalankan perulangan `j` dan `k` untuk membuat pola piramida dan pola piramida terbalik.

---

Demikian soal dan jawaban kode program membuat pola belah ketupat bintang dalam bahasa C++. Kode yang diperlukan memang cukup kompleks karena butuh 6 buah perulangan for yang saling terhubung satu sama lain. Semoga bisa bermanfaat.