---
obsidianUIMode: preview
note_type: book theory
judul_materi: Kompleksitas Multiset
sumber:
  - myself
date_learned: 2026-07-27T22:22:00
tags:
  - data-structures
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Kompleksitas Multiset

Dalam analisis algoritma dan pemrograman kompetitif, memahami kompleksitas waktu dan ruang dari suatu struktur data adalah kunci utama untuk menghindari *Time Limit Exceeded* (*TLE*) dan *Memory Limit Exceeded* (*MLE*). Karena `std::multiset` diimplementasikan menggunakan *balanced binary search tree* (biasanya *Red-Black Tree*), karakteristik performanya berbeda secara signifikan jika dibandingkan dengan wadah sekuensial seperti `std::vector`.

Catatan ini merinci kompleksitas waktu untuk setiap operasi dasar serta analisis penggunaan memori dari `std::multiset`.

## Kompleksitas Waktu (*Time Complexity*)

Setiap operasi pada `std::multiset` bergantung pada ukuran wadah $N$ yang menyatakan jumlah total elemen saat ini:

* Operasi `insert()` dan `emplace()`: Berlangsung dalam waktu $O(\log N)$ karena elemen baru harus disisipkan pada posisi yang menjaga keterurutan dan keseimbangan *tree*.
* Operasi `erase()` berdasarkan *iterator*: Membutuhkan waktu $O(\log N)$ untuk pencarian *node*, namun mendekati $O(1)$ secara *amortized* jika *iterator* yang valid sudah berada di tangan.
* Operasi `erase()` berdasarkan *value* atau rentang *iterator*: Berlangsung dalam waktu $O(\log N + K)$, di mana $K$ adalah jumlah elemen duplikat yang berhasil dihapus dari wadah.
* Operasi pencarian seperti `find()`, `count()`, `lower_bound()`, dan `upper_bound()`: Berlangsung dalam waktu $O(\log N)$ melalui mekanisme pencarian biner pada *tree*.
* Traversal atau iterasi penuh menggunakan *iterator*: Memakan waktu $O(N)$ untuk mengunjungi seluruh elemen secara keseluruhan, dengan biaya $O(\log N)$ secara *amortized* untuk melompat antar *node* yang berdekatan.

## Kompleksitas Ruang (*Space Complexity*)

* Kompleksitas ruang secara keseluruhan untuk menyimpan $N$ elemen di dalam wadah adalah $O(N)$.
* Namun, terdapat *memory overhead* yang cukup signifikan dibandingkan `std::vector`. Setiap elemen tidak hanya menyimpan nilainya saja, tetapi dibungkus dalam sebuah *node* yang memerlukan memori ekstra untuk menyimpan tiga *pointer* (*parent*, *left child*, dan *right child*) serta informasi penanda warna pada *Red-Black Tree*.