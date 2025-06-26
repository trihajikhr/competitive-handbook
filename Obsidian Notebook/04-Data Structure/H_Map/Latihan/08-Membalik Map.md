---
obsidianUIMode: preview
note_type: latihan
latihan: Membalik Map
sumber: chatgpt.com
tags:
  - data-structure
  - map
date_learned: 2025-06-21T19:51:00
---
---
🧠 Siap! Kita tingkatkan ke soal yang lebih menantang. Kamu sekarang akan bekerja dengan **nested map dan vector**, serta transformasi data.

---

# 🧩 Soal 8: Membalik Map — Kelompok Kelas Berdasarkan Jumlah Siswa

**Deskripsi:**

Diberikan `n` baris input yang masing-masing berisi `nama_kelas` dan `nama_siswa`, hitung jumlah siswa per kelas **seperti soal sebelumnya**.  
Tapi kali ini, kamu harus membalik datanya:

- Buat `map<int, vector<string>>` di mana:
    
    - **key = jumlah siswa**
        
    - **value = daftar nama kelas yang memiliki jumlah siswa tersebut**
        

Cetak hasilnya dalam urutan **jumlah siswa naik**, dan nama kelas dalam setiap jumlah diurutkan **secara leksikografis**.

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
1: XIIC
2: XIIB
3: XIIA
```

---

### 💡 Petunjuk:

1. Gunakan `map<string, int>` untuk menghitung jumlah siswa per kelas.
    
2. Lalu, buat `map<int, vector<string>>` untuk membalik: jumlah siswa → daftar kelas.
    
3. Jangan lupa untuk **mengurutkan `vector<string>`** dalam setiap entri (gunakan `sort()`).
    
4. Cetak dalam format:
    
    ```
    jumlah: kelas1 kelas2 ...
    ```
    

---

Soal ini akan menguji:

- Pemahaman `map<string, int>`
    
- Penggunaan `map<int, vector<string>>`
    
- Iterasi nested structure
    
- Sorting manual per `vector<string>`
    

Silakan dikerjakan! Kirimkan hasilmu jika sudah 💪

# Jawabanku

### Jawaban pertama
Jawabanku yang masih bisa diperbaiki:

```cpp
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<string, int> input;
    map<int, string> dasmap;

    int n; cin >> n;
    string s, x;
    while(n--){
        cin >> s >> x;
        input[s]++;
    }

    for(const auto & [key, val]: input){
        dasmap[val]=key;
    }

    for(const auto & [key, val]: dasmap){
        cout << key << ": " << val << "\n";
    }
    return 0;
}
```

### Jawaban yang benar sesuai editorial
Berikut adalah jawaban yang lebih baik:

```cpp
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> input;
    map<int, vector<string>> dasmap;

    int n; cin >> n;
    string kelas, siswa;

    while (n--) {
        cin >> kelas >> siswa;
        input[kelas]++;
    }

    for (const auto& [nama_kelas, jumlah] : input) {
        dasmap[jumlah].push_back(nama_kelas);
    }

    for (auto& [jumlah, daftar_kelas] : dasmap) {
        sort(daftar_kelas.begin(), daftar_kelas.end()); // urutkan nama kelas
        cout << jumlah << ": ";
        for (const string& nama_kelas : daftar_kelas) {
            cout << nama_kelas << " ";
        }
        cout << "\n";
    }

    return 0;
}
```

# Editorial
👍 Kamu sudah memahami tahap pertama dengan **baik**, yaitu:

- Menggunakan `map<string, int>` untuk menghitung jumlah siswa per kelas ✅
    

Namun, masih ada **beberapa hal penting yang perlu diperbaiki** agar sesuai dengan soal **"Membalik map: jumlah → daftar kelas"**, yaitu:

---

### ❌ Kesalahan Logika di Kode-mu:

```cpp
map<int, string> dasmap;
...
dasmap[val] = key;
```

- Ini **meng-overwrite** entri jika ada dua kelas dengan jumlah siswa yang sama.
    
- Yang kamu butuhkan adalah `map<int, vector<string>>`, **bukan** `map<int, string>`.
    

---

### ✅ Solusi yang Benar Harus:

```cpp
map<int, vector<string>> jumlah_to_kelas;
```

- Karena beberapa kelas bisa punya jumlah siswa yang **sama**, dan harus dikumpulkan dalam sebuah `vector<string>`.
    

---

### ✍️ Berikut versi perbaikannya:

```cpp
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> kelas_ke_jumlah;
    map<int, vector<string>> jumlah_ke_kelas;

    int n; cin >> n;
    string kelas, siswa;

    while (n--) {
        cin >> kelas >> siswa;
        kelas_ke_jumlah[kelas]++;
    }

    for (const auto& [nama_kelas, jumlah] : kelas_ke_jumlah) {
        jumlah_ke_kelas[jumlah].push_back(nama_kelas);
    }

    for (auto& [jumlah, daftar_kelas] : jumlah_ke_kelas) {
        sort(daftar_kelas.begin(), daftar_kelas.end()); // urutkan nama kelas
        cout << jumlah << ": ";
        for (const string& nama_kelas : daftar_kelas) {
            cout << nama_kelas << " ";
        }
        cout << "\n";
    }

    return 0;
}
```

---

### 📤 Output dari Contoh Input:

```
1: XIIC
2: XIIB
3: XIIA
```

✅ Sesuai ekspektasi.

---

Kalau kamu sudah paham dan ingin tantangan lanjutan, **Soal 9** akan melibatkan `map<string, set<string>>` untuk memastikan **satu siswa hanya dihitung satu kali per kelas**, meskipun muncul berkali-kali. Siap?