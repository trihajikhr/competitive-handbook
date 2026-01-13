---
obsidianUIMode: preview
note_type: tips trick
tips_trick: String Fun Fact
sumber:
  - myself
tags:
  - strings
  - tips-trick
---
---
# String Fun Fact

Materi ini berisi tips-trick menarik singkat yang bisa digunakan ketika bermain dengan menggunakan tipe data string. Jika ada teori yang terlalu panjang atau rumit untuk dijelaskan, maka akan dibuat satu file tersendiri.

## 1. Fungsi yang berkaitan dengan string

### 1.1 | Akses awal dan akhir karakter string

Umumnya, programmer akan mengakses karakter pertama string dengan `str[0]`, karena ini mengarah ke indeks pertama string. Dan untuk mengakses karakter terakhir string, mereka biasanya menggunakan `str[str.length()-1]`, karena `str.length()` akan mengembalikan panjang string aktual, tetapi untuk mendapatkan karakter terakhir, maka indeks harus dikurangi dengan satu, karena perhitungan indeks dimulai dari $0$.

Tetapi, ada cara yang lebih efisien untuk mendapatkan karakter pertama dan terakhir dari string, yaitu dengan menggunakan dua fungsi berikut:

- `str.front()`: mengembalikan karakter pertama dari string `str`.
- `str.back()`: mengembalikan karakter terakhir dari string `str`.



