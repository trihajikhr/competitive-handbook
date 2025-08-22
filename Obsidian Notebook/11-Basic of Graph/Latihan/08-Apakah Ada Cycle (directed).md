---
obsidianUIMode: preview
note_type: latihan
latihan: Apakah Ada Cycle (directed)
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - graph-basic
date_learned: 2025-08-17T03:08:00
---
---
# 1 | Apakah Ada Cycle (directed)

Diberikan sebuah graph directed. Tugasmu adalah menentukan apakah graph yang diberikan (yang merupakan graph directed) memiliki cycle atau tidak. Jika iya, maka outputkan `YES`, jika sebaliknya outputkan `NO`.

```ad-info
Penjelasan apa itu cycle sudah dijelaskan di latihan soal sebelumnya!

Sebuah graph directed tanpa cycle juga disebut dengan DAG, atau Directed Acyclic Graph
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

void dfsRec(VVI& graph, VB& visited, VB& inStack, int now, bool& val) {
   if (val) {
      return;
   }

   visited[now] = true;
   inStack[now] = true;

   for (const auto& A : graph[now]) {
      if (!visited[A]) {
         dfsRec(graph, visited, inStack, A, val);
      } else if (inStack[A]) {
         val = true;
         return;
      }
   }

   inStack[now] = false;
}

auto isCycle(VVI& graph) -> bool {
   bool val = false;
   vector<bool> visited(graph.size(), false), inStack(graph.size(), false);

   for (int i = 1; i < graph.size(); i++) {
      if (!visited[i]) {
         dfsRec(graph, visited, inStack, i, val);
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
   }

   cout << (isCycle(graph) ? "YES" : "NO");
   return 0;
}
```

<br/>

---
# 3 | Editorial

## 3.1 | Deskripsi

Siklus dalam **graf berarah (directed graph)** adalah lintasan yang dimulai dari sebuah simpul dan kembali lagi ke simpul tersebut melalui satu atau lebih sisi (edge) yang mengikuti arah panah. Mengetahui apakah sebuah graf berarah mengandung siklus atau tidak sangatlah penting, terutama dalam permasalahan seperti:

* **Topological Sorting**: hanya bisa dilakukan jika graf **bebas siklus** (DAG – Directed Acyclic Graph).
* **Dependency Resolution**: seperti urutan build software, jadwal mata kuliah, atau ketergantungan paket.
* **Deadlock Detection**: dalam sistem operasi, siklus pada graf bisa menunjukkan deadlock.

Kode berikut mengimplementasikan **algoritma DFS (Depth-First Search)** untuk mengecek apakah sebuah directed graph mengandung siklus.

## 3.2 | Ide Utama

* Saat melakukan DFS, kita butuh dua penanda:

  1. **`visited[]`** → apakah simpul sudah pernah dikunjungi sebelumnya.
  2. **`inStack[]`** → apakah simpul sedang berada di jalur DFS yang sedang aktif (rekursi saat ini).

* Jika selama DFS, kita menemukan edge yang menuju ke simpul **yang masih berada di jalur DFS aktif**, maka artinya ada **back edge**, yang membentuk **siklus**.

* Jika DFS sudah selesai dari suatu simpul, kita keluarkan simpul tersebut dari jalur aktif (`inStack[now] = false`).

## 3.3 | Penjelasan Kode

### 1. Representasi Graf

```cpp
VVI graph(n + 1);
```

Graf disimpan dalam bentuk **adjacency list**, di mana `graph[u]` berisi daftar simpul yang dituju dari simpul `u`. Karena grafnya **directed**, hanya `graph[u].push_back(v)` yang ditambahkan (tanpa `graph[v].push_back(u)`).

### 2. Fungsi DFS Rekursif

```cpp
void dfsRec(VVI& graph, VB& visited, VB& inStack, int now, bool& val)
```

* `visited` memastikan simpul hanya diproses sekali.
* `inStack` melacak simpul yang sedang aktif di jalur DFS.
* Jika menemukan edge menuju simpul yang **masih dalam jalur aktif**, berarti ada **siklus**.


### 3. Fungsi `isCycle()`

```cpp
for (int i = 1; i < graph.size(); i++) {
   if (!visited[i]) {
      dfsRec(graph, visited, inStack, i, val);
   }
}
```

Dilakukan loop untuk memulai DFS dari semua simpul yang belum dikunjungi. Hal ini penting karena graf bisa memiliki **beberapa komponen terpisah**.

### 4. Bagian Main Program

```cpp
for (int i = 0; i < m; i++) {
   int u, v;
   cin >> u >> v;
   graph[u].push_back(v);
}
```

Input berupa jumlah simpul `n` dan jumlah sisi `m`. Kemudian tiap sisi berupa **pasangan terarah (u → v)**.
Terakhir, program mencetak `"YES"` jika ada siklus, `"NO"` jika tidak.

## 3.4 | Kompleksitas

* **Waktu**: `O(V + E)`

  * Setiap simpul (`V`) dan setiap sisi (`E`) dikunjungi maksimal sekali.
* **Memori**: `O(V)`

  * Digunakan oleh array `visited[]` dan `inStack[]`.


## 3.5 | Contoh Uji

### Input 1

```
4 4
1 2
2 3
3 4
4 2
```

Graf: `1 → 2 → 3 → 4 → 2`
**Output**:

```
YES
```

Ada siklus: `2 → 3 → 4 → 2`.


### Input 2

```
4 3
1 2
2 3
3 4
```

Graf: `1 → 2 → 3 → 4` (tidak ada jalan kembali).
**Output**:

```
NO
```


## 3.6 | Kesimpulan

* Siklus pada graf berarah dapat dideteksi dengan **DFS** menggunakan dua penanda: `visited` dan `inStack`.
* Jika ada edge menuju simpul yang sedang berada di jalur DFS aktif, berarti ada **siklus**.
* Implementasi ini efisien dengan kompleksitas `O(V + E)` dan banyak dipakai dalam berbagai masalah seperti **topological sort, dependency resolution,** dan **deadlock detection**.
