---
obsidianUIMode: preview
note_type: book theory
judul_materi: Insert Element Multiset
sumber:
  - myself
date_learned: 2026-07-27T21:41:00
tags:
  - data-structures
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Insert Element Multiset

*Insert* data adalah proses penambahan elemen ke dalam *multiset*. Karena *multiset* adalah wadah asosiatif berbasis *Balanced Binary Search Tree* (biasanya *Red-Black Tree*), setiap kali kita menyisipkan elemen baru, wadah akan secara otomatis menempatkan elemen tersebut pada posisi yang menjaga keterurutan data.

Berikut adalah berbagai cara melakukan *insert* data pada *multiset* beserta contoh kodenya dalam C++.

## Menggunakan Fungsi `insert()` dengan Nilai (*Value*)

Cara paling umum adalah melewatkan nilai secara langsung ke fungsi `insert()`. Fungsi ini akan menyalin atau memindahkan elemen ke dalam *multiset* dan mengembalikan sebuah *iterator* yang menunjuk ke posisi elemen yang baru saja dimasukkan.

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> angka;

    // Menyisipkan elemen satu per satu
    angka.insert(10);
    angka.insert(5);
    angka.insert(20);
    angka.insert(10); // Duplikat diizinkan dalam multiset

    std::cout << "Isi multiset setelah insert:\n";
    for (int x : angka) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
```

## Menggunakan Fungsi `emplace()`

Jika kita memasukkan objek yang kompleks, fungsi `emplace()` dapat digunakan untuk membangun elemen secara langsung di dalam wadah tanpa melalui proses penyalinan atau pemindahan salinan (*temporary copy*), sehingga berpotensi lebih efisien.

```cpp
#include <iostream>
#include <set>
#include <string>

struct Mahasiswa {
    std::string nama;
    int nilai;

    // Operator kurang dari wajib didefinisikan agar multiset tahu cara mengurutkannya
    bool operator<(const Mahasiswa& other) const {
        return nilai < other.nilai;
    }
};

int main() {
    std::multiset<Mahasiswa> mhs_set;

    // Membangun objek langsung di dalam multiset
    mhs_set.emplace("Budi", 85);
    mhs_set.emplace("Ani", 90);
    mhs_set.emplace("Citra", 85); // Nilai sama (duplikat) diizinkan

    std::cout << "Daftar Mahasiswa (terurut berdasarkan nilai):\n";
    for (const auto& m : mhs_set) {
        std::cout << m.nama << " dengan nilai " << m.nilai << "\n";
    }

    return 0;
}
```

## Menggunakan Fungsi `insert()` dengan *Hint Iterator*

Kita dapat memberikan petunjuk berupa posisi *iterator* kepada fungsi `insert()`. Petunjuk ini digunakan oleh wadah untuk memulai pencarian posisi penyisipan. Jika *hint* yang diberikan akurat (mendekati posisi asli elemen), kompleksitas waktu penyisipan dapat mendekati waktu konstan amortisasi $O(1)$.

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> angka = {10, 20, 30, 40};

    // hint menunjuk ke awal multiset
    auto it = angka.begin();

    // Menyisipkan dengan hint
    angka.insert(it, 15);

    std::cout << "Isi multiset setelah insert dengan hint:\n";
    for (int x : angka) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}

```

## Menyisipkan Sekumpulan Data dari *Range*

Kita dapat menyisipkan serangkaian elemen dari wadah lain (seperti *vector* atau *array*) sekaligus menggunakan *range insert*.

```cpp
#include <iostream>
#include <vector>
#include <set>

int main() {
    std::multiset<int> angka = {100, 200};
    std::vector<int> tambahan = {50, 150, 50, 250};

    // Menyisipkan seluruh elemen dari vector ke dalam multiset
    angka.insert(tambahan.begin(), tambahan.end());

    std::cout << "Isi multiset setelah range insert:\n";
    for (int x : angka) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
```

## Menggunakan Fungsi `emplace_hint()`

Fungsi ini merupakan gabungan antara efisiensi *emplace* (membangun objek secara langsung di dalam wadah tanpa penyalinan) dan kecepatan *hint* (memberikan petunjuk posisi *iterator* awal pencarian). Cara ini sangat berguna ketika kita memasukkan objek kompleks dengan posisi petunjuk yang akurat.

```cpp
#include <iostream>
#include <set>
#include <string>

struct Titik {
    int x, y;
    bool operator<(const Titik& other) const {
        return x < other.x;
    }
};

int main() {
    std::multiset<Titik> koordinat;
    
    // Menyisipkan elemen pertama sebagai acuan hint
    auto it = koordinat.emplace(1, 2);

    // Menggunakan emplace_hint dengan memanfaatkan iterator sebelumnya
    koordinat.emplace_hint(it, 3, 4);

    return 0;
}

```

