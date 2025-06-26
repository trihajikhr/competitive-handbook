---
obsidianUIMode: preview
note_type: latihan
latihan: Reset Data Harian
sumber: Google.com, AI
tags:
  - data-structure
  - unordered_map
date_learned: 2025-06-16T18:34:00
---
---
Sip, kita lanjut ke **Soal Nomor 7**, dan kali ini kamu akan belajar dan mempraktikkan fungsi **`unordered_map::clear()`**.

---

# 🧠 Soal 7: Reset Data Harian

Kamu adalah pengembang sistem pencatat absensi harian. Setiap hari:

- Akan dimasukkan beberapa data absensi berupa: `<nama> <status>`
    
- Lalu sistem akan mencetak semua data yang tersimpan.
    
- Setelah itu, seluruh data harus **dihapus (clear)** untuk hari berikutnya.
    

Tugasmu:

1. Menerima `d` hari (jumlah hari), lalu untuk tiap harinya:
    
    - Baca `n` data absensi
        
    - Simpan ke dalam `unordered_map<string, string>`
        
    - Cetak semua data (urutan boleh bebas karena unordered_map)
        
    - Kosongkan map untuk data hari berikutnya
        

---

### 💡 Format Input

```
d
n
<nama> <status>
...
n
<nama> <status>
...
```

---

### 📥 Contoh Input

```
2
3
andi hadir
budi hadir
citra sakit
2
dina hadir
eko izin
```

---

### 📤 Contoh Output

```
andi: hadir
budi: hadir
citra: sakit
dina: hadir
eko: izin
```

---

### 🎯 Tujuan Pembelajaran

- Mengenal fungsi `clear()` pada `unordered_map`
    
- Mempelajari penggunaan ulang struktur data tanpa deklarasi ulang
    
- Menyusun program yang modular per hari (loop bertingkat)
    

---

Jika kamu siap, langsung coba dulu! Setelah itu, kirimkan jawabanmu ke sini. Kalau butuh petunjuk juga boleh 😄

## Jawabanku

Berikut adalah jawabanku dari soal ini:

```cpp
#include<iostream>
#include<sstream>
#include<unordered_map>
#include<iterator>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    unordered_map<string, string> hadir;

    while(n--){
        int k; cin >> k;
        if(k>100000){
            hadir.max_load_factor(0.5f);
            hadir.reserve(k*2);
        } else {
            hadir.reserve(k);
        }

        string s;
        while(k--){
            getline(cin >> ws, s);

            stringstream ss(s);
            string name, no;
            ss >> name >> no;
            
            hadir.insert_or_assign(name, no);
        }

        for(const auto& [key, value]: hadir){
            cout << key << ": " << value << "\n";
        }

        hadir.clear();
    }


    return 0;
}
```

# Editorial
✅ Jawabanmu **sudah sangat bagus** dan **menggunakan fungsi `clear()` dengan benar!** Berikut adalah penjelasan editorial lengkap untuk kamu catat di Obsidian:

---
### ✨ Tujuan Soal

Melatih penggunaan fungsi `clear()` pada `unordered_map` untuk:

- Menghapus seluruh isi map setelah digunakan
    
- Menggunakan ulang map untuk data baru tanpa deklarasi ulang
    

---

### 🔍 Struktur Program & Penjelasan Baris

```cpp
int n; cin >> n;
```

- Membaca jumlah hari (`n`) sebagai iterasi luar.
    

```cpp
unordered_map<string, string> hadir;
```

- Membuat satu map untuk semua hari. Map ini akan dibersihkan (`clear`) setiap akhir hari, jadi tidak perlu dibuat ulang.
    

---

### 🔁 Per Hari: Looping & Pengisian Data

```cpp
while(n--){
    int k; cin >> k;
```

- Untuk setiap hari, baca jumlah data `k` (banyaknya absensi hari itu).
    

```cpp
    if(k>100000){
        hadir.max_load_factor(0.5f);
        hadir.reserve(k*2);
    } else {
        hadir.reserve(k);
    }
```

- Mengoptimalkan map untuk performa: meminimalkan rehashing.
    

```cpp
    string s;
    while(k--){
        getline(cin >> ws, s);
        stringstream ss(s);
        string name, no;
        ss >> name >> no;
        hadir.insert_or_assign(name, no);
    }
```

- Membaca data absensi `name status`, lalu menyimpannya ke map. `insert_or_assign()` menjamin update jika nama sudah ada.
    

---

### 📤 Cetak & Kosongkan Map

```cpp
    for(const auto& [key, value]: hadir){
        cout << key << ": " << value << "\n";
    }
```

- Mencetak semua data pada map hari itu.
    

```cpp
    hadir.clear();
```

- Menghapus semua data dari map. Ini sangat penting agar tidak terbawa ke hari berikutnya.
    

---

### 📌 Contoh Output

Untuk input:

```
2
2
andi hadir
budi sakit
1
citra izin
```

Output:

```
andi: hadir
budi: sakit
citra: izin
```

---

## 💯 Penilaian: 10/10

- ✅ Menggunakan `clear()` dengan benar
    
- ✅ Struktur modular per hari
    
- ✅ Efisien (pakai `reserve`, `max_load_factor`)
    
- ✅ Idiomatik C++
    

---

Kalau sudah kamu catat, kita lanjut ke **Soal Nomor 8** dengan fungsi baru dari `unordered_map`, siap? 😎