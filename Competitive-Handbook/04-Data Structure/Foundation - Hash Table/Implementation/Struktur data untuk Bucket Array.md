---
obsidianUIMode: preview
note_type: tips trick
tips_trick:
sumber:
date_learned: 2026-07-12T02:17:00
tags:
---
---
# Struktur data untuk Bucket Array

> Struktur data apa yang paling cocok digunakan sebagai *bucket array* di *hash table*? Apakah `std::array` atau `std::vector`

Pilihan yang sangat krusial di awal. Mari kita bedah berdasarkan kebutuhan struktur data yang ingin Anda bangun:

## Analisis Opsi

- **`std::array`**: Ini adalah _container_ dengan ukuran yang tetap dan ditentukan saat waktu kompilasi (_compile-time_). Jika Anda memilih ini, Anda harus menetapkan ukuran tabel dari awal dan tidak bisa mengubahnya nanti. Anda akan kesulitan saat ingin mengimplementasikan fitur _resizing_ atau _rehashing_ yang baru saja kita bahas.

- **`std::vector`**: Ini adalah _container_ yang ukuran memorinya bisa berubah secara dinamis (_runtime_). Karena `vector` bisa tumbuh dan menyusut sesuai kebutuhan, ini adalah pilihan standar untuk mengelola _bucket array_ pada _hash table_ yang fleksibel.

## Pertimbangan untuk Implementasi Anda

Jika tujuan Anda adalah membangun _hash table_ yang mendekati perilaku `std::unordered_map` (yang mendukung _resizing_ saat _load factor_ tinggi):

- **Fleksibilitas**: `std::vector` memberikan fleksibilitas untuk alokasi ulang memori saat Anda perlu memperbesar tabel melalui _rehashing_.
- **Akses**: Keduanya memberikan performa akses _random_ $O(1)$ menggunakan operator indeks `[]`, yang sangat penting untuk performa _hash table_.
- **Memori**: `std::vector` mengelola alokasi _heap_-nya sendiri secara otomatis, yang akan sangat membantu dalam mengelola siklus hidup data Anda.

## Kesimpulan

Untuk `unordered_map` yang akan Anda buat sendiri, **`std::vector`** adalah pilihan yang jauh lebih tepat dan pragmatis. Ia akan menjadi "tulang punggung" yang menampung _bucket-bucket_ Anda.