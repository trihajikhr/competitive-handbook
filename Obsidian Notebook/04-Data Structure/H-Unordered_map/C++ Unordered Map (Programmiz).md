---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSUM-0001
nama_algoritma: 
kategori_algoritma: data structure
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
sumber: programiz.com
date_learned: 2025-06-16T11:19:00
tags:
  - data-structure
  - unordered_map
---
---
# C++ Unordered Map

Dalam C++, **STL `unordered_map`** adalah sebuah _container_ asosiatif tak terurut yang menyediakan fungsionalitas struktur data berupa _unordered map_ atau _dictionary_.

Berbeda dengan `map` biasa, urutan kunci dalam `unordered_map` **tidak terdefinisi**.

![[C++ Unordered Map-2.png|500]]

Selain itu, `unordered_map` diimplementasikan menggunakan **struktur data hash table**, sedangkan `map` biasa menggunakan **struktur data pohon pencarian biner** (_binary search tree_).

---

## Membuat `unordered_map` di C++ STL

Untuk membuat `unordered_map` di C++, kita perlu menyertakan berkas header `unordered_map` terlebih dahulu:

```cpp
#include <unordered_map>
```

Setelah mengimpor file tersebut, kita bisa membuat `unordered_map` dengan sintaks berikut:

```cpp
unordered_map<tipe_kunci, tipe_nilai> ump;
```

Penjelasan:

- `tipe_kunci` menunjukkan tipe data untuk kunci (_key_)
    
- `tipe_nilai` menunjukkan tipe data untuk nilai (_value_)
    

Contoh:

```cpp
// Membuat unordered_map dengan kunci dan nilai bertipe int
unordered_map<int, int> ump_integer;

// Membuat unordered_map dengan kunci string dan nilai bertipe int
unordered_map<string, int> ump_string;
```

---

## Inisialisasi `unordered_map`

Kita bisa menginisialisasi `unordered_map` C++ dengan beberapa cara berikut:

```cpp
// Daftar Inisialisasi (Initializer List)
unordered_map<string, int> unordered_map1 = {
  {"One", 1},
  {"Two", 2},
  {"Three", 3}
};

// Inisialisasi Seragam (Uniform Initialization)
unordered_map<string, int> unordered_map2 {
  {"One", 1},
  {"Two", 2},
  {"Three", 3}
};
```

Pada contoh di atas, kita menginisialisasi `unordered_map` dengan langsung memberikan pasangan nilai.

Dengan demikian, baik `unordered_map1` maupun `unordered_map2` berisi data:

```cpp
{{"One", 1}, {"Two", 2}, {"Three", 3}}
```

### Contoh kode C++ `unordered_map`

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

  // inisialisasi seragam (uniform initialization)
  unordered_map<string, int> unordered_map1  {
    {"One", 1},
    {"Two", 2},
    {"Three", 3}
  };

  cout << "Kunci - Nilai" << endl;

  // melakukan perulangan pada unordered_map
  // menampilkan pasangan kunci-nilai
  for(const auto& key_value: unordered_map1) {
    string key = key_value.first;
    int value = key_value.second;
    
    cout << key << " - " << value << endl;
  }
  
  return 0;
}
```

---

### 📌 Penjelasan Baris per Baris:

1. `#include <iostream>`  
    Menyertakan pustaka untuk input-output standar (seperti `cout`).
    
2. `#include <unordered_map>`  
    Menyertakan pustaka untuk menggunakan struktur data `unordered_map`.
    
3. `using namespace std;`  
    Menghindari penulisan awalan `std::` untuk setiap fungsi/tipe dari namespace standar.
    
4. `unordered_map<string, int> unordered_map1 { ... };`  
    Membuat dan menginisialisasi `unordered_map` dengan tiga pasangan:
    
    - `"One" → 1`
        
    - `"Two" → 2`
        
    - `"Three" → 3`
        
5. `cout << "Kunci - Nilai" << endl;`  
    Menampilkan header kolom.
    
6. `for (const auto& key_value : unordered_map1)`  
    Melakukan iterasi untuk setiap pasangan (kunci-nilai) dalam `unordered_map`.
    
7. `key = key_value.first; value = key_value.second;`  
    Mengambil kunci dan nilai dari pasangan tersebut.
    
8. `cout << key << " - " << value << endl;`  
    Menampilkan kunci dan nilai pada satu baris.
    

---

### 🔎 Catatan Penting:

- **Urutan keluaran tidak terjamin** karena `unordered_map` menggunakan _hash table_.
    
- Kode ini akan mencetak semua pasangan `key-value` dari map yang telah diinisialisasi.
    
### 💡 Output

```
Kunci - Nilai  
Three - 3  
Two - 2  
One - 1  
```

---

### 📘 Penjelasan:

Dalam contoh di atas, kita telah **mendeklarasikan dan menginisialisasi** sebuah `unordered_map` bernama `unordered_map1` menggunakan **uniform initialization**:

```cpp
unordered_map<string, int> unordered_map1 {
  {"One", 1},
  {"Two", 2},
  {"Three", 3}
};
```

Lalu, kita menampilkan isi dari `unordered_map` tersebut menggunakan **perulangan for berbasis rentang (range-based for loop)**:

```cpp
for(const auto& key_value: unordered_map1) {
  string key = key_value.first;
  int value = key_value.second;    
  cout << key << " - " << value << endl;
}
```

---

### 🔍 Apa yang terjadi di dalam loop?

- Setiap elemen dari `unordered_map` (berupa pasangan **kunci-nilai**) disimpan ke dalam variabel `key_value`.
    
- Kita kemudian mengambil nilai kunci dan nilainya menggunakan:
    
    - `key_value.first` → memberikan **kunci**
        
    - `key_value.second` → memberikan **nilai**
        

---

### ⚠️ Perhatikan:

Walaupun kita membuat `unordered_map` dengan urutan kunci `"One"`, `"Two"`, `"Three"`, **output-nya muncul dalam urutan yang tidak terdefinisi**.

Hal ini karena:

- Elemen dalam `unordered_map` **tidak disimpan berdasarkan urutan** kunci atau nilai.
    
- Penyimpanan dilakukan berdasarkan **fungsi hash internal**, sehingga urutannya **acak**.
    

---

### 🆕 Catatan (C++17 dan versi lebih baru):

Sejak C++17, kamu dapat menggunakan **structure bindings** untuk menyederhanakan penulisan kode:

```cpp
for(const auto& [key, value]: unordered_map1) {
  cout << key << " - " << value << endl; 
}
```

Pendekatan ini membuat kode lebih ringkas dan mudah dibaca, karena kita langsung memecah pasangan `key_value` menjadi variabel `key` dan `value`.

### 🔄 Cara Lain untuk Menginisialisasi `unordered_map` di C++

#### 📌 Menyalin satu `unordered_map` ke `unordered_map` lain

Kita dapat menyalin isi dari satu `unordered_map` ke `unordered_map` lainnya menggunakan **metode inisialisasi dengan rentang (_range method initialization_)**.

```cpp
unordered_map<string, int> unordered_map_1 {
  {"One", 1},
  {"Two", 2},
  {"Three", 3}
};

unordered_map<string, int> unordered_map_2(unordered_map_1.begin(), unordered_map_1.end());
```

---

### 💡 Penjelasan:

1. Pertama, kita membuat sebuah `unordered_map` bernama `unordered_map_1` yang berisi tiga pasangan kunci-nilai:
    
    - `"One" → 1`
        
    - `"Two" → 2`
        
    - `"Three" → 3`
        
2. Kemudian, kita membuat `unordered_map` lain bernama `unordered_map_2` dengan **menyalin seluruh elemen** dari `unordered_map_1` menggunakan rentang iterasi:
    
    - `unordered_map_1.begin()` → iterator awal
        
    - `unordered_map_1.end()` → iterator akhir
        

Dengan pendekatan ini, `unordered_map_2` akan memiliki **salinan yang identik** dari semua elemen dalam `unordered_map_1`.

Berikut terjemahan lengkap materi tersebut ke dalam Bahasa Indonesia:

## 📚 Metode-Metode pada `unordered_map` di C++

Dalam C++, kelas `unordered_map` menyediakan berbagai metode untuk melakukan operasi pada _unordered map_.

|Metode|Deskripsi|
|---|---|
|`insert()`|Menyisipkan satu atau lebih pasangan kunci-nilai|
|`count()`|Mengembalikan 1 jika kunci ada, dan 0 jika tidak ada|
|`find()`|Mengembalikan iterator ke elemen dengan kunci yang ditentukan|
|`at()`|Mengakses elemen berdasarkan kunci tertentu|
|`size()`|Mengembalikan jumlah elemen dalam map|
|`empty()`|Mengembalikan `true` jika map kosong|
|`erase()`|Menghapus elemen berdasarkan kunci tertentu|
|`clear()`|Menghapus semua elemen dari map|

---

## ➕ Menyisipkan Pasangan Kunci-Nilai ke dalam `unordered_map`

Kita dapat menyisipkan pasangan kunci-nilai ke dalam `unordered_map` menggunakan:

- **`insert()`** → menyisipkan pasangan kunci-nilai
    
- **`[]` (operator indeks)** → menyisipkan kunci dan nilai
    

### Contoh:

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

  unordered_map<string, int> unordered_map1;
  
  // menyisipkan pasangan {"One", 1}
  unordered_map1["One"] = 1;

  // menyisipkan pasangan {"Two", 2}
  unordered_map1.insert({"Two", 2});

  // menyisipkan dua pasangan sekaligus: {"Three", 3}, {"Four", 4}	
  unordered_map1.insert({{"Three", 3}, {"Four", 4}});
  
  cout << "Kunci - Nilai" << endl;

  // menampilkan semua elemen dari unordered_map1   
  for(const auto& key_value: unordered_map1) {
    string key = key_value.first;
    int value = key_value.second;
    
    cout << key << " - " << value << endl;
  }
 
  return 0;
}
```

---

### 🖨️ Output:

```
Kunci - Nilai  
Four - 4  
Two - 2  
Three - 3  
One - 1  
```

---

### 📌 Penjelasan:

1. Kita membuat `unordered_map` kosong untuk menyimpan pasangan `string` dan `int`.
    
2. Menyisipkan pasangan `{"One", 1}` menggunakan **operator indeks**:
    
    ```cpp
    unordered_map1["One"] = 1;
    ```
    
3. Menyisipkan pasangan `{"Two", 2}` menggunakan metode **`insert()`**:
    
    ```cpp
    unordered_map1.insert({"Two", 2});
    ```
    
4. Menyisipkan **dua pasangan sekaligus** menggunakan `insert()` dan initializer list:
    
    ```cpp
    unordered_map1.insert({{"Three", 3}, {"Four", 4}});
    ```
    

---

🔎 Seperti sebelumnya, urutan keluaran **tidak dijamin** karena `unordered_map` menggunakan struktur data _hash table_, bukan struktur terurut.

## 🔍 Mengakses Nilai dari `unordered_map`

Kita dapat menggunakan dua metode berikut untuk **mengakses nilai berdasarkan kunci tertentu** pada `unordered_map`:

|Metode|Deskripsi|
|---|---|
|`at()`|Mengembalikan nilai untuk kunci tertentu|
|`[]`|Mengembalikan nilai untuk kunci tertentu|

### Contoh:

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  unordered_map<string, string> capital_city {
    {"Nepal", "Kathmandu"},
    {"India", "New Delhi"},
    {"Australia", "Canberra"}
  };
  
  cout << "Ibu kota Nepal adalah " << capital_city["Nepal"] << endl;
  cout << "Ibu kota Australia adalah " << capital_city.at("Australia");
  
  return 0;
}
```

### 🖨️ Output:

```
Ibu kota Nepal adalah Kathmandu  
Ibu kota Australia adalah Canberra  
```

### 📌 Penjelasan:

- `capital_city["Nepal"]` → mengakses nilai dari kunci `"Nepal"`
    
- `capital_city.at("Australia")` → mengakses nilai dari kunci `"Australia"`
    

---

### ⚠️ Catatan Penting:

Walaupun kita **bisa menggunakan `[]`** untuk mengakses elemen, **lebih disarankan menggunakan `at()`**.

Kenapa?

- `at()` akan **melempar pengecualian (exception)** jika kunci tidak ditemukan.
    
- Sedangkan `[]` akan **secara otomatis menambahkan kunci baru** dengan **nilai tak terdefinisi (garbage value)**.
    

### Contoh:

```cpp
cout << "Ibu kota Jepang adalah: " << capital_city["Japan"];
```

Jika `"Japan"` belum ada, maka **elemen baru `"Japan"` akan ditambahkan** ke dalam map dengan nilai kosong/tak terdefinisi. Ini bisa menyebabkan **bug tersembunyi**.

---

## ✏️ Mengubah Nilai dalam `unordered_map`

Kita bisa menggunakan `[]` atau `at()` untuk **mengubah nilai** dari kunci tertentu dalam `unordered_map`.

### Contoh:

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  unordered_map<string, string> capital_city {
    {"India", "Calcutta"},
    {"Pakistan", "Karachi"},
  };
  
  cout << "Ibu Kota Lama:" << endl;
  cout << "India : " << capital_city["India"] << endl;
  cout << "Pakistan : " << capital_city["Pakistan"];
 
  // ubah nilai untuk "India" menggunakan []
  capital_city["India"] = "New Delhi";

  // ubah nilai untuk "Pakistan" menggunakan at()
  capital_city.at("Pakistan") = "Islamabad";
  
  cout << "\n\nIbu Kota Baru:" << endl;
  cout << "India : " << capital_city["India"] << endl;
  cout << "Pakistan : " << capital_city["Pakistan"];
  
  return 0;
}
```

### 🖨️ Output:

```
Ibu Kota Lama:  
India : Calcutta  
Pakistan : Karachi  

Ibu Kota Baru:  
India : New Delhi  
Pakistan : Islamabad  
```

### 📌 Penjelasan:

- Nilai `"India"` diubah menggunakan operator `[]`:
    
    ```cpp
    capital_city["India"] = "New Delhi";
    ```
    
- Nilai `"Pakistan"` diubah menggunakan metode `at()`:
    
    ```cpp
    capital_city.at("Pakistan") = "Islamabad";
    ```
    

## 🗑️ Menghapus Elemen dari `unordered_map`

Untuk **menghapus elemen berdasarkan kunci**, kita dapat menggunakan metode `erase()`.

### Contoh:

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

// deklarasi fungsi untuk menampilkan unordered_map
void display_unordered_map(const unordered_map<int, string> &);

int main() {
  unordered_map<int, string> student {
    {111, "John"},
    {132, "Mark"},
    {143, "Chris"}
  };
  
  cout << "Isi Awal Unordered Map:\n";
  display_unordered_map(student);

  // hapus elemen dengan kunci 143
  student.erase(143);
  
  cout << "\nIsi Akhir Unordered Map:\n";
  display_unordered_map(student);

  return 0;
}

// fungsi utilitas untuk menampilkan isi unordered_map
void display_unordered_map(const unordered_map<int, string> &umap){
  for(const auto& key_value: umap) {
    int key = key_value.first;
    string value = key_value.second;
    
    cout << key << " - " << value << endl;
  }
}
```

### 🖨️ Output:

```
Isi Awal Unordered Map:
143 - Chris
132 - Mark
111 - John

Isi Akhir Unordered Map:
132 - Mark
111 - John
```

### 🧾 Penjelasan:

- Awalnya isi map: `{143: "Chris", 132: "Mark", 111: "John"}`
    
- Perintah:
    
    ```cpp
    student.erase(143);
    ```
    
    menghapus elemen dengan **kunci 143**.
    
- Hasil akhirnya tinggal: `{132: "Mark", 111: "John"}`
    

> 🔎 **Catatan:** Untuk menghapus semua elemen, gunakan:

```cpp
student.clear();
```

---

## ❓ Memeriksa Apakah Suatu Kunci Ada

### 🔹 Metode:

|Metode|Deskripsi|
|---|---|
|`find()`|Mengembalikan iterator ke elemen jika kunci ditemukan, jika tidak maka `end()`|
|`count()`|Mengembalikan 1 jika kunci ada, 0 jika tidak|

### Contoh:

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  unordered_map<int, string> student{
      {111, "John"},
      {132, "Mark"},
      {143, "Chris"}
  };

  cout << "Menggunakan find():" << endl;
  cout << "Apakah ID 143 ada? ";

  if (student.find(143) != student.end()) {
    cout << "Ya";
  } else {
    cout << "Tidak";
  }

  cout << "\n\nMenggunakan count():" << endl;
  cout << "Apakah ID 1433 ada? ";

  if (student.count(1433)) {
    cout << "Ya";
  } else {
    cout << "Tidak";
  }

  return 0;
}
```

### 🖨️ Output:

```
Menggunakan find():
Apakah ID 143 ada? Ya

Menggunakan count():
Apakah ID 1433 ada? Tidak
```

### 🧾 Penjelasan:

- `student.find(143)` → Mengembalikan iterator ke elemen dengan kunci 143 jika ada.
    
- `student.count(1433)` → Mengembalikan `0` karena kunci 1433 tidak ada.
    
