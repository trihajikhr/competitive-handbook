---
obsidianUIMode: preview
note_type: latihan
latihan: Jumlah Siswa Unik per Kelas
sumber: chatgpt.com
tags:
  - data-structure
  - set
date_learned: 2025-06-21T23:12:00
---
---
# 🧩 Soal 9: Jumlah Siswa Unik per Kelas

**Deskripsi:**

Diberikan `n` baris input berupa `nama_kelas` dan `nama_siswa`.  
Tapi kali ini, bisa saja **nama siswa yang sama muncul lebih dari sekali dalam kelas yang sama**.

Tugasmu adalah menghitung **jumlah siswa unik** di setiap kelas.  
Cetak hasilnya dalam format:

```
nama_kelas jumlah_siswa_unik
```

Urutkan hasil berdasarkan **nama_kelas** secara leksikografis.

---

### 🧪 Contoh Input:

```
8
XIIA Andi
XIIB Budi
XIIA Citra
XIIB Dinda
XIIA Andi
XIIC Farhan
XIIA Citra
XIIB Budi
```

### 📤 Contoh Output:

```
XIIA 2
XIIB 2
XIIC 1
```

---

### 💡 Petunjuk:

- Gunakan struktur data:  
    `map<string, set<string>> kelas_ke_siswa`
    
- Karena `set` otomatis menyimpan elemen **unik**, siswa yang sama dalam satu kelas tidak akan dihitung ganda.
    
- Jumlah siswa unik dalam satu kelas = `kelas_ke_siswa[kelas].size()`
    

---

Silakan dikerjakan, dan kirim hasilmu kalau sudah. Ini soal penting untuk memahami **nested map & set** dalam konteks nyata 👊

## Jawabanku
Berikut adalah jawabanku untuk soal ini:

```cpp
#include<iostream>
#include<set>
#include<map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, set<string>> dasmap;
    int n; cin >> n;

    while(n--){
        string s,x;
        cin >> s >> x;

        dasmap[s].insert(x);
    }

    for(const auto & [key, val] : dasmap){
        cout << key << " " << val.size() << "\n";
    }
    return 0;
}
```

# Editorial
🔥 **Luar biasa!**  
Kamu berhasil menyelesaikan **Soal 9** dengan **struktur data yang tepat**, kode yang ringkas, dan hasil yang akurat.

---

### ✅ Penilaian Kode:

|Aspek|Penjelasan|
|---|---|
|`map<string, set<string>>`|Tepat untuk menyimpan banyak nama unik per kelas.|
|`dasmap[s].insert(x)`|Memastikan nama siswa yang sama **tidak dihitung dua kali**.|
|`val.size()`|Menghitung jumlah siswa unik per kelas dengan efisien.|
|Output sesuai urutan key|Karena `map` menyimpan berdasarkan urutan leksikografis otomatis.|

---

### 🧪 Contoh Uji:

#### Input:

```
8
XIIA Andi
XIIB Budi
XIIA Citra
XIIB Dinda
XIIA Andi
XIIC Farhan
XIIA Citra
XIIB Budi
```

#### Output:

```
XIIA 2
XIIB 2
XIIC 1
```

✅ **Sesuai ekspektasi 100%**
