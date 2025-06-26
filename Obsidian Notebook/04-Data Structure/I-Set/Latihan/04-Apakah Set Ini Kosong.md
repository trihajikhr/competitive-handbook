---
obsidianUIMode: preview
note_type: latihan
latihan: Apakah Set Ini Kosong
sumber: chatgpt.com
tags:
  - data-structure
  - set
date_learned: 2025-06-20T21:09:00
---
---
# 🧩 Latihan 4 — Apakah Set Ini Kosong?

**Fokus:** Mengenalkan fungsi `empty()` dan `size()` dari `std::set`

---

### Deskripsi Soal:

Buat program yang membaca `n` bilangan bulat dan menyimpannya ke dalam `set`. Setelah itu, program harus:

1. Menampilkan apakah set kosong atau tidak, menggunakan fungsi `empty()`.
    
2. Menampilkan berapa banyak elemen unik yang ada, menggunakan fungsi `size()`.
    

---

### Input Format:

- Baris pertama: bilangan bulat `n` (0 ≤ n ≤ 100)
    
- Baris kedua: `n` bilangan bulat, masing-masing antara 1 hingga 1000 (bisa kosong jika `n = 0`)
    

---

### Output Format:

- Baris pertama: `Set kosong` jika kosong, atau `Set tidak kosong` jika tidak kosong
    
- Baris kedua: `Jumlah elemen unik: X`, dengan `X` adalah jumlah elemen unik di dalam set
    

---

### Contoh Input 1:

```
0
```

### Contoh Output 1:

```
Set kosong
Jumlah elemen unik: 0
```

---

### Contoh Input 2:

```
6
10 20 20 30 10 40
```

### Contoh Output 2:

```
Set tidak kosong
Jumlah elemen unik: 4
```

---

🧠 **Petunjuk:**

- Gunakan `set.empty()` untuk mengecek apakah set kosong
    
- Gunakan `set.size()` untuk mendapatkan banyaknya elemen unik
    

---

Kamu boleh langsung kirimkan kode jawabanmu jika sudah selesai! Setelah itu kita bisa lanjut ke soal 5 yang mulai membahas traversal terbalik! 🚀

## Jawabanku
Berikut adalah jawabanku yang sudah benar:

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
        daset.emplace(x);
    }

    if(!daset.empty()) cout << "Set tidak kosong\n";
    else cout << "Set kosong\n";

    cout << "Jumlah elemen unik: " << daset.size() << "\n";
    return 0;
}
```

# Editorial
💯 **Sempurna!** Kode kamu **tepat, efisien, dan sesuai dengan semua kriteria soal**.

---

### ✅ Poin-poin yang Sudah Benar:

1. **Input dan Penyimpanan dengan `set`**
    
    ```cpp
    daset.emplace(x);
    ```
    
    → Efisien dan elegan, `emplace()` bekerja seperti `insert()` tapi bisa sedikit lebih cepat.
    
2. **Cek kekosongan `set`**
    
    ```cpp
    if (!daset.empty())
    ```
    
    → Pemakaian `empty()` sangat tepat. ✅
    
3. **Cek jumlah elemen unik**
    
    ```cpp
    daset.size()
    ```
    
    → Menampilkan jumlah elemen unik (karena `set` otomatis membuang duplikat). ✅
    
4. **Format output juga sesuai instruksi soal**:
    
    - `"Set tidak kosong"` atau `"Set kosong"`
        
    - `"Jumlah elemen unik: X"` ✅
        

---

### 📌 Contoh Output Cek:

#### Input:

```
6
1 2 2 3 3 3
```

#### Output:

```
Set tidak kosong
Jumlah elemen unik: 3
```

✅ **Sesuai harapan!**
