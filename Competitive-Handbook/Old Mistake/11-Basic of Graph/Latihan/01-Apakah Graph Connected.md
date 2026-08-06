---
obsidianUIMode: preview
note_type: latihan
latihan: Apakah Graph Connected
sumber:
  - myself
tags:
  - graph-algorithm
  - graph-basic
date_learned: 2025-08-16T16:12:00
---
---
# 1 | Apakah Graph Connected

Diberikan sebuah graph. Tugasmu adalah menentukan apakah graph yang diberikan adalah graph connected atau bukan. Jika connected, outputkan `YES`, jika tidak, outputkan `NO`.

```ad-info
Graf terhubung adalah graf di mana setiap pasangan simpul (vertex) di dalam graf tersebut terhubung oleh sebuah lintasan (path). Dengan kata lain, dari setiap simpul dalam graf, dimungkinkan untuk mencapai simpul lainnya melalui serangkaian sisi yang saling terhubung
```

<br/>

---
# 2 | Jawaban

Berikut adalah jawaban yang sudah benar:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using VVI = vector<vector<int>>;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void dfsRec(VVI& graph, vector<bool>& visited, int now) {
   for (const auto& A : graph[now]) {
      if (visited[A])
         continue;
      visited[A] = true;
      dfsRec(graph, visited, A);
   }
}

auto isConnected(VVI& graph) -> bool {
   vector<bool> visited(graph.size(), false);
   visited[1] = true;
   dfsRec(graph, visited, 1);

   for (int i = 1; i < visited.size(); i++) {
      if (!visited[i]) {
         return false;
      }
   }
   return true;
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

   for (auto& x : graph) {
      ranges::sort(x);
   }

   cout << (isConnected(graph) ? "YES" : "NO");
   return 0;
}
```

<br/>

---
# 3 | Editorial

## 3.1 | Problem Statement

Diberikan sebuah graph tak-berarah dengan `n` simpul (`1..n`) dan `m` sisi.  
Tugas: tentukan apakah graph tersebut **connected** — artinya, dari node 1 kita bisa mencapai semua node lainnya.

Output:

- `"YES"` jika graph connected
    
- `"NO"` jika tidak
    
## 3.2 | Observasi

- Sebuah graph disebut **connected** jika setiap simpul bisa dicapai dari simpul lain melalui serangkaian edge.
    
- Cukup cek dari **satu node awal** (misalnya node `1`).
    
    - Jika DFS/BFS dari node `1` bisa mengunjungi semua simpul, maka graph connected.
        
    - Jika ada simpul yang tidak terkunjungi, graph tidak connected.
        

## 3.3 | Algoritma

1. Bangun graph menggunakan **adjacency list**.
    
    - Ukuran: `n+1` supaya indexing dari `1..n`.
        
2. Lakukan **DFS** (Depth First Search) dari node `1`.
    
    - Tandai semua simpul yang dikunjungi (`visited[i] = true`).
        
3. Setelah DFS selesai, cek apakah ada simpul `i (1..n)` yang belum dikunjungi.
    
    - Jika ada, graph tidak connected.
        
    - Jika semua visited, graph connected.
        
## 3.4 | Kompleksitas

- Representasi adjacency list → `O(n + m)` memori.
    
- DFS mengunjungi tiap simpul & edge sekali → `O(n + m)` waktu.
    
- Mengecek visited → `O(n)`.
    
- Total kompleksitas: **`O(n + m)`**, efisien untuk input besar.

## 3.5 | Implementasi (DFS Rekursif)

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using VVI = vector<vector<int>>;

void dfsRec(VVI& graph, vector<bool>& visited, int now) {
    for (const auto& A : graph[now]) {
        if (visited[A]) continue;
        visited[A] = true;
        dfsRec(graph, visited, A);
    }
}

auto isConnected(VVI& graph, int n) -> bool {
    vector<bool> visited(n + 1, false);
    visited[1] = true;
    dfsRec(graph, visited, 1);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) return false;
    }
    return true;
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (auto& x : graph) {
        ranges::sort(x);
    }

    cout << (isConnected(graph, n) ? "YES" : "NO");
    return 0;
}
```

## 3.6 | Contoh Uji

**Input 1:**

```
4 3
1 2
2 3
3 4
```

**Proses:** DFS dari 1 mengunjungi semua node (1,2,3,4).  
**Output:**

```
YES
```

**Input 2:**

```
4 1
1 2
```

**Proses:** DFS dari 1 hanya mengunjungi node (1,2). Node 3 & 4 tidak terkunjungi.  
**Output:**

```
NO
```
