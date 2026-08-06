---
obsidianUIMode: preview
note_type: book theory
judul_materi: Karakteristik Topologi dan Derajat Simpul
sumber:
  - myself
date_learned: 2026-07-30T18:30:00
tags:
  - graphs
  - grid-graphs
---
Link Sumber: 

---

> [!IMPORTANT]
>  

# Karakteristik Topologi dan Derajat Simpul

## Pengantar

Setelah memahami definisi dasar, langkah selanjutnya adalah mengenali sifat topologi dari sebuah *grid graph*. Karakteristik utama yang membedakan *grid graph* dari graf arbitrer lainnya adalah tingkat keteraturan yang tinggi pada setiap simpulnya. Keteraturan ini ditentukan oleh posisi geografis simpul tersebut di dalam grid.

## Klasifikasi Simpul Berdasarkan Posisi

Dalam sebuah *grid graph* berukuran dua dimensi, tidak semua simpul memiliki jumlah tetangga yang sama. Berdasarkan letaknya, simpul-simpul dapat diklasifikasikan ke dalam tiga kategori utama:

* **Simpul Sudut (*Corner Nodes*)**: Simpul yang berada tepat di keempat pojok grid. Simpul ini hanya memiliki dua tetangga (satu secara horizontal dan satu secara vertikal). Derajat simpul (*degree*) untuk kelompok ini adalah $2$.
* **Simpul Tepi (*Boundary / Edge Nodes*)**: Simpul yang terletak di sepanjang garis batas terluar grid tetapi bukan di sudut. Simpul ini memiliki tiga tetangga (dua menyusuri garis tepi dan satu masuk ke arah interior). Derajat simpul untuk kelompok ini adalah $3$.
* **Simpul Interior (*Internal Nodes*)**: Simpul yang berada di bagian dalam grid dan tidak bersentuhan langsung dengan batas luar. Simpul ini memiliki empat tetangga lengkap (atas, bawah, kiri, dan kanan). Derajat simpul untuk kelompok ini adalah $4$.

## Distribusi Derajat Simpul

Keteraturan struktur ini menghasilkan pola distribusi derajat yang tetap pada setiap ukuran grid berukuran $n \times m$ (dengan $n$ baris dan $m$ kolom, di mana $n, m \ge 2$):

* Jumlah simpul sudut selalu tepat 4 buah.
* Jumlah simpul tepi dihitung melalui formula $2(n - 2) + 2(m - 2) = 2n + 2m - 8$.
* Jumlah simpul interior dihitung melalui formula $(n - 2)(m - 2) = nm - 2n - 2m + 4$.

Jumlah keseluruhan derajat dari seluruh simpul dalam graf selalu memenuhi teorema *Handshaking Lemma*, yaitu dua kali jumlah sisi:


$$\sum_{v \in V} \text{deg}(v) = 2\vert{}E\vert{}$$

## Ukuran dan Kompleksitas Skala

Jumlah total elemen dalam sebuah *grid graph* bertambah secara kuadratik seiring dengan bertambahnya dimensi ukuran baris dan kolom. Untuk grid berukuran $n \times m$:

* Total *vertices* ($\vert{}V\vert{}) = nm$
* Total *edges* ($\vert{}E\vert{}) = 2nm - n - m$