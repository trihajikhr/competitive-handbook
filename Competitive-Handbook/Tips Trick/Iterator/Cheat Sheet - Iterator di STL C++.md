---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Cheat Sheet - Iterator di STL C++
sumber: Google.com, AI
tags:
  - iterator
---
---
# Cheat Sheet: Iterator di STL C++

## 1. Apa Itu Iterator?

- **Iterator** adalah objek yang **menunjuk** ke elemen dalam container STL (misalnya `vector`, `list`, `unordered_map`, dll).
    
- Mirip pointer, mendukung operasi:
    
    - **Dereference** (`*it`) untuk mengakses elemen.
        
    - **Increment** (`++it` atau `it++`) untuk maju ke elemen berikutnya.
        
- Menyediakan **abstraksi** agar kode dapat bekerja dengan berbagai jenis container.
    

## 2. Struktur Dasar Iterator

```cpp
// Contoh iterasi pada vector<int>
std::vector<int> v = {1,2,3};
for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << "\n";
}
```

- `begin()`: iterator ke elemen pertama.
    
- `end()`: iterator _one-past-the-end_.
    

## 3. Kapan Boleh Tidak Menggunakan Iterator?

- **Baca-only** (tidak memodifikasi container):
    
    - Range-based for cocok dan lebih ringkas.
        
    - `std::for_each` dengan lambda (jika tidak perlu modifikasi container).
        

```cpp
// Range-based for (baca-only)
for (auto &x : v) {
    std::cout << x << " ";
}
```

## 4. Kapan HARUS Menggunakan Iterator?

- **Modifikasi container** (hapus/insert) **sambil iterasi**.
    
- Container **associative** (`map`, `unordered_map`, `set`, `unordered_set`) jika perlu **erase**.
    
- Mengakses elemen dengan kontrol posisi dan aksi kompleks.
    

```cpp
// Menghapus elemen ganjil pada vector
for (auto it = v.begin(); it != v.end();) {
    if (*it % 2 != 0)
        it = v.erase(it);  // aman: erase mengembalikan iterator berikutnya
    else
        ++it;
}
```

## 5. Container yang Tepat untuk Iterator

|Container|Boleh Range-based?|Butuh Iterator?|
|---|---|---|
|`std::vector`|✅ Ya|✅ kalau erase/insert|
|`std::list`|✅ Ya|✅ untuk operasi middle|
|`std::deque`|✅ Ya|✅ untuk erase mid/front|
|`std::map`/`set`|✅ Ya (baca)|✅ untuk erase|
|`std::unordered_map`/`set`|✅ Ya (baca)|✅ untuk erase|

## 6. Contoh Lengkap: `unordered_map::erase()`

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string,int> m = {{"A",10},{"B",5},{"C",12}};
    int threshold = 10;

    // Hapus yang nilai < threshold
    for (auto it = m.begin(); it != m.end();) {
        if (it->second < threshold)
            it = m.erase(it);
        else
            ++it;
    }

    // Cetak hasil
    for (auto &p : m) {
        cout << p.first << ": " << p.second << "\n";
    }
}
```

## 7. Tips Praktis

- **Gunakan `auto it`** untuk tipe iterator agar lebih ringkas.
    
- **Prefer `const auto&`** jika tidak perlu memodifikasi elemen.
    
- **Cek `it != container.end()`** sebelum dereference.
    
- **Hati-hati `erase` di associative container**: gunakan iterator, bukan key, dalam loop.
    
- Rangkum pola common:
    
    - Hapus sambil iterasi: `it = c.erase(it);`
        
    - Lanjut tanpa hapus: `++it;`
        
_