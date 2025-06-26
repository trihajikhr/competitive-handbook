---
obsidianUIMode: preview
note_type: latihan
latihan: Sliding Window Maximum
sumber: Google.com, AI
tags:
  - data-structure
  - array
date_learned: 2025-06-14T21:44:00
---
---
# Sliding Window Maximum
## 13. Sliding Window Maximum

**Deskripsi**  
Diberikan `std::array<int, N>` dan ukuran jendela konstan `K`, buat fungsi template

```cpp
template <size_t N, size_t K>
std::array<int, N - K + 1> slidingMax(const std::array<int, N>& arr);
```

yang mengembalikan array berisi maksimum pada setiap subarray (window) berukuran `K` yang bergeser dari kiri ke kanan.

**Contoh Input**

```cpp
constexpr size_t N = 8;
constexpr size_t K = 3;
std::array<int, N> arr = {1, 3, -1, -3, 5, 3, 6, 7};
```

**Contoh Output**

```
3 3 5 5 6 7
```

---

Silakan kerjakan ini dulu. Kirim kode C++ lengkap (fungsi + `main()` dengan `std::cout`) saat sudah selesai, nanti aku koreksi dan beri editorial! 🚀

## Jawabanku

```cpp
#include <iostream>
#include <array>
using namespace std;

template <size_t N, size_t K>
array<int, N - K + 1> slidingMax(const array<int, N>& arr) {
    array<int, N - K + 1> out{};
    for (size_t i = 0; i + K <= N; ++i) {
        int mx = arr[i];
        for (size_t j = i + 1; j < i + K; ++j) {
            if (arr[j] > mx) mx = arr[j];
        }
        out[i] = mx;
    }
    return out;
}

int main() {
    constexpr size_t N = 8;
    constexpr size_t K = 3;
    array<int, N> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    auto res = slidingMax<N, K>(arr);

    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n"; 
    return 0;
}

```

## Editorial
Berikut editorial lengkap untuk implementasi **Sliding Window Maximum** murni menggunakan `std::array` dan loop:

---

## Editorial: Sliding Window Maximum (Brute-Force O(N·K))

```cpp
#include <iostream>
#include <array>
using namespace std;

template <size_t N, size_t K>
array<int, N - K + 1> slidingMax(const array<int, N>& arr) {
    array<int, N - K + 1> out{};               // 1) Siapkan array hasil
    for (size_t i = 0; i + K <= N; ++i) {      // 2) Geser window start di 0..N-K
        int mx = arr[i];                       //    Inisialisasi mx dengan elemen pertama window
        for (size_t j = i + 1; j < i + K; ++j) // 3) Loop dalam: cari max di window [i..i+K-1]
            if (arr[j] > mx) 
                mx = arr[j];
        out[i] = mx;                           // 4) Simpan mx ke posisi i di out
    }
    return out;                                // 5) Kembalikan hasil
}

int main() {
    constexpr size_t N = 8, K = 3;
    array<int, N> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    auto res = slidingMax<N, K>(arr);

    for (int x : res) cout << x << " ";
    cout << "\n"; // Output: 3 3 5 5 6 7
    return 0;
}
```

---

### 1. Signature & STL Array

- Fungsi **templated** dengan parameter `N` (panjang array) dan `K` (ukuran window) pada **compile time**.
    
- Menggunakan `std::array<int, N>` untuk input dan mengembalikan `std::array<int, N-K+1>` untuk output.
    
- Memastikan **type safety** dan **fixed-size** array, tanpa dynamic allocation.
    

---

### 2. Logika Brute-Force

1. **Persiapan Output**
    
    ```cpp
    array<int, N - K + 1> out{};
    ```
    
    Inisialisasi semua elemen `out` ke 0 (atau default).
    
2. **Loop Window**
    
    ```cpp
    for (size_t i = 0; i + K <= N; ++i)
    ```
    
    - `i` menandai posisi awal window.
        
    - Kondisi `i + K <= N` memastikan window tidak melampaui batas array.
        
3. **Cari Maksimum**
    
    ```cpp
    int mx = arr[i];
    for (size_t j = i + 1; j < i + K; ++j)
        if (arr[j] > mx) mx = arr[j];
    ```
    
    - Inisialisasi `mx` dengan elemen pertama window.
        
    - Iterasi sisa elemen agar `mx` menyimpan nilai maksimum dalam window.
        
4. **Simpan Hasil**
    
    ```cpp
    out[i] = mx;
    ```
    
    - Posisi ke-`i` pada `out` menyimpan maksimum window yang dimulai di `i`.
        
5. **Return**
    
    ```cpp
    return out;
    ```
    
    - Kembalikan array hasil setelah semua window diproses.
        

---

### 3. Kompleksitas

- **Time:**
    
    - Loop luar: O(N−K+1) ≈ O(N)
        
    - Loop dalam: O(K)
        
    - Total: **O(N·K)**
        
- **Space:**
    
    - O(N−K+1) untuk array `out`.
        
    - O(1) extra (variabel skalar).
        

---

### 4. Kapan Pakai?

- Pendekatan ini **sederhana** dan mudah diimplementasikan.
    
- **Cukup cepat** untuk N, K kecil–sedang.
    
- Jika N dan K besar (misal 10⁵), gunakan **deque** atau **segment tree** untuk O(N).
    

---

### 5. Keunggulan `std::array`

- **Compile-time size:** ukuran array selalu diketahui, meningkatkan optimasi.
    
- **Exception safety** dan **type safety** dibanding C-style array.
    
- Integrasi mulus dengan STL (range-based for, algoritma, dsb).
    

---

Semoga membantu memahami setiap langkah dan trade-off dari pendekatan ini! 🚀