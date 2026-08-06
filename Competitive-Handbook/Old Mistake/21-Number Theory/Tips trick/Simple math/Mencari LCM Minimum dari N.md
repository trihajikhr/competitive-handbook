---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Mencari LCM Minimum dari N
sumber:
  - myself
  - codeforces.com
date_learned: 2026-01-29T00:49:00
tags:
  - number-theory
  - tips-trick
---
---
# Mencari LCM Minimum dari N

Diberikan sebuah bilangan bulat positif $n$. Kita ingin menentukan dua bilangan bulat positif $a$ dan $b$ sedemikian sehingga $a + b = n$ dan nilai $\text{LCM}(a, b)$ minimum.

Tanpa mengurangi keumuman, kita dapat menuliskan pasangan tersebut sebagai $(k, n-k)$ dengan $k \le n-k$. Karena $k \le n/2$, maka $n-k \ge n/2$.

## 1. Analisis Faktor

Perhatikan bahwa jika $k \mid n$, maka $n-k$ juga merupakan kelipatan dari $k$. Dalam hal ini berlaku:

$$\text{LCM}(k, n-k) = n-k < n$$

Sebaliknya, jika $k \nmid n$, maka $k \nmid (n-k)$. Karena $\text{LCM}(k, n-k)$ harus merupakan kelipatan dari $n-k$ dan tidak sama dengan $n-k$, diperoleh:

$$\text{LCM}(k, n-k) \ge 2(n-k) \ge n$$

Dengan demikian, nilai minimum dari $\text{LCM}(k, n-k)$ hanya dapat dicapai ketika $k$ merupakan faktor dari $n$.

## 2. Solusi Optimal

Untuk $k \mid n$, kita memiliki $\text{LCM}(k, n-k) = n-k$. Oleh karena itu, untuk meminimalkan LCM, kita perlu meminimalkan $n-k$, atau secara ekuivalen memaksimalkan $k$. Ini berarti $k$ harus dipilih sebagai faktor wajar terbesar dari $n$.

Jika $p$ adalah faktor prima terkecil dari $n$, maka faktor wajar terbesar dari $n$ adalah:

$$k = \frac{n}{p}$$

Kasus khusus terjadi ketika $n$ adalah bilangan prima; dalam hal ini $p = n$ dan $k = 1$.

## 3. Implementasi

Masalah ini direduksi menjadi pencarian faktor prima terkecil dari $n$. Faktor tersebut dapat ditemukan dengan pembagian percobaan (_trial division_) hingga $\sqrt{n}$. Jika tidak ditemukan pembagi pada rentang tersebut, maka $n$ adalah prima.

Untuk batasan $n \le 10^9$, algoritma ini berjalan dalam kompleksitas waktu $O(\sqrt{n})$, yang sangat efisien untuk batas waktu kompetisi. Pasangan optimal yang dihasilkan adalah $(k, n-k)$, dengan $k = n / p$.

Problem berikut dapat diselesaikan dengan pemahaman ini: [1372B - Omkar and Last Class of Math](https://codeforces.com/problemset/problem/1372/B)