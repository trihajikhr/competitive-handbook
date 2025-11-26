---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 327A
judul_DEATH: Flipping Game
teori_DEATH:
sumber:
  - codeforces.com
rating: 1200
ada_tips: false
date_learned: 2025-10-30T17:33:00
tags:
  - brute-force
  - dynamic-programming
  - implementation
---
Sumber: [Problem - 327A - Codeforces](https://codeforces.com/problemset/problem/327/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 327A-Flipping Game

Diberikan sebuah array $a$ dengan $n$ elemen, dimana elemen-elemen ini hanya terdiri dari angka $1$ dan juga $0$. Kamu diberikan tugas, dimana kamu boleh melakukan operasi berikut:

- Pilih indeks $i$ dan $j$, dimana $1 \leq i \leq j \leq n$, lalu lakukan *flip*, atau membalik angka yang ada di rentang tersebut, misalnya angka $1 \rightarrow 0$, dan $0 \rightarrow 1$.

Tugasmu adalah, memaksimalkan lalu menentukan banyaknya kemunculan angka $1$ yang mungkin pada array, seandainya kamu hanya diperbolehkan melakukan operasi diatas maksimal sekali.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Well, aku mencoba menemukan solusi yang efisien, namun akhirnya berakhir tidak berhasil. Ada satu yang berhasil tetapi menggunakan kompleksitas $O(n^3)$. Lihat penjelasan dibawah untuk sekalian penjelasan!

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Saya akan menyajikan di sini algoritma $O(N^3)$, yang cukup untuk menyelesaikan tugas ini. Kemudian, bagi mereka yang tertarik, saya akan menunjukkan metode untuk mencapai kompleksitas **$O(N)$**.

### Metode $O(N^3)$

Hal pertama yang perlu diperhatikan adalah bahwa batasan (constraints) cukup longgar untuk mengizinkan algoritma *brute force*. Dengan menggunakan *brute force*, saya dapat menghitung untuk setiap kemungkinan satu gerakan (move) jumlah angka $1$ yang dihasilkan setelah menerapkannya dan mengambil nilai maksimum.

Untuk mempertimbangkan setiap gerakan, saya hanya perlu menghasilkan semua indeks $i, j$ sedemikian sehingga $i \le j$ dengan $2$ *loop FOR*. Sejauh ini kita memiliki kompleksitas $O(N^2)$.

Misalkan sekarang saya memiliki 2 nilai $i$ dan $j$ yang tetap. Saya perlu menghitung variabel **$cnt$** (awalnya 0) yang mewakili jumlah angka satu jika saya melakukan gerakan tersebut. Untuk melakukan ini, saya memilih indeks $k$ lain untuk melewati larik $a[]$ (membutuhkan waktu $O(N)$, membuat total kompleksitas menjadi **$O(N^3)$**).

Kita punya dua kasus:

1.  **$k$ berada dalam rentang $[i, j]$** (ini berarti $i \le k$ DAN $k \le j$). Jika dalam rentang, maka nilai $a[k]$ di-*flip* (dibalik), jadi kita tambahkan **$1 - a[k]$** ke variabel *count* (perhatikan bahwa ini mengubah 0 menjadi 1 dan 1 menjadi 0).
2.  **$k$ tidak berada dalam rentang** (jika kondisi tersebut tidak terpenuhi). Jika tidak dalam rentang, kita cukup menambahkan **$a[k]$** ke variabel $cnt$.

Jawabannya adalah maksimum dari semua $cnt$ yang diperoleh.
### Metode $O(N)$

Untuk mencapai kompleksitas ini, kita perlu membuat sebuah pengamatan.

Misalkan saya membalik (*flip*) suatu interval (tidak masalah interval mana, bisa saja interval apa pun). Juga misalkan **$S$** adalah jumlah angka satu sebelum membaliknya. Apa yang terjadi?

* Setiap kali saya membalik nilai 0, $S$ bertambah 1 (saya mendapatkan nilai 1 yang baru).
* Setiap kali saya membalik nilai 1, $S$ berkurang 1 (saya kehilangan nilai 1).

Apa yang akan menjadi "keuntungan" dari pembalikan? Saya menganggap "menang" "+1" ketika saya mendapatkan nilai 0 dan "-1" ketika saya mendapatkan nilai 1. "Keuntungan" (gain) hanyalah jumlah dari +1 dan -1.

Ini memberi kita ide untuk membuat vektor lain **$b[]$**.

* $b[i]$ adalah **$1$** jika $a[i]$ adalah $0$.
* $b[i]$ adalah **$-1$** jika $a[i]$ adalah $1$.

Kita ingin memaksimalkan jumlah $S + \text{gain\_setelah\_satu\_gerakan}$. Karena $S$ adalah konstan (tetap), saya ingin memaksimalkan $\text{gain\_setelah\_satu\_gerakan}$.

Dengan kata lain, saya ingin mencari sub-barisan (*subsequence*) dalam $b[]$ yang memberikan jumlah maksimal. Jika saya membaliknya, saya juga akan mendapatkan jumlah angka 1 yang maksimal. Ini dapat ditemukan secara *trivial* (mudah) dalam $O(N^2)$.

Bagaimana cara mendapatkan **$O(N)$**? Seorang programmer yang relatif berpengalaman dalam *dynamic programming* akan segera mengenalinya sebagai masalah klasik "sub-barisan dari jumlah maksimal" (*"subsequence of maximal sum"*). Jika Anda belum pernah mendengarnya, kembalilah ke pendekatan ini setelah Anda mempelajarinya.

## 3.2 | Analisis Pribadi

Dari cara editorial, kita diperbolehkan dan mungkin untuk membuat kompleksitas $O(n^3)$, maka berikut adalah jawabanku, dan ini adalah opsi yang aku berhasil untuk pertama kalinya:

```cpp
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    bool dif = false;
    vector<int> d(n);
    int one = 0;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        if (i != 0 && d[i] != d[i - 1])
            dif = true;
        if (d[i])
            one++;
    }

    if (!dif) {
        if (n == 1 && d[0] == 1)
            cout << 0;
        else if (n > 1 && d[0] == 1)
            cout << n - 1;
        else if (d[0] == 0)
            cout << n;
        return 0;
    }

    int ans = 0, curr = 0, curOne = 0, curZer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n - i; j++) {
            curOne = 0, curZer = 0;
            for (int k = j; k < j + i; k++) {
                if (d[k])
                    curOne++;
                else
                    curZer++;
            }
            if (curZer > curOne) {
                ans = max(ans, one + (curZer - curOne));
            }
            ans = max(ans, curr);
            curr = 0;
        }
    }

    cout << ans << '\n';
    return 0;
}
```

Pendekatan yang lebih efisien, yang mana dikatakan mampu untuk menggunakan solusi dengan kompleksitas $O(n)$, mungkin akan ditampilkan di analisis jawaban user lain.
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n], temp, curr = 0, summ = 0, mx = -n;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    curr += 1 - 2 * temp;
    summ += temp;
    mx = max(mx, curr);
    if (curr < 0) curr = 0;
  }
  cout << mx + summ;
  return 0;
}
```

Algoritma yang *clever*. Algoritma ini mungkin adalah algoritma yang dimaksud oleh editorial, dimana menerapkan konsep dynamic programming sebagai konsepnya.

Program ini menjumlahkan angka $1$, yang nantinya akan ditampung ke dalam variabel $summ$. Lalu, variabel $curr$ akan bertambah ketika nilai yang dimasukan adalah angka $0$, dan berkurang ketika angka yang dimasukan adalah angka $1$, menggunakan cara yang cukup *clever* yaitu: $1-2\times temp$. Pendekatan ini bertujuan untuk menghitung banyaknya kemunculan angka $1$ (*yang ditampung kedalam $summ$*),  lalu menghitung nilai $curr$ terbesar, yang mana menunjukan letak segment yang menjadi kandidat utama untuk dilakukanya operasi *flip*, menambahkan beberapa angka $1$ pada keseluruhan array sebanyak $curr$.

Terakhir, dapatkan total angka $1$ yang bisa didapat, dengan cara: $mx + summ$.
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, i, res = 0, x, a[105], rec = -4, j, w = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) res++;
    if (a[i] == 1) w -= 1;
    else w += 1;
    rec = max(rec, w);
    w = max(w, 0);
  }

  cout << res + rec;
}
```

Algotritma ini menerapkan konsep yang sama dengan contoh pertama. Namun, mungkin lebih readable. Walaupun kondisional pada baris nomor 9-10 mungkin bisa digabung saja.
### 3 | Jawaban Ketiga

```cpp
// Hey stalker :)
#include "bits/stdc++.h"

using namespace std;

#define MOD 1000000007

#define by_DevanshuSharma\
ios::sync_with_stdio(false);\
cin.tie(NULL);

#define no cout << "NO\n";
#define yes cout << "YES\n";

void solve() {
  int ans = 0;
  bool flag = true;
  vector <int> vec;
  map <int, int> mpp;
  set <int> set;

  int n;
  cin >> n;
  vector <int> a(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      sum++;
    }
  }
  
  if (sum == n) {
    cout << n - 1;
    return;
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int one = 0, zero = 0;
      for (int k = i; k <= j; k++) {
        if (a[k] == 0) {
          zero++;
        } else {
          one++;
        }
        ans = max(ans, sum - one + zero);
      }
      ans = max(ans, sum - one + zero);
    }
  }
  cout << ans;
}

int main() {
  by_DevanshuSharma
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int T = 1, t = 0;
  // cin >> T;
  while (t++ < T) {
    // cout<<"Case #"<<t<<":"<<' ';
    solve();
    // cout<<'\n';
  }
  cerr << "Time : " << 1000 * ((double) clock()) / (double) CLOCKS_PER_SEC << "ms\n";
}
```

Algoritma ini mungkin menggunakan pendekatan yang hampir sama dengan pendekatan pertamaku yang menggunakan konsep 3 nested loop, kompleksitas $O(n^3)$. Tapi anehnya, mungkin karena inputanya masih kecil, menjadikan algoritma ini (*entah kenapa*) memiliki kompleksitas paling cepat.