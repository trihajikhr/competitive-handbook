---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 492B
judul_DEATH: Vanya and Lanterns
teori_DEATH:
sumber:
  - codeforces.com
rating: 1200
ada_tips?: true
date_learned: 2025-10-09T21:02:00
tags:
  - binary-search
  - implementation
  - math
  - sortings
---
Sumber: [Problem - 492B - Codeforces](https://codeforces.com/problemset/problem/492/B)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 492B-Vanya and Lanterns

Terdapat sebuah jalan dengan panjang dari $0$ hingga $l$. Terdapat $n$ lampu, dimana $a_i$ menunjukan koordinat atau letak lentera tersebut terhadap koordinat jalan dengan panjang $l$ tadi.

Lampu-lampu tersebut bisa menerangi jalan, dengan jangkauan tertentu. Tugas kita adalah, menentukan jangkauan lampu paling kecil, yang dibutuhkan untuk memastikan semua jalan mendapatkan penerangan.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Karena setiap lampu berada pada titik koordinat yang berbeda-beda, maka ketika menerima array, kita perlu mengurutkan (sorting *ascending*) array tersebut.

Letak lampu paling kiri membutuhkan jangkauan yang memastikan posisi dirinya hingga koordinat $0$ mendapatkan penerangan. Letak lampu paling kanan juga demikian, jangkauan yang dibutuhkan lampu paling kanan dengan ujung jalan yaitu $l$ juga harus dihitung.

Artinya, kita harus menyimpan nilai $max(lent[0]-0, l-lent[n-1])$, misal kita simpan nilai ini di $ans$.

Setelah itu, kita juga harus menghitung selisih jarak antar lampu. Karena kedua lampu bisa saling memancarkan cahaya, maka jangkauan yang dibutuhkan antar dua lampu pastilah sama, yang mana berasal dari selisih koordinat keduanya dibagi dengan $2$. Sehingga, kita hanya perlu melakukan proses traversal terhadap array, dan melakukan operasi berikut:

$$ans = max(ans, \frac{lent[i+1]-lent[i]}{2})$$

Gunakan tipe data float atau double, dan simpan koordinat atau value dari $a_i$ dari lampu tersebut dengan tipe data pecahan tersebut, sehingga kita tidak perlu melakukan konversi.

Berikut adalah jawabanku:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double n, l;
    cin >> n >> l;
    vector<double> len(n);
    for (auto& x : len) cin >> x;
    double ans = -1;
    ranges::sort(len);
    ans = max(len[0], l-len[n-1]);

    for (int i=0; i<n-1; i++) {
        ans = max(ans, (len[i+1]-len[i])/2);
    }
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Urutkan lampion-lampion dalam urutan tidak menurun (non-*decreasing*). Kemudian, kita perlu mencari jarak maksimal antara dua lampion yang bertetangga, sebut saja $maxdist$.

Kita juga perlu mempertimbangkan batas-batas jalan dan menghitung jarak dari lampion terluar ke batas-batas jalan, yaitu $(a[0] - 0)$ dan $(l - a[n-1])$.

Jawabannya adalah: $\max(\frac{maxdist}{2}, \max(a[0] - 0, l - a[n-1]))$.

Kompleksitas waktu: $O(n \log n)$.

Berikut adalah implementasi editorial:

```cpp
#include <stdio.h>
#include <algorithm>
using namespace std;
int n,i,a[100500],rez,l;
int main()
{
    scanf("%d%d",&n,&l);
    for (i = 0; i < n; i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    rez = 2*max(a[0],l-a[n-1]);
    for (i = 0; i < n-1; i++)
        rez = max(rez, a[i+1]-a[i]);
    printf("%.10f\n",rez/2.);
    return 0;
}
```

## 3.2 | Analisis Pribadi

Aku bisa menjawab soal ini dengan mudah, dan sepertinya pendekatan pertamaku sudah merupakan pendekatan yang efisien.

Berikut adalah jawabanku:

```cpp
#include<bits/stdc++.h>
using namespace std;

auto main() -> int {
    int n, l;
    cin >> n >> l;
    vector<double> v(n);
    for (auto& x : v) cin >> x;
    ranges::sort(v);
    double ans = numeric_limits<double>::min();
    ans = max(l-v[n-1], v[0]-0);
    for (int i=0; i<n-1; i++) {
        ans = max(ans, (v[i+1]-v[i])/2);
    }
    cout << setprecision(10) << fixed << ans;
    return 0;
}
```
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#import < bits / stdc++.h >
using namespace std;

int i, l, n;
double m, a[1005];

int main() {
    for (cin >> n >> l; i < n;) cin >> a[i++];
    for (sort(a, a + n); --i;) m = max(m, (a[i] - a[i - 1]) / 2);
    cout << fixed << max(m, max( * a, l - a[n - 1]));
}
```

Well, solusi yang singkat, namun bagi pemula, mungkin akan bingung dengan kode ini. Kode ini benar-benar menggunakan perulangan `for` sebagai tempat untuk melakukan inisialisasi langsung, dan mengandalkan angka $0$ yang akan bertindak sebagai `false`, menghentikan perulangan.

Tapi logika utamanya sama.
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;

int n, L, a[1005];
int main() {
    scanf("%d%d", & n, & L);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    int ans = max(L - a[n], a[1]) * 2;
    for (int i = 1; i < n; ++i) ans = max(ans, a[i + 1] - a[i]);
    printf("%.1f\n", ans * 0.5);
    return 0;
}
```

Logikanya masih sama, hanya lebih mengandalkan input output gaya C saja.
### 3 | Jawaban Ketiga

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double max_dub(double a, double b) {
    if (a > b) {
        return a;
    }
    return b;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());

    double a1 = a[0] - 0;
    double a2 = m - a[n - 1];

    double a3 = 0;

    for (int i = 0; i < n - 1; i++) {
        a3 = max_dub(a3, (double)(a[i + 1] - a[i]));
    }

    double a4 = a3 / 2;

    cout << fixed;
    cout.precision(9);
    cout << max_dub(a4, max_dub(a1, a2));

    return 0;
}
```

Logika utamanya sama, hanya saja jauh lebih panjang, karena tidak dibuat *langsung*, melainkan mendekati solusi secara perlahan, cocok untuk pemula.