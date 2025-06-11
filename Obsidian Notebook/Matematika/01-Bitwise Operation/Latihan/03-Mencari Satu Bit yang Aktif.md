---
obsidianUIMode: preview
note_type: latihan
latihan: Mencari Satu Bit yang Aktif
sumber: chatgpt.com
tags:
  - bits
  - bitwise
---
---
# Mencari Satu Bit yang Aktif

Diberikan sebuah bilangan bulat positif `x`. Tentukan apakah **hanya satu bit 1** yang aktif dalam representasi biner dari `x`.

Contoh:

```
Input: 16   → Output: YES    (karena 16 = 10000)
Input: 10   → Output: NO     (karena 10 = 1010, ada dua bit 1)
```

---

## 📘 Penjelasan Konsep

Sebuah bilangan memiliki **hanya satu bit 1** jika dan hanya jika bentuk binernya seperti ini:

```
00010000
```

Ciri khusus:

- Bilangan tersebut adalah **pangkat dua**, seperti 1, 2, 4, 8, 16, 32, ...
    
- Dan memiliki properti **bitwise** berikut:
    

### 💡 Rumus:

```cpp
(x > 0) && ((x & (x - 1)) == 0)
```

### 📌 Kenapa bisa begitu?

- `x - 1` akan mengubah bit 1 paling kanan menjadi 0 dan semua bit setelahnya menjadi 1.
    
- Maka jika `x` hanya punya satu bit 1, `x & (x - 1)` akan menjadi 0.
    

Contoh:

```
x = 8  → 1000
x - 1 = 7 → 0111
1000 & 0111 = 0000
```

---

## 🧪 Implementasi C++

```cpp
#include <iostream>
using namespace std;

bool isSingleBitSet(int x) {
    return (x > 0) && ((x & (x - 1)) == 0);
}

int main() {
    int x;
    cout << "Masukkan bilangan: ";
    cin >> x;

    if (isSingleBitSet(x))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
```
