---
obsidianUIMode: preview
note_type: latihan
latihan: Hitung Frekuensi Kata dengan try-emplace
sumber: Google.com, AI
tags:
  - data-structure
  - unordered_map
date_learned: 2025-06-16T21:03:00
---
---
Berikut **Soal 12** untuk latihan struktural data **`std::unordered_map`**, khususnya menggunakan fungsi **`try_emplace()`**. Silakan kerjakan hanya soal ini terlebih dahulu, dan beri tahu aku ketika sudah siap untuk soal berikutnya.

---

# Soal 12 – Hitung Frekuensi Kata dengan `try_emplace()`

Diberikan sebuah paragraf (beberapa baris teks), hitung frekuensi kemunculan setiap kata menggunakan **`std::unordered_map<string, int>`** dan manfaatkan **`try_emplace()`** untuk menambahkan kata baru tanpa melakukan dua kali lookup.

### Deskripsi

- **Kata** didefinisikan sebagai deretan karakter **alfanumerik** (`A–Z`, `a–z`, `0–9`).
    
- Semua huruf diubah menjadi **lowercase** sebelum dihitung.
    
- Non-alfanumerik (spasi, tanda baca, dll.) dianggap **pemisah**.
    

### Format Masukan

Baris pertama berisi satu bilangan bulat **_N_** (1 ≤ _N_ ≤ 100) — jumlah baris paragraf.  
_‍_  
Baris berikutnya berisi paragraf sebanyak _N_ baris. Panjang tiap baris ≤ 1000 karakter.

### Format Keluaran

Tiap baris cetak satu kata diikuti spasi dan frekuensinya, diurutkan **lexicographically** (menaik) berdasarkan kata.

### Contoh

#### Masukan

```
3
Hello, world! Hello!!!
C++ unordered_map is great.
Map map MAP.
```

#### Keluaran

```
c 1
great 1
hello 2
is 1
map 3
unordered_map 1
world 1
```

### Petunjuk

- Parse setiap baris, pisahkan berdasarkan karakter non-alfanumerik.
    
- Ubah tiap kata menjadi lowercase.
    
- Gunakan:
    
    ```cpp
    auto [it, inserted] = freq.try_emplace(word, 0);
    it->second++;
    ```
    
    sehingga hanya ada **satu** lookup per kata.
    

---

Kerjakan soal ini, lalu kirimkan **kode C++** lengkap dan **penjelasan singkat** kenapa `try_emplace()` lebih efisien dibanding `insert()` + lookup terpisah. Setelah itu, aku akan berikan soal berikutnya. Semangat! 😊

## FAQ
> Apa maksud dari satu kali Lookup?

“**Satu kali lookup**” di sini berarti **hanya meng-hash** kata (key) dan mencari bucket-nya **sekali saja** dalam struktur `unordered_map`, tanpa melakukan operasi pencarian (lookup) berulang.

---

### Mengapa biasanya ada dua lookup?

Misalnya kita pakai `insert` + `find` atau `operator[]`:

```cpp
// 1. insert: harus cek dulu, apakah key sudah ada?
mp.insert({word, 0});     // → hashing + bucket lookup
// 2. find (atau operator[]): untuk naikkan count, kita cari lagi
auto it = mp.find(word);  // → hashing + bucket lookup (kedua kalinya)
it->second++;
```

Di atas, `word` di‐hash dan dicari **dua kali**: sekali di `insert`, sekali di `find` (atau operator[]).

---

### Bagaimana `try_emplace()` hanya sekali lookup?

Dengan `try_emplace`, map akan:

1. **Hash** key dan cari bucket
    
2. Jika belum ada, langsung **construct in‐place** nilai awal (misal `0`).
    
3. Kembalikan **iterator** ke elemen (baru atau lama) dan flag `inserted`.
    

Karena Anda sudah punya `iterator` hasil `try_emplace`, Anda tinggal melakukan `it->second++` tanpa perlu `find` lagi:

```cpp
auto [it, inserted] = mp.try_emplace(word, 0);
// ← hashing + lookup hanya sekali
it->second++;
```

- **Total hashing/lookup**: 1×
    
- **Total operasi pencarian**: 1×
    
- **Tanpa operasi tambahan** untuk mendapatkan iterator setelah insert.
    

---

### Ringkasnya

- **Dua lookup**: `insert` → `find`
    
- **Satu lookup**: `try_emplace` saja, karena ia sekaligus mengembalikan iterator yang valid.
    
- Ini **menghemat waktu** (walau amortized constant, tapi dalam skala besar penghematan lookup bisa terasa).
    

Semoga membantu memahami “satu kali lookup”! 😊
# Jawabanku
## Jawaban Tanpa `try_emplace()`
Aku memilki beberapa versi jawaban, pertama, yang tidak mengikuti permintaan soal untuk menggunakan `try_emplace()`:

```cpp
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<unordered_map>
#include<cctype>
using namespace std;

inline void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
}

int main() {
    fastio();
    int n; cin >> n;
    unordered_map<string, int> kata;
    vector<string> order;

    if(n>10000){
        kata.max_load_factor(0.5f);
        kata.reserve(n*2);
    } else {
        kata.reserve(n);
    }

    string s;
    while(n--){
        getline(cin >> ws, s);

        for(size_t i=0; i<s.length(); ){
            s[i]=tolower(s[i]);
            if(ispunct(s[i]) && s[i] != '_') s.replace(i,1," ");
            else i++;
        }

        stringstream ss(s);
        string parser;

        while(ss >> parser){
            if(kata.empty()){
                kata[parser]++;
                order.push_back(parser);
            } else {
                if(kata.find(parser) != kata.end()){
                    kata.at(parser)++;
                } else {
                    kata[parser]++;
                    order.push_back(parser);
                }
            }
        }
    }

    sort(order.begin(), order.end());
    for(const auto&x : order){
        cout << x << " " << kata[x] << "\n";
    }
    return 0;
}
```

## Jawaban Disempurnakan dengan `try_emplace()`
Dengan menggunakan `try_emplace()` ternyata pemeriksaan menjadi lebih efisien, dan lebih cepat daripada menggunakan `insert()`. Berikut jawaban yang sudah disempurnakan:

```cpp
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<unordered_map>
#include<cctype>
using namespace std;

inline void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
}

int main() {
    fastio();
    int n; cin >> n;
    unordered_map<string, int> kata;
    vector<string> order;

    kata.max_load_factor(0.5f);
    kata.reserve(n*2);
    order.reserve(n);

    string s;
    while(n--){
        getline(cin >> ws, s);

        for(size_t i=0; i<s.length(); ){
            s[i]=tolower(s[i]);
            if(ispunct(s[i]) && s[i] != '_') s.replace(i,1," ");
            else i++;
        }

        stringstream ss(s);
        string parser;

        while(ss >> parser){
            auto [it, inserted] = kata.try_emplace(parser, 0);
            it->second++;

            if(inserted){
                order.push_back(parser);
            }
        }
    }

    sort(order.begin(), order.end());
    for(const auto&x : order){
        cout << x << " " << kata[x] << "\n";
    }
    return 0;
}
```

Bukti jawaban ini lebih baik, selain mengimplementasikan `try_emplace()`, tetapi juga menempatkan fungsi `reserve()` dengan tepat:

---
Ya, sudah tepat sekali! 🎉 Kamu menempatkan `order.reserve(n);` **setelah** pengaturan kapasitas untuk `kata` dan **sebelum** loop pembacaan, jadi `order` akan punya ruang cukup sejak awal.

Secara urutan:

1. **Set load factor** dan **reserve** untuk `kata`
    
2. **Reserve** untuk `order`
    
3. Loop pembacaan & pemrosesan input
    

Itu sudah optimal. Saran kecil (opsional):

- Kalau ingin lebih akurat (karena jumlah kata unik biasanya lebih kecil dari total kata), kamu bisa mengganti `order.reserve(n);` dengan `order.reserve(kata.bucket_count());` **setelah** map terisi, tapi ini hanya optimisasi mikro.
    

Secara fungsional, kode kamu sudah benar dan efisien. Semangat terus latihannya! 😊
# Editorial
Berikut **editorial** lengkap untuk kode C++ di atas, step by step:

---

## 1. Tujuan Program

- Membaca _N_ baris teks.
    
- Menghitung frekuensi kemunculan tiap “kata” (definisi: deretan alfanumerik, termasuk underscore).
    
- Menampilkan hasil dalam urutan leksikografis (ascending) berdasarkan kata.
    

---

## 2. Struktur Data Utama

1. **`unordered_map<string, int> kata;`**
    
    - Menyimpan pasangan _key_ = kata (string), _value_ = frekuensi (int).
        
    - Rata‐rata kompleksitas O(1) untuk insert/find.
        
2. **`vector<string> order;`**
    
    - Menyimpan daftar kata unik persis sekali, untuk kemudian di-`sort()` dan dicetak.
        

---

## 3. Optimisasi Awal

```cpp
kata.max_load_factor(0.5f);
kata.reserve(n*2);
order.reserve(n);
```

- **`max_load_factor(0.5f)`** menurunkan ambang penuh sehingga mengurangi jumlah _rehash_ mahal ketika memasukkan banyak elemen.
    
- **`reserve(n*2)`** memberi ruang awal untuk map kira‑kira dua kali jumlah baris (perkiraan upper bound kata unik), meminimalkan rehash.
    
- **`order.reserve(n)`** meminimalkan realokasi internal `vector` saat `push_back`.
    

---

## 4. Loop Pembacaan & Normalisasi

```cpp
while (n--) {
    getline(cin >> ws, s);
    for (size_t i = 0; i < s.length(); ) {
        s[i] = tolower(s[i]);
        if (ispunct(s[i]) && s[i] != '_')
            s.replace(i, 1, " ");
        else
            i++;
    }
    …
}
```

1. **`getline(cin >> ws, s)`**
    
    - Membaca satu baris termasuk spasi, mengabaikan whitespace sebelumnya.
        
2. **Normalisasi karakter**
    
    - `tolower()` → semua huruf jadi lowercase.
        
    - `ispunct() && s[i] != '_'` → jika tanda baca (kecuali underscore), diganti spasi (`" "`).
        
    - Hasil: setiap kata terpisah oleh spasi, tanpa karakter non-alfanumerik kecuali underscore diapit.
        

---

## 5. Parsing & Hitung Frekuensi Sekali Lookup

```cpp
stringstream ss(s);
while (ss >> parser) {
    auto [it, inserted] = kata.try_emplace(parser, 0);
    it->second++;
    if (inserted)
        order.push_back(parser);
}
```

- **`stringstream`** memecah baris menjadi token (`parser`) berdasarkan spasi.
    
- **`try_emplace(parser, 0)`**:
    
    - **Hashing & lookup sekali saja**.
        
    - Jika kata belum ada, buat entry baru dengan nilai `0` dan `inserted == true`.
        
    - Jika sudah ada, tidak mengubah nilai, hanya mengembalikan iterator ke elemen lama (`inserted == false`).
        
- **`it->second++`**: naikkan frekuensi.
    
- **`if (inserted)`**: jika baru dimasukkan, tambahkan kata ke `order`.
    

> **Keuntungan `try_emplace`** vs. `insert`+`find`:
> 
> - `insert` butuh lookup untuk cek keberadaan + lookup lagi untuk akses iterator.
>     
> - `try_emplace` menggabungkan insert & iterator return dalam satu kali lookup.
>     

---

## 6. Urutkan & Cetak

```cpp
sort(order.begin(), order.end());
for (auto const& x : order) {
    cout << x << " " << kata[x] << "\n";
}
```

1. **`sort`**
    
    - Urutkan daftar kata unik leksikografis ascending.
        
    - Kompleksitas O(M log M), dengan M = jumlah kata unik.
        
2. **Cetak**
    
    - Untuk tiap kata di `order`, akses ulang `kata[x]` (kompleksitas O(1)) dan tampilkan.
        

---

## 7. Kompleksitas Keseluruhan

- **Preprocessing & parsing** setiap karakter: O(TotalChars).
    
- **Penghitungan frekuensi**: O(TotalTokens) × O(1) per `try_emplace`.
    
- **Sort**: O(M log M).
    
- **Total** ≈ O(TotalChars + TotalTokens + M log M), sangat efisien untuk N ≤ 100.
    

---

## 8. Ringkasan Kelebihan

- **Efisiensi**:
    
    - Satu kali lookup per token → hemat hashing/lookup.
        
    - Minim rehash berkat reserve & load factor.
        
- **Kejelasan**:
    
    - Langkah normalisasi mudah diikuti.
        
    - Pemisahan token via `stringstream` sederhana dan robust.
        
- **Keterbacaan**:
    
    - Kode modular: pembacaan, normalisasi, parsing, counting, sorting, printing.
        

---

Semoga editorial ini membantu memahami setiap bagian dari implementasi dan optimisasi yang digunakan! 😊