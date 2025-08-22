---
obsidianUIMode: preview
note_type: latihan
latihan: Graph Weakly Connected
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - graph-basic
date_learned: 2025-08-18T15:55:00
---
---
# 1 | Graph Weakly Connected

Diberikan sebuah graph directed. Tentukan apakah graph tersebut weakly connected atau tida. Jika iya, maka outputkan `YES`, jika tidak, outputkan `NO`.


```ad-info
**Definisi:**
Sebuah directed graph disebut **weakly connected** jika **mengabaikan arah edge**, semua node dengan setidaknya satu edge bisa dijangkau dari node lain.

* Dengan kata lain, jika kita mengubah semua edge menjadi **undirected**, graph menjadi **connected**.
* Perlu diingat: weak connectivity hanya berlaku untuk **directed graph**. Untuk **undirected graph**, kita cukup memeriksa connected/disconnected.

**Cara mengecek weak connectivity:**

1. Buat **graph undirected sementara** dari graph directed asli:

   * Untuk setiap edge `(u → v)`, tambahkan `(u – v)` dan `(v – u)` di adjacency list undirected.
2. Jalankan **DFS atau BFS** dari salah satu node yang memiliki edge.
3. Jika semua node yang memiliki edge ter-visit → graph **weakly connected**, jika tidak → graph disconnected.

**Catatan:**

* Node yang tidak memiliki edge sama sekali biasanya tidak mempengaruhi weak connectivity, karena DFS tidak akan mengunjunginya.
* Weakly connected tidak menjamin **strong connectivity**; arah edge tetap penting untuk definisi yang lebih ketat.
```





<br/>

---
# 2 | Jawaban

Berikut adalah jawabanku yang sudah benar:

```cpp
#include <iostream>
#include <vector>
using namespace std;

using VVI = vector<vector<int>>;
using VB = vector<bool>;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void dfsRec(VVI& graph, VB& visited, int now) {
   for (const auto& node : graph[now]) {
      if (!visited[node]) {
         visited[node] = true;
         dfsRec(graph, visited, node);
      }
   }
}

auto isWeakConnected(VVI& graph) -> bool {
   vector<bool> visited(graph.size(), false);

   // buat graph undirect sementara
   vector<vector<int>> undirect(graph.size());
   for (int u = 1; u < graph.size(); u++) {
      for (const auto& adj : graph[u]) {
         undirect[u].push_back(adj);
         undirect[adj].push_back(u);
      }
   }

   dfsRec(undirect, visited, 1);

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
   }

   if (isWeakConnected(graph)) {
      cout << "YES";
   } else
      cout << "NO";

   return 0;
}
```

<br/>

---
# 3 | Editorial

## 3.1 | Masalah yang diselesaikan

Program ini bertujuan untuk **menentukan apakah sebuah directed graph weakly connected**, yaitu jika semua node yang memiliki edge dapat dijangkau dari satu sama lain ketika arah edge diabaikan.

## 3.2 | Alur logika algoritma

1. **Input Graph Directed**

   * Baca jumlah node `n` dan edge `m`.
   * Untuk setiap edge `(u → v)`, tambahkan ke adjacency list `graph[u]`.

2. **Membuat Undirected Copy**

   * Buat graph sementara `undirect`.
   * Untuk setiap edge `(u → v)` di graph asli, tambahkan edge `u – v` dan `v – u` di `undirect`.
   * Tujuannya agar DFS bisa menjangkau semua node yang terhubung, **mengabaikan arah edge**.

3. **DFS Traversal**

   * Jalankan DFS dari satu node yang memiliki edge (misal node 1).
   * Tandai semua node yang ter-visit di vector `visited`.

4. **Cek Semua Node Terjangkau**

   * Iterasi semua node yang memiliki edge.
   * Jika ada node yang tidak ter-visit → graph **tidak weakly connected**.
   * Jika semua node ter-visit → graph **weakly connected**.

5. **Output**

   * Jika weakly connected → cetak `YES`.
   * Jika tidak → cetak `NO`.

## 3.3 | Insight Teknis

* **DFS Rekursif**

  * Memastikan traversal semua node yang bisa dijangkau.
  * Harus **memanggil DFS pada node tetangga**, bukan node saat ini.

* **Undirected Copy**

  * Sangat penting untuk weak connectivity.
  * Mengabaikan arah edge tapi tetap mempertahankan hubungan antar node.

* **Efisiensi**

  * Kompleksitas `O(V + E)`, karena setiap node dan edge dikunjungi maksimal sekali.
  * Cukup cepat untuk graph ukuran CP standar.

## 3.4 | Kesimpulan

Program ini merupakan latihan yang **sangat bagus sebelum mempelajari strong connectivity** atau SCC.

* Weak connectivity → arah edge **diabaikan**.
* Strong connectivity → arah edge **diperhitungkan**, lebih ketat.
