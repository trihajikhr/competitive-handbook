---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 318A
judul_DEATH: Even Odds
teori_DEATH:
sumber:
  - codeforces.com
rating: 900
ada_tips:
date_learned: 2025-11-26T12:15:00
tags:
  - math
  - algebra
---
Sumber: [Problem - 318A - Codeforces](https://codeforces.com/problemset/problem/318/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 318A-Even Odds

Diberikan sebuah angka $n$ yang menyatakan sebuah deret angka yang terdiri dari angka dari $1$ hingga $n$. Angka yang ada didalamnya tersusun dengan pola tertentu, dimana semua angka ganjil dari $1$ hingga $n$ ada dibagian paling kiri deret dan tersusun secara ascending. Begitu pula dengan angka genap dari $1$ hingga $n$, terletak pada bagian kanan dari angka ganjil terakhir, dan tersusun secara ascending.

Diberikan inputan kedua yaitu $k$. Tentukan pada posisi $k$ pada susunan angka tadi, angka apa yang ada diposisi tersebut.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Jika $n$ bernilai genap, maka jumlah angka ganjil dan positif adalah sama, tapi jika angka $n$ ganjil, maka jumlah angka ganjil lebih banyak dari jumlah angka genap, yaitu selisih satu angka. Sehingga harus dibuat percabangan untuk menangani kondisi ini.

Karena nilai dari $n$ bisa sampai $10^{12}$, wajib digunakan tipe digunakan tipe data `long long`.

Jika $k \leq n/2$, maka $k$ menunjuk angka ganjil, dan angka tersebut adalah $(k \cdot 2)-1$. Khusus ketika $n$ ganjil, maka ketika aturan awal harus diganti dengan pembulatan keatas $k \leq \lceil n/2 \rceil$.

Jika tidak, maka $k$ menunjuk ke angka genap. Jika $n$ genap, maka posisinya lebih mudah diketahui, yaitu dengan $(k-(n/2)) \cdot 2$. Tapi jika $n$ ganjil, maka angka genap yang ditunjuk adalah $k-((n+1)/2)) \cdot 2$.

Kode ini adalah implementasiku:

```cpp
#include<iostream>
using namespace std;
 
using ll = long long;
 
auto main() -> int {
    ll n, k;
    cin >> n >> k;
 
    if (n%2 == 0) {
        cout << (k <= (n/2) ? (k*2)-1 : (k-(n/2))*2);
    } else {
        cout << (k <= (n+1)/2 ? (k*2)-1 : (k-((n+1)/2))*2);
    }
    return 0;
}
```

Namun kemudian aku menemukan cara untuk memperpendek kode diatas, menjadi lebih singkat dan jelas menjadi seperti ini:

```cpp
#include <iostream>
using namespace std;
 
using LL = long long;
auto main() -> int {
    LL n = 0;
    LL k = 0;
    cin >> n >> k;
 
    if (k <= (n + 1) / 2) {
        cout << (k * 2) - 1;
    } else {
        cout << (k - ((n + 1) / 2)) * 2;
    }
 
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Dalam masalah ini, kita perlu memahami bagaimana tepatnya angka dari 1 sampai $n$ tersusun ulang ketika kita menuliskan semua angka ganjil terlebih dahulu dan setelahnya semua angka genap. Untuk mengetahui angka mana yang berada pada posisi $k$ kita perlu menemukan posisi di mana angka genap mulai muncul dan mengeluarkan entah posisi angka ganjil dari paruh pertama barisan, atau untuk angka genap dari paruh kedua barisan.

## 3.2 | Analisis Pribadi

Jawaban dari kebanyakan user menggunakan percabangan ternary, namun jika dibuat menjadi if-else, maka jawaban ku yang ini sudah benar dan efisien:

```cpp
#include <iostream>
using namespace std;
 
using LL = long long;
auto main() -> int {
    LL n = 0;
    LL k = 0;
    cin >> n >> k;
 
    if (k <= (n + 1) / 2) {
        cout << (k * 2) - 1;
    } else {
        cout << (k - ((n + 1) / 2)) * 2;
    }
 
    return 0;
}
```
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include <iostream>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    cout << (k <= n / 2 + n % 2 ? k * 2 - 1 : (k - n / 2 - n % 2) * 2) << endl;
}
```
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    uint64_t k, n;
    cin >> n >> k;
    cout << ((2 * (k - 1) >= n) ? ((k - n / 2 - n % 2) * 2) : (2 * k - 1));
}
```
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;

long long n, k;
int main() {
    cin >> n >> k;
    if (k <= (n + 1) / 2 ? cout << k * 2 - 1 : cout << (k - (n + 1) / 2) * 2) {}
}
```