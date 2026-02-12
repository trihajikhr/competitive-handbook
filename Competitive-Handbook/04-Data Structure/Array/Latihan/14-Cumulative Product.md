---
obsidianUIMode: preview
note_type: latihan
latihan: Cumulative Product
sumber: Google.com, AI
tags:
  - data-structure
  - array
---
---
# Cumulative Product
## 14. Cumulative Product

**Deskripsi:**  
Diberikan sebuah `std::array<int, N>`, buat fungsi template

```cpp
template <size_t N>
std::array<long long, N> cumulativeProd(const std::array<int, N>& arr);
```

yang mengembalikan array output `out` di mana:

```
out[i] = arr[0] * arr[1] * ... * arr[i]   // untuk 0 <= i < N
```

Gunakan `long long` untuk menampung hasil perkalian agar mengurangi risiko overflow pada N cukup besar.

**Contoh Input:**

```cpp
constexpr size_t N = 5;
std::array<int, N> arr = {2, 3, 4, 5, 6};
```

**Contoh Output:**

```
2 6 24 120 720
```

## Jawabanku
```cpp
#include<iostream>
#include<array>
using namespace std;

template <size_t N>
array<long long, N> cumulativeProd(const array<int, N>&arr){
    array<long long, N> out {};
    
    long long prod=1;
    for(size_t i=0; i<N; i++){
        prod*=arr.at(i);
        out.at(i)=prod;
    }

    return out;
}

int main() {
    constexpr size_t N = 5;
    array<int, N> arr = {2,3,4,5,6};
    array<long long, N> rest;

    rest = cumulativeProd(arr);
    for(const auto&x:rest){
        cout << x << " ";
    }

    cout << "\n";
    return 0;
}
```

## Editorial


```cpp
#include <iostream>
#include <array>
using namespace std;

template <size_t N>
array<long long, N> cumulativeProd(const array<int, N>& arr) {
    array<long long, N> out{};          // 1) Siapkan array hasil

    long long prod = 1;                // 2) Gunakan long long untuk akumulasi
    for (size_t i = 0; i < N; ++i) {
        prod *= arr[i];                // 3) Kalikan arr[i]
        out[i] = prod;                 // 4) Simpan ke out[i]
    }

    return out;                        // 5) Kembalikan hasil
}

int main() {
    constexpr size_t N = 5;
    array<int, N> arr = {2, 3, 4, 5, 6};

    // Compiler dapat mendeteksi N secara otomatis
    auto res = cumulativeProd(arr);

    // Cetak hasil: 2 6 24 120 720
    for (long long x : res) 
        cout << x << " ";
    cout << "\n";
    return 0;
}
```

### Penjelasan

1. **Template & STL Array**
    
    - `std::array<int, N>` untuk input, `std::array<long long, N>` untuk output.
        
    - Ukuran diketahui di compile-time, tanpa dynamic allocation.
        
2. **Akumulasi Produk**
    
    - Variabel `prod` bertipe `long long` agar hasil perkalian besar tetap aman.
        
    - `out[i]` menyimpan produk hingga elemen ke-`i`.
        
3. **Kompleksitas**
    
    - Waktu: O(N) satu pass.
        
    - Ruang: O(N) untuk `out`, O(1) tambahan.
        
4. **Catatan**
    
    - Menggunakan `arr[i]` lebih ringkas dan cukup aman dalam loop kendali.
        
    - `out{}` memastikan semua elemen diinisialisasi, meski akan ditimpa di loop.
        

Dengan perbaikan ini, fungsi **cumulativeProd** siap dipakai sebagai komponen andalan di catatan Obsidian-mu! 🚀