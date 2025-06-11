---
obsidianUIMode: preview
note_type: latihan
latihan: Menghitung Bit Aktif dalam Representasi Biner
sumber: chatgpt.com
tags:
  - bits
  - bitwise
---
---
# Menghitung Bit Aktif dalam Representasi Biner

**Deskripsi:**  
Diberikan bilangan bulat non-negatif `x`, hitung jumlah bit yang bernilai 1 dalam representasi binernya.

**Contoh:**

```
Input: 13
Output: 3   // karena 13 = 1101
```

💡 _Hint:_ Gunakan `x & (1 << i)` dalam loop, atau bisa juga `__builtin_popcount(x)` (versi built-in).

## Jawaban:

Versi 1:

```cpp
#include<iostream>
using namespace std;

int main() {
    int x; cin >> x;
    int count=0;
    for(int i=0; (1 << i) <= x ; i++){
        if((x & (1 << i)) != 0) count++;
    }

    cout << count << "\n";
    return 0;
}
```

Versi 2:
```cpp
#include<iostream>
#include<bitset>
using namespace std;

int main() {
    int x; cin >> x;
    cout << __builtin_popcount(x) << "\n";
    return 0;
}
```

## Penjelasan:

### ✅ Penjelasan Logika

```cpp
for(int i=0; (1 << i) <= x; i++) {
    if((x & (1 << i)) != 0) count++;
}
```

- `1 << i` menghasilkan bilangan dengan **hanya satu bit 1 di posisi ke-i**.
    
- `(x & (1 << i))` akan menghasilkan **nol jika bit ke-i dari `x` adalah 0**, dan **non-zero jika bit ke-i adalah 1**.
    
- Maka `if(...)` hanya menambah count jika bit ke-i menyala (bernilai 1).
    
- Perulangan berhenti jika `1 << i` sudah lebih besar dari `x` (bit ke-i pasti kosong semua untuk `i` lebih besar dari jumlah bit aktif `x`).
    

Contoh:  
Jika `x = 13`, biner = `1101`, maka jumlah bit 1 adalah `3`.

---

### 🧠 Catatan Tambahan (Tidak wajib diubah)

Kamu juga bisa memakai fungsi built-in dari C++20:

```cpp
cout << __builtin_popcount(x) << "\n";
```

Namun, pendekatan manual kamu sangat bagus untuk **belajar memahami bitwise** secara mendalam.

## Ilustrasi
Tentu! Mari kita **jelaskan dan buat tabel perulangan** dari kode berikut agar kamu benar-benar paham bagaimana ia bekerja secara langkah demi langkah:

```cpp
for(int i = 0; (1 << i) <= x; i++) {
    if((x & (1 << i)) != 0) count++;
}
```

---

### 🎯 Tujuan:

Menghitung **berapa banyak bit 1** dalam bilangan bulat positif `x`.

---

### 🧪 Contoh:

Misalnya, kita ambil `x = 13`.

Representasi biner dari `13` adalah:

```
13 = 1101 (biner) → ada 3 buah bit 1
```

---

### 🔍 Tabel Iterasi:

|i|1 << i (Des)|1 << i (Bin)|x & (1 << i) (Bin)|x & (1 << i) (Des)|Kondisi `!= 0`?|count|
|---|---|---|---|---|---|---|
|0|1|0001|1101 & 0001 = 0001|1|✅ ya|1|
|1|2|0010|1101 & 0010 = 0000|0|❌ tidak|1|
|2|4|0100|1101 & 0100 = 0100|4|✅ ya|2|
|3|8|1000|1101 & 1000 = 1000|8|✅ ya|3|
|4|16|10000|1101 & 10000 = 00000|0|❌ (stop loop)|3|

---

### 📌 Penjelasan:

- `1 << i` artinya geser angka 1 ke kiri sebanyak `i` posisi, sehingga kamu "menyalakan" hanya bit ke-`i`.
    
- `x & (1 << i)` akan menghasilkan **non-zero** jika bit ke-`i` dalam `x` menyala (1).
    
- Perulangan berhenti saat `1 << i` lebih besar dari `x` (karena bit-bit setelah itu pasti tidak relevan untuk angka `x`).
    

---

### 💡 Hasil akhir:

Untuk `x = 13`, nilai akhir `count = 3`, sesuai karena `1101` punya tiga bit 1.
