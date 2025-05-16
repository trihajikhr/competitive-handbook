---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 12TH-GTBF-S003
nama_algoritma: Breadth First Search
kategori_algoritma: Graph Algorithm - Traversal
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen & geeksforgeeks.com"
date_learned: 2025-05-01T18:57:00
tags:
  - graph
  - graph-BFS
  - graph-traversal
---
#graph #graph-BFS #graph-traversal 

---
# Implementasi BFS Directed
Tentu! Berikut adalah implementasi dan editorial lengkap untuk **BFS pada graf terarah (directed)**, yang dibagi menjadi dua kategori: **Connected** dan **Disconnected**. Kita akan melanjutkan dari materi yang telah kamu pelajari sebelumnya, khususnya mengenai **Breadth-First Search (BFS)** dan graf terarah.

---

## 1. BFS untuk Graph Directed - Connected

### Implementasi:

Pada graf terarah yang terhubung (connected), kita hanya perlu memulai BFS dari satu simpul sumber dan akan mengunjungi semua simpul yang dapat dijangkau dari simpul tersebut.

```cpp
#include<bits/stdc++.h>
using namespace std;

// BFS dari simpul sumber yang diberikan s
vector<int> bfsDirectedConnected(vector<vector<int>>& adj) {
    int V = adj.size();
    
    int s = 0; // simpul sumber
    vector<int> res;  // untuk menyimpan hasil traversal

    queue<int> q;  // membuat queue untuk BFS
    vector<bool> visited(V, false);  // menandai simpul yang sudah dikunjungi

    visited[s] = true;  // tandai simpul sumber sebagai dikunjungi
    q.push(s);  // masukkan simpul sumber ke dalam queue

    while (!q.empty()) {
        int curr = q.front();  // ambil simpul dari depan queue
        q.pop();  // keluarkan simpul dari queue
        res.push_back(curr);  // simpan simpul ke dalam hasil

        // kunjungi tetangga dari simpul yang baru saja dikeluarkan
        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);  // masukkan simpul tetangga ke dalam queue
            }
        }
    }

    return res;
}

int main() {
    vector<vector<int>> adj = {{1}, {2}, {3}, {4}, {5}};  // graf terarah yang terhubung
    vector<int> ans = bfsDirectedConnected(adj);
    for (auto i : ans) {
        cout << i << " ";  // mencetak hasil BFS
    }
    return 0;
}
```

### Editorial:

- **Adjacency List**: Representasi graf menggunakan adjacency list, di mana `adj[i]` berisi tetangga simpul `i`. Pada graf terarah, hanya sisi yang mengarah dari simpul `i` ke simpul lainnya yang tercatat di `adj[i]`.
    
- **Queue dan Visited Array**: Queue digunakan untuk menelusuri simpul, sedangkan array `visited` memastikan simpul hanya dikunjungi sekali.
    
- **BFS Traversal**: Dimulai dari simpul sumber (`s = 0`), BFS menelusuri semua simpul yang terhubung dari sumber secara level-by-level. Kita terus mengunjungi tetangga dari simpul yang sedang diproses dan menambahkannya ke dalam queue.
    
- **Connected Graph**: Pada graf terarah yang terhubung, jika kita memulai BFS dari simpul sumber, kita akan mengunjungi semua simpul yang dapat dijangkau dari simpul tersebut.
    

---

## 2. BFS untuk Graph Directed - Disconnected

### Implementasi:

Pada graf terarah yang terputus (disconnected), kita harus memulai BFS dari **setiap simpul yang belum dikunjungi**. Ini akan memastikan kita mengunjungi semua simpul, bahkan yang tidak terhubung langsung dengan simpul sumber.

```cpp
#include<bits/stdc++.h>
using namespace std;

// BFS dari simpul sumber yang diberikan s
void bfsDirectedDisconnected(vector<vector<int>>& adj, int s, vector<bool>& visited, vector<int>& res) {
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        // Kunjungi semua tetangga yang belum dikunjungi
        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

// Melakukan BFS untuk seluruh graf yang terputus
vector<int> bfsDirectedDisconnected(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<int> res;
    vector<bool> visited(V, false);  // menandai simpul yang sudah dikunjungi

    // Lakukan BFS untuk setiap simpul yang belum dikunjungi
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            bfsDirectedDisconnected(adj, i, visited, res);
        }
    }

    return res;
}

int main() {
    // Graf terarah yang terputus (disconnected)
    vector<vector<int>> adj = {{1}, {2}, {3}, {4}, {5}, {}};
    vector<int> ans = bfsDirectedDisconnected(adj);
    for (auto i : ans) {
        cout << i << " ";  // mencetak hasil BFS
    }
    return 0;
}
```

### Editorial:

- **Adjacency List**: Sama seperti pada graf terhubung, graf terputus juga diwakili oleh adjacency list. Namun, pada graf terputus, beberapa simpul mungkin tidak memiliki hubungan dengan simpul lainnya, yang membuat traversal lebih kompleks.
    
- **BFS untuk Setiap Simpul**: Pada graf terputus, kita harus memastikan bahwa semua simpul dikunjungi. Untuk itu, kita memulai BFS dari setiap simpul yang belum dikunjungi. Dengan cara ini, meskipun graf memiliki komponen yang terpisah, semua simpul tetap akan terakses.
    
- **Queue dan Visited Array**: Queue digunakan untuk menelusuri graf, dan array `visited` memastikan bahwa setiap simpul hanya dikunjungi sekali.
    
- **Disconnected Graph**: Pada graf terputus, beberapa simpul mungkin tidak terjangkau dari simpul lain. Oleh karena itu, kita memulai BFS dari setiap simpul yang belum dikunjungi untuk menelusuri semua komponen terpisah.
    

---

## Kesimpulan:

- **BFS untuk Graf Terarah (Connected)**: Implementasinya dimulai dari satu simpul sumber, dan traversal akan mengunjungi semua simpul yang dapat dijangkau dari sumber tersebut. Jika graf terhubung, maka BFS akan mengunjungi semua simpul graf.
    
- **BFS untuk Graf Terarah (Disconnected)**: Karena graf terputus, BFS harus dimulai dari **setiap simpul yang belum dikunjungi** untuk memastikan semua simpul dapat dijangkau. Hasilnya adalah semua simpul di graf, terlepas dari apakah mereka terhubung langsung dengan simpul sumber atau tidak.
    

Kedua implementasi ini menggunakan struktur **queue** untuk traversal level by level dan array **visited** untuk memastikan simpul hanya dikunjungi sekali.