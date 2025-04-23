---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSPQ-0001
nama_algoritma: priority queue
kategori_algoritma: data structure
kesulitan: 
time_complexity: 
memory_complexity: 
sumber: programiz.com & chatgpt.com
date_learned: 2025-04-23T11:17:00
tags:
  - priority-queue
  - heap
---
#array #data-structure #priority-queue #heap 

---
# Priority Queue  
Priority queue adalah tipe khusus dari queue di mana setiap elemen diasosiasikan dengan nilai prioritas. Elemen-elemen akan diproses berdasarkan prioritasnya. Artinya, elemen dengan prioritas lebih tinggi akan diproses terlebih dahulu.

Namun, jika terdapat elemen-elemen dengan prioritas yang sama, maka mereka akan diproses sesuai urutan dalam queue.

**Pemberian Nilai Prioritas**

Secara umum, nilai dari elemen itu sendiri dianggap sebagai nilai prioritas. Sebagai contoh:

Elemen dengan nilai tertinggi dianggap sebagai elemen dengan prioritas tertinggi. Namun, dalam kasus lain, kita bisa menganggap elemen dengan nilai terendah sebagai elemen dengan prioritas tertinggi.

Kita juga bisa menetapkan prioritas sesuai dengan kebutuhan kita.

![[Priority Queue-1.png]]

## Perbedaan antara Priority Queue dan Queue Biasa  
Dalam queue, aturan yang digunakan adalah _first-in-first-out_, sedangkan dalam priority queue, elemen dihapus berdasarkan prioritasnya. Elemen dengan prioritas tertinggi akan dihapus terlebih dahulu.

## Implementasi Priority Queue  
Priority queue dapat diimplementasikan menggunakan array, linked list, heap, atau binary search tree. Di antara struktur data tersebut, heap memberikan implementasi yang paling efisien untuk priority queue.

Oleh karena itu, dalam tutorial ini kita akan menggunakan struktur data heap untuk mengimplementasikan priority queue. Sebuah _max-heap_ akan digunakan dalam operasi-operasi berikut. Jika ingin mempelajari lebih lanjut, silakan kunjungi _max-heap_ dan _min-heap_.

Berikut adalah analisis komparatif dari berbagai implementasi priority queue:

|Operasi|peek|insert|delete|
|---|---|---|---|
|Linked List|O(1)|O(n)|O(1)|
|Binary Heap|O(1)|O(log n)|O(log n)|
|Binary Search Tree|O(1)|O(log n)|O(log n)|
## Operasi-operasi pada Priority Queue  
Operasi dasar dari priority queue meliputi _inserting_, _removing_, dan _peeking_ elemen.

Sebelum mempelajari priority queue lebih lanjut, disarankan untuk mempelajari terlebih dahulu struktur data _heap_ agar memahami dengan lebih baik bagaimana _binary heap_ digunakan untuk mengimplementasikan priority queue dalam pembahasan ini.

### 1. Menyisipkan Elemen ke dalam Priority Queue  
Penyisipan elemen ke dalam priority queue (max-heap) dilakukan melalui langkah-langkah berikut:

- Sisipkan elemen baru di akhir pohon.

![[Priority Queue-2.png]]

- Lakukan _heapify_ pada pohon.

![[Priority Queue-3.png]]

**Algoritma Penyisipan Elemen ke dalam Priority Queue (Max-Heap)**

```
Jika belum ada node,
  buat newNode.
else (jika sudah ada node)
  sisipkan newNode di akhir (node terakhir dari kiri ke kanan).

heapify array
```

Untuk _Min-Heap_, algoritma di atas dimodifikasi sehingga `parentNode` selalu lebih kecil daripada `newNode`.
### 2. Menghapus Elemen dari Priority Queue  
Penghapusan elemen dari priority queue (max-heap) dilakukan sebagai berikut:

- Pilih elemen yang akan dihapus.
  
  ![[Priority Queue-4.png]]
- Tukar elemen yang akan dihapus dengan elemen terakhir.
  ![[Priority Queue-5.png]]
- Hapus elemen terakhir.

    ![[Priority Queue-6.png]]
- Lakukan _heapify_ pada pohon.
  
  ![[Priority Queue-7.png]]

**Algoritma Penghapusan Elemen dari Priority Queue (Max-Heap)**

```
Jika nodeToBeDeleted adalah leafNode,
  hapus node tersebut.
Else
  tukar nodeToBeDeleted dengan lastLeafNode
  hapus nodeToBeDeleted.

heapify array
```

Untuk _Min-Heap_, algoritma di atas dimodifikasi sehingga kedua childNode selalu lebih kecil daripada currentNode.

---

### 3. Peeking dari Priority Queue (Menemukan max/min)  
Operasi _peek_ mengembalikan elemen maksimum dari Max Heap atau elemen minimum dari Min Heap tanpa menghapus node tersebut.

Untuk baik Max Heap maupun Min Heap:

```cpp
return rootNode
```

---

### 4. Extract-Max/Min dari Priority Queue  
_Extract-Max_ mengembalikan node dengan nilai maksimum setelah menghapusnya dari Max Heap, sementara _Extract-Min_ mengembalikan node dengan nilai minimum setelah menghapusnya dari Min Heap.


## Implementasi Priority Queue dalam Python, Java, C, dan C++

**C++**

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Fungsi untuk menukar posisi dua elemen
void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

// Fungsi untuk heapify pohon
void heapify(vector<int> &hT, int i) {
  int size = hT.size();
  
  // Cari yang terbesar di antara root, left child, dan right child
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < size && hT[l] > hT[largest])
    largest = l;
  if (r < size && hT[r] > hT[largest])
    largest = r;

  // Tukar dan lanjutkan heapifying jika root bukan yang terbesar
  if (largest != i) {
    swap(&hT[i], &hT[largest]);
    heapify(hT, largest);
  }
}

// Fungsi untuk menyisipkan elemen ke dalam pohon
void insert(vector<int> &hT, int newNum) {
  int size = hT.size();
  if (size == 0) {
    hT.push_back(newNum);
  } else {
    hT.push_back(newNum);
    for (int i = size / 2 - 1; i >= 0; i--) {
      heapify(hT, i);
    }
  }
}

// Fungsi untuk menghapus elemen dari pohon
void deleteNode(vector<int> &hT, int num) {
  int size = hT.size();
  int i;
  for (i = 0; i < size; i++) {
    if (num == hT[i])
      break;
  }
  swap(&hT[i], &hT[size - 1]);

  hT.pop_back();
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(hT, i);
  }
}

// Cetak pohon
void printArray(vector<int> &hT) {
  for (int i = 0; i < hT.size(); ++i)
    cout << hT[i] << " ";
  cout << "\n";
}

// Kode utama
int main() {
  vector<int> heapTree;

  insert(heapTree, 3);
  insert(heapTree, 4);
  insert(heapTree, 9);
  insert(heapTree, 5);
  insert(heapTree, 2);

  cout << "Array Max-Heap: ";
  printArray(heapTree);

  deleteNode(heapTree, 4);

  cout << "Setelah menghapus elemen: ";

  printArray(heapTree);
}
```

---

## Aplikasi Priority Queue  
Beberapa aplikasi dari priority queue adalah:

- Algoritma Dijkstra
    
- Implementasi stack
    
- Load balancing dan penanganan interrupt dalam sistem operasi
    
- Kompresi data dalam kode Huffman