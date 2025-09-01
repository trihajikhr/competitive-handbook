---
obsidianUIMode: preview
note_type: latihan
latihan: Simulasi Undo Daftar Tugas
sumber: Google.com, AI
tags:
  - vector
  - data-structure
date_learned: 2025-06-14T21:45:00
---
---
# 🧩 Soal 10: Simulasi Undo Daftar Tugas

Fokus ke `vector::pop_back()` dan operasi dasar stack-like

---

## 🎯 Deskripsi:

Kamu diminta membuat program daftar tugas yang mendukung dua operasi:

1. **ADD nama_tugas** → Menambahkan tugas ke akhir daftar
    
2. **UNDO** → Menghapus tugas terakhir (seperti `pop_back()`)
    

---

## 📥 Input Format:

```
q     // jumlah perintah
<q baris perintah>
```

Perintah hanya salah satu dari:

- `ADD Belajar`
    
- `ADD Makan`
    
- `UNDO`
    
- `SHOW`
    

---

## 📤 Output:

Setiap `SHOW` akan mencetak seluruh tugas saat ini dari awal ke akhir, atau mencetak `"KOSONG"` jika list kosong.

---

## 🧪 Contoh Input:

```
6
ADD Belajar
ADD Makan
SHOW
UNDO
SHOW
UNDO
```

## ✅ Contoh Output:

```
Belajar
Makan
Belajar
KOSONG
```

---

## 💡 Catatan:

- Gunakan `vector<string> stack`
    
- `ADD` → `push_back()`
    
- `UNDO` → `pop_back()` jika tidak kosong
    
- `SHOW` → tampilkan semua isi atau `"KOSONG"`
    

---

Kalau kamu udah siap, langsung kerjain dan kirim ke sini — aku akan bantu review dan kasih editorial lengkap seperti biasa. 🚀

## Jawabanku
Berikut adalah kode jawabanku:

```cpp
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<string> stack;

    while(n--){
        string s;
        getline(cin >> ws, s);

        stringstream ss(s);
        string cmd;
        ss >> cmd;

        if(cmd == "ADD"){
            string word;
            ss >>  word >> ws;
            getline(ss, word);
            stack.push_back(word);
        } else if (cmd == "UNDO"){
            stack.pop_back();
        } else {
            if(!stack.empty()){
                for(const auto&x:stack){
                    cout << x << "\n";
                }
            } else {
                cout << "KOSONG\n";
            }
        }
    }
    return 0;
}
```

## Editorial
Kerja bagus! ✅ Kode kamu **berfungsi dengan benar** untuk menangani perintah `ADD`, `UNDO`, dan `SHOW`. Berikut adalah **editorial lengkap**, termasuk penjelasan fitur `vector` yang kamu gunakan dan saran penyempurnaan kecil.

---


### Header dan Setup

```cpp
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
```

- Menggunakan `vector` sebagai struktur data utama.
    
- `stringstream` digunakan untuk parsing kalimat perintah.
    

```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

- Mempercepat input/output.
    

### Input Jumlah Perintah dan Inisialisasi Stack

```cpp
int n; cin >> n;
vector<string> stack;
```

- `stack` adalah vector biasa, tapi digunakan seperti stack (LIFO).
    

---

### 🌟 Parsing dan Eksekusi Perintah

```cpp
while(n--){
    string s;
    getline(cin >> ws, s);
```

- `getline(cin >> ws, s);` berguna untuk membaca seluruh baris, termasuk spasi setelah perintah.
    

---

### 🚀 Perintah `ADD`

```cpp
    stringstream ss(s);
    string cmd;
    ss >> cmd;

    if(cmd == "ADD"){
        string word;
        ss >>  word >> ws;
        getline(ss, word);
        stack.push_back(word);
    }
```

- Bagian `ss >> word >> ws; getline(ss, word);` akan mengambil kata setelah `ADD`, dan mengambil sisanya sebagai `word`.
    
- Tugas baru ditambahkan ke akhir vector (seperti `push` dalam stack).
    

### 🧼 Perintah `UNDO`

```cpp
else if (cmd == "UNDO"){
    stack.pop_back();
}
```

- Menghapus elemen terakhir dari vector — sangat cocok dengan konsep undo.
    

> ⚠️ **Saran kecil:** Tambahkan pengecekan agar tidak `pop_back()` pada vector kosong:

```cpp
if(!stack.empty()) stack.pop_back();
```

### 👁️ Perintah `SHOW`

```cpp
else {
    if(!stack.empty()){
        for(const auto&x:stack){
            cout << x << "\n";
        }
    } else {
        cout << "KOSONG\n";
    }
}
```

- Menampilkan isi vector.
    
- Kalau kosong, cetak `"KOSONG"`.
    

---

## ✅ Fungsi Vector yang Kamu Gunakan

|Fungsi Vector|Peran|
|---|---|
|`push_back()`|Menambahkan tugas baru|
|`pop_back()`|Menghapus tugas terakhir|
|`empty()`|Mengecek apakah stack kosong|
|Iterasi `for`|Menampilkan isi daftar tugas|

---

## 🧠 Rangkuman

- Kamu telah **menggunakan vector sebagai stack** dengan cara yang sangat tepat.
    
- Parsing input multi-kata sudah bagus.
    
- Kode sudah **rapi dan aman**, tinggal tambahkan pengecekan kecil untuk `UNDO`.
    

---

## 🧪 Mau Variasi Lebih Menantang?

Berikut beberapa ide soal lanjutan:

1. **Soal 11: UNDO + REDO**
    
    - Tambahkan fitur `REDO` (dengan dua vector: `stack` dan `redo_buffer`).
        
2. **Soal 12: Edit Tugas**
    
    - Perintah `EDIT i TeksBaru` untuk mengubah tugas ke-i.
        
3. **Soal 13: Copy-Paste Blok Tugas**
    
    - `COPY i j`, `PASTE k`
        

Tertarik ke yang mana dulu? Atau mau lanjut ke **Soal 11: UNDO + REDO**? 💡