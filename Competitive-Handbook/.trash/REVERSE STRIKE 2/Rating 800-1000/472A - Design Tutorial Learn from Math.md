---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 472A
judul_FAST: "Design Tutorial: Learn from Math"
teori_FAST: Semua digit diatas angka 12, bisa dihasilkan dari penjumlahan dua bilangan komposit
sumber:
  - codeforces
date_learned: 2025-08-08T13:25:00
tags:
  - STRIKE
  - number-theory
---
Sumber: [472A - Design Tutorial: Learn from Math](https://codeforces.com/problemset/problem/472/A)

> [!NOTE] ⚔️ Teori STRIKE:
> Semua angka diatas angka 12, bisa didapatkan dari menjumlahkan 2 bilangan komposit, atau non-prima.

<br/>

---
# 472A - Design Tutorial Learn from Math

Kita diminta untuk mencari tahu nilai dari $a$ dan $b$ dari inputan $n$ dimana $a+b=n$, dengan ketentuan bahwa angka $a$ dan $b$ adalah bilangan komposit, atau non-prima.  

<br/>

---
# Sesi STRIKE ⚔️

Berikut adalah jawaban yang sudah benar:

```cpp
/*
Author  : trihajikhr
Date    : 2025-08-08 13:18
Problem : Codeforces - 472A | Design Tutorial: Learn form Math
*/

#include <iostream>
using namespace std;

auto isPrime(int n) -> bool {
   if (n < 2)
      return false;
   for (int i = 2; i * i <= n; i++) {
      if (n % i == 0)
         return false;
   }

   return true;
}

auto main() -> int {
   int n;
   cin >> n;

   int a = n / 2;
   int b = (n % 2 == 0 ? n / 2 : (n / 2) + 1);

   while (isPrime(a) || isPrime(b)) {
      a--;
      b++;
   }

   cout << a << " " << b;
   return 0;
}
```

<br/>

---


# Jawaban dan Editorial

Salah satu cara untuk menyelesaikan masalah ini adalah dengan bruteforce: terdapat O(n) cara berbeda untuk menguraikan n sebagai jumlah dua bilangan. Jika kita dapat memeriksa apakah suatu bilangan merupakan bilangan prima dalam O(1), maka seluruh algoritma dapat berjalan dalam O(n). Anda dapat menggunakan Sieve Eratosthenes untuk melakukan pra-kalkulasi.

Cara lain adalah mencoba membuktikan teorema ini. Pembuktiannya sederhana: jika n adalah bilangan ganjil, maka 9 dan (n-9) adalah jawabannya (n-9 adalah bilangan genap minimal 4, sehingga merupakan bilangan komposit), dan jika n adalah bilangan genap, maka 8 dan (n-8) adalah jawabannya (n-8 adalah bilangan genap minimal 4, sehingga juga harus merupakan bilangan komposit).

## Analisis Pribadi

Kita bagi angka $n$ dengan 2, lalu simpan ke $a$ dan $b$. Jika angkanya genap, maka nilai $a$ dan $b$ akan mendapat nilai yang sama. Tapi jika $n$ ganjil, maka $b$ akan mendapatkan $(n/2)+1$ .

Lalu lakukan pengecekan prima. Jika salah satu dari $a$ atau $b$ adalah prima, maka kita perllu melakukan pengurangan pada $a$ dan penjumlaahn pada $b$, masing-maisng satu. Ini dilakukan hingga tidak ada satupun yang merupakan bilangan prima.