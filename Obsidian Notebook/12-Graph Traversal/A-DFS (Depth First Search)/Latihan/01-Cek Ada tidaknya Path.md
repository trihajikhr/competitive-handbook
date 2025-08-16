---
obsidianUIMode: preview
note_type: latihan
latihan: Simple Path Check
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - graph-traversal
  - graph-DFS
date_learned: 2025-08-05T00:56:00
---
---
# Simple Path Check

Diberi graph tak berarah (undirected), cek apakah terdapat path dari node `x` ke `y`. 

Inputanya cukup sederhana, dimana terdapat `n` node dan `m` jalur, diikuti `m` baris yang terdiri dari pasangan node `u` dan `v` yang merepresentasikan keterhubungan. Baris terakhir terdiri dari dua inputan yaitu node awal dan node tujuan.

Latihan yang cukup sederhana untuk menerapkan DFS bukan?

### Contoh
Input:

```
20 12
1 2
2 3
3 1
4 5
5 6
7 8
8 7
9 10
11 12
13 14
15 16
17 18
4 5
```

Output:

```
Path ada!
```

Input:

```
20 12
1 2
2 3
3 1
4 5
5 6
7 8
8 7
9 10
11 12
13 14
15 16
17 18
4 18
```

Output:

```
Path tidak ada!
```

<br/>

---
# Jawaban

Berikut adalah jawabanku, yang masih bisa dioptimalkan lagi. Nanti baca di editorial:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
using VB = vector<bool>;
using VVI = vector<vector<int>>;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void dfsSearch(const VVI& graph, VB& visited, int now, int target, bool& found) {
   if (now == target) {
      found = true;
      return;
   }
   for (int v : graph[now]) {
      if (!visited[v]) {
         visited[v] = true;
         dfsSearch(graph, visited, v, target, found);
      }
   }
}

auto isHavePath(VVI& graph, int now, int target) -> bool {
   VB visited(graph.size(), false);
   visited[now] = true;
   bool found = false;
   dfsSearch(graph, visited, now, target, found);
   return found;
}

auto main() -> int {
   fastio();
   int n, m;
   cin >> n >> m;
   VVI graph(n + 1);
   VI rest;

   for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;

      graph[u].push_back(v);
      graph[v].push_back(u);
   }

   for (auto& x : graph) {
      ranges::sort(x);
   }

   int x, y;
   cin >> x >> y;
   bool found = isHavePath(graph, x, y);

   if (found)
      cout << "Path ada!";
   else
      cout << "Path tidak ada!";

   return 0;
}
```

<br/>

---
# Editorial

Ini adalah fungsi DFS nya:

```cpp
void dfsSearch(const VVI& graph, VB& visited, int now, int target, bool& found) {
   if (now == target) {
      found = true;
      return;
   }
   
   for (int v : graph[now]) {
      if (!visited[v]) {
         visited[v] = true;
         dfsSearch(graph, visited, v, target, found);
      }
   }
}
```

Kita mentraversal semua node dari graph dengan cara melakukan pengecekan node tetangga secara lurus terus-menerus. 

Setiap node yang sudah dikunjungi, akan ditandai dengan `visited[v] = true`, sehingga tidak dikunjungi dua kali. 

Tugas kita adalah mencari dan menentukan, apakah ada path dari node sekarang, ke node target. Jika semisal jalur ada, atau graph adalah graph connected, maka pasti node target ditemukan, menghasilkan `found` adalah `true`.

Tapi jika node target ternyata berada di graph terpisah, karena graph disconnected, maka target hanya akan ditemukan jika node awal berada di komponent yang sama dengan node target. Jika tidak, maka pasti tidak akan ada rute dari node awal ke node target, sehingga `found` akan tetap menjadi `false`.