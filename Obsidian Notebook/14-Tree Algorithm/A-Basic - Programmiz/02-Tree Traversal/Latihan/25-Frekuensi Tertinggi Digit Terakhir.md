---
obsidianUIMode: preview
note_type: latihan
latihan: Frekuensi Tertinggi Digit Terakhir
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-27T11:02:00
---
---
Baik! Berikut soal **terakhir** (soal ke-30) dalam rangkaian latihan traversal tree-mu. Soal ini tetap fokus pada traversal dan penyimpanan data untuk dianalisis, dan sedikit lebih menantang.

---

# 🧩 Soal 25: Frekuensi Tertinggi Digit Terakhir pada Level Tertentu

**Deskripsi**:  
Diberikan sebuah binary tree. Pada level ke-`l` dari tree tersebut, tentukan **digit terakhir (satuan)** mana yang paling sering muncul di antara seluruh node pada level tersebut.

Jika ada lebih dari satu digit dengan frekuensi yang sama dan tertinggi, pilih digit yang **lebih kecil**.

---

### 📥 Input:

- Sebuah binary tree yang telah dibentuk di dalam program.
    
- Integer `l` (level yang akan diperiksa).
    

---

### 📤 Output:

- Cetak digit terakhir dengan frekuensi paling banyak pada level ke-`l`.
    

---

### 🌳 Contoh Struktur Tree:

```

              42
            /    \
          35      78
         /  \    /  \
       21   45  67  89
       
```

Misalnya input `l = 3`  
Node di level ke-3: `21, 45, 67, 89`  
Digit terakhir: `1, 5, 7, 9`  
Semua muncul 1 kali, jadi ambil yang paling kecil ⇒ Output: `1`

---

### 🎯 Tantangan:

- Lakukan traversal untuk menyimpan seluruh node pada level `l`.
    
- Hitung digit terakhirnya (`node->data % 10`) lalu cari frekuensi terbanyak.
    
- Gunakan struktur data `map` atau `array` untuk mempermudah pencatatan.
    

---

Jika kamu siap, langsung coba koding sendiri ya. Setelah selesai, kirimkan hasilnya ke sini dan aku akan bantu review seperti biasa! 💪🌲

# Jawabanku
Berikut adalah jawabanku yang sudah melalui beberapa tahap perbaikan:

```cpp
#include<climits>
#include<iostream>
#include<map>
#include<iterator>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int data){
        this->data = data;
        left=right=NULL;
    }
};

void treeTraverse(struct Node*node, int lvl, map<int,int>&dasmap){
    if(node == NULL) return;

    treeTraverse(node->left, lvl-1, dasmap);
    treeTraverse(node->right, lvl-1, dasmap);
    
    if(lvl == 1){
        dasmap[(node->data % 10)]++;
    }
}

int lastDigitTree(struct Node*node, int lvl){
    map<int, int> dasmap;
    int temp = INT_MIN;
    int rest=0;

    treeTraverse(node, lvl, dasmap);

    map<int, int>::iterator iter;
    for(iter=dasmap.begin(); iter != dasmap.end(); iter++){
        if(iter->second > temp){
            temp=iter->second;
            rest=iter->first;
        }
    }

    return rest;
}

int main() {
    struct Node * root = new Node(42);
    root->left = new Node(35);
    root->left->left = new Node(21);
    root->left->right = new Node(45);
    root->right = new Node(78);
    root->right->right = new Node(89);
    root->right->left = new Node(67);

    int l; cin >> l;
    cout << "Digit terkecil terkahir kemunculan terbannyak: ";
    cout << lastDigitTree(root, l) << endl;
    return 0;
}
```

# Editorial
Jawabanmu sudah **sangat bagus dan tepat secara logika serta implementasi traversalnya rapi**! Sekarang aku bantu buatkan **editorial per blok kode** agar bisa kamu simpan ke dalam Obsidian-mu. 👇

---

### 🔹 `struct Node`

```cpp
struct Node {
    int data;
    struct Node *left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};
```

**Penjelasan**:

- Struct dasar untuk membuat node pada binary tree.
    
- Constructor digunakan untuk langsung menginisialisasi nilai `data`, serta pointer `left` dan `right` menjadi `NULL`.
    

---

### 🔹 Fungsi `treeTraverse`

```cpp
void treeTraverse(struct Node* node, int lvl, map<int,int>& dasmap){
    if(node == NULL) return;

    treeTraverse(node->left, lvl - 1, dasmap);
    treeTraverse(node->right, lvl - 1, dasmap);
    
    if(lvl == 1){
        dasmap[(node->data % 10)]++;
    }
}
```

**Penjelasan**:

- Fungsi rekursif untuk menelusuri tree hingga mencapai level `lvl`.
    
- Jika sudah mencapai level yang dimaksud (`lvl == 1`), ambil digit terakhir dari `node->data` menggunakan `data % 10`, lalu simpan ke dalam `dasmap` sebagai frekuensi kemunculan.
    
- Traversal dilakukan dengan urutan **left → right**, cocok untuk simulasi level order di level tertentu.
    

---

### 🔹 Fungsi `lastDigitTree`

```cpp
int lastDigitTree(struct Node* node, int lvl){
    map<int, int> dasmap;
    int temp = INT_MIN;
    int rest = 0;

    treeTraverse(node, lvl, dasmap);

    map<int, int>::iterator iter;
    for(iter = dasmap.begin(); iter != dasmap.end(); iter++){
        if(iter->second > temp){
            temp = iter->second;
            rest = iter->first;
        }
    }

    return rest;
}
```

**Penjelasan**:

- Fungsi utama yang memanggil `treeTraverse` untuk mendapatkan frekuensi digit terakhir dari setiap node di level `lvl`.
    
- Kemudian mencari digit dengan frekuensi tertinggi. Karena `map` secara default berurutan dari kecil ke besar, maka **jika frekuensinya sama**, digit yang **lebih kecil akan dipilih** terlebih dahulu.
    
- Ini menjawab keperluan soal dengan benar.
    

---

### 🔹 Fungsi `main`

```cpp
int main() {
    struct Node * root = new Node(42);
    root->left = new Node(35);
    root->left->left = new Node(21);
    root->left->right = new Node(45);
    root->right = new Node(78);
    root->right->right = new Node(89);
    root->right->left = new Node(67);

    int l; cin >> l;
    cout << "Digit terkecil terakhir kemunculan terbanyak: ";
    cout << lastDigitTree(root, l) << endl;
    return 0;
}
```

**Penjelasan**:

- Tree dibangun sesuai contoh soal.
    
- Input level dibaca dari pengguna.
    
- Hasil digit akhir dengan frekuensi tertinggi di level tersebut dicetak.
    

---

### ✅ Catatan Penilaian:

- ✅ Menggunakan `map` untuk menyimpan frekuensi secara efisien.
    
- ✅ Traversal dan pengambilan data sesuai permintaan soal.
    
- ✅ Penanganan pemilihan digit terkecil saat frekuensi sama **berhasil dilakukan secara implisit karena `map` terurut**.
    

---

Ingin lanjut ke **soal ke-31** (latihan traversal yang lebih advance), atau kamu ingin istirahat dulu dan review semua yang sudah kamu capai sejauh ini? 😎