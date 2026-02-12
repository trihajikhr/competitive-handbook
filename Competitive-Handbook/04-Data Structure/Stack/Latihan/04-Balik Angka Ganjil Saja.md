---
obsidianUIMode: preview
note_type: latihan
latihan: Balik Angka Ganjil Saja
sumber: Google.com, AI
tags:
  - stack
  - data-structure
date_learned: 2025-06-15T21:47:00
---
---
# Balik Angka Ganjil Saja

Berikutnya kita lanjut ke **Soal Stack 4**, dan aku pilihkan versi yang masih natural buat melatih penggunaan fungsi `top()`, `push()`, dan logika stack:

---

## 🧠 Soal Stack 4 – Balik Angka Ganjil Saja

**Deskripsi:**

Diberikan `n` bilangan bulat. Masukkan semua angka tersebut ke dalam stack. Kemudian, cetak hanya angka **ganjil**, dari atas ke bawah.

**Format Input:**

- Baris pertama: bilangan bulat `n` (1 ≤ n ≤ 100)
    
- Baris kedua: `n` bilangan bulat, dipisahkan spasi
    

**Format Output:**

- Cetak satu per baris semua angka ganjil dari atas ke bawah (yang masuk stack paling akhir keluar lebih dulu).
    
- Jika tidak ada angka ganjil, cetak `TIDAK ADA`.
    

**Contoh Input:**

```
6
8 3 6 7 4 1
```

**Contoh Output:**

```
1
7
3
```

**Contoh Input:**

```
4
2 4 6 8
```

**Contoh Output:**

```
TIDAK ADA
```

**Petunjuk:**

- Setelah semua angka dimasukkan ke stack, lakukan proses `top()` dan `pop()`.
    
- Gunakan stack seperti biasa untuk mencetak secara terbalik.
    
- Jangan lupa cek ganjil dengan `x % 2 == 1`.
    

---

Kalau sudah selesai, nanti kita bisa lanjut ke Soal Stack #6 dengan tema ekspresi matematika atau undo-redo. Tinggal bilang aja!

## Jawabanku
Berikut adalah jawabanku untuk soal ini:

```cpp
#include<iostream>
#include<stack>
using namespace std;

int main() {
    int n; cin >> n;
    stack<int> num;
    while(n--){
        int x; cin >> x;

        if(x%2==1) num.push(x);
    }

    if(num.empty()) cout << "TIDAK ADA";
    else {
        while(!num.empty()){
            cout << num.top() << "\n";
            num.pop();
        }
    }
    return 0;
}
```

# Editorial
💯 Mantap! Kode kamu sudah:

- ✅ Menggunakan `stack<int>` dengan benar
    
- ✅ Menyaring angka ganjil saat `push`
    
- ✅ Mengecek kondisi kosong dengan `empty()`
    
- ✅ Mencetak angka dari atas ke bawah menggunakan `top()` dan `pop()`
    

### ✔️ Output dan logika juga sudah sesuai:

- Jika tidak ada angka ganjil → cetak `TIDAK ADA`
    
- Jika ada → cetak dalam urutan **terbalik** sesuai prinsip LIFO (Last In First Out)
    

---

### 🔧 Sedikit saran (optional, untuk pembiasaan good style):

Untuk output `TIDAK ADA`, tambahkan newline (`\n`) di akhir agar lebih bersih saat dijalankan otomatis:

```cpp
if(num.empty()) cout << "TIDAK ADA\n";
```
