---
obsidianUIMode:
note_type: Dokumentasi
judul_dokumentasi: Compile files without build
date_add: 2025-10-02T14:21:00
status_dokumentasi: ✅Finish ❌Not-Finish
tags:
  - debugger
---
---
# Compile files without build
Kali aku akan membuat dokumentasi untuk bagaimana caranya Build, Run, & Debug dengan menggunakan Clion. Penjelasan ini akan sangat panjang, namun sangat penting untuk kemudahahan penggunaan selanjutnya.

Jadi, yahh, ikuti dokumentasi panjang ini secara perlahan, karena panduan ini diambil dari dokumentasi resminya.

![[01-Compile files without build-1.png]]


<br/>

---
# 1 | Compile files without build

Sumber: [Compile files without build \| CLion Documentation](https://www.jetbrains.com/help/clion/compiling-single-file.html)

Untuk mempercepat proses development, Anda mungkin sesekali memilih untuk melakukan compile satu file tanpa harus melakukan building seluruh project. Untuk tujuan ini, CLion menyediakan aksi Recompile.

![[01-Compile files without build-1.png]]

Recompile tersedia untuk source files dan header files individual, dan juga untuk grup files yang dipilih di project tree. Untuk headers, CLion menggunakan resolve context untuk melakukan compile salah satu source files yang include _header_ yang ditentukan. Perlu diperhatikan bahwa Recompile di-_disable_ untuk directories dan files non-C/C++.

> Anda dapat menggunakan **Recompile** untuk project [CMake](https://www.jetbrains.com/help/clion/quick-cmake-tutorial.html), [Makefile](https://www.jetbrains.com/help/clion/makefiles-support.html), [Meson](https://www.jetbrains.com/help/clion/meson.html), dan [compilation database](https://www.jetbrains.com/help/clion/compilation-database.html).

Cara melakukan Recompile:
1. Untuk _file_ yang sedang terbuka, pilih **Build | Recompile** dari _main menu_ atau tekan **Ctrl+Shift+F9**.
   
   ![[01-Compile files without build-2.png]]
2. Untuk _file_ di **project tree**, pilih **Recompile** dari **context menu** atau gunakan _shortcut_ yang sama **Ctrl+Shift+F9**.
   
   ![[01-Compile files without build-3.png]]
3. Untuk beberapa **files**, pilih **files** tersebut di **project tree**, dan gunakan opsi **Recompile Selected Files** dari **context menu** **Ctrl+Shift+F9**.
   
   ![[01-Compile files without build-4.png]]

> Saat digunakan untuk banyak **files**, proses **recompilation** akan berhenti setelah kegagalan **compilation** yang pertama.




## Makefile / Compilation database

Saat dipanggil dari Makefile atau compilation database project, **Recompile** mengambil compilation command yang ditemukan selama analisis project, memodifikasinya menghilangkan _output_ dan menambahkan _flag_ `--syntax-only`, dan menggunakannya untuk melakukan compile _file_ yang dipilih.
### Examining the results

Sama seperti **build** biasa, Anda dapat memeriksa hasil **compilation** _single file_ di **Message Tool Window**:

![[01-Compile files without build-5.png]]

Jika **compilation** gagal, Anda akan mendapatkan pesan _popup_ pemberi sinyal:

![[01-Compile files without build-6.png]]

