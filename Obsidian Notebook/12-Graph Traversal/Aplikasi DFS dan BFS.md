---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 12TH-GTBF-S001
nama_algoritma: 
kategori_algoritma: Graph Algorithm - Traversal
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen & geeksforgeeks.com"
date_learned: 2025-05-02T09:42:00
tags:
  - graph
  - graph-BFS
  - graph-DFS
  - graph-traversal
---
#graph #graph-DFS #graph-BFS #graph-traversal 

---
# Kekurangan DFS dan BFS
**Depth-First Search (DFS) dan Breadth-First Search (BFS)** adalah dua algoritma traversal/pencarian dalam struktur data pohon atau graf. Berikut kelebihan dan kekurangan masing-masing:

### Depth-First Search (DFS)  
**Kelebihan:**  
1. **Memori lebih hemat** karena hanya menyimpan satu jalur (menggunakan stack, baik rekursif maupun iteratif).  
2. **Lebih cepat menemukan solusi** jika solusi berada di cabang yang dalam.  
3. **Cocok untuk masalah yang memerlukan eksplorasi mendalam**, seperti puzzle, permainan, atau deteksi siklus.  

**Kekurangan:**  
1. **Tidak optimal untuk mencari jalur terpendek** dalam graf tanpa bobot (unweighted graph).  
2. **Bisa terjebak dalam loop** jika tidak menggunakan penanda node yang sudah dikunjungi (visited).  
3. **Tidak garansi menemukan solusi terdekat** karena menjelajah sedalam mungkin terlebih dahulu.  

---

### Breadth-First Search (BFS)  
**Kelebihan:**  
1. **Selalu menemukan jalur terpendek** dalam graf tanpa bobot (unweighted graph).  
2. **Tidak terjebak dalam loop** karena mengeksplorasi level per level.  
3. **Cocok untuk pencarian node terdekat**, seperti rute terpendek atau jaringan sosial.  

**Kekurangan:**  
1. **Memori lebih boros** karena menyimpan semua node di level saat ini (menggunakan queue).  
2. **Lambat untuk graf dalam** karena harus menjelajah semua level sebelum mencapai tujuan.  
3. **Tidak efisien untuk masalah dengan solusi jauh di dalam pohon**.  

### Perbandingan Singkat  
| Kriteria          | DFS                          | BFS                          |
|-------------------|-----------------------------|-----------------------------|
| **Kompleksitas Memori** | O(depth) (lebih hemat) | O(breadth) (lebih boros) |
| **Jalur Terpendek** | Tidak optimal | Optimal (unweighted graph) |
| **Kecepatan** | Cepat jika solusi dalam | Lambat untuk graf dalam |
| **Loop Handling** | Butuh visited check | Aman dari loop |

**Pilihan tergantung kebutuhan:**  
- Gunakan **BFS** untuk mencari jalur terpendek atau node terdekat.  
- Gunakan **DFS** untuk menghemat memori atau masalah yang memerlukan eksplorasi mendalam.  

**Penggunaan DFS dan BFS** dalam dunia nyata dan komputasi sangat beragam, tergantung pada karakteristik masalah yang dihadapi. Berikut beberapa contoh aplikasinya:

---
# Aplikasi DFS dan BFS
### 1. Depth-First Search (DFS)  
**Digunakan ketika:**  
- **Eksplorasi mendalam** lebih penting daripada menemukan jalur terpendek.  
- **Memori terbatas**, karena DFS umumnya lebih hemat memori dibanding BFS.  

**Contoh Aplikasi:**  
- **Maze Solving (Pencarian Jalur dalam Labirin):**  
  DFS cocok untuk mencari solusi apa pun (tidak harus terpendek) dengan menjelajah satu jalur sampai ujung sebelum backtracking.  

- **Deteksi Siklus dalam Graf:**  
  DFS mudah diadaptasi untuk mendeteksi siklus (misal: dependency cycle dalam software).  

- **Topological Sorting:**  
  Digunakan dalam scheduling tugas (contoh: menentukan urutan compile dependencies).  

- **Game AI (Permainan seperti Chess, Puzzle):**  
  DFS digunakan untuk mengeksplorasi langkah-langkah mungkin secara mendalam (misal: algoritma Minimax).  

- **Connected Components dalam Graf:**  
  Menemukan semua node yang terhubung dalam graf tidak terarah.  

---

### 2. Breadth-First Search (BFS)  
**Digunakan ketika:**  
- **Jalur terpendek** atau **solusi terdekat** diperlukan.  
- **Graf tidak terlalu dalam**, karena BFS boros memori.  

**Contoh Aplikasi:**  
- **Pencarian Rute Terpendek (GPS, Maps):**  
  BFS menjamin jalur terpendek dalam graf tanpa bobot (unweighted).  

- **Jaringan Sosial (Friend Recommendation):**  
  Mencari teman dalam jarak tertentu (contoh: "Orang yang mungkin Anda kenal" di LinkedIn).  

- **Broadcast Jaringan (Network Broadcasting):**  
  Protokol seperti ARP atau DHCP menggunakan pendekatan BFS untuk menyebarkan informasi ke semua node.  

- **Web Crawling:**  
  Mesin pencari seperti Google menggunakan BFS untuk mengindeks halaman web level demi level.  

- **Penyebaran Virus/Worm Simulation:**  
  Memodelkan penyebaran malware dalam jaringan komputer.  

---

### Perbandingan Penggunaan  
| **Masalah**               | **DFS** | **BFS** | **Alasan** |
|---------------------------|---------|---------|------------|
| Pencarian jalur terpendek | ❌ | ✔ | BFS menjamin hasil terpendek. |
| Eksplorasi graf besar | ✔ | ❌ | DFS lebih hemat memori. |
| Deteksi siklus | ✔ | ❌ | DFS mudah diimplementasikan. |
| Rekomendasi teman (jarak dekat) | ❌ | ✔ | BFS menjelajah "lapisan terdekat" dulu. |
| Penyelesaian puzzle (backtracking) | ✔ | ❌ | DFS cocok untuk mencoba semua kemungkinan. |

---

### Kesimpulan  
- **Gunakan DFS** untuk masalah yang memerlukan **kedalaman**, **backtracking**, atau **hemat memori**.  
- **Gunakan BFS** untuk masalah yang memerlukan **jarak terdekat**, **rute terpendek**, atau **eksplorasi level per level**.  

Keduanya adalah algoritma fundamental dengan keunikan masing-masing, dan pilihannya tergantung pada kebutuhan spesifik masalah yang dihadapi. 🎯

# Aplikasi DFS dan BFS Antii Laaksonen
Menggunakan algoritma _graph traversal_, kita dapat memeriksa banyak properti graf. Biasanya, baik _depth-first search_ maupun _breadth-first search_ dapat digunakan, tetapi dalam praktiknya, _depth-first search_ lebih sering dipilih karena lebih mudah diimplementasikan.

Dalam aplikasi berikut, kita akan mengasumsikan bahwa graf bersifat _undirected_.
## Pemeriksaan Konektivitas

Sebuah graf dikatakan _connected_ jika terdapat jalur antara setiap pasangan node dalam graf. Oleh karena itu, kita dapat memeriksa apakah sebuah graf _connected_ dengan memulai dari sembarang node dan mengecek apakah kita dapat mencapai semua node lainnya.

Sebagai contoh, dalam graf berikut:

![[Aplikasi DFS dan BFS-1.png|500]]

Sebuah _depth-first search_ dari node 1 mengunjungi node-node berikut:

![[Aplikasi DFS dan BFS-2.png|500]]

Karena pencarian tidak mengunjungi semua node, kita dapat menyimpulkan bahwa graf tersebut tidak terhubung. Dengan cara yang sama, kita juga dapat menemukan semua komponen yang terhubung dalam sebuah graf dengan melakukan iterasi melalui node-node dan selalu memulai _depth-first search_ yang baru jika node saat ini belum termasuk dalam komponen mana pun.

## Menemukan Siklus

Sebuah graf mengandung siklus jika selama traversi graf, kita menemukan node yang tetangganya (selain node sebelumnya dalam jalur saat ini) telah dikunjungi. Sebagai contoh, graf berikut:

![[Aplikasi DFS dan BFS-3.png|500]]

mengandung dua siklus, dan kita dapat menemukan salah satunya sebagai berikut:

![[Aplikasi DFS dan BFS-4.png|500]]

Setelah berpindah dari 2 node 5 ke node , kita menyadari bahwa neighbor 3 dari node 5 telah dikunjungi sebelumnya. Dengan demikian, graph mengandung cycle yang melalui node 3, misalnya, 3 -> 2 -> 5 ->3.

Cara lain untuk mengetahui apakah suatu graph mengandung cycle adalah dengan menghitung jumlah node dan edge dalam setiap komponen. Jika suatu komponen berisi $c$ node dan tidak memiliki cycle, maka harus memiliki tepat $c-1$ edge (sehingga membentuk tree). Jika ada $c$ atau lebih edge, maka komponen tersebut pasti mengandung cycle.

## Pemeriksaan Bipartiteness

Suatu graph adalah bipartite jika node-node-nya dapat diwarnai menggunakan dua warna sedemikian rupa sehingga tidak ada node yang berdekatan memiliki warna yang sama. Mengejutkan, cukup mudah untuk memeriksa apakah suatu graph bipartite menggunakan algoritma traversal graph.

Idenya adalah memberi warna biru pada node awal, semua neighbor-nya diberi warna merah, semua neighbor mereka diberi warna biru, dan seterusnya. Jika pada suatu titik dalam pencarian kita menemukan bahwa dua node yang berdekatan memiliki warna yang sama, ini berarti graph tidak bipartite. Jika tidak, graph adalah bipartite dan satu kemungkinan coloring telah ditemukan.

Sebagai contoh, graph berikut...

![[Aplikasi DFS dan BFS-5.png|500]]

tidak bipartite, karena pencarian dari node 1 berlangsung sebagai berikut:

![[Aplikasi DFS dan BFS-6.png|500]]

Kita perhatikan bahwa warna dari kedua node 2 dan 5 adalah merah, sementara mereka adalah node yang berdekatan dalam graf. Dengan demikian, graf ini tidak bipartite.

Algoritma ini selalu bekerja, karena ketika hanya ada dua warna yang tersedia, warna dari node awal dalam suatu komponen akan menentukan warna dari semua node lainnya dalam komponen tersebut. Tidak ada perbedaan apakah node awal berwarna merah atau biru.

Perlu dicatat bahwa dalam kasus umum, sulit untuk menentukan apakah node dalam suatu graf dapat diwarnai menggunakan $k$ warna sehingga tidak ada node yang berdekatan memiliki warna yang sama. Bahkan ketika $k=3$, tidak ada algoritma yang efisien yang diketahui, karena masalah ini bersifat _NP-hard_. 