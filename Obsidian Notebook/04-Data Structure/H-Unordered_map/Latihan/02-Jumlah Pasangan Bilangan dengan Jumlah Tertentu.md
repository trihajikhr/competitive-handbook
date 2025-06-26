---
obsidianUIMode: preview
note_type: latihan
latihan: Jumlah Pasangan Bilangan dengan Jumlah Tertentu
sumber: Google.com, AI
tags:
  - data-structure
  - unordered_map
date_learned: 2025-06-16T14:28:00
---
---
# 🧠 Soal 2: Jumlah Pasangan Bilangan dengan Jumlah Tertentu

Diberikan array bilangan bulat `input` dengan panjang `n`, serta sebuah bilangan bulat `target_sum`.

Tentukan **berapa banyak pasangan** `(i, j)` dengan `i < j` yang memiliki **jumlah elemen sama dengan `target_sum`**, yaitu:

```
input[i] + input[j] == target_sum
```

---

### 📥 Input

- Baris pertama: integer `n` (jumlah elemen)
    
- Baris kedua: `n` integer (`input[i]`)
    
- Baris ketiga: integer `target_sum`
    

### 📤 Output

- Cetak jumlah pasangan `(i, j)` dengan `input[i] + input[j] == target_sum`
    

---

### 🧪 Contoh Input

```
6
1 5 7 -1 5 1
6
```

### ✅ Contoh Output

```
5
```


---

### 🔧 Hint

Gunakan `unordered_map<int,int>` untuk menghitung **jumlah elemen yang bisa membentuk pasangan** dengan elemen saat ini.

---

Kalau kamu sudah siap, langsung kerjakan dan kirim solusimu! 🚀

# Jawaban | 1
Kamu benar! 😅 Jawabannya memang **5**, dan aku akui kesalahan penjelasan di output sebelumnya. Mari kita luruskan semuanya:

---

### 📥 Input:

```
6
1 5 7 -1 5 1
6
```

### 💡 Penjelasan Lengkap Pasangan:

Kita cari semua pasangan `(i, j)` dengan `i < j` dan `arr[i] + arr[j] == 6`.

Data:

```
Index:  0  1  2  3  4  5  
Array: [1, 5, 7, -1, 5, 1]
```

Cari semua pasangan yang jumlahnya 6:

- (0,1) → 1+5 = 6 ✅
    
- (0,4) → 1+5 = 6 ✅
    
- (1,5) → 5+1 = 6 ✅
    
- (2,3) → 7 + (-1) = 6 ✅
    
- (4,5) → 5+1 = 6 ✅
    

✔️ Total pasangan valid = **5**

---

### 🧠 Kenapa Solusi `unordered_map` Tetap Benar?

Jawaban 3 itu dari solusi yang **menghitung jumlah pasangan (x, y)** saat `x` datang dan **y sudah pernah muncul** sebelumnya. Itu hanya menghitung pasangan satu arah.

Untuk menangani **semua kombinasi** `(i, j)` dengan `i < j`, dan tidak salah hitung, urutan pemrosesan sangat penting.

---

### ✅ Perbaikan Kode:

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    int target;
    cin >> target;

    unordered_map<int, int> freq;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];
        if (freq.count(complement)) {
            count += freq[complement]; // pasangan valid ditemukan
        }
        freq[arr[i]]++;
    }

    cout << count << "\n";
    return 0;
}
```

---

### 🔥 Kesimpulan:

- Kamu benar, jawabannya **5**.
    
- Kode `unordered_map` di atas **benar dan optimal**.
    
- Aku yang salah tulis penjelasan di contoh output sebelumnya. Makasih udah koreksi! 🙌
    

Kalau udah siap, kita gas soal ke-3 😎