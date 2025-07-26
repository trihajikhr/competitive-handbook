---
obsidianUIMode: preview
note_type: latihan
latihan: Total Nilai pada Jalur Diameter Binary Tree
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-07-06T14:43:00
---
---
# Soal 15 – Total Nilai pada Jalur Diameter Binary Tree

### 🧠 Deskripsi:

Diberikan sebuah **binary tree** dalam bentuk array level-order, dengan `-1` sebagai penanda node kosong.  
Temukan **jumlah nilai node** yang dilalui di **jalur diameter** tree tersebut.

> 🧩 _Diameter adalah jalur terpanjang antar dua node mana pun di dalam tree._

- Jalur ini boleh (atau tidak) melewati root.
    
- Jika ada lebih dari satu jalur diameter (panjang sama), cukup ambil salah satu yang menghasilkan total nilai tertinggi.
    

---

### 📥 Input:

1. Integer `n` – jumlah elemen array
    
2. `n` bilangan bulat – elemen level-order tree (`-1` = null)
    

---

### 📤 Output:

- Sebuah bilangan bulat: jumlah nilai node di sepanjang jalur diameter
    

---

### 📌 Contoh 1:

#### Input:

```
11
1 2 3 4 5 -1 -1 -1 -1 6 7
```

#### Visualisasi:

```

        1
       / \
      2   3
     / \
    4   5
       / \
      6   7
```

#### Jalur Diameter:

- `6 → 5 → 2 → 4`
    
- Total = `6 + 5 + 2 + 4 = 17`
    

#### Output:

```
17
```

---

### 📌 Contoh 2:

#### Input:

```
7
10 5 20 -1 -1 15 25
```

#### Visualisasi:

```

       10
      /  \
     5    20
         /  \
        15  25
```

#### Jalur Diameter:

- `5 → 10 → 20 → 25`
    
- Total = `5 + 10 + 20 + 25 = 60`
    

#### Output:

```
60
```

---

### ⚙️ Batasan:

- `1 ≤ n ≤ 10⁵`
    
- Nilai node `[-10⁶, 10⁶]`
    
- Tree tidak harus lengkap
    

---

## 💡 Petunjuk:

- Gunakan DFS post-order
    
- Di setiap node, hitung:
    
    - `depth` subtree kiri dan kanan
        
    - `sum` maksimum dari jalur kiri dan kanan
        
- Simpan kombinasi terbaik yang membentuk diameter di global/state
    
# Jawabanku
Aku masih belum menemukan jawaban yang tepat, sehingga aku memutuskan untuk belajar lebih dulu dari jawaban editorial berikut:

```cpp
#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>
using namespace std;

#define UQ unique_ptr<Node<T>>
#define MQ make_unique<Node<T>>

template <typename T>
struct Node {
    T data;
    UQ left, right;
    Node(T data) : data(data) {}

    static UQ buildTrees(vector<T>& vec, int idx = 0) {
        if (idx >= vec.size() || vec[idx] == -1) return nullptr;
        UQ node = MQ(vec[idx]);
        node->left = buildTrees(vec, 2 * idx + 1);
        node->right = buildTrees(vec, 2 * idx + 2);
        return node;
    }

    pair<int, T> dfsDiameterSum(T& bestSum, int& bestDiameter) {
        if (!left && !right) return {0, data}; // leaf

        int lDepth = 0, rDepth = 0;
        T lSum = 0, rSum = 0;

        if (left) tie(lDepth, lSum) = left->dfsDiameterSum(bestSum, bestDiameter);
        if (right) tie(rDepth, rSum) = right->dfsDiameterSum(bestSum, bestDiameter);

        int diameterHere = lDepth + rDepth;
        T sumHere = lSum + data + rSum;

        if (diameterHere > bestDiameter) {
            bestDiameter = diameterHere;
            bestSum = sumHere;
        } else if (diameterHere == bestDiameter) {
            bestSum = max(bestSum, sumHere);
        }

        int depth = 1 + max(lDepth, rDepth);
        T branchSum = max(lSum, rSum) + data;
        return {depth, branchSum};
    }

    T getDiameterSum() {
        int bestDiameter = 0;
        T bestSum = data;
        dfsDiameterSum(bestSum, bestDiameter);
        return bestSum;
    }

    void trav() const {
        if (left) left->trav();
        cout << data << " ";
        if (right) right->trav();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    vector<int> vec(n);
    for (auto& x : vec) cin >> x;

    unique_ptr<Node<int>> root = Node<int>::buildTrees(vec);
    cout << root->getDiameterSum() << '\n';

    return 0;
}

```

# Editorial
Berikut **editorial lengkap** per blok kode untuk implementasi **“Total Nilai pada Jalur Diameter Binary Tree”**:

---

```cpp
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;
```

- Menyertakan dependensi standar:
    
    - `<iostream>` untuk `cin`/`cout`
        
    - `<memory>` untuk `unique_ptr`
        
    - `<vector>` untuk array dinamis
        
    - `<algorithm>` untuk `max`
        

---

```cpp
#define UQ unique_ptr<Node<T>>
#define MQ make_unique<Node<T>>
```

- **Makro ringkas**:
    
    - `UQ` ≡ `unique_ptr<Node<T>>`
        
    - `MQ` ≡ `make_unique<Node<T>>`
        
- Mengurangi kata-kata berulang saat membangun pointer
    

---

```cpp
template <typename T>
struct Node {
    T data;
    UQ left, right;
    Node(T data) : data(data) {}
```

- **Struct Node** generik:
    
    - `data` menyimpan nilai node (`int` pada penggunaan nanti)
        
    - `left, right` adalah subtree sebagai `unique_ptr`
        
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

- **Membangun tree** dari array level-order:
    
    - `-1` dianggap node kosong
        
    - Anak kiri: `2*idx + 1`, anak kanan: `2*idx + 2`
        
    - Rekursi berhenti saat indeks keluar batas atau `-1`
        

---

```cpp
    pair<int, T> dfsDiameterSum(T& bestSum, int& bestDiameter) {
        if (!left && !right) return {0, data};
```

- **Awal DFS di leaf**:
    
    - Jika node tidak punya anak, depth = 0 (edge ke bawah), sum = `data`
        
    - Mengembalikan `{depth, branchSum}`
        

---

```cpp
        int lDepth = 0, rDepth = 0;
        T lSum = 0, rSum = 0;

        if (left)  tie(lDepth, lSum) = left->dfsDiameterSum(bestSum, bestDiameter);
        if (right) tie(rDepth, rSum) = right->dfsDiameterSum(bestSum, bestDiameter);
```

- **Kunjungi subtree kiri & kanan**:
    
    - `lDepth, lSum` hasil dari anak kiri
        
    - `rDepth, rSum` hasil dari anak kanan
        
    - `tie` memecah `pair<int,T>`
        

---

```cpp
        int diameterHere = lDepth + rDepth;
        T sumHere = lSum + data + rSum;
```

- **Menghitung potensi diameter melalui node ini**:
    
    - `diameterHere`: jumlah edge kiri + kanan
        
    - `sumHere`: total nilai jalur kiri → node → jalur kanan
        

---

```cpp
        if (diameterHere > bestDiameter) {
            bestDiameter = diameterHere;
            bestSum = sumHere;
        } else if (diameterHere == bestDiameter) {
            bestSum = max(bestSum, sumHere);
        }
```

- **Update global**:
    
    - Jika `diameterHere` lebih panjang → simpan `sumHere`
        
    - Jika sama panjang → ambil `sumHere` yang lebih besar
        

---

```cpp
        int depth = 1 + max(lDepth, rDepth);
        T branchSum = max(lSum, rSum) + data;
        return {depth, branchSum};
    }
```

- **Mengembalikan pair untuk parent**:
    
    - `depth`: tinggi subtree di bawah node ini (edge count)
        
    - `branchSum`: nilai jalur maksimal dari node ini turun ke leaf
        

---

```cpp
    T getDiameterSum() {
        int bestDiameter = 0;
        T bestSum = data;
        dfsDiameterSum(bestSum, bestDiameter);
        return bestSum;
    }
```

- **Antarmuka**:
    
    - Inisialisasi `bestDiameter` dan `bestSum`
        
    - Panggil `dfsDiameterSum` dari root
        
    - Kembalikan `bestSum` akhir
        

---

```cpp
    void trav() const {
        if (left) left->trav();
        cout << data << " ";
        if (right) right->trav();
    }
};
```

- **In-order traversal** (opsional, bukan bagian inti soal)
    

---

```cpp
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; 
    cin >> n;
    vector<int> vec(n);
    for (auto& x : vec) 
        cin >> x;

    auto root = Node<int>::buildTrees(vec);
    cout << root->getDiameterSum() << '\n';
    return 0;
}
```

- **`main()`**:
    
    1. Baca `n` dan array level-order
        
    2. Bangun tree via `buildTrees`
        
    3. Cetak hasil `getDiameterSum()`
        

---

### 🔍 Kompleksitas

- **Waktu**: O(n), satu kali DFS
    
- **Memori**: O(h) stack, tanpa struktur tambahan besar
    

Dengan struktur ini, kamu mendapatkan solusi yang **efisien**, **ringkas**, dan **mudah dipelihara**. Semoga membantu!