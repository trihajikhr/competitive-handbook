---
obsidianUIMode: preview
note_type: latihan
latihan: Rotasi Melingkar (Circular Rotation)
sumber: Google.com, AI
tags:
  - data-structure
  - array
date_learned: 2025-06-13T21:42:00
---
---

# Rotasi Melingkar (Circular Rotation)
## Soal 5: Rotasi Melingkar (Circular Rotation)

Buat fungsi berikut:

```cpp
template <size_t N>
void rotateRight(std::array<int, N>& arr, int k);
```

yang **melakukan rotasi ke kanan** sebanyak `k` langkah pada `arr` **in-place**, tanpa menggunakan array atau container tambahan (kecuali beberapa variabel bantu skalar). Elemen yang “keluar” di ujung kanan harus “masuk” kembali di ujung kiri.

Di `main()`, lakukan:

1. Deklarasi sebuah `std::array<int, 10> data = { 1,2,3,4,5,6,7,8,9,10 };`
    
2. Panggil `rotateRight(data, 3);`
    
3. Cetak isi `data` dengan range-based for, sehingga outputnya:
    
    ```
    8 9 10 1 2 3 4 5 6 7
    ```
    

### Ketentuan

- **WAJIB** menggunakan `std::array<int,10>` di `main`.
    
- `rotateRight` **harus** menerima `std::array<int,N>&` (template) dan `k` (bisa lebih besar dari `N`, artinya putaran penuh).
    
- **In-place**: tidak boleh membuat array bantu—gunakan algoritma reverse triple-step:
    
    1. Balik seluruh array.
        
    2. Balik sub-array [0..k-1].
        
    3. Balik sub-array [k..N-1].
        
- Kirimkan kode C++ lengkap: `#include <array>`, `<iostream>`, definisi template `rotateRight`, dan `main()`.
    

Tantang dirimu—kirim solusimu, nanti aku koreksi dan berikan editorial! 🚀

## Jawaban
Kode programku untuk menjawab soal:

```cpp
#include<iostream>
#include<array>
using namespace std;

template <size_t N>
void rotateRight(array<int, N>& arr, int k){
    int rightEdge;
    k%=10;
    if(k==0) return;
    while(k--){
        rightEdge=arr[N-1];

        for(int i=N-1; i>0; i--){
            arr[i]=arr[i-1];
        }
        arr[0]=rightEdge;
    }
}

int main() {
    array<int, 10> data = {1,2,3,4,5,6,7,8,9,10};
    rotateRight(data, 3);

    for(const auto& x: data){
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
```

## Editorial
Kode kamu **benar** dari segi keluaran—rotasi berjalan sesuai harapan—tetapi masih **belum sesuai ketentuan soal**:

1. **Harus in-place dengan algoritma reverse triple-step**, bukan rotasi satu-per-satu.
    
2. **Gunakan `k %= N;`**, bukan literal `10`.
    
3. **Kompleksitas** seharusnya **O(N)**, bukan $O(N·k)$.
    

---

## ✅ Versi Sesuai Soal (Reverse Triple-Step)

```cpp
#include <iostream>
#include <array>
#include <algorithm> // untuk std::reverse
using namespace std;

template <size_t N>
void rotateRight(array<int, N>& arr, int k) {
    // Normalisasi k
    k %= N;
    if (k < 0) k += N; 
    if (k == 0) return;

    // 1. Balik seluruh array
    reverse(arr.begin(), arr.end());
    // 2. Balik sub-array [0..k-1]
    reverse(arr.begin(), arr.begin() + k);
    // 3. Balik sub-array [k..N-1]
    reverse(arr.begin() + k, arr.end());
}

int main() {
    array<int, 10> data = {1,2,3,4,5,6,7,8,9,10};
    rotateRight(data, 3);

    for (int x : data) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
```

### Editorial Lengkap

1. **Normalisasi `k`**
    
    - `k %= N;` menjamin `0 ≤ k < N`.
        
    - Jika `k` negatif, `k += N` mengembalikannya ke rentang positif.
        
2. **Reverse Triple-Step**  
    Algoritma yang memutar array `arr` ke kanan `k` posisi dengan tiga kali operasi pembalikan (reverse), seluruhnya in-place:
    
    1. **Reverse seluruh array**
        
        - Contoh: `{1 2 3 4 5 6 7 8 9 10}` → `{10 9 8 7 6 5 4 3 2 1}`
            
    2. **Reverse prefix sepanjang `k`**
        
        - Prefix `k=3` dari hasil di atas: `{10 9 8}` → dibalik → `{8 9 10}`
            
        - Array menjadi: `{8 9 10 7 6 5 4 3 2 1}`
            
    3. **Reverse suffix dari `k` sampai akhir**
        
        - Suffix `{7 6 5 4 3 2 1}` → dibalik → `{1 2 3 4 5 6 7}`
            
        - Hasil akhir: `{8 9 10 1 2 3 4 5 6 7}`
            
3. **Kompleksitas**
    
    - **Waktu:** $O(N)$ untuk tiga kali reverse (masing-masing $O(N)$).
        
    - **Ruang:** $O(1)$ tambahan—hanya variabel skalar `k`.
        
4. **Keuntungan**
    
    - Lebih efisien dibanding shift one-by-one ($O(N·k)$).
        
    - Elegan dan idiomatis memanfaatkan `std::reverse`.
        

---

Dengan ini, fungsi `rotateRight` sudah **in-place**, **$O(N)$**, dan **sesuai ketentuan** soal. 🚀