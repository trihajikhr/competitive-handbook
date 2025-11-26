---
obsidianUIMode: preview
note_type: latihan
latihan: lower_bound
sumber:
  - chatgpt.com
tags:
  - STL
  - STL-algorithm
date_learned: 2025-08-15T17:00:00
---
---
# 1 | Mencari Posisi Siswa

Diberikan array terurut menaik berisi `N` bilangan bulat dan sebuah bilangan `X`. Tentukan indeks pertama (0-based) di mana `X` bisa ditempatkan agar urutan tetap terjaga. Jika `X` sudah ada, kembalikan indeks pertama kemunculannya.

### Contoh 1:

**Input:**

```
5 70
50 60 70 80 90
```

**Output:**

```
2
```

### Contoh 2:

**Input:**

```
5 75
50 60 70 80 90 
```

**Output:**

```
3
```




<br/>

---
# 2 | Jawaban

## 2.1 | Jawaban Pertama

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
   int n, k;
   cin >> n >> k;
   vector<int> vec(n);
   for (auto& x : vec) {
      cin >> x;
   }

   int pos = lower_bound(vec.begin(), vec.end(), k) - vec.begin();
   cout << pos;

   return 0;
}
```

Versi jawaban ini sudah benar, namun jika menggunakan C++ yang lebih modern, ada cara yang lebih singkat.

## 2.2 | Jawaban Kedua

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
   int n, k;
   cin >> n >> k;
   vector<int> vec(n);
   for (auto& x : vec) {
      cin >> x;
   }

   int pos = ranges::lower_bound(vec, k) - vec.begin();
   cout << pos;

   return 0;
}
```

dengan menggunakan `ranges`, penulisanya menjadi lebih singkat. Penjelasan tentang hal ini akan dijelaskan di bagian editorial.

<br/>

---
# 3 | Editorial

`ranges` berguna untuk membuat kita tidak perlu untuk mengetikan `vec.begin(), vec.end()`. Tapi apakah ketika kita menggunakan `ranges` disini, kita perlu menambahkan header `<ranges>`?

Jawabanya akan dijelaskan di bagian bawah. 

Ketika kita menuliskan ini:

```cpp
ranges::lower_bound(vec, k)
```

itu berarti kamu menggunakan **C++20 Ranges library**, yang deklarasinya ada di `<algorithm>` juga, **tapi** untuk versi `ranges` kamu perlu `#include <ranges>` **jika** nanti mau pakai fitur range adaptors (misalnya `vec | views::filter(...)`).

Untuk kasus ini, cukup:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>
```

tidak perlu `#include <ranges>` karena `ranges::lower_bound` memang didefinisikan di `<algorithm>` di namespace `std::ranges`.

---

📌 Ringkasnya:

* `std::lower_bound` → `<algorithm>`
* `std::ranges::lower_bound` → juga `<algorithm>` (C++20 ke atas)
* `#include <ranges>` → hanya diperlukan jika mau pakai adaptor seperti `views::filter`, `views::transform`, dsb.

Atau ringkasanya adalah seperti ini:

- **Kalau ada elemen yang sama dengan nilai yang dicari** → `lower_bound` kasih posisi **elemen pertama yang sama** (paling depan di blok nilai itu).
<br/>

- **Kalau nggak ada elemen yang sama** → kasih posisi **elemen pertama yang lebih besar** dari nilai itu (alias tepat setelah semua yang lebih kecil).
    

Jadi intinya: dia _selalu_ kasih posisi pertama di mana `val` bisa dimasukkan **tanpa merusak urutan**.
