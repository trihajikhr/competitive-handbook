---
obsidianUIMode: preview
note_type: latihan
latihan: Cari Nilai Maksimum Leaf Node
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-29T15:16:00
---
---
# Soal 8: Cari Nilai Maksimum Leaf Node

Buatlah fungsi `int maxLeafValue(Node* root)`  
yang mengembalikan nilai terbesar **di antara semua leaf nodes**.

---

#### Tree yang Digunakan:

```

           90
         /    \
       70      120
      /  \     /  \
    60   80  110  130
             /
           105
```

---

### Penjelasan:

Leaf nodes adalah:

- `60`, `80`, `105`, `130`
    

Nilai maksimumnya = `130`

---

### Syarat:

- Jangan menggunakan `std::max_element` atau library `algorithm`.
    
- Traversal bebas: preorder, postorder, atau inorder — yang penting logikanya benar.
    

---

Silakan implementasikan kode lengkapnya, mulai dari pembuatan tree-nya hingga fungsi `maxLeafValue()`. Kirim ke sini, nanti langsung aku bedah dan editorialin!

# Jawabanku
Berikut adalah jawabanku untuk menyelesaikan tantangan ini:

```cpp
#include<iostream>
#include<climits>
#include<memory>
using namespace std;

struct Node{
    int data;
    unique_ptr<Node> left, right;
    Node(int data) : data(data) {};

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

    bool isLeaf(){
        return !left && !right;
    }

    int maxLeafNode(){
        int restLeft=INT_MIN, restRight=INT_MIN;

        if(left) restLeft = left->maxLeafNode();
        if(right) restRight = right->maxLeafNode();
        if(isLeaf()) return data;

        return max(restLeft, restRight);
    }
};

int main() {
    unique_ptr<Node> root = make_unique<Node>(90);
    root->setChild(70, 120)
        ->left->setChild(60, 80);
    
    root->right->setChild(110,130)
        ->left->setLeft(105);

    cout << root->maxLeafNode() << "\n";
    return 0;
}
```

# Editorial
🔥 Jawaban kamu **benar total**, implementasi `maxLeafNode()` elegan dan aman terhadap edge case, serta struktur pohonnya **pas banget** dengan yang diminta. Kita langsung bedah semuanya secara editorial.

---

## ✅ Pemeriksaan Output

### Tree yang kamu bangun:

```

           90
         /    \
       70      120
      /  \     /  \
    60   80  110  130
             /
           105
```

### Leaf nodes:

- `60`, `80`, `105`, `130`  
    Nilai maksimum: **130**
    

Program kamu mencetak:

```
130
```

✅ **Sesuai**

---

## ✍️ Editorial

### Fungsi `isLeaf()`

```cpp
bool isLeaf(){
    return !left && !right;
}
```

- Ini pengecekan daun yang clean dan efisien.
    

---

### Fungsi `maxLeafNode()`

```cpp
int maxLeafNode(){
    int restLeft = INT_MIN, restRight = INT_MIN;

    if(left)  restLeft = left->maxLeafNode();
    if(right) restRight = right->maxLeafNode();
    if(isLeaf()) return data;

    return max(restLeft, restRight);
}
```

### Kenapa ini benar:

- **Base case**: jika `isLeaf()`, langsung kembalikan `data` node itu.
    
- **Recursive case**: jalankan ke kiri dan kanan, dan ambil maksimum dari keduanya.
    
- `INT_MIN` digunakan untuk inisialisasi agar tidak mengganggu saat `max()` dihitung — ini penting, karena jika tidak ada anak kiri misalnya, `restLeft` tetap valid untuk `max`.
    

Ini adalah pendekatan **postorder traversal**, dan **ideal** untuk penggabungan hasil anak-anak.

---

## 🛠 Tree Builder

```cpp
unique_ptr<Node> root = make_unique<Node>(90);
root->setChild(70, 120)
    ->left->setChild(60, 80);

root->right->setChild(110, 130)
    ->left->setLeft(105);
```

- Penulisan ini membuat tree **presisi sesuai soal**
    
- Gaya chaining mempermudah dan mempercepat pembentukan struktur kompleks
    

---

## ✅ Rangkuman

- ✅ Logika benar, hasil benar
    
- ✅ Aman dari bug seperti “tidak ada daun” karena pakai `INT_MIN`
    
- ✅ Gaya `unique_ptr` tetap dijaga, clean memory
    
- ✅ Tree sesuai, traversal efisien
    
