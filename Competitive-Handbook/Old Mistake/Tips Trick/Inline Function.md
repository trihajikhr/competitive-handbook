---
obsidianUIMode: preview
note_type: tips trick
tips_trick: inline function
sumber: chatgpt.com
tags:
  - efisien
  - syntax
---
#efisien #syntax 

---

# 📌 Materi Lengkap: **Inline Function** di C++

### 🔷 Apa itu Inline Function?

`inline` function adalah fungsi yang disarankan kepada **compiler** untuk **mengganti pemanggilan fungsi dengan isi dari fungsi itu sendiri** saat program dikompilasi.

> Tujuannya: Menghindari **overhead pemanggilan fungsi** (function call overhead), terutama untuk fungsi pendek/sederhana.

---

### 🧠 **Sintaks Dasar**

```cpp
inline return_type function_name(parameters) {
    // isi fungsi
}
```

Contoh:

```cpp
inline int square(int x) {
    return x * x;
}
```

---

### 🔧 Cara Kerja Inline Function

Ketika kamu memanggil fungsi `square(5)` dalam program:

```cpp
int y = square(5);
```

Compiler akan **mengganti** pemanggilan itu dengan:

```cpp
int y = 5 * 5;
```

Jadi tidak ada lagi lompatan ke fungsi, **langsung disisipkan kodenya.**

---

### 🟢 Kapan Menggunakan Inline?

✅ Gunakan jika:

- Fungsi **sangat pendek**, seperti 1–2 baris.
    
- Fungsi **sering dipanggil** dan menyebabkan bottleneck.
    
- Fungsi **tidak mengakses sumber daya besar** (file, I/O, atau operasi berat).
    

---

### 🔴 Kapan Tidak Disarankan?

🚫 Jangan gunakan `inline` jika:

- Fungsi **besar/kompleks**.
    
- Fungsi menggunakan **loop, switch, rekursi**.
    
- Fungsi didefinisikan di **file terpisah (bukan header)**.
    
- Fungsi **virtual** (karena virtual dipanggil lewat pointer vtable, bukan bisa di-inline secara langsung).
    

---

### ⚠️ Catatan Penting:

- `inline` **hanyalah saran untuk compiler**, bukan perintah wajib.
    
- Compiler **boleh mengabaikan** `inline` jika merasa tidak cocok.
    
- Fungsi **dalam class** (di body class) secara default dianggap `inline`.
    

---

### 🧪 Contoh Program

```cpp
#include <iostream>
using namespace std;

inline int tambah(int a, int b) {
    return a + b;
}

int main() {
    int x = 5, y = 3;
    cout << "Hasil: " << tambah(x, y) << "\n"; // langsung disisipkan jadi 5+3
    return 0;
}
```

---

### 💡 Inline Function vs Macro

|Perbedaan|Inline Function|Macro (`#define`)|
|---|---|---|
|Tipe data|Dicek compiler|Tidak dicek|
|Error|Bisa dilacak|Tidak mudah dilacak|
|Keamanan|Aman & type-safe|Rentan bug|
|Contoh|`inline int f(int x)`|`#define f(x) (x*x)`|

---

### 📁 Inline Function di Header File

Kalau kamu definisikan fungsi di file `.h` dan ingin digunakan di banyak file `.cpp`, maka fungsi **harus** dideklarasikan `inline`, atau bisa terjadi error multiple definition.

```cpp
// file: mymath.h
inline int square(int x) {
    return x * x;
}
```

---

### 🧠 Kesimpulan

- `inline` berguna untuk fungsi kecil dan sering dipanggil.
    
- Mengurangi overhead pemanggilan fungsi.
    
- Harus digunakan dengan bijak — tidak cocok untuk fungsi besar.
    
- Digunakan juga saat mendefinisikan fungsi di header agar tidak error multiple definition.
    

---

Kalau kamu ingin versi Markdown untuk dicatat di Obsidian, tinggal bilang aja, nanti aku kasih versi `---` dan `###` siap pakai!