---
obsidianUIMode: preview
note_type: tips trick
tips_trick: pengecekan angka prima
sumber: chatgpt.com
tags:
  - matematika
---
#matematika 

---
# 🧠 Konsep Dasar: Bilangan Prima dan Faktorisasi

### Bilangan Prima (Prime Numbers)

Bilangan bulat positif yang hanya memiliki dua faktor: **1 dan dirinya sendiri**.

Contoh:
- 2, 3, 5, 7, 11, 13, 17, 19, ...

### Ciri-ciri:

- 2 adalah satu-satunya bilangan prima genap.
- Semua bilangan prima selain 2 adalah ganjil.

### Faktorisasi Prima (Prime Factorization)

Memecah sebuah bilangan menjadi hasil perkalian dari bilangan-bilangan prima.
Contoh:

- 60 = 2 × 2 × 3 × 5

---

## 💻 C++: Mengecek Bilangan Prima (Naif)

```cpp
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
```

Ada beberapa orang yang menggukan cara ini:

```cpp
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
```

Ini benar secara logika, namun, ada sedikit catatan penting soal efisiensi dan keakuratan:
### ⚠️ Masalah Teknis Kecil: `sqrt(n)`

- Fungsi `sqrt(n)` mengembalikan **nilai floating point** (`double`).
    
- Dalam perulangan `for (int i = 2; i <= sqrt(n); ++i)`, `sqrt(n)` akan dipanggil **berulang kali**, dan bisa menyebabkan **efisiensi buruk** serta potensi kesalahan pembulatan.
### ✅ Solusi Aman dan Efisien:

Simpan dulu hasil akar dalam variabel:

```cpp
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) return false;
    int batas = sqrt(n);
    for (int i = 2; i <= batas; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
```

Atau bahkan lebih bagus (dan aman tanpa floating point):

```cpp
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
```

> `i * i <= n` adalah teknik umum untuk menghindari `sqrt()` dan menjaga perhitungan tetap di bilangan bulat (integer-only), sehingga lebih cepat dan aman.

---
### 🧠 Kesimpulan:

|Versi|Aman?|Disarankan?|Alasan|
|---|---|---|---|
|`i <= sqrt(n)` langsung|❌|Tidak|Perlu `#include <cmath>`, ada biaya dan resiko pembulatan|
|`int batas = sqrt(n)`|✅|Boleh|Lebih efisien, cukup dipanggil sekali|
|`i * i <= n`|✅|**Ya!**|Cepat, aman, dan tidak pakai floating point|


Kalau kamu mau versi terbaik, gunakan yang `i * i <= n`.  

---

## 💻 C++: Faktorisasi Prima

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> primeFactors(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}
```

---

## 🧪 Contoh Penggunaan

```cpp
int main() {
    int n = 60;
    vector<int> factors = primeFactors(n);
    cout << "Faktorisasi prima dari " << n << ": ";
    for (int f : factors) {
        cout << f << " ";
    }
    cout << endl;
    return 0;
}
```

---

### 📝 Istilah Inggris:

|Bahasa Indonesia|Bahasa Inggris|
|---|---|
|Bilangan Prima|Prime Number|
|Faktorisasi Prima|Prime Factorization|
|Faktor|Factor|

---
<br/><br/><br/>
# 🧠 Konsep: Sieve of Eratosthenes

### Tujuan:

Menentukan **semua bilangan prima dari 1 hingga N** secara efisien.
### Ide Utama:

- Anggap semua bilangan dari 2 sampai N adalah **calon prima**.
- Tandai semua kelipatan dari setiap bilangan prima sebagai **bukan prima** (composite).
- Dimulai dari 2, lalu 3, 5, dan seterusnya hingga √N.

---

## 🪄 Ilustrasi Langkah:

Untuk N = 30:

1. Mulai dari 2, tandai semua kelipatan 2 (selain 2) → bukan prima.
2. Lanjut ke 3, tandai semua kelipatan 3 (selain 3) → bukan prima.
3. Lanjut ke 4 (sudah ditandai), skip.
4. Lanjut ke 5, tandai kelipatannya.
5. Berhenti di √30.

---

## 💻 Implementasi C++: Sieve of Eratosthenes

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    return isPrime;
}
```

---

## 🧪 Contoh Penggunaan:

```cpp
int main() {
    int n = 50;
    vector<bool> isPrime = sieve(n);

    cout << "Bilangan prima dari 1 sampai " << n << ":\n";
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) cout << i << " ";
    }
    cout << endl;

    return 0;
}
```

---

## ⏱ Kompleksitas Waktu:

- **O(n log log n)** — sangat cepat untuk n sampai 1e6 atau bahkan 1e7.
    

---

## 📝 Istilah Inggris:

|Bahasa Indonesia|Bahasa Inggris|
|---|---|
|Bilangan Prima|Prime Number|
|Saringan Eratosthenes|Sieve of Eratosthenes|
|Bukan prima|Composite number (non-prime)|
