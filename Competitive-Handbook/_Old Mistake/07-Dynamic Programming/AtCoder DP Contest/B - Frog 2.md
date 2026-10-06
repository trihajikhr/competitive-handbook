---
obsidianUIMode: preview
note_type: latihan
judul_problem: B - Frog 2
latihan: dynamic programming dasar
sumber:
  - atcoder.jp
tags:
  - dynamic-programming
date_learned: 2026-04-01T23:14:00
---
Link Sumber: [B - Frog 2](https://atcoder.jp/contests/dp/tasks/dp_b)

---
> [!IMPORTANT]
# B - Frog 2

Terdapat $N$ buah batu, bernomor $1, 2, \dots, N$. Untuk setiap $i$ ($1 \le i \le N$), tinggi dari batu $i$ adalah $h_i$.

Terdapat seekor katak yang awalnya berada di batu $1$. Ia akan mengulangi tindakan berikut beberapa kali untuk mencapai batu $N$:

- Jika katak saat ini berada di batu $i$, lompat ke salah satu dari berikut ini: batu $i+1, i+2, \dots, i+K$. Di sini, biaya sebesar $|h_i - h_j|$ akan muncul, di mana $j$ adalah batu tujuan mendarat.

Cari minimum kemungkinan total biaya yang dikeluarkan sebelum katak mencapai batu $N$.

**Batasan**

Semua nilai dalam input adalah bilangan bulat.

- $2 \le N \le 10^5$
- $1 \le K \le 100$
- $1 \le h_i \le 10^4$
    

**Input**

Input diberikan dari Standard Input dengan format berikut:

```
N K
h1 h2 ... hn
```

**Output**

Cetak minimum kemungkinan total biaya yang dikeluarkan.

**Contoh Input 1**

```
5 3
10 30 40 50 20
```

**Contoh Output 1**

```
30
```

Jika kita mengikuti jalur $1 \to 2 \to 5$, total biaya yang dikeluarkan adalah $|10 - 30| + |30 - 20| = 30$.

**Contoh Input 2**

```
3 1
10 20 10
```

**Contoh Output 2**

```
20
```

Jika kita mengikuti jalur $1 \to 2 \to 3$, total biaya yang dikeluarkan adalah $|10 - 20| + |20 - 10| = 20$.

**Contoh Input 3**

```
2 100
10 10
```

**Contoh Output 3**

```
0
```

Jika kita mengikuti jalur $1 \to 2$, total biaya yang dikeluarkan adalah $|10 - 10| = 0$.

**Contoh Input 4**

```
10 4
40 10 20 70 80 10 20 70 80 60
```

**Contoh Output 4**

```
40
```

Jika kita mengikuti jalur $1 \to 4 \to 8 \to 10$, total biaya yang dikeluarkan adalah $|40 - 70| + |70 - 70| + |70 - 60| = 40$.

<br/>

---
## Jawaban

```cpp
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
    int n, k;
    cin >> n >> k;
    vector<int> h(n + 1), dp(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    dp[1] = 0;
    for (int i = 2; i <= min(n, k); i++) {
        dp[i] = abs(h[i] - h[1]);
    }

    for (int i = min(n, k + 1); i <= n; i++) {
        int temp = INT_MAX;
        for (int j = 1; j <= min(k, n); j++) {
            temp = min(temp, dp[i - j] + abs(h[i] - h[i - j]));
        }
        dp[i] = temp;
    }

    cout << dp[n];
    return 0;
}
```

<br/>

---
## Editorial

Misalkan $f(i)$ menjadi biaya minimum untuk mencapai batu $i$. Karena katak awalnya berada di batu $1$, $f(1)=0$.

Untuk $i \ge 2$, katak dapat mencapai batu $i$ dari batu $j$ jika $i-K \le j \le i-1$. Karena tidak ada batu sebelum batu $1$, diperlukan juga $j \ge 1$. Oleh karena itu,

$$f(i) = \min_{\max(i-K, 1) \le j \le i-1} \{f(j) + |h_j - h_i|\}$$

Kita dapat mengimplementasikan logika di atas menggunakan perulangan bersarang (*nested loop*) untuk melakukan iterasi terhadap semua kemungkinan nilai $i$ dan $j$ guna menghitung $f(N)$, yaitu biaya minimum untuk mencapai batu $N$. Karena kita melakukan iterasi pada $N$ kemungkinan nilai $i$, dan setiap perulangan melakukan iterasi paling banyak $K$ kemungkinan nilai $j$, kompleksitas waktu (*time complexity*) adalah $O(NK)$.