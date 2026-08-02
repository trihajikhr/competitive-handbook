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
# Traversal Dasar pada Grid Graphs: BFS dan DFS

## Pengantar

Penelusuran (*traversal*) adalah fondasi dasar dalam pemrosesan *grid graph*. Karena struktur *grid* dapat dipandang sebagai graf implisit, algoritma penelusuran standar seperti *Breadth-First Search* (BFS) dan *Depth-First Search* (DFS) dapat diterapkan secara langsung tanpa perlu membangun daftar ketetanggaan (*adjacency list*) secara eksplisit. Kedua algoritma ini memiliki peran mendasar yang berbeda dalam analisis ruang pencarian berbasis grid.

## Penelusuran Melebar (*Breadth-First Search* / BFS)

Algoritma BFS mengeksplorasi *grid* secara bertahap tingkat demi tingkat (*level by level*) dari simpul awal. Pada *unweighted grid* (graf tanpa bobot pada sisinya), BFS menjamin ditemukannya lintasan terpendek (*shortest path*) dalam hal jumlah langkah dari titik asal ke titik tujuan.

### Mekanisme Kerja

* Menggunakan struktur data antrean (*queue*) untuk menyimpan koordinat yang akan dikunjungi.
* Memelihara matriks jarak atau visited state untuk mencatat simpul yang sudah diproses agar menghindari iterasi tak berhingga.
* Mengeksplorasi seluruh tetangga ortogonal yang valid dari simpul yang sedang diproses sebelum melangkah lebih jauh.

### Contoh Implementasi C++

Berikut adalah fungsi C++ untuk menghitung jarak terpendek dari simpul asal $(r_s, c_s)$ ke seluruh simpul pada *grid* berukuran $R \times C$:

```cpp
#include <vector>
#include <queue>

using namespace std;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

vector<vector<int>> bfsShortestPath(int R, int C, int rs, int cs) {
    vector<vector<int>> dist(R, vector<int>(C, -1));
    queue<pair<int, int>> q;

    dist[rs][cs] = 0;
    q.push({rs, cs});

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    return dist;
}

```

## Penelusuran Mendalam (*Depth-First Search* / DFS)

Algoritma DFS mengeksplorasi *grid* dengan cara menelusuri satu cabang sedalam mungkin sebelum melakukan *backtracking*. DFS tidak menjamin lintasan terpendek, namun sangat efisien untuk menghitung komponen terhubung (*connected components*), mendeteksi wilayah tertutup (*flood fill*), atau memeriksa keberadaan suatu jalur.

### Mekanisme Kerja

* Menggunakan tumpukan (*stack*), baik secara ekplisit maupun implisit melalui rekursi fungsi.
* Memulai penelusuran dari suatu simpul dan secara agresif melangkah ke tetangga valid pertama yang belum dikunjungi.
* Kembali (*backtrack*) ketika menemui jalan buntu atau batas *grid*.

### Contoh Implementasi C++

Berikut adalah contoh penerapan DFS untuk menghitung ukuran komponen terhubung pada *grid* biner:

```cpp
#include <vector>

using namespace std;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int dfsFloodFill(int r, int c, int R, int C, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    visited[r][c] = true;
    int component_size = 1;

    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
            if (grid[nr][nc] == 1 && !visited[nr][nc]) {
                component_size += dfsFloodFill(nr, nc, R, C, grid, visited);
            }
        }
    }
    return component_size;
}

```

## Perbandingan Kompleksitas dan Kegunaan

| Parameter                  | Breadth-First Search (BFS)               | Depth-First Search (DFS)                                           |
| -------------------------- | ---------------------------------------- | ------------------------------------------------------------------ |
| **Struktur Data Utamanya** | Queue (`std::queue`)                     | Call Stack (Rekursi) / `std::stack`                                |
| **Kompleksitas Waktu**     | $\mathcal{O}(R \cdot C)$                 | $\mathcal{O}(R \cdot C)$                                           |
| **Kompleksitas Ruang**     | $\mathcal{O}(R \cdot C)$                 | $\mathcal{O}(R \cdot C)$                                           |
| **Jaminan Shortest Path**  | Ya (pada *unweighted grid*)              | Tidak                                                              |
| **Karakteristik Utama**    | Menyebar menyerupai gelombang lingkaran  | Menelusuri jalur hingga buntu sebelum balik                        |
| **Kasus Penggunaan Utama** | Jarak terpendek, *level-order traversal* | *Flood fill*, hitung pulau (*connected component*), *maze solving* |