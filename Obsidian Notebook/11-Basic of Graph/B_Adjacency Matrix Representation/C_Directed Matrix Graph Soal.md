---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 11TH-BGRP-MR03
nama_algoritma: Matrix Representation Graph
kategori_algoritma: Graph Algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen & chatgpt.com"
date_learned: 2025-04-28T21:25:00
tags:
  - graph
  - graph-matrix
---
#graph #graph-matrix 

---
# Soal 1 | Directed Graph (Tanpa Bobot)

**Deskripsi:** Diberikan sebuah directed graph, tampilkan adjacency matrix-nya.

**Input:**

- Baris pertama: dua integer `n` dan `m`, di mana `n` adalah jumlah node, dan `m` adalah jumlah edges.
    
- Baris berikutnya: `m` pasangan integer `u v` yang menunjukkan bahwa ada edge dari node `u` ke node `v`.
    

**Output:**

- Matriks adjacency berukuran `n x n`, di mana elemen matriks pada posisi `[i][j]` bernilai `1` jika ada edge dari node `i` ke node `j`, dan `0` jika tidak ada.
    

**Contoh Input 1:**

```
3 3
1 2
2 3
3 1
```

**Contoh Output 1:**

```
0 1 0
0 0 1
1 0 0
```

**Penjelasan:**

- Ada 3 node.
    
- Node 1 memiliki edge menuju node 2.
    
- Node 2 memiliki edge menuju node 3.
    
- Node 3 memiliki edge menuju node 1. Sehingga matriks adjacency akan tampak seperti di atas.
    
## Jawaban
Implementasi dengan C++:

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

## Editorial

### 1. Header dan Fungsi Fast I/O

```cpp
#include<iostream>
#include<vector>
using namespace std;
```

- `#include<iostream>`: Menyertakan library yang memungkinkan kita menggunakan input dan output standar (seperti `cin` dan `cout`).
    
- `#include<vector>`: Menyertakan library yang memungkinkan penggunaan tipe data `vector`, yang berguna untuk menyimpan data secara dinamis.
    
- `using namespace std;`: Ini memungkinkan kamu menggunakan fungsi dan objek standar di C++ tanpa harus menyebutkan `std::` setiap kali, misalnya `cout` bukan `std::cout`.
    

**Fungsi Fast I/O:**

```cpp
inline void fastio(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}
```

- `inline void fastio()`: Fungsi ini bertujuan untuk mengoptimalkan I/O (input-output). `inline` memastikan fungsi ini dioptimalkan oleh compiler.
    
- `ios_base::sync_with_stdio(0)`: Memastikan input dan output C++ tidak disinkronkan dengan C-style I/O (misalnya `scanf`, `printf`), yang bisa mempercepat I/O.
    
- `cin.tie(0)`: Membebaskan aliran `cin` (input stream) dari `cout` (output stream). Secara default, `cin` dan `cout` saling terikat, yang berarti `cin` akan menunggu sampai `cout` selesai menulis sebelum melanjutkan input. Dengan `cin.tie(0)`, proses input bisa lebih cepat.
    
- `cout.tie(0)`: Membebaskan `cout` dari output lainnya.
    

---

### 2. Deklarasi Variabel dan Input

```cpp
int n, m;
cin >> n >> m;
```

- `int n, m;`: Mendeklarasikan dua variabel bertipe integer, `n` untuk jumlah node (kota) dan `m` untuk jumlah edges (hubungan antara kota).
    
- `cin >> n >> m;`: Menerima input dua bilangan berturut-turut untuk `n` (jumlah kota) dan `m` (jumlah jembatan) dari pengguna.
    

---

### 3. Matriks Adjacency

```cpp
vector<vector<int>> adj (n+1, vector<int>(n+1, 0));
```

- `vector<vector<int>> adj`: Mendeklarasikan sebuah **vector of vectors**, yang digunakan untuk menyimpan adjacency matrix (matriks ketetanggaan).
    
- `n+1`: Ukuran matriks adalah `n+1` untuk menyesuaikan dengan indeks yang dimulai dari 1, bukan 0.
    
- `vector<int>(n+1, 0)`: Setiap baris dari matriks diinisialisasi sebagai `vector<int>` dengan panjang `n+1`, dan setiap elemen diinisialisasi dengan nilai 0. Ini berarti bahwa belum ada edge yang terhubung.
    

---

### 4. Memasukkan Data Edges

```cpp
for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    adj[u][v] = 1;
}
```

- `for(int i = 0; i < m; i++)`: Menggunakan loop untuk membaca semua pasangan edge yang diberikan oleh input (jumlahnya `m`).
    
- `int u, v;`: Mendeklarasikan dua variabel integer, `u` dan `v`, yang akan menampung pasangan node yang terhubung.
    
- `cin >> u >> v;`: Membaca pasangan node `u` dan `v` yang terhubung oleh edge. Pada input ini, kita menerima dua angka yang merepresentasikan sebuah edge dari node `u` ke node `v`.
    
- `adj[u][v] = 1;`: Menandakan bahwa ada edge dari node `u` ke node `v`. Dalam matriks adjacency, kita set elemen `[u][v]` menjadi `1`.
    

---

### 5. Menampilkan Matriks Adjacency

```cpp
cout << "\n";
for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
        cout << adj[i][j] << " ";
    }
    cout << "\n";
}
```

- `cout << "\n";`: Menambahkan baris kosong sebelum mencetak matriks.
    
- `for(int i = 1; i <= n; i++)`: Loop pertama yang mengiterasi baris-baris dalam matriks, di mana setiap baris mewakili node `i`.
    
- `for(int j = 1; j <= n; j++)`: Loop kedua yang mengiterasi kolom-kolom dalam matriks, di mana setiap kolom mewakili node `j`.
    
- `cout << adj[i][j] << " ";`: Mencetak nilai pada posisi `[i][j]` dalam matriks adjacency (apakah ada edge antara node `i` dan `j` atau tidak).
    
- `cout << "\n";`: Setelah mencetak semua elemen dalam satu baris, pindah ke baris berikutnya.
    

---

### 6. Return 0

```cpp
return 0;
```

- `return 0;`: Menandakan bahwa program telah selesai dengan sukses. Ini adalah konvensi dalam C++ untuk menunjukkan bahwa program selesai tanpa error.
    

---

### Contoh Input dan Output:

**Input:**

```
3 3
1 2
2 3
3 1
```

**Output:**

```
0 1 0 
0 0 1 
1 0 0 
```

**Penjelasan Output:**

- Matriks di atas menunjukkan bahwa:
    
    - Ada edge dari node 1 ke node 2 (`adj[1][2] = 1`).
        
    - Ada edge dari node 2 ke node 3 (`adj[2][3] = 1`).
        
    - Ada edge dari node 3 ke node 1 (`adj[3][1] = 1`).
        
- Jika tidak ada edge antara dua node, maka nilai di dalam matriks adalah `0`.
    

---

### Ringkasan:

- Kamu telah berhasil membuat sebuah program yang menggunakan **adjacency matrix** untuk merepresentasikan graph **terarah tanpa bobot**.
    
- Adjacency matrix adalah cara yang sederhana dan efisien (untuk graph kecil) untuk menyimpan graph, di mana setiap elemen matriks mewakili apakah ada edge antara dua node.
    
- Program ini dapat dengan mudah diubah untuk graph yang lebih kompleks, seperti yang berbobot, dengan sedikit modifikasi.
    


---

# Soal 2 | Directed Graph (Dengan Bobot)

**Deskripsi:** Diberikan sebuah directed graph berbobot, tampilkan weighted adjacency matrix-nya.

**Input:**

- Baris pertama: dua integer `n` dan `m`, di mana `n` adalah jumlah node, dan `m` adalah jumlah edges.
    
- Baris berikutnya: `m` triplet integer `u v w`, di mana `u` dan `v` adalah node yang terhubung, dan `w` adalah bobot dari edge tersebut.
    

**Output:**

- Matriks adjacency berukuran `n x n`, di mana elemen matriks pada posisi `[i][j]` bernilai `w` jika ada edge dari node `i` ke node `j`, dan `0` jika tidak ada.
    

**Contoh Input 2:**

```
3 3
1 2 5
2 3 3
3 1 2
```

**Contoh Output 2:**

```
0 5 0
0 0 3
2 0 0
```

**Penjelasan:**

- Ada 3 node.
    
- Node 1 memiliki edge menuju node 2 dengan bobot 5.
    
- Node 2 memiliki edge menuju node 3 dengan bobot 3.
    
- Node 3 memiliki edge menuju node 1 dengan bobot 2. Sehingga matriks adjacency berbobot akan tampak seperti di atas.
    

## Jawaban
Berikut adalah implementasi yang cukup efisien dan solid untuk C++:

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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1, vector<int>(n+1, INF));

    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u][v]=w;
    }

    cout << "\n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<= n; j++){
            if(adj[i][j] == INF) cout << "INF ";
            else cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
```

## Editorial


### 1. Deklarasi Matriks Adjacency dengan INF:

```cpp
vector<vector<int>> adj(n+1, vector<int>(n+1, INF)); // matrix nxn isi INF
```

- `vector<vector<int>> adj(n+1, vector<int>(n+1, INF));`: Matriks `adj` diinisialisasi dengan ukuran `n+1` x `n+1`. Hal ini mengakomodasi indeks yang mulai dari 1 (bukan 0).
    
- `INF`: Digunakan untuk menandai bahwa tidak ada edge antara dua node, yang diatur dengan nilai yang sangat besar (misalnya `1e9`).
    
- **Perhatian**: Matriks ini **diisi dengan nilai `INF`** yang menunjukkan bahwa node `i` dan node `j` tidak terhubung. Jika ada edge, kita akan mengganti nilai tersebut dengan bobot edge yang sesuai.
    

### 2. Menandai Diri Sendiri dengan Jarak 0:

```cpp
for (int i = 1; i <= n; i++) adj[i][i] = 0; // jarak ke diri sendiri 0
```

- Pada langkah ini, kamu memastikan bahwa jarak dari node ke dirinya sendiri adalah 0, yang masuk akal dalam konteks graph. Ini diperlukan untuk memastikan bahwa saat kita memproses graf, kita tahu bahwa tidak ada biaya untuk "menyambung" ke diri sendiri.
    

### 3. Membaca Input Edges:

```cpp
for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u][v] = w; // hanya satu arah
}
```

- Kamu membaca input `m` yang berisi informasi tentang berapa banyak edge yang ada di graf. Untuk setiap edge, kamu mengambil tiga angka: `u`, `v`, dan `w` yang menunjukkan bahwa ada edge dari node `u` ke node `v` dengan bobot `w`.
    
- Nilai `adj[u][v] = w;` mengubah nilai dalam matriks menjadi bobot `w` untuk edge yang diberikan.
    
- Ini hanya satu arah karena kamu tidak mengubah `adj[v][u]`. Jadi, ini adalah representasi graph **terarah**.
    

### 4. Menampilkan Matriks Adjacency:

```cpp
cout << "\nAdjacency Matrix:\n";
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        if (adj[i][j] == INF) cout << "INF ";
        else cout << adj[i][j] << " ";
    }
    cout << "\n";
}
```

- Kamu mencetak matriks adjacency di sini.
    
- Jika nilai dalam matriks adalah `INF`, berarti tidak ada edge antara dua node, jadi kamu mencetak "INF".
    
- Jika ada edge, kamu mencetak bobot edge tersebut.
    
- Pada akhir setiap baris, kamu mencetak newline untuk memulai baris baru, yang menandakan bahwa kamu sedang mencetak baris baru dalam matriks.
    

---

### Contoh Input dan Output:

**Input:**

```
4 5
1 2 5
1 3 3
2 4 2
3 4 1
4 1 6
```

**Output:**

```
Adjacency Matrix:
INF 5 3 INF INF 
INF INF INF 2 INF 
INF INF INF 1 INF 
6 INF INF INF INF 
```

### Penjelasan Output:

- Baris pertama menunjukkan bahwa dari node 1:
    
    - Ada edge dari node 1 ke node 2 dengan bobot 5.
        
    - Ada edge dari node 1 ke node 3 dengan bobot 3.
        
    - Tidak ada edge dari node 1 ke node 4 (jadi INF).
        
- Baris kedua menunjukkan bahwa dari node 2:
    
    - Ada edge dari node 2 ke node 4 dengan bobot 2.
        
    - Tidak ada edge lainnya dari node 2 ke node lainnya.
        
- Baris ketiga menunjukkan bahwa dari node 3:
    
    - Ada edge dari node 3 ke node 4 dengan bobot 1.
        
    - Tidak ada edge lainnya dari node 3 ke node lainnya.
        
- Baris keempat menunjukkan bahwa dari node 4:
    
    - Ada edge dari node 4 ke node 1 dengan bobot 6.
        
    - Tidak ada edge lainnya dari node 4 ke node lainnya.
        

---

### Kesimpulan:

Secara keseluruhan, kode yang kamu berikan **benar** dan tidak ada kesalahan. Kamu menggunakan **matrix representation** yang sangat tepat dengan menandai edges yang tidak ada dengan `INF` dan memastikan jarak dari node ke dirinya sendiri adalah `0`. Kamu juga mengatur adjacency matrix untuk graph terarah yang berbobot dengan baik.

# Informasi Tambahan
## Kenapa menggunakan INF?
Penggunaan nilai `INF` dalam representasi matriks adjacency adalah teknik yang umum digunakan dalam graph untuk menandakan **ketidakterhubungan** antara dua node. INF (infinity) adalah nilai yang sangat besar yang digunakan untuk menyatakan bahwa **tidak ada edge** yang menghubungkan dua node.

Berikut adalah beberapa alasan mengapa menggunakan `INF` itu penting:

### 1. Menandakan Tidak Ada Edge (Ketidakterhubungan):

Dalam graph, tidak setiap node akan terhubung ke node lainnya. Dengan menggunakan `INF`, kita bisa menyatakan bahwa antara node `i` dan node `j` tidak ada edge yang menghubungkannya. Jika kita menggunakan nilai selain `INF`, seperti `0` atau nilai lainnya, kita bisa membingungkan sistem karena `0` mungkin saja dianggap sebagai **berartinya tidak ada bobot** atau **terhubung dengan diri sendiri**.

### 2. Memudahkan Implementasi Algoritma Pathfinding:

Jika kita menggunakan algoritma seperti **Floyd-Warshall** atau **Dijkstra** untuk mencari jarak terpendek, nilai `INF` memungkinkan kita untuk membedakan dengan jelas antara node yang tidak terhubung dan node yang terhubung tetapi memiliki jarak tertentu. Dalam algoritma tersebut, kita biasanya mulai dengan jarak antara node-node yang tidak terhubung sebagai `INF` karena tidak ada jalur yang menghubungkan mereka.

### 3. Konsistensi dalam Matriks:

Ketika kita bekerja dengan matriks adjacency, kita sering kali bekerja dengan **nilai tetap**. Jika kita menggunakan `INF`, kita memberi tahu bahwa **secara default, semua node yang tidak terhubung dengan edge diberi nilai yang sangat besar**. Ini menjaga konsistensi struktur data matriks dan memudahkan perhitungan lebih lanjut.

### 4. Fleksibilitas dalam Pembandingan:

Menggunakan nilai `INF` memberi kita fleksibilitas yang lebih besar saat memanipulasi data. Contohnya, jika kita ingin memeriksa apakah ada edge antara dua node, kita cukup memeriksa apakah nilai dalam matriks adalah `INF`. Dengan demikian, kita bisa dengan mudah membedakan antara dua kondisi:

- Ada edge: nilai dalam matriks adalah bobot edge.
    
- Tidak ada edge: nilai dalam matriks adalah `INF`.
    

---

### Contoh Perbandingan:

#### Tanpa `INF` (misalnya menggunakan `0`):

Jika kita menggunakan `0` untuk menandakan ketidakterhubungan, kita akan kesulitan membedakan antara:

- **Tidak ada edge** (seharusnya tidak ada hubungan).
    
- **Edge dengan bobot 0** (terhubung tetapi dengan bobot nol).
    

#### Dengan `INF`:

Dengan menggunakan `INF`, kita secara eksplisit menunjukkan bahwa **dua node tidak terhubung**. Nilai `INF` sangat jarang digunakan dalam konteks jarak atau bobot edge, jadi ini membantu dalam pembedaan antara jarak yang tidak ada dan jarak yang memang ada.

---

### Kesimpulan:

Penggunaan `INF` sangat bermanfaat dalam representasi matriks adjacency karena:

- Memungkinkan kita untuk membedakan dengan jelas antara node yang terhubung dan yang tidak terhubung.
    
- Memudahkan implementasi algoritma untuk pathfinding, seperti Dijkstra atau Floyd-Warshall.
    
- Memberikan konsistensi dalam cara kita menangani ketidakterhubungan antara node.
    

Jika kamu ingin membuat graph yang lebih sederhana tanpa memperhitungkan **tidak ada edge**, kamu bisa menggunakan pendekatan lain, tetapi `INF` adalah praktik yang sangat umum dan sangat membantu dalam kebanyakan aplikasi graph.
## Lalu apa maksud dari INF=1e9?
`INF = 1e9` adalah cara untuk mendefinisikan **nilai yang sangat besar** sebagai representasi dari "tak terhingga" dalam konteks algoritma graph, khususnya ketika kita menggunakan **matriks adjacency** untuk menunjukkan ketidakterhubungan antara dua node.

### Penjelasan `1e9`:

- `1e9` adalah notasi ilmiah yang artinya **1 x 10^9**, atau **1.000.000.000** (satu milyar).
    
- Dalam konteks ini, kita memilih nilai **1 milyar** karena itu cukup besar untuk mewakili jarak yang sangat jauh antara dua node yang tidak terhubung.
    
- **Kenapa 1 milyar?** Karena dalam banyak kasus algoritma seperti Dijkstra atau Floyd-Warshall, nilai yang lebih besar dari **jumlah node** dalam graph biasanya cukup untuk mewakili "tak terhingga". Dengan cara ini, nilai `INF` akan lebih mudah ditangani dan tidak akan terjadi benturan dengan nilai jarak aktual dalam graph.
    

### Kenapa menggunakan `1e9`?

Nilai `1e9` atau 1 milyar sering digunakan dalam algoritma graph karena:

1. **Tidak Mengganggu Nilai Jarak yang Valid**: Biasanya dalam graph, jarak antar node tidak akan pernah mencapai angka sebesar 1 milyar (atau jauh lebih kecil dari itu). Ini memungkinkan kita menggunakan `1e9` sebagai nilai default untuk menandakan "tidak ada edge".
    
2. **Efisiensi Komputasi**: Menggunakan nilai seperti `1e9` lebih efisien dalam hal memori dan perhitungan dibandingkan dengan menggunakan `INT_MAX` atau angka yang lebih besar yang mungkin mempengaruhi kinerja algoritma, terutama jika kita bekerja dengan graph yang sangat besar.
    

### INF dan Algoritma Graph

- **Dijkstra**: Dalam algoritma Dijkstra, kita menggunakan `INF` untuk menunjukkan bahwa suatu node belum ditemukan jalur terpendeknya. Semuanya diinisialisasi dengan nilai `INF`, dan seiring berjalannya algoritma, nilai-nilai tersebut diperbarui dengan jarak yang lebih pendek.
    
- **Floyd-Warshall**: Dalam algoritma ini, kita menggunakan `INF` untuk menunjukkan bahwa tidak ada jalur langsung antara dua node, dan kita mencoba untuk mencari jalur terpendek di antara setiap pasangan node.
    

### Contoh:

Misalnya, jika kita memiliki graph dengan 4 node, dan kita tidak memiliki edge antara node 1 dan node 2, kita akan menetapkan nilai `INF` untuk matriks adjacency di posisi `[1][2]` dan `[2][1]`. Dalam hal ini, `INF` adalah 1 milyar (`1e9`), yang berarti bahwa tidak ada jalur langsung dari node 1 ke node 2.

Berikut contoh visualisasi menggunakan `INF`:

```
     1        1
 1 ------> 2 ------> 3
  |            |
  v            v
  4 <-------- 5
```

Untuk menggambarkan ketidakterhubungan antara node-node yang tidak langsung terhubung, kita menggunakan `INF`:

```
   1    2    3    4    5
1  0   INF  INF  1   INF
2  INF  0    1   INF  3
3  INF  1    0   INF  INF
4  1   INF  INF  0   INF
5  INF  3    INF  INF  0
```

- Di sini, `INF` menunjukkan bahwa tidak ada edge langsung antara node tersebut.
    
- Misalnya, tidak ada edge antara node 1 dan node 2, jadi `adj[1][2]` dan `adj[2][1]` berisi `INF`.
    

Dengan cara ini, kita bisa memanfaatkan nilai `INF` sebagai indikasi tidak adanya hubungan, yang sangat berguna untuk perhitungan dalam berbagai algoritma pencarian jalur dan pengolahan graph.