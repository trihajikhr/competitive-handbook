---
obsidianUIMode: preview
note_type: latihan
latihan: Set of Sets
sumber: chatgpt.com
tags:
  - data-structure
  - set
date_learned: 2025-06-21T00:03:00
---
---
🔥 Tantangan 15 — The Grand Finale: Set di dalam Set (Nested Set)

---

# 🧩 Deskripsi Soal — Set of Sets

**Fokus:** Memahami bagaimana menyimpan struktur data kompleks dalam `std::set`, khususnya `set<set<int>>`.

---

### 🧠 Deskripsi Masalah:

Buat program yang:

1. Membaca `n` himpunan (tiap himpunan berisi bilangan unik, terurut otomatis)
    
2. Menyimpan semua himpunan ke dalam `set<set<int>>`
    
3. Mencetak semua himpunan dalam urutan leksikografis
    

---

### 📝 Format Input:

- Baris pertama: bilangan bulat `n` (jumlah himpunan)
    
- Untuk setiap himpunan:
    
    - Baris pertama: bilangan bulat `k` (banyaknya elemen)
        
    - Baris berikutnya: `k` bilangan bulat
        

---

### 🖨️ Format Output:

- Cetak setiap himpunan satu per baris, elemen dipisahkan spasi
    
- Urutkan hasil secara **leksikografis (default urutan `set<set<int>>`)**
    

---

### 📌 Contoh Input:

```
3
3
1 2 3
3
2 3 4
2
1 2
```

### ✅ Contoh Output:

```
1 2
1 2 3
2 3 4
```

---

### 🧠 Catatan:

- Kamu bisa gunakan `set<int> s;` untuk satu himpunan
    
- Lalu `set<set<int>> kumpulan;` untuk menyimpan semuanya
    
- Karena `std::set` sudah punya perbandingan leksikografis otomatis, kamu tidak perlu membuat comparator manual
    

---

Kalau siap, langsung kirimkan kodenya ya — ini tantangan terakhir dan penutup latihan advance `std::set`! 🚀

## Jawabanku
Berikut adalah jawabanku untuk problem ini:

```cpp
#include<iostream>
#include<set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    set<int> s;
    set<set<int>> himp;

    int n; cin >> n;
    while(n--){
        int m; cin >> m;
        for(int i=0, x; i<m; i++){
            cin >> x;
            s.insert(x);
        }

        himp.emplace(s);
        s.clear();
    }

    for(const auto& in: himp){
        for(auto element: in){
            cout << element << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
```

# Editorial
🔥 **Luar biasa!** Kamu telah menyelesaikan **Tantangan 15 — Set di dalam Set** dengan **benar dan efisien!**  
Semua aspek penting kamu tangani dengan tepat. Berikut ini ulasan singkat:

---

### ✅ Pemeriksaan Kode:

1. **Struktur data yang digunakan:**
    
    ```cpp
    set<int> s;
    set<set<int>> himp;
    ```
    
    ✔️ Benar — `s` untuk menyusun satu himpunan, `himp` untuk menyimpan semua himpunan.
    
2. **Input loop:**
    
    - Kamu menggunakan `s.clear()` agar `set<int>` bisa dipakai ulang tanpa data sisa.  
        ✔️ Sangat efisien dan idiomatik.
        
3. **Penggunaan `emplace`:**
    
    ```cpp
    himp.emplace(s);
    ```
    
    ✔️ Lebih efisien daripada `insert(s)`.
    
4. **Output:**
    
    - Kamu mencetak elemen tiap `set<int>` dalam `set<set<int>>` baris per baris.  
        ✔️ Sudah sesuai permintaan soal.
        

---

### 🧪 Uji Contoh:

#### Input:

```
3
3
1 2 3
3
2 3 4
2
1 2
```

#### Output:

```
1 2
1 2 3
2 3 4
```

✅ **Benar dan rapi**

---

### 📌 Catatan Tambahan (Opsional):

- Jika kamu ingin menghindari deklarasi ulang `s` dan `s.clear()`, kamu juga bisa langsung:
    
    ```cpp
    set<int> s;
    for (...) {
        cin >> x;
        s.insert(x);
    }
    himp.emplace(move(s));
    ```
    
    Tapi pendekatanmu sekarang sudah **sangat aman dan mudah dibaca**.
    

---

### 🏁 Selamat!

🎉 Kamu telah menyelesaikan **15 tantangan `std::set`**, dari dasar hingga tingkat lanjut:

- 🔹 insert, erase, find, contains
    
- 🔹 iterasi biasa & reverse
    
- 🔹 custom comparator
    
- 🔹 set of pair & struct
    
- 🔹 lower_bound, upper_bound, equal_range
    
- 🔹 dan nested set (set of sets)
    

---

Kalau kamu ingin tantangan baru untuk `std::map`, `multiset`, atau `priority_queue`, tinggal bilang saja.  
Atau kita bisa mulai latihan `graph`, `string`, atau STL lanjutan seperti `unordered_map` tingkat expert. 🚀