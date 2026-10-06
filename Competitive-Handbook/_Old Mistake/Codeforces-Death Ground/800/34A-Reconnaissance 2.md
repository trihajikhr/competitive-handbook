---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 34A
judul_DEATH: Reconnaissance 2
teori_DEATH:
sumber:
  - codeforces.com
rating: 800
ada_tips: false
date_learned: 2025-10-22T12:29:00
tags:
  - implementation
---
Sumber: [Problem - 34A - Codeforces](https://codeforces.com/problemset/problem/34/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 34A-Reconnaissance 2

Diberikan array berukuran $n$, yang sebenarnya berbentuk lingkaran (*elemen pertama berjejeran dengan elemen terakhir*). Cari pasangan array yang selisih terkecil, dan outputkan indeksnya. Jika ada lebih dari satu jawaban, maka outputkan salah satunya.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Solusi dari soal ini mudah, kita bisa menyimpanya dengan menggunakan array, lalu melakukan traversal terhadap array, dan jika ada selisih antara dua buah elemen array yang lebih kecil daripada nilai yang disimpan, maka perbarui indeksnya. Aku menggunakan array 1-based index, supaya lebih mudah.

Namun ada solusi yang jauh lebih efisien, yaitu tanpa menyimpan array sama sekali, dimana pencarian elemen bertetanggaan terkecil cukup dilakukan ketika menerima inputan. Kita hanya perlu menyimpan elemen pertama, sebelum (*ketika traversal*), dan elemen terakhhir.

Berikut implementasinya:

```cpp
#include<iostream>
#include<algorithm>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, p, mins = INT_MAX, d, c;
    cin >> n;
    for (int i=1, x; i <= n; i++) {
        cin >> x;
        if (i==1) {
            a = x;
        } else {
            int diff = abs(x - p);
            if (diff < mins) {
                mins = diff;
                d = i - 1;
                c = i;
            }
        }
        p = x;
    }

    if (abs(a-p) < mins) {
        d=1, c=n;
    }

    cout << d << " " << c << "\n";
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

"Menemukan minimum dalam *array* (larik), dengan satu perbandingan tambahan antara elemen pertama dan elemen terakhir."

## 3.2 | Analisis Pribadi

Soal ini mudah, jadi tidak perlu dibahas terlalu jauh.
## 3.3 | Analisis Jawaban User Lain

Gaya penulisan berbeda, tapi kebanyakan ide dan konsep tetap sama:

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, c, b, d;
    cin >> n;
    int a[n];
    for (int i = 0; i <= n - 1; i++)
        cin >> a[i];
    int min = abs(a[0] - a[n - 1]);
    b = 1;
    d = n;
    for (int i = 0; i <= n - 2; i++) {
        c = abs(a[i + 1] - a[i]);
        if (min > c) {
            min = c;
            b = i + 1;
            d = i + 2;
        }
    }
    cout << b << " " << d;
}
```
### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll n;
    cin >> n;
    int sum = n - 1, ans = 0;
    int a[n + 5];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        if (abs(a[sum] - a[ans]) > abs(a[i] - a[i + 1])) {
            sum = i;
            ans = i + 1;
        }
    }
    cout << sum + 1 << " " << ans + 1;
}
```
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    int indx1 = 1;
    int indx2 = n;
    int d = abs(a[0] - a[n - 1]);
    int b = d;
    for(int i = 1;i < n;i++) {
        int k = abs(a[i] - a[i - 1]);
        if(k < b) {
            b = k;
            indx1 = i;
            indx2 = i + 1;
        }
    }
    cout << indx1 << " " << indx2 << endl;
    return 0;
}
```