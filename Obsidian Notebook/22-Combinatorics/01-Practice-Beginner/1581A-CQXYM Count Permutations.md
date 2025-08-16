---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 1581A
judul_FAST: CQXYM Count Permutations
teori_FAST: 
sumber:
  - codeforces
date_learned: 2025-08-13T22:06:00
tags:
  - STRIKE
  - combinatios
---
Sumber: [Problem - 1581A - Codeforces](https://codeforces.com/problemset/problem/1581/A)

> [!NOTE] ⚔️ Teori STRIKE:
> 

<br/>

---
# 1 | CQXYM Count Permutations



CQXYM sedang menghitung **permutasi** dengan panjang $2n$.

Sebuah **permutasi** adalah array yang terdiri dari $n$ bilangan bulat berbeda dari $1$ hingga $n$ dalam urutan acak. Contohnya: $[2,3,1,5,4]$ adalah sebuah permutasi, tetapi $[1,2,2]$ **bukan** permutasi (angka $2$ muncul dua kali) dan $[1,3,4]$ juga **bukan** permutasi ($n = 3$ tetapi ada angka $4$ di dalamnya).

Sebuah permutasi $p$ (dengan panjang $2n$) akan dihitung hanya jika jumlah indeks $i$ yang memenuhi $p_i < p_{i+1}$ **tidak kurang dari** $n$.

**Contoh:**

* Permutasi $[1,2,3,4]$ dihitung, karena jumlah indeks $i$ yang memenuhi $p_i < p_{i+1}$ adalah $3$ ($i = 1, 2, 3$).
* Permutasi $[3,2,1,4]$ **tidak** dihitung, karena jumlah indeks $i$ yang memenuhi $p_i < p_{i+1}$ hanya $1$ ($i = 3$).

CQXYM meminta kamu membantu menghitung banyaknya permutasi seperti itu **modulo** $10^9 + 7$ ($1000000007$).

Operasi **modulo** berarti mengambil sisa hasil bagi.
Contoh:

- $7 \bmod 3 = 1 \quad \text{karena} \quad 7 = 3 \cdot 2 + 1,$
- $15 \bmod 4 = 3 \quad \text{karena} \quad 15 = 4 \cdot 3 + 3.$

#### Input
Input terdiri dari beberapa *test case*.

* Baris pertama berisi bilangan bulat $t$ $(t \ge 1)$ — jumlah *test case*.
* Setiap *test case* hanya berisi satu baris dengan bilangan bulat $n$ $(1 \le n \le 10^5)$.

Dijamin bahwa jumlah seluruh nilai $n$ dari semua *test case* tidak melebihi $10^5$.

#### Output
Untuk setiap *test case*, cetak jawabannya dalam satu baris.


<br/>

---
# 2 | Sesi STRIKE ⚔️


<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Penjelasan Editorial

Misalkan sebuah permutasi $p$, dan $\sum_{i=2}^{2n} [p_{i-1} < p_i] = k$. Misalkan sebuah permutasi $q$ yang memenuhi $\forall \ 1 \le i \le 2n, \quad q_i = 2n - p_i$.

Kita dapat mengetahui bahwa

$$
\forall \ 2 \le i \le 2n, \quad [p_{i-1} < p_i] + [q_{i-1} < q_i] = 1
$$

Sehingga:

$$
\sum_{i=2}^{2n} [q_{i-1} < q_i] = 2n - 1 - k
$$

Artinya, salah satu dari $p$ atau $q$ akan dihitung. Kesimpulannya, **setengah dari seluruh permutasi** akan dihitung dalam jawaban.

Dengan demikian, jawabannya adalah:

$$
\frac{1}{2} (2n)!
$$

Kompleksitas waktunya adalah $O\left(\sum n\right)$.
Jika kamu melakukan **precompute** faktorial, maka kompleksitasnya menjadi $O(t + n)$.

## 3.2 |  Analisis Pribadi