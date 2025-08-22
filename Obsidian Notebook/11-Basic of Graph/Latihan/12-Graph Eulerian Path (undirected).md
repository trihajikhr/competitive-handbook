---
obsidianUIMode: preview
note_type: latihan
latihan: Graph Eulerian Path (undirected)
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - graph-basic
date_learned: 2025-08-17T22:04:00
---
---
# 1 | Graph Eulerian Path (undirected)

Diberikan sebuah graph undirected. Tugasmu adalah menentukan apakah graph yang diberikan adalah graph yang memiliki eulerian path. Jika ada, maka cetak `YES` dan juga path nya, dan jika tidak maka cetak `NO`.

```ad-info
**Eulerian Path** adalah sebuah lintasan (path) dalam graph yang melewati **setiap edge tepat satu kali**.

Ciri penting:

* **Path** berarti boleh mengunjungi simpul (node) lebih dari sekali, asalkan edge yang dipakai berbeda.
* Jadi, fokus utamanya bukan “kunjungi semua simpul”, melainkan **gunakan semua edge tanpa ada yang terlewat dan tanpa ada yang dipakai ulang**.

Syarat keberadaan Eulerian Path (graph tak berarah):

1. Graph harus **connected** (jika hanya dilihat node-node yang punya edge).
2. Harus ada **tepat 0 atau 2 node dengan derajat ganjil**:

   * Kalau **0 node ganjil** → yang ada adalah **Eulerian Circuit** (path yang berawal dan berakhir di simpul yang sama).
   * Kalau **2 node ganjil** → yang ada adalah **Eulerian Path** (path yang berawal di salah satu simpul ganjil dan berakhir di simpul ganjil lainnya).
   * Kalau jumlah node ganjil lebih dari 2 → **tidak ada Eulerian Path**.

👉 Jadi, **Eulerian Path = lintasan yang pakai semua edge sekali**.

* Bedanya dengan **Hamiltonian Path** → Hamiltonian peduli pada **simpul** (kunjungi semua simpul tepat sekali).
* Eulerian peduli pada **edge** (pakai semua edge tepat sekali).

Beriut adalah contoh graph dengan euler path:

![[11-Graph Eulerian Path (undirected)-1.png]]
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

void isConnected(VVP& graph, VB& visited, int now) {
   for (const auto& adj : graph[now]) {
      if (!visited[adj.first]) {
         visited[adj.first] = true;
         isConnected(graph, visited, adj.first);
      }
   }
}

void dfsRec(VVP& graph, VI& edgesID, VI& path, int now, bool& stop) {
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
         dfsRec(graph, edgesID, path, node, stop);
         edgesID[id] = temp;
         if (!stop) {
            path.pop_back();
         }
      }
   }
}

auto isEulerPath(VVP& graph, VI& edgesID, VI& oddStart) -> pair<int, VI> {
   bool thePath = false;
   vector<int> path;
   vector<bool> visited(graph.size(), false);
   int component = 0;

   for (int i = 1; i < graph.size(); i++) {
      if (!visited[i]) {
         visited[i] = true;
         isConnected(graph, visited, i);
         component++;

         if (component > 1)
            break;
      }
   }

   if (component > 1) {
      return {-2, {}};
   } else {
      dfsRec(graph, edgesID, path, oddStart[0], thePath);
      if (!thePath) {
         path.clear();
         dfsRec(graph, edgesID, path, oddStart[1], thePath);
         if (!thePath)
            return {-1, {}};
      }
   }
   return {1, path};
}

auto main() -> int {
   fastio();
   int n, m;
   cin >> n >> m;
   vector<vector<pair<int, int>>> graph(n + 1);
   vector<int> edgesID(m + 1, 1);

   for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;

      graph[u].emplace_back(v, i + 1);
      graph[v].emplace_back(u, i + 1);
   }

   int odd = 0;
   vector<int> oddStart;
   for (int i = 1; i <= n; i++) {
      if (graph[i].size() % 2 == 1) {
         odd++;
         oddStart.push_back(i);
      }
   }

   if (odd != 2) {
      cout << "NO\n";
      cout << "Jumlah node ganjil bukan 2!";
   } else {
      for (auto& node : graph) {
         ranges::sort(node, [](auto& a, auto& b) { 
	         return a.first < b.first; 
         });
      }

      pair<int, vector<int>> rest = isEulerPath(graph, edgesID, oddStart);

      if (rest.first == -2) {
         cout << "NO\n";
         cout << "Graph tidak connected!";
      } else if (rest.first == -1) {
         cout << "NO\n";
         cout << "Eulerian path tidak ditemukan!";
      } else if (rest.first == 1) {
         cout << "YES\n";
         for (int i = 0; i < rest.second.size(); i++) {
            cout << rest.second[i];
            if (i != rest.second.size() - 1) {
               cout << " -> ";
            }
         }
      }
   }
   return 0;
}
```

<br/>

---
# 3 | Editorial

### 1. Identifikasi kondisi dasar Eulerian Path

Syarat klasik:

- Sebuah graph tak berarah memiliki **Eulerian Path** jika:
    
    - Graph **connected** (semua node yang punya edge ada dalam satu komponen).
        
    - Tepat **dua simpul** memiliki derajat ganjil.
        
- Kedua simpul ganjil inilah yang menjadi kandidat **titik awal** dan **titik akhir**.
    

### 2. Pengecekan connectivity

Sebelum mencoba membangun jalur, graph dicek dengan DFS biasa:

- Ambil satu node yang punya edge.
    
- Tandai semua node yang bisa dijangkau.
    
- Kalau masih ada node dengan edge yang belum terjangkau → graph tidak connected → **tidak mungkin ada Eulerian Path**.
    

### 3. Penentuan titik awal

Karena ada dua node ganjil, jalur pasti **dimulai dari salah satunya**.

- Algoritma mencoba dari node ganjil pertama.
    
- Jika gagal, dicoba dari node ganjil kedua.
    

### 4. Pembangunan jalur dengan backtracking DFS

Algoritma membangun jalur edge per edge:

- Setiap edge hanya boleh dipakai sekali → setiap edge diberi **ID unik** dan status “sudah dipakai atau belum”.
    
- DFS rekursif berjalan:
    
    - Kunjungi node sekarang.
        
    - Coba lanjut ke node tetangga lewat edge yang belum dipakai.
        
    - Tandai edge sebagai “terpakai” lalu lanjut DFS.
        
    - Jika di ujung jalur semua edge sudah habis dipakai → **Eulerian Path ditemukan**.
        
    - Jika gagal, edge dikembalikan statusnya (backtrack) dan coba alternatif lain.
        

### 5. Early stop (optimisasi kecil)

Begitu satu jalur valid ditemukan, proses dihentikan.

- Hal ini aman karena Eulerian Path maksimal hanya ada satu (untuk graph tak berarah dengan dua simpul ganjil).
    

### 6. Hasil akhir

- Jika jalur berhasil ditemukan → cetak jalurnya.
    
- Jika gagal setelah mencoba dari kedua node ganjil → **tidak ada Eulerian Path**.
    

---

👉 Jadi intinya, algoritmanya berjalan seperti ini:

1. Pastikan graph connected.
    
2. Pastikan ada tepat 2 node ganjil.
    
3. Coba DFS backtracking mulai dari node ganjil pertama → kalau gagal, coba node ganjil kedua.
    
4. Jalur ditemukan jika seluruh edge bisa dipakai tepat sekali.
    
