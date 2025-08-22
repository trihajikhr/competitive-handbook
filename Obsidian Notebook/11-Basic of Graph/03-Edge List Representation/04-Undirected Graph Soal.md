---
obsidianUIMode: 
note_type: algorithm theory
id_algoritma: 11TH-BGRP-EL04
nama_algoritma: edge list graph representation
kategori_algoritma: graph algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber:
  - "buku: CP handbook by Antti Laaksonen"
  - chatgpt.com
date_learned: 2025-04-29T17:17:00
tags:
  - graph-algorithm
  - graph-basic
---
---
# 1 | Soal 1 Komunitas dan Jumlah Orang 

**Deskripsi:**

Sebuah komunitas terdiri dari sejumlah orang. Setiap orang dalam komunitas bisa saling berhubungan satu sama lain, artinya ada hubungan antara dua orang yang saling berteman. Kamu diminta untuk menyusun daftar teman antara orang-orang tersebut. Programmu harus membaca informasi tentang hubungan pertemanan tersebut dan menampilkannya dalam bentuk daftar pasangan orang yang berteman.

**Input:**

- Baris pertama berisi dua bilangan bulat `n` dan `m`, yang menyatakan jumlah orang dan jumlah hubungan pertemanan.
    
- Baris berikutnya berisi `m` baris, dimana masing-masing baris berisi dua bilangan bulat `u` dan `v` yang menunjukkan bahwa orang `u` berteman dengan orang `v`.
    

**Output:**

- Daftar hubungan pertemanan dalam format "u - v" (tanpa urutan khusus).
    

**Contoh Input:**

```
4 4
1 2
2 3
3 4
4 1
```

**Contoh Output:**

```
1 - 2
2 - 1
2 - 3
3 - 2
3 - 4
4 - 3
4 - 1
1 - 4
```

## 1.1 | Jawaban
Berikut jawaban yang sudah cukup baik, namun masih bisa dioptimalisasi nantinya:

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

    vector<pair<int,int>> edges;

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;

        edges.push_back({u,v});
        edges.push_back({v,u});
    }

    for(const auto&x:edges){
        cout << x.first << " - " << x.second << "\n";
    }
    return 0;
}
```

## 1.2 | Editorial
Jawaban yang kamu buat sudah benar dan cukup jelas. Berikut adalah penjelasan tentang kode yang telah kamu buat:

### 1.2.1 | Penjelasan Kode:

1. **Input dan Setup:**
    
    - `cin >> n >> m;` — Membaca dua input pertama: `n` (jumlah orang, atau kota) dan `m` (jumlah hubungan pertemanan, atau jalan).
        
    - `vector<pair<int,int>> edges;` — Membuat sebuah vektor `edges` yang akan menyimpan pasangan `(u, v)` yang menunjukkan hubungan antara dua orang atau dua kota.
        
2. **Proses Pembacaan Input:**
    
    - Dalam loop pertama (`for(int i=0;i<m;i++)`), kita membaca `m` pasangan `u` dan `v`, yang menunjukkan hubungan pertemanan (untuk soal 1) atau jalan antar kota (untuk soal 2).
        
    - Karena graph ini **undirected**, kita menambahkan dua pasang: satu untuk `u -> v` dan satu lagi untuk `v -> u`. Ini memastikan bahwa hubungan antar orang atau jalan antar kota tercatat dua arah.
        
3. **Mencetak Hasil:**
    
    - Loop kedua (`for(const auto&x:edges)`) digunakan untuk mencetak semua hubungan pertemanan atau jalan. Dalam setiap iterasi, kita mencetak pasangan `(x.first, x.second)` dalam format yang sesuai (misalnya `1 - 2`).
        

### 1.2.2 | Optimasi yang Bisa Dilakukan:

- Pada kode ini, kamu mengulangi dua kali setiap pasangan `(u, v)` (misalnya `1 - 2` dan `2 - 1`). Itu sebenarnya tidak perlu karena soal ini sudah menyebutkan bahwa ini adalah **undirected graph**, yang berarti `1 - 2` dan `2 - 1` seharusnya dianggap sama.
    
- Untuk mencegah duplikasi, kamu bisa mempertimbangkan untuk menyaring pasangan yang sudah pernah dicetak.
    

### 1.2.3 | Perbaikan untuk Menghindari Duplikasi:

Salah satu cara untuk mencegah duplikasi pasangan adalah dengan menyaring pasangan yang sudah pernah tercatat. Bisa menggunakan `set` atau struktur data lain untuk menyaring duplikasi.

## 1.3 | Jawaban 2
Untuk menghindari duplikasi dalam soal nomor 1 (undirected graph), kita bisa menggunakan `set` atau `unordered_set` untuk memastikan bahwa setiap pasangan `(u, v)` hanya dicatat satu kali, meskipun kita memasukkan kedua arah `u -> v` dan `v -> u`. Dengan demikian, kita dapat memastikan bahwa kita hanya menyimpan pasangan yang unik dan mencetaknya satu kali.

Berikut adalah perbaikan menggunakan `set`:

### 1.3.1 | Perbaikan dengan `set`:

```cpp
#include<iostream>
#include<vector>
#include<set>
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

    set<pair<int,int>> edges; // Menggunakan set untuk menyaring duplikasi

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // Menambahkan pasangan (u, v) dan (v, u) agar bisa terbaca dua arah
        if(u != v) {
            edges.insert({min(u, v), max(u, v)}); // Menyaring pasangan yang sama, agar hanya ada satu pasangan
        }
    }

    for(const auto& x : edges) {
        cout << x.first << " - " << x.second << "\n";
    }

    return 0;
}
```

### 1.3.2 | Penjelasan Perbaikan:

1. **Set untuk Menyaring Duplikasi:**
    
    - `set<pair<int, int>> edges;` — `set` secara otomatis menghindari duplikasi. Setiap kali kita menambahkan pasangan `(u, v)` dan `(v, u)`, `set` akan memastikan bahwa pasangan tersebut hanya disimpan sekali.
        
    - Untuk memastikan bahwa pasangan `(u, v)` dan `(v, u)` dianggap sama (untuk undirected graph), kita menggunakan `min(u, v)` dan `max(u, v)`. Ini menjamin bahwa pasangan `(1, 2)` dan `(2, 1)` akan disimpan dalam urutan yang sama yaitu `(1, 2)`.
        
2. **Menghindari Duplikasi dalam Input:**
    
    - Jika `u != v`, kita menyaring pasangan `(u, v)` dan `(v, u)` dengan memasukkan mereka sebagai `(min(u, v), max(u, v))`. Ini akan memastikan bahwa hanya pasangan yang unik yang akan disimpan dalam set.
        
3. **Output:**
    
    - Dalam loop kedua, kita mencetak setiap pasangan yang ada dalam `set`, dan karena `set` menyimpan elemen dalam urutan tertentu, hasilnya akan otomatis terurut.
        

### 1.3.3 | Keuntungan Menggunakan `set`:

- **Tanpa Duplikasi:** `set` secara otomatis menyaring duplikasi.
    
- **Efisiensi Waktu:** Proses memasukkan elemen ke dalam `set` dan mengecek duplikasi memiliki waktu rata-rata `O(log n)`, yang lebih efisien daripada mencatat semua pasangan terlebih dahulu dan kemudian memeriksa duplikasi secara manual.
    
Dengan perbaikan ini, kamu bisa memastikan tidak ada duplikasi pasangan dalam hasil yang dicetak. 

---
# 2 | Soal 2 Permainan dan Kota

**Deskripsi:**

Dalam sebuah permainan, ada banyak kota yang saling terhubung dengan jalan. Setiap jalan memiliki panjang tertentu. Tugasmu adalah menampilkan daftar jalan yang menghubungkan kota-kota, beserta panjang jalan tersebut.

**Input:**

- Baris pertama berisi dua bilangan bulat `n` dan `m`, yang menyatakan jumlah kota dan jumlah jalan.
    
- Baris berikutnya berisi `m` baris, yang masing-masing berisi tiga bilangan bulat `u`, `v`, dan `w` yang menunjukkan adanya jalan antara kota `u` dan `v` dengan panjang `w`.
    

**Output:**

- Daftar jalan yang menghubungkan kota-kota dalam format "u - v (w)", yang menunjukkan jalan antara kota `u` dan kota `v` dengan panjang `w`. Jangan tampilkan duplikasi atau urutan yang berbeda (misalnya "u - v" dan "v - u" hanya boleh muncul satu kali).
    

**Contoh Input:**

```
3 3
1 2 5
2 3 7
1 3 3
```

**Contoh Output:**

```
1 - 2 (5)
2 - 1 (5)
1 - 3 (3)
3 - 1 (3)
2 - 3 (7)
3 - 2 (7)
```

## 2.1 | Jawaban
Berikut jawaban yang sudah cukup efektif dan solid:

```cpp
#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

inline void fastio(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}

int main() {
    int n,m;
    cin >> n >> m;

    vector<tuple<int,int,int>> edges;

    for(int i=0; i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;

        edges.push_back({u,v,w});
        edges.push_back({v,u,w});
    }

    cout << "\n";
    for(auto& edge:edges){
        int u,v,w;
        tie(u,v,w) = edge;
        cout << u << " - " << v << " (" << w << ")\n"; 
    }
    return 0;
}
```

## 2.2 | Editorial

### 2.2.1 | Penjelasan:

- **`tie(u, v, w) = edge;`**: Ini digunakan untuk membongkar tuple menjadi tiga variabel `u`, `v`, dan `w`.
    
- **Kenapa dua kali `push_back`?** Karena graf tak berarah (undirected), maka setiap edge `u v` harus disimpan juga sebagai `v u`.
    
- Output menampilkan edge dengan bobotnya, contoh:
    
    ```
    1 - 2 (4)
    2 - 1 (4)
    ```
    

Jika kamu ingin menghindari duplikasi seperti pada soal sebelumnya, kamu juga bisa gunakan `set<tuple<int,int,int>>` dengan pendekatan mirip seperti ini:

```cpp
edges.insert({min(u,v), max(u,v), w});
```

Tapi kalau memang kamu ingin eksplisit mencetak dua arah, versi sekarang sudah sangat baik.

## 2.3 | Editorial 2

### 2.3.1 | Tujuan Program:

Program ini digunakan untuk membaca dan menampilkan graf tak berarah (undirected) dengan bobot (weighted), menggunakan struktur **edge list**.

### 2.3.2 | Penjelasan Kode per Bagian:

```cpp
#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
```

- `#include<iostream>` → Digunakan untuk operasi input dan output (`cin`, `cout`).
    
- `#include<vector>` → Digunakan untuk menyimpan daftar edge dalam struktur `vector`.
    
- `#include<tuple>` → Digunakan untuk menyimpan tiga elemen (`u`, `v`, dan `w`) dalam satu tuple.
    


```cpp
inline void fastio(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}
```

- Fungsi `fastio()` mempercepat proses I/O agar efisien.
    
    - `sync_with_stdio(0)` memutus sinkronisasi `cin/cout` dengan `scanf/printf`.
        
    - `cin.tie(0)` mencegah `cin` otomatis mem-flush `cout`.
        


```cpp
int n,m;
cin >> n >> m;
```

- Membaca jumlah simpul (`n`) dan jumlah sisi (`m`) dari graf.
    

```cpp
vector<tuple<int,int,int>> edges;
```

- Membuat vektor `edges` untuk menyimpan daftar sisi graf.
    
- Setiap elemen tuple menyimpan:
    
    - `u` = simpul asal,
        
    - `v` = simpul tujuan,
        
    - `w` = bobot/berat sisi dari `u` ke `v`.
        

```cpp
for(int i=0; i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;

    edges.push_back({u,v,w});
    edges.push_back({v,u,w});
}
```

- Perulangan ini membaca `m` buah sisi.
    
- Karena **graf tidak berarah**, maka:
    
    - Tambahkan dua sisi untuk setiap masukan: `u → v` dan `v → u`.
        

```cpp
for(auto& edge:edges){
    int u,v,w;
    tie(u,v,w) = edge;
    cout << u << " - " << v << " (" << w << ")\n"; 
}
```

- Melakukan iterasi untuk menampilkan semua sisi dalam graf.
    
- Fungsi `tie(u,v,w)` digunakan untuk membongkar tuple menjadi tiga variabel terpisah.
    
- Output menampilkan sisi dalam format:
    
    - `u - v (w)`, artinya terdapat sisi dari `u` ke `v` dengan bobot `w`.
        

### 2.3.3 | Contoh Input Output

```
3 2
1 2 5
2 3 7
```

### 2.3.4 | Contoh Output:

```
1 - 2 (5)
2 - 1 (5)
2 - 3 (7)
3 - 2 (7)
```

### 2.3.5 | Kesimpulan:

- Representasi **edge list** sangat efisien untuk menyimpan sisi secara eksplisit.
    
- Cocok digunakan dalam algoritma seperti:
    
    - **Kruskal's Algorithm** (untuk MST),
        
    - **Bellman-Ford** (untuk shortest path pada graf berbobot negatif),
        
- `tuple<int,int,int>` memudahkan menyimpan dan mengakses tiga komponen sisi.
    
