---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 12TH-GTBF-S002
nama_algoritma: Breadth First Search
kategori_algoritma: Graph Algorithm - Traversal
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen & geeksforgeeks.com"
date_learned: 2025-05-01T18:20:00
tags:
  - graph
  - graph-BFS
  - graph-traversal
---
#graph #graph-BFS #graph-traversal 

---
# Implementasi BFS Undirected

Diberikan sebuah **graf tak berarah (undirected graph)** yang direpresentasikan dalam bentuk **daftar ketetanggaan (adjacency list)** `adj`, di mana setiap `adj[i]` merepresentasikan daftar simpul (vertices) yang terhubung dengan simpul `i`.  Lakukan penelusuran **Breadth First Search (BFS)** mulai dari simpul 0, kunjungi simpul dari kiri ke kanan sesuai dengan urutan dalam daftar ketetanggaan, dan kembalikan sebuah daftar yang berisi urutan penelusuran BFS dari graf tersebut.

---

### Contoh:

**Input:**  
`adj[][] = [[1,2], [0,2,3], [0,1,4], [1,4], [2,3]]`

![[B_Implementasi BFS Undirected-1.png|500]]

**Output:**  
`[0, 1, 2, 3, 4]`

**Penjelasan:**  
Mulai dari simpul 0, penelusuran BFS akan mengikuti langkah-langkah berikut:

- Kunjungi 0 → Output: [0]
    
- Kunjungi 1 (tetangga pertama dari 0) → Output: [0, 1]
    
- Kunjungi 2 (tetangga berikutnya dari 0) → Output: [0, 1, 2]
    
- Kunjungi 3 (tetangga berikutnya dari 1) → Output: [0, 1, 2, 3]
    
- Kunjungi 4 (tetangga dari 2) → Output akhir: [0, 1, 2, 3, 4]
    

---

**Input:**  
`adj[][] = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]`

![[B_Implementasi BFS Undirected-2.png|500]]

**Output:**  
`[0, 1, 2, 3, 4]`

**Penjelasan:**  
Mulai dari simpul 0, penelusuran BFS berjalan sebagai berikut:

- Kunjungi 0 → Output: [0]
    
- Kunjungi 1 (tetangga pertama dari 0) → Output: [0, 1]
    
- Kunjungi 2 (tetangga berikutnya dari 0) → Output: [0, 1, 2]
    
- Kunjungi 3 (tetangga pertama dari 2 yang belum dikunjungi) → Output: [0, 1, 2, 3]
    
- Kunjungi 4 (tetangga berikutnya dari 2) → Output akhir: [0, 1, 2, 3, 4]
    
## Apa itu Breadth First Search (BFS)?

**Breadth First Search (BFS)** adalah algoritma dasar untuk menelusuri graf. BFS dimulai dari sebuah simpul, lalu menelusuri semua simpul yang bertetangga dengannya terlebih dahulu. Setelah semua tetangga langsung dikunjungi, barulah simpul-simpul tetangga dari tetangga tersebut yang ditelusuri.

---

BFS berbeda dengan DFS karena simpul-simpul yang **paling dekat** akan dikunjungi terlebih dahulu sebelum simpul lainnya. Umumnya, penelusuran dilakukan secara **level per level**.

Beberapa algoritma graf terkenal seperti **Dijkstra’s shortest path**, **Kahn’s Algorithm**, dan **Prim’s Algorithm** didasarkan pada BFS.

BFS sendiri juga bisa digunakan untuk:

- mendeteksi **siklus** pada graf berarah maupun tak berarah,
    
- menemukan **jalur terpendek** dalam graf yang tidak berbobot,
    
- dan menyelesaikan berbagai masalah lainnya.
    

---

## BFS dari Sumber Tertentu

Algoritma dimulai dari simpul sumber tertentu dan menjelajahi semua simpul yang dapat dijangkau dari sumber tersebut.

Cara kerjanya mirip dengan **penelusuran level-order** pada tree. Seperti pada tree, kita mulai dari simpul awal (dalam tree biasanya dari root/akar), dan menelusuri simpul level demi level menggunakan struktur data **queue (antrian)**.

Namun, perbedaannya adalah:

- Tidak seperti tree, **graf bisa mengandung siklus (cycle)**, sehingga kita bisa saja kembali ke simpul yang sama.
    
- Untuk mencegah suatu simpul diproses lebih dari satu kali, digunakan array **visited** bertipe Boolean.
    
---
Berikut adalah ilustrasi yang mudah dipahami tentang bagaimana algoritma BFS bekerja:

![[B_Implementasi BFS Undirected-3.png]]

![[B_Implementasi BFS Undirected-4.png]]

![[B_Implementasi BFS Undirected-5.png]]

![[B_Implementasi BFS Undirected-6.png]]

![[B_Implementasi BFS Undirected-7.png]]

![[B_Implementasi BFS Undirected-8.png]]

![[B_Implementasi BFS Undirected-9.png]]

![[B_Implementasi BFS Undirected-11.png]]


Ikuti pendekatan berikut ini:
### Inisialisasi:

Masukkan simpul sumber (source vertex) ke dalam **antrian (queue)** dan tandai simpul tersebut sebagai telah dikunjungi.

### Eksplorasi:

Selama antrian tidak kosong:

- Keluarkan satu simpul dari antrian (**dequeue**) dan kunjungi simpul tersebut (misalnya, cetak nilainya).
    
- Untuk setiap tetangga dari simpul tersebut yang **belum dikunjungi**:
    
    - Masukkan tetangga tersebut ke dalam antrian (**enqueue**).
        
    - Tandai tetangga tersebut sebagai telah dikunjungi.
        

### Terminasi:

Ulangi langkah eksplorasi sampai antrian kosong.

---

Algoritma ini memastikan bahwa semua simpul dalam graf dikunjungi secara **breadth-first** (penelusuran melebar), dimulai dari simpul awal.

# Implementasi BFS Undirected - Connected
> [!NOTE] PENTING!
> Materi ini mengajarkan tentang teori, namun implementasi dalam kasus nyata cukup berbeda, dimana program yang dibuat harus dinamis atau mampu menerima inputan user. Untuk hal itu, pelajari di materi ini:
> 
> - [[D_BFS Kasus Nyata Undirected dan Directed]]

Berikut adalah contoh implementasi dengan menggunakan C++:

```cpp
#include<bits/stdc++.h>
using namespace std;

// BFS dari simpul sumber yang diberikan s
vector<int> bfs(vector<vector<int>>& adj)  {
    int V = adj.size();
    
    int s = 0; // simpul sumber
    // buat array untuk menyimpan hasil penelusuran
    vector<int> res;

    // Buat antrian untuk BFS
    queue<int> q;  
    
    // Awalnya tandai semua simpul sebagai belum dikunjungi
    vector<bool> visited(V, false);

    // Tandai simpul sumber sebagai sudah dikunjungi dan masukkan ke antrian
    visited[s] = true;
    q.push(s);

    // Iterasi selama antrian tidak kosong
    while (!q.empty()) {
      
        // Keluarkan satu simpul dari antrian dan simpan
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        // Ambil semua tetangga dari simpul curr yang baru dikeluarkan
        // Jika tetangga belum dikunjungi, tandai sebagai sudah dikunjungi dan masukkan ke antrian
        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }

    return res;
}

int main()  {

    vector<vector<int>> adj = {{1,2}, {0,2,3}, {0,4}, {1,4}, {2,3}};
    vector<int> ans = bfs(adj);
    for(auto i:ans) {
        cout<<i<<" ";
    }
    return 0;
}
```

### Penjelasan versi singkat
Kode tersebut **hanya bekerja untuk graph yang _connected_** — lebih tepatnya, hanya akan menelusuri **semua node yang bisa dijangkau dari simpul sumber `s = 0`**.

#### Penjelasan:

- Karena kode **hanya melakukan BFS dari simpul `0`**, maka **simpul-simpul yang tidak terhubung langsung atau tidak langsung ke simpul `0` tidak akan dikunjungi**.
    
- Ini berarti **graph yang ter-_disconnected_** (terdiri dari lebih dari satu komponen) tidak akan seluruhnya ditelusuri oleh algoritma ini.
    

#### Contoh:

Jika graph-nya seperti ini:

```
Component 1: 0 - 1 - 2
Component 2: 3 - 4
```

Maka BFS dari node `0` hanya akan mengunjungi `0`, `1`, dan `2`. Node `3` dan `4` tidak akan muncul dalam output.

#### Kesimpulan:

- **Jenis graph**: Kode ini hanya lengkap untuk **connected graph** (atau komponen yang terhubung dengan simpul 0).
    
- Untuk menangani **graph yang disconnected**, perlu memanggil BFS dari **setiap simpul yang belum dikunjungi**.
    

## Editorial

Breadth-First Search (BFS) adalah salah satu algoritma dasar dalam teori graf yang digunakan untuk menelusuri atau mencari simpul (node) dalam suatu graf secara menyeluruh (exhaustive search). Algoritma ini bekerja dengan mengunjungi simpul-simpul secara berlapis, dimulai dari simpul sumber (source node) dan bergerak ke simpul-simpul tetangganya terlebih dahulu sebelum melanjutkan ke simpul-simpul yang lebih jauh.

Dalam editorial ini, kita akan membahas implementasi BFS menggunakan bahasa pemrograman C++ beserta penjelasan rinci tentang sintaks dan logika yang digunakan.

---

### Struktur Kode dan Penjelasan
Berikut adalah implementasi BFS dalam C++ beserta penjelasan setiap bagiannya:

### 1. Header dan Namespace
```cpp
#include<bits/stdc++.h>
using namespace std;
```
- `#include<bits/stdc++.h>` adalah header yang mencakup hampir semua library standar C++, sehingga memudahkan dalam penggunaan struktur data seperti `queue` dan `vector`.
- `using namespace std` digunakan agar tidak perlu menulis `std::` sebelum fungsi atau objek dari library standar.

### 2. Fungsi BFS
```cpp
vector<int> bfs(vector<vector<int>>& adj) {
    int V = adj.size();
    
    int s = 0; // simpul sumber
    vector<int> res; // menyimpan hasil penelusuran BFS
```
- Fungsi `bfs` menerima adjacency list (`adj`) yang merepresentasikan graf.
- `V` menyimpan jumlah simpul dalam graf.
- `s = 0` menandakan bahwa pencarian BFS dimulai dari simpul `0` (bisa diubah sesuai kebutuhan).
- `res` adalah vektor yang akan menyimpan urutan simpul yang dikunjungi.

### 3. Inisialisasi Antrian dan Status Kunjungan
```cpp
    queue<int> q; // antrian untuk BFS
    vector<bool> visited(V, false); // menandai simpul yang sudah dikunjungi
```
- `queue<int> q` digunakan untuk menyimpan simpul yang akan diproses.
- `visited` adalah array boolean yang menandai apakah suatu simpul sudah dikunjungi (`true`) atau belum (`false`).

### 4. Memulai BFS dari Simpul Sumber
```cpp
    visited[s] = true;
    q.push(s);
```
- Simpul sumber (`s`) ditandai sebagai sudah dikunjungi dan dimasukkan ke dalam antrian.

### 5. Proses Penelusuran BFS
```cpp
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        res.push_back(curr);
```
- Selama antrian tidak kosong, simpul terdepan (`front`) diambil dan disimpan dalam `curr`, lalu dikeluarkan dari antrian (`pop`).
- Simpul `curr` dimasukkan ke dalam `res` sebagai bagian dari hasil BFS.

### 6. Eksplorasi Tetangga Simpul
```cpp
        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
```
- Untuk setiap tetangga (`x`) dari simpul `curr`:
  - Jika tetangga belum dikunjungi (`!visited[x]`), tandai sebagai sudah dikunjungi dan masukkan ke antrian.
- Proses ini memastikan BFS menelusuri graf secara berlapis (level by level).

### 7. Mengembalikan Hasil BFS
```cpp
    return res;
}
```
- Fungsi mengembalikan vektor `res` yang berisi urutan simpul hasil penelusuran BFS.

---

### 8. Fungsi `main` untuk Pengujian
```cpp
int main() {
    vector<vector<int>> adj = {{1,2}, {0,2,3}, {0,4}, {1,4}, {2,3}};
    vector<int> ans = bfs(adj);
    for(auto i:ans) {
        cout<<i<<" ";
    }
    return 0;
}
```
- Graf direpresentasikan menggunakan adjacency list:
  ```
  0: [1, 2]
  1: [0, 2, 3]
  2: [0, 4]
  3: [1, 4]
  4: [2, 3]
  ```
- Hasil BFS dicetak dalam bentuk urutan simpul yang dikunjungi.

---

## Analisis Kompleksitas
- **Kompleksitas Waktu:** `O(V + E)`, di mana `V` adalah jumlah simpul dan `E` adalah jumlah sisi. Setiap simpul dan sisi dikunjungi tepat sekali.
- **Kompleksitas Ruang:** `O(V)`, karena digunakan antrian (`queue`) dan array `visited` yang menyimpan data sebanyak `V` simpul.

---

## Kesimpulan
Implementasi BFS di atas merupakan contoh dasar yang dapat digunakan untuk:
1. Menelusuri graf secara berurutan.
2. Mencari jalur terpendek dalam graf tidak berbobot.
3. Memeriksa konektivitas graf.

Dengan memahami struktur kode ini, pembaca dapat mengembangkannya untuk kebutuhan yang lebih kompleks, seperti:
- Menambahkan penelusuran berbasis kondisi tertentu.
- Menggunakan BFS untuk menyelesaikan masalah seperti pencarian dalam grid (shortest path dalam labirin).

Semoga penjelasan ini membantu dalam memahami implementasi BFS dalam C++! 🚀

# Implementasi BFS Undirected - Disconnected

Implementasi sebelumnya menerima sebuah **source** sebagai input dan hanya mencetak **vertices** yang dapat dicapai dari source tersebut. Karena itu, implementasi tersebut **tidak akan mencetak semua vertices jika graf dalam keadaan disconnected**.

Mari kita bahas algoritma yang mencetak **seluruh vertices tanpa memerlukan source tertentu**, dan bisa digunakan untuk **graf yang mungkin disconnected**.

Idenya sederhana:  
Alih-alih memanggil BFS hanya untuk satu vertex, kita **memanggil BFS yang telah diimplementasikan sebelumnya untuk setiap vertex yang belum dikunjungi, satu per satu**.

```cpp
#include<bits/stdc++.h>
using namespace std;

// BFS dari source yang diberikan s
void bfs(vector<vector<int>>& adj, int s, 
        vector<bool>& visited, vector<int> &res) {

    // Membuat queue untuk BFS
    queue<int> q; 

    // Tandai node source sebagai sudah dikunjungi dan masukkan ke dalam queue
    visited[s] = true;
    q.push(s);

    // Iterasi melalui queue
    while (!q.empty()) {

        // Ambil vertex dari queue dan simpan
        int curr = q.front(); 
        q.pop();
        res.push_back(curr);

        // Ambil semua vertex tetangga dari vertex yang baru saja di-dequeue
        // Jika tetangga belum dikunjungi, tandai sebagai dikunjungi dan masukkan ke dalam queue
        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}
                      
// Melakukan BFS untuk seluruh graf yang mungkin terputus (disconnected)
vector<int> bfsDisconnected(vector<vector<int>>& adj) {
    int V = adj.size();

    // Membuat array untuk menyimpan hasil traversal
    vector<int> res;

    // Awalnya tandai semua vertex sebagai belum dikunjungi
    vector<bool> visited(V, false); 

    // Melakukan BFS untuk setiap node
    for (int i = 0; i < adj.size(); ++i) {
        if (!visited[i]) {
            bfs(adj, i, visited, res);
        }
    }

    return res;
}

int main()  {

    vector<vector<int>> adj = { {1, 2}, {0}, {0},
                                {4}, {3, 5}, {4}};
    vector<int> ans = bfsDisconnected(adj);
    for(auto i:ans) {
        cout<<i<<" ";
    }
    return 0;
}
```

## Editorial

Breadth-First Search (BFS) adalah algoritma penelusuran graf yang mengunjungi simpul secara berlapis (level by level). Pada graf terhubung (connected graph), BFS dimulai dari satu simpul sumber dan mengunjungi semua simpul yang terjangkau. Namun, pada graf terputus (disconnected graph), beberapa simpul mungkin tidak dapat dijangkau dari simpul sumber awal, sehingga diperlukan modifikasi agar BFS dapat menjangkau seluruh komponen graf.

Dalam editorial ini, kita akan membahas implementasi BFS untuk graf terputus menggunakan C++, termasuk penjelasan sintaks dan logika di baliknya.

---

### Struktur Kode dan Penjelasan
Kode ini terdiri dari dua fungsi utama:
1. `bfs()` – Melakukan BFS dari suatu simpul sumber.
2. `bfsDisconnected()` – Memastikan BFS mencakup seluruh komponen graf yang terputus.

### 1. Fungsi `bfs()`
```cpp
void bfs(vector<vector<int>>& adj, int s, vector<bool>& visited, vector<int>& res) {
    queue<int> q; 
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int curr = q.front(); 
        q.pop();
        res.push_back(curr);

        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}
```
#### Penjelasan:
- **Input:**
  - `adj`: Adjacency list yang merepresentasikan graf.
  - `s`: Simpul sumber untuk memulai BFS.
  - `visited`: Array boolean untuk melacak simpul yang sudah dikunjungi.
  - `res`: Vektor untuk menyimpan urutan kunjungan BFS.
- **Proses:**
  1. Buat antrian (`queue`) untuk menyimpan simpul yang akan diproses.
  2. Tandai simpul sumber (`s`) sebagai sudah dikunjungi dan masukkan ke antrian.
  3. Selama antrian tidak kosong:
     - Ambil simpul terdepan (`front`), simpan ke `res`, lalu keluarkan dari antrian (`pop`).
     - Untuk setiap tetangga (`x`) dari simpul tersebut:
       - Jika belum dikunjungi (`!visited[x]`), tandai dan masukkan ke antrian.
- **Output:** Hasil BFS disimpan di `res`.

---

### 2. Fungsi `bfsDisconnected()`
```cpp
vector<int> bfsDisconnected(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<int> res;
    vector<bool> visited(V, false); 

    for (int i = 0; i < adj.size(); ++i) {
        if (!visited[i]) {
            bfs(adj, i, visited, res);
        }
    }
    return res;
}
```
#### Penjelasan:
- **Input:** `adj` (adjacency list graf).
- **Proses:**
  1. Inisialisasi `visited` dengan `false` (semua simpul belum dikunjungi).
  2. Loop melalui semua simpul (`0` hingga `V-1`):
     - Jika simpul belum dikunjungi (`!visited[i]`), lakukan BFS dari simpul tersebut.
  3. Dengan cara ini, semua komponen graf (baik terhubung maupun terputus) akan dikunjungi.
- **Output:** Vektor `res` berisi urutan BFS untuk seluruh graf.

---

### 3. Fungsi `main()` untuk Pengujian
```cpp
int main() {
    vector<vector<int>> adj = { {1, 2}, {0}, {0}, {4}, {3, 5}, {4} };
    vector<int> ans = bfsDisconnected(adj);
    for(auto i:ans) {
        cout<<i<<" ";
    }
    return 0;
}
```
#### Penjelasan:
- Graf direpresentasikan dalam adjacency list:
  ```
  0: [1, 2]
  1: [0]
  2: [0]
  3: [4]
  4: [3, 5]
  5: [4]
  ```
- Graf ini terdiri dari **2 komponen terputus**:
  - Komponen 1: `0 ↔ 1 ↔ 2`
  - Komponen 2: `3 ↔ 4 ↔ 5`
- Hasil BFS akan mencetak urutan kunjungan untuk semua simpul, misalnya:  
  **`0 1 2 3 4 5`** (bergantung pada urutan pemrosesan).

---

## Analisis Kompleksitas
- **Kompleksitas Waktu:** `O(V + E)`  
  - Setiap simpul dan sisi dikunjungi tepat sekali.
- **Kompleksitas Ruang:** `O(V)`  
  - Digunakan untuk menyimpan `visited`, `queue`, dan `res`.

---

## Perbandingan dengan BFS untuk Graf Terhubung

| **Aspek**               | **BFS Terhubung**               | **BFS Terputus**                     |
|-------------------------|--------------------------------|--------------------------------------|
| **Inisialisasi**        | Mulai dari 1 simpul sumber (`s=0`) | Loop semua simpul, mulai jika belum dikunjungi |
| **Jangkauan**           | Hanya komponen terhubung dengan `s` | Semua komponen graf                  |
| **Implementasi**        | Cukup 1 kali panggil `bfs()`    | Perlu loop dan cek `visited`         |
| **Contoh Kasus**        | Pohon, graf terhubung          | Jaringan terisolasi, graf tidak terhubung |

---

## Kesimpulan
Implementasi BFS untuk graf terputus penting karena:
1. **Menangani kasus graf tidak terhubung** (misal: jaringan dengan subnet terisolasi).
2. **Memastikan semua komponen terproses** tanpa melewatkan simpul mana pun.
3. **Dapat dikembangkan** untuk:
   - Menghitung jumlah komponen terhubung.
   - Memeriksa bipartiteness pada seluruh graf.
   - Mencari shortest path dalam graf berbobot seragam.

Dengan memahami konsep ini, pembaca dapat mengadaptasi BFS untuk berbagai masalah graf yang lebih kompleks. 