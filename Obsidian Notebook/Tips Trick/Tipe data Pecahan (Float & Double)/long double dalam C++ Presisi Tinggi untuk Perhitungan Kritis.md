---
obsidianUIMode: preview
note_type: tips trick
tips_trick: long double dalam C++ Presisi Tinggi untuk Perhitungan Kritis
sumber: Google.com, AI
tags:
  - tipe-data
  - float
  - double
---

---

# 🔍 `long double` dalam C++: Presisi Tinggi untuk Perhitungan Kritis

`long double` adalah tipe data pecahan (`floating-point`) dengan presisi **lebih tinggi** dari `double`. Walau jarang digunakan, tipe ini sangat berguna untuk perhitungan yang **sangat sensitif terhadap presisi**, seperti simulasi ilmiah atau numerik presisi tinggi.

---

## 📊 Perbandingan Tipe Pecahan

| Tipe         | Ukuran (byte) | Presisi Desimal | Format Biner (IEEE)     |
|--------------|----------------|------------------|--------------------------|
| `float`      | 4              | ~7 digit         | IEEE 754 single (32 bit) |
| `double`     | 8              | ~15–16 digit     | IEEE 754 double (64 bit) |
| `long double`| 10, 12, 16*     | ~18–21 digit+    | Extended precision / platform dependent |

> ⚠️ Ukuran `long double` tergantung **sistem operasi** dan **compiler**:
> - GCC Linux: biasanya 16 byte (80-bit extended precision).
> - Windows MSVC: biasanya **sama seperti `double`** (tidak ada peningkatan presisi).

---

## 🧪 Contoh Presisi Lebih Tinggi

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float f = 1.123456789123456789L;
    double d = 1.123456789123456789L;
    long double ld = 1.123456789123456789L;

    cout << fixed << setprecision(20);
    cout << "float       : " << f << endl;
    cout << "double      : " << d << endl;
    cout << "long double : " << ld << endl;
    return 0;
}
````

**Output (di sistem Linux GCC):**

```
float       : 1.12345683574676513672
double      : 1.12345678912345679012
long double : 1.12345678912345678912  ← paling akurat
```

---

## ⚙️ Sintaks Literal `long double`

- Tambahkan huruf **`L` atau `l`** di akhir literal desimal:
    

```cpp
long double pi = 3.141592653589793238L;
```

---

## 📌 Kapan Gunakan `long double`?

✅ Gunakan ketika:

- Kamu sedang mengerjakan **perhitungan ilmiah yang sangat sensitif terhadap presisi**.
    
- Membuat **aplikasi numerik presisi tinggi** (misalnya kalkulasi diferensial, integral, permodelan fisik).
    
- Ingin mengurangi efek **akumulasi kesalahan pembulatan** pada banyak iterasi.
    

❌ Jangan gunakan jika:

- Kamu bekerja di Windows dengan compiler yang tidak mendukung `long double` dengan benar.
    
- Tidak ada kebutuhan presisi ekstrem — `double` sudah sangat memadai.
    

---

## 🛠️ Cara Mengecek Ukuran `long double` di Sistemmu

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Ukuran long double: " << sizeof(long double) << " byte" << endl;
    return 0;
}
```

Outputnya mungkin seperti ini:

```
Ukuran long double: 16 byte
```

---

## 🧠 Tips Penting

- Gunakan **`setprecision()`** saat mencetak hasil untuk benar-benar melihat perbedaan presisi.
    
- Jangan membandingkan `long double` secara langsung:
    

```cpp
const long double EPS = 1e-12L;
if (fabsl(a - b) < EPS) {
    cout << "Nilai mendekati sama.";
}
```

Gunakan `fabsl()` untuk versi `long double` dari `abs()`.

> Untuk penjelasan lebih lengkap, lihat [[Penggunaan Tepat Long Double dalam C++]]

---

## 🧾 Kesimpulan

|Tipe|Presisi|Ukuran (umum)|Cocok untuk...|
|---|---|---|---|
|`float`|Rendah|4 byte|Grafik ringan, game, IoT|
|`double`|Tinggi|8 byte|Default untuk presisi umum|
|`long double`|Sangat tinggi|10–16 byte|Simulasi, sains, numerik kritis|

---

## 📚 Referensi

- cppreference.com: [long double cppreference](https://en.cppreference.com/w/cpp/language/types)
    
- IEEE Floating Point Arithmetic
    
- GCC & Clang documentation on extended precision
    

---

> 💬 "Pilih `long double` jika dunia angka tidak bisa mentoleransi kesalahan sekecil apa pun."
