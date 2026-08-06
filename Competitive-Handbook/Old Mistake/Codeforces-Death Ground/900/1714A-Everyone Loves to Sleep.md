---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1714A
judul_DEATH: Everyone Loves to Sleep
teori_DEATH: jam dengan format 24 jam
sumber:
  - codeforces.com
rating: 900
ada_tips?: true
date_learned: 2025-10-18T12:09:00
tags:
  - algorithm
---
Sumber: [Problem - 1714A - Codeforces](https://codeforces.com/problemset/problem/1714/A)

```ad-tip
title:⚔️ Teori Death Ground
Mensimulasikan format jam 24 jam!
```

<br/>

---
# 1 | 1714A-Everyone Loves to Sleep

Aku diberikan nilai $n,H,M$, dimana nilai $n$ menyatakan banyaknya alarm yang terpasang, dan nilai dari $H$ adalah jam sekarang, dan $M$ adalah menit sekarang.

Sebanyak $n$ baris berikutnya, akan menunjukan nilai $h_i$ dan $m_i$, yang menunjukan bahwa alarm ke-$i$ akan berbunyi. Tugasku adalah menetukan, alarm mana yang akan menyalan terlebih dahulu setelah aku tidur. Jika ada alarm yang berbunyi dengan waktu yang sama dengan waktu aku tidur, maka jawabanya adalah $0 \; 0$. Outputkan jawaban dengan format $jam$ $menit$.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Aku kesulitan untuk mensimulasikan waktu yang dibutuhkan, karena hanya benar di beberapa test case saja.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official


Untuk memulainya, mari kita pelajari cara menentukan **berapa banyak waktu yang harus berlalu sebelum alarm ke-$i$ berbunyi**. Jika waktu alarm lebih lambat daripada waktu saat ini, maka jelas $\text{60} \times (h_i - H) + m_i - M$ menit harus berlalu. Jika tidak, nilai ini akan negatif, dan kemudian harus berlalu $\text{24} \times \text{60} + \text{60} \times (h_i - H) + m_i - M$ karena **sehari penuh harus berlalu**, tidak termasuk waktu dari alarm hingga waktu saat ini. Kita hanya perlu menemukan **jumlah menit minimum** di antara semua jam alarm.

Karena batasan yang kecil, masalah ini juga dapat diselesaikan dengan **mensimulasikan proses tidur**: tambahkan $\text{1}$ ke jawaban dan periksa apakah ada alarm yang akan berbunyi setelah waktu ini.

Penjelasan Singkat Istilah:

* $h_i$: jam alarm ke-$i$
* $H$: jam saat ini
* $m_i$: menit alarm ke-$i$
* $M$: menit saat ini
* $\text{60} \times (h_i - H) + m_i - M$: Perbedaan waktu dalam menit jika alarm masih dalam hari yang sama.
* $\text{24} \times \text{60} + \text{60} \times (h_i - H) + m_i - M$: Perbedaan waktu dalam menit jika alarm berbunyi pada hari berikutnya (24 jam + perbedaan waktu).
* "Constrains": Batasan (biasanya merujuk pada batasan nilai input dalam masalah pemrograman).
* "Stimulating the sleep process": Mensimulasikan proses tidur, di sini berarti secara bertahap menghitung waktu yang berlalu dari menit ke menit.

Implementasi Editorial:

```cpp
#include <bits/stdc++.h>

#define int long long
#define pb emplace_back
#define mp make_pair
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

typedef long double ld;
typedef long long ll;

using namespace std;

mt19937 rnd(143);

const int inf = 1e15;
const int M = 1e9 + 7;
const ld pi = atan2(0, -1);
const ld eps = 1e-6;

void solve(){
    int n;
    cin >> n;
    int time, h, m;
    cin >> h >> m;
    time = 60 * h + m;
    int ans = 24 * 60;
    for(int i = 0; i < n; ++i){
        cin >> h >> m;
        int t = 60 * h + m - time;
        if(t < 0) t += 24 * 60;
        ans = min(ans, t);
    }
    cout << ans / 60 << " " << ans % 60;
}

bool multi = true;

signed main() {
    int t = 1;
    if (multi)cin >> t;
    for (; t; --t) {
        solve();
        cout << endl;
    }
    return 0;
}
```

## 3.2 | Analisis Pribadi

Aku kesulitan untuk mengatasi, seadainya alaarm berikutnya yang berbunyi adalah memutari jam hampir 2 kali. Hampir benar, tapi ternyata masih salah. Aku belajar di soal ini, untuk menggunakan kondisional jika semisal selisihnya kurang dari $0$, maka tambahkan saja dengan $1440$, untuk menemukan selisih yang tepat.

Berikut adalah implementasiku:

```cpp
#include<iostream>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, H, M, ans = 1440;
        cin >> n >> H >> M;
        int time = 60 * H + M;
        for (int i=0, h, m; i<n; i++) {
            cin >> h >> m;
            int diff = 60*h+m - time;
            if (diff < 0) diff += 1440;
            ans = min(ans, diff);
        }
        cout << ans/60 << " " << ans%60 << '\n';
    }
    return 0;
}
```
## 3.3 | Analisis Jawaban User Lain

Karena solusi dari editorial merupakan solusi yang paling efisien, karena kompleksitasnya yang langsung menemukan jawaban dari membaca inputan secara langsung, maka jawaban dari banyak user juga tidak terlalu berbeda:

### 1 | Jawaban Pertama

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, h, m;
        cin >> n >> h >> m;
        int H = INT_MAX;
        while (n--) {
            int l, r;
            cin >> l >> r;
            int x = (l - h) * 60 + (r - m);
            if (x < 0) x += 24 * 60;
            H = min(H, x);
        }
        cout << H / 60 << " " << H % 60 << "\n";
    }
}
```

### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, h, m;
        cin >> n >> h >> m;
        int now = h * 60 + m, mn = 1e9;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            int alarm = a * 60 + b;
            int wait = (alarm - now + 1440) % 1440;
            mn = min(mn, wait);
        }
        cout << mn / 60 << " " << mn % 60 << endl;
    }
}
```
### 3 | Jawaban Ketiga

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

void solve() {
    int n;
    cin >> n;
    int time, h, m;
    cin >> h >> m;
    time = 60 * h + m;
    int ans = 24 * 60;
    for (int i = 0; i < n; ++i) {
        cin >> h >> m;
        int t = 60 * h + m - time;
        if (t < 0) t += 24 * 60;
        ans = min(ans, t);
    }
    cout << ans / 60 << " " << ans % 60;
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```