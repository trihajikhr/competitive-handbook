---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 2108A
judul_STRIKE: Permutation Warm-Up
teori_STRIKE: Permutasi dan fungsi jarak absolut
sumber:
  - codeforces
ada_tips?: 
date_learned: 2025-08-14T15:39:00
tags:
  - STRIKE
  - combinatorics
---
Sumber: [Problem - 2108A - Codeforces](https://codeforces.com/problemset/problem/2108/A)

```ad-tip
title:⚔️ Teori STRIKE
- Teknik **batas nilai + pola kenaikan** untuk menghitung _range_ nilai fungsi.
    
- Menggunakan **parity** untuk mengurangi kemungkinan nilai yang harus dihitung.
    
- Mengubah brute force jadi **O(1)**.
```


<br/>

---
# 1 | Permutation Warm-Up

Untuk sebuah permutasi $p$ dengan panjang $n$, kita mendefinisikan fungsi:

$$
f(p) = \sum_{i=1}^{n} \lvert p_i - i \rvert .
$$

Diberikan sebuah bilangan $n$. Kamu perlu menghitung berapa banyak nilai berbeda yang dapat diambil oleh fungsi $f(p)$ ketika mempertimbangkan semua permutasi dari bilangan $1$ sampai $n$.

$*$ **Permutasi** berukuran $n$ adalah sebuah array yang berisi $n$ bilangan bulat berbeda dari $1$ hingga $n$ dalam urutan sembarang. Sebagai contoh, $[2,3,1,5,4]$ adalah sebuah permutasi, tetapi $[1,2,2]$ **bukan** permutasi (karena $2$ muncul dua kali), dan $[1,3,4]$ juga **bukan** permutasi (karena $n=3$ tetapi terdapat $4$ di dalam array).

#### Input:
Setiap berkas masukan berisi beberapa test case. Baris pertama berisi jumlah test case $t$ $(1 \le t \le 100)$. Deskripsi setiap test case menyusul.

Baris pertama tiap test case berisi sebuah bilangan bulat $n$ $(1 \le n \le 500)$ — banyaknya angka dalam permutasi.

#### Output:
Untuk setiap test case, keluarkan sebuah bilangan bulat — banyaknya **nilai berbeda** yang dapat diambil fungsi $f(p)$ untuk panjang permutasi yang diberikan.


<br/>

---
# 2 | Sesi STRIKE ⚔️

**STRIKE – Permutasi & Fungsi Jarak Absolut**

Pada soal ini, tujuan awalnya terlihat seperti harus mencoba semua permutasi ($n!$ kemungkinan) untuk menghitung berapa banyak nilai unik $f(p)$ yang mungkin. Namun, setelah dianalisis, ditemukan pola penting: nilai minimum selalu $0$ (urutan asli) dan nilai maksimum selalu $\left\lfloor \frac{n^2}{2} \right\rfloor$ (urutan dibalik). Pergeseran elemen terbesar satu per satu menaikkan $f(p)$ dengan selisih konstan $+2$, sehingga semua nilai di antara min dan max yang mungkin hanyalah bilangan genap. Dari sini, menghitung jumlah nilai unik cukup dengan mencari banyak bilangan genap antara $0$ hingga $\left\lfloor \frac{n^2}{2} \right\rfloor$, menghasilkan rumus $\left\lfloor \frac{n^2}{4} \right\rfloor + 1$. Trik yang diambil adalah menggunakan batas min–max, pola kenaikan teratur, dan sifat parity untuk memangkas perhitungan dari $O(n!)$ menjadi $O(1)$.


<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Kita mulai dengan $p = [1, 2, 3, \dots, n]$. Untuk $p$ ini, $f(p) = 0$.

Sekarang, kita pindahkan elemen $n$ ke posisi awal **satu posisi demi satu posisi**. Mudah dilihat bahwa kita akan **menambah** nilai $f(p)$ sebesar $2$ pada setiap langkah.

Selanjutnya, kita pindahkan $n-1$ ke posisi ke-2, lalu $n-2$ ke posisi ke-3, dan seterusnya, sampai kita mencapai $p = [n, n-1, \dots, 2, 1].$

Untuk $p$ ini, $f(p) = \left\lfloor \frac{n^2}{2} \right\rfloor .$

Selama proses ini, kita mendapatkan **setiap bilangan genap** dari $0$ hingga $\left\lfloor \frac{n^2}{2} \right\rfloor$, karena pada setiap langkah kita menambahkan $+2$.

Sekarang, kita buktikan bahwa tidak mungkin mendapatkan nilai lain.

1. Jelas bahwa kita tidak dapat memperoleh nilai yang lebih kecil dari $0$ atau lebih besar dari $\left\lfloor \frac{n^2}{2} \right\rfloor$.
2. Kita hanya bisa mendapatkan nilai **genap**, karena setiap pertukaran mengubah nilai $f(p)$ dengan jumlah genap.

Maka, jumlah nilai berbeda yang mungkin adalah: $\left\lfloor \frac{n^2}{4} \right\rfloor + 1 .$

**Kompleksitas waktu:** $O(1)$.

Berikut implementasinya:

```cpp
#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;
#define SPEEDY std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define forn(i, n) for (ll i = 0; i < ll(n); ++i)

void solution(){
    ll n;cin>>n;
    ll k=n/2;
    if (n%2){cout<<k*(k+1)+1;return;}
    cout<<k*k+1;
}

int main() {
    SPEEDY;
    int t; cin>>t;
    while (t--){
        solution();
        cout << '\n';
    } return 0;
}
```
## 3.2 | Analisis Pribadi

Tujuan soal ini sebenarnya sederhana: **menghitung berapa banyak nilai berbeda yang bisa dihasilkan oleh fungsi**

$$
f(p) = \sum_{i=1}^n |p_i - i|
$$

kalau kita mencoba **semua permutasi** dari $1, 2, \dots, n$.

Kalau dipecah:

1. **Fungsi $f(p)$** ini mengukur “total jarak” posisi tiap elemen dari tempat aslinya.

   * Kalau $p$ adalah urutan asli $[1,2,\dots,n]$, jaraknya nol, jadi $f(p) = 0$.
   * Kalau urutannya dibalik $[n, n-1, \dots, 1]$, jaraknya maksimum.

2. **Pertanyaannya:** dari semua kemungkinan urutan, berapa *jumlah nilai unik* dari $f(p)$ yang mungkin muncul?

3. **Trik soalnya:** ternyata tidak semua angka mungkin muncul — hanya **bilangan genap** dari $0$ sampai $\lfloor \frac{n^2}{2} \rfloor$, sehingga jumlahnya $\lfloor \frac{n^2}{4} \rfloor + 1$.

Jadi tujuan intinya bukan cari nilai $f(p)$ untuk tiap permutasi (karena itu mustahil kalau $n$ besar), tapi **memahami pola** perubahan $f(p)$ dan menyadari bahwa jawabannya bisa dihitung langsung dengan rumus $O(1)$.

Berikut implementasiku:

```cpp
/*
Author  : Riveris
Date    : 2025-08-13 01:08
Problem : Codeoforces - 2108A | Permutation Warm-Up
*/

#include <cmath>
#include <iostream>
using namespace std;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void solve() {
   int n;
   cin >> n;
   cout << floor(pow(n, 2) / 4) + 1 << '\n';
}

auto main() -> int {
   fastio();
   int t;
   cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}
```

```ad-faq
Kenapa dibagi dengan 4?
```

Oke, aku jelasin kenapa jawabannya jadi

$$
\left\lfloor \frac{n^2}{4} \right\rfloor + 1
$$

dan kenapa ada “bagi 4”-nya.

### Jarak maksimum $f(p)$

Kita tahu $f(p) = \sum |p_i - i|$.

Kalau permutasi dibalik total $[n, n-1, \dots, 1]$, jaraknya maksimum.
Contoh kecil:

* $n = 4$:

$$
p = [4, 3, 2, 1]
$$

Jaraknya: $|4-1| + |3-2| + |2-3| + |1-4| = 3 + 1 + 1 + 3 = 8]$ . Hasilnya $8 = \frac{4^2}{2}$.

Secara umum, jarak maksimum =

$$
\left\lfloor \frac{n^2}{2} \right\rfloor
$$

### Kita hanya dapat bilangan genap

Setiap kali kita menukar dua elemen, jarak total berubah **dengan kelipatan 2**, jadi nilai $f(p)$ cuma bisa **genap**:

$$
0, 2, 4, \dots, \left\lfloor \frac{n^2}{2} \right\rfloor
$$

### Menghitung jumlah bilangan genap

Kalau angka dari $0$ sampai $M$ hanya genap saja, banyaknya angka adalah:

$$
\frac{M}{2} + 1
$$

(tambah 1 karena termasuk nol).

Di sini $M = \left\lfloor \frac{n^2}{2} \right\rfloor$, jadi:

$$
\frac{\left\lfloor \frac{n^2}{2} \right\rfloor}{2} + 1
= \left\lfloor \frac{n^2}{4} \right\rfloor + 1
$$

**Singkatnya:**

* Bagi 2 pertama: karena jarak maksimum $\frac{n^2}{2}$.
* Bagi 2 kedua: karena kita hanya menghitung bilangan genap.
  Gabung → bagi $4$.

### Visualisasi

Masih ngga mudeng? intinya gini, kita nyoba nyari banyaknya hasil dari $f(p)$ yang beda beda, terus nanti dihitung sebaerapa banyak beda dari hasilnya.

DImana hasilnya itu bakal beda kalau semial kita urutkan terbalik, terus geser geserin elemen terbesar ke kanan, terus menerus sampai keurut lagi. Itu mirip kaya bubble sort yang pakai kompleksitas $n^2$ kan? 

Coba deh buat pergeseran dari semisal n = 4, ada 16 kemungkinan tuh. Nah pasti hasilnya 5 dari banyaknya hasil yang berbeda.

Kaya gini contohnya:

1 2 3 4 = 0
1 2 4 3 = 2
1 3 2 4 = 2
2 1 3 4 = 2
1 3 4 2 = 4
1 4 2 3 = 4
1 4 3 2 = 4
2 1 4 3 = 4
2 3 1 4 = 4
3 1 2 4 = 4
3 2 1 4 = 4
2 3 4 1 = 6
2 4 1 3 = 6
2 4 3 1 = 6
3 1 4 2 = 6
3 2 4 1 = 6
4 1 2 3 = 6
4 1 3 2 = 6
4 2 1 3 = 6
4 2 3 1 = 6
3 4 1 2 = 8
3 4 2 1 = 8
4 3 1 2 = 8
4 3 2 1 = 8

Lihat? Dari nilai $n=4$, cuma ada 5 hasil dari $f(p)$.

Penggeseran kaya diatas dilakukan sebanyak $n^2$. Lalu kita bagi dengan 4 karena kita harus melakukan pembagian 2 dua kali karena jarak maksimum dari $\frac{n^2}{2}$ dan karena kita hanya menghitung banyak bilangan genap. Lalu hasilnya kita tambah satu, karena $0$ nya ngga kehitung, padahal 0 juga termasuk dalam salah satu hasil unik dari kombinasi diatas kan.