---
obsidianUIMode: preview
note_type: latihan
latihan: Majority Element
sumber: Google.com, AI
tags:
  - data-structure
  - array
date_learned: 2025-06-13T21:42:00
---
---
# Majority Element 
Siap! 🔥 Berikut **dua tantangan baru** yang tetap fokus pada penggunaan `std::array` STL. Level-nya naik dikit ya, biar makin mantap:

---

## 🔷 Tantangan 1: Majority Element

**Soal:**  
Diberikan sebuah array `std::array<int, 9>` berisi bilangan bulat. Carilah **elemen mayoritas**, yaitu elemen yang muncul **lebih dari ⌊N/2⌋ kali** (dalam array ukuran 9 berarti >4 kali). Jika ada, cetak elemennya, jika tidak, cetak `"Tidak ada elemen mayoritas"`.

**Contoh Input:**

```cpp
std::array<int, 9> data = {3,3,4,3,5,3,6,3,3};
```

**Output yang Diharapkan:**

```
Elemen mayoritas: 3
```

## Jawabanku
Berikut adalah kode programku untuk menjawab soal:

```cpp
#include<iostream>
#include<array>
using namespace std;

template <size_t N>
int solve(const array<int, N>& arr){
    array<int, N> hash = {0};

    for(size_t i=0; i<N; i++){
        hash[arr[i]-1]++;
    }

    int maks=INT_MIN;
    int idx;
    bool found=false;
    for(int i=0; i<N; i++){
        if(hash[i]>4 && hash[i]>maks){
            maks=hash[i];
            idx=i;
            found=true;
        }
    }

    if(found){
        return idx+1;
    } else return -1;
}

int main() {
    array<int, 9> data = {3,3,4,3,5,3,6,3,3};
    int rest = solve(data);

    if(rest != -1){
        cout << "Elemen Mayoritas: " << rest << "\n";
    } else cout << "Tidak ada elemen mayoritas!\n";
    return 0;
}
```

## Editorial
Keren! Kamu berhasil menyelesaikan tantangan **Majority Element** dengan pendekatan yang kreatif menggunakan array sebagai _hash map_! 🎯 Sekarang kita bahas dan nilai implementasimu:

---

### ✅ **Hasil Output:**

Dengan input:

```cpp
{3, 3, 4, 3, 5, 3, 6, 3, 3}
```

Output yang kamu hasilkan:

```
Elemen Mayoritas: 3
```

Ini **benar** ✅.

---

### 📘 **Analisis dan Editorial:**

#### 🔹 Tujuan:

Mencari elemen yang muncul lebih dari `⌊N/2⌋` kali dari array `std::array<int, 9>`.

#### 🔹 Logika Kode Kamu:

1. **Inisialisasi `hash`:**
    
    ```cpp
    array<int, N> hash = {0};
    ```
    
    Digunakan untuk menyimpan frekuensi kemunculan tiap elemen (diasumsikan nilainya dari 1 sampai N).
    
2. **Pengisian Frekuensi:**
    
    ```cpp
    hash[arr[i]-1]++;
    ```
    
    Diasumsikan bahwa elemen bernilai minimal 1 dan maksimal 9 agar tidak out-of-bounds (karena `arr[i]-1`).
    
3. **Pencarian Nilai Mayoritas:**  
    Iterasi seluruh `hash[]` untuk mencari nilai yang muncul lebih dari `4` kali (karena `N=9`), lalu ambil nilai terbesar yang memenuhi syarat.
    

---

### ⚠️ **Catatan dan Perbaikan Potensial:**

|Masalah|Penjelasan|
|---|---|
|❗ `hash[arr[i]-1]`|Ini berbahaya jika `arr[i]` bernilai `0` atau negatif, karena bisa menyebabkan **out-of-bounds**.|
|❗ Ukuran tetap `N`|Jika elemen terbesar > N, maka akan tetap terjadi out-of-bounds.|
|📦 Tidak fleksibel|Cocok untuk nilai-nilai kecil, tapi kurang fleksibel jika range elemen besar atau tidak dimulai dari 1.|

---

### ✅ Alternatif Aman: Menggunakan `unordered_map`

Kalau ingin program lebih aman dan fleksibel:

```cpp
#include <unordered_map>
unordered_map<int, int> freq;
for (auto x : arr) freq[x]++;
```

---

### ✅ Kesimpulan:

- ✅ Jawaban kamu benar untuk kasus ini.
    
- 💡 Pendekatan kamu cepat dan ringan untuk range kecil (1..N).
    
- ⚠️ Tapi tidak tahan terhadap input nilai besar atau negatif.
    
- 🌟 Tetap hebat karena kamu memanfaatkan `std::array` sesuai tantangan!
    

