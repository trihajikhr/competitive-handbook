---
obsidianUIMode: preview
note_type: latihan
latihan: Deteksi Duplikasi Kontak
sumber: Google.com, AI
tags:
  - data-structure
  - unordered_map
date_learned: 2025-06-16T20:37:00
---
---
# 🧠 Soal 10: Deteksi Duplikasi Kontak

Buat program yang menyimpan daftar kontak berdasarkan nama. Namun, **jika nama kontak sudah ada**, jangan tambahkan ulang, dan tampilkan pesan:

```
Kontak dengan nama X sudah ada.
```

Jika belum ada, masukkan ke dalam map.

#### 📥 Input

Baris pertama: satu bilangan bulat `n` – banyaknya baris data.  
Berikutnya `n` baris: setiap baris berisi `nama nomor_hp`.

#### 📤 Output

- Untuk setiap nama yang belum pernah dimasukkan, simpan dalam map.
    
- Untuk setiap nama yang **sudah ada**, tampilkan:
    

```
Kontak dengan nama <nama> sudah ada.
```

#### 💡 Contoh Input

```
5
Adit 081234
Budi 081111
Adit 099999
Citra 082222
Budi 083333
```

#### 📋 Contoh Output

```
Kontak dengan nama Adit sudah ada.
Kontak dengan nama Budi sudah ada.
```

---

### 🎯 Tujuan Latihan:

- Menggunakan `unordered_map.count(key)` untuk memeriksa apakah key sudah ada **sebelum** `insert`.
    
- Tidak menggunakan `operator[]` agar tidak otomatis membuat key baru.
    

---

Kalau sudah selesai, kirimkan kodenya — nanti aku beri evaluasi dan kita lanjut ke soal berikutnya!

## Jawabanku
Berikut adalah jawaban yang sudah benar dan clean

```cpp
#include<iostream>
#include<unordered_map>
#include<sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    unordered_map<string, string> kontak;
    kontak.reserve(20);

    string s;
    while(n--){
        getline(cin >> ws, s);

        stringstream ss(s);
        string nama, no;
        ss >> nama >> no;

        if(kontak.count(nama)){
            cout << "Kontak dengan nama " << nama << " sudah ada.\n";
        } else {
            kontak.insert({nama, no});
        }
    }
    return 0;
}
```

# Editorial
✅ **Keren! Kodenya sudah tepat dan clean.**  
Kamu berhasil menggunakan `unordered_map.count()` dengan benar untuk mengecek apakah key sudah ada **sebelum** memasukkannya. Berikut sedikit evaluasi dan penguatan:

---

### ✅ Yang Sudah Bagus:

- `kontak.count(nama)` digunakan **tanpa menyebabkan insert otomatis**, beda dengan `kontak[nama]`.
    
- Gunakan `kontak.insert(...)` dengan pair, yang efisien untuk data baru.
    
- `getline(cin >> ws, s)` menangani spasi di awal string dengan tepat.
    
- Sudah pas pakai `stringstream` untuk parsing `nama` dan `no`.
    
- `kontak.reserve(20)` = bagus buat efisiensi kecil-menengah.
    

---

### 🧠 Catatan Kecil (Tidak Wajib Diperbaiki)

- Jika jumlah `n` sangat besar (misal >10k), kamu bisa tambahkan heuristik seperti sebelumnya:
    

```cpp
if(n > 10000){
    kontak.max_load_factor(0.5f);
    kontak.reserve(n * 2);
} else {
    kontak.reserve(n);
}
```

---

Siap lanjut ke **Soal Nomor 11**? Ini akan mengenalkan kamu ke **fungsi `.equal_range()`** yang berguna pada `unordered_multimap`.