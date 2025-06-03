---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Representasi Floating Point
sumber: Google.com, AI
tags:
  - tipe-data
  - float
  - double
---

---
# Representasi Floating Point

**Akar masalah:** 

Aku membandingkan 2 tipe data double dan dua tipe data float, berharap bahwa karena perbandingan dengan double dan float akan menghasilkan NO karena presisi yang belum ditentukan dengan baik, tapi malah mendapat hasil sebaliknya. Ada yang YES:

```cpp
#include<iostream>
using namespace std;

int main() {
    double a = 0.1 + 0.2;
    double b = 0.3;

    float c = 0.5 + 0.25;
    float d = 0.75;
    
    if(a==b) cout << "YES";
    else cout << "NO";

	cout << "\n";

    if(c==d) cout << "YES";
    else cout << "NO";
    return 0;
}
```

Output:
```
NO
YES
```

Kenapa? Ayo kita cari tahu!

---

Dalam pemrograman menggunakan `float` dan `double`, kita sering menjumpai fenomena yang mengejutkan:  

```cpp
double a = 0.1 + 0.2;
double b = 0.3;

if (a == b) cout << "YES";
else cout << "NO"; // Output: NO
````

Padahal, secara matematis `0.1 + 0.2` memang sama dengan `0.3`. Lalu kenapa hasil perbandingan tersebut **tidak sama dalam program**?

---

## 🧪 Representasi Floating Point: Akar Masalahnya

Komputer menyimpan bilangan pecahan dalam **representasi biner dengan presisi terbatas**, yaitu format **IEEE 754**:

- `0.1`, `0.2`, dan `0.3` **tidak bisa direpresentasikan secara eksak** dalam biner.
    
- Sebaliknya, bilangan seperti `0.5`, `0.25`, dan `0.75` bisa direpresentasikan **secara tepat**.
    

### ⚠️ Contoh Representasi Mendekati (Double):

|Nilai Desimal|Representasi Biner (hampir)|
|---|---|
|0.1|0.10000000000000000555...|
|0.2|0.20000000000000001110...|
|0.3|0.29999999999999998890...|
|0.1 + 0.2|0.30000000000000004441...|

Perhatikan bahwa `0.1 + 0.2` sedikit **lebih besar** dari `0.3`, sehingga perbandingan `a == b` akan gagal.

---

## ✅ Kenapa `0.5 + 0.25 == 0.75` Bisa `YES`?

Contoh kode:

```cpp
float c = 0.5 + 0.25;
float d = 0.75;

if (c == d) cout << "YES"; // Output: YES
```

Karena:

- `0.5` = 2⁻¹
    
- `0.25` = 2⁻²
    
- `0.75` = `0.5 + 0.25` = `0.11` dalam biner  
    ➡️ Semua ini **eksak dalam representasi biner**, sehingga hasil perbandingannya `true`.
    

---

## 📌 Kesimpulan Penting

|Nilai|Bisa Diwakili Eksak?|Aman untuk Perbandingan Langsung?|
|---|---|---|
|0.1, 0.2, 0.3|❌ Tidak|❌ Tidak|
|0.5, 0.25, 0.75|✅ Ya|✅ Ya|

---

## 🛡️ Solusi Aman: Bandingkan dengan Epsilon (`EPS`)

Gunakan nilai toleransi (epsilon) untuk membandingkan `float`/`double`:

```cpp
const double EPS = 1e-9;
if (abs(a - b) < EPS) {
    cout << "Sama secara numerik";
}
```

Kita menganggap dua angka **cukup dekat** jika selisihnya kurang dari EPS. Ini cara **profesional dan aman** dalam menangani bilangan pecahan.

---

## 🔧 Tips Tambahan

- Gunakan `std::numeric_limits<double>::lowest()` untuk nilai awal saat mencari maksimum.
    
- Gunakan `std::fixed << std::setprecision(n)` saat ingin mencetak hasil dengan akurasi tinggi.
    
- Hindari $==$, `<`, `>` langsung untuk nilai pecahan.
    

---

## 📚 Referensi Lanjut

- IEEE 754 Floating Point Standard
    
- Dokumentasi C++: `std::numeric_limits`, `std::abs`, `std::setprecision`
    
- Artikel: "What Every Computer Scientist Should Know About Floating-Point Arithmetic" oleh David Goldberg
    

---

> 🧠 Pemahaman ini sangat penting agar program kita **tidak menampilkan hasil yang salah secara diam-diam**, terutama dalam simulasi, perhitungan ilmiah, dan kontes programming.

