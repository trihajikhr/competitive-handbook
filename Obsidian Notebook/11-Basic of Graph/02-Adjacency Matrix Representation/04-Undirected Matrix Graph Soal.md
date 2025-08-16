---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 11TH-BGRP-MR04
nama_algoritma: adjacency matrix representation
kategori_algoritma: graph algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber:
  - "buku: CP handbook by Antti Laaksonen"
  - chatgpt.com
date_learned: 2025-04-28T21:42:00
tags:
  - graph-algorithm
  - graph-basic
---
---
# 1 | Soal 1 Undirected Graph (Tanpa Bobot)

**Deskripsi:** Diberikan sebuah undirected graph, tampilkan adjacency matrix-nya.

**Input:**

- Baris pertama: dua integer `n` dan `m`, di mana `n` adalah jumlah node, dan `m` adalah jumlah edges.
    
- Baris berikutnya: `m` pasangan integer `u v` yang menunjukkan bahwa ada edge antara node `u` dan node `v`.
    

**Output:**

- Matriks adjacency berukuran `n x n`, di mana elemen matriks pada posisi `[i][j]` bernilai `1` jika ada edge antara node `i` dan node `j`, dan `0` jika tidak ada.
    

**Contoh Input 1:**

```
3 3
1 2
2 3
3 1
```

**Contoh Output 1:**

```
0 1 1
1 0 1
1 1 0
```

**Penjelasan:**

- Ada 3 node.
    
- Node 1 terhubung dengan node 2.
    
- Node 2 terhubung dengan node 3.
    
- Node 3 terhubung dengan node 1. Karena graph-nya undirected, kita juga harus mencatat bahwa jika `i` terhubung dengan `j`, maka `j` juga terhubung dengan `i`.
    

## 1.1 | Jawaban

Berikut kode C++ nya:

```cpp
#include<iostream>
#include<vector>
using namespace std;

inline void fastio(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}

int main() {
    fastio();
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj (n+1, vector<int>(n+1,0));

    for(int i=0;i<m;i++){
        int u,v;

        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    cout << "\n";
    for(int i=1; i<=n;i++){
        for(int j=1; j<=n; j++){
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
```
## 1.2 | Editorial

```cpp
#include<iostream>
#include<vector>
using namespace std;
```

- Import library penting:
    
    - `iostream` untuk input/output.
        
    - `vector` untuk menggunakan array dinamis 2 dimensi (matrix).


```cpp
inline void fastio(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}
```

- Membuat fungsi `fastio()` untuk mempercepat input/output.
    
- Ini biasa dipakai di **competitive programming** supaya program membaca input lebih cepat.
    

```cpp
int main() {
    fastio();
```

- Memanggil `fastio()` di `main` supaya aktif.
    
- Memulai program.
    


```cpp
int n, m;
cin >> n >> m;
```

- Membaca banyaknya **node** `n` dan banyaknya **edge** `m`.
    


```cpp
vector<vector<int>> adj (n+1, vector<int>(n+1,0));
```

- Membuat **matrix adjacency** berukuran `(n+1) x (n+1)`, diisi dengan nilai awal `0`.
    
- Kenapa `n+1`? Karena kamu ingin indexing dari **1** hingga **n** (bukan dari 0).
    
- Nilai `0` artinya: **tidak ada koneksi** antar dua node.
    


```cpp
for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    adj[u][v] = 1;
    adj[v][u] = 1;
}
```

- Loop sebanyak `m` untuk membaca semua edge.
    
- Untuk setiap pasangan node `(u, v)`, kamu:
    
    - Set `adj[u][v] = 1`
        
    - dan `adj[v][u] = 1`
        
- Karena ini **undirected graph**, hubungan dua arah harus sama-sama diupdate.
    

```cpp
cout << "\n";
for(int i=1; i<=n;i++){
    for(int j=1; j<=n; j++){
        cout << adj[i][j] << " ";
    }
    cout << "\n";
}
```

- Menampilkan **matrix adjacency**.
    
- Untuk setiap `i` dan `j`, kamu print `adj[i][j]`, dengan spasi.
    
- Setelah satu baris selesai (`j` habis), kamu `cout << "\n"`.
    

## 1.3 | Contoh Input/Output

Input:

```
5 4
1 2
1 3
4 5
2 4
```

Artinya:

- 5 node
    
- 4 edge:
    
    - 1 terhubung ke 2
        
    - 1 terhubung ke 3
        
    - 4 terhubung ke 5
        
    - 2 terhubung ke 4
        

Output:

```
0 1 1 0 0
1 0 0 1 0
1 0 0 0 0
0 1 0 0 1
0 0 0 1 0
```

Keterangan:

- `1` berarti **ada edge** antara dua node.
    
- `0` berarti **tidak ada edge**.
    

✅ **Kesimpulan:**  

Kode yang kamu buat **sudah 100% benar** untuk **undirected unweighted graph** dengan **matrix representation**!



---

# 2 | Soal 2 Undirected Graph (Dengan Bobot)

**Deskripsi:** Diberikan sebuah undirected graph berbobot, tampilkan weighted adjacency matrix-nya.

**Input:**

- Baris pertama: dua integer `n` dan `m`, di mana `n` adalah jumlah node, dan `m` adalah jumlah edges.
    
- Baris berikutnya: `m` triplet integer `u v w`, di mana `u` dan `v` adalah node yang terhubung, dan `w` adalah bobot dari edge tersebut.
    

**Output:**

- Matriks adjacency berukuran `n x n`, di mana elemen matriks pada posisi `[i][j]` bernilai `w` jika ada edge antara node `i` dan node `j`, dan `0` jika tidak ada.
    

**Contoh Input 2:**

```
3 3
1 2 5
2 3 3
3 1 2
```

**Contoh Output 2:**

```
0 5 2
5 0 3
2 3 0
```

**Penjelasan:**

- Ada 3 node.
    
- Node 1 terhubung dengan node 2 dengan bobot 5.
    
- Node 2 terhubung dengan node 3 dengan bobot 3.
    
- Node 3 terhubung dengan node 1 dengan bobot 2. Karena graph-nya undirected, matriks adjacency-nya akan simetris (misalnya, elemen `[1][2]` dan `[2][1]` sama).
    
## 2.1 | Jawaban
Berikut adalah implementasi dengan menggunakan C++ yang sudah cukup solid:

```cpp
#include<iostream>
#include<vector>
using namespace std;

inline void fastio(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}

const int INF = 1e9;

int main() {
    fastio();

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1, vector<int>(n+1, INF));

    for(int i=0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u][v]=w;
        adj[v][u]=w;
    }

    cout << "\n";
    for(int i=1; i<=n;i++){
        for(int j=1; j<= n;j++){
            if(adj[i][j] == INF) cout << "INF ";
            else cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
```

## 2.2 | Editorial


```cpp
#include<iostream>
#include<vector>
using namespace std;
```

- Import `iostream` untuk input/output, dan `vector` untuk memakai array 2 dimensi (matrix) yang fleksibel ukurannya.
    

```cpp
inline void fastio(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}
```

- Fungsi untuk mempercepat input/output. Ini membuat program lebih cepat membaca data dari `cin` dan menulis ke `cout`.
    

```cpp
const int INF = 1e9;
```

- `INF` di-set ke `1e9` (1.000.000.000) sebagai **nilai besar** untuk menandai **tidak ada edge** antara dua node.
    

```cpp
int main() {
    fastio();
```

- Mulai `main()` dan memanggil `fastio()`.
    

```cpp
int n, m;
cin >> n >> m;
```

- Membaca `n` node dan `m` edge dari input.


```cpp
vector<vector<int>> adj(n+1, vector<int>(n+1, INF));
```

- Membuat matrix `adj` berukuran `(n+1) x (n+1)`, dengan semua nilai awal diisi `INF`.
    
- Karena node-nya mulai dari `1`, bukan `0`, maka dibuat ukuran `n+1`.


```cpp
for(int i=0;i<m;i++){
    int u, v, w;
    cin >> u >> v >> w;
    adj[u][v]=w;
    adj[v][u]=w;
}
```

- Untuk setiap edge:
    
    - `u` dan `v` adalah node yang terhubung.
        
    - `w` adalah bobot (weight) dari edge itu.
        
- Karena ini **undirected graph**, maka:
    
    - `adj[u][v] = w`
        
    - dan `adj[v][u] = w`
        
- Ini memastikan **kedua arah** (`u` ke `v` dan `v` ke `u`) punya **nilai bobot** yang sama.


```cpp
cout << "\n";
for(int i=1; i<=n;i++){
    for(int j=1; j<= n;j++){
        if(adj[i][j] == INF) cout << "INF ";
        else cout << adj[i][j] << " ";
    }
    cout << "\n";
}
```

- Menampilkan matrix adjacency.
    
- Untuk setiap node `i` ke `j`:
    
    - Jika `adj[i][j] == INF`, artinya **tidak ada koneksi**, jadi tampilkan `"INF"`.
        
    - Kalau ada bobot (`w`), tampilkan bobotnya.


## 2.3 | Contoh Input/Output

Input:

```
4 5
1 2 10
1 3 5
2 3 2
2 4 1
3 4 7
```

Artinya:

- Ada 4 node, 5 edge.
    
- Edge:
    
    - 1-2 dengan bobot 10
        
    - 1-3 dengan bobot 5
        
    - 2-3 dengan bobot 2
        
    - 2-4 dengan bobot 1
        
    - 3-4 dengan bobot 7
        

Output:

```
INF 10 5 INF 
10 INF 2 1 
5 2 INF 7 
INF 1 7 INF 
```


✅ **Kesimpulan:**  

Jawabanmu **sudah benar 100%** untuk kasus **undirected, weighted graph** menggunakan **matrix representation**!

---

# 3 | Informasi Tambahan

Ada beberapa hal yang masih membuatku bingung, jadi aku menanyakan beberapa hal:
## 3.1 | Kenapa `1e9`?

> Hei, jika 1e9 itu merujuk ke angka 1 milyar, bukankah akan mengisi memory besar?

Bagus banget pertanyaannya! 🔥  
Dan ya, **benar**, tapi **mari kita kupas pelan-pelan** supaya kamu paham betul:

## 3.2 | Apakah `1e9` Membuat Matrix Berat di Memory?

**Jawabannya: Tidak,**  
karena **`1e9` itu cuma sebuah **nilai angka biasa** yang diisikan ke elemen-elemen matrix.

Kalau kita membuat ini:

```cpp
const int INF = 1e9;
vector<vector<int>> adj(n+1, vector<int>(n+1, INF));
```

- **Matrix `adj`** tetap berisi **tiap elemennya bertipe `int`**, yang dalam C++ biasanya ukuran `4 byte` (32 bit).
    
- Mau isinya `0`, `1`, `123`, atau `1e9`, **ukuran memory tiap elemen tetap 4 byte**.
    
- **Bukan** berarti "karena angkanya besar jadi memorinya lebih besar" — **bukan begitu** cara kerja memory komputer.
    

**Singkatnya:**

- Memory matrix ditentukan oleh **jumlah elemennya**, **bukan besar nilainya**.
    
- Jadi kalau matrix `n x n`, memory ≈ `n² × 4 byte`.
    
### 3.2.1 | Contoh Hitungan Kasar

Misalnya `n = 1000`:

- Ukuran matrix `1000 × 1000 = 1.000.000` elemen.
    
- 1 elemen = 4 byte.
    
- Total memory = **4 MB**.
    

➡️ **Tetap 4MB**, entah isinya `0`, `1e9`, atau `-99999` sekalipun.

### 3.2.2 | Kenapa pakai nilai besar seperti `1e9`?

Karena:

- Untuk **membedakan** antara:
    
    - "ada edge" (berbobot kecil/mana saja) ✅
        
    - **dan** "tidak ada edge" (kita tandai dengan `INF`) ❌
        
- `1e9` adalah angka yang **dijamin lebih besar** dari bobot edge normal dalam soal graph biasa.
    

Kalau bobot antar node kecil-kecil, misalnya maksimal bobot 1000, maka `1e9` **pasti lebih besar**, jadi aman digunakan untuk menandai **ketiadaan edge**.

## 3.3 | Kesimpulannya

|Hal|Jawaban|
|:--|:--|
|Apakah angka besar memperbesar memory?|❌ Tidak|
|Yang menentukan memory?|✅ Banyaknya elemen matrix|
|Kenapa pilih angka besar?|✅ Untuk menandai "tidak ada edge" dengan jelas|


Kalau mau lebih hemat memory, ada teknik lain juga seperti:

- **Matrix dinamis** (pakai `map` buat sparse graph)
    
- **Pakai adjacency list** (daripada matrix, kalau edge jarang)
    

Tapi untuk **belajar basic graph** — cara kamu sekarang **sudah sangat baik**! 🔥

> Sebentar, jadi 1e9 itu kita pilih karena dijamin tidak ada bobot yang seukuran 1 milyar? Aku masih tidak paham, kenapa harus 1e9? Kan 1 milyar sangat besar, apa ngga terlalu membebani memory?

Oke, aku jelaskan **lebih pelan-pelan lagi**, supaya kamu benar-benar paham ya 🔥.  
Ini pertanyaan _penting banget_, dan kamu **sangat tepat** mempertanyakannya.

## 3.4 | Kenapa harus pakai `1e9` untuk INF?

**Tujuannya:**  
Kita perlu **menandai** mana dua node yang **tidak terhubung**.  
Karena dalam **matrix adjacency weighted graph**, semua kombinasi `(u,v)` pasti ada nilainya.

Jadi:

- Kalau `u` dan `v` **terhubung**, kita isi dengan bobot sebenarnya (misal 2, 5, 20, dst).
    
- Kalau **tidak terhubung**, kita butuh angka **khusus** untuk menandai bahwa "tidak ada jalan di antara `u` ke `v`".
    

Nah, angka **INF** ini digunakan sebagai tanda bahwa tidak ada koneksi.

### 3.4.1 | Lalu, kenapa angka besar seperti `1e9`?

Karena **angka bobot asli biasanya kecil** di kebanyakan soal graph (misal 1–1000).

Kalau kita pakai angka besar (seperti `1e9 = 1000000000`), **pasti tidak bentrok** dengan bobot asli.

Contoh:

|`u`|`v`|bobot (`adj[u][v]`)|
|:-:|:-:|:-:|
|1|2|5|
|1|3|INF (= 1e9)|

Artinya:

- Dari 1 ke 2 ada jalan dengan bobot 5.
    
- Dari 1 ke 3 **tidak ada jalan**.
    

Kalau kamu pakai `0` buat tandai "tidak ada jalan", itu berbahaya! Karena kadang-kadang **ada soal** yang memperbolehkan bobot 0.

➡️ **Maka, angka besar seperti `1e9` itu aman.**

### 3.4.2 | Apakah besar angka `1e9` bikin memori penuh?

⚡ **Jawaban: Tidak.**

Karena **type `int` di C++ selalu 4 byte**, **tidak peduli angkanya berapa**.

Misalnya:

|Nilai|Memory|
|:-:|:-:|
|`5`|4 bytes|
|`123`|4 bytes|
|`1e9`|4 bytes|
|`-99999`|4 bytes|

Jadi, **1 angka `int` = 4 byte**.  
**Bukan** "semakin besar angkanya, semakin besar memory" ❌.

### 3.4.3 | Singkatnya

✅ **Kenapa 1e9?**

- Supaya **tidak bentrok** dengan bobot asli.
    
- **Mudah dikenali** di matrix.
    
- Standar dalam banyak lomba programming (CP, ICPC, dsb).
    

✅ **Apakah memory berat karena 1e9?**

- **Tidak.** Memory hanya bergantung pada **jumlah elemen**, bukan nilai besarannya.
    

### 3.4.4 | Analogi Sederhana

Bayangkan kamu punya rak buku:

- Setiap rak muat 1 buku.
    
- Mau isinya buku tipis atau tebal, **raknya tetap 1**.
    

Sama seperti itu:

- Mau isinya `5` atau `1e9`, **slot memory tetap 4 byte**.
    

Kalau mau lebih ekstrem, sebenarnya banyak orang pakai bahkan:

- `1e8`
    
- `2e9`
    
- atau `INT_MAX/2`
    

Yang penting, **lebih besar dari bobot apapun yang mungkin terjadi** di graph soalmu.

## 3.5 |📚 TABEL PILIHAN INF UNTUK MATRIX GRAPH

|Kebutuhan|Nilai INF yang Cocok|Keterangan|
|:--|:--|:--|
|Bobot maksimum di soal kecil (≤ 10⁶)|`1e9`|Standar biasa, cukup aman|
|Bobot maksimum bisa sampai mendekati 10⁹|`2e9` atau `2e9+5`|Agar lebih aman, karena takut ada bobot besar|
|Ingin super aman (jarang banget dipakai kecuali extreme case)|`INT_MAX/2` (sekitar 1e9)|Untuk mencegah overflow saat penjumlahan|
|Khusus untuk algoritma seperti Dijkstra / Bellman-Ford|`1e9`, `2e9`, atau `LLONG_MAX/2` (jika pakai `long long`)|Bergantung tipe data: `int` atau `long long`|
|Graph tidak berbobot (unweighted)|Tidak perlu INF, bisa pakai 0/1 saja|Misal adjacency matrix berisi 0 (tidak ada) atau 1 (ada edge)|

---

## 3.6 | Catatan Tambahan:

- **Kenapa INT_MAX/2?**  
    Karena di algoritma graph seperti Dijkstra atau Floyd-Warshall, kadang kita butuh melakukan `dist[u] + dist[v]`.  
    Kalau kamu pakai `INT_MAX`, nanti bisa terjadi overflow.
    
    Jadi pakai setengahnya (`INT_MAX/2`) supaya masih aman ketika dijumlah.
    
- **Tipe Data:**
    
    - Kalau pakai `int`, batas maksimal sekitar `2e9`.
        
    - Kalau pakai `long long int`, batas maksimal bisa sampai `9e18`, baru pakai `LLONG_MAX/2`.
        

### 3.6.1 | Tips Praktis Buatmu:

|Kasus|Pakai Ini|
|:--|:--|
|Soal normal / CP biasa|`const int INF = 1e9;`|
|Soal berat, bobot bisa besar|`const int INF = 2e9;`|
|Pakai `long long` semua|`const long long INF = 1e18;`|

### 3.6.2 | Contoh Langsung

```cpp
const int INF = 1e9; // untuk graph normal

vector<vector<int>> adj(n+1, vector<int>(n+1, INF));

// lalu isi matrix seperti biasa
adj[u][v] = w;
```

Kalau lebih ekstrem:

```cpp
const int INF = 2e9; // lebih aman untuk bobot besar
```

### 3.6.3 | Kesimpulan Super Pendek

- **INF itu cuma angka besar** buat tanda "tidak ada edge".
    
- **1e9** sudah lebih dari cukup di 95% soal CP biasa.
    
- **Memory tidak berat** karena semua angka `int` tetap pakai 4 byte.
    
