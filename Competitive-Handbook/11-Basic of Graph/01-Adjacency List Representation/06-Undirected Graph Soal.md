---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 11TH-BGRP-AL06
nama_algoritma: adjacency list
kategori_algoritma: graph algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber:
  - "buku: CP handbook by Antti Laaksonen & chatgpt.com"
date_learned: 2025-04-28T19:12:00
tags:
  - graph-algorithm
  - graph-basic
---
---
# 1 | ✏️ Soal: Undirected Graph (Tanpa Bobot)

## 1.1 | Teman Sekelas

Di sebuah kelas ada **N siswa**.  
Beberapa siswa berteman satu sama lain.  
Pertemanan itu **dua arah** (kalau A berteman dengan B, maka B juga berteman dengan A).

**Tugasmu:**

- Buat program untuk membaca hubungan ini menggunakan **undirected adjacency list**.
    
- Cetak semua teman dari setiap siswa.
    
#### Format Input:

- Baris pertama: dua bilangan bulat **N** dan **M** (jumlah siswa dan jumlah pertemanan).
    
- M baris berikutnya: dua bilangan bulat **u v** (artinya siswa `u` dan siswa `v` berteman).
    
#### Format Output:

- Untuk setiap siswa dari 1 sampai N:
    
    ```
    Siswa X:
    - Berteman dengan Y
    - Berteman dengan Z
    ```
    
#### Contoh
Input:

```
5 4
1 2
1 3
2 4
3 5
```

Output:

```
Siswa 1:
- Berteman dengan 2
- Berteman dengan 3
Siswa 2:
- Berteman dengan 1
- Berteman dengan 4
Siswa 3:
- Berteman dengan 1
- Berteman dengan 5
Siswa 4:
- Berteman dengan 2
Siswa 5:
- Berteman dengan 3
```
**Catatan:**  
Karena **undirected**, hubungan dicatat ke **dua arah**:

```cpp
adj[u].push_back(v);
adj[v].push_back(u);
```


## 1.2 | Jawaban
Jawaban yang sudah cukup efektif:

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
    int n,m;
    cin >> n >> m;

    vector<vector<int>> adj (n+1);

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "\n";
    for(int i=1;i<=n;i++){
        cout << "Siswa " << i << ": \n";
        for(const auto&x:adj[i]){
            cout << "- Berteman dengan " << x << "\n";
        }
        cout << "\n";
    }
    return 0;
}
```

## 1.3 | Editorial Jawaban

### 1.3.1 | Tujuan Program:

Program ini digunakan untuk merepresentasikan dan menampilkan **relasi pertemanan antar siswa**, di mana setiap hubungan bersifat **dua arah (undirected)** dan **tak berbobot (unweighted)**.

### 1.3.2 | Penjelasan Baris per Baris:

```cpp
#include<iostream>
#include<vector>
using namespace std;
```

- **`#include<iostream>`**: Untuk input/output (`cin`, `cout`).
    
- **`#include<vector>`**: Menggunakan struktur data `vector` untuk adjacency list.
    

```cpp
inline void fastio(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}
```

- Fungsi untuk mempercepat proses I/O.
    
    - `ios_base::sync_with_stdio(0)` → Memutus sinkronisasi dengan I/O C.
        
    - `cin.tie(0)` → Mencegah `cin` dari flush otomatis `cout`.
        
    - `cout.tie(0)` → Mempercepat output.
        

```cpp
int n,m;
cin >> n >> m;
```

- Membaca jumlah node (`n`) dan jumlah edge (`m`).
    
- Dalam konteks ini, `n` adalah jumlah **siswa**, `m` adalah jumlah **relasi pertemanan**.

```cpp
vector<vector<int>> adj (n+1);
```

- Inisialisasi adjacency list `adj`, dengan ukuran `n+1` agar indexing bisa dimulai dari `1`.
    
- `adj[i]` menyimpan daftar siswa yang berteman dengan siswa `i`.


```cpp
for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
}
```

- Membaca input edge sebanyak `m`.
    
- Karena **tidak berarah**, relasi ditambahkan dua kali:
    
    - `u → v` dan `v → u`
        
- Jadi, jika siswa 1 berteman dengan siswa 2, maka:
    
    - `adj[1].push_back(2)`
        
    - `adj[2].push_back(1)`

```cpp
for(int i=1;i<=n;i++){
    cout << "Siswa " << i << ": \n";
    for(const auto&x:adj[i]){
        cout << "- Berteman dengan " << x << "\n";
    }
    cout << "\n";
}
```

- Loop dari `1` hingga `n` untuk mencetak semua teman dari masing-masing siswa.
    
- Untuk setiap siswa `i`, kita menampilkan daftar siswa yang berteman dengannya.
    
- Menggunakan `for(const auto& x : adj[i])` untuk membaca setiap tetangga siswa `i`.
    
### 1.3.3 |  Contoh
Input:

```
4 3
1 2
2 3
4 1
```

Output:

```
Siswa 1: 
- Berteman dengan 2
- Berteman dengan 4

Siswa 2: 
- Berteman dengan 1
- Berteman dengan 3

Siswa 3: 
- Berteman dengan 2

Siswa 4: 
- Berteman dengan 1
```

### 1.3.4 | Kesimpulan:

- Representasi `vector<vector<int>>` cocok untuk **graf tak berbobot**.
    
- Sangat efisien untuk menyimpan relasi dalam graf sparse (sedikit edge).
    
- Cocok digunakan pada graf undirected seperti jaringan sosial, peta jalan dua arah, dll.
    

---
# 2 | ✏️ Soal: Undirected Weighted Graph (Berbobot)

## 2.1 | Jembatan Kota

Ada **N kota** yang dihubungkan oleh **M jembatan**.  Setiap jembatan memiliki **panjang tertentu**.  Semua jembatan dapat dilalui **dua arah**.

**Tugasmu:**

- Buat program untuk membaca data ini sebagai **undirected weighted adjacency list**.
    
- Cetak semua koneksi jembatan dari setiap kota, beserta panjangnya.
    
#### Format Input:

- Baris pertama: dua bilangan bulat **N** dan **M** (jumlah kota dan jumlah jembatan).
    
- M baris berikutnya: tiga bilangan bulat **u v w** (artinya ada jembatan dari kota `u` ke kota `v` dengan panjang `w`).
    

#### Format Output:

- Untuk setiap kota dari 1 sampai N:
    
    ```
    Kota X:
    - Ke Kota Y dengan panjang Z
    - Ke Kota A dengan panjang B
    ```

### Contoh

Input:

```
4 3
1 2 5
2 3 7
3 4 4
```

Output:

```
Kota 1:
- Ke Kota 2 dengan panjang 5
Kota 2:
- Ke Kota 1 dengan panjang 5
- Ke Kota 3 dengan panjang 7
Kota 3:
- Ke Kota 2 dengan panjang 7
- Ke Kota 4 dengan panjang 4
Kota 4:
- Ke Kota 3 dengan panjang 4
```

**Catatan penting:**  
Karena **undirected weighted**, setiap edge harus disimpan dua kali **(u ke v dan v ke u)** dengan **weight**-nya!

```cpp
adj[u].push_back({v, w});
adj[v].push_back({u, w});
```

## 2.2 | Jawaban
Jawaban yang sudah cukup efektif:

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

    int n,m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n+1);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    cout << "\n";

    for(int i=1;i<=n;i++){
        cout << "Kota ke " << i << ":\n";
        for(const auto&x:adj[i]){
            cout << "- Ke Kota " << x.first << " dengan jarak " << x.second << "\n";
        }
        cout << "\n";
    }
    return 0;
}
```

## 2.3 | Editorial Jawaban

### 2.3.1 | Tujuan Program:

Program ini digunakan untuk merepresentasikan dan menampilkan **jaringan jalan antar kota** yang bersifat **dua arah (undirected)** dan memiliki **jarak tertentu (weighted)**.

### 2.3.2 | Penjelasan Baris per Baris:

```cpp
#include<iostream>
#include<vector>
using namespace std;
```

- `#include<iostream>` → Untuk operasi input/output (`cin`, `cout`).
    
- `#include<vector>` → Menggunakan `vector` untuk membuat adjacency list.

```cpp
inline void fastio(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}
```

- Fungsi untuk mempercepat proses I/O:
    
    - `ios_base::sync_with_stdio(0)` → Memutus sinkronisasi antara `cin/cout` dan `scanf/printf`.
        
    - `cin.tie(0)` → Mencegah `cin` dari flush otomatis ke `cout`.
        
    - `cout.tie(0)` → Menghindari delay pada output.

```cpp
int n,m;
cin >> n >> m;
```

- Membaca:
    
    - `n` = jumlah simpul (kota).
        
    - `m` = jumlah sisi (jalan dua arah dengan bobot tertentu).
        

```cpp
vector<vector<pair<int,int>>> adj(n+1);
```

- Adjacency list berbobot.
    
- `adj[i]` menyimpan daftar pasangan `(v, w)`:
    
    - `v` = kota tujuan.
        
    - `w` = jarak dari kota `i` ke kota `v`.


```cpp
for(int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;

    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}
```

- Membaca `m` sisi (jalan) berupa tiga nilai:
    
    - `u` = kota asal.
        
    - `v` = kota tujuan.
        
    - `w` = jarak antar kota.
        
- Karena **graf tak berarah**, maka:
    
    - Tambahkan `v → u` dan `u → v`.
        


```cpp
for(int i=1;i<=n;i++){
    cout << "Kota ke " << i << ":\n";
    for(const auto&x:adj[i]){
        cout << "- Ke Kota " << x.first << " dengan jarak " << x.second << "\n";
    }
    cout << "\n";
}
```

- Menampilkan semua tetangga dari setiap kota.
    
- Setiap pasangan `(v, w)` dicetak dalam format:
    
    - `"- Ke Kota v dengan jarak w"`
        


### 2.3.3 | Contoh

Jika input:

```
4 3
1 2 10
2 3 5
1 4 20
```

Maka output:

```
Kota ke 1:
- Ke Kota 2 dengan jarak 10
- Ke Kota 4 dengan jarak 20

Kota ke 2:
- Ke Kota 1 dengan jarak 10
- Ke Kota 3 dengan jarak 5

Kota ke 3:
- Ke Kota 2 dengan jarak 5

Kota ke 4:
- Ke Kota 1 dengan jarak 20
```


### 2.3.4 | Kesimpulan:

- Representasi `vector<vector<pair<int,int>>>` cocok untuk **graf berbobot**.
    
- Setiap simpul menyimpan daftar pasangan `(tujuan, bobot)`.
    
- Cocok digunakan dalam algoritma **Dijkstra**, **Prim**, dan **Kruskal**, serta banyak kasus nyata seperti peta, biaya, waktu, dan jarak.
    
