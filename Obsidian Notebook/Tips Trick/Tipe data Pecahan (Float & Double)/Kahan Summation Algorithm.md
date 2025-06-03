---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Kahan Summation Algorithm
sumber: Google.com, AI
tags:
  - tipe-data
  - float
  - double
---

---
# 🧠 Kahan Summation Algorithm: Menangani Error Pembulatan dalam Float/Double

## 📌 Apa Itu Kahan Summation?

**Kahan Summation Algorithm** (juga dikenal sebagai *Compensated Summation*) adalah algoritma numerik yang dirancang untuk **mengurangi error pembulatan (round-off error)** saat menjumlahkan banyak angka pecahan (`float`, `double`, dll).

Biasanya, dalam penjumlahan biasa, error kecil yang muncul karena pembulatan bisa **tertumpuk (akumulatif)**, terutama saat menjumlahkan banyak angka kecil atau angka yang sangat bervariasi nilainya.

Kahan Summation **mengompensasi kesalahan pembulatan di setiap langkah penjumlahan**, sehingga hasil akhirnya jauh lebih akurat.

---

## 🤔 Kenapa Kahan Summation Dibutuhkan?

Misalkan kita punya banyak angka kecil, misalnya `0.000001`, dan kita jumlahkan satu juta kali:

### Penjumlahan biasa:
```cpp
double sum = 0.0;
for (int i = 0; i < 1000000; ++i) {
    sum += 0.000001;
}
````

📉 **Masalah:** Nilai `sum` bisa jadi tidak tepat, misalnya `0.999999999999996` karena **error pembulatan yang terus bertambah**.

---

## 🛠️ Solusi: Algoritma Kahan

```cpp
double sum = 0.0;
double c = 0.0; // kompensasi untuk error

for (int i = 0; i < n; ++i) {
    double y = input[i] - c;
    double t = sum + y;
    c = (t - sum) - y;
    sum = t;
}
```

### Penjelasan Langkah:

|Variabel|Fungsi|
|---|---|
|`sum`|Menyimpan hasil penjumlahan sejauh ini|
|`c`|Menyimpan kompensasi (error yang “hilang” di langkah sebelumnya)|
|`y`|Nilai yang sudah dikoreksi terhadap error sebelumnya|
|`t`|Nilai sementara dari `sum + y`, yang akan dijadikan `sum` baru|

📌 Inti dari algoritma ini: **menjaga supaya error pembulatan tidak lenyap, melainkan disimpan dan dikoreksi pada langkah selanjutnya**.

---

## 💡 Contoh Lengkap

```cpp
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    vector<double> input(1000000, 0.000001);

    // Penjumlahan biasa
    double normal_sum = 0.0;
    for (double x : input) {
        normal_sum += x;
    }

    // Kahan Summation
    double kahan_sum = 0.0;
    double c = 0.0;
    for (double x : input) {
        double y = x - c;
        double t = kahan_sum + y;
        c = (t - kahan_sum) - y;
        kahan_sum = t;
    }

    cout << fixed << setprecision(15);
    cout << "Normal sum : " << normal_sum << endl;
    cout << "Kahan sum  : " << kahan_sum << endl;
    return 0;
}
```

### 🧪 Output yang Mungkin:

```
Normal sum : 0.999999999999996
Kahan sum  : 1.000000000000000
```

🎯 **Kahan menghasilkan hasil yang lebih akurat**!

---

## ⚖️ Kapan Menggunakan Kahan Summation?

|Situasi|Gunakan Kahan?|
|---|---|
|Menjumlahkan angka kecil dalam jumlah besar|✅ Ya|
|Akurasi sangat penting (keuangan, statistik, simulasi ilmiah)|✅ Ya|
|Data besar dan heterogen|✅ Ya|
|Program real-time sederhana|❌ Mungkin tidak perlu|

---

## ⛔ Keterbatasan Kahan Summation

- Tidak sepenuhnya menghilangkan semua error, hanya **menguranginya secara signifikan**.
    
- Bisa lebih **lambat** dibanding penjumlahan biasa karena ada operasi tambahan.
    
- Tidak cocok digunakan dalam GPU atau SIMD (Single Instruction Multiple Data) karena bersifat sekuensial.
    

---

## 🧠 Kesimpulan

Kahan Summation adalah teknik penting dalam pemrograman numerik:

- ✅ Mengurangi akumulasi error pembulatan saat menjumlahkan angka pecahan.
    
- ✅ Cocok untuk data yang sangat banyak atau aplikasi numerik yang presisi tinggi.
    
- ⚠️ Perlu ekstra pemrosesan, namun hasilnya jauh lebih akurat.
    

> 📌 "Kahan Summation adalah contoh klasik bagaimana sedikit kompensasi bisa menyelamatkan akurasi perhitungan."

