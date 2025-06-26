---
obsidianUIMode: preview
note_type: latihan
latihan: Cari Jumlah Total Nilai untuk Nama Tertentu
sumber: chatgpt.com
tags:
  - data-structure
  - multimap
date_learned: 2025-06-23T15:05:00
---
---
# Soal 9: Cari Jumlah Total Nilai untuk Nama Tertentu

**Deskripsi**  
Diberikan sebuah `multimap<string, int>` berisi beberapa entry `(nama, nilai)`. Lalu diberikan sebuah nama. Tugasmu adalah menghitung jumlah seluruh nilai yang berasosiasi dengan nama tersebut dan menampilkannya.  

Jika nama tidak ditemukan, tampilkan pesan khusus.

---

**Spesifikasi Input**

1. Baris pertama: integer N — jumlah entry
    
2. N baris berikutnya:
    
    ```
    name value
    ```
    
3. Baris terakhir: sebuah string `target_name`
    

---

**Spesifikasi Output**

- Jika `target_name` ada dalam `multimap`, tampilkan:
    
    ```
    Total nilai untuk <target_name>: <jumlah>
    ```
    
- Jika tidak ada entry dengan nama tersebut, tampilkan:
    
    ```
    Tidak ditemukan data untuk <target_name>
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
Alice 91
Alice
```

_Output:_

```
Total nilai untuk Alice: 276
```

---

**Contoh 2**  
_Input:_

```
4
X 50
Y 60
Z 70
A 80
B
```

_Output:_

```
Tidak ditemukan data untuk B
```

---

Langsung kerjakan dalam C++, kirim setelah selesai, kita bahas bareng!

## Jawabanku
Berikut adalah jawabanku untuk kasus ini:

```cpp
#include<iostream>
#include<map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    multimap<string, int> mulmap;
    int n,x; string s;
    cin >> n;

    while(n--){
        cin >> s >> x;
        mulmap.insert({s,x});
    }

    string target; cin >> target;
    if(mulmap.find(target) != mulmap.end()){
        auto range = mulmap.equal_range(target);

        int sum=0;
        for(auto it = range.first; it != range.second; it++){
            sum+=it->second;
        }

        cout << "Total nilai untuk " << target << ": " << sum << "\n";
    } else {
        cout << "Tidak ditemukan data untuk " << target << "\n";
    }
    return 0;
}
```

# Editorial
✅ Jawaban kamu **sudah 100% benar dan ideal**!  
Kamu menggunakan `equal_range()` untuk menjangkau semua entri dengan key tertentu, dan ini sangat tepat untuk `multimap`.

---

Berikut **editorial per blok kode**, siap kamu salin ke pembahasan soal:

---

```cpp
#include <iostream>
#include <map>
using namespace std;
```

- Header:
    
    - `<map>`: untuk struktur `multimap`
        
    - `<iostream>`: I/O dasar
        

---

```cpp
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
```

- Optimasi I/O agar `cin` dan `cout` lebih cepat
    

---

```cpp
    multimap<string, int> mulmap;
    int n, x;
    string s;
    cin >> n;
```

- `mulmap`: menyimpan semua pasangan nama-nilai
    
- `n`: jumlah entry
    
- `s`, `x`: variabel bantu input nama dan nilai
    

---

```cpp
    while(n--) {
        cin >> s >> x;
        mulmap.insert({s, x});
    }
```

- Memasukkan seluruh data ke dalam `mulmap`
    

---

```cpp
    string target;
    cin >> target;
```

- Membaca `target`, yaitu nama yang ingin dicari jumlah total nilainya
    

---

```cpp
    if (mulmap.find(target) != mulmap.end()) {
        auto range = mulmap.equal_range(target);

        int sum = 0;
        for (auto it = range.first; it != range.second; it++) {
            sum += it->second;
        }

        cout << "Total nilai untuk " << target << ": " << sum << "\n";
```

- Jika `target` ditemukan:
    
    - Gunakan `equal_range` untuk mendapatkan rentang entri dengan key `target`
        
    - Hitung semua nilainya dalam loop
        
    - Cetak total nilai
        

---

```cpp
    } else {
        cout << "Tidak ditemukan data untuk " << target << "\n";
    }
```

- Jika `target` tidak ditemukan, tampilkan pesan sesuai spesifikasi
    

---

### Kompleksitas Waktu

- Penyisipan `n` entry ke `multimap`: $O(n \log n)$
    
- Pencarian dan penjumlahan entry untuk key: $O(k)$, dengan `k` = jumlah kemunculan nama target
    

---

Siap untuk **Soal 10** sekaligus soal terakhir dari rangkaian dasar `multimap` ini?