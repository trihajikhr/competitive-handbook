---
obsidianUIMode: preview
note_type: tips trick
tips_trick: pemahaman struct node
sumber: chatgpt.com
tags:
  - tree-algorithm
---
---
# 🧠 PEMAHAMAN `struct Node`

## 📦 Struktur dasarnya:

```cpp
struct Node {
    int data;
    struct Node *left, *right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};
```

---

### 🔍 1. `struct Node`

Kita sedang mendefinisikan sebuah **struktur** bernama `Node`. Dalam konteks **Tree**, satu _Node_ mewakili satu simpul tree.

### 🔍 2. `int data;`

- Ini adalah nilai yang disimpan di node tersebut.
    
- Bisa berupa angka, huruf, atau bahkan tipe lain — tapi saat ini kita pakai `int` supaya fokus ke struktur.
    

### 🔍 3. `struct Node *left, *right;`

- Ini adalah **pointer** ke dua child:
    
    - `left` → child kiri dari node ini.
        
    - `right` → child kanan dari node ini.
        
- Karena ini **binary tree**, hanya ada dua child maksimum.
    

> 🔁 Jadi: Node bisa menunjuk ke node lainnya → struktur ini disebut **self-referential struct**.

### 🔍 4. `Node(int data)` → Constructor

Ini adalah **constructor**, yang digunakan saat kamu menulis `new Node(12)` misalnya.

Penjelasan langkah demi langkah:

```cpp
Node(int data) {
    this->data = data;      // Menyimpan nilai ke dalam data anggota struct
    left = right = NULL;    // Set awal anak kiri dan kanan ke NULL
}
```

Kenapa `this->data`?

- Karena nama parameter (`data`) sama dengan nama member (`data`), jadi kita perlu `this->` untuk membedakan antara _parameter lokal_ dan _variabel dalam struct_.
    

---

## ❓ Kenapa Harus `new Node(...)`?

### 1. `new` artinya kita alokasi memori di heap

- Tree bersifat **dinamis** — kita tidak tahu berapa banyak node yang dibutuhkan.
    
- Maka, kita perlu memesan memori secara **dinamis**, dan ini dilakukan dengan `new`.
    

Contoh:

```cpp
Node* root = new Node(10);
```

Artinya:

- Buat objek `Node` di heap (bukan stack),
    
- Dan simpan alamatnya ke pointer `root`.
    

---

### ✳️ Analogi

Bayangkan setiap `Node` adalah **rumah**.  
`data` = siapa yang tinggal di rumah.  
`left` dan `right` = alamat rumah tetangganya.

Saat kamu buat pohon:

```cpp
root->left = new Node(5);
```

Artinya kamu membangun rumah baru untuk child kiri dan menyambungkannya ke rumah utama (`root`).

---

### 📌 Ringkasan:

| Komponen            | Fungsi                                                    |
| ------------------- | --------------------------------------------------------- |
| `struct Node`       | Membentuk blueprint node tree                             |
| `int data`          | Menyimpan nilai dari node                                 |
| `Node* left, right` | Menyimpan alamat child kiri dan kanan                     |
| `Node(int data)`    | Constructor untuk mengisi data awal dan set child ke NULL |
| `new Node(x)`       | Alokasi node baru secara dinamis di heap                  |
