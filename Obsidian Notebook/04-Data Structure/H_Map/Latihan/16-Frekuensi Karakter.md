---
obsidianUIMode: preview
note_type: latihan
latihan: Frekuensi Karakter
sumber: Gemini AI
tags:
  - data-structure
  - map
date_learned: 2025-06-22T17:58:00
---
Latihan baru oleh Gemini AI!

---

# Tantangan 1: Frekuensi Karakter

Buatlah sebuah program C++ yang membaca sebuah string (misalnya, `"belajar c plus plus"`).

```
belajar c plus plus
```

Gunakan `std::map` untuk menghitung berapa kali setiap karakter muncul dalam string tersebut. Setelah itu, tampilkan setiap karakter beserta jumlah kemunculannya.

**Contoh Output yang Diharapkan:**

```
Karakter ' ' muncul 3 kali
Karakter '+' muncul 2 kali
Karakter 'a' muncul 2 kali
Karakter 'b' muncul 1 kali
Karakter 'c' muncul 1 kali
Karakter 'e' muncul 1 kali
Karakter 'j' muncul 1 kali
Karakter 'l' muncul 2 kali
Karakter 'p' muncul 1 kali
Karakter 'r' muncul 1 kali
Karakter 's' muncul 1 kali
Karakter 'u' muncul 1 kali
```

_(Urutan karakter tidak harus sama persis karena `std: :map` akan mengurutkannya secara otomatis berdasarkan kuncinya.)_

---

Silakan coba kerjakan dan tunjukkan kodemu jika sudah selesai! Jangan ragu bertanya jika ada yang kurang jelas.

## Jawabanku
Berikut adalah jawabanku yang sudah benar:

```cpp
#include<iostream>
#include<map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<char, int> dasmap;
    string s; getline(cin >> ws, s);

    for(char c : s){
        dasmap[c]++;
    }

    for(const auto & [key, val]: dasmap){
        cout << "Karakter '" << key << "' muncul " << val << " kali\n";
    }
    return 0;
}
```

# Editorial
Fantastis! Jawabanmu untuk Tantangan 1 sangat tepat dan efisien. Kamu sudah menggunakan `std::map` dengan sangat baik untuk menghitung frekuensi karakter.

Beberapa poin bagus dari kodemu:

- **Penggunaan `std::map<char, int>`:** Sangat sesuai untuk memetakan karakter ke hitungan kemunculannya.
<br/>
- **Perulangan `for(char c : s)`:** Cara yang modern dan ringkas untuk mengiterasi setiap karakter dalam string.
<br/>
- **`dasmap[c]++`:** Ini adalah trik yang sangat cerdas dan umum digunakan dengan `std::map`. Ketika `c` pertama kali diakses, `dasmap[c]` akan diinisialisasi secara otomatis ke `0` (nilai default untuk `int`), kemudian langsung di-increment menjadi `1`. Ini membuat kode jauh lebih singkat daripada harus memeriksa apakah kuncinya sudah ada atau belum.
<br/>
- **Perulangan `for(const auto & [key, val]: dasmap)`:** Penggunaan structured binding (`[key, val]`) adalah fitur C++ yang sangat nyaman dan membuat kode lebih mudah dibaca saat mengiterasi `map`.
<br/>
- **`ios::sync_with_stdio(false); cin.tie(nullptr);`:** Ini menunjukkan bahwa kamu juga memperhatikan **optimasi I/O**, yang bagus untuk masalah kompetitif programming. Meskipun tidak terlalu krusial untuk soal ini, ini adalah kebiasaan yang baik.

Secara keseluruhan, pemahamanmu tentang `std::map` sudah sangat mantap berdasarkan solusi ini.

