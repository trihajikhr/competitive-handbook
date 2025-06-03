---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Mencari nilai Max dari kumpulan tipe data Double atau Float
sumber: Google.com, AI
tags:
  - math
  - float
  - double
---

---
# Mencari nilai Max dari kumpulan tipe data Double atau Float
Mengelola **akurasi perbandingan nilai float/double** adalah hal **krusial** di dunia nyata (finance, science, machine learning) maupun di kontes programming. Karena float/double itu **bukan eksak**, kita tidak bisa asal membandingkan langsung seperti int.

## 📌 Pentingnya Mengetahui Cara yang Tepat Mencari Nilai Maksimum dari `float` atau `double`

Dalam pemrograman, pencarian nilai maksimum adalah salah satu operasi dasar yang sangat sering digunakan — baik itu dalam pengolahan data, analisis statistik, perhitungan ilmiah, maupun dalam konteks kompetisi pemrograman. Namun, ketika tipe data yang digunakan adalah **`float` atau `double`**, pencarian nilai maksimum menjadi lebih kompleks dibandingkan dengan tipe data bilangan bulat (`int`).

### ❗ Masalah Utama: Ketidakakuratan Float

Tipe `float` dan `double` direpresentasikan dalam bentuk **presisi terbatas (floating-point binary)**, yang artinya **tidak semua angka bisa direpresentasikan secara eksak di dalam memori**. Ini bisa menimbulkan kesalahan pembulatan yang sangat kecil — tetapi cukup untuk membuat hasil perbandingan menjadi tidak akurat jika kita tidak hati-hati.

Contohnya:

```cpp
double a = 0.1 + 0.2;
double b = 0.3;
if (a == b) {
    // Mungkin hasilnya false! (padahal secara matematis harusnya true)
}
```

Inilah sebabnya **kita tidak boleh membandingkan nilai float/double secara langsung dengan operator $==$, $<$, atau $>$ tanpa pertimbangan tambahan seperti toleransi kesalahan (epsilon).**

---

### 🎯 Mengapa Ini Penting Saat Mencari Maksimum?

Ketika kita mencari nilai maksimum dari kumpulan `float` atau `double`, kita biasanya melakukan serangkaian perbandingan:

```cpp
if (x > maks) maks = x;
```

Namun, jika nilai `x` sangat dekat dengan `maks`, kesalahan pembulatan bisa menyebabkan perbandingan ini **gagal mengenali bahwa `x` sebenarnya lebih besar**, atau sebaliknya. Akibatnya, kita bisa mendapatkan hasil maksimum yang **salah**, walau hanya sedikit meleset. Ini berbahaya, apalagi dalam aplikasi yang bergantung pada presisi tinggi, seperti:

- Simulasi fisika
    
- Perhitungan keuangan
    
- Sistem navigasi
    
- Ilmu data dan statistik
    
- Pemodelan AI dan machine learning
    

---

### 🔧 Solusi: Gunakan Toleransi (Epsilon)

Pendekatan yang umum dan direkomendasikan adalah menggunakan **nilai toleransi kesalahan kecil (disebut epsilon)** dalam perbandingan:

```cpp
const double EPS = 1e-9;
if (x - maksimum > EPS) {
    maksimum = x;
}
```

Dengan pendekatan ini, kita hanya akan memperbarui maksimum jika `x` memang **signifikan lebih besar** dari nilai saat ini, menghindari jebakan perbandingan angka yang nyaris sama.

---

### 🧠 Kesimpulan

Mengetahui cara yang tepat untuk mencari nilai maksimum dari `float` atau `double` bukan hanya soal menulis kode yang benar secara sintaks, tetapi juga menulis kode yang **benar secara numerik** dan **andal secara logika**.

Mengabaikan detail ini bisa menyebabkan hasil yang:

- Salah secara matematis
    
- Sulit dideteksi bug-nya
    
- Mengacaukan seluruh hasil analisis
    

Karena itu, setiap programmer — dari pemula hingga profesional — wajib memahami **prinsip dan teknik yang benar dalam menangani bilangan pecahan**, terutama saat melakukan perbandingan dan mencari nilai ekstrem seperti maksimum.


---
## Macam-macam metode
Jadi, ada beberapa cara yang bisa kita gunakan untuk mencari nilai maksimal dari suatu kumpulan tipe data double, atau membandingkan antara 2 tipe data double/float.
### 📌 1. Jangan Pakai $==$, $>$, atau $<$ Secara Mentah

**Salah (raw comparison):**

```cpp
if (a == b) // bisa gagal meskipun nilainya kelihatan sama!
```

**Benar (pakai toleransi/epsilon):**

```cpp
const double EPS = 1e-9;
if (std::abs(a - b) < EPS) {
    // a dianggap sama dengan b
}
```


---

### 📈 2. Cara Membandingkan Float/Double untuk Mencari Maksimum

```cpp
double maksimum = data[0];
for (int i = 1; i < n; i++) {
    if (data[i] - maksimum > EPS) {
        maksimum = data[i];
    }
}
```

> ✅ Ini cara yang aman dan presisi: "lebih besar dari maksimum _secara signifikan_".

---

### 🔍 3. Gunakan `std::max` dan `std::max_element` — Masih Aman!

```cpp
double maksimum = std::max(a, b); // tetap oke
```

```cpp
double maksimum = *std::max_element(vec.begin(), vec.end());
```

🔸 Karena `std::max` dan `max_element` menggunakan operator `<`, mereka **tidak sensitif terhadap error kecil** seperti $==$.

Namun, jika kamu ingin hasil yang lebih stabil dalam perbandingan dekat, gunakan manual dengan `EPS` seperti di atas.

---

### 🔒 4. Gunakan `std::numeric_limits<double>::lowest()` untuk Nilai Awal

Daripada:

```cpp
double maksimum = -1e9;
```

Lebih aman:

```cpp
#include <limits>
double maksimum = std::numeric_limits<double>::lowest();
```

> ✨ Ini memastikan kamu menangani angka negatif besar dengan aman.

---

### 🧪 5. Gunakan Precision Saat Output

```cpp
#include <iomanip>
std::cout << std::fixed << std::setprecision(10) << maksimum << '\n';
```

> Supaya hasilnya tidak dibulatkan di layar, dan tetap sesuai akurasi internal.

---

### 🧠 6. Jika Bisa, Gunakan `long double`

Kalau kamu butuh akurasi lebih tinggi dan platform/compiler mendukung:

```cpp
long double a = 1.234567890123456L;
```

Namun:

- Performa lebih lambat
    
- Ukuran memory lebih besar
    
- Tidak semua platform mendukung penuh
    

---

### ✅ 7. Ringkasan Best Practice

|Kebutuhan|Solusi Aman|
|---|---|
|Bandingkan dua float/double|Pakai `abs(a - b) < EPS`|
|Cari nilai maksimum manual|Gunakan `if (x - max > EPS)`|
|Cari nilai maksimum STL|`std::max_element()` tetap boleh, aman secara umum|
|Nilai awal maksimum|`std::numeric_limits<double>::lowest()`|
|Output hasil|`std::fixed << std::setprecision(x)`|
