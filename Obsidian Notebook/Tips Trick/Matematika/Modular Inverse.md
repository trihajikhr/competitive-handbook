---
obsidianUIMode: preview
note_type: tips trick
tips_trick: modular inverse
sumber: chatgpt.com
tags:
  - matematika
  - modular
---
#matematika #modular

---
# Modular Inverse
Mantap! Sekarang kita masuk ke topik **Modular Inverse** — konsep penting yang sering muncul ketika kita perlu melakukan pembagian dalam operasi modulo.

---

## 🧠 Konsep Modular Inverse

### Apa itu Modular Inverse?

Misalkan kita punya angka $a$ dan modulus $m$, modular inverse dari $a$ modulo $m$ adalah bilangan $x$ sehingga:

$$a \times x \equiv 1 \pmod{m}$$

Artinya, $x$ adalah “kebalikan” dari $a$ di sistem modulo $m$.

---

### Kapan modular inverse digunakan?

Karena pembagian biasa tidak berlaku di modulo, kita gunakan modular inverse untuk “membagi” dengan $a$ modulo $m$:

$$\frac{b}{a} \equiv b \times a^{-1} \pmod{m}$$

---

## ⚠️ Catatan penting:

- Modular inverse **hanya ada jika $a$ dan $m$ coprime** $(FPB(a, m) = 1)$.
    
- Jika $m$ adalah bilangan prima, kita bisa gunakan **Fermat’s Little Theorem** untuk cari inverse.
    

---

## 💻 Cara Cari Modular Inverse

### 1. Dengan Fermat’s Little Theorem (jika $m$ prima)

$$a^{-1} \equiv a^{m-2} \pmod{m}$$

Gunakan fungsi `modPow` yang sudah kita buat tadi:

```cpp
int modInverse(int a, int m) {
    return modPow(a, m - 2, m);
}
```

---

### 2. Dengan Extended Euclidean Algorithm (bisa untuk mm non-prima)

```cpp
int extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x1, y1;
    int d = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

int modInverse(int a, int m) {
    int x, y;
    int g = extendedGCD(a, m, x, y);
    if (g != 1) return -1; // inverse tidak ada
    x = (x % m + m) % m;
    return x;
}
```

---

## 🧪 Contoh Penggunaan

```cpp
#include <iostream>
using namespace std;

// Fungsi modPow dari sebelumnya
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

int modInverse(int a, int m) {
    return modPow(a, m - 2, m); // asumsikan m prima
}

int main() {
    int a = 3, m = 1000000007;
    int inv = modInverse(a, m);
    if (inv != -1) cout << "Modular inverse dari " << a << " mod " << m << " adalah " << inv << endl;
    else cout << "Modular inverse tidak ada" << endl;
    return 0;
}
```

---

## 🔑 Kesimpulan

- Modular inverse berguna untuk operasi pembagian di modulo.
    
- Gunakan Fermat’s Little Theorem untuk mm prima.
    
- Gunakan Extended Euclidean untuk kasus umum.
    
