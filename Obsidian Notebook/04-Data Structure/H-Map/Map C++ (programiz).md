---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSMP-0001
nama_algoritma: 
kategori_algoritma: data structure
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
sumber: programiz.com
date_learned: 2025-04-22T13:06:00
tags:
  - data-structure
  - map
---
---
# Map Data Structure
Dalam C++, _map_ adalah kontainer _associated_ yang menyimpan pasangan data.

Pasangan data ini, yang dikenal sebagai **key-value pairs**, memiliki **key yang unik**, sedangkan **value yang terkait tidak harus unik**.

![[Map C++-1.png]]

**Elemen-elemen dalam sebuah map secara internal disortir berdasarkan key-nya.**

Untuk menggunakan _map_ dalam C++, kita harus menyertakan file header `map` ke dalam program:

```cpp
#include <map>
```

# Membuat Map

Kita dapat mendeklarasikan sebuah _map_ dengan sintaks berikut:

```cpp
std::map<key_type, value_type> map_name = {{key1, value1}, {key2, value2}, ...};
```

Penjelasan:

- `std::map` – mendeklarasikan sebuah _STL container_ bertipe _map_
    
- `<key_type>` – tipe data dari _key_ yang akan disimpan dalam map
    
- `<value_type>` – tipe data dari _value_ yang akan disimpan dalam map
    
- `map_name` – nama unik yang diberikan pada map
    
- `key1, key2, ...` – _key_ yang disimpan dalam map
    
- `value1, value2, ...` – _value_ yang disimpan dalam map
    

Contoh:

```cpp
// membuat map dengan key bertipe int dan value bertipe string
std::map<int, string> student = {{1, "Jacqueline"}, {2, "Blake"}, {3, "Denise"}};
```

**Catatan**: Kita juga bisa menginisialisasi elemen map tanpa menggunakan operator assignment `=`. Misalnya:

```cpp
std::map<int, string> student {{1, "Jacqueline"}, {2, "Blake"}, {3, "Denise"}};
```

---

# Metode-metode pada Map

Dalam C++, kelas `map` menyediakan berbagai metode untuk melakukan operasi pada map:

|Operasi|Deskripsi|
|---|---|
|`insert()`|Menambahkan sebuah elemen (_key-value pair_) ke dalam map|
|`erase()`|Menghapus satu elemen atau rentang elemen dari map|
|`clear()`|Menghapus seluruh elemen dalam map|
|`find()`|Mencari elemen dalam map berdasarkan key yang diberikan|
|`size()`|Mengembalikan jumlah elemen dalam map|
|`empty()`|Mengembalikan `true` jika map kosong|
# Menambahkan Nilai ke Dalam Map

Kita bisa menggunakan operator `[]` untuk menambahkan _key-value pair_ ke dalam map. Contoh:

```cpp
// membuat map dengan key bertipe int dan value bertipe string
std::map<int, string> student;

// menambahkan elemen dengan key 1 dan value "Jacqueline"
student[1] = "Jacqueline";

// menambahkan elemen dengan key 2 dan value "Blake"
student[2] = "Blake";
```

Kita juga bisa menggunakan fungsi `insert()` bersama dengan `make_pair()` untuk menyisipkan elemen ke dalam map. Contoh:

```cpp
student.insert(std::make_pair(3, "Denise"));
```

Secara umum, dua metode di atas dapat ditulis dalam bentuk sintaks sebagai berikut:

```cpp
// menggunakan operator []
map_name[key] = value;

// menggunakan fungsi insert() dan make_pair()
map_name.insert(std::make_pair(key, value));
```

## Contoh 1: C++ Map

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    
    map<int, string> student;
  
    // menggunakan operator [] untuk menambahkan elemen
    student[1] = "Jacqueline";
    student[2] = "Blake";

    // menggunakan metode insert() untuk menambahkan elemen
    student.insert(make_pair(3, "Denise"));
    student.insert(make_pair(4, "Blake"));

    // menambahkan elemen dengan key duplikat
    student[5] = "Timothy";
    student[5] = "Aaron";  // akan menimpa "Timothy"

    for (int i = 1; i <= student.size(); ++i) {
        cout << "Student[" << i << "]: " << student[i] << endl;
    }

    return 0;
}
```

### Output

```
Student[1]: Jacqueline  
Student[2]: Blake  
Student[3]: Denise  
Student[4]: Blake  
Student[5]: Aaron
```

### Penjelasan

- Program ini membuat map bernama `student` yang menyimpan _key_ bertipe `int` dan _value_ bertipe `string`.
    
- Kita menambahkan data menggunakan dua metode: `[]` dan `insert()`.
    
- Nilai `"Blake"` boleh muncul dua kali karena map **mengizinkan duplikasi nilai**.
    
- Tapi key **harus unik**, sehingga saat kita menambahkan `student[5] = "Aaron"`, data `"Timothy"` yang sebelumnya dimasukkan dengan key `5` akan **ditimpa**.
    

### Catatan

Jika kita mencetak `student[1]` menggunakan `cout`, maka yang muncul hanya **nilainya saja**, bukan key-nya.

```cpp
cout << student[1];  // Output: Jacqueline
```

# Akses Key dan Value pada Map C++

Kita dapat mengakses **key** dan **value** dari map dengan menggunakan **iterator**.

## Contoh:

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> student;

    student[1] = "Jacqueline";
    student[2] = "Blake";
    student[3] = "Denise";
    student[4] = "Aaron";

    // deklarasi iterator map
    map<int, string>::iterator iter;

    // gunakan iterator untuk menampilkan elemen map
    for (iter = student.begin(); iter != student.end(); ++iter) {
        cout << iter->first << " - " << iter->second << endl;
    }

    return 0;  
}
```

### Output

```
1 - Jacqueline  
2 - Blake  
3 - Denise  
4 - Aaron
```

### Penjelasan

- Iterator `iter` digunakan untuk menelusuri elemen map.
    
- `iter->first` mengakses **key**, sedangkan `iter->second` mengakses **value**.
    
- `begin()` mengembalikan iterator ke elemen **pertama** map.
    
- `end()` mengembalikan iterator ke **setelah elemen terakhir** (digunakan sebagai batas akhir loop).
    
- Map otomatis terurut berdasarkan **key**, jadi urutan output-nya mengikuti urutan key.
    

### Alternatif Akses dengan Dereference

Kita juga bisa menggunakan `*iter` untuk mengakses pair (key, value) secara langsung:

```cpp
cout << (*iter).first << " - ";     // Output: 1
cout << (*iter).second << endl;     // Output: Jacqueline
```

Ini secara fungsi sama dengan `iter->first` dan `iter->second`, hanya berbeda cara penulisannya.

> 💡 `*iter` artinya kita mendereferensikan iterator dan mengakses nilai `pair<key, value>` secara langsung.

# Fungsi `find()` pada Map di C++

Kita dapat menggunakan fungsi `find()` untuk mencari **key** di dalam map.

## Sintaks:

```cpp
map_name.find(key);
```

### Contoh:

```cpp
map<int, string> student;
map<int, string>::iterator iter;

student[1] = "Jacqueline";
student[2] = "Blake";

// cari key 2
iter = student.find(2);
```

### Penjelasan:

- Jika **key ditemukan**, `find()` akan mengembalikan **iterator** yang menunjuk ke elemen tersebut.
    
- Jika **tidak ditemukan**, maka `find()` mengembalikan **map.end()**.
    
### Contoh implementasi berdasarkan masalah

> Hei, semisal di data map, aku memiliki angka 1 sampai 9, dan jika user memasukan angka, maka utputnya adalah string nomornya. Bentuk mapnya seperti `<int,string>`. Nah, jika nomor yang dimasukan bisa dicari di map,  kemudian bagaimana mengoutputkanya?

Hei! Jadi kamu punya `map<int, string>` dan ingin jika user memasukkan angka (misalnya `3`), program akan mencari `3` di map dan mengeluarkan string yang sesuai (misalnya `"tiga"`).

Berikut contoh kode C++-nya:

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> numberMap = {
        {1, "satu"},
        {2, "dua"},
        {3, "tiga"},
        {4, "empat"},
        {5, "lima"},
        {6, "enam"},
        {7, "tujuh"},
        {8, "delapan"},
        {9, "sembilan"}
    };

    int input;
    cout << "Masukkan angka (1-9): ";
    cin >> input;

    // Cek apakah input ada di map
    if (numberMap.find(input) != numberMap.end()) {
        cout << "Output: " << numberMap[input] << endl;
    } else {
        cout << "Angka tidak ditemukan di map." << endl;
    }

    return 0;
}
```

### Penjelasan singkat:

- `numberMap.find(input) != numberMap.end()` digunakan untuk mengecek apakah `input` ada di map.
    
- Kalau ada, ditampilkan `numberMap[input]`.
    
- Kalau tidak, tampilkan pesan bahwa angka tidak ditemukan.
    

# Menghapus Elemen dari Map

Kita bisa menghapus elemen dari map menggunakan **`erase()`** dan **`clear()`**.

---

## Fungsi `clear()`

Menghapus **semua elemen** dari map.

```cpp
map<int, string> student;

student[1] = "Jacqueline";
student[2] = "Blake";

cout << student.size();    // Output: 2

student.clear();

cout << student.size();    // Output: 0
```

---

## Fungsi `erase()`

Digunakan untuk menghapus **elemen tertentu**.

### 1. Berdasarkan Key

```cpp
map<string, int> student_rank {
    {"Josh", 2},
    {"Rachel", 4},
    {"Betty", 6}
};

student_rank.erase("Rachel");  // menghapus elemen dengan key "Rachel"
```

### 2. Berdasarkan Iterator

```cpp
map<string, int>::iterator itr = student_rank.begin();
itr++;  // iterator menunjuk ke elemen kedua
student_rank.erase(itr);  // menghapus elemen kedua
```

> 💡 `erase()` hanya menghapus **satu elemen** pada posisi iterator tertentu, dan tidak menyebabkan error meskipun iterator tidak valid, selama dicek dulu.

---

Dengan fungsi `find()`, `erase()`, dan `clear()`, kita bisa mengelola isi map dengan fleksibel dan efisien.

## Contoh 2: `erase()` untuk Menghapus Elemen Map Secara Individual

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map <int, string> student {
        {1, "Denise"}, 
        {2, "Blake"}, 
        {3, "Courtney"}, 
        {4, "John"}, 
        {5, "Jennifer"}
    };
    
    map <int, string>::iterator itr;

    // Tampilkan nilai awal
    cout << "Initial Values:" << endl;
    for(itr = student.begin(); itr != student.end(); ++itr) {
        cout << itr->second << ", ";
    }
    cout << endl;
    
    // Hapus elemen pertama
    itr = student.begin();
    student.erase(itr);

    // Hapus elemen dengan key 4
    student.erase(4);

    // Tampilkan nilai akhir
    cout << "\nFinal Values:" << endl;
    for(itr = student.begin(); itr != student.end(); ++itr) {
        cout << itr->second << ", ";
    }
    
    return 0;
}
```

**Output:**

```
Initial Values:
Denise, Blake, Courtney, John, Jennifer, 

Final Values:
Blake, Courtney, Jennifer, 
```

![[Map C++-3.png]]
#### Penjelasan:

- `student.erase(itr);` menghapus elemen **pertama** (`key 1` → "Denise")
    
- `student.erase(4);` menghapus elemen dengan **key 4** → "John"
    

---

## Menghapus Rentang Elemen dengan `erase(first, last)`

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map <int, string> student {
        {1, "Denise"}, 
        {2, "Blake"}, 
        {3, "Courtney"}, 
        {4, "John"}, 
        {5, "Jennifer"}
    };

    map <int, string>::iterator iter;
    
    cout << "Initial Values:" << endl;
    for(iter = student.begin(); iter != student.end(); ++iter) {
        cout << iter->second << ", ";
    }
    cout << endl;
    
    // Hapus dari key 2 hingga sebelum key 5
    student.erase(student.find(2), student.find(5));

    cout << "\nFinal Values:" << endl;
    for(iter = student.begin(); iter != student.end(); ++iter) {
        cout << iter->second << ", ";
    }
    
    return 0;
}
```

**Output:**

```
Initial Values:
Denise, Blake, Courtney, John, Jennifer, 

Final Values:
Denise, Jennifer, 
```

![[Map C++-2.png]]
### Penjelasan:

- `erase(student.find(2), student.find(5));`
    
    - Menghapus semua elemen dari **key 2 hingga sebelum key 5**
        
    - Elemen dengan **key 2, 3, dan 4** dihapus
        
    - Elemen dengan **key 5** tetap ada
        

> 📝 Dalam bentuk range, `erase(start, end)` bersifat **inklusif pada awal (start)** dan **eksklusif pada akhir (end)**.

---
# Menghapus elemen Map berdasarkan Value
Di C++, `std::map` tidak menyediakan fungsi langsung untuk menghapus elemen berdasarkan **value**, karena map itu berbasis **key**. Tapi kamu tetap bisa melakukannya dengan cara **mencari value-nya secara manual**, lalu **menghapus key-nya** setelah ketemu.

### Contoh:

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> student {
        {1, "Joni"},
        {2, "Yoga"},
        {3, "Axio"},
        {4, "Yoga"}
    };

    string value_to_remove = "Yoga";
    
    for (auto it = student.begin(); it != student.end(); ) {
        if (it->second == value_to_remove) {
            it = student.erase(it); // erase returns the next iterator
        } else {
            ++it;
        }
    }

    // Tampilkan hasil akhirnya
    for (auto& pair : student) {
        cout << pair.first << " - " << pair.second << endl;
    }

    return 0;
}
```

### Output:

```
1 - Joni
3 - Axio
```

### Penjelasan:

- Kita melakukan iterasi ke seluruh isi map.
    
- Saat value cocok (`it->second == value_to_remove`), kita hapus elemen itu dengan `erase()`.
    
- Penting: jangan pakai `++it` setelah `erase`, karena `erase()` sudah mengembalikan iterator berikutnya (kalau tidak, program bisa crash).
    

## Membuat fungsi untuk menghapus Elemen berdasarkan Value:
Tentu! Berikut contoh fungsi reusable yang bisa kamu pakai untuk **menghapus elemen dari `std::map` berdasarkan value**:

### ✅ Fungsi `removeByValue()` – hapus semua elemen dengan value tertentu

```cpp
#include <iostream>
#include <map>
using namespace std;

void removeByValue(map<int, string>& m, const string& target_value) {
    for (auto it = m.begin(); it != m.end(); ) {
        if (it->second == target_value) {
            it = m.erase(it); 
            // hapus elemen dan lanjut ke iterator berikutnya
        } else {
            ++it;
        }
    }
}
```

### ✅ Contoh penggunaannya:

```cpp
int main() {
    map<int, string> student {
        {1, "Joni"},
        {2, "Yoga"},
        {3, "Axio"},
        {4, "Yoga"}
    };

    cout << "Sebelum dihapus:\n";
    for (const auto& s : student) {
        cout << s.first << " - " << s.second << endl;
    }

    // Panggil fungsi untuk menghapus semua yang value-nya "Yoga"
    removeByValue(student, "Yoga");

    cout << "\nSetelah dihapus:\n";
    for (const auto& s : student) {
        cout << s.first << " - " << s.second << endl;
    }

    return 0;
}
```

### Output:

```
Sebelum dihapus:
1 - Joni
2 - Yoga
3 - Axio
4 - Yoga

Setelah dihapus:
1 - Joni
3 - Axio
```

