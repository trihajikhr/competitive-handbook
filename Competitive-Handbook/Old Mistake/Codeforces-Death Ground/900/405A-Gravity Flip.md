---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 405A
judul_DEATH: Gravity Flip
teori_DEATH:
sumber:
  - codeforces.com
rating: 900
ada_tips:
date_learned: 2025-11-26T12:46:00
tags:
  - greedy
  - implementation
  - sortings
  - algorithm
---
Sumber: [Problem - 405A - Codeforces](https://codeforces.com/problemset/problem/405/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 405A-Gravity Flip

Diberikan sebuah array berukuran $n$, yang setiap $a_i$ menyatakan jumlah balok yang tertumpuk pada posisi $i$. Sekarang, semisal gravitasi dipindah menjadi di arah kanan, maka balok-balok tersebut akan saling berpindah, karena adanya gravitasi yang berbeda.

Tentukan banyaknya balok pada setiap posisi setelah proses tersebut.

(*lihat soal secara langsung untuk gambar ilustrasi yang lebih detail*).

<br/>

---
# 2 | Sesi Death Ground ⚔️

Jangan pusing, soal ini mudah, kita hanya perlu mengurutkan array secara ascending, karena jika gravitasi dipindah ke kanan, maka semua balok akan berpindah ke kanan menempati ruang kosong yang ada. Sehingga program sesederhana ini sudah menjadi solusi final:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
auto main() -> int {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) cin >> x;
    ranges::sort(v);
    for (const auto& x : v) {
        cout << x << " ";
    }
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Amati bahwa dalam konfigurasi akhir, tinggi kolom berada dalam urutan tidak menurun / *ascending*. Juga, jumlah kolom dari setiap ketinggian tetap sama. Ini berarti bahwa jawaban dari masalah ini adalah **urutan terurut** dari ketinggian kolom yang diberikan.

Kompleksitas solusi: $O(n)$, karena kita dapat mengurutkan *counting sort*.

## 3.2 | Analisis Pribadi

Jawabanku sudah benar, cuma tinggal urutkan saja\.

## 3.3 | Analisis Jawaban User Lain

Karena solusi final adalah tinggal mengurutkan, perbedaan jawaban hanya terletak pada bagaimana cara mengurutkan atau algoritma sorting yang digunakan. Namun kebanyakan menggunakan algoritma sorting STL yang memang jelas lebih cepat daripada implementasi manual.

### 1 | Jawaban Pertama

```cpp
# include < bits / stdc++.h >
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int x: a)
        cout << x << " ";
}
```
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
```
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (auto u: a) cout << u << " ";
}
```