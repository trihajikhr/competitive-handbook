---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 04TH-DSQUE0003
nama_algoritma: queue data structure
kategori_algoritma: data structure
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
sumber: geeksforgeeks.org
date_learned: 2025-03-07T18:17:00
tags:
  - array
  - data-structure
  - queue
---
#array #data-structure #queue 

---
# Pengenalan dan Implementasi Array untuk Queue

Seperti **stack**, **queue** adalah struktur data linier yang mengikuti aturan tertentu dalam melakukan operasi penyimpanan data. Aturan yang digunakan adalah **First In First Out (FIFO)**. Kita bisa membayangkan **queue** seperti antrean orang yang menunggu untuk menerima sesuatu dalam urutan yang berurutan dari awal antrean.

Queue adalah daftar berurutan di mana penyisipan dilakukan di salah satu ujung yang disebut **rear** dan penghapusan dilakukan dari ujung lainnya yang disebut **front**.

Contoh yang baik dari **queue** adalah antrean pelanggan untuk mendapatkan suatu sumber daya, di mana pelanggan yang datang lebih dulu akan dilayani lebih dulu.

**Perbedaan antara stack dan queue terletak pada cara menghapus elemen.**

- **Pada stack**, elemen yang paling **terakhir** ditambahkan adalah yang **pertama** dihapus (**LIFO**).
- **Pada queue**, elemen yang paling **awal** ditambahkan adalah yang **pertama** dihapus (**FIFO**).

![[03-Implementasi Array untuk Queue-1.png]]

---

# 1. Implementasi Queue dengan Array Sederhana

Untuk mengimplementasikan **queue** menggunakan **array**, kita hanya perlu menyimpan dua variabel utama:

- `front` (menunjukkan elemen pertama dalam antrean).
- `size` (jumlah elemen dalam queue).

Kita bisa mendapatkan **rear** dengan rumus berikut: $rear=front+size−1$

**Operasi dasar dalam implementasi array sederhana:**

- **Enqueue** (menambahkan elemen) dilakukan dengan menyisipkan elemen di akhir array. Operasi ini memakan **O(1)** waktu.
- **Dequeue** (menghapus elemen) dilakukan dengan menghapus elemen dari awal array, tetapi ini memerlukan pergeseran seluruh elemen ke kiri. Oleh karena itu, operasi ini memakan **O(n)** waktu.
- Jika kita melakukan sebaliknya, yaitu menyisipkan di awal dan menghapus di akhir, maka **penyisipan akan menjadi lebih mahal**.

**Tabel Kompleksitas Operasi dalam Implementasi Array Sederhana**

| Operasi                                 | Kompleksitas Waktu |
| --------------------------------------- | ------------------ |
| Enqueue (penyisipan)                    | $O(1)$             |
| Dequeue (penghapusan)                   | $O(n)$             |
| Front (mengambil elemen depan)          | $O(1)$             |
| Rear (mengambil elemen belakang)        | $O(1)$             |
| IsFull (memeriksa apakah queue penuh)   | $O(1)$             |
| IsEmpty (memeriksa apakah queue kosong) | $O(1)$             |

## Implementasi Queue Menggunakan Array – Sederhana

Harap dicatat bahwa **implementasi array sederhana** yang dibahas di sini **tidak digunakan dalam praktik** karena **tidak efisien**. Dalam praktiknya, kita biasanya menggunakan **implementasi queue dengan Linked List** atau **implementasi queue dengan circular array**.

Tujuan dari pembahasan ini adalah untuk memberi pemahaman mengapa kita membutuhkan **implementasi circular array untuk queue**.

---

## Penjelasan Implementasi

- Queue menggunakan **array dengan kapasitas tetap** yang disebut `capacity` dan melacak jumlah elemen saat ini menggunakan variabel `size`.
- Variabel `front` diinisialisasi dengan nilai `0` dan menunjukkan **indeks elemen pertama dalam queue**.
- Saat operasi **dequeue**, elemen pada indeks ini akan dihapus.

Untuk mengimplementasikan **queue berukuran `n` menggunakan array**, operasi dasarnya adalah sebagai berikut:

1. **Enqueue**
    
    - Menambahkan elemen baru ke akhir queue.
    - Memeriksa apakah masih ada ruang dalam queue sebelum menambahkan elemen.
    - Menambah ukuran queue setelah elemen dimasukkan.
2. **Dequeue**
    
    - Menghapus elemen **pertama** dengan menggeser semua elemen lainnya **ke kiri**.
    - Mengurangi ukuran queue setelah elemen dihapus.
3. **getFront**
    
    - Mengembalikan elemen **pertama** dalam queue jika tidak kosong.
    - Mengembalikan `-1` jika queue kosong.
4. **Display**
    
    - Menampilkan elemen dalam queue dari **front** hingga **size**.

---

## Ilustrasi Queue dalam Array

![[03-Implementasi Array untuk Queue-2.png]]

![[03-Implementasi Array untuk Queue-3.png]]

![[03-Implementasi Array untuk Queue-4.png]]

![[03-Implementasi Array untuk Queue-5.png]]

![[03-Implementasi Array untuk Queue-6.png]]

![[03-Implementasi Array untuk Queue-7.png]]

## Implementasi dalam C++

Berikut adalah implementasi sederhana queue menggunakan array dalam bahasa **C++**:

```cpp
// C++ program to implement queue using array.
#include <bits/stdc++.h>
using namespace std;

class Queue {
public:
    vector<int> arr;
    int size;
    int capacity;
    int front;

    Queue(int qSize) {
        size = 0;
        front = 0;
        capacity = qSize;
        arr.resize(qSize);
    }

    // Function to add an element to queue.
    void enqueue(int x) {
        // If queue is full
        if (size == capacity) {
            return;
        }

        arr[size] = x;
        size++; // Increment queue size.
    }

    // Function to remove front element from queue.
    void dequeue() {
        // If queue is empty
        if (size == 0) {
            return;
        }

        // Shift all elements to the left.
        for (int i = 1; i < size; i++) {
            arr[i - 1] = arr[i];
        }

        size--; // Decrement queue size.
    }

    // Function which returns the front element.
    int getFront() {
        if (size == 0)
            return -1;
        return arr[front];
    }

    // Function to display elements of the queue.
    void display() {
        for (int i = front; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue *q = new Queue(4);

    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    cout << q->getFront() << endl; // Output: 1
    q->dequeue();
    q->enqueue(4);
    q->display(); // Output: 2 3 4

    return 0;
}
```

 Output:

```
1
2 3 4
```

## Analisis Kompleksitas Waktu

|Operasi|Kompleksitas Waktu|
|---|---|
|**Enqueue** (penyisipan)|**O(1)**|
|**Dequeue** (penghapusan)|**O(n)**|
|**getFront** (mengambil elemen depan)|**O(1)**|
|**Display** (menampilkan queue)|**O(n)**|

- **Enqueue** hanya menambahkan elemen di akhir array, sehingga membutuhkan **O(1)** waktu.
- **Dequeue** membutuhkan **O(n)** waktu karena setiap elemen harus digeser ke kiri setelah elemen pertama dihapus.
- **getFront** hanya mengembalikan elemen pertama, sehingga memiliki kompleksitas **O(1)**.
- **Display** mencetak semua elemen dalam queue, sehingga membutuhkan **O(n)** waktu.

**Kompleksitas Ruang (Auxiliary Space):** **O(n)**, karena kita menggunakan array berukuran `n` untuk menyimpan queue.

---

## Kekurangan Implementasi Ini

Kita dapat melihat bahwa operasi **Dequeue** memiliki **O(n)** waktu, yang **tidak efisien**.  
Idealnya, baik operasi **Enqueue** maupun **Dequeue** harus memiliki kompleksitas **O(1)**.

Karena itu, jika kita ingin menggunakan **array untuk queue**, **implementasi yang lebih efisien** adalah menggunakan **circular array**, karena memiliki keuntungan berikut:

- **Cache friendliness**
- **Akses acak (random access)**
- **Semua operasi dapat dilakukan dalam O(1) waktu**

Untuk solusi yang lebih baik, silakan lihat **Implementasi Circular Array untuk Queue**.

---

# 2. Implementasi Queue dengan Circular Array

Kita bisa meningkatkan efisiensi operasi **queue** menggunakan **circular array**, sehingga semua operasi dapat berjalan dalam **O(1) waktu**.

**Ide utama dari circular array:**

- **Queue dianggap sebagai buffer melingkar**.
- **Front dan rear dikelola menggunakan operasi modulus** untuk mencegah pemborosan ruang kosong.
- Ketika kita menyisipkan elemen baru, **rear** diinkrementasikan menggunakan modulus.
- Ketika kita menghapus elemen, **front** diinkrementasikan menggunakan modulus.

**Tabel Kompleksitas Operasi dalam Implementasi Circular Array**

| Operasi                                 | Kompleksitas Waktu |
| --------------------------------------- | ------------------ |
| Enqueue (penyisipan)                    | $O(1)$             |
| Dequeue (penghapusan)                   | $O(1)$             |
| Front (mengambil elemen depan)          | $O(1)$             |
| Rear (mengambil elemen belakang)        | $O(1)$             |
| IsFull (memeriksa apakah queue penuh)   | $O(1)$             |
| IsEmpty (memeriksa apakah queue kosong) | $O(1)$             |

Untuk detail implementasi, silakan lihat **Circular Array Implementation of Queue**.

## Pendahuluan ke Circular Queue

**Circular Queue** adalah cara lain untuk mengimplementasikan simple queue di mana elemen terakhir dalam antrian terhubung ke elemen pertama, membentuk lingkaran.

Operasi dalam antrian ini mengikuti prinsip **FIFO (First In First Out)** dan juga dikenal sebagai **Ring Buffer**. Dalam antrian biasa, kita dapat menambahkan elemen sampai antrian penuh. Namun, ketika antrian penuh, kita tidak dapat memasukkan elemen baru meskipun ada ruang kosong di bagian depan antrian.

---
## Operasi pada Circular Queue

- **getFront**: Mengembalikan elemen pertama dalam antrian.
- **getRear**: Mengembalikan elemen terakhir dalam antrian.
- **enqueue(value)**: Menambahkan elemen ke antrian circular. Dalam antrian circular, elemen baru selalu dimasukkan di posisi belakang (**rear**).
- **dequeue()**: Menghapus elemen dari antrian circular. Dalam antrian circular, elemen selalu dihapus dari posisi depan (**front**).

## Implementasi Circular Queue menggunakan Array

1. **Inisialisasi**
    
    - Buat array dengan ukuran **n**, di mana **n** adalah jumlah maksimum elemen yang dapat ditampung oleh antrian.
    - Inisialisasi tiga variabel: **size**, **capacity**, dan **front**.
2. **Enqueue (Menambahkan Elemen ke Antrian)**
    
    - Periksa apakah **size == capacity** (antrian penuh), jika ya, tampilkan pesan **"Queue is full"**.
    - Jika tidak penuh:
        - Hitung posisi **rear** dengan rumus `(front + size) % capacity`.
        - Masukkan elemen pada indeks **rear**.
        - Tambahkan ukuran **size** sebanyak 1.
3. **Dequeue (Menghapus Elemen dari Antrian)**
    
    - Periksa apakah **size == 0** (antrian kosong), jika ya, tampilkan pesan **"Queue is empty"**.
    - Jika tidak kosong:
        - Ambil elemen pada indeks **front**.
        - Perbarui **front** dengan rumus `(front + 1) % capacity`.
        - Kurangi **size** sebanyak 1.
        - Kembalikan elemen yang dihapus.

---

## Ilustrasi Circular Queue

![[03-Implementasi Array untuk Queue-8.png]]

![[03-Implementasi Array untuk Queue-9.png]]

![[03-Implementasi Array untuk Queue-10.png]]

![[03-Implementasi Array untuk Queue-11.png]]

![[03-Implementasi Array untuk Queue-12.png]]

![[03-Implementasi Array untuk Queue-13.png]]

---

## Implementasi dalam C++

```cpp
// Program C++ untuk operasi enqueue dan dequeue pada Circular Queue
#include <iostream>
using namespace std;

class MyQueue {
private:
    int *arr;        
    int front, size; 
    int capacity;    

public:
    // Konstruktor untuk inisialisasi antrian
    MyQueue(int c) {
        arr = new int[c];
        capacity = c;
        size = 0;
        front = 0;
    }

    // Mendapatkan elemen pertama (front)
    int getFront() {
        if (size == 0) 
            return -1; 
        return arr[front];
    }

    // Mendapatkan elemen terakhir (rear)
    int getRear() {
        if (size == 0) 
            return -1; 
        int rear = (front + size - 1) % capacity;
        return arr[rear];
    }

    // Menambahkan elemen ke belakang antrian
    void enqueue(int x) {
        if (size == capacity) 
            return; 
        int rear = (front + size) % capacity;
        arr[rear] = x;
        size++;
    }

    // Menghapus elemen dari depan antrian
    int dequeue() {
        if (size == 0) 
            return -1;
        int res = arr[front];
        front = (front + 1) % capacity;
        size--;
        return res;
    }
};

int main() {
    MyQueue q(4);
    q.enqueue(10);
    cout << q.getFront() << " " << q.getRear() << endl;
    q.enqueue(20);
    cout << q.getFront() << " " << q.getRear() << endl;
    q.enqueue(30);
    cout << q.getFront() << " " << q.getRear() << endl;
    q.enqueue(40);
    cout << q.getFront() << " " << q.getRear() << endl;
    q.dequeue();
    cout << q.getFront() << " " << q.getRear() << endl;
    q.dequeue();
    cout << q.getFront() << " " << q.getRear() << endl;
    q.enqueue(50);
    cout << q.getFront() << " " << q.getRear() << endl;
    return 0;
}
```

 Output:

```
10 10
10 20
10 30
10 40
20 40
30 40
30 50
```

## Analisis Kompleksitas Operasi Circular Queue

|**Operasi**|**Kompleksitas Waktu**|
|---|---|
|**enqueue(x)**|O(1)|
|**dequeue()**|O(1)|
|**getFront()**|O(1)|
|**getRear()**|O(1)|

**Auxiliary Space**: O(size), di mana **size** adalah jumlah elemen dalam antrian circular.