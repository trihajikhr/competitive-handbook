---
obsidianUIMode: preview
note_type: latihan
latihan: Mencari Rute Terpendek
sumber:
  - myself
tags:
  - graph-algorithm
  - shortest-path
date_learned: 2025-08-04T15:38:00
---
---
# Pesta Liga Lagenda!

Kerajaan Arrakis baru saja memenangkan kejuaraan Liga Lagenda untuk pertama kali setelah 2000 tahun menanti. Pagelaran Liga Lagenda umumnya diselenggarakan 100 tahun sekali, di inti Sabuk Galaksi. Jelas kemenangan besar tersebut membawa banyak sekali pesta diseluruh penjuru negri, termasuk pesta diwilayah universitas Dune, tempat Paul menuntut ilmu.

Tidak mau ketinggalan pesta, Paul berusaha untuk merancang rute sebagai persiapan pesta esok hari. Terdapat $n$ tempat dengan $m$ jalan yang menghubungkan tempat-tempat tersebut. Jarak dari satu tempat ke tempat lain adalah $w$, dan beruntungnya, Paul mengetahui semua jalan berkat memory supernya. 

Tetapi, Paul khawatir bahwa ada mata-mata Bene Geserit kerajaan yang mungkin sudah mengetahui rencananya, sehingga ada kemungkinan mereka akan menyelinap ke kamarnya dan mengambil rancangan petanya, sehingga bisa mengikutinya besok. 

![[06-Mencari Rute Terpendek-1.png]]

Untuk mengantisipasi hal ini, Paul berencana untuk membuat peta palsu. Karena Paul tahu bahwa Bene Geserit mungkin tidak sebodoh itu, dia berencana untuk membuat 2 peta. Peta pertama berisi peta dengan rute terpendek kedua, dan peta kedua berisi rute terjauh, barang kali Bene Geserit tidak sepintar yang ia kira.

Sekarang, bantu Paul membuat rancangan petanya dan 2 peta untuk mengelabui mata-mata kerajaan, sehingga Paul bisa mengamankan petanya dengan aman.

#### Input
Inputan terdiri dari $n$ dan $m$, yaitu banyaknya tempat dan banyaknya jalur. Setelah itu, terdapat $m$ baris, yang terdiri dari $u,v,w$, dimana $u$ dan $v$ artinya kedua node tersebut terhubung dalam jalur yang memiliki jarak sebsar $w$.

Baris terakhir berisi $x$ dan $y$, lokasi Asrama Paul dan lokasi pesta esok hari.

Dijamin bahwa graph terhubung, dan inputan valid.

#### Output

Cetak 6 baris, yaitu:
- Baris pertama berisi besar total jarak yang berhasil Paul tempuh, dan baris dibawahnya adalah rute yang ia ambil.
- Baris ketiga berisi besar total jarak yang sesuai dengan syarat peta kedua, dan rute yang diambilnya.
- Baris kelimat berisi besar total jarak yang sesuai dengan syarat peta ketiga, dan rute yang diambilnya

#### Contoh:
Input:

```
14 24
1 2 5
1 3 7
1 4 9
1 5 11
4 5 14
5 6 19
6 7 20
3 7 10
7 8 7
9 5 6
8 1 11
3 2 19
7 10 4
10 11 13
11 3 7
11 12 16
9 6 15
12 2 9
9 13 14
13 6 12
6 14 11
14 13 10
14 10 8
7 14 10
2 13
```

![[graph (7).png]]

Output:

```
36
2 1 5 9 13
43
2 1 8 7 14 13
146
2 3 11 10 14 7 8 1 4 5 6 9 13
```

Jalur terpendek, dan jalur terpendek kedua:

![[06-Mencari Rute Terpendek-2.png]]

Jalur terjauh:

![[06-Mencari Rute Terpendek-3.png]]

<br/>

---
# Jawaban

Berikut jawaban yang sudah benar:

```cpp
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

using VVT = vector<vector<tuple<int, int>>>;
using VPV = vector<pair<int, vector<int>>>;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void getAllPath(VVT& graph, VPV& rest, vector<bool>& visited, bool& nefar, int& now, int& target, int& mins, int& maks, vector<int> curr = {}, int sumpath = 0) {

   curr.push_back(now);

   if (now == target) {
      if (!nefar) {
         rest[0] = {sumpath, curr};
         mins = sumpath;

         rest[1] = {sumpath, curr};
         maks = sumpath;
         nefar = true;
      } else if (sumpath < mins) {
         mins = sumpath;
         rest[0] = {mins, curr};
      } else if (sumpath != mins && sumpath < rest[1].first) {
         rest[1] = {sumpath, curr};
      }

      if (nefar && sumpath > maks) {
         maks = sumpath;
         rest[2] = {maks, curr};
      }

      return;
   }

   for (const auto& V : graph[now]) {
      auto [to, weight] = V;
      if (!visited[to]) {
         sumpath += weight;
         visited[to] = true;
         getAllPath(graph, rest, visited, nefar, to, target, mins, maks, curr, sumpath);
         sumpath -= weight;
         visited[to] = false;
      }
   }
}

void getPath(VVT& graph, VPV& rest, int now, int target) {
   vector<bool> visited(graph.size(), false);
   visited[now] = true;
   bool nefar = false;
   int mins = INT_MAX;
   int maks = INT_MIN;
   getAllPath(graph, rest, visited, nefar, now, target, mins, maks);
}

auto main() -> int {
   fastio();
   int n, m;
   cin >> n >> m;
   vector<vector<tuple<int, int>>> graph(n + 1);
   vector<pair<int, vector<int>>> rest(3, {INT_MAX, {}});

   for (int i = 1; i <= m; i++) {
      int u, v, w;
      cin >> u >> v >> w;

      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, w);
   }

   for (auto& x : graph) {
      ranges::sort(x);
   }

   int x, y;
   cin >> x >> y;

   getPath(graph, rest, x, y);

   for (const auto& row : rest) {
      cout << row.first << '\n';
      for (const auto& x : row.second) {
         cout << x << " ";
      }
      cout << '\n';
   }

   return 0;
}

```

<br/>

---
# Editorial