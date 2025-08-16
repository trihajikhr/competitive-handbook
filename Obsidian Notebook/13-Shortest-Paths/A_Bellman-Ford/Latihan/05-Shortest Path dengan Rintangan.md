---
obsidianUIMode: preview
note_type: latihan
latihan: Shortest Path dengan Rintangan
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - shortest-path
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

Ahaa, ini adalah soal yang dirancang sebagai persiapan untuk memulai graph weighted 😅, karena sudah memiliki pasangan inputan ketiga.

Nah, jika disoal-soal sebelumnya adjacency list yang kita buat hanya berisi node mana yang berpasangan dengan node tertentu, kali ini, info pasangan node harus diberi pasangan tambahan, yaitu apakah jalur dari node $u$ ke node $v$ aman atau tidak. Aman atau tidaknya jalur yang menghubungkan antaar node $u$ dan node $v$ dinyatakan dalam 1 dan 0, dimana 0 artinya aman, dan 1 artinya tidak aman karena ada kamera yang terpasang di jalur itu.

Setiap node dalam adjacency list harus menyimpan setiap pasangan:

```
node -> {{node tujuan, aman/tidak aman}, {node tujuan, aman/tidak aman}}
```

Oleh karena itu, kita menggunakan struktur data tuple:

```cpp
vector<vector<tuple<int, int>>> graph(n + 1);
```

> Pelajari dulu saja tuple kalau belum tahu 😜, gampang lah

Dengan ini, kita bisa membungkus 2 informasi tersebut menjadi satu pada adjacency list. 

```cpp
for (int i = 1; i <= m; i++) {
  int u, v, k;
  cin >> u >> v >> k;

  graph[u].emplace_back(v, k);
  graph[v].emplace_back(u, k);
}
```

Setelah itu, kita menerika 3 inputan dari user, yaitu node sekarang, node tujuan, dan keterangan aman atau tidaknya jalur yang menghubungkanya.

Saat kita memasukan data tersebut ke dalam adjacecny list, kita bisa saja menggunakan `push_back()`, namun karena data didalam vector bukan tipe data biasa, namun tuple, lebih disarankan untuk menggunakan `emplace_back()`.

Lakukan selang-seling antara $u$ dan $v$ jika graph yang dibuat adalah graph undirected. Jika graphnya directed, lakukan untuk $u$ ke $v$ saja.

Setelah itu, minta node awal dan tujuan dari user, dan panggil fungsi `securePath()`.

### `securePath()`

```cpp
void securePath(vector<vector<tuple<int, int>>>& graph, vector<int>& rest, int now, int target) {
   vector<bool> visited(graph.size(), false);
   visited[now] = true;
   bool found = false;
   getSecurePath(graph, rest, visited, now, target, found);
}
```

Fungsi `securePath()` memiliki parameter adjacency list dari graph, vector hasil, node asal, dan node tujuan.

Fungsi ini dibuat sebagai fungsi bantu, supaya fungsi pemanggil utama di `main` tidak harus memberikan terlalu banyak argumen.

Didalam fungsi ini, kita membuat vector boolean untuk menandai mana node yang sudah dikunjungi dan mana yang belum, jangan lupa set semuanya sebagai `false`. Lalu tandai node tujuan sebagai `true`, dan bool `found` sebagai false, ini supaya fungsi `getSecurePath()` bekerja dengan baik.

Setelah itu, kita panggil saja fungsi `getSecurePath()`.

### `getSecurePath()`

```cpp
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
```

Pertama, kita harus membuat mekanisme mencari jalur terpendek, dengan cara memperbarui setiap vector `rest` dengan vector penjelajah `curr` apabila node mencapai `target` dan vector `curr` menyimpang rute yang lebih pendek daripada rute yang tersimpan di `rest`.

Ketika `target` ditemukan untuk pertama kali, mekanisme ini hanya mengambil langsung nilai dari `curr`. Ketika target ditemukan untuk kali kedua dan seterusnya, kita baru menjalankan pengambilan rute terpendek dengan mekanisme perbandingan. 

Oke, bagian ini seharusnya mudah, kita sudah membahas ini di soal-soal sebelumnya. Mekanisme yang baru, ada pada kode ini:

```cpp
for (const auto& V : graph[now]) {
  auto [to, cam] = V;
  if (cam == 0 && !visited[to]) {
	 visited[to] = true;
	 getSecurePath(graph, rest, visited, to, target, found, curr);
	 visited[to] = false;
  }
}
```

Perhatikan lagi, bahwa kita menyimpan struktur tuple didalam vector graph. Untuk bisa memecah tipe data yang tersimpan didalam tuple, sehingga kita bisa menggunakan masing-masing nilainya, kita bisa menggunakan beberapa cara.

Jika kamu sudah belajar tentang struktur data tuple, kamu seharusnya tahu bahwa ada dua cara yang mudah untuk memecah atau mendestruksi nilai didalam tuple, 

- Menggunakan `tie()`
- Menggunakan `auto []`

Cara paling mudah, ringkas, dan lebih modern adalah dengan menggunakan `auto[]`, sehingga kita menggunakan `auto[]`.

Didalam `auto[]`, kita menetapkan variabel `to` untuk mengambil node yang bertetanggaan dengan node sekarang, dan variabel `cam` untuk menyimpan nilai 1 dan 0, keterangan apakah jalur aman atau tidak.

Lakukan penelusuran jika node tersebut belum dikunjungi, dan juga `cam == 0` :

```cpp
if (cam == 0 && !visited[to]) {
	 visited[to] = true;
	 getSecurePath(graph, rest, visited, to, target, found, curr);
	 visited[to] = false;
}
```

Nahh, mekanisme ini memastikan bahwa Jake, hanya mengunjungi node yang belum dikunjungi, dan tidak ada kamera dijalur tersebut.

Setelah melakukan penelusuran secara DFS, jangan lupa tulis `visited[to] = false`, untuk mekanisme backtracking.










