---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Binary Exponentiation
sumber:
  - cp-algorithms.com
date_learned: 2025-09-24T03:08:00
tags:
  - number-theory
  - algebra
---
Link Sumber: [Binary Exponentiation - Algorithms for Competitive Programming](https://cp-algorithms.com/algebra/binary-exp.html)

---
# Binary Exponentiation

Eksponensiasi biner (juga dikenal sebagai *exponentiation by squaring*) adalah sebuah trik yang memungkinkan kita untuk menghitung $a^n$ hanya dengan menggunakan $O(\log n)$ perkalian (alih-alih $O(n)$ perkalian yang dibutuhkan oleh pendekatan naif).

Algoritma ini juga memiliki aplikasi penting dalam banyak tugas yang tidak berhubungan dengan aritmatika, karena dapat digunakan dengan operasi apa pun yang memiliki sifat **asosiatif**:

$$(X \cdot Y) \cdot Z = X \cdot (Y \cdot Z)$$

Ini paling jelas berlaku untuk **perkalian modular**, **perkalian matriks**, dan masalah-masalah lain yang akan kita bahas nanti.

## 1 | Algoritma

Menaikkan $a$ ke pangkat $n$ secara naif diekspresikan sebagai perkalian dengan $a$ yang dilakukan sebanyak $n - 1$ kali: $a^{n} = a \cdot a \cdot \ldots \cdot a$. Namun, pendekatan ini tidak praktis untuk $a$ atau $n$ yang besar.

Kita tahu bahwa $a^{b+c} = a^b \cdot a^c$ dan $a^{2b} = a^b \cdot a^b = (a^b)^2$.

Ide dari eksponensiasi biner adalah, kita memecah pekerjaan dengan menggunakan **representasi biner** dari eksponen.

Misalnya, mari kita tulis $n$ dalam basis 2:
$$3^{13} = 3^{1101_2} = 3^8 \cdot 3^4 \cdot 3^1$$

Karena angka $n$ memiliki tepat $\lfloor \log_{2} n \rfloor + 1$ digit dalam basis 2, kita hanya perlu melakukan $O(\log n)$ perkalian, jika kita tahu pangkat-pangkat $a^1, a^2, a^4, a^8, \dots, a^{2^{\lfloor \log n \rfloor}}$.

Jadi, kita hanya perlu tahu cara cepat untuk menghitung pangkat-pangkat tersebut. 

Untungnya ini sangat mudah, karena sebuah elemen dalam urutan tersebut hanyalah kuadrat dari elemen sebelumnya.

$$\begin{align} 3^1 &= 3 \\ 3^2 &= \left(3^1\right)^2 = 3^2 = 9 \\ 3^4 &= \left(3^2\right)^2 = 9^2 = 81 \\ 3^8 &= \left(3^4\right)^2 = 81^2 = 6561 \end{align}$$

Jadi, untuk mendapatkan jawaban akhir untuk $3^{13}$, kita hanya perlu mengalikan tiga dari mereka (melewatkan $3^2$ karena bit yang sesuai dalam $n$ tidak disetel): $3^{13} = 6561 \cdot 81 \cdot 3 = 1594323$.

Kompleksitas akhir dari algoritma ini adalah $O(\log n)$: kita harus menghitung $\log n$ pangkat dari $a$, dan kemudian harus melakukan paling banyak $\log n$ perkalian untuk mendapatkan jawaban akhir dari mereka.

Pendekatan **rekursif** berikut mengungkapkan ide yang sama:

$$a^n = \begin{cases} 1 &\text{jika } n == 0 \\ \left(a^{\frac{n}{2}}\right)^2 &\text{jika } n > 0 \text{ dan } n \text{ genap}\\ \left(a^{\frac{n - 1}{2}}\right)^2 \cdot a &\text{jika } n > 0 \text{ dan } n \text{ ganjil}\\ \end{cases}$$

## 2 | Implementasi

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

Pendekatan kedua menyelesaikan tugas yang sama tanpa **rekursi**. Ini menghitung semua pangkat dalam sebuah *loop*, dan mengalikan yang memiliki bit yang sesuai disetel dalam $n$. Meskipun kompleksitas kedua pendekatan ini identik, pendekatan ini akan lebih cepat dalam praktik karena kita tidak memiliki *overhead* dari panggilan rekursif.

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


## 3 | Aplikasi
### 3.1 | Perhitungan Efektif Eksponen Besar modulo Suatu Angka

**Masalah:** Hitung $x^n \bmod m$. Ini adalah operasi yang sangat umum. Misalnya, operasi ini digunakan dalam menghitung **invers perkalian modular**.

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

**Catatan:** Dimungkinkan untuk mempercepat algoritma ini untuk nilai $b >> m$ yang besar. Jika $m$ adalah bilangan prima, $x^n \equiv x^{n \bmod (m-1)} \pmod{m}$ (menurut **Teorema Kecil Fermat**). Jika $m$ adalah bilangan komposit, $x^n \equiv x^{n \bmod{\phi(m)}} \pmod{m}$ (menurut **Teorema Euler**). Untuk detail lebih lanjut, lihat artikel tentang Invers Modular.

### 3.2 | Perhitungan Efektif Bilangan Fibonacci

**Masalah:** Hitung bilangan Fibonacci ke-$n$, $F_n$.

**Solusi:** Untuk detail lebih lanjut, lihat artikel Bilangan Fibonacci. Kita hanya akan membahas gambaran umum algoritmanya. Untuk menghitung bilangan Fibonacci berikutnya, hanya dua bilangan sebelumnya yang diperlukan, karena $F_n = F_{n-1} + F_{n-2}$. Kita dapat membangun matriks $2 \times 2$ yang menjelaskan transformasi ini: transisi dari $F_i$ dan $F_{i+1}$ ke $F_{i+1}$ dan $F_{i+2}$. Oleh karena itu, kita dapat menaikkan matriks transformasi ini ke pangkat ke-$n$ untuk menemukan $F\_n$ dengan kompleksitas waktu $O(\\log n)$.

-----

### Menerapkan Permutasi sebanyak $k$ Kali

**Masalah:** Anda diberikan sebuah barisan dengan panjang $n$. Terapkan permutasi yang diberikan sebanyak $k$ kali.

**Solusi:** Cukup naikkan permutasi tersebut ke pangkat ke-$k$ menggunakan eksponensiasi biner, lalu terapkan ke barisan. Ini akan memberikan Anda kompleksitas waktu $O(n \\log k)$.

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

**Catatan:** Tugas ini dapat diselesaikan lebih efisien dalam waktu linear dengan membangun **graf permutasi** dan mempertimbangkan setiap **siklus** secara independen. Anda kemudian dapat menghitung $k$ modulo ukuran siklus dan menemukan posisi akhir untuk setiap angka yang merupakan bagian dari siklus ini.

-----

### Penerapan Cepat Serangkaian Operasi Geometris pada Sekumpulan Titik

**Masalah:** Diberikan $n$ titik $p\_i$, terapkan $m$ transformasi pada setiap titik ini. Setiap transformasi bisa berupa pergeseran (*shift*), penskalaan (*scaling*), atau rotasi di sekitar sumbu tertentu dengan sudut yang diberikan. Ada juga operasi "loop" yang menerapkan daftar transformasi yang diberikan sebanyak $k$ kali (operasi "loop" dapat bersarang). Anda harus menerapkan semua transformasi lebih cepat dari $O(n \\cdot length)$, di mana $length$ adalah jumlah total transformasi yang akan diterapkan (setelah membuka operasi "loop").

**Solusi:** Mari kita lihat bagaimana berbagai jenis transformasi mengubah koordinat:

  * Operasi **pergeseran**: menambahkan konstanta yang berbeda ke setiap koordinat.
  * Operasi **penskalaan**: mengalikan setiap koordinat dengan konstanta yang berbeda.
  * Operasi **rotasi**: transformasinya lebih rumit, tetapi setiap koordinat baru masih dapat direpresentasikan sebagai kombinasi linear dari koordinat lama.

Seperti yang Anda lihat, setiap transformasi dapat direpresentasikan sebagai **operasi linear** pada koordinat. Jadi, sebuah transformasi dapat ditulis sebagai matriks $4 \\times 4$ dalam bentuk:

$$\begin{pmatrix} a_{11} & a_ {12} & a_ {13} & a_ {14} \\ a_{21} & a_ {22} & a_ {23} & a_ {24} \\ a_{31} & a_ {32} & a_ {33} & a_ {34} \\ a_{41} & a_ {42} & a_ {43} & a_ {44} \end{pmatrix}$$

yang, ketika dikalikan dengan vektor dengan koordinat lama dan satu unit, memberikan vektor baru dengan koordinat baru dan satu unit:

$$\begin{pmatrix} x & y & z & 1 \end{pmatrix} \cdot \begin{pmatrix} a_{11} & a_ {12} & a_ {13} & a_ {14} \\ a_{21} & a_ {22} & a_ {23} & a_ {24} \\ a_{31} & a_ {32} & a_ {33} & a_ {34} \\ a_{41} & a_ {42} & a_ {43} & a_ {44} \end{pmatrix} = \begin{pmatrix} x' & y' & z' & 1 \end{pmatrix}$$

(Mengapa memperkenalkan koordinat keempat fiktif? Itulah keindahan **koordinat homogen**, yang banyak digunakan dalam grafika komputer. Tanpa ini, tidak mungkin untuk mengimplementasikan operasi afinitas seperti operasi pergeseran sebagai perkalian matriks tunggal, karena membutuhkan kita untuk **menambahkan** konstanta ke koordinat. Transformasi afinitas menjadi transformasi linear dalam dimensi yang lebih tinggi\!)

Sekarang, setelah setiap transformasi dijelaskan sebagai sebuah matriks, urutan transformasi dapat dijelaskan sebagai hasil kali dari matriks-matriks ini, dan "loop" sebanyak $k$ pengulangan dapat dijelaskan sebagai matriks yang dipangkatkan dengan $k$ (yang dapat dihitung menggunakan eksponensiasi biner dalam $O(\\log k)$). Dengan cara ini, matriks yang mewakili semua transformasi dapat dihitung terlebih dahulu dalam $O(m \\log k)$, dan kemudian dapat diterapkan ke setiap $n$ titik dalam $O(n)$ untuk kompleksitas total $O(n + m \\log k)$.

-----

### Jumlah Jalur dengan Panjang $k$ dalam Sebuah Graf

**Masalah:** Diberikan graf berarah tak berbobot dengan $n$ verteks, temukan jumlah jalur dengan panjang $k$ dari verteks $u$ mana pun ke verteks $v$ mana pun.

**Solusi:** Masalah ini dibahas lebih rinci dalam artikel terpisah. Algoritmanya terdiri dari menaikkan **matriks kedekatan** (*adjacency matrix*) $M$ dari graf (matriks di mana $m\_{ij} = 1$ jika ada sisi dari $i$ ke $j$, atau $0$ sebaliknya) ke pangkat ke-$k$. Sekarang, $m\_{ij}$ akan menjadi jumlah jalur dengan panjang $k$ dari $i$ ke $j$. Kompleksitas waktu dari solusi ini adalah $O(n^3 \\log k)$.

**Catatan:** Dalam artikel yang sama, variasi lain dari masalah ini juga dibahas: ketika sisi-sisinya berbobot dan diperlukan untuk menemukan jalur dengan bobot minimum yang berisi tepat $k$ sisi. Seperti yang ditunjukkan dalam artikel itu, masalah ini juga diselesaikan dengan eksponensiasi matriks kedekatan. Matriks akan memiliki bobot sisi dari $i$ ke $j$, atau $\\infty$ jika tidak ada sisi seperti itu. Alih-alih operasi perkalian dua matriks yang biasa, yang dimodifikasi harus digunakan: alih-alih perkalian, kedua nilai dijumlahkan, dan alih-alih penjumlahan, diambil nilai minimum. Yaitu: $result\_{ij} = \\min\\limits\_{1\\ \\leq\\ k\\ \\leq\\ n}(a\_{ik} + b\_{kj})$.

-----

### Variasi Eksponensiasi Biner: Mengalikan Dua Angka modulo $m$

**Masalah:** Kalikan dua angka $a$ dan $b$ modulo $m$. Angka $a$ dan $b$ muat dalam tipe data bawaan, tetapi produknya terlalu besar untuk muat dalam bilangan bulat 64-bit. Idenya adalah untuk menghitung $a \\cdot b \\pmod m$ tanpa menggunakan **aritmatika *bignum***.

**Solusi:** Kita cukup menerapkan algoritma konstruksi biner yang dijelaskan di atas, hanya saja melakukan **penjumlahan** alih-alih perkalian. Dengan kata lain, kita telah "memperluas" perkalian dua angka menjadi $O (\\log m)$ operasi penjumlahan dan perkalian dengan dua (yang, pada dasarnya, adalah penjumlahan).

$$a \cdot b = \begin{cases} 0 &\text{jika }a = 0 \\ 2 \cdot \frac{a}{2} \cdot b &\text{jika }a > 0 \text{ dan }a \text{ genap} \\ 2 \cdot \frac{a-1}{2} \cdot b + b &\text{jika }a > 0 \text{ dan }a \text{ ganjil} \end{cases}$$

**Catatan:** Anda dapat menyelesaikan tugas ini dengan cara lain menggunakan operasi **floating-point**. Pertama, hitung ekspresi $\\frac{a \\cdot b}{m}$ menggunakan bilangan floating-point dan ubah (*cast*) ke bilangan bulat tak bertanda $q$. Kurangi $q \\cdot m$ dari $a \\cdot b$ menggunakan aritmatika bilangan bulat tak bertanda dan ambil modulo $m$ untuk menemukan jawabannya. Solusi ini terlihat agak tidak dapat diandalkan, tetapi sangat cepat, dan sangat mudah diimplementasikan.