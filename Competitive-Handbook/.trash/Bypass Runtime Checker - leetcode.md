---
obsidianUIMode: preview
note_type: tips trick
tips_trick: bypass runtime checker
sumber: leetcode.com & chatgpt.com
tags:
  - fast-running
  - syntax
  - hack
  - not-recommended
---
#hack #not-recommended #syntax #fast-running 

---
# Bypass Runtime Checker
Pernah main leetcode, dan menemukan solusi dari orang lain yang berjalan dengan running time super cepat? Lalu ketika dilihat kodenya, terdapat static constructor aneh seperti ini dibagian atas:

```cpp
const auto __ = []() {
    struct ___ { 
        static void _() { 
            std::ofstream("display_runtime.txt") << 0 << "\n"; 
        } 
    }; 
    std::atexit(&___::_); 
    return 0;
} ();
```

Yuk kita **kupas habis** baris ini:

---

## 🔍 Penjelasan Baris per Baris

### 1. `const auto __ = []() { ... }();`

- Ini adalah **lambda function** anonim (tanpa nama), yang langsung **dijalankan sekali** saat program mulai.
    
- Nilainya (hasil return `0`) disimpan ke variabel `__` (cuma nama random).
    
- Biasanya ini dipakai buat **menginisialisasi sesuatu sebelum eksekusi utama dimulai**, semacam constructor global.
    

---

### 2. Di dalam lambda-nya:

#### `struct ___ { static void _() { ... } };`

- Struct `___` punya method statis `_()`
    
- Isinya: tulis `0\n` ke file `display_runtime.txt`
    

#### `std::atexit(&___::_);`

- `std::atexit()` itu fungsi dari C++ standard library
    
- Memanggil fungsi `_()` **saat program selesai**, **sebelum keluar**
    
- Jadi dia menjadwalkan fungsi `_()` untuk dijalankan saat `return 0;` di `main()`
    

---

### ⚡ Apa Tujuannya?

Biasanya ini **tidak relevan dengan logika utama program**, tapi:

- Di LeetCode, kadang ada **runtime tracker** yang bisa dipaksa di-_trigger_ dengan cara seperti ini.
    
- Bisa juga digunakan untuk **"bypass" sistem output** tertentu, misalnya untuk keperluan debugging, tracking waktu, atau mengecoh runtime checker agar dianggap cepat.
    

---

## 🤓 Kesimpulan

|Bagian|Fungsi|
|---|---|
|`const auto __ = [](){...}();`|Menjalankan kode sekali sebelum `main()`|
|`std::atexit()`|Memanggil fungsi saat program berakhir|
|`std::ofstream(...)`|Tulis sesuatu ke file (mungkin untuk tracking waktu di sistem mereka)|

🧠 **Catatan**: Ini termasuk trik "hacky", dan **tidak diperlukan dalam solusi biasa** — tapi kadang muncul di solusi LeetCode dari user tertentu yang suka eksperimen atau optimasi timing.

Kalau kamu lihat ini di LeetCode, kamu **boleh abaikan** kalau tidak diminta khusus.

---

# Jadi, tidak bisa dipakai di kompetisi?
Yup, **benar banget!** 🎯

Kalau kamu ikut **lomba competitive programming** seperti:

- **ICPC**, **OSN**, **TOKI**, **KOMIFU**, **Codeforces**, **AtCoder**, **Kattis**, dll.
    

Maka:

### ❌ **Kode seperti ini tidak diperlukan dan tidak disarankan:**

```cpp
const auto __ = []() {
    struct ___ {
        static void _() {
            std::ofstream("display_runtime.txt") << 0 << "\n";
        }
    };
    std::atexit(&___::_);
    return 0;
} ();
```

---

## ✅ Kenapa Tidak Diperlukan?

1. **Tidak diminta di soal.**
    
2. File output seperti `display_runtime.txt` **tidak boleh dibuat sembarangan**.
    
3. Bisa dianggap **perilaku aneh** oleh sistem grading (bisa error atau WA).
    
4. Runtime tracker bukan tanggung jawab peserta lomba.
    

---

## 🧠 Kapan Digunakan?

Biasanya **di LeetCode** atau **platform dengan class-based submission**, orang kadang:

- Pake ini buat **bypass runtime check**
    
- Atau nge-_hack_ sistem agar runtime-nya lebih kecil (nggak selalu berhasil)
    

---

## 🚀 Di Kompetisi?

Yang kamu fokuskan cukup:

- Logika benar ✅
    
- Optimal ✅
    
- Input/output cepat (pakai `ios::sync_with_stdio(0); cin.tie(0);`) ✅
    

---

Kalau kamu lihat kode seperti itu di GitHub/LeetCode, kamu boleh anggap itu cuma "hobi" atau eksperimen seseorang 😄  
Untuk lomba, **cukup fokus ke logika dan efisiensi**.

