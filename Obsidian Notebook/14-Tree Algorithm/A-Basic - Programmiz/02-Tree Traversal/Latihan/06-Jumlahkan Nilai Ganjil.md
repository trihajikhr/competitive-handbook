---
obsidianUIMode: preview
note_type: latihan
latihan: Jumlahkan Nilai Ganjil
sumber: chatgpt.com
tags:
  - tree-algorithm
date_learned: 2025-06-26T09:15:00
---
---
Sip! 🔥 Kita lanjut ke **Soal 6**, kali ini traversal-nya tetap fokus, tapi kita tambah **syarat khusus** saat mengunjungi node. Tujuannya: melatih kamu **memfilter data saat traversal** — kemampuan penting dalam soal-soal real-world dan kompetitif.

---

# Soal 6 – Jumlahkan Nilai Ganjil dengan Preorder Traversal

Diberikan pohon biner berikut:

```

        15
       /  \
     10    20
    / \    / \
   8  13  17  25
   
```

### 🎯 Tugasmu:

Gunakan **preorder traversal** untuk menghitung **jumlah semua nilai ganjil** pada pohon tersebut.

> 💡 _Ingat: preorder = root → left → right_  
> Kamu hanya menjumlahkan node yang bernilai **ganjil**.

---

### ✅ Syarat:

- Traversal wajib preorder
    
- Tidak boleh pakai variabel global
    
- Gunakan fungsi rekursif yang **mengembalikan hasil penjumlahan**
    

---

Kirim kodenya kalau sudah, dan seperti biasa aku bantu berikan editorial dan penilaian! 🚀

# Jawabanku
Berikut adalah jawabanku untuk tantangan ini:

```cpp
#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node (int data){
        this->data = data;
        left = right = NULL;
    }
};

int oddSumTree(struct Node *node){
    if(node == NULL) return 0;

    int odd=0;
	if(node->data %2==1) odd+=node->data;
    odd += oddSumTree(node->left); 
    odd += oddSumTree(node->right);
    return odd;
}

int main() {
    struct Node * root = new Node(15);
    root->left = new Node(10);
    root->left->left = new Node(8);
    root->left->right = new Node(13);

    root->right = new Node(20);
    root->right->left = new Node(17);
    root->right->right = new Node(25);

    cout << "Total ganjil tree: ";
    cout << oddSumTree(root);
    return 0;
}
```

# Editorial
Kamu luar biasa konsisten dan teliti! 💥 Kode kamu sudah **100% benar** dan rapi, serta memenuhi semua syarat yang diajukan:  
✔️ Traversal preorder  
✔️ Tanpa variabel global  
✔️ Rekursif dan mengembalikan hasil

Sekarang aku bantu buatkan **editorial + pembahasan sederhana** agar kamu bisa langsung salin ke Obsidian!

---

## 🌳 Soal 6 – Jumlahkan Nilai Ganjil dengan Preorder Traversal

**Struktur pohon:**

```

        15
       /  \
     10    20
    / \    / \
   8  13  17  25
   
```

---

## ✅ Tujuan

Gunakan **preorder traversal** (root → left → right) untuk menghitung jumlah semua node yang memiliki nilai **ganjil**.

---

## 🧠 Konsep yang Diuji

- Traversal preorder
    
- Menambahkan kondisi saat kunjungan node (ganjil saja)
    
- Rekursi dengan pengembalian nilai
    
- Tanpa penggunaan variabel global (clean code)
    

---

## 🧪 Evaluasi Kode

### Fungsi:

```cpp
int oddSumTree(struct Node *node){
    if(node == NULL) return 0;

    int odd = 0;
    if(node->data % 2 == 1) odd += node->data;
    odd += oddSumTree(node->left); 
    odd += oddSumTree(node->right);
    return odd;
}
```

### ✅ Analisis:

- Mengecek apakah `node->data` ganjil (`% 2 == 1`)
    
- Jika iya, tambahkan ke variabel `odd`
    
- Lanjutkan preorder traversal ke kiri dan kanan
    
- Semua penjumlahan disatukan dan dikembalikan sebagai total
    

---

## 🔍 Langkah Traversal & Penjumlahan

Urutan preorder:

```
15 → 10 → 8 → 13 → 20 → 17 → 25
```

Yang ganjil:

```
15, 13, 17, 25
```

### 🔢 Total:

```
15 + 13 + 17 + 25 = 70
```

---

## 💬 Kesimpulan

Kamu berhasil menambahkan **syarat dinamis** ke dalam traversal preorder, dan tetap menjaga struktur kode tetap bersih dan efisien. Ini akan sangat berguna untuk berbagai jenis soal seperti:

- Validasi data
    
- Pemrosesan kondisi khusus
    
- Path analysis di pohon

# Tambahan Analisis
Tentu banget! Mari kita **bedah fungsi `oddSumTree()`** secara **mendetail** agar kamu bener-bener ngerti _apa yang terjadi di balik layar saat traversal berlangsung_, dan kenapa semua bagian kode itu penting.

---

## 🔍 FUNGSI:

```cpp
int oddSumTree(struct Node *node){
    if(node == NULL) return 0;

    int odd = 0;
    if(node->data %2 == 1) odd += node->data;

    odd += oddSumTree(node->left); 
    odd += oddSumTree(node->right);
    return odd;
}
```

---

## 🧠 Tujuan Fungsi:

Mengembalikan total penjumlahan dari semua node dalam pohon yang **nilainya ganjil**, menggunakan **preorder traversal**.

---

## 📘 PENJELASAN PER BAGIAN:

### 🔹 `if (node == NULL) return 0;`

Ini adalah **base case** untuk rekursi:

- Kalau node-nya kosong, kita kembalikan 0 karena tidak ada yang bisa dijumlahkan.
    
- Ini mencegah program memanggil fungsi ke arah yang tidak valid (null pointer).
    

> 🔧 Tanpa ini, fungsi bisa berakhir dalam error atau infinite recursion.

---

### 🔹 `int odd = 0;`

Kita inisialisasi variabel lokal `odd` yang akan menyimpan **penjumlahan sementara** untuk subtree saat ini.

---

### 🔹 `if (node->data % 2 == 1) odd += node->data;`

Bagian ini adalah **filter**:

- `node->data % 2 == 1` → artinya nilainya ganjil.
    
- Kalau benar, tambahkan ke `odd`.
    

> ✅ Ini yang membuat kita **tidak menghitung nilai genap**.

---

### 🔹 `odd += oddSumTree(node->left);`

Memanggil fungsi yang sama untuk anak kiri:

- Fungsi akan **menghitung jumlah ganjil dari seluruh subtree kiri**
    
- Nilainya langsung ditambahkan ke `odd` di node saat ini
    

---

### 🔹 `odd += oddSumTree(node->right);`

Sama seperti yang kiri, tapi untuk subtree kanan.

---

### 🔹 `return odd;`

Akhirnya, fungsi akan **mengembalikan total jumlah ganjil dari seluruh subtree yang berakar di node ini**.

> Dan karena ini rekursif, return-nya akan dikembalikan ke parent, terus naik ke atas sampai root, hingga akhirnya di-`main()` kamu bisa lihat total keseluruhan.

---

## 🔁 Ilustrasi Proses Traversal

Contoh di node `10`:

```
Node 10:
- Ganjil? ❌ (10 % 2 == 0)
- Total = 0
- Kiri → node 8 → ganjil? ❌
- Kanan → node 13 → ganjil? ✅ (13)

Total dari subtree `10` = 13
```

---

## 🔄 Urutan Traversal (Preorder)

`15 → 10 → 8 → 13 → 20 → 17 → 25`

Nilai ganjil: `15, 13, 17, 25` → Total: `70`

---

## ✨ Ringkasan Alur:

|Tahap|Proses|
|---|---|
|1. Cek null|Jika `NULL`, return 0|
|2. Cek ganjil|Tambahkan jika ganjil|
|3. Rekursi kiri|Tambahkan hasil dari anak kiri|
|4. Rekursi kanan|Tambahkan hasil dari anak kanan|
|5. Return total|Kembalikan hasil ke parent|

---

## 🧼 Kenapa Ini Desain yang Baik?

- **Pure function**: tidak pakai variabel global
    
- **Modular**: mudah dipakai kembali untuk operasi lain
    
- **Aman**: semua kondisi dicek (null, ganjil)
    
- **Rekursif natural**: menyatu dengan struktur pohon
    
