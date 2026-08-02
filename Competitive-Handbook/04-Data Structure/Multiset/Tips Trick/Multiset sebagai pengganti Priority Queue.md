---
obsidianUIMode: preview
note_type: book theory
judul_materi: Multiset sebagai pengganti Priority Queue
sumber:
  - myself
date_learned: 2026-07-27T22:39:00
tags:
  - data-structures
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Multiset sebagai pengganti Priority Queue

Secara default, `std::priority_queue` hanya memungkinkan kita untuk melihat atau menghapus elemen terbesar (atau terkecil) di bagian ujung saja. Struktur tersebut tidak menyediakan fungsi `erase()` untuk membuang elemen arbitrer yang berada di tengah-tengah antrean.

Jika dalam sebuah masalah (seperti algoritma *greedy* atau *sliding window*) kamu membutuhkan struktur data yang bisa mengambil elemen maksimum/minimum secara cepat, sekaligus bisa menghapus elemen sembarang di tengah wadah, maka `std::multiset` adalah solusi yang tepat. Elemen terkecil selalu bisa diakses melalui `*angka.begin()`, dan elemen terbesar melalui `*--angka.end()`.

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> angka = {30, 10, 50, 20};

    // Mengakses elemen terkecil dan terbesar layaknya priority queue
    std::cout << "Nilai minimum: " << *angka.begin() << "\n";
    std::cout << "Nilai maksimum: " << *--angka.end() << "\n";

    // Menghapus elemen spesifik di tengah (tidak bisa dilakukan di priority_queue biasa)
    auto it = angka.find(30);
    if (it != angka.end()) {
        angka.erase(it);
    }

    std::cout << "Minimum baru setelah 30 dihapus: " << *angka.begin() << "\n";

    return 0;
}

```

## Mengapa Ini bekerja?

Bagian ini membahas secara komprehensif landasan kerja dan alasan mengapa penggunaan `std::multiset` dapat berfungsi sebagai pengganti *priority queue* dinamis dalam pemrograman kompetitif.

### 1. Representasi Struktur Data di Bawah Tendensi *Binary Search Tree*

Secara internal, pustaka standar C++ mengimplementasikan `std::multiset` menggunakan struktur data berbasis *self-balancing binary search tree* (umumnya menggunakan varian *Red-Black Tree*).

* Setiap elemen disimpan sebagai simpul atau *node* di dalam *tree*.
* Properti utama dari *tree* ini adalah elemen-elemen selalu berada dalam keadaan terurut (*sorted order*) secara otomatis setiap kali terjadi operasi penyisipan (`insert`) atau penghapusan (`erase`).

### 2. Kompleksitas Waktu Operasi Utama

Berbeda dengan `std::priority_queue` standar yang dibangun di atas *underlying container* berupa *vector* (sehingga tidak mendukung pencarian atau penghapusan elemen arbitrer secara efisien), `std::multiset` menawarkan kompleksitas waktu yang berbeda untuk setiap operasinya:

| Operasi | `std::priority_queue` | `std::multiset` |
| --- | --- | --- |
| Akses Ekstrem (Min/Max) | $O(1)$ | $O(1)$ (melalui iterator `begin()` / `--end()`) |
| Penyisipan Elemen (`insert`) | $O(\log N)$ | $O(\log N)$ |
| Pencarian Elemen Arbitrer (`find`) | Tidak Mendukung | $O(\log N)$ |
| Penghapusan Elemen Arbitrer (`erase`) | Tidak Mendukung | $O(\log N)$ (jika iterator diketahui) |

### 3. Mekanisme Kerja Akses Elemen Ekstrem

Karena elemen di dalam `std::multiset` selalu terurut secara penuh:

* *Node* paling kiri dari struktur *tree* selalu merepresentasikan nilai terkecil. Fungsi `angka.begin()` mengembalikan sebuah *bidirectional iterator* ke *node* tersebut, sehingga dereferensi `*angka.begin()` memberikan akses instan berwaktu $O(1)$ ke nilai minimum.
* *Node* paling kanan merepresentasikan nilai terbesar. Ekspresi `*--angka.end()` memanfaatkan iterator penutup (*past-the-end iterator*) dari `angka.end()` yang digeser mundur satu langkah untuk mencapai elemen maksimum dengan kompleksitas $O(1)$.

### 4. Fleksibilitas Penghapusan Elemen Sembarang

Alasan paling krusial mengapa trik ini sukses digunakan pada masalah seperti *sliding window* atau algoritma *greedy* tingkat lanjut adalah kemampuan metode `erase()` menerima argumen berupa iterator:

```cpp
auto it = angka.find(30);
if (it != angka.end()) {
    angka.erase(it);
}
```

Ketika fungsi `angka.find(30)` dipanggil, struktur internal melakukan penelusuran *tree* untuk menemukan *node* yang bernilai `30` dalam waktu $O(\log N)$. Setelah iterator yang menunjuk ke lokasi persis elemen tersebut didapatkan, fungsi `angka.erase(it)` dapat langsung membuang elemen tersebut dan melakukan penyeimbangan ulang *tree* (*rebalancing*) dalam waktu $O(\log N)$ tanpa merusak urutan elemen lainnya. Kemampuan inilah yang tidak dimiliki oleh `std::priority_queue` konvensional.