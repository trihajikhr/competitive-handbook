---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 03TH-STLS-V001
nama_algoritma: Linear Search
kategori_algoritma: search
kesulitan: 🥉 easy
time_complexity: 🟠 O(n)
memory_complexity: 🟢 O(1)
sumber: Google.com, AI
date_learned: 2025-06-02T10:34:00
tags:
  - linear-search
  - sorting
---
#linear-search #sorting 

---
# Variasi Linear Search C++

Linear Search adalah metode pencarian sederhana yang memeriksa satu per satu elemen dalam suatu koleksi data (seperti array atau vektor) secara berurutan, mulai dari indeks pertama hingga akhir, sampai menemukan elemen yang dicari. Pada setiap langkah, algoritma membandingkan nilai elemen saat ini dengan nilai target; jika sama, proses berhenti dan posisi elemen dikembalikan. Jika tidak, proses berlanjut hingga akhir struktur data. Karena bersifat sekuensial, Linear Search tidak memerlukan data terurut dan dapat diterapkan pada hampir semua tipe kontainer, baik array statis, dinamis, maupun struktur lain yang mendukung iterasi.

Meski sangat mudah diimplementasikan dan tidak membutuhkan pra-pengurutan, kekurangannya adalah efisiensi: waktu rata-rata dan terburuknya adalah $O(n)$, karena dalam kasus terburuk (elemen tidak ada atau ada di ujung terjauh) algoritma harus memeriksa semua elemen. Oleh karena itu, Linear Search cocok untuk koleksi berukuran kecil hingga sedang atau saat data tidak bisa diurutkan dengan mudah, tetapi kurang optimal untuk dataset besar jika dibandingkan dengan algoritma pencarian berperforma lebih tinggi (misalnya Binary Search pada data terurut).

---

## 1 | Metode Manual (Tanpa Fungsi)
Penjelasan:  
Melakukan iterasi `for` biasa ke dalam array (atau vector), membandingkan satu per satu elemen dengan nilai target.  
- Kelebihan: Sangat straightforward, cocok untuk cepat mencoba konsep dasar.  
- Kekurangannya: Kode menjadi verbose jika digunakan berulang kali di berbagai tempat.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = { 5, 2, 9, 1, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;
    int index = -1;  // Default jika tidak ditemukan

    // Mulai linear search manual
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            index = i;
            break;   // hentikan setelah menemukan kemunculan pertama
        }
    }

    if (index != -1) {
        cout << "Ditemukan " << target << " di indeks ke-" << index << "\n";
    } else {
        cout << target << " tidak ditemukan dalam array\n";
    }

    return 0;
}
````

- **Cara Kerja:**
    
    1. `for (int i = 0; i < n; i++)`: iterasi indeks dari 0 hingga `n-1`.
        
    2. `if (arr[i] == target)`: jika sama, simpan posisi `i` ke `index`, lalu `break`.
        
    3. Setelah loop, cek `index`: jika bukan `-1`, berarti ditemukan; kalau masih `-1`, berarti tidak ditemukan.
        

---

## 2 | Metode Fungsi untuk Array Biasa (C-Style Array)

Penjelasan:  
Membungkus prosedur linear search manual ke dalam fungsi reusable yang menerima:

- Pointer ke array (atau nama array)
    
- Panjang array (`n`)
    
- Nilai target  
    Mengembalikan indeks pertama kali ditemukan (atau `-1` jika tidak ditemukan).
    

```cpp
#include <iostream>
using namespace std;

/**
 * Melakukan linear search pada C-style array.
 * @param arr     : pointer/array of int
 * @param n       : ukuran array
 * @param target  : nilai yang dicari
 * @return        : indeks elemen pertama yang sama dengan target; -1 jika tidak ditemukan
 */
int linearSearchArray(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;   // langsung kembalikan indeks
        }
    }
    return -1;    // tidak ditemukan
}

int main() {
    int arr[] = { 3, 8, 2, 7, 4, 1 };
    int n  = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int idx = linearSearchArray(arr, n, target);
    if (idx != -1)
        cout << "Ditemukan " << target << " di indeks ke-" << idx << "\n";
    else
        cout << target << " tidak ditemukan\n";

    return 0;
}
```

- **Catatan:**
    
    - Parameter `int arr[]` secara implisit diperlakukan sebagai `int* arr`, sehingga ukuran (length) harus dipisahkan sebagai `n`.
        
    - Mengembalikan `int` adalah indeks; `-1` menandakan “tidak ada”.
        

---

## 3. Metode Fungsi untuk `std::vector<T>`

Penjelasan:  
Karena `std::vector` memiliki metode `.size()`, tinggal iterasi dengan `vector[index]` atau gunakan iterator.

- Lebih modern dan type-safe dibandingkan C-style array.
    
- Dapat digeneralisasi menggunakan `template`.
    

### 3.1 | `linearSearchVector` (untuk `vector<int>`)

```cpp
#include <iostream>
#include <vector>
using namespace std;

/**
 * Linear search pada std::vector<int>.
 * @param vec     : vektor integer
 * @param target  : nilai yang dicari
 * @return        : indeks elemen pertama yang sama dengan target; -1 jika tidak ditemukan
 */
int linearSearchVector(const vector<int>& vec, int target) {
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] == target) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

int main() {
    vector<int> data = { 10, 15, 8, 7, 25 };
    int target = 8;

    int idx = linearSearchVector(data, target);
    if (idx != -1)
        cout << "Ditemukan " << target << " di indeks ke-" << idx << "\n";
    else
        cout << target << " tidak ditemukan\n";

    return 0;
}
```

#### Fungsi:

```cpp
int linearSearchVector(const vector<int>& vec, int target)
```

- Fungsi ini bernama `linearSearchVector`.
    
- Menerima dua parameter:
    
    - `const vector<int>& vec` → vektor bilangan bulat yang akan dicari (diberi `const` karena tidak diubah dan `&` agar tidak terjadi penyalinan data).
        
    - `int target` → nilai yang ingin dicari dalam vektor.
        
- Fungsi mengembalikan sebuah `int`, yaitu indeks elemen `target` jika ditemukan, atau `-1` jika tidak ditemukan.
    

---

#### Isi fungsi:

```cpp
for (size_t i = 0; i < vec.size(); i++) {
```

- Ini adalah perulangan dari indeks `i = 0` hingga `i < vec.size()`.
    
- `size_t` digunakan karena `vec.size()` menghasilkan tipe unsigned (non-negatif).
    
- Perulangan ini memeriksa setiap elemen dalam vektor satu per satu.

> Cari tahu tentang `size_t` di [[Penggunaan size_t dan perbedaanya dengan Int pada Loop]]

---

```cpp
    if (vec[i] == target) {
```

- Mengecek apakah elemen pada indeks ke-`i` sama dengan nilai `target`.
    
- Jika sama, maka artinya elemen sudah ditemukan.
    

---

```cpp
        return static_cast<int>(i);
```

- Mengembalikan nilai indeks `i` sebagai `int`.
    
- Kenapa pakai `static_cast<int>`? Karena `i` bertipe `size_t` (unsigned), sedangkan fungsi mengembalikan `int` (signed). Ini mencegah peringatan konversi tipe data.

> Ketahui lebih lanjut tentang `static_cast` di [[Apa itu static_cast]]

---

```cpp
return -1;
```

- Kalau perulangan selesai tanpa menemukan `target`, maka fungsi mengembalikan `-1`, menandakan "tidak ditemukan".
    

---

#### Contoh penggunaan:

```cpp
vector<int> data = {10, 20, 30, 40, 50};
int pos = linearSearchVector(data, 30);  // hasil: 2
int pos2 = linearSearchVector(data, 99); // hasil: -1
```

---

#### Catatan tambahan:

- Fungsi ini hanya mencari satu nilai pertama yang cocok.
    
- Jika ada nilai duplikat, hanya indeks pertama yang dikembalikan.
### 3.2 | Template Umum (Generic)

```cpp
#include <iostream>
#include <vector>
using namespace std;

/**
 * Linear search generic pada std::vector<T>.
 * @tparam T       : tipe data (mis. int, double, string, dll.)
 * @param vec      : vektor dengan elemen berjenis T
 * @param target   : nilai target berjenis T
 * @return         : indeks elemen pertama yang sama dengan target; -1 jika tidak ditemukan
 */
template <typename T>
int linearSearch(const vector<T>& vec, const T& target) {
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] == target) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

int main() {
    vector<string> names = { "Andi", "Budi", "Cici", "Dodi" };
    string targetName = "Cici";

    int idx = linearSearch(names, targetName);
    if (idx != -1)
        cout << "Ditemukan \"" << targetName << "\" di indeks ke-" << idx << "\n";
    else
        cout << "\"" << targetName << "\" tidak ditemukan\n";

    return 0;
}
```

- **Penjelasan Template:**
    
    - `template <typename T>` artinya fungsi bekerja untuk `vector<T>`, bisa `int`, `double`, `string`, dsb.
        
    - Mengembalikan `int` sebagai indeks (casting dari `size_t`).

> Pelajari lebih tentang template di:
> - [[Template di C++]]
> - [[Contoh Template C++]]

---

## 4 | Mengembalikan Boolean (Cek Ada/Tidak)

Kadang kita hanya perlu memeriksa apakah `target` ada dalam koleksi, tanpa butuh indeks.

- Kembalikan `true` jika ada, `false` jika tidak.
    

```cpp
#include <iostream>
#include <vector>
using namespace std;

/**
 * Mengecek keberadaan target di dalam koleksi tanpa mengembalikan indeks.
 * @tparam T       : tipe data
 * @param vec      : vektor berjenis T
 * @param target   : nilai target
 * @return         : true jika target ada; false jika tidak
 */
template <typename T>
bool contains(const vector<T>& vec, const T& target) {
    for (const auto& item : vec) {
        if (item == target) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> angka = { 4, 6, 2, 9, 1 };
    int cari = 9;
    if (contains(angka, cari))
        cout << cari << " ditemukan dalam vektor\n";
    else
        cout << cari << " tidak ditemukan\n";
    return 0;
}
```

- **Catatan:**
    
    - Versi ini lebih ringkas karena menggunakan _range-based for_ (`for (const auto& item : vec)`).
        
    - Mengembalikan boolean lebih efisien jika tidak butuh tahu di posisi mana.
        

---

## 5 | Menggunakan `std::find` (STL)

Daripada menulis loop manual, bisa memanfaatkan algoritma `std::find` (`<algorithm>`).

- Kelebihan: Kode lebih ringkas, memanfaatkan implementasi STL.
    
- `std::find` mengembalikan iterator ke elemen yang ditemukan, atau `end()` jika tidak ada.
    

```cpp
#include <iostream>
#include <vector>
#include <algorithm>  // std::find
using namespace std;

int main() {
    vector<int> vec = { 5, 3, 7, 1, 4 };
    int target = 7;

    auto it = find(vec.begin(), vec.end(), target);
    if (it != vec.end()) {
        int idx = static_cast<int>(distance(vec.begin(), it));
        cout << "Ditemukan " << target << " di indeks ke-" << idx << "\n";
    } else {
        cout << target << " tidak ditemukan\n";
    }
    return 0;
}
```

- **Penjelasan:**
    
    1. `auto it = find(vec.begin(), vec.end(), target);`
        
    2. Jika `it != vec.end()`, berarti ditemukan—lalu gunakan `distance(vec.begin(), it)` untuk konversi iterator ke indeks (`size_t`), casting ke `int`.
        
    3. Jika `it == vec.end()`, berarti tidak ditemukan.
        

---

## 6 | Mengembalikan `std::optional<int>` (C++17 ke Atas)

Daripada menggunakan `-1` atau `bool`, kita bisa memanfaatkan `std::optional<int>` untuk mengindikasikan “ada” (dengan nilai indeks) atau “tidak ada” (empty).

- Lebih idiomatik di C++17+ jika ingin mengekspresikan nilai yang mungkin tidak ada.
    

```cpp
#include <iostream>
#include <vector>
#include <optional>   // std::optional
using namespace std;

/**
 * Linear search yang mengembalikan std::optional<int>.
 * - Jika ditemukan, return std::optional berisi indeks.
 * - Jika tidak ditemukan, return std::nullopt.
 */
template <typename T>
optional<int> linearSearchOpt(const vector<T>& vec, const T& target) {
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] == target) {
            return static_cast<int>(i);
        }
    }
    return nullopt;
}

int main() {
    vector<int> data = { 2, 4, 6, 8, 10 };
    int target = 6;

    optional<int> result = linearSearchOpt(data, target);
    if (result.has_value()) {
        cout << "Ditemukan " << target << " di indeks ke-" << result.value() << "\n";
    } else {
        cout << target << " tidak ditemukan\n";
    }
    return 0;
}
```

- **Keuntungan `std::optional`:**
    
    - Jelas membedakan antara “ditemukan pada indeks 0” dan “tidak ditemukan”.
        
    - Developer dipaksa melakukan pengecekan `has_value()` sebelum akses `value()`.
        

---

# Complexitas dan Catatan Akhir

- **Waktu (Time Complexity):**
    
    - **Best Case:** $O(1)$ → target adalah elemen pertama (index 0).
        
    - **Worst/Average Case:** $O(n)$ → target ada di akhir atau tidak ada (harus cek semua).

<br/>

- **Ruang (Space Complexity):**
    
    - $O(1)$ → hanya variabel counter dan/atau iterator, tidak ada struktur tambahan yang bergantung pada $n$.

<br/>

- **Stability & Order:**
    
    - Linear Search bersifat stable (tidak merubah urutan elemen manapun).

<br/>

- **Kapan Gunakan:**
    
    - Untuk ukuran data kecil hingga sedang ($n$ beberapa ribu atau puluhan ribu).
        
    - Ketika data tidak terurut (unsorted) dan kita hanya perlu cek keberadaan atau posisi pertama.
        

---

## Ringkasan Variasi

**Ringkasan Variasi Linear Search C++**

1. **Manual Loop (Tanpa Fungsi)**  
    Iterasi langsung di `main()` untuk mencari elemen.

	```cpp
	for(int i=0;i<n;i++){
		if(arr[i]==target){
			idx=i;
			break;
		}
	}
	```

	
2. **Fungsi untuk C-Style Array**  
    Membungkus proses ke dalam function:
    
    ```cpp
    int linearSearchArray(int arr[], int n, int target);
    ```
    
3. **Fungsi untuk `std::vector<int>` (Non-Template)**
    Alih-alih menggunakan C-Style Array, kita menggunakan struktur data vector yang lebih dinamis dan fleksible dalam penggunaan:
    ```cpp
    int linearSearchVector(const vector<int>& vec, int target);
    ```
    
4. **Fungsi Template untuk `std::vector<T>`**
    Menggunakan Template untuk mempercepat dan mempermudah deteksi tipe data:
    ```cpp
    template<typename T>
    int linearSearch(const vector<T>& vec, const T& target);
    ```
    
5. **Pengembalian Boolean (Ada/Tidak)**
    Menggunakan boolean untuk return `true` jika ditemukan, atau `false` jika tidak ditemukan:
    ```cpp
    template<typename T>
    bool contains(const vector<T>& vec, const T& target);
    ```
    
6. **Menggunakan STL `std::find`**
    Menggunakan bantuan fungsi bawaan dari header `<algorithm>`, dipasangkan dengan struktur data vector:
    ```cpp
    auto it = find(vec.begin(), vec.end(), target);
    ```
    
7. **Mengembalikan `std::optional<int>`**
    Menggunakan metode `std::optional` untuk menentukan "ada" atau "tidak" daya yang dicari, dan jika ada, kita ambil valuenya:
    ```cpp
    template<typename T>
    optional<int> linearSearchOpt(const vector<T>& vec, const T& target);
    ```
    

---

### 1. Manual Loop (Tanpa Fungsi)

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;
    int index = -1;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            index = i;
            break;
        }
    }
    
    if (index != -1)
        cout << "Ditemukan " << target << " di indeks ke-" << index << "\n";
    else
        cout << target << " tidak ditemukan\n";
    
    return 0;
}
```

---

### 2. Fungsi untuk C-Style Array

```cpp
#include <iostream>
using namespace std;

int linearSearchArray(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {3, 8, 2, 7, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int idx = linearSearchArray(arr, n, target);
    if (idx != -1)
        cout << "Ditemukan " << target << " di indeks ke-" << idx << "\n";
    else
        cout << target << " tidak ditemukan\n";

    return 0;
}
```

---

### 3. Fungsi untuk `std::vector<int>` (Non-Template)

```cpp
#include <iostream>
#include <vector>
using namespace std;

int linearSearchVector(const vector<int>& vec, int target) {
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] == target) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

int main() {
    vector<int> data = {10, 15, 8, 7, 25};
    int target = 8;

    int idx = linearSearchVector(data, target);
    if (idx != -1)
        cout << "Ditemukan " << target << " di indeks ke-" << idx << "\n";
    else
        cout << target << " tidak ditemukan\n";

    return 0;
}
```

---

### 4. Template untuk `std::vector<T>`

```cpp
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
int linearSearch(const vector<T>& vec, const T& target) {
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] == target) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

int main() {
    vector<string> names = {"Andi", "Budi", "Cici", "Dodi"};
    string targetName = "Cici";

    int idx = linearSearch(names, targetName);
    if (idx != -1)
        cout << "Ditemukan \"" << targetName << "\" di indeks ke-" << idx << "\n";
    else
        cout << "\"" << targetName << "\" tidak ditemukan\n";

    return 0;
}
```

---

### 5. Variasi Boolean (Ada/Tidak)

```cpp
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
bool contains(const vector<T>& vec, const T& target) {
    for (const auto& item : vec) {
        if (item == target) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> angka = {4, 6, 2, 9, 1};
    int cari = 9;
    
    if (contains(angka, cari))
        cout << cari << " ditemukan dalam vektor\n";
    else
        cout << cari << " tidak ditemukan\n";
    
    return 0;
}
```

---

### 6. Menggunakan STL `std::find`

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec = {5, 3, 7, 1, 4};
    int target = 7;

    auto it = find(vec.begin(), vec.end(), target);
    if (it != vec.end()) {
        int idx = static_cast<int>(distance(vec.begin(), it));
        cout << "Ditemukan " << target << " di indeks ke-" << idx << "\n";
    } else {
        cout << target << " tidak ditemukan\n";
    }

    return 0;
}
```

---

### 7. Mengembalikan `std::optional<int>`

```cpp
#include <iostream>
#include <vector>
#include <optional>
using namespace std;

template <typename T>
optional<int> linearSearchOpt(const vector<T>& vec, const T& target) {
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] == target) {
            return static_cast<int>(i);
        }
    }
    return nullopt;
}

int main() {
    vector<int> data = {2, 4, 6, 8, 10};
    int target = 6;

    optional<int> result = linearSearchOpt(data, target);
    if (result.has_value()) {
        cout << "Ditemukan " << target << " di indeks ke-" << result.value() << "\n";
    } else {
        cout << target << " tidak ditemukan\n";
    }
    
    return 0;
}
```