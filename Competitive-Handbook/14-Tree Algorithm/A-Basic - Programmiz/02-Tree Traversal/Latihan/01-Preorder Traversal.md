---
obsidianUIMode: preview
note_type: latihan
latihan: Preorder Traversal – Menyusun Output
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-25T18:54:00
---
---
Mantap! 🔥 Saatnya masuk ke sesi latihan khusus traversal tree! Soal-soalnya akan aku susun **satu per satu**, dan setiap soal akan fokus ke salah satu metode traversal: **inorder**, **preorder**, atau **postorder**, bergantian supaya kamu makin paham bedanya.

---
# 🧩 Soal 1: Preorder Traversal – Menyusun Output

Diberikan struktur pohon biner berikut:

```

       10
      /  \
     20   30
    / \
   40 50
   
```

Tuliskan **urutan output** yang dihasilkan oleh **preorder traversal** dari pohon tersebut.

> 💡 _Ingat: preorder = kunjungi root, lalu subtree kiri, lalu subtree kanan._

---

Kalau sudah siap, kirim jawabannya, lalu kita lanjut ke soal ke-2 dengan traversal yang berbeda! 😄

## Jawabanku
Berikut adalah jawabanku mengimplementasikan tree algorithm dan menggunakan preorder traversal pertama kali. Masih tidak percaya ternyata aku bisa haha:

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

void preorderTraversal(struct Node * node){
    if(node == NULL) return;
    
    cout << node->data << " -> ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

int main() {
    struct Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    cout << "Preorder Traversal: \n";
    preorderTraversal(root);
    return 0;
}
```

## Editorial

**Struktur pohon:**

```

       10
      /  \
     20   30
    / \
   40 50
   
```

---

### ✅ Tujuan

Lakukan **preorder traversal** terhadap pohon di atas, lalu tampilkan urutan node yang dikunjungi.

---

### 🧠 Konsep Preorder Traversal

Traversal preorder mengikuti urutan:

> **Root → Left Subtree → Right Subtree**

Artinya:

1. Kunjungi node saat ini (root)
    
2. Traversal ke anak kiri
    
3. Traversal ke anak kanan
    

---

### 🧩 Langkah Eksekusi

Jalankan langkah traversal pada pohon di soal:

1. Mulai dari `10` (root) → tampilkan
    
2. Ke kiri (`20`) → tampilkan
    
3. Ke kiri (`40`) → tampilkan
    
4. `40` tidak punya anak → kembali ke `20`
    
5. Ke kanan (`50`) → tampilkan
    
6. Kembali ke `10`, ke kanan (`30`) → tampilkan
    

---

### 🔢 Hasil Akhir

```
10 -> 20 -> 40 -> 50 -> 30 ->
```

---

### 🧪 Evaluasi Kode

Kodenya seperti ini:

```cpp
void preorderTraversal(struct Node * node){
    if(node == NULL) return;
    
    cout << node->data << " -> ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}
```

✅ Sudah sangat tepat karena:

- Fungsi rekursifnya berjalan sesuai urutan preorder
    
- Kondisi `if(node == NULL)` menangani kasus basis
    
- Fungsi dipanggil berturut-turut untuk anak kiri lalu anak kanan
    

---

### 💬 Kesimpulan

Kamu sudah berhasil menerapkan **preorder traversal** dengan benar, baik dalam **pemahaman konsep traversal** maupun **implementasi kodenya**. Ini pondasi penting untuk masuk ke traversal lain seperti inorder dan postorder.
