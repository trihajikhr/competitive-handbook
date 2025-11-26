---
obsidianUIMode: preview
note_type: latihan
latihan: Jumlah Komponen Terhubung
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - graph-traversal
  - graph-DFS
date_learned: 2025-08-05T01:52:00
---
---
# Hitung Jumlah Komponen Terhubung

Diberikan sebuah graph **tak berarah** dengan `n` simpul dan `m` sisi, yang mungkin terdiri dari beberapa komponen. Tugas Anda adalah **menghitung jumlah komponen terhubung** dalam graph tersebut.

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
Satu bilangan bulat — jumlah komponen terhubung.
Dan kemudian diikuti node yang ada pada masing-masing komponent.

### Contoh:
Input:

```txt
10 6
1 2
2 3
4 5
6 7
8 9
9 10
```

Output:

```
4
1 2 3 
4 5 
6 7 
8 9 10 
```

🔎 Penjelasan:

Komponen-komponen:

- {1,2,3}
    
- {4,5}
    
- {6,7}
    
- {8,9,10}
    


<br/>

---
# Jawaban

Berikut adalah jawabanku yang sudah benar:

```cpp
#include <algorithm>
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

void dfsSearch(VVI& graph, VI& curr, VB& visited, int now) {
   curr.push_back(now);

   for (const auto& v : graph[now]) {
      if (!visited[v]) {
         visited[v] = true;
         dfsSearch(graph, curr, visited, v);
      }
   }
}

void preComponents(VVI& graph, VVI& rest, VB& visited) {
   VI curr;
   for (int i = 1; i < graph.size(); i++) {
      if (!visited[i]) {
         visited[i] = true;
         dfsSearch(graph, curr, visited, i);
         ranges::sort(curr);
         rest.push_back(curr);
         curr.clear();
      }
   }
}

auto main() -> int {
   fastio();
   int n, m;
   cin >> n >> m;
   VVI graph(n + 1), rest;
   VB visited(n + 1, false);

   for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;

      graph[u].push_back(v);
      graph[v].push_back(u);
   }

   preComponents(graph, rest, visited);

   cout << rest.size() << '\n';
   for (const auto& row : rest) {
      for (const auto& x : row) {
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

Untuk bisa mengiterasi semua node seandainya graph yang diberikan adalah graph yang disconnected, maka kita harus menjadikan semua node sebagai node awal, dan memulai dari sana. Ini akan membuat kita melakukan DFS dari beberapa titik lokasi yang berbeda, sehingga semua node pada graph berhasil dikunjungi.

```cpp
void dfsSearch(VVI& graph, VI& curr, VB& visited, int now) {
   curr.push_back(now);

   for (const auto& v : graph[now]) {
      if (!visited[v]) {
         visited[v] = true;
         dfsSearch(graph, curr, visited, v);
      }
   }
}

void preComponents(VVI& graph, VVI& rest, VB& visited) {
   VI curr;
   for (int i = 1; i < graph.size(); i++) {
      if (!visited[i]) {
         visited[i] = true;
         dfsSearch(graph, curr, visited, i);
         ranges::sort(curr);
         rest.push_back(curr);
         curr.clear();
      }
   }
}
```

Fungsi `preComponents()` akan menyiapkan array `curr` untuk menampung setiap node yang ada pada masing-masing komponent jika graph yang diberikan adalah graph disconnected. Dimana array `curr` akan terisi darri pemanggilan fungsi `dfsSearch()`.

Kita memanggil fungsi DFS beberapa kali, dengan mengandalkan banyaknya Node yang  ada pada graph, ini memastikan mekanisme memulai DFS dari berbagai titik node yang belum dikunjungi. Ketika suatu node masih `false`, padahal sudah memanggil fungsi DFS, itu pertanda bahwa node tersebut berada di komponen yang berbeda, sehingga fungsi `preComponents()` akan memulai DFS lagi dari sana.

Perulangan ini akan menjalakan DFS yang berbeda-beda hanya jika pemanggilan satu fungsi DFS tidak berhasil mengunjungi semua node. Jika graph yang diberikan adalah graph connected, pemanggilan fungsi akan tetap berjalan sekali, karena semua node akhirnya berhasil dikunjungi, membuat array `visited` semuanya menjadi true.

Setelah satu komponen dari graph berhasil didapatkan, kita sort terlebih dahulu nilai didalam array `curr`, lalu masukan ke dalam array `rest`. Untuk mempersiapkan pengisian selanjutnya, kita kosongkan saja array `curr`, dengan `curr.clear()`.

