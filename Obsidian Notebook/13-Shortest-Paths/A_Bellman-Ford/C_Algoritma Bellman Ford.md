---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 13TH-SPBF-0003
nama_algoritma: Bellman Ford Algorithm
kategori_algoritma: Graph - Shortest Path
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen & programmiz.com & geeksforgeeks.com & chatgpt.com"
date_learned: 2025-05-04T12:54:00
tags:
  - graph-algorithm
  - shortest-paths
  - bellman-ford
---
#graph-algorithm #shortest-paths #bellman-ford 

---
# Algoritma Bellman–Ford

Diberikan sebuah graf berbobot dengan **V** _vertex_ dan **E** _edge_, serta sebuah _source vertex_ `src`. Tugasnya adalah menghitung jarak terpendek dari _source_ ke semua _vertex_ lainnya. Jika suatu _vertex_ tidak dapat dijangkau dari _source_, jaraknya harus ditandai dengan $10^8$. Jika terdapat **siklus berbobot negatif** (_negative weight cycle_), maka kembalikan **-1** untuk menandakan bahwa perhitungan _shortest path_ tidak memungkinkan.

## Contoh:
#### Input:

`V = 5`  
`edges = [[0, 1, 5], [1, 2, 1], [1, 3, 2], [2, 4, 1], [4, 3, -1]]`  
`src = 0`

![[C_Implementasi Algoritma Bellman Ford-1.png]]

#### Output:

`[0, 5, 6, 6, 7]`

#### Penjelasan:

_Shortest Paths_:

- Dari 0 ke 1, jarak minimum adalah 5 melalui jalur **0 → 1**
    
- Dari 0 ke 2, jarak minimum adalah 6 melalui jalur **0 → 1 → 2**
    
- Dari 0 ke 3, jarak minimum adalah 6 melalui jalur **0 → 1 → 2 → 4 → 3**
    
- Dari 0 ke 4, jarak minimum adalah 7 melalui jalur **0 → 1 → 2 → 4**
    

---

#### Input:

`V = 4`  
`edges = [[0, 1, 4], [1, 2, -6], [2, 3, 5], [3, 1, -2]]`  
`src = 0`

![[C_Implementasi Algoritma Bellman Ford-2.png]]

#### Output:

`[-1]`

#### Penjelasan:

Graf mengandung **siklus berbobot negatif** (_negative weight cycle_) yang dibentuk oleh jalur **1 → 2 → 3 → 1**, di mana total bobot siklus tersebut bernilai negatif.

---
# Siklus Berbobot Negatif (Negative Weight Cycle):

Siklus berbobot negatif adalah sebuah **siklus dalam graf** di mana jumlah bobot dari seluruh _edge_ dalam siklus tersebut bernilai negatif. Jika kamu menelusuri siklus tersebut, total bobot yang terkumpul akan menjadi kurang dari nol.

![[C_Implementasi Algoritma Bellman Ford-3.png]]

Jika terdapat **siklus berbobot negatif** di dalam graf, maka _shortest path_ tidak akan ada, karena setiap kali kita menelusuri siklus tersebut, total jarak akan terus berkurang tanpa batas.

---

## Keterbatasan Algoritma Dijkstra:

Karena kita ingin mencari **shortest path dari satu sumber** (_single source shortest path_), mungkin kita akan terpikir untuk menggunakan algoritma Dijkstra. Namun, Dijkstra **tidak cocok** jika graf memiliki _edge_ berbobot negatif.  

Alasannya adalah: Dijkstra **tidak akan mengunjungi kembali** node yang sudah ditandai sebagai “telah dikunjungi”.  

Jika ada _shorter path_ yang bisa ditemukan melalui jalur lebih panjang yang mengandung _negative edge_, algoritma Dijkstra **tidak akan bisa menemukannya**.

---

## Prinsip _Relaxation_ pada Edge:

_Relaxation_ berarti memperbarui jarak terpendek ke suatu _node_ jika ditemukan jalur yang lebih pendek melalui _node_ lain. Untuk sebuah _edge_ (u, v) dengan bobot w:

Jika melewati u memberikan jalur lebih pendek ke v dari _source_ (yaitu `distance[v] > distance[u] + w`), maka kita perbarui `distance[v] = distance[u] + w`.

Dalam algoritma Bellman-Ford, proses ini diulang sebanyak **(V – 1)** kali untuk semua _edge_.

---

## Mengapa Melakukan _Relaxation_ Sebanyak (V – 1) Kali Akan Menjamin _Shortest Path_ dari Satu Sumber?

Jalur terpendek antara dua _vertex_ bisa memiliki paling banyak **(V – 1)** _edge_. Tidak mungkin ada jalur sederhana (tanpa siklus) yang memiliki lebih dari (V – 1) _edge_ — karena jika lebih, pasti membentuk siklus.

Oleh karena itu, dengan mengulang proses _relaxation_ sebanyak (V – 1) kali, kita memastikan bahwa semua jalur potensial dari _source_ ke setiap _node_ telah dievaluasi.

 Contoh _Relaxation_ (dengan asumsi node 0 sebagai _source_):
 
![[C_Implementasi Algoritma Bellman Ford-4.png]]

1. **Relaxation Pertama:**  
    Karena jarak terpendek ke vertex 1 dan 2 belum diketahui (masih tak hingga, yaitu $10^8$), maka jarak ke vertex 2 dan 3 juga tetap $10^8$.  
    Namun, untuk vertex 1, jaraknya diperbarui menjadi 4 karena `dist[0] + 4 < dist[1]` (yaitu `0 + 4 <`$10^8$).

<br/>

2. **Relaxation Kedua:**  
    Jarak ke vertex 2 masih $10^8$, jadi jarak ke vertex 3 juga belum berubah.  
    Namun sekarang, `dist[2]` bisa diperbarui menjadi 3 karena `dist[1] + (-1) = 3`.
<br/>

3. **Relaxation Ketiga:**  
    Jarak ke vertex 3 akan diperbarui menjadi 5 karena `dist[2] + 2 = 5`.
<br/>

Jadi, dalam contoh di atas:

- `dist[1]` diperbarui pada _relaxation_ pertama
    
- `dist[2]` diperbarui pada _relaxation_ kedua
    
- Maka, `dist` untuk node terakhir (V – 1) akan diperbarui pada _relaxation_ ke-(V – 1)
    

# Deteksi Siklus Berbobot Negatif (Negative Weight Cycle)

Seperti yang telah kita bahas sebelumnya, kita membutuhkan **(V – 1)** kali _relaxation_ pada seluruh _edge_ untuk memperoleh _single source shortest path_.

Jika setelah itu masih memungkinkan dilakukan **1 kali _relaxation_ tambahan (ke-V)** pada salah satu _edge_, hal ini menunjukkan bahwa terdapat _edge_ yang menyebabkan bobot total menjadi lebih kecil — artinya telah terjadi _relaxation_ tambahan pada jalur yang melibatkan **siklus berbobot negatif**.

Hal ini menjadi **indikasi kuat** bahwa graf mengandung **negative weight cycle**.

---

## Ringkasan:

- Bellman-Ford adalah algoritma _single source shortest path_.
    
- Efektif digunakan untuk graf yang memiliki _edge_ berbobot negatif.
    
- Tidak hanya menghitung jarak terpendek, tapi juga mampu **mendeteksi keberadaan siklus berbobot negatif**.
    
- Bekerja berdasarkan prinsip _relaxation_ terhadap semua _edge_.
    

---

## Ilustrasi:
![[C_Implementasi Algoritma Bellman Ford-6.png]]


![[C_Implementasi Algoritma Bellman Ford-7.png]]


![[C_Implementasi Algoritma Bellman Ford-5.png]]

![[C_Implementasi Algoritma Bellman Ford-8.png]]

![[C_Implementasi Algoritma Bellman Ford-9.png]]

![[C_Implementasi Algoritma Bellman Ford-10.png]]

# Implementasi Algoritma Belman Ford
Berikut adalah implementasi dari Algoritma Bellman Ford dengan menggunakan C++:

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Fungsi untuk menjalankan algoritma Bellman-Ford
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    
    // Awalnya, jarak dari source ke semua vertex lain tidak diketahui (tak hingga)
	vector<int> dist(V, 1e8);
	dist[src] = 0;
  
	// Lakukan *relaxation* terhadap semua edge sebanyak V kali,
    // bukan (V - 1), karena kita butuh 1 iterasi tambahan untuk mendeteksi siklus negatif
	for (int i = 0; i < V; i++) {
	    
		for (vector<int> edge : edges) {
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
			    
                // Jika ini adalah *relaxation* ke-V, berarti terdapat siklus negatif
                if(i == V - 1)
                    return {-1};
               
                // Perbarui jarak terpendek ke node v
                dist[v] = dist[u] + wt;
            }
		}
	}

    return dist;
}

int main() {
    
    // Jumlah vertex dalam graf
    int V = 5;

    // Representasi edge list: {source, destination, weight}
    vector<vector<int>> edges = {
        {1, 3, 2}, 
        {4, 3, -1},
        {2, 4, 1}, 
        {1, 2, 1},
        {0, 1, 5} 
    };

    // Tentukan source vertex
    int src = 0;

    // Jalankan algoritma Bellman-Ford untuk mendapatkan shortest path dari src
    vector<int> ans = bellmanFord(V, edges, src);

    // Cetak jarak terpendek dari src ke semua vertex
    for (int dist : ans) 
        cout << dist << " ";

    return 0; 
}
```

# Implementasi Algoritma Bellman Ford Versi lanjut
Berikut adalah implementasi algoritma Bellman Ford yang sudah disesuaikan:

```cpp
#include<iostream>
#include<vector>
using namespace std;

const int INF = 1e9;

inline void fastio(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}

vector<int> bellmanFord(int n, vector<vector<int>>&edges, int src){
    vector<int> dist(n, INF);
    dist[src]=0;

    for(int i=0;i<n;i++){
        for(vector<int>edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if(dist[u] != INF && dist[u]+wt < dist[v]){
                if(i == n-1){
                    return {-1};
                } 

                dist[v] = dist[u] + wt;
            }
        }
    }
    return dist;
}

int main() {
    fastio();
    int n,m;
    cin >> n >> m;

    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;

        edges.push_back({u,v,w});
    }

    int src=0;
    vector<int> rest = bellmanFord(n, edges, src);

    cout << "\nHasil: ";
    for(auto&x:rest){
        if(x==INF) cout << "INF ";
        else cout << x << " ";
    }
    cout << "\n";
    return 0;
}
```

## Editorial Lengkap
Tentu! Berikut adalah **editorial lengkap** mengenai setiap penggunaan **syntax** dalam kode yang kamu berikan:

### 1. **`#include<iostream>` dan `#include<vector>`**

```cpp
#include<iostream>
#include<vector>
```

- `#include<iostream>`: Menyertakan library standar C++ untuk input/output (I/O). Library ini memungkinkan penggunaan `cin` dan `cout`.
    
- `#include<vector>`: Menyertakan library C++ untuk penggunaan struktur data **vector**. Vector adalah container dinamis yang bisa menampung sejumlah elemen dan ukuran bisa berubah secara otomatis.
    

### 2. **`using namespace std;`**

```cpp
using namespace std;
```

- Menggunakan **namespace standar** (std) agar tidak perlu menulis `std::` di depan objek atau fungsi yang ada di dalam namespace ini, seperti `cin`, `cout`, `vector`, dll.
    

### 3. **`const int INF = 1e9;`**

```cpp
const int INF = 1e9;
```

- Menetapkan sebuah **konstanta** `INF` dengan nilai `1e9` (1,000,000,000), yang digunakan untuk merepresentasikan **nilai tak terhingga** atau **unreachable distance** dalam algoritma Bellman-Ford. Ini berarti jika sebuah node tidak dapat dijangkau, jaraknya akan diset ke `INF`.
    

### 4. **`inline void fastio() {...}`**

```cpp
inline void fastio(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}
```

- `inline`: Menyatakan bahwa fungsi `fastio()` diharapkan untuk dipanggil **di tempat** (inline), yang berarti compiler akan menggantikan pemanggilan fungsi dengan isi fungsi tersebut langsung untuk mengurangi overhead pemanggilan fungsi.
    
- **`ios_base::sync_with_stdio(0)`**: Menonaktifkan sinkronisasi antara C-style I/O (`scanf`/`printf`) dan C++-style I/O (`cin`/`cout`). Ini dapat meningkatkan performa I/O.
    
- **`cin.tie(0)` dan `cout.tie(0)`**: Memutuskan hubungan antara `cin` dan `cout`, yang biasanya secara default disinkronkan agar `cin` flush sebelum `cout`. Dengan menonaktifkannya, I/O bisa lebih cepat karena tidak ada buffer flushing yang tidak perlu.
    

### 5. **`vector<int> bellmanFord(int n, vector<vector<int>>& edges, int src)`**

```cpp
vector<int> bellmanFord(int n, vector<vector<int>>& edges, int src){
```

- Fungsi ini mengembalikan **vector**, yang menyimpan jarak terpendek dari **sumber (source)** ke setiap node.
    
- **`n`**: Jumlah total **node** dalam graf.
    
- **`edges`**: Referensi ke **list edges** (setiap edge berisi 3 elemen: node awal, node tujuan, dan bobot).
    
- **`src`**: **Node sumber** dari mana algoritma Bellman-Ford akan dihitung.
    

### 6. **`vector<int> dist(n, INF);`**

```cpp
vector<int> dist(n, INF);
```

- Membuat **vector `dist`** dengan panjang `n` (jumlah node). Setiap elemen diinisialisasi dengan **INF**, yang menunjukkan jarak tak terhingga dari node sumber ke node lainnya.
    

### 7. **`dist[src] = 0;`**

```cpp
dist[src] = 0;
```

- Menginisialisasi **jarak sumber** (node `src`) ke 0, karena jarak dari sumber ke dirinya sendiri adalah 0.
    

### 8. **Loop untuk Relaxasi Edges**

```cpp
for(int i = 0; i < n; i++){
    for(vector<int> edge : edges){
```

- **`for(int i = 0; i < n; i++)`**: Loop ini melakukan relaksasi **`n` kali** (karena jarak terpendek pada graf dengan `n` node bisa diproses dalam maksimal `n-1` relaksasi).
    
- **`for(vector<int> edge : edges)`**: Loop ini akan mengiterasi setiap **edge** dalam daftar **edges**. Setiap **edge** adalah **vector** dengan tiga elemen, yang merepresentasikan `(u, v, wt)`.
    

### 9. **`int u = edge[0]; int v = edge[1]; int wt = edge[2];`**

```cpp
int u = edge[0];
int v = edge[1];
int wt = edge[2];
```

- **`u`**: Node awal dari edge.
    
- **`v`**: Node tujuan dari edge.
    
- **`wt`**: Bobot dari edge tersebut.
    

### 10. **`if (dist[u] != INF && dist[u] + wt < dist[v])`**

```cpp
if(dist[u] != INF && dist[u] + wt < dist[v]){
```

- **Pengecekan** apakah jarak ke **node u** tidak tak terhingga dan apakah jalur melalui node `u` lebih pendek daripada jarak yang sudah tercatat di node `v`. Jika benar, maka kita melakukan **relaksasi** untuk memperbarui jarak ke node `v`.
    

### 11. **`if(i == n - 1) return {-1};`**

```cpp
if(i == n - 1) return {-1};
```

- Jika pada **relaksasi ke-`n`** (relaksasi terakhir), masih ada perubahan jarak, ini menunjukkan adanya **siklus negatif** (negative weight cycle). Fungsi akan mengembalikan **`{-1}`** untuk menandakan bahwa graf mengandung siklus negatif.
    

### 12. **`dist[v] = dist[u] + wt;`**

```cpp
dist[v] = dist[u] + wt;
```

- Melakukan **relaksasi** pada node `v`, memperbarui jarak terpendek ke node `v` melalui node `u`.
    

### 13. **`return dist;`**

```cpp
return dist;
```

- Fungsi `bellmanFord` mengembalikan vector `dist`, yang berisi jarak terpendek dari sumber ke setiap node dalam graf.
    

### 14. **`int main()`**

```cpp
int main() {
```

- Fungsi utama `main` adalah titik masuk program.
    

### 15. **`fastio();`**

```cpp
fastio();
```

- Memanggil fungsi `fastio()` yang telah didefinisikan sebelumnya untuk mempercepat operasi input/output.
    

### 16. **`cin >> n >> m;`**

```cpp
cin >> n >> m;
```

- Membaca jumlah **node (`n`)** dan jumlah **edge (`m`)**.
    

### 17. **`vector<vector<int>> edges;`**

```cpp
vector<vector<int>> edges;
```

- Membuat vector dua dimensi `edges` untuk menyimpan semua edge dari graf. Setiap edge adalah vector berisi `{u, v, bobot}`.
    

### 18. **`edges.push_back({u, v, w});`**

```cpp
edges.push_back({u, v, w});
```

- Menambahkan edge baru ke dalam list **edges**.
    

### 19. **`vector<int> rest = bellmanFord(n, edges, src);`**

```cpp
vector<int> rest = bellmanFord(n, edges, src);
```

- Memanggil fungsi `bellmanFord` untuk menghitung jarak terpendek dari node sumber `src` ke semua node lainnya, dan menyimpan hasilnya dalam vector `rest`.
    

### 20. **Loop untuk mencetak hasil**

```cpp
for(auto& x : rest){
    if(x == INF) cout << "INF ";
    else cout << x << " ";
}
```

- Loop ini mencetak hasil dari vector `rest`:
    
    - **Jika `x == INF`**: Menandakan bahwa node tersebut tidak dapat dijangkau dari sumber, dan mencetak **INF**.
        
    - **Jika tidak**: Mencetak jarak terpendek ke node tersebut.
        

### 21. **`return 0;`**

```cpp
return 0;
```

- Menandakan bahwa program selesai dijalankan dengan sukses.
    

---

### 🧠 **Kesimpulan**

- Program ini mengimplementasikan **algoritma Bellman-Ford** untuk menghitung jarak terpendek dari sumber ke semua node pada graf berarah.
    
- Kode ini menggunakan teknik **relaksasi** untuk memperbarui jarak dan mendeteksi **siklus negatif**.
    
- `fastio()` digunakan untuk mempercepat input/output, yang berguna untuk kompetisi pemrograman.
    

