---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 07TH-DPCP-0002
nama_algoritma: knapsack problem
kategori_algoritma: dynamic programming
kesulitan: 🥈 medium
time_complexity:
memory_complexity:
sumber:
  - cp-algorithms.com
date_learned: 2025-09-05T16:46:00
tags:
  - dynamic-programming
---
Link sumber: [Knapsack Problem - Algorithms for Competitive Programming](https://cp-algorithms.com/dynamic_programming/knapsack.html)

---
# Masalah Knapsack

Pengetahuan Prasyarat: [[01-Introduction to Dynamic Programming]]

## 1 | Pendahuluan

Pertimbangkan contoh berikut:

### [[USACO07 Dec] Charm Bracelet](https://www.acmicpc.net/problem/6144)
Terdapat $n$ barang yang berbeda dan sebuah knapsack dengan kapasitas $W$. Setiap barang memiliki 2 atribut, yaitu berat ($w_{i}$) dan nilai ($v_{i}$). Kamu harus memilih sebuah *subset* barang untuk dimasukkan ke dalam knapsack, dengan syarat total berat tidak boleh melebihi kapasitas $W$ dan total nilai harus semaksimal mungkin.

Dalam contoh di atas, setiap barang hanya memiliki dua kemungkinan keadaan: dipilih atau tidak dipilih, yang sesuai dengan biner 0 dan 1. Oleh karena itu, jenis permasalahan ini disebut “0-1 Knapsack Problem”.
## 2 | 0-1 Knapsack

### Penjelasan

Pada contoh di atas, masukan (input) dari masalah ini adalah:

- Berat barang ke-$i$ ($w_{i}$)
- Nilai barang ke-$i$ ($v_{i}$)
- Total kapasitas knapsack ($W$)

Misalkan $f_{i,j}$  adalah _state dynamic programming_ yang menyimpan nilai total maksimum yang dapat dibawa knapsack dengan kapasitas $j$ , ketika hanya mempertimbangkan $i$ barang pertama.

Sekarang, jika semua _state_ untuk $i-1$ barang pertama sudah dihitung, apa pilihan untuk barang ke-$i$?

1. **Barang tidak dimasukkan ke knapsack**

   * Kapasitas yang tersisa tidak berubah
   * Nilai total tidak berubah
   * Maka nilai maksimum dalam kasus ini adalah:
     \$f\_{i-1, j}\$

2. **Barang dimasukkan ke knapsack**

   * Kapasitas yang tersisa berkurang sebesar \$w\_{i}\$
   * Nilai total bertambah sebesar \$v\_{i}\$
   * Maka nilai maksimum dalam kasus ini adalah:
     \$f\_{i-1, j-w\_i} + v\_i\$

Dari sini kita bisa menurunkan persamaan transisi DP:

$$
f_{i, j} = \max(f_{i-1, j},\; f_{i-1, j-w_i} + v_i)
$$

Lebih lanjut, karena \$f\_{i}\$ hanya bergantung pada \$f\_{i-1}\$, maka dimensi pertama bisa dihapus. Sehingga kita memperoleh aturan transisi:

$$
f_j \gets \max(f_j,\; f_{j-w_i}+v_i)
$$

Transisi ini harus dijalankan **dari nilai \$j\$ yang besar ke kecil** (*decreasing order*), supaya \$f\_{j-w\_i}\$ secara implisit merujuk ke \$f\_{i-1, j-w\_i}\$, bukan ke \$f\_{i, j-w\_i}\$.

---

### Catatan Penting

Sangat penting untuk memahami aturan transisi ini, karena sebagian besar transisi pada masalah knapsack diturunkan dengan cara yang mirip.

---

Apakah kamu mau aku juga bikinkan **contoh kode DP knapsack 0-1 (C++/Python)** biar lebih gampang dipahami?
