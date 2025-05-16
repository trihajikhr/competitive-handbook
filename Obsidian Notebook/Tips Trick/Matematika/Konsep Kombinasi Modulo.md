---
obsidianUIMode: preview
note_type: tips trick
tips_trick: konsep kombinasi modulo
sumber: chatgpt.com
tags:
  - matematika
  - modular
---
#matematika #modular 

---
# Konsep kombinasi Modulo
Oke, kita masuk ke cara menghitung **Kombinasi modulo** yang aman untuk angka besar — penting banget di pemrograman kompetitif!

---

## 🧠 Konsep Kombinasi Modulo

Kita ingin menghitung:

$$C(n, r) \bmod m = \frac{n!}{r! \times (n-r)!} \bmod m$$

dengan $m$ biasanya bilangan prima besar (contoh: $10^9+7$).

---

## 🔑 Tantangan:

- Faktorial $n!$ bisa sangat besar, jadi kita simpan faktorial modulo $m$.
    
- Untuk pembagian modulo, gunakan **modular inverse**.

---

## 💻 Implementasi Lengkap:

```cpp
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000;   // batas maksimal n
const int MOD = 1000000007;

vector<long long> fact(MAX + 1);
vector<long long> invFact(MAX + 1);

// Modular exponentiation (dari sebelumnya)
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

// Precompute faktorial dan invers faktorial
void precomputeFactorials() {
    fact[0] = 1;
    for (int i = 1; i <= MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAX] = modPow(fact[MAX], MOD - 2, MOD);  // modular inverse dengan Fermat
    for (int i = MAX - 1; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

// Fungsi kombinasi modulo
long long nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

int main() {
    precomputeFactorials();
    int n = 1000000, r = 500000;
    cout << "C(" << n << "," << r << ") mod " << MOD << " = " << nCr(n, r) << endl;
    return 0;
}
```

---

## Penjelasan singkat:

- `fact[i]` menyimpan $i!$ mod $m$.
    
- `invFact[i]` menyimpan modular inverse dari $i!$ mod $m$.
    
- Jadi rumus $C(n,r) = fact[n] \times invFact[r] \times invFact[n-r] \bmod m$.
    
