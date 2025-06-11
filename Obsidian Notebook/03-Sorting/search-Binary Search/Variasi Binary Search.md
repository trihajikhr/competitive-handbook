---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 03TH-STBN-V001
nama_algoritma: Binary Search Algorithm
kategori_algoritma: search
kesulitan: 🥉 easy
time_complexity: 🟢 O(1) > 🔵 O(log n) > 🔵 O(log n)
memory_complexity: 🟢 O(1)
sumber: Google.com, AI
date_learned: 2025-06-05T09:43:00
tags:
  - search
  - sorting
  - array
---
---
# Variasi Binary Search
Berikut adalah beberapa variasi dan pola penggunaan Binary Search yang sering dijumpai dalam pemrograman kompetitif atau implementasi sehari-hari:

## 1. Binary Search Biasa (Exact Match)

- **Tujuan**: Mencari indeks `i` di mana `A[i] == target`.
    
- **Implementasi**: Biasa menggunakan loop `while (lo <= hi)` atau `while (lo < hi)` dengan mid = `(lo + hi) / 2`.
    
- **Poin Penting**: Pastikan kondisi loop, perhitungan `mid`, dan update `lo/hi` sudah benar agar tidak terjadi infinite loop atau keluar satu elemen terlalu banyak.
    

> **Contoh Kasus**: Mencari apakah suatu angka ada dalam array terurut.

```cpp
int binary_search_exact(const vector<int>& A, int target) {
    int lo = 0, hi = (int)A.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (A[mid] == target) return mid;
        else if (A[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1; // Tidak ditemukan
}
```

---

## 2. Lower Bound (First Element ≥ Target)

- **Tujuan**: Mengembalikan indeks `i` terkecil di mana `A[i] ≥ target`.
    
- **Kegunaan**:
    
    - Menentukan posisi sisipan (insert position) untuk mempertahankan array terurut.
        
    - Menghitung jumlah elemen < target dengan `count = lower_bound(A.begin(), A.end(), target) - A.begin()`.
        
- **Implementasi**:
    
    - Loop dengan kondisi `while (lo < hi)`, kemudian jika `A[mid] < target → lo = mid + 1`, else `hi = mid`.
        
    - Hasil akhir `lo` menunjuk ke indeks pertama yang memenuhi `A[lo] ≥ target`, atau `lo == n` jika semua elemen < target.
        

```cpp
int lower_bound_idx(const vector<int>& A, int target) {
    int lo = 0, hi = (int)A.size();  // notice hi = size, bukan size-1
    // Invariant: kita mencari di [lo, hi), artinya hi boleh sama dengan n
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (A[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo; 
}
```

- **Hasil**:
    
    - Jika `target` lebih kecil atau sama dengan elemen paling kecil, akan `return 0`.
        
    - Jika semua elemen `< target`, maka `return n` (di luar indeks array).
        

---

## 3. Upper Bound (First Element > Target)

- **Tujuan**: Mengembalikan indeks `i` terkecil di mana `A[i] > target`.
    
- **Kegunaan**:
    
    - Menghitung jumlah elemen ≤ target dengan `count = upper_bound(A.begin(), A.end(), target) - A.begin()`.
        
    - Dalam kasus menghitung frekuensi nilai tertentu, selisih antara `upper_bound(target)` dan `lower_bound(target)` memberi banyaknya kemunculan.
        
- **Implementasi**:
    
    - Mirip `lower_bound`, tapi kondisi diubah menjadi `if (A[mid] <= target) lo = mid + 1; else hi = mid`.
        

```cpp
int upper_bound_idx(const vector<int>& A, int target) {
    int lo = 0, hi = (int)A.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (A[mid] <= target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}
```

- **Hasil**:
    
    - Jika semua elemen `≤ target`, maka `return n`.
        
    - Jika `target < A[0]`, maka `return 0`.
        

---

## 4. First / Last Occurrence (Leftmost / Rightmost)

- **Leftmost (First Occurrence)**: Dalam array terurut (bisa ada duplikat), cari indeks paling kiri yang nilainya sama dengan `target`.
    
    - Bisa diimplementasikan dengan memodifikasi `lower_bound`: setelah mendapat `idx = lower_bound(A, target)`, cek apakah `idx < n && A[idx] == target`. Jika ya, itulah indeks pertama. Jika tidak, berarti `target` tidak ada.
        
- **Rightmost (Last Occurrence)**: Cari indeks paling kanan yang nilainya sama dengan `target`.
    
    - Misalnya `idx = upper_bound(A, target) - 1`. Jika `idx >= 0 && A[idx] == target`, maka itulah indeks terakhir. Jika tidak, berarti tidak ada.
        

> **Contoh Pseudocode (First Occurrence)**:

```cpp
int first_occurrence(const vector<int>& A, int target) {
    int idx = lower_bound_idx(A, target);
    if (idx < (int)A.size() && A[idx] == target) return idx;
    else return -1; 
}
```

> **Contoh Pseudocode (Last Occurrence)**:

```cpp
int last_occurrence(const vector<int>& A, int target) {
    int idx = upper_bound_idx(A, target) - 1;
    if (idx >= 0 && A[idx] == target) return idx;
    else return -1;
}
```

---

## 5. Boolean Search (Search pada Array Boolean atau Kondisi Monoton)

- **Tujuan**: Saat kita punya array `B[0..n-1]` berisi nilai boolean, di mana untuk suatu titik `k`, `B[0..k] = false`, dan `B[k+1..n-1] = true`. Kita ingin mencari indeks pertama `true`.
    
- **Implementasi**:
    
    - Mirip `lower_bound`, tapi perbandingan langsung pada nilai boolean:
        
        - Jika `B[mid] == false`, geser `lo = mid + 1`.
            
        - Jika `B[mid] == true`, geser `hi = mid`.
            
- **Kegunaan**:
    
    - Mencari “transition point” pada fungsi boolean yang monoton (false → true).
        
    - Sering disebut “binary search on predicate”.
        

```cpp
int find_first_true(const vector<bool>& B) {
    int lo = 0, hi = (int)B.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (!B[mid]) lo = mid + 1;
        else hi = mid;
    }
    return lo; // jika lo == n, berarti tidak ada true
}
```

---

## 6. Binary Search Pada Array yang Terotasi (Rotated Sorted Array)

- **Kondisi**: Array semula terurut menaik, lalu dipotong (rotated) di satu titik. Contoh: `[4,5,6,7,0,1,2]`.
    
- **Tujuan**: Cari elemen `target` di dalam array terotasi tanpa melakukan linear scan $(O(n))$.
    
- **Ide Utama**:
    
    1. Tentukan mid seperti biasa.
        
    2. Periksa apakah sisi kiri (`A[lo..mid]`) terurut menaik atau sisi kanan (`A[mid..hi]`) terurut menaik.
        
    3. Jika sisi yang terurut mengandung `target`, geser batas sehingga mencari di sisi itu; jika tidak, cari di sisi sebaliknya.
        
- **Pseudocode Singkat**:
    

```cpp
int search_rotated(const vector<int>& A, int target) {
    int lo = 0, hi = (int)A.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (A[mid] == target) return mid;

        // Jika sisi kiri [lo..mid] terurut menaik
        if (A[lo] <= A[mid]) {
            if (A[lo] <= target && target < A[mid]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        // Sisi kiri tidak terurut, berarti sisi kanan [mid..hi] terurut menaik
        else {
            if (A[mid] < target && target <= A[hi]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }
    return -1; // tidak ditemukan
}
```

- **Catatan**: Hati-hati dengan duplikat; jika ada elemen duplikat, perlu penanganan khusus (misalnya skip nilai sama di ujung).
    

---

## 7. Binary Search pada Array Unimodal / Bitonic

- **Kondisi**: Array menaik sampai suatu puncak, lalu menurun (bitonic).
    
- **Tujuan**:
    
    1. Pertama, temukan indeks puncak (peak) — yaitu posisi maksimum.
        
    2. Setelah tahu puncak, lakukan binary search menaik di `A[0..peak]` atau binary search menurun di `A[peak..n-1]`.
        
- **Langkah**:
    
    1. **Cari Peak**
        
        - Loop `while (lo < hi)`, mid = `(lo+hi)/2`.
            
        - Jika `A[mid] > A[mid+1]`, berarti kita di or di sebelah kiri puncak; geser `hi = mid`.
            
        - Jika `A[mid] < A[mid+1]`, berarti kita masih di bagian menaik; geser `lo = mid + 1`.
            
        - Akhirnya `lo == hi` menunjuk ke puncak.
            
    2. **Cari Target**
        
        - Lakukan binary search menaik (gunakan fungsi biasa) pada jangkauan `0..peak`.
            
        - Jika tidak ketemu, lakukan binary search namun dengan kondisi terbalik (karena bagian setelah peak menurun) pada jangkauan `peak+1..n-1`.
            

---

## 8. Search in “Infinite” or Ukuran Tidak Diketahui (Exponential + Binary Search)

- **Kondisi**: Data seolah-olah “infinite” atau kita tidak tahu panjang array (misalnya streaming data, atau pointer ke struktur yang hanya bisa diakses via `get(i)` tapi `i` bisa out-of-bounds).
    
- **Langkah**:
    
    1. **Eksponensial**: Mulai dengan `bound = 1`. Sementara `get(bound) < target`, gandakan `bound <<= 1` (`bound = bound * 2`), hingga `get(bound) ≥ target` atau error (beyond end).
        
    2. Sekarang ada jangkauan `[bound/2 .. bound]` di mana `target` mungkin ada (atau jangkauan sampai batas array).
        
    3. Lakukan binary search di dalam jangkauan ini. Pastikan ketika akses melewati batas, tangani exception atau gunakan sentinel.
        

```cpp
int search_infinite(/* fungsi get(i) */) {
    // Contoh: kita anggap get(i) return -∞ jika i di luar
    int bound = 1;
    while (get(bound) < target) {
        bound <<= 1;
    }
    // Lakukan binary search pada [bound/2 .. bound]
    int lo = bound >> 1, hi = bound;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int val = get(mid);
        if (val == target) return mid;
        else if (val < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
```

---

## 9. Binary Search on “Answer Space” (Parametric Search)

- **Konsep**: Daripada mencari index di array, kita mencari nilai (numerik, biasanya integer atau real) yang memenuhi suatu kondisi monoton.
    
- **Contoh Kasus**:
    
    - Mencari kapasitas minimum (integer) sehingga bisa membagi barang ke dalam `k` kontainer.
        
    - Mencari nilai tolerance terkecil untuk memuaskan suatu kondisi (berupa boolean).
        
    - Mencari nilai maksimal `x` di mana suatu fungsi terpenuhi.
        
- **Implementasi**:
    
    1. Definisikan fungsi `check(x)` yang mengembalikan `true/false` dan bersifat monoton (jika `check(x) == true`, maka untuk semua `y > x`, `check(y) == true`, atau sebaliknya).
        
    2. Lakukan binary search pada rentang `lo..hi` dari nilai yang mungkin.
        
    3. Cari titik peralihan (transition point) di mana `check(mid)` berubah dari `false → true` (atau sebaliknya), sama seperti pola “Boolean Search” di array.
        
- **Catatan**: Bisa diterapkan pada domain integer maupun real (floating), dengan syarat saat domain real perlu berhenti saat `hi - lo` cukup kecil (misalnya `1e-6`).
    

```cpp
long long lo = 0, hi = 1e18, ans = -1;
while (lo <= hi) {
    long long mid = lo + (hi - lo) / 2;
    if (check(mid)) {
        ans = mid;
        hi = mid - 1; // cari nilai terkecil yang masih valid
    } else {
        lo = mid + 1;
    }
}
// `ans` sekarang adalah jawaban minimum yang memenuhi
```

---

## 10. Binary Search pada Fungsi yang Terdistribusi dalam Matriks Terurut

- **Kondisi**: Misalnya diberikan matrix `M` ukuran `n×m` di mana setiap baris dan kolom terurut menaik, atau seluruh elemen di-flatten menjadi array terurut.
    
- **Beberapa Pendekatan**:
    
    1. **Flatten dan Lakukan Binary Search**
        
        - Anggap `A[i][j]` dikonversi ke indeks `k = i * m + j`.
            
        - Akses elemen via `value = A[k/m][k%m]`.
            
        - Terapkan binary search di rentang `0..(n*m - 1)`.
            
    2. **Binary Search Baris+lalu Kolom**
        
        - Jika hanya baris yang terurut, bisa cari baris yang potensial (`lo..hi`) dengan memeriksa corner elements, lalu dalam baris itu lakukan binary search biasa.
            
        - Jika setiap baris dan kolom terurut (misalnya matrix sorted row-wise and column-wise), bisa gunakan teknik “search from top-right corner” yang bukan binary search murni, tapi O(n+m). Namun, untuk strict row-then-column terurut, flatten+binary search lebih umum.
            

---

## 11. Variasi Praktis Lainnya

1. **Binary Search pada String (Lexicographic)**
    
    - Misalnya mencari posisi kata dalam `vector<string>` terurut.
        
    - Prinsip sama, perbandingan menggunakan `A[mid].compare(target)`.
        
2. **Binary Search dengan Kondisi Kustom (Compare Function)**
    
    - Daripada `A[mid] < target`, kita bisa punya `compare(A[mid], target) < 0` atau callback fungsi khusus, misalnya untuk struktur data yang sudah terurut berdasarkan kriteria tertentu.
        
3. **Binary Search pada Bitset / Bitwise**
    
    - Kadang kita ingin cari batas posisi bit tertentu berubah (misal, paling kiri 1 di deretan bit yang berubah bergantung kondisi).
        
4. **Ternary Search (Pencarian pada Fungsi Unimodal Kontinu / Diskrit)**
    
    - Meskipun bukan “binary” search, prinsipnya mirip: cari titik maksimum/minimum fungsi unimodal.
        
    - Bagi interval menjadi tiga bagian, bandingkan nilai fungsi di dua titik tengah, lalu geser interval.
        
    - **Catatan**: Ternary Search hanya berlaku jika fungsi unimodal (naik kemudian turun) dan domainnya kontinu atau diskrit dengan properti unimodal yang jelas.
        
5. **Binary Search di Tree Implicit (Fenwick Tree, Segment Tree)**
    
    - Misalnya menemukan “smallest prefix sum ≥ k” pada Fenwick Tree: lakukan binary lifting, yang sejatinya binary search pada rangkaian sum.
        
    - Atau cari point di Segment Tree berdasarkan cumulated frequency. Konsepnya: di setiap node, periksa apakah di subtree kiri cukup untuk memenuhi target, dll.
        

---

## 12. Perbedaan Implementasi: Iteratif vs Rekursif

- **Iteratif**
    
    - Umumnya lebih ringkas, cukup gunakan `while (lo <= hi)` atau `while (lo < hi)`.
        
    - Tidak memerlukan overhead stack.
        
- **Rekursif**
    
    - Kode bisa lebih mudah dibaca (bagian “cari di kiri / kanan” dipisah jadi dua panggilan fungsi).
        
    - Berisiko stack overflow jika dipanggil terlalu dalam (meski depth log₂(n) biasanya aman).
        
- **Rekomendasi**: Untuk kasus standar, iteratif lebih disarankan karena mudah di-debug dan konsisten dalam performa.
    

---

## 13. Tips & Trik Umum

1. **Hati-hati dengan Off-by-One**
    
    - Pastikan kondisi `while (lo < hi)` versus `while (lo <= hi)` sudah tepat sesuai tujuan (first ≥, last ≤, exact match, dsb).
        
    - Saat menggunakan `lo < hi`, hasil akhir umumnya `lo == hi`, sedangkan `lo <= hi` setelah loop bisa memaksilkan `lo == hi+1`.
        
2. **Perhitungan Mid**
    
    - Gunakan `int mid = lo + (hi - lo) / 2;`
        
    - Hindari `(lo + hi) / 2` apabila `lo + hi` dapat overflow (jarang terjadi pada int 32-bit, tapi aman digunakan di C++).
        
3. **Ketika Ada Duplikat**
    
    - Jika ingin hanya “apapun” yang pertama menemukan (exact match), sudah cukup.
        
    - Jika butuh `first/last occurrence`, gunakan pola `lower_bound`/`upper_bound` seperti di atas.
        
4. **Pastikan Domain (Rentang) yang Dicari sudah Jelas**
    
    - Misal, untuk lower_bound kita pakai `[0..n]` (hi = n), bukan `[0..n-1]`.
        
    - Untuk search pada rentang real, tentukan epsilon (misal `1e-6`) dan loop hingga `hi - lo < ε`.
        

---

### Ringkasan Variasi Umum

|Variasi|Kondisi Array/Fungsi|Tujuan Utama|
|---|---|---|
|Exact Match|Array terurut (integer)|Temukan indeks di mana `A[i] == target`|
|Lower Bound (First ≥ target)|Array terurut menaik|Indeks paling kiri dengan `A[i] ≥ target`|
|Upper Bound (First > target)|Array terurut menaik|Indeks paling kiri dengan `A[i] > target`|
|First/Last Occurrence (Duplikat)|Array terurut dengan duplikat|Temukan batas range elemen sama (`A[i] == target`)|
|Boolean Search (Monoton False→True)|Array/Predicate Boolean|Temukan titik peralihan dari `false → true`|
|Search di Rotated Sorted Array|Array menaik yang dirotasi|Cari `target` di array yang terotasi|
|Search di Array Unimodal/Bitonic|Array menaik lalu menurun|Cari puncak (peak), lalu cari di masing-masing segmen|
|Infinite-Size Search (Exponential)|Data tanpa informasi panjang|Pertama cari jangkauan, lalu binary di dalamnya|
|Parametric Search (Answer Space)|Fungsi boolean monotonic|Cari nilai minimal/maksimal yang memenuhi kondisi|
|Binary Search di Matriks Terurut|Matrix terurut (baris/kolom)|Flatten atau cari per baris/kolom|
|Ternary Search (Unimodal Kontinu)|Fungsi unimodal|Cari nilai maksimum/minimum fungsi unimodal|

---

Dengan memahami pola–pola di atas, kamu bisa menyesuaikan implementasi Binary Search sesuai kebutuhan masalah. Setiap variasi sebenarnya turun dari konsep dasar “pecah rentang menjadi dua (divide and conquer)” namun dengan kondisi dan update `lo/hi` yang sedikit berbeda. Semoga membantu memperkaya pemahaman variasi atau “pattern” Binary Search dalam berbagai skenario pemrograman!