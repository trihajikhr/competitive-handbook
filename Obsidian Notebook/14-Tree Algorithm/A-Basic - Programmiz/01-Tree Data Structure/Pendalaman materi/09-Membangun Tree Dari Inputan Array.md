---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Membangun Tree Dari Inputan Array
sumber: chatgpt.com
date_learned: 2025-06-27T14:44:00
tags:
  - tree-algorithm
---
Link Sumber: 

---
# Membangun Tree Dari Inputan Array

> Apakah bisa membuat tree dari inputan berupa array, sehingga kita tidak perlu menggunakan metode manual?

Bisa banget! Kalau kamu ingin membangun _binary tree_ dari input berbentuk **array**, kamu bisa melakukannya dengan **presisi penuh**, terutama jika bentuk pohonnya adalah **Complete Binary Tree** atau disusun sesuai **Level Order** (tingkat demi tingkat, dari kiri ke kanan).

---

## Kasus 1: Tree dari Array → Complete Binary Tree

Untuk **complete binary tree**, kamu bisa pakai indeks array untuk langsung menyusun seperti:

- `A[0]` → root
    
- `A[1]` → left child of A[0]
    
- `A[2]` → right child of A[0]
    
- `A[3]` → left child of A[1], dan seterusnya…
    

```cpp
Node* buildCompleteTree(const vector<int>& A, int idx = 0) {
    if (idx >= A.size() || A[idx] == -1) return nullptr;

    Node* node = new Node(A[idx]);
    node->left = buildCompleteTree(A, 2 * idx + 1);
    node->right = buildCompleteTree(A, 2 * idx + 2);
    return node;
}
```

**Contoh Pemakaian:**

```cpp
vector<int> arr = {10, 5, 20, 3, 8, 15, 25};  // bentuk complete binary tree
Node* root = buildCompleteTree(arr);
```

### BONUS: Visual Struktur dari Array

Jika `A = {10, 5, 20, 3, 8, 15, 25}`

```

           10
         /    \
       5       20
      / \     /  \
     3   8   15   25
     
```

---

## Kasus 2: Tree dari Array Level-order dengan NULL

Jika kamu ingin mendukung **node kosong** seperti ini:

```cpp
vector<optional<int>> arr = {
    10,
    5, 20,
    nullopt, 8, 15, 25
};
```

Gunakan pendekatan dengan queue:

```cpp
Node* buildLevelOrderTree(const vector<optional<int>>& A) {
    if (A.empty() || !A[0].has_value()) return nullptr;

    Node* root = new Node(A[0].value());
    queue<Node*> q;
    q.push(root);
    int idx = 1;

    while (!q.empty() && idx < A.size()) {
        Node* curr = q.front(); q.pop();

        // kiri
        if (idx < A.size() && A[idx].has_value()) {
            curr->left = new Node(A[idx].value());
            q.push(curr->left);
        }
        idx++;

        // kanan
        if (idx < A.size() && A[idx].has_value()) {
            curr->right = new Node(A[idx].value());
            q.push(curr->right);
        }
        idx++;
    }
    return root;
}
```

**Contoh:**

```cpp
vector<optional<int>> arr = {
    10,
    5, 20,
    nullopt, 8, 15, 25
};
Node* root = buildLevelOrderTree(arr);
```

---

## Jika Tidak Punya `optional` (misal di C++11/14)

Gunakan sentinel value, misal `-1`:

```cpp
Node* buildTreeWithNull(const vector<int>& A, int idx = 0) {
    if (idx >= A.size() || A[idx] == -1) return nullptr;

    Node* node = new Node(A[idx]);
    node->left = buildTreeWithNull(A, 2 * idx + 1);
    node->right = buildTreeWithNull(A, 2 * idx + 2);
    return node;
}
```

---


# Membangun Tree Acak 

> Lalu, bagaimana jika tree yang ingin kita buat bukan complete tree? Apakah akan susah menggunakan cara seperti diatas?

Iya, betul banget! Kalau **bukan complete binary tree** (misalnya pohon tidak penuh atau bentuknya acak), membangun tree dari array **akan lebih rumit**, karena kita tidak bisa langsung menentukan siapa anak kiri dan anak kanan hanya berdasarkan indeks.

---

## Kenapa Susah Kalau Bukan Complete Binary Tree?

Karena:

- Struktur pohonnya **tidak bisa ditebak** hanya dari posisi elemen array.
    
- Perlu **penanda** untuk mengetahui apakah posisi tertentu adalah anak kiri atau kanan, atau apakah sebuah node ada atau tidak.
    

---

## Solusi Umum: Pakai Level Order + Null

Agar bisa menangani tree bentuk **bebas**, cara paling fleksibel adalah:

> Gunakan array seperti ini (misal pakai `optional<int>` atau sentinel `-1`) dan bangun dengan **queue**.

Contoh:

```cpp
vector<optional<int>> arr = {
    1,
    2, 3,
    nullopt, 4, nullopt, 5
};
```

Tree-nya akan jadi:

```

       1
      / \
     2   3
      \    \
       4    5
       
```

Dan kita **tidak bisa** bangun ini dengan pendekatan "index ke-2*i+1" karena formasinya tidak lengkap.

---

## Alternatif Format Input Lain

Jika kamu ingin input fleksibel dari array, bisa gunakan format **Parent-Child** seperti ini:

```cpp
// (parent, left, right)
vector<tuple<int, int, int>> nodes = {
    {10, 5, 20},
    {5, 3, 8},
    {20, 15, 25}
};
```

Ini bentuk seperti tabel hubungan antar node. Bisa kamu pakai untuk membangun tree secara presisi.

---

### Kesimpulan

- ✅ **Complete Tree → gampang** → cukup pakai `2*i+1`, `2*i+2`.
    
- ⚠️ **Partial / Incomplete Tree → butuh extra informasi** → seperti `null`, atau format relasi.
    
- ✅ Kalau pakai `vector<optional<int>>`, kamu bisa bangun tree acak dengan struktur bebas.
    

