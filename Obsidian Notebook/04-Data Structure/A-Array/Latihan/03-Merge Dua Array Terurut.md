---
obsidianUIMode: preview
note_type: latihan
latihan: Merge Dua Array Terurut
sumber: Google.com, AI
tags:
  - data-structure
  - array
date_learned: 2025-06-13T21:42:00
---
---
# Merge Dua Array Terurut
## Soal 3: Merge Dua Array Terurut

Buat sebuah fungsi:

```cpp
std::array<int, 10> mergeArrays(
    const std::array<int,5>& a,
    const std::array<int,5>& b
);
```

yang **menggabungkan** dua buah `std::array<int,5>` terurut menaik (`a` dan `b`) menjadi satu `std::array<int,10>` terurut menaik, tanpa menggunakan container selain `std::array`.

**Panduan:**

1. Gunakan dua indeks (`i` untuk `a`, `j` untuk `b`) dan satu indeks (`k`) untuk array hasil.
    
2. Selama `i < 5` dan `j < 5`, bandingkan `a[i]` dan `b[j]` lalu sisipkan yang lebih kecil ke `result[k++]`.
    
3. Setelah salah satu habis, salin sisa elemen dari array yang belum habis.
    
4. Kembalikan `result`.
    

Di `main()`, deklarasikan:

```cpp
std::array<int,5> a = {1, 3, 5, 7, 9};
std::array<int,5> b = {2, 4, 6, 8, 10};
```

Panggil `mergeArrays(a, b)` lalu cetak semua elemen array hasil ke `std::cout` (range-based for) dengan spasi:

```
1 2 3 4 5 6 7 8 9 10
```

---

**Ketentuan:**

- **WAJIB** menggunakan hanya `std::array`.
    
- Fungsi harus menerima `const std::array<int,5>&` dan mengembalikan `std::array<int,10>`.
    
- Jangan pakai `std::vector`, `std::list`, atau container lain.
    
- Kirimkan kode C++ lengkap dengan `#include <array>`, `#include <iostream>`, definisi fungsi `mergeArrays`, dan `main()`.
    

Setelah kamu kirim, aku akan koreksi dan—jika benar—beri editorial lengkap! Selamat mencoba! 😊

## Jawabanku
Kode program dari jawabanku:

```cpp
#include<iostream>
#include<array>
using namespace std;

array<int, 10> mergeArrays(
    const array<int, 5> & a,
    const array<int, 5> & b){
        
        array<int, 10> result;
        int i=0, j=0, k=0;

        while(i<5 && j<5){
            result[k++] = (a[i] < b[j] ? a[i++] : b[j++]);    
        }

        while(i<5) result[k++] = a[i++];
        while(j<5) result[k++] = b[j++];
        return result;
}

int main() {
    array<int, 5> a = {1,3,5,7,9};
    array<int, 5> b = {2,4,6,8,10};

    array<int, 10> data;
    data = mergeArrays(a,b);

    for(const auto & x: data){
        cout << x << " ";
    }
    return 0;
}
```

## Editorial
✅ Kode kamu sudah **benar** dan menjalankan merge dua `std::array<int,5>` terurut menjadi satu `std::array<int,10>` terurut. Berikut poin-poin kunci dan editorial lengkapnya:

---

## Editorial Lengkap

```cpp
#include <iostream>
#include <array>
using namespace std;

// Menggabungkan dua array terurut ukuran 5 menjadi satu array terurut ukuran 10
array<int, 10> mergeArrays(
    const array<int, 5>& a,
    const array<int, 5>& b
) {
    array<int, 10> result;
    int i = 0, j = 0, k = 0;

    // Selama kedua array masih punya elemen tersisa, ambil yang lebih kecil
    while (i < 5 && j < 5) {
        if (a[i] < b[j]) {
            result[k++] = a[i++];
        } else {
            result[k++] = b[j++];
        }
    }

    // Salin sisa elemen dari a (jika ada)
    while (i < 5) {
        result[k++] = a[i++];
    }
    // Salin sisa elemen dari b (jika ada)
    while (j < 5) {
        result[k++] = b[j++];
    }

    return result;
}

int main() {
    array<int, 5> a = {1, 3, 5, 7, 9};
    array<int, 5> b = {2, 4, 6, 8, 10};

    // Panggil mergeArrays dan cetak hasilnya
    array<int, 10> data = mergeArrays(a, b);
    for (int x : data) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
```

### Penjelasan Baris-per-Baris

1. **Signature Fungsi**
    
    - `const array<int,5>& a`, `const array<int,5>& b`  
        Menerima dua referensi ke array terurut, tanpa mengubah aslinya.
        
2. **Array Hasil**
    
    - `array<int,10> result;`  
        Menyiapkan wadah berukuran tepat untuk menampung gabungan.
        
3. **Tiga Indeks**
    
    - `i` untuk melacak posisi di `a`
        
    - `j` untuk melacak posisi di `b`
        
    - `k` untuk posisi berikutnya di `result`
        
4. **Loop Utama**
    
    ```cpp
    while (i < 5 && j < 5) {
        if (a[i] < b[j]) result[k++] = a[i++];
        else             result[k++] = b[j++];
    }
    ```
    
    Bandingkan elemen saat ini dan masukkan yang lebih kecil, lalu majukan indeks yang bersangkutan.
    
5. **Menyalin Sisa**  
    Setelah salah satu array habis, salin elemen yang masih tersisa dari array lainnya:
    
    ```cpp
    while (i < 5) result[k++] = a[i++];
    while (j < 5) result[k++] = b[j++];
    ```
    
6. **Complexity**
    
    - Waktu: O(n + m) — di sini n = m = 5, jadi O(10).
        
    - Ruang: O(n + m) untuk `result`.
        
7. **Alternatif STL**  
    Untuk referensi, STL menyediakan:
    
    ```cpp
    array<int,10> result;
    merge(a.begin(), a.end(), b.begin(), b.end(), result.begin());
    ```
    
    di `<algorithm>`, tetapi implementasi manual memperkuat pemahaman pola two-pointer merge.
    

---

Selamat—kamu sudah sukses menggabungkan dua `std::array` terurut! Siap lanjut ke soal ke-4? 🚀