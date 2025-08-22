---
obsidianUIMode: preview
note_type: latihan
latihan: Hamiltonion Circuit (undirected)
sumber:
  - Google
tags:
  - graph-algorithm
  - graph-basic
date_learned: 2025-08-18T19:15:00
---
---
# 1 | Hamiltonion Circuit (undirected)

Diberikan sebuah graph undirected. Tugasmku adalah menetukan apakah graph yang diberikan merupakan graph memiliki circuit hamilton. Jika ada, cetak `YES` dan juga path-nya, dan jika tidak maka cetak `NO`.

```ad-info
ℹ️ **Definisi:**

1. **Hamiltonian Path**

   * Jalur yang **melewati setiap node tepat sekali**.
   * Tidak harus kembali ke node awal.

2. **Hamiltonian Cycle** (Hamiltonian Circuit)

   * Jalur yang **melewati setiap node tepat sekali** **dan kembali ke node awal**.
   * Jadi cycle lengkap yang menyentuh semua node.

---

ℹ️ **Syarat / Observasi Umum di Undirected Graph**

> Tidak ada **syarat sederhana yang pasti bisa langsung diterapkan**, tapi ada beberapa **sifat penting** yang bisa membantu menilai kemungkinan Hamiltonian:

1. **Degree rendah → mustahil**

   * Node dengan degree < 2 → tidak mungkin ada Hamiltonian cycle (karena tidak bisa masuk dan keluar tanpa mengulang node).

2. **Graph connected**

   * Hamiltonian path/cycle hanya mungkin jika graph **connected**.

3. **Dirac’s Theorem (sufficient condition, undirected graph sederhana)**

   * Jika graph **simple** dengan `n ≥ 3` dan setiap node punya degree ≥ n/2 → graph pasti punya Hamiltonian cycle.

4. **Ore’s Theorem (sufficient condition, undirected graph sederhana)**

   * Jika untuk setiap pair non-adjacent `(u, v)`, `deg(u) + deg(v) ≥ n` → graph punya Hamiltonian cycle.

---

ℹ️ **Catatan**

* **Hamiltonian problem**: Umumnya **NP-complete**, artinya **tidak ada algoritma cepat umum untuk semua graph**.
* Di CP, biasanya ada **shortcut / heuristik**:

  * Graph kecil → coba semua permutasi / backtracking
  * Graph khusus → gunakan properti degree, complete graph, bipartite dengan ukuran tertentu, dll.
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
using VB = vector<bool>;
using VI = vector<int>;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void dfsRec(VVI& graph, VB& visited, VI& path, int now, int target, bool& stop) {
   if (stop)
      return;

   path.push_back(now);

   if (path.size() == graph.size() - 1) {
      for (const auto& finish : graph[now]) {
         if (finish == target) {
            path.push_back(finish);
            stop = true;
            return;
         }
      }
   }

   for (const auto& next : graph[now]) {
      if (!visited[next]) {
         visited[next] = true;
         dfsRec(graph, visited, path, next, target, stop);
         visited[next] = false;
         if (!stop) {
            path.pop_back();
         }
      }
   }
}

auto isHamiltonian(VVI& graph) -> pair<bool, VI> {
   vector<bool> visited(graph.size(), false);
   vector<int> path;
   bool hamilton = false;
   visited[1] = true;
   dfsRec(graph, visited, path, 1, 1, hamilton);

   if (!hamilton) {
      return {hamilton, {}};
   }
   return {hamilton, path};
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

   // rapikan saja
   for (auto& adj : graph) {
      ranges::sort(adj);
   }

   bool degrePass = true;
   for (int i = 1; i <= n; i++) {
      if (graph[i].size() < 2) {
         degrePass = false;
         break;
      }
   }

   if (degrePass) {
      pair<bool, vector<int>> rest = isHamiltonian(graph);
      if (rest.first) {
         cout << "YES\n";
         for (int i = 0; i < rest.second.size(); i++) {
            cout << rest.second[i];
            if (i != rest.second.size() - 1) {
               cout << " -> ";
            }
         }
      }
   } else {
      cout << "NO\n";
      cout << "Terdapat node dengan degre < 2!";
   }
   return 0;
}
```

<br/>

---
# 3 | Editorial

## 3.1 | Alur Logika Program

1. **Input & Representasi Graph**

   * Program membaca jumlah node `n` dan edge `m`.
   * Graph disimpan dalam bentuk adjacency list (`vector<vector<int>>`).
   * Setiap edge `(u, v)` ditambahkan dua arah (karena graph undirected).

2. **Penyaringan Awal (Degree Check)**

   * Sebelum melakukan pencarian Hamiltonian, program mengecek apakah setiap node memiliki derajat minimal 2.
   * Jika ada node dengan degree `< 2`, langsung dipastikan **bukan Hamiltonian cycle** → output `NO`.

3. **Pencarian Hamiltonian Cycle dengan DFS + Backtracking**

   * Mulai pencarian dari node `1`.
   * Setiap node ditandai sebagai `visited` untuk mencegah dipakai ulang dalam jalur.
   * Jalur (`path`) disimpan agar bisa dicetak jika solusi ditemukan.

4. **Stopping Condition**

   * Jika jumlah node yang dikunjungi sudah `n` dan node terakhir punya edge balik ke node awal, maka jalur valid → ditemukan Hamiltonian cycle.
   * Program langsung berhenti (`stop = true`) begitu satu solusi ditemukan.

5. **Output**

   * Jika Hamiltonian cycle ada → cetak `"YES"` dan jalurnya dalam format `1 -> 2 -> … -> 1`.
   * Jika tidak ada → cetak `"NO"`.

## 3.2 | Alur Algoritma

1. **Bangun Graph** dengan adjacency list.
2. **Cek Degree Minimum** setiap node.

   * Jika ada degree < 2 → `NO` (tidak perlu lanjut).
3. **DFS Backtracking**

   * Mulai dari node 1.
   * Tandai node sebagai visited dan masukkan ke `path`.
   * Rekursi ke semua tetangga yang belum dikunjungi.
   * Jika `path.size() == n` → cek apakah node terakhir terhubung ke node awal.

     * Jika iya → Hamiltonian cycle ditemukan.
     * Jika tidak → backtrack.
4. **Hentikan Pencarian** segera setelah solusi ditemukan.
5. **Keluarkan Hasil**: cetak `YES` + jalur, atau `NO` jika tidak ada solusi.

