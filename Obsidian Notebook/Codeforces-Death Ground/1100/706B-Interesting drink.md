---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 706B
judul_DEATH: Interesting drink
teori_DEATH:
sumber:
  - codeforces.com
rating: 1100
ada_tips?:
date_learned: 2025-10-19T11:46:00
tags:
---
Sumber: [Problem - 706B - Codeforces](https://codeforces.com/problemset/problem/706/B)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 706B-Interesting drink

Diberikan $n$ toko, dimana toko-toko ini menjual minuman yang akan kita beli. Setiap toko memiliki harga jual yang berbeda, dimana $a_i$ adalah harga dari minuman Beecola yang dijual di toko tersebut.

Diberikan $q$ queries, dimana kita diberikan jumlah koin yang berbeda-beda sebanyak $q$. Tugas kita adalah menentukan, seberapa banyak minuman yang dapat dibeli seadainya kita diberikan koin sebanyak $q_i$ koin. 

<br/>

---
# 2 | Sesi Death Ground ⚔️

Karena hanya diberikan satu sample toko sebanyak $n$, dan lalu selanjutnya kita hanya perlu menghitung operasi  per queries $q$, maka kita harus menggunakan cara yang efisien. Kompleksitas akan membengkak jika dilakukan pencarian secara manual, yaitu menghitung banyaknya elemen  $a_i \leq q_i$ secara langsung.

Solusinya, kita bisa sorting terlebih dahulu $n$ toko, lalu gunakan fungsi `upper_bound` untuk mencari indeks elemen terakhir yang tidak melebihi $q_i$. Penggunaan fungsi ini juga efisien, karena menggunakan mekanisme pencarian binary search dibelakangnya.

Berikut adalah implementasiku:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> vec(n);
    for (auto& x : vec) cin >> x;
    ranges::sort(vec);
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        int idx = ranges::upper_bound(vec, x) - vec.begin();
        cout << idx << '\n';
    }
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official
Pertimbangkan $c[x]$ sebagai jumlah toko di mana harga per minuman adalah $x$. Kita hitung *prefix sum* (*jumlah awalan*) dari larik (array) ini. Kemudian, pilihan-pilihan berikut:

1. Jika jumlah uang saat ini ($m$) lebih besar dari ukuran larik *prefix sum* tersebut, maka jawabannya adalah $n$.
2. Jika tidak, jawabannya adalah $c[m]$.

Kompleksitas Waktu: $O(n+q)$.

## 3.2 | Analisis Pribadi

Menuurtku, jawaban pertamaku sudah benar dan efisien.
## 3.3 | Analisis Jawaban User Lain

Sorting, lalu menggunakan fungsi `upper_bound()` sepertinya merupakan solusi yang pendek dan efisien. Tidak heran kenapa banyak user lain yang memiliki jawaban yang serupa:

### 1 | Jawaban Pertama

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, i, a[100005];
int main() {
    for (cin >> n; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (cin >> i; cin >> i;) cout << upper_bound(a, a + n, i) - a << endl;
}
```
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q, j, ans;
    cin >> n;
    int x[n];
    for (int i = 0; i < n; i++) cin >> x[i];
    cin >> q;
    sort(x, x + n);
    while (q--) {
        cin >> j;
        ans = upper_bound(x, x + n, j) - x;
        cout << ans << endl;
    }
}
```
### 3 | Jawaban Ketiga

```cpp
#include<bits/stdc++.h>
using namespace std;

using ll = long long int;
int sarder() {
    int n;
    cin >> n;
    vector < int > a(n);
    int cnt;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int q;
    cin >> q;
    while (q--) {
        ll x;
        cin >> x;
        int cnt = upper_bound(a.begin(), a.end(), x) - a.begin();
        cout << cnt << "\n";
        cnt = 0;
    }
    return 0;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sarder();
    return 0;
}
```