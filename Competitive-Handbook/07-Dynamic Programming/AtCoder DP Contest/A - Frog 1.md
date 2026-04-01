---
obsidianUIMode: preview
note_type: latihan
judul_problem: A - Frog 1
latihan: dynamic programming dasar
sumber:
  - atcoder.jp
tags:
  - dynamic-programming
date_learned: 2026-04-01T22:38:00
---
Link Sumber: [A - Frog 1](https://atcoder.jp/contests/dp/tasks/dp_a)

---
> [!IMPORTANT]
# A - Frog 1

Terdapat $N$ buah batu, bernomor $1, 2, \dots, N$. Untuk setiap $i$ ($1 \le i \le N$), tinggi dari batu $i$ adalah $h_i$.

Terdapat seekor katak yang awalnya berada di batu $1$. Ia akan mengulangi tindakan berikut beberapa kali untuk mencapai batu $N$:

- Jika katak saat ini berada di batu $i$, lompat ke batu $i+1$ atau batu $i+2$. Di sini, biaya sebesar $|h_i - h_j|$ akan muncul, di mana $j$ adalah batu tujuan mendarat.

Cari minimum kemungkinan total biaya yang dikeluarkan sebelum katak mencapai batu $N$.

**Batasan**

Semua nilai dalam input adalah bilangan bulat.

- $2 \le N \le 10^5$
- $1 \le h_i \le 10^4$

**Input**

Input diberikan dari Standard Input dengan format berikut:

```
N
h1 h2 ... hn
```

**Output**

Cetak minimum kemungkinan total biaya yang dikeluarkan.

**Contoh Input 1**

```
4
10 30 40 20
```

**Contoh Output 1**

```
30
```

Jika kita mengikuti jalur $1 \to 2 \to 4$, total biaya yang dikeluarkan adalah $|10 - 30| + |30 - 20| = 30$.

**Contoh Input 2**

```
2
10 10
```

**Contoh Output 2**

```
0
```

Jika kita mengikuti jalur $1 \to 2$, total biaya yang dikeluarkan adalah $|10 - 10| = 0$.

**Contoh Input 3**

```
6
30 10 60 10 60 50
```

**Contoh Output 3**

```
40
```

Jika kita mengikuti jalur $1 \to 3 \to 5 \to 6$, total biaya yang dikeluarkan adalah $|30 - 60| + |60 - 60| + |60 - 50| = 40$.


<br/>

---
## Jawaban

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
    int n;
    cin >> n;
    vector<int> h(n + 1), dp(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    dp[1] = 0;
    dp[2] = abs(h[2] - h[1]);

    for (int i = 3; i <= n; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[n];
    return 0;
}
```

<br/>

---
## Editorial

Misalkan $f(i)$ menjadi biaya minimum untuk mencapai batu $i$. Karena katak awalnya berada di batu $1$, $f(1)=0$. Satu-satunya cara untuk mencapai batu $2$ adalah dari batu $1$, sehingga $f(2)=|h_1-h_2|$.

Untuk $i > 2$, katak dapat mencapai batu $i$ dari batu $i-1$ atau batu $i-2$, sehingga:

$$f(i) = \min(f(i-1) + |h_{i-1} - h_i|, f(i-2) + |h_{i-2} - h_i|)$$

Kita dapat mengimplementasikan logika di atas menggunakan perulangan (for-loop) untuk menghitung $f(N)$, yaitu biaya minimum untuk mencapai batu $N$. Karena kita melakukan iterasi (*iterate*) pada $N$ kemungkinan nilai $i$, kompleksitas waktu (*time complexity*) adalah $O(N)$.