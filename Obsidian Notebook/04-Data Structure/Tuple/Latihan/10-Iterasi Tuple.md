---
obsidianUIMode: preview
note_type: latihan
latihan: Iterasi Tuple
sumber:
  - chatgpt.com
tags:
  - data-structure
  - tuple
date_learned: 2025-08-03T16:22:00
---
---
# Iterasi Tuple

Tugas:

1. Buat tuple:
    
    ```cpp
    auto t = std::make_tuple(10, 20.5f, 'Z');
    ```
    
2. Cetak semua elemen menggunakan **template rekursif** atau `constexpr if`.
    

Contoh hasil:

```
10
20.5
Z
```


<br/>

---
# Jawaban

```cpp
#include <iostream>
#include <tuple>
using namespace std;

#define get(i, a) get<i>(a)

template <typename T, size_t I = 0>
void printTuple(const T& tup) {
   if constexpr (I < tuple_size<T>::value) {
      cout << get<I>(tup) << '\n';
      printTuple<T, I + 1>(tup);
   }
}

auto main() -> int {
   auto tup = make_tuple(10, 20.5f, 'Z');
   printTuple(tup);
}
```

<br/>

---
# Editorial

Baik, berikut **editorial khusus** untuk blok kode berikut:

```cpp
template <typename T, size_t I = 0>
void printTuple(const T& tup) {
   if constexpr (I < tuple_size<T>::value) {
      cout << get<I>(tup) << '\n';
      printTuple<tup, I + 1>(tup);
   }
}
```

---

## Penjelasan Per Baris

### `template <typename T, size_t I = 0>`

- Ini adalah **template fungsi rekursif**.
    
- `T` adalah tipe tuple (misalnya `tuple<int, float, char>`).
    
- `I` adalah **indeks saat ini**, default dimulai dari `0`.
    

### `void printTuple(const T& tup)`

- Fungsi menerima **referensi const** ke sebuah tuple.
    
- Tujuannya: **mencetak semua elemen tuple satu per satu**.
    

### `if constexpr (I < tuple_size<T>::value)`

- `if constexpr` memastikan pengecekan terjadi **saat kompilasi**, bukan runtime.
    
- `tuple_size<T>::value` mengembalikan jumlah elemen tuple.
    
- Selama `I` masih dalam batas tuple, blok di dalam `if` akan dieksekusi.
    

### `cout << get<I>(tup) << '\n';`

- Mencetak elemen ke-`I` dari tuple menggunakan `std::get<I>(...)`.
    
- Karena `I` adalah **nilai konstan saat kompilasi**, ini valid secara sintaks dan efisien.



---

## ✅ Perbaikan Lengkap

```cpp
template <typename T, size_t I = 0>
void printTuple(const T& tup) {
   if constexpr (I < tuple_size<T>::value) {
      cout << get<I>(tup) << '\n';
      printTuple<T, I + 1>(tup); // ✅ Perbaikan di sini
   }
}
```
