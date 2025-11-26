---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSML-0002
nama_algoritma: 
kategori_algoritma: data structure
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
sumber: geeksforgeeks.org
date_learned: 2025-06-23T19:57:00
tags:
  - data-structure
  - multimap
---
---
# 🧭 Multimap di C++ STL

Di C++, `multimap` adalah **kontainer asosiatif** yang mirip dengan `map`, tetapi `multimap` dapat menyimpan **beberapa elemen dengan key (kunci) yang sama**.

Secara default, `multimap` akan menyimpan semua elemen dalam **urutan menaik berdasarkan key**. Namun, urutan ini dapat diubah jika diperlukan (misalnya dengan custom comparator).

Multimap menyediakan **operasi cepat** untuk **penyisipan (insertion)**, **penghapusan (deletion)**, dan **pencarian (search)** pada data yang sudah diurutkan ini.

---

### 📌 Contoh:

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    // Membuat multimap dengan key bertipe int dan value bertipe string
    multimap<int, string> mm = {
        {1, "Geeks"}, 
        {2, "For"}, 
        {1, "C++"}, 
        {2, "STL"}
    };

    for (auto i : mm) 
        cout << i.first << ": " << i.second << "\n";

    return 0;
}
```

**Output:**

```
1: Geeks
1: C++
2: For
2: STL
```

---

### 🔍 Penjelasan:

Dalam program di atas, kita membuat sebuah `multimap` dan memasukkan 4 pasangan key-value:

- `{1, "Geeks"}`
    
- `{2, "For"}`
    
- `{1, "C++"}`
    
- `{2, "STL"}`
    

Karena `multimap` **mengizinkan duplikat key**, maka semua pasangan ini disimpan, meskipun key-nya sama. Dalam output, elemen diurutkan berdasarkan **key secara menaik**, dan entri dengan key yang sama disimpan dalam urutan sesuai penambahan (urutan stabil).

---

### 🧬 Sintaks Dasar

`multimap` didefinisikan sebagai **template class** `std::multimap` di dalam header `<map>`.

```cpp
multimap<key_type, value_type, comp> mm;
```

Keterangan:

- `key_type`: Tipe data dari **key**
    
- `value_type`: Tipe data dari **value**
    
- `comp`: _Comparator_ khusus yang digunakan untuk mengatur urutan key (opsional). Jika tidak diberikan, maka data akan diurutkan berdasarkan **urutan menaik** dari key.
    
- `mm`: Nama multimap yang digunakan dalam program.
    

---

✅ **Catatan tambahan**:

- `multimap` cocok digunakan ketika kita perlu menyimpan **beberapa entri untuk satu key** (misalnya: siswa dengan beberapa nilai, kota dengan beberapa kode pos, dsb).
    
- Berbeda dari `unordered_multimap`, `multimap` menjaga **urutan elemen** berdasarkan key, yang sangat berguna untuk **iterasi terurut**.

---
# 📌 Deklarasi dan Inisialisasi Multimap

Kita dapat mendeklarasikan dan menginisialisasi `multimap` dengan berbagai cara, seperti yang ditunjukkan pada contoh berikut:

---

### 📄 Contoh Kode

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {

    // Membuat multimap kosong
    multimap<int, string> mm1;

    // Membuat multimap dengan initializer list
    multimap<int, string> mm2 = {
        {1, "Geeks"},
        {2, "For"},
        {1, "C++"}
    };

    for (auto i : mm2)
        cout << i.first << ": " << i.second << endl;

    return 0;
}
```

---

### 🖨️ Output

```
1: Geeks
1: C++
2: For
```

---

### 🔍 Penjelasan:

Dalam contoh di atas:

- Pernyataan:
    
    ```cpp
    multimap<int, string> mm1;
    ```
    
    Membuat sebuah `multimap` kosong bernama `mm1`. Ini disebut **default initialization** atau inisialisasi default.
    
- Pernyataan:
    
    ```cpp
    multimap<int, string> mm2 = {{1, "Geeks"}, {2, "For"}, {1, "C++"}};
    ```
    
    Menginisialisasi `multimap` bernama `mm2` menggunakan **initializer list**, yang langsung mengisinya dengan tiga pasangan key-value.
    

---

### ✍️ Penjelasan Tambahan:

- Karena `multimap` mengizinkan key yang **duplikat**, maka dua entri `{1, "Geeks"}` dan `{1, "C++"}` keduanya disimpan.
    
- `multimap` otomatis **mengurutkan berdasarkan key secara menaik**, sehingga output-nya ditampilkan dalam urutan:
    
    ```
    1: Geeks
    1: C++
    2: For
    ```
    
- `#include <bits/stdc++.h>` merupakan header gabungan yang umum dipakai di lingkungan kompetitif (CP), tetapi di produksi biasanya lebih baik memakai header spesifik: `#include <map>`, `#include <iostream>`, dll.

---
# ⚙️ Operasi Dasar pada Multimap

Operasi-operasi dasar yang bisa dilakukan pada kontainer `multimap` ditunjukkan di bawah ini:

---

## ✅ 1. Menyisipkan Elemen

Pasangan key-value dapat dimasukkan ke dalam `multimap` menggunakan metode `insert()`.  
Penggunaan operator `[]` **tidak valid pada multimap**, karena satu key bisa memiliki **lebih dari satu value**. Operator `[]` hanya tersedia pada `map`, yang tidak mengizinkan duplikasi key.

---

### 📄 Contoh Kode

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    multimap<int, string> mm;

    // Menyisipkan pasangan key-value
    mm.insert({1, "Geeks"});
    mm.insert({2, "For"});
    mm.insert({1, "C++"});

    for(auto x: mm)
        cout << x.first << ": " << x.second << endl;

    return 0;
}
```

---

### 🖨️ Output

```
1: Geeks
1: C++
2: For
```

---

### 🔍 Penjelasan:

- Tiga pasangan `(key, value)` dimasukkan ke dalam `multimap`, termasuk dua entri dengan key yang sama (`1`).
    
- Karena `multimap` mengizinkan **key duplikat**, kedua entri dengan key `1` tetap disimpan.
    

---

### 📌 Catatan Tambahan:

- **Urutan elemen dengan key yang sama** ditentukan oleh **urutan penyisipan**.
    
- Urutan keseluruhan tetap berdasarkan **urutan menaik dari key**, karena `multimap` secara default menggunakan `std::less<Key>` untuk mengurutkan.
    
- Jika ingin menyisipkan elemen menggunakan operator `[]`, kamu perlu menggunakan `map`, **bukan multimap**.

---
## 🔍 2. Mengakses Elemen

Elemen-elemen pada `multimap` hanya bisa diakses menggunakan **iterator**.  
Untuk mengambil nilai:

- **Key** diakses lewat anggota `.first`
    
- **Value** diakses lewat anggota `.second`
    
- Digunakan operator `->` untuk mengakses dari iterator
    

Seperti yang telah disebutkan sebelumnya, operator `[]` **tidak bisa digunakan** di `multimap`, karena tidak unik (bisa ada banyak value untuk satu key).

Kita dapat menggunakan fungsi `next()` dan `advance()` untuk memindahkan iterator ke posisi tertentu.

Namun, kita bisa dengan cepat mengakses elemen **pertama** dan **terakhir** menggunakan iterator `begin()` dan `end()`.

---

### 📄 Contoh Kode

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    multimap<int, string> mm = {
        {1, "Geeks"},
        {2, "For"},
        {1, "C++"}
    };
    
    // Mengakses elemen pertama
    auto f = mm.begin();
    cout << f->first << ": " << f->second << endl;
    
    // Mengakses elemen kedua
    auto it = next(f, 1);
    cout << it->first << ": " << it->second;

    return 0;
}
```

---

### 🖨️ Output

```
1: Geeks
1: C++
```

---

### 🔍 Penjelasan:

- `mm.begin()` mengembalikan iterator ke elemen **pertama** dalam `multimap`, yaitu `{1, "Geeks"}`.
    
- `next(f, 1)` menggeser iterator `f` satu langkah ke depan untuk mengakses elemen **kedua**.
    
- Setelah mendapatkan iterator tersebut (`it`), kita gunakan `it->first` untuk mengakses **key**, dan `it->second` untuk mengakses **value**.
    

---

### 💡 Catatan Tambahan:

- `end()` menunjukkan **posisi setelah elemen terakhir** (yaitu sentinel), bukan elemen terakhir itu sendiri.
    
- `next(it, n)` adalah shortcut dari `advance(it, n); return it;`
    
- Karena `multimap` **mengurutkan secara otomatis** berdasarkan key, iterasi dari `begin()` akan menjelajahi elemen dalam urutan menaik dari key.
---
## ✏️ 3. Memperbarui Elemen

Pada `multimap`, **key dari suatu elemen tidak dapat diubah** setelah elemen tersebut dimasukkan.  
Namun, kita bisa **memodifikasi value-nya** menggunakan iterator yang menunjuk ke elemen tersebut.

---

### 📄 Contoh Kode

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    multimap<int, string> mm = {
        {1, "Geeks"},
        {2, "For"},
        {1, "C++"}
    };

    // Memperbarui value dari elemen kedua
    auto it = next(mm.begin(), 1);
    it->second = "Java";

    for (auto x : mm)
        cout << x.first << ": " << x.second << endl;

    return 0;
}
```

---

### 🖨️ Output

```
1: Geeks
1: Java
2: For
```

---

### 🔍 Penjelasan:

- Multimap `mm` awalnya memiliki tiga entri: `{1, "Geeks"}`, `{2, "For"}`, `{1, "C++"}`
    
- `mm.begin()` mengarah ke elemen pertama → `{1, "Geeks"}`
    
- `next(mm.begin(), 1)` menggeser iterator ke elemen kedua → `{1, "C++"}`
    
- Lalu kita **mengubah value-nya menjadi "Java"** menggunakan:
    
    ```cpp
    it->second = "Java";
    ```
    

Hasil akhirnya:

- Elemen `{1, "C++"}` telah berubah menjadi `{1, "Java"}`
    

---

### ⚠️ Catatan Penting:

- C++ `multimap` **tidak mengizinkan perubahan pada key** karena key digunakan untuk menjaga urutan.
    
- Jika ingin mengganti key, satu-satunya cara adalah:
    
    1. Hapus elemen lama
        
    2. Tambahkan kembali elemen dengan key baru
        
---

## 🔁 4. Menelusuri (Traversing)

`multimap` dapat ditelusuri (diiterasi) dengan dua cara utama:

1. Menggunakan **range-based for loop**
    
2. Menggunakan iterator dengan `begin()` dan `end()` dalam sebuah loop manual
    

---

### 📄 Contoh Kode

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    multimap<int, string> mm = {
        {1, "Geeks"},
        {2, "For"},
        {1, "C++"}
    };

    // Menelusuri multimap dengan iterator manual
    for(auto it = mm.begin(); it != mm.end(); it++)
        cout << it->first << " " << it->second << "\n";

    return 0;
}
```

---

### 🖨️ Output

```
1 Geeks
1 C++
2 For
```

---

### 🔍 Penjelasan:

- Multimap `mm` berisi tiga entri:
    
    ```
    {1, "Geeks"}, {2, "For"}, {1, "C++"}
    ```
    
- Elemen-elemen ditampilkan **berdasarkan urutan key menaik**, sesuai sifat dasar `multimap`.
    
- Karena ada dua entri dengan key `1`, keduanya tetap ditampilkan sesuai urutan penyisipan.
    

---

### 📌 Penjelasan Tambahan:

- `it->first` digunakan untuk mengambil **key**
    
- `it->second` digunakan untuk mengambil **value**
    
- Perulangan `for(auto it = mm.begin(); it != mm.end(); it++)` adalah cara umum untuk mengakses setiap elemen dalam `multimap` saat kamu ingin kontrol penuh atas iterator (misalnya saat ingin menghapus elemen sambil menelusuri)

## 🔍 5. Menemukan Elemen

`multimap` memungkinkan pencarian cepat berdasarkan **key** menggunakan fungsi `find()`.  
Fungsi ini mengembalikan **iterator ke elemen pertama** yang memiliki key tersebut.

Jika key **tidak ditemukan**, maka fungsi ini akan mengembalikan **iterator `end()`**, yaitu iterator yang menunjuk ke posisi setelah elemen terakhir.

Jika kamu ingin menemukan elemen tertentu **di antara beberapa elemen yang memiliki key yang sama**, kamu bisa mencarinya dalam **rentang** yang dikembalikan oleh fungsi `equal_range()`.

---

### 📄 Contoh Kode: Mencari Elemen

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    multimap<int, string> mm = {
        {1, "Geeks"},
        {2, "For"},
        {1, "C++"}
    };

    // Mencari elemen dengan key 2
    auto it = mm.find(2);

    cout << it->first << ": " << it->second;
    return 0;
}
```

---

### 🖨️ Output

```
2: For
```

---

### ✍️ Penjelasan Tambahan:

- Karena hanya ada **satu entri dengan key `2`**, fungsi `find(2)` langsung menunjuk ke elemen itu.
    
- Jika ada beberapa entri dengan key yang sama, `find()` hanya akan **mengembalikan iterator ke yang pertama**.
    
- Untuk menelusuri **semua** elemen dengan key tertentu, gunakan `equal_range()`.
    

---

## ❌ 6. Menghapus Elemen

Elemen dalam `multimap` dapat dihapus menggunakan fungsi `erase()`, dengan dua cara:

1. **Menghapus berdasarkan key**  
    Jika kita memberikan key ke `erase()`, **semua elemen** dengan key tersebut akan dihapus.
    
2. **Menghapus berdasarkan iterator**  
    Jika kita memberikan iterator ke `erase()`, maka hanya **satu elemen yang ditunjuk iterator** tersebut yang akan dihapus.
    

---

### 📄 Contoh Kode: Menghapus Elemen

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    multimap<int, string> mm = {
        {1, "Geeks"},
        {2, "For"},
        {1, "C++"}
    };

    // Menghapus semua elemen dengan key 2
    mm.erase(2);

    // Menghapus satu elemen pertama dengan key 1
    mm.erase(mm.find(1));

    for (auto x: mm)
        cout << x.first << ": " << x.second;

    return 0;
}
```

---

### 🖨️ Output

```
1: C++
```

---

### ✍️ Penjelasan Tambahan:

- Setelah `mm.erase(2);`, elemen `{2, "For"}` dihapus.
    
- Setelah `mm.erase(mm.find(1));`, hanya **satu** dari dua elemen dengan key `1` yang dihapus (yaitu `{1, "Geeks"}`).
    
- Elemen `{1, "C++"}` tetap ada dan ditampilkan sebagai output.
    

# Lebih dalam mengenai Multimap

## ⏱️ Kompleksitas Waktu (Time Complexity)

Tabel berikut menunjukkan kompleksitas waktu dari berbagai operasi pada `multimap`:

|Operasi|Kompleksitas Waktu|
|---|---|
|Menyisipkan elemen (`insert`)|O(log n)|
|Menghapus elemen (`erase`)|O(log n)|
|Mengakses elemen pada posisi tertentu (iterator)|O(n)|
|Mencari elemen berdasarkan key (`find`)|O(log n)|
|Mengetahui jumlah elemen dengan key tertentu (`count`)|O(log n)|
|Menelusuri seluruh isi `multimap` (`traverse`)|O(n)|

---

## 🛠️ Operasi Lain yang Umum

Berikut ini adalah contoh-contoh tambahan untuk membantumu menguasai operasi `multimap` lebih dari sekadar dasar:

- ✅ Cek Ukuran Multimap (`size()`)
    
- ❓ Cek Apakah Kosong (`empty()`)
    
- 🔄 Tukar Isi Dua Multimap (`swap()`)
    
- 🔢 Temukan Frekuensi Key (`count()`)
    
- 🔁 Temukan Semua Kemunculan Key (`equal_range()`)
    
- 📜 Cetak Semua Elemen dengan Key Tertentu
    
- 🔑 Simpan `vector` sebagai Key di Multimap
    
- ⚖️ Gunakan Komparator Kustom
    
- ⚙️ Cara Kerja Internal
    

---

## ⚙️ Cara Kerja Internal

`multimap` adalah **kontainer asosiatif** yang menyediakan implementasi built-in dari struktur data **Red-Black Tree**.

Red-Black Tree adalah **binary search tree yang self-balancing**. Ini menyimpan data dalam urutan tertentu dan menyediakan kompleksitas waktu **logaritmik** untuk operasi:

- **insert** (penyisipan)
    
- **delete** (penghapusan)
    
- **search** (pencarian)
    

Di dalam `multimap`, **key yang duplikat** disimpan sesuai dengan **urutan penyisipan**, sehingga kita bisa memiliki **lebih dari satu elemen dengan key yang sama**.

---

## 🆚 Perbandingan: Multimap vs Map

|Map|Multimap|
|---|---|
|Hanya mengizinkan **satu elemen per key**|Mengizinkan **banyak elemen dengan key yang sama**|

---

## 📚 Daftar Fungsi Anggota `std::multimap`

Berikut ini adalah seluruh fungsi anggota (`member functions`) yang tersedia di kelas `std::multimap`:

|Fungsi|Deskripsi|
|---|---|
|`crbegin()`|Mengembalikan **constant reverse iterator** ke elemen terakhir.|
|`crend()`|Mengembalikan iterator ke elemen sebelum elemen pertama (reverse end).|
|`emplace_hint()`|Menyisipkan elemen dengan **petunjuk posisi** tertentu.|
|`clear()`|Menghapus seluruh elemen.|
|`empty()`|Mengembalikan apakah multimap kosong.|
|`max_size()`|Mengembalikan jumlah maksimum elemen yang bisa ditampung.|
|`value_comp()`|Mengembalikan fungsi pembanding value (default-nya `operator<`).|
|`rbegin()`|Iterator ke elemen terakhir.|
|`rend()`|Reverse iterator ke sebelum elemen pertama.|
|`cbegin()`|Constant iterator ke elemen pertama.|
|`cend()`|Constant iterator ke posisi setelah elemen terakhir.|
|`swap()`|Menukar isi dua multimap dengan tipe dan ukuran yang sama.|
|`size()`|Mengembalikan jumlah elemen saat ini.|
|`emplace()`|Menyisipkan elemen langsung (tanpa membuat pair).|
|`begin()`|Iterator ke elemen pertama.|
|`end()`|Iterator ke elemen setelah elemen terakhir.|
|`lower_bound()`|Menemukan iterator ke elemen **>= key**.|
|`upper_bound()`|Menemukan iterator ke elemen **> key**.|
|`count()`|Menghitung jumlah elemen dengan key tertentu.|
|`erase()`|Menghapus elemen, baik berdasarkan key atau iterator.|
|`find()`|Mengembalikan iterator ke elemen dengan key tertentu, atau `end()` jika tidak ditemukan.|
|`equal_range()`|Mengembalikan pasangan iterator yang mencakup semua elemen dengan key yang sama.|
|`insert()`|Menyisipkan elemen ke dalam multimap.|
|`insert_range()`|Menyisipkan **beberapa elemen sekaligus** dari range lain.|
|`merge()`|Menggabungkan dua `multimap` (atau multiset).|
|`key_comp()`|Mengembalikan objek pembanding key (`<` secara default).|
