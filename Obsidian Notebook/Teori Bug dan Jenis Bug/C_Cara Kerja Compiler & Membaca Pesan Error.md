---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: memahami cara kerja compiler & membaca pesan error
sumber: Google.com, AI
date_learned: 2025-05-16T13:37:00
tags:
  - bug
  - compiler
---
#bug #compiler 

---
# Memahami Cara Kerja Compiler & Membaca Pesan Error

## 1. Apa Itu Compiler?

- Compiler adalah program yang mengubah kode sumber (source code) menjadi kode mesin yang dapat dijalankan oleh komputer.
    
- Proses kompilasi biasanya melibatkan beberapa tahap:
    
    - **Lexical analysis**: Memecah kode jadi token-token.
        
    - **Syntax analysis**: Memeriksa struktur kode sesuai aturan bahasa.
        
    - **Semantic analysis**: Memastikan makna kode sesuai konteks.
        
    - **Optimization**: Meningkatkan performa kode.
        
    - **Code generation**: Menghasilkan kode mesin.
        
- Jika terjadi kesalahan selama proses ini, compiler akan memberi **pesan error** atau **warning**.
    

---

## 2. Jenis Pesan Error dan Warning yang Sering Muncul

|Jenis Error|Penjelasan|Contoh Pesan|
|---|---|---|
|**Syntax Error**|Kesalahan aturan penulisan bahasa pemrograman.|`error: expected ';' before 'return'`|
|**Type Error**|Kesalahan penggunaan tipe data.|`cannot convert ‘const char*’ to ‘int’`|
|**Undefined Reference**|Fungsi atau variabel tidak ditemukan saat linking.|`undefined reference to ‘myFunction()’`|
|**Warning**|Peringatan potensi masalah, tapi tidak menghentikan kompilasi.|`warning: unused variable ‘x’`|

---

## 3. Struktur Pesan Error Compiler

Pesan error biasanya terdiri dari beberapa bagian:

```
nama_file:baris:kolom: tipe_error: deskripsi_error
```

Contoh:

```
main.cpp:10:5: error: expected ';' before 'return'
```

Penjelasan:

- `main.cpp` = nama file yang error
    
- `10` = nomor baris
    
- `5` = posisi kolom karakter
    
- `error` = tipe masalah (error atau warning)
    
- `expected ';' before 'return'` = deskripsi kesalahan
    

---

## 4. Cara Membaca dan Menangani Pesan Error

1. **Perhatikan baris dan kolom kode** yang disebut dalam pesan error.
<br/>
2. **Baca deskripsi error dengan seksama** untuk mengerti jenis masalahnya.
<br/>
3. **Periksa kode di baris tersebut dan sekitarnya**, kadang kesalahan muncul sebelum baris yang disebut.
<br/>
4. **Cari tanda baca yang hilang** seperti titik koma, kurung buka/tutup, atau tanda kutip.
<br/>
5. **Periksa tipe data dan deklarasi variabel** jika ada error tipe.
<br/>
6. **Jika error terkait fungsi, pastikan fungsi sudah didefinisikan dan dipanggil dengan benar.**
<br/>
7. **Gunakan mesin pencari (Google) untuk pesan error yang tidak familiar.**
<br/>
---

## 5. Contoh Kasus dan Penjelasan Pesan Error

### Contoh 1: Lupa titik koma

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, world!" << std::endl
    return 0;
}
```

Pesan error:

```
main.cpp:5:5: error: expected ';' before 'return'
```

**Analisis:**  
Compiler mengharapkan titik koma (`;`) setelah `std::endl`. Perbaiki dengan menambahkan titik koma di akhir baris tersebut.

---

### Contoh 2: Variabel tidak dideklarasi

```cpp
#include <iostream>

int main() {
    std::cout << x << std::endl;
    return 0;
}
```

Pesan error:

```
main.cpp:4:18: error: 'x' was not declared in this scope
```

**Analisis:**  
Variabel `x` belum dideklarasikan sebelum dipakai. Deklarasikan terlebih dahulu atau gunakan variabel yang ada.

---

### Contoh 3: Kesalahan tipe data

```cpp
int number = "10";
```

Pesan error:

```
error: cannot convert ‘const char [3]’ to ‘int’ in initialization
```

**Analisis:**  
Tidak boleh mengisi variabel bertipe `int` dengan string `"10"`. Gunakan angka tanpa tanda kutip.

---

## 6. Tips Praktis

- Jangan panik saat mendapat error, baca pesan error dengan teliti.
    
- Mulai perbaikan dari error pertama yang muncul, karena error berikutnya mungkin akibat yang pertama.
    
- Gunakan **print debugging** untuk memahami alur program saat program sudah bisa dikompilasi tapi hasilnya salah.
    
- Jika perlu, gunakan debugger seperti `gdb` untuk melacak nilai variabel dan jalannya program.
    
