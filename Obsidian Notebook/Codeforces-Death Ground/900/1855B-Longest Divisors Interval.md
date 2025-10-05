---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1855B
judul_DEATH: Longest Divisors Interval
teori_DEATH:
sumber:
  - codeforces.com
ada_tips?:
date_learned: 2025-10-05T20:53:00
tags:
---
Sumber: [Problem - 1855B - Codeforces](https://codeforces.com/problemset/problem/1855/B)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1855B-Longest Divisors Interval



<br/>

---
# 2 | Sesi Death Ground ⚔️

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

**Hint 1**: Apa jawabannya jika $n$ adalah ganjil (odd)?

**Hint 2**: Coba generalisasi Hint 1.

**Hint 3**: Apa jawabannya jika $n$ bukan *multiple* (kelipatan) dari 3?

**Hint 4**: Jika jawabannya bukan *multiple* dari $x$, jawabannya adalah $<x$. Jika jawabannya adalah *multiple* dari $1, \dots, x$, jawabannya adalah $\ge x$.

Misalkan Anda menemukan *interval* yang valid $[l, r]$. Perhatikan bahwa *interval* $[l, r]$ mengandung setidaknya satu *multiple* dari $x$ untuk setiap $1 \le x \le r-l+1$ (Anda dapat mengetahuinya dengan melihat nilai-nilai di $[l, r]$ *modulo* $x$). Maka, *interval* $[1, r-l+1]$ juga valid dan memiliki panjang yang sama.

Jadi, cukuplah untuk memeriksa *interval* dengan $l=1$, yaitu, temukan $x$ terkecil yang tidak membagi $n$. Jawabannya adalah $x-1$.

*Kompleksitas*: $O(\log(\text{maxn}))$

Berikut adalah implementasinya:

```cpp
#include <iostream>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    long long i = 1;
    while (n % i == 0) {
        i++;
    }
    cout << i - 1 << '\n';
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
```

## 3.2 | Analisis Pribadi
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
```
### 2 | Jawaban Kedua

```cpp
```
### 3 | Jawaban Ketiga

```cpp
```