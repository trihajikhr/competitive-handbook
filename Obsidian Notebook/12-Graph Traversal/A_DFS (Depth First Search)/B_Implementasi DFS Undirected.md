---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 12TH-GTDF-S002
nama_algoritma: Depth First Search
kategori_algoritma: Graph Algorithm - Traversal
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen & geeksforgeeks.com"
date_learned: 2025-04-30T21:42:00
tags:
  - graph-algorithm
  - graph-traversal
  - graph-DFS
---
#graph-algorithm #graph-traversal #graph-DFS 

---
# Implementasi DFS Undirected

> [!NOTE] Info sederhana
> Didalam *graph traversal*, hal-hal yang penting untuk dipelajari adalah tentang graph yang *directed* atau *undirected*, dan *connected* atau *disconnected*. Bobot atau w*eighted graph* tidak terlalu penting dalam implementasi *graph traversal*, karena dalam *graph traversal*, adalah tentang bagaimana kita mengunjungi dan mengakses setiap node-node dalam graph.


> [!NOTE] Info Complex
> Dalam mempelajari DFS (Depth-First Search), penting untuk memahami bagaimana algoritma ini bekerja pada berbagai jenis graph, namun tidak berarti kita harus mempelajari enam jenis DFS yang terpisah. 
> 
> Perbedaan utama yang memengaruhi perilaku DFS adalah apakah graph tersebut *directed* atau *undirected*, serta apakah graph-nya *connected* atau *disconnected*. DFS pada *directed graph* memiliki arah traversal yang harus diperhatikan, berbeda dengan *undirected graph* yang tidak mempermasalahkan arah. 
> 
> Selain itu, jika graph-nya tidak sepenuhnya terhubung (disconnected), DFS dari satu simpul saja tidak cukup untuk menjangkau seluruh simpul—kita perlu melakukan DFS terpisah dari setiap simpul yang belum dikunjungi. 
> 
> Sementara itu, perbedaan antara *weighted* dan *non-weighted* graph tidak berdampak pada DFS karena algoritma ini tidak mempertimbangkan bobot edge, melainkan hanya struktur koneksi antar simpul. Jadi, secara praktis, variasi penting DFS yang perlu dipahami mencakup kombinasi *directed/undirected* dan *connected/disconnected*, bukan bobot edge.

Dalam Depth First Search (atau DFS) untuk sebuah graph, kita menelusuri semua _adjacent vertices_ satu per satu. Ketika kita menelusuri sebuah _adjacent vertex_, kita menyelesaikan terlebih dahulu seluruh penelusuran terhadap semua _vertices_ yang dapat dicapai melalui _vertex_ tersebut. Ini mirip dengan tree (struktur pohon), di mana kita sepenuhnya menelusuri _left subtree_ terlebih dahulu sebelum berpindah ke _right subtree_. Perbedaan utamanya adalah, tidak seperti tree, graph bisa mengandung _cycles_ (sebuah _node_ bisa dikunjungi lebih dari sekali). Untuk menghindari pemrosesan ulang terhadap _node_ yang sama, kita menggunakan sebuah array boolean bernama _visited_.


> [!NOTE] FAQ:
> 
> **Vertex** dan **vertices** adalah istilah dalam teori graf:
> 
> - **Vertex** adalah bentuk **tunggal**, artinya satu simpul dalam graph.
>     
>     - Contoh: "Node A is a vertex in the graph."
>         
> - **Vertices** adalah bentuk **jamak** dari vertex, artinya lebih dari satu simpul.
>     
>     - Contoh: "We visited all vertices using DFS."
>         
> 
> Dalam konteks ini, kamu bisa menganggap "vertex" itu sama seperti **node** atau **simpul**, dan "vertices" berarti kumpulan node.

## Contoh 1
Catatan: Bisa terdapat beberapa hasil traversal DFS dari sebuah graph, tergantung pada urutan pemilihan _adjacent vertices_. Dalam kasus ini, kita memilih _vertices_ berdasarkan urutan saat mereka dimasukkan (insertion order).

**Input:** `adj = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]`

![[B_Implementasi DFS Undirected-1.png|500]]

**Output:** `[0 1 2 3 4]`  
**Penjelasan:** _Source vertex_ atau simpul awal adalah 0. Kita mengunjungi simpul ini terlebih dahulu, lalu mengunjungi salah satu simpul yang bersebelahan (_adjacent_).  
Mulai dari 0: Tandai sebagai visited. Output: 0  
Lanjut ke 1: Tandai sebagai visited. Output: 1  
Lanjut ke 2: Tandai sebagai visited. Output: 2  
Lanjut ke 3: Tandai sebagai visited. Output: 3 (kembali ke 2)  
Lanjut ke 4: Tandai sebagai visited. Output: 4 (kembali ke 2, lalu kembali ke 1, dan akhirnya kembali ke 0)

## Contoh 2
Perlu dicatat bahwa sebuah graph bisa memiliki lebih dari satu hasil traversal DFS. Sebagai contoh, setelah mengunjungi simpul 1, kita bisa saja memilih simpul 2 sebagai simpul tetangga selanjutnya, bukan 0, dan akan menghasilkan urutan DFS yang berbeda. Dalam contoh ini, kita memilih _adjacent vertices_ sesuai urutan saat dimasukkan (_insertion order_).

**Input:** `[[2, 3, 1], [0], [0, 4], [0], [2]]`  

![[B_Implementasi DFS Undirected-2.png|500]]

**Output:** `[0 2 4 3 1]`  
**Penjelasan langkah-langkah DFS:**

Mulai dari 0: Tandai sebagai visited. Output: 0  
Lanjut ke 2: Tandai sebagai visited. Output: 2  
Lanjut ke 4: Tandai sebagai visited. Output: 4 (kembali ke 2, lalu kembali ke 0)  
Lanjut ke 3: Tandai sebagai visited. Output: 3 (kembali ke 0)  
Lanjut ke 1: Tandai sebagai visited. Output: 1 (kembali ke 0)

## Ilustrasi DFS
Mari kita pahami cara kerja Depth First Search (DFS) dengan bantuan ilustrasi berikut, dengan sumber (source) sebagai 0.

![[B_Implementasi DFS Undirected-3.png]]

![[B_Implementasi DFS Undirected-4.png]]

![[B_Implementasi DFS Undirected-5.png]]

![[B_Implementasi DFS Undirected-6.png]]

![[B_Implementasi DFS Undirected-7.png]]

![[B_Implementasi DFS Undirected-8.png]]

![[B_Implementasi DFS Undirected-9.png]]

![[B_Implementasi DFS Undirected-10.png]]

![[B_Implementasi DFS Undirected-11.png]]

![[B_Implementasi DFS Undirected-12.png]]

---

Baiklah, berikut contoh Implementasi DFS dengan C++
# Undirected Graph - Connected (geeksforgeeks)


> [!NOTE] PENTING!
> Materi ini mengajarkan tentang teori, namun implementasi dalam kasus nyata cukup berbeda, dimana program yang dibuat harus dinamis atau mampu menerima inputan user. Untuk hal itu, pelajari di materi ini:
> 
> - [[D_DFS Kasus Nyata Undirected dan Directed]]




```cpp
#include <bits/stdc++.h>
using namespace std;

// Fungsi rekursif untuk traversal DFS
void dfsRec(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &res)
{

    visited[s] = true;

    res.push_back(s);

    // Secara rekursif mengunjungi semua *adjacent vertices*
    // yang belum dikunjungi
    for (int i : adj[s])
        if (visited[i] == false)
            dfsRec(adj, visited, i, res);
}

// Fungsi DFS utama yang menginisialisasi array visited
// dan memanggil DFSRec
vector<int> DFS(vector<vector<int>> &adj)
{
    vector<bool> visited(adj.size(), false);
    vector<int> res;
    dfsRec(adj, visited, 0, res);
    return res;
}

// Untuk menambah sebuah edge pada graph tak terarah
void addEdge(vector<vector<int>> &adj, int s, int t)
{
    adj[s].push_back(t);
    adj[t].push_back(s);
}

int main()
{
    int V = 5;
    vector<vector<int>> adj(V);

    // Menambahkan edges
    vector<vector<int>> edges = {{1, 2}, {1, 0}, {2, 0}, {2, 3}, {2, 4}};
    for (auto &e : edges)
        addEdge(adj, e[0], e[1]);

    // Simpul awal untuk DFS
    vector<int> res = DFS(adj); // Melakukan DFS mulai dari simpul sumber 0;

    for (int i = 0; i < V; i++)
        cout << res[i] << " ";
}
```

Penjelasan singkat dari komentar-komentar di kode tersebut:

- **Fungsi rekursif DFS**: Menjelaskan bagaimana DFS dilakukan secara rekursif, mengunjungi setiap _adjacent vertex_ yang belum dikunjungi.
    
- **Fungsi DFS utama**: Fungsi ini bertugas untuk menginisialisasi array `visited` dan memanggil fungsi rekursif `dfsRec` untuk mulai melakukan traversal.
    
- **Menambah edge**: Fungsi ini menambah edge dalam graph tak terarah dengan memasukkan simpul-simpul yang saling terhubung ke dalam list tetangga.

Kode tersebut sebenarnya bekerja untuk **graph tak terarah (undirected)** dan **terhubung (connected)** dalam hal ini.

Berikut penjelasannya:

1. **Graph Tak Terarah (Undirected)**:  
    Fungsi `addEdge` menambahkan edge di kedua arah. Ketika kamu menambahkan edge antara simpul `s` dan `t`, maka kedua simpul tersebut akan menjadi _adjacent_ satu sama lain. Dengan kata lain, jika ada edge antara simpul `s` dan `t`, maka `s` akan berada di daftar tetangga `t`, dan `t` akan berada di daftar tetangga `s`. Ini adalah karakteristik dari graph tak terarah.
    
    ```cpp
    adj[s].push_back(t);
    adj[t].push_back(s);
    ```
    
2. **Graph Terhubung (Connected)**:  
    Meskipun kode ini tidak secara eksplisit memeriksa apakah graph terhubung atau tidak, **DFS** akan bekerja dengan baik untuk graph yang terhubung. DFS akan mengunjungi semua simpul yang dapat dicapai dari simpul sumber (0 dalam hal ini). Jika graph terhubung, DFS akan mengunjungi semua simpul, sedangkan jika graph terputus (disconnected), DFS hanya akan mengunjungi simpul yang berada dalam komponen terhubung dengan simpul sumber.
    
    Namun, jika graph tidak terhubung, DFS akan hanya mengunjungi simpul-simpul yang ada dalam komponen yang terhubung dengan simpul sumber 0. Jika kamu ingin mengunjungi semua komponen terhubung dalam graph yang terputus, kamu perlu memanggil DFS untuk setiap simpul yang belum dikunjungi (misalnya, jika ada lebih dari satu komponen terhubung).

## Editorial Kode
Berikut adalah **editorial lengkap** yang menjelaskan setiap penggunaan syntax dalam kode C++ yang kamu berikan. Fokus utamanya adalah implementasi **DFS (Depth-First Search)** pada **graph tak berarah (undirected graph)** menggunakan **adjacency list**.

### 1. Header dan Namespace

```cpp
#include <bits/stdc++.h>
using namespace std;
```

- `#include <bits/stdc++.h>`: Mengimpor **seluruh library standar C++**. Praktis, tapi sebaiknya dihindari di lingkungan produksi karena memperlambat kompilasi.
    
- `using namespace std;`: Agar kita tidak perlu menulis `std::` di depan tipe/objek dari Standard Library (misalnya `cout`, `vector`, dll).
    

---

### 2. Fungsi DFS Rekursif

```cpp
void dfsRec(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &res)
```

- Fungsi ini menjalankan **DFS** secara rekursif mulai dari simpul `s`.
    
- `adj`: Representasi graf dalam bentuk adjacency list.
    
- `visited`: Menandai simpul yang sudah dikunjungi agar tidak dikunjungi dua kali.
    
- `res`: Menyimpan urutan simpul yang dikunjungi selama DFS.
    

```cpp
visited[s] = true;
res.push_back(s);
```

- Tandai simpul `s` sebagai sudah dikunjungi.
    
- Tambahkan `s` ke hasil `res`.
    

```cpp
for (int i : adj[s])
    if (visited[i] == false)
        dfsRec(adj, visited, i, res);
```

- Iterasi setiap simpul `i` yang bertetangga dengan `s`.
    
- Jika simpul `i` belum dikunjungi, panggil DFS untuk `i`.
    

---

### 3. Fungsi DFS Utama

```cpp
vector<int> DFS(vector<vector<int>> &adj)
```

- Fungsi yang menyiapkan array `visited` dan memanggil fungsi rekursif dari simpul `0`.
    

```cpp
vector<bool> visited(adj.size(), false);
vector<int> res;
dfsRec(adj, visited, 0, res);
return res;
```

- `visited`: Diinisialisasi dengan ukuran `adj.size()` (jumlah simpul).
    
- `res`: Hasil urutan DFS.
    
- DFS dimulai dari simpul `0`.
    

---

### 4. Menambahkan Edge ke Graph

```cpp
void addEdge(vector<vector<int>> &adj, int s, int t)
```

- Tambahkan edge dari `s` ke `t` dan sebaliknya karena graf **tak berarah**.
    

```cpp
adj[s].push_back(t);
adj[t].push_back(s);
```

---

### 5. Fungsi `main()`

```cpp
int V = 5;
vector<vector<int>> adj(V);
```

- `V = 5`: Jumlah simpul dalam graf.
    
- `adj(V)`: Membuat adjacency list dengan `V` vektor kosong (`adj[0]`, `adj[1]`, ..., `adj[4]`).
    

```cpp
vector<vector<int>> edges = {{1, 2}, {1, 0}, {2, 0}, {2, 3}, {2, 4}};
for (auto &e : edges)
    addEdge(adj, e[0], e[1]);
```

- Inisialisasi edge sebagai vektor pasangan.
    
- `auto &e`: setiap edge `e` adalah pasangan simpul `[s, t]`.
    
- `addEdge()` dipanggil untuk menambahkan edge ke graf.
    

```cpp
vector<int> res = DFS(adj);
```

- Memanggil fungsi `DFS`, dimulai dari simpul `0`, dan hasil traversal disimpan di `res`.
    

```cpp
for (int i = 0; i < V; i++)
    cout << res[i] << " ";
```

- Menampilkan hasil traversal DFS dalam urutan simpul yang dikunjungi.
    

---

### 🔍 CONTOH OUTPUT

Bergantung pada struktur graf dan simpul awal (`0`), urutan output bisa:

```
0 1 2 3 4
```

Atau urutan DFS lainnya yang valid, karena ada beberapa edge ke simpul yang sama (tidak selalu unik).

---

### 💡 CATATAN PENTING

- DFS traversal **bergantung pada urutan penyimpanan adjacency list**.
    
- Program ini **selalu mulai dari simpul 0**, meskipun simpul 0 mungkin tidak terhubung langsung di awal edge list.
    
- Jika graf tidak terhubung, DFS ini hanya akan mengunjungi komponen yang bisa dijangkau dari simpul `0`.
    

#### Tips Trick 
DFS traversal akan melakukan penelusuran berdasarkan urutan edges yang diinputkan, sehingga hasil penelusuran akan bervariasi tergantung urutan inputan edges-nya. Hal ini mejadi alasan dimana walaupun graph yang dibuat sama, namun hasil DFS traversal atau outputnya bisa berbeda.

Jika kamu ingin DFS mengunjungi simpul dengan urutan kecil lebih dulu, kamu bisa **sort adjacency list sebelum DFS**, misalnya:

```cpp
for (auto &neighbors : adj){
    sort(neighbors.begin(), neighbors.end());
}
```

Atau kunjungi note berikut untuk penjelasan yang lebih rinci:
- [[Urutan Traversal DFS Selalu dari yang Terkecil]]

# ChatGPT (AI version)
Haha, pasti! Kita coba buat versi implementasi DFS-nya. Meskipun ide dasarnya tetap sama, ada beberapa cara yang bisa membuat implementasi berbeda, terutama dalam gaya penulisan atau alur pemrogramannya.

Berikut adalah implementasi DFS versi saya, yang sedikit berbeda, tapi tetap sama prinsipnya:

```cpp
#include <bits/stdc++.h>
using namespace std;

// Fungsi DFS Iteratif menggunakan stack
vector<int> DFS(vector<vector<int>> &adj, int V)
{
    vector<bool> visited(V, false);
    vector<int> res;
    stack<int> s;

    // Memulai DFS dari simpul sumber 0
    s.push(0);

    while (!s.empty())
    {
        int node = s.top();
        s.pop();

        if (!visited[node])
        {
            visited[node] = true;
            res.push_back(node);
        }

        // Menambahkan simpul tetangga yang belum dikunjungi
        for (int i = adj[node].size() - 1; i >= 0; i--) // Menambahkan dari belakang agar urutannya sesuai
        {
            int neighbor = adj[node][i];
            if (!visited[neighbor])
            {
                s.push(neighbor);
            }
        }
    }

    return res;
}

// Untuk menambah sebuah edge pada graph tak terarah
void addEdge(vector<vector<int>> &adj, int s, int t)
{
    adj[s].push_back(t);
    adj[t].push_back(s);
}

int main()
{
    int V = 5;
    vector<vector<int>> adj(V);

    // Menambahkan edges
    vector<vector<int>> edges = {{1, 2}, {1, 0}, {2, 0}, {2, 3}, {2, 4}};
    for (auto &e : edges)
        addEdge(adj, e[0], e[1]);

    // Melakukan DFS mulai dari simpul sumber 0
    vector<int> res = DFS(adj, V);

    // Menampilkan hasil traversal DFS
    for (int i : res)
        cout << i << " ";
}
```

### Apa yang berbeda di sini?

1. **Iteratif, bukan rekursif**:  
    Saya menggunakan stack untuk implementasi DFS secara iteratif, bukan rekursif. Dengan cara ini, kita bisa menghindari batasan kedalaman rekursi yang mungkin terjadi pada graph yang sangat besar.
    
2. **Penambahan tetangga dari belakang**:  
    Saat menambahkan _neighbor_ ke dalam stack, saya menambahkan dari belakang (`i >= 0`) untuk memastikan traversal dilakukan sesuai dengan urutan yang diinginkan (mirip dengan urutan insertion).
    
3. **Lebih fleksibel**:  
    Dalam implementasi ini, kita bisa lebih mudah mengendalikan traversal menggunakan stack dibandingkan dengan rekursi, yang kadang membuat program lebih sulit di-debug jika ada masalah.
    

### Apakah hasilnya sama?

Ya, meskipun implementasinya sedikit berbeda (iteratif vs rekursif), hasil dari DFS ini akan **sama**, yaitu mengunjungi semua simpul yang terhubung, dimulai dari simpul 0. Traversalnya tetap akan menghasilkan urutan yang konsisten, selama graph tidak terputus dan menggunakan urutan tetangga yang sama.

Jadi, apakah versi saya ini sudah lebih keren atau tetap setia pada yang pertama? 😄

### Iteratif vs Rekursif?
> **FAQ**: Ehhh, sebelunya adalah pendekatan rekursif, jadi milikmu adalah pendekatan iteratif?

Haha, iya betul! Sebelumnya, implementasi DFS yang saya terjemahkan itu menggunakan pendekatan **rekursif**, sedangkan versi yang saya buat sekarang menggunakan pendekatan **iteratif** dengan stack.

Jadi, meskipun kedua versi ini bekerja dengan prinsip yang sama, yaitu menjelajahi graph secara mendalam (depth-first), cara implementasinya berbeda:

- **Rekursif**: DFS berjalan secara otomatis melalui pemanggilan fungsi berulang-ulang, mengikuti jalur dari simpul satu ke simpul lainnya.
<br/>
- **Iteratif**: DFS mengelola stack sendiri untuk mengontrol traversal, memproses satu simpul per satu waktu, dan kembali ke simpul sebelumnya saat jalur tidak lagi dapat dieksplorasi.
    

Keduanya sah-sah saja kok, dan biasanya, pendekatan iteratif lebih disarankan untuk graph yang besar karena menghindari batasan _stack overflow_ yang bisa terjadi pada rekursi jika graphnya terlalu dalam.

## Jadi? Mana lebih baik?
Secara keseluruhan, baik **DFS rekursif** maupun **iteratif** memiliki kelebihan dan kekurangan masing-masing, tergantung pada konteks dan kebutuhan spesifikmu. Berikut adalah beberapa pertimbangan untuk membantu memilih mana yang lebih cocok:

### 1. DFS Rekursif

**Kelebihan:**

- **Lebih sederhana** dan lebih **mudah dipahami** karena menggunakan pemanggilan fungsi yang alami (langsung menelusuri jalur mendalam).
    
- **Kode lebih bersih** dan lebih sedikit baris, membuatnya lebih elegan jika graph tidak terlalu besar.
    

**Kekurangan:**

- Dapat menyebabkan **stack overflow** pada graph yang sangat dalam atau besar, karena setiap pemanggilan rekursif menambah tumpukan fungsi.
    
- Kurang fleksibel jika kamu perlu mengontrol traversal lebih banyak (misalnya, jika kamu ingin mengubah urutan atau melacak beberapa jalur sekaligus).
    

---

### 2. DFS Iteratif

**Kelebihan:**

- Tidak ada risiko **stack overflow**, karena kita mengontrol stack sendiri. Ini lebih aman pada graph yang sangat dalam.
    
- Lebih **fleksibel**, karena kita bisa lebih mudah memodifikasi alur traversal, misalnya dengan memodifikasi stack atau menambahkan lebih banyak fitur kontrol.
    
- **Lebih cocok untuk graph besar**, terutama saat bekerja dengan struktur data yang lebih kompleks atau jika ingin menghindari batasan kedalaman rekursi.
    

**Kekurangan:**

- **Lebih rumit** untuk diimplementasikan dan lebih **panjang** daripada versi rekursif, meskipun tidak jauh berbeda dalam hal logika.
    
- Cenderung lebih sulit dipahami bagi pemula karena melibatkan penggunaan stack manual.
    

---

### Kesimpulan:

- Jika **graph relatif kecil** atau kamu ingin implementasi yang cepat dan sederhana, **DFS rekursif** bisa menjadi pilihan yang baik.
    
- Jika **graph sangat besar** atau kamu khawatir dengan batasan rekursi, **DFS iteratif** lebih disarankan, karena lebih aman dan lebih fleksibel dalam menghadapi graph yang lebih dalam atau lebih kompleks.
    

Pada akhirnya, **keduanya sah** dan tidak ada yang lebih "benar" secara mutlak, tergantung pada kebutuhanmu. Jika kamu masih merasa bingung, coba mulai dengan rekursif, lalu beralih ke iteratif ketika kamu merasa perlu menangani graph yang lebih besar atau lebih rumit! 😄

# Undirected Graph - Disconnected (geeksforgeeks)

Implementasi di atas menerima sebuah _source_ sebagai input dan hanya mencetak simpul-simpul yang dapat dijangkau dari _source_ tersebut. Ia tidak akan mencetak semua simpul jika graph-nya terputus (_disconnected_). Sekarang, mari kita bahas algoritma yang mencetak semua simpul tanpa bergantung pada _source_, bahkan ketika graph-nya mungkin terputus.

Idenya sederhana: alih-alih memanggil DFS untuk satu simpul saja, kita memanggil fungsi DFS yang telah diimplementasikan tersebut untuk setiap simpul yang belum dikunjungi, satu per satu.

```cpp
#include <bits/stdc++.h>
using namespace std;

// Untuk menambahkan edge ke dalam graph tak terarah
void addEdge(vector<vector<int>> &adj, int s, int t)
{
    adj[s].push_back(t);
    adj[t].push_back(s);
}

// Fungsi rekursif untuk traversal DFS
void dfsRec(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &res)
{
    // Tandai simpul saat ini sebagai sudah dikunjungi
    visited[s] = true;

    res.push_back(s);

    // Kunjungi semua simpul tetangga yang belum dikunjungi secara rekursif
    for (int i : adj[s])
        if (visited[i] == false)
            dfsRec(adj, visited, i, res);
}

// Fungsi utama DFS untuk melakukan DFS pada seluruh graph
vector<int> DFS(vector<vector<int>> &adj)
{
    vector<bool> visited(adj.size(), false);
    vector<int> res;
    // Iterasi ke seluruh simpul untuk menangani graph yang terputus
    for (int i = 0; i < adj.size(); i++)
    {
        if (visited[i] == false)
        {
            // Jika simpul ke-i belum dikunjungi,
            // lakukan DFS dari simpul tersebut
            dfsRec(adj, visited, i, res);
        }
    }

    return res;
}

int main()
{
    int V = 6;
    // Membuat adjacency list untuk graph
    vector<vector<int>> adj(V);

    // Mendefinisikan edge-edge pada graph
    vector<vector<int>> edges = {{1, 2}, {2, 0}, {0, 3}, {4, 5}};

    // Mengisi adjacency list dengan edge-edge tersebut
    for (auto &e : edges)
        addEdge(adj, e[0], e[1]);
    vector<int> res = DFS(adj);

    for (auto it : res)
        cout << it << " ";
    return 0;
}
```

Penjelasan ringkas: Kode ini melakukan **DFS pada graph yang mungkin terputus (disconnected)**. Ia memanggil DFS dari setiap simpul yang belum dikunjungi untuk memastikan seluruh komponen dalam graph dikunjungi.

## Editorial 

Program ini menerapkan algoritma **Depth First Search (DFS)** untuk menjelajahi seluruh simpul dalam sebuah **graph tak terarah (undirected graph)**, **termasuk** jika graph tersebut **terputus (disconnected)**.

---

### 📦 Library yang Digunakan

```cpp
#include <bits/stdc++.h>
using namespace std;
```

- `#include <bits/stdc++.h>`: Mengimpor semua library standar C++ (digunakan untuk kemudahan, terutama saat kompetisi).
    
- `using namespace std;`: Agar kita bisa langsung menggunakan objek dari namespace `std` tanpa perlu mengetik `std::` di depannya.
    

---

### 🧱 Fungsi `addEdge`

```cpp
void addEdge(vector<vector<int>> &adj, int s, int t)
{
    adj[s].push_back(t);
    adj[t].push_back(s);
}
```

- Tujuan: Menambahkan _edge_ antara dua node `s` dan `t` dalam **graph tak terarah**.
    
- `adj[s].push_back(t)` → menambahkan `t` ke daftar tetangga node `s`.
    
- `adj[t].push_back(s)` → karena tak terarah, kita juga menambahkan `s` ke daftar tetangga node `t`.
    

---

### 🔁 Fungsi Rekursif DFS (`dfsRec`)

```cpp
void dfsRec(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &res)
```

- Tujuan: Melakukan DFS dari simpul `s`, menyimpan hasil ke `res`, dan menandai node yang telah dikunjungi.
    
- Parameter:
    
    - `adj`: representasi adjacency list dari graph.
        
    - `visited`: penanda apakah simpul sudah dikunjungi.
        
    - `s`: simpul saat ini yang sedang dijelajahi.
        
    - `res`: hasil urutan DFS.
        

```cpp
visited[s] = true;
res.push_back(s);
```

- Menandai simpul `s` sebagai sudah dikunjungi dan menyimpannya ke hasil.
    

```cpp
for (int i : adj[s])
    if (!visited[i])
        dfsRec(adj, visited, i, res);
```

- Menelusuri seluruh tetangga dari simpul `s`.
    
- Jika tetangga `i` belum dikunjungi, lakukan DFS rekursif ke `i`.
    

---

### 🌐 Fungsi Utama `DFS`

```cpp
vector<int> DFS(vector<vector<int>> &adj)
```

- Tujuan: Menjalankan DFS **untuk seluruh graph**, termasuk jika graph terputus.
    
- Langkah:
    
    1. Buat array `visited` untuk menandai simpul yang sudah dikunjungi.
        
    2. Loop ke seluruh simpul (`for (int i = 0; i < adj.size(); i++)`).
        
    3. Jika simpul `i` belum dikunjungi, panggil `dfsRec` dari simpul tersebut.
        

Hasil DFS dari semua komponen graph akan dikumpulkan dalam `res`.

---

### 🏁 Fungsi `main`

```cpp
int main()
```

#### Inisialisasi graph:

```cpp
int V = 6;
vector<vector<int>> adj(V);
```

- `V`: jumlah simpul (vertices) dalam graph.
    
- `adj`: adjacency list, berukuran `V`.
    

#### Menentukan edge:

```cpp
vector<vector<int>> edges = {{1, 2}, {2, 0}, {0, 3}, {4, 5}};
```

- Edge dalam bentuk pasangan simpul. Graph ini memiliki **dua komponen terpisah**:
    
    - Komponen 1: 0-2-1 dan 0-3
        
    - Komponen 2: 4-5
        

#### Menambahkan edge:

```cpp
for (auto &e : edges)
    addEdge(adj, e[0], e[1]);
```

- Untuk setiap edge, kita tambahkan ke adjacency list dengan `addEdge`.
    

#### Menjalankan DFS:

```cpp
vector<int> res = DFS(adj);
```

- Menjalankan DFS dari seluruh simpul, mencakup semua komponen graph.
    

#### Menampilkan hasil:

```cpp
for (auto it : res)
    cout << it << " ";
```

- Menampilkan urutan simpul yang dikunjungi oleh DFS, dalam satu baris.
    

---

### 🔎 Contoh Output

Untuk input edge:

```cpp
{{1, 2}, {2, 0}, {0, 3}, {4, 5}}
```

Kemungkinan output (tergantung urutan traversal):

```
0 2 1 3 4 5
```

---

### 🧾 Kesimpulan

Kode ini adalah implementasi DFS lengkap yang:

- Bekerja untuk **graph tak terarah**.
    
- Menangani **graph terputus** dengan menjelajahi seluruh komponen.
    
- Menggunakan **rekursi** untuk traversal.
    
- Menyimpan hasil traversal dalam vektor hasil `res`.
    

# ChatGPT (AI version)


>  Apakah implementasi dari GeeksforGeeks sudah cukup bagus?

Ya, **versi dari GeeksforGeeks** tersebut **sudah sangat bagus** sebagai implementasi dasar **Depth First Search (DFS)** untuk pemula hingga menengah. Ini alasannya:

---

### ✅ Kelebihan Kode GeeksforGeeks

1. **Sangat edukatif**: Komentar-komentarnya jelas dan menjelaskan langkah demi langkah — cocok untuk pembelajaran.
    
2. **Menangani graph yang terputus (disconnected)**: Ini penting karena banyak tutorial hanya membahas graph yang terhubung penuh.
    
3. **Menggunakan struktur data standar**:
    
    - `vector<vector<int>>` untuk adjacency list.
        
    - `vector<bool>` untuk visited.
        
    - `vector<int>` untuk hasil traversal.
        
4. **Konsisten dan bersih**: Tidak ada optimisasi ekstrem yang bisa membingungkan pemula, tapi cukup kuat untuk diterapkan dalam kompetisi dasar.
    
5. **Modular**: Fungsi DFS dipisahkan menjadi dua — satu fungsi rekursif (`dfsRec`), satu fungsi utama (`DFS`) — ini memudahkan debugging dan pengembangan lebih lanjut.
    

---

### 🚫 Kekurangannya (kalau mau dikritisi secara lebih lanjut)

1. **Tidak fleksibel terhadap source node**:
    
    - DFS-nya selalu dimulai dari node 0 — padahal di beberapa kasus kompetitif, kamu ingin bisa memilih source secara dinamis.
        
2. **Tidak ada pemrosesan tambahan (misal depth, parent, dll)**:
    
    - Untuk pembelajaran lanjutan, kamu mungkin butuh menyimpan lebih banyak informasi saat DFS, tapi ini bisa kamu tambahkan sendiri.
        
3. **Tidak eksplisit menggunakan stack (iteratif)**:
    
    - Versi rekursif mudah dipahami, tapi tidak cocok untuk graph sangat dalam (karena risiko stack overflow).
        

---

### 🏁 Kesimpulan

Kode DFS dari GeeksforGeeks tersebut:

- Sangat cocok untuk pembelajaran dasar hingga menengah.
    
- Sudah mencakup graph **tak terarah** dan **terputus**.
    
- **Sudah bagus** untuk pemahaman konsep dan sebagai pondasi untuk modifikasi lanjutan.
    

Kalau kamu sudah memahami versi ini, kamu bisa lanjut ke:

- Versi **DFS iteratif (menggunakan stack)**.
    
- DFS untuk **directed graph**.
    
- DFS dengan fitur tambahan seperti **menemukan komponen terhubung**, **pendeteksian siklus**, atau **topological sort**.
    

Kamu ingin saya bantu tunjukkan bagaimana kode itu bisa dimodifikasi untuk graph **directed** atau **mulai dari node selain 0**?

---
## Implementasi
Tentu! Berikut adalah **versi implementasi DFS dalam C++** yang saya tulis sendiri. Tujuannya adalah agar:

- Lebih **modular** dan **fleksibel** (kamu bisa pilih mulai dari node mana saja).
    
- Bisa dipakai untuk **graph tak terarah** maupun **terarah** hanya dengan sedikit penyesuaian.
    
- Bisa dengan mudah ditambahkan fitur lain seperti **mendeteksi komponen terhubung** atau **mendeteksi siklus** nantinya.
    

---

### 🧠 Versi DFS Modular & Fleksibel (C++)

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Fungsi DFS rekursif
void dfs(int u, const vector<vector<int>> &adj, vector<bool> &visited, vector<int> &result) {
    visited[u] = true;
    result.push_back(u);

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited, result);
        }
    }
}

// Fungsi utama DFS: bisa dipakai untuk graph yang terputus
vector<int> runDFS(const vector<vector<int>> &adj, int startNode = 0) {
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<int> result;

    // Jika hanya ingin DFS dari satu simpul:
    dfs(startNode, adj, visited, result);

    // Jika ingin menjelajahi semua simpul (termasuk komponen lain):
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, result);
        }
    }

    return result;
}

// Menambahkan edge ke dalam graph (ubah jika ingin directed)
void addEdge(vector<vector<int>> &adj, int u, int v, bool directed = false) {
    adj[u].push_back(v);
    if (!directed) adj[v].push_back(u); // tidak ditambahkan jika directed
}

int main() {
    int V = 6; // jumlah simpul
    vector<vector<int>> adj(V);

    // Tambahkan edge
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 4, 5); // komponen terpisah

    // Jalankan DFS
    vector<int> dfsResult = runDFS(adj);

    // Cetak hasil
    for (int node : dfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
```

---

### 🧾 Catatan Desain

- Fungsi `dfs(...)` memisahkan traversal, sehingga bisa dipanggil dari mana saja.
    
- Fungsi `runDFS(...)` melakukan:
    
    - DFS dari `startNode` jika ingin dari satu sumber.
        
    - DFS ke seluruh simpul jika ingin mencakup komponen terpisah.
        
- Fungsi `addEdge(...)` punya opsi `directed`, sehingga kamu bisa ubah dengan cepat menjadi **graph berarah**.
    

---

### Contoh Output

Untuk edge:

```cpp
0-1, 0-2, 1-3, 4-5
```

Output DFS bisa jadi:

```
0 1 3 2 4 5
```

Urutan bisa bervariasi tergantung urutan adjacency list.
## Perbedaan
Bagus! Mari kita bandingkan **kode GeeksforGeeks** dan **versi saya** secara **konseptual dan praktikal** agar kamu tahu kapan pakai yang mana.

---

### ⚔️ Perbandingan: GeeksforGeeks vs Versi Saya

|Aspek|GeeksforGeeks|Versi Saya|
|---|---|---|
|**Modularitas**|DFS utama (`DFS()`) dan rekursif (`dfsRec()`) dipisah.|Juga modular, tapi lebih fleksibel (bisa DFS dari simpul mana saja).|
|**Starting Node**|Selalu mulai dari `0`. Tidak bisa diubah kecuali edit kodenya.|Bisa mulai dari node mana saja dengan parameter `startNode`.|
|**Komponen Terputus**|Ditangani dalam versi kedua (kode yang kamu beri).|Sudah ditangani dalam satu fungsi (`runDFS()`), tidak perlu versi terpisah.|
|**Edge Directed/Undirected**|Hanya undirected. Harus modifikasi manual jika ingin directed.|Bisa pilih dengan parameter `directed = true/false`.|
|**Ekspansi ke fitur lain (seperti topological sort, cycle detection)**|Harus ubah struktur lebih banyak.|Lebih mudah dimodifikasi karena struktur fungsi lebih fleksibel.|
|**Pemahaman dasar DFS**|Sangat cocok untuk belajar rekursi dan dasar DFS.|Cocok untuk pemahaman lanjutan dan siap pakai di banyak skenario.|

---

### 🧠 Penjelasan Tambahan

- **Versi GeeksforGeeks** cocok untuk yang **baru belajar**, karena fokus pada pemahaman dasar: bagaimana visited bekerja, bagaimana traversal dijalankan, dll.
    
- **Versi saya** didesain untuk:
    
    - Langsung bisa digunakan di banyak tipe graph (terhubung/tidak, berarah/tidak).
        
    - Mudah dikembangkan (misal: cari komponen, DFS dari node manapun, atau sebagai dasar algoritma lanjutan).
        

---

### 🎯 Kesimpulan

> **Kalau kamu sedang belajar dasar DFS**, gunakan versi **GeeksforGeeks**.
> 
> **Kalau kamu sudah mulai sering ngerjain soal kompetitif**, atau butuh fleksibilitas, pakai **versi saya**.

Mau saya bantu tambahkan fitur lain ke versi saya? Seperti **menyimpan parent** atau **komponen ke berapa**?

## Versi Iteratif
Sip! Sekarang aku kasih kamu **versi DFS iteratif (tanpa rekursi)** — ini penting karena:

- Bisa **menghindari stack overflow** pada graph yang sangat besar atau dalam.
    
- Kadang dibutuhkan di **soal kompetitif** yang tidak memperbolehkan rekursi dalam constraints besar.
    
- Memakai **stack manual**, sesuai konsep Depth First.
    

---

### 🔁 DFS Iteratif Versi Saya (C++)

```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Fungsi DFS iteratif
vector<int> DFSIterative(const vector<vector<int>> &adj, int startNode = 0) {
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<int> result;
    stack<int> stk;

    stk.push(startNode);

    while (!stk.empty()) {
        int u = stk.top();
        stk.pop();

        if (!visited[u]) {
            visited[u] = true;
            result.push_back(u);

            // Push semua tetangga ke stack
            // (bisa dibalik urutan untuk hasil traversal beda)
            for (auto it = adj[u].rbegin(); it != adj[u].rend(); ++it) {
                if (!visited[*it]) {
                    stk.push(*it);
                }
            }
        }
    }

    return result;
}

// Tambahkan edge
void addEdge(vector<vector<int>> &adj, int u, int v, bool directed = false) {
    adj[u].push_back(v);
    if (!directed) adj[v].push_back(u);
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    // Tambahkan edge (graph tidak terhubung)
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 4, 5);

    // DFS iteratif dari simpul 0
    vector<int> result = DFSIterative(adj, 0);

    for (int node : result) {
        cout << node << " ";
    }

    return 0;
}
```

---

### 🔍 Catatan

- Menggunakan `stack<int>` agar sesuai prinsip DFS.
    
- Gunakan `rbegin()` dan `rend()` saat mendorong tetangga supaya urutan traversal mirip versi rekursif (karena stack LIFO).
    
- Kamu bisa memodifikasi agar bisa **DFS ke seluruh graph** (termasuk disconnected) dengan menambahkan loop di luar stack mirip seperti versi rekursif full traversal tadi.
    

---

### 🧠 Kapan Pakai DFS Iteratif?

- Jika kamu ingin **menghindari rekursi**.
    
- Jika kedalaman graph bisa besar banget.
    
- Jika kamu sedang latihan menyelesaikan DFS tanpa stack call bawaan.
    
