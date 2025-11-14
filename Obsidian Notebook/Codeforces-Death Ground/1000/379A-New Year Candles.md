---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 379A
judul_DEATH: New Year Candles
teori_DEATH:
sumber:
  - codeforces.com
rating: 1000
ada_tips?:
date_learned: 2025-10-06T16:13:00
tags:
---
Sumber: [Problem - 379A - Codeforces](https://codeforces.com/problemset/problem/379/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 379A-New Year Candles

Kita diminta untuk mencari tahu, berapa total lilin yang kita nyalakan, jika pada awalnya kita memiliki $a$ lilin, dan setiap kita membakar tepat $b$ lilin, kita bisa membuat lilin baru, atau $a+1$.


<br/>

---
# 2 | Sesi Death Ground ⚔️

Karena batasan yang diberikan adalah 1000, aku merasa tidak apa menggunakan cara iteratif. Lakukan perhitungan dimana ketika $a$ kita kurangi, maka kita tambahkan nilai ke variabel yang menghitung banyak lilin yang dibakar, misal $wo$, dimana $wo+1$. Ketika $wo \% b = 0$, maka artinay ada tepat $b$ lilin sehingga kita bisa membuat lilin baru.

Berikut implementasiku:

```cpp
#include<iostream>
using namespace std;

auto main() -> int {
    int a,b, ans=0, wo=0;
    cin >> a >> b;

    while (a--) {
        ans++, wo++;
        if (wo%b==0) {
            a++, wo=0;
        }
    }
    cout << ans;
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Misalkan $cur_a$ adalah jumlah lilin baru, dan $cur_b$ adalah jumlah lilin yang sudah terbakar habis.

Awalnya, $cur_a = a$ dan $cur_b = 0$. Setelah membakar semua $cur_a$ lilin baru, jumlah jam bertambah sebanyak $cur_a$, dan $cur_b += cur_a$. Selanjutnya, mari kita ubah semua lilin yang terbakar habis menjadi lilin baru: $cur_a = cur_b / b$. Ulangi algoritma ini sampai kita bisa membuat setidaknya satu lilin baru.

## 3.2 | Analisis Pribadi

Walaupun cara perulangan ini bekerja, namun jika batasanya misal $10^{9}$ lebih, jelas cara ini tidak efisien sama sekali. Tapi karena aku tidak tahu jawaban seperti apa yang efisien (ada dibawah), maka aku cukup memanfaatkan batasan yang kecil dari problem, untuk tidak masalah mengimplementasikan solusi iteratif.
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include<iostream>
using namespace std;
int a, b;
int main() {
	cin>> a >> b;
	cout<<(a*b-1) / (b-1);
}
```

Ternyata ada jawaban yang hanya menggunakan $O(1)$ komplekstias waktu, tanpa menggunakan perulangan sama sekali!

$$T = (a \times b - 1) / (b-1)$$


Total lilin terbakar = lilin awal + lilin hasil daur ulang.

Setiap lilin baru butuh $b-1$ stump tambahan (karena 1 stump didapat langsung dari lilin yang dibakar).

Hasil pembagian $(a\times b - 1)/(b-1)$ memberi total maksimum lilin yang bisa dibakar.
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>

using namespace std;
int a, b;
int main() {
    cin >> a >> b;
    cout << (a * b - 1) / (b - 1);
}
```

Hampir sama seperti jawaban pertama, karenan memang ternyata jawaban ini adalah jawaban yang paling efisien.
### 3 | Jawaban Ketiga

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c = 0;
    cin >> a >> b;
    while (a--) {
        c++;
        if (c % b == 0)
            a += 1;
    }
    cout << c;
}
```

Hampir sama seperti jawabanku.