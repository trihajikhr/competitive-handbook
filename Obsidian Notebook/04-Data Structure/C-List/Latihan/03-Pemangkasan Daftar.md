---
obsidianUIMode: preview
note_type: latihan
latihan: Pemangkasan Daftar
sumber: chatgpt.com
tags:
  - list
  - data-structure
date_learned: 2025-07-09T11:49:00
---
---
Mantap! Sekarang kita masuk ke Soal 3, tingkat kesulitannya naik sedikit karena kita akan melibatkan traversal dari belakang dan menghapus banyak elemen sekaligus. Soal ini menguji pemahaman kamu tentang manipulasi `std::list` dan iterator dua arah.

---
# Soal 3: Pemangkasan Daftar

### 📝 Deskripsi:

Kamu mengelola sebuah daftar nilai yang terus bertambah. Karena ruang terbatas, kamu akan sesekali memangkas daftar ini, yaitu menghapus elemen dari belakang hingga tersisa sejumlah elemen tertentu saja.

Implementasikan semua perintah dan cetak isi list saat diminta.

---

### 📥 Input:

Baris pertama berisi bilangan bulat **N** – jumlah perintah.  
Setiap dari N baris berikutnya berisi salah satu dari perintah berikut:

- `"ADD x"` — Tambahkan `x` ke belakang list
    
- `"TRIM k"` — Pangkas list dari belakang sehingga hanya menyisakan `k` elemen pertama
    
- `"PRINT_FORWARD"` — Cetak isi list dari depan ke belakang
    
- `"PRINT_BACKWARD"` — Cetak isi list dari belakang ke depan
    

---

### 📤 Output:

Untuk setiap perintah `"PRINT_FORWARD"` atau `"PRINT_BACKWARD"`, cetak isi list dalam satu baris, dipisahkan spasi. Jika list kosong, cetak `EMPTY`.

---

### ⚙️ Batasan:

- `1 <= N <= 1000`
    
- `-10^9 <= x <= 10^9`
    
- `0 <= k <= panjang list saat itu`
    

---

### 💡 Contoh Input:

```
9
ADD 10
ADD 20
ADD 30
TRIM 2
PRINT_FORWARD
ADD 40
PRINT_BACKWARD
TRIM 0
PRINT_FORWARD
```

### 💬 Contoh Output:

```
10 20
40 20 10
EMPTY
```

# Jawabanku
Berikut adalah jawabanku yang sudah benar dan optimal:

```cpp
#include<iostream>
#include<list>
#include<sstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    list<int> dalist;
    int n; cin >> n;
    while(n--){
        string s; getline(cin >> ws, s);
        stringstream ss(s);
        string cmd; int val;
        ss >> cmd;

        if(cmd == "ADD"){
            ss >> val;
            dalist.push_back(val);
        } else if (cmd == "TRIM"){
            ss >> val;
            if(val >= dalist.size() || val<0){
                continue;
            } else if(val==0){
                dalist.clear();
                continue;
            }

            while(dalist.size() > val) dalist.pop_back();
        } else if (cmd == "PRINT_FORWARD"){
            if(dalist.empty()) {
                cout << "EMPTY\n";
                continue;
            }

            for(auto it=dalist.begin(); it != dalist.end(); it++){
                cout << *it << " ";
            } cout << endl;
        } else if(cmd == "PRINT_BACKWARD"){
            if(dalist.empty()) {
                cout << "EMPTY\n";
                continue;
            }
            
            for(auto it=dalist.rbegin(); it != dalist.rend(); it++){
                cout << *it << " ";
            } cout << endl;
        }
    }
    return 0;
}
```

# Editorial
💯 Sempurna!  
Kodenya **bersih, efisien, dan sesuai spesifikasi soal**. Kamu sudah menguasai penggunaan `std::list` dengan sangat baik, termasuk:

- `push_back` untuk penambahan,
    
- `pop_back` untuk pemangkasan,
    
- traversal dengan `begin()` dan `rbegin()` untuk cetak maju dan mundur,
    
- pengecekan kondisi kosong dengan `dalist.empty()`.
    

---

## 🔍 Review Singkat Per Blok:

### ✅ `TRIM`

```cpp
if(val >= dalist.size() || val < 0){
    continue;
}
```

Kamu menangani kondisi **di luar batas** (val terlalu besar atau negatif) — bagus.

```cpp
else if(val == 0){
    dalist.clear();
    continue;
}
```

Penanganan spesial untuk `TRIM 0` — hapus semua elemen. ✔️

```cpp
while(dalist.size() > val) dalist.pop_back();
```

Loop `pop_back` untuk memangkas — ini adalah cara terbaik dan paling sesuai dengan sifat `std::list`.

---

### ✅ `PRINT_FORWARD` dan `PRINT_BACKWARD`

```cpp
for(auto it = dalist.begin(); it != dalist.end(); it++) ...
for(auto it = dalist.rbegin(); it != dalist.rend(); it++) ...
```

Traversal normal dan reverse ✅  
Cocok banget untuk `std::list` karena iterator dua arah (bidirectional iterator).

---

### ✅ Output Format

```cpp
cout << "EMPTY\n";
```

Disiapkan dengan tepat untuk kondisi kosong. Kamu bahkan `continue;` agar tidak lanjut ke bawah — sangat rapi!

---

## ✅ Contoh Input Uji (Sesuai soal):

```
9
ADD 10
ADD 20
ADD 30
TRIM 2
PRINT_FORWARD
ADD 40
PRINT_BACKWARD
TRIM 0
PRINT_FORWARD
```

### ✅ Output:

```
10 20
40 20 10
EMPTY
```

✔️ Jawaban kamu sesuai sepenuhnya.
