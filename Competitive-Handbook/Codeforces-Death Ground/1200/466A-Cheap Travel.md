---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 466A
judul_DEATH: Cheap Travel
teori_DEATH:
sumber:
  - codeforces.com
rating: 1200
ada_tips?: false
date_learned: 2025-10-09T21:51:00
tags:
  - implementation
---
Sumber: [Problem - 466A - Codeforces](https://codeforces.com/problemset/problem/466/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 466A-Cheap Travel

Ann ingin melakukan perjalanan dengan kereta sebanyak $n$ kali. Terdapat $2$ tiket yang bisa dia pilih, yaitu tiket yang dengan harga $a$ yang melayani hanya satu kali keberangkatan, dan tiket dengan harga $b$ yang melayani $m$ keberangkatan.

Tentuka harga minimal yang perlu Ann keluarkan, agar ia bisa melakukan perjalananya dengan kereta sebanyak $n$ kali.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Pertama,  cari tahu harga masing-masing yang harus dikeluarkan jika semisal Ann memprioritaskan satu jenis tiket saja.

Misal total biaya untuk penggunaan tiket pertama adalah $x$, maka harga yang dibutuhkan untuk melakukan $n$ perjalanan adalah: 

$$x = a \times n$$
Lalu total harga untuk penggunaan tiket kedua adalah $y$, maka harga yang dibutuhkan untuk melakukan $n$ perjalanan adalah:

$$y=\left(\frac{n}{m} \times b\right) + min\left((n \text{ mod }m) \times a, b\right)$$

Perhitungan $y$ memperkirakan, jika semisal membeli tiket kedua, maka ada kemungkinan bahwa pembelian terakhir akan melebihi kebutuhan $n$ perjalanan. Oleh karena itu, dilakukan langkah yang optimal. Yaitu kita hanya membeli tiket kedua hingga penawaran perjalanan tepat sebelum melebihi $n$ perjalanan. Setelah itu, hitung sisa perjalanan yang ada, dan tentukan, mana yang lebih murah untuk menutupi perjalanan terakhir, apakahh dengan membeli tiket pertama sebanyak $n \text{ mod }m$ kali, atau tiket kedua tepat sekali.

Lalu, jawabanya adalah nilai terkecil diantara $x$ dan $y$.

Maka berikut jawabanku:

```cpp
#include<iostream>
#include<algorithm>
using namespace std;

auto main() -> int {
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    int x = a*n;
    int y = ((n/m)*b) + min(((n%m)*a), b);
    cout << min(x,y);
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Solusi dari masalah ini didasarkan pada dua klaim:

* Jika $m \cdot a \le b$, maka tidak ada gunanya membeli tiket terusan (tiket perjalanan).
* Terkadang lebih baik membeli tiket terusan dalam jumlah total perjalanan yang melebihi jumlah yang kita butuhkan.

Jika kita mendapatkan keuntungan dengan membeli tiket terusan, maka jumlah tiket terusan tersebut adalah $x = \lfloor \frac{n}{m} \rfloor$.

Untuk sisa perjalanan sebanyak $n - m \cdot x$, kita harus memilih varian terbaik: membeli tiket terpisah untuk setiap perjalanan, atau membeli tiket terusan dan tidak menggunakannya secara penuh.

Kompleksitas: $O(1)$

Implementasi editorial:

```cpp
#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n, m, a, b;
    
    cin >> n >> m >> a >> b;
    if (m * a <= b)
        cout << n * a << "\n";
    else 
        cout << (n/m) * b + min((n%m) * a, b) << "\n";

    return 0;
}
```

---

## 3.2 | Analisis Pribadi

Rumusku sangat tepat, sesuai, dan efisien seperti editorial. Jawabanku sudah benar dan valid.
## 3.3 | Analisis Jawaban User Lain

Solusii dari editorial sudah memiliki kompleksitas yang paiing efisien. Jawaban dari banyak pengguna lain tidak jauh berbeda:

### 1 | Jawaban Pertama

```cpp
#include<iostream>

main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << std::min(a * c, a / b * d + std::min(d, a % b * c));
}
```
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a,b;
	cin>>n>>m>>a>>b;
	cout<<min(n*a,n/m*b+min(b,n%m*a));
}
```
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n , m , a, b;
    cin >> n >> m >> a >> b;
    int ans = 0;
    if (m * a <= b ) {
        cout << a * n;
    } else {
        ans += n / m * b;
        int rem = n % m;
        ans += min(rem * a, b);
        cout << ans << "\n"; 

    }
}
```