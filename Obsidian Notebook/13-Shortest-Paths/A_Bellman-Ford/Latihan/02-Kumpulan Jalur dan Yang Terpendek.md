---
obsidianUIMode: preview
note_type: latihan
latihan: Mencari Jalur Terpendek
sumber:
  - myself
tags:
  - graph-algorithm
  - shortest-paths
date_learned: 2025-08-03T18:27:00
---
---
# Toni dan Rumah Barunya

Toni baru saja berpindah ke rumah baru, di kota baru. Di kota barunya, ada banyak tempat-tempat penting yang harus ia kunjungi untuk memenuhi banyak kebutuhan hitup. Terdapat $n$ tempat dan $m$ jalur yang menghubungkan setiap tempat tersebut.

Toni ingin mencatat dalam cataanya, tempat apa yang bisa ia kunjungi jika ia pergi dari tempat yang berada diposisi $x$ ke posisi $y$, sekaligus mencari jalur terpendek yang mungkin bisa dia ambil.

Tugasmu adalah mencetak semua jalur yang mungkin, dari posisinya sekarang, ke posisi tujuan, sekaligus mencetak jalur terpendek yang bisa diambil.

Graph undirected, tidak berbobot, dan semua node saling terhubung.

#### Input

Baris pertama berupa $n$ dan $m$, banyaknya node dan banyaknya dan banyaknya jalur.

$m$ baris berikutnya adalah keterhubungan antar node, yaitu $a$ dan $b$. 

Lalu baris terakhir adalah $x$ dan $y$. Posisinya sekarang, ke posisi tujuan

#### Output

Cetak semua jalur yang bisa Toni ambil, lalu cetak juga jalur terpendek yang mungkin.

#### Contoh

Input:

```
13 17
1 2
1 3
1 4
2 3
3 4
1 5
5 6
6 7
6 8
8 9
7 9
9 10
10 11
11 12
3 13
13 11
1 12
4 7
```

![[graph (3).png]]

Output:

```
4 1 2 3 13 11 10 9 7 
4 1 2 3 13 11 10 9 8 6 7 
4 1 3 13 11 10 9 7 
4 1 3 13 11 10 9 8 6 7 
4 1 5 6 7
4 1 5 6 8 9 7
4 1 12 11 10 9 7
4 1 12 11 10 9 8 6 7
4 3 1 5 6 7
4 3 1 5 6 8 9 7
4 3 1 12 11 10 9 7
4 3 1 12 11 10 9 8 6 7
4 3 2 1 5 6 7
4 3 2 1 5 6 8 9 7
4 3 2 1 12 11 10 9 7
4 3 2 1 12 11 10 9 8 6 7
4 3 13 11 10 9 7
4 3 13 11 10 9 8 6 7
4 3 13 11 12 1 5 6 7
4 3 13 11 12 1 5 6 8 9 7

Shortest: 4 1 5 6 7
```

<br/>



---
# Jawaban

Berikut adalah jawabanku yang sudah benar:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
using VVI = vector<vector<int>>;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void getAllPath(VVI& graph, VVI& rest, vector<bool>& visited, int now, int target, VI curr = {}) {
   curr.push_back(now);

   if (now == target) {
      rest.push_back(curr);
      return;
   }

   for (auto v : graph[now]) {
      if (!visited[v]) {
         visited[v] = true;
         getAllPath(graph, rest, visited, v, target, curr);
         visited[v] = false;
      }
   }
}

void printAllPath(VVI& rest) {
   int mins = INT_MAX;
   int idx, count = 0;

   for (const auto& row : rest) {
      if (mins > row.size()) {
         idx = count;
         mins = row.size();
      }
      count++;
      for (const auto& x : row) {
         cout << x << " ";
      }

      cout << '\n';
   }

   // cetak jalur terpendek
   cout << "\nShortest: ";
   for (int i : rest[idx]) {
      cout << i << " ";
   }
}

auto main() -> int {
   fastio();
   int n, m;
   cin >> n >> m;

   // array 1 based index
   VVI graph(n + 1), rest;
   vector<bool> visited(n + 1, false);

   for (int i = 0, u, v; i < m; i++) {
      cin >> u >> v;

      graph[u].push_back(v);
      graph[v].push_back(u);
   }

   // merapikan array graph
   for (auto& x : graph) {
      std::ranges::sort(x);
   }

   int x, y;
   cin >> x >> y;

   visited[x] = true;

   getAllPath(graph, rest, visited, x, y);
   printAllPath(rest);

   return 0;
}

```

<br/>

---
# Editorial

Editorial yang akan kubuat kali ini hanya berfokus pada bagian yang belum dijelaskan di latihan soal sebelumnya. Hampir sebagian besar kode ini menggunakan pendekatan yang sama, jadi jik ada bagian yang belum paham yang tidak dijelaskan disini, buka saja latihan sebelumnya!

Pada saat kita membuat graph dari node-node, semua node tersimpan dalam adjacency list. Supaya kita bisa merapikan setiap larik node dalam graph, kita bisa sort terlebih dahulu, dengan cara ini:

```cpp
for (auto& x : graph) {
  std::ranges::sort(x);
}
```

Ini berguna supaya tampilan output lebih bersih dan rapi, tapi tidak ada hubunganya dengan algoritma penyelesaiana, ini hanya masalah kerapian output saja.

Setelah kita mendapat semua jalur, kita cetak saja langsung. Namun, sambil menyelam minum air, kita sisipkan algoritma pencarian jalur terpendek, dengan mengukur array mana dari kumpulan array yang tersimpan di array dua dimensi, yang memiliki ukuran paling kecil:

```cpp
int mins = INT_MAX;
int idx, count = 0;

for (const auto& row : rest) {
  if (mins > row.size()) {
	 idx = count;
	 mins = row.size();
  }
  count++;
  // operasi lain...
}
```

Kita gunakan fungsi `size()` untuk mendapatkan ukuran arraynya. Dan karena kita menggunakan for-each loop, kita harus menambahkan `count` didalamnya, dan juga `idx` untuk menyimpan nilai terkecil jika didapat nilai terkecil. Perbarui nilai `mins` jika ada array dengan ukuran yang lebih kecil nilainya dari `mins`.

Pembahasan ini terlalu mudah untuk dijelaskan panjang lebar, cukup pahami saja bahwa tugas kita hanyalah mencari nilai terkecil.