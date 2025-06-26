---
obsidianUIMode: preview
note_type: latihan
latihan: Filter Nilai di Bawah KKM
sumber: Google.com, AI
tags:
  - data-structure
  - unordered_map
date_learned: 2025-06-16T15:01:00
---
---
### 🔧 Fungsi Baru: `.erase(key)`

Digunakan untuk **menghapus elemen** dari map berdasarkan key.

---

# 🧠 Soal 4: Filter Nilai di Bawah KKM

Kamu diberikan daftar siswa beserta nilainya. Semua nilai yang **di bawah KKM** harus dihapus dari map.  

Setelah itu, tampilkan daftar siswa yang **lolos KKM** (yaitu nilainya **>= KKM**) secara **urut sesuai input awal**.

---

### 📥 Input Format:

- Baris pertama: integer `n` (jumlah siswa)
    
- Baris kedua: integer `kkm` (nilai batas minimal)
    
- `n` baris berikutnya: nama dan nilai (string dan int)
    

### 📤 Output:

- Tampilkan semua siswa yang **lulus** (nilai ≥ kkm), dalam urutan input.
    
- Format: `Nama : Nilai`
    
- Jika tidak ada yang lulus, cetak `"Tidak ada yang lulus"`
    

---

### 🧪 Contoh Input:

```
5
75
Alya 90
Budi 70
Cinta 85
Dino 40
Eka 76
```

### ✅ Output:

```
Alya : 90
Cinta : 85
Eka : 76
```

---

### ⚠️ Catatan:

- Gunakan `unordered_map<string, int>` untuk menyimpan data siswa.
    
- Gunakan `erase()` untuk menghapus siswa dengan nilai di bawah KKM.
    
- Gunakan `vector<string>` untuk menjaga **urutan input**, karena `unordered_map` tidak menyimpan urutan.
    

---

Siap tantangannya? Kirim solusimu kalau sudah! 🚀

## Jawabanku
Berikut jawabanku yang masih memiliki kesalahan fatal

```cpp
#include<iostream>
#include<sstream>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
    int n; cin >> n;
    int k; cin >> k;
    vector<string> user;
    unordered_map<string, int> report;
    report.reserve(n);

    while(n--){
        string s;
        getline(cin >> ws, s);

        stringstream ss(s);
        string name; int nilai;
        ss >> name >> nilai;
        
        report.insert({name, nilai});
        if(nilai>=k){
            user.push_back(name);
        }
    }

    for(auto& [key, value]: report){
        if(value<k) report.erase(key);
    }

    for(const auto&x:user){
        cout << x << ": " << report[x] << "\n";
    }
    return 0;
}
```

### Jawaban yang baik dan benar
Dan berikut adalah jawaban yang sudah diperbaiki

# Editorial dan Jawaban yang lebih baik
Solusi kamu hampir benar dan **logikanya sudah tepat**, tapi ada satu **bug fatal** yang bisa menyebabkan crash (segmentation fault atau undefined behavior):

---

## ⚠️ Kesalahan Fatal:

Kamu menghapus elemen (`erase`) dari `unordered_map` saat sedang men-`iterate` langsung ke map itu sendiri.

```cpp
for(auto& [key, value]: report){
    if(value<k) report.erase(key);  // ❌ Salah besar
}
```

⛔ Ini adalah **undefined behavior** — karena kamu **mengubah ukuran container** (`report`) saat sedang looping langsung ke dalamnya.

---

## ✅ Cara Aman untuk Erase:

Gunakan iterator manual, **bukan range-based loop**. Berikut bentuk yang benar:

```cpp
for (auto it = report.begin(); it != report.end(); ) {
    if (it->second < k)
        it = report.erase(it);  // erase() mengembalikan iterator baru yang valid
    else
        ++it;
}
```

---

## 🎯 Versi Final yang Sudah Diperbaiki:

```cpp
#include<iostream>
#include<sstream>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
    int n; cin >> n;
    int k; cin >> k;
    vector<string> user;
    unordered_map<string, int> report;
    report.reserve(n);

    while(n--){
        string s;
        getline(cin >> ws, s);

        stringstream ss(s);
        string name; int nilai;
        ss >> name >> nilai;
        
        report[name] = nilai;
        user.push_back(name);
    }

    // Hapus semua yang nilai < k
    for (auto it = report.begin(); it != report.end(); ) {
        if (it->second < k)
            it = report.erase(it);
        else
            ++it;
    }

    // Output yang lulus
    bool found = false;
    for(const auto& name : user){
        if(report.count(name)){
            cout << name << ": " << report[name] << "\n";
            found = true;
        }
    }

    if(!found){
        cout << "Tidak ada yang lulus\n";
    }

    return 0;
}
```

---

## 💯 Penilaian Akhir:

|Aspek|Nilai|Catatan|
|---|---|---|
|Logika & Tujuan|✅|Sudah benar sesuai permintaan|
|Urutan Output Terjaga|✅|Disimpan lewat `vector<string>`|
|Pemakaian `.erase()`|⚠️|Digunakan tapi dengan cara yang salah (harus diperbaiki)|
|Efisiensi & Clean Code|✅|Sudah cukup efisien dan mudah dibaca|

### 🎓 Nilai Akhir: **85 / 100**

Kalau kamu revisi jadi pakai `iterator` waktu `erase`, langsung naik ke **100 / 100**.

---

Siap lanjut ke **Soal 5** yang akan mengenalkan `count()` untuk mengecek keberadaan key?
# Jawaban perbaikan

Berikut adalah jawaban yang sudah diperbaiki:

```cpp
#include<iostream>
#include<sstream>
#include<vector>
#include<unordered_map>
#include<iterator>
using namespace std;

int main() {
    int n; cin >> n;
    int k; cin >> k;
    vector<string> user;
    unordered_map<string, int> report;
    report.reserve(n);

    while(n--){
        string s;
        getline(cin >> ws, s);

        stringstream ss(s);
        string name; int nilai;
        ss >> name >> nilai;
        
        report.insert({name, nilai});
        if(nilai>=k){
            user.push_back(name);
        }
    }

    unordered_map<string, int>::iterator iter;
    for(auto iter = report.begin(); iter != report.end(); ){
        if(iter->second < k){
            iter = report.erase(iter);
        } else {
            iter++;
        }
    }

    bool found = false;
    for(const auto& x : user){
        if(report.count(x)){
            cout << x << ": " << report[x] << "\n";
            found = true;
        }
    }
    if(!found){
        cout << "Tidak ada yang lulus\n";
    }
    return 0;
}
```
# Terkait pentingnya iterator

> Tunggu, emang apa kegunaan dari iterator? Dan kenapa lebih baik menggunakan iterator?

Pertanyaanmu luar biasa penting untuk pemahaman struktur data modern seperti `unordered_map`!

Mari kita bahas secara **konsep dasar dulu**, lalu **praktisnya di C++**, khususnya kenapa **`iterator` sangat penting dan lebih baik** untuk kasus seperti `erase()`.

---

## 🧠 Apa Itu Iterator?

> 🔁 **Iterator** adalah _"penunjuk"_ ke elemen dalam container STL (seperti `vector`, `map`, `unordered_map`), yang bisa kamu pakai untuk:

- Membaca atau memodifikasi elemen.
    
- Bergerak ke elemen berikutnya.
    
- **Menghapus elemen saat sedang iterasi**.
    

Mirip seperti pointer, tapi disesuaikan dengan tipe container.

---

## 💥 Masalah dengan Loop `range-based for`

```cpp
for (auto& [key, value] : report) {
    if (value < k) {
        report.erase(key);  // ❌ Undefined behavior
    }
}
```

Kenapa ini salah?

- Karena kamu **ubah ukuran map** (`erase`) **sambil** loop sedang **pakai internal iterator**.
    
- STL tidak menjamin loop itu akan tetap valid — **bisa crash atau hasil aneh**.
    

---

## ✅ Kenapa `iterator` Lebih Aman?

```cpp
for (auto it = report.begin(); it != report.end(); ) {
    if (it->second < k) {
        it = report.erase(it);  // ✅ valid dan aman
    } else {
        ++it;
    }
}
```

- `erase(it)` akan **menghapus** elemen di posisi `it`, dan **mengembalikan iterator baru** ke elemen berikutnya.
    
- Ini membuat loop tetap konsisten dan stabil meskipun kita ubah isi container.
    

---

## 🔍 Kapan Harus Pakai Iterator?

|Situasi|Gunakan Iterator?|
|---|---|
|Looping biasa tanpa hapus/tambah|❌ Tidak wajib|
|Ingin menghapus (`erase`) saat looping|✅ **WAJIB**|
|Ingin mengakses elemen dan posisinya|✅ Disarankan|
|Looping sambil `insert` ke container|✅ Iterator & hati-hati|

---

## 🧠 Analogi:

> Kamu sedang jalan menyusuri barisan meja di kelas. Kalau kamu mau **menghapus meja** sambil jalan, kamu harus tahu posisi sekarang, dan **lompat ke meja berikutnya setelah penghapusan**.  
> Kalau kamu pakai sistem otomatis (seperti `range-based loop`), sistem jadi bingung:  
> “Loh, mana mejanya tadi? Kok jumlahnya berubah?”

---

## ✍️ Singkatnya:

> **Gunakan iterator jika kamu ingin _modifikasi struktur_ (hapus/tambah) sambil iterasi.**

Tanpa iterator, kamu sedang main api 🔥 dengan container STL, dan bisa menyebabkan crash, bug, atau output aneh.

---

Kalau kamu mau, aku bisa buatin rangkuman `Cheat Sheet: Penggunaan Iterator di STL C++` juga nanti! Mau?

# Tambahan tentang iterator
> Bentar bentar, berarti, metode iterasi dari stl semcam itu, bagusnya adalah pakai iterator? karena lebih aman?

Yesss, kamu **nangkep intinya dengan tepat!** 🙌

---

## 🧠 Jawaban Singkat:

> **Ya, semua iterasi STL (seperti `unordered_map`, `vector`, `set`, dll)** sebaiknya pakai **`iterator` langsung jika kamu berencana memodifikasi container-nya** (hapus/tambah elemen), karena itu **lebih aman dan stabil.**

---

## ⚠️ Kenapa Gak Aman Pakai `range-based for`?

```cpp
for (auto& [key, value] : mymap) {
    if (value < 10) {
        mymap.erase(key); // ❌ Bahaya
    }
}
```

- Ini **bisa menyebabkan crash**, atau hasil aneh karena internal iterator STL tidak mengizinkan modifikasi ukuran saat sedang dipakai loop.
    

---

## ✅ Aman: Pakai Iterator

```cpp
for (auto it = mymap.begin(); it != mymap.end(); ) {
    if (it->second < 10) {
        it = mymap.erase(it);  // aman: erase mengembalikan iterator baru
    } else {
        ++it;
    }
}
```

- Kamu **kontrol penuh** iterasinya.
    
- STL `erase()` di map/unordered_map/set akan mengembalikan iterator ke elemen **setelah** yang dihapus.
    

---

## 🔍 Perbandingan Jenis Iterasi:

|Jenis Loop|Modifikasi Aman?|Cocok untuk|
|---|---|---|
|`range-based for`|❌ Tidak aman|Baca-only|
|`for (auto it = ...)`|✅ Aman|Hapus atau ubah saat iterasi|
|`for_each` + lambda|❌ Tidak aman|Baca saja|
|`while (it != end)`|✅ Aman|Modifikasi aman|

---

## 🧠 Analogi:

> Bayangin kamu lagi lewat satu per satu kursi penonton di stadion.  
> Kalau kamu **ubah susunan kursinya** (hapus satu) pas kamu jalan pakai _jalur otomatis_, kamu bisa kepleset 😅  
> Tapi kalau kamu pakai peta manual (iterator), kamu bisa lihat dan sesuaikan jalurnya.

---

## 💡 Tips:

- Gunakan `range-based` loop kalau **cuma baca**.
    
- Gunakan `iterator` kalau ingin **hapus atau modifikasi elemen** saat loop.
    

---

Kalau kamu mau, aku bisa buatin **cheat sheet lengkap** tentang jenis-jenis loop STL, dan kapan pakai yang mana. Mau?

