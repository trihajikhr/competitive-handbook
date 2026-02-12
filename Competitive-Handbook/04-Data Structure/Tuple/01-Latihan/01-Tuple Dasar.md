---
obsidianUIMode: preview
note_type: latihan
latihan: Tuple Dasar
sumber:
  - chatgpt.com
tags:
  - data-structure
  - tuple
date_learned: 2025-08-03T14:31:00
---
---
# 1 | Tuple Dasar

Buatlah sebuah tuple `t` yang berisi tiga elemen:

- Integer `10`
    
- Karakter `'Z'`
    
- Double `3.14`
    

Cetak semua elemen tuple tersebut satu per satu.

<br/>

---
# 2 | Jawaban
Soal ini mudah, jadi langsung saja cetak pakai `get` dan juga `make_tuple`:

```cpp
#include <iostream>
#include <tuple>
using namespace std;

auto main() -> int {
   tuple<int, char, double> datup;
   datup = make_tuple(10, 'Z', 3.14);

   // cetak tuple
   cout << get<0>(datup) << " " << get<1>(datup) << " " << get<2>(datup);
   return 0;
}
```

<br/>

---
# 3 | Editorial

Setiap elemen di dalam `std::tuple` dapat diakses menggunakan fungsi templat `std::get<I>(t)`, di mana `I` adalah indeks konstanta pada waktu kompilasi (bukan nilai variabel).

Indeks tuple dimulai dari `0`, mirip seperti array, namun aksesnya dilakukan melalui parameter templat, bukan melalui operator indeks (`[]`)

- `get<0>(datup)` mengembalikan elemen pertama, yaitu `10` (tipe `int`).
- `get<1>(datup)` mengembalikan elemen kedua, yaitu `'Z'` (tipe `char`).
- `get<2>(datup)` mengembalikan elemen ketiga, yaitu `3.14` (tipe `double`).

```ad-info
Elemen pada `std::tuple` diakses dengan `std::get<I>(t)`, di mana `I` adalah indeks yang ditentukan pada waktu kompilasi, dimulai dari nol. Tidak seperti array, tuple tidak memiliki operator indeks runtime (`[]`), sehingga akses harus dilakukan melalui parameter templat `get<>`.
```