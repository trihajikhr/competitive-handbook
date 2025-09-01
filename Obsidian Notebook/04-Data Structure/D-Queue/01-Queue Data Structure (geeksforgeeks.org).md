---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSQU-E001
nama_algoritma:
kategori_algoritma: data structure
kesulitan: 🥉 easy
time_complexity:
memory_complexity:
sumber: geeksforgeeks.org
date_learned: 2025-03-07T17:46:00
tags:
  - data-structure
  - queue
---
---
# 1 | Queue Data Structure

Queue adalah struktur data linear yang mengikuti prinsip *FIFO* (*First In First Out*), yang berarti elemen pertama yang dimasukkan akan menjadi elemen pertama yang dikeluarkan.

## 1.1 | Prinsip FIFO dalam Queue

Prinsip FIFO (*First In First Out*) menyatakan bahwa elemen pertama yang ditambahkan ke dalam Queue akan menjadi elemen pertama yang dihapus atau diproses. Queue dapat diibaratkan sebagai antrean orang yang menunggu membeli tiket, di mana orang yang pertama datang adalah yang pertama dilayani (_First Come First Serve_).

![[Queue Data Structure (geeksforgeeks.org)-1.png]]

## 1.2 | Terminologi Dasar dalam Queue

1. **Front** → Posisi elemen pertama dalam queue yang siap untuk dilayani atau dihapus. Ini disebut juga sebagai head dari queue.
2. **Rear** → Posisi elemen terakhir dalam queue, yaitu elemen yang baru saja ditambahkan. Ini disebut juga sebagai tail dari queue.
3. **Size** → Jumlah elemen yang saat ini berada dalam queue.
4. **Capacity** → Jumlah maksimal elemen yang dapat ditampung oleh queue.
## 1.3 | Representasi Queue

![[Queue Data Structure (geeksforgeeks.org)-2.png]]

Queue dapat direpresentasikan menggunakan array atau **linked list**.

<br/>

---
# 2 | Operasi dalam Queue

## 2.1 | Enqueue (Menambahkan Elemen ke Queue)

Operasi enqueue digunakan untuk menambahkan elemen ke bagian belakang queue.

Langkah-langkah:

- Periksa apakah queue penuh. Jika penuh, kembalikan error overflow.
- Jika tidak penuh, tingkatkan nilai rear untuk menunjuk ke posisi berikutnya.
- Masukkan elemen ke dalam posisi rear.
  
  ![[Queue Data Structure (geeksforgeeks.org)-3.png]]
  ![[Queue Data Structure (geeksforgeeks.org)-4.png]]
  ![[Queue Data Structure (geeksforgeeks.org)-5.png]]
  ![[Queue Data Structure (geeksforgeeks.org)-6.png]]
  ![[Queue Data Structure (geeksforgeeks.org)-7.png]]
  ![[Queue Data Structure (geeksforgeeks.org)-8.png]]

## 2.2 | Dequeue (Menghapus Elemen dari Queue)

Operasi dequeue digunakan untuk menghapus elemen dari bagian depan queue.

Langkah-langkah:

- Periksa apakah queue kosong. Jika kosong, kembalikan error underflow.
- Hapus elemen yang berada di front.
- Tingkatkan nilai front ke posisi berikutnya.
  
  ![[Queue Data Structure (geeksforgeeks.org)-9.png]]
  ![[Queue Data Structure (geeksforgeeks.org)-10.png]]
  ![[Queue Data Structure (geeksforgeeks.org)-11.png]]
  ![[Queue Data Structure (geeksforgeeks.org)-12.png]]
  ![[Queue Data Structure (geeksforgeeks.org)-13.png]]
  ![[Queue Data Structure (geeksforgeeks.org)-14.png]]
## 2.3 | Operasi Lain 
### 2.3.1 | Peek atau Front Operation

Operasi ini mengembalikan elemen di posisi front, tetapi tidak menghapusnya dari queue.

### 2.3.2 | Size Operation

Mengembalikan jumlah elemen yang ada dalam queue.

### 2.3.3 isEmpty Operation

Mengembalikan true jika queue kosong, false jika tidak.

### 2.3.4 | isFull Operation

Mengembalikan true jika queue penuh, false jika tidak.

<br/>

---
# 3 | Analisis Kompleksitas Operasi Queue

| Operasi | Kompleksitas Waktu | Kompleksitas Ruang |
| ------- | ------------------ | ------------------ |
| enqueue | $O(1)$             | $O(1)$             |
| dequeue | $O(1)$             | $O(1)$             |
| front   | $O(1)$             | $O(1)$             |
| size    | $O(1)$             | $O(1)$             |
| isEmpty | $O(1)$             | $O(1)$             |
| isFull  | $O(1)$             | $O(1)$             |
<br/>

---

# 4 | Jenis-Jenis Queue

## 4.1 | Simple Queue
- Queue standar yang mengikuti prinsip FIFO.
- Elemen hanya dapat ditambahkan di belakang (_rear_) dan dihapus dari depan (_front_).

## 4.2 | Double-Ended Queue (Deque)
- Queue di mana penambahan dan penghapusan elemen bisa dilakukan dari kedua ujung.
- Tipe deque:
	- Input Restricted Queue → Elemen hanya bisa ditambahkan dari satu ujung, tetapi bisa dihapus dari kedua ujung.
	- Output Restricted Queue → Elemen bisa ditambahkan dari kedua ujung, tetapi hanya bisa dihapus dari satu ujung.
## 4.3 | Circular Queue

- Queue di mana posisi terakhir terhubung kembali ke posisi pertama.
- FIFO tetap berlaku, tetapi posisi rear dapat melingkar kembali ke awal jika ada ruang kosong.
## 4.4 | Priority Queue

- Queue khusus di mana elemen diproses berdasarkan prioritasnya.
- Tipe priority queue:
	- Ascending Priority Queue → Elemen dengan prioritas terkecil diproses lebih dahulu.
	- Descending Priority Queue → Elemen dengan prioritas terbesar diproses lebih dahulu.

![[Queue Data Structure (geeksforgeeks.org)-15.png]]

<br/>

---
# 5 | Aplikasi Struktur Data Queue

Queue memiliki banyak aplikasi di dunia nyata, terutama dalam sistem komputer, misalnya:

1. Manajemen Tugas di Sistem Komputer
    - _CPU Scheduling_ → Menjalankan proses secara bergantian menggunakan queue.
    - _Disk Scheduling_ → Mengatur antrean permintaan akses ke disk.

<br/>

2. Sebagai Buffer Data
    - Digunakan sebagai buffer antara _keyboard_ dan _CPU_ karena perbedaan kecepatan pemrosesan.

<br/>

3. Komunikasi Jaringan
    - Queue digunakan dalam router, switch, dan mail queue untuk menangani paket data.

<br/>

4. Algoritma Graf
    - Breadth First Search (BFS) → Menggunakan queue untuk eksplorasi graf.
    - Topological Sorting → Menggunakan queue untuk menyusun urutan dependensi dalam graf.

Untuk detail lebih lanjut, silakan merujuk ke Aplikasi Queue.


