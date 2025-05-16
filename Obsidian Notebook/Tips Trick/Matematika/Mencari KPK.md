---
obsidianUIMode: preview
note_type: tips trick
tips_trick: mencari kpk
sumber: chatgpt.com
tags:
  - matematika
---
#matematika 

---
# 🧠 Konsep Dasar: KPK (Kelipatan Persekutuan Terkecil)

### Apa itu KPK?

KPK, atau dalam istilah bahasa inggris **LCM** (Least Common Multiple), adalah bilangan bulat positif terkecil yang dapat dibagi habis oleh dua bilangan. Misalnya:

- KPK dari 4 dan 6 adalah 12.

### Hubungan dengan FPB

KPK dan FPB saling berkaitan melalui rumus:

$$KPK(a,b)=\frac{a \times b}{FPB(a,b)}$$

---

## 💻 Implementasi KPK di C++

```cpp
int fpb(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int kpk(int a, int b) {
    return (a / fpb(a, b)) * b;
}
```

> Catatan: `(a / fpb(a, b)) * b` lebih aman terhadap **overflow** dibandingkan `a * (b / fpb(a, b))`.

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

int kpk(int a, int b) {
    return (a / fpb(a, b)) * b;
}

int main() {
    int x = 12, y = 18;
    cout << "KPK dari " << x << " dan " << y << " adalah " << kpk(x, y) << endl;
    return 0;
}
```

## 💯 Fungsi Bawaan 
Untuk mencari KPK, kita bisa memanfaatkan fungsi bawaan C++, yang baru tersedia di C++17, yaitu fungsi `lcm()` dari header `<numeric>`. Berikut contoh implementasinya:

```cpp
#include <iostream>
#include <numeric>  // std::lcm

int main() {
    int a = 12, b = 18;
    std::cout << "LCM: " << std::lcm(a, b) << "\n";  // Output: 36
    return 0;
}
```