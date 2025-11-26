---
obsidianUIMode: preview
note_type: latihan
latihan: Jumlah Siswa per Kelas
sumber: chatgpt.com
tags:
  - data-structure
  - map
date_learned: 2025-06-21T19:46:00
---
---
# 🧩 Soal 7: Jumlah Siswa per Kelas

**Deskripsi:**

Diberikan data siswa dalam format `nama_kelas` dan `nama_siswa`, sebanyak `n` baris.  
Tugasmu adalah menghitung berapa banyak siswa di setiap kelas.

Cetak jumlah siswa untuk setiap kelas berdasarkan urutan nama kelas (leksikografis).

---

### 🧪 Contoh Input:

```
6
XIIA Andi
XIIB Budi
XIIA Citra
XIIB Dinda
XIIA Eka
XIIC Farhan
```

### 📤 Contoh Output:

```
XIIA 3
XIIB 2
XIIC 1
```

---

### 💡 Petunjuk:

- Gunakan `map<string, int>` untuk menyimpan jumlah siswa per kelas.
    
- Input terdiri dari `n` baris, masing-masing `kelas` dan `nama`.
    
- `nama` tidak digunakan dalam penghitungan, cukup `kelas`.
    

---

Kalau sudah selesai, kirim jawabannya ya. Kita bahas dan lanjut ke tantangan selanjutnya!

## Jawabanku
Berikut adalah jawabanku yang sudah optimal:

```cpp
#include<iostream>
#include<map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> dasmap;
    int n; string s, x;
    cin >> n;

    while(n--){
        cin >> s >> x;
        dasmap[s]++;
    }

    for(const auto& [key, val]:dasmap){
        cout << key << " " << val << "\n";
    }
    return 0;
}
```

# Editorial
✅ **Sangat tepat!**  
Jawabanmu untuk Soal 7 **benar, efisien, dan bersih secara sintaksis**. Ini implementasi yang ideal untuk menghitung jumlah siswa per kelas.

---

### 💡 Penjelasan:

```cpp
cin >> s >> x;
dasmap[s]++;
```

- `s` = nama kelas
    
- `x` = nama siswa (tidak perlu disimpan)
    
- `dasmap[s]++` akan otomatis membuat entry baru untuk kelas jika belum ada, lalu menaikkan jumlahnya satu per siswa.
    

---

### 🧪 Uji Kasus:

#### Input:

```
6
XIIA Andi
XIIB Budi
XIIA Citra
XIIB Dinda
XIIA Eka
XIIC Farhan
```

#### Output:

```
XIIA 3
XIIB 2
XIIC 1
```

✅ **Sesuai 100%**

---

### 🔍 Catatan Kecil:

- Kamu sudah menggunakan `ios::sync_with_stdio(false);` dan `cin.tie(nullptr);` — bagus untuk efisiensi input.
    
- `auto& [key, val]` membuat kode sangat clean dan idiomatik.
    

---

Kalau siap, kita lanjut ke **Soal 8: Membalik Map (jumlah → daftar kelas)**. Kali ini, kamu akan belajar membuat `map<int, vector<string>>`. Siap?