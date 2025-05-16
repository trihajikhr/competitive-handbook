---
obsidianUIMode: preview
note_type: tips trick
tips_trick: konsep modular arithmetic
sumber: chatgpt.com
tags:
  - matematika
  - modular
---
#matematika #modular 

---
# 🧠 Konsep Dasar: Modular Arithmetic

### Apa itu Modular Arithmetic?

Modular arithmetic adalah sistem aritmatika di mana angka "dibungkus" setelah mencapai nilai modulus tertentu, mirip jam yang berputar setelah mencapai angka 12.

### Notasi:

$$a \equiv b \pmod{m}$$

dibaca: "a kongruen b modulo m", artinya ketika $a$ dibagi $m$, sisanya adalah $b$.

### Contoh:

- $17 \equiv 5 \pmod{12}$ karena $17 = 12 \times 1 + 5$.
- $25 \equiv 1 \pmod{12}$.

---

## 💻 Operasi Modular di C++

```cpp
int add_mod(int a, int b, int m) {
    return (a % m + b % m) % m;
}

int sub_mod(int a, int b, int m) {
    return (a % m - b % m + m) % m;
}

int mul_mod(int a, int b, int m) {
    return (int)((1LL * (a % m) * (b % m)) % m);
}
```

---

## 🧪 Contoh Penggunaan:

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 17, b = 25, m = 12;

    cout << "Penjumlahan modulo: " << (a + b) % m << endl;
    cout << "Pengurangan modulo: " << (a - b + m) % m << endl;
    cout << "Perkalian modulo: " << (1LL * a * b) % m << endl;

    return 0;
}
```

### Penjelasan kenapa kita pakai `1LL`:

- Dalam ekspresi `(1LL * a * b) % m`, tujuan `1LL` adalah **membuat operasi perkalian berjalan dengan tipe data 64-bit (`long long`)** agar menghindari _overflow_ saat mengalikan dua `int` yang besar.
    
- Kalau kamu hanya menulis `(a * b) % m` dan `a` dan `b` bertipe `int`, maka perkalian `a * b` juga dilakukan dengan tipe `int`. Jika hasilnya melebihi batas `int` (sekitar 2 miliar), maka terjadi _overflow_ yang menyebabkan hasil salah.
    

#### Contoh sederhana:

```cpp
int a = 100000, b = 100000, m = 1000000007;
int res = (a * b) % m;       // Bisa overflow sebelum mod
int res_correct = (1LL * a * b) % m;  // Aman, karena perkalian dalam long long
```
#### Jadi intinya:

- `1LL` = angka 1 sebagai `long long`.
    
- Meng-cast atau memulai operasi dengan `long long` agar seluruh perkalian dilakukan dalam 64-bit.
    
- Ini teknik **standar** untuk menghindari overflow di operasi perkalian modular.
    
---

## 🔑 Kenapa Modular Arithmetic penting?

- Memastikan hasil perhitungan tidak overflow.
    
- Digunakan di algoritma hashing, kriptografi, dan pemrograman kompetitif.
    
- Sering muncul soal menghitung pangkat besar modulo mm.
