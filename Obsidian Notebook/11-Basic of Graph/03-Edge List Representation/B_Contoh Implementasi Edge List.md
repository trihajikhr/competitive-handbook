---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 11TH-BGRP-EL02
nama_algoritma: Edge list graph representation
kategori_algoritma: Graph Algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen & chatgpt.com"
date_learned: 2025-04-29T16:24:00
tags:
  - graph-algorithm
  - graph-edge-list
---
#graph-algorithm #graph-edge-list 

---
# Contoh Implementasi Graph dengan Edge List

## 1️⃣ Directed Unweighted Graph

```cpp
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v}); // hanya satu arah
    }

    cout << "\nDaftar Arah:\n";
    for (auto [u, v] : edges) {
        cout << u << " -> " << v << "\n";
    }

    return 0;
}
```

## 2️⃣ Directed Weighted Graph 
### Versi C++ 17
Jika kita menggunakan C++ 17, kita bisa menggunakan *sturctured binding* untuk pengulangan, dimana implementasinya adalah sebagai berikut:

```cpp
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    cout << "\nDaftar Arah & Bobot:\n";
    for (auto [u, v, w] : edges) {
        cout << u << " -> " << v << " (biaya " << w << ")\n";
    }

    return 0;
}
```
### Versi C++ 14
Jika C++ yang digunakan masih versi C++ 14, kita bisa menggunakan fungsi `tie()`:
```cpp
#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

inline void fastio(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}

int main() {
    fastio();
    int n,m;
    cin >> n >> m;

    vector<tuple<int,int,int>> edges;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;

        edges.push_back({u,v,w});
    }

    cout << "\nDaftar Jalan: \n";
    for(auto &edge : edges){
        int u, v, w;
        tie(u, v, w) = edge;
        cout << u << " -> " << v << " (" << w << " menit)\n";
    }
    cout << "\n";
    return 0;
}
```
## 3️⃣ Undirected Unweighted Graph

```cpp
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        edges.push_back({v, u}); // tambahkan dua arah
    }

    cout << "\nDaftar Koneksi:\n";
    for (auto [u, v] : edges) {
        cout << u << " - " << v << "\n";
    }

    return 0;
}
```

## 4️⃣ Undirected Weighted Graph
### Versi C++ 17

```cpp
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        edges.push_back({v, u, w}); // dua arah
    }

    cout << "\nDaftar Koneksi & Bobot:\n";
    for (auto [u, v, w] : edges) {
        cout << u << " - " << v << " (jarak " << w << ")\n";
    }

    return 0;
}
```

### Versi C++ 14

```cpp
#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

inline void fastio(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}

int main() {
    int n,m;
    cin >> n >> m;

    vector<tuple<int,int,int>> edges;

    for(int i=0; i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;

        edges.push_back({u,v,w});
        edges.push_back({v,u,w});
    }

    cout << "\n";
    for(auto& edge:edges){
        int u,v,w;
        tie(u,v,w) = edge;
        cout << u << " - " << v << " (" << w << ")\n"; 
    }
    return 0;
}
```
---

Penjelasan cepat:

- `pair<int, int>` dipakai untuk unweighted.
    
- `tuple<int, int, int>` dipakai untuk weighted.
    
- Untuk **undirected**, masukkan kedua arah: `(u,v)` dan `(v,u)`.
    
