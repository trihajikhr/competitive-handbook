---
obsidianUIMode: preview
note_type: latihan
latihan: Tiket Sekali Pakai
sumber:
  - codeforces
tags:
  - STL
  - STL-algorithm
date_learned: 2025-08-15T17:52:00
---
---
# 1 | Tiket Sekali Pakai

Sebuah panitia konser menjual `N` tiket, masing-masing dengan harga tertentu. Harga-harga tiket **tidak terurut**.

Ada `K` pembeli, masing-masing bersedia membeli **tiket termurah yang harganya ≥ harga minimum yang mereka mau**.

Setelah sebuah tiket terjual, tiket itu **tidak bisa dibeli lagi** oleh pembeli berikutnya.

Tugasmu adalah menentukan harga tiket yang dibeli masing-masing pembeli. Jika tidak ada tiket yang memenuhi permintaan pembeli, cetak `-1`.

#### Format Input

```
N K
p1 p2 ... pN
x1
x2
...
xK
```

* `N` (1 ≤ N ≤ 2×10⁵) = jumlah tiket.
* `K` (1 ≤ K ≤ 2×10⁵) = jumlah pembeli.
* `pi` (1 ≤ pi ≤ 10⁹) = harga tiket ke-i.
* `xi` (1 ≤ xi ≤ 10⁹) = harga minimum yang diminta pembeli ke-i.

#### Format Output
`K` baris, masing-masing harga tiket yang dibeli pembeli ke-i, atau `-1` jika tidak ada yang cocok.


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
150
50
-1
```

**Penjelasan**

* Pembeli 1 minta ≥ 120 → tiket termurah yang memenuhi adalah 150 → terjual.
* Pembeli 2 minta ≥ 50 → tiket termurah yang memenuhi (dari sisa tiket) adalah 50 → terjual.
* Pembeli 3 minta ≥ 300 → tidak ada tiket yang memenuhi → `-1`.

**Soal ini menguji:**

* Pemahaman `lower_bound` untuk mencari tiket yang sesuai.
* Menghapus elemen yang sudah dipakai (misalnya pakai `multiset` atau `ordered_set` / `set`).
* Efisiensi karena `N` dan `K` bisa sampai 2×10⁵.

<br/>

---
# 2 | Jawaban

## 2.1 | Jawaban Pertama
Berikut adalah jawabanku yang masih belum efektif, namun sengaja aku tulis supaya bisa membuat perbandingan nantinya:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
   int n, k;
   cin >> n >> k;
   vector<int> tiket(n), user(k);

   for (auto& x : tiket) cin >> x;
   for (auto& x : user) cin >> x;
   ranges::sort(tiket);
   ranges::sort(tiket);

   for (int i = 0; i < k; i++) {
      auto pos = ranges::lower_bound(tiket, user[i]);
      if (pos == tiket.end()) {
         cout << -1 << " ";
      } else {
         int idx = pos - tiket.begin();
         cout << tiket[idx] << " ";
         tiket[idx] = -1;
         ranges::sort(tiket);
      }
   }
   return 0;
}
```

Kenapa kode ini tidak efektif? Karena kita harus melakukan penyortiran pada vector `tiket`, setiap kali kita melakukan pencarian `lower_bound()`, jelas ini tidak efektif.

## 2.1 | Jawaban Kedua

```cpp
#include <iostream>
#include <set>
#include <vector>
using namespace std;

auto main() -> int {
   int n, k;
   cin >> n >> k;
   multiset<int> cost;
   vector<int> user(k);

   for (int i = 0, x; i < n; i++) {
      cin >> x;
      cost.insert(x);
   }

   for (auto& x : user) {
      cin >> x;
   }

   for (int i = 0; i < k; i++) {
      auto pos = cost.lower_bound(user[i]);
      if (pos == cost.end()) {
         cout << -1 << "\n";
      } else {
         cout << *pos << "\n";
         cost.erase(pos);
      }
   }
   return 0;
}
```

Ini adalah pendekatan yang lebih efisien, bagian ini akan dijelaskan dibagian editorial.
## 2.3 | Jawaban Ketiga

```cpp
#include <iostream>
#include <set>
using namespace std;

auto main() -> int {
   int n, k;
   cin >> n >> k;
   multiset<int> cost;

   for (int i = 0, x; i < n; i++) {
      cin >> x;
      cost.insert(x);
   }

   for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      auto pos = cost.lower_bound(x);
      if (pos == cost.end()) {
         cout << -1 << "\n";
      } else {
         cout << *pos << "\n";
         cost.erase(pos);
      }
   }
   return 0;
}
```

Bagian ini sebenarnya menghilangkan kebutuhan menerima inputan sebagai vector, dan langsung mencetak output untuk setiap inputan. Namun, untuk penjelasan yang lebih mudah dimengerti, akan digunakan kode jawaban pada nomor 2 saja.

<br/>

---
# 3 | Editorial

Alasan kenapa jawaban pertama tidak efisien sebenarnya berasal dari potongan kode ini:

```cpp
tiket[idx] = -1;
ranges::sort(tiket);
```

Setiap tiket yang dibeli, harusnya dihapus. Mekanisme ini bisa dilakukan dengan menggunakan sorting lagi, atau cara yang lebih baik yaitu dengan `erase` pada vector.

Namun kedua operasi tersebut memakan kompleksitas yang tinggi. Sorting sendiri memakan kompleksitas $O(n \log n)$, dan erase pada vector mengharuskan menggeser semua elemen disamping kanan ke kiri untuk mengisi slot yang kosong karena aksi penghapusan.

Sedangkan cara yang kugunakan diatas adalah dengan melakukan sorting, yang mana jelas tidak efektif. Ini bikin kompleksitas jadi **O(K × N log N)**.
### Solusi yang lebih efektif

Gunakan struktur data yang **selalu terurut** secara otomatis dan mendukung penghapusan cepat, misalnya:

- `multiset<int>` di C++
- atau `std::set` kalau tidak ada duplikat harga.

Dengan `multiset`:

- Insert tiket → O(log N)
- Cari harga dengan `lower_bound` → O(log N)
- Hapus tiket → O(log N)

Sehingga total kompleksitas: **O((N + K) log N)**, jauh lebih cepat.

### Menggunakan multiset
Oleh karena itu, kita menggunakan struktur data `multiset` untuk mengatasi hal ini, karena itu merupakan pendekatan yang lebih optimal.

Kelebihannya:

* **Tidak perlu sort ulang** tiap kali, karena `multiset` selalu terurut otomatis.
* `lower_bound()` di `multiset` langsung O(log N) untuk pencarian.
* `erase(pos)` di `multiset` juga O(log N).
* Total kompleksitas: **O((N+K) log N)**, aman untuk N, K sampai 2×10⁵.

Kalau mau lebih rapi, kamu bisa langsung baca `user[i]` di dalam loop tanpa simpan di `vector`, kecuali memang mau simpan untuk keperluan lain.

Misalnya:

```cpp
for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    auto pos = cost.lower_bound(x);
    if (pos == cost.end()) cout << -1 << "\n";
    else {
        cout << *pos << "\n";
        cost.erase(pos);
    }
}
```


