---
obsidianUIMode: preview
note_type: latihan
latihan: Topological DFS
sumber:
  - chatgpt.com
tags:
  - graph-traversal
  - graph-DFS
  - graph-algorithm
date_learned: 2025-08-05T16:15:00
---
---
# Topological DFS - Leksikografis Terbesar

Diberikan sebuah graf **berarah dan tanpa siklus (DAG)** dengan `n` node bernomor **1 sampai n** dan `m` buah edge.

Tentukan satu urutan **topologis** dari graf tersebut, yaitu urutan node sedemikian hingga untuk setiap edge `u → v`, maka `u` muncul **sebelum** `v`.

Jika terdapat banyak kemungkinan urutan, maka cetak **urutan yang secara leksikografis terbesar**.

> Gunakan DFS dan pastikan traversal dari node bernomor besar ke kecil, dan tetangga juga diurutkan menurun.

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
    
- Dijamin graf adalah **DAG** (tidak ada siklus)
    

#### Output Format:

Satu baris berisi `n` bilangan bulat — urutan topologis yang valid, dan **leksikografis terbesar**.

---

#### Contoh Input:

```
6 6
1 2
1 3
3 4
2 4
4 5
4 6
```

#### Contoh Output:

```
1 3 2 4 6 5
```


<br/>

---
# Jawaban

Berikut adalah jawaban yang sudah benar:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using VVI = vector<vector<int>>;
using VB = vector<bool>;
using VI = vector<int>;

void dfsSearch(VVI& graph, VB& visited, int now, VI& rest) {
   visited[now] = true;
   for (auto& V : graph[now]) {
      if (!visited[V])
         dfsSearch(graph, visited, V, rest);
   }
   rest.push_back(now);  // push node setelah semua child dikunjungi
}

void topologicalOrder(VVI& graph, VI& rest) {
   VB visited(graph.size(), false);
   for (int i = 1; i < graph.size(); i++) {
      if (!visited[i])
         dfsSearch(graph, visited, i, rest);
   }
}

auto main() -> int {
   int n, m;
   cin >> n >> m;
   VVI graph(n + 1);
   VI rest;

   for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      graph[u].push_back(v);
   }

   for (auto& x : graph) {
      ranges::sort(x);
   }

   topologicalOrder(graph, rest);
   ranges::reverse(rest);
   for (const auto& x : rest) {
      cout << x << " ";
   }
   return 0;
}
```

<br/>

---
# Editorial


**Deskripsi Masalah:**  
Diberikan sebuah graf berarah tanpa siklus (DAG) dengan `n` simpul bernomor 1 hingga `n` dan `m` buah sisi. Tentukan urutan topologis dari simpul-simpul tersebut. Jika terdapat lebih dari satu urutan yang valid, pilih urutan yang secara leksikografis terbesar.


**Strategi Penyelesaian:**  
Topological sort dapat diperoleh dengan menggunakan algoritma DFS. Pada setiap simpul, DFS akan memanggil rekursif ke seluruh anak (tetangga) sebelum memasukkan simpul itu sendiri ke dalam urutan akhir. Dengan cara ini, simpul akan masuk ke hasil setelah semua ketergantungannya selesai dikunjungi.


**Penyesuaian untuk Leksikografis Terbesar:**  
Agar hasil urutan menjadi leksikografis terbesar:

- DFS harus dilakukan dengan memprioritaskan simpul yang lebih besar.
    
- Untuk itu, traversal dimulai dari simpul `n` ke `1`.
    
- Adjacency list dari tiap simpul diurutkan secara menurun agar tetangga dengan nomor lebih besar dikunjungi terlebih dahulu.
    

**Langkah Implementasi:**

1. Buat adjacency list untuk graf berarah.
    
2. Lakukan pengurutan descending pada adjacency list setiap simpul.
    
3. Gunakan array penanda `visited` untuk menghindari pengulangan simpul.
    
4. Lakukan DFS dari setiap simpul mulai dari `n` ke `1`.
    
5. Simpul dimasukkan ke dalam hasil setelah seluruh tetangga selesai dikunjungi (post-order).
    
6. Balikkan urutan hasil akhir untuk mendapatkan urutan topologis.
    

**Contoh:**

Input:

```
6 6
1 2
1 3
3 4
2 4
4 5
4 6
```

Urutan topologis leksikografis terbesar:

```
1 3 2 4 6 5
```

**Catatan Tambahan:**  
Metode ini bekerja dalam kompleksitas waktu `O(n + m log d)`, dengan `d` adalah derajat maksimum simpul, karena adanya pengurutan pada adjacency list. Untuk graf yang sangat besar, urutan tetangga bisa diurutkan langsung saat input jika dibutuhkan efisiensi.
