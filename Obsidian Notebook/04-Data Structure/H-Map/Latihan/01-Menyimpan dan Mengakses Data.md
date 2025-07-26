---
obsidianUIMode: preview
note_type: latihan
latihan: Menyimpan dan Mengakses Data
sumber: chatgpt.com
tags:
  - data-structure
  - map
date_learned: 2025-06-21T19:04:00
---
---
Bagus! Kita akan mulai latihan `map` secara bertahap, seperti metode sebelumnya. Akan ada 15 soal, satu per satu, dimulai dari yang paling dasar dulu untuk mengenalkan fungsi-fungsi penting di `std::map`. Berikut soal pertama:

---
# 🧩 Soal 1: Menyimpan dan Mengakses Data

**Deskripsi:**  
Buat program C++ yang membaca `n` buah pasangan `string` dan `int` dari input. Simpan data ini dalam `std::map<string, int>`. Setelah itu, program harus menerima satu `string` dan mencetak nilai `int` yang berasosiasi dengannya. Jika tidak ditemukan, cetak `"Tidak ditemukan"`.

**Contoh Input:**

```
3
apel 10
jeruk 20
pisang 30
jeruk
```

**Contoh Output:**

```
20
```

**Contoh Input 2:**

```
2
nanas 5
mangga 12
semangka
```

**Contoh Output 2:**

```
Tidak ditemukan
```

---

Kalau sudah selesai atau butuh petunjuk, bilang saja ya! Siap lanjut ke soal 2 setelah ini.
## Jawabanku
Berikut adalah jawabanku yang walaupun sudah benar, tapi masih bisa ditingkatkan lagi:

```cpp
#include<iostream>
#include<map>
using namespace std;

int main() {
    int n; cin >> n;
    map<string, int> dasmap;
    
    string s; int x;
    while(n--){
        cin >> s >> x;
        dasmap.insert(make_pair(s,x));
    }

    string f; cin >> f;
    auto it = dasmap.find(f);

    if(it != dasmap.end()){
        cout << dasmap.at(f);
    } else {
        cout << "Tidak ditemukan\n";
    }
    return 0;
}
```

# Editorial
Mantap! Kode kamu **sudah benar** dan fungsional. 👍 Namun, ada beberapa catatan perbaikan kecil dan saran optimalisasi:

---

### ✅ Yang Sudah Baik

- ✅ Kamu menggunakan `map<string, int>` dengan benar.
    
- ✅ Fungsi `insert(make_pair(...))` sudah tepat.
    
- ✅ Pengecekan `find()` sudah aman.
    
- ✅ `at()` digunakan dengan valid (karena kamu sudah cek `find()` sebelumnya).
    

---

### ✍️ Saran Peningkatan

1. **Gunakan indexing langsung (`[]`) saat mengisi map.**  
    Karena tidak perlu membuat `pair`, dan lebih singkat:
    
    ```cpp
    dasmap[s] = x;
    ```
    
    Alih-alih:
    
    ```cpp
    dasmap.insert(make_pair(s,x));
    ```
    
2. **Gunakan `it->second` daripada `map.at(key)` setelah `find()`.**  
    Karena kamu sudah dapat iterator-nya:
    
    ```cpp
    cout << it->second;
    ```
    

---

### 🔁 Versi Alternatif (lebih ringkas):

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    int n; cin >> n;
    map<string, int> dasmap;
    
    string s; int x;
    while (n--) {
        cin >> s >> x;
        dasmap[s] = x;
    }

    string f; cin >> f;
    auto it = dasmap.find(f);
    if (it != dasmap.end()) {
        cout << it->second;
    } else {
        cout << "Tidak ditemukan\n";
    }

    return 0;
}
```

Kalau sudah paham, yuk kita lanjut ke **Soal 2**, fokus ke **penghapusan elemen (`erase`) dalam map**. Siap?