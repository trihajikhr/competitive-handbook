---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 13TH-SPFA-0003
nama_algoritma: Bellman Ford Algorithm - SPFA
kategori_algoritma: Graph - Shortest Path
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen & programmiz.com & geeksforgeeks.com & chatgpt.com"
date_learned: 2025-05-04T21:57:00
tags:
  - graph
  - shortest-paths
  - SPFA
  - bellman-ford
---
#graph #shortest-paths #SPFA #bellman-ford 

---
# Variasi 1 | Dengan Struct
SPFA dengan menggunakan bantuan struct:
```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

struct Edge {
    int to, weight;
};

void SPFA(int start, vector<vector<Edge>>& graph, vector<int>& dist) {
    int n = graph.size();
    vector<bool> inQueue(n, false);
    queue<int> q;

    dist[start] = 0;
    q.push(start);
    inQueue[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inQueue[u] = false;

        for (Edge& e : graph[u]) {
            if (dist[u] != INF && dist[u] + e.weight < dist[e.to]) {
                dist[e.to] = dist[u] + e.weight;
                if (!inQueue[e.to]) {
                    q.push(e.to);
                    inQueue[e.to] = true;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Masukkan jumlah node dan edge: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);

    cout << "Masukkan edge dalam format: dari ke bobot\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int start;
    cout << "Masukkan node awal: ";
    cin >> start;

    vector<int> dist(n, INF);
    SPFA(start, graph, dist);

    cout << "\nJarak minimum dari node " << start << " ke tiap node:\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF)
            cout << "Node " << i << " tidak bisa dijangkau\n";
        else
            cout << "Node " << i << ": " << dist[i] << endl;
    }

    return 0;
}

```

## Editorial
Berikut adalah **editorial lengkap baris per baris** untuk program C++ implementasi algoritma **Shortest Path Faster Algorithm (SPFA)**:

---

### Bagian Header dan Namespace

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
```

- `#include <iostream>`: Untuk input/output (cout, cin).
    
- `#include <vector>`: Untuk menggunakan struktur data `vector`, yaitu array dinamis.
    
- `#include <queue>`: Untuk menggunakan struktur data antrian (`queue`), yang digunakan dalam SPFA.
    
- `#include <climits>`: Untuk mendapatkan nilai `INT_MAX`, yaitu representasi dari tak hingga (∞) dalam C++.
    

```cpp
using namespace std;
```

- Menghindari penulisan `std::` berulang-ulang.
    

```cpp
const int INF = INT_MAX;
```

- Mendefinisikan konstanta `INF` sebagai nilai tak hingga (digunakan untuk inisialisasi jarak awal).
    

---

### Definisi Struktur Edge

```cpp
struct Edge {
    int to, weight;
};
```

- Mendefinisikan struktur `Edge` untuk merepresentasikan sebuah sisi (edge).
    
    - `to`: simpul tujuan.
        
    - `weight`: bobot dari sisi tersebut.
        

---

### Fungsi SPFA (Shortest Path Faster Algorithm)

```cpp
void SPFA(int start, vector<vector<Edge>>& graph, vector<int>& dist)
```

- `start`: node sumber.
    
- `graph`: representasi graf sebagai list of adjacency list.
    
- `dist`: array jarak yang akan diupdate sebagai output dari algoritma.
    

```cpp
int n = graph.size();
```

- Menyimpan jumlah simpul dalam graf.
    

```cpp
vector<bool> inQueue(n, false);
queue<int> q;
```

- `inQueue`: menyimpan status apakah simpul saat ini sedang berada dalam antrian.
    
- `q`: antrian untuk menyimpan simpul yang akan direlaksasi.
    

```cpp
dist[start] = 0;
q.push(start);
inQueue[start] = true;
```

- Inisialisasi jarak ke simpul awal adalah 0.
    
- Masukkan simpul awal ke dalam antrian dan tandai sebagai sedang dalam antrian.
    

```cpp
while (!q.empty()) {
```

- Loop berjalan selama masih ada simpul dalam antrian.
    

```cpp
    int u = q.front();
    q.pop();
    inQueue[u] = false;
```

- Ambil simpul `u` dari depan antrian, lalu tandai bahwa `u` sudah tidak ada dalam antrian.
    

```cpp
    for (Edge& e : graph[u]) {
```

- Iterasi semua edge dari simpul `u`.
    

```cpp
        if (dist[u] != INF && dist[u] + e.weight < dist[e.to]) {
```

- Jika jarak ke `u` bukan ∞, dan relaksasi ke `e.to` menghasilkan nilai lebih kecil, maka perbarui.
    

```cpp
            dist[e.to] = dist[u] + e.weight;
```

- Update jarak dari simpul awal ke `e.to` melalui `u`.
    

```cpp
            if (!inQueue[e.to]) {
                q.push(e.to);
                inQueue[e.to] = true;
            }
```

- Jika `e.to` belum berada dalam antrian, masukkan ke antrian agar bisa direlaksasi nanti.
    

---

### Fungsi `main()`

```cpp
int n, m;
cout << "Masukkan jumlah node dan edge: ";
cin >> n >> m;
```

- Menerima input jumlah simpul dan sisi dari pengguna.
    

```cpp
vector<vector<Edge>> graph(n);
```

- Inisialisasi graf sebagai vector of adjacency list (`n` buah simpul).
    

```cpp
cout << "Masukkan edge dalam format: dari ke bobot\n";
for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
}
```

- Input edge satu per satu dan tambahkan ke adjacency list `graph`.
    
- Format edge: dari simpul `u` ke `v` dengan bobot `w`.
    

```cpp
int start;
cout << "Masukkan node awal: ";
cin >> start;
```

- Menerima input simpul awal dari pengguna.
    

```cpp
vector<int> dist(n, INF);
SPFA(start, graph, dist);
```

- Inisialisasi array jarak dengan `INF`, lalu jalankan SPFA.
    

---

### Menampilkan Hasil Akhir

```cpp
cout << "\nJarak minimum dari node " << start << " ke tiap node:\n";
for (int i = 0; i < n; ++i) {
    if (dist[i] == INF)
        cout << "Node " << i << " tidak bisa dijangkau\n";
    else
        cout << "Node " << i << ": " << dist[i] << endl;
}
```

- Menampilkan hasil akhir.
    
- Jika jarak tetap `INF`, berarti simpul tidak terjangkau dari simpul awal.
    

---

### Kesimpulan

- Algoritma SPFA merupakan optimisasi dari Bellman-Ford.
    
- Cocok untuk graf berarah dan berbobot, termasuk bobot negatif.
    
- Menggunakan antrian untuk mempercepat proses relaksasi.
    
- Kompleksitas waktu:
    
    - Rata-rata: **O(E)**
        
    - Kasus terburuk: **O(V × E)**
        
- Kompleksitas ruang: **O(V)** untuk array `dist` dan `inQueue`.
    

# Variasi 2 | Menggunakan Pair<>
SPFA Tanpa struct, melainkan menggunakan `pair`:
```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

void SPFA(int start, vector<vector<pair<int, int>>>& graph, vector<int>& dist) {
    int n = graph.size();
    vector<bool> inQueue(n, false);
    queue<int> q;

    dist[start] = 0;
    q.push(start);
    inQueue[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inQueue[u] = false;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (!inQueue[v]) {
                    q.push(v);
                    inQueue[v] = true;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Masukkan jumlah node dan edge: ";
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);

    cout << "Masukkan edge dalam format: dari ke bobot\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int start;
    cout << "Masukkan node awal: ";
    cin >> start;

    vector<int> dist(n, INF);
    SPFA(start, graph, dist);

    cout << "\nJarak minimum dari node " << start << " ke tiap node:\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF)
            cout << "Node " << i << " tidak bisa dijangkau\n";
        else
            cout << "Node " << i << ": " << dist[i] << endl;
    }

    return 0;
}

```

## Editorial
Berikut **editorial lengkap** untuk potongan kode SPFA dengan representasi graf menggunakan `vector<vector<pair<int, int>>>`, bukan `struct Edge`.

---

### 📌 Bagian Fungsi SPFA (tanpa `struct Edge`)

```cpp
int n = graph.size();
```

- Menyimpan jumlah simpul pada graf ke dalam variabel `n`.
    
- Ini didapat dari ukuran outer vector `graph`.
    

```cpp
vector<bool> inQueue(n, false);
queue<int> q;
```

- `inQueue`: array boolean untuk menandai apakah suatu simpul sedang berada dalam antrian.
    
- `queue<int> q`: antrian utama SPFA tempat menyimpan simpul yang perlu direlaksasi.
    

```cpp
dist[start] = 0;
q.push(start);
inQueue[start] = true;
```

- Inisialisasi jarak simpul awal ke dirinya sendiri = 0.
    
- Masukkan simpul awal ke antrian dan tandai bahwa dia sudah berada di dalam antrian.
    

---

### 🔁 Proses Relaksasi Menggunakan SPFA

```cpp
while (!q.empty()) {
```

- Selama masih ada simpul dalam antrian yang menunggu untuk direlaksasi.
    

```cpp
    int u = q.front();
    q.pop();
    inQueue[u] = false;
```

- Ambil simpul `u` dari depan antrian dan tandai bahwa ia tidak lagi berada dalam antrian.
    

```cpp
    for (auto& edge : graph[u]) {
        int v = edge.first;
        int w = edge.second;
```

- Iterasi seluruh tetangga dari simpul `u`.
    
- `edge` adalah pasangan `(v, w)`:
    
    - `v`: simpul tujuan dari edge.
        
    - `w`: bobot dari edge `u -> v`.
        

```cpp
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
```

- Cek apakah jarak baru ke `v` lebih kecil dari jarak lama:
    
    - Jika iya, lakukan **relaksasi** (update jarak `dist[v]`).
        

```cpp
            if (!inQueue[v]) {
                q.push(v);
                inQueue[v] = true;
            }
```

- Jika `v` belum berada dalam antrian, masukkan ke antrian untuk direlaksasi nanti.
    

---

### 🧾 Fungsi `main()`

```cpp
int n, m;
cout << "Masukkan jumlah node dan edge: ";
cin >> n >> m;
```

- Input jumlah simpul (`n`) dan jumlah edge (`m`).
    

```cpp
vector<vector<pair<int, int>>> graph(n);
```

- Membuat list adjacency di mana tiap simpul menyimpan pasangan `(tujuan, bobot)`.
    

```cpp
cout << "Masukkan edge dalam format: dari ke bobot\n";
for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
}
```

- Input daftar edge satu per satu.
    
- `graph[u].push_back({v, w})`: tambahkan edge dari `u` ke `v` dengan bobot `w`.
    

```cpp
int start;
cout << "Masukkan node awal: ";
cin >> start;
```

- Input simpul awal.
    

```cpp
vector<int> dist(n, INF);
SPFA(start, graph, dist);
```

- Inisialisasi array `dist` dengan nilai tak hingga (`INF`).
    
- Panggil algoritma SPFA untuk menghitung jarak terpendek dari simpul awal.
    

---

### 🖨️ Output Akhir

```cpp
cout << "\nJarak minimum dari node " << start << " ke tiap node:\n";
for (int i = 0; i < n; ++i) {
    if (dist[i] == INF)
        cout << "Node " << i << " tidak bisa dijangkau\n";
    else
        cout << "Node " << i << ": " << dist[i] << endl;
}
```

- Tampilkan hasil akhir dari jarak minimum dari simpul awal ke seluruh simpul lain.
    
- Jika jaraknya tetap `INF`, berarti simpul tersebut **tidak dapat dijangkau**.
    

---

### 📈 Kompleksitas

- **Waktu rata-rata**: O(E)
    
- **Waktu terburuk**: O(V × E)
    
- **Ruang**: O(V)

# Variasi 3 | Vector dist didalam fungsi
Disini kita membuat fungsi yang menangani semua SPFA, dengan vector `dist` yang juga dibuat didalam fungsi. Oleh karena itu, fungsi harus mengembalikan nilai:

```cpp
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

const int INF = INT_MAX;

inline void fastio(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}

vector<int> SPFA (vector<vector<pair<int,int>>> &graph, int n, int src){
    vector<int> dist(n, INF);
    vector<bool> inQueue(n, false);
    queue<int> q;

    dist[src] = 0;
    q.push(src);
    inQueue[src] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inQueue[u] = false;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;

                if (!inQueue[v]) {
                    q.push(v);
                    inQueue[v] = true;
                }
            }
        }
    }
    return dist;
}

int main() {
    int n,m;
    cin >> n >> m;
    
    vector<vector<pair<int,int>>> graph (n);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;

        graph[u].push_back({v,w});
    }

    int src; cin >> src;

    vector<int> rest = SPFA (graph, n, src);

    cout << "\n";
    for(auto&x:rest){
        if(x==INF) cout << "INF ";
        else cout << x << " ";
    }
    cout << "\n";

    return 0;
}
```
