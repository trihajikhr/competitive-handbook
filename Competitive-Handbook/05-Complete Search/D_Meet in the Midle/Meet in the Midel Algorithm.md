---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 
nama_algoritma: 
kategori_algoritma: 
kesulitan: 🥉 easy 🥈 medium 🥇 hard
time_complexity: 🟢 O(1) 🔵 O(log n) 🟡 O(√n) 🟠 O(n) 🟤 O(n log n) 🟣 O(n²) 🟧 O(n³) 🔴 O(2ⁿ) ⚫ O(n!) ⚪O(formula)
memory_complexity: 🟢 O(1) 🔵 O(log n) 🟡 O(√n) 🟠 O(n) 🟤 O(n log n) 🟣 O(n²) 🟧 O(n³) 🔴 O(2ⁿ) ⚫ O(n!) ⚪O(formula) ✅ → Stable ❌ → Unstable
sumber: 
date_learned: 
tags:
---
#tag #tag #tag 

---
Great question! 🎯 **Meet in the Middle** adalah teknik yang muncul **setelah pruning dan backtracking** dalam topik _complete search_. Teknik ini sangat powerful untuk kasus ketika brute force biasa terlalu lambat, bahkan dengan pruning atau backtracking.

---

## 🧠 Apa Itu **Meet in the Middle**?

**Meet in the Middle (MitM)** adalah teknik _complete search_ yang membagi masalah menjadi dua bagian yang lebih kecil, menghitung semua kemungkinan dari masing-masing bagian, lalu **menggabungkannya di tengah**.

> **Inti ide:** Daripada mencari solusi secara keseluruhan langsung dari awal sampai akhir (yang bisa butuh waktu `O(2^n)`), kita **bagi dua** (`n/2` dan `n/2`) → lalu waktu jadi `O(2^(n/2))` untuk setiap sisi, dan hasil akhirnya jadi jauh lebih cepat!

---

## 📚 Contoh Kasus Klasik: **Subset Sum Problem**

> Diberikan array `A` dengan `n` elemen, dan target `X`. Apakah ada subset dari `A` yang jumlah elemennya sama dengan `X`?

Jika `n` besar (misal `n = 40`), maka mencoba semua subset (`2^n`) **terlalu berat**.

### 🔁 Solusi Biasa:

- Brute-force semua subset → waktu: `O(2^n)` → TIDAK MAMPU untuk `n > 25`.
    

### ✅ Solusi Meet in the Middle:

1. Bagi array jadi dua bagian: `left` dan `right`.
    
2. Hitung semua kemungkinan subset sum dari `left` → simpan di `L`.
    
3. Hitung semua kemungkinan subset sum dari `right` → simpan di `R`.
    
4. Untuk setiap nilai `a` di `L`, cari `X - a` di `R` (dengan binary search jika perlu).
    
5. Total waktu: `O(2^(n/2) * log(2^(n/2))) = O(2^(n/2) * n)` → jauh lebih efisien.
    

---

## 💡 C++ Contoh Implementasi: Subset Sum dengan MitM

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> getSubsetSums(const vector<int>& arr) {
    int n = arr.size();
    vector<long long> sums;
    for (int mask = 0; mask < (1 << n); mask++) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) sum += arr[i];
        }
        sums.push_back(sum);
    }
    return sums;
}

bool meetInTheMiddle(vector<int>& arr, int x) {
    int n = arr.size();
    vector<int> left(arr.begin(), arr.begin() + n/2);
    vector<int> right(arr.begin() + n/2, arr.end());

    vector<long long> L = getSubsetSums(left);
    vector<long long> R = getSubsetSums(right);
    sort(R.begin(), R.end());

    for (long long s : L) {
        if (binary_search(R.begin(), R.end(), x - s)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int& a : arr) cin >> a;

    if (meetInTheMiddle(arr, x)) {
        cout << "YES, subset with sum " << x << " exists.\n";
    } else {
        cout << "NO subset with that sum.\n";
    }
    return 0;
}
```

---

## 🧩 Kapan Menggunakan Meet in the Middle?

|Situasi|Cocok pakai MitM?|
|---|---|
|Ukuran input `n ≤ 40` tapi terlalu besar untuk brute-force langsung|✅ YA|
|Masalah bisa dibagi dua secara natural|✅ YA|
|Hasil dari satu bagian bisa digabung dengan hasil bagian lain|✅ YA|

---

Kalau kamu mau belajar versi **Meet in the Middle untuk N-Queens Count**, **Knapsack**, atau bentuk **counting combinations**, tinggal bilang ya. Kita bisa lanjut ngulik strategi cerdas buat problem besar 💪

Mau lanjut ke contoh soal lain dengan MitM atau bikin soal latihan?