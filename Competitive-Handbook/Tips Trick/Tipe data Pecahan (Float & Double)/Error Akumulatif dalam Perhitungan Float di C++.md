---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Error Akumulatif dalam Perhitungan Float di C++
sumber: Google.com, AI
tags:
  - tipe-data
  - float
  - double
---

---
# 🧮 Error Akumulatif dalam Perhitungan Float di C++

## 📌 Apa Itu Error Akumulatif?

Error akumulatif (cumulative error) adalah kesalahan yang **terkumpul atau bertambah sedikit demi sedikit** saat kita melakukan banyak operasi aritmetika menggunakan tipe data pecahan seperti `float` atau `double`.

Kesalahan ini muncul karena **representasi angka pecahan dalam komputer tidak selalu akurat** secara biner. Akibatnya, setiap operasi bisa menyimpan sedikit kesalahan pembulatan, dan jika dilakukan berulang-ulang, kesalahan tersebut bisa **menumpuk dan menghasilkan hasil akhir yang salah** secara signifikan.

---

## ⚠️ Kenapa Bisa Terjadi?

- `float` dan `double` hanya dapat menyimpan **angka dengan jumlah digit terbatas** (7-8 digit untuk `float`, 15-16 untuk `double`).
- Banyak angka desimal **tidak bisa direpresentasikan secara sempurna** dalam format biner (contoh: 0.1, 0.2, 0.3).
- Operasi seperti penjumlahan atau pengurangan terhadap angka-angka sangat kecil atau sangat besar dapat menyebabkan **loss of significance** atau **round-off error**.

---

## 🔬 Contoh: Penjumlahan Float yang Tidak Akurat

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float sum = 0.0f;
    for (int i = 0; i < 1000000; ++i) {
        sum += 0.000001f;
    }

    cout << fixed << setprecision(10);
    cout << "Hasil: " << sum << endl;

    return 0;
}
````

### 🎯 Ekspektasi:

Kita menjumlahkan `0.000001` sebanyak satu juta kali, seharusnya hasilnya adalah `1.000000`.

### ❌ Kenyataan:

Output bisa jadi seperti:

```
Hasil: 0.9999998808
```

> Hasilnya sedikit meleset karena **error pembulatan yang menumpuk** di setiap iterasi.

---

## 🧪 Contoh pada Double (Lebih Akurat tapi Tetap Terbatas)

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double sum = 0.0;
    for (int i = 0; i < 1000000; ++i) {
        sum += 0.000001;
    }

    cout << fixed << setprecision(15);
    cout << "Hasil: " << sum << endl;

    return 0;
}
```

### 🔍 Hasil:

```
Hasil: 0.999999999999996
```

> Masih lebih baik dari `float`, tapi **tetap tidak presisi sempurna**.

---

## ⚙️ Dampak Error Akumulatif

|Operasi|Risiko Error Akumulatif?|Penjelasan|
|---|---|---|
|Penjumlahan angka kecil|Tinggi|Angka kecil seringkali "hilang" saat dijumlahkan ke angka besar.|
|Perkalian dalam loop besar|Sedang|Bisa menumpuk jika dilakukan dalam jumlah besar.|
|Operasi kombinasi besar-kecil|Tinggi|`big + small` bisa membuat angka kecil diabaikan.|
|Pembulatan berulang|Tinggi|Bisa mengubah hasil akhir secara signifikan.|

---

## ✅ Cara Mengurangi Error Akumulatif

### 1. Gunakan `double` atau `long double`

```cpp
long double total = 0.0L;
```

Lebih presisi dari `float`, terutama pada sistem yang mendukungnya.

### 2. Gunakan metode **Kahan Summation Algorithm**

```cpp
double sum = 0.0;
double c = 0.0;  // kompensasi

for (int i = 0; i < n; ++i) {
    double y = input[i] - c;
    double t = sum + y;
    c = (t - sum) - y;
    sum = t;
}
```

> Teknik ini menyimpan kesalahan pembulatan dan memperbaikinya saat penjumlahan berikutnya.

### 3. Urutkan penjumlahan dari **angka terkecil ke terbesar**

#### 🧠 Penjelasan:

Dalam floating-point arithmetic, **angka kecil bisa kehilangan presisinya** saat dijumlahkan langsung dengan angka besar. Hal ini disebabkan oleh cara komputer menyimpan angka dalam format biner: bit-bit dari angka kecil bisa saja diabaikan karena tidak cukup "ruang" untuk menyimpannya saat ditambahkan ke angka yang jauh lebih besar.

Dengan **menjumlahkan dari angka terkecil ke terbesar**, kita memastikan bahwa angka kecil masih dihitung secara akurat sebelum mereka “tertutup” oleh angka besar.

---

#### 📉 Ilustrasi Kesalahan

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<double> numbers = {1e8, 1.0, 1.0, 1.0, 1.0};

    // Penjumlahan dari besar ke kecil
    double sum1 = 0.0;
    for (double x : numbers)
        sum1 += x;

    // Urutkan dari kecil ke besar
    sort(numbers.begin(), numbers.end());

    // Penjumlahan dari kecil ke besar
    double sum2 = 0.0;
    for (double x : numbers)
        sum2 += x;

    cout.precision(17);
    cout << "Tanpa urutan   : " << sum1 << endl;
    cout << "Dengan urutan  : " << sum2 << endl;

    return 0;
}
```

---

#### 📌 Output (simulasi):

```
Tanpa urutan   : 100000004.00000000
Dengan urutan  : 100000004.00000001
```

> Selisihnya **kecil tapi nyata**, terutama saat angka-angka kecil dijumlahkan ke angka yang sangat besar.

---

#### 🔧 Catatan Tambahan:

- Strategi ini sangat efektif bila:
    
    - Kamu menjumlahkan **ribuan atau jutaan angka**.
        
    - Nilai-nilainya memiliki **rentang sangat lebar** (ada angka sangat kecil dan sangat besar).
        
- Teknik ini **mudah diimplementasikan** dan **meningkatkan akurasi** secara signifikan dalam akumulasi numerik.
    
### 4. Hindari perbandingan $==$ pada hasil akumulasi

Gunakan toleransi (`epsilon`) saat membandingkan:

```cpp
if (fabs(a - b) < 1e-9) { ... }
```

---

## 🧠 Catatan Tambahan

- Gunakan `std::accumulate` (dari `<numeric>`) dengan hati-hati. Ia melakukan penjumlahan biasa dan tetap bisa menyebabkan akumulasi error.
    
- Dalam aplikasi numerik kritis (simulasi fisika, keuangan, dll), selalu rancang strategi untuk **mengendalikan error**.
    

---

## 📌 Kesimpulan

Error akumulatif adalah **keniscayaan** dalam perhitungan floating-point. Namun, kita bisa **meminimalkan dampaknya** dengan:

- Memilih tipe data yang lebih presisi (`double`, `long double`).
    
- Menggunakan algoritma akumulasi yang stabil.
    
- Memahami sifat floating-point dan tidak membandingkan secara langsung hasil yang bisa terpengaruh error.
    

> 💬 "Kesalahan kecil yang dibiarkan terus-menerus bisa menghasilkan keputusan yang salah besar."

