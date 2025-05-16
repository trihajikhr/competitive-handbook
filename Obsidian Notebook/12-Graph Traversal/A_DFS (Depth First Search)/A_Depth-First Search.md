---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 12TH-GTDF-S001
nama_algoritma: Depth First Search
kategori_algoritma: Graph Algorithm - Traversal
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen & w3shools.com"
date_learned: 2025-04-30T18:46:00
tags:
  - graph
  - graph-traversal
  - graph-DFS
---
#graph #graph-traversal #graph-DFS

---
Bab ini membahas dua algoritma dasar pada graf: _depth-first search_ dan _breadth-first search_. Kedua algoritma ini diberikan sebuah _starting node_ dalam graf dan mengunjungi semua node yang dapat dicapai dari _starting node_. Perbedaan utama antara kedua algoritma ini adalah urutan dalam mengunjungi node-node tersebut.

# Depth-First Search
**Depth-first search** (DFS) adalah teknik _graph traversal_ yang sederhana. Algoritma ini dimulai dari sebuah _starting node_ dan menjelajahi semua node lain yang dapat dicapai dari _starting node_ menggunakan _edges_ dalam graf.

DFS selalu mengikuti satu jalur dalam graf selama masih menemukan node baru. Setelah itu, algoritma akan kembali ke node sebelumnya dan mulai menjelajahi bagian lain dari graf. DFS mencatat node yang telah dikunjungi sehingga setiap node hanya diproses satu kali.

## W3Schools
### Depth First Search Traversal

**Depth First Search** (DFS) disebut "menyelam dalam" karena algoritma ini mengunjungi sebuah **vertex**, lalu **adjacent vertex** (simpul yang bertetangga), kemudian **adjacent vertex** dari simpul itu, dan seterusnya. Dengan cara ini, jarak dari **starting vertex** akan terus bertambah di setiap iterasi rekursifnya.
### Cara kerjanya:

1. Mulai **DFS traversal** dari sebuah vertex.
    
2. Lakukan **DFS traversal secara rekursif** pada setiap **adjacent vertex** selama vertex tersebut **belum dikunjungi**.
    
3. Jalankan animasi di bawah ini untuk melihat bagaimana **DFS traversal** berjalan pada sebuah **Graph**, dimulai dari vertex **D** (ini sama dengan animasi sebelumnya).
    

---
![[20250430-1153-33.3085928.mp4]]

---

**Penjelasan:**  
Traversal DFS dimulai dari vertex **D**, dan menandai vertex D sebagai **visited**. Setelah itu, untuk setiap vertex baru yang dikunjungi, metode traversal akan dipanggil kembali secara **rekursif** untuk semua **adjacent vertex** yang **belum dikunjungi**. Jadi, ketika vertex **A** dikunjungi dalam animasi di atas, traversal akan berlanjut ke vertex **C** atau **E** (tergantung pada implementasi).

## Internet

### 📚 Materi Lengkap: Depth-First Search (DFS)

### 🔹 1. Pengertian DFS

**Depth-First Search** (DFS) adalah salah satu metode **graph traversal** yang menjelajahi graf dengan cara "menyelam" sedalam mungkin ke satu cabang sebelum kembali dan menjelajahi cabang lain.

DFS dapat digunakan pada:

- **Graph berarah (directed)** maupun **tak berarah (undirected)**
    
- Graph **berbobot** maupun **tak berbobot**
    
- Graph **terhubung** maupun **tidak terhubung**
    

---

### 🔹 2. Sifat dan Karakteristik DFS

- DFS menggunakan **rekursi** atau **stack (tumpukan)** untuk menjelajahi graf.
    
- DFS menjelajahi dari **vertex awal (starting vertex)** ke **vertex tetangga** yang belum dikunjungi, terus menerus hingga mencapai akhir jalur.
    
- Setelah tidak ada tetangga yang belum dikunjungi, traversal **kembali ke simpul sebelumnya** dan melanjutkan ke tetangga lainnya.
    
- Dikenal dengan istilah **backtracking**.
    

---

### 🔹 3. Terminologi penting

|Istilah|Arti|
|---|---|
|**Vertex**|Simpul (node) dalam graph|
|**Edge**|Sisi/penghubung antar vertex|
|**Visited**|Vertex yang sudah dikunjungi dalam proses traversal|
|**Adjacent**|Vertex yang langsung terhubung dengan vertex lainnya|
|**Backtracking**|Kembali ke vertex sebelumnya jika semua adjacent vertex sudah dikunjungi|

---

### 🔹 4. Kapan DFS digunakan?

DFS cocok digunakan untuk:

- **Mendeteksi siklus** dalam graph
    
- **Menemukan komponen terhubung** (connected components)
    
- **Topological sorting** (pada graph berarah)
    
- **Menelusuri semua kemungkinan** (misalnya dalam maze, puzzle, atau tree)
    
- **Pencarian jalur** (pathfinding), walau DFS **tidak menjamin jalur terpendek**
    

---

### 🔹 5. Strategi Traversal DFS

DFS memiliki dua cara umum:

- **Rekursif**: fungsi memanggil dirinya sendiri
    
- **Iteratif**: menggunakan **stack** secara eksplisit
    

Traversal dimulai dari vertex awal, dan:

1. Tandai vertex sebagai `visited`
    
2. Kunjungi setiap `adjacent vertex` yang belum `visited`
    
3. Ulangi langkah tersebut secara rekursif atau menggunakan stack
    

---

### 🔹 6. Traversal Order

Urutan traversal DFS **tidak unik** dan bisa berbeda tergantung:

- Vertex awal
    
- Urutan adjacency (misalnya: tetangga diurutkan berdasarkan abjad, ID terkecil dulu, dll)
    

Contoh hasil traversal bisa berbeda antara:

```
DFS dari A → A-B-C
DFS dari A → A-C-B
```

---

### 🔹 7. Kelebihan DFS

- Implementasi sederhana (terutama versi rekursif)
    
- Menggunakan memori yang lebih sedikit dibanding BFS
    
- Cocok untuk menjelajahi cabang hingga habis sebelum pindah
    

---

### 🔹 8. Kekurangan DFS

- Tidak menemukan jalur terpendek (jika tujuan traversal adalah mencari path)
    
- Bisa masuk ke **infinite loop** jika tidak ada pengecekan `visited` pada graph dengan siklus
    

---

### 🔹 9. Representasi Graf untuk DFS

DFS bisa digunakan pada representasi graf berikut:

- **Adjacency List** ✅ (paling umum dan efisien)
    
- **Adjacency Matrix** (bisa juga, tapi kurang efisien untuk graf besar)
    

---

### 🔹 10. Contoh Kasus Penggunaan DFS

- **Pemetaan jaringan**: Menemukan semua perangkat yang terhubung
    
- **Puzzle Solving**: Menyelesaikan maze dengan pencarian mendalam
    
- **Web Crawling**: Mengunjungi semua tautan dari halaman web
    
- **Compiler**: Melakukan topological sort untuk urutan kompilasi
    
## Antii Laaksonen
**Depth-first search** (DFS) adalah teknik _graph traversal_ yang sederhana. Algoritma ini dimulai dari sebuah _starting node_ dan menjelajahi semua node lain yang dapat dicapai dari _starting node_ menggunakan _edges_ dalam graf.

DFS selalu mengikuti satu jalur dalam graf selama masih menemukan node baru. Setelah itu, algoritma akan kembali ke node sebelumnya dan mulai menjelajahi bagian lain dari graf. DFS mencatat node yang telah dikunjungi sehingga setiap node hanya diproses satu kali.

# Contoh cara kerja DFS
Mari kita lihat bagaimana _depth-first search_ (DFS) memproses graf berikut:

![[Depth-First Search-1.png|500]]


Kita dapat memulai pencarian dari node mana pun dalam graf; sekarang kita akan memulai pencarian dari node 1.

Pencarian pertama-tama bergerak ke node 2:

![[Depth-First Search-2.png|500]]

Setelah itu, node 3 dan 5 akan dikunjungi:

![[Depth-First Search-3.png|500]]

Tetangga dari node 5 adalah node 2 dan 3, tetapi keduanya sudah dikunjungi, sehingga algoritma kembali ke node sebelumnya. Selain itu, semua tetangga dari node 3 dan 2 juga telah dikunjungi, jadi langkah berikutnya adalah bergerak dari node 1 ke node 4:

![[Depth-First Search-4.png|500]]

Setelah itu, pencarian berakhir karena semua node telah dikunjungi.

Kompleksitas waktu dari _depth-first search_ (DFS) adalah $O(n+m)$, di mana $n$  adalah jumlah node dan $m$  adalah jumlah _edges_, karena algoritma memproses setiap node dan _edge_ sekali.

# Implementasi | Dasar
_Depth-first search_ (DFS) dapat diimplementasikan dengan mudah menggunakan rekursi. Fungsi berikut, `dfs`, memulai pencarian dari suatu node tertentu. Fungsi ini mengasumsikan bahwa graf disimpan dalam bentuk _adjacency list_ menggunakan array:

```cpp
vector<int> adj[N];
```

Selain itu, terdapat array tambahan:

```cpp
bool visited[N];
```

yang digunakan untuk melacak node yang telah dikunjungi. Awalnya, semua nilai dalam array `visited` adalah `false`. Saat pencarian mencapai node $s$, nilai `visited[s]`  diubah menjadi `true`.

Berikut adalah implementasi DFS:

```cpp
void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
    // proses node s
    for (auto u : adj[s]) {
        dfs(u);
    }
}

```