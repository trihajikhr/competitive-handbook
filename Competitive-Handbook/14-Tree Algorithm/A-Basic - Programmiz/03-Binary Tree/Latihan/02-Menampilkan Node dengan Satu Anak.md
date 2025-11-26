---
obsidianUIMode: preview
note_type: latihan
latihan: Menampilkan Node dengan Satu Anak
sumber: myself
tags:
  - tree-algorithm
date_learned: 2025-07-01T17:58:00
---
---
# Menampilkan Node dengan Satu Anak


Diberikan sebuah **binary tree**, tugasmu adalah menampilkan semua node yang hanya memiliki **satu anak** (baik kiri saja atau kanan saja).

Node yang memiliki dua anak atau tidak punya anak **tidak ditampilkan**.

#### 📥 Input:

Sebuah struktur binary tree yang direpresentasikan dalam bentuk input seperti ini:

Input berupa barisan pasangan: parent child side
Contoh:

```text
5
A B L
A C R
B D L
C E R
E F L
```

Artinya:

- A adalah root.
    
- A punya anak kiri B, dan anak kanan C.
    
- B punya anak kiri D.
    
- C punya anak kanan E.
    
- E punya anak kiri F.
    

#### 📤 Output:

Tampilkan semua node yang memiliki **tepat satu anak**. Urutan output bebas, selama benar.

**Contoh Output dari input di atas:**

```
B
C
E
```

Karena:

- B hanya punya anak kiri (D).
    
- C hanya punya anak kanan (E).
    
- E hanya punya anak kiri (F).
    
- A punya dua anak → tidak ditampilkan.
    
- D dan F tidak punya anak → tidak ditampilkan.

# Jawabanku
Berikut adalah jawabanku yang memakan waktu 1 jam, dengan beberapa peningkatan yang masih bisa dilakukan:

```cpp
#include <iostream>
#include <memory>
using namespace std;

template <typename T>
struct Node {
    T data;
    unique_ptr<Node<T>> left, right;
    Node(T data) : data(data) {}

    Node* setLeft(T val){
        left = make_unique<Node<T>>(val);
        return left.get();
    }

    Node* setRight(T val){
        right = make_unique<Node<T>>(val);
        return right.get();
    }

    Node* setChild(T a, T b){
        setLeft(a); setRight(b);
        return this;
    }

    static void insertNode(unique_ptr<Node<T>>& root, T parent, T child, T post){
        if (!root) {
            root = make_unique<Node<T>>(parent);
            if (post == 'L') root->setLeft(child);
            else root->setRight(child);
            return;
        }

        if (root->data == parent) {
            if (post == 'L') root->setLeft(child);
            else root->setRight(child);
        } else {
            if (root->left) insertNode(root->left, parent, child, post);
            if (root->right) insertNode(root->right, parent, child, post);
        }
    }

    void traverse() const {
        if (left) left->traverse();
        cout << data << " ";
        if (right) right->traverse();
    }

    bool isOneChild() const {
        return (!left && right) || (left && !right); 
    }

    void oneChild() const {
        if(left) left->oneChild();
        if(right) right->oneChild();
        if(isOneChild()){
            cout << data << "\n";
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unique_ptr<Node<char>> root;

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        char a, b, c;
        cin >> a >> b >> c;

        Node<char>::insertNode(root, a, b, c);
    }

    root->oneChild();
    return 0;
}
```

# Editorial
Kodenya **sudah sangat bagus dan hampir sempurna** untuk menyelesaikan soal "menampilkan node yang hanya memiliki satu anak". Tapi agar kamu (atau penguji) tidak bingung dan program lebih kuat, ini beberapa catatan penting dan perbaikannya:

###  Yang Sudah Bagus:

- Penggunaan `unique_ptr` untuk manajemen memori modern.
    
- Fungsi `insertNode` bersifat rekursif, bagus untuk membangun tree dari input.
    
- Fungsi `isOneChild` dan `oneChild()` bersih dan sesuai kebutuhan soal.
    

### ⚠️ Catatan dan Perbaikan Minor:

1. **Masalah saat root belum terbentuk dan langsung anak ditambahkan**  
    Kode saat `!root` hanya membentuk root dengan satu anak, tapi tidak menangani kasus ketika `parent` dari `insertNode` **bukan root** dan root belum terbentuk. Tapi ini bisa kamu abaikan jika input selalu diberikan dari atas ke bawah.
<br/>
2. **Input format**  
    Program ini mengasumsikan input diberikan dalam format:  
    `parent child side`, contoh: `A B L`.  
    Pastikan user tahu format input ini, karena tidak ada prompt di `cin`.
<br/>
3. **Output akhir tambahan `\n`**  
    Tambahan `cout << '\n';` di akhir tidak masalah, tapi jika kamu ingin clean output, kamu bisa hilangkan.
    

---

### 💡 Saran Peningkatan (Opsional):

Jika kamu ingin menyortir hasil node (misalnya agar output selalu dalam urutan abjad atau urutan level), kamu bisa simpan hasil `oneChild()` ke dalam vector dulu:

```cpp
void oneChild(vector<T>& result) const {
    if (left) left->oneChild(result);
    if (right) right->oneChild(result);
    if (isOneChild()) {
        result.push_back(data);
    }
}
```

Dan di `main()`:

```cpp
vector<char> res;
root->oneChild(res);
for (char c : res) cout << c << '\n';
```


### ✅ Kesimpulan:

Kodenya **sudah benar dan sesuai dengan deskripsi soal**. Bisa digunakan langsung untuk evaluasi node dengan satu anak. Kalau kamu ingin soal lain berdasarkan tree ini, tinggal lanjut bilang aja ya!