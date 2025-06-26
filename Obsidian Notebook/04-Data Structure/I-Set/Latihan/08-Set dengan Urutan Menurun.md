---
obsidianUIMode: preview
note_type: latihan
latihan: Set dengan Urutan Menurun
sumber: chatgpt.com
tags:
  - data-structure
  - set
date_learned: 2025-06-20T22:11:00
---
---
# 🧩 Latihan 8 — Set dengan Urutan Menurun

**Fokus:** Membuat `std::set` dengan **urutan menurun (descending)** menggunakan **custom comparator**.

---

### Deskripsi Soal:

Buatlah program yang menyimpan `n` bilangan bulat ke dalam sebuah `set`, tapi kali ini **set harus mengurutkan elemen secara menurun** (dari besar ke kecil). Cetak seluruh elemen dari set tersebut.

---

### Input Format:

- Baris pertama: bilangan bulat `n` (1 ≤ n ≤ 100)
    
- Baris kedua: `n` bilangan bulat, bisa mengandung duplikat
    

---

### Output Format:

- Cetak semua elemen unik dari set dalam **urutan menurun**, dipisahkan dengan spasi.
    

---

### Contoh Input:

```
6
30 10 20 10 40 20
```

### Contoh Output:

```
40 30 20 10
```

---

### 🧠 Petunjuk:

Gunakan syntax berikut saat deklarasi set:

```cpp
set<int, greater<int>> s;
```

atau buat comparator sendiri jika ingin eksplorasi lebih dalam.

---

Kalau kamu sudah selesai, kirimkan kodenya seperti biasa!  
Kalau mau tantangan lebih (misalnya comparator kustom dengan `struct`), tinggal bilang aja! 💪

## Jawabanku
Berikut adalah jawabanku untuk permasalahan ini:

```cpp
#include<iostream>
#include<set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    set<int, greater<int>> daset;
    for(int i=0, x; i<n; i++){
        cin >> x;
        daset.emplace(x);
    }

    for(const auto & x: daset){
        cout << x << " ";
    }

    return 0;
}
```

# Editorial
🔥 **Perfect!** Kamu benar-benar sudah menguasai `std::set` — sekarang bahkan sudah berhasil mengubah **urutan sorting** jadi menurun!

---

### ✅ Pemeriksaan Kode:

1. **Deklarasi Set dengan Comparator `greater<int>`**:
    
    ```cpp
    set<int, greater<int>> daset;
    ```
    
    ✔️ Ini artinya elemen akan diurutkan **dari besar ke kecil** secara otomatis. Mantap!
    
2. **Masukkan elemen dengan `emplace()`**:
    
    ```cpp
    daset.emplace(x);
    ```
    
    ✔️ Rapi dan efisien.
    
3. **Cetak elemen** dalam urutan menurun:
    
    ```cpp
    for (const auto &x : daset) cout << x << " ";
    ```
    
    ✔️ Karena `set` sudah descending, kamu tidak perlu reverse traversal. Simpel dan elegan!
    

---

### 🧪 Uji:

**Input:**

```
6
30 10 20 10 40 20
```

**Output:**

```
40 30 20 10
```

✅ **Sesuai ekspektasi!**

---

### 📘 Catatan Ekstra:

Kalau kamu tertarik untuk eksplorasi lebih jauh, kamu bisa juga coba buat comparator dengan `struct`:

```cpp
struct Desc {
    bool operator()(int a, int b) const {
        return a > b;
    }
};
set<int, Desc> s;
```

Tapi untuk latihan ini, `greater<int>` sudah sangat tepat.
