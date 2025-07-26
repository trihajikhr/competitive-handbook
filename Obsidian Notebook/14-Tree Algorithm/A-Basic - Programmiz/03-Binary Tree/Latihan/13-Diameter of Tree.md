---
obsidianUIMode: preview
note_type: latihan
latihan: Diameter of Tree
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-07-06T12:59:00
---
---
# Soal: Diameter of Binary Tree

### 📥 Input:

- Sebuah array integer `A` berisi representasi level-order traversal dari _binary tree_.  
    Gunakan `-1` untuk menyatakan node kosong/null.
    

### 📤 Output:

- Sebuah integer: diameter tree (jumlah edge maksimum antar dua node).
    

---

### 💡 Contoh:

```cpp
7
1 2 3 4 5 -1 -1
```

**Penjelasan:**  
Tree yang terbentuk:

```

      1
     / \
    2   3
   / \
  4   5
```

Path terpanjang: 4 → 2 → 1 → 3 → panjang edge = 3. 

Jika yang dicari adalah jumlah node untuk membentuk path terpanjang, maka jawabanya adalah 4, tapi jika yang dicari adalah panjang ege, maka jawabanya $totalnode-1$.

---

Kalau kamu perlu template parsing dari array ke tree, tinggal bilang saja. Kalau tidak, aku tunggu jawabanmu 💪

# Jawabanku
## Jawaban yang masih salah
Berikut adalah jawabanku yang masih terdapat kekeliruan, dimana terdapat kesalahan:

```cpp
#include<iostream>
#include<memory>
#include<vector>
using namespace std;

#define UQ unique_ptr<Node<T>>
#define MQ make_unique<Node<T>>

template <typename T>
struct Node {
    T data;
    UQ left, right;
    Node (T data) : data(data) {}

    static UQ buildTrees(vector<T>& vec, int idx=0){
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

    void countLeftLength(T& l) {
        if(left) {
            l++;
            left->countLeftLength(l);
        }
    }


    void countRightLength(T& r) {
        if(right) {
            r++;
            right->countLeftLength(r);
        }
    }

    int getDiameterLength() {
        int l=0, r=0;
        countLeftLength(l); countRightLength(r);
        return l+r;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    vector<int> vec(n);
    for(auto & x: vec) cin >> x;

    unique_ptr<Node<int>> root = Node<int>::buildTrees(vec);
    cout << root->getDiameterLength();
    return 0;
}
```

## Jawaban yang sudah benar
Berikut adalah jawaban yang sudah benar dan sesuai:

```cpp
#include<iostream>
#include<memory>
#include<vector>
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

    int depth(int& diameter) {
        int l = left ? left->depth(diameter) : 0;
        int r = right ? right->depth(diameter) : 0;
        diameter = max(diameter, l + r);
        return 1 + max(l, r);
    }

    int getDiameterLength() {
        int diameter = 0;
        depth(diameter);
        return diameter;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto& x : vec) cin >> x;

    auto root = Node<int>::buildTrees(vec);
    cout << root->getDiameterLength() << '\n';

    return 0;
}
```

# Editorial
Dengan senang hati! Ini dia **editorial lengkap per blok kode** dari program penghitungan diameter _binary tree_ dengan pendekatan DFS. Fokus khusus diberikan pada fungsi `depth`.

---

## 🧩 Bagian Per Bagian

### 🧱 1. Tipe dan Pendeklarasian Awal

```cpp
#define UQ unique_ptr<Node<T>>
#define MQ make_unique<Node<T>>
```

> **Penjelasan:**
> 
> - Makro untuk menyederhanakan penulisan pointer unik (`unique_ptr`) agar lebih ringkas.
>     
> - `UQ` = `unique_ptr<Node<T>>`
>     
> - `MQ` = `make_unique<Node<T>>`
>     

---

### 🌱 2. Struktur Node Template

```cpp
template <typename T>
struct Node {
    T data;
    UQ left, right;
    Node(T data) : data(data) {}
```

> **Penjelasan:**
> 
> - `Node` menyimpan data bertipe `T`, dan pointer ke anak kiri dan kanan.
>     
> - Gunakan smart pointer (`unique_ptr`) agar tidak perlu menghapus node secara manual (otomatis dikelola C++).
>     

---

### 🏗️ 3. Fungsi `buildTrees` — Membangun Tree dari Array Level-order

```cpp
static UQ buildTrees(const vector<T>& vec, int idx = 0) {
    if (idx >= vec.size() || vec[idx] == -1) return nullptr;
    UQ node = MQ(vec[idx]);
    node->left = buildTrees(vec, 2 * idx + 1);
    node->right = buildTrees(vec, 2 * idx + 2);
    return node;
}
```

> **Penjelasan:**
> 
> - Membangun _binary tree_ dari array seperti `heap` (level-order).
>     
> - `-1` dianggap sebagai `null` (tidak ada node).
>     
> - Formula:
>     
>     - `left_child_idx = 2*i + 1`
>         
>     - `right_child_idx = 2*i + 2`
>         
> - Rekursi membentuk struktur pohon dari akar ke daun.
>     

---

### 🌲 4. Fungsi `depth()` — Kunci Utama Menghitung Diameter

```cpp
int depth(int& diameter) {
    int l = left ? left->depth(diameter) : 0;
    int r = right ? right->depth(diameter) : 0;
    diameter = max(diameter, l + r);
    return 1 + max(l, r);
}
```

> **Penjelasan Detail:**

- Fungsi ini **mengembalikan kedalaman dari subtree saat ini** (jumlah node dari node ini ke bawah).
    
- Parameter `diameter` dikirim **by reference**, agar nilai maksimum diameter bisa di-_update_ secara global saat DFS berjalan.
    

#### 🔍 Baris per baris:

- `int l = left ? left->depth(diameter) : 0;`
    
    > Jika ada anak kiri, hitung kedalamannya. Kalau tidak, 0.
    
- `int r = right ? right->depth(diameter) : 0;`
    
    > Sama seperti kiri, untuk anak kanan.
    
- `diameter = max(diameter, l + r);`
    
    > Inilah kuncinya: diameter _lewat node ini_ adalah `l + r` edge.  
    > Update global maximum jika ini lebih besar.
    
- `return 1 + max(l, r);`
    
    > Mengembalikan tinggi node ini, yaitu 1 (node sekarang) + kedalaman subtree terdalam di bawahnya.
    

---

### 📏 5. Fungsi `getDiameterLength()` — Pintu Masuk

```cpp
int getDiameterLength() {
    int diameter = 0;
    depth(diameter);
    return diameter;
}
```

> **Penjelasan:**
> 
> - Memanggil `depth()` dari root dan mengembalikan diameter global.
>     
> - Variabel `diameter` bersifat lokal, tapi di-_pass_ ke setiap `depth()` sebagai referensi.
>     

---

### 🧪 6. Fungsi `main()**`**

```cpp
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto& x : vec) cin >> x;

    auto root = Node<int>::buildTrees(vec);
    cout << root->getDiameterLength() << '\n';

    return 0;
}
```

> **Penjelasan:**
> 
> - Membaca input array
>     
> - Membangun pohon dari array
>     
> - Mencetak diameter
>     

---

## 🧠 Kesimpulan Konsep:

- `depth()` melakukan DFS post-order
    
- Diameter dihitung **sebagai total edge dari kiri + kanan** pada setiap node.
    
- Global maximum disimpan via parameter referensi
    
- Kompleksitas: **O(n)**, satu DFS kunjungan ke seluruh node.
    

---

Kalau kamu mau, aku bisa bantu ubah kode ini menjadi versi rekursi eksternal (di luar struct) atau bahkan bentuk non-rekursif. Tapi versi ini sudah sangat rapi dan idiomatik C++. Siap ke soal berikutnya?