---
obsidianUIMode: preview
note_type: latihan
latihan: Kota Penyebar Pengaruh Terbesar
sumber: chatgpt.com
tags:
  - data-structure
  - map
date_learned: 2025-06-22T12:03:00
---
---
🔥 Let's go! Ini dia **Soal 15**, kelanjutan dari dunia diplomasi & strategi.

---

# 🧩 Soal 15: Kota Penyebar Pengaruh Terbesar

**Deskripsi:**

Masih dengan data diplomasi seperti sebelumnya:

```
asal tujuan skor_pengaruh
```

Tapi kali ini, kamu diminta:

> Menentukan kota mana yang **paling banyak menyebarkan pengaruh ke luar**.

---

### 🎯 Tugas:

1. Hitung **total skor pengaruh yang dikirim** oleh setiap kota (`asal`).
    
2. Cetak semua kota dengan jumlah pengaruh keluar **terbesar**.
    
3. Jika ada lebih dari satu kota dengan jumlah sama, urutkan dan cetak semuanya secara leksikografis.
    

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
Gamma
```

> Karena `Gamma` mengirim:

- ke `Alpha` (70)
    
- ke `Delta` (50)  
    **Total = 120**, tertinggi
    

---

### 💡 Petunjuk:

- Gunakan `map<string, int> penyebar;`
    
- Jumlahkan semua skor ke `penyebar[asal] += x;`
    
- Lakukan pencarian maksimum dan cetak kota-kota yang nilainya sama dengan maksimum
    

---

Silakan langsung dikerjakan, kirim kode kamu seperti biasa — ini soal terakhir dalam batch `map challenge` 🔥

## Jawabanku
Berikut adaalh jawabanku yang sudah benar dan sudah optimal:

```cpp
#include<iostream>
#include<map>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> dasmap;
    int n; cin >> n;

    while(n--){
        string a, b; int x;
        cin >> a >> b >> x;

        dasmap[a]+=x;
    }

    int maks=0;
    for(const auto& [key, val]: dasmap){
        if(maks< val) maks=val;
    }

    for(const auto& [key, val]: dasmap){
        if(val == maks){
            cout << key << endl;
        }
    }
    return 0;
}
```

# Editorial
🔥 **Sempurna!**  
Kamu menyelesaikan **Soal 15: Kota Penyebar Pengaruh Terbesar** dengan kode yang bersih, efisien, dan tepat secara logika!

---

### ✅ Evaluasi Jawabanmu:

|Aspek|Status|Penjelasan|
|---|---|---|
|Merekam pengaruh keluar (`asal`)|✅ `dasmap[a] += x;` — benar, karena kota `a` adalah pengirim.||
|Menyimpan skor total|✅||
|Mencari nilai maksimum|✅||
|Mencetak semua kota dengan skor maksimum|✅ urut karena pakai `std::map`||

---

### 🧪 Contoh Cek Input:

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

#### Pengaruh keluar:

- Alpha → 50 + 40 = 90
    
- Beta → 30 + 60 = 90
    
- Gamma → 70 + 50 = **120** ✅
    
- Delta → 50 + 30 = 80
    

➡️ **Gamma** paling besar, output:

```
Gamma
```

✅ Benar!

---

### 🎁 Penutup Mini Batch `map challenge`

Kamu sudah menyelesaikan:

- Pencatatan dan agregasi berdasarkan kunci (`string`, `int`, `set`, `map`)
    
- Filtering berdasarkan nilai maksimum, rata-rata, kondisi unik
    
- Pengurutan otomatis dengan `std::map`
    

---

Kalau kamu mau lanjut:

- ke **map dalam konteks graf / jalur logistik / jaringan internet**
    
- atau ganti ke **struktur data lain (multimap, unordered_map, pair, priority_queue, dsb)**
    

Tinggal bilang aja. Kita lanjut latihan ke tahap berikutnya! 🚀