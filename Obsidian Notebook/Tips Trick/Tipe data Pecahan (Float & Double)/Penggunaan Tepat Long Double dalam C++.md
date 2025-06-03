---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Penggunaan Long Double dalam C++
sumber: Google.com, AI
tags:
  - tipe-data
  - float
  - double
---

---

# 🎯 Penggunaan `long double` yang Tepat dan Tidak Tepat

Tipe data `long double` dalam C++ digunakan untuk kasus-kasus yang membutuhkan **presisi pecahan sangat tinggi**. Namun, untuk bisa memanfaatkannya dengan baik, kita harus memahami **kapan** dan **bagaimana** menggunakannya secara **benar**. Kesalahan dalam penggunaannya bisa menyebabkan **tidak ada perbedaan** dibandingkan `double`, atau bahkan membuat program kita **tidak efisien**.

---

## 🚫 Contoh Penggunaan yang Tidak Tepat

```cpp
#include <iostream>
using namespace std;

int main() {
    long double a = 0.1 + 0.2;
    long double b = 0.3;

    if (a == b)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
````

### ❌ Kenapa Ini Tidak Tepat?

- Walaupun kita pakai `long double`, kita tetap melakukan perbandingan $==$.
    
- Karena bilangan pecahan **tidak bisa disimpan dengan presisi sempurna**, perbandingan $==$ sering gagal.
    
- `0.1 + 0.2` secara biner tidak sama persis dengan `0.3`, bahkan dalam `double` maupun `long double`.
    

---

## ✅ Contoh Penggunaan yang Tepat

```cpp
#include <iostream>
#include <cmath>  // untuk fabsl
using namespace std;

int main() {
    long double a = 0.1L + 0.2L;
    long double b = 0.3L;

    const long double EPS = 1e-12L; // toleransi error

    if (fabsl(a - b) < EPS)
        cout << "Nilai hampir sama (presisi tinggi)";
    else
        cout << "Berbeda";

    return 0;
}
```

### ✅ Kenapa Ini Tepat?

- Menggunakan **literal `L`** agar angka `0.1`, `0.2`, dan `0.3` benar-benar bertipe `long double`.
    
- Menggunakan **`fabsl()`**, fungsi `abs()` khusus untuk `long double`.
    
- Menggunakan perbandingan dengan **toleransi (`epsilon`)** untuk memperhitungkan kesalahan pembulatan kecil.
    

---

## 🔍 Eksperimen Perbandingan Presisi

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
```

### Hasil (di sistem GCC/Linux 64-bit):

```
float       : 1.12345683574676513672
double      : 1.12345678912345679012
long double : 1.12345678912345678912
```

Kita bisa melihat:

- **`float`** kehilangan banyak digit desimal.
    
- **`double`** lebih presisi.
    
- **`long double`** mempertahankan lebih banyak digit presisi.
    

---

## 🧠 Inti Pemahaman

|Kasus|Tidak Tepat|Tepat|
|---|---|---|
|Gunakan literal|`long double a = 0.1 + 0.2;`|`long double a = 0.1L + 0.2L;`|
|Bandingkan nilai pecahan|`if (a == b)`|`if (fabsl(a - b) < EPS)`|
|Tampilkan nilai|Tanpa `setprecision()` → hasil terlihat sama|Gunakan `setprecision(20)` agar perbedaan terlihat|
|Sistem tidak mendukung `long double`|Tetap tulis `long double`, tapi hasil sama dengan `double`|Gunakan hanya jika sistem & compiler benar-benar mendukung|

---

## 📎 Kesimpulan

- Gunakan `long double` jika kamu **benar-benar butuh** presisi ekstra.
    
- Selalu **gunakan literal `L`** untuk memastikan angka ditafsirkan sebagai `long double`.
    
- Jangan **bandingkan langsung** angka pecahan, gunakan **epsilon tolerance** dan fungsi `fabsl()` untuk presisi tinggi.
    
- **Cek ukuran `long double` di sistemmu**: tidak semua compiler mendukung ukuran lebih dari `double`.
    

```cpp
cout << sizeof(long double) << " byte" << endl;
```

---

> 🔬 **Presisi tinggi tanpa cara yang benar = presisi yang sia-sia.** Pelajari tools-nya, pahami konteksnya, baru gunakan `long double` dengan bijak.

