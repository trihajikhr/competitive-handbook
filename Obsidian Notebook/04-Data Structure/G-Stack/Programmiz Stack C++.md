---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSST-0001
nama_algoritma: 
kategori_algoritma: data structure
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
sumber: programiz.com & chatgpt.com
date_learned: 2025-04-23T12:11:00
tags:
  - data-structure
  - stack
---
---
# Stack C++  
Stack STL menyediakan fungsionalitas struktur data stack dalam C++.  

Struktur data stack mengikuti prinsip LIFO (Last In First Out). Artinya, elemen yang terakhir ditambahkan akan dihapus pertama kali.  

Dalam stack, elemen yang terakhir ditambahkan akan dihapus pertama.  

## Membuat Stack  
Untuk membuat stack di C++, pertama-tama kita perlu menyertakan file header stack.  

```cpp
#include <stack>
```  

Setelah mengimpor file ini, kita dapat membuat stack menggunakan sintaks berikut:  

```cpp
stack<type> st;
```  

Di sini, `type` menunjukkan tipe data yang ingin kita simpan dalam stack. Contohnya,  

```cpp
// membuat stack integer  
stack<int> integer_stack;  

// membuat stack string  
stack<string> string_stack;
```  

## Contoh: Stack STL C++  
```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    // membuat stack string
    stack<string> languages;
    
    // menambahkan elemen ke Stack
    languages.push("C++");
    languages.push("Java");
    languages.push("Python");
    
    // mencetak elemen teratas
    cout << languages.top();

    return 0;
}
```  

**Output**  
```
Python
```  

Pada contoh di atas, kita telah membuat stack string bernama `languages`.  

Di sini, kita menggunakan metode `push()` untuk menambahkan elemen ke stack. Kemudian, kita menggunakan metode `top()` untuk menampilkan elemen teratas.  

Kita akan mempelajari lebih lanjut tentang metode `push()` dan `top()` nanti dalam tutorial ini.  

## Metode Stack  
Di C++, kelas stack menyediakan berbagai metode untuk melakukan operasi berbeda pada stack.  

| Operasi    | Deskripsi                                      |
|------------|-----------------------------------------------|
| `push()`   | menambahkan elemen ke stack                   |
| `pop()`    | menghapus elemen dari stack                   |
| `top()`    | mengembalikan elemen di bagian atas stack     |
| `size()`   | mengembalikan jumlah elemen dalam stack       |
| `empty()`  | mengembalikan `true` jika stack kosong        |

## Menambahkan Elemen ke Stack  
Kita menggunakan metode `push()` untuk menambahkan elemen ke stack. Contoh:  

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    // membuat stack string
    stack<string> colors;

    // memasukkan elemen ke stack
    colors.push("Red");
    colors.push("Orange");
    
    cout << "Stack: ";

    // mencetak elemen stack
    while(!colors.empty()) {
        cout << colors.top() << ", ";
        colors.pop();
    }
 
    return 0;
}
```  

**Output**  
```
Stack: Orange, Red,
```  

Pada contoh di atas, kita telah membuat stack string bernama `colors`. Kemudian, kita menggunakan metode `push()` untuk menambahkan elemen ke stack.  

```cpp
colors.push("Red");
colors.push("Orange");
```  

Alih-alih langsung mencetak isi stack, kita menggunakan perulangan `while` dan berbagai metode stack.  

```cpp
while(!colors.empty()) {
    cout << colors.top() << ", ";
    colors.pop();
}
```  

Untuk mencetak semua elemen stack, kita mencetak elemen teratasnya lalu melakukan `pop` (menghapus) di dalam perulangan. Proses ini berlanjut hingga stack kosong.  

Kita akan mempelajari metode `pop()`, `top()`, dan `empty()` di bagian selanjutnya.  

Perhatikan juga bahwa kita memasukkan elemen dalam urutan: `{"Red", "Orange"}`.  

Namun saat mencetak elemen, kita mendapatkan `{"Orange", "Red"}`.  

Hal ini terjadi karena stack adalah struktur data LIFO, yang berarti elemen yang terakhir dimasukkan akan diambil pertama kali.  

**Catatan:** Tidak seperti vektor atau kontainer lainnya, kita tidak bisa menggunakan perulangan `range-based for` untuk iterasi melalui stack. Ini karena stack STL adalah **STL Container Adapter**, yang memberikan akses terbatas agar berperilaku seperti struktur data stack standar.  

## Menghapus Elemen dari Stack  
Kita dapat menghapus elemen dari stack menggunakan metode `pop()`. Contoh:  

```cpp
#include <iostream>
#include <stack>
using namespace std;

// prototipe fungsi utilitas display_stack
void display_stack(stack<string> st);

int main() {
    // membuat stack string
    stack<string> colors;

    // memasukkan elemen ke stack
    colors.push("Red");
    colors.push("Orange");
    colors.push("Blue");
    
    cout << "Stack Awal: ";
    // mencetak elemen stack
    display_stack(colors);
    
    // menghapus "Blue" karena dimasukkan terakhir
    colors.pop();
    
    cout << "Stack Akhir: ";
    // mencetak elemen stack
    display_stack(colors);
    
    return 0;
}

// fungsi utilitas untuk menampilkan elemen stack
void display_stack(stack<string> st) {
    while(!st.empty()) {
        cout << st.top() << ", ";
        st.pop();
    }
    cout << endl;
}
```  

**Output**  
```
Stack Awal: Blue, Orange, Red,
Stack Akhir: Orange, Red,
```  

Pada contoh di atas, kita menggunakan metode `pop()` untuk menghapus elemen dari stack.  

Awalnya, isi stack adalah `{"Blue", "Orange", "Red"}`.  

Kemudian kita menggunakan metode `pop()` untuk menghapus elemen.  

```cpp
// menghapus elemen teratas
colors.pop();
```  

Ini menghapus elemen di bagian atas stack, yaitu elemen yang terakhir dimasukkan, yaitu `"Blue"`.  

Maka, stack akhir menjadi `{"Orange", "Red"}`.  

## Mengakses Elemen dari Stack  
Kita mengakses elemen di bagian atas stack menggunakan metode `top()`. Contoh:  

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    // membuat stack string
    stack<string> colors;

    // memasukkan elemen ke stack
    colors.push("Red");
    colors.push("Orange");
    colors.push("Blue");
    
    // mendapatkan elemen teratas
    string top = colors.top();

    cout << "Elemen Teratas: " << top;
    
    return 0;
}
```  

**Output**  
```
Elemen Teratas: Blue
```  

Pada contoh di atas, kita membuat stack string bernama `colors` dan menambahkan elemen: `"Red"`, `"Orange"`, dan `"Blue"`.  

Kemudian kita menggunakan metode `top()` untuk mengakses elemen teratas:  

```cpp
string top = colors.top();
```  

Di sini, `"Blue"` dimasukkan terakhir, jadi itulah elemen teratas.  

## Mendapatkan Ukuran Stack  
Kita menggunakan metode `size()` untuk mendapatkan jumlah elemen dalam stack. Contoh:  

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    // membuat stack integer
    stack<int> prime_nums;

    // memasukkan elemen ke stack
    prime_nums.push(2);
    prime_nums.push(3);
    prime_nums.push(5);
    
    // mendapatkan ukuran stack
    int size = prime_nums.size();
    cout << "Ukuran Stack: " << size;

    return 0;
}
```  

**Output**  
```
Ukuran Stack: 3
```  

Pada contoh di atas, kita membuat stack integer bernama `prime_nums` dan menambahkan tiga elemen ke dalamnya.  

Kemudian kita menggunakan metode `size()` untuk menemukan jumlah elemen dalam stack:  

```cpp
prime_nums.size();
```  

Karena kita menambahkan 3 elemen ke stack, `prime_nums.size()` mengembalikan `3`.  

## Memeriksa Apakah Stack Kosong  
Kita menggunakan metode `empty()` untuk memeriksa apakah stack kosong. Metode ini mengembalikan:  
- `1` (`true`) - jika stack kosong  
- `0` (`false`) - jika stack tidak kosong  

Contoh:  

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    // membuat stack double
    stack<double> nums;
    
    cout << "Apakah stack kosong? ";

    // memeriksa apakah stack kosong
    if (nums.empty()) {
        cout << "Ya" << endl;
    }
    else {
        cout << "Tidak" << endl;
    }

    cout << "Memasukkan elemen..." << endl;

    // memasukkan elemen ke stack
    nums.push(2.3);
    nums.push(9.7);
 
    cout << "Apakah stack kosong? ";

    // memeriksa apakah stack kosong
    if (nums.empty()) {
        cout << "Ya";
    }
    else {
        cout << "Tidak";
    }

    return 0;
}
```  

**Output**  
```
Apakah stack kosong? Ya
Memasukkan elemen...
Apakah stack kosong? Tidak
```  

Pada contoh di atas, kita menggunakan metode `empty()` untuk menentukan apakah stack kosong:  

```cpp
if(nums.empty()) { // mengembalikan false
    cout << "Ya" << endl;
}
else {
    cout << "Tidak" << endl; 
}
```  

Awalnya, stack tidak memiliki elemen. Jadi `nums.empty()` mengembalikan `true`.  

Kemudian kita menambahkan elemen ke stack.  

Kembali, kita menggunakan `nums.empty()` untuk memeriksa apakah stack kosong. Kali ini, mengembalikan `false`.