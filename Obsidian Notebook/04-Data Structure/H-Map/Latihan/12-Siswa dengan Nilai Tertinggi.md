---
obsidianUIMode: preview
note_type: latihan
latihan: Siswa dengan Nilai Tertinggi
sumber: chatgpt.com
tags:
  - data-structure
  - map
date_learned: 2025-06-21T23:39:00
---
---
# 🧩 Soal 12: Siswa dengan Nilai Tertinggi

**Deskripsi:**

Kamu diberikan `n` baris input yang masing-masing berisi:

- `nama_kelas`
    
- `nama_siswa`
    
- `nilai` (integer)
    

Tugasmu:

1. Simpan **nilai terakhir** setiap siswa dalam kelas.
    
2. Cari **satu siswa dengan nilai tertinggi di seluruh data**.
    
3. Cetak `nama_kelas` dan `nama_siswa` dari siswa tersebut.
    

Jika ada lebih dari satu siswa dengan nilai tertinggi yang sama:

- Pilih siswa yang nama kelasnya lebih kecil secara leksikografis.
    
- Jika nama kelasnya sama, pilih siswa dengan nama yang lebih kecil.
    

---

### 🧪 Contoh Input:

```
8
XIIA Andi 80
XIIB Budi 90
XIIA Citra 75
XIIB Dinda 88
XIIA Andi 85
XIIC Farhan 95
XIIA Citra 70
XIIB Budi 92
```

### 📤 Contoh Output:

```
XIIC Farhan
```

---

### 💡 Petunjuk:

- Gunakan `map<string, map<string, int>>` seperti sebelumnya.
    
- Simpan nilai maksimum global dan identitas (kelas & nama siswa).
    
- Untuk tie-breaker: gunakan logika `(kelas < best_kelas || (kelas == best_kelas && siswa < best_siswa))`.
    

---

Siap? Silakan kerjakan! Kirim jawabannya kalau sudah selesai.

## Jawabanku
Walaupun sempat kesulitan, tapi ini  jawaban ini sudah optimal:

```cpp
#include<iostream>
#include<map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, map<string, int>> dasmap;
    int n; cin >> n;

    while(n--){
        string a,b; int x;
        cin >> a >> b >> x;

        dasmap[a][b] = x;
    }

    string kelas, nama;
    int maks=0;
    for(const auto& [key, val]: dasmap){
        for(const auto& [inkey, inval]: val){
            if(inval>maks){
                maks=inval;
                nama=inkey;
                kelas=key;
            } else if (inval==maks){
                if(key!=kelas){
                    if(key<kelas){
                        kelas=key;
                        nama=inkey;
                    }
                } else {
                    if(inkey<nama){
                        nama=inkey;
                        kelas=key;
                    }
                }
            }
        }
    }

    cout << kelas << " " << nama << "\n";
    return 0;
}
```

# Editorial
✅ **Top-notch!**  
Kamu menyelesaikan **Soal 12** dengan **logika yang benar**, **struktur data yang tepat**, dan **tie-breaker yang lengkap**. Ini sudah level mahir dalam traversal `nested map`.

---

### 🔍 Review Jawabanmu:

#### Struktur:

```cpp
map<string, map<string, int>> dasmap;
```

✅ Sangat tepat — menyimpan nilai terakhir tiap siswa di setiap kelas.

---

#### Proses pencarian maksimum:

```cpp
if (inval > maks) {
    ...
} else if (inval == maks) {
    ...
}
```

Tie-breaker sudah sangat lengkap:

|Kasus|Penanganan|
|---|---|
|Nilai lebih besar|Ganti semuanya ✅|
|Nilai sama, kelas lebih kecil|Ganti ✅|
|Nilai sama, kelas sama, nama lebih kecil|Ganti ✅|

---

### 🔢 Contoh Uji:

#### Input:

```
8
XIIA Andi 80
XIIB Budi 90
XIIA Citra 75
XIIB Dinda 88
XIIA Andi 85
XIIC Farhan 95
XIIA Citra 70
XIIB Budi 92
```

- Budi muncul dua kali, tapi nilai terakhirnya = 92.
    
- Farhan = 95 → lebih tinggi dari semua → ✅
    

#### Output:

```
XIIC Farhan
```

✅ **Benar dan sesuai!**

---

### 🧠 Catatan Tambahan:

- Inisialisasi `maks = 0` bisa kamu ganti dengan `int maks = INT_MIN;` agar aman terhadap kasus nilai negatif (jika nanti soal diperluas).
    

---

Kalau kamu sudah siap, kita bisa lanjut ke **Soal 13**, di mana kamu akan diminta mencari **semua siswa yang nilai akhirnya sama persis dengan rata-rata kelas mereka**. Siap?