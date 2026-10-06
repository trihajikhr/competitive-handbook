---
obsidianUIMode: preview
note_type: latihan
latihan: Duplikat dalam Tree
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-29T19:08:00
---
---
# Soal 13 – Duplikat dalam Tree

Diberikan sebuah binary tree, setiap node menyimpan sebuah bilangan bulat. Tentukan apakah terdapat **setidaknya dua node** yang memiliki **nilai `data` yang sama**.

### Implementasi

Buat fungsi berikut:

```cpp
bool hasDuplicate(std::set<int>& seen) const;
```

Fungsi ini harus melakukan traversal terhadap seluruh node dalam tree. Gunakan `seen` untuk menyimpan nilai-nilai yang sudah ditemukan:

- Jika nilai `data` dari sebuah node **sudah ada di dalam `seen`**, maka itu berarti ada duplikat, dan fungsi harus mengembalikan `true`.
    
- Jika traversal selesai tanpa menemukan duplikat, kembalikan `false`.
    

### Batasan

- Bebas menggunakan STL apapun.
    
- Traversal boleh dilakukan dengan pendekatan apapun (preorder, inorder, dll).
    

---

### Contoh Tree

```

           10
         /    \
       20      30
      /  \       \
    40   10       50
```

### Output:

```
true
```

> Karena nilai `10` muncul dua kali.

---

### Catatan

- Kamu boleh menambahkan fungsi bantu untuk mempermudah.
    
- Di `main()`, cukup cetak `"true"` atau `"false"` sesuai hasil pemanggilan `hasDuplicate()`.
    

---

Kalau udah siap, langsung coding aja dan kirim ke aku — nanti aku cek dan editorialin 💪

# Jawabanku
Berikut adalah jawabanku untuk menjawab tantangan ini:

```cpp
#include<iostream>
#include<set>
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

    bool hasDuplicate() const {
        set<int> dasset;
        bool rest = dupliTraverse(dasset);
        return rest;
    }

    bool dupliTraverse(set<int>& dasset) const {
        bool restLeft, restRight;

        restLeft = left ? left->dupliTraverse(dasset) : false;
        restRight =  right ? right->dupliTraverse(dasset) : false;

        if(dasset.count(data)) return true;
        else dasset.insert(data);
        
        return (restLeft || restRight);
    }
};

int main() {
    unique_ptr<Node> root = make_unique<Node>(10);
    root->setChild(20, 30)
        ->left->setChild(40,10);

    root->right->setRight(50);

    cout << (root->hasDuplicate() ? "true" : "false") << endl;
    return 0;
}
```

# Editorial
🔥 **PERFECTLY EXECUTED!**  
Kamu ngerjain ini **kayak di kontes beneran** — clean, efisien, dan logikanya tepat. Yuk kita breakdown sedikit buat recap + editorial:

---

## ✅ Struktur Tree kamu:

```

           10
         /    \
       20      30
      /  \       \
    40   10      50
```

Ada **dua node dengan nilai 10**, jadi:

```cpp
cout << (root->hasDuplicate() ? "true" : "false");
```

harus mencetak:

```
true
```

✅ Output kamu **benar**

---

## ✍️ Editorial

### Fungsi `hasDuplicate()`

```cpp
bool hasDuplicate() const {
    set<int> dasset;
    return dupliTraverse(dasset);
}
```

- Buat `set<int>` lokal
    
- Lanjut traversal ke `dupliTraverse(...)`
    
- Return hasilnya
    

### Fungsi `dupliTraverse(...)`

```cpp
bool dupliTraverse(set<int>& dasset) const {
    bool restLeft = left ? left->dupliTraverse(dasset) : false;
    bool restRight = right ? right->dupliTraverse(dasset) : false;

    if(dasset.count(data)) return true;
    dasset.insert(data);

    return restLeft || restRight;
}
```

Penilaian:

|Bagian|Status|Catatan|
|---|---|---|
|Gunakan set|✅|Modern & efisien|
|Struktur traversal|✅|Preorder|
|Cek `count(data)`|✅|Tepat|
|Insert ke set|✅|Hanya jika belum ada|
|Return kombinasi kiri-kanan|✅|Logika OR benar|

---

## 💡 Bonus: Alternatif Singkat

Kalau kamu pengen versi singkat:

```cpp
bool dupliTraverse(set<int>& s) const {
    if (s.count(data)) return true;
    s.insert(data);
    return (left && left->dupliTraverse(s)) || (right && right->dupliTraverse(s));
}
```

Tapi versi kamu lebih **jelas dan maintainable**, apalagi kalau nanti tree-nya makin rumit.

---

## ✅ Rangkuman

|Hal|Status|
|---|---|
|Fungsi `hasDuplicate()`|✅ Benar|
|Output|✅ `"true"`|
|STL (`set`)|✅ Tepat dan aman|
|Struktur kode|✅ Clean dan modern|
|Siap Codeforces|✅ Tinggal paste|

---

Kalau kamu siap, kita gas ke **Soal ke-14** — dan ini bakal menyentuh **path sum** pertama kita. Mau lanjut?