---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1486A
judul_DEATH: Shifting Stacks
teori_DEATH: prefix sum + dynamic programming
sumber:
  - codeforces.com
rating: 900
ada_tips?:
date_learned: 2025-10-09T19:59:00
tags:
---
Sumber:

```ad-tip
title:⚔️ Teori Death Ground
Algoritma kebutuhan balok pada anak tangga:
$$w_i = \frac{(i-1) \cdot i}{2}$$
```

<br/>

---
# 1  1486A-Shifting Stacks

Diberikan sebuah array berukuran $n$, yang mana merepresentasikan banyaknya stack balok. Setiap stack balok ke-$i$, memiliki $h_i$ balok. Jika kita diperbolehkan memindahkan beberapa balok dari stack $i$ ke stack $i+1$, apakah mungkin untuk membuat tumpukan stack tersebut menaik secara ascending?

<br/>

---
# 2 | Sesi Death Ground ⚔️

Untuk membuat balok-balok tersebut menaik, kita perlu tahu bahwa untuk setiap stack membutuhkan jumlah balok minimal yang ada dibagian-bagian kiri dan bagianya, kita sebut saja $w$.

Maksudnya adalah, misal kita memiliki $n=5$, maka:
- Tumpukan $i=1$, nilai $w=0$, karena jika ada satu stack, dan tidak ada balok sama sekali, itu tidak masalah;
- Tumpukan $i=2$, nilai $w=1$, karena kita perlu menyusun $[0,1]$, sehingga Jumlah balok minimal adalah $1$.
- Tumpukan $i=3$, nilai $w=3$, karena kita perlu menyusun $[0,1,2]$. Jumlah balok minimal adalah $3$.
- Tumpukan $i=4$, nilai $w=6$, karena kita perlu menyusun $[0,1,2,3]$. Sehingga jumlah balok minimal adalah $6$.
- Tumpukan $i=5$, nilai $w=10$, karena kita perlu menyusun $[0,1,2,3,4]$, sehingga jumlah balok minimal adalah $10$.

```ad-tip
Kita bisa menggunakan dynamic programming untuk menyusun nilai $w$ dari setiap posisi. Atau, jika tidak ingin menggunakan memory tambahan, bisa menggunakan rumus berikut:

$$w_i = \frac{(i-1) \cdot i}{2}$$
```

Nah, karena pergeseran balok hanya bisa dilakukan ke samping kanan ($i+1$), maka untuk setiap stack $i$, harus terdapat $x_i \geq w_i$, dimana $x_i$ adalah jumlah semua balok yang ada di stack $i$ dan stack-stack  sebelumnya, dan $w_i$ adalah jumlah balok minimum di posisi $i$.

```ad-tip
Kita bisa membangun array *prefix sum* untuk melakukan pengecekan $x_i \geq w_i$ pada setiap $i$ ketika kita melakukan iterasi pada $n$.
```

Artinya, untuk setiap $i$ pada stack, kita perlu memastikan kondisi berikut terpenuhi:

$$\frac{(i-1) \cdot i}{2} \; \geq \; \sum_{i=1}^{i}{h_i}$$
...dimana jika ada satu saja $i$ yang tidak terpenuhi, maka tidak mungkin untuk menyusun stack balok secara ascending.
<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official


**Hint 1**: Berapa batas bawah jumlah balok agar jawabannya **YES**?

**Hint 2**: Periksa predikat untuk setiap *prefix*.

Mari kita pertimbangkan jumlah balok terkecil yang kita perlukan untuk membuat $i$ ketinggian pertama **menaik (ascending)**. Karena ketinggian adalah **non-negatif** dan **menaik**, ketinggiannya harus terlihat seperti $0, 1, 2, 3, \dots, i-1$, sehingga jumlah minimumnya adalah $\frac{(i-1) \cdot i}{2}$.

Ternyata, ini adalah satu-satunya persyaratan. Jika ini tidak berlaku untuk setiap *prefix*, jawabannya adalah **NO** karena kita tidak dapat membuat *prefix* tertentu menaik. Sebaliknya, jawabannya adalah **YA** karena Anda dapat memindahkan balok ke kanan sampai setidaknya ada $i$ balok di tumpukan ke-$i$, dan ini akan membuat ketinggiannya menaik.

Implementasi editorial:

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    long long sum = 0, need = 0;
    for (int i = 0; i < n; ++i) {
        need += i;
        sum += a[i];
        if (sum < need) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
```

## 3.2 | Analisis Pribadi

Kode pertamaku yang berhasil sebelum aku melihat editorial adalah seperti ini:

```cpp
#include<iostream>
#include<vector>
using namespace std;

using ll = long long;
constexpr int SZ = 101;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 1-based index (ALL)!
    vector<ll> dp(SZ);
    dp[0] = 0;
    for (int i=1; i<SZ; i++) {
        dp[i] = (i-1)+dp[i-1];
    }

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> bata(n+1), pref(n+1);
        for (int i=1; i<=n; i++) {
            cin >> bata[i];
            pref[i] = bata[i]+pref[i-1];
        }

        bool poss = true;
        for (int i=2; i<= n; i++) {
            if (dp[i] > pref[i]) {
                poss = false;
                break;
            }
        }
        cout << (poss ? "YES" : "NO") << '\n';
    }
    return 0;
}
```

Aku menggunakan dynamic programming, padahal bisa diganti saja dengan rumus.

Aku juga membangun prefix sum, padahal bisa saja langsung lakukan pengecekan.

Analisis penuh sudah ada dibagian atas. 

## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;

long long t, n, x, y, o, i;
main() {
    cin >> t;
    while (t--) {
        cin >> n;
        y = 0, o = 1;
        for (i = 0; i < n; i++) {
            cin >> x;
            x += y;
            y = x - i;
            if (y < 0) o = 0;
        }
        puts(o ? "YES" : "NO");
    }
}
```
### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>
using namespace std;
void solve();

int main() {
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

void solve() {
	int n;
	cin >> n;
	int64_t cnt = 0;
	bool ok = 1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt += x;
		cnt -= i;
		ok &= cnt >= 0;
	}
	cout << (ok ? "YES\n" : "NO\n");
}
```
### 3 | Jawaban Ketiga

```cpp
#include<bits/stdc++.h>
using namespace std;

inline int read() {
    int res = 0;
    bool zf = 0;
    char c;
    while (((c = getchar()) < '0' || c > '9') && c != '-');
    if (c == '-') zf = 1;
    else res = c - '0';
    while ((c = getchar()) >= '0' && c <= '9') 
	    res = (res << 3) + (res << 1) + c - '0';
	    
    if (zf) return -res;
    return res;
}

signed main() {
    int T = read();
    while (T--) {
        int n = read();
        long long tot = 0;
        bool f = 1;
        for (register int i = 1; i <= n; ++i) {
            int x = read();
            tot += x;
            if (tot < (i - 1) * i / 2) {
                f = 0;
            }
        }
        if (f) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
```

Kode buatan LGM **disorientation**.