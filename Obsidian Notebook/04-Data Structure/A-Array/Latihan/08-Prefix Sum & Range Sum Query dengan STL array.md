---
obsidianUIMode: preview
note_type: latihan
latihan: Prefix Sum & Range Sum Query dengan STL array
sumber: Google.com, AI
tags:
  - data-structure
  - array
date_learned: 2025-06-13T21:42:00
---
---
# Prefix Sum & Range Sum Query dengan STL array
## Soal 8: Prefix Sum & Range Sum Query dengan `std::array`

Buat dua fungsi template:

#### Membangun Prefix Sum

```cpp
template <size_t N>
std::array<int, N> buildPrefix(const std::array<int, N>& arr);
```

- Mengembalikan `pref` di mana
	
	```
	pref[0] = arr[0];
	pref[i] = arr[0] + arr[1] + … + arr[i]    (1 ≤ i < N)
	```

#### Query Jumlah Rentang
    
```cpp
template <size_t N>
int rangeSum(const std::array<int, N>& pref, int L, int R);
```

- Mengembalikan jumlah
	
	```
	arr[L] + arr[L+1] + … + arr[R]
	```
	
	dengan bantuan `pref`. Asumsikan `0 ≤ L ≤ R < N`.
	
#### Fungsi main()
Di `main()`, deklarasikan:

```cpp
std::array<int, 10> data = {5, 1, 3, 7, 2, 6, 4, 8, 0, 9};
```

1. Panggil `buildPrefix(data)` → dapatkan `pref`.
    
2. Cetak `pref` (range-based for).
    
3. Lakukan tiga query `rangeSum(pref, L, R)` dengan:
    
    - L=0, R=3
        
    - L=2, R=5
        
    - L=4, R=9  
        dan cetak hasilnya dengan format:
        
    
    ```
    Sum[0..3] = 16
    Sum[2..5] = 18
    Sum[4..9] = 29
    ```
    

---

**Ketentuan:**

- **WAJIB** menggunakan `std::array<int,10>`.
    
- Fungsi–fungsi hanya boleh menggunakan `std::array`, **tanpa** container lain.
    
- Komputasi `rangeSum` harus O(1) per query, memanfaatkan `pref`.
    
- Kirimkan kode C++ lengkap (`#include <array>`, `<iostream>`, definisi template, dan `main()`).
    

Semangat! Setelah kamu kirim, aku akan koreksi dan—jika benar—beri editorial tuntas! 🚀

## Jawabanku
Berikut kode programku:

```cpp
#include<iostream>
#include<array>
using namespace std;

template <size_t N>
array<int, N> buildPrefiq(const array<int, N> & arr){
    array<int, N> rest;
    
    int sum=0;
    for(size_t i=0; i<N; i++){
        sum+=arr[i];
        rest[i]=sum;
    }

    return rest;
}

template<size_t N>
int rangeSum(const array<int, N>& pref, int L, int R){
    cout << "Sum[" << L << ".." << R << "] = ";
    if (L==0) return pref[R];
    else return pref[R]-pref[L-1];
}

int main() {
    array<int, 10> data = {5,1,3,7,2,6,4,8,0,9};
    array<int, 10> pref;

    pref = buildPrefiq(data);
    cout << "Prefiq Sum dari Array Data: \n";
    for(const auto&x: pref){
        cout << x << " ";
    }

    cout << "\n";
    int rest;
    rest = rangeSum(pref, 0, 3);
    cout << rest << "\n";

    rest = rangeSum(pref, 2, 5);
    cout << rest << "\n";
    
    rest = rangeSum(pref, 4, 9);
    cout << rest << "\n";
    return 0;
}
```

## Editorial
Berikut **perbaikan** kode-mu agar sesuai spesifikasi:

```cpp
#include <iostream>
#include <array>
using namespace std;

// 1) Membangun prefix sum
template <size_t N>
array<int, N> buildPrefix(const array<int, N>& arr) {
    array<int, N> pref;
    int sum = 0;
    for (size_t i = 0; i < N; ++i) {
        sum += arr[i];
        pref[i] = sum;
    }
    return pref;
}

// 2) Query range sum O(1)
template <size_t N>
int rangeSum(const array<int, N>& pref, int L, int R) {
    if (L == 0) 
        return pref[R];
    else 
        return pref[R] - pref[L - 1];
}

int main() {
    array<int, 10> data = {5,1,3,7,2,6,4,8,0,9};

    // Bangun prefix sum
    auto pref = buildPrefix(data);

    // Cetak prefix sum
    cout << "Prefix Sum:\n";
    for (int x : pref) {
        cout << x << " ";
    }
    cout << "\n\n";

    // Lakukan dan cetak tiga query
    struct Query { int L, R; };
    array<Query, 3> queries = {{{0,3}, {2,5}, {4,9}}};

    for (auto [L,R] : queries) {
        int ans = rangeSum(pref, L, R);
        cout << "Sum[" << L << ".." << R << "] = " << ans << "\n";
    }

    return 0;
}
```

---

### Editorial Lengkap

1. **`buildPrefix`**
    
    - **Parameter:** `const array<int,N>& arr`
        
    - **Proses:** Iterasi dari `i=0` hingga `N-1`, akumulasi `sum += arr[i]`, lalu `pref[i] = sum`.
        
    - **Output:** `array<int,N> pref` berisi prefix sums.
        
2. **`rangeSum`**
    
    - **Parameter:** `const array<int,N>& pref`, `int L`, `int R`
        
    - **Logika:**
        
        - Jika `L == 0`, jumlah rentang `[0..R]` sama dengan `pref[R]`.
            
        - Jika `L > 0`, jumlah `[L..R] = pref[R] - pref[L-1]`.
            
    - **Kompleksitas:** O(1) per query.
        
3. **`main()`**
    
    - Bangun `pref` dari `data`.
        
    - Cetak `pref` dengan loop.
        
    - Siapkan tiga query `(L,R)` dalam array kecil.
        
    - Loop untuk setiap query, panggil `rangeSum`, dan cetak hasil sesuai format.
        
4. **Output yang Diharapkan**
    
    ```
    Prefix Sum:
    5 6 9 16 18 24 28 36 36 45
    
    Sum[0..3] = 16
    Sum[2..5] = 18
    Sum[4..9] = 29
    ```
    

Dengan ini fungsi dan output sudah sesuai soal—prefix sum dibangun benar, dan setiap query dihitung dalam O(1). 🚀