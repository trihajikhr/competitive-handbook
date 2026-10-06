---
obsidianUIMode: preview
note_type: book theory
judul_materi:
sumber:
date_learned: 2026-07-12T01:38:00
tags:
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Cuckoo Hashing

_Cuckoo hashing_ adalah teknik resolusi _collision_ berbasis _open addressing_ yang menjamin waktu pencarian (_retrieval_) dalam kondisi terburuk (_worst-case_) sebesar $O(1)$. Nama teknik ini terinspirasi dari perilaku burung _cuckoo_ yang membuang telur burung lain dari sarang untuk menempatkan telurnya sendiri.

## Prinsip Kerja Utama

- Dua Fungsi _Hash_: Teknik ini menggunakan dua fungsi _hash_ berbeda ($h_1$ dan $h_2$) serta dua tabel _hash_ terpisah (atau satu tabel besar yang dibagi menjadi dua area).
- Lokasi Alternatif: Setiap _key_ memiliki tepat dua posisi potensial di dalam tabel, yaitu $h_1(key)$ dan $h_2(key)$.
- Proses _Displacement_ (Penggusuran): Jika sebuah _key_ baru ingin dimasukkan ke posisi $h_1(key)$ tetapi sudah terisi, _key_ lama yang menempati posisi tersebut akan "diusir" dan dipindahkan ke posisi alternatifnya (jika di $h_1$, pindah ke $h_2$, dan sebaliknya).

## Mekanisme Operasional

- _Insertion_:
    
    1. Masukkan _key_ baru ke $h_1(key)$.
        
    2. Jika posisi tersebut sudah terisi, pindahkan elemen lama ke lokasi alternatifnya menggunakan fungsi _hash_ kedua.
        
    3. Jika lokasi baru tersebut juga terisi, elemen yang ada di sana kembali diusir dan dipindahkan ke lokasi alternatifnya yang lain.
        
    4. Proses ini berlanjut secara berantai hingga semua elemen mendapatkan posisi yang stabil.
        
- _Retrieval_: Karena setiap _key_ hanya bisa berada di dua posisi, proses pencarian sangat cepat. Sistem cukup memeriksa $h_1(key)$ dan $h_2(key)$. Jika tidak ditemukan di salah satu dari dua posisi tersebut, maka _key_ dipastikan tidak ada dalam tabel.
    
- _Deletion_: Sama seperti _retrieval_, sistem cukup memeriksa dua posisi tersebut. Jika ditemukan, elemen dapat langsung dihapus tanpa meninggalkan _tombstone_ atau mengganggu rantai _probing_ lainnya.

## Analisis Kinerja

- _Worst-case Retrieval_: Karena hanya ada dua lokasi yang perlu diperiksa, waktu pencarian selalu konstan $O(1)$, menjadikannya salah satu metode tercepat untuk operasi baca.
    
- _Cycle Detection_: Selama proses _insertion_, mungkin terjadi _infinite loop_ jika rantai penggusuran membentuk sebuah siklus. Jika hal ini terjadi, sistem harus melakukan _rehash_ (membangun ulang tabel dengan fungsi _hash_ baru) untuk memecahkan siklus tersebut.
    
- _Load Factor_: Efektivitas _cuckoo hashing_ menurun drastis jika _load factor_ terlalu tinggi (biasanya performa optimal di bawah 50%). Jika kapasitas sudah terlalu penuh, probabilitas terjadinya siklus saat _insertion_ meningkat tajam.
    
- _Rehashing_: _Cuckoo hashing_ memerlukan manajemen memori yang lebih dinamis karena sering kali harus melakukan _rehash_ total saat terjadi siklus, yang memakan waktu cukup signifikan dibandingkan dengan metode _chaining_.

## Keunggulan dan Keterbatasan

- Keunggulan: Kecepatan _retrieval_ yang absolut dan deterministik. Sangat cocok untuk sistem yang frekuensi pembacaan datanya jauh lebih tinggi dibandingkan frekuensi penulisan.
    
- Keterbatasan: Proses _insertion_ bersifat probabilistik dan bisa sangat lambat dalam kondisi tertentu karena kemungkinan terjadinya siklus penggusuran yang panjang.