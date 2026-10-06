# Segment Tree 

*Segment Tree* adalah struktur data yang menyimpan informasi tentang *interval array* dalam bentuk pohon. Hal ini memungkinkan penyelesaian *range query* pada suatu *array* secara efisien, namun tetap cukup fleksibel untuk mengizinkan modifikasi cepat pada *array* tersebut. Ini mencakup pencarian jumlah dari elemen-elemen *array* yang berurutan $a[l \dots r]$, atau mencari elemen minimum dalam rentang tersebut dalam waktu $O(\log n)$. Di antara proses menjawab *query* tersebut, *Segment Tree* memungkinkan modifikasi *array* dengan mengganti satu elemen, atau bahkan mengubah elemen-elemen dari seluruh *subsegment* (misalnya menetapkan semua elemen $a[l \dots r]$ ke nilai apa pun, atau menambahkan suatu nilai ke semua elemen dalam *subsegment* tersebut).

Secara umum, *Segment Tree* adalah struktur data yang sangat fleksibel, dan sejumlah besar masalah dapat diselesaikan dengannya. Selain itu, dimungkinkan juga untuk menerapkan operasi yang lebih kompleks dan menjawab *query* yang lebih rumit (lihat versi lanjutan dari *Segment Tree*). Secara khusus, *Segment Tree* dapat dengan mudah digeneralisasi ke dimensi yang lebih besar. Sebagai contoh, dengan *Segment Tree* dua dimensi, Anda dapat menjawab *query* jumlah atau minimum pada suatu *subrectangle* dari matriks yang diberikan hanya dalam waktu $O(\log^2 n)$.

Salah satu sifat penting dari *Segment Tree* adalah bahwa struktur data ini hanya membutuhkan jumlah memori linier. *Segment Tree* standar membutuhkan $4n$ *vertex* untuk bekerja pada *array* berukuran $n$.

## Simplest form of a Segment Tree

Untuk memulai dengan mudah, kita mempertimbangkan bentuk paling sederhana dari *Segment Tree*. Kita ingin menjawab *sum query* secara efisien. Definisi formal dari tugas kita adalah: Diberikan sebuah *array* $a[0 \dots n-1]$, *Segment Tree* harus mampu menemukan jumlah elemen antara indeks $l$ dan $r$ (yaitu menghitung jumlah $\sum_{i=l}^r a[i]$), dan juga menangani perubahan nilai elemen-elemen dalam *array* tersebut (yaitu melakukan *assignment* dalam bentuk $a[i] = x$). *Segment Tree* harus mampu memproses kedua jenis *query* tersebut dalam waktu $O(\log n)$.

Ini merupakan peningkatan dari pendekatan-pendekatan yang lebih sederhana. Implementasi *array* yang naif — hanya menggunakan *array* sederhana — dapat melakukan *update* elemen dalam waktu $O(1)$, tetapi membutuhkan waktu $O(n)$ untuk menghitung setiap *sum query*. Sementara itu, *prefix sum* yang dihitung di awal (*precomputed*) dapat menghitung *sum query* dalam waktu $O(1)$, tetapi melakukan *update* pada satu elemen *array* membutuhkan $O(n)$ perubahan pada *prefix sum* tersebut.

### Structure of the Segment Tree

Kita dapat menggunakan pendekatan *divide-and-conquer* untuk segmen-segmen *array*. Kita menghitung dan menyimpan jumlah dari elemen-elemen seluruh *array*, yaitu jumlah dari segmen $a[0 \dots n-1]$. Kemudian kita membagi *array* tersebut menjadi dua paruh, $a[0 \dots (n-1)/2]$ dan $a[(n+1)/2 \dots n-1]$, lalu menghitung serta menyimpan jumlah dari masing-masing paruh tersebut. Setiap dari kedua paruh ini nantinya dibagi dua lagi secara bergantian, dan seterusnya hingga semua segmen mencapai ukuran $1$.

Kita dapat melihat segmen-segmen ini membentuk sebuah *binary tree*: *root* dari *tree* ini adalah segmen $a[0 \dots n-1]$, dan setiap *vertex* (kecuali *leaf vertex*) memiliki tepat dua *child vertex*. Inilah alasan mengapa struktur data ini dinamakan "*Segment Tree*", meskipun pada sebagian besar implementasi, *tree* tersebut tidak dikonstruksi secara eksplisit (lihat Implementasi).

Berikut adalah representasi visual dari *Segment Tree* pada *array* $a = [1, 3, -2, 8, -7]$:

![](Segment%20Tree-2.png)

Dari deskripsi singkat mengenai struktur data ini, kita sudah dapat menyimpulkan bahwa *Segment Tree* hanya membutuhkan jumlah *vertex* yang linier. Tingkat pertama dari *tree* berisi satu *node* (*root*), tingkat kedua akan berisi dua *vertex*, tingkat ketiga berisi empat *vertex*, hingga jumlah *vertex* mencapai $n$. Dengan demikian, jumlah *vertex* pada kasus terburuk (*worst case*) dapat diestimasi melalui deret penjumlahan $1 + 2 + 4 + \dots + 2^{\lceil\log_2 n\rceil} \lt 2^{\lceil\log_2 n\rceil + 1} \lt 4n$.

Perlu dicatat bahwa setiap kali $n$ bukan merupakan perpangkatan dua, tidak semua tingkat pada *Segment Tree* akan terisi penuh. Kita dapat melihat perilaku tersebut pada gambar. Untuk saat ini kita bisa mengabaikan fakta ini, tetapi hal tersebut akan menjadi penting nanti saat tahap implementasi.

Tinggi dari *Segment Tree* adalah $O(\log n)$, karena ketika turun dari *root* menuju *leaf*, ukuran segmen berkurang kira-kira separuhnya.
### Construction

Sebelum mengonstruksi *segment tree*, kita perlu memutuskan:

* nilai yang disimpan pada setiap *node* dari *segment tree*. Sebagai contoh, pada *sum segment tree*, sebuah *node* akan menyimpan jumlah elemen dalam rentangnya $[l, r]$.
* operasi *merge* yang menggabungkan dua *sibling* dalam *segment tree*. Sebagai contoh, pada *sum segment tree*, dua *node* yang bersesuaian dengan rentang $a[l_1 \dots r_1]$ dan $a[l_2 \dots r_2]$ akan di-*merge* menjadi sebuah *node* yang bersesuaian dengan rentang $a[l_1 \dots r_2]$ dengan menjumlahkan nilai dari kedua *node* tersebut.

Catat bahwa sebuah *vertex* merupakan *leaf vertex* jika segmen yang bersesuaian dengannya hanya mencakup satu nilai pada *array* asli. *Leaf vertex* berada di tingkat paling bawah dari *segment tree*. Nilainya akan sama dengan elemen (yang bersesuaian) $a[i]$.

Sekarang, untuk konstruksi *segment tree*, kita mulai dari tingkat paling bawah (*leaf vertex*) dan menetapkan nilai masing-masing. Berdasarkan nilai-nilai ini, kita dapat menghitung nilai dari tingkat sebelumnya menggunakan fungsi *merge*. Berdasarkan nilai tersebut, kita dapat menghitung nilai dari tingkat sebelumnya lagi, dan mengulangi prosedur ini hingga mencapai *root vertex*.

Akan lebih praktis untuk menjelaskan operasi ini secara rekursif dari arah sebaliknya, yaitu dari *root vertex* menuju *leaf vertex*. Prosedur konstruksi, jika dipanggil pada *non-leaf vertex*, melakukan hal berikut:

* mengonstruksi nilai dari kedua *child vertex* secara rekursif
* melakukan *merge* pada nilai-nilai yang telah dihitung dari *children* tersebut.

Kita memulai konstruksi dari *root vertex*, dan dengan demikian, kita dapat menghitung keseluruhan *segment tree*.

Kompleksitas waktu dari konstruksi ini adalah $O(n)$, dengan asumsi bahwa operasi *merge* membutuhkan waktu konstan (operasi *merge* dipanggil sebanyak $n$ kali, yang sama dengan jumlah *internal node* pada *segment tree*).

### Sum Queries

Untuk saat ini kita akan menjawab *sum query*. Sebagai masukan, kita menerima dua buah *integer* $l$ dan $r$, dan kita harus menghitung jumlah dari segmen $a[l \dots r]$ dalam waktu $O(\log n)$.

Untuk melakukan hal ini, kita akan melintasi (*traverse*) *Segment Tree* dan menggunakan hasil penjumlahan segmen yang telah dihitung sebelumnya (*precomputed sums*). Mari kita asumsikan bahwa saat ini kita berada di *vertex* yang mencakup segmen $a[tl \dots tr]$. Ada tiga kasus yang mungkin terjadi.

Kasus termudah adalah ketika segmen $a[l \dots r]$ sama dengan segmen yang bersesuaian pada *vertex* saat ini (yaitu $a[l \dots r] = a[tl \dots tr]$), maka proses selesai dan kita dapat mengembalikan nilai penjumlahan yang telah dihitung sebelumnya (*precomputed sum*) yang tersimpan pada *vertex* tersebut.

Secara alternatif, segmen dari *query* dapat jatuh sepenuhnya ke dalam domain dari *left child* atau *right child*. Ingat kembali bahwa *left child* mencakup segmen $a[tl \dots tm]$ dan *right vertex* mencakup segmen $a[tm + 1 \dots tr]$ dengan $tm = (tl + tr) / 2$. Dalam kasus ini, kita cukup pergi ke *child vertex* yang segmennya mencakup segmen *query* tersebut, lalu menjalankan algoritma yang dijelaskan di sini pada *vertex* tersebut.

Kemudian ada kasus terakhir, yaitu segmen *query* berpotongan (*intersect*) dengan kedua *children*. Dalam kasus ini, kita tidak punya pilihan lain selain melakukan dua pemanggilan rekursif (*recursive calls*), masing-masing untuk setiap *child*. Pertama, kita pergi ke *left child*, menghitung jawaban parsial untuk *vertex* ini (yaitu jumlah nilai dari perpotongan antara segmen *query* dan segmen dari *left child*), kemudian pergi ke *right child*, menghitung jawaban parsial menggunakan *vertex* tersebut, lalu menggabungkan kedua jawaban dengan menjumlahkannya. Dengan kata lain, karena *left child* merepresentasikan segmen $a[tl \dots tm]$ dan *right child* merepresentasikan segmen $a[tm+1 \dots tr]$, kita menghitung *sum query* $a[l \dots tm]$ menggunakan *left child*, dan *sum query* $a[tm+1 \dots r]$ menggunakan *right child*.

Jadi, pemrosesan *sum query* adalah sebuah fungsi yang secara rekursif memanggil dirinya sendiri sekali dengan *left child* atau *right child* (tanpa mengubah batasan *query*), atau dua kali, sekali untuk *left child* dan sekali untuk *right child* (dengan membagi *query* menjadi dua *subquery*). Rekursi berakhir kapan saja batasan dari segmen *query* saat ini cocok dengan batasan dari segmen *vertex* saat ini. Dalam kasus tersebut, jawabannya adalah nilai *precomputed* dari penjumlahan segmen ini, yang tersimpan di dalam *tree*.

Dengan kata lain, kalkulasi dari *query* adalah penelusuran (*traversal*) *tree*, yang menyebar melalui semua cabang *tree* yang diperlukan, dan menggunakan nilai penjumlahan segmen yang telah dihitung sebelumnya (*precomputed sum values*) di dalam *tree*.

Tentu saja kita akan memulai penelusuran dari *root vertex* pada *Segment Tree*.

Prosedur ini diilustrasikan pada gambar berikut. Sekali lagi *array* $a = [1, 3, -2, 8, -7]$ digunakan, dan di sini kita ingin menghitung jumlah $\sum_{i=2}^4 a[i]$. *Vertex* yang berwarna akan dikunjungi, dan kita akan menggunakan nilai *precomputed* dari *vertex* yang berwarna hijau. Ini memberi kita hasil $-2 + 1 = -1$.

![660](Segment%20Tree-1.png)

Mengapa kompleksitas dari algoritma ini adalah $O(\log n)$? Untuk menunjukkan kompleksitas ini, kita dapat melihat setiap tingkat (*level*) dari *tree*. Ternyata, untuk setiap tingkat kita tidak pernah mengunjungi lebih dari empat *vertices*. Dan karena tinggi dari *tree* adalah $O(\log n)$, kita mendapatkan *running time* yang diinginkan.

Kita dapat membuktikan bahwa proposisi ini (paling banyak empat *vertices* pada setiap tingkat) adalah benar menggunakan induksi. Pada tingkat pertama, kita hanya mengunjungi satu *vertex*, yaitu *root vertex*, sehingga di sini kita mengunjungi kurang dari empat *vertices*. Sekarang mari kita lihat tingkat sembarang. Berdasarkan hipotesis induksi, kita mengunjungi paling banyak empat *vertices*. Jika kita hanya mengunjungi paling banyak dua *vertices*, maka tingkat berikutnya akan memiliki paling banyak empat *vertices*. Hal ini trivial, karena setiap *vertex* hanya dapat menyebabkan paling banyak dua pemanggilan rekursif (*recursive calls*). Jadi, mari kita asumsikan bahwa kita mengunjungi tiga atau empat *vertices* pada tingkat saat ini. Dari *vertices* tersebut, kita akan menganalisis *vertices* yang berada di tengah secara lebih cermat. Karena *sum query* meminta jumlah dari *subarray* yang kontigu, kita tahu bahwa segmen-segmen yang bersesuaian dengan *vertices* di tengah yang dikunjungi akan sepenuhnya tertutup (*completely covered*) oleh segmen dari *sum query*. Oleh karena itu, *vertices* tersebut tidak akan melakukan pemanggilan rekursif apa pun. Jadi, hanya *vertex* paling kiri dan *vertex* paling kanan yang memiliki potensi untuk melakukan pemanggilan rekursif. Dan keduanya hanya akan menghasilkan paling banyak empat pemanggilan rekursif, sehingga tingkat berikutnya juga akan memenuhi asersi tersebut. Kita dapat mengatakan bahwa satu cabang mendekati batasan kiri dari *query*, dan cabang kedua mendekati batasan kanan.

Oleh karena itu, kita mengunjungi paling banyak $4 \log n$ *vertices* secara keseluruhan, dan hal tersebut setara dengan *running time* sebesar $O(\log n)$.

Kesimpulannya, *query* bekerja dengan membagi segmen *input* menjadi beberapa *sub-segment* yang seluruh nilai pemjumlahannya telah dihitung sebelumnya (*precomputed*) dan disimpan di dalam *tree*. Dan jika kita berhenti melakukan pembagian (*partitioning*) setiap kali segmen *query* cocok dengan segmen *vertex*, maka kita hanya membutuhkan $O(\log n)$ segmen seperti itu, yang menjadi sumber efektivitas dari *Segment Tree*.

### Update queries

Sekarang kita ingin mengubah elemen tertentu di dalam *array*, katakanlah kita ingin melakukan *assignment* $a[i] = x$. Dan kita harus membangun ulang *Segment Tree*, sedemikian rupa sehingga bersesuaian dengan *array* baru yang telah dimodifikasi tersebut.

*Query* ini lebih mudah dibandingkan dengan *sum query*. Setiap tingkat (*level*) dari sebuah *Segment Tree* membentuk partisi dari *array*. Oleh karena itu, sebuah elemen $a[i]$ hanya berkontribusi pada satu segmen dari setiap tingkat. Dengan demikian, hanya $O(\log n)$ *vertices* yang perlu diperbarui (*updated*).

Sangat mudah untuk melihat bahwa permintaan *update* dapat diimplementasikan menggunakan fungsi rekursif. Fungsi ini menerima kiriman parameter berupa *current tree vertex*, dan secara rekursif memanggil dirinya sendiri dengan salah satu dari dua *child vertices* (yaitu yang memuat $a[i]$ dalam segmennya), dan setelah itu menghitung ulang nilai *sum*-nya, mirip seperti yang dilakukan pada metode *build* (yaitu sebagai jumlah dari kedua *children*-nya).

Sekali lagi, berikut adalah visualisasi menggunakan *array* yang sama. Di sini kita melakukan *update* $a[2] = 3$. *Vertex* yang berwarna hijau adalah *vertices* yang kita kunjungi dan perbarui.

### Implementation

Pertimbangan utamanya adalah bagaimana cara menyimpan *Segment Tree*. Tentu saja kita bisa mendefinisikan sebuah *struct* $\text{Vertex}$ dan membuat objek-objek yang menyimpan batasan segmen, jumlahnya, serta *pointer* tambahan ke *child vertices*-nya. Namun, hal ini memerlukan penyimpanan banyak informasi redundan dalam bentuk *pointer*. Kita akan menggunakan trik sederhana untuk membuatnya jauh lebih efisien dengan menggunakan *implicit data structure*: Hanya menyimpan nilai *sum* di dalam sebuah *array*. (Metode serupa juga digunakan untuk *binary heap*). Jumlah dari *root vertex* berada pada indeks 1, jumlah dari kedua *child vertices*-nya pada indeks 2 dan 3, jumlah dari *children* dari kedua *vertex* tersebut pada indeks 4 hingga 7, dan seterusnya. Dengan *1-indexing*, secara praktis *left child* dari sebuah *vertex* pada indeks $i$ disimpan pada indeks $2i$, dan *right child* pada indeks $2i + 1$. Secara ekuivalen, *parent* dari sebuah *vertex* pada indeks $i$ disimpan pada $i/2$ (*integer division*).

Hal ini sangat menyederhanakan implementasi. Kita tidak perlu menyimpan struktur *tree* di dalam memori. Struktur tersebut terdefinisi secara tersirat (*implicitly*). Kita hanya membutuhkan satu *array* yang berisi jumlah dari semua segmen.

Seperti yang telah disebutkan sebelumnya, kita perlu menyimpan paling banyak $4n$ *vertices*. Jumlahnya mungkin bisa lebih sedikit, tetapi untuk kemudahan kita selalu mengalokasikan *array* berukuran $4n$. Akan ada beberapa elemen dalam *array sum* yang tidak bersesuaian dengan *vertex* mana pun pada *tree* sebenarnya, tetapi hal ini tidak mempersulit implementasi.

Jadi, kita menyimpan *Segment Tree* cukup sebagai sebuah *array* $t[]$ dengan ukuran empat kali dari ukuran *input* $n$:

```cpp
int n, t[4*MAXN];
```

Prosedur untuk mengonstruksi *Segment Tree* dari *array* $a[]$ yang diberikan terlihat seperti ini: ini adalah fungsi rekursif dengan parameter $a[]$ (*input array*), $v$ (indeks dari *current vertex*), serta batasan $tl$ dan $tr$ dari segmen saat ini. Pada program utama, fungsi ini akan dipanggil dengan parameter dari *root vertex*: $v = 1$, $tl = 0$, dan $tr = n - 1$.

```cpp
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
```

Selanjutnya, fungsi untuk menjawab *sum query* juga merupakan fungsi rekursif, yang menerima parameter berupa informasi tentang *current vertex/segment* (yaitu indeks $v$ serta batasan $tl$ dan $tr$) dan juga informasi tentang batasan dari *query*, yaitu $l$ dan $r$. Untuk menyederhanakan kode, fungsi ini selalu melakukan dua pemanggilan rekursif (*recursive calls*), bahkan jika hanya satu yang diperlukan — dalam kasus tersebut pemanggilan rekursif yang tidak perlu akan memiliki $l > r$, dan hal ini dapat dengan mudah ditangani menggunakan pengecekan tambahan di awal fungsi.

```cpp
int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}
```

Terakhir adalah *update query*. Fungsi ini juga akan menerima informasi tentang *current vertex/segment*, dan secara tambahan juga parameter dari *update query* (yaitu posisi elemen beserta nilai barunya).

```cpp
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}
```

### Memory efficient implementation

Sebagian besar orang menggunakan implementasi dari bagian sebelumnya. Jika Anda melihat *array* `t`, Anda dapat melihat bahwa *array* tersebut mengikuti penomoran *node-node tree* dalam urutan *BFS traversal* (*level-order traversal*). Menggunakan penelusuran ini, *children* dari *vertex* $v$ masing-masing berada pada $2v$ dan $2v + 1$. Namun, jika $n$ bukan merupakan perpangkatan dua, metode ini akan melewati beberapa indeks dan membiarkan beberapa bagian dari *array* `t` tidak terpakai. Konsumsi memori dibatasi sebesar $4n$, meskipun sebuah *Segment Tree* dari *array* berukuran $n$ elemen sebenarnya hanya membutuhkan $2n - 1$ *vertices*.

Namun, hal tersebut dapat dikurangi. Kita menomori ulang *vertices* dari *tree* dalam urutan *Euler tour traversal* (*pre-order traversal*), dan kita menuliskan semua *vertices* ini secara berurutan berdampingan.

Mari kita lihat sebuah *vertex* pada indeks $v$, dan biarkan *vertex* tersebut bertanggung jawab atas segmen $[l, r]$, serta misalkan $mid = \dfrac{l + r}{2}$. Sangat jelas bahwa *left child* akan memiliki indeks $v + 1$. *Left child* bertanggung jawab atas segmen $[l, mid]$, yaitu secara total akan ada $2 \times (mid - l + 1) - 1$ *vertices* di dalam *subtree* milik *left child*. Dengan demikian, kita dapat menghitung indeks dari *right child* milik $v$. Indeksnya adalah $v + 2 \times (mid - l + 1)$. Melalui penomoran ini, kita mencapai pengurangan memori yang dibutuhkan menjadi $2n$.

## Advanced versions of Segment Trees

*Segment Tree* adalah struktur data yang sangat fleksibel, serta memungkinkan variasi dan ekstensi ke berbagai arah yang berbeda. Mari kita coba mengelompokkannya di bawah ini.

### More complex queries

Mengubah *Segment Tree* agar dapat menghitung *query* yang berbeda (misalnya menghitung nilai minimum / maksimum alih-alih jumlah) bisa sangat mudah dilakukan, tetapi bisa juga menjadi sangat non-trivial.

#### Mencari Nilai Maksimum

Mari kita sedikit mengubah kondisi dari masalah yang dijelaskan di atas: alih-alih melakukan *query* untuk mencari jumlah, kita sekarang akan melakukan *maximum query*.

*Tree* akan memiliki struktur yang persis sama dengan *tree* yang dijelaskan sebelumnya. Kita hanya perlu mengubah cara $t[v]$ dihitung dalam fungsi $\text{build}$ dan $\text{update}$. $t[v]$ sekarang akan menyimpan nilai maksimum dari segmen yang bersesuaian. Kita juga perlu mengubah kalkulasi dari nilai yang dikembalikan oleh fungsi $\text{sum}$ (mengganti penjumlahan dengan nilai maksimum).

Tentu saja masalah ini dapat dengan mudah diubah untuk menghitung nilai minimum alih-alih maksimum.

Daripada menampilkan implementasi untuk masalah ini, implementasi akan diberikan untuk versi yang lebih kompleks dari masalah ini di bagian selanjutnya.

#### Mencari Nilai Maksimum dan Jumlah Kemunculannya

Tugas ini sangat mirip dengan tugas sebelumnya. Selain menemukan nilai maksimum, kita juga harus menemukan jumlah kemunculan dari nilai maksimum tersebut.

Untuk menyelesaikan masalah ini, kita menyimpan sepasang angka (*pair of numbers*) pada setiap *vertex* di dalam *tree*: Selain nilai maksimum, kita juga menyimpan jumlah kemunculannya pada segmen yang bersesuaian. Menentukan *pair* yang tepat untuk disimpan pada $t[v]$ masih dapat dilakukan dalam waktu konstan menggunakan informasi dari *pair* yang tersimpan pada *child vertices*. Penggabungan dua *pair* tersebut sebaiknya dilakukan dalam fungsi terpisah, karena ini akan menjadi operasi yang dilakukan saat membangun *tree*, saat menjawab *maximum query*, dan saat melakukan modifikasi.

```cpp
pair<int, int> t[4*MAXN];

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) 
        return a;
    if (b.first > a.first)
        return b;
    return make_pair(a.first, a.second + b.second);
}

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_pair(a[tl], 1);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

pair<int, int> get_max(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return make_pair(-INF, 0);
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(get_max(v*2, tl, tm, l, min(r, tm)), 
                   get_max(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = make_pair(new_val, 1);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}
```

#### Menghitung *Greatest Common Divisor* / *Least Common Multiple*

Pada masalah ini, kita ingin menghitung *GCD* / *LCM* dari semua angka dalam rentang tertentu pada *array*.

Variasi *Segment Tree* yang menarik ini dapat diselesaikan dengan cara yang persis sama seperti *Segment Tree* yang kita turunkan untuk *sum* / *minimum* / *maximum queries*: cukup dengan menyimpan *GCD* / *LCM* dari *vertex* yang bersesuaian pada setiap *vertex* di dalam *tree*. Penggabungan dua *vertices* dapat dilakukan dengan menghitung *GCD* / *LCM* dari kedua *vertices* tersebut.

#### Menghitung Jumlah Angka Nol, Mencari Angka Nol ke-$k$

Pada masalah ini, kita ingin menemukan jumlah angka nol dalam rentang tertentu, dan secara tambahan menemukan indeks dari angka nol ke-$k$ menggunakan fungsi kedua.

Sekali lagi kita harus sedikit mengubah nilai yang disimpan pada *tree*: Kali ini kita akan menyimpan jumlah angka nol dari setiap segmen di dalam `t[]`. Cukup jelas bagaimana cara mengimplementasikan fungsi $\text{build}$, $\text{update}$, dan $\text{count\_zero}$, kita dapat menggunakan ide dari masalah *sum query*. Dengan demikian kita telah menyelesaikan bagian pertama dari masalah ini.

Sekarang kita mempelajari cara menyelesaikan masalah mencari angka nol ke-$k$ pada *array* $a[]$. Untuk melakukan tugas ini, kita akan turun melintasi *Segment Tree*, dimulai dari *root vertex*, dan bergerak setiap kalinya ke *left child* atau *right child*, tergantung pada segmen mana yang memuat angka nol ke-$k$. Untuk memutuskan ke *child* mana kita harus pergi, cukup dengan melihat jumlah angka nol yang muncul pada segmen yang bersesuaian dengan *left vertex*. Jika jumlah *precomputed* ini lebih besar atau sama dengan $k$, maka kita perlu turun ke *left child*, dan jika tidak, kita turun ke *right child*. Perhatikan, jika kita memilih *right child*, kita harus mengurangkan jumlah angka nol dari *left child* dari nilai $k$.

Pada implementasi, kita dapat menangani kasus khusus di mana $a[]$ memuat kurang dari $k$ angka nol dengan mengembalikan nilai -1.

```cpp
int find_kth(int v, int tl, int tr, int k) {
    if (k > t[v])
        return -1;
    if (tl == tr)
        return tl;
    int tm = (tl + tr) / 2;
    if (t[v*2] >= k)
        return find_kth(v*2, tl, tm, k);
    else 
        return find_kth(v*2+1, tm+1, tr, k - t[v*2]);
}
```

#### Mencari *Prefix Array* dengan Jumlah Tertentu

Tugasnya adalah sebagai berikut: untuk suatu nilai $x$ yang diberikan, kita harus menemukan indeks terkecil $i$ secara cepat sedemikian rupa sehingga jumlah dari $i$ elemen pertama pada *array* $a[]$ lebih besar atau sama dengan $x$ (dengan asumsi bahwa *array* $a[]$ hanya memuat nilai-nilai non-negatif).

Tugas ini dapat diselesaikan menggunakan *binary search*, dengan menghitung jumlah *prefix* menggunakan *Segment Tree*. Namun, hal ini akan menghasilkan solusi dengan kompleksitas $O(\log^2 n)$.

Sebagai gantinya, kita dapat menggunakan ide yang sama seperti pada bagian sebelumnya, dan menemukan posisinya dengan menelusuri turun (*descending*) pada *tree*: yaitu dengan bergerak setiap kalinya ke kiri atau ke kanan, tergantung pada jumlah dari *left child*. Dengan demikian, kita menemukan jawabannya dalam waktu $O(\log n)$.

#### Mencari Elemen Pertama yang Lebih Besar dari Jumlah Tertentu

Tugasnya adalah sebagai berikut: untuk suatu nilai $x$ dan rentang $a[l \dots r]$ yang diberikan, temukan $i$ terkecil dalam rentang $a[l \dots r]$ sedemikian rupa sehingga $a[i]$ lebih besar dari $x$.

Tugas ini dapat diselesaikan menggunakan *binary search* di atas *max prefix queries* dengan *Segment Tree*. Namun, hal ini akan menghasilkan solusi dengan kompleksitas $O(\log^2 n)$.

Sebagai gantinya, kita dapat menggunakan ide yang sama seperti pada bagian-bagian sebelumnya, dan menemukan posisinya dengan menelusuri turun (*descending*) pada *tree*: yaitu dengan bergerak setiap kalinya ke kiri atau ke kanan, tergantung pada nilai maksimum dari *left child*. Dengan demikian, kita menemukan jawabannya dalam waktu $O(\log n)$.

```cpp
int get_first(int v, int tl, int tr, int l, int r, int x) {
    if(tl > r || tr < l) return -1;
    if(t[v] <= x) return -1;

    if (tl== tr) return tl;

    int tm = tl + (tr-tl)/2;
    int left = get_first(2*v, tl, tm, l, r, x);
    if(left != -1) return left;
    return get_first(2*v+1, tm+1, tr, l ,r, x);
}
```

#### Mencari *Subsegment* dengan Jumlah Maksimal

Di sini kita kembali menerima sebuah rentang $a[l \dots r]$ untuk setiap *query*, dan kali ini kita harus menemukan sebuah *subsegment* $a[l^\prime \dots r^\prime]$ sedemikian rupa sehingga $l \le l^\prime$ dan $r^\prime \le r$, serta jumlah elemen-elemen dari segmen ini bernilai maksimal. Seperti sebelumnya, kita juga ingin dapat memodifikasi elemen individual dari *array*. Elemen-elemen dari *array* dapat bernilai negatif, dan *subsegment* optimal bisa saja kosong (misalnya jika semua elemen bernilai negatif).

Masalah ini merupakan penggunaan *Segment Tree* yang *non-trivial*. Kali ini kita akan menyimpan empat nilai untuk setiap *vertex*: jumlah dari segmen (*sum*), *maximum prefix sum*, *maximum suffix sum*, dan jumlah dari *maximal subsegment* di dalamnya. Dengan kata lain, untuk setiap segmen pada *Segment Tree*, jawabannya telah dihitung sebelumnya (*precomputed*), begitu pula dengan jawaban untuk segmen-segmen yang menyentuh batasan kiri dan kanan dari segmen tersebut.

Bagaimana cara membangun *tree* dengan data seperti itu? Sekali lagi kita menghitungnya secara rekursif: pertama-tama kita menghitung keempat nilai tersebut untuk *left child* dan *right child*, lalu menggabungkannya untuk memperoleh empat nilai pada *current vertex*. Perhatikan bahwa jawaban untuk *current vertex* adalah salah satu dari:

* jawaban dari *left child*, yang berarti *subsegment* optimal sepenuhnya berada di dalam segmen milik *left child*
* jawaban dari *right child*, yang berarti *subsegment* optimal sepenuhnya berada di dalam segmen milik *right child*
* penjumlahan dari *maximum suffix sum* milik *left child* dan *maximum prefix sum* milik *right child*, yang berarti *subsegment* optimal berpotongan (*intersect*) dengan kedua *children*.

Oleh karena itu, jawaban untuk *current vertex* adalah nilai maksimum dari ketiga nilai ini. Menghitung *maximum prefix / suffix sum* bahkan lebih mudah. Berikut adalah implementasi dari fungsi $\text{combine}$, yang hanya menerima data dari *left child* dan *right child*, lalu mengembalikan data untuk *current vertex*.

```cpp
struct data {
    int sum, pref, suff, ans;
};

data combine(data l, data r) {
    data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}
```

Menggunakan fungsi $\text{combine}$, sangat mudah untuk membangun *Segment Tree*. Kita dapat mengimplementasikannya dengan cara yang persis sama seperti pada implementasi-implementasi sebelumnya. Untuk menginisialisasi *leaf vertices*, kita buat fungsi tambahan $\text{make\_data}$, yang akan mengembalikan sebuah objek $\text{data}$ yang menyimpan informasi dari satu nilai tunggal.

```cpp
data make_data(int val) {
    data res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(0, val);
    return res;
}

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_data(a[tl]);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = make_data(new_val);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}
```

Sekarang tinggal bagaimana cara menghitung jawaban untuk suatu *query*. Untuk menjawabnya, kita turun melintasi *tree* seperti sebelumnya, membagi *query* menjadi beberapa *subsegment* yang bersesuaian dengan segmen-segmen pada *Segment Tree*, lalu menggabungkan jawaban dari *subsegment* tersebut menjadi satu jawaban tunggal untuk *query*. Dari sini seharusnya sudah jelas bahwa proses kerjanya persis sama seperti pada *Segment Tree* sederhana, tetapi alih-alih menjumlahkan, mencari nilai minimum, atau mencari nilai maksimum dari nilainya, kita menggunakan fungsi $\text{combine}$.

```cpp
data query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return make_data(0);
    if (l == tl && r == tr) 
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(query(v*2, tl, tm, l, min(r, tm)), 
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
}
```

### Saving the entire subarrays in each vertex

Ini adalah subbagian terpisah yang berdiri sendiri dari yang lain, karena pada setiap *vertex* dari *Segment Tree* kita tidak menyimpan informasi tentang segmen yang bersesuaian dalam bentuk terkompresi (*sum*, *minimum*, *maximum*, ...), melainkan menyimpan seluruh elemen dari segmen tersebut. Dengan demikian, *root* dari *Segment Tree* akan menyimpan seluruh elemen *array*, *left child vertex* akan menyimpan paruh pertama dari *array*, *right vertex* menyimpan paruh kedua, dan seterusnya.

Pada penerapan paling sederhana dari teknik ini, kita menyimpan elemen-elemen tersebut dalam keadaan terurut (*sorted*). Pada versi yang lebih kompleks, elemen-elemen tersebut tidak disimpan di dalam *list*, melainkan struktur data yang lebih tingkat lanjut (*sets*, *maps*, ...). Namun semua metode ini memiliki faktor kesamaan, yaitu setiap *vertex* membutuhkan memori linier (yaitu sebanding dengan panjang dari segmen yang bersesuaian).

Pertanyaan alami pertama saat mempertimbangkan *Segment Tree* jenis ini adalah mengenai konsumsi memori. Secara intuitif ini terlihat seperti membutuhkan memori sebesar $O(n^2)$, tetapi ternyata keseluruhan *tree* hanya akan membutuhkan memori sebesar $O(n \log n)$. Mengapa bisa demikian? Cukup sederhana, karena setiap elemen dari *array* jatuh ke dalam $O(\log n)$ segmen (ingat bahwa tinggi dari *tree* adalah $O(\log n)$).

Jadi, terlepas dari pemborosan yang tampak pada *Segment Tree* semacam ini, struktur data ini hanya mengonsumsi sedikit lebih banyak memori daripada *Segment Tree* biasa.

Beberapa aplikasi khas dari struktur data ini dijelaskan di bawah ini. Perlu dicatat adanya kemiripan antara *Segment Tree* jenis ini dengan struktur data 2D (sebenarnya ini adalah struktur data 2D, tetapi dengan kapabilitas yang cukup terbatas).

#### Mencari Angka Terkecil yang Lebih Besar atau Sama dengan Angka Tertentu. Tanpa *Query* Modifikasi.

Kita ingin menjawab *query* dengan bentuk sebagai berikut: untuk tiga angka $(l, r, x)$ yang diberikan, kita harus menemukan angka minimal pada segmen $a[l \dots r]$ yang lebih besar dari atau sama dengan $x$.

Kita mengonstruksi sebuah *Segment Tree*. Pada setiap *vertex*, kita menyimpan *list* terurut dari semua angka yang muncul pada segmen yang bersesuaian, seperti yang dijelaskan di atas. Bagaimana cara membangun *Segment Tree* semacam ini seefektif mungkin? Seperti biasa kita mendekati masalah ini secara rekursif: misalkan *list* dari *left child* dan *right child* sudah dikonstruksi, dan kita ingin membangun *list* untuk *current vertex*. Dari sudut pandang ini, operasinya sekarang menjadi trivial dan dapat diselesaikan dalam waktu linier: Kita hanya perlu menggabungkan dua *list* yang terurut menjadi satu, yang dapat dilakukan dengan mengiterasi kedua *list* menggunakan *two pointers*. C++ STL sudah memiliki implementasi dari algoritma ini.

Karena struktur dari *Segment Tree* ini dan kemiripannya dengan algoritma *merge sort*, struktur data ini juga sering disebut sebagai "*Merge Sort Tree*".

```cpp
vector<int> t[4*MAXN];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = vector<int>(1, a[tl]);
    } else { 
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        merge(t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(),
              back_inserter(t[v]));
    }
}
```

Kita telah mengetahui bahwa *Segment Tree* yang dikonstruksi dengan cara ini akan membutuhkan memori sebesar $O(n \log n)$. Dan berkat implementasi ini, konstruksinya juga membutuhkan waktu sebesar $O(n \log n)$, karena bagaimanapun juga setiap *list* dikonstruksi dalam waktu linier terhadap ukurannya.

Sekarang pertimbangkan jawaban untuk *query*. Kita akan turun melintasi *tree*, seperti pada *Segment Tree* reguler, membagi segmen $a[l \dots r]$ menjadi beberapa *subsegment* (paling banyak menjadi $O(\log n)$ bagian). Jelas bahwa jawaban dari keseluruhan *query* adalah nilai minimum dari masing-masing *subquery*. Jadi sekarang kita hanya perlu memahami cara merespons *query* pada salah satu *subsegment* yang bersesuaian dengan suatu *vertex* pada *tree*.

Kita berada di suatu *vertex* dari *Segment Tree* dan ingin menghitung jawaban untuk *query*, yaitu menemukan angka minimum yang lebih besar dari atau sama dengan angka $x$ yang diberikan. Karena *vertex* tersebut memuat *list* elemen dalam keadaan terurut, kita dapat dengan mudah melakukan *binary search* pada *list* ini dan mengembalikan angka pertama yang lebih besar dari atau sama dengan $x$.

Dengan demikian, jawaban untuk *query* pada satu segmen *tree* membutuhkan waktu $O(\log n)$, dan keseluruhan *query* diproses dalam waktu $O(\log^2 n)$.

```cpp
int query(int v, int tl, int tr, int l, int r, int x) {
    if (l > r)
        return INF;
    if (l == tl && r == tr) {
        vector<int>::iterator pos = lower_bound(t[v].begin(), t[v].end(), x);
        if (pos != t[v].end())
            return *pos;
        return INF;
    }
    int tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, min(r, tm), x), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r, x));
}
```

Konstanta $\text{INF}$ bernilai sama dengan suatu angka besar yang lebih besar dari semua angka dalam *array*. Penggunaannya menandakan bahwa tidak ada angka yang lebih besar dari atau sama dengan $x$ pada segmen tersebut. Ini memiliki arti "tidak ada jawaban pada interval yang diberikan".

#### Mencari Angka Terkecil yang Lebih Besar atau Sama dengan Angka Tertentu. Dengan *Query* Modifikasi.

Tugas ini mirip dengan tugas sebelumnya. Pendekatan terakhir memiliki kekurangan, yaitu tidak memungkinkan untuk memodifikasi *array* di antara proses menjawab *query*. Sekarang kita ingin melakukan tepat hal tersebut: sebuah *query* modifikasi akan melakukan *assignment* $a[i] = y$.

Solusinya mirip dengan solusi masalah sebelumnya, tetapi alih-alih menggunakan *list* pada setiap *vertex* dari *Segment Tree*, kita akan menyimpan *balanced list* yang memungkinkan Anda untuk mencari angka, menghapus angka, dan memasukkan angka baru secara cepat. Karena *array* dapat memuat angka yang berulang, pilihan yang optimal adalah struktur data $\text{multiset}$.

Konstruksi dari *Segment Tree* semacam ini dilakukan dengan cara yang hampir sama persis seperti pada masalah sebelumnya, hanya saja sekarang kita perlu menggabungkan $\text{multiset}$ dan bukan *list* yang terurut. Hal ini menghasilkan waktu konstruksi sebesar $O(n \log^2 n)$ (secara umum penggabungan dua *red-black tree* dapat dilakukan dalam waktu linier, tetapi C++ STL tidak menggaransi kompleksitas waktu ini).

Fungsi $\text{query}$ juga hampir ekuivalen, hanya saja sekarang fungsi $\text{lower\_bound}$ milik $\text{multiset}$ yang harus dipanggil. 

> $\text{std::lower\_bound}$ hanya bekerja dalam waktu $O(\log n)$ jika digunakan dengan *random-access iterators*.

Terakhir adalah permintaan modifikasi. Untuk memprosesnya, kita harus turun melintasi *tree*, dan memodifikasi semua $\text{multiset}$ dari segmen bersesuaian yang memuat elemen terdampak. Kita cukup menghapus nilai lama dari elemen ini (tetapi hanya satu kemunculan), lalu memasukkan nilai yang baru.

```cpp
void update(int v, int tl, int tr, int pos, int new_val) {
    t[v].erase(t[v].find(a[pos]));
    t[v].insert(new_val);
    if (tl != tr) {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
    } else {
        a[pos] = new_val;
    }
}
```

Pemrosesan dari *query* modifikasi ini juga membutuhkan waktu sebesar $O(n \log^2 n)$.

#### Mencari Angka Terkecil yang Lebih Besar atau Sama dengan Angka Tertentu. Akselerasi dengan "Fractional Cascading".

Kita memiliki deskripsi masalah yang sama: kita ingin menemukan angka minimal yang lebih besar dari atau sama dengan $x$ pada suatu segmen, tetapi kali ini dalam waktu $O(\log n)$. Kita akan meningkatkan kompleksitas waktu menggunakan teknik "*fractional cascading*".

*Fractional cascading* adalah teknik sederhana yang memungkinkan Anda meningkatkan *running time* dari beberapa *binary search* yang dilakukan secara bersamaan. Pendekatan kita sebelumnya untuk *search query* adalah membagi tugas menjadi beberapa sub-tugas, yang masing-masing diselesaikan dengan *binary search*. *Fractional cascading* memungkinkan Anda mengganti semua *binary search* tersebut hanya dengan satu *binary search*.

Contoh paling sederhana dan paling jelas dari *fractional cascading* adalah masalah berikut: terdapat $k$ buah *list* angka yang terurut, dan kita harus menemukan angka pertama yang lebih besar dari atau sama dengan angka yang diberikan pada setiap *list*.

Alih-alih melakukan *binary search* untuk setiap *list*, kita dapat menggabungkan semua *list* menjadi satu *list* terurut yang besar. Secara tambahan, untuk setiap elemen $y$, kita menyimpan *list* hasil pencarian untuk $y$ di masing-masing dari $k$ *list* tersebut. Oleh karena itu, jika kita ingin menemukan angka terkecil yang lebih besar dari atau sama dengan $x$, kita hanya perlu melakukan satu kali *binary search*, dan dari *list* indeks tersebut kita dapat menentukan angka terkecil di setiap *list*. Namun, pendekatan ini membutuhkan memori sebesar $O(n \cdot k)$ ($n$ adalah panjang dari *list* gabungan), yang bisa menjadi sangat tidak efisien.

*Fractional cascading* mengurangi kompleksitas memori ini menjadi memori sebesar $O(n)$, dengan cara membuat $k$ *list* baru dari $k$ *list input*, di mana setiap *list* baru memuat *list* yang bersesuaian dan secara tambahan juga setiap elemen kedua dari *list* baru berikutnya. Menggunakan struktur ini, kita hanya perlu menyimpan dua indeks: indeks elemen pada *list* asli, dan indeks elemen pada *list* baru berikutnya. Jadi pendekatan ini hanya menggunakan memori sebesar $O(n)$, dan masih dapat menjawab *query* menggunakan satu *binary search*.

Namun untuk aplikasi kita, kita tidak memerlukan kekuatan penuh dari *fractional cascading*. Pada *Segment Tree* kita, sebuah *vertex* akan memuat *list* terurut dari semua elemen yang muncul baik di *left subtree* maupun *right subtree* (seperti pada *Merge Sort Tree*). Selain *list* terurut ini, kita menyimpan dua posisi untuk setiap elemen. Untuk sebuah elemen $y$, kita menyimpan indeks terkecil $i$, sedemikian rupa sehingga elemen ke-$i$ pada *list* terurut dari *left child* bernilai lebih besar dari atau sama dengan $y$. Dan kita menyimpan indeks terkecil $j$, sedemikian rupa sehingga elemen ke-$j$ pada *list* terurut dari *right child* bernilai lebih besar dari atau sama dengan $y$. Nilai-nilai ini dapat dihitung secara paralel dengan langkah penggabungan (*merging step*) saat kita membangun *tree*.

Bagaimana hal ini mempercepat *query*?

Ingat kembali, pada solusi normal kita melakukan *binary search* pada setiap *node*. Namun dengan modifikasi ini, kita dapat menghindari semuanya kecuali satu *binary search*.

Untuk menjawab suatu *query*, kita cukup melakukan *binary search* pada *root node*. Ini memberikan kita elemen terkecil $y \ge x$ pada keseluruhan *array*, tetapi ini juga memberikan kita dua posisi: indeks dari elemen terkecil yang lebih besar dari atau sama dengan $x$ pada *left subtree*, dan indeks dari elemen terkecil $y$ pada *right subtree*. Perhatikan bahwa $\ge y$ adalah sama dengan $\ge x$, karena *array* kita tidak memuat elemen apa pun di antara $x$ dan $y$. Pada solusi *Merge Sort Tree* normal, kita akan menghitung indeks-indeks ini melalui *binary search*, tetapi dengan bantuan nilai-nilai yang telah dihitung sebelumnya (*precomputed values*), kita cukup melihatnya (*look up*) dalam waktu $O(1)$. Dan kita dapat mengulangi hal tersebut sampai kita mengunjungi semua *node* yang mencakup interval *query* kita.

Rangkumannya, seperti biasa kita menyentuh $O(\log n)$ *nodes* selama proses *query*. Pada *root node* kita melakukan *binary search*, dan pada semua *node* lainnya kita hanya melakukan operasi dengan waktu konstan ($O(1)$). Ini berarti kompleksitas untuk menjawab suatu *query* adalah $O(\log n)$.

Namun perhatikan bahwa cara ini menggunakan memori tiga kali lebih banyak daripada *Merge Sort Tree* normal, yang sebenarnya sudah menggunakan banyak memori ($O(n \log n)$).

Sangat mudah untuk menerapkan teknik ini pada masalah yang tidak memerlukan *query* modifikasi apa pun. Kedua posisi tersebut hanyalah *integer* dan dapat dengan mudah dihitung dengan melakukan pencacahan (*counting*) saat menggabungkan dua urutan yang terurut.

Masih dimungkinkan untuk mengizinkan *query* modifikasi, tetapi hal itu akan sangat rumit pada keseluruhan kode. Alih-alih *integer*, Anda perlu menyimpan *array* terurut sebagai `multiset`, dan alih-alih indeks, Anda perlu menyimpan *iterator*. Serta Anda harus bekerja sangat hati-hati agar dapat menaikkan (*increment*) atau menurunkan (*decrement*) *iterator* yang tepat selama *query* modifikasi.

#### Variasi Lain yang Dimungkinkan

Teknik ini membuka kelas aplikasi baru yang sangat luas. Alih-alih menyimpan `vector` atau `multiset` pada setiap *vertex*, struktur data lain dapat digunakan: *Segment Tree* lain (yang dibahas secara singkat pada bagian Generalisasi ke Dimensi yang Lebih Tinggi), *Fenwick Tree*, *Cartesian Tree*, dan lain-lain.

### Range updates (Lazy Propagation)

Semua masalah pada bagian-bagian sebelumnya membahas *query* modifikasi yang hanya memengaruhi satu elemen tunggal dari *array*. Namun, *Segment Tree* memungkinkan kita menerapkan *query* modifikasi pada seluruh segmen dari elemen-elemen yang berdampingan (*contiguous elements*), dan menjalankan *query* tersebut dalam waktu yang sama, yaitu $O(\log n)$.

#### Penjumlahan pada Segmen

Kita mulai dengan mempertimbangkan masalah dalam bentuk yang paling sederhana: *query* modifikasi harus menambahkan suatu angka $x$ ke semua angka pada segmen $a[l \dots r]$. *Query* kedua, yang harus kita jawab, hanya menanyakan nilai dari $a[i]$.

Untuk membuat *query* penjumlahan menjadi efisien, kita menyimpan informasi pada setiap *vertex* di dalam *Segment Tree* mengenai berapa nilai yang harus kita tambahkan ke semua angka pada segmen yang bersesuaian. Sebagai contoh, jika datang *query* "tambahkan 3 ke seluruh *array* $a[0 \dots n-1]$", maka kita menempatkan angka 3 pada *root* dari *tree*. Secara umum, kita harus menempatkan angka ini pada beberapa segmen, yang membentuk partisi dari segmen *query*. Dengan demikian, kita tidak perlu mengubah seluruh $O(n)$ nilai, melainkan hanya sebanyak $O(\log n)$ nilai.

Jika sekarang datang *query* yang menanyakan nilai saat ini dari entri *array* tertentu, kita cukup turun melintasi *tree* dan menjumlahkan seluruh nilai yang ditemukan di sepanjang jalur tersebut.

```cpp
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(v*2, tl, tm, pos);
    else
        return t[v] + get(v*2+1, tm+1, tr, pos);
}
```

#### Pengoperasian Nilai (*Assignment*) pada Segmen

Misalkan sekarang *query* modifikasi meminta untuk menetapkan (*assign*) setiap elemen pada segmen tertentu $a[l \dots r]$ dengan suatu nilai $p$. Sebagai *query* kedua, kita akan kembali mempertimbangkan pembacaan nilai dari *array* $a[i]$.

Untuk melakukan *query* modifikasi ini pada seluruh segmen, Anda harus menyimpan informasi pada setiap *vertex* dari *Segment Tree* mengenai apakah segmen yang bersesuaian sepenuhnya tertutup dengan nilai yang sama atau tidak. Hal ini memungkinkan kita melakukan *update* secara "lambat" (*lazy update*): alih-alih mengubah semua segmen di dalam *tree* yang mencakup segmen *query*, kita hanya mengubah beberapa, dan membiarkan yang lainnya tidak berubah. *Vertex* yang ditandai menandakan bahwa setiap elemen pada segmen yang bersesuaian ditetapkan dengan nilai tersebut, dan sebenarnya seluruh *subtree* di bawahnya juga hanya boleh memuat nilai ini. Dalam arti tertentu, kita bersikap malas (*lazy*) dan menunda penulisan nilai baru ke semua *vertices* tersebut. Kita dapat melakukan tugas yang rumit ini nanti, jika memang diperlukan.

Jadi setelah *query* modifikasi dijalankan, beberapa bagian dari *tree* menjadi tidak relevan — beberapa modifikasi tetap belum dipenuhi di dalamnya.

Sebagai contoh, jika *query* modifikasi "tetapkan suatu angka ke seluruh *array* $a[0 \dots n-1]$" dijalankan, pada *Segment Tree* hanya terjadi satu perubahan tunggal — angka tersebut ditempatkan pada *root* dari *tree* dan *vertex* ini diberi tanda. Segmen-segmen selebihnya tetap tidak berubah, meskipun pada kenyataannya angka tersebut seharusnya ditempatkan di seluruh *tree*.

Misalkan sekarang *query* modifikasi kedua menyatakan bahwa separuh pertama dari *array* $a[0 \dots n/2]$ harus ditetapkan dengan angka lain. Untuk memproses *query* ini, kita harus menetapkan setiap elemen pada seluruh *left child* dari *root vertex* dengan angka tersebut. Namun sebelum kita melakukan hal ini, kita harus membereskan *root vertex* terlebih dahulu. Kerumitan di sini adalah bahwa separuh kanan dari *array* seharusnya masih ditetapkan dengan nilai dari *query* pertama, dan pada saat ini tidak ada informasi yang tersimpan untuk separuh kanan tersebut.

Cara untuk menyelesaikan hal ini adalah dengan Mendorong (*push*) informasi dari *root* ke *children*-nya, yaitu jika *root* dari *tree* telah ditetapkan dengan suatu angka, maka kita menetapkan *left child* dan *right child* dengan angka ini dan menghapus tanda (*mark*) dari *root*. Setelah itu, kita dapat menetapkan *left child* dengan nilai yang baru, tanpa kehilangan informasi penting apa pun.

Rangkumannya kita mendapatkan: untuk *query* apa pun (baik *query* modifikasi maupun *query* pembacaan) selama proses turun melintasi *tree*, kita harus selalu mendorong (*push*) informasi dari *current vertex* ke kedua *children*-nya. Kita dapat memahami hal ini dalam artian bahwa ketika kita turun melintasi *tree*, kita menerapkan modifikasi yang tertunda (*delayed modifications*), tetapi hanya sebanyak yang diperlukan saja (sehingga tidak merusak kompleksitas $O(\log n)$).

Untuk implementasinya, kita perlu membuat fungsi $\text{push}$, yang akan menerima *current vertex*, lalu fungsi tersebut akan mendorong informasi dari *vertex*-nya ke kedua *children*-nya. Kita akan memanggil fungsi ini di awal fungsi-fungsi *query* (tetapi kita tidak akan memanggilnya dari *leaf vertices*, karena tidak ada kebutuhan untuk mendorong informasi lebih jauh lagi dari *leaves*).

```cpp
void push(int v) {
    if (marked[v]) {
        t[v*2] = t[v*2+1] = t[v];
        marked[v*2] = marked[v*2+1] = true;
        marked[v] = false;
    }
}

void update(int v, int tl, int tr, int l, int r, int new_val) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] = new_val;
        marked[v] = true;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), new_val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return t[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    if (pos <= tm) 
        return get(v*2, tl, tm, pos);
    else
        return get(v*2+1, tm+1, tr, pos);
}
```

Catatan: fungsi $\text{get}$ juga dapat diimplementasikan dengan cara lain: tanpa melakukan *delayed updates* (*push*), melainkan langsung mengembalikan nilai $t[v]$ jika $marked[v]$ bernilai *true*.

#### Penjumlahan pada Segmen, *Query* Nilai Maksimum

Sekarang *query* modifikasi bertujuan untuk menambahkan suatu angka ke semua elemen dalam suatu rentang, dan *query* pembacaan bertujuan untuk menemukan nilai maksimum dalam suatu rentang.

Oleh karena itu, untuk setiap *vertex* pada *Segment Tree*, kita harus menyimpan nilai maksimum dari *subsegment* yang bersesuaian. Bagian yang menarik adalah bagaimana cara menghitung ulang nilai-nilai ini selama proses permintaan modifikasi.

Untuk tujuan ini, kita menyimpan nilai tambahan untuk setiap *vertex*. Dalam nilai ini, kita menyimpan nilai penjumlahan (*addends*) yang belum kita propagasikan ke *child vertices*. Sebelum melintasi turun ke suatu *child vertex*, kita memanggil fungsi $\text{push}$ dan mempropagasi nilai tersebut ke kedua *children*. Kita harus melakukan hal ini baik dalam fungsi $\text{update}$ maupun fungsi $\text{query}$.

```cpp
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2], t[v*2 + 1]);
    }
}

void push(int v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -INF;
    if (l == tl && tr == r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}
```

### Generalization to higher dimensions

*Segment Tree* dapat digeneralisasikan secara sangat alami ke dimensi yang lebih tinggi. Jika pada kasus satu dimensi kita membagi indeks-indeks *array* menjadi beberapa segmen, maka pada kasus dua dimensi kita membuat *Segment Tree* biasa terhadap indeks pertama, dan untuk setiap segmen kita membangun *Segment Tree* biasa terhadap indeks kedua.

#### 2D Segment Tree Sederhana

Diberikan sebuah matriks $a[0 \dots n-1, 0 \dots m-1]$, dan kita harus menemukan jumlah (atau minimum/maksimum) pada suatu submatriks $a[x_1 \dots x_2, y_1 \dots y_2]$, serta melakukan modifikasi pada elemen matriks individual (yaitu *query* dengan bentuk $a[x][y] = p$).

Oleh karena itu, kita membangun *2D Segment Tree*: pertama-tama *Segment Tree* menggunakan koordinat pertama ($x$), kemudian koordinat kedua ($y$).

Untuk membuat proses konstruksi lebih mudah dipahami, Anda dapat melupakan sejenak bahwa matriks tersebut berdimensi dua, dan hanya menyisakan koordinat pertama. Kita akan mengonstruksi *Segment Tree* satu dimensi biasa hanya dengan menggunakan koordinat pertama. Namun, alih-alih menyimpan sebuah angka di dalam suatu segmen, kita menyimpan seluruh *Segment Tree*: yaitu pada saat ini kita mengingat bahwa kita juga memiliki koordinat kedua; tetapi karena pada saat ini koordinat pertama telah ditetapkan ke suatu interval $[l \dots r]$, kita sebenarnya bekerja dengan jalur/strip $a[l \dots r, 0 \dots m-1]$ dan untuk jalur tersebut kita membangun sebuah *Segment Tree*.

Berikut adalah implementasi konstruksi dari *2D Segment Tree*. Ini sebenarnya merepresentasikan dua blok terpisah: pembuatan *Segment Tree* di sepanjang koordinat $x$ ($\text{build}_x$), dan koordinat $y$ ($\text{build}_y$). Untuk *leaf nodes* pada $\text{build}_y$, kita harus memisahkan dua kasus: ketika segmen saat ini dari koordinat pertama $[tlx \dots trx]$ memiliki panjang 1, dan ketika memiliki panjang lebih besar dari satu. Pada kasus pertama, kita langsung mengambil nilai yang bersesuaian dari matriks, dan pada kasus kedua kita dapat menggabungkan nilai-nilai dari dua *Segment Tree* milik *left son* dan *right son* pada koordinat $x$.

```cpp
void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = a[lx][ly];
        else
            t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy*2, ly, my);
        build_y(vx, lx, rx, vy*2+1, my+1, ry);
        t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
    }
}

void build_x(int vx, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(vx*2, lx, mx);
        build_x(vx*2+1, mx+1, rx);
    }
    build_y(vx, lx, rx, 1, 0, m-1);
}
```

*Segment Tree* semacam ini tetap menggunakan jumlah memori yang linier, tetapi dengan konstanta yang lebih besar: $16 n m$. Jelas bahwa prosedur $\text{build}_x$ yang dijelaskan juga bekerja dalam waktu linier.

Sekarang kita beralih ke pemrosesan *query*. Kita akan menjawab *query* dua dimensi menggunakan prinsip yang sama: pertama-tama bagi *query* pada koordinat pertama, lalu untuk setiap *vertex* yang dicapai, kita memanggil *Segment Tree* yang bersesuaian pada koordinat kedua.

```cpp
int sum_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry) 
        return 0;
    if (ly == tly && try_ == ry)
        return t[vx][vy];
    int tmy = (tly + try_) / 2;
    return sum_y(vx, vy*2, tly, tmy, ly, min(ry, tmy))
         + sum_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry);
}

int sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return 0;
    if (lx == tlx && trx == rx)
        return sum_y(vx, 1, 0, m-1, ly, ry);
    int tmx = (tlx + trx) / 2;
    return sum_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry)
         + sum_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry);
}
```

Fungsi ini bekerja dalam waktu $O(\log n \log m)$, karena pertama-tama ia turun melintasi *tree* pada koordinat pertama, dan untuk setiap *vertex* yang dilalui pada *tree* tersebut, ia melakukan *query* pada *Segment Tree* yang bersesuaian di sepanjang koordinat kedua.

Terakhir, kita mempertimbangkan *query* modifikasi. Kita ingin mempelajari cara memodifikasi *Segment Tree* sesuai dengan perubahan nilai dari suatu elemen $a[x][y] = p$. Jelas bahwa perubahan hanya akan terjadi pada *vertices* dari *Segment Tree* pertama yang mencakup koordinat $x$ (dan akan ada sebanyak $O(\log n)$ *vertices* seperti itu), dan untuk *Segment Trees* yang bersesuaian dengannya, perubahan hanya akan terjadi pada *vertices* yang mencakup koordinat $y$ (dan akan ada sebanyak $O(\log m)$ *vertices* seperti itu). Oleh karena itu, implementasinya tidak akan jauh berbeda dari kasus satu dimensi, hanya saja sekarang kita pertama-tama turun pada koordinat pertama, lalu kemudian pada koordinat kedua.

```cpp
void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = new_val;
        else
            t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
    } else {
        int my = (ly + ry) / 2;
        if (y <= my)
            update_y(vx, lx, rx, vy*2, ly, my, x, y, new_val);
        else
            update_y(vx, lx, rx, vy*2+1, my+1, ry, x, y, new_val);
        t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
    }
}

void update_x(int vx, int lx, int rx, int x, int y, int new_val) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        if (x <= mx)
            update_x(vx*2, lx, mx, x, y, new_val);
        else
            update_x(vx*2+1, mx+1, rx, x, y, new_val);
    }
    update_y(vx, lx, rx, 1, 0, m-1, x, y, new_val);
}
```

#### Kompresi *2D Segment Tree*

Misalkan masalahnya adalah sebagai berikut: terdapat $n$ titik pada bidang datar yang diberikan oleh koordinatnya $(x_i, y_i)$, dan terdapat *query* berbentuk "hitung jumlah titik yang berada di dalam persegi panjang $((x_1, y_1), (x_2, y_2))$". Jelas bahwa untuk masalah seperti ini, menjadi sangat boros jika kita mengonstruksi *2D Segment Tree* dengan $O(n^2)$ elemen. Sebagian besar memori ini akan terbuang sia-sia, karena setiap titik tunggal hanya dapat masuk ke dalam $O(\log n)$ segmen *tree* di sepanjang koordinat pertama, dan oleh karena itu total ukuran "berguna" dari semua segmen *tree* pada koordinat kedua adalah $O(n \log n)$.

Jadi kita melakukan hal sebagai berikut: pada setiap *vertex* dari *Segment Tree* terhadap koordinat pertama, kita menyimpan *Segment Tree* yang dikonstruksi hanya berdasarkan koordinat kedua yang muncul pada segmen koordinat pertama saat ini. Dengan kata lain, saat membangun *Segment Tree* di dalam suatu *vertex* dengan indeks $vx$ dan batas $tlx$ serta $trx$, kita hanya mempertimbangkan titik-titik yang jatuh ke dalam interval ini $x \in [tlx, trx]$, lalu membangun *Segment Tree* hanya menggunakan titik-titik tersebut.

Dengan demikian, kita akan mencapai kondisi di mana setiap *Segment Tree* pada koordinat kedua akan memakan memori sebesar yang benar-benar dibutuhkannya saja. Hasilnya, total penggunaan memori akan berkurang menjadi $O(n \log n)$. Kita masih dapat menjawab *query* dalam waktu $O(\log^2 n)$, kita hanya perlu melakukan *binary search* pada koordinat kedua, tetapi hal ini tidak akan memperburuk kompleksitas.

Namun, *query* modifikasi tidak memungkinkan untuk dilakukan dengan struktur ini: faktanya jika sebuah titik baru muncul, kita harus menambahkan elemen baru di tengah-tengah suatu *Segment Tree* di sepanjang koordinat kedua, yang tidak dapat dilakukan secara efisien.

Sebagai penutup, kita catat bahwa *2D Segment Tree* yang dikompresi dengan cara yang dijelaskan ini menjadi praktis ekuivalen dengan modifikasi *1D Segment Tree* (lihat bagian Menyimpan Seluruh *Subarray* pada Setiap *Vertex*). Secara khusus, *2D Segment Tree* hanyalah kasus khusus dari menyimpan *subarray* pada setiap *vertex* dari *tree*. Dari sini disimpulkan bahwa, jika Anda harus meninggalkan *2D Segment Tree* karena ketidakmungkinan dalam mengeksekusi *query* modifikasi, masuk akal untuk mencoba mengganti *Segment Tree* bersarang (*nested Segment Tree*) tersebut dengan struktur data yang lebih kuat, misalnya *Cartesian Tree* (*Treap*).

### Preserving the history of its values (Persistent Segment Tree)

Struktur data persisten (*persistent data structure*) adalah struktur data yang mengingat keadaan (*state*) sebelumnya untuk setiap modifikasi. Hal ini memungkinkan kita untuk mengakses versi mana pun dari struktur data tersebut yang menarik bagi kita dan mengeksekusi *query* pada versi tersebut.

*Segment Tree* adalah struktur data yang dapat diubah menjadi struktur data persisten secara efisien (baik dalam konsumsi waktu maupun memori). Kita ingin menghindari penyalinan seluruh *tree* sebelum setiap modifikasi, dan kita tidak ingin kehilangan perilaku waktu $O(\log n)$ untuk menjawab *range queries*.

Faktanya, setiap permintaan perubahan pada *Segment Tree* hanya menyebabkan perubahan data pada $O(\log n)$ *vertices* di sepanjang jalur yang dimulai dari *root*. Jadi jika kita menyimpan *Segment Tree* menggunakan *pointers* (yaitu sebuah *vertex* menyimpan *pointer* ke *left child* dan *right child vertex*), maka ketika melakukan *query* modifikasi, kita hanya perlu membuat *vertices* baru alih-alih mengubah *vertices* yang sudah ada. *Vertices* yang tidak terdampak oleh *query* modifikasi masih dapat digunakan dengan mengarahkan *pointer* ke *vertices* yang lama. Dengan demikian, untuk satu *query* modifikasi, sebanyak $O(\log n)$ *vertices* baru akan dibuat, termasuk *root vertex* baru dari *Segment Tree*, dan seluruh versi *tree* sebelumnya yang berakar pada *root vertex* lama akan tetap tidak berubah.

Mari kita berikan contoh implementasi untuk *Segment Tree* paling sederhana: ketika hanya terdapat *query* penjumlahan (*sum*), dan *query* modifikasi elemen tunggal (*point update*).

```cpp
struct Vertex {
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

Vertex* build(int a[], int tl, int tr) {
    if (tl == tr)
        return new Vertex(a[tl]);
    int tm = (tl + tr) / 2;
    return new Vertex(build(a, tl, tm), build(a, tm+1, tr));
}

int get_sum(Vertex* v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return v->sum;
    int tm = (tl + tr) / 2;
    return get_sum(v->l, tl, tm, l, min(r, tm))
         + get_sum(v->r, tm+1, tr, max(l, tm+1), r);
}

Vertex* update(Vertex* v, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
        return new Vertex(new_val);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos, new_val));
}
```

Untuk setiap modifikasi pada *Segment Tree*, kita akan menerima *root vertex* yang baru. Untuk berpindah secara cepat di antara dua versi *Segment Tree* yang berbeda, kita perlu menyimpan *roots* ini di dalam sebuah *array*. Untuk menggunakan versi *Segment Tree* tertentu, kita cukup memanggil *query* menggunakan *root vertex* yang sesuai.

Dengan pendekatan yang dijelaskan di atas, hampir semua *Segment Tree* dapat diubah menjadi struktur data persisten.

#### Mencari Elemen Terkecil ke-$k$ dalam Suatu Rentang (*Range $k$-th Smallest Number*)

Kali ini kita harus menjawab *query* dengan bentuk "Apakah elemen terkecil ke-$k$ pada rentang $a[l \dots r]$?". *Query* ini dapat dijawab menggunakan *binary search* dan *Merge Sort Tree*, tetapi kompleksitas waktu untuk satu *query* adalah $O(\log^3 n)$. Kita akan menyelesaikan tugas yang sama menggunakan *Persistent Segment Tree* dalam waktu $O(\log n)$.

Pertama, kita akan mendiskusikan solusi untuk masalah yang lebih sederhana: Kita hanya mempertimbangkan *array* dengan elemen-elemen yang dibatasi oleh $0 \le a[i] < n$. Dan kita hanya ingin menemukan elemen terkecil ke-$k$ pada suatu *prefix* tertentu dari *array* $a$. Akan sangat mudah untuk memperluas ide yang dikembangkan ini nantinya untuk *array* tanpa batasan dan *range queries* tanpa batasan. Perhatikan bahwa kita akan menggunakan indeks berbasis 1 (*1-based indexing*) untuk $a$.

Kita akan menggunakan *Segment Tree* yang menghitung semua angka yang muncul, yaitu pada *Segment Tree* kita akan menyimpan histogram dari *array*. Jadi *leaf vertices* akan menyimpan seberapa sering nilai $0, 1, \dots, n-1$ muncul di dalam *array*, dan *vertices* lainnya menyimpan berapa banyak angka dalam suatu rentang yang ada di dalam *array*. Dengan kata lain, kita membuat *Segment Tree* biasa dengan *sum queries* di atas histogram *array*. Namun alih-alih membuat seluruh $n$ *Segment Trees* untuk setiap kemungkinan *prefix*, kita akan membuat satu *Persistent Segment Tree* yang memuat informasi yang sama. Kita akan mulai dengan *Segment Tree* kosong (semua hitungan bernilai $0$) yang ditunjuk oleh $root_0$, lalu menambahkan elemen $a[1], a[2], \dots, a[n]$ satu demi satu. Untuk setiap modifikasi kita akan menerima *root vertex* baru, mari kita sebut $root_i$ sebagai *root* dari *Segment Tree* setelah memasukkan $i$ elemen pertama dari *array* $a$. *Segment Tree* yang berakar pada $root_i$ akan memuat histogram dari *prefix* $a[1 \dots i]$. Menggunakan *Segment Tree* ini, kita dapat menemukan posisi elemen ke-$k$ dalam waktu $O(\log n)$ menggunakan teknik yang sama dengan mencari elemen ke-$k$.

Sekarang beralih ke versi masalah tanpa batasan.

Pertama, untuk batasan pada *query*: Alih-alih hanya melakukan *query* ini pada *prefix* dari $a$, kita ingin menggunakan segmen sembarang $a[l \dots r]$. Di sini kita membutuhkan *Segment Tree* yang merepresentasikan histogram dari elemen-elemen pada rentang $a[l \dots r]$. Mudah untuk melihat bahwa *Segment Tree* semacam itu hanyalah selisih antara *Segment Tree* yang berakar pada $root_r$ dan *Segment Tree* yang berakar pada $root_{l-1}$, yaitu setiap *vertex* pada *Segment Tree* $[l \dots r]$ dapat dihitung dari *vertex* pada *tree* $root_r$ dikurangi *vertex* pada *tree* $root_{l-1}$.

Pada implementasi fungsi $\text{find\_kth}$, hal ini dapat ditangani dengan melewatkan dua *vertex pointer* dan menghitung hitungan/jumlah (*count/sum*) dari segmen saat ini sebagai selisih dari dua hitungan/jumlah *vertices* tersebut.

Berikut adalah fungsi $\text{build}$, $\text{update}$, dan $\text{find\_kth}$ yang telah dimodifikasi:

```cpp
Vertex* build(int tl, int tr) {
    if (tl == tr)
        return new Vertex(0);
    int tm = (tl + tr) / 2;
    return new Vertex(build(tl, tm), build(tm+1, tr));
}

Vertex* update(Vertex* v, int tl, int tr, int pos) {
    if (tl == tr)
        return new Vertex(v->sum+1);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos));
}

int find_kth(Vertex* vl, Vertex *vr, int tl, int tr, int k) {
    if (tl == tr)
        return tl;
    int tm = (tl + tr) / 2, left_count = vr->l->sum - vl->l->sum;
    if (left_count >= k)
        return find_kth(vl->l, vr->l, tl, tm, k);
    return find_kth(vl->r, vr->r, tm+1, tr, k-left_count);
}
```

Seperti yang sudah dituliskan di atas, kita perlu menyimpan *root* dari *Segment Tree* awal, dan juga semua *root* setelah setiap *update*. Berikut adalah kode untuk membangun *Persistent Segment Tree* di atas `vector a` dengan elemen-elemen dalam rentang `[0, MAX_VALUE]`.

```cpp
int tl = 0, tr = MAX_VALUE + 1;
std::vector<Vertex*> roots;
roots.push_back(build(tl, tr));
for (int i = 0; i < a.size(); i++) {
    roots.push_back(update(roots.back(), tl, tr, a[i]));
}

// find the 5th smallest number from the subarray [a[2], a[3], ..., a[19]]
int result = find_kth(roots[2], roots[20], tl, tr, 5);
```

Sekarang beralih ke batasan pada elemen-elemen *array*: Kita sebenarnya dapat mengubah *array* apa pun menjadi *array* semacam itu menggunakan *coordinate compression* (kompresi indeks). Elemen terkecil di dalam *array* akan diberi nilai 0, elemen terkecil kedua diberi nilai 1, dan seterusnya. Sangat mudah untuk membuat tabel acuan (*lookup table*, contohnya menggunakan `map` atau `vector` terurut dengan `lower_bound`), yang mengubah suatu nilai menjadi indeksnya dan sebaliknya dalam waktu $O(\log n)$.

## Dynamic Segment Tree

(Disebut demikian karena bentuknya yang dinamis dan *node*-nya biasanya dialokasikan secara dinamis. Dikenal juga sebagai *Implicit Segment Tree* atau *Sparse Segment Tree*.)

Sebelumnya, kita mempertimbangkan kasus-kasus di mana kita memiliki kemampuan untuk membangun *Segment Tree* asli sejak awal. Namun apa yang harus dilakukan jika ukuran *array* awal diisi dengan suatu elemen default, tetapi ukurannya tidak memungkinkan bagi Anda untuk membangun seluruh *tree* secara lengkap di awal?

Kita dapat menyelesaikan masalah ini dengan membuat *Segment Tree* secara *lazy* (inkremental). Pada awalnya, kita hanya akan membuat *root*, dan kita baru akan membuat *vertices* lainnya hanya saat kita membutuhkannya. Dalam kasus ini, kita akan menggunakan implementasi berbasis *pointer* (sebelum menuju ke *child vertices*, periksa apakah *children* tersebut sudah dibuat, dan jika belum, buat *children* tersebut). Setiap *query* tetap hanya memiliki kompleksitas $O(\log n)$, yang cukup kecil untuk sebagian besar kasus penggunaan (misalnya $\log_2 10^9 \approx 30$).

Dalam implementasi ini kita memiliki dua jenis *query*: menambahkan suatu nilai pada posisi tertentu (awalnya semua nilai adalah $0$), dan menghitung jumlah dari seluruh nilai dalam suatu rentang (*range sum*). Vertex(0, n) akan menjadi *root vertex* dari *implicit tree* tersebut.

```cpp
struct Vertex {
    int left, right;
    int sum = 0;
    Vertex *left_child = nullptr, *right_child = nullptr;

    Vertex(int lb, int rb) {
        left = lb;
        right = rb;
    }

    void extend() {
        if (!left_child && left + 1 < right) {
            int t = (left + right) / 2;
            left_child = new Vertex(left, t);
            right_child = new Vertex(t, right);
        }
    }

    void add(int k, int x) {
        extend();
        sum += x;
        if (left_child) {
            if (k < left_child->right)
                left_child->add(k, x);
            else
                right_child->add(k, x);
        }
    }

    int get_sum(int lq, int rq) {
        if (lq <= left && right <= rq)
            return sum;
        if (max(left, lq) >= min(right, rq))
            return 0;
        extend();
        return left_child->get_sum(lq, rq) + right_child->get_sum(lq, rq);
    }
};
```

Jelas sekali bahwa ide ini dapat diperluas dengan berbagai cara lain. Sebagai contoh, dengan menambahkan dukungan untuk *range updates* menggunakan *lazy propagation*.

## Practice Problems

- [SPOJ - KQUERY](http://www.spoj.com/problems/KQUERY/) [Persistent segment tree / Merge sort tree]
- [Codeforces - Xenia and Bit Operations](https://codeforces.com/problemset/problem/339/D)
- [UVA 11402 - Ahoy, Pirates!](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2397)
- [SPOJ - GSS3](http://www.spoj.com/problems/GSS3/)
- [Codeforces - Sereja And Brackets](https://codeforces.com/contest/380/problem/C)
- [Codeforces - Distinct Characters Queries](https://codeforces.com/problemset/problem/1234/D)
- [Codeforces - Knight Tournament](https://codeforces.com/contest/356/problem/A) [For beginners]
- [Codeforces - Ant colony](https://codeforces.com/contest/474/problem/F)
- [Codeforces - Drazil and Park](https://codeforces.com/contest/515/problem/E)
- [Codeforces - Circular RMQ](https://codeforces.com/problemset/problem/52/C)
- [Codeforces - Lucky Array](https://codeforces.com/contest/121/problem/E)
- [Codeforces - The Child and Sequence](https://codeforces.com/contest/438/problem/D)
- [Codeforces - DZY Loves Fibonacci Numbers](https://codeforces.com/contest/446/problem/C) [Lazy propagation]
- [Codeforces - Alphabet Permutations](https://codeforces.com/problemset/problem/610/E)
- [Codeforces - Eyes Closed](https://codeforces.com/problemset/problem/895/E)
- [Codeforces - Kefa and Watch](https://codeforces.com/problemset/problem/580/E)
- [Codeforces - A Simple Task](https://codeforces.com/problemset/problem/558/E)
- [Codeforces - SUM and REPLACE](https://codeforces.com/problemset/problem/920/F)
- [Codeforces - XOR on Segment](https://codeforces.com/problemset/problem/242/E) [Lazy propagation]
- [Codeforces - Please, another Queries on Array?](https://codeforces.com/problemset/problem/1114/F) [Lazy propagation]
- [COCI - Deda](https://oj.uz/problem/view/COCI17_deda) [Last element smaller or equal to x / Binary search]
- [Codeforces - The Untended Antiquity](https://codeforces.com/problemset/problem/869/E) [2D]
- [CSES - Hotel Queries](https://cses.fi/problemset/task/1143)
- [CSES - Polynomial Queries](https://cses.fi/problemset/task/1736)
- [CSES - Range Updates and Sums](https://cses.fi/problemset/task/1735)