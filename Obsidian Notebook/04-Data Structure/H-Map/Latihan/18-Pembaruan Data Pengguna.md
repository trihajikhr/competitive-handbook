---
obsidianUIMode: preview
note_type: latihan
latihan: Pembaruan Data Pengguna
sumber: Gemini AI
tags:
  - data-structure
  - map
date_learned: 2025-06-22T18:12:00
---
---
# Tantangan 3: Pembaruan Data Pengguna

Kamu memiliki data pengguna di sebuah sistem. Setiap pengguna memiliki **ID unik** (integer) dan **nama** (string). Terkadang, nama pengguna bisa berubah.

Buatlah program C++ yang menggunakan `std::map<int, std::string>` untuk:

1. Menginisialisasi `map` dengan data pengguna awal:
    - ID 101: "Alice"
    - ID 102: "Bob"
    - ID 103: "Charlie"
2. Tampilkan semua data pengguna saat ini.
3. Lakukan pembaruan nama untuk pengguna dengan ID 102 menjadi "Robert".
4. Tambahkan pengguna baru: ID 104: "Diana".
5. Hapus pengguna dengan ID 101.
6. Setelah semua operasi di atas, tampilkan kembali semua data pengguna yang tersisa untuk memverifikasi perubahan.

---

Bagaimana, menarik bukan? Silakan dicoba!

## Jawabanku
Berikut adalah jawabanku yang sudah benar:

```cpp
#include<iostream>
#include<map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int, string> dasmap {
        {101, "Alice"},
        {102, "Bob"},
        {103, "Charlie"}
    };

    // tampilkan semua
    for(const auto& [key, val]: dasmap){
        cout << key << ": " << val << endl;
    }

    // pembaruan nama
    dasmap[102] = "Robert";

    // tambah pengguna
    dasmap[104] = "Diana";

    // hapus user
    dasmap.erase(101);

    // tampilkan lagi
    for(const auto& [key, val]: dasmap){
        cout << key << ": " << val << "\n";
    }

    return 0;
}
```

# Editorial
Brilian! Jawabanmu untuk Tantangan 3 sangat tepat dan menunjukkan pemahaman yang solid tentang operasi dasar `std::map` seperti inisialisasi, penambahan (atau pembaruan), dan penghapusan elemen.

Beberapa poin bagus dari kodemu:

- **Inisialisasi C++11 Style:** Penggunaan _initializer list_ `{}` saat mendeklarasikan `dasmap` sangat rapi dan modern.
<br/>
- **Pembaruan Elemen:** Kamu dengan tepat menggunakan `dasmap[102] = "Robert";` untuk memperbarui nilai yang sudah ada. Ini adalah cara yang paling umum dan idiomatis.
<br/>
- **Penambahan Elemen:** Sama seperti pembaruan, `dasmap[104] = "Diana";` secara otomatis akan menambahkan elemen baru jika kuncinya belum ada. Ini adalah fleksibilitas yang sangat bagus dari `std::map`.
<br/>
- **Penghapusan Elemen:** Penggunaan `dasmap.erase(101);` adalah cara standar dan efisien untuk menghapus elemen berdasarkan kuncinya.
<br/>
- **Iterasi:** Kamu konsisten menggunakan _structured binding_ `for(const auto& [key, val]: dasmap)`, yang sangat meningkatkan keterbacaan kode.

Semua langkah yang diminta dalam tantangan ini sudah kamu implementasikan dengan sempurna. Kamu sudah sangat mahir menggunakan `std::map` untuk mengelola data dinamis.
