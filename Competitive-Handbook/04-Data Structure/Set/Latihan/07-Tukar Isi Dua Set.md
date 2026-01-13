---
obsidianUIMode: preview
note_type: latihan
latihan: Tukar Isi Dua Set
sumber: chatgpt.com
tags:
  - data-structure
  - set
date_learned: 2025-06-20T21:40:00
---
---
# 🧩 Latihan 7 — Tukar Isi Dua Set

**Fokus:** Latihan menggunakan fungsi anggota `swap()` dari `std::set`.

---

### Deskripsi Soal:

Diberikan dua set berisi bilangan bulat. Tukar isi dari kedua set tersebut menggunakan fungsi `swap()`, lalu tampilkan isi keduanya setelah ditukar.

---

### Input Format:

- Baris pertama: bilangan bulat `n` dan `m` (jumlah elemen di set A dan B)
    
- Baris kedua: `n` bilangan bulat untuk set A
    
- Baris ketiga: `m` bilangan bulat untuk set B
    

---

### Output Format:

- Baris pertama: isi set A setelah ditukar
    
- Baris kedua: isi set B setelah ditukar
    

---

### Contoh Input:

```
3 4
1 2 3
10 20 30 40
```

### Contoh Output:

```
10 20 30 40
1 2 3
```

---

### 🧠 Petunjuk:

- Buat dua `set<int>`: A dan B
    
- Gunakan `A.swap(B);`
    
- Cetak isi set A dan B setelah operasi swap
    

---

Kamu boleh langsung kirim kode solusinya jika sudah selesai! Kalau butuh bantuan atau contoh awal, tinggal bilang aja! 💪

## Jawabanku
Berikut adalah jawabanku untuk permasalahan ini:

```cpp
#include<iostream>
#include<set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    set<int> A, B;

    for(int i=0, x; i<n; i++){
        cin >> x;
        A.emplace(x);
    }

    for(int i=0, x; i<m; i++){
        cin >> x;
        B.emplace(x);
    }

    A.swap(B);

    for(const auto&x:A){
        cout << x << " ";
    }

    cout << "\n";

    for(const auto&x:B){
        cout << x << " ";
    }

    return 0;
}
```

# Editorial
💯 Excellent! Kode kamu benar, bersih, dan sesuai semua kriteria soal!

---

### ✅ Yang Sudah Tepat:

1. **Membuat dua set `A` dan `B` serta mengisi datanya**:
    
    ```cpp
    set<int> A, B;
    A.emplace(...);
    B.emplace(...);
    ```
    
2. **Menukar isi kedua set dengan `swap()`**:
    
    ```cpp
    A.swap(B);
    ```
    
    ✔️ Ini lebih cepat dan bersih dibanding menyalin elemen satu per satu.
    
3. **Mencetak isi setelah ditukar**:
    
    ```cpp
    for (const auto& x : A) cout << x << " ";
    for (const auto& x : B) cout << x << " ";
    ```
    

---

### 🧪 Contoh Uji:

#### Input:

```
3 4
1 2 3
10 20 30 40
```

#### Output:

```
10 20 30 40
1 2 3
```

✅ Sesuai dengan hasil yang diharapkan!

---

### 📘 Catatan Ekstra:

- `swap()` berjalan dalam waktu **O(1)** karena hanya menukar pointer internal antara dua set, bukan menyalin data.
    
- Bisa juga digunakan seperti ini:
    
    ```cpp
    swap(A, B);  // Fungsi global di <utility>
    ```
    
