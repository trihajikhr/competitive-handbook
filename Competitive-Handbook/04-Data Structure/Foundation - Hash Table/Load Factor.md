---
obsidianUIMode: preview
note_type: book theory
judul_materi:
sumber:
date_learned: 2026-07-12T00:30:00
tags:
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Load Factor


_Load factor_ adalah metrik utama dalam _hash table_ yang mengukur seberapa penuh _bucket_ atau _slot_ yang tersedia di dalam _array_. Nilai ini menjadi indikator penting untuk memantau efisiensi struktur data tersebut.

_Load factor_ dapat dipahami sebagai indikator efisiensi yang merepresentasikan rasio antara jumlah elemen yang tersimpan dengan total kapasitas _bucket_ yang tersedia dalam suatu _hash table_. Secara teknis, nilai ini berfungsi sebagai parameter krusial untuk mengukur kepadatan data di dalam struktur penyimpanan tersebut. Apabila jumlah data telah melampaui batas ambang kapasitas yang ditentukan, probabilitas terjadinya _collision_ akan meningkat secara signifikan, yang pada akhirnya dapat menurunkan performa sistem secara keseluruhan. Oleh karena itu, _load factor_ menjadi acuan utama dalam menentukan kapan suatu sistem perlu melakukan prosedur _rehashing_ atau ekspansi kapasitas memori guna menjaga performa operasi tetap optimal.

## Definisi _load factor_

Secara matematis, _load factor_ dilambangkan dengan $\alpha$ dan dirumuskan sebagai berikut:

$$\alpha = \frac{n}{k}$$

- $n$: adalah jumlah entri atau elemen yang saat ini disimpan di dalam _hash table_.
- $k$: adalah jumlah total _bucket_ atau ukuran _array_ yang tersedia.

## Mengapa _load factor_ itu penting?

- Indikator kinerja: _Load factor_ menunjukkan seberapa besar kemungkinan terjadinya _collision_. Semakin tinggi nilainya, semakin besar risiko tabrakan data karena _bucket_ yang tersedia semakin sedikit.
- Pemicu _rehashing_: _Load factor_ biasanya digunakan sebagai ambang batas (_threshold_) untuk melakukan _rehashing_. Jika _load factor_ melampaui angka tertentu (misalnya $0,7$ atau $0,75$), maka _hash table_ perlu memperbesar ukuran _array_ agar performa operasi tetap optimal.
- Keseimbangan memori dan kecepatan: Nilai _load factor_ yang rendah berarti penggunaan memori lebih boros karena banyak _bucket_ kosong, namun akses data menjadi sangat cepat. Sebaliknya, nilai yang tinggi menghemat memori namun meningkatkan risiko _collision_ yang dapat memperlambat waktu akses data.

## Dampak pada operasi

- Jika _load factor_ terlalu mendekati 1, kinerja _hash table_ akan menurun drastis karena _collision resolution_ (seperti _chaining_ atau _open addressing_) harus bekerja lebih keras setiap kali ada operasi penyisipan atau pencarian.
- Dengan menjaga _load factor_ tetap rendah melalui proses _rehashing_ secara berkala, waktu operasi _constant time_ $O(1)$ dapat tetap dipertahankan.
# FAQ

## Penjelasan Rehashing
_Rehashing_ adalah proses membangun kembali struktur _hash table_ dengan kapasitas yang lebih besar. Proses ini dipicu ketika nilai _load factor_ melampaui batas ambang tertentu, yang menandakan bahwa _hash table_ sudah terlalu penuh dan risiko _collision_ semakin tinggi.

Berikut adalah tahapan dalam proses _rehashing_:

- Membuat _array_ baru dengan ukuran yang lebih besar, biasanya dua kali lipat dari ukuran _array_ sebelumnya.
- Menginisialisasi ulang seluruh _bucket_ pada _array_ baru tersebut.
- Memindahkan setiap elemen dari _array_ lama ke _array_ baru dengan menghitung ulang indeksnya menggunakan _hash function_ yang baru disesuaikan dengan ukuran _array_ yang telah diperbesar.
- Setelah seluruh elemen berhasil dipindahkan, _array_ lama akan dihapus atau dibebaskan dari memori.

Meskipun _rehashing_ merupakan operasi yang membutuhkan _computational complexity_ sebesar $O(n)$ karena harus memproses ulang seluruh data, tindakan ini sangat diperlukan untuk menjaga performa operasi _search_, _insertion_, dan _deletion_ agar tetap mendekati _constant time_ $O(1)$ di masa mendatang.
