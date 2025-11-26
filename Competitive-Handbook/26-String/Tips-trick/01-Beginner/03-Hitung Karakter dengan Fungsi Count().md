---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Hitung Karakter dengan Fungsi Count()
sumber:
  - codeforces.com
date_learned: 2025-09-24T19:51:00
tags:
  - string
  - tips-trick
---
Link Sumber: 

---
# Hitung Karakter dengan Fungsi Count()

Fungsi **`std::count()`** merupakan bagian dari library **`<algorithm>`** di C++. Fungsi ini digunakan untuk **menghitung banyaknya kemunculan suatu nilai** dalam sebuah rentang, termasuk karakter pada string. Karena `std::string` mendukung iterator (`begin()` dan `end()`), maka `count()` dapat langsung diterapkan pada string untuk menghitung jumlah kemunculan sebuah karakter tertentu.

Berikut sintaksnya:

```cpp
std::count(first, last, value);
```

**Parameter**:

* `first` → iterator awal (misalnya `s.begin()`)
* `last` → iterator akhir (misalnya `s.end()`)
* `value` → nilai yang ingin dihitung jumlah kemunculannya (misalnya `'a'`)

**Nilai Kembali**:

* Sebuah bilangan bulat (`int`) yang menyatakan jumlah kemunculan `value` di dalam rentang `[first, last)`.

Berikut contoh penggunaanya:

```cpp
#include <iostream>
#include <string>
#include <algorithm> // diperlukan untuk std::count
using namespace std;

int main() {
    string teks = "programming";

    // hitung jumlah huruf 'g'
    int jumlahG = count(teks.begin(), teks.end(), 'g');

    // hitung jumlah huruf 'm'
    int jumlahM = count(teks.begin(), teks.end(), 'm');

    cout << "Jumlah huruf 'g' : " << jumlahG << '\n';
    cout << "Jumlah huruf 'm' : " << jumlahM << '\n';
    return 0;
}
```

Output

```
Jumlah huruf 'g' : 2
Jumlah huruf 'm' : 2
```
## Kesimpulan

Fungsi **`std::count()`** sangat berguna untuk **menghitung jumlah kemunculan karakter tertentu dalam string**. Dengan memanfaatkan iterator `begin()` dan `end()`, kita dapat menghitung karakter apapun dalam string dengan cara yang sederhana, cepat, dan mudah dibaca.
