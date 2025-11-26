---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 2004A
judul_DEATH: Closest Point
teori_DEATH:
sumber:
  - codeforces.com
rating: 800
ada_tips: false
date_learned: 2025-10-22T10:45:00
tags:
  - implementation
  - math
---
Sumber: [Problem - 2004A - Codeforces](https://codeforces.com/problemset/problem/2004/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 2004A-Closest Point

Diberikan sebuah arrray berukuran $n$. Tentukan apakah mungkin untuk menyisipkan sebuah angka $x$, yang mana $x$ akan menjadi titik terdekat antara $a_{i-1}$ dengan $a_{i+1}$.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Aku pusing dan enah kenapa tidak menemukan solusi yang optimal untuk problem ini. Tapi setelah beberapa kali percobaan, kode ini berhasil:

```cpp
#include<iostream>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> dat(n);
    for (auto& x : dat) {
        cin >> x;
    }

    if (n==2) {
        if (dat[1]-dat[0] == 1) {
            cout << "NO\n";
        } else cout << "YES\n";
        return;
    }

    bool poss = false;
    int diff = dat[1] - dat[0];
    if (diff != 1 && diff != 2 && diff % 2 != 1) {
        poss = true;
        for (int i=0; i<n-1; i++) {
            if ((dat[i+1] - dat[i]) != diff ) {
                poss = false;
                break;
            }
        }

    }
    cout << (poss ? "YES" : "NO") << '\n';
}


auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Masalah ini dapat diselesaikan secara "naif" dengan melakukan iterasi pada titik yang kita tambahkan dan memeriksa bahwa titik tersebut menjadi titik terdekat untuk semua elemen dari himpunan. Namun, ada solusi lain yang lebih cepat dan lebih mudah untuk diimplementasikan.

Ketika kita menambahkan sebuah titik, titik tersebut hanya bisa menjadi yang terdekat untuk dua titik dari himpunan: satu di sebelah kiri, dan satu di sebelah kanan. Jika ada, misalnya, dua titik di sebelah kiri dari titik yang kita tambahkan, maka syarat pada titik paling kiri tidak akan terpenuhi (titik yang kita tambahkan tidak akan menjadi yang terdekat dengannya).

Jadi, jika $n>2$, tidak ada cara untuk menambahkan titik. Jika $n=2$, kita ingin menyisipkan titik baru di antara dua titik yang sudah ada — jadi kita perlu memeriksa bahwa keduanya tidak bersebelahan (tidak berdekatan).

**Catatan:** Frasa "not adjacent" (tidak bersebelahan/tidak berdekatan) pada konteks ini sering merujuk pada kasus di mana dua titik tersebut memiliki jarak lebih dari 1, terutama jika masalahnya melibatkan koordinat bilangan bulat.

Solusi editorial:

```cpp
t = int(input())
for i in range(t):
    n = int(input())
    x = list(map(int, input().split()))
    if n > 2 or x[0] + 1 == x[-1]:
        print('NO')
    else:
        print('YES')
```

## 3.2 | Analisis Pribadi

Dijelaskan didalam editorial, bahwa jika ukuran array adalah $n > 2$, maka mustahil untuk menambahkan nilai $x$ yang bisa menjadi titik terdekat antara $a_{i-1}$ dengan $a_{i+1}$.

Satu-satunya kondisi yang mungkin adalah ketika $n=2$, dan $|a_1-a_2| \neq 1$. Berikut implementasiku:

```cpp
#include<iostream>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) cin >> x;
    if (n > 2) {
        cout << "NO\n";
    } else {
        if (v[1]-v[0] == 1) cout << "NO\n";
        else cout << "YES\n";
    }
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
```
## 3.3 | Analisis Jawaban User Lain

Ide dan konsep dari editorial sudah yang paling efisien. Jawaban pengguna lain tidak jauh berbeda:

### 1 | Jawaban Pertama

```cpp
#include<stdio.h>

int t, n, x[200020], i;
int main() {
    scanf("%d", & t);
    for (; t--;) {
        scanf("%d", & n);
        for (i = 0; i++ < n;) scanf("%d", x + i);
        printf(n < 3 && x[2] - x[1] > 1 ? "YES\n" : "NO\n");
    }
}
```
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;

int t, n, a[55];

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (n == 2 && a[2] - a[1] >= 2) cout << "YES\n";
        else cout << "NO\n";
    }
}
```
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    cout << (n > 2 || (n == 2 && a[0] == a[1]-1) ? "NO\n" : "YES\n");
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
}
```