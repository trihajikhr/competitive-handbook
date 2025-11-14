---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Fibonacci Numbers
sumber:
  - cp-algorithms.com
date_learned: 2025-10-24T00:45:00
tags:
  - cp-algorithms
  - algorithm
---
Link Sumber: [Fibonacci Numbers - Algorithms for Competitive Programming](https://cp-algorithms.com/algebra/fibonacci-numbers.html)

---
# Fibonacci Numbers

**Barisan Fibonacci** (*Fibonacci Sequence*) didefinisikan sebagai berikut:

$$F_0 = 0, F_1 = 1, F_n = F_{n-1} + F_{n-2}$$

Elemen-elemen pertama dari barisan ini ([OEIS A000045](http://oeis.org/A000045)) adalah:

$$0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, \dots$$
## 1 | Properties

Bilangan Fibonacci memiliki banyak properti (*properties*) yang menarik. Berikut adalah beberapa di antaranya:

- Identitas Cassini (*Cassini's identity*):
	$$F_{n-1} F_{n+1} - F_n^2 = (-1)^n$$
	Ini dapat dibuktikan dengan **induksi** (*induction*). Bukti satu baris oleh Knuth berasal dari pengambilan determinan (*determinant*) dari bentuk matriks $2 \times 2$ di bawah ini.

<br/>

- Aturan "Penjumlahan" (*"addition" rule*):
	$$F_{n+k} = F_k F_{n+1} + F_{k-1} F_n$$
<br/>

- Menerapkan identitas sebelumnya pada kasus $k = n$, kita mendapatkan:
	$$F_{2n} = F_n (F_{n+1} + F_{n-1})$$
<br/>

- Dari sini kita dapat membuktikan dengan induksi bahwa untuk setiap bilangan bulat positif $k$, $F_{nk}$ adalah **kelipatan** (*multiple*) dari $F_n$.

<br/>

- Kebalikan (*inverse*) dari ini juga benar: jika $F_m$ adalah kelipatan dari $F_n$, maka $m$ adalah kelipatan dari $n$.

<br/>

- Identitas GCD (*GCD identity*):
$$\text{GCD}(F_m, F_n) = F_{\text{GCD}(m, n)}$$
Bilangan Fibonacci adalah masukan kasus terburuk (*worst possible inputs*) untuk Algoritma Euclidean (lihat Teorema Lamé dalam artikel [Algoritma Euclidean](https://cp-algorithms.com/algebra/euclid-algorithm.html)).
## 2 | Fibonacci Coding

Kita dapat menggunakan barisan bilangan Fibonacci untuk mengodekan bilangan bulat positif menjadi kata kode biner (*binary code words*). Menurut **Teorema Zeckendorf** (*Zeckendorf's theorem*), setiap bilangan asli $N$ dapat direpresentasikan secara unik sebagai jumlah bilangan Fibonacci:

$$N = F_{k_1} + F_{k_2} + \ldots + F_{k_r}$$

sedemikian hingga $k_1 \ge k_2 + 2, k_2 \ge k_3 + 2, \ldots, k_r \ge 2$ (yaitu: representasi tersebut tidak dapat menggunakan dua bilangan Fibonacci yang berurutan).

Dari sini disimpulkan bahwa setiap bilangan dapat dienkode secara unik dalam **pengkodean Fibonacci** (*Fibonacci coding*). Dan kita dapat mendeskripsikan representasi ini dengan kata kode biner $d_0 d_1 d_2 \dots d_s 1$, di mana $d_i$ adalah $1$ jika $F_{i+2}$ digunakan dalam representasi. Kode tersebut akan ditambahkan dengan angka $1$ terakhir untuk menunjukkan akhir dari kata kode tersebut. Perhatikan bahwa ini adalah satu-satunya kejadian di mana dua *bit* $1$ yang berurutan muncul.

$$\begin{eqnarray} 1 &=& 1 &=& F_2 &=& (11)_F \\ 2 &=& 2 &=& F_3 &=& (011)_F \\ 6 &=& 5 + 1 &=& F_5 + F_2 &=& (10011)_F \\ 8 &=& 8 &=& F_6 &=& (000011)_F \\ 9 &=& 8 + 1 &=& F_6 + F_2 &=& (100011)_F \\ 19 &=& 13 + 5 + 1 &=& F_7 + F_5 + F_2 &=& (1001011)_F \end{eqnarray}$$

Pengodean (*encoding*) bilangan bulat $n$ dapat dilakukan dengan algoritma *greedy* sederhana (*simple greedy algorithm*):

1.  Iterasi melalui bilangan Fibonacci dari yang terbesar hingga terkecil sampai Anda menemukan bilangan yang kurang dari atau sama dengan $n$.

2.  Misalkan bilangan ini adalah $F_i$. Kurangi $F_i$ dari $n$ dan letakkan $1$ di posisi $i-2$ dari kata kode (*codeword*) (pengindeksan dari $0$ dimulai dari *bit* paling kiri ke paling kanan).

3.  Ulangi hingga tidak ada sisa (*remainder*).

4.  Tambahkan $1$ terakhir ke kata kode untuk menunjukkan akhirnya.

Untuk **mendekode** (*decode*) sebuah kata kode, pertama-tama hapus $1$ terakhir. Kemudian, jika *bit* ke-$i$ diatur (*set*) (pengindeksan dari $0$ dimulai dari *bit* paling kiri ke paling kanan), jumlahkan $F_{i+2}$ ke bilangan tersebut.

## 3 | Formulas for the  $n^{\text{th}}$  Fibonacci number

### 3.1 | Closed-form expression

Ada sebuah rumus yang dikenal sebagai "**Rumus Binet** (*Binet's formula*)," meskipun rumus ini telah dikenal oleh Moivre:

$$F_n = \frac{\left(\frac{1 + \sqrt{5}}{2}\right)^n - \left(\frac{1 - \sqrt{5}}{2}\right)^n}{\sqrt{5}}$$

Rumus ini mudah dibuktikan dengan **induksi** (*induction*), tetapi dapat diturunkan dengan bantuan konsep **fungsi pembangkit** (*generating functions*) atau dengan menyelesaikan **persamaan fungsional** (*functional equation*).

Anda dapat segera melihat bahwa nilai absolut (*absolute value*) dari suku kedua selalu kurang dari $1$, dan nilai tersebut juga menurun dengan sangat cepat (secara eksponensial). Oleh karena itu, nilai dari suku pertama saja "hampir" sama dengan $F_n$. Hal ini dapat ditulis secara ketat sebagai:

$$F_n = \left[\frac{\left(\frac{1 + \sqrt{5}}{2}\right)^n}{\sqrt{5}}\right]$$

di mana tanda kurung siku menunjukkan pembulatan ke bilangan bulat terdekat (*rounding to the nearest integer*).

Karena kedua rumus ini memerlukan akurasi yang sangat tinggi saat bekerja dengan bilangan pecahan (*fractional numbers*), rumus-rumus ini kurang bermanfaat dalam perhitungan praktis.

### 3.2 | Fibonacci in linear time

Bilangan Fibonacci ke-$n$ dapat dengan mudah ditemukan dalam $O(n)$ dengan menghitung bilangan satu per satu hingga $n$. Namun, ada juga cara yang lebih cepat, seperti yang akan kita lihat.

Kita dapat mulai dari **pendekatan iteratif** (*iterative approach*), untuk memanfaatkan penggunaan rumus $F_n = F_{n-1} + F_{n-2}$, oleh karena itu, kita hanya akan melakukan **prakalkulasi** (*precalculate*) nilai-nilai tersebut dalam sebuah larik (*array*). Perhitungan ini harus mempertimbangkan kasus dasar (*base cases*) untuk $F_0$ dan $F_1$.

```cpp
int fib(int n) {
    int a = 0;
    int b = 1;
    for (int i = 0; i < n; i++) {
        int tmp = a + b;
        a = b;
        b = tmp;
    }
    return a;
}
```


Dengan cara ini, kita memperoleh solusi **linear** (*linear solution*), waktu $O(n)$, dengan menyimpan semua nilai sebelum $n$ dalam barisan tersebut.

### 3.3 | Matrix form

Untuk beralih dari $(F_n, F_{n-1})$ ke $(F_{n+1}, F_n)$, kita dapat mengekspresikan **relasi rekurensi linear** (*linear recurrence*) sebagai perkalian matriks $2 \times 2$:

$$\begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix} \begin{pmatrix} F_n \\ F_{n-1} \end{pmatrix} = \begin{pmatrix} F_n + F_{n-1} \\ F_{n} \end{pmatrix} = \begin{pmatrix} F_{n+1} \\ F_{n} \end{pmatrix}$$

Ini memungkinkan kita untuk memperlakukan iterasi rekurensi sebagai perkalian matriks berulang, yang memiliki properti yang bagus. Secara khusus,

$$\begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix}^n \begin{pmatrix} F_1 \\ F_0 \end{pmatrix} = \begin{pmatrix} F_{n+1} \\ F_{n} \end{pmatrix}$$

di mana $F_1 = 1, F_0 = 0$. Bahkan, karena

$$\begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix} = \begin{pmatrix} F_2 & F_1 \\ F_1 & F_0 \end{pmatrix}$$

kita dapat menggunakan matriks secara langsung:

$$\begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix}^n = \begin{pmatrix} F_{n+1} & F_n \\ F_n & F_{n-1} \end{pmatrix}$$

Dengan demikian, untuk menemukan $F_n$ dalam waktu $O(\log n)$, kita harus memangkatkan matriks tersebut dengan $n$. (Lihat [Eksponensiasi Biner](https://cp-algorithms.com/algebra/binary-exp.html) (*Binary exponentiation*))

```cpp
struct matrix {
    long long mat[2][2];
    matrix friend operator *(const matrix &a, const matrix &b){
        matrix c;
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
              c.mat[i][j] = 0;
              for (int k = 0; k < 2; k++) {
                  c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
              }
          }
        }
        return c;
    }
};

matrix matpow(matrix base, long long n) {
    matrix ans{ {
      {1, 0},
      {0, 1}
    } };
    while (n) {
        if(n&1)
            ans = ans*base;
        base = base*base;
        n >>= 1;
    }
    return ans;
}

long long fib(int n) {
    matrix base{ {
      {1, 1},
      {1, 0}
    } };
    return matpow(base, n).mat[0][1];
}
```
### 3.4 | Fast Doubling Method

Dengan menjabarkan (*expanding*) ekspresi matriks di atas untuk $n = 2 \cdot k$:

$$\begin{pmatrix} F_{2k+1} & F_{2k}\\ F_{2k} & F_{2k-1} \end{pmatrix} = \begin{pmatrix} 1 & 1\\ 1 & 0 \end{pmatrix}^{2k} = \begin{pmatrix} F_{k+1} & F_{k}\\ F_{k} & F_{k-1} \end{pmatrix} ^2$$

kita dapat menemukan persamaan yang lebih sederhana ini:

$$ \begin{align} F_{2k+1} &= F_{k+1}^2 + F_{k}^2 \\ F_{2k} &= F_k(F_{k+1}+F_{k-1}) = F_k (2F_{k+1} - F_{k})\\ \end{align}.$$

Dengan demikian, menggunakan dua persamaan di atas, bilangan Fibonacci dapat dihitung dengan mudah melalui kode berikut:

```cpp
pair<int, int> fib (int n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}
```

Kode di atas mengembalikan $F_n$ dan $F_{n+1}$ sebagai pasangan.

## 4 | Periodicity modulo p

Pertimbangkan barisan Fibonacci modulo $p$. Kita akan membuktikan bahwa barisan tersebut bersifat **periodik** (*periodic*).

Mari kita buktikan ini dengan **kontradiksi** (*contradiction*). Pertimbangkan $p^2 + 1$ pasang pertama bilangan Fibonacci yang diambil modulo $p$:

$$(F_0,\ F_1),\ (F_1,\ F_2),\ \ldots,\ (F_{p^2},\ F_{p^2 + 1})$$

Hanya ada $p$ sisa (*remainder*) yang berbeda modulo $p$, dan paling banyak $p^2$ pasang sisa yang berbeda, sehingga terdapat setidaknya dua pasang yang identik di antara mereka. Ini cukup untuk membuktikan bahwa barisan tersebut bersifat periodik, karena bilangan Fibonacci hanya ditentukan oleh dua bilangan pendahulunya (*predecessors*). Oleh karena itu, jika dua pasang bilangan berurutan berulang, itu juga berarti bilangan setelah pasangan tersebut akan berulang dengan cara yang sama (*in the same fashion*).

Sekarang kita memilih dua pasang sisa identik dengan indeks terkecil dalam barisan. Misalkan pasangan tersebut adalah $(F_a,\ F_{a + 1})$ dan $(F_b,\ F_{b + 1})$. Kita akan membuktikan bahwa $a = 0$. Jika ini salah (*false*), akan ada dua pasangan sebelumnya $(F_{a-1},\ F_a)$ dan $(F_{b-1},\ F_b)$, yang, berdasarkan properti bilangan Fibonacci, juga akan sama. Namun, ini bertentangan (*contradicts*) dengan fakta bahwa kita telah memilih pasangan dengan indeks terkececil, yang melengkapi bukti kita bahwa tidak ada **pra-periode** (*pre-period*) (yaitu, bilangan tersebut bersifat periodik mulai dari $F_0$).

## 5 | Practice Problems

- [SPOJ - Euclid Algorithm Revisited](http://www.spoj.com/problems/MAIN74/)
- [SPOJ - Fibonacci Sum](http://www.spoj.com/problems/FIBOSUM/)
- [HackerRank - Is Fibo](https://www.hackerrank.com/challenges/is-fibo/problem)
- [Project Euler - Even Fibonacci numbers](https://www.hackerrank.com/contests/projecteuler/challenges/euler002/problem)
- [DMOJ - Fibonacci Sequence](https://dmoj.ca/problem/fibonacci)
- [DMOJ - Fibonacci Sequence (Harder)](https://dmoj.ca/problem/fibonacci2)
- [DMOJ UCLV - Numbered sequence of pencils](https://dmoj.uclv.edu.cu/problem/secnum)
- [DMOJ UCLV - Fibonacci 2D](https://dmoj.uclv.edu.cu/problem/fibonacci)
- [DMOJ UCLV - fibonacci calculation](https://dmoj.uclv.edu.cu/problem/fibonaccicalculatio)
- [LightOJ - Number Sequence](https://lightoj.com/problem/number-sequence)
- [Codeforces - C. Fibonacci](https://codeforces.com/problemset/gymProblem/102644/C)
- [Codeforces - A. Hexadecimal's theorem](https://codeforces.com/problemset/problem/199/A)
- [Codeforces - B. Blackboard Fibonacci](https://codeforces.com/problemset/problem/217/B)
- [Codeforces - E. Fibonacci Number](https://codeforces.com/problemset/problem/193/E)