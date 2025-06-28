---
obsidianUIMode: preview
note_type: latihan
latihan: Node dengan Syarat
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-26T19:06:00
---
---
🔥 KALIMAT KEREN BANGET!! 🔥  

_"Pemenang sejati adalah mereka yang memenangkan permainan bahkan sebelum permainan dimulai..."_  

Itulah mental **juara sejati** — menang di **latihan**, karena latihan adalah **tempat membentuk dominasi** 💪

---

# Soal 14 – Cetak Semua Node pada Level Tertentu yang Genap dan Kelipatan 5

### 📋 Deskripsi

Diberikan sebuah **binary tree**, buatlah fungsi:

```cpp
void printEvenMultiplesOfFiveAtLevel(Node* root, int level);
```

yang akan **mencetak semua node** pada **level ke-`level`** yang:

1. **Genap**, dan
    
2. **Merupakan kelipatan dari 5**
    

---

### 📥 Input

- `root`: pointer ke akar pohon
    
- `level`: level target (dimulai dari 1)
    

---

### 📤 Output

- Nilai node di level tersebut yang **genap dan kelipatan 5**, dipisahkan dengan spasi
    
- Jika tidak ada, tidak perlu mencetak apa-apa
    

---

### 💡 Contoh Struktur Pohon:

```

         30
        /   \
      12     25
     /  \    / \
   10   6  20  50
   
```

### Contoh:

- `level = 2` → node: `12, 25` → hanya `25` kelipatan 5 tapi tidak genap → ❌
    
- `level = 3` → node: `10, 6, 20, 50`  
    → Genap dan kelipatan 5: `10, 20, 50` → output: `10 20 50`
    

---

### ⚙️ Ketentuan

- Gunakan **rekursi**
    
- Tidak menggunakan variabel global
    
- Tidak perlu menyimpan hasil dalam struktur data tambahan
    
- Cetak nilai langsung jika memenuhi syarat
    

# Jawabanku
Berikut adalah jawabanku untuk menyelesaikan tantangan ini:

```cpp
#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *kiri, *kanan;
    Node(int data){
        this->data = data;
        kiri = kanan = NULL;
    }
};

void solve(struct Node * node, int lvl){
    if(node == NULL) return;

    if((node->data %2==0 && node->data%5==0) && lvl==1){
        cout << node->data << " ";
    }
    solve(node->kiri, lvl-1);
    solve(node->kanan, lvl-1);
}

int main() {
    struct Node * root = new Node(30);
    root->kiri = new Node(12);
    root->kanan = new Node(25);
    root->kiri->kiri = new Node(10);
    root->kiri->kanan = new Node(6);
    root->kanan->kanan = new Node(50);
    root->kanan->kiri = new Node(20);

    int l; cin >> l;
    cout << "Hasil: ";
    solve(root, l);
    return 0;
}
```

# Editorial
🔥 **Fantastis! Kerja ciamik!**  
Kamu sudah paham betul bagaimana melakukan traversal ke level tertentu, lalu menyisipkan kondisi yang ketat — **hanya mencetak node jika nilainya genap dan kelipatan 5**.

Seperti biasa, aku bantu buatkan **editorial profesional** biar bisa kamu salin ke Obsidian.

---

## 🧩 Soal 14 – Cetak Semua Node Genap dan Kelipatan 5 di Level Tertentu

---

### 📘 Deskripsi

Cetak semua node pada level ke-`l` dari binary tree yang:

- **Genap** (`% 2 == 0`)
    
- **Kelipatan 5** (`% 5 == 0`)
    

---

### ✅ Fungsi:

```cpp
void solve(struct Node * node, int lvl){
    if(node == NULL) return;

    if((node->data % 2 == 0 && node->data % 5 == 0) && lvl == 1){
        cout << node->data << " ";
    }

    solve(node->kiri, lvl - 1);
    solve(node->kanan, lvl - 1);
}
```

---

## 🌳 Contoh Struktur Pohon:

```

         30
        /   \
      12     25
     /  \    / \
   10   6  20  50
   
```

---

### 🎯 Contoh Uji:

- Input: `level = 3`  
    Node di level 3: `10, 6, 20, 50`  
    Syarat genap & kelipatan 5: `10, 20, 50`  
    Output:
    
    ```
    Hasil: 10 20 50
    ```
    

---

## 🧠 Penjelasan

|Baris|Penjelasan|
|---|---|
|`if (node == NULL)`|Basis rekursi — tidak ada node|
|`if (lvl == 1)`|Berarti kita sedang berada di level target|
|`node->data % 2 == 0 && node->data % 5 == 0`|Cek apakah node genap dan kelipatan 5|
|`cout << node->data`|Cetak node yang memenuhi|
|`solve(node->kiri/kanan, lvl - 1)`|Lanjutkan traversal ke anak kiri dan kanan|

---

### ✅ Evaluasi

|Aspek|Status|
|---|---|
|Traversal berbasis level|✅|
|Filtering dua kondisi (genap + kel. 5)|✅|
|Tidak gunakan variabel global|✅|
|Clean code & sesuai output|✅|

---

## 🏁 Kesimpulan

Latihan ini semakin mengasah kemampuan kamu dalam:

- Menggabungkan banyak kondisi logika
    
- Traversal recursive berbasis level
    
- **Penerapan kondisi numerik spesifik** pada traversal pohon
    

Kamu sudah berada di jalur yang benar untuk menangani **tree traversal dengan syarat kompleks**, seperti:

- Node dengan digit unik
    
- Node yang termasuk dalam rentang tertentu
    
- Node dengan properti matematis khusus
    

---

Kalau sudah kamu salin editorialnya, beri tanda — dan kita lanjut ke **Soal 15**, penutup dari sesi traversal dasar ini 🏁

Mau lanjut? Soalnya akan melibatkan **perbandingan nilai kiri dan kanan di level tertentu** 😉