---
obsidianUIMode: preview
note_type: latihan
latihan: Hitung Frekuensi Unik Nilai di Multimap
sumber: chatgpt.com
tags:
  - data-structure
  - multimap
date_learned: 2025-06-23T14:20:00
---
---
# Soal 6: Hitung Frekuensi Unik Nilai di Multimap

**Deskripsi**  
Diberikan sebuah `multimap<string, int>` berisi pasangan `(nama, nilai)`, tugasmu adalah menghitung **berapa kali tiap nilai muncul secara keseluruhan** (tanpa peduli siapa namanya).

Outputkan daftar nilai unik yang ada, dan berapa kali masing-masing nilai itu muncul.

---

**Spesifikasi Input**

1. Baris pertama: integer $N$ — jumlah entry
    
2. $N$ baris berikutnya:
    
    ```
    name value
    ```
    

---

**Spesifikasi Output**  
Cetak seluruh nilai unik dalam urutan menaik, beserta jumlah kemunculannya:

```
value1 frekuensi1
value2 frekuensi2
...
```

---

**Contoh 1**  
_Input:_

```
6
Alice 90
Bob 85
Alice 85
Charlie 70
Bob 90
Dina 85
```

_Output:_

```
70 1
85 3
90 2
```

---

**Contoh 2**  
_Input:_

```
3
A 100
B 100
C 100
```

_Output:_

```
100 3
```

---

Silakan langsung implementasikan solusinya! Setelah itu kita bahas bersama.

## Jawabanku
Berikut adalah jawabanku untuk problem ini:

```cpp
#include<iostream>
#include<map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;

    multimap<string, int> mulmap;
    map<int, int> rest;
    string s; int x, t;
    while(n--){
        cin >> s >> x;
        mulmap.insert({s,x});
    }

    for(auto it = mulmap.begin(); it != mulmap.end(); it++){
        rest[it->second]++;
    }

    for(const auto& [key, val]: rest){
        cout << key << " " << val << "\n";
    }

    return 0;
}
```

# Editorial
Jawabanmu **sudah tepat dan efisien**!  
Kamu memakai dua struktur:

- `multimap<string, int>` untuk input
    
- `map<int, int>` untuk menghitung frekuensi nilai—ini sangat cocok karena `map` otomatis mengurutkan nilai.
    

Berikut **editorial per blok kode** untuk dokumentasi atau laporanmu:

---

```cpp
#include <iostream>
#include <map>
using namespace std;
```

- Import header:
    
    - `<iostream>`: input/output
        
    - `<map>`: untuk `multimap` dan `map` biasa
        

---

```cpp
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
```

- Optimasi `cin`/`cout` agar lebih cepat—standar di kontes/program besar.
    

---

```cpp
    int n; 
    cin >> n;

    multimap<string, int> mulmap;
    map<int, int> rest;
    string s; 
    int x;
```

- `n`: jumlah entry
    
- `mulmap`: menyimpan data awal (nama → nilai)
    
- `rest`: menyimpan frekuensi nilai unik (nilai → jumlah kemunculan)
    
- `s`, `x`: untuk membaca input
    

---

```cpp
    while(n--) {
        cin >> s >> x;
        mulmap.insert({s, x});
    }
```

- Membaca input sebanyak `n` kali dan simpan ke dalam `mulmap`.
    

---

```cpp
    for (auto it = mulmap.begin(); it != mulmap.end(); it++) {
        rest[it->second]++;
    }
```

- Iterasi seluruh entry `mulmap`
    
- Ambil `it->second` (yaitu nilai), lalu naikkan penghitung `rest[val]`
    
- Hasil: setiap nilai yang muncul, dihitung berapa kali
    

---

```cpp
    for (const auto& [key, val] : rest) {
        cout << key << " " << val << "\n";
    }
```

- Cetak isi `rest` dengan urutan `key` (nilai) ascending (otomatis oleh `map`)
    

---

### Kompleksitas Waktu

- Penyisipan ke `multimap`: $O(n \log n)$
    
- Iterasi menghitung frekuensi: $O(n)$
    
- Penyisipan ke `map` (rest): $O(n \log k)$ dengan `k=#` nilai unik
    

---

Kamu siap banget buat lanjut ke **Soal nomor 7**?