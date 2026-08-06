---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Menukar (Toggle) Bit di C++
sumber: geeksforgeeks.org
date_learned: 2025-06-10T00:21:00
tags:
  - bits
  - bitwise
---
Link Sumber: [Toggling Bits in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/toggling-bits-in-cpp/)

---
# Menukar (Toggle) Bit di C++
Dalam pemrograman C++, _menukar_ atau _toggle_ sebuah bit berarti mengubah nilai dari bit tertentu dalam sebuah bilangan biner. Operasi ini berguna dalam berbagai aplikasi seperti kriptografi, kompresi data, dan pengendalian perangkat keras.

Pada artikel ini, kita akan mempelajari bagaimana cara menukar (toggle) satu bit pada posisi tertentu dalam bilangan biner. Selain itu, kita juga akan melihat bagaimana cara menukar beberapa bit sekaligus.

---

## Apa Itu Bit Toggling?

_Toggling bit_ berarti **membalik nilai bit**. Misalnya:

- Mengubah bit dari `0` menjadi `1`.
    
- Mengubah bit dari `1` menjadi `0`.
    

---

## Cara Menukar Bit di C++?

Di C++, kita bisa menggunakan operator **XOR (`^`)** untuk menukar bit. Operator XOR (exclusive OR) menghasilkan `true` atau `1` **hanya jika** kedua bit input berbeda.

Berikut adalah tabel kebenaran untuk XOR:

|A|B|A ^ B|
|---|---|---|
|0|0|0|
|0|1|1|
|1|0|1|
|1|1|0|

Dari tabel tersebut, kita bisa menyimpulkan:

- **Bit XOR 1** → hasilnya **berkebalikan** (bit ditukar).
    
- **Bit XOR 0** → hasilnya **tetap sama**.
    

---

## Menukar Bit Tertentu di C++

Untuk menukar bit tertentu dalam suatu bilangan, kita dapat membuat **bitmask** dengan posisi bit yang ingin diubah diset ke `1`, sementara bit lainnya diset ke `0`. Lalu gunakan operator XOR (`^`) antara bilangan dan bitmask tersebut.

### Contoh:

Contoh berikut menunjukkan cara menukar **bit ke-3** dalam suatu bilangan:

```cpp
// Program C++ untuk menukar bit tertentu dari sebuah bilangan unsigned
#include <iostream>
using namespace std;

int main()
{
    // Inisialisasi bilangan biner: 0001 1101 (29 desimal)
    unsigned int num = 29;

    // Posisi bit yang ingin ditukar (indeks mulai dari 0)
    unsigned int bit_position = 2;

    // Buat mask dengan bit ke-2 diset ke 1
    unsigned int mask = 1 << bit_position;

    // Tukar bit dengan operasi XOR
    num = num ^ mask;

    // Cetak hasil setelah bit ditukar
    cout << "Hasil: " << num << endl;

    return 0;
}
```

### Output:

```
Hasil: 25
```

### Penjelasan:

- Bilangan awal: `0001 1101` (29)
    
- Bit yang ditukar: bit ke-2
    
- Mask yang digunakan: `0000 0100`
    
- Hasil akhir: `0001 1001` (25 desimal)
    

### Kompleksitas:

- **Waktu:** `O(1)`
    
- **Memori Tambahan:** `O(1)`
    

---

## Menukar Beberapa Bit Sekaligus di C++

Kita juga bisa menukar beberapa bit sekaligus dengan membuat **bitmask** yang menandai semua bit yang ingin ditukar. XOR-kan bilangan dengan bitmask tersebut untuk menukar bit-bit yang sesuai.

### Contoh:

Contoh berikut menunjukkan cara menukar **bit ke-1, ke-3, dan ke-4** dari suatu bilangan:

```cpp
// Program C++ untuk menukar beberapa bit dari sebuah bilangan unsigned
#include <iostream>
using namespace std;

int main()
{
    // Inisialisasi bilangan biner: 0001 1101 (29 desimal)
    unsigned int num = 29;

    // Buat mask dengan bit ke-0, ke-2, dan ke-3 diset ke 1
    unsigned int mask = (1 << 0) | (1 << 2) | (1 << 3);

    // Tukar bit-bit dengan operasi XOR
    num = num ^ mask;

    // Cetak hasil
    cout << "Hasil: " << num << endl;

    return 0;
}
```

### Output:

```
Hasil: 16
```

### Penjelasan:

- Bilangan awal: `0001 1101` (29)
    
- Bit yang ditukar: ke-0, ke-2, ke-3
    
- Mask yang digunakan: `0000 1101`
    
- Hasil akhir: `0001 0000` (16 desimal)
    

### Kompleksitas:

- **Waktu:** `O(n)`, dengan `n` adalah jumlah bit yang ingin ditukar.
    
- **Memori Tambahan:** `O(1)`
    

---

## Aplikasi Bit Toggling

Beberapa aplikasi dari teknik manipulasi bit seperti _toggling_:

- Digunakan dalam **algoritma enkripsi dan dekripsi**.
    
- Berguna untuk **kompresi data** yang efisien.
    
- Digunakan untuk mengatur **pengaturan perangkat keras** secara langsung, seperti menyalakan/mematikan flag di dalam register kontrol.
    

---

## Kesimpulan

Menukar bit di C++ adalah proses yang sederhana dengan menggunakan **operator XOR**. Dengan membuat bitmask yang tepat, kita dapat secara efisien menukar satu atau lebih bit dalam sebuah bilangan biner. Teknik ini sangat penting untuk pemrograman tingkat rendah dan banyak digunakan dalam berbagai aplikasi yang memerlukan manipulasi data tingkat bit.
