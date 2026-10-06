---
obsidianUIMode: preview
note_type: latihan
latihan: Tournament Esport
sumber:
  - chatgpt.com
tags:
  - STL
  - STL-algorithm
date_learned: 2025-08-16T02:06:00
---
---
# 1 | Tournament Esport

Di sebuah turnamen e-sports, setiap pemain mengumpulkan poin berdasarkan hasil pertandingan. Setelah turnamen selesai, panitia punya daftar poin semua pemain, dalam bentuk terurut ascending.

Sekarang, beberapa sponsor ingin tahu **berapa banyak pemain yang memiliki poin ≤ X** untuk nilai X tertentu. Kamu diminta menjawab pertanyaan ini **secepat mungkin** untuk banyak query.

#### Format Input:

* Baris pertama: `n` (jumlah pemain) dan `q` (jumlah pertanyaan sponsor).
* Baris kedua: `n` bilangan bulat, poin pemain, **sudah terurut menaik** (boleh ada duplikat).
* `q` baris berikutnya: masing-masing satu bilangan bulat `X`.

#### Format Output:

* Untuk setiap query, cetak jumlah pemain yang memiliki poin ≤ X.

#### Contoh:

```
Input:
6 4
10 20 20 30 40 50
5
20
35
60

Output:
0
3
3
6
```

**Petunjuk:**
Gunakan `upper_bound()` untuk menemukan **posisi pertama elemen yang lebih besar dari X**, lalu gunakan indeks posisi itu sebagai jumlah pemain yang memiliki poin ≤ X.


<br/>

---
# 2 | Jawaban

Ini adalah jawaban yang sudah benar:

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
      cout << pos - height.begin() << '\n';
   }

   return 0;
}
```

<br/>

---
# 3 | Editorial

Nah, ini udah bener untuk versi **menghitung jumlah elemen ≤ X** 👍

Penjelasannya begini:

* `ranges::upper_bound(height, x)` akan mengembalikan iterator ke **elemen pertama yang lebih besar dari x**.
* Karena `height` disimpan dalam `vector`, selisih `pos - height.begin()` akan memberi **jarak dari awal array**, alias jumlah elemen yang ≤ `x`.
* Output langsung jumlah tersebut.

Contoh jalannya program untuk input:

```
height = [10, 20, 20, 30, 40, 50]
x = 20
```

* `upper_bound` akan menunjuk ke elemen `30` (karena ini elemen pertama > 20).
* Posisi `30` adalah indeks ke-3 (0-based), sehingga `pos - height.begin()` = 3 → artinya ada **3 elemen** yang nilainya ≤ 20.
