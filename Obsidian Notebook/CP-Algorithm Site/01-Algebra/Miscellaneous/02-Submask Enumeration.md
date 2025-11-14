---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Submask Enumeration
sumber:
  - cp-algorithms.com
date_learned: 2025-10-13T17:23:00
tags:
  - bit-representation
---
Link Sumber: [Enumerating submasks of a bitmask - Algorithms for Competitive Programming](https://cp-algorithms.com/algebra/all-submasks.html)

---
# 1 | Submask Enumeration
## 1.1 | Mengenumerasi Semua Submask dari *Mask* Tertentu

Diberikan sebuah *bitmask* $\large m$, Anda ingin melakukan iterasi secara efisien melalui semua submask-nya, yaitu, *mask* $\large s$ di mana hanya bit-bit yang disertakan dalam *mask* $\large m$ yang diset.

Perhatikan implementasi dari algoritma ini, yang didasarkan pada trik operasi bit:

```cpp
int s = m;
while (s > 0) {
    // ... you can use s ...
    s = (s-1) & m;
}
```

Atau, menggunakan pernyataan `for` yang lebih ringkas:

```cpp
for (int s=m; s; s=(s-1)&m)
    // ... you can use s ...
```

Pada kedua varian kode di atas, submask yang bernilai nol (0) tidak akan diproses. Kita dapat memprosesnya di luar perulangan (*loop*), atau menggunakan desain yang kurang elegan, misalnya:

```cpp
for (int s=m; ; s=(s-1)&m) {
    // ... you can use s ...
    if (s==0)  break;
}
```

Mari kita telusuri mengapa kode di atas mengunjungi semua submask dari $\large m$, tanpa pengulangan, dan dalam urutan menurun.

Misalkan kita memiliki *bitmask* saat ini $\large s$, dan kita ingin beralih ke *bitmask* berikutnya. Dengan mengurangi satu unit dari *mask* $\large s$ ($\large s-1$), kita akan menghilangkan bit yang diset paling kanan (*rightmost set bit*) dan semua bit di sebelah kanannya akan menjadi 1.

Setelah itu, kita menghilangkan semua bit satu "ekstra" yang tidak termasuk dalam *mask* $\large m$ dan oleh karena itu tidak dapat menjadi bagian dari submask. Kita melakukan penghilangan ini dengan menggunakan operasi bitwise $\large (s-1) \ \& \ m$.

Sebagai hasilnya, kita "memotong" *mask* $\large s-1$ untuk menentukan nilai tertinggi yang dapat diambilnya, yaitu submask berikutnya setelah $\large s$ dalam urutan menurun.

Dengan demikian, algoritma ini menghasilkan semua submask dari *mask* ini dalam urutan menurun, hanya melakukan dua operasi per iterasi (*iteration*).

Kasus khusus terjadi ketika $\large s = 0$. Setelah mengeksekusi $\large s-1$, kita mendapatkan *mask* di mana semua bit diset (representasi bit dari $\large -1$), dan setelah $\large (s-1) \ \& \ m$ kita akan memiliki $\large s$ yang sama dengan $\large m$. Oleh karena itu, berhati-hatilah dengan *mask* $\large s = 0$ — jika perulangan tidak berakhir pada nol, algoritma dapat memasuki perulangan tak terbatas (*infinite loop*).
## 1.2 | Iterasi Melalui Semua *Mask* dengan Submask-nya. Kompleksitas $\large O(3^n)$

Dalam banyak masalah, terutama yang menggunakan pemrograman dinamis *bitmask* (*bitmask dynamic programming*), Anda ingin melakukan iterasi melalui semua *bitmask* dan untuk setiap *mask*, melakukan iterasi melalui semua submask-nya:

```cpp
for (int m=0; m<(1<<n); ++m)
    for (int s=m; s; s=(s-1)&m)
        // ... s and m ...
```

Mari kita buktikan bahwa perulangan (*loop*) dalam akan dieksekusi dengan total $\large O(3^n)$ iterasi.

### 1.2.1 | Pembuktian Pertama (Berdasarkan Opsi Bit)

Perhatikan bit ke-$\large i$. Ada tepat tiga opsi untuk bit tersebut:

1.  Bit tersebut **tidak termasuk** dalam *mask* $\large m$ (dan oleh karena itu tidak termasuk dalam submask $\large s$).
2.  Bit tersebut **termasuk** dalam $\large m$, tetapi **tidak termasuk** dalam $\large s$.
3.  Bit tersebut **termasuk** dalam **keduanya**, $\large m$ dan $\large s$.

Karena ada total $\large n$ bit, maka akan ada $\large 3^n$ kombinasi yang berbeda.

### 1.2.2 | Pembuktian Kedua (Berdasarkan Koefisien Binomial)

Perhatikan bahwa jika *mask* $\large m$ memiliki $\large k$ bit yang diaktifkan (*enabled bits*), maka ia akan memiliki $\large 2^k$ submask.

Karena kita memiliki total $\large \binom{n}{k}$ *mask* dengan $\large k$ bit yang diaktifkan (lihat *binomial coefficients*), maka jumlah total kombinasi untuk semua *mask* adalah:

$$\large \sum_{k=0}^n \binom{n}{k} \cdot 2^k$$

Untuk menghitung bilangan ini, perhatikan bahwa jumlah di atas sama dengan ekspansi dari $\large (1+2)^n$ menggunakan **teorema binomial** (*binomial theorem*). Oleh karena itu, kita memiliki $\large 3^n$ kombinasi, seperti yang ingin kita buktikan.

<br/>

---
# 2 | Soal Latihan (Practice Problems)

- [Atcoder - Close Group](https://atcoder.jp/contests/abc187/tasks/abc187_f)
- [Codeforces - Nuclear Fusion](http://codeforces.com/problemset/problem/71/E)
- [Codeforces - Sandy and Nuts](http://codeforces.com/problemset/problem/599/E)
- [Uva 1439 - Exclusive Access 2](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4185)
- [UVa 11825 - Hackers' Crackdown](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2925)