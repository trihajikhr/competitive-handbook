---
obsidianUIMode: preview
note_type: latihan
latihan: Pengurutan Tugas Prioritas
sumber: chatgpt.com
tags:
  - list
  - data-structure
date_learned: 2025-07-09T11:11:00
---
---
Mantap! Kita lanjut ke soal kedua dengan sedikit tantangan tambahan—kali ini kamu akan diminta memodifikasi list berdasarkan urutan indeks, jadi tidak hanya berdasarkan nilai.

---
# Soal 2: Pengurutan Tugas Prioritas

### 📝 Deskripsi:

Kamu mengelola daftar tugas yang disimpan dalam `std::list<int>`. Tugasmu adalah memproses beberapa perintah yang dapat:

- Menambah elemen di awal atau akhir,
    
- Menghapus elemen berdasarkan indeks,
    
- Mengganti nilai pada indeks tertentu,
    
- Mencetak isi list.
    

Karena `std::list` tidak mendukung akses langsung via indeks seperti array, kamu harus melakukan penelusuran manual.

---

### 📥 Input:

Baris pertama berisi bilangan bulat **N** — jumlah perintah.  
Setiap dari N baris berikutnya berisi salah satu perintah berikut:

- `"ADD_FRONT x"` — Tambahkan `x` ke depan list
    
- `"ADD_BACK x"` — Tambahkan `x` ke belakang list
    
- `"REMOVE_AT i"` — Hapus elemen pada indeks `i` (jika valid)
    
- `"REPLACE i x"` — Ganti elemen pada indeks `i` dengan nilai `x` (jika valid)
    
- `"PRINT"` — Cetak isi list dalam satu baris, pisahkan dengan spasi. Jika kosong, cetak `EMPTY`
    

---

### 📤 Output:

Untuk setiap perintah `PRINT`, cetak isi list sesuai kondisi saat itu.

---

### ⚙️ Constraints:

- `1 <= N <= 1000`
    
- `-10^9 <= x <= 10^9`
    
- `0 <= i < panjang list saat itu`
    

---

### 💡 Contoh Input:

```
9
ADD_BACK 10
ADD_BACK 20
ADD_BACK 30
REPLACE 1 25
REMOVE_AT 0
ADD_FRONT 5
PRINT
REMOVE_AT 10
PRINT
```

### 💬 Contoh Output:

```
5 25 30
5 25 30
```

# Jawabanku
## Jawaban yang masih kurang
Jawaban ini masih memiliki banyak kekurangan, namun ini disebabkan karena terdapat fungsi tertentu yang belum aku tahu, tapi yang namanya belajar, pasti berawal dari ketidaktahuan. Berikut adalah jawaban yang masih kurang, namun masih mampu menjawab tantangan dengan benar:

```cpp
#include<iostream>
#include<list>
#include<sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    list<int> dalist;
    int n; cin >> n;
    while(n--){
        list<int>::iterator itr = dalist.begin();
        string s; getline(cin >> ws, s);
        stringstream ss(s);
        string cmd; int val, sec;
        ss >> cmd;

        if(cmd=="ADD_BACK"){
            ss >> val;
            dalist.push_back(val);
        } else if (cmd == "ADD_FRONT"){
            ss >> val;
            dalist.push_front(val);
        } else if (cmd=="REMOVE_AT") {
            ss >> val; val--;
            if(val > dalist.size()) continue;
            for(int i=0; i<val; i++) itr++;
            dalist.erase(itr);
        } else if (cmd=="REPLACE"){
            ss >> val >> sec;
            val--;
            if(val > dalist.size()) continue;
            for(int i=0; i<val; i++) itr++;
            dalist.insert(itr, sec);
            dalist.erase(itr);
        } else if (cmd=="PRINT") {
            for(const auto&x: dalist) {
                cout << x << " ";
            }
        }
    }
    return 0;
}
```

## Jawaban yang sudah optimal
Berikut adalah jawaban yang sudah optimal berdasarkan saran dari editorial:

```cpp
#include <iostream>
#include <list>
#include <sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    list<int> dalist;
    int n; cin >> n;
    while(n--) {
        string s; getline(cin >> ws, s);
        stringstream ss(s);
        string cmd;
        ss >> cmd;

        if (cmd == "ADD_BACK") {
            int val; ss >> val;
            dalist.push_back(val);
        } else if (cmd == "ADD_FRONT") {
            int val; ss >> val;
            dalist.push_front(val);
        } else if (cmd == "REMOVE_AT") {
            int idx; ss >> idx;
            idx--;
            if (idx < 0 || idx >= dalist.size()) continue;
            auto it = dalist.begin();
            advance(it, idx);
            dalist.erase(it);
        } else if (cmd == "REPLACE") {
            int idx, val; ss >> idx >> val;
            idx--;
            if (idx < 0 || idx >= dalist.size()) continue;
            auto it = dalist.begin();
            advance(it, idx);
            *it = val;
        } else if (cmd == "PRINT") {
            if (dalist.empty()) {
                cout << "EMPTY\n";
            } else {
                for (auto x : dalist) cout << x << " ";
                cout << "\n";
            }
        }
    }
    return 0;
}
```

# Editorial | Kesalahan Jawaban Pertama
Keren! Kamu sudah hampir benar — tapi ada beberapa detail yang perlu diperbaiki agar sesuai dengan **deskripsi soal dan hasil output yang tepat**.

Berikut ulasan lengkapnya 👇

---

### ✅ Yang Sudah Bagus:

- Gunakan `std::list` dengan benar
    
- Menangani semua perintah (`ADD_BACK`, `ADD_FRONT`, `REPLACE`, `REMOVE_AT`, `PRINT`)
    
- Gunakan `stringstream` dan `getline(cin >> ws, s)` secara rapi
    
- Iterasi manual pakai iterator sesuai untuk `std::list`
    

---

### 🔍 Yang Perlu Diperbaiki:

#### 1. Index off-by-one

Kamu mengurangi `val--` agar jadi 0-based (bagus), **tapi** kondisi `if(val > dalist.size()) continue;` salah.

```cpp
if(val > dalist.size()) continue;
```

Ini harusnya:

```cpp
if(val < 0 || val >= dalist.size()) continue;
```

Karena indeks valid adalah `0` sampai `size - 1`, bukan `<= size`.

---

#### 2. Iterator `itr` dipakai sebelum waktunya

Kamu mendeklarasikan:

```cpp
list<int>::iterator itr = dalist.begin();
```

di awal loop. Itu aman, tapi **jangan langsung `erase(itr)` setelah `insert(itr, val)`** karena posisi `itr` jadi **invalid setelah insert**.

### Solusi untuk `REPLACE`:

```cpp
auto it = dalist.begin();
advance(it, val); // lebih ringkas daripada loop manual

*it = sec;
```

Ganti nilainya langsung, tidak perlu `insert` + `erase`. Ini lebih efisien dan aman.

---

#### 3. Output PRINT tidak mencetak "EMPTY"

Kalau list kosong, kamu tidak mencetak `"EMPTY"` seperti diminta di soal.

Perbaiki bagian ini:

```cpp
else if (cmd=="PRINT") {
    if (dalist.empty()) {
        cout << "EMPTY\n";
    } else {
        for(const auto&x: dalist) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
```

# Editorial | Penjelasan 
Siap! Ini dia penjelasan **per blok kode** dari versi program perbaikanku, lengkap dengan penjelasan _mengapa_ ditulis seperti itu. Tujuannya supaya kamu bisa belajar dari kesalahan kecil sebelumnya dan memahami praktik terbaik penggunaan `std::list`.

---

## 🔍 Penjelasan Per Blok Kode

### 🔹 1. Header dan Optimasi I/O

```cpp
#include <iostream>
#include <list>
#include <sstream>
using namespace std;
```

**Penjelasan:**

- `#include <iostream>` → Untuk input/output (cin, cout)
    
- `#include <list>` → Untuk menggunakan `std::list`
    
- `#include <sstream>` → Untuk memecah input satu baris menjadi kata-kata (pakai `stringstream`)
    
- `using namespace std;` → Supaya tidak perlu menulis `std::` berulang-ulang
    

---

### 🔹 2. Optimasi I/O dan Deklarasi List

```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

**Penjelasan:**

- Mempercepat proses input/output dengan menonaktifkan sinkronisasi `cin/cout` dengan `stdio`.
    
- `cin.tie(nullptr)` mencegah `cin` otomatis flush `cout`, membuat I/O lebih efisien.
    
- `list<int> dalist;` → Inisialisasi list kosong yang akan diisi perintah.
    

---

### 🔹 3. Membaca Banyak Perintah

```cpp
int n; cin >> n;
while(n--) {
    string s; getline(cin >> ws, s);
    stringstream ss(s);
    string cmd;
    ss >> cmd;
```

**Penjelasan:**

- `int n; cin >> n;` → Membaca jumlah perintah.
    
- `getline(cin >> ws, s);` → Membaca satu baris penuh, `ws` menghilangkan spasi sebelum teks agar getline tidak terlewat baris.
    
- `stringstream ss(s);` → Menguraikan isi baris menjadi kata-kata.
    
- `ss >> cmd;` → Ambil perintah utama dari baris (seperti `"ADD_BACK"`, `"REPLACE"`)
    

---

### 🔹 4. ADD_BACK dan ADD_FRONT

```cpp
if (cmd == "ADD_BACK") {
    int val; ss >> val;
    dalist.push_back(val);
} else if (cmd == "ADD_FRONT") {
    int val; ss >> val;
    dalist.push_front(val);
}
```

**Penjelasan:**

- Perintah `"ADD_BACK x"` dan `"ADD_FRONT x"` hanya perlu mengambil `x`, lalu menambahkan ke belakang atau depan `dalist`.
    

---

### 🔹 5. REMOVE_AT

```cpp
else if (cmd == "REMOVE_AT") {
    int idx; ss >> idx;
    idx--;
    if (idx < 0 || idx >= dalist.size()) continue;
    auto it = dalist.begin();
    advance(it, idx);
    dalist.erase(it);
}
```

**Penjelasan:**

- `idx--` → Karena input berupa angka 1-based, kita ubah ke 0-based.
    
- Validasi: `if (idx < 0 || idx >= dalist.size())` → Mencegah akses indeks tidak valid.
    
- `advance(it, idx);` → Menggeser iterator `it` sebanyak `idx` langkah dari awal list.
    
- `dalist.erase(it);` → Menghapus elemen pada posisi itu.
    

**Kenapa tidak pakai loop manual (`for`) seperti sebelumnya?**  
→ `advance(it, idx);` lebih ringkas dan efisien untuk STL iterator.

---

### 🔹 6. REPLACE

```cpp
else if (cmd == "REPLACE") {
    int idx, val; ss >> idx >> val;
    idx--;
    if (idx < 0 || idx >= dalist.size()) continue;
    auto it = dalist.begin();
    advance(it, idx);
    *it = val;
}
```

**Penjelasan:**

- Sama seperti `REMOVE_AT`, kita geser iterator ke indeks `idx`.
    
- Tapi alih-alih `insert` dan `erase`, kita langsung ganti nilainya: `*it = val;`
    

**Mengapa ini lebih baik?**  
→ Lebih efisien (1 operasi, bukan 2), dan tidak perlu khawatir iterator menjadi invalid karena `insert` + `erase`.

---

### 🔹 7. PRINT

```cpp
else if (cmd == "PRINT") {
    if (dalist.empty()) {
        cout << "EMPTY\n";
    } else {
        for (auto x : dalist) cout << x << " ";
        cout << "\n";
    }
}
```

**Penjelasan:**

- Jika list kosong, cetak `"EMPTY"` (sesuai spesifikasi soal).
    
- Kalau tidak, cetak semua elemen list dalam satu baris, dipisahkan spasi.
    

---

## 🧠 Kesalahan Awal yang Berhasil Kamu Atasi:

| Masalah Awal                                | Solusi                                             |
| ------------------------------------------- | -------------------------------------------------- |
| Cek indeks salah: `if(val > list.size())`   | Ganti dengan `if (val < 0 or val >= dalist.size()` |
| Ganti elemen dengan `insert + erase`        | Ganti dengan langsung `*it = val;`                 |
| Lupa cetak `EMPTY` jika list kosong         | Tambah `if (dalist.empty()) cout << "EMPTY"`       |
| Loop manual `for(int i=0; i<val; i++) it++` | Ganti dengan `advance(it, val)`                    |
