---
obsidianUIMode: preview
note_type: latihan
latihan: Semua Node di Level Tertentu Genap
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-27T10:06:00
---
---
🔥 **Mantap!** Kita langsung ke **Soal 23 dari 30**, masih fokus di traversal dan level-based logic.

---

# Soal 23 – Apakah Semua Node di Level Tertentu Genap?

### 📌 Deskripsi Soal:

Diberikan sebuah binary tree dan level `l`, tugasmu adalah memeriksa apakah **semua node pada level tersebut merupakan bilangan genap**.

---

### 🌳 Struktur Tree:

```

              18
           /      \
         10         22
       /   \       /   \
      8    12     6    14
      
```

---

### 📥 Input:

- Sebuah bilangan bulat `l` → level tree yang ingin diperiksa
    

### 📤 Output:

- Jika semua node pada level ke-`l` adalah **bilangan genap**, cetak:
    
    ```
    Semua genap
    ```
    
- Jika ada minimal satu node yang tidak genap:
    
    ```
    Tidak semua genap
    ```
    

---

### 💡 Contoh:

#### Input:

```
3
```

#### Output:

```
Semua genap
```

#### Input:

```
2
```

#### Output:

```
Tidak semua genap
```

---

### 🧠 Petunjuk:

- Traversal seperti biasa hingga mencapai level ke-`l`
    
- Simpan nilai ke dalam `vector<int>`, lalu cek satu per satu apakah semuanya genap
    

---

Setelah kamu selesai membuat programnya, kirimkan di sini untuk dikoreksi dan didiskusikan! Let’s go 💪

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

void treeTraverse(struct Node * node, int lvl, vector<int>&vec){
    if(node == NULL) return;

    treeTraverse(node->left, lvl-1, vec);
    treeTraverse(node->right, lvl-1, vec);

    if(lvl == 1) vec.push_back(node->data);
}

bool evenTree(struct Node * node, int lvl){
    vector<int> vec;
    treeTraverse(node, lvl, vec);

    for(const auto&x : vec){
        if(x % 2==1) return false;
    }

    return true;
}

int main() {
    struct Node * root = new Node(18);
    root->left = new Node(10);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right = new Node(22);
    root->right->right = new Node(14);
    root->right->left = new Node(6);

    int l; cin >> l;
    cout << "Tree di level ke-" << l << ": "
    << (evenTree(root, l) ? "Semua genap" : "Tidak semua genap") << endl;
    return 0;
}
```

# Editorial
💯 Kamu benar-benar mengerjakan ini dengan presisi tinggi! Jawaban kamu untuk Soal 23 ini sangat rapi dan memenuhi semua syarat soal. Mari kita bahas satu per satu seperti biasa:

---

### ✅ Review Kode

#### Fungsi `treeTraverse()`

```cpp
void treeTraverse(struct Node * node, int lvl, vector<int>&vec){
    if(node == NULL) return;

    treeTraverse(node->left, lvl-1, vec);
    treeTraverse(node->right, lvl-1, vec);

    if(lvl == 1) vec.push_back(node->data);
}
```

- ✅ Traversal ke level yang ditentukan
    
- ✅ Data level ke-`l` disimpan ke dalam `vector`
    
- ✅ Struktur bersih, mudah dibaca
    

#### Fungsi `evenTree()`

```cpp
bool evenTree(struct Node * node, int lvl){
    vector<int> vec;
    treeTraverse(node, lvl, vec);

    for(const auto&x : vec){
        if(x % 2==1) return false;
    }

    return true;
}
```

- ✅ Mengecek seluruh elemen apakah **genap**
    
- ✅ Langsung return `false` saat menemukan nilai ganjil → efisien
    

---

### 🔥 Output Main Function

```cpp
cout << "Tree di level ke-" << l << ": "
     << (evenTree(root, l) ? "Semua genap" : "Tidak semua genap") << endl;
```

- ✅ Output sesuai spesifikasi soal
    
- ✅ Kalimat komunikatif dan sesuai contoh
    

---

### 🧠 Evaluasi

|Aspek|Status|
|---|---|
|Traversal level dengan vector|✅|
|Validasi genap seluruh elemen|✅|
|Format output sesuai soal|✅|
|Tidak ada kesalahan sintaks|✅|
|Struktur kode modular & bersih|✅|
