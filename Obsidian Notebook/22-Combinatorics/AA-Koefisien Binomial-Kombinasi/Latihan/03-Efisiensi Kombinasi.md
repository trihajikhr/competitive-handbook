---
obsidianUIMode: preview
note_type: latihan
latihan: Efisiensi Kombinasi
sumber:
  - chatgpt.com
tags:
  - combinatorics
date_learned: 2025-08-12T00:50:00
---
---
# Tim Panahan Terbaik 🏹

Dalam sebuah turnamen panahan, ada $n$ atlet. Pelatih ingin memilih $k$ atlet untuk membentuk **tim inti**.

Namun, aturan turnamen menyebutkan bahwa **setiap tim inti harus memiliki minimal 1 pemanah kidal**.

Terdapat $m$ atlet yang kidal di antara $n$ atlet tersebut.

Hitung berapa banyak cara pelatih dapat membentuk tim inti yang memenuhi syarat.

**Input format:**

```
n m k
```

* $1 \le m \le n \le 50$
* $1 \le k \le n$

**Output format:**

```
jumlah_cara
```

**Contoh:**

```
Input:
5 2 3

Output:
9
```

**Penjelasan contoh:**

* Total cara pilih tim: $\binom{5}{3} = 10$ (tanpa aturan khusus)
* Tim tanpa kidal: pilih semua dari (n-m) atlet tangan kanan = $\binom{3}{3} = 1$
* Jawaban = total - tim tanpa kidal = $10 - 1 = 9$ 

Hint kecil: **Pakai kombinasi dan prinsip komplemen** (total semua tim - tim yang melanggar aturan).

<br/>

---
# Jawaban

Berikut adalah jawabanya:

```cpp
#include <iostream>
using namespace std;

auto nCr(int n, int k) -> long long {
   k = min(k, n - k);
   long long res = 1;
   for (int i = 1; i <= k; i++) {
      res = res * (n - i + 1) / i;
   }
   return res;
}

auto main() -> int {
   int n, m, k;
   cin >> n >> m >> k;

   long long total = nCr(n, k);
   long long normal = (n - m >= k) ? nCr(n - m, k) : 0;  
	   // jika tak cukup atlet tangan kanan
   cout << total - normal << '\n';
   return 0;
}
```

<br/>

---
# Editorial

### 1 | Identifikasi masalah
Kita punya:

* $n$ = jumlah total atlet
* $m$ = jumlah atlet kidal
* $k$ = jumlah anggota tim inti

Syarat: tim harus punya **≥ 1 atlet kidal**.
Kita diminta menghitung **jumlah cara** membentuk tim seperti itu.


### 2 | Pendekatan
Alih-alih langsung menghitung tim yang valid, lebih mudah menghitung **semua tim** lalu mengurangi **tim yang tidak valid**.

* **Semua tim** (tanpa aturan) = $\binom{n}{k}$
* **Tim tanpa kidal** = semua anggota diambil dari atlet tangan kanan (jumlah = $n - m$), sehingga:

  $$
  \binom{n-m}{k}
  $$

  Tapi ini hanya valid jika $n - m \ge k$, kalau tidak, hasilnya **0**.

### 3 | Rumus akhir

$$
\text{Jawaban} =
\binom{n}{k} - 
\begin{cases}
\binom{n-m}{k}, & \text{jika } n-m \ge k \\
0, & \text{jika } n-m < k
\end{cases}
$$


### 4 | Alasan memilih metode ini

* Menghitung semua tim valid langsung itu ribet (harus pakai penjumlahan kombinasi dari “1 kidal, sisanya kanan” sampai “k kidal, sisanya kanan”).
* Prinsip komplemen memotong perhitungan jadi **2 kombinasi saja**.
* Waktu dan memori efisien, cocok untuk $n \le 50$.

### 5 | Perhitungan manual (contoh)
Input:

```
n = 5, m = 2, k = 3
```

* Semua tim: $\binom{5}{3} = 10$
* Tim tanpa kidal: $\binom{5-2}{3} = \binom{3}{3} = 1$
* Jawaban: $10 - 1 = 9$


### 6 | Kompleksitas

* Menghitung kombinasi dengan rumus **multiplicative formula**: $O(k)$
* Total operasi: $O(k)$ saja, sangat cepat.
