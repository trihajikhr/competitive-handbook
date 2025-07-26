---
obsidianUIMode: preview
note_type: latihan
latihan: Lowest Common Ancestor
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-07-06T13:25:00
---
---
# Lowest Common Ancestor (LCA) of Binary Tree
Diberikan sebuah _binary tree_ dan dua nilai node `p` dan `q`, temukan lowest common ancestor (LCA) dari kedua node tersebut.

- LCA dari dua node `p` dan `q` adalah node terdalam yang merupakan ancestor dari `p` dan `q` sekaligus.
    
- Asumsikan:
    
    - Nilai node unik
        
    - Kedua node pasti ada di tree

### 📦 Input Array Level-order:

```
11
3 5 1 6 2 0 8 -1 -1 7 4
```

---

### 🌳 Tree Visualisasi:

```

          3
        /   \
       5     1
      / \   / \
     6   2 0   8
        / \
       7   4
```

- Node `3` adalah root
    
- `5` dan `1` adalah anak kiri-kanan dari `3`
    
- `2` adalah anak kanan dari `5`, dan seterusnya...
    

---

### 📌 Soal:

Jika `p = 5` dan `q = 1`, maka:

- Ancestor dari 5: **3**
    
- Ancestor dari 1: **3**
    
- → **LCA = 3**
    

Jika `p = 7` dan `q = 4`, maka:

- Ancestor dari 7: 2 → 5 → 3
    
- Ancestor dari 4: 2 → 5 → 3
    
- → **LCA = 2**

# Jawabanku
## Jawaban yang masih bisa dioptimalkan
Berikut adalah jawabanku untuk menjawab tantangan ini, yang masih bisa dioptimalkan berdasarkan saran editorial:

```cpp
#include<iostream>
#include<vector>
#include<memory>
using namespace std;

#define UQ unique_ptr<Node<T>>
#define MQ make_unique<Node<T>>

template <typename T>
struct Node {
    T data;
    UQ left, right;
    Node (T data) : data(data) {}

    static UQ buildTrees(vector<T>&vec, int idx=0){
        if(idx >= vec.size() || vec[idx]==-1) return nullptr;
        UQ node = MQ(vec[idx]);
        node->left = buildTrees(vec, 2*idx+1);
        node->right = buildTrees(vec, 2*idx+2);
        return node;
    }

    void trav() const {
        if(left) left->trav();
        cout << data << " ";
        if(right) right->trav();
    }

    bool getPathToNode(vector<T>& vec, T target, vector<T> curr={}) const {
        curr.push_back(data);
        if(target == data){
            vec = curr;
            return true;
        }

        if(left && left->getPathToNode(vec,target,curr)) return true;
        if(right && right->getPathToNode(vec,target,curr)) return true;
        return false;
    }

    int getLCA(T a, T b){
        vector<T> pathA, pathB;
        if(!getPathToNode(pathA, a) || !getPathToNode(pathB, b)){
            cout << "Node tidak ditemukan!";
            exit(0);
        }

        int i = 0, minLen = min(pathA.size(), pathB.size());
        while (i < minLen && pathA[i] == pathB[i]) ++i;

        return pathA[i - 1];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    vector<int> vec(n);
    for(auto&x:vec) cin >> x;
    unique_ptr<Node<int>> root = Node<int>::buildTrees(vec);
    int a,b; cin >> a >> b;

    cout << root->getLCA(a,b);
    return 0;
}
```

## Jawaban yang lebih baik
Berikut adalah jawaban yang lebih baik:

```cpp
#include <iostream>
#include <vector>
#include <memory>
#include <optional>
using namespace std;

#define UQ unique_ptr<Node<T>>
#define MQ make_unique<Node<T>>

template <typename T>
struct Node {
    T data;
    UQ left, right;
    Node(T data) : data(data) {}

    static UQ buildTrees(const vector<T>& vec, int idx = 0) {
        if (idx >= vec.size() || vec[idx] == -1) return nullptr;
        UQ node = MQ(vec[idx]);
        node->left = buildTrees(vec, 2 * idx + 1);
        node->right = buildTrees(vec, 2 * idx + 2);
        return node;
    }

    Node<T>* findLCA(T a, T b) {
        Node<T>* lca = nullptr;
        dfsLCA(this, a, b, lca);
        return lca;
    }

private:
    int dfsLCA(Node<T>* node, T a, T b, Node<T>*& lca) {
        if (!node) return 0;
        int left = dfsLCA(node->left.get(), a, b, lca);
        int right = dfsLCA(node->right.get(), a, b, lca);
        int mid = (node->data == a || node->data == b) ? 1 : 0;
        if (left + right + mid >= 2 && !lca) lca = node;
        return (left + right + mid) > 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto& x : vec) cin >> x;

    int a, b;
    cin >> a >> b;

    auto root = Node<int>::buildTrees(vec);
    auto lca = root->findLCA(a, b);

    if (lca) cout << lca->data << '\n';
    else cout << "Node tidak ditemukan\n";

    return 0;
}

```

# Editorial Perbandingan

> Perbedaan versi pertama dan kedua?

Pertanyaan yang sangat tajam! Mari kita bahas **kenapa versi ini lebih baik** dibanding versi sebelumnya — yang menggunakan pencarian dua path dan membandingkan mereka.

---

## 💡 Pendekatan Sebelumnya: _Path Comparison_

### Cara Kerja:

- Cari path dari root ke `a` (vector A)
    
- Cari path dari root ke `b` (vector B)
    
- Bandingkan kedua path dari awal, node terakhir yang sama → **LCA**
    

### 🔻 Kekurangan:

1. **Dua kali traversal penuh**:
    
    - Harus cari path `a` dan path `b` → 2x DFS di tree
        
2. **Overhead memori**:
    
    - Menyimpan dua vector `pathA`, `pathB` → O(h) memori _dua kali_
        
3. **Banyak salinan `vector<T>` saat rekursi**:
    
    - Pada versi awal kamu menyalin `curr` di setiap rekursi
        
4. **Tidak langsung berhenti**:
    
    - Meski `a` dan `b` sudah ditemukan, traversal terus berjalan (tidak optimal)
        

---

## ✅ Pendekatan Versi Ini: _Post-order DFS Langsung_

### Cara Kerja:

- Satu DFS traversal
    
- Di setiap node, cek:
    
    - Apakah `a` ada di subtree kiri?
        
    - Apakah `b` ada di subtree kanan?
        
    - Atau apakah node saat ini adalah salah satu dari `a` atau `b`?
        
- Jika dua dari tiga kondisi ini terpenuhi → node tersebut adalah **LCA**
    

---

### ✅ Keunggulan:

|Aspek|DFS Langsung|Path Comparison|
|---|---|---|
|**Traversal**|1x DFS|2x DFS minimum|
|**Memori**|O(h) stack (tidak simpan path)|O(h) × 2 vector|
|**Efisiensi**|Lebih cepat dan hemat memori|Cukup cepat, tapi bisa boros|
|**Ekspresi LCA**|Elegan, langsung deteksi saat traversal|Deteksi setelah dua path selesai|
|**Early Stopping**|Ya (langsung return)|Tidak (harus bangun path penuh dulu)|
|**Generalitas**|Mudah diperluas, bisa ubah jadi pointer umum|Kurang fleksibel|

---

## 📌 Kesimpulan:

Versi sekarang lebih baik karena:

- Lebih efisien secara waktu dan memori
    
- Hanya perlu satu traversal
    
- Tidak menyimpan path eksplisit
    
- Langsung menemukan jawaban saat DFS
    

---

Versi ini adalah **standar yang umum dipakai** di kompetisi, interview coding, dan juga di pustaka algoritma seperti LeetCode / GeeksForGeeks / CLRS-style textbook.

Kalau kamu ingin nanti kita benchmarking langsung (bandingkan waktu jalan dan jumlah alokasi memori), aku juga bisa bantu!

# Editorial Kode
Berikut **editorial lengkap per blok kode** untuk versi LCA dengan DFS langsung sebagai _member function_. Tiap blok dijelaskan fungsinya dan logika utamanya:

---

```cpp
#include <iostream>
#include <vector>
#include <memory>
#include <optional>
using namespace std;
```

- **Header**
    
    - `<iostream>`: untuk input/output `cin`/`cout`
        
    - `<vector>`: struktur data array dinamis
        
    - `<memory>`: smart pointer (`unique_ptr`)
        
    - `<optional>`: (opsional, tapi di versi akhir kita tidak menggunakan)
        

---

```cpp
#define UQ unique_ptr<Node<T>>
#define MQ make_unique<Node<T>>
```

- **Makro Pendek**
    
    - `UQ` menggantikan `unique_ptr<Node<T>>`
        
    - `MQ` menggantikan `make_unique<Node<T>>`
        
    - Membuat penulisan pointer menjadi lebih ringkas
        

---

```cpp
template <typename T>
struct Node {
    T data;
    UQ left, right;
    Node(T data) : data(data) {}
```

- **Struct Node**
    
    - `data`: nilai node (generic `T`)
        
    - `left`, `right`: pointer unik ke subtree kiri/kanan
        
    - Konstruktor inisialisasi `data`
        

---

```cpp
    static UQ buildTrees(const vector<T>& vec, int idx = 0) {
        if (idx >= vec.size() || vec[idx] == -1) return nullptr;
        UQ node = MQ(vec[idx]);
        node->left  = buildTrees(vec, 2 * idx + 1);
        node->right = buildTrees(vec, 2 * idx + 2);
        return node;
    }
```

- **Membangun Tree dari Array Level-order**
    
    - `vec`: representasi level-order, `-1` = `null`
        
    - Formula indeks:
        
        - Anak kiri = `2*idx + 1`
            
        - Anak kanan = `2*idx + 2`
            
    - Rekursi berhenti jika `idx` di luar rentang atau `vec[idx] == -1`
        

---

```cpp
    Node<T>* findLCA(T a, T b) {
        Node<T>* lca = nullptr;
        dfsLCA(this, a, b, lca);
        return lca;
    }
```

- **Antarmuka Pencarian LCA**
    
    - Buat pointer `lca` kosong
        
    - Panggil `dfsLCA` mulai dari `this` (root)
        
    - Kembalikan pointer `lca` hasil temuan (atau `nullptr` jika tidak ada)
        

---

```cpp
private:
    int dfsLCA(Node<T>* node, T a, T b, Node<T>*& lca) {
        if (!node) return 0;
        int left  = dfsLCA(node->left.get(),  a, b, lca);
        int right = dfsLCA(node->right.get(), a, b, lca);
        int mid   = (node->data == a || node->data == b) ? 1 : 0;
        if (left + right + mid >= 2 && !lca)
            lca = node;
        return (left + right + mid) > 0;
    }
```

- **DFS Post-order untuk Deteksi LCA**
    
    - **Base case**: `node == nullptr` → kembalikan `0`
        
    - **Rekursi**:
        
        - `left`: apakah `a`/`b` ada di subtree kiri? (0/1)
            
        - `right`: apakah `a`/`b` ada di subtree kanan?
            
        - `mid`: apakah `node` sendiri sama dengan `a` atau `b`?
            
    - **Deteksi LCA**:
        
        - Jika jumlah `left + right + mid >= 2` → berarti dua dari kondisi terpenuhi → `node` adalah LCA
            
        - Hanya set sekali (`!lca`) agar tetap yang terdalam pertama
            
    - **Return**: `1` jika subtree ini mengandung `a` atau `b` (dipakai parent)
        

---

```cpp
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto& x : vec)
        cin >> x;

    int a, b;
    cin >> a >> b;

    auto root = Node<int>::buildTrees(vec);
    auto lca  = root->findLCA(a, b);

    if (lca) cout << lca->data << '\n';
    else     cout << "Node tidak ditemukan\n";

    return 0;
}
```

- **`main()`**
    
    1. Baca ukuran `n` dan isi array level-order
        
    2. Baca `a` dan `b`, dua nilai yang dicari LCAnya
        
    3. Bangun `root` via `buildTrees`
        
    4. Panggil `findLCA(a,b)`
        
    5. Cetak `lca->data` jika ditemukan, atau pesan error
        

---

### 🎯 Ringkasan Keunggulan

- **Satu kali traversal** pohon (O(n))
    
- **Hemat memori**: hanya stack rekursi O(h), tanpa vector path
    
- **Elegan & modular**: LCA tetap menjadi member function
    
- **Standar kompetisi**: solusi yang umum dipakai di LeetCode, interview, dsb
    

Semoga membantu memahami setiap bagian! Kalau ada yang ingin didalami lagi, kabari saja. 🙌