---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 04TH-DSSE-0001
nama_algoritma: set data structure
kategori_algoritma: data structure
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
sumber: programiz.com
date_learned: 2025-04-21T19:37:00
tags:
  - array
  - data-structure
  - set
---
#array #data-structure #set 

---
# C++ Set Data Structure  
Set adalah container STL (Standard Template Library) yang menyimpan elemen-elemen unik dengan tipe yang sama secara terurut.

Karena setiap elemen dalam set memiliki nilai yang unik, nilai itu sendiri bertindak sebagai key untuk mengidentifikasi elemen tersebut.

## Properti Set  
Set di C++ memiliki properti berikut:

1. **Elemen Unik**  
    Tidak ada dua elemen dalam set yang memiliki nilai yang sama.
    
2. **Tidak Bisa Diubah**  
    Kita dapat menambahkan atau menghapus elemen dari set, tetapi kita tidak bisa mengubah nilai dari elemen yang sudah ada.
    
3. **Urutan Terurut**  
    Elemen dalam set disimpan dalam urutan tertentu yang mengikuti _strict weak ordering_.
    
    Secara default, set di C++ disusun dalam urutan menaik (ascending), tetapi kita bisa mengubahnya jika diperlukan.
    
4. **Asosiatif**  
    Elemen dalam set diakses berdasarkan key-nya, bukan berdasarkan posisi di dalam container.
    
    Ini berbeda dengan array, di mana elemen diakses menggunakan indeks.

## Membuat Set  
Untuk menggunakan _set_ dalam C++, kita harus menyertakan file header `<set>` dalam program kita:

```cpp
#include <set>
```

Kita bisa membuat _set_ di C++ dengan sintaks berikut:

```cpp
// deklarasi set
std::set<data_type> set_name = {key1, key2, key3, ...};
```

Penjelasan:

- `std::set` – mendeklarasikan container STL dengan tipe _set_.
    
- `<data_type>` – tipe data dari nilai-nilai yang akan disimpan dalam set.
    
- `set_name` – nama unik yang diberikan untuk set tersebut.
    
- `key1, key2, key3, ...` – nilai-nilai (yang juga bertindak sebagai key) yang akan disimpan dalam set.
    

Contoh:

```cpp
// inisialisasi set dengan elemen
std::set<int> my_set1 = {5, 3, 8, 1, 3};

// membuat set kosong
std::set<int> my_set2;
```

**Catatan:**  
Selanjutnya, kita akan menggunakan _namespace_ `std`, jadi kita bisa menghilangkan `std::` dari sintaks kita.

## Contoh 1: Membuat Set

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {

    set<int> my_set = {5, 3, 8, 1, 3};
    
    for(int val : my_set) {
        cout << val << " ";
    }

    return 0;
}
```

**Output:**

```
1 3 5 8
```

Di sini, kita telah membuat sebuah _set_ bertipe `int`.

Seperti yang terlihat, _set_ mengembalikan nilai-nilai dalam urutan yang terurut dan mengabaikan elemen yang duplikat (3 hanya muncul sekali).

**Catatan:**  
Kita **tidak bisa menggunakan operator `[]`** untuk menambahkan elemen ke dalam set. Melakukan hal tersebut akan menghasilkan error.

```cpp
// ini tidak diperbolehkan dalam set
my_set[4] = 4;
```

---

### Mengurutkan Set dalam Urutan Menurun

Untuk mendapatkan elemen _set_ dalam urutan menurun (_descending_), kita bisa mengubah sintaks seperti berikut:

```cpp
set<int, greater<int>> my_set;
```

**Contoh:**

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {

    set<int, greater<int>> my_set = {5, 3, 8, 1, 3};
    
    for(int val : my_set) {
        cout << val << " ";
    }

    return 0;
}
```

**Output:**

```
8 5 3 1
```

Seperti yang terlihat, elemen-elemen dalam _set_ kini dikembalikan dalam urutan menurun.

---

## Method dalam C++ Set

Kelas `set` di C++ menyediakan berbagai metode untuk melakukan operasi pada _set_.

| Operasi    | Deskripsi                                                                                    |
| ---------- | -------------------------------------------------------------------------------------------- |
| `insert()` | Menambahkan elemen ke dalam set.                                                             |
| `erase()`  | Menghapus elemen dari set.                                                                   |
| `clear()`  | Menghapus semua elemen dalam set.                                                            |
| `empty()`  | Mengecek apakah set kosong.                                                                  |
| `size()`   | Mengembalikan jumlah elemen dalam set.                                                       |
| `count(x)` | Mengecek, apakah nilai x ada didalam set. Mengembalikan 1 jika ada di set, dan 0 jika tidak. |
|            |                                                                                              |

---

## Contoh 2: Menambahkan Nilai ke Set

```cpp
#include <iostream>     
#include <set>          
using namespace std;
   
int main () {

    set<int> my_set;

    // menambahkan nilai ke dalam set
    my_set.insert(10);
    my_set.insert(30);
    my_set.insert(20);
    my_set.insert(50);
    my_set.insert(40);
    my_set.insert(50);
    
    // mencetak elemen-elemen set
    for (int i : my_set) {
        cout << i << "  ";
    }
    
    return 0;
}
```

**Output:**

```
10  20  30  40  50
```

Di sini, kita membuat _set_ kosong bernama `my_set` bertipe `int` dan menambahkan nilai menggunakan metode `insert()`.

Perhatikan bahwa elemen duplikat (50) diabaikan, dan _set_ tetap terurut naik meskipun urutan penambahannya berbeda.

## Contoh 3: Mengecek Apakah Sebuah Elemen Ada dalam Set

```cpp
#include <iostream>     
#include <set>          
using namespace std;
   
int main () {

    set<int> my_set;

    // menambahkan nilai ke dalam set
    my_set.insert(10);
    my_set.insert(30);
    my_set.insert(20);
    my_set.insert(50);
    my_set.insert(40);
    my_set.insert(50);
    
    // mengecek apakah 40 ada
    int num = 40;
    if(my_set.count(num) == 1) {
        cout << num << " exists." << endl;
    } else {
        cout << num << " doesn't exist." << endl;
    }
    
    // mengecek apakah 60 ada
    num = 60;
    if(my_set.count(num) == 1) {
        cout << num << " exists." << endl;
    } else {
        cout << num << " doesn't exist." << endl;
    }
    
    return 0;
}
```

**Output:**

```
40 exists.
60 doesn't exist.
```

Di sini, kita membuat _set_ kosong `my_set` bertipe `int` dan menambahkan nilai-nilai menggunakan metode `insert()`.

Kita memeriksa apakah angka `40` dan `60` ada dalam _set_ menggunakan `my_set.count(num)`.

Metode `count(num)` akan mengembalikan `1` jika `num` ada dalam _set_, dan `0` jika tidak.

---

## Contoh 4: Menghapus Elemen dari Set

```cpp
#include <iostream>     
#include <set>          
using namespace std;
   
int main () {

    set<int> my_set = {10, 20, 30, 40};
    
    // set sebelum penghapusan
    cout << "The set before deletion: ";
    for (int i : my_set) {
        cout << i << "  ";
    }

    // menghapus elemen dari set
    my_set.erase(10);
    my_set.erase(20);
    
    // set setelah penghapusan
    cout << "\nThe set after deletion: ";
    for (int i : my_set) {
        cout << i << "  ";
    }

    // menghapus semua elemen dari set
    my_set.clear();

    // set setelah menghapus semua elemen
    cout << "\nThe set after clearing all elements: ";
    for (int i : my_set) {
        cout << i << "  ";
    }
    
    return 0;
}
```

**Output:**

```
The set before deletion: 10  20  30  40  
The set after deletion: 30  40  
The set after clearing all elements: 
```

Di sini, kita menggunakan metode `erase()` untuk menghapus elemen tertentu dari _set_.

Lalu kita menggunakan metode `clear()` untuk menghapus semua elemen dalam _set_.

---

## Contoh 5: Metode `empty()` dan `size()` pada C++ Set

Metode `empty()` dan `size()` disebut _capacity methods_ dalam C++.

- `empty()` mengembalikan:
    
    - `1` (true) jika _set_ kosong
        
    - `0` (false) jika _set_ tidak kosong
        

**Contoh:**

```cpp
#include <iostream>     
#include <set>          
using namespace std;
   
int main () {

    set<int> my_set = {10, 20, 30};

    // set sebelum clear
    cout << "The set before clear: ";
    for (int i : my_set) {
        cout << i << "  ";
    }
    
    // mengecek apakah set kosong
    cout << "\nEmpty: " << my_set.empty() << endl;

    // mengecek jumlah elemen dalam set
    cout << "Size: " << my_set.size() << endl;
    
    // menghapus seluruh elemen dari set
    my_set.clear();
    
    // set setelah clear
    cout << "\nThe set after clear: ";
    for (int i : my_set) {
        cout << i << "  ";
    }
    
    // mengecek kembali dengan capacity methods
    cout << "\nEmpty: " << my_set.empty() << endl;
    cout << "Size: " << my_set.size() << endl;

    return 0;
}
```

**Output:**

```
The set before clear: 10  20  30  
Empty: 0  
Size: 3  

The set after clear:  
Empty: 1  
Size: 0
```

Sebelum menghapus elemen:

- `empty()` mengembalikan `0`, menandakan set tidak kosong
    
- `size()` mengembalikan `3`, menandakan ada 3 elemen
    

Setelah menghapus:

- `empty()` mengembalikan `1`, menandakan set kosong
    
- `size()` mengembalikan `0`, menandakan tidak ada elemen dalam set.

## Contoh 6: Metode `count()` untuk mengecek data ke Set
Untuk mengetahui apakah elemen `x` ada dalam set di C++, Anda dapat menggunakan fungsi `count()` dari `std::set`. Syntaxnya adalah `set.count(x)`. Fungsi ini akan mengembalikan 1 jika `x` ada di set, dan 0 jika tidak.

```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> mySet = {1, 2, 3, 4, 5};
    int x = 3;

    if (mySet.count(x) == 1) {
        std::cout << "Elemen " << x << " ada di set." << std::endl;
    } else {
        std::cout << "Elemen " << x << " tidak ada di set." << std::endl;
    }

    x = 6;

    if (mySet.count(x) == 1) {
        std::cout << "Elemen " << x << " ada di set." << std::endl;
    } else {
        std::cout << "Elemen " << x << " tidak ada di set." << std::endl;
    }

    return 0;
}
```

Penjelasan:

1. `#include <iostream>`: Menghubungkan header untuk operasi I/O (input/output).
2. `#include <set>`: Menghubungkan header untuk menggunakan kelas `std::set`.
3. `std::set<int> mySet = {1, 2, 3, 4, 5};`: Membuat sebuah set `mySet` bertipe `int` dan diinisialisasi dengan beberapa nilai.
4. `int x = 3;`: Mendeklarasikan variabel `x` bertipe `int` dan diinisialisasi dengan nilai 3.
5. `mySet.count(x)`: Memanggil fungsi `count()` pada set `mySet` dengan nilai `x` sebagai argumen.
6. `if (mySet.count(x) == 1)`: Memeriksa apakah `count()` mengembalikan 1 (berarti `x` ada di set).
7. `if (mySet.count(x) == 0)`: Memeriksa apakah `count()` mengembalikan 0 (berarti `x` tidak ada di set).
8. `std::cout`: Menampilkan output ke layar.

Maka outputnya:

```
Elemen 3 ada di set.
Elemen 6 tidak ada di set.
```