---
obsidianUIMode: preview
note_type: latihan
latihan: Hapus Entri
sumber: Google.com, AI
tags:
  - data-structure
  - unordered_map
date_learned: 2025-06-17T06:46:00
---
---

Berikut **Soal 15** untuk memperkenalkan cara **menghapus entri berdasarkan kondisi** pada `std::unordered_map` menggunakan **`std::erase_if`** (C++20):

---
# Soal 15 – Hapus Entri Berdasarkan Nilai dengan `erase_if`

Diberikan sebuah peta `unordered_map<string, int>` yang berisi nama karyawan (string) dan jumlah **jam lembur** mereka (int). Kamu perlu **menghapus semua entri** karyawan yang **jam lemburnya kurang dari ambang** tertentu.

### Deskripsi

1. Baca dua bilangan bulat:
    
    - **_n_** (1 ≤ _n_ ≤ 1000): jumlah entri.
        
    - **_T_** (0 ≤ _T_ ≤ 10 000): ambang minimal jam lembur.
        
2. Baca _n_ baris, setiap baris “_nama jam_” (misal `Andi 5`).
    
3. Gunakan **`std::erase_if`** untuk menghapus semua pasangan `(nama → jam)` di mana `jam < T`.
    
4. Kumpulkan key yang tersisa, urutkan secara leksikografis, lalu cetak:
    
    - Baris pertama: satu bilangan, jumlah entri yang tersisa (`map.size()`).
        
    - Baris selanjutnya: tiap “_nama jam_” sesuai urutan.
        

### Contoh

#### Masukan

```
5 8
Andi 10
Budi 7
Citra 12
Dewi 5
Eko 9
```

#### Proses

- Ambang T = 8 → hapus Budi (7) dan Dewi (5).
    

#### Keluaran

```
3
Andi 10
Citra 12
Eko 9
```

---

**Tugasmu**

- Implementasi C++:
    
    1. Baca `n` dan `T`.
        
    2. Bangun `unordered_map<string,int> mp`.
        
    3. Panggil `std::erase_if(mp, [&](auto &p){ return p.second < T; });`.
        
    4. Kumpulkan key, `sort()`, dan cetak sesuai format.
        
- Sertakan **penjelasan singkat** mengapa `erase_if` lebih elegan/efisien (hint: satu traversal, tanpa manual loop + `.erase()` terpisah).
    

Kerjakan soal ini dulu, lalu beri tahu aku ketika sudah siap untuk soal berikutnya! 😊
## Jawabanku
Beriku adalah jawaban yang benar:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<unordered_map>
#include<utility>     // untuk std::pair
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t; cin >> n >> t;
    unordered_map<string, int> worker;
    vector<string> order;

    if(n > 10000){
        worker.max_load_factor(0.5f);
        worker.reserve(n * 2);
    } else worker.reserve(n);
    order.reserve(n);

    string s;
    while(n--){
        getline(cin >> ws, s);
        stringstream ss(s);
        string name; int no;
        ss >> name >> no;
        worker.emplace(name, no);
    }

    // Hapus elemen yang tidak memenuhi ambang batas
    erase_if(worker, [&](auto &p){ return p.second < t; });

    // Ambil semua key yang tersisa
    for(const auto& [k, v] : worker){
        order.push_back(k);
    }

    sort(order.begin(), order.end());
    for(const auto& x : order){
        cout << x << " " << worker[x] << "\n";
    }

    return 0;
}
```

# Editorial
Berikut **editorial singkat** untuk solusi Soal 15:

---

## 🧾 Editorial Soal 15 – Hapus Entri Berdasarkan Nilai dengan `erase_if`

### 📌 Tujuan:

Menghapus semua entri dari `unordered_map<string, int>` di mana nilai (jam lembur) lebih kecil dari ambang batas `t`.

---

### 🧩 Langkah-langkah Solusi:

1. **Baca input**
    
    - `n`: jumlah karyawan
        
    - `t`: ambang batas jam lembur minimum
        
    - Lalu baca `n` baris berisi `nama` dan `jumlah jam`, dan simpan ke `unordered_map<string, int> worker`.
        
2. **Menghapus data yang tidak valid dengan `erase_if`**
    
    - Sintaks:
        
        ```cpp
        erase_if(worker, [&](auto &p){ return p.second < t; });
        ```
        
    - Fungsi ini akan **traverse** map dan menghapus setiap entri yang memenuhi kondisi (`jam < t`).
        
    
    ✅ **Kelebihan:**
    
    - Tidak perlu `for` + `erase()` manual yang rentan bug.
        
    - Lebih pendek, bersih, dan aman dari invalidated iterator.
        
3. **Kumpulkan key dan urutkan**
    
    - Iterasi ulang map yang tersisa, simpan key ke dalam vector `order`.
        
    - Urutkan dengan `sort(order.begin(), order.end());`.
        
4. **Output**
    
    - Cetak jumlah entri setelah penghapusan: `worker.size()`.
        
    - Lalu cetak semua pasangan key–value sesuai urutan `order`.
        

---

### 💡 Catatan Penting

- `erase_if` tersedia di C++20. Jika kompiler belum mendukungnya, kamu perlu menggunakan loop manual (dengan `for (auto it = ...; )`).
    
- `unordered_map` tidak menyimpan urutan, jadi untuk mencetak dalam urutan tertentu (misalnya leksikografis), kamu perlu menyimpan dan mengurutkan key-nya sendiri.
    

---

Kalau sudah siap, mari kita lanjut ke **Soal 16** — terakhir dari rangkaian ini! 🚀