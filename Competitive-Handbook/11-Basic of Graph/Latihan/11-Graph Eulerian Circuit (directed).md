---
obsidianUIMode: preview
note_type: latihan
latihan: Graph Eulerian Circuit (directed)
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - graph-basic
date_learned: 2025-08-17T23:47:00
---
---
# 1 | Graph Eulerian Circuit (directed)

Diberikan sebuah graph directed. Tugasmu adalah menentukan apakah graph yang diberikan adalah graph yang memiliki euler circuit. Jika iya, oututpkan `YES`, dengan menampilkan path nya, jika tidak, maka outputkan `NO`.

```ad-info
### Apa itu Eulerian Circuit

* **Eulerian circuit** adalah **jalur di graph yang mengunjungi setiap edge tepat satu kali** dan **kembali ke node awal**.
* Bukan cuma node, tapi **edge harus dilewati sekali saja**.

### Aturan Eulerian Circuit di Directed Graph

Agar sebuah **directed graph** memiliki Eulerian circuit, harus terpenuhi dua syarat:

1. **Indegree = Outdegree di setiap node**

   * Setiap node harus punya jumlah edge masuk (`indegree`) sama dengan jumlah edge keluar (`outdegree`).
   * Ini menjamin kalau kita masuk ke node tertentu, kita juga bisa keluar dan akhirnya kembali ke node awal.

2. **Graph Strongly Connected**

   * Semua node dengan degree > 0 harus **dapat dicapai dari node lain** (ada jalur ke dan dari setiap node).
   * Node isolasi (tanpa edge sama sekali) bisa diabaikan, karena tidak mempengaruhi jalur.

Jika kedua syarat di atas terpenuhi, graph directed **pasti punya Eulerian circuit** dan bisa dicari dengan algoritma seperti DFS rekursif (seperti yang kamu buat) atau Hierholzer.

Berikut adalah contoh graph directed yang memiliki euler circuit:

![[11-Graph Eulerian Circuit (directed)-1.png]]

Dimana path circuitnya: 1 -> 2 -> 1 -> 5 -> 4 -> 2 -> 3 -> 2 -> 4 -> 3 -> 4 -> 5 -> 1
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

using VVP = vector<vector<pair<int, int>>>;
using VI = vector<int>;
using VB = vector<bool>;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void getEulerCircuit(VVP& graph, VI& rest, VI& edgesID, int now, bool& stop) {
   if (stop) {
      return;
   }

   rest.push_back(now);

   if (rest.size() == edgesID.size()) {
      stop = true;
      return;
   }

   for (const auto& [node, id] : graph[now]) {
      if (edgesID[id]) {
         int temp = edgesID[id];
         edgesID[id] = 0;
         getEulerCircuit(graph, rest, edgesID, node, stop);
         edgesID[id] = temp;
         if (!stop) {
            rest.pop_back();
         }
      }
   }
}

auto eulerCircuit(VVP& graph, VI& edgesID) -> VI {
   vector<int> val;
   bool stop = false;
   int start = -1;
   for (int i = 1; i < graph.size(); i++) {
      if (!graph[i].empty()) {
         start = i;
         break;
      }
   }

   if (start != -1)
      getEulerCircuit(graph, val, edgesID, start, stop);
   else
      return {};
   return val;
}

void dfsRec(VVP& graph, VI& visited, int now) {
   visited[now] = 1;

   for (const auto& [node, stat] : graph[now]) {
      if (!visited[node]) {
         dfsRec(graph, visited, node);
      }
   }
}

auto isStronglyConnected(VVP& graph) -> bool {
   int start = -1;
   int n = graph.size() - 1;

   for (int i = 1; i < n; i++) {
      if (!graph[i].empty()) {
         start = i;
         break;
      }
   }

   // graph kosong dianggap strongly connected
   if (start == -1) {
      return true;
   }

   vector<int> visited(n + 1, 0);
   dfsRec(graph, visited, start);
   for (int i = 1; i <= n; i++) {
      if (!visited[i] && !graph.empty()) {
         return false;
      }
   }

   // bangun graph transpose
   vector<vector<pair<int, int>>> transpose(n + 1);
   for (int u = 1; u <= n; u++) {
      for (auto [v, id] : graph[u]) {
         transpose[v].emplace_back(u, id);
      }
   }

   ranges::fill(visited, 0);
   dfsRec(transpose, visited, start);
   for (int i = 1; i <= n; i++) {
      if (!visited[i] && !graph[i].empty()) {
         return false;
      }
   }

   return true;
}

auto main() -> int {
   fastio();
   int n, m;
   cin >> n >> m;
   vector<vector<pair<int, int>>> graph(n + 1);
   vector<int> edgesID(m + 1, 1);
   vector<int> indeg(n + 1, 0), outdeg(n + 1, 0);

   for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;

      outdeg[u]++;
      indeg[v]++;

      graph[u].emplace_back(v, i + 1);
   }

   bool pass = true;
   for (int i = 1; i <= n; i++) {
      if (indeg[i] != outdeg[i]) {
         pass = false;
         break;
      }
   }

   if (!pass) {
      cout << "NO\n";
      cout << "Indegree dan Outdegree tidak sama!";
   } else {
      if (isStronglyConnected(graph)) {
         // jika semua strongly connected
         for (int i = 1; i <= n; i++) {
            ranges::sort(graph[i], [](auto& a, auto& b) { 
	            return a.first < b.first; 
            });
         }

         cout << "YES\n";
         cout << "Indegree == Outdegree\n";
         cout << "Dan juga Strongly Connected\n";

         vector<int> rest = eulerCircuit(graph, edgesID);
         for (int i = 0; i < rest.size(); i++) {
            cout << rest[i];
            if (i != rest.size() - 1) {
               cout << " -> ";
            }
         }
      } else {
         cout << "NO\n";
         cout << "Graph tidak strongly connected!";
      }
   }

   return 0;
}
```

<br/>

---
# 3 | Editorial

## 3.1 | Masalah

Diberikan directed graph dengan `n` node dan `m` edge, temukan **Eulerian circuit** jika ada.

* Eulerian circuit: jalur yang **mengunjungi setiap edge tepat satu kali** dan kembali ke node awal.

## 3.2 | Syarat Eulerian Circuit (Directed Graph)

1. **Indegree = Outdegree** di setiap node.
2. Graph **strongly connected** (semua node dengan degree > 0 bisa dicapai dari node lain).

   * Node isolasi (tanpa edge) bisa diabaikan.

## 3.3 | Alur Logika Program

1. **Input Graph**

   * Baca jumlah node `n` dan edge `m`.
   * Buat adjacency list `graph[u]` untuk menyimpan pasangan `(v, edgeID)`.
   * Hitung `indegree` dan `outdegree` untuk setiap node.

2. **Cek Syarat Indegree = Outdegree**

   * Iterasi semua node, pastikan `indegree[i] == outdegree[i]`.
   * Jika ada node yang tidak memenuhi → **tidak ada Eulerian circuit** → output NO.

3. **Cek Strong Connectivity**

   * Jalankan DFS dari node awal dengan degree > 0.
   * Pastikan semua node dengan edge dapat dijangkau.
   * Buat **transpose graph** dan jalankan DFS lagi untuk mengecek reachability balik.
   * Jika gagal → **tidak ada Eulerian circuit** → output NO.

4. **Bangun Eulerian Circuit (DFS Backtracking)**

   * Mulai dari node awal, lakukan DFS:

     * Push node ke `rest` (jalur sementara).
     * Cek semua edge yang belum digunakan (`edgesID[id] == 1`).
     * Tandai edge digunakan (`edgesID[id] = 0`) dan rekursi ke node tujuan.
     * Jika semua edge sudah dilewati, set `stop = true` → jalur selesai.
     * Kalau DFS backtrack, pop node dari `rest` jika `stop == false`.

5. **Output Jalur**

   * Cetak `rest` → berisi **Eulerian circuit lengkap**.
   * Jalur sesuai urutan node saat DFS traversal.

## 3.4 |  Catatan Implementasi

* **Stop flag** memastikan DFS berhenti begitu circuit lengkap → `rest` tetap utuh.
* **Pop-back** hanya terjadi saat backtracking, menjaga urutan jalur saat DFS gagal di branch tertentu.
* **Node isolasi** tidak mengganggu, karena tidak memiliki edge → tidak masuk jalur.
* Bisa sort adjacency list kalau ingin jalur **lexicographically smallest**.

### 3.5 | Kesimpulan

* Program mengecek **syarat Eulerian circuit**, kemudian membangunnya dengan DFS rekursif + backtracking.
* Untuk graph yang **indegree=outdegree + strongly connected**, algoritma **selalu menghasilkan Eulerian circuit valid**.
* Metode ini cocok untuk latihan dan eksperimen DFS, walau untuk graph besar bisa lebih efisien pakai **Hierholzer**.

