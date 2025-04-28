---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 11TH-BGRP-AL06
nama_algoritma: Adjacency list Graph basic
kategori_algoritma: Graph Algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen & chatgpt.com"
date_learned: 2025-04-28T19:12:00
tags:
  - graph
  - graph-adjacency-list
---
#graph #graph-adjacency-list 

---
# ✏️ Soal 1: Undirected Graph (Tanpa Bobot)

**Judul: "Teman Sekelas"**

Di sebuah kelas ada **N siswa**.  
Beberapa siswa berteman satu sama lain.  
Pertemanan itu **dua arah** (kalau A berteman dengan B, maka B juga berteman dengan A).

**Tugasmu:**

- Buat program untuk membaca hubungan ini menggunakan **undirected adjacency list**.
    
- Cetak semua teman dari setiap siswa.
    

---

### 📥 Format Input:

- Baris pertama: dua bilangan bulat **N** dan **M** (jumlah siswa dan jumlah pertemanan).
    
- M baris berikutnya: dua bilangan bulat **u v** (artinya siswa `u` dan siswa `v` berteman).
    

### 📤 Format Output:

- Untuk setiap siswa dari 1 sampai N:
    
    ```
    Siswa X:
    - Berteman dengan Y
    - Berteman dengan Z
    ```
    

---

### Contoh Input:

```
5 4
1 2
1 3
2 4
3 5
```

### Contoh Output:

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

---

**Catatan:**  
Karena **undirected**, hubungan dicatat ke **dua arah**:

```cpp
adj[u].push_back(v);
adj[v].push_back(u);
```

---
## Jawaban
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
# ✏️ Soal 2: Undirected Weighted Graph

**Judul: "Jembatan Kota"**

Ada **N kota** yang dihubungkan oleh **M jembatan**.  
Setiap jembatan memiliki **panjang tertentu**.  
Semua jembatan dapat dilalui **dua arah**.

**Tugasmu:**

- Buat program untuk membaca data ini sebagai **undirected weighted adjacency list**.
    
- Cetak semua koneksi jembatan dari setiap kota, beserta panjangnya.
    

---

### 📥 Format Input:

- Baris pertama: dua bilangan bulat **N** dan **M** (jumlah kota dan jumlah jembatan).
    
- M baris berikutnya: tiga bilangan bulat **u v w** (artinya ada jembatan dari kota `u` ke kota `v` dengan panjang `w`).
    

### 📤 Format Output:

- Untuk setiap kota dari 1 sampai N:
    
    ```
    Kota X:
    - Ke Kota Y dengan panjang Z
    - Ke Kota A dengan panjang B
    ```
    

---

### Contoh Input:

```
4 3
1 2 5
2 3 7
3 4 4
```

### Contoh Output:

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

---

**Catatan penting:**  
Karena **undirected weighted**, setiap edge harus disimpan dua kali **(u ke v dan v ke u)** dengan **weight**-nya!

```cpp
adj[u].push_back({v, w});
adj[v].push_back({u, w});
```

---
## Jawaban
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