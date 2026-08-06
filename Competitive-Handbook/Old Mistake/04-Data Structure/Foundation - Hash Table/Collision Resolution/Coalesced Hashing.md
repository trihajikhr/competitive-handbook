---
obsidianUIMode: preview
note_type: book theory
judul_materi:
sumber:
date_learned: 2026-07-12T01:39:00
tags:
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Coalesced Hashing

_Coalesced hashing_ adalah metode penanganan _collision_ yang menggabungkan karakteristik _open addressing_ dengan struktur _linked list_ dari _chaining_. Dalam metode ini, semua elemen data disimpan langsung di dalam _array_ utama, namun setiap _slot_ memiliki _pointer_ tambahan untuk membentuk rantai di antara _key_ yang mengalami _collision_.

## Prinsip Kerja Utama

- _Direct Storage_: Seperti _open addressing_, tidak ada _bucket_ terpisah di luar _array_ utama. Seluruh data menempati _slot_ di dalam _array_.
- _Pointer Linkage_: Setiap _slot_ di dalam _array_ memiliki kolom _next_ (penunjuk). Jika terjadi _collision_, _key_ baru ditempatkan di _slot_ kosong berikutnya (biasanya di bagian bawah tabel yang disebut _cellar_ atau _address space_ sisa), lalu _pointer_ pada _key_ sebelumnya diarahkan ke posisi _key_ baru tersebut.
- _Coalescing_: Istilah _coalesced_ muncul karena rantai yang terbentuk dari _collision_ yang berbeda dapat bergabung atau "menyatu" menjadi satu rantai besar, sehingga mengefisiensikan ruang simpan.

## Mekanisme Operasional

- _Insertion_:
    
    1. Hitung _hash index_ dari _key_. Jika _slot_ kosong, masukkan data.
        
    2. Jika _slot_ terisi, telusuri rantai (_follow the chain_) menggunakan _pointer_ hingga mencapai _node_ terakhir.
        
    3. Cari _slot_ kosong di bagian bawah _array_ (menggunakan _pointer_ _freelist_).
        
    4. Tempatkan _key_ baru di _slot_ kosong tersebut dan perbarui _pointer_ dari _node_ terakhir untuk menunjuk ke posisi _key_ baru ini.
        
- _Retrieval_: Sistem melakukan _hashing_ untuk mendapatkan indeks awal, lalu mengikuti rantai _pointer_ sampai _key_ ditemukan atau sampai mencapai _end of chain_ (nilai _null_).
- _Deletion_: Mirip dengan _open addressing_, penghapusan bisa dilakukan dengan _tombstone_. Namun, dalam _coalesced hashing_, proses ini lebih kompleks karena harus menjaga integritas rantai _pointer_ agar tidak memutus akses ke _key_ lain dalam rantai yang sama.

## Analisis Kinerja

- _Space Efficiency_: Lebih hemat memori dibandingkan _chaining_ karena tidak memerlukan struktur data _linked list_ tambahan di setiap _bucket_. Pointer hanya disimpan di dalam _array_ utama.
- _Clustering_: Mengurangi masalah _primary clustering_ yang ditemukan pada _linear probing_ karena _collision_ ditangani dengan struktur rantai yang lebih terorganisir, bukan sekadar mengisi _slot_ kosong yang berdekatan secara fisik.
- _Search Performance_: Performa pencarian berada di antara _chaining_ dan _open addressing_. Karena rantai disimpan di dalam _array_, _cache locality_ cenderung lebih baik dibandingkan _chaining_ (yang sering kali melibatkan alokasi memori tersebar di _heap_).
- _Load Factor_: Dapat menangani _load factor_ yang lebih tinggi dibandingkan _open addressing_ murni, karena rantai _collision_ tidak membatasi kemampuan untuk menemukan _slot_ kosong baru.

## Perbandingan dengan Metode Lain

- _Vs Chaining_: Tidak memerlukan alokasi _node_ dinamis secara terus-menerus, sehingga _overhead_ memori lebih rendah.
- _Vs Open Addressing_: Memiliki alur pencarian yang lebih deterministik karena struktur rantainya jelas, tidak seperti _probing_ yang harus memeriksa satu per satu _slot_ yang mungkin tidak relevan.