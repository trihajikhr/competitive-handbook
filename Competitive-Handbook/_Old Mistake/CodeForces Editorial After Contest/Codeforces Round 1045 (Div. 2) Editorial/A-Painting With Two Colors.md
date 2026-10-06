---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 2134A
judul_STRIKE: Painting With Two Colors
teori_STRIKE: Tentang paritas
sumber:
  - codeforces
ada_tips?: true
date_learned: 2025-08-27T03:00:00
tags:
  - STRIKE
---
Sumber: [Problem - A - Codeforces](https://codeforces.com/contest/2134/problem/A)

```ad-tip
title:⚔️ Teori STRIKE
Jika soal berkaitan dengan paritas ganjil genap, maka langsung bandingkan saja dengan modulo!
```

<br/>

---
# 1 | A-Painting With Two Colors

Buka link sumber untuk membaca problem statement! Pahami dan cermati! Setelah itu baru lanjut ke bagian pembahasan.

<br/>

---
# 2 | Sesi STRIKE ⚔️

Jadi, kita diberikan 3 buah variabel, yaitu variabel $a$, $b$, dan variabel $n$. Untuk setiap variabel, memiliki batasan, dimana $1 \leq a,b \leq n$. 

Problem statement memberikan tantangan, dimana variabel $n$ menunjukan besar baris dengan $n$ kolom, dan tugas kita adalah menentukan, apakah dengan melakukan pewarnaan pada array tersebut dengan nilai $a$ dan $b$ akan menghasilkan hasil yang simetri.

oke mungkin sampai disini cukup memusingkan, ya tentu karena memang syarat dari problem statement nya sendiri memang cukup banyak.

Nilai dari $a$ dan $b$ sendiri, jika semakin kecil, maka batasan ujungnya akan semakin ke kanan. Artinya, jika nilainya adalah 1, maka kita bisa melakukan pewarnaan dengan pilihan yang sangat luas, namun hanya sedikit petak yang boleh diwarnai, yaitu dalam contoh ini, adalah 1.

Tapi, jika nilai $a$ atau $b$ besar, maka pilihan dimana kita memulai lebih terbatas, lebih ke ujung kiri, namun pewarnaanya lebih memnuhi ruang, bahkan jika semisal nilai salah satu dari $a$ atau $b$ adalah sama dengan $n$, maka semua petak pasti terwarnai.

```ad-warning
Baca problem statement ini, karena syarat dan ilustrasi ditampilkan lebih jelas: [Problem - A - Codeforces](https://codeforces.com/contest/2134/problem/A)
```

Petak dengan banyaknya sell sebanyak $n$, akan diwarnai dengan 2 tahap, yaitu diwarnai dengan warna merah dengan batasan sebanyak $a$. Lalu setelahnya, dilakukan pewarnaan dengan warna biru, dengan batasan sebanyak $b$. Jika semisal terdapat petak yang dicat dengan dua warna, maka petak tersebut akan berubah menjadi warna biru. Biru yang mendominasi.

Nah, pewarnaan ini, harus menghasilkan bentuk yang simetri. Maksudnya, semisal kita memiliki array $arr$, maka untuk setiap $arr[i] = arr[n-i+1]$. Jika kondisi tersebut bisa dicapai, maka ouputkan YES, sebaliknya outputkan NO.

#tips-trick Jika soal berkaitan dengan paritas ganjil genap, maka langsung bandingkan saja dengan modulo!
<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Mari kita pertimbangkan terlebih dahulu sel **biru** sebanyak $b$. Karena semua $b$ sel muncul di lukisan akhir, agar pewarnaannya simetris, sel-sel tersebut harus ditempatkan di bagian **tengah** dari grid. Akibatnya, $b$ dan $n$ harus memiliki **paritas** yang sama.

Selanjutnya, kita periksa dua kemungkinan kasus:

* Jika $b ≥ a$, maka sel biru bisa sepenuhnya menutupi semua sel merah. Dalam situasi ini, nilai $a$ tidak memengaruhi hasil pewarnaan akhir.
* Jika $b < a$, maka sel merah tidak sepenuhnya tertutup oleh sel biru. Oleh karena itu, sel merah juga harus ditempatkan di bagian tengah grid, yang berarti $a$ dan $n$ juga harus memiliki **paritas** yang sama.

Dengan demikian, dengan memeriksa kondisi-kondisi tersebut, kita bisa menentukan apakah pewarnaan simetris dapat dibuat. Proses ini hanya membutuhkan waktu $\mathcal{O}(1)$.

```cpp
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    if (a <= b) {
      cout << ((n % 2) == (b % 2) ? "YES\n" : "NO\n");
    } else {
      cout << ((n % 2) == (b % 2) && (n % 2) == (a % 2) ? "YES\n" : "NO\n");
    }
  }
}
```

## 3.2 | Analisis Pribadi

Pertama, ketahui dulu kondisi apa saja yang akan membuat suatu array menjadi mungkin untuk diwarnai secara simetri. Terdapat beberapa kondisi yang mungkin:

1. Ketika pewarnaan cat pertama lebih kecil rentangnya daripada pewarnaan cat kedua. Ketika kondisi ini terjadi, maka kita hanya perlu memeriksa apakah pewarnaan cat kedua yang menutup cat pertama langsung bisa membentuk bentuk simetri atau tidak. Dan ingat, warna biru akan menimpa warna merah. 
<br/>

2. Ketika pewarnaan cat pertama lebih besar daripada pewarnaan cat kedua. Ketika kondisi ini terjadi, maka harus dilakukan pemeriksaan apakah kedua pewarnaan sudah berada pada titik simetri atau belum, karena jika salah satu tidak sesuai, maka pewarnaan simetri tidak bisa tercapai.

Well, kita perlu memperlakukan ukuran $n$ dengan cara yang berbeda jika ganjil atau genap.

Jika genap, maka pewarnaan yang mungkin untuk membuat bentuk menjadi simetri, hanyalah ketika variabel $a$ dan $b$ adalah genap. Jika salah satu ganjil, maka nilai ganjil tersebut haruslah nilai $a$, dan $a < b$, karena pewarnaan $b$ akan menutupi kesahalan dari pewarnaan $a$. Jika nilai $b$ yang ganjil, maka tidak mungkin untuk membuat array menjadi simetri.

Jika ganjil, maka nilai $a$ dan $b$ harus ganjil. Jika salah satu genap, maka nilai genap tersebut haruslah nilai $a$, dan $a < b$, karena pewarnaan $b$ akan menutupi kesalahan dari pewarnaan $a$. Jika justru $b$ nya genap, maka tidak mungkin untuk membuat array menjadi simetri.

Jadi, berikut adalah kodeku untuk menjawab tantangan ini, ketika mengikuti kontes secara live:

```cpp
/*
Author  : Riveris
Date    : 2025-08-26 21:42
Problem : Codeforces | 2134A - Painting With Two Colors
*/

#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    static void solve() {
        int n = 0;
        int a = 0;
        int b = 0;
        cin >> n >> a >> b;

        // ingat urutan sangat penting!
        bool poss = true;
        int maks = INT_MIN;
        if (n % 2 == 0) {
            if ((b % 2 == 1) || (a > b && a % 2 == 1)) {
                poss = false;
            }
        } else {
            if ((b % 2 == 0) || (a > b && a % 2 == 0)) {
                poss = false;
            }
        }

        cout << (poss ? "YES" : "NO") << '\n';
    }
};

auto main() -> int {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 0;
    cin >> t;
    while ((t--) != 0) {
        Solution::solve();
    }
    return 0;
}
```
## 3.3 | Analisis Jawaban User Lain

Berikut adalah kode yang ditulis oleh standings No.1, yang ditulis oleh [Hamed_Ghaffari](https://codeforces.com/profile/Hamed_Ghaffari "Grandmaster Hamed_Ghaffari"), pada submit berikut [codeforces.com/contest/2134/submission/335617805](https://codeforces.com/contest/2134/submission/335617805):

```ad-warning
Submit asli hanya bisa dilihat oleh pengguna yang sudah register dan menyelesaikan problem yang sama!
```

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using ull = unsigned long long;

#define X               first
#define Y               second
#define SZ(x)           int(x.size())
#define all(x)          x.begin(), x.end()
#define mins(a,b)       (a = min(a,b))
#define maxs(a,b)       (a = max(a,b))
#define pb              push_back
#define Mp              make_pair
#define lc              id<<1
#define rc              lc|1
#define mid             ((l+r)>>1)
mt19937_64              rng(chrono::steady_clock::now().time_since_epoch().count());

const ll  INF = 1e9 + 23;
const ll  MOD = 1e9 + 7;
const int MXN = 2e5 + 5;
const int LOG = 23;

void Main() {
    int n, a, b;
    cin >> n >> a >> b;
    if(n%2!=b%2) {
        cout << "NO\n";
        return;
    }
    if(a>b && a%2!=n%2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while(T--) Main();
    return 0;
}
```

Jika disaring, maka hanya kode ini yang diperlukan:

```cpp
#include <bits/stdc++.h>
using namespace std;

void Main() {
    int n, a, b;
    cin >> n >> a >> b;
    if(n%2!=b%2) {
        cout << "NO\n";
        return;
    }
    if(a>b && a%2!=n%2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while(T--) Main();
    return 0;
}
```

Idenya hampir sama, namun lebih langsung.

Jika $n$ terdeteksi tidak memiliki paritas yang sama dengan nilai $b$, maka jelas, langsung outputkan saja NO.

Tetapi jika nilai $n$ dan $b$ memiliki paritas yang sama, maka kondisional pertama akan terlewati, dan langsung menuju ke pemeriksaan kedua. Ini artinya kita sudah mengamankan bahwa nilai $b$ selanjutnya sudah pasti sesuai dengan paritas yang sama dengan $n$.

Jika nilai dari $a>b$, maka nilai $a$ tidak akan tertutup sepenuhnya oleh $b$, sehingga nilai dari $a$ wajib memiliki paritas yang sama dengan $n$. Jika paritasnya ternyata berbeda, maka outputkan saja NO.

Jika tidak ada satupun kondisi diatas yang memfilter input, berarti inputan adalah mungkin untuk membuat bentuk array yang simetri, maka outputkan YES.