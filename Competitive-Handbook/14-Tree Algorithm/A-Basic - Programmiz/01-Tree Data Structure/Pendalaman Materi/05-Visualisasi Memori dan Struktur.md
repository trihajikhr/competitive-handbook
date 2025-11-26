---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Visualisasi Memori dan Struktur
sumber: Google.com, AI
date_learned: 2025-06-27T15:04:00
tags:
  - tree-algorithm
---
Link Sumber: 

---
# Visualisasi Memori dan Struktur

Untuk memahami apa yang terjadi “di balik layar” saat kita membangun dan menelusuri sebuah **binary tree**, mari kita lihat **bagaimana memori** dialokasikan dan **bagaimana pointer** saling terhubung.

---

## Alokasi di Heap vs Stack

```cpp
Node* root = new Node(10);
```

- **Heap**
    
    - `new Node(10)` akan memesan memori di heap untuk menampung satu `Node` (biasanya 24 byte: 4 bytes untuk `int data` + 8 bytes untuk pointer `left` + 8 bytes untuk pointer `right`, tergantung arsitektur).
        
    - Alamat heap ini yang disimpan di `root` (variabel di **stack**).
        
- **Stack**
    
    - Variabel `root` (bertipe `Node*`) ditempatkan di stack dan menyimpan alamat memori heap.
        

```
Stack                   Heap
┌───────────────┐       ┌───────────────────────────┐
│ root          │───┐   │ [0x7f8ab000]              │
│ (Node* ptr)   │   └──>│ data = 10                 │
│               │       │ left = nullptr            │
└───────────────┘       │ right = nullptr           │
                        └───────────────────────────┘
```

---
## Struktur `Node` di Memori

Misalkan `Node` disusun seperti ini:

```cpp
struct Node {
    int data;       // 4 bytes
    Node* left;     // 8 bytes (64-bit)
    Node* right;    // 8 bytes
};
```

Di memori akan tampak sebagai blok berurutan:

```
Address    | Content
--------------------------------
0x7f8ab000 | [00 00 00 0A]       // data = 10
0x7f8ab004 | [00 00 00 00 00 00 00 00]  // left = nullptr
0x7f8ab00C | [00 00 00 00 00 00 00 00]  // right = nullptr
```

- **Byte-ordering** (endianness) dapat memengaruhi tampilan byte, tapi konsepnya sama.
    

---

## Menyambung Beberapa Node

Contoh pembentukan sederhana:

```cpp
struct Node * root = new Node(10);
root->left  = new Node(5);
root->right = new Node(20);
```

Visualisasinya:

```
Stack                        Heap
┌───────────────┐            ┌──────────────────┐       ┌──────────────────┐
│ root          │───┐        │ [0x7f8ab000]     │       │ [0x7f8ac000]     │
│               │   │        │ data = 10        │       │ data = 5         │
└───────────────┘   │        │ left = 0x7f8ac000│<───┐  │ left = nullptr   │
                    │        │ right=0x7f8ad000 │<─┐ └─>│ right= nullptr   │
                    │        └──────────────────┘  │    └──────────────────┘
                    │                              │
                    │                              │
                    │        ┌──────────────────┐  │    ┌──────────────────┐
                    └──────> │ [0x7f8ad000]     │<─┘    │ [0x7f8ae000]     │
                             │ data = 20        │       │ data = ?         │
                             │ left = nullptr   │       │ ...              │
                             │ right=nullptr    │       └──────────────────┘
                             └──────────────────┘
```

- Setiap `new Node(value)` mengembalikan alamat unik di heap.
    
- Pointer `root->left` dan `root->right` diubah untuk menunjuk alamat–alamat tersebut.
    

---

## Visualisasi Traversal (Contoh Inorder)

Saat melakukan:

```cpp
void inorder(Node* node) {
  if (!node) return;
  inorder(node->left);
  visit(node);
  inorder(node->right);
}
```

Panggilan rekursif terjadi _secara depth-first_, memanfaatkan **stack call**:

```
Call Stack (top → bottom)
──────────────────────────────────────
inorder(root->right)
inorder(root)         // setelah inorder(root->left) selesai
inorder(root->left)

main()                // sebelum memanggil inorder(root)
```

---

## Ringkasan

- **Node** dialokasikan di **heap**, pointer dikelola di **stack**.
    
- **Pointer** menyambung antar node membentuk struktur tree.
    
- **Rekursi** traversal menggunakan call stack untuk menelusuri node.
    

Dengan visualisasi di atas, kamu lebih memahami:

1. **Di mana** node disimpan (heap).
    
2. **Bagaimana** pointer menghubungkan node.
    
3. **Bagaimana** traversal rekursif bergerak melalui memori.
    

