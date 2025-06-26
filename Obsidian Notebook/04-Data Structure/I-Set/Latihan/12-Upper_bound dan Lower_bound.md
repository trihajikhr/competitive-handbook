---
obsidianUIMode: preview
note_type: latihan
latihan: Upper_bound dan Lower_bound
sumber: chatgpt.com
tags:
  - data-structure
  - set
date_learned: 2025-06-20T23:10:00
---
---
# 🧩 Tantangan 12 — Mencari Batas Terdekat dengan `lower_bound()` dan `upper_bound()`

**Fokus:** Gunakan `std::set::lower_bound()` dan `std::set::upper_bound()` untuk menemukan elemen yang lebih besar atau sama dari `x`, dan yang lebih besar dari `x`.

---

### Deskripsi Soal:

Buatlah program yang:

1. Membaca `n` bilangan bulat dan menyimpannya ke dalam `set`
    
2. Membaca satu bilangan `x`
    
3. Cetak:
    
    - Elemen terkecil dalam set yang **≥ x** (`lower_bound`)
        
    - Elemen terkecil dalam set yang **> x** (`upper_bound`)
        

Jika elemen tidak ditemukan (iterator mencapai `end()`), cetak `"Tidak ditemukan"`.

---

### Input Format:

- Baris pertama: bilangan bulat `n` (1 ≤ n ≤ 100)
    
- Baris kedua: `n` bilangan bulat
    
- Baris ketiga: bilangan bulat `x` (nilai target)
    

---

### Output Format:

- Baris pertama: hasil `lower_bound(x)` atau "Tidak ditemukan"
    
- Baris kedua: hasil `upper_bound(x)` atau "Tidak ditemukan"
    

---

### Contoh Input 1:

```
5
10 20 30 40 50
25
```

### Contoh Output 1:

```
30
30
```

### Contoh Input 2:

```
4
5 15 25 35
35
```

### Contoh Output 2:

```
35
Tidak ditemukan
```

---

🧠 **Petunjuk**:

- Gunakan:
    
    ```cpp
    auto it = s.lower_bound(x);
    auto it2 = s.upper_bound(x);
    ```
    
- Jangan lupa cek `if (it == s.end())`
    

---

Langsung saja kirimkan solusimu! Setelah ini, kita akan lanjut ke Tantangan 13 dengan kombinasi range erase dan traversal. 🚀

## Jawabanku
Berikut adalah jawabanku untuk menjawab tantangan ini:

```cpp
#include<iostream>
#include<set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    set<int> daset;

    for(int i=0, x; i<n; i++){
        cin >> x;
        daset.insert(x);
    }

    int x; cin >> x;

    auto lower = daset.lower_bound(x);
    auto upper = daset.upper_bound(x);

    if(lower != daset.end()) cout << *lower << "\n";
    else cout << "Tidak ditemukan\n";

    if(upper != daset.end()) cout << *upper << "\n";
    else cout << "Tidak ditemukan\n";
    return 0;
}
```

# Editorial
🔥 **Sempurna!** Kamu berhasil menyelesaikan **Tantangan 12** dengan sangat elegan dan akurat! 🎯

---

### ✅ Pemeriksaan Solusi:

1. **Penggunaan `lower_bound(x)`**:
    
    ```cpp
    auto lower = daset.lower_bound(x);
    ```
    
    ✔️ Mengembalikan iterator ke elemen **≥ x**
    
2. **Penggunaan `upper_bound(x)`**:
    
    ```cpp
    auto upper = daset.upper_bound(x);
    ```
    
    ✔️ Mengembalikan iterator ke elemen **> x**
    
3. **Penanganan jika iterator `end()`**:
    
    ```cpp
    if(lower != daset.end()) ...
    else cout << "Tidak ditemukan\n";
    ```
    
    ✔️ Aman dan sesuai spesifikasi soal.
    

---

### 🧪 Uji Coba:

#### Input:

```
4
5 15 25 35
35
```

#### Output:

```
35
Tidak ditemukan
```

✅ Tepat!

---

### 🧠 Catatan:

- `lower_bound(x)` sangat berguna dalam binary search berbasis set/map
    
- `upper_bound(x)` sangat cocok digunakan saat membuat interval atau menghitung jumlah elemen lebih besar dari `x`
    
- Kamu bisa gunakan `advance(it, k)` juga jika ingin melangkah ke elemen setelahnya
    
