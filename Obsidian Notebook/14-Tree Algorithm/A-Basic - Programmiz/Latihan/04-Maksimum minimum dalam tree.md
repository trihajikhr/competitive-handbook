---
obsidianUIMode: preview
note_type: latihan
latihan: Maksimum minimum dalam tree
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-25T22:08:00
---
---
Mantap! 🔥 Sekarang kita naik level sedikit 💪 — soal-soalnya mulai menguji **pemahaman traversal secara mendalam**, bukan hanya baca urutan, tapi **menebak struktur pohon** dari urutan traversalnya, atau **mengolah datanya saat traversal**.

---

# Soal 4 – Temukan Nilai Maksimum dengan Postorder Traversal

Diberikan struktur pohon biner berikut:

```

       10
      /  \
     4    18
    / \     \
   1   9     21
   
```

### 🎯 Tugasmu:

Gunakan **postorder traversal** untuk mencari dan mencetak **nilai maksimum** di pohon tersebut.

> 💡 _Jangan langsung pakai fungsi `max()` atau `max_element()` pada list manual. Buat traversal-nya dan temukan maksimum sambil berjalan melalui tree!_

---

Silakan buat kodenya dalam C++ seperti biasa. Setelah itu, aku akan bantu berikan **editorial dan penilaian detail**! 😎

## Jawabanku
### Versi Mandiri
Berikut adalah jawabanku untuk menjawab soal ini, yang sebenarnya masih bisa ditingkatkan lagi dari saran yang diberikan editorial:

```cpp
#include<iostream>
#include<climits>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

int maks = INT_MIN;
void postorderTraversal(struct Node *node){
    if(node == NULL) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);

    if(node->data > maks){
        maks = node->data;
    }
}

int main() {
    struct Node * root = new Node(10);
    root->left = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(9);

    root->right = new Node(18);
    root->right->right = new Node(21);

    postorderTraversal(root);
    cout << "Nilai maks: " << maks << "\n";

    return 0;
}
```

### Jawaban yang lebih baik
Jawaban ini lebih baik, karena tidak menggunakan variabel global seperti pada versi jawaban pertama. Fungsi yang dibuat mentraversal sekaligus mencari nilai terbesar diantara node tree. Berikut conoth implementasinnya:

```cpp
#include<iostream>
#include<climits>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

int findMax(struct Node* node) {
    if (node == NULL) return INT_MIN;

    int leftMax = findMax(node->left);
    int rightMax = findMax(node->right);

    return max(node->data, max(leftMax, rightMax));
}

int main() {
    struct Node * root = new Node(10);
    root->left = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(9);
    root->right = new Node(18);
    root->right->right = new Node(21);

    int maks = findMax(root);
    cout << "Nilai maks: " << maks << "\n";
    return 0;
}
```

# Editorial
Keren banget! 🔥 Kamu udah ngerti cara **mengolah data sambil traversal** — itu level lanjut dalam memahami tree traversal. Sekarang aku buatkan **editorial lengkap dan pembahasan sederhana** buat Soal 4 agar bisa langsung kamu salin ke Obsidian.

---

## Editorial jawaban pertama

**Struktur pohon:**

```

       10
      /  \
     4    18
    / \     \
   1   9     21
   
```

---

### ✅ Tujuan

Gunakan **postorder traversal** untuk mengunjungi semua node dan tentukan **nilai maksimum** di seluruh pohon.

---

### 🧠 Konsep yang Diuji

- Traversal **postorder** (kiri → kanan → root)
    
- Melakukan **operasi saat traversal** (bukan sekadar mencetak)
    
- Menyimpan dan memperbarui nilai maksimum saat menjelajah node
    

---

### 🧪 Evaluasi Kode

### Fungsi:

```cpp
int maks = INT_MIN;
void postorderTraversal(struct Node *node){
    if(node == NULL) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);

    if(node->data > maks){
        maks = node->data;
    }
}
```

### ✅ Analisis:

- Traversal dilakukan sesuai urutan **postorder**
    
- Variabel global `maks` digunakan untuk menyimpan nilai terbesar
    
- Setiap node dibandingkan dengan `maks` dan diperbarui jika perlu
    
- Nilai awal `maks` adalah `INT_MIN` agar semua nilai pasti lebih besar dari itu
    

### 🔢 Hasil Traversal (postorder)

Traversal:

1. `1`, `9`, `4`
    
2. `21`, `18`
    
3. `10`
    

Node yang dikunjungi:

```
1 -> 9 -> 4 -> 21 -> 18 -> 10
```

Nilai maksimum = **21**

---

### 💬 Kesimpulan

Kamu berhasil menggunakan traversal sebagai **alat untuk menganalisis data**, bukan hanya membaca struktur. Ini langkah penting untuk menyelesaikan masalah-masalah berbasis pohon ke depannya. Hanya perlu hati-hati di bagian **struktur pohon** agar tidak menimpa node!

## Editorial jawaban kedua

> apakah mungkin untuk traversalnya  langsung mencari nilai maks dan mengembalikan nilanya? Tidak menggunakan variabel global?

Pertanyaan yang sangat **cerdas dan matang secara teknis!** 💡  
Jawabannya: **Ya, sangat mungkin** — dan justru itu adalah pendekatan yang **lebih baik dan lebih bersih**, karena:

✅ Tidak pakai **variabel global**  
✅ Fungsi menjadi **murni (pure function)**  
✅ Lebih aman untuk **pemrograman modular dan rekursif**

---

### 🔧 Cara Melakukannya:

Ubah fungsi `postorderTraversal()` menjadi fungsi **yang mengembalikan nilai maksimum** dari subtree yang sedang diproses.

---

### ✅ Versi Tanpa Variabel Global:

```cpp
int findMax(struct Node* node) {
    if (node == NULL) return INT_MIN;

    int leftMax = findMax(node->left);
    int rightMax = findMax(node->right);

    return max(node->data, max(leftMax, rightMax));
}
```

### 🧪 Penjelasan:

- Fungsi memanggil dirinya sendiri secara rekursif ke kiri dan kanan.
    
- Mengambil **maksimum** dari ketiga nilai:
    
    - Nilai saat ini (`node->data`)
        
    - Maksimum dari subtree kiri
        
    - Maksimum dari subtree kanan
        
- Fungsi akan terus mengembalikan nilai maksimum naik ke atas, hingga akhirnya kita mendapat maksimum dari seluruh pohon.
    

---

### 📌 Pemakaian di `main()`:

```cpp
int main() {
    struct Node * root = new Node(10);
    root->left = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(9);
    root->right = new Node(18);
    root->right->right = new Node(21);

    int maks = findMax(root);
    cout << "Nilai maks: " << maks << "\n";
    return 0;
}
```

---

### 💬 Keunggulan Pendekatan Ini:

|Pendekatan|Kelebihan|
|---|---|
|Tanpa variabel global|Fungsi jadi modular dan lebih mudah diuji|
|Rekursif murni|Tidak ada efek samping, aman di berbagai skenario|
|Cocok untuk interview / clean code|Ini yang sering dicari di pengujian teknis|
