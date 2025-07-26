---
obsidianUIMode: preview
note_type: latihan
latihan: Hitung Node Internal
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-29T18:28:00
---
---
# Soal 10: Hitung Node Internal

Buatlah fungsi `int countInternalNodes()`  
yang mengembalikan jumlah **node internal**, yaitu:

- Node yang **bukan daun** (leaf)
    
- Dan **bukan nullptr**
    

---

#### Gunakan Tree Berikut:

```

           40
         /    \
       20      60
      /  \       \
    10   30      70
                 /
               65
```

---

### Penjelasan:

- Node internal = node yang punya minimal satu anak
    
- Dalam tree ini:
    
    - `40` → punya dua anak ✅
        
    - `20` → punya dua anak ✅
        
    - `60` → punya satu anak ✅
        
    - `70` → punya satu anak ✅
        
- Node `10`, `30`, `65` → daun ❌
    

✅ Total internal node = **4**

---

Silakan implementasikan:

- Tree-nya
    
- Fungsi `countInternalNodes()`
    
- Cetak hasilnya di `main()`
    

Nanti akan aku periksa dan editorialin kayak biasanya!

# Jawabanku
Berikut adalah jawabanku untuk menyelesaikan tantangan ini:

```cpp
#include<iostream>
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

    Node* SetChild(int a, int b){
        setLeft(a); setRight(b);
        return this;
    }

    int internalCount() const {
        int cnt=0;

        if(left) cnt += left->internalCount();
        if(right) cnt += right->internalCount();
        if(left || right) cnt++;

        return cnt;
    }
};

int main() {
    unique_ptr<Node> root = make_unique<Node>(40);
    root->SetChild(20,60)
        ->left->SetChild(10,30);
    
    root->right->setRight(70)->setLeft(65);

    cout << root->internalCount() << "\n";
    return 0;
}
```

# Editorial
🔥 KEREN! Kode kamu lagi-lagi **on point**, rapi, dan hasilnya **benar**. Struktur tree-nya tepat sesuai soal, fungsi `internalCount()` kamu sudah menangani semuanya dengan cara yang elegan.

Sekarang kita bahas detailnya satu per satu.

---

## ✅ Pemeriksaan Tree

Tree yang kamu bangun:

```

           40
         /    \
       20      60
      /  \       \
    10   30      70
                 /
               65
```

### Node internal (punya minimal 1 anak):

- `40` → dua anak ✅
    
- `20` → dua anak ✅
    
- `60` → satu anak ✅
    
- `70` → satu anak ✅  
    ➡️ Total = **4**
    

Dan program kamu mencetak:

```
4
```

✅ **Benar**

---

## ✍️ Editorial

### Fungsi `internalCount()`

```cpp
int internalCount() const {
    int cnt = 0;
    if(left) cnt += left->internalCount();
    if(right) cnt += right->internalCount();
    if(left || right) cnt++;
    return cnt;
}
```

- Rekursif ke `left` dan `right` seperti biasa
    
- `if(left || right)` artinya: node saat ini **bukan leaf** → dihitung
    
- Tidak menghitung `nullptr`, dan tidak menghitung daun
    
- Implementasi yang **ringkas dan jelas**
    

---

### Tree Builder

```cpp
unique_ptr<Node> root = make_unique<Node>(40);
root->SetChild(20,60)
    ->left->SetChild(10,30);
    
root->right->setRight(70)->setLeft(65);
```

- Kamu memakai `SetChild(...)` (dengan kapital `S`) — aman, tidak bentrok dengan `setChild` lainnya
    
- Chaining kamu rapi dan ekspresif
    
- Teknik “checkpoint” kamu gunakan juga pada `->right->setRight(...)` → smart!
    

---

## ✅ Rangkuman

|Komponen|Status|
|---|---|
|Struktur tree|✅ Benar|
|Fungsi `internalCount()`|✅ Benar|
|Output|✅ Benar (4)|
|Gaya penulisan|✅ Clean dan modern|
|Error/runtime?|✅ Aman dan stabil|

---

Kalau kamu siap, kita lanjut ke **Soal ke-11**. Yang ini bakal melibatkan **membandingkan tinggi subtree kiri dan kanan** — cocok buat simulasi keseimbangan. Gas?