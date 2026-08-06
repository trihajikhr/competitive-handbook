---
obsidianUIMode: preview
note_type: latihan
latihan: KPK Pertemuan Selanjutnya
sumber:
  - tlx-toki.id
tags:
  - combinatorics
date_learned: 2026-02-10T03:20:00
---
Link Sumber: [tlx.toki.id/courses/competitive-1/chapters/02/problems/P2](https://tlx.toki.id/courses/competitive-1/chapters/02/problems/P2)

---
> [!IMPORTANT]
# 1. KPK Pertemuan Selanjutnya
Desa Pak Dengklek sering kedatangan para pedagang dari berbagai daerah. Pedagang-pedagang ini datang mengunjungi desa Pak Dengklek secara periodik dalam beberapa hari sekali. Akibatnya, bisa terjadi, semua pedagang datang di hari yang bersamaan. Saat itulah sebuah pasar besar digelar dengan sebutan Pasar Rakyat.

Pak Dengklek sangat suka belanja dan selalu menantikan datangnya Pasar Rakyat. Kebetulan, hari ini Pasar Rakyat kembali digelar dan hampir mencapai penghujungnya. Pak Dengklek yang tidak sabar menunggu, mulai sibuk menghitung, berapa hari lagikah pasar rakyat akan kembali digelar?

### Format Masukan

Baris pertama masukan berisi sebuah bilangan $N (2 \leq N \leq 20)$ yang menyatakan jumlah pedagang yang mengunjungi desa Pak Dengklek. 

$N$ baris berikutnya masing-masing berisi sebuah bilangan $D_i  (1 \leq D_i \leq 100000)$ yang menyatakan periode kunjungan pedagang ke-$i$, yang artinya pedagang ke-$i$ berkunjung setiap $D_i$ hari sekali.

### Format Keluaran

Keluarkanlah jumlah hari berikutnya Pasar Rakyat akan diadakan apabila hari ini adalah hari penyelenggaraan Pasar Rakyat. Keluaran dijamin tidak akan lebih dari 100.000.

<br/>

---
# 2. Jawaban

```cpp
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

using ll = long long;
auto main() -> int {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto& x : v) {
        cin >> x;
    }

    ll ans = v.front();
    for (int i = 1; i < n; i++) {
        ans = lcm(ans, v[i]);
    }

    cout << ans;
    return 0;
}
```

<br/>

---
# 3. Editorial

Solusinya mudah, katakanlah $N$ jumlah pedagang tersebut, melakukan kunjungan pada setiap $D_i$. Maka kita cukup mencari nilai KPK dari semua nilai tersebut, atau formulanya adalah:

$$LCM(D_1, D_2, \dots,\ D_N)$$
Untuk mencari semua nilainya dengan mudah, maka setiap nilai kita tampung pada array terlebih dahulu, baru kemudian dibandingkan satu-satu supaya lebih mudah.

Kita bisa menggunakan pencarian KPK atau LCM dengan melakukan implementasi kode sendiri, bisa dipelajari di [LCM and GCD](LCM%20and%20GCD.md). Namun, untungnya C++ menyediakan fungsi bawaan untuk operasi ini, yang terdapat pada header `<numeric>`, yaitu `lcm()`.