---
obsidianUIMode: preview
note_type: latihan
latihan: Hapus Semua Nilai di Bawah Ambang Tertentu
sumber: chatgpt.com
tags:
  - data-structure
  - multimap
date_learned: 2025-06-23T15:35:00
---
---
# Soal 10: Hapus Semua Nilai di Bawah Ambang Tertentu

**Deskripsi**  
Diberikan sebuah `multimap<string, int>` berisi pasangan `(nama, nilai)`.  
Diberikan pula sebuah bilangan bulat `T` sebagai **ambang batas**.  

Tugasmu adalah menghapus semua entry yang nilai-nya **kurang dari T**, lalu mencetak seluruh isi multimap setelah penghapusan.

---

**Spesifikasi Input**

1. Baris pertama: integer N — jumlah entry
    
2. N baris berikutnya:
    
    ```
    name value
    ```
    
3. Baris terakhir: integer T — ambang nilai
    

---

**Spesifikasi Output**

- Jika setelah penghapusan tidak ada entry tersisa, cetak:
    
    ```
    Semua data terhapus
    ```
    
- Jika masih ada entry, tampilkan seluruh isi multimap yang tersisa, satu per baris:
    
    ```
    name value
    ```
    
    dengan urutan berdasarkan key (`name`) secara ascending
    

---

**Contoh 1**  
_Input:_

```
6
Alice 90
Bob 85
Alice 60
Charlie 70
Bob 50
Alice 95
70
```

_Output:_

```
Alice 90
Alice 95
Bob 85
Charlie 70
```

---

**Contoh 2**  
_Input:_

```
4
A 50
B 60
C 40
D 20
61
```

_Output:_

```
Semua data terhapus
```

---

Langsung implementasikan, kirim ke sini kalau sudah, kita review dan tutup rangkaian dasar `multimap` ini! 💪

## Jawabanku
Berikut adalah jawabanku untuk problem ini:

```cpp
#include<iostream>
#include<iterator>
#include<map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    multimap<string, int> mulmap;
    int n, x; string s;
    cin >> n;

    while(n--){
        cin >> s >> x;
        mulmap.insert({s,x});
    }

    int t; cin >> t;

    multimap<string, int>::iterator iter;
    for(iter = mulmap.begin(); iter != mulmap.end();){
        if(iter -> second <t){
            iter = mulmap.erase(iter);
        } else {
            iter++;
        }
    }

    if(!mulmap.empty()){
        for(const auto& [key, val]: mulmap){
            cout << key << " " << val << "\n";
        }
    } else cout << "Semua data terhapus\n";

    return 0;
}
```

# Editorial
✅ **Sempurna!**  
Kamu berhasil menyelesaikan soal nomor 10 dengan cara yang efisien dan benar.

---

Berikut **editorial per blok kode**, seperti biasa untuk dokumentasi atau laporanmu:

---

```cpp
#include <iostream>
#include <iterator>
#include <map>
using namespace std;
```

- Header:
    
    - `<map>`: untuk `multimap`
        
    - `<iterator>`: untuk `iterator` eksplisit
        
    - `<iostream>`: I/O
        

---

```cpp
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
```

- Optimasi `cin`/`cout`
    

---

```cpp
    multimap<string, int> mulmap;
    int n, x;
    string s;
    cin >> n;
```

- `mulmap`: kontainer data
    
- `n`: jumlah entry
    
- `s`, `x`: untuk input nama dan nilai
    

---

```cpp
    while(n--) {
        cin >> s >> x;
        mulmap.insert({s, x});
    }
```

- Menyimpan seluruh entry ke dalam `multimap`
    

---

```cpp
    int t;
    cin >> t;
```

- `t`: ambang nilai. Semua entry dengan nilai `< t` akan dihapus
    

---

```cpp
    multimap<string, int>::iterator iter;
    for(iter = mulmap.begin(); iter != mulmap.end(); ) {
        if(iter->second < t) {
            iter = mulmap.erase(iter);
        } else {
            iter++;
        }
    }
```

- Iterasi manual dengan `iterator` untuk **menghapus saat iterasi**
    
- Jika nilai kurang dari ambang batas, hapus dan lanjutkan ke iterator berikutnya
    
- `erase()` mengembalikan iterator baru → tidak perlu `++iter` dalam kasus ini
    

---

```cpp
    if(!mulmap.empty()) {
        for(const auto& [key, val] : mulmap) {
            cout << key << " " << val << "\n";
        }
    } else {
        cout << "Semua data terhapus\n";
    }
```

- Jika masih ada data, tampilkan semuanya
    
- Jika kosong, tampilkan pesan sesuai spesifikasi soal
    

---

### Catatan Tambahan

- Aman digunakan karena `erase()` saat iterasi hanya menghapus elemen saat itu dan langsung pindah ke elemen berikutnya
    
- Urutan key dijaga secara otomatis oleh `multimap`
    

---

### Penutup

🎉 **Kamu sudah menyelesaikan 10 soal dasar `multimap`!**

- Mulai dari insert, find, count, erase, hingga penggunaan lanjutan seperti `merge`, `equal_range`, dan pengurutan berdasarkan isi
    
- Kamu juga sudah latihan:
    
    - Filter nilai
        
    - Menyimpan nilai terstruktur (`map<string, vector<int>>`)
        
    - Penghapusan kondisional
        

Kalau kamu mau lanjut ke **latihan lanjutan multimap**, atau pindah ke topik berikutnya (misalnya `priority_queue`, `unordered_multimap`, atau struktur data lanjutan lainnya), tinggal bilang aja!