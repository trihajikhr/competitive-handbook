---
obsidianUIMode: preview
note_type: book theory
judul_materi: Perbedaan Multiset dengan Set
sumber:
  - myself
date_learned: 2026-07-27T20:58:00
tags:
  - data-structures
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Perbedaan Multiset dengan Set

## Penanganan *Duplicate Elements*

Perbedaan paling mendasar terletak pada cara kedua *containers* ini menangani *duplicate elements*. `std::set` adalah sebuah *unique associative container* yang hanya menyimpan *elements* dengan *values* unik; jika kita mencoba memasukkan *value* yang sudah ada, operasi tersebut akan diabaikan dan tidak mengubah *container*. Sebaliknya, `std::multiset` mengizinkan penyimpanan *duplicate elements*, sehingga penambahan *value* yang sama akan selalu diterima dan menambah jumlah total *elements* di dalam *container*.

## Perilaku Fungsi Anggota Pencarian (*Search Operations*)

Karena karakteristik keunikan nilainya, fungsi pencarian seperti `std::set::count` akan selalu mengembalikan nilai $0$ atau $1$. Sementara itu, pada `std::multiset`, fungsi `std::multiset::count` dapat mengembalikan angka lebih dari $1$ tergantung pada seberapa banyak *elements* identik yang tersimpan. Dalam hal pengambilan rentang, fungsi `std::equal_range` sangat esensial pada `std::multiset` untuk mengembalikan sepasang *iterators* yang mencakup seluruh kemunculan dari sebuah *value* spesifik.

## Penggunaan Memori dan Performa

Meskipun keduanya sama-sama diimplementasikan menggunakan *Balanced Binary Search Tree* (biasanya *Red-Black Tree*) dengan kompleksitas waktu operasi dasar $O(\log n)$, `std::multiset` umumnya mengonsumsi memori tambahan yang lebih besar secara akumulatif apabila terdapat banyak *duplicate elements* karena setiap *node* baru dialokasikan secara independen di dalam memori *heap*, tanpa ada mekanisme penggabungan atau kompresi frekuensi seperti pada `std::map`.

## Kesimpulan

Perbedaan utama antara `std::set` dan `std::multiset` terletak pada penanganan *duplicate elements*. 

`std::set` hanya menyimpan *unique elements* dengan fungsi `count` yang menghasilkan maksimal nilai $1$, sedangkan `std::multiset` mengizinkan duplikasi data sehingga fungsi `count` dapat mengembalikan nilai lebih dari $1$. Dari segi performa dan struktur internal, keduanya identik menggunakan *Balanced Binary Search Tree* dengan kompleksitas waktu operasi $O(\log n)$, namun `std::multiset` lebih optimal untuk skenario yang membutuhkan pelacakan frekuensi kemunculan *values* secara langsung melalui *range queries* seperti `equal_range`.

