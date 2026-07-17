---
obsidianUIMode: preview
note_type: book theory
judul_materi:
sumber:
date_learned: 2026-07-12T01:23:00
tags:
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Chaining

_Chaining_ merupakan metode penanganan _collision_ yang menggunakan struktur data sekunder pada setiap _bucket_ dalam _hash table_ untuk menampung elemen yang memiliki nilai _hash_ identik. Berikut adalah detail teknis mengenai implementasinya:

## Mekanisme Penyimpanan dan Struktur

- _Array_ Utama: Setiap elemen dalam _array_ berfungsi sebagai kepala penunjuk (_head pointer_) ke sebuah struktur data tambahan, umumnya berupa _linked list_.
- Penyimpanan Data: Ketika fungsi _hash_ memetakan _key_ ke sebuah indeks, sistem akan mengakses _bucket_ terkait. Jika _bucket_ tersebut kosong, data akan ditempatkan langsung. Jika _bucket_ sudah terisi, data akan ditambahkan sebagai elemen baru ke dalam _linked list_ tersebut.
- Fleksibilitas Struktur: Meskipun _linked list_ adalah struktur yang paling umum digunakan, dalam kondisi tertentu, struktur data lain seperti _balanced binary search trees_ dapat digunakan untuk meningkatkan performa pada kasus terburuk (_worst-case scenario_).

## Operasi Dasar pada _Chaining_

- _Insertion_: Sistem menghitung _hash index_, kemudian menelusuri atau langsung menyisipkan data ke dalam _list_ di _bucket_ tersebut. Jika _key_ sudah ada, sistem akan melakukan _update_ terhadap _value_.
- _Retrieval_: Sistem menuju indeks hasil perhitungan _hash_, lalu melakukan _traversal_ (penelusuran) pada _list_ di _bucket_ tersebut untuk mencocokkan _key_ yang dicari.
- _Deletion_: Setelah menemukan lokasi _key_ melalui pencarian pada _list_, sistem menghapus _node_ tersebut dan melakukan penyesuaian pada referensi _pointer_ di _node_ sekitarnya.

## Analisis Kinerja

- Keunggulan: Menghindari masalah _clustering_ yang sering terjadi pada metode _open addressing_ dan relatif lebih mudah diimplementasikan karena tidak memerlukan proses pencarian _slot_ kosong yang kompleks.
- _Worst-case Scenario_: Jika distribusi _hash_ tidak seragam, seluruh data dapat menumpuk di satu _bucket_, mengubah kompleksitas waktu pencarian dari rata-rata $O(1)$ menjadi $O(n)$.
- Manajemen Memori: Membutuhkan alokasi memori tambahan untuk menyimpan _pointer_ di setiap _node list_, yang dapat meningkatkan _overhead_ memori dibandingkan dengan metode penanganan _collision_ lainnya.
# FAQ
## Kesamaan linked list

> Bentar, jadi 2 buah key bisa menghasilkan *hash code* yang sama, sehingga nanti valuenya bakal disimpan didalam satu *linked list*?

Tepat sekali. Itu adalah pemahaman yang sangat akurat mengenai konsep _chaining_.

Ketika dua _key_ yang berbeda menghasilkan _hash code_ yang sama (yang kemudian dipetakan ke indeks _array_ yang sama), sistem _hash table_ menggunakan _linked list_ di _bucket_ tersebut sebagai "wadah penampung" untuk semua _key_ yang mengalami _collision_ tersebut.

Berikut adalah gambaran ringkas bagaimana hal itu bekerja di dalam _bucket_ tersebut:

- _Head Pointer_: Setiap _bucket_ pada _array_ utama sebenarnya menyimpan sebuah _pointer_ yang menunjuk ke _head node_ dari sebuah _linked list_.
- _Node Storage_: Setiap _node_ di dalam _linked list_ tersebut menyimpan pasangan _key_ dan _value_ yang asli, bukan hanya nilai _hash_-nya saja.    
- _Collision Handling_: Jadi, jika _key_ A dan _key_ B memiliki _hash code_ yang sama, maka _linked list_ di _bucket_ tersebut akan memiliki setidaknya dua _node_. Satu _node_ untuk menyimpan (A, ValueA) dan satu _node_ untuk (B, ValueB).

Dengan cara ini, meskipun fungsi _hash_ mengalami _collision_, data tidak tertimpa dan tetap bisa dibedakan. Saat Anda melakukan _retrieval_ menggunakan _key_ B, sistem akan menuju ke _bucket_ tersebut, lalu melakukan _traversal_ pada _linked list_-nya, dan melakukan pengecekan per _node_ untuk memastikan _key_ mana yang sebenarnya memiliki _value_ yang Anda cari.