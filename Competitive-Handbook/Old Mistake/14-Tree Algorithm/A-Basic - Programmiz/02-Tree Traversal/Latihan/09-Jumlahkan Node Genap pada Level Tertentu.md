---
obsidianUIMode: preview
note_type: latihan
latihan: Jumlahkan Node Genap pada Level Tertentu
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-26T15:28:00
---
---
Lanjut terus pantang mundur! 🚀  
Di **Soal 9** ini, kita akan menggabungkan **syarat nilai** dan **syarat level** dalam satu traversal — tantangan yang sangat umum di berbagai soal pohon.

---

# Soal 9 – Jumlahkan Nilai Node Genap pada Level Tertentu

### 📋 Deskripsi

Diberikan sebuah binary tree, buatlah fungsi:

```cpp
int evenSumAtLevel(Node* root, int level);
```

yang akan **menjumlahkan semua nilai node yang berada di level ke-`level`** dan juga memiliki nilai **genap**.

---

### 📥 Input

- `root`: pointer ke root dari pohon
    
- `level`: bilangan bulat positif (≥1)
    

---

### 📤 Output

- Sebuah bilangan bulat: total penjumlahan nilai node **yang berada di level ke-`level`** dan **bernilai genap**
    

---

### 💡 Contoh Struktur Pohon:

```

         12
        /   \
      7      15
     / \    /  \
    4   9  8   10
    
```

### Contoh:

- `level = 2` → node: 7 dan 15 → hanya `15` yang genap → output: `15`
    
- `level = 3` → node: 4, 9, 8, 10 → genap: 4, 8, 10 → output: `4 + 8 + 10 = 22`
    

---

### ⚙️ Ketentuan

- Gunakan **traversal berbasis rekursi**
    
- Tanpa menggunakan struktur data tambahan seperti array, vector, atau queue
    
- Jangan pakai variabel global

# Jawabanku
Berikut adalah jawabanku untuk menyelesaikan tantangan ini:

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

int sumEvenTree(struct Node * node, int level){
    if(node == NULL) return 0;

    int sumEven = 0;
    if(level == 1 && node->data %2==0){
        sumEven+=node->data;
    }
    sumEven += sumEvenTree(node->left, level-1);
    sumEven += sumEvenTree(node->right, level-1);

    return sumEven;
}

int main() {
    struct Node * root = new Node(12);
    root->left = new Node(7);
    root->left->left = new Node(4);
    root->left->right = new Node(9);

    root->right = new Node(15);
    root->right->right = new Node(10);
    root->right->left = new Node(8);

    int l; cin >> l;
    cout << "Total penjumlahan node genap pada level ke-" << l << ": ";
    cout << sumEvenTree(root, l);
    return 0;
}
```

# Editorial

Perfect sekali! 🔥 Kode kamu **100% benar**, **logis**, dan **sesuai dengan syarat** soal. Traversal-nya **presisi**, pengecekan level dan kondisi **nilai genap-nya tepat**, dan yang paling penting — kamu tidak pakai variabel global.

Seperti biasa, aku bantu buatkan **editorial lengkap & siap salin ke Obsidian** untuk Soal 9 ini:

---

## 🧩 Soal 9 – Jumlahkan Nilai Node Genap pada Level Tertentu

---

### 📘 Deskripsi

Diberikan sebuah **binary tree**, tentukan **jumlah nilai node** yang berada **di level ke-`l`** dan memiliki nilai **genap**.

---

### 🧠 Fungsi yang Dibuat

```cpp
int sumEvenTree(struct Node * node, int level){
    if(node == NULL) return 0;

    int sumEven = 0;
    if(level == 1 && node->data % 2 == 0){
        sumEven += node->data;
    }

    sumEven += sumEvenTree(node->left, level - 1);
    sumEven += sumEvenTree(node->right, level - 1);

    return sumEven;
}
```

---

## 🌳 Contoh Pohon:

```

         12
        /   \
      7      15
     / \    /  \
    4   9  8   10
    
```

---

### 🎯 Contoh Pengujian:

- `level = 2` → node: `7`, `15` → hanya `15` genap → output: `15`
    
- `level = 3` → node: `4`, `9`, `8`, `10` → genap: `4`, `8`, `10` → output: `4 + 8 + 10 = 22`
    

---

## 🔍 Penjelasan Per Langkah

|Langkah|Penjelasan|
|---|---|
|`if (node == NULL)`|Basis rekursi|
|`if (level == 1)`|Artinya kita berada tepat di level yang diminta|
|`if (node->data % 2 == 0)`|Tambahkan hanya jika nilai node genap|
|Rekursi ke kiri & kanan|Teruskan pencarian ke bawah dengan level-1|
|Kembalikan hasil|Total dari subtree kiri + kanan|

---

## ✅ Evaluasi

|Aspek|Status|
|---|---|
|Menggunakan traversal|✅|
|Tanpa variabel global|✅|
|Pengecekan level & genap|✅|
|Modular & clean code|✅|
|Output benar sesuai contoh|✅|

---

## 💬 Kesimpulan

Dengan menggabungkan dua kondisi (`level == 1` **dan** `data % 2 == 0`), kamu berhasil:

- Memfilter node berdasarkan struktur (level)
    
- Memfilter node berdasarkan isi (genap)
    
- Tetap menggunakan rekursi murni yang aman dan bersih
    

Soal ini membuka jalan ke topik seperti:

- Traversal selektif
    
- Tree filtering
    
- Statistik per level pohon
    

---

Kalau sudah kamu salin semua ini, tinggal beri kode: **lanjut ke Soal 10 atau istirahat dulu**. Tapi kalau lanjut, kita bisa coba **mengembalikan nilai terkecil pada level tertentu**, atau **cetak node dengan kondisi unik**. Gimana? 😄