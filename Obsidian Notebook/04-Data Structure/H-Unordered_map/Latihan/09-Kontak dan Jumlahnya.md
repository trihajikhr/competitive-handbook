---
obsidianUIMode: preview
note_type: latihan
latihan: Kontak dan Jumlahnya
sumber: Google.com, AI
tags:
  - data-structure
  - unordered_map
date_learned: 2025-06-16T19:33:00
---
---
Berikut **Soal Nomor 9** dalam seri latihan `unordered_map` — fokus kita sekarang adalah fungsi **`size()`**.

---

# 🧠 Soal Nomor 9: Kontak dan Jumlahnya

Kamu sedang membuat sistem buku kontak. Setiap baris perintah terdiri dari:

- `tambah <nama> <nomor>` — menambahkan kontak baru atau memperbarui jika sudah ada.
    
- `hapus <nama>` — menghapus kontak berdasarkan nama.
    
- `jumlah` — mencetak jumlah total kontak yang tersimpan saat ini.
    

---

#### 🧪 Contoh Input:

```
tambah andi 0812
tambah budi 0821
jumlah
hapus andi
jumlah
```

#### 🎯 Contoh Output:

```
2
1
```

---

### 📝 Catatan:

- Gunakan `unordered_map<string, string>` untuk menyimpan data.
    
- Gunakan fungsi **`size()`** untuk mencetak jumlah data.
    
- Pastikan `getline()` tetap digunakan untuk menangani input lebih dari satu kata.
    

---

Jika sudah selesai mengerjakan, kirimkan jawabanmu ya — nanti akan aku nilai dan buatkan editorialnya! 💪

## Jawaban
Berikut adalah jawabanku untuk soal ini:

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
        string cmd;
        ss >> cmd;

        string name, hp;
        if(cmd=="tambah"){
            ss >> name >> hp;
            kontak.insert_or_assign(name, hp);
        } else if (cmd=="jumlah"){
            cout << kontak.size() << "\n";
        } else if (cmd=="hapus"){
            ss >> name;
            if (kontak.find(name) != kontak.end()){
                kontak.erase(name);
            }
        }
    }
    return 0;
}
```

# Editorial
✅ Jawabanmu **benar dan efisien!**  
Kamu telah menggunakan fungsi `unordered_map::size()` dengan tepat, serta menangani input dengan baik menggunakan `getline` dan `stringstream`.

---

## 📘 Editorial Soal Nomor 9 – Fungsi `size()` pada `unordered_map`

#### 🧩 Tujuan Soal

Melatih penggunaan:

- `insert_or_assign()` untuk menambahkan atau memperbarui entri
    
- `erase()` untuk menghapus entri berdasarkan key
    
- `size()` untuk mengetahui jumlah total pasangan key-value dalam `unordered_map`
    

---

### 🔍 Penjelasan Kode

```cpp
unordered_map<string, string> kontak;
kontak.reserve(20);
```

- Membuat map `kontak` untuk menyimpan nama dan nomor HP.
    
- `reserve(20)` sebagai pre-alokasi untuk efisiensi saat dimasukkan data baru.
    

---

```cpp
while(getline(cin >> ws, s)){
    stringstream ss(s);
    string cmd;
    ss >> cmd;
```

- Membaca input satu baris penuh, lalu memecahnya dengan `stringstream`.
    
- `cmd` menyimpan perintah: `"tambah"`, `"jumlah"`, atau `"hapus"`.
    

---

```cpp
if(cmd=="tambah"){
    ss >> name >> hp;
    kontak.insert_or_assign(name, hp);
}
```

- Jika perintah `"tambah"`, langsung update atau insert pasangan nama dan nomor.
    

---

```cpp
else if (cmd=="jumlah"){
    cout << kontak.size() << "\n";
}
```

- Menampilkan ukuran map dengan `size()`.
    

---

```cpp
else if (cmd=="hapus"){
    ss >> name;
    if (kontak.find(name) != kontak.end()){
        kontak.erase(name);
    }
}
```

- Menghapus entri jika key ditemukan.
    

---

### 🧪 Contoh Output

Untuk input:

```
tambah andi 0812
tambah budi 0821
jumlah
hapus andi
jumlah
```

Output:

```
2
1
```

---

### 🎯 Catatan Penting

- `size()` sangat efisien karena memiliki kompleksitas waktu **O(1)**.
    
- Tidak perlu iterasi manual untuk menghitung jumlah pasangan key-value dalam `unordered_map`.
    

---

Siap ke **Soal Nomor 10**? Soal selanjutnya akan fokus ke fungsi **`clear()`**.