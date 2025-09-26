---
obsidianUIMode: preview
note_type: latihan
latihan: Menyimpan Data Unik
sumber: chatgpt.com
tags:
  - set
  - data-structure
date_learned: 2025-06-20T20:43:00
---
---
Mantap! Kita mulai latihan `std::set` dari soal pertama. Fokus latihan ini adalah membiasakan diri dengan fungsi `insert()` dan bagaimana `set` menjaga keunikan dan urutan elemen.

---

# 🧩 Latihan 1 — Menyimpan Data Unik

**Deskripsi Soal:**

Diberikan sebuah array bilangan bulat dengan beberapa elemen yang mungkin **duplikat**. Tugasmu adalah mencetak elemen-elemen yang berbeda (unik) dalam urutan menaik, **menggunakan `std::set` dan fungsi `insert()`**.

**Input Format:**

- Baris pertama: sebuah bilangan bulat `n` (1 ≤ n ≤ 100), menyatakan jumlah elemen dalam array.
    
- Baris kedua: `n` buah bilangan bulat, dipisahkan dengan spasi.
    

**Output Format:**

- Cetak elemen-elemen unik dalam urutan menaik, dipisahkan dengan spasi.
    

**Contoh Input:**

```
8
4 2 4 5 2 1 3 1
```

**Contoh Output:**

```
1 2 3 4 5
```

---

**Catatan Panduan:**

- Gunakan `std::set<int> s;` untuk menyimpan elemen.
    
- Sisipkan setiap elemen dari array ke dalam `s` dengan `insert()`.
    
- Lalu cetak seluruh isi `s`.
    

---

Jika sudah selesai, kirimkan kode kamu atau cukup bilang "lanjut ke soal 2", maka aku akan berikan soal berikutnya yang memperkenalkan fungsi `find()`. Semangat! 💪

## Jawabanku
Berikut adalah kode program untuk jawabanku:

```cpp
#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> input(n);

    for(auto&x:input){
        cin >> x;
    }

    set<int> rest;
    for(int i=0; i<n; i++){
        rest.insert(input[i]);
    }

    for(const auto&x: rest){
        cout << x << " ";
    }
    
    return 0;
}
```

# Editorial

## Editorial Soal 1: Menyimpan Data Unik dengan `std::set`

### 1. Pembacaan Input

```cpp
int n; 
cin >> n;
vector<int> input(n);
for (auto &x : input) {
    cin >> x;
}
```

- **Fungsi**: Membaca jumlah elemen `n` dan kemudian membaca `n` bilangan bulat ke dalam `vector<int> input`.
    
- **Catatan**: Penggunaan `auto& x` di loop memastikan kita membaca langsung ke elemen vector tanpa copy tambahan.
    

### 2. Penyimpanan Unik dengan `std::set`

```cpp
set<int> rest;
for (int i = 0; i < n; i++) {
    rest.insert(input[i]);
}
```

- **Mengapa `set`?**
    
    - `std::set` menjamin hanya menyimpan elemen unik. Jika Anda memanggil `insert()` pada nilai yang sudah ada, maka insert tersebut diabaikan.
        
    - `set` juga otomatis menyimpan elemen dalam urutan terurut (menaik secara default), sehingga kita tidak perlu sorting terpisah.
        
- **Kompleksitas**: Setiap `insert()` memerlukan O(log k), di mana k adalah jumlah elemen di dalam `set` saat itu. Total untuk n elemen adalah O(n log n).
    

### 3. Pencetakan Hasil

```cpp
for (const auto &x : rest) {
    cout << x << " ";
}
```

- **Iterator-based loop**: Dengan range-based for, iterasi terjadi dari awal hingga akhir `set`, mencetak elemen yang sudah terurut.
    
- **Hasil**: Elemen-elemen unik dicetak dalam urutan menaik.
    

### 4. Optimasi I/O

```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

- **Tujuan**: Mempercepat operasi input/output dengan memisahkan sinkronisasi C++ stream dengan C stdio.
    
- **Manfaat**: Penting bila n cukup besar, karena mempercepat pembacaan dan penulisan data.
    

---

### Potential Improvements / Catatan Tambahan

1. **Penggabungan Loop**  
    Kamu dapat langsung memasukkan input ke dalam `set` tanpa `vector` perantara:
    
    ```cpp
    set<int> rest;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        rest.insert(x);
    }
    ```
    
    Ini menghemat memori dan satu loop.
    
2. **Menangani Output Terakhir**  
    Jika ingin bersih tanpa spasi akhir, bisa pakai:
    
    ```cpp
    bool first = true;
    for (auto x : rest) {
        if (!first) cout << ' ';
        cout << x;
        first = false;
    }
    ```
    
3. **Alternatif dengan `emplace()`**  
    Bekerja sama seperti `insert()`, tapi bisa lebih efisien jika elemen yang disimpan adalah objek kompleks:
    
    ```cpp
    rest.emplace(x);
    ```
    
    Pada tipe primitif seperti `int`, perbedaan performa minimal.
    

---

Kamu sudah memahami konsep utama:

- **Bagaimana `set` menjaga keunikan**
    
- **Mengapa tidak perlu `sort()` terpisah**
    
- **Kompleksitas O(n log n)**
    

Jika sudah jelas, kita lanjut ke **Soal 2**! 🚀