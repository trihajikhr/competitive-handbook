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
   tuple<int, char, double> t;
   t = make_tuple(7, 'B', 2.71);
   auto [a, b, c] = t;
   cout << a << " " << b << " " << c << "\n";
   return 0;
}
```

atau:

```cpp
#include <iostream>
#include <tuple>
using namespace std;

auto main() -> int {
   auto t = make_tuple(7, 'B', 2.71);
   auto [a, b, c] = t;
   cout << a << " " << b << " " << c << "\n";
   return 0;
}
```

<br/>

---
# 3 | Editorial

Cukup gunakan `auto` untuk melakukan pembongkaran pada tuple. Bisa juga menggunakan `tie()`. 

Keuntungan menggunakan `auto` adalah lebih modern, dan lebih mudah diaplikasikan, lebih mudah dipahami pemula. Sedangkan jika menggunakan `tie()`, kelebihanya adalah bisa mengabaikan data yang tidak ingin di destructure, caranya adalah dengan menyisipkan `ignore` pada saat penggunaan `tie()`.

Jika menggunakan `auto` sudah dicontohkan dibagian atas, maka berikut adalah contoh ketika kita menggunakan `tie()`:

```cpp
#include <iostream>
#include <tuple>
using namespace std;

auto main() -> int {
    tuple<int, char, float> t;
    t = make_tuple(7, 'B', 2.71);
    int a;
    char b;
    float c;
    tie(a,b,c) = t;
    cout << a << " " << b << " " << c << "\n";
    return 0;
}
```

Katakanlah, ingin mengambil hanya data pada indeks ke-$0$ dan data pada indeks ke-$2$, mengabaikan data indeks ke-$1$. Kita bisa saja menggunakan metode pengaksesan biasa, yaitu `get<>()`, namun karena kita sedang belajar destructuring tuple, kita tidak akan menggunakanya.

Jika menggunakan `auto`, tipe data penampung untuk destructuring tuple harus lengkap. Sehingga jika kita tidak ingin menggunakan data pada indeks tertentu dari tuple, maka variabel penampung tersebut akan berakhir tidak digunakan.

Solusinya adalah menggunakan `tie` dengan `ignore`, contohnya sebagai berikut:

```cpp
#include <iostream>
#include <tuple>
using namespace std;

auto main() -> int {
    tuple<int, char, float> t;
    t = make_tuple(7, 'B', 2.71);
    int a;
    float c;
    tie(a, ignore ,c) = t;  // mengabaikan indeks ke-1
    cout << a << " " << c << "\n";
    return 0;
}
```