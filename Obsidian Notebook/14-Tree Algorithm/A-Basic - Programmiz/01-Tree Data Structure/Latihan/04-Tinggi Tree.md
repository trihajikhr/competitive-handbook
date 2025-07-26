---
obsidianUIMode: preview
note_type: latihan
latihan: Tinggi Tree
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-29T13:58:00
---
---
# Soal 4: Hitung Tinggi (Height) Tree

Buatlah fungsi `int height(Node* root)` yang mengembalikan **tinggi** (atau kedalaman maksimal) dari sebuah binary tree.

Definisi tinggi:

- Sebuah node tanpa anak memiliki tinggi 1.
    
- Sebuah node dengan anak memiliki tinggi `1 + max(tinggi anak kiri, tinggi anak kanan)`.
    

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

Tingginya adalah:

- `3 → 8 → 5 → 10` = 3 level (jalur terpanjang dari root ke leaf)  
    Jadi hasil: `3`
    

---

Silakan kamu implementasikan fungsinya. Kirimkan hasilnya seperti biasa, nanti aku cek dan beri editorialnya. Semangat!

# Jawabanku

Berikut adalah jawabanku untuk menyelesaikan tantangan ini:

```cpp
#include<iostream>
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

    bool isLeaf(){
        return (!left && !right);
    }

    int treeHeight(int lvl=1){
        int restLeft=0, restRigth=0;
        if(left)  restLeft=left->treeHeight(lvl+1);
        if(right) restRigth=right->treeHeight(lvl+1);
        if(isLeaf()) return lvl;
        return max(lvl, max(restLeft, restRigth));
    }
};

int main() {
    unique_ptr<Node> root = make_unique<Node>(10);
    root->setChild(5,20)->left->setChild(3,8);

    cout << root->treeHeight() << "\n";
    return 0;
}
```

## Perbaikan minor
Aku membuat fungsi untuk mencari nilai height dengan cara berikut:

```cpp
bool isLeaf(){
	return (!left && !right);
}

int treeHeight(int lvl=1){
	int restLeft=0, restRigth=0;
	if(left)  restLeft=left->treeHeight(lvl+1);
	if(right) restRigth=right->treeHeight(lvl+1);
	if(isLeaf()) return lvl;
	return max(lvl, max(restLeft, restRigth));
}
```

Tapi, ada cara yang lebih  efisien, cara itu ditunjukan di pembahasan editorial, yaitu seperti ini:

```cpp
int height() {
    int hl = left ? left->height() : 0;
    int hr = right ? right->height() : 0;
    return 1 + max(hl, hr);
}
```


# Editorial
🔥 Kode kamu **benar** dan berhasil menghitung tinggi tree sesuai definisi yang tepat! Tapi yang paling menarik: kamu pakai parameter `lvl` untuk melacak level saat ini — ini gaya yang jarang dipakai tapi sangat _powerful_ kalau dipahami.

Mari kita bedah seperti biasa.

---

## ✅ Pemeriksaan Output

Tree:

```

      10        ← level 1
     /  \
    5   20      ← level 2
   / \
  3   8         ← level 3
```

Tinggi (dari root ke daun terdalam): **3**

Program mencetak `3` ✅

---

## 🧠 Editorial

### Fungsi `treeHeight(int lvl = 1)`

```cpp
int treeHeight(int lvl=1){
    int restLeft=0, restRigth=0;
    if(left)  restLeft=left->treeHeight(lvl+1);
    if(right) restRigth=right->treeHeight(lvl+1);
    if(isLeaf()) return lvl;
    return max(lvl, max(restLeft, restRigth));
}
```

#### Penjelasan:

- `lvl` melacak seberapa dalam node saat ini.
    
- Jika node adalah **leaf**, kamu return level itu (`lvl`).
    
- Untuk node bukan leaf, kamu cari nilai maksimum antara kiri dan kanan, karena height = jalur terdalam.
    

🔍 Catatan kecil:

- Variabel `restRigth` → ada typo dikit, harusnya `restRight`, tapi tidak memengaruhi hasil.
    

---

## 🎓 Catatan Tambahan (Gaya Alternatif)

Biasanya, fungsi `height()` ditulis tanpa parameter dan seperti ini:

```cpp
int height() {
    int hl = left ? left->height() : 0;
    int hr = right ? right->height() : 0;
    return 1 + max(hl, hr);
}
```

Tapi pendekatanmu (dengan `lvl`) **juga benar**, dan bahkan lebih fleksibel kalau kita ingin tahu level spesifik selama traversal.

---

## ✅ Rangkuman

- ✅ Logika benar, hasil benar
    
- ✅ Gaya traversal dengan level manual kreatif dan efektif
    
- ✅ Gaya chaining tetap konsisten
    
- 🟡 Minor: typo nama variabel `restRigth`
    
