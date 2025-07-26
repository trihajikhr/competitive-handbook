---
obsidianUIMode: preview
note_type: latihan
latihan: Median Dinamis
sumber: chatgpt.com
tags:
  - list
  - data-structure
date_learned: 2025-07-09T14:01:00
---
---
🔥 Siap! Sekarang kita masuk ke Soal 7: Median Dinamis  

Ini adalah soal STL `list` yang menantang, karena kamu harus menambahkan elemen sambil menghitung nilai median secara real-time.

---
# Soal 7: Median Dinamis

### 📝 Deskripsi:

Kamu mengelola daftar bilangan bulat. Setiap kali kamu menambahkan elemen, kamu perlu mencetak **nilai median** saat ini.

Median didefinisikan sebagai:

- Jika jumlah elemen ganjil → ambil nilai **tengah**
    
- Jika genap → ambil **rata-rata dua nilai tengah** (dibulatkan ke bawah)
    

Kamu **hanya menggunakan `std::list`**, tidak boleh pakai `vector`, `multiset`, atau library balancing tree lainnya.

### 📥 Input:

Baris pertama berisi bilangan bulat **N** – jumlah perintah.  
Setiap baris berikutnya hanya:

- `"ADD x"` — Tambahkan `x` ke list dan **langsung cetak median**

### 📤 Output:

Untuk setiap `ADD`, cetak nilai median dari list saat itu di baris baru.
### ⚙️ Batasan:

- `1 <= N <= 1000`
    
- `-10^6 <= x <= 10^6`
    
- Cetak median sebagai bilangan bulat (dibulatkan ke bawah jika pecahan)

### 💡 Contoh Input:

```
5
ADD 1
ADD 3
ADD 2
ADD 4
ADD 5
```

### 💬 Contoh Output:

```
1
2
2
2
3
```

### 💡 Penjelasan:

- Setelah `1`: median = 1
    
- Setelah `1,3`: median = (1+3)/2 = 2
    
- Setelah `1,2,3`: median = 2
    
- Setelah `1,2,3,4`: median = (2+3)/2 = 2
    
- Setelah `1,2,3,4,5`: median = 3

## 🔧 Petunjuk Implementasi:

1. Gunakan `std::list<int>` untuk menyimpan data
    
2. Setelah `push_back`, **sort dulu**
    
3. Gunakan `advance()` untuk cari posisi median dengan iterator
    
4. Hitung sesuai genap/ganjil

# Jawabanku
Berikut adalah jawaban yang sudah optimal:

```cpp
#include<iostream>
#include<list>
#include<algorithm>
#include<iterator>
#include<sstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    list<int> dalist;
    int n; cin >> n;

    while(n--) {
        string s; getline(cin >> ws, s);
        stringstream ss(s);
        string cmd; int val;
        ss >> cmd >> val;

        dalist.push_back(val);
        dalist.sort();

        int sz = dalist.size();
        auto itr = dalist.begin();

        if(sz % 2 == 1){
            advance(itr, sz/2);
            cout << *itr << "\n";
        } else {
            advance(itr, sz/2 - 1);
            int a = *itr; itr++;
            int b = *itr;
            cout << (a + b)/2 << "\n";
        }
    }

    return 0;
}

```

# Editorial
Tentu! Berikut adalah **editorial per blok kode program** untuk versi final dari **Soal 7: Median Dinamis** menggunakan `std::list`.
## 🧩 Penjelasan Per Blok

---

### 🔹 Header & Namespace

```cpp
#include<iostream>
#include<list>
#include<algorithm>
#include<iterator>
#include<sstream>
using namespace std;
```

📌 **Fungsi:**

- `iostream`: untuk input/output
    
- `list`: tipe data `std::list`
    
- `algorithm`: untuk fungsi `sort()`
    
- `iterator`: untuk `advance()`
    
- `sstream`: untuk parsing string per baris (pakai `stringstream`)
    

---

### 🔹 Setup I/O Efisien

```cpp
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
```

📌 **Fungsi:**

- Mempercepat I/O di C++ (non-sinkron dengan `stdio`)
    
- Supaya `cin`/`cout` lebih cepat, terutama untuk jumlah perintah besar
    

---

### 🔹 Deklarasi List & Input Jumlah Perintah

```cpp
list<int> dalist;
int n; cin >> n;
```

📌 **Fungsi:**

- `dalist` adalah list utama tempat menyimpan semua angka
    
- `n` adalah jumlah baris perintah
    

---

### 🔹 Loop Utama untuk Setiap Perintah

```cpp
while(n--) {
    string s; getline(cin >> ws, s);
    stringstream ss(s);
    string cmd; int val;
    ss >> cmd >> val;
```

📌 **Fungsi:**

- `getline(cin >> ws, s)` membaca 1 baris perintah lengkap (mengabaikan spasi)
    
- `stringstream` untuk parsing `cmd` (harus `"ADD"`) dan `val` angkanya
    

---

### 🔹 Tambah Angka dan Urutkan List

```cpp
dalist.push_back(val);
dalist.sort();
```

📌 **Fungsi:**

- Tambahkan angka ke akhir list
    
- Lalu sort agar median bisa dihitung dengan benar (median butuh data urut)
    

---

### 🔹 Hitung Ukuran List dan Siapkan Iterator

```cpp
int sz = dalist.size();
auto itr = dalist.begin();
```

📌 **Fungsi:**

- `sz`: ukuran list saat ini
    
- `itr`: iterator awal untuk mulai maju ke posisi median
    

---

### 🔹 Cek Ganjil atau Genap, Cetak Median

#### 🔸 Jika Ganjil:

```cpp
if(sz % 2 == 1){
    advance(itr, sz/2);
    cout << *itr << "\n";
}
```

📌 **Fungsi:**

- Geser iterator ke tengah `sz/2`
    
- Cetak elemen itu sebagai median
    

---

#### 🔸 Jika Genap:

```cpp
else {
    advance(itr, sz/2 - 1);
    int a = *itr; itr++;
    int b = *itr;
    cout << (a + b)/2 << "\n";
}
```

📌 **Fungsi:**

- Geser iterator ke dua elemen tengah: `itr` di tengah pertama (`a`), `itr+1` di tengah kedua (`b`)
    
- Hitung rata-rata bulat (otomatis dibulatkan ke bawah), lalu cetak
    

---

### 🔹 Akhiri Program

```cpp
return 0;
```

📌 **Fungsi:**

- Mengembalikan status 0 dari `main`, menandakan program selesai sukses
    

---

## 🏁 Rangkuman

|Bagian|Fungsi|
|---|---|
|`list` + `sort()`|Menyimpan data dan mengurutkannya setiap `ADD`|
|`advance()`|Menemukan posisi median|
|`size() % 2`|Menentukan ganjil/genap|
|`median (a+b)/2`|Dibulatkan ke bawah otomatis karena `int`|
