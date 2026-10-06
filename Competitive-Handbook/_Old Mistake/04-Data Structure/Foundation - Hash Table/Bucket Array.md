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
# Bucket Array
_Array_ atau _bucket array_ adalah struktur data dasar yang berfungsi sebagai wadah atau tempat penyimpanan utama dalam sebuah _hash table_. Berikut adalah penjelasan mengenai _array_ dalam konteks tersebut:

## Definisi _array_ sebagai wadah

_Array_ adalah kumpulan elemen yang disimpan di lokasi memori yang berdekatan. Dalam sebuah _hash table_, _array_ ini bertindak sebagai ruang penyimpanan utama di mana setiap posisi di dalam _array_ tersebut disebut sebagai _bucket_ atau _slot_.

## Fungsi utama _bucket array_

- Penyimpanan data: Setiap _bucket_ berfungsi sebagai tempat untuk menampung _value_ yang telah dipetakan oleh _hash function_.    
- Akses cepat: Karena _array_ memiliki properti _random access_, sistem dapat langsung menuju ke indeks tertentu dalam waktu _constant time_ $O(1)$ setelah mendapatkan _hash code_.
- Manajemen ruang: _Array_ menyediakan ruang yang sudah dialokasikan sebelumnya untuk menampung data, sehingga proses penyimpanan menjadi sangat efisien.

## Bagaimana _bucket array_ bekerja

1. _Hashing_: Ketika kita ingin menyimpan atau mencari data, _hash function_ akan memproses _key_ dan menghasilkan _hash code_.
2. _Indexing_: _Hash code_ tersebut kemudian dioperasikan dengan modulo ukuran _array_ (misalnya: `hash % arraySize`) untuk mendapatkan indeks yang valid di dalam _array_.
3. _Placement_: Data kemudian disimpan di _bucket_ yang sesuai dengan indeks tersebut.

## Pentingnya ukuran _array_

- Kapasitas: Ukuran _array_ menentukan berapa banyak _bucket_ yang tersedia. Jika ukuran _array_ terlalu kecil dibandingkan jumlah data, risiko terjadinya _collision_ akan meningkat drastis.
- _Resizing_: Jika jumlah elemen sudah terlalu banyak dibandingkan ukuran _array_ (disebut _high load factor_), sistem biasanya akan melakukan _resizing_ atau _rehashing_, yaitu membuat _array_ baru yang lebih besar dan memindahkan seluruh data dari _array_ lama ke _array_ baru agar performa tetap optimal.

Jika Anda membayangkan _hash table_ sebagai sebuah lemari arsip, _array_ adalah deretan laci-laci kosong di lemari tersebut, sementara _hash function_ adalah sistem yang menentukan di laci nomor berapa sebuah dokumen harus diletakkan.
# FAQ
## Masalah ukuran array

> Pertanyaanya, bagaimana kita menentukan ukuran array? Dua kasus, ketika ukuran data diketahui, dan ketika ukuran data tidak diketahui, dan sering sekali bertambah dan bertambah

Menentukan ukuran _array_ dalam _hash table_ merupakan tantangan krusial untuk menjaga keseimbangan antara penggunaan memori dan efisiensi waktu. Berikut adalah penjelasannya berdasarkan dua kondisi yang Anda sebutkan:

### Ketika ukuran data diketahui (Fixed Size)

Jika Anda sudah mengetahui jumlah data maksimal yang akan disimpan, Anda dapat menentukan ukuran _array_ sejak awal agar performa tetap optimal.

- Pilihlah ukuran _array_ yang merupakan bilangan prima (_prime number_). Hal ini sangat disarankan karena bilangan prima membantu mendistribusikan _key_ dengan lebih merata saat menggunakan operasi modulo, sehingga meminimalkan _collision_.
- Tentukan ukuran _array_ berdasarkan _load factor_ yang ideal. Sebagai contoh, jika Anda memiliki 1.000 data dan ingin _load factor_ sebesar 0,75, maka Anda memerlukan ukuran _array_ sekitar 1.333 (1.000 / 0,75). Menggunakan bilangan prima terdekat di atas angka tersebut (misalnya 1.361) adalah praktik yang baik.

### Ketika ukuran data tidak diketahui dan terus bertambah (Dynamic Size)

Jika jumlah data bersifat dinamis dan terus bertambah, kita tidak bisa menetapkan ukuran _array_ yang statis karena akan menyebabkan penurunan performa akibat _load factor_ yang terlalu tinggi.

- Gunakan strategi _dynamic resizing_ (atau _rehashing_). Ini adalah proses di mana sistem secara otomatis membuat _array_ baru yang lebih besar ketika _load factor_ melampaui ambang batas tertentu (misalnya 0,75).
- Biasanya, ukuran _array_ baru dibuat dua kali lipat dari ukuran sebelumnya (_doubling the size_).
- Setelah _array_ baru dibuat, seluruh elemen dari _array_ lama harus dipetakan ulang (_rehashed_) ke dalam _array_ baru karena fungsi indeks `hash % arraySize` akan menghasilkan nilai yang berbeda akibat perubahan ukuran _arraySize_.
    
- Meskipun proses _rehashing_ ini memerlukan _computational complexity_ yang cukup besar $(O(n))$, proses ini jarang terjadi sehingga _amortized time complexity_ untuk operasi penyisipan tetap efisien, yaitu $O(1)$.