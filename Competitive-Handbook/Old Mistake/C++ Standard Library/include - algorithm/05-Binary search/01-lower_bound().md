---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: lower_bound()
sumber:
  - cplusplus.com
  - chatgpt.com
  - geeksforgeeks.org
date_learned: 2025-08-15T16:01:00
tags:
  - STL
  - STL-algorithm
---
Link Sumber: 
- [cplusplus.com/reference/algorithm/lower\_bound/](https://cplusplus.com/reference/algorithm/lower_bound/)
- [lower\_bound in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/cpp/lower_bound-in-cpp/)

---
# lower_bound

## 1 | Definisi fungsi

- `std::lower_bound()` adalah fungsi di header `<algorithm>` yang digunakan untuk mencari posisi pertama di sebuah rentang **terurut** di mana nilai di situ **tidak kurang dari** (≥) nilai yang dicari.

```ad-danger
**ARRAY YANG DIGUNAKAN UNTUK `lower_bound()` HARUS SUDAH DISORTING!**

Iya, **wajib** kalau mau hasilnya benar.
`std::lower_bound` (dan juga `std::upper_bound`) hanya bekerja dengan benar **jika**:

1. **Urutan datanya sudah di-*sort* sesuai kriteria perbandingan** (`operator<` default, atau comparator yang kamu kasih sendiri).
2. Atau minimal, datanya sudah di-*partition* sehingga semua elemen `< val` ada di depan, dan sisanya di belakang.

Kalau datanya belum di-*sort*, `lower_bound` bisa kasih hasil yang salah total, karena algoritmanya itu **binary search**—dia langsung loncat ke tengah, lalu ke kiri/kanan berdasarkan asumsi bahwa data terurut.

💡 Singkatnya:

* Mau cari pakai *binary search* → data harus terurut.
* Mau pakai `lower_bound` → anggap aja *binary search with twist*, jadi ya, **urutkan dulu**.
```

- Karena menggunakan binary search, waktu pencariannya efisien, yaitu **O(log n)**.

---

## 2 | Materi dari cplusplus.com
### 2.1 | Ringkasan

**ℹ️ Definisi resminya:**

> Fungsi mengembalikan iterator ke elemen pertama dalam rentang `[first, last)` yang **tidak dianggap lebih kecil dari** `val`. Jika semuanya lebih kecil dari `val`, maka dikembalikan `last`.

**ℹ️ Implementasi logika dasarnya secara pseudo-code:**
    
```cpp
// default
template <class ForwardIterator, class T>  
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val);

// custom
template <class ForwardIterator, class T, class Compare>  
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);
```

**ℹ️ Kompleksitas:**
- Untuk random-access iterator: logaritmik (≈ log₂(N) + 1 perbandingan)
- Untuk iterator non-random (misalnya list): bisa jadi lebih lambat karena traversal.

**ℹ️ Contoh penggunaan:**

```cpp
int myints[] = {10,20,30,30,20,10,10,20};
std::vector<int> v(myints, myints+8); // 10 20 30 30 20 10 10 20
std::sort(v.begin(), v.end());        // 10 10 10 20 20 20 30 30

auto low = std::lower_bound(v.begin(), v.end(), 20);
auto up = std::upper_bound(v.begin(), v.end(), 20);

std::cout << "lower_bound at position " << (low - v.begin()) << '\n';
std::cout << "upper_bound at position " << (up - v.begin()) << '\n';
```

Output:

```
lower_bound at position 3
upper_bound at position 6
```

### 2.2 | Versi Lengkap

#### 2.2.1 | Mengembalikan iterator ke *lower bound*

Mengembalikan sebuah *iterator* yang menunjuk ke **elemen pertama** dalam rentang $[first, last)$ yang **tidak lebih kecil** dibandingkan `val`.

Elemen-elemen dibandingkan menggunakan `operator<` untuk versi pertama, dan fungsi `comp` untuk versi kedua.

Elemen dalam rentang tersebut **harus sudah terurut** berdasarkan kriteria yang sama (`operator<` atau `comp`), atau setidaknya **terpartisi** dengan benar terhadap `val`.

Fungsi ini mengoptimalkan jumlah perbandingan yang dilakukan dengan cara **membandingkan elemen yang tidak berurutan** di dalam rentang terurut, sehingga sangat efisien untuk *random-access iterator*.

Berbeda dengan `upper_bound`, nilai yang ditunjuk oleh *iterator* hasil fungsi ini **dapat sama dengan** `val`, tidak hanya lebih besar.
#### 2.2.2 | Perilaku fungsi ini

Perilakunya setara dengan:

```cpp
template <class ForwardIterator, class T>
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val)
{
  ForwardIterator it;
  iterator_traits<ForwardIterator>::difference_type count, step;
  count = distance(first, last);
  while (count > 0)
  {
    it = first; 
    step = count / 2; 
    advance(it, step);
    if (*it < val) { // atau: if (comp(*it, val)), untuk versi (2)
      first = ++it;
      count -= step + 1;
    }
    else count = step;
  }
  return first;
}
```

#### 2.2.3 | Parameter

```cpp
std::lower_bound (first, last, val, comp);
```

* **`first`, `last`**
  *Forward iterator* yang menunjuk ke posisi awal dan akhir dari sebuah *sequence* yang terurut (atau terpartisi dengan benar). Rentang yang digunakan adalah $[first, last)$, yang mencakup semua elemen mulai dari `first` **hingga sebelum** `last`.
<br/>

* **`val`**
  Nilai *lower bound* yang dicari di dalam rentang. Untuk versi (1), `T` harus dapat dibandingkan dengan elemen di dalam $[first, last)$ sebagai operand kanan dari `operator<`.
<br/>

* **`comp`** (opsional)
  Fungsi biner yang menerima dua argumen:

  1. Elemen dari tipe yang ditunjuk oleh *ForwardIterator*.
  2. Nilai `val`.

  Fungsi ini mengembalikan nilai yang bisa dikonversi ke `bool`. Nilai `true` berarti argumen pertama dianggap datang **sebelum** argumen kedua. Fungsi ini tidak boleh mengubah argumen-argumennya. `comp` dapat berupa *function pointer* atau *function object*. Biasa digunakan untuk fungsi pembanding custom.

#### 2.2.4 | Nilai Kembalian

* Sebuah *iterator* ke *lower bound* dari `val` di rentang.
* Jika semua elemen dalam rentang lebih kecil dari `val`, fungsi mengembalikan `last`.

**Berikut versi GeeksForGeeks**:

- Mengembalikan sebuah _iterator_ ke elemen terkecil yang nilainya **lebih besar atau sama dengan** `val`.  
- Jika semua elemen dalam _range_ bernilai **lebih kecil** dari nilai yang diberikan, fungsi ini akan mengembalikan _iterator_ ke **akhir range**.  
- Jika semua elemen dalam _range_ bernilai **lebih besar** dari nilai yang diberikan, fungsi ini akan mengembalikan _iterator_ ke **awal range**.

```ad-danger
**Catatan:** Jika _range_ tidak di-_sort_ atau setidaknya tidak di-_partition_ sesuai dengan nilai yang diberikan, perilaku fungsi ini tidak terdefinisi.
```

```ad-tip
Fungsi `std::lower_bound` berguna untuk mencari posisi pertama di mana sebuah nilai dapat disisipkan di dalam _range_ yang sudah terurut.
```

#### 2.2.5 | Contoh

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints, myints+8);  // 10 20 30 30 20 10 10 20

  std::sort(v.begin(), v.end());         // 10 10 10 20 20 20 30 30

  std::vector<int>::iterator low, up;
  low = std::lower_bound(v.begin(), v.end(), 20); //           ^
  up  = std::upper_bound(v.begin(), v.end(), 20); //                    ^

  std::cout << "lower_bound at position " << (low - v.begin()) << '\n';
  std::cout << "upper_bound at position " << (up  - v.begin()) << '\n';

  return 0;
}
```

**Keluaran:**

```
lower_bound at position 3
upper_bound at position 6
```

#### 2.2.6 | Kompleksitas

* Rata-rata: **logaritmik** terhadap jarak antara `first` dan `last`.
  Melakukan sekitar $\log_2(N) + 1$ perbandingan elemen, di mana $N$ adalah jarak tersebut.
* Untuk *non-random-access iterator*, operasi `advance` menambah kompleksitas linear terhadap $N$ rata-rata.

#### 2.2.7 | Data Races

* Elemen-elemen dalam rentang $[first, last)$ diakses.

#### 2.2.8 | Pengecualian

* Melempar *exception* jika perbandingan elemen atau operasi iterator melempar exception.
* Argumen yang tidak valid menyebabkan *undefined behavior*.

---

## 3 | Perbandingan `lower_bound` vs `upper_bound`

| Fungsi        | Kriteria Pencarian                              | Hasil                                                           |
| ------------- | ----------------------------------------------- | --------------------------------------------------------------- |
| `lower_bound` | Elemen pertama `e` dimana `e >= val`            | Jika ada, pointer ke elemen itu; jika tidak, pointer ke `last`. |
| `upper_bound` | Elemen pertama `e` dimana `e > val`             | Jika tidak ditemukan, pointer ke `last`.                        |


Visualisasi untuk array `[1,2,2,3,3,3,4,...]`:

```
lower_bound → posisi pertama 3
upper_bound → posisi pertama > 3 (yaitu 4)
```

---
## 4 | Kegunaan Praktis `std::lower_bound`

- **Menemukan posisi sisipan** nilai dalam struktur terurut (sebagai titik sisip).
- **Cek keberadaan nilai**:
    
    ```cpp
    auto it = std::lower_bound(v.begin(), v.end(), val);
    if (it != v.end() && *it == val) {
      // val ditemukan
    }
    ```
    
- **Menghitung jumlah elemen kecil atau besar** dibanding nilai:
    
    ```cpp
    int smaller = lb - v.begin();
    int larger  = v.size() - smaller;
    ```
    
- **Insert dalam vector terurut**:
    
    ```cpp
    auto lb = std::lower_bound(v.begin(), v.end(), val);
    v.insert(lb, val);
    ```
    
- Pada **set/map**, ada versi member `lower_bound()` yang serupa, tapi menggunakan struktur pohon ($\log n$) di baliknya.
    

---

## 5 | Contoh Kode (Singkat & Praktis)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};
    int val = 35;

    auto it = lower_bound(v.begin(), v.end(), val);
    if (it != v.end()) {
        cout << "Found lower_bound: " << *it
             << " at index " << (it - v.begin()) << "\n";
    } else {
        cout << "No element >= " << val << "\n";
    }

    // Contoh insert:
    v.insert(it, val);
    cout << "After insert: ";
    for (int x : v) cout << x << " ";
    cout << "\n";
    return 0;
}
```

---

## 6 | Tip Lanjutan dari Komunitas

Ingin mencari elemen **paling besar yang ≤ val**? Penjelasan dari Reddit:

> “Gunakan `upper_bound` untuk mendapatkan iterator ke elemen pertama yang **lebih besar dari** `val`. Kemudian `--it` untuk mendapatkan elemen tepat di bawah (≤ val).”

Contohnya:

```cpp
auto it = upper_bound(v.begin(), v.end(), val);
if (it != v.begin()) {
    --it;
    // *it adalah elemen ≤ val
}
```

---

## 7 | Kesimpulan

`std::lower_bound()` adalah alat yang powerful untuk bekerja dengan data terurut—apakah itu untuk pencarian, sisipan, atau analisis posisi. Materi lengkap dan implementasi resmi bisa kamu pelajari di cplusplus.com seperti yang sudah saya sertakan di atas.

---

## 8 | Latihan
Ini adalah latihan menggunakan `lower_bound()`:

- [[01-Mencari Posisi Siswa]]
- [[02-Konser dan Tiket]]
- [[03-Tiket Sekali Pakai]]
