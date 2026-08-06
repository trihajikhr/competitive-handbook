---
obsidianUIMode: preview
note_type: book theory
judul_materi: Knapsack Problem
sumber:
  - cp-algorithms.com
date_learned: 2026-03-07T05:46:00
tags:
---
Link Sumber: [Knapsack Problem - Algorithms for Competitive Programming](https://cp-algorithms.com/dynamic_programming/knapsack.html)

---

> [!IMPORTANT]
>  
# Knapsack Problem

Prasyarat Pengetahuan: [Introduction to Dynamic Programming](https://cp-algorithms.com/dynamic_programming/intro-to-dp.html)

## Introduction

Perhatikan contoh berikut:

### [USACO07 Dec] Charm Bracelet

Terdapat $n$ barang yang berbeda dan sebuah tas (knapsack) dengan kapasitas $W$. Setiap barang memiliki 2 atribut, yaitu berat ($w_{i}$) dan nilai ($v_{i}$). Anda harus memilih subset barang untuk dimasukkan ke dalam tas sedemikian rupa sehingga total berat tidak melebihi kapasitas $W$ dan total nilai dimaksimalkan.

Pada contoh di atas, setiap objek hanya memiliki dua kemungkinan status (diambil atau tidak diambil), yang sesuai dengan biner 0 dan 1. Oleh karena itu, jenis masalah ini disebut "*0-1 knapsack problem*".
## 0-1 Knapsack

### Explanation

Dalam contoh di atas, input untuk masalah tersebut adalah sebagai berikut: berat dari barang ke-$i$ yaitu $w_{i}$, nilai dari barang ke-$i$ yaitu $v_{i}$, dan total kapasitas tas $W$.

Misalkan $f_{i, j}$ menjadi status pemrograman dinamis (_dynamic programming state_) yang menyimpan total nilai maksimum yang dapat dibawa tas dengan kapasitas $j$, ketika hanya $i$ barang pertama yang dipertimbangkan.

Dengan asumsi bahwa semua status dari $i-1$ barang pertama telah diproses, apa saja pilihan untuk barang ke-$i$?

- Ketika barang tersebut **tidak dimasukkan** ke dalam tas, sisa kapasitas tetap tidak berubah dan total nilai tidak berubah. Oleh karena itu, nilai maksimum dalam kasus ini adalah $f_{i-1, j}$.
    
- Ketika barang tersebut **dimasukkan** ke dalam tas, sisa kapasitas berkurang sebesar $w_{i}$ dan total nilai bertambah sebesar $v_{i}$, sehingga nilai maksimum dalam kasus ini adalah $f_{i-1, j-w_i} + v_i$.


Dari sini kita dapat menurunkan persamaan transisi (_transition_) DP:

$$f_{i, j} = \max(f_{i-1, j}, f_{i-1, j-w_i} + v_i)$$

Lebih lanjut, karena $f_{i}$ hanya bergantung pada $f_{i-1}$, kita dapat menghapus dimensi pertama. Kita mendapatkan aturan transisi:

$$f_j \gets \max(f_j, f_{j-w_i}+v_i)$$

Aturan tersebut harus dijalankan dalam urutan $j$ yang **menurun** (sehingga $f_{j-w_i}$ secara implisit merujuk pada $f_{i-1, j-w_i}$ dan bukan $f_{i, j-w_i}$).

**Sangat penting untuk memahami aturan transisi ini, karena sebagian besar transisi untuk masalah knapsack diturunkan dengan cara yang serupa.**

### Implementation

Algoritma yang dijelaskan dapat diimplementasikan dalam $O(nW)$ sebagai berikut:

```cpp
for (int i = 1; i <= n; i++)
  for (int j = W; j >= w[i]; j--)
    f[j] = max(f[j], f[j - w[i]] + v[i]);
```

Sekali lagi, perhatikan urutan eksekusinya. Urutan ini harus diikuti dengan ketat untuk memastikan **invarian** (_invariant_) berikut: Tepat sebelum pasangan $(i, j)$ diproses, $f_k$ sesuai dengan $f_{i,k}$ untuk $k > j$, tetapi sesuai dengan $f_{i-1,k}$ untuk $k < j$. Hal ini memastikan bahwa $f_{j-w_i}$ diambil dari langkah ke-$(i-1)$, dan bukan dari langkah ke-$i$.

## Complete Knapsack

Model _complete knapsack_ mirip dengan 0-1 _knapsack_, satu-satunya perbedaan adalah bahwa suatu barang dapat dipilih dalam jumlah yang tidak terbatas, bukan hanya sekali.

Kita dapat merujuk pada ide 0-1 _knapsack_ untuk mendefinisikan status: $f_{i, j}$, yaitu nilai maksimum yang dapat diperoleh tas menggunakan $i$ barang pertama dengan kapasitas maksimum $j$.

Perlu dicatat bahwa meskipun definisi statusnya mirip dengan 0-1 _knapsack_, aturan **transisi** (_transition_) miliknya berbeda.
### Explanation

Pendekatan yang sepele (_trivial_) adalah, untuk $i$ barang pertama, lakukan enumerasi berapa kali setiap barang akan diambil. Kompleksitas waktu dari pendekatan ini adalah $O(n^2W)$.

Hal ini menghasilkan persamaan transisi berikut:

$$f_{i, j} = \max\limits_{k=0}^{\infty}(f_{i-1, j-k\cdot w_i} + k\cdot v_i)$$

Pada saat yang sama, ini dapat disederhanakan menjadi persamaan yang lebih "datar":

$$f_{i, j} = \max(f_{i-1, j}, f_{i, j-w_i} + v_i)$$

Alasan mengapa ini berhasil adalah karena $f_{i, j-w_i}$ sudah diperbarui oleh $f_{i, j-2\cdot w_i}$ dan seterusnya.

Sama seperti 0-1 _knapsack_, kita dapat menghapus dimensi pertama untuk mengoptimalkan kompleksitas ruang. Ini memberi kita aturan transisi yang sama dengan 0-1 _knapsack_:

$$f_j \gets \max(f_j, f_{j-w_i}+v_i)$$

### Implementation

Algoritma yang dijelaskan dapat diimplementasikan dalam $O(nW)$ sebagai berikut:

```cpp
for (int i = 1; i <= n; i++)
  for (int j = w[i]; j <= W; j++)
    f[j] = max(f[j], f[j - w[i]] + v[i]);
```

Meskipun memiliki aturan transisi yang sama, kode di atas tidak tepat untuk 0-1 _knapsack_.

Jika kita mengamati kode tersebut dengan teliti, kita melihat bahwa untuk barang $i$ yang sedang diproses dan status saat ini $f_{i,j}$, ketika $j \ge w_i$, maka $f_{i,j}$ akan dipengaruhi oleh $f_{i,j-w_i}$. Ini setara dengan kemampuan untuk memasukkan barang $i$ ke dalam ransel berkali-kali, yang konsisten dengan masalah _complete knapsack_ dan bukan masalah 0-1 _knapsack_.