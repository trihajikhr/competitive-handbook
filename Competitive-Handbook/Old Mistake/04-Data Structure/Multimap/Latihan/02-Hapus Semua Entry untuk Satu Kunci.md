---
obsidianUIMode: preview
note_type: latihan
latihan: Hapus Semua Entry untuk Satu Kunci
sumber: chatgpt.com
tags:
  - data-structure
  - multimap
date_learned: 2025-06-22T21:53:00
---
---
# Soal 2: Hapus Semua Entry untuk Satu Kunci

**Deskripsi**  
Buat sebuah program C++ yang membaca sejumlah pasangan (nama, nilai) ke dalam sebuah `multimap<string,int>`. Selanjutnya, program akan membaca satu buah nama dan menghapus **semua** entry yang memiliki nama tersebut dari `multimap`. Terakhir, cetak berapa banyak entry yang dihapus.

---

**Spesifikasi Input**

1. Baris pertama berisi bilangan bulat $N (1 \le N \le 10^5)$, jumlah pasangan yang akan dimasukkan.
    
2. $N$ baris berikutnya masing-masing berisi:
    
    - `string name` (tanpa spasi),
        
    - `int score` $(0 \le score \le 100)$.
        
3. Baris terakhir berisi satu `string target`, nama yang akan dihapus.
    

**Spesifikasi Output**

- Satu baris:
    
    ```
    Removed X entries for target
    ```
    
    di mana `X` adalah jumlah pasangan (entry) yang dihapus untuk kunci `target`.
    

---

**Contoh 1**  
_Input:_

```
5
Alice 90
Bob 85
Alice 95
Charlie 70
Bob 88
Bob
```

_Output:_

```
Removed 2 entries for Bob
```

**Contoh 2**  
_Input:_

```
3
Dina 80
Eka 75
Fiona 88
Gita
```

_Output:_

```
Removed 0 entries for Gita
```

---

Silakan implementasikan program sesuai spesifikasi di atas! Setelah selesai, kirim kodenya agar bisa kita cek bersama.

## Jawaban
### Jawaban pertama
Berikut adalah jawaban pertama yang masih bisa ditingkatkan lagi:

```cpp
#include<iostream>
#include<map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    multimap<string, int> mulmap;
    int n; cin >> n;

    string s; int x;
    while(n--){
        cin >> s >> x;
        mulmap.insert({s,x});
    }

    cin >> s;
    int cnt=0;
    if(mulmap.count(s)){
        auto range = mulmap.equal_range(s);

        for(auto it = range.first; it != range.second; it++){
            cnt++;
        }

        mulmap.erase(s);
    }

    cout << "Removed " << cnt << " entries for " << s << "\n";
    return 0;
}
```

### Jawaban yang dioptimalkan
Berikut adalah jawaban yang sudah mengikuti saran dari editorial:

```cpp
#include<iostream>
#include<map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    multimap<string, int> mulmap;
    int n; cin >> n;

    string s; int x;
    while(n--){
        cin >> s >> x;
        mulmap.insert({s,x});
    }

    cin >> s;
    size_t cnt = mulmap.erase(s);
    cout << "Removed " << cnt << " entries for " << s << "\n";
    return 0;
}
```

fungsi `erase()` akan langsung mengembalikan banyaknya entry yang dihapus! Sehingga tidak diperlukan perulangan!
# Editorial
Berikut **editorial per blok kode** untuk program soal nomor 2 yang kamu tulis:

```cpp
#include <iostream>
#include <map>
using namespace std;
```

- **Header**
    
    - `<iostream>`: untuk `cin`/`cout`
        
    - `<map>`: untuk `multimap`
        

---

```cpp
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
```

- **Optimasi I/O**  
    Sinkronisasi `iostream` dengan C-style I/O dimatikan, dan `cin.tie(nullptr)` memutus `cin` dari `cout` untuk mempercepat baca/tulis—standar di kompetitif programming.
    

---

```cpp
    multimap<string, int> mulmap;
    int n; 
    cin >> n;
```

- **Deklarasi dan Input jumlah data**
    
    - `mulmap`: menampung pasangan `(nama, nilai)` dengan kemungkinan duplikat nama.
        
    - `n`: banyaknya pasangan yang akan dibaca.
        

---

```cpp
    string s; 
    int x;
    while (n--) {
        cin >> s >> x;
        mulmap.insert({s, x});
    }
```

- **Membaca dan Menyisipkan data**
    
    - Setiap iterasi membaca `s` (nama) dan `x` (nilai), lalu `insert` ke dalam `multimap`.
        
    - `while(n--)` memastikan tepat `n` kali pembacaan.
        

---

```cpp
    cin >> s;
    int cnt = 0;
```

- **Input target**
    
    - Baca `s` sebagai nama yang akan dihapus seluruh entry-nya.
        
    - `cnt` akan menghitung jumlah entry yang dihapus (saat ini 0).
        

---

```cpp
    if (mulmap.count(s)) {
        auto range = mulmap.equal_range(s);
        for (auto it = range.first; it != range.second; ++it) {
            cnt++;
        }
        mulmap.erase(s);
    }
```

1. **`mulmap.count(s)`**  
    Mengecek apakah ada minimal satu entry untuk kunci `s`.
    
2. **`equal_range(s)`**  
    Mengambil dua iterator:
    
    - `first` menunjuk entri pertama dengan kunci `s`
        
    - `second` menunjuk satu posisi setelah entri terakhir
        
3. **Loop hitung**  
    Iterasi dari `range.first` ke `range.second` (eksklusif) untuk menambah `cnt`.
    
4. **`mulmap.erase(s)`**  
    Menghapus **semua** entry dengan kunci `s` sekaligus.
    

---

```cpp
    cout << "Removed " << cnt << " entries for " << s << "\n";
    return 0;
}
```

- **Output**  
    Mencetak `"Removed X entries for Y"`, di mana `X = cnt` dan `Y = s`.
    
- **Akhiri program** dengan `return 0;`.
    

---

### Catatan Tambahan

- Kamu bisa menyederhanakan penghitungan `cnt` dengan memanfaatkan nilai kembalian `erase`, yaitu:
    
    ```cpp
    size_t cnt = mulmap.erase(s);
    ```
    
    Karena `erase(key)` pada `multimap` sudah langsung mengembalikan jumlah entry yang dihapus, jadi tidak perlu loop `equal_range` + hitung manual.
    
- Kompleksitas keseluruhan:
    
    - Pembuatan dan penyisipan data: $O(N \log N)$
        
    - `count`, `equal_range`, dan `erase`: masing-masing $O(\log N)$ untuk pencocokan kunci, plus $O(k)$ jika ada kk entry dihapus.
        

Semoga editorial per blok ini lebih mudah kamu copy–paste! Kalau ada yang perlu didiskusikan lagi, beri tahu ya.