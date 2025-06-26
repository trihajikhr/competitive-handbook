---
obsidianUIMode: preview
note_type: latihan
latihan: Node pada Level Tertentu
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-26T09:38:00
---
---
# Soal 7 – Cetak Node pada Level Tertentu

### 📋 Deskripsi

Diberikan sebuah **binary tree** sebagai berikut:

```

         1
       /   \
      2     3
     / \   / \
    4   5 6   7
    
```

Buatlah sebuah fungsi dengan header berikut:

```cpp
void printLevel(Node* root, int level);
```

yang akan mencetak **semua node** yang berada tepat di **level ke-`level`** (dihitung mulai dari level 1 sebagai root).

---

### 📥 Input

- `root`: pointer ke root dari binary tree
    
- `level`: bilangan bulat positif (≥1) yang menunjukkan level target
    

---

### 📤 Output

Cetak nilai-nilai node pada level tersebut (jika ada), dipisahkan oleh spasi, dan diakhiri dengan newline.

---

### 💡 Contoh

Jika pohon seperti di atas dan:

- `level = 1` → output: `1`
    
- `level = 2` → output: `2 3`
    
- `level = 3` → output: `4 5 6 7`
    

---

### ⚙️ Batasan

- Gunakan **traversal berbasis rekursi**
    
- Tidak diperkenankan menggunakan struktur data tambahan (seperti `queue`, `vector`, `stack`, dll)
    

---

Kalau kamu sudah siap, kirimkan kode jawabannya dan aku bantu evaluasi serta buat editorial seperti sebelumnya 😎

# Jawabanku
Berikut adalah jawabanku:

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

void printLevel(Node* node, int level) {
    if (node == NULL) return;

    if (level == 1)
        cout << node->data << " ";
    else {
        printLevel(node->left, level - 1);
        printLevel(node->right, level - 1);
    }
}


int main() {
    struct Node * root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int l; cin >> l;
    cout << "Node di level ke " << l << ": ";
    printLevel(root, l);
    return 0;
}
```

# Editorial
Mantap! ✅ Jawaban kamu **benar secara konsep, struktur, dan implementasi**. Kamu telah menerapkan **rekursi murni untuk traversal berdasarkan level**, yang menunjukkan pemahaman yang sangat kuat.

Sekarang aku bantu kamu dengan **editorial dan pembahasan lengkap** untuk **Soal 7**, siap langsung dicatat ke Obsidian! 😎

---

## 🧩 Soal 7 – Cetak Node pada Level Tertentu

---

### 📘 Deskripsi Singkat

Cetak semua node yang berada tepat di **level ke-`l`** dalam pohon biner. Gunakan pendekatan rekursif, **tanpa menggunakan struktur data tambahan**.

---

### 🌳 Struktur Pohon Uji:

```

         1
       /   \
      2     3
     / \   / \
    4   5 6   7
    
```

---

### 🧠 Strategi Penyelesaian

Gunakan **recursive traversal** dengan ide dasar:

- Jika `level == 1`, berarti kita berada di level target → cetak nilai node
    
- Jika belum (`level > 1`), teruskan rekursi ke subtree kiri dan kanan dengan `level - 1`
    

---

### ✅ Implementasi Fungsi

```cpp
void printLevel(Node* node, int level) {
    if (node == NULL) return;

    if (level == 1)
        cout << node->data << " ";
    else {
        printLevel(node->left, level - 1);
        printLevel(node->right, level - 1);
    }
}
```

---

### 🔍 Penjelasan Per Baris

|Kode|Penjelasan|
|---|---|
|`if (node == NULL)`|Cegah traversing ke node kosong|
|`if (level == 1)`|Basis: kita sudah sampai di level yang diminta|
|`cout << node->data << " "`|Cetak nilai node|
|Rekursi kiri & kanan|Pindah ke level berikutnya dengan `level-1`|

---

### 💡 Contoh Input & Output:

Misal input:

```
3
```

Berarti kamu ingin mencetak node di level ke-3.

Output:

```
Node di level ke 3: 4 5 6 7
```

---

### 🎯 Evaluasi

|Aspek|Status|
|---|---|
|Rekursi digunakan dengan benar|✅|
|Tanpa struktur tambahan|✅|
|Output sesuai dengan urutan dari kiri ke kanan|✅|
|Penanganan input dan output rapi|✅|

---

### ✅ Kesimpulan

Kamu sudah berhasil:

- Menerapkan rekursi untuk traversal berbasis kedalaman
    
- Memahami logika pemangkasan level
    
- Menjaga kode tetap bersih dan efisien
    

Soal ini adalah pondasi untuk memahami **level order traversal**, **height of tree**, dan **banyak operasi pohon lainnya** ke depan.
