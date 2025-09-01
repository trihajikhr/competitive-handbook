---
obsidianUIMode: preview
note_type: latihan
latihan: Catatan Siswa dan Duplikasi
sumber: Google.com, AI
tags:
  - vector
  - data-structure
date_learned: 2025-06-14T21:45:00
---
---
# Catatan Siswa dan Duplikasi
Mantap! Kita lanjut ke **Soal 7**, fokus ke `emplace_back()` dan `assign()` dalam konteks yang alami dan praktis.

---

## 🧪 Soal 7: Catatan Siswa dan Duplikasi

Buat program C++ yang:

1. Membaca bilangan bulat `N` (1 ≤ N ≤ 1000): jumlah siswa.
    
2. Untuk setiap siswa, baca:
    
    - `nama` (string tanpa spasi)
        
    - `nilai` (integer)
        
3. Simpan data ke `vector<pair<string, int>>` menggunakan `emplace_back(...)` — **jangan gunakan `push_back({...})`**.
    
4. Setelah semua siswa dibaca, salin isi vector ke `vector<pair<string,int>> copy;` menggunakan fungsi `assign(...)`.
    
5. Cetak semua data di `copy`, satu per baris:
    
    ```
    Nama: <nama>, Nilai: <nilai>
    ```
    

---

### Contoh Input:

```
3
Andi 80
Budi 75
Citra 90
```

### Contoh Output:

```
Nama: Andi, Nilai: 80
Nama: Budi, Nilai: 75
Nama: Citra, Nilai: 90
```

---

### Tujuan Soal

- Mempraktikkan `emplace_back(...)` pada struktur data bertipe kompleks (`pair`).
    
- Menggunakan `assign(...)` untuk menyalin isi vector secara langsung dan bersih.
    

---

Kalau sudah selesai, kirimkan kodenya dan kita akan bahas serta lanjut ke **Soal 9** (lebih seru, pakai `resize()` dan default value)! 😊
## Jawabanku
Berikut adalah kode jawabnku:

```cpp
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<string, int>> input;
    for(int i=0; i<n; i++){
        string s; int a;
        cin >> s >> a;

        input.emplace_back(s,a);
    }

    vector<pair<string,int>> copy;
    copy.assign(input.begin(), input.end());
    for(const auto&x:copy){
        cout << "Nama: " << x.first << ", Nilai: " << x.second << "\n"; 
    }
    return 0;
}
```
## Editorial
Kode kamu **sudah tepat dan rapi sekali!** 🎉  
Berikut ini **editorial lengkap** untuk Soal 8:

---

### ✅ Tujuan Soal

Melatih penggunaan dua fungsi penting pada `std::vector`:

- `emplace_back()` → menambahkan elemen dengan konstruksi langsung (tanpa membuat `pair` sementara).
    
- `assign(...)` → menyalin isi vector secara langsung dari vector lain (tanpa loop manual).
    

---

### 🧠 Penjelasan Baris per Baris

```cpp
#include<iostream>
#include<vector>
using namespace std;
```

Mengimpor pustaka dasar: `iostream` untuk I/O, dan `vector` untuk struktur data dinamis.

---

```cpp
int main() {
    int n; cin >> n;
```

Membaca jumlah siswa `n`.

---

```cpp
    vector<pair<string, int>> input;
```

Membuat `vector` yang menyimpan pasangan `nama` dan `nilai` siswa.  
Tipe `pair<string, int>` menyimpan dua jenis data yang berhubungan.

---

```cpp
    for(int i=0; i<n; i++){
        string s; int a;
        cin >> s >> a;
        input.emplace_back(s,a);
    }
```

✅ Di sini kamu membaca `nama` dan `nilai`, lalu menyisipkan ke dalam `vector`:

- `emplace_back(s, a)` secara **efisien** membangun `pair<string, int>` langsung di dalam vector tanpa objek sementara.  
    ➤ Lebih cepat daripada `push_back({s, a})` karena menghindari copy/move constructor tambahan.
    

---

```cpp
    vector<pair<string,int>> copy;
    copy.assign(input.begin(), input.end());
```

✅ Di sini kamu menggunakan:

- `assign(first, last)` untuk **menyalin seluruh isi vector `input`** ke vector baru `copy`.
    
- Ini cara elegan dan efisien, **lebih bersih** daripada melakukan loop dan `push_back` manual.
    

---

```cpp
    for(const auto& x : copy){
        cout << "Nama: " << x.first << ", Nilai: " << x.second << "\n"; 
    }
```

✅ Output:

- Menampilkan nama dan nilai siswa dari `copy` dalam format yang diminta.
    
- `x.first` adalah `nama`, dan `x.second` adalah `nilai`.
    

---

### 🧩 Kompleksitas

- Waktu:
    
    - Input dan `emplace_back`: **O(N)**
        
    - `assign`: **O(N)**
        
    - Output: **O(N)**
        
- Memori: dua vector masing-masing berisi N elemen → **O(N)**
    

---

### 💡 Catatan Tambahan

|Fungsi|Keunggulan|
|---|---|
|`emplace_back()`|Lebih efisien untuk object complex (cth: pair)|
|`assign()`|Rapi & cepat untuk copy seluruh isi vector|

---

Kalau kamu sudah siap, kita lanjut ke **Soal 8**, yang akan menguji pemahamanmu tentang `resize()` dan _default values_. Gas? 😄