---
obsidianUIMode: preview
note_type: latihan
latihan: Mencari Bit Aktif di Posisi X
sumber: chatgpt.com
tags:
  - bits
  - bitwise
---
---
#  Temukan Bit yang Aktif di Posisi ke-3


Diberikan sebuah bilangan bulat non-negatif `x`, tentukan apakah **bit ke-3 dari kanan (0-based index)** adalah 1.

Contoh:

```
Input: 13 → Output: YES   (karena 13 = 1101, bit ke-3 adalah 1)
Input: 5  → Output: NO    (karena 5  = 0101, bit ke-3 adalah 0)
```

---

## 📘 Penjelasan Konsep

Bit ke-3 berarti kita ingin tahu apakah **bit di posisi ke-3** dari kanan bernilai **1**.  
Gunakan operasi **bitwise AND** untuk memeriksa apakah bit tersebut aktif.

### 💡 Rumus:

```cpp
if (x & (1 << 3))
```

Penjelasan:

- `1 << 3` artinya geser angka 1 ke kiri sebanyak 3 kali → hasilnya `00001000` (yaitu 8).
    
- Jika bit ke-3 di `x` adalah 1, maka hasil `x & 8` akan lebih dari 0.
    

---

## 🧪 Implementasi C++

```cpp
#include <iostream>
using namespace std;

bool isBit3Set(int x) {
    return (x & (1 << 3));
}

int main() {
    int x;
    cout << "Masukkan bilangan: ";
    cin >> x;

    if (isBit3Set(x))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
```

## Penjelasan tambahan

> Jika bit ke-3 di `x` adalah 1, maka hasil `x & 8` akan lebih dari 0?

### 💡 Maksudnya Apa?

- Kita ingin **memeriksa apakah bit ke-3 (dari kanan, posisi indeks ke-3) bernilai 1.**
    
- Untuk melakukan itu, kita **membandingkan `x` dengan bilangan yang hanya memiliki bit ke-3 aktif**, yaitu:
    
    ```
    1 << 3 = 8 = 00001000 (dalam biner, 8-bit)
    ```
    
- Lalu kita lakukan **bitwise AND**:
    
    ```cpp
    x & (1 << 3)
    ```
    

---

### 🧪 Contoh 1: `x = 13`

13 dalam biner:

```
00001101
         ↑
      posisi ke-0, ke-2, dan ke-3 aktif
```

```cpp
1 << 3 = 8 = 00001000
13 & 8 = 00001101
          &
         00001000
         ---------
         00001000 → hasilnya 8
```

> Karena hasilnya **bukan nol**, maka bit ke-3 aktif.

---

### 🧪 Contoh 2: `x = 5`

5 dalam biner:

```
00000101
         ↑
      posisi ke-0 dan ke-2 aktif
```

```cpp
1 << 3 = 00001000
5 & 8  = 00000101
          &
         00001000
         ---------
         00000000 → hasilnya 0
```

> Karena hasilnya **nol**, berarti **bit ke-3 tidak aktif**.

---

### ✨ Jadi...

Kalimat:

> Jika bit ke-3 di `x` adalah 1, maka hasil `x & 8` akan lebih dari 0.

berarti:

> Jika kita lakukan operasi AND antara `x` dan `00001000` (yaitu 8), dan hasilnya **tidak nol**, maka **bit ke-3 aktif**.

---

### 📘 Versi Umum (untuk bit ke-k):

Gunakan:

```cpp
if (x & (1 << k))
```

Jika hasilnya bukan nol, maka **bit ke-k aktif**. Kalau nol, berarti tidak aktif.
