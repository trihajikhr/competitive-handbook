---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSQUE0002
nama_algoritma: queue data structure
kategori_algoritma: data structure
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
sumber: geeksforgeeks.org
date_learned: 2025-03-07T18:03:00
tags:
  - array
  - data-structure
  - queue
---
#array #data-structure #queue 

---

# Operasi Dasar untuk Queue dalam Struktur Data

Beberapa operasi dasar untuk **Queue** dalam **Struktur Data** adalah:

- `enqueue()` – Menambahkan elemen ke dalam queue.
- `dequeue()` – Menghapus elemen dari queue.
- `peek()` atau `front()` – Mengambil elemen yang tersedia di bagian depan queue tanpa menghapusnya.
- `rear()` – Mengembalikan elemen di bagian belakang queue tanpa menghapusnya.
- `isFull()` – Memeriksa apakah queue penuh.
- `isEmpty()` – Memeriksa apakah queue kosong.
- `size()` – Mengembalikan ukuran queue, yaitu jumlah total elemen yang dikandungnya.

![[Basic Operations for Queue in Data Structure-1.png]]

## Operasi 1: `enqueue()`

Menambahkan elemen ke bagian belakang queue.

Langkah-langkah untuk melakukan **enqueue (penyisipan)** dalam queue:

1. Periksa apakah queue penuh.
2. Jika queue penuh, kembalikan **overflow error** dan keluar.
3. Jika queue tidak penuh, tingkatkan pointer **rear** untuk menunjuk ke ruang kosong berikutnya.
4. Tambahkan elemen ke lokasi queue tempat **rear** menunjuk.
5. Kembalikan status sukses.

![[Basic Operations for Queue in Data Structure-2.png]]

**Implementasi `enqueue()`:**

```cpp
void queueEnqueue(int data) {
    // Periksa apakah queue penuh
    if (capacity == rear) {
        printf("\nQueue is full\n");
        return;
    }

    // Tambahkan elemen ke bagian belakang
    else {
        queue[rear] = data;
        rear++;
    }
    return;
}
```

**Analisis Kompleksitas:**

- **Time Complexity:** $O(1)$
- **Space Complexity:** $O(N)$

---
## Operasi 2: `dequeue()`

Menghapus dan mengembalikan elemen di bagian depan queue.

Langkah-langkah untuk melakukan **dequeue (penghapusan)** dalam queue:

1. Periksa apakah queue kosong.
2. Jika queue kosong, kembalikan **underflow error** dan keluar.
3. Jika queue tidak kosong, akses elemen di posisi **front**.
4. Tingkatkan pointer **front** untuk menunjuk ke elemen berikutnya.
5. Kembalikan status sukses.

![[Basic Operations for Queue in Data Structure-3.png]]

**Implementasi `dequeue()`:**

```cpp
void queueDequeue() {
    // Jika queue kosong
    if (front == rear) {
        printf("\nQueue is empty\n");
        return;
    }

    // Geser semua elemen ke kiri
    else {
        for (int i = 0; i < rear - 1; i++) {
            queue[i] = queue[i + 1];
        }

        // Kurangi rear
        rear--;
    }
    return;
}
```

**Analisis Kompleksitas:**

- **Time Complexity:** $O(1)$
- **Space Complexity:** $O(N)$

---
## Operasi 3: `front()`

Mengembalikan elemen di bagian depan tanpa menghapusnya.

Langkah-langkah untuk melakukan **front()**:

1. Jika queue kosong, kembalikan nilai minimum.
2. Jika tidak, kembalikan elemen **front**.

**Implementasi front():**

```cpp
// Fungsi untuk mendapatkan elemen di depan queue
int front(Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    return queue->arr[queue->front];
}
```

**Analisis Kompleksitas:**

- **Time Complexity:** $O(1)$
- **Space Complexity:** $O(N)$

---

## Operasi 4: `rear()`

Mengembalikan elemen di bagian belakang tanpa menghapusnya.

Langkah-langkah untuk melakukan **rear()**:

1. Jika queue kosong, kembalikan nilai minimum.
2. Jika tidak, kembalikan elemen **rear**.

**Implementasi rear():**

```cpp
// Fungsi untuk mendapatkan elemen di belakang queue
int rear(Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    return queue->arr[queue->rear];
}
```

**Analisis Kompleksitas:**

- **Time Complexity:** $O(1)$
- **Space Complexity:** $O(N)$

---

## Operasi 5: `isEmpty()`

Mengembalikan nilai boolean untuk menentukan apakah queue kosong atau tidak.

Langkah-langkah untuk melakukan **isEmpty()**:

1. Jika nilai **front** sama dengan **-1**, kembalikan `true` (queue kosong).
2. Jika tidak, kembalikan `false` (queue tidak kosong).

**Implementasi isEmpty():**

```cpp
// Fungsi untuk memeriksa apakah queue kosong
bool isEmpty() {
    if (front == -1)
        return true;
    else
        return false;
}
```

**Analisis Kompleksitas:**

- **Time Complexity:** $O(1)$
- **Space Complexity:** $O(N)$

---

## Operasi 6: `isFull()`

Mengembalikan nilai boolean untuk menentukan apakah queue penuh atau tidak.

Langkah-langkah untuk melakukan **isFull()**:

1. Jika nilai **front** sama dengan **0** dan **rear** sama dengan kapasitas queue, kembalikan `true`.
2. Jika tidak, kembalikan `false`.

**Implementasi isFull():**

```cpp
// Fungsi untuk memeriksa apakah queue penuh
bool isFull() {
    if (front == 0 && rear == MAX_SIZE - 1) {
        return true;
    }
    return false;
}
```

**Analisis Kompleksitas:**

- **Time Complexity:** $O(1)$
- **Space Complexity:** $O(N)$

---

## Operasi 7: `size()`

Mengembalikan ukuran queue, yaitu jumlah total elemen yang dikandungnya.

**Implementasi size():**

```cpp
// Program C++ untuk mengilustrasikan
// Implementasi fungsi size()
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> myqueue;
    myqueue.push(1);
    myqueue.push(8);
    myqueue.push(3);
    myqueue.push(6);
    myqueue.push(2);

    // Queue menjadi: 1, 8, 3, 6, 2

    cout << myqueue.size();

    return 0;
}
```

**Analisis Kompleksitas:**

- **Time Complexity:** $O(1)$
- **Space Complexity:** $O(N)$
