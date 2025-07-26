---
obsidianUIMode: preview
note_type: latihan
latihan: Node Kakek dan Cucu-cucunya
sumber: myself
tags:
  - tree-algorithm
date_learned: 2025-07-01T20:49:00
---
---
# Soal 5: Node Kakek dan Cucu-cucunya

Dalam sebuah **binary tree**, sebuah node disebut sebagai **kakek** jika ia memiliki **minimal satu cucu** — yaitu, anak dari anaknya.

Tugasmu adalah:

1. Menemukan semua node yang merupakan **kakek**.
    
2. Menampilkan mereka beserta **daftar cucu-cucunya** (baik dari anak kiri maupun anak kanan).

#### 📥 Input:

Tree dibangun dari barisan triplet:

```
parent child side
```

Semua nilai adalah integer.

#### 📤 Output:

Untuk setiap node yang merupakan kakek, tampilkan satu baris seperti:

```
Kakek: X | Cucu-cucu: A B ...
```

Urutan cucu boleh bebas.

#### 📌 Contoh Input:

```
11
50 30 L
50 70 R
30 20 L
30 40 R
20 10 L
20 25 R
70 60 L
70 80 R
60 55 L
60 58 R
80 85 R
```

Struktur pohon:

```

                  50
               /      \
             30        70
           /    \     /   \
         20     40   60    80
        /  \         / \     \
      10   25      55  58    85
      

```

#### 🖥️ Penjelasan 

- **50** → anak: 30, 70
    
    - Cucu: dari 30 = 20, 40 → ✅  
        dari 70 = 60, 80 → ✅  
        tapi 20 dan 60 juga punya anak, **tidak dihitung ke cucu 50** karena sudah generasi ke-3.
        
    
    → **Cucu 50 = 20 40 60 80** ✅
    
- **30** → anak: 20, 40
    
    - 20 punya anak: 10, 25 → cucu 30 = 10, 25 ✅
        
- **70** → anak: 60, 80
    
    - 60 punya anak: 55, 58
        
    - 80 punya anak: 85  
        → Cucu 70 = 55, 58, 85 ✅
        
- **20, 60** juga punya cucu, tapi mereka bukan kakek karena anak-anaknya tidak punya anak.

#### 📤 Contoh Output:

```
Kakek: 50 | Cucu-cucu: 20 40 60 80
Kakek: 30 | Cucu-cucu: 10 25
Kakek: 70 | Cucu-cucu: 55 58 85
```

# Jawaban
## Dengan bantuan map dan vector
Berikut adalah jawabanku yang masih bisa ditingkatkan berdasarkan saran dari editorial:

```cpp
#include<iostream>
#include<memory>
#include<map>
#include<vector>
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

    Node* setChild(T a, int b){
        setLeft(a); setRight(b);
        return this;
    }

    void traverse() const {
        if(left) left->traverse();
        cout << data << " ";
        if(right) right->traverse();
    }

    bool insertNodes(T parent, T child, T post){
        if(data == parent){
            if(post == 'L') setLeft(child);
            else setRight(child);
            return true;
        }

        bool inserted = false;
        if(left) inserted |= left->insertNodes(parent, child, post);
        if(right) inserted |= right->insertNodes(parent, child, post);
        return inserted;
    }

    void getGrandNodes(map<T, vector<T>>& dasmap, T gp, int num=1) const {
        if(left) left->getGrandNodes(dasmap, gp, num-1);
        if(right) right->getGrandNodes(dasmap, gp, num-1);
        if(num==0 && (left || right)) {
            if(left) dasmap[gp].push_back(left->data);
            if(right) dasmap[gp].push_back(right->data);
        }
    }

    void printGrandNodes() const {
        map<T, vector<T>> dasmap;
        if(left) left->printGrandNodes();
        if(right) right->printGrandNodes();
        getGrandNodes(dasmap, data);

        for(const auto& [key, val]: dasmap){
            cout << "Kakek: " << key << " | Cucu-cucu: ";
            for(const auto& x: val){
                cout << x << " ";
            }
            cout << endl;
        }
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

    root->printGrandNodes();

    return 0;
}
```

## Jawaban yang lebih bersih
Jawaban ini lebih dioptimalkan secara memori, dan mengurangi banyak rekursif yang tidak perlu:

```cpp
#include<iostream>
#include<memory>
#include<vector>
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

    Node* setChild(T a, int b){
        setLeft(a); setRight(b);
        return this;
    }

    void traverse() const {
        if(left) left->traverse();
        cout << data << " ";
        if(right) right->traverse();
    }

    bool insertNodes(T parent, T child, T post){
        if(data == parent){
            if(post == 'L') setLeft(child);
            else setRight(child);
            return true;
        }

        bool inserted = false;
        if(left) inserted |= left->insertNodes(parent, child, post);
        if(right) inserted |= right->insertNodes(parent, child, post);
        return inserted;
    }

    // versi jawaban yang lebih baik
    void findAndPrintGrandchildren() const {
        if (left) left->findAndPrintGrandchildren();
        if (right) right->findAndPrintGrandchildren();

        vector<T> cucu;

        if (left) {
            if (left->left) cucu.push_back(left->left->data);
            if (left->right) cucu.push_back(left->right->data);
        }
        if (right) {
            if (right->left) cucu.push_back(right->left->data);
            if (right->right) cucu.push_back(right->right->data);
        }

        if (!cucu.empty()) {
            cout << "Kakek: " << data << " | Cucu-cucu: ";
            for (const T& c : cucu) {
                cout << c << " ";
            }
            cout << "\n";
        }
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

    root->findAndPrintGrandchildren();
    return 0;
}
```

# Editorial
Keren banget! Kamu udah berhasil menyelesaikan **soal tentang kakek dan cucu-cucunya** dengan kode yang:

- 🔍 Mendeteksi cucu tepat di level ke-2 dari node.
    
- 🧠 Memakai `map<T, vector<T>>` untuk menyimpan daftar cucu per kakek.
    
- 🧵 Rekursif dan bersih.
    
- 📤 Output-nya sudah sesuai format.
    

Tapi aku ada beberapa **catatan kecil** untuk menyempurnakan kode kamu (biar benar-benar mantap):

---

### ✅ Yang Sudah Bagus

1. **Fungsi `getGrandNodes()`** memanfaatkan parameter `num` sebagai kedalaman → sangat cocok untuk mendeteksi level cucu (yaitu `num == 0`).
    
2. **`dasmap[gp]`** dipakai untuk menyimpan cucu per kakek secara rapi.
    
3. **Rekursi dalam `printGrandNodes()`** ke kiri dan kanan → bagus.
    

---

### ⚠️ Perbaikan Penting

**Masalah utama**: Fungsi `printGrandNodes()` dipanggil rekursif ke seluruh node:

```cpp
if(left) left->printGrandNodes();
if(right) right->printGrandNodes();
```

Artinya, setiap node (termasuk node yang **bukan kakek**) juga menjalankan `getGrandNodes()`. Akibatnya:

- Banyak node **bukan kakek** akan tetap memproses `getGrandNodes()` dan **mengeluarkan output kosong** atau tidak relevan.
    
- Map akan dicetak berulang dari setiap node.
    

---

### ✅ Cara Memperbaiki

1. Gabungkan traversal dan deteksi kakek dalam satu rekursi.
    
2. Cetak hanya jika node memang punya cucu.
    

Berikut versi yang lebih bersih dan efisien:

```cpp
void findAndPrintGrandchildren() const {
    if (left) left->findAndPrintGrandchildren();
    if (right) right->findAndPrintGrandchildren();

    vector<T> cucu;

    if (left) {
        if (left->left) cucu.push_back(left->left->data);
        if (left->right) cucu.push_back(left->right->data);
    }
    if (right) {
        if (right->left) cucu.push_back(right->left->data);
        if (right->right) cucu.push_back(right->right->data);
    }

    if (!cucu.empty()) {
        cout << "Kakek: " << data << " | Cucu-cucu: ";
        for (const T& c : cucu) {
            cout << c << " ";
        }
        cout << "\n";
    }
}
```

Gantilah `printGrandNodes()` kamu dengan fungsi ini di `main()`:

```cpp
root->findAndPrintGrandchildren();
```

---

### 🔚 Kesimpulan

- Ide kamu dan logika dasarnya udah **top-tier**.
    
- Dengan sedikit restruktur, kamu bisa **hindari map** dan dapat output yang lebih **langsung dan efisien**.
    
- Tapi kalau kamu sengaja ingin map-nya untuk keperluan lain (misalnya kumpulkan data dulu, baru cetak), juga tetap valid.
    

Kalau kamu mau lanjut ke soal 6 atau ada ide soal lain, tinggal lempar aja. Kamu udah di level eksplorasi bebas 💪