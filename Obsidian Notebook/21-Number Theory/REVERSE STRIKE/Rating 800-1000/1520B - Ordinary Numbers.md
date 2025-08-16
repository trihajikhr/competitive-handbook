---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 1520B
judul_FAST: Ordinary Numbers
teori_FAST: Digit sama pada satuan, puluhan, ratusan, dan seterusnya selalu 9
sumber:
  - codeforces
date_learned: 2025-08-08T14:58:00
tags:
  - STRIKE
  - number-theory
---
Sumber: [1520B - Ordinary Numbers](https://codeforces.com/problemset/problem/1520/B)

> [!NOTE] ⚔️ Teori STRIKE:
> Setiap angka satuan, puluhan, ratusan, ribuan, dan seterusnya, pasti memiliki 9 nilai angka dengan susunan digit yang sama.

<br/>

---
# 1520B - Ordinary Numbers

Kita sebut suatu bilangan bulat positif **n** sebagai _ordinary_ jika dalam notasi desimal semua digitnya sama.  

Sebagai contoh, **1**, **2**, dan **99** adalah _ordinary numbers_, tetapi **719** dan **2021** bukan _ordinary numbers_.

Untuk suatu bilangan **n** yang diberikan, tentukan berapa banyak _ordinary numbers_ di antara bilangan dari **1** sampai **n**.


<br/>

---
# Sesi STRIKE ⚔️

Ini adalah jawabanya:

```cpp
/*
Author  : trihajikhr
Date    : 2025-08-08 14:28
Problem : Codeforces - 1520B | Ordinary Numbers
*/

#include <iostream>
using namespace std;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void solve() {
   string n;
   cin >> n;
   if (n.length() == 1) {
      cout << n << '\n';
      return;
   }

   int sum = 9 * (n.length() - 1);
   int f = n[0] - '0';
   sum += f;

   for (int i = 1; i < n.length(); i++) {
      if (f > (n[i] - '0')) {
         sum--;
         break;
      } else if (f < (n[i]) - '0') {
         break;
      }
   }

   cout << sum << '\n';
}

auto main() -> int {
   fastio();
   int t;
   cin >> t;
   while (t--) solve();
   return 0;
}
```

<br/>

---

# Jawaban dan Editorial

## Analisis Pribadi

Editorial menggunakan pendekatan nested loop, tapi kita cukup menggunakan pendektan yang ini.

Setiap angka satuan, puluha, dan seterusnya, hanya memiliki 9 angka dengan nilai digit yang sama. Semisal 1,2,33,999, dan 66666, dan seterusnya.

Sehingga, kita terima integer sebagai string. Jika panjangnya adalah 1, maka itu satuan, dan kita outputkan saja langsung. 

Jika itu pululan, ratusan, ribuan, dan seterusnya, maka pasti dia sudah melewati banyak angka sebelumnya. Semisal $n$ adalah ratusan 5XX, otomatis $n$ sudah melewati semua puluhan, dan  semua satuan.

Otomatis, nilai $n$ pasti memiliki angka ordinary numbers $18 \leq n$. 

Selanjutnya, semisal angka $n$ tadi adalah 5XX, maka kita tahu bahwa angka ratusan 5XX, memiliki digit awal 5, dan kita ambil digit pertama, didapat hasil akhir sekarang adalah $18 + 5 = 23$.

Tetapi, kita harus tahu, bahwa ketika angka 5XX adalah 501, otomatis dia belum mencapai angka 555 yang dibutuhkan untuk kita ambil 5 sebagai penambahan akhir. Justru hasil yang benar dalam kondisi ini adalah $18+4=22$.

Oleh karena itu, kita lakukan pengecekan pada semua digit selain digit pertama. Jika kita meneukan digit yang berbeda, dan digit yang berbeda tersebut lebih besar dari digit pertama, maka kita break, karena dipastikan nilai sudah benar.

Tapi jika digit yang berbeda tersebut lebih kecil dari digit pertama, maka kita ambil $\text {digit pertama} - 1$, lalu break, tidak usah pikirkan digit dibelakangnya.

Lalu, tampilkan hasil akhir.