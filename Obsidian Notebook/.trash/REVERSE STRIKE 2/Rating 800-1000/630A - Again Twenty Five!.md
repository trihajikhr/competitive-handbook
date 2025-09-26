---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 630A - Again Twenty Five!
judul_FAST: Again Twenty Five!
teori_FAST: 2 digit terakhir dari basis 5 yang dipangkatkan
sumber:
  - codeforces
date_learned: 2025-08-08T00:34:00
tags:
  - STRIKE
  - number-theory
---
Sumber: [630A - Again Twenty Five!](https://codeforces.com/problemset/problem/630/A)

> [!NOTE] ⚔️ Teori STRIKE:
> Angka 5, ketika dipangkatkan berapapun, 2 digit terakhirnya pasti 25, bahkan seadaianya angka 5 dipangkatkan dengan $n$ dimana $n$ memiliki nilai hingga $2 \cdot 10^{18}$

<br/>

---
# Again Twenty Five!

Soal meminta kita untuk mencari 2 digit terakhir dari angka 5 yang dipangkatkan dengan $n$ dimana $n$ berasal dari inputan user!

<br/>

---
# Sesi STRIKE ⚔️

Well, terima inputan sebagai string, dan outputkan langsung saja 25. Itu sudah sesuai!

```cpp
/*
Author  : trihajikhr
Date    : 2025-08-08 00:30
Problem : Codeforces - 630A | Again Twenty Five!
*/

#include <iostream>

auto main() -> int {
   std::string s;
   std::cin >> s;
   std::cout << 25;
   return 0;
}

```

<br/>

---


# Jawaban dan Editorial
Kamu bisa mencobanya sendiri dengan menggunakan kalkulator, bahwa benar bahwa angka 5 yang dipangkatkan dengan berapapun, hasilnya pasti memiliki 2 digit terakhir berupa 25!

## Analisis Pribadi