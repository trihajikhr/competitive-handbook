---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Apa Itu Iterator di STL?
sumber: chatgpt.com
date_learned: 2025-06-21T00:01:00
tags:
  - iterator
---
Link Sumber: 

---
Pertanyaan ini menyentuh **inti dari bagaimana iterator bekerja di STL (Standard Template Library)** — dan kamu sedang masuk ke pemahaman tingkat intermediate–lanjutan. Mari kita kupas dengan simpel tapi mendalam:

---

# 🔁 Apa Itu Iterator di STL?

Iterator di C++ STL adalah **abstraksi seperti pointer** yang digunakan untuk **menjelajahi elemen dalam container** (`set`, `vector`, `map`, dll.).

> ➤ **Mirip pointer**, tapi bukan pointer — dia adalah **objek** yang bisa:

- Di-_dereference_ (`*it`)
    
- Di-_increment_ (`++it`)
    
- Di-_compare_ (`it != end()`)
    

---

## ❓ Kenapa Harus Di-_dereference_ (`*it`)?

Karena **iterator tidak menyimpan nilai secara langsung**, tapi hanya menunjuk ke suatu **elemen di dalam container**.

Misal:

```cpp
set<int> s = {10, 20, 30};
auto it = s.begin();   // it menunjuk ke elemen pertama

cout << *it;           // kita ambil NILAI yang ditunjuk (yaitu 10)
```

Kalau kamu hanya pakai `it` saja, itu adalah **iterator-nya**, bukan nilainya.

---

## 🔬 Analogi Pointer:

|Pointer|Iterator|
|---|---|
|`int* ptr = &x;`|`set<int>::iterator it = s.begin();`|
|`*ptr` = akses nilai x|`*it` = akses nilai elemen set|
|`++ptr` = geser ke alamat selanjutnya|`++it` = geser ke elemen berikutnya|

---

## 🧠 Contoh:

```cpp
set<string> nama = {"Andi", "Budi", "Citra"};
auto it = nama.begin();   // iterator menunjuk ke "Andi"

cout << *it;              // akses string "Andi"
```

Kalau kamu menulis `cout << it;`, itu akan error atau menampilkan tipe aneh (karena `it` adalah objek iterator, bukan nilai string-nya).

---

## 📎 Kesimpulan:

✅ Kita perlu mengakses iterator sebagai pointer dengan `*it` karena:

1. Iterator hanyalah penunjuk ke elemen dalam container
    
2. Untuk mengambil nilainya, kita harus dereference (`*it`)
    
3. Ini adalah konsep utama dalam desain STL agar efisien dan fleksibel
    
