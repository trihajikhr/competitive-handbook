---
obsidianUIMode: preview
note_type: latihan
latihan: 13-Operasi Node Ganjil dengan Level dan X
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-26T18:52:00
---
---
Senang banget dengarnya! Semangatmu luar biasa 😄  
Ayo kita lanjut ke **Soal 13**, kali ini dengan filter ganda!

---

# Soal 13 – Jumlahkan Node Ganjil di Level Tertentu yang Lebih dari X

### 📋 Deskripsi

Diberikan sebuah **binary tree**, buatlah fungsi:

```cpp
int sumOddGreaterThanXAtLevel(Node* root, int level, int x);
```

yang akan **menjumlahkan semua node** pada **level ke-`level`** yang:

1. **Nilainya ganjil**, dan
    
2. **Lebih besar dari `x`**
    

---

### 📥 Input

- `root`: pointer ke root dari binary tree
    
- `level`: level target (mulai dari 1)
    
- `x`: bilangan bulat (batas bawah nilai node yang dihitung)
    

---

### 📤 Output

- Sebuah bilangan bulat: hasil penjumlahan nilai node yang memenuhi kedua syarat
    

---

### 💡 Contoh Struktur Pohon:

```

         15
        /   \
      7      22
     / \    /  \
    3  13  17  20
    
```

### Contoh:

- `level = 3`, `x = 10`  
    → node: `3, 13, 17, 20`  
    → ganjil dan >10: `13, 17`  
    → output: `13 + 17 = 30`
    

---

### ⚙️ Ketentuan

- Gunakan **rekursi per level**
    
- Tidak boleh pakai struktur data tambahan
    
- Tidak menggunakan variabel global
    
- Pastikan efisien dan readable
    
# Jawabanku
Berikut adalah jawabanku untuk menyelesaikan permasalah ini, yang sudah optimal dan efisien:

```cpp
#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *kiri, *kanan;
    Node(int data){
        this->data = data;
        kiri = kanan = NULL;
    }
};

int solve(struct Node*node, int lvl, int x){
    if(node == NULL) return 0;

    int sum=0;
    if((lvl==1 && node->data%2==1) && node->data > x){
        sum += node->data;
    }
    
    sum += solve(node->kiri, lvl-1, x);
    sum += solve(node->kanan, lvl-1, x);
    return sum;
}

int main() {
    struct Node* root = new Node(15);
    root->kiri = new Node(7);
    root->kiri->kiri = new Node(3);
    root->kiri->kanan = new Node(13);

    root->kanan = new Node(22);
    root->kanan->kanan = new Node(20);
    root->kanan->kiri = new Node(17);

    int l, x; cin >> l >> x;
    cout << "Jumlah node di level ke-" << l << " dengan lebih dari " << x 
    << " adalah: " << solve(root, l, x); 
    return 0;
}
```

# Editorial
🔥 **Brilian!**  
Kamu berhasil menyatukan **dua kondisi filter (ganjil dan lebih dari X)** dalam satu traversal yang tetap rapi dan efisien. Kamu juga menggunakan nama variabel yang bersih (`solve`, `lvl`, `x`) dan sudah cukup readable!

Sekarang aku bantu seperti biasa dengan **editorial lengkap dan profesional** untuk Soal 13:

---

## 🧩 Soal 13 – Jumlahkan Node Ganjil di Level Tertentu yang Lebih dari X

---

### 📘 Deskripsi

Diberikan sebuah binary tree dan bilangan bulat `x`, jumlahkan semua node pada level ke-`l` yang:

- Bernilai **ganjil**
    
- Dan **lebih besar dari `x`**
    

---

### ✅ Fungsi:

```cpp
int solve(struct Node* node, int lvl, int x){
    if(node == NULL) return 0;

    int sum = 0;
    if((lvl == 1 && node->data % 2 == 1) && node->data > x){
        sum += node->data;
    }

    sum += solve(node->kiri, lvl - 1, x);
    sum += solve(node->kanan, lvl - 1, x);
    return sum;
}
```

---

### 🌳 Contoh Struktur Pohon:

```

         15
        /   \
      7      22
     / \    /  \
    3  13  17  20
    
```

---

### 🎯 Contoh Uji:

- `level = 3`, `x = 10`  
    Node di level 3: `3, 13, 17, 20`  
    Ganjil dan >10: `13`, `17`  
    Output: `13 + 17 = 30`
    

---

## 🧠 Penjelasan Langkah Per Langkah

|Langkah|Penjelasan|
|---|---|
|`if (node == NULL)`|Base case traversal|
|`if (lvl == 1)`|Artinya kita sudah sampai di level target|
|`node->data % 2 == 1`|Filter nilai ganjil|
|`node->data > x`|Filter nilai lebih dari `x`|
|`sum += ...`|Tambahkan ke total jika memenuhi dua kondisi|
|Rekursi ke kiri dan kanan|Turun ke subtree dengan `level - 1`|

---

## ✅ Evaluasi

|Aspek|Status|
|---|---|
|Traversal berdasarkan level|✅|
|Penyaringan nilai dua kondisi|✅|
|Tidak ada variabel global|✅|
|Efisien dan modular|✅|
|Output sesuai spesifikasi|✅|

---

## 🏁 Kesimpulan

Kamu kini bisa:

- Menggabungkan **lebih dari satu syarat** dalam proses traversal
    
- Menulis fungsi rekursif yang **fleksibel dan bersih**
    
- Memanipulasi output traversal **berbasis properti** nilai node
    

Kemampuan ini akan sangat berguna dalam berbagai soal seperti:

- **Subtree processing**
    
- **Conditional traversal**
    
- **Penghitungan statistik custom pada level/tree tertentu**
    

---

Kalau sudah kamu salin editorialnya, beri tanda, dan kita bisa lanjut ke **Soal 14** dengan ide baru:  

🔹 _Cetak nilai node pada level tertentu yang merupakan **bilangan genap dan kelipatan 5**._

Masih semangat? 😄