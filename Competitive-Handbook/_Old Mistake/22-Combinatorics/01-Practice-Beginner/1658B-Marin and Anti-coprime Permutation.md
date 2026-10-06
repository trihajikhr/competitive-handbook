---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 1658B
judul_STRIKE: Marin and Anti-coprime Permutation
teori_STRIKE: 
sumber:
  - codeforces
date_learned: 2025-08-13T20:05:00
tags:
  - STRIKE
  - combinatorics
---
Sumber: [Problem - 1658B - Codeforces](https://codeforces.com/problemset/problem/1658/B)

```ad-tip
title:⚔️ Teori STRIKE

```

<br/>

---
# 1 | Marin and Anti-coprime Permutation

Marin ingin kamu menghitung banyaknya **permutasi indah**. Sebuah *permutasi indah* dengan panjang $n$ adalah permutasi yang memiliki sifat berikut:

$$
\gcd(1 \cdot p_1,\ 2 \cdot p_2,\ \dots,\ n \cdot p_n) > 1,
$$

di mana $\gcd$ adalah **greatest common divisor** (faktor persekutuan terbesar).

Sebuah **permutasi** adalah array yang terdiri dari $n$ bilangan bulat berbeda dari $1$ hingga $n$ dalam urutan acak.

Contoh: $[2, 3, 1, 5, 4]$ adalah permutasi, tetapi $[1, 2, 2]$ **bukan** permutasi (angka $2$ muncul dua kali) dan $[1, 3, 4]$ juga **bukan** permutasi ($n = 3$ tetapi terdapat angka $4$ di array).

**Input**

* Baris pertama berisi satu bilangan bulat $t$ $(1 \le t \le 10^3)$ — jumlah *test case*.
* Setiap *test case* terdiri dari satu baris yang berisi satu bilangan bulat $n$ $(1 \le n \le 10^3)$.

**Output**
Untuk setiap *test case*, cetak satu bilangan bulat — banyaknya permutasi indah.
Karena jawabannya bisa sangat besar, cetaklah jawabannya **modulo** $998244353$.


<br/>

---
# 2 | Sesi STRIKE ⚔️


<br/>

---


# 3 | Jawaban dan Editorial

Misalkan $g = \gcd(1 \cdot p_1,\ 2 \cdot p_2,\ \dots,\ n \cdot p_n)$, berapakah nilai maksimum dari $g$?

Untuk setiap nilai $g$, bisakah kamu menyusun permutasi yang memenuhi syarat?

## 3.1 | Analisis Official

Kita dapat membuktikan bahwa $g \le 2$.
#### Bukti:
Misalkan $g > 2$:

* Jika ada bilangan prima $p > 2$ sehingga $p \mid g$, maka ada $\left\lfloor \frac{n}{p} \right\rfloor$ bilangan yang habis dibagi $p$, sehingga kita hanya bisa memasangkan paling banyak $2 \left\lfloor \frac{n}{3} \right\rfloor$ bilangan ke dalam pasangan, yang jumlahnya lebih kecil daripada $n$.

* Jika tidak, kita bisa memasangkan bilangan ganjil dengan posisi genap, dan bilangan genap dengan posisi ganjil, yang menyebabkan $2 \mid g$. Karena $p_2$ ganjil, maka $2 \cdot p_2$ tidak habis dibagi $2^k$ untuk $k > 1$.

Oleh karena itu, $g \le 2$.

#### Kesimpulan:

* Jika $n$ ganjil, jawabannya adalah $0$, karena jumlah bilangan ganjil lebih banyak daripada bilangan genap.
* Jika $n$ genap, kita bisa memasangkan bilangan ganjil di posisi genap, dan bilangan genap di posisi ganjil.
  Untuk bilangan ganjil di posisi genap, ada $\left( \frac{n}{2} \right)!$ cara.
  Berdasarkan aturan perkalian, jawabannya adalah:

  $$
  \left( \left( \frac{n}{2} \right)! \right)^2
  $$

#### Implementasi

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    if (n & 1) {
        cout << "0\n";
        return;
    }
    long long ans = 1;
    for (int i = 1; i <= n / 2; ++i) {
        ans *= 1LL * i * i % MOD;
        ans %= MOD;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
```
## 3.2 | Analisis Pribadi

Berikut adalah jawabanku:

```cpp
/*
Author  : Riveris
Date    : 2025-08-13 20:20
Problem : Codeforces - 1658B | Marin and Anti-coprime Permutation
*/

#include <iostream>
using namespace std;

const int MOD = 998244353;

auto factor(int n) -> long long {
   long long val;
   val = 1;
   for (int i = 1; i <= n; i++) {
      val *= i;
      val %= MOD;
   }
   return val;
}

void solve() {
   int n;
   cin >> n;

   if (n % 2 == 1) {
      cout << 0 << '\n';
      return;
   }

   long long rest = factor(n / 2);
   rest *= rest;
   rest %= MOD;
   cout << rest << '\n';
}

auto main() -> int {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int t;
   cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}

```

Dieditorial dijelaskan bahwa jika $n$ ganjil, maka jawabanya adalah 0, karena ada jauh lebih banyak angka ganjil daripada genap pada situasi ini.

Sedangkan jika $n$ genap, kombinasi yang mungkin adalah dengan meletakan angka genap pada posisi ganjil, dan angka ganjil pada posisi genap. Susunan kombinasi dari angka-angka ini kita pisah menjadi dua, dan kemudian cari kombinasinya sendiri-sendiri sebelum dikalikan.

Sehingga: untuk kombinasi angka ganjil $(\frac{n}{2})!$
Untuk kombinasi angka genap juga sama $(\frac{n}{2})!$

Sehingga rumus finalnya, cukup: $(\frac{n}{2})! \times (\frac{n}{2})!$, atau $((\frac{n}{2})!)^2$

