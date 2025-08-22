---
obsidianUIMode: preview
note_type: latihan
latihan: Apakah Graph Tree (directed)
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - graph-basic
date_learned: 2025-08-18T18:08:00
---
---
# 1 | Apakah Graph Tree (directed)

Diberikan sebuah graph directed. Tugasmu adalah menentukan apakah graph yang diberikan merupakan graph tree atau tidak. Jika iya, maka outputkan `YES`, dan jika tidak maka ouputkan saja `NO`.

```ad-info
**Definisi:**

Sebuah **directed graph** disebut **tree (arborescence)** jika memenuhi semua syarat berikut:

1. **Hanya satu root** → ada tepat satu node tanpa parent (`indegree = 0`).
2. **Setiap node selain root memiliki tepat satu parent** (`indegree = 1`).
3. **Acyclic** → tidak ada cycle di graph.
4. **Connected dari root** → semua node bisa dicapai dari root.

> Intuisi: Tree directed = seperti cabang pohon dari root, semua node hanya punya satu jalur dari root, dan tidak ada loop.

---

**Cara Mengecek Directed Tree**

1. **Root check**

   * Hitung `indegree` setiap node.
   * Pastikan **hanya satu node dengan indegree = 0**.
   * Semua node lain harus punya `indegree = 1`.

2. **Cycle check**

   * DFS dari root dengan **recursion stack (`inStack`)**.
   * Jika DFS ketemu node yang sudah ada di `inStack` → ada cycle → **bukan tree**.

3. **Connected check**

   * Setelah DFS, semua node harus **visited** → graph connected dari root.

4. **Kesimpulan**

   * Jika root valid + acyclic + connected → **graph adalah directed tree**.
   * Jika gagal salah satu → **bukan directed tree**.

---

💡 **Tips CP:**

* Gabungkan connected + cycle check dalam satu DFS untuk efisiensi.
* Root check bisa dilakukan sebelum DFS → cepat untuk memutuskan **bukan tree** jika gagal.
* Struktur ini berguna untuk masalah: **topological sort, DP di tree, atau struktur hierarki**.
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
using VI = vector<int>;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void dfsRec(VVI& graph, VB& visited, VB& inStack, int now, bool& acycle) {
   if (!acycle)
      return;

   visited[now] = true;
   inStack[now] = true;

   for (const auto& next : graph[now]) {
      if (!visited[next]) {
         dfsRec(graph, visited, inStack, next, acycle);
      } else if (inStack[next]) {
         acycle = false;
         return;
      }
   }
}

auto isTree(VVI& graph, int startNode) -> bool {
   vector<bool> visited(graph.size(), false), inStack(graph.size(), false);
   bool acycle = true;
   dfsRec(graph, visited, inStack, startNode, acycle);

   for (int i = 1; i < visited.size(); i++) {
      if (!visited[i]) {
         return false;
      }
   }

   return acycle;
}

auto main() -> int {
   fastio();
   int n, m;
   cin >> n >> m;
   vector<vector<int>> graph(n + 1);
   vector<int> indeg(n + 1), outdeg(n + 1);
   bool root = false;
   int startRoot = -1;

   for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;

      outdeg[u]++;
      indeg[v]++;

      graph[u].push_back(v);
   }

   for (int i = 1; i <= n; i++) {
      if (indeg[i] == 0) {
         if (!root) {
            root = true;
            startRoot = i;
         } else {
            root = false;
            break;
         }
      }

      if (indeg[i] > 1) {
         root = false;
         break;
      }
   }

   if (!root) {
      cout << "NO\n";
      cout << "Graph bukan tree, karena root tidak sesuai!";
   } else {
      if (isTree(graph, startRoot)) {
         cout << "YES\n";
         cout << "Graph merupakan graph tree!";
      } else {
         cout << "NO\n";
         cout << "Bukan merupakan graph tree\n";
      }
   }

   return 0;
}
```

<br/>

---
# 3 | Editorial

## 3.1 | Masalah

Diberikan sebuah **directed graph** dengan `n` node dan `m` edge. Tugasnya adalah menentukan apakah graph tersebut **directed tree (arborescence)**.

**Syarat directed tree:**

1. Ada **tepat satu root** (`indegree = 0`)
2. Semua node lain memiliki **tepat satu parent** (`indegree = 1`)
3. Graph **acyclic**
4. Semua node bisa dicapai dari root (**connected dari root**)

## 3.2 | Logika Program

1. **Hitung indegree setiap node**

   * Root → node dengan `indegree = 0`
   * Pastikan **hanya satu root**
   * Pastikan semua node lain memiliki `indegree = 1`

2. **DFS untuk cycle detection + connected check**

   * Lakukan DFS dari root
   * Gunakan `visited` untuk menandai node yang sudah dikunjungi
   * Gunakan `inStack` untuk mendeteksi cycle:

     * Jika DFS menemui node yang sudah ada di `inStack` → ada cycle → **bukan tree**
   * Setelah DFS selesai:

     * Semua node harus **visited** → connected dari root
     * Flag `acycle` harus `true` → tidak ada cycle

3. **Kesimpulan**

   * Jika root valid + connected + acyclic → output **YES, directed tree**
   * Jika salah satu gagal → output **NO, bukan directed tree**

## 3.3 | Alur Algoritma

1. Baca input `n` dan `m` → buat **adjacency list**
2. Hitung **indegree** setiap node

   * Tentukan root, cek validitas indegree
3. Lakukan **DFS dari root**:

   * Tandai node visited
   * Gunakan `inStack` untuk cycle detection
4. Setelah DFS, cek:

   * Semua node visited → connected
   * Tidak ada cycle (`acycle = true`)
5. Gabungkan hasil → tentukan apakah **graph adalah directed tree**

## 3.4 | Catatan CP

* **Root check** sebelum DFS → optimasi cepat
* DFS menggabungkan **connected + acyclic check** → efisien
* Struktur ini bisa langsung dijadikan **template CP** untuk masalah hierarki, topological sort, atau DP di tree directed
