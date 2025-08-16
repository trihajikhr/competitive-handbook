---
obsidianUIMode: preview
note_type: latihan
latihan: Directed Graph Mencari Jalur
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - graph-DFS
  - graph-traversal
date_learned: 2025-08-05T15:12:00
---
---
# Apakah Bisa Mencapai Tujuan? (Directed Path Existence)

Diberikan sebuah graf berarah dengan `n` node (bernomor dari `0` sampai `n-1`) dan `m` edge. Setiap edge berupa arah dari node `u` ke node `v`.

Tentukan apakah ada **jalur** dari node `a` ke node `b` (bisa langsung atau melalui node lain).

#### Input Format:

```
n m
u1 v1
u2 v2
...
um vm
a b
```

- `1 ≤ n ≤ 10^5`
    
- `0 ≤ m ≤ 2×10^5`
    
- `0 ≤ ui, vi, a, b < n`
    

#### Output Format:

Cetak `YES` jika ada jalur dari `a` ke `b`, atau `NO` jika tidak ada.

#### Contoh Input:

```
5 4
1 2
2 3
3 4
4 5
1 5
```

#### Contoh Output:

```
YES
```


<br/>

---
# Jawaban

Berikut adalah jawabanya:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using VVI = vector<vector<int>>;
using VB = vector<bool>;

void dfsSearch(VVI& graph, VB& visited, int now, int target, bool& found) {
   if (now == target) {
      found = true;
      return;
   }

   for (auto& V : graph[now]) {
      if (visited[V])
         continue;
      visited[V] = true;
      dfsSearch(graph, visited, V, target, found);
   }
}

auto isHavePath(VVI& graph, int now, int target) -> bool {
   VB visited(graph.size(), false);
   bool found = false;

   visited[now] = true;
   dfsSearch(graph, visited, now, target, found);
   return found;
}

auto main() -> int {
   int n, m;
   cin >> n >> m;
   VVI graph(n + 1);

   for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      graph[u].push_back(v);
   }

   for (auto& x : graph) {
      ranges::sort(x);
   }

   int x, y;
   cin >> x >> y;

   bool rest = isHavePath(graph, x, y);
   if (rest) {
      cout << "YES\n";
   } else
      cout << "NO\n";

   return 0;
}
```

<br/>

---
# Editorial

Well, ini soal yang mudah, sama seperti soal nomor 1 mungkin. Perbedaanya adalah bahwa kita hanya menggunakan directed graph saja.

```cpp
for (int i = 0; i < m; i++) {
  int u, v;
  cin >> u >> v;
  graph[u].push_back(v);
}
```