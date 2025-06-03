---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 12TH-GTDF-S003
nama_algoritma: Depth First Search
kategori_algoritma: Graph Algorithm - Traversal
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen & geeksforgeeks.com"
date_learned: 2025-05-01T17:22:00
tags:
  - graph
  - graph-DFS
  - graph-traversal
---
#graph #graph-traversal #graph-DFS 

---
# Implementasi DFS Directed

**Depth-First Search (DFS)** adalah algoritma dasar untuk mengeksplorasi struktur graf. Pada graf berarah (*directed graph*), DFS dapat dimulai dari suatu titik tertentu dan menjelajahi semua *node* yang terhubung. Algoritma ini juga dapat digunakan untuk memastikan seluruh bagian graf dikunjungi, bahkan jika graf memiliki komponen terpisah (*disconnected sections*). Artikel ini menjelaskan cara kerja DFS ketika dimulai dari satu *node* sumber (*source*) dan bagaimana algoritma ini dapat digunakan untuk mengeksplorasi seluruh graf, termasuk bagian yang terputus.  

## Contoh 1  

**Input:**  
`V = 5, E = 5`,  
`edges = {{1, 2}, {1, 0}, {2, 0}, {2, 3}, {4, 2}}`,  
`source = 1`  

![[C_Implementasi DFS Directed-1.png|500]]


**Output:** `1 2 0 3`  

**Penjelasan Langkah DFS:**  
1. Mulai dari **1**: Tandai sudah dikunjungi. Output: `1`  
2. Pindah ke **2**: Tandai sudah dikunjungi. Output: `2`  
3. Pindah ke **0**: Tandai sudah dikunjungi. Output: `0` (*backtrack* ke **2**)  
4. Pindah ke **3**: Tandai sudah dikunjungi. Output: `3` (*backtrack* ke **2**)  
5. Semua *neighbor* **2** sudah dieksplorasi (*backtrack* ke **1**)  
6. Semua *neighbor* **1** sudah dieksplorasi (proses selesai)  

## Contoh 2

**Input:**  
`V = 5, E = 4`,  
`edges = {{0, 2}, {0, 3}, {2, 4}, {1, 0}}`,  
`source = 2`  

![[C_Implementasi DFS Directed-2.png|500]]

**Output:** `2 4`  

**Penjelasan Langkah DFS:**  
1. Mulai dari **2**: Tandai sudah dikunjungi. Output: `2`  
2. Pindah ke **4**: Tandai sudah dikunjungi. Output: `4` (*backtrack* ke **2**)  
3. Semua *neighbor* **2** sudah dieksplorasi (*backtrack* ke titik awal)  

Berikut terjemahan dalam bahasa Indonesia dengan tetap mempertahankan istilah komputasionalnya:

---

# DFS dari Sumber Tertentu pada Graf Berarah
## DFS Directed Graph - Connected
**Depth-First Search (DFS) dari sumber tertentu** adalah metode untuk mengeksplorasi graf berarah (*directed graph*) dengan memulai dari *vertex* spesifik dan menelusuri setiap *node* sejauh mungkin ke bawah dalam suatu jalur. Jika kita mencapai *vertex* yang tidak memiliki *neighbor* yang belum dikunjungi, kita melakukan *backtrack* ke *vertex* sebelumnya untuk mengeksplorasi jalur lain yang belum dikunjungi. Pendekatan ini sangat berguna untuk tugas-tugas seperti mencari jalur (*finding paths*), memeriksa konektivitas (*checking connectivity*), dan mengeksplorasi semua *node* yang dapat dijangkau dari titik awal.
### Cara Kerja:
1. **Gunakan array boolean `visited`** untuk mencatat *vertex* mana yang sudah dikunjungi. Ini membantu menghindari *infinite loop* ketika graf memiliki siklus (*cycles*).
2. **Gunakan rekursi** untuk mengunjungi semua *neighbor* yang belum dikunjungi dari *source node*:
   - Pertama, tandai *current vertex* sebagai sudah dikunjungi dan proses *vertex* tersebut (misalnya, dengan mencetak nilainya).
   - Kemudian, kunjungi secara rekursif setiap *neighbor* yang belum dikunjungi dari *current vertex*.
   - Jika suatu *vertex* tidak memiliki *neighbor* yang belum dikunjungi, lakukan *backtrack* ke *vertex* sebelumnya untuk mengeksplorasi jalur lain yang belum dikunjungi.
   
Berikut implementasi dari pendekatan di atas:

```cpp
#include <bits/stdc++.h>
using namespace std;

// Fungsi untuk menambahkan edge ke dalam adjacency list
void addEdge(vector<vector<int>> &adj, int s, int t){
    // Tambahkan edge dari simpul s ke simpul t
    adj[s].push_back(t);
}

// Fungsi rekursif untuk traversal DFS
void DFSRec(vector<vector<int>> &adj, vector<bool> &visited, int s){
    // Tandai simpul saat ini sebagai sudah dikunjungi
    visited[s] = true;

    // Cetak simpul saat ini
    cout << s << " ";

    // Kunjungi secara rekursif semua simpul tetangga yang belum dikunjungi
    for (int i : adj[s])
        if (visited[i] == false)
            DFSRec(adj, visited, i);
}

// Fungsi utama DFS yang menginisialisasi array visited
// dan memanggil DFSRec
void DFS(vector<vector<int>> &adj, int s){
    vector<bool> visited(adj.size(), false);
    // Panggil fungsi DFS rekursif
    DFSRec(adj, visited, s);
}

int main(){
    int V = 5;

    // Buat adjacency list untuk graph
    vector<vector<int>> adj(V);

    // Definisikan edge-edge dari graph
    vector<vector<int>> edges={{1, 2}, {1, 0}, {2, 0}, {2, 3}, {4, 2}};

    // Isi adjacency list dengan edge
    for (auto &e : edges)
        addEdge(adj, e[0], e[1]);

    int source = 1;
    cout << "DFS dari simpul sumber: " << source << endl;
    DFS(adj, source);

    return 0;
}
```

### 🧠 Editorial DFS Rekursif (C++): Penjelasan Baris per Baris

```cpp
#include <bits/stdc++.h>
using namespace std;
```

- **Fungsi:** Mengimpor semua pustaka standar C++ (termasuk `iostream`, `vector`, `algorithm`, dll).
    
- **Kegunaan:** Mempermudah saat menulis kode kompetitif tanpa harus mengimpor pustaka satu per satu.
    
- **`using namespace std;`** agar kamu tidak perlu menulis `std::vector`, `std::cout`, dll.
    

---

```cpp
void addEdge(vector<vector<int>> &adj, int s, int t){
    adj[s].push_back(t);
}
```

- **Fungsi:** Menambahkan edge dari simpul `s` ke simpul `t`.
    
- **`adj`** adalah adjacency list, yang diwakili sebagai `vector` dari `vector<int>`.
    
- **`push_back(t)`** berarti simpul `t` dimasukkan ke daftar tetangga dari `s`.
    
- **Catatan:** Ini adalah implementasi _directed graph_. Jika ingin _undirected_, tambahkan juga `adj[t].push_back(s)`.
    

---

```cpp
void DFSRec(vector<vector<int>> &adj, vector<bool> &visited, int s){
    visited[s] = true;
    cout << s << " ";
```

- **Fungsi:** Fungsi rekursif DFS untuk mengunjungi simpul dan semua tetangganya.
    
- **`visited[s] = true;`** menandai bahwa simpul `s` telah dikunjungi.
    
- **`cout << s`** mencetak simpul saat ini (hasil traversal).
    
- **Kenapa rekursif?** Karena DFS menyelami satu jalur sampai akhir sebelum backtrack.
    

---

```cpp
    for (int i : adj[s])
        if (visited[i] == false)
            DFSRec(adj, visited, i);
}
```

- **Fungsi:** Melakukan iterasi terhadap semua tetangga dari simpul `s`.
    
- **Jika tetangga belum dikunjungi**, maka DFS dipanggil secara rekursif pada tetangga tersebut.
    
- **`for (int i : adj[s])`** adalah bentuk modern dari loop untuk setiap elemen dalam `adj[s]`.
    

---

```cpp
void DFS(vector<vector<int>> &adj, int s){
    vector<bool> visited(adj.size(), false);
    DFSRec(adj, visited, s);
}
```

- **Fungsi utama DFS**: menyiapkan struktur data yang dibutuhkan (visited), lalu memulai traversal.
    
- **`visited`** berukuran jumlah simpul (`adj.size()`), semuanya diinisialisasi `false`.
    
- Memanggil `DFSRec()` dengan simpul awal `s`.
    

---

```cpp
int main(){
    int V = 5;
    vector<vector<int>> adj(V);
```

- **Inisialisasi graph**: membuat adjacency list `adj` dengan `V` simpul.
    
- `adj` adalah `vector` dari `vector<int>`, artinya tiap simpul punya daftar tetangga.
    

---

```cpp
    vector<vector<int>> edges={{1, 2}, {1, 0}, {2, 0}, {2, 3}, {4, 2}};
```

- **Daftar edge** yang membentuk graph.
    
- Edge diberikan sebagai pasangan (u, v) artinya dari `u` ke `v`.
    

---

```cpp
    for (auto &e : edges)
        addEdge(adj, e[0], e[1]);
```

- Mengisi adjacency list `adj` menggunakan edge-edge yang telah didefinisikan.
    
- **`auto &e`** mengambil referensi tiap edge agar efisien.
    
- `e[0]` adalah sumber, `e[1]` adalah tujuan dari setiap edge.
    

---

```cpp
    int source = 1; 
    cout << "DFS dari simpul sumber: " << source << endl;
    DFS(adj, source);
```

- Menentukan simpul awal (`source`) untuk DFS.
    
- Mencetak informasi bahwa DFS dimulai dari `source`.
    
- Memanggil fungsi DFS yang sudah ditentukan.
    

---

```cpp
    return 0;
}
```

- Mengakhiri program utama.
    
- Nilai `0` mengindikasikan bahwa program berjalan dengan sukses.
    

---

### 📌 Kesimpulan

- **Struktur kode ini modular** dan mudah dimengerti.
    
- Sangat cocok untuk memahami dasar **DFS rekursif pada graph berarah**.
    
- Untuk **graph tak berarah**, tinggal ubah fungsi `addEdge()` agar menambahkan dua arah.
    

---

## Mengganti Fungsi untuk membuat DFS Directed - Disconnected
Jika ingin mendukung *disconnected graph*, kamu perlu memodifikasi fungsi `DFS()` agar memanggil DFS untuk setiap simpul yang belum dikunjungi:

```cpp
void DFS(vector<vector<int>> &adj){
    vector<bool> visited(adj.size(), false);
    for (int i = 0; i < adj.size(); ++i) {
        if (!visited[i]) {
            DFSRec(adj, visited, i);
        }
    }
}
```

**Modifikasi kode seperti berikut** akan membuat program DFS kamu **menjelajahi seluruh simpul**, termasuk yang **tidak terhubung langsung** ke simpul sumber—alias menangani **disconnected graph**.

### ✅ Penjelasan:


- Alih-alih hanya mulai DFS dari satu `source`, program akan **memeriksa semua simpul**.
    
- Jika suatu simpul belum dikunjungi (`!visited[i]`), maka **DFS akan dijalankan dari sana**.
    
- Dengan begitu, **semua komponen graph**, baik yang terhubung maupun tidak, akan dijelajahi.
    

### 📌 Contoh:

Misalnya, untuk graph seperti ini:

```bash
Komponen 1: 0 - 1 - 2  
Komponen 2: 3 - 4
```

Kalau kamu hanya memulai DFS dari `0`, simpul `3` dan `4` tidak akan dikunjungi. Tapi dengan pendekatan ini, setelah `0`, `1`, dan `2` selesai, DFS akan lanjut ke simpul `3` dan menyusuri `4`.

## DFS Directed - Disconnected
Pada graf berarah (*directed graph*), sisi-sisi memiliki arah tertentu yang berarti kita hanya dapat berpindah dari satu *vertex* ke *vertex* lain mengikuti arah sisi tersebut. Sebuah graf disebut terputus (*disconnected*) ketika tidak semua *vertex* dapat dijangkau dari satu *vertex* tunggal.

Implementasi sebelumnya menerima *source* sebagai input dan hanya mencetak *vertex-vertex* yang dapat dijangkau dari *source* tersebut. Pada kasus graf terputus, implementasi itu tidak akan mencetak semua *vertex*. Sekarang kita akan membahas algoritma yang dapat mencetak semua *vertex* tanpa memerlukan *source* tertentu dan dapat bekerja pada graf yang mungkin terputus.

Untuk menangani graf seperti ini menggunakan DFS, kita harus memastikan bahwa algoritma DFS dimulai dari setiap *vertex* yang belum dikunjungi. Pendekatan ini memungkinkan penjelajahan semua komponen (*components*) dalam graf secara menyeluruh.

```cpp
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int s, int t){
    adj[s].push_back(t); // Tambahkan edge dari simpul s ke t
}

// Fungsi rekursif untuk traversal DFS
void DFSRec(vector<vector<int>> &adj, vector<bool> &visited,int s){
    // Tandai simpul saat ini sebagai telah dikunjungi
    visited[s] = true;

    // Cetak simpul saat ini
    cout << s << " ";

    // Kunjungi semua simpul tetangga yang belum dikunjungi secara rekursif
    for (int i : adj[s])
        if (visited[i] == false)
            DFSRec(adj, visited, i);
}

// Fungsi utama DFS untuk melakukan DFS pada seluruh graph
void DFS(vector<vector<int>> &adj){
    vector<bool> visited(adj.size(), false);

    // Perulangan ke semua simpul untuk menangani graph yang terputus (disconnected)
    for (int i = 0; i < adj.size(); i++){
        if (visited[i] == false){
            // Jika simpul i belum dikunjungi,
            // lakukan DFS dari simpul tersebut
            DFSRec(adj, visited, i);
        }
    }
}

int main(){
    int V = 6;
    // Buat daftar adjacency untuk graph
    vector<vector<int>> adj(V);

    // Definisikan edge-edge dari graph
    vector<vector<int>> edges = {{1, 2}, {2, 0}, {0, 3}, {4, 5}};

    // Isi daftar adjacency dengan edge-edge tersebut
    for (auto &e : edges)
        addEdge(adj, e[0], e[1]);

    cout << "DFS lengkap dari graph:" << endl;
    DFS(adj);

    return 0;
}
```

## Editorial

### 📘 Tujuan Program

Program ini mengimplementasikan algoritma **Depth First Search (DFS)** untuk melakukan traversal pada **graf berarah (directed graph)**. Algoritma disusun sedemikian rupa agar bisa menjelajahi **seluruh simpul (vertices)** meskipun graf tersebut memiliki beberapa **komponen tidak terhubung (disconnected components)**.

---

### 📌 Struktur dan Penjelasan Kode

### 1. Library dan Namespace

```cpp
#include <bits/stdc++.h>
using namespace std;
```

- `#include <bits/stdc++.h>`: Mengimpor semua library standar C++.
    
- `using namespace std;`: Agar tidak perlu mengetik `std::` berkali-kali.
    

---

### 2. Fungsi untuk Menambahkan Edge

```cpp
void addEdge(vector<vector<int>> &adj, int s, int t){
    adj[s].push_back(t); // Tambahkan edge dari s ke t
}
```

- Menambahkan **satu arah** edge dari vertex `s` ke `t`.
    
- Karena hanya `adj[s]`, ini menjadikan graph **berarah (directed)**.
    
- Adjacency list (`adj`) digunakan untuk menyimpan koneksi antar simpul.
    

---

### 3. Fungsi DFS Rekursif

```cpp
void DFSRec(vector<vector<int>> &adj, vector<bool> &visited, int s){
    visited[s] = true;
    cout << s << " ";
```

- Menandai vertex `s` sebagai telah dikunjungi (`visited[s] = true`).
    
- Mencetak vertex `s`.
    
- Tujuan utamanya adalah melakukan **traversal menyeluruh ke semua tetangga** yang bisa dijangkau dari `s`.
    

```cpp
    for (int i : adj[s])
        if (!visited[i])
            DFSRec(adj, visited, i);
}
```

- Melakukan **rekursi** ke setiap tetangga `i` dari `s` jika belum dikunjungi.
    
- Dengan cara ini, program menyelam sedalam mungkin di jalur DFS sebelum kembali.
    

---

### 4. Fungsi Utama DFS

```cpp
void DFS(vector<vector<int>> &adj){
    vector<bool> visited(adj.size(), false);
```

- Membuat array boolean `visited` dengan ukuran sebanyak jumlah simpul, untuk melacak simpul mana yang sudah dikunjungi.
    

```cpp
    for (int i = 0; i < adj.size(); i++){
        if (!visited[i]){
            DFSRec(adj, visited, i);
        }
    }
}
```

- **Melakukan loop ke semua vertex**. Ini penting agar simpul yang **tidak terhubung** juga tetap dikunjungi.
    
- DFS dipanggil hanya jika simpul tersebut belum dikunjungi.
    

---

### 5. Fungsi `main`

```cpp
int main(){
    int V = 6;
    vector<vector<int>> adj(V);
```

- `V = 6`: Jumlah simpul dalam graf.
    
- `adj(V)`: Inisialisasi adjacency list dengan `V` buah list kosong.
    

```cpp
    vector<vector<int>> edges = {{1, 2}, {2, 0}, {0, 3}, {4, 5}};
```

- Ini adalah daftar **edge berarah**, misalnya `{1, 2}` berarti **edge dari 1 ke 2**.
    
- `{4, 5}` adalah komponen terpisah dari yang lainnya → **graf tidak terhubung**.
    

```cpp
    for (auto &e : edges)
        addEdge(adj, e[0], e[1]);
```

- Menambahkan semua edge ke dalam adjacency list dengan memanggil `addEdge()`.
    

```cpp
    cout << "Complete DFS of the graph:" << endl;
    DFS(adj);
```

- Memanggil fungsi `DFS()` untuk memulai traversal dan mencetak hasilnya.
    

```cpp
    return 0;
}
```

---

### ✅ Output Program

Program akan mencetak seluruh simpul yang bisa dijangkau dalam graf, termasuk dari komponen-komponen yang tidak terhubung langsung.

Contoh output (urutan bisa berbeda tergantung struktur):

```
Complete DFS of the graph:
1 2 0 3 4 5 
```

---

### 📚 Kesimpulan

- Algoritma ini cocok untuk **graf berarah dan tidak terhubung**.
    
- DFS dilakukan pada semua simpul dengan mengecek `visited`, sehingga tidak ada simpul yang terlewat.
    
- Implementasi menggunakan **rekursi**, dan adjacency list sebagai representasi graf.
    

Kalau kamu ingin versi **graf tak berarah**, cukup tambahkan satu baris lagi di `addEdge`:

```cpp
adj[t].push_back(s);
```

