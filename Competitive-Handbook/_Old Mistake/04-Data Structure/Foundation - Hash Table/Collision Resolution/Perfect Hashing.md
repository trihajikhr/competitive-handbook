---
obsidianUIMode: preview
note_type: book theory
judul_materi:
sumber:
date_learned:
tags:
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Perfect Hashing

_Perfect hashing_ adalah teknik penyusunan _hash table_ yang menjamin bahwa tidak akan terjadi _collision_ sama sekali. Teknik ini secara khusus dirancang untuk kumpulan _key_ yang bersifat statis, di mana seluruh _key_ yang akan disimpan sudah diketahui sejak awal.

## Prinsip Kerja Utama

- _Static Set_: Teknik ini hanya dapat diterapkan jika kumpulan _key_ tidak berubah setelah _hash table_ dibangun.
    
- _Zero Collision_: Karena seluruh _key_ sudah diketahui, fungsi _hash_ dapat dipilih secara spesifik untuk memetakan setiap _key_ ke indeks unik tanpa benturan.
    
- _Two-level Scheme_: Implementasi paling umum menggunakan skema dua tingkat untuk memastikan efisiensi ruang sekaligus menghindari _collision_.
    

## Skema Dua Tingkat (_Two-level Scheme_)

- Tingkat Pertama: Menggunakan fungsi _hash_ standar yang memetakan _key_ ke dalam sebuah _array_ utama berukuran $M$. Karena fungsi ini tidak menjamin keunikan, _collision_ mungkin terjadi di tingkat ini.
    
- Tingkat Kedua: Setiap _bucket_ pada _array_ utama merupakan sebuah _sub-hash table_ kecil. Jika tingkat pertama menghasilkan _collision_ pada suatu _bucket_ dengan $n$ _key_, maka _sub-table_ tersebut akan dibuat dengan ukuran $n^2$. Ukuran kuadratik ini secara matematis memberikan probabilitas tinggi untuk menemukan fungsi _hash_ yang bebas _collision_ di tingkat kedua.
    

## Karakteristik Operasional

- _Retrieval Time_: Menjamin waktu pencarian dalam _worst-case scenario_ sebesar $O(1)$. Hal ini sangat krusial untuk aplikasi yang membutuhkan performa deterministik.
    
- _Space Complexity_: Meskipun secara teoretis membutuhkan ruang $O(n^2)$ pada kasus ekstrem, penggunaan fungsi _hash_ yang dipilih secara acak dari keluarga _universal hashing_ dapat membatasi penggunaan ruang total rata-rata menjadi linear, yaitu menjadi $O(n)$.
    
- _Construction Cost_: Membutuhkan proses _pre-processing_ yang lebih intensif dibandingkan metode resolusi _collision_ konvensional karena harus menghitung fungsi _hash_ yang tepat untuk setiap _sub-table_.
    

## Analisis Kinerja

- Keunggulan: Memberikan performa pencarian yang optimal dan sangat konsisten. Tidak ada mekanisme _traversal_ seperti pada _chaining_ atau _probing_ seperti pada _open addressing_.
    
- Keterbatasan: Tidak fleksibel terhadap penambahan atau penghapusan data secara _real-time_. Jika data di dalam _hash table_ perlu dimodifikasi, _perfect hashing_ harus dibangun ulang sepenuhnya (_rebuilding_), yang memakan waktu cukup lama.
    
- Penggunaan: Ideal untuk sistem kamus data statis, seperti kata-kata kunci dalam bahasa pemrograman, tabel simbol pada _compiler_, atau _dataset_ yang bersifat _read-only_.
