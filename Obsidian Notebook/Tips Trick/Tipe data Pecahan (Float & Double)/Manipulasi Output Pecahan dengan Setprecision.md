---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Manipulasi Output Pecahan dengan Setprecision
sumber: Google.com, AI
tags:
  - tipe-data
  - function
  - float
  - double
---

---
# 🧮 `std::setprecision()` dan Manipulasi Output Pecahan di C++

Dalam C++, manipulasi tampilan angka pecahan sangat penting untuk:
- Menampilkan data secara rapi
- Menghindari angka terlalu panjang
- Menyesuaikan presisi sesuai kebutuhan aplikasi (ilmu, keuangan, dll)

C++ menyediakan manipulasi ini melalui **header `<iomanip>`**, khususnya:
- `std::setprecision(n)`
- `std::fixed`
- `std::scientific`
- `std::showpoint`, `std::noshowpoint`
- `std::setw`, `std::left`, `std::right`

---

## 🎯 Fungsi `std::setprecision()`

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double pi = 3.14159265358979;

    cout << setprecision(4) << pi << endl;
    return 0;
}
````

**Output (tanpa `fixed`):**

```
3.142
```

### 📌 Catatan:

- `setprecision(n)` → **jumlah digit signifikan**, **bukan jumlah digit setelah koma**, _kecuali_ dipakai bersama `fixed`.
    

---

## ✅ Contoh dengan `fixed`

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double pi = 3.14159265358979;

    cout << fixed << setprecision(4) << pi << endl;
    return 0;
}
```

**Output:**

```
3.1416
```

✅ Sekarang `setprecision(4)` berarti **4 angka setelah koma**.

---

## 📌 Perbedaan `setprecision()` Dengan dan Tanpa `fixed`

|Mode|Contoh (`3.14159265`)|Keterangan|
|---|---|---|
|`setprecision(4)`|`3.142`|4 digit signifikan total|
|`fixed + setprecision(4)`|`3.1416`|4 angka setelah titik desimal|
|`scientific + setprecision(4)`|`3.1416e+00`|Notasi ilmiah 4 angka setelah koma|

---

## 🧪 Contoh Perbandingan

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double num = 123.456789;

    cout << "Default       : " << num << endl;
    cout << "Precision(4)  : " << setprecision(4) << num << endl;
    cout << "Fixed(4)      : " << fixed << setprecision(4) << num << endl;
    cout << "Scientific(4) : " << scientific << setprecision(4) << num << endl;

    return 0;
}
```

**Output:**

```
Default       : 123.457
Precision(4)  : 123.5
Fixed(4)      : 123.4568
Scientific(4) : 1.2346e+02
```

---

## ✨ Format Tambahan (opsional)

|Manipulator|Fungsi|
|---|---|
|`setw(n)`|Lebar kolom minimum (padding spasi)|
|`left`, `right`|Perataan ke kiri atau kanan|
|`showpoint`|Selalu tampilkan titik desimal|
|`noshowpoint`|Sembunyikan titik desimal jika tidak perlu|
|`setfill(char)`|Isi padding (default = spasi)|

**Contoh:**

```cpp
cout << setw(10) << right << setfill('*') << fixed << setprecision(2) << 12.3;
```

**Output:**

```
****12.30
```

---

## 🎓 Kapan Menggunakan?

|Kebutuhan|Teknik|
|---|---|
|Tampilan uang (`$12.50`)|`fixed` + `setprecision(2)`|
|Angka ilmiah (`1.2e+05`)|`scientific` + `setprecision(n)`|
|Tampilan rapi dalam tabel|`setw()`, `left/right`, `setfill()`|
|Debugging angka pecahan|`setprecision(20)`|

---

## 🧠 Tips Praktis

- Gunakan `fixed` jika ingin kontrol **angka di belakang koma**.
    
- Untuk angka **sangat besar atau kecil**, pertimbangkan `scientific`.
    
- Gunakan `std::ostringstream` jika ingin menggabungkan string hasil format.
    

```cpp
#include <sstream>
ostringstream ss;
ss << fixed << setprecision(2) << 1.23456;
string hasil = ss.str();  // "1.23"
```

---

## 🧾 Kesimpulan

- `std::setprecision(n)` adalah alat penting untuk mengatur **presisi tampilan angka pecahan**.
    
- Gunakan `fixed` atau `scientific` untuk mengatur mode tampilan.
    
- Untuk keuangan, hasil akhir sebaiknya dibulatkan dan ditampilkan dengan `fixed` dan `setprecision(2)`.
    

---

> 📌 “Tampilan yang rapi mencerminkan logika yang presisi.”
