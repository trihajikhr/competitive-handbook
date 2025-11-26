---
obsidianUIMode: preview
note_type: latihan
latihan: Simulasi Daftar Putar
sumber: chatgpt.com
tags:
  - list
  - data-structure
date_learned: 2025-07-09T15:35:00
---
---
Great! 🔥 Kita masuk ke Soal 9 — Soal Terakhir untuk STL `std::list`, yang akan menguji seluruh kemampuan manipulasi `list`: penyisipan di tengah, penghapusan, dan rotasi dinamis.

# Soal 9: Simulasi Daftar Putar (Playlist Simulator)

### 📝 Deskripsi:

Kamu sedang membuat simulasi sistem daftar putar lagu. Daftar ini dikelola dengan `std::list`, dan kamu harus memproses berbagai perintah untuk menavigasi dan mengubah daftar lagu.

### 📥 Input:

Baris pertama: satu bilangan bulat **N** — jumlah perintah  
N baris berikutnya berisi salah satu perintah:

- `ADD x` — Tambahkan lagu bernomor `x` ke **akhir** daftar
    
- `INSERT_AFTER y x` — Sisipkan lagu `x` setelah lagu `y` (jika `y` ada)
    
- `REMOVE x` — Hapus lagu `x` dari daftar (jika ada)
    
- `NEXT` — Geser pointer ke lagu berikutnya
    
- `PREV` — Geser pointer ke lagu sebelumnya
    
- `CURRENT` — Cetak lagu yang sedang diputar
    
- `PRINT` — Cetak seluruh daftar dari depan ke belakang
    

### 🧠 Aturan Navigasi:

- Posisi saat ini diawali di **lagu pertama**
    
- Jika `NEXT` melebihi akhir, tetap di akhir
    
- Jika `PREV` di awal, tetap di awal
    
- Jika daftar kosong, `CURRENT` harus cetak `EMPTY`

### 📤 Output:

Untuk setiap `CURRENT` → cetak nomor lagunya  
Untuk setiap `PRINT` → cetak seluruh daftar, atau `EMPTY` jika kosong
### ⚙️ Batasan:

- `1 <= N <= 1000`
    
- Nilai lagu: bilangan bulat unik `-10^6 ≤ x ≤ 10^6`


### 💡 Contoh Input:

```
9
ADD 10
ADD 20
CURRENT
NEXT
CURRENT
INSERT_AFTER 10 15
PRINT
REMOVE 15
PRINT
```

### 💬 Output:

```
10
20
10 15 20
10 20
```

# Jawabanku
Berikut adalah jawabanku untuk menyelesaikan tantangan ini, yang sudah diperbaiki berdasarkan saran dari editorial:

```cpp
#include<iostream>
#include<sstream>
#include<list>
#include<iterator>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    list<int> dalist;
    list<int>::iterator curr = dalist.end(); // awalnya invalid
    int n; cin >> n;

    while (n--) {
        string s; getline(cin >> ws, s);
        stringstream ss(s);
        string cmd; int y, z;
        ss >> cmd;

        if (cmd == "ADD") {
            ss >> y;
            dalist.push_back(y);
            if (dalist.size() == 1) curr = dalist.begin(); 
            // atur pointer saat pertama kali add
        }

        else if (cmd == "INSERT_AFTER") {
            ss >> y >> z;
            for (auto it = dalist.begin(); it != dalist.end(); ++it) {
                if (*it == y) {
                    ++it;
                    dalist.insert(it, z);
                    break;
                }
            }
        }

        else if (cmd == "REMOVE") {
            ss >> y;
            for (auto it = dalist.begin(); it != dalist.end(); ++it) {
                if (*it == y) {
                    if (curr == it) {
                        // ubah curr jika sedang menunjuk ke elemen yang dihapus
                        curr = dalist.erase(it);
                        if (curr == dalist.end() && !dalist.empty()) {
                            curr = prev(dalist.end());
                        }
                    } else {
                        dalist.erase(it);
                    }
                    break;
                }
            }
        }

        else if (cmd == "NEXT") {
            if (!dalist.empty()) {
                auto temp = curr;
                ++temp;
                if (temp != dalist.end()) curr = temp;
            }
        }

        else if (cmd == "PREV") {
            if (curr != dalist.begin()) {
                --curr;
            }
        }

        else if (cmd == "CURRENT") {
            if (!dalist.empty()) cout << *curr << '\n';
            else cout << "EMPTY\n";
        }

        else if (cmd == "PRINT") {
            if (dalist.empty()) cout << "EMPTY\n";
            else {
                for (const auto& x : dalist) cout << x << ' ';
                cout << '\n';
            }
        }
    }

    return 0;
}
```

# Editorial
Perhatikan kode berikut, ini adalah contoh kodeku yang salah, dan alasan kenapa salah:

```cpp
#include<iostream>
#include<sstream>
#include<list>
#include<iterator>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    list<int> dalist;
    list<int> ::iterator itr;
    list<int> ::iterator curr = dalist.begin();
    int n; cin >> n;
    while(n--){
        string s; getline(cin >> ws, s);
        stringstream ss(s);
        string cmd; int y, z;
        ss >> cmd;

        if(cmd == "ADD"){
            ss >> y;
            dalist.push_back(y);
        } else if(cmd == "INSERT_AFTER") {
            ss >> y >> z;
            for(itr=dalist.begin(); itr!=dalist.end(); itr++){
                if(*itr == y) {
                    dalist.insert(++itr, z);
                    break;
                }
            }
        } else if (cmd == "REMOVE") {
            ss >> y;
            auto it = find(dalist.begin(), dalist.end(), y);
            if(it!= dalist.end()) {
                int idx = static_cast<int>(distance(dalist.begin(), it));
                itr = dalist.begin();
                advance(itr, idx);
                dalist.erase(itr);
            }
        } 
        else if (cmd == "NEXT") {
            if(++curr == dalist.end()) curr--;
            else curr++;
        } else if (cmd=="PREV") {
            if(curr == dalist.begin()) continue;
            else curr--;
        } else if (cmd == "CURRENT") {
            if(!dalist.empty()) cout << *curr << endl;
            else cout << "EMPTY\n";
        } else if (cmd == "PRINT") {
            if(!dalist.empty()){
                for(const auto&x:dalist) {
                    cout << x << " ";
                } cout << endl;
            } else cout << "EMPTY\n";
        }
    }
    return 0;
}
```

## 🔍 Masalah Utama dalam Kode

### 1. 🧨 `curr` tidak di-set saat `ADD` pertama kali

Jika kamu menambahkan elemen pertama (`ADD 10`), `curr` masih menunjuk ke `dalist.begin()` sebelum elemen itu ditambahkan, sehingga bisa invalid / undefined.

✅ Solusi: Saat `dalist.size() == 1` setelah `ADD`, set `curr = dalist.begin();`
### 2. 🧨 `NEXT` kamu melangkah dua kali!

```cpp
if(++curr == dalist.end()) curr--;
else curr++;
```

❌ `++curr` sudah maju, lalu kamu maju **lagi**: `curr++`, artinya dua langkah.

✅ Solusi yang benar:

```cpp
if (curr != dalist.end()) {
    auto temp = curr;
    ++temp;
    if (temp != dalist.end()) curr = temp;
}
```

### 3. ❌ `REMOVE` tidak cek apakah `curr` menunjuk ke elemen yang dihapus

Jika kamu hapus elemen yang sedang ditunjuk oleh `curr`, maka `curr` akan jadi **dangling iterator** → **runtime error** jika kamu pakai lagi.

✅ Solusi:

- Kalau `curr == it`, ubah ke `curr = dalist.begin();`
    
- Tapi jika list jadi kosong, atur `curr = dalist.end();`

|Bagian|Status|Catatan|
|---|---|---|
|Penambahan, penghapusan data|✅|Sudah benar|
|Navigasi `curr` (NEXT/PREV)|🔧|Diperbaiki supaya stabil, tidak lompat dua langkah|
|Penanganan `curr` saat REMOVE|✅|Sudah aman dari dangling iterator|
|Output (CURRENT/PRINT)|✅|Sesuai format dan syarat kosong|

---
<br/><br/><br/>

# Editorial per Blok Kode Program

## 📦 Kode Lengkap Referensi (Sudah Diperbaiki)

```cpp
#include<iostream>
#include<sstream>
#include<list>
#include<iterator>
#include<algorithm>
using namespace std;
```

### 🔹 Header

- `iostream` → untuk input/output
    
- `sstream` → parsing string input dengan `stringstream`
    
- `list` → struktur data `std::list`
    
- `iterator`, `algorithm` → untuk manipulasi iterator (e.g., `prev`, `advance`, `find`)
    

---

```cpp
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
```

### 🔹 Setup I/O Efisien

- Mempercepat proses `cin` / `cout` (jika jumlah perintah besar)
    

---

```cpp
    list<int> dalist;
    list<int>::iterator curr = dalist.end(); // awalnya tidak menunjuk ke elemen manapun
    int n; cin >> n;
```

### 🔹 Inisialisasi Struktur

- `dalist`: list lagu
    
- `curr`: penunjuk ke lagu yang sedang diputar
    
    - Awalnya di-`end()` (invalid) karena list masih kosong
        

---

```cpp
    while (n--) {
        string s; getline(cin >> ws, s);
        stringstream ss(s);
        string cmd; int y, z;
        ss >> cmd;
```

### 🔹 Loop Perintah

- Membaca satu baris perintah
    
- Gunakan `stringstream` untuk parsing
    
- `cmd` bisa berupa `ADD`, `NEXT`, `CURRENT`, dst.
    

---

```cpp
        if (cmd == "ADD") {
            ss >> y;
            dalist.push_back(y);
            if (dalist.size() == 1) curr = dalist.begin(); // atur pointer saat list pertama kali diisi
        }
```

### 🔹 Perintah `ADD`

- Tambahkan lagu `y` ke akhir list
    
- Jika itu **elemen pertama**, set `curr` ke awal (karena sebelumnya `end()`)
    

---

```cpp
        else if (cmd == "INSERT_AFTER") {
            ss >> y >> z;
            for (auto it = dalist.begin(); it != dalist.end(); ++it) {
                if (*it == y) {
                    ++it;
                    dalist.insert(it, z);
                    break;
                }
            }
        }
```

### 🔹 Perintah `INSERT_AFTER`

- Cari elemen `y`
    
- Sisipkan `z` **setelah** `y` dengan `insert(++it, z)`
    

---

```cpp
        else if (cmd == "REMOVE") {
            ss >> y;
            for (auto it = dalist.begin(); it != dalist.end(); ++it) {
                if (*it == y) {
                    if (curr == it) {
                        curr = dalist.erase(it);
                        if (curr == dalist.end() && !dalist.empty())
                            curr = prev(dalist.end());
                    } else {
                        dalist.erase(it);
                    }
                    break;
                }
            }
        }
```

### 🔹 Perintah `REMOVE`

- Cari dan hapus elemen `y`
    
- Jika `curr` menunjuk ke elemen yang dihapus:
    
    - Pindahkan ke elemen berikutnya (`erase()` mengembalikan iterator berikutnya)
        
    - Jika sudah di `end()` tapi list belum kosong, geser ke `prev(end())`
        

---

```cpp
        else if (cmd == "NEXT") {
            if (!dalist.empty()) {
                auto temp = curr;
                ++temp;
                if (temp != dalist.end()) curr = temp;
            }
        }
```

### 🔹 Perintah `NEXT`

- Geser `curr` ke kanan jika belum di akhir
    
- Gunakan `temp` dulu supaya tidak geser langsung dan "lewat batas"
    

---

```cpp
        else if (cmd == "PREV") {
            if (curr != dalist.begin()) {
                --curr;
            }
        }
```

### 🔹 Perintah `PREV`

- Mundur satu langkah kalau `curr` belum di awal list
    

---

```cpp
        else if (cmd == "CURRENT") {
            if (!dalist.empty()) cout << *curr << '\n';
            else cout << "EMPTY\n";
        }
```

### 🔹 Perintah `CURRENT`

- Cetak lagu saat ini (`*curr`)
    
- Kalau list kosong, tampilkan `"EMPTY"`
    

---

```cpp
        else if (cmd == "PRINT") {
            if (dalist.empty()) cout << "EMPTY\n";
            else {
                for (const auto& x : dalist) cout << x << ' ';
                cout << '\n';
            }
        }
```

### 🔹 Perintah `PRINT`

- Cetak semua isi list dari depan ke belakang
    
- Jika kosong, tampilkan `"EMPTY"`
    

---

```cpp
    }
    return 0;
}
```

### 🔹 Penutup

- Program selesai
    

---

## 🧪 Contoh Eksekusi

Input:

```
9
ADD 10
ADD 20
CURRENT
NEXT
CURRENT
INSERT_AFTER 10 15
PRINT
REMOVE 15
PRINT
```

Output:

```
10
20
10 15 20
10 20
```

✅ Semua sesuai!

---

## 🏁 Kesimpulan

|Fitur|Status|Catatan|
|---|---|---|
|Navigasi dengan iterator|✅|Sudah aman dan presisi|
|Penanganan saat list kosong|✅|Tidak error, responsif dengan `"EMPTY"`|
|Insert dan remove fleksibel|✅|Bisa di mana saja dan stabil|
|Struktur kode rapi dan efisien|✅|Sudah optimal untuk STL dan mudah diperluas|
