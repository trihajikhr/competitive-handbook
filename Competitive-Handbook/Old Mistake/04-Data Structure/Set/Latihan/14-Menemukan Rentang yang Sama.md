---
obsidianUIMode: preview
note_type: latihan
latihan: Menemukan Rentang yang Sama
sumber: chatgpt.com
tags:
  - data-structure
  - set
date_learned: 2025-06-20T23:53:00
---
---
🔥 Siap! Kita masuk ke **Tantangan 14** — kali ini fokus pada **`equal_range()`**, yaitu fitur dari `std::set` yang jarang digunakan tapi sangat powerful.

---

# 🧩 Tantangan 14 — Menemukan Rentang yang Sama (`equal_range`)

**Fokus:** Memahami bagaimana `equal_range(x)` bekerja dalam konteks `std::set`.

---

### Deskripsi Soal:

Buat program yang:

1. Membaca `n` bilangan bulat dan menyimpannya ke dalam `set`
    
2. Membaca sebuah bilangan `x`
    
3. Cetak:
    
    - Elemen pertama **≥ x** (`lower_bound`)
        
    - Elemen pertama **> x** (`upper_bound`)
        
    - Semua elemen dalam `equal_range(x)` yaitu `[lower_bound(x), upper_bound(x))`
        

Jika hasilnya kosong, cetak `"Kosong"`

---

### Input Format:

- Baris pertama: bilangan bulat `n`
    
- Baris kedua: `n` bilangan bulat
    
- Baris ketiga: sebuah bilangan `x`
    

---

### Output Format:

- Baris pertama: `lower_bound(x)` atau `"Kosong"`
    
- Baris kedua: `upper_bound(x)` atau `"Kosong"`
    
- Baris ketiga: Semua elemen antara `lower_bound(x)` dan `upper_bound(x)` atau `"Kosong"`
    

---

### Contoh Input:

```
6
10 20 30 30 30 40
30
```

### Contoh Output:

```
30
40
30
```

### Contoh Input 2:

```
4
5 10 15 20
17
```

### Output 2:

```
20
20
```

---

### 🧠 Petunjuk:

- Gunakan:
    
    ```cpp
    auto [lo, up] = daset.equal_range(x);
    ```
    
    atau:
    
    ```cpp
    pair<iterator, iterator> pr = daset.equal_range(x);
    ```
    
- Ingat: `equal_range()` **selalu** mengembalikan `pair<iterator, iterator>` dengan:
    
    - `first`: sama dengan `lower_bound(x)`
        
    - `second`: sama dengan `upper_bound(x)`
        

---

Kalau kamu siap, langsung kirim kodenya dan kita lanjut ke **Tantangan Terakhir (15)** setelah itu! 💪

## Jawabanku
#### Jawaban yang masih ada sedikit kekeliruan
Berikut ini adalah jawaban yang masih bisa ditingkatkan lagi:

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

    int x; cin >> x;

    auto l = daset.lower_bound(x);
    auto r = daset.upper_bound(x);
    auto [le, ri] = daset.equal_range(x);

    cout << *le << "\n" << *ri << "\n";
    return 0;
}
```

#### Jawaban yang sesuai seperti editorial
Berikut adalah jawaban yang sesuai dengan ketentuan dan saran dari editorial:

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

    int x; cin >> x;
    auto [le, ri] = daset.equal_range(x);

    // Output lower_bound
    if (le != daset.end()) cout << *le << "\n";
    else cout << "Kosong\n";

    // Output upper_bound
    if (ri != daset.end()) cout << *ri << "\n";
    else cout << "Kosong\n";

    // Output isi equal_range
    if (le == ri) cout << "Kosong\n";
    else {
        for (auto it = le; it != ri; ++it)
            cout << *it << " ";
        cout << "\n";
    }

    return 0;
}
```

# Editorial
🔥 Kamu sudah sangat dekat! Tapi hati-hati — ada potensi error saat `lower_bound()` atau `upper_bound()` menghasilkan `end()`, yang tidak bisa didereferensikan (`*end()` = UB/undefined behavior).

---

### ⚠️ Masalah:

Jika `x` lebih besar dari semua elemen, maka:

```cpp
auto le = daset.lower_bound(x); // bisa jadi == daset.end()
```

Sehingga:

```cpp
cout << *le; // ❌ UB jika le == end()
```

---

### ✅ Solusi:

Cek dulu sebelum mencetak:

```cpp
if (le != daset.end()) cout << *le << "\n";
else cout << "Kosong\n";

if (ri != daset.end()) cout << *ri << "\n";
else cout << "Kosong\n";
```

Untuk baris ketiga — **menampilkan semua elemen dari `le` sampai `ri` (range `equal_range`)**:

```cpp
if (le == ri)
    cout << "Kosong\n";
else {
    for (auto it = le; it != ri; ++it)
        cout << *it << " ";
    cout << "\n";
}
```

---

### 💡 Versi Lengkap (Revisi):

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

    int x; cin >> x;
    auto [le, ri] = daset.equal_range(x);

    // Output lower_bound
    if (le != daset.end()) cout << *le << "\n";
    else cout << "Kosong\n";

    // Output upper_bound
    if (ri != daset.end()) cout << *ri << "\n";
    else cout << "Kosong\n";

    // Output isi equal_range
    if (le == ri) cout << "Kosong\n";
    else {
        for (auto it = le; it != ri; ++it)
            cout << *it << " ";
        cout << "\n";
    }

    return 0;
}
```

---

### ✅ Contoh Uji:

#### Input:

```
6
10 20 30 30 30 40
30
```

#### Output:

```
30
40
30
```

🟢 **Sesuai!**

---

Kalau sudah fix dan kamu puas, kita langsung ke **Tantangan Terakhir: Set of Sets** — paling sulit dari semuanya! Siap? 😎