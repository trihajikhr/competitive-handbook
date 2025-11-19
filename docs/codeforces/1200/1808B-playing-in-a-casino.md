---
tags:
    - math
    - sortings
---

# 1808B - Playing in a Casino
Sumber: [1808B - Playing in a Casino](https://codeforces.com/problemset/problem/1808/B)

Didalam sebuah kasino, terdapat $n$ pemain yang bermain dengan $n$ deck kartu. Setiap kartu, memiliki tepat $m$ angka yang tertulis didalamnya.

Permain dilakukan dengan cara berpasangan dengan semua pemain yang ada. Misal ada $4$ pemain, maka akan dilakukan $6$ permainan, karena pemain pertama bermain dengan pemain kedua, ketiga, dan keempat. Pemain kedua bermain dengan pemain ketiga dan keempat. Dan pemain ketiga bermain dengan pemain keemapat. Total ada $6$ permainan.

Setiap game, menentukan pemenang dengan cara yang cukup kompleks. Pemenang dari setiap permainan berpasangan akan mendapatkan chip, semisal pemain $a$ memiliki kartu dengan angka $a_1, a_2, \cdots a_m$, dan pemain kedua memiliki kartu dengan angka $b_1, b_2, \cdots, b_m$, maka pemanang akan mendapatkan chip sebanyak $|a_1 - b_1| + ||a_2 - b_2| + \cdots + |a_m - b_m|$.

Untuk menentukan kebutuhan chip yang diperlukan, hitung total chip yang mungkin untuk didapatkan seorang pemenang dalam setiap permainan. Karena mungkin untuk memiliki banyak pemain dan kartu, tugasmu adalah membuat program yang bisa menghitung kebutuhan deck maksimal ini

## Analisisa Awal

inputan yang diberikan adalah $n$ yang menyatakan banyaknya player dan kartu, dan $m$ yang menyatakan banyaknya angka pada setiap kartu.

Batasan yang diberikan oleh soal ini adalah $1 \leq n \cdot m \leq 3 \cdot 10^5$. Dan setiap angka pada kartu memiliki batasan berupa $1 \leq C_{i,j} \leq 10^6$, yang mendeskripsikan besaran kartu ke-$i$.

Dengan menggunakan pendekatan biasa, sangat mungkin untuk menyelesaikan masalah ini dengan menggunakan _nested loops_ tiga lapis, namun kompleksitas $O(n^3)$ jelas akan melebihi _time limit_, karena itu adalah pendekatan naif.

Kode dibawah ini bisa menyelesaikankan beberapa testcase, namun tidak mungkin untuk menangani inputan berukuran besar, sehingga berakhir _time limit exceed_:

```cpp
#include<iostream>
#include<vector>
using namespace std;

using ll = long long;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> v (n, vector<ll>(m));
    for (auto& r : v) {
        for (auto& x : r) {
            cin >> x;
        }
    }

    ll sum = 0; 
    for (int i=0; i < n-1; i++) { // (1)
        for (int j=i+1; j<n; j++) {
            for (int k=0; k<m; k++) {
                sum += abs(v[i][k] - v[j][k]);
            }
        }
    }
    cout << sum << "\n";
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

1. Nested loops ini menggunakan kompleksitas $O(n^3)$, mengakibatkan _time limit exceed_

## Jawaban dan Editorial

### Analisis Editorial

Anda mungkin memperhatikan bahwa masalahnya dapat diselesaikan secara independen untuk setiap kolom dari matriks *input*. Jawabannya kemudian adalah jumlah $\sum_{i=1}^{n}\sum_{j=i+1}^{n}|a_i - a_j|$, di mana $a$ adalah larik yang mewakili satu kolom.

Mari kita coba hitung jumlah ini untuk setiap kolom.

1.  Mari kita urutkan semua elemen dari kolom saat ini.
2.  Mari kita hitung jawabannya untuk beberapa elemen di daftar yang sudah diurutkan.
3.  Jawabannya untuk elemen tersebut adalah $a_i \cdot i - \text{sum}$, di mana $\text{sum}$ adalah jumlah pada *prefix* (jumlah elemen-elemen sebelumnya).

Mengapa demikian? Karena kita menganggap bahwa bilangan ini ($a_i$) lebih besar daripada yang lain (yaitu elemen-elemen di *prefix*). Dengan demikian, modulus akan terurai menjadi $|a_i - a_j| = a_i - a_j$, dan ini sudah mudah dihitung.

### Analisis Pribadi



### Analisis Jawaban Lain