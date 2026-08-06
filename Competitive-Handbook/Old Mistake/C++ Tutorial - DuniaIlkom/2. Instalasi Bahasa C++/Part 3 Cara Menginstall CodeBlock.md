---
obsidianUIMode: preview
sumber: duniailkom
level: pemula
bahasa: C++
tanggal_study: 2024-10-01T20:14:00
total_study: 3
tags:
  - Cpp
id: DIB1
---
# Tutorial Belajar C++ Part 3: Cara Menginstall Code::Block

17 Oct 20 

Untuk bisa menjalankan kode program yang ditulis dalam bahasa C++, kita butuh **compiler** dan **IDE / teks editor**. Dalam tutorial ini akan dibahas cara menginstall aplikasi **IDE Code::Block** yang didalamnya juga terdapat **GNU GCC compiler**.

---

### Pengertian Compiler

**Compiler** adalah aplikasi yang berfungsi membaca dan menerjemahkan kode program komputer untuk menghasilkan sebuah aplikasi.

Seperti yang nantinya akan kita praktekkan, bahasa C++ berisi instruksi yang ditulis dalam kode khusus (dikenal dengan istilah _syntax_). Contoh kode tersebut adalah: **cout << "Hello World"**, atau **cin >> num**. Nantinya compiler akan membaca perintah ini dan menghasilkan sebuah aplikasi file .**exe** (untuk sistem operasi Windows).

Dengan kata lain, **Compiler Bahasa C++** adalah program yang dibutuhkan untuk memproses perintah yang ditulis dalam bahasa C untuk menjadi sebuah aplikasi jadi.

Terdapat cukup banyak compiler C++. Daftar lengkapnya bisa dilihat ke [List of compilers bahasa pemrograman C++](https://en.wikipedia.org/wiki/List_of_compilers#C++_compilers). Yang cukup terkenal di antaranya:

- GCC (g++) / GNU Project
- Borland Turbo C++
- Microsoft Visual C++
- Intel C++ Compiler

Dalam pemrosesan sebuah kode program, biasanya butuh lagi aplikasi lain yang disebut sebagai _linker_. **Linker** berfungsi untuk menggabungkan berbagai _library external_ yang dibutuhkan sebuah kode program. Umumnya compiler modern sudah langsung menyertakan linker ini.

---

### Pengertian IDE

**IDE** (singkatan dari **Integrated Development Environment**) adalah aplikasi yang menggabungkan **teks editor**, **compiler** dan **linker** dalam 1 aplikasi. Kadang ditambah juga dengan sebuah **debugger**, yakni fitur untuk menampilkan kesalahan dari kode program.

Beberapa IDE juga memiliki fitur tambahan seperti real-time debugging (memberitahu error sebelum kode program di compile), syntax highlighting (mewarnai beberapa kode agar mudah dibaca) dan code completion (memberikan saran penulisan kode program).

Sebuah IDE sangat memudahkan proses pembuatan program karena kita hanya perlu membuka 1 aplikasi saja.

Contoh dari IDE untuk bahasa C++ adalah **Turbo C++**, **Visual C++** dan **Code::Blocks**. Untuk tutorial belajar bahasa pemrograman C++ di Duniailkom ini, saya akan memakai Code::Blocks.

---

### Mendownload aplikasi IDE Code::Blocks

**Code::Blocks** atau **Code Blocks** adalah **IDE** (_Integrated Development Environment_) untuk bahasa pemrograman **C**, **C++** dan **Fortran**.

Dengan menggunakan Code::Blocks, kita sudah mendapati aplikasi **teks editor**, **compiler, linker** dan **debugger** untuk bahasa pemrograman C++ dalam sekali install.

**Code::Blocks** sendiri merupakan aplikasi Open Source yang bisa didapat dengan gratis. IDE ini juga tersedia untuk sistem operasi Linux, Mac, dan Windows. IDE **Code::Blocks** beralamat di [http://www.codeblocks.org.](http://www.codeblocks.org/)

Untuk mulai download aplikasi **Code::Blocks**, silahkan buka alamat web diatas, lalu klik menu **"Download"** (1), dan pilih **"Download the binary release"** (2).

[![Pilih menu download Code Blocks](https://www.duniailkom.com/wp-content/uploads/2017/03/Pilih-menu-download-Code-Blocks.jpg)](https://www.duniailkom.com/wp-content/uploads/2017/03/Pilih-menu-download-Code-Blocks.jpg)

Pilih menu download Code Blocks

Di halaman berikutnya pilih sistem operasi dimana **Code::Blocks** akan diinstall. Jika menggunakan Windows, scroll halaman sampai ke judul **"Windows XP / Vista / 7 / 8.x / 10"**. Apabila menggunakan sistem operasi Linux atau Mac OS, link downloadnya juga tersedia.

Pada saat tutorial ini saya buat di Oktober 2020, versi terakhir adalah **Code::Blocks** **20.03**. Besar kemungkinan versi yang anda dapati akan lebih baru dari ini. Namun itu tidak masalah dan cara instalasinya kurang lebih tetap sama.

Terdapat beberapa jenis installer **Code::Blocks**. Pilih yang "**mingw-setup**" seperti dalam gambar dibawah, atau tepatnya "**codeblocks-20.03mingw-setup.exe".** Langkah ini **sangat penting** karena jika salah download, compiler C++ tidak akan terinstall (terpaksa download ulang lagi).

[![Cara Download CodeBlock](https://www.duniailkom.com/wp-content/uploads/2020/10/Cara-Download-CodeBlock.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Cara-Download-CodeBlock.png)

Cara Download Code::Block

Klik salah satu link "download form", bisa dari FossHUB atau Sourceforge.net. Jika tidak ada kendala, proses download akan berjalan. File instalasi **codeblocks-20.03mingw-setup.exe** berukuran sekitar **145MB**.

Jika mengalami kendala pada saat proses download atau ingin menggunakan versi yang sama dengan tutorial di Duniailkom ini, saya juga sudah siapkan link di Google Drive berikut: [Code::Block 20.03 (MinGW Setup) – Windows 64 bit](https://drive.google.com/file/d/18tbchZnuGRTWSC5RE8sspxQmm5gEe9w-/view?usp=sharing).

---

### Cara Menginstall Code::Blocks

Setelah file master Code::Block tersedia, saatnya mulai proses instalasi. Double klik file **codeblocks-20.03mingw-setup.exe** yang baru saja di download, dan akan tampil jendela awal proses instalasi.

[![Jendela awal proses instalasi Code Blocks](https://www.duniailkom.com/wp-content/uploads/2017/03/Jendela-awal-proses-instalasi-Code-Blocks.jpg)](https://www.duniailkom.com/wp-content/uploads/2017/03/Jendela-awal-proses-instalasi-Code-Blocks.jpg)

Jendela awal proses instalasi Code::Blocks

Klik tombol **"Next"** untuk lanjut. Lalu di halaman **"License Aggrement"**, klik saja tombol **"I Agree"**.

Halaman berikutnya adalah **"Choose Components"**, biarkan pilihan default (seluruh pilihan di centang), lalu klik tombol "**Next"**.

[![Memilih Komponen Code Block](https://www.duniailkom.com/wp-content/uploads/2020/10/Memilih-Komponen-Code-Block.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Memilih-Komponen-Code-Block.png)

Jendela **"Choose Install Location"** berguna untuk mengubah lokasi instalasi Code::Blocks. Disini saya akan membiarkan pilihan default. Artinya kode program Code::Blocks akan terinstall di **"C:\Program Files\CodeBlocks"**.

[![Lokasi Instalasi Code Block](https://www.duniailkom.com/wp-content/uploads/2020/10/Lokasi-Instalasi-Code-Block.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Lokasi-Instalasi-Code-Block.png)

Klik Tombol **"Install"** dan proses instalasi akan berlangsung beberapa saat.

[![Proses Instalasi Code Blocks Sedang Berlangsung](https://www.duniailkom.com/wp-content/uploads/2017/03/Proses-Instalasi-Code-Blocks-Sedang-Berlangsung.jpg)](https://www.duniailkom.com/wp-content/uploads/2017/03/Proses-Instalasi-Code-Blocks-Sedang-Berlangsung.jpg)

Proses Instalasi Code::Blocks Sedang Berlangsung

Setelah proses instalasi selesai, akan tampil jendela konfirmasi **"Do you want to run Code::Blocks now?"** Klik **Yes** agar setelah proses instalasi, IDE **Code::Blocks** langsung tampil.

Sampai disini, aplikasi **Code::Blocks** sudah sukses terinstall dan siap untuk digunakan.

[![Tampilan Code Block 20](https://www.duniailkom.com/wp-content/uploads/2020/10/Tampilan-Code-Block-20.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Tampilan-Code-Block-20.png)

Tampilan Code::Block 20

---

### Periksa Pengaturan Lokasi Compiler

Pada saat menginstall Code::Block, juga ikut terinstall compiler bahasa C++ **GNU GCC** yang disediakan oleh **MinGW-W64 project**. Aplikasi Code::Block harus terhubung dengan compiler ini agar nantinya bisa memproses file C++.

Untuk memeriksanya, silahkan buka menu **Settings -> Compilers…** 

[![Periksa compiler yang dipakai Code Block](https://www.duniailkom.com/wp-content/uploads/2020/10/Periksa-compiler-yang-dipakai-Code-Block.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Periksa-compiler-yang-dipakai-Code-Block.png)

Setelah itu pilih tab "**Toolchain executables**" (1).dan pastikan kotak teks "**Compiler's installation directory**" berisi "**C:\Program Files\CodeBlocks\MinGW**" (2) seperti gambar di bawah ini:

[![Periksa compiler yang dipakai Code Block](https://www.duniailkom.com/wp-content/uploads/2020/10/Periksa-compiler-yang-dipakai-Code-Block-2.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Periksa-compiler-yang-dipakai-Code-Block-2.png)

Jika kolom ini berisi alamat lain atau kosong, klik tombol "**Auto-detect**" agar Code::Block bisa mencari compiler bahasa C++ secara otomatis.

Jika anda menggunakan aplikasi Code::Block versi lama, bisa saja kotak ini berisi alamat **C:\Program Files (x86)\CodeBlocks\MinGW**. Itu juga tidak masalah karena di versi sebelumnya, folder instalasi Code::Block ada di **C:\Program Files (x86)\CodeBlocks\ **

Tutup jendela pengaturan ini dengan menekan tombol **OK**.

---

Dalam tutorial kali ini kita telah berhasil menginstall aplikasi IDE **Code::Blocks**. Inilah aplikasi yang akan dipakai sebagai tempat menulis kode program bahasa C++.

Mengenai cara menggunakan Code::Block, akan kita bahas pada tutorial berikutnya: [Cara Menjalankan Kode C++ (Proses Compile)](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-cara-menjalankan-kode-c-plus-plus-atau-proses-compile/ "Tutorial Belajar C++ Part 4: Cara Menjalankan Kode C++ (Proses Compile)").