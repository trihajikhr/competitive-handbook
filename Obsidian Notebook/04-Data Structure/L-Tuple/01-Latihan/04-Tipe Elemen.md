---
obsidianUIMode: preview
note_type: latihan
latihan: Tipe Elemen
sumber:
  - chatgpt.com
tags:
  - data-structure
  - tuple
date_learned: 2025-08-03T15:05:00
---
---
# 1 | Tipe Elemen

Dengan tuple berikut:

```cpp
auto t = std::make_tuple(42, 3.14f, 'X');
```

Tugasmu:

1. Cetak nama tipe dari elemen ke-1 (`3.14f`) menggunakan `typeid(...)` dan `tuple_element`.

💡 Gunakan `typeid(...).name()` untuk mencetak nama tipe.


<br/>

---
# 2 | Jawaban

Berikut adalah jawaban yang benar, menampilkan semua tipe data yang ada didalam tuple:

```cpp
#include <iostream>
#include <tuple>
using namespace std;

auto main() -> int {
   tuple<int, float, char> datup;
   datup = make_tuple(42, 3.14, 'C');
   using a = tuple_element<0, decltype(datup)>::type;
   using b = tuple_element<1, decltype(datup)>::type;
   using c = tuple_element<2, decltype(datup)>::type;
   cout << typeid(a).name() << '\n';
   cout << typeid(b).name() << '\n';
   cout << typeid(c).name() << '\n';
   return 0;
}
```

<br/>

---
# 3 | Editorial

Program ini mendemonstrasikan cara mendapatkan tipe elemen di dalam `std::tuple` menggunakan `tuple_element`.

Pertama, dibuat tuple `datup` dengan tiga elemen: `int`, `float`, dan `char`. Kemudian, dengan `tuple_element<index, tuple_type>::type`, kita bisa mengekstrak tipe pada posisi tertentu. Misalnya, `tuple_element<0, decltype(datup)>::type` menghasilkan tipe elemen pertama (`int`). Hasil ini disimpan dengan `using` alias sebagai `a`, `b`, dan `c`.

Selanjutnya, program mencetak nama tipe tersebut dengan `typeid(...).name()`. Output bisa bervariasi tergantung compiler, tetapi inti tujuannya adalah menampilkan tipe asli masing-masing elemen tuple.

👉 Editorial singkat: `tuple_element` sangat berguna ketika kita ingin melakukan *metaprogramming* dengan tuple, misalnya menulis template yang bergantung pada tipe elemen di posisi tertentu.
