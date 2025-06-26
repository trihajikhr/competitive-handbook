---
obsidianUIMode: preview
note_type: latihan
latihan: Menampilkan Semua Nilai untuk Semua Nama
sumber: chatgpt.com
tags:
  - data-structure
  - multimap
date_learned: 2025-06-23T14:44:00
---
---
# Soal 8: Menampilkan Semua Nilai untuk Semua Nama (Berurutan)

**Deskripsi**  
Diberikan sebuah `multimap<string, int>` yang menyimpan beberapa nama dan nilai (bisa duplikat nama). Tugasmu adalah menampilkan semua nama **unik** dalam urutan leksikografis, lalu untuk setiap nama, tampilkan semua nilai yang dimilikinya dalam **urutan naik**.

---

**Spesifikasi Input**

1. Baris pertama: integer N — jumlah entry
    
2. N baris berikutnya:
    
    ```
    name value
    ```
    

---

**Spesifikasi Output**

- Untuk setiap nama unik:
    
    - Satu baris:
        
        ```
        name: value1 value2 ...
        ```
        
    - Nilai-nilai ditampilkan dalam urutan menaik
        
    - Nama-nama juga ditampilkan secara urut leksikografis
        

---

**Contoh 1**  
_Input:_

```
6
Alice 90
Bob 85
Alice 95
Charlie 70
Bob 88
Alice 91
```

_Output:_

```
Alice: 90 91 95
Bob: 85 88
Charlie: 70
```

---

**Contoh 2**  
_Input:_

```
4
Zed 100
Anna 75
Zed 80
Anna 75
```

_Output:_

```
Anna: 75 75
Zed: 80 100
```

---

Silakan implementasikan kode C++-nya, lalu kirim agar bisa kita review bersama.

## Jawabanku
Berikut adalah jawabanku untuk program ini:

```cpp
#include<iostream>
#include<map>
#include<iterator>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    multimap<string, int> mulmap;
    map<string, vector<int>> rest;
    int n, x; string s;
    cin >> n;
    
    while(n--){
        cin >> s >> x;
        mulmap.insert({s,x});
    }

    for(const auto& [key, val]: mulmap){
        rest[key].push_back(val);
    }

    for(auto& [key, val]: rest){
        sort(val.begin(), val.end());
    }

    for(const auto& [key, val]: rest){
        cout << key << ": ";

        for(const auto& x: val){
            cout << x << " ";
        }

        cout << "\n";
    }
    return 0;
}
```

# Editorial
✅ Jawabanmu **benar, bersih, dan optimal!**  
Kamu berhasil:

- Menyimpan data input ke dalam `multimap`
    
- Mengelompokkan nilai berdasarkan nama ke dalam `map<string, vector<int>>`
    
- Mengurutkan nilai-nilai untuk setiap nama
    
- Menampilkan hasil dengan format yang benar
    

---

Berikut **editorial per blok kode** yang siap kamu salin ke laporan atau catatan pembahasan soalmu:

---

```cpp
#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;
```

- Header:
    
    - `<map>`: untuk `multimap` dan `map`
        
    - `<vector>`: untuk menyimpan list nilai per nama
        
    - `<algorithm>`: untuk `sort()`
        

---

```cpp
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
```

- Optimasi `cin`/`cout` agar cepat, sesuai praktik competitive programming.
    

---

```cpp
    multimap<string, int> mulmap;
    map<string, vector<int>> rest;
    int n, x;
    string s;
    cin >> n;
```

- `mulmap`: untuk menyimpan data mentah input
    
- `rest`: menyimpan kumpulan nilai untuk setiap nama (dikelompokkan)
    
- `n`: jumlah entry
    
- `s`, `x`: variabel bantu nama dan nilai
    

---

```cpp
    while(n--) {
        cin >> s >> x;
        mulmap.insert({s, x});
    }
```

- Membaca data input dan menyisipkannya ke `mulmap`
    

---

```cpp
    for (const auto& [key, val] : mulmap) {
        rest[key].push_back(val);
    }
```

- Mengelompokkan nilai berdasarkan `key` (nama)
    
- Hasilnya: `rest["Alice"] = {90, 95, 91}` dan sebagainya
    

---

```cpp
    for (auto& [key, val] : rest) {
        sort(val.begin(), val.end());
    }
```

- Mengurutkan semua nilai di setiap `vector<int>` agar nilai tampil naik
    

---

```cpp
    for (const auto& [key, val] : rest) {
        cout << key << ": ";
        for (const auto& x : val) {
            cout << x << " ";
        }
        cout << "\n";
    }
```

- Menampilkan semua nama (urut leksikografis otomatis oleh `map`)
    
- Diikuti nilai-nilai yang sudah diurutkan
    

---

### Kompleksitas

- Input: $O(n \log n)$ karena `multimap`
    
- Pengelompokan: $O(n)$
    
- Sorting nilai tiap nama: total $O(n \log k)$
    
- Output: $O(n)$
    

---

Siap lanjut ke **Soal 9**? Atau ada bagian dari soal ini yang mau kamu optimalkan lebih lanjut?