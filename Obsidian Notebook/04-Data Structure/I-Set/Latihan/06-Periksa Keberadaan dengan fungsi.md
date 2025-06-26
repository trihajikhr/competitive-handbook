---
obsidianUIMode: preview
note_type: latihan
latihan: Periksa Keberadaan dengan fungsi
sumber: chatgpt.com
tags:
  - data-structure
  - set
date_learned: 2025-06-20T21:32:00
---
---
# 🧩 Latihan 6 — Periksa Keberadaan dengan `count()` dan `contains()`

**Fokus:** Melatih penggunaan fungsi `count()` dan `contains()` untuk mengecek apakah sebuah elemen ada dalam `std::set`.

---

### Deskripsi Soal:

Buatlah program yang:

1. Membaca `n` bilangan bulat.
    
2. Menyimpan semua bilangan itu dalam `set`.
    
3. Membaca bilangan `x`, lalu:
    
    - Jika `x` ada dalam `set`, cetak `Ada`
        
    - Jika tidak ada, cetak `Tidak ada`
        

**Gunakan `count()` atau `contains()` untuk mengeceknya.**

---

### Input Format:

- Baris pertama: bilangan bulat `n` (1 ≤ n ≤ 100)
    
- Baris kedua: `n` bilangan bulat (bisa duplikat)
    
- Baris ketiga: bilangan bulat `x` yang ingin dicek keberadaannya
    

---

### Output Format:

- `Ada` jika elemen `x` ditemukan dalam set
    
- `Tidak ada` jika tidak ditemukan
    

---

### Contoh Input 1:

```
5
2 4 6 8 10
6
```

### Contoh Output 1:

```
Ada
```

---

### Contoh Input 2:

```
4
1 3 5 7
2
```

### Contoh Output 2:

```
Tidak ada
```

---

🧠 **Petunjuk:**

- `count(x)` akan mengembalikan 0 jika tidak ada, dan 1 jika ada (karena `set` tidak menyimpan duplikat).
    
- Jika kamu pakai C++20, kamu juga bisa pakai `contains(x)` langsung (lebih ekspresif).
    

---

Kamu bebas pilih `count()` atau `contains()` (jika kompiler kamu mendukung C++20). Kirimkan jawabanmu seperti biasa, ya! 🚀

## Jawabanku
Berikut adalah kode jawabanku:

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

    // menggunakan fungsi count()
    if(daset.count(x)) cout << "Ada\n";
    else cout << "Tidak ada\n";

    // menggunakan fungsi contains();
    if(daset.contains(x)) cout << "Ada\n";
    else cout << "TIdak ada\n";
    
    return 0;
}
```

# Editorial
⚡ Kode kamu **sangat bagus**! Tapi ada satu hal kecil yang perlu diperhatikan agar lebih **aman secara kompatibilitas C++**.

---

### ✅ Hal-Hal yang Sudah Tepat:

1. **Penggunaan `count()`**
    
    ```cpp
    if(daset.count(x)) cout << "Ada\n";
    else cout << "Tidak ada\n";
    ```
    
    ✔️ Ini **pasti aman** digunakan di semua versi C++ (termasuk C++11 hingga C++17).
    
2. **Penggunaan `contains()`**
    
    ```cpp
    if(daset.contains(x)) cout << "Ada\n";
    else cout << "TIdak ada\n";
    ```
    
    ⚠️ Ini hanya tersedia di **C++20 ke atas**. Kalau kamu pakai **kompiler lama** atau tidak mengaktifkan `-std=c++20`, maka ini akan menghasilkan **error** saat kompilasi.
    

---

### 🧠 Solusi:

Untuk menghindari error di sistem yang belum mendukung C++20, kamu bisa:

#### 💡 Solusi 1: Komentar dulu bagian `contains()` (jika hanya ingin uji dengan `count()`):

```cpp
// if (daset.contains(x)) cout << "Ada\n";
// else cout << "Tidak ada\n";
```

#### 💡 Solusi 2: Tambahkan pengecekan versi C++:

```cpp
#if __cplusplus >= 202002L
    if (daset.contains(x)) cout << "Ada\n";
    else cout << "Tidak ada\n";
#endif
```

---

### 🧪 Contoh Output (misal `x = 6`):

```
Ada
Ada
```

✅ Artinya keduanya berfungsi jika kompiler kamu mendukungnya.

---

### 💡 Catatan Ekstra:

- `count(x)` di `std::set` hanya mungkin mengembalikan `0` atau `1`, jadi sangat ringan.
    
- `contains(x)` hanya lebih **ekspresif dan bersih**, tapi tidak memberikan kelebihan performa.
    
