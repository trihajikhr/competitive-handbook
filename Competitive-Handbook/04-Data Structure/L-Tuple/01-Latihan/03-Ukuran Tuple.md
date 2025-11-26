---
obsidianUIMode: preview
note_type: latihan
latihan: Ukuran Tuple
sumber:
  - chatgpt.com
tags:
  - data-structure
  - tuple
date_learned: 2025-08-03T14:56:00
---
---
# 1 | Ukuran Tuple


Diberikan tuple:

```cpp
auto t = std::make_tuple(1, 2.0, 'C', "text");
```

Tugasmu:

1. Cetak ukuran (jumlah elemen) dari tuple tersebut menggunakan `tuple_size`.

<br/>

---
# 2 | Jawaban

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
# 3 | Editorial

Ukuran sebuah `std::tuple` tidak dapat diperoleh secara langsung melalui metode anggota seperti `.size()`, karena `std::tuple` bukan kontainer runtime. Satu-satunya cara standar untuk mengetahui jumlah elemennya adalah dengan `std::tuple_size<T>::value`, di mana `T` merupakan tipe tuple yang diketahui pada waktu kompilasi.

Satu-satunya cara yang aman, standar, dan kompatibel di semua versi C++ (≥11) untuk mengetahui ukuran `std::tuple` adalah:

```cpp
std::tuple_size<decltype(t)>::value
```

Penjelasan formal singkat:

- `std::tuple_size<T>` adalah _class template_ khusus yang disediakan oleh `<tuple>`.
- Ia memiliki anggota statik `::value` bertipe `std::size_t`, yang menyimpan jumlah elemen dari tuple bertipe `T`.
- Evaluasinya terjadi pada waktu kompilasi, sehingga efisien dan bebas overhead runtime.
- Cara ini tetap aman bahkan untuk `const`, `volatile`, atau reference dari tuple.

Contoh lengkap:

```cpp
#include <tuple>
#include <iostream>
using namespace std;

auto main() -> int {
    tuple<int, char, double> t{10, 'Z', 3.14};

    constexpr size_t sz = tuple_size<decltype(t)>::value; 
    cout << "Ukuran tuple: " << sz << "\n";
}
```

Output:

```
Ukuran tuple: 3
```

> Kalau tujuannya mengetahui ukuran tuple dengan aman dan standar, cukup gunakan `std::tuple_size<decltype(tuple_name)>::value`.

Tidak ada cara lain yang lebih _idiomatic_ atau _portable_ dari ini. Ini adalah cara yang efisien, portabel, aman, dan standar untuk mengetahui ukuran dari tuple.