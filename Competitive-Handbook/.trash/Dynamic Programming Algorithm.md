---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 07TH-DP00-0001
nama_algoritma: Dynamic Programming
kategori_algoritma: Dynamic Programming
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen & chatgpt.com"
date_learned: 2025-04-16T11:00:00
tags:
  - dynamic-programming
---
#dynamic-programming 

---
# Dynamic Programming Algorithm

**Dynamic Programming (DP)** adalah _paradigma pemrograman_ (cara berpikir) untuk menyelesaikan masalah **yang kompleks dengan memecahnya menjadi submasalah yang lebih sederhana**, lalu **menyimpan hasil submasalah tersebut** agar tidak dihitung ulang.

---

### ⚙️ Syarat Masalah Bisa Diselesaikan dengan DP:

1. **Overlapping Subproblems**  
    Submasalah yang sama muncul berkali-kali saat menyelesaikan masalah utama.  
    → Contoh: menghitung `fib(5)` butuh `fib(4)` dan `fib(3)`, sedangkan `fib(4)` juga butuh `fib(3)` dan `fib(2)` → `fib(3)` dihitung berulang kali.
    
2. **Optimal Substructure**  
    Solusi dari masalah utama bisa dibangun dari solusi optimal submasalahnya.  
    → Contoh: untuk tahu jumlah minimum koin untuk nilai `n`, kita bisa ambil solusi optimal untuk `n - coin[i]`.
    

---

### ✨ Teknik Utama dalam DP:

1. **Memoization (Top-Down)**
    
    - Menyimpan hasil dari fungsi rekursif agar tidak dihitung ulang.
        
    - Biasanya implementasi pakai rekursi + cache (array/map).
        
    - Cocok untuk kasus yang lebih alami ditulis secara rekursif.
        
2. **Tabulation (Bottom-Up)**
    
    - Mulai dari submasalah terkecil dan bangun solusi besar secara iteratif.
        
    - Pakai array atau tabel, tanpa rekursi.
        
    - Biasanya lebih efisien (tidak ada call stack overhead).
        

---

### 📦 Struktur Umum Penyelesaian DP:

1. **Definisikan state**  
    → Apa yang ingin kamu cari? Biasanya berupa `dp[i]`, `dp[i][j]`, dll.
    
2. **Tentukan base case**  
    → Misalnya, `dp[0] = 1`, atau `dp[i][0] = 0`.
    
3. **Tulis relasi rekursifnya**  
    → Contoh: `dp[i] = dp[i-1] + dp[i-2]`.
    
4. **Implementasikan dengan memoization atau tabulation**
    

## Algoritma Dynamic Programming

**Dynamic Programming (DP)** adalah sebuah *paradigma pemrograman* yang digunakan untuk menyelesaikan masalah kompleks dengan memecahnya menjadi submasalah yang lebih kecil dan menyimpan hasil dari submasalah tersebut agar tidak dihitung ulang.

### Ciri-ciri masalah yang cocok diselesaikan dengan DP:
1. **Overlapping Subproblems** – Submasalah yang sama muncul berulang kali.
2. **Optimal Substructure** – Solusi dari masalah utama bisa dibentuk dari solusi submasalah.

### Teknik Utama:
- **Memoization (Top-Down):** menggunakan rekursi + penyimpanan hasil di cache.
- **Tabulation (Bottom-Up):** menggunakan iterasi dari submasalah kecil ke besar.

# Contoh Algoritma Dynamic Programming
- Fibonacci Number
- 0/1 Knapsack Problem
- Longest Common Subsequence (LCS)
- Coin Change
- Edit Distance
- Matrix Chain Multiplication
- Longest Increasing Subsequence (LIS)

# Dynamic Programming Complexity
## Time Complexity
### Best Case (Kasus Terbaik) - 
Tergantung implementasi dan input; kadang bisa lebih cepat jika memoization hanya menghitung sebagian kecil submasalah.

### Average Case (Kasus Rata-rata) - 
Biasanya sesuai dengan jumlah total state DP yang dihitung.

### Worst Case (Kasus Terburuk) - 
Sering kali O(N²) atau lebih tergantung jumlah state dan transisi.

### Ringkasan
| Kasus        | Kompleksitas Waktu |
| ------------ | ------------------ |
| Best Case    | Tergantung kasus   |
| Average Case | Tergantung kasus   |
| Worst Case   | Tergantung kasus   |

## Space Complexity dan Stability
### Space Complexity
Biasanya O(N) hingga O(N²), tergantung jumlah state yang perlu disimpan.

### Stability
Tidak relevan dalam konteks DP karena bukan algoritma pengurutan. Tapi solusi DP bisa stabil dalam arti "konsisten" jika struktur DP benar.

## Kesimpulan
| Faktor Complexity | Nilai             |
| ----------------- | ---------------- |
| Best Case         | Kasus-spesifik   |
| Average Case      | Kasus-spesifik   |
| Worst Case        | Kasus-spesifik   |
| Space Complexity  | O(N)–O(N²)        |
| Stability         | Tidak berlaku    |

# Aplikasi Dynamic Programming

- Optimalisasi kombinatorial (Knapsack, Partition Problem)
- Pengolahan string (LCS, Edit Distance)
- Jalur minimum/maksimum (Grid DP, Matrix DP)
- Game theory (DP with memoization for winning states)
- Problem counting (jumlah cara melakukan sesuatu)

## Keunggulan dan kelemahan
### Keunggulan Dynamic Programming
- Efisien untuk masalah dengan submasalah berulang
- Solusi optimal karena semua kemungkinan dianalisis
- Cocok untuk berbagai domain (string, array, graf, dll.)

### Kelemahan Dynamic Programming
- Sulit diidentifikasi bagi pemula
- Konsumsi memori tinggi jika tidak dioptimasi
- Kadang sulit untuk dimodifikasi atau diparalelkan

## Kesimpulan
Dynamic Programming adalah pendekatan penting dalam pemrograman kompetitif dan algoritma karena memungkinkan penyelesaian masalah yang sebelumnya tidak efisien secara waktu atau tidak mungkin diselesaikan dalam waktu terbatas.
