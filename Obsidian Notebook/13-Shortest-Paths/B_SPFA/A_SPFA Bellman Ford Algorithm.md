---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 13TH-SPFA-0001
nama_algoritma: Bellman Ford Algorithm - SPFA
kategori_algoritma: Graph - Shortest Path
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen & programmiz.com & geeksforgeeks.com & chatgpt.com"
date_learned: 2025-05-04T21:19:00
tags:
  - graph-algorithm
  - shortest-paths
  - SPFA
  - bellman-ford
---
#graph-algorithm #shortest-paths #SPFA #bellman-ford 

---
# SPFA Algorithm (Antii Laaksonen)
**Algoritma SPFA** ("Shortest Path Faster Algorithm") adalah varian dari algoritma Bellman-Ford, yang seringkali lebih efisien daripada algoritma asli. Algoritma SPFA tidak memeriksa semua edge pada setiap putaran, tetapi sebaliknya, memilih edge yang akan diperiksa dengan cara yang lebih cerdas. 

Algoritma ini mempertahankan antrian node yang mungkin digunakan untuk mengurangi jarak. Pertama, algoritma menambahkan node awal 𝑥 ke dalam queue. Kemudian, algoritma selalu memproses node pertama dalam queue, dan ketika sebuah edge 𝑎 → 𝑏 mengurangi jarak, node 𝑏 ditambahkan ke dalam queue. 

Efisiensi algoritma SPFA tergantung pada struktur graf: algoritma ini seringkali efisien, tetapi kompleksitas waktu kasus terburuknya tetap 𝑂(𝑛𝑚), dan memungkinkan untuk membuat input yang dapat membuat algoritma ini seperlahan algoritma Bellman-Ford asli.
# SPFA Bellman Ford Algorithm
**SPFA (Shortest Path Faster Algorithm)** adalah algoritma yang lebih cepat daripada **Bellman-Ford** untuk mencari jarak terpendek dalam graf berbobot, tetapi dengan prinsip yang mirip. SPFA sering dianggap sebagai pengembangan dari Bellman-Ford, dengan menggunakan **queue** (biasanya **queue berbasis prioritas** atau **deque**) untuk meningkatkan efisiensi dalam memperbarui jarak terpendek pada setiap iterasi.

### Perbedaan Utama dengan Bellman-Ford:

1. **Bellman-Ford**: Setiap iterasi memperbarui jarak untuk semua sisi (edges) dalam graf, tanpa mempertimbangkan apakah sebuah sisi benar-benar perlu diproses lagi. Ini mengarah pada waktu eksekusi yang lebih lambat terutama untuk graf yang jarang (sparse graph).
<br/>
2. **SPFA**: Alih-alih memeriksa setiap sisi dalam graf pada setiap iterasi, SPFA hanya memproses node yang jaraknya telah diperbarui dan dimasukkan ke dalam antrian. Dengan kata lain, hanya node yang "perlu diproses" yang akan diproses, dan ini sering kali mengurangi jumlah iterasi yang diperlukan, sehingga lebih cepat dalam banyak kasus.
    

### Langkah-langkah SPFA:

1. **Inisialisasi**:
    
    - Tentukan jarak awal dari sumber (src) ke semua node lainnya sebagai tak terhingga (infinity).
        
    - Masukkan node sumber ke dalam **queue** dengan jarak 0.
        
2. **Proses Queue**:
    
    - Ambil node terdepan dari **queue**.
        
    - Periksa setiap sisi yang terhubung ke node tersebut. Jika ada jarak yang lebih pendek ke node yang terhubung, perbarui jarak dan masukkan node tersebut ke dalam **queue** jika belum ada di sana.
        
3. **Repeat**: Proses langkah 2 sampai tidak ada perubahan lebih lanjut pada jarak.
    
4. **Menghentikan Algoritma**:
    
    - Jika **queue** kosong dan tidak ada perubahan lebih lanjut, algoritma selesai.
        

### Kelebihan SPFA dibandingkan dengan Bellman-Ford:

1. **Lebih Cepat**: Karena hanya memproses node yang jaraknya berubah, SPFA lebih cepat dalam banyak kasus, terutama pada graf yang jarang.
    
2. **Efisiensi dengan Queue**: Penggunaan **queue** membantu memastikan bahwa hanya node yang perlu diproses yang dimasukkan ke dalam antrian, sehingga mengurangi overhead yang tidak perlu.
    
3. **Kemungkinan Lebih Cepat daripada Dijkstra**: SPFA bisa lebih cepat daripada algoritma **Dijkstra** dalam beberapa graf yang sangat besar dengan banyak edge, tergantung pada struktur graf tersebut.
    

### Kekurangan SPFA:

- **Dapat Mengalami Kinerja Buruk** pada Graf Tertentu: Walaupun SPFA lebih cepat dalam banyak kasus, pada graf tertentu (misalnya graf dengan banyak siklus negatif) bisa menjadi lebih lambat daripada Bellman-Ford.
    
- **Tidak Menjamin Kinerja Terbaik di Semua Kasus**: Dalam graf dengan banyak edge atau struktur tertentu, SPFA mungkin tidak selalu lebih cepat dari Bellman-Ford atau algoritma lainnya.
    

### Function SPFA:

```cpp
vector<int> spfa(int n, vector<vector<int>>& flights, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (auto& edge : adj[node]) {
            int v = edge.first, weight = edge.second;
            if (dist[node] + weight < dist[v]) {
                dist[v] = dist[node] + weight;
                q.push(v);  // Memasukkan node yang jaraknya diperbarui
            }
        }
    }

    return dist;
}
```

### Kesimpulan:

- SPFA adalah algoritma yang lebih efisien daripada Bellman-Ford untuk graf yang jarang, terutama dalam hal waktu komputasi.
    
- Algoritma ini mengoptimalkan pendekatan Bellman-Ford dengan hanya memproses node yang jaraknya diperbarui, mengurangi overhead.
    
- SPFA merupakan algoritma yang sangat populer dalam banyak aplikasi _shortest path_, terutama dalam graf dengan banyak node dan sedikit edge.