---
obsidianUIMode: preview
note_type: book theory
judul_materi: Sifat Bipartit pada Grid Graphs
sumber:
  - myself
date_learned: 2026-07-30T18:35:00
tags:
  - graphs
  - grid-graphs
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Sifat Bipartit pada Grid Graphs

## Pengantar

Salah satu karakteristik struktural yang paling menarik dan berguna dari *grid graph* adalah sifat bipartitnya. Dalam teori graf, sebuah *bipartite graph* adalah graf yang himpunan simpulnya dapat dibagi menjadi dua himpunan bagian yang saling lepas, sedemikian rupa sehingga tidak ada dua *vertex* di dalam himpunan bagian yang sama yang terhubung langsung oleh sebuah *edge*.

## Karakterisasi Sifat Bipartit

Sebuah *grid graph* secara universal selalu terbukti sebagai graf yang *bipartite*. Untuk memahami mengapa hal ini selalu berlaku, kita dapat melihat pola geometris dari grid itu sendiri.

Jika kita membayangkan sebuah papan catur atau *grid*, setiap langkah pergerakan dari satu *vertex* ke *vertex* tetangganya selalu berpindah dari kolom ganjil ke genap, atau dari baris dengan indeks tertentu ke indeks berikutnya secara bergantian. Properti ini membuat seluruh simpul dalam *grid graph* dapat dipartisi ke dalam dua kelompok terpisah secara konsisten.

## Pembuktian Melalui Pewarnaan Koordinat

Cara paling intuitif dan matematis untuk membuktikan sifat bipartit pada *grid graph* adalah melalui pelabelan atau pewarnaan dua warna berdasarkan koordinat simpulnya.

Misalkan setiap *vertex* pada grid direpresentasikan oleh pasangan koordinat $(x, y)$, di mana $x$ adalah indeks baris dan $y$ adalah indeks kolom. Kita dapat membagi seluruh *vertices* $V$ menjadi dua himpunan bagian, $V_1$ dan $V_2$, berdasarkan jumlah dari koordinat tersebut:

* Himpunan $V_1$ berisi semua *vertex* $(x, y)$ di mana jumlah koordinatnya bernilai genap:

$$(x + y) \equiv 0 \pmod 2$$


* Himpunan $V_2$ berisi semua *vertex* $(x, y)$ di mana jumlah koordinatnya bernilai ganjil:

$$(x + y) \equiv 1 \pmod 2$$



Ketika kita memeriksa setiap *edge* yang menghubungkan dua *vertex* yang bertetangga, jarak perpindahan selalu melibatkan perubahan nilai koordinat sebesar tepat satu satuan pada salah satu sumbu (baik $x$ maupun $y$). Akibat perubahan ini, jika suatu simpul berada pada kelompok dengan jumlah koordinat genap, maka seluruh tetangganya pasti berada pada kelompok dengan jumlah koordinat ganjil, dan begitu pula sebaliknya. Tidak akan pernah ada *edge* yang menghubungkan dua *vertex* di dalam himpunan $V_1$ yang sama, ataupun di dalam himpunan $V_2$ yang sama.

## Implikasi dan Penerapan

Kehadiran sifat bipartit ini memberikan keuntungan besar dalam berbagai masalah komputasi dan *competitive programming*:

* *Graph Coloring*: Memastikan bahwa *grid graph* selalu dapat diwarnai hanya menggunakan dua warna (*2-colorable*).
* *Maximum Matching*: Mempermudah penyelesaian masalah pemasangan maksimal (*matching*) dengan mereduksinya menjadi algoritma aliran maksimum (*maximum flow*) pada graf berarah dua bagian (*bipartite matching*).
* Model Permainan: Digunakan untuk menganalisis strategi kemenangan pada permainan papan atau masalah penempatan objek di atas petak-petak grid.