---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Pembulatan Tanpa Fungsi Bawaan
sumber: Google.com, AI
date_learned: 2025-07-17T02:08:00
tags:
  - math
  - function
---
Link Sumber: 

---
# 📚 Materi: Pembulatan ke Bawah dan ke Atas (Tanpa Fungsi Bawaan)

## 🔹 Konteks

Dalam pemrograman kompetitif dan perhitungan integer, kamu sering kali perlu menghitung:

* **Pembulatan ke bawah**: $\left\lfloor \frac{a}{b} \right\rfloor$
* **Pembulatan ke atas**: $\left\lceil \frac{a}{b} \right\rceil$

Tanpa menggunakan fungsi built-in seperti `ceil()` atau `floor()`, kita bisa memanfaatkan **operasi bilangan bulat**.

---

## ✅ Pembulatan ke Bawah (Floor)

> Untuk bilangan bulat positif dan negatif:

$$
\left\lfloor \frac{a}{b} \right\rfloor = \text{hasil pembagian biasa } (a / b)
$$

Di C++ atau bahasa lain:

* Jika `a` dan `b` bertipe `int`, maka `a / b` otomatis memberikan hasil pembulatan ke bawah **jika a dan b memiliki tanda yang sama**.

### ⚠️ Masalah: Tanda Berbeda

Untuk `a` negatif dan `b` positif, C++ **membulatkan ke nol**, bukan ke bawah. Maka kita perlu perbaikan manual.

### 📌 Implementasi Aman:

```cpp
int floor_div(int a, int b) {
    if (a % b == 0) return a / b;
    if ((a < 0) != (b < 0)) return a / b - 1; // tanda beda
    return a / b;
}
```

---

## 🔼 Pembulatan ke Atas (Ceil)

> Untuk mendapatkan:

$$
\left\lceil \frac{a}{b} \right\rceil
$$

Gunakan rumus umum:

$$
\text{ceil}(a, b) = \frac{a + b - 1}{b}
\quad \text{(jika a dan b positif)}
$$

Tapi jika `a` atau `b` bisa negatif, kamu perlu hati-hati.

### 📌 Implementasi Umum (Integer-Safe):

```cpp
int ceil_div(int a, int b) {
    if (a % b == 0) return a / b;
    if ((a > 0) == (b > 0)) return a / b + 1; // tanda sama
    return a / b;
}
```

### 📌 Versi Khusus untuk Positif (Paling Umum di Kontes):

Jika kamu yakin `a ≥ 0` dan `b > 0`, cukup:

```cpp
int ceil_div(int a, int b) {
    return (a + b - 1) / b;
}
```

---

## 📌 Contoh Penggunaan

```cpp
cout << floor_div(7, 3);  // Output: 2
cout << ceil_div(7, 3);   // Output: 3

cout << floor_div(-7, 3); // Output: -3
cout << ceil_div(-7, 3);  // Output: -2
```

---

## 🧠 Catatan Tambahan

* Di banyak kompetisi, `ceil_div(a, b)` sering digunakan untuk membagi tugas/kapasitas dalam bentuk integer.
* Pastikan tidak terjadi **overflow** saat menghitung `(a + b - 1)`, terutama jika `a` dan `b` besar → gunakan `long long`.

---

## ✍️ Kesimpulan

| Operasi      | Rumus (Positif)         | Catatan                    |
| ------------ | ----------------------- | -------------------------- |
| Floor        | `a / b`                 | Aman jika `a, b` positif   |
| Ceil         | `(a + b - 1) / b`       | Hanya aman jika `a, b` ≥ 0 |
| Floor (umum) | Periksa tanda & modulus | Perlu fungsi khusus        |
| Ceil (umum)  | Periksa tanda & modulus | Perlu fungsi khusus        |

