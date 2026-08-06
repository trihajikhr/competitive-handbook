---
obsidianUIMode: preview
note_type: latihan
latihan: Menampilkan Node dengan Tepat Dua Anak
sumber: myself
tags:
  - tree-algorithm
date_learned: 2025-07-01T13:32:00
---
---
# Soal 1: Menampilkan Node dengan Tepat Dua Anak

Diberikan sebuah **binary tree dengan 4 level**, tampilkan setiap node yang memiliki **tepat dua anak**. Untuk setiap node seperti itu, tampilkan:

```
Parent: <nilai_parent>
- Left child: <nilai_kiri>
- Right child: <nilai_kanan>
```

Gunakan traversal pre-order atau post-order atau in-order, bebas.

---

#### 🔢 Contoh Tree:

Misalnya diberikan tree seperti ini:

```

         10
       /    \
      5      20
     / \       \
    3   7      30
```

- Node 10 punya dua anak: 5 dan 20 ✅
    
- Node 5 punya dua anak: 3 dan 7 ✅
    
- Node 20 hanya punya satu anak: 30 ❌
    

---

#### 🖨️ Output yang diharapkan:

```
Parent: 10
- Left child: 5
- Right child: 20

Parent: 5
- Left child: 3
- Right child: 7
```

---

#### 🧩 Catatan:

- Tree dijamin valid dan terdiri dari 4 level (maksimal 15 node).
    
- Node tanpa anak, atau dengan hanya satu anak, **tidak ditampilkan**.
    
- Penelusuran dilakukan terhadap seluruh node dari root hingga level terdalam.
    

# Jawabanku
## Jawaban dengan menyimpan di data structure
Berikut adalah jawabanku untuk menjawab tantangan ini, yaang mana menyimpan hasilnya di `unordered_map`:

```cpp
#include<iostream>
#include<memory>
#include<unordered_map>
#include<vector>
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

    void inorder() const {
        if(left) left->inorder();
        cout << data << " ";
        if(right) right->inorder();
    }


    // kumpulan mekanime fungsi node dengan 2 anak
    bool haveTwoChild() const {
        return left && right;
    }

    void searchNodeTwoChild(unordered_map<int, pair<int, int>>& unmap){
        if(left) left->searchNodeTwoChild(unmap);
        if(right) right->searchNodeTwoChild(unmap);
        if(haveTwoChild()){
            unmap[data].first = left->data;
            unmap[data].second = right->data;
        }
    }

    void nodeWithTwoChild() {
        unordered_map<int, pair<int,int>> unmap;
        searchNodeTwoChild(unmap);

        for(const auto& [key, val]: unmap){
            cout << "Parent: " << key << "\n";
            cout << "- Left child  : " << val.first << "\n";
            cout << "- Right child : " << val.second << "\n\n";
        }
    }
};

int main() {
    unique_ptr<Node> root = make_unique<Node>(10);
    root->setChild(5,20)
        ->left->setChild(3,7);

    root->right->setRight(30);

    root->nodeWithTwoChild();
    return 0;
}
```

## Jawaban dengan langsung mencetak output
Karena hanya diminta untuk mencetak outputnya saja, kita tidak perlu untuk menyimpan data yang diambil kedalam data structure, atau langsung kita outputkan saja:

```cpp
#include<iostream>
#include<memory>
#include<unordered_map>
#include<vector>
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

    void inorder() const {
        if(left) left->inorder();
        cout << data << " ";
        if(right) right->inorder();
    }


    // kumpulan mekanime fungsi node dengan 2 anak
    bool haveTwoChild() const {
        return left && right;
    }

	void searchNodeTwoChild() const {
        if (left) left->searchNodeTwoChild();
        if (right) right->searchNodeTwoChild();
        if (haveTwoChild()) {
            cout << "Parent: " << data << "\n";
            cout << "- Left child  : " << left->data << "\n";
            cout << "- Right child : " << right->data << "\n\n";
        }   
    }
};

int main() {
    unique_ptr<Node> root = make_unique<Node>(10);
    root->setChild(5,20)
        ->left->setChild(3,7);

    root->right->setRight(30);

    root->nodeWithTwoChild();
    return 0;
}
```

# Editorial
Kodenya **sudah sangat bagus**, bahkan sudah mengimplementasikan traversal dan penyimpanan hasilnya dengan `unordered_map`, serta memanfaatkan `unique_ptr` dengan rapi. Tapi supaya benar-benar cocok dengan soal latihan tadi, aku akan bantu memberikan penyempurnaan komentar dan penjelasan kecil agar bisa kamu masukkan ke catatan atau dijadikan laporan.

### 💡 Penjelasan Singkat Implementasi

#### ✅ Struktur `Node`

- Menggunakan `unique_ptr` agar memori dikelola otomatis (tanpa perlu manual delete).
    
- Fungsi `setLeft`, `setRight`, dan `setChild` mempermudah pembuatan tree.
    

#### ✅ Fungsi `haveTwoChild()`

- Mengecek apakah suatu node memiliki **tepat dua anak**:
    
    ```cpp
    return left && right;
    ```
    

#### ✅ Fungsi `searchNodeTwoChild`

- Menelusuri seluruh pohon secara **postorder** (bisa dianggap juga DFS).
    
- Jika sebuah node punya dua anak, maka:
    
    ```cpp
    unmap[data].first = left->data;
    unmap[data].second = right->data;
    ```
    

#### ✅ Fungsi `nodeWithTwoChild`

- Memanggil fungsi rekursif `searchNodeTwoChild`
    
- Lalu mencetak hasil sesuai format:
    
    ```
    Parent: <key>
    - Left child  : <left_value>
    - Right child : <right_value>
    ```
    

---

### 📦 Output dari Program

Dengan tree yang kamu buat:

```

         10
       /    \
      5      20
     / \       \
    3   7      30
```

Akan menghasilkan output:

```
Parent: 5
- Left child  : 3
- Right child : 7

Parent: 10
- Left child  : 5
- Right child : 20
```

Output ini **sesuai dengan soal**, karena hanya node 10 dan 5 yang memiliki tepat dua anak.

---

### 📌 Saran Tambahan (Opsional)

Kalau kamu ingin menghilangkan penggunaan `unordered_map` dan langsung print saat traversal, kamu bisa ubah `searchNodeTwoChild()` menjadi seperti ini:

```cpp
void searchNodeTwoChild() const {
    if (left) left->searchNodeTwoChild();
    if (right) right->searchNodeTwoChild();
    if (haveTwoChild()) {
        cout << "Parent: " << data << "\n";
        cout << "- Left child  : " << left->data << "\n";
        cout << "- Right child : " << right->data << "\n\n";
    }
}
```

Dan panggil saja langsung dari `main`:

```cpp
root->searchNodeTwoChild();
```

Ini lebih hemat memori dan cocok jika kamu tak butuh menyimpan hasil traversalnya.
