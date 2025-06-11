---
obsidianUIMode: preview
note_type: latihan
latihan: Membalik STL array In-Place
sumber: Google.com, AI
tags:
  - data-structure
  - array
---
---
# Membalik STL array In-Place
## Soal 1: Membalik `std::array` In-Place

Buat sebuah fungsi:

```cpp
void reverseArray(std::array<int, 7>& arr);
```

yang **membalik urutan elemen** dalam `arr`, **tanpa** membuat array tambahan (lakukan in-place swap).

Di `main()`, deklarasikan:

```cpp
std::array<int, 7> data = {1, 2, 3, 4, 5, 6, 7};
```

Panggil `reverseArray(data);` lalu cetak seluruh elemen `data` ke `std::cout` dengan spasi, sehingga outputnya menjadi:

```
7 6 5 4 3 2 1
```

### Ketentuan

- **WAJIB** menggunakan `std::array<int, 7>`.
    
- Fungsi `reverseArray` harus menerima argumen sebagai reference (`&`) agar memodifikasi langsung array di `main`.
    
- Jangan gunakan container atau array tambahan—cukup swap elemen di tempat.
    

**Kirimkan kode C++ lengkap** (termasuk `#include <array>`, `#include <iostream>`, definisi fungsi, dan `main()`). Setelah itu aku akan koreksi dan jika benar, berikan editorial lengkap! 😊

## Jawaban
Berikut kode program jawabanku:

```cpp
#include<iostream>
#include<array>
using namespace std;

void reverseArray(array<int, 7>& arr) {
    for(int i=0; i<arr.size()/2; i++){
        swap(arr.at(i), arr.at(arr.size()-i-1));
    }
}

int main() {
    array<int, 7> data = {1,2,3,4,5,6,7};
    reverseArray(data);

    for(const auto& x:data){
        cout << x << " ";
    }
    return 0;
}
```

## Editorial
✅ Kode kamu sudah **benar**! Berikut beberapa poin yang membuatnya tepat:

1. **Signature Fungsi**
    
    ```cpp
    void reverseArray(std::array<int, 7>& arr)
    ```
    
    - Menerima `std::array` sebagai reference, sehingga modifikasi “in-place” langsung terlihat di `main()`.
        
2. **Loop dan Swap**
    
    ```cpp
    for (int i = 0; i < arr.size()/2; ++i) {
        swap(arr.at(i), arr.at(arr.size() - i - 1));
    }
    ```
    
    - `arr.size()/2` memastikan kamu hanya mengiterasi setengah panjang array.
        
    - `swap(...)` dari `<utility>` menukar dua elemen dalam sekali panggil.
        
    - Memakai `.at()` memberi pengecekan batas—lebih aman daripada `operator[]`, meski sedikit lebih mahal performanya.
        
3. **Cetak Isi Array**
    
    ```cpp
    for (const auto& x : data) {
        cout << x << " ";
    }
    ```
    
    - Range-based for loop memudahkan iterasi tanpa indeks manual.
        
4. **Kompleksitas**
    
    - Waktu: O(n) karena satu loop sederhana.
        
    - Ruang: O(1) extra memory, karena semua penukaran bersifat in-place.
        

---

## Editorial Lengkap

```cpp
#include <iostream>
#include <array>
using namespace std;

// Fungsi membalik urutan elemen std::array ukuran 7, in-place
void reverseArray(array<int, 7>& arr) {
    // Cukup iterasi hingga setengah panjang agar setiap pasang elemen hanya ditukar sekali
    for (int i = 0; i < arr.size() / 2; ++i) {
        // arr.at() memeriksa batas, lalu swap menukar kedua elemen
        swap(arr.at(i), arr.at(arr.size() - i - 1));
    }
}

int main() {
    // Inisialisasi std::array dengan 7 elemen
    array<int, 7> data = {1, 2, 3, 4, 5, 6, 7};

    // Panggil fungsi reverse
    reverseArray(data);

    // Cetak hasil; output: 7 6 5 4 3 2 1
    for (const auto& x : data) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
```

### Penjelasan Baris-per-Baris

1. **Include & Namespace**
    
    - `<array>` untuk `std::array`
        
    - `<iostream>` untuk `std::cout`
        
    - `using namespace std;` (opsional, mempersingkat penulisan)
        
2. **Fungsi `reverseArray`**
    
    - **Parameter**: `array<int, 7>&` — reference ke array yang akan diubah.
        
    - **Logika**: Untuk setiap indeks `i` dari 0 sampai `size/2 - 1`, tukar elemen di `i` dengan elemen di `size-1-i`.
        
3. **`main()`**
    
    - Deklarasi dan inisialisasi array.
        
    - Memanggil `reverseArray` agar `data` terbalik.
        
    - Mencetak isi array dengan loop berbasis rentang.
        
4. **Keamanan & Pilihan API**
    
    - `.at()` vs `operator[]`:
        
        - `.at(i)` melempar `std::out_of_range` jika `i` di luar batas, mencegah UB.
            
        - `operator[]` lebih cepat, tapi tanpa pengecekan.
            
    - `std::swap` adalah cara idiomatis untuk menukar nilai.
        
5. **Alternatif**
    
    - Kamu bisa juga menggunakan algoritma STL:
        
        ```cpp
        #include <algorithm>
        reverse(data.begin(), data.end());
        ```
        
        Tapi menulis manual seperti ini memperkuat pemahaman “in-place algorithm”.
        

---

Selamat, kamu sudah mahir membalik `std::array` in-place! 🚀 Jika ingin latihan soal berikutnya atau ingin membahas implementasi lain (misal: rotate, shift, dsb.), bilang saja!