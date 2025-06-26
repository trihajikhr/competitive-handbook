---
obsidianUIMode: preview
note_type: latihan
latihan: Perang Pengaruh Antar Kota
sumber: chatgpt.com
tags:
  - data-structure
  - map
date_learned: 2025-06-22T11:54:00
---
---
# 🔥 Soal 14: Perang Pengaruh Antar Kota

**Latar Cerita:**

Bayangkan kamu adalah sistem pusat analitik dalam game strategi seperti _Civilization_ atau _Total War_.

Setiap hari, kota-kota mengirim **diplomat** ke kota lain untuk memperluas pengaruh. Data dikirim dalam format:

```
asal tujuan skor_pengaruh
```

---

### 🎯 Tugasmu:

1. Untuk setiap kota, hitung **total pengaruh yang masuk** (diterima dari kota lain).
    
2. Cetak kota-kota yang menerima **pengaruh tertinggi**.
    
3. Jika ada lebih dari satu kota dengan nilai tertinggi, tampilkan semuanya, **urutkan leksikografis**.
    

---

### 🧪 Contoh Input:

```
8
Alpha Beta 50
Gamma Alpha 70
Beta Alpha 30
Delta Beta 50
Alpha Gamma 40
Gamma Delta 50
Beta Gamma 60
Delta Alpha 30
```

### 📤 Contoh Output:

```
Alpha
```

→ Karena `Alpha` menerima:

- dari `Gamma`: 70
    
- dari `Beta`: 30
    
- dari `Delta`: 30  
    **Total = 130** (paling tinggi)
    

---

### 💡 Petunjuk:

- Gunakan `map<string, int>` untuk menyimpan **pengaruh masuk** tiap kota.
    
- Abaikan `asal` sebagai penerima — hanya `tujuan` yang menerima poin.
    
- Setelah input selesai, cari nilai maksimal dan tampilkan kota-kota yang memiliki nilai tersebut.
    

---

Apakah tantangan seperti ini lebih menarik? Kalau kamu suka, aku bisa bikin variasi game-war semacam ini lebih banyak 🔥

## Jawabanku
Berikut adalah jawabaku yang sudah berna dan optimal:

```cpp
#include<iostream>
#include<map>
#include<climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> dasmap;
    int n; cin >> n;

    while(n--){
        string a, b; int x;
        cin >> a >> b >> x;
        
        dasmap[b]+=x;
    }
    
    int maks=INT_MIN;
    for(const auto& [key, val]: dasmap){
        if(maks<val) maks=val;
    }

    for(const auto&[key, val]: dasmap){
        if(val==maks){
            cout << key << endl;
        }
    }
    return 0;
}
```

# Editorial
🚀 **Keren! Jawabanmu untuk Soal 14 versi "Perang Pengaruh Antar Kota" sudah 100% benar!**

---

### ✅ Yang Sudah Tepat:

|Komponen|Status|Penjelasan|
|---|---|---|
|Menyimpan total pengaruh masuk|✅|`dasmap[b] += x;` menghitung pengaruh yang diterima oleh kota `b`|
|Mencari nilai maksimum global|✅|`maks = max(maks, val);` (dalam bentuk manual)|
|Mencetak semua kota dengan pengaruh maksimum|✅|Diperiksa ulang dan dicetak sesuai|
|Urutan leksikografis|✅|Karena pakai `std::map`, otomatis urut|

---

### 🧪 Uji Input:

```
8
Alpha Beta 50
Gamma Alpha 70
Beta Alpha 30
Delta Beta 50
Alpha Gamma 40
Gamma Delta 50
Beta Gamma 60
Delta Alpha 30
```

### 📊 Perhitungan:

|Kota|Pengaruh Masuk|
|---|---|
|Alpha|70 + 30 + 30 = 130 ✅|
|Beta|50 + 50 = 100|
|Gamma|40 + 60 = 100|
|Delta|50|

Jadi, output:

```
Alpha
```

✅ Sesuai 100%

---

### 🌟 Saran Kecil (Opsional):

Untuk meningkatkan gaya dan keamanan:

```cpp
int maks = INT_MIN;
// bisa diganti:
int maks = 0; // jika diasumsikan skor pengaruh selalu non-negatif
```

---

Kalau kamu menikmati soal semacam ini, aku bisa terus lanjut dengan **konsep dominasi wilayah, pengaruh terbalik, konflik terkuat, jaringan mata-mata**, dan lainnya — semua berbasis struktur data.

Siap untuk **Soal 15: Kota yang Paling Banyak Menyebarkan Pengaruh** (versi pembalikan dari ini)?