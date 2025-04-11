---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Static Constructor
sumber: chatgpt.com
tags:
  - efisien
  - syntax
  - fast-running
---
#efisien #syntax #fast-running

---
# 📘 Materi: Inisialisasi Awal dengan Static di C++ (Static Constructor & Static Lambda)


### 🧩 **Masalah Utama di Platform Seperti LeetCode**

- Kamu **tidak punya akses ke `main()`**.
    
- Tapi kamu ingin melakukan setup awal, seperti:
    
    - `ios::sync_with_stdio(false);`
        
    - `cin.tie(nullptr);`
        
    - Pengaturan log, output file, timer, dsb.
        

Jadi, kamu **perlu menjalankan kode satu kali di awal**, tanpa `main()`. Di sinilah **`static lambda` atau `static constructor` style** berperan.

---

## 🔹 1. Static Initialization dengan Lambda

### 📌 Contoh Umum:

```cpp
static const auto fast_io = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
```

### ✅ Apa yang terjadi di sini?

- `fast_io` adalah variabel `static` bertipe `const auto`.
    
- Nilainya diambil dari lambda `[]() { ... }();` yang langsung dieksekusi (perhatikan `()` di akhir).
    
- Karena variabel ini **`static`**, ia akan **dieksekusi satu kali** saat program dijalankan (tepat sebelum fungsi lainnya).
    

---

## 🔹 2. Static Initialization di Dalam Class

### 📌 Dalam Class seperti di LeetCode:

```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        static const auto fast_io = []() {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);
            return 0;
        }();

        // lanjutkan program
    }
};
```

✅ Lambda akan dijalankan **hanya sekali**, saat `sortArray` pertama kali dipanggil.

---

## 🔹 3. Static Member di Luar Class (Lebih Advanced)

```cpp
class Solution {
public:
    static const auto fast_io;
};

const auto Solution::fast_io = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
```

⚠ Ini digunakan **jika kamu ingin `fast_io` berlaku global untuk class** dan tidak memanggilnya berkali-kali dari setiap fungsi.

---

## 🤔 Kenapa Tidak Langsung Ditulis Seperti Biasa?

Karena:

- Kita **tidak punya `main()`** di LeetCode/Codeforces.
    
- Kita butuh jalankan sesuatu _sebelum logic utama_, maka kita "menitipkan" perintah ke dalam eksekusi `static`.
    

---

## 📚 Ringkasan

|Teknik|Contoh|Kapan Digunakan|
|---|---|---|
|`static lambda`|`static const auto _ = [](){ ... }();`|Untuk I/O cepat atau inisialisasi|
|`static member`|`static const auto x;` + `const auto Class::x = [](){...}();`|Jika kamu butuh reusable di banyak fungsi class|
|`static variable` dalam fungsi|`static bool once = setup();`|Untuk setup satu kali dalam fungsi tertentu|
