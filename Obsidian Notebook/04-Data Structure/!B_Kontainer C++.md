---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DS00-0002
nama_algoritma:
kategori_algoritma: data structure
kesulitan:
time_complexity:
memory_complexity:
sumber:
  - programiz.com
  - chatgpt.com
date_learned: 2025-04-23T09:40:00
tags:
  - array
  - data-structure
---
#array #data-structure 

---
# Kontainer STL C++

Sebuah _container_ (kontainer) adalah objek yang menyimpan sekumpulan objek dari tipe tertentu. Misalnya, jika kita perlu menyimpan daftar nama, kita dapat menggunakan `vector`.

STL (Standard Template Library) di C++ menyediakan berbagai jenis kontainer sesuai dengan kebutuhan kita.

---

### Jenis Kontainer STL dalam C++

Secara umum, terdapat 3 jenis kontainer dalam STL C++:

1. **Sequential Containers**
    
2. **Associative Containers**
    
3. **Unordered Associative Containers**
    

---

## 1. Sequential Containers dalam C++

Dalam C++, _sequential container_ memungkinkan kita menyimpan elemen yang dapat diakses secara berurutan.

Secara internal, _sequential container_ diimplementasikan sebagai struktur data array atau linked list.

#### Jenis Sequential Containers:

- `array`
    
- `vector`
    
- `deque`
    
- `list`
    
- `forward_list`
    

#### Contoh: Sequential Container C++ (`vector`)

Dalam contoh ini, kita akan menggunakan kelas `vector` untuk mendemonstrasikan cara kerja _sequential container_.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
  // inisialisasi vector bertipe int
  vector<int> numbers = {1, 100, 10, 70, 100};

  // cetak vector
  cout << "Numbers are: ";
  for(auto &num: numbers) {
    cout << num << ", ";
  }

  return 0;
}
```

**Output:**

```
Numbers are: 1, 100, 10, 70, 100,
```

Dalam contoh di atas, kita membuat _sequential container_ bernama `numbers` menggunakan kelas `vector`.

```cpp
vector<int> numbers = {1, 100, 10, 70, 100};
```

Di sini, kita menggunakan _ranged for loop_ untuk mencetak setiap elemen dalam kontainer.

Pada output, kita dapat melihat bahwa angka-angka dicetak dalam urutan sesuai dengan inisialisasinya.

---

## 2. Associative Containers dalam C++

Dalam C++, _associative containers_ memungkinkan kita menyimpan elemen dalam urutan yang _tersortir_. Urutan tersebut tidak bergantung pada kapan elemen dimasukkan.

Secara internal, mereka diimplementasikan menggunakan struktur data pohon biner.

#### Jenis Associative Containers:

- `set`
    
- `map`
    
- `multiset`
    
- `multimap`
    

#### Contoh: Associative Container C++ (`set`)

Dalam contoh ini, kita akan menggunakan kelas `set` untuk mendemonstrasikan cara kerja _associative container_.

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
  // inisialisasi set bertipe int
  set<int> numbers = {1, 100, 10, 70, 100};

  // cetak set
  cout << "Numbers are: ";
  for(auto &num: numbers) {
    cout << num << ", ";
  }

  return 0;
}
```

**Output:**

```
Numbers are: 1, 10, 70, 100,
```

Dalam contoh di atas, kita membuat _associative container_ menggunakan kelas `set`.

Kita menginisialisasi `set` bernama `numbers` dengan angka yang tidak berurutan dan ada duplikat:

```cpp
set<int> numbers = {1, 100, 10, 70, 100};
```

Kemudian, kita mencetak isi `set` menggunakan _ranged for loop_.

Pada output, kita melihat bahwa angka-angka diurutkan secara ascending dan nilai duplikat dihapus. Nilai `100` yang muncul dua kali hanya dicetak satu kali oleh `set`.

---

## 3. Unordered Associative Containers dalam C++

Dalam C++, STL _Unordered Associative Containers_ menyediakan versi tak terurut dari _associative container_.

Secara internal, mereka diimplementasikan menggunakan struktur data _hash table_.

#### Jenis Unordered Associative Containers:

- `unordered_set`
    
- `unordered_map`
    
- `unordered_multiset`
    
- `unordered_multimap`
    

#### Contoh: Unordered Associative Container C++ (`unordered_set`)

Dalam contoh ini, kita akan menggunakan kelas `unordered_set` untuk mendemonstrasikan cara kerja _unordered associative container_.

```cpp
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  // inisialisasi unordered_set bertipe int
  unordered_set<int> numbers = {1, 100, 10, 70, 100};

  // cetak set
  cout << "Numbers are: ";
  for(auto &num: numbers) {
    cout << num << ", ";
  }

  return 0;
}
```

**Output:**

```
Numbers are: 70, 10, 100, 1,
```

Dalam contoh di atas, kita membuat _unordered associative container_ menggunakan kelas `unordered_set`.

Kita menginisialisasi `unordered_set` bernama `numbers` dengan angka tidak berurutan dan nilai duplikat `100`.

```cpp
unordered_set<int> numbers = {1, 100, 10, 70, 100};
```

Lalu kita cetak isi set menggunakan _ranged for loop_.

Output menunjukkan bahwa angka duplikat `100` dihapus, tetapi data tidak diurutkan secara ascending seperti pada `set`.

---

## Container Adapter dalam C++

Dalam C++, _Container Adapter_ mengambil kontainer STL yang sudah ada dan menyediakan antarmuka yang dibatasi untuk membuatnya berperilaku berbeda. Contohnya:

Sebuah `stack` adalah _container adapter_ yang menggunakan _sequential container_ `deque` dan menyediakan antarmuka terbatas hanya untuk operasi `push()` dan `pop()`.

#### Jenis Container Adapter:

- `stack`
    
- `queue`
    
- `priority_queue`
    

#### Contoh: Container Adapter C++ (`stack`)

Dalam contoh ini, kita menggunakan kelas `stack` untuk mendemonstrasikan cara kerja _container adapter_.

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
  // buat stack bertipe int
  stack<int> numbers;

  // masukkan elemen ke dalam stack
  numbers.push(1);
  numbers.push(100);
  numbers.push(10);

  cout << "Numbers are: ";

  // akses elemen dengan top() dan pop() sampai stack kosong
  while(!numbers.empty()) {
    // cetak elemen paling atas
    cout << numbers.top() << ", ";
    // hapus elemen paling atas dari stack
    numbers.pop();
  }

  return 0;
}
```

**Output:**

```
Numbers are: 10, 100, 1,
```

Dalam contoh di atas, kita membuat _container adapter_ menggunakan kelas `stack`.

```cpp
stack<int> numbers;
```

Berbeda dengan kontainer lain, kita tidak dapat langsung menginisialisasi nilai ke dalam `stack`. Hal ini karena _container adapter_ membatasi pengisian nilai secara langsung.

Oleh karena itu, kita menggunakan operasi `push()` untuk menambahkan elemen ke dalam stack.

Demikian juga, kita tidak bisa langsung melakukan iterasi ke dalam `stack`. Maka digunakan perulangan yang berjalan selama `stack` belum kosong.

```cpp
while (!numbers.empty()) {
  cout << numbers.top() << ", ";
  numbers.pop();
}
```

Penjelasan:

- `numbers.empty()` — memeriksa apakah stack kosong.
    
- `numbers.top()` — mengembalikan elemen di bagian atas stack.
    
- `numbers.pop()` — menghapus elemen di bagian atas stack.
    
