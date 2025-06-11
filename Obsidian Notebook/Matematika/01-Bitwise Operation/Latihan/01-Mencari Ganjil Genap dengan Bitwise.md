---
obsidianUIMode: preview
note_type: latihan
latihan: Mencari Ganjil Genap dengan Bitwise
sumber: chatgpt.com
tags:
  - bits
  - bitwise
---
---
# Mencari Ganjil Genap dengan Bitwise

**Deskripsi:**  
Diberikan sebuah bilangan bulat `x`. Cetak `EVEN` jika genap, `ODD` jika ganjil.  
Gunakan operasi bitwise!

**Contoh:**

```
Input: 7
Output: ODD

Input: 12
Output: EVEN
```

💡 _Hint:_ Gunakan `x & 1`.

---
## Jawaban:
Versi 1:

```cpp
#include<iostream>
using namespace std;

// menentukan ganjil genap menggunakan representasi bit (bitwise)
int main() {
    int x; cin >> x;
    bool odd = (x & 1 ? true : false);
    cout << (odd ? "ODD" : "EVEN") << "\n";
    return 0;
}
```

Versi 2:
```cpp
#include<iostream>
using namespace std;

int main() {
    int x; cin >> x;
    cout << (x & 1 == 1 ? "ODD" : "EVEN") << "\n";
    return 0;
}
```

## Penjelasan:

Mengapa operasi bitwise bisa digunakan untuk menentukan apakah sebuah bilangan bulat genap atau ganjil, khususnya menggunakan `x & 1`.

### 🔍 Inti dari Bitwise AND (`&`)

Operasi bitwise bekerja **per bit**. Artinya, ketika kita melakukan `x & 1`, kita sedang **mengecek bit paling kanan (bit ke-0)** dari bilangan `x`.

### 💡 Representasi Biner dan Bit Paling Kanan

Dalam biner:

- **Bilangan genap** selalu berakhir dengan **0**
    
- **Bilangan ganjil** selalu berakhir dengan **1**
    

Contoh:

|Desimal|Biner|Bit ke-0|
|---|---|---|
|4|100|0|
|5|101|1|
|12|1100|0|
|13|1101|1|


### ✅ Menggunakan `x & 1`

Operasi `x & 1` hanya memeriksa **bit terakhir** dari `x`. Kenapa?

```cpp
Contoh: x = 13 (1101)
        1 = 0001
     ----------
    1101 & 0001 = 0001 → hasilnya 1 → artinya ganjil

Contoh: x = 12 (1100)
        1 = 0001
     ----------
    1100 & 0001 = 0000 → hasilnya 0 → artinya genap
```

Jadi:

- Jika `x & 1` menghasilkan `1`, maka `x` **ganjil**
    
- Jika `x & 1` menghasilkan `0`, maka `x` **genap**
    

### 🚀 Keunggulan Dibandingkan Modulo

Biasanya orang menulis `x % 2 == 0` untuk cek genap. Itu juga benar, tapi...

|Operasi|Kecepatan|
|---|---|
|`%` modulo|Lebih lambat|
|`&` bitwise|**Sangat cepat** (O(1))|

### Kesimpulan

Kita bisa menggunakan `x & 1` untuk mengecek apakah sebuah bilangan **genap atau ganjil** karena:

- Bit paling kanan dari representasi biner menunjukkan apakah bilangan itu genap (0) atau ganjil (1).
    
- Operasi bitwise `&` sangat cepat dan langsung mengecek bit tersebut.
    