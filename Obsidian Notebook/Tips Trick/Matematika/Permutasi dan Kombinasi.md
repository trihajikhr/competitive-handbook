---
obsidianUIMode: preview
note_type: tips trick
tips_trick: permutasi dan kombinasi
sumber: chatgpt.com
tags:
  - matematika
---
#matematika 

---
# Permutasi dan Kombinasi
Oke, kita bahas **Permutasi dan Kombinasi** sekarang, dua konsep dasar yang sering muncul di matematika diskrit dan kompetisi pemrograman.

## 🧠 Konsep Dasar

### Permutasi (Permutation)

- **Definisi**: Susunan berbeda dari objek-objek yang diambil dari suatu himpunan.
- Urutan **penting** di sini.
- Contoh: Permutasi dari {A, B, C} mengambil 2 elemen adalah AB, BA, AC, CA, BC, CB.
    

---

### Kombinasi (Combination)

- **Definisi**: Pemilihan objek dari suatu himpunan tanpa memperhatikan urutan.
- Urutan **tidak penting**.
- Contoh: Kombinasi dari {A, B, C} mengambil 2 elemen adalah {A, B}, {A, C}, {B, C}.

---

## 📐 Rumus Matematika

| Nama      | Notasi                          | Rumus                   |
| --------- | ------------------------------- | ----------------------- |
| Permutasi | $P(n, r)$                       | $\frac{n!}{(n - r)!}$   |
| Kombinasi | $C(n, r) atau (nr)\binom{n}{r}$ | $\frac{n!}{r!(n - r)!}$ |

---

## 💻 Implementasi C++

### 1. Fungsi Faktorial (faktorial sederhana)

```cpp
long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; ++i)
        res *= i;
    return res;
}
```

---

### 2. Fungsi Permutasi

```cpp
long long permutation(int n, int r) {
    return factorial(n) / factorial(n - r);
}
```

---

### 3. Fungsi Kombinasi

```cpp
long long combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}
```

---

## ⚠️ Catatan Penting

- Fungsi ini cocok untuk $n$ dan $r$ kecil (biasanya < 20), karena faktorial cepat membesar dan bisa overflow.
- Untuk nilai besar dan modulo, kita harus gunakan teknik modular inverse dan precompute faktorial modulo.

---

## 🧪 Contoh Penggunaan

```cpp
#include <iostream>
using namespace std;

long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; ++i)
        res *= i;
    return res;
}

long long permutation(int n, int r) {
    return factorial(n) / factorial(n - r);
}

long long combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    int n = 5, r = 3;
    cout << "Permutasi P(" << n << "," << r << ") = " << permutation(n, r) << endl;
    cout << "Kombinasi C(" << n << "," << r << ") = " << combination(n, r) << endl;
    return 0;
}
```
