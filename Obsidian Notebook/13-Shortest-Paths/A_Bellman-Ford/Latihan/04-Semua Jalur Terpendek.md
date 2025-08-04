---
obsidianUIMode: preview
note_type: latihan
latihan: Semua Jalur Terpendek
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - shortest-paths
date_learned: 2025-08-03T22:45:00
---
---
# Labirin Merah Berdarah

Setelah insiden terakhir, Toni terjebak di sebuah **labirin tua** yang konon dihuni oleh **Ghostface**. Di setiap percabangan lorong, Toni harus memilih dengan cepat, karena Ghostface bisa muncul dari belakang kapan saja.

Labirin ini terdiri dari `n` ruangan dan `m` lorong penghubung. Setiap lorong dapat dilalui dua arah. Toni ingin pergi dari ruangan `x` ke ruangan `y`, dan dia tahu bahwa **semakin lama dia berjalan, semakin besar kemungkinan dia tertangkap**.

Tugasmu adalah membantu Toni mencari tahu **ada berapa jalur berbeda** dari `x` ke `y` yang memiliki **panjang terpendek**, sehingga dia bisa memilih jalur mana pun tanpa memperlama waktu.

> Jalur dianggap berbeda jika urutan simpulnya berbeda. Graph **selalu terhubung** dan **tidak berbobot**.


#### Input:  

Baris pertama: dua bilangan bulat `n` dan `m`  
Lalu `m` baris, masing-masing dua bilangan `u v` (lorong dari `u` ke `v`)  
Baris terakhir: dua bilangan `x` dan `y`

#### Output:  

Satu baris: jumlah jalur terpendek dari `x` ke `y`

#### Contoh
Input:

```
10 16
1 2
2 3
3 4
4 5
5 6
1 7
7 8
8 9
9 10
10 6
2 8
8 4
4 10
7 3
3 9
9 5
1 6
```

![[graph (5).png]]

Output:

```
16
```

Dari semua kemungkinan jalur ini:

```
1 2 3 4 5 6 
1 2 3 4 5 9 10 6 
1 2 3 4 8 9 10 6 
1 2 3 4 8 9 5 6 
1 2 3 4 10 9 5 6 
1 2 3 4 10 6 
1 2 3 7 8 9 10 6
1 2 3 7 8 9 10 4 5 6
1 2 3 7 8 9 5 4 10 6
1 2 3 7 8 9 5 6
1 2 3 7 8 4 5 6
1 2 3 7 8 4 5 9 10 6
1 2 3 7 8 4 10 9 5 6
1 2 3 7 8 4 10 6
1 2 3 9 8 4 5 6
1 2 3 9 8 4 10 6
1 2 3 9 10 6
1 2 3 9 10 4 5 6
1 2 3 9 5 4 10 6
1 2 3 9 5 6
1 2 8 7 3 4 5 6
1 2 8 7 3 4 5 9 10 6
1 2 8 7 3 4 10 9 5 6
1 2 8 7 3 4 10 6
1 2 8 7 3 9 10 6
1 2 8 7 3 9 10 4 5 6
1 2 8 7 3 9 5 4 10 6
1 2 8 7 3 9 5 6
1 2 8 9 10 6
1 2 8 9 10 4 5 6
1 2 8 9 3 4 5 6
1 2 8 9 3 4 10 6
1 2 8 9 5 4 10 6
1 2 8 9 5 6
1 2 8 4 3 9 10 6
1 2 8 4 3 9 5 6
1 2 8 4 5 6
1 2 8 4 5 9 10 6
1 2 8 4 10 9 5 6
1 2 8 4 10 6
1 7 8 9 10 6
1 7 8 9 10 4 5 6
1 7 8 9 3 4 5 6
1 7 8 9 3 4 10 6
1 7 8 9 5 4 10 6
1 7 8 9 5 6
1 7 8 2 3 4 5 6
1 7 8 2 3 4 5 9 10 6
1 7 8 2 3 4 10 9 5 6
1 7 8 2 3 4 10 6
1 7 8 2 3 9 10 6
1 7 8 2 3 9 10 4 5 6
1 7 8 2 3 9 5 4 10 6
1 7 8 2 3 9 5 6 
1 7 8 4 3 9 10 6
1 7 8 4 3 9 5 6
1 7 8 4 5 6
1 7 8 4 5 9 10 6
1 7 8 4 10 9 5 6
1 7 8 4 10 6
1 7 3 2 8 9 10 6
1 7 3 2 8 9 10 4 5 6
1 7 3 2 8 9 5 4 10 6
1 7 3 2 8 9 5 6
1 7 3 2 8 4 5 6
1 7 3 2 8 4 5 9 10 6
1 7 3 2 8 4 10 9 5 6
1 7 3 2 8 4 10 6
1 7 3 4 5 6
1 7 3 4 5 9 10 6
1 7 3 4 8 9 10 6
1 7 3 4 8 9 5 6
1 7 3 4 10 9 5 6
1 7 3 4 10 6
1 7 3 9 8 4 5 6
1 7 3 9 8 4 10 6
1 7 3 9 10 6
1 7 3 9 10 4 5 6
1 7 3 9 5 4 10 6
1 7 3 9 5 6
```

16 diataranya adalah jalur terpendek, dengan ukuran yang sama:

```
1 2 3 4 5 6
1 2 3 4 10 6
1 2 3 9 10 6
1 2 3 9 5 6
1 2 8 9 10 6
1 2 8 9 5 6
1 2 8 4 5 6
1 2 8 4 10 6
1 7 8 9 10 6
1 7 8 9 5 6
1 7 8 4 5 6
1 7 8 4 10 6
1 7 3 4 5 6
1 7 3 4 10 6
1 7 3 9 10 6
1 7 3 9 5 6
```


<br/>

---
# Jawaban

Ini adalah jawaban yang sudah benar:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
using VVI = vector<vector<int>>;
using VB = vector<bool>;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void sorthestPath(VVI& graph, VB& visited, int now, int target, bool& found, int& count, int& mins, VI curr = {}) {
   curr.push_back(now);
   if (now == target) {
      if (!found) {
         count = 1;
         found = true;
         mins = curr.size();
      } else if (found && (mins > curr.size())) {
         count = 1;
         mins = curr.size();
      } else if (found && (mins == curr.size())) {
         count++;
      }

      return;
   }

   for (auto V : graph[now]) {
      if (!visited[V]) {
         visited[V] = true;
         sortestPath(graph, visited, V, target, found, count, mins, curr);
         visited[V] = false;
      }
   }
}

auto sorthestCount(VVI& graph, int now, int target) -> int {
   vector<bool> visited(graph.size(), false);
   bool found = false;
   int count = 0;
   int mins = INT_MAX;
   sortestPath(graph, visited, now, target, found, count, mins);
   return count;
}

auto main() -> int {
   fastio();
   int n, m;
   cin >> n >> m;

   VVI graph(n + 1);
   for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;

      graph[u].push_back(v);
      graph[v].push_back(u);
   }

   for (auto& row : graph) {
      ranges::sort(row);
   }

   int x, y;
   cin >> x >> y;

   int count = sorthestCount(graph, x, y);
   cout << count << '\n';

   return 0;
}

```

<br/>

---
# Editorial

Logika sederhana dimainkan disini. Kita tidak menyimpan banyaknya jalur yang mungkin pada array 2 dimensi, kita juga tidak mengambil satupun path atau jalur untuk dioutputkan. Yang perlu kita lakukan adalah mencari jalur terpendek, dan menghitung berapa banyak jalur lainya dengan panjang yang sama.

```cpp
auto sorthestCount(VVI& graph, int now, int target) -> int {
   vector<bool> visited(graph.size(), false);
   bool found = false;
   int count = 0;
   int mins = INT_MAX;
   sorthestPath(graph, visited, now, target, found, count, mins);
   return count;
}
```

Saat pencarian menemukan target untuk pertama kali, nilai `count` diubah menjadi 1, kita menetapkan nilai `mins` dengan panjang path `curr` pertama yang menemukan target, dan merubah `found` menjadi `true`, untuk memulai algoritma mencari path terpendek dengan perbandingan. Mekanisme ini ada pada kondisional `if(!found)`, seperti pada baris berikut:

```cpp
if (now == target) {
  if (!found) {
	 count = 1;
	 found = true;
	 mins = curr.size();
  } else if (found && (mins > curr.size())) {
	 count = 1;
	 mins = curr.size();
  } else if (found && (mins == curr.size())) {
	 count++;
  }
```

Ketika pencarian kedua, dan seterusnya mencapai target, akan ada 3 kondisi:

Kondisi pertama ialah ketika ukuran `curr` lebih besar dari nilai `mins`. Ini artinya rute yang ditemukan oleh `curr` tidak lebih pendek dari nilai yang sekaang, sehingga kita skip.

Kondisi kedua, adalah ketika pencarian `curr` menemukan rute yang lebih pendek dari rute yang disimpan di `mins`. Ketika rute yang lebih pendek ditemukan, kita mereset nilai `count` ke 1, dan memperbarui nilai `mins` ke panjang rute yang lebih pendek.

Kondisi ketiga, adalah ketika pencarian `curr`, menemukan rute yang sama pendeknya dengan panjang rute yang disimpan di `mins`. Ketika hal ini terjadi, kita menghitung banyaknya rute terpendek yang sama nilainya, sehingga kita lakukan `count++`.

Variabel `count` dan `mins` kita jadikan sebagai paramter yang menerima pass by reference, supaya bisa mengubah nilai inisialisasi awal yang ditetapkan pada fungsi `sorthestCount()`. Fungsi `shorthestCount()` kemudian mengembalikan variabel `count` yang sudah terisi banyaknya rute terpendek hasil pemanggilan fungsi `shorthesPath()`, yang kemudian ditampilkan di `main`.





