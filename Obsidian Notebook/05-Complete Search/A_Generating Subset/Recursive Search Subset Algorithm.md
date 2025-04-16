---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 05TH-CSGSRS-0001
nama_algoritma: Recursive Search Subset Algorithm
kategori_algoritma: complete search
kesulitan: 🥉 easy
time_complexity: 🔴 O(2ⁿ)
memory_complexity: 🟠 O(n)
sumber: "buku: CP handbook by Antti Laaksonen & chatgpt.com"
date_learned: 2025-04-11T18:42:00
tags:
  - complete-search
  - generating-subset
  - recursive-search
---
#complete-search #generating-subset #recursive-search

---

# Recursive Search Subset Algorithm
Algoritma **Recursive Search Subset** adalah teknik untuk menghasilkan semua subset dari suatu himpunan dengan cara **rekursif**, yaitu memproses elemen satu per satu dan pada setiap langkah memutuskan apakah akan menyertakan elemen tersebut ke dalam subset atau tidak.
## Algoritma Recursive Search Subset

Kita ingin mencari semua subset dari suatu himpunan {0, 1, ..., n-1}.

Misalnya, `n = 3`. Maka kita akan memanggil fungsi `search(0)` yang akan membentuk pohon keputusan:

```cpp

							search(0)
                         /             \
                   (tanpa 0)         (dengan 0)
                  search(1)           search(1)
                 /        \           /        \
           (tanpa 1)  (dengan 1)  (tanpa 1)  (dengan 1)
           ...           ...         ...         ...
           
```

### Kode Referensi

```cpp
vector<int> subset;
int n;

void search(int k) {
    if (k == n) {
        // proses subset
        for (int x : subset) cout << x << " ";
        cout << "\n";
    } else {
        search(k + 1);         // tidak menyertakan elemen ke-k
        subset.push_back(k);   // menyertakan elemen ke-k
        search(k + 1);         // lanjutkan pencarian
        subset.pop_back();     // hapus elemen (backtrack)
    }
}
```

---

### ✅ Penjelasan Langkah per Langkah

1. **Inisialisasi:**
    
    - `subset` adalah vektor kosong untuk menyimpan elemen subset saat ini.
        
    - `n` adalah ukuran himpunan, misalnya 3 untuk elemen {0, 1, 2}.
        
2. **Fungsi `search(k)` dipanggil:**
    
    - Basis rekursi: Jika `k == n`, kita sudah mengecek seluruh elemen, maka **cetak isi subset saat ini**.
        
    - Jika `k < n`, kita memiliki dua pilihan:
        
        - **Tanpa elemen ke-k:** lanjutkan ke `search(k+1)` tanpa menambahkan apa pun.
            
        - **Dengan elemen ke-k:**
            
            - Tambahkan `k` ke `subset`.
                
            - Panggil lagi `search(k+1)`.
                
            - Setelah selesai, hapus `k` dari `subset` untuk **backtracking** (kembali ke kondisi sebelum menambahkan elemen itu).
                
3. **Proses ini membentuk pohon keputusan** dengan dua cabang di setiap level: menyertakan atau tidak menyertakan elemen ke-`k`.
    
4. **Total subset yang dihasilkan = 2ⁿ**.
    

Berikut hasilnya:

![[Recursive Search Subset Algorithm-1.png]]

---

# Contoh Algoritma Recursive Search Subset

Untuk `n = 3` dan himpunan {0, 1, 2}, semua subset yang dihasilkan:

```
Semua subset dari himpunan {0, 1, 2}:
{ }
{ 2 }
{ 1 }
{ 1 2 }
{ 0 }
{ 0 2 }
{ 0 1 }
{ 0 1 2 }
```

Seperti ini kodenya:

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> subset;
int n = 3; // Ukuran himpunan {0, 1, 2}

void search(int k) {
    if (k == n) {
        // Menampilkan subset saat ini
        cout << "{ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "}\n";
    } else {
        // Tanpa elemen ke-k
        search(k + 1);
        // Dengan elemen ke-k
        subset.push_back(k);
        search(k + 1);
        subset.pop_back(); // Backtrack
    }
}

int main() {
    cout << "Semua subset dari himpunan {0, 1, 2}:\n";
    search(0);
    return 0;
}
```

## 🧠 Kenapa `search(0)`?

`k` di sini adalah **index elemen** dari himpunan `{0, 1, 2, ..., n-1}` yang sedang kita putuskan:

> "Apakah elemen ke-`k` akan dimasukkan ke subset atau tidak?"

Jadi saat kita menulis `search(0)`, itu artinya:

- Kita mulai dari elemen pertama dalam himpunan, yaitu elemen `0`.
    
- Kita akan membuat **dua percabangan**:
    
    - Tanpa memasukkan `0` ke dalam subset
        
    - Dengan memasukkan `0` ke dalam subset
        

Setelah itu:

- `search(1)` berarti kita memutuskan tentang elemen ke-1 (yaitu `1`)
    
- dan seterusnya, hingga `k == n`, yaitu kita sudah memutuskan untuk semua elemen
    

---

## 🔄 Ilustrasi Singkat:

Misal `n = 3`, jadi himpunan kita: `{0, 1, 2}`  
Kita panggil `search(0)` → kita akan membuat keputusan untuk elemen `0`  
Kemudian `search(1)` → keputusan untuk elemen `1`  
Kemudian `search(2)` → keputusan untuk elemen `2`  
Terakhir `search(3)` → artinya kita sudah selesai memutuskan untuk semua elemen → cetak subset!

---

## 📌 Kesimpulan:

- `k` = indeks elemen yang sedang dipertimbangkan
    
- `search(0)` artinya mulai pertimbangkan elemen pertama (`0`)
    
- Kita akan lanjut sampai `k == n`, yang artinya **seluruh keputusan sudah dibuat** → kita punya satu subset yang valid untuk dicetak
    


# Recursive Search Subset Complexity

## Time Complexity

### Best Case (Kasus Terbaik) -

Masih tetap menghasilkan semua subset, karena sifatnya exhaustif: **O(2ⁿ)**

### Average Case (Kasus Rata-rata) -

Tetap harus mengeksplorasi semua kemungkinan subset: **O(2ⁿ)**

### Worst Case (Kasus Terburuk) -

Harus membangkitkan seluruh subset (jumlahnya 2ⁿ): **O(2ⁿ)**

### Ringkasan

|Kasus|Kompleksitas Waktu|
|---|---|
|Best Case|O(2ⁿ)|
|Average Case|O(2ⁿ)|
|Worst Case|O(2ⁿ)|

## Space Complexity dan Stability

### Space Complexity

- **O(n)** untuk rekursi stack dan subset saat ini (karena setiap subset bisa panjang maksimal `n`).
    

### Stability

- Tidak ada urutan khusus yang dipertahankan (bukan sorting), jadi tidak relevan untuk stabilitas.
    

---

## Kesimpulan

|Faktor Complexity|Nilai|
|---|---|
|Best Case|O(2ⁿ)|
|Average Case|O(2ⁿ)|
|Worst Case|O(2ⁿ)|
|Space Complexity|O(n)|
|Stability|-|

---

# Aplikasi Recursive Search Subset


- Digunakan dalam masalah yang memerlukan eksplorasi **semua subset**, seperti:
    
    - **Subset Sum Problem**
        
    - **Knapsack Problem** (versi brute-force)
        
    - **Decision Tree Traversal**
        
    - **Combinatorial Optimization**
        
    - **Power Set Generator**
        

---

## Keunggulan dan kelemahan

### Keunggulan Recursive Search Subset

- **Sederhana dan mudah dipahami.**
    
- Cocok untuk ruang pencarian kecil hingga menengah (biasanya n ≤ 20).
    
- Mudah dimodifikasi untuk memenuhi kondisi tertentu (misal, subset dengan jumlah tertentu).
    

### Kelemahan Recursive Search Subset

- **Tidak efisien untuk `n` besar** karena waktu eksekusi eksponensial.
    
- Rekursi yang dalam bisa menyebabkan stack overflow jika tidak hati-hati.
    
- Bukan pilihan terbaik untuk kasus real-time atau data besar.
    

---

## Kesimpulan

|Faktor Complexity|Nilai|
|---|---|
|Best Case|O(2ⁿ)|
|Average Case|O(2ⁿ)|
|Worst Case|O(2ⁿ)|
|Space Complexity|O(n)|
|Stability|-|
