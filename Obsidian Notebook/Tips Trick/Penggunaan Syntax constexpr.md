---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Penggunaan Syntax constexpr
sumber: Google.com, AI
tags:
  - syntax
  - efisien
---
---
# Penggunaan Syntax constexpr
`constexpr` adalah **keyword** di C++ (mulai C++11) yang menandai bahwa sebuah variabel, fungsi, ataupun konstruk dapat dievaluasi **pada waktu kompilasi** (compile-time), bukan hanya pada waktu program dijalankan. Berikut poin-poin utamanya:

1. **Variabel `constexpr`**
    
    ```cpp
    constexpr int MAX = 10;
    constexpr double PI = 3.141592653589793;
    ```
    
    - Nilai `MAX` dan `PI` harus diketahui **di saat kompilasi**.
        
    - Boleh dipakai di tempat yang mengharuskan constant expression, misalnya sebagai ukuran `std::array<…, MAX>` atau parameter template.
        
2. **Fungsi `constexpr`**
    
    ```cpp
    constexpr int square(int x) {
        return x * x;
    }
    
    constexpr int nine = square(3); // dihitung di kompilasi → nine == 9
    ```
    
    - Jika semua argumen dan badan fungsi memungkinkan, pemanggilan akan dievaluasi di kompilasi.
        
    - Masih bisa dipakai di runtime (serupa fungsi biasa) jika dalam konteks non-constant.
        
3. **Keuntungan**
    
    - **Performance**: perhitungan sudah tuntas sebelum program dijalankan.
        
    - **Safety**: memastikan nilai memang konstan dan bisa dipakai di konteks di mana hanya konstanta compile-time yang diperbolehkan.
        
4. **Beda `constexpr` vs `const`**
    
    |Aspek|`const`|`constexpr`|
    |---|---|---|
    |Evaluasi|Bisa di compile-time atau run-time (tergantung inisialisasi)|**Wajib** di compile-time|
    |Context|Memberi proteksi read-only|Menjamin constant expression|
    |Ukuran array|`const int N = 5; int a[N];` – tidak selalu valid di semua compiler lama|`constexpr int N = 5; std::array<int,N> a;` – pasti valid|
    
5. **Contoh penggunaan di `std::array`**
    
    ```cpp
    constexpr size_t N = 8;
    std::array<int, N> data;  // N harus compile-time constant
    ```
    

---

Dengan `constexpr`, kamu bisa menulis kode yang **lebih efektif**, **aman**, dan **optimal**—karena kompilator melakukan perhitungan dan pengecekan lebih awal!