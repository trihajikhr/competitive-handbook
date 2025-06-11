---
obsidianUIMode: preview
note_type: latihan
latihan: Mengubah Desimal Menjadi Bit
sumber: codeforces
tags:
  - bits
  - bitwise
---
---
# Mengubah Desimal Menjadi Bit
Jika kita memiliki angka desimal, dan ingin merubahnya kedalam representasi biner, kita bisa menggunakan beberapa pendekatan dalam bahasa C++. Berikut diataranya:

## 🧠 Konversi Bilangan Desimal ke Biner (Manual Tanpa `bitset`)

```cpp
#include<iostream>
using namespace std;

string to_biner(int x){
    if(x == 0) return "0"; // handle kasus khusus
    string s;
    while(x > 0){
        s += (x % 2 ? '1' : '0');
        x /= 2;
    }

    reverse(s.begin(), s.end());
    return s;
}

int main() {
    int x; cin >> x;
    cout << to_biner(x) << "\n";
    return 0;
}
```

### 📄 Deskripsi Masalah

Konversi bilangan bulat positif dari bentuk desimal ke bentuk biner dalam C++ secara manual, **tanpa menggunakan** `bitset`. Kode ini berguna untuk memahami bagaimana representasi biner bekerja secara logika dasar.

---

### 💡 Penjelasan Kode

```cpp
#include<iostream>
using namespace std;
```

Import library standar `iostream` untuk input/output. Namespace `std` digunakan agar tidak perlu mengetik `std::` terus-menerus.

---

#### Fungsi `to_biner(int x)`

```cpp
string to_biner(int x){
    if(x == 0) return "0"; // handle kasus khusus
```

- Jika `x == 0`, langsung kembalikan string `"0"` karena representasi biner dari 0 adalah 0. Tanpa ini, akan menghasilkan string kosong.
    

```cpp
    string s;
```

- Inisialisasi string kosong untuk menampung hasil konversi biner.
    

```cpp
    while(x > 0){
        s += (x % 2 ? '1' : '0');
        x /= 2;
    }
```

- Lakukan perulangan selama `x > 0`:
    
    - `x % 2` akan menghasilkan `1` jika bit terakhir adalah 1, dan `0` jika tidak.
        
    - Karakter `'1'` atau `'0'` ditambahkan ke akhir string `s`.
        
    - `x /= 2` membagi `x` dengan 2, memindahkan proses ke bit berikutnya.
        

> Karena penambahan karakter dilakukan dari belakang (LSB ke MSB), maka hasil akhir perlu dibalik.

```cpp
    reverse(s.begin(), s.end());
    return s;
}
```

- String `s` dibalik menggunakan `reverse()` agar menjadi urutan yang benar (MSB → LSB).
    
- Fungsi mengembalikan string hasil konversi.
    

---

#### Fungsi `main()`

```cpp
int main() {
    int x; cin >> x;
    cout << to_biner(x) << "\n";
    return 0;
}
```

- Menerima input `x` dari user.
    
- Memanggil fungsi `to_biner(x)` dan mencetak hasilnya ke layar.
    

---

### 🧪 Contoh Input dan Output

**Input:**

```
13
```

**Output:**

```
1101
```

**Penjelasan:**  
13 = 8 + 4 + 0 + 1 → dalam biner: `1101`.

---

### 🔎 Catatan Tambahan

- Fungsi ini hanya menangani bilangan bulat **non-negatif**. Untuk angka negatif atau format tetap (misalnya 8-bit), gunakan `bitset`.
    
- Untuk pemrosesan jumlah besar atau pengujian bit satu per satu, pendekatan ini memberi pemahaman lebih mendalam dibanding `bitset`.
    

---

### 📌 Kesimpulan

Kode `to_biner()` ini adalah cara manual dan efisien untuk mengonversi bilangan desimal ke bentuk biner, ideal untuk pembelajaran dasar bitwise dan debugging secara manual dalam kompetisi atau latihan C++.

---
## 🧠 Konversi Desimal ke Biner dengan `bitset` di C++

```cpp
#include<iostream>
#include<bitset>
using namespace std;

int main() {
    int x; cin >> x;
    cout << bitset<8>(x) << "\n";
    return 0;
}
```

### 📄 Deskripsi Singkat

`bitset` adalah template class di C++ yang memungkinkan kita **menyimpan dan memanipulasi bit secara langsung** seperti array boolean tetap. Ini sangat efisien dan sering digunakan dalam Competitive Programming untuk operasi bit level.

---

### 💻 Contoh Kode

```cpp
#include<iostream>
#include<bitset>
using namespace std;

int main() {
    int x; cin >> x;
    cout << bitset<8>(x) << "\n";
    return 0;
}
```

---

### 🧩 Penjelasan Per Baris

```cpp
#include<iostream>
```

- Untuk input/output dasar seperti `cin` dan `cout`.
    

```cpp
#include<bitset>
```

- Mengimpor class template `bitset` dari STL (Standard Template Library).
    

```cpp
int x; cin >> x;
```

- Menerima input bilangan bulat dari user.
    

```cpp
cout << bitset<8>(x) << "\n";
```

- Membuat sebuah objek `bitset` sepanjang **8 bit** (dari `bitset<8>`) berdasarkan nilai `x`.
    
- Output yang dicetak adalah representasi **biner sepanjang 8 bit**, termasuk **nol di depan (leading zeros)** jika perlu.
    

---

### 🧪 Contoh Input dan Output

**Input:**

```
5
```

**Output:**

```
00000101
```

**Penjelasan:**  
5 dalam biner adalah `101`, dan karena kita memakai `bitset<8>`, maka akan ditambahkan nol di depan menjadi 8 digit: `00000101`.

---

### 🔧 Format Umum Penggunaan

```cpp
bitset<N> b(x);
```

- `N` adalah panjang bit yang ingin kamu tampilkan. Nilai `N` ini bisa diisi dengan angka lain, semisal 16, 32, 64, 10, 11, 54, dan seterusnya.
    
- `x` adalah bilangan bulat (integer) yang dikonversi menjadi bitset.
    

Kamu juga bisa menyimpan `bitset` ke variabel:

```cpp
bitset<8> b(x);
cout << b[0]; // mencetak bit paling kanan (LSB)
```

---

### 🛠️ Kelebihan `bitset`

- Cepat dan efisien untuk menyimpan bit.
    
- Mendukung operasi logika bitwise seperti `&`, `|`, `^`, `~`, `<<`, `>>`.
    
- Dapat digunakan untuk **representasi subset** (misalnya dalam DP Bitmask).
    
- Bisa digunakan dalam array dan map seperti tipe data biasa.
    

---

### ⚠️ Catatan Penting

- `bitset<8>(x)` akan **memotong** nilai `x` jika lebih dari 8 bit.
    
    - Misalnya `x = 300`, maka `bitset<8>(300)` → hanya menampilkan **8 bit terakhir**.
        
- Jika ingin menampilkan 32 bit atau 64 bit, gunakan:
    

```cpp
bitset<32>(x); // untuk int
bitset<64>(x); // untuk long long
```

---

### 📌 Kesimpulan

`bitset` sangat cocok untuk:

- Menampilkan bilangan dalam bentuk biner dengan cepat.
    
- Melakukan operasi logika tingkat bit (bitwise logic).
    
- Digunakan dalam teknik **bitmasking** di Competitive Programming.
    
