---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Contoh Template C++
sumber: Google.com, AI
tags:
  - template-code
---
---
# Penggunaan Template di C++

> **Deskripsi Umum:**  
> Template adalah fitur C++ untuk membuat fungsi atau kelas yang bersifat generik (generic), sehingga dapat bekerja dengan berbagai jenis tipe data tanpa perlu menulis ulang kode untuk setiap tipe. Dengan template, programmer dapat menciptakan satu definisi yang fleksibel dan dapat digunakan kembali (reusable) untuk tipe data berbeda.  

---

## 1. Fungsi Template (Function Template)

### 1.1. Sintaks Dasar
```cpp
template <typename T>
T namaFungsi(T arg1, T arg2) {
    // Implementasi yang menggunakan tipe T
    return arg1 + arg2;
}
````

- `template <typename T>`: Mendefinisikan parameter template `T`. Kata kunci `typename` (atau `class`) menunjukkan bahwa `T` adalah placeholder untuk suatu tipe.
    
- `T namaFungsi(T arg1, T arg2)`: Fungsi yang mengembalikan tipe `T` dan menerima dua parameter bertipe `T`.
    

### 1.2. Contoh Kasus: Menukar Nilai (swap)

```cpp
#include <iostream>
using namespace std;

// Definisi fungsi template
template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    cout << "Sebelum swap: x = " << x << ", y = " << y << "\n";
    swapValues(x, y);  // T di-infer menjadi int
    cout << "Setelah swap : x = " << x << ", y = " << y << "\n\n";

    double p = 3.14, q = 2.71;
    cout << "Sebelum swap: p = " << p << ", q = " << q << "\n";
    swapValues(p, q);  // T di-infer menjadi double
    cout << "Setelah swap : p = " << p << ", q = " << q << "\n";

    return 0;
}
```

- Pemanggilan `swapValues(x, y)` menginstruksikan compiler untuk membuat instansiasi `swapValues<int>`.
    
- Pemanggilan `swapValues(p, q)` menginstruksikan compiler untuk membuat instansiasi `swapValues<double>`.
    

### 1.3. Contoh: Fungsi Maksimum (max)

```cpp
#include <iostream>
using namespace std;

template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << "Max(3, 7)     = " << findMax(3, 7) << "\n";        // int
    cout << "Max(3.5, 2.1) = " << findMax(3.5, 2.1) << "\n";    // double
    cout << "Max('A', 'Z') = " << findMax('A', 'Z') << "\n";    // char
    return 0;
}
```

- Fungsi `findMax` dapat dipanggil dengan `int`, `double`, `char`, ataupun tipe data lain yang mendukung operator `>`.
    

---

## 2. Kelas Template (Class Template)

### 2.1. Sintaks Dasar

```cpp
template <typename T>
class NamaKelas {
public:
    T data;

    NamaKelas(T val) : data(val) { }

    void show() {
        std::cout << data << "\n";
    }
};
```

- `template <typename T>`: Menyatakan parameter generik `T`.
    
- `class NamaKelas { ... }`: Mendefinisikan kelas dengan anggota yang bertipe `T`.
    

### 2.2. Contoh: Stack Generik

```cpp
#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T* arr;
    int capacity;
    int topIndex;

public:
    explicit Stack(int size) : capacity(size), topIndex(-1) {
        arr = new T[capacity];
    }

    ~Stack() {
        delete[] arr;
    }

    void push(const T& value) {
        if (topIndex < capacity - 1) {
            arr[++topIndex] = value;
        } else {
            cout << "Stack overflow!\n";
        }
    }

    T pop() {
        if (topIndex >= 0) {
            return arr[topIndex--];
        } else {
            cout << "Stack underflow!\n";
            return T();  // Mengembalikan default-constructed T
        }
    }

    bool isEmpty() const {
        return topIndex < 0;
    }

    void display() const {
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    // Stack<int>
    Stack<int> intStack(5);
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.display();          // Output: 30 20 10
    cout << intStack.pop() << "\n";  // Output: 30

    // Stack<string>
    Stack<string> strStack(3);
    strStack.push("C++");
    strStack.push("Template");
    strStack.display();          // Output: Template C++
    cout << strStack.pop() << "\n";  // Output: Template

    return 0;
}
```

- Dengan `Stack<int>`, `T` di-instanstiasi sebagai `int`.
    
- Dengan `Stack<string>`, `T` di-instanstiasi sebagai `std::string`.
    

---

## 3. Template dengan Banyak Parameter

### 3.1. Fungsi Template dengan Dua Tipe

```cpp
template <typename T1, typename T2>
void displayPair(T1 a, T2 b) {
    cout << "First : " << a << "\n";
    cout << "Second: " << b << "\n";
}

int main() {
    displayPair<int, string>(42, "Jawaban");
    displayPair(3.14, 100);  
    // di sini, compiler meng-infer T1 = double, T2 = int
    return 0;
}
```

- `template <typename T1, typename T2>`: Mendefinisikan dua parameter tipe generik.
    
- Compiler dapat meng-infer tipe secara otomatis jika argumen fungsi sesuai.
    

### 3.2. Kelas Template dengan Dua Parameter

```cpp
template <typename Key, typename Value>
class Pair {
public:
    Key key;
    Value value;

    Pair(const Key& k, const Value& v) : key(k), value(v) { }

    void print() const {
        cout << "{" << key << " : " << value << "}\n";
    }
};

int main() {
    Pair<string, int> agePair("Andi", 25);
    agePair.print();  // Output: {Andi : 25}

    Pair<int, double> coordPair(10, 3.14);
    coordPair.print();  // Output: {10 : 3.14}
    return 0;
}
```

- `Pair<string, int>` → `Key = string`, `Value = int`.
    
- `Pair<int, double>` → `Key = int`, `Value = double`.
    

---

## 4. Spesialisasi Template (Template Specialization)

### 4.1. Spesialisasi Penuh pada Fungsi

Jika ingin versi khusus untuk tipe tertentu:

```cpp
#include <iostream>
using namespace std;

template <typename T>
void printTypeInfo(const T& value) {
    cout << "Tipe umum: " << value << "\n";
}

// Spesialisasi penuh untuk int
template <>
void printTypeInfo<int>(const int& value) {
    cout << "Tipe int khusus: " << value << "\n";
}

int main() {
    printTypeInfo(3.14);   // Memanggil versi umum
    printTypeInfo(42);     // Memanggil versi khusus int
    return 0;
}
```

### 4.2. Spesialisasi Parsial pada Kelas

Untuk kasus tertentu, misalnya hanya pointer atau array:

```cpp
#include <iostream>
using namespace std;

// Kelas template umum
template <typename T>
class Printer {
public:
    static void print(const T& value) {
        cout << "Nilai : " << value << "\n";
    }
};

// Parsial khusus untuk tipe pointer
template <typename T>
class Printer<T*> {
public:
    static void print(T* ptr) {
        if (ptr) {
            cout << "Pointer ke : " << *ptr << "\n";
        } else {
            cout << "Pointer null\n";
        }
    }
};

int main() {
    int x = 100;
    Printer<int>::print(x);    // Versi umum
    Printer<int*>::print(&x);  // Versi parsial pointer
    Printer<int*>::print(nullptr);
    return 0;
}
```

---

## 5. Template Variadic (C++11 ke Atas)

### 5.1. Fungsi Variadic

Untuk membuat fungsi yang menerima jumlah argumen tak terbatas:

```cpp
#include <iostream>
using namespace std;

// Base case (hanya satu argumen)
void printAll() {
    cout << "\n";
}

template <typename T, typename... Rest>
void printAll(const T& first, const Rest&... rest) {
    cout << first << " ";
    printAll(rest...);   // Rekursi pada sisanya
}

int main() {
    printAll(1, 2.5, "C++", 'A');  
    // Output: 1 2.5 C++ A 
    return 0;
}
```

- `typename... Rest` → parameter pack yang menangkap nol atau lebih tipe tambahan.
    
- `printAll(first, rest...)` dipecah secara rekursif hingga tidak ada argumen tersisa.
    

---

## 6. Kapan Menggunakan Template

1. **Code Reuse (Penggunaan Ulang Kode)**
    
    - Saat logika algoritma sama, tetapi tipe data yang diproses bisa berbeda (misalnya sorting, pencarian, struktur data).
        
    - Daripada menulis fungsi/kode terpisah untuk `int`, `double`, `string`, dan sebagainya, cukup buat satu template.
        
2. **Type Safety**
    
    - Template memaksa pemeriksaan tipe saat kompilasi (compile-time). Ini mencegah bug yang mungkin muncul karena konversi tipe yang tidak sesuai.
        
    - Contohnya, fungsi template `add<T>` memastikan kedua operand bertipe sama.
        
3. **Generic Programming**
    
    - Membantu membuat pustaka (library) atau kerangka kerja (framework) yang generik dan fleksibel (misalnya STL: `vector<T>`, `map<Key, Value>`, `algorithm<T>`).
        
    - Anda bisa mengadaptasi algoritma dan struktur data untuk tipe kustom Anda tanpa mengutak-atik implementasi dasar.
        
4. **Performance (Efisiensi)**
    
    - Karena template di-instanstiasi pada waktu kompilasi, compiler dapat melakukan inlining dan optimasi spesifik tipe. Hasilnya, kode template bisa seefisien versi manual khusus tipe (zero-overhead abstraction).
        
5. **Kapan Sebaiknya Tidak Menggunakan Template**
    
    - Jika hanya memerlukan satu tipe data spesifik dan tidak ada kemungkinan reuse untuk tipe lain, menulis fungsi atau kelas khusus lebih sederhana.
        
    - Saat kode menjadi terlalu kompleks akibat kombinasi parameter pack, spesialisasi, atau metafungsi template—apabila tujuan awal hanya satu kasus sederhana.
        
    - Jika kompilasi menjadi sangat lambat karena banyak instansiasi tipe, bisa mempertimbangkan alternatif (seperti menggunakan fungsi virtual pada hierarki kelas, meski ini punya overhead runtime).
        

---

## 7. Contoh Lengkap: Stack dengan Template dan Spesialisasi

```cpp
#include <iostream>
#include <cassert>
using namespace std;

// Kelas template umum
template <typename T>
class MyStack {
private:
    T* dataArr;
    int capacity;
    int topIndex;

public:
    explicit MyStack(int size) : capacity(size), topIndex(-1) {
        dataArr = new T[capacity];
    }

    ~MyStack() {
        delete[] dataArr;
    }

    void push(const T& value) {
        assert(topIndex < capacity - 1 && "Stack overflow!");
        dataArr[++topIndex] = value;
    }

    T pop() {
        assert(topIndex >= 0 && "Stack underflow!");
        return dataArr[topIndex--];
    }

    bool isEmpty() const {
        return topIndex < 0;
    }

    void display() const {
        for (int i = topIndex; i >= 0; --i) {
            cout << dataArr[i] << " ";
        }
        cout << "\n";
    }
};

// Spesialisasi khusus (partial) untuk tipe bool agar menampilkan teks sendiri
template <>
class MyStack<bool> {
private:
    bool* dataArr;
    int capacity;
    int topIndex;

public:
    explicit MyStack(int size) : capacity(size), topIndex(-1) {
        dataArr = new bool[capacity];
    }

    ~MyStack() {
        delete[] dataArr;
    }

    void push(const bool& value) {
        assert(topIndex < capacity - 1 && "Stack overflow!");
        dataArr[++topIndex] = value;
    }

    bool pop() {
        assert(topIndex >= 0 && "Stack underflow!");
        return dataArr[topIndex--];
    }

    bool isEmpty() const {
        return topIndex < 0;
    }

    void display() const {
        for (int i = topIndex; i >= 0; --i) {
            cout << (dataArr[i] ? "true " : "false ");
        }
        cout << "\n";
    }
};

int main() {
    MyStack<int> s1(3);
    s1.push(100);
    s1.push(200);
    s1.display();      // Output: 200 100
    cout << s1.pop() << "\n";  // Output: 200

    MyStack<bool> s2(3);
    s2.push(true);
    s2.push(false);
    s2.display();      // Output: false true
    cout << (s2.pop() ? "true\n" : "false\n");  // Output: false
    return 0;
}
```

- Kelas umum `MyStack<T>` menangani tipe apa pun.
    
- Spesialisasi penuh `MyStack<bool>` menampilkan `true/false` sebagai teks daripada angka `1/0`.
    

---

## 8. Ringkasan dan Tips

- **Definisi Template**
    
    - Gunakan `template <typename T>` atau `template <class T>` untuk fungsi atau kelas yang ingin dibuat generik.
        
    - Bisa juga mendeklarasikan beberapa parameter: `template <typename T1, typename T2, typename... Rest>`.
        
- **Instansiasi**
    
    - Saat memanggil fungsi atau membuat objek kelas template, compiler akan membuat kode khusus untuk tipe yang dipakai.
        
    - Contoh: `vector<int> v;` → compiler menghasilkan implementasi `vector<int>`.
        
- **Spesialisasi**
    
    - `template <>` untuk spesialisasi penuh (full specialization).
        
    - `template <typename T> class Nama<T*>` untuk spesialisasi parsial (partial specialization) pada parameter pointer.
        
- **Ketika Menggunakan**
    
    - Ingin menulis algoritma atau struktur data sekali, tetapi dapat digunakan pada berbagai tipe.
        
    - Ingin menjaga type safety sekaligus menghindari duplikasi kode.
        
    - Ingin memanfaatkan optimasi kompilator (inlining, optimasi tipe-spesifik).
        
- **Perhatian**
    
    - Terlalu banyak template (terutama nested atau variadic) bisa membuat kode sulit dibaca dan memperlambat kompilasi.
        
    - Debugging kesalahan template seringkali menampilkan pesan error panjang—biasakan membaca jejak tipe di `<>` untuk memahami masalah.
        

Dengan memahami konsep dan praktik di atas, kamu dapat merancang kode C++ yang lebih fleksibel, aman, dan mudah di-maintain. Selamat mengeksplorasi penggunaan template dalam proyekmu!