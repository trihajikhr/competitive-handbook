---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Chaining pada Class vs Struct
sumber: chatgpt.com
date_learned: 2025-07-06T16:20:00
tags:
  - tree-algorithm
---
Link Sumber: 

---

# Chaining pada Class dan Struct berbeda?

> Pada struct, kita bisa langsung chaining dengan mengarahkanya langsung dengan `left` dan `right`, sedangkan pada class, kita harus menggunakan fungsi getter untuk mendapatkan akses node dibawahnya. Apakah itu benar?

💡 YES — kalau kamu pakai `struct`, maka secara default semua member adalah `public`, jadi:

```cpp
template<typename T>
struct Node {
    T data;
    std::unique_ptr<Node<T>> left, right;
    Node (T data) : data(data) {}
};
```

Maka kamu bisa langsung mengakses `left` dari luar:

```cpp
auto root = std::make_unique<Node<int>>();
root->left = std::make_unique<Node<int>>(2);
root->left->right = std::make_unique<Node<int>>(3);
```

### ✅ Artinya:

- Kamu **tidak perlu `getLeft()`**, karena `left` sudah public.
    
- Ini membuat kode chaining atau modifikasi lebih bebas dan langsung.
    

---

## 🚧 Tapi... kenapa ini berbahaya?

Meskipun bisa, ini tidak selalu bijak atau aman, karena:

| Risiko                            | Penjelasan                                                                         |
| --------------------------------- | ---------------------------------------------------------------------------------- |
| ❌ Tidak ada kontrol akses     | Siapa pun bisa mengganti, menghapus, atau `move` `left` tanpa aturan.              |
| ❌ Rawan bug dan memory leak   | Misalnya, seseorang bisa `left = nullptr` dan menyebabkan node hilang tanpa jejak. |
| ❌ Struktur tree mudah rusak   | Tidak ada mekanisme validasi saat child ditambahkan.                               |
| ❌ Sulit debug jika tree rusak | Karena semua bebas mengubah isi node tanpa batasan.                                |

---

## ✅ Solusi aman: Tetap gunakan `class` + `getter/setter`

```cpp
class Node {
private:
    std::unique_ptr<Node> left;
public:
    Node* getLeft() const { return left.get(); }
    Node* setLeft(int val) {
        left = std::make_unique<Node>(val);
        return left.get();
    }
};
```

> Ini memberikan **kombinasi terbaik antara keamanan dan fleksibilitas**.

---

Misalnya, kita ingin:

- Mengakses node kiri dari root
    
- Mengakses anak kanan dari node tersebut
    
- Mencetak datanya

Contoh lengkap dengan penggunaan `getLeft()` dan `getRight()`

```cpp
#include <iostream>
#include <memory>
using namespace std;

class Node {
private:
    int data;
    unique_ptr<Node> left, right;

public:
    Node(int val) : data(val) {}

    int getData() const {
        return data;
    }

    Node* getLeft() const {
        return left.get();
    }

    Node* getRight() const {
        return right.get();
    }

    Node* setLeft(int val) {
        left = make_unique<Node>(val);
        return left.get();
    }

    Node* setRight(int val) {
        right = make_unique<Node>(val);
        return right.get();
    }

    void printPreorder() const {
        cout << data << " ";
        if (left) left->printPreorder();
        if (right) right->printPreorder();
    }
};

int main() {
    auto root = make_unique<Node>(1);

    root->setLeft(2)
         ->setRight(4)
         ->setLeft(8);

    root->setRight(3)
         ->setLeft(5)
         ->setRight(6);

    // ✅ Contoh penggunaan getter:
    Node* leftChild = root->getLeft();       
    // Akses anak kiri dari root
    
    if (leftChild) {
        cout << "Left child of root: " << leftChild->getData() << endl;

        Node* rightOfLeft = leftChild->getRight(); 
        // Akses anak kanan dari node 2
        
        if (rightOfLeft) {
            cout << "Right child of node 2: " << rightOfLeft->getData() << endl;
        }
    }

    cout << "\nPreorder traversal: ";
    root->printPreorder();
    cout << endl;
}
```

### 🧾 Output Program:

```
Left child of root: 2
Right child of node 2: 4

Preorder traversal: 1 2 4 8 3 5 6
```


### 📌 Catatan:

- `getLeft()` dan `getRight()` dipakai untuk **mengakses node dalam tree secara aman** tanpa membuka akses langsung ke pointer `unique_ptr`.
    
- Kamu tetap bisa menjelajah atau baca data child node, tapi **tidak bisa memindahkan atau menghapusnya secara sembarangan**, karena ownership tetap dijaga oleh `unique_ptr`.
    


---

## 🔁 Kalau tetap mau pakai `struct`, bisa, tapi harus sadar:

- Kamu memilih **kemudahan > keamanan**
    
- Cocok untuk **prototipe, skrip latihan, atau eksperimen kecil**
    
- Tidak ideal untuk **kode produksi atau sistem besar**
    

---

## 📌 Kesimpulan

| Pendekatan | Bisa langsung akses `left`/`right`? | Aman?    | Cocok untuk           |
| ---------- | ----------------------------------- | -------- | --------------------- |
| `struct`   | ✅ Ya                                | ❌ Kurang | Eksperimen, latihan   |
| `class`    | ❌ Tidak langsung                    | ✅ Aman   | Produksi, desain rapi |

Kalau kamu mau, aku bisa bantu kamu **ubah versi `struct` menjadi `class` yang lebih aman**, atau bahkan buat versi “semi-terbuka” dengan pengaman minimal.