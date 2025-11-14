---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1934A
judul_DEATH: Too Min Too Max
teori_DEATH:
sumber:
  - codeforces.com
rating: 800
ada_tips: true
date_learned: 2025-10-22T16:43:00
tags:
  - greedy
  - math
---
Sumber: [Problem - A - Codeforces](https://codeforces.com/contest/1934/problem/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1934A-Too Min Too Max

Diberikan array berukuran $n$. Tentukan nilai maksimal dari mengambil $4$ elemen dari array dan melakukan operasi berikut:

$$|a_i - a_j| + |a_j - a_k| + |a_k - a_l| + |a_l - a_i|$$


<br/>

---
# 2 | Sesi Death Ground ⚔️

Untuk mendapatkan nilai selisih maksimal dari syarat yang diberikan, mudah. Kita hanya perlu melakukan sorting, dan selisih maksimal didapat dengan membandingkan $2$ elemen terkecil (*minimal*) dengan $2$ elemen terbesar (*maksimal*).

Berikut adalah implementasinya:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) cin >> x;
    ranges::sort(v);
    int l = 0, r = n-1;
    for (int i=0; i<2; i++) {
        ans += abs(v[l]-v[r]);
        ans += abs(v[l]-v[r-1]);
        l++;
    }
    cout << ans << '\n';
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

**Hint**: Berapakah jawabannya jika hanya ada $4$ elemen dalam *array*?

**Solusi**:
Anggaplah hanya ada $4$ elemen dalam *array*. Biarkan mereka diurutkan menjadi $a \le b \le c \le d$. Maka jawabannya akan menjadi maksimum dari tiga kasus yang tercantum sebagai berikut:

1.  $|a-b| + |b-c| + |c-d| + |d-a| = 2 \cdot d - 2 \cdot a$
2.  $|a-b| + |b-d| + |d-c| + |c-a| = 2 \cdot d - 2 \cdot a$
3.  $|a-c| + |c-b| + |b-d| + |d-a| = \mathbf{2 \cdot (d+c) - 2 \cdot (a+b)}$

Jadi, jelas **$2 \cdot (d+c) - 2 \cdot (a+b)$** adalah nilai maksimumnya.

Oleh karena itu, untuk memaksimalkan nilai ini, kita dapat menetapkan $d$ dan $c$ sebesar mungkin, dan $a$ dan $b$ sekecil mungkin, yaitu $d=a_n$, $c=a_{n-1}$, $b=a_2$ dan $a=a_1$, di mana $a_i$ berarti elemen ke-$i$ dalam urutan terurut dari *array* yang diberikan.

Implementasi editorial:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcases;
    cin >> testcases;
    for (int t = 1; t <= testcases; t++) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int j = 0; j < n; j++) {
            cin >> v[j];
        }
        sort(v.begin(), v.end());
        cout << 2 * (v[n - 1] - v[0]) + 2 * (v[n - 2] - v[1]) << endl;
    }
}
```

## 3.2 | Analisis Pribadi

Solusi dari editorial sudah benar dan efisien, walaupun sedikit berbeda denganku, tapi cukup efisien juga, jadi akan aku anggap sudah benar.
## 3.3 | Analisis Jawaban User Lain

Ide dan konsep dari editorial sudah benar dan efisien, sehingga jawaban dari user lain tidak jauh berbeda:

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;

int t, n, a[101];
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        cout << (a[n] + a[n - 1] - a[1] - a[2] << 1) << endl;
    }
}
```
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;

int t, n, a[101];
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        cout << (a[n] + a[n - 1] - a[1] - a[2] << 1) << endl;
    }
}
```
### 3 | Jawaban Ketiga

```cpp
#include<bits/stdc++.h>
using namespace std;

int n, a[106];
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    cout << a[n - 1] - a[0] + a[n - 2] - a[0] + 
	    a[n - 1] - a[1] + a[n - 2] - a[1] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
```