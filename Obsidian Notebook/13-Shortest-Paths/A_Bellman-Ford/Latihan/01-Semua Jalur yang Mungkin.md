---
obsidianUIMode: preview
note_type: latihan
latihan: Jarak Semua Jalur
sumber:
  - myself
tags:
  - graph-algorithm
  - shortest-path
date_learned: 2025-08-03T16:50:00
---
---
# Katakan Peta! Katakan Peta!

Pemadam kebakaran di Desa Berantah, sangatlah cekatan. Setiap ada panggilan kebakaran, mereka selalu tahu semua jalur yang bisa dilewati. Hal itu disebabkan karena mereka memiliki peta spesial yang menyimpan daftar urutan tempat yang bisa diambil jika ingin bepergian dari setiap tempat ke tempat lainya.

Sayangnya, peta tersebut tidak mau bekerja di hari yang genting, karena mereka memecat Dora, sang pawang peta. Padahal, mereka harus segera bepergian dari kota $x$ ke kota $y$ untuk melaksanakan tugas.

Jika Semua kota terhubung dan dapat dilalui, bantu pemadam kebakaran ini, menemukan semua jalur yang mungkin untuk diambil dari kota $x$ ke kota $y$, jika terdapat $n$ kota dan $m$ jalur yang ada.



#### Input:

Baris pertama berisi $n$ dan $m$, yaitu banyak kota dan banyak jalur

Baris selanjutnya terdiri dari $m$ baris, yang terdiri dari $a$, dan $b$, merepresentasikan bahwa node $a$ terhubung dengan node $b$, dan sebaliknya.

Baris terakhir adalah $x$ dan $y$, lokasi node awal, dan lokasi node tujuan yang dicari.

Untuk semua berlaku $1 \leq n,m,a,b,x,y \leq 10^{9}$.

#### Output:

Semua jalur yang ada, dari node $x$ ke node $y$. 

#### Contoh:

Input:

```
7 8
1 2
1 3
1 4
2 3
3 4
1 5
5 6
6 7
3 7
```

![[graph (1).png]]

Output:

```
3 1 5 6 7 
3 2 1 5 6 7 
3 4 1 5 6 7 
```

<br/>

---
# Jawaban

Berikut adalah jawabanku:

```cpp
#include <iostream>
#include <vector>
using namespace std;

#define VI vector<int>
#define VVI vector<vector<int>>

void getAllPath(VVI& graph, VVI& rest, int x, int target, vector<bool>& visited, VI curr = {}) {
   curr.push_back(x);

   if (x == target) {
      rest.push_back(curr);
      return;
   }

   for (auto v : graph[x]) {
      if (!visited[v]) {
         visited[v] = true;
         getAllPath(graph, rest, v, target, visited, curr);
         visited[v] = false;
      }
   }
}

auto main() -> int {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int n, m;
   cin >> n >> m;

   // array 1 based index
   VVI graph(n + 1), rest;
   vector<bool> visited(n + 1, false);

   for (int i = 1, u, v; i <= m; i++) {
      cin >> u >> v;

      graph[u].push_back(v);
      graph[v].push_back(u);
   }

   int x, y;
   cin >> x >> y;

   visited[x] = true;

   getAllPath(graph, rest, x, y, visited);
   int idx = 1;
   if (rest.size()) {
      for (const auto& row : rest) {
         for (const auto& x : row) {
            cout << x << " ";
         }
         cout << "\n";
      }
   } else {
      cout << "Tidak ada jalur yang bisa diambil dari " << x << " ke " << y << "\n";
   }

   return 0;
}
```


<br/>

---
# Editorial

Baiklah, kita mulai dari atas saja.

Pada bagian header, aku menggunakan 2 header, dan deklarasi namaspace. Pencarian semua jalur cukup sederhana, sehingga tidak membutuhkan banyak header.

Karena kita membutuhkan array dinamis, kita gunakan vector. Tapi karena penggunaan vector 2 dimensi dan satu dimensi, harus menuliskan vector terlebih dahulu, maka itu membuat aku lelah, sehingga aku gunakan saja macro seperti ini:

```cpp
#define VI vector<int>
#define VVI vector<vector<int>>
```

Ini menyingkat penulisan yang panjang menjadi lebih pendek, bisa juga gunakan `using` jika merujuk ke C++ modern (ini lebih disarankan untuk meng alias kan tipe data):

```cpp
using VI = vector<int>;
using VVI = vector<vector<int>>;
```

Oke, kita mulai dari bagian `main` terlebih dahulu.

Pada bagian main, seperti biasa, kita gunakan `fastio`, untuk I/O cepat.

Lalu terima banyaknya $n$ node dan $m$ jalur dari user.

Untuk array penampung data graph, kita buat array vector dua dimensi, dengan ukuran yang sama dengan banyaknya node. Tetapi, karena index pada array selalu dimulai dari 0, supaya lebih mudah, kita buat array 1 based index. Sehingga ukuran dari array dua dimensi penampung graphnya, kita buat berukuran $n+1$.

Kita juga perlu membuat arary untuk menampung nilai true dan false, atau vector bool, sebagai mekanisme agar node yang sudah dikunjungi, tidak dikunjungi lagi. Karena secara logika, jalur yang kita cari bukan jalur yang berputar putar, melainkan jalur yang mengarah ke tujuan.


```cpp
VVI graph(n + 1), rest;
vector<bool> visited(n + 1, false);
```


Kita membuat 2 array 2 dimensi, berupa `graph` untuk menampung data graph, dan juga `rest` untuk menampung hasil dari pencarian semua jalur. Tidak lupa, kita set semua data vector `visited` sebagai false, karena belum ada yang dikunjungi.

Lalu, lakukan inputan dari user, sebanyak $m$ kali:

```cpp
for (int i = 1, u, v; i <= m; i++) {
  cin >> u >> v;

  graph[u].push_back(v);
  graph[v].push_back(u);
}
```

Karena graph yang dibuat adalah graph undirected, jadi kita perlu melakukan `push_back` bolak-balik antara dua node. Jika graph directed, ambil baris ke-4 saja.

```cpp
int x, y;
cin >> x >> y;

visited[x] = true;

getAllPath(graph, rest, x, y, visited);
```

Sekarang kita meminta node awal dan node tujuan dari user. Lalu kita tetapkan node $x$ sebagai sudah dikunjungi, dengan langsung kita jadikan `visited[x] = true`. Lalu lakukan pemanggilan fungsi `getAllPath()`.

---
### Fungsi getAllPath()

```cpp
void getAllPath(VVI& graph, VVI& rest, int x, int target, vector<bool>& visited, VI curr = {}) {
   curr.push_back(x);

   if (x == target) {
      rest.push_back(curr);
      return;
   }

   for (auto v : graph[x]) {
      if (!visited[v]) {
         visited[v] = true;
         getAllPath(graph, rest, v, target, visited, curr);
         visited[v] = false;
      }
   }
}
```

Fungsi ini bekerja secara rekursif, menelusuri node pada graph secara DFS, dan menyimpan jalur yang tepat menuju ke node target pada array `rest`.

Setiap DFS, atau setiap penelusuran ke satu node tetangga, akan melakukan `push_back`, atau memasukan node tersebut kedalam array `curr`. Array `curr` adalah **parameter dengan nilai default**. Artinya:

- Jika saat pemanggilan fungsi **tidak ada argumen untuk `curr`**, maka `curr` otomatis diisi dengan `vector<int>()` kosong.
    
- Nilai default ini hanya dipakai **saat pemanggilan pertama**.
    
- Saat fungsi memanggil dirinya sendiri (rekursi), argumen `curr` selalu **diisi manual** (hasil dari rekursi sebelumnya), jadi nilai defaultnya **tidak pernah dipakai ulang**.

Oleh karena itu, array `curr` akan menyimpan data kunjungan node yang berbeda-beda dari setiap pemanggilan rekursi, dan baru kita ambil datanya ketika `x == target`. Ketika target ditemukan, kita memasukan data `curr` ke array `rest` dengan `rest.push_back(curr)`. Tidak lupa juga, setelah target ditemukan, kita tidak melakukan penelusuran lagi. Jadi,  kita hentikan DFS dengan `return`.

```cpp
for (auto v : graph[x]) {
  if (!visited[v]) {
	 visited[v] = true;
	 getAllPath(graph, rest, v, target, visited, curr);
	 visited[v] = false;
  }
}
```

Pada kode diatas, kita melakukan penelusuran node hanya pada node yang belum dikunjungi. Mekanisme ini bisa dilakukan karena ada bantuan array boolean yang kita buat sebelumnya dan kita panggil disini.

Jika node tersebut sudah dikunjungi, maka cari node lain. JIka belum dikunjungi, maka kita kunjungi terlebih dahulu. 

Saat dikunjungi, kita tandai node tersebut sudah dikunjunig, dengan `visited[v] = true`. Lalu lakukan pemanggilan fungsi `getAllPath()` secara rekursif disini. Pada perulangan for-each-loop, nilai `v` adalah node yang sedang kita kunjungi, sehingga `v` kita jadikan argumen pada fungsi `getAllPath()`, pada posisi parameter `x`.

Mekanisme backtrack dilakukan dengan mengembalikan node yang sudah dikunjungi sebagai false, dengan `visite[v] = false`.
