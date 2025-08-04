---
obsidianUIMode: preview
note_type: latihan
latihan: Mencari Satu Jalur Terpendek
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - shortest-paths
date_learned: 2025-08-03T20:54:00
---
---
# Ghostface di Panti Angker

Toni masuk ke sebuah **panti asuhan tua** yang konon sudah terbengkalai selama puluhan tahun. Ia ingin membuktikan bahwa tempat itu aman—**ternyata tidak.**

Begitu ia masuk, pintu **terkunci otomatis**, dan dari balik lorong terdengar suara:  **"Hello, Toni..."**  

![[03-Ghostface di Panti Angker-1.png]]

Itu suara **Ghostface**. Dia muncul entah dari mana dan mulai mengejar Toni.

Bangunan ini terdiri dari `N` ruangan, terhubung oleh `M` lorong rahasia. Lorong-lorong itu menyatu seperti labirin dan bisa membawa Toni ke ruangan mana saja... jika dia **tidak salah jalan**.

Toni berada di ruangan `X`, dan satu-satunya jalan keluar ada di ruangan `Y`. Kamu harus membantu Toni **menemukan satu-satunya jalur terpendek ke luar** sebelum Ghostface menangkapnya.

> Ghostface tahu semua jalan. Kalau Toni tidak mengambil **jalur tercepat**, dia akan tertangkap dan **tidak akan pernah keluar.**
#### Input Format:

- Baris pertama: dua bilangan bulat `N` dan `M` — jumlah ruangan dan lorong.
    
- `M` baris berikutnya: dua bilangan `u` dan `v` — lorong antar ruangan.
    
- Baris terakhir: dua bilangan `X` dan `Y` — posisi Toni sekarang dan pintu keluar.
    

> Semua lorong **tak berbobot, dua arah**, dan pasti ada jalan dari `X` ke `Y`.

#### Output Format:

- Satu baris berisi **jalur tercepat** yang dilalui Toni dari `X` ke `Y`.
    
- Jika ada beberapa jalur dengan panjang yang sama, pilih yang **secara angka ruangan paling kecil dulu (lexicographically)**.
    
- Jika tidak ada jalan (secara teori mustahil, tapi kalau kamu temukan...), tulis:  
    `Ghostface got Toni.`
    

#### Contoh 
Input:

```
10 14
1 2
1 3
1 4
3 5
5 6
6 4
2 7
7 8
8 3
7 9
9 10
10 3
4 2
8 10
6 9
```

![[graph (2).png]]


Output:

```
6 4 2 7 9
```


<br/>

---
# Jawaban

Berikut adalah jawabanku:

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

void DFS(VVI& graph, VI& rest, VB& visited, int now, int target, VI curr = {}) {
   curr.push_back(now);
   if (now == target) {
      if (rest.empty()) {
         rest = curr;
      } else if (curr.size() < rest.size()) {
         rest = curr;
      }

      return;
   }

   for (auto& v : graph[now]) {
      if (!visited[v]) {
         visited[v] = true;
         DFS(graph, rest, visited, v, target, curr);
         visited[v] = false;
      }
   }
}

void shortest(VVI& graph, VI& rest, int x, int y) {
   vector<bool> visited(graph.size(), false);
   visited[x] = true;
   DFS(graph, rest, visited, x, y);
}

auto main() -> int {
   fastio();
   int n, m;
   cin >> n >> m;

   VVI graph(n + 1);
   VI rest;

   for (int i = 1, u, v; i <= m; i++) {
      cin >> u >> v;

      graph[u].push_back(v);
      graph[v].push_back(u);
   }

   int x, y;
   cin >> x >> y;

   // panggil fungsi
   for (auto& x : graph) {
      ranges::sort(x);
   }

   shortest(graph, rest, x, y);
   for (const auto& x : rest) {
      cout << x << " ";
   }

   return 0;
}
```

<br/>

---
# Editorial

Berbeda dari soal sebelumnya, dimana kita perlu mencari semua jalur yang ada pada graf, pada soal ini, kita hanya perlu mencari satu jalur, yaitu satu jalur terpendek, 

Disini lebih baik kita tidak menggunakan array dua dimensi seperti soal sebelumnya, karena akan memakan banyak sekali memory, padahal yang kita butuhkan hanyalah satu jalur saja, yaitu jalur terpendek.

Pada fungsi `main`, kita hanya perlu mendeklarasikan array 2 dimensi `graph` untuk graph inputan, dan juga array `rest` sebagai tempat menampung jawaban dari fungsi yang nanti akan kita panggil.

Setelah itu, kita urutkan adjacency list kita, supaya lebih rapi, dan penelusuran graph bisa dipahami lebih mudah. Ini tidak memengaruhi alur logika, hanya saja mempermudah kita kedepanya jika ingin melakukan debug.

### Fungsi `shortest`

```cpp
void shortest(VVI& graph, VI& rest, int x, int y) {
   vector<bool> visited(graph.size(), false);
   visited[x] = true;
   DFS(graph, rest, visited, x, y, found);
}
```

Supaya pemanggilan fungsi didalam `main` lebih rapi —cukup dengan 4 argumen saja—, kita bisa membuat fungsi bantu, yaitu fungsi seperti `shortest()`.

Pembuatan array `visited` sebagai mekanisme mana yang sudah dikunjungi dan mana yang belum, dibuat disini, dengan cukup mengambil ukuran array `graph` untuk mengetahui banyaknya node, dan kita set semuanya sebagai false.

Tidak lupa juga, kita set `visited[x] = true`, tanda kita sudah kunjungi, karena kan ini node awal.

Setelah itu, panggil fungsi `DFS()` untuk melakukan penelusuran mencari jalur terpendek.

### Fungsi `DFS`

Yang perlu kita lakukan didalam fungsi DFS sebenarnya cukup sederhana. Jika soal-soal sebelumnya adalah tentang mencetak semua jalur, di soal ini kita hanya perlu mencari satu jalur pilihan, yaitu jalur terpendek diatara yang lainya.

Karena graph yang diberikan bukan graph berbobot (latihan dulu sebelum yang susah haha), maka mudah saja menemukan jawabanya.

Kita hanya perlu mencari mana diantara array `curr` yang isinya paling kecil. Ini bisa dilakukan dengan mekanisme seperti mencari nilai minimal, dimana kita membandingkan array ukuran `curr` dengan ukuran `rest`. Jika `curr` lebih kecil daripada `rest`, maka artinya `curr` telah menemukan jalur yang lebih pendek, sehingga kita perbarui isi dari `rest`.

Pada saat kita menemukan target untuk pertama kali, array `rest` masih kosong, sehingga mekanisme yang dijelaskan diatas tidak bisa bekerja. Solusinya adalah, kita menggunakan kondisional, dimana jika `rest` masih kosong, maka langsung saja isi nilai dari `rest` dengan `curr`. 

Mekanisme lengkapnya adalah seperti ini:

```cpp
void DFS(VVI& graph, VI& rest, VB& visited, int now, int target, VI curr = {}) {
   curr.push_back(now);
   if (now == target) {
      if (rest.empty()) {
         rest = curr;
      } else if (curr.size() < rest.size()) {
         rest = curr;
      }

      return;
   }

   for (auto& v : graph[now]) {
      if (!visited[v]) {
         visited[v] = true;
         DFS(graph, rest, visited, v, target, curr);
         visited[v] = false;
      }
   }
}
```


