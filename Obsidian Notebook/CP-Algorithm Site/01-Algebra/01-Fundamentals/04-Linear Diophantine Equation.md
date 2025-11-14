---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Linear Diophantine Equation
sumber:
  - cp-algorithms.com
date_learned: 2025-10-24T00:18:00
tags:
  - cp-algorithms
---
Link Sumber: [Linear Diophantine Equations - Algorithms for Competitive Programming](https://cp-algorithms.com/algebra/linear-diophantine-equation.html)

---
# Linear Diophantine Equation

Persamaan Diophantine Linear (*Linear Diophantine Equation*) (dalam dua variabel) adalah persamaan dengan bentuk umum:

$$ax + by = c$$

di mana $a$, $b$, $c$ adalah bilangan bulat yang diberikan, dan $x$, $y$ adalah bilangan bulat yang tidak diketahui.

Dalam artikel ini, kita mempertimbangkan beberapa masalah klasik pada persamaan ini:

* menemukan satu solusi
* menemukan semua solusi
* menemukan jumlah solusi dan solusi itu sendiri dalam interval tertentu
* menemukan solusi dengan nilai minimum $x + y$
## 1 | The degenerate case

Kasus degenerasi (*degenerate case*) yang perlu ditangani adalah ketika $a = b = 0$. Mudah dilihat bahwa kita hanya memiliki **tidak ada solusi** (*no solutions*) atau **solusi tak terhingga** (*infinitely many solutions*), tergantung pada apakah $c = 0$ atau tidak. Di sisa artikel ini, kita akan mengabaikan kasus ini.

## 2 | Analytic solution

Ketika $a \neq 0$ dan $b \neq 0$, persamaan $ax+by=c$ dapat diperlakukan secara ekuivalen sebagai salah satu dari yang berikut:

$$\begin{align} ax &\equiv c \pmod b \\ by &\equiv c \pmod a \end{align}$$

Tanpa mengurangi keumuman (*Without loss of generality*), asumsikan bahwa $b \neq 0$ dan pertimbangkan persamaan pertama. Ketika $a$ dan $b$ adalah **koprima** (*co-prime*), solusi untuk itu diberikan sebagai

$$x \equiv ca^{-1} \pmod b,$$

di mana $a^{-1}$ adalah [invers modular](https://cp-algorithms.com/algebra/module-inverse.html) (*modular inverse*) dari $a$ modulo $b$.

Ketika $a$ dan $b$ tidak koprima, nilai $ax$ modulo $b$ untuk semua bilangan bulat $x$ dapat dibagi oleh $g=\gcd(a, b)$, sehingga solusi hanya ada ketika $c$ dapat dibagi oleh $g$. Dalam kasus ini, salah satu solusi dapat ditemukan dengan mereduksi persamaan tersebut dengan $g$:

$$(a/g) x \equiv (c/g) \pmod{b/g}.$$

Menurut definisi $g$, bilangan $a/g$ dan $b/g$ adalah koprima, sehingga solusinya diberikan secara eksplisit sebagai
$$\begin{cases}
x \equiv (c/g)(a/g)^{-1}\pmod{b/g},\\
y = \frac{c-ax}{b}.
\end{cases}$$

## 3 | Algorithmic solution

**Lemma Bézout** (juga disebut **Identitas Bézout**) adalah hasil yang berguna yang dapat digunakan untuk memahami solusi berikut.

> Misalkan $g = \gcd(a,b)$. Maka terdapat bilangan bulat $x,y$ sedemikian sehingga $ax + by = g$. 
> 
> Terlebih lagi, $g$ adalah bilangan bulat positif terkecil yang dapat ditulis dalam bentuk $ax + by$; semua bilangan bulat dalam bentuk $ax + by$ adalah kelipatan (*multiples*) dari $g$.

Untuk menemukan satu solusi dari persamaan Diophantine dengan $2$ variabel tak dikenal, Anda dapat menggunakan [Algoritma Euclidean Diperluas](https://cp-algorithms.com/algebra/extended-euclid-algorithm.html) (*Extended Euclidean algorithm*). Pertama, asumsikan bahwa $a$ dan $b$ adalah non-negatif. Ketika kita menerapkan Algoritma Euclidean Diperluas untuk $a$ dan $b$, kita dapat menemukan faktor persekutuan terbesar mereka $g$ dan $2$ bilangan $x_g$ dan $y_g$ sedemikian sehingga:

$$a x_g + b y_g = g$$

Jika $c$ dapat dibagi oleh $g = \gcd(a, b)$, maka persamaan Diophantine yang diberikan memiliki solusi, jika tidak, persamaan tersebut tidak memiliki solusi. Buktinya langsung (*straight-forward*): kombinasi linear dari dua bilangan dapat dibagi oleh pembagi persekutuan (*common divisor*) mereka.

Sekarang, misalkan $c$ dapat dibagi oleh $g$, maka kita memiliki:

$$a \cdot x_g \cdot \frac{c}{g} + b \cdot y_g \cdot \frac{c}{g} = c$$

Oleh karena itu, salah satu solusi dari persamaan Diophantine adalah:

$$x_0 = x_g \cdot \frac{c}{g},$$

$$y_0 = y_g \cdot \frac{c}{g}.$$

Ide di atas masih berfungsi ketika $a$ atau $b$ atau keduanya negatif. Kita hanya perlu mengubah tanda ($sign$) dari $x_0$ dan $y_0$ bila perlu.

Terakhir, kita dapat mengimplementasikan ide ini sebagai berikut (perhatikan bahwa kode ini tidak mempertimbangkan kasus $a = b = 0$):

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

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
```

## 4 | Mendapatkan Semua Solusi

Dari satu solusi $(x_0, y_0)$, kita dapat memperoleh semua solusi dari persamaan yang diberikan.

Misalkan $g = \gcd(a, b)$ dan misalkan $x_0, y_0$ adalah bilangan bulat yang memenuhi:

$$a \cdot x_0 + b \cdot y_0 = c$$

Sekarang, kita harus melihat bahwa menambahkan $\frac{b}{g}$ ke $x_0$, dan pada saat yang sama mengurangi $\frac{a}{g}$ dari $y_0$ tidak akan merusak kesamaan (*equality*):

$$a \cdot \left(x_0 + \frac{b}{g}\right) + b \cdot \left(y_0 - \frac{a}{g}\right) = a \cdot x_0 + b \cdot y_0 + a \cdot \frac{b}{g} - b \cdot \frac{a}{g} = c$$

Jelas, proses ini dapat diulang, sehingga semua bilangan dalam bentuk:

$$x = x_0 + k \cdot \frac{b}{g}$$

$$y = y_0 - k \cdot \frac{a}{g}$$

adalah solusi dari persamaan Diophantine yang diberikan, di mana $k$ adalah bilangan bulat sembarang.

Karena persamaan ini bersifat **linear**, semua solusi terletak pada garis yang sama, dan berdasarkan definisi $g$, ini adalah himpunan (*set*) dari semua solusi yang mungkin untuk persamaan Diophantine yang diberikan.

## 5 | Finding the number of solutions and the solutions in a given interval

Dari bagian sebelumnya, harus jelas bahwa jika kita tidak memberlakukan batasan (*restrictions*) apa pun pada solusi, akan ada jumlah yang tak terhingga (*infinite number*) dari solusi tersebut. Jadi, di bagian ini, kita menambahkan beberapa batasan pada interval $x$ dan $y$, dan kita akan mencoba menghitung dan **mengenumerasi** (*enumerate*) semua solusinya.

Misalkan ada dua interval: $[\min_x; \max_x]$ dan $[\min_y; \max_y]$ dan katakanlah kita hanya ingin menemukan solusi di dalam kedua interval ini.

Perhatikan bahwa jika $a$ atau $b$ adalah $0$, maka masalah hanya memiliki satu solusi. Kita tidak akan mempertimbangkan kasus ini di sini.

Pertama, kita dapat menemukan solusi yang memiliki nilai $x$ minimum, sedemikian sehingga $x \ge \min_x$. Untuk melakukan ini, kita pertama-tama mencari solusi apa pun dari persamaan Diophantine. Kemudian, kita geser (*shift*) solusi ini untuk mendapatkan $x \ge \min_x$ (menggunakan apa yang kita ketahui tentang himpunan semua solusi di bagian sebelumnya). Ini dapat dilakukan dalam $O(1)$. Tandai nilai minimum $x$ ini sebagai $l_{x1}$.

Demikian pula, kita dapat menemukan nilai maksimum $x$ yang memenuhi $x \le \max_x$. Tandai nilai maksimum $x$ ini sebagai $r_{x1}$.

Serupa dengan itu, kita dapat menemukan nilai minimum $y$ ($y \ge \min_y$) dan nilai maksimum $y$ ($y \le \max_y$). Tandai nilai $x$ yang sesuai sebagai $l_{x2}$ dan $r_{x2}$.

Solusi akhir adalah semua solusi dengan $x$ dalam irisan (*intersection*) dari $[l_{x1}, r_{x1}]$ dan $[l_{x2}, r_{x2}]$. Mari kita tandai irisan ini sebagai $[l_x, r_x]$.

Berikut adalah kode yang mengimplementasikan ide ini. Perhatikan bahwa kita membagi $a$ dan $b$ di awal dengan $g$. Karena persamaan $a x + b y = c$ ekuivalen dengan persamaan

$$\frac{a}{g} x + \frac{b}{g} y = \frac{c}{g},$$

kita dapat menggunakan persamaan yang terakhir ini, dan kita akan memiliki $\gcd(\frac{a}{g}, \frac{b}{g}) = 1$, yang menyederhanakan rumus.

```cpp
void shift_solution(int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}

int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}
```

Setelah kita memiliki $l_x$ dan $r_x$, juga mudah untuk **mengenumerasi** (*enumerate*) semua solusi. Kita hanya perlu melakukan iterasi melalui $x = l_x + k \cdot \frac{b}{g}$ untuk semua $k \ge 0$ hingga $x = r_x$, dan menemukan nilai $y$ yang bersesuaian menggunakan persamaan $a x + b y = c$.

## 6 |  Mencari Solusi dengan Nilai Minimum dari $x + y$

Di sini, $x$ dan $y$ juga perlu diberikan batasan (*restriction*), jika tidak, jawabannya dapat menjadi tak terhingga negatif (*negative infinity*).

Idenya mirip dengan bagian sebelumnya: Kita menemukan sembarang solusi dari persamaan Diophantine, lalu menggeser (*shift*) solusi tersebut untuk memenuhi beberapa kondisi.

Terakhir, gunakan pengetahuan tentang himpunan (*set*) semua solusi untuk menemukan nilai minimum:

$$x' = x + k \cdot \frac{b}{g},$$

$$y' = y - k \cdot \frac{a}{g}.$$

Perhatikan bahwa $x + y$ berubah sebagai berikut:

$$x' + y' = x + y + k \cdot \left(\frac{b}{g} - \frac{a}{g}\right) = x + y + k \cdot \frac{b-a}{g}$$

Jika $a < b$, kita perlu memilih nilai $k$ sekecil mungkin (*smallest possible*). Jika $a > b$, kita perlu memilih nilai $k$ sebesar mungkin (*largest possible*). Jika $a = b$, semua solusi akan memiliki jumlah $x + y$ yang sama.

## 7 | Practice Problems

- [Spoj - Crucial Equation](http://www.spoj.com/problems/CEQU/)
- [SGU 106](http://codeforces.com/problemsets/acmsguru/problem/99999/106)
- [Codeforces - Ebony and Ivory](http://codeforces.com/contest/633/problem/A)
- [Codechef - Get AC in one go](https://www.codechef.com/problems/COPR16G)
- [LightOj - Solutions to an equation](http://www.lightoj.com/volume_showproblem.php?problem=1306)
- [Atcoder - F - S = 1](https://atcoder.jp/contests/abc340/tasks/abc340_f)