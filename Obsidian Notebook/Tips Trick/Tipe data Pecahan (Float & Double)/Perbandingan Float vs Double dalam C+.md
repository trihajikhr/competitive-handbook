---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Perbandingan Float vs Double dalam C++
sumber: Google.com, AI
tags:
  - tipe-data
  - float
  - double
---

---

# 🔍 Perbandingan `float` vs `double` dalam C++

Dalam pemrograman C++, kita sering menggunakan tipe data `float` dan `double` untuk menyimpan angka desimal (pecahan). Meskipun mirip, keduanya memiliki perbedaan penting dalam **presisi**, **ukuran**, dan **penggunaan**.

---

## 📊 Tabel Perbandingan

| Aspek               | `float`                                | `double`                                 |
|---------------------|----------------------------------------|-------------------------------------------|
| **Kepanjangan**     | Floating-point number                  | Double precision floating-point number    |
| **Ukuran**          | 4 byte (32 bit)                        | 8 byte (64 bit)                           |
| **Presisi**         | ~7 digit desimal akurat                | ~15–16 digit desimal akurat              |
| **Jangkauan nilai** | ~±3.4 × 10³⁸                           | ~±1.7 × 10³⁰⁸                            |
| **Literal default** | Harus pakai `f` (contoh: `3.14f`)      | Literal desimal default (`3.14` = double) |
| **Kecepatan**       | Sedikit lebih cepat (tergantung CPU)   | Sedikit lebih lambat                      |
| **Penggunaan umum** | Ketika memori terbatas & presisi cukup | Ketika butuh presisi tinggi              |

---

## 🧪 Contoh Perbedaan Presisi

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float f = 1.123456789;
    double d = 1.123456789;

    cout << fixed << setprecision(9);
    cout << "float  : " << f << endl;
    cout << "double : " << d << endl;

    return 0;
}
````

**Output:**

```
float  : 1.123456836   ← hanya ~7 digit akurat
double : 1.123456789   ← akurat sampai ~15 digit
```

---

## 📌 Penjelasan Teknis

- `float` menggunakan **32 bit**: 1 bit untuk tanda, 8 bit eksponen, 23 bit mantissa.
    
- `double` menggunakan **64 bit**: 1 bit tanda, 11 bit eksponen, 52 bit mantissa.
    
- Semakin banyak bit mantissa, semakin tinggi presisinya.
    
- `float` cocok untuk aplikasi ringan, `double` cocok untuk akurasi tinggi.

> Ketahui apa itu Mantissa di [[Apa itu Mantissa]]

---

## 📦 Kapan Menggunakan `float`?

Gunakan `float` jika:

- Kamu sedang mengerjakan **game 2D**, **grafik ringan**, atau proyek di **mikrokontroler / embedded system**.
    
- Memori terbatas dan tidak butuh presisi tinggi.
    
- Kamu memproses jutaan angka dan perlu efisiensi memori.
    

## 🎯 Kapan Menggunakan `double`?

Gunakan `double` jika:

- Aplikasi kamu membutuhkan **presisi tinggi** (misalnya: simulasi fisika, perhitungan ilmiah, statistik, keuangan).
    
- Kamu mengikuti kontes pemrograman atau membuat program umum (default aman).
    
- Kamu memproses data numerik penting dan ingin menghindari kesalahan pembulatan.
    

---

## ⚠️ Catatan Tambahan

- Literal desimal seperti `3.14` adalah `double` secara default. Untuk `float`, gunakan `3.14f`.
    
- Perbandingan `float` atau `double` sebaiknya menggunakan **toleransi (epsilon)**:
    

```cpp
const double EPS = 1e-9;
if (abs(a - b) < EPS) {
    cout << "Angka mendekati sama";
}
```

- Jika butuh presisi lebih tinggi lagi, bisa gunakan `long double`, tapi perlu cek dukungan sistem.
    

---

## 📚 Referensi

- [cppreference.com - float vs double](https://en.cppreference.com/)
    
- IEEE 754 Floating Point Standard
    
- Buku: _Programming Principles and Practice Using C++_ oleh Bjarne Stroustrup
    

---

> 💡 Gunakan `float` saat kamu tahu presisi rendah cukup, dan `double` untuk keamanan presisi.

