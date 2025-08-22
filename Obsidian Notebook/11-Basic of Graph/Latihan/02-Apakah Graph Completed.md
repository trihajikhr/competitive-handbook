---
obsidianUIMode: preview
note_type: latihan
latihan: Apakah Graph Completed
sumber:
  - "buku: CP handbook by Antti Laaksonen"
  - chatgpt.com
tags:
  - graph-algorithm
  - graph-basic
date_learned: 2025-08-16T16:55:00
---
---
# 1 | Apakah Graph Completed

Kamu diberikan sebuah graph. Tugasmu adalah mengecek apakah graph yang diberikan complete atau tidak. Jika iya, maka outputkan `YES`, jika tidak, maka outputkan `NO`!

```ad-info
Dalam teori graf, graf lengkap (complete graph) adalah graf sederhana di mana setiap pasangan simpul (vertex) yang berbeda dihubungkan oleh satu sisi (edge). Jadi, setiap simpul terhubung langsung ke semua simpul lainnya dalam graf.

Contohnya adalah seperti ini:

![[02-Apakah Graph Completed-1.png]]
```

<br/>

---
# 2 | Jawaban

Berikut adalah jawaban yang sudah benar:

```cpp
#include <iostream>
#include <set>
#include <vector>
using namespace std;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

using VSI = vector<set<int>>;
using VB = vector<bool>;

auto main() -> int {
   fastio();
   int n, m;
   cin >> n >> m;

   VSI graph(n + 1);
   for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;

      if (u == v)
         continue;
      graph[u].insert(v);
      graph[v].insert(u);
   }

   int edges = 0;
   for (int i = 1; i <= n; i++) {
      edges += graph[i].size();
   }

   edges /= 2;

   if (edges != n * (n - 1) / 2) {
      cout << "NO\n";
      return 0;
   }

   bool pass = true;
   for (int i = 1; i <= n; i++) {
      if (graph[i].size() != n - 1) {
         pass = false;
         break;
      }
   }

   cout << (pass ? "YES" : "NO") << '\n';

   return 0;
}
```

<br/>

---
# 3 | Editorial
## 3.1 | Editorial per blok
#### 1. Fast I/O

```cpp
inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}
```

Dipakai untuk mempercepat input-output. Bukan bagian inti algoritma, tapi penting untuk efisiensi saat data besar.

#### 2. Deklarasi Struktur Data

```cpp
using VSI = vector<set<int>>;
```

* `vector<set<int>>` dipakai untuk menyimpan adjacency list.
* `set` digunakan agar:

  * Tidak ada duplikasi sisi (misalnya jika input `1 2` muncul dua kali, tetap dihitung sekali).
  * Tidak ada self-loop (`u == v` kita abaikan di bagian input).

#### 3. Input Jumlah Node dan Edge

```cpp
int n, m;
cin >> n >> m;
```

* `n`: jumlah simpul.
* `m`: jumlah sisi yang diberikan.

#### 4. Membangun Graph

```cpp
VSI graph(n + 1);
for (int i = 0; i < m; i++) {
   int u, v;
   cin >> u >> v;
   if (u == v) continue;        // abaikan self-loop
   graph[u].insert(v);
   graph[v].insert(u);
}
```

* Setiap edge `u v` dimasukkan ke adjacency list.
* Karena graph **tak berarah**, kita masukkan dua arah (`u->v` dan `v->u`).
* Self-loop di-skip karena tidak relevan untuk complete graph.

#### 5. Hitung Jumlah Edge Aktual

```cpp
int edges = 0;
for (int i = 1; i <= n; i++) edges += graph[i].size();
edges /= 2; // karena undirected
```

* Menjumlahkan ukuran adjacency setiap node.
* Dibagi 2 karena setiap edge dihitung dua kali (`u->v` dan `v->u`).

#### 6. Cek Jumlah Edge Sesuai Rumus

```cpp
if (edges != n * (n - 1) / 2) {
   cout << "NO\n";
   return 0;
}
```

* Graph complete dengan `n` simpul pasti punya jumlah edge **tepat** `n * (n - 1) / 2`.
* Jika tidak sama, langsung dipastikan bukan complete graph.

Untuk complete graph dengan `n` node, julah edge harus tepat: $m = \frac{n \cdot (n-1)}{2}$
#### 7. Cek Derajat Setiap Node

```cpp
for (int i = 1; i <= n; i++) {
   if (graph[i].size() != n - 1) {
      cout << "NO\n";
      return 0;
   }
}
```

* Syarat lain dari complete graph: setiap simpul terhubung ke semua simpul lainnya.
* Itu berarti setiap node punya derajat `n - 1`.
* Jika ada satu saja simpul yang tidak memenuhi, jawabannya **NO**.

#### 8. Output Akhir

```cpp
cout << "YES\n";
return 0;
```

Jika lolos semua pengecekan, berarti graph adalah complete.

## 3.2 |  Inti Algoritma

1. **Bangun graph** dengan adjacency list.
2. **Hitung total edge**, cocokkan dengan rumus complete graph.
3. **Cek derajat tiap simpul** harus `n - 1`.
4. Kalau semua syarat terpenuhi → **YES**, jika tidak → **NO**.

