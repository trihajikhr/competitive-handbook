---
obsidianUIMode: preview
note_type: latihan
latihan: Graph Strongly Connected
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - graph-basic
date_learned: 2025-08-18T16:35:00
---
---
# 1 | Graph Strongly Connected

Diberikan sebuah graph directed. Tugasmu adalah menentukan apakah graph directed tersebut adalah graph yang strongly connected. Jika iya, maka outputkan `YES`, dan jika tidak maka outputkan saja `NO`.


```ad-info
ℹ️ **Definisi:**

* Sebuah directed graph disebut **strongly connected** jika **untuk setiap pasangan node u dan v**, ada path dari `u → v` **dan** path dari `v → u`.
* Artinya, **setiap node bisa dijangkau dari setiap node lain** dengan memperhatikan arah edge.

**Perbedaan dengan weakly connected:**

* **Weakly connected:** arah edge diabaikan → graph undirected sementara cukup digunakan.
* **Strongly connected:** arah edge **harus diperhitungkan** → graph asli dan arah edge sangat penting.

---

ℹ️ **Cara mengecek strong connectivity**

1. Pilih satu node `s` sebagai starting point.
2. Jalankan DFS/BFS di graph asli dari `s`.

   * Tujuannya: cek apakah semua node bisa dijangkau dari `s` (forward reachability).
3. **Buat transpose graph** → semua arah edge dibalik.
4. **Jalankan DFS/BFS lagi di transpose dari `s`.**

   * Tujuannya: cek apakah semua node bisa dijangkau dari `s` di arah sebaliknya (backward reachability).
5. **Kesimpulan:**

   * Jika kedua DFS mencakup semua node → graph **strongly connected**.
   * Jika ada node yang tidak terjangkau di salah satu DFS → graph **tidak strongly connected**.

---

💡 **Catatan teknis:**

* Transpose graph penting untuk mengecek reachability arah sebaliknya.
* Kompleksitas tetap `O(V + E)` karena DFS hanya berjalan dua kali dan pembuatan transpose linear.
* Konsep ini adalah dasar sebelum belajar algoritma SCC seperti **Kosaraju** atau **Tarjan**.
```


<br/>

---
# 2 | Jawaban

Berikut adalah jawabanku yang sudah benar:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using VVI = vector<vector<int>>;
using VI = vector<int>;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void dfsRec(VVI& graph, VI& visited, int now) {
   visited[now] = 1;
   for (const auto& node : graph[now]) {
      if (!visited[node]) {
         visited[node] = 1;
         dfsRec(graph, visited, node);
      }
   }
}

auto isStronglyConnected(VVI& graph) -> bool {
   vector<int> visited(graph.size(), 0);
   dfsRec(graph, visited, 1);

   for (int i = 1; i < visited.size(); i++) {
      if (!visited[i]) {
         return false;
      }
   }

   // transpose graph
   vector<vector<int>> transpose(graph.size());
   for (int u = 1; u < graph.size(); u++) {
      for (const auto& node : graph[u]) {
         transpose[node].push_back(u);
      }
   }

   ranges::fill(visited, 0);

   dfsRec(transpose, visited, 1);

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

   if (isStronglyConnected(graph)) {
      cout << "YES";
   } else
      cout << "NO";
   return 0;
}
```

<br/>

---
# 3 | Editorial

## 3.1 | Tujuan

Program ini bertujuan untuk menentukan apakah sebuah directed graph **strongly connected**, yaitu setiap node bisa dijangkau dari setiap node lain sesuai arah edge.

## 3.2 | Alur Logika Program

1. **Membaca input**

   * Masukkan jumlah node `n` dan jumlah edge `m`.
   * Buat adjacency list `graph` untuk menyimpan semua edge.
   * Baca setiap edge `u → v` dan simpan di `graph[u]`.

2. **DFS pertama (Forward Reachability)**

   * Buat vector `visited` berukuran `n+1` untuk menandai node yang dikunjungi.
   * Jalankan `dfsRec(graph, visited, 1)` dari node 1.
   * Cek apakah semua node terkunjungi.

     * Jika ada node yang tidak terkunjungi → graph **tidak strongly connected**, hentikan program.

3. **Membuat Transpose Graph**

   * Buat adjacency list `transpose` berukuran `n+1`.
   * Untuk setiap edge `u → v` di graph asli, tambahkan `v → u` di transpose.
   * Tujuannya: untuk mengecek reachability di arah sebaliknya (backward reachability).

4. **DFS kedua (Backward Reachability)**

   * Reset `visited` menjadi semua 0.
   * Jalankan `dfsRec(transpose, visited, 1)` dari node yang sama.
   * Cek apakah semua node terkunjungi.

     * Jika ada node yang tidak terkunjungi → graph **tidak strongly connected**.

5. **Kesimpulan**

   * Jika kedua DFS mencakup semua node → graph **strongly connected**.
   * Jika ada node yang tidak terjangkau di salah satu DFS → graph **tidak strongly connected**.

## 3.3 | Hal Teknis Penting

* **DFS rekursif** digunakan untuk mengeksplorasi semua node yang terhubung dari node tertentu.
* **Transpose graph** wajib untuk mengecek backward reachability.
* Kompleksitas algoritma: `O(V + E)`

  * DFS pertama: `O(V + E)`
  * DFS kedua: `O(V + E)`
  * Pembuatan transpose: `O(E)`
* Konsep ini adalah dasar sebelum mempelajari algoritma SCC lebih canggih seperti Kosaraju atau Tarjan.

## 3.4 | Ringkasan

* **Strongly connected** → cek forward dan backward reachability.
* **Weakly connected** → cukup buat graph undirected sementara, arah edge tidak penting.
* Algoritma DFS + transpose sudah cukup untuk graph kecil sampai menengah.
