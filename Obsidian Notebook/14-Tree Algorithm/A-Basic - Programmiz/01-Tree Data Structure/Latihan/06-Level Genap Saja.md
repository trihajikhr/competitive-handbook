---
obsidianUIMode: preview
note_type: latihan
latihan: Level Genap Saja
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-29T14:40:00
---
---
# Soal 6: Preorder Traversal Level Genap Saja

Buatlah fungsi `void getPreorderEvenLevel(Node* root, vector<int>& result, int level = 1)`  

yang melakukan traversal preorder (akar → kiri → kanan), **tapi hanya menyimpan data dari node yang berada di level genap saja**.

---

#### Contoh:

Untuk tree:

```

          50            ← level 1
        /    \
      30      70        ← level 2
     /  \     / \
   20   40  60  90      ← level 3
         /
       35              ← level 4

```

Untuk tree di atas, node pada level genap adalah:

- Level 2 → `30`, `70`
    
- Level 4 → `35`
    

Jadi output `result` harus berisi: `{30, 70, 35}`  

Urutannya berdasarkan **preorder**: akar dulu, lalu kiri, lalu kanan, tetapi hanya **menyimpan jika level genap**.

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

    void getVecPreorder(vector<int>& vec, int lvl=1){
        if(lvl %2==0) vec.push_back(data);
        if(left) left->getVecPreorder(vec, lvl+1);
        if(right) right->getVecPreorder(vec, lvl+1);
    }
};

int main() {
    unique_ptr<Node> root = make_unique<Node>(50);
    root->setChild(30,70)->left->setChild(20,40)->right->setRight(35);
    root->right->setChild(60,90);

    vector<int> rest; root->getVecPreorder(rest);
    for(const auto& x: rest){
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
```

# Editorial
🔥 Mantap! Jawaban kamu **benar** dan pohon yang kamu bangun juga **sesuai instruksi**. Fungsi preorder-nya juga tepat sasaran: hanya memasukkan nilai dari node yang berada di level genap saja. Sekarang kita bahas editorialnya satu per satu.

---

## ✅ Pemeriksaan Output

Tree yang kamu bangun:

```

            50            ← level 1
           /   \
         30     70        ← level 2
        /  \   /  \
      20   40 60  90      ← level 3
              /
            35            ← level 4
```

### Traversal preorder (genap level only):

Urut preorder:

- `50` (lvl 1) → skip
    
- `30` (lvl 2) → ✅ ambil
    
- `20` (lvl 3) → skip
    
- `40` (lvl 3) → skip
    
- `35` (lvl 4) → ✅ ambil
    
- `70` (lvl 2) → ✅ ambil
    
- `60`, `90` (lvl 3) → skip
    

Jadi output: `30 35 70` ✅

Dan programmu mencetak:

```
30 35 70
```

✅ **Benar**

---

## 🧠 Editorial

### Fungsi `getVecPreorder(...)`

```cpp
void getVecPreorder(vector<int>& vec, int lvl=1){
    if(lvl % 2 == 0) vec.push_back(data);
    if(left) left->getVecPreorder(vec, lvl + 1);
    if(right) right->getVecPreorder(vec, lvl + 1);
}
```

### Kenapa ini benar:

- Traversal **preorder** tetap dipertahankan (akar → kiri → kanan)
    
- Tapi hanya `push_back()` jika `lvl % 2 == 0`
    
- Level dihitung secara eksplisit melalui parameter `lvl`, dimulai dari `1` di `main()`
    

Cerdas dan rapi 💡

---

### Tree Builder

```cpp
root->setChild(30,70)
    ->left->setChild(20,40)
          ->right->setRight(35);
root->right->setChild(60,90);
```

- Kamu membentuk tree persis seperti soal
    
- Gaya chaining-nya konsisten dan ekspresif
    

---

## ✅ Rangkuman

- ✅ Fungsi preorder dengan filter level **berfungsi sempurna**
    
- ✅ Tree dibangun dengan tepat sesuai instruksi
    
- ✅ Hasil output benar: `{30, 35, 70}`
    
- ✅ Struktur kode bersih dan efisien
    
