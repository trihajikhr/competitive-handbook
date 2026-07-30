---
obsidianUIMode: preview
note_type: book theory
judul_materi: Jalur Hamiltonian dan Eulerian pada Grid Graphs
sumber:
  - myself
date_learned: 2026-07-30T18:38:00
tags:
  - graphs
  - grid-graphs
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Jalur Hamiltonian dan Eulerian pada Grid Graphs

## Pengantar

Setelah memahami struktur, topologi, dan sifat bipartit dari sebuah *grid graph*, aspek teoretis mendalam berikutnya berkaitan dengan keterhubungan global melalui lintasan tertentu. Dua konsep klasik dalam teori graf yang sering dikaji pada struktur grid adalah *Hamiltonian path* (atau sirkuit) dan *Eulerian path* (atau sirkuit). Keberadaan jalur-jalur ini pada *grid graph* sangat bergantung pada dimensi dan ukuran paritas dari grid tersebut.

## Jalur dan Sirkuit Hamiltonian

Sebuah *Hamiltonian path* adalah jalur di dalam graf yang mengunjungi setiap *vertex* tepat satu kali. Jika jalur tersebut berawal dan berakhir pada *vertex* yang sama sehingga membentuk sebuah siklus tertutup, maka struktur tersebut dinamakan *Hamiltonian cycle*.

Pada *grid graph* berukuran $n \times m$, eksistensi *Hamiltonian cycle* tunduk pada batasan paritas yang ketat karena sifat bipartit graf tersebut:

* Jika kedua dimensi $n$ dan $m$ bernilai genap, maka *grid graph* selalu memiliki *Hamiltonian cycle*. Hal ini dapat dibuktikan dengan mudah karena total jumlah simpul $nm$ bernilai genap, yang memungkinkan pembagian simpul secara seimbang antara himpunan bipartit $V_1$ dan $V_2$.
* Jika salah satu dari dimensi $n$ atau $m$ bernilai ganjil dan perkalian total simpul $nm$ juga bernilai ganjil, maka *grid graph* tidak akan pernah memiliki *Hamiltonian cycle*. Alasannya, dalam graf bipartit, setiap siklus harus memiliki panjang genap (beralternasi secara simetris antara kedua himpunan bipartit), sehingga tidak mungkin memuat semua simpul jika jumlah total simpulnya ganjil. Meskipun demikian, *Hamiltonian path* masih mungkin eksis jika salah satu dimensinya bernilai lebih besar dari satu.

## Jalur dan Sirkuit Eulerian

Berbeda dengan jalur Hamiltonian yang membatasi kunjungan pada *vertex*, *Eulerian path* adalah jejak di dalam graf yang melewati setiap *edge* tepat satu kali. Jika jalur tersebut kembali ke simpul awal, dinamakan *Eulerian circuit*.

Berdasarkan teorema Euler, sebuah graf memiliki *Eulerian circuit* jika dan hanya jika setiap *vertex* di dalam graf tersebut memiliki *degree* genap. Karakteristik ini memberikan implikasi langsung pada *grid graph*:

* Mengingat struktur *grid graph* selalu memiliki *vertex* sudut dengan *degree* 2, *vertex* tepi dengan *degree* 3, dan *vertex* interior dengan *degree* 4, selalu ada *vertex* yang memiliki *degree* ganjil (yaitu seluruh simpul tepi dan sudut).
* Karena terdapat *vertex* dengan *degree* ganjil, sebuah *grid graph* berukuran berhingga tidak akan pernah memiliki *Eulerian circuit*.
* Namun, *Eulerian path* (jalur yang tidak harus kembali ke titik awal) dapat eksis jika dan hanya jika jumlah *vertex* ber-*degree* ganjil di dalam graf tersebut tepat berjumlah nol atau dua. Pada *grid graph* standar, jumlah simpul ber-*degree* ganjil selalu lebih dari dua (seluruh simpul batas memiliki *degree* 3), sehingga *Eulerian path* secara umum tidak ditemukan pada *grid graph* dua dimensi standar kecuali dalam kasus khusus yang terdegenerasi (seperti *grid* berukuran $1 \times n$).

## Relevansi dalam Algoritma dan Komputasi

Pemahaman mengenai eksistensi jalur ini sangat krusial dalam berbagai domain komputasi:

* *Pathfinding* dan Eksplorasi: Menentukan batas kemampuan agen otonom untuk memindai seluruh petak tanpa redundansi.
* Pembuatan Labirin (*Maze Generation*): Pemanfaatan *spanning trees* pada grid sering kali dikaitkan dengan penelusuran jalur tanpa siklus untuk menghasilkan struktur labirin yang valid.