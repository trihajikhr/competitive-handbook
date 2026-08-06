---
obsidianUIMode: preview
note_type: latihan
latihan: Urutan Operasi
sumber:
  - chatgpt.com
tags:
  - combinatorics
date_learned: 2025-08-12T01:43:00
---
---
# Bunga Berbeda Warna

Seorang florist memiliki $n$ jenis bunga berbeda (misal mawar merah, tulip kuning, lili putih, dll).

Dia ingin menyusun $k$ bunga dalam satu vas, tetapi **setiap jenis bunga boleh dipakai lebih dari sekali** (boleh ada yang sama).

Urutan bunga dalam vas **tidak penting**.

**Tugas:**
Hitung berapa banyak cara yang mungkin.

**Format Input:**

```
n k
```

**Format Output**

```
jumlah_cara
```

**Input:**

```
3 4
```

**Output:**

```
15
```

<br/>

---
# Jawaban

Berikut adalah jawaban yang sudah lumayan benar:

```cpp
#include <iostream>
using namespace std;

auto nCr(int n, int r) -> long long {
   r = min(r, n - r);

   long long rest = 1;

   for (int i = 1; i <= r; i++) {
      rest *= (n - i + 1);
      rest /= i;
   }

   return rest;
}

auto main() -> int {
   int n, k;
   cin >> n >> k;
   cout << nCr(n + k - 1, k);
   return 0;
}
```

<br/>

---
# Editorial

Oke, kita bikin editorial yang fokus membahas masalah **urutan operasi dalam perhitungan kombinasi**, khususnya saat implementasi di C++ supaya hasilnya benar dan tidak terjadi kesalahan akibat pembagian integer.

## 📜 Editorial — Urutan Operasi di Perhitungan Kombinasi

### Masalah yang Sering Terjadi

Saat kita menghitung kombinasi dengan rumus:

$$
\binom{n}{r} = \frac{n \times (n-1) \times (n-2) \times \dots \times (n-r+1)}{r \times (r-1) \times \dots \times 1}
$$

banyak orang menulis loop seperti ini:

```cpp
for (int i = 1; i <= r; i++) {
    rest = rest * (n - i + 1) / i;
}
```

**Masalahnya:**
Karena `rest` adalah integer, operasi `/ i` akan membulatkan ke bawah. Jika pembagian terjadi sebelum semua faktor perkalian dikalikan, informasi bisa hilang (truncated), yang membuat hasil akhir salah.

Contoh kasus:

* `rest = 2`, `n - i + 1 = 3`, `i = 2`
* `(2 * 3) / 2` = `3` ✅ (benar)
* Kalau kebalik `(2 * 3 / 2)` dihitung sebagai `(2 * 1)` = `2` ❌ (karena `3/2` jadi `1` di integer division)

---

### Solusi

Pastikan **perkalian dilakukan terlebih dahulu**, baru dibagi, agar pembagiannya tepat.

```cpp
for (int i = 1; i <= r; i++) {
    rest *= (n - i + 1); // kalikan dulu
    rest /= i;           // lalu bagi
}
```

Dengan begitu, setiap langkah loop menghasilkan bilangan bulat yang benar, tanpa ada sisa pecahan yang hilang.

---

### Kenapa Tidak Langsung Hitung Faktorial?

Menghitung dengan faktorial:

$$
\binom{n}{r} = \frac{n!}{r! \cdot (n-r)!}
$$

sering membuat **overflow** bahkan untuk nilai `n` yang tidak terlalu besar (misalnya `n=30` sudah mendekati batas `long long`).
Metode perkalian-bagi secara bertahap menjaga hasil tetap kecil selama perhitungan.

---

### Kesimpulan

* Gunakan loop perkalian-bagi bertahap.
* Lakukan **perkalian dulu**, baru **pembagian**.
* Rumus tetap sama, tapi urutan operasi memengaruhi hasil karena pembagian integer membulatkan ke bawah.

