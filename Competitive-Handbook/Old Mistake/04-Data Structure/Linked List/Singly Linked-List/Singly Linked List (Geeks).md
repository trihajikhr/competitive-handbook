---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSLL-0001
nama_algoritma: singly linked list
kategori_algoritma: linked list
kesulitan: 🥉 easy
time_complexity:
memory_complexity:
sumber:
  - geeksforgeeks.org
date_learned: 2025-10-15T20:43:00
tags:
  - data-structure
  - linked-list
---
Link sumber: 
- [Singly Linked List Tutorial - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/singly-linked-list-tutorial/)
- [Linked List Data Structure - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/linked-list-data-structure/)

---

# Singly Linked List

**Singly linked list** adalah sebuah struktur data (_data structure_) fundamental. Struktur ini terdiri dari node, di mana setiap node berisi field data dan sebuah referensi ke node berikutnya di dalam linked list. Referensi `next` pada node terakhir adalah `null`, yang menandakan akhir dari list. Linked list mendukung operasi penyisipan (_insertion_) dan penghapusan (_deletion_) yang efisien.

![[Singly Linked List-1.png]]

## 1 | Pemahaman Struktur Node

Dalam sebuah singly linked list, setiap node terdiri dari dua bagian: *data* dan sebuah _pointer_ ke node berikutnya. Struktur ini memungkinkan node dihubungkan bersama secara dinamis (_dynamically linked_), membentuk sebuah urutan yang menyerupai rantai.

```cpp
// Definisi sebuah Node dalam singly linked list
class Node {
  
public:
    // Bagian data dari node
    int data;

    // Pointer ke node berikutnya dalam list
    Node* next;

    // Konstruktor untuk menginisialisasi node dengan data
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
```


Dalam contoh ini, `class Node` berisi field *data* bertipe integer untuk menyimpan informasi dan sebuah _pointer_ ke Node lain (`next`) untuk membangun link ke node berikutnya dalam list.
## 2 | Membuat Contoh _Linked List_ Berukuran 3 untuk Memahami Cara Kerja

Buat node pertama:
- Alokasikan memori untuk node pertama dan simpan data di dalamnya.
- Tandai node ini sebagai `head`.

Buat node kedua:

- Alokasikan memori untuk node kedua dan simpan data di dalamnya.
- Link-kan `next` dari node pertama ke node baru ini.

Buat node ketiga:

- Alokasikan memori untuk node ketiga dan simpan data di dalamnya.
- Link-kan `next` dari node kedua ke node ini.
- Atur `next`-nya menjadi `NULL` untuk memastikan bahwa `next` dari node terakhir adalah `NULL`.

Berikut adalah contoh implementasi:

```cpp
#include<iostream>
using namespace std;

// Struktur node singly linked list
class Node {
public:
    int data;
    Node* next;

    // Konstruktor untuk menginisialisasi node baru dengan data
    Node(int new_data) {
        this->data = new_data;
        this->next = nullptr;
    }
};

int main() {
    
    // Buat node pertama (head dari list)
    Node* head = new Node(10);

    // Hubungkan node kedua
    head->next = new Node(20);

    // Hubungkan node ketiga
    head->next->next = new Node(30);

    // Hubungkan node keempat
    head->next->next->next = new Node(40);

    // Mencetak linked list
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}
```

Output:

```
10 20 30 40
```

## 3 | Aplikasi Linked List

- Polynomial Arithmetic (Aritmetika Polinomial)
  
	_Linked list_ sangat berguna untuk merepresentasikan polinomial karena **ukuran dan kompleksitasnya yang dinamis**. Setiap _node_ dapat menyimpan satu suku (koefisien dan eksponen) dari polinomial, dan karena polinomial dapat memiliki jumlah suku yang bervariasi—bahkan bisa sangat jarang (_sparse_)—_linked list_ memungkinkan penambahan atau penghapusan suku secara efisien tanpa perlu mengalokasikan ulang seluruh struktur. Hal ini mempermudah operasi seperti penambahan atau perkalian polinomial, karena hanya suku-suku yang ada saja yang disimpan dan diproses.
	
	<br/>
	
- Sparse Matrix (Matriks Jarang)
  
	Dalam komputasi, matriks yang didominasi oleh nilai nol disebut **matriks jarang** (_sparse matrix_). Menggunakan _array_ biasa untuk matriks semacam ini akan membuang memori yang besar. _Linked list_ (terutama _doubly linked list_ atau kombinasi _array_ dan _linked list_) memungkinkan kita untuk menyimpan **hanya elemen-elemen bukan nol** (_non-zero elements_) beserta indeks baris dan kolomnya. Pendekatan ini secara drastis mengurangi kebutuhan memori dan dapat mempercepat operasi tertentu, seperti _traversal_ pada elemen-elemen yang signifikan.
	
	<br/>
	
- Browser History Navigation (Navigasi Riwayat _Browser_)
  
	Saat Anda menavigasi riwayat laman web (tombol **Back** dan **Forward**), _doubly linked list_ adalah _struktur data_ (_data structure_) yang ideal. Setiap halaman web yang dikunjungi menjadi sebuah _node_, dan karena _doubly linked list_ memiliki _pointer_ ke _node_ sebelumnya (`prev`) dan _node_ berikutnya (`next`), perpindahan antara halaman yang baru dikunjungi dan yang lama menjadi sangat cepat, hanya membutuhkan waktu.
	
	<br/>
	
- Undo / Redo (Batalkan / Ulangi)
  
	Fungsi **Undo** (Batalkan) dan **Redo** (Ulangi) dalam perangkat lunak, seperti pengolah kata atau editor grafis, sering diimplementasikan menggunakan dua _stack_ atau sebuah _doubly linked list_. Setiap tindakan pengguna yang dapat dibatalkan disimpan sebagai sebuah _node_. Jika menggunakan _doubly linked list_, perpindahan maju (Redo) dan mundur (Undo) pada urutan operasi sangat mudah dilakukan dengan memindahkan _pointer_ saat ini (`current pointer`) ke _node_ `prev` atau `next`, yang menjamin respons yang cepat.
	
	<br/>
	
- Text Editor (Editor Teks)
  
	Meskipun editor teks modern menggunakan struktur yang lebih kompleks seperti _Ropes_ atau _Gap Buffers_, _linked list_ adalah dasar yang kuat, terutama untuk **penyisipan dan penghapusan karakter/kata yang efisien**. Karena _linked list_ tidak memerlukan pergeseran seluruh blok memori seperti _array_ statis, editor teks yang menggunakan _linked list_ dapat menangani penambahan atau penghapusan teks di tengah dokumen dengan lebih cepat (atau lebih tepatnya, waktu eksekusinya lebih konsisten) dibandingkan _array_ murni.
	
	<br/>
	
- Social Media Feeds (Umpan Media Sosial)
  
	Umpan media sosial, seperti lini masa di X (sebelumnya Twitter) atau Instagram, pada dasarnya adalah **daftar konten yang terus bertambah**. Karena postingan atau konten baru terus ditambahkan ke bagian atas atau bawah daftar secara _real-time_, _linked list_ sangat cocok karena kemudahannya untuk **penyisipan di awal atau akhir** (_insertion at the head or tail_). Ini memastikan bahwa _feed_ Anda dapat di-_update_ dengan cepat tanpa harus mereplikasi ulang seluruh daftar konten yang sudah ada.

## 4 | Keunggulan dan Kelemahan
### 4.1 | Keunggulan (_Advantage_)

- **Ukuran dinamis** (_Dynamic size_): Tidak ada batas ukuran tetap seperti pada *array*.

<br/>

- **Penyisipan dan penghapusan yang efisien**: Operasi penyisipan (_insertion_) dan penghapusan (_deletion_) efisien pada awal dan akhir list. Penyisipan di tengah juga efisien jika kita sudah memiliki referensi atau pointer ke node setelah node mana kita perlu menyisipkan.

<br/>

- **Dapat mengimplementasikan struktur data kompleks**: Dapat digunakan untuk mengimplementasikan struktur data (_data structure_) yang lebih kompleks seperti _stack_, _queue_, dan _graph_.

### 4.2 | Kelemahan (_Disadvantage_)

- **Memori ekstra diperlukan**: Diperlukan memori tambahan untuk menyimpan _pointer_ (`next`) di setiap _node_.

<br/>

- **Tidak ada akses langsung/acak** (_No direct/random access_): Memerlukan traversal (penjelajahan) dari awal (`head`) untuk mencapai _node_ tertentu.

<br/>

- **Tidak ramah cache** (_Cache unfriendly_): _Node_ tidak disimpan dalam memori yang berdekatan (_contiguous memory_), sehingga kurang efisien dalam pemanfaatan _cache_ prosesor.