---
obsidianUIMode: preview
note_type: latihan
latihan: Para Atlet
sumber:
  - chatgpt.com
tags:
  - STL
  - STL-algorithm
date_learned: 2025-08-16T01:57:00
---
---
# 1 | Para Atlet
Kamu mengelola daftar tinggi badan atlet dalam sebuah tim basket. Daftar ini **sudah terurut menaik** dan mungkin mengandung angka yang sama (boleh ada duplikat).

Suatu hari, pelatih ingin mencari pemain pertama yang memiliki tinggi **lebih besar** dari tinggi tertentu `h` yang dia sebutkan. Jika tidak ada pemain yang lebih tinggi, pelatih akan diberi laporan `-1`.
#### Input:

* Baris pertama: dua bilangan bulat `n` (jumlah atlet) dan `q` (jumlah permintaan pencarian).
* Baris kedua: `n` bilangan bulat terurut menaik, tinggi tiap atlet dalam cm.
* `q` baris berikutnya: masing-masing satu bilangan bulat `h` yang ingin dicari pelatih.

#### Output:

* Untuk setiap permintaan, cetak tinggi pemain pertama yang lebih besar dari `h`, atau `-1` jika tidak ada.

#### Contoh:

```
Input:
6 3
170 175 175 180 185 190
175
160
190

Output:
180
170
-1
```

<br/>

---
# 2 | Jawaban

Berikut adalah jawaban yang sudah benar:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
   int n, k;
   cin >> n >> k;
   vector<int> height(n);
   for (auto& x : height) cin >> x;

   for (int i = 0; i < k; i++) {
      int x;
      cin >> x;

      auto pos = ranges::upper_bound(height, x);
      if (pos == height.end()) {
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

Kita ingin mencari pemain pertama dengan tinggi **lebih besar** daripada `h`. Fungsi `upper_bound` mengembalikan iterator ke elemen pertama yang lebih besar dari nilai yang dicari.

Langkah di kode:

1. Membaca `n` (jumlah atlet) dan `k` (jumlah query).
2. Menyimpan tinggi badan atlet dalam `vector<int> height`.
3. Untuk setiap query `x`:

   * `auto pos = ranges::upper_bound(height, x);` mencari elemen pertama yang lebih besar dari `x`.
   * Jika `pos == height.end()`, artinya **tidak ada pemain yang lebih tinggi**, cetak `-1`.
   * Jika tidak, dereferensikan iterator dengan `*pos` untuk mendapatkan nilainya dan cetak.

Catatan: Karena soal menyebutkan data sudah terurut menaik, kita tidak perlu memanggil `sort()` lagi. Jika datanya belum tentu urut, `sort(height.begin(), height.end())` perlu dilakukan sebelum `upper_bound`.
