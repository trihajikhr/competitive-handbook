---
obsidianUIMode: preview
note_type: latihan
latihan: Weighted Graph Banyak Jarak Terpendek yang Sama
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - shortest-path
date_learned: 2025-08-04T19:56:00
---
---
# Pengepungan Kastil Windvale

Kastil Windvale sedang dikepung oleh pasukan Orc dari seluruh penjuru negeri. Sang Pangeran, Ardyn, harus segera melarikan diri ke pos terdekat sebelum fajar menyingsing.

Negeri tersebut terdiri dari beberapa wilayah yang terhubung oleh jalan berbatu. Setiap jalan memiliki bobot tertentu, menggambarkan waktu tempuh (dalam menit). Ardyn ingin mencapai pos aman secepat mungkin, **tapi juga ingin tahu berapa banyak jalur berbeda** yang bisa ia ambil **dengan waktu minimum**.

Bantu Ardyn mencari:

1. **Waktu minimum** yang dibutuhkan untuk melarikan diri.
    
2. **Jumlah jalur berbeda** dari kastil ke pos aman **yang memiliki waktu tempuh minimum**.
    
#### Format Input:

Baris pertama berisi dua bilangan bulat `n` dan `m` — banyak wilayah dan banyak jalan (1 ≤ n ≤ 10⁵, 1 ≤ m ≤ 2×10⁵)

Selanjutnya terdapat `m` baris, masing-masing berisi tiga bilangan `u v w` — artinya ada jalan dari `u` ke `v` dengan waktu tempuh `w` (1 ≤ u, v ≤ n, 1 ≤ w ≤ 10⁹)

Baris terakhir berisi dua bilangan `s` dan `t` — posisi awal Ardyn dan lokasi pos aman.
#### Format Output:

Dua baris:

- Baris pertama: Banyaknya rute yang berbeda dan waktu tempuh minimum dari `s` ke `t`
    
- Baris kedua: Path yang memiliki jarak yang sama.
    
#### Contoh 

Input:

```
5 6
1 2 2
2 5 5
1 3 4
3 5 3
1 4 3
4 5 6
1 5
```

Output:

```
2 7
1 2 5 
1 3 5 
```

> Penjelasan:  
> Dua jalur dari 1 ke 5 dengan waktu 7:  
> `1 → 2 → 5` dan `1 → 3 → 5`


<br/>

---
# Jawaban

Berikut adalah jawabanku untuk menyelesaikan tantangan ini:

```cpp
#include <algorithm>
#include <climits>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

using VVT = vector<vector<tuple<int, int>>>;
using VI = vector<int>;
using VB = vector<bool>;
using VVI = vector<vector<int>>;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void dsfSearch(VVT& graph, VVI& rest, VB& visited, int now, int target, int& mins, int& count, int& total,
               int sumpath = 0, VI curr = {}) {
   curr.push_back(now);

   if (now == target) {
      if (rest.empty()) {
         rest.push_back(curr);
         total = mins = sumpath;
         count = 1;
      } else if (sumpath < mins) {
         rest.clear();
         rest.push_back(curr);
         total = mins = sumpath;
         count = 1;
      } else if (sumpath == mins) {
         rest.push_back(curr);
         count++;
      }
      return;
   }

   for (const auto& node : graph[now]) {
      auto [to, val] = node;
      if (!visited[to]) {
         sumpath += val;
         visited[to] = true;
         dsfSearch(graph, rest, visited, to, target, mins, count, total, sumpath, curr);
         visited[to] = false;
         sumpath -= val;
      }
   }
}

auto countShortest(VVT& graph, VVI& rest, int& now, int& target) -> pair<int, int> {
   VB visited(graph.size(), false);
   visited[now] = true;
   int count = 0;
   int mins = INT_MAX;
   int sumpath = 0;
   dsfSearch(graph, rest, visited, now, target, mins, count, sumpath);
   return {count, sumpath};
}

auto main() -> int {
   fastio();
   int n, m;
   cin >> n >> m;
   VVT graph(n + 1);
   VVI rest;

   for (int i = 1; i <= m; i++) {
      int u, v, w;
      cin >> u >> v >> w;

      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, w);
   }

   int x, y;
   cin >> x >> y;

   auto count = countShortest(graph, rest, x, y);

   if (count.first == 0) {
      cout << "no path!\n";
   } else {
      cout << count.first << " " << count.second << "\n";

      for (const auto& row : rest) {
         for (const auto& x : row) {
            cout << x << " ";
         }
         cout << '\n';
      }
   }

   return 0;
}

```

<br/>

---
# Editorial