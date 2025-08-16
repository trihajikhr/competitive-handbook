---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 1389A
judul_FAST: LCM Problem
teori_FAST: Nilai dari LCM terkecil kurang dari r, jika diberi a dan b untuk LCM(a,b), dan a<b, hanya terpenuhi jika a*2<=r.
sumber:
  - codeforces
date_learned: 2025-08-08T15:23:00
tags:
  - STRIKE
  - number-theory
---
Sumber: [1389A - LCM Problem](https://codeforces.com/problemset/problem/1389/A)

> [!NOTE] ⚔️ Teori STRIKE:
> Jika kamu diberi angka $n$, dan diminta untuk mencari LCM(n, m) yang tidak melewati $r$, dimana kamu harus menggunakan satu angka $n$ tersebut, dan satunya yaitu $m$ harus lebih besar dari $n$, maka cukup $LCM(n, (n*2))$, jika hasilnya dibawah atau sama dengan $r$, maka hasilnya benar, jika tidak, maka tidak mungkin ada persamaan yang memnuhi.
> 
> Atau, dengan kata lain, cukup hitung apakah $n*2 \leq r$, jika memenuhi , outputkan $n$ dan $n*2$, jika tidak, outputkan $-1$.

<br/>

---
# LCM Problem

Misalkan **LCM(x, y)** adalah bilangan bulat positif terkecil yang habis dibagi oleh **x** dan **y**.  
Sebagai contoh, **LCM(13, 37) = 481**, dan **LCM(9, 6) = 18**.

Diberikan dua bilangan bulat **l** dan **r**. Temukan dua bilangan bulat **x** dan **y** sedemikian sehingga **l ≤ x < y ≤ r** dan **l ≤ LCM(x, y) ≤ r**.

<br/>

---
# Sesi STRIKE ⚔️

Berikut jawaban yang benar:

```cpp
/*
Author  : trihajikhr
Date    : 2025-08-08 15:17
Problem : Codeforces - 1389A | LCM Problem
*/

#include <iostream>
using namespace std;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void solve() {
   int l, r;
   cin >> l >> r;
   if (l * 2 <= r) {
      cout << l << " " << l * 2 << '\n';
   } else {
      cout << -1 << " " << -1 << '\n';
   }
}

auto main() -> int {
   fastio();
   int t;
   cin >> t;
   while (t--) solve();
   return 0;
}
```

<br/>

---


# Jawaban dan Editorial

Misalkan kita sudah memilih x dan y sebagai jawaban, dan x bukan pembagi dari y.  

Karena LCM(x, y) berada di dalam rentang [l, r], kita sebenarnya bisa saja memilih x dan LCM(x, y) sebagai pasangan.  

Artinya, jika jawaban ada, maka pasti ada juga jawaban di mana x adalah pembagi dari y.

Jika $2·l > r$, maka tidak ada pasangan (x, y) yang memenuhi l ≤ x < y ≤ r dan x | y (x membagi y).  
Jika tidak, maka $x = l$ dan $y = 2·l$ adalah jawabannya.

## Analisis Pribadi

Analisis sudah ditaruh di bagian atas, problem ini tidak terlalu sulit.