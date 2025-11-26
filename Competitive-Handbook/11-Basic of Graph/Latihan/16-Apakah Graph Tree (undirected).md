---
obsidianUIMode: preview
note_type: latihan
latihan: Apakah Graph Tree (undirected)
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - graph-basic
date_learned: 2025-08-18T17:54:00
---
---
# 1 | Apakah Graph Tree (undirected)

Diberikan sebuah graph undirected. Tugasmu adalah menentukan apakah graph yang diberikan merupakan graph tree atau tidak. Jika iya, maka cetak `YES`, jika tidak maka cetak `NO`.

```ad-info
**Definisi:**

Sebuah **undirected graph** disebut **tree** jika memenuhi tiga syarat:

1. **Connected** → semua node bisa dijangkau dari node manapun.
2. **Acyclic** → tidak ada cycle.
3. **Edge count** → jumlah edge = `n - 1`, di mana `n` adalah jumlah node.

> Intuisi: Tree itu semacam “jaringan cabang” tanpa lingkaran, dan selalu ada tepat satu jalur antara dua node.

---

**Cara Mengecek Tree (Undirected)**

1. **Cek jumlah edge**

   * Jika `m != n - 1`, langsung **bukan tree**.

2. **Cek connected**

   * Gunakan **DFS/BFS** mulai dari sembarang node.
   * Tandai node yang sudah dikunjungi (`visited`).
   * Setelah traversal, jika ada node yang tidak visited → **bukan tree**.

3. **Cek acyclic**

   * DFS untuk mendeteksi cycle:

     * Saat DFS ke node tetangga, jika ketemu node yang sudah visited **dan bukan parent** → ada cycle.
     * Kalau semua node visited tanpa ketemu kondisi di atas → graph acyclic.

4. **Kesimpulan**

   * Jika **jumlah edge = n-1** + **connected** + **acyclic** → **graph adalah tree**.
   * Kalau salah satu gagal → **bukan tree**.

---

💡 **Tips CP:**

* Gabungkan connected + acyclic dalam satu DFS untuk efisiensi.
* Edge count = n-1 bisa jadi shortcut cepat sebelum DFS.
* Tree undirected = dasar untuk banyak masalah: MST, diameter, LCA, dll.
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
using VI = vector<int>;
using VB = vector<bool>;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void dfsRec(VVI& graph, VB& visited, int now, int parent, bool& acycle) {
   if (!acycle)
      return;

   visited[now] = true;
   for (const auto& node : graph[now]) {
      if (!visited[node]) {
         dfsRec(graph, visited, node, now, acycle);
      } else if (node != parent) {
         acycle = false;
         return;
      }
   }
}

auto isTree(VVI& graph) -> bool {
   vector<bool> visited(graph.size(), false);
   bool acycle = true;
   dfsRec(graph, visited, 1, 1, acycle);
   if (acycle) {
      for (int i = 1; i < visited.size(); i++) {
         if (!visited[i]) {
            acycle = false;
            break;
         }
      }
   }
   return acycle;
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

   if (m != n - 1) {
      cout << "NO\n";
      cout << "Graph tidak memiliki edges yang sesuai!";
   } else {
      if (isTree(graph)) {
         cout << "YES\n";
         cout << "Graph adalah Tree!";
      } else {
         cout << "NO\n";
         cout << "Graph bukanlah Tree!";
      }
   }
   return 0;
}
```

<br/>

---
# 3 | Editorial

## 3.1 | Masalah

Diberikan sebuah **undirected graph** dengan `n` node dan `m` edge. Tugasnya adalah menentukan apakah graph tersebut **tree**.

**Tree (Undirected) harus memenuhi:**

1. Connected (semua node bisa dijangkau)
2. Acyclic (tidak ada cycle)
3. Edge count = n - 1

## 3.2 | Logika Program

1. **Edge Count Check**

   * Tree harus punya **n-1 edge**.
   * Jika `m != n-1`, langsung output **bukan tree** → ini shortcut cepat sebelum DFS.

2. **DFS untuk Connected + Acyclic**

   * **DFS traversal** mulai dari node `1` (atau node manapun).
   * Gunakan **visited array** untuk menandai node yang sudah dikunjungi.
   * Saat menelusuri tetangga:

     * Jika tetangga belum dikunjungi → lanjut DFS rekursif.
     * Jika tetangga sudah dikunjungi **dan bukan parent** → ketemu cycle → set flag `acycle = false`.
   * Setelah DFS selesai:

     * Jika ada node yang **tidak visited** → graph tidak connected → set flag `acycle = false`.

3. **Kesimpulan**

   * Jika semua kondisi terpenuhi (`edge = n-1`, connected, acyclic) → output **YES, tree**.
   * Jika gagal salah satu → output **NO, bukan tree**.

## 3.3 | Alur Algoritma

1. Baca `n` dan `m`, buat graph adjacency list.
2. Jika `m != n-1` → langsung **bukan tree**.
3. Lakukan DFS:

   * Tandai node visited
   * Cek cycle menggunakan parent node
4. Setelah DFS, cek apakah semua node visited → connected.
5. Gabungkan hasil cycle check + connected → tentukan apakah graph adalah tree.

## 3.4 | Catatan CP

* Menggabungkan **connected + acyclic** dalam satu DFS efisien dan cukup untuk CP.
* Edge count check sebelum DFS → optimasi cepat.
* Struktur ini bisa langsung dijadikan template untuk **masalah tree undirected lain**, misal diameter, LCA, MST.
