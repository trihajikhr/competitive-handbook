---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSUM-0003
nama_algoritma: 
kategori_algoritma: data structure
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
sumber: geeksforgeeks.org
date_learned: 2025-06-16T12:54:00
tags:
  - data-structure
  - unordered_map
---
---
# Unordered Map in C++ STL


Dalam C++, **`unordered_map`** adalah _container_ asosiatif tak terurut yang menyimpan data dalam bentuk pasangan kunci‑nilai unik. Berbeda dengan `map`, `unordered_map` menggunakan **hashing** untuk menyimpan elemennya. Hal ini memberikan kompleksitas waktu rata‑rata $O(1)$ untuk operasi **pencarian**, **penyisipan**, dan **penghapusan**, tetapi elemen-elemen **tidak** disusun dalam urutan tertentu.

---

### Contoh

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Membuat unordered_map dengan kunci int dan nilai string
    unordered_map<int, string> um = {
        {1, "Geeks"},
        {2, "For"},
        {3, "C++"}
    };

    for (auto i : um)
        cout << i.first << ": " << i.second << endl;
    return 0;
}
```

#### Output (urutan bisa berbeda)

```
3: C++
1: Geeks
2: For
```

**Penjelasan:**  
Pada contoh di atas, kita membuat `unordered_map` bernama `um` yang berisi tiga pasangan kunci‑nilai:

- `{1, "Geeks"}`
    
- `{2, "For"}`
    
- `{3, "C++"}`
    

---

## Sintaks
Unordered map didefinisikan oleh `std::unordered_map`   class template, yang ada di header `<unordered_map>`
```cpp
unordered_map<key_type, value_type> um;
```

- `key_type` : tipe data untuk kunci
    
- `value_type`: tipe data untuk nilai
    
- `um` : nama variabel `unordered_map`
    

---

## Deklarasi dan Inisialisasi

Kita dapat mendeklarasikan dan menginisialisasi `unordered_map` dengan beberapa cara:

```cpp
#include <bits/stdc++.h>
using namespace std;

void print(unordered_map<int, string> um) {
    for (auto i : um)
        cout << i.first << " " << i.second << endl;
}

int main() {
    // 1. Default initialization (map kosong)
    unordered_map<int, string> um1;
    
    // 2. Inisialisasi menggunakan initializer list
    unordered_map<int, string> um2 = {
        {1, "Geeks"},
        {2, "For"},
        {3, "C++"}
    };
    
    print(um1);
    cout << endl;
    print(um2);
    return 0;
}
```

#### Output untuk `um2` (urutan acak)

```
3 C++
1 Geeks
2 For
```

**Penjelasan:**

1. `unordered_map<int, string> um1;`  
    Membuat map kosong. Itu disebut dengan *default initialization*.
    
2. `unordered_map<int, string> um2 = {{1, "Geeks"}, {2, "For"}, {3, "C++"}};`  
    Menginisialisasi map dengan _initializer list_.
    

## Operasi Dasar pada `unordered_map` di C++

---

### 1. Menyisipkan Elemen

Pasangan kunci‑nilai baru dapat dimasukkan ke dalam `unordered_map` menggunakan:

- Operator `[]`
    
- Fungsi `insert()`
    

> ⚠️ Jika kunci sudah ada, maka:

- `insert()` akan mengabaikan penyisipan.
    
- `[]` akan memperbarui nilai yang terkait dengan kunci tersebut.
    

#### Contoh:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, string> um;

    // Menyisipkan elemen dengan operator []
    um[1] = "Geeks";

    // Menyisipkan elemen dengan insert()
    um.insert({2, "For"});
    um.insert({3, "C++"});

    for (auto i : um)
        cout << i.first << ": " << i.second << endl;

    return 0;
}
```

#### Output:

```
3: C++
2: For
1: Geeks
```

---

### 2. Mengakses Elemen

Elemen dalam `unordered_map` dapat diakses menggunakan:

- Operator `[]`
    
- Fungsi `at()`
    

> ⚠️ Jika kunci tidak ditemukan:

- `[]` akan membuat entri baru dengan nilai default.
    
- `at()` akan melempar exception (`out_of_range`).
    

#### Contoh:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, string> um = {
        {1, "Geeks"}, {2, "For"}, {3, "C++"}
    };

    // Mengakses dengan operator []
    cout << um[2] << endl;

    // Mengakses dengan fungsi at()
    cout << um.at(1) << endl;

    return 0;
}
```

#### Output:

```
For
Geeks
```

---

### 3. Memperbarui Elemen

Elemen dapat diperbarui dengan:

- Menetapkan nilai baru menggunakan `[]` atau `at()`
    

> ⚠️ Jika kunci tidak ditemukan:

- `[]` akan membuat elemen baru.
    
- `at()` akan menyebabkan error.
    

#### Contoh:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, string> um = {
        {1, "Geeks"}, {2, "For"}, {3, "C++"}
    };

    // Memperbarui menggunakan operator []
    um[2] = "By";
    cout << um[2] << endl;

    // Memperbarui menggunakan fungsi at()
    um.at(1) = "Tips";
    cout << um.at(1) << endl;

    return 0;
}
```

#### Output:

```
By
Tips
```

**Penjelasan:**

- Nilai pada kunci `2` diubah menjadi `"By"` menggunakan `[]`.
    
- Nilai pada kunci `1` diubah menjadi `"Tips"` menggunakan `at()`.
    
### 4. Mencari Elemen

`unordered_map` menyediakan cara pencarian elemen secara efisien berdasarkan **kunci** menggunakan fungsi anggota `find()`.

- Fungsi ini mengembalikan iterator ke elemen jika ditemukan, atau
    
- `um.end()` jika tidak ditemukan.
    

#### Contoh:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, string> um = {
        {1, "Geeks"}, {2, "For"}, {3, "C++"}
    };

    // Mencari elemen dengan kunci 2
    auto it = um.find(2);

    if (it != um.end())
        cout << it->first << ": " << it->second;
    else
        cout << "Not Found";
    return 0;
}
```

#### Output:

```
2: For
```

---

### 5. Melakukan Traversal (Penelusuran)

Traversal (penelusuran) pada `unordered_map` berarti mengiterasi semua pasangan kunci-nilai yang disimpan dalam kontainer.

#### Cara pertama: menggunakan iterator (`begin()` hingga `end()`)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, string> um = {
        {1, "Geeks"}, {2, "For"}, {3, "C++"}
    };

    // Traversal menggunakan iterator
    for (auto it = um.begin(); it != um.end(); it++)
        cout << it->first << ": " << it->second << endl;

    return 0;
}
```

#### Output:

```
3: C++
1: Geeks
2: For
```

> ⚠️ Karena `unordered_map` **tidak menjamin urutan**, elemen bisa ditampilkan dalam urutan yang berbeda dari urutan penyisipannya.

---

### 6. Menghapus Elemen

Elemen dalam `unordered_map` dapat dihapus menggunakan fungsi `erase()`:

- Dengan memberikan **kunci** secara langsung.
    
- Dengan memberikan **iterator** ke elemen.
    

#### Contoh:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, string> um = {
        {1, "Geeks"}, {2, "For"}, {3, "C++"}
    };

    // Menghapus elemen dengan kunci 2
    um.erase(2);

    // Menghapus elemen pertama (ditunjuk oleh begin())
    um.erase(um.begin());

    // Menampilkan hasil setelah penghapusan
    for (auto it = um.begin(); it != um.end(); it++)
        cout << it->first << ": " << it->second << endl;

    return 0;
}
```

#### Output:

```
1: Geeks
```

#### Penjelasan:

- Pertama, pasangan dengan kunci `2` dihapus.
    
- Kemudian elemen **pertama** dalam map (sesuai iterator `begin()`) juga dihapus.
    
## Kompleksitas Waktu (`Time Complexity`)

Tabel berikut menunjukkan kompleksitas waktu rata-rata untuk operasi-operasi dasar pada `unordered_map`:

|**Operasi**|**Kompleksitas Waktu**|
|---|---|
|Menyisipkan elemen|O(1) _(rata-rata)_|
|Menghapus elemen berdasarkan kunci|O(1) _(rata-rata)_|
|Mengakses elemen berdasarkan kunci|O(1) _(rata-rata)_|
|Mencari elemen berdasarkan kunci|O(1) _(rata-rata)_|
|Memperbarui elemen berdasarkan kunci|O(1) _(rata-rata)_|
|Menelusuri seluruh `map`|O(n)|

### Catatan:

- Semua operasi di atas memiliki kompleksitas **rata-rata konstan (O(1))** karena `unordered_map` menggunakan struktur **hash table** di belakang layar.
    
- Namun dalam **kasus terburuk** (jika terjadi terlalu banyak _collision_ atau tabrakan hash), waktu akses bisa meningkat menjadi O(n), meskipun hal ini **jarang terjadi** jika fungsi hash dirancang dengan baik.
    
## 🔧 Cara Kerja Internal (`Internal Working`)

Dalam C++, `unordered_map` menyediakan implementasi internal dari struktur data **hash table**. Ia melakukan hashing hanya pada **kunci (key)** dari setiap elemen untuk menemukan indeks-nya di dalam tabel, dan menyimpan elemen sebagai pasangan **key-value**.

Karena menggunakan hashing, maka operasi seperti:

- **Penyisipan (insert)**
    
- **Penghapusan (delete)**
    
- **Pencarian (search)**
    

semuanya memiliki kompleksitas waktu **O(1)** dalam rata-rata (_amortized_).

---

## 🆚 Perbandingan `unordered_map` vs `map`

|Fitur|`unordered_map`|`map`|
|---|---|---|
|**Urutan Elemen**|Tidak terurut, berdasarkan nilai hash|Terurut secara naik (default: `std::less`)|
|**Struktur Dasar**|Hash Table|Balanced Binary Search Tree (biasanya Red-Black Tree)|
|**Kompleksitas Operasi**|Rata-rata O(1) untuk operasi dasar|O(log n) untuk operasi dasar|
|**Penggunaan Umum**|Saat performa kecepatan sangat penting|Saat urutan elemen dibutuhkan|

---

## 📚 Daftar Fungsi Anggota (`Member Functions`) dalam `std::unordered_map`

|Fungsi|Deskripsi|
|---|---|
|`at(k)`|Mengembalikan referensi ke nilai dari elemen dengan kunci `k`.|
|`operator[]`|Mengakses atau memperbarui nilai dari kunci tertentu.|
|`contains(k)`|Mengecek apakah terdapat elemen dengan kunci `k`.|
|`equal_range(k)`|Mengembalikan batas dari semua elemen yang memiliki kunci sama dengan `k`.|
|`begin()`|Iterator ke elemen pertama.|
|`end()`|Iterator ke posisi setelah elemen terakhir.|
|`cbegin()`|Iterator konstan ke elemen pertama.|
|`cend()`|Iterator konstan ke posisi setelah elemen terakhir.|
|`bucket(k)`|Nomor bucket tempat elemen dengan kunci `k` berada.|
|`bucket_count()`|Mengembalikan jumlah total bucket.|
|`bucket_size(i)`|Jumlah elemen dalam bucket ke-`i`.|
|`max_bucket_count()`|Jumlah maksimum bucket yang dapat ditampung.|
|`count(k)`|Mengembalikan 0 atau 1 apakah kunci `k` ada atau tidak.|
|`find(k)`|Iterator ke elemen dengan kunci `k`, atau `end()` jika tidak ditemukan.|
|`empty()`|Mengembalikan true jika `unordered_map` kosong.|
|`size()`|Jumlah elemen yang ada.|
|`max_size()`|Jumlah maksimum elemen yang dapat disimpan.|
|`erase(k)`|Menghapus elemen berdasarkan kunci.|
|`clear()`|Menghapus semua elemen.|
|`insert()`|Menyisipkan elemen tunggal.|
|`insert_range()`|Menyisipkan rentang elemen.|
|`emplace()`|Membuat dan menyisipkan elemen di tempat (in-place).|
|`emplace_hint()`|Menyisipkan elemen dengan petunjuk posisi.|
|`swap()`|Menukar isi dua `unordered_map`.|
|`extract()`|Mengeluarkan node dari `unordered_map`.|
|`merge()`|Menggabungkan dua `unordered_map` menjadi satu.|
