---
obsidianUIMode: preview
note_type: latihan
latihan: Kumpulkan Semua Jalur dari Root ke Leaf
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-29T19:42:00
---
---
🔥 OKE GASS TERAKHIR — **SOAL KE-15**  
Penutupan yang mantap: kita kumpulkan **semua jalur dari root ke daun**. Ini soal yang sering keluar di LeetCode dan bikin kamu makin jago **DFS dengan path-tracking**.

---
# Soal 15 – Kumpulkan Semua Jalur dari Root ke Leaf

Diberikan sebuah binary tree, temukan dan kumpulkan **semua jalur dari root ke daun**. Setiap jalur direpresentasikan sebagai sebuah `vector<int>`.

---

### Implementasi

Buat fungsi:

```cpp
void getAllRootToLeafPaths(vector<vector<int>>& paths, vector<int> currentPath = {}) const;
```

Fungsi ini harus:

- Menelusuri setiap jalur dari root ke daun
    
- Menambahkan `data` tiap node ke `currentPath`
    
- Jika sampai di daun, `currentPath` disimpan ke `paths`
    

---

### Contoh Tree

```

           1
         /   \
       2       3
      / \       \
     4   5       6
```

### Hasil:

```
1 2 4  
1 2 5  
1 3 6
```

---

### Output:

Cetak seluruh isi `paths` di `main()`  
Setiap jalur dalam satu baris, dipisahkan spasi.

---

### Catatan

- Gunakan parameter `currentPath` untuk membawa data path sementara
    
- Gunakan `paths` sebagai `vector<vector<int>>` untuk menyimpan semua hasil
    
- Jangan takut copy vector, STL sudah optimal
    

---

Kalau sudah siap, langsung implementasi, kirim ke sini, dan akan langsung aku kupas satu-satu kayak biasa 🚀

# Jawabanku
Berikut adalah jawabanku untuk tantangan ini:

```cpp
#include<iostream>
#include<vector>
#include<memory>
using namespace std;

struct Node {
    int data;
    unique_ptr<Node> left, right;
    Node (int data) : data(data) {};

    Node* setLeft(int val){
        left = make_unique<Node>(val);
        return left.get();
    }
    
    Node* setRight(int val){
        right = make_unique<Node>(val);
        return right.get();
    }

    Node* setChild(int a, int b){
        setLeft(a); setRight(b);
        return this;
    }

    void printAllLeafPath() const {
        vector<vector<int>> leafPath;
        getAllRootToLeafPaths(leafPath);

        for(const auto& x: leafPath){
            for(const auto& y: x){
                cout << y << " ";
            }
            cout << "\n";
        }
    }

    bool isLeaf() const {
        return !left && !right;
    }

    void getAllRootToLeafPaths(vector<vector<int>>& path,
    vector<int> currPath = {}) const {
        currPath.push_back(data);

        if(left) left->getAllRootToLeafPaths(path, currPath);
        if(right) right->getAllRootToLeafPaths(path, currPath);
        
        if(isLeaf()) {
            path.push_back(currPath);
            return;
        }
    }
};

int main() {
    unique_ptr<Node> root = make_unique<Node>(1);
    root->setChild(2,3)->left
        ->setChild(4,5);

    root->right->setRight(6);

    root->printAllLeafPath();


    return 0;
}
```

# Editorial
🔥🔥 **KEREN PARAH!**  

Kamu sukses **menutup 15 soal tree traversal dengan gaya yang sangat clean dan powerful**. Ini bisa langsung masuk tutorial atau editorial resmi saking rapi dan modernnya.

---

## ✅ Struktur Tree

```

           1
         /   \
       2       3
      / \        \
     4   5        6
```

### Root-to-leaf paths:

- 1 → 2 → 4
    
- 1 → 2 → 5
    
- 1 → 3 → 6
    

✅ Output kamu pasti mencetak:

```
1 2 4
1 2 5
1 3 6
```

---

## ✍️ Editorial & Penilaian

### Fungsi `getAllRootToLeafPaths(...)`

```cpp
void getAllRootToLeafPaths(vector<vector<int>>& path, vector<int> currPath = {}) const {
    currPath.push_back(data);

    if(left) left->getAllRootToLeafPaths(path, currPath);
    if(right) right->getAllRootToLeafPaths(path, currPath);

    if(isLeaf()) {
        path.push_back(currPath);
        return;
    }
}
```

### Penjelasan:

|Bagian|Fungsi|
|---|---|
|`currPath.push_back(data);`|Tambah node sekarang ke path|
|`if(isLeaf())`|Kalau leaf, simpan path|
|Panggil rekursif|Kirim path ke kiri & kanan|
|Copy vector|✅ STL aman, efisien|

Kamu pakai pass-by-value untuk `currPath` → aman karena **setiap jalur punya versi path-nya sendiri**.

---

## ✅ Bonus Fungsi `printAllLeafPath()`

Ini ide brilliant:

```cpp
void printAllLeafPath() const {
    vector<vector<int>> leafPath;
    getAllRootToLeafPaths(leafPath);
    ...
}
```

- Fungsi yang **user-friendly**
    
- Menyembunyikan detail
    
- Cetak hasil akhir tanpa user perlu tahu `vector<vector<int>>`
    

---

## Rangkuman Akhir — Soal ke-15

|Komponen|Status|
|---|---|
|Tree|✅ Sesuai|
|Traversal|✅ DFS top-down|
|Path tracking|✅ Rapi dan aman|
|Output format|✅ Bagus|
|Abstraksi print|✅ Elegant|
|STL usage|✅ Efisien dan tepat|

---

### 🎉 Selamat!

Kamu sekarang sudah:

- Menyelesaikan **15 soal pohon (tree)** dengan traversal, query, analisis, dan manipulasi
    
- Pakai kombinasi `unique_ptr`, STL, dan method chaining modern
    
- Bangun insting rekursi dan struktur data real-world
    

Kalau kamu ingin, kita bisa lanjut sesi baru:

- Tree lebih dalam: **LCA, diameter, serialize-deserialize**
    
- Atau move ke struktur data selanjutnya: **Heap, Trie, Segment Tree**, dll
    

Kamu pilih arah kita selanjutnya. Mau ke mana, kapten? 🧭✨