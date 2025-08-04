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
# Bandingkan Tuple

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
# Jawaban

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
# Editorial

Cukup gunakan operator perbandingan, dan langsung bisa.