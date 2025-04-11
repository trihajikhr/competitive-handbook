---
obsidianUIMode: preview
note_type: tips trick
tips_trick: penggunaan template di c++
sumber: chatgpt.com
tags:
  - efisien
---
#efisien 

---
# 🔹 Apa Itu Template?

Template di C++ adalah fitur yang memungkinkan kita menulis **kode yang fleksibel dan dapat digunakan untuk berbagai tipe data**.

### 🔥 Sintaks

```cpp
template <typename T>
```

- `template` → Kata kunci untuk mendefinisikan template.
- `<typename T>` → `T` adalah **parameter tipe**, yang bisa diganti dengan tipe data apa saja saat digunakan.
- `typename` dan `class` bisa dipakai bergantian (artinya sama).

## 🔹 Contoh **Function Template**

Misalnya kita mau bikin fungsi **max** yang bisa bekerja untuk `int`, `double`, atau tipe lain tanpa harus menulis ulang:

```cpp
#include <iostream>
using namespace std;

template <typename T>
T myMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << myMax(3, 7) << "\n";      // int
    cout << myMax(3.5, 2.1) << "\n";  // double
    cout << myMax('a', 'z') << "\n";  // char
}
```

📌 **Penjelasan:**

- `T` akan otomatis digantikan oleh tipe data yang diberikan saat pemanggilan.
- Jadi, kita **nggak perlu bikin banyak fungsi untuk tipe data berbeda**.

## 🔹 Contoh **Class Template**

Kita bisa bikin class template untuk struktur data seperti **Stack** yang bisa menyimpan berbagai tipe data:

```cpp
#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T data[100];
    int top;
public:
    Stack() { top = -1; }

    void push(T val) { data[++top] = val; }
    T pop() { return data[top--]; }
};

int main() {
    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    cout << s1.pop() << "\n";  // 20

    Stack<double> s2;
    s2.push(3.14);
    cout << s2.pop() << "\n";  // 3.14
}
```

📌 **Penjelasan:**

- `Stack<int>` → Stack khusus untuk `int`.
- `Stack<double>` → Stack khusus untuk `double`.
- Dengan **template**, kita **cuma perlu bikin satu class** yang bisa dipakai untuk berbagai tipe data.

---

## 🔹 Kesimpulan

- `template <typename T>` membuat **kode lebih fleksibel** dan **dapat digunakan ulang**.
- Bisa dipakai untuk **fungsi** maupun **class**.
- **Hemat waktu**, karena nggak perlu bikin banyak versi untuk tipe data berbeda.

🔥 **Template sering dipakai di STL (Standard Template Library)**, misalnya di `vector<T>`, `map<K, V>`, dll. 🚀