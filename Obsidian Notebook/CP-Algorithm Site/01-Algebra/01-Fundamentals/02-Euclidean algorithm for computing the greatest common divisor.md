---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Euclidean algorithm for computing the greatest common divisor
sumber:
  - cp-algorithms.com
date_learned: 2025-10-22T22:13:00
tags:
  - cp-algorithms
---
Link Sumber: [Euclidean algorithm for computing the greatest common divisor - Algorithms for Competitive Programming](https://cp-algorithms.com/algebra/euclid-algorithm.html)

---
# Euclidean algorithm for computing the greatest common divisor

Diberikan dua bilangan bulat non-negatif $a$ dan $b$, kita harus mencari $\text{GCD}$ (*greatest common divisor*) atau faktor persekutuan terbesar mereka, yaitu bilangan terbesar yang merupakan pembagi bagi $a$ maupun $b$. Hal ini umumnya dilambangkan dengan $\gcd(a, b)$. Secara matematis didefinisikan sebagai:

$$\gcd(a, b) = \max \{k > 0 : (k \mid a) \text{ dan } (k \mid b) \}$$

(di sini simbol "$\mid$" menunjukkan keterbagian (*divisibility*), yaitu "$k \mid a$" berarti "$k$ membagi $a$")

Ketika salah satu bilangan adalah nol, sementara bilangan lainnya bukan nol, faktor persekutuan terbesar mereka, berdasarkan definisi, adalah bilangan yang bukan nol tersebut. Ketika kedua bilangan adalah nol, faktor persekutuan terbesar mereka tidak terdefinisi (bisa berupa bilangan yang sangat besar secara arbitrer), tetapi mudah untuk mendefinisikannya sebagai nol juga untuk mempertahankan asosiatifitas dari $\gcd$. Ini memberikan kita aturan sederhana: jika salah satu bilangan adalah nol, faktor persekutuan terbesar adalah bilangan lainnya.

Algoritma Euclidean, yang dibahas di bawah, memungkinkan untuk menemukan faktor persekutuan terbesar dari dua bilangan $a$ dan $b$ dalam kompleksitas waktu $O(\log \min(a, b))$. Karena fungsi ini bersifat **asosiatif** (*associative*), untuk menemukan $\text{GCD}$ dari **lebih dari dua bilangan**, kita dapat melakukannya dengan $\gcd(a, b, c) = \gcd(a, \gcd(b, c))$ dan seterusnya.

Algoritma ini pertama kali dijelaskan dalam "Elements" karya Euclid (sekitar $300$ SM), tetapi mungkin saja algoritma tersebut memiliki asal-usul yang lebih awal.

## 1 | Algorithm

Awalnya, Algoritma Euclidean dirumuskan sebagai berikut: kurangi bilangan yang lebih kecil dari bilangan yang lebih besar hingga salah satu bilangan menjadi nol. Memang, jika $g$ membagi $a$ dan $b$, maka $g$ juga membagi $a-b$. Di sisi lain, jika $g$ membagi $a-b$ dan $b$, maka $g$ juga membagi $a = b + (a-b)$, yang berarti bahwa himpunan (*set*) dari pembagi persekutuan untuk $\{a, b\}$ dan $\{b, a-b\}$ adalah sama (*coincide*).

Perhatikan bahwa $a$ tetap menjadi bilangan yang lebih besar sampai $b$ dikurangi darinya setidaknya $\left\lfloor\frac{a}{b}\right\rfloor$ kali. Oleh karena itu, untuk mempercepat proses, $a-b$ disubstitusikan dengan $a-\left\lfloor\frac{a}{b}\right\rfloor b = a \bmod b$. Kemudian algoritma dirumuskan dengan cara yang sangat sederhana:

$$\gcd(a, b) = \begin{cases}a,&\text{jika }b = 0 \\ \gcd(b, a \bmod b),&\text{selain itu.}\end{cases}$$
## 2 | Implementation

```cpp
int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
```

Menggunakan operator ternary (*ternary operator*) dalam C++, kita dapat menuliskannya dalam satu baris.

```cpp
int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}
```

Dan terakhir, berikut adalah implementasi non-rekursif:

```cpp
int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
```

Perlu dicatat bahwa sejak C++17, `gcd` telah diimplementasikan sebagai [fungsi standar](https://en.cppreference.com/w/cpp/numeric/gcd) (*standard function*) dalam C++.

## 3 | Time Complexity

Waktu berjalan (*running time*) dari algoritma ini diperkirakan oleh **Teorema Lamé** (*Lamé's theorem*), yang menetapkan hubungan mengejutkan antara Algoritma Euclidean dan **barisan Fibonacci** (*Fibonacci sequence*):

Jika $a > b \geq 1$ dan $b < F_n$ untuk suatu $n$, Algoritma Euclidean melakukan paling banyak $n-2$ panggilan rekursif.

Selain itu, mungkin untuk menunjukkan bahwa batas atas (*upper bound*) dari teorema ini adalah optimal. Ketika $a = F_n$ dan $b = F_{n-1}$, $\gcd(a, b)$ akan melakukan tepat $n-2$ panggilan rekursif. Dengan kata lain, bilangan Fibonacci yang berurutan adalah masukan/input kasus terburuk (*worst case input*) untuk algoritma Euclid.

Mengingat bahwa bilangan Fibonacci tumbuh secara eksponensial, kita mendapatkan bahwa Algoritma Euclidean bekerja dalam $O(\log \min(a, b))$.

Cara lain untuk memperkirakan kompleksitas adalah dengan memperhatikan bahwa $a \bmod b$ untuk kasus $a \geq b$ setidaknya $2$ kali lebih kecil dari $a$, sehingga bilangan yang lebih besar berkurang setidaknya menjadi separuhnya pada setiap iterasi algoritma. Menerapkan penalaran ini pada kasus ketika kita menghitung $\text{GCD}$ dari himpunan bilangan $a_1, \dots, a_n \leq C$, ini juga memungkinkan kita untuk memperkirakan total waktu berjalan sebagai $O(n + \log C)$, dan bukan $O(n \log C)$, karena setiap iterasi non-trivial dari algoritma mengurangi kandidat $\text{GCD}$ saat ini setidaknya dengan faktor $2$.

## 3 | Least common multiple

Menghitung **kelipatan persekutuan terkecil** (umumnya dilambangkan $\text{LCM}$) dapat direduksi menjadi penghitungan $\text{GCD}$ dengan rumus sederhana berikut:

$$\text{lcm}(a, b) = \frac{a \cdot b}{\gcd(a, b)}$$

Dengan demikian, $\text{LCM}$ dapat dihitung menggunakan **Algoritma Euclidean** dengan kompleksitas waktu yang sama.

Berikut diberikan kemungkinan implementasi yang dengan cerdik menghindari *integer overflow* dengan cara membagi $a$ terlebih dahulu dengan $\text{GCD}$:

```cpp
int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}
```

## 4 | Binary GCD

Algoritma **GCD Biner** (*Binary GCD*) adalah sebuah optimasi (*optimization*) dari Algoritma Euclidean yang biasa.

Bagian lambat dari algoritma normal adalah operasi **modulo**. Meskipun kita melihat operasi modulo sebagai $O(1)$, operasi tersebut jauh lebih lambat daripada operasi yang lebih sederhana seperti penjumlahan, pengurangan, atau operasi *bitwise*. Jadi, akan lebih baik untuk menghindarinya.

Ternyata, kita dapat merancang algoritma $\text{GCD}$ yang cepat dan menghindari operasi modulo. Algoritma ini didasarkan pada beberapa properti (*properties*):

- **Jika kedua bilangan genap**, maka kita dapat memfaktorkan (*factor out*) dua dari keduanya dan menghitung $\text{GCD}$ dari bilangan sisanya: $\gcd(2a, 2b) = 2 \gcd(a, b)$.

<br/>

- **Jika salah satu bilangan genap dan yang lainnya ganjil**, maka kita dapat menghilangkan faktor $2$ dari bilangan yang genap: $\gcd(2a, b) = \gcd(a, b)$ jika $b$ ganjil.

<br/>

- **Jika kedua bilangan ganjil**, maka mengurangi satu bilangan dari bilangan lainnya tidak akan mengubah $\text{GCD}$: $\gcd(a, b) = \gcd(b, a-b)$.

Hanya dengan menggunakan properti-properti ini, dan beberapa fungsi *bitwise* cepat dari **GCC**, kita dapat mengimplementasikan versi cepat:

```c
int gcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}
```

Perhatikan, bahwa optimasi semacam ini biasanya tidak diperlukan, dan sebagian besar bahasa pemrograman sudah memiliki fungsi $\text{GCD}$ dalam *standard libraries* mereka. Contohnya, C++17 memiliki fungsi standar `std::gcd` dalam *header* `numeric`.
## 5 | Practice Problems

- [CSAcademy - Greatest Common Divisor](https://csacademy.com/contest/archive/task/gcd/)
- [Codeforces 1916B - Two Divisors](https://codeforces.com/contest/1916/problem/B)