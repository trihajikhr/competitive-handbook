---
obsidianUIMode: preview
note_type: latihan
latihan: Mencari Rata-Rata Tertinggi per Kunci
sumber: chatgpt.com
tags:
  - data-structure
  - multimap
date_learned: 2025-06-22T22:06:00
---
---
# Soal 3: Mencari Rata-Rata Tertinggi per Kunci

**Deskripsi**  
Diberikan $N$ pasangan $(\textit{name}, \textit{score})$ yang disimpan dalam sebuah `multimap<string,int>`. Tugasmu adalah menghitung rata-rata nilai untuk setiap nama, kemudian menentukan:

1. Nama yang memiliki **rata-rata nilai tertinggi**.
    
2. Jika ada lebih dari satu nama dengan rata-rata sama, pilih nama yang **paling kecil secara leksikografis**.
    

**Spesifikasi Input**

- Baris pertama: integer $N (1 \le N \le 10^5)$
    
- $N$ baris berikutnya:
    
    ```
    name score
    ```
    
    di mana `name` adalah string (tanpa spasi) dan `score` integer $[0,100]$.
    

**Spesifikasi Output**

- Satu baris:
    
    ```
    <best_name> <average>
    ```
    
    di mana `<best_name>` adalah nama dengan rata-rata tertinggi, dan `<average>` adalah rata-rata (dengan dua angka di belakang koma, dibulatkan ke bawah).
    

**Contoh 1**  
_Input:_

```
5
Alice 90
Bob 85
Alice 95
Charlie 70
Bob 88
```

_Proses:_

- Alice: (90 + 95) / 2 = 92.50
    
- Bob: (85 + 88) / 2 = 86.50
    
- Charlie: (70) / 1 = 70.00  
    _Output:_
    

```
Alice 92.50
```

**Contoh 2**  
_Input:_

```
6
Dina 80
Eka 75
Fiona 88
Eka 85
Dina 82
Fiona 82
```

_Proses:_

- Dina: (80+82)/2 = 81.00
    
- Eka: (75+85)/2 = 80.00
    
- Fiona: (88+82)/2 = 85.00  
    _Output:_
    

```
Fiona 85.00
```

**Contoh 3 (Tie Breaking)**  
_Input:_

```
4
Alpha 90
Bravo 90
Alpha 80
Bravo 80
```

_Proses:_

- Alpha: (90+80)/2 = 85.00
    
- Bravo: (90+80)/2 = 85.00  
    Tie → pilih “Alpha”  
    _Output:_
    

```
Alpha 85.00
```

---

Silakan implementasikan solusi sesuai spesifikasi di atas! Setelah selesai, kirim kode C++-mu agar kita bisa cek bersama.

## Jawabanku
### Jawaban yang masih bisa ditingkatkan
Berikut adalah jawabanku yang masih bisa ditingkatkan:

```cpp
#include<iostream>
#include<map>
#include<set>
#include<iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    multimap<string, int> mulmap;
    int n; cin >> n;

    string s; int x;
    while(n--){
        cin >> s >> x;
        mulmap.insert({s,x});
    }

    string win; float maks=0;
    for(const auto& [key, val]: mulmap){
        float avg=0, cnt=0;
        auto range = mulmap.equal_range(key);
        
        for(auto it = range.first; it != range.second; it++){
            avg+= it->second;
            cnt++;
        }

        avg/=cnt;
        
        if(avg>maks){
            win=key;
            maks=avg;
        } else if (avg==maks){
            win=(win < key? win : key);
        }
    }

    cout << win << " " << setprecision(2) << fixed << maks << "\n";
    return 0;
}
```

# Editorial
Kode kamu **sudah sangat dekat dengan benar**, tapi ada satu **bug penting**:  
loop-mu memproses **key yang sama berulang kali**, karena `for (const auto& [key, val] : mulmap)` akan mengunjungi semua entry, termasuk yang punya kunci duplikat.

Jadi misalnya:

```cpp
multimap<string, int> mm;
mm.insert({"Alice", 90});
mm.insert({"Alice", 95});
```

Maka:

- loop `for (const auto& [key, val] : mulmap)` akan **memproses "Alice" dua kali**.
    

---

### ✅ Solusi: Gunakan `set<string>` atau `map<string, pair<jumlah, total>>`

Kita akan gunakan `set<string>` agar setiap nama diproses **hanya sekali**.

Berikut versi **revisi** dari kode kamu:

```cpp
#include <iostream>
#include <map>
#include <set>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    multimap<string, int> mulmap;
    int n; cin >> n;

    string s; int x;
    while(n--) {
        cin >> s >> x;
        mulmap.insert({s, x});
    }

    set<string> sudah_diproses;
    string win;
    float maks = 0;

    for (const auto& [key, val] : mulmap) {
        if (sudah_diproses.count(key)) continue;
        sudah_diproses.insert(key);

        float total = 0, cnt = 0;
        auto range = mulmap.equal_range(key);
        for (auto it = range.first; it != range.second; ++it) {
            total += it->second;
            cnt++;
        }

        float avg = total / cnt;

        if (avg > maks) {
            maks = avg;
            win = key;
        } else if (avg == maks) {
            win = min(win, key);
        }
    }

    cout << win << " " << fixed << setprecision(2) << maks << "\n";
    return 0;
}
```

---

### 🔍 Penjelasan Perubahan

- **`set<string> sudah_diproses`**: mencegah menghitung rata-rata yang sama dua kali.
    
- Cek `if (sudah_diproses.count(key)) continue;`
    
- `win = min(win, key);` lebih aman dan lebih idiomatik daripada ternary manual.
    

---

Jika kamu ingin versi yang **lebih efisien** lagi, kita bisa pakai `map<string, pair<jumlah_nilai, total_nilai>>` sebagai preprocessing, tapi versi ini sudah sangat solid.

Kalau siap, kita lanjut ke **Soal 4**!