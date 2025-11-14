---
obsidianUIMode: preview
note_type: latihan
latihan: Binary Exponentiation
sumber:
  - myself
tags:
  - cp-algorithms-
date_learned: 2025-10-24T21:30:00
---
---

# 1 | Binary Exponentiation

Kita tahu bahwa untuk mendapatkan nilai dari $a^n$, maka bisa dilakukan perkalian $a$ sebanyak $n-1$ kali untuk mendapatkan hasilnya, namun ini adalah cara naif. 

## 1.1 | Basic Implementation
Oleh karena itu, carilah hasil dari $a^n$ dengan menggunakan kompleksitas $O(n)$, yang juga dibandingkan dengan pendekatan *binary exponentiation* dengan kompleksitas $O(\log n)$.

Lalu gunakan juga pendekatan selain *binary exponentiation*, yaitu cara rekursif yang menerapkan aturan berikut:

$$a^n = \begin{cases} 1 &\text{jika } n == 0 \\ \left(a^{\frac{n}{2}}\right)^2 &\text{jika } n > 0 \text{ dan } n \text{ genap}\\ \left(a^{\frac{n - 1}{2}}\right)^2 \cdot a &\text{jika } n > 0 \text{ dan } n \text{ ganjil}\\ \end{cases}$$


Pada tahap awal pengenalan dan latihan ini, diberikan kemudahan dimana tidak ada batasan input atau syarat apapun, silahkan outputkan jawaban dengan caramu sendiri.

## 1.2 | Effective computation of large exponents modulo a number
Kamu diberikan $3$ angka yaitu $x$ $(1 \leq x \leq 10^{9}$), $n$ $(1 \leq n \leq 10^{9})$, dan juga angka $m$ $(1 \leq m \leq 100)$.  Hitunglah operasi $x^n \bmod m$ dari inputan yang diberikan. 

Input:

```
10
2 5 5
2 10 20
5 90 8
5 7 8 12
180 83 15
123458 98 5
1547876593 84672957384 90
78423 89 5
324514 101 11
758341491 1283149 3
```

Output:

```
2
4
1
5
70
85
9049349661
1
78
1280322
```

## 1.3 | Effective computation of Fibonacci numbers


<br/>

---
# 2 | Jawaban

## 2.1 | Basic Implementation

Berikut adalah penerapan dasar untuk berbagai cara perpangkatan:

```cpp
#include<iostream>
#include<cmath>
using namespace std;

using LL = long long;

LL naifpow(LL a, LL n) {
    LL rest = a;
    for (int i=1; i<n; i++) {
        rest *= a;
    }
    return rest;
}

LL binpow(LL a, LL b) {
    LL rest = 1;
    while (b > 0) {
        if (b & 1) {
            rest *= a;
        }
        a *= a;
        b >>= 1;
    }
    return rest;
}

LL rekurpow(LL a, LL n) {
    if (n==0) return 1LL;
    LL rest = rekurpow(a, n / 2);
    if (n % 2)
        return rest * rest * a;
    else
        return rest * rest;
}

int main() {
    LL a, n;
    cin >> a >> n;
    cout << "Cara naif (O(n)): " << naifpow(a,n) << '\n';
    cout << "Cara binary (O(log n)): " << binpow(a,n) << '\n';
    cout << "Cara rekursif (O(log n)): " << rekurpow(a,n) << '\n';
    return 0;
}
```

## 2.2 | Effective computation of large exponents modulo a number

Operasi modulo tidak mengganggu perkalian, sehingga cukup menggunakan kode yang sama, tetapi menambahkan perkalian modulo:

```cpp
#include<iostream>
using namespace std;

using ll = long long;
ll binpow(ll a, ll n, ll m) {
    a %= m;
    ll rest = 1;
    while (n > 0) {
        if (n & 1) rest = rest * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return rest;
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long a, n, m;
        cin >> a >> n >> m;
        cout << binpow(a,n,m) << '\n';
    }
    return 0;
}
```

## 2.3 | Effective computation of Fibonacci numbers

<br/>

---
# 3 | Editorial

Penjelasan semua jawaban diatas ada pada materi [[CP-Algorithm Site/01-Algebra/01-Fundamentals/01-Binary Exponentiation|01-Binary Exponentiation]]
