---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 11TH-BGRP-EL01
nama_algoritma: edge list graph representation
kategori_algoritma: graph algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber:
  - "buku: CP handbook by Antti Laaksonen"
date_learned: 2025-04-29T16:17:00
tags:
  - graph-algorithm
  - graph-basic
---
---
# 1 | Edge List Representation

Sebuah **edge list** menyimpan semua _edges_ dalam sebuah graf dalam urutan tertentu. Ini adalah cara yang nyaman untuk merepresentasikan graf jika algoritma memproses semua _edges_ dalam graf dan tidak perlu mencari _edges_ yang berawal dari suatu node tertentu.

_Edge list_ dapat disimpan dalam sebuah _vector_:

```cpp
vector<pair<int, int>> edges;
```

Setiap pasangan  menunjukkan bahwa terdapat sebuah _edge_ dari node  ke node . Dengan demikian, graf berikut:

![[A_Edge List Representation-1.png]]

dapat direpresentasikan sebagai berikut:

```cpp
edges.push_back({1,2});
edges.push_back({2,3});
edges.push_back({2,4});
edges.push_back({3,4});
edges.push_back({4,1});
```

Jika graf memiliki _weight_, struktur ini dapat diperluas sebagai berikut:

```cpp
vector<tuple<int, int, int>> edges;
```

Setiap elemen dalam daftar ini berbentuk , yang berarti terdapat _edge_ dari node  ke node  dengan _weight_ . Sebagai contoh, graf berikut:

![[A_Edge List Representation-2.png]]

dapat direpresentasikan sebagai berikut:

```cpp
edges.push_back({1,2,5});
edges.push_back({2,3,7});
edges.push_back({2,4,6});
edges.push_back({3,4,5});
edges.push_back({4,1,2});
```

---
# 2 |  Sumber Lain (Internet)
##  2.1 | Pengertian

Edge List adalah representasi graf yang menyimpan semua edge (sisi) sebagai pasangan node. Setiap edge direpresentasikan sebagai:

- `(u, v)` untuk unweighted graph
    
- `(u, v, w)` untuk weighted graph
    

## 2.2 | Struktur Data

Gunakan `vector<pair<int, int>>` untuk graf tak berbobot dan `vector<tuple<int, int, int>>` untuk graf berbobot.

### 2.3 | Implementasi Unweighted Graph (Undirected)

```cpp
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m; // n = jumlah simpul, m = jumlah edge
    cin >> n >> m;

    vector<pair<int, int>> edges;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        edges.push_back({v, u});
    }

    cout << "\nDaftar Edge:\n";
    for(auto edge : edges) {
        cout << edge.first << " - " << edge.second << "\n";
    }

    return 0;
}
```

### 2.4 | Kelebihan

- Representasi paling sederhana.
    
- Mudah digunakan untuk algoritma seperti **Kruskal's Minimum Spanning Tree**.
    

### 2.5 | Kekurangan

- Tidak efisien untuk mencari semua tetangga dari node tertentu.
    
- Tidak cocok untuk operasi yang memerlukan akses cepat ke tetangga node.
    
