---
obsidianUIMode: preview
note_type: book theory
judul_materi:
sumber:
date_learned:
tags:
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Algoritma Floyd-Warshall

Diberikan sebuah _directed graph_ (graf berarah) atau _undirected graph_ (graf tak berarah) berbobot $G$ dengan $n$ _vertices_ (simpul). Tugasnya adalah menemukan panjang lintasan terpendek (_shortest path_) $d_{ij}$ antara setiap pasangan _vertices_ $i$ dan $j$.

_Graph_ tersebut boleh memiliki _edge_ (sisi) dengan bobot negatif, tetapi tidak boleh memiliki _negative weight cycle_ (siklus berbobot negatif).

Jika terdapat _negative cycle_, Anda dapat menelusuri siklus ini berulang-ulang, di mana setiap iterasinya akan membuat _cost_ (biaya/jarak) dari lintasan menjadi semakin kecil. Akibatnya, Anda dapat membuat lintasan tertentu menjadi sekecil apa pun tanpa batas, atau dengan kata lain, _shortest path_ menjadi tidak terdefinisi. Hal ini secara otomatis berarti bahwa sebuah _undirected graph_ tidak boleh memiliki _edge_ dengan bobot negatif sama sekali, karena _edge_ tersebut sudah membentuk _negative cycle_ akibat Anda dapat bergerak maju-mundur di sepanjang _edge_ tersebut sesuka Anda.

Algoritma ini juga dapat digunakan untuk mendeteksi keberadaan _negative cycle_. Graf tersebut memiliki _negative cycle_ jika pada akhir algoritma, jarak dari suatu _vertex_ $v$ ke dirinya sendiri bernilai negatif.

Algoritma ini dipublikasikan secara bersamaan dalam artikel oleh Robert Floyd dan Stephen Warshall pada tahun 1962. Namun, pada tahun 1959, Bernard Roy telah memublikasikan algoritma yang secara esensial sama, tetapi publikasinya tidak mendapat banyak perhatian.

## Deskripsi Algoritma

Ide kunci dari algoritma ini adalah mempartisi proses pencarian _shortest path_ antara dua _vertices_ mana pun ke dalam beberapa fase inkremental (bertahap).

Mari kita beri nomor pada _vertices_ mulai dari $1$ hingga $n$. _Matrix_ untuk jarak adalah $d[ ][ ]$.

Sebelum fase ke-$k$ ($k = 1 \dots n$), nilai $d[i][j]$ untuk setiap _vertices_ $i$ dan $j$ menyimpan panjang lintasan terpendek antara _vertex_ $i$ dan _vertex_ $j$, yang hanya memuat _vertices_ $\{1, 2, ..., k-1\}$ sebagai _internal vertices_ (simpul perantara/internal) dalam lintasan tersebut.

Dengan kata lain, sebelum fase ke-$k$, nilai dari $d[i][j]$ sama dengan panjang lintasan terpendek dari _vertex_ $i$ ke _vertex_ $j$, jika lintasan ini hanya diizinkan melewati _vertex_ dengan nomor yang lebih kecil dari $k$ (titik awal dan akhir lintasan tidak dibatasi oleh aturan ini).

Sifat ini sangat mudah dipastikan terpenuhi pada fase pertama. Untuk $k = 0$, kita dapat mengisi _matrix_ dengan $d[i][j] = w_{i j}$ jika terdapat _edge_ antara $i$ dan $j$ dengan bobot $w_{i j}$, dan $d[i][j] = \infty$ jika tidak ada _edge_. Dalam praktiknya, $\infty$ akan direpresentasikan oleh suatu nilai yang sangat besar. Seperti yang akan kita lihat nanti, ini merupakan sebuah syarat wajib bagi algoritma.

Sekarang, asumsikan kita berada pada fase ke-$k$, dan kita ingin menghitung _matrix_ $d[ ][ ]$ agar memenuhi syarat untuk fase ke-$(k + 1)$. Kita harus memperbarui jarak untuk beberapa pasangan _vertices_ $(i, j)$. Ada dua kasus yang mendasarinya:

1. Lintasan terpendek dari _vertex_ $i$ ke _vertex_ $j$ dengan _internal vertices_ dari himpunan $\{1, 2, \dots, k\}$ sama persis dengan lintasan terpendek dengan _internal vertices_ dari himpunan $\{1, 2, \dots, k-1\}$.
    
    Dalam kasus ini, nilai $d[i][j]$ tidak akan berubah selama transisi fase.
    
1. Lintasan terpendek dengan _internal vertices_ dari $\{1, 2, \dots, k\}$ bernilai lebih pendek.
    
    Ini berarti lintasan baru yang lebih pendek tersebut melewati _vertex_ $k$. Artinya, kita dapat membagi lintasan terpendek antara $i$ dan $j$ menjadi dua lintasan: lintasan antara $i$ dan $k$, serta lintasan antara $k$ dan $j$. Jelas bahwa kedua lintasan tersebut hanya menggunakan _internal vertices_ dari $\{1, 2, \dots, k-1\}$ dan merupakan lintasan terpendek yang memenuhi syarat tersebut. Oleh karena itu, kita sudah menghitung panjang dari lintasan-lintasan tersebut sebelumnya, dan kita dapat menghitung panjang lintasan terpendek antara $i$ dan $j$ sebagai $d[i][k] + d[k][j]$.
    

Dengan menggabungkan kedua kasus ini, kita dapat menghitung kembali panjang untuk semua pasangan $(i, j)$ pada fase ke-$k$ dengan cara berikut:

$$d_{\text{baru}}[i][j] = \min(d[i][j], d[i][k] + d[k][j])$$

Dengan demikian, semua pekerjaan yang diperlukan pada fase ke-$k$ hanyalah melakukan iterasi pada semua pasangan _vertices_ dan menghitung kembali panjang lintasan terpendek di antara mereka. Hasilnya, setelah fase ke-$n$, nilai $d[i][j]$ di dalam _matrix_ jarak adalah panjang lintasan terpendek antara $i$ dan $j$, atau bernilai $\infty$ jika lintasan antara _vertex_ $i$ dan $j$ tidak ada.

Catatan terakhir — kita tidak perlu membuat _matrix_ jarak terpisah $d_{\text{baru}}[ ][ ]$ untuk menyimpan lintasan terpendek dari fase ke-$k$ secara sementara. Artinya, semua perubahan dapat dilakukan langsung pada _matrix_ $d[ ][ ]$ di fase mana pun. Faktanya, pada fase ke-$k$ mana pun, kita paling banyak hanya meningkatkan (memperpendek) jarak dari suatu lintasan di dalam _matrix_ jarak. Oleh karena itu, kita tidak akan memperburuk panjang lintasan terpendek untuk pasangan _vertices_ mana pun yang akan diproses pada fase ke-$(k+1)$ atau setelahnya.

_Time complexity_ (kompleksitas waktu) dari algoritma ini sudah jelas sebesar $O(n^3)$.

## Implementasi

Misalkan $d[][]$ adalah sebuah _2D array_ (array dua dimensi) berukuran $n \times n$, yang diisi sesuai dengan fase ke-$0$ seperti yang telah dijelaskan sebelumnya. Kita juga akan menetapkan nilai $d[i][i] = 0$ untuk setiap $i$ pada fase ke-$0$.

Kemudian algoritma diimplementasikan sebagai berikut:

```cpp
for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
    }
}
```

Diasumsikan bahwa jika tidak ada _edge_ antara dua _vertices_ $i$ dan $j$, maka isi _matrix_ pada $d[i][j]$ berisi sebuah angka yang besar (cukup besar sehingga nilainya lebih besar dari panjang lintasan mana pun di dalam _graph_ ini). Dengan begitu, _edge_ ini akan selalu tidak menguntungkan untuk diambil, dan algoritma akan berjalan dengan benar.

Namun, jika terdapat _edge_ dengan bobot negatif di dalam graf, langkah pencegahan khusus harus diambil. Jika tidak, nilai akhir di dalam _matrix_ mungkin akan berbentuk $\infty - 1$, $\infty - 2$, dll., yang mana tentu saja nilai tersebut sebenarnya tetap menunjukkan bahwa tidak ada lintasan di antara _vertices_ yang bersangkutan. Oleh karena itu, jika _graph_ memiliki _edge_ dengan bobot negatif, lebih baik menulis algoritma Floyd-Warshall dengan cara berikut, sehingga ia tidak melakukan transisi menggunakan lintasan yang sebenarnya tidak ada.


```cpp
for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (d[i][k] < INF && d[k][j] < INF)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
    }
}
```

## Rekonstruksi Urutan Vertices pada Shortest Path

Sangat mudah untuk menyimpan informasi tambahan yang dapat digunakan untuk merekonstruksi _shortest path_ antara dua _vertices_ tertentu dalam bentuk urutan _vertices_.

Untuk melakukan ini, selain _matrix_ jarak $d[ ][ ]$, sebuah _matrix_ leluhur/induk $p[ ][ ]$ (_matrix of ancestors_) harus dipertahankan. _Matrix_ ini akan berisi nomor fase di mana jarak terpendek antara dua _vertices_ terakhir kali diubah. Jelas bahwa nomor fase tersebut tidak lain adalah _vertex_ yang berada di tengah-tengah lintasan terpendek yang dicari. Sekarang kita hanya perlu mencari _shortest path_ antara _vertices_ $i$ dan $p[i][j]$, serta antara $p[i][j]$ dan $j$. Hal ini mengarah pada algoritma rekonstruksi _shortest path_ berbasis rekursif yang sederhana.

## Kasus Bobot Riil (Real Weights)

Jika bobot dari _edge_ bukan berupa bilangan bulat (_integer_) melainkan bilangan riil (_real/float_), kita perlu memperhitungkan _error_ (galat) yang terjadi saat bekerja dengan tipe data _float_.

Algoritma Floyd-Warshall memiliki efek samping yang tidak menyenangkan, yaitu _error_ dapat terakumulasi dengan sangat cepat. Faktanya, jika terdapat _error_ sebesar $\delta$ pada fase pertama, _error_ ini dapat merambat ke iterasi kedua menjadi $2 \delta$, ke iterasi ketiga menjadi $4 \delta$, dan seterusnya.

Untuk menghindari hal ini, algoritma dapat dimodifikasi untuk memperhitungkan _error_ ($\text{EPS} = \delta$) dengan menggunakan perbandingan berikut:

```cpp
if (d[i][k] + d[k][j] < d[i][j] - EPS)
    d[i][j] = d[i][k] + d[k][j]; 
```

## Kasus Negative Cycles

Secara formal, algoritma Floyd-Warshall tidak berlaku untuk _graph_ yang mengandung _negative weight cycle_. Namun, untuk semua pasangan _vertices_ $i$ dan $j$ yang tidak memiliki lintasan yang dimulai dari $i$, mengunjungi _negative cycle_, dan berakhir di $j$, algoritma ini akan tetap bekerja dengan benar.

Untuk pasangan _vertices_ yang jawabannya tidak ada (karena adanya _negative cycle_ di dalam lintasan di antara mereka), algoritma Floyd akan menyimpan angka acak (mungkin bernilai sangat negatif, tetapi tidak selalu) di dalam _matrix_ jarak. Meskipun demikian, kita bisa meningkatkan algoritma Floyd-Warshall agar dapat menangani pasangan _vertices_ tersebut dengan cermat, dan mengeluarkan hasilnya, misalnya sebagai $-\text{INF}$.

Hal ini dapat dilakukan dengan cara berikut: mari kita jalankan algoritma Floyd-Warshall standar untuk _graph_ yang diberikan. Kemudian, lintasan terpendek antara _vertices_ $i$ dan $j$ dianggap tidak ada jika dan hanya jika terdapat suatu _vertex_ $t$ sedemikian rupa sehingga $t$ dapat dijangkau dari $i$ dan $j$ dapat dijangkau dari $t$, di mana nilai $d[t][t] < 0$.

Selain itu, saat menggunakan algoritma Floyd-Warshall untuk _graph_ dengan _negative cycles_, kita harus ingat bahwa situasi di mana jarak dapat menurun ke arah negatif secara eksponensial bisa saja terjadi. Oleh karena itu, _integer overflow_ harus ditangani dengan membatasi jarak minimal menggunakan suatu nilai tertentu (misalnya $-\text{INF}$).

Untuk mempelajari lebih lanjut tentang pencarian _negative cycles_ di dalam graf, silakan lihat artikel terpisah _"Finding a negative cycle in the graph"_.