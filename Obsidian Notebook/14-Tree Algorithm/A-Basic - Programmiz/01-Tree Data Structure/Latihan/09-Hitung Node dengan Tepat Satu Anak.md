---
obsidianUIMode: preview
note_type: latihan
latihan: Hitung Node dengan Tepat Satu Anak
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-29T15:40:00
---
---
# Soal 9: Hitung Node dengan Tepat Satu Anak

Buatlah fungsi `int countOneChild(Node* root)`  
yang menghitung jumlah node yang memiliki **tepat satu anak**, baik hanya kiri **atau** hanya kanan — tapi **bukan keduanya dan bukan nol anak**.

---

#### Gunakan Tree Berikut:

```

           50
         /    \
       30      80
      /         \
    20           90
                  \
                  100
```

---

### Penjelasan:

- Node `30` punya satu anak (kiri saja) → ✅
    
- Node `80` punya satu anak (kanan saja) → ✅
    
- Node `90` punya satu anak (kanan saja) → ✅
    
- Total node dengan satu anak = **3**
    

---

### Syarat:

- Jangan pakai struktur data tambahan seperti array, queue, dll.
    
- Gunakan traversal rekursif saja.
    

---

Silakan implementasikan, dan kirim ke sini seperti biasa. Nanti aku cek dan editorialin!

# Jawabanku
Berikut adalah jawabanku untuk menjawab tantangan ini. Sebelumnya terdapat kesalahan pada fungsi `isOneChild()`:

```cpp
#include<iostream>
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

    bool isOneChild(){
        return (left && !right) || (!left && right);
    }

    bool isTwoChild(){
        return (left && right);
    }

    int countOneChild(){
        int cnt=0;
        if(left) cnt += left->countOneChild();
        if(right) cnt += right->countOneChild();
        if(isOneChild()) cnt++;

        return cnt;
    }
};

int main() {
    unique_ptr<Node> root = make_unique<Node>(50);
    root->setChild(30, 80)
        ->left->setLeft(20);

    root->right->setRight(90)
        ->setRight(100);


    cout << root->countOneChild() << "\n";
    return 0;
}
```

# Editorial
Siap! Ini dia editorial lengkap untuk solusi Soal ke-9: Menghitung Jumlah Node dengan Tepat Satu Anak, versi terbaru yang sudah kamu perbaiki dan berjalan benar.

---

## 🧠 Tujuan Soal

Hitung berapa banyak node di tree yang memiliki tepat satu anak:

- Hanya anak kiri ✅
    
- Hanya anak kanan ✅
    
- Bukan dua anak atau tidak punya anak sama sekali ❌
    

---

## 🌲 Tree yang Dibangun

```plaintext

           50
         /    \
       30      80
      /          \
    20            90
                    \
                    100
```

---

### 🔎 Penjelasan Struktur

|Node|Anak Kiri|Anak Kanan|Jumlah Anak|Dihitung?|
|---|---|---|---|---|
|50|30|80|2|❌|
|30|20|null|1|✅|
|80|null|90|1|✅|
|90|null|100|1|✅|
|20|null|null|0|❌|
|100|null|null|0|❌|

Total node yang valid: `3`

---

## 📄 Kode Penting

### Fungsi `isOneChild()`

```cpp
bool isOneChild(){
    return (left && !right) || (!left && right);
}
```

✅ Logika ini mengecek:

- `left` ada tapi `right` tidak → true
    
- `right` ada tapi `left` tidak → true
    
- lainnya → false
    

🛑 Tidak seperti versi sebelumnya `left != right`, ini lebih **spesifik dan benar**.

---

### Fungsi `countOneChild()`

```cpp
int countOneChild(){
    int cnt = 0;
    if(left)  cnt += left->countOneChild();
    if(right) cnt += right->countOneChild();
    if(isOneChild()) cnt++;
    return cnt;
}
```

- Fungsi ini **rekursif postorder**: telusuri dulu anak, lalu nilai node saat ini
    
- Jumlah dihitung akurat, karena node hanya dianggap jika punya **tepat satu anak**
    

---

## ✅ Output Program

```cpp
cout << root->countOneChild() << "\n"; // Output: 3
```

Hasil: `3`  
✅ **Sesuai harapan dan validasi secara manual**

---

## 💬 Ringkasan

|Aspek|Penilaian|Catatan|
|---|---|---|
|Logika One Child|✅|Sudah benar & eksplisit|
|Traversal Rekursif|✅|Bersih dan efisien|
|Output|✅|Sesuai ekspektasi|
|Tree Builder|✅|Rapi dan cocok dengan soal|
|Style|✅|Gaya chaining konsisten|
