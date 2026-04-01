---
obsidianUIMode: preview
note_type: book theory
judul_materi: Sparse Table
sumber:
  - cp-algorithms.com
date_learned: 2026-02-14T01:02:00
tags:
  - data-structure
  - range-queries
  - cp-algorithms
---
Link Sumber: [Sparse Table - Algorithms for Competitive Programming](https://cp-algorithms.com/data_structures/sparse-table.html)

---

> [!IMPORTANT]
>  
# Sparse Table

**Sparse Table** adalah sebuah struktur data yang memungkinkan untuk menjawab *range queries*. Ia dapat menjawab sebagian besar range queries dalam $O(\log n)$, tetapi kekuatan utamanya adalah menjawab *range minimum queries* (atau *range maximum queries* yang setara). Untuk kueri tersebut, ia dapat menghitung jawaban dalam waktu $O(1)$.

Satu-satunya kekurangan dari struktur data ini adalah ia hanya dapat digunakan pada array yang bersifat tidak dapat diubah (_immutable_). Artinya, array tidak boleh berubah di antara dua kueri. Jika ada elemen dalam array yang berubah, seluruh struktur data harus dihitung ulang.

## Intuition

Setiap bilangan non-negatif dapat direpresentasikan secara unik sebagai jumlah dari pangkat dua yang menurun. Ini hanyalah varian dari representasi biner sebuah angka. Contoh: $13 = (1101)_2 = 8 + 4 + 1$. Untuk sebuah angka $x$, maksimal terdapat $\lceil \log_2 x \rceil$ suku penjumlahan.

Dengan penalaran yang sama, setiap interval dapat direpresentasikan secara unik sebagai gabungan dari interval-interval dengan panjang yang merupakan pangkat dua menurun. Contoh: $[2, 14] = [2, 9] \cup [10, 13] \cup [14, 14]$, di mana interval lengkap memiliki panjang $13$, dan masing-masing interval individu memiliki panjang $8$, $4$, dan $1$ secara berurutan. Di sini juga gabungannya terdiri dari maksimal $\lceil \log_2(\text{panjang interval}) \rceil$ banyak interval.

Ide utama di balik Sparse Table adalah melakukan pra-penghitungan (*precompute*)[^1] semua jawaban untuk range queries dengan panjang pangkat dua. Setelah itu, range query yang berbeda dapat dijawab dengan membagi range tersebut menjadi beberapa range dengan panjang pangkat dua, mencari jawaban yang telah dihitung sebelumnya, dan menggabungkannya untuk mendapatkan jawaban lengkap.

## Precomputation

Kita akan menggunakan array 2-dimensi untuk menyimpan jawaban kueri yang telah dihitung sebelumnya. $st[i][j]$ akan menyimpan jawaban untuk range $[j, j + 2^i - 1]$ dengan panjang $2^i$. Ukuran array 2-dimensi tersebut adalah $(K + 1) \times \text{MAXN}$, di mana $MAXN$ adalah panjang array terbesar yang mungkin. $K$ harus memenuhi $K \ge \lfloor \log_2 \text{MAXN} \rfloor$, karena $2^{\lfloor \log_2 \text{MAXN} \rfloor}$ adalah range pangkat dua terbesar yang harus didukung. Untuk array dengan panjang yang wajar ($\le 10^7$ elemen), $K = 25$ adalah nilai yang baik.

Dimensi $MAXN$ diletakkan di posisi kedua untuk memungkinkan akses memori yang berurutan (*cache friendly*).

```cpp
int st[K + 1][MAXN];
```

Karena range $[j, j + 2^i - 1]$ dengan panjang $2^i$ terbagi dengan rapi menjadi range $[j, j + 2^{i - 1} - 1]$ dan $[j + 2^{i - 1}, j + 2^i - 1]$, keduanya dengan panjang $2^{i - 1}$, kita dapat membuat tabel secara efisien menggunakan _dynamic programming_:

```cpp
std::copy(array.begin(), array.end(), st[0]);

for (int i = 1; i <= K; i++)
    for (int j = 0; j + (1 << i) <= N; j++)
        st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
```

Fungsi $f$ akan bergantung pada tipe kueri. Untuk *range sum queries*, ia akan menghitung jumlah, untuk *range minimum queries* ia akan menghitung nilai minimum. Kompleksitas waktu dari precomputation adalah $O(N \log N)$.

## Range Sum Queries

Untuk jenis kueri ini, kita ingin mencari jumlah semua nilai dalam sebuah range. Oleh karena itu, definisi alami dari fungsi $f$ adalah $f(x, y) = x + y$. Kita dapat membangun struktur datanya dengan:

```cpp
long long st[K + 1][MAXN];

std::copy(array.begin(), array.end(), st[0]);

for (int i = 1; i <= K; i++)
    for (int j = 0; j + (1 << i) <= N; j++)
        st[i][j] = st[i - 1][j] + st[i - 1][j + (1 << (i - 1))];
```

Untuk menjawab kueri jumlah untuk range $[L, R]$, kita melakukan iterasi pada semua pangkat dua, dimulai dari yang terbesar. Begitu suatu pangkat dua $2^i$ lebih kecil atau sama dengan panjang range ($= R - L + 1$), kita memproses bagian pertama range $[L, L + 2^i - 1]$, dan melanjutkan dengan range yang tersisa $[L + 2^i, R]$.

```cpp
long long sum = 0;
for (int i = K; i >= 0; i--) {
    if ((1 << i) <= R - L + 1) {
        sum += st[i][L];
        L += 1 << i;
    }
}
```

Kompleksitas waktu untuk *Range Sum Query* adalah $O(K) = O(\log \text{MAXN})$.

## Range Minimum Queries (RMQ)

Ini adalah kueri di mana Sparse Table sangat unggul. Saat menghitung minimum dari suatu range, tidak masalah jika kita memproses suatu nilai dalam range tersebut sekali atau dua kali. Oleh karena itu, alih-alih membagi range menjadi banyak range, kita juga bisa membagi range tersebut menjadi hanya dua range yang tumpang tindih dengan panjang pangkat dua. Contoh: kita dapat membagi range $[1, 6]$ menjadi range $[1, 4]$ dan $[3, 6]$. Range minimum dari $[1, 6]$ jelas sama dengan minimum dari range minimum $[1, 4]$ dan range minimum $[3, 6]$. Jadi kita dapat menghitung minimum dari range $[L, R]$ dengan:

$$\min(\text{st}[i][L], \text{st}[i][R - 2^i + 1]) \quad \text{ di mana } i = \log_2(R - L + 1)$$

Ini mengharuskan kita untuk menghitung $\log_2(R - L + 1)$ dengan cepat. Anda bisa melakukannya dengan melakukan precompute pada semua logaritma:

```cpp
int lg[MAXN+1];
lg[1] = 0;
for (int i = 2; i <= MAXN; i++)
    lg[i] = lg[i/2] + 1;
```

Atau, log dapat dihitung secara langsung dalam waktu dan ruang yang konstan:

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

[Benchmark](https://quick-bench.com/q/Zghbdj_TEkmw4XG2nqOpD3tsJ8U) menunjukkan bahwa penggunaan array $lg$ lebih lambat karena adanya _cache misses_. Setelah itu, kita perlu melakukan precompute pada struktur Sparse Table. Kali ini kita mendefinisikan $f$ dengan $f(x, y) = \min(x, y)$.

```cpp
int st[K + 1][MAXN];

std::copy(array.begin(), array.end(), st[0]);

for (int i = 1; i <= K; i++)
    for (int j = 0; j + (1 << i) <= N; j++)
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
```

Dan minimum dari range $[L, R]$ dapat dihitung dengan:

```cpp
int i = lg[R - L + 1];
int minimum = min(st[i][L], st[i][R - (1 << i) + 1]);
```

Kompleksitas waktu untuk *Range Minimum Query* adalah $O(1)$.

> [!IMPORTANT]
> *Range Maximum Query* dan *Range Minimum Query* menggunakan pendekatan yang persis sama. Perbedaanya adalah, jika yang dicari adalah Maximum Query, maka ganti operasi $f(x, y) = min(x, y)$ menjadi $f(x,y) = max(x,y)$. Dan seluruh struktur Sparse Table tetap identik.

## Similar data structures supporting more types of queries

Salah satu kelemahan utama dari pendekatan $O(1)$ di atas adalah ia hanya mendukung kueri dari [fungsi idempoten](https://en.wikipedia.org/wiki/Idempotence) (_idempotent functions_). Artinya, ia bekerja sangat baik untuk range minimum queries, tetapi tidak mungkin menjawab range sum queries dengan pendekatan ini.

Ada struktur data serupa yang dapat menangani tipe fungsi asosiatif (_associative functions_) apa pun dan menjawab range queries dalam $O(1)$. Salah satunya adalah [Disjoint Sparse Table](https://discuss.codechef.com/questions/117696/tutorial-disjoint-sparse-table). Lainnya adalah [Sqrt Tree](https://cp-algorithms.com/data_structures/sqrt-tree.html).

[^1]: Precompute dalam coding adalah teknik mengolah atau menghitung data di awal (sebelum program utama atau bagian yang kritis dijalankan) dan menyimpan hasilnya untuk digunakan nanti. Tujuan utamanya adalah untuk menghemat waktu eksekusi saat program berjalan (runtime), sehingga program menjadi lebih cepat dan efisien, dengan melakukan Trade-off dengan memori.