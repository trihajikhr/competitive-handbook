---
obsidianUIMode: preview
note_type: latihan
latihan: Set of User-Defined Struct
sumber: chatgpt.com
tags:
  - data-structure
  - set
date_learned: 2025-06-20T22:46:00
---
---
# 🧩 Latihan 10 — Set of User-Defined Struct

**Fokus:** Menggunakan `std::set` untuk menyimpan **struct buatan sendiri**, dengan aturan pengurutan kustom melalui operator overloading.

---

### Deskripsi Soal:

Buat sebuah struct bernama `Mahasiswa` yang menyimpan:

- `string nama`
    
- `int nilai`
    

Simpan `n` data mahasiswa ke dalam `set<Mahasiswa>`, lalu cetak semuanya dalam urutan:

1. **Nilai terbesar ke terkecil**
    
2. Jika nilai sama, urutkan berdasarkan **nama secara leksikografis naik**
    

---

### Input Format:

- Baris pertama: bilangan bulat `n` (1 ≤ n ≤ 100)
    
- Baris berikutnya: `n` baris, masing-masing berisi `nama` dan `nilai`
    

---

### Output Format:

- Cetak data mahasiswa dalam format:  
    `nama nilai`  
    satu per baris
    

---

### Contoh Input:

```
5
Andi 90
Budi 85
Cici 90
Dina 70
Andi 85
```

### Contoh Output:

```
Andi 90
Cici 90
Andi 85
Budi 85
Dina 70
```

---

### 🧠 Petunjuk:

- Buat struct `Mahasiswa` dan overload operator `<`
    
- Gunakan `set<Mahasiswa>`
    
- Gunakan `emplace` untuk menambahkan data
    

Contoh pendek struct:

```cpp
struct Mahasiswa {
    string nama;
    int nilai;

    bool operator<(const Mahasiswa& other) const {
        if (nilai != other.nilai) return nilai > other.nilai; // descending
        return nama < other.nama; // ascending
    }
};
```

---

Langsung saja buat dan kirimkan kodenya!  
Setelah itu, aku akan beri penilaian terakhir dan wrap-up keseluruhan latihan `std::set` kamu. 🔥

## Jawabanku
Berikut adalah jawaban dari tantangan ini:

```cpp
#include<iostream>
#include<set>
using namespace std;

struct Mahasiswa{
    string nama;
    int nilai;

    bool operator<(const Mahasiswa& other) const {
        if(nilai != other.nilai) return nilai > other.nilai;
        else return nama < other.nama;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    set<Mahasiswa> daset;

    for(int i=0; i<n; i++){
        string a; int b; 
        cin >> a >> b;
        daset.emplace(a,b);
    }

    for(const auto& [nama, nilai]: daset){
        cout << nama << " " << nilai << "\n";
    }

    return 0;
}
```

# Editorial
🔥 **LUAR BIASA!** Kamu baru saja menyelesaikan latihan `std::set` paling komprehensif — **termasuk level lanjutan dengan struct dan custom sorting!** Ini benar-benar performa tingkat tinggi! 🚀

---

### ✅ Evaluasi Jawaban:

#### 1. **Struct `Mahasiswa` dan Overloading Operator `<`**

```cpp
struct Mahasiswa {
    string nama;
    int nilai;
    bool operator<(const Mahasiswa& other) const {
        if (nilai != other.nilai) return nilai > other.nilai;
        return nama < other.nama;
    }
};
```

✔️ Mengurutkan:

- Berdasarkan **nilai menurun**
    
- Jika sama, berdasarkan **nama naik**
    

#### 2. **Pemakaian `set<Mahasiswa>`**

```cpp
set<Mahasiswa> daset;
```

✔️ Menyimpan objek unik berdasarkan aturan `operator<`

#### 3. **Input dan Insert**

```cpp
daset.emplace(a, b);
```

✔️ Langsung emplace ke dalam set tanpa perlu membuat objek manual.

#### 4. **Structured Binding di Output**

```cpp
for (const auto& [nama, nilai] : daset)
```

✔️ Penggunaan modern dan bersih (C++17). Output rapi sesuai soal.

---

### 🧪 Cek dengan Contoh Input:

```
5
Andi 90
Budi 85
Cici 90
Dina 70
Andi 85
```

### ✅ Output:

```
Andi 90
Cici 90
Andi 85
Budi 85
Dina 70
```

🟢 **Sesuai 100% dengan aturan soal.**

---

### 🏁 Wrap-Up — Kamu Sudah Menguasai:

|Topik Latihan|Status|
|---|---|
|Dasar penggunaan `set`|✅|
|Insert, erase, find, count, contains|✅|
|Traversal biasa dan terbalik|✅|
|Swap antar set|✅|
|Custom comparator dengan `greater<int>`|✅|
|Set of pairs (`pair<int, int>`)|✅|
|Set of struct + custom `operator<`|✅🔥|

---

### 🎓 Next Level:

Jika kamu ingin lanjut ke topik lanjutan:

- `std::multiset` (untuk elemen duplikat)
    
- `unordered_set` (hash-based, O(1) avg ops)
    
- `map`, `unordered_map`
    
- atau langsung lanjut ke `priority_queue`, `deque`, dll
    

Tinggal bilang ya, aku siap bantu kamu mendalami struktur data lainnya! 💪