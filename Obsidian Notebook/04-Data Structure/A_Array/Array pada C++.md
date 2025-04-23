---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSAR-0001
nama_algoritma: 
kategori_algoritma: data structure
kesulitan: 
time_complexity: 
memory_complexity: 
sumber: programiz.com & chatgpt.com
date_learned: 2025-04-23T09:51:00
tags:
  - array
  - data-structure
---
#array #data-structure 

---
# C++ `std::array`

Dalam C++, `std::array` adalah sebuah _container class_ yang membungkus array berukuran tetap. Ia mirip dengan array bergaya C karena menyimpan banyak nilai dengan tipe yang sama.

## Deklarasi C++ `std::array`

`std::array` didefinisikan di dalam header `<array>`, jadi kita harus menyertakan header ini sebelum menggunakan `std::array`.

**Sintaks**

```cpp
#include <array>

// deklarasi std::array
std::array<T, N> nama_array;
```

Keterangan:

- `T` – Tipe elemen yang akan disimpan
    
- `N` – Jumlah elemen dalam array
    

Berikut contoh deklarasi `std::array` berukuran 5 yang menyimpan daftar angka:

```cpp
std::array<int, 5> numbers;
```

## Inisialisasi `std::array`

Kita bisa menginisialisasi `std::array` dengan dua cara:

**Metode 1:**

```cpp
// initializer list
std::array<int, 5> numbers = {1, 2, 3, 4, 5};
```

**Metode 2:**

```cpp
// uniform initialization
std::array<int, 5> marks {10, 20, 30, 40, 50};
```

Di sini, kita menginisialisasi dua array bernama `numbers` dan `marks`, keduanya berukuran 5 dan menyimpan elemen bertipe `int`.

---

### Contoh: C++ `std::array`

```cpp
#include <iostream>
#include <array>

using namespace std;

int main(){
    // uniform initialization
    array<int, 5> numbers {1, 2, 3, 4, 5};

    cout << "The elements are: " << endl;

    // loop dengan range-based for
    for(const int num: numbers){
        cout << num << " ";
    }
}
```

**Output:**

```
The elements are: 
1 2 3 4 5
```

---

## Mengakses Elemen `std::array`

Kita bisa mengakses elemen array menggunakan operator `[]` dan indeks elemen:

```cpp
std::array<int, 5> n = {1, 2, 3, 4, 5};

std::cout << n[0]; // mengembalikan 1
std::cout << n[1]; // mengembalikan 2
```

Karena indeks dimulai dari 0, maka `n[0]` adalah elemen pertama, `n[1]` adalah elemen kedua, dan seterusnya.

> Catatan: Mengakses elemen menggunakan operator `[]` tidak memeriksa kesalahan _out of bounds_ (di luar batas).

Kesalahan _out of bounds_ terjadi saat program mencoba mengakses data di luar batas yang diizinkan. Misalnya, kita punya array berisi 5 elemen dan mencoba mengakses elemen ke-10 — itu adalah kesalahan _out of bounds_.

Cara lain untuk mengakses elemen array adalah menggunakan metode `at`, yang memeriksa kesalahan _out of bounds_:

```cpp
std::array<int, 5> n = {1, 2, 3, 4, 5};
std::cout << n.at(0);  // mengembalikan 1
std::cout << n.at(1);  // mengembalikan 2
std::cout << n.at(10); // melempar pengecualian std::out_of_range
```

---

## Memodifikasi Elemen `std::array`

Untuk memodifikasi elemen pada indeks tertentu, kita bisa menggunakan `[]` atau `at`:

```cpp
std::array<int, 5> marks = {50, 67, 88, 98, 34};

marks[2] = 76;       // ubah elemen ke-3 menggunakan []
marks.at(0) = 1;     // ubah elemen pertama menggunakan at
```

**Contoh: Memodifikasi dan Mengakses Elemen Array**

```cpp
#include <iostream>
#include <array>

using namespace std;

int main(){
    array<int, 5> numbers = {1, 2, 3, 4, 5};

    cout << "First element: " << numbers[0] << '\n';
    cout << "Second element: " << numbers.at(1) << '\n';

    numbers[0] = 8;
    cout << "Modifying first element: " << numbers[0] << '\n';

    numbers.at(1) = 90;
    cout << "Modifying second element: " << numbers[1] << '\n';
}
```

**Output:**

```
First element: 1  
Second element: 2  
Modifying first element: 8  
Modifying second element: 90
```

---

## Mengecek Apakah Array Kosong

Untuk memeriksa apakah array kosong, gunakan metode `empty()`:

```cpp
n.empty();
```

Metode `empty` akan mengembalikan `true` jika array kosong dan `false` jika tidak.

---

## Mendapatkan Jumlah Elemen Array

Gunakan metode `size()` untuk mendapatkan jumlah elemen dalam array:

```cpp
n.size();  // mengembalikan ukuran array
```

**Contoh: Menggunakan `empty` dan `size`**

```cpp
#include <iostream>
#include <array>
using namespace std;

int main(){
    array<int, 5> numbers = {1, 2, 3, 4, 5};

    cout << "The size of array is: " << numbers.size() << '\n';

    if(numbers.empty()){
        cout << "The array is empty";
    } else {
        cout << "The array is not empty";
    }
}
```

**Output:**

```
The size of array is: 5  
The array is not empty
```

---

## Mengisi `std::array` Dengan Nilai yang Sama

Gunakan metode `fill()` untuk mengisi seluruh array dengan nilai yang sama.

**Contoh:**

```cpp
#include <iostream>
#include <array>

using namespace std;

int main(){
    array<int, 5> a;

    a.fill(0);  // isi array dengan nol

    cout << "The elements are: ";
    for(const int& elt: a){
        cout << elt << " ";
    }
}
```

**Output:**

```
The elements are: 0 0 0 0 0
```

---

## Contoh: Menggunakan `std::array` dengan Algoritma STL

Dalam C++, kita dapat menggunakan _Standard Template Library (STL)_ untuk menerapkan beberapa algoritma yang umum digunakan. Algoritma-algoritma ini mendukung `std::array` dengan baik.

```cpp
#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>

using namespace std;

int main(){
    array<int, 5> age = {45, 23, 66, 87, 21};

    // sorting
    sort(age.begin(), age.end());

    cout << "The sorted array is: ";
    for(const int elt: age){
        cout << elt << " ";
    }
    cout << endl;

    // searching
    auto found = find(age.begin(), age.end(), 5);

    if (found != age.end()) cout << "5 was Found" << endl;
    else cout << "5 was Not Found" << endl;

    // summing
    int sum = accumulate(age.begin(), age.end(), 0);

    cout << "The sum of the element of array is : " << sum;
}
```

**Output:**

```
The sorted array is: 21 23 45 66 87  
5 was Not Found  
The sum of the element of array is : 242
```

**Penjelasan:**

- **Sorting:** menggunakan `sort(age.begin(), age.end())` untuk mengurutkan array dari awal hingga akhir.
    
- **Searching:** menggunakan `find(age.begin(), age.end(), 5)` untuk mencari angka 5 dalam array.
    
- **Summing:** menggunakan `accumulate(age.begin(), age.end(), 0)` untuk menjumlahkan semua elemen dalam array.
    
