---
obsidianUIMode: preview
note_type: latihan
latihan: Menambahkan Kontak dengan emplace
sumber: Google.com, AI
tags:
  - data-structure
  - unordered_map
date_learned: 2025-06-16T20:44:00
---
Mantap! Kita lanjut ke Soal Nomor 11: Mengenal `emplace()` pada `unordered_map` 🚀

---

# 🧠 Soal 11: Menambahkan Kontak dengan `emplace()`

Buatlah program C++ untuk menyimpan data kontak dalam `unordered_map<string, string>`.  
Setiap baris input berupa:

```
[nama] [nomor_telepon]
```

Tambahkan data ke dalam map menggunakan fungsi `emplace()`.  
Jika kontak dengan `nama` tersebut **sudah ada**, maka **abaikan** (jangan diubah).  
Setelah seluruh input dimasukkan, cetak seluruh isi `unordered_map` dalam format:

```
[nama]: [nomor_telepon]
```

Contoh input:

```
Andi 0812
Budi 0813
Andi 0819
Citra 0821
```

Contoh output:

```
Andi: 0812
Budi: 0813
Citra: 0821
```

---

### 🎯 **Tujuan**

- Melatih penggunaan `emplace()`
    
- Mengenal perbedaan antara `insert()` vs `emplace()`
    
- Menangani penambahan data dengan pengecekan duplikasi
    

Kalau kamu sudah selesai mengerjakan, tinggal kirim kodenya ke sini ya! 👨‍💻

## Jawabanku
Berikut adalah kode jawabanku yang sudah benar dan clean:

```cpp
#include<iostream>
#include<unordered_map>
#include<sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, string> kontak;
    kontak.reserve(20);

    string s;
    while(getline(cin >> ws, s)){
        stringstream ss(s);
        string nama, no;
        ss >> nama >> no;
    
        kontak.emplace(nama, no);
    }

    for(const auto&[key, val]: kontak){
        cout << key << ": " << val << "\n";
    }
    return 0;
}
```

# Editorial
✅ **Jawabanmu sudah sangat tepat!**  
Kamu **berhasil** menggunakan `emplace()` dengan benar untuk menambahkan data ke dalam `unordered_map` **tanpa menimpa data yang sudah ada**. Berikut beberapa catatan dan penegasan agar kamu bisa menyimpannya ke dalam catatanmu:

---

### 📌 Penjelasan Kode

```cpp
unordered_map<string, string> kontak;
kontak.reserve(20);
```

- Kamu menginisialisasi `unordered_map` untuk menyimpan pasangan `nama → nomor`, dan langsung melakukan reservasi kapasitas untuk menghindari rehashing yang tidak perlu.
    

```cpp
kontak.emplace(nama, no);
```

- `emplace()` akan **menambahkan** data **hanya jika key belum ada**.
    
- Jika key `nama` sudah ada, maka **data tidak akan dimasukkan**, berbeda dengan `insert_or_assign()` atau `operator[]` yang akan menimpa isinya.
    

```cpp
for(const auto&[key, val]: kontak){
    cout << key << ": " << val << "\n";
}
```

- Ini mencetak seluruh isi `unordered_map`. Urutannya **tidak dijamin** karena sifat `unordered_map`.
    

---

### ✅ Kesimpulan

- Fungsi `emplace()` sangat cocok ketika kamu ingin **menyisipkan data tanpa menimpa** entri yang sudah ada.
    
- Lebih efisien daripada `insert()` saat kamu menghindari pembuatan temporary object karena langsung membangun data di tempat.
    

---

Kalau sudah dicatat, kita bisa lanjut ke **soal nomor 12** ya! 🚀