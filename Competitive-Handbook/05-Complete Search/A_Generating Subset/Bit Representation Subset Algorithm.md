---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 05TH-CSGSBR-0001
nama_algoritma: Bit Representation Subset Algorithm
kategori_algoritma: complete search
kesulitan: 🥉 easy
time_complexity: ⚪O(2ⁿ • n)
memory_complexity: 🟠 O(n)
sumber: "buku: CP handbook by Antti Laaksonen & chatgpt.com"
date_learned: 2025-04-12T12:32:00
tags:
  - complete-search
  - generating-subset
  - bit-representation
---
#complete-search #generating-subset #bit-representation

---
# Bit Representations Subset Algorithm

## Algoritma Bit Representations Subset

Algoritma Bit Representations Subset adalah teknik menghasilkan semua kemungkinan subset dari sebuah himpunan dengan menggunakan representasi biner dari angka. Setiap angka dari $0$ sampai $2^n - 1$ merepresentasikan satu subset, di mana bit ke-i menunjukkan apakah elemen ke-i dalam array dimasukkan ke dalam subset atau tidak.

Contohnya, jika kita punya array `arr = [a, b, c]`:

- 000 → []
    
- 001 → [c]
    
- 010 → [b]
    
- 011 → [b, c]
    
- ...
    
- 111 → [a, b, c]
    

# Contoh Algoritma Bit Representations Subset

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) cin >> x;

    // Bitmasking dari 0 hingga 2^n - 1
    for (int b = 0; b < (1 << n); b++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (b & (1 << i)) {
                subset.push_back(arr[i]);
            }
        }

        // Cetak subset
        cout << "[ ";
        for (int x : subset) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
```

## Bit Representations Subset Complexity

### Time Complexity

#### Best Case (Kasus Terbaik) -

Tetap $O(2^n \cdot n)$ karena semua subset tetap harus dicek.

#### Average Case (Kasus Rata-rata) -

Tetap $O(2^n \cdot n)$ karena jumlah iterasi tidak tergantung input, melainkan panjang array.

#### Worst Case (Kasus Terburuk) -

Tetap $O(2^n \cdot n)$.

### Ringkasan

| Kasus        | Kompleksitas Waktu |
| ------------ | ------------------ |
| Best Case    | $O(2^n \cdot n)$   |
| Average Case | $O(2^n \cdot n)$   |
| Worst Case   | $O(2^n \cdot n)$   |

## Space Complexity dan Stability

### Space Complexity

- $O(n)$ untuk menyimpan subset sementara
    
- Tidak menggunakan rekursi, jadi tidak ada call stack tambahan
    

### Stability

- Tidak ada pengaruh terhadap stability karena ini bukan algoritma pengurutan
    

## Kesimpulan

| Faktor Complexity | Nilai            |
| ----------------- | ---------------- |
| Best Case         | $O(2^n \cdot n)$ |
| Average Case      | $O(2^n \cdot n)$ |
| Worst Case        | $O(2^n \cdot n)$ |
| Space Complexity  | $O(n)$           |
| Stability         | Tidak relevan    |

# Aplikasi Bit Representations Subset


- Masalah subset sum
- Masalah kombinasi (combination)
- Pencarian subset dengan kriteria tertentu (max profit, min cost)
- Penyelesaian brute-force pada ukuran kecil

## Keunggulan dan kelemahan

### Keunggulan Bit Representations Subset

- Implementasi simpel dan efisien
- Tidak perlu rekursi (iteratif)
- Mudah dikendalikan dan dimodifikasi
- Cocok untuk ukuran kecil hingga menengah (n ≤ 20)
    

### Kelemahan Bit Representations Subset

- Kompleksitas eksponensial $(2^n)$
- Tidak cocok untuk input besar $(n > 25)$
- Sulit diterapkan jika elemen subset memiliki batasan kompleks atau kondisi tambahan
    

## Kesimpulan

Bit Representations Subset Algorithm sangat cocok untuk menyelesaikan masalah pencarian semua kombinasi subset dari array secara efisien dan bersih. Meskipun memiliki kompleksitas eksponensial, ia sangat ideal untuk masalah-masalah ukuran kecil hingga menengah. Penggunaannya luas dalam domain seperti optimasi kombinatorial, brute-force, dan enumerasi subset.
