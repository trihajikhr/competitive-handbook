---
obsidianUIMode: preview
note_type: latihan
latihan: Pasangan dengan Jumlah X
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-26T20:19:00
---
---
Mantap banget! 💪  
Kita lanjut ke **5 soal tambahan** (nomor 16–20) dengan pendekatan yang kamu suka:  
➡️ Traversal + penyimpanan data ke dalam struktur data (biasanya `vector`, `queue`, `stack`, `set`, dll), lalu **diolah sesuai permintaan soal**.

---

# Soal 16 – Apakah Ada Pasangan Nilai di Level Tertentu yang Jumlahnya X?

### 📋 Deskripsi

Diberikan sebuah binary tree dan sebuah angka target `X`, cek apakah ada **dua node berbeda** pada **level ke-`l`** yang jika dijumlahkan hasilnya `X`.

---

### 🧠 Fungsi:

```cpp
bool hasPairWithSumAtLevel(Node* root, int level, int X);
```

---

### 📥 Input

- `root`: pointer ke root tree
    
- `level`: level target (mulai dari 1)
    
- `X`: angka target
    

---

### 📤 Output

- Cetak `"ADA"` jika ada 2 node berbeda di level `l` yang jumlahnya `X`,  
    atau `"TIDAK ADA"` jika tidak ditemukan.
    

---

### 💡 Contoh:

Misal tree:

```

       10
     /    \
   5       15
  / \     /  \
 3   7   12   8
 
```

- `level = 3`, `X = 15`  
    → node di level 3 = `3, 7, 12, 8`  
    → pasangan: `7 + 8 = 15` ✅  
    → Output: `"ADA"`
    

---

### ⚙️ Petunjuk:

- Gunakan traversal berbasis level ke-`l`, lalu simpan node ke `vector<int>`
    
- Gunakan `unordered_set` atau brute-force untuk mencari 2 angka yang jumlahnya `X`
    
- Tidak perlu mencari posisi, cukup nilai
    

---

Langsung kerjakan, dan setelah kamu submit, aku bantu evaluasi + editorial seperti biasa! 😎

# Jawabanku
Berikut adalah jawabanku untuk menyelesaikan tantangan ini:

```cpp
#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

void treeTraverse(struct Node * node, int lvl, vector<int>& vec){
    if(node == NULL) return;

    treeTraverse(node->left, lvl-1, vec);
    treeTraverse(node->right, lvl-1, vec);

    if(lvl == 1){
        vec.push_back(node->data);
    }
}

bool isMatching(struct Node* node, int lvl, int x){
    vector<int> vec;
    treeTraverse(node, lvl, vec);

    for(int i=0; i<vec.size()-1; i++){
        for(int j=i+1; j<vec.size(); j++){
            if(vec[i]+vec[j] == x){
                return true;
            }
        }
    }

    return false;
}

int main() {
    struct Node * root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(7);

    root->right = new Node(15);
    root->right->right = new Node(8);
    root->right->left = new Node(12);

    int l, x; cin >> l >> x;
    cout << (isMatching(root, l, x)? "ADA" : "TIDAK ADA") << endl;
    return 0;
}
```

# Editorial
💯 **JAWABANMU SEMPURNA!**  

Kamu **menggabungkan traversal + penyimpanan data + pemeriksaan kondisi** dengan sangat rapi dan logis!  

Sekarang aku bantu buatkan editorial profesional seperti biasa — siap salin ke Obsidian:

### ✅ Fungsi Utama

```cpp
bool isMatching(struct Node* node, int lvl, int x){
    vector<int> vec;
    treeTraverse(node, lvl, vec);

    for(int i=0; i < vec.size()-1; i++){
        for(int j=i+1; j < vec.size(); j++){
            if(vec[i]+vec[j] == x){
                return true;
            }
        }
    }
    return false;
}
```

---

### 🔍 Fungsi Pendukung

```cpp
void treeTraverse(struct Node * node, int lvl, vector<int>& vec){
    if(node == NULL) return;

    treeTraverse(node->left, lvl - 1, vec);
    treeTraverse(node->right, lvl - 1, vec);

    if(lvl == 1){
        vec.push_back(node->data);
    }
}
```

---

## 🌳 Contoh Tree:

```

       10
     /    \
    5      15
   / \    /  \
  3   7  12   8
  
```

- `level = 3`, `x = 15`  
    → Node di level 3: `3, 7, 12, 8`  
    → 7 + 8 = 15 ✅ → Output: `"ADA"`
    

---

## 🧠 Penjelasan:

|Langkah|Penjelasan|
|---|---|
|Traversal|Kunjungi node pada level `l` dan simpan ke `vector<int>`|
|Penyimpanan|Gunakan vektor untuk menyimpan nilai-nilai di level tersebut|
|Pencocokan|Periksa semua pasangan nilai dalam vektor apakah ada yang jumlahnya `x`|
|Return|Jika ketemu satu pasangan → `return true`, kalau tidak → `false`|

---

## ✅ Evaluasi

|Aspek|Status|
|---|---|
|Traversal level dan penyimpanan ke vektor|✅|
|Pemeriksaan semua kombinasi pasangan|✅|
|Tidak ada variabel global|✅|
|Output sesuai spesifikasi|✅|

---

### ⚡ Peningkatan Opsional

Kalau nanti kamu ingin performa lebih baik:

- Gunakan `unordered_set<int>` untuk mengecek `X - val` dalam O(1)
    

Tapi untuk **dasar traversal dan pemrosesan level**, jawaban kamu **sangat bagus dan tepat sasaran**!

---

Kalau kamu sudah salin editorial ini, langsung bilang ya — kita lanjut ke **Soal 17**, dan akan aku buat makin menantang! 😎