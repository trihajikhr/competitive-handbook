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
   tuple<int, char, float> datup;
   datup = make_tuple(10, 'Z', 3.14);

   // cetak tupple
   cout << get<0>(datup) << " " << get<1>(datup) << " " << get<2>(datup);
   return 0;
}
```

<br/>

---
# 3 | Editorial

Setiap data pada tuple itu bisa diakses seperti array, dengan pengindeksan mirip seperti cara kita mengindeks array, yang dimulai dari 0.

Hanya saja, kita menggunakan tambahan `get<>`.