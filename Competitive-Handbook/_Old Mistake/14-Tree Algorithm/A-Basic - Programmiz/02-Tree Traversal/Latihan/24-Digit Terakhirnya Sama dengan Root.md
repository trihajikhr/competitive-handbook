---
obsidianUIMode: preview
note_type: latihan
latihan: Digit Terakhirnya Sama dengan Root
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-27T10:23:00
---
---
Wih mantap! 🔥 Kamu benar-benar sudah khatam banyak variasi traversal tree ya. Kalau begitu, kita masuk ke **soal eksperimental** — soal yang **menggabungkan traversal dengan aturan logika baru**, dijamin **belum pernah kamu kerjakan** karena ini kustom banget.

---

# Soal 24 – Total Nilai Node Level `l` yang Digit Terakhirnya Sama dengan Root

### 📌 Deskripsi Soal:

Diberikan sebuah **binary tree** dan sebuah bilangan bulat `l`.  
Tugasmu adalah menghitung **jumlah seluruh node pada level ke-`l`** yang **digit terakhirnya (satuan)** **sama dengan digit terakhir dari root node**.

---

### 📥 Input:

- Integer `l` — level yang ingin dicek
    

---

### 📤 Output:

- Jika ada node di level tersebut yang digit terakhirnya sama dengan digit terakhir root → cetak total penjumlahan node tersebut.
    
- Jika tidak ada node yang cocok atau level kosong → cetak:
    
    ```
    Tidak ditemukan
    ```
    

---

### 🌳 Contoh Tree:

```

              37
           /      \
         25        42
        /  \      /   \
      17   39   31    44
      
```

> Digit terakhir dari root = **7**

---

### 💡 Contoh Input/Output:

#### Input:

```
3
```

#### Output:

```
17
```

#### Penjelasan:

Level ke-3: 17, 39, 31, 44  
→ Yang digit terakhirnya 7 = 17  
→ Total = 17

---

#### Input:

```
2
```

#### Output:

```
Tidak ditemukan
```

---

### 🧠 Petunjuk:

- Gunakan traversal ke level `l`.
    
- Simpan elemen yang `x % 10 == root->data % 10`
    
- Lalu jumlahkan.
    
- Hati-hati kalau tidak ada node, maka `Tidak ditemukan`.
    

---

Siap gas? 🎯  
Kalau ini juga kamu udah bisa pecahkan dengan cepat, berarti kamu udah masuk **tier elite traversal**! Kirim jawabanmu kalau udah!

# Jawaban Editorial
Ada kalanya kita perlu melihat jawaban dari versi yang lain, kali ini aku tidak menjawab:

```cpp
#include<iostream>
#include<vector>
#include<optional>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

void treeTraverse(Node* node, int lvl, int rootDigit, int& sum, bool& found) {
    if (!node) return;

    treeTraverse(node->left, lvl - 1, rootDigit, sum, found);
    treeTraverse(node->right, lvl - 1, rootDigit, sum, found);

    if (lvl == 1 && node->data % 10 == rootDigit) {
        sum += node->data;
        found = true;
    }
}

optional<int> sumMatching(Node* root, int lvl) {
    int rootLastDigit = root->data % 10;
    int sum = 0;
    bool found = false;

    treeTraverse(root, lvl, rootLastDigit, sum, found);

    if (found) return sum;
    else return nullopt;
}


int main() {
    struct Node * root = new Node(37);
    root->left = new Node(25);
    root->left->left = new Node(17);
    root->left->right = new Node(39);
    root->right = new Node(42);
    root->right->right = new Node(44);
    root->right->left = new Node(31);

    int l; cin >> l;
    auto res = sumMatching(root, l);

    if (res.has_value()) {
        cout << "Total: " << res.value() << endl;
    } else {
        cout << "Tidak ditemukan" << endl;
    }

    return 0;
}
```

# Editorial
Berikut adalah **editorial lengkap** dari program C++ yang menggunakan `std::optional` untuk menjumlahkan node pada level tertentu yang **digit terakhirnya sama dengan root**. Penjelasan diberikan per blok kode agar mudah dipahami dan dicatat ke Obsidian:

---

### 🔷 `struct Node`

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};
```

📌 **Penjelasan**:

- Struktur data dasar sebuah node pohon biner.
    
- `data`: menyimpan nilai integer.
    
- `left` dan `right`: pointer ke anak kiri dan anak kanan.
    
- Konstruktor langsung menginisialisasi nilai dan menyetel anak ke `NULL`.
    

---

### 🔷 Fungsi `treeTraverse()`

```cpp
void treeTraverse(Node* node, int lvl, int rootDigit, int& sum, bool& found) {
    if (!node) return;

    treeTraverse(node->left, lvl - 1, rootDigit, sum, found);
    treeTraverse(node->right, lvl - 1, rootDigit, sum, found);

    if (lvl == 1 && node->data % 10 == rootDigit) {
        sum += node->data;
        found = true;
    }
}
```

📌 **Penjelasan**:

- Fungsi rekursif traversal pohon.
    
- `lvl`: menunjukkan level yang sedang dituju.
    
- `rootDigit`: menyimpan **digit terakhir** dari root tree.
    
- `sum`: akumulator hasil penjumlahan.
    
- `found`: boolean penanda apakah ada node yang cocok.
    

💡 Saat `lvl == 1` dan digit terakhir dari node saat ini **sama dengan digit root**, maka:

- `node->data` ditambahkan ke `sum`.
    
- `found` diset ke `true`.
    

---

### 🔷 Fungsi `sumMatching()`

```cpp
optional<int> sumMatching(Node* root, int lvl) {
    int rootLastDigit = root->data % 10;
    int sum = 0;
    bool found = false;

    treeTraverse(root, lvl, rootLastDigit, sum, found);

    if (found) return sum;
    else return nullopt;
}
```

📌 **Penjelasan**:

- Fungsi utama untuk menjumlahkan node tertentu di level tertentu.
    
- `optional<int>` digunakan agar bisa mengembalikan:
    
    - nilai hasil jika ditemukan (`return sum`), atau
        
    - tidak mengembalikan apa pun (`return nullopt`).
        
- `rootLastDigit`: mengambil digit terakhir dari root sebagai referensi.
    

🧠 Fungsi ini memanggil `treeTraverse()` dan mengembalikan hasil sesuai kondisi.

---

### 🔷 Fungsi `main()`

```cpp
int main() {
    struct Node * root = new Node(37);
    root->left = new Node(25);
    root->left->left = new Node(17);
    root->left->right = new Node(39);
    root->right = new Node(42);
    root->right->right = new Node(44);
    root->right->left = new Node(31);
```

📌 **Penjelasan**:

- Membuat struktur pohon secara manual.
    
- Root bernilai 37, maka digit terakhir acuan = `7`.
    

---

### 🔷 Input level dan output hasil

```cpp
    int l; cin >> l;
    auto res = sumMatching(root, l);

    if (res.has_value()) {
        cout << "Total: " << res.value() << endl;
    } else {
        cout << "Tidak ditemukan" << endl;
    }

    return 0;
}
```

📌 **Penjelasan**:

- Menerima input level `l`.
    
- Memanggil `sumMatching()` dan menyimpan hasilnya dalam `std::optional<int>`.
    
- Jika `has_value()` bernilai `true`, maka tampilkan nilainya.
    
- Jika `false`, tampilkan bahwa tidak ada node yang cocok.
    

---

### 🔚 Kesimpulan:

|Aspek|Penilaian|
|---|---|
|✅ Modularitas|Fungsi-fungsi terpisah dan jelas fungsinya|
|✅ Modern C++|Pemakaian `std::optional` menggantikan penggunaan variabel global / flag|
|✅ Efisiensi|Traversal tetap efisien, hanya satu kali scan level|
|✅ Readability|Kode mudah dibaca dan dijelaskan per bagian|

---

Kalau kamu mau, aku juga bisa bantu kamu bikin diagram pohonnya untuk kamu tempel di Obsidian. Siap lanjut ke soal berikutnya? 😄