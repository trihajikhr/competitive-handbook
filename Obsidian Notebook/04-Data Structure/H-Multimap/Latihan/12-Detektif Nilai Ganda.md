---
obsidianUIMode: preview
note_type: latihan
latihan: Detektif Nilai Ganda
sumber: chatgpt.com
tags:
  - data-structure
  - multimap
date_learned: 2025-06-23T18:40:00
---
---
Siap! Kita akan buat soal nomor 12 hingga 15 dengan **tema dan konteks yang lebih variatif**, tapi tetap menguji kemampuan `multimap`.

Berikut **Soal 12** dengan nuansa baru:

---
# Soal 12: Detektif Nilai Ganda

**Deskripsi**  

Seorang guru mencurigai bahwa ada siswa yang memiliki **nilai yang sama** sebanyak **lebih dari satu kali** di sistemnya. Bantulah guru ini untuk menemukan seluruh siswa yang **punya nilai yang ganda (duplikat)**.

---

**Spesifikasi Input**

1. Baris pertama: integer $N$ — jumlah entri
    
2. Diikuti $N$ baris pasangan:
    
    ```
    nama nilai
    ```
    

---

**Spesifikasi Output**

- Tampilkan semua nama yang memiliki **nilai yang sama lebih dari satu kali**
    
- Urutan nama sesuai urutan leksikografis
    
- Jika tidak ada yang memiliki duplikat nilai, cetak:
    
    ```
    Tidak ada duplikat
    ```
    

---

**Contoh Input:**

```
7
Alice 90
Bob 85
Alice 90
Charlie 70
Bob 85
Dina 88
Dina 70
```

**Output:**

```
Alice
Bob
```

---

**Penjelasan:**

- Alice punya dua kali nilai 90 → duplikat
    
- Bob punya dua kali nilai 85 → duplikat
    
- Dina tidak punya nilai yang sama lebih dari sekali
    

---

Yuk, coba kerjakan soal ini dulu. Setelah itu kita lanjut ke soal 13–15 yang juga lebih bervariasi temanya!

## Jawabanku
Berikut adalah jawabanku untuk menyelesaiak problem ini, yang 95% benar, karena masih bisa ditingkatkan lagi dengan pengecekan apakah set `rest` kosong atau tidak yang dibahas di editorial:

```cpp
#include<map>
#include<iostream>
#include<set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    multimap<string, int> mulmap;
    set<int> point;
    set<string> rest;

    int n, x; string s;
    cin >> n;

    while(n--){
        cin >> s >> x;
        mulmap.insert({s,x});
    }

    auto nm = mulmap.begin();
    string nama = nm->first;
    point.insert(nm->second);
    for(const auto& [key, val]: mulmap){
        if(key != nama){
            nama = key;
            point.clear();
            point.insert(val);
        } else {
            if(point.count(val)){
                rest.insert(key);
            } else point.insert(val);
        }
    }

    for(const auto& x: rest){
        cout << x << "\n";
    }
    return 0;
}
```

# Editorial
✅ Jawabanmu **tepat, efisien, dan sesuai deskripsi soal!**  
Kamu menyelesaikan soal dengan pendekatan yang **cerdas dan praktis**—yaitu:

- Menyimpan nilai-nilai yang pernah muncul untuk satu nama dalam `set<int>`
    
- Menambahkan nama ke `rest` jika nilai yang sama muncul lagi
    

---

Berikut **editorial per blok kode** untuk dokumentasi soal 12:

---

```cpp
#include <map>
#include <iostream>
#include <set>
using namespace std;
```

- Menggunakan:
    
    - `multimap`: untuk menyimpan input `(nama, nilai)`
        
    - `set<int>`: untuk melacak nilai-nilai unik per nama
        
    - `set<string>`: untuk menyimpan nama yang terdeteksi duplikat
        

---

```cpp
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
```

- Optimasi I/O
    

---

```cpp
    multimap<string, int> mulmap;
    set<int> point;
    set<string> rest;

    int n, x;
    string s;
    cin >> n;

    while (n--) {
        cin >> s >> x;
        mulmap.insert({s, x});
    }
```

- Membaca input ke dalam `multimap`
    
- `point`: menyimpan nilai yang sudah muncul untuk nama yang sedang diproses
    
- `rest`: hasil akhir — nama-nama yang punya nilai duplikat
    

---

```cpp
    auto nm = mulmap.begin();
    string nama = nm->first;
    point.insert(nm->second);
```

- Inisialisasi nama pertama dan nilai pertama
    

---

```cpp
    for (const auto& [key, val] : mulmap) {
        if (key != nama) {
            nama = key;
            point.clear();
            point.insert(val);
        } else {
            if (point.count(val)) {
                rest.insert(key);
            } else {
                point.insert(val);
            }
        }
    }
```

- Iterasi semua entri:
    
    - Jika `key` berganti → mulai sesi baru
        
    - Jika `key` sama seperti sebelumnya:
        
        - Cek apakah `val` sudah pernah muncul → jika ya, tambahkan `key` ke `rest`
            
        - Jika belum, tambahkan ke `point`
            

---

```cpp
    for (const auto& x : rest) {
        cout << x << "\n";
    }
```

- Cetak hasil akhir
    

---

⚠️ **Catatan kecil**:  
Jika tidak ada hasil (`rest.empty()`), kamu belum menambahkan pengecekan `"Tidak ada duplikat"`. Untuk menyempurnakan:

```cpp
if (rest.empty()) cout << "Tidak ada duplikat\n";
else for (const auto& x : rest) cout << x << "\n";
```

---

Siap untuk **lanjut ke soal nomor 13** dengan tema baru juga?