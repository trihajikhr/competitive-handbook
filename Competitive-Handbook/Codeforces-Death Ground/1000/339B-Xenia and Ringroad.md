---
obsidianUIMode: preview
note_type: death ground
kode_soal: 339B
judul_DEATH: Xenia and Ringroad
teori_DEATH:
sumber:
  - codeforces.com
rating: 1000
ada_tips:
date_learned: 2025-11-29T19:43:00
tags:
---
Sumber: [Problem - 339B - Codeforces](https://codeforces.com/problemset/problem/339/B)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 339B-Xenia and Ringroad

Xenia hidup disebuah rumah yang tersusun secara melingkar sebanyak $n$ rumah. Diberikan sebuah task sebanyak $m$, yang mana $a_i$ merepresentasikan bahwa Xenia harus mengerjakan tugas tersebut di rumah ke $i$. Xenia hanya boleh bergerak searah jarum jam, dan selalu dimulai dari posisi rumah ke-$1$. Jika Terdapat task pada posisi dimana $a_i$ lebih kecil dari posisi sekarang, maka Xenia harus melakukan gerakan memutar, karena hanya boleh bergerak satu arah.

Tentukan, berapa langkah minimal yang diperlukan Xenia untuk menyelesaikan $m$ task pada $n$ rumah yang diberikan tersebut!

<br/>

---
# 2 | Sesi Death Ground ⚔️

Pertama, gunakan tipe data `long long`, karena ketika aku menggunakan int, ternyata terdapat overlflow. Oke, sekarang masuk ke algoritma yang gunakan.

Jika $a_{i+1} < a_i$, maka kita harus melakukan gerakan memutar. Gerakan memutar akan membutuhkan sebanyak $n$ langkah, karena terdapat $n$ rumah yang harus dilwati. Selama $i \neq n$, maka kita cukup lakukan pemeriksaan ini. Ketika tepat $i \equiv n$, maka kita cukup periksa nilai dari $a_n$ dan tambahkan langkah terakhir yang diperlukan dengan cukup $a_n -1$.

Kenapa jawaban ini bisa benar? Karena kita tidak perlu menghitung langkah yang diperlukan jika $a_{i+1} > a_i$, kita cukup hitung berapa banyak putaran yang diperlukan, dan posisi task terakhir.

Berikut implementasiku:

```cpp
#include<iostream>
using namespace std;

using ll = long long;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, ans = 0;
    cin >> n >> m;

    ll curr, prev = -1;
    for (int i=0; i<m; i++) {
        cin >> curr;
        if (i != 0) {
            if (curr < prev) ans += n;
        }
        prev = curr;
    }

    ans += prev - 1;
    cout << ans ;
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Untuk menyelesaikan problem ini, kita harus mengetahui cara menghitung dengan cepat waktu yang dibutuhkan untuk berpindah dari rumah $a$ ke $b$. Pertimbangkan kasus ketika $a \le b$. Maka Xenia membutuhkan $b - a$ detik untuk pergi dari $a$ ke $b$. Sebaliknya, jika $a > b$, Xenia harus melewati rumah nomor $1$. Jadi ia membutuhkan waktu $n - a + b$ detik.

## 3.2 | Analisis Pribadi

Jawabanku tidak menggunakan array, dan menggunakan kompleksitas $O(n)$, jadi seharusnya sudah efisien secara memory dan waktu. 
## 3.3 | Analisis Jawaban User Lain

Beberapa user bisa menuliskan solusi yang ternyata lebih singkat. Tapi selama tidak ada perbedaan dari sisi memory dan kompleksitas, maka sama saja.

### 1 | Jawaban Pertama

```cpp
#include<iostream>
#define ll long long

using namespace std;

int main() {
    int n, k, p = 1, x;
    ll r = 0;
    cin >> n >> k;
    while (k--) {
        cin >> x;
        r += (x - p + n) % n;
        p = x;
    }
    cout << r;
}
```
### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m, btmp = 1, tmp;
	long long t;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> tmp;
		t += tmp - btmp + (tmp < btmp) * n;
		btmp = tmp;
	}
	cout << t;
}
```
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define ull unsigned long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    ll mx = 0;
    ll now = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        mx += ((--x) - now + n) % n;
        now = x;
    }

    cout << mx;

    return 0;
}
```