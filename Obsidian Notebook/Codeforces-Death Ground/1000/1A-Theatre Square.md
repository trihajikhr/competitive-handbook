---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1A
judul_DEATH: Theatre Square
teori_DEATH: bulatkan keatas
sumber:
  - codeforces.com
rating: 1000
ada_tips?: true
date_learned: 2025-10-06T14:50:00
tags:
  - math
---
Sumber: [Problem - 1A - Codeforces](https://codeforces.com/problemset/problem/1/A)

```ad-tip
title:⚔️ Teori Death Ground
$$ceil(\frac{n}{a}) = \frac{n+a-1}{a}$$
```

<br/>

---
# 1 | 1A-Theatre Square

Jika disederhanakan, diberikan sebuah tempat berbentuk persegi, dengan panjang $n$ dan lebar adalah $m$. Tugas kita adalah menutup semua tempat tersebut dengan ubin, yang berbentuk persegi (kotak sama sisi) dengan panjang sisi adalah $a$.

Tentukan berapa banyak ubin minimal yang dibutuhkan untuk menutupi semua tempat tersebut.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Jawabanya mudah, kita hanya cukup mencari minimal ubin yang dibutuhkan untuk menutupi semua panjang $n$, lalu dikalikan dengan minimal ubin yang dibutuhkan untuk menutupi semua panjang dari $m$. 

Hal ini bisa dilakukan dengan membagi nilai dari $n$ dan $m$ dengan $a$, tetapi dibulatkan keatas. Atau rumusnya adalah:

$$ans = \lceil{\frac{n}{a}}\rceil \times \lceil{\frac{m}{a}}\rceil$$

Bisa digunakan bantuan fungsi `ceil()` untuk pembulatan keatas, atau menggunakan aturan berikut:

$$ceil(\frac{n}{a}) = \frac{n+a-1}{a}$$

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Kendala bahwa sisi-sisi setiap lempengan batu (flagstone) harus **sejajar** dengan sisi-sisi persegi memungkinkan untuk menganalisis sumbu **X dan Y secara terpisah**, yaitu, berapa banyak segmen dengan panjang **'a'** yang dibutuhkan untuk menutupi segmen dengan panjang **'m'** dan **'n'** -- dan mengambil **hasil kali** dari kedua kuantitas ini. Jawabannya adalah **$\text{ceil}(m/a) * \text{ceil}(n/a)$**, di mana $\text{ceil}(x)$ adalah bilangan bulat terkecil yang lebih besar dari atau sama dengan $x$. Hanya menggunakan bilangan bulat, ini biasanya ditulis sebagai **$((m+a-1)/a)*((n+a-1)/a)$**. Perhatikan bahwa jawabannya bisa mencapai $10^{18}$, yang **tidak muat** dalam bilangan bulat 32-bit.

Sebagian besar kesulitan, jika ada, yang dialami peserta kontes terkait dengan **tipe data** dan **prioritas operator**, yang sangat bergantung pada bahasa pemrograman yang digunakan, jadi hal-hal tersebut tidak dibahas di sini.

## 3.2 | Analisis Pribadi

Pembulatan keatas adalah cara paling efisien, kita tidak perlu menggunakan perulangan. Kompleksitasnya menjadi $O(1)$ sekarang.

Hal yang perlu diperhatikan adalah batasan dari problem, yaitu hinngga $10^{18}$. Oleh karena itu, pastikan menggunakna tipe data long long. Berikut implementasinya:

```cpp
#include<iostream>
using namespace std;

auto main() -> int {
    long long n, m, a;
    cin >> n >> m >> a;
    cout << ((n+(a-1))/a) * ((m+(a-1))/a);
    return 0;
}
```

## 3.3 | Analisis Jawaban User Lain

Jawaban dari editorial adalah cara yang paling efisien, sehingga jawaban user lain pun tidak jauh berbeda.

### 1 | Jawaban Pertama

```cpp
#import <iostream>
    main() {
        int n, m, a;
        std::cin >> n >> m >> a;
        std::cout << (--n / a + 1 ll) * (--m / a + 1);
    }
```
### 2 | Jawaban Kedua

```cpp
#include <iostream>
using namespace std;
int main(){
  long long n,m,a;
  cin>>n>>m>>a;
  cout<<((n+a-1)/a)*((m+a-1)/a);
}
```
### 3 | Jawaban Ketiga

```cpp
#include<iostream>
using namespace std;
int 
main(void) {
	long long  n, m, a;
	cin >> n >> m >> a;
	long long nn = ( n - 1 ) / a;
	long long mm = ( m - 1 ) / a;
	cout << ( nn + 1 ) * ( mm + 1 );
	return 0;
} 
```