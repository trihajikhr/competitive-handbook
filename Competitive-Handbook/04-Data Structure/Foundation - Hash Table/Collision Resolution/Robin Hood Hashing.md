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
# Robin Hood Hashing

_Robin Hood hashing_ merupakan variasi dari metode _open addressing_ yang bertujuan untuk menyeimbangkan jarak pencarian setiap _key_ di dalam _hash table_. Nama teknik ini berasal dari prinsip mengambil dari yang kaya dan memberikan kepada yang miskin, yaitu menyeimbangkan distribusi jarak pencarian agar tidak ada data yang terlalu jauh dari posisi _hash_ aslinya.

## Prinsip Kerja Utama

- _Distance from Ideal Slot (DIB)_: Setiap elemen menyimpan informasi mengenai _Distance from Initial Bucket_ (DIB), yaitu selisih antara posisi penyimpanan saat ini dengan posisi indeks yang dihasilkan oleh fungsi _hash_.
- _Swap Logic_: Saat melakukan _insertion_, jika sistem menemukan data baru yang memiliki jarak DIB lebih besar daripada data yang sudah menempati suatu _slot_, maka sistem akan menukar posisi kedua data tersebut.
- _Fairness_: Data yang baru (yang mungkin memiliki DIB lebih besar karena _collision_ berkepanjangan) akan mengambil alih posisi data lama yang lebih dekat dengan indeks idealnya. Data yang lama kemudian dipindahkan ke posisi berikutnya untuk mencari tempat baru.

## Mekanisme Operasional

- _Insertion_: Ketika _key_ baru dipetakan ke sebuah indeks, sistem mulai melakukan _probing_. Jika ditemukan _slot_ yang sudah terisi, sistem membandingkan DIB _key_ baru dengan DIB data yang ada di _slot_ tersebut. Jika DIB _key_ baru lebih besar, data ditukar (_swap_) dan proses _probing_ berlanjut dengan data yang sebelumnya menempati _slot_ tersebut.
- _Retrieval_: Proses pencarian tetap mengikuti alur _probing_ standar. Namun, karena distribusi data lebih merata, waktu tunggu rata-rata untuk menemukan _key_ menjadi lebih stabil.
- _Early Exit_: Karena data yang memiliki DIB besar selalu didorong lebih jauh, kita dapat berhenti mencari jika kita menjumpai data yang memiliki DIB lebih kecil daripada DIB _key_ yang sedang dicari, karena secara logis _key_ tersebut tidak mungkin berada di posisi lebih jauh.
## Analisis Kinerja

- _Clustering Reduction_: Teknik ini secara efektif mengurangi varians dari panjang pencarian (_probe sequence length_). Masalah _clustering_ yang biasanya parah pada _linear probing_ dapat diredam secara signifikan.
- _Performance Consistency_: _Robin Hood hashing_ menghasilkan distribusi jarak pencarian yang jauh lebih seragam. Hal ini membuat performa _retrieval_ menjadi lebih stabil meskipun _load factor_ tinggi.
- _Complexity_: Memerlukan sedikit tambahan memori untuk menyimpan nilai DIB pada setiap _node_ atau elemen data, namun peningkatan stabilitas performa sering kali dianggap sepadan dengan biaya tersebut.

## Perbandingan dengan _Open Addressing_ Standar

- _Clustering_: Berbeda dengan _linear probing_ yang membiarkan _cluster_ tumbuh tak terkendali, _Robin Hood hashing_ aktif merestrukturisasi _cluster_ selama proses _insertion_.
- _Efficiency_: Memungkinkan _load factor_ yang lebih tinggi tanpa mengalami penurunan performa yang sedrastis _linear probing_ atau _quadratic probing_.