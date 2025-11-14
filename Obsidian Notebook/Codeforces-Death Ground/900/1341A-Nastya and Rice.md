---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1341A
judul_DEATH: Nastya and Rice
teori_DEATH: intersection
sumber:
  - codeforces.com
rating: 900
ada_tips?: true
date_learned: 2025-10-18T16:03:00
tags:
---
Sumber: [Problem - 1341A - Codeforces](https://codeforces.com/problemset/problem/1341/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1341A-Nastya and Rice

Aku buat simple aja disini!

Diberikan sebuah nilai $n,a,b,c,d$. Tentukan apakah persamaan berikut dapat dipenuhi atau tidak:

$$c-d \leq (n \cdot \{x \; | \; a-b \leq x \leq a+b\}) \leq c+d$$

Jika iya, outputkan `Yes`, sebaliknya, outputkan `No`.

*Jika tidak paham dengan penjelasan yang singkat ini, lihat saja laman soalnya!*

<br/>

---
# 2 | Sesi Death Ground ⚔️

Pertama, aku  mencoba menggunakan perulangan, yang dimulai dari $a-b$ hingga $a+b$, dan mencari, untuk setiap nilai yang dikalikan dengan $n$, apakah ada yang berada diantara $c-d \leq x \leq c+d$. 

Namun, daripada mencari nilai yang memenuhi, jauh lebih efisien untuk mencari kemungkinan **yang tidak memenuhi**, yaitu berpikir secara terbalik.

Jika nilai terendah justru melebihi batas maksimal: $n \cdot (a-b) > c+d$, atau nilai tertinggi justru tidak mencapai batas minimal: $n \cdot (a+b) < c-d$, maka artinya tidak ada intersection dari angka $x$ yang memenuhi $c-d \leq x \leq c+d$, sehingga kita bisa outputkan `No`. Sebaliknya, jika dua kondisional diatas tidak terpenuhi, maka akan ada nilai yang memenuhi, sehingga outputkan `yes`.

Berikut kode implementasiku:

```cpp
#include<iostream>
using namespace std;

void solve() {
    int n, a,b,c,d;
    cin >> n >> a >> b  >> c >> d;
    int L = n * (a-b), R = n * (a+b);
    if (R < c-d || L > c + d) cout << "No\n";
    else cout << "Yes\n";
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Kita bisa mendapatkan berat total biji-bijian apa pun dari $n(a-b)$ hingga $n(a+b)$.

Jadi, kita hanya perlu memeriksa bahwa **segmen** (rentang/interval) $[n(a-b); n(a+b)]$ dan $[c-d; c+d]$ **saling berpotongan** (beririsan).

Penjelasan Variabel:

* $n(a-b)$ hingga $n(a+b)$: Rentang berat total yang mungkin dari semua biji-bijian.
* $[n(a-b); n(a+b)]$: Rentang berat yang *tersedia*.
* $[c-d; c+d]$: Rentang berat yang *diinginkan* (target).
* *Saling berpotongan (intersect)*: Berarti ada setidaknya satu nilai berat yang dimiliki oleh kedua rentang tersebut, yang menunjukkan bahwa berat yang diinginkan dapat dicapai.

Implementasi editorial:

```cpp
#include <iostream>
using namespace std;
 
int main() {
	int q;
	cin >> q;
	while (q--) {
		int n, a, b, c, d;
		cin >> n >> a >> b >> c >> d;
		int L = n * (a - b), R = n * (a + b);
		if (R < c - d || c + d < L)
		    cout << "No\n";
		else
		    cout << "Yes\n";
	}
}
```

## 3.2 | Analisis Pribadi

Solusiku ternyata mirip dengan solusi dari editorial, simple dan sama-sama efisien, karena kompleksitasnya konstan, atau $O(1)$.
## 3.3 | Analisis Jawaban User Lain

Karena solusi terbaik adalah yang memiliki kompleksitas konstan, maka jawaban dari user lain pun tidak terlalu jauh berbeda:

### 1 | Jawaban Pertama

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, a, b, c, d;
    for (cin >> t; t--;) {
        cin >> n >> a >> b >> c >> d;
        cout << ((a - b) * n > (c + d) || (a + b) * n < (c - d) ? "No\n" : "Yes\n");
    }
}
```
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, A, B, C, D;
        cin >> N >> A >> B >> C >> D;
        A *= N, B *= N;
        cout << (abs(A - C) <= B + D ? "Yes" : "No") << '\n';
    }
}
```
### 3 | Jawaban Ketiga

```cpp
// ADDITIONAL LIBRARIES
//#include <stdio.h>
//#include <unordered_map>
//#include <stack>
//#include <unordered_set>
//#include <time.h>
//#include <sstream>
//#include <bitset>
//#include <limits>

// MAIN LIBRARIES
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm> 
#include <cmath>

const char el = '\n';
const char sp = ' ';
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout.precision(12);

    int t;
    cin >> t;
    while (t--) {
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        int n1 = n * (a - b), n2 = n * (a + b);
        bool cond = (n1 < c - d && n2 < c - d) || (n1 > c + d && n2 > c + d);
        cout << (!cond ? "Yes" : "No") << el;
    }
}
```