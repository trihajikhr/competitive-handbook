---
obsidianUIMode: preview
note_type: latihan
latihan: Hitung Banyak Node Component
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - graph-traversal
  - graph-DFS
date_learned: 2025-08-05T01:42:00
---
---
# Hitung Banyak Node Component

Diberikan graph **tak berarah dan tidak selalu terhubung**, terdiri dari `n` node bernomor **1 hingga n**, dan `m` edge. Cetak semua node yang berada dalam **komponen yang sama** dengan node `u`.

**Input Format:**

```
n m  
a1 b1  
a2 b2  
...  
am bm  
u
```

**Batasan:**

- `1 ≤ n ≤ 10^5`
    
- `1 ≤ ai, bi ≤ n`
    
- `1 ≤ u ≤ n`
    

**Output:**

- Baris pertama: jumlah node dalam komponen `u`.
    
- Baris kedua: daftar node dalam urutan menaik.
    
### Contoh:

Input:

```txt
20 12
1 2
2 3
3 1
4 5
5 6
7 8
8 7
9 10
11 12
13 14
15 16
17 18
4
```

Output:

```
3
4 5 6
```


<br/>

---
# Jawaban

Berikut jawabanku yang sudah solid:

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

void dfsSearch(VVI& graph, VB& visited, VI& rest, int now) {
   rest.push_back(now);

   for (const auto& v : graph[now]) {
      if (!visited[v]) {
         visited[v] = true;
         dfsSearch(graph, visited, rest, v);
      }
   }
}

void searchComponents(VVI& graph, VI& rest, int now) {
   VB visited(graph.size(), false);
   visited[now] = true;
   dfsSearch(graph, visited, rest, now);
}

auto main() -> int {
   fastio();
   int n, m;
   cin >> n >> m;

   VVI graph(n + 1);
   VI rest;

   for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;

      graph[u].push_back(v);
      graph[v].push_back(u);
   }

   for (auto& x : graph) {
      ranges::sort(x);
   }

   int x;
   cin >> x;
   searchComponents(graph, rest, x);
   ranges::sort(rest);

   cout << rest.size() << '\n';
   for (const auto& x : rest) {
      cout << x << " ";
   }
   cout << '\n';

   return 0;
}

```

<br/>

---
# Editorial

Diberikan sebuah graph tak berarah dengan `n` simpul dan `m` sisi, serta sebuah simpul awal `x`. Tugasnya adalah mencetak semua simpul yang berada dalam **komponen yang sama** dengan simpul `x`, dalam **urutan menaik**.

### 🧩 Struktur dan Penjelasan Kode

#### 1. Inisialisasi dan Optimasi I/O

```cpp
inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}
```

Fungsi `fastio()` mengaktifkan optimasi input/output untuk mempercepat proses baca-tulis pada data besar.

#### 2. DFS Rekursif

```cpp
void dfsSearch(VVI& graph, VB& visited, VI& rest, int now) {
   rest.push_back(now);
   for (const auto& v : graph[now]) {
      if (!visited[v]) {
         visited[v] = true;
         dfsSearch(graph, visited, rest, v);
      }
   }
}
```

Fungsi `dfsSearch` melakukan **Depth-First Search** secara rekursif dari node `now`. Setiap node yang dikunjungi disimpan ke dalam `rest`, dan ditandai telah dikunjungi pada array `visited`.

#### 3. Menyiapkan DFS

```cpp
void searchComponents(VVI& graph, VI& rest, int now) {
   VB visited(graph.size(), false);
   visited[now] = true;
   dfsSearch(graph, visited, rest, now);
}
```

Fungsi `searchComponents` mempersiapkan array penanda `visited` dan memulai DFS dari node `now`. Hasil DFS akan dikumpulkan dalam `rest`.

#### 4. Fungsi `main`

```cpp
int n, m;
cin >> n >> m;
VVI graph(n + 1);
```

- Membaca jumlah node dan edge.
    
- `graph` di-deklarasikan dengan ukuran `n + 1` untuk mendukung indeks 1-based.
    

```cpp
for (int i = 0; i < m; i++) {
   int u, v;
   cin >> u >> v;
   graph[u].push_back(v);
   graph[v].push_back(u);
}
```

- Setiap edge `u–v` ditambahkan ke dalam list adjacency untuk kedua arah karena graph tak berarah.
    

```cpp
for (auto& x : graph) {
   ranges::sort(x);
}
```

- Menyortir setiap list adjacency agar traversal DFS dilakukan dalam urutan menaik.
    

```cpp
int x;
cin >> x;
searchComponents(graph, rest, x);
ranges::sort(rest);
```

- Membaca node awal, melakukan DFS, lalu menyortir hasil akhir `rest`.
    

```cpp
cout << rest.size() << '\n';
for (const auto& x : rest) {
   cout << x << " ";
}
```

- Mencetak jumlah node dalam komponen, diikuti oleh daftar node yang terhubung.
    

---

### 📌 Catatan Teknis

- Kompleksitas waktu: **O(n + m)**
    
- Kompleksitas memori: **O(n + m)**
    
- DFS cocok untuk graph sparse dan sangat efisien untuk menentukan komponen terhubung.
    

