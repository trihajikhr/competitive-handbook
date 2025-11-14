---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1676C
judul_DEATH: Most Similar Words
teori_DEATH:
sumber:
  - codeforces.com
rating: 800
ada_tips: false
date_learned: 2025-10-22T14:16:00
tags:
  - brute-force
  - greedy
  - implementation
  - math
  - string
---
Sumber: [Problem - 1676C - Codeforces](https://codeforces.com/problemset/problem/1676/C)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1676C-Most Similar Words

Diberikan kumpulan kata sebanyak $n$, dengan panjang yang sama yaitu $m$. Tentukan, untuk setiap kata yang diberikan, nilai selisih paling kecil untuk setiap karakter-karakter yang ada pada $n$ kata yang diberikan. Misal kata $a_i$ dan kata $a_j$ adalah `best` dan `cost`, maka total selisih dari selisih dari tiap karakter adalah:

- $|b-c|=1$
- $|e-o|=10$
- $|s-s|=0$
- $|t-t|=0$

Maka jumlah selisihnya adalah $11$. 

<br/>

---
# 2 | Sesi Death Ground ⚔️

Solusinya mudah, melihat dari batasan input $2 \leq n \leq 50, \; 1 \leq m \leq 8$, maka menggunakan $3$ perulangan bersarang $O(n^3)$ masih memungkinkan untuk membangun solusi.

Caranya mudah, kita hanya perlu menggunakan perulangan pertama untuk menunjuk kata $a_i$, perulangan kedua digunakan untuk menunjuk kata $a_j$ dimana $i<j$, lalu perulangan ketiga digunakan untuk membandingkan tiap karakter dari kata $a_i$ dan $a_j$. Jumlahkan selisih tiap karakater, lalu ambil nilai terkecil.

Berikut adalah implementasiku:

```cpp
#include<iostream>
#include<vector>
using namespace std;

void solve() {
    int n, m, ans = INT_MAX;
    cin >> n >> m;
    vector<string> s(n);
    for (auto& x : s) {
        cin >> x;
    }

    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            int temp = 0;
            for (int k=0; k<m; k++) {
                temp += abs(s[i][k]-s[j][k]);
            }
            ans = min(ans, temp);
        }
    }
    cout << ans << "\n";
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

Pertama, diberikan sepasang *string* dengan panjang $m$ manapun, kita harus dapat mengetahui perbedaan di antara keduanya. Cukup dengan mencari jumlah dari selisih absolut antara setiap karakter dari posisi yang sama. Sekarang, kita harus melalui semua pasangan yang mungkin dan memilih nilai minimum di antara semuanya menggunakan fungsi yang kita gunakan untuk menghitung perbedaan tersebut.

Solusi editorial:

```cpp
#include "bits/stdc++.h"
using namespace std;

int cost(string& a, string& b) {
    int val = 0;
    for(int i = 0; i < a.size(); ++i) {
        val += abs(a[i] - b[i]);
    }
    return val;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<string> s(n);
        for(int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                ans = min(ans, cost(s[i], s[j]));
            }
        }
        cout << ans << "\n";
    }
}
```
## 3.2 | Analisis Pribadi

Ide dan konsep sama. Menggunakan $3$ perulangan bersarang. Solusiku sudah benar dan seharusnya sudah efisien.
## 3.3 | Analisis Jawaban User Lain

Ide dan konsep dari editorial sudah benar dan efisien. Pendekatan yang lain tidak jauh berbeda:

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>

using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i, j, k;
        cin >> n >> m;
        string a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        int s = 1000;
        for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++) {
                int p = 0;
                for (k = 0; k < m; k++) p += abs(a[i][k] - a[j][k]);
                s = min(s, p);
            }
        cout << s << endl;
    }
}
```
### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>
using namespace std;

//2024 ayu;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    char a[50][8];
    cin >> t;
    while (t--) {
        int n, m, mi = 1e9;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int s = 0;
                for (int k = 0; k < m; k++) {
                    s += abs(a[i][k] - a[j][k]);
                }
                mi = min(mi, s);
            }
        }
        cout << mi << "\n";

    }

    return 0;
}
```
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s[n];
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        int dis, ans = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                dis = 0;
                for (int k = 0; k < m; k++) {
                    dis += abs(s[i][k] - s[j][k]);
                }

                ans = min(dis, ans);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
```