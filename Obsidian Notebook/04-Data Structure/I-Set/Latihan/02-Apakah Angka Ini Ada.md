---
obsidianUIMode: preview
note_type: latihan
latihan: Apakah Angka Ini Ada
sumber: chatgpt.com
tags:
  - data-structure
  - set
date_learned: 2025-06-20T20:54:00
---
---
🔥 Sip, kita lanjut ke **Latihan 2: Mengenal `find()` di `std::set`**  
Fokus soal ini adalah **mencari elemen di dalam set** menggunakan fungsi `find()`.

---

# 🧩 Latihan 2 — Apakah Angka Ini Ada?

**Deskripsi Soal:**

Diberikan `n` bilangan bulat dan sebuah bilangan target `x`. Tugasmu adalah menentukan apakah `x` terdapat di dalam kumpulan bilangan tersebut atau tidak, **menggunakan `std::set` dan fungsi `find()`**.

---

**Input Format:**

- Baris pertama: bilangan bulat `n` (1 ≤ n ≤ 100)
    
- Baris kedua: `n` bilangan bulat, masing-masing antara 1 hingga 1000
    
- Baris ketiga: bilangan bulat `x`, angka yang ingin dicari
    

**Output Format:**

- Jika `x` ditemukan di dalam set, cetak: `Ditemukan`
    
- Jika tidak ditemukan, cetak: `Tidak ditemukan`
    

---

**Contoh Input 1:**

```
6
10 20 30 40 50 60
40
```

**Contoh Output 1:**

```
Ditemukan
```

**Contoh Input 2:**

```
4
5 10 15 20
7
```

**Contoh Output 2:**

```
Tidak ditemukan
```

---

🧠 **Panduan:**

- Gunakan `find(x)` untuk mendapatkan iterator ke elemen.
    
- Bandingkan hasilnya dengan `end()` untuk mengetahui apakah elemen tersebut ada.
    

Kalau sudah selesai, kirimkan kodenya seperti biasa. Kalau kamu ingin petunjuk, tinggal bilang saja! 💪

# Jawaban
#### Jawaban yang masih belum benar
Berikut adalah jawaban yang masih memiliki kesahalah, karena tidak menggunakan fungsi `find()` milik `set`:

```cpp
#include<iostream>
#include<set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    set<int> daset;

    for(int i=0, x; i<n; i++){
        cin >> x;
        daset.insert(x);
    }

    int x; cin >> x;

    auto it = find(daset.begin(), daset.end(), x);
    if(it != daset.end()){
        cout << "Ditemukan\n";
    } else {
        cout << "Tidak ditemukan\n";
    }
    return 0;
}
```

#### Jawaban yang benar sesuai editorial
Berikut jawaban yang sesuai:

```cpp
#include<iostream>
#include<set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    set<int> daset;

    for(int i=0, x; i<n; i++){
        cin >> x;
        daset.insert(x);
    }

    int x; cin >> x;

    auto it = daset.find(x);
    if(it != daset.end()){
        cout << "Ditemukan\n";
    } else {
        cout << "Tidak ditemukan\n";
    }
    return 0;
}
```

# Editorial
⚠️ Kamu **nyaris benar**, tapi ada **satu hal penting yang perlu diperbaiki**:

---

### ❗ Kesalahan Kecil:

Kamu menggunakan:

```cpp
auto it = find(daset.begin(), daset.end(), x);
```

Ini akan bekerja **dengan benar**, _tapi_ kamu sedang memakai **fungsi `std::find()` dari `<algorithm>`**, bukan `std::set::find()`.

Padahal, tujuan soal ini adalah **melatih penggunaan fungsi anggota `find()` milik `std::set`**, yaitu:

```cpp
auto it = daset.find(x);  // ✅ lebih efisien
```

---

### 🔍 Kenapa penting?

- `std::set::find()` berjalan dalam **O(log n)** waktu karena menggunakan struktur pohon (Red-Black Tree)
    
- `std::find()` dari `<algorithm>` bekerja dalam **O(n)** waktu karena sekadar linear scan
    

---

### ✅ Perbaikan Kode:

Cukup ubah baris pencarian:

```cpp
auto it = daset.find(x); // GANTI dari std::find ke set::find
```

---

### 💯 Dengan perbaikan ini, kode kamu:

- Sudah efisien
    
- Sudah benar sesuai tujuan latihan
    
- Output akan tetap sama:
    
    - Jika elemen ditemukan → `"Ditemukan"`
        
    - Jika tidak ditemukan → `"Tidak ditemukan"`
        

---

Kalau sudah paham, kita siap lanjut ke **Latihan 3: Menghapus elemen menggunakan `erase()`**.

Lanjut? 😎