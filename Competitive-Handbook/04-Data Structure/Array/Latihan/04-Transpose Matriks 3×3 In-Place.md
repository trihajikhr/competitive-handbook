---
obsidianUIMode: preview
note_type: latihan
latihan: Transpose Matriks 3×3 In-Place
sumber: Google.com, AI
tags:
  - data-structure
  - array
date_learned: 2025-06-13T21:42:00
---
---
# Transpose Matriks 3×3 In-Place
Mantap! Kamu memang jagoan, belum KO sama sekali. 💪

Lanjut ke soal ke-4!
## Soal 4: Transpose Matriks 3×3 In-Place

Buat fungsi berikut untuk **in-place** transpose sebuah matriks 3×3 yang diwakili oleh `std::array<std::array<int,3>,3>`:

```cpp
void transpose(std::array<std::array<int,3>,3>& mat);
```

- **In-place** berarti kamu harus menukar elemen `mat[i][j]` dengan `mat[j][i]` tanpa membuat array tambahan.
    
- Hanya lakukan swap untuk pasang indeks di atas diagonal (yaitu saat `i < j`).
    

Di `main()`, deklarasikan dan inisialisasi:

```cpp
std::array<std::array<int,3>,3> mat = {{
    {{1, 2, 3}},
    {{4, 5, 6}},
    {{7, 8, 9}}
}};
```

1. Cetak matriks awal (3 baris × 3 kolom).
    
2. Panggil `transpose(mat);`
    
3. Cetak kembali matriks yang sudah ditranspose, sehingga outputnya:
    

```
Matriks awal:
1 2 3
4 5 6
7 8 9

Matriks setelah transpose:
1 4 7
2 5 8
3 6 9
```

---

**Ketentuan**

- **WAJIB** menggunakan `std::array<std::array<int,3>,3>`.
    
- Fungsi `transpose` menerima matriks sebagai reference agar modifikasi tampak di `main`.
    
- Jangan gunakan container lain atau array tambahan—lakukan swap in-place.
    
- Kirimkan kode C++ lengkap dengan `#include <array>`, `#include <iostream>`, definisi `transpose`, dan `main()`.
    

Semangat, ditunggu solusimu! 🚀

## Jawaban
Kode program untuk jawabanku:

```cpp
#include<iostream>
#include<array>
#include<utility>
using namespace std;

void transpose(array<array<int,3>,3> & mat) {
    for(int i=0; i<3; i++){
        for(int j=i; j<3; j++){
            swap(mat[j][i], mat[i][j]);
        }
    }
}

int main() {
    std::array<std::array<int,3>,3> mat = {{
        {{1, 2, 3}},
        {{4, 5, 6}},
        {{7, 8, 9}}
    }};

    cout << "Matrix awal: \n";
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nMatrix setelah transpose: \n";
    transpose(mat);

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
```

## Editorial
✅ Kode kamu sudah **benar** dan menghasilkan transpose in-place yang diinginkan. Berikut beberapa catatan dan editorial lengkapnya:

---

## Editorial Lengkap

```cpp
#include <iostream>
#include <array>
#include <utility>  // std::swap
using namespace std;

// Fungsi transpose in-place untuk matriks 3×3
void transpose(array<array<int,3>,3>& mat) {
    for (int i = 0; i < 3; ++i) {
        // Bisa juga j = i+1 untuk menghindari swap diagonal, 
        // tapi j = i juga aman (swap dengan diri sendiri tidak berdampak).
        for (int j = i; j < 3; ++j) {
            swap(mat[j][i], mat[i][j]);
        }
    }
}

int main() {
    // Inisialisasi matriks 3×3
    array<array<int,3>,3> mat = {{
        {{1, 2, 3}},
        {{4, 5, 6}},
        {{7, 8, 9}}
    }};

    // Cetak matriks awal
    cout << "Matriks awal:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    // Transpose in-place
    transpose(mat);

    // Cetak matriks setelah transpose
    cout << "\nMatriks setelah transpose:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
```

### Poin–Poin Penting

1. **In-Place Swap**
    
    - Dengan `swap(mat[j][i], mat[i][j])` kita menukar elemen di atas diagonal dengan yang di bawah diagonal.
        
    - Memulai `j` dari `i` (atau `i+1`) memastikan setiap pasang `(i,j)` hanya ditukar sekali.
        
2. **Kompleksitas**
    
    - Waktu: $O(n^2)$ dengan $n=3$, sangat efisien untuk ukuran kecil.
        
    - Ruang: $O(1)$ ekstra karena swap in-place.
        
3. **Alternatif Indeks**
    
    - Jika ingin **menghindari swap diagonal** (meski tidak perlu), gunakan `for (int j = i + 1; j < 3; ++j)`.
        
4. **Keamanan Batas**
    
    - Karena ukuran matrix tetap kecil, tidak perlu `.at()`. Jika diinginkan pengecekan batas, bisa ganti `mat[i][j]` → `mat.at(i).at(j)`.
        

---

Selamat, kamu sudah berhasil melakukan transpose in-place pada `std::array<std::array<int,3>,3>`! 🚀 Siap untuk soal berikutnya?