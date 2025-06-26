---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Kondisi Tertentu Untuk Kasus Multimap
sumber: chatgpt.com
date_learned: 2025-06-23T18:31:00
tags:
  - data-structure
  - multimap
---
Link Sumber: 

---
# Kondisi Tertentu Untuk Kasus Multimap
## Solusi Menghapus Elemen Multimap tunggal
> Dijelaskan bahwa kita bisa menghapus elemen mulitmap dengan key nya, tapi bagaimana jika aku ingin menghapus suatu elemen di mulitmap, yang walaupun key nya sama, tapi jika value nya tidak memenuhi kondisi tertentu, maka key dan value tersebut dihapus?

Pertanyaan kamu sangat bagus! Pada `std::multimap`, karena bisa ada banyak elemen dengan _key_ yang sama tapi _value_-nya berbeda, kita memang perlu berhati-hati saat menghapus elemen.

### 📌 Masalah:

Kamu ingin **menghapus elemen dari `multimap` berdasarkan syarat tertentu pada _value_**, walaupun _key_-nya sama. Contoh kasus:

```cpp
multimap<string, int> mm = {
    {"apel", 10},
    {"apel", 5},
    {"apel", 20},
    {"jeruk", 7}
};
```

Misalnya kamu ingin **menghapus semua elemen dengan key `"apel"` tapi hanya jika valuenya < 10**.

---

### ✅ Solusi:

Gunakan `equal_range(key)` untuk mendapatkan seluruh elemen dengan key tertentu, lalu lakukan iterasi dan hapus dengan hati-hati menggunakan iterator.

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    multimap<string, int> mm = {
        {"apel", 10},
        {"apel", 5},
        {"apel", 20},
        {"jeruk", 7}
    };

    string targetKey = "apel";
    auto range = mm.equal_range(targetKey);

    for (auto it = range.first; it != range.second; ) {
        if (it->second < 10) {
            it = mm.erase(it); // erase() mengembalikan iterator ke elemen berikutnya
        } else {
            ++it;
        }
    }

    // Menampilkan isi multimap setelah penghapusan
    for (const auto& [key, val] : mm) {
        cout << key << ": " << val << '\n';
    }

    return 0;
}
```

### 🧠 Penjelasan:

- `equal_range(key)` mengembalikan `pair<iterator, iterator>` berisi semua elemen dengan key tersebut.
    
- Gunakan loop manual, dan **jangan pakai `++it` setelah `erase(it)`**, karena `erase()` sudah mengembalikan iterator ke elemen selanjutnya.
    

---

Kalau kamu ingin menghapus **semua elemen yang memenuhi syarat tanpa peduli key-nya**, tinggal loop langsung ke seluruh `multimap`:

```cpp
for (auto it = mm.begin(); it != mm.end(); ) {
    if (it->second < 10) {
        it = mm.erase(it);
    } else {
        ++it;
    }
}
```

Kalau kamu punya contoh kasus khusus, aku bisa bantu sesuaikan juga.

---
## Mengecek Apakah dua Multimap Sama?
> Jika aku ingin mengecek apakah multimap di A dan B itu sama baik key dan val, apakah harus dilakukan secara iteratif? Dan seperti apa penulisan kode yang tepat?

Pertanyaanmu sangat bagus dan penting kalau kamu ingin membandingkan isi dari dua `multimap`.

### 🔎 Apakah harus iteratif?

**Tidak perlu** dilakukan secara iteratif manual jika hanya ingin mengecek apakah seluruh isi `A` dan `B` identik (termasuk _urutan internal_ `multimap`, yaitu urutan sorting berdasarkan key). Kamu bisa membandingkan langsung:

```cpp
if (A == B) {
    cout << "A dan B sama\n";
} else {
    cout << "A dan B berbeda\n";
}
```

### ✅ Penjelasan:

- `std::multimap` mendukung operator $==$ secara langsung.
    
- Dua `multimap` dianggap **sama** jika keduanya memiliki **ukuran yang sama** dan setiap pasang `(key, value)` juga **sama dan dalam urutan yang sama** (urut berdasarkan sorting internal `multimap`, jadi kamu tidak perlu khawatir soal urutan manual).
    

---

### 🧪 Contoh Lengkap:

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    multimap<string, int> A = {
        {"apel", 5},
        {"apel", 10},
        {"jeruk", 7}
    };

    multimap<string, int> B = {
        {"apel", 5},
        {"apel", 10},
        {"jeruk", 7}
    };

    if (A == B) {
        cout << "A dan B sama\n";
    } else {
        cout << "A dan B berbeda\n";
    }

    return 0;
}
```

---

### 🧩 Catatan:

- Kalau kamu **mengisi `multimap` dengan urutan berbeda** tapi isinya tetap sama (misalnya `{"jeruk",7}` di awal dan `{"apel",5}` di akhir), `multimap` akan tetap mengurutkannya otomatis, jadi perbandingan masih valid.
    
- Namun kalau kamu ingin membandingkan hanya berdasarkan _key_ saja, atau hanya _value_ saja per key, maka kamu **butuh pendekatan iteratif**.
    

Kalau kamu ada tujuan perbandingan yang lebih spesifik (misalnya hanya key yang sama tapi bebas urutan value), beritahu aku ya, akan aku bantu kodenya.

---
## Pengecekan 2 Multimap dengan Iteratif
> Nah, kalau aku ingin megecek misal key saja, dan aku ingin melakukanya secara iteratif, nah itu kaya gimana tuh?

Bagus! Kalau kamu ingin **mengecek apakah dua `multimap` punya key yang sama saja**, tanpa peduli jumlah value-nya per key ataupun isi value-nya, maka kamu perlu:

1. Mengekstrak semua key dari masing-masing `multimap`,
    
2. Menyimpan ke dalam `set` (karena `set` hanya menyimpan unik),
    
3. Lalu bandingkan kedua `set` tersebut.
    

---

### ✅ Contoh Kode Iteratif:

```cpp
#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    multimap<string, int> A = {
        {"apel", 10},
        {"apel", 5},
        {"jeruk", 7}
    };

    multimap<string, int> B = {
        {"jeruk", 3},
        {"apel", 100},
        {"apel", 99}
    };

    set<string> keysA, keysB;

    for (const auto& [key, val] : A) {
        keysA.insert(key);
    }

    for (const auto& [key, val] : B) {
        keysB.insert(key);
    }

    if (keysA == keysB) {
        cout << "Key dari A dan B sama\n";
    } else {
        cout << "Key dari A dan B berbeda\n";
    }

    return 0;
}
```

---

### 🧠 Penjelasan:

- `set<string> keysA` menyimpan semua key unik dari `multimap A`.
    
- Karena `set` hanya menyimpan elemen unik, maka walaupun `"apel"` muncul dua kali, hanya satu yang disimpan.
    
- Setelah itu cukup bandingkan `keysA == keysB`.
    

---

### 💡 Bonus (Versi Lebih Ringkas dengan Lambda + Range-for):

Kalau kamu terbiasa dengan C++ modern (C++17 ke atas), kamu bisa bikin fungsi pembantu untuk ekstrak key:

```cpp
auto extract_keys = [](const multimap<string, int>& mm) {
    set<string> s;
    for (const auto& [k, _] : mm)
        s.insert(k);
    return s;
};

if (extract_keys(A) == extract_keys(B)) {
    cout << "Key sama\n";
}
```

Kalau kamu ingin membandingkan **jumlah kemunculan setiap key**, atau struktur lebih kompleks, aku juga bisa bantu buatkan.

---
> Apakah bisa menggunakan range for loop, tapi menggunakan A dan B sekaligus?

Pertanyaanmu sangat bagus, dan ini menyentuh batas kemampuan `range-based for loop` di C++.

### ❓ Apakah bisa membandingkan dua `multimap` secara **simultan** dalam satu `range-based for loop** seperti ini?

```cpp
for (const auto& [key, val] : A, B) {
    // ...
}
```

### ❌ Jawaban Singkat: Tidak bisa seperti itu

Kode di atas:

```cpp
for (const auto& [key, val] : A, B) { ... }
```

adalah **tidak valid**, karena `range-based for` hanya menerima **satu container**. Ekspresi `A, B` akan dievaluasi sebagai _comma operator_, yang artinya hanya `B` yang dianggap sebagai container di loop itu.

---

### ✅ Alternatif: Gunakan Iterator Manual

Kalau kamu ingin **membandingkan A dan B secara berpasangan (berurutan)**, kamu bisa gunakan **iterator manual** seperti ini:

```cpp
auto itA = A.begin();
auto itB = B.begin();

while (itA != A.end() && itB != B.end()) {
    cout << "A: " << itA->first << " " << itA->second << " | "
         << "B: " << itB->first << " " << itB->second << "\n";

    // Misal ingin membandingkan key:
    if (itA->first != itB->first) {
        cout << "Key berbeda!\n";
        break;
    }

    ++itA;
    ++itB;
}

if (itA == A.end() && itB == B.end()) {
    cout << "Semua key cocok dan panjang sama\n";
} else {
    cout << "Ukuran berbeda atau key mismatch\n";
}
```

---

### 💡 Catatan:

- Pendekatan ini **hanya valid** jika kamu tahu bahwa `A` dan `B` berisi elemen dalam urutan yang sama.
    
- Kalau urutannya bisa berbeda, maka cara paling aman tetap dengan mengekstrak dan membandingkan `set` dari key-nya.
    

---

### 🔁 Alternatif Menggunakan `zip-like` Behavior (C++23 atau manual):

Kalau kamu ingin behavior seperti `zip()` di Python (dua container dijalankan bersama), bisa pakai pendekatan dengan STL atau `boost`, tapi itu advanced. Jika kamu mau belajar itu juga, aku bisa bantu buatkan juga.

Jadi kesimpulannya:

- `for (auto [k,v]: A, B)` tidak valid.
    
- Untuk membandingkan per elemen, pakailah iterator manual.
    
- Untuk hanya membandingkan key, gunakan `set` dan `range-based for` masing-masing.
    

Kamu ingin aku bantu buat versi `zip`-like custom untuk latihan juga?