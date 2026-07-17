---
obsidianUIMode: preview
note_type: book theory
judul_materi:
sumber:
date_learned: 2026-07-12T00:56:00
tags:
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Collision

_Collision_ terjadi ketika fungsi _hash_ $h(k)$ memetakan dua atau lebih _key_ yang berbeda ($k_1 \neq k_2$) ke dalam indeks _array_ yang sama, yaitu $h(k_1) = h(k_2)$. Ini adalah konsekuensi logis dari keterbatasan ruang memori.

Dengan bahasa yang dipermudah, _collision_ dalam _hash table_ bisa dibayangkan seperti kejadian saat dua orang tamu hotel mendapatkan nomor kamar yang sama dari resepsionis, padahal kamar tersebut hanya bisa menampung satu orang. Hal ini terjadi karena sistem _hash_ yang kita gunakan, setelah mengolah data yang masuk, ternyata mengarahkan mereka ke alamat atau indeks _array_ yang persis sama. Karena posisi di dalam _array_ tersebut terbatas dan tidak bisa menyimpan lebih dari satu informasi utama secara langsung, maka terjadilah benturan yang mengharuskan sistem untuk menentukan aturan tambahan agar tidak ada data yang hilang atau tertukar.

## Mengapa Collision Tidak Terelakkan?

- **Pigeonhole Principle**: Secara matematis, jika Anda memiliki $N$ _slot_ di _array_ dan Anda mencoba menyimpan $N+1$ _key_ ke dalamnya, setidaknya satu _slot_ akan menampung lebih dari satu _key_. Karena ruang penyimpanan (kapasitas _array_) selalu terbatas dan jumlah input data (ruang _key_) biasanya jauh lebih besar, _collision_ adalah kepastian statistik.
- **Hash Function Constraints**: Fungsi _hash_ idealnya bersifat seragam (_uniform hashing_), namun dalam praktiknya, fungsi _hash_ yang sempurna (yang tidak pernah menghasilkan _collision_) sangat sulit dibuat kecuali jika kita mengetahui seluruh _set_ data sejak awal (disebut _perfect hashing_).

## Anatomi Terjadinya Collision

1. **Input Pemrosesan**: Dua _key_ berbeda dimasukkan ke dalam fungsi _hash_ yang sama.
2. **Pemetaan Indeks**: Meskipun inputnya berbeda secara bit-level, fungsi _hash_ mereduksi nilai-nilai tersebut ke dalam rentang indeks yang terbatas ($0$ sampai $M-1$, di mana $M$ adalah ukuran _array_).
3. **Benturan Lokasi**: Ketika hasil perhitungan indeks untuk _key_ kedua menunjukkan posisi yang sudah terisi oleh data dari _key_ pertama, maka secara teknis terjadi _collision_.

## Dampak pada Integritas Data

- **Potensi Data Loss**: Jika sistem tidak memiliki mekanisme resolusi, data baru mungkin akan menimpa (_overwrite_) data yang sudah ada di _slot_ tersebut.
- **Degradasi Operasional**: _Collision_ memaksa sistem untuk melakukan langkah tambahan setelah mendapatkan indeks. Tanpa _collision_, pencarian data adalah $O(1)$. Dengan _collision_, pencarian menjadi bergantung pada bagaimana data tersebut diatur setelah benturan terjadi.

## Pengaruh Load Factor terhadap Collision

_Load factor_ ($\alpha = n/k$) bertindak sebagai tekanan pada sistem. Semakin tinggi nilai $\alpha$, semakin padat _array_ kita. Padatnya _array_ ini secara langsung berkorelasi dengan peningkatan probabilitas _collision_. Dalam kondisi _load factor_ yang rendah, _collision_ mungkin jarang terjadi, namun seiring bertambahnya data, _collision_ akan menjadi frekuensi yang rutin dialami oleh struktur data tersebut.