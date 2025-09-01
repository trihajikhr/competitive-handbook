---
obsidianUIMode: preview
note_type: latihan
latihan: Simulasi Editor Daftar Tugas
sumber: Google.com, AI
tags:
  - data-structure
  - vector
date_learned: 2025-06-14T21:45:00
---
---
# Simulasi Editor Daftar Tugas

## 🧪 Soal 9: Simulasi Editor Daftar Tugas

Kamu diminta membuat program yang mensimulasikan **daftar tugas** dengan fitur-fitur berikut:

### 📥 Input:

1. Integer `n` — jumlah awal tugas
    
2. `n` baris string — tiap baris adalah nama tugas awal
    
3. Integer `q` — jumlah perintah yang akan dijalankan
    
4. `q` baris perintah, dengan format berikut:
    
    - `INSERT pos nama` → tambahkan tugas baru `nama` di posisi `pos` (0-based)
        
    - `DELETE pos` → hapus tugas di posisi `pos`
        
    - `SHOW` → tampilkan seluruh isi daftar, pisahkan dengan newline
        

---

### 💡 Ketentuan:

- Gunakan `vector<string> list`
    
- Gunakan:
    
    - `insert(...)`
        
    - `erase(...)`
        
    - `size()` untuk validasi posisi
        
- Abaikan perintah `INSERT`/`DELETE` jika `pos` tidak valid
    
- Perintah `SHOW` bisa muncul lebih dari sekali
    

---

### 🧪 Contoh Input:

```
3
Belajar
Makan
Tidur
5
INSERT 1 Ngoding
SHOW
DELETE 2
SHOW
INSERT 10 Nonton
```

### ✅ Output:

```
Belajar
Ngoding
Makan
Tidur
Belajar
Ngoding
Tidur
```

---

### 🎯 Tujuan:

- Melatih penggunaan:
    
    - `vector::insert(pos, value)`
        
    - `vector::erase(pos)`
        
    - `vector::size()` untuk validasi
        
- Memahami posisi dan efek penyisipan/penghapusan dalam vector
    

---

Kalau sudah kamu kerjakan, tinggal kirim ke sini — nanti aku bantu review dan kasih editorial lengkap seperti biasa! 🔥

## Jawabaku
Kode programku, walaupun ternyata masih kurang:

```cpp
#include<iostream>
#include<cctype>
#include<vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<string> list(n);
    for(auto&x:list){
        cin >> x;
    }

    int q; cin >> q;
    while(q--){
        string s; 
        getline(cin >> ws, s);

        int idx;
        if(s.contains("INSERT")){
            for(char c: s){
                if(isdigit(c)){
                    idx=c-'0';
                    break;
                }
            }

            string add;
            int space=0;
            for(int i=0; i<s.length();i++){
                if(s[i]==' '){
                    space++;
                }

                if(space==2){
                    add=s.substr(i+1);
                    break;
                }
            }

            list.insert(list.begin() + (idx - 1), add);
        }

        else if (s.contains("SHOW")){
            for(const auto&x:list){
                cout << x << "\n";
            }
        }

        else if (s.contains("DELETE")){
            for(char c:s){
                if(isdigit(c)){
                    idx=c-'0';
                    break;
                }
            }

            list.erase(list.begin() + idx-1);
        }
    }
    return 0;
}
```

## Editorial
Bagus banget! 🔥 Kamu udah berhasil membuat parser perintah manual dari `string`, lalu memetakan perintah `INSERT`, `DELETE`, dan `SHOW` dengan operasi vector! Tapi ada beberapa **catatan dan penyempurnaan** supaya lebih **aman, fleksibel, dan scalable**.

---

### ✅ Penilaian Umum

|Aspek|Penilaian|
|---|---|
|Fungsi vector|✅ `insert`, `erase`, `size`, `begin` digunakan benar|
|Indeks 1-based|✅ Sudah dikonversi ke 0-based dengan `(idx - 1)`|
|Perintah SHOW|✅ Sudah menampilkan semua isi|
|Parsing string|⚠️ Masih lemah pada dua hal (dijelaskan di bawah)|
|Validasi index|❌ Belum ada — bisa error kalau `DELETE 10` di data 3 elemen|
|Digit parsing|❌ Kurang fleksibel — hanya ambil satu digit `c-'0'`, tidak bisa `DELETE 12`|

---

### ⚠️ Masalah yang Ditemukan

#### 1. `isdigit(c)` hanya ambil satu digit:

```cpp
for(char c:s){
    if(isdigit(c)){
        idx=c-'0'; // ini cuma valid untuk angka 0 sampai 9
        break;
    }
}
```

Kalau input `INSERT 12 Laporan`, `idx` hanya jadi `1`, karena kamu ambil angka pertama saja.

##### 🔧 Solusi: Parsing pakai `stringstream`:

```cpp
#include <sstream>
...
stringstream ss(s);
string cmd;
ss >> cmd;
if(cmd == "INSERT"){
    int idx;
    string word;
    ss >> idx >> ws;
    getline(ss, word);
    ...
}
```

---

#### 2. Belum ada **validasi indeks**:

Contoh:

```cpp
DELETE 999
```

Akan menyebabkan `vector::erase` mengakses lokasi tidak valid ⇒ program crash.

#### 🔧 Solusi:

Sebelum `insert` atau `erase`, tambahkan:

```cpp
if(idx < 1 || idx > list.size()+1) continue; // untuk INSERT
if(idx < 1 || idx > list.size()) continue;   // untuk DELETE
```

---

## ✅ Versi Revisi (lebih kuat dan scalable)

```cpp
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<string> list(n);
    for(auto& x : list) cin >> x;

    int q; cin >> q;
    cin.ignore(); // buang newline setelah angka

    while(q--) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string cmd;
        ss >> cmd;

        if(cmd == "INSERT") {
            int pos; string value;
            ss >> pos >> ws;
            getline(ss, value);

            if(pos >= 1 && pos <= list.size() + 1)
                list.insert(list.begin() + (pos - 1), value);
        }
        else if(cmd == "DELETE") {
            int pos;
            ss >> pos;

            if(pos >= 1 && pos <= list.size())
                list.erase(list.begin() + (pos - 1));
        }
        else if(cmd == "SHOW") {
            for(const auto& x : list)
                cout << x << "\n";
        }
    }

    return 0;
}
```

---

## 🧠 Editorial Ringkas

| Baris Kode                             | Penjelasan                                         |
| -------------------------------------- | -------------------------------------------------- |
| `getline(cin, line)`                   | Membaca seluruh perintah dalam satu string         |
| `stringstream ss(line)`                | Membantu memecah string berdasarkan spasi          |
| `cmd == "INSERT"`                      | Mengecek jenis perintah                            |
| `ss >> pos >> ws; getline(ss, value);` | Membaca posisi dan string (yang bisa berisi spasi) |
| Validasi index                         | Mencegah crash saat posisi di luar jangkauan       |
| `list.insert(...)`, `list.erase(...)`  | Operasi utama yang diminta soal                    |

---

# Variasi `string::find()` dan `npos`
Siap! Kita akan bahas **variasi `string::npos`** dalam konteks program editor list kamu, agar kamu bisa mengenali kapan dan bagaimana `npos` muncul, serta menghindari bug halus.

---

## 🧩 Apa itu `string::npos`?

`string::npos` adalah **nilai khusus** (`size_t`) yang digunakan untuk menunjukkan bahwa **pencarian tidak menemukan hasil** dalam string.

Contoh:

```cpp
string s = "halo";
size_t pos = s.find("z");  // tidak ditemukan
if(pos == string::npos) cout << "Tidak ketemu!";
```

---

## ✅ Variasi Soal: Deteksi Perintah Tak Dikenal dengan `npos`

### 🎯 Tujuan:

- Melatih `string::find()`
    
- Mengenal `string::npos`
    
- Mendeteksi jika perintah tidak valid dan mengabaikannya
    

---

## 🧪 Soal 9B: Editor Daftar Tugas + Validasi Perintah

### 📥 Input:

1. Integer `n` — jumlah tugas awal
    
2. `n` baris string — tugas awal
    
3. Integer `q` — jumlah perintah
    
4. `q` baris perintah: `INSERT`, `DELETE`, `SHOW`, atau salah ketik
    

### 📤 Output:

- Abaikan perintah yang tidak mengandung `INSERT`, `DELETE`, atau `SHOW`
    
- Jalankan hanya jika perintah ditemukan di string dengan `.find(...) != npos`
    

---

### 💡 Contoh:

**Input:**

```
2
Baca
Coding
5
INSERT 1 Main
SHOW
DELEET 2
DELETE 5
SHWO
```

**Output:**

```
Main
Baca
Coding
```

Penjelasan:

- `INSERT 1 Main` → valid
    
- `SHOW` → valid
    
- `DELEET` → tidak valid (karena tidak mengandung "DELETE")
    
- `DELETE 5` → out of bound → diabaikan
    
- `SHWO` → salah ketik → diabaikan
    

---

## 🧠 Tips Pemakaian `.find()` dan `npos`

```cpp
if(s.find("INSERT") != string::npos) {
    // ini adalah perintah INSERT
}
```

Kalau tidak ditemukan:

```cpp
if(s.find("DELETE") == string::npos) {
    // DELETE tidak ditemukan dalam string
}
```
