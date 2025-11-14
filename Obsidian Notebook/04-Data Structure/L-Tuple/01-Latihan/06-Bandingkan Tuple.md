---
obsidianUIMode: preview
note_type: latihan
latihan: Bandingkan Tuple
sumber:
  - chatgpt.com
tags:
  - data-structure
  - tuple
date_learned: 2025-08-03T15:29:00
---
---
# 1 | Bandingkan Tuple

Diberikan dua tuple:

```cpp
auto a = std::make_tuple(1, 2);
auto b = std::make_tuple(1, 3);
```

Tugasmu:

1. Bandingkan `a < b` dan cetak hasilnya (`true`/`false`).
    
2. Tambahkan satu contoh lain yang hasilnya `false`.



<br/>

---
# 2 | Jawaban

Ternyata kita bisa langsung saja menggunakan operasi perbandingan:

```cpp
#include <iostream>
#include <tuple>
using namespace std;

#define get(i, t) get<i>(t)

auto main() -> int {
   tuple<int, int> a = {1, 2};
   tuple<int, int> b = {1, 3};
   cout << (a < b ? "True" : "False");
   return 0;
}
```

<br/>

---
# 3 | Editorial

C++ menyediakan operator perbandingan bawaan $==$, $!=$, $<$, $<=$, $>$, $>=$ untuk `std::tuple`. Perbandingan dilakukan secara leksikografis, yaitu elemen demi elemen dari kiri ke kanan, sama seperti cara string dibandingkan.

Secara formal, untuk dua tuple `a` dan `b` dengan jumlah elemen yang sama:

- `a < b` bernilai `true` jika dan hanya jika:
    
    - elemen pertama `a` lebih kecil dari elemen pertama `b`, atau
        
    - jika elemen pertama sama, maka elemen kedua dibandingkan, dan seterusnya.
        

Dengan contoh:

```cpp
(1, 2) < (1, 3) → true  // karena elemen pertama sama, tapi 2 < 3
(2, 1) < (1, 9) → false // karena 2 > 1
```

Perbandingan tuple ini dilakukan secara otomatis menggunakan **operator `<=>` (C++20)** atau operator relational biasa di versi sebelumnya.


```ad-info
`std::tuple` mendukung perbandingan langsung menggunakan operator bawaan.  
Perbandingan dilakukan leksikografis (dictionary order) berdasarkan urutan elemen dari kiri ke kanan. Tidak perlu menulis fungsi pembanding manual.
```