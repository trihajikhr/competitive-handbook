---
obsidianUIMode: preview
note_type: data structures theory
nama_algoritma: set
kategori_algoritma: data structures
kesulitan: 🥉 easy
sumber: geeksforgeeks.org
date_learned: 2025-06-20T20:32:00
tags:
  - set
  - data-structures
---
Link Sumber: [Set in C++ STL - GeeksforGeeks](https://www.geeksforgeeks.org/cpp/set-in-cpp-stl/)

---
> [!IMPORTANT]
> 
# C++ STL

Di C++, _set_ adalah wadah asosiatif (_associative container_) yang menyimpan elemen-elemen unik dalam urutan yang terurut. Secara default, elemen-elemen disimpan dalam urutan menaik berdasarkan _key_-nya, tetapi urutan ini dapat diubah sesuai kebutuhan. _Set_ menyediakan operasi penyisipan, penghapusan, dan pencarian yang cepat.

Contoh:

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    
    // Membuat set berisi bilangan bulat
    set<int> s = {3, 5, 2, 1};
    
    for (auto x : s)
        cout << x << " ";
    return 0;
}
```

**Output:**

```
1 2 3 5
```

**Penjelasan:**  
Dalam program di atas, kita membuat sebuah _set_ dengan nama `s` yang berisi nilai-nilai `{3, 5, 2, 1}`. _Set_ akan otomatis menyusun elemen-elemennya dalam urutan menaik, dan hanya menyimpan elemen unik.

## 1. Sintaks

Wadah _set_ didefinisikan sebagai _class template_ `std::set` di dalam header `<set>`.

```cpp
set<T, comp> s;
```

Keterangan:

- `T`: Tipe data dari elemen-elemen dalam _set_
    
- `s`: Nama yang diberikan untuk _set_
    
- `comp`: Fungsi predikat biner yang menentukan bagaimana _set_ membandingkan dua elemen. Digunakan untuk mengurutkan _set_ dalam urutan kustom. Argumen ini bersifat opsional — jika tidak diberikan, _set_ akan diurutkan secara menaik.
    
## 2. Deklarasi dan Inisialisasi

Kita bisa mendeklarasikan dan menginisialisasi sebuah _set_ dengan berbagai cara seperti ditunjukkan dalam kode berikut:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {

    // Membuat set kosong
    set<int> s1;

    // Membuat set menggunakan initializer list
    set<int> s2 = {5, 1, 3, 2, 4};

    for (auto i : s2)
        cout << i << " ";
    return 0;
}
```

**Output:**

```
1 2 3 4 5
```

**Penjelasan:**  
Dalam program ini, kita membuat dua _set_:

- Pernyataan `set<int> s1` membuat _set_ kosong bernama `s1`. Ini disebut inisialisasi default.
    
- Pernyataan `set<int> s2 = {5, 1, 3, 2, 4}` membuat _set_ `s2` dengan 5 elemen menggunakan initializer list.
    

Untuk mengetahui lebih banyak cara dalam menginisialisasi _set_ di C++, kamu bisa merujuk pada artikel _Different Ways to Initialize Set_.

## 3. Operasi Dasar

Berikut ini adalah operasi dasar yang dapat dilakukan pada _set_:

### 3.1. Menambahkan elemen

Dalam _set_, elemen ditambahkan menggunakan fungsi `insert()` atau `emplace()`. Jika elemen sudah ada di dalam _set_, maka tidak akan ditambahkan lagi. Kita tidak bisa menentukan posisi penyisipan karena urutan elemen ditentukan secara otomatis berdasarkan aturan pengurutan.

**Contoh:**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s = {1, 4, 2};

    // Menambahkan elemen ke set
    s.insert(5);
    s.emplace(3);
    s.insert(5); // tidak akan ditambahkan karena 5 sudah ada

    for (auto x : s) cout << x << " ";
    return 0;
}
```

**Output:**

```
1 2 3 4 5
```

### 3.2. Mengakses elemen

Kita tidak bisa mengakses elemen _set_ menggunakan indeks seperti pada array atau vector. Untuk mengakses elemen berdasarkan posisi, kita perlu menggunakan iterator yang diperoleh dari fungsi `begin()` atau `end()` dan menggesernya dengan fungsi `next()` atau `advance()`.

**Contoh:**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s = {1, 4, 2, 3, 5};

    // Mengakses elemen pertama
    auto it1 = s.begin();

    // Mengakses elemen ketiga
    auto it2 = next(it1, 2);

    cout << *it1 << " " << *it2;
    return 0;
}
```

**Output:**

```
1 3
```

**Penjelasan:**  
Dalam program di atas, `s.begin()` mengembalikan iterator ke elemen pertama dari _set_ dan disimpan di `it1`. Untuk mengakses elemen ketiga, fungsi `next()` digunakan untuk menggeser iterator `it1` sebanyak 2 posisi, dan disimpan dalam `it2`. `*it1` dan `*it2` digunakan untuk mendereferensikan iterator tersebut sehingga kita bisa mendapatkan nilai pada posisi itu.

### 3.3. Memperbarui elemen

Kita **tidak dapat mengubah nilai elemen** setelah elemen tersebut disimpan dalam _set_.

### 3.4. Mencari elemen

_Set_ menyediakan operasi pencarian cepat berdasarkan nilai dengan menggunakan fungsi anggota `find()`. Fungsi ini mengembalikan _iterator_ ke elemen jika ditemukan, atau mengembalikan `end()` jika tidak ditemukan.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s = {1, 4, 2, 3, 5};

    // Mencari angka 3
    auto it = s.find(3);

    if (it != s.end()) cout << *it;
    else cout << "Element not Found!";
    return 0;
}
```

**Output:**

```
3
```

### 3.5. Melakukan traversal

Sama seperti kontainer lainnya, _set_ dapat dengan mudah ditelusuri menggunakan _range-based for loop_ atau menggunakan _iterator_ dari `begin()` dan `end()`.

**Contoh:**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s = {5, 1, 4, 3, 2};

    // Menelusuri menggunakan iterator
    for(auto it = s.begin(); it != s.end(); it++)
        cout << *it << " ";
    return 0;
}
```

**Output:**

```
1 2 3 4 5
```

### 3.6. Menghapus elemen

Dalam _set_, elemen dihapus menggunakan fungsi `erase()`. Kita bisa menghapus elemen berdasarkan nilai, atau berdasarkan posisi menggunakan _iterator_.

**Contoh:**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s = {1, 4, 2, 3, 5};

    // Menghapus elemen berdasarkan nilai
    s.erase(5);

    // Menghapus elemen pertama dengan iterator
    s.erase(s.begin());

    for (auto x : s) cout << x << " ";
    return 0;
}
```

**Output:**

```
2 3 4
```

## 4. Kompleksitas Waktu

Berikut adalah tabel kompleksitas waktu dari berbagai operasi dasar pada _set_:

|Operasi|Kompleksitas Waktu|
|---|---|
|Menyisipkan elemen|O(log n)|
|Menghapus elemen|O(log n)|
|Mencari elemen terbesar|O(1)|
|Mencari elemen terkecil|O(1)|
|Mencari elemen tertentu|O(log n)|
|Menelusuri seluruh _set_|O(n)|

## 5. Cara Kerja Internal

Di C++, _set_ adalah kontainer asosiatif yang diimplementasikan menggunakan **Red-Black Tree**. Struktur data ini menjamin elemen selalu tersimpan dalam urutan terurut dan memastikan bahwa operasi penyisipan, penghapusan, dan pencarian berjalan dalam waktu logaritmik.

### 5.1. Perbedaan set dan unordered set

|Fitur|`set`|`unordered_set`|
|---|---|---|
|Urutan|Elemen disimpan terurut|Elemen disimpan acak|
|Kompleksitas waktu|O(log n) untuk operasi|O(1) untuk operasi|
|Struktur|Red-Black Tree|Hash Table|

### 5.2. Daftar fungsi anggota `std::set`

|Fungsi|Deskripsi|
|---|---|
|`begin()`|Mengembalikan _iterator_ ke elemen pertama|
|`end()`|Mengembalikan _iterator_ ke setelah elemen terakhir|
|`rbegin()`|Iterator balik ke elemen terakhir|
|`rend()`|Iterator balik ke sebelum elemen pertama|
|`crbegin()`|Konstanta reverse iterator ke akhir|
|`crend()`|Konstanta reverse iterator ke awal|
|`cbegin()`|Konstanta iterator ke awal|
|`cend()`|Konstanta iterator ke akhir|
|`size()`|Mengembalikan jumlah elemen|
|`max_size()`|Ukuran maksimum yang bisa ditampung|
|`empty()`|Mengecek apakah kosong|
|`insert()`|Menyisipkan elemen|
|`erase()`|Menghapus elemen|
|`swap()`|Menukar isi dengan _set_ lain|
|`clear()`|Menghapus seluruh elemen|
|`emplace()`|Menyisipkan elemen secara efisien|
|`insert_range()`|Menyisipkan banyak elemen sekaligus|
|`merge()`|Menggabungkan dua _set_|
|`count()`|Mengembalikan jumlah elemen (selalu 0 atau 1)|
|`find()`|Mencari elemen|
|`contains()`|Mengecek apakah elemen ada|
|`equal_range()`|Mengembalikan pasangan iterator untuk elemen dengan _key_ tertentu|
|`upper_bound()`|Menemukan elemen pertama yang lebih besar dari nilai tertentu|
|`lower_bound()`|Menemukan elemen pertama yang sama atau lebih besar|
|`key_comp()`|Mengembalikan objek pembanding (_comparator_) yang digunakan|
