---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Divisibility Rules dan Cara Menemukannya
sumber: chatgpt.com
date_learned: 2025-07-16T22:31:00
tags:
  - math
---
Link Sumber: 

---
# Divisibility Rules dan Cara Menemukannya

Catatan ini membahas **aturan keterbagian** untuk bilangan **apa pun** disertai metode umum menurunkannya.

## Pendekatan Umum Menemukan Aturan Divisibilitas

Misalkan kita ingin mengetahui kapan suatu bilangan $a$ habis dibagi oleh $n$. Langkah-langkahnya:

### 1 | Ekspansi Desimal dan Modulo
Tulis:

$$
a = d_0 + 10d_1 + 10^2 d_2 + \cdots + 10^k d_k
$$

Kemudian:

$$
a \equiv d_0 \cdot 10^0 + d_1 \cdot 10^1 + d_2 \cdot 10^2 + \cdots + d_k \cdot 10^k \pmod{n}.
$$

Cari pola atau transformasi yang mempermudah perhitungan modulonya.

### 2 | Sifat Bilangan Pembagi $n$

* Jika $n$ memiliki faktor-faktor kecil (misal 2, 3, 5, 7), gunakan gabungan aturan sederhana.
* Jika $n$ prima besar, gunakan algoritma pembagian modular atau langsung bagi.

### 3 | Modifikasi Digit
Bentuk operasi pada digit, misalnya:

* **Penjumlahan digit** (untuk 3, 9):

$$
10 \equiv 1 \pmod{3,9} \implies a \equiv \sum d_i \pmod{3,9}.
$$
* **Pengurangan digit tertentu** (untuk 7, 13, ...):
contoh:  $a = 10x + y$, gunakan transformasi linear pada $x,y$.

### 4 | Teorema Aritmetika Modular
Jika:

$$
10 \equiv k \pmod{n},
$$

maka

$$
a = 10x + y \implies a \equiv kx + y \pmod{n}.
$$

### 5 | Pembagian Langsung
   Jika aturan penjumlahan/pengurangan terlalu rumit, sebaiknya menggunakan algoritma pembagian standar.

---

## Contoh Aturan untuk Beberapa Nilai $n$

### Aturan untuk $n=11$

**Rule**: Selang-seling jumlah digit habis dibagi 11:

$$
(d_0 - d_1 + d_2 - d_3 + \cdots) \equiv 0 \pmod{11}.
$$

**Contoh**: 121 → $1 - 2 + 1 = 0$ ⇒ habis dibagi 11.

### Aturan untuk $n=13$

**Rule**: Kalikan digit terakhir dengan 9, kurangi dari sisa angka, lalu ulangi:

$$
	\text{Jika}\; a=10x+y,\quad a' = x - 9y.
$$

Ulangi sampai sederhana.
**Contoh**: 286 → $28 - 9\times6 = -26$ ⇒ tidak habis dibagi 13.

### Aturan untuk $n=17,19,23,\dots$

Biasanya lebih praktis menggunakan pembagian modular atau langsung bagi dengan kalkulator/computer.

---

> Untuk bilangan $n$ lain, cukup tentukan nilai $10 \bmod n$ dan terapkan Teorema Modular, atau sesuaikan transformasi digit.

---

##### Sumber Referensi

* David M. Burton, *Elementary Number Theory*
* Khan Academy, artikel *Divisibility Rules*
