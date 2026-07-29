---
obsidianUIMode: preview
note_type: book theory
judul_materi: Menghapus Element Multiset
sumber:
  - myself
date_learned: 2026-07-27T22:09:00
tags:
  - data-structures
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Menghapus Element Multiset

Menghapus elemen dari *multiset* adalah operasi penting untuk mengelola memori dan menjaga akurasi data yang disimpan di dalam *balanced binary search tree*. Karena *multiset* mengizinkan adanya elemen duplikat, penghapusan dapat dilakukan berdasarkan nilai spesifik ataupun posisi *iterator*.

Berikut adalah berbagai cara melakukan penghapusan elemen pada *multiset* beserta contoh kodenya dalam C++.

## Menghapus Berdasarkan Nilai (*Value*)

Jika kita melewatkan sebuah nilai ke fungsi `erase()`, seluruh elemen yang memiliki nilai tersebut akan dihapus dari *multiset*. Fungsi ini juga mengembalikan jumlah total elemen yang berhasil dihapus.

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> angka = {10, 20, 10, 30, 10, 40};

    // Menghapus semua elemen dengan nilai 10
    size_t jumlah_dihapus = angka.erase(10);

    std::cout << "Jumlah elemen yang dihapus: " << jumlah_dihapus << "\n";
    std::cout << "Isi multiset setelah penghapusan:\n";
    for (int x : angka) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
```

## Menghapus Berdasarkan *Iterator* Tunggal

Jika kita hanya ingin menghapus satu instans elemen duplikat tertentu (bukan semuanya), kita harus mencari elemen tersebut menggunakan `find()` atau fungsi *lookup* lainnya untuk mendapatkan *iterator*, lalu melewatkan *iterator* tersebut ke fungsi `erase()`.

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> angka = {10, 20, 10, 30};

    // Mencari salah satu elemen 10
    auto it = angka.find(10);
    if (it != angka.end()) {
        // Hanya satu elemen duplikat yang akan dihapus
        angka.erase(it);
    }

    std::cout << "Isi multiset setelah penghapusan satu iterator:\n";
    for (int x : angka) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
```

## Menghapus Berdasarkan Rentang *Iterator* (*Range Erase*)

Kita dapat menghapus sekumpulan elemen sekaligus dengan menentukan batas awal dan batas akhir berupa rentang *iterator* (*range*), misalnya menggunakan hasil dari `lower_bound` dan `upper_bound`.

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> angka = {10, 20, 20, 20, 30, 40};

    auto lb = angka.lower_bound(20);
    auto ub = angka.upper_bound(20);

    // Menghapus semua elemen pada rentang nilai 20
    angka.erase(lb, ub);

    std::cout << "Isi multiset setelah menghapus rentang 20:\n";
    for (int x : angka) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}

```

## Menghapus Seluruh Elemen Menggunakan `clear()`

Jika kita ingin mengosongkan seluruh isi *multiset* seketika tanpa harus menghapusnya satu per satu, fungsi `clear()` dapat digunakan. Operasi ini akan membuat ukuran wadah menjadi nol.

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> angka = {10, 20, 30};

    angka.clear();

    std::cout << "Ukuran multiset setelah clear: " << angka.size() << "\n";

    return 0;
}
```

## Menghapus Satu Instans Berdasarkan Nilai (*Single Element by Value*)

Di dalam C++, fungsi `erase()` dengan parameter *value* akan menghapus *seluruh* elemen duplikat yang memiliki nilai tersebut. Jika kita ingin menghapus *hanya satu* instans elemen dengan nilai tertentu tanpa harus memanggil *find* secara manual untuk mengambil *iterator*-nya, kita bisa memanfaatkan fungsi `lower_bound()` yang dikombinasikan langsung dengan `erase()`.

Teknik ini sangat berguna dalam pemrograman kompetitif ketika kita menyimpan banyak elemen duplikat dan hanya ingin membuang satu buah elemen saja berdasarkan nilainya.

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> angka = {10, 10, 10, 20, 30};

    // Mencari posisi elemen pertama yang bernilai 10 lalu menghapusnya sekali saja
    auto it = angka.lower_bound(10);
    if (it != angka.end() && *it == 10) {
        angka.erase(it); // Hanya menghapus satu instans elemen 10
    }

    std::cout << "Isi multiset setelah menghapus satu instans nilai 10:\n";
    for (int x : angka) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
```