---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSLS-B001
nama_algoritma: forward list
kategori_algoritma: data structure
kesulitan: 
time_complexity: 
memory_complexity: 
sumber: programiz.com & chatgpt.com
date_learned: 2025-04-23T10:25:00
tags:
  - array
  - data-structure
  - forward-list
---
#array #data-structure #forward-list

---
# C++ Forward List

_Forward list_ C++ adalah _sequence containers_ yang tersusun dalam urutan linear yang ketat, di mana kamu bisa menambahkan atau menghapus elemen di mana saja dalam urutan tersebut dengan efisiensi waktu konstan.

Elemen dalam _forward list_ menyimpan informasi tentang lokasi elemen berikutnya. Oleh karena itu, mereka lebih efisien dalam menyisipkan, memindahkan, dan mengekstraksi elemen dibandingkan dengan _containers_ seperti _array_, _vector_, dan sebagainya.

Namun, akses acak langsung tidak didukung dalam _forward list_.

---

## Membuat Forward List

Untuk membuat _forward list_, kita harus menyertakan header `<forward_list>` dalam kode kita:

```cpp
#include <forward_list>
```

Kita bisa menginisialisasi _forward list_ sebagai berikut:

```cpp
std::forward_list<data_type> forward_list_name = {value1, value2, value3, ...};
```

Penjelasan:

- `data_type` – tipe data dalam _forward list_.
    
- `forward_list_name` – nama dari _forward list_.
    
- `value1, value2, value3, ...` – nilai-nilai yang akan dimasukkan.
    

Contoh:

```cpp
// membuat forward list bertipe integer
std::forward_list<int> integer_fwd_list = {1, 3, 2, 4, 5};

// membuat forward list bertipe string
std::forward_list<string> string_fwd_list = {"Eeny", "Meeny", "Miny", "Moe"};
```

---

## Contoh 1: C++ Forward List

```cpp
#include <forward_list>
#include <iostream>
using namespace std;

int main() {

    forward_list<int> fwd_list = {1, 3, 2, 4, 5};

    // mencetak elemen dalam forward list
    for (const int& element : fwd_list) {
        cout << element << " ";
    }

    return 0;
}
```

**Output:**

```
1 3 2 4 5
```

Perhatikan bahwa elemen muncul sesuai urutan saat dimasukkan.

> Catatan: Kita akan menggunakan _namespace std_ di seluruh tutorial. Oleh karena itu, kita menghilangkan `std::` dari contoh.

---

## Metode-metode pada Forward List

Beberapa metode yang umum digunakan dalam _forward list_ adalah:

|Fungsi|Deskripsi|
|---|---|
|`front()`|Mengakses elemen pertama.|
|`push_front()`|Menambahkan elemen ke awal daftar.|
|`insert_after()`|Menambahkan elemen tepat setelah posisi tertentu.|
|`assign()`|Mengganti isi daftar dengan konten baru.|
|`pop_front()`|Menghapus elemen pertama.|
|`remove()`|Menghapus elemen dengan nilai tertentu.|
|`clear()`|Menghapus semua isi daftar.|

---

## Contoh 2: Mengakses Elemen Pertama dari Forward List

Kita dapat mengakses elemen pertama dari _forward list_ menggunakan fungsi `front()`.

```cpp
#include <forward_list>
#include <iostream>

using namespace std;

int main() {

    forward_list<int> fwd_list = {1, 2, 3, 4, 5};

    // mengakses elemen pertama
    int first_element = fwd_list.front();

    cout << "The first element is: " << first_element;

    return 0;
}
```

**Output:**

```
The first element is: 1
```

---

## Contoh 3: Menambahkan Elemen ke Forward List

Ada dua cara untuk menambahkan elemen ke _forward list_:

- `push_front()` – menambahkan elemen di awal.
    
- `insert_after()` – menambahkan elemen di posisi tertentu.
    

```cpp
#include <forward_list>
#include <iostream>

using namespace std;

int main() {

    forward_list<int> fwd_list = {1, 2, 5};

    // menambahkan elemen di awal
    fwd_list.push_front(2);

    cout << "Forward List setelah push_front(): ";
    for (const int& element : fwd_list) {
        cout << element << " ";
    }
    cout << endl;

    // menunjuk iterator ke posisi ke-2
    auto itr = fwd_list.begin();
    advance(itr, 1);

    // menyisipkan angka 7 di posisi ke-3
    fwd_list.insert_after(itr, 7);

    cout << "Forward List setelah insert_after(): ";
    for (const int& element : fwd_list) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
```

**Output:**

```
Forward List setelah push_front(): 2 1 2 5 
Forward List setelah insert_after(): 2 1 7 2 5  
```

Di sini, `fwd_list.push_front()` menambahkan `2` di awal _forward list_.

Untuk menyisipkan `7` di posisi ketiga, kita harus memindahkan `itr` ke posisi kedua:

```cpp
auto itr = fwd_list.begin();
advance(itr, 1);
```

Kemudian, kita sisipkan elemen setelah posisi tersebut:

```cpp
fwd_list.insert_after(itr, 7); 
```

---

## Contoh 4: Memperbarui Isi Forward List

Kita bisa memperbarui seluruh isi _forward list_ dengan elemen baru menggunakan fungsi `assign()`.

```cpp
#include <forward_list>
#include <iostream>

using namespace std;

int main() {

    forward_list<int> fwd_list = {1, 2, 5};
    
    cout << "Forward List sebelum assign(): ";
    for (const int& element : fwd_list) {
        cout << element << " ";
    }
    
    // mengganti seluruh isi dengan elemen baru 3 dan 4
    fwd_list.assign({3, 4});

    cout << "\nForward List setelah assign(): ";
    for (const int& element : fwd_list) {
        cout << element << " ";
    }
    cout << endl;
    
    return 0;    
}
```

**Output:**

```
Forward List sebelum assign(): 1 2 5 
Forward List setelah assign(): 3 4 
```

Fungsi `assign()` menggantikan seluruh isi _forward list_ dengan isi baru.

---

## Contoh 5: Menghapus Elemen dari Forward List

Ada tiga cara untuk menghapus elemen dari _forward list_:

- `pop_front()` – menghapus elemen pertama.
    
- `remove()` – menghapus semua elemen dengan nilai tertentu.
    
- `clear()` – menghapus semua elemen dari daftar.
    

```cpp
#include <forward_list>
#include <iostream>

using namespace std;

int main() {

    forward_list<int> fwd_list = {1, 2, 3, 4, 3, 5};

    cout << "Original Forward List: ";
    for (const int& element : fwd_list) {
        cout << element << " ";
    }
    cout << endl;

    // menghapus elemen pertama
    fwd_list.pop_front();

    cout << "Forward List setelah pop_front(): ";
    for (const int& element : fwd_list) {
        cout << element << " ";
    }
    cout << endl;

    // menghapus semua nilai 3
    fwd_list.remove(3);

    cout << "Forward List setelah remove(3): ";
    for (const int& element : fwd_list) {
        cout << element << " ";
    }
    cout << endl;

    // menghapus semua elemen
    fwd_list.clear();

    cout << "Forward List setelah clear(): ";
    for (const int& element : fwd_list) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
```

**Output:**

```
Original Forward List: 1 2 3 4 3 5 
Forward List setelah pop_front(): 2 3 4 3 5 
Forward List setelah remove(3): 2 4 5 
Forward List setelah clear(): 
```
