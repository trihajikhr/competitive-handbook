---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Extended Euclidean Algorithm
sumber:
  - cp-algorithms.com
date_learned: 2025-10-24T00:03:00
tags:
  - cp-algorithms
---
Link Sumber: [Extended Euclidean Algorithm - Algorithms for Competitive Programming](https://cp-algorithms.com/algebra/extended-euclid-algorithm.html)

---
# Extended Euclidean Algorithm

Sementara [Algoritma Euclidean](https://cp-algorithms.com/algebra/euclid-algorithm.html) (*Euclidean algorithm*) hanya menghitung faktor persekutuan terbesar ($\text{GCD}$) dari dua bilangan bulat $a$ dan $b$, versi yang diperluas (*extended version*) juga menemukan cara untuk merepresentasikan $\text{GCD}$ dalam bentuk $a$ dan $b$, yaitu koefisien $x$ dan $y$ yang memenuhi:

$$a \cdot x + b \cdot y = \gcd(a, b)$$

Penting untuk dicatat bahwa berdasarkan [Identitas Bézout](https://en.wikipedia.org/wiki/B%C3%A9zout%27s_identity) (*Bézout's identity*) kita selalu dapat menemukan representasi tersebut. Misalnya, $\gcd(55, 80) = 5$, oleh karena itu kita dapat merepresentasikan $5$ sebagai kombinasi linear (*linear combination*) dengan suku $55$ dan $80$: $55 \cdot 3 + 80 \cdot (-2) = 5$.

Bentuk masalah yang lebih umum dibahas dalam artikel tentang [Persamaan Diophantine Linear](https://cp-algorithms.com/algebra/linear-diophantine-equation.html) (*Linear Diophantine Equations*). Pembahasan tersebut akan dibangun di atas algoritma ini.

## 1 | Algorithm

Kita akan menandai $\text{GCD}$ dari $a$ dan $b$ dengan $g$ di bagian ini.

Perubahan pada algoritma aslinya sangat sederhana. Jika kita mengingat kembali algoritmanya, kita dapat melihat bahwa algoritma tersebut berakhir dengan $b = 0$ dan $a = g$. Untuk parameter ini, kita dapat dengan mudah menemukan koefisien, yaitu $g \cdot 1 + 0 \cdot 0 = g$.

Mulai dari koefisien ini, $(x, y) = (1, 0)$, kita dapat mundur ke atas melalui panggilan rekursif. Yang perlu kita lakukan hanyalah mencari tahu bagaimana koefisien $x$ dan $y$ berubah selama transisi dari $(a, b)$ ke $(b, a \bmod b)$.

Mari kita asumsikan kita telah menemukan koefisien $(x_1, y_1)$ untuk $(b, a \bmod b)$:

$$b \cdot x_1 + (a \bmod b) \cdot y_1 = g$$

dan kita ingin menemukan pasangan $(x, y)$ untuk $(a, b)$:

$$ a \cdot x + b \cdot y = g$$

Kita dapat merepresentasikan $a \bmod b$ sebagai:

$$ a \bmod b = a - \left\lfloor \frac{a}{b} \right\rfloor \cdot b$$

Mensubstitusikan ekspresi ini ke dalam persamaan koefisien $(x_1, y_1)$ menghasilkan:

$$ g = b \cdot x_1 + (a \bmod b) \cdot y_1 = b \cdot x_1 + \left(a - \left\lfloor \frac{a}{b} \right\rfloor \cdot b \right) \cdot y_1$$

dan setelah menyusun ulang suku-suku (*rearranging the terms*):

$$g = a \cdot y_1 + b \cdot \left( x_1 - y_1 \cdot \left\lfloor \frac{a}{b} \right\rfloor \right)$$

Kita menemukan nilai $x$ dan $y$:

$$\begin{cases} x = y_1 \\ y = x_1 - y_1 \cdot \left\lfloor \frac{a}{b} \right\rfloor \end{cases} $$

## 2 | Implementasi

```cpp
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
```

Fungsi rekursif di atas mengembalikan $\text{GCD}$ ($d$) dan nilai-nilai koefisien ke $x$ dan $y$ (yang dilewatkan ke fungsi dengan referensi (*passed by reference*)).

Implementasi Algoritma Euclidean Diperluas ini juga menghasilkan hasil yang benar untuk bilangan bulat negatif.

## 3 | Versi Iteratif

Dimungkinkan juga untuk menulis Algoritma Euclidean Diperluas (*Extended Euclidean Algorithm*) dalam cara iteratif. Karena menghindari rekursi, kode akan berjalan sedikit lebih cepat daripada versi rekursif.

```cpp
int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
```

Jika Anda melihat variabel $a_1$ dan $b_1$ dengan cermat, Anda dapat melihat bahwa keduanya mengambil nilai yang persis sama seperti pada versi iteratif dari [Algoritma Euclidean](https://cp-algorithms.com/algebra/euclid-algorithm.html#implementation) yang biasa. Jadi, algoritma tersebut setidaknya akan menghitung $\text{GCD}$ yang benar.

Untuk melihat mengapa algoritma menghitung koefisien yang benar, pertimbangkan bahwa invarian (*invariants*) berikut berlaku pada waktu tertentu (sebelum *loop* `while` dimulai dan pada akhir setiap iterasi):

$$x \cdot a + y \cdot b = a_1$$
$$x_1 \cdot a + y_1 \cdot b = b_1$$

Biarkan nilai-nilai di akhir sebuah iterasi dilambangkan dengan tanda aksen ($\text{'}$), dan asumsikan $q = \frac{a_1}{b_1}$. Dari [Algoritma Euclidean](https://cp-algorithms.com/algebra/euclid-algorithm.html), kita memiliki:

$$a_1' = b_1$$
$$b_1' = a_1 - q \cdot b_1$$

Agar invarian pertama berlaku, hal berikut harus benar:

$$x' \cdot a + y' \cdot b = a_1' = b_1$$
$$x' \cdot a + y' \cdot b = x_1 \cdot a + y_1 \cdot b$$

Demikian pula untuk invarian kedua, hal berikut harus berlaku:

$$x_1' \cdot a + y_1' \cdot b = a_1 - q \cdot b_1$$
$$x_1' \cdot a + y_1' \cdot b = (x - q \cdot x_1) \cdot a + (y - q \cdot y_1) \cdot b$$

Dengan membandingkan koefisien $a$ dan $b$, persamaan pembaruan (*update equations*) untuk setiap variabel dapat diturunkan, memastikan bahwa invarian dipertahankan di sepanjang algoritma.

Pada akhirnya, kita tahu bahwa $a_1$ mengandung $\text{GCD}$, jadi $x \cdot a + y \cdot b = g$. Ini berarti bahwa kita telah menemukan koefisien yang diperlukan.

Anda bahkan dapat mengoptimalkan kodenya lebih lanjut dan menghapus variabel $a_1$ dan $b_1$ dari kode, dan hanya menggunakan kembali $a$ dan $b$. Namun, jika Anda melakukannya, Anda kehilangan kemampuan untuk berargumen mengenai invarian.

## 4 | Practice Problems

- [UVA - 10104 - Euclid Problem](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1045)
- [GYM - (J) Once Upon A Time](http://codeforces.com/gym/100963)
- [UVA - 12775 - Gift Dilemma](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4628)