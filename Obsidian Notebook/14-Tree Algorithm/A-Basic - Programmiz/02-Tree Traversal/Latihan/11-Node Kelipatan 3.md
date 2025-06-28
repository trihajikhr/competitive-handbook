---
obsidianUIMode: preview
note_type: latihan
latihan: Node Kelipatan 3
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-26T18:20:00
---
---
Sip, kita lanjut ke **Soal 11** — sekarang waktunya kamu mengasah kemampuan **traversal + filtering kondisi khusus**.

---

# Soal 11 – Cetak Semua Node pada Level Tertentu yang Kelipatan 3

### 📋 Deskripsi

Diberikan sebuah **binary tree**, buatlah fungsi:

```cpp
void printMultiplesOf3(Node* root, int level);
```

yang akan **mencetak semua node di level ke-`level`** yang **merupakan kelipatan dari 3**.

---

### 📥 Input

- `root`: pointer ke root dari pohon
    
- `level`: level target (mulai dari 1 sebagai root)
    

---

### 📤 Output

Cetak nilai-nilai node pada level ke-`level` **yang habis dibagi 3**, pisahkan dengan spasi.

> Tidak perlu mencetak apapun jika tidak ada node yang memenuhi syarat.

---

### 💡 Contoh Struktur Pohon:

```

         12
        /   \
      7      18
     / \    /  \
    9   5  6   20
    
```

### Contoh:

- `level = 2` → node: `7, 18` → hanya `18` kelipatan 3 → output: `18`
    
- `level = 3` → node: `9, 5, 6, 20` → hanya `9, 6` kelipatan 3 → output: `9 6`
    

---

### ⚙️ Ketentuan

- Gunakan **rekursi**
    
- Jangan gunakan struktur data tambahan
    
- Jangan pakai variabel global
    
- Output hanya nilai-nilai kelipatan 3 di level yang diminta
    

---

Silakan langsung kerjakan dan kirim kode C++-nya. Setelah itu aku bantu evaluasi + editorial seperti biasa 😎

# Jawabanku
Berikut adalah jawabanku untuk menjawab tantangan ini:

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

void printMultiTree(struct Node * node, int l){
    if(node == NULL) return;

    if(l==1 && node->data%3==0){
        cout << node->data << " ";
    }
    printMultiTree(node->left, l-1);
    printMultiTree(node->right, l-1);
}

int main() {
    struct Node * root = new Node(12);
    root->left = new Node(7);
    root->right = new Node(18);
    root->left->left = new Node(9);
    root->left->right = new Node(5);

    root->right->right = new Node(20);
    root->right->left = new Node(6);

    int l; cin >> l;
    cout << "Kelipatan 3: ";
    printMultiTree(root, l);
    return 0;
}
```

# Editorial
💯 **Sangat bagus!**  
Kamu sudah bisa menggabungkan:

- traversal rekursif berdasarkan level
    
- pengecekan kondisi nilai (kelipatan 3)
    
- serta **output langsung tanpa menyimpan ke array/list**
    

Sekarang aku bantu buatkan **editorial lengkap untuk Soal 11**, siap kamu salin ke Obsidian:

---

## 🧩 Soal 11 – Cetak Semua Node pada Level Tertentu yang Kelipatan 3

---

### 📘 Deskripsi

Buat fungsi yang mencetak **semua node pada level `l`** dari sebuah binary tree **yang merupakan kelipatan dari 3**.

---

### ✅ Fungsi:

```cpp
void printMultiTree(struct Node * node, int l){
    if(node == NULL) return;

    if(l == 1 && node->data % 3 == 0){
        cout << node->data << " ";
    }

    printMultiTree(node->left, l - 1);
    printMultiTree(node->right, l - 1);
}
```

---

## 🌳 Struktur Contoh Pohon:

```

         12
        /   \
      7      18
     / \    /  \
    9   5  6   20
    
```

---

### 🎯 Contoh Pengujian:

|Input `l`|Node di level `l`|Kelipatan 3|Output|
|---|---|---|---|
|1|12|✅|12|
|2|7, 18|18|18|
|3|9, 5, 6, 20|9, 6|9 6|

---

### 🧠 Penjelasan Fungsi

|Baris|Penjelasan|
|---|---|
|`if (node == NULL)`|Hentikan jika node kosong|
|`if (l == 1)`|Kita sudah berada di level target|
|`node->data % 3 == 0`|Cek apakah nilai node kelipatan 3|
|`cout << node->data`|Cetak jika memenuhi syarat|
|Rekursi kiri dan kanan|Lanjutkan pencarian dengan level dikurangi 1|

---

### ✅ Evaluasi

|Aspek|Status|
|---|---|
|Traversal level-based|✅|
|Filtering nilai sesuai syarat|✅|
|Tidak gunakan struktur tambahan|✅|
|Clean code, modular|✅|
|Output sesuai harapan|✅|

---

### 🏁 Kesimpulan

Kamu sudah menunjukkan pemahaman mendalam tentang:

- Level traversal menggunakan rekursi
    
- Filtering berdasarkan kondisi nilai tertentu
    
- Teknik traversal tanpa menyimpan hasil
    

Ini adalah bekal kuat untuk topik-topik lanjutan seperti:

- View-based traversal (left/right/top view)
    
- Kondisional traversal
    
- Kustomisasi hasil traversal berdasarkan banyak aturan
    
