---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 1843C
judul_STRIKE: Sum in Binary Tree
teori_STRIKE: Trik Binary tree
sumber:
  - codeforces
ada_tips?: true
date_learned: 2025-08-14T00:15:00
tags:
  - STRIKE
  - combinatorics
---
Sumber: [Problem - 1843C - Codeforces](https://codeforces.com/problemset/problem/1843/C)

```ad-tip
title:⚔️ Teori STRIKE
Trik menemukan jumlah nilai path pada binary tree, dari root ke node dengan nilai $u$, dengan binary tree yang tersusun dengan susunan menaik dari kiri ke kanan, dan menurun.
```

<br/>

---
# 1 | Sum in Binary Tree


Vanya sangat menyukai matematika. Suatu hari, ketika ia sedang mengerjakan sebuah soal matematika, ia menemukan sebuah pohon (*tree*) yang menarik. Pohon ini dibangun dengan cara sebagai berikut:

Awalnya, pohon hanya memiliki satu simpul (vertex) bernomor $1$ — yang menjadi akar (*root*) pohon. Kemudian, Vanya menambahkan dua anak pada simpul tersebut, dan memberi nomor berurutan — $2$ dan $3$.

Setelah itu, ia akan menambahkan anak-anak untuk setiap simpul dengan urutan nomor yang menaik, dimulai dari simpul $2$, dengan memberikan nomor anak-anak tersebut menggunakan indeks terkecil yang belum terpakai.

Hasilnya, Vanya akan memiliki pohon tak hingga dengan akar di simpul bernomor $1$, di mana setiap simpul memiliki tepat dua anak, dan nomor simpul diatur berurutan berdasarkan lapisan (*layer*) pohon.

![[1843C-Sum in Binary Tree-2.png]]

Vanya ingin tahu berapa jumlah nomor simpul pada jalur dari simpul bernomor $1$ hingga simpul bernomor $n$ pada pohon tersebut. Karena Vanya tidak suka menghitung, ia memintamu untuk membantunya menemukan jumlah tersebut.

#### Input:
Baris pertama berisi satu bilangan bulat $t$ $(1 \le t \le 10^4)$ — jumlah *test case*.

Selanjutnya terdapat $t$ baris — deskripsi setiap *test case*.
Masing-masing baris berisi satu bilangan bulat $n$ $(1 \le n \le 10^{16})$ — nomor simpul yang ingin diketahui jumlah nomor simpul pada jalur dari akar hingga simpul tersebut.

#### Output:
Untuk setiap *test case*, cetak satu bilangan bulat — jumlah yang diminta.


<br/>

---
# 2 | Sesi STRIKE ⚔️

Setiap parent, akan memiliki anak kiri dan kanan dengan nilai $2 \cdot u$ untuk child kiri, dan $(2 \cdot u)+1$ untuk anak kanan.  

Trik menemukan jumlah nilai path pada binary tree, dari root ke node dengan nilai $u$, dengan binary tree yang tersusun dengan susunan menaik dari kiri ke kanan, dan menurun. #tips-trick 

<br/>

---


# 3 | Jawaban dan Editorial
## 3.1 | Analisis Official


Mudah untuk melihat bahwa child dari node bernomor $u$ memiliki nomor $2 \cdot u$ dan $2 \cdot u + 1$.
Jadi, leluhur (parent) dari simpul $u$ memiliki nomor $\left\lfloor \frac{u}{2} \right\rfloor$.

Perhatikan bahwa berdasarkan rumus ini, panjang jalur dari root ke node bernomor $n$ adalah $\left\lfloor \log_2 n \right\rfloor$.

Oleh karena itu, dengan batasan yang diberikan, kita bisa menuliskan jalur ke root secara eksplisit dan menghitung jumlah nomor node pada jalur tersebut dalam $O(\log n)$.

**Total kompleksitas:** $O(\log n)$ untuk setiap *test case*.

## 3.2 | Analisis Pribadi

Editorial resmi memberikan penjelasan yng cukup mudah dipahami. Soal ini juga tidak terlalu sulit jika melihat ke editorial. Dimana kita cukup tahu, bahwa tree yang digunakan disini adalah Binary Tree.

Binary Tree adalah tree yang tepat memiliki 2 anak, kanan dan kiri.

Setiap nilai dari setiap node binary tree yang disusun sedemikian rupa dengan cara diatas, memiliki sebuah pola yang jelas.

Dipastikan bahwa setiap parent, akan memiliki child yang nilainya 2 kali dari nilai paretnya. Jika parent node memiliki nilai $x$, maka child kiri akan memiliki nilai $x \cdot 2$ dan anak kanan akan memiliki nilai $(x \cdot 2) + 1$.

Kita cukup melakukan pembagian dengan 2 pada nilai node saat ini hingga habis ke nilai 1, untuk bisa naik ke node root dengan penjumlahan yang sesuai. Jangan lupa untuk menjumlahkan nilai node saat ini terlebih dahulu sebelum memulai pembagian.

Ini adalah implementasinya:

```cpp
/*
Author  : Riveris
Date    : 2025-08-11 20:06
Problem : Codeforces - 1843C | Sum in Binary Tree
*/

#include <iostream>
using namespace std;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

auto main() -> int {
   fastio();
   int t;
   cin >> t;
   while (t--) {
      long long n;
      cin >> n;

      long long sum = 0;
      while (n >= 1) {
         sum += n;
         n /= 2;
      }

      cout << sum << '\n';
   }
   return 0;
}

```