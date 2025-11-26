---
obsidianUIMode: preview
note_type: latihan
latihan: Tuple as function Return
sumber:
  - chatgpt.com
tags:
  - data-structure
  - tuple
date_learned: 2025-08-03T16:09:00
---
---
# 1 | Tuple as function Return


Tugas:

1. Buat fungsi `getData()` yang mengembalikan `tuple<int, string, float>`.
    
2. Di `main()`, panggil `getData()`, lalu **destructuring** hasilnya ke tiga variabel dan cetak.

<br/>

---
# 2 | Jawaban

Berikut adalah jawabanku untuk menjawab tantangan ini:

```cpp
#include <iostream>
#include <tuple>
using namespace std;

#define get(i, a) get<i>(a)

auto getData(int t, const string& s, float f) -> tuple<int, string, float> { 
	return make_tuple(t, s, f); 
}

auto main() -> int {
   int t;
   string s;
   float f;
   cin >> t >> s >> f;

   auto datup = getData(t, s, f);
   auto [a, b, c] = datup;
   cout << a << " " << b << " " << c << "\n";
	return 0;
}
```

<br/>

---
# 3 | Editorial

Tentu saja kita bisa membuat fungsi yang mengembalikan tipe data berupa tuple. Hal ini juga bisa dimanfaatkan, jika semisal kita ingin membuat fungsi yang mengembalikan banyak data sekaligus.

Alih-alih membuat `struct` yang mungkin tidak perlu karena hanya digunakan sekali, kita bisa menggunakan `tuple` untuk membungkus kumpulan nilai kembalian. Lalu diterima dan didestructor dengan menggunakan `auto` seperti cara-cara sebelumnya;