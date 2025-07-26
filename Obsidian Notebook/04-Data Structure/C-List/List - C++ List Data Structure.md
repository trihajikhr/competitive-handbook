---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSLS-0001
nama_algoritma: 
kategori_algoritma: data structure
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
sumber: programiz.com & chatgpt.com
date_learned: 2025-04-23T10:02:00
tags:
  - data-structure
  - list
---
---
# List C++

**List C++** adalah kontainer STL (_Standard Template Library_) yang menyimpan elemen-elemen secara acak di lokasi memori yang tidak saling berhubungan. Untuk mempertahankan urutan secara sekuensial, setiap elemen dalam list memiliki dua tautan:

- satu menunjuk ke elemen sebelumnya
    
- satu lagi menunjuk ke elemen berikutnya
    

![[List Data Structure-1.png]]

Di C++, STL `list` mengimplementasikan struktur data _doubly-linked list_. Akibatnya, kita bisa melakukan iterasi maju dan mundur.

### Versi ChatGPT

#### 📌 Apa itu `list` di C++ dan Kegunaannya?

Di C++, `list` adalah **container** dari STL (Standard Template Library) yang mengimplementasikan **doubly linked list**.

Artinya:

- Setiap elemen menyimpan data dan dua pointer (ke elemen sebelumnya dan selanjutnya).
    
- Akses langsung ke elemen tertentu **tidak secepat** `vector`, tapi penambahan/penghapusan elemen di tengah list **sangat efisien** (tidak perlu menggeser elemen seperti pada `vector`).
    

#### ✅ Kapan dan untuk Apa Menggunakan `list`?

Gunakan `list` jika kamu butuh:

1. **Menyisipkan atau menghapus elemen dengan cepat di awal, tengah, atau akhir**.
    
    - Misalnya: antrian ganda, undo/redo system, editor teks, dll.
        
2. **Menghindari overhead saat melakukan insert/delete di `vector`**.
    
    - `vector` harus menggeser elemen lainnya saat insert/delete, sementara `list` hanya update pointer.
        
3. **Traversal dua arah.**
    
    - Karena `list` adalah **doubly linked list**, kamu bisa maju-mundur antar elemen.
        
#### 💻 Contoh Kasus Penggunaan List dalam Program

1. **Implementasi Deque (Double Ended Queue)**
    
    - Bisa push dan pop dari depan maupun belakang.
        
    - Misalnya digunakan dalam algoritma Sliding Window.
        
2. **LRU Cache (Least Recently Used Cache)**
    
    - Untuk menyimpan elemen dengan prioritas penggunaan terakhir.
        
    - `list` dipakai untuk menyusun urutan, karena bisa cepat mindahin node ke depan/belakang.
        
3. **Undo/Redo di Text Editor**
    
    - Setiap aksi disimpan dalam list, dan user bisa mundur/maju ke perubahan sebelumnya.
        
4. **Manipulasi Data Besar Tanpa Banyak Copy**
    
    - Kalau kamu perlu menyisipkan atau menghapus ribuan data di tengah-tengah, `list` sangat hemat dibanding `vector`.
        
5. **Simulator Antrian (Queue)**
    
    - Misalnya: sistem antrian pelanggan, penjadwalan proses.
        

#### ⚠️ Kapan Tidak Menggunakan `list`?

- Kalau kamu butuh akses cepat ke elemen dengan indeks tertentu (misalnya `list[5]`) → **gunakan `vector` atau `array`**.
    
- Kalau datamu jarang berubah atau hanya perlu ditambahkan di akhir → `vector` lebih optimal.
    


---

## Membuat `list` di C++ STL

Untuk membuat sebuah list, kita perlu menyertakan header file `list` dalam program kita:

```cpp
#include<list>
```

Setelah mengimpor header tersebut, kita bisa mendeklarasikan list dengan sintaks berikut:

```cpp
std::list<Type> nama_list = {nilai1, nilai2, ...};
```

Keterangan:

- `std::list` → mendeklarasikan kontainer STL bertipe list
    
- `<Type>` → tipe data dari nilai-nilai yang akan disimpan dalam list
    
- `nama_list` → nama unik yang diberikan untuk list
    
- `nilai1, nilai2, ...` → nilai-nilai yang akan disimpan dalam list
    

Contoh:

```cpp
// membuat list bertipe integer
std::list<int> numbers = {1, 2, 3, 4, 5};

// membuat list bertipe karakter
std::list<char> vowels = {'a', 'e', 'i', 'o', 'u'};
```

**Catatan:** Kita juga dapat menuliskan elemen list tanpa menggunakan tanda sama dengan. Contoh:

```cpp
std::list<int> numbers {1, 2, 3, 4, 5};
```

---

## Contoh: List STL C++

```cpp
#include <iostream>
#include <list>

using namespace std;

int main() {

    // membuat list
    list<int> numbers {1, 2, 3, 4};
  
    // menampilkan elemen list
    cout << "List Elements: ";
    for(int number : numbers) {
        cout << number <<", ";
    }
    
    return 0;
}
```

**Output:**

```
List Elements: 1, 2, 3, 4,
```

Dalam contoh di atas, kita membuat list dengan nama `numbers` yang berisi elemen: 1, 2, 3, 4. Kita menggunakan _range-based for loop_ untuk mencetak elemen-elemen list.

**Catatan:** Kita menggunakan `list` bukan `std::list` karena sudah mendefinisikan `std` sebagai namespace dengan `using namespace std;`.

---

## Operasi Dasar pada List

STL C++ menyediakan berbagai fungsi yang dapat digunakan untuk melakukan berbagai operasi pada list. Berikut beberapa fungsi umum untuk melakukan operasi:

### 1. Menambahkan Elemen ke List

Kita dapat menambahkan nilai ke dalam list menggunakan fungsi berikut:

- `push_front()` → menambahkan elemen ke awal list
    
- `push_back()` → menambahkan elemen ke akhir list
    

Contoh:

```cpp
#include <iostream>
#include <list>

using namespace std;

int main() {
    
    // membuat list
    list<int> numbers = {1, 2, 3};
  
    // menampilkan list awal
    cout << "Initial List: ";
    for(int number: numbers) {
        cout << number << ", ";
    }
  
    // menambahkan elemen di awal
    numbers.push_front(0);

    // menambahkan elemen di akhir
    numbers.push_back(4);

    // menampilkan list akhir
    cout << endl << "Final List: ";
    for(int number : numbers) {
        cout << number << ", ";
    }

    return 0;
}
```

**Output:**

```
Initial List: 1, 2, 3, 
Final List: 0, 1, 2, 3, 4,
```

---

### 2. Mengakses Elemen List

Kita dapat mengakses elemen list menggunakan fungsi berikut:

- `front()` → mengembalikan elemen pertama
    
- `back()` → mengembalikan elemen terakhir
    

Contoh:

```cpp
#include <iostream>
#include <list>

using namespace std;

int main() {

    list<int> numbers = {1, 2, 3, 4, 5};
  
    cout << "First Element: " << numbers.front() << endl;
    cout << "Last Element: " << numbers.back();
  
    return 0;
}
```

**Output:**

```
First Element: 1  
Last Element: 5
```

---

### 3. Menghapus Elemen List

Kita bisa menghapus elemen list menggunakan fungsi berikut:

- `pop_front()` → menghapus elemen pertama
    
- `pop_back()` → menghapus elemen terakhir
    

Contoh:

```cpp
#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> numbers = {1, 2, 3, 4, 5};
 
    cout << "Inital List: ";
    for(int number : numbers) {
        cout << number << ",  ";
    }

    numbers.pop_front();
    numbers.pop_back();

    cout << endl << "Final List: ";
    for(int number : numbers) {
        cout << number << ", ";
    }

    return 0;
}
```

**Output:**

```
Inital List: 1,  2,  3,  4,  5,  
Final List: 2, 3, 4,
```

---

## Fungsi Lain pada List di C++

|Fungsi|Deskripsi|
|---|---|
|`reverse()`|Membalik urutan elemen dalam list|
|`sort()`|Mengurutkan elemen list|
|`unique()`|Menghapus elemen duplikat yang berurutan|
|`empty()`|Mengecek apakah list kosong|
|`size()`|Mengembalikan jumlah elemen dalam list|
|`clear()`|Menghapus semua elemen dalam list|
|`merge()`|Menggabungkan dua list yang sudah terurut|

---

## Mengakses Elemen List dengan _Iterator_

Kita bisa menggunakan iterator untuk mengakses elemen tertentu di dalam list.

Contoh:

```cpp
#include <iostream>
#include <list>

using namespace std;

int main() {

    list<int> numbers = {1, 2, 3, 4, 5};

    list<int>::iterator itr = numbers.begin();
  
    ++itr;  // ke elemen kedua
    cout << "Second Element: " << *itr << endl;

    ++itr; ++itr;  // ke elemen keempat
    cout << "Fourth Element: " << *itr;
  
    return 0;
}
```

**Output:**

```
Second Element: 2  
Fourth Element: 4
```

**Penjelasan:**

- `list<int>::iterator` → mendefinisikan iterator untuk list bertipe `int`
    
- `numbers.begin()` → menunjuk ke elemen pertama list
    
- Kita menggunakan `++itr` berulang kali karena iterator tidak bisa dijumlahkan dengan integer seperti `itr + 3`.

Hal ini karena iterator bukanlah nilai numerik sederhana seperti bilangan bulat biasa. Iterator menunjuk ke lokasi memori tertentu dalam kontainer.  
  
Menambah iterator dengan operator `++` akan menunjuk ke elemen berikutnya dalam kontainer.

Untuk mempelajari lebih lanjut tentang iterator, kunjungi [C++ STL Iterators](https://www.programiz.com/cpp-programming/iterators) .

---

## Pertanyaan Umum

> **Bagaimana cara menambahkan elemen di posisi tertentu dalam list?**  

### Cara Menambahkan Elemen ke List di Lokasi Tertentu

Kita menggunakan fungsi `insert()` untuk menambahkan elemen pada posisi tertentu.

Sintaks dari fungsi `insert()` untuk `list` adalah:

```cpp
list_name.insert(iterator, value);
```

Penjelasan:

- `iterator` – menunjuk ke posisi di mana nilai akan disisipkan
    
- `value` – nilai aktual yang akan disisipkan pada posisi yang ditentukan oleh iterator
    

Mari kita lihat contoh berikut:

```cpp
#include <iostream>
#include <list>

using namespace std;

int main() {
    
    // membuat list
    list<int> numbers {1, 2, 3};
    
    // menampilkan list awal  
    cout << "Initial List: ";
    for(int number : numbers) {
        cout << number << ", ";
    }

    // membuat iterator untuk menunjuk ke posisi pertama
    list<int>::iterator itr = numbers.begin();

    // menaikkan iterator ke posisi ke-3
    ++itr; 
    ++itr;  

    // menyisipkan 0 pada posisi ke-3 dalam list
    numbers.insert(itr, 0);

    // menampilkan list yang telah dimodifikasi  
    cout << endl << "Final List: ";
    for(int number : numbers) {
        cout << number << ", ";
    }
    
    return 0;
}
```

**Output:**

```
Initial List: 1, 2, 3, 
Final List: 1, 2, 0, 3,
```

---


> **Bagaimana cara menghapus elemen dari posisi tertentu dalam list?**  

### Cara Menghapus Elemen List dari Lokasi Tertentu

Kita menggunakan fungsi `remove()` untuk menghapus elemen pada posisi tertentu. Sintaks fungsi `remove()` adalah:

```cpp
list_name.remove(element);
```

Fungsi `remove()` dapat digunakan dengan dua cara berikut:

- Menggunakan **Value**
    
- Menggunakan **Iterator**
    

---

### 1. `remove()` dengan Value

```cpp
#include <iostream>
#include <list>

using namespace std;

int main() {

    // membuat list
    list<int> numbers {1, 2, 1, 3, 4, 1};
  
    // menampilkan list awal  
    cout << "Initial List: ";
    for(int number : numbers) {
        cout << number << ", ";
    }
  
    // menghapus semua elemen dengan nilai 1
    numbers.remove(1);

    // menampilkan list yang telah dimodifikasi
    cout << endl << "Final List: ";
    for(int number : numbers) {
        cout << number << ", ";
    }

    return 0;
}
```

**Output:**

```
Initial List: 1, 2, 1, 3, 4, 1, 
Final List: 2, 3, 4, 
```

---

### 2. `remove()` dengan Iterator

```cpp
#include <iostream>
#include <list>

using namespace std;

int main() {
    
    // membuat list dan iterator
    list<int> numbers {0, 1, 2, 3, 4, 5, 3};
    list<int>::iterator itr = numbers.begin();
  
    // menampilkan list awal
    cout << "Initial List: ";
    for(int number : numbers) {
        cout << number << ", ";
    }

    // menggerakkan iterator ke elemen ke-4
    for (int i = 0; i < 3; i++){
        ++itr;
    }

    // menghapus elemen ke-4
    numbers.remove(*itr);

    // menampilkan list yang telah dimodifikasi
    cout << endl << "Final List: ";
    for(int number : numbers) {
        cout << number << ", ";
    }

    return 0;
}
```

**Output:**

```
Initial List: 0, 1, 2, 3, 4, 5, 3, 
Final List: 0, 1, 2, 4, 5, 
```

**Catatan:**  
Di sini, kedua elemen yang memiliki nilai `3` dihapus, meskipun kita hanya menggunakan fungsi `remove()` pada elemen ke-4.

Hal ini terjadi karena fungsi `remove()` menghapus **semua elemen** yang memiliki **nilai yang sama** dengan elemen yang ditunjuk oleh iterator.

---

## Tantangan:

Buat fungsi untuk memeriksa apakah dua sublist identik.

Jika dua list `list1` dan `list2` identik, kembalikan `"Identical"`. Jika tidak, kembalikan `"Not identical"`.

**Contoh:**

```cpp
list1[] = {1, 2, 3}  
list2[] = {1, 2, 3}  
Output → "Identical"
```

**Petunjuk:** Dua list dianggap identik jika memiliki elemen yang sama dengan urutan yang sama. Misalnya `{2, 5}` dan `{2, 5}` adalah list yang identik.
