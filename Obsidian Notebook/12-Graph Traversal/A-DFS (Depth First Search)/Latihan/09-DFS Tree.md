---
obsidianUIMode: preview
note_type: latihan
latihan: 
sumber: 
tags:
  - tag
date_learned:
---
---
# DFS Tree

Diberikan sebuah graf **tak berarah dan terhubung**, dengan `n` simpul bernomor **1 sampai n** dan `m` sisi.

Lakukan DFS mulai dari simpul `1`, dan **cetak semua edge** yang digunakan untuk membentuk **DFS Tree**.

#### Input Format:

```
n m
u1 v1
u2 v2
...
um vm
```

- `1 ≤ n ≤ 10^5`
    
- `1 ≤ m ≤ 2×10^5`
    
- `1 ≤ ui, vi ≤ n`
    
- Graf **tidak memiliki loop** atau multiple edge
    
- Graf **terhubung** (semua simpul bisa dicapai dari simpul 1)
    

#### Output Format:

Cetak `n-1` baris. Setiap baris berisi dua bilangan `a b`, menunjukkan edge dari `a` ke `b` yang digunakan dalam DFS Tree (urutan kunjungan).

#### Contoh Input:

```
5 5
1 2
1 3
3 4
2 5
4 5
```

#### Contoh Output:

```
1 2
2 5
1 3
3 4
```

(urutan bisa berbeda tergantung urutan DFS, tapi jumlah baris selalu `n-1`)

<br/>

---
# Jawaban

Berikut adalah jawabanku:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using VVI = vector<vector<int>>;
using VB = vector<bool>;
using VI = vector<int>;
using VP = vector<pair<int, int>>;

void dfsSearch(VVI& graph, VB& visited, VP& rest, int now) {
   visited[now] = true;
   for (const auto& V : graph[now]) {
      if (visited[V])
         continue;
      rest.emplace_back(now, V);
      dfsSearch(graph, visited, rest, V);
   }
}

void getPair(VVI& graph, VP& rest) {
   VB visited(graph.size(), false);
   dfsSearch(graph, visited, rest, 1);
}

auto main() -> int {
   int n, m;
   cin >> n >> m;
   VVI graph(n + 1);
   VP rest;

   for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;

      graph[u].push_back(v);
      graph[v].push_back(u);
   }

   getPair(graph, rest);
   for (const auto& [u, v] : rest) {
      cout << u << " " << v << '\n';
   }

   return 0;
}
```

<br/>

---
# Editorial

**Deskripsi Masalah:**

Diberikan graf tidak berarah dengan `n` node dan `m` edge. Tugasnya adalah membangun struktur pohon yang dihasilkan dari proses Depth-First Search (DFS) yang dimulai dari node 1. Setiap edge yang pertama kali menghubungkan node yang belum dikunjungi dimasukkan ke dalam pohon sebagai bagian dari hasil.

**Input:**

Baris pertama terdiri dari dua bilangan bulat `n` dan `m` (`1 ≤ n ≤ 10⁵`, `0 ≤ m ≤ 2×10⁵`), yang menyatakan jumlah node dan edge.

Setelahnya terdapat `m` baris, masing-masing berisi dua bilangan `u` dan `v` (`1 ≤ u,v ≤ n`) yang menyatakan edge antara node `u` dan `v`.

**Tujuan:**

Keluarkan pasangan `(u, v)` sebanyak `n - 1` yang merepresentasikan edge-edge dari DFS Tree (jika graf terhubung). Jika graf tidak terhubung, DFS Tree akan memuat lebih sedikit edge.

**Langkah Penyelesaian:**

1. Representasikan graf dalam bentuk adjacency list.
    
2. Buat array penanda kunjungan (`visited[]`) untuk menyimpan status kunjungan tiap node.
    
3. Lakukan DFS dari node 1.
    
4. Setiap kali mengunjungi node baru `v` dari `u`, simpan pasangan `(u, v)` sebagai bagian dari DFS Tree.
    

**Implementasi:**

```cpp
void dfsSearch(VVI& graph, VB& visited, VP& rest, int now) {
   visited[now] = true;
   for (const auto& V : graph[now]) {
      if (visited[V])
         continue;
      rest.emplace_back(now, V);
      dfsSearch(graph, visited, rest, V);
   }
}
```


**Catatan:**

- Edge `(u, v)` dianggap bagian dari DFS Tree hanya jika `v` belum pernah dikunjungi saat eksplorasi dari `u`.
    
- Hasil DFS Tree tidak unik; bergantung pada urutan tetangga di adjacency list.
    
- Untuk hasil deterministik, adjacency list dapat diurutkan sebelum DFS.
    
