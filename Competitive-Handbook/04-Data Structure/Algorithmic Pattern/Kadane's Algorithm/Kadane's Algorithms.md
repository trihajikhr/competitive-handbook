---
obsidianUIMode: preview
note_type: book theory
judul_materi: Kadane's Algorithms
sumber:
  - myself
date_learned: 2026-07-15T18:00:00
tags:
  - algorithm
  - data-structures
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Kadane's Algorithms
## Overview

Kadane’s Algorithm adalah algoritma _linear-time_ ($O(N)$) yang digunakan untuk menemukan **Maximum Subarray Sum**—jumlah elemen terbesar dari sub-bagian _array_ yang berurutan. Algoritma ini merupakan teknik fundamental dalam _state tracking_ yang memungkinkan optimasi masalah yang secara naif membutuhkan kompleksitas $O(N^2)$.

## Core Concept

Ide utama Kadane adalah memproses _array_ secara linear dan memutuskan pada setiap langkah: 

- "Apakah lebih baik memperluas subarray yang ada saat ini, atau memulai subarray baru dari elemen saat ini?"

Secara matematis, untuk setiap posisi $i$, kita melacak:

1. **`current_max`**: Jumlah maksimum subarray yang berakhir tepat di indeks $i$.
2. **`global_max`**: Nilai maksimum yang pernah ditemukan di seluruh iterasi.

### The Recurrence Relation

$$current\_max_i = \max(A_i, current\_max_{i-1} + A_i)$$

$$global\_max = \max(global\_max, current\_max_i)$$

## Algorithmic Steps

1. **Inisialisasi**:
    
    - `current_max` = elemen pertama _array_.
    - `global_max` = elemen pertama _array_.
        
2. **Iterasi**: Mulai dari elemen kedua hingga akhir _array_.
    
3. **Update State**:
    
    - Perbarui `current_max` dengan membandingkan nilai elemen saat ini dengan penjumlahan elemen saat ini dan `current_max` sebelumnya.
        
    - Perbarui `global_max` jika `current_max` lebih besar.
        
4. **Terminasi**: Setelah iterasi selesai, `global_max` berisi nilai maksimum yang dicari.
    

## Implementation (C++)

```cpp
#include <vector>
#include <algorithm>
#include <iostream>

long long kadane(const std::vector<int>& arr) {
    long long current_max = arr[0];
    long long global_max = arr[0];

    for (size_t i = 1; i < arr.size(); ++i) {
        // State tracking: pilih antara memulai baru atau melanjutkan
        current_max = std::max((long long)arr[i], current_max + arr[i]);
        
        // Update best state ditemukan
        if (current_max > global_max) {
            global_max = current_max;
        }
    }
    return global_max;
}
```

## Complexity Analysis

| Metric           | Complexity | Note                                                   |
| ---------------- | ---------- | ------------------------------------------------------ |
| Time Complexity  | $O(N)$     | Melakukan satu kali _pass_ linear melalui _array_.     |
| Space Complexity | $O(1)$     | Hanya menggunakan dua variabel untuk _state tracking_. |

## Use Cases

- **Pencarian Rentang Optimal**: Digunakan sebagai sub-rutin dalam masalah yang membutuhkan pemilihan interval terbaik (seperti pada problem _Range Flip_).
    
- **Financial Analysis**: Menentukan periode waktu dengan keuntungan kumulatif tertinggi dalam sebuah data deret waktu (_time-series_).
    
- **Image Processing**: Digunakan dalam deteksi fitur tertentu pada matriks (saat dikembangkan ke 2D menggunakan teknik _prefix sum_).
    

## Key Takeaway

Kadane adalah bukti efisiensi **state tracking**. Daripada melakukan _nested loop_ untuk mengevaluasi setiap kombinasi _subarray_ ($O(N^2)$), kita menggunakan memori $O(1)$ untuk membawa status akumulasi saat ini dan mencapai $O(N)$. Ini adalah teknik wajib untuk setiap _competitive programmer_.

# FAQ

## Kasus Unik
> Wait, kalau kaya gitu, kalau semua elemenya positif, maka kita bisa ambil semua rentangnya sebagai jawaban, atau $l = 1$, dan $r = n$?

Betul sekali. Jika semua elemen di dalam _array_ adalah positif, maka *Kadane's Algorithm* secara otomatis akan menghasilkan jawaban yang mencakup seluruh _array_ (dari indeks $0$ sampai $n-1$).

## Kunci algoritma kadane

> Aku ingin tahu, kenapa
> 
> ```cpp
> current_max = max(arr[i], current_max + arr[i]);
> ```
> 
> Bisa bekerja? Jika ditengah array ada nilai negatif yang besar, bagaimana cara kerja algoritma Kadane mengatasinya?

Pertanyaan yang sangat bagus. Ini adalah inti dari "kecerdasan" algoritma Kadane.

Mari kita bedah secara intuitif menggunakan contoh yang kamu sebutkan: "Bagaimana jika ada angka negatif yang sangat besar di tengah?"

Misalkan array kita adalah: `[10, -100, 5]`

### Langkah demi Langkah Eksekusi

1. **Indeks 0 ($A_0 = 10$):**
    
    - `current_max` = 10.
        
    - `global_max` = 10.
        
2. **Indeks 1 ($A_1 = -100$):**
    
    - Rumusnya: `current_max = max(arr[1], current_max + arr[1])`
        
    - `current_max = max(-100, 10 + (-100))`
        
    - `current_max = max(-100, -90)`
        
    - **Hasilnya adalah -90.**
        
    - _Penjelasan:_ Algoritma mencoba dua hal: "Mulai baru dari -100" atau "Lanjut dari 10". Ternyata, baik lanjut maupun mulai baru, keduanya buruk. Tapi, algoritma memilih -90 karena itu adalah "beban" yang harus dibawa jika kita memaksa mengambil elemen tersebut. `global_max` tetap 10.
        
3. **Indeks 2 ($A_2 = 5$):**
    
    - Rumusnya: `current_max = max(arr[2], current_max + arr[2])`
        
    - `current_max = max(5, -90 + 5)`
        
    - `current_max = max(5, -85)`
        
    - **Hasilnya adalah 5.**
        
    - _Penjelasan:_ Di sini terjadi keajaiban. Algoritma membandingkan: "Apakah aku harus lanjut membawa beban -85 tadi, atau aku **membuang semua beban masa lalu** dan memulai subarray baru dari angka 5?"
        
    - Karena 5 > -85, **algoritma memilih untuk membuang seluruh subarray sebelumnya dan memulai baru dari angka 5.**
        

### Kenapa `std::max` adalah Kunci?

Logika `current_max = max(arr[i], current_max + arr[i])` sebenarnya adalah **mekanisme reset otomatis**.

- Jika `current_max + arr[i]` (akumulasi lama + elemen baru) nilainya **lebih kecil** daripada `arr[i]` itu sendiri, itu artinya **akumulasi masa lalu sudah menjadi beban (bernilai negatif bersih)**.
    
- Begitu ia menjadi beban, `std::max` akan menolak untuk menambahkannya dan memilih `arr[i]` (memulai subarray baru di indeks tersebut).
    

### Ringkasan Konseptual

Algoritma ini tidak menyimpan "dendam" pada nilai negatif yang besar. Jika angka negatif tersebut membuat total akumulasi menjadi lebih buruk daripada sekadar memulai dari angka berikutnya, algoritma akan **meninggalkan semua sejarah tersebut** dan _restart_ dari posisi saat itu juga.

Itulah alasan kenapa Kadane tidak akan pernah "terjebak" oleh angka negatif yang besar. Angka negatif tersebut akan "dibuang" oleh `std::max` tepat pada saat ia membuat total keseluruhan menjadi lebih kecil daripada nilai elemen tunggal itu sendiri.