---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 13TH-SPBF-0001
nama_algoritma: Bellman Ford Algorithm
kategori_algoritma: graph
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen & programmiz.com & geeksforgeeks.com & chatgpt.com"
date_learned: 2025-04-17T14:39:00
tags:
  - graph
  - shortest-paths
  - bellman-ford
---
#graph #shortest-paths #bellman-ford 

---
# Bellman Ford Algorithm (Programmiz)
> Programmiz.com

Algoritma ini mirip dengan algoritma Dijkstra tetapi dapat bekerja dengan graph yang memiliki edge dengan bobot negatif.

### Mengapa dalam kehidupan nyata seseorang memiliki edge dengan bobot negatif?  

Edge dengan bobot negatif mungkin terlihat tidak berguna pada awalnya, tetapi bobot negatif dapat menjelaskan banyak fenomena seperti arus kas (_cashflow_), panas yang dilepaskan/diserap dalam reaksi kimia, dan sebagainya.

Sebagai contoh, jika terdapat berbagai cara untuk mencapai dari satu zat kimia A ke zat kimia lain B, setiap metode akan memiliki sub-reaksi yang melibatkan baik pelepasan maupun penyerapan panas.

Jika kita ingin menemukan kumpulan reaksi di mana energi minimum dibutuhkan, maka kita perlu mempertimbangkan penyerapan panas sebagai bobot negatif dan pelepasan panas sebagai bobot positif.

### Mengapa kita perlu berhati-hati dengan bobot negatif?  
Edge dengan bobot negatif dapat menciptakan _negative weight cycle_, yaitu sebuah siklus yang akan mengurangi total jarak lintasan dengan kembali ke titik yang sama.

![[Bellman Ford Algorithm-1.png]]


Algoritma _shortest path_ seperti **Dijkstra's Algorithm** yang tidak mampu mendeteksi siklus semacam itu dapat memberikan hasil yang salah karena mereka bisa melewati _negative weight cycle_ dan mengurangi panjang lintasan.

## Algoritma Bellman Ford
Algoritma Bellman Ford bekerja dengan melebih-lebihkan panjang lintasan dari _starting vertex_ ke semua _vertex_ lainnya. Kemudian algoritma ini secara iteratif melakukan _relaxation_ terhadap estimasi tersebut dengan menemukan lintasan-lintasan baru yang lebih pendek daripada lintasan yang sebelumnya telah dilebih-lebihkan.

Dengan melakukan ini berulang kali untuk semua _vertex_, kita dapat menjamin bahwa hasil akhirnya sudah teroptimasi.

1. Mulai dengan weighted graph
   ![[Bellman Ford Algorithm-2.png]]
2. Pilih sebuah starting vertex dan tetapkan nilai lintasan tak hingga (*infinity*) ke semua vertex lainnya.
   ![[Bellman Ford Algorithm-3.png]]
3. Kunjungi setiap edge dan lakukan *relaxation* terhadap jarak lintasan jika nilainya tidak akurat.
   ![[Bellman Ford Algorithm-4.png]]
   **Catatan:** Untuk melakukan _relaxation_ terhadap lintasan pada sebuah _edge_ (U, V), jika: 
   - `distance(U) + edge_weight(U, V) < distance(V)`,  maka tetapkan  
   - `distance(V) = distance(U) + edge_weight(U, V)`.

4. Kita perlu melakukan ini sebanyak **V kali** karena dalam kasus terburuk, panjang lintasan suatu *vertex* mungkin perlu disesuaikan ulang sebanyak **V kali**.
   ![[Bellman Ford Algorithm-5.png]]
5. Perhatikan bagaimana *vertex* di pojok kanan atas mengalami penyesuaian pada panjang lintasannya.
   ![[Bellman Ford Algorithm-6.png]]
6. Step terakhir
   ![[Bellman Ford Algorithm-7.png]]
## Pseudocode Bellman Ford Algorithm

Kita perlu menyimpan jarak lintasan (_path distance_) untuk setiap _vertex_. Kita dapat menyimpannya dalam sebuah array berukuran _v_, di mana _v_ adalah jumlah _vertex_.

Kita juga ingin bisa mendapatkan lintasan terpendek, bukan hanya mengetahui panjang lintasan terpendek saja. Untuk itu, kita memetakan setiap _vertex_ ke _vertex_ yang terakhir memperbarui panjang lintasannya.

Setelah algoritma selesai dijalankan, kita dapat melakukan _backtrack_ dari _destination vertex_ ke _source vertex_ untuk menemukan lintasannya.

```plaintext
function bellmanFord(G, S)
  for each vertex V in G
    distance[V] <- infinite
    previous[V] <- NULL
  distance[S] <- 0

  for each vertex V in G				
    for each edge (U,V) in G
      tempDistance <- distance[U] + edge_weight(U, V)
      if tempDistance < distance[V]
        distance[V] <- tempDistance
        previous[V] <- U

  for each edge (U,V) in G
    if distance[U] + edge_weight(U, V) < distance[V]
      Error: Negative Cycle Exists

  return distance[], previous[]
```
# Contoh Algoritma Bellman Ford

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
# Bellman Ford Complexity
## Time Complexity
### Best Case (Kasus Terbaik) - $O(V\cdot E)$
Dalam kasus terbaik, ketika semua edge sudah di-_relax_ dengan cepat (misalnya, graph tidak memiliki banyak perubahan dalam iterasi pertama), kompleksitas waktu tetap O(V × E) karena algoritma akan tetap memeriksa semua edge sebanyak V-1 kali.
### Average Case (Kasus Rata-rata) - $O(V\cdot E)$
Dalam kasus rata-rata, algoritma Bellman-Ford masih membutuhkan waktu O(V × E) karena untuk setiap iterasi, algoritma akan memeriksa semua edge dan melakukan _relaxation_.

### Worst Case (Kasus Terburuk) - $O(V\cdot E)$
Kasus terburuk terjadi ketika graph memiliki banyak edge dan vertex, serta perlu melakukan _relaxation_ untuk setiap edge sebanyak V-1 kali (terutama pada graph dengan banyak siklus atau jika tidak ada pengurangan jarak). Oleh karena itu, kompleksitas waktu Bellman-Ford adalah O(V × E) dalam kasus terburuk.

### Penjelasan Komplexitas:

- **V** adalah jumlah _vertex_ dalam graph.
    
- **E** adalah jumlah _edge_ dalam graph.
    

Walaupun Bellman-Ford efektif dalam menangani graph dengan bobot negatif dan mendeteksi siklus negatif, ia bisa menjadi kurang efisien pada graph yang sangat besar karena kompleksitas waktu yang lebih tinggi dibandingkan algoritma lain seperti Dijkstra (dengan heap).

| Kasus        | Kompleksitas Waktu |
| ------------ | ------------------ |
| Best Case    | $O(V\cdot E)$      |
| Average Case | $O(V\cdot E)$      |
| Worst Case   | $O(V\cdot E)$      |
## Space Complexity dan Stability
### Space Complexity
Kompleksitas ruang dari algoritma Bellman-Ford bergantung pada data yang perlu disimpan:

1. **Ruang untuk Menyimpan Jarak (Distances)**:  
    Bellman-Ford memerlukan array untuk menyimpan jarak terpendek dari _source vertex_ ke setiap _vertex_ lainnya. Ini membutuhkan ruang O(V), di mana V adalah jumlah _vertex_ dalam graph.
    
2. **Ruang untuk Menyimpan Previous Vertex (Previous Array)**:  
    Untuk melacak lintasan terpendek, kita juga perlu array untuk menyimpan _previous vertex_ yang digunakan untuk membangun kembali lintasan terpendek. Ini juga membutuhkan O(V) ruang.
    
3. **Ruang untuk Menyimpan Graph**:  
    Graph biasanya disimpan dalam bentuk adjacency list atau adjacency matrix, yang memerlukan O(E) ruang, di mana E adalah jumlah _edge_ dalam graph.

Jadi, total **Space Complexity** dari algoritma Bellman-Ford adalah O(V + E).

- **Space Complexity**: O(V + E)
### Stability
Stabilitas dalam konteks algoritma biasanya merujuk pada apakah algoritma dapat memberikan hasil yang konsisten dan dapat diandalkan dalam semua kasus, termasuk kasus yang memerlukan penanganan nilai yang sangat besar atau sangat kecil.

1. **Stabilitas Bellman-Ford**:  
    Bellman-Ford dapat menangani graph dengan bobot negatif dan mendeteksi siklus negatif, yang memberikan stabilitas dalam hal deteksi jalur terpendek meskipun ada perubahan dalam bobot yang dapat menyebabkan hasil yang lebih buruk pada algoritma lain yang tidak dapat menangani bobot negatif. Namun, Bellman-Ford tidak begitu efisien jika dibandingkan dengan algoritma seperti Dijkstra pada graph dengan bobot non-negatif.
    
2. **Ketahanan terhadap Siklus Negatif**:  
    Bellman-Ford memiliki keunggulan dalam hal stabilitas karena dapat mendeteksi _negative weight cycle_ dan memberikan **error** ketika siklus negatif ditemukan, yang menunjukkan bahwa solusi optimal tidak dapat ditemukan.
## Kesimpulan
- Bellman-Ford adalah pilihan yang sangat baik untuk **graph dengan bobot negatif** dan **deteksi siklus negatif**.
    
- Namun, untuk graph tanpa bobot negatif, **Dijkstra** lebih efisien dan lebih cepat.

Berikut adalah pembahasan tentang **Aplikasi Bellman-Ford**, termasuk keunggulan, kelemahan, dan kesimpulannya:


# Aplikasi Bellman-Ford

Algoritma Bellman-Ford digunakan untuk mencari **lintasan terpendek** dari satu titik sumber ke semua titik lainnya dalam graph berbobot, termasuk graph dengan **bobot negatif**. Selain itu, algoritma ini mampu **mendeteksi siklus berbobot negatif**, menjadikannya alat penting dalam pemodelan yang melibatkan perubahan nilai dinamis seperti:

- **Perdagangan mata uang (currency arbitrage)**
    
- **Perhitungan jalur biaya minimum dengan penalti**
    
- **Pemodelan energi dalam reaksi kimia**
    
- **Routing jaringan (contoh: RIP – Routing Information Protocol)**
    

## Keunggulan dan Kelemahan

### Keunggulan Bellman-Ford

- ✅ **Mampu menangani bobot negatif**: Tidak seperti Dijkstra, Bellman-Ford bekerja dengan baik pada graph yang memiliki edge dengan bobot negatif.
    
- ✅ **Dapat mendeteksi siklus negatif**: Salah satu fitur terpenting adalah kemampuannya untuk memberitahu apakah graph mengandung _negative weight cycle_.
    
- ✅ **Implementasi sederhana**: Meskipun tidak seefisien Dijkstra dalam hal kecepatan, implementasinya cukup lurus dan mudah dipahami.
    
- ✅ **Fleksibel**: Dapat digunakan untuk berbagai jenis representasi graph (adjacency list/matrix).
    

### Kelemahan Bellman-Ford

- ❌ **Lebih lambat dari Dijkstra**: Dengan kompleksitas waktu **O(V × E)**, Bellman-Ford lebih lambat dibandingkan Dijkstra (dengan heap) yang berjalan dalam O((V + E) log V).
    
- ❌ **Kurang efisien untuk graph besar**: Karena perlu mengevaluasi semua edge berkali-kali, Bellman-Ford menjadi tidak praktis untuk graph dengan ribuan vertex dan edge.
    
- ❌ **Tidak optimal untuk graph tanpa bobot negatif**: Pada kasus seperti ini, Dijkstra jauh lebih cepat dan lebih efisien.
    

## Kesimpulan

- Algoritma **Bellman-Ford sangat cocok digunakan** pada kasus-kasus di mana:
    
    - Graph mengandung bobot negatif.
        
    - Kita ingin mendeteksi adanya _negative weight cycle_.
        
- **Kurang cocok digunakan** untuk graph besar dan tidak mengandung bobot negatif karena performanya yang lambat.
    
- Meskipun lebih lambat, **Bellman-Ford unggul dalam fleksibilitas dan kemampuan menangani kondisi kompleks**, membuatnya tetap penting untuk dipelajari dan digunakan dalam konteks tertentu.
    
