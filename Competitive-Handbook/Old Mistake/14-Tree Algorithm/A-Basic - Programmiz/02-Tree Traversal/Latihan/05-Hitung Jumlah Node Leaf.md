---
obsidianUIMode: preview
note_type: latihan
latihan: Hitung Jumlah Node
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-25T23:42:00
---
---
Siap, langsung kita **gas ke Soal 5!** 😎  
Kali ini kita buat tantangan traversal yang **melibatkan perhitungan saat traversal**, bukan hanya cetak atau cari nilai. Fokus tetap di traversal, tapi kamu harus berpikir sedikit lebih dalam.

---

# Soal 5 – Hitung Jumlah Node Leaf dengan Inorder Traversal

Diberikan struktur pohon berikut:

```

        8
       / \
      3   10
     / \    \
    1   6    14
           /
         13
         
```

### 🎯 Tugasmu:

Gunakan **inorder traversal** untuk menghitung dan mengembalikan **jumlah node daun** (leaf node) pada pohon tersebut.

> 💡 _Node daun adalah node yang tidak memiliki anak kiri maupun anak kanan._

---

### ✅ Petunjuk:

- Buat fungsi rekursif `countLeaves(Node*)` yang menggunakan **inorder traversal**.
    
- Tidak harus mencetak node-nya, cukup mengembalikan jumlah node daun.
    
- Boleh tanpa variabel global (lebih baik).
    

---

Ayo, kirimkan solusi C++-nya! Setelah itu akan aku bantu buat editorial dan pembahasan lengkap seperti sebelumnya. 🚀

# Jawabanku
Berikut adalah jawabanku yang dibantu editorial:

```cpp
#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

int countLeaves(struct Node* node) {
    if (node == NULL) return 0;

    int count = 0;
    count += countLeaves(node->left);
    
    if (node->left == NULL && node->right == NULL) count++;

    count += countLeaves(node->right);
    return count;
}


int main() {
    struct Node *root = new Node(8);
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(6);

    root->right = new Node(10);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    cout << "Node leaf: ";
    cout << countLeaves(root);
    return 0;
}
```

# Editorial
Sempurna! 💯 Kamu sukses menyelesaikan tantangan traversal dengan logika yang tepat dan bersih — dan kamu juga sudah menggunakan pendekatan **tanpa variabel global**, sesuai best practice! 🔥  
Sekarang aku buatin lagi **editorial lengkap dan pembahasan sederhana** untuk Soal 5 agar kamu bisa salin langsung ke Obsidian.

---

## 🌳 Soal 5 – Hitung Jumlah Node Daun dengan Inorder Traversal

**Struktur pohon:**

```

        8
       / \
      3   10
     / \    \
    1   6    14
           /
         13
         
```

---

## ✅ Tujuan

Menggunakan **inorder traversal** untuk menghitung **jumlah node daun** dalam pohon.  
Node daun adalah node yang **tidak memiliki anak kiri maupun kanan**.

---

## 🧠 Konsep yang Diuji

- Traversal inorder (kiri → root → kanan)
    
- Deteksi kondisi node daun (tanpa anak kiri & kanan)
    
- Rekursi dengan akumulasi hasil
    
- Desain fungsi yang **mengembalikan hasil** (bukan hanya mencetak)
    

---

## 🧪 Evaluasi Kode

### Fungsi:

```cpp
int countLeaves(struct Node* node) {
    if (node == NULL) return 0;

    int count = 0;
    count += countLeaves(node->left);
    
    if (node->left == NULL && node->right == NULL)
        count++;

    count += countLeaves(node->right);
    return count;
}
```

### ✅ Analisis:

- Fungsi dipanggil rekursif ke subtree kiri
    
- Jika node saat ini tidak punya anak, maka dihitung sebagai daun
    
- Rekursif dilanjutkan ke subtree kanan
    
- Nilai dari kiri + tengah (jika daun) + kanan dijumlahkan
    

---

## 🔍 Traversal + Leaf Detection

Mari kita hitung daunnya berdasarkan traversal:

1. Kunjungi `1` → daun ✅
    
2. Kembali ke `3`, ke kanan: `6` → daun ✅
    
3. Kembali ke `8`, ke kanan → `10`, ke kanan → `14`, ke kiri → `13` → daun ✅
    

### ✅ Daun:

- `1`
    
- `6`
    
- `13`
    

### ❌ Bukan daun:

- `3`, `8`, `10`, `14` (masih punya anak)
    

---

## 🔢 Hasil Akhir:

```
Jumlah node daun = 3
```

---

## 💬 Kesimpulan

Kamu sudah memahami bagaimana **mengekstrak informasi penting dari traversal tree**, bukan hanya membaca urutan node. Ini membuka banyak kemampuan, seperti menghitung total node, tinggi pohon, bahkan validasi BST nanti.
