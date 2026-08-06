---
obsidianUIMode: preview
note_type: latihan
latihan: Cari Jalur dari Root ke Node Tertentu
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-07-02T14:25:00
---
---
# 🔍 Soal 9: Cari Jalur dari Root ke Node Tertentu

### 📋 Deskripsi Singkat:

Diberikan array `A` yang merepresentasikan **complete binary tree**, serta sebuah nilai `X`.  

Tugasmu adalah mencari **jalur dari root ke node bernilai `X`**.

Jika ditemukan, cetak jalurnya dengan format:

```
Path: a -> b -> c -> X
```

Jika tidak ada, cetak:

```
NOT FOUND
```

### 🧪 Contoh Input:

```
15
10 5 15 3 7 12 20 2 4 6 8 11 13 18 25
13
```

### 🧾 Output:

```
Path: 10 -> 15 -> 12 -> 13
```


Kalau kamu tadi minta **"tree yang besar"**, kita bisa tetap pakai soal ini tapi perbesar datanya kayak tadi:

### 💣 Input Besar:

```
30
50 30 70 20 40 60 80 10 25 35 45 55 65 75 90 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
65
```

### 🔄 Output yang diharapkan:

```
Path: 50 -> 70 -> 60 -> 65
```

---

Kalau kamu udah punya solusi, tinggal test aja pakai data ini.

Kalau butuh soal lanjutan, tinggal bilang:

- "Cek apakah ada lebih dari satu jalur menuju X"
    
- "Cetak semua jalur ke semua node ganjil"
    
- "Level node X"
    

Gas terus!
# Jawabanku
## Jawaban yang masih terdapat minor kesalahan
```cpp
#include<iostream>
#include<memory>
#include<vector>
using namespace std;

template <typename T>
struct Node {
    T data;
    unique_ptr<Node<T>> left, right;
    Node(T data) : data(data) {};

    unique_ptr<Node<T>> setLeft(T val){
        left = make_unique<Node<T>>(val);
        return left.get();
    }
    
    unique_ptr<Node<T>> seRight(T val){
        right = make_unique<Node<T>>(val);
        return right.get();
    }

    unique_ptr<Node<T>> setChild(T a, T b){
        setLeft(a); setRight(b);
        return this;
    }

    void inTraverse() const {
        if(left) left->inTraverse();
        cout << data << " ";
        if(right) right->inTraverse();
    }

    // cari path dari root ke node X
    void searchPathToX(vector<T>& vec, T target, vector<T> curr={}, bool stop=false) {
        curr.push_back(data);
        if(stop) return;
        if(left) left->searchPathToX(vec, target, curr, stop);
        if(right) right->searchPathToX(vec, target, curr, stop);
        if(data == target){
            vec = curr;
            stop=true;
            return;
        }
    }
    
    void getPathToX(T target) {
        vector<T> vec;
        searchPathToX(vec, target);
        cout << "Path: ";
        for(int i=0; i<vec.size(); i++){
            cout << vec[i];
            if(i != vec.size()-1) cout << " -> ";
        }
    }

    static unique_ptr<Node<T>> buildTrees(vector<T>& vec, int idx = 0){
        if(idx >= vec.size() || vec[idx] == -1) return nullptr;

        unique_ptr<Node<T>> node = make_unique<Node<T>>(vec[idx]);
        node->left = buildTrees(vec, 2*idx+1);
        node->right = buildTrees(vec, 2*idx+2);
        return node;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> vec(n);
    for(auto&x: vec) cin >> x;
    int target; cin >> target;

    unique_ptr<Node<int>> root;
    root = Node<int>::buildTrees(vec);
    root->getPathToX(target);
    return 0;
}
```

## Jawaban yang lebih baik
Dilakukan perbaikan pada sistem early stop fungsi `searhPathToX()` agar langsung berhenti ketika sudah ada node target yang ditemukan, dan juga memperbaiki output, yang belum menangani node target yang tidak ada didalam tree:

```cpp
#include<iostream>
#include<memory>
#include<vector>
using namespace std;

template <typename T>
struct Node {
    T data;
    unique_ptr<Node<T>> left, right;
    Node(T data) : data(data) {};

    unique_ptr<Node<T>> setLeft(T val){
        left = make_unique<Node<T>>(val);
        return left.get();
    }
    
    unique_ptr<Node<T>> setRight(T val){
        right = make_unique<Node<T>>(val);
        return right.get();
    }

    unique_ptr<Node<T>> setChild(T a, T b){
        setLeft(a); setRight(b);
        return this;
    }

    void inTraverse() const {
        if(left) left->inTraverse();
        cout << data << " ";
        if(right) right->inTraverse();
    }

    // cari path dari root ke node X
    bool searchPathToX(vector<T>& vec, T target, vector<T> curr = {}) {
        curr.push_back(data);
        if (data == target) {
            vec = curr;
            return true;
        }

        if (left && left->searchPathToX(vec, target, curr)) return true;
        if (right && right->searchPathToX(vec, target, curr)) return true;

        return false;
    }
    
    void getPathToX(T target) {
        vector<T> vec;
        if (searchPathToX(vec, target)) {
            cout << "Path: ";
            for (int i = 0; i < vec.size(); i++) {
                cout << vec[i];
                if (i != vec.size() - 1) cout << " -> ";
            }
            cout << "\n";
        } else {
            cout << "NOT FOUND\n";
        }
    }

    static unique_ptr<Node<T>> buildTrees(vector<T>& vec, int idx = 0){
        if(idx >= vec.size() || vec[idx] == -1) return nullptr;

        unique_ptr<Node<T>> node = make_unique<Node<T>>(vec[idx]);
        node->left = buildTrees(vec, 2*idx+1);
        node->right = buildTrees(vec, 2*idx+2);
        return node;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> vec(n);
    for(auto&x: vec) cin >> x;
    int target; cin >> target;

    unique_ptr<Node<int>> root;
    root = Node<int>::buildTrees(vec);
    root->getPathToX(target);
    return 0;
}
```
# Editorial Jawaban Pertama
Bagus, kamu sudah menyusun struktur kode dan logikanya dengan sangat rapi! Tapi ada **sedikit kekeliruan logika** di fungsi pencarian path `searchPathToX()` yang menyebabkan flag `stop` **tidak bekerja seperti yang diharapkan**, karena kamu **mengubah parameter `stop` secara _by value_**, bukan _by reference_.

---

### ✅ Perbaikan Kecil:

Ubah `stop` menjadi **reference** agar perubahan nilainya bisa disimpan selama rekursi:

```cpp
void searchPathToX(vector<T>& vec, T target, vector<T> curr = {}, bool& stop = *(new bool(false))) {
    if (stop) return;

    curr.push_back(data);
    if (data == target) {
        vec = curr;
        stop = true;
        return;
    }

    if (left) left->searchPathToX(vec, target, curr, stop);
    if (right) right->searchPathToX(vec, target, curr, stop);
}
```

Tapi pendekatan lebih rapi dan aman adalah:

### ✨ Solusi Lebih Bersih:

Buat `searchPathToX()` return `bool`, dan kembalikan `true` jika sudah menemukan target:

```cpp
bool searchPathToX(vector<T>& vec, T target, vector<T> curr = {}) {
    curr.push_back(data);
    if (data == target) {
        vec = curr;
        return true;
    }

    if (left && left->searchPathToX(vec, target, curr)) return true;
    if (right && right->searchPathToX(vec, target, curr)) return true;

    return false;
}
```

Dan fungsi `getPathToX()` jadi:

```cpp
void getPathToX(T target) {
    vector<T> vec;
    if (searchPathToX(vec, target)) {
        cout << "Path: ";
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i];
            if (i != vec.size() - 1) cout << " -> ";
        }
        cout << "\n";
    } else {
        cout << "NOT FOUND\n";
    }
}
```

---

### 🔧 Typo kecil:

```cpp
unique_ptr<Node<T>> seRight(T val)  // ❌ seRight
```

Harusnya:

```cpp
unique_ptr<Node<T>> setRight(T val)  // ✅ setRight
```

---

### 📌 Kesimpulan:

- Logika kamu sudah **tepat**
    
- Flag `stop` tidak efektif karena tidak _by reference_
    
- Disarankan gunakan pendekatan boolean return untuk kontrol yang lebih bersih
    
- Typo `seRight` sebaiknya dibetulkan agar tidak bikin bingung di kemudian hari
    

Kalau kamu siap, bisa lanjut ke soal variasi lain dari path (misalnya: “cetak semua path yang panjangnya genap”, atau “hanya path ke leaf”). Gaskeun 😎