---
obsidianUIMode: preview
note_type: book theory
judul_materi: Primality Tests
sumber:
  - cp-algorithms.com
date_learned: 2026-01-28T22:02:00
tags:
  - number-theory
  - cp-algorithms
---
Link Sumber: [Primality tests - Algorithms for Competitive Programming](https://cp-algorithms.com/algebra/primality_tests.html)

---

> [!IMPORTANT]
>  
# Primality Tests

Artikel ini menjelaskan berbagai algoritma untuk menentukan apakah sebuah angka adalah bilangan prima atau bukan.
## 1. Pembagian Percobaan (_Trial Division_)

Berdasarkan definisinya, bilangan prima tidak memiliki pembagi selain $1$ dan dirinya sendiri. Bilangan komposit memiliki setidaknya satu pembagi tambahan, sebut saja $d$. Secara alami, $\frac{n}{d}$ juga merupakan pembagi dari $n$. Mudah untuk melihat bahwa salah satu dari $d \le \sqrt{n}$ atau $\frac{n}{d} \le \sqrt{n}$ adalah benar, oleh karena itu salah satu pembagi $d$ dan $\frac{n}{d}$ bernilai $\le \sqrt{n}$. Kita dapat menggunakan informasi ini untuk memeriksa primalitas.

Kita mencoba mencari pembagi non-trivial dengan memeriksa apakah ada angka antara $2$ dan $\sqrt{n}$ yang merupakan pembagi dari $n$. Jika ditemukan pembagi, maka $n$ sudah pasti bukan prima, jika tidak, maka $n$ adalah prima.

```cpp
bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return x >= 2;
}
```

Ini adalah bentuk paling sederhana dari pemeriksaan prima. Anda dapat mengoptimalkan fungsi ini cukup banyak, misalnya dengan hanya memeriksa semua bilangan ganjil di dalam perulangan (_loop_), karena satu-satunya bilangan prima genap adalah 2. Berbagai optimalisasi serupa dijelaskan dalam artikel tentang [faktorisasi integer](https://cp-algorithms.com/algebra/factorization.html) (_integer factorization_).
## 2. Pengujian Primalitas Fermat (*Fermat primality test*)

Ini adalah pengujian probabilistik (_probabilistic test_).

Teorema kecil Fermat (_Fermat's little theorem_) (lihat juga [Euler's totient function](https://cp-algorithms.com/algebra/phi-function.html)) menyatakan bahwa untuk sebuah bilangan prima $p$ dan sebuah integer $a$ yang koprim (_coprime_), persamaan berikut berlaku:

$$a^{p-1} \equiv 1 \bmod p$$

Secara umum, teorema ini tidak berlaku untuk bilangan komposit.

Hal ini dapat digunakan untuk membuat pengujian primalitas. Kita memilih sebuah integer $2 \le a \le p - 2$, dan memeriksa apakah persamaan tersebut berlaku atau tidak. Jika tidak berlaku, misalnya $a^{p-1} \not\equiv 1 \bmod p$, kita tahu bahwa $p$ tidak mungkin merupakan bilangan prima. Dalam kasus ini, kita menyebut basis $a$ sebagai saksi Fermat (_Fermat witness_) untuk kekompositan $p$.

Namun, ada kemungkinan juga bahwa persamaan tersebut berlaku untuk bilangan komposit. Jadi, jika persamaan tersebut berlaku, kita tidak memiliki bukti untuk primalitas. Kita hanya bisa mengatakan bahwa $p$ adalah probabilitas prima (_probably prime_). Jika ternyata angka tersebut sebenarnya adalah komposit, kita menyebut basis $a$ sebagai pembohong Fermat (_Fermat liar_).

Dengan menjalankan pengujian untuk semua basis $a$ yang mungkin, kita sebenarnya dapat membuktikan bahwa sebuah angka adalah prima. Namun, hal ini tidak dilakukan dalam praktik, karena membutuhkan usaha yang jauh lebih besar daripada sekadar melakukan pembagian percobaan (_trial division_). Sebaliknya, pengujian akan diulang berkali-kali dengan pilihan acak untuk $a$. Jika kita tidak menemukan saksi untuk kekompositan, sangat mungkin bahwa angka tersebut memang prima.

```cpp
bool probablyPrimeFermat(int n, int iter=5) {
    if (n < 4)
        return n == 2 || n == 3;

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (binpower(a, n - 1, n) != 1)
            return false;
    }
    return true;
}
```

Kita menggunakan [perpangkatan biner](https://cp-algorithms.com/algebra/binary-exp.html) (_binary exponentiation_) untuk menghitung pangkat $a^{p-1}$ secara efisien.

Ada satu kabar buruk: terdapat beberapa bilangan komposit di mana $a^{n-1} \equiv 1 \bmod n$ berlaku untuk semua $a$ yang koprim (_coprime_) terhadap $n$, misalnya untuk angka $561 = 3 \cdot 11 \cdot 17$. Angka-angka seperti ini disebut bilangan Carmichael (_Carmichael numbers_). Pengujian primalitas Fermat hanya dapat mengidentifikasi angka-angka ini jika kita sangat beruntung dan memilih basis $a$ dengan $\gcd(a, n) \ne 1$.

Pengujian Fermat masih digunakan dalam praktik karena sangat cepat dan bilangan Carmichael sangat jarang terjadi. Sebagai contoh, hanya terdapat 646 angka tersebut di bawah $10^9$.
## 3. Pengujian Primalitas Miller-Rabin (*Miller-Rabin primality test*)

Pengujian Miller-Rabin memperluas ide dari pengujian Fermat. Untuk sebuah bilangan ganjil $n$, maka $n-1$ adalah genap dan kita dapat mengeluarkan semua faktor pangkat 2. Kita dapat menuliskan:

$$n - 1 = 2^s \cdot d,~\text{dengan}~d~\text{ganjil.}$$

Hal ini memungkinkan kita untuk memfaktorkan persamaan dari Teorema Kecil Fermat:

$$\begin{array}{rl} a^{n-1} \equiv 1 \bmod n &\Longleftrightarrow a^{2^s d} - 1 \equiv 0 \bmod n \\\\ &\Longleftrightarrow (a^{2^{s-1} d} + 1) (a^{2^{s-1} d} - 1) \equiv 0 \bmod n \\\\ &\Longleftrightarrow (a^{2^{s-1} d} + 1) (a^{2^{s-2} d} + 1) (a^{2^{s-2} d} - 1) \equiv 0 \bmod n \\\\ &\quad\vdots \\\\ &\Longleftrightarrow (a^{2^{s-1} d} + 1) (a^{2^{s-2} d} + 1) \cdots (a^{d} + 1) (a^{d} - 1) \equiv 0 \bmod n \\\\ \end{array}$$

Jika $n$ adalah prima, maka $n$ harus membagi salah satu dari faktor-faktor ini. Dalam pengujian primalitas Miller-Rabin, kita memeriksa tepat pernyataan tersebut, yang merupakan versi lebih ketat dari pernyataan pada pengujian Fermat. Untuk basis $2 \le a \le n-2$, kita memeriksa apakah salah satu dari kondisi berikut:

$$a^d \equiv 1 \bmod n$$

berlaku, atau

$$a^{2^r d} \equiv -1 \bmod n$$

berlaku untuk suatu $0 \le r \le s - 1$.

Jika kita menemukan basis $a$ yang tidak memenuhi satu pun dari persamaan di atas, maka kita telah menemukan saksi (_witness_) untuk kekompositan $n$. Dalam kasus ini, kita telah membuktikan bahwa $n$ bukan bilangan prima.

Sama seperti pengujian Fermat, ada kemungkinan bahwa kumpulan persamaan tersebut dipenuhi oleh bilangan komposit. Dalam hal ini, basis $a$ disebut sebagai pembohong kuat (_strong liar_). Jika sebuah basis $a$ memenuhi persamaan (salah satunya), maka $n$ hanyalah probabilitas prima kuat (_strong probable prime_). Namun, tidak ada angka seperti bilangan Carmichael, di mana semua basis non-trivial berbohong. Faktanya, dapat ditunjukkan bahwa paling banyak $\frac{1}{4}$ dari basis yang ada bisa menjadi pembohong kuat. Jika $n$ adalah komposit, kita memiliki probabilitas $\ge 75\%$ bahwa basis acak akan memberitahu kita bahwa angka tersebut komposit. Dengan melakukan beberapa iterasi menggunakan basis acak yang berbeda, kita dapat menentukan dengan probabilitas sangat tinggi apakah angka tersebut benar-benar prima atau komposit.

Berikut adalah implementasi untuk integer 64 bit.

```cpp
using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n, int iter=5) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}
```

Sebelum pengujian Miller-Rabin, Anda dapat menguji tambahan apakah salah satu dari beberapa bilangan prima pertama adalah pembagi. Ini dapat mempercepat pengujian secara signifikan, karena sebagian besar bilangan komposit memiliki pembagi prima yang sangat kecil. Contohnya, $88\%$ dari semua angka memiliki faktor prima yang lebih kecil dari $100$.
## 4. Versi Deterministik (*Deterministic version*)

Miller menunjukkan bahwa algoritma ini dapat dibuat deterministik hanya dengan memeriksa semua basis $\le O((\ln n)^2)$. Bach kemudian memberikan batasan konkret, yaitu hanya perlu menguji semua basis $a \le 2 \ln(n)^2$.

Angka tersebut masih merupakan jumlah basis yang cukup besar. Oleh karena itu, banyak orang telah menginvestasikan daya komputasi yang besar untuk menemukan batasan bawah yang lebih kecil. Ternyata, untuk menguji integer 32 bit, kita hanya perlu memeriksa 4 basis prima pertama: 2, 3, 5, dan 7. Bilangan komposit terkecil yang gagal dalam pengujian ini adalah $3,215,031,751 = 151 \cdot 751 \cdot 28351$. Sedangkan untuk menguji integer 64 bit, cukup dengan memeriksa 12 basis prima pertama: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, dan 37.

Hal ini menghasilkan implementasi deterministik sebagai berikut:

```cpp
bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}
```

Dimungkinkan juga untuk melakukan pemeriksaan hanya dengan 7 basis: 2, 325, 9375, 28178, 450775, 9780504, dan 1795265022. Namun, karena angka-angka ini (kecuali 2) bukan bilangan prima, Anda perlu memeriksa secara tambahan apakah angka yang Anda periksa sama dengan salah satu pembagi prima dari basis-basis tersebut: 2, 3, 5, 13, 19, 73, 193, 407521, 299210837.