---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 1370A
judul_FAST: Maximum GCD
teori_FAST: Nilai FPB atau GCD terbesar dari n, jika a < b, adalah n/2
sumber:
  - codeforces
date_learned: 2025-08-08T13:38:00
tags:
  - STRIKE
  - number-theory
---
Sumber: [1370A - Maximum GCD](https://codeforces.com/problemset/problem/1370/A)

> [!NOTE] ⚔️ Teori STRIKE:
> Jika kita diminta untuk mencari angka $a$ dan $b$ dari $n$, dimana $1\leq a < b \leq n$, dan kita harus mencari FPB atau GCD dari $n$, dimana $gcd(a,b)$ adalalah sebesar mungkin, maka jawabanya adalah $n/2$.

<br/>

---
# 1370A - Maximum GCD

Mari kita pertimbangkan semua bilangan bulat dalam rentang dari **1** sampai **n** (termasuk keduanya).

Di antara semua pasangan bilangan bulat **berbeda** dalam rentang ini, temukan _greatest common divisor_ (GCD) terbesar yang mungkin. Secara formal, temukan nilai maksimum dari `gcd(a, b)`, di mana `1 ≤ a < b ≤ n`.

_Greatest common divisor_ atau `gcd(a, b)` dari dua bilangan bulat positif **a** dan **b** adalah bilangan bulat terbesar yang menjadi pembagi dari **a** dan **b** sekaligus.


<br/>

---
# Sesi STRIKE ⚔️

Jawabanya:

```cpp
/*
Author  : trihajikhr
Date    : 2025-08-08 13:35
Problem : Codeforces - 1370A | Maximum GCD
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
      int n;
      cin >> n;
      cout << n / 2 << '\n';
   }
   return 0;
}
```


<br/>

---


# Jawaban dan Editorial


## Analisis Pribadi

Semisal nilai dari n adalah 100, maka nilai GCD tertinggi yang mungkin adalah 50, yang didapat dari gcd(50, 100). 

Ini artinya nilai gcd terbesar yang mungkin dari suatu angka $n$, jika kedua nilai $a$ dan $b$ tidak boleh sama, adalah hasil pembagian $n$ dengan 2. Lalu bagaimana dengan ganjil? Karena int ganjil jika dibagi 2 otomatis dibulatkan kebawah, maka rumus tadi tetap berlaku.