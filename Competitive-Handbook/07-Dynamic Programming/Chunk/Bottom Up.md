---
obsidianUIMode: preview
note_type: book theory
judul_materi: Bottom Up
sumber:
  - myself
date_learned: 2026-07-20T01:58:00
tags:
  - dynamic-programming
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Bottom Up
Dalam _Dynamic Programming_ (DP), **Bottom-Up** (sering disebut juga sebagai pendekatan **tabulasi**) adalah metode penyelesaian masalah dengan cara membangun solusi dari kasus yang paling kecil (sub-masalah terkecil) hingga mencapai kasus utama yang ingin diselesaikan.

Berikut adalah penjelasan mendalam mengenai konsep ini:

## Konsep Utama

Berbeda dengan pendekatan _Top-Down_ (rekursif/memoization) yang memecah masalah besar menjadi masalah kecil secara bertahap, **Bottom-Up** bekerja secara terbalik:

1. **Iteratif:** Menggunakan perulangan (_looping_) daripada rekursi.
2. **Menyimpan Hasil:** Hasil dari sub-masalah disimpan dalam sebuah struktur data (biasanya _array_ atau tabel 1D/2D).
3. **Membangun Solusi:** Anda mengisi tabel tersebut dari indeks awal (kasus dasar) secara berurutan hingga mencapai indeks akhir yang merupakan jawaban dari masalah utama.

## Analogi Sederhana

Bayangkan Anda ingin menaiki tangga sampai ke anak tangga ke-10:

- **Top-Down:** Anda berdiri di tangga ke-10 dan berpikir, "Untuk sampai ke sini, saya harus berada di tangga ke-9 atau ke-8." Anda mundur ke bawah sampai ke dasar, lalu naik lagi.
- **Bottom-Up:** Anda mulai dari tanah (tangga ke-0), lalu melangkah ke tangga ke-1, ke-2, dan seterusnya hingga akhirnya sampai di tangga ke-10 dengan menggunakan informasi dari anak tangga sebelumnya yang sudah Anda injak.

## Kelebihan Bottom-Up

- **Efisiensi Memori:** Karena tidak menggunakan rekursi, kita menghindari risiko _Stack Overflow_ (kehabisan memori tumpukan fungsi).
- **Kecepatan:** Biasanya sedikit lebih cepat daripada _top-down_ karena tidak ada _overhead_ (beban tambahan) dari pemanggilan fungsi rekursif secara terus-menerus.
- **Urutan yang Jelas:** Anda bisa melihat dengan jelas bagaimana setiap sub-masalah berkontribusi pada solusi akhir.

### Contoh: Bilangan Fibonacci

Untuk mencari nilai Fibonacci ke-n, rumusnya adalah $F(n) = F(n-1) + F(n-2)$.

Jika menggunakan **Bottom-Up** (menggunakan array/tabel):
```
def fibonacci_bottom_up(n):
    if n <= 1: return n
    
    # Membuat tabel untuk menyimpan hasil
    dp = [0] * (n + 1)
    dp[1] = 1
    
    # Mengisi tabel dari bawah ke atas
    for i in range(2, n + 1):
        dp[i] = dp[i-1] + dp[i-2]
        
    return dp[n]
```

## Kapan Menggunakan Bottom-Up?

Anda sebaiknya menggunakan pendekatan ini jika:

1. Anda sudah mengetahui urutan sub-masalah yang harus diselesaikan.
2. Anda ingin mengoptimalkan penggunaan memori (terkadang tabel DP bisa dioptimalkan lebih jauh lagi menjadi hanya beberapa variabel saja jika hanya membutuhkan nilai sebelumnya).
3. Anda ingin menghindari batasan kedalaman rekursi (_recursion depth limit_) pada bahasa pemrograman tertentu.
