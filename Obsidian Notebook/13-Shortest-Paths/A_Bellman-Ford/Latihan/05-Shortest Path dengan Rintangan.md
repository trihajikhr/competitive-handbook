---
obsidianUIMode: preview
note_type: latihan
latihan: Shortest Path dengan Rintangan
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - shortest-paths
date_learned: 2025-08-04T01:34:00
---
---
# I'm All Alone Here Darling

Sudah larut malam di asrama, dan Jake berusaha menyelinap ke **kamar Angelica** untuk melakukan sesuatu yang... yahh... jelas-jelas tidak boleh diceritakan 😏. Tapi situasinya rumit.

![[05-Shortest Path dengan Rintangan-1.png]]

Tiga kawannya—**Delta**, **India**, dan **Juliet**—saat ini sedang memperketat pengawasan dengan memasang kamera pengawas di setiap lorong. Kalau Jake nekat lewat situ, siap-siap reputasinya runtuh.

Lorong-lorong rahasia sebanyak $m$ menghubungkan kamar-kamar lainnya yang berjumlah $n$, dan Jake tahu semua rute yang  mungkin. Tapi waktu tak tersisa banyak.

Temukan **satu rute tercepat dari kamar Jake ke Angelica** tanpa melewati kamera yang dipasang oleh **Delta**, **India**, dan **Juliet**. Kalau tidak ada jalan aman malam ini, yah... mungkin Jake harus menahan rindu.

#### Input

Inputan terdiri dari $n$ dan $m$, yang merepresentasikan banyaknya kamar. Setelah itu terdapat $m$ baris yang terdiri dari inputan $u$ dan $v$, merepresentasikan hubungan antar lorong, dan keterangan ada tidaknya kamera di setiap lorong. Jika nilainya 1, artinya ada kamera, jika 0, maka aman.

Inputan selanjutnya adalah $x$ dan $y$, lokasi kamar Jake, dan lokasi kamar Angelica.

#### Output

Cetak satu baris yang merupakan jalur terpendek yang aman, yang bisa diambil oleh Jake. Atau cetak "Menahan rindu" jika tidak ada jalur yang bisa diambil oleh Jake yang malang.

#### Contoh

Input:

```
13 21
1 2 1
1 3 1
1 4 0
4 5 0
5 2 1
4 6 1
2 7 0
7 8 0
8 3 1
1 6 1
8 9 0
3 6 0
4 10 0
11 9 1
11 7 0
3 2 0
6 5 0
10 12 1
12 13 0
13 5 1
13 10 0
11 12
```

![[graph (6).png]]

Output:

```
11 7 2 3 6 5 4 10 13 12 
```

<br/>

---
# Jawaban

Berikut jawabanku yang sudah solid:

```cpp
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void getSecurePath(vector<vector<tuple<int, int>>>& graph, vector<int>& rest, vector<bool>& visited, int now, int target, bool& found, vector<int> curr = {}) {
   curr.push_back(now);
   if (now == target) {
      if (!found) {
         rest = curr;
         found = true;
      } else if (curr.size() < rest.size()) {
         rest = curr;
      }

      return;
   }

   for (const auto& V : graph[now]) {
      auto [to, cam] = V;
      if (cam == 0 && !visited[to]) {
         visited[to] = true;
         getSecurePath(graph, rest, visited, to, target, found, curr);
         visited[to] = false;
      }
   }
}

void securePath(vector<vector<tuple<int, int>>>& graph, vector<int>& rest, int now, int target) {
   vector<bool> visited(graph.size(), false);
   visited[now] = true;
   bool found = false;
   getSecurePath(graph, rest, visited, now, target, found);
}

auto main() -> int {
   fastio();
   int n, m;
   cin >> n >> m;
   vector<vector<tuple<int, int>>> graph(n + 1);
   vector<int> rest;

   for (int i = 1; i <= m; i++) {
      int u, v, k;
      cin >> u >> v >> k;

      graph[u].emplace_back(v, k);
      graph[v].emplace_back(u, k);
   }

   int x, y;
   cin >> x >> y;

   securePath(graph, rest, x, y);
   if (rest.empty()) {
      cout << "Menahan rindu\n";
   } else {
      for (const auto& x : rest) {
         cout << x << " ";
      }
   }
   return 0;
}
```


<br/>

---
# Editorial