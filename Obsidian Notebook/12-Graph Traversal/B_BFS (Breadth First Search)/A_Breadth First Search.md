---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 12TH-GTBF-S001
nama_algoritma: Breadth First Search
kategori_algoritma: Graph Algorithm - Traversal
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen & geeksforgeeks.com"
date_learned: 2025-05-01T17:50:00
tags:
  - graph
  - graph-BFS
  - graph-traversal
---
#graph #graph-BFS #graph-traversal 

---
# Breadth First Search
**Breadth-first search** (BFS) mengunjungi node berdasarkan urutan jaraknya yang meningkat dari node awal. Dengan demikian, BFS dapat digunakan untuk menghitung jarak dari node awal ke semua node lainnya. Namun, implementasi BFS lebih kompleks dibandingkan dengan _depth-first search_ (DFS).

BFS menelusuri node secara bertahap dari satu tingkat ke tingkat berikutnya. Pertama, BFS mengeksplorasi node yang berjarak 1 dari node awal, lalu node yang berjarak 2, dan seterusnya. Proses ini berlanjut hingga semua node telah dikunjungi.

### Contoh

Mari kita lihat bagaimana BFS menelusuri graf berikut:

![[A_Breadth First Search-1.png|500]]

Misalkan pencarian dimulai dari node 1. Pertama, kita memproses semua node yang dapat dicapai dari node 1 menggunakan satu edge:

![[A_Breadth First Search-2.png|500]]

Setelah itu, kita melanjutkan ke node 3 dan 5:

![[A_Breadth First Search-3.png|500]]

Akhirnya, kita mengunjungi node 6:

![[A_Breadth First Search-4.png|500]]

Sekarang kita telah menghitung jarak dari node awal ke semua node dalam graf. Jaraknya adalah sebagai berikut:

| node | distance |
| ---- | -------- |
| 1    | 0        |
| 2    | 1        |
| 3    | 2        |
| 4    | 1        |
| 5    | 2        |
| 6    | 3        |

Seperti dalam _depth-first search_, kompleksitas waktu _breadth-first search_ adalah $O(n+m)$ , di mana $n$ adalah jumlah node dan $m$ adalah jumlah edge.

# Implementasi
_Breadth-first search_ lebih sulit diimplementasikan dibandingkan _depth-first search_, karena algoritma ini mengunjungi node di berbagai bagian graf. Implementasi khasnya menggunakan _queue_ yang berisi node. Pada setiap langkah, node berikutnya dalam _queue_ akan diproses.

Kode berikut mengasumsikan bahwa graf disimpan sebagai _adjacency list_ dan mempertahankan struktur data berikut:

```cpp
queue<int> q; 
bool visited[N]; 
int distance[N]; 
```

_Queue_ $q$ berisi node yang akan diproses dalam urutan jarak yang meningkat. Node baru selalu ditambahkan ke akhir _queue_, dan node di awal _queue_ adalah node berikutnya yang akan diproses. Array `visited` menunjukkan node mana yang telah dikunjungi oleh pencarian, dan array `distance` akan berisi jarak dari node awal ke semua node dalam graf.

Pencarian dapat diimplementasikan sebagai berikut, dimulai dari node $x$:

```cpp
visited[x] = true;  
distance[x] = 0;  
q.push(x);  
while (!q.empty()) {  
    int s = q.front(); q.pop();  
    // proses node s  
    for (auto u : adj[s]) {  
        if (visited[u]) continue;  
        visited[u] = true;  
        distance[u] = distance[s] + 1;  
        q.push(u);  
    }  
}
```