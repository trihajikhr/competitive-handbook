---
obsidianUIMode: preview
note_type: latihan
latihan: Temukan Entry dengan Nilai Minimum dan Maksimum
sumber: chatgpt.com
tags:
  - data-structure
  - multimap
date_learned: 2025-06-23T14:33:00
---
---
# Soal 7: Temukan Entry dengan Nilai Minimum dan Maksimum

**Deskripsi**  
Diberikan sebuah `multimap<string, int>` yang berisi pasangan `(nama, nilai)`. Tugasmu adalah mencari:

- Entry dengan **nilai minimum**
    
- Entry dengan **nilai maksimum**
    

Jika ada lebih dari satu entry dengan nilai minimum atau maksimum, ambil yang **nama-nya paling kecil secara leksikografis** untuk masing-masing kasus.

---

**Spesifikasi Input**

1. Baris pertama: integer N — jumlah entry
    
2. N baris berikutnya:
    
    ```
    name value
    ```
    

---

**Spesifikasi Output**  
Cetak dua baris:

1. Baris pertama untuk nilai minimum:
    
    ```
    min_name min_value
    ```
    
2. Baris kedua untuk nilai maksimum:
    
    ```
    max_name max_value
    ```
    

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
Dina 70
```

_Output:_

```
Charlie 70
Alice 95
```

_**Penjelasan**:_

- Nilai minimum adalah `70`, dimiliki Charlie dan Dina → ambil "Charlie"
    
- Nilai maksimum adalah `95`, hanya dimiliki Alice
    

---

**Contoh 2**  
_Input:_

```
4
X 50
Y 100
Z 100
A 50
```

_Output:_

```
A 50  
Y 100
```

---

Silakan implementasikan solusinya. Kirimkan kodenya ke sini setelah selesai!

## Jawabanku
Berikut adalah jawabanku untuk problem ini:

```cpp
#include<iostream>
#include<climits>
#include<map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    multimap<string, int> mulmap;
    int n, x; string s;
    cin >> n;

    int mins=INT_MAX;
    int maxs=INT_MIN;

    string mini, maxa;

    while(n--){
        cin >> s >> x;
        mulmap.insert({s,x});
    }

    for(const auto& [key, val]: mulmap){
        if(mins>val){
            mins=val;
            mini = key;
        } else if (mins==val){
            mini = (mini < key? mini : key);
        }

        if(maxs<val){
            maxs = val;
            maxa = key;
        } else if (maxs==val){
            maxa = (maxa < key? maxa : key);
        }
    }

    cout << mini << " " << mins << "\n";
    cout << maxa << " " << maxs << "\n";
    return 0;
}
```

# Editorial
✅ Jawabanmu **sudah benar, efisien, dan rapi**!  
Kamu sudah menangani dua hal penting:

- Mencari nilai minimum dan maksimum secara linear
    
- Tie-breaking (nilai sama) dengan memilih **nama terkecil secara leksikografis**
    

---

Berikut **editorial per blok kode** yang bisa langsung kamu salin ke pembahasan soalmu:

---

```cpp
#include <iostream>
#include <climits>
#include <map>
using namespace std;
```

- Header:
    
    - `<iostream>`: untuk input/output
        
    - `<climits>`: untuk `INT_MAX` dan `INT_MIN`
        
    - `<map>`: untuk `multimap`
        

---

```cpp
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
```

- Optimasi I/O agar proses baca/tulis cepat
    

---

```cpp
    multimap<string, int> mulmap;
    int n, x;
    string s;
    cin >> n;
```

- `mulmap`: untuk menyimpan semua pasangan `(nama, nilai)`
    
- `n`: jumlah entry yang akan dibaca
    
- `s`, `x`: variabel sementara untuk nama dan nilai
    

---

```cpp
    int mins = INT_MAX;
    int maxs = INT_MIN;
    string mini, maxa;
```

- `mins`, `maxs`: inisialisasi ke nilai ekstrem agar pengecekan minimum/maksimum berfungsi
    
- `mini`, `maxa`: nama untuk nilai minimum dan maksimum
    

---

```cpp
    while (n--) {
        cin >> s >> x;
        mulmap.insert({s, x});
    }
```

- Membaca seluruh data input ke dalam `multimap`
    

---

```cpp
    for (const auto& [key, val] : mulmap) {
        if (mins > val) {
            mins = val;
            mini = key;
        } else if (mins == val) {
            mini = (mini < key ? mini : key);
        }

        if (maxs < val) {
            maxs = val;
            maxa = key;
        } else if (maxs == val) {
            maxa = (maxa < key ? maxa : key);
        }
    }
```

- **Pengecekan minimum dan maksimum** secara langsung saat iterasi
    
- Jika ditemukan nilai baru yang lebih kecil atau lebih besar → update nilai dan nama
    
- Jika nilainya sama → pilih nama terkecil leksikografis
    

---

```cpp
    cout << mini << " " << mins << "\n";
    cout << maxa << " " << maxs << "\n";
    return 0;
}
```

- Output akhir sesuai spesifikasi
    
- Dua baris: satu untuk nilai minimum, satu untuk nilai maksimum
    

---

### Kompleksitas Waktu

- Input dan penyisipan: $O(n \log n)$
    
- Iterasi untuk cari min dan max: $O(n)$
    
- Total sangat efisien untuk batas $n \leq 10^5$
    

---

Keren, kamu udah sampai **soal 7 dari multimap**. Mau lanjut ke **soal 8** sekarang?