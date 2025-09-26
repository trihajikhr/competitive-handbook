---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Pembulatan Tanpa Fungsi Bawaan
sumber:
  - google.com
  - gemini.google.com
date_learned: 2025-07-17T02:08:00
tags:
  - math
  - function
---
Link Sumber: [Find ceil of a/b without using ceil() function - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/find-ceil-ab-without-using-ceil-function/)

---
# Pembulatan ke Bawah dan ke Atas (Tanpa Fungsi Bawaan)

## 1 | Konteks

Dalam pemrograman kompetitif dan perhitungan integer, kamu sering kali perlu menghitung:

* **Pembulatan ke bawah**: $\left\lfloor \frac{a}{b} \right\rfloor$
* **Pembulatan ke atas**: $\left\lceil \frac{a}{b} \right\rceil$

Tanpa menggunakan fungsi built-in seperti `ceil()` atau `floor()`, kita bisa memanfaatkan **operasi bilangan bulat**.

## 2 | Pembulatan ke Bawah (Floor)

> Untuk bilangan bulat positif dan negatif:

$$
\left\lfloor \frac{a}{b} \right\rfloor = \text{hasil pembagian biasa } (a / b)
$$

Di C++ atau bahasa lain:

* Jika `a` dan `b` bertipe `int`, maka `a / b` otomatis memberikan hasil pembulatan ke bawah jika a dan b memiliki tanda yang sama.

### 2.1 | Masalah: Tanda Berbeda

Untuk `a` negatif dan `b` positif, C++ **membulatkan ke nol**, bukan ke bawah. Maka kita perlu perbaikan manual.

Berikut implementasi Aman:

```cpp
int floor_div(int a, int b) {
    if (a % b == 0) return a / b;
    if ((a < 0) != (b < 0)) return a / b - 1; // tanda beda
    return a / b;
}
```

## 3 | Pembulatan ke Atas (Ceil)

> Untuk mendapatkan:

$$
\left\lceil \frac{a}{b} \right\rceil
$$

Gunakan rumus umum:

$$
\text{ceil}(a, b) = \frac{a + b - 1}{b}
\quad \text{(jika a dan b positif)}
$$

Tapi jika `a` atau `b` bisa negatif, kamu perlu hati-hati. Cara implementasi umum (Integer-Safe) berikut bisa digunakan:

```cpp
int ceil_div(int a, int b) {
    if (a % b == 0) return a / b;
    if ((a > 0) == (b > 0)) return a / b + 1; // tanda sama
    return a / b;
}
```

Namun, di competitive programming, biasanya pembulatan keatas cukup dilakukan dengan langsung menggunakan rumus diatas, tanpa perlu membuat fungsi terpisah. Tapi jika ingin menggunakan fungsi terpisah, maka bisa menggunakan cara dibawah.

Jika kamu yakin `a ≥ 0` dan `b > 0`, cukup:

```cpp
int ceil_div(int a, int b) {
    return (a + b - 1) / b;
}
```

## 4 | Contoh Penggunaan

```cpp
cout << floor_div(7, 3);  // Output: 2
cout << ceil_div(7, 3);   // Output: 3

cout << floor_div(-7, 3); // Output: -3
cout << ceil_div(-7, 3);  // Output: -2
```

## 5 | Catatan Tambahan

* Di banyak kompetisi, `ceil_div(a, b)` sering digunakan untuk membagi tugas/kapasitas dalam bentuk integer.
* Pastikan tidak terjadi **overflow** saat menghitung `(a + b - 1)`, terutama jika `a` dan `b` besar → gunakan `long long`.

## 6 | Keguanaan dan Kenapa

Sebenarnya, **"rumus pembulatan ke atas"** dan fungsi **`ceil`** (ceiling) pada dasarnya melakukan hal yang sama: membulatkan bilangan real ke bilangan bulat terkecil yang lebih besar atau sama dengan bilangan itu.

Tapi ada beberapa alasan kenapa orang kadang lebih memilih *rumus manual* daripada langsung pakai `ceil`:
### 6.1 | Portabilitas (tidak bergantung library)

* Fungsi `ceil` ada di `<cmath>` (C++), `math` (Python), dll.
* Kadang di kompetisi atau embedded system, orang ingin meminimalisir penggunaan library, jadi cukup pakai rumus aritmetika sederhana.
  Misalnya:

  $$
  \text{ceil}\Big(\frac{a}{b}\Big) = \frac{a + b - 1}{b} \quad \text{(jika a, b > 0, bilangan bulat)}
  $$

### 6.2 | Kinerja

* Rumus berbasis operasi integer (penjumlahan & pembagian bulat) biasanya lebih cepat daripada memanggil `ceil`, karena `ceil` bekerja dengan *floating point* lalu dikonversi kembali.
* Dalam CP (Competitive Programming), rumus integer lebih disukai karena menghindari floating point error.

### 6.3 | Menghindari masalah presisi

* `ceil(3.00000000000001)` bisa menghasilkan `4`, padahal mungkin maksud kita `3`.
* Kalau konteksnya adalah integer division, rumus `(a + b - 1) / b` lebih aman karena tidak menyentuh floating point sama sekali.

### 6.4 | Lebih sesuai dengan konteks integer

* Banyak problem CP berbentuk: *"berapa banyak wadah dibutuhkan untuk menampung n item dengan kapasitas k tiap wadah?"*
* Solusinya langsung pakai rumus:

  $$
  \left\lceil \frac{n}{k} \right\rceil = \frac{n + k - 1}{k}
  $$

  Ini jauh lebih simpel, tidak perlu convert ke double, lalu panggil `ceil`, lalu convert balik ke int.
### 6.5 | Ringkasnya:

* **Gunakan `ceil`** → ketika bekerja dengan **float** atau **double**.
* **Gunakan rumus pembulatan integer** → ketika bekerja dengan **integer division** dalam konteks diskrit (misalnya CP).

## 6 | Kesimpulan

| Operasi      | Rumus (Positif)         | Catatan                    |
| ------------ | ----------------------- | -------------------------- |
| Floor        | `a / b`                 | Aman jika `a, b` positif   |
| Ceil         | `(a + b - 1) / b`       | Hanya aman jika `a, b` ≥ 0 |
| Floor (umum) | Periksa tanda & modulus | Perlu fungsi khusus        |
| Ceil (umum)  | Periksa tanda & modulus | Perlu fungsi khusus        |

Kesimpulannya, penggunaan rumus pembulatan ke atas lebih bermanfaat ketimbang `ceil` ketika bekerja dalam konteks bilangan bulat, karena lebih aman dari error presisi floating point, lebih efisien secara kinerja, serta tidak bergantung pada library tambahan; sementara `ceil` lebih cocok dipakai saat menangani bilangan pecahan (float/double) yang memang memerlukan pembulatan ke atas secara langsung.
