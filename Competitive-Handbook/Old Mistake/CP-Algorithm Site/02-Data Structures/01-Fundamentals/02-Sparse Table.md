---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Sparse Table
sumber:
  - cp-algorithms.com
date_learned: 2025-09-24T07:33:00
tags:
  - data-structure
---
Link Sumber: [Sparse Table - Algorithms for Competitive Programming](https://cp-algorithms.com/data_structures/sparse-table.html)

---
# Sparse Table
**Sparse Table** adalah struktur data yang dirancang untuk menjawab **range queries** (kueri rentang) dengan sangat efisien. Meskipun sebagian besar kueri rentang bisa dijawab dalam waktu **$O(\log n)$**, keunggulan utamanya adalah pada **Range Minimum Query (RMQ)** (kueri nilai minimum rentang) atau kueri serupa seperti **Range Maximum Query**. Untuk kueri ini, Sparse Table dapat memberikan jawaban dalam waktu **$O(1)$**.

Satu-satunya kelemahan dari struktur data ini adalah bahwa ia hanya dapat digunakan pada **array yang tidak dapat diubah (immutable)**. Ini berarti, jika ada elemen dalam array yang berubah, seluruh struktur data harus dihitung ulang (recomputed).

## 1 | Intuisi (Intuition)

Setiap bilangan non-negatif dapat direpresentasikan secara unik sebagai jumlah dari perpangkatan dua yang menurun. Ini hanyalah varian dari representasi biner sebuah bilangan. Sebagai contoh, $13 = (1101)_2 = 8 + 4 + 1$. Untuk sebuah bilangan $x$, paling banyak akan ada $\lceil \log_2 x \rceil$ suku penjumlahan.

Dengan penalaran yang sama, setiap interval dapat direpresentasikan secara unik sebagai gabungan dari interval-interval dengan panjang perpangkatan dua. Contohnya, $[2, 14]$ dapat dipecah menjadi $[2, 9] \cup [10, 13] \cup [14, 14]$, di mana interval penuh memiliki panjang 13, dan interval individu memiliki panjang 8, 4, dan 1 secara berurutan. Di sini juga, gabungan tersebut terdiri dari paling banyak $\lceil \log_2(\text{panjang interval}) \rceil$ buah interval. 

Ide utama di balik **Sparse Table** adalah untuk melakukan **pra-komputasi (precompute)** semua jawaban untuk kueri rentang dengan panjang yang merupakan perpangkatan dua. Setelah itu, kueri rentang lainnya dapat dijawab dengan memecah rentang tersebut menjadi beberapa rentang dengan panjang perpangkatan dua, mencari jawaban yang sudah dihitung sebelumnya, dan menggabungkannya untuk mendapatkan jawaban lengkap.

## 2 | Pra-komputasi (Precomputation)

Untuk pra-komputasi, kita menggunakan array 2-dimensi `st` untuk menyimpan jawaban dari kueri yang sudah dihitung. $\text{st}[i][j]$ akan menyimpan jawaban untuk rentang $[j, j + 2^i - 1]$ dengan panjang $2^i$. Ukuran array ini adalah $(\text{K} + 1) \times \text{MAXN}$, di mana $\text{MAXN}$ adalah panjang array maksimum yang mungkin, dan $\text{K}$ harus memenuhi $\text{K} \ge \lfloor \log_2 \text{MAXN} \rfloor$. Nilai ini dipilih karena $2^{\lfloor \log_2 \text{MAXN} \rfloor}$ adalah pangkat dua terbesar yang bisa kita dukung sebagai panjang rentang. Untuk array dengan panjang hingga $10^7$ elemen, nilai $K = 25$ adalah pilihan yang bagus.

Dimensi $\text{MAXN}$ diletakkan di posisi kedua (`st[i][j]`) untuk memungkinkan akses memori yang berdekatan, yang membuatnya lebih **cache-friendly**.

```cpp
int st[K + 1][MAXN];
```


Karena rentang $[j, j + 2^i - 1]$ dengan panjang $2^i$ dapat dibagi dengan rapi menjadi dua sub-rentang: $[j, j + 2^{i - 1} - 1]$ dan $[j + 2^{i - 1}, j + 2^i - 1]$, yang keduanya memiliki panjang $2^{i - 1}$, kita dapat membuat tabel ini secara efisien menggunakan **dynamic programming**.

Langkah-langkahnya adalah sebagai berikut:

1.  **Basis:** Kita salin elemen-elemen dari array asli ke dalam baris pertama `st[0]`. Ini karena setiap rentang dengan panjang $2^0 = 1$ adalah elemen itu sendiri.
    ```cpp
    std::copy(array.begin(), array.end(), st[0]);
    ```
2.  **Rekurensi:** Kita mengisi tabel dengan melakukan iterasi dari $i = 1$ hingga $K$. Untuk setiap $i$ dan setiap posisi awal $j$, `st[i][j]` dihitung dengan menggabungkan hasil dari dua sub-rentang sebelumnya yang memiliki panjang $2^{i-1}$.
    ```cpp
    for (int i = 1; i <= K; i++)
        for (int j = 0; j + (1 << i) <= N; j++)
            st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    ```

Fungsi $f$ bergantung pada jenis kueri: untuk **range sum queries**, $f$ akan menjumlahkan kedua nilai, sementara untuk **range minimum queries** (atau **range maximum queries**), $f$ akan mengambil nilai minimum (atau maksimum).

Kompleksitas waktu dari proses pra-komputasi ini adalah **$O(N \log N)$**, karena kita memiliki dua loop bersarang di mana loop luar berjalan $\log N$ kali dan loop dalam berjalan $N$ kali.

## 3 | Range Sum Queries

Untuk jenis kueri ini, kita ingin menemukan jumlah semua nilai dalam suatu rentang. Oleh karena itu, definisi alami untuk fungsi $f$ adalah $f(x, y) = x + y$. Kita dapat membangun struktur datanya dengan cara berikut:

```cpp
long long st[K + 1][MAXN];
std::copy(array.begin(), array.end(), st[0]);
for (int i = 1; i <= K; i++)
    for (int j = 0; j + (1 << i) <= N; j++)
        st[i][j] = st[i - 1][j] + st[i - 1][j + (1 << (i - 1))];
```

Untuk menjawab kueri jumlah (sum query) pada rentang $[L, R]$, kita akan mengiterasi semua pangkat dua, dimulai dari yang terbesar. Setiap kali pangkat dua $2^i$ lebih kecil atau sama dengan panjang rentang $(R - L + 1)$, kita akan memproses bagian pertama dari rentang $[L, L + 2^i - 1]$ dan melanjutkan dengan rentang sisanya, $[L + 2^i, R]$.

```cpp
long long sum = 0;
for (int i = K; i >= 0; i--) {
    if ((1 << i) <= R - L + 1) {
        sum += st[i][L];
        L += 1 << i;
    }
}
```

Kompleksitas waktu untuk sebuah Range Sum Query adalah $O(K) = O(\log \text{MAXN})$.

## 4 | Range Minimum Queries (RMQ)

Sparse Table sangat efektif untuk kueri minimum rentang karena operasi minimum bersifat **idempotent**, artinya `min(x, x) = x`. Properti ini memungkinkan kita untuk membagi rentang yang dicari menjadi dua rentang yang **tumpang tindih** (overlapping), tanpa memengaruhi hasilnya. Misalnya, untuk mencari minimum pada rentang $[1, 6]$, kita dapat membaginya menjadi rentang $[1, 4]$ dan $[3, 6]$. Nilai minimum dari $[1, 6]$ sama dengan nilai minimum dari `min(minimum([1, 4]), minimum([3, 6]))`.

Oleh karena itu, kita dapat menjawab kueri minimum untuk rentang $[L, R]$ menggunakan rumus:

$$\min(\text{st}[i][L], \text{st}[i][R - 2^i + 1])$$

di mana $i = \lfloor \log_2(R - L + 1) \rfloor$. Nilai $i$ adalah pangkat dua terbesar yang terkandung dalam panjang rentang.

Untuk menghitung $\lfloor \log_2(x) \rfloor$ dengan cepat, kita bisa menggunakan beberapa metode:

1.  **Pra-komputasi (Precomputation)**: Buat tabel `lg` untuk menyimpan nilai logaritma dari 1 hingga `MAXN`.

    ```cpp
    int lg[MAXN+1];
    lg[1] = 0;
    for (int i = 2; i <= MAXN; i++)
        lg[i] = lg[i/2] + 1;
    ```

2.  **Fungsi *Built-in***: Beberapa kompilator C++ menyediakan fungsi untuk menghitung logaritma basis 2 dengan sangat cepat, seperti `std::bit_width` (C++20) atau `__builtin_clz` (sebelum C++20).

    ```cpp
    // C++20
    #include <bit>
    int log2_floor(unsigned long i) {
        return std::bit_width(i) - 1;
    }

    // pre C++20
    int log2_floor(unsigned long long i) {
        return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
    }
    ```

    Berdasarkan beberapa benchmark, menggunakan fungsi *built-in* ini umumnya lebih cepat karena menghindari *cache misses* yang mungkin terjadi saat mengakses array `lg`.


Setelah tabel Sparse Table (`st`) diisi, kita dapat menemukan minimum dari rentang $[L, R]$ dengan:

```cpp
int i = lg[R - L + 1];
int minimum = min(st[i][L], st[i][R - (1 << i) + 1]);
```

**Kompleksitas waktu** untuk menjawab sebuah **Range Minimum Query** adalah **$O(1)$**, yang merupakan keunggulan utama dari Sparse Table. Ini membuatnya sangat ideal untuk kasus di mana Anda memiliki banyak kueri pada array yang tidak berubah.

## 5 | Struktur Data Serupa yang Mendukung Lebih Banyak Jenis Kueri

Beberapa struktur data yang mirip dengan Sparse Table dapat menangani lebih banyak jenis kueri. Kelemahan utama dari Sparse Table adalah efisiensi **$O(1)$**-nya hanya berlaku untuk kueri dengan fungsi-fungsi **idempotent**, seperti `min` atau `max`. Karena itu, ia tidak cocok untuk kueri seperti **Range Sum Queries** karena fungsi penjumlahan (`+`) bukanlah fungsi idempotent.

Untuk mengatasi batasan ini, ada struktur data lain yang dirancang untuk menjawab kueri rentang dalam **$O(1)$** untuk berbagai jenis fungsi asosiatif. Dua contoh yang paling menonjol adalah:

* **Disjoint Sparse Table**: Struktur data ini memecah array menjadi blok-blok, lalu pra-komputasi jawaban untuk rentang di dalam dan di antara blok-blok tersebut. Ini memungkinkan kueri pada rentang apa pun dijawab dalam waktu konstan.

* **Sqrt Tree**: Struktur ini juga memecah array, tetapi menggunakan pendekatan yang berbeda, seringkali mengandalkan dekomposisi array menjadi blok-blok yang berukuran akar kuadrat (square root). Mirip dengan Disjoint Sparse Table, Sqrt Tree juga bisa menjawab kueri untuk fungsi-fungsi asosiatif dalam waktu konstan.

Dengan demikian, jika Anda membutuhkan kecepatan **$O(1)$** untuk kueri yang tidak idempotent (seperti penjumlahan), Anda bisa menggunakan struktur data yang lebih canggih ini.