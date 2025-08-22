---
obsidianUIMode: preview
note_type: latihan
latihan: Regular Graph
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - graph-basic
date_learned: 2025-08-16T23:10:00
---
---
# 1 | Regular Graph

Diberikan sebuah graph tak berarah dengan **n** simpul dan **m** sisi. Tentukan apakah graph tersebut merupakan **regular graph**.

```ad-info
Sebuah graph disebut **regular** jika setiap simpul memiliki derajat (degree/edge) yang sama.
```

**Input:**

* Baris pertama berisi dua bilangan bulat `n` dan `m` — banyak simpul dan banyak sisi.
* Berikutnya terdapat `m` baris, masing-masing berisi dua bilangan bulat `u v` — menandakan terdapat sisi antara simpul `u` dan `v`.

**Output:**

* Cetak `YES` jika graph adalah regular.
* Cetak `NO` jika tidak.

**Contoh Input 1:**

```
4 4
1 2
2 3
3 4
4 1
```

**Contoh Output 1:**

```
YES
```

**Contoh Input 2:**

```
4 3
1 2
2 3
3 4
```

**Contoh Output 2:**

```
NO
```

<br/>

---
# 2 | Jawaban

Berikut adalah jawabanku yang sudah benar:

```cpp
#include <iostream>
#include <vector>
using namespace std;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

auto main() -> int {
   fastio();
   int n, m;
   cin >> n >> m;
   vector<vector<int>> graph(n + 1);

   for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;

      graph[u].push_back(v);
      graph[v].push_back(u);
   }

   bool regular = true;
   int pass = graph[1].size();
   for (int i = 1; i <= n; i++) {
      if (graph[i].size() != pass) {
         regular = false;
         break;
      }
   }

   cout << (regular ? "YES" : "NO");
   return 0;
}
```

<br/>

---
# 3 | Editorial


## 3.1 | Tujuan
Kita ingin menentukan apakah sebuah graph adalah *regular graph*.
Sebuah graph dikatakan *regular* jika setiap simpul memiliki derajat yang sama.


## 3.2 | Penjelasan per blok kode program
### 1. Inisialisasi dan Input

```cpp
#include <iostream>
#include <vector>
using namespace std;
```

Kita hanya membutuhkan dua header:

* `<iostream>` untuk input–output.
* `<vector>` untuk menyimpan adjacency list.

### 2. Fast I/O

```cpp
inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}
```

Fungsi ini mempercepat proses input dan output agar program lebih efisien.

### 3. Membaca Graph

```cpp
int n, m;
cin >> n >> m;
vector<vector<int>> graph(n + 1);

for (int i = 0; i < m; i++) {
   int u, v;
   cin >> u >> v;

   graph[u].push_back(v);
   graph[v].push_back(u);
}
```

* `n` = jumlah simpul, `m` = jumlah sisi.
* `graph` disimpan sebagai adjacency list.
* Setiap sisi `u–v` dimasukkan dua arah karena graph tidak berarah.

### 4. Mengecek Regular Graph

```cpp
bool regular = true;
int pass = graph[1].size();
for (int i = 1; i <= n; i++) {
   if (graph[i].size() != pass) {
      regular = false;
      break;
   }
}
```

* Ambil derajat simpul pertama sebagai patokan (`pass`).
* Bandingkan derajat semua simpul dengan `pass`.
* Jika ada perbedaan, berarti graph tidak regular.

### 5. Output Hasil

```cpp
cout << (regular ? "YES" : "NO");
```

* Cetak **YES** bila graph regular.
* Cetak **NO** bila tidak.


## 3.3 | Kesimpulan:

Algoritma ini berjalan dalam kompleksitas **O(n + m)**, cukup efisien untuk menentukan apakah sebuah graph regular atau tidak.

