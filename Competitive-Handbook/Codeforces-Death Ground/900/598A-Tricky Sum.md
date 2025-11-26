---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 598A
judul_DEATH: Tricky Sum
teori_DEATH:
sumber:
  - codeforces.com
rating: 900
ada_tips?:
date_learned: 2025-10-18T15:13:00
tags:
---
Sumber: [Problem - 598A - Codeforces](https://codeforces.com/problemset/problem/598/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 598A-Tricky Sum

Kita diminta mencari total penjumlahan dari $1$ hingga $n$, namun setiap $n$ yang merupakan hasil dari angka perpangkatan $2$, akan menjadi nilai minus.

Contoh, untuk $n=4$, jumlahnya adalah $-1-2+3-4 = -4$, karena angka $2^0=1$, $2^1=2$, dan $2^2=4$.

Tentukan hasilnya.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Jika kita melakukan penjumlahan dari $1$ hingga $n$, dan menggunakan pendeteksian, apakah suatu angka ke-$i$ bisa habis dibagi $2$ atau tidak, maka kompleksitas akan meledak.

Pertama, perhatikan bahwa terdapat beberapa test case, dan nilai $n$ bisa sangat besar, yaitu hingga $1 \leq n \leq 10^9$. Artinya kita harus menggunakan tipe data long long disini.

Pertama, kita bisa menangani angka apa saja yang merupakan hasil dari perpangkatan $2$, dengan melakukan precompute. Menyimpan semua nilai pada satu array sebelum memulai testcase pertama. Ini akan menghemat waktu kedepanya.

Lalu setelah itu, kita bisa mencari jumlah total dari $1$ sampai $n$, dengan rumus berikut:

$$\sum_1^{n}i = \frac{n \cdot (n+1)}{2}$$

Setelah itu, lakukan perulangan dengan menggunakan array precompute yang sudah dibuat, dan gunakan semua nilai yang berada dibawah atau sama dengan $n$ untuk mengurangi total jumlah. Namun, masing-masing nilainya kita kalikan dengan $2$, ini karena total awal yang kita dapat tidak ada minus didalamnya, sehingga untuk mendapatkan nilai yang sesuai, doublekan nilai pengurangnya.

Berikut adalah implementasiku yang sudah benar:

```cpp
#include<iostream>
#include<vector>
using namespace std;

using LL = long long;
void getFill(vector<LL>& two) {
    LL curr = 1;
    two.push_back(curr);
    while (curr <= 1e9) {
        curr *= 2;
        two.push_back(curr);
    }
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<LL> two;
    getFill(two);
    int t;
    cin >> t;
    while (t--) {
        LL n;
        cin >> n;
        LL sum = (n * (n+1))/2;
        int idx=0;
        while (two[idx] <= n) {
            sum -= two[idx++]*2;
        }
        cout << sum << '\n';
    }
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Jika masalah ini **tidak memiliki "trik"** dan yang harus dilakukan hanyalah mencari jumlah $1 + 2 + \dots + n$, maka dengan menggunakan rumus penjumlahan deret aritmatika, hasilnya adalah $s = \frac{n \cdot (n+1)}{2}$ (bilangan dengan bentuk seperti ini disebut **bilangan segitiga**).

Namun, setiap bilangan yang merupakan **pangkat dari dua** harus dijumlahkan **bukan dengan tanda "plus", melainkan dengan tanda "minus"**.

Oleh karena itu, mari kita **mengurangi dua kali** (karena pengurangan pertama hanya akan menghapus bilangan tersebut dari jumlah, dan pengurangan kedua akan menjadikannya negatif/minus) setiap pangkat dari dua yang tidak melebihi $n$.

Cara termudah untuk melakukan ini adalah dengan menggunakan perulangan (loop) seperti ini:

```cpp
long long pow2 = 1;
while (pow2 <= n)
    s -= pow2 * 2, pow2 *= 2;
```

Nilai $s$ setelah perulangan ini akan menjadi jawabannya. Jumlah iterasi perulangan ini tidak akan melebihi logaritma biner dari bilangan $n$ (lebih tepatnya, ditambah satu), yang merupakan bilangan sekitar 30 untuk nilai uji maksimum yang mungkin.

**Asimptotik:** $\mathcal{O}(\log n)$ (untuk satu kasus uji dalam himpunan).

## 3.2 | Analisis Pribadi

Solusi editorial adalah dengan melakukan perulangan mandiri untuk setiap test case, sedangkan kodeku menggunakan precompute, sehingga pencarian jumlah nilai yang dimiliki oleh semua angka hasil perpangkatan dengan $2$ menjadi jauh lebih sedikit.

Tapi, aku merasa pendekatan editorial sebernanya juga efektif, karena dari segi memori, jauh lebih ringan. Sedangkan kodeku, jauh lebih ringan dari segi komputasi, karena tidak perlu melakukan pencarian nilai perpangkatan $2$, melainkan hanya mengambil data array precompute.

## 3.3 | Analisis Jawaban User Lain

Solusi editorial sudah optimal, jawaban lain berada di sekitar ide dan konsep yang sama:

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;

long long i, t, n, k;
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        k = (n * (n + 1)) / 2;
        for (i = 1; i <= n; i *= 2) {
            k -= (2 * i);
        }
        cout << k << endl;
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
        long long sum = 0, p = 1, n;
        cin >> n;
        sum = n * (n + 1) / 2;
        while (p <= n) {
            sum -= (2 * p);
            p = 2 * p;
        }
        cout << sum << endl;
    }

    return 0;
}
```
### 3 | Jawaban Ketiga

```cpp
#include<iostream>
#include<cmath>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        long long n;
        cin >> n;
        long long sum = 0;
        for(long long i=1;i<=n;i *= 2){
            sum += i;
        }

        cout << (n * (n+1))/2 - 2*sum << endl;
    }
    
    return 0;
}
```