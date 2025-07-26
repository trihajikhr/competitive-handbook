---
obsidianUIMode: preview
note_type: latihan
latihan: Hitung Jumlah Node Bernilai Genap
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-29T13:44:00
---
---
# Soal 3: Hitung Jumlah Node Bernilai Genap

Buatlah fungsi `int countEven(Node* root)` yang menghitung berapa banyak node dalam tree yang **nilai `data`-nya merupakan bilangan genap**.

---

#### Contoh:

Untuk tree:

```

      10
     /  \
    5   20
   / \
  3   8
  
```

Node-node dengan nilai genap: `10`, `8`, `20`  
Total node genap: **3**

---

Silakan implementasikan, dan seperti biasa, aku akan periksa dan beri penjelasan setelah kamu kirimkan hasilnya!

# Jawabanku
Berikut adalah jawabanku, yang selain mencaritotal penjumlahan node genap, tapi juga mencari banyaknya node genap:

```cpp
#include<iostream>
#include<memory>
using namespace std;

struct Node {
    int data;
    unique_ptr<Node> left, right;
    Node(int data) : data(data) {};

    // chaining
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

    int evenCount(){
        int cnt=0;

        if(left) cnt += left->evenCount();
        if(right) cnt += right->evenCount();
        if(data%2==0) cnt++;
        return cnt;
    }

    int evenSum(){
        int sum=0;

        if(left) sum += left->evenSum();
        if(right) sum += right->evenSum();
        if(data%2==0) sum+=data;
        return sum;
    }
};

int main() {
    unique_ptr<Node> root = make_unique<Node>(10);
    root->setChild(5,20)->left->setChild(3,8);

    cout << root->evenCount() << "\n";
    return 0;
}
```

# Editorial
🔥 KEREN! Kode kamu kembali **benar**, clean, dan fleksibel — bahkan kamu bonusin fungsi `evenSum()` juga! Sekarang seperti biasa, kita bedah satu per satu sebagai editorial dan kita lihat apakah ada ruang untuk penguatan.

---

## ✅ Pemeriksaan Output

Tree:

```

      10
     /  \
    5   20
   / \
  3   8
```

Node dengan nilai **genap**: `10`, `20`, `8` → total: `3`  
Program kamu mencetak `3` → **benar** ✅

---

## ✍️ Editorial

### 1. Struktur dan Fungsi Builder

```cpp
Node* setLeft(int val);
Node* setRight(int val);
Node* setChild(int a, int b);
```

Konsisten dan chaining-nya bagus. Penamaan `setLeft` dan `setRight` juga sekarang konsisten (tidak typo lagi). 👍

---

### 2. Fungsi `evenCount()`

```cpp
int evenCount(){
    int cnt=0;
    if(left) cnt += left->evenCount();
    if(right) cnt += right->evenCount();
    if(data % 2 == 0) cnt++;
    return cnt;
}
```

- Ini traversal **postorder**, karena kamu proses anak kiri dan kanan dulu, baru node saat ini.
    
- Pengecekan `data % 2 == 0` langsung di tempat, efisien dan mudah dibaca.
    

---

### 3. Fungsi `evenSum()` (tambahan opsional dari kamu)

```cpp
int evenSum(){
    int sum=0;
    if(left) sum += left->evenSum();
    if(right) sum += right->evenSum();
    if(data%2==0) sum+=data;
    return sum;
}
```

- Fungsi tambahan ini sangat berguna kalau nanti kita butuh menjumlahkan nilai genap, bukan sekadar menghitung jumlah nodenya.
    
- Bisa jadi versi lanjutan dari soal ini.
    

---

## 🟢 Rangkuman

- ✅ Output benar
    
- ✅ Struktur rapi dan traversal efisien
    
- ✅ Konsistensi gaya meningkat
    
- ✅ Tambahan fungsi `evenSum()` menunjukkan fleksibilitas desainmu
    
