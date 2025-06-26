---
obsidianUIMode: preview
note_type: latihan
latihan: Merge Dua Daftar Angka Unik
sumber: Google.com, AI
tags:
  - vector
  - data-structure
date_learned: 2025-06-14T21:46:00
---
---
Untuk soal terakhir (Soal 15) aku usulkan yang memadukan beberapa algoritma `vector` dan STL-algorithm pada satu skenario praktis:
# 🧩 Soal 15: Merge Dua Daftar Angka Unik

Kamu punya dua daftar bilangan bulat **sudah terurut menaik**:

1. Baca integer `n`, lalu daftar `A` berisi `n` angka terurut.
    
2. Baca integer `m`, lalu daftar `B` berisi `m` angka terurut.
    

Tugasmu:

1. **Merge** dua daftar tersebut menjadi satu `vector<int> C`, tetap terurut menaik.
    
2. **Hapus** semua duplikat di `C` sehingga setiap angka muncul sekali.
    
3. Cetak isi `C`, dipisah spasi (atau `EMPTY` jika tidak ada elemen).
    

### Ketentuan dan Fungsi yang Dipraktikkan

- Gunakan algoritma STL:
    
    - `merge(A.begin(), A.end(), B.begin(), B.end(), back_inserter(C));`
        
    - `C.erase(unique(C.begin(), C.end()), C.end());`
        
- Pelajari juga opsi in-place:
    
    - `A.insert(A.end(), B.begin(), B.end());`
        
    - `inplace_merge(A.begin(), A.begin()+n, A.end());`
        

### Contoh

**Input:**

```
5
1 3 5 7 9
4
2 3 6 8
```

**Output:**

```
1 2 3 5 6 7 8 9
```

---

Soal ini akan menguji:

1. Cara menggabungkan dua `vector` terurut (`merge` vs `inplace_merge` + `insert`).
    
2. Cara membersihkan elemen berulang (`unique` + `erase`).
    
3. Pemahaman iterators dan `back_inserter`.
    

Kalau kamu setuju, langsung coba implementasi dan kirim kodenya—nanti aku review dan kasih editorial seperti biasa! 🚀

# Jawaban dan Editorial
Karena aku belum pernah menghadapi soal seperti ini, maka aku pusutkan untuk melihat jawaban, dan juga editorialnya sekalian:

Berikut **jawaban lengkap (C++)** diikuti **editorial** untuk Soal 15: Merge Dua Daftar Angka Unik.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    // Baca daftar A
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    // Baca daftar B
    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    // 1) Merge A dan B ke C
    vector<int> C;
    C.reserve(n + m);
    merge(A.begin(), A.end(),
          B.begin(), B.end(),
          back_inserter(C));

    // 2) Hapus duplikat berurutan
    C.erase(unique(C.begin(), C.end()), C.end());

    // 3) Cetak hasil
    if (C.empty()) {
        cout << "EMPTY\n";
    } else {
        for (size_t i = 0; i < C.size(); i++) {
            cout << C[i] << (i + 1 < C.size() ? ' ' : '\n');
        }
    }
    return 0;
}
```

---

## Editorial

### 1. Ringkasan Masalah

- Ada dua daftar terurut **menaik**: `A` (size = n) dan `B` (size = m).
    
- Kita perlu menggabungkan keduanya menjadi satu daftar baru `C` tetap terurut menaik, lalu menghilangkan semua elemen duplikat sehingga setiap angka muncul sekali.
    

### 2. Langkah Penyelesaian

1. **Merge Terurut**  
    Pakai:
    
    ```cpp
    merge(A.begin(), A.end(),
          B.begin(), B.end(),
          back_inserter(C));
    ```
    
    - Fungsi ini menggabungkan dua range yang sudah terurut ke range tujuan (`C`), sambil tetap menaik.
        
2. **Hapus Duplikat Berurutan**  
    Ketika `C` sudah terurut, semua duplikat tersusun rapat.  
    Gunakan pola “remove-erase idiom”:
    
    ```cpp
    C.erase(
      unique(C.begin(), C.end()),
      C.end()
    );
    ```
    
    - `unique` memindahkan setiap elemen unik ke depan dan mengembalikan iterator ke akhir bagian unik.
        
    - `erase` memangkas sisa elemen duplikat.
        
3. **Cetak atau EMPTY**
    
    - Jika `C.empty()`, cetak `"EMPTY"`.
        
    - Lainnya, cetak semua nilai dipisah spasi.
        

### 3. Fungsi & Algoritma STL

|Fungsi / Algo|Kegunaan|
|---|---|
|`merge(first1, last1, first2, last2, outIt)`|Menggabungkan dua range terurut → terurut di `C`.|
|`back_inserter(C)`|Output iterator untuk men‐`push_back` ke vector `C`.|
|`unique(first, last)`|Menghapus duplikat berurutan (memindahkan unik ke depan).|
|`erase(it, last)`|Menghapus elemen di range `[it, last)`.|

### 4. Kompleksitas

- **Waktu**
    
    - `merge`: O(n + m)
        
    - `unique` + `erase`: O(n + m)
        
    - Total: O(n + m)
        
- **Memori**
    
    - Vector `C` menggunakan O(n + m) ruang.
        

### 5. Alternatif In‑Place

Jika ingin menggabung tanpa container tambahan `C`, bisa juga:

```cpp
A.insert(A.end(), B.begin(), B.end());
inplace_merge(A.begin(), A.begin() + n, A.end());
A.erase(unique(A.begin(), A.end()), A.end());
```

- `insert` menambahkan B ke akhir A
    
- `inplace_merge` menggabung dua bagian terurut di dalam satu vector
    
- Sisanya sama: `unique` + `erase`.
    

---

Selamat! Dengan ini kamu telah melalui 15 soal latihan intensif tentang `vector` dan berbagai fungsi/algoritma STL-nya. 🚀 Semoga makin paham dan siap gunakan di proyek nyata maupun lomba!