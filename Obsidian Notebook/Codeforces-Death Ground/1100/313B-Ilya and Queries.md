---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 313B
judul_DEATH: Ilya and Queries
teori_DEATH:
sumber:
  - codeforces.com
rating: 1100
ada_tips?:
date_learned: 2025-10-19T12:49:00
tags:
---
Sumber: [Problem - 313B - Codeforces](https://codeforces.com/problemset/problem/313/B)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 313B-Ilya and Queries

Diberikan sebuah string $s$ yang hanya terdiri dari karakter . dan juga #. Tugasmu adalah menentukan, dari indeks ke $l$ hingga $r$ yang diberikan sebanyak $q$ queries, berapa jumlah karakter pada rentang tersebut yang memenuhi $s_i = s_{i+1}$.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Menggunakan cara manual akan membawamu pada time limit, yaitu menggunakan nilali $l$ sebagai awal pencarian, dan menggunakan titik $r$ sebagai batas, terlalu sederhana dan tidak efisien, karena kompleksitasnya menjadi $O(n)$ per queries.

Solusi yang efisien adalah dengan menerapkan algoritma *prefix sum*, dimana untuk setiap pasangan $s_i = s_{i+1}$, maka akan menambah hasil dari prefix sum, dan seterusnya hingga akhir.

Karena nilai prefix sum hanya menyimpan jumlah karakter berpasangan, maka untuk batas paling kanan, yaitu $r$, harus dikurangi dengan $1$ atau $r=r-1$ sebelum digunakan sebagai indeks prefix sum. Ini karena pengambilan 2 pasang karakter menjadikan total prefix sum tidak sama dengan panjang string $s$.

Berikut adalah implementasiku:

```cpp
#include<iostream>
#include<string>
#include<vector>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    vector<int> pref(s.length(), 0);
    for (int i=0; i<s.length()-1; i++) {
        pref[i+1] = pref[i] + (s[i] == s[i+1]);
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << pref[r-1] - pref[l-1] << '\n';
    }

    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Hitung di awal (*Precalculate*) sebuah larik $A_i$, di mana $A_i = 1$, jika $s_i = s_{i+1}$, dan $A_i = 0$ jika sebaliknya. Sekarang, untuk setiap kueri $(l, r)$, Anda perlu menemukan jumlah dari $A_i$, di mana $(l \leq i < r)$.

Ini adalah masalah standar. Untuk menyelesaikan masalah ini, Anda dapat menghitung di awal larik lain, $Sum$, di mana $Sum_i = A_1 + A_2 + \dots + A_i$ (yaitu, *prefix sum* dari $A$). Kemudian, jumlah pada interval $(l, r)$ adalah $Sum_r - Sum_{l-1}$.

## 3.2 | Analisis Pribadi

Solusiku menerapkan konsep prefix sum yang sama dengan konsep editorial, jadi menurutku, solusiku seharusnya sudah efisien.
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include<iostream>

int Q, A[100005], L, R, i;
std::string S;

main() {
    std::cin >> S >> Q;
    for (i = S.length() - 2; i >= 0; i--) 
	    A[i] = A[i + 1] + (S[i] == S[i + 1]);
	    
    while (Q--) {
        std::cin >> L >> R;
        std::cout << A[L - 1] - A[R - 1] << "\n";
    }
}
```

Konsepnya sama, menggunakan prefix sum, tapi kode ini menyusun prefix sum dari kanan ke kiri, sedangkan aku menyusun prefix sum dari kiri ke kanan.
### 2 | Jawaban Kedua

```cpp
#import < bits / stdc++.h >
using namespace std;

int i, l, r, q, w[100005];
string s;

main() {
    for (cin >> s; s[++i];) w[i + 1] = w[i] + (s[i - 1] == s[i]);
    for (cin >> q; q--;) {
        cin >> l >> r;
        cout << w[r] - w[l] << endl;
    }
}
```

Menggunakan prefix sum juga, namun logika program dimasukan ke dalam perulangan for. Walaupun tampak simple, namun menjadi lebih sulit dipahami dan menyulitkan ketika terjadi error (*debugging lebih sulit*). Tapi tidak apa-apa, kita masih bisa pelajari sesuatu dari kode ini, yaitu memasukan banyak syntax sekaligus ke dalam perulangan for ternyata bisa menyelesaikan problem ini dengan menggunakan *prefix sum*.
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

void solve()
{
    string s;
    cin >> s;

    ll N = s.length() + 5;

    ll n;
    cin >> n;

    vector<ll> v(N, 0);
    for (ll i = 1; i < s.length(); ++i)
        v[i - 1] = (s[i - 1] == s[i]);

    vector<ll> p(N, 0);
    for (ll i = 0; i < N; ++i)
        p[i] = v[i] + p[i - 1];

    while (n--)
    {
        ll l, r;
        cin >> l >> r;
        l--, r--;

        cout << p[r - 1] - p[l - 1] << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    solve();
    // int t;
    // cin >> t;
    // while (t--)
    //     solve();
}
```

Penyelesaian ini mirip dengan implementasiku, menggunakan prefix sum, dan tetap menggunakan $r-1$ untuk mengatasi batasan prefix sum yang berkurang.