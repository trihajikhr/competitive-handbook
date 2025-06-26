---
obsidianUIMode: preview
note_type: latihan
latihan: Unordered Map – Frekuensi Elemen
sumber: Google.com, AI
tags:
  - data-structure
  - unordered_map
date_learned: 2025-06-16T13:17:00
---
---
# Unordered Map – Frekuensi Elemen

 **Deskripsi:**  
 Diberikan sebuah array `arr` berisi `N` bilangan bulat.  
 Tugasmu adalah menghitung frekuensi kemunculan tiap elemen di array tersebut menggunakan `unordered_map`, lalu mencetak setiap elemen beserta jumlah kemunculannya sesuai urutan kemunculan pertama kali.
 
 **Format Input:**
 
 ```
 N
 arr[0] arr[1] … arr[N-1]
 ```

 - `1 ≤ N ≤ 10^5`
     
 - `-10^9 ≤ arr[i] ≤ 10^9`
     
 
 **Format Output:**  
 Untuk setiap elemen unik di `arr`, cetak
  ```
nilai : frekuensi
 ```

 dalam satu baris, sesuai urutan elemen tersebut muncul pertama kali di array.

**Contoh:**

```
Input:
7
4 2 4 5 2 3 4

Output:
4 : 3
2 : 2
5 : 1
3 : 1
```

---

Silakan kerjakan soal ini di file Obsidian-mu. Kalau sudah selesai atau ada kendala, tinggal kirim solusinya, lalu kita lanjut ke soal berikutnya! 🚀

# Jawaban | 1
Berikut adalah jawabanku, yang mash bisa ditingkatkan:

```cpp
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> input(n);
    for(auto & x: input) cin >> x;

    unordered_map<int,int> freq;
    unordered_map<int, bool> out;
    for(const auto&x: input) {
        freq[x]++;
        out[x]=true;
    }

    for(int i=0; i<n; i++){
        if(out[input[i]]){
            cout << input[i] << ": " << freq[input[i]] << "\n";
            out[input[i]] = false;
        }
    }
    return 0;
}
```


## Editorial
Berikut editorial lengkap untuk solusi “Unordered Map – Frekuensi Elemen”:

---

## 1. Ide Utama

- **Hitung frekuensi** setiap elemen dengan `unordered_map<int,int> freq`.
    
- **Catat elemen yang sudah dicetak** dengan `unordered_map<int,bool> seen` (alias `out` dalam kode) untuk menjaga **orde kemunculan pertama**.
    

---

## 2. Langkah–langkah Algoritma

1. **Baca input**
    
    ```cpp
    int n; 
    cin >> n;
    vector<int> input(n);
    for (auto &x : input) 
        cin >> x;
    ```
    
    - `n` adalah panjang array.
        
    - `input` menyimpan elemen-elemen yang akan diproses.
        
2. **Bangun peta frekuensi**
    
    ```cpp
    unordered_map<int,int> freq;
    unordered_map<int,bool> out;
    for (const auto &x : input) {
        freq[x]++;      // hitung +1 tiap muncul
        out[x] = true;  // tandai sebagai “belum dicetak”
    }
    ```
    
    - `freq[x]` akan menjadi total kemunculan `x`.
        
    - `out[x] = true` artinya elemen `x` **siap** untuk dicetak sekali pertama kali.
        
3. **Cetak sesuai urutan pertama**
    
    ```cpp
    for (int i = 0; i < n; i++) {
        int v = input[i];
        if (out[v]) {
            cout << v << " : " << freq[v] << "\n";
            out[v] = false;  // tandai sudah dicetak
        }
    }
    ```
    
    - Iterasi ulang `input` dari indeks 0…n−1.
        
    - Jika `out[v] == true`, artinya ini **kemunculan pertama** dari `v` → cetak dan ubah `out[v] = false` agar tidak dicetak ulang.
        

---

## 3. Kompleksitas

- **Waktu**: rata‑rata _O(n)_
    
    - Mengisi `freq` dan `out` pada satu loop → O(n)
        
    - Loop cetak juga O(n)
        
- **Memori**: O(n) untuk menyimpan `input`, O(k) untuk `freq`/`out` (k = jumlah elemen unik ≤ n).
    

---

## 4. Catatan dan Peningkatan

- **Reserve kapasitas map**
    
    ```cpp
    freq.reserve(n);
    out.reserve(n);
    ```
    
    Bisa mengurangi _rehashes_ jika `n` besar.
    
- **Alternatif tanpa map**  
    Gunakan `vector<int> order;` untuk mencatat urutan unik:
    
	```cpp
	vector<int> order;
	for(const auto &x :input){
		freq[x]++;
		if(freq[x]==1){
			order.push_back(x);
		}
	}
	
	for (const auto & x : order) {
		cout << x << " : " << freq[x] << "\n";
	}
    ```
    
    → Lebih simpel, hanya satu `unordered_map<int,int>`.
    

---

Soal 1 selesai! 🎉  
Kalau sudah paham dan siap, kita lanjut ke **Soal 2**. Mau langsung lanjut?

# Jawaban | 2
Berikut adalah versi yang lebih baik:

```cpp
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> input(n);
    for(auto & x: input) cin >> x;

    unordered_map<int,int> freq;
    freq.reserve(n);

    vector<int> order;
    for(const auto &x :input){
        freq[x]++;
        if(freq[x]==1){
            order.push_back(x);
        }
    }

    for (const auto & x : order) {
        cout << x << " : " << freq[x] << "\n";
    }
    return 0;
}
```

## Editorial

Bagus sekali! 🎉 Solusi barumu sudah lebih ringkas dan efisien. Beberapa poin penting:

1. **Hanya satu `unordered_map`**  
    – Kamu menghilangkan map kedua untuk tracking boolean, jadi hanya `freq` satu-satunya, lebih hemat memori dan kode lebih bersih.
    
2. **Menggunakan `vector<int> order`**  
    – Saat `freq[x]` jadi 1, kamu tahu itu kemunculan pertama → langsung `order.push_back(x)`. Dengan begitu urutan kemunculan terjaga tanpa perlu map tambahan.
    
3. **Reserve kapasitas**  
    – `freq.reserve(n);` meminimalkan rehashing, sangat berguna saat `n` besar.
    
4. **Kompleksitas tetap O(n)**  
    – Loop pertama untuk isi `freq` dan `order` O(n), loop kedua untuk output juga O(k) (k = jumlah unik ≤ n).
    

### Catatan kecil

- Jika datamu sangat besar dan load factor default masih terasa tinggi, kamu bisa mengatur `freq.max_load_factor()` agar lebih agresif dalam alokasi bucket sebelum rehash.
    
- Jangan lupa cek edge case `n = 0`, meski biasanya batas soal dimulai dari 1.
    

### max_load_factor()
Hampir—tapi `max_load_factor()` perlu kamu beri nilai float agar unordered_map tahu seberapa “padat” bucket-nya boleh sebelum di‑rehash. Contohnya:

```cpp
unordered_map<int,int> freq;

if (n > 10000) {
    // Turunkan load factor, jadi reseving bisa alokasi lebih banyak bucket awal
    freq.max_load_factor(0.5f);       
    // Karena load_factor = 0.5, kita reserve 2× bucket untuk n elemen
    freq.reserve(n * 2);              
} else {
    // Load factor default (~1.0) cukup untuk n kecil
    freq.reserve(n);
}
```

Penjelasan:

1. **`max_load_factor(0.5f)`**  
    Membuat map rela menyimpan maksimal 1 elemen per 0.5 bucket. Artinya akan ada 2 bucket per elemen pada reserve selanjutnya, mengurangi kemungkinan collision.
    
2. **`reserve(bucket_count)`**  
    Parameter di `reserve()` bukan jumlah elemen, melainkan jumlah _buckets_. Karena kita menurunkan load factor, kita perlu `reserve(n / load_factor)` → di contoh: `n * 2`.
    
3. Untuk _cases_ kecil (`n ≤ 10000`) load factor default (`1.0`) sudah OK, jadi cukup `reserve(n)`.
    

Dengan cara ini kamu meminimalisir rehashing dan collision saat data besar, tetap ringkas dan efektif. 🚀

# Jawaban | 3
Beriut adalah jawaban final:

```cpp
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
    int n; cin >> n;
    if(n==0) return 0;
    vector<int> input(n);
    for(auto & x: input) cin >> x;

    unordered_map<int,int> freq;

    if (n > 10000) {
        freq.max_load_factor(0.5f);       
        freq.reserve(n * 2);              
    } else {
        freq.reserve(n);
    }
    

    vector<int> order;
    for(const auto &x :input){
        freq[x]++;
        if(freq[x]==1){
            order.push_back(x);
        }
    }

    for (const auto & x : order) {
        cout << x << " : " << freq[x] << "\n";
    }
    return 0;
}
```

## Editorial
### ✅ Penilaian: **10/10**

#### 🎯 Kriteria Penilaian:

|Aspek|Status|Catatan|
|---|---|---|
|Kompilasi|✔️|Tidak ada error|
|Efisiensi waktu|✔️|O(n) dengan `unordered_map`|
|Efisiensi memori|✔️|Menggunakan `reserve()` dan `max_load_factor()`|
|Kejelasan kode|✔️|Struktur bersih dan mudah dibaca|
|Edge case (`n == 0`)|✔️|Diperiksa di awal|
|Format output|✔️|Sesuai spesifikasi soal: `nilai : frekuensi`|

---

### 💡 Catatan Plus:

- Kamu sudah **menerapkan best practice** yang sering diremehkan pemula: _optimisasi bucket & load factor_ untuk dataset besar.
    
- Penanganan urutan unik pakai `vector<int> order` sangat tepat.
    

---

Kalau kamu ingin menyimpan ini sebagai versi final di Obsidian, ini bisa kamu beri nama:

```
Soal 1 - Frekuensi Elemen (unordered_map)
```

Kalau sudah siap, lanjut kita ke **Soal 2**? 😎