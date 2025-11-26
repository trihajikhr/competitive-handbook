---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Tree dengan Malloc
sumber: Google.com, AI
date_learned: 2025-06-30T15:38:00
tags:
  - tree-algorithm
---
Link Sumber: 

---
# Tree dengan Malloc
## Apa itu Malloc
`malloc` adalah singkatan dari **memory allocation**, sebuah fungsi standar di bahasa C (juga tersedia di C++) untuk mengalokasikan blok memori dinamis pada **heap** pada waktu program berjalan. Berikut penjelasan lengkapnya:


### 1. Prototype dan Header

```c
#include <stdlib.h>

void *malloc(size_t size);
```

- **`size`** : Jumlah byte yang ingin dialokasikan.
    
- **Return value**
    
    - Jika berhasil, mengembalikan pointer bertipe `void*` ke blok memori baru.
        
    - Jika gagal (misalnya tidak cukup memori), mengembalikan `NULL`.
        

Karena return-nya `void*`, di C++ biasanya harus di-`static_cast` atau di-`reinterpret_cast`, sedangkan di C tidak perlu cast.


### 2. Cara Kerja Dasar

1. **Alokasi**  
    Saat `malloc(n)` dipanggil, runtime mencari **n** byte kosong di heap.
<br/>
2. **Inisialisasi**  
    Memori yang dikembalikan **tidak diinisialisasi**—isinya bisa sampah (garbage).
<br/>
3. **Pointer Mentah**  
    `malloc` hanya memberikan alamat memori; **tidak memanggil constructor** seperti `new` di C++.
    


### 3. Contoh Penggunaan

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Alokasikan array 10 elemen int
    int *arr = (int*)malloc(10 * sizeof(int));
    if (!arr) {
        fprintf(stderr, "Allocation failed\n");
        return 1;
    }

    // Inisialisasi dan gunakan
    for (int i = 0; i < 10; i++) {
        arr[i] = i * i;
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Setelah selesai: DEALOKASI!
    free(arr);
    arr = NULL;  // hindari dangling pointer

    return 0;
}
```


### 4. Dealokasi dengan `free`

Setiap blok yang dialokasikan `malloc` **harus** dibebaskan dengan:

```c
void free(void *ptr);
```

- Jika lupa memanggil `free`, terjadi **memory leak**, memori tetap “terkunci” sampai program selesai.
    
- Memanggil `free(NULL)` aman—tidak berpengaruh.
    
- Setelah `free(ptr)`, pointer menjadi **dangling**; sebaiknya set `ptr = NULL`.
    


### 5. Variasi & Rekanan

- **`calloc(num, size)`**  
    Alokasi untuk `num` blok berukuran `size` byte, dan **menginisialisasi** semua byte menjadi nol.
<br/>
- **`realloc(ptr, new_size)`**  
    Mengubah ukuran blok yang sudah dialokasikan. Bisa memindahkan blok ke lokasi lain jika perlu.
    


### 6. Kapan dan Mengapa Pakai `malloc`?

- **Sesuai kebutuhan dinamis**  
    Saat ukuran data baru diketahui hanya di runtime (bukan compile-time).
<br/>
- **Lebih ringan** dibanding `new` di C++, tapi tanpa constructor/destructor.
<br/>
- **Kontrol penuh** atas alokasi dan dealokasi—berguna untuk sistem embedded atau performance-tuned code.
    


### 7. Kelemahan & Pitfalls

|Masalah|Penjelasan|
|---|---|
|Memory leak|Lupa `free` → memori menumpuk|
|Dangling pointer|`free` tapi pointer masih dipakai|
|Double free|Memanggil `free` dua kali pada alamat yang sama|
|No constructor/destructor|Tidak memanggil constructor/destructor objek|
|Uninitialized memory|Isi memori setelah `malloc` bersifat garbage|

**Tips**

- Selalu cek hasil `malloc` terhadap `NULL`.
    
- Pasangkan setiap `malloc` dengan satu `free` yang tepat.
    
- Pertimbangkan `calloc` jika butuh zero-initialized memory.
    


### 8. Perbandingan dengan C++

|Fitur|`malloc`/`free`|`new`/`delete`|
|---|---|---|
|Type safety|Return `void*` (need cast)|Return typed pointer|
|Initialization|No constructor called|Memanggil constructor|
|Deallocation|`free(ptr)`|Memanggil destructor + `operator delete(ptr)`|
|Error handling|Return `NULL`|`throw std::bad_alloc`|


### Kesimpulan

- `malloc` memberi **kendali penuh** atas memori—cukup cepat, tapi raw
    
- Wajib di-pair dengan `free` untuk menghindari memory leak
    
- Di C++ modern, sering digantikan oleh `new`/`delete` atau smart pointers (`unique_ptr`, `shared_ptr`)
    

Dengan memahami `malloc`, kamu menguasai **fondasi memori low‑level** yang akan membuat penggunaan `new` dan smart pointer di C++ terasa lebih jelas dan aman.

---
## Apakah bisa menggunakan Malloc pada Tree?

🟢 **Ya, tentu bisa!**  

Membangun **binary tree dengan `malloc()`** sepenuhnya mungkin dan sangat umum dilakukan di bahasa C — dan bahkan di awal-awal belajar C++, orang juga masih pakai gaya ini kadang.

### Kenapa Bisa?

Karena `malloc()` tugasnya adalah: **mengalokasikan memori sebesar yang kamu minta**, lalu memberikan pointer ke memori itu.  

Kalau kamu punya `struct Node`, kamu tinggal alokasikan memori seukuran `Node`, dan kamu dapat pointer ke node baru.

### Contoh: Membangun Tree Sederhana

```c
#include <stdio.h>
#include <stdlib.h>

// Struktur Dasar Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Membuat node baru
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// fungsi traverse
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    /*
            10
           /  \
         5     20
    */

    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(20);

    printf("Root: %d\n", root->data);
    printf("Left child: %d\n", root->left->data);
    printf("Right child: %d\n", root->right->data);

    // Jangan lupa free memory!
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
```

### Hal yang Harus Diwaspadai Saat Pakai `malloc`

|Risiko|Penjelasan|
|---|---|
|💥 Lupa `free()`|Akan terjadi **memory leak**|
|❌ Tidak ada constructor|Data harus diset manual|
|❗ Raw pointer|Salah akses → **segfault**|
|😵‍💫 Tidak ada destructor otomatis|Harus handle semuanya sendiri|

### Bandingkan: `malloc` vs `new`

|Hal|`malloc` (C)|`new` (C++)|
|---|---|---|
|Alokasi memori|✅|✅|
|Panggil constructor|❌|✅|
|Bisa override operator|❌|✅|
|Harus pakai `free`|✅|❌ (pakai `delete`)|
|Aman dari memory leak|❌|✅ dengan `smart pointer`|


### Kesimpulan

✅ **BISA banget membangun tree dengan `malloc`**, dan itu justru cara paling dasar sebelum masuk `new` dan `unique_ptr`.

---
## Contoh lain penggunaan malloc pada tree
Berikut contoh lengkap bagaimana membangun, memanipulasi, dan membebaskan sebuah **binary tree** di C dengan **`malloc`/`free`**—tanpa `new` apalagi `unique_ptr`. Kami akan bahas baris per baris:


```c
#include <stdio.h>
#include <stdlib.h>

// 1) Definisi Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// 2) Fungsi createNode: alokasi + inisialisasi
Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        fprintf(stderr, "ERROR: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    node->data  = value;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

// 3) Helper untuk set child
void setLeft(Node* parent, int value) {
    parent->left = createNode(value);
}
void setRight(Node* parent, int value) {
    parent->right = createNode(value);
}

// 4) Contoh traversal: hitung jumlah node
int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left)
             + countNodes(root->right);
}

// 5) Bebaskan seluruh tree (postorder)
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// 6) Contoh penggunaan di main
int main() {
    // a) Buat root
    Node* root = createNode(10);

    // b) Bangun struktur tree
    setLeft(root, 5);
    setRight(root, 20);
    // Subtree di kiri
    setLeft(root->left, 3);
    setRight(root->left, 8);
    // Subtree di kanan
    setLeft(root->right, 15);
    setRight(root->right, 30);

    // c) Gunakan: misal hitung dan cetak jumlah node
    printf("Total nodes: %d\n", countNodes(root));  // harusnya 7

    // d) Jangan lupa free semua
    freeTree(root);
    return 0;
}
```

### Penjelasan langkah‑langkah:

1. **`typedef struct Node { … } Node;`**  
    Mendefinisikan node yang punya `data` dan dua pointer ke anak kiri/kanan.
    
2. **`createNode(int)`**
    
    - Panggil `malloc(sizeof(Node))` untuk alokasikan memori.
        
    - Cek `NULL` untuk memastikan alokasi berhasil.
        
    - Inisialisasi `data`, set `left`/`right` ke `NULL`.
        
3. **`setLeft` / `setRight`**  
    Fungsi bantu yang memanggil `createNode` dan menghubungkannya ke parent.
    
4. **`countNodes(Node*)`**  
    Traversal rekursif postorder (atau preorder/inorder) untuk menghitung semua node.  
    Base case: `root == NULL` → 0.
    
5. **`freeTree(Node*)`**  
    Sangat penting: traverse ke anak kiri & kanan dulu, lalu `free(root)`.  
    Ini mencegah memory leak.
    
6. **`main()`**
    
    - Membangun tree bertingkat—sesuai kebutuhan Anda.
        
    - Memanggil fungsi manipulasi atau traversal apa pun (`countNodes`, `sumOfLeaves`, dll).
        
    - Terakhir, memanggil `freeTree(root)` sebelum program keluar.
        

---

Dengan pola ini kamu pegang **manual memory management** penuh:

- Semua node dialokasikan secara eksplisit.
    
- Semua node dibebaskan secara eksplisit.
    

Ini adalah dasar “low‑level” yang kemudian di-“upgrade” oleh `new`/`delete` di C++, dan akhirnya oleh smart pointer (`unique_ptr`) agar lebih aman dan bebas dari kebocoran memori.

---
## Kesimpulan

1. **Alokasi Dinamis di Heap**
    
    - `malloc(size)` mengalokasikan blok memori sebesar `size` byte tanpa memanggil konstruktor (C) atau inisialisasi (C++).
        
    - Hasilnya adalah `void*` yang perlu di-_cast_ ke tipe pointer yang diinginkan.
    <br/>
2. **Inisialisasi Manual**
    
    - Setelah `malloc`, kamu **harus** mengatur sendiri nilai‑nilai struct atau variabel di dalam blok memori.
        
    - Tidak ada pemanggilan konstruktor otomatis.
      <br/>
3. **Dealokasi Manual**
    
    - **Wajib** memanggil `free(ptr)` untuk tiap pointer yang di-_malloc_.
        
    - Lupa `free` → **memory leak**; `free` berlebih atau `free(ptr)` yang tidak dialokasikan → undefined behavior.
       <br/>
4. **Type-Punning & Cast**
    
    - Karena `malloc` mengembalikan `void*`, kamu perlu _cast_ ke `T*`:
        
        ```c
        T* p = (T*)malloc(sizeof(T));
        ```
        
    - Kesalahan _cast_ bisa menimbulkan bug memori.
    <br/>
5. **Kelebihan vs `new`**
    
    - **Ringan**: overhead minimal, cocok untuk embedded/C murni.
        
    - **Portabel** di C dan C++.
        
    - **Tidak memanggil konstruktor** (kadang jadi kekurangan di C++).
    <br/>
6. **Kekurangan**
    
    - **Tidak aman**: raw pointer → segfault jika salah akses.
        
    - Tidak ada **RAII**: tidak ada jaminan pembersihan otomatis.
        
    - **Tidak exception‑safe**: jika alokasi gagal, `malloc` mengembalikan `NULL` alih‑alih melempar.
       <br/>
7. **Variasi & Tips**
    
    - Pakai `calloc(n, size)` untuk alokasi + inisialisasi ke nol.
        
    - Cek selalu hasil `malloc` sebelum gunakan:
        
        ```c
        if (!p) { /* handle error */ }
        ```
      <br/>
8. **Langkah Berikutnya**
    
    - Di C++ modern, pertimbangkan **`new`** atau **smart pointer** (`unique_ptr`/`shared_ptr`) untuk keamanan dan kemudahan.
        
    - Untuk kinerja ekstrem, gunakan **custom allocator** atau **memory pool**.
       <br/>


Dengan fondasi di atas, kamu bisa memahami kapan dan bagaimana menggunakan `malloc` secara benar, serta kapan sebaiknya beralih ke metode alokasi yang lebih aman di C++.

### Rekomendasi Penggunaan

1. **Belajar & Sistem Low‑Level (C/Embedded)**  
    → **`malloc`**: paham dasar pointer dan manajemen memori manual.
    
2. **Proyek C++ Tradisional**  
    → **`new/delete`**: gunakan konstruktor/destruktor, tapi perhatikan exception safety.
    
3. **Proyek Modern & Besar**  
    → **`unique_ptr`**: RAII lengkap, otomatis mengurus memory, cocok untuk almost all kasus.
    

---

### Arah “Upgrade” Ke Depan

- **`shared_ptr`** untuk kepemilikan bersama (graf, AST dengan cross‑link)
    
- **Immutable/Functional Trees** dengan `shared_ptr` dan salinan terstruktur
    
- **Custom Allocator/Arena** untuk performa ekstrem (game engine, high‑throughput)
    
- **Serialize/Deserialize**: tambahkan metode baca/tulis ke JSON/Binary
    
- **Visitor Pattern/Polymorphism**: untuk AST di compiler/interpreter
    

Dengan pemahaman perbandingan ini, kamu bisa memilih implementasi **sesuai kebutuhan**—dari yang “paling rendah” sampai “paling modern dan aman.”
# Catatan Penulis
Pada saat pertama kali belajar tentang tree, ada materi yang menggunakan metode `malloc`, dan ada materi yang mengajarkan dengan metode `new`. Tetapi karena dikatakan bahwa `malloc` sejatinya adalah untuk bahasa C, maka penulis memilih menggunakan metode `new` (yang akan dipelajari selanjutnya).

Penulis tidak sempat belajar banyak menggunakan metode `malloc`, karena lebih suka menggunakan 2 metode lain, yaitu `new` dan juga `unique_ptr`, yang lebih mampu dikendalikan dan lebih aman dari memory leaks, terutama `unique_ptr`.

Catatan ini dibuat sebagai pemenuh materi, dimana menggunakan `malloc` untuk membangun tree adalah mungkin dilakukan. Ada banyak materi terkait tree dengan `malloc`, dan ini adalah salah satunya.