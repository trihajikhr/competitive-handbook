---
obsidianUIMode: preview
note_type: latihan
latihan: Menyisipkan dan Menampilkan Semua Nilai untuk Satu Kunci
sumber: chatgpt.com
tags:
  - data-structure
  - multimap
date_learned: 2025-06-22T21:33:00
---
---

Oke, mari kita mulai seri latihan tentang **`multimap`**. Kita akan mengerjakan satu soal per soal agar lebih fokus.

---

# Soal 1: Menyisipkan dan Menampilkan Semua Nilai untuk Satu Kunci

Terapkan kode C++ berikut:

1. Deklarasi `multimap<string, int> grades;`
    
2. Sisipkan data nilai siswa:
    
    ```cpp
    grades.insert({"Alice", 90});
    grades.insert({"Bob",   85});
    grades.insert({"Alice", 95});
    grades.insert({"Charlie", 70});
    grades.insert({"Bob",   88});
    ```
    
3. Minta pengguna memasukkan nama siswa (tipe `string`), lalu tampilkan **semua** nilai yang berasosiasi dengan nama tersebut.
    
    - Jika nama tidak ada, cetak `"Tidak ada data untuk [nama]"`.
        
    - Jika ada, cetak setiap nilai di baris terpisah, misalnya:
        
        ```
        Nilai untuk Alice:
        90
        95
        ```
        

Tantangan tambahan (opsional):

- Gunakan `equal_range()` untuk mengambil rentang iterator untuk kunci tersebut.
    
- Pastikan output disortir secara ascending berdasarkan nilai.
    

Silakan coba implementasi soal ini. Kalau sudah selesai atau ada kendala, kabari aku, kita bahas solusinya sebelum lanjut ke soal berikutnya!

## Jawabanku
Berikut adalah jawabanku yang sudah optimal:

```cpp
#include<iostream>
#include<map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    multimap<string, int> grades;
    grades.insert({"Alice", 90});
    grades.insert({"Bob",   85});
    grades.insert({"Alice", 95});
    grades.insert({"Charlie", 70});
    grades.insert({"Bob",   88});

    string s; cin >> s;
    if(grades.count(s)){
        cout << "Nilai untuk " << s << ":\n";
        auto range = grades.equal_range(s);
        if(range.first != range.second){
            for(auto it = range.first; it != range.second; it++){
                cout << it->second << "\n";
            }
        }
    } else {
        cout << "Tidak ada data untuk " << s << "\n";
    }
    return 0;
}
```

# Editorial
Editorial memiliki versi pendekatanya sendiri terhadap permasalahan:

```cpp
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1. Deklarasi multimap untuk menyimpan nama → nilai
    multimap<string, int> grades;

    // 2. Sisipkan data nilai siswa
    grades.insert({"Alice", 90});
    grades.insert({"Bob",   85});
    grades.insert({"Alice", 95});
    grades.insert({"Charlie", 70});
    grades.insert({"Bob",   88});

    // 3. Baca nama siswa dari input
    string s;
    cout << "Masukkan nama siswa: ";
    cin >> s;

    // 4. Cek apakah kunci ada dengan count()
    if (grades.count(s) > 0) {
        cout << "Nilai untuk " << s << ":\n";

        // 5. Ambil rentang iterator untuk kunci s
        auto range = grades.equal_range(s);

        // 6. Kumpulkan semua nilai ke dalam vector supaya bisa di-sort
        vector<int> vals;
        for (auto it = range.first; it != range.second; ++it) {
            vals.push_back(it->second);
        }

        // 7. (Opsional) Urutkan nilai ascending
        sort(vals.begin(), vals.end());

        // 8. Tampilkan setiap nilai
        for (int v : vals) {
            cout << v << "\n";
        }
    }
    else {
        // 9. Jika kunci tidak ada
        cout << "Tidak ada data untuk " << s << "\n";
    }

    return 0;
}
```

## Pembahasan kode

```cpp
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
```

- **Header**:
    
    - `<iostream>` untuk input/output
        
    - `<map>` agar bisa pakai `multimap`
        
    - `<vector>` untuk menampung nilai sebelum disort
        
    - `<algorithm>` untuk fungsi `sort`
        

---

```cpp
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
```

- **Optimasi I/O** agar `cin`/`cout` lebih cepat—standar di kompetitif programming.
    

---

```cpp
    multimap<string, int> grades;
```

- **Deklarasi** `grades` sebagai `multimap` dari `string` ke `int`, memungkinkan satu nama punya banyak nilai.
    

---

```cpp
    grades.insert({"Alice", 90});
    grades.insert({"Bob",   85});
    grades.insert({"Alice", 95});
    grades.insert({"Charlie", 70});
    grades.insert({"Bob",   88});
```

- **Penyisipan data**:
    
    - Setiap `insert` menambah pasangan (kunci, nilai).
        
    - Karena `multimap`, duplikat kunci (`Alice`, `Bob`) otomatis diizinkan.
        

---

```cpp
    cout << "Masukkan nama siswa: ";
    string s;
    cin >> s;
```

- **Input**:
    
    - Minta nama siswa
        
    - Baca ke variabel `s`
        

---

```cpp
    if (grades.count(s) > 0) {
        cout << "Nilai untuk " << s << ":\n";
```

- **Cek keberadaan**:
    
    - `count(s)` menghitung berapa entry dengan kunci `s`.
        
    - Jika > 0, berarti ada datanya → cetak header.
        

---

```cpp
        auto range = grades.equal_range(s);
```

- **Ambil rentang iterator**
    
    - `range.first` = duluan `it` untuk kunci `s`
        
    - `range.second` = posisi setelah entry terakhir untuk `s`
        

---

```cpp
        vector<int> vals;
        for (auto it = range.first; it != range.second; ++it) {
            vals.push_back(it->second);
        }
```

- **Kumpulkan nilai**:
    
    - Iterasi dari `first` sampai `second` (eksklusif)
        
    - Simpan setiap `it->second` (nilai) ke `vector<int> vals`
        

---

```cpp
        sort(vals.begin(), vals.end());
```

- **Urutkan ascending**:
    
    - `multimap` hanya urut berdasarkan kunci, bukan nilai
        
    - Dengan menyortir `vals`, kita pastikan nilai ditampilkan dari kecil ke besar
        

---

```cpp
        for (int v : vals) {
            cout << v << "\n";
        }
```

- **Cetak nilai** satu per baris dalam urutan ascending
    

---

```cpp
    } else {
        cout << "Tidak ada data untuk " << s << "\n";
    }
    return 0;
}
```

- **Jika tidak ada** (`count(s) == 0`), tampilkan pesan
    
- **Akhiri program** dengan `return 0;`
    

---

Dengan format blok kode + penjelasan per blok, kamu bisa langsung copy–paste ke pembahasanmu. Kalau masih ada yang mau diubah atau ditambah, kabari!