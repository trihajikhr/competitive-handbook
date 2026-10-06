---
obsidianUIMode: preview
note_type: latihan
latihan: Terhubung atau Tidak
sumber: myself
tags:
  - graph-algorithm
date_learned: 2025-07-05T17:16:00
---
---
# Terhubung atau Tidak

Tentukan apakah graf yang diberikan adalah graf terhubung, atau semua node bisa dijangkau dari node 1! Graph yang diberikan adalah graph undirected, dan unweighted.

### Input output

Keterangan: diberikan inputan `n` dan `m`. 

`n` adalah jumlah node, dan `m` adalah jumlah edge, diikuti `m` inputan yang merepresentasikan hubungan antar dua node! 

Contoh Inputan:

```
6 4
1 2
2 3
4 5
5 6
```

output:

```
Graf tidak terhubung
```

Jawabanya adalah tidak terhubung karena node 4,5, dan 6 tidak terhubung dengan node 1,2, dan 3. 

# Jawabanku
Berikut adalah jawabanku yang sudah cukup optimal:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

inline void fastio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void dfsRec(vector<vector<int>>&adj, vector<bool>&visited, int s){
    visited[s]=true;

    for(auto&x:adj[s]){
        if(!visited[x]){
            dfsRec(adj, visited, x);
        }
    }
}

void DFS(vector<vector<int>>& adj, int start) {
    vector<bool> visited(adj.size(), false);
    dfsRec(adj, visited, start);

    bool connected = true;
    for (bool v : visited) {
        if (!v) connected = false;
    }

    if (connected) cout << "Graf terhubung\n";
    else cout << "Graf TIDAK terhubung\n";
}

void addEdge(vector<vector<int>>&adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    fastio();
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n); 

    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--; 

        if ((u >= 0 && u < n) && (v >= 0 && v < n)) {
            addEdge(adj, u, v);
        } else {
            cerr << "Simpul di luar batas: " << u+1 << " " << v+1 << "\n";
        }
    }

    for(auto& x : adj) sort(x.begin(), x.end());
    DFS(adj, 0);
    return 0;
}

```

# Editorial Pertama
Jawabanmu sudah sangat tepat untuk menentukan apakah graf tak berarah dan tidak berbobot tersebut terhubung atau tidak. 🎉

Berikut poin-poin evaluasinya:

### ✅ Yang SUDAH BENAR

1. **Input & Inisialisasi**
    
    - `adj(n)` membentuk graf berukuran `n`, dengan indeks 0 s/d `n-1`.
        
    - Kamu sudah menangani input 1-based dengan `u--, v--`.
        
2. **Validasi Input**
    
    - Kamu memeriksa apakah `u` dan `v` berada dalam rentang indeks yang valid, sehingga menghindari error out-of-bounds.
        
    - 👍 Ini penting agar input yang salah tidak bikin program crash.
        
3. **DFS Traversal**
    
    - Fungsi `dfsRec()` rekursif kamu sudah benar dan efisien.
        
    - Fungsi `DFS()` hanya memanggil sekali `dfsRec()` dari simpul `start` (0), lalu mengecek apakah semua simpul sudah dikunjungi.
        
4. **Penentuan Graf Terhubung**
    
    - Pengecekan `visited[]` sudah tepat untuk menilai keterhubungan graf.
        
5. **I/O Efisien**
    
    - Kamu sudah memakai `fastio()` — ini membantu input/output besar.
        

### ✨ Saran Peningkatan Kecil

#### 1. Bisa langsung return hasil keterhubungan (opsional)

Jika kamu ingin fungsi `DFS()` lebih fleksibel, kamu bisa buat dia return `bool`:

```cpp
bool DFS(vector<vector<int>>& adj, int start) {
    vector<bool> visited(adj.size(), false);
    dfsRec(adj, visited, start);

    return all_of(visited.begin(), visited.end(), [](bool v){ return v; });
}
```

Di `main()`:

```cpp
if (DFS(adj, 0)) cout << "Graf terhubung\n";
else cout << "Graf TIDAK terhubung\n";
```

#### 2. Tampilkan info jumlah simpul terkunjungi (jika mau)

```cpp
int count = 0;
for (bool v : visited) if (v) count++;
cout << "Jumlah simpul terkunjungi: " << count << " dari total " << n << "\n";
```

---
<br/><br/>

# Editorial Kedua
Tentu! Berikut ini adalah **editorial berupa penjelasan per blok kode** dari programmu, yang berguna untuk menjelaskan **fungsi setiap bagian kode** dengan rapi dan mudah dimengerti. Gaya penulisan ini cocok untuk dimasukkan ke laporan atau untuk bahan belajar pribadi.


## 🧾 Editorial Program: Pemeriksaan Graf Terhubung dengan DFS

### 🔹 1. Header dan Namespace

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
```

👉 Baris ini mengimpor pustaka penting:

- `iostream` untuk input-output (`cin`, `cout`)
    
- `vector` untuk struktur data `vector` yang dipakai untuk adjacency list
    
- `algorithm` untuk fungsi `sort()`
    

### 🔹 2. Fungsi Percepat Input/Output

```cpp
inline void fastio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
```

👉 Fungsi ini digunakan untuk mempercepat proses input dan output dengan mematikan sinkronisasi antara C-style dan C++-style I/O. Sangat membantu jika data besar.

### 🔹 3. Fungsi DFS Rekursif

```cpp
void dfsRec(vector<vector<int>>&adj, vector<bool>&visited, int s){
    visited[s]=true;

    for(auto&x:adj[s]){
        if(!visited[x]){
            dfsRec(adj, visited, x);
        }
    }
}
```

👉 Ini adalah fungsi rekursif utama untuk menelusuri graf:

- Menandai simpul `s` sebagai telah dikunjungi.
    
- Menelusuri setiap simpul tetangga dari `s` yang belum dikunjungi.
    
- Ini disebut **Depth-First Search (DFS)**.


### 🔹 4. Fungsi DFS Utama dan Pemeriksaan Keterhubungan

```cpp
void DFS(vector<vector<int>>& adj, int start) {
    vector<bool> visited(adj.size(), false);
    dfsRec(adj, visited, start);

    bool connected = true;
    for (bool v : visited) {
        if (!v) connected = false;
    }

    if (connected) cout << "Graf terhubung\n";
    else cout << "Graf TIDAK terhubung\n";
}
```

👉 Fungsi ini:

- Membuat vektor `visited` untuk mencatat simpul yang sudah dikunjungi.
    
- Memanggil DFS dari simpul awal (`start`).
    
- Setelah DFS selesai, dicek apakah semua simpul sudah dikunjungi:
    
    - Jika ya, maka graf **terhubung**.
        
    - Jika tidak, maka ada simpul yang **terisolasi** atau berada di **komponen berbeda**.
        

### 🔹 5. Fungsi Tambah Sisi (Edge)

```cpp
void addEdge(vector<vector<int>>&adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
```

👉 Fungsi ini menambahkan sisi antara simpul `u` dan `v` ke dalam graf. Karena graf tidak berarah, maka `u` dimasukkan ke daftar tetangga `v`, dan sebaliknya.

### 🔹 6. Fungsi `main()` – Fungsi Utama Program

```cpp
int main() {
    fastio();
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n); 
```

👉 Membaca `n` (jumlah simpul) dan `m` (jumlah sisi). Membuat adjacency list `adj` berukuran `n`.

---

```cpp
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--; 

        if ((u >= 0 && u < n) && (v >= 0 && v < n)) {
            addEdge(adj, u, v);
        } else {
            cerr << "Simpul di luar batas: " << u+1 << " " << v+1 << "\n";
        }
    }
```

👉 Membaca pasangan sisi `u` dan `v`. Karena input memakai indeks 1-based, maka dikurangi 1 agar cocok dengan indexing C++ yang 0-based.

👉 Validasi input dilakukan untuk mencegah akses `out-of-bounds`.

---

```cpp
    for(auto& x : adj) sort(x.begin(), x.end());
```

👉 Menyortir daftar tetangga setiap simpul agar traversal DFS teratur. Ini opsional, tapi bermanfaat jika kita ingin hasil traversal dalam urutan tertentu.

---

```cpp
    DFS(adj, 0);
    return 0;
}
```

👉 Memanggil fungsi `DFS()` dari simpul 0 (yaitu simpul pertama setelah dikonversi ke 0-based). Setelah selesai, program akan mencetak apakah graf terhubung atau tidak.

---

## 📌 Kesimpulan

- Program ini menggunakan **DFS** untuk mengecek apakah seluruh simpul bisa dicapai dari satu simpul awal.
    
- Jika semua simpul bisa dikunjungi dari simpul 0, maka graf **terhubung**.
    
- Validasi input menjaga program agar tidak crash akibat data tidak valid.
    
- Representasi menggunakan **adjacency list**, yang efisien untuk graf yang tidak terlalu padat.
    

---

Kalau kamu mau versi editorial ini disederhanakan untuk penjelasan di kelas, atau ditulis ulang dalam gaya bahasa yang lebih kasual atau formal (seperti laporan skripsi), tinggal bilang ya!