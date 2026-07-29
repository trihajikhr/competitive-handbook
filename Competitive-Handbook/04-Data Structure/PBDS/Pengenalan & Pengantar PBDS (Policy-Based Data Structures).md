---
obsidianUIMode: preview
note_type: book theory
judul_materi: Pengenalan & Pengantar PBDS (Policy-Based Data Structures)
sumber:
  - myself
date_learned: 2026-07-26T17:28:00
tags:
  - data-structures
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Pengenalan & Pengantar PBDS (Policy-Based Data Structures)

## 1. Definisi dan Karakteristik

**Policy-Based Data Structures (PBDS)** adalah sekumpulan ekstensi struktur data tingkat lanjut yang disediakan oleh GNU C++ compiler (`libstdc++`). Berbeda dengan **STL (Standard Template Library)** konvensional yang menyediakan wadah standar seperti `std::set`, `std::map`, atau `std::priority_queue`, PBDS dirancang dengan arsitektur berbasis kebijakan (_policy-based design_).

Arsitektur ini memungkinkan pengembang untuk menyesuaikan perilaku internal struktur data—seperti mekanisme _hashing_, strategi penyeimbangan pohon (_tree balancing_), atau algoritma _heap_—tanpa harus menulis ulang implementasi dasarnya dari awal.

## 2. Perbedaan Utama dengan STL Konvensional

Meskipun beberapa wadah di PBDS tampak serupa dengan STL, terdapat perbedaan mendasar pada fungsionalitas dan fleksibilitasnya:

- **Fitur Tambahan (Order Statistics):** `std::set` standar tidak memiliki cara efisien untuk mencari elemen berdasarkan indeks ke-$k$ atau mengetahui peringkat suatu nilai. PBDS melalui kontainer `tree` menyediakan fungsi khusus yang dapat mengeksekusi operasi tersebut dalam waktu logaritmik.
    
- **Keamanan Hash:** `std::unordered_map` rentan terhadap _anti-hash tests_ (serangan _malicious input_ yang sengaja memicu _collision_ maksimal sehingga kompleksitas waktu merosot menjadi $O(N^2)$). PBDS menyediakan `gp_hash_table` dengan penanganan _probing_ yang jauh lebih cepat dan aman untuk _competitive programming_.
    
- **Variasi Heap yang Kaya:** `std::priority_queue` hanya mendukung struktur _binary heap_ standar. PBDS menyediakan berbagai varian _heap_ (seperti _pairing heap_ dan _fibonacci heap_) yang mendukung operasi penggabungan (_meld_) dan pembaruan kunci (_decrease-key_) yang efisien.

## 3. Keunggulan di Competitive Programming

Dalam konteks pemecahan masalah algoritmik, PBDS sering kali menjadi solusi pintas (_shortcut_) untuk menghindari implementasi struktur data rumit yang memakan waktu:

- **Menghindari Segment Tree / Fenwick Tree yang Rumit:** Masalah seperti _Inversion Count_ atau pencarian elemen ke-$k$ pada rentang yang dinamis dapat diselesaikan dengan mudah menggunakan _Ordered Set_ dari PBDS.
    
- **Performa Tinggi:** Diimplementasikan langsung pada tingkat pustaka sistem GNU, struktur data ini dioptimalkan untuk meminimalkan _overhead_ memori dan waktu eksekusi.

## 4. Kompatibilitas Compiler

Sebelum menggunakan PBDS, penting untuk memahami batasan lingkungan pengembangannya:

- **Didukung Penuh (GNU GCC):** Hampir seluruh _online judge_ kompetitif (seperti Codeforces, CodeChef, TLX, AtCoder) menggunakan compiler GCC/G++, sehingga _header_ PBDS dijamin berfungsi sempurna.
    
- **Tidak Didukung (MSVC):** Compiler bawaan Microsoft Visual Studio tidak menyertakan pustaka `ext/pb_ds`. Jika kamu menggunakan sistem operasi Windows, pastikan lingkungan pengembangan lokal menggunakan toolchain **MinGW-w64** atau **GCC** (misalnya melalui WSL atau MinGW di dalam VS Code).