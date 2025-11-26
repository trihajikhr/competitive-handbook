---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 1325A
judul_FAST: EhAb AnD gCd
teori_FAST: Trik GCD dan KPK
sumber:
  - codeforces
date_learned: 2025-08-08T16:04:00
tags:
  - STRIKE
  - number-theory
---
Sumber: [1325A - EhAb AnD gCd](https://codeforces.com/problemset/problem/1325/A)

> [!NOTE] ⚔️ Teori STRIKE:
> $$GCD(1,a-1) + LCM(1,a-1)=a$$

<br/>

---
# 1325A - EhAb AnD gCd

Diberikan sebuah bilangan bulat positif $x$.
Temukan dua bilangan bulat positif $a$ dan $b$ sedemikian sehingga:

$$
\text{GCD}(a,b) + \text{LCM}(a,b) = x
$$

Sebagai pengingat:

* $\text{GCD}(a,b)$ adalah bilangan bulat terbesar yang membagi habis $a$ dan $b$.
* $\text{LCM}(a,b)$ adalah bilangan bulat terkecil yang habis dibagi oleh $a$ dan $b$.

Dijamin bahwa solusi selalu ada. Jika terdapat beberapa pasangan $(a,b)$ yang memenuhi, Anda boleh mencetak pasangan mana pun.

<br/>

---
# Sesi STRIKE ⚔️

Ini adalah problem yang sekilas sulit, padahal ez:

```cpp
/*
Author  : trihajikhr
Date    : 2025-08-08 16:00
Problem : Codeforces - 1325A | EhAb AnD gCd
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
      cout << 1 << " " << n - 1 << '\n';
   }
   return 0;
}
```

<br/>

---


# Jawaban dan Editorial

## Analisis Pribadi

Well, solusinya cukup sederhana, lihat saja bagain atas.