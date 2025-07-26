---
obsidianUIMode: preview
note_type: latihan
latihan: Rerata Nilai Terakhir per Siswa Unik per Kelas
sumber: chatgpt.com
tags:
  - data-structure
  - map
date_learned: 2025-06-21T23:19:00
---
---
# 🧩 Soal 10: Rerata Nilai Terakhir per Siswa Unik per Kelas

**Deskripsi:**

Diberikan `n` baris input, masing-masing berisi:

- `nama_kelas`
    
- `nama_siswa`
    
- `nilai` (integer)
    

Mungkin saja seorang siswa muncul **lebih dari satu kali dalam kelas yang sama**. Jika iya, **ambil nilai terakhirnya** (terakhir muncul dalam input).

Tugasmu adalah:

- Menyimpan **nilai terakhir tiap siswa dalam suatu kelas**
    
- Menghitung **rata-rata nilai** untuk tiap kelas (gunakan **pembulatan ke bawah** jika perlu).
    
- Cetak hasil dalam format:
    

```
nama_kelas rata_rata_nilai
```

Urutkan berdasarkan `nama_kelas` secara leksikografis.

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
XIIA 77
XIIB 90
XIIC 95
```

---

### 💡 Petunjuk:

- Gunakan:  
    `map<string, map<string, int>> kelas_ke_siswa_nilai;`
    
- Ambil nilai terakhir (overwrite saja jika muncul lagi).
    
- Untuk setiap kelas:
    
    - Jumlahkan nilai siswa
        
    - Bagi dengan jumlah siswa
        

---

Silakan kerjakan! Ini soal penting untuk menguasai nested `map` dan traversal yang efisien. Kalau sudah selesai, kirim hasilnya — kita review bersama.

## Jawabanku
Berikut adalah jawabanku yang sudah tepat dan sesuai:

```cpp
#include<iostream>
#include<map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, map<string, int>> dasmap;
    int n; cin >> n;
    
    string a, b; int nil;
    while(n--){
        cin >> a >> b >> nil;
        dasmap[a][b]=nil;
    }

    int avg=0;
    for(const auto& [key, val]: dasmap){
        cout << key << " ";
        for(const auto& [inkey, inval]: val){
            avg+=inval;
        }
        cout << avg/val.size() << "\n";
        avg=0;
    }
    return 0;
}
```

# Editorial
✅ **Jawabanmu sudah tepat dan fungsional!**  
Kamu telah:

- Menggunakan `map<string, map<string, int>>` untuk menyimpan nilai terakhir tiap siswa dalam kelas.
    
- Melakukan penghitungan rata-rata per kelas secara benar.
    
- Menampilkan hasil sesuai urutan nama kelas (leksikografis).
    

---

### 💡 Penjelasan Kode:

```cpp
map<string, map<string, int>> dasmap;
```

- Struktur ini menyimpan:  
    `kelas → (siswa → nilai terakhir)`
    

---

```cpp
dasmap[a][b] = nil;
```

- Menyimpan nilai siswa `b` dalam kelas `a`, dan otomatis **menimpa nilai sebelumnya** jika siswa yang sama muncul lagi — ini **tepat** untuk soal ini.
    

---

```cpp
for(const auto& [key, val] : dasmap) {
    ...
    for(const auto& [inkey, inval] : val) {
        avg += inval;
    }
    cout << key << " " << avg / val.size() << "\n";
    avg = 0;
}
```

- Iterasi setiap kelas.
    
- Menjumlahkan nilai semua siswa unik dalam kelas itu.
    
- Membagi dengan jumlah siswa untuk mendapat rata-rata.
    
- Reset `avg = 0` setelah tiap kelas — ini penting dan kamu sudah benar.
    

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

### 🧮 Map akhir:

- XIIA: Andi 85, Citra 70 → `(85 + 70) / 2 = 77`
    
- XIIB: Budi 92, Dinda 88 → `(92 + 88) / 2 = 90`
    
- XIIC: Farhan 95 → `95`
    

### 📤 Output:

```
XIIA 77  
XIIB 90  
XIIC 95
```

✅ **Sesuai 100%**

---

Siap lanjut ke **Soal 11**, yang akan menguji kemampuan kamu dalam **menyaring dan mencetak hanya siswa tertentu berdasarkan syarat nilai**?