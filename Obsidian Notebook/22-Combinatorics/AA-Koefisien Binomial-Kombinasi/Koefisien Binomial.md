---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Koefisien Binomial
sumber:
  - Google
  - "buku: CP handbook by Antti Laaksonen"
date_learned: 2025-08-12T12:31:00
tags:
  - combinatorics
---
Link Sumber: [Binomial Coefficients - Algorithms for Competitive Programming](https://cp-algorithms.com/combinatorics/binomial-coefficients.html)

---
# Binomial Coefficients

Koefisien binomial $\binom nk$ adalah jumlah cara untuk memilih satu set  $k$  elemen dari $n$  elemen yang berbeda tanpa memperhitungkan urutan penataan elemen tersebut (yaitu, jumlah set yang tidak berurutan).

Koefisien binomial juga merupakan koefisien dalam perluasan  $(a + b) ^ n$ (yang disebut teorema binomial):

$$ (a+b)^n = \binom n 0 a^n + \binom n 1 a^{n-1} b + \binom n 2 a^{n-2} b^2 + \cdots + \binom nka^{nk} b^k + \cdots + \binom nnb^n $$ 
Rumus ini, beserta segitiga yang memungkinkan perhitungan koefisien secara efisien, diyakini ditemukan oleh Blaise Pascal pada abad ke-17. Namun, rumus ini telah diketahui oleh matematikawan Tiongkok Yang Hui, yang hidup pada abad ke-13. Kemungkinan rumus ini ditemukan oleh cendekiawan Persia, Omar Khayyam. Lebih lanjut, matematikawan India, Pingala, yang hidup lebih awal pada abad ke-3 SM, mendapatkan hasil serupa. Keunggulan Newton terletak pada kemampuannya menggeneralisasi rumus ini untuk eksponen yang bukan bilangan asli.

<br/>

---
## 1 | Calculation

**Rumus analitik untuk perhitungan:**

$$\binom n k = \frac{n!}{k!(n-k)!}$$

Rumus ini dapat dengan mudah diturunkan dari masalah *ordered arrangement* (jumlah cara memilih $k$ elemen berbeda dari $n$ elemen berbeda). Pertama, mari kita hitung jumlah pilihan **berurutan** dari $k$ elemen. Ada $n$ cara untuk memilih elemen pertama, $n-1$ cara untuk memilih elemen kedua, $n-2$ cara untuk memilih elemen ketiga, dan seterusnya. Hasilnya, kita memperoleh rumus jumlah susunan berurutan:

$$n (n-1) (n-2) \cdots (n - k + 1) = \frac{n!}{(n-k)!}$$

Kita bisa dengan mudah berpindah ke **susunan tak berurutan** dengan mencatat bahwa setiap susunan tak berurutan memiliki tepat $k!$ susunan berurutan yang berbeda ($k!$ adalah jumlah permutasi yang mungkin dari $k$ elemen). Dengan demikian, kita memperoleh rumus akhir dengan membagi $\frac{n!}{(n-k)!}$ dengan $k!$.

**Rumus rekurens** (yang berhubungan dengan "Segitiga Pascal" yang terkenal):

$$\binom n k = \binom{n-1}{k-1} + \binom{n-1}{k}$$

Rumus ini mudah diturunkan menggunakan rumus analitik.

Catatan: untuk $n < k$, nilai $\binom n k$ dianggap **nol**.

<br/>

---

## 2 | Properties
Koefisien binomial memiliki banyak sifat yang berbeda. Berikut adalah yang paling sederhana di antaranya:

- Symmetry rule:
    
     $$ \binom n k = \binom n {n-k} $$ 
    
- Factoring in:
    
     $$ \binom n k = \frac n k \binom {n-1} {k-1} $$ 
    
- Sum over  $k$ :
    
     $$ \sum_{k = 0}^n \binom n k = 2 ^ n $$ 
    
- Sum over  $n$ :
    
     $$ \sum_{m = 0}^n \binom m k = \binom {n + 1} {k + 1} $$ 
    
- Sum over  $n$  and  $k$ :
    
     $$ \sum_{k = 0}^m \binom {n + k} k = \binom {n + m + 1} m $$ 
    
- Sum of the squares:
    
     $$ {\binom n 0}^2 + {\binom n 1}^2 + \cdots + {\binom n n}^2 = \binom {2n} n $$ 
    
- Weighted sum:
    
     $$ 1 \binom n 1 + 2 \binom n 2 + \cdots + n \binom n n = n 2^{n-1} $$ 
    
- Connection with the [Fibonacci numbers](https://cp-algorithms.com/algebra/fibonacci-numbers.html):
    
     $$ \binom n 0 + \binom {n-1} 1 + \cdots + \binom {n-k} k + \cdots + \binom 0 n = F_{n+1} $$

<br/>

---

## 3 | Calculation and Implementation

### 3.1 | CP Handbook Anti Laaksonen

#### Formula 1
Koefisien binomial dapat dihitung secara rekursif sebagai berikut:

$$\binom{n}{k}=\binom{n-1}{k-1}+\binom{n-1}{k}$$

Idenya adalah untuk memilih satu elemen $x$ dalam himpunan. Jika $x$ dimasukkan ke dalam himpunan bagian, maka kita harus memilih $k-1$ elemen dari $n-1$ elemen yang tersisa. Jika $x$ tidak dimasukkan, maka kita harus memilih $k$ elemen dari $n-1$ elemen.

Kasus dasar untuk rekursi adalah: $\binom{n}{0}=\binom{n}{n}=1$

Karena selalu ada tepat satu cara untuk membentuk himpunan kosong dan satu cara untuk membentuk himpunan yang berisi semua elemen.

Implementasinya mungkin sebagai berikut:

```cpp
#include <iostream>
using namespace std;

long long binomialCoeff(int n, int k) {
    if (k == 0 || k == n) return 1;
    if (k > n) return 0;
    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << binomialCoeff(n, k) << '\n';
}
```

Kekurangan metode rekursif murni ini:

1. **Waktu eksekusi sangat lambat** untuk $n$ besar, karena kompleksitasnya eksponensial $O(2^n)$. Banyak submasalah dihitung berulang-ulang.
2. **Konsumsi stack tinggi** — kedalaman rekursi bisa mencapai $n$, dan jumlah panggilan fungsi meledak untuk input besar, berisiko stack overflow.
3. **Tidak efisien untuk penggunaan praktis** — meskipun sederhana dan mudah dipahami, ini hanya cocok untuk nilai $n$ kecil atau pembelajaran konsep.

Jadi, **metode ini bukan yang paling efisien**, tapi metode ini paling “bersih” secara konsep untuk memahami sifat rekursif koefisien binomial.

#### Formula 2
Cara lain untuk menghitung koefisien binomial adalah sebagai berikut:

$$\binom{n}{k}=\frac{n!}{k!(n-k)!}$$

Ada $n!$ permutasi dari $n$ elemen. Kita menelusuri semua permutasi dan selalu memasukkan $k$ elemen pertama dari permutasi ke dalam himpunan bagian. Karena urutan elemen dalam himpunan bagian dan elemen di luar himpunan bagian tidak berpengaruh, hasilnya dibagi dengan $k!$  dan $(n-k)!$. Konsep ini sebenarnya sederhana, mengikuti persamaan berikut:

$$\frac{10}{5 \cdot 2} = 1\leftrightarrow \frac{\frac{10}{5}}{2}=1$$

Pembagian langsung ini juga bukan tanpa alasan, karena kita juga menghindari perkalian dari $k!$ dengan $(n-k)!$ yang hasilnya mungkin terlalu besar, sehingga mengakibatkan overflow.

Implementasinya adalah sebagai berikut:

```cpp
#include <iostream>
using namespace std;

long long fac(int n){
    long long sum = 1;
    for(int i=1; i<=n; i++){
        sum *= i;
    }
    
    return sum;
}

long long binom(int n, int k){
    return (fac(n) / fac(k)) / fac(n-k);
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << binom(n,k);
    return 0;
}
```

Kekurangannya:

1. **Rawan overflow** — nilai faktorial tumbuh sangat cepat bahkan untuk $n$ sedang, sehingga hasil perhitungan menyalahi batas tipe data.
2. **Perhitungan tidak efisien** — menghitung faktorial tiga kali membuat banyak operasi berulang yang sebenarnya bisa dihindari.
3. **Tidak cocok untuk $n$ besar** — selain overflow, waktu dan memori bisa terbuang untuk menghitung faktorial yang besar lalu dibagi lagi.

Kesimpulan: **bukan metode yang paling efisien**, meskipun sederhana dan langsung mengikuti rumus matematis.

### 3.2 | CP-Algorithm

#### Perhitungan langsung menggunakan rumus analitik

Rumus pertama, yang paling langsung, sangat mudah di-*code*, tetapi metode ini berisiko mengalami *overflow* bahkan untuk nilai $n$ dan $k$ yang relatif kecil (meskipun jawabannya masih muat di dalam tipe data tertentu, perhitungan faktorial perantara dapat menyebabkan *overflow*). Oleh karena itu, metode ini sering kali hanya dapat digunakan dengan aritmetika bilangan besar ([long arithmetic](https://cp-algorithms.com/algebra/big-integer.html)):

```cpp
int C(int n, int k) {
    int res = 1;
    for (int i = n - k + 1; i <= n; ++i)
        res *= i;
    for (int i = 2; i <= k; ++i)
        res /= i;
    return res;
}
```

   * **Kelebihan:** Implementasi sederhana, cepat ditulis, dan tidak memerlukan penyimpanan data tambahan.
   * **Kekurangan:** Masih berisiko *overflow* jika $n$ atau $k$ relatif besar, serta nilai perantara dapat menjadi sangat besar.


#### Implementasi yang ditingkatkan

Perhatikan bahwa pada implementasi di atas, pembilang (*numerator*) dan penyebut (*denominator*) memiliki jumlah faktor yang sama ($k$), yang masing-masing nilainya ≥ 1. Oleh karena itu, kita dapat mengganti pecahan tersebut menjadi hasil kali dari $k$ pecahan, yang masing-masing bernilai *real*. Namun, pada setiap langkah setelah mengalikan jawaban saat ini dengan salah satu pecahan berikutnya, hasilnya tetap berupa bilangan bulat (hal ini mengikuti sifat faktorisasi).

Implementasi C++:

```cpp
int C(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}
```

Di sini kita secara hati-hati mengubah tipe *floating point* menjadi bilangan bulat, dengan mempertimbangkan bahwa akibat kesalahan pembulatan yang terakumulasi, nilainya mungkin sedikit lebih kecil dari nilai sebenarnya (misalnya $2.99999$ alih-alih $3$).

   * **Kelebihan:** Nilai perantara lebih kecil, memanfaatkan sifat faktorisasi, dan hasil tetap bilangan bulat pada setiap langkah.
   * **Kekurangan:** Menggunakan *floating point* sehingga berpotensi terjadi kesalahan pembulatan; perlu hati-hati saat konversi ke bilangan bulat.
#### Segitiga Pascal

Dengan menggunakan hubungan rekurens, kita dapat membangun tabel koefisien binomial (*Segitiga Pascal*) dan mengambil hasil darinya.

Keuntungan metode ini adalah bahwa nilai perantara tidak pernah melebihi jawaban akhirnya, dan menghitung setiap elemen baru dalam tabel hanya memerlukan satu operasi penjumlahan.
Kelemahannya adalah eksekusi yang lambat untuk $n$ dan $k$ besar jika hanya diperlukan satu nilai dan bukan seluruh tabel (karena untuk menghitung $\binom{n}{k}$ kita perlu membangun tabel semua $\binom{i}{j}$ dengan $1 \le i \le n, 1 \le j \le n$, atau setidaknya $1 \le j \le \min(i, 2k)$). Kompleksitas waktunya dapat dianggap $\mathcal{O}(n^2)$.

Implementasi C++:

```cpp
const int maxn = ...;
int C[maxn + 1][maxn + 1];
C[0][0] = 1;
for (int n = 1; n <= maxn; ++n) {
    C[n][0] = C[n][n] = 1;
    for (int k = 1; k < n; ++k)
        C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
}
```

Jika seluruh tabel nilai tidak diperlukan, cukup menyimpan dua baris terakhir saja (baris ke-$n$ saat ini dan baris ke-$n-1$ sebelumnya).

   * **Kelebihan:** Nilai perantara tidak melebihi hasil akhir, cocok untuk menghitung banyak nilai $\binom{n}{k}$ sekaligus, serta konsepnya mudah dipahami.
   * **Kekurangan:** Membutuhkan waktu dan memori $O(n^2)$ jika membangun tabel penuh; tidak efisien bila hanya memerlukan satu nilai; memori dapat menjadi besar untuk $n$ yang tinggi.

#### Perhitungan dalam $O(1)$

Terakhir, dalam beberapa situasi, bermanfaat untuk *precompute* semua nilai faktorial sehingga setiap koefisien binomial yang diperlukan dapat dihitung hanya dengan dua operasi pembagian.
Hal ini bisa menguntungkan ketika menggunakan [aritmetika bilangan besar](https://cp-algorithms.com/algebra/big-integer.html), atau ketika memori tidak memungkinkan *precompute* seluruh Segitiga Pascal.

   * **Kelebihan:** Setelah proses prahitung, setiap nilai $\binom{n}{k}$ dapat dihitung sangat cepat; ideal untuk banyak *query*.
   * **Kekurangan:** Tetap berisiko *overflow* pada faktorial besar, memerlukan memori untuk menyimpan seluruh nilai faktorial, dan tidak efisien jika hanya digunakan untuk satu kali perhitungan.

### 3.3 | User

#### Rumus *Multiplicative*

Koefisien binomial didefinisikan sebagai:

$$
\binom{n}{r} = \frac{n!}{r! \, (n-r)!}
$$

Tapi kalau kita langsung hitung pakai faktorial, sering terjadi dua masalah:

1. **Angka jadi terlalu besar** (overflow) sebelum sempat dibagi.
2. Kalau **pakai modulus**, pembagian di modulus tidak selalu mudah (butuh invers modular).


Ada bentuk lain yang langsung mengalikan dan membagi secara bertahap:

$$
\binom{n}{r} = \frac{n}{1} \times \frac{n-1}{2} \times \frac{n-2}{3} \times \dots \times \frac{n-r+1}{r}
$$

Dengan kata lain:

$$
\binom{n}{r} = \prod_{i=1}^{r} \frac{n - r + i}{i}
$$

atau

$$
\binom{n}{r} = \prod_{i=1}^{r} \frac{n - i + 1}{i}
$$

(bebas mau tulis yang mana, sama saja).

Kenapa cara ini lebih enak:

* Kita **hanya perlu** $r$ langkah, jadi kompleksitasnya **O(r)**, bukan O(n).
* Lebih aman dari overflow karena kita bisa bagi setelah setiap kali kali (*interleaving multiply-divide*).
* Kalau modulus **prima**, kita bisa ganti pembagian jadi perkalian dengan invers modular.
* Bisa dipakai untuk $n$ besar tanpa harus hitung semua faktorial.

**Contoh hitungan**

Misal $\binom{5}{2}$:

$$
\binom{5}{2} = \frac{5}{1} \times \frac{4}{2}
$$

Langkah demi langkah:

* Awal: result = 1
* result × 5 ÷ 1 = 5
* result × 4 ÷ 2 = 10

#### Versi dengan modulus (bilangan prima)

Kalau modulus $p$ adalah prima:

$$
\binom{n}{r} \bmod p = \prod_{i=1}^{r} \left[ (n-i+1) \times i^{-1} \bmod p \right]
$$

di mana $i^{-1}$ adalah invers modular dari $i$ modulo $p$.

#### Implementasi kode

Versi tanpa modulus:

```cpp
#include <bits/stdc++.h>
using namespace std;

long long nCr(long long n, long long r) {
    if (r > n) return 0;
    r = min(r, n - r); // gunakan r yang lebih kecil
    long long res = 1;

    for (long long i = 1; i <= r; i++) {
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}

int main() {
    cout << nCr(5, 2) << "\n"; // output: 10
}
```

Versi dengan modulus prima:

```cpp
#include <bits/stdc++.h>
using namespace std;

long long modpow(long long a, long long b, long long m) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

long long nCr_mod(long long n, long long r, long long mod) {
    if (r > n) return 0;
    r = min(r, n - r); // ambil r kecil
    long long res = 1;

    for (long long i = 1; i <= r; i++) {
        res = res * (n - i + 1) % mod;
        res = res * modpow(i, mod - 2, mod) % mod; // invers modular
    }
    return res;
}

int main() {
    const long long MOD = 1'000'000'007;
    cout << nCr_mod(5, 2, MOD) << "\n"; // output: 10
}
```

Kalau mau dipakai untuk $n$ besar (misal sampai $10^{12}$), versi ini tetap aman asalkan $r$ masih relatif kecil, karena dia cuma butuh $O(r)$ langkah, bukan $O(n)$.

<br/>

---
## 4 | Menghitung koefisien binomial modulo $m$

Cukup sering kita menemui permasalahan menghitung koefisien binomial dengan hasil di-*modulo* terhadap suatu $m$.

### Koefisien binomial untuk $n$ kecil

Pendekatan *Segitiga Pascal* yang telah dibahas sebelumnya dapat digunakan untuk menghitung semua nilai $\binom{n}{k} \bmod m$ untuk $n$ yang relatif kecil, karena kompleksitas waktunya adalah $\mathcal{O}(n^2)$. Pendekatan ini dapat digunakan untuk *modulo* berapa pun, karena hanya menggunakan operasi penjumlahan.

### Koefisien binomial modulo bilangan prima besar

Rumus koefisien binomial adalah:

$$
\binom{n}{k} = \frac{n!}{k!(n-k)!},
$$

jadi jika kita ingin menghitungnya *modulo* bilangan prima $m > n$, kita peroleh:

$$
\binom{n}{k} \equiv n! \cdot (k!)^{-1} \cdot ((n-k)!)^{-1} \mod{m}.
$$

Pertama, kita *precompute* semua faktorial modulo $m$ hingga $\text{MAXN}!$ dalam waktu $O(\text{MAXN})$:

```cpp
factorial[0] = 1;
for (int i = 1; i <= MAXN; i++) {
    factorial[i] = factorial[i - 1] * i % m;
}
```

Setelah itu, kita dapat menghitung koefisien binomial dalam waktu $O(\log m)$:

```cpp
long long binomial_coefficient(int n, int k) {
    return factorial[n] * inverse(factorial[k] * factorial[n - k] % m) % m;
}
```

Bahkan kita dapat menghitung koefisien binomial dalam waktu $O(1)$ jika kita *precompute* invers dari semua faktorial dalam $O(\text{MAXN} \log m)$ menggunakan metode biasa untuk menghitung invers, atau bahkan dalam $O(\text{MAXN})$ dengan menggunakan kongruensi:

$$
(x!)^{-1} \equiv ((x-1)!)^{-1} \cdot x^{-1}
$$

dan metode untuk [menghitung semua invers](https://cp-algorithms.com/algebra/module-inverse.html#mod-inv-all-num) dalam $O(n)$.

```cpp
long long binomial_coefficient(int n, int k) {
    return factorial[n] * inverse_factorial[k] % m * inverse_factorial[n - k] % m;
}
```

### Koefisien binomial modulo pangkat prima

Di sini kita ingin menghitung koefisien binomial modulo sebuah pangkat prima, yaitu $m = p^b$ untuk suatu bilangan prima $p$.

Jika $p > \max(k, n-k)$, maka kita bisa menggunakan metode yang sama seperti dijelaskan di bagian sebelumnya. Namun jika $p \le \max(k, n-k)$, maka setidaknya salah satu dari $k!$ atau $(n-k)!$ **tidak** relatif prima terhadap $m$, sehingga kita tidak bisa menghitung invers modularnya — invers tersebut memang tidak ada. Meskipun begitu, kita tetap bisa menghitung koefisien binomial.

Idenya sebagai berikut: kita hitung untuk setiap $x!$ pangkat terbesar $c$ sehingga $p^c$ membagi $x!$, atau ditulis $p^c \mid x!$. Kita sebut nilai itu $c(x)$. Lalu kita definisikan

$$
g(x) := \frac{x!}{p^{c(x)}}
$$

Dengan begitu, kita bisa menulis koefisien binomial sebagai:

$$
\binom{n}{k} = \frac{g(n) \cdot p^{c(n)}}{g(k) \cdot p^{c(k)} \cdot g(n-k) \cdot p^{c(n-k)}} 
= \frac{g(n)}{g(k) \cdot g(n-k)} \cdot p^{c(n) - c(k) - c(n-k)}
$$

Yang menarik adalah bahwa $g(x)$ **bebas** dari faktor prima $p$. Oleh karena itu, $g(x)$ relatif prima terhadap $m$, dan kita bisa menghitung invers modular dari $g(k)$ dan $g(n-k)$.

Setelah melakukan pra-komputasi semua nilai $g$ dan $c$ (yang bisa dilakukan secara efisien dengan pemrograman dinamis dalam $\mathcal{O}(n)$), kita bisa menghitung koefisien binomial dalam waktu $O(\log m)$. Atau, kita bisa pra-komputasi semua invers dan semua pangkat $p$, lalu menghitung koefisien binomial dalam waktu $O(1)$.

Perhatikan, jika $c(n) - c(k) - c(n-k) \ge b$, maka $p^b \mid p^{c(n) - c(k) - c(n-k)}$, dan koefisien binomial tersebut bernilai $0$.


### Koefisien binomial modulo bilangan sebarang

Sekarang kita menghitung koefisien binomial modulo suatu modulus sembarang $m$.

Misalkan faktorisasi prima dari $m$ adalah

$$
m = p_1^{e_1} p_2^{e_2} \cdots p_h^{e_h}
$$

Kita dapat menghitung koefisien binomial modulo $p_i^{e_i}$ untuk setiap $i$. Ini akan memberikan kita $h$ kongruensi berbeda. Karena semua modulus $p_i^{e_i}$ saling koprima, kita bisa menerapkan [Chinese Remainder Theorem](https://cp-algorithms.com/algebra/chinese-remainder-theorem.html) (CRT) untuk menghitung koefisien binomial modulo hasil kali semua modulus tersebut, yang merupakan koefisien binomial modulo $m$ yang diinginkan.

### Koefisien binomial untuk $n$ besar dan modulus kecil

Jika $n$ terlalu besar, algoritma $\mathcal{O}(n)$ yang dibahas sebelumnya menjadi tidak praktis.
Namun, jika modulus $m$ kecil, masih ada cara untuk menghitung $\binom{n}{k} \bmod m$.

Ketika modulus $m$ adalah bilangan prima, ada 2 pilihan:

1. [Teorema Lucas](https://en.wikipedia.org/wiki/Lucas's_theorem) dapat diterapkan, yang memecah masalah perhitungan $\binom{n}{k} \bmod m$ menjadi $\log_m n$ masalah dengan bentuk $\binom{x_i}{y_i} \bmod m$ di mana $x_i, y_i < m$.
   Jika setiap koefisien yang sudah direduksi dihitung menggunakan faktorial dan faktorial invers yang sudah dipra-hitungan, kompleksitasnya adalah $\mathcal{O}(m + \log_m n)$.
<br/>

2. Metode perhitungan [faktorial modulo P](https://cp-algorithms.com/algebra/factorial-modulo.html) dapat digunakan untuk mendapatkan nilai $g$ dan $c$ yang dibutuhkan, lalu digunakan seperti yang dijelaskan pada bagian modulo [prime power](https://cp-algorithms.com/combinatorics/binomial-coefficients.html#mod-prime-pow).
   Ini memerlukan $\mathcal{O}(m \log_m n)$.

Ketika $m$ **bukan bilangan prima** tetapi **square-free**, faktor-faktor primanya dapat diperoleh, lalu koefisien modulo setiap faktor prima dihitung menggunakan salah satu metode di atas, dan hasil akhirnya diperoleh menggunakan **Chinese Remainder Theorem**.

Ketika $m$ **bukan square-free**, generalisasi Teorema Lucas untuk prime power dapat diterapkan sebagai pengganti Teorema Lucas.

