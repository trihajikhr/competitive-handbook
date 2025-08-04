---
obsidianUIMode: preview
note_type: latihan
latihan: Gabungkan Elemen
sumber:
  - chatgpt.com
tags:
  - data-structure
  - tuple
date_learned: 2025-08-03T15:27:00
---
---
# Gabungkan Elemen

Diberikan dua tuple:

```cpp
auto t1 = std::make_tuple(1, 'A');
auto t2 = std::make_tuple(3.14, "hello");
```

Tugasmu:

1. Gabungkan `t1` dan `t2` menjadi satu tuple `t3`.
    
2. Cetak semua elemen `t3`.
    

<br/>

---
# Jawaban

Mudah menggunakan satu fungsi saja:

```cpp
#include <iostream>
#include <tuple>
using namespace std;

auto main() -> int {
   tuple<int, char> t1;
   tuple<float, string> t2;
   t1 = make_tuple(1, 'A');
   t2 = make_tuple(3.14, "hello");
   auto t3 = tuple_cat(t1, t2);

   cout << get<0>(t3) << "\n";
   cout << get<1>(t3) << "\n";
   cout << get<2>(t3) << "\n";
   cout << get<3>(t3) << "\n";
   return 0;
}
```

<br/>

---
# Editorial

Cukup menggunakan satu fungsi yaitu `tupple_cat()`.