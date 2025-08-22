---
obsidianUIMode: preview
note_type: latihan
latihan: Apakah Ada Cycle (undirected)
sumber:
  - chatgpt.com
  - myself
tags:
  - graph-algorithm
  - graph-basic
date_learned: 2025-08-17T02:39:00
---
---
# 1 | Apakah Ada Cycle (undirected)

Diberikan sebuah graph undirected, tugasmu adalah menentukan apakah terdapat cycle pada graph yang diberikan. Jika iya, maka outputkan `YES`, jika tidak ada, maka outputkan `NO`.

```ad-info
Siklus (cycle) pada graph adalah lintasan tertutup yang dimulai dari sebuah simpul, melewati serangkaian sisi, lalu kembali lagi ke simpul asal tanpa mengulang sisi yang sama. Pada graph tak berarah (undirected), siklus muncul jika ada jalur tertutup yang berbeda dari sekadar hubungan langsung dengan simpul sebelumnya, misalnya persegi `1–2–3–4–1`. Sedangkan pada graph berarah (directed), siklus terbentuk jika ada jalur melingkar yang mengikuti arah panah, seperti `1 → 2 → 3 → 4 → 1`. Graph yang tidak memiliki siklus disebut **acyclic**, dan khusus graph tak berarah yang terhubung tanpa siklus disebut **tree**.

Berikut contohnya:

![[07-Apakah Ada Cycle-1.png]]

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

void dfsRec(VVI& graph, VB& visited, int now, int last, bool& val) {
   if (val)
      return;
   for (const auto& A : graph[now]) {
      if (!visited[A]) {
         visited[A] = true;
         dfsRec(graph, visited, A, now, val);
      } else {
         if (A != last && visited[A]) {
            val = true;
            return;
         }
      }
   }
}

auto isCycle(VVI& graph) -> bool {
   bool val = false;
   vector<bool> visited(graph.size(), false);

   for (int i = 1; i < graph.size(); i++) {
      if (!visited[i]) {
         visited[i] = true;

         dfsRec(graph, visited, i, i, val);
      }
   }

   return val;
}

auto main() -> int {
   fastio();
   int n, m;
   cin >> n >> m;

   VVI graph(n + 1);
   for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;

      graph[u].push_back(v);
      graph[v].push_back(u);
   }

   cout << (isCycle(graph) ? "YES" : "NO");

   return 0;
}
```

<br/>

---
# 3 | Editorial

Proyek ini menunjukkan cara **mendeteksi siklus (cycle)** pada sebuah **graf tak-berarah** menggunakan algoritma **Depth-First Search (DFS)**. Program akan membaca input berupa jumlah simpul dan sisi, membangun representasi graf dengan adjacency list, lalu mengecek apakah graf tersebut mengandung siklus.

## 3.1 | Deskripsi Masalah

Diberikan sebuah graf tak-berarah dengan **N** simpul dan **M** sisi, tentukan apakah graf tersebut mengandung **siklus**.

* **Siklus** adalah lintasan di mana simpul awal sama dengan simpul akhir, dan semua sisi yang dilewati bersifat unik.
* Dalam graf tak-berarah, perlu hati-hati agar tidak salah mendeteksi sisi yang kembali ke simpul *parent* sebagai siklus.

## 3.2 | Intuisi Solusi

Kita gunakan **DFS traversal** untuk menelusuri graf.

* Simpan status setiap simpul dengan array `visited[]`.
* Untuk setiap simpul, telusuri semua tetangganya:

  * Jika tetangga **belum dikunjungi**, lakukan DFS rekursif ke sana.
  * Jika tetangga **sudah dikunjungi** dan **bukan parent**, berarti ditemukan siklus.

Dengan cara ini, kita bisa membedakan antara "kembali ke parent" (yang sah) dan "menemukan siklus" (yang valid).
## 3.3 | Algoritma

1. Bangun adjacency list dari input graf.
2. Siapkan array `visited[]` untuk menandai simpul yang sudah dikunjungi.
3. Untuk setiap simpul yang belum dikunjungi, jalankan DFS.
4. Dalam DFS:

   * Jika menemukan tetangga yang sudah dikunjungi dan **bukan parent**, tandai `cycle = true`.
5. Setelah semua DFS selesai:

   * Jika ditemukan siklus → cetak `"YES"`.
   * Jika tidak ada siklus → cetak `"NO"`.

## 3.4 | Kompleksitas

* **Waktu**:

  * Setiap simpul dan sisi dikunjungi sekali → **O(N + M)**.
* **Memori**:

  * Penyimpanan adjacency list + stack rekursi → **O(N + M)**.
