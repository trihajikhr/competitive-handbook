---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Perbandingan Stabil untuk Sorting Angka Pecahan
sumber: Google.com, AI
tags:
  - tipe-data
  - sorting
  - float
  - double
---

---
# 🔄 Perbandingan Stabil untuk Sorting Angka Pecahan (`float`, `double`, `long double`)

Sorting (pengurutan) angka pecahan seperti `float`, `double`, atau `long double` **memiliki tantangan tersendiri** karena sifat floating-point yang tidak selalu presisi. Oleh karena itu, penting untuk memahami **cara membandingkan angka pecahan secara stabil**, terutama jika kamu ingin mendapatkan hasil sorting yang **akurat dan konsisten**.

---

## ⚠️ Masalah Umum saat Sorting Floating Point

- Angka seperti `0.1 + 0.2` tidak persis sama dengan `0.3`.
- Operasi aritmatika dapat menghasilkan **kesalahan pembulatan (rounding error)**.
- Perbandingan langsung (`a < b`, `a == b`) bisa gagal jika angka sangat dekat.

---

## 🧪 Contoh: Kesalahan Perbandingan Sederhana

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<double> v = {0.1 + 0.2, 0.3};

    sort(v.begin(), v.end());

    for (double x : v)
        cout << x << ' ';
}
````

### Output:

```
0.3 0.3
```

Secara logika kita mengira `0.1 + 0.2 != 0.3`, tetapi di sini terlihat **identik**, karena kesalahan pembulatan tidak terlihat saat dicetak. Namun **di memori** keduanya tetap berbeda.

---

## ✅ Solusi: Gunakan Fungsi Comparator Stabil dengan EPSILON

Gunakan fungsi pembanding kustom yang mempertimbangkan **toleransi kesalahan (epsilon)**:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const double EPS = 1e-9;

bool compare_stable(double a, double b) {
    if (fabs(a - b) < EPS) return false; // anggap sama → stabil
    return a < b;
}

int main() {
    vector<double> v = {0.1 + 0.2, 0.3, 0.3000000000001};

    sort(v.begin(), v.end(), compare_stable);

    for (double x : v)
        cout << fixed << x << ' ';
}
```

### Penjelasan:

- `fabs(a - b) < EPS`: jika selisih sangat kecil, dianggap **sama**.
    
- Menghindari "flip-flop" saat sorting nilai-nilai yang hampir sama → **urutan stabil**.
    

---

## 🧠 Kenapa Perbandingan Stabil Itu Penting?

|Masalah Umum|Dampak|
|---|---|
|Nilai-nilai sangat dekat dianggap tidak sama|Urutan hasil sort bisa tidak konsisten|
|Kesalahan pembulatan|Urutan bisa berubah tergantung compiler/hardware|
|Tidak pakai epsilon|Bisa menghasilkan hasil sort yang tidak deterministik|
|Sort dengan comparator biasa|Bisa menyebabkan flip-flop antara dua angka yang mendekati|

---

## 📦 Versi untuk `float` dan `long double`

Ganti `double` dan `fabs` dengan:

|Tipe|Fungsi abs|EPS yang Disarankan|
|---|---|---|
|`float`|`fabsf(a - b)`|`1e-6f`|
|`double`|`fabs(a - b)`|`1e-9`|
|`long double`|`fabsl(a - b)`|`1e-12L`|

Contoh versi `long double`:

```cpp
bool compare_ld(long double a, long double b) {
    return (fabsl(a - b) < 1e-12L) ? false : a < b;
}
```

---

## 📌 Kesimpulan

- Perbandingan langsung angka pecahan ($<$, $==$) **tidak aman** untuk kasus-kasus sensitif seperti sorting.
    
- Gunakan **fungsi pembanding stabil** yang mempertimbangkan `epsilon`.
    
- **Gunakan `fabsl`, `fabs`, atau `fabsf`** tergantung tipe data.
    
- Hasil sort yang akurat dan deterministik = program yang lebih bisa dipercaya.
    

---

> 💡 "Stabilitas dalam sorting angka pecahan bukan soal cepat, tapi soal kepercayaan pada hasil yang tidak berubah-ubah."
