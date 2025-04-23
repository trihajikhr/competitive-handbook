---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 04TH-DSMP-LT01
nama_algoritma: multimap data structure
kategori_algoritma: data structure
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
sumber: programiz.com & chatgpt.com
date_learned: 2025-04-22T16:22:00
tags:
  - array
  - data-structure
  - multimap
---
#array #data-structure #multimap

---
# C++ Multimap

**C++ multimap** adalah _associative container_ dalam Standard Template Library (STL) yang menyediakan fungsionalitas seperti map, tetapi memperbolehkan beberapa elemen memiliki **key** yang sama (_equivalent keys_).

## Membuat C++ Multimap

Untuk membuat multimap di C++, kita perlu menyertakan file header `<map>` terlebih dahulu:

```cpp
#include <map>
```

Setelah kita mengimpor file tersebut, kita bisa membuat multimap dengan sintaks berikut:

```cpp
std::multimap<key_type, value_type> multimap_name = {
    {key1, value1},
    {key2, value2},
    ...
};
```

Keterangan:

- `key_type` – tipe data untuk key
    
- `value_type` – tipe data untuk value
    
- `{key1, value1}, {key2, value2}, ...` – pasangan key-value yang akan dimasukkan ke multimap
    

> Catatan: Kita akan menggunakan _namespace_ `std` dalam tutorial ini. Jadi, kita bisa cukup menulis `multimap` alih-alih `std::multimap`.

Contoh:

```cpp
// membuat multimap dengan key bertipe int dan value bertipe string
multimap<int, string> my_multimap = {
    {1, "One"},
    {1, "Uno"},
    {2, "Two"},
};
```

Multimap di atas bernama `my_multimap`, di mana key bertipe `int` dan value bertipe `string`.

---

## Contoh: C++ Multimap

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {

    // membuat multimap
    multimap<int, string> my_multimap = {
        {1, "Un"},
        {1, "One"},
        {2, "Two"},
        {2, "Dos"},
        {1, "Uno"},
        {2, "Deux"}
    };

    cout << "Key - Value" << endl;

    // melakukan iterasi pada multimap
    // menampilkan pasangan key-value
    for(const auto& key_value: my_multimap) {
        int key = key_value.first;
        string value = key_value.second;

        cout << key << " - " << value << endl;
    }

    return 0;
}
```

**Output:**

```
Key - Value
1 - Un
1 - One
1 - Uno
2 - Two
2 - Dos
2 - Deux
```

Pada contoh di atas, kita mendeklarasikan dan menginisialisasi sebuah multimap bernama `my_multimap`.

Perhatikan bahwa multimap diurutkan berdasarkan **key** dan **bukan** berdasarkan urutan penambahan (_insertion_).

> Catatan: Urutan penambahan hanya dijaga untuk elemen-elemen dengan key yang identik.

Kemudian, kita menampilkan isi multimap menggunakan _ranged for loop_:

```cpp
for(const auto& key_value: my_multimap) {
    int key = key_value.first;
    string value = key_value.second;    
    cout << key << " - " << value << endl;
}
```

Pada kode tersebut, setiap elemen (pasangan key-value) dari multimap disimpan dalam variabel `key_value`.

Kemudian kita mengambil key dan value menggunakan:

- `key_value.first` – mengambil key
    
- `key_value.second` – mengambil value
    
# Metode pada C++ Multimap

Dalam C++, kelas `multimap` menyediakan berbagai metode untuk melakukan operasi berbeda pada multimap.

|Metode|Deskripsi|
|---|---|
|`insert()`|menyisipkan satu atau lebih pasangan key-value|
|`count()`|mengembalikan jumlah total kemunculan dari key tertentu|
|`find()`|mengembalikan iterator ke elemen dengan key tertentu|
|`size()`|mengembalikan jumlah elemen|
|`empty()`|mengembalikan `true` jika multimap kosong|
|`erase()`|menghapus elemen dengan key tertentu|
|`clear()`|menghapus semua elemen dalam multimap|

---

## Menyisipkan Elemen ke dalam Multimap

Kita dapat menyisipkan pasangan key-value ke dalam multimap menggunakan metode `insert()`. Contohnya:

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {

    multimap<string, int> numbers;

    // menyisipkan pasangan {"Odd", 1}
    numbers.insert({"Odd", 1});

    // menyisipkan beberapa pasangan
    numbers.insert({{"Even", 2}, {"Even", 6}, {"Odd", 5}, {"Even", 4}});

    cout << "Key - Value" << endl;

    // menampilkan isi multimap
    for(const auto& key_value: numbers) {
        string key = key_value.first;
        int value = key_value.second;
        cout << key << " - " << value << endl;
    }

    return 0;
}
```

**Output:**

```
Key - Value
Even - 2
Even - 6
Even - 4
Odd - 1
Odd - 5
```

---

## Menghapus Elemen dari Multimap

Kita dapat menggunakan metode berikut untuk menghapus elemen dari multimap:

- `erase()` – menghapus elemen dengan key tertentu
    
- `clear()` – menghapus semua elemen dari multimap
    

Contoh:

```cpp
#include <iostream>
#include <map>
using namespace std;

// prototipe fungsi untuk menampilkan multimap
void display_multimap(const multimap<int, string> &);

int main() {

    multimap<int, string> student {
        {111, "John"},
        {132, "Mark"},
        {143, "Chris"},
        {143, "Christopher"}
    };
  
    cout << "Initial Multimap:" << endl;
    display_multimap(student);

    // menghapus elemen dengan key: 143  
    student.erase(143);
  
    cout << "\nMultimap Setelah Menghapus Key 143: " << endl;
    display_multimap(student);

    // menghapus semua elemen multimap
    student.clear();

    cout << "\nMultimap Setelah Menghapus Semua Elemen: " << endl;
    display_multimap(student);

    return 0;
}

// fungsi untuk menampilkan elemen multimap
void display_multimap(const multimap<int, string> &umap){

    for(const auto& key_value: umap) {
        int key = key_value.first;
        string value = key_value.second;
    
        cout << key << " - " << value << endl;
    }
}
```

**Output:**

```
Initial Multimap:
111 - John
132 - Mark
143 - Chris
143 - Christopher

Multimap Setelah Menghapus Key 143: 
111 - John
132 - Mark

Multimap Setelah Menghapus Semua Elemen: 
```

Pada contoh di atas, kita menggunakan metode `erase()` untuk menghapus elemen-elemen dengan key `143` dari multimap.

Kemudian, kita menggunakan metode `clear()` untuk menghapus semua elemen dalam multimap.
## Mengecek Ukuran dan Kekosongan Multimap

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    multimap<string, int> my_multimap;

    string result = my_multimap.empty() ? "Yes" : "No";
    int multimap_size = my_multimap.size();

    cout << "Before Insertion";
    cout << "\nIs multimap empty? " << result << endl;
    cout << "multimap size: " << multimap_size << endl;

    my_multimap.insert({"apple", 2});

    result = my_multimap.empty() ? "Yes" : "No";
    multimap_size = my_multimap.size();

    cout << "\nAfter Insertion" << endl;
    cout << "Is multimap empty? " << result << endl;
    cout << "multimap size: " << multimap_size << endl;

    return 0;
}
```

**Output:**

```
Before Insertion
Is multimap empty? Yes
multimap size: 0

After Insertion
Is multimap empty? No
multimap size: 1
```

---

## Mencari Key dalam Multimap

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    multimap<string, int> my_multimap {
        {"apple", 5},
        {"banana", 3},
        {"apple", 2},
        {"cherry", 4}
    };

    string key_to_find = "apple";
    auto found = my_multimap.find(key_to_find);

    if (found != my_multimap.end()) {
        cout << "Found key " << key_to_find << ":\n";
        cout << found->first << " - " << found->second << endl;
    } else {
        cout << "Key " << key_to_find << " not found." << endl;
    }

    return 0;
}
```

**Output:**

```
Found key apple:
apple - 5
```

> Lalu bagaimana jika ada lebih dari satu key yang sama, apakah bisa memunculkan semua value dari key yang sama sekaligus? Kode diatas hanya bisa menampilkan satu key target pertama.

Ya, kamu benar banget — kode kamu saat ini hanya menggunakan `find()`, yang **hanya mengembalikan satu iterator pertama** yang cocok dengan key yang dicari. Karena ini adalah `multimap`, bisa saja ada beberapa entri dengan key yang sama, dan kamu ingin menampilkan semuanya, bukan cuma satu.

Untuk itu, kamu bisa gunakan `equal_range()`, yang mengembalikan **pasangan iterator** (`pair<iterator, iterator>`) yang mencakup semua elemen dengan key yang sama.

Berikut versi revisi kode kamu agar menampilkan semua nilai dengan key yang sama:

```cpp
#include<iostream>
#include<map>
using namespace std;

int main() {
    multimap<int, string> student = {
        {1, "Wali"},
        {1, "Jenna"},
        {2, "Hendrik"},
        {3, "Zulkarnain"},
        {3, "Natasha"},
        {7, "Tania"},
        {6, "Alex"}
    };

    cout << "Key yang anda ingin cari: ";
    int x; cin >> x;

    auto range = student.equal_range(x); // mendapatkan range untuk key x

    if (range.first == range.second) {
        cout << "Key " << x << " tidak ditemukan!" << endl;
    } else {
        cout << "Key ditemukan " << x << ":\n";
        for (auto it = range.first; it != range.second; ++it) {
            cout << it->first << " - " << it->second << endl;
        }
    }

    return 0;
}
```

### Penjelasan:

- `equal_range(x)` akan mengembalikan pasangan `iterator`:
    
    - `range.first` → awal dari key yang cocok
        
    - `range.second` → satu langkah setelah key yang cocok terakhir
        
- Loop dari `range.first` ke `range.second` akan mencetak semua entri dengan key `x`.
    

Silakan coba kode ini, dan kamu akan lihat bahwa semua data dengan key yang sama bisa ditampilkan. 

---

## Mengecek Apakah Key Ada dalam Multimap

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    multimap<int, string> students {
        {20, "Chris"},
        {28, "Joseph"},
        {20, "Blake"}
    };

    cout << "Using count():" << endl;
    int count_20 = students.count(20);
    cout << "Does age 20 exist? " << (count_20 ? "Yes" : "No") << endl;
    if (count_20)
        cout << "Total Students with age 20 = " << count_20 << endl;

    cout << "\nUsing find():" << endl;
    cout << "Does age 27 exist? ";
    cout << (students.find(27) != students.end() ? "Yes" : "No") << endl;

    return 0;
}
```

**Output:**

```
Using count():
Does age 20 exist? Yes
Total Students with age 20 = 2

Using find():
Does age 27 exist? No
```

