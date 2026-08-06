---
obsidianUIMode: preview
note_type: latihan
latihan: Jumlah Seluruh Node di Tree
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-29T13:09:00
---
---
# Soal 1: Jumlah Seluruh Node di Tree

Buatlah fungsi `int countNodes(Node* root)` yang menerima root dari sebuah binary tree dan mengembalikan jumlah seluruh node yang ada di dalam tree tersebut.

Contoh:  
Jika treenya adalah:

```

      10
     /  \
    5   20
   / \
  3   8
  
```

Maka fungsi `countNodes` harus mengembalikan `5`.

---

Kalau sudah kamu kerjakan, kirimkan kodenya ke sini, nanti aku periksa dan kasih editorialnya ya. Silakan!

# Jawabanku
Berikut adalah jawabanku yang sudah tepat dan benar:

```cpp
#include<iostream>
#include<memory>
using namespace std;

struct Node {
    int data;
    unique_ptr<Node> left, right;
    Node(int data) : data(data) {}; 

    Node* setRight(int val){
        right = make_unique<Node>(val);
        return right.get();
    }

    Node* setLeft(int val){
        left = make_unique<Node>(val);
        return left.get();
    }

    Node* setChild(int a, int b){
        setLeft(a); setRight(b);
        return this;
    }

    int countNodes() const {
        int cnt = 0;
        if(left) cnt+= left->countNodes();
        if(right) cnt+= right->countNodes();
        cnt++;
        return cnt;
    }
};

int main() {
    unique_ptr<Node> root = make_unique<Node>(10);
    root->setChild(5,20)->left->setChild(3,8);

    cout << root->countNodes() << "\n";
    return 0;
}
```

# Editorial
Keren! Kodenya sudah **benar** dan berhasil menghitung jumlah node dalam tree dengan struktur:

```

      10
     /  \
    5    20
   / \
  3   8
```

Output-nya adalah `5`, sesuai dengan jumlah semua node.

---

## Pemeriksaan Kode

- Kamu menggunakan `unique_ptr`, yang artinya ownership node terjamin dan tidak akan terjadi memory leak.
    
- Fungsi `countNodes()` diimplementasikan **secara rekursif**, dengan menjumlahkan:
    
    - Jumlah node di subtree kiri
        
    - Jumlah node di subtree kanan
        
    - Ditambah 1 untuk node saat ini
        

---

### Editorial Per Baris

#### Struktur Node:

```cpp
struct Node {
    int data;
    unique_ptr<Node> left, right;
```

- Ini adalah struktur dasar tree node. Kita pakai `unique_ptr` agar memory-nya otomatis dikelola (tidak perlu `delete` manual).
    

```cpp
    Node(int data) : data(data) {}; 
```

- Konstruktor untuk menginisialisasi data node saat pembuatan.
    

#### Fungsi bantu untuk membuat tree:

```cpp
    Node* setRight(int val){
        right = make_unique<Node>(val);
        return right.get();
    }

    Node* setLeft(int val){
        left = make_unique<Node>(val);
        return left.get();
    }

    Node* setChild(int a, int b){
        setLeft(a); setRight(b);
        return this;
    }
```

- Fungsi `setLeft` dan `setRight` mempermudah penambahan anak kiri dan kanan.
    
- `setChild(a, b)` langsung menambahkan dua anak sekaligus, lalu mengembalikan `this` supaya bisa chaining seperti `->left->setChild(...)`.
    

#### Fungsi utama soal:

```cpp
    int countNodes() const {
        int cnt = 0;
        if(left) cnt += left->countNodes();
        if(right) cnt += right->countNodes();
        cnt++;
        return cnt;
    }
```

- Ini adalah rekursi pas di textbook.
    
- Hitung jumlah node dari subtree kiri dan kanan, lalu tambah `1` untuk node itu sendiri.
    

#### Di main:

```cpp
    unique_ptr<Node> root = make_unique<Node>(10);
    root->setChild(5,20)->left->setChild(3,8);
```

- Membuat tree sesuai contoh.
    

```cpp
    cout << root->countNodes() << "\n";
```

- Cetak jumlah seluruh node, yaitu `5`.
    

## Pembahasan kedua

Sebelumnya, jawabanku seperti ini. Hal ini menimbulkan beberapa pertanyaan untukku:

```cpp
    auto setRight(int val){
        right = make_unique<Node>(val);
        return right.get();
    }

    auto setLeft(int val){
        left = make_unique<Node>(val);
        return left.get();
    }

    auto setChild(int a, int b){
        setLeft(a); setRight(b);
        return this;
    }
```

> hei, sebentar, kan aku menggunakan unique_ptr, dan penggunaan * artinya aku menggunakan raw pointer, yang diaktakan tidak bagus jika sudah pakai unique_ptr? nah auto yang aku pakai itu menggantikan tipe data kembalian apa sih? aku pakai auto karena bingung aja

Pertanyaanmu **bagus banget**! Ini menyentuh pemahaman mendalam soal `unique_ptr`, `auto`, dan raw pointer.

---

### 🤔 Masalah Utama yang Kamu Pikirkan

> “Aku pakai `unique_ptr`, tapi kok return-nya pakai `*` alias raw pointer? Apa ini buruk?”

Jawabannya: **tidak selalu buruk**, asal kamu tahu bahwa pointer itu:

- **tidak memiliki ownership**,
    
- dan tidak dipakai untuk membuat salinan atau new object baru.
    

---

### 🧠 Apa yang auto Tangkap di Sini?

Mari lihat contohnya:

```cpp
auto setLeft(int val) {
    left = make_unique<Node>(val);
    return left.get();  // ← ini dia
}
```

`left.get()` akan mengembalikan **raw pointer** (`Node*`) ke objek yang dimiliki oleh `left` (yang merupakan `unique_ptr<Node>`).

Jadi `auto` di situ:

```cpp
auto setLeft(...)  →  diturunkan menjadi  Node*
```

Karena `left.get()` punya tipe `Node*`, maka `auto` == `Node*`.

---

### 😬 Apakah Aman Mengembalikan `Node*` dari `unique_ptr<Node>`?

Ya, **aman**, **selama kamu tidak menyimpan raw pointer itu lebih lama dari hidup `unique_ptr`-nya**.

Dalam kasusmu:

- `setLeft()` hanya mengembalikan raw pointer untuk keperluan _chaining_, bukan untuk menyimpan di tempat lain.
    
- Kamu tidak `delete` atau `new` di luar — semuanya dikelola oleh `unique_ptr`.
    
- Maka **ini aman dan sah-sah saja**.
    

Contoh chaining aman:

```cpp
root->setChild(5, 20)->left->setChild(3, 8);
```

---

### ✅ Rekomendasi (kalau ingin lebih eksplisit)

Kalau kamu nggak suka pakai `auto`, atau ingin lebih jelas, bisa tulis:

```cpp
Node* setLeft(int val) {
    left = make_unique<Node>(val);
    return left.get();
}
```

Jadi kamu tahu persis bahwa itu `Node*`.

---

### 🚫 Kapan Ini Jadi Berbahaya?

Kalau kamu melakukan hal seperti ini:

```cpp
Node* p = root->setLeft(10);  // OK
delete p;                     // ❌❌❌ jangan delete ini!
```

Atau:

```cpp
Node* p = root->setLeft(10);
saveToVector(p);  // lalu vector menyimpannya terlalu lama
```

Itu bisa menyebabkan dangling pointer — karena kamu tidak tahu apakah `root` masih hidup atau sudah dihapus.

---

### 🟢 Kesimpulan

- `auto` di `return left.get()` → sebenarnya `Node*`
    
- Itu aman **selama hanya dipakai untuk chaining sementara**
    
- Kalau ingin eksplisit dan jelas, ganti `auto` dengan `Node*`
    
- Kamu sudah di jalur yang benar — gaya chaining kamu elegan dan benar!
    

