---
obsidianUIMode: preview
note_type: book theory
judul_materi: Pengertian Lexicographical
sumber:
  - gemini.google.com
date_learned: 2026-01-13T12:31:00
tags:
  - strings
---
Link Sumber: [Lexicographic rank of a String - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/lexicographic-rank-of-a-string/)

---

> [!IMPORTANT]
> **Lexicographical** adalah metode pengurutan data berdasarkan urutan simbol atau abjad, layaknya menyusun kata di dalam kamus. Sistem ini membandingkan karakter demi karakter dari posisi paling kiri ke kanan berdasarkan nilai kode (ASCII/Unicode). Akibatnya, angka sering kali tidak diurutkan berdasarkan nilai matematikanya (contoh: "10" dianggap lebih kecil dari "2" karena dimulai dengan angka 1), dan huruf kapital biasanya mendahului huruf kecil. Metode ini merupakan standar dasar dalam pemrograman untuk mengurutkan string, nama file, atau data tekstual lainnya.
# Pengertian Lexicographical

Secara sederhana, Lexicographical adalah pengurutan berdasarkan urutan abjad (seperti di kamus).

## 1. Pengertian

Urutan ini tidak melihat nilai angka secara keseluruhan, melainkan membandingkan karakter demi karakter dari kiri ke kanan berdasarkan nilai kode (ASCII/Unicode).

## 2. Contoh Perbandingan

Jika kita mengurutkan angka secara biasa (numerik) vs lexicographical:

- Urutan Numerik: `1, 2, 10, 20`
- Urutan Lexicographical: `1, 10, 2, 20`

**Mengapa?** Karena saat membandingkan `10` dan `2`, komputer melihat karakter pertama. `1` datang sebelum `2`, maka `10` dianggap "lebih kecil" dari `2`.

### Contoh perbadingan pada string

|**Data**|**Urutan Lexicographical**|**Penjelasan**|
|---|---|---|
|`apple` vs `apply`|`apple` < `apply`|Karakter ke-5: `e` muncul sebelum `y`.|
|`ball` vs `balloon`|`ball` < `balloon`|Jika semua karakter awal sama, yang **lebih pendek** menang.|
|`Cat` vs `cat`|`Cat` < `cat`|**Huruf besar** (ASCII 67) lebih kecil dari **huruf kecil** (ASCII 99).|
|`123` vs `abc`|`123` < `abc`|**Angka** biasanya muncul sebelum **huruf**.|

### Contoh list yang sudah terurut

Jika kamu punya list acak: `["zebra", "100", "Apple", "apple", "2"]`

Maka urutan **lexicographical**-nya adalah:

1. **"100"** (Dimulai dengan angka 1)
2. **"2"** (Dimulai dengan angka 2)
3. **"Apple"** (Huruf besar A)
4. **"apple"** (Huruf kecil a)
5. **"zebra"** (Huruf terakhir)

### Kenapa ini penting?

Dalam programming, jika kamu menggunakan fungsi `sort()` pada data angka yang disimpan sebagai **String**, kamu akan mendapatkan hasil "aneh" (seperti `1, 10, 2`) karena komputer menggunakan aturan kamus ini, bukan nilai matematikanya.
## 3. Penerapan dalam Programming

- **Sorting String:** Mengurutkan nama user (Andi, Budi, Caca).
- **Version Control:** Membandingkan versi software (v1.0.2 vs v1.0.11).
- **Database:** Pengurutan kolom bertipe `VARCHAR` atau `TEXT`.

## 4. Maksud & Kesimpulan

Maksud utamanya adalah memberikan standar cara komputer membandingkan dua buah kata atau deretan simbol.

> **Catatan:** Dalam urutan ini, huruf kapital biasanya muncul lebih dulu daripada huruf kecil (Contoh: "Z" lebih kecil dari "a") karena nilai ASCII-nya lebih rendah.



