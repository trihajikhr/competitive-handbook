---
obsidianUIMode: preview
note_type: latihan
latihan: Gabungkan Dua Multimap
sumber: chatgpt.com
tags:
  - data-structure
  - multimap
date_learned: 2025-06-22T23:18:00
---
---
# Soal 5: Gabungkan Dua Multimap

**Deskripsi**  
Diberikan dua buah `multimap<string,int>` yaitu `A` dan `B`, masing-masing berisi pasangan `(nama, nilai)`. Gabungkan semua entry dari `B` ke `A` sehingga `A` menyimpan keseluruhan data dari keduanya. Setelah itu, tampilkan seluruh isi `A` secara berurutan berdasarkan kunci.

---

**Spesifikasi Input**

1. Baris pertama berisi integer nn: jumlah entry dalam `A`
    
2. Diikuti $n$ baris, masing-masing berisi:
    
    ```
    name value
    ```
    
3. Baris berikutnya berisi integer mm: jumlah entry dalam `B`
    
4. Diikuti $m$ baris, masing-masing berisi:
    
    ```
    name value
    ```
    

---

**Spesifikasi Output**

- Tampilkan seluruh isi multimap hasil gabungan (yaitu `A`) satu per baris:
    
    ```
    name value
    ```
    
    dengan urutan berdasarkan kunci (`name`) secara ascending (otomatis oleh `multimap`)
    

---

**Contoh 1**  
_Input:_

```
3
Alice 90
Bob 85
Alice 95
2
Charlie 70
Bob 88
```

_Output:_

```
Alice 90
Alice 95
Bob 85
Bob 88
Charlie 70
```

**Contoh 2**  
_Input:_

```
1
Zed 100
2
Anna 88
Zed 75
```

_Output:_

```
Anna 88
Zed 75
Zed 100
```

---

Silakan langsung kerjakan kodenya. Setelah selesai, kirim ke sini untuk kita bahas bersama!

## Jawabanku
Berikut adalah jawabanku yang sudah cukup optimal:

```cpp
#include<iostream>
#include<map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    multimap<string, int> A, B;
    int n, m, x; string s;
    
    cin >> n;
    while(n--){
        cin >> s >> x;
        A.insert({s,x});
    }

    cin >> m;
    while(m--){
        cin >> s >> x;
        B.insert({s,x});
    }

    A.merge(B);

    for(const auto& [key, val]: A){
        cout << key << " " << val << "\n";
    }
    return 0;
}
```

# Editorial
Jawabanmu **sudah sangat tepat dan efisien**—menggunakan `multimap::merge()` adalah solusi paling bersih untuk kasus ini.

Seperti biasa, berikut **editorial per blok kode** untuk dokumentasi atau laporanmu:

---

```cpp
#include <iostream>
#include <map>
using namespace std;
```

- **Header**
    
    - `<iostream>`: untuk input/output
        
    - `<map>`: untuk menggunakan `multimap`
        

---

```cpp
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
```

- **Optimasi I/O** agar `cin` dan `cout` bekerja lebih cepat.
    

---

```cpp
    multimap<string, int> A, B;
    int n, m, x;
    string s;
```

- Deklarasi dua buah `multimap`:
    
    - `A`: kontainer utama
        
    - `B`: kontainer yang akan digabungkan ke `A`
        
- `n`, `m`: jumlah entry masing-masing
    
- `s`, `x`: untuk membaca input `(name, value)`
    

---

```cpp
    cin >> n;
    while(n--) {
        cin >> s >> x;
        A.insert({s, x});
    }

    cin >> m;
    while(m--) {
        cin >> s >> x;
        B.insert({s, x});
    }
```

- Membaca data ke dalam multimap `A` dan `B`
    
- Setiap pasangan `(s, x)` disisipkan ke multimap masing-masing
    

---

```cpp
    A.merge(B);
```

- Menggabungkan semua isi `B` ke dalam `A`
    
- **Setelah ini, `B` akan kosong**, dan `A` berisi semua data
    
- Karena `multimap` mendukung duplikat kunci, tidak ada konflik saat `merge`
    

---

```cpp
    for (const auto& [key, val] : A) {
        cout << key << " " << val << "\n";
    }
```

- Menampilkan seluruh isi `A` setelah penggabungan
    
- Secara otomatis terurut berdasarkan `key` karena sifat `multimap`
    

---

### Alternatif: Tanpa `merge()`

Jika compiler tidak mendukung `merge()` (misal standar C++ versi lama), bisa diganti dengan:

```cpp
for (const auto& [key, val] : B) {
    A.insert({key, val});
}
```

---

Siap untuk **Soal 6**? Atau mau lanjut review bagian mana dulu?