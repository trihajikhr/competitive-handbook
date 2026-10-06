---
obsidianUIMode: preview
note_type: book theory
judul_materi: Representasi dan Struktur Data pada Grid Graphs
sumber:
  - myself
date_learned: 2026-07-30T18:45:00
tags:
  - graphs
  - grid-graphs
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Representasi dan Struktur Data pada Grid Graphs

## Pengantar

Setelah memahami fondasi teoretis dari *grid graph*, langkah awal dalam mengimplementasikannya ke dalam kode adalah menentukan bagaimana graf tersebut disimpan di memori komputer. Berbeda dengan graf umum yang membutuhkan matriks ketetanggaan (*adjacency matrix*) atau daftar ketetanggaan (*adjacency list*) yang memakan memori berlebih, struktur spasial *grid graph* yang sangat teratur memungkinkan kita merepresentasikannya secara implisit tanpa menyimpan *edges* secara eksplisit.

## Strategi Representasi Memori

Dalam bahasa C++, terdapat dua pendekatan utama untuk merepresentasikan *grid graph* di memori:

### 1. Grid Dua Dimensi (Implicit Representation)

Pendekatan ini menggunakan array dua dimensi atau `std::vector<std::vector<T>>`. Koordinat baris ($r$) dan kolom ($c$) secara langsung berfungsi sebagai identifikasi *vertex*.

* Pengaksesan elemen bernilai kompleksitas $\mathcal{O}(1)$.
* Tidak memerlukan alokasi memori tambahan untuk menyimpan *edges*, karena keterhubungan antar-*vertex* dihitung secara dinamis saat runtime berdasarkan tetangga di sekitarnya.

### 2. Linierisasi Grid Satu Dimensi (Flattened Grid)

Pendekatan ini memetakan matriks dua dimensi berukuran $R \times C$ ke dalam array satu dimensi berukuran $R \cdot C$. Pemetaan koordinat dua dimensi $(r, c)$ menjadi indeks linier tunggal $i$ dilakukan menggunakan formula:


$$i = r \cdot C + c$$

Sebaliknya, untuk mengembalikan indeks linier $i$ menjadi koordinat dua dimensi $(r, c)$, kita menggunakan operasi pembagian dan modulus:


$$r = \lfloor i / C \rfloor, \quad c = i \bmod C$$

Pendekatan satu dimensi ini menawarkan keuntungan *cache locality* yang lebih baik dan mempermudah pengintegrasian dengan struktur data graf standar seperti Disjoint Set Union (DSU) atau algoritma pencarian rute berbasis prioritas.

## Penanganan Batas dan Arah Gerak (*Direction Arrays*)

Untuk menelusuri tetangga dari suatu *vertex* pada koordinat $(r, c)$, pergerakan ortogonal (atas, bawah, kiri, kanan) dipetakan menggunakan *direction arrays* atau *offset arrays*. Teknik ini menghindari penulisan percabangan `if-else` yang berulang.

```cpp
// Offset arah pergerakan ortogonal: {delta_baris, delta_kolom}
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

// Pengecekan apakah koordinat (nr, nc) berada dalam batas grid berukuran R x C
bool isValid(int nr, int nc, int R, int C) {
    return (nr >= 0 && nr < R && nc >= 0 && nc < C);
}
```

## Kompleksitas Ruang dan Akses Memori

| Skema Representasi | Kompleksitas Memori | Kompleksitas Akses Tetangga |
| --- | --- | --- |
| Implicit 2D Array | $\mathcal{O}(R \cdot C)$ | $\mathcal{O}(1)$ per tetangga |
| Flattened 1D Array | $\mathcal{O}(R \cdot C)$ | $\mathcal{O}(1)$ per tetangga |
| Explicit Adjacency List | $\mathcal{O}(R \cdot C)$ | $\mathcal{O}(1)$ dengan *overhead* memori hingga 4x lipat |

Implikasi utama dari sifat *grid graph* adalah bahwa penggunaan *adjacency list* eksplisit umumnya merupakan sebuah redundansi. Penyimpanan implisit menggunakan array 2D atau 1D beserta *direction arrays* jauh lebih efisien dan direkomendasikan untuk sebagian besar kasus komputasi.