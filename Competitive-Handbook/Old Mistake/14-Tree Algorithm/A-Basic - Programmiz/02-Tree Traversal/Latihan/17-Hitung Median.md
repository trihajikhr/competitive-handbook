---
obsidianUIMode: preview
note_type: latihan
latihan: itung Median Node pada Level Tertentu
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-26T20:39:00
---
---
🔥 Let's GOO ke **Soal 17 dari 20**!  
Masih dengan gaya traversal + pemrosesan data — tapi kali ini kamu harus **mengurutkan nilai node pada level tertentu** dan **mengambil nilai median**.

---

# Soal 17 – Hitung Median Node pada Level Tertentu

### 📋 Deskripsi

Diberikan sebuah binary tree dan level `l`, buat fungsi untuk **menghitung nilai median** dari semua node di **level ke-`l`**.

---

### 📥 Input

- Tree (dibentuk manual di `main`)
    
- Integer `l` (level ke berapa, dimulai dari 1)
    

---

### 📤 Output

- Median dari semua node di level ke-`l`, dalam bentuk:
    
    - Jika jumlah node ganjil → median adalah nilai tengah
        
    - Jika jumlah node genap → median adalah **rata-rata dua nilai tengah (float)**
        

---

### 🧠 Fungsi:

```cpp
double findMedianAtLevel(Node* root, int level);
```

---

### 💡 Contoh Pohon:

```

       10
     /    \
    5      15
   / \    /  \
  3   7  12   8
  
```

- Level 3 → node: `3, 7, 12, 8` → urut: `3, 7, 8, 12`  
    → median = (7 + 8)/2 = **7.5**
    
- Level 2 → node: `5, 15` → median = (5 + 15)/2 = **10.0**
    
- Level 1 → node: `10` → median = **10.0**
    

---

### ⚙️ Petunjuk

- Gunakan traversal untuk menyimpan node level-`l` ke `vector<int>`
    
- Urutkan vektor pakai `sort()`
    
- Hitung median berdasarkan ukuran vektor
    

---

Langsung kerjakan ya, dan seperti biasa aku bantu evaluasi & editorial begitu kamu submit! 😎

# Jawabanku
Berikut adalah jawabanku untuk menyelesaikan tantangan ini:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int data){
        this->data = data;
        left=right=NULL;
    }
};

void treeTravers(struct Node * node, int lvl, vector<int>&vec){
    if(node == NULL) return;

    treeTravers(node->left, lvl-1, vec);
    treeTravers(node->right, lvl-1, vec);
    if(lvl == 1){
        vec.push_back(node->data);
    }
}

float medianTree(struct Node * node, int lvl){
    vector<int> vec;
    treeTravers(node, lvl, vec);
    sort(vec.begin(), vec.end());

    float rest; int n = vec.size();
    if(n % 2==0){
        rest = static_cast<float>(vec[(n/2)-1]+vec[n/2])/2.0;
    } else {
        rest = vec[n/2];
    }

    return rest;
}

int main() {
    struct Node * root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(7);

    root->right = new Node(15);
    root->right->right = new Node(8);
    root->right->left = new Node(12);

    int l; cin >> l;
    cout << "Median tree di level ke-" << l << ": " 
    << medianTree(root, l) << endl;
    return 0;
}
```

# Editorial
🔥 **Kamu berhasil menyelesaikan Soal 17 dengan sangat baik!** 

Struktur kodenya bersih, traversalnya tepat, dan proses penghitungan median juga sudah akurat. Sekarang kita bedah seperti biasa agar bisa kamu catat di Obsidian:

---

### ✅ Fungsi Utama

```cpp
float medianTree(struct Node * node, int lvl){
    vector<int> vec;
    treeTravers(node, lvl, vec);
    sort(vec.begin(), vec.end());

    float rest; int n = vec.size();
    if(n % 2==0){
        rest = static_cast<float>(vec[(n/2)-1] + vec[n/2]) / 2.0;
    } else {
        rest = vec[n/2];
    }

    return rest;
}
```

---

### 🔍 Fungsi Pendukung

```cpp
void treeTravers(struct Node * node, int lvl, vector<int>&vec){
    if(node == NULL) return;

    treeTravers(node->left, lvl - 1, vec);
    treeTravers(node->right, lvl - 1, vec);

    if(lvl == 1){
        vec.push_back(node->data);
    }
}
```

---

### 🌳 Contoh Tree:

```

       10
     /    \
    5      15
   / \    /  \
  3   7  12   8
  
```

- Level 3: `3, 7, 12, 8` → sort → `3, 7, 8, 12`  
    → median = (7 + 8)/2 = **7.5**
    

---

### 🧠 Penjelasan:

|Langkah|Penjelasan|
|---|---|
|`treeTravers()`|Menyimpan nilai-nilai node di level `lvl`|
|`sort()`|Mengurutkan vector sebelum menghitung median|
|Median||

- Ganjil: ambil elemen tengah
    
- Genap: rata-rata 2 elemen tengah
    

---

## ✅ Evaluasi

|Aspek|Status|
|---|---|
|Traversal level + penyimpanan ke vector|✅|
|Pengurutan dan penghitungan median|✅|
|Penanganan genap–ganjil dengan tepat|✅|
|Casting untuk hasil float (bukan int)|✅|
|Output sesuai harapan|✅|

---

Kalau sudah kamu salin, langsung kita lanjut ke **Soal ke-18**, yang akan lebih interaktif lagi — kamu akan hitung **modus** alias nilai yang paling sering muncul! 🔢  
Siap? 😎