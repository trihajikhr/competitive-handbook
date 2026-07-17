---
obsidianUIMode: preview
note_type: tips trick
tips_trick:
sumber:
date_learned: 2026-07-12T04:00:00
tags:
---
---
# Bucket Array Size
> Ketika membuat *hash table*, berapa ukuran yang pas untuk dijadikan ukuran default *bucket array*?
## _Power of Two Sizing_: Optimasi Bitwise untuk _Hash Table_

Pendekatan _power of two_ ($size = 2^k$) adalah teknik yang sangat populer dalam implementasi _hash table_ modern (seperti `unordered_map` di banyak kompilator dan `HashMap` di Java/Go). Fokus utamanya adalah meminimalkan siklus instruksi CPU saat menentukan indeks _bucket_.

### Mengapa _Power of Two_?

Dalam sebuah _hash table_, operasi yang paling sering dilakukan adalah pemetaan _hash code_ ke indeks _bucket_: `index = hash % size`.

- **Masalah Operasi Modulo**: Bagi CPU, instruksi pembagian (DIV) untuk operasi modulo adalah salah satu instruksi yang paling lambat.
- **Keunggulan _Bitwise AND_**: Jika ukuran tabel ($M$) adalah pangkat dua ($2^k$), maka angka tersebut dalam bentuk biner hanya memiliki satu bit bernilai `1` di posisi ke-$k$, dan sisanya `0`. Sebagai contoh, jika $M=16$ ($10000$ dalam biner), maka $M-1=15$ ($01111$ dalam biner).
- **Efisiensi**: Operasi `hash % 16` secara matematis identik dengan `hash & 15`. Instruksi `AND` di tingkat _hardware_ jauh lebih cepat daripada instruksi pembagian.

### Konsekuensi Terhadap Fungsi _Hash_

Karena kita "membuang" bit-bit yang lebih tinggi dan hanya mengambil bit-bit rendah (tergantung nilai $M-1$), fungsi _hash_ menjadi sangat bergantung pada distribusi bit tersebut.

- **Pola Data yang Berbahaya**: Jika fungsi _hash_ Anda hanya menghasilkan angka yang bit rendahnya mirip, maka akan terjadi _collision_ yang sangat parah karena semua angka tersebut akan dipetakan ke _bucket_ yang sama.
- **Kebutuhan _Hash Mixing_**: Untuk menggunakan _power of two_, Anda **wajib** memiliki fungsi _hash_ yang kuat yang mampu "menyebarkan" bit input ke seluruh posisi (sering disebut _avalanche effect_). Jika bit input diubah sedikit saja, semua bit output harus berubah secara acak.

### Strategi _Resizing_

Saat melakukan _rehashing_ pada tabel berbasis _power of two_, ada optimasi elegan yang bisa dilakukan:

- Karena ukuran baru adalah $2 \times M_{old}$, maka $M_{new} - 1$ hanyalah $M_{old} - 1$ ditambah satu bit tambahan di posisi yang lebih tinggi.
- Artinya, saat _rehashing_, sebuah elemen hanya memiliki dua kemungkinan posisi: tetap di indeks yang sama, atau pindah ke `indeks + M_{old}`. Anda tidak perlu menghitung ulang fungsi _hash_ dari awal untuk seluruh angka, cukup periksa satu bit tersebut.

## _Prime Number Sizing_: Distribusi yang Tangguh

_Prime number sizing_ adalah pendekatan klasik yang memprioritaskan keamanan distribusi data di atas kecepatan CPU murni.

### Mengapa _Prime Number_?

Tujuan utamanya adalah memecah pola aritmatika pada data input agar tidak terjadi _clustering_ (pengelompokan) di _bucket_ tertentu.

- **Menghindari _Bad Hashing_**: Banyak fungsi _hash_ sederhana (misalnya yang hanya menjumlahkan nilai karakter _string_ atau _integer_ berurutan) akan menghasilkan angka yang memiliki hubungan aritmatika tertentu (misal kelipatan 10, atau kelipatan 2).
    
- **Efek Modulo Bilangan Prima**: Jika Anda menggunakan ukuran $M$ yang prima, maka `hash % M` akan lebih kecil kemungkinannya untuk menghasilkan indeks yang sama secara berulang meskipun data input memiliki pola tertentu. Bilangan prima tidak memiliki faktor pembagi selain 1 dan dirinya sendiri, sehingga ia "menabrak" pola kelipatan dengan lebih efektif daripada angka pangkat dua.
    

### Kelemahan Utama

- **Biaya CPU**: Anda tetap harus menggunakan operator modulo (`%`) yang lambat karena tidak ada optimasi bitwise untuk bilangan prima (kecuali bilangan prima Mersenne, namun ini jarang digunakan untuk _hash table_ umum).
    
- **Kompleksitas _Resizing_**: Anda harus menyiapkan daftar bilangan prima terlebih dahulu (misalnya: 17, 31, 67, 127, 257, 509, 1021, ...). Saat melakukan _rehashing_, Anda tidak bisa sekadar menggeser bit seperti pada _power of two_; Anda harus menghitung ulang `hash % M_{new}` untuk setiap elemen.
    

## Perbandingan untuk Implementasi Anda

| Fitur              | Power of Two                           | Prime Number                     |
| ------------------ | -------------------------------------- | -------------------------------- |
| Operasi Indeks | `hash & (M-1)` (Sangat Cepat)          | `hash % M` (Lambat)              |
| Ketangguhan    | Bergantung pada kualitas fungsi _hash_ | Lebih tangguh terhadap pola data |
| Implementasi   | Sangat mudah dengan bitwise            | Memerlukan daftar _prime_        |
| Penggunaan     | _High-performance systems_             | _General-purpose applications_   |

### Saran Kolaborasi:

Untuk latihan Anda, jika Anda ingin merasakan "pengalaman _engineer_" yang membangun `std::unordered_map`, cobalah **_power of two_**. Namun, jika Anda ingin meminimalisir risiko _collision_ yang disebabkan oleh fungsi _hash_ yang masih sederhana, gunakan **_prime number_**.