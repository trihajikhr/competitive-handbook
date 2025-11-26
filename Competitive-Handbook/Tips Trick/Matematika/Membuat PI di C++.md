---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Membuat PI
sumber: Google.com, AI
tags:
  - math
---
#math 

---
# Membuat PI di C++

File ini mencatat berbagai metode komputasional untuk mendapatkan nilai π (pi) dalam bahasa C++. Beberapa metode berasal dari pustaka standar, sementara yang lain menggunakan pendekatan numerik atau konstanta dari pustaka eksternal.


---
## 📌 1. Menggunakan `atan(1) * 4` dari `<cmath>`

### Penjelasan:
Fungsi `atan(1)` mengembalikan nilai arcus tangen dari 1 dalam radian, yang secara matematis bernilai π/4. Maka, untuk mendapatkan π, kita kalikan dengan 4.

### Contoh kode:
```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double pi = atan(1) * 4;
    cout << pi << endl;
    return 0;
}
````

### Penjelasan kode:

- `#include <cmath>`: untuk menggunakan fungsi `atan()`.
    
- `atan(1)`: mengembalikan π/4.
    
- `pi = atan(1) * 4`: hasil akhir mendekati 3.14159...
    

---

## 📌 2. Menggunakan konstanta `M_PI` (GNU/Compiler-specific)

### Penjelasan:

`M_PI` adalah konstanta yang tersedia di banyak compiler (non-standar). Nilainya mendekati π.

### Contoh kode:

```cpp
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    double pi = M_PI;
    cout << pi << endl;
    return 0;
}
```

### Penjelasan kode:

- `#define _USE_MATH_DEFINES`: diperlukan agar konstanta `M_PI` dikenali (khususnya di MSVC).
    
- `M_PI`: konstanta dengan nilai π.
    
- Cocok jika kamu tidak keberatan dengan dependensi non-standar.
    

---

## 📌 3. Menggunakan `std::numbers::pi` dari C++20

### Penjelasan:

Mulai C++20, konstanta `pi` tersedia langsung dari header `<numbers>`.

### Contoh kode:

```cpp
#include <iostream>
#include <numbers>
using namespace std;

int main() {
    double pi = std::numbers::pi;
    cout << pi << endl;
    return 0;
}
```

### Penjelasan kode:

- `#include <numbers>`: menyediakan konstanta matematika seperti π.
    
- `std::numbers::pi`: konstanta standar tipe `double` dengan presisi tinggi.
    
- Ini adalah cara **paling modern dan standar** untuk mendapatkan nilai π di C++20 ke atas.
    

---

## 📌 4. Menggunakan Deret Gregory-Leibniz

### Penjelasan:

Deret tak hingga:

$$\pi = 4 \left(1 - \frac{1}{3} + \frac{1}{5} - \frac{1}{7} + \cdots \right)$$

Metode ini lambat konvergensinya, tetapi berguna untuk demonstrasi numerik.

### Contoh kode:

```cpp
#include <iostream>
using namespace std;

int main() {
    double pi = 0.0;
    int terms = 1000000; // jumlah suku deret

    for (int i = 0; i < terms; ++i) {
        double term = 1.0 / (2 * i + 1);
        if (i % 2 == 0)
            pi += term;
        else
            pi -= term;
    }

    pi *= 4;
    cout << pi << endl;
    return 0;
}
```

### Penjelasan kode:

- Deret dihitung sebanyak `1_000_000` suku.
    
- Alternatif antara positif dan negatif berdasarkan indeks `i`.
    
- Hasilnya semakin mendekati π saat `terms` diperbesar.
    

---

## 📌 5. Menggunakan Boost `boost ::math::constants::pi`

### Penjelasan:

Boost menyediakan konstanta matematika standar, termasuk π dengan berbagai tipe numerik (`float`, `double`, `long double`).

### Contoh kode:

```cpp
#include <iostream>
#include <boost/math/constants/constants.hpp>
using namespace std;

int main() {
    double pi = boost::math::constants::pi<double>();
    cout << pi << endl;
    return 0;
}
```

### Penjelasan kode:

- `boost::math::constants::pi<double>()` memberikan nilai π dalam presisi `double`.
    
- Pastikan Boost sudah terinstal dan dikonfigurasi dalam project.
    

---

## 📌 6. Menyimpan Nilai Pi ke String dengan Presisi Tinggi

### Penjelasan:

Kadang kita perlu menyimpan π dalam bentuk `string` dengan banyak digit presisi (misalnya untuk tampilan, ekspor, atau komputasi presisi tinggi).

### Contoh kode:

```cpp
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double pi = atan(1) * 4;
    ostringstream out;

    out << fixed << setprecision(30) << pi;
    string pi_str = out.str();

    cout << "Pi: " << pi_str << endl;
    return 0;
}
```

### Penjelasan kode:

- `ostringstream`: untuk membuat stream yang menulis ke string.
    
- `setprecision(30)`: mengatur jumlah digit desimal.
    
- `fixed`: menampilkan angka dalam format desimal tetap, bukan scientific.
    
- `pi_str = out.str()`: menyimpan hasil stream sebagai `string`.
    

---

## 💡 Kesimpulan

| Metode                      | Akurasi          | Portabilitas  | Kecepatan | Keterangan              |
| --------------------------- | ---------------- | ------------- | --------- | ----------------------- |
| `atan(1) * 4`               | Tinggi           | ✅ Standar     | Cepat     | Aman dan portable       |
| `M_PI`                      | Tinggi           | ❌ Non-standar | Cepat     | Tergantung compiler     |
| `std::numbers::pi` (C++20)  | Tinggi           | ✅ Modern      | Cepat     | Butuh C++20             |
| Gregory-Leibniz             | Bertahap         | ✅ bagus       | Lambat    | Edukatif                |
| Boost                       | Tinggi           | ❌ Perlu Boost | Cepat     | Perlu pustaka eksternal |
| `ostringstream + precision` | Presisi tampilan | ✅ bagus       | Sedang    | Cocok untuk output      |

