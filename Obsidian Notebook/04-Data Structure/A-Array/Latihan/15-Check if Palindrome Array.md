---
obsidianUIMode: preview
note_type: latihan
latihan: Check if Palindrome Array
sumber: Google.com, AI
tags:
  - data-structure
  - array
date_learned: 2025-06-13T14:49:00
---
---
# Check if Palindrome Array
## 15. Check if Palindrome Array

**Deskripsi:**  
Buat fungsi template:

```cpp
template <size_t N>
bool isPalindrome(const std::array<int, N>& arr);
```

yang mengembalikan `true` jika array `arr` bersifat palindrome, yaitu `arr[i] == arr[N-1-i]` untuk semua `0 <= i < N/2`, dan `false` sebaliknya.

**Contoh Input dan Output:**

1. **Input:**
    

```cpp
std::array<int, 5> arr1 = {1, 2, 3, 2, 1};
```

**Output:**

```
true
```

2. **Input:**
    

```cpp
std::array<int, 6> arr2 = {1, 2, 3, 4, 2, 1};
```

**Output:**

```
false
```

## Jawabanku
Berikut adalah kode program dari kasus ini:

```cpp
#include<iostream>
#include<array>
using namespace std;

template <size_t N>
bool isPalindrome(const array<int, N> & arr){
    for(size_t i=0; i<N/2; i++){
        if(arr[i] != arr[N-i-1]){
            return false;
        }
    }
    return true;
}

int main() {
    array<int,5> arr1 = {1,2,3,2,1};
    array<int,10> arr2 = {1,2,3,4,2,1,6,5,4,3};

    cout << "Array 1 adalah: " << (isPalindrome(arr1)? "true" : "false") << "\n";
    cout << "Array 1 adalah: " << (isPalindrome(arr2)? "true" : "false") << "\n";
    return 0;
}
```

## Editorial
✅ Kode kamu sudah **benar** dan sangat ringkas! Berikut editorial lengkapnya:

---

## Editorial: Check if Palindrome Array

```cpp
template <size_t N>
bool isPalindrome(const array<int, N>& arr) {
    // Cukup periksa hingga setengah panjang array
    for (size_t i = 0; i < N/2; ++i) {
        if (arr[i] != arr[N - 1 - i]) {
            return false;   // Jika ada pasangan yang berbeda → bukan palindrome
        }
    }
    return true;            // Semua pasangan cocok → palindrome
}
```

### Penjelasan Baris-per-Baris

1. **Template & Parameter**
    
    - `N` dikenal di compile-time, array size tetap.
        
    - Fungsi menerima `const array<int, N>&` agar tidak menyalin dan mencegah modifikasi.
        
2. **Loop Pemeriksaan**
    
    ```cpp
    for (size_t i = 0; i < N/2; ++i)
    ```
    
    - Cukup memeriksa `i` dari `0` sampai `N/2 - 1`.
        
    - Pasangan yang dibandingkan: `arr[i]` dengan `arr[N-1-i]`.
        
3. **Deteksi Ketidakcocokan**
    
    ```cpp
    if (arr[i] != arr[N - 1 - i])
        return false;
    ```
    
    - Begitu ditemukan perbedaan, langsung kembalikan `false`.
        
4. **Simpulkan Palindrome**  
    Bila loop selesai tanpa menemukan perbedaan, pengembalian `true` menandakan array bersifat palindrome.
    

---

### Kompleksitas

- **Time:** O(N/2) ≈ O(N)
    
- **Space:** O(1) extra (hanya variabel skalar)
    

---

### Contoh Output Program

```cpp
array<int,5> arr1 = {1,2,3,2,1};
array<int,10> arr2 = {1,2,3,4,2,1,6,5,4,3};

cout << isPalindrome(arr1); // true
cout << isPalindrome(arr2); // false
```

---

Pendekatan ini memanfaatkan kekuatan **`std::array`** dan pemeriksaan indeksi—sederhana, aman (tidak ada out-of-bounds), dan efisien. Selamat! 🚀