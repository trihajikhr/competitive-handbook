---
obsidianUIMode: preview
note_type: book theory
judul_materi:
sumber:
date_learned: 2026-07-12T01:46:00
tags:
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Resizing dan Rehashing

_Resizing_ dan _rehashing_ adalah proses fundamental untuk menjaga efisiensi _hash table_ agar tetap berjalan dalam waktu rata-rata $O(1)$ seiring bertambahnya jumlah elemen. Proses ini merupakan mekanisme pertahanan utama terhadap penurunan performa yang disebabkan oleh peningkatan _load factor_.

## Mengapa _Resizing_ Diperlukan

- _Load Factor Threshold_: Ketika _load factor_ ($\alpha = \frac{n}{m}$, dengan $n$ adalah jumlah elemen dan $m$ adalah jumlah _bucket_) melebihi ambang batas tertentu, frekuensi _collision_ meningkat secara eksponensial.
- _Performance Degradation_: Pada _chaining_, _linked list_ menjadi terlalu panjang. Pada _open addressing_, _probing_ menjadi sangat lama karena sulit menemukan _slot_ kosong.
- _Threshold Umum_: Kebanyakan implementasi (seperti `unordered_map` di C++) menetapkan _max load factor_ sekitar $0.7$ hingga $1.0$. Jika melampaui batas ini, tabel akan memicu proses _resizing_.

## Mekanisme _Rehashing_

_Rehashing_ adalah proses memetakan ulang seluruh elemen yang ada dari _array_ lama ke _array_ baru yang lebih besar.

1. _Allocation_: Sistem mengalokasikan _array_ baru dengan kapasitas lebih besar, biasanya dua kali lipat dari kapasitas sebelumnya ($m_{new} = 2 \times m_{old}$).
2. _Redistribution_: Karena ukuran _array_ berubah, fungsi _hash_ ($h(key) \pmod m$) juga berubah nilainya. Oleh karena itu, setiap _key_ harus dihitung ulang indeksnya berdasarkan $m_{new}$.
3. _Migration_: Setiap elemen dari _array_ lama dipindahkan ke lokasi baru di _array_ baru. Setelah semua elemen berpindah, _array_ lama dihapus (_deallocated_).

## Dampak Performa: _Amortized Analysis_

Meskipun proses _rehashing_ memakan waktu $O(n)$ karena harus memproses semua elemen, operasi ini jarang terjadi.

- _Amortized Complexity_: Jika kita menggandakan ukuran tabel setiap kali penuh, biaya _rehashing_ akan terdistribusi merata di antara semua operasi _insertion_. Secara matematis, biaya rata-rata untuk setiap _insertion_ tetap $O(1)$.
- _Spiky Latency_: Perlu dicatat bahwa meskipun biaya rata-ratanya kecil, operasi _insertion_ tunggal yang memicu _rehashing_ akan memakan waktu lebih lama (_latency spike_). Dalam sistem _real-time_ atau _game engine_, lonjakan ini sering kali dihindari dengan melakukan _incremental rehashing_.

## _Incremental Rehashing_

Untuk menghindari _latency spike_ yang besar pada sistem yang membutuhkan respons cepat:

- _Concept_: Alih-alih memindahkan semua data sekaligus, sistem memindahkan elemen secara bertahap.
- _Implementation_: Setiap kali ada operasi _insert_, _update_, atau _delete_, sistem akan memindahkan sejumlah kecil elemen (misalnya 1 atau 2 _bucket_) dari _array_ lama ke _array_ baru.
- _Dual Table_: Selama proses transisi, sistem akan memeriksa kedua _array_ (lama dan baru) untuk setiap operasi _search_ hingga seluruh data selesai dipindahkan.

## Pertimbangan Implementasi

- _Prime Number Sizing_: Beberapa implementasi menggunakan ukuran tabel berupa bilangan prima (_prime number_). Hal ini bertujuan agar distribusi data lebih merata, terutama jika fungsi _hash_ memiliki pola tertentu yang bisa berinteraksi dengan ukuran tabel yang berupa kelipatan pangkat dua.
- _Memory Overhead_: _Resizing_ membutuhkan memori sementara yang cukup besar karena harus menampung _array_ lama dan _array_ baru secara bersamaan selama proses migrasi.
- _Copy vs Move_: Jika memungkinkan, _key_ dan _value_ dipindahkan (_move_) daripada disalin (_copy_) untuk menghemat biaya operasional, terutama jika _value_ yang disimpan adalah objek yang kompleks.

# FAQ
## Apakah Collision tetap dibutuhkan?

> Ehh bentar bentar, aku mau tanya satu hal, kalau semisal ujung ujungya kita main *resizing* dah *rehashing*, berarti tidak dibutuhkan *collision resolution* dong? Karena kita mengatasinya dengan menggandakan ukuran *bucket array*?

Ini adalah pertanyaan yang sangat menarik dan sering muncul ketika pertama kali mempelajari struktur data ini. Jawaban singkatnya adalah: tidak, _resizing_ dan _rehashing_ tidak menghilangkan kebutuhan akan resolusi _collision_.

Berikut adalah alasan logis mengapa keduanya harus tetap berjalan beriringan:

### 1. _Resizing_ Hanya Menunda, Bukan Menghilangkan _Collision_

Bayangkan sebuah _hash table_ dengan ukuran $M$. Prinsip _Pigeonhole Principle_ menyatakan bahwa jika Anda memiliki $N$ _key_ dan hanya $M$ _bucket_, selama $N > M$, _collision_ secara matematis **pasti** terjadi.

- Meskipun Anda memperbesar _bucket array_ menjadi $2 \times M$, Anda tetap akan memiliki jumlah _key_ yang sama ($N$) yang dipetakan ke dalam ruang yang lebih luas.
- Probabilitas _collision_ memang berkurang karena kepadatan data (_load factor_) menurun, namun kemungkinannya tetap tidak pernah mencapai nol. Dua _key_ yang berbeda bisa saja menghasilkan nilai _hash_ yang sama oleh fungsi _hash_ yang sama, tidak peduli seberapa besar ukuran _array_ Anda.

### 2. Sifat Fungsi _Hash_

_Hash function_ bekerja dengan memetakan ruang input yang sangat luas (misalnya, semua kemungkinan _string_ atau _integer_) ke dalam ruang output yang terbatas (ukuran _array_ Anda).

Karena ruang input jauh lebih besar daripada ruang output, _collision_ adalah fitur bawaan yang tidak terelakkan. _Resizing_ hanya bertujuan menjaga agar _collision_ tetap berada pada frekuensi yang rendah sehingga performa tetap mendekati $O(1)$, bukan untuk meniadakan benturan tersebut.

### 3. Apa yang Terjadi Jika Kita Hanya Mengandalkan _Resizing_?

Jika kita mencoba membuat _hash table_ tanpa resolusi _collision_ sama sekali:

- Saat terjadi _collision_ pada sebuah _bucket_, sistem akan dipaksa melakukan _rehashing_ total setiap kali ada dua _key_ yang bentrok.
- Ini akan menjadi sangat tidak efisien. Bayangkan Anda punya $100$ _key_ dan terjadi _collision_ kecil, lalu Anda harus memindahkan $100$ data tersebut ke _array_ baru yang lebih besar hanya untuk mengakomodasi satu _key_ tersebut.
- Ini akan membuat operasi _insertion_ memiliki _worst-case_ yang sangat buruk dan sangat tidak stabil.

### 4. Analogi Sederhana

Bayangkan _hash table_ adalah sebuah perpustakaan:

- _Bucket array_ adalah rak buku.
- _Hash function_ adalah sistem kategorisasi yang menentukan di rak mana buku harus ditaruh.
- _Collision resolution_ adalah aturan: "Jika buku ini harus di rak A, tapi rak A sudah penuh, taruh di tumpukan di samping rak A."
- _Resizing_ adalah keputusan: "Rak kita sudah terlalu penuh dan tumpukan di samping sudah terlalu tinggi, mari kita bangun rak baru yang lebih besar dan susun ulang semua buku."

Jika Anda tidak punya aturan "tumpukan di samping" (_collision resolution_), maka setiap kali ada dua buku yang harus ditaruh di rak yang sama, Anda terpaksa merenovasi seluruh perpustakaan (_resizing_). Itu akan sangat melelahkan dan tidak praktis.

Dengan demikian, _resizing_ dan _collision resolution_ adalah dua lapisan pertahanan yang berbeda:

1. Resolusi _collision_ menangani benturan lokal yang terjadi saat ini.
2. _Resizing_ menjaga agar frekuensi benturan lokal tersebut tetap jarang dan terkendali.
