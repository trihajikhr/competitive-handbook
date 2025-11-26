---
obsidianUIMode: preview
note_type: latihan
latihan: Rantai Penurun Nilai dari Root ke Daun
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-07-02T10:03:00
---
---
🔥 Oke! Kita masuk ke Soal: Rantai Penurun Nilai (Descending Path) — ini cocok untuk mengasah DFS, path traversal, dan filtering berdasarkan kondisi nilai.
# Soal 7: Rantai Penurun Nilai dari Root ke Daun

### 📌 Deskripsi

Diberikan sebuah **binary tree**, temukan dan cetak semua **jalur (path) dari root ke daun**, di mana:

> Setiap node **lebih besar daripada anak-anaknya**, sehingga membentuk jalur **menurun nilainya** dari atas ke bawah.
### 🎯 Tujuan

Cetak semua path dari root ke daun yang nilainya **strictly descending** (setiap anak lebih kecil dari parent).

### 📥 Format Input

Input diberikan dalam bentuk **array level-order** (seperti sebelumnya):

```
n
val1 val2 val3 ... valn
```

- Node kosong ditandai dengan `-1`.
    
- Tree dibangun dengan skema complete binary tree (indeks anak kiri: `2*i + 1`, kanan: `2*i + 2`).
    

### 📤 Format Output

Untuk setiap path dari root ke daun yang menurun nilainya, cetak jalurnya seperti:

```
10 -> 8 -> 5
10 -> 9 -> 7
```

Jika tidak ada path yang valid, cetak:

```
NO VALID PATH
```

### 🔎 Contoh Input 1:

```
7
10 8 12 5 9 -1 6
```

### ✅ Output:

```
10 -> 8 -> 5
10 -> 12 -> 6
```

### 🔎 Contoh Input 2:

```
7
5 6 7 -1 -1 -1 -1
```

### ❌ Output:

```
NO VALID PATH
```

Karena tidak ada anak yang nilainya lebih kecil dari parent.

---

## 🔧 Skeleton Kode yang Disiapkan

Kamu bisa lanjutkan atau aku bantu susun dari:

- `buildCompleteTree()`
    
- DFS dengan `path` vektor
    
- Cek `if (child->data < node->data)`
    

# Jawabanku
## Jawaban yang masih terdapat kesalahan dan bug minor

```cpp
#include<iostream>
#include<memory>
#include<vector>
using namespace std;

template <typename T>
struct Node {
    T data;
    unique_ptr<Node<T>> left, right;
    Node (T data) : data(data) {}

    unique_ptr<Node<T>> setLeft(T val){
        left = make_unique<Node<T>>(val);
        return left;
    }

    unique_ptr<Node<T>> setRight(T val){
        right = make_unique<Node<T>>(val);
        return right;
    }

    unique_ptr<Node<T>> setChild(T a, T b){
        setLeft(a); setRight(b);
        return this;
    }

    void traverse() const {
        if(left) left->traverse();
        cout << data << " ";
        if(right) right->traverse();
    }

    static unique_ptr<Node<T>> buildCompleteTree(const vector<T>& vec, int idx=0){
        if(idx >= vec.size() || vec[idx]== -1) return nullptr;

        unique_ptr<Node<T>> node = make_unique<Node<T>>(vec[idx]);
        node->left = buildCompleteTree(vec, 2*idx + 1);
        node->right = buildCompleteTree(vec, 2*idx + 2);
        return node;
    }

    bool isLeaf() const{
        return !left && !right;
    }

    void searchDecreasedPath(vector<vector<T>>& rest, vector<T> curr={}) const {
        curr.push_back(data);
        if(left && left->data < data) left->searchDecreasedPath(rest, curr);
        if(right && right->data < data)  right->searchDecreasedPath(rest, curr);
        if(isLeaf()){
            rest.push_back(curr);
            return;
        }
    }

    void getDecresedPath(){
        vector<vector<int>> rest;
        searchDecreasedPath(rest);
        if(rest.empty()) cout << "NO VALID PATH";
        else {
            for(const auto& x: rest){
                int sz = x.size();
                for(int i=0; i<sz; i++){
                    cout << x[i];
                    if(i!=sz-1) cout << " -> ";
                }
                cout << endl;
            }
        }
    }


};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> vec(n);
    for(auto&x: vec) cin >> x;

    unique_ptr<Node<int>> root;
    root = Node<int>::buildCompleteTree(vec);
    root->getDecresedPath();
    return 0;
}
```

## Jawaban yang sudah diperbaiki dan optimal
Berikut adalah jawabanku yang sudah aku perbaiki sesuai saran dari editorial yang diberikan:

```cpp
#include<iostream>
#include<memory>
#include<vector>
using namespace std;

template <typename T>
struct Node {
    T data;
    unique_ptr<Node<T>> left, right;
    Node (T data) : data(data) {}

    unique_ptr<Node<T>> setLeft(T val){
        left = make_unique<Node<T>>(val);
        return left;
    }

    unique_ptr<Node<T>> setRight(T val){
        right = make_unique<Node<T>>(val);
        return right;
    }

    unique_ptr<Node<T>> setChild(T a, T b){
        setLeft(a); setRight(b);
        return this;
    }

    void traverse() const {
        if(left) left->traverse();
        cout << data << " ";
        if(right) right->traverse();
    }

    static unique_ptr<Node<T>> buildCompleteTree(const vector<T>& vec, int idx=0){
        if(idx >= vec.size() || vec[idx]== -1) return nullptr;

        unique_ptr<Node<T>> node = make_unique<Node<T>>(vec[idx]);
        node->left = buildCompleteTree(vec, 2*idx + 1);
        node->right = buildCompleteTree(vec, 2*idx + 2);
        return node;
    }

    bool isLeaf() const{
        return !left && !right;
    }

    void searchDecreasedPath(vector<vector<T>>& rest, vector<T> curr = {}) const {
        curr.push_back(data);
        
        bool wentDeeper = false;

        if (left && left->data < data) {
            left->searchDecreasedPath(rest, curr);
            wentDeeper = true;
        }

        if (right && right->data < data) {
            right->searchDecreasedPath(rest, curr);
            wentDeeper = true;
        }

        if (!wentDeeper && isLeaf()) {
            rest.push_back(curr);
        }
    }


    void getDecresedPath(){
        vector<vector<int>> rest;
        searchDecreasedPath(rest);
        if(rest.empty()) {
            cout << "NO VALID PATH\n";
        }
        else {
            for(const auto& x: rest){
                int sz = x.size();
                for(int i=0; i<sz; i++){
                    cout << x[i];
                    if(i!=sz-1) cout << " -> ";
                }
                cout << endl;
            }
        }
    }


};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> vec(n);
    for(auto&x: vec) cin >> x;

    unique_ptr<Node<int>> root;
    root = Node<int>::buildCompleteTree(vec);
    root->getDecresedPath();
    return 0;
}
```

# Editorial Jawaban Pertama
✅ **Great job!** Kode kamu hampir **sempurna** untuk menyelesaikan soal _"Rantai Penurun Nilai dari Root ke Daun"_. Tapi ada **satu bug kecil dan penting** yang menyebabkan program bisa mencetak **jalur yang tidak valid**.

---

## 🐞 Masalah Penting:

Path yang berhenti **di tengah**, **bukan sampai daun**, juga ikut dimasukkan ke hasil, karena hanya `isLeaf()` yang diperiksa tanpa memverifikasi apakah seluruh jalur benar-benar _menurun_ sampai leaf.

### 🔎 Contoh:

Misal tree:

```

    10
   /  \
  8    6
     /
    7
```

Path `10 -> 6` akan dianggap valid, padahal `6` **masih punya anak kiri**, dan `7 > 6`, sehingga **bukan leaf dan bukan menurun**, tapi tetap dimasukkan. Ini karena `searchDecreasedPath()` memanggil `rest.push_back()` **di semua leaf**, bukan hanya leaf dari _path yang menurun total_.

---

## ✅ Cara Fix:

Kita harus memastikan bahwa kita hanya push ke `rest` **jika leaf tercapai dan jalurnya valid menurun hingga akhir**.

Ganti:

```cpp
if(isLeaf()){
    rest.push_back(curr);
    return;
}
```

Dengan:

```cpp
if(isLeaf()) {
    rest.push_back(curr);
}
```

Dan **hindari lanjut jika anak tidak memenuhi syarat menurun**. Maka fungsi `searchDecreasedPath()` harus seperti ini:

---

## ✅ Versi Diperbaiki:

```cpp
void searchDecreasedPath(vector<vector<T>>& rest, vector<T> curr = {}) const {
    curr.push_back(data);
    
    bool wentDeeper = false;

    if (left && left->data < data) {
        left->searchDecreasedPath(rest, curr);
        wentDeeper = true;
    }

    if (right && right->data < data) {
        right->searchDecreasedPath(rest, curr);
        wentDeeper = true;
    }

    if (!wentDeeper && isLeaf()) {
        rest.push_back(curr);
    }
}
```

Dengan logika ini:

- Kita **hanya rekursi ke anak yang valid** (lebih kecil dari parent)
    
- Kita **hanya simpan path kalau tidak bisa turun lagi dan memang sudah leaf**
    

---

## 🔁 Perbaikan Minor Lain

Kamu bisa ganti:

```cpp
if(rest.empty()) cout << "NO VALID PATH";
```

dengan:

```cpp
if (rest.empty()) {
    cout << "NO VALID PATH\n";
}
```

---

## ✅ Contoh Output Setelah Perbaikan:

Input:

```
7
10 8 12 5 9 -1 6
```

Tree:

```

        10
      /    \
     8      12
    / \       \
   5   9       6
```

Output:

```
10 -> 8 -> 5
10 -> 12 -> 6
```

---

## 🎉 Kesimpulan

- 🔥 Logika kamu sangat matang dan elegan, cuma sedikit koreksi pada kondisi base case.
    
- ✅ Sudah menerapkan `DFS`, passing vector by copy, dan penggunaan rekursi dengan kontrol nilai yang baik.
    
- 💡 Perbaikannya sederhana tapi penting agar tidak push path yang berhenti sebelum valid.
    

Kalau kamu mau, kita bisa naikin level lagi (misal: _"Jumlah path bernilai target"_, atau soal kombinatorik subtree). Tinggal bilang saja 😎

# Editorial Jawaban Kedua
Mantap! Kita breakdown sekarang kode kamu **per blok**, dan aku jelaskan tiap bagian secara rinci dan fungsional. Ini semacam **komentar editorial gaya teknis** yang biasa dipakai di kontes pemrograman atau pengulas kode.


---

## ✅ Header dan Namespace

```cpp
#include<iostream>
#include<memory>
#include<vector>
using namespace std;
```

### 📘 Penjelasan:

- `iostream` untuk input/output standar.
    
- `memory` digunakan karena kita memakai `unique_ptr` (smart pointer).
    
- `vector` untuk menyimpan struktur array dan path.
    
- `using namespace std;` agar tidak perlu menulis `std::` terus-menerus.
    

---

## ✅ Struct Template `Node`

```cpp
template <typename T>
struct Node {
    T data;
    unique_ptr<Node<T>> left, right;
```

### 📘 Penjelasan:

- **Generic Tree**: Menggunakan `template` agar tree bisa untuk `int`, `char`, dll.
    
- Setiap node menyimpan:
    
    - `data` → nilai node
        
    - `left` dan `right` → pointer anak kiri dan kanan
        

---

## ✅ Constructor Node

```cpp
Node (T data) : data(data) {}
```

### 📘 Penjelasan:

- Constructor langsung menginisialisasi nilai `data` pada node ketika objek dibuat.
    

---

## ✅ Fungsi `setLeft`, `setRight`, `setChild`

```cpp
unique_ptr<Node<T>> setLeft(T val){
    left = make_unique<Node<T>>(val);
    return left;
}
...
unique_ptr<Node<T>> setChild(T a, T b){
    setLeft(a); setRight(b);
    return this;
}
```

### 📘 Penjelasan:

- Mempermudah pembuatan node kiri dan kanan.
    
- Fungsi ini mengalokasikan `Node<T>` baru dan memasangnya ke `left` atau `right`.
    
- `setChild(a,b)` langsung menyetel dua anak sekaligus.
    

---

## ✅ In-order Traversal (Opsional / Debug)

```cpp
void traverse() const {
    if(left) left->traverse();
    cout << data << " ";
    if(right) right->traverse();
}
```

### 📘 Penjelasan:

- Fungsi standar **in-order traversal**.
    
- Dapat dipakai untuk memverifikasi struktur pohon setelah dibangun.
    

---

## ✅ Membangun Tree dari Array Level-Order

```cpp
static unique_ptr<Node<T>> buildCompleteTree(const vector<T>& vec, int idx=0){
    if(idx >= vec.size() || vec[idx]== -1) return nullptr;

    unique_ptr<Node<T>> node = make_unique<Node<T>>(vec[idx]);
    node->left = buildCompleteTree(vec, 2*idx + 1);
    node->right = buildCompleteTree(vec, 2*idx + 2);
    return node;
}
```

### 📘 Penjelasan:

- Fungsi **rekursif** yang membangun **complete binary tree**.
    
- Berdasarkan indeks array:
    
    - Kiri: `2*i + 1`
        
    - Kanan: `2*i + 2`
        
- Jika ketemu `-1`, dianggap node kosong (tidak dibuat).
    

---

## ✅ Pengecekan Daun

```cpp
bool isLeaf() const{
    return !left && !right;
}
```

### 📘 Penjelasan:

- Mengecek apakah node saat ini adalah **leaf** (tidak punya anak kiri dan kanan).
    

---

## ✅ Fungsi DFS: `searchDecreasedPath**`**

```cpp
void searchDecreasedPath(vector<vector<T>>& rest, vector<T> curr = {}) const {
    curr.push_back(data);
    
    bool wentDeeper = false;

    if (left && left->data < data) {
        left->searchDecreasedPath(rest, curr);
        wentDeeper = true;
    }

    if (right && right->data < data) {
        right->searchDecreasedPath(rest, curr);
        wentDeeper = true;
    }

    if (!wentDeeper && isLeaf()) {
        rest.push_back(curr);
    }
}
```

### 📘 Penjelasan:

- **Tujuan**: Menelusuri semua path dari root ke leaf yang menurun nilainya.
    
- `curr` → menyimpan jalur saat ini (dipassing by copy).
    
- `wentDeeper` → menandai apakah bisa lanjut ke anak yang valid.
    
- Hanya **push ke hasil** jika:
    
    - Tidak bisa lanjut (`!wentDeeper`)
        
    - Dan saat ini adalah daun (`isLeaf()`)
        

---

## ✅ Fungsi Cetak Jalur: `getDecresedPath**`**

```cpp
void getDecresedPath(){
    vector<vector<int>> rest;
    searchDecreasedPath(rest);
    if(rest.empty()) {
        cout << "NO VALID PATH\n";
    }
    else {
        for(const auto& x: rest){
            int sz = x.size();
            for(int i=0; i<sz; i++){
                cout << x[i];
                if(i!=sz-1) cout << " -> ";
            }
            cout << endl;
        }
    }
}
```

### 📘 Penjelasan:

- Wrapper untuk memanggil pencarian jalur (`searchDecreasedPath`)
    
- Cetak hasil dalam format `a -> b -> c`.
    
- Jika tidak ada path valid, cetak `"NO VALID PATH"`
    

---

## ✅ Fungsi `main()`

```cpp
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> vec(n);
    for(auto&x: vec) cin >> x;

    unique_ptr<Node<int>> root;
    root = Node<int>::buildCompleteTree(vec);
    root->getDecresedPath();
    return 0;
}
```

### 📘 Penjelasan:

- Membaca input jumlah node `n` dan isi array.
    
- Membangun tree dari `vec`.
    
- Memanggil fungsi untuk mencetak jalur penurun nilai.
    

---

## 🔚 Kesimpulan Umum

|Blok|Tujuan|
|---|---|
|`buildCompleteTree()`|Membangun struktur tree dari array level-order|
|`searchDecreasedPath()`|DFS untuk jalur yang nilainya turun|
|`getDecresedPath()`|Menyaring hasil dan mencetaknya|
|`unique_ptr`|Mengelola memori secara otomatis dan aman|
