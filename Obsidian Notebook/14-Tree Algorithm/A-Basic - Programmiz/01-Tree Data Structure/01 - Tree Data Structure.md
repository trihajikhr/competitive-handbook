---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 14TH-TREE-00A1
nama_algoritma: 
kategori_algoritma: tree algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: programiz.com
date_learned: 2025-06-23T23:39:00
tags:
  - tree-algorithm
---
Link sumber: [Tree Data Structure](https://www.programiz.com/dsa/trees)

---
# Struktur Data Tree

**Tree** adalah struktur data hierarkis non-linear yang terdiri dari **node-node** yang saling terhubung melalui **edge**.

![[Tree Data Structure-1.png]]

---
## Mengapa Menggunakan Struktur Data Tree?

Struktur data lain seperti array, linked list, stack, dan queue adalah struktur data linear yang menyimpan data secara sekuensial. Untuk melakukan operasi apa pun pada struktur data linear, kompleksitas waktunya akan meningkat seiring dengan bertambahnya ukuran data. Hal ini tidak dapat diterima dalam dunia komputasi modern saat ini.

Berbeda dengan itu, berbagai jenis **struktur data tree** memungkinkan akses data yang **lebih cepat dan lebih efisien**, karena merupakan **struktur data non-linear**.

## Terminologi dalam Tree

### Node

**Node** adalah entitas yang berisi sebuah **key** atau **value**, serta **pointer** ke node-node anak (**child nodes**)-nya.

Node terakhir pada setiap jalur (path) disebut **leaf node** atau **external node**, yaitu node yang **tidak memiliki link/pointer** ke child node mana pun.

Node yang memiliki **setidaknya satu child node** disebut sebagai **internal node**.

### Edge

**Edge** adalah **hubungan (link)** atau **sambungan** antara dua node.

![[Tree Data Structure-2.png]]

### Root

**Root** adalah node paling atas dalam sebuah tree.

### Height of a Node

**Height (tinggi) dari sebuah node** adalah jumlah **edge** dari node tersebut hingga ke **leaf node** terdalam (yaitu, jalur terpanjang dari node tersebut menuju sebuah leaf node).

### Depth of a Node

**Depth (kedalaman) dari sebuah node** adalah jumlah **edge** dari **root** hingga ke node tersebut.

### Height of a Tree

**Height dari sebuah tree** adalah **height dari root node** atau sama dengan **depth dari node terdalam**.

![[Tree Data Structure-3.png]]

### Degree of a Node

**Degree** dari sebuah **node** adalah jumlah total **cabang** (branch) atau **child node** yang dimiliki oleh node tersebut.

### Forest

**Forest** adalah kumpulan dari **tree-tree yang tidak saling terhubung** (**disjoint trees**).

![[Tree Data Structure-4.png]]

Kamu bisa membuat sebuah **forest** dengan **memotong root** dari sebuah **tree**.

---

## Jenis-Jenis Tree

- [[03 - Binary Tree]]
    
- [[08 - Binary Search Tree]]
    
- [[09 - AVL Tree]]
    
- [[01 - B-tree]]
    

---

## Tree Traversal

Untuk melakukan operasi apa pun pada sebuah **tree**, kamu perlu mencapai **node tertentu**. **Algoritma tree traversal** membantu dalam **mengunjungi node yang dibutuhkan** di dalam tree.

> Untuk mempelajari lebih lanjut, silakan kunjungi topik [[02 - Tree Traversal - inorder, preorder and postorder]].

---

## Aplikasi Tree

- **Binary Search Tree (BST)** digunakan untuk **mengecek dengan cepat** apakah suatu elemen terdapat dalam sebuah **set** atau tidak.
<br/>
- **Heap** adalah jenis tree yang digunakan untuk **heap sort**.
<br/>
- Versi modifikasi dari tree yang disebut **Trie** digunakan dalam **router modern** untuk menyimpan informasi routing.
<br/>
- **Database populer** banyak menggunakan **B-Trees** dan **T-Trees**, yang merupakan **varian dari struktur tree** yang telah kita pelajari, untuk menyimpan data mereka.
<br/>
- **Compiler** menggunakan **syntax tree** untuk **memvalidasi sintaks** dari setiap program yang kamu tulis.

