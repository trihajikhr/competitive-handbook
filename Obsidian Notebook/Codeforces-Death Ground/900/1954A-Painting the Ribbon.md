---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1954A
judul_DEATH: Painting the Ribbon
teori_DEATH:
sumber:
  - codeforces.com
rating: 900
ada_tips?:
date_learned: 2025-10-09T18:40:00
tags:
---
Sumber: [Problem - 1954A - Codeforces](https://codeforces.com/problemset/problem/1954/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1954A-Painting the Ribbon

Diberikan sebuah pita sebanyak $n$ potong. Kita bisa mewarnai pita tersebut menjadi sebanyak $m$ warna.

Alice ingin pita tersebut memiliki warna-warna yang berbeda. Sedangkan Bob sebaliknya, Dia ingin pita-pita tersebut memiliki warna yang sama. Pewarnaan pita tersebut pertama-tama dilakukan oleh Alice, kemudian akan dicat kembali oleh Bob, dimana ia akan mengecat paling banyak $k$ pita saja. 

Alice bisa mewarnai semua pita tersebut dengan susunan apapun, namun dia akan berusaha supaya Bob tidak bisa membuat semua pita tadi sama warna. 

Tugas kita adalah menentukan, dengan ketiga nilai yang diberikan, apakah Alice bisa membuat pita tersebut berbeda warna? 

<br/>

---
# 2 | Sesi Death Ground ⚔️

Ada intuisi sederhana disini.

Supaya tujuan Alice tercapai, dia harus menggunakan semua $m$ warna yang tersedia dalam komposisi yang (jika bisa) sama untuk semua $n$ pita. Ini karena, jika kita menyebar warna sebanyak mungkin pada semua pita, maka Bob harus bekerja lebih banyak untuk mewarnai pita-pita tersebut, padahal dia hanya boleh mengecat ulang $k$ pita saja.

Jika $n=50$ dan $m=10$, maka apa yang harus Alice lakukan adalah dengan mengecat semua $n$ pita dengan $m$ warna, dengan cara $n/m$, yaitu $\frac{50}{10}=5$. Sekarang, warna yang sama pada kumpulan $n$ pita paling besar adalah $5$ pita masing-masing. Ini artinya, Bob harus mengecat ulang sebanyak $50-5=45$ pita, untuk bisa membuat semua pita berwarna sama.

Tapi, jika $n \; \text{mod} \; m \neq 0$ , maka pasti akan ada satu kumpulan pita berwarna sama dengan jumlah satu pita lebih banyak dari yang lainya, dan Bob akan memanfaatkan hal tersebut. Artinya, jika terdapat kondisi $n \; \text{mod} \; m \neq 0$, maka kita harus membulatkanya keatas.

Sehingga, jika variable $w$ adalah variabel yang menyimpan banyaknya pita yang harus dicat ulang oleh Bob untuk menjadikan semua pita berwarna sama, maka kita bisa menggunakan rumus:
$$ w= (n- \lceil \frac{n}{m} \rceil)   \;\; \begin{cases}
\text{YES} &\text{if } w > k \\
\text{NO} &\text{if } w \leq k
\end{cases}$$

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Kapan **Bob** bisa mendapatkan pita di mana setiap bagian memiliki **warna $i$**? Harus ada setidaknya **$n-k$** bagian dengan **warna $i$**. Jadi, jika jumlah bagian dengan warna $i$ kurang dari $n-k$, Bob tidak dapat mengecat ulang seluruh pita menjadi warna $i$.

Jadi, **Alice** harus mengecat pita sedemikian rupa sehingga untuk setiap warna, terdapat paling banyak **$n-k-1$** bagian dari warna tersebut. Ada setidaknya dua cara untuk memeriksa apakah ini mungkin: misalnya, Anda dapat menghitung **panjang maksimum yang mungkin** dari pita sedemikian rupa sehingga tidak mengandung lebih dari $n-k-1$ bagian dari setiap warna; atau Anda dapat menghitung **jumlah maksimum bagian di antara semua warna** jika Anda mencoba mewarnai pita se-merata mungkin.

Implementasi (python):

```cpp
t = int(input())
for i in range(t):
    n, m, k = map(int, input().split())
    max_color = (n + m - 1) / m
    if max_color + k >= n:
        print('NO')
    else:
        print('YES')
```

## 3.2 | Analisis Pribadi

Semua analisisku mengarah ke solusi yang benar. Jadi, berikut implementasiku:

```cpp
#include<iostream>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if ((n-((n+m-1)/m)) <= k) cout << "NO\n";
    else cout << "YES\n";
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
```
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include <iostream>
using namespace std;

int main() {
    short int tc, n, m, k;
    cin >> tc;
    for (; cin >> n >> m >> k;) cout << (m * (n - 1 - k) >= n ? 
    "YES" : "NO") << '\n';
}
```

Jika kita membagi, dan kemudian mengurangi, program ini menggunakan pendekatan terbalik, yaitu mengurangi dan mengalikan. 
### 2 | Jawaban Kedua

```cpp
#include<cstdio>

int T, n, m, k;
int main() {
    scanf("%d", & T);
    while (T--) {
        scanf("%d%d%d", & n, & m, & k);
        printf("%s\n", (n + m - 1) / m + k < n ? "YES" : "NO");
    }
}
```

Solusi dari kebanyakan jawaban berada di sekelliling solusi yang diberikan editorial, jadi ini juga hampir sama, hanya saja operasinya dipindahkan untuk menjumlahkan, bukan mengurangi.
### 3 | Jawaban Ketiga

```cpp
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define el '\n'
#define fi first
#define se second
using namespace std;
//const ll MOD = 1e9 + 7;
int n , m , k;


void xuly()
{
    string ans = "NO";
    cin >> n >> m >> k;
    int x = n/m;
    int t = (m-1)*x;
    if(n%m != 0) t += n%m - 1;
    if(t > k) ans = "YES";
    cout << ans << el;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(".inp","r",stdin);freopen(".out","w",stdout);
    int t ; cin >> t;
    while(t--)xuly();
    return 0;
}

```

Solusi ini juga bisa digunakan! Ibaratnya sama saja seperti analisis kita, mencari $w$ (jumlah pita yang harus diwarnai untuk menjadikan Bob mampu menyamakan semua warna pita), dan membandingkan nilainya dengan $k$, banyaknya pita yang bisa diwarnai oleh Bob.