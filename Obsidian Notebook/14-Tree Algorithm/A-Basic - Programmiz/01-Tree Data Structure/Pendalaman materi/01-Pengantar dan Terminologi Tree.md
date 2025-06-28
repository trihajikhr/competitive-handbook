---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Pengantar dan Terminologi Tree
sumber: Google.com, AI
date_learned: 2025-06-27T14:56:00
tags:
  - tree-algorithm
---
Link Sumber: 

---
# Pengenalan Tree Algorithm

**Tujuan:** Memahami konsep dasar dan istilah-istilah umum pada struktur pohon (tree).

## Apa itu Tree?

- **Tree** adalah struktur data hierarkis yang terdiri dari **node**-node yang terhubung melalui **edge**.
    
- Satu node ditetapkan sebagai **root**, dan setiap node dapat memiliki nol atau lebih **child**.
    

## Terminologi Dasar

- **Root**: Node paling atas pada tree.
    
- **Node**: Elemen dasar yang berisi nilai/data dan pointer ke anak.
    
- **Child**: Node yang langsung berada di bawah node lain.
    
- **Parent**: Node yang menjadi induk dari child.
    
- **Leaf**: Node tanpa anak (child = NULL).
    
- **Subtree**: Pohon yang terbentuk dari satu node dan semua keturunannya.
    
- **Edge**: Koneksi antara dua node (parent ↔ child).
    

## Jenis-jenis Binary Tree

- **Binary Tree**: Setiap node memiliki paling banyak dua anak (left, right).
    
- **Full Binary Tree**: Setiap node selain leaf memiliki tepat dua anak.
    
- **Complete Binary Tree**: Semua level terisi penuh kecuali level terakhir, yang terisi dari kiri ke kanan.
    
- **Perfect Binary Tree**: Semua level terisi penuh, jumlah node = $2^{(h+1)}-1$.
    
- **Skewed Tree**: Semua node hanya memiliki satu anak (kiri atau kanan) — menyerupai linked list.
    

## Visualisasi Struktur Tree

```

       10            ← Root
      /  \
     5    20         ← Level 2
    / \   / \
   3   8 15  25      ← Level 3
   
```

- Tingkat (level) dihitung mulai dari root = level 1.
    
- Jarak (height): jumlah level maksimum.
    

## Relevansi Tree

- Digunakan pada pencarian (BST), representasi ekspresi (syntax tree), file system, dan banyak algoritma grafis.
    
