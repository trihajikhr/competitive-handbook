---
obsidianUIMode: preview
note_type: latihan
latihan: Ubah Format Key dengan Node Extraction
sumber: Google.com, AI
tags:
  - data-structure
  - unordered_map
date_learned: 2025-06-17T06:16:00
---
---
Berikut **Soal 14** untuk memperkenalkan teknik **mengubah key** di `std::unordered_map` menggunakan **`extract()`** dan **`insert()`** node:

---

# Soal 14 – Ubah Format Key dengan Node Extraction

Diberikan sebuah peta `unordered_map<string, int>` yang berisi nama-nama produk (string) dan stoknya (int). Kamu diminta **mengubah format key** setiap produk menjadi **uppercase** seluruhnya, tanpa melakukan copy string atau lookup ganda.

- **Wajib** pakai `extract()` untuk mengambil node dari map lama, modifikasi key di node, lalu `insert()` kembali ke map.
    
- Jangan buat map baru atau rebuild dari nol—lakukan in-place pada map yang sama.
    

### Deskripsi

1. Baca integer **_n_** (1 ≤ _n_ ≤ 1000) — jumlah produk.
    
2. Baca _n_ baris, masing-masing “_produk stok_” (misal `apple 5`).
    
3. Untuk tiap entri:
    
    - **Ambil node** dengan `auto nh = mp.extract(key);`
        
    - Ubah `nh.key()` menjadi versi **uppercase** (gunakan `std::toupper` per karakter).
        
    - **Masukkan kembali** node ke `mp` dengan `mp.insert(move(nh));`
        
4. Setelah semua diubah, **urutkan** daftar key uppercase secara leksikografis ascending dan cetak “_key stok_” setiap baris.
    

### Format Masukan

```
5
apple 10
Banana 3
grape 7
orange 2
mango 5
```

### Format Keluaran

```
APPLE 10
BANANA 3
GRAPE 7
MANGO 5
ORANGE 2
```

---

**Tugasmu:**

- Implementasi C++ membaca input, memodifikasi key in-place dengan `extract` & `insert`, lalu menampilkan hasil terurut.
    
- Sertakan **penjelasan singkat** mengapa teknik ini efisien (hint: node relocation tanpa alokasi ulang string).
    

Kerjakan soal ini, lalu kirimkan kodenya! 😊

## Jawabanku
Berikut adaalh jawabanku yang sudah mengalami beberapa perbaikdan dari saran editorial:

```cpp
#include<iostream>
#include<cctype>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    unordered_map<string, int> produk;
    produk.reserve(n);

    while(n--) {
        string nama;
        int stok;
        cin >> nama >> stok;
        produk.emplace(nama, stok);
    }

    vector<string> hasil_keys;
    for (auto it = produk.begin(); it != produk.end(); ) {
        auto nh = produk.extract(it++); 

        string& k = nh.key();
        for (char& c : k) c = toupper(c);

        hasil_keys.push_back(k);  
        produk.insert(move(nh));  
    }

    sort(hasil_keys.begin(), hasil_keys.end());

    for (const string& key : hasil_keys) {
        cout << key << " " << produk[key] << "\n";
    }

    return 0;
}
```

### Jawaban yang dikomentari

```cpp
#include<iostream>
#include<cctype>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<utility>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    unordered_map<string, int> produk;
    produk.reserve(n);

    // Input
    while(n--) {
        string nama;
        int stok;
        cin >> nama >> stok;
        produk.emplace(nama, stok);
    }

    // Ubah key menjadi uppercase menggunakan extract() dan insert()
    vector<string> hasil_keys;
    for (auto it = produk.begin(); it != produk.end(); ) {
        auto nh = produk.extract(it++);  // simpan dan majukan iterator dulu agar tidak invalid

        string& k = nh.key();
        for (char& c : k) c = toupper(c);

        hasil_keys.push_back(k);  // kumpulkan key untuk pengurutan nanti
        produk.insert(move(nh));  // masukkan kembali node ke map
    }

    // Urutkan key-key
    sort(hasil_keys.begin(), hasil_keys.end());

    // Cetak hasil
    for (const string& key : hasil_keys) {
        cout << key << " " << produk[key] << "\n";
    }

    return 0;
}

```

# Editorial
Berikut adalah **editorial singkat Soal 14 – Mengubah Key Unordered Map dengan `extract()`**:

---

### 🧠 Tujuan Soal:

Melatih penggunaan `unordered_map::extract()` untuk **memodifikasi key** secara langsung, tanpa membuat map baru, tanpa melakukan lookup ganda, dan tetap efisien.

---

### 📌 Langkah-langkah Solusi:

1. **Membaca Input**
    
    - Masukkan `n` data produk dalam bentuk `(nama_produk, stok)`.
        
    - Simpan di `unordered_map<string, int> produk`.
        
2. **Mengubah Key dengan `extract()`**
    
    - Kita tidak bisa langsung mengubah `key` dalam `unordered_map`, karena key bersifat **immutable** di dalam map.
        
    - Tapi dengan `extract(key)`:
        
        - Kita ambil **node handle** (`node_type`).
            
        - Lalu, kita bisa **modifikasi `nh.key()`** seperti variabel biasa.
            
    - Contoh:
        
        ```cpp
        auto nh = produk.extract("apple");
        string& k = nh.key();  // akses key
        transform(k.begin(), k.end(), k.begin(), ::toupper);
        produk.insert(move(nh));  // masukkan kembali node yang telah dimodifikasi
        ```
        
3. **Hati-hati dengan Iterator**
    
    - Setelah `extract()`, iterator lama menjadi invalid.
        
    - Maka, gunakan:
        
        ```cpp
        for (auto it = map.begin(); it != map.end(); ) {
            auto nh = map.extract(it++); // advance iterator dulu
            ...
        }
        ```
        
4. **Urutkan dan Cetak Output**
    
    - Karena `unordered_map` tidak berurutan, kita kumpulkan semua key ke `vector<string>`, lalu `sort()` dan cetak nilai dari map.
        

---

### ⚙️ Keunggulan Teknik Ini

- **Efisien:** karena `extract()` + `insert()` hanya memindahkan node, **tanpa copy** atau alokasi ulang.
    
- **Aman:** bisa modifikasi `key`, yang sebelumnya tidak mungkin dilakukan dalam map biasa.
    
- **Rapi:** kita hanya pakai satu map, tanpa membangun ulang atau membuat map baru.
    

---

### 🧾 Contoh Ringkas

```cpp
auto nh = produk.extract("banana");
for (char& c : nh.key()) c = toupper(c);
produk.insert(move(nh));
```

---

Jika kamu sudah memahami teknik ini, kamu telah menguasai salah satu **fitur lanjutan C++17** dalam STL!  
Beritahu aku jika kamu siap lanjut ke **Soal 15** — latihan terakhir `unordered_map` 🎯