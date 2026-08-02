---
obsidianUIMode: preview
note_type: book theory
judul_materi: Definisi Formal dan Konstruksi Matematika
sumber:
  - myself
date_learned: 2026-07-30T18:16:00
tags:
  - graphs
  - grid-graphs
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Definisi Formal dan Konstruksi Matematika

## Pengantar

Grid graph adalah salah satu struktur graf yang paling sering ditemui dalam matematika diskret, ilmu komputer teoretis, serta bidang komputasi seperti *competitive programming* dan pemodelan spasial. Secara intuitif, graf ini menyerupai papan catur atau kisi-kisi kertas berpetak, di mana setiap titik persimpangan merepresentasikan sebuah *vertex* dan setiap ruas garis di antaranya merepresentasikan sebuah *edge*.

## Definisi Formal

Secara formal, sebuah *grid graph* dua dimensi (sering juga disebut sebagai *lattice graph* atau *mesh*) dapat didefinisikan secara aljabar melalui operasi *Cartesian product* dari dua buah *path graphs*.

Misalkan $P_n$ adalah sebuah *path graph* yang memiliki $n$ *vertices* dan $P_m$ adalah *path graph* dengan $m$ *vertices*. *Grid graph* $G$ berukuran $n \times m$ didefinisikan sebagai *Cartesian product*:


$$G = P_n \square P_m$$

Himpunan *vertices* ($V$) dari graf ini merupakan hasil kali Cartesian dari himpunan simpul kedua *path graph*:


$$V(G) = V(P_n) \times V(P_m) = \{(u, v) \mid 1 \le u \le n, 1 \le v \le m\}$$

Dua *vertices* $(u_1, v_1)$ dan $(u_2, v_2)$ terhubung oleh sebuah *edge* jika dan hanya jika jarak Euclidean di antara keduanya bernilai tepat 1. Secara matematis, kondisi kedekatan ini dapat dituliskan sebagai:


$$\vert{}u_1 - u_2\vert{} + \vert{}v_1 - v_2\vert{} = 1$$


Artinya, dua simpul terhubung jika keduanya berada pada baris yang sama dengan kolom yang bersisian, atau pada kolom yang sama dengan baris yang bersisian.

## Komponen Pembentuk

Komponen dasar dari struktur ini terdiri dari dua elemen utama:

* Vertices: Merepresentasikan titik-titik koordinat diskret pada bidang dua dimensi. Total jumlah simpul dalam *grid graph* berukuran $n \times m$ adalah $\vert{}V\vert{} = nm$.
* Edges: Merepresentasikan hubungan ketetanggaan secara ortogonal (atas, bawah, kiri, kanan). Total jumlah sisi pada *grid graph* terhingga dihitung melalui formula:

$$\vert{}E\vert{} = 2nm - n - m$$



## Generalisasi Bentuk

Struktur grid graph dapat diperluas ke dalam berbagai dimensi dan variasi topologi:

* Grid N-Dimensi: Konsep produk Cartesian dapat diperluas untuk $k$ dimensi, dinotasikan sebagai $P_{n_1} \square P_{n_2} \square \dots \square P_{n_k}$, yang sering digunakan dalam ruang pencarian multi-variabel.
* Toroidal Grid (Mesh): Variasi di mana simpul-simpul pada batas tepi ($1$ dan $n$) saling dihubungkan kembali, menghilangkan efek batas (*boundary*) dan membentuk permukaan torus secara topologis.