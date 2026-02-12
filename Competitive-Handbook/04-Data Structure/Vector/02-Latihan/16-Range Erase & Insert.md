---
obsidianUIMode: preview
note_type: latihan
latihan: Range Erase & Insert
sumber:
  - chatgpt.com
tags:
  - vector
  - data-structure
date_learned: 2025-08-25T19:55:00
---
---
# 1 | Range Erase & Insert

Kamu punya sebuah `vector<int> A` berisi `N` elemen.
Ada `Q` operasi, dengan dua jenis perintah:

1. `1 L R` → hapus elemen dari indeks `L` sampai `R` (**inklusif**).
2. `2 P X` → sisipkan elemen `X` di posisi `P`.

Setelah semua operasi selesai, cetak isi akhir dari vector.

**Contoh Input:**

```
N = 5
A = [1, 2, 3, 4, 5]
Q = 3
1 2 3
2 1 10
2 4 20
```

**Proses:**

* `1 2 3` → hapus indeks `2..3` → `[1, 4, 5]`
* `2 1 10` → insert `10` di indeks `1` → `[1, 10, 4, 5]`
* `2 4 20` → insert `20` di indeks `4` → `[1, 10, 4, 20, 5]`

**Output:**

```
1 10 4 20 5
```


👉 Hint Editorial:

* Untuk hapus range: gunakan `v.erase(v.begin() + L, v.begin() + R + 1);`
* Untuk insert: gunakan `v.insert(v.begin() + P, X);`
* Ingat, `erase` dan `insert` punya kompleksitas **O(N)** → kalau Q besar, bisa berat, tapi untuk latihan ini cukup.

<br/>

---
# 2 | Jawaban

Berikut adalah jawabanku yang sudah benar:

```cpp
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
   int n;
   cin >> n;
   vector<int> vec(n);

   for (auto& var : vec) {
      cin >> var;
   }

   int q;
   cin >> q;
   while (q--) {
      int a, b, c;
      cin >> a >> b >> c;

      if (a == 1) {
         vec.erase(vec.begin() + b - 1, vec.begin() + c);
      } else if (a == 2) {
         vec.insert(vec.begin() + b - 1, c);
      }
   }

   for (const auto& x : vec) {
      cout << x << " ";
   }
   return 0;
}

```

<br/>

---
# 3 | Editorial

Langsung fokus pada bagian penghapusan dengan `erase()` dan penyisipan dengan `insert()`. Jika diminta untuk menghapus satu elemen, maka kita hanya perlu mendapatkan iterator yang mengarah ke indexnya. Tapi karena soal meminta penghapusan berdasarkan rentang, yang dimulai dari `L` ke `R`, maka kita bisa menggunakan kode seperti ini:

```cpp
vec.erase(vec.begin() + b - 1, vec.begin() + c);
```

Inputan `L` dan `R`, menunjukan lokasi index secara 1-based index, sehingga harus dikurangi dengan 1 agar sesuai. Kita menggunakan 2 kali `vec.begin()` lalu ditambahkan dengan rentang `L` dan rentang `R`, sehingga semua elemen yang berada diantaranya termasuk dirinya sendiri, akan dihapus.

Setelah itu, vector akan menyusut, mengisi kekosongan dibagian dalamnya yang terbentuk karena operasi `erase()`.

Setelah itu, operasi insert dilakukan dengan menuju ke posisi index yang diperlukan, dengan cara `vec.begin() + b -1`, lalu sisipkan nilai yang ingin ditambahkan. Kodenya seperti ini:

```cpp
vec.insert(vec.begin() + b - 1, c);
```

Cara-cara diatas lebih simple dari yang kukira, karena aku berpikir bahwa harus melakukan operasi `find()` terlebih dahulu, ternyata jika yang diminta adalah indeksnya, maka cukup lakukan operasi sederhana seperti diatas.