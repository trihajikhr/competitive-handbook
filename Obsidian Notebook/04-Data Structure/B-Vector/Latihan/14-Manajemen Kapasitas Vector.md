---
obsidianUIMode: preview
note_type: latihan
latihan: Manajemen Kapasitas Vector
sumber: Google.com, AI
tags:
  - vector
  - data-structure
date_learned: 2025-06-14T21:46:00
---
---
# Manajemen Kapasitas Vector
## 🧩 Soal 14: Manajemen Kapasitas Vector

### 📥 Input

Baris pertama berisi integer **`Q`** (1 ≤ Q ≤ 10⁵): jumlah perintah.  
Kemudian ada **Q** baris, tiap baris salah satu perintah:

1. `APPEND x`  
    – Tambahkan integer `x` ke akhir `vector` (pakai `push_back`).
    
2. `RESERVE k`  
    – Panggil `vec.reserve(k)`.
    
3. `SHRINK`  
    – Panggil `vec.shrink_to_fit()`.
    
4. `PRINT_SIZE`  
    – Cetak `vec.size()`.
    
5. `PRINT_CAPACITY`  
    – Cetak `vec.capacity()`.
    
6. `CLEAR`  
    – Panggil `vec.clear()`.
    

### 📤 Output

Untuk setiap `PRINT_SIZE` atau `PRINT_CAPACITY`, cetak satu angka di baris baru sesuai hasil pemanggilan fungsi.

---

### 🎯 Tujuan & Fungsi yang Dipraktikkan

|Fungsi|Kegunaan|
|---|---|
|`push_back(x)`|Menambah elemen di akhir|
|`size()`|Mendapatkan jumlah elemen saat ini|
|`capacity()`|Mendapatkan kapasitas internal vector|
|`reserve(k)`|Menjamin kapasitas minimal `k`|
|`shrink_to_fit()`|Menciutkan kapasitas agar pas dengan size()|
|`clear()`|Mengosongkan semua elemen|

---

### 💡 Contoh

**Input:**

```
8
APPEND 1
PRINT_SIZE
PRINT_CAPACITY
APPEND 2
RESERVE 10
PRINT_CAPACITY
SHRINK
PRINT_CAPACITY
```

**Output:**

```
1
[awal kapasitas setelah satu push_back, misal 1 atau 2]
2
10
2
```

> _(Catatan: implementasimu mungkin memperlihatkan doubling rule pada push_back, lalu reserve, lalu shrink_to_fit)_

---

Coba implementasikan parser-nya dan eksekusi perintah sesuai spesifikasi. Nanti kita bahas hasilnya dan lihat pola `capacity()` saat `push_back` dan setelah `reserve`/`shrink_to_fit`. 🚀

## Jawabanku
Berikut adalah kode jawabanku untuk menjawab soal ini:


```cpp
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> task;
    int n; cin >> n;

    while(n--){
        string s;
        getline(cin >> ws, s);

        stringstream ss(s);
        string cmd;
        ss >> cmd;

        if(cmd=="APPEND"){
            string x;
            ss >> x;
            task.push_back(x);
        } else if(cmd=="RESERVE"){
            int k;
            ss >> k;
            task.reserve(k);
        } else if(cmd=="SHRINK"){
            task.shrink_to_fit();
        } else if(cmd=="PRINT_SIZE"){
            cout << task.size() << "\n";
        } else if(cmd=="PRINT_CAPACITY"){
            cout << task.capacity() << "\n";
        } else if(cmd=="CLEAR"){
            task.clear();
        }
    }
    return 0;
}
```

# Editorial
Berikut **editorial lengkap** untuk Soal 14: Manajemen Kapasitas `vector`.

---

## 📋 Ringkasan Soal

Kamu membuat sebuah `vector<string> task` (di soal asli int, tapi penggunaannya sama) dan mengeksekusi perintah-perintah untuk mempelajari bagaimana **ukuran** (`size`) dan **kapasitas** (`capacity`) internal berubah:

1. **APPEND x** → `push_back(x)`
    
2. **RESERVE k** → `reserve(k)`
    
3. **SHRINK** → `shrink_to_fit()`
    
4. **PRINT_SIZE** → cetak `size()`
    
5. **PRINT_CAPACITY** → cetak `capacity()`
    
6. **CLEAR** → `clear()`
    

---

## 🔍 Penjelasan Fungsi

|Fungsi|Apa yang Dilakukan|
|---|---|
|`push_back(x)`|Menambah elemen di akhir; jika `size() == capacity()`, kapasitas akan **doubled** (umumnya).|
|`reserve(k)`|Memastikan `capacity() >= k`; jika `k > current_capacity`, alokasi ulang ke `k`.|
|`shrink_to_fit()`|Mengusulkan (non‑binding) agar kapasitas disusutkan menjadi `size()`.|
|`size()`|Mengembalikan jumlah elemen yang sedang disimpan.|
|`capacity()`|Mengembalikan jumlah total ruang yang sudah dialokasikan (≥ `size()`).|
|`clear()`|Menghapus semua elemen, menjadikan `size() = 0`, tapi **tidak** mengubah `capacity()`.|

---

## 📈 Ilustrasi Pola `capacity()`

1. **Awal**: kosong → `size() = 0`, `capacity() = 0` (implementasi bisa berbeda).
    
2. **push_back pertama**: `size() = 1` → kapasitas biasanya menjadi 1 (atau 2).
    
3. **push_back selanjutnya**: jika mencapai `capacity()`, kapasitas diperluas, biasanya **menggandakan** (1 → 2 → 4 → 8 → ...).
    
4. **RESERVE 10**: memaksa `capacity() = 10` jika sebelumnya < 10.
    
5. **SHRINK**: setelah beberapa `push_back`, misal `size() = 2`, `capacity` disusutkan menjadi `2`.
    
6. **CLEAR**: `size()` menjadi 0, tapi `capacity()` tetap sama kecuali kamu memanggil `shrink_to_fit()` lagi.
    

---

## ⚙️ Contoh Alur Eksekusi

Misalnya input:

```
8
APPEND a
PRINT_SIZE
PRINT_CAPACITY
APPEND b
RESERVE 10
PRINT_CAPACITY
SHRINK
PRINT_CAPACITY
```

- Setelah `APPEND a`:
    
    - `size() = 1`
        
    - `capacity()` kemungkinan `1` atau `2`
        
- `PRINT_SIZE` → `1`
    
- `PRINT_CAPACITY` → misal `2`
    
- `APPEND b`:
    
    - `size() = 2`
        
    - jika `capacity()` masih `2`, tidak berubah
        
- `RESERVE 10`:
    
    - `capacity()` menjadi `10`
        
- `PRINT_CAPACITY` → `10`
    
- `SHRINK`:
    
    - `capacity()` disesorong ke `size() = 2`
        
- `PRINT_CAPACITY` → `2`
    

Catatan: **implementasi spesifik doubling rule** bisa berbeda antar pustaka, jadi kapasitas awal dan peningkatannya bisa 1→2→4… atau 0→1→2→4… tapi pola dasarnya tetap menggandakan.

---

## 💡 Tips & Praktik Baik

- Gunakan `reserve(n)` sebelum serangkaian `push_back` besar untuk **menghindari alokasi ulang berulang**, meningkatkan performa.
    
- Setelah operasi yang mengurangi elemen secara signifikan, `shrink_to_fit()` membantu menghemat memori.
    
- Ingat: `clear()` **tidak** mengubah `capacity()`. Jika kamu perlu melepaskan memori, wajib memanggil `shrink_to_fit()`.
    

---

Dengan memahami fungsi–fungsi ini, kamu bisa menulis kode yang **lebih efisien** dan **hemat memori** saat menggunakan `vector`. Semoga bermanfaat! 🚀