---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Bahaya menggunakan float atau double sebagai indeks
sumber: Google.com, AI
tags:
  - tipe-data
  - float
  - double
---

---
# ⚠️ Bahaya Menggunakan `float` atau `double` sebagai Indeks atau dalam Struktur Data

Dalam pemrograman, tipe `float` atau `double` digunakan untuk menyimpan angka pecahan. Namun, **menggunakan tipe ini sebagai indeks array atau kunci struktur data seperti `map`, `set`, dan `unordered_map`** sangat **tidak disarankan** dan bisa menimbulkan **perilaku tak terduga atau bug tersembunyi**.

---

## 🚫 Jangan Gunakan Pecahan sebagai Indeks Array

```cpp
#include <iostream>
using namespace std;

int main() {
    double i = 2.7;
    int arr[10];
    arr[(int)i] = 42;

    cout << arr[2] << endl;  // Akan menampilkan 42
    return 0;
}
````

✅ Secara teknis ini **berhasil**, karena kita **mencasting float ke int** (`2.7` jadi `2`).  
❌ Tapi ini berbahaya jika kita **tidak sadar sedang menggunakan angka pecahan**, atau tidak mencastingnya dengan benar.

---

### ❗ Kesalahan Umum

```cpp
int arr[10];
double i = 2.7;

arr[i] = 42; // ❌ Mungkin kompile, tapi hasilnya tidak pasti
```

- **Error tersembunyi**: `i` adalah `double`, tapi digunakan sebagai indeks integer.
    
- Bisa kompile tergantung compiler (dengan implicit conversion), **namun rawan bug.**
    

---

## 🔥 Bahaya dalam Struktur Data STL

### Contoh: `std::map<double, int>`

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<double, string> m;
    m[0.1 + 0.2] = "Hello";
    cout << m[0.3] << endl; // ❌ Output: kosong!
    return 0;
}
```

📉 **Masalah**:

- `0.1 + 0.2 != 0.3` secara biner, jadi `m[0.3]` dan `m[0.1+0.2]` adalah **kunci yang berbeda!**
    
- Ini bisa membuat pencarian key salah, insert tak terduga, atau struktur data membengkak tanpa disadari.
    

---

## 💥 Di `unordered_map` Lebih Berbahaya Lagi

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<double, string> um;
    um[0.3] = "A";
    um[0.1 + 0.2] = "B";

    cout << um[0.3] << endl;         // A atau B?
    cout << um[0.1 + 0.2] << endl;   // B atau kosong?

    return 0;
}
```

🔍 Hasilnya bisa:

- Berbeda antara compiler.
    
- Berbeda antara arsitektur (32-bit vs 64-bit).
    
- Berubah jika optimisasi compiler diaktifkan.
    

---

## 👎 Ringkasan Bahaya

|Kasus|Akibat|
|---|---|
|Menggunakan float sebagai indeks array|Error pembulatan, akses memori salah, out-of-bounds|
|Menggunakan float sebagai key di map/set|Perbandingan tidak akurat → key tidak ditemukan|
|Menggunakan float di `unordered_map`|Hashing tidak stabil → tabrakan key, hasil aneh|
|Float sebagai penentu posisi (`pos[x]`)|Index tidak pasti, susah debug|

---

## ✅ Rekomendasi Aman

|Situasi|Solusi Aman|
|---|---|
|Indeks array, vector, atau loop|Gunakan `int`, `size_t`, `long long`|
|Key untuk struktur data map/set|Gunakan `int` jika mungkin|
|Butuh presisi tetap (misal uang)|Gunakan `int` sebagai fixed-point|
|Butuh komparasi float|Gunakan `epsilon`: `abs(a - b) < eps`|
|Butuh key real dengan aman|Gunakan pembulatan atau konversi string|

---

## 🧠 Contoh Teknik Aman: Menggunakan Pembulatan

```cpp
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main() {
    map<int, string> m;
    double f = 0.1 + 0.2;

    // Dibulatkan ke sen (jika f mewakili uang)
    int key = round(f * 100);

    m[key] = "Hello";

    cout << m[round(0.3 * 100)] << endl; // ✅ Hello
    return 0;
}
```

---

## ✨ Kesimpulan

- Floating-point **tidak akurat secara biner** → jangan digunakan sebagai indeks atau key!
    
- Gunakan tipe data `int` atau `long long` yang **stabil, deterministik, dan presisi**.
    
- Jika tetap butuh key pecahan, lakukan **pembulatan eksplisit** dan dokumentasikan konversinya.
    

> 💡 **"Jika kamu harus menggunakan angka pecahan sebagai identitas, pastikan kamu mengendalikannya — bukan membiarkannya mengejutkanmu."**
