---
obsidianUIMode: preview
note_type: latihan
latihan: Menyalin Semua Entry dengan Nilai Tertentu ke Multimap Baru
sumber: chatgpt.com
tags:
  - data-structure
  - multimap
date_learned: 2025-06-22T23:09:00
---
---
# Soal 4: Menyalin Semua Entry dengan Nilai Tertentu ke Multimap Baru

**Deskripsi**  
Diberikan sebuah `multimap<string,int>` berisi pasangan `(nama, nilai)`. Buatlah program yang:

1. Membaca sebuah nilai target (misalnya `85`)
    
2. Menyalin semua entry dari multimap asal ke **multimap baru** **hanya jika** nilai (value)-nya **sama persis** dengan target
    
3. Menampilkan seluruh isi multimap baru (urut berdasarkan kunci seperti biasa)
    

---

**Spesifikasi Input**

1. Baris pertama berisi integer $N 1 \leq N \leq 10^5)$, jumlah pasangan.
    
2. $N$ baris berikutnya:
    
    ```
    name value
    ```
    
    - `name` adalah string tanpa spasi
        
    - `value` adalah integer $0 \le value \le 100$
        
3. Baris terakhir berisi satu bilangan bulat: nilai target.
    

---

**Spesifikasi Output**

- Jika tidak ada entry yang cocok, cetak:
    
    ```
    Tidak ada entry dengan nilai X
    ```
    
    (ganti `X` dengan nilai target)
    
- Jika ada, cetak semua pasangan `(nama, nilai)` dari multimap baru, satu per baris:
    
    ```
    nama1 nilai
    nama2 nilai
    ...
    ```
    

---

**Contoh 1**  
_Input:_

```
5
Alice 90
Bob 85
Alice 85
Charlie 70
Bob 88
85
```

_Output:_

```
Alice 85
Bob 85
```

---

**Contoh 2**  
_Input:_

```
3
Eka 70
Dina 80
Fiona 90
75
```

_Output:_

```
Tidak ada entry dengan nilai 75
```

---

Silakan langsung implementasikan kode C++-nya. Kalau sudah selesai, kirim untuk kita review!

## Jawabanku
Berikut adalah jawabanku untuk soal ini:

```cpp
#include<iostream>
#include<map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    multimap<string, int> input;
    multimap<string, int> rest;
    int n, x; string s;
    cin >> n;

    while(n--){
        cin >> s >> x;
        input.insert({s,x});
    }

    int t; cin >> t;
    for(const auto& [key, val]: input){
        if(val==t) rest.insert({key, val});
    }

    if(!rest.empty()){
        for(const auto& [key, val]: rest){
            cout << key << " " << val << "\n";
        }
    } else {
        cout << "Tidak ada entry dengan nilai " << t << "\n";
    }
    return 0;
}
```

# Editorial
Jawabanmu **sudah 100% benar dan rapi**.  
Tapi seperti biasa, berikut **editorial per blok kode** agar bisa langsung kamu pakai untuk dokumentasi atau laporan:

---

```cpp
#include <iostream>
#include <map>
using namespace std;
```

- Import header:
    
    - `<iostream>` untuk input/output
        
    - `<map>` untuk struktur `multimap`
        

---

```cpp
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
```

- Optimasi I/O untuk mempercepat `cin` dan `cout`.
    

---

```cpp
    multimap<string, int> input;
    multimap<string, int> rest;
```

- `input`: menyimpan semua data awal
    
- `rest`: menyimpan hasil filter (entry dengan nilai sesuai target)
    

---

```cpp
    int n, x;
    string s;
    cin >> n;
```

- `n`: jumlah entry yang akan dibaca
    
- `x`: sementara untuk menampung nilai
    
- `s`: sementara untuk menampung nama
    

---

```cpp
    while(n--) {
        cin >> s >> x;
        input.insert({s, x});
    }
```

- Membaca dan menyisipkan pasangan `(s, x)` ke dalam `input`.
    

---

```cpp
    int t; 
    cin >> t;
```

- Membaca **nilai target** (`t`) yang akan dicari.
    

---

```cpp
    for(const auto& [key, val] : input) {
        if (val == t) {
            rest.insert({key, val});
        }
    }
```

- Iterasi seluruh `input`
    
- Jika `val == t`, salin entry ke `rest`
    

---

```cpp
    if (!rest.empty()) {
        for (const auto& [key, val] : rest) {
            cout << key << " " << val << "\n";
        }
    } else {
        cout << "Tidak ada entry dengan nilai " << t << "\n";
    }
```

- Jika hasil (`rest`) tidak kosong, tampilkan semuanya dalam urutan leksikografis (otomatis oleh `multimap`)
    
- Jika kosong, tampilkan pesan sesuai soal.
    

---

### Catatan

- Kompleksitas waktu:
    
    - Membaca dan menyisipkan `N` data: O(N log N)
        
    - Iterasi filter: O(N)
        
    - Menyisipkan ke multimap `rest`: O(K log K) di mana K adalah jumlah entry yang cocok
        

---

Keren, sekarang lanjut ke **Soal nomor 5**?