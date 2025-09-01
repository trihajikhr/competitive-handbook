---
obsidianUIMode: preview
note_type: latihan
latihan: Hapus Elemen Genap dan Rampingkan Kapasitas
sumber: Google.com, AI
tags:
  - data-structure
  - vector
date_learned: 2025-06-14T21:45:00
---
---
# Hapus Elemen Genap dan Rampingkan Kapasitas
## Soal 7: Hapus Elemen Genap dan Rampingkan Kapasitas

Buat program C++ yang:

1. Baca sebuah bilangan bulat `N` (1 ≤ N ≤ 1 000 000).
    
2. Baca `N` bilangan bulat dan simpan di `vector<int> arr`.
    
3. Hapus **semua** elemen genap dari `arr` dengan **algoritma STL** (bukan loop manual).
    
4. Setelah penghapusan, panggil `arr.shrink_to_fit()` agar kapasitas `vector` mengecil sesuai ukurannya.
    
5. Cetak:
    
    - Baris pertama: ukuran akhir `arr` (0 jika kosong).
        
    - Baris kedua: semua nilai di `arr`, dipisahkan spasi (atau nothing jika kosong).
        

### Contoh

```
Input:
10
3 4 5 6 7 8 9 10 11 12

Output:
5
3 5 7 9 11
```

### Petunjuk

- Gunakan `<algorithm>`:
    
    ```cpp
    arr.erase(
        remove_if(arr.begin(), arr.end(),
                  [](int v){ return v % 2 == 0; }),
        arr.end()
    );
    ```
    
- Kemudian:
    
    ```cpp
    arr.shrink_to_fit();
    ```
    
- Terakhir, cetak `arr.size()` dan isi `arr`.
    

---

Coba implementasikan dan kirim kode kamu, aku akan cek—lalu kita lanjut ke **Soal 8**! 😊

## Jawabanku
Berikut adalah jawaban yang diharapkan dari soal:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(auto&x:arr) cin >> x;

    arr.erase(
        remove_if(arr.begin(), arr.end(),
            [](int v){ return v % 2 == 0;}), 
        arr.end()
    );

    arr.shrink_to_fit();
    for(const auto&x:arr) cout << x << " ";

    return 0;
}
```

Kode program jika aku menggunakan metode konvensional:
```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(auto&x:arr) cin >> x;

    int idx=0;
    for(int i=0; i<n; i++){
        if(arr[i]%2==1) arr[idx++] = arr[i];
    }

    arr.resize(idx);
    for(const auto&x :arr) cout << x << " ";

    return 0;
}
```

## Editorial
> Editorial jawaban versi pertama:

Bagus! Kode-mu sudah **benar** dan berhasil menyelesaikan Soal 7 dengan:

✅ Menghapus semua elemen genap menggunakan `remove_if + erase`.  
✅ Menggunakan `shrink_to_fit()` untuk mengecilkan kapasitas vector.  
✅ Output akhir sudah sesuai—**tapi kamu lupa satu hal kecil**: mencetak ukuran vector di baris pertama.

---

### ✅ Perbaikan kecil:

Tambahkan baris ini **sebelum loop cetak:**

```cpp
cout << arr.size() << "\n";
```

Jadi blok akhir kodenya menjadi:

```cpp
arr.shrink_to_fit();
cout << arr.size() << "\n";
for(const auto&x : arr) cout << x << " ";
cout << "\n";
```

---

### ✨ Penjelasan Fungsi yang Kamu Gunakan

- `remove_if(...)`:  
    Memindahkan elemen yang tidak perlu ke akhir vector (tanpa menghapusnya).
    
- `vector::erase(...)`:  
    Digunakan untuk benar-benar menghapus sisa elemen di akhir hasil `remove_if`.
    
- `shrink_to_fit()`:  
    Menyusutkan kapasitas vector agar pas dengan ukurannya saat ini. Berguna untuk menghemat memori jika vector sudah menyusut jauh.
    
