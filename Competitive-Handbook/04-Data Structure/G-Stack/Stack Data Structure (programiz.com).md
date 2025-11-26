---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSST-0003
nama_algoritma: 
kategori_algoritma: data structure
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
sumber: programiz.com
date_learned: 2025-03-06T22:21:00
tags:
  - data-structure
  - stack
---
---
# Stack Data Structure

Stack adalah struktur data linear yang mengikuti prinsip **Last In First Out (LIFO)**. Ini berarti elemen terakhir yang dimasukkan ke dalam stack akan dikeluarkan lebih dulu.

Kamu bisa membayangkan struktur data stack seperti tumpukan piring yang disusun satu di atas yang lain.

![[Stack Data Structure-1.png]]

Di sini, kamu dapat:

- Meletakkan piring baru di atas
- Mengambil piring teratas
- Dan, jika ingin mengambil piring di bagian bawah, kamu harus terlebih dahulu mengeluarkan semua piring di atasnya.

Inilah cara kerja struktur data stack.
## Prinsip LIFO pada Stack

Dalam istilah pemrograman, menambahkan item ke atas stack disebut **push**, sedangkan menghapus item disebut **pop**.

![[Stack Data Structure-2.png]]

Pada gambar di atas, meskipun item 3 dimasukkan terakhir, item tersebut dihapus pertama kali. Inilah cara kerja prinsip **LIFO (Last In First Out)**.

Kita dapat mengimplementasikan stack dalam berbagai bahasa pemrograman seperti C, C++, Java, Python, atau C#, tetapi spesifikasinya kurang lebih sama.

## Operasi Dasar pada Stack

Terdapat beberapa operasi dasar yang memungkinkan kita melakukan berbagai tindakan pada stack:

- **Push**: Menambahkan elemen ke atas stack.
- **Pop**: Menghapus elemen dari atas stack.
- **IsEmpty**: Memeriksa apakah stack kosong.
- **IsFull**: Memeriksa apakah stack penuh.
- **Peek**: Mengambil nilai elemen teratas tanpa menghapusnya.

## Cara Kerja Struktur Data Stack

Operasi stack bekerja sebagai berikut:

- Sebuah pointer bernama `TOP` digunakan untuk melacak elemen teratas dalam stack.
- Saat menginisialisasi stack, kita menetapkan nilainya ke **-1**, sehingga kita dapat memeriksa apakah stack kosong dengan membandingkan `TOP == -1`.
- Saat **push** (menambahkan elemen), kita meningkatkan nilai `TOP` dan menempatkan elemen baru pada posisi yang ditunjuk oleh `TOP`.
- Saat **pop** (menghapus elemen), kita mengambil elemen yang ditunjuk oleh `TOP` dan mengurangi nilainya.
- Sebelum melakukan **push**, kita harus memeriksa apakah stack sudah penuh.
- Sebelum melakukan **pop**, kita harus memeriksa apakah stack sudah kosong.

![[Stack Data Structure-3.png]]
# Implementasi Stack 
Implementasi stack yang paling umum adalah menggunakan **array**, tetapi juga dapat diimplementasikan menggunakan **list**.

```cpp
// Implementasi stack dalam C++

#include <stdlib.h>
#include <iostream>

using namespace std;

#define MAX 10
int size = 0;

// Membuat sebuah stack
struct stack {
  int items[MAX];
  int top;
};
typedef struct stack st;

void createEmptyStack(st *s) {
  s->top = -1;
}

// Memeriksa apakah stack penuh
int isfull(st *s) {
  if (s->top == MAX - 1)
    return 1;
  else
    return 0;
}

// Memeriksa apakah stack kosong
int isempty(st *s) {
  if (s->top == -1)
    return 1;
  else
    return 0;
}

// Menambahkan elemen ke dalam stack
void push(st *s, int newitem) {
  if (isfull(s)) {
    cout << "STACK PENUH";
  } else {
    s->top++;
    s->items[s->top] = newitem;
  }
  size++;
}

// Menghapus elemen dari stack
void pop(st *s) {
  if (isempty(s)) {
    cout << "\n STACK KOSONG \n";
  } else {
    cout << "Item yang dihapus= " << s->items[s->top];
    s->top--;
  }
  size--;
  cout << endl;
}

// Mencetak elemen-elemen dalam stack
void printStack(st *s) {
  printf("Stack: ");
  for (int i = 0; i < size; i++) {
    cout << s->items[i] << " ";
  }
  cout << endl;
}

// Kode utama (driver code)
int main() {
  int ch;
  st *s = (st *)malloc(sizeof(st));

  createEmptyStack(s);

  push(s, 1);
  push(s, 2);
  push(s, 3);
  push(s, 4);

  printStack(s);

  pop(s);

  cout << "\nSetelah menghapus elemen\n";
  printStack(s);
}
```

## Bonus python

```py
# Stack implementation in python


# Creating a stack
def create_stack():
    stack = []
    return stack


# Creating an empty stack
def check_empty(stack):
    return len(stack) == 0


# Adding items into the stack
def push(stack, item):
    stack.append(item)
    print("pushed item: " + item)


# Removing an element from the stack
def pop(stack):
    if (check_empty(stack)):
        return "stack is empty"

    return stack.pop()


stack = create_stack()
push(stack, str(1))
push(stack, str(2))
push(stack, str(3))
push(stack, str(4))
print("popped item: " + pop(stack))
print("stack after popping an element: " + str(stack))

```
# Stack Time Complexity
## Time Complexity
Untuk implementasi stack berbasis array, operasi _push_ dan _pop_ memiliki waktu konstan, yaitu $O(1)$.
# Aplikasi Struktur Data Stack

Meskipun stack adalah struktur data yang sederhana untuk diimplementasikan, ia sangat kuat. Penggunaan stack yang paling umum meliputi:

- **Membalikkan kata** – Masukkan semua huruf ke dalam stack, lalu keluarkan (_pop_) satu per satu. Karena sifat LIFO pada stack, huruf-huruf akan keluar dalam urutan terbalik.
- **Dalam kompilator** – Kompilator menggunakan stack untuk menghitung nilai ekspresi seperti $2+4/5∗(7−9)$ dengan mengonversi ekspresi ke dalam bentuk _prefix_ atau _postfix_.
- **Dalam browser** – Tombol _back_ pada browser menyimpan semua URL yang telah dikunjungi sebelumnya dalam stack. Setiap kali pengguna mengunjungi halaman baru, URL tersebut ditambahkan ke atas stack. Saat tombol _back_ ditekan, URL saat ini dihapus dari stack, dan URL sebelumnya diakses.
## Keunggulan dan kelemahan
### Keunggulan Stack
- **Mudah diimplementasikan** – Stack adalah struktur data yang sederhana dan dapat diimplementasikan menggunakan array atau linked list.
- **Efisien dalam manajemen data** – Operasi _push_ dan _pop_ memiliki kompleksitas waktu **O(1)**, sehingga sangat cepat.
- **Mendukung LIFO (Last In, First Out)** – Berguna dalam banyak aplikasi seperti pemrosesan ekspresi matematika, _undo/redo_ dalam editor teks, dan fungsi rekursi.
- **Penggunaan memori yang terkontrol** – Dalam implementasi berbasis array, stack menggunakan blok memori tetap, sedangkan dalam implementasi berbasis linked list, penggunaan memori lebih fleksibel.
### Kelemahan Stack
- **Terbatas pada LIFO** – Karena hanya mendukung operasi LIFO, stack tidak cocok untuk semua jenis masalah seperti pencarian elemen di tengah struktur data.
- **Keterbatasan ukuran dalam array-based stack** – Jika menggunakan array, ukuran stack harus ditentukan sebelumnya, yang dapat menyebabkan pemborosan memori jika terlalu besar atau kesalahan _overflow_ jika terlalu kecil.
- **Risiko stack overflow** – Jika stack mencapai batas kapasitasnya (dalam implementasi array) atau terjadi rekursi yang terlalu dalam, program bisa mengalami stack overflow.
- **Akses elemen terbatas** – Tidak seperti array atau linked list, elemen dalam stack hanya dapat diakses dari atas, sehingga kurang fleksibel dalam beberapa kasus.
## Kesimpulan
- `std::stack` **tidak mendukung akses indeks langsung**.
- Hanya bisa mengakses elemen teratas dengan `top()`.
- Untuk melihat elemen lain, harus melakukan **pop** atau menyalin stack.
- Jika perlu akses bebas, gunakan `std::vector` atau `std::deque`.

# Informasi Tambahan
Stack yang kita pelajari diatas adalah stack yang bukan berasal dari standard library, atau STL. Sedangkan di C++, stack merupakan data structure yang memang berasal dari STL. Jadi berikut materi tambahan tentang stack jika kita menggunakan stack STL:

Oke! Ini dia **materi dan contoh implementasi semua fungsi dasar Stack** beserta penjelasannya. Kita pakai **C++** karena kamu sedang fokus ke competitive programming dan sudah belajar OOP C++ juga.

---

## 🧠 Materi Fungsi Dasar Stack

### 📌 1. `push(x)`

Menambahkan elemen `x` ke atas stack.

### 📌 2. `pop()`

Menghapus elemen teratas dari stack.

### 📌 3. `top()` / `peek()`

Mengembalikan elemen teratas tanpa menghapusnya.

### 📌 4. `isEmpty()` / `empty()`

Mengecek apakah stack kosong.

### 📌 5. `size()`

Mengembalikan jumlah elemen dalam stack.

### 📌 6. `push_range(vector)`

Menambahkan banyak elemen sekaligus (tidak standar di STL, tapi bisa dibuat sendiri).

---

## 🚀 Implementasi C++

```cpp
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Fungsi push_range() tambahan
void push_range(stack<int>& st, const vector<int>& values) {
    for (int val : values) {
        st.push(val);
    }
}

int main() {
    stack<int> st;

    // 1. push()
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Setelah push: top = " << st.top() << endl; // Output: 30

    // 2. top()
    cout << "Elemen teratas (top): " << st.top() << endl; // Output: 30

    // 3. pop()
    st.pop();
    cout << "Setelah pop: top = " << st.top() << endl; // Output: 20

    // 4. empty()
    if (st.empty()) {
        cout << "Stack kosong\n";
    } else {
        cout << "Stack tidak kosong\n"; // Output
    }

    // 5. size()
    cout << "Ukuran stack: " << st.size() << endl; // Output: 2

    // 6. push_range()
    vector<int> tambahan = {40, 50, 60};
    push_range(st, tambahan);
    cout << "Setelah push_range: top = " << st.top() << endl; // Output: 60

    return 0;
}
```

---

## 🧩 Catatan Tambahan

- Stack bersifat **LIFO**: Last In First Out.
    
- Di C++, `stack` berasal dari header `<stack>`.
    
- Untuk traversal isi stack, kamu perlu _pop_ satu per satu karena `stack` tidak menyediakan iterator.
    
