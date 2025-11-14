---
obsidianUIMode: preview
note_type: latihan
latihan: Tuple dalam Vector
sumber:
  - chatgpt.com
tags:
  - data-structure
  - tuple
date_learned: 2025-08-03T15:49:00
---
---
# 1 | Tuple dalam Vector

Tugas:

1. Buat `vector<tuple<int, string>>` berisi data berikut:
    
    - `(3, "Alice")`
        
    - `(1, "Bob")`
        
    - `(2, "Charlie")`
        
2. Urutkan vector berdasarkan nilai integer (elemen pertama tuple).
    
3. Cetak hasil akhirnya.

<br/>

---
# 2 | Jawaban

```cpp
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

#define get(i, t) get<i>(t)

auto main() -> int {
   vector<tuple<int, string>> vectup;
   vectup.emplace_back(3, "Alice");
   vectup.emplace_back(1, "Bob");
   vectup.emplace_back(2, "Charlie");
   std::ranges::sort(vectup, [](const auto& a, const auto& b) { 
	   return get<0>(a) < get<0>(b); 
	});

   for (auto& i : vectup) {
      auto [num, name] = i;
      cout << num << " " << name << '\n';
   }
   return 0;
}
```

<br/>

---
# 3 | Editorial

## 3.1 | `emplace_back` vs `push_back`

- `emplace_back(3, "Alice")` langsung **membuat tuple di tempat**, tanpa membuat sementara (`temporary object`).
    
- `push_back(make_tuple(...))` butuh membuat tuple dulu, lalu disalin/di-move.
    
- Jadi: `emplace_back` lebih **efisien & idiomatik**, terutama untuk `tuple`, `pair`, dan objek kompleks.
    

## 3.2 | Kenapa bisa pakai `std::ranges::sort`

- `std::ranges::sort` tersedia sejak **C++20**.
    
- Keuntungannya:
    
    - Tidak perlu `.begin()` & `.end()`.
        
    - Lebih aman untuk container yang bukan raw array.
        
    - Dukungan lambda lebih jelas & ekspresif.
        

Cara diatas memang sangat dianjurkan, terutama ketika kamu sudah menggunakan C++ 20.