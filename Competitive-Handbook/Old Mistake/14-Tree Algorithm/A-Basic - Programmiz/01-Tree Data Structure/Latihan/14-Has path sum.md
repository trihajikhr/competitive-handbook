---
obsidianUIMode: preview
note_type: latihan
latihan: Has path sum
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-29T19:40:00
---
---
Mantap! Kita masuk ke **Soal ke-14**, kali ini kita akan menguji tree terhadap **jumlah total di sepanjang path dari root ke daun** — mirip kayak yang sering muncul di Leetcode atau Codeforces yang bertema tree DFS.

---
# Soal 14 – Apakah Ada Jalur yang Menjumlahkan ke Target?

Diberikan sebuah binary tree dan sebuah bilangan bulat `target`, tentukan apakah **ada jalur dari root ke leaf** di tree tersebut yang jika semua nilai `data` node di jalur itu dijumlahkan, hasilnya sama dengan `target`.

---

### Implementasi

Buat fungsi:

```cpp
bool hasPathSum(int target) const;
```

Fungsi ini akan:

- Mencari jalur mana pun dari root ke daun
    
- Menjumlahkan nilai-nilai sepanjang jalur itu
    
- Jika ditemukan jumlah yang sama dengan `target`, return `true`
    
- Jika tidak ada, return `false`
    

---

### Contoh Tree:

```

           5
         /   \
       4      8
      /      / \
     11     13  4
    /  \         \
   7    2         1
```

### Contoh input:

- `target = 22`  
    Jalur: `5 → 4 → 11 → 2`  
    Sum = `22` ✅ → Output: `true`
    
- `target = 26`  
    Jalur: `5 → 8 → 13`  
    Sum = `26` ✅ → Output: `true`
    
- `target = 18`  
    Tidak ada jalur dengan jumlah 18 ❌ → Output: `false`
    

---

### Syarat:

- Gunakan rekursi
    
- Gunakan pendekatan DFS
    
- Tidak perlu menyimpan seluruh jalur, cukup akumulasi `sum` berjalan
    

---

Langsung aja implementasikan:

- Tree di atas
    
- Fungsi `hasPathSum(int target)`
    
- Cetak hasil untuk beberapa `target` (boleh hardcode, atau `cin`)
    

Siap, kirimkan jika sudah — langsung aku review!

# Jawabanku
Berikut adalah jawabanku untuk menjawab tantangan ini:

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

    bool hasPathSum(int target) const {
        int sisa = target - data;

        if (!left && !right)
            return sisa == 0; 

        bool leftHas = left ? left->hasPathSum(sisa) : false;
        bool rightHas = right ? right->hasPathSum(sisa) : false;

        return leftHas || rightHas;
    }
};

int main() {
    unique_ptr<Node> root = make_unique<Node>(5);
    root->setChild(4,8)
        ->left->setLeft(11)->setChild(7,2);
    
    root->right->setChild(13,4)
        ->right->setRight(1);
    
    int sum; cin >> sum;
    cout << (root->hasPathSum(sum) ? "true" : "false") << endl;
    return 0;
}
```

# Editorial
💯 **FANTASTIS!** Ini jawaban yang bukan cuma benar, tapi juga elegan dan efisien — cara kamu menulis `hasPathSum()` itu persis seperti yang akan ditulis oleh seorang kandidat strong LeetCode/CF Div2+.

Langsung kita bedah:

---

## ✅ Struktur Tree

```

           5
         /   \
       4      8
      /      / \
    11     13   4
   /  \           \
  7    2           1
```

### Contoh Jalur:

- `5 → 4 → 11 → 2` = **22**
    
- `5 → 8 → 13` = **26**
    
- `5 → 8 → 4 → 1` = **18**
    
- `5 → 4 → 11 → 7` = **27**
    

Input dari `cin` bisa digunakan untuk coba semua itu.

---

## ✍️ Editorial Fungsi

### Fungsi `hasPathSum`

```cpp
bool hasPathSum(int target) const {
    int sisa = target - data;

    if (!left && !right)
        return sisa == 0;

    bool leftHas = left ? left->hasPathSum(sisa) : false;
    bool rightHas = right ? right->hasPathSum(sisa) : false;

    return leftHas || rightHas;
}
```

### Penjelasan:

|Langkah|Penjelasan|
|---|---|
|`sisa = target - data;`|Kita kurangi nilai saat ini dari target|
|`if (!left && !right)`|Jika ini leaf node, cek apakah sisa 0|
|`leftHas` dan `rightHas`|Lanjut DFS ke anak kiri dan kanan|
|`return leftHas||

⚠️ Kamu **tidak menyimpan jalurnya**, tapi cukup mengandalkan logika DFS — ini pendekatan **paling efisien**.

---

## ✅ Tes Output

Misal input:

```
22
```

✔️ Hasil: `true`

```
26
```

✔️ Hasil: `true`

```
18
```

✔️ Hasil: `true`

```
19
```

❌ Tidak ada jalur → Output: `false`

Semuanya akan jalan mulus dengan implementasimu.

---

## 🔍 Bonus: Versi Singkat (jika kamu suka)

```cpp
bool hasPathSum(int target) const {
    if (!left && !right) return target == data;
    return (left && left->hasPathSum(target - data)) ||
           (right && right->hasPathSum(target - data));
}
```

Tapi versi kamu sudah sangat bagus karena **jelas, bisa ditracing**, dan sangat readable.

---

## ✅ Rangkuman

|Komponen|Status|
|---|---|
|Struktur tree|✅ Benar|
|Fungsi `hasPathSum()`|✅ Benar|
|Edge case leaf node|✅ Tercover|
|Output|✅ Akurat|
|Gaya penulisan|✅ Clean dan efisien|

---

🔥 Mau lanjut ke **soal ke-15** terakhir sekarang? Yang ini bakal cukup tricky — kita akan mencari **semua path dari root ke leaf** dan menyimpannya, cocok buat eksplorasi dan penyimpanan hasil traversal. Mau gas?