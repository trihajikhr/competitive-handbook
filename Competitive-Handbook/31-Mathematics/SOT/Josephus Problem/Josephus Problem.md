---
obsidianUIMode: preview
note_type: book theory
judul_materi: Josephus Problem
sumber:
  - CSES
date_learned: 2026-07-20T17:13:00
tags:
  - mathematics
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Josephus Problem
*Josephus problem* adalah sebuah teka-teki matematika atau ilmu komputer klasik yang melibatkan eliminasi orang dalam lingkaran.

Secara naratif, masalah ini dinamai dari Flavius Josephus, seorang sejarawan Yahudi yang terjebak bersama 40 tentaranya di dalam sebuah gua oleh pasukan Romawi. Alih-alih menyerah atau bunuh diri, kelompok tersebut memutuskan untuk membentuk lingkaran dan membunuh setiap orang ke-$k$ sampai tersisa satu orang yang akan bertahan hidup (atau dalam versi sejarahnya, Josephus dan satu orang lainnya mengatur posisi agar selamat).

Dalam bentuk formalnya, aturan permainan ini adalah sebagai berikut:

- Terdapat $n$ orang yang dinomori dari $1$ sampai $n$ dan disusun melingkar.
- Dimulai dari orang pertama, proses hitung maju sebanyak $k$ orang dilakukan.
- Orang ke-$k$ yang jatuh pada hitungan tersebut dieliminasi dari lingkaran.
- Proses diulang dari orang berikutnya setelah yang tereliminasi hingga hanya tersisa satu orang.

Tujuan utama dari masalah ini adalah menentukan posisi awal orang ke berapa yang akan bertahan hidup terakhir (sering dinotasikan sebagai $J(n)$ untuk kasus eliminasi setiap orang ke-2 atau $k = 2$).

Untuk kasus umum dengan $k = 2$, terdapat solusi analitis menggunakan representasi biner dari $n$:

$$J(n) = 2(n - 2^{\lfloor \log_2 n \rfloor}) + 1$$

Dalam ilmu komputer, masalah ini sering diselesaikan menggunakan struktur data seperti _Circular Linked List_, pendekatan rekursif, atau pemrograman dinamis untuk efisiensi kompleksitas waktu.

## Kode dan Algoritma

```cpp
int josephus(int n, int k) {
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res = (res + k) % i;
    return res + 1;
}
```

Algoritma **Josephus Problem** di atas adalah salah satu solusi paling elegan dan efisien menggunakan pendekatan **pemrograman dinamis (dynamic programming)** secara iteratif. Kode tersebut menyelesaikan masalah dengan kompleksitas waktu $O(n)$ dan kompleksitas ruang $O(1)$.

Berikut adalah penjelasan rinci mengenai cara kerja algoritma tersebut dan mengapa hasilnya terbukti benar.

### Cara Kerja Algoritma

Masalah Josephus klasik melibatkan $n$ orang yang berdiri melingkar (diberi nomor 1 sampai $n$). Proses eliminasi dimulai dari orang pertama, di mana setiap orang ke-$k$ akan disingkirkan sampai tersisa satu orang terakhir.

Potongan kode C++ di atas memetakan posisi orang yang bertahan menggunakan indeks berbasis 0 ($0$ sampai $n-1$), lalu di akhir ditambahkan $1$ (`res + 1`) untuk mengembalikannya ke penomoran berbasis 1 ($1$ sampai $n$).

Mari kita bedah cara kerjanya per langkah:

1. **Inisialisasi (`res = 0`):**
    
    Ketika hanya ada $1$ orang ($n = 1$), orang tersebut pasti berada di posisi indeks `0` (atau posisi pertama). Oleh karena itu, basis rekursifnya dimulai dari `res = 0`.
    
2. **Loop Iteratif (`for (int i = 1; i <= n; ++i)`):**
    
    Algoritma membangun solusi secara bottom-up, mulai dari kelompok berukuran $i = 1$ hingga mencapai ukuran akhir $i = n$.
    
3. **Transisi Posisi (`res = (res + k) % i`):**
    
    Setiap kali ukuran lingkaran bertambah dari $i-1$ ke $i$, posisi orang yang selamat digeser sebesar $k$ langkah, lalu dibungkus dengan operasi modulo (`% i`) karena bentuknya melingkar (lingkaran berukuran $i$).
    

### Mengapa Ini Menjadi Jawaban yang Benar? (Penjelasan Matematis)

Kebenaran dari rumus `res = (res + k) % i` didasarkan pada hubungan rekurensi (penurunan rumus) dari Josephus problem.

Misalkan kita mendefinisikan $J(n, k)$ sebagai indeks orang yang selamat dari $n$ orang dengan keloncatan $k$ (menggunakan indeks 0).

1. Ketika kita mengeliminasi orang ke-$k$ dari lingkaran yang berisi $n$ orang, orang yang tersisa sekarang berada dalam lingkaran baru dengan ukuran $n - 1$ orang.
    
2. Posisi awal penghitungan di lingkaran baru bergeser sebanyak $k$ posisi dari awal lingkaran lama.
    
3. Oleh karena itu, jika posisi orang yang selamat pada lingkaran ukuran $n-1$ adalah $J(n-1, k)$, maka posisi orang tersebut di lingkaran asal yang berukuran $n$ dapat dikembalikan dengan rumus pergeseran:
    
    $$J(n, k) = (J(n-1, k) + k) \pmod n$$
    

Kode iteratif di atas mengimplementasikan rumus relasi rekurensi ini dari bawah ke atas:

- Mulai dari $i = 1$ (1 orang, posisi selamat = `0`).
    
- Naik ke $i = 2$ (2 orang, posisi dihitung dari hasil sebelumnya ditambah $k$, lalu dimodulo 2).
    
- Terus berlanjut hingga $i = n$.
    

Karena perhitungan ini mencerminkan relasi matematika yang sah untuk setiap penambahan ukuran lingkaran eliminasi, hasil akhir `res` dijamin akurat menunjuk pada indeks orang yang bertahan hidup. Penambahan angka `1` di akhir (`res + 1`) sekadar menyesuaikan kembali format indeks dari basis 0 ke basis 1 yang lazim digunakan manusia.