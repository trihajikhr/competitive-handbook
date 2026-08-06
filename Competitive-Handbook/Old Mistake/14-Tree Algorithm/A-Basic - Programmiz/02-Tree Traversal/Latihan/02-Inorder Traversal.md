---
obsidianUIMode: preview
note_type: latihan
latihan: Inorder Traversal
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-25T19:07:00
---
---
Mantap! 🔥 Saatnya lanjut ke **Soal 2: Inorder Traversal** — dengan pendekatan dan tantangan yang sedikit berbeda dari soal sebelumnya.

---

# Soal 2 – Inorder Traversal: Buat Program Lengkap

Diberikan struktur pohon berikut:

```

      1
     / \
    2   3
       /
      4
      
```

### 🎯 Tugasmu:

1. Bangun struktur pohon biner tersebut dalam program C++.
    
2. Buat dan panggil fungsi `inorderTraversal()` untuk menampilkan hasil traversalnya.
    

> 💡 _Ingat: inorder traversal adalah: kiri → root → kanan_

---

Kalau sudah selesai, kirimkan kodenya di sini. Setelah itu aku akan bantu beri **editorial + pembahasan lengkapnya** seperti sebelumnya 💪

## Jawabanku
Berikut adalah jawabanku untuk traversal versi Inorder Traversal:

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

void inorderTraversal(struct Node* node){
    if(node == NULL) return;

    inorderTraversal(node->left);
    cout << node->data << " -> ";
    inorderTraversal(node->right);
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    return 0;
}
```

## Editorial
Keren! 🎉 Kode kamu **sudah tepat dan sempurna** untuk menyelesaikan Soal 2 dengan metode **inorder traversal**. Sekarang aku buatkan kamu **editorial dan pembahasan lengkap** seperti sebelumnya — siap untuk dicatat di Obsidian 💻🧠

**Struktur pohon:**

```
      1
     / \
    2   3
       /
      4
```

---

### ✅ Tujuan

Lakukan **inorder traversal** terhadap pohon di atas, lalu tampilkan urutan node yang dikunjungi.

---

### 🧠 Konsep Inorder Traversal

Traversal inorder mengikuti urutan:

> **Left Subtree → Root → Right Subtree**

Artinya:

1. Telusuri ke anak kiri terlebih dahulu
    
2. Kunjungi node saat ini
    
3. Lanjutkan ke anak kanan
    

---

### 🧩 Langkah Eksekusi

Traversal pada pohon:

1. Mulai dari `1`, pergi ke kiri → `2`
    
2. `2` tidak punya anak → tampilkan `2`
    
3. Kembali ke `1` → tampilkan `1`
    
4. Ke kanan → `3`, ke kiri dulu → `4`
    
5. `4` tidak punya anak → tampilkan `4`
    
6. Kembali ke `3` → tampilkan `3`
    

---

### 🔢 Hasil Akhir

```
2 -> 1 -> 4 -> 3 ->
```

---

### 🧪 Evaluasi Kode

Kodenya seperti ini:

```cpp
void inorderTraversal(struct Node* node){
    if(node == NULL) return;

    inorderTraversal(node->left);
    cout << node->data << " -> ";
    inorderTraversal(node->right);
}
```

✅ Sangat tepat karena:

- Rekursi dijalankan lebih dulu ke kiri, baru cetak data, lalu ke kanan
    
- Ini sesuai dengan definisi traversal inorder
    
- Struktur pohon dibangun dengan benar sesuai soal
    

---

## 💬 Kesimpulan

Kamu sudah berhasil menyelesaikan **inorder traversal** dengan sangat baik, mulai dari membangun pohon sampai memprosesnya. Sekarang kamu telah memahami dua dari tiga traversal utama pohon. Satu lagi tinggal **postorder traversal**!
