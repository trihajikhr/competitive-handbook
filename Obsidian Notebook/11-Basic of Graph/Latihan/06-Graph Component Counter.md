---
obsidianUIMode: preview
note_type: latihan
latihan: Graph Component Counter
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - graph-basic
date_learned: 2025-08-17T02:20:00
---
---
# 1 | Graph Component Counter

Diberikan sebuah graph disconnected, atau tidak terhubung. Tugasmu adalah menghitung seberapa banyak komponen yang ada pada sebuah graph yang diberikan.

```ad-info
Bagian-bagian connected dari sebuah graf disebut components. Sebagai contoh, graf berikut mengandung tiga components: {$1,2,3$}, {$4,5,6,7$}, dan {$8$}.

![[06-Graph Component Counter-1.png]]
```

<br/>

---
# 2 | Jawaban

Berikut adalah jawaban yang sudah benar:

```cpp
#include <iostream>
#include <vector>
using namespace std;

using VVI = vector<vector<int>>;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void dfsSearch(VVI& graph, vector<bool>& visited, int now) {
   for (const auto& V : graph[now]) {
      if (!visited[V]) {
         visited[V] = true;
         dfsSearch(graph, visited, V);
      }
   }
}

auto components(VVI& graph) -> int {
   int val = 0;
   vector<bool> visited(graph.size());

   for (int i = 1; i < graph.size(); i++) {
      if (!visited[i]) {
         visited[i] = true;
         dfsSearch(graph, visited, i);
         val++;
      }
   }

   return val;
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

   cout << components(graph) << '\n';

   return 0;
}
```

<br/>

---
# 3 | Editorial

## 3.1 | Penjelasan per blok kode program
### 1. Struktur dasar

```cpp
using VVI = vector<vector<int>>;
```

Supaya gampang, `VVI` dipakai untuk adjacency list. Jadi `graph[u]` berisi semua tetangga dari simpul `u`.

### 2. DFS untuk menandai kunjungan

```cpp
void dfsSearch(VVI& graph, vector<bool>& visited, int now) {
   for (const auto& V : graph[now]) {
      if (!visited[V]) {
         visited[V] = true;
         dfsSearch(graph, visited, V);
      }
   }
}
```

Ini DFS klasik. Dari node `now`, kamu kunjungi semua tetangganya. Setiap kali nemu node yang belum dikunjungi, tandai `visited[V] = true` lalu lanjut DFS.

### 3. Fungsi menghitung komponen

```cpp
auto components(VVI& graph) -> int {
   int val = 0;
   vector<bool> visited(graph.size());

   for (int i = 1; i < graph.size(); i++) {
      if (!visited[i]) {
         visited[i] = true;
         dfsSearch(graph, visited, i);
         val++;
      }
   }
   return val;
}
```

Loop dari node `1 … n`.

* Kalau `visited[i] == false`, berarti kita ketemu komponen baru.
* DFS dijalankan untuk menandai semua node dalam komponen itu.
* Counter `val++` nambah 1.

Akhirnya `val` menyimpan **jumlah komponen terhubung**.

### 4. Main program

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
cout << components(graph) << '\n';
```

* Input graph dengan **n node** dan **m edge**.
* Disimpan pakai adjacency list.
* Hasil: jumlah komponen.
