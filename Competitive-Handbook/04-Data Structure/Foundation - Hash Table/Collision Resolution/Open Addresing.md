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
# Open Addresing

_Open addressing_ merupakan teknik resolusi _collision_ di mana seluruh elemen data disimpan langsung di dalam _array_ utama. Ketika terjadi _collision_, sistem akan mencari _slot_ kosong lain di dalam _array_ tersebut untuk menempatkan data yang baru, alih-alih menggunakan struktur data tambahan di luar _array_.

## Mekanisme Dasar

- Pencarian _Slot_ Alternatif (_Probing_): Ketika _hash function_ memetakan _key_ ke indeks yang sudah terisi, sistem akan melakukan _probing_ (penelusuran) untuk mencari _slot_ kosong berikutnya.
- Penyimpanan Tunggal: Karena tidak ada _pointer_ atau _list_, setiap _slot_ dalam _array_ hanya boleh menampung maksimal satu data.
- Kapasitas Terbatas: Jumlah data yang dapat disimpan dalam _hash table_ dengan metode _open addressing_ dibatasi oleh ukuran _array_ itu sendiri (kapasitas maksimum tidak boleh melebihi jumlah _slot_).
## Teknik _Probing_ Utama

- _Linear Probing_: Sistem memeriksa _slot_ secara berurutan ($index + 1, index + 2, index + 3, \dots$) sampai menemukan _slot_ kosong. Teknik ini sangat ramah terhadap _cache_ karena akses memori yang berdekatan.
- _Quadratic Probing_: Sistem memeriksa _slot_ dengan interval kuadrat ($index + 1^2, index + 2^2, index + 3^2, \dots$). Hal ini membantu mengurangi masalah _primary clustering_ yang sering terjadi pada _linear probing_.
- _Double Hashing_: Sistem menggunakan fungsi _hash_ kedua untuk menentukan interval lompatan. Teknik ini dianggap sebagai salah satu metode paling efektif untuk menyebarkan data karena interval lompatan bergantung pada _key_ itu sendiri, bukan sekadar urutan indeks.
## Analisis Kinerja

- _Clustering_: Kelemahan utama _open addressing_ adalah _clustering_. _Linear probing_ rentan terhadap _primary clustering_ (penumpukan data di area tertentu), sementara _quadratic probing_ dapat mengalami _secondary clustering_.
- _Load Factor_: Performa _open addressing_ sangat sensitif terhadap _load factor_ ($\alpha$). Semakin mendekati angka $1$, performa akan menurun drastis karena sistem semakin sulit menemukan _slot_ kosong. Biasanya, _load factor_ dibatasi di bawah $0.7$ atau $0.8$.
- _Deletion_: Operasi _deletion_ pada _open addressing_ cukup kompleks karena tidak bisa langsung menghapus data. Menghapus data secara langsung dapat memutus rantai _probing_ untuk _key_ lain, sehingga harus menggunakan penanda khusus seperti _tombstone_ (tanda bahwa _slot_ pernah terisi) agar proses _retrieval_ tidak terganggu.

# FAQ
## Deletion lebih rumit
> Berarti proses penghapusan pada hash table ketika menggunakan Open Adressing mallah jauh lebih rumit?

Tepat sekali. Analisis Anda sangat tajam. Proses _deletion_ pada _open addressing_ memang jauh lebih kompleks dan berisiko dibandingkan dengan _chaining_.

Pada _chaining_, menghapus data hanyalah masalah memanipulasi _pointer_ pada _linked list_, yang tidak akan mengganggu akses ke data lain di _bucket_ yang sama. Sebaliknya, pada _open addressing_, menghapus data secara "bersih" (_hard delete_) dapat merusak alur pencarian (_retrieval_).

### Mengapa _Deletion_ pada _Open Addressing_ Rumit?

Masalah utamanya adalah **pemutusan rantai _probing_**. Bayangkan skenario berikut:

1. Kita memasukkan _key_ A, B, dan C yang semuanya menghasilkan indeks awal yang sama.
2. Karena terjadi _collision_, sistem menggunakan _probing_ sehingga data tersimpan di posisi: A -> B -> C (berurutan).
3. Jika kita menghapus data B secara total dan membiarkan _slot_-nya menjadi _empty_ (_null_), maka saat sistem mencoba mencari C di masa depan, sistem akan mengikuti alur _probing_ yang sama.
4. Ketika sistem sampai di _slot_ B yang sekarang kosong, sistem akan menganggap bahwa "C tidak ada dalam tabel" karena proses pencarian berhenti saat menemui _slot_ kosong. Data C pun menjadi tidak terjangkau (_orphaned_), meskipun sebenarnya masih tersimpan di _array_.

### Solusi: Penggunaan _Tombstone_

Untuk mengatasi masalah pemutusan rantai tersebut, implementasi _open addressing_ biasanya menggunakan teknik _lazy deletion_ dengan penanda khusus yang sering disebut sebagai **_tombstone_**:

- **Apa itu _tombstone_?**: Alih-alih mengosongkan _slot_ yang dihapus menjadi _null_, sistem menandai _slot_ tersebut dengan status khusus (_tombstone_).
    
- **Fungsi saat _retrieval_**: Saat proses pencarian (_retrieval_) melewati _slot_ yang ditandai _tombstone_, sistem akan mengabaikannya dan terus melakukan _probing_ sampai menemukan _key_ yang dicari atau sampai bertemu _slot_ yang benar-benar _null_.
    
- **Fungsi saat _insertion_**: Saat proses penyisipan (_insertion_), sistem bisa menggunakan kembali _slot_ ber-_tombstone_ tersebut untuk menyimpan data baru.

### Konsekuensi _Tombstone_

- **Efisiensi Pencarian**: Semakin banyak _tombstone_ yang menumpuk di dalam _array_, maka proses _retrieval_ akan semakin melambat karena sistem harus terus melakukan _probing_ melewati banyak _tombstone_ sebelum menemukan data yang dicari.
- **Maintenance**: Kadang-kadang diperlukan proses _rehash_ (membangun ulang _hash table_) jika jumlah _tombstone_ sudah terlalu banyak agar _hash table_ tetap efisien.

Singkatnya, _open addressing_ mengorbankan kesederhanaan operasi _deletion_ demi menghemat memori (karena tidak butuh _pointer_ tambahan).