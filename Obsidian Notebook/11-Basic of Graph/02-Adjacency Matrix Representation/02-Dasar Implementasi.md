---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 11TH-BGRP-MR02
nama_algoritma: adjacency matrix representation
kategori_algoritma: graph algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber:
  - "buku: CP handbook by Antti Laaksonen"
  - chatgpt.com
date_learned: 2025-04-28T21:15:00
tags:
  - graph-algorithm
  - graph-basic
---
---
Berikut, diberikan dasar-dasar representasi dari graph:

# 1 | Graph Tidak Berarah (Undirected) — Tanpa Bobot

```cpp
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1, vector<int>(n+1, 0)); // matrix nxn isi 0

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // karena tidak berarah
    }

    // Output adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
```

---

# 2 | Graph Terarah (Directed) — Tanpa Bobot

```cpp
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1, vector<int>(n+1, 0)); // matrix nxn isi 0

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1; // hanya satu arah
    }

    // Output adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
```

---

# 3 | Graph Tidak Berarah (Undirected) — Berbobot (Weighted)

```cpp
#include<iostream>
#include<vector>
using namespace std;

const int INF = 1e9; // besar untuk menandai tidak ada edge

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1, vector<int>(n+1, INF)); // matrix nxn isi INF

    for (int i = 1; i <= n; i++) adj[i][i] = 0; // jarak ke diri sendiri 0

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w; // karena tidak berarah
    }

    // Output adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (adj[i][j] == INF) cout << "INF ";
            else cout << adj[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
```

---

# 4 | Graph Terarah (Directed) — Berbobot (Weighted)

```cpp
#include<iostream>
#include<vector>
using namespace std;

const int INF = 1e9; // besar untuk menandai tidak ada edge

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1, vector<int>(n+1, INF)); // matrix nxn isi INF

    for (int i = 1; i <= n; i++) adj[i][i] = 0; // jarak ke diri sendiri 0

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w; // hanya satu arah
    }

    // Output adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (adj[i][j] == INF) cout << "INF ";
            else cout << adj[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
```

---

# 5 | Ringkasan:

|Tipe Graph|Arah|Bobot|Catatan|
|:--|:-:|:-:|:--|
|Tidak Berarah|❌|❌|`adj[u][v] = adj[v][u] = 1`|
|Terarah|✅|❌|`adj[u][v] = 1` saja|
|Tidak Berarah Weighted|❌|✅|`adj[u][v] = adj[v][u] = w`|
|Terarah Weighted|✅|✅|`adj[u][v] = w` saja|
