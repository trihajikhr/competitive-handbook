---
obsidianUIMode: preview
note_type: latihan
latihan: Hitung Rerata Node
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-26T21:34:00
---
---
🔥 **Let's Go ke Soal 19 dari 20!**  

Latihan ini tetap menggunakan traversal, penyimpanan nilai, dan pengolahan data. Kali ini kamu diminta menghitung **rerata (mean)** node pada **level tertentu** dari sebuah pohon.

---

# Soal 19 – Hitung Rerata Node pada Level Tertentu

---

### 📋 Deskripsi

Diberikan sebuah binary tree dan sebuah integer `l`, hitung **rata-rata (mean)** dari semua node pada **level ke-`l`**.  
Hasil ditampilkan dalam format `float` hingga dua angka di belakang koma.

---

### 📥 Input

- Binary tree (dibentuk manual di `main`)
    
- Integer `l` (level ke berapa, dimulai dari 1)
    

---

### 📤 Output

- Rata-rata nilai node di level ke-`l`, dalam format float (2 digit di belakang koma)
    

---

### 🧠 Fungsi:

```cpp
float meanLevelTree(Node* root, int level);
```

---

### 💡 Contoh Tree:

```

       20
     /    \
   10      30
  /  \    /  \
 5   15  25  35
 
```

- level = 3 → node = `5, 15, 25, 35`  
    → (5 + 15 + 25 + 35) / 4 = **20.00**
    
- level = 2 → node = `10, 30`  
    → (10 + 30)/2 = **20.00**
    
- level = 1 → node = `20`  
    → mean = **20.00**
    

---

### ⚙️ Petunjuk:

- Simpan nilai node pada level `l` ke dalam `vector<int>`
    
- Jumlahkan semua elemen vektor dan bagi dengan banyak elemen
    
- Gunakan `fixed` dan `setprecision(2)` untuk tampilan rapi
    

---

Silakan kamu kerjakan! Setelah itu aku bantu evaluasi dan editorial seperti biasa 💪

# Jawabanku
Berikut adalah jawabanku yang sudah cukup optimal:

```cpp
#include<iostream>
#include<vector>
#include<numeric>
#include<iomanip>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int data){
        this->data = data;
        left=right = NULL;
    }
};

void treeTravers(struct Node * node, int lvl, vector<int>& vec){
    if(node == NULL) return;

    treeTravers(node->left, lvl-1, vec);
    treeTravers(node->right, lvl-1, vec);
    if(lvl == 1){
        vec.push_back(node->data);
    }
}

float treeAverage(struct Node * node, int lvl){
    vector<int> vec;
    treeTravers(node, lvl, vec);

    float rest = accumulate(vec.begin(), vec.end(), 0);
    rest/= static_cast<float>(vec.size());
    return rest;
}

int main() {
    struct Node * root = new Node(20);
    root->left = new Node(10);
    root->left->left = new Node(5);
    root->left->right = new Node(15);

    root->right = new Node(30);
    root->right->right = new Node(35);
    root->right->left = new Node(25);

    int l; cin >> l;
    cout << "Rerata tree di level ke-" << l << ": "
    << setprecision(2) << fixed << treeAverage(root, l) << endl;
    return 0;
}
```

# Editorial
🎯 **Excellent Work!**

Kamu berhasil menyelesaikan **Soal 19** dengan sempurna — dan juga dengan _clean code_ serta tampilan hasil yang sangat rapi. Berikut penjelasan lengkapnya sebagai bahan catatan:

---

### ✅ Fungsi Utama

```cpp
float treeAverage(struct Node * node, int lvl){
    vector<int> vec;
    treeTravers(node, lvl, vec);

    float rest = accumulate(vec.begin(), vec.end(), 0);
    rest /= static_cast<float>(vec.size());
    return rest;
}
```

---

### 🔍 Fungsi Traversal Level

```cpp
void treeTravers(struct Node * node, int lvl, vector<int>& vec){
    if(node == NULL) return;

    treeTravers(node->left, lvl-1, vec);
    treeTravers(node->right, lvl-1, vec);

    if(lvl == 1){
        vec.push_back(node->data);
    }
}
```

---

### 🌳 Contoh Tree:

```

       20
     /    \
   10      30
  /  \    /  \
 5   15  25  35
 
```

- Level 3: `5, 15, 25, 35`  
    → Rerata: (5 + 15 + 25 + 35)/4 = **20.00**
    
- Level 2: `10, 30` → (10+30)/2 = **20.00**
    

---

### 📌 Teknik Penting

|Teknik|Keterangan|
|---|---|
|`vector<int>`|Menyimpan node pada level tertentu|
|`accumulate()`|Menjumlahkan isi vektor|
|`static_cast<float>()`|Menghindari pembagian bilangan bulat|
|`setprecision(2)`|Format output 2 digit desimal (float tampak rapi)|

---

## ✅ Evaluasi

|Aspek|Status|
|---|---|
|Traversal dan pengumpulan nilai level|✅|
|Penghitungan mean secara akurat|✅|
|Penanganan casting dan format float|✅|
|Output bersih dan profesional|✅|

---

Kalau sudah kamu catat ke Obsidian, saatnya kita ke **Soal terakhir: Soal 20 dari 20** 🎉  
Akan ada twist sedikit — kamu diminta mencari nilai **maksimum dan minimum sekaligus** di level tertentu dan mencetak **selisih** di antara keduanya.

Siap? 💥