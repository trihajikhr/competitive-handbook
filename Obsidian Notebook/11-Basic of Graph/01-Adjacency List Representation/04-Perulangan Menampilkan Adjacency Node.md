---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 11TH-BGRP-AL04
nama_algoritma: adjacency list
kategori_algoritma: graph algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber:
  - "buku: CP handbook by Antti Laaksonen"
  - chatgpt.com
date_learned: 2025-04-27T18:52:00
tags:
  - graph-algorithm
  - graph-basic
---
---
# 1 |  Loop Untuk Menampilakan Semua Tetangga Node

> Dalam buku Antti Laaksonen,dijelaskan bahwa dengan perulangan tertentu, kita bisa mengetahui banyaknya adjacency node dari node tertentu yang kita pilih dengan menggunakan perulangan, tepatnya perulangan `for-each`. Bagaimana contohnya?

Oke, aku ngerti! 🔥  
Kamu mau aku bantu buatkan **implementasi lengkap** dari potongan teori Antti Laaksonen tadi, kan?

Langsung aku buatkan ya — **simple graph** pakai **adjacency list**, lalu ada loop `for (auto u : adj[s])` untuk menelusuri tetangganya.

## 1.2 | Implementasi C++:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1); // adjacency list, 1-based index

    // Input edge
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v); 
        adj[v].push_back(u); // karena graph tidak berarah
    }

    // Contoh: Menampilkan semua node yang bisa dicapai dari node s
    int s;
    cout << "Masukkan node s: ";
    cin >> s;

    cout << "Node yang bisa dicapai dari node " << s << " adalah: ";
    for (auto u : adj[s]) {
        cout << u << " ";
    }
    cout << endl;

    return 0;
}
```

## 2.2 | Penjelasan kode:

- **`vector<vector<int>> adj(n+1)`**  
    Membuat adjacency list dengan 1-based index.
<br/>

- **Input edge**  
    Setiap kali baca `u v`, berarti `u` berteman dengan `v`, dan `v` berteman dengan `u`.  
<br/>

- **Loop `for (auto u : adj[s])`**  
    Menelusuri semua node yang bisa langsung dicapai dari node `s`.
    

### 2.2.1 | Contoh Input:

```
5 4
1 2
1 3
2 4
2 5
2
```

(Artinya: 5 node, 4 edge. Lalu kita ingin tahu node yang bisa dicapai dari node `2`.)

### 2.2.2 | Output:

```
Masukkan node s: 2
Node yang bisa dicapai dari node 2 adalah: 1 4 5
```
