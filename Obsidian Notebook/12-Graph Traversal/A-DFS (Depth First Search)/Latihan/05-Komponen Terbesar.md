---
obsidianUIMode: preview
note_type: latihan
latihan: Komponen Terbesar
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - graph-traversal
  - graph-DFS
date_learned: 2025-08-05T14:38:00
---
---
# Hitung Ukuran Komponen Terbesar

**Deskripsi:**  
Diberikan graph tak berarah dengan `n` simpul dan `m` sisi. Hitung ukuran komponen terhubung (_connected component_) yang paling besar.

**Format Masukan:**

```
n m  
u1 v1  
u2 v2  
...  
um vm
```

**Format Keluaran:**

```
Ukuran komponen terbesar
```

**Contoh Masukan:**

```
6 4  
1 2  
2 3  
4 5  
5 6
```

**Contoh Keluaran:**

```
3
```

**Catatan:**

- Komponen terbesar adalah `{4, 5, 6}` atau `{1, 2, 3}`, ukurannya 3.


<br/>

---
# Jawaban

Berikut adalah jawabanku:

```cpp
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

using VVI = vector<vector<int>>;
using VI = vector<int>;
using VB = vector<bool>;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void dfsSearch(VVI& graph, VI& rest, VB& visited, int now) {
   rest.push_back(now);

   for (const auto& V : graph[now]) {
      if (visited[V])
         continue;
      visited[V] = true;
      dfsSearch(graph, rest, visited, V);
   }
}

auto biggestComponents(VVI& graph, VI& rest) -> vector<int> {
   VB visited(graph.size(), false);
   VI temp;

   for (int i = 1; i < graph.size(); i++) {
      if (visited[i])
         continue;
      visited[i] = true;
      dfsSearch(graph, temp, visited, i);

      if (rest.size() < temp.size()) {
         rest = temp;
      }

      temp.clear();
   }

   return rest;
}

auto main() -> int {
   fastio();
   int n, m;
   cin >> n >> m;
   VVI graph(n + 1);
   VI rest;
   VB visited(n + 1, false);

   for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;

      graph[u].push_back(v);
      graph[v].push_back(u);
   }

   for (auto& x : graph) {
      ranges::sort(x);
   }

   rest = biggestComponents(graph, rest);

   cout << rest.size() << '\n';
   for (const auto& x : rest) {
      cout << x << " ";
   }
   return 0;
}
```

<br/>

---
# Editorial

Soal ini mudah, cukup cari komponen terbesar saja. Sehingga algoritma yang perlu digunakan adalah dengan melakukan perbandingan, apakah nilai dari `curr` lebih besar dari `rest`. Jika lebih besar, maka array `curr` baru saja menemukan komponen yang lebih besar, sehingga kita ambil datanya, dengan menyimpanya di `rest`. Tidak lupa juga bersihkan nilai dari `curr` setiap penggunaan.