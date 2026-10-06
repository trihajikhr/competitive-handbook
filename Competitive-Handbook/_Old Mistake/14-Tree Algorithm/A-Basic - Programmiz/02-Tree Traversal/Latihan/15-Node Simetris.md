---
obsidianUIMode: preview
note_type: latihan
latihan: Node Simetris
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-26T19:20:00
---
---
🔥 Let's go! Kita tiba di **Soal 15**, penutup dari sesi latihan traversal dasar ini.  
Kali ini kamu akan menggabungkan traversal level dan **perbandingan struktur kiri–kanan**, sedikit lebih “mindsety”.

---

# Soal 15 – Apakah Semua Node di Kiri dan Kanan pada Level Tertentu Sama?

### 📋 Deskripsi

Diberikan sebuah **binary tree**, buat fungsi:

```cpp
bool isLevelSymmetric(Node* root, int level);
```

yang akan **mengembalikan `true` jika node di level ke-`level` simetris secara nilai**, artinya:

- Nilai-nilai dari kiri ke kanan **sama** dengan nilai-nilai dari kanan ke kiri
    

➡️ **Bukan simetri pohon**, tapi **simetri data pada level tersebut saja**.

---

### 📥 Input

- `root`: pointer ke root binary tree
    
- `level`: bilangan bulat ≥ 1
    

---

### 📤 Output

- `true` atau `false` (boleh cetak `"YES"` atau `"NO"`)
    

---

### 💡 Contoh Pohon:

```

         8
        / \
      3     3
     / \   / \
    4   5 5   4
    
```

- Level 1 → `8` → simetris ✅
    
- Level 2 → `3, 3` → simetris ✅
    
- Level 3 → `4, 5, 5, 4` → simetris ✅
    
- Kalau jadi `4, 5, 6, 4` → tidak simetris ❌
    

---

### ⚙️ Ketentuan:

- Gunakan **traversal berbasis level**
    
- Simpan nilai pada level ke-`l` dalam vektor
    
- Lalu cek apakah vektor itu simetris
    

---

Sudah siap? Langsung buat dan kirimkan kodenya — aku akan bantu evaluasi dan membuat editorialnya seperti biasa 😎

# Jawaban
Berikut adalah jawabanku untuk problem yang satu ini:

```cpp
#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    struct Node *kiri, *kanan;
    Node(int data){
        this->data = data;
        kiri=kanan=NULL;
    }
};

void isTreeSymetric(Node * node, int lvl, vector<int>& vec){
    if(node == NULL) return;

    isTreeSymetric(node->kiri, lvl-1, vec);
    isTreeSymetric(node->kanan, lvl-1, vec);
    
    if(lvl == 1){
        vec.push_back(node->data);
    }
}

bool isSymetric(Node* node, int lvl){
    vector<int> vec;
    isTreeSymetric(node, lvl, vec);

    for(size_t i=0; i<vec.size()/2; i++){
        if(vec[i] != vec[vec.size()-i-1]){
            return false;
        }
    }
    return true;
}

int main() {
    struct Node *root = new Node(8);
    root->kiri = new Node(3);
    root->kiri->kiri = new Node(4);
    root->kiri->kanan = new Node(5);

    root->kanan = new Node(3);
    root->kanan->kanan = new Node(4);
    root->kanan->kiri = new Node(5);

    int l; cin >> l;
    cout << "Tree simetris: " 
    << (isSymetric(root, l) ? "true" : "false") << endl;
    return 0;
}
```

# Editorial
🔥 **Sempurna untuk soal penutup sesi traversal dasar!**  
Kamu menyelesaikan soal ini dengan **struktur rekursif yang bersih**, **penyimpanan level-data ke vektor**, dan **cek simetri** yang tepat.

Sekarang aku bantu buatkan **editorial final** untuk soal nomor 15 — siap kamu salin ke Obsidian!

---

## 🧩 Soal 15 – Apakah Node di Level Tertentu Simetris?

---

### 📘 Deskripsi

Cek apakah semua **nilai node** pada level ke-`l` dalam tree:

- **Simetris dari kiri ke kanan**, yaitu `vec[i] == vec[n-1-i]`  
    (mirip palindrome)
    

---

### ✅ Fungsi Utama:

```cpp
bool isSymetric(Node* node, int lvl){
    vector<int> vec;
    isTreeSymetric(node, lvl, vec);

    for(size_t i = 0; i < vec.size() / 2; i++){
        if(vec[i] != vec[vec.size() - i - 1]){
            return false;
        }
    }
    return true;
}
```

---

### 🧠 Fungsi Rekursif Pendukung:

```cpp
void isTreeSymetric(Node* node, int lvl, vector<int>& vec){
    if(node == NULL) return;

    isTreeSymetric(node->kiri, lvl - 1, vec);
    isTreeSymetric(node->kanan, lvl - 1, vec);

    if(lvl == 1){
        vec.push_back(node->data);
    }
}
```

---

## 🌳 Contoh Pohon:

```

         8
        / \
      3     3
     / \   / \
    4  5  5   4
    
```

- Level 1 → `8` → ✅
    
- Level 2 → `3, 3` → ✅
    
- Level 3 → `4, 5, 5, 4` → ✅
    
- Kalau jadi `4, 5, 6, 4` → ❌
    

---

## 🎯 Penjelasan:

|Langkah|Penjelasan|
|---|---|
|`isTreeSymetric()`|Melakukan traversal level-`l` dan simpan ke `vector<int>`|
|`lvl == 1`|Artinya kita sudah sampai level target, push data ke vector|
|Cek `vec[i] == vec[n-1-i]`|Bandingkan elemen kiri dan kanan dari vector|

---

### ✅ Evaluasi

|Aspek|Status|
|---|---|
|Traversal berbasis level|✅|
|Penyimpanan nilai ke vector|✅|
|Pengecekan simetri yang akurat|✅|
|Tidak ada variabel global|✅|
|Output sesuai harapan|✅|

---

## 🏁 Kesimpulan

Kamu sekarang telah menyelesaikan **15 soal traversal pohon** yang mencakup:

|Tipe Latihan|✔️|
|---|---|
|Traversal preorder, inorder, postorder|✅|
|Traversal berbasis level|✅|
|Jumlah node dengan kondisi tertentu|✅|
|Mencetak nilai dengan filter|✅|
|Cek simetri level data|✅|

---

### 🏆 Penutup Sesi Traversal

Kamu sekarang:

- Sudah sangat siap untuk masuk ke **level berikutnya**, seperti:
    
    - **Level Order Traversal menggunakan Queue**
        
    - **Traversal Iteratif**
        
    - **Traversal berbasis BFS/DFS**
        
- Bisa menangani **perhitungan dan filter spesifik** berbasis traversal
    

---

Kalau kamu ingin, sesi selanjutnya bisa kita mulai dengan topik:

- 🔁 Level Order Traversal dengan Queue (BFS)
    
- 📦 Iterative Traversal (tanpa rekursi)
    
- 🌲 Soal Binary Search Tree (BST)
    

Mau langsung lanjut atau istirahat dulu, sang pemenang latihan? 😄💪