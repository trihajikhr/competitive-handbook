---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Fungsi Pembulatan C++
sumber: Google.com, AI
tags:
  - tipe-data
  - syntax
  - float
  - double
---

---
# 🎯 Rounding Modes dan Fungsi Pembulatan dalam C++

Dalam perhitungan numerik, kita sering berhadapan dengan angka pecahan (`float`, `double`, `long double`) yang perlu dibulatkan ke angka bulat terdekat. C++ menyediakan beberapa fungsi pembulatan dalam library `<cmath>`. Memahami perbedaan antara fungsi-fungsi ini sangat penting agar hasil perhitungan tidak menyesatkan.

---

## 📚 Fungsi Pembulatan dalam C++

| Fungsi     | Efek Pembulatan                       | Contoh (`x = -2.3`) | Contoh (`x = 2.7`) |
|------------|----------------------------------------|---------------------|---------------------|
| `floor(x)` | Dibulatkan ke bawah (menuju -∞)        | -3                  | 2                   |
| `ceil(x)`  | Dibulatkan ke atas (menuju +∞)         | -2                  | 3                   |
| `round(x)` | Dibulatkan ke bilangan bulat terdekat  | -2                  | 3                   |
| `trunc(x)` | Dibuang bagian desimalnya (menuju nol) | -2                  | 2                   |

> Semua fungsi ini terdapat dalam header:  
```cpp
#include <cmath>
````

---

## 🔎 Penjelasan Singkat Setiap Fungsi

### `floor(x)`

- Membulatkan ke bawah (ke bilangan bulat lebih kecil atau sama).
    

```cpp
cout << floor(2.7);  // output: 2
cout << floor(-2.7); // output: -3
```

### `ceil(x)`

- Membulatkan ke atas (ke bilangan bulat lebih besar atau sama).
    

```cpp
cout << ceil(2.1);  // output: 3
cout << ceil(-2.1); // output: -2
```

### `round(x)`

- Membulatkan ke bilangan bulat terdekat.
    
- Jika angka .5, dibulatkan menjauh dari nol (C++11 dan setelahnya).
    

```cpp
cout << round(2.5);  // output: 3
cout << round(-2.5); // output: -3
```

### `trunc(x)`

- Menghapus bagian desimal, seperti pembulatan ke nol.
    

```cpp
cout << trunc(2.9);  // output: 2
cout << trunc(-2.9); // output: -2
```

---

## 🔬 Contoh Eksperimen

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double angka[] = {-2.8, -2.5, -2.3, 0.0, 2.3, 2.5, 2.8};

    for (double x : angka) {
        cout << "x = " << x << endl;
        cout << "  floor : " << floor(x) << endl;
        cout << "  ceil  : " << ceil(x) << endl;
        cout << "  round : " << round(x) << endl;
        cout << "  trunc : " << trunc(x) << endl;
        cout << "--------------------------\n";
    }
}
```

---

## ⚠️ Perhatian terhadap Rounding `.5`

```cpp
cout << round(2.5);  // 3
cout << round(-2.5); // -3
```

> `round()` pada C++ mengikuti **“round halfway away from zero”**. Ini bisa berbeda dengan metode perbankan atau matematika klasik yang biasa membulatkan ke **genap** jika berada di titik tengah (banker's rounding).

---

## 🛠️ Gunakan Rounding Saat:

✅ Membatasi hasil agar sesuai dengan aturan:

- Pembulatan harga.
    
- Pembulatan skor atau rating.
    
- Saat bekerja dengan indeks array.
    

✅ Membandingkan hasil pecahan:

```cpp
int nilai_bulat = (int)round(nilai_double);
```

---

## 📎 Kesimpulan Fungsi Pembulatan

|Fungsi|Ke Mana Dibulatkan|Mirip Dengan...|
|---|---|---|
|floor|Ke bawah (lebih kecil)|Lantai|
|ceil|Ke atas (lebih besar)|Atap|
|round|Terdekat|Aturan matematika umum|
|trunc|Menghapus desimal|Potong, bukan bulat|


> 🧠 "Mengetahui cara membulatkan angka dengan benar = menjaga keakuratan dan keadilan hasil perhitungan. Jangan remehkan efek 1 angka pembulatan!"
