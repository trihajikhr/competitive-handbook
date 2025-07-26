---
obsidianUIMode: preview
note_type: latihan
latihan: Cetak Siswa dengan Nilai di Atas Ambang
sumber: chatgpt.com
tags:
  - data-structure
  - map
date_learned: 2025-06-21T23:30:00
---
---
# 🧩 Soal 11: Cetak Siswa dengan Nilai di Atas Ambang

**Deskripsi:**

Kamu diberikan `n` baris data, masing-masing berisi:

- `nama_kelas`
    
- `nama_siswa`
    
- `nilai` (integer)
    

Tugasmu:

1. Simpan hanya **nilai terakhir** per siswa dalam tiap kelas (sama seperti Soal 10).
    
2. Lalu, diberikan **nilai ambang batas** `t`.
    
3. Cetak **nama kelas** dan seluruh siswa yang memiliki nilai **lebih besar dari `t`**.
    
4. Tampilkan dalam urutan nama kelas leksikografis, dan di dalamnya urutkan nama siswa juga secara leksikografis.
    

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
80
```

### 📤 Contoh Output:

```
XIIA:
  Andi
XIIB:
  Budi
  Dinda
XIIC:
  Farhan
```

---

### 💡 Petunjuk:

- Gunakan `map<string, map<string, int>>` untuk menyimpan nilai akhir.
    
- Gunakan `cin >> t;` setelah input data siswa.
    
- Iterasi setiap kelas → filter siswa dengan nilai > `t`.
    
- Cetak kelas hanya jika ada siswa yang memenuhi syarat.
    
- Gunakan `std::map` agar urutan tetap terjaga (kelas & siswa).
    

---

Silakan dikerjakan! Kirim hasilnya jika sudah, kita evaluasi bareng seperti biasa 👊

## Jawabanku
Berikut adalah jawabanku yang sudah dioptimalkan:

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

        dasmap[a][b]=x;
    }

    int t; cin >> t;

    for(const auto& [key, val] : dasmap){
        bool firstTime=true;
        for(const auto& [inkey, inval]: val){
            if(inval>t){
                if(firstTime){
                    cout << key << ":\n";
                    firstTime=false;
                }
                cout << "  " << inkey << "\n";
            }
        }
    }
    return 0;
}
```

# Editorial
🎯 **Sempurna!**  
Kamu berhasil menyelesaikan **Soal 11** dengan sangat baik. Semua poin penting sudah dipenuhi:

---

### ✅ Ceklist Kebenaran:

|Fitur|Status|Penjelasan|
|---|---|---|
|Menyimpan nilai terakhir per siswa|✅|`dasmap[a][b] = x` sudah tepat — menimpa nilai sebelumnya.|
|Menerima ambang batas `t` setelah data|✅|`cin >> t` dilakukan setelah data siswa selesai.|
|Menampilkan hanya siswa dengan nilai > `t`|✅|`if (inval > t)` benar.|
|Mencetak nama kelas hanya jika ada siswa yang lolos|✅|Dikelola dengan flag `firstTime`.|
|Format output terjaga|✅|`" " << inkey` sudah sesuai indentasi.|
|Kelas & siswa terurut otomatis|✅|Karena pakai `std::map`.|

---

### 🧪 Contoh Uji:

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
80
```

#### Output:

```
XIIA:
  Andi
XIIB:
  Budi
  Dinda
XIIC:
  Farhan
```

✅ **Sesuai 100%**

---

### 🧠 Bonus:

Penggunaan `firstTime` untuk kontrol pencetakan header kelas = **cara yang elegan dan efisien**.

---

Kalau kamu siap, **Soal 12** akan melibatkan:

- Pencarian global siswa dengan **nilai tertinggi**
    
- Dari seluruh kelas dan siswa
    
- Cetak: nama_kelas dan nama_siswa
    

Siap?