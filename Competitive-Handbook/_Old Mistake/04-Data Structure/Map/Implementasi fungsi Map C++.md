---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSMP-0004
nama_algoritma: 
kategori_algoritma: data structure
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
sumber: Gemini AI
date_learned: 2025-06-22T18:25:00
tags:
  - data-structure
  - map
---
---
# Contoh Implementasi Fungsi `std::map` di C++

Laporan ini menyajikan serangkaian contoh kode yang mengilustrasikan penggunaan berbagai fungsi anggota `std::map` dalam C++. Setiap bagian akan fokus pada kategori fungsi tertentu, dilengkapi dengan kode yang dapat dijalankan dan penjelasan singkat tentang perilakunya.

## 1. Deklarasi dan Inisialisasi `std::map`

`std::map` dapat dideklarasikan dan diinisialisasi dengan beberapa cara, termasuk konstruktor default, inisialisasi dengan daftar inisialisasi (`initializer_list`), atau menyalin dari `map` lain.

```cpp
#include <iostream>
#include <map>
#include <string>
#include <utility> // Untuk std::make_pair
using namespace std; // Deklarasi namespace std

int main() {
    // Deklarasi map kosong
    map<string, int> emptyMap;
    cout << "Ukuran emptyMap: " << emptyMap.size() << endl; // Output: 0

    // Inisialisasi map dengan initializer list (C++11)
    map<string, int> fruitPrices = {
        {"Apple", 10000},
        {"Banana", 5000},
        {"Orange", 8000}
    }; // [1, 2]
    cout << "Ukuran fruitPrices: " << fruitPrices.size() << endl; // Output: 3

    // Menyalin map lain
    map<string, int> copiedPrices = fruitPrices;
    cout << "Ukuran copiedPrices: " << copiedPrices.size() << endl; // Output: 3

    // Inisialisasi dengan rentang dari map lain
    map<string, int> rangePrices(fruitPrices.begin(), fruitPrices.end()); // [1]
    cout << "Ukuran rangePrices: " << rangePrices.size() << endl; // Output: 3

    cout << "\n--- Isi fruitPrices ---" << endl;
    for (const auto& pair : fruitPrices) {
        cout << pair.first << ": " << pair.second << endl;
    }
    return 0;
}
```

## 2. Menyisipkan Elemen (Insertion)

Elemen dapat disisipkan ke dalam `std::map` menggunakan `insert()`, `operator`, `emplace()`, `insert_or_assign()`, dan `try_emplace()`.

```cpp
#include <iostream>
#include <map>
#include <string>
#include <utility> // Untuk std::make_pair
using namespace std; // Deklarasi namespace std

int main() {
    map<string, int> studentScores;

    // Menggunakan operator untuk menyisipkan atau memperbarui
    studentScores["Alice"] = 95; // Menyisipkan jika "Alice" belum ada [1, 3]
    studentScores = 88;
    studentScores["Alice"] = 98; // Memperbarui nilai "Alice" [1]
    cout << "Alice score (via operator): " << studentScores["Alice"] << endl; // Output: 98

    // Menggunakan insert() dengan std::pair atau {key, value}
    studentScores.insert(make_pair("Charlie", 75)); // [1, 4]
    studentScores.insert({"David", 90});
    // Mencoba menyisipkan kunci yang sudah ada (tidak akan mengubah nilai)
    auto result_insert = studentScores.insert({"Bob", 80}); // [1]
    if (!result_insert.second) {
        cout << "Penyisipan 'Bob' gagal karena kunci sudah ada. Nilai Bob: " << studentScores << endl; // Output: 88
    }

    // Menggunakan emplace() (C++11) - konstruksi in-place
    // Lebih efisien untuk tipe data kompleks karena menghindari salinan sementara [1]
    studentScores.emplace("Eve", 100);

    // Menggunakan insert_or_assign() (C++17) - menyisipkan atau menugaskan
    // Menyisipkan jika kunci tidak ada, atau menugaskan nilai baru jika kunci sudah ada [1]
    studentScores.insert_or_assign("Charlie", 85); // Memperbarui Charlie
    studentScores.insert_or_assign("Frank", 70);   // Menyisipkan Frank
    cout << "Charlie score (via insert_or_assign): " << studentScores["Charlie"] << endl; // Output: 85

    // Menggunakan try_emplace() (C++17) - menyisipkan di tempat jika kunci tidak ada
    // Menyisipkan jika kunci tidak ada. Jika kunci ada, tidak melakukan apa-apa [1]
    studentScores.try_emplace("David", 60); // Tidak akan mengubah David (tetap 90)
    studentScores.try_emplace("Grace", 92); // Menyisipkan Grace
    cout << "David score (via try_emplace): " << studentScores << endl; // Output: 90

    cout << "\n--- Semua Skor Siswa ---" << endl;
    for (const auto& pair : studentScores) {
        cout << pair.first << ": " << pair.second << endl;
    }
    return 0;
}
```

## 3. Akses Elemen

Elemen dapat diakses menggunakan `at()` (dengan pemeriksaan batas) atau `operator` (tanpa pemeriksaan batas, menyisipkan jika tidak ada).

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std; // Deklarasi namespace std

int main() {
    map<string, int> inventory = {
        {"Laptop", 10},
        {"Mouse", 50},
        {"Keyboard", 20}
    };

    // Mengakses elemen menggunakan operator
    cout << "Jumlah Laptop: " << inventory["Laptop"] << endl; // Output: 10 [1, 3]

    // Mengakses elemen menggunakan at() (lebih aman)
    try {
        cout << "Jumlah Keyboard: " << inventory.at("Keyboard") << endl; // Output: 20 [1]
        // Mencoba mengakses kunci yang tidak ada dengan at() akan melempar pengecualian
        cout << "Jumlah Monitor: " << inventory.at("Monitor") << endl;
    } catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl; // Output: Error: map::at: key not found
    }

    // Menggunakan operator untuk kunci yang tidak ada akan menyisipkan elemen baru
    cout << "Jumlah Speaker (sebelum akses): " << inventory << endl; // Output: 0 (nilai default int)
    cout << "Ukuran inventory setelah akses Speaker: " << inventory.size() << endl; // Output: 4

    cout << "\n--- Isi Inventory ---" << endl;
    for (const auto& pair : inventory) {
        cout << pair.first << ": " << pair.second << endl;
    }
    return 0;
}
```

## 4. Iterasi Elemen

`std::map` menyediakan iterator untuk melintasi elemen dalam urutan kunci yang terurut.

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std; // Deklarasi namespace std

int main() {
    map<int, string> errorCodes = {
        {404, "Not Found"},
        {200, "OK"},
        {500, "Internal Server Error"},
        {403, "Forbidden"}
    };

    cout << "--- Iterasi Maju (Ascending Key Order) ---" << endl;
    // Menggunakan iterator begin() dan end() [1, 2]
    for (auto it = errorCodes.begin(); it!= errorCodes.end(); ++it) {
        cout << "Kode: " << it->first << ", Pesan: " << it->second << endl;
    }
    // Output akan terurut berdasarkan kunci: 200, 403, 404, 500

    cout << "\n--- Iterasi Mundur (Descending Key Order) ---" << endl;
    // Menggunakan reverse iterator rbegin() dan rend() [1, 2]
    for (auto it = errorCodes.rbegin(); it!= errorCodes.rend(); ++it) {
        cout << "Kode: " << it->first << ", Pesan: " << it->second << endl;
    }
    // Output akan terurut terbalik: 500, 404, 403, 200

    cout << "\n--- Iterasi Konstan (cbegin(), cend()) ---" << endl;
    // Menggunakan const iterator (tidak dapat memodifikasi elemen) [1, 2]
    for (auto it = errorCodes.cbegin(); it!= errorCodes.cend(); ++it) {
        cout << "Kode: " << it->first << ", Pesan: " << it->second << endl;
        // it->second = "New Message"; // Ini akan menyebabkan error kompilasi
    }
    return 0;
}
```

## 5. Kapasitas Map

Fungsi-fungsi ini memberikan informasi tentang ukuran dan status `std::map`.

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std; // Deklarasi namespace std

int main() {
    map<string, double> productPrices;

    // empty() - memeriksa apakah map kosong [1, 2]
    cout << "Apakah productPrices kosong? " << (productPrices.empty()? "Ya" : "Tidak") << endl; // Output: Ya

    // size() - mengembalikan jumlah elemen [1, 2]
    cout << "Ukuran productPrices: " << productPrices.size() << endl; // Output: 0

    productPrices["Laptop"] = 1200.0;
    productPrices["Monitor"] = 300.0;

    cout << "\nSetelah menambahkan elemen:" << endl;
    cout << "Apakah productPrices kosong? " << (productPrices.empty()? "Ya" : "Tidak") << endl; // Output: Tidak
    cout << "Ukuran productPrices: " << productPrices.size() << endl; // Output: 2

    // max_size() - mengembalikan jumlah maksimum elemen yang dapat ditampung [1, 2]
    // Nilai ini sangat besar dan bergantung pada sistem
    cout << "Ukuran maksimum productPrices: " << productPrices.max_size() << endl;

    return 0;
}
```

## 6. Menghapus Elemen (Deletion)

Elemen dapat dihapus dari `std::map` berdasarkan kunci, iterator, atau rentang iterator.

```cpp
#include <iostream>
#include <map>
#include <string>
#include <algorithm> // Untuk std::next
using namespace std; // Deklarasi namespace std

int main() {
    map<int, string> students = {
        {101, "Alice"},
        {102, "Bob"},
        {103, "Charlie"},
        {104, "David"},
        {105, "Eve"}
    };

    cout << "--- Map Awal ---" << endl;
    for (const auto& pair : students) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "Ukuran: " << students.size() << endl << endl;

    // 1. Menghapus elemen berdasarkan kunci (erase(key)) [1, 5]
    students.erase(103); // Menghapus Charlie
    cout << "--- Setelah menghapus kunci 103 ---" << endl;
    for (const auto& pair : students) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "Ukuran: " << students.size() << endl << endl;

    // 2. Menghapus elemen berdasarkan iterator (erase(iterator)) [1, 5]
    auto it_to_erase = students.find(101); // Mencari Alice
    if (it_to_erase!= students.end()) {
        students.erase(it_to_erase); // Menghapus Alice
    }
    cout << "--- Setelah menghapus elemen dengan iterator (kunci 101) ---" << endl;
    for (const auto& pair : students) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "Ukuran: " << students.size() << endl << endl;

    // 3. Menghapus rentang elemen (erase(first, last)) [1, 5]
    // Menghapus dari Bob (102) hingga sebelum Eve (105)
    auto first_it = students.find(102);
    auto last_it = students.find(105); // Ini akan menunjuk ke Eve
    if (first_it!= students.end() && last_it!= students.end()) {
        students.erase(first_it, last_it); // Menghapus Bob dan David
    }
    cout << "--- Setelah menghapus rentang (dari 102 hingga sebelum 105) ---" << endl;
    for (const auto& pair : students) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "Ukuran: " << students.size() << endl << endl;

    // 4. Mengosongkan seluruh map (clear()) [1, 2]
    students.clear();
    cout << "--- Setelah clear() ---" << endl;
    cout << "Ukuran: " << students.size() << endl; // Output: 0
    cout << "Apakah map kosong? " << (students.empty()? "Ya" : "Tidak") << endl; // Output: Ya

    return 0;
}
```

## 7. Pencarian Elemen (Lookup)

`std::map` menyediakan fungsi pencarian yang efisien untuk menemukan elemen atau rentang elemen.

```cpp
#include <iostream>
#include <map>
#include <string>
#include <algorithm> // Untuk std::for_each
using namespace std; // Deklarasi namespace std

int main() {
    map<int, string> inventory = {
        {10, "Laptop"},
        {20, "Monitor"},
        {30, "Keyboard"},
        {40, "Mouse"},
        {50, "Webcam"}
    };

    cout << "--- Map Inventory ---" << endl;
    for (const auto& pair : inventory) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << endl;

    // find() - mencari elemen dengan kunci spesifik [1, 2]
    auto it_find = inventory.find(30);
    if (it_find!= inventory.end()) {
        cout << "Ditemukan kunci 30: " << it_find->second << endl; // Output: Keyboard
    } else {
        cout << "Kunci 30 tidak ditemukan." << endl;
    }

    it_find = inventory.find(99);
    if (it_find == inventory.end()) {
        cout << "Kunci 99 tidak ditemukan." << endl; // Output: Kunci 99 tidak ditemukan.
    }
    cout << endl;

    // count() - mengembalikan 1 jika kunci ada, 0 jika tidak [1, 2]
    if (inventory.count(20)) {
        cout << "Kunci 20 ada dalam inventory." << endl; // Output: Kunci 20 ada dalam inventory.
    } else {
        cout << "Kunci 20 tidak ada." << endl;
    }
    cout << endl;

    // contains() (C++20) - cara yang lebih ringkas untuk memeriksa keberadaan [1]
    if (inventory.contains(40)) {
        cout << "Kunci 40 ada dalam inventory (via contains())." << endl; // Output: Kunci 40 ada dalam inventory (via contains()).
    }
    cout << endl;

    // lower_bound() - elemen pertama yang tidak kurang dari kunci [1, 6, 7]
    auto lb = inventory.lower_bound(25);
    if (lb!= inventory.end()) {
        cout << "lower_bound(25): " << lb->first << ": " << lb->second << endl; // Output: 30: Keyboard
    }

    // upper_bound() - elemen pertama yang lebih besar dari kunci [1, 6, 7]
    auto ub = inventory.upper_bound(30);
    if (ub!= inventory.end()) {
        cout << "upper_bound(30): " << ub->first << ": " << ub->second << endl; // Output: 40: Mouse
    }
    cout << endl;

    // equal_range() - mengembalikan pasangan iterator [lower_bound, upper_bound) [1, 6]
    auto range = inventory.equal_range(30);
    cout << "equal_range(30):" << endl;
    for (auto it = range.first; it!= range.second; ++it) {
        cout << it->first << ": " << it->second << endl; // Output: 30: Keyboard
    }

    // Contoh equal_range untuk kunci yang tidak ada
    auto empty_range = inventory.equal_range(25);
    cout << "\nequal_range(25):" << endl;
    if (empty_range.first == empty_range.second) {
        cout << "Rentang kosong, kunci tidak ditemukan." << endl; // Output: Rentang kosong, kunci tidak ditemukan.
    }

    return 0;
}
```

## 8. Fungsi Modifikasi Lainnya

`std::map` juga menyediakan fungsi seperti `swap()`, `extract()`, dan `merge()` untuk manipulasi yang lebih canggih.

```cpp
#include <iostream>
#include <map>
#include <string>
#include <utility> // Untuk std::move
using namespace std; // Deklarasi namespace std

int main() {
    // swap() - menukar isi dua map secara efisien [1]
    map<int, string> map1 = {{1, "One"}, {2, "Two"}};
    map<int, string> map2 = {{3, "Three"}, {4, "Four"}};

    cout << "Sebelum swap:" << endl;
    cout << "Map1: ";
    for (const auto& p : map1) cout << "{" << p.first << ", " << p.second << "} ";
    cout << "\nMap2: ";
    for (const auto& p : map2) cout << "{" << p.first << ", " << p.second << "} ";
    cout << endl;

    map1.swap(map2); // O(1) kompleksitas waktu [1]

    cout << "\nSetelah swap:" << endl;
    cout << "Map1: ";
    for (const auto& p : map1) cout << "{" << p.first << ", " << p.second << "} ";
    cout << "\nMap2: ";
    for (const auto& p : map2) cout << "{" << p.first << ", " << p.second << "} ";
    cout << endl;

    // extract() (C++17) - mengekstrak node tanpa menghancurkan elemen [1]
    map<int, string> originalMap = {{10, "A"}, {20, "B"}, {30, "C"}};
    map<int, string> targetMap;

    cout << "\n--- Sebelum extract ---" << endl;
    cout << "Original Map: ";
    for (const auto& p : originalMap) cout << "{" << p.first << ", " << p.second << "} ";
    cout << "\nTarget Map: ";
    for (const auto& p : targetMap) cout << "{" << p.first << ", " << p.second << "} ";
    cout << endl;

    // Ekstrak node dengan kunci 20
    auto node = originalMap.extract(20); // [1]
    if (!node.empty()) {
        targetMap.insert(move(node)); // Masukkan node ke map lain [1]
    }

    cout << "\n--- Setelah extract dan insert ---" << endl;
    cout << "Original Map: ";
    for (const auto& p : originalMap) cout << "{" << p.first << ", " << p.second << "} "; // Output: {10, A} {30, C}
    cout << "\nTarget Map: ";
    for (const auto& p : targetMap) cout << "{" << p.first << ", " << p.second << "} ";     // Output: {20, B}
    cout << endl;

    // merge() (C++17) - menggabungkan node dari map lain [1]
    map<int, string> sourceMap = {{15, "X"}, {25, "Y"}, {30, "Z"}}; // Kunci 30 duplikat

    cout << "\n--- Sebelum merge ---" << endl;
    cout << "Target Map: ";
    for (const auto& p : targetMap) cout << "{" << p.first << ", " << p.second << "} "; // Output: {20, B}
    cout << "\nSource Map: ";
    for (const auto& p : sourceMap) cout << "{" << p.first << ", " << p.second << "} "; // Output: {15, X} {25, Y} {30, Z}
    cout << endl;

    targetMap.merge(sourceMap); // [1]
    // Kunci 30 dari sourceMap tidak akan digabungkan karena sudah ada di targetMap (dari originalMap)

    cout << "\n--- Setelah merge ---" << endl;
    cout << "Target Map: ";
    for (const auto& p : targetMap) cout << "{" << p.first << ", " << p.second << "} ";
    // Output: {15, X} {20, B} {25, Y} {30, C} (kunci 30 tetap dari originalMap)
    cout << "\nSource Map (setelah merge, elemen dipindahkan): ";
    for (const auto& p : sourceMap) cout << "{" << p.first << ", " << p.second << "} "; // Output: {30, Z} (kunci 30 yang tidak dipindahkan)
    cout << endl;

    return 0;
}
```

## 9. Komparator Kustom untuk Tipe Data Buatan Pengguna

`std::map` memungkinkan penggunaan komparator kustom untuk menentukan urutan pengurutan dan definisi keunikan, terutama saat bekerja dengan tipe data buatan pengguna.

```cpp
#include <iostream>
#include <map>
#include <string>
#include <cmath> // Untuk std::abs
using namespace std; // Deklarasi namespace std

// Tipe data buatan pengguna
struct City {
    string name;
    int population;
};

// Komparator kustom menggunakan Functor: Mengurutkan berdasarkan populasi (menurun),
// kemudian nama (menaik) jika populasi sama.
struct CompareCityByPopulationDesc {
    bool operator()(const City& c1, const City& c2) const {
        if (c1.population!= c2.population) {
            return c1.population > c2.population; // Urutan menurun berdasarkan populasi
        }
        return c1.name < c2.name; // Urutan menaik berdasarkan nama jika populasi sama
    }
};

int main() {
    // Menggunakan std::map dengan komparator kustom (Functor)
    map<City, string, CompareCityByPopulationDesc> cityInfo;

    cityInfo = "Japan";
    cityInfo = "India";
    cityInfo = "China";
    cityInfo = "Brazil";
    cityInfo[{ "Mexico City", 9200000 }] = "Mexico";
    cityInfo = "China"; // Populasi lebih rendah dari Shanghai

    cout << "--- Kota diurutkan berdasarkan Populasi (Menurun) dan Nama (Menaik) ---" << endl;
    for (const auto& pair : cityInfo) {
        cout << pair.first.name << " (Populasi: " << pair.first.population << "): " << pair.second << endl;
    }
    // Output akan terurut:
    // Shanghai (Populasi: 26300000): China
    // Beijing (Populasi: 21500000): China
    // Delhi (Populasi: 19000000): India
    // Tokyo (Populasi: 13960000): Japan
    // Sao Paulo (Populasi: 12300000): Brazil
    // Mexico City (Populasi: 9200000): Mexico

    cout << "\n--------------------\n";

    // Contoh lain: Menggunakan lambda untuk pengurutan terbalik (descending) untuk int
    auto reverseIntCmp =(int a, int b) {
        return a > b; // Mengurutkan secara menurun
    };
    map<int, string, decltype(reverseIntCmp)> reverseMap(reverseIntCmp); // [8]

    reverseMap[9] = "Ten";
    reverseMap[10] = "Five";
    reverseMap[11] = "Twenty";
    reverseMap[12] = "One";

    cout << "--- Map Integer diurutkan Menurun ---" << endl;
    for (const auto& pair : reverseMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
    // Output:
    // 20: Twenty
    // 10: Ten
    // 5: Five
    // 1: One

    return 0;
}
```

# Fungsi Pada Map | Versi yang lebih Rapi

Laporan ini menyajikan contoh kode C++ yang terpisah dan spesifik untuk setiap fungsi anggota `std::map` yang umum digunakan. Setiap bagian akan menjelaskan tujuan fungsi dan memberikan ilustrasi kode yang jelas.

## 1. Deklarasi dan Inisialisasi `std::map`

Bagian ini menunjukkan berbagai cara untuk mendeklarasikan dan menginisialisasi objek `std::map`, termasuk konstruktor default, inisialisasi dengan daftar inisialisasi (`initializer_list`), atau menyalin dari `map` lain.

```cpp
#include <iostream>
#include <map>
#include <string>
#include <utility> // Untuk make_pair
using namespace std;

int main() {
    // Deklarasi map kosong
    map<string, int> emptyMap;
    cout << "Ukuran emptyMap: " << emptyMap.size() << endl; // Output: 0

    // Inisialisasi map dengan initializer list (C++11)
    map<string, int> fruitPrices = {
        {"Apple", 10000},
        {"Banana", 5000},
        {"Orange", 8000}
    }; // [1, 2]
    cout << "Ukuran fruitPrices: " << fruitPrices.size() << endl; // Output: 3

    // Menyalin map lain
    map<string, int> copiedPrices = fruitPrices;
    cout << "Ukuran copiedPrices: " << copiedPrices.size() << endl; // Output: 3

    // Inisialisasi dengan rentang dari map lain
    map<string, int> rangePrices(fruitPrices.begin(), fruitPrices.end()); [1]
    cout << "Ukuran rangePrices: " << rangePrices.size() << endl; // Output: 3

    cout << "\n--- Isi fruitPrices ---" << endl;
    for (const auto& pair : fruitPrices) {
        cout << pair.first << ": " << pair.second << endl;
    }
    return 0;
}
```

## 2. `map::insert()`

Fungsi `insert()` digunakan untuk menyisipkan pasangan kunci-nilai baru ke dalam `std::map`. Jika kunci sudah ada, operasi ini tidak akan mengubah nilai yang sudah ada. 

```cpp
#include <iostream>
#include <map>
#include <string>
#include <utility> // Untuk make_pair
using namespace std;

int main() {
    map<string, int> studentScores;

    // Menyisipkan elemen menggunakan insert() dengan std::pair
    studentScores.insert(make_pair("Alice", 95)); [1, 3]
    studentScores.insert({"Bob", 88}); // Inisialisasi daftar juga berfungsi

    // Mencoba menyisipkan kunci yang sudah ada (tidak akan mengubah nilai)
    auto result = studentScores.insert({"Alice", 98});
    if (!result.second) {
        cout << "Penyisipan 'Alice' gagal karena kunci sudah ada. Nilai Alice: " << studentScores["Alice"] << endl;
    }

    cout << "--- Skor Siswa Setelah Insert ---" << endl;
    for (const auto& pair : studentScores) {
        cout << pair.first << ": " << pair.second << endl;
    }
    return 0;
}
```

## 3. `map::operator` (untuk Penyisipan/Pembaruan)

Operator `[]` digunakan untuk menyisipkan elemen jika kunci belum ada, atau memperbarui nilai jika kunci sudah ada. Jika kunci tidak ada, ia akan menyisipkan elemen baru dengan nilai default.

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> studentScores;

    // Menyisipkan elemen baru menggunakan operator
    studentScores["Alice"] = 95; // Alice disisipkan
    studentScores = 88;   // Bob disisipkan

    // Memperbarui nilai elemen yang sudah ada menggunakan operator
    studentScores["Alice"] = 98; // Nilai Alice diperbarui

    // Mengakses kunci yang tidak ada akan menyisipkan dengan nilai default (0 untuk int)
    cout << "Nilai Charlie (sebelum inisialisasi): " << studentScores["Charlie"] << endl; // Charlie disisipkan dengan nilai 0

    cout << "--- Skor Siswa Setelah Operator ---" << endl;
    for (const auto& pair : studentScores) {
        cout << pair.first << ": " << pair.second << endl;
    }
    return 0;
}
```

## 4. `map::emplace()` (C++11)

Fungsi `emplace()` mengkonstruksi elemen baru secara _in-place_ di dalam map, menghindari salinan sementara yang tidak perlu. Ini dapat lebih efisien untuk tipe data kompleks. 

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;
    // Perlu operator< untuk digunakan sebagai kunci di map
    bool operator<(const Person& other) const {
        if (name!= other.name) return name < other.name;
        return age < other.age;
    }
};

int main() {
    map<Person, string> peopleInfo;

    // Menggunakan emplace() untuk mengkonstruksi objek Person dan string secara in-place
    peopleInfo.emplace(Person{"Alice", 30}, "Software Engineer"); [1]
    peopleInfo.emplace(Person{"Bob", 25}, "Data Scientist");

    // Mencoba emplace dengan kunci yang sudah ada (tidak akan menyisipkan)
    auto result = peopleInfo.emplace(Person{"Alice", 30}, "Project Manager");
    if (!result.second) {
        cout << "Emplace 'Alice' gagal karena kunci sudah ada." << endl;
    }

    cout << "--- Informasi Orang Setelah Emplace ---" << endl;
    for (const auto& pair : peopleInfo) {
        cout << pair.first.name << " (" << pair.first.age << "): " << pair.second << endl;
    }
    return 0;
}
```

## 5. `map::insert_or_assign()` (C++17)

Fungsi `insert_or_assign()` menyisipkan elemen jika kunci tidak ada, atau menugaskan nilai baru ke elemen yang ada jika kunci sudah ada. 

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> productStock;

    // Menyisipkan elemen baru
    productStock.insert_or_assign("Laptop", 100); [1]
    cout << "Stok Laptop (awal): " << productStock["Laptop"] << endl;

    // Memperbarui nilai elemen yang sudah ada
    productStock.insert_or_assign("Laptop", 120);
    cout << "Stok Laptop (setelah update): " << productStock["Laptop"] << endl;

    // Menyisipkan elemen baru lagi
    productStock.insert_or_assign("Mouse", 500);
    cout << "Stok Mouse: " << productStock["Mouse"] << endl;

    cout << "--- Stok Produk Setelah Insert_or_assign ---" << endl;
    for (const auto& pair : productStock) {
        cout << pair.first << ": " << pair.second << endl;
    }
    return 0;
}
```

## 6. `map::try_emplace()` (C++17)

Fungsi `try_emplace()` menyisipkan elemen di tempat jika kunci tidak ada. Jika kunci sudah ada, fungsi ini tidak melakukan apa-apa dan tidak memodifikasi nilai yang ada. 

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, string> userStatus;

    // Menyisipkan elemen baru
    userStatus.try_emplace("Alice", "Online"); [1]
    cout << "Status Alice (awal): " << userStatus["Alice"] << endl;

    // Mencoba menyisipkan kunci yang sudah ada (tidak akan mengubah nilai)
    userStatus.try_emplace("Alice", "Offline");
    cout << "Status Alice (setelah try_emplace): " << userStatus["Alice"] << endl; // Tetap "Online"

    // Menyisipkan elemen baru
    userStatus.try_emplace("Bob", "Away");
    cout << "Status Bob: " << userStatus << endl;

    cout << "--- Status Pengguna Setelah Try_emplace ---" << endl;
    for (const auto& pair : userStatus) {
        cout << pair.first << ": " << pair.second << endl;
    }
    return 0;
}
```

## 7. `map::at()`

Fungsi `at()` mengakses elemen yang ditentukan dengan pemeriksaan batas. Jika kunci yang diberikan tidak ditemukan dalam `std::map`, fungsi ini akan melemparkan pengecualian `std::out_of_range`. 

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> inventory = {
        {"Laptop", 10},
        {"Mouse", 50},
        {"Keyboard", 20}
    };

    // Mengakses elemen menggunakan at()
    cout << "Jumlah Keyboard: " << inventory.at("Keyboard") << endl; // Output: 20 [1]

    // Mencoba mengakses kunci yang tidak ada dengan at() akan melempar pengecualian
    try {
        cout << "Jumlah Monitor: " << inventory.at("Monitor") << endl;
    } catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl; // Output: Error: map::at: key not found
    }

    cout << "\n--- Isi Inventory ---" << endl;
    for (const auto& pair : inventory) {
        cout << pair.first << ": " << pair.second << endl;
    }
    return 0;
}
```

## 8. `map::operator` (untuk Akses)

Operator `[]` juga dapat digunakan untuk mengakses elemen. Jika kunci tidak ada, ia akan menyisipkan elemen baru dengan nilai default. 

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> inventory = {
        {"Laptop", 10},
        {"Mouse", 50},
        {"Keyboard", 20}
    };

    // Mengakses elemen yang sudah ada menggunakan operator
    cout << "Jumlah Laptop: " << inventory["Laptop"] << endl; // Output: 10 [1, 4]

    // Mengakses kunci yang tidak ada akan menyisipkan elemen baru dengan nilai default (0 untuk int)
    cout << "Jumlah Speaker (sebelum akses): " << inventory << endl; // Output: 0
    cout << "Ukuran inventory setelah akses Speaker: " << inventory.size() << endl; // Output: 4

    cout << "\n--- Isi Inventory ---" << endl;
    for (const auto& pair : inventory) {
        cout << pair.first << ": " << pair.second << endl;
    }
    return 0;
}
```

## 9. `map::begin()` dan `map::end()` (Iterasi Maju)

`begin()` mengembalikan iterator ke elemen pertama dalam map (yaitu, elemen dengan kunci terkecil), sedangkan `end()` mengembalikan iterator ke posisi teoretis setelah elemen terakhir. Digunakan untuk iterasi maju. 

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<int, string> errorCodes = {
        {404, "Not Found"},
        {200, "OK"},
        {500, "Internal Server Error"},
        {403, "Forbidden"}
    };

    cout << "--- Iterasi Maju (Ascending Key Order) ---" << endl;
    // Iterasi menggunakan iterator begin() dan end()
    for (auto it = errorCodes.begin(); it!= errorCodes.end(); ++it) { [1, 2]
        cout << "Kode: " << it->first << ", Pesan: " << it->second << endl;
    }
    // Output akan terurut berdasarkan kunci: 200, 403, 404, 500
    return 0;
}
```

## 10. `map::rbegin()` dan `map::rend()` (Iterasi Mundur)

`rbegin()` mengembalikan _reverse iterator_ ke elemen terakhir (yang merupakan awal dari urutan terbalik), sedangkan `rend()` mengembalikan _reverse iterator_ ke posisi "satu sebelum elemen pertama" (yang merupakan akhir dari urutan terbalik). Digunakan untuk iterasi mundur. 

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<int, string> errorCodes = {
        {404, "Not Found"},
        {200, "OK"},
        {500, "Internal Server Error"},
        {403, "Forbidden"}
    };

    cout << "--- Iterasi Mundur (Descending Key Order) ---" << endl;
    // Iterasi menggunakan reverse iterator rbegin() dan rend()
    for (auto it = errorCodes.rbegin(); it!= errorCodes.rend(); ++it) { [1, 2]
        cout << "Kode: " << it->first << ", Pesan: " << it->second << endl;
    }
    // Output akan terurut terbalik: 500, 404, 403, 200
    return 0;
}
```

## 11. `map::cbegin()` dan `map::cend()` (Iterasi Konstan)

`cbegin()` dan `cend()` (sejak C++11) mirip dengan `begin()` dan `end()`, tetapi mengembalikan iterator konstan. Ini berguna ketika iterasi dilakukan pada map yang tidak boleh dimodifikasi, memastikan _const-correctness_. 

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    const map<int, string> errorCodes = { // Map dideklarasikan sebagai const
        {404, "Not Found"},
        {200, "OK"},
        {500, "Internal Server Error"}
    };

    cout << "--- Iterasi Konstan (cbegin(), cend()) ---" << endl;
    // Menggunakan const iterator
    for (auto it = errorCodes.cbegin(); it!= errorCodes.cend(); ++it) { [1, 2]
        cout << "Kode: " << it->first << ", Pesan: " << it->second << endl;
        // it->second = "New Message"; // Ini akan menyebabkan error kompilasi karena const iterator
    }
    return 0;
}
```

## 12. `map::empty()`

Fungsi `empty()` memeriksa apakah kontainer tidak mengandung elemen apa pun. Mengembalikan `true` jika map kosong, dan `false` jika tidak kosong. 

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, double> productPrices;

    // Memeriksa apakah map kosong
    cout << "Apakah productPrices kosong? " << (productPrices.empty()? "Ya" : "Tidak") << endl; // Output: Ya [1, 2]

    productPrices["Laptop"] = 1200.0;

    cout << "\nSetelah menambahkan elemen:" << endl;
    cout << "Apakah productPrices kosong? " << (productPrices.empty()? "Ya" : "Tidak") << endl; // Output: Tidak

    return 0;
}
```

## 13. `map::size()`

Fungsi `size()` mengembalikan jumlah elemen (pasangan kunci-nilai) yang saat ini ada dalam map. 1

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, double> productPrices;

    cout << "Ukuran productPrices (awal): " << productPrices.size() << endl; // Output: 0 [1, 2]

    productPrices["Laptop"] = 1200.0;
    productPrices["Monitor"] = 300.0;

    cout << "Ukuran productPrices (setelah penambahan): " << productPrices.size() << endl; // Output: 2

    return 0;
}
```

## 14. `map::max_size()`

Fungsi `max_size()` mengembalikan jumlah maksimum elemen yang secara teoretis dapat ditampung oleh map. Nilai ini biasanya sangat besar dan bergantung pada alokator memori yang digunakan serta ketersediaan memori sistem. 

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, double> productPrices;

    // Mengembalikan jumlah maksimum elemen yang dapat ditampung
    cout << "Ukuran maksimum productPrices: " << productPrices.max_size() << endl; [1, 2]
    // Output akan bervariasi tergantung sistem dan compiler, biasanya angka yang sangat besar.

    return 0;
}
```

## 15. `map::erase(key)`

Fungsi `erase(key)` menghapus elemen dari map berdasarkan kunci yang diberikan. Mengembalikan jumlah elemen yang dihapus (0 atau 1 karena kunci unik). 

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<int, string> students = {
        {101, "Alice"},
        {102, "Bob"},
        {103, "Charlie"}
    };

    cout << "--- Map Awal ---" << endl;
    for (const auto& pair : students) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "Ukuran: " << students.size() << endl << endl;

    // Menghapus elemen berdasarkan kunci
    size_t erased_count = students.erase(102); // Menghapus Bob [1, 5]
    cout << "Menghapus kunci 102. Jumlah elemen dihapus: " << erased_count << endl;

    cout << "--- Map Setelah menghapus kunci 102 ---" << endl;
    for (const auto& pair : students) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "Ukuran: " << students.size() << endl << endl;

    // Mencoba menghapus kunci yang tidak ada
    erased_count = students.erase(999);
    cout << "Menghapus kunci 999. Jumlah elemen dihapus: " << erased_count << endl;

    return 0;
}
```

## 16. `map::erase(iterator)`

Fungsi `erase(iterator)` menghapus elemen pada posisi yang ditunjuk oleh iterator. Mengembalikan iterator ke elemen berikutnya setelah yang dihapus. 

```cpp
#include <iostream>
#include <map>
#include <string>
#include <iterator> // Untuk next
using namespace std;

int main() {
    map<int, string> students = {
        {101, "Alice"},
        {102, "Bob"},
        {103, "Charlie"}
    };

    cout << "--- Map Awal ---" << endl;
    for (const auto& pair : students) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "Ukuran: " << students.size() << endl << endl;

    // Menghapus elemen berdasarkan iterator (misalnya, elemen kedua)
    auto it_to_erase = next(students.begin(), 1); // Iterator ke Bob
    auto next_it = students.erase(it_to_erase); // Menghapus Bob [1, 5]

    cout << "--- Map Setelah menghapus elemen dengan iterator ---" << endl;
    for (const auto& pair : students) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "Ukuran: " << students.size() << endl;
    if (next_it!= students.end()) {
        cout << "Iterator setelah penghapusan menunjuk ke: " << next_it->first << ": " << next_it->second << endl; // Output: 103: Charlie
    } else {
        cout << "Iterator setelah penghapusan menunjuk ke end()." << endl;
    }

    return 0;
}
```

## 17. `map::erase(first, last)`

Fungsi `erase(first, last)` menghapus rentang elemen yang ditentukan oleh dua iterator (`[first, last)`). 

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<int, string> students = {
        {101, "Alice"},
        {102, "Bob"},
        {103, "Charlie"},
        {104, "David"},
        {105, "Eve"}
    };

    cout << "--- Map Awal ---" << endl;
    for (const auto& pair : students) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "Ukuran: " << students.size() << endl << endl;

    // Menghapus rentang elemen (misalnya, dari Bob (102) hingga sebelum Eve (105))
    auto first_it = students.find(102); // Iterator ke Bob
    auto last_it = students.find(105); // Iterator ke Eve
    
    if (first_it!= students.end() && last_it!= students.end()) {
        students.erase(first_it, last_it); // Menghapus Bob, Charlie, David [1, 5]
    }

    cout << "--- Map Setelah menghapus rentang ---" << endl;
    for (const auto& pair : students) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "Ukuran: " << students.size() << endl;

    return 0;
}
```

## 18. `map::clear()`

Fungsi `clear()` menghapus semua elemen dari map, membuatnya kosong. Setelah operasi ini, `size()` akan mengembalikan 0 dan `empty()` akan mengembalikan `true`. 

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> data = {
        {"A", 1}, {"B", 2}, {"C", 3}
    };

    cout << "--- Map Awal ---" << endl;
    cout << "Ukuran: " << data.size() << endl;
    cout << "Apakah map kosong? " << (data.empty()? "Ya" : "Tidak") << endl << endl;

    // Mengosongkan seluruh map
    data.clear(); [1, 2]

    cout << "--- Map Setelah clear() ---" << endl;
    cout << "Ukuran: " << data.size() << endl; // Output: 0
    cout << "Apakah map kosong? " << (data.empty()? "Ya" : "Tidak") << endl; // Output: Ya

    return 0;
}
```

## 19. `map::find()`

Fungsi `find()` mencari elemen dengan kunci spesifik. Jika elemen ditemukan, ia mengembalikan iterator ke elemen tersebut; jika tidak, ia mengembalikan `end()`. 

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<int, string> inventory = {
        {10, "Laptop"},
        {20, "Monitor"},
        {30, "Keyboard"}
    };

    cout << "--- Map Inventory ---" << endl;
    for (const auto& pair : inventory) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << endl;

    // Mencari elemen yang ada
    auto it_found = inventory.find(20); [1, 2]
    if (it_found!= inventory.end()) {
        cout << "Ditemukan kunci 20: " << it_found->second << endl; // Output: Monitor
    } else {
        cout << "Kunci 20 tidak ditemukan." << endl;
    }

    // Mencari elemen yang tidak ada
    auto it_not_found = inventory.find(99);
    if (it_not_found == inventory.end()) {
        cout << "Kunci 99 tidak ditemukan." << endl; // Output: Kunci 99 tidak ditemukan.
    }

    return 0;
}
```

## 20. `map::count()`

Fungsi `count()` mengembalikan jumlah elemen yang cocok dengan kunci tertentu. Karena `std::map` hanya menyimpan kunci unik, fungsi ini akan selalu mengembalikan 1 jika elemen ditemukan, dan 0 jika tidak. 

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> userPoints = {
        {"Alice", 100},
        {"Bob", 150}
    };

    cout << "--- Map User Points ---" << endl;
    for (const auto& pair : userPoints) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << endl;

    // Memeriksa keberadaan kunci yang ada
    if (userPoints.count("Alice")) { [1, 2]
        cout << "Alice ada dalam map. Poinnya: " << userPoints["Alice"] << endl;
    } else {
        cout << "Alice tidak ada." << endl;
    }

    // Memeriksa keberadaan kunci yang tidak ada
    if (userPoints.count("Charlie")) {
        cout << "Charlie ada dalam map." << endl;
    } else {
        cout << "Charlie tidak ada." << endl; // Output: Charlie tidak ada.
    }

    return 0;
}
```

## 21. `map::contains()` (C++20)

Fungsi `contains()` memeriksa apakah kontainer berisi elemen dengan kunci tertentu. Ini adalah cara yang lebih ringkas dan seringkali lebih jelas daripada `find()!= end()` hanya untuk memeriksa keberadaan elemen. 

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, bool> featureFlags = {
        {"DarkMode", true},
        {"Notifications", false}
    };

    cout << "--- Map Feature Flags ---" << endl;
    for (const auto& pair : featureFlags) {
        cout << pair.first << ": " << (pair.second? "Aktif" : "Tidak Aktif") << endl;
    }
    cout << endl;

    // Memeriksa keberadaan kunci yang ada
    if (featureFlags.contains("DarkMode")) { [1]
        cout << "Fitur DarkMode ada." << endl; // Output: Fitur DarkMode ada.
    }

    // Memeriksa keberadaan kunci yang tidak ada
    if (!featureFlags.contains("Analytics")) {
        cout << "Fitur Analytics tidak ada." << endl; // Output: Fitur Analytics tidak ada.
    }

    return 0;
}
```

## 22. `map::lower_bound()`

Fungsi `lower_bound()` mengembalikan iterator ke elemen pertama dalam map yang _tidak kurang dari_ (`>=`) kunci yang diberikan. 

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<int, char> grades = {
        {65, 'D'}, {70, 'C'}, {80, 'B'}, {90, 'A'}
    };

    cout << "--- Map Grades ---" << endl;
    for (const auto& pair : grades) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << endl;

    // Mencari nilai >= 75
    auto lb = grades.lower_bound(75); [1, 6, 7]
    if (lb!= grades.end()) {
        cout << "Nilai >= 75: " << lb->first << " -> " << lb->second << endl; // Output: 80 -> B
    } else {
        cout << "Tidak ada nilai >= 75." << endl;
    }

    // Mencari nilai >= 90 (kunci yang tepat)
    lb = grades.lower_bound(90);
    if (lb!= grades.end()) {
        cout << "Nilai >= 90: " << lb->first << " -> " << lb->second << endl; // Output: 90 -> A
    }

    // Mencari nilai >= 95 (tidak ada, akan menunjuk ke end())
    lb = grades.lower_bound(95);
    if (lb == grades.end()) {
        cout << "Tidak ada nilai >= 95." << endl; // Output: Tidak ada nilai >= 95.
    }

    return 0;
}
```

## 23. `map::upper_bound()`

Fungsi `upper_bound()` mengembalikan iterator ke elemen pertama dalam map yang _lebih besar dari_ (`>`) kunci yang diberikan.

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<int, char> grades = {
        {65, 'D'}, {70, 'C'}, {80, 'B'}, {90, 'A'}
    };

    cout << "--- Map Grades ---" << endl;
    for (const auto& pair : grades) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << endl;

    // Mencari nilai > 70
    auto ub = grades.upper_bound(70); [1, 6, 7]
    if (ub!= grades.end()) {
        cout << "Nilai > 70: " << ub->first << " -> " << ub->second << endl; // Output: 80 -> B
    } else {
        cout << "Tidak ada nilai > 70." << endl;
    }

    // Mencari nilai > 90 (tidak ada, akan menunjuk ke end())
    ub = grades.upper_bound(90);
    if (ub == grades.end()) {
        cout << "Tidak ada nilai > 90." << endl; // Output: Tidak ada nilai > 90.
    }

    return 0;
}
```

## 24. `map::equal_range()`

Fungsi `equal_range()` mengembalikan `std::pair` dari dua iterator yang mendefinisikan rentang elemen yang cocok dengan kunci tertentu. Iterator pertama adalah hasil dari `lower_bound()` dan yang kedua adalah hasil dari `upper_bound()` untuk kunci yang sama. 

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<int, string> productCodes = {
        {100, "A"}, {101, "B"}, {102, "C"}
    };

    cout << "--- Map Product Codes ---" << endl;
    for (const auto& pair : productCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << endl;

    // Mencari rentang untuk kunci 101
    auto range = productCodes.equal_range(101); [1, 6]
    cout << "Rentang untuk kunci 101:" << endl;
    for (auto it = range.first; it!= range.second; ++it) {
        cout << it->first << ": " << it->second << endl; // Output: 101: B
    }

    // Mencari rentang untuk kunci yang tidak ada
    auto empty_range = productCodes.equal_range(99);
    cout << "\nRentang untuk kunci 99:" << endl;
    if (empty_range.first == empty_range.second) {
        cout << "Rentang kosong, kunci tidak ditemukan." << endl; // Output: Rentang kosong, kunci tidak ditemukan.
    }

    return 0;
}
```

## 25. `map::swap()`

Fungsi `swap()` menukar seluruh isi dua map dengan tipe yang sama secara efisien, biasanya dalam waktu konstan (O(1)). 

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<int, string> map1 = {{1, "One"}, {2, "Two"}};
    map<int, string> map2 = {{3, "Three"}, {4, "Four"}};

    cout << "Sebelum swap:" << endl;
    cout << "Map1: ";
    for (const auto& p : map1) cout << "{" << p.first << ", " << p.second << "} ";
    cout << "\nMap2: ";
    for (const auto& p : map2) cout << "{" << p.first << ", " << p.second << "} ";
    cout << endl;

    map1.swap(map2); // O(1) kompleksitas waktu [1]

    cout << "\nSetelah swap:" << endl;
    cout << "Map1: ";
    for (const auto& p : map1) cout << "{" << p.first << ", " << p.second << "} ";
    cout << "\nMap2: ";
    for (const auto& p : map2) cout << "{" << p.first << ", " << p.second << "} ";
    cout << endl;

    return 0;
}
```

## 26. `map::extract()` (C++17)

Fungsi `extract()` mengekstrak node (elemen) dari kontainer tanpa menghancurkan elemennya. Node yang diekstrak kemudian dapat dimasukkan ke kontainer asosiatif lain yang kompatibel tanpa perlu alokasi atau dealokasi ulang memori elemen. 

```cpp
#include <iostream>
#include <map>
#include <string>
#include <utility> // Untuk move
using namespace std;

int main() {
    map<int, string> originalMap = {{10, "A"}, {20, "B"}, {30, "C"}};
    map<int, string> targetMap;

    cout << "--- Sebelum extract ---" << endl;
    cout << "Original Map: ";
    for (const auto& p : originalMap) cout << "{" << p.first << ", " << p.second << "} ";
    cout << "\nTarget Map: ";
    for (const auto& p : targetMap) cout << "{" << p.first << ", " << p.second << "} ";
    cout << endl;

    // Ekstrak node dengan kunci 20
    auto node = originalMap.extract(20); [1]
    if (!node.empty()) {
        targetMap.insert(move(node)); // Masukkan node ke map lain [1]
    }

    cout << "\n--- Setelah extract dan insert ---" << endl;
    cout << "Original Map: ";
    for (const auto& p : originalMap) cout << "{" << p.first << ", " << p.second << "} "; // Output: {10, A} {30, C}
    cout << "\nTarget Map: ";
    for (const auto& p : targetMap) cout << "{" << p.first << ", " << p.second << "} ";     // Output: {20, B}
    cout << endl;

    return 0;
}
```

## 27. `map::merge()` (C++17)

Fungsi `merge()` menggabungkan node dari kontainer asosiatif lain (misalnya `std: :map` atau `std: :set`) ke map saat ini. Elemen dari `source_map` akan dipindahkan jika kunci mereka unik dan dapat disisipkan ke dalam map ini. 

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<int, string> targetMap = {{10, "Apple"}, {20, "Banana"}};
    map<int, string> sourceMap = {{15, "Grape"}, {20, "Orange"}, {25, "Mango"}}; // Kunci 20 duplikat

    cout << "--- Sebelum merge ---" << endl;
    cout << "Target Map: ";
    for (const auto& p : targetMap) cout << "{" << p.first << ", " << p.second << "} ";
    cout << "\nSource Map: ";
    for (const auto& p : sourceMap) cout << "{" << p.first << ", " << p.second << "} ";
    cout << endl;

    targetMap.merge(sourceMap); [1]
    // Kunci 20 dari sourceMap tidak akan digabungkan karena sudah ada di targetMap

    cout << "\n--- Setelah merge ---" << endl;
    cout << "Target Map: ";
    for (const auto& p : targetMap) cout << "{" << p.first << ", " << p.second << "} ";
    // Output: {10, Apple} {15, Grape} {20, Banana} {25, Mango}
    cout << "\nSource Map (setelah merge, elemen dipindahkan): ";
    for (const auto& p : sourceMap) cout << "{" << p.first << ", " << p.second << "} "; // Output: {20, Orange} (kunci 20 yang tidak dipindahkan)
    cout << endl;

    return 0;
}
```

## 28. Komparator Kustom untuk Tipe Data Buatan Pengguna

`std::map` memungkinkan penggunaan komparator kustom untuk menentukan urutan pengurutan dan definisi keunikan, terutama saat bekerja dengan tipe data buatan pengguna. Komparator dapat diimplementasikan sebagai _functor_ (struct dengan `operator()`) atau _lambda expression_. 

### 28.1. Overloading `operator<` untuk Tipe Kunci

Metode ini paling alami untuk tipe data buatan pengguna. Dengan meng-overload `operator<` di dalam definisi kelas atau _struct_ `Key`, `std::map` akan secara otomatis menggunakan operator ini untuk pengurutan dan penentuan keunikan. 

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

// Tipe data buatan pengguna dengan operator< di-overload
struct Person {
    string name;
    int age;

    // Mengurutkan berdasarkan usia, kemudian nama jika usia sama
    bool operator<(const Person& other) const {
        if (age!= other.age) {
            return age < other.age;
        }
        return name < other.name;
    }
};

int main() {
    // Menggunakan map dengan operator< yang di-overload
    map<Person, string> peopleMapByAge;

    peopleMapByAge[{ "Alice", 30 }] = "Software Engineer";
    peopleMapByAge = "Data Scientist";
    peopleMapByAge[{ "Charlie", 30 }] = "Project Manager"; // Akan diurutkan setelah Alice karena nama
    peopleMapByAge = "UX Designer";   // Akan diurutkan setelah Bob karena nama

    cout << "--- Orang diurutkan berdasarkan Usia kemudian Nama ---" << endl;
    for (const auto& pair : peopleMapByAge) {
        cout << pair.first.name << " (" << pair.first.age << "): " << pair.second << endl;
    }
    // Output:
    // Bob (25): Data Scientist
    // David (25): UX Designer
    // Alice (30): Software Engineer
    // Charlie (30): Project Manager

    return 0;
}
```

### 28.2. Menggunakan Functor (Struct dengan `operator()`)

Sebuah _functor_ adalah objek yang meng-overload `operator()`, memungkinkannya dipanggil seperti fungsi. Metode ini memberikan fleksibilitas yang lebih besar, termasuk kemampuan untuk menyimpan _state_ jika diperlukan. 

```cpp
#include <iostream>
#include <map>
#include <string>
#include <cmath> // Untuk abs
using namespace std;

// Tipe data buatan pengguna
struct City {
    string name;
    int population;
};

// Komparator kustom menggunakan Functor: Mengurutkan berdasarkan populasi (menurun),
// kemudian nama (menaik) jika populasi sama.
struct CompareCityByPopulationDesc {
    bool operator()(const City& c1, const City& c2) const {
        if (c1.population!= c2.population) {
            return c1.population > c2.population; // Urutan menurun berdasarkan populasi
        }
        return c1.name < c2.name; // Urutan menaik berdasarkan nama jika populasi sama
    }
};

int main() {
    // Menggunakan map dengan komparator kustom (Functor)
    map<City, string, CompareCityByPopulationDesc> cityInfo;

    cityInfo = "Japan";
    cityInfo = "India";
    cityInfo = "China";
    cityInfo = "Brazil";
    cityInfo[{ "Mexico City", 9200000 }] = "Mexico";
    cityInfo = "China"; // Populasi lebih rendah dari Shanghai

    cout << "--- Kota diurutkan berdasarkan Populasi (Menurun) dan Nama (Menaik) ---" << endl;
    for (const auto& pair : cityInfo) {
        cout << pair.first.name << " (Populasi: " << pair.first.population << "): " << pair.second << endl;
    }
    // Output akan terurut:
    // Shanghai (Populasi: 26300000): China
    // Beijing (Populasi: 21500000): China
    // Delhi (Populasi: 19000000): India
    // Tokyo (Populasi: 13960000): Japan
    // Sao Paulo (Populasi: 12300000): Brazil
    // Mexico City (Populasi: 9200000): Mexico

    return 0;
}
```

### 28.3. Menggunakan Lambda Expression (C++11+)

Untuk komparator sederhana yang tidak memerlukan _state_ dan digunakan secara lokal, _lambda expression_ menawarkan sintaks yang ringkas dan nyaman. 

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Menggunakan lambda untuk pengurutan terbalik (descending) untuk int
    auto reverseIntCmp =(int a, int b) {
        return a > b; // Mengurutkan secara menurun
    };
    map<int, string, decltype(reverseIntCmp)> reverseMap(reverseIntCmp); [9]

    reverseMap[10] = "Ten";
    reverseMap[11] = "Five";
    reverseMap[12] = "Twenty";
    reverseMap[13] = "One";

    cout << "--- Map Integer diurutkan Menurun ---" << endl;
    for (const auto& pair : reverseMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
    // Output:
    // 20: Twenty
    // 10: Ten
    // 5: Five
    // 1: One

    return 0;
}
```