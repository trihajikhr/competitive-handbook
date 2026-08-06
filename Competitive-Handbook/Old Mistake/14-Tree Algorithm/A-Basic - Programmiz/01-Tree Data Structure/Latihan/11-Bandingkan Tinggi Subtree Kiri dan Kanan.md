---
obsidianUIMode: preview
note_type: latihan
latihan: Bandingkan Tinggi Subtree Kiri dan Kanan
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-29T18:37:00
---
---
# Soal 11: Bandingkan Tinggi Subtree Kiri dan Kanan

Buatlah fungsi:

```cpp
int height() const;
string compareSubtreeHeight() const;
```

- Fungsi `height()` menghitung tinggi dari tree (level maksimum dari akar ke daun)
    
- Fungsi `compareSubtreeHeight()` akan:
    
    - Mengembalikan `"LEFT"` jika subtree kiri **lebih tinggi**
        
    - Mengembalikan `"RIGHT"` jika subtree kanan **lebih tinggi**
        
    - Mengembalikan `"EQUAL"` jika keduanya **sama tinggi**
        

---

#### Tree yang Digunakan:

```

           10
         /    \
       5       15
      /         \
     3           20
                  \
                  25
```

---

### Penjelasan:

- Tinggi subtree kiri (dari 5) = 2 (5 → 3)
    
- Tinggi subtree kanan (dari 15) = 3 (15 → 20 → 25)
    
- Maka hasil dari `compareSubtreeHeight()` = `"RIGHT"`
    

---

Silakan implementasikan:

- `height()` pada `Node`
    
- `compareSubtreeHeight()` pada `Node`
    
- Cetak hasil `compareSubtreeHeight()` dari root di `main()`
    

Setelah kamu kirim, langsung aku cek dan editorialin!

# Jawabanku
Berikut adalah jawabanku untuk menyelesaikan tantangan ini, tapi sudah ditambah sedikit perbaikan dari evaluasi editorial:

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

    Node* setChild(int a, int b){
        setLeft(a); setRight(b);
        return this;
    }

    int height() const {
        int hl = left ? left->height() : -1;
        int hr = right ? right->height() : -1;
        return 1 + max(hl, hr);
    }

    string compareSubtreeHeight() const {
		int restLeft = left ? left->height() : -1;
		int restRight = right ? right->height() : -1;

        if(restLeft > restRight) return "LEFT";
        else if (restLeft < restRight) return "RIGHT";
        else return "EQUAL";
    }
};

int main() {
    unique_ptr<Node> root = make_unique<Node>(10);
    root->setChild(5,15)->left->setLeft(3);
    root->right->setRight(20)->setRight(25);

    string rest = root->compareSubtreeHeight();
    cout << rest << "\n";
    return 0;
}
```

# Editorial
🚀 **PERFECT!** Jawabanmu benar total, akurat, dan kamu bahkan menangani edge case tinggi dengan gaya yang cerdas. Yuk langsung kita bahas seperti biasa:

---

## ✅ Struktur Tree-mu

```

           10
         /    \
       5       15
      /          \
     3            20
                     \
                     25
```

### Tinggi subtree:

- Subtree kiri (5 → 3): `2`
    
- Subtree kanan (15 → 20 → 25): `3`  
    ✅ Maka hasil `compareSubtreeHeight()` harus `"RIGHT"`
    

Program kamu mencetak:

```
RIGHT
```

✅ **Benar!**

---

## ✍️ Editorial

### Fungsi `height()`

```cpp
int height() const {
    int hl = left ? left->height() : -1;
    int hr = right ? right->height() : -1;
    return 1 + max(hl, hr);
}
```

💡 **Kenapa pakai `-1`?**

- Supaya:
    
    - Jika node **tidak punya anak**, `height()` = `0` (karena `1 + max(-1, -1)`)
        
    - Jika ada satu anak, tetap naik 1 level
        
- Ini definisi tinggi yang **umum dipakai** di teori tree (tinggi node daun = 0)
    

✅ Ini desain yang presisi, cocok untuk banyak algoritma balance-check.

---

### Fungsi `compareSubtreeHeight()`

```cpp
string compareSubtreeHeight() const {
    int restLeft = left->height();
    int restRight = right->height();

    if(restLeft > restRight) return "LEFT";
    else if (restLeft < restRight) return "RIGHT";
    else return "EQUAL";
}
```

⚠️ Di sini kamu **tidak melakukan pengecekan `if(left)` dan `if(right)`** sebelum akses `left->height()`.

Tapi karena di `main()` kamu sudah membangun keduanya, maka program **tetap jalan**.

### 🛡️ Supaya lebih tahan banting:

```cpp
int restLeft = left ? left->height() : -1;
int restRight = right ? right->height() : -1;
```

---

## ✅ Rangkuman

|Hal|Status|
|---|---|
|Struktur tree|✅ Sesuai soal|
|Fungsi `height()`|✅ Akurat dan logis|
|Fungsi `compareSubtreeHeight()`|✅ Memberi hasil `"RIGHT"`|
|Clean dan aman?|⚠️ Hampir, bisa tambah pengecekan null|
|Output|✅ Sesuai|

---

Kalau kamu siap, kita gas ke **Soal ke-12**! Kali ini kita akan main dengan **jumlah nilai semua node yang berada di level tertentu**, misalnya level ke-3. Mau lanjut?