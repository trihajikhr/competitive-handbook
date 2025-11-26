---
obsidianUIMode: preview
note_type: latihan
latihan: Apakah Graph Bipartite
sumber:
  - chatgpt.com
  - "buku: CP handbook by Antti Laaksonen"
tags:
  - graph-algorithm
  - graph-basic
date_learned: 2025-08-16T22:10:00
---
---
# 1 | Apakah Graph Bipartite

Diberikan sebuah graph. Tugasmu kali ini adalah menentukan apakah Graph yang diberikan adalah graph bipartite atau tidak. Jika graph tersebut adalah graph bipartite, cetak `YES`, jika tidak, maka cetak `NO`.

```ad-info
Masalah ini meminta kita menentukan apakah sebuah graf tak berarah bersifat bipartit atau tidak. Graf bipartit adalah graf yang simpul-simpulnya dapat dibagi menjadi dua kelompok, sehingga setiap sisi selalu menghubungkan simpul dari kelompok pertama ke simpul dari kelompok kedua. Konsekuensinya, jika dua simpul bertetangga ternyata berada pada kelompok yang sama, maka graf otomatis tidak bipartit.

Berikut adalah contoh gambaran graph yang bipartit:

![[03-Apakah Graph Bipartite-1.png]]
```


<br/>

---
# 2 | Jawaban

Berikut adalah jawabanku, yang sudah direvisi berkali-kali dan akhirnya menjadi lebih sempurna:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using VVI = vector<vector<int>>;
using VI = vector<int>;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void dfsRec(VVI& graph, vector<int>& color, int now, bool& val) {
   if (!val)
      return;

   for (auto& A : graph[now]) {
      if (color[A] == 0) {
         color[A] = (color[now] == 1 ? 2 : 1);

         dfsRec(graph, color, A, val);
      } else {
         if (color[A] == color[now]) {
            val = false;
            return;
         }
      }
   }
}

auto isBipartite(VVI& graph) -> bool {
   bool val = true;
   vector<int> color(graph.size(), 0);

   for (int i = 1; i < graph.size(); i++) {
      if (color[i] == 0) {
         color[i] = 1;

         dfsRec(graph, color, i, val);
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

   for (auto& x : graph) {
      ranges::sort(x);
   }

   cout << (isBipartite(graph) ? "YES" : "NO");

   return 0;
}
```

<br/>

---
# 3 | Editorial

Untuk menyelesaikan masalah ini, kita bisa melakukan pewarnaan simpul dengan dua warna. Caranya, ambil simpul yang belum diwarnai, lalu warnai dengan warna pertama. Dari simpul ini, semua tetangganya harus diberi warna kedua. Proses ini dilanjutkan secara rekursif atau dengan traversal (DFS/BFS). Jika suatu saat ditemukan dua simpul yang bertetangga tetapi memiliki warna yang sama, berarti graf tidak bipartit.

Kita juga harus memperhatikan bahwa graf bisa saja tidak terhubung. Oleh karena itu, pewarnaan harus dilakukan untuk setiap komponen terhubung. Implementasi akhirnya menggunakan DFS rekursif untuk memberi warna pada simpul. Jika seluruh proses berjalan tanpa konflik warna, maka graf bipartit, dan kita keluarkan jawaban "YES". Sebaliknya, jika ada konflik, maka jawabannya "NO".

Kompleksitas waktu algoritma ini adalah $O(n + m)$, karena setiap simpul dan sisi hanya dikunjungi sekali. Dengan demikian, algoritma ini cukup efisien untuk batasan input yang besar.

Jika biasanya kita menandai suatu graph sudah dikunjungi dengan menggunakan bantuan vector `visited`, disini kita bisa menggantikanya dengan vector `color`, dimana kita menandai semua graph memiliki color `0`, ini juga menjadi pentunjuk bahwa graph belum dikunjungi, dan harus di traversal.

```cpp
void dfsRec(VVI& graph, vector<int>& color, int now, bool& val) {
   if (!val)
      return;

   for (auto& A : graph[now]) {
      if (color[A] == 0) {
         color[A] = (color[now] == 1 ? 2 : 1);

         dfsRec(graph, color, A, val);
      } else {
         if (color[A] == color[now]) {
            val = false;
            return;
         }
      }
   }
}
```

Jika kita mendapati ada node tetangga yang masih memiliki warna `0`, maka kita kunjungi, dan lakukan pemberian warna yang berlawanan dengan warna dari node sekarang atau `now`.

Tetapi, jika kita juga memiliki edge dengan node lain yang sudah dikunjungi, maka kita perlu melakukan pemeriksaan terhadap node tersebut. Dimana jika node tersebut memiliki warna yang berbeda dengan warna sekarang, maka itu aman. Tetapi jika warnanya sama dengan node sekarang, maka artinya graph tersebut bukanlah graph bipartit, sehingga kita lakukan early stop, dengan mengganti `val` menjadi false, dan return.