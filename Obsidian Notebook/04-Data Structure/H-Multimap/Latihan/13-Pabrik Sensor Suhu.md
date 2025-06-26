---
obsidianUIMode: preview
note_type: latihan
latihan: Pabrik Sensor Suhu
sumber: chatgpt.com
tags:
  - data-structure
  - multimap
date_learned: 2025-06-23T18:58:00
---
---
# 🧪 Soal 13: Pabrik Sensor Suhu

**Deskripsi**  
Sebuah pabrik memiliki banyak sensor suhu yang tersebar di berbagai ruangan. Setiap sensor mencatat suhu secara berkala. Data dari sensor disimpan dalam bentuk pasangan `(ruangan, suhu)` di `multimap<string, int>`.

Pabrik ingin mengetahui **jumlah ruangan** yang pernah mencatat suhu **di atas** ambang batas tertentu.

---

**Spesifikasi Input**

1. Baris pertama: integer N — jumlah catatan
    
2. N baris berikutnya:
    
    ```
    nama_ruangan suhu
    ```
    
3. Baris terakhir: integer T — ambang suhu
    

---

**Spesifikasi Output**

- Cetak satu baris:
    
    ```
    Jumlah ruangan dengan suhu di atas T: <jumlah>
    ```
    
- Hanya hitung **satu kali per ruangan**, meskipun ruangan tersebut punya banyak catatan yang melebihi T
    

---

**Contoh Input:**

```
7
A1 35
A2 45
A1 40
B1 25
A2 50
C3 60
C3 20
40
```

**Output:**

```
Jumlah ruangan dengan suhu di atas T: 2
```

---

**Penjelasan:**

- A1 punya suhu 40 (batas), tidak dihitung
    
- A2: 45, 50 → dihitung 1
    
- B1: 25 → tidak
    
- C3: 60 → dihitung 1
    
- Total: A2, dan C3 (karena ada suhu 40 **tidak dihitung**)
    

---

Silakan implementasikan solusinya! Setelah itu kita lanjut ke soal 14 dan 15 yang juga beda tema!

## Jawaban
Berikut adalah jawabanku yang sudah optimal:

```cpp
#include<iostream>
#include<map>
#include<set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    multimap<string, int> mulmap;
    set<string> rest;
    int count=0;

    int n, x; string s;
    cin >> n;

    while(n--){
        cin >> s >> x;
        mulmap.insert({s,x});
    }

    int t; cin >> t;

    for(const auto& [key, val]: mulmap){
        if(val>t){
            rest.insert(key);
        }
    }

    cout << "Jumlah ruangan dengan suhu di atas T: " << rest.size() << "\n";
    return 0;
}
```

# Editorial
✅ Jawaban kamu **sudah tepat dan optimal!**  
Kamu:

- Menyimpan seluruh catatan suhu
    
- Memasukkan nama ruangan ke dalam `set<string>` jika suhunya melebihi ambang `t`
    
- Menggunakan `.size()` dari `set` untuk menghitung jumlah ruangan unik
    

---

Berikut **editorial per blok kode**, siap untuk laporan atau catatan kamu:

---

```cpp
#include <iostream>
#include <map>
#include <set>
using namespace std;
```

- `multimap`: menyimpan semua catatan suhu
    
- `set`: menyimpan nama ruangan yang unik dan lolos ambang suhu
    

---

```cpp
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
```

- Optimasi I/O untuk mempercepat input-output
    

---

```cpp
    multimap<string, int> mulmap;
    set<string> rest;
    int count = 0;
```

- `mulmap`: menyimpan semua pasangan `(ruangan, suhu)`
    
- `rest`: menyimpan nama ruangan yang lolos ambang batas
    
- `count` tidak dipakai, bisa dihapus (tidak memengaruhi hasil)
    

---

```cpp
    int n, x;
    string s;
    cin >> n;

    while (n--) {
        cin >> s >> x;
        mulmap.insert({s, x});
    }
```

- Input semua data suhu dari sensor ke `multimap`
    

---

```cpp
    int t;
    cin >> t;
```

- Ambang suhu `t` yang dijadikan patokan
    

---

```cpp
    for (const auto& [key, val] : mulmap) {
        if (val > t) {
            rest.insert(key);
        }
    }
```

- Jika suhu `val` melebihi ambang, nama ruangan `key` ditambahkan ke `rest`
    
- Karena `rest` adalah `set`, ruangan hanya disimpan satu kali walau suhu tinggi muncul berkali-kali
    

---

```cpp
    cout << "Jumlah ruangan dengan suhu di atas T: " << rest.size() << "\n";
    return 0;
```

- Menampilkan jumlah total ruangan yang punya suhu tinggi
    

---

Siap lanjut ke **Soal 14**? Kali ini kita pakai tema **event dan waktu**!