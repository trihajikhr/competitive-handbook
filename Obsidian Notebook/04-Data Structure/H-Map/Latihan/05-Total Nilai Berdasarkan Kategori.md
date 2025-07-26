---
obsidianUIMode: preview
note_type: latihan
latihan: Total Nilai Berdasarkan Kategori
sumber: chatgpt.com
tags:
  - data-structure
  - map
date_learned: 2025-06-21T19:26:00
---
---
# 🧩 Soal 5: Total Nilai Berdasarkan Kategori

**Deskripsi:**

Diberikan `n` baris input, masing-masing berisi:

- sebuah `string` sebagai nama kategori
    
- sebuah `int` sebagai nilai
    

Tugasmu adalah menjumlahkan semua nilai untuk setiap kategori, lalu mencetak hasilnya berdasarkan urutan kategori (urutan leksikografis default dari `map`).

---

### 🧪 Contoh Input:

```
6
buah 10
sayur 5
buah 7
daging 20
sayur 3
buah 2
```

### 📤 Contoh Output:

```
buah 19
daging 20
sayur 8
```

---

### 💡 Petunjuk:

- Gunakan `std::map<string, int>` untuk menjumlahkan nilai berdasarkan kategori.
    
- Saat membaca tiap baris, tambahkan nilainya ke `map[kategori] += nilai`.
    
- Setelah selesai, cetak semua isi map.
    

---

Silakan kerjakan, dan kita review setelahnya ya!

## Jawabanku
Berikut adalah jawabn yang sudah optimal:

```cpp
#include<iostream>
#include<map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> dasmap;
    int n; cin >> n;
    
    string s; int x;

    while(n--){
        cin >> s >> x;
        dasmap[s]+=x;
    }

    for(const auto& [key, val]: dasmap){
        cout << key << " " << val << "\n";
    }
    return 0;
}
```

# Editorial
🔍 **Sangat baik dan langsung ke inti!**  
Kodenya **benar**, **optimal**, dan sudah memenuhi semua spesifikasi soal ke-5.

---

### ✅ Rangkuman Keunggulan Kode-mu:

|Hal|Penjelasan|
|---|---|
|`dasmap[s] += x`|Cara terbaik untuk menambahkan nilai per kategori tanpa perlu cek apakah key sudah ada.|
|`map<string, int>`|Sangat cocok karena `map` otomatis menyimpan dalam urutan leksikografis.|
|Loop `for (const auto& [key, val] : dasmap)`|Modern dan bersih, menunjukkan pemahaman gaya C++ kontemporer.|
|`ios::sync_with_stdio(false)`|Menunjukkan kesadaran terhadap optimasi I/O.|

---

### 🧪 Contoh Proses:

#### Input:

```
6
buah 10
sayur 5
buah 7
daging 20
sayur 3
buah 2
```

#### Map akhir:

```
buah: 19
daging: 20
sayur: 8
```

#### Output:

```
buah 19
daging 20
sayur 8
```

✅ **Sesuai 100%**

---

Kalau kamu siap, mari kita lanjut ke **Soal 6: Mencari Kategori dengan Nilai Tertinggi**. Kali ini kamu akan melibatkan pencarian maksimum dari isi `map`. Siap?