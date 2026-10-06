---
obsidianUIMode: preview
note_type: latihan
latihan: Cari Kontak
sumber: Google.com, AI
tags:
  - data-structure
  - unordered_map
date_learned: 2025-06-16T18:18:00
---
---
Mantap, kita masuk ke **Soal ke-6**, dan kali ini kita akan fokus pada fungsi **`unordered_map::find()`**.  

Soal ini akan membiasakanmu membedakan antara `find()` dan `count()` serta penggunaannya untuk mencari key dan akses nilai dengan aman.

---

# 🧠 Soal 6: Cari Kontak

Kamu akan membuat sistem pencarian kontak. Setiap kontak memiliki:

- Nama (`string`)
    
- Nomor telepon (`string`)
    

Kamu harus:

1. Menyimpan semua data ke dalam `unordered_map<string, string>`.
    
2. Menerima beberapa query pencarian nama kontak.
    
3. Jika kontak ditemukan, tampilkan nomornya.
    
4. Jika tidak, tampilkan `"Kontak tidak ditemukan"`.
    

---

### 💡 Format Input

```
n
<nama_1> <nomor_1>
<nama_2> <nomor_2>
...
<nama_n> <nomor_n>
q
<query_1>
<query_2>
...
<query_q>
```

---

### 📤 Contoh Input

```
3
andi 08123456789
budi 08561234567
citra 08219876543
2
budi
eko
```

---

### 📥 Contoh Output

```
08561234567
Kontak tidak ditemukan
```

---

### 🎯 Tujuan Pembelajaran

- Belajar menggunakan `unordered_map::find()` untuk akses aman.
    
- Mengetahui perbedaan `find()` dan `count()` dalam praktik.
    
- Menjaga efisiensi pencarian di struktur `unordered_map`.
    

---

Kalau kamu sudah siap, kerjakan dulu ya! Kalau mau minta bantuan atau butuh penjelasan bedanya `find()` vs `count()`, tinggal bilang! 💪

## Jawabanku
Berikut adalah kode jawabanku:

```cpp
#include<iostream>
#include<unordered_map>
#include<sstream>
#include<iterator>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;

    unordered_map<string,string> kontak;
    if(n>10000){
        kontak.max_load_factor(0.5f);
        kontak.reserve(2 * n);
    } else {
        kontak.reserve(n);
    }

    string s;
    while(n--){
        getline(cin >> ws, s);
        stringstream ss(s);

        string name, no;
        ss >> name >> no;

        kontak.insert_or_assign(name, no);
    }

    cin >> n;
    while(n--){
        getline(cin >> ws, s);
        if(kontak.find(s) != kontak.end()){
            cout << kontak.at(s) << "\n";
        } else {
            cout << "Kontak tidak ditemukan\n";
        }
    
    }
    return 0;
}
```

# Editorial

✅ Jawabanmu **sudah sangat bagus dan efisien** — benar-benar menunjukkan pemahaman tentang `unordered_map`, terutama penggunaan `find()` dan `insert_or_assign()`! Sekarang mari kita review secara sistematis supaya kamu bisa simpan di catatanmu:

---

## 📝 Review Jawaban - Soal 6: Cari Kontak

### 🔧 Struktur Data & Setup

- Kamu menggunakan `unordered_map<string, string>` untuk menyimpan kontak: ✔️
    
- Pakai `max_load_factor` dan `reserve()` agar performa optimal saat input besar: ✔️ (ini jarang dipakai tapi menunjukkan perhatian pada efisiensi — mantap!)
    
- Gunakan `insert_or_assign` untuk memastikan kalau kontak lama di-_overwrite_ dengan nomor baru: ✔️ (lebih baik dari `insert()` kalau datanya bisa berubah)
    

```cpp
if(n>10000){
    kontak.max_load_factor(0.5f);
    kontak.reserve(2 * n);
} else {
    kontak.reserve(n);
}
```

### 🔍 Pencarian Kontak

- Kamu pakai `find()` untuk memeriksa apakah nama ada di map, **bukan langsung pakai `[]` atau `at()` saja** — ini sangat penting agar tidak memaksa `unordered_map` membuat key baru jika tidak ada: ✔️
    
- Setelah `find()`, kamu ambil nilai pakai `at()` → ini _clean_, karena `at()` akan melempar exception jika tidak ditemukan, tapi kamu sudah aman karena pakai `find()` dulu.
    

```cpp
if(kontak.find(s) != kontak.end()){
    cout << kontak.at(s) << "\n";
} else {
    cout << "Kontak tidak ditemukan\n";
}
```

---

### ✨ Bonus: Kenapa `find()` Lebih Aman?

Jika kamu pakai `kontak[s]` tanpa cek, maka:

- Jika `s` belum ada di map, `unordered_map` akan otomatis **menambahkan entri baru dengan nilai default** (`""` untuk `string`).
    
- Ini bisa menimbulkan **bug tersembunyi** dalam sistem pencatatan.
    

---

### 📥 Contoh Output dari Input

**Input:**

```
3
andi 08123456789
budi 08561234567
citra 08219876543
2
budi
eko
```

**Output:**

```
08561234567
Kontak tidak ditemukan
```

✅ Output ini **tepat** dan urutannya sesuai input.

---

## 💯 Nilai: **10/10**

Sudah optimal, rapi, idiomatik, dan scalable. Tinggal kamu salin ke Obsidian dan beri label misalnya:

> `"Penggunaan find() + insert_or_assign() dalam unordered_map"`

---

Kalau sudah siap, kita gas ke **Soal ke-7** dengan fungsi baru dari `unordered_map`. Mau lanjut?