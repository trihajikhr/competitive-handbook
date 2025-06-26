---
obsidianUIMode: preview
note_type: latihan
latihan: Cek Apakah Daftar Kontak Kosong
sumber: Google.com, AI
tags:
  - data-structure
  - unordered_map
date_learned: 2025-06-16T18:47:00
---
---
Mantap! Kita masuk ke **Soal Nomor 8**, dan kali ini kamu akan berlatih menggunakan fungsi `unordered_map::empty()`.

---
# 🧠 Soal 8: Cek Apakah Daftar Kontak Kosong

Dalam sebuah aplikasi pesan, ada fitur untuk memeriksa apakah daftar kontak pengguna masih kosong.

Buatlah program yang:

1. Membaca perintah-perintah berikut:
    
    - `tambah <nama> <nomor>` → tambahkan kontak
        
    - `hapus <nama>` → hapus kontak
        
    - `cek_kosong` → cetak `YA` jika map kosong, `TIDAK` jika tidak
        
2. Jalankan perintah hingga akhir input (misal hingga EOF atau jumlah perintah yang sudah ditentukan)
    

---

### 📥 Contoh Input

```
tambah andi 0811
tambah budi 0812
cek_kosong
hapus andi
hapus budi
cek_kosong
```

---

### 📤 Contoh Output

```
TIDAK
YA
```

---

### 📚 Tujuan Pembelajaran

- Mengenal fungsi `empty()` untuk memeriksa apakah map tidak memiliki elemen
    
- Menggabungkan perintah-perintah dinamis untuk manipulasi map
    
- Memahami kondisi ketika map kosong secara efisien
    

---

Kalau kamu butuh batasan input, kita bisa set misalnya `q` jumlah perintah dibaca di awal. Tapi kalau mau pakai `while(getline(...))` juga boleh biar fleksibel.

Silakan kamu kerjakan dulu ya, nanti aku bantu evaluasi jawabanmu 😄

## Jawabanku
Berikut adalah kode programku:

```cpp
#include<iostream>
#include<sstream>
#include<unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unordered_map<string, string> kontak;
    kontak.reserve(20);

    string s;
    while(getline(cin >> ws, s)){
    
        stringstream ss(s);
        string cmd;
        ss >> cmd;

        if(cmd=="tambah"){
            string name, no;
            ss >> name >> no;
            kontak.insert_or_assign(name, no);

        } else if (cmd=="cek_kosong"){
            if(kontak.empty()) cout << "YA\n";
            else cout << "TIDAK\n";

        } else if (cmd=="hapus"){
            string userErase;
            getline(ss >> ws, userErase);

            if(kontak.find(userErase) != kontak.end()){
                kontak.erase(userErase);
            } 
        }
    }
    return 0;
}
```

# Editorial
✅ **Keren! Jawabanmu sudah benar dan efisien!** Kamu sudah berhasil mengimplementasikan perintah-perintah yang diminta dan menggunakan fungsi `unordered_map::empty()` dengan tepat. Berikut **editorial lengkapnya** untuk kamu catat ke Obsidian:

---

### 🎯 Tujuan

- Melatih penggunaan fungsi `empty()` untuk mengecek apakah map kosong
    
- Menggunakan perintah-perintah dinamis untuk memodifikasi `unordered_map`
    
- Memahami kondisi kosong dalam konteks real-world (kontak, data user, dll.)
    

---

### 🧩 Struktur Program & Penjelasan

```cpp
unordered_map<string, string> kontak;
kontak.reserve(20);
```

- Membuat `unordered_map` untuk menyimpan nama dan nomor kontak. `reserve(20)` adalah optimalisasi ringan (optional).
    

---

### 🔄 Perintah Dinamis

```cpp
while(getline(cin >> ws, s)){
    stringstream ss(s);
    string cmd;
    ss >> cmd;
```

- Menggunakan `getline` agar bisa membaca satu baris penuh dan diproses lewat `stringstream`. Ini fleksibel untuk perintah-perintah berbeda.
    

---

#### 📥 Perintah `tambah`

```cpp
string name, no;
ss >> name >> no;
kontak.insert_or_assign(name, no);
```

- Menambahkan atau memperbarui kontak. `insert_or_assign` menjaga agar duplikat nama langsung ditimpa.
    

#### 🔍 Perintah `cek_kosong`

```cpp
if(kontak.empty()) cout << "YA\n";
else cout << "TIDAK\n";
```

- Mengecek apakah map kosong. Fungsi `empty()` sangat efisien, hanya O(1).
    

#### ❌ Perintah `hapus`

```cpp
string userErase;
getline(ss >> ws, userErase);

if(kontak.find(userErase) != kontak.end()){
    kontak.erase(userErase);
}
```

- Menghapus kontak dari map jika ditemukan. `find` mencegah error jika user tidak ada.
    

---

### 📌 Contoh

#### Input:

```
tambah andi 0811
tambah budi 0812
cek_kosong
hapus andi
hapus budi
cek_kosong
```

#### Output:

```
TIDAK
YA
```

---

## ✅ Penilaian: 10/10

- ✅ Fungsi `empty()` dipakai tepat
    
- ✅ Input fleksibel dengan `stringstream`
    
- ✅ Aman dari crash (`find` dicek dulu sebelum `erase`)
    
- ✅ Rapi dan idiomatik
    

---

Kalau sudah kamu catat, ayo kita lanjut ke **Soal Nomor 9**, dan kali ini akan melibatkan **fungsi `size()`** untuk menghitung jumlah elemen map! Mau langsung lanjut? 😎