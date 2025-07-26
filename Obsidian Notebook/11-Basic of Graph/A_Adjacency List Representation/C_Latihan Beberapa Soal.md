---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 11TH-BGRP-AL03
nama_algoritma: Adjacency list Graph basic
kategori_algoritma: Graph Algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen & chatgpt.com"
date_learned: 2025-04-26T22:26:00
tags:
  - graph-algorithm
  - graph-adjacency-list
---
#graph-algorithm #graph-adjacency-list 

---
# 1 | ✏️ Soal Latihan: "Teman Seangkatan"

Di sebuah sekolah, ada **N siswa** yang masing-masing diberi nomor dari **1 sampai N**.  
Sekolah tersebut mencatat **M hubungan pertemanan** antara siswa.

**Tugasmu**:

- Buat program untuk membaca input **N** dan **M**, lalu membaca **M pasang siswa yang berteman**.
- Simpan hubungan ini dalam bentuk **adjacency list**.
- Terakhir, tampilkan daftar teman untuk setiap siswa.
    
---

### 📥 Format Input:

- Baris pertama: dua bilangan bulat **N** dan **M**.
    
- M baris berikutnya: masing-masing berisi dua bilangan bulat **u** dan **v** (artinya siswa `u` berteman dengan siswa `v`).
    

### 📤 Format Output:

- Untuk setiap siswa dari 1 hingga N:
    
    - Cetak "Teman siswa X:" diikuti daftar nomor teman-temannya.
        

---

### Contoh Input:

```
5 4
1 2
1 3
2 4
5 2
```

### Contoh Output:

```
Teman siswa 1: 2 3
Teman siswa 2: 1 4 5
Teman siswa 3: 1
Teman siswa 4: 2
Teman siswa 5: 2
```

---

> **Catatan:** Ini graph **tidak berarah** / *undirected* (pertemanan saling dua arah).

## Jawaban

Dengan menggunakan representasi graph adjacency list, maka berikut jawabanya:

```cpp
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // output
    for(int i=1;i<=n;i++){
        cout << "Teman siswa " << i << ": ";
        for(int x:adj[i]){
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
```

---
# 2 | ✏️ Soal Latihan: "Jalur Teman"

Di sebuah sekolah terdapat **N siswa**, dan ada **M hubungan pertemanan** antara beberapa siswa.  

Tugas kamu adalah membuat graph menggunakan **adjacency list** dan menemukan **jumlah jalur** yang menghubungkan dua siswa yang diberikan. **Jalur** yang dimaksud adalah semua kemungkinan rute yang dapat dilalui dari satu siswa ke siswa lainnya melalui hubungan pertemanan.

### 📥 Format Input:

- Baris pertama: dua bilangan bulat **N** dan **M** (jumlah siswa dan jumlah hubungan pertemanan).
    
- M baris berikutnya: dua bilangan bulat **u** dan **v** (artinya siswa `u` berteman dengan siswa `v`).
    
- Baris terakhir: dua bilangan bulat **a** dan **b** (cek apakah ada jalur yang menghubungkan siswa `a` ke siswa `b`).
    

### 📤 Format Output:

- Tampilkan **jumlah jalur** yang menghubungkan siswa **a** ke siswa **b**.
    
- Jalur yang dimaksud adalah **rute sederhana** (rute tanpa mengunjungi satu siswa lebih dari sekali).
    

---

### Contoh Input 1:

```
4 4
1 2
1 3
2 3
3 4
1 4
```

### Contoh Output 1:

```
2
```

### Contoh Input 2:

```
3 2
1 2
2 3
1 3
```

### Contoh Output 2:

```
1
```

### Contoh Input 3:

```
3 1
1 2
2 3
```

### Contoh Output 3:

```
0
```

---

### Catatan:

- Kamu hanya perlu mencari **jalur sederhana**, artinya tidak ada node yang dikunjungi lebih dari sekali.
    
- Untuk soal ini, kamu bisa menggunakan teknik pencarian **DFS** (Depth First Search) untuk menemukan semua jalur yang mungkin antara dua siswa.
    

## Jawaban

Soal ini cukup sulit, maksudku, soal ini bisa diselesaikan dengan menggunakan DFS, dan aku belum tahu apa itu haha.. 😂
### DFS (Depth First Search)

- DFS bekerja dengan cara menjelajahi **sedalam mungkin** di sepanjang setiap cabang sebelum kembali dan mencoba cabang lain.
    
- DFS bisa digunakan untuk **menemukan jalur** antara dua node di graph (misalnya dalam soal ini).
    

#### Cara kerja DFS secara umum:

1. Pilih node awal (misalnya siswa `a`).
    
2. Kunjungi node tersebut, tandai sudah dikunjungi.
    
3. Kunjungi semua tetangga (node yang terhubung) yang belum dikunjungi.
    
4. Lakukan langkah 2 dan 3 secara rekursif untuk setiap node tetangga.
    

---

### Implementasi DFS dalam C++

Untuk soal ini, kamu akan menggunakan DFS untuk mencari **jumlah jalur** antara dua node. Kamu bisa memodifikasi DFS untuk menghitung berapa banyak jalur yang bisa ditemukan dari `a` ke `b`.

Berikut adalah contoh implementasi DFS untuk mencari jalur antara dua node:

```cpp
#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, int target, vector<vector<int>>& adj, vector<bool>& visited, int& pathCount) {
    if (node == target) {
        pathCount++;  // Jika kita mencapai target, hitung jalur
        return;
    }

    visited[node] = true;

    // Jelajahi semua tetangga yang belum dikunjungi
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, target, adj, visited, pathCount);
        }
    }

    visited[node] = false; // Unmark node setelah selesai
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1); // adjacency list
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Jika graf tidak berarah
    }

    int a, b;
    cin >> a >> b;

    vector<bool> visited(n + 1, false);  // Array untuk menandai apakah node sudah dikunjungi
    int pathCount = 0;  // Jumlah jalur yang ditemukan

    dfs(a, b, adj, visited, pathCount);

    cout << pathCount << endl;

    return 0;
}
```

---

### Penjelasan Kode:

1. **DFS Function**:
    
    - Fungsi `dfs` memeriksa node saat ini, dan jika sudah mencapai target (`b`), maka kita **menambah jumlah jalur** (`pathCount`).
        
    - Setelah itu, fungsi ini melanjutkan ke tetangga yang belum dikunjungi.
        
    - Ketika pencarian selesai pada node tertentu, node tersebut **ditandai ulang sebagai belum dikunjungi** (`visited[node] = false`) untuk memungkinkan pencarian jalur lainnya.
        
2. **Main Function**:
    
    - Input graph yang diwakili dengan **adjacency list**.
        
    - Menyediakan array `visited` untuk menandai node yang sudah dikunjungi selama DFS.
        
    - Menyimpan jumlah jalur yang ditemukan dalam variabel `pathCount` dan akhirnya dicetak ke output.
        

---

### Langkah-langkah menggunakan DFS untuk soal ini:

1. Mulai dari node `a`, lakukan DFS untuk mencari jalur ke node `b`.
    
2. Setiap kali kita mencapai node `b`, hitung satu jalur.
    
3. Jangan lupa untuk **backtrack (unmark)** setiap node setelah selesai mengeksplorasi cabang tertentu, agar jalur lain bisa terhitung.

---
# 3 | ✏️ Weighted Graph : "Rute Pengiriman"

Ada **N kota** yang terhubung oleh **M jalan**.  
Setiap jalan memiliki **jarak tertentu** (berat pada edge).

**Tugasmu:**

- Buat program untuk membaca graph ini menggunakan **weighted adjacency list**.
    
- Cetak daftar semua kota yang terhubung dari setiap kota, **bersama dengan jaraknya**.
    

---

### 📥 Format Input:

- Baris pertama: dua bilangan bulat **N** dan **M** (jumlah kota dan jumlah jalan).
    
- M baris berikutnya: tiga bilangan bulat **u v w**, yang artinya ada jalan dari kota `u` ke kota `v` dengan jarak `w`.
    

### 📤 Format Output:

- Untuk setiap kota dari 1 sampai N, cetak semua tetangganya dalam format:
    
    ```
    Kota X:
    - Kota Y dengan jarak Z
    - Kota A dengan jarak B
    ```
    
- Urutan kota tetangga boleh bebas.
    

---

### Contoh Input:

```
4 5
1 2 7
1 3 9
2 3 10
2 4 15
3 4 11
```

### Contoh Output:

```
Kota 1:
- Kota 2 dengan jarak 7
- Kota 3 dengan jarak 9
Kota 2:
- Kota 1 dengan jarak 7
- Kota 3 dengan jarak 10
- Kota 4 dengan jarak 15
Kota 3:
- Kota 1 dengan jarak 9
- Kota 2 dengan jarak 10
- Kota 4 dengan jarak 11
Kota 4:
- Kota 2 dengan jarak 15
- Kota 3 dengan jarak 11
```

---

### Catatan:

- Karena ini **graph tidak berarah**, kamu harus menyimpan edge dua arah (`u` ke `v` dan `v` ke `u`).
    
- Gunakan **pair** di adjacency list (`vector<vector<pair<int, int>>> adj`) supaya kamu bisa menyimpan `(node, weight)`.
    
## Jawaban

Berikut jawaban dari latihan weighted graph:

```cpp
#include<iostream>
#include<vector>
using namespace std;

inline void fastio(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main(){
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
        cout << "Kota " << i <<":\n";
        for(auto x:adj[i]){
            cout << "- kota " << x.first << " dengan jarak " << x.second << "\n";
        }
        cout << "\n";
    }

    return 0;
}
```