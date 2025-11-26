---
obsidianUIMode: preview
note_type: tips trick
tips_trick: mengambil string dari string
sumber: deepseek.com
tags:
  - string
---
#string

---
# Apa kegunaan dari fungsi substr() di C++
Fungsi `substr()` di C++ digunakan untuk mengambil sebagian (substring) dari sebuah string. Fungsi ini merupakan bagian dari library `<string>` di C++.

### Format Dasar:
```cpp
string substr(size_t pos = 0, size_t len = npos) const;
```
- **`pos`**: Posisi awal substring (indeks dimulai dari 0).
- **`len`**: Panjang substring yang ingin diambil. Jika tidak ditentukan atau melebihi panjang string, fungsi akan mengambil hingga akhir string.

### Contoh Penggunaan:
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "Hello, World!";
    
    // Ambil substring mulai dari indeks 7 sampai akhir
    string substr1 = str.substr(7);
    cout << substr1 << endl;  // Output: "World!"
    
    // Ambil 5 karakter mulai dari indeks 0
    string substr2 = str.substr(0, 5);
    cout << substr2 << endl;  // Output: "Hello"
    
    // Ambil substring dari indeks 7, sebanyak 3 karakter
    string substr3 = str.substr(7, 3);
    cout << substr3 << endl;  // Output: "Wor"
    
    return 0;
}
```

### Catatan:
1. Jika `pos` melebihi panjang string, fungsi akan melemparkan exception `out_of_range`.
2. Jika `len` tidak ditentukan atau melebihi sisa string, substring akan diambil hingga akhir string.

Fungsi ini sangat berguna untuk manipulasi string, seperti memotong bagian tertentu dari teks.