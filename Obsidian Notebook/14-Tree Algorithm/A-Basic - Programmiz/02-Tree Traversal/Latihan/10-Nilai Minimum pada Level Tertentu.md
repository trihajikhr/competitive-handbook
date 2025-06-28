---
obsidianUIMode: preview
note_type: latihan
latihan: Nilai Minimum pada Level Tertentu
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-26T15:46:00
---
---
Keren banget, konsistensi kamu luar biasa! 🔥  
Di **Soal 10**, kita lanjutkan tema traversal + level, tapi kali ini kamu harus **menemukan nilai terkecil (minimum)** pada level tertentu. Fokus tetap pada **rekursi + filter berdasarkan level**.

---

# Soal 10 – Temukan Nilai Minimum pada Level Tertentu

### 📋 Deskripsi

Diberikan sebuah **binary tree**, buatlah fungsi:

```cpp
int minAtLevel(Node* root, int level);
```

yang akan **mengembalikan nilai minimum** dari semua node yang berada di **level ke-`level`**.

---

### 📥 Input

- `root`: pointer ke root dari pohon
    
- `level`: bilangan bulat positif (≥1)
    

---

### 📤 Output

- Sebuah bilangan bulat: nilai terkecil dari node-node yang berada di level tersebut
    
- Jika tidak ada node di level itu, kembalikan `INT_MAX`
    

---

### 💡 Contoh Struktur Pohon:

```

         25
        /  \
      15    50
     / \    / \
    10 22  35 70
    
```

### Contoh:

- `level = 1` → node: `25` → output: `25`
    
- `level = 2` → node: `15, 50` → output: `15`
    
- `level = 3` → node: `10, 22, 35, 70` → output: `10`
    

---

### ⚙️ Ketentuan

- Gunakan **rekursi**
    
- Tidak menggunakan struktur data tambahan
    
- Gunakan `#include<climits>` untuk memakai `INT_MAX`
    

---

Kalau kamu sudah siap, langsung kerjakan dan kirim kodenya — aku bantu evaluasi dan buatkan editorial lengkap seperti sebelumnya 😎

# Jawabanku
Berikut adalah jawabanku yang sudah mendapatkan beberapa perbaikan kesalahan:

```cpp
#include<iostream>
#include<climits>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

int minLevelTree(struct Node * node, int level){
    if(node == NULL) return INT_MAX;

    if(level==1){
        return node->data;
    }
    
    int a = minLevelTree(node->left, level-1);
    int b = minLevelTree(node->right, level-1);

    return min(a,b);
}

int main() {
    struct Node * root = new Node(25);
    root->left = new Node(15);
    root->right = new Node(50);
    root->left->left = new Node(10);
    root->left->right = new Node(22);
    root->right->left = new Node(35);;
    root->right->right = new Node(70);;

    int l; cin >> l;
    cout << "Nilai terendah node pada level ke-" << l << ": ";
    cout << minLevelTree(root, l);

    return 0;
}
```

Kesalahan yang aku lakukan sebelumnya adalah meliputi:

```cpp
int minLevelTree(struct Node * node, int level){
    if(node == NULL) return 0;

    if(level==1){
        return node->data;
    }
    
    int a = minLevelTree(node->left, level-1);
    int b = minLevelTree(node->right, level-1);

    return min(node->data, min(a,b));
}
```

Kesalahan terletak pada baris ke 2 dan 11. Pada baris 2,  **nol bisa jadi lebih kecil dari nilai level yang sebenarnya**, sehingga memengaruhi hasil minimum secara salah.

Contoh:

- Jika ada node dengan nilai `10`, tapi satu subtree kosong (mengembalikan `0`), maka `min(10, 0)` akan mengembalikan `0`, padahal tidak ada `0` di pohon.

Sehingga harus diganti dengan:

```cpp
if(node == NULL) return INT_MAX;
```

Lalu kesalahn yang kedua adalah saat memanggil `min(node->data, min(a, b))`. Kenapa?

Karena pengecekan `level == 1` hanya berlaku untuk node yang berada **di level target**, sedangkan `node->data` tetap digunakan dalam perhitungan `min()` meskipun **node itu tidak berada di level target**. Itu menyebabkan **node yang bukan dari level ke-`l` juga dihitung**, padahal tidak seharusnya.

Perbaikan yang tepat sudah dilakukan, yaitu merubahnya menjadi seperti ini:

```cpp
return min(a,b);
```

# Editorial
Top banget! 💯 Jawabanmu **benar secara logika, struktur, dan efisiensi**. Kamu telah memanfaatkan `INT_MAX` sebagai nilai default ketika node tidak ada, serta mengembalikan nilai terkecil dengan pendekatan rekursif yang rapi.  
Sekarang aku bantu buatkan **editorial lengkap seperti biasa** — tinggal kamu salin ke Obsidian!

---

## 🧩 Soal 10 – Temukan Nilai Minimum pada Level Tertentu

---

### 📘 Deskripsi

Diberikan sebuah binary tree, cari nilai node yang paling kecil (minimum) pada level ke-`l`. Level dihitung dari root sebagai level ke-1.

---

### 📥 Input

- `root`: pointer ke akar pohon
    
- `level`: level target yang ingin diperiksa
    

---

### 📤 Output

- Nilai terkecil (minimum) dari semua node di level tersebut
    
- Jika level tersebut kosong, kembalikan `INT_MAX`
    

---

## 🌳 Contoh Struktur Pohon:

```

         25
        /  \
      15    50
     / \    / \
    10 22  35 70
    
```

### Contoh Input & Output:

|Input `level`|Output|
|---|---|
|1|25|
|2|15|
|3|10|
|4|2147483647 (INT_MAX)|

---

### ✅ Fungsi:

```cpp
int minLevelTree(struct Node * node, int level){
    if(node == NULL) return INT_MAX;

    if(level == 1){
        return node->data;
    }
    
    int a = minLevelTree(node->left, level - 1);
    int b = minLevelTree(node->right, level - 1);

    return min(a, b);
}
```

---

### 🧠 Penjelasan Per Langkah

|Baris|Penjelasan|
|---|---|
|`if (node == NULL)`|Base case — subtree kosong|
|`if (level == 1)`|Kita sudah di level target — ambil nilai node|
|Rekursi kiri dan kanan|Turunkan level hingga sampai ke 1|
|`return min(a, b)`|Ambil nilai terkecil dari kedua subtree|

---

### ⚙️ Kenapa Pakai `INT_MAX`?

Karena kalau suatu subtree kosong, kita tidak ingin itu mempengaruhi hasil minimum.  
`min(x, INT_MAX)` akan tetap `x`, jadi `INT_MAX` **aman digunakan sebagai nilai default** saat tidak ada node.

---

### 🎯 Evaluasi

|Aspek|Status|
|---|---|
|Rekursi bersih dan aman|✅|
|Tidak pakai variabel global|✅|
|Penanganan level kosong (default: `INT_MAX`)|✅|
|Clean code & modular|✅|

---

## 🏁 Kesimpulan

Fungsi `minLevelTree()` sudah menangani semua kasus dengan benar:

- Struktur pohon lengkap
    
- Level yang ada dan level yang kosong
    
- Menggabungkan logika pencarian minimum dan rekursi dalam satu traversal
    

Ini membuktikan kamu sudah **kuat di dasar traversal dan bisa membentuk fungsi berbasis kondisi spesifik pada pohon**.
