---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1921C
judul_DEATH: Sending Messages
teori_DEATH:
sumber:
  - codeforces.com
rating: 900
ada_tips?:
date_learned: 2025-10-18T13:14:00
tags:
---
Sumber: [Problem - 1921C - Codeforces](https://codeforces.com/problemset/problem/1921/C)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1921C-Sending Messages

Diberikan $n,f,a$ dan $b$. Nilai $n$ merepresentasikan banyaknya pesan yang harus dikirimkan, $f$ adalah baterai ponsel sekarang, $a$ adalah daya yang dibutuhkan untuk ponsel tersebut menyala dalam satu satuan waktu, dan $b$ adalah daya yang dibutuhkan untuk ponsel tersebut mati dan dihidupkan kembali.

Tugas kita adalah menentukan, apakah mungkin untuk mengirim semua $n$ pesan sebelum daya ponsel mati ($\leq 0$). Setiap pesan ke-$i$ menandakan waktu dimana pesan tersebut harus dikirimkan. 

<br/>

---
# 2 | Sesi Death Ground ⚔️

Problem ini cukup sederhana, kita hanya perlu mengambil opsi dengan penggunaan daya terkecil disetiap pengiriman pesan. Hal itu bisa didapat dengan cara mengurangi daya $f$ disetiap pesan:

$$f = f - min((m[i+1]-m[i]) \times a, \; b) $$
Jika setelah semua pesan dikirimkan, dan nilai $f > 0$, maka jawabanya adalah `YES`, karena kita bisa mengirim semua pesan dengan ada daya tersisa. Sebaliknya outputkan `NO`.

Operasi diatas juga bisa dilakukan tanpa membuat array atau vector, yaitu cukup dengan menggunakan satu variabel bantu, yang akan menyimpan inputan sebelumnya, untuk dibandingkan dengan inputan yang baru diterima.

Berikut adalah implementasiku:

```cpp
#include<iostream>
using namespace std;

using LL = long long;
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        LL n,f,a,b, curr = 0;
        cin >> n >> f >> a >> b;
        for (int i=0, x; i<n; i++) {
            cin >> x;
            f -= min((x-curr)*a , b);
            curr = x;
        }

        cout << (f > 0 ? "YES" : "NO") << '\n';
    }
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Bagian yang paling menantang dari masalah ini mungkin adalah **memahami pernyataan masalah dengan cermat**.

Masalah ini dapat direduksi menjadi sebagai berikut: Ada $n$ interval waktu: dari $\text{0}$ ke $m_1$, dari $m_1$ ke $m_2$, ..., dari $m_{n-1}$ ke $m_n$. Untuk setiap interval, kita perlu menemukan cara untuk menghabiskan daya ponsel sesedikit mungkin, dan memeriksa bahwa total jumlah daya yang kita habiskan lebih kecil dari daya awal ponsel.

Strategi Penghematan Daya:

Untuk menghabiskan jumlah daya minimum untuk satu interval waktu, kita dapat bertindak dengan salah satu dari dua cara. Misalkan panjang interval tersebut adalah $t$.

1.  **Biarkan ponsel menyala** dan menghabiskan $a \times t$ unit daya.
2.  **Matikan ponsel** di awal interval dan nyalakan di akhir, menghabiskan $b$ unit daya.

Kompleksitas waktu total dari solusi ini adalah $\text{O}(n)$.

Implementasi editorial (python):

```py
t = int(input())
for _ in range(t):
    n, f, a, b = map(int, input().split())
    m = [0] + [int(x) for x in input().split()]
    for i in range(1, n + 1):
        f -= min(a * (m[i] - m[i - 1]), b)
    print('YES' if f > 0 else 'NO')
```
## 3.2 | Analisis Pribadi

Jawabanku sudah optimal!

## 3.3 | Analisis Jawaban User Lain

Solusiku dan editorial hampir sama, dan sepertinya sudah merupakan solusi paling optimal. Jawaban dari user lain tidak jauh berbeda!

### 1 | Jawaban Pertama

```cpp
#include<iostream>
using namespace std;

typedef long long LL;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        LL f, a, b, now(0), t;
        cin >> n >> f >> a >> b;
        while (n--) {
            cin >> t;
            f -= min(b, (t - now) * a);
            now = t;
        }
        if (f <= 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}
```
### 2 | Jawaban Kedua

```cpp
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, f, a, b, x, m = 0;
        cin >> n >> f >> a >> b;
        for (int i = 0; i < n; i++) {
            cin >> x;
            f -= min(b, (x - m) * a);
            m = x;
        }
        if (f <= 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
```
### 3 | Jawaban Ketiga

```cpp
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MOD 1000000007
#define NO cout<< "NO\n"
#define MINUS cout<< "-1\n"
#define YES cout<< "YES\n"
#define pb push_back
#define debug cout<< "i'm working\n"
#define all vec.begin(), vec.end()

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int T;
    cin >> T;

    while(T--) {
        ll n,f,a,b;
        cin >> n >> f >> a >> b;
        ll arr[n];

        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        for(int i=0; i<n; i++) {
            if(i == 0) {
                f -= min((arr[i]*a), b);
            } else {
                f -= min((abs(arr[i]-arr[i-1])*a), b);
            }

            if(f <= 0) break;
        }
        if(f <= 0) NO;
        else YES;
    }
}
```