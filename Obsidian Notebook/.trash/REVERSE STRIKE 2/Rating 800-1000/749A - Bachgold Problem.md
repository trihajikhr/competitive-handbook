---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 749A
judul_FAST: Bachgold Problem
teori_FAST: Jumlah bilangan prima terbanyak dari n
sumber:
  - codeforces
date_learned: 2025-08-08T14:00:00
tags:
  - STRIKE
  - number-theory
---
Sumber: [749A - Bachgold Problem](https://codeforces.com/contest/749/problem/A "Codeforces Round 388 (Div. 2)")

> [!NOTE] ⚔️ Teori STRIKE:
> Semua angka, diatas satu, bisa disusun dengan jumlah prima maksimum, jika disusun dengan angka 2 dan 3. Untuk angka genap, dia bisa disusun dengan angka 2 terus menerus untuk mendapatkan jumlah prima maksimum. Untuk angka ganjil, juga bisa dilakukan hal yang sama, perbedaanya adalah diangka terakhir, ganti 2 menjadi 3. Jumlah kemunculan prima pada akhirnya sama dengan $n/2$.

<br/>

---
# 749A - Bachgold Problem

**Bachgold problem** sangat mudah untuk diformulasikan. Diberikan sebuah bilangan bulat positif **n**, representasikan bilangan tersebut sebagai jumlah (*sum*) dari **sebanyak mungkin** bilangan prima. Dapat dibuktikan bahwa representasi seperti itu selalu ada untuk setiap bilangan bulat yang lebih besar dari 1.

Ingat bahwa suatu bilangan bulat **k** disebut **prima** jika bilangan tersebut lebih besar dari 1 dan memiliki tepat dua pembagi bilangan bulat positif — yaitu **1** dan **k** itu sendiri.

<br/>

---
# Sesi STRIKE ⚔️

Berikut adalah jawaban yang sudah benar:

```cpp
/*
Author  : trihajikhr
Date    : 2025-08-08 13:55
Problem : Codeforces - 749A | Bachgold problem
*/

#include <iostream>
using namespace std;

auto main() -> int {
   int n;
   cin >> n;
   bool odd = n % 2 == 1;

   cout << n / 2 << '\n';
   for (int i = 0; i < n / 2; i++) {
      if (odd && i == (n / 2) - 1) {
         cout << 3;
         continue;
      }

      cout << 2 << " ";
   }
   return 0;
}
```


<br/>

---


# Jawaban dan Editorial

Kita perlu merepresentasikan bilangan bulat **N** (`1 < N`) sebagai jumlah (_sum_) dari **sebanyak mungkin** bilangan prima. Bilangan-bilangan prima tersebut **tidak harus berbeda**.

Jika **N** adalah bilangan genap, kita bisa merepresentasikannya sebagai jumlah yang hanya terdiri dari **2** – bilangan prima terkecil. Karena ini adalah bilangan prima terkecil, maka jumlah bilangan prima dalam penjumlahannya akan maksimal pada kasus ini.

Jika **N** adalah bilangan ganjil, kita bisa merepresentasikan `N - 1` sebagai jumlah yang hanya terdiri dari **2**, lalu mengganti suku terakhir dari **2** menjadi **3**.

Penggunaan bilangan prima **P > 3** sebagai salah satu suku **tidak optimal**, karena bisa diganti dengan lebih dari satu angka **2** dan **3**.

## Analisis Pribadi