---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSMP-0002
nama_algoritma: 
kategori_algoritma: data structure
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
sumber: geeksforgeeks.org
date_learned: 2025-06-22T17:30:00
tags:
  - data-structure
  - map
---

---
# Map Data Structures in C++

## 📘 Map di C++

Dalam C++, **map** adalah _associative container_ yang menyimpan data dalam bentuk pasangan **key-value** (_kunci dan nilai_), yang secara default diurutkan berdasarkan **kunci**.  
Tidak boleh ada dua elemen dalam map yang memiliki kunci yang sama.

Secara bawaan, map menyimpan data dalam urutan **menaik (ascending)** berdasarkan kunci, namun urutan ini bisa diubah sesuai kebutuhan.

---

### 🔍 Contoh:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {

    // Membuat map dengan kunci bertipe int
    // dan nilai bertipe string
    map<int, string> m {{1, "Geeks"},
                        {2, "For"},
                        {3, "Geeks"}};

    for (auto& p : m)
        cout << p.first << " " << p.second << "\n";

    return 0;
}
```

### 💡 Output:

```
1 Geeks
2 For
3 Geeks
```

### 🧠 Penjelasan:

Pada program di atas, kita membuat sebuah map `m` dengan **kunci bertipe `int`** dan **nilai bertipe `string`**.  

Kita memasukkan tiga pasangan `key-value` ke dalam map: `{1, "Geeks"}`, `{2, "For"}`, dan `{3, "Geeks"}`.  

Map secara otomatis **mengurutkan kunci** dalam **urutan menaik** (ascending).

---

### 🔧 Sintaks:

Container `map` didefinisikan sebagai template class `std::map` yang berada di dalam header `<map>`.

```cpp
map<key_type, value_type, comp> m;
```

Penjelasan:

- `key_type`: Tipe data dari **kunci**.
    
- `value_type`: Tipe data dari **nilai**.
    
- `comp` _(opsional)_: Fungsi pembanding kustom yang menentukan bagaimana dua kunci dibandingkan untuk proses pengurutan.  Jika tidak disediakan, maka secara default kunci akan diurutkan dalam **urutan menaik**.
    
- `m`: Nama dari map yang dibuat.
    
# 🏗️ Deklarasi dan Inisialisasi Map

Kita bisa **mendeklarasikan dan menginisialisasi map** dalam beberapa cara berbeda, seperti pada contoh berikut:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Membuat map kosong
    map<int, string> m1;

    // Inisialisasi map menggunakan initializer list
    map<int, string> m2 = {
        {1, "Geeks"},
        {2, "For"},
        {3, "Geeks"}
    };

    for (auto& p : m2)
        cout << p.first << " " << p.second << endl;

    return 0;
}
```

### 💡 Output:

```
1 Geeks  
2 For  
3 Geeks
```

### 🧠 Penjelasan:

- Pernyataan `map<int, string> m1;` membuat sebuah **map kosong** tanpa elemen.
    
- Pernyataan `map<int, string> m2 = {{1, "Geeks"}, {2, "For"}, {3, "Geeks"}};` membuat sebuah map yang sudah langsung diisi dengan tiga pasangan **key-value**, menggunakan **initializer list**.
    

🔍 Untuk cara lain dalam menginisialisasi map, kamu bisa lihat artikel: _Different Ways to Initialize a Map_

---

# ⚙️ Operasi Dasar pada Map

Beberapa **operasi dasar** yang umum dilakukan pada `std::map` antara lain:

---

## 1. 🔼 Menyisipkan (Insert) Elemen

Kita bisa menyisipkan elemen ke dalam map dengan dua cara:

- Menggunakan **operator `[]`**
    
- Menggunakan **fungsi `insert()`**
    

> ⚠️ **Perbedaan penting:**

- Jika key **sudah ada**:
    
    - `insert()` → akan **mengabaikan** penyisipan.
        
    - `[]` → akan **mengubah nilai lama** menjadi nilai baru.
        

---

### 🧪 Contoh:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, string> m = {
        {2, "For"},
        {3, "Geeks"}
    };

    // Menyisipkan pasangan kunci-nilai
    m.insert({1, "Geeks"});

    for (auto x : m)
        cout << x.first << " " << x.second << endl;

    return 0;
}
```

### 💡 Output:

```
1 Geeks  
2 For  
3 Geeks
```

### 📌 Catatan:

- Kita **tidak bisa menentukan posisi penyisipan secara manual**, karena `map` akan **mengurutkan elemen secara otomatis** berdasarkan kunci.
    
- Untuk mempelajari lebih dalam tentang cara menyisipkan elemen ke dalam map, kamu bisa lihat artikel: _Different Ways to Insert Elements in a Map_
    
---

## 2. 🔍 Mengakses Elemen

Elemen dalam `map` dapat diakses menggunakan **operator `[]`** dengan memberikan **kunci** sebagai indeks.

- Jika **kunci tersebut ada**, maka akan mengembalikan **nilai yang terkait**.
    
- Jika **kunci tersebut tidak ada**, maka **elemen baru akan dibuat** dengan kunci tersebut dan **nilai default**.
    

Untuk **menghindari penambahan elemen yang tidak diinginkan**, kamu bisa menggunakan fungsi **`at()`**, yang hanya mengakses nilai **tanpa menambah** elemen baru.

---

### 🧪 Contoh:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, string> m = {
        {1, "Geeks"},
        {2, "For"},
        {3, "Geeks"}
    };

    // Mengakses elemen
    cout << m[1] << endl;    // akan mengakses nilai dengan kunci 1
    cout << m.at(2);         // akan mengakses nilai dengan kunci 2

    return 0;
}
```

### 💡 Output:

```
Geeks  
For
```

📌 Untuk metode lain dalam mengakses nilai pada `map`, kamu bisa lihat artikel: _Different Ways to Access a Value in a Map_

---

## 3. ✏️ Memperbarui Elemen

Kunci (`key`) dari elemen yang sudah ada tidak bisa diubah di dalam map.

Namun, nilai (`value`) yang terkait dengan kunci tersebut bisa diperbarui, yaitu dengan cara mengakses elemen tersebut lalu menggunakan operator penugasan ($=$) untuk mengganti nilainya.

---

### 🧪 Contoh:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, string> m = {
        {1, "Geeks"},
        {2, "For"},
        {3, "Geeks"}
    };

    // Memperbarui nilai
    m[0] = "Tweaks";     // Menambahkan elemen baru dengan key 0 dan nilai "Tweaks"
    m.at(1) = "By";      // Mengubah nilai elemen dengan key 1 menjadi "By"
    
    cout << m[0] << endl;
    cout << m.at(1);
    
    return 0;
}
```

### 💡 Output:

```
Tweaks  
By
```

### 🧠 Penjelasan:

- Ekspresi `m[0] = "Tweaks"` akan **menambah elemen baru** karena `0` belum ada sebelumnya.
    
- Ekspresi `m.at(1) = "By"` akan **mengubah nilai elemen dengan key 1**.
    

📌 Untuk metode lainnya dalam memperbarui nilai dalam map, kamu bisa lihat artikel: _Different Ways to Update Value of a Pair in Map_

## 4. 🔎 Mencari Elemen

`map` menyediakan cara pencarian elemen yang **cepat berdasarkan kunci** menggunakan fungsi anggota `find()`.

- Fungsi ini akan **mengembalikan iterator** ke elemen yang ditemukan.
    
- Jika elemen **tidak ditemukan**, maka akan mengembalikan `m.end()` (penanda akhir map).
    

---

### 🧪 Contoh:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, string> m = {
        {1, "Geeks"},
        {2, "For"},
        {3, "Geeks"}
    };

    // Mencari elemen dengan kunci 2
    auto it = m.find(2);

    if (it != m.end())
        cout << it->first << " " << it->second;
    else
        cout << "Key not Found!";

    return 0;
}
```

### 💡 Output:

```
2 For
```

📌 Untuk teknik lain dalam mengecek apakah suatu kunci ada dalam map, lihat artikel: _Check if Map Contains a Specific Key_

---

## 5. 🔁 Menelusuri (Traversing)

`map` bisa dengan mudah ditelusuri menggunakan:

- **range-based for loop**, atau
    
- **iterator klasik** dengan `begin()` dan `end()`
    

---

### 🧪 Contoh:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, string> m = {
        {1, "Geeks"},
        {2, "For"},
        {3, "Geeks"}
    };

    // Menelusuri menggunakan iterator
    for (auto it = m.begin(); it != m.end(); ++it)
        cout << it->first << " " << it->second << endl;

    return 0;
}
```

### 💡 Output:

```
1 Geeks  
2 For  
3 Geeks
```

📌 Untuk berbagai cara menelusuri elemen map, lihat artikel: _Different Ways to Traverse a Map_

---

## 6. ❌ Menghapus Elemen

Elemen dalam `map` bisa dihapus menggunakan fungsi `erase()`:

- dengan memberikan **kunci** sebagai parameter, atau
    
- dengan memberikan **iterator** yang menunjuk ke elemen yang ingin dihapus
    

---

### 🧪 Contoh:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, string> m = {
        {1, "Geeks"},
        {2, "For"},
        {3, "Geeks"}
    };

    // Menghapus elemen berdasarkan kunci
    m.erase(2);

    // Menghapus elemen pertama (berdasarkan iterator)
    m.erase(m.begin());

    for (auto i : m)
        cout << i.first << " " << i.second << endl;

    return 0;
}
```

### 💡 Output:

```
3 Geeks
```

📌 Untuk cara lain dalam menghapus elemen dari map, lihat artikel: _Different Ways to Delete Elements from Map_

---
# ⏱️ Kompleksitas Waktu (`Time Complexity`)

|Operasi|Kompleksitas Waktu|
|---|---|
|Menyisipkan elemen (`insert`)|`O(log n)`|
|Menghapus elemen berdasarkan key|`O(log n)`|
|Mengakses elemen berdasarkan key|`O(log n)`|
|Mencari elemen berdasarkan key|`O(log n)`|
|Memperbarui nilai berdasarkan key|`O(log n)`|
|Menelusuri seluruh isi map|`O(n)`|

---

# 🔧 Operasi Umum Lainnya pada Map

Berikut beberapa operasi umum lainnya yang sering digunakan pada `std::map`:

- ✅ Mengecek apakah map kosong (`empty`)
    
- 📏 Mengetahui ukuran map (`size`)
    
- 🔄 Menukar isi dua map (`swap`)
    
- 🔁 Mengonversi `vector<pair>` ke map
    
- 🔃 Mengurutkan map dengan urutan kustom
    
- 🧩 Membuat map dengan tipe data buatan pengguna (_user-defined type_)
    
- ➕ Menggabungkan dua map (_merge_)
    

---

# ⚙️ Cara Kerja Internal (`Internal Working`)

Di C++, `map` adalah sebuah _associative container_ yang secara internal **diimplementasikan menggunakan pohon Red-Black (RB Tree)**.

Karena menggunakan struktur **Red-Black Tree**, maka operasi seperti:

- penyisipan (`insert`),
    
- penghapusan (`erase`), dan
    
- pencarian (`find`)
    

semuanya berjalan dengan **kompleksitas waktu logaritmik `O(log n)`**, dan data selalu **tersimpan dalam urutan terurut berdasarkan kunci**.

---

# 📚 Daftar Lengkap Fungsi Anggota (`Member Functions`) pada `std::map`

|Fungsi|Deskripsi|
|---|---|
|`insert()`|Menyisipkan elemen dengan kunci tertentu ke dalam map.|
|`count()`|Mengembalikan jumlah elemen dengan kunci tertentu.|
|`equal_range()`|Mengembalikan pasangan iterator (awal dan akhir) untuk rentang kunci.|
|`erase()`|Menghapus elemen dari map (berdasarkan kunci atau iterator).|
|`begin()`|Iterator ke elemen pertama dalam map.|
|`end()`|Iterator ke satu posisi setelah elemen terakhir dalam map.|
|`rbegin()`|_Reverse iterator_ ke elemen terakhir dalam map.|
|`rend()`|_Reverse iterator_ ke elemen sebelum elemen pertama.|
|`find()`|Mengembalikan iterator ke elemen dengan kunci tertentu (atau `end()` jika tidak ada).|
|`crbegin()`|_Const reverse iterator_ ke elemen terakhir.|
|`crend()`|_Const reverse iterator_ ke sebelum elemen pertama.|
|`cbegin()`|_Const iterator_ ke elemen pertama.|
|`cend()`|_Const iterator_ ke posisi setelah elemen terakhir.|
|`emplace()`|Menyisipkan elemen dengan efisiensi langsung di tempat.|
|`max_size()`|Mengembalikan kapasitas maksimum map.|
|`upper_bound()`|Mengembalikan iterator ke elemen pertama dengan kunci > dari kunci yang diberikan.|
|`lower_bound()`|Mengembalikan iterator ke elemen pertama dengan kunci ≥ dari kunci yang diberikan.|
|`emplace_hint()`|Menyisipkan elemen dengan petunjuk posisi iterator untuk efisiensi.|
|`value_comp()`|Mengembalikan fungsi pembanding untuk nilai elemen (`<` secara default).|
|`key_comp()`|Mengembalikan fungsi pembanding untuk kunci (`<` secara default).|
|`size()`|Mengembalikan jumlah elemen dalam map.|
|`empty()`|Mengecek apakah map kosong.|
|`clear()`|Menghapus semua elemen dari map.|
|`at()`|Mengakses elemen berdasarkan kunci tanpa membuat elemen baru.|
|`swap()`|Menukar isi dua map (harus bertipe sama).|
