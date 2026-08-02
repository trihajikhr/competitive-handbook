---
obsidianUIMode: preview
note_type: book theory
judul_materi: Grids and Graphs
sumber:
  - myself
date_learned: 2026-07-30T18:27:00
tags:
  - graphs
  - grid-graphs
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Grids and Graphs
![](_assets/Grids%20and%20Graphs-1.png)

## Apa itu Grid Graph?

Bayangkan kamu sedang melihat selembar kertas bergaris kotak-kotak atau papan catur. Setiap titik pertemuan antara garis vertikal dan horizontal bisa kita anggap sebagai sebuah titik, dan garis yang menghubungkan titik-titik yang bersebelahan adalah jalurnya.

Dalam ilmu komputer dan matematika, struktur seperti ini disebut sebagai *grid graph* (graf grid). Sederhananya, *grid graph* adalah jaringan titik dan jalur yang tersusun rapi dalam bentuk baris dan kolom yang teratur.

## Contoh dalam Kehidupan Sehari-Hari

Meskipun istilahnya terdengar teknis, konsep grid graph sangat dekat dengan kehidupan kita:

* **Peta Jalan di Kota**: Tata letak jalan di kota-kota modern (seperti Manhattan) dirancang menyerupai kotak-kotak. Persimpangan jalan adalah titiknya, dan ruas jalan di antara dua persimpangan adalah jalurnya.
* **Papan Permainan**: Papan catur, papan *tic-tac-toe*, atau petak-petak dalam permainan papan (*board games*) adalah contoh nyata dari grid graph.
* **Piksel Layar Komputer**: Setiap gambar di layar monitor terdiri dari jutaan titik kecil (piksel) yang tersusun dalam bentuk grid.

## Istilah Dasar yang Perlu Dikenal

Dalam mempelajari grid graph, ada beberapa istilah sederhana yang sering digunakan:

* **Vertex (Simpul / Titik)**: Tempat atau persimpangan. Jika ukuran grid adalah $3 \times 4$ (3 baris dan 4 kolom), maka total titik yang ada adalah $3 \times 4 = 12$ titik.
* **Edge (Sisi / Jalur)**: Garis penghubung lurus antara dua titik yang bersebelahan secara mendatar (kiri-kanan) atau tegak (atas-bawah).
* **Tetangga (Neighbors)**: Titik-titik yang terhubung langsung dengan suatu titik. Di tengah-tengah grid, sebuah titik biasanya memiliki 4 tetangga, yaitu atas, bawah, kiri, dan kanan.

## Mengapa Grid Graphs Penting?

Grid graph sangat populer dalam dunia pemrograman dan kecerdasan buatan karena bentuknya yang sangat teratur. Komputer sangat menyukai keteraturan ini karena memudahkan proses pencarian jalur (seperti mencari rute tercepat di aplikasi peta) atau memproses gambar dan permainan video secara efisien.