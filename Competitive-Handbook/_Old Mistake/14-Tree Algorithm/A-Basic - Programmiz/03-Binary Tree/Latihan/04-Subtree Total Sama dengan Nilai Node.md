---
obsidianUIMode: preview
note_type: latihan
latihan: Subtree Total Sama dengan Nilai Node
sumber: myself
tags:
  - tree-algorithm
date_learned: 2025-07-01T20:16:00
---
---
Keren! Tantangan pertama ini **lumayan tricky**, karena kita perlu menghitung **jumlah seluruh node dalam subtree**, lalu cocokkan dengan nilai node itu sendiri. Tapi kamu pasti bisa 🚀

# Soal 4: Subtree Total Sama dengan Nilai Node

Diberikan sebuah **binary tree**, carilah semua node yang memiliki **subtree total** (jumlah semua node di bawahnya termasuk anak-anak dan cucu-cucunya) yang **sama dengan nilai node itu sendiri**.
#### 📥 Input:

Masih dengan format triplet:

```
parent child side
```

Semua nilai node adalah bilangan bulat.
#### 📤 Output:

Untuk setiap node yang memenuhi syarat, tampilkan:

```
Node: X | Subtree Total: Y
```
#### 🔍 Penjelasan:

Subtree total dari sebuah node dihitung sebagai **jumlah semua nilai node di bawahnya (left dan right), tapi TIDAK termasuk dirinya sendiri**.

Jika total itu **sama dengan nilai node**, maka node tersebut valid.
#### 📌 Contoh Input:

```
4
10 3 L
10 7 R
3 1 L
3 2 R
```

Pohon yang terbentuk:

```

      10
     /  \
    3    7
   / \
  1   2
```

- Node 3 → anak: 1 + 2 = **3** ✅
    
- Node 10 → 3 + 1 + 2 + 7 = **13** ❌
    
- Node 7 → tidak punya anak → total = 0 ≠ 7 ❌
    
#### 📤 Contoh Output:

```
Node: 3 | Subtree Total: 3
```

# Jawabanku
Berikut adalah jawabanku untuk menyelesaikan tantangan ini, dan kode ini sudah cukup optimal:

```cpp
#include<iostream>
#include<memory>
using namespace std;

template <typename T>
struct Node {
    T data;
    unique_ptr<Node<T>> left, right;
    Node(T data) : data(data) {}

    Node* setLeft(T val){
        left = make_unique<Node<T>>(val);
        return left.get();
    }
    
    Node* setRight(T val){
        right = make_unique<Node<T>>(val);
        return right.get();
    }
    Node* setChild(T a, T b){
        setLeft(a); setRight(b);
        return this;
    }

    void traverse() const {
        if(left) left->traverse();
        cout << data << " ";
        if(right) right->traverse();
    }

    int sumSubTree() const {
        int sum=0;
        if(left) sum += left->sumSubTree();
        if(right) sum += right->sumSubTree();
        sum+=data;
        return sum;
    }

    void sameSubtree() const {
        int x = sumSubTree() - data;
        if(x == data){
            cout << "Node: " << data << " | "
            << "Subtree Total: " << x << "\n";
        }

        if(left) left->sameSubtree();
        if(right) right->sameSubtree();
    }

    bool insertNodes(T parent, T child, T post){
        if(parent == data){
            if(post == 'L') setLeft(child);
            else setRight(child);
            return true;
        }

        bool inserted = false;
        if(left) inserted |= left->insertNodes(parent, child, post);
        if(right) inserted |= right->insertNodes(parent, child, post);
        return inserted;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unique_ptr<Node<int>> root;
    int n; cin >> n;

    for(int i=0; i<n; i++){
        int a,b; char x;
        cin >> a >> b >> x;

        if(i==0){
            root = make_unique<Node<int>>(a);
            if(x=='L') root->setLeft(b);
            else root->setRight(b);
        } else root->insertNodes(a,b,x);
    }

    root->sameSubtree();
    return 0;
}
```

# Editorial
🔥 **Mantap! Kode kamu udah TEPAT untuk menyelesaikan soal 4.** Berikut review menyeluruh untuk memastikan kamu benar-benar paham dan tahu kalau ini udah sangat solid:

---

## ✅ Apa yang Sudah Bagus

1. `sumSubTree()` berjalan rekursif dan mengembalikan total nilai seluruh subtree termasuk dirinya sendiri.  
   
    Kamu lalu kurangi `data` supaya hanya dapat jumlah anak-cucu, bukan dirinya sendiri. → ✅ Cerdas!
    
2. **Fungsi `sameSubtree()`** sangat tepat:
    
    - Mengecek `sumSubTree() - data == data`.
        
    - Menampilkan format yang informatif dan sesuai soal.
        
    - Rekursi ke kiri dan kanan dengan aman.
        
3. `insertNodes()` memakai pendekatan efisien dengan `bool inserted` dan short-circuit OR.
    
4. Struktur main() clean dan modular. Gampang dibaca dan dipahami.
    

---

## ✅ Output Contoh

Untuk input:

```
4
10 3 L
10 7 R
3 1 L
3 2 R
```

Output:

```
Node: 3 | Subtree Total: 3
```

💯 Sesuai harapan!

---

## ⚠️ Catatan Opsional (Jika Mau Lebih Kuat)

> Ini sudah diperbaiki!

1. **Validasi Root di `main()`**  
    Kamu langsung panggil `root->insertNodes()` meskipun `i==0`. Padahal bisa disimpan di `else` agar lebih bersih:
    
    ```cpp
    if(i == 0){
        root = make_unique<Node<int>>(a);
        if(x == 'L') root->setLeft(b);
        else root->setRight(b);
    } else {
        root->insertNodes(a, b, x);
    }
    ```
    
2. **Kasus ekstrem (subtree kosong)**  
    Sudah tertangani dengan baik karena kamu hanya menampilkan jika `x == data`, dan subtree tanpa anak akan otomatis `0`.
    

---

## 🚀 Tantangan Selanjutnya? (Opsional)

Kalau kamu masih semangat, ini beberapa level lanjut:

- Cari semua daun (leaf) dan hitung totalnya.
    
- Tentukan "level terjauh" (depth maksimum) dari root.
    
- Cari node yang merupakan "kakek" (memiliki cucu), dan tampilkan semua cucunya.
    

Kalau kamu tertarik, tinggal bilang "lanjut", dan kita gas soal ke-5 😄