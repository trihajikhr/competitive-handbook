---
obsidianUIMode: preview
note_type: book theory
judul_materi: Pengambilan Element Multiset
sumber:
  - myself
date_learned: 2026-07-27T21:47:00
tags:
  - data-structures
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Pengambilan Element Multiset

Pengambilan data atau *access* pada *multiset* memiliki karakteristik yang unik dibandingkan wadah sekuensial seperti *vector*. Karena elemen di dalam *multiset* diatur secara terurut dan tidak memiliki indeks numerik langsung (seperti `arr[i]`), pengambilan data dilakukan melalui *iterator*, pencarian nilai, atau fungsi rentang khusus.

Berikut adalah berbagai cara melakukan pengambilan data pada *multiset* beserta contoh kodenya dalam C++.

## Pengambilan Data Menggunakan *Iterator*

Kita dapat mengakses elemen satu per satu secara berurutan menggunakan *range-based for loop* atau menggunakan *iterator* secara manual dari `begin()` hingga `end()`.

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> angka = {40, 10, 20, 10, 30};

    // Mengambil dan mencetak seluruh data secara terurut
    std::cout << "Elemen dalam multiset: ";
    for (auto it = angka.begin(); it != angka.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;
}
```

## Pencarian Nilai Menggunakan `find()`

Fungsi `find(val)` digunakan untuk mencari keberadaan suatu nilai. Fungsi ini mengembalikan sebuah *iterator* yang menunjuk ke elemen pertama yang ditemukan. Jika nilai tersebut tidak ada di dalam *multiset*, fungsi akan mengembalikan *iterator* `end()`.

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> angka = {10, 20, 10, 30, 20};

    auto it = angka.find(20);
    if (it != angka.end()) {
        std::cout << "Nilai " << *it << " ditemukan dalam multiset.\n";
    } else {
        std::cout << "Nilai tidak ditemukan.\n";
    }

    return 0;
}
```

## Menghitung Kemunculan Elemen Menggunakan `count()`

Karena *multiset* mengizinkan adanya duplikat, fungsi `count(val)` sangat berguna untuk mengetahui berapa kali suatu nilai tertentu muncul di dalam wadah.

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> angka = {10, 20, 10, 30, 10};

    // Menghitung jumlah kemunculan nilai 10
    int jumlah = angka.count(10);
    std::cout << "Nilai 10 muncul sebanyak " << jumlah << " kali.\n";

    return 0;
}
```

## Pencarian Batas Menggunakan `lower_bound()` dan `upper_bound()`

Untuk rentang elemen duplikat, kita sering memerlukan `lower_bound` (mengembalikan *iterator* ke elemen pertama yang nilainya tidak kurang dari target) dan `upper_bound` (mengembalikan *iterator* ke elemen pertama yang nilainya lebih besar dari target).

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> angka = {10, 20, 20, 20, 30};

    auto lb = angka.lower_bound(20);
    auto ub = angka.upper_bound(20);

    std::cout << "Elemen dengan nilai 20 berada di antara iterator tersebut.\n";
    std::cout << "Jumlah elemen 20 dapat dihitung dari jarak iterator: " 
              << std::distance(lb, ub) << "\n";

    return 0;
}
```

## Mengambil Rentang Sekaligus Menggunakan `equal_range()`

Fungsi `equal_range(val)` mengembalikan sebuah `std::pair` yang berisi `lower_bound` dan `upper_bound` sekaligus untuk suatu nilai. Cara ini sangat efektif untuk mengambil seluruh kemunculan elemen duplikat dalam satu langkah.

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> angka = {5, 10, 10, 10, 15, 20};

    // Mengambil rentang untuk nilai 10
    auto rentang = angka.equal_range(10);

    std::cout << "Semua kemunculan nilai 10:\n";
    for (auto it = rentang.first; it != rentang.second; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;
}
```

## Pemanfaatan *Reverse Iterator* untuk Pengambilan Data Terbalik

Karena *multiset* diurutkan secara menaik secara *default*, kita dapat mengambil atau melintasi elemen dari yang terbesar ke yang terkecil menggunakan *reverse_iterator* melalui fungsi `rbegin()` dan `rend()`.

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> angka = {10, 20, 30, 40, 50};

    std::cout << "Elemen dari besar ke kecil: ";
    for (auto it = angka.rbegin(); it != angka.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;

```

## Pengecekan Keberadaan Menggunakan `contains()` (C++20 ke atas)

Mulai standar C++20, wadah asosiatif menyediakan fungsi `contains(val)` yang mengembalikan nilai *boolean* (`true` jika nilai ditemukan, `false` jika tidak). Fungsi ini jauh lebih ringkas dibandingkan harus membandingkan hasil `find()` dengan `end()`.

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> angka = {10, 20, 30};

    if (angka.contains(20)) {
        std::cout << "Nilai 20 ada di dalam multiset.\n";
    }

    return 0;
}
```

