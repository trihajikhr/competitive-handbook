---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 13TH-SPFA-0002
nama_algoritma: Bellman Ford Algorithm - SPFA
kategori_algoritma: Graph - Shortest Path
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen & programmiz.com & geeksforgeeks.com & chatgpt.com"
date_learned: 2025-05-04T21:46:00
tags:
  - graph
  - SPFA
  - shortest-paths
  - bellman-ford
---
#graph #bellman-ford  #SPFA #shortest-paths 

---
# Algoritma Shortest Path Faster (SPFA)

Diberikan sebuah graf berarah berbobot dengan **V** simpul (vertices), **E** sisi (edges), dan sebuah simpul sumber **S**. Tugasnya adalah mencari jalur terpendek dari simpul sumber ke semua simpul lainnya dalam graf tersebut.

## Contoh:

**Input**:  
V = 5, S = 1  
arr = `{{1, 2, 1}, {2, 3, 7}, {2, 4, -2}, {1, 3, 8}, {1, 4, 9}, {3, 4, 3}, {2, 5, 3}, {4, 5, -3}}`  

**Output**:
```
1, 0  
2, 1  
3, 8  
4, -1  
5, -4  
```

**Penjelasan**:  
Untuk input tersebut, jalur terpendek dari simpul 1 ke 1 adalah 0, dari 1 ke 2 adalah 1, dan seterusnya.

---
**Input**:  
V = 5, S = 1  
arr = `{{1, 2, -1}, {1, 3, 4}, {2, 3, 3}, {2, 4, 2}, {2, 5, 2}, {4, 3, 5}, {4, 2, 1}, {5, 4, 3}}`  

**Output**:
```
1, 0  
2, -1  
3, 2  
4, 1  
5, 1  
```

---

## Pendekatan:

Algoritma SPFA (Shortest Path Faster Algorithm) didasarkan pada algoritma Bellman-Ford, di mana setiap simpul digunakan untuk melakukan relaksasi terhadap simpul-simpul tetangganya. Namun, dalam algoritma SPFA, kita menggunakan **antrian (queue)** untuk menyimpan simpul-simpul yang perlu diproses. Sebuah simpul hanya akan dimasukkan ke dalam antrian jika nilai jaraknya mengalami relaksasi (yakni, diperbarui menjadi lebih kecil). Proses ini terus berlangsung sampai tidak ada lagi simpul yang bisa direlaksasi.

### Langkah-langkah:

1. Buat array `d[]` untuk menyimpan jarak terpendek dari simpul sumber ke setiap simpul lainnya. Inisialisasi semua elemen array ini dengan tak hingga (`infinity`) kecuali `d[S] = 0` (S adalah simpul sumber).
    
2. Buat antrian `Q` dan masukkan simpul sumber ke dalamnya.
    
3. Selama antrian tidak kosong, lakukan hal berikut untuk setiap edge (u, v) di graf:
    
    - Jika `d[v] > d[u] + bobot edge(u, v)`, maka:
        
        - `d[v] = d[u] + bobot edge(u, v)`
            
        - Jika simpul `v` belum ada di antrian, masukkan simpul `v` ke dalam antrian.
            

**Catatan**:  
Istilah _relaksasi_ berarti memperbarui nilai biaya/estimasi jarak ke simpul `v` jika jalur melalui `u` memberikan nilai yang lebih kecil. Hal ini bisa dianalogikan seperti _pegas spiral yang ditarik_—pada awalnya, estimasi jaraknya terlalu tinggi (pegasnya panjang). Ketika ditemukan jalur yang lebih pendek, "pegas" ini menjadi lebih santai (relaksasi), dan nilainya semakin mendekati nilai sebenarnya. Akhirnya, ketika semua relaksasi selesai, nilai-nilai jarak yang benar ditemukan.

# Implementasi
Implementasi dari Pendekatan di Atas (dalam C++):

```cpp
// Implementasi SPFA dalam C++

#include <bits/stdc++.h>
using namespace std;

// Graf disimpan dalam bentuk vektor dari vektor pasangan (pair)
// Elemen pertama dari pair menyimpan simpul tujuan (vertex)
// Elemen kedua dari pair menyimpan bobot (weight)
vector<vector<pair<int, int>>> graph;

// Fungsi untuk menambahkan edge ke dalam graf
// Menghubungkan simpul 'frm' ke simpul 'to' dengan bobot tertentu
void addEdge(int frm, int to, int weight) {
    graph[frm].push_back({ to, weight });
}

// Fungsi untuk mencetak jarak terpendek dari simpul sumber
void print_distance(int d[], int V) {
    cout << "Simpul \t\t Jarak dari sumber" << endl;

    for (int i = 1; i <= V; i++) {
        cout << i << " \t\t " << d[i] << '\n';
    }
}

// Fungsi utama untuk menjalankan algoritma SPFA
void shortestPathFaster(int S, int V) {
    // Array untuk menyimpan jarak terpendek
    int d[V + 1];

    // Array boolean untuk mengecek apakah simpul sedang ada dalam antrian
    bool inQueue[V + 1] = { false };

    // Inisialisasi semua jarak ke tak hingga (infinity)
    for (int i = 0; i <= V; i++) {
        d[i] = INT_MAX;
    }
    d[S] = 0;

    // Inisialisasi antrian dan masukkan simpul sumber
    queue<int> q;
    q.push(S);
    inQueue[S] = true;

    while (!q.empty()) {
        // Ambil simpul dari depan antrian
        int u = q.front();
        q.pop();
        inQueue[u] = false;

        // Relaksasi semua edge yang keluar dari simpul ini
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            int weight = graph[u][i].second;

            // Jika ditemukan jalur lebih pendek
            if (d[v] > d[u] + weight) {
                d[v] = d[u] + weight;

                // Jika simpul belum ada dalam antrian, masukkan ke antrian
                if (!inQueue[v]) {
                    q.push(v);
                    inQueue[v] = true;
                }
            }
        }
    }

    // Cetak hasil akhir
    print_distance(d, V);
}

// Fungsi utama
int main() {
    int V = 5;  // Jumlah simpul
    int S = 1;  // Simpul sumber

    // Inisialisasi graf dengan V+1 simpul (indeks mulai dari 1)
    graph = vector<vector<pair<int, int>>>(V + 1);

    // Menambahkan edge: addEdge(dari, ke, bobot)
    addEdge(1, 2, 1);
    addEdge(2, 3, 7);
    addEdge(2, 4, -2);
    addEdge(1, 3, 8);
    addEdge(1, 4, 9);
    addEdge(3, 4, 3);
    addEdge(2, 5, 3);
    addEdge(4, 5, -3);

    // Menjalankan algoritma SPFA
    shortestPathFaster(S, V);

    return 0;
}
```

### Output:

```
Simpul      Jarak dari sumber  
1           0  
2           1  
3           8  
4          -1  
5          -4  
```

---

### Kompleksitas Waktu:

- **Rata-rata**: O(|E|)
    
- **Kasus terburuk**: O(|V| × |E|)
    

### Kompleksitas Ruang:

- **O(V)** karena kita menyimpan array jarak untuk setiap simpul.
    

> **Catatan**: Batas waktu rata-rata (O(|E|)) untuk algoritma SPFA masih belum terbukti secara teoritis, namun secara praktis algoritma ini sangat cepat untuk banyak graf.
