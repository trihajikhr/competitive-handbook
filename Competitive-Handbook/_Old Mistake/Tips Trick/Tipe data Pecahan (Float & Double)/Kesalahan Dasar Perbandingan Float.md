---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Kesalahan Dasar Perbandingan Float
sumber: Google.com, AI
tags:
  - float
  - double
  - tipe-data
---

---
# ⚠️ Kesalahan Umum Saat Membandingkan Float dalam Pemrograman

Perbandingan `float` atau `double` bukanlah hal yang sederhana seperti pada tipe data `int`. Banyak programmer pemula (dan bahkan menengah) terjebak dalam kesalahan yang menyebabkan bug tersembunyi.

---

## 📌 Masalah Utama: Representasi Pecahan dalam Biner

Tipe `float` dan `double` menyimpan nilai **dalam bentuk biner**, dan **tidak semua angka desimal bisa direpresentasikan secara presisi**.

Contoh:

```cpp
#include <iostream>
using namespace std;

int main() {
    double a = 0.1 + 0.2;
    double b = 0.3;

    if (a == b) cout << "Sama";
    else cout << "Tidak sama";  // Output: Tidak sama
}
````

> 🧠 Walaupun `0.1 + 0.2` secara matematis = `0.3`, dalam komputer mereka **tidak persis sama** secara biner.

---

## ❌ Kesalahan Umum

### 1. Menggunakan $==$ Secara Langsung

```cpp
float x = 0.7f;
if (x == 0.7) {
    // Bug bisa terjadi di sini
}
```

> ⚠️ Salah satu dari dua nilai mungkin **tidak dapat direpresentasikan** secara presisi.

---

### 2. Mengabaikan Ketelitian dalam Perhitungan Bertingkat

```cpp
double a = 1.0 / 3.0;
double b = a * 3.0;

if (b == 1.0)
    cout << "Benar";   // Tidak dijamin selalu benar
```

> Akumulasi error floating point bisa menyebabkan hasil tidak 100% akurat.

---

### 3. Tidak Menggunakan Toleransi (Epsilon)

Perbandingan float sebaiknya **menggunakan toleransi kecil**, misalnya:

```cpp
bool areEqual(double a, double b, double eps = 1e-9) {
    return fabs(a - b) < eps;
}
```

> ✅ Ini adalah **cara yang benar** dan stabil secara numerik.

---

### 4. Menggunakan Float sebagai Indeks atau Hash Key

```cpp
map<float, int> m;
m[0.1f + 0.2f] = 1;
```

> ⚠️ Hasilnya bisa tidak terprediksi. Lebih baik gunakan `int` atau `string` jika memungkinkan.

---

### 5. Menganggap Float Cocok untuk Keuangan

```cpp
float saldo = 1e9;
saldo -= 0.1f;
```

> ❌ Float dan double tidak cocok untuk perhitungan uang. Gunakan **fixed-point** atau **integer dengan skala** (mis. dalam satuan sen).

---

## ✅ Cara Benar Membandingkan Float

### Fungsi General:

```cpp
bool almostEqual(double a, double b, double eps = 1e-9) {
    return fabs(a - b) < eps;
}
```

### Contoh Penggunaan:

```cpp
if (almostEqual(0.1 + 0.2, 0.3)) {
    cout << "Nilai hampir sama!";
}
```

---

## 🧠 Tips Tambahan

|Situasi|Rekomendasi|
|---|---|
|Perbandingan float/double|Gunakan epsilon (toleransi)|
|Loop dengan kenaikan pecahan|Jangan andalkan `a == target`|
|Uji float dalam unit test|Gunakan `EXPECT_NEAR` atau `assert(almostEqual(...))`|
|Hitungan uang/uang digital|Hindari float/double, pakai integer atau fixed-point|

---

## ✨ Kesimpulan

- `float` dan `double` **tidak boleh dibandingkan langsung dengan $==$**
    
- Selalu gunakan pendekatan **epsilon (toleransi)** untuk menghindari bug numerik
    
- Hindari penggunaan `float` dalam konteks penting seperti indeks array, struktur data, atau sistem keuangan
    
- Uji fungsi yang menggunakan `float` secara ketat dengan test toleransi presisi
    

> 💡 “Jangan percaya bahwa `a == b` hanya karena kelihatannya sama di layar.”
