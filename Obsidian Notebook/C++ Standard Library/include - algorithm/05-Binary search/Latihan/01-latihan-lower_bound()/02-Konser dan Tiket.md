---
obsidianUIMode: preview
note_type: latihan
latihan: Konser dan Tiket
sumber:
  - chatgpt.com
tags:
  - STL
  - STL-algorithm
date_learned: 2025-08-15T17:29:00
---
---
# 1 | Konser dan Tiket

Diberikan daftar harga tiket konser yang sudah diurutkan menaik dan sejumlah calon pembeli. Setiap calon pembeli punya batas harga maksimum `X`.Untuk tiap pembeli, tentukan **indeks tiket termurah yang harganya ≥ X**.

Jika tidak ada tiket dengan harga ≥ X, cetak `-1`.

**Format Input:**

```
N Q
p1 p2 ... pN
x1
x2
...
xQ
```

* `N` = jumlah tiket (1 ≤ N ≤ 10⁵)
* `Q` = jumlah pembeli (1 ≤ Q ≤ 10⁵)
* `p1 … pN` = harga tiket (urut menaik)
* `xi` = batas harga minimum yang diminta pembeli ke-i

**Format Output:**
`Q` baris, masing-masing indeks (0-based) tiket yang sesuai, atau `-1` jika tidak ada.

#### Contoh 
Input:

```
5 3
50 100 150 200 250
120
50
300
```

Output:

```
2
0
-1
```

**Penjelasan:**

* Pembeli 1 (`X=120`) → tiket pertama ≥ 120 adalah 150 di indeks `2`.
* Pembeli 2 (`X=50`) → tiket pertama ≥ 50 adalah 50 di indeks `0`.
* Pembeli 3 (`X=300`) → tidak ada tiket ≥ 300 → `-1`.

<br/>

---
# 2 | Jawaban
## 2.1 | Jawaban Pertama

Berikut adalah jawabanku:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
   int n, k;
   cin >> n >> k;
   vector<int> cost(n), user(k);
   for (auto& x : cost) cin >> x;
   for (auto& x : user) cin >> x;

   for (int i = 0; i < k; i++) {
      int pos = ranges::lower_bound(cost, user[i]) - cost.begin();
      cout << (pos == n ? -1 : pos) << '\n';
   }

   return 0;
}
```

Kode diatas sebenarnya masih memiliki kekurangan, dimana jika array yang dimasukan tidak terurut, maka hasil yang dikeluarkan akan salah. Jadi, masih bisa dilakukan beberapa peningkatan.
## 2.2 | Jawaban Kedua

Lakukan pengamanan, dengan melakukan sorting ascending, sehingga hasil dari fungsi `lower_bound()` menjadi benar:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
   int n, k;
   cin >> n >> k;
   vector<int> cost(n), user(k);

   for (auto& x : cost) cin >> x;
   for (auto& x : user) cin >> x;
   ranges::sort(cost);

   for (int i = 0; i < k; i++) {
      int pos = ranges::lower_bound(cost, user[i]) - cost.begin();
      cout << (pos == n ? -1 : pos) << '\n';
   }

   return 0;
}
```

<br/>

---
# 3 | Editorial

Kode ini menerima input harga tiket (`cost`) dan permintaan harga minimum dari pembeli (`user`). 

Pertama, kita mengurutkan `cost` secara ascending karena `lower_bound` hanya bekerja pada data terurut. Kemudian, untuk setiap pembeli, kita memanggil `lower_bound` untuk mencari iterator ke elemen pertama dalam `cost` yang nilainya **lebih besar atau sama dengan** permintaan pembeli.  
Iterator hasil pencarian ini diubah menjadi indeks dengan operasi pengurangan `iterator - cost.begin()`.  

Jika indeks tersebut sama dengan `n` (panjang `cost`), berarti tidak ada tiket dengan harga ≥ permintaan pembeli, sehingga kita mencetak `-1`. Jika tidak, kita mencetak indeks tersebut.