---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Chaining dengan bantuan Checkpoint Tree
sumber: Google.com, AI
date_learned: 2025-06-30T15:19:00
tags:
  - tree-algorithm
---
Link Sumber: 

---
# Chaining dengan bantuan Checkpoint Tree

Ketika aku berlatih banyak soal tentang tree, aku mulai menyadari satu hal. Ketika aku menggunakan metode biasa, yaitu penulisan tree seperti ini:

```cpp
#include<iostream>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
	Node(int data){
		this->data = data;
		left=right=nullptr;
	}
};
```

Maka, ketika aku harus mendeklarasikan dan menginisialisasikan tree yang berbentuk seperti ini:

```

         8
        / \
      3     3
     / \   / \
    4   5 5   4
    
```

aku harus mengetikan ini di fungsi main:

```cpp
int main(){
	struct Node* root = new Node(8);
	root->left = new Node(3);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->right = new Node(4);
	root->right->left = new Node(5);

	return 0;
}
```

Perhatikan banyaknya syntax yang perlu ditulis, sangat banyak! Aku berfikir bahwa pendekatan ini tidak efisien dari segi kecepatan sama sekali, sehingga diperlukan cara lain.

Aku menemukan cara yang lebih baik, dimana cara ini membuat kita tidak perlu untuk menchaining node tree dari root. Chaining dari root akan memakan banyak sekali waktu penulisan, dan akan semakin buruk, seiring bertambahnya level tree. Selain memakan waktu yang lebih banyak, metode chaining dari root rawan akan kesalahan, dan juga menyulitkan proses debugging.

Maka ditemukanlah cara baru, yaitu dengan **menyimpan checkpoint**.

---
## Teknik “Checkpoint Chaining” dalam Pembangunan Tree

Pada saat membangun tree biner yang cukup dalam, penulisan berantai (chaining) langsung dari simpul akar (`root`) dapat menjadi panjang, rawan kesalahan, dan sulit dipelihara. **Checkpoint chaining** adalah sebuah pola di mana kita menyimpan sementara pointer (atau smart pointer) ke simpul tengah, sehingga setiap kali ingin menambah atau memodifikasi subtree, kita tidak perlu lagi menulis rangkaian panggilan yang panjang dari root.

---

### Keunggulan Checkpoint Chaining

1. **Ringkas**  
    Dengan menyimpan simpul perantara, baris kode yang dibutuhkan menjadi lebih sedikit dan langsung ke sasaran.
    <br/>
2. **Aman dari Null‑Dereference**  
    Anda tidak lagi melakukan akses beruntun ke anggota objek yang mungkin masih kosong (`nullptr`), sehingga mengurangi risiko program crash.
    <br/>
3. **Mudah Dibaca dan Dipelihara**  
    Nama variabel checkpoint (misalnya `leftSubtree`, `deepestNode`) dapat menggambarkan bagian tree yang sedang dimodifikasi—sehingga kode menjadi lebih self‑documenting.
    <br/>

---

### Contoh Perbandingan

#### 1. Cara Konvensional (Raw Chaining dari Akar)

```cpp
// Asumsi root sudah ada
root->right                     // dapat anak kanan
    ->left                      // lalu anak kiri
    ->right                     // lalu anak kanan
    ->left                      // lalu anak kiri
    ->setRight(90);             // baru memasang anak kanan bernilai 90
```

- **Kerentanan:** Jika salah satu di antaranya (`right` atau `left`) belum pernah dibuat, maka `nullptr->…` akan menyebabkan crash.
    
- **Keterbacaan:** Sangat panjang dan susah diikuti, terutama jika struktur tree berubah.
    

#### 2. Checkpoint Chaining (Mengambil Simpul Perantara)

```cpp
// root
Node* root = new Node(10);
root->right = new Node(50);

// Pertama, simpan simpul tengah
Node* firstCheckpoint = root->right->setLeft(77);

// Lalu jauhkan simpul berikutnya
Node* secondCheckpoint = firstCheckpoint->setRight(88);

// Terakhir tambahkan anak pada checkpoint terakhir
secondCheckpoint->setLeft(99);
```

**Penjelasan:**

Kita mulai dari tree sederhana di mana root (10) sudah punya anak kanan, katakanlah bernilai 50:

```

   10
     \
      50
```

Kemudian kita melakukan checkpoint chaining:

1. `Node* firstCheckpoint = root->right->setLeft(77);`  
    Ini menambahkan anak kiri `77` ke simpul `50`.
    

```

   10
     \
      50
     /
   77   ← firstCheckpoint
```

2. `Node* secondCheckpoint = firstCheckpoint->setRight(88);`  
    Dari simpul `77`, tambahkan anak kanan `88`.
    

```

   10
     \
      50
     /
   77  
     \
      88   ← secondCheckpoint
```

3. `secondCheckpoint->setLeft(99);`  
    Dari simpul `88`, tambahkan anak kiri `99`.
    

```

       10
         \
          50
         /
       77
         \
          88
         /
       99
```

Jadi struktur pohon akhirnya adalah seperti di atas—tiap baris `setXxx()` menambahkan simpul tepat di tempat checkpoint, tanpa harus terus menulis `root->right->…->…->…`.

Semoga visualisasi ini lebih jelas!

Kode menjadi **singkat**, **jelas**, dan **aman** karena setiap checkpoint sudah pasti valid.

---

### Aplikasi Lanjutan

Dalam kasus di mana Anda membangun tree dari data eksternal (misalnya parser bahasa pemrograman atau generator struktur data), checkpoint chaining dapat dipadukan dengan peta (map) untuk akses cepat:

```cpp
unordered_map<string, Node*> checkpointMap;

// Setelah membuat simpul tertentu:
checkpointMap["leftSubtreeRoot"] = root->left;

// Nanti kapan pun ingin mengakses subtree kiri:
Node* leftRoot = checkpointMap["leftSubtreeRoot"];
leftRoot->setRight(123);
```

Dengan demikian, Anda dapat menempatkan label pada berbagai titik penting dalam tree dan mengaksesnya kapan saja tanpa harus menelusuri dari akar.

---

## Kesimpulan

> “Checkpoint chaining” membuat proses pembangunan dan modifikasi tree menjadi lebih ringkas, lebih aman terhadap kesalahan akses `nullptr`, serta lebih mudah dipahami dan dipelihara.

Anda sudah menguasai teknik ini melalui praktik langsung—ini merupakan fondasi yang kokoh untuk membangun struktur data tree yang kompleks dan dapat diskalakan.