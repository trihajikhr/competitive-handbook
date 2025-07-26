---
obsidianUIMode: preview
note_type: latihan
latihan: Editor Teks Sederhana
sumber: chatgpt.com
tags:
  - list
  - data-structure
date_learned: 2025-07-11T16:51:00
---
---
🔥 Langsung saja! Ini **soal ke-15** — dan ini akan menantang pemahaman `list` dalam manipulasi dua arah. Sangat cocok ditutup dengan ini.

---
#  Soal 15 — Editor Teks Sederhana

### 🧠 Deskripsi:

Kamu diminta mensimulasikan editor teks _sederhana_ berbasis karakter dengan **satu kursor**, seperti di terminal jadul.

Editor menyimpan karakter dalam barisan. Kamu bisa:

- Mengetik karakter (menambah di posisi kursor)
    
- Menghapus karakter di kiri kursor (`BACKSPACE`)
    
- Memindah kursor ke kiri atau ke kanan

### 📥 Input:

- Baris pertama: `n` — jumlah perintah
    
- `n` baris berikutnya: perintah, bisa berupa:
    
    - `"TIK c"` — ketik karakter `c`
        
    - `"KIRI"` — geser kursor satu langkah ke kiri
        
    - `"KANAN"` — geser kursor satu langkah ke kanan
        
    - `"BACKSPACE"` — hapus karakter di kiri kursor
### 📤 Output:

- Satu baris: isi editor setelah semua perintah

### 🧪 Contoh Input:

```
7
TIK a
TIK b
TIK c
KIRI
BACKSPACE
TIK x
KANAN
```

### 💬 Output:

```
axc
```
### 💡 Petunjuk:

- Gunakan `list<char>` untuk menyimpan karakter
    
- Gunakan iterator `auto cursor = text.begin();` sebagai posisi kursor
    
- `insert(cursor, ch)` untuk menyisipkan sebelum kursor
    
- `erase(prev(cursor))` untuk `BACKSPACE`

# Jawabanku
Berikut adalah jawabanku yang sudah tepat dan optimal:

```cpp
#include<iostream>
#include<list>
#include<string>
#include<sstream>
using namespace std;

int main() {
    list<char> curs;
    auto itr = curs.begin();  

    int n; cin >> n;
    cin.ignore(); 

    while(n--){
        string s;
        getline(cin, s);
        stringstream ss(s);
        string cmd; char c;
        ss >> cmd;

        if(cmd == "TIK"){
            ss >> c;
            curs.insert(itr, c);      
        } else if (cmd == "KIRI"){
            if(itr != curs.begin()) itr--;
        } else if (cmd == "KANAN"){
            if(itr != curs.end()) itr++;
        } else if (cmd == "BACKSPACE"){
            if(itr != curs.begin()) {
                auto temp = itr;
                curs.erase(--temp);   
            }
        }
    }

    for(const char& ch : curs) cout << ch;
    cout << "\n";
    return 0;
}
```

# Editorial
Mantap! 🎉 Karena kamu sudah menyelesaikan soal ke-15 dengan sempurna, berikut ini editorial lengkap per blok kode program untuk implementasi editor teks berbasis `list<char>` dan kursor (`iterator`).

---

## 🧾 Kode Program (Final)

```cpp
#include<iostream>
#include<list>
#include<string>
#include<sstream>
using namespace std;

int main() {
    list<char> curs;
    auto itr = curs.begin();  // posisi awal kursor di depan teks

    int n; cin >> n;
    cin.ignore(); // hapus newline setelah input angka

    while(n--){
        string s;
        getline(cin, s);
        stringstream ss(s);
        string cmd; char c;
        ss >> cmd;

        if(cmd == "TIK"){
            ss >> c;
            curs.insert(itr, c);      // ketik karakter sebelum kursor
        } else if (cmd == "KIRI"){
            if(itr != curs.begin()) itr--; // geser kursor ke kiri
        } else if (cmd == "KANAN"){
            if(itr != curs.end()) itr++; // geser kursor ke kanan
        } else if (cmd == "BACKSPACE"){
            if(itr != curs.begin()) {
                auto temp = itr;
                curs.erase(--temp);   // hapus karakter sebelum kursor
            }
        }
    }

    for(const char& ch : curs) cout << ch;
    cout << "\n";
    return 0;
}
```

---

## 📖 Editorial Per Blok

### 🔷 Header & Namespace

```cpp
#include<iostream>
#include<list>
#include<string>
#include<sstream>
using namespace std;
```

- `iostream` → untuk input/output
    
- `list` → struktur data utama untuk teks
    
- `string` & `stringstream` → untuk memproses input per baris dan per kata
### 🔷 Inisialisasi Struktur Data

```cpp
list<char> curs;
auto itr = curs.begin();
```

- `curs` menyimpan karakter satu per satu
    
- `itr` berperan sebagai **kursor**
    
    - Menunjuk ke posisi **antara** karakter dalam editor

### 🔷 Input Jumlah Operasi

```cpp
int n; cin >> n;
cin.ignore(); // penting untuk membuang newline setelah angka
```

- `cin.ignore()` wajib, karena `getline()` berikutnya bisa terjebak dengan newline sisa input `n`

### 🔷 Proses Setiap Perintah

```cpp
while(n--){
    string s;
    getline(cin, s);
    stringstream ss(s);
    string cmd; char c;
    ss >> cmd;
```

- Baca satu baris perintah penuh
    
- Gunakan `stringstream` untuk memecah menjadi kata (command + argumen)
    
#### 📝 TIK → Mengetik karakter

```cpp
if(cmd == "TIK"){
    ss >> c;
    curs.insert(itr, c);
}
```

- Menyisipkan karakter `c` **sebelum posisi kursor**
    
- Secara visual: teks = `...X[c]Y...`, di mana `[]` = posisi `itr`
    

#### ⬅️ KIRI → Geser kursor ke kiri

```cpp
else if (cmd == "KIRI"){
    if(itr != curs.begin()) itr--;
}
```

- Geser iterator `itr` mundur 1 langkah
    
- Tidak boleh melampaui awal list

#### ➡️ KANAN → Geser kursor ke kanan

```cpp
else if (cmd == "KANAN"){
    if(itr != curs.end()) itr++;
}
```

- Geser iterator maju 1 langkah
    
- Tidak boleh melewati `end()`
#### ⌫ BACKSPACE → Hapus karakter kiri kursor

```cpp
else if (cmd == "BACKSPACE"){
    if(itr != curs.begin()) {
        auto temp = itr;
        curs.erase(--temp);
    }
}
```

- Hapus karakter **tepat sebelum** kursor
    
- Simpan iterator `temp = itr`, lalu `--temp` untuk menunjuk ke kiri, lalu hapus
    

---

### 🖨️ Cetak Hasil Akhir

```cpp
for(const char& ch : curs) cout << ch;
cout << "\n";
```

- Setelah semua operasi selesai, cetak isi list satu per satu
    
- Output berupa string final dari isi editor
    

## ✅ Ilustrasi Eksekusi Contoh:

Input:

```
7
TIK a
TIK b
TIK c
KIRI
BACKSPACE
TIK x
KANAN
```

Langkah demi langkah:

- Tik `a` → `a|`
    
- Tik `b` → `ab|`
    
- Tik `c` → `abc|`
    
- KIRI → `ab|c`
    
- BACKSPACE → `a|c`
    
- Tik `x` → `ax|c`
    
- KANAN → `axc|`
    

Output akhir: `axc`

## 🏁 Kesimpulan

|Aspek|Status|
|---|---|
|Struktur `list<char>`|✅|
|Kursor dinamis dengan `iterator`|✅|
|Operasi sesuai spesifikasi|✅|
|Efisien dan bersih|✅|

