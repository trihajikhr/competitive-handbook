---
obsidianUIMode: preview
note_type: latihan
latihan: Gabungkan Elemen
sumber:
  - chatgpt.com
tags:
  - data-structure
  - tuple
date_learned: 2025-08-03T15:27:00
---
---
# 1 | Gabungkan Elemen

Diberikan dua tuple:

```cpp
auto t1 = std::make_tuple(1, 'A');
auto t2 = std::make_tuple(3.14, "hello");
```

Tugasmu:

1. Gabungkan `t1` dan `t2` menjadi satu tuple `t3`.
    
2. Cetak semua elemen `t3`.
    

<br/>

---
# 2 | Jawaban

Mudah menggunakan satu fungsi saja:

```cpp
#include <iostream>
#include <tuple>
using namespace std;

auto main() -> int {
   tuple<int, char> t1;
   tuple<double, string> t2;
   t1 = make_tuple(1, 'A');
   t2 = make_tuple(3.14, "hello");
   auto t3 = tuple_cat(t1, t2);

   cout << get<0>(t3) << "\n";
   cout << get<1>(t3) << "\n";
   cout << get<2>(t3) << "\n";
   cout << get<3>(t3) << "\n";
   return 0;
}
```

Versi menggunakan auto:

```cpp
#include <iostream>
#include <tuple>
using namespace std;

auto main() -> int {
   auto t1 = std::make_tuple(1, 'A');
   auto t2 = std::make_tuple(3.14, "hello");
   auto t3 = tuple_cat(t1, t2);

   cout << get<0>(t3) << "\n";
   cout << get<1>(t3) << "\n";
   cout << get<2>(t3) << "\n";
   cout << get<3>(t3) << "\n";
   return 0;
}
```

<br/>

---
# 3 | Editorial

Program ini mendemonstrasikan cara menggabungkan beberapa objek `std::tuple` menjadi satu tuple baru menggunakan fungsi `std::tuple_cat()`.

Fungsi `std::tuple_cat()` menerima satu atau lebih tuple sebagai argumen, dan menghasilkan sebuah tuple baru yang berisi semua elemen dari tuple-argumen tersebut, dalam urutan yang sama.

Pada contoh berikut:

```cpp
auto t1 = std::make_tuple(1, 'A');
auto t2 = std::make_tuple(3.14, "hello");
auto t3 = std::tuple_cat(t1, t2);
```

Tuple `t3` akan memiliki empat elemen:

- `int` dengan nilai `1`,
    
- `char` dengan nilai `'A'`,
    
- `double` dengan nilai `3.14`,
    
- `const char*` dengan nilai `"hello"`.
    

Hasil akhirnya dapat diakses menggunakan `std::get<index>(tuple)`, misalnya `get<2>(t3)` mengembalikan `3.14`.

Secara formal:

- `std::tuple_cat()` adalah _variadic template function_ yang menyatukan tuple secara **compile-time**.
- Tipe hasilnya ditentukan secara otomatis oleh compiler menggunakan _template argument deduction_.
- Fungsi ini juga dapat menerima lebih dari dua tuple, contohnya:
    
    ```cpp
    auto t4 = tuple_cat(t1, t2, make_tuple(true, 99));
    ```
    
    yang akan menghasilkan tuple dengan enam elemen.
    

```ad-info
`std::tuple_cat` berguna ketika kita ingin menggabungkan beberapa tuple tanpa harus menyalin elemennya satu per satu. Proses penggabungan dilakukan secara compile-time, dan hasilnya adalah tuple baru yang berisi semua elemen dari setiap tuple sumber, sesuai urutan kemunculannya.
```

### Apakah ada batas banyaknya parameter untuk fungsi `tuple_cat()`?

`std::tuple_cat()` adalah _variadic template function_, didefinisikan di header `<tuple>` sebagai:

```cpp
template <class... Tuples>
constexpr auto tuple_cat(Tuples&&... tpls);
```

Artinya:

- Ia bisa menerima jumlah parameter tuple yang tidak terbatas secara logika, karena menggunakan parameter pack `Tuples...`.
    
- Jadi secara teori, kamu bisa menulis:
    
    ```cpp
    tuple_cat(t1, t2, t3, t4, t5, ..., tN);
    ```
    
    selama kompilator dan memori template instantiation masih sanggup.
    

Tapi di dunia nyata (compiler nyata)... ada batasnya

C++ sendiri tidak menetapkan batas maksimum jumlah parameter template.  
Namun, compiler punya batas praktis, agar tidak meledak karena _template recursion depth_ atau _instantiation limit_.


| Compiler    | Batas Template Parameter Pack (perkiraan) | Catatan                                          |
| ----------- | ----------------------------------------- | ------------------------------------------------ |
| GCC / Clang | sekitar **1024** elemen                   | bisa diubah dengan flag `-ftemplate-depth=`      |
| MSVC        | sekitar **512** elemen                    | bisa diubah dengan `/constexpr:depth` atau `/Zm` |
| ICC / ICX   | mirip GCC                                 | tergantung backend LLVM                          |

Artinya:

> Secara _praktis_, kita bisa memanggil `std::tuple_cat()` dengan ratusan tuple tanpa masalah, tapi di atas 500–1000 elemen bisa gagal dikompilasi karena *template recursion depth exceeded*.


Selain jumlah _tuple parameter_, juga ada batas pada **banyaknya elemen dalam hasil tuple**.

Karena `tuple_cat()` membentuk tuple hasil dengan menggabungkan semua elemen dari setiap tuple argumen, maka:

```cpp
tuple_cat(t1, t2, t3);
```

akan menghasilkan `tuple` dengan `N₁ + N₂ + N₃` elemen.

Untuk `std::tuple`, batas elemen juga **tidak diatur dalam standar C++**, tapi lagi-lagi:

- Di GCC & Clang: bisa mencapai **sekitar 1024 elemen**.
    
- Di MSVC: biasanya **256–512 elemen** sebelum error `C1202: recursive type or function dependency context too complex`.


```ad-info
C++20 dan seterusnya mendukung _constexpr tuple concatenation_ dengan cara yang sama, jadi `tuple_cat` tetap aman digunakan bahkan dalam konteks compile-time, selama jumlah elemennya tidak melebihi batas template engine.
```

```ad-summary
`std::tuple_cat` tidak punya batas resmi dalam standar C++, tapi secara _praktis_, dibatasi oleh kemampuan compiler dalam menangani template parameter pack — biasanya sekitar 500–1000 tuple atau elemen.
```
