---
obsidianUIMode: preview
note_type: latihan
latihan: Simpan Traversal Inorder ke Vector
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-29T14:27:00
---
---
# Soal 5: Simpan Traversal Inorder ke Vector

Buatlah fungsi `void getInorder(Node* root, vector<int>& result)` yang menyimpan hasil **inorder traversal** dari tree ke dalam vector `result`.

Inorder traversal = `kiri → akar → kanan`

---

#### Contoh:

Untuk tree:

```

      10
     /  \
    5   20
   / \
  3   8
  
```

Urutan inorder-nya adalah: `3 5 8 10 20`  
Maka `result` akan berisi: `{3, 5, 8, 10, 20}`

---

Silakan implementasikan! Kirimkan hasilnya seperti biasa, nanti aku periksa dan beri editorial lengkapnya.

# Jawabanku
Berikut adalah jawabanku yang sudah benar:

```cpp
#include<iostream>
#include<vector>
#include<memory>
using namespace std;

struct Node {
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

    void getInorder(vector<int>&vec){
        if(left) left->getInorder(vec);
        vec.push_back(data);
        if(right) right->getInorder(vec);
    }
};

int main() {
    unique_ptr<Node> root = make_unique<Node>(10);
    root->setChild(5,20)->left->setChild(3,8);

    vector<int> rest;
    root->getInorder(rest);

    for(const auto &x: rest){
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
```

# Editorial
💯 Kode kamu **sempurna** untuk soal ini! Traversal inordernya benar, hasilnya disimpan ke dalam `vector<int>`, dan kamu tampilkan hasilnya dengan gaya modern pakai `range-based for loop`. Sekarang seperti biasa, mari kita breakdown.

---

## ✅ Pemeriksaan Output

Tree:

```

      10
     /  \
    5   20
   / \
  3   8
```

Urutan inorder-nya adalah: `3 5 8 10 20`  
Program mencetak:

```
3 5 8 10 20
```

✅ **Benar**

---

## 🧠 Editorial

### Fungsi `getInorder(vector<int>& vec)`

```cpp
void getInorder(vector<int>& vec){
    if(left) left->getInorder(vec);
    vec.push_back(data);
    if(right) right->getInorder(vec);
}
```

#### Kenapa ini benar:

- Rekursi ke anak kiri dulu (`left->getInorder(vec)`)
    
- Lalu push `data` (node saat ini)
    
- Baru lanjut ke anak kanan (`right->getInorder(vec)`)
    

Ini adalah bentuk **inorder traversal klasik** dalam tree binary.

📌 Kamu tidak perlu cek `if(this)` karena fungsi hanya dipanggil dari node yang sudah ada (`root->getInorder(...)`), dan pengecekan anak sudah ditangani.

---

### Penulisan di `main()`

```cpp
vector<int> rest;
root->getInorder(rest);

for(const auto &x: rest){
    cout << x << " ";
}
```

- `vector<int> rest` digunakan sebagai wadah untuk menyimpan hasil traversal
    
- Kamu pakai `const auto&` untuk iterasi — ini modern dan efisien (👍)
    
- Output ditampilkan langsung
    

---

## ✨ Rangkuman

- ✅ Traversal benar dan rapi
    
- ✅ Penyimpanan ke `vector<int>` tepat
    
- ✅ Gaya modern dengan `range-based for`
    
- ✅ Konsisten secara struktur & nama fungsi
    
