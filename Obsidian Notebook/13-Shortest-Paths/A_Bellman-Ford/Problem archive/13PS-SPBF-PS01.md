---
obsidianUIMode: preview
note_type: problem set
id_problem: 13PS-SPBF-PS01
judul_problem: Penerbangan termurah dengan K stop
sumber: leetcode.com
kategori_problem: 📊 problem_statement
kesulitan: 🥈 medium
time_complexity: 🟢 O(1) 🔵 O(log n) 🟡 O(√n) 🟠 O(n) 🟤 O(n log n) 🟣 O(n²) 🟧 O(n³) 🔴 O(2ⁿ) ⚫ O(n!) ⚪O(formula)
memory_complexity: 🟢 O(1) 🔵 O(log n) 🟡 O(√n) 🟠 O(n) 🟤 O(n log n) 🟣 O(n²) 🟧 O(n³) 🔴 O(2ⁿ) ⚫ O(n!) ⚪O(formula) ✅ → Stable ❌ → Unstable
status: ❌ unsolved ⏳ progress 🏆 solved
date_solved: 2025-04-17T15:59:00
pendekatan: bellman ford algorithm
tags:
  - graph-algorithm
  - shortest-paths
  - bellman-ford
  - heap
  - depth-first-search
  - breadth-first-search
  - dynamic-programming
---
Link problem: [Cheapest Flights Within K Stops - LeetCode](https://leetcode.com/problems/cheapest-flights-within-k-stops/description/)

#graph-algorithm #shortest-paths #bellman-ford #dynamic-programming #heap #depth-first-search #breadth-first-search

---
# Penerbangan termurah dengan K stop
Time limit: -
Memory limit: -


Terdapat `n` kota yang dihubungkan oleh sejumlah penerbangan. Kamu diberikan sebuah array `flights` di mana `flights[i] = [fromi, toi, pricei]` menunjukkan bahwa terdapat penerbangan dari kota `fromi` ke kota `toi` dengan biaya `pricei`.

Kamu juga diberikan tiga buah bilangan bulat `src`, `dst`, dan `k`. Kembalikan harga termurah dari `src` ke `dst` dengan **maksimal `k` pemberhentian**. Jika **tidak ada rute seperti itu**, kembalikan `-1`.

---

### Contoh 1:
![[13PS-SPBF-PS01-1.png]]

**Input**:  
`n = 4`  
`flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]`  
`src = 0`  
`dst = 3`  
`k = 1`

**Output**: `700`

**Penjelasan**:  
Graf seperti yang ditunjukkan di atas.  
Jalur optimal dengan **maksimal 1 pemberhentian** dari kota 0 ke 3 ditandai dengan warna merah dan memiliki biaya `100 + 600 = 700`.  
Perhatikan bahwa jalur melalui kota `[0,1,2,3]` lebih murah, tetapi tidak valid karena menggunakan **2 pemberhentian**.

---

### Contoh 2:
![[13PS-SPBF-PS01-2.png]]
**Input**:  
`n = 3`  
`flights = [[0,1,100],[1,2,100],[0,2,500]]`  
`src = 0`  
`dst = 2`  
`k = 1`

**Output**: `200`

**Penjelasan**:  
Graf seperti yang ditunjukkan di atas.  
Jalur optimal dengan **maksimal 1 pemberhentian** dari kota 0 ke 2 ditandai dengan warna merah dan memiliki biaya `100 + 100 = 200`.

---

### Contoh 3:
![[13PS-SPBF-PS01-3.png]]
**Input**:  
`n = 3`  
`flights = [[0,1,100],[1,2,100],[0,2,500]]`  
`src = 0`  
`dst = 2`  
`k = 0`

**Output**: `500`

**Penjelasan**:  
Graf seperti yang ditunjukkan di atas.  
Jalur optimal **tanpa pemberhentian** dari kota 0 ke 2 ditandai dengan warna merah dan memiliki biaya `500`.

---

### Batasan (Constraints):

- `1 <= n <= 100`
    
- `0 <= flights.length <= (n * (n - 1) / 2)`
    
- `flights[i].length == 3`
    
- `0 <= fromi, toi < n`
    
- `fromi != toi`
    
- `1 <= pricei <= 10⁴`
    
- Tidak akan ada penerbangan ganda antara dua kota.
    
- `0 <= src, dst, k < n`
    
- `src != dst`
    

# Jawaban
Jawaban yang sudah lumayan optimal dan efisien:

```cpp
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(k + 2, vector<int>(n, INT_MAX));

        dp[0][src]=0;

        for(int i=1; i<= k+1; ++i){
            dp[i]=dp[i-1];

            for(auto& flight: flights){
                int u=flight[0], v=flight[1], price=flight[2];

                if(dp[i-1][u] != INT_MAX && dp [i-1][u] + price < dp[i][v]){
                    dp[i][v] = dp[i-1][u] + price;
                }
            }
        }
        return dp[k+1][dst] == INT_MAX ? -1 : dp[k+1][dst];
    }
};
```

Time complexity: $O(k \cdot E)$
Memory complexity: $O(k \cdot n)$
## Jawaban efektif
Jawaban ini bekerja dengan runtime dan memoy terkecil:

```cpp
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        int E = flights.size();
        for(int i=0 ; i<E ; i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adj[u].push_back({v , wt});
        }
        queue<pair<int , pair<int , int>>>q;
        vector<int>dist(n , 1e9);
        dist[src]=0;
        q.push({0 , {src , 0  }});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            
             if (stops > k) continue;
             for(auto iter : adj[node] ){
                int adjNode = iter.first;
                int edw = iter.second;
                  if((cost + edw < dist[adjNode]) && stops<=k){
                    dist[adjNode]= cost + edw;
                    q.push({stops+1 , {adjNode, cost + edw}});
                  }
                 
             }

        }
        return dist[dst]==1e9? -1 : dist[dst];
    }
};
```

Time complexity: $O()$
Memory complexity: $O()$

### Solusi efektif dan perbedaanya
Kedua solusi yang kamu tunjukkan memiliki pendekatan yang mirip, yaitu mencari jalur dengan biaya terendah dari `src` ke `dst` dengan batasan jumlah pemberhentian (`k`). Namun, keduanya menggunakan pendekatan yang berbeda. Berikut adalah perbandingan antara keduanya:

#### 1. Solusi pertama (Bellman-Ford Modified)

- **Pendekatan**: Menggunakan **Bellman-Ford** yang dimodifikasi dengan iterasi sebanyak `k+1` kali. Setiap iterasi memperbarui harga termurah ke kota lain.
    
- **Waktu**: O(k * E), dengan `k` sebagai jumlah pemberhentian yang diizinkan dan `E` sebagai jumlah penerbangan.
    
- **Ruang**: O(k * n), karena kita menyimpan harga untuk setiap kota dan setiap jumlah pemberhentian.
    
- **Keunggulan**: Solusi ini lebih mudah dipahami jika kamu sudah familiar dengan Bellman-Ford dan cocok jika kamu ingin memperbarui jarak kota dengan beberapa iterasi relaksasi.
    
- **Kelemahan**: Membutuhkan banyak iterasi, terutama jika jumlah pemberhentian (`k`) sangat besar, yang mungkin bisa mempengaruhi efisiensi dalam kasus-kasus tertentu.
    

#### 2. Solusi kedua (Modified BFS)

- **Pendekatan**: Menggunakan **BFS yang dimodifikasi** dengan antrian dan membatasi pemberhentian dengan melacak jumlah pemberhentian yang telah dilakukan. Penerbangan yang lebih murah diperbarui jika ditemukan jalur yang lebih pendek.
    
- **Waktu**: O(E * k), karena kita menggunakan BFS untuk memproses semua penerbangan dan membatasi langkah berdasarkan jumlah pemberhentian.
    
- **Ruang**: O(n), karena kita hanya menyimpan jarak termurah untuk setiap kota.
    
- **Keunggulan**: Menggunakan BFS yang lebih alami dengan antrian. Lebih mudah untuk mengontrol jumlah pemberhentian dalam satu iterasi.
    
- **Kelemahan**: Memerlukan antrian dan struktur data yang lebih rumit. Selain itu, ada risiko lebih banyak memori yang digunakan untuk antrian.
    

#### Perbandingan Kelebihan dan Kekurangan

|Faktor|**Solusi Bellman-Ford**|**Solusi BFS Dimodifikasi**|
|---|---|---|
|**Pendekatan**|Bellman-Ford dengan relaksasi iteratif|BFS dengan antrian dan kontrol pemberhentian|
|**Kompleksitas Waktu**|O(k * E)|O(E * k)|
|**Kompleksitas Ruang**|O(k * n)|O(n)|
|**Kemudahan Implementasi**|Mudah dipahami jika sudah familiar dengan Bellman-Ford|Lebih kompleks dengan antrian dan pelacakan pemberhentian|
|**Efisiensi untuk Kasus Besar**|Mungkin lebih lambat untuk `k` besar|Lebih efisien dengan kontrol pemberhentian yang lebih ketat|

#### Kesimpulan:

- **Solusi Bellman-Ford** lebih baik jika kamu lebih suka bekerja dengan konsep relaksasi dan algoritma yang sudah sangat dikenal. Ini memberikan kontrol yang baik terhadap semua langkah yang dilakukan untuk relaksasi jarak.
    
- **Solusi BFS dimodifikasi** lebih efisien dalam hal memori, dan menggunakan struktur antrian yang lebih natural untuk melacak jarak terpendek dengan pemberhentian yang terbatas. Jika kamu lebih suka pendekatan yang berbasis graf terarah dan kontrol pemberhentian yang lebih jelas, maka solusi ini lebih baik.
    

Jika **k** tidak terlalu besar dan jumlah penerbangan relatif kecil, maka solusi BFS yang dimodifikasi mungkin lebih efisien dalam implementasi dan penggunaan memori. Namun, jika **k** sangat besar, maka Bellman-Ford dapat lebih baik dalam menangani banyak iterasi relaksasi.

Namun, pada dasarnya kedua solusi memiliki kompleksitas yang serupa dalam hal waktu dan memori, jadi pilihan antara keduanya lebih bergantung pada preferensi dan pemahaman terhadap algoritma yang ada.
# Editorial 
Untuk menyelesaikan masalah ini, kita bisa menggunakan pendekatan **modified Bellman-Ford** atau **Breadth-First Search (BFS)** dengan sedikit modifikasi untuk membatasi jumlah pemberhentian (`k`). Berikut adalah solusi menggunakan **Bellman-Ford** karena kita perlu mempertimbangkan maksimal `k` pemberhentian.

### Pendekatan

- Kita akan menggunakan array `dp[k+1][n]` di mana:
    
    - `dp[i][j]` menyimpan harga termurah untuk mencapai kota `j` dengan tepat `i` pemberhentian.
        
    - `dp[0][src] = 0` (harga dari kota sumber ke dirinya sendiri adalah 0).
        
    - Lakukan iterasi sebanyak `k+1` kali, dan pada setiap iterasi lakukan relaksasi terhadap semua penerbangan.
        

### Langkah-langkah

1. Inisialisasi array `dp` untuk menyimpan harga termurah dari sumber ke kota lain untuk setiap jumlah pemberhentian.
    
2. Lakukan iterasi sebanyak `k+1` kali:
    
    - Untuk setiap penerbangan, relaksasi jarak ke kota tujuan jika jalur baru lebih murah.
        
3. Hasil akhirnya akan ada di `dp[k+1][dst]` yang menyimpan harga termurah dengan maksimal `k` pemberhentian.
    

### Solusi dalam C++:

```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    // dp[i][j] adalah harga termurah untuk mencapai kota j dengan i pemberhentian
    vector<vector<int>> dp(k + 2, vector<int>(n, INT_MAX));
    
    // harga dari src ke src adalah 0, tanpa pemberhentian
    dp[0][src] = 0;
    
    // Relaksasi selama k+1 iterasi
    for (int i = 1; i <= k + 1; ++i) {
        // Salin harga dari iterasi sebelumnya
        dp[i] = dp[i - 1];
        
        // Cek penerbangan untuk relaksasi
        for (auto& flight : flights) {
            int u = flight[0], v = flight[1], price = flight[2];
            
            // Jika ada harga untuk mencapai kota u, coba relaksasi ke kota v
            if (dp[i - 1][u] != INT_MAX && dp[i - 1][u] + price < dp[i][v]) {
                dp[i][v] = dp[i - 1][u] + price;
            }
        }
    }

    // Harga termurah ke dst dengan maksimal k pemberhentian
    return dp[k + 1][dst] == INT_MAX ? -1 : dp[k + 1][dst];
}

int main() {
    int n = 4;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0, dst = 3, k = 1;
    
    int result = findCheapestPrice(n, flights, src, dst, k);
    cout << "Cheapest price: " << result << endl;

    return 0;
}
```

### Penjelasan:

- `dp[i][j]`: menyimpan harga termurah untuk mencapai kota `j` dengan **i pemberhentian**.
    
- **Iterasi**: Kita melakukan iterasi sebanyak `k+1` kali, yang mewakili jumlah pemberhentian yang diizinkan.
    
- Setiap iterasi, kita memperbarui `dp[i][v]` untuk setiap penerbangan `(u, v)` jika harga baru lebih murah daripada yang sudah ada.
    
- Hasil akhir adalah harga termurah untuk mencapai `dst` dengan maksimal `k` pemberhentian, yang ada di `dp[k+1][dst]`.
    

### Kompleksitas:

- **Waktu**: O(k * E), di mana `E` adalah jumlah penerbangan (edges) dan `k` adalah jumlah pemberhentian maksimal.
    
- **Ruang**: O(k * n), karena kita menyimpan harga untuk setiap kota dan setiap jumlah pemberhentian.
    

### Contoh:

Dengan input:

```cpp
n = 4;
flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
src = 0;
dst = 3;
k = 1;
```

Hasil output:

```
Cheapest price: 700
```

Ini sesuai dengan contoh yang kamu berikan, di mana jalur optimal dari kota 0 ke kota 3 dengan 1 pemberhentian adalah 700.

# Informasi tambahan
Algoritma Bellman-Ford memang memiliki kompleksitas waktu yang relatif tinggi dibandingkan dengan algoritma lainnya, seperti Dijkstra. Namun, ada beberapa cara untuk mencoba meningkatkan efisiensi implementasinya atau memilih pendekatan yang lebih tepat berdasarkan karakteristik graf yang dihadapi. Mari kita bahas beberapa cara untuk mengoptimalkan algoritma Bellman-Ford atau mempertimbangkan alternatif lain yang mungkin lebih efisien:

### 1. Early Stopping (Berhenti Lebih Cepat)

- **Pengoptimalan dengan Pengecekan Perubahan**: Salah satu cara untuk mengurangi waktu eksekusi adalah dengan menggunakan teknik _early stopping_. Jika dalam iterasi tertentu tidak ada perubahan pada jarak (distance), artinya sudah tidak ada lagi yang perlu diperbarui, dan kita bisa menghentikan algoritma lebih awal.
    
- **Implementasi Early Stopping**: Sebelum melanjutkan ke iterasi berikutnya, kamu bisa mengecek apakah ada perubahan pada jarak yang dihitung di setiap iterasi. Jika tidak ada perubahan pada jarak di seluruh iterasi, kita bisa berhenti lebih cepat daripada melakukan iterasi penuh.
    

```cpp
for (int i = 0; i < n - 1; i++) {
    bool updated = false; // flag untuk cek perubahan
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], weight = edge[2];
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            dist[v] = dist[u] + weight;
            updated = true;
        }
    }
    // Jika tidak ada perubahan, kita berhenti lebih awal
    if (!updated) break;
}
```

Teknik ini dapat mengurangi iterasi yang tidak perlu jika graf tidak memiliki banyak siklus atau jika jarak sudah stabil lebih cepat.

### 2. Penggunaan Struktur Data Lebih Canggih

- **Menggunakan Queue untuk Pengoptimalan (SPFA - Shortest Path Faster Algorithm)**: SPFA adalah algoritma yang mirip dengan Bellman-Ford namun menggunakan struktur data **queue** untuk mempercepat pembaruan jarak. Ini memanfaatkan ide dari algoritma Bellman-Ford tetapi dengan pendekatan yang lebih dinamis dalam memperbarui node yang perlu dieksplorasi.
    
    Pada SPFA, setiap node hanya akan dieksplorasi jika ada kemungkinan untuk memperbarui jaraknya, dan node yang sudah tidak bisa diperbarui lagi tidak akan dimasukkan kembali ke dalam queue.
    

```cpp
// SPFA menggunakan priority queue untuk optimasi
#include <queue>
#include <vector>
#include <climits>

using namespace std;

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

SPFA dapat berjalan lebih cepat daripada Bellman-Ford dalam banyak kasus, terutama pada graf yang jarang (sparse graph).

### 3. Preprocessing untuk Menghindari Pengulangan yang Tidak Perlu

- **Menghindari Perhitungan Ulang untuk Graf yang Tidak Berubah**: Jika graf yang digunakan adalah graf yang tidak berubah antara eksekusi algoritma, kita bisa menggunakan cache atau hasil perhitungan sebelumnya untuk menghindari komputasi yang sama berulang kali.
    

### 4. Alternatif dengan Dijkstra

Jika graf tidak mengandung edge dengan bobot negatif, **algoritma Dijkstra** adalah pilihan yang lebih efisien dibandingkan dengan Bellman-Ford, dengan kompleksitas waktu O((V + E) log V) menggunakan priority queue. Dijkstra jauh lebih cepat dalam menangani graf yang tidak mengandung siklus negatif.

### 5. Menggunakan Optimasi Berdasarkan Struktur Graf

- **Jika grafnya terhubung secara lengkap (dense graph)**, algoritma Bellman-Ford tetap bisa efektif meskipun lebih lambat dari Dijkstra. Namun, pada graf yang sangat besar dengan banyak edge, pertimbangkan untuk menggunakan algoritma lain atau pendekatan yang lebih efisien untuk permasalahan shortest path.
    
- **Optimasi berbasis heuristik**: Dalam beberapa kasus, kamu bisa menggunakan teknik seperti _A_ (A-star search) yang mengkombinasikan pencarian jalur terpendek dengan heuristik, meskipun ini memerlukan fungsi heuristik yang cocok dan tidak cocok untuk semua kasus.
    

### 6. Penggunaan Parallelism atau Multi-threading

Jika graf sangat besar dan komputasi sangat intensif, beberapa implementasi Bellman-Ford dapat dioptimalkan dengan paralelisasi, meskipun hal ini tidak mudah diimplementasikan pada Bellman-Ford biasa. Kamu bisa mencoba untuk memecah pekerjaan menjadi bagian-bagian kecil dan mengeksekusinya secara paralel untuk meningkatkan kinerja di lingkungan yang mendukung multi-threading.

---

### Kesimpulan

- **Early Stopping** adalah pengoptimalan paling sederhana yang bisa mempercepat algoritma Bellman-Ford dalam beberapa kasus.
    
- **SPFA (Shortest Path Faster Algorithm)** adalah alternatif yang sangat menarik dan biasanya lebih cepat daripada Bellman-Ford karena menggunakan queue dinamis.
    
- Jika graf tidak mengandung edge negatif, **Dijkstra** bisa menjadi alternatif yang lebih efisien.
    
- **Optimasi berbasis struktur graf dan penggunaan paralelisasi** dapat meningkatkan efisiensi lebih lanjut dalam kasus tertentu.
    

Dengan optimasi-optimasi tersebut, kamu bisa meningkatkan kinerja algoritma Bellman-Ford tergantung pada kondisi dan karakteristik graf yang dihadapi.