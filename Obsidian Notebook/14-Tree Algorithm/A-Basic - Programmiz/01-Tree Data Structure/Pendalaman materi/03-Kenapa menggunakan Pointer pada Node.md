---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Kenapa menggunakan Pointer pada Node
sumber: chatgpt.com
tags:
  - tree-algorithm
---
---
# Kenapa menggunakan Pointer pada Node
 
Ini inti dari mengapa kita selalu menggunakan **pointer (`Node*`)** dalam struktur tree di C++. Yuk kita bahas satu per satu secara logis dan mendalam — kamu akan langsung melihat kenapa ini sangat masuk akal.

---

## Pertanyaan:

- Kenapa saat mendeklarasikan `Node`, kita menjadikannya **pointer**?
- Kenapa parameter fungsi seperti `inorderTraversal()` juga menggunakan **pointer (`Node*`)**?

---

## 1. Kenapa pakai `Node*` saat menyimpan child (`left`, `right`)

### 🔧Penjelasan teknis:

```cpp
struct Node {
    int data;
    Node *left, *right;
};
```

Bayangkan kalau kita **tidak** pakai pointer:

```cpp
struct Node {
    int data;
    Node left;  // ⚠️ Tidak boleh!
    Node right;
};
```

> ❌ Ini akan menyebabkan **rekursi tak berujung saat kompilasi**, karena:

- `Node` punya `Node` di dalamnya, yang juga punya `Node`, dan seterusnya...
    
- Compiler tidak akan bisa menentukan berapa ukuran `Node` karena tidak pernah selesai.
    

✅ **Solusi: Gunakan pointer!**

- Pointer hanya menyimpan **alamat** ke node lain, bukan isinya langsung.
    
- Ini memutus rantai tak berujung, karena ukuran pointer tetap (biasanya 4 atau 8 byte), berapa pun dalamnya tree.
    

---

## 2. Kenapa fungsi seperti `inorderTraversal(Node*)` pakai pointer juga?

Karena kita ingin **mengakses dan memodifikasi** node asli yang ada di memori heap.

```cpp
void inorderTraversal(Node* node) {
    if(node == NULL) return;
    inorderTraversal(node->left);
    cout << node->data << " -> ";
    inorderTraversal(node->right);
}
```

Alasannya:

- Fungsi ini berjalan **secara rekursif**, menavigasi seluruh struktur tree.
    
- Tree dibangun menggunakan `new` (memori heap), dan hanya bisa diakses lewat **pointer**.
    
- Kalau kita pakai **bukan pointer** (misalnya `Node node`), maka hanya salinan lokal yang akan dibuat, dan perubahan tidak mempengaruhi node asli.
    

---

## Analogi Singkat:

Bayangkan kamu sedang menjelajahi rumah-rumah (node).

- Kalau kamu punya **alamat rumahnya (pointer)**, kamu bisa berpindah dari satu rumah ke rumah lainnya tanpa membuat rumah baru.
    
- Tapi kalau kamu hanya menyalin isi rumah ke dalam rumahmu sendiri, kamu **tidak bisa melanjutkan perjalanan** ke rumah-rumah tetangganya.
    

---

## Ringkasan:

| Konteks                            | Kenapa pakai Pointer (`Node*`)                                        |
| ---------------------------------- | --------------------------------------------------------------------- |
| `left` dan `right` di dalam `Node` | Agar tidak terjadi rekursi tak berujung dan untuk navigasi antar node |
| Parameter fungsi traversal         | Agar bisa membaca struktur asli dari tree yang tersimpan di heap      |
| Saat `new Node(...)`               | Karena objek disimpan di heap, dan perlu pointer untuk mengaksesnya   |
# Alasan Menggunakan Pointer (lanjutan)
Pada **binary tree** (dan kebanyakan struktur data tree), kita pakai **pointer** karena beberapa alasan mendasar:

## Ukuran Dinamis  
- Tree bisa tumbuh (nambah node) atau menyusut (hapus node) kapan saja.  
- Dengan `new` dan pointer, kita bisa mengalokasi memori di **heap** secara dinamis sesuai kebutuhan—tidak terbatas pada ukuran tetap seperti array.

## Hubungan Antar Node  
- Setiap node punya dua “jalur” (child kiri dan kanan).  
- Pointer (`Node* left`, `Node* right`) memungkinkan satu node menyimpan **alamat** node anaknya, membentuk struktur bercabang (non­-linier) yang fleksibel.
    
## Rekursi & Navigasi  
- Traversal Tree (preorder, inorder, postorder) bersifat rekursif: fungsi memanggil dirinya sendiri untuk `node->left` dan `node->right`.  
- Tanpa pointer, kita tidak punya cara mudah untuk “lompat” ke node yang lain.
    
## Efisiensi Memori  
- Jika sebuah node tidak punya child kiri/kanan, pointer-nya cukup di-set ke `nullptr`—tidak ada alokasi ekstra.  
- Berbeda dengan array 2D atau matriks, yang akan membuang ruang untuk posisi anak yang kosong.

## Representasi Umum  
- Banyak algoritma tree (misalnya pencarian di BST, heap, segment tree) mengharuskan perpindahan langsung ke anak atau parent. Pointer adalah cara paling langsung dan efisien untuk itu.


---

**Singkatnya:**  

Pointer membuat **struktur Tree** menjadi fleksibel, dinamis, dan mudah di­-traverse secara rekursif—cocok untuk semua kebutuhan algoritma dan aplikasi yang melibatkan tree.