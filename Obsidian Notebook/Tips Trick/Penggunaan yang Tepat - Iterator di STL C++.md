---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Penggunaan yang Tepat - Iterator di STL C++
sumber: Google.com, AI
tags:
  - iterator
---
---
# Penggunaan yang Tepat - Iterator di STL C++

## 1. Apa Itu Iterator?

Iterator adalah objek yang berfungsi sebagai penunjuk ke elemen dalam container STL, seperti `vector`, `list`, `map`, dan `unordered_map`. Mereka memungkinkan kita untuk menelusuri (traverse) container tersebut tanpa mengetahui detail implementasinya. Dengan menggunakan iterator, kode kita menjadi lebih generik dan dapat bekerja pada berbagai jenis container.

Selain itu, iterator mendukung operasi dasar seperti dereference (`*it`) untuk mengakses nilai, increment (`++it`) untuk berpindah ke elemen berikutnya, dan comparison (`it != container.end()`) untuk memeriksa batas. Mirip pointer pada array C, iterator menawarkan abstraksi yang memudahkan manipulasi data di STL.

**Contoh Dasar pada `vector<int>`:**

```cpp
std::vector<int> v = {10, 20, 30};
for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << "Nilai: " << *it << '\n';
}
```

**Contoh pada `unordered_map<string,int>`:**

```cpp
std::unordered_map<std::string,int> m = {{"A",1}, {"B",2}};
for (auto it = m.begin(); it != m.end(); ++it) {
    std::cout << it->first << " => " << it->second << '\n';
}
```

## 2. Struktur Dasar Iterator

Semua container STL menyediakan operasi `.begin()` dan `.end()` yang mengembalikan iterator ke awal dan satu posisi setelah elemen terakhir. Hal ini memungkinkan loop seperti `for(it = begin; it != end; ++it)`. Iterator dari masing-masing container berbeda implementasinya, namun API-nya konsisten.

Iterator juga mendukung operator aritmatika pada beberapa container: Random Access Iterator (seperti pada `vector` dan `deque`) memungkinkan `it + n` atau `it - n`, sedangkan pada container lain (seperti `list`, `map`) kita terbatas pada `++it` dan `--it`.

**Contoh penggunaan `end()`:**

```cpp
std::list<char> letters = {'x','y','z'};
auto it = letters.begin();
while (it != letters.end()) {
    std::cout << *it << ' ';
    ++it;
}
```

**Contoh Random Access pada `vector`:**

```cpp
auto it = v.begin();
std::cout << *(it + 1) << '\n';  // mengakses elemen kedua
```

## 3. Kapan Boleh Tidak Menggunakan Iterator?

Jika tugas hanya membaca (read-only) elemen container dan tidak melakukan modifikasi struktur, iterasi menggunakan **range-based for** sangat direkomendasikan. Sintaks ini lebih ringkas dan meminimalkan kemungkinan kesalahan pada loop.

Begitu pula, fungsi standar seperti `std::for_each` atau algoritma STL dapat digunakan untuk operasi baca saja, tanpa perlu eksplisit menggunakan iterator.

**Range-based for pada `vector`:**

```cpp
for (const auto &x : v) {
    std::cout << x << ' ';
}
```

**std::for_each pada `array`:**

```cpp
int a[] = {1,2,3};
std::for_each(std::begin(a), std::end(a), [](int x){ std::cout << x << ' '; });
```

## 4. Kapan HARUS Menggunakan Iterator?

Saat kita perlu memodifikasi container—seperti menambah (`insert`) atau menghapus (`erase`) elemen—sambil menelusuri, iterator memberikan kontrol penuh atas posisi dan langkah selanjutnya. Modifikasi langsung pada container saat range-based loop dapat menyebabkan iterator tidak valid.

Iterator juga berguna bila kita butuh menyisipkan elemen pada posisi tertentu atau ingin melakukan traversing dua arah (misal pada `list`), yang tidak didukung dengan range-based syntax.

**Contoh menghapus elemen ganjil pada `vector`:**

```cpp
for (auto it = v.begin(); it != v.end(); ) {
    if (*it % 2 != 0)
        it = v.erase(it);
    else
        ++it;
}
```

**Contoh insert pada `list`:**

```cpp
std::list<int> l = {1,2,3};
auto it = l.begin();
++it;  // menunjuk ke elemen kedua
l.insert(it, 99);  // sisipkan sebelum elemen kedua
```

## 5. Container yang Tepat untuk Iterator

### Vector, Deque, dan List

`vector` dan `deque` mendukung Random Access Iterator, sehingga operasi akses acak dimungkinkan. `list` hanya mendukung Bidirectional Iterator namun efisien untuk insert/erase di tengah.

### Map, Set, Unordered Variants

Pada container associative seperti `map`, `set`, dan variannya, iterator penting untuk operasi hapus atau modifikasi elemen berdasarkan key. `unordered_map` dan `unordered_set` juga menyediakan iterator untuk traversing bucket.

|Container|Iterator Type|Operasi Kunci|
|---|---|---|
|`vector<T>`|Random Access Iterator|Erase/insert|
|`deque<T>`|Random Access Iterator|Erase/insert|
|`list<T>`|Bidirectional Iterator|Erase/insert middle|
|`map<K,V>`, `set<K>`|Bidirectional Iterator|Erase by iterator|
|`unordered_map<K,V>`, `unordered_set<K>`|Forward Iterator|Erase safe with iterator|

## 6. Contoh Lengkap: `unordered_map::erase()`

Berikut contoh lengkap menghapus semua entri dengan nilai di bawah threshold dari `unordered_map`:

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string,int> m = {{"A",10},{"B",5},{"C",12}};
    int threshold = 10;

    for (auto it = m.begin(); it != m.end(); ) {
        if (it->second < threshold)
            it = m.erase(it);  // erase mengembalikan iterator valid berikutnya
        else
            ++it;
    }

    for (const auto &p : m) {
        std::cout << p.first << ": " << p.second << '\n';
    }
    return 0;
}
```

## 7. Tips Praktis dan Best Practices

1. **Gunakan `auto`** untuk mendeklarasikan iterator, agar kode lebih ringkas.
    
2. **Range-based for** untuk kode baca-only; **iterator** untuk modifikasi.
    
3. **Cek validitas iterator** sebelum derefensi: selalu bandingkan dengan `.end()`.
    
4. **Hindari invalid iterator** dengan tidak menggunakan container setelah di-erase oleh key saat range-based loop.
    
5. **Pertimbangkan kompleksitas**: `erase(it)` pada `vector` O(n), tapi pada `list` O(1).
    

Dengan memahami kapan dan bagaimana menggunakan iterator, kamu akan menulis kode STL yang **efisien**, **aman**, dan **mudah dipelihara**.