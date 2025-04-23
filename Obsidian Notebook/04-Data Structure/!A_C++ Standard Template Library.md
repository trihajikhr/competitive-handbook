---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 04TH-DS00-0001
nama_algoritma: 
kategori_algoritma: data structure
kesulitan: 
time_complexity: 
memory_complexity: 
sumber: programiz.com
date_learned: 2025-04-22T17:11:00
tags:
  - array
  - data-structure
---
#array #data-structure 

---
# C++ Standard Template Library

Dalam C++, **Standard Template Library (STL)** menyediakan seperangkat alat pemrograman untuk mengimplementasikan algoritma dan struktur data seperti _vector_, _list_, _queue_, dan sebagainya.

STL mengimplementasikan struktur data dan algoritma ini menggunakan kelas dan fungsi tujuan umum yang telah diuji secara ketat.

**C++ STL memiliki 3 komponen utama:**

- **Container**
    
- **Iterator**
    
- **Algorithm**
    

Selain itu, STL juga menyediakan beberapa fitur lainnya, termasuk **function object**, **smart pointer**, dan **mekanisme penanganan exception**.

---

## C++ STL Containers

_Container_ dalam STL menyimpan data dan mengorganisasikannya dengan cara tertentu sesuai kebutuhan.

Sebagai contoh, _vector_ menyimpan data dengan tipe yang sama dalam urutan berurutan. Sedangkan _map_ menyimpan data dalam pasangan _key-value_.

Kita bisa mengklasifikasikan container STL menjadi 3 jenis:

#### 1. **Sequence containers**:

- `array`
    
- `vector`
    
- `queue`
    
- `deque`
    
- `forward_list`
    
- `list`
    

#### 2. **Associative containers**:

- `set`
    
- `multiset`
    
- `map`
    
- `multimap`
    

#### 3. **Unordered associative containers**:

- `unordered_set`
    
- `unordered_multiset`
    
- `unordered_map`
    
- `unordered_multimap`
    

> Untuk mempelajari lebih lanjut tentang _container_, kunjungi tutorial **C++ STL Containers**.

**Catatan:** _STL array_ berbeda dari array biasa yang selama ini kita gunakan. _STL array_ didefinisikan dalam kelas `std::array`, yang memiliki banyak fungsi dan algoritma berguna selain struktur data array itu sendiri. Fitur-fitur ini tidak tersedia dalam array biasa.

---

## Contoh 1: C++ STL Containers – Vector

Dalam C++, _vector_ seperti array yang dapat diubah ukurannya; mereka menyimpan data bertipe sama secara berurutan dan ukurannya bisa diubah saat _runtime_ sesuai kebutuhan.

Kita perlu mengimpor _header file_ `<vector>` untuk menggunakan _vector_.

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    // membuat vector bertipe int
    vector<int> numbers {1, 2, 3, 4, 5};

    // mencetak elemen vector menggunakan ranged loop
    for (int number : numbers) {
        cout << number << "  ";
    }
    
    return 0;
}
```

**Output:**

```
1  2  3  4  5
```

Di sini, kita membuat sebuah _vector_ bertipe `int` bernama `numbers` dengan 5 elemen.

Kemudian kita menggunakan _ranged for loop_ untuk mencetak semua elemen dari _vector_ tersebut.

> Untuk mempelajari lebih lanjut tentang _vector_ dalam C++, kunjungi tutorial **C++ Vectors**.

---

## C++ STL Iterators

_Iterator_ adalah objek yang digunakan untuk mengakses elemen dari sebuah _container_.

Kita dapat mendeklarasikan _iterator_ untuk setiap _container_ dalam STL C++. Contohnya:

```cpp
vector<int>::iterator it;
```

Kita sering menggunakan fungsi anggota _iterator_ seperti `begin()`, `end()`, dan lain-lain untuk mengembalikan _iterator_ yang menunjuk ke elemen dalam _container_. Contohnya:

```cpp
vector<int> numbers = {3, 2, 5, 1, 4};
vector<int>::iterator itr1 = numbers.begin();
vector<int>::iterator itr2 = numbers.end();
```

Penjelasan:

- `numbers.begin()` – mengembalikan _iterator_ yang menunjuk ke awal _vector_ `numbers`, yaitu elemen 3
    
- `numbers.end()` – mengembalikan _iterator_ yang menunjuk ke elemen _setelah_ elemen terakhir dalam _vector_ `numbers`
    

**Catatan:** `numbers.end()` **tidak** mengembalikan _iterator_ ke elemen terakhir (`4`), melainkan ke elemen teoritis setelah elemen terakhir. Hal ini berlaku untuk semua jenis _container_.

> Untuk mempelajari lebih lanjut tentang _iterator_ dalam STL, kunjungi tutorial **C++ STL Iterators**.

---

## Contoh 2: C++ STL Iterators

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    // inisialisasi vector bertipe int
    vector<int> numbers {1, 2, 3, 4, 5};

    // inisialisasi iterator vector untuk menunjuk ke elemen pertama
    vector<int>::iterator itr = numbers.begin();
    cout << "First Element: " << *itr << "  "<<endl;

    // mengubah iterator untuk menunjuk ke elemen terakhir
    itr = numbers.end() - 1;
    cout << "Last Element: " << *itr;

    return 0;  
}
```

**Output:**

```
First Element: 1  
Last Element: 5
```

Di sini, kita menggunakan `numbers.end() - 1` alih-alih `numbers.end()`.

Hal ini karena fungsi `end()` menunjuk ke elemen teoritis setelah elemen terakhir dari _container_.

Jadi, kita perlu mengurangi 1 dari `numbers.end()` untuk menunjuk ke elemen terakhir. Demikian pula, `numbers.end() - 2` akan menunjuk ke elemen kedua dari belakang, dan seterusnya.

**Catatan:**

- Tanda `*` sebelum `itr` menunjukkan bahwa nilai dari elemen yang ditunjuk oleh _iterator_ sedang diakses (seperti _dereferencing_ pointer).
    
- Jika kita mencoba mencetak _iterator_ secara langsung, akan muncul error:
    
    ```cpp
    // error
    cout << itr << "  ";
    ```
    
    Karena, tidak seperti pointer, kita **tidak bisa mencetak iterator** secara langsung.
    

---

## C++ STL Algorithms

Sebuah **algoritma** adalah serangkaian instruksi untuk menyelesaikan suatu masalah tertentu.

Dalam C++, kita bisa menggunakan STL untuk mengimplementasikan beberapa algoritma yang umum digunakan. Komponen STL ini dikenal sebagai **algorithms library**.

Beberapa algoritma yang paling umum digunakan dalam STL antara lain:

- **Sorting algorithms**
    
- **Searching algorithms**
    
- **Copying algorithms**
    
- **Counting algorithms**
    

> Untuk mempelajari lebih lanjut tentang _algorithms library_, kunjungi tutorial **C++ STL Algorithms**.

---

## Contoh 3: C++ STL Sorting Algorithm

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    
    // inisialisasi vector bertipe int
    vector<int> numbers = {3, 2, 5, 1, 4};

    // mengurutkan elemen vector dalam urutan menaik
    sort(numbers.begin(), numbers.end());

    // mencetak vector yang telah diurutkan
    for (int number : numbers) {
        cout << number << "  ";
    }
    
    return 0;    
}
```

**Output:**

```
1  2  3  4  5
```

Dalam contoh ini, kita menggunakan fungsi `sort()` untuk mengurutkan elemen-elemen dari _vector_ `numbers` dalam urutan menaik.

Perhatikan bahwa kita mengimpor _header file_ `<algorithm>` untuk menggunakan fungsi `sort()`.
