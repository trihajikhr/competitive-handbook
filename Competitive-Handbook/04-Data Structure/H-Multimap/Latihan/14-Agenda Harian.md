---
obsidianUIMode: preview
note_type: latihan
latihan: Agenda Harian
sumber: chatgpt.com
tags:
  - data-structure
  - multimap
date_learned: 2025-06-23T19:11:00
---
---
# ⏰ Soal 14: Agenda Harian

**Deskripsi**  
Kamu membuat aplikasi agenda harian yang mencatat berbagai aktivitas harian dalam format `(waktu, aktivitas)`. Semua data disimpan dalam `multimap<int, string>`, di mana:

- `int` = jam kegiatan (0–23)
    
- `string` = deskripsi kegiatan
    

Tugasmu adalah mencetak semua aktivitas yang terjadi **dalam rentang waktu tertentu** (inklusif), **berurutan berdasarkan jam terkecil ke terbesar**.

---

**Spesifikasi Input**

1. Baris pertama: integer N — jumlah kegiatan
    
2. Diikuti N baris:
    
    ```
    jam aktivitas
    ```
    
3. Baris terakhir: dua integer `a` dan `b` — rentang jam (inklusif)
    

---

**Spesifikasi Output**

- Tampilkan semua entri `(jam aktivitas)` dalam rentang tersebut, berurutan menaik berdasarkan jam
    
- Jika tidak ada kegiatan di rentang tersebut, tampilkan:
    
    ```
    Tidak ada aktivitas
    ```
    

---

**Contoh Input:**

```
6
8 Sarapan
9 Rapat
13 MakanSiang
15 Coding
17 Olahraga
21 Tidur
13 17
```

**Output:**

```
13 MakanSiang
15 Coding
17 Olahraga
```

---

**Contoh Input 2:**

```
4
7 Yoga
9 Meeting
11 Istirahat
12 Makan
18 20
```

**Output:**

```
Tidak ada aktivitas
```

---

Langsung coba implementasikan! Setelah itu kita masuk soal 15, penutup multimap 💪

## Jawabanku
Berikut adalah jawabanku untuk tantangan kali ini:

```cpp
#include<iostream>
#include<map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    multimap<int, string> agenda;
    int n, x; string s;

    cin >> n;
    while(n--){
        cin >> x; getline(cin >> ws, s);
        agenda.insert({x, s});
    }

    int a, b; cin >> a >> b;
    bool kosong=true;

    for(const auto& [key, val]: agenda){
        if(key >= a && key <= b){
            cout << key << " " << val << "\n";
            kosong=false;
        }
    }

    if(kosong) cout << "Tidak ada aktivitas\n";
    return 0;
}
```

# Editorial
✅ Jawabanmu sudah **benar, rapi, dan sesuai spesifikasi soal**!

Kamu menggunakan `getline(cin >> ws, s)` dengan tepat untuk menangkap input string dengan spasi, dan memanfaatkan `multimap` agar entri otomatis terurut berdasarkan jam.

---

### Penjelasan Per Blok Kode (Editorial)

---

```cpp
#include <iostream>
#include <map>
using namespace std;
```

- `multimap`: digunakan karena memungkinkan **jam yang sama** dengan aktivitas berbeda
    
- `iostream`: untuk I/O dasar
    

---

```cpp
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
```

- Optimasi input/output
    

---

```cpp
    multimap<int, string> agenda;
    int n, x;
    string s;

    cin >> n;
    while (n--) {
        cin >> x;
        getline(cin >> ws, s);
        agenda.insert({x, s});
    }
```

- `cin >> x`: membaca jam kegiatan
    
- `getline(cin >> ws, s)`: membaca deskripsi lengkap (termasuk spasi)
    
- Data langsung dimasukkan ke `agenda`, otomatis terurut naik berdasarkan jam
    

---

```cpp
    int a, b;
    cin >> a >> b;
    bool kosong = true;
```

- Rentang waktu `a` sampai `b` (inklusif)
    
- `kosong`: flag untuk mendeteksi apakah ada kegiatan yang cocok
    

---

```cpp
    for (const auto& [key, val] : agenda) {
        if (key >= a && key <= b) {
            cout << key << " " << val << "\n";
            kosong = false;
        }
    }
```

- Iterasi seluruh agenda
    
- Hanya mencetak entri yang jam-nya dalam rentang `[a, b]`
    

---

```cpp
    if (kosong)
        cout << "Tidak ada aktivitas\n";
    return 0;
}
```

- Jika tidak ada aktivitas dalam rentang tersebut, tampilkan pesan default
    

---

Siap untuk masuk ke **Soal 15**, latihan penutup untuk `multimap` dengan tantangan tema baru juga?