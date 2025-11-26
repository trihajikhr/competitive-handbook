---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 2030B
judul_STRIKE: Minimise Oneness
teori_STRIKE: 
sumber:
  - codeforces
ada_tips?: 
date_learned: 2025-08-14T02:36:00
tags:
  - STRIKE
  - combinatorics
---
Sumber: [codeforces.com \| 502: Bad gateway](https://codeforces.com/problemset/problem/2030/B)

```ad-tip
title:⚔️ Teori STRIKE
→ Minimize $|f(t) - g(t)|$ dengan $1$ digit '1', sisanya '0'.
```

<br/>

---
# 1 | Minimise Oneness

Untuk sebuah string biner sembarang `t`, kita definisikan:

* **f(t)** = jumlah subsekuens tak kosong dari `t` yang hanya berisi karakter `0`.
* **g(t)** = jumlah subsekuens tak kosong dari `t` yang mengandung **setidaknya satu** karakter `1`.

Perhatikan bahwa untuk **f(t)** dan **g(t)**, setiap subsekuens dihitung **sebanyak jumlah kemunculannya** di `t`. Contoh:

* f(000) = 7
* g(100) = 4

Kita definisikan **oneness** dari string biner `t` sebagai:

$$
|f(t) - g(t)|
$$

di mana untuk bilangan bulat `z`, $|z|$ adalah nilai absolut dari `z`.

Kamu diberi sebuah bilangan bulat positif `n`. Tugasnya: temukan string biner `s` dengan panjang `n` sehingga **oneness**-nya sekecil mungkin. Jika ada lebih dari satu jawaban, boleh cetak salah satunya.

#### Catatan:

* *String biner* adalah string yang hanya terdiri dari karakter `0` dan `1`.
* *Subsekuens* dari suatu urutan `b` adalah urutan yang bisa diperoleh dari `b` dengan menghapus beberapa (mungkin nol atau semua) elemen.
  Contoh subsekuens dari `1011101`:

  * 0
  * 1
  * 11111
  * 0111
    Bukan subsekuens: 000, 11100.

#### Input
Baris pertama: sebuah bilangan bulat `t` (1 ≤ t ≤ 10⁴) — jumlah *test case*.

Setiap *test case* terdiri dari satu baris berisi bilangan bulat `n` (1 ≤ n ≤ 2×10⁵) — panjang string `s`.

Dijamin bahwa total nilai `n` di semua *test case* tidak lebih dari 2×10⁵.

#### Output
Untuk setiap *test case*, cetak string `s` di baris baru.
Jika ada beberapa jawaban, cetak salah satunya.



<br/>

---
# 2 | Sesi STRIKE ⚔️

**Trik**: Kalau ingin meminimalkan selisih jumlah subsequence yang hanya 0 dan yang mengandung 1, cukup buat string biner yang mengandung **tepat satu** angka 1 (posisinya bebas).

**Alasannya**: Dengan satu 1, jumlah subsequence di kedua kategori berbeda tepat **1**, yang adalah selisih terkecil yang mungkin.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

**Observasi:** $f(t) - g(t)$ selalu bilangan ganjil.

**Bukti:** $f(t) + g(t)$ adalah himpunan semua *subsequence* tak kosong dari $t$, yaitu $2^{|t|} - 1$, yang merupakan bilangan ganjil. Jumlah dan selisih dua bilangan bulat memiliki paritas yang sama, sehingga $f(t) - g(t)$ selalu ganjil.

Dengan menyertakan tepat satu digit **1** pada string $s$, kita dapat membuat $f(s) = 2^{n} - 1 - 1$ dan $g(s) = 2^{n} - 1$, sehingga $f(s) - g(s) = 1$ berdasarkan prinsip perkalian. Jelas ini adalah hasil terbaik yang bisa dicapai. Jadi, kita cukup mencetak string apa pun yang mengandung tepat satu **1**.

Implementasinya adalah sebagai berikut:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << '1';
        for(int i = 1; i < n; i++) cout << '0';
        cout << endl;
    }
}
```

## 3.2 | Analisis Pribadi

### Ingat definisi $f(t)$ dan $g(t)$

* $f(t)$ = jumlah *subsequence* tak kosong yang **hanya berisi 0**.
* $g(t)$ = jumlah *subsequence* tak kosong yang **mengandung minimal satu 1**.

Kalau semua *subsequence* dibagi dua kategori itu, jumlahnya pasti:

$$
f(t) + g(t) = 2^{|t|} - 1
$$

karena semua *subsequence* tak kosong termasuk salah satu kategori.


### Kenapa cukup 1 digit **1**?

Misal kita pilih string $s$ dengan **tepat satu** digit **1**, sisanya **0** semua. Contoh:

* $n = 5$ → `10000`

Efeknya:

* *Subsequence* yang **hanya 0** = semua subsequence yang tidak mengambil si **1** itu → jumlahnya:

$$
f(s) = 2^{n-1} - 1
$$

(kita hanya pilih dari $n-1$ nol, tak kosong).

* *Subsequence* yang mengandung minimal satu **1** = semua sisanya → jumlahnya:

$$
g(s) = (2^n - 1) - f(s) = (2^n - 1) - (2^{n-1} - 1) = 2^{n-1}
$$

### Selisihnya selalu 1

$$
|f(s) - g(s)| = \big| (2^{n-1} - 1) - 2^{n-1} \big| = 1
$$

Dan dari pembuktian di soal, nilai **oneness** (selisih) ini **tidak bisa lebih kecil dari 1**, jadi ini **paling optimal**.

### Kenapa kodenya cukup `1` di depan dan sisanya `0`?

Karena string dengan **tepat satu 1** bisa di mana saja, hasilnya sama. Pilih paling gampang saja: taruh **1** di awal, lalu print **0** sebanyak $n-1$ kali.
Itulah yang dilakukan oleh:

```cpp
cout << '1';
for(int i = 1; i < n; i++) cout << '0';
```

Jadi, ini implementasiku:

```cpp
/*
Author  : Riveris
Date    : 2025-08-13 00:16
Problem : Codeforces - 2030B | Minimise Oneness
*/

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
   cout << 1;
   for (int i = 0; i < n - 1; i++) {
      cout << 0;
   }

   cout << '\n';
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