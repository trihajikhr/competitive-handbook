---
obsidianUIMode: preview
note_type: latihan
latihan: Jumlah Node di Level Ganjil
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-29T15:05:00
---
---
# Soal 7: Jumlah Nilai Node di Level Ganjil

Buatlah fungsi `int sumOddLevel(Node* root, int level = 1)`  
yang mengembalikan jumlah semua nilai node yang berada di **level ganjil** saja (level 1, 3, 5, dst).

---

#### Gunakan Tree Ini:

```

          100           ← level 1
         /   \
       50     150       ← level 2
      /  \     \
    25   75    200      ← level 3
         /            ←
       60             ← level 4
```

---

### Target Output:

Node di level ganjil:

- Level 1: `100`
    
- Level 3: `25`, `75`, `200`
    

Total = `100 + 25 + 75 + 200 = 400`

---

Silakan implementasikan tree tersebut dan fungsi `sumOddLevel()`. Kirimkan ke sini, nanti langsung aku cek dan kupas editorialnya seperti biasa!

# Jawabanku
Berikut adalah jawabanku untuk menyelesaikan tantangan ini:

```cpp
#include<iostream>
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

    int sumOddLevel(int lvl=1){
        int sum = 0;

        if(left) sum += left->sumOddLevel(lvl+1);
        if(right) sum += right->sumOddLevel(lvl+1);
        if(lvl%2!=0) sum+=data;

        return sum;
    }
};

int main() {
    unique_ptr<Node> root = make_unique<Node>(100);
    root->setChild(50,150)
        ->left->setChild(25,75)
            ->right->setLeft(60);
    root->right->setRight(200);

    cout << root->sumOddLevel() << "\n";
    return 0;
}
```

# Editorial
🔥 Mantap lagi! Jawabanmu benar secara logika, struktur tree yang kamu bangun **persis** seperti soal, dan implementasi fungsi `sumOddLevel()` juga tepat sasaran.

Sekarang kita kupas tuntas seperti biasa supaya makin mantap!

---

## ✅ Pemeriksaan Tree

Kamu membangun tree seperti ini:

```

           100            ← level 1
         /     \
       50       150       ← level 2
      /  \         \
    25   75       200     ← level 3
         /
       60                  ← level 4
```

### Node di level ganjil:

- Level 1: `100`
    
- Level 3: `25`, `75`, `200`
    

Total: `100 + 25 + 75 + 200 = 400`

Keluaran program kamu:

```
400
```

✅ **Benar**

---

## ✍️ Editorial

### Fungsi `sumOddLevel(int lvl = 1)`

```cpp
int sumOddLevel(int lvl=1){
    int sum = 0;

    if(left) sum += left->sumOddLevel(lvl+1);
    if(right) sum += right->sumOddLevel(lvl+1);
    if(lvl % 2 != 0) sum += data;

    return sum;
}
```

#### Kenapa ini benar:

- Traversal **postorder**, tapi posisi `if(lvl % 2 != 0)` di akhir tidak masalah karena kamu tidak memanipulasi anaknya.
    
- Penjumlahan `sum += data` hanya terjadi jika level ganjil.
    
- `lvl` dikelola secara rekursif lewat parameter → ini pattern yang konsisten dari soal-soalmu sebelumnya.
    

---

## 🔨 Tree Builder Kamu

```cpp
root->setChild(50,150)
    ->left->setChild(25,75)
        ->right->setLeft(60);
root->right->setRight(200);
```

- Gaya chaining masih dipertahankan dan membuat kode tetap ringkas.
    
- Struktur tree sudah **presisi** seperti yang diminta.
    

---

## ✅ Rangkuman

- ✅ Logika traversal dan seleksi level **sangat akurat**
    
- ✅ Tree dibangun dengan rapi sesuai skema soal
    
- ✅ Output: 400 — sesuai harapan
    
- ✅ Tidak ada kebocoran memori karena penggunaan `unique_ptr`
    
