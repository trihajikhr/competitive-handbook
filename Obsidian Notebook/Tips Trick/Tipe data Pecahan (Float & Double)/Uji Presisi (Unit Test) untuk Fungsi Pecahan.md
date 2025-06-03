---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Uji Presisi (Unit Test) untuk Fungsi Pecahan
sumber: Google.com, AI
tags:
  - float
  - tipe-data
  - double
---

---
# 🧪 Uji Presisi (Unit Test) untuk Fungsi Pecahan

Fungsi yang melibatkan tipe data `float`, `double`, atau `long double` perlu diuji secara hati-hati karena **ketidakakuratan representasi biner** dari angka pecahan. Unit test untuk fungsi pecahan **tidak bisa mengandalkan perbandingan $==$ secara langsung**.

---

## ⚠️ Mengapa Perlu Uji Presisi?

Contoh masalah:

```cpp
#include <iostream>
using namespace std;

int main() {
    double a = 0.1 + 0.2;
    double b = 0.3;

    if (a == b)
        cout << "Equal\n";
    else
        cout << "Not Equal\n";  // ❌ ini yang tercetak
}
````

> 🔍 `0.1 + 0.2` secara biner tidak sama persis dengan `0.3`

---

## ✅ Cara Benar: Menggunakan _Epsilon Comparison_

### Definisi:

Bandingkan dua nilai pecahan `a` dan `b` menggunakan toleransi kecil (`epsilon`):

```cpp
bool areAlmostEqual(double a, double b, double eps = 1e-9) {
    return fabs(a - b) < eps;
}
```

---

## 📦 Contoh Unit Test Sederhana (C++)

Misal kita menguji fungsi:

```cpp
double bagiDua(double x) {
    return x / 2.0;
}
```

### Tanpa Epsilon — Salah

```cpp
#include <cassert>
int main() {
    assert(bagiDua(0.3) == 0.15);  // ❌ bisa gagal
}
```

### Dengan Epsilon — Benar

```cpp
#include <cassert>
#include <cmath>

bool almostEqual(double a, double b, double eps = 1e-9) {
    return fabs(a - b) < eps;
}

int main() {
    assert(almostEqual(bagiDua(0.3), 0.15));  // ✅ aman
}
```

---

## 🧪 Contoh Framework: Google Test

Jika kamu menggunakan framework seperti [Google Test](https://github.com/google/googletest), gunakan makro `EXPECT_NEAR`:

```cpp
#include <gtest/gtest.h>

double akar(double x) {
    return sqrt(x);
}

TEST(FungsiPecahanTest, TestAkar) {
    EXPECT_NEAR(akar(2.0), 1.414213, 1e-6);
}
```

---

## 🔢 Kapan Gunakan Epsilon Lebih Kecil?

|Presisi Dibutuhkan Untuk|Nilai Epsilon|
|---|---|
|Hasil visualisasi grafik|`1e-4` ~ `1e-5`|
|Perhitungan akuntansi|`1e-6` ~ `1e-8`|
|Perhitungan ilmiah / fisika|`1e-9` ~ `1e-12`|
|Perhitungan kritis (misal GPS)|`1e-15` atau lebih|

---

## 🛡️ Tips Uji Presisi

- Gunakan `fabs(a - b) < eps` → stabil dan mudah dikontrol
    
- Jangan bandingkan $==$ langsung kecuali untuk `int`
    
- Selalu beri keterangan unit test yang gagal
    
- Dokumentasikan nilai epsilon yang kamu pilih
    
- Tambahkan beberapa test case dekat batas toleransi
    

---

## 📁 Contoh Uji Batch

```cpp
double square(double x) {
    return x * x;
}

void runTests() {
    assert(almostEqual(square(0.5), 0.25));
    assert(almostEqual(square(1.0), 1.0));
    assert(almostEqual(square(1.414213), 2.0, 1e-6));
    assert(almostEqual(square(-3.0), 9.0));
}
```

---

## ✨ Kesimpulan

- Unit test untuk fungsi pecahan **tidak boleh pakai $==$ secara langsung**
    
- Gunakan pendekatan epsilon: `fabs(a - b) < eps`
    
- Framework testing modern (seperti GoogleTest atau Catch2) sudah mendukung `EXPECT_NEAR`
    
- **Uji presisi penting agar programmu akurat, stabil, dan bebas bug tersembunyi**
    

> 💡 “Akurasi tidak hanya soal hasil — tapi juga cara membuktikan bahwa hasil itu dapat dipercaya.”

