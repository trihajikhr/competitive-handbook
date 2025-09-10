---
obsidianUIMode: preview
note_type: latihan
latihan: Destructuring
sumber:
  - chatgpt.com
tags:
  - data-structure
  - tuple
date_learned: 2025-08-03T14:54:00
---
---
# 1 | Destructuring

Gunakan teknik **structured binding** untuk mengekstrak nilai dari tuple berikut:

```cpp
auto t = std::make_tuple(7, 'B', 2.71);
```

Cetak semua elemen tanpa menggunakan `get`.

<br/>

---
# 2 | Jawaban

Jawabanya cukup mudah, masih gampang diawal-awal ini:

```cpp
#include <iostream>
#include <tuple>
using namespace std;

auto main() -> int {
   tuple<int, char, float> t;
   t = make_tuple(7, 'B', 2.71);
   auto [a, b, c] = t;
   cout << a << " " << b << " " << c << "\n";
   return 0;
}
```

<br/>

---
# 3 | Editorial

Cukup gunakan `auto` untuk melakukan pembongkaran pada tuple. Bisa juga menggunakan `tie()`. 

Keuntungan menggunakan `auto` adalah lebih modern, dan lebih mudah diaplikasikan, lebih mudah dipahami pemula. Sedangkan jika menggunakan `tie()`, kelebihanya adalah bisa mengabaikan data yang tidak ingin di destructor, caranya adalah dengan menyisipkan `ignore` pada saat penggunaan `tie()`.