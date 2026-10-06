---
obsidianUIMode: preview
note_type: book theory
judul_materi:
sumber:
date_learned:
tags:
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Algoritma Pencarian Jalur Lanjutan pada Weighted Grids: Dijkstra dan A*

## Pengantar

Pada implementasi dunia nyata dan permasalahan komputasi yang lebih kompleks, setiap petak atau pergerakan antar-simpul di dalam *grid* sering kali memiliki bobot atau biaya (*cost*) yang bervariasi—misalnya perbedaan medan, rintangan berat, atau kecepatan pergerakan. Dalam kondisi *weighted grid* seperti ini, algoritma BFS biasa tidak lagi menjamin penemuan lintasan dengan total biaya minimum. Untuk itu, diperlukan algoritma pencarian jalur lanjutan seperti **Dijkstra's Algorithm** dan **A* Search Algorithm**.

---

## Algoritma Dijkstra pada Grid

Algoritma Dijkstra digunakan untuk mencari lintasan dengan akumulasi bobot terkecil dari simpul asal ke seluruh simpul lain pada graf dengan bobot non-negatif. Pada *grid graph*, Dijkstra memprioritaskan ekspansi simpul yang memiliki akumulasi biaya (*distance*) terkecil saat itu.

### Mekanisme Kerja

* Menggunakan antrean berprioritas (*priority queue*) atau *min-heap* untuk menyimpan pasangan `(biaya, koordinat)`.
* Memelihara matriks 2D `dist` yang diinisialisasi dengan nilai tak hingga ($\infty$), kecuali titik awal yang diinisialisasi dengan `0`.
* Jika ditemukan jalur baru ke suatu petak dengan total biaya yang lebih kecil daripada nilai di matriks `dist`, nilai tersebut diperbarui dan dimasukkan ke dalam antrean.

### Contoh Implementasi C++

Berikut adalah fungsi C++ untuk mencari biaya minimum dari $(0, 0)$ ke titik tujuan $(R-1, C-1)$ pada grid bernilai bobot:

```cpp
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int INF = 1e9;
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int dijkstraGrid(const vector<vector<int>>& grid) {
    int R = grid.size();
    int C = grid[0].size();
    
    vector<vector<int>> dist(R, vector<int>(C, INF));
    // Priority queue menyimpan {biaya, baris, kolom}, terurut dari biaya terkecil
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    dist[0][0] = grid[0][0];
    pq.push({grid[0][0], 0, 0});

    while (!pq.empty()) {
        auto [d, r, c] = pq.top();
        pq.pop();

        if (d > dist[r][c]) continue;
        if (r == R - 1 && c == C - 1) return d;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                int new_cost = d + grid[nr][nc];
                if (new_cost < dist[nr][nc]) {
                    dist[nr][nc] = new_cost;
                    pq.push({new_cost, nr, nc});
                }
            }
        }
    }
    return dist[R - 1][C - 1];
}

```

---

## Algoritma A* Search (*A-Star*)

Algoritma A* merupakan pengembangan dari Dijkstra yang memanfaatkan **fungsi heuristik** untuk mengarahkan pencarian secara cerdas menuju titik tujuan, sehingga mengurangi jumlah simpul yang perlu dieksplorasi secara drastis.

### Fungsi Evaluasi $f(n)$

Setiap simpul $n$ dievaluasi berdasarkan nilai $f(n)$:


$$f(n) = g(n) + h(n)$$

* $g(n)$: Biaya sebenarnya yang telah ditempuh dari titik asal ke simpul $n$.
* $h(n)$: Perkiraan biaya (heuristik) dari simpul $n$ ke titik tujuan.

### Fungsi Heuristik pada Grid

Untuk pergerakan 4 arah (ortogonal) pada *grid*, fungsi heuristik yang paling tepat dan konsisten (*admissible*) adalah **Manhattan Distance**:


$$h(r, c) = \vert{}r - r_{\text{target}}\vert{} + \vert{}c - c_{\text{target}}\vert{}$$

Jika pergerakan 8 arah (termasuk diagonal) diizinkan, maka **Chebyshev Distance** atau **Octile Distance** lebih tepat digunakan.

### Contoh Implementasi C++ (A* Search)

```cpp
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

const int INF = 1e9;
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int manhattan(int r, int c, int tr, int tc) {
    return abs(r - tr) + abs(c - tc);
}

int aStarGrid(const vector<vector<int>>& grid, pair<int, int> start, pair<int, int> target) {
    int R = grid.size();
    int C = grid[0].size();
    auto [sr, sc] = start;
    auto [tr, tc] = target;

    vector<vector<int>> g_score(R, vector<int>(C, INF));
    // Priority queue menyimpan {f_score, baris, kolom}
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    g_score[sr][sc] = grid[sr][sc];
    int initial_f = g_score[sr][sc] + manhattan(sr, sc, tr, tc);
    pq.push({initial_f, sr, sc});

    while (!pq.empty()) {
        auto [f, r, c] = pq.top();
        pq.pop();

        if (r == tr && c == tc) return g_score[tr][tc];

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                int tentative_g = g_score[r][c] + grid[nr][nc];
                if (tentative_g < g_score[nr][nc]) {
                    g_score[nr][nc] = tentative_g;
                    int f_score = tentative_g + manhattan(nr, nc, tr, tc);
                    pq.push({f_score, nr, nc});
                }
            }
        }
    }
    return -1; // Jalur tidak ditemukan
}

```

---

## Perbandingan Algoritma Pencarian Jalur

| Parameter | Breadth-First Search (BFS) | Dijkstra's Algorithm | A* Search Algorithm |
| --- | --- | --- | --- |
| **Jenis Graf** | *Unweighted Grid* | *Weighted Grid* (non-negatif) | *Weighted Grid* (non-negatif) |
| **Heuristik** | Tidak ada | Tidak ada ($h(n) = 0$) | Ya ($h(n) \ge 0$) |
| **Pola Eksplorasi** | Melebar simetris (lingkaran) | Melebar sesuai bobot (kontur biaya) | Terarah menuju titik tujuan |
| **Kompleksitas Waktu** | $\mathcal{O}(V)$ | $\mathcal{O}(E \log V)$ | $\mathcal{O}(E \log V)$ (lebih cepat secara praktis) |
| **Penggunaan Utama** | Langkah minimal | Rute biaya minimum tanpa tujuan pasti | *Pathfinding* game & navigasi peta |

Bagaimana, apakah materi teknis ini sudah mencakup keseluruhan kebutuhan rancangan materi *grid graphs* yang kamu susun?