---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: 20 Cara Membangun dan Menginisialisasi Tree
sumber: Google.com, AI
date_learned: 2025-06-27T14:38:00
tags:
  - tree-algorithm
---
Link Sumber: 

---
# 20 Cara Membangun dan Menginisialisasi Tree
Berikut beberapa **cara / pola** untuk “mengisikan” atau **membangun (populate)** sebuah binary tree, mulai dari yang manual hingga yang otomatis dan lebih “smart”. Pilih sesuai kebutuhanmu!

---

## 1. Manual Link-by-Link

Langsung `new` node satu per satu dan hubungkan anaknya.

```cpp
Node* root = new Node(10);
root->left        = new Node(5);
root->right       = new Node(20);
root->left->left  = new Node(3);
root->left->right = new Node(8);
root->right->left = new Node(15);
root->right->right= new Node(25);
```

---

## 2. Fungsi `insert()` untuk Binary Search Tree

Kalau tree-mu adalah BST, gunakan fungsi insert rekursif:

```cpp
Node* insert(Node* node, int val) {
    if (!node) return new Node(val);
    if (val < node->data)
        node->left  = insert(node->left,  val);
    else
        node->right = insert(node->right, val);
    return node;
}

// pemakaian
Node* root = nullptr;
for (int v : {10,5,20,3,8,15,25})
    root = insert(root, v);
```

Maka tree yang terbentuk akan menjadi:

```

          10
         /  \
       5     20
      / \    / \
     3   8  15 25

```

---

## 3. Membangun Balanced BST dari Sorted Array

Ideal saat kamu punya data terurut, dan butuh tree seimbang:

```cpp
Node* buildBalanced(vector<int>& A, int lo, int hi) {
    if (lo > hi) return nullptr;
    int mid = (lo + hi) / 2;
    Node* node = new Node(A[mid]);
    node->left  = buildBalanced(A, lo,   mid-1);
    node->right = buildBalanced(A, mid+1, hi);
    return node;
}

// pemakaian
vector<int> A = {3,5,8,10,15,20,25};
Node* root = buildBalanced(A, 0, A.size()-1);
```

---

## 4. Build dari Level-Order Array dengan Queue

Beri array (atau `vector`) termasuk marker `-1`/`NULL` untuk anak yang kosong:

```cpp
// array level-order: -1 artinya NULL
vector<int> arr = {10,5,20,3,8,-1,25,-1,-1,-1,-1};
// gunakan queue untuk assign anak
queue<Node*> q;
Node* root = new Node(arr[0]); q.push(root);
int i = 1;
while (!q.empty() && i < arr.size()) {
    Node* cur = q.front(); q.pop();
    if (arr[i] != -1) {
        cur->left = new Node(arr[i]);
        q.push(cur->left);
    }
    i++;
    if (i < arr.size() && arr[i] != -1) {
        cur->right = new Node(arr[i]);
        q.push(cur->right);
    }
    i++;
}
```

---

## 5. Build dari Preorder + Inorder (Rekonstruksi)

Diberikan dua traversal, kamu bisa mengembalikan struktur tree:

```cpp
Node* buildPI(vector<int>& pre, int preL, int preR,
              vector<int>& in,  int inL,  int inR,
              unordered_map<int,int>& inPos) {
    if (preL > preR) return nullptr;
    int rootVal = pre[preL];
    Node* root = new Node(rootVal);
    int k = inPos[rootVal];
    int leftCount = k - inL;
    root->left  = buildPI(pre, preL+1, preL+leftCount, in, inL, k-1, inPos);
    root->right = buildPI(pre, preL+leftCount+1, preR, in, k+1, inR, inPos);
    return root;
}

// panggil dengan hash-mapping posisi inorder
```

---

## 6. Build dari String “Bracket Notation”

Misal representasi seperti `"10(5(3,8),20(,25))"` — parse secara rekursif.

```cpp
Node* parse(const string& s, int& pos) {
    // baca angka, lalu jika ada '(', parse anak kiri, skip ',', parse anak kanan
    // implementasi memakai helper recursive-descent
}
```

---

## 7. Initializer-List Aggregate (C++20)

Jika `Node` punya constructor dengan default args:

```cpp
struct Node {
    int data;
    Node* left=nullptr, *right=nullptr;
    Node(int v, Node* l=nullptr, Node* r=nullptr)
      : data(v), left(l), right(r) {}
};

// Kemudian:
Node* root = new Node(10,
                new Node(5,new Node(3),new Node(8)),
                new Node(20,nullptr,new Node(25))
              );
```

---

## 8. Functional-Style Persistent Tree

Buat `shared_ptr` immutable nodes:

```cpp
using PNode = shared_ptr<const NodeF>;
struct NodeF {
    int data; PNode left, right;
    NodeF(int v, PNode l=nullptr, PNode r=nullptr)
      : data(v), left(l), right(r) {}
};
// build sama dengan versi 3, tapi alloca with make_shared<NodeF>
```

---

## 9. Build via Range Insertion (Divide-and-Conquer)

Untuk balanced random tree:

```cpp
Node* buildRand(vector<int>& A, int lo, int hi) {
    if (lo>hi) return nullptr;
    int idx = rand() % (hi-lo+1) + lo;
    Node* node = new Node(A[idx]);
    node->left  = buildRand(A, lo,   idx-1);
    node->right = buildRand(A, idx+1, hi);
    return node;
}
```

---

## 10. Build by Inserting in a Heap-like Manner

Kalau tree-mu mewakili heap:

```cpp
vector<int> H = {—,10,5,20,3,8,15,25}; // 1-based
function<Node*(int)> buildHeap = [&](int i) -> Node* {
  if (i >= H.size()) return nullptr;
  Node* cur = new Node(H[i]);
  cur->left  = buildHeap(i*2);
  cur->right = buildHeap(i*2+1);
  return cur;
};
Node* root = buildHeap(1);
```

---

## 11. Build dari Input Level-order Pakai Queue (Interaktif)

Cocok untuk soal interaktif:

```cpp
Node* buildFromInput() {
    int val; cin >> val;
    if (val == -1) return nullptr;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front(); q.pop();

        int l, r;
        cin >> l >> r;

        if (l != -1) {
            curr->left = new Node(l);
            q.push(curr->left);
        }
        if (r != -1) {
            curr->right = new Node(r);
            q.push(curr->right);
        }
    }
    return root;
}
```

---

## 12. Build Tree from Postorder + Inorder

Seperti cara #5, tapi postorder dan inorder:

```cpp
Node* buildPI(vector<int>& post, int postL, int postR,
              vector<int>& in, int inL, int inR,
              unordered_map<int,int>& inPos) {
    if (postL > postR) return nullptr;
    int rootVal = post[postR];
    Node* root = new Node(rootVal);
    int k = inPos[rootVal];
    int leftCount = k - inL;
    root->left  = buildPI(post, postL, postL+leftCount-1, in, inL, k-1, inPos);
    root->right = buildPI(post, postL+leftCount, postR-1, in, k+1, inR, inPos);
    return root;
}
```

---

## 13. Build Tree dari Array Representasi Heap (0-indexed)

Khusus array representasi tree binary penuh (complete binary tree):

```cpp
Node* buildCompleteTree(const vector<int>& A, int idx) {
    if (idx >= A.size()) return nullptr;
    Node* node = new Node(A[idx]);
    node->left = buildCompleteTree(A, 2*idx+1);
    node->right = buildCompleteTree(A, 2*idx+2);
    return node;
}
```

---

## 14. Build dari Vector of Pairs (Parent-Child Info)

Cocok untuk input berupa daftar hubungan:

```cpp
// {parent, {left, right}}, -1 jika kosong
map<int, pair<int,int>> treeData = {
    {10, {5, 20}}, {5, {3, 8}}, {20, {15, 25}}, ...
};

unordered_map<int, Node*> nodes;

Node* buildFromPairs(int rootVal) {
    if (nodes.count(rootVal)) return nodes[rootVal];
    Node* root = new Node(rootVal);
    nodes[rootVal] = root;

    if (treeData.count(rootVal)) {
        auto [l, r] = treeData[rootVal];
        if (l != -1) root->left  = buildFromPairs(l);
        if (r != -1) root->right = buildFromPairs(r);
    }
    return root;
}
```

---

## 15. Build Tree dari Serialized String (Preorder)

Kamu bisa menyimpan tree sebagai string `"10 5 3 # # 8 # # 20 15 # # 25 # #"`  
(# = NULL)

```cpp
Node* deserialize(istringstream& in) {
    string val;
    in >> val;
    if (val == "#") return nullptr;

    Node* node = new Node(stoi(val));
    node->left  = deserialize(in);
    node->right = deserialize(in);
    return node;
}

// pemakaian
string data = "10 5 3 # # 8 # # 20 15 # # 25 # #";
istringstream in(data);
Node* root = deserialize(in);
```

## 16. Build dari Vector of Tuples (Node, Left, Right)  
Gunakan `vector<tuple<int, int, int>>` untuk menyatakan isi node dan dua anaknya. Cocok untuk data yang sudah lengkap dan eksplisit.

```cpp
struct Node {
    int data;
    Node *left, *right;
    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

Node* buildFromTuples(const vector<tuple<int, int, int>>& nodes) {
    unordered_map<int, Node*> mp;
    for (auto [val, l, r] : nodes)
        mp[val] = new Node(val);
    for (auto [val, l, r] : nodes) {
        if (l != -1) mp[val]->left  = mp[l];
        if (r != -1) mp[val]->right = mp[r];
    }
    return mp[nodes[0].get<0>()]; // asumsi root adalah node pertama
}

// pemakaian
vector<tuple<int,int,int>> data = {
    {10, 5, 20}, {5, 3, 8}, {20, 15, 25}, {3, -1, -1}, {8, -1, -1}, {15, -1, -1}, {25, -1, -1}
};
Node* root = buildFromTuples(data);
```

---

## 17. Build Tree dari Adjacency List (Rooted Tree)  
Jika diberikan adjacency list dan root diketahui, kamu bisa pakai DFS atau BFS untuk membangunnya.

```cpp
Node* buildFromAdjList(const vector<vector<int>>& adj, int u, int parent = -1) {
    Node* node = new Node(u);
    for (int v : adj[u]) {
        if (v != parent) { // hindari kembali ke parent
            if (!node->left) node->left = buildFromAdjList(adj, v, u);
            else             node->right = buildFromAdjList(adj, v, u);
        }
    }
    return node;
}

// pemakaian
vector<vector<int>> adj = {
    {},             // dummy 0-index (pakai 1-indexed)
    {2,3},          // 1
    {4,5},          // 2
    {},             // 3
    {},             // 4
    {}              // 5
};
Node* root = buildFromAdjList(adj, 1);
```

---

## 18. Build Tree dari Parent Array  
Gunakan array `parent[i]` yang menyatakan parent dari node `i`. Nilai `-1` berarti root.

```cpp
Node* buildFromParentArray(const vector<int>& parent) {
    int n = parent.size();
    vector<Node*> nodes(n);
    Node* root = nullptr;
    for (int i = 0; i < n; i++) nodes[i] = new Node(i);
    for (int i = 0; i < n; i++) {
        if (parent[i] == -1) root = nodes[i];
        else {
            Node* p = nodes[parent[i]];
            if (!p->left) p->left = nodes[i];
            else          p->right = nodes[i];
        }
    }
    return root;
}

// pemakaian
vector<int> parent = {-1, 0, 0, 1, 1, 2, 2}; // bentuk lengkap binary tree
Node* root = buildFromParentArray(parent);
```

---

## 19. Build Huffman Tree dari Frekuensi  
Bangun tree berdasarkan pasangan (frekuensi, nilai karakter) dengan priority queue. Digunakan untuk kompresi.

```cpp
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f): ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

Node* buildHuffman(const vector<pair<char, int>>& freqList) {
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto [ch, freq] : freqList)
        pq.push(new Node(ch, freq));
    while (pq.size() > 1) {
        Node* l = pq.top(); pq.pop();
        Node* r = pq.top(); pq.pop();
        Node* merged = new Node('-', l->freq + r->freq);
        merged->left = l;
        merged->right = r;
        pq.push(merged);
    }
    return pq.top();
}

// pemakaian
vector<pair<char, int>> freqs = {{'a', 5}, {'b', 9}, {'c', 12}, {'d', 13}, {'e', 16}, {'f', 45}};
Node* root = buildHuffman(freqs);
```

---

## 20. Build dari DFS Order + Depth Info  
Jika diketahui urutan DFS preorder dan kedalaman tiap node, tree bisa dibangun dengan stack.

```cpp
struct Info {
    int val, depth;
};

Node* buildFromDFSAndDepth(const vector<Info>& arr) {
    if (arr.empty()) return nullptr;
    stack<pair<Node*, int>> st;
    Node* root = new Node(arr[0].val);
    st.push({root, arr[0].depth});
    for (int i = 1; i < arr.size(); i++) {
        Node* node = new Node(arr[i].val);
        while (!st.empty() && st.top().second >= arr[i].depth)
            st.pop();
        if (!st.top().first->left) st.top().first->left = node;
        else                        st.top().first->right = node;
        st.push({node, arr[i].depth});
    }
    return root;
}

// pemakaian
vector<Info> nodes = {
    {10, 0}, {5, 1}, {3, 2}, {8, 2}, {20, 1}, {15, 2}, {25, 2}
};
Node* root = buildFromDFSAndDepth(nodes);
```
