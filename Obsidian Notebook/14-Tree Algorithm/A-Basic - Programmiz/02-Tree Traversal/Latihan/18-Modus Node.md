---
obsidianUIMode: preview
note_type: latihan
latihan: Modus Node
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-26T21:13:00
---
---
🔥 Nice! Kita langsung ke **Soal 18 dari 20**  

Kali ini kamu akan bermain dengan **frekuensi**. Traversal + simpan nilai, lalu temukan **modus (nilai yang paling sering muncul)** di level tertentu.

---

# Soal 18 – Temukan Modus Node pada Level Tertentu

---

### 📋 Deskripsi

Diberikan sebuah binary tree dan integer `l`, tentukan **nilai yang paling sering muncul** (modus) pada **level ke-`l`**.

---

### 📥 Input

- Tree (dibentuk manual di `main`)
    
- Integer `l` (level ke-`l`, dimulai dari 1)
    

---

### 📤 Output

- Nilai **modus** dari node di level ke-`l`
    
- Jika terdapat lebih dari satu nilai dengan frekuensi yang sama, **cetak nilai terkecil di antara mereka**
    

---

### 🧠 Fungsi:

```cpp
int findModeAtLevel(Node* root, int level);
```

---

### 💡 Contoh:

Misal Tree:

```

       10
     /    \
   7       7
  / \     /  \
 3   9   3    9
 
```

- level = 3 → node = `3, 9, 3, 9`  
    → 3 muncul 2x, 9 muncul 2x  
    → Jawaban = **3** (karena lebih kecil)
    

---

### ⚙️ Petunjuk

- Gunakan `map<int, int>` untuk menyimpan frekuensi
    
- Traversal sampai level `l` dan masukkan node ke map
    
- Ambil nilai dengan frekuensi tertinggi, dan jika ada yang sama, ambil nilai terkecil
    

---

Langsung coba kerjakan ya! Nanti aku bantu evaluasi & editorial lengkap seperti biasa 🔥

# Jawaban
Berikut adalah jawabanku yang sudah tepat:

```cpp
#include<iostream>
#include<map>
#include<iterator>
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

void treeTravers(struct Node * node, int lvl, map<int, int>& dasmap){
    if(node == NULL) return;

    treeTravers(node->left, lvl-1, dasmap);
    treeTravers(node->right, lvl-1, dasmap);
    
    if(lvl == 1){
        dasmap[node->data]++;
    }
}

int treeModus(struct Node * node, int lvl){
    map<int, int> dasmap;
    treeTravers(node, lvl, dasmap);

    int maks=INT_MIN, rest;
    map<int, int>::iterator iter;
    for(iter = dasmap.begin(); iter != dasmap.end(); iter++){
        if(iter->second > maks){
            maks= iter->second;
            rest = iter->first;
        }
    }
    
    return rest;
}

int main() {
    struct Node * root = new Node(10);
    root->left = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(9);

    root->right = new Node(7);
    root->right->left = new Node(3);
    root->right->right = new Node(9);

    int l; cin >> l;
    cout << "Nilai Modus dari Tree di level ke-" << l << ": " 
    << treeModus(root, l) << endl;
    return 0;
}
```

# Editorial
🔥 **Luar biasa! Jawabanmu untuk Soal 18 sudah sangat tepat!**  

Kamu berhasil menggabungkan traversal, penggunaan `map` untuk frekuensi, dan pengambilan nilai minimum saat frekuensinya sama. Mari kita bedah editorial profesional seperti biasa:

---

### ✅ Fungsi Utama

```cpp
int treeModus(struct Node * node, int lvl){
    map<int, int> dasmap;
    treeTravers(node, lvl, dasmap);

    int maks = INT_MIN, rest;
    for(auto iter = dasmap.begin(); iter != dasmap.end(); iter++){
        if(iter->second > maks){
            maks = iter->second;
            rest = iter->first;
        }
    }
    return rest;
}
```

---

### 🔍 Fungsi Pendukung

```cpp
void treeTravers(struct Node * node, int lvl, map<int, int>& dasmap){
    if(node == NULL) return;

    treeTravers(node->left, lvl - 1, dasmap);
    treeTravers(node->right, lvl - 1, dasmap);

    if(lvl == 1){
        dasmap[node->data]++;
    }
}
```

---

### 🌳 Contoh Tree:

```

       10
     /    \
    7       7
   / \     / \
  3   9   3   9
  
```

- Level 3: `3, 9, 3, 9`  
    → Frekuensi: `{3: 2, 9: 2}`  
    → Dua nilai sama frekuensi, ambil yang lebih kecil → **3**
    

---

### 🧠 Penjelasan:

|Langkah|Penjelasan|
|---|---|
|`treeTravers()`|Menyimpan semua node di level ke-`l` ke dalam `map<int, int>` sebagai frekuensi|
|Perhitungan|Iterasi seluruh map dan cari nilai dengan frekuensi terbesar|
|Tie breaker|Karena `map` disusun terurut, jika ada frekuensi sama maka yang lebih kecil akan tetap disimpan sebagai `rest` terlebih dulu|

---

## ✅ Evaluasi

|Aspek|Status|
|---|---|
|Traversal sesuai level|✅|
|Penyimpanan frekuensi pakai `map`|✅|
|Penanganan multiple modus → pilih terkecil|✅|
|Output sesuai format dan hasil|✅|

---

### ⚡ Catatan Tambahan

Kalau kamu nanti pakai `unordered_map`, kamu perlu manual mencari nilai terkecil saat frekuensi sama. Tapi `map` otomatis mengurutkan, jadi solusi kamu **sangat efisien untuk kebutuhan ini** 👌

---

Kalau sudah kamu salin ke catatan, langsung lanjut ke **Soal 19**, tantangannya lebih seru: kita akan hitung **rerata (mean)** node pada level tertentu, dalam format `float` yang rapi! 🚀