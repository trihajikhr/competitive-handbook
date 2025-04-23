---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 
nama_algoritma: 
kategori_algoritma: 
kesulitan: 🥉 easy 🥈 medium 🥇 hard
time_complexity: 🟢 O(1) 🔵 O(log n) 🟡 O(√n) 🟠 O(n) 🟤 O(n log n) 🟣 O(n²) 🟧 O(n³) 🔴 O(2ⁿ) ⚫ O(n!) ⚪O(formula)
memory_complexity: 🟢 O(1) 🔵 O(log n) 🟡 O(√n) 🟠 O(n) 🟤 O(n log n) 🟣 O(n²) 🟧 O(n³) 🔴 O(2ⁿ) ⚫ O(n!) ⚪O(formula) ✅ → Stable ❌ → Unstable
sumber: 
date_learned: 
tags:
---
#tag #tag #tag 

---
# SPFA Bellman Ford Algorithm
**SPFA (Shortest Path Faster Algorithm)** adalah algoritma yang lebih cepat daripada **Bellman-Ford** untuk mencari jarak terpendek dalam graf berbobot, tetapi dengan prinsip yang mirip. SPFA sering dianggap sebagai pengembangan dari Bellman-Ford, dengan menggunakan **queue** (biasanya **queue berbasis prioritas** atau **deque**) untuk meningkatkan efisiensi dalam memperbarui jarak terpendek pada setiap iterasi.

### Perbedaan Utama dengan Bellman-Ford:

1. **Bellman-Ford**: Setiap iterasi memperbarui jarak untuk semua sisi (edges) dalam graf, tanpa mempertimbangkan apakah sebuah sisi benar-benar perlu diproses lagi. Ini mengarah pada waktu eksekusi yang lebih lambat terutama untuk graf yang jarang (sparse graph).
    
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
    

### Pseudocode SPFA:

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