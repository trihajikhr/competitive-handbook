---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1793C
judul_DEATH: Dora and Search
teori_DEATH:
sumber:
  - codeforces.com
rating: 1200
ada_tips:
date_learned: 2025-11-06T20:07:00
tags:
  - constructive-algorithms
  - data-structures
  - two-pointers
---
Sumber: [Problem - 1793C - Dora and Search](https://codeforces.com/problemset/problem/1793/C)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1793C-Dora and Search

Diberikan sebuah array permutasi berukuran $n$. Tugasmu adalah menemukan subsegment dari array permutasi yang diberikan dari rentang $l$ hingga $r$, yang mana nilai $a_l$ dan $a_r$ bukanlah nilai terkecil ataupun terbesar dari subsegment tersebut.

Atau tentukan jika subsegment yang memenuhi syarat tersebut tidak dapat ditemukan.

<br/>

---
# 2 | Sesi Death Ground ⚔️

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Misalkan kita ingin memeriksa apakah keseluruhan array memenuhi klaim tersebut. Jika ya, maka kita dapat menampilkan keseluruhan array sebagai jawaban. Jika tidak, salah satu dari dua elemen ekstrem (tepi) tidak memenuhi persyaratan kita. Dari sini kita dapat menyimpulkan bahwa semua segmen yang mengandung elemen yang tidak memenuhi persyaratan kita juga akan salah, karena elemen ekstrem ini akan tetap menjadi minimum/maksimum.

Algoritma ini mengikuti fakta di atas: mari kita lihat sub-segmen $[l;r]$, yang pada awalnya sama dengan $[1;n]$. Jika $a_l = \min(a_l, a_{l+1}, \ldots, a_r)$ atau $a_l = \max(a_l, a_{l+1}, \ldots, a_r)$, maka kita lanjutkan ke segmen $[l+1;r]$. Penalaran serupa juga diperlukan untuk $a_r$. Dengan demikian, setelah beberapa iterasi, kita akan mendapatkan sub-segmen yang diperlukan, atau kita akan mendapatkan $l == r$ dan jawabannya adalah **$-1$**.

Asimtotik akhir: **$O(n \log n)$** atau **$O(n)$** tergantung pada implementasinya.

## 3.2 | Analisis Pribadi
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
```
### 2 | Jawaban Kedua

```cpp
```
### 3 | Jawaban Ketiga

```cpp
```