---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSSTC0002
nama_algoritma: stack data structure
kategori_algoritma: data structure
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
sumber: geeksforgeeks.org
date_learned: 2025-03-06T22:37:00
tags:
  - data-structure
  - array
  - stack
---
#array #stack #data-structure 

---
# Stack Data Structure

Dalam C++, **stack** adalah container yang mengikuti urutan **LIFO (Last In First Out)** dalam proses penyisipan dan penghapusan elemen. Ini berarti bahwa elemen yang paling baru dimasukkan akan dihapus terlebih dahulu, sedangkan elemen yang dimasukkan pertama akan dihapus terakhir.

Hal ini dilakukan dengan menambahkan dan menghapus elemen hanya dari **satu ujung stack**, yang biasanya disebut sebagai **top (puncak) stack**.

**Contoh:**

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;

    // Menambahkan elemen ke dalam stack
    st.push(1);
    st.push(2);
    st.push(3);

    while(!st.empty()) {
        // Menampilkan elemen teratas stack
        cout << st.top() << " ";
        // Menghapus elemen teratas stack
        st.pop();
    }
    return 0;
}
```

**Output:**

```bash
3 2 1
```

Penjelasan: Dalam program di atas, kita membuat sebuah stack dari tipe data integer dengan nama `st`. Elemen 1, 2, dan 3 kemudian dimasukkan ke dalam stack satu per satu menggunakan operasi `push()`. Karena stack mengikuti urutan LIFO, elemen-elemen tersebut disimpan dalam urutan terbalik dari saat mereka dimasukkan.

## Syntax
Stack didefinisikan sebagai template kelas `std::stack` yang terdapat dalam file header `<stack>`.

```cpp
stack<T> st;
````

Di mana:

- `T`: Tipe data elemen dalam stack.
- `st`: Nama yang diberikan untuk stack.

## Deklarasi dan Inisialisasi

Di C++, stack dapat dideklarasikan dan diinisialisasi dengan dua cara seperti yang ditunjukkan dalam contoh di bawah ini:

```cpp
#include <bits/stdc++.h>
using namespace std;

void print(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

int main() {
    
    // Deklarasi stack kosong
    stack<int> st1;
    
    // Menambahkan elemen ke dalam stack
    st1.push(10);
    st1.push(20);
    st1.push(30);
    st1.push(40);
    
    // Membuat stack lain dari st1
    stack<int> st2(st1);
    
    print(st1);
    cout << endl;
    print(st2);
    return 0;
}
```

**Output:**

```bash
40 30 20 10 
40 30 20 10 
```

Penjelasan: Dalam program di atas,

- Pernyataan `stack<int> st1` membuat stack kosong yang menyimpan elemen bertipe integer. Elemen kemudian ditambahkan ke dalam `st1`.
- Pernyataan `stack<int> st2 (st1)` membuat stack `st2` dengan elemen yang sama seperti `st1`.
# Operasi Dasar

Berikut adalah operasi dasar yang dapat dilakukan pada stack:
## 1. Menyisipkan Elemen

Pada stack, elemen baru hanya dapat dimasukkan di bagian atas stack menggunakan metode `push()`. Tidak ada cara untuk menyisipkan elemen di posisi lain dalam stack.

**Contoh:**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;
    
    // memasukan elemen ke bagian atas (top) stack
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
```

**Output:**

```bash
40 30 20 10 
```

![[Stack Data Structure (geeksforgeeks.com)-1.png]]

## 2. Mengakses Elemen

Hanya elemen teratas dari stack yang dapat diakses menggunakan metode `top()`. Kita tidak bisa mengakses elemen yang berada di tengah stack.

**Contoh:**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // mengakses elemen teratas
    cout << st.top();
    return 0;
}
```

**Output:**

```bash
40
```

![[Stack Data Structure (geeksforgeeks.com)-2.png]]

## 3. Menghapus Elemen

Dalam stack, hanya elemen teratas yang dapat dihapus menggunakan metode `pop()` dalam satu operasi. Untuk menghapus elemen lain, kita harus terlebih dahulu menghapus semua elemen yang dimasukkan setelah elemen tersebut (yaitu elemen-elemen di atasnya).

**Contoh:**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    
    // menghapus elemen teratas
    st.pop();
    
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
```

**Output:**

```bash
30 20 10
```

![[Stack Data Structure (geeksforgeeks.com)-3.png]]

## 4. Pseudo Traversal

Karena elemen selain elemen teratas tidak dapat diakses secara langsung dalam stack, stack tidak dapat ditelusuri (traverse) secara langsung. Namun, kita dapat membuat salinan dari stack, mengakses elemen teratas, dan menghapusnya satu per satu. Dengan cara ini, kita dapat menelusuri stack tanpa mengubah stack aslinya.

**Contoh:**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    
    // Create a copy
    stack<int> temp(st);
    
    while(!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    return 0;
}
```

**Output:**

```bash
40 30 20 10
```

**Penjelasan:** Dalam program di atas, _pseudo-traversal_ dilakukan dengan membuat salinan dari `st` untuk menghindari perubahan pada stack asli. Loop `while` mencetak dan menghapus elemen dari `temp` menggunakan `top()` dan `pop()` hingga stack kosong.

# Kompleksitas Waktu

Tabel di bawah ini menunjukkan kompleksitas waktu dari operasi-operasi stack:

| Operasi                       | Time Complexity |
| ----------------------------- | --------------- |
| Menyisipkan Elemen - `push()` | $O(1)$          |
| Mengakses Elemen - `top()`    | $O(1)$          |
| Menghapus Elemen - `pop()`    | $O(1)$          |
| Traverse the stack            | $O(n)$          |
# Cara Kerja Internal

Kelas _stack_ dalam C++ menyediakan implementasi bawaan dari struktur data stack. Stack ini diimplementasikan sebagai _container adapter_ yang dibangun di atas _container_ lain seperti `vector`, `list`, dll. Stack mengikuti prinsip **LIFO (Last In, First Out)** untuk operasi _push_ dan _pop_. Elemen teratas selalu merupakan elemen yang paling baru ditambahkan, dan operasi hanya dapat dilakukan pada bagian atas stack.

> **Catatan:** Meskipun stack bisa diimplementasikan menggunakan `vector`, elemen di tengahnya tidak dapat diakses karena adanya batasan LIFO.

# Semua Fungsi Anggota

Berikut adalah daftar semua fungsi anggota dari kelas `std::stack` di C++:

# Fungsi Anggota `std::stack` dalam C++

Berikut adalah daftar fungsi anggota yang tersedia dalam `std::stack` dan fungsinya:

| **Fungsi**      | **Deskripsi** |
|-----------------|--------------|
| `push()`       | Menambahkan satu elemen ke bagian atas stack. |
| `push_range()` | Menambahkan sejumlah elemen sekaligus ke bagian atas stack. |
| `top()`        | Mengakses elemen teratas dari stack tanpa menghapusnya. |
| `pop()`        | Menghapus elemen teratas dari stack. |
| `emplace()`    | Menyisipkan dan membangun elemen baru di bagian atas stack. |
| `size()`       | Mengembalikan jumlah elemen dalam stack. |
| `empty()`      | Memeriksa apakah stack kosong atau tidak. |
| `swap()`       | Menukar isi dua stack. |

## Penjelasan Tambahan
- **`push()` vs `emplace()`**:  
  `push()` menambahkan elemen yang sudah ada ke dalam stack, sedangkan `emplace()` langsung membangun elemen di dalam stack untuk efisiensi yang lebih baik.
- **`push_range()`**:  
  Fungsi ini memungkinkan menambahkan lebih dari satu elemen sekaligus, tetapi hanya tersedia di versi C++ terbaru.
- **`top()`**:  
  Hanya membaca elemen teratas tanpa menghapusnya, berguna untuk melihat nilai terbaru di stack.
