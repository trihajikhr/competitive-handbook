---
obsidianUIMode: preview
note_type: latihan
latihan: Postorder Traversal
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-25T21:58:00
---
---
Gas lah! 😎🔥 Kamu lagi **on fire** banget ini — mumpung semangat, kita lanjut ke **Soal 3: Postorder Traversal**!

# Soal 3 – Postorder Traversal: Urutan Kunjungan

Diberikan struktur pohon biner berikut:

```

        7
       / \
      3   11
     / \    \
    1   5    15
    
```

### 🎯 Tugasmu:

Tentukan **urutan output** yang dihasilkan oleh **postorder traversal** dari pohon tersebut.  
Tidak perlu buat kode dulu — cukup kirim **urutan angka** hasil traversalnya.

> 💡 _Ingat: postorder = kiri → kanan → root_

---

Kalau sudah, langsung kirim jawabannya. Setelah itu aku bantu evaluasi dan lanjut editorial kayak biasa! 💪

## Jawabanku
Berikut adalah implementasi dari kode program kami:

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

void postorderTraversal(struct Node *node){
    if(node == NULL) return;

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " -> ";
}

int main() {
    struct Node * root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(11);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->right = new Node(15);

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    return 0;
}
```

## Editorial
Wuihh mantap! 🔥 Kamu langsung sikat dengan kode C++ lengkap — dan lagi-lagi **benar semua!** 💯  

Sekarang aku buatin **editorial dan pembahasan sederhana** untuk **Soal 3 – Postorder Traversal**. Silakan salin ke Obsidian kamu nanti ya.

---

**Struktur pohon:**

```

        7
       / \
      3   11
     / \    \
    1   5    15
    
```

---

### ✅ Tujuan

Lakukan **postorder traversal** terhadap pohon di atas, lalu tampilkan urutan node yang dikunjungi.

---

### 🧠 Konsep Postorder Traversal

Traversal postorder mengikuti urutan:

> **Left Subtree → Right Subtree → Root**

Artinya:

1. Telusuri subtree kiri sampai habis
    
2. Telusuri subtree kanan
    
3. Baru kunjungi node saat ini
    

---

### 🧩 Langkah Eksekusi

1. Mulai dari root (`7`)
    
2. Ke kiri: `3`
    
    - Ke kiri lagi: `1` → tampilkan `1`
        
    - Kembali ke `3`, ke kanan: `5` → tampilkan `5`
        
    - Selesai anak-anak `3` → tampilkan `3`
        
3. Kembali ke `7`, ke kanan: `11`
    
    - Ke kanan lagi: `15` → tampilkan `15`
        
    - Selesai anak-anak `11` → tampilkan `11`
        
4. Akhirnya tampilkan `7`
    

---

### 🔢 Hasil Akhir

```
1 -> 5 -> 3 -> 15 -> 11 -> 7 ->
```

---

### 🧪 Evaluasi Kode

Fungsinya seperti ini:

```cpp
void postorderTraversal(struct Node *node){
    if(node == NULL) return;

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " -> ";
}
```

✅ Sudah sangat benar karena:

- Urutan traversal sesuai postorder: kiri → kanan → root
    
- Fungsi rekursif berjalan dengan rapi
    
- Struktur pohon dibangun sesuai instruksi
    

---

### 💬 Kesimpulan

Kamu berhasil menyelesaikan **postorder traversal** secara **tepat dan rapi**. Ini menandakan kamu sudah menguasai **tiga traversal dasar** dengan sangat baik:

✅ Preorder  
✅ Inorder  
✅ Postorder
