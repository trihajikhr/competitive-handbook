---
obsidianUIMode: preview
note_type: book theory
judul_materi: Breadth-first search
sumber:
  - cp-algorithms.com
date_learned: 2026-03-15T23:30:00
tags:
  - graphs
  - graph-BFS
---
Link Sumber: [Breadth First Search - Algorithms for Competitive Programming](https://cp-algorithms.com/graph/breadth-first-search.html)

---

> [!IMPORTANT]
>  
# Breadth-first search

*Breadth first search* adalah salah satu algoritma pencarian dasar dan esensial pada graf.

Sebagai hasil dari cara kerja algoritma ini, jalur yang ditemukan oleh breadth first search ke node mana pun adalah jalur terpendek ke node tersebut, yaitu jalur yang mengandung jumlah edge terkecil dalam graf tidak berbobot.

Algoritma ini bekerja dalam waktu

$$O(n + m)$$

, di mana $n$ adalah jumlah vertex dan $m$ adalah jumlah edge.

## Description of the algorithm

Algoritma ini menerima masukan berupa graf tidak berbobot dan id dari source vertex $s$. Graf masukan dapat berupa graf berarah (*directed*) atau tidak berarah (*undirected*), hal tersebut tidak berpengaruh bagi algoritma ini.

Algoritma ini dapat dipahami sebagai api yang menyebar pada graf: pada langkah ke-nol hanya source $s$ yang terbakar. Pada setiap langkah, api yang membakar setiap vertex menyebar ke semua tetangganya. Dalam satu iterasi algoritma, "cincin api" diperluas lebarnya sebesar satu unit (itulah asal nama algoritma ini).

Lebih tepatnya, algoritma ini dapat dinyatakan sebagai berikut: Buat sebuah `queue` $q$ yang akan berisi vertex-vertex yang akan diproses dan sebuah array Boolean `used[]` yang menunjukkan untuk setiap vertex, apakah ia telah dinyalakan (atau dikunjungi) atau tidak.

Awalnya, masukkan source $s$ ke dalam `queue` dan atur `used[s] = true`, dan untuk semua vertex $v$ lainnya atur `used[v] = false`. Kemudian, lakukan perulangan hingga `queue` kosong dan dalam setiap iterasi, keluarkan sebuah vertex dari bagian depan `queue`. Iterasi melalui semua edge yang keluar dari vertex ini dan jika beberapa edge ini menuju ke vertex yang belum dinyalakan, bakar vertex tersebut dan masukkan ke dalam `queue`.

Sebagai hasilnya, ketika `queue` kosong, "cincin api" tersebut berisi semua vertex yang dapat dijangkau dari source $s$, dengan setiap vertex dicapai dengan cara terpendek yang dimungkinkan. Anda juga dapat menghitung panjang dari jalur terpendek (yang hanya memerlukan pemeliharaan array panjang jalur `d[]`) serta menyimpan informasi untuk memulihkan semua jalur terpendek ini (untuk ini, perlu memelihara sebuah array "parents" `p[]`, yang menyimpan untuk setiap vertex, dari vertex mana kita mencapainya).

## Applications of BFS

Kami menulis kode untuk algoritma yang dijelaskan dalam C++ dan Java.

```cpp
vector<vector<int>> adj;  // adjacency list representation
int n; // number of nodes
int s; // source vertex

queue<int> q;
vector<bool> used(n);
vector<int> d(n), p(n);

q.push(s);
used[s] = true;
p[s] = -1;
while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : adj[v]) {
        if (!used[u]) {
            used[u] = true;
            q.push(u);
            d[u] = d[v] + 1;
            p[u] = v;
        }
    }
}
```

Jika kita harus memulihkan dan menampilkan jalur terpendek dari source ke suatu vertex $u$, hal itu dapat dilakukan dengan cara berikut:

```cpp
if (!used[u]) {
    cout << "No path!";
} else {
    vector<int> path;
    for (int v = u; v != -1; v = p[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    cout << "Path: ";
    for (int v : path)
        cout << v << " ";
}
```

## Practice Problems

- Menemukan jalur terpendek dari source ke vertex lain dalam graf tidak berbobot.

<br/>

- Menemukan semua komponen terhubung (connected components) dalam graf tidak berarah dalam waktu
    
    $$O(n + m)$$
    
    : Untuk melakukan ini, kita cukup menjalankan BFS mulai dari setiap vertex, kecuali vertex yang sudah dikunjungi dari pemanggilan sebelumnya. Jadi, kita melakukan BFS normal dari setiap vertex, tetapi tidak mengatur ulang array `used[]` setiap kali kita mendapatkan komponen terhubung yang baru, dan total waktu berjalan akan tetap
    
    $$O(n + m)$$
    
    (melakukan beberapa BFS pada graf tanpa mengnolkan array `used[]` disebut sebagai rangkaian breadth first search).

<br/>

- Menemukan solusi untuk masalah atau permainan dengan jumlah langkah paling sedikit, jika setiap keadaan (*state*) permainan dapat direpresentasikan oleh vertex dari graf, dan transisi dari satu keadaan ke keadaan lainnya adalah edge dari graf.

<br/>

- Menemukan jalur terpendek dalam graf dengan bobot 0 atau 1: Ini hanya memerlukan sedikit modifikasi pada breadth first search normal: Alih-alih memelihara array `used[]`, kita sekarang akan memeriksa apakah jarak ke vertex lebih pendek dari jarak yang ditemukan saat ini, kemudian jika edge saat ini berbobot nol, kita menambahkannya ke bagian depan `queue` (front), jika tidak, kita menambahkannya ke bagian belakang `queue` (back). Modifikasi ini dijelaskan lebih rinci dalam artikel 0-1 BFS.

<br/>

- Menemukan siklus terpendek (*shortest cycle*) dalam graf berarah tidak berbobot: Mulai breadth first search dari setiap vertex. Segera setelah kita mencoba pergi dari vertex saat ini kembali ke source vertex, kita telah menemukan siklus terpendek yang mengandung source vertex tersebut. Pada titik ini kita dapat menghentikan BFS, dan memulai BFS baru dari vertex berikutnya. Dari semua siklus tersebut (paling banyak satu dari setiap BFS), pilih yang terpendek.

<br/>

- Temukan semua edge yang terletak pada jalur terpendek mana pun di antara pasangan vertex $(a, b)$ yang diberikan. Untuk melakukan ini, jalankan dua breadth first search: satu dari $a$ dan satu dari $b$. Misalkan `da[]` adalah array yang berisi jarak terpendek yang diperoleh dari BFS pertama (dari $a$) dan `db[]` adalah array yang berisi jarak terpendek yang diperoleh dari BFS kedua dari $b$. Sekarang untuk setiap edge $(u, v)$, sangat mudah untuk memeriksa apakah edge tersebut terletak pada jalur terpendek mana pun antara $a$ dan $b$: kriterianya adalah kondisi $d_a[u] + 1 + d_b[v] = d_a[b]$.

<br/>

- Temukan semua vertex pada jalur terpendek mana pun di antara pasangan vertex $(a, b)$ yang diberikan. Untuk mencapainya, jalankan dua breadth first search: satu dari $a$ dan satu dari $b$. Misalkan `da[]` adalah array yang berisi jarak terpendek yang diperoleh dari BFS pertama (dari $a$) dan `db[]` adalah array yang berisi jarak terpendek yang diperoleh dari BFS kedua (dari $b$). Sekarang untuk setiap vertex, sangat mudah untuk memeriksa apakah ia terletak pada jalur terpendek mana pun antara $a$ dan $b$: kriterianya adalah kondisi $d_a[v] + d_b[v] = d_a[b]$.

<br/>

- Temukan rute terpendek (*shortest walk*) dengan panjang genap dari source vertex $s$ ke target vertex $t$ dalam graf tidak berbobot: Untuk ini, kita harus membangun graf pembantu (*auxiliary graph*), yang vertex-nya adalah keadaan $(v, c)$, di mana $v$ adalah node saat ini, $c = 0$ atau $c = 1$ adalah paritas saat ini. Setiap edge $(u, v)$ dari graf asli dalam kolom baru ini akan berubah menjadi dua edge $((u, 0), (v, 1))$ dan $((u, 1), (v, 0))$. Setelah itu kita menjalankan BFS untuk menemukan rute terpendek dari vertex awal $(s, 0)$ ke vertex akhir $(t, 0)$.


Catatan: Poin ini menggunakan istilah "walk" dan bukan "path" karena suatu alasan, karena vertex berpotensi berulang dalam rute yang ditemukan agar panjangnya genap. Masalah menemukan jalur (path) terpendek dengan panjang genap adalah NP-Complete dalam graf berarah, dan dapat diselesaikan dalam waktu linier dalam graf tidak berarah, tetapi dengan pendekatan yang jauh lebih rumit.

## Practice Problems

- [SPOJ: AKBAR](http://spoj.com/problems/AKBAR)
- [SPOJ: NAKANJ](http://www.spoj.com/problems/NAKANJ/)
- [SPOJ: WATER](http://www.spoj.com/problems/WATER)
- [SPOJ: MICE AND MAZE](http://www.spoj.com/problems/MICEMAZE/)
- [Timus: Caravans](http://acm.timus.ru/problem.aspx?space=1&num=2034)
- [DevSkill - Holloween Party (archived)](http://web.archive.org/web/20200930162803/http://www.devskill.com/CodingProblems/ViewProblem/60)
- [DevSkill - Ohani And The Link Cut Tree (archived)](http://web.archive.org/web/20170216192002/http://devskill.com:80/CodingProblems/ViewProblem/150)
- [SPOJ - Spiky Mazes](http://www.spoj.com/problems/SPIKES/)
- [SPOJ - Four Chips (hard)](http://www.spoj.com/problems/ADV04F1/)
- [SPOJ - Inversion Sort](http://www.spoj.com/problems/INVESORT/)
- [Codeforces - Shortest Path](http://codeforces.com/contest/59/problem/E)
- [SPOJ - Yet Another Multiple Problem](http://www.spoj.com/problems/MULTII/)
- [UVA 11392 - Binary 3xType Multiple](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2387)
- [UVA 10968 - KuPellaKeS](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1909)
- [Codeforces - Police Stations](http://codeforces.com/contest/796/problem/D)
- [Codeforces - Okabe and City](http://codeforces.com/contest/821/problem/D)
- [SPOJ - Find the Treasure](http://www.spoj.com/problems/DIGOKEYS/)
- [Codeforces - Bear and Forgotten Tree 2](http://codeforces.com/contest/653/problem/E)
- [Codeforces - Cycle in Maze](http://codeforces.com/contest/769/problem/C)
- [UVA - 11312 - Flipping Frustration](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2287)
- [SPOJ - Ada and Cycle](http://www.spoj.com/problems/ADACYCLE/)
- [CSES - Labyrinth](https://cses.fi/problemset/task/1193)
- [CSES - Message Route](https://cses.fi/problemset/task/1667/)
- [CSES - Monsters](https://cses.fi/problemset/task/1194)