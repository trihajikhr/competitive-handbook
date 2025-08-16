---
obsidianUIMode: preview
note_type: latihan
latihan: Tiket Konser dan Upper Bound
sumber:
  - chatgpt.com
tags:
  - STL
  - STL-algorithm
date_learned: 2025-08-15T20:26:00
---
---
# 1 | Tiket Konser dan Upper Bound

Kamu sedang membuat sistem untuk memproses daftar harga tiket konser yang sudah **terurut menaik**. Daftar ini berisi harga-harga unik (tidak ada duplikat). Setiap kali ada pembeli datang, mereka menyebutkan harga maksimum yang sanggup mereka bayar. Tugasmu adalah menemukan harga tiket **pertama yang lebih besar** daripada harga maksimum yang disebutkan pembeli. Jika tidak ada harga yang lebih besar, kembalikan indikator khusus (misalnya `-1`) yang berarti tiket tidak tersedia.

Contohnya, jika daftar harga adalah `100 200 300 400 500` dan pembeli bilang maksimal `250`, maka sistem harus mengembalikan `300`.

#### Input:

* Baris pertama berisi bilangan bulat `n` (jumlah tiket) dan `q` (jumlah pembeli).
* Baris kedua berisi `n` bilangan bulat terurut menaik, merepresentasikan harga tiket.
* `q` baris berikutnya masing-masing berisi satu bilangan bulat, harga maksimum yang sanggup dibayar pembeli.

#### Output:

* Untuk setiap pembeli, cetak harga tiket pertama yang **lebih besar** daripada harga yang dia sebutkan, atau `-1` jika tidak ada.

#### Contoh:

Input:

```
5 3
100 200 300 400 500 
100 465 800
```

Output:

```
200
500
-1
```

<br/>

---
# 2 | Jawaban

## 2.1 | Jawaban pertama

Berikut adalah jawaban yang sudah benar, namun masih bisa di efisiensikan dengan langsung mengatasi inputan tanpa harus menyimpanya di vector:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
   int n, q;
   cin >> n >> q;
   vector<int> price(n), user(q);
   for (auto& x : price) cin >> x;
   for (auto& x : user) cin >> x;

   ranges::sort(price);

   for (int i = 0; i < q; i++) {
      auto pos = ranges::upper_bound(price, user[i]);
      if (pos == price.end()) {
         cout << -1 << '\n';
      } else {
         cout << *pos << '\n';
      }
   }
   return 0;
}
```

## 2.2 | Jawaban kedua

Berikut adalah jawaban kedua yang mana kita tidak perlu membuat vector `user`, sehingga menjadi lebih efisien. Namun bagian editorial nanti akan menjelaskan jawaban pertama saja:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
   int n, q;
   cin >> n >> q;
   vector<int> price(n);
   for (auto& x : price) cin >> x;

   ranges::sort(price);

   for (int i = 0; i < q; i++) {
      int x;
      cin >> x;
      auto pos = ranges::upper_bound(price, x);
      if (pos == price.end()) {
         cout << -1 << '\n';
      } else {
         cout << *pos << '\n';
      }
   }
   return 0;
}
```

<br/>

---
# 3 | Editorial

`upper_bound()` akan mengembalikan iterator ke **elemen pertama** yang _lebih besar_ daripada nilai `val`.

Ada dua kondisi khusus yang perlu diperhatikan:

1. **Jika semua elemen dalam container lebih kecil atau sama dengan `val`**, maka `upper_bound()` akan mengembalikan `last` (atau `end()` pada container).
    
2. **Jika semua elemen lebih besar dari `val`**, maka iterator yang dikembalikan akan menunjuk ke elemen pertama (awal container).
    

Dalam kode ini, kita menggunakan `vector<int> price`. Setelah memanggil:

```cpp
auto pos = ranges::upper_bound(price, x);
```

- Jika `pos == price.end()`, artinya **tidak ada harga yang lebih besar** dari `x`, sehingga kita cetak `-1`.
    
- Jika tidak, artinya kita menemukan elemen yang lebih besar, dan karena `pos` adalah iterator, kita harus mendereferensikan (`*pos`) untuk mendapatkan nilainya sebelum mencetak.
    

Contoh:

```
price = [100, 200, 300, 400, 500]
x = 250  → upper_bound → menunjuk ke 300
x = 500  → upper_bound → menunjuk ke end() → cetak -1
x = 50   → upper_bound → menunjuk ke 100
```
