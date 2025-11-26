---
obsidianUIMode: preview
note_type: latihan
latihan: Binary Tree dari Array
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-27T15:14:00
---
---
Tentu, kita mulai dari soal pertama untuk latihan membangun **tree dari input array**. Soal pertama akan cukup dasar agar kamu bisa fokus memahami bagaimana proses pembentukan node dan koneksi antar node dilakukan.

---

# 🟢 Soal 1: Binary Tree dari Array Level-Order (Tanpa NULL)

**Deskripsi:**

Diberikan sebuah array bilangan bulat `arr[]` yang merepresentasikan **sebuah binary tree dalam urutan level-order traversal** (tingkat demi tingkat dari kiri ke kanan), buatlah fungsi untuk membangun tree tersebut.

Setiap elemen array merepresentasikan nilai dari satu node. **Anggap semua node valid** (tidak ada nilai `NULL` atau `-1`). Array akan selalu lengkap (tanpa lubang), dan panjang array selalu `n = 2^k - 1` untuk suatu `k`.

---

**Contoh Input:**

```cpp
arr = {1, 2, 3, 4, 5, 6, 7}
```

**Tree yang terbentuk:**

```

        1
      /   \
     2     3
    / \   / \
   4  5  6   7
   
```

---

**Tugas:**

1. Buatlah struktur `Node` yang sesuai.
    
2. Implementasikan fungsi `Node* buildTree(const vector<int>& arr)` yang membangun tree dari input tersebut.
    
3. Implementasikan fungsi untuk mencetak **inorder traversal** dari tree yang terbentuk, agar bisa digunakan untuk mengecek hasilnya.
    

---

Kalau kamu sudah siap mengerjakan atau butuh petunjuk awal, tinggal bilang ya!