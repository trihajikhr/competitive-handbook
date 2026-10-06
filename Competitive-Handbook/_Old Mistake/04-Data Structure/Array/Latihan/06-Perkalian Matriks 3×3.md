---
obsidianUIMode: preview
note_type: latihan
latihan: Perkalian Matriks 3×3
sumber: Google.com, AI
tags:
  - data-structure
  - array
date_learned: 2025-06-13T21:42:00
---
---
# Perkalian Matriks 3×3
## Soal 6: Perkalian Matriks 3×3

Buat fungsi berikut:

```cpp
std::array<std::array<int,3>,3>
multiply(const std::array<std::array<int,3>,3>& A,
         const std::array<std::array<int,3>,3>& B);
```

- Fungsi `multiply` menerima dua matriks `A` dan `B` (masing-masing 3×3) sebagai **const reference**.
    
- Kembalikan matriks hasil perkalian `C = A × B`, di mana
    
    ```
    C[i][j] = ∑_{k=0..2} A[i][k] * B[k][j]
    ```
    
    untuk setiap i, j = 0,1,2.
    
- **WAJIB** hanya menggunakan `std::array<std::array<int,3>,3>`—tidak boleh container lain.
    

Di `main()`, deklarasikan dan inisialisasi dua matriks:

```cpp
std::array<std::array<int,3>,3> A = {{
    {{1, 2, 3}},
    {{4, 5, 6}},
    {{7, 8, 9}}
}};
std::array<std::array<int,3>,3> B = {{
    {{9, 8, 7}},
    {{6, 5, 4}},
    {{3, 2, 1}}
}};
```

Panggil `multiply(A, B);` lalu cetak semua elemen matriks hasil dalam format 3 baris × 3 kolom.

**Output yang diharapkan**:

```
Hasil A × B:
30 24 18
84 69 54
138 114 90
```

---

### Ketentuan

1. **WAJIB** menggunakan `std::array<std::array<int,3>,3>`.
    
2. Fungsi `multiply` mengembalikan matriks baru, tidak mengubah `A` atau `B`.
    
3. Gunakan **tiga** loop bersarang: untuk `i` (0..2), `j` (0..2), dan `k` (0..2).
    
4. Kirimkan kode C++ lengkap dengan `#include <array>`, `#include <iostream>`, definisi fungsi `multiply`, dan `main()`.
    

Ayo kerjakan! Setelah kamu kirimkan, aku akan koreksi dan—jika benar—beri editorial lengkap. Semangat! 🚀

## Jawabanku
Kode program untuk jawabanku:

```cpp
#include<iostream>
#include<array>
using namespace std;

array<array<int,3>,3> multiply (
    const array<array<int,3>,3> & A,
    const array<array<int,3>,3> & B){
        
        array<array<int,3>,3> C;

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                int sum=0;
                for(int k=0; k<3; k++){
                    sum += A[i][k] * B[k][j];
                }
                C[i][j]=sum;
            }
        }
        return C;
}

int main() {
    array<array<int,3>,3> A = {{
        {{1,2,3}},
        {{4,5,6}},
        {{7,8,9}}
    }};

    array<array<int,3>,3> B = {{
        {{9,8,7}},
        {{6,5,4}},
        {{3,2,1}}
    }};

    array<array<int,3>,3> rest;
    rest = multiply(A,B);

    cout << "Hasil A x B:\n";
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << rest[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
```

## Editorial
✅ Kode kamu sudah **benar** dan sesuai spesifikasi! Berikut editorial lengkapnya:

```cpp
#include <iostream>
#include <array>
using namespace std;

// Fungsi perkalian matriks 3×3 menggunakan std::array
array<array<int,3>,3> multiply(
    const array<array<int,3>,3>& A,
    const array<array<int,3>,3>& B
) {
    array<array<int,3>,3> C;    // Matriks hasil

    // Hitung C = A × B
    for (int i = 0; i < 3; ++i) {          // baris A
        for (int j = 0; j < 3; ++j) {      // kolom B
            int sum = 0;
            for (int k = 0; k < 3; ++k) {  // over k
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }

    return C;
}

int main() {
    array<array<int,3>,3> A = {{
        {{1, 2, 3}},
        {{4, 5, 6}},
        {{7, 8, 9}}
    }};
    array<array<int,3>,3> B = {{
        {{9, 8, 7}},
        {{6, 5, 4}},
        {{3, 2, 1}}
    }};

    auto C = multiply(A, B);

    cout << "Hasil A × B:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
```

### Penjelasan:

1. **Signature**
    
    ```cpp
    array<array<int,3>,3> multiply(
        const array<array<int,3>,3>& A,
        const array<array<int,3>,3>& B
    );
    ```
    
    - Menerima dua matriks konstan sebagai reference agar tak tercopy ke fungsi.
        
2. **Inisialisasi Matriks Hasil**
    
    ```cpp
    array<array<int,3>,3> C;
    ```
    
    - Menyiapkan matriks 3×3 untuk menampung hasil.
        
3. **Tiga Loop Bersarang**
    
    - `i` iterasi baris A (0..2)
        
    - `j` iterasi kolom B (0..2)
        
    - `k` iterasi index kolom A / baris B (0..2)  
        Menghitung `sum += A[i][k] * B[k][j]`.
        
4. **Penempatan Hasil**
    
    ```cpp
    C[i][j] = sum;
    ```
    
    Setelah loop `k` selesai, `sum` adalah elemen `(i,j)` dari hasil perkalian.
    
5. **Cetak Hasil**
    
    - Loop `i` dan `j` 0..2, mencetak `C[i][j]` dengan spasi.
        
6. **Complexity**
    
    - Waktu: O(n³) untuk n=3 → konstan, tetapi pola ini berlaku umum untuk matriks n×n.
        
    - Ruang: O(n²) untuk matriks hasil.
        

---

Kerja bagus—kamu masih tetap semangat dan belum KO! 🚀 Siap untuk tantangan selanjutnya?