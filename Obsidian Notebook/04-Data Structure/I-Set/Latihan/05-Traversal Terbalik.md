---
obsidianUIMode: preview
note_type: latihan
latihan: Traversal Terbalik
sumber: chatgpt.com
tags:
  - data-structure
  - set
date_learned: 2025-06-20T21:19:00
---
---
# 🧩 Latihan 5 — Traversal Terbalik

**Fokus:** Menggunakan `rbegin()` dan `rend()` untuk menelusuri `std::set` dari belakang (dari elemen terbesar ke terkecil).

---

### Deskripsi Soal:

Diberikan `n` bilangan bulat, cetak elemen-elemennya dalam urutan **menurun** menggunakan traversal terbalik dari `set`.

---

### Input Format:

- Baris pertama: bilangan bulat `n` (1 ≤ n ≤ 100)
    
- Baris kedua: `n` bilangan bulat yang mungkin mengandung duplikat
    

---

### Output Format:

- Cetak elemen-elemen unik dari set, **dari yang terbesar ke terkecil**, dipisahkan dengan spasi.
    

---

### Contoh Input 1:

```
6
10 20 20 30 40 10
```

### Contoh Output 1:

```
40 30 20 10
```

---

🧠 **Petunjuk:**

- Gunakan `set.rbegin()` sebagai iterator ke elemen terbesar.
    
- Iterasi mundur sampai `set.rend()`.
    
- `std::set` secara default diurutkan naik, jadi kita butuh `reverse_iterator`.
    

---

Kalau kamu sudah siap, langsung kirim kode solusinya dan kita lanjutkan ke latihan selanjutnya! 💪

## Jawaban
Berikut adalah jawaban yang sudah benar:

```cpp
#include<iostream>
#include<set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    set<int> daset;

    for(int i=0, x; i<n; i++){
        cin >> x;
        daset.emplace(x);
    }

    for(auto it = daset.rbegin(); it != daset.rend(); it++){
        cout << *it << " ";
    }
    return 0;
}
```

# Editorial
🔥 Hebat! Jawaban kamu benar dan clean banget!

---

### ✅ Yang Sudah Tepat:

1. **Menyimpan elemen dalam `set`**:
    
    ```cpp
    daset.emplace(x);
    ```
    
    - Menghindari duplikat ✅
        
    - Otomatis terurut naik ✅
        
2. **Traversal mundur (descending)** dengan:
    
    ```cpp
    for (auto it = daset.rbegin(); it != daset.rend(); it++)
    ```
    
    - Pakai reverse iterator (`rbegin()` ke `rend()`) ✅
        
    - Cetak dari terbesar ke terkecil ✅
        
3. **Output sesuai ekspektasi**:
    
    Contoh:
    
    ```
    Input:
    6
    10 20 20 30 40 10
    
    Output:
    40 30 20 10
    ```
    
    ✅ **Sesuai!**
    

---

### ⚙️ Catatan Ekstra:

Kamu sudah membuktikan pemahaman tentang:

- Struktur data `set`
    
- Reverse traversal menggunakan `rbegin()` / `rend()`
    
- Efisiensi (karena traversal `O(n)` pada struktur yang terurut)
    
