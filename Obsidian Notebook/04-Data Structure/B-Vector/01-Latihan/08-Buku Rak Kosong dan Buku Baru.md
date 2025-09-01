---
obsidianUIMode: preview
note_type: latihan
latihan: Buku Rak Kosong dan Buku Baru
sumber: Google.com, AI
tags:
  - vector
  - data-structure
date_learned: 2025-06-14T21:45:00
---
---
# Buku Rak Kosong dan Buku Baru
Siap! Kita lanjut ke **Soal 8** (revisi nomor), dengan fokus pada fungsi `resize()` dan pengisian default di `vector`.

---

## 🧪 Soal 8: Buku Rak Kosong dan Buku Baru

Sebuah perpustakaan memiliki rak buku berkapasitas `N` slot. Semula semua slot **kosong** dan akan diisi kemudian.

1. Baca `N` (1 ≤ N ≤ 100).
    
2. Buat `vector<string> rak`, dan isi dengan string `"KOSONG"` di semua slot menggunakan `resize(...)`.
    
3. Baca `M` (0 ≤ M ≤ N): jumlah buku yang akan dimasukkan.
    
4. Lalu baca `M` pasang data:
    
    - `pos` (0-based index), dan
        
    - `judul` (string tanpa spasi), yaitu buku yang akan ditaruh di posisi `pos`.  
        Update `rak[pos] = judul;`
        
5. Cetak isi rak dari indeks 0 hingga N-1, satu per baris.
    

---

### Contoh Input:

```
5
2
1 Algoritma
3 StrukturData
```

### Contoh Output:

```
KOSONG
Algoritma
KOSONG
StrukturData
KOSONG
```

---

### Tujuan Soal:

- Melatih penggunaan:
    
    - `vector::resize(size, default_value)`
        
    - Akses dan update elemen via indeks
        

---

Kalau sudah, kirimkan kodenya untuk dicek — dan nanti kita lanjut ke **Soal 9**, yang akan lebih interaktif dan melibatkan kombinasi fungsi! 🚀
## Jawabanku
Versi pertama:

```cpp
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n; cin >> n;

    vector<string> rak;
    rak.resize(n, "KOSONG");  

    int m; cin >> m;
    while(m--){
        int idx; string s;
        cin >> idx >> s;
        rak[idx - 1] = s;  
    }

    cout << "\n";
    for(const auto& slot : rak){
        cout << slot << "\n";
    }

    return 0;
}
```

Versi langsung inisialisasi vector sebanyak N dan semuanya bernilai "KOSONG":

```cpp
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<string> rak(n, "KOSONG");  
    
    int m; cin >> m;
    while(m--){
        int idx; string s;
        cin >> idx >> s;
        rak[idx-1] = s;  
    }

    for(const auto& slot : rak){
        cout << slot << "\n";
    }

    return 0;
}
```

## Editorial

### 🎯 Tujuan

- Melatih penggunaan `vector::resize(n, default_value)`
    
- Melatih pemahaman indeks (0-based vs 1-based)
    
- Melatih manipulasi nilai elemen `vector` menggunakan indeks langsung
    

---

### ✅ Penjelasan Kode Baris per Baris

```cpp
#include<iostream>
#include<vector>
using namespace std;
```

Mengimpor pustaka input/output dan `vector` dari STL.

---

```cpp
int n; cin >> n;
```

Membaca jumlah slot rak buku (`n`).

---

```cpp
vector<string> rak;
rak.resize(n, "KOSONG");
```

### 🧩 Penjelasan Penting:

- Kita membuat vector kosong (`rak`)
    
- Lalu mengatur ukurannya menjadi `n` menggunakan:
    
    ```cpp
    rak.resize(n, "KOSONG");
    ```
    
- Fungsi ini mengisi semua elemen dengan string `"KOSONG"`
    
- Setara dengan:
    
    ```cpp
    for (int i = 0; i < n; i++) rak[i] = "KOSONG";
    ```
    
    tapi lebih ringkas dan efisien
    

---

```cpp
int m; cin >> m;
```

Membaca jumlah buku yang ingin dimasukkan (`m`).

---

```cpp
while(m--){
    int idx; string s;
    cin >> idx >> s;
    rak[idx - 1] = s;
}
```

- Membaca pasangan `idx` (nomor rak) dan `s` (judul buku)
    
- Karena input menggunakan **1-based index**, kita konversi ke **0-based** dengan:
    
    ```cpp
    rak[idx - 1] = s;
    ```
    

---

```cpp
for(const auto& slot : rak){
    cout << slot << "\n";
}
```

- Mencetak isi seluruh rak dari awal hingga akhir
    
- Menggunakan loop berbasis-range (`for-each`)
    
- Satu elemen per baris, sesuai permintaan soal
    

---

### 🧮 Kompleksitas

|Operasi|Kompleksitas|
|---|---|
|resize|O(n)|
|loop input m|O(m)|
|loop output n|O(n)|
|**Total**|O(n + m)|

---

### 🧪 Contoh Uji Coba

**Input:**

```
5
2
1 Algoritma
3 StrukturData
```

**Output:**

```
Algoritma
KOSONG
StrukturData
KOSONG
KOSONG
```

---

### 💡 Catatan Tambahan

|Fungsi STL|Penjelasan Singkat|
|---|---|
|`resize(n, val)`|Menambah atau memotong vector ke ukuran `n`, isi default `val`|
|`rak[idx - 1] = s`|Update elemen vector pakai indeks (perlu hati-hati soal 0/1-based)|
|`for (auto x : v)`|Cara bersih dan modern untuk mencetak semua isi vector|

---

Kalau sudah paham, kita siap lanjut ke **Soal 9** yang akan memperkenalkan kamu pada `insert()`, `erase()`, dan `size()` — cocok untuk latihan seperti _editor sederhana_. Mau lanjut sekarang? 💪