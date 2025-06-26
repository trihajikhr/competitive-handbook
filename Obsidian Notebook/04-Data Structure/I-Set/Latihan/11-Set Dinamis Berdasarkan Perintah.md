---
obsidianUIMode: preview
note_type: latihan
latihan: Set Dinamis Berdasarkan Perintah
sumber: chatgpt.com
tags:
  - data-structure
  - set
date_learned: 2025-06-20T22:59:00
---
---

🔥 Siap! Karena kamu sudah menaklukkan 10 latihan dasar `std::set`, sekarang kita masuk ke **Level Lanjutan** — 5 tantangan kompleks yang:

> ⚙️ Menggabungkan berbagai fungsi seperti `insert()`, `erase()`, `count()`, `contains()`, `swap()`, `clear()`, `upper_bound()`, `lower_bound()`, dll.  
> 💡 Dirancang untuk menguji **pemahaman mendalam dan strategi penggunaan** `std::set`.

---

# 🧩 Tantangan 11 — Set Dinamis Berdasarkan Perintah

**Deskripsi:**

Buatlah program yang:

- Membaca `n` perintah.
    
- Masing-masing perintah bisa berupa:
    
    ```
    ADD x       → Tambahkan elemen x ke dalam set
    DEL x       → Hapus elemen x dari set
    FIND x      → Cetak "ADA" jika x ada di set, "TIDAK ADA" jika tidak
    PRINT       → Cetak semua elemen dari terkecil ke terbesar
    CLEAR       → Kosongkan seluruh set
    SIZE        → Cetak ukuran set saat ini
    ```
    

---

### Input Format:

- Baris pertama: bilangan bulat `n` (1 ≤ n ≤ 1000)
    
- `n` baris berikutnya berisi salah satu perintah di atas
    

---

### Output Format:

- Output sesuai perintah (`FIND`, `PRINT`, `SIZE`)
    
- Untuk perintah `ADD`, `DEL`, `CLEAR`, cukup diproses (tidak mencetak apa pun)
    

---

### Contoh Input:

```
8
ADD 10
ADD 5
ADD 20
FIND 10
DEL 5
SIZE
PRINT
CLEAR
```

### Contoh Output:

```
ADA
2
10 20
```

---

🧠 **Petunjuk**:

- Gunakan `stringstream` atau `substr()` untuk memecah perintah dan nilai.
    
- Gunakan `daset.count(x)` atau `daset.contains(x)` untuk `FIND`.
    
- Gunakan `daset.erase(x)`, `daset.clear()`, `daset.insert(x)`, `daset.size()` dan traversal biasa.
    

---

⚡ Kirim solusimu untuk Tantangan 11 ini, dan kita lanjutkan sampai Tantangan 15! 💪

## Jawabanku
Berikut adalah jawabanku untuk problem ini:

```cpp
#include<iostream>
#include<set>
#include<sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    set<int> daset;

    while(n--){
        string s;
        getline(cin >> ws, s);

        stringstream ss(s);
        string cmd; int x; 
        ss >> cmd;

        if(cmd=="ADD"){
            ss >> x;
            daset.insert(x);
        } else if(cmd=="DEL"){
            ss >> x;
            daset.erase(x);
        } else if (cmd=="FIND"){
            ss >> x;
            if(daset.find(x) != daset.end()){
                cout << "ADA\n";
            } else cout << "TIDAK ADA\n";
        } else if(cmd=="PRINT"){
            for(const auto & x: daset){
                cout << x << " ";
            } cout << "\n";
        } else if (cmd=="CLEAR"){
            daset.clear();
        } else if(cmd=="SIZE"){
            cout << daset.size() << "\n";
        }
    }
    return 0;
}
```

# Editorial
🔥 Mantap! Solusimu untuk Tantangan 11 sempurna!

---

### ✅ Pemeriksaan Kode:

1. **Input Baris dan Parsing Perintah**
    
    ```cpp
    getline(cin >> ws, s);
    stringstream ss(s);
    ss >> cmd;
    ```
    
    ✔️ Ini membuat parser kamu fleksibel dan tahan terhadap spasi tambahan.
    
2. **Penanganan Perintah**:
    
    - `ADD x` → `insert(x)` ✔️
        
    - `DEL x` → `erase(x)` ✔️
        
    - `FIND x` → `find(x) != end()` ✔️
        
    - `PRINT` → loop set ✔️
        
    - `CLEAR` → `clear()` ✔️
        
    - `SIZE` → `size()` ✔️
        
3. **Responsif & Efisien**
    
    - Output hanya untuk perintah tertentu ✔️
        
    - Gunakan `set<int>` untuk memastikan elemen tetap unik dan terurut ✔️
        

---

### 🧪 Uji Contoh:

#### Input:

```
8
ADD 10
ADD 5
ADD 20
FIND 10
DEL 5
SIZE
PRINT
CLEAR
```

#### Output:

```
ADA
2
10 20
```

✅ **Output sesuai!**

---

### 🧠 Tambahan Catatan:

- Kalau kamu ingin lebih ekspresif di C++20+, bisa ganti:
    
    ```cpp
    daset.contains(x)
    ```
    
    sebagai pengganti:
    
    ```cpp
    daset.find(x) != daset.end()
    ```
    
