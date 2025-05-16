---
obsidianUIMode: preview
note_type: tips trick
tips_trick: 
sumber: 
tags:
  - matematika
---
#matematika

---
Bagus! Yang aku maksud dengan **template header** adalah file C++ (misalnya bernama `math_utils.hpp`) yang berisi kumpulan fungsi matematika penting—baik bawaan dari C++ maupun buatan sendiri—jadi kamu bisa langsung `#include "math_utils.hpp"` di semua programmu tanpa nulis ulang fungsinya terus-menerus.

Contohnya seperti ini:

---

### 📂 `math_utils.hpp`

```cpp
#ifndef MATH_UTILS_HPP
#define MATH_UTILS_HPP

#include <numeric>  // for std::gcd and std::lcm (C++17+)
#include <vector>
#include <cmath>    // for sqrt

// GCD alias FPB
int gcd(int a, int b) {
    return std::gcd(a, b); // C++17
}

// LCM alias KPK
int lcm(int a, int b) {
    return std::lcm(a, b); // C++17
}

// Cek bilangan prima
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// Faktorisasi prima
std::vector<int> primeFactors(int n) {
    std::vector<int> factors;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

#endif
```

---

### 💻 Contoh Pemakaian di `main.cpp`

```cpp
#include <iostream>
#include "math_utils.hpp"

int main() {
    int a = 24, b = 36;
    std::cout << "GCD: " << gcd(a, b) << "\n";
    std::cout << "LCM: " << lcm(a, b) << "\n";

    int n = 29;
    std::cout << n << " is prime? " << (isPrime(n) ? "Yes" : "No") << "\n";

    std::vector<int> faktors = primeFactors(60);
    std::cout << "Prime factors of 60: ";
    for (int f : faktors) std::cout << f << " ";
    std::cout << "\n";

    return 0;
}
```

---

### 💡 Keuntungan:

- Tinggal pakai `#include "math_utils.hpp"` setiap kali kamu butuh operasi matematika.
    
- Kode utama jadi lebih bersih.
    
- Kamu bisa terus menambahkan fungsi baru ke file ini (misalnya `modular_inverse`, `sieve`, dll).
    

---

Kalau kamu suka gaya ini, aku bisa bantu kamu buatkan versi awalnya lalu bantu mengembangkannya tiap kali kamu belajar konsep baru. Mau aku bantu buat versi lengkap awalnya?