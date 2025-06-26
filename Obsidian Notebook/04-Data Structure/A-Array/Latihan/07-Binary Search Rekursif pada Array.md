---
obsidianUIMode: preview
note_type: latihan
latihan: Binary Search Rekursif pada Array
sumber: Google.com, AI
tags:
  - data-structure
  - array
date_learned: 2025-06-13T21:42:00
---
---
# Binary Search Rekursif pada Array
## Soal 7: Binary Search Rekursif pada `std::array`

Buat dua fungsi template:

#### Wrapper

```cpp
template <size_t N>
int binarySearch(const std::array<int, N>& arr, int x);
```

- Menerima array terurut (`asc`) dan target `x`, lalu memanggil fungsi rekursif.

#### Fungsi Rekursif
    
```cpp
template <size_t N>
int binarySearch(
	const std::array<int, N>& arr,
	int low,
	int high,
	int x
);
```

- Jika `low > high`, kembalikan `-1`.  
- Hitung `mid = low + (high - low) / 2`.  
- Jika `arr[mid] == x`, kembalikan `mid`.  
- Jika `arr[mid] < x`, cari di subarray kanan (`low = mid+1`).  
- Jika `arr[mid] > x`, cari di subarray kiri (`high = mid-1`).

Di `main()`:

```cpp
std::array<int, 8> data = {1,2,3,4,5,6,7,8};
int target1 = 5;
int target2 = 10;
std::cout << "Index of " << target1 << " = " << binarySearch(data, target1) << "\n";
std::cout << "Index of " << target2 << " = " << binarySearch(data, target2) << "\n";
```

**Output yang diharapkan:**

```
Index of 5 = 4
Index of 10 = -1
```

---

Kirimkan **kode C++ lengkap** (dengan semua `#include` dan `using namespace std;` jika mau), aku akan koreksi dan—jika sudah benar—beri editorial tuntas! 🚀

## Jawabanku
Kode program untuk jawabanku:

```cpp
#include<iostream>
#include<array>
using namespace std;

template <size_t N>
int binarySearch(const array<int, N> & data,
    int low,
    int high,
    int target){

        while(low<=high){
            int mid = (low+high)/2;
            if(data[mid]==target) return mid;
            else if (data[mid]<target) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }

int main() {
    array<int, 8> data = {1,2,3,4,5,6,7,8};
    int target1 = 5;
    int target2 = 10;

    cout << "Index of: " << target1 << " = " << binarySearch(data, 0, 7, target1) << "\n";
    cout << "Index of: " << target2 << " = " << binarySearch(data, 0, 7, target2) << "\n";
    return 0;
}
```

## Editorial
Masih belum sesuai soal, karena:

1. **Belum ada wrapper** `binarySearch(const array<int,N>&, int x)`.
    
2. Yang kamu tulis adalah versi **iteratif**, bukan **rekursif** seperti diminta.
    

Berikut versi lengkap **rekursif** dengan wrapper:

```cpp
#include <iostream>
#include <array>
using namespace std;

// 1) Wrapper: cukup terima array dan target, panggil fungsi rekursif
template <size_t N>
int binarySearch(const array<int, N>& arr, int x) {
    return binarySearch(arr, 0, N - 1, x);
}

// 2) Fungsi rekursif: cari di arr[low..high]
template <size_t N>
int binarySearch(const array<int, N>& arr, int low, int high, int x) {
    if (low > high) 
        return -1;

    int mid = low + (high - low) / 2;
    if (arr[mid] == x) 
        return mid;
    else if (arr[mid] < x) 
        return binarySearch(arr, mid + 1, high, x);
    else 
        return binarySearch(arr, low, mid - 1, x);
}

int main() {
    array<int, 8> data = {1,2,3,4,5,6,7,8};
    int target1 = 5;
    int target2 = 10;

    cout << "Index of " << target1 
         << " = " << binarySearch(data, target1) << "\n";
    cout << "Index of " << target2 
         << " = " << binarySearch(data, target2) << "\n";
    return 0;
}
```

---

### Editorial

1. **Wrapper**
    
    ```cpp
    template <size_t N>
    int binarySearch(const array<int, N>& arr, int x) {
        return binarySearch(arr, 0, N - 1, x);
    }
    ```
    
    - Menyembunyikan parameter `low`/`high` dari pengguna.
        
2. **Fungsi Rekursif**
    
    ```cpp
    template <size_t N>
    int binarySearch(const array<int, N>& arr, int low, int high, int x) {
        if (low > high) return -1;
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x)
            return binarySearch(arr, mid + 1, high, x);
        else
            return binarySearch(arr, low, mid - 1, x);
    }
    ```
    
    - Basis: `low > high` → elemen tidak ada.
        
    - Rekurensi ke setengah yang lebih kecil/lebih besar.
        
3. **Complexity**
    
    - Waktu: O(log N).
        
    - Ruang: O(log N) karena depth rekursi.
        
4. **Output yang Diharapkan**
    
    ```
    Index of 5  = 4
    Index of 10 = -1
    ```
    

Sekarang sudah sesuai soal: ada wrapper, fungsi rekursif, dan hanya menggunakan `std::array`. 🚀