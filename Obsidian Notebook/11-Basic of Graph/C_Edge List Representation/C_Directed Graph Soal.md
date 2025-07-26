---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 11TH-BGRP-EL03
nama_algoritma: Edge list graph representation
kategori_algoritma: Graph Algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen & chatgpt.com"
date_learned: 2025-04-29T16:34:00
tags:
  - graph-algorithm
  - graph-edge-list
---
#graph-algorithm #graph-edge-list 

---
# 🔹 Soal 1: Directed Unweighted Graph

**Deskripsi:** Terdapat _n_ situs web dan _m_ hyperlink. Setiap hyperlink mengarahkan dari satu situs ke situs lain. Tampilkan semua hyperlink dalam urutan input menggunakan _edge list_.

**Input Format:**

```
n m
u₁ v₁
u₂ v₂
...
uₘ vₘ
```

- `n`: jumlah node (situs web)
    
- `m`: jumlah hyperlink (edge)
    
- `uᵢ → vᵢ`: hyperlink dari situs `uᵢ` ke `vᵢ`
    

**Contoh Input:**

```
4 3
1 2
2 3
3 4
```

**Contoh Output:**

```
Hyperlink:
1 -> 2
2 -> 3
3 -> 4
```

## Jawaban
Berikut implementasi dengan menggunakan C++, yang cukup efisien dan solid:

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

    vector<pair<int,int>> edges;

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;

        edges.push_back({u,v});
    }

    cout << "\n\nHyperlink: \n";   
    for(const auto&x:edges){
        cout << x.first << " -> " << x.second << "\n";
    }
    return 0;
}
```

## Editorial

### 📝 Deskripsi Soal

Diberikan sebuah directed graph (graf berarah) tanpa bobot. Tugas kita adalah menyimpan semua hubungan arah antar simpul, kemudian mencetak semua arah sebagai output, menggunakan **edge list representation**.

### 💡 Konsep yang Digunakan

- **Edge List Representation** adalah cara menyimpan graph dengan menyimpan setiap edge sebagai pasangan `(u, v)`, di mana `u` adalah node asal dan `v` adalah node tujuan.
    
- Representasi ini efisien dan sederhana untuk menyimpan informasi edge dan cocok untuk graf yang jarang (sparse graph).
    

### 🧩 Penjelasan Kode

```cpp
vector<pair<int,int>> edges;
```

- Kita membuat sebuah vektor dari pasangan `(int, int)` untuk menyimpan setiap edge `(u, v)` yang merepresentasikan arah dari `u` ke `v`.
    

```cpp
cin >> u >> v;
edges.push_back({u, v});
```

- Menerima input edge dari user dan langsung menyimpannya ke dalam edge list.
    

```cpp
for (const auto& x : edges) {
    cout << x.first << " -> " << x.second << "\n";
}
```

- Melakukan iterasi pada semua pasangan `(u, v)` dan mencetaknya dalam format arah: `u -> v`.
    

### 🖥️ Contoh Input

```
4 3
1 2
2 3
4 2
```

### 📤 Output

```
Hyperlink: 
1 -> 2
2 -> 3
4 -> 2
```

### ✅ Kelebihan Pendekatan Ini

- Simpel dan mudah diimplementasikan.
    
- Menggunakan memori rendah dibanding adjacency matrix (hanya menyimpan edge saja).
    
- Sangat cocok untuk operasi seperti _sorting edges_, _minimum spanning tree_, atau saat menggunakan algoritma seperti Kruskal’s.
    

---

# 🔹 Soal 2: Directed Weighted Graph

**Deskripsi:** Sebuah kota memiliki _n_ titik persimpangan dan _m_ jalan satu arah, masing-masing dengan waktu tempuh tertentu. Tampilkan seluruh jalan dalam format edge list.

**Input Format:**

```
n m
u₁ v₁ w₁
u₂ v₂ w₂
...
uₘ vₘ wₘ
```

- `n`: jumlah node (persimpangan)
    
- `m`: jumlah jalan
    
- `wᵢ`: waktu tempuh dari `uᵢ` ke `vᵢ`
    

**Contoh Input:**

```
4 3
1 2 10
2 3 20
4 1 5
```

**Contoh Output:**

```
Daftar Jalan:
1 -> 2 (10 menit)
2 -> 3 (20 menit)
4 -> 1 (5 menit)
```

---

Kamu bisa menyelesaikan keduanya menggunakan struktur seperti:

- `vector<pair<int, int>>` untuk soal pertama.
    
- `vector<tuple<int, int, int>>` untuk soal kedua.
    
## Jawaban

Berikut jawaban dengan menggunakan kode C++ yang sudah cukup solid:

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
    fastio();
    int n,m;
    cin >> n >> m;

    vector<tuple<int,int,int>> edges;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;

        edges.push_back({u,v,w});
    }

    cout << "\nDaftar Jalan: \n";
    for(auto &edge : edges){
        int u, v, w;
        tie(u, v, w) = edge;
        cout << u << " -> " << v << " (" << w << " menit)\n";
    }
    cout << "\n";
    return 0;
}
```

## Editorial
### Tujuan Program:

Program ini mengimplementasikan **representasi graph dengan edge list** pada **directed weighted graph**. Program ini menerima input berupa jumlah node dan edges, serta detail edges yang berisi pasangan node (`u` dan `v`) dan bobot (`w`). Program ini kemudian menampilkan daftar edge dengan bobotnya.

### Penjelasan Kode:

1. **Library dan Setup:**
    
    ```cpp
    #include<iostream>
    #include<vector>
    #include<tuple>
    using namespace std;
    ```
    
    - `#include<iostream>`: Mengimpor library untuk input dan output standar.
        
    - `#include<vector>`: Digunakan untuk menyimpan list edge dalam bentuk vector.
        
    - `#include<tuple>`: Mengimpor library untuk menggunakan tuple yang memungkinkan penyimpanan lebih dari satu nilai dalam satu unit.
        
    
    `using namespace std;` memudahkan penulisan tanpa perlu menulis `std::` berulang kali.
    
2. **Fungsi `fastio()`:**
    
    ```cpp
    inline void fastio(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    ```
    
    - Fungsi ini digunakan untuk mempercepat proses input/output. `ios_base::sync_with_stdio(0)` mengatur agar `cin` dan `cout` tidak disinkronkan dengan C-style I/O (seperti `scanf` dan `printf`), yang mempercepat proses input dan output.
        
    - `cin.tie(0)` dan `cout.tie(0)` digunakan untuk memutuskan ikatan antara `cin` dan `cout`, yang lagi-lagi mempercepat I/O.
        
3. **Inisialisasi dan Input:**
    
    ```cpp
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    ```
    
    - `n` adalah jumlah node (titik), dan `m` adalah jumlah edge (jalan/jalur).
        
    - `vector<tuple<int, int, int>> edges;` digunakan untuk menyimpan semua edge. Setiap edge disimpan dalam bentuk tuple yang berisi:
        
        - `u`: Node asal
            
        - `v`: Node tujuan
            
        - `w`: Bobot dari edge (misalnya, waktu atau jarak).
            
    
    Program kemudian melakukan input sebanyak `m` kali untuk membaca setiap edge yang memiliki dua node dan bobot.
    
4. **Input Edge:**
    
    ```cpp
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    ```
    
    - Loop ini digunakan untuk membaca input sebanyak `m` kali.
        
    - Setiap iterasi menerima input untuk `u`, `v`, dan `w`, yang menunjukkan sebuah edge dari node `u` ke node `v` dengan bobot `w`.
        
    - Setelah itu, `edges.push_back({u, v, w});` menambahkan edge ini ke dalam vector `edges` dalam bentuk tuple `(u, v, w)`.
        
5. **Menampilkan Output:**
    
    ```cpp
    cout << "\nDaftar Jalan: \n";
    for(auto &edge : edges){
        int u, v, w;
        tie(u, v, w) = edge;
        cout << u << " -> " << v << " (" << w << " menit)\n";
    }
    cout << "\n";
    ```
    
    - `cout << "\nDaftar Jalan: \n";` Menampilkan header untuk output.
        
    - `for(auto &edge : edges)` adalah loop yang digunakan untuk mengiterasi setiap edge di dalam vector `edges`.
        
    
    **Menggunakan `tie()` untuk Dekonstruksi Tuple:**
    
    ```cpp
    tie(u, v, w) = edge;
    ```
    
    - Di sini, `tie()` digunakan untuk **dekonstruksi** tuple. `edge` adalah tuple `(u, v, w)` yang berisi 3 elemen, dan kita ingin mengambil nilai-nilai tersebut dan menyimpannya ke dalam variabel `u`, `v`, dan `w`.
        
    - `tie()` memungkinkan kita untuk mendapatkan nilai-nilai dari tuple tanpa perlu menggunakan indeks seperti `get<0>(edge)` atau `get<1>(edge)`.
        
    
    **Menampilkan Setiap Edge:**
    
    ```cpp
    cout << u << " -> " << v << " (" << w << " menit)\n";
    ```
    
    - Setelah mendekonstruksi tuple ke dalam variabel `u`, `v`, dan `w`, kita mencetak informasi edge tersebut dalam format `u -> v (w menit)`.
        

### Penjelasan Bagian `tie()`:

`tie()` adalah fungsi di C++ yang digunakan untuk mengeluarkan nilai dari objek **tuple** ke dalam variabel individual. Contohnya:

```cpp
tie(u, v, w) = edge;
```

- Di sini, `edge` adalah sebuah tuple dengan tiga elemen `(u, v, w)`. `tie()` digunakan untuk mengasignasikan nilai-nilai dalam tuple tersebut langsung ke variabel `u`, `v`, dan `w`.
    
- `tie()` sangat berguna saat kita ingin mengambil banyak nilai dari objek `tuple` tanpa menggunakan cara `get<0>(edge)`, `get<1>(edge)`, dll. Dengan `tie()`, kita bisa mendekonstruksi tuple ke dalam variabel dengan lebih ringkas dan jelas.
    

### Contoh Input dan Output:

**Input:**

```
4 4
1 2 5
2 3 3
3 4 2
4 1 7
```

- `n = 4` (ada 4 node)
    
- `m = 4` (ada 4 edge)
    
- Edges:
    
    - Edge pertama: 1 -> 2 dengan bobot 5
        
    - Edge kedua: 2 -> 3 dengan bobot 3
        
    - Edge ketiga: 3 -> 4 dengan bobot 2
        
    - Edge keempat: 4 -> 1 dengan bobot 7
        

**Output:**

```
Daftar Jalan:
1 -> 2 (5 menit)
2 -> 3 (3 menit)
3 -> 4 (2 menit)
4 -> 1 (7 menit)
```

### Kesimpulan:

- **Fitur `tie()`** sangat mempermudah dekonstruksi tuple dan membuat kode menjadi lebih jelas dan lebih singkat.
    
- **Edge List Representation** dengan menggunakan **tuple** dalam vector sangat cocok untuk menyimpan dan memproses graph yang memiliki banyak edge, terutama ketika setiap edge memiliki bobot seperti dalam soal ini.
    
- Program ini dapat dengan mudah digunakan untuk menyelesaikan masalah-masalah yang melibatkan graph terarah dan berbobot.
    
