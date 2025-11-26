---
obsidianUIMode: preview
note_type: tips trick
tips_trick: mencari fpb atau gcd
sumber: chatgpt.com
tags:
  - matematika
---
#matematika 

---

# 🧠 Konsep Dasar: FPB (Faktor Persekutuan Terbesar)

### Apa itu FPB?

FPB, atau dalam istilah bahasa inggris **GCD** (Greatest Common Divisor), adalah bilangan bulat terbesar yang dapat membagi habis dua bilangan (atau lebih). Misalnya:

- FPB dari 12 dan 18 adalah 6.
### Metode yang umum digunakan:

1. **Faktorisasi** (kurang efisien untuk bilangan besar).
2. **Algoritma Euclidean** (sangat efisien, terutama untuk pemrograman).
### Algoritma Euclidean:

Jika kita ingin mencari FPB($a$, $b$), kita lakukan:

```
FPB(a, b) = FPB(b, a % b)
```

Ulangi sampai `b = 0`. Maka hasilnya adalah `a`.

---

## 💻 Implementasi FPB di C++

### Versi rekursif

```cpp
int fpb(int a, int b) {
    if (b == 0) return a;
    return fpb(b, a % b);
}
```

### Versi iteratif

```cpp
int fpb(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
```

---

## 🧪 Contoh Penggunaan

```cpp
#include <iostream>
using namespace std;

int fpb(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int x = 48, y = 18;
    cout << "FPB dari " << x << " dan " << y << " adalah " << fpb(x, y) << endl;
    return 0;
}
```

## 💯 Fungsi bawaan
Di C++, kita bisa mencari FPB dengan menggunakan fungsi bawaan C++, yang baru tersedia di C++17 keatas, yaitu fungsi `gce()` dari header `<numeric>`. Berikut contohnya:

```cpp
#include <iostream>
#include <numeric>  // std::gcd

int main() {
    int a = 36, b = 60;
    std::cout << "GCD: " << std::gcd(a, b) << "\n";  // Output: 12
    return 0;
}
```