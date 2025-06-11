---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Ekstraksi Bit di C++
sumber: geeksforgeeks.org
date_learned: 2025-06-10T00:18:00
tags:
  - bits
  - bitwise
---
Link Sumber: [Extract Bits in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/extract-bits-in-cpp/)

---
# Ekstraksi Bit di C++
Menarik bit dari sebuah bilangan berarti mengambil sebanyak `k` bit dimulai dari posisi tertentu `pos` dengan menggunakan operasi bitwise seperti AND (`&`) dan shift (`<<`, `>>`). Dalam artikel ini, kita akan mempelajari bagaimana cara mengekstrak bit di C++.

### Contoh:

**Input:**

```
num = 214
k = 3
pos = 2
```

**Output:**

```
5
```

## Cara Ekstraksi Bit di C++

Untuk mengekstrak `k` bit dari posisi `pos` dalam suatu bilangan:

1. **Lakukan operasi right shift** pada `num` sebanyak `pos` bit, sehingga bit yang ingin diambil bergeser ke posisi paling rendah (Least Significant Bits).
    
2. **Buat sebuah mask** dengan `k` bit di posisi bawah diset menjadi 1.
    
3. **Terapkan operasi AND** antara hasil shift dengan mask tersebut untuk mendapatkan hasil ekstraksi.
    

### Langkah-langkah Ekstraksi Bit

Misalnya kita punya contoh: `num = 214` (biner: `11010110`), `k = 3`, dan `pos = 2`.

1. **Right Shift:**  
    `shifted = num >> pos`  
    `shifted = 214 >> 2 = 53` (biner: `110101`)
    
2. **Buat Mask:**  
    `mask = (1 << k) - 1`  
    `mask = (1 << 3) - 1 = 7` (biner: `111`)
    
3. **Terapkan Mask:**  
    `result = shifted & mask`  
    `result = 53 & 7 = 5` (biner: `101`)
    

## Program C++ untuk Ekstraksi Bit

Program berikut menunjukkan bagaimana kita dapat mengekstrak `k` bit dari posisi `pos` dalam sebuah bilangan `num`.

```cpp
// Program C++ untuk mengekstrak 'k' bit dari posisi 'pos' dalam bilangan 'num'

#include <iostream>
using namespace std;

// Fungsi untuk mengekstrak 'k' bit dari posisi 'pos' dalam bilangan 'num'
unsigned int extractBits(unsigned int num, unsigned int pos, unsigned int k)
{
    // Geser 'num' ke kanan sebanyak 'pos' bit
    unsigned int shifted = num >> pos;

    // Buat mask dengan 'k' bit terbawah diset ke 1
    unsigned int mask = (1 << k) - 1;

    // Terapkan mask ke hasil shift
    return shifted & mask;
}

int main()
{
    // Bilangan contoh dari mana bit akan diambil
    unsigned int num = 214;
    // Posisi awal bit yang akan diambil
    unsigned int pos = 2;
    // Jumlah bit yang akan diambil
    unsigned int k = 3;

    // Panggil fungsi untuk mengekstrak bit
    unsigned int result = extractBits(num, pos, k);

    // Cetak hasil
    cout << "Bit yang diekstrak: " << result << endl;

    return 0;
}
```

**Keluaran:**

```
Bit yang diekstrak: 5
```

### Kompleksitas Waktu:

- **O(1)**, karena setiap operasi di dalam fungsi `extractBits` (shift kanan, pembuatan mask, dan operasi AND) dilakukan dalam waktu konstan.
    

### Kompleksitas Ruang Tambahan:

- **O(1)**, karena tidak ada alokasi memori tambahan yang signifikan.
    
