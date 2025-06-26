---
obsidianUIMode: preview
note_type: latihan
latihan: Frekuensi Elemen
sumber: Google.com, AI
tags:
  - data-structure
  - vector
date_learned: 2025-06-14T21:44:00
---
---
# Frekuensi Elemen

## Soal 5: Frekuensi Elemen

Buat program C++ yang:

1. Baca bilangan bulat `N` (1 ≤ N ≤ 100 000).
    
2. Baca `N` bilangan bulat dan simpan di `vector<int> arr`.
    
3. Hitung frekuensi kemunculan tiap elemen di `arr`.
    
4. Cetak tiap elemen unik bersama jumlah kemunculannya, dalam urutan **muncul pertama kali**.
    

### Contoh

```
Input:
7
4 2 4 3 2 4 5

Output:
4 3
2 2
3 1
5 1
```

**Petunjuk:**

- Gunakan `unordered_map<int,int> freq;` untuk hitung frekuensi.
    
- Gunakan `vector<int> order;` untuk mencatat urutan unik pertama kali muncul.
    
- Saat traversal:
    
    ```cpp
    for (int v : arr) {
        if (freq[v]++ == 0)
            order.push_back(v);
    }
    ```
    
- Setelah itu, iterasi `order` untuk mencetak `v` dan `freq[v]`.
    

Kerjakan Soal 5, lalu kirim kodenya—aku akan cek kembali! 😊

## Jawabanku
Kode program untuk jawabaku:

```cpp
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(auto&x:arr) cin >> x;

    unordered_map<int, int> rest;

    for(const auto&x:arr){
        rest[x]++;
    }

    unordered_map<int,int>::iterator iter;
    for(iter = rest.begin(); iter != rest.end(); iter++){
        cout << iter->first << " " << iter->second << "\n";
    }

    return 0;
}
```

### Tanggapan kesalahan
Beberapa hal yang perlu diperhatikan di kodenya:

1. **Urutan Cetak**  
    Dengan iterasi langsung `for(iter = rest.begin(); …)`, kamu akan mendapatkan elemen dalam urutan hash map—bukan urutan kemunculan pertama di input. Untuk menjaga “first-seen order”, kita perlu menyimpan elemen unik dalam `vector<int> order` saat pertama kali kita melihatnya.
    
2. **Gabungkan Hitung & Rekam Urutan**  
    Daripada dua loop terpisah, biasanya kita lakukan sekaligus:
    
    ```cpp
    unordered_map<int,int> freq;
    vector<int> order;
    for (int v : arr) {
        if (freq[v]++ == 0)
            order.push_back(v);
    }
    ```
    
    Di sini, `freq[v]++ == 0` artinya ini adalah kemunculan pertama, jadi kita `push_back(v)` ke `order`.
    
3. **Cetak Sesuai `order`**  
    Setelah itu, cukup:
    
    ```cpp
    for (int v : order) {
        cout << v << " " << freq[v] << "\n";
    }
    ```
    

---

 Coba perbaiki kode-mu agar output mengikuti urutan elemen muncul pertama kali.

### Jawaban Akhir
Kode program jawaban yang sudah direvisi:

```cpp
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(auto&x:arr) cin >> x;

    unordered_map<int,int> freq;
    vector<int> order;
    for (int v : arr) {
        if (freq[v]++ == 0)
            order.push_back(v);
    }

    for(const auto & x: order){
        cout << x << " " << freq[x] << "\n";
    }
    return 0;
}
```

## Editorial
1. **Baca Input**
    
    - `n` elemen dibaca dan disimpan dalam `vector<int> arr`.
        
2. **Hitung Frekuensi & Rekam Urutan Muncul**
    
    - Gunakan `unordered_map<int,int> freq` untuk mencatat berapa kali tiap nilai muncul.
        
    - Gunakan `vector<int> order` untuk mencatat nilai-nilai unik sesuai kali pertama mereka dilihat.
        
    - Saat men-traverse `arr`:
        
        ```cpp
        if (freq[v]++ == 0)
            order.push_back(v);
        ```
        
        - `freq[v]++ == 0` berarti ini kemunculan pertama `v`, sehingga kita tambahkan ke `order`.
            
        - Terlepas dari apakah pertama kali atau tidak, `freq[v]` tetap di-increment, jadi peta frekuensi selalu terbarui.
            
3. **Cetak Hasil**
    
    - Iterasi `order` memastikan output mengikuti urutan kemunculan unik pertama kali.
        
    - Untuk tiap `v` di `order`, cetak `v` dan `freq[v]`.
        
4. **Kompleksitas**
    
    - Waktu: O(N) rata-rata, karena operasi pada `unordered_map` adalah O(1) average per akses.
        
    - Memori: O(N) untuk menyimpan `arr`, `freq`, dan `order`.
        
5. **Kelebihan & Catatan**
    
    - Menjamin urutan “first-seen” tanpa perlu struktur data berurut (seperti `map` atau vector scan berulang).
        
    - Cukup ringkas dan clear karena memisahkan logika frekuensi dan urutan ke dua container yang tepat.
        

Dengan begitu, kamu mendapatkan daftar elemen unik plus jumlah kemunculannya dalam satu pass efisien! 😊