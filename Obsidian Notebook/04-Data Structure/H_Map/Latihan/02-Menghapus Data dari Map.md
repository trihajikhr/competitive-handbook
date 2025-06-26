---
obsidianUIMode: preview
note_type: latihan
latihan: Menghapus Data dari Map
sumber: chatgpt.com
tags:
  - data-structure
  - map
date_learned: 2025-06-21T19:10:00
---
---
# 🧩 Soal 2: Menghapus Data dari Map

**Deskripsi:**

Buat program C++ yang:

1. Menerima `n` pasangan `string` dan `int`.
    
2. Menyimpan pasangan tersebut ke dalam `std::map<string, int>`.
    
3. Menerima sebuah kata `hapus_kata` dan menghapus entri tersebut dari map jika ada.
    
4. Terakhir, cetak semua isi map **berdasarkan urutan key** (karena `map` secara default tersusun berdasarkan urutan `key` secara leksikografis).
    

---

**Contoh Input:**

```
4
apel 5
jeruk 2
pisang 9
mangga 3
jeruk
```

**Contoh Output:**

```
apel 5
mangga 3
pisang 9
```

---

**Petunjuk:**

- Gunakan `map.erase(key)` untuk menghapus entri.
    
- Cetak semua isi map dengan `for (auto& pair : map) {}`.
    

Kalau kamu sudah selesai, tinggal kirimkan hasilnya — dan setelah itu kita lanjut ke soal ke-3!

## Jawabanku
Berikut adalah jawabanku yang sudah benar:

```cpp
#include<iostream>
#include<map>
using namespace std;

int main() {
    int n; cin >> n;
    map<string, int> dasmap;

    string s; int x;
    while(n--){
        cin >> s >> x;
        dasmap[s]=x;
    }

    string hapus; cin >> hapus;
    if(dasmap.find(hapus) != dasmap.end()){
        dasmap.erase(hapus);
    }

    for(const auto& pair : dasmap){
        cout << pair.first << " " << pair.second << "\n";
    }
    return 0;
}
```

# Editorial

## 🧩 Soal 2: Menghapus Data dari Map

### 📌 Tujuan

Latihan ini bertujuan agar kamu:

- Bisa mengisi `std::map` dengan data dari input.
    
- Tahu cara menghapus elemen dari `map` berdasarkan key.
    
- Paham bahwa `std::map` menyimpan elemen secara otomatis dalam **urutan key** yang terurut secara leksikografis.
    
- Mampu mencetak isi map menggunakan `range-based for loop`.
    

---

### 🧠 Logika dan Penjelasan Langkah Demi Langkah

```cpp
int n; cin >> n;
map<string, int> dasmap;
```

- Membaca jumlah pasangan data yang akan dimasukkan.
    
- Inisialisasi map `dasmap` dengan key bertipe `string` dan value bertipe `int`.
    

---

```cpp
string s; int x;
while(n--) {
    cin >> s >> x;
    dasmap[s] = x;
}
```

- Membaca `n` pasang string dan integer.
    
- Menggunakan indexing (`[]`) untuk langsung menyimpan nilai ke dalam map.
    
    - Jika key `s` belum ada, maka akan otomatis dibuat dan diisi dengan `x`.
        
    - Jika key `s` sudah ada, maka nilainya akan **ditimpa** (overwrite).
        

---

```cpp
string hapus; cin >> hapus;
if(dasmap.find(hapus) != dasmap.end()) {
    dasmap.erase(hapus);
}
```

- Membaca string `hapus` yang akan dihapus dari map.
    
- Gunakan `find()` untuk mengecek apakah `hapus` ada di dalam map.
    
- Jika ketemu (`!= map.end()`), maka `erase(hapus)` akan menghapusnya.
    

🔎 Kenapa tidak langsung `dasmap.erase(hapus);` saja?

- Itu **aman juga**, karena `erase(key)` akan **tidak melakukan apa-apa** jika key-nya tidak ditemukan. Tapi dengan pengecekan eksplisit, kita lebih sadar bahwa penghapusan hanya dilakukan bila benar-benar ada.
    

---

```cpp
for(const auto& pair : dasmap){
    cout << pair.first << " " << pair.second << "\n";
}
```

- `range-based for` digunakan untuk menampilkan semua isi map.
    
- Karena `std::map` disimpan terurut berdasarkan key, maka output akan otomatis dalam urutan abjad.
    
- `pair.first` adalah key (string), dan `pair.second` adalah value (int).
    

---

### 🧪 Contoh Kasus:

#### Input:

```
4
apel 5
jeruk 2
pisang 9
mangga 3
jeruk
```

#### Proses:

- Map awal: `{ apel:5, jeruk:2, pisang:9, mangga:3 }`
    
- Dihapus: `jeruk`
    
- Map akhir: `{ apel:5, mangga:3, pisang:9 }`
    

#### Output:

```
apel 5
mangga 3
pisang 9
```

---

### ✅ Konsep Kunci yang Dipelajari

|Konsep|Penjelasan|
|---|---|
|`map[key] = value`|Menyisipkan/mengubah elemen|
|`map.erase(key)`|Menghapus elemen berdasarkan key|
|`map.find(key)`|Mencari apakah key ada|
|Iterasi `for`|Menampilkan seluruh isi map|
