---
obsidianUIMode: preview
note_type: latihan
latihan: Ukuran Tuple
sumber:
  - chatgpt.com
tags:
  - tag
date_learned: 2025-08-03T14:56:00
---
---
# Ukuran Tuple


Diberikan tuple:

```cpp
auto t = std::make_tuple(1, 2.0, 'C', "text");
```

Tugasmu:

1. Cetak ukuran (jumlah elemen) dari tuple tersebut menggunakan `tuple_size`.

<br/>

---
# Jawaban

Jawaban yang cukup mudah, hanya saja harus hafal sintaksnya:

```cpp
#include <iostream>
#include <tuple>
using namespace std;

auto main() -> int {
   auto datup = make_tuple(1, 2.0, 'C', "String");
   cout << tuple_size<decltype(datup)>::value;
   return 0;
}
```

<br/>

---
# Editorial

Untuk mengetahui besar atau banyaknya data pada tuple, memang panjang sintaksnya, seperti ini:

```cpp
tuple_size<decltype(nama_tupple)>::value
```