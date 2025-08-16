---
obsidianUIMode: preview
note_type: latihan
latihan: Count Nodes Reachable
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - graph-DFS
  - graph-traversal
date_learned:
---
---
# Count Nodes Reachable

Diberikan graf **berarah** dengan `n` node (bernomor **1** sampai **n**) dan `m` edge.

Hitung berapa banyak node yang bisa dijangkau dari node `u` (termasuk dirinya sendiri).

#### Input Format:

```
n m
u1 v1
u2 v2
...
um vm
u
```

- `1 ≤ n ≤ 10^5`
    
- `1 ≤ m ≤ 2×10^5`
    
- `1 ≤ ui, vi, u ≤ n`
    

#### Output Format:

Satu bilangan bulat: jumlah node yang dapat dijangkau dari `u`.

#### Contoh Input:

```
6 5
1 2
1 3
2 4
4 5
3 6
1
```

#### Contoh Output:

```
6
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
using VI = vector<int>;

void dfsSearch(VVI& graph, VB& visited, int now, int& count) {
   count++;

   for (auto& V : graph[now]) {
      if (visited[V])
         continue;
      visited[V] = true;

      dfsSearch(graph, visited, V, count);
   }
}

auto countAdjacent(VVI& graph, int adj) -> int {
   VB visited(graph.size(), false);
   int count = 0;
   visited[adj] = true;
   dfsSearch(graph, visited, adj, count);
   return count;
}

auto main() -> int {
   int n, m;
   cin >> n >> m;
   VVI graph(n + 1);
   VI rest;

   for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      graph[u].push_back(v);
   }

   for (auto& x : graph) {
      ranges::sort(x);
   }

   int x;
   cin >> x;

   int count = countAdjacent(graph, x);
   cout << count << '\n';

   return 0;
}

```

<br/>

---
# Editorial

KIta cukup menghitung berapa kali fungsi `dfsSearch()` terpanggil, dengan menaruh increment `count` didalamnya.