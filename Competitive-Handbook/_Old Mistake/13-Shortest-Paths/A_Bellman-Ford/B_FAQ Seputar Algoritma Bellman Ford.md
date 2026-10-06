---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 13TH-SPBF-0002
nama_algoritma: Bellman Ford Algorithm
kategori_algoritma: Graph - Shortest Path
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen & programmiz.com & geeksforgeeks.com & chatgpt.com"
date_learned: 2025-05-04T16:10:00
tags:
  - graph-algorithm
  - shortest-paths
  - bellman-ford
---
#graph-algorithm #shortest-paths #bellman-ford 

---
# FAQ Seputar Algoritma Bellman Ford
## 1 | Apakah perlu disorting dulu supaya rapi outputnya?
> Hei, apakah algoritma bellman ford harus disorting dulu supaya outputnya rapi, seperti dfs dan bfs? atau tidak perlu?

### ❓ Apakah Bellman-Ford harus di-_sorting_ dulu agar outputnya rapi?

**Jawaban: Tidak perlu.**

---

### 🔍 Penjelasan:

**Bellman-Ford** adalah algoritma untuk mencari _single source shortest path_, artinya:

- Fokusnya hanya pada menghitung **jarak terpendek** dari satu titik ke semua titik lainnya.
    
- Tidak ada traversal berbasis urutan seperti pada **DFS** (preorder/postorder) atau **BFS** (level-order).
    
- Ia hanya melakukan **relaxation** terhadap semua edge sebanyak _(V - 1)_ kali, tanpa memperhatikan urutan node atau edge.
    

---

### 🧾 Tapi bagaimana jika ingin output-nya rapi?

Kalau kamu **ingin** hasil akhir (misalnya `vector<int> dist`) dicetak dalam urutan tertentu (misalnya: dari vertex 0 ke N-1), maka:

- Kamu hanya perlu **mengurutkan saat mencetak** hasilnya, **bukan saat menjalankan algoritmanya**.
    

Contoh:

```cpp
for (int i = 0; i < dist.size(); i++) {
    cout << "Jarak dari src ke " << i << ": " << dist[i] << endl;
}
```

---

### 🔁 Kesimpulan:

- **Tidak perlu sorting** untuk Bellman-Ford agar hasilnya benar.
    
- **Sorting hanya opsional** kalau kamu ingin output yang lebih rapi atau terurut berdasarkan indeks simpul.
    

## 2 | Apakah bisa jika sumbernya tidak dari 0?
> Jika di referensi sumbernya adalah `0`, apakah bisa jika sumbernya dari node lain?

Iya, **bisa banget!** Di Bellman-Ford, **kamu bebas memilih sumber (source) dari node manapun**, tidak harus dari node 0.

---

### 🔧 Penjelasan:

Di Bellman-Ford, kita inisialisasi jarak (`dist`) sebagai berikut:

```cpp
vector<int> dist(V, 1e8); // semua node dianggap belum diketahui jaraknya
dist[src] = 0; // node sumber ditetapkan punya jarak 0 ke dirinya sendiri
```

Bagian penting di sini adalah `dist[src] = 0;`, dan `src` bisa bernilai **0, 1, 2, ..., V-1**, tergantung simpul mana yang kamu pilih sebagai **sumber**.

---

### 📌 Contoh:

Misal kamu punya 5 simpul (`0, 1, 2, 3, 4`) dan kamu ingin mencari jarak terpendek **dari node 3**, kamu tinggal panggil:

```cpp
bellmanFord(5, edges, 3);
```

Dan algoritma akan menghitung jarak dari node 3 ke semua simpul lainnya.

---

### 🧠 Singkatnya:

- **Source tidak harus 0**, bisa dari simpul manapun.
    
- Pastikan saat memanggil fungsi `bellmanFord(V, edges, src)`, kamu memberikan nilai `src` sesuai node yang kamu inginkan sebagai titik awal.
    

## 3 | Algoritma bellman ford itu bisa udirected dan directed kan?


### 🔍 Jawaban singkat:

**Bellman-Ford bisa digunakan untuk**:

- **Directed graph** ✅
    
- **Undirected graph** ✅
    

TAPI... ada **hal penting** yang harus kamu perhatikan tergantung jenis graph-nya:

---

### 📌 1. **Directed Graph (graf berarah)** — _natural case untuk Bellman-Ford_

- Ini **kasus yang paling umum dan ideal** untuk Bellman-Ford.
    
- Tiap edge hanya berlaku satu arah, misalnya `u → v` saja.
    
- Langsung cocok digunakan tanpa perubahan.
    

---

### 📌 2. **Undirected Graph (graf tak berarah)** — _butuh perlakuan khusus_

- Karena edge-nya dua arah (`u - v` berarti `u → v` dan `v → u`), kamu harus **masukkan dua edge ke dalam edge list**.
    

#### Contoh:

Jika input edge dari user adalah:

```
0 1 3
```

Kamu harus masukkan ke edge list:

```cpp
edges.push_back({0, 1, 3});
edges.push_back({1, 0, 3});
```

Karena di undirected graph, kamu bisa pergi dari 0 ke 1 **dan** dari 1 ke 0.

---

### ⚠️ Catatan untuk Undirected Graph:

- **Hati-hati jika ada edge negatif**, karena:
    
    - **Undirected graph + edge negatif = kemungkinan besar negatif cycle**!
        
    - Contoh: `(0 - 1)` dengan weight `-5` akan jadi dua edge: `0 → 1` dan `1 → 0`, membentuk siklus negatif hanya dari satu edge.
        

Jadi, Bellman-Ford tetap bisa jalan di undirected graph, tapi **pastikan tidak ada edge negatif** kalau tidak ingin siklus negatif palsu.

---

### ✅ Kesimpulan:

|Jenis Graph|Cocok untuk Bellman-Ford?|Catatan|
|---|---|---|
|Directed Graph|✅ Ya|Langsung gunakan. Ideal.|
|Undirected Graph|✅ Ya|Tapi edge harus dimasukkan dua arah; hati-hati dengan edge negatif.|
## 3.1 | Jadi jika ada edge -1 aja, udah ngga bisa tuh undirected? 

🟡 **Iya, tepat sekali — jika ada edge negatif (misalnya `-1`) dalam undirected graph, itu bisa langsung bikin masalah serius.**

---

### 📉 Kenapa?

Misal kamu punya **graf tak berarah** dengan satu edge:

```
0 --(-1)-- 1
```

Karena ini **undirected**, artinya kamu punya **dua** edge:

- `0 → 1` dengan bobot `-1`
    
- `1 → 0` dengan bobot `-1`
    

➡️ Ini secara tidak langsung membentuk **siklus negatif**:

```
0 → 1 → 0 → 1 → 0 → ...  (dengan total berat -2, -3, dst)
```

Dan karena Bellman-Ford dirancang untuk **mendeteksi siklus negatif**, maka:

- Ia akan selalu mendeteksinya di undirected graph dengan edge negatif
    
- Padahal itu bukan “siklus” dalam arti biasa — hanya hasil dari dua arah dari satu edge saja
    

---

### ❌ Jadi:

**Undirected graph dengan edge negatif = hampir pasti Bellman-Ford akan gagal.**

---

### ✅ Solusi:

- Kalau kamu **perlu menggunakan Bellman-Ford**, **gunakan directed graph saja**.
    
- Kalau graph kamu memang **undirected dan ada edge negatif**, maka **algoritma Bellman-Ford tidak cocok**.
    
    - Alternatif: coba lihat **Johnson’s algorithm** (advanced, pakai Bellman-Ford di awal), atau pertimbangkan algoritma khusus untuk graf tertentu.
        

---

### 🔧 Kesimpulan praktis:

|Jenis Graf|Ada Edge Negatif?|Gunakan Bellman-Ford?|
|---|---|---|
|**Directed**|✅ Boleh|✅ Ya|
|**Undirected**|❌ Tidak|✅ Boleh|
|**Undirected**|✅ Ya|❌ Hindari|

## 4 | Nah jika directed, tapi ada beberapa node yang tidak bisa diakses karena edge nya berlawanan, nanti outputnya apa?

Bagus! Kalau di **directed graph**, ada beberapa node yang tidak bisa diakses dari sumber karena arah edge yang tidak sesuai, maka **output-nya akan berupa nilai tak terhingga** untuk node-node yang tidak dapat dijangkau.

---

### 🔍 Penjelasan:

Saat kamu menggunakan algoritma **Bellman-Ford** di directed graph, prosesnya seperti ini:

1. **Inisialisasi**: Setiap node selain sumber akan di-set ke **tak terhingga** (misalnya `1e9`).
    
2. **Relaxasi**: Jika sebuah node tidak dapat dijangkau dari sumber, maka **jaraknya tetap tak terhingga** karena tidak ada jalur yang mengarah ke node tersebut.
    

### 📌 Output:

- Untuk node yang **dapat dijangkau**: Jarak akan terupdate dengan benar.
    
- Untuk node yang **tidak dapat dijangkau**: Jarak tetap di `1e9` (atau nilai besar lainnya yang menandakan tak terhingga).
    

### 📝 Contoh:

Misalkan graf kamu adalah sebagai berikut (digraph):

```
S → A → B → C
|         ↑
↓         |
D ←──────┘
```

Dan sumbernya adalah **S** (`src = 0`), tapi **C** tidak bisa dijangkau dari **S** karena tidak ada jalur yang mengarah dari **S** ke **C**. Maka, output-nya bisa seperti ini:

#### Output:

```
Jarak dari S ke S: 0
Jarak dari S ke A: 3
Jarak dari S ke B: 5
Jarak dari S ke C: 1e9 (atau tak terhingga)
Jarak dari S ke D: 6
```

#### Penjelasan:

- **S → A** dengan jarak `3` (langsung).
    
- **A → B** dengan jarak `2`, jadi **S → B** = 3 + 2 = `5`.
    
- **C** tidak dapat dijangkau dari **S**, jadi **dist[C] = 1e9** (tak terhingga).
    
- **D** dapat dijangkau melalui **S → D** dengan jarak `6`.
    

### ⚠️ Penting:

- **Jika ada banyak node yang tidak dapat dijangkau**, output untuk node-node itu akan tetap **1e9** (atau angka besar lainnya, tergantung implementasi).
    

---

### 🧠 Kesimpulan:

- **Node yang tidak dapat dijangkau** oleh sumber akan punya jarak **tak terhingga** (`1e9` atau nilai yang sangat besar) setelah algoritma selesai dijalankan.
    
- **Tidak perlu sorting** untuk output-nya, cukup cek nilai `dist[]` yang dihasilkan.
    

Mau coba dengan contoh kode atau penjelasan tambahan?