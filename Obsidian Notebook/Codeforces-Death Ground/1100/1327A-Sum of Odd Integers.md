---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1327A
judul_DEATH: Sum of Odd Integers
teori_DEATH: menghitung total penjumlahan angka ganjil sebanyak k kali
sumber:
  - codeforces.com
rating: 1100
ada_tips?: true
date_learned: 2025-10-19T15:50:00
tags:
  - math
  - algebra
---
Sumber: [Problem - 1327A - Codeforces](https://codeforces.com/problemset/problem/1327/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1327A-Sum of Odd Integers

Diberikan sebuah angka $n$ dan $k$. Tugasmu adalah menentukan, apakah mungkin untuk menyusun angka ganjil positif sebanyak $k$ angka, dan ketika dijumlahkan maka hasilnya adalah $n$? Jika mungkin, maka outputkan `YES`, sebaliknya `NO`.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Aturan matematika untuk angka ganjil, adalah bahwa kumpulan angka ganjil yang dijumlahkan hanya mungkin menghasilkan total genap jika jumlah angka ganjil adalah genap. Jika jumlah angka ganjil adalah ganjil, maka total penjumlahan semuanya juga pasti ganjil.

Ini artinya, aturan berikut harus terpenuhi:

$$n \text{ mod }2 \equiv k \text{ mod } 2$$

Selain itu, kita juga harus tahu, apakah dengan menyusun $k$ angka ganjil yang dimulai dengan angka ganjil terkecil yaitu $1+3+5, \dots, k$, jumlahnya tidak melebihi $n$, karena jika menggunakan angka ganjil terkecil saja sudah melebihi $n$, maka jelas tidak mungkin untuk menyusun jumlah yang tepat dengan angka ganjil sebanyak $k$.

Hal itu bisa diketahui dengan melihat pola berikut:

$1=1$
$1+3=4$
$1+3+5=9$
$1+3+5+7=16$
$1+3+5+7+9=25$
$1+3+5+7+9+11=36$
$1+3+5+7+9+11+13=49$

Rumus penjumlahan $k$ angka ganjil yang dimulai dari $1$ hingga angka ganjil ke-$6$: $k^2$.

Intuisiku, mengatakan bahwa selama 2 syarat diatas tidak dilanggar, maka mungkin untuk menyusun $k$ angka ganjil yang memiliki jumlah $n$, yang mana ternyata intuisiku benar.

Berikut adalah implementasiku:

```cpp
#include<iostream>
using namespace std;

using LL = long long;
void solve() {
    LL n, k;
    cin >> n >> k;
    if ((k*k) > n || (n%2) != (k%2)) {
        cout << "NO\n";
    } else cout << "YES\n";
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


Pertama-tama, perhatikan bahwa jumlah dari $k$ bilangan ganjil pertama adalah $k^2$.

Jika $k^2 > n$, maka jawabannya jelas "NO". Dan jika $n \bmod 2 \neq k \bmod 2$, maka jawabannya juga "NO" ($\bmod$ adalah operasi modulo).

Jika kondisi-kondisi tersebut tidak terpenuhi, jawabannya selalu "YES" (YA) dan akan terlihat seperti ini: $[1, 3, 5, \dots, 2(k-1)-1, \text{rem}]$, di mana $\text{rem} = n - \sum_{i=1}^{k-1} (2i-1)$.

Nilai *rem* (sisa) ini jelas lebih besar dari $2(k-1)-1$ karena $k^2 \leq n$, dan jelas merupakan bilangan ganjil karena paritas dari $n$ dan $k$ adalah sama.

**Penjelasan Istilah Kunci:**

* **$k$ bilangan ganjil pertama:** Deret bilangan ganjil yang dimulai dari 1 (yaitu: $1, 3, 5, \dots$).
* **$n \bmod 2$ dan $k \bmod 2$:** Modulo 2 ($X \bmod 2$) menghasilkan 0 jika $X$ adalah bilangan genap, dan 1 jika $X$ adalah bilangan ganjil. Paritas ($n \bmod 2 \neq k \bmod 2$) berarti $n$ dan $k$ harus memiliki jenis bilangan yang sama (sama-sama ganjil atau sama-sama genap).
* **$\sum_{i=1}^{k-1} (2i-1)$:** Ini adalah notasi sigma untuk menjumlahkan $(k-1)$ bilangan ganjil pertama. Jumlah ini setara dengan $(k-1)^2$.
* **rem:** Sisa yang tersisa ($n$ dikurangi jumlah dari $(k-1)$ bilangan ganjil pertama), yang digunakan sebagai elemen terakhir dalam larik.

Implementasi editorial (python):

```py
for i in range(int(input())):
    n, k = map(int, input().split())
    print('YES' if k * k <= n and n % 2 == k % 2 else 'NO')
```
## 3.2 | Analisis Pribadi

Solusiku dengan jawaban dari editorial ternyata sudah tepat dan benar.
## 3.3 | Analisis Jawaban User Lain

Jawabanku dan ide konsep dari editorial sudah merupakan solusi yang paling efisien, sehingga jawaban dari user lain tidak jauh berbeda:

### 1 | Jawaban Pertama

```cpp
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        unsigned long long a, b;
        cin >> a >> b;
        cout << (a >= b * b && a % 2 == b % 2 ? "YES\n" : "NO\n");
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
        long long n, k;
        cin >> n >> k;

        if (n % 2 == k % 2 && k * k <= n) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
```
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        long long a = 1 ll * k * k;
        if (n >= a and(n - a) % 2 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
```