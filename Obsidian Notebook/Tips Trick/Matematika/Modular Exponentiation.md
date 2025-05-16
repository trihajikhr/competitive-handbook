---
obsidianUIMode: preview
note_type: tips trick
tips_trick: modular exponentiation
sumber: chatgpt.com
tags:
  - matematika
  - modular
---
#matematika #modular 

---
# Modular Exponentiation
Sip, kita bahas sekarang **Modular Exponentiation** alias **pangkat cepat modulo** — teknik untuk menghitung:

$$a^b \bmod m$$

dengan efisien, terutama saat $b$ sangat besar.

---

## 🧠 Konsep Modular Exponentiation

### Masalahnya:

Kalau langsung hitung $a^b$ dulu, bisa jadi sangat besar dan tidak muat di memori.

### Solusinya:

Gunakan metode **pangkat cepat (fast exponentiation)** dengan operasi modulo tiap langkah supaya nilainya tetap kecil.

---

## 💻 Implementasi C++: Modular Exponentiation (Iteratif)

```cpp
int modPow(int a, int b, int m) {
    int result = 1;
    a = a % m;

    while (b > 0) {
        if (b & 1) result = (1LL * result * a) % m;
        a = (1LL * a * a) % m;
        b >>= 1;
    }
    return result;
}
```

---

## 🧪 Contoh Penggunaan:

```cpp
#include <iostream>
using namespace std;

int modPow(int a, int b, int m) {
    int result = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) result = (1LL * result * a) % m;
        a = (1LL * a * a) % m;
        b >>= 1;
    }
    return result;
}

int main() {
    int a = 3, b = 13, m = 1000000007;
    cout << a << "^" << b << " mod " << m << " = " << modPow(a, b, m) << endl;
    return 0;
}
```

---

## ⏱ Kompleksitas

- $O(\log b)$, jauh lebih cepat daripada $O(b)$ kalau pakai perulangan biasa.


