---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 160A
judul_DEATH: Twins
teori_DEATH:
sumber:
  - codeforces.com
rating: 900
ada_tips:
date_learned: 2025-11-26T11:47:00
tags:
  - greedy
  - sortings
---
Sumber: [Problem - 160A - Codeforces](https://codeforces.com/problemset/problem/160/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 160A-Twins

Kamu diberikan $n$ koin, dengan setiap koin memiliki value antara $1 \leq a_i \leq 100$. Tentukan berapa banyak koin minimal yang perlu diambil untuk bisa mendapatkan jumlah total yang sedikit lebih besar dari sisanya.


<br/>

---
# 2 | Sesi Death Ground ⚔️

Solusinya mudah, kita hanya perlu menjumlahkan terlebih dahulu semua koin ketika diterima sebagai inputan, misal kita tampung dalam $sum$. Setelah itu, urutkan koin dari terbesar ke terkecil, dan lakukan traversal sambil mengurangi $sum$ terhadap koin $a_i$, dan sambil melakukan counter pada variable counter misal $cnt$. Mungkin kita bisa menggunakan variabel bantu, untuk digunakan sebagai tempat menjumlahkan besaran koin setiap $a_i$, misal $cur$ sebagai perbandingan nanti.

Sorting dilakukan secara descending, karena kita mengutamakan untuk mengambil koin terbesar terlebih dahulu sebelum koin yang lebih kecil, sehingga variabel counter digunakan untuk menghitung berapa banyak koin bervalue besar yang sudah kita ambil.

Misal seperti ini:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
auto main() -> int {
    int n, sum = 0;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
        sum += x;
    }
    ranges::sort(v, greater<>());
 
    int cnt = 0, cur = 0;
    for (const auto& x : v) {
        cnt++;
        cur += x, sum -= x;
        if (cur > sum) break;
    }
 
    cout << cnt;
    return 0;
}
```

Ketika value $cur > sum$, maka artinya jumlah value dari koin yang kita ambil sudah kebih besar dari sisanya, sehingga kita stop, dan kita berhasil menghitung pengambilan koin dengan jumlah value lebih besar dari sisanya, dengan jumlah koin sekecil mungkin.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Jelas bahwa Anda harus mengambil koin yang paling bernilai. Jadi, urutkan nilai dalam urutan tidak menurun, lalu ambil koin dari yang paling bernilai ke yang paling sedikit, sampai Anda mendapatkan **benar-benar** lebih dari setengah total nilai. Kompleksitas waktu bergantung pada algoritma pengurutan yang Anda gunakan. $O(n^2)$ juga dapat diterima, tetapi jika Anda menggunakan *bogosort* yang berjalan dalam $O(n!) \dots$

## 3.2 | Analisis Pribadi

Well, karena kompleksitas jawabanku adalah $O(n)$, aku rasa jawabanku sudah benar dan optimal, sehingga tidak perlu diubah lagi.
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, i, u, s = 0, a[105];
int main() {
    for (cin >> n; i < n; s += a[i++]) cin >> a[i];
    for (sort(a, a + n); u * 2 <= s;) {
        u += a[--i];
    }
    cout << n - i;
}
```

Kode ini sangat singkat, namun sulit dipahami dan didebug jika terjadi error. Bagus untuk mereka yang sudah paham betul aturan penulis di C++, namun praktek terbaik adalah membuat kode yang mudah dimengerti, baik untuk orang lain, maupun diri sendiri di masa depan.
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>

using namespace std;
int main() {
    int a[10000], n, t = 0, b = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        t += a[i];
    }

    sort(a, a + n);
    int i;
    for (i = 0; 2 * b <= t; i++) {
        b += a[n - i - 1];
    }
    cout << i;
}
```

Well, dia menggunakan $i$ sebagai variabel counter sekaligus increment di perulangan `for`, masuk akal juga, boleh-boleh tuh. Kode ini mengurutkan array dari kecil ke terbesar, dan menghitung dari belakang ke depan, konsepnya sama, tapi prakteknya sedikit berbeda.
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum = 0, ans = 0, iter = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a + n);
    reverse(a, a + n);

    for (int i = 0; i < n; i++) {
        if (ans > sum) break;
        ans += a[i];
        sum -= a[i];
        iter++;
    }
    cout << iter;
    return 0;
}
```

Kode ini miirp dengan kodeku, perbedaanya terletak pada ketidak efisienan pada sort, lalu di reverse. Harusnya sort secara descending secara langsung untuk mengurangi kompleksitas yang tidak perlu dari `reverse()`.