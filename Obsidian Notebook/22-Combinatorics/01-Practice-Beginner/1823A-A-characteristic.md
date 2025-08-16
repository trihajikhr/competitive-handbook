---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 1823A-A-characteristic
judul_FAST: A-characteristic
teori_FAST: 
sumber:
  - codeforces
date_learned: 2025-08-13T20:36:00
tags:
  - STRIKE
  - combinatorics
---
Sumber: [Problem - 1823A - Codeforces](https://codeforces.com/problemset/problem/1823/A)

> [!NOTE] ⚔️ Teori STRIKE:
> 

<br/>

---
# 1 | A-characteristic

Diberikan sebuah array $a_1, a_2, \dots, a_n$ yang terdiri dari angka $1$ dan $-1$. Didefinisikan **karakteristik-A** dari array ini sebagai banyaknya pasangan indeks $1 \le i < j \le n$ sehingga $a_i \cdot a_j = 1$.

Tugasmu adalah mencari **array $a$** dengan panjang $n$ yang memiliki karakteristik-A sama dengan nilai $k$ yang diberikan.

**Input**
Setiap input berisi beberapa *test case*.

* Baris pertama berisi bilangan bulat $t$ $(1 \le t \le 100)$ — jumlah *test case*.
* Setiap *test case* terdiri dari satu baris berisi dua bilangan bulat $n$ dan $k$ $(2 \le n \le 100; \ 0 \le k \le \frac{(n-1)n}{2})$ — panjang array yang diminta dan karakteristik-A yang diminta.

**Output**
Untuk setiap *test case*:

* Jika **tidak ada** array $a$ dengan karakteristik-A $k$, cetak `NO`.
* Jika ada, cetak `YES` diikuti $n$ bilangan $1$ dan $-1$ yang membentuk array $a$ tersebut.
  Jika ada lebih dari satu jawaban, cetak salah satu.

<br/>

---
# 2 | Sesi STRIKE ⚔️


<br/>

---


# 3 | Jawaban dan Editorial

Perhatikan bahwa A-characteristic hanya bergantung pada jumlah angka $1$. Misalkan jumlah angka $1$ adalah $x$, maka jumlah angka $-1$ adalah $n - x$, dan **karakteristik-A** diberikan oleh:

$$
f(x) = \frac{(x - 1) \cdot x}{2} + \frac{(n - x - 1) \cdot (n - x)}{2}
$$

Kita dapat melakukan iterasi untuk semua $x$ dari $0$ hingga $n$, dan memeriksa apakah ada $x$ yang memenuhi $f(x) = k$. Jika ada, cetak $x$ buah angka $1$ dan $n - x$ buah angka $-1$.

## Analisis Pribadi