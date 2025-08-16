---
obsidianUIMode: preview
note_type: latihan
latihan: Pengecekan Cycle pada Graph
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - graph-traversal
  - graph-DFS
date_learned: 2025-08-05T13:59:00
---
---
# Pengecekan Cycle pada Graph

Berikut deskripsi lengkap soal nomor 4:

Diberikan sebuah graph **tak berarah** dengan `n` simpul dan `m` sisi. Tugas Anda adalah menentukan apakah graph tersebut mengandung **setidaknya satu siklus**.

**Input Format:**

```
n m  
a1 b1  
a2 b2  
...  
am bm
```

- `1 ≤ n ≤ 10^5`
    
- `1 ≤ ai, bi ≤ n`
    

**Output:**

- Cetak `"YES"` jika terdapat siklus dalam graph.
    
- Cetak `"NO"` jika tidak ada siklus.

### Contoh 1:

Input:

```txt
5 5
1 2
2 3
3 4
4 5
5 1
```

Output:

```
YES
```

---

### Contoh 2:

Input:

```txt
4 2
1 2
3 4
```

Output:

```
NO
```

### Catatan:

- Gunakan DFS untuk mendeteksi siklus dengan menjaga **parent** dari simpul sebelumnya.
    
- Karena graph bisa tidak terhubung, pastikan periksa setiap komponen.
    


<br/>

---
# Jawaban

Berikut adalah jawabanku yang sudah benar:

```cpp
#include <algorithm>
#include <cstddef>
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

void dfsSearch(VVI& graph, VB& visited, int now, bool& cycle, int prev = 0) {
   for (auto& V : graph[now]) {
      if (V == prev)
         continue;  // jangan balik ke parent

      if (visited[V]) {
         cycle = true;
         return;
      }

      visited[V] = true;
      dfsSearch(graph, visited, V, cycle, now);
   }
}

auto isCycel(VVI& graph, bool& cycle) -> bool {
   VB visited(graph.size(), false);

   for (int i = 1; i < graph.size(); i++) {
      if (!visited[i]) {
         visited[i] = true;
         dfsSearch(graph, visited, i, cycle);
      }
   }

   return cycle;
}

auto main() -> int {
   fastio();
   int n, m;
   cin >> n >> m;
   VVI graph(n + 1);
   bool cycle = false;

   for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;

      graph[u].push_back(v);
      graph[v].push_back(u);
   }

   isCycel(graph, cycle);
   if (cycle) {
      cout << "YES\n";
   } else
      cout << "NO\n";

   return 0;
}

```

<br/>

---
# Editorial

Fungsi `isCycle()` memiliki peran yang cukup sederhana, yaitu memastikan bahwa jika graph yang diberiukan adalah graph disconnected, maka semua node tetap berhasil dijangkau atau ditraversal dengan sempurna.

Hal yang paling penting dari algoritma pencarian cycle pada graph ada di fungsi `dfsSearch()`:

```cpp
void dfsSearch(VVI& graph, VB& visited, int now, bool& cycle, int prev = 0) {
   for (auto& V : graph[now]) {
      if (V == prev)
         continue;  // jangan balik ke parent
      if (visited[V]) {
         cycle = true;
         return;
      }
      visited[V] = true;
      dfsSearch(graph, visited, V, cycle, now);
   }
}
```

Sebelum menjelaskan lebih lanjut tentang tentang fungsi ini, kita harus memahami logika dasar dari mencari graph dengan `cycle`.

Graph yang memiliki `cycle`, ditandai dengan adanya jalur yang mengarah ke node yang sudah dikunjungi, tapi bukan node sebelumnya. Semisal kita memiliki node yang membentuk segita atau segiempat, atau bahkan lingkaran, maka pasti ada cycle, karena node awal akan bertemu dengan node akhir yang mengarah ke node awal.

Suatu graph bukan cycle jika tidak ada node yang menemukan node yang sudah dikunjungi dan bukan node sebelemnya. Semisal graph garis lurus.

Dari logika ini, solusinya mudah, kita tinggal melakukan penelusuran pada DFS hanya jika node tersebut belum dikunjungi, lalu melakukan 2 pengkondisian.

Kondisi pertama, adalah jika node sekarang mengarah ke node sbeelumnya, maka itu bukan cycle, walaupun node tersebut sudah dikunjungi. Jadi kita skip dengan `continue`. Nilai dari node sebelumnya bisa kita isi dengan `now` pada saat pemanggilan DFS, karena nilai `now` adalah node sebelumnya.

Kondisi kedua, adalah ketika kita menemukan suatu node yang sudah dikunjungi, dan dia bukan node sebelumnya. Ohh, berarti kita menemukan sikuls atau cycle disini. Oleh karena itu, kita rubah boolean `cycle` menjadi `true`, dan return.

```cpp
  if (visited[V]) {
	 cycle = true;
	 return;
  }
```

Nah, jika cycle belum ditemukan dan node tidak mengarah ke parentnya, lakukan mekanisme traversal DFS biasa, dengan:

```cpp
  visited[V] = true;
  dfsSearch(graph, visited, V, cycle, now);
```

