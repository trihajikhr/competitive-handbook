---
obsidianUIMode: preview
note_type: latihan
latihan: Mendeteksi Kata Duplikat
sumber: chatgpt.com
tags:
  - data-structure
  - map
date_learned: 2025-06-21T19:21:00
---
---
# 🧩 Soal 4: Mendeteksi Kata Duplikat

**Deskripsi:**

Kamu diberikan `n` kata. Tugasmu adalah mencetak `"Ya"` jika **ada minimal satu kata yang muncul lebih dari sekali**, dan `"Tidak"` jika semua kata berbeda (unik).

Gunakan `std::map<string, int>` untuk melacak frekuensi kata.

---

### 🧪 Contoh Input 1:

```
5
apel jeruk pisang apel semangka
```

### 📤 Contoh Output 1:

```
Ya
```

---

### 🧪 Contoh Input 2:

```
4
nanas jeruk semangka mangga
```

### 📤 Contoh Output 2:

```
Tidak
```

---

### 💡 Petunjuk:

- Baca semua kata dan simpan frekuensinya.
    
- Jika ada nilai dalam map yang > 1, cetak `"Ya"`.
    
- Jika tidak ada yang duplikat, cetak `"Tidak"`.
    

---

Kalau sudah selesai, kirim jawabanmu dan kita bahas seperti biasa.

## Jawabanku
Berikut adalah jawabanku yang sudah benar:

```cpp
#include<iostream>
#include<map>
using namespace std;

int main() {
    map<string, int> dasmap;
    int n; cin >> n;
    string s;

    while(n--){
        cin >> s;
        dasmap[s]++;
    }

    bool duplikat=false;
    for(const auto& [key, val]: dasmap){
        if(val>1) {
            duplikat=true;
            break;
        }
    }

    cout << (duplikat ? "Ya" : "Tidak") << "\n";
    return 0;
}
```

# Editorial
🌟 **Sempurna lagi!**  
Kamu menyelesaikan Soal 4 **dengan sangat efisien dan rapi**. Tidak ada kesalahan. Berikut analisisnya:

---

### ✅ Yang Sudah Sangat Baik

|Aspek|Penjelasan|
|---|---|
|`dasmap[s]++`|Cepat dan otomatis menginisialisasi value jadi 1 kalau key baru muncul.|
|Loop `for (const auto& [key, val] : dasmap)`|Structured binding yang modern dan elegan.|
|Cek `if (val > 1)` dan `break`|Efisien — tidak perlu cek seluruh map jika sudah ketemu duplikat.|
|Output ternary `duplikat ? "Ya" : "Tidak"`|Ringkas dan jelas.|

---

### 🔁 Proses Singkat:

- Map menyimpan jumlah kemunculan setiap kata.
    
- Jika `val > 1` ditemukan, artinya ada duplikat.
    
- Output disesuaikan dengan hasil pemeriksaan.
    

---

### 🧪 Contoh Kasus:

#### Input:

```
6
apel jeruk semangka pisang apel jeruk
```

#### Map setelah pengisian:

```
apel: 2
jeruk: 2
semangka: 1
pisang: 1
```

-> `Ya`

---

Kalau sudah siap, yuk kita lanjut ke **Soal 5: Total Nilai Berdasarkan Kategori**, kali ini `map<string, int>` kita gunakan untuk menjumlahkan nilai-nilai berdasarkan kategori teks. Siap?