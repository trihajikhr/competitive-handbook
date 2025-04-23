---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSDQ-0001
nama_algoritma: deque data structure
kategori_algoritma: data structure
kesulitan: 
time_complexity: 
memory_complexity: 
sumber: programiz.com & chatgpt.com
date_learned: 2025-04-23T10:53:00
tags:
  - array
  - data-structure
  - deque
---
#array #data-structure #deque

---
# C++ Deque

Dalam C++, STL `deque` adalah kontainer sekuensial yang menyediakan fungsionalitas struktur data **antrian dua ujung** (_double-ended queue_).

Pada queue biasa, elemen ditambahkan dari belakang dan dihapus dari depan. Namun, dalam `deque`, kita bisa menyisipkan dan menghapus elemen dari **depan maupun belakang**.

![[C++ Deque-1.png]]
### Struktur Data Deque

Untuk mempelajari lebih lanjut tentang `deque`, kunjungi topik _Deque Data Structure_.

---

## Membuat Deque di C++ STL

Untuk membuat `deque` di C++, kita terlebih dahulu perlu menyertakan file header `deque`.

```cpp
#include <deque>
```

Setelah kita mengimpor file ini, kita bisa membuat deque dengan sintaks berikut:

```cpp
deque<tipe_data> dq;
```

Di sini, `tipe_data` menunjukkan tipe data yang ingin kita simpan dalam `deque`. Contoh:

```cpp
// membuat deque bertipe integer
deque<int> dq_integer;

// membuat deque bertipe string
deque<string> dq_string;
```

---

## Inisialisasi Deque

Kita bisa menginisialisasi deque C++ dengan cara berikut:

```cpp
// metode 1: initializer list
deque<int> deque1 = {1, 2, 3, 4, 5};

// metode 2: uniform initialization
deque<int> deque2 {1, 2, 3, 4, 5};
```

Kedua `deque1` dan `deque2` di atas diinisialisasi dengan nilai `1, 2, 3, 4, 5`.

---

## Contoh: C++ Deque

```cpp
#include <iostream>
#include <deque>
using namespace std;

// prototipe fungsi
void display_deque(deque<int>);

int main() {
  // uniform initialization
  deque<int> deque1 {1, 2, 3, 4, 5};

  cout << "deque1 = ";
  for (int num : deque1) {
    cout << num << ", ";
  }

  return 0;
}
```

**Output:**

```
deque1 = 1, 2, 3, 4, 5,
```

---

## Cara Lain Membuat Deque di C++

### Membuat `deque` menggunakan _fill constructor_.
Kita juga bisa menginisialisasi sebuah `deque` dengan menyalin elemen dari `deque` lain menggunakan **range constructor**. Ini dikenal sebagai **range method**. Contohnya:

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
    // fill constructor
    deque<int> deque1(5, 12);  // deque1 = {12, 12, 12, 12, 12}

    // range constructor
    deque<int> deque2(deque1.begin(), deque1.end());  // menyalin semua elemen deque1

    // cetak isi deque2
    for (int val : deque2) {
        cout << val << " ";
    }

    return 0;
}
```

Output:

```
12 12 12 12 12
```

#### Penjelasan:

- **`deque<int> deque2(deque1.begin(), deque1.end());`**  
    Ini menggunakan **range constructor**, yang menyalin semua elemen dari `deque1` ke `deque2`.
    

Jadi:

- **Fill constructor** digunakan untuk mengisi `deque` dengan nilai yang sama berulang kali.
    
- **Range constructor** digunakan untuk menyalin elemen dari container lain (misalnya dari `deque` lain atau bagian dari `deque` tersebut).

### Membuat `deque` dari `deque` lain.

Kita juga bisa menentukan rentang elemen tertentu yang ingin kita salin menggunakan **range constructor**.

Contoh:

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> deque1 = {1, 2, 3, 4, 5};

    // salin semua elemen deque1 ke deque2
    deque<int> deque2(deque1.begin(), deque1.end());

    // salin elemen dari indeks 1 sampai 2 (tidak termasuk indeks 3)
    deque<int> deque3(deque1.begin() + 1, deque1.begin() + 3);  // {2, 3}

    // cetak deque3
    for (int val : deque3) {
        cout << val << " ";
    }

    return 0;
}
```

Output:

```
2 3
```

### Penjelasan:

- `deque1.begin() + 1` menunjuk ke elemen di indeks 1, yaitu `2`.
    
- `deque1.begin() + 3` menunjuk ke elemen di indeks 3, yaitu `4`, **tetapi elemen ini tidak termasuk** karena batas akhir pada range constructor bersifat **eksklusif**.
    
- Maka, `deque3` hanya berisi elemen dari indeks 1 dan 2 → `{2, 3}`.
    

Ini adalah fitur yang sangat berguna untuk menyalin sebagian elemen dari sebuah `deque`.

---

## Metode-Metode Deque di C++

Kelas `deque` dalam C++ menyediakan berbagai metode untuk melakukan operasi pada deque.

| Metode         | Deskripsi                              |
| -------------- | -------------------------------------- |
| `push_back()`  | menyisipkan elemen di belakang         |
| `push_front()` | menyisipkan elemen di depan            |
| `pop_back()`   | menghapus elemen dari belakang         |
| `pop_front()`  | menghapus elemen dari depan            |
| `front()`      | mengembalikan elemen di depan          |
| `back()`       | mengembalikan elemen di belakang       |
| `at()`         | mengatur/mengakses elemen di indeks    |
| `size()`       | mengembalikan jumlah elemen            |
| `empty()`      | mengembalikan `true` jika deque kosong |

---

## Menyisipkan Elemen ke Deque

Gunakan metode berikut untuk menyisipkan elemen:

- `push_back()` — menyisipkan elemen di akhir
    
- `push_front()` — menyisipkan elemen di awal
    

### Contoh:

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
  deque<int> nums {2, 3};

  cout << "Initial Deque: ";
  for (const int& num : nums) {
    cout << num << ", ";
  }
  
  // menambahkan 4 di belakang
  nums.push_back(4);

  // menambahkan 1 di depan
  nums.push_front(1);
  
  cout << "\nFinal Deque: ";
  for (const int& num : nums) {
    cout << num << ", ";
  }

  return 0;
}
```

**Output:**

```
Initial Deque: 2, 3,
Final Deque: 1, 2, 3, 4,
```

> Catatan: Kita juga bisa menggunakan metode `insert()` dan `emplace()` untuk menambahkan elemen ke `deque`.

---

## Mengakses Elemen dari Deque

Gunakan metode berikut untuk mengakses elemen:

- `front()` — mengembalikan elemen di depan
    
- `back()` — mengembalikan elemen di belakang
    
- `at()` — mengembalikan elemen di indeks tertentu
    

### Contoh:

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
  deque<int> nums {1, 2, 3};

  cout << "Front element: " << nums.front() << endl;
  cout << "Back element: " << nums.back() << endl;
  cout << "Element at index 1: " << nums.at(1) << endl;
  cout << "Element at index 0: " << nums[0];

  return 0;
}
```

**Output:**

```
Front element: 1
Back element: 3
Element at index 1: 2
Element at index 0: 1
```

> Catatan: Meski kita bisa menggunakan operator `[]`, lebih disarankan memakai `at()` karena akan melempar exception jika indeks keluar batas, sedangkan `[]` hanya mengembalikan nilai sampah (_garbage value_).

---

## Mengubah Elemen di Deque

Gunakan metode `at()` untuk mengubah elemen:

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
  deque<int> nums = {1, 2};

  cout << "Initial Deque: ";
  for (const int& num : nums) {
    cout << num << ", ";
  }

  // ubah elemen di indeks
  nums.at(0) = 3;
  nums.at(1) = 4;

  cout << "\nUpdated Deque: ";
  for (const int& num : nums) {
    cout << num << ", ";
  }

  return 0;
}
```

**Output:**

```
Initial Deque: 1, 2,
Updated Deque: 3, 4,
```

---

## Menghapus Elemen dari Deque

Gunakan metode berikut untuk menghapus elemen:

- `pop_back()` — hapus elemen dari belakang
    
- `pop_front()` — hapus elemen dari depan
    

### Contoh:

```cpp
#include <iostream>
#include <deque>
using namespace std;

// fungsi bantu untuk menampilkan deque
void display_deque(deque<int> dq){
  for (const int& num : dq) {
    cout << num << ", ";
  }
}

int main() {
  deque<int> nums {1, 2, 3};

  cout << "Initial Deque: ";
  display_deque(nums);

  // hapus dari belakang
  nums.pop_back();
  cout << "\nDeque setelah pop_back(): ";
  display_deque(nums);

  // hapus dari depan
  nums.pop_front();
  cout << "\nDeque setelah pop_front(): ";
  display_deque(nums);

  return 0;
}
```

**Output:**

```
Initial Deque: 1, 2, 3,
Deque setelah pop_back(): 1, 2,
Deque setelah pop_front(): 2,
```

---

## Iterator pada C++ Deque

Iterator digunakan untuk menunjuk ke alamat memori dari elemen `deque`.

### Sintaks Membuat Iterator:

```cpp
deque<tipe_data>::iterator nama_iterator;
```

Contoh:

```cpp
deque<int>::iterator iter_int;
deque<double>::iterator iter_double;
```

---

## Mengakses Elemen dengan Iterator

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
  deque<int> nums {1, 2, 3};
  
  // deklarasi iterator
  deque<int>::iterator dq_iter;

  // menunjuk ke elemen pertama
  dq_iter = nums.begin();
  int first_element = *dq_iter;
  cout << "nums[0] = " << first_element << endl;

  // menunjuk ke indeks ke-1
  dq_iter = nums.begin() + 1;
  int element_index1 = *dq_iter;
  cout << "nums[1] = " << element_index1 << endl;

  // menunjuk ke elemen terakhir
  dq_iter = nums.end() - 1;
  int last_element = *dq_iter;
  cout << "nums[2] = " << last_element;

  return 0;
}
```

**Output:**

```
nums[0] = 1
nums[1] = 2
nums[2] = 3
```

Dalam contoh di atas, kita telah menggunakan **iterator** untuk mengakses elemen dalam `deque`. Iterator memungkinkan kita untuk menjelajahi elemen-elemen dalam struktur data seperti array, vector, atau deque, dengan cara yang efisien.

Berikut adalah ringkasan dan contoh penggunaan iterator pada `deque`:

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> nums = {1, 2, 3, 4, 5};

    // deklarasi iterator
    deque<int>::iterator dq_iter;

    // 1. menunjuk ke elemen pertama
    dq_iter = nums.begin();
    cout << "Elemen pertama: " << *dq_iter << endl;  // Output: 1

    // 2. menunjuk ke elemen indeks 1
    dq_iter = nums.begin() + 1;
    cout << "Elemen indeks 1: " << *dq_iter << endl;  // Output: 2

    // 3. menunjuk ke elemen terakhir
    dq_iter = nums.end() - 1;
    cout << "Elemen terakhir: " << *dq_iter << endl;  // Output: 5

    return 0;
}
```

### Penjelasan:

- `nums.begin()` → iterator ke elemen pertama (`1`).
    
- `nums.begin() + i` → iterator ke elemen di indeks `i`.
    
- `nums.end()` → iterator **setelah** elemen terakhir (out-of-bound), sehingga `nums.end() - 1` menunjuk ke elemen terakhir.
    
- `*dq_iter` → mengambil **nilai** dari elemen yang ditunjuk oleh iterator.
    

Iterator sangat berguna ketika kita ingin menelusuri, membaca, atau bahkan memodifikasi elemen dalam container STL seperti `deque`.