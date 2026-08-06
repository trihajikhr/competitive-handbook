---
obsidianUIMode: preview
note_type: latihan
latihan: Graph Eulerian Path (directed)
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - graph-basic
date_learned: 2025-08-18T15:43:00
---
---
# 1 | Graph Eulerian Path (directed)

Diberikan sebuah graph directed. Tugasmu adalah menetukan apakah graph yang diberikan adalah graph yang memiliki euler path. Jika ada, maka outputkan `YES` dengan pathnya, dan jika tidak maka outputkan `NO` dengan alasanya.

```ad-info
**Euler Path** adalah sebuah **jalur dalam graph** yang melewati **setiap edge tepat sekali**, tanpa harus kembali ke node awal. Jika jalur ini kembali ke node awal, jalur tersebut disebut **Euler Circuit** atau **Eulerian Cycle**.

Untuk **directed graph**, agar sebuah Euler Path ada, graph harus memenuhi kondisi berikut:

1. **Degree Condition (Indegree dan Outdegree):**

   * Setiap node harus memiliki **indegree = outdegree**, kecuali maksimal dua node:

     * **Start node:** node dengan `outdegree = indegree + 1` → titik awal Euler Path.
     * **End node:** node dengan `indegree = outdegree + 1` → titik akhir Euler Path.
   * Semua node lainnya harus memiliki `indegree = outdegree`.

2. **Weak Connectivity:**

   * Graph harus **weakly connected**, artinya jika kita mengabaikan arah edge, semua node dengan edge harus terhubung menjadi satu komponen.
   * Ini memastikan jalur dapat menjangkau semua edge dalam satu traversal tanpa “terputus”.

Dengan kedua kondisi ini terpenuhi, sebuah directed graph memiliki **Euler Path**. Algoritma seperti **DFS backtracking** atau **Hierholzer** dapat digunakan untuk menemukan jalurnya.
```




<br/>

---
# 2 | Jawaban

Berikut adalah jawabanya:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using VVP = vector<vector<pair<int, int>>>;
using VI = vector<int>;
using VB = vector<bool>;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void dfsConnect(VVP& graph, VB& visited, int now) {
   for (const auto& [node, id] : graph[now]) {
      if (!visited[node]) {
         visited[node] = true;
         dfsConnect(graph, visited, node);
      }
   }
}

auto isConnected(VVP& graph) -> bool {
   vector<bool> visited(graph.size(), false);
   int components = 0;

   // bangung graph undirected sementara untuk cek weak connectivity
   vector<vector<pair<int, int>>> undirect(graph.size());
   for (int u = 1; u < graph.size(); u++) {
      for (const auto& [node, id] : graph[u]) {
         undirect[u].emplace_back(node, id);
         undirect[node].emplace_back(u, id);
      }
   }

   dfsConnect(undirect, visited, 1);
   for (int i = 1; i < visited.size(); i++) {
      if (!visited[i]) {
         return false;
      }
   }

   return true;
}

void dfsEulerPath(VVP& graph, VI& path, VI& edgesID, int now, bool& stop) {
   if (stop)
      return;

   path.push_back(now);

   if (path.size() == edgesID.size()) {
      stop = true;
      return;
   }

   for (const auto& [node, id] : graph[now]) {
      if (edgesID[id]) {
         int temp = edgesID[id];
         edgesID[id] = 0;
         dfsEulerPath(graph, path, edgesID, node, stop);
         edgesID[id] = temp;
         if (!stop) {
            path.pop_back();
         }
      }
   }
}

auto getEulerPath(VVP& graph, VI& edgesID, int startIdx) -> VI {
   vector<int> path;
   bool stop = false;

   dfsEulerPath(graph, path, edgesID, startIdx, stop);

   return path;
}

auto main() -> int {
   fastio();
   int n, m;
   cin >> n >> m;

   vector<vector<pair<int, int>>> graph(n + 1);
   vector<int> edgesID(m + 1, 1);
   vector<int> indeg(n + 1), outdeg(n + 1);

   for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;

      outdeg[u]++;
      indeg[v]++;

      graph[u].emplace_back(v, i + 1);
   }

   int start = 0, end = 0, startIdx = -1;
   for (int i = 1; i <= n; i++) {
      if (outdeg[i] - indeg[i] == 1) {
         start++;
         startIdx = i;
      } else if (indeg[i] - outdeg[i] == 1) {
         end++;
      } else if (indeg[i] != outdeg[i]) {
         start = -1;
         end = -1;
         break;
      }
   }

   if ((start == -1 || end == -1) || !((start == 1 && end == 1) || (start == 0 && end == 0))) {
      cout << "NO\n";
      cout << "Graph tidak memiliki degre node yang sesuai!";
   } else {
      if (isConnected(graph)) {
         cout << "YES\n";
         vector<int> rest = getEulerPath(graph, edgesID, startIdx);
         for (int i = 0; i < rest.size(); i++) {
            cout << rest[i] << " ";
            if (i != rest.size() - 1) {
               cout << " -> ";
            }
         }
      } else {
         cout << "NO\n";
         cout << "Graph disconnected!";
      }
   }

   return 0;
}
```

<br/>

---
# 3 | Editorial

## 3.1 | Masalah yang diselesaikan

Tujuan dari kode ini adalah **menentukan apakah sebuah directed graph memiliki Euler Path**, dan jika ada, **menemukan jalurnya**. Jalur Euler Path harus melewati **setiap edge tepat satu kali**.

## 3.2 | Alur logika algoritma

1. **Membaca graph dan menghitung degree**

   * Input dibaca untuk setiap edge `(u → v)`.
   * Untuk setiap node dihitung:

     * **outdegree** → jumlah edge keluar dari node.
     * **indegree** → jumlah edge masuk ke node.

2. **Memeriksa kondisi degree untuk Euler Path**

   * Node-node graph diperiksa:

     * Node dengan `outdegree = indegree + 1` → kandidat **start node**.
     * Node dengan `indegree = outdegree + 1` → kandidat **end node**.
     * Node lain harus memiliki `indegree = outdegree`.
   * Jika kondisi ini tidak terpenuhi → **graph tidak memiliki Euler Path**.

3. **Memeriksa weak connectivity**

   * Graph dibuat versi **undirected sementara** dengan menambahkan edge balik `(v → u)` untuk setiap edge `(u → v)`.
   * DFS dijalankan untuk mengecek apakah semua node dengan edge bisa dijangkau → memastikan **weak connectivity**.
   * Jika graph disconnected → **tidak ada Euler Path**.

4. **Menemukan Euler Path (DFS backtracking)**

   * Jika graph memenuhi kondisi degree dan connected, DFS backtracking dijalankan:

     * Menyimpan jalur node dalam vector `path`.
     * Setiap edge dicatat di `edgesID` untuk menandai apakah sudah dipakai.
     * DFS mencoba semua edge yang tersedia dari node saat ini, melakukan backtrack jika jalur tidak lengkap.
   * Setelah semua edge digunakan → `path` berisi **Euler Path**.

5. **Output**

   * Jika Euler Path ada → dicetak urutan node yang dilalui.
   * Jika tidak → dicetak pesan alasan (degree mismatch atau graph disconnected).

## 3.3 | Insight teknis

* **Edge ID**:

  * Setiap edge diberi ID unik agar bisa menandai apakah sudah dipakai dalam DFS.
* **Backtracking DFS**:

  * Berguna untuk menemukan path secara eksplisit, tapi bersifat eksponensial untuk graph besar.
  * Latihan bagus untuk memahami Euler Path sebelum menggunakan algoritma efisien seperti **Hierholzer**.
* **Weak Connectivity via undirected copy**:

  * Menambahkan edge balik `(v → u)` memungkinkan DFS menjangkau semua node tanpa tergantung arah asli edge.
  * Pastikan tidak mengakses adjacency list secara langsung dari node tujuan (tidak ada edge balik di graph asli), agar aman dari out-of-bounds.

## 3.4 | Kesimpulan

* Kode ini sudah mencakup **semua langkah penting** untuk memvalidasi dan menemukan Euler Path pada directed graph:

  1. Cek degree condition.
  2. Cek weak connectivity.
  3. DFS backtracking untuk menemukan path.
* Konsep ini adalah dasar yang bagus sebelum melangkah ke versi yang lebih efisien seperti **Hierholzer**.

