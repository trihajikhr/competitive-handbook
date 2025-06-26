---
obsidianUIMode: preview
note_type: latihan
latihan: Hapus Elemen dalam Rentang Tertutup
sumber: chatgpt.com
tags:
  - data-structure
  - set
date_learned: 2025-06-20T23:19:00
---
---
🔥 Gaskeun ke **Tantangan 13 — Penghapusan dalam Rentang (Range Erase)**

---

# 🧩 Tantangan 13 — Hapus Elemen dalam Rentang Tertutup [L, R]

**Fokus:** Gunakan `std::set::lower_bound()` dan `std::set::upper_bound()` untuk menghapus elemen dalam rentang `[L, R]`.

---

### Deskripsi Soal:

Buat program yang:

1. Membaca `n` bilangan bulat ke dalam `set`
    
2. Membaca dua bilangan `L` dan `R`
    
3. Menghapus **semua elemen dalam set** yang berada di dalam rentang **[L, R] (inklusif)**
    
4. Mencetak isi set setelah penghapusan
    

---

### Input Format:

- Baris pertama: bilangan bulat `n`
    
- Baris kedua: `n` bilangan bulat
    
- Baris ketiga: dua bilangan `L` dan `R` (L ≤ R)
    

---

### Output Format:

- Cetak seluruh isi set setelah elemen dalam rentang `[L, R]` dihapus, dalam urutan menaik.
    
- Jika kosong, cetak `Set kosong`
    

---

### Contoh Input 1:

```
6
10 20 30 40 50 60
25 45
```

### Contoh Output 1:

```
10 20 50 60
```

---

### Contoh Input 2:

```
5
5 10 15 20 25
5 25
```

### Contoh Output 2:

```
Set kosong
```

---

### 🧠 Petunjuk:

- Gunakan:
    
    ```cpp
    auto it1 = s.lower_bound(L);
    auto it2 = s.upper_bound(R);
    s.erase(it1, it2);
    ```
    
- Cetak dengan:
    
    ```cpp
    if (s.empty()) cout << "Set kosong";
    else for (auto x : s) cout << x << " ";
    ```
    

---

Kamu boleh langsung kirimkan solusi jika sudah siap! 💪