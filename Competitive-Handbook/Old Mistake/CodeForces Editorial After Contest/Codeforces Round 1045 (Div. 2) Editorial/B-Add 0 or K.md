---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 
judul_STRIKE: 
teori_STRIKE: 
sumber: 
ada_tips?: 
date_learned: 
tags:
  - STRIKE
---
Sumber:

```ad-tip
title:⚔️ Teori STRIKE
```

<br/>

---
# 1 | Judul

<br/>

---
# 2 | Sesi STRIKE ⚔️



#tips-trick 
<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official


Masalah ini ekuivalen dengan mencari sebuah array berisi $n$ bilangan bulat tak negatif
$c_1, c_2, \dots, c_n$ sedemikian sehingga $0 \leq c_i \leq k$ untuk $1 \leq i \leq n$ dan

$$
\gcd(a_1 + k \cdot c_1, \; a_2 + k \cdot c_2, \; \dots, \; a_n + k \cdot c_n) > 1
$$

Idenya sebagai berikut. Jika kita bisa menemukan sebuah bilangan bulat $g > 1$ dan bilangan-bilangan bulat $c_1, c_2, \dots, c_n$ sedemikian sehingga setiap $a_i + k \cdot c_i$ habis dibagi oleh $g$ (untuk $1 \leq i \leq n$), maka kondisi GCD tersebut akan terpenuhi.

Ada (setidaknya) dua cara untuk membangun solusi seperti itu. Cara yang paling sederhana adalah mengambil $g = k + 1$, dan mendefinisikan $c_i = a_i \bmod (k+1)$.

Ini berhasil karena

$$
a_i + k \cdot c_i \equiv c_i + k \cdot c_i \equiv (k+1) \cdot c_i \equiv 0 \pmod{k+1}
$$

Sehingga setiap suku habis dibagi oleh $k+1$.


Alternatifnya, kita juga bisa menemukan bilangan bulat terkecil $x$ sedemikian sehingga $\gcd(x, k) = 1$, dan tetapkan $g = x$.

Perhatikan bahwa $g \leq 29$, karena $k \leq 10^9$ dan hasil kali semua bilangan prima dari 2 sampai 29 sudah melebihi $10^9$.

Kemudian, untuk setiap $a_i$, kita dapat menambahkan $k$ berulang kali sampai habis dibagi oleh $g$. Bahkan, nilai $c_i$ bisa ditentukan secara eksplisit (meskipun hal itu tidak diwajibkan), yaitu:

$$
a_i + k \cdot c_i \equiv 0 \pmod g 
\quad \Longrightarrow \quad 
c_i \equiv (-a_i \cdot k^{-1}) \pmod g
$$

di mana $k^{-1}$ adalah invers perkalian dari $k$ modulo $g$.

Dengan demikian, melalui salah satu dari kedua metode ini, kita selalu bisa membangun array yang valid sehingga

$$
\gcd(\text{bilangan-bilangan hasil}) > 1
$$
<br/>

Ada dua solusi untuk tantangan ini, berikut adalah cara pertama:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto &i : a) {
      cin >> i;
      i += (i % (k + 1)) * k;
    }
    for (auto i : a)
      cout << i << ' ';
    cout << '\n';
  }
}
```

Berikut adalah cara kedua:

```cpp
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto &i : a) {
      cin >> i;
    }

    for (int g = 2;; g++) {
      if (gcd(g, k) != 1)
        continue;
      for (auto &i : a) {
        while (i % g != 0)
          i += k;
      }
      for (auto i : a)
        cout << i << ' ';
      cout << '\n';
      break;
    }
  }
}
```
## 3.2 | Analisis Pribadi
## 3.3 | Analisis Jawaban User Lain