---
obsidianUIMode: preview
note_type: death ground
kode_soal: 500A
judul_DEATH: New Year Transportation
teori_DEATH: dfs and similar dasar, mulai masuk ke graph
sumber:
  - codeforces.com
rating: 1000
ada_tips: true
date_learned: 2025-11-30T13:10:00
tags:
  - dfs-and-similar
  - graphs
  - implementation
---
Sumber: [Problem - 500A - Codeforces](https://codeforces.com/problemset/problem/500/A)

```ad-tip
title:⚔️ Teori Death Ground
Jika algoritma graph yang diberikan hanya bergerak satu arah, dan linear, maka loop biasa sudah cukup untuk menyelesaikannya.
```

<br/>

---
# 1 | 500A-New Year Transportation

> Soalnya ribet, padahal bisa dibuat gampang.

Terdapat sebuah rumah yang berada didalam sel-sel, dan sebanyak $n-1$ jalan. Sel tersebut berbentuk lurus, jadi hanya terdiri dari satu baris sel yang memanjang. Setiap orang yang tinggal dimasing-masing sel, ingin bertemu dengan orang dari rumah lain, sehingga mereka membuat portal, yang membuat mereka bisa berpindah-pindah tempat, namun portal ini bekerja dengan cara tertentu.

Terdapat $n-1$ portal, setiap portal menghubungkan sel $i$ ke sel $i + a_i$. Portal ini hanya bisa digunakan satu arah, jadi tidak bisa digunakan lagi untuk kembali, atau balik ke posisi $i$ setelah berpindah ke posisi $i+a_i$.

Sekarang kamu diberikan $n-1$ jalan, berupa sebuah array. Jika tujuanku adalah mencapai posisi $t$, dan posisi sel tempat aku memulai adalah posisi $1$. Tentukan apakah mungkin untuk mencapai sel $t$ dengan melewati jalan-jalan yang diberikan.



<br/>

---
# 2 | Sesi Death Ground ⚔️

Walaupun soal ini memiliki tag berupa graph, dan dfs, namun kita tidak perlu mengimplementasikanya sampai sejauh itu.

Terima inputan sebanyak $n-1$ jalan, tampung dengan array atau vector misal $v$. Pastikan menggunakan array 1-based index supaya lebih mudah, karena kita membutuhkan posisi yang dimulai dari 1.

Solusinya sederhana, kita bisa membuat sebuah variabel $cur$ yang menyimpan posisi sel sekarang, lalu gunakan perulangan while. Selama $cur <t$, lakukan $cur = cur + v[cur]$. Jika $cur > t$ dan $cur \neq t$, maka artinya kita melewati posisi sel $t$ sehingga kita bisa outputkan `NO`, karena tidak mungkin bisa kembali. Tapi jika $cur > t$ dan $cur \equiv t$, maka artinya kita bisa mencapai posisi $t$ dan outputkan `YES`. Berikut implementasiku:

```cpp
#include<iostream>
#include<vector>
using namespace std;
 
auto main() -> int {
    int n, t;
    cin >> n >> t;
    vector<int> v(n+1);
    for (int i=1; i<=n-1; i++) {
        cin >> v[i];
    }
 
    int cur = 1;
    while (cur < t) {
        cur += v[cur];
    }
 
    cout << (t == cur ? "YES" : "NO");
    return 0;
}
```


<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Dalam soal ini, kita diberikan sebuah graf berarah, dan ditanyakan apakah suatu simpul tertentu dapat dicapai dari simpul $1$. Hal ini dapat diselesaikan dengan menjalankan DFS yang dimulai dari simpul $1$.

Karena setiap simpul memiliki maksimal satu sisi keluar, DFS dapat ditulis sebagai loop sederhana. Beberapa orang menggunakan ini untuk membuat submission yang sangat singkat.

Kode editorial, yang ternyata dari Tourist 😅:

```cpp
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>
 
using namespace std;
 
int a[1234567];
 
int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  for (int i = 1; i < n; i++) {
    scanf("%d", a + i);
  }
  int x = 1;
  while (x < t) {
    x += a[x];
  }
  puts(x == t ? "YES" : "NO");
  return 0;
}
```

## 3.2 | Analisis Pribadi

Luar biasa, kode implementasiku bahkan mirip dengan jawaban dari Tourist! Ini artinya kode implementasiku sudah jelas benar, singkat, dan efisien 😎.
## 3.3 | Analisis Jawaban User Lain

Jawaban dariku, editorial, dan beberpa pengguna banyak yang sama, jadi aku akan mengambil jawabanku sebagai sudah benar dan tepat. Kode orang lain juga kebanyakan sama, jika ada yang berbeda, maka gunakan saja sebagai bahan evaluasi.

### 1 | Jawaban Pertama

```cpp
#include<iostream>
using namespace std;

int main() {
    int a, b, c = 0, n[100000];
    cin >> a >> b;
    for (int i = 1; i < a; i++) {
        cin >> n[i];
    }
    for (c = 1; c < b; c = c + n[c]);
    cout << (c == b ? "YES" : "NO");
    return 0;
}
```
### 2 | Jawaban Kedua

```cpp
#include <iostream>
using namespace std;

int a[30001];
int main() {
    int n, k, x = 1;
    cin >> n >> k;
    for (int i = 1; i < n; i++) cin >> a[i];
    while (x < k) x = x + a[x];
    if (x == k) cout << "YES";
    else cout << "NO";
    return 0;
}
```
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>

#define ll long long
#define endl "\n"
#define gcd __gcd
#define yes cout << "YES";
#define no cout << "NO";
using namespace std;
void lol() {
    ll n, b, ans = 1;
    cin >> n >> b;
    ll a[n + 5];
    bool bl = false;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        if (ans == b) bl = true;
    }
    while (ans <= n) {
        if (ans == b) {
            yes
            return;
        }
        ans += a[ans];
    }
    no
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll salmon = 1;
    while (salmon--) {
        lol();
        cout << endl;
    }
}
```