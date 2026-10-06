---
obsidianUIMode: preview
note_type: latihan
latihan: Kombinasi Multiplicative Formula
sumber:
  - chatgpt.com
tags:
  - combinatorics
date_learned: 2025-08-12T00:16:00
---
---
# Festival Layang-Layang 🎏


Di sebuah festival, terdapat **n** jenis layang-layang berbeda. Panitia ingin membuat pajangan yang berisi tepat **k** layang-layang.

Namun ada **aturan khusus**: layang-layang yang dipajang **harus berwarna berbeda**, dan urutan penempatan di pajangan **tidak penting**.

Hitung berapa banyak cara berbeda panitia dapat memilih layang-layang tersebut.

**Input format:**

```
n k
```

**Output format:**

```
jumlah_cara
```

**Batasan:**

* $0 \le k \le n \le 50$
* Gunakan hasil kombinasi $\binom{n}{k}$ dengan metode yang efisien agar tidak overflow.

**Contoh:**

```
Input:
6 3

Output:
20
```

Kalau tadi kamu bisa pakai rumus faktorial, kali ini cobalah bikin versi CP-friendly yang tidak menghitung faktorial besar secara langsung (hint: gunakan perhitungan bertahap supaya aman untuk n=50).

<br/>

---
# Jawaban

Berikut adalah jawaban yang disarankan:

```cpp
#include <iostream>
using namespace std;

auto nCr(int n, int k) -> long long {
   if (k > n - k)
      k = n - k;

   long long rest = 1;
   for (int i = 1; i <= k; i++) {
      rest = rest * (n - i + 1) / i;
   }

   return rest;
}

auto main() -> int {
   int n, k;
   cin >> n >> k;
   cout << nCr(n, k) << '\n';
   return 0;
}
```

<br/>

---
# Editorial

Baiklah, mari kita bedah kode ini.

**Hint (tanpa cheat):**

1. Ambil `k = min(k, n-k)` supaya loopnya lebih pendek.
<br/>

2. Gunakan **rumus multiplicative** — bukan faktorial penuh. Intinya:

   $$
   \binom{n}{k}=\prod_{i=1}^{k}\frac{n-i+1}{i}
   $$

   artinya kamu kalikan bertahap pembilang `(n-i+1)` dan bagi dengan `i` setiap langkah, bukan menghitung faktorial besar.
<br/>

3. Untuk menjaga angka tetap bulat dan mencegah overflow sementara, **selalu sederhanakan** pembilang dan penyebut menggunakan `gcd` sebelum mengalikan. Contoh strategi:

   * punya array/variabel pembilang yang tinggal `(n-i+1)` tiap iterasi,
   * bagi nilai `i` dengan gcd terhadap pembilang sebelum melakukan operasi perkalian.
<br/>

3. Pakai `long long` (atau `__int128` bila kamu mau ekstra aman), tapi kalau kamu menerapkan penyederhanaan gcd tiap langkah, `long long` cukup untuk batas yang diberikan.
<br/>

4. Pastikan hasil akhir tetap integer dan lakukan pembagian hanya setelah penyederhanaan — jangan lakukan pembagian float.

Masih belum paham? Oke, baca versi satunya!

---
## Trik Aman Hitung Hasil Kombinasi
### 1. Prinsip dasar kombinasi

Rumus umum:

$$
\binom{n}{k} = \frac{n!}{k!(n-k)!}
$$

Masalahnya di CP: menghitung faktorial langsung bisa bikin **overflow** meskipun $n$ kecil (misalnya $20!$ sudah > $2^{63}$ kalau pakai `long long`).

### 2. Trik simetri kombinasi

Kombinasi punya sifat:

$$
\binom{n}{k} = \binom{n}{n-k}
$$

Jadi kalau $k > n-k$, kita cukup hitung $\binom{n}{n-k}$ supaya langkahnya lebih sedikit. Contoh: $\binom{10}{7} = \binom{10}{3}$, lebih gampang hitung yang $k=3$.

Di kode:

```cpp
if (k > n - k) k = n - k;
```

Atau:

```cpp
k = min(k, n-k);
```

### 3. Rumus perkalian bertahap (multiplicative formula)

Dari rumus faktorial, kita bisa sederhanakan jadi:

$$
\binom{n}{k} = \frac{n}{1} \times \frac{n-1}{2} \times \frac{n-2}{3} \times \dots \times \frac{n-k+1}{k}
$$

Jadi kita mulai dari 1, lalu tiap langkah:

* Kalikan pembilang dengan $(n - i + 1)$
* Bagi hasilnya dengan $i$ (pembagi langkah sekarang)

### 4. Kenapa aman dari overflow?

* Kita **tidak** simpan pembilang & penyebut besar-besaran.
* Setiap langkah langsung dibagi → angka tetap kecil.
* Dengan $n \le 50$, `long long` (64-bit) sudah cukup.
### 5. Alur hitung di kode

Misal $n=6$, $k=3$:

```
res = 1
i=1 → res = 1 * 6 / 1 = 6
i=2 → res = 6 * 5 / 2 = 15
i=3 → res = 15 * 4 / 3 = 20
```

Selesai, hasilnya **20**.

### 6. Visualisasi cara kerja

$$
\binom{6}{3} = \frac{6}{1} \times \frac{5}{2} \times \frac{4}{3}
$$


| Iterasi $i$ | Operasi yang Dilakukan | Nilai `res` Sebelum | Hitung                 | Nilai `res` Sesudah |
| ----------- | ---------------------- | ------------------- | ---------------------- | ------------------- |
| 1           | res × (6) ÷ 1          | 1                   | $1 \times 6 / 1 = 6$   | 6                   |
| 2           | res × (5) ÷ 2          | 6                   | $6 \times 5 / 2 = 15$  | 15                  |
| 3           | res × (4) ÷ 3          | 15                  | $15 \times 4 / 3 = 20$ | 20                  |

✅ **Hasil akhir:** $\binom{6}{3} = 20$

---

**Keunggulan metode ini:**

* Tidak pernah menyimpan $6! = 720$ atau angka besar lain → aman dari overflow.
* Hanya butuh $k$ langkah, bukan 3 faktorial.
* Sangat cocok di CP untuk $n$ sedang hingga besar (misalnya $n = 1000$ kalau tipe data mencukupi).

> You said: Oke, intinya, alih alih simpan hasil kali yang mungkin gede banget, mending langsung bagi aja? Gitu kan maksunya?

Ya, persis! 🤓

Intinya:

- Kalau langsung hitung faktorial → angka cepat **meledak** sebelum sempat dibagi.
    
- Kalau pakai **multiplicative formula**, kita **bagi setiap langkah** → angka tetap kecil, aman, dan cepat.
    

Ini kayak prinsip **mencuci piring sambil makan**:  
jangan tunggu semua piring numpuk baru dicuci (faktorial penuh), tapi langsung cuci tiap selesai makan satu piring (bagi tiap langkah). 🍽️

Kalau sudah paham konsep ini, kita bisa bikin kombinasi yang **super besar** tanpa bikin komputer “pusing” duluan.
