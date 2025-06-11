---
obsidianUIMode: preview
note_type: latihan
latihan: Mencari Nilai Minimum dan Maksimum
sumber: Google.com, AI
tags:
  - data-structure
  - array
---
---

# Mencari Nilai Minimum dan Maksimum

## Soal 2: Mencari Nilai Minimum dan Maksimum

#### 1 | Bagian pertama
Buat dua fungsi berikut yang bekerja **in-place** pada sebuah `std::array<int, 8>`:

```cpp
std::pair<int,int> findMinMax(const std::array<int,8>& arr);
```

- Mengembalikan `{min, max}` dari `arr` tanpa menggunakan algoritma STL seperti  `std::min_element`/`std::max_element`.

#### 2 | Bagian kedua

```cpp
void normalize(std::array<int,8>& arr);
```

- Mengubah setiap elemen `arr[i]` menjadi `arr[i] - min`, lalu membagi dengan `(max - min)`, sehingga semua elemen ter-“skala” ke rentang `[0,1]`.

- Gunakan nilai `min` dan `max` hasil `findMinMax`.

---
#### 3 | Bagian ketiga

Di dalam `main()`, deklarasikan:

```cpp
std::array<int,8> data = { 10, 5, 20, 15, 0, 30, 25, 10 };
```

1. Panggil `findMinMax` untuk mendapatkan `min` dan `max`, cetak hasilnya:
    
    ```
    Min = 0, Max = 30
    ```
    
2. Panggil `normalize(data);` dan cetak semua elemen `data` ke `std::cout` dengan presisi dua angka desimal* , sehingga output kira-kira:
    
    ```
    0.33 0.17 0.67 0.50 0.00 1.00 0.83 0.33
    ```
    

> gunakan `std::fixed << std::setprecision(2)`

---

> **Catatan penting**:
> 
> - **WAJIB** menggunakan `std::array<int,8>`.
>     
> - Di `normalize` kamu memerlukan tipe floating (misalnya `double`) untuk pembagian, tapi tetap simpan hasilnya kembali ke array—jadi ubah array menjadi `std::array<double,8>` atau cast elemen ke `double` saat operasi.
>     
> - Jangan pakai container tambahan selain array itu sendiri.
>     

Kirimkan kode C++ lengkap (termasuk headers `<array>`, `<iostream>`, `<iomanip>`, dan definisi fungsi + `main`). Setelah aku terima, akan aku koreksi dan—jika benar—beri editorial lengkap. Semangat! 🚀

## Jawabanku
Kode program jawabanku:

```cpp
#include<iostream>
#include<iomanip>
#include<array>
#include<utility>
using namespace std;

pair<int,int> findMinMax(const array<int, 8> & data){
    int mins = data.at(0);
    int maks = data.at(0);

    for(size_t i=0; i<data.size(); i++){
        if(data[i]<mins) mins=data[i];
        if(data[i]>maks) maks=data[i];
    }

    return make_pair(mins,maks);
}

void normalize(array<int, 8> & data, int mins, int maks){

    array<float, 8> normalize;

    for(size_t i=0; i<data.size(); i++){
        normalize[i] = (static_cast<float>(data[i]) - mins) / (static_cast<float>(maks) - mins);
    }

    for(const auto& x : normalize){
        cout << fixed << setprecision(2) << x << " ";
    }

    cout << "\n";
}

int main() {
    array<int, 8> data = {10,5,20,15,0,30,25,10};
    pair<int,int> rest = findMinMax(data);

    // mencetak hasil mins dan maks
    cout << "Nilai minimal dari Data: " << rest.first << "\n";
    cout << "Nilai maksimal dari Data: " << rest.second << "\n";

    // normalize
    normalize(data, rest.first, rest.second);

    return 0;
}
```

## Editorial
Kode kamu sudah mendekati, tapi masih ada beberapa hal yang perlu dirapikan agar sesuai spesifikasi:

1. **Tipe array di- normalize** harus bertipe floating (misal `double`) sehingga hasil pemetaan ke 0,10,1 bisa disimpan.
    
2. **“In-place”** berarti fungsi `normalize` mengubah isi array yang sama, bukan mencetak hasil ke dalam fungsi terpisah.
    
3. Untuk keseragaman, kita ubah kedua fungsi agar bekerja pada `std::array<double,8>`.
    

Berikut versi lengkap yang memenuhi semua ketentuan:

```cpp
#include <array>
#include <iostream>
#include <iomanip>
#include <utility>  // for std::pair

// 1) Mencari min dan max (fungsi bekerja pada std::array<double,8>)
std::pair<double,double> findMinMax(const std::array<double,8>& arr) {
    double mn = arr[0], mx = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < mn) mn = arr[i];
        if (arr[i] > mx) mx = arr[i];
    }
    return {mn, mx};
}

// 2) Normalisasi in-place: tiap elemen diubah jadi (x - mn)/(mx - mn)
void normalize(std::array<double,8>& arr) {
    auto [mn, mx] = findMinMax(arr);
    double range = mx - mn;
    if (range == 0.0) return; // semua sama, biarkan saja
    
    for (size_t i = 0; i < arr.size(); ++i) {
        arr[i] = (arr[i] - mn) / range;
    }
}

int main() {
    // Ubah array jadi std::array<double,8> agar bisa menampung hasil normalisasi
    std::array<double,8> data = { 10, 5, 20, 15, 0, 30, 25, 10 };

    // 1) Cari min & max
    auto [mn, mx] = findMinMax(data);
    std::cout << "Min = " << static_cast<int>(mn)
              << ", Max = " << static_cast<int>(mx) << "\n";

    // 2) Normalisasi in-place
    normalize(data);

    // Cetak isi array dengan dua desimal
    std::cout << std::fixed << std::setprecision(2);
    for (double x : data) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

---

## Editorial Lengkap

1. **`findMinMax`**
    
    - **Parameter:** `const std::array<double,8>& arr`
        
    - Inisialisasi `mn` dan `mx` ke elemen pertama.
        
    - Iterasi dari indeks 1 sampai 7, perbarui `mn` dan `mx` sesuai kondisi.
        
    - Kembalikan `{mn, mx}` sebagai `std::pair<double,double>`.
        
2. **`normalize`**
    
    - **Parameter:** `std::array<double,8>& arr` agar modifikasi in-place.
        
    - Dapatkan `mn, mx` dari `findMinMax`.
        
    - Hitung `range = mx - mn`. Jika `range == 0`, berarti semua elemen sama; hentikan.
        
    - Untuk setiap elemen `arr[i]`, ubah ke (arr[i]−mn)/range(arr[i] - mn) / range.
        
3. **`main`**
    
    - Deklarasi `data` sebagai `std::array<double,8>` dengan nilai integer di-brace-init (di-convert otomatis ke `double`).
        
    - Panggil `findMinMax`, cetak hasil “Min = 0, Max = 30”.
        
    - Panggil `normalize(data)`.
        
    - Cetak `data` dengan `std::fixed` dan `std::setprecision(2)` untuk menampilkan dua angka di belakang koma.
        
4. **Output yang Diharapkan**
    
    ```
    Min = 0, Max = 30
    0.33 0.17 0.67 0.50 0.00 1.00 0.83 0.33
    ```
    

Dengan revisi ini, semua ketentuan—tipe array STL, in-place, tanpa wadah tambahan, dan cetak dengan presisi—sudah terpenuhi. Semoga membantu! 🚀