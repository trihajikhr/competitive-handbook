---
obsidianUIMode: preview
note_type: latihan
latihan: Apakah Graph Multigraph atau Simple
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - graph-basic
date_learned: 2025-08-16T22:40:00
---
---
# 1 | Apakah Graph Multigraph atau Simple

Diberikan sebuah graf dengan **n** simpul dan **m** sisi. Tentukan apakah graf tersebut adalah **multigraph** atau **simple graph**.

- Graf disebut **multigraph** jika memiliki **setidaknya satu self-loop** atau **setidaknya satu pasangan simpul yang terhubung oleh lebih dari satu sisi**.
    
- Graf disebut **simple graph** jika tidak mengandung keduanya.


```ad-info
Multigraf adalah jenis graf (struktur data dalam matematika) yang memperbolehkan adanya sisi ganda (paralel) di antara dua simpul. Artinya, dua simpul bisa dihubungkan oleh lebih dari satu sisi. 

Contohnya adalah sebagai berikut:

![[04-Apakah Graph Multigraph-1.png]]
```

```ad-info
Graf simple adalah jenis graf dalam matematika dan ilmu komputer yang tidak memiliki sisi ganda (multiple edges) maupun gelang (loops). Sisi ganda adalah dua atau lebih sisi yang menghubungkan simpul yang sama, sedangkan gelang adalah sisi yang menghubungkan sebuah simpul dengan dirinya sendiri. Dengan kata lain, dalam graf simple, setiap pasangan simpul hanya dapat dihubungkan oleh paling banyak satu sisi, dan tidak ada sisi yang dimulai dan diakhiri pada simpul yang sama.

Contohnya adalah sebagai berikut:

![[graph (2).png]]
```

<br/>

---
# 2 | Jawaban

Berikut adalah jawaban ku yang sudah benar:

```cpp
#include <iostream>
#include <set>
#include <vector>
using namespace std;

using VVS = vector<set<int>>;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

auto main() -> int {
   fastio();
   int n, m;
   cin >> n >> m;
   VVS graph(n + 1);

   bool multi = false;

   for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;

      if (u == v || graph[u].count(v) || graph[v].count(u)) {
         multi = true;
      }

      graph[u].insert(v);
      graph[v].insert(u);
   }

   cout << (multi ? "MULTIGRAPH" : "SIMPLE");

   return 0;
}
```

<br/>

---
# 3 | Editorial

## 3.1 | Penjelasan per blok kode program
### 1. Masalah

Kita diminta menentukan apakah sebuah graf merupakan **multigraph** atau **simple graph**.

- **Multigraph** → mengandung _self-loop_ atau _multiple edge_.
    
- **Simple graph** → tidak ada self-loop dan tidak ada multiple edge.
    

Input:

- Jumlah simpul `n` dan jumlah sisi `m`.
    
- Diikuti `m` baris pasangan `(u, v)` yang merepresentasikan sisi.
    

Output:

- `"MULTIGRAPH"` jika ditemukan self-loop atau multiple edge.
    
- `"SIMPLE"` jika tidak ada keduanya.
    

### 2. Representasi

Kita gunakan **vector of set**:

```cpp
using VVS = vector<set<int>>;
VVS graph(n + 1);
```

- `graph[u]` menyimpan semua simpul yang terhubung dengan `u`.
    
- `set` digunakan supaya elemen unik (tidak bisa duplikat).
    


### 3. Pemeriksaan Self-loop

```cpp
if (u == v) multi = true;
```

- Jika ada sisi dari simpul ke dirinya sendiri, langsung tandai sebagai multigraph.
    

### 4. Pemeriksaan Multiple edge

```cpp
if (graph[u].count(v)) multi = true;
```

- Jika simpul `v` sudah ada di `graph[u]`, artinya sisi `(u, v)` sudah pernah dimasukkan.
    
- Karena graf undirected, cukup cek satu arah saja.


### 5. Menambahkan Edge

```cpp
graph[u].insert(v);
graph[v].insert(u);
```

- Setelah dicek, sisi `(u, v)` baru ditambahkan.
    
- Menyimpan dua arah karena graf undirected.

### 6. Output

```cpp
cout << (multi ? "MULTIGRAPH" : "SIMPLE");
```

- Jika ditemukan kasus self-loop atau multiple edge → `"MULTIGRAPH"`.
    
- Jika aman → `"SIMPLE"`.


### 7. Kode Lengkap

```cpp
#include <iostream>
#include <set>
#include <vector>
using namespace std;

using VVS = vector<set<int>>;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

auto main() -> int {
   fastio();
   int n, m;
   cin >> n >> m;
   VVS graph(n + 1);

   bool multi = false;

   for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;

      if (u == v || graph[u].count(v)) {
         multi = true;
      }

      graph[u].insert(v);
      graph[v].insert(u);
   }

   cout << (multi ? "MULTIGRAPH" : "SIMPLE");

   return 0;
}
```

Jadi ringkasnya:

- **Self-loop** → `u == v`
    
- **Multiple edge** → `graph[u].count(v) == true`
    
- Jika salah satu terjadi → **multigraph**

## 3.2 | Multigraph vs Simple graph

Konsep **multigraph** dan **simple graph** saling berkaitan secara langsung.

- **Simple graph** adalah graph yang tidak mengandung self-loop maupun multiple edge.
    
- **Multigraph** adalah graph yang mengandung setidaknya satu self-loop atau satu multiple edge.
    

Dengan definisi tersebut, jelas bahwa sebuah graph hanya mungkin termasuk ke dalam salah satu dari keduanya. Jika suatu graph **bukan simple graph**, maka graph tersebut otomatis merupakan multigraph. Sebaliknya, jika suatu graph **bukan multigraph**, maka graph tersebut adalah simple graph.

Oleh karena itu, algoritma yang digunakan untuk mendeteksi adanya self-loop atau multiple edge sudah cukup untuk menentukan kedua hal sekaligus. Dengan kata lain, **pencarian multigraph identik dengan pencarian apakah graph tersebut simple atau tidak**, sehingga tidak diperlukan algoritma terpisah untuk masing-masing.