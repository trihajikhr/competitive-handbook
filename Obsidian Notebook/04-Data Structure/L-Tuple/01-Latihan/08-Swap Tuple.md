---
obsidianUIMode: preview
note_type: latihan
latihan: Swap Tuple
sumber:
  - chatgpt.com
tags:
  - data-structure
  - tuple
date_learned: 2025-08-03T15:54:00
---
---
# 1 | Swap Tuple

Tugas:

1. Buat dua tuple `a` dan `b`, misalnya:
    
    ```cpp
    tuple<int, char> a{1, 'X'}, b{2, 'Y'};
    ```
    
2. Tukar isi `a` dan `b` menggunakan `std::swap`.
    
3. Cetak isi keduanya setelah ditukar.



<br/>

---
# 2 | Jawaban

```cpp
#include <iostream>
#include <tuple>
#include <utility> // untuk std::swap

using namespace std;

int main() {
    tuple<int, char> a{1, 'X'};
    tuple<int, char> b{2, 'Y'};

    cout << "Sebelum ditukar:\n";
    cout << "a = (" << get<0>(a) << ", " << get<1>(a) << ")\n";
    cout << "b = (" << get<0>(b) << ", " << get<1>(b) << ")\n";

    // tukar isi a dan b
    swap(a, b);

    cout << "\nSetelah ditukar:\n";
    cout << "a = (" << get<0>(a) << ", " << get<1>(a) << ")\n";
    cout << "b = (" << get<0>(b) << ", " << get<1>(b) << ")\n";

    return 0;
}
```

<br/>

---
# 3 | Editorial

Problemnya meminta menukar isi dua tuple. Solusi paling mudah adalah memakai fungsi bawaan `std::swap` dari C++ yang sudah mendukung tipe generik, termasuk tuple.

Langkahnya sederhana:

1. Definisikan dua tuple `a` dan `b` dengan nilai awal.
2. Cetak nilai tuple sebelum ditukar (gunakan `std: :get<i>` untuk mengakses elemen ke-`i`).
3. Gunakan `swap(a, b);` untuk menukar isinya.
4. Cetak kembali setelah ditukar untuk memastikan hasil.

Karena `std::swap` sudah diimplementasikan dengan efisien, kita tidak perlu menulis fungsi manual untuk pertukaran. Dengan begitu, kode singkat, aman, dan mudah dibaca.

👉 Inti editorial: manfaatkan library standar (`<utility>`) agar operasi umum seperti pertukaran bisa langsung dipakai tanpa harus implementasi ulang.

