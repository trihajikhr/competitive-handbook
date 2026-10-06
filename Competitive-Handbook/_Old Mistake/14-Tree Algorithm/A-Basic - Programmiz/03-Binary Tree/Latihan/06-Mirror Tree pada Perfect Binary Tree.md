---
obsidianUIMode: preview
note_type: latihan
latihan: Mirror Tree pada Perfect Binary Tree
sumber: myself
tags:
  - tree-algorithm
date_learned: 2025-07-01T23:19:00
---
---
# Level 6: Mirror Tree pada Perfect Binary Tree

#### 📌 Deskripsi:

Diberikan sebuah **perfect binary tree**, yaitu tree yang:

- Semua level **penuh**, dan
    
- Setiap node **punya 0 atau 2 anak**.
    

Tugasmu adalah menentukan apakah tree tersebut adalah **mirror dari dirinya sendiri**, artinya:

> Untuk setiap pasangan node di kiri dan kanan, nilai dan strukturnya **harus simetris secara horizontal**.

---

### 📥 Input Format:

Tree dibangun dari `n` baris input:

```
parent child side
```

- `parent` dan `child` adalah bilangan bulat.
    
- `side` adalah `'L'` atau `'R'` untuk kiri/kanan.
    

**Jumlah node = 2^h - 1** untuk pohon penuh setinggi `h`. Misalnya:

- Tinggi 3 → 7 node
    
- Tinggi 4 → 15 node
    

---

### 📤 Output:

- Jika tree merupakan mirror: `YES`
    
- Jika tidak: `NO`
    

---

### ✅ Contoh Input (Perfect & Mirror):

```
6
1 2 L
1 2 R
2 3 L
2 4 R
2 4 L
2 3 R
```

Tree:

```

       1
     /   \
    2     2
   / \   / \
  3  4  4   3
```

**Output:**

```
YES
```

---

### ❌ Contoh Input (Perfect but Not Mirror):

```
6
1 2 L
1 2 R
2 3 L
2 5 R
2 4 L
2 3 R
```

Tree:

```

       1
     /   \
    2     2
   / \   / \
  3  5  4   3
```

**Output:**

```
NO
```

# Jawabanku
Ada beberapa hal yang cukup menantang disini. Jika aku menggunakan fungsi `insertNodes()` untuk menyimpan node dengan parent tertentu dan posisi tertentu, maka akan terjadi kesalaha!

Kesalahan ini disebabkan oleh adanya node duplikat atau node yang sama pada tree, sehingga pencarian node tertentu untuk menaruh node yang diinsert berdasarkan parent dan posisi akan berakhir dengan kesalaahan.

Ada beberapa cara untuk mengatasi ini, seperti:
- Menggunakan bantuan ID untuk parent child, dan nodes
- Menggunakan inputan array

Karena aku belum belajar menggunakan bantuan ID pada nodes, maka aku memilih menggunakan inputan array. 

Inputan array mengharuskan user memasukan inputan seperti ini:

```bash
7
1 2 2 3 4 4 3
```

Ini artinya ada 7 inputan, dan 7 nodes yang dibuat, yang mana berdasrkan inputan tersebut, akan dibuat tree seperti ini:

```

          1
        /   \
      2       2
     / \     / \
    3   4   4   3
```

Sehingga, jika merujuk ke tantangan kali ini, maka berikut contoh input dan outputnya:

Contoh 1:
```
7
1 2 2 3 4 4 3
```

```
YES
```

Contoh 2:
```
7
1 2 2 3 4 3 4
```

```
NO
```

> Inputan yang diminta pertama kali masih dipertahankan, untuk peningkatan metode penerimaan inputan selanjutnya!
---

Berikut jawabanku untuk menjawab tantangan ini:

```cpp
#include<iostream>
#include<memory>
#include<unordered_map>
#include<vector>
#include<queue>
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

    bool insertNodes(T parent, T child, T post) {
        if(parent == data){
            if(post == 'L') setLeft(child);
            else setRight(child);
            return true;
        }

        bool inserted=false;
        if(left) inserted |= left->insertNodes(parent, child, post);
        if(right) inserted |= right->insertNodes(parent, child, post);
        return inserted;
    }

    void getLevel(unordered_map<T, vector<T>>& levelMap) const {
        queue<pair<const Node<T>*, T>> q;
        q.push({this, 0});

        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();

            levelMap[level].push_back(node->data);

            if (node->left) q.push({node->left.get(), level + 1});
            if (node->right) q.push({node->right.get(), level + 1});
        }
    }


    bool getMirror() {
        unordered_map<int, vector<T>> levelMap;
        getLevel(levelMap);

        for (auto& [level, nodes] : levelMap) {
            int n = nodes.size();
            for (int i = 0; i < n / 2; ++i) {
                if (nodes[i] != nodes[n - i - 1]) {
                    return false;
                }
            }
        }
        return true;
    }

    static unique_ptr<Node<T>> buildCompleteTree(const vector<int>& A, int idx = 0) {
        if (idx >= A.size() || A[idx] == -1) return nullptr;

        unique_ptr<Node<T>> node = make_unique<Node<T>>(A[idx]);
        node->left = buildCompleteTree(A, 2 * idx + 1);
        node->right = buildCompleteTree(A, 2 * idx + 2);
        return node;
    }

};

int main() {
    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    unique_ptr<Node<int>> root;
    int n; cin >> n;
    vector<int> vec(n);
    for(auto& x : vec){
        cin >> x;
    }

    root = Node<int>::buildCompleteTree(vec);

    root->traverse();
    if(root->getMirror()) cout << "YES";
    else cout << "NO";

    /*
    for(int i=0; i<n; i++){
        int a,b; char x;
        cin >> a >> b >> x;
        if(i==0){
            root = make_unique<Node<int>>(a);
            if(x=='L') root->setLeft(b);
            else root->setRight(b);
        } else root->insertNodes(a,b,x);
    }
    
    if(root->getMirror()) cout << "YES";
    else cout << "NO";
    */

    
    return 0;
}
```

# Editorial

Diberikan sebuah **perfect binary tree**, tentukan apakah tree tersebut merupakan **mirror terhadap dirinya sendiri**, yaitu:

> Untuk setiap node, anak kirinya harus memiliki **nilai dan struktur yang simetris** dengan anak kanan pada posisi yang berlawanan.

---

## 🎯 Tujuan

Cek apakah seluruh isi tree secara horizontal simetris dari kiri dan kanan.

---

## 📥 Format Input

1. Baris pertama: `n` – jumlah elemen di array (jumlah node).
    
2. Baris kedua: `n` bilangan bulat – elemen-elemen node dalam urutan level-order.  
    (Node kosong bisa dilambangkan dengan `-1`, meskipun dalam kasus perfect tree tidak digunakan.)
    

---

## 📤 Format Output

- Cetak `YES` jika tree adalah mirror secara nilai.
    
- Cetak `NO` jika tidak.
    

---

## 🧠 Strategi Penyelesaian

### 1. Bangun Tree dari Array

Karena input diberikan dalam bentuk array `level-order`, kita bisa membangun tree dengan cara rekursif:

- Index parent di `i`
    
- Anak kiri di `2*i + 1`
    
- Anak kanan di `2*i + 2`
    

### 2. Ambil Node Berdasarkan Level (Level-order Traversal)

Kita lakukan **level-order traversal** (BFS) menggunakan `queue`, dan menyimpan semua node ke dalam `unordered_map<int, vector<int>>`, dengan:

- key = level ke-berapa
    
- value = list node pada level itu
    

### 3. Cek Simetri di Tiap Level

Untuk setiap level:

- Ambil vector node-nya
    
- Bandingkan node kiri dan kanan (mirror position)
    
    - Jika ada satu yang beda → `return false`
        
    - Kalau semua sama di semua level → `return true`
        

---

## 🔧 Struktur Program

### Fungsi Utama:

- `buildCompleteTree()` → membangun binary tree dari array level-order.
    
- `getLevel()` → mengisi `unordered_map` dengan isi tree berdasarkan level.
    
- `getMirror()` → mengecek apakah tiap level simetris secara horizontal.
    

---

## 🧪 Contoh Kasus

### Input:

```
7
1 2 2 3 4 4 3
```

### Tree yang Dibentuk:

```

        1
      /   \
    2       2
   / \     / \
  3   4   4   3
```

### Output:

```
YES
```

---

## ✅ Kelebihan Solusi Ini

- 🎯 Efisien → hanya satu traversal untuk membangun dan satu untuk mengecek.
    
- 💡 Modular → fungsi-fungsinya reusable dan terpisah dengan baik.
    
- 🔁 Bisa diskalakan → mudah diperluas ke tree yang lebih besar.
    
- 💥 Menghindari bug pointer duplikat karena tidak pakai pencarian berdasarkan nilai.
    

---

## 🧩 Kemungkinan Perluasan Soal

1. Mengizinkan `-1` sebagai node kosong → jadi tidak hanya perfect binary tree.
    
2. Menambahkan pengecekan **struktur**, bukan hanya nilai.
    
3. Menemukan node yang tidak simetris.
    
4. Menambahkan pembalikan mirror ke tree yang tidak mirror.
    

---

## 💻 Cuplikan Kode Utama (Simplifikasi)

```cpp
bool getMirror() {
    unordered_map<int, vector<T>> levelMap;
    getLevel(levelMap);

    for (auto& [level, nodes] : levelMap) {
        int n = nodes.size();
        for (int i = 0; i < n / 2; ++i) {
            if (nodes[i] != nodes[n - i - 1]) return false;
        }
    }
    return true;
}
```

---

## 🏁 Penutup

Soal ini menekankan pentingnya:

- Pemahaman struktur binary tree
    
- Traversal berdasarkan level
    
- Pemetaan data ke struktur yang tepat (`unordered_map`, `vector`)
    
- Perhatian terhadap pointer dan duplikasi node dalam implementasi tree
    
