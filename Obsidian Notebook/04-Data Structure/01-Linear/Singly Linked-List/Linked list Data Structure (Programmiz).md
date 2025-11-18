---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSLL-0002
nama_algoritma: singly linked list
kategori_algoritma: linked list
kesulitan: 🥉 easy
time_complexity:
memory_complexity:
sumber:
  - programiz.com
date_learned: 2025-10-15T20:48:00
tags:
  - data-structure
  - linked-list
---
Link sumber: [Linked List Data Structure](https://www.programiz.com/dsa/linked-list)

---
# Linked list Data Structure

Sebuah linked list adalah _struktur data_ (_data structure_) linear yang menyertakan serangkaian node yang saling terhubung. Di sini, setiap node menyimpan data dan alamat (_address_) dari node berikutnya. Sebagai contoh,

![[04-Data Structure/Z-src/Linked list Data Structure (Programmiz)-1.png]]


Kita harus memulai dari suatu tempat, sehingga kita memberikan alamat (_address_) dari _node_ pertama sebuah nama khusus yang disebut `HEAD`. Selain itu, _node_ terakhir dalam linked list dapat diidentifikasi karena bagian `next`-nya menunjuk ke `NULL`.

Linked list dapat terdiri dari berbagai jenis: *singly linked list* (list berantai tunggal), *doubly linked list* (list berantai ganda), dan *circular linked list* (list berantai melingkar). Dalam artikel ini, kita akan berfokus pada singly linked list. Untuk mempelajari jenis-jenis lain, kunjungi [Types of Linked List](https://www.programiz.com/dsa/linked-list-types).

> Catatan: Anda mungkin pernah memainkan permainan Perburuan Harta Karun (_Treasure Hunt_), di mana setiap petunjuk mencakup informasi mengenai petunjuk berikutnya. Begitulah cara linked list beroperasi.


<br/>

## 1 | Representasi Linked List


Mari kita lihat bagaimana setiap node dari linked list direpresentasikan. Setiap node terdiri dari:

- Sebuah _item_ data
- Sebuah alamat (_address_) dari node lain

Kita membungkus baik _item_ data maupun referensi node berikutnya dalam sebuah `struct` sebagai berikut:

```cpp
struct node {
  int data;
  struct node *next;
};
```

Memahami struktur (_structure_) sebuah node linked list adalah kunci untuk memahami keseluruhan konsepnya.

Setiap `struct node` memiliki sebuah _item_ data dan sebuah _pointer_ ke `struct node` lain. Mari kita buat sebuah Linked List sederhana dengan tiga _item_ untuk memahami cara kerjanya.

```cpp
/* Inisialisasi node */
struct node *head;
struct node *one = NULL;
struct node *two = NULL;
struct node *three = NULL;

/* Alokasikan memori */
one = malloc(sizeof(struct node));
two = malloc(sizeof(struct node));
three = malloc(sizeof(struct node));

/* Tetapkan nilai data */
one->data = 1;
two->data = 2;
three->data=3;

/* Hubungkan node */
one->next = two;
two->next = three;
three->next = NULL;

/* Simpan alamat dari node pertama pada head */
head = one;
```

Jika Anda tidak memahami salah satu baris di atas, yang Anda butuhkan hanyalah penyegaran ulang mengenai _pointer_ dan _struct_.

Hanya dalam beberapa langkah, kita telah membuat sebuah linked list sederhana dengan tiga node.

![[Linked list Data Structure (Programmiz)-2.png]]

Kekuatan linked list berasal dari kemampuan untuk memutus rantai dan menyambungkannya kembali. Misalnya, jika Anda ingin menyisipkan elemen 4 di antara 1 dan 2, langkah-langkahnya adalah:

1.  Buat `struct node` baru dan alokasikan memori untuknya.
2.  Tambahkan nilai data-nya sebagai 4.
3.  Arahkan *pointer* `next`-nya ke `struct node` yang berisi nilai data 2.
4.  Ubah *pointer* `next` dari "1" ke *node* yang baru saja kita buat.

Melakukan hal serupa pada array akan memerlukan pergeseran posisi semua elemen berikutnya. Sedangkan pada linked list, bisa dilakukan dengan kompleksitas yang konstan.

Dalam Python dan Java, linked list dapat diimplementasikan menggunakan class. Dalam C++, linked list juga bisa diimplementasikan menggunakan class, hanya saja pada contoh kali ini, kita menggunakan struct.

<br/>

## 2 | Utilitas Linked List

List adalah salah satu struktur data (_data structure_) yang paling populer dan efisien, dengan implementasi di setiap bahasa pemrograman seperti C, C++, Python, Java, dan C#.

Selain itu, linked list adalah cara yang bagus untuk mempelajari cara kerja _pointer_. Dengan mempraktikkan cara memanipulasi linked list, Anda dapat mempersiapkan diri untuk mempelajari struktur data (_data structure_) yang lebih lanjut seperti _graf_ (graphs) dan _trees_ (pohon).

<br/>

## 3 | Implementasi Linked List

Berikut adalah implementasi linked list dengan menggunakan bahasa C++:

```cpp
// Implementasi linked list dalam C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Membuat sebuah node
class Node {
   public:
  int value;
  Node* next;
};

int main() {
  Node* head;
  Node* one = NULL;
  Node* two = NULL;
  Node* three = NULL;

  // alokasikan 3 node di heap
  one = new Node();
  two = new Node();
  three = new Node();

  // Tetapkan nilai value
  one->value = 1;
  two->value = 2;
  three->value = 3;

  // Hubungkan node
  one->next = two;
  two->next = three;
  three->next = NULL;

  // cetak nilai (value) linked list
  head = one;
  while (head != NULL) {
    cout << head->value;
    head = head->next;
  }
}
```

<br/>

## 4 | Kompleksitas Linked List

Kompleksitas waktu (*time complexity*):

| Operasi                  | Kasus Terburuk (Worst Case) | Kasus Rata-Rata (Average Case) |
| ------------------------ | --------------------------- | ------------------------------ |
| Pencarian (_Search_)     | $O(n)$                      | $O(n)$                         |
| Penyisipan (_Insert_)    | $O(1)$                      | $O(1)$                         |
| Penghapusan (_Deletion_) | $O(1)$                      | $O(1)$                         |
Kompleksitas ruang (*space complexity*): $O(n)$

<br/>

## 5 | Aplikasi Linked List
- Alokasi memori dinamis (_Dynamic memory allocation_)
- Diimplementasikan dalam _stack_ dan _queue_ (antrean)
- Dalam fungsi Undo pada perangkat lunak (_software_)
- _Hash tables_ dan _Graf_ (Graphs)

