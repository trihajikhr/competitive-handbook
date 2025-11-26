---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Binary Exponentiation
sumber:
  - cp-algorithms.com
date_learned: 2025-10-24T03:08:00
tags:
  - cp-algorithms
---
Link Sumber: [Binary Exponentiation - Algorithms for Competitive Programming](https://cp-algorithms.com/algebra/binary-exp.html)

---
# Binary Exponentiation

Eksponensiasi biner (juga dikenal sebagai *exponentiation by squaring*) adalah sebuah trik yang memungkinkan kita untuk menghitung $a^n$ hanya dengan menggunakan $O(\log n)$ perkalian (alih-alih $O(n)$ perkalian yang dibutuhkan oleh pendekatan naif).

Algoritma ini juga memiliki aplikasi penting dalam banyak tugas yang tidak berhubungan dengan aritmatika, karena dapat digunakan dengan operasi apa pun yang memiliki sifat asosiatif:

$$(X \cdot Y) \cdot Z = X \cdot (Y \cdot Z)$$

Ini paling jelas berlaku untuk perkalian modular, perkalian matriks, dan masalah-masalah lain yang akan kita bahas nanti.

## 1 | Algorithm

Menaikkan $a$ ke pangkat $n$ secara naif diekspresikan sebagai perkalian dengan $a$ yang dilakukan sebanyak $n - 1$ kali: $a^{n} = a \cdot a \cdot \ldots \cdot a$. Namun, pendekatan ini tidak praktis untuk $a$ atau $n$ yang besar.

$$a^{b+c} = a^b \cdot a^c \;\;\text{ dan }\;\; a^{2b} = a^b \cdot a^b = (a^b)^2$$

Ide dari eksponensiasi biner adalah, kita memecah pekerjaan dengan menggunakan **representasi biner** dari eksponen.

Misalnya, mari kita tulis $n$ dalam basis 2:
$$3^{13} = 3^{1101_2} = 3^8 \cdot 3^4 \cdot 3^1$$

Karena angka $n$ memiliki tepat $\lfloor \log_{2} n \rfloor + 1$ digit dalam basis 2, kita hanya perlu melakukan $O(\log n)$ perkalian, jika kita tahu pangkat-pangkat $a^1, a^2, a^4, a^8, \dots, a^{2^{\lfloor \log n \rfloor}}$.

Jadi, kita hanya perlu tahu cara cepat untuk menghitung pangkat-pangkat tersebut. Untungnya ini sangat mudah, karena sebuah elemen dalam urutan tersebut hanyalah kuadrat dari elemen sebelumnya.

$$\begin{align} 3^1 &= 3 \\ 3^2 &= \left(3^1\right)^2 = 3^2 = 9 \\ 3^4 &= \left(3^2\right)^2 = 9^2 = 81 \\ 3^8 &= \left(3^4\right)^2 = 81^2 = 6561 \end{align}$$

Jadi, untuk mendapatkan jawaban akhir untuk $3^{13}$, kita hanya perlu mengalikan tiga dari mereka (melewatkan $3^2$ karena bit yang sesuai dalam $n$ tidak diset): $3^{13} = 6561 \cdot 81 \cdot 3 = 1594323$.

Kompleksitas akhir dari algoritma ini adalah $O(\log n)$: kita harus menghitung $\log n$ pangkat dari $a$, dan kemudian harus melakukan paling banyak $\log n$ perkalian untuk mendapatkan jawaban akhir dari mereka.

Pendekatan **rekursif** berikut mengungkapkan ide yang sama:

$$a^n = \begin{cases} 1 &\text{jika } n == 0 \\ \left(a^{\frac{n}{2}}\right)^2 &\text{jika } n > 0 \text{ dan } n \text{ genap}\\ \left(a^{\frac{n - 1}{2}}\right)^2 \cdot a &\text{jika } n > 0 \text{ dan } n \text{ ganjil}\\ \end{cases}$$

## 2 | Implementation

Pertama adalah pendekatan rekursif, yang merupakan terjemahan langsung dari formula rekursif:

```cpp
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
```

Pendekatan kedua menyelesaikan tugas yang sama tanpa rekursi. Ini menghitung semua pangkat dalam sebuah *loop*, dan mengalikan yang memiliki bit yang diset sesuai dalam $n$. Meskipun kompleksitas kedua pendekatan ini identik, pendekatan ini akan lebih cepat dalam praktik karena kita tidak memiliki *overhead* dari panggilan rekursif.

```cpp
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
```


## 3 | Applications
### 3.1 | Effective computation of large exponents modulo a number

**Masalah:** Hitung $x^n \bmod m$. Ini adalah operasi yang sangat umum. Misalnya, operasi ini digunakan dalam menghitung [invers perkalian modular](https://cp-algorithms.com/algebra/module-inverse.html).

**Solusi:** Karena kita tahu bahwa operator modulo tidak mengganggu perkalian $(a \cdot b \equiv (a \bmod m) \cdot (b \bmod m) \pmod m)$, kita dapat langsung menggunakan kode yang sama, dan hanya mengganti setiap perkalian dengan perkalian modular:

```cpp
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
```

**Catatan:** Dimungkinkan untuk mempercepat algoritma ini untuk nilai $b >> m$ yang besar. Jika $m$ adalah bilangan prima, $x^n \equiv x^{n \bmod (m-1)} \pmod{m}$ (menurut *Fermat's little theorem*). Jika $m$ adalah bilangan komposit, $x^n \equiv x^{n \bmod{\phi(m)}} \pmod{m}$ (menurut *Euler's theorem*). Untuk detail lebih lanjut, lihat artikel tentang [Invers Modular](https://cp-algorithms.com/algebra/module-inverse.html#fermat-euler).

### 3.2 | Effective computation of Fibonacci numbers

**Masalah:** Hitung bilangan Fibonacci ke-$n$, $F_n$.

**Solusi:** Untuk detail lebih lanjut, lihat artikel [Bilangan Fibonacci](https://cp-algorithms.com/algebra/fibonacci-numbers.html). Kami hanya akan membahas tinjauan umum dari algoritma tersebut. Untuk menghitung bilangan Fibonacci berikutnya, hanya dua bilangan sebelumnya yang diperlukan, karena $F_n = F_{n-1} + F_{n-2}$. Kita dapat membangun matriks berukuran $2 \times 2$ yang menggambarkan transformasi ini: transisi dari pasangan $F_i$ dan $F_{i+1}$ menjadi $F_{i+1}$ dan $F_{i+2}$. Sebagai contoh, menerapkan transformasi ini pada pasangan $F_0$ dan $F_1$ akan mengubahnya menjadi $F_1$ dan $F_2$. Oleh karena itu, kita dapat memangkatkan matriks transformasi ini ke pangkat ke-$n$ untuk menemukan $F_n$ dengan kompleksitas waktu $O(\log n)$.

### 3.3 | Applying a permutation  $k$  times

**Masalah:** Anda diberikan sebuah barisan/sekuen dengan panjang $n$. Terapkan permutasi yang diberikan sebanyak $k$ kali.

**Solusi:** Cukup naikkan permutasi tersebut ke pangkat ke-$k$ menggunakan eksponensiasi biner, lalu terapkan ke barisan/sekuen. Ini akan memberikan Anda kompleksitas waktu $O(n \; \log \; k)$.

```cpp
vector<int> applyPermutation(vector<int> sequence, vector<int> permutation) {
    vector<int> newSequence(sequence.size());
    for(int i = 0; i < sequence.size(); i++) {
        newSequence[i] = sequence[permutation[i]];
    }
    return newSequence;
}

vector<int> permute(vector<int> sequence, vector<int> permutation, long long k) {
    while (k > 0) {
        if (k & 1) {
            sequence = applyPermutation(sequence, permutation);
        }
        permutation = applyPermutation(permutation, permutation);
        k >>= 1;
    }
    return sequence;
}
```

Kode diatas yang disederhanakan:

```cpp
using VI = vector<int>;
using LL = long long;
VI applyPermutation(VI sequence, VI permutation) {
    VI newSequence(sequence.size());
    for(int i = 0; i < sequence.size(); i++) {
        newSequence[i] = sequence[permutation[i]];
    }
    return newSequence;
}

VI permute(VI sequence, VI permutation, LL k) {
    while (k > 0) {
        if (k & 1) {
            sequence = applyPermutation(sequence, permutation);
        }
        permutation = applyPermutation(permutation, permutation);
        k >>= 1;
    }
    return sequence;
}
```

**Catatan:** Tugas ini dapat diselesaikan lebih efisien dalam waktu linear dengan membangun **graf permutasi** dan mempertimbangkan setiap **siklus** secara independen. Anda kemudian dapat menghitung $k$ modulo ukuran siklus dan menemukan posisi akhir untuk setiap angka yang merupakan bagian dari siklus ini.

### 3.4 | Fast application of a set of geometric operations to a set of points

**Masalah:** Diberikan $n$ titik $p_i$, terapkan $m$ transformasi pada setiap titik ini. Setiap transformasi bisa berupa pergeseran (*shift*), penskalaan (*scaling*), atau rotasi di sekitar sumbu tertentu dengan sudut yang diberikan. Ada juga operasi "loop" yang menerapkan daftar transformasi yang diberikan sebanyak $k$ kali (operasi "loop" dapat bersarang). Anda harus menerapkan semua transformasi lebih cepat dari $O(n \cdot length)$, di mana $length$ adalah jumlah total transformasi yang akan diterapkan (setelah membuka operasi "loop").

**Solusi:** Mari kita lihat bagaimana berbagai jenis transformasi mengubah koordinat:

  * Operasi **pergeseran**: menambahkan konstanta yang berbeda ke setiap koordinat.
  * Operasi **penskalaan**: mengalikan setiap koordinat dengan konstanta yang berbeda.
  * Operasi **rotasi**: transformasinya lebih rumit, (*kita tidak membahas detailnya disini*) tetapi setiap koordinat baru masih dapat direpresentasikan sebagai kombinasi linear dari koordinat lama.

Seperti yang Anda lihat, setiap transformasi dapat direpresentasikan sebagai **operasi linear** pada koordinat. Jadi, sebuah transformasi dapat ditulis sebagai matriks $4 \times 4$ dalam bentuk:

$$\begin{pmatrix} a_{11} & a_ {12} & a_ {13} & a_ {14} \\ a_{21} & a_ {22} & a_ {23} & a_ {24} \\ a_{31} & a_ {32} & a_ {33} & a_ {34} \\ a_{41} & a_ {42} & a_ {43} & a_ {44} \end{pmatrix}$$

yang, ketika dikalikan dengan vektor dengan koordinat lama dan satu unit, memberikan vektor baru dengan koordinat baru dan satu unit:

$$\begin{pmatrix} x & y & z & 1 \end{pmatrix} \cdot \begin{pmatrix} a_{11} & a_ {12} & a_ {13} & a_ {14} \\ a_{21} & a_ {22} & a_ {23} & a_ {24} \\ a_{31} & a_ {32} & a_ {33} & a_ {34} \\ a_{41} & a_ {42} & a_ {43} & a_ {44} \end{pmatrix} = \begin{pmatrix} x' & y' & z' & 1 \end{pmatrix}$$

(Mengapa memperkenalkan koordinat keempat fiktif, kamu bertanya? Itulah keindahan [koordinat homogen](https://en.wikipedia.org/wiki/Homogeneous_coordinates), yang banyak digunakan dalam grafika komputer. Tanpa ini, tidak mungkin untuk mengimplementasikan operasi afinitas seperti operasi pergeseran sebagai perkalian matriks tunggal, karena membutuhkan kita untuk **menambahkan** konstanta ke koordinat. Transformasi afinitas menjadi transformasi linear dalam dimensi yang lebih tinggi!)

Berikut adalah beberapa contoh bagaimana transformasi direpresentasikan dalam bentuk matriks:

- Operasi Pergeseran (*Shift operation*): Menggeser koordinat $x$ sebesar $5$, koordinat $y$ sebesar $7$, dan koordinat $z$ sebesar $9$.

	$$\begin{pmatrix} 1 & 0 & 0 & 0 \\ 0 & 1 & 0 & 0 \\ 0 & 0 & 1 & 0 \\ 5 & 7 & 9 & 1 \end{pmatrix}$$

- Operasi Skala (*Scaling operation*): Menskalakan (*scale*) koordinat $x$ sebesar $10$ dan dua koordinat lainnya sebesar $5$.

	$$\begin{pmatrix} 10 & 0 & 0 & 0 \\ 0 & 5 & 0 & 0 \\ 0 & 0 & 5 & 0 \\ 0 & 0 & 0 & 1 \end{pmatrix}$$

- Operasi Rotasi (*Rotation operation*): Memutar (*rotate*) sebesar $\theta$ derajat di sekitar sumbu $x$ mengikuti **aturan tangan kanan** (*right-hand rule*) (arah berlawanan jarum jam).

$$\begin{pmatrix} 1 & 0 & 0 & 0 \\ 0 & \cos \theta & -\sin \theta & 0 \\ 0 & \sin \theta & \cos \theta & 0 \\ 0 & 0 & 0 & 1 \end{pmatrix}$$


Setelah setiap transformasi dideskripsikan sebagai matriks, urutan transformasi (*sequence of transformations*) dapat dideskripsikan sebagai hasil kali (*product*) dari matriks-matriks ini, dan **"perulangan"** (*"loop"*) sebanyak $k$ pengulangan dapat dideskripsikan sebagai matriks yang dipangkatkan dengan $k$ (yang dapat dihitung menggunakan **eksponensiasi biner** (*binary exponentiation*) dalam $O(\log{k})$). Dengan cara ini, matriks yang merepresentasikan semua transformasi dapat dihitung terlebih dahulu dalam $O(m \log{k})$, dan kemudian dapat diterapkan ke setiap $n$ titik dalam $O(n)$ untuk total kompleksitas sebesar $O(n + m \log{k})$.

### 3.5 | Number of paths of length  $k$  in a graph

**Masalah:** Diberikan *graph* berarah (*directed*) tak berbobot (*unweighted graph*) dengan $n$ *vertex* (titik), temukan jumlah *path* (lintasan) dengan panjang $k$ dari *vertex* mana pun $u$ ke *vertex* lain $v$.

**Solusi:** Masalah ini dibahas lebih rinci dalam [artikel terpisah](https://cp-algorithms.com/graph/fixed_length_paths.html). Algoritma ini terdiri dari pemangkatan **matriks kedekatan** (*adjacency matrix*) $M$ dari *graph* (sebuah matriks di mana $m_{ij} = 1$ jika ada *edge* (sisi) dari $i$ ke $j$, atau $0$ jika tidak ada) dengan pangkat $k$. Sekarang $m_{ij}$ akan menjadi jumlah *path* dengan panjang $k$ dari $i$ ke $j$. Kompleksitas waktu (*time complexity*) dari solusi ini adalah $O(n^3 \log k)$.

**Catatan:** Dalam artikel yang sama, variasi lain dari masalah ini dipertimbangkan: ketika *edge* berbobot (*weighted*) dan diminta untuk menemukan *path* dengan bobot minimum (*minimum weight path*) yang mengandung tepat $k$ *edge*. Seperti yang ditunjukkan dalam artikel tersebut, masalah ini juga diselesaikan dengan pemangkatan matriks kedekatan (*adjacency matrix*). Matriks tersebut akan memiliki bobot *edge* dari $i$ ke $j$, atau $\infty$ jika tidak ada *edge* tersebut. Alih-alih operasi biasa mengalikan dua matriks, harus digunakan operasi yang dimodifikasi: alih-alih perkalian, kedua nilai dijumlahkan, dan alih-alih penjumlahan (*summation*), diambil nilai minimum. Yaitu: $\text{result}_{ij} = \min\limits_{1\ \leq\ k\ \leq\ n}(a_{ik} + b_{kj})$.

### 3.6 | Variation of binary exponentiation: multiplying two numbers modulo  $m$

**Masalah:** Mengalikan dua bilangan $a$ dan $b$ modulo $m$. Bilangan $a$ dan $b$ dapat dimuat dalam tipe data bawaan (*built-in data types*), tetapi hasil kali (*product*) keduanya terlalu besar untuk dimuat dalam bilangan bulat $64$-*bit*. Idenya adalah menghitung $a \cdot b \pmod m$ tanpa menggunakan aritmetika *bignum*.

**Solusi:** Kita cukup menerapkan algoritma konstruksi **biner** (*binary construction algorithm*) yang dijelaskan di atas, hanya saja melakukan operasi penjumlahan (*additions*) alih-alih perkalian (*multiplications*). Dengan kata lain, kita telah "**mengembangkan**" (*expanded*) perkalian dua bilangan menjadi $O (\log m)$ operasi penjumlahan dan perkalian dengan dua (yang pada dasarnya adalah penjumlahan).

$$a \cdot b = \begin{cases} 0 &\text{jika }a = 0 \\ 2 \cdot \frac{a}{2} \cdot b &\text{jika }a > 0 \text{ dan }a \text{ genap} \\ 2 \cdot \frac{a-1}{2} \cdot b + b &\text{jika }a > 0 \text{ dan }a \text{ ganjil} \end{cases}$$

**Catatan:** Anda dapat menyelesaikan tugas ini dengan cara berbeda menggunakan operasi *floating-point*. Pertama, hitung ekspresi $\frac{a \cdot b}{m}$ menggunakan bilangan *floating-point* dan *cast* (konversi) ke bilangan bulat tak bertanda (*unsigned integer*) $q$. Kurangi $q \cdot m$ dari $a \cdot b$ menggunakan aritmetika bilangan bulat tak bertanda dan ambil modulo $m$ untuk menemukan jawabannya. Solusi ini terlihat agak tidak dapat diandalkan (*unreliable*), tetapi sangat cepat, dan sangat mudah diimplementasikan. Lihat [di sini](https://cs.stackexchange.com/questions/77016/modular-multiplication) untuk informasi lebih lanjut.

## 4 | Practice Problems

- [UVa 1230 - MODEX](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3671)
- [UVa 374 - Big Mod](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=310)
- [UVa 11029 - Leading and Trailing](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1970)
- [Codeforces - Parking Lot](http://codeforces.com/problemset/problem/630/I)
- [leetcode - Count good numbers](https://leetcode.com/problems/count-good-numbers/)
- [Codechef - Chef and Riffles](https://www.codechef.com/JAN221B/problems/RIFFLES)
- [Codeforces - Decoding Genome](https://codeforces.com/contest/222/problem/E)
- [Codeforces - Neural Network Country](https://codeforces.com/contest/852/problem/B)
- [Codeforces - Magic Gems](https://codeforces.com/problemset/problem/1117/D)
- [SPOJ - The last digit](http://www.spoj.com/problems/LASTDIG/)
- [SPOJ - Locker](http://www.spoj.com/problems/LOCKER/)
- [LA - 3722 Jewel-eating Monsters](https://vjudge.net/problem/UVALive-3722)
- [SPOJ - Just add it](http://www.spoj.com/problems/ZSUM/)
- [Codeforces - Stairs and Lines](https://codeforces.com/contest/498/problem/E)

