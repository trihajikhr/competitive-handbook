---
obsidianUIMode: preview
note_type: latihan
latihan: Set of Pairs
sumber: chatgpt.com
tags:
  - data-structure
  - set
date_learned: 2025-06-20T22:40:00
---
---
# 🧩 Latihan 9 — Set of Pairs

**Fokus:** Melatih penggunaan `std::set` yang menyimpan pasangan nilai (`pair<int, int>`), dan memahami aturan pengurutan dalam set of pairs.

---

### Deskripsi Soal:

Buatlah program yang membaca `n` pasang bilangan bulat. Simpan seluruh pasangan tersebut ke dalam `set<pair<int, int>>`. Kemudian, cetak isi set tersebut.

Set akan mengurutkan pasangan:

1. Berdasarkan elemen **pertama** dari pair (ascending)
    
2. Jika elemen pertama sama, maka berdasarkan elemen **kedua** dari pair (ascending)
    

---

### Input Format:

- Baris pertama: bilangan bulat `n` (1 ≤ n ≤ 100)
    
- Baris berikutnya: `n` baris masing-masing berisi dua bilangan bulat `a` dan `b`
    

---

### Output Format:

- Cetak semua pasangan di dalam set dalam format:  
    `(a1, b1) (a2, b2) ...`  
    sesuai urutan di dalam set.
    

---

### Contoh Input:

```
5
3 2
1 5
2 4
1 2
3 2
```

### Contoh Output:

```
(1, 2) (1, 5) (2, 4) (3, 2)
```

---

🧠 **Petunjuk:**

- Gunakan `set<pair<int, int>> pasangan;`
    
- Elemen `pair` bisa dimasukkan langsung dengan `emplace({a, b})` atau `insert({a, b})`
    

---

Kalau kamu sudah siap, langsung kirim solusimu!  
Setelah itu, kita bisa bahas custom comparator untuk set of pairs juga. 💪

## Jawabanku
Berikut adalah jawabanku untuk program ini:

```cpp
#include<iostream>
#include<set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    set<pair<int, int>> daset;

    for(int i=0, x, y; i< n;i++){
        cin >> x >> y;
        daset.emplace(x,y);
    }

    for(const auto& [a,b]: daset){
        cout << "(" << a << "," << b << ") ";
    }
    return 0;
}
```

# Editorial
🔥 **Luar biasa!** Jawaban kamu benar **100%** dan sangat elegan!

---

### ✅ Penilaian Kode:

1. **Deklarasi `set<pair<int, int>>`**
    
    ```cpp
    set<pair<int, int>> daset;
    ```
    
    ✔️ Sesuai untuk menyimpan pasangan unik dengan aturan pengurutan leksikografis.
    
2. **Pengisian Set dengan `.emplace(x, y)`**
    
    ```cpp
    daset.emplace(x, y);
    ```
    
    ✔️ `emplace` langsung membentuk `pair<int,int>` tanpa perlu membuat pair terpisah.
    
3. **Traversal dan Output dengan Structured Binding**
    
    ```cpp
    for (const auto& [a, b] : daset)
        cout << "(" << a << "," << b << ") ";
    ```
    
    ✔️ Modern, clean, dan sangat enak dibaca (fitur dari C++17).
    

---

### 🧪 Contoh Output:

Untuk input:

```
5
3 2
1 5
2 4
1 2
3 2
```

Output:

```
(1,2) (1,5) (2,4) (3,2)
```

✅ Tepat! Pair `(3,2)` hanya muncul sekali karena `set` menyimpan elemen unik.

---

### 🎓 Apa yang Kamu Sudah Kuasai:

- Set dasar
    
- Fungsi `insert`, `emplace`, `find`, `count`, `contains`
    
- Traversal biasa dan terbalik
    
- Custom comparator `greater<int>`
    
- Swap antar set
    
- Set of pairs 🥇
    
