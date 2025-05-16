---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 11TH-BGRP-AL01
nama_algoritma: Adjacency list Graph basic
kategori_algoritma: Graph Algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen"
date_learned: 2025-04-26T17:22:00
tags:
  - graph
  - graph-adjacency-list
---
#graph #graph-adjacency-list

---
# Adjacency List Representation
Dalam representasi _adjacency list_, setiap node  dalam graf diberikan sebuah **_adjacency list_** yang berisi node-node yang terhubung dengan _edge_ dari $x$. _Adjacency lists_ adalah cara yang paling populer untuk merepresentasikan graf, dan sebagian besar algoritma dapat diimplementasikan secara efisien menggunakan metode ini.

Cara yang nyaman untuk menyimpan _adjacency lists_ adalah dengan mendeklarasikan sebuah array dari _vectors_ sebagai berikut:

```cpp
vector<int> adj[N];
```

Konstanta  dipilih agar semua _adjacency lists_ dapat disimpan. Sebagai contoh, graf berikut:

![[A_Adjacency Lists-1.png]]

Dapat disimmpan sebagai berikut:

```cpp
adj[1].push_back(2);
adj[2].push_back(3);
adj[2].push_back(4);
adj[3].push_back(4);
adj[4].push_back(1);
```

Jika graf bersifat *directed*, maka kita bisa menuliskanya seperti diatas, atau dengan ilustrasi sebagai berikut:

```cpp
adj[u].push_back(v);
```

Jika graf bersifat _undirected_, penyimpanannya serupa, tetapi setiap _edge_ ditambahkan dalam kedua arah.

Ketika membaca edge `(u, v)`, kita harus simpan **dua kali**:

```cpp
adj[u].push_back(v);    // u terhubung ke v
adj[v].push_back(u);    // v terhubung ke u
```

Jadi **satu baris input** menghasilkan **dua baris penyimpanan**.

Sebagai contoh, jika dengan gambar diatas, maka kita bisa membuat _undirected graf_ dengan cara berikut:

```cpp
adj[1].push_back(2);
adj[2].push_back(1); // balikanya

adj[2].push_back(3);
adj[3].push_back(2); // balikanya

adj[2].push_back(4);
adj[4].push_back(2); // balikanya

adj[3].push_back(4);
adj[4].push_back(3); // balikanya

adj[4].push_back(1);
adj[1].push_back(4); // balikanya
```

Untuk _weighted graph_, struktur ini dapat diperluas sebagai berikut:

```cpp
vector<pair<int,int>> adj[N];
```

Dalam kasus ini, _adjacency list_ dari node  akan berisi pasangan  setiap kali terdapat _edge_ dari node  ke node  dengan _weight_ . Sebagai contoh, graf berikut:

![[A_Adjacency Lists-2.png]]

Dapat disimpan sebagai berikut:

```cpp
adj[1].push_back({2,5});
adj[2].push_back({3,7});
adj[2].push_back({4,6});
adj[3].push_back({4,5});
adj[4].push_back({1,2});
```

Keuntungan menggunakan _adjacency lists_ adalah kita dapat dengan efisien menemukan node-node yang dapat dicapai dari suatu node melalui sebuah _edge_.

Sebagai contoh, _loop_ berikut akan melewati semua node yang dapat dicapai dari node $s$:

```cpp
for (auto u : adj[s]) {
// process node u
}
```

Untuk memperdalam kemampuan dalam memahami dan menerapkan graph, belajar di catatan ini:

- [[B_Praktik Graph Adjacency List]]
- [[C_Latihan Beberapa Soal]]