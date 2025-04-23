---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSSTC0003
nama_algoritma: stack data structure
kategori_algoritma: data structure
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
sumber: programiz.com & geeksforgeeks.com
date_learned: 2025-03-06T23:07:00
tags:
  - array
  - data-structure
  - stack
---
#array #data-structure #stack 

---
# Pilih yang mana antara 2 versi?

Kamu bingung karena ada dua pendekatan berbeda dalam mengimplementasikan _stack_ di C++:

### 1️⃣ **Menggunakan STL (`std::stack<int>`)** → (Versi GeeksforGeeks)

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
```

**✔ Keunggulan:**

- **Mudah & cepat** karena menggunakan **Standard Template Library (STL)**.
- **Sudah ada implementasi siap pakai** (tanpa perlu bikin fungsi `push` atau `pop` sendiri).
- **Aman & lebih teruji** karena dikelola oleh STL.

**✖ Kelemahan:**

- Tidak bisa mengontrol alokasi memori secara langsung.
- Hanya bisa diakses dengan fungsi bawaan STL (`push()`, `pop()`, `top()`, `empty()`, dll.).

---

### 2️⃣ **Implementasi Manual Menggunakan Struct & Array** → (Versi Programiz)

```cpp
#define MAX 10

struct stack {
    int items[MAX];
    int top;
};
```

**✔ Keunggulan:**

- **Lebih fleksibel**, bisa mengatur sendiri cara kerja _stack_.
- **Dapat mengoptimalkan performa** sesuai kebutuhan (misalnya dengan _static_ atau _dynamic array_).
- **Bisa belajar lebih dalam** bagaimana _stack_ bekerja.

**✖ Kelemahan:**

- Harus mengelola sendiri operasi dasar (_push_, _pop_, _isempty_, _isfull_).
- Bisa terjadi _**stack overflow**_ jika tidak diatur dengan baik.
- **Kurang praktis** dibandingkan `std::stack<int>` dari STL.

---

### 🔥 **Kesimpulan** 🔥

- Jika **ingin kemudahan & kecepatan**, pakai **STL (`std::stack<int>`)**.
- Jika **ingin memahami cara kerja stack dari nol & mengontrol memorinya**, pakai **struct dengan array/manual**.

Mana yang lebih cocok tergantung kebutuhanmu! Kalau untuk **competitive programming**, lebih baik pakai STL karena lebih cepat & praktis. 🚀