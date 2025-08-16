---
obsidianUIMode: preview
note_type: latihan
latihan: Cycle di Directed Graph
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - graph-traversal
  - graph-DFS
date_learned: 2025-08-05T19:47:00
---
---
# Cycle Detection (Directed)

Diberi graf **berarah** dengan `n` node dan `m` edge.  
Tentukan apakah graf mengandung **siklus**.

#### Input Format:

```
n m  
u1 v1  
u2 v2  
...  
um vm
```

- `1 ≤ n ≤ 10⁵`
    
- `1 ≤ m ≤ 2×10⁵`
    
- `1 ≤ ui, vi ≤ n`
    
#### Output Format:

```
YES
```

Jika ada siklus.

```
NO
```

Jika tidak ada

#### Contoh:

**Input:**

```
4 4
1 2
2 3
3 4
4 2
```

**Output:**

```
YES
```


<br/>

---
# Jawaban

Berikut adalah jawabanku yang sudah benar:

```cpp

#include <iostream>
#include <vector>
using namespace std;

using VVI = vector<vector<int>>;
using VI = vector<int>;

void dfs(VVI& graph, VI& status, bool& cycle, int u) {
   status[u] = 1;
   for (int v : graph[u]) {
      if (status[v] == 1)
         cycle = true;
      else if (status[v] == 0)
         dfs(graph, status, cycle, v);
   }
   status[u] = 2;
}

auto isCycle(VVI& graph) -> bool {
   int n = graph.size();
   VI status(n, 0);
   bool cycle = false;
   for (int i = 1; i < n; i++) {
      if (status[i] == 0)
         dfs(graph, status, cycle, i);
   }
   return cycle;
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

   cout << (isCycle(graph) ? "YES\n" : "NO\n");
}
```

<br/>

---
# Editorial

Diberikan sebuah _directed graph_ dengan `n` simpul dan `m` sisi, tentukan apakah terdapat minimal satu siklus di dalam graph tersebut.

#### Metode

Pendekatan dilakukan dengan **Depth-First Search (DFS)** menggunakan teknik **3-state coloring**, yaitu:

- `0`: simpul **belum dikunjungi**
    
- `1`: simpul **sedang dikunjungi** (masih di stack rekursif)
    
- `2`: simpul **telah selesai dikunjungi**
    

Selama DFS, jika ditemukan tetangga `v` dari `u` yang sudah berstatus `1` (masih dalam DFS stack), maka terdapat **back edge**, yang mengindikasikan adanya **siklus**.

#### Implementasi

```cpp
void dfs(VVI& graph, VI& status, bool& cycle, int u) {
   status[u] = 1;
   for (int v : graph[u]) {
      if (status[v] == 1) cycle = true;
      else if (status[v] == 0) dfs(graph, status, cycle, v);
   }
   status[u] = 2;
}
```

Prosedur ini dipanggil untuk setiap simpul yang belum dikunjungi, agar menjangkau semua komponen graf.

#### Kompleksitas

- Waktu: **O(n + m)** — setiap simpul dan sisi dikunjungi maksimal satu kali.
    
- Memori: **O(n + m)** — untuk representasi adjacency list dan array status.
    

#### Kesimpulan

Dengan teknik DFS 3-status, kita dapat secara efisien mendeteksi adanya siklus dalam directed graph. Teknik ini bersifat deterministik dan cocok untuk batas input besar.
