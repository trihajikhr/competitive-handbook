---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: upper_bound()
sumber:
  - cplusplus.com
date_learned: 2025-08-15T20:07:00
tags:
  - STL
  - STL-algorithm
---
Link Sumber: 
- [cplusplus.com/reference/algorithm/upper\_bound/](https://cplusplus.com/reference/algorithm/upper_bound/)
- [upper\_bound() in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/cpp/upper_bound-in-cpp/)

---
# upper_bound()

## 1 | Definisi Fungsi

Dalam C++, `upper_bound()` adalah fungsi bawaan yang digunakan untuk menemukan elemen pertama dalam rentang terurut yang lebih besar dari nilai tertentu. Fungsi ini mengimplementasikan algoritma *binary search* sehingga rentang tersebut harus diurutkan atau setidaknya dipartisi berdasarkan elemen yang diberikan.

## 2 | Apa itu `upper_bound()`?

* **Istilah C++ STL**:
  `std::upper_bound()` adalah fungsi dari C++ Standard Library yang digunakan untuk menemukan posisi pertama di dalam rentang yang elemennya **lebih besar dari** nilai tertentu.
  Rentang tersebut **harus sudah terurut ascending** atau minimal terpartisi dengan benar terhadap nilai yang dicari.
<br/>

* **Fungsi `upper_bound(first, last, val)`**:
  Mengembalikan *iterator* ke elemen pertama yang **strictly greater** dari `val`.
  Jika tidak ada elemen yang lebih besar, maka mengembalikan `last` (akhir rentang).
<br/>

* **Pendekatan visual**:
  Jika array `v = [1,2,2,3,3,3,4,5,6]` dan `k = 3`, maka:

  * `lower_bound` menunjuk ke elemen pertama yang `>= 3`, yaitu `3`.
  * `upper_bound` menunjuk ke elemen pertama yang `> 3`, yaitu `4`.

---

## 3 | Sintaks dan Parameter

```cpp
auto it = std::upper_bound(first, last, val);
// atau dengan comparator custom
auto it = std::upper_bound(first, last, val, comp);
```

* `first`, `last`: iterator awal dan akhir dari range.
* `val`: nilai pembanding.
* `comp`: (opsional) fungsi pembanding custom, misalnya `std::greater<int>()`.



---

## 4 | Contoh Penggunaan

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};
    cout << *upper_bound(v.begin(), v.end(), 30) << endl; // Output: 40
    return 0;
}
```

Artinya: elemen pertama yang lebih besar dari 30 adalah 40.

Untuk container `set`:

```cpp
set<int> s = {10,20,30,40,50};
auto it = s.upper_bound(30); // *it == 40
```

Hasilnya iterator menuju elemen pertama yang dianggap lebih besar dari `30`.

---

## 5 | Perbedaan `lower_bound()` vs `upper_bound()`

| Fungsi        | Keterangan                          |
| ------------- | ----------------------------------- |
| `lower_bound` | Elemen pertama dimana `elem >= val` |
| `upper_bound` | Elemen pertama dimana `elem > val`  |

Contoh:
Untuk nilai `9` dalam v = `{5,6,9,9,10,...}`:

* `lower_bound` → pertama kali `>= 9` (posisi pertama 9)
* `upper_bound` → pertama kali `> 9` (posisi elemen 10)

Penjelasan dari forum Reddit menyatakan:

> "`lower_bound()` mencari elemen pertama yang **tidak kurang dari target**; sedangkan `upper_bound()` mencari elemen pertama yang **lebih besar dari target**."

---
## 6 | Nilai Kembalian

Mengembalikan sebuah iterator ke elemen terkecil yang **lebih besar** daripada *val*. Jika semua elemen dalam rentang **kurang dari atau sama dengan** nilai yang diberikan, fungsi ini akan mengembalikan iterator ke akhir rentang. Jika semua elemen dalam rentang **lebih besar** dari nilai yang diberikan, fungsi ini akan mengembalikan iterator ke awal rentang.

```ad-danger
Catatan: Jika rentang tidak dalam keadaan terurut atau setidaknya dipartisi berdasarkan nilai yang diberikan, perilaku fungsi ini tidak terdefinisi.
```

Fungsi `std::upper_bound` berguna untuk menemukan posisi pertama di mana suatu nilai dapat disisipkan **setelah** semua elemen yang sama dengan nilai tersebut, dalam sebuah rentang yang sudah terurut.

---
## 7 | Kompleksitas & Legalitas

* Kompleksitas: **O(log n)** di rata-rata — karena algoritma *binary search*.
* Untuk iterator non-random-access (misalnya linked list), `advance()` bisa menambah overhead linear.
* Jika rentang tidak terurut atau tidak terpartisi dengan benar, hasilnya bisa **undefined behavior**.

---

## 8 | Ringkasan Singkat

* **`upper_bound()`**: Cari elemen pertama yang **> nilai target** di rentang terurut.
* **Harus disertai** rentang yang sudah **terurut** (ascending) atau setidaknya terpartisi.
* Mengembalikan iterator, dan bisa dikombinasikan dengan `lower_bound()` untuk menghitung jumlah elemen sama (`equal_range`).

---
## 9 | Latihan Soal

Berikut adalah beberapa latihan soal yang kukerjakan:

- [[01-Tiket Konser dan Upper Bound]]
- [[02-Para Atlet]]
- [[03-Tournament Esport]]