---
obsidianUIMode: preview
note_type: latihan
latihan: Graph Eulerian Circuit (undirected)
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - graph-basic
date_learned: 2025-08-17T14:49:00
---
---
# 1 | Graph Eulerian Circuit (undirected)

Diberikan sebuah graph undirected. Tugasmu adalah menentukan apakah graph yang diberikan memiliki sirkuit euler. Jika ada, maka outputkan `YES` dan path nya, dan jika tidak maka outputkan `NO`.

```ad-info
Graf Eulerian adalah suatu graf yang memiliki sirkuit Euler, yaitu lintasan yang dimulai dan diakhiri pada simpul yang sama, serta melewati setiap sisi (edge) dalam graf tepat satu kali. Dengan kata lain, sebuah graf disebut Eulerian jika dan hanya jika setiap simpulnya memiliki derajat genap (jumlah sisi yang terhubung ke simpul tersebut adalah genap).

Contohnya adalah graph berikut:

![[graph (9).png]]

Dimana sirkuit euler yang terbentuk, jika kita memulai traversal dari titik 1, maka pathnya adalah 1 –> 2 –> 3 –> 4 –> 5 –> 1 –> 6 –> 7 –> 1

Untuk mengetahui apakah graph mungkin untuk memiliki sirkuit euler, ada beberapa syarat, diataranya:

- Graph harus connected, (semua simpul dengan degre > 0 ada di satu komponen yang sama)
- Tidak ada node dengan degree ganjil
```

<br/>

---
# 2 | Jawaban

Berikut adalah jawabanku yang sudah benar. Harap ingat satu hal, algoritma yang kita pelajari di bab 11 Basic of Graph ini tidak terlalu fokus pada efisiensi. Hanya untuk latihan graph, dan pengenalan algoritma graph.

Kenyataanya, DFS pada graph sering kali tidak efisien, karena kompleksitasnya yang eksponensial di graph besar dapat mengakibatkan runtime limit. 

Jadi, anggap saaj ini sebagai latihan saja, di pembejalaran di bab-bab yang akan datang, kita baru akan mulai mempelajari algoritma yang lebih efisien. Untuk kasus menentukan apakah graph eulerian atau tidak, kita sebenarnya bisa menggunakan algoritma yang lebih efisien seperti algoritma ***Hierholzer***.

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using VVP = vector<vector<pair<int, int>>>;
using VI = vector<int>;
using VB = vector<bool>;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void isConnected(VVP& graph, VB& visited, int now, VI& curr) {
   curr.push_back(now);
   for (const auto& [node, ID] : graph[now]) {
      if (!visited[node]) {
         visited[node] = true;
         isConnected(graph, visited, node, curr);
      }
   }
}

void dfsRec(VVP& graph, VI& edgesID, VI& path, int now, int target, bool& found) {
   if (found)
      return;
   path.push_back(now);

   if (now == target) {
      bool allUsed = true;
      for (int i = 1; i < edgesID.size(); i++) {
         if (edgesID[i] != 0) {
            allUsed = false;
            break;
         }
      }

      if (allUsed) {
         found = true;
         return;
      }
   }

   for (const auto& [node, ID] : graph[now]) {
      if (edgesID[ID]) {
         int temp = edgesID[ID];
         edgesID[ID] = 0;
         dfsRec(graph, edgesID, path, node, target, found);
         edgesID[ID] = temp;
         if (!found)
            path.pop_back();
      }
   }
}

auto isEuler(VVP& graph, VI& edgesID) -> pair<int, VI> {
   bool found = false, connected = false;
   vector<bool> visited(graph.size(), false);
   vector<int> path, curr;
   int component = 0;

   // cek apakah graph connected
   for (int i = 1; i < graph.size(); i++) {
      if (!visited[i] && graph[i].size() > 0) {
         visited[i] = true;
         isConnected(graph, visited, i, curr);
         if (curr.size() > 0) {
            component++;
         }

         curr.clear();
      }

      if (component > 1) {
         break;
      }
   }

   if (component > 1) {
      return {-2, {}};
   } else {
      int start = -1;
      for (int i = 1; i < graph.size(); i++) {
         if (graph[i].size() > 0) {
            start = i;
            break;
         }
      }
      if (start != -1)
         dfsRec(graph, edgesID, path, start, start, found);
   }
   if (!found)
      return {-1, {}};
   return {1, path};
}

auto main() -> int {
   fastio();
   int n, m;
   cin >> n >> m;
   vector<vector<pair<int, int>>> graph(n + 1);
   vector<int> edgesID(m + 1, 1);

   for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;

      graph[u].emplace_back(v, i + 1);
      graph[v].emplace_back(u, i + 1);
   }

   // ini mengecek apakah ada degre ganjil!
   bool isOdd = false;
   for (int i = 1; i <= n; i++) {
      if (graph[i].size() % 2 == 1) {
         isOdd = true;
         break;
      }
   }

   if (isOdd) {
      cout << "NO\n";
      cout << "Bukan graph Euler karena terdapat node dengan degree ganjil!";
   } else {
   
      // sorting supaya hasilnya enak didebug cuy
      for (auto& adj : graph) {
         ranges::sort(adj, [](auto& a, auto& b) { 
	         return a.first < b.first; 
         });
      }

      pair<int, vector<int>> rest = isEuler(graph, edgesID);

      if (rest.first == -2) {
         cout << "NO\n";
         cout << "Graph disconnected dengan degree != 0";
      } else if (rest.first == -1) {
         cout << "NO\n";
         cout << "Tidak ditemukan path circuit euler";
      } else if (rest.first == 1) {
         cout << "YES\n";
         cout << "Graph Eulerian!\n";
         cout << "Path: ";
         for (int i = 0; i < rest.second.size(); i++) {
            cout << rest.second[i];
            if (i != rest.second.size() - 1) {
               cout << " -> ";
            }
         }
      }
   }
   return 0;
}
```

<br/>

---
# 3 | Editorial

```ad-question
Apakah graph undirected jika semua nodenya memiliki jumlah degre genap, sudah pasti memiliki circuit euler?
```

Jawabannya: **iya, dengan syarat graph-nya connected (terhubung)**.

Lebih tepatnya:

* **Teorema Euler (1736)** bilang:

  * Suatu **graph tak berarah** memiliki **Eulerian circuit** ⇔ **graph connected** (abaikan simpul isolated/degree 0) **dan semua simpulnya punya degree genap**.
  * Kalau ada tepat **dua simpul ganjil** → hanya punya **Eulerian path**, bukan circuit.

Jadi:

* Kalau semua simpul derajatnya genap → **pasti ada Eulerian circuit**, asal tidak terpecah jadi beberapa komponen.
* Kalau graph disconnected → walaupun semua derajat genap, tetap **bukan Eulerian** (karena kamu nggak bisa “menjahit” semua edge dalam satu lintasan).

⚡ Contoh counter-case: dua buah segitiga terpisah (masing-masing degree simpulnya genap = 2), tapi graph tidak connected → tidak Eulerian.

```ad-todo
Editorial dari kode diatas sangat panjang, aku belum ada waktu untuk menulisnya sendiri. Dan jujur saja, dibutuhkan 6 jam lebih untuk menyempurnakan algoritma tersebut!

Tapi karena hal itu, aku rasa tidak perlu terburu-buru membuat editorialnya, karena sudah lumayan nempel di ingatan, haha 😂.

Lagipula, ada algoritma hierholzer yang lebih pas jika tujuanya adalah mencari apakah graph yang diberikan merupakan graph eulerian!
```
