---
obsidianUIMode: preview
note_type: tips trick
tips_trick: for-each loop
sumber: chatgpt.com
tags:
  - syntax
  - efisien
---
#syntax #efisien 

---
# For-Each Loop di C++

For-each loop (juga dikenal sebagai **range-based for loop**) adalah fitur dalam C++ yang digunakan untuk **mengiterasi elemen dalam container** seperti array, `vector`, `map`, dan struktur data lainnya dengan cara yang lebih sederhana dibandingkan for loop biasa.

---

## 🔹 Sintaks For-Each Loop

```cpp
for (T variable : container) {
    // kode yang dieksekusi untuk setiap elemen
}
```

- `T` → Tipe data dari elemen dalam container.
- `variable` → Variabel yang akan menyimpan nilai setiap elemen.
- `container` → Struktur data yang akan diiterasi.

---

## 🔹 Contoh Dasar: Iterasi Array

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    for (int x : arr) {
        cout << x << " ";
    }
}
```

📌 **Output:**

```
1 2 3 4 5
```

✅ **Lebih ringkas** dibandingkan for loop biasa:

```cpp
for (int i = 0; i < 5; i++) {
    cout << arr[i] << " ";
}
```

---

## 🔹 Iterasi Vector

For-each loop **sangat cocok digunakan untuk `vector`** dari STL (Standard Template Library).

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};

    for (int num : v) {
        cout << num << " ";
    }
}
```

📌 **Output:**

```
10 20 30 40 50
```

---

## 🔹 Menggunakan `auto` untuk Kemudahan

Daripada menulis tipe data panjang seperti `vector<int>::iterator`, kita bisa pakai `auto`:

```cpp
for (auto x : v) {
    cout << x << " ";
}
```

📌 **Keuntungan `auto`**

- **Lebih fleksibel** karena otomatis menyesuaikan tipe data.
- **Cocok untuk iterasi struktur data kompleks** seperti `map`, `unordered_map`, dll.

---

## 🔹 Menggunakan `const` untuk Mencegah Perubahan Data

Kalau kita hanya ingin membaca data, bisa pakai `const`:

```cpp
for (const auto &x : v) {
    cout << x << " ";
}
```

- `const` → Mencegah perubahan nilai elemen.
- `&` → Menggunakan referensi agar tidak membuat salinan elemen.

---

## 🔹 Iterasi dengan `map` (Key-Value Pair)

For-each loop juga bisa digunakan pada `map` untuk mengakses **key-value pair**:

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> m = {{"Alice", 90}, {"Bob", 85}, {"Charlie", 95}};

    for (const auto &[key, value] : m) {
        cout << key << " mendapat nilai " << value << "\n";
    }
}
```

📌 **Output:**

```
Alice mendapat nilai 90
Bob mendapat nilai 85
Charlie mendapat nilai 95
```

✅ `auto &[key, value]` → Menggunakan structured binding untuk mengakses key dan value secara langsung.

---

## 🔹 Modifikasi Nilai Elemen dengan Referensi (`&`)

Jika kita ingin **mengubah elemen dalam container**, gunakan **reference (`&`)**:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    for (int &x : v) {  // Gunakan referensi
        x *= 2;  // Kalikan setiap elemen dengan 2
    }

    for (int x : v) {
        cout << x << " ";
    }
}
```

📌 **Output:**

```
2 4 6 8 10
```

✅ **Tanpa `&`**, perubahan hanya terjadi pada salinan elemen, bukan elemen aslinya.

---

## 🔹 Kapan Tidak Bisa Menggunakan For-Each Loop?

1. **Jika butuh akses ke indeks**
    
    - For-each **tidak menyediakan indeks**, jadi kalau perlu `i`, pakai `for` biasa.
    
    ```cpp
    for (int i = 0; i < v.size(); i++) {
        cout << "Index " << i << ": " << v[i] << "\n";
    }
    ```
    
2. **Jika perlu menghapus elemen saat iterasi**
    - Tidak bisa `erase()` elemen dalam `vector` atau `map` saat menggunakan for-each.

---

# 🔹 Kesimpulan

✅ **For-each loop lebih sederhana & aman** dibandingkan for loop biasa.  
✅ **Gunakan `auto` untuk kemudahan**, terutama dalam struktur data kompleks.  
✅ **Gunakan `const` untuk membaca & `&` untuk mengubah elemen.**  
✅ **Cocok untuk array, vector, map, dan struktur data STL lainnya.**

🔥 **For-each loop sangat berguna dalam competitive programming & pemrograman sehari-hari! 🚀**