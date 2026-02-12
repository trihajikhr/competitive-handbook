---
obsidianUIMode: preview
note_type: book theory
judul_materi: Binomial Coefficients
sumber:
  - cp-algorithms.com
date_learned: 2026-02-09T23:50:00
tags:
  - combinatorics
  - cp-algorithms
---
Link Sumber: [Binomial Coefficients - Algorithms for Competitive Programming](https://cp-algorithms.com/combinatorics/binomial-coefficients.html)

---

> [!IMPORTANT]
>  
# Binomial Coefficients

*Binomial coefficients* atau koefisien binomial $\binom n k$ adalah jumlah cara untuk memilih sebuah himpunan berisi $k$ elemen dari $n$ elemen yang berbeda tanpa memperhatikan urutan penyusunan elemen-elemen tersebut (yaitu, jumlah himpunan tak terurut).

Koefisien binomial juga merupakan koefisien dalam ekspansi $(a + b)^n$ (yang disebut sebagai teorema binomial):

$$(a+b)^n = \binom n 0 a^n + \binom n 1 a^{n-1} b + \binom n 2 a^{n-2} b^2 + \cdots + \binom n k a^{n-k} b^k + \cdots + \binom n n b^n$$

Diyakini bahwa rumus ini, serta segitiga yang memungkinkan perhitungan koefisien secara efisien, ditemukan oleh Blaise Pascal pada abad ke-17. Meskipun demikian, hal ini sudah diketahui oleh matematikawan Tiongkok Yang Hui, yang hidup pada abad ke-13. Mungkin juga ditemukan oleh sarjana Persia Omar Khayyam. Selain itu, matematikawan India Pingala, yang hidup lebih awal pada abad ke-3 SM, memperoleh hasil yang serupa. Jasa Newton adalah dia menggeneralisasi rumus ini untuk eksponen yang bukan bilangan asli.

## 1. Calculation

**Rumus analitik** (*analytic formula*) untuk perhitungan:

$$\binom n k = \frac {n!} {k!(n-k)!}$$

Rumus ini dapat dengan mudah dideduksi dari masalah penyusunan terurut (jumlah cara untuk memilih $k$ elemen berbeda dari $n$ elemen berbeda). Pertama, mari kita hitung jumlah pemilihan terurut dari $k$ elemen. Ada $n$ cara untuk memilih elemen pertama, $n-1$ cara untuk memilih elemen kedua, $n-2$ cara untuk memilih elemen ketiga, dan seterusnya. Sebagai hasilnya, kita mendapatkan rumus jumlah penyusunan terurut:

$$n (n-1) (n-2) \cdots (n - k + 1) = \frac {n!} {(n-k)!}$$

Kita dapat dengan mudah berpindah ke penyusunan tak terurut, dengan memperhatikan bahwa setiap penyusunan tak terurut berhubungan tepat dengan $k!$ penyusunan terurut ($k!$ adalah jumlah permutasi yang mungkin dari $k$ elemen). Kita mendapatkan rumus akhir dengan membagi $\frac {n!} {(n-k)!}$ dengan $k!$.

![500](src/Binomial%20Coefficients-1.png)

**Rumus rekurensi** (*recurrence formula*) (yang dikaitkan dengan "Segitiga Pascal" (*Pascal's Triangle*) yang terkenal):

$$\binom n k = \binom {n-1} {k-1} + \binom {n-1} k$$

Sangat mudah untuk mendeduksi hal ini menggunakan rumus analitik.

Perhatikan bahwa untuk $n \lt k$, nilai dari $\binom n k$ diasumsikan sebagai nol.

## 2. Properties

Koefisien binomial memiliki banyak properti yang berbeda. Berikut adalah beberapa yang paling sederhana:

Aturan simetri (*symmetry rule*):

$$\binom n k = \binom n {n-k}$$

Faktorisasi:

$$\binom n k = \frac n k \binom {n-1} {k-1}$$

Jumlah terhadap $k$:

$$\sum_{k = 0}^n \binom n k = 2 ^ n$$

Jumlah terhadap $n$:

$$\sum_{m = 0}^n \binom m k = \binom {n + 1} {k + 1}$$

Jumlah terhadap $n$ dan $k$:

$$\sum_{k = 0}^m \binom {n + k} k = \binom {n + m + 1} m$$

Jumlah kuadrat:

$${\binom n 0}^2 + {\binom n 1}^2 + \cdots + {\binom n n}^2 = \binom {2n} n$$

Jumlah terbobot:

$$1 \binom n 1 + 2 \binom n 2 + \cdots + n \binom n n = n 2^{n-1}$$

Hubungan dengan bilangan [Fibonacci](https://cp-algorithms.com/algebra/fibonacci-numbers.html) (*Fibonacci numbers*):

$$\binom n 0 + \binom {n-1} 1 + \cdots + \binom {n-k} k + \cdots + \binom 0 n = F_{n+1}$$

## 3. Calculation

### 3.1. Straightforward calculation using analytical formula

Rumus pertama yang bersifat langsung sangat mudah untuk dikodekan, tetapi metode ini kemungkinan besar akan mengalami *overflow*[^1] bahkan untuk nilai $n$ dan $k$ yang relatif kecil (meskipun jawaban akhirnya muat sepenuhnya ke dalam suatu tipe data, perhitungan *intermediate factorials* dapat menyebabkan *overflow*). Oleh karena itu, metode ini seringkali hanya dapat digunakan dengan [long arithmetic](https://cp-algorithms.com/algebra/big-integer.html):

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

### 3.2. Improved implementation

Perhatikan bahwa dalam implementasi di atas, pembilang dan penyebut memiliki jumlah faktor yang sama ($k$), yang masing-masing nilainya lebih besar dari atau sama dengan 1. Oleh karena itu, kita dapat mengganti pecahan tersebut dengan hasil perkalian $k$ buah pecahan, yang masing-masing bernilai real. Meskipun demikian, pada setiap langkah setelah mengalikan jawaban saat ini dengan masing-masing pecahan berikutnya, hasilnya akan tetap berupa integer (hal ini sesuai dengan properti faktorisasi).

Implementasi C++:

```cpp
int C(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}
```

Di sini kita secara hati-hati melakukan cast dari floating point ke integer, dengan mempertimbangkan bahwa akibat *accumulated errors* [^2], nilainya mungkin sedikit lebih kecil dari nilai sebenarnya (sebagai contoh, $2.99999$ alih-alih $3$).

### 3.3. Pascal's Triangle

Dengan menggunakan *recurrence relation*, kita dapat menyusun sebuah tabel koefisien binomial (*Pascal's triangle*) dan mengambil hasilnya dari sana. Keuntungan dari metode ini adalah hasil antara (*intermediate results*) tidak pernah melebihi jawaban akhir dan perhitungan setiap elemen tabel baru hanya memerlukan satu operasi penjumlahan. Kelemahannya adalah eksekusi yang lambat untuk $n$ dan $k$ yang besar jika Anda hanya memerlukan satu nilai tunggal dan bukan seluruh tabel (karena untuk menghitung $\binom n k$, Anda perlu membangun tabel untuk semua $\binom i j, 1 \le i \le n, 1 \le j \le n$, atau setidaknya sampai $1 \le j \le \min (i, 2k)$). *Time complexity* dapat dianggap sebesar $O(n^2)$.

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

Jika seluruh tabel nilai tidak diperlukan, cukup simpan dua baris terakhir saja (baris ke-$n$ saat ini dan baris ke-$n-1$ sebelumnya).

### 3.4. Calculation in $O(1)$

Terakhir, dalam beberapa situasi akan lebih menguntungkan untuk melakukan *precompute* semua faktorial agar dapat menghasilkan koefisien binomial yang diperlukan hanya dengan dua operasi pembagian nantinya. Hal ini bisa bermanfaat saat menggunakan [long arithmetic](https://cp-algorithms.com/algebra/big-integer.html), ketika memori tidak memungkinkan untuk melakukan precomputation seluruh Pascal's triangle.

## 4. Computing binomial coefficients modulo $m$

Sering kali Anda akan menemui masalah penghitungan koefisien binomial modulo suatu $m$.

### 4.1. Binomial coefficient for small $n$

Pendekatan *Pascal's triangle* yang dibahas sebelumnya dapat digunakan untuk menghitung semua nilai $\binom{n}{k} \bmod m$ untuk nilai $n$ yang cukup kecil, karena metode ini memerlukan *time complexity* $O(n^2)$. Pendekatan ini dapat menangani modulo apa pun, karena hanya menggunakan operasi penjumlahan.

### 4.2. Binomial coefficient modulo large prime

Rumus untuk koefisien binomial adalah

$$\binom n k = \frac {n!} {k!(n-k)!},$$

sehingga jika kita ingin menghitungnya modulo suatu bilangan prima $m > n$, kita mendapatkan

$$\binom n k \equiv n! \cdot (k!)^{-1} \cdot ((n-k)!)^{-1} \pmod m.$$

Pertama, kita melakukan *precompute* semua faktorial modulo $m$ hingga $\text{MAXN}!$ dalam waktu $O(\text{MAXN})$.

```cpp
factorial[0] = 1;
for (int i = 1; i <= MAXN; i++) {
    factorial[i] = factorial[i - 1] * i % m;
}
```

Dan setelah itu kita dapat menghitung koefisien binomial dalam waktu $O(\log m)$.

```cpp
long long binomial_coefficient(int n, int k) {
    return factorial[n] * inverse(factorial[k] * factorial[n - k] % m) % m;
}
```

Kita bahkan dapat menghitung koefisien binomial dalam waktu $O(1)$ jika kita melakukan *precompute* terhadap inverse dari semua faktorial dalam waktu $O(\text{MAXN} \log m)$ menggunakan metode reguler untuk menghitung inverse, atau bahkan dalam waktu $O(\text{MAXN})$ menggunakan kongruensi $(x!)^{-1} \equiv ((x-1)!)^{-1} \cdot x^{-1}$ dan metode untuk [menghitung semua inverse](https://cp-algorithms.com/algebra/module-inverse.html#mod-inv-all-num) dalam $O(n)$.

```cpp
long long binomial_coefficient(int n, int k) {
    return factorial[n] * inverse_factorial[k] % m * inverse_factorial[n - k] % m;
}
```

### 4.3. Binomial coefficient modulo prime power

Di sini kita ingin menghitung koefisien binomial modulo suatu pangkat bilangan prima, yaitu $m = p^b$ untuk suatu bilangan prima $p$. Jika $p > \max(k, n-k)$, maka kita dapat menggunakan metode yang sama seperti yang dijelaskan pada bagian sebelumnya. Namun, jika $p \le \max(k, n-k)$, maka setidaknya salah satu dari $k!$ dan $(n-k)!$ tidak *coprime* dengan $m$, dan oleh karena itu kita tidak dapat menghitung modular inverse-nya karena inverse tersebut tidak ada. Meskipun demikian, kita tetap bisa menghitung koefisien binomialnya.

Idenya adalah sebagai berikut: Untuk setiap $x!$, kita hitung eksponen terbesar $c$ sedemikian sehingga $p^c$ habis membagi $x!$, yaitu $p^c ~|~ x!$. Misalkan $c(x)$ adalah angka tersebut, dan misalkan $g(x) := \frac{x!}{p^{c(x)}}$. Dengan demikian, kita dapat menuliskan koefisien binomial sebagai:

$$\binom n k = \frac {g(n) p^{c(n)}} {g(k) p^{c(k)} g(n-k) p^{c(n-k)}} = \frac {g(n)} {g(k) g(n-k)}p^{c(n) - c(k) - c(n-k)}$$

Hal yang menarik adalah $g(x)$ sekarang sudah bebas dari faktor prima $p$. Oleh karena itu, $g(x)$ bersifat *coprime* terhadap $m$, dan kita bisa menghitung modular inverse dari $g(k)$ dan $g(n-k)$.

Setelah melakukan precompute untuk semua nilai $g$ dan $c$, yang dapat dilakukan secara efisien menggunakan *dynamic programming* dalam $O(n)$, kita dapat menghitung koefisien binomial dalam waktu $O(\log m)$. Atau, kita bisa melakukan *precompute* untuk semua inverse dan semua pangkat dari $p$, lalu menghitung koefisien binomial dalam $O(1)$.

Perhatikan bahwa jika $c(n) - c(k) - c(n-k) \ge b$, maka $p^b ~|~ p^{c(n) - c(k) - c(n-k)}$, sehingga koefisien binomialnya adalah $0$.

### 4.4. Binomial coefficient modulo an arbitrary number

Sekarang kita akan menghitung koefisien binomial modulo suatu modulus sembarang $m$.

Misalkan faktorisasi prima dari $m$ adalah $m = p_1^{e_1} p_2^{e_2} \cdots p_h^{e_h}$. Kita dapat menghitung koefisien binomial modulo $p_i^{e_i}$ untuk setiap $i$. Ini akan memberikan kita $h$ buah kongruensi yang berbeda. Karena semua moduli $p_i^{e_i}$ bersifat coprime, kita dapat menerapkan [Chinese Remainder Theorem](https://cp-algorithms.com/algebra/chinese-remainder-theorem.html) untuk menghitung koefisien binomial modulo hasil kali dari semua moduli tersebut, yang merupakan koefisien binomial modulo $m$ yang kita cari.
### 4.5. Binomial coefficient for large  $n$  and small modulo

Ketika $n$ terlalu besar, algoritma $O(n)$ yang dibahas di atas menjadi tidak praktis. Namun, jika modulus $m$ bernilai kecil, masih ada cara untuk menghitung $\binom{n}{k} \bmod m$.

Ketika modulus $m$ adalah bilangan prima, ada 2 opsi:

1. [Lucas's theorem](https://en.wikipedia.org/wiki/Lucas's_theorem) dapat diterapkan untuk memecah masalah penghitungan $\binom{n}{k} \bmod m$ menjadi $\log_m n$ masalah dalam bentuk $\binom{x_i}{y_i} \bmod m$ di mana $x_i, y_i < m$. Jika setiap koefisien yang sudah disederhanakan dihitung menggunakan *precomputed factorials* dan *inverse factorials*, kompleksitasnya adalah $O(m + \log_m n)$.
    
2. Metode penghitungan [factorial modulo P](https://cp-algorithms.com/algebra/factorial-modulo.html) dapat digunakan untuk mendapatkan nilai $g$ dan $c$ yang diperlukan, lalu menggunakannya seperti yang dijelaskan pada bagian modulo pangkat bilangan prima ([modulo prime power](https://cp-algorithms.com/combinatorics/binomial-coefficients.html#mod-prime-pow)). Ini memakan waktu $O(m \log_m n)$.


Ketika $m$ bukan bilangan prima tetapi merupakan _square-free_ (tidak memiliki faktor kuadrat), faktor prima dari $m$ dapat dicari dan koefisien modulo setiap faktor prima tersebut dapat dihitung menggunakan salah satu metode di atas. Jawaban keseluruhan kemudian diperoleh melalui Chinese Remainder Theorem.

Ketika $m$ bukan _square-free_, [generalisasi Lucas's theorem untuk pangkat bilangan prima](https://web.archive.org/web/20170202003812/http://www.dms.umontreal.ca/~andrew/PDF/BinCoeff.pdf) dapat diterapkan sebagai pengganti Lucas's theorem yang biasa.
## 5. Practice Problems

- [Codechef - Number of ways](https://www.codechef.com/LTIME24/problems/NWAYS/)
- [Codeforces - Curious Array](http://codeforces.com/problemset/problem/407/C)
- [LightOj - Necklaces](http://www.lightoj.com/volume_showproblem.php?problem=1419)
- [HACKEREARTH: Binomial Coefficient](https://www.hackerearth.com/problem/algorithm/binomial-coefficient-1/description/)
- [SPOJ - Ada and Teams](http://www.spoj.com/problems/ADATEAMS/)
- [SPOJ - Greedy Walking](http://www.spoj.com/problems/UCV2013E/)
- [UVa 13214 - The Robot's Grid](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5137)
- [SPOJ - Good Predictions](http://www.spoj.com/problems/GOODB/)
- [SPOJ - Card Game](http://www.spoj.com/problems/HC12/)
- [SPOJ - Topper Rama Rao](http://www.spoj.com/problems/HLP_RAMS/)
- [UVa 13184 - Counting Edges and Graphs](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=5095)
- [Codeforces - Anton and School 2](http://codeforces.com/contest/785/problem/D)
- [Codeforces - Bacterial Melee](http://codeforces.com/contest/760/problem/F)
- [Codeforces - Points, Lines and Ready-made Titles](http://codeforces.com/contest/872/problem/E)
- [SPOJ - The Ultimate Riddle](https://www.spoj.com/problems/DCEPC13D/)
- [CodeChef - Long Sandwich](https://www.codechef.com/MAY17/problems/SANDWICH/)
- [Codeforces - Placing Jinas](https://codeforces.com/problemset/problem/1696/E)

## 6. References

- [Blog fishi.devtail.io](https://fishi.devtail.io/weblog/2015/06/25/computing-large-binomial-coefficients-modulo-prime-non-prime/)
- [Question on Mathematics StackExchange](https://math.stackexchange.com/questions/95491/n-choose-k-bmod-m-using-chinese-remainder-theorem)
- [Question on CodeChef Discuss](https://discuss.codechef.com/questions/98129/your-approach-to-solve-sandwich)

[^1]: **Overflow** adalah kondisi ketika hasil dari suatu perhitungan aritmetika melampaui kapasitas penyimpanan maksimum yang dapat ditampung oleh suatu tipe data (misalnya `int`, `long`, atau `float`). Dalam komputer, setiap tipe data memiliki batas memori tertentu (misalnya $32$-bit atau $64$-bit). Jika hasil operasi melebihi batas atas tersebut, nilai tersebut akan "meluap" dan biasanya berputar kembali ke nilai minimum (negatif), yang mengakibatkan hasil perhitungan menjadi salah secara total dan tidak terprediksi.
[^2]: **Accumulated error** adalah penumpukan kesalahan kecil yang terjadi akibat pembulatan atau keterbatasan presisi angka pada setiap tahap perhitungan berulang. Dalam komputasi, karena tipe data seperti floating point tidak bisa merepresentasikan angka riil tertentu secara sempurna (misalnya hasil pembagian yang berulang), selisih tipis antara nilai komputer dan nilai matematika sebenarnya akan terus bertambah besar seiring banyaknya operasi yang dilakukan, hingga akhirnya dapat memengaruhi hasil akhir secara signifikan.