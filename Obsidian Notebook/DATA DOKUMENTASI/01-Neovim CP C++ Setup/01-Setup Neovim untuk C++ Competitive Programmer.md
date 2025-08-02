---
obsidianUIMode: preview
note_type: Dokumentasi
judul_dokumentasi: Setup Neovim untuk C++ Competitive Programmer
date_add: 2025-07-23T23:10:00
status_dokumentasi: ✅Finish
tags:
  - neovim
  - vim
  - lazyvim
---
---
# NEOVIM Introduction
---
<br/>

## Apa itu NEOVIM
Nvim adalah singkatan dari Neovim, yaitu sebuah text editor (editor teks) yang merupakan fork atau turunan dari Vim, namun lebih modern, modular, dan extensible.

### 🔍 Penjelasan Singkat:
Vim adalah editor teks terkenal yang berjalan di terminal, terkenal karena kecepatannya dan navigasi berbasis keyboard.

Neovim dikembangkan untuk:
- Memperbaiki arsitektur Vim yang lama.
- Memberi dukungan yang lebih baik untuk plugin modern, seperti LSP (Language Server Protocol), debugging, dan integrasi IDE.
- Mempermudah kustomisasi dengan bahasa seperti Lua.

### 🧠 Fitur Utama Neovim:
- 💡 LSP (Language Server)	Fitur seperti autocomplete, go-to definition, linting.
- 🔌 Plugin Modern	Mendukung plugin dengan Lua, lebih cepat dan powerful.
- ⚙️ Konfigurasi Lua	Bisa dikonfigurasi dengan Lua (lebih bersih dan efisien dibanding Vimscript).
- 🧩 Ekosistem Plugin Aktif	Banyak plugin seperti telescope.nvim, nvim-tree, lualine, dll.
- 📟 Terminal Terintegrasi	Bisa buka terminal langsung di dalam Neovim.
- 🖥️ GUI Support (opsional)	Bisa dipakai dengan GUI frontend seperti Neovide, LunarVim, dll.

### 🚀 Cocok Untuk Siapa?
- Cocok banget buat programmer yang suka kerja cepat, efisien, dan dengan keyboard-centric.
- Bagi pengguna Vim yang ingin fitur modern seperti autocompletion dan debugging, Neovim adalah upgrade terbaik.

---
<br/>

## 🚀 Kenapa Neovim Sangat Cocok untuk Competitive Programming?

Neovim adalah editor teks modern berbasis terminal yang dirancang untuk kecepatan, efisiensi, dan fleksibilitas — tiga hal yang sangat penting bagi seorang competitive programmer. Berikut alasan utamanya:

### ✅ 1. Super Cepat dan Ringan

Neovim berjalan di dalam terminal dan memiliki waktu startup yang hampir instan. Dibandingkan dengan IDE besar seperti VS Code atau IntelliJ:

- **Tanpa GUI berat**: Neovim hanya fokus pada teks, tanpa embel-embel visual yang memperlambat.
- **Responsif di mesin spek rendah**: Cocok digunakan bahkan di laptop jadul atau lingkungan server.

### ✅ 2. Navigasi Cepat Tanpa Mouse

Segala sesuatu di Neovim dirancang untuk dilakukan **dengan keyboard**:

- Navigasi antar file, berpindah tab, pindah antar fungsi — semua bisa dilakukan dalam hitungan detik.
- Minimalkan waktu yang terbuang karena bolak-balik antara mouse dan keyboard.

### ✅ 3. Bisa Disesuaikan dengan Workflow Competitive Programming

Neovim sangat fleksibel dan bisa dikonfigurasi untuk mendukung:

- 🔘 Compile dan run dengan satu tombol (misalnya: `F5`, `F3`, dll).
- 📥 Input otomatis dari file `input.txt` dan output ke `output.txt`.
- 📂 Snippets khusus C++, Python, dsb, agar bisa fokus langsung ke logika soal.
- 📄 Plugin seperti `telescope` untuk mencari file cepat, atau `nvim-lspconfig` untuk bantuan coding seperti IDE.

### ✅ 4. Hemat Waktu Saat Kontes

Setiap detik sangat berarti saat lomba. Dengan Neovim, kamu bisa:

- Membuka banyak file sekaligus dengan tabs/split.
- Menyusun test case otomatis dengan keymap yang kamu buat sendiri.
- Menyimpan template C++ atau Python hanya dalam 1 shortcut.

### ✅ 5. Tidak Perlu Tinggalkan Terminal

Neovim mendukung terminal terintegrasi (`:terminal`), sehingga:

- Kamu bisa **compile, run, dan debug langsung di dalam editor**.
- Tidak perlu ALT+TAB ke terminal lain — semuanya ada di satu tempat.

---
<br/>

## ⚡ Kenapa Neovim Sangat Cepat?

Kecepatan Neovim berasal dari desain dan arsitekturnya yang minimalis dan efisien:

- Dibuat dengan **C** dan **Lua**, bukan Electron.
- Tidak perlu GUI, hanya terminal — hemat resource.
- Mendukung **asynchronous processing**, jadi plugin tidak menghambat kinerja utama.
- Konfigurasi modular dan ringan.


Kalau kamu competitive programmer yang ingin kontrol penuh atas lingkungan ngodingmu, **Neovim adalah pilihan yang tepat**. Kombinasi kecepatan, efisiensi, dan kemampuan custom-nya membuat kamu bisa lebih fokus menyelesaikan soal — bukan melawan editor.

---
<br/>

# Tahap Instalasi Awal

## 2.1 | Install scoop
Untuk bisa menginstal neovim dengan mudah, pertama-tama kita perlu mengistall aplikasi yang bernama scoop. Scoop adalah package manager untuk Windows yang membuat instalasi software dari command line jadi super gampang dan rapi — mirip seperti apt di Linux atau brew di macOS.

Dengan Scoop, kamu bisa install aplikasi terminal (seperti neovim, git, node, dll) hanya dengan satu perintah:

```bash
scoop install neovim
```

Kenapa kita pakai scoop untuk snstall Neovim?
Karena:
- 📦 Mudah & cepat: Tidak perlu cari-cari file .exe di internet.
- 🚫 Tanpa bloatware: Tidak ada iklan, bundling, atau embel-embel lain.
- 🧹 Instalasi rapi: Semua aplikasi diatur dalam folder khusus (C:\Users\<user>\scoop), gampang dihapus kalau ingin uninstall total.
- 🔁 Auto-update: Dengan scoop update, kamu bisa update semua tool CLI termasuk Neovim.

Atau, semisal kalau kamu butuh tambahan tool seperti clang, gcc, atau python buat competitive programming, tinggal:

```bash
scoop install gcc python git
```

Nah, cara install scoop sendiri mudah, kita cukup pergi ke situs resmi dari scoop, yaitu [scoop.sh](https://scoop.sh/), lalu disana akan diberikan syntax yang perlu kita copy-paste ke terminal kita, untuk memasangnya. 

![[nvim-setup.png]]


> ⚠️ Lebih baik kunjungi situs resmi jika ada perubahan! 

Syntax yang perlu kita copy adalah seperti ini:

```bash
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
Invoke-RestMethod -Uri https://get.scoop.sh | Invoke-Expression
```

Pasang di terminal kita, misal klik kanan untuk paste cepat (disini aku menggunakan powershell), lalu tekan enter.

Lalu jika sudah muncul pernyataan seperti ini, artinya instalasi kita berhasil:

```bash
PS C:\Users\ASUS> Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
PS C:\Users\ASUS> Invoke-RestMethod -Uri https://get.scoop.sh | Invoke-Expression
Initializing...
Downloading...
Creating shim...
Adding ~\scoop\shims to your path.
Scoop was installed successfully!
Type 'scoop help' for instructions.
PS C:\Users\ASUS>
```


---
<br/>

## 2.2 | Instalasi Git
Git adalah sistem kontrol versi (version control system) yang membantu kamu melacak perubahan dalam file atau proyek, khususnya dalam pemrograman dan pengembangan perangkat lunak.

Kamu perlu memasangnya agar bisa mendapatkan banyak kemudahan dalam proses instalasi, dan agar nantinya konfigurasi neovim yang kamu buat dengan susah payah bisa disimpan dengan aman.

Apa yang dilakukan Git?

- Mencatat perubahan pada file seiring waktu.
- Membuat versi-versi (history) dari proyek kamu, seperti _save point_.
- Bekerja secara kolaboratif (bisa kerja bareng tim tanpa konflik).
- Mendukung backup ke layanan seperti GitHub (kode kamu aman di cloud).

Analogi sederhana, bayangkan kamu sedang menulis dokumen skripsi:

- Tanpa Git: kamu simpan file seperti `skripsi-final-v3-fix-final-REVISI-BENAR.docx`.
- Dengan Git: kamu hanya punya 1 file, tapi bisa **lihat semua revisi sebelumnya**, **balik ke versi tertentu**, bahkan **lihat siapa ubah apa**.
### ⚙️ Fitur Penting Git:

|Fitur|Keterangan|
|---|---|
|`git init`|Memulai repositori Git di folder kamu|
|`git add`|Menandai file yang ingin disimpan perubahannya|
|`git commit`|Menyimpan snapshot/perubahan ke dalam repositori|
|`git status`|Melihat status file: apakah ada yang diubah, belum disimpan, dll|
|`git push`|Mengirim perubahan ke GitHub atau server Git lain|
|`git pull`|Mengambil update terbaru dari GitHub|
|`git clone`|Menyalin seluruh proyek dari GitHub ke komputer lokal kamu|

### 🌍 Git vs GitHub

- **Git**: alat lokal untuk version control.
- **GitHub**: layanan hosting berbasis cloud untuk menyimpan proyek Git kamu secara online.

### 🪣 Cara instal git
Untuk install git, kamu bisa mengunjungi situs resminya, yaitu [git-scm](https://git-scm.com/), dan pilih versi git yang sesuai, misal jika kamu menggunakan windows, pilih git untuk windows dan unduh. Untuk tahapan penginstalan git, bisa kamu ikuti panduan yang sudah banyak berseliweran di internet. Atau kamu juga bisa menggunakan scoop untuk menginstall git, dengan cara:

```bash
scoop install git
```

Namun karena ada banyak konfigurasi yang perlu dilakukan ketika menginstall git, lebih baik lakukan penginstalan manual dengan cara menginstall file zip nya di situs resminya.

![[git-site.png]]

Jika proses instalasi sudah selesai, kita cek terlebih dahulu di terminal kita, atau pastikan kita bisa membuka git bash di opsi terminal. Ketikan perintah berikut:

```bash
git --version
```

Dan jika muncul output seperti ini, maka pemasangan git kita berhasil:

```bash
git version 2.49.0.windows.1
```

---
<br/>

## 2.3 | Pembuatan akun Github
GitHub adalah layanan hosting berbasis web untuk proyek yang menggunakan Git. Bisa dibilang, GitHub adalah tempat kamu menyimpan dan berbagi kode Git secara online.

Apa yang dilakukan GitHub?

- Menyimpan repositori Git kamu di cloud.
- Memudahkan kolaborasi dengan orang lain (tim, open source, dll).
- Menyediakan antarmuka web untuk melihat, mengedit, dan mengatur proyek Git.
- Memiliki fitur tambahan seperti **Issues**, **Pull Requests**, **Wiki**, **Actions (CI/CD)**, dan lainnya.

Analogi:

Bayangkan kamu punya proyek Neovim lokal yang dikontrol Git. Lalu kamu upload ke GitHub agar bisa:

- Diakses dari komputer lain.
- Dibagikan ke orang lain.
- Dikontribusi oleh tim.
- Dicadangkan secara online.

Contoh Kegunaan GitHub

- Menyimpan konfigurasi Neovim kamu (misal: `~/.config/nvim`) di GitHub.
- Melihat perubahan konfigurasi seiring waktu.
- Mendownload atau meng-clone repo orang lain untuk belajar (misal: dotfiles, plugin, script).

### 🧭 Istilah Penting di GitHub

|Istilah|Penjelasan|
|---|---|
|**Repository**|Folder proyek Git kamu yang disimpan di GitHub|
|**Commit**|Snapshot perubahan pada proyek|
|**Branch**|Versi terpisah dari proyek untuk menguji fitur baru|
|**Pull Request**|Permintaan untuk menggabungkan perubahan ke branch utama|
|**Fork**|Salinan proyek orang lain yang bisa kamu modifikasi sendiri|
|**Star**|Seperti “like” — menunjukkan kamu menyukai atau ingin menyimpan repo itu|
|**Issue**|Tempat mendiskusikan bug, fitur baru, atau laporan|

### 🔑 Pembuatan akun Github
Untuk membuat akun github, caranya cukup mudah, dan jika kamu melihat repository ini, harusnya kamu sudah membuat akun github sebelumnya. Tapi jika belum, cukup masuk ke situs [github.com](https://github.com/), dan kamu buat akun disana.

---
<br/>

## 2.4 | Instalasi Node js
Node.js adalah lingkungan runtime JavaScript di luar browser — artinya, kamu bisa menjalankan kode JavaScript di komputer langsung, tanpa perlu browser seperti Chrome atau Firefox.

Penjelasan Singkat Node.js

- Biasanya, JavaScript hanya berjalan di browser.
- Node.js memungkinkan JavaScript berjalan di sisi server atau sistem lokal.
- Dibangun di atas mesin V8 JavaScript Engine milik Google (yang juga dipakai di Chrome).

Untuk Apa Node.js Digunakan?

|Penggunaan|Penjelasan|
|---|---|
|💻 **Server-side programming**|Bangun backend, API, web server (misalnya pakai Express.js)|
|⚙️ **CLI Tools**|Buat command-line tool (misal: `npm`, `vite`, `eslint`, dll)|
|🔗 **Build tools**|Digunakan untuk alat-alat seperti Webpack, Babel, ESLint, Prettier|
|🔌 **Plugin/Extensions**|Banyak plugin Neovim modern (seperti LSP, formatter, linter) butuh Node|

Nahh, kita perlu pasang nodejs karena kita akan menggunakan banyak plugins di neovim kedepanya.

Node.js perlu kamu pasang jika kamu ingin menggunakan plugin-plugin modern di Neovim — apalagi kalau kamu pakai LazyVim, AstroNvim, atau konfigurasi berbasis LSP dan Treesitter.

### 🤔 Kenapa Harus Install Node.js untuk Neovim?

Karena banyak plugin Neovim yang:

✅ Ditulis dalam JavaScript/TypeScript  
✅ Butuh eksekusi via Node.js  
✅ Pakai `npm` untuk install dependency


Banyak plugin Neovim modern (terutama berbasis JavaScript/TypeScript) **membutuhkan Node.js**, contohnya:

- `nvim-treesitter`
    
- `null-ls.nvim`
    
- `mason.nvim` (dan beberapa formatter)
    
- `prettier`, `eslint`, dll.
    

> 📌 **Jika kamu pakai LazyVim**, biasanya kamu akan diminta install `node` agar semuanya berjalan normal.

### 💫Instal Node js

Untuk menginstall node js, kita bisa masuk ke situs resmi dari [Node Js](https://nodejs.org/en/), dan masuk ke bagian menu [download node js](https://nodejs.org/en/download), lalu semisal kamu menggunakan windows sekarang, unduh node js untuk windows, mungkin yang memiliki ekstensi .msi.

Kamu juga bisa menginstall node js dari scoop juga, dengan cara berikut:

```bash
scoop install nodejs
```

Maka akan muncul beberapa proses download pada terminal, dan diakhiri dengan ini:

```bash
'nodejs' (24.4.1) was installed successfully!
```

Kita cek apakah benar-benar terinstall sepenuhnya, dengan cara mengetikan ini pada terminal, dan jika keluar versinya, maka artinya pemasangan berhasil:

```bash
node -v
```

Output:

```bash
v24.4.1
```

---
<br/>

## 2.5 | Instalasi LLVM dan GCC

LLVM dan GCC adalah compiler toolchain — alat untuk menerjemahkan kode sumber (seperti C/C++) menjadi program yang bisa dijalankan di komputer.

### 🧱 1. GCC (GNU Compiler Collection)

- 🔧 Compiler yang dikembangkan oleh proyek **GNU**.
- Bahasa yang didukung: `C`, `C++`, `Fortran`, `Ada`, `Go`, dll.
- Compiler default di **Linux**.
- Di Windows, biasanya digunakan lewat **MinGW** atau **MSYS2**.

✅ Paling banyak digunakan secara historis  
✅ Kompatibel dengan banyak project open-source  
✅ Compiler default di banyak distro Linux

🔍 Cek versi:

```bash
g++ --version
```

### 🧠 2. LLVM (Low Level Virtual Machine)

- LLVM adalah **framework** untuk membuat compiler modern.
- Compiler `clang` adalah bagian dari LLVM (khusus untuk C/C++).
- Dibuat oleh Apple, sekarang jadi standar di macOS dan iOS development.
- Fokus pada **kecepatan kompilasi** dan **diagnosis error yang jelas**.

✅ Lebih cepat dan output error-nya lebih informatif  
✅ Compiler default di macOS  
✅ Cocok buat pengembangan modern dan embedded

🔍 Cek versi:

```bash
clang++ --version
```

### ⚔️ GCC vs LLVM/Clang

|Fitur|GCC|LLVM / Clang|
|---|---|---|
|Asal|GNU Project|Apple / LLVM Foundation|
|Kecepatan Kompilasi|Sedikit lebih lambat|Lebih cepat|
|Error Message|Kurang detail|Lebih informatif dan jelas|
|Dukungan OS|Linux, Windows, macOS|Linux, Windows, macOS|
|Popularitas|Banyak di Linux/Unix|Banyak di macOS dan project modern|

Kalau kamu ingin rekomendasi:  
- ✅ **Pakai `clang` (LLVM)** kalau kamu pengin modern, cepat, dan error message-nya enak dibaca.  
- ✅ Tapi **`gcc` juga bagus**, terutama kalau kamu terbiasa dengan tool Linux klasik.

### 🖥️ Instalasi LLVM 
Untuk menginstall LLVM, kita bisa masuk ke situs resminya, yaitu [LLVM](https://releases.llvm.org/download.html). 

![[llvm-site.png]]

Dan kita akan diarahkan ke situs downloadnya yang berada di repository github [llvm-project/release](https://github.com/llvm/llvm-project/releases). 

![[llvm-site-2.png]]

Scrool kebawah, dan kamu akan mendapatkan banyak vesi unduhan yang bisa dipilih:

![[llvm-site-3.png]]

Atau, jika ingin cepat, seperti biasa 😊, lakukan via scoop, dengan cara mengetikan ini diterminal:

```bash
scoop install llvm
```

Tunggu prosesnya selesai, dan cek apakah berhasil terpasang di komputer kita dengan cara mengetikan syntax berikut di terminal:

```bash
clang --version

# atau

clang++ --version
```

Jika muncul output seperti berikut, maka artinya instalasi berhasil:

```bash
clang version 18.1.7
Target: x86_64-pc-windows-msvc
Thread model: posix
InstalledDir: C:\Program Files\LLVM\bin
```

Nah, saat kita instal LLVM, sebenarnya ada banyak paket yang kita install juga.

Kalau kamu install **LLVM**, terutama dari sumber resmi seperti website LLVM atau dari Scoop (`scoop install llvm`), kamu akan mendapatkan **paket LLVM lengkap**, yang terdiri dari komponen-komponen berikut:

 omponen Utama dalam LLVM:

|Komponen|Penjelasan|
|---|---|
|**LLVM**|Framework inti untuk compiler, optimizer, IR (Intermediate Representation)|
|**Clang**|Front-end compiler untuk C, C++, Objective-C|
|**clang-tools-extra**|Alat bantu seperti `clang-tidy`, `clangd`, dll|
|**LLD**|Linker modern buatan LLVM (alternatif `ld`)|
|**libc++**|Library standar C++ versi LLVM (implementasi STL)|
|**Polly**|Loop optimizer berbasis polyhedral model|
|**Flang**|Compiler untuk bahasa Fortran (Fortran + LLVM)|

Jika install lewat `scoop install llvm`, kamu akan mendapat:

- `clang`, `clang++` → compiler utama
- `clangd` → language server (buat LSP di Neovim misalnya)
- `clang-format`, `clang-tidy` → format & lint checker
- `lld` → linker
- `llvm-ar`, `llvm-nm`, `llvm-objdump` → tool level rendah
- `opt`, `llc`, `llvm-link` → optimizer dan IR tool

Cek sendiri isi LLVM hasil install dari Scoop

Setelah install:

```bash
clang --version
lld --version
clangd --version
clang-tidy --version
```

Atau cek daftar semua tool:

```bash
where clang
where clangd
where lld
```


> Jadi, ya — **dalam LLVM memang termasuk Clang, clang-tools-extra, LLD, libc++, Polly, dan Flang**.  
> 
> Beberapa mungkin belum sepenuhnya aktif digunakan (misal Flang masih berkembang), tapi tool utama seperti `clang`, `clangd`, `lld`, dll sudah siap pakai langsung dari instalasi.

### 🖥️ Instalasi GCC

Kalau kamu ingin download GCC secara manual lewat web, kamu bisa melakukannya — tapi prosesnya lebih rumit dibanding pakai Scoop. Biasanya orang mengunduh GCC melalui MinGW-w64, karena itulah versi GCC yang kompatibel untuk Windows.

Untuk bisa mengunduhnya, bisa masuk ke situs resmi dari [mingw-w64](https://www.mingw-w64.org/):

![[mingw-gcc.png]]


Dan lalu masuk ke menu [download](https://www.mingw-w64.org/downloads/):

![[mingw-gcc-2.png]]

Atau, jika kamu sedikit bingung dengan navigasi dari situs ini, bisa kamu langsung unduh dari situs [SourceForge](https://sourceforge.net/projects/mingw-w64/) berikut:

![[mingw-gcc-3.png]]

Setelah melakukan pengunduhan, install GCC tersebut dengan cara pemasangan pada umumnya.

Atau, seperti biasa 😊, via scoooop! Kita bisa instal langsung via scoop dengan cara mengetikan perintah ini diterminal:

```bash
scoop install gcc
```

> Ini akan menginstal GCC (via paket `main/gcc`), biasanya versi dari **MinGW-w64**, dan menyediakan:

- `gcc` (compiler C)
- `g++` (compiler C++)
- Tools lain seperti `gdb`, `ld`, dll.

Nah, cek terlebih dahulu apakah pemasangan berhasil, dengan cara ketikan perintah berikut di terminal:

```bash
gcc --version
```

Nah kalau muncul hasil seperti ini, artinya pemasangan berhasil:

```bash
gcc.exe (GCC) 13.2.0
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

#### Alternatif lain - MSYS2

Ada juga alternatif lain dalam menginstall Alternatif Lain - MSYS2. Kalau kamu lebih advanced dan ingin ekosistem UNIX-like di Windows, kamu bisa pakai [MSYS2](https://www.msys2.org/):

![[msys2.png]]

Ikuti panduan cara install GCC yang mudah diikuti di situs ini. Intinya, setelah berhasil memasang MSYS2, kita jalankan perintah berikut di terminalnya:

```bash
pacman -S mingw-w64-x86_64-gcc
```

Tapi ini biasanya dipakai oleh programmer tingkat lanjut atau untuk compile CMake, DLL, dsb.

---
<br/>

## 2.6 | Instalasi Neovim
Sekarang kita bisa menginstal neovim dengan mudah, cukup ketikan syntax berikut pada terminal kita, lalu tekan enter, lalu tunggu hingga proses selesai:

```bash
scoop install neovim
```

Gambar berikut menunjukan proses pemasangan neovim berhasil:

![[neovim-install-img.png]]

---
<br/>

# Instalasi Plugins Awal Neovim
Kita perlu tahu terlebih dahulu, bahwa saat kita menginstal neovim dari scoop, maka neovim kita masih kosong, default, tidak ada konfigurasi apapun, atau sebutannya "*plain neovim*". Beberapa mungkin tidak masalah dengan neovim tanpa konfigurasi ini. Tetapi, seperti halnya linux dengan banyak sekali distronya, neovim juga memiliki beberapa distronya sendiri, ini disebut dengan **Neovim distribution**.

Neovim distribution berguna untuk memudahkan kita menggunakan neovim. Dan yang paling penting, mempercantik tampilan dan memudahkan workflow. 

Beberapa neovim distribution pupuler ini bisa kamu pilih:

| Distro              | Ciri Khas / Fokus                                                                                      |
| ------------------- | ------------------------------------------------------------------------------------------------------ |
| **LunarVim (lvim)** | Fokus ke user yang biasa pakai IDE (mirip VSCode), plugin banyak, pakai `which-key`, `telescope`, dll. |
| **LazyVim**         | Distro ringan dan modular, dibangun dengan plugin manager `lazy.nvim`, pakai Lua penuh.                |
| **NvChad**          | Tampilan modern dan interaktif, sangat cocok buat user yang suka tampilan “gahar”.                     |
| **AstroNvim**       | Paling mirip IDE penuh, kompleks, cocok buat user advance yang suka fitur banyak.                      |

---
<br/>

## 3.1 | Instalasi LazyVim
Disini, aku memilih untuk menginstal LazyVim, jadi ikuti proses ini.

Pertama, pastikan neovim sudah terpasang. Untuk memastikan sekali lagi, bisa ketik perintah berikut pada terminal:

```bash
nvim --version
```

Jika neovim berhasil terpasang, maka akan muncul output seperti ini:

```bash
PS C:\Users\ASUS> nvim --version
NVIM v0.11.3
Build type: Release
LuaJIT 2.1.1741730670
Run "nvim -V1 -v" for more info
```

Jika sudah berhasil terpasang, untuk kamu yang pernah menggunakan neovim sebelumnya,  ada dua opsi disini. 

Jika kamu ingin menghapus konfigurasi neovim sebelumnya dengan yang baru, maka konfigurasi lama harus dibersihkan terlebih dahulu, sehingga bersih tempat instalasinya. Caranya dengan hapus manual pada folder `nvim` dan `nvim-data`. Lokasi pathnya ada di:

- `C:\Users\<nama-user>\AppData\Local\nvim`
- `C:\Users\<nama-user>\AppData\Local\nvim-data`

Atau cukup ketikan perintah ini diterminal:

```bash
Remove-Item $env:LOCALAPPDATA\nvim -Recurse -Force
Remove-Item $env:LOCALAPPDATA\nvim-data -Recurse -Force
```

Tapi  jika yang ingin kamu lakukan adalah mencoba konfigurasi neovim yang baru, maka data sebelumnya harus kita backup atau rename, supaya data lama aman, dan konfigurasi neovim yang baru tidak terganggu.

Rename folder `nvim` misal menjadi `nvim-bak`, dan `nvim-data` menjadi `nvim-data-bak`. Tapi terserah kamu jika ingin merename seperti apa. Atau jika kamu ingin memindahkan foldernya juga bisa, semisal memasukan kedua folder tadi di  `C:\Users\<nama-user>\AppData\Local\nvim-backup-folder`. 

Atau lakukan backup via terminal, dengan syntax berikut,  jalankan pada terminal dan enter:

```bash
# required
Move-Item $env:LOCALAPPDATA\nvim $env:LOCALAPPDATA\nvim.bak

# optional but recommended
Move-Item $env:LOCALAPPDATA\nvim-data $env:LOCALAPPDATA\nvim-data.bak
```

Dengan ini, kapanpun kamu ingin kembali menggunakan konfigurasi neovim lama, cukup rename lagi. Atau jika backup yang dilakukan adalah dengan memindahkan foldernya, kembalikan lagi folder tersebut ke `C:\Users\<nama-user>\AppData\Local\`. Tentunya dengan gantian folder yang baru yang kita rename atau pindah.

---
Setelah antisipasi awal selesai, kita bisa langsung install LazyVim. Untuk menginstallnya, sebenarnya kita cukup clone repository github [LazyVim](https://github.com/LazyVim/LazyVim). Tapi sebelum itu, coba masuk ke repository ini terlebih dahulu.

Nahhh, disini kamu perlu sedikit membaca beberapa penjelasan yang dibuat sebelum bergerak terlalu jauh (baca file README maksudnya), seperti daftar fitur yang diberikan, syarat requirement yang terdiri dari neovim versi terbaru, git, C compiler, dan juga Nerd Font. Dan yang paling penting adalah bagaimana cara memulai instalasinya.

> [!NOTE] ⚠️ PENTING!
> Jangan melompat-lompat dalam mengikuti panduan yang diberikan. Hal ini penting untuk menghindari error yang tidak bisa diatasi di pemakaian jangka panjang, yang diakibatkan oleh kesalahan pemasangan diawal konfigurasi. 
> 
> Ini serius! 
> 
> Membaca pelan-pelan dan memahami dengan baik cara memasang konfigurasi dengan benar, dengan cara membaca semua dokumentasi yang diberikan, akan benar-benar menyelamatkan puluhan jam waktumu dari menangani error yang tidak perlu!
> 

Repository utama ini berisikan daftar pengaturan dan plugins default ketika kita memasang lazyVim. Jangan clone repository ini! Repo ini hanya berisi settingan default yang memang seharusnya tidak kita utak-atik langsung. Konfigurasi pada LazyVim yang nanti kita pasang bisa kita lakukan pada Repository yang akan disebutkan di bacaan README.

Di file README yang diberikan, pengguna dipersilahkan untuk membaca panduan yang lebih jelas di repository yang berbeda, yaitu [LazyVim/Starter](https://github.com/LazyVim/starter). Nah, ini adalah repository yang bisa kita clone, sebagai proses pemasangan LazyVim.

Kembali baca file README dari repository ini, dan kita akan diberikan situs dokumentasi instalasi, yaitu [LazyVim.org](https://www.lazyvim.org/), yang berisi panduan singkat dan mudah dipahami, tentang bagaimana menginstall LazyVim.

![[lazyvim-doc-img.png]]


Nah, ini adalah dokumentasi asli dari LazyVim, jadi ingat-ingat selalu situs ini jika terdapat masalah pada konfigurasi LazyVim. Dan tentunya, proses instalasi juga perlu kita ikuti disini. Untuk instalasi versi video, dokumentasi ini juga menyertakan video dari youtube yang bisa diikuti, jika lebih suka tutorial video:

![Zero to IDE with LazyVim - YouTube](https://www.youtube.com/watch?v=N93cTbtLCIM)

---
Oke, langsung saja, masuk ke menu [Installation](https://www.lazyvim.org/installation), maka akan muncul tampilan seperti ini:

![[nvim-install-img.png]]

Baiklah, berikut adalah panduan langsung dari dokumentasi resminya, bisa diikuti:

- Make a backup of your current Neovim files (*buat folder backup, tapi sudah kita lakukan sebelumnya, dan memang aku ambil dari dokumentasi ini wkwkw.. Jadi bisa diskip*):

	```bash
	# required
	Move-Item $env:LOCALAPPDATA\nvim $env:LOCALAPPDATA\nvim.bak
	
	# optional but recommended
	Move-Item $env:LOCALAPPDATA\nvim-data $env:LOCALAPPDATA\nvim-data.bak
	```

- Clone the starter (*clone repository*):

	```bash
	git clone https://github.com/LazyVim/starter $env:LOCALAPPDATA\nvim
	```

- Remove the `.git` folder, so you can add it to your own repo later (*hapus folder git, supaya kita bisa simpan konfigurasinya untuk repo kita sendiri*):

	```bash
	Remove-Item $env:LOCALAPPDATA\nvim\.git -Recurse -Force
	```

- Start Neovim! (*tunggu apa lagi, Gass!!*):

	```bash
	nvim
	```

> It is recommended to run `:LazyHealth` after installation. This will load all plugins and check if everything is working correctly (*setelah instalasi, didalam neovim, gunakan perintah `:LazyHealth` untuk mengecek apakah semua plugin terpasang dengan baik atau tidak*).

Maka, otomatis, ketika kita ketikan `nvim` pada terminal kita, neovim kita akan melakukan banyak sekali pengunduhan plugin awal, yang mana tampilanya akan seperti ini:

![[instal-1-img.png]]

Setelah semua proses loading selesai, maka akan ada momen dimana theme atau tampilan dari neovim kita berubah menjadi lebih bagus. Jika proses pengunduhan sudah selesai, tekan `q` untuk kembali ke tampilan menu utama, dan Taaaaraaa...., LazyVim kita berhasil terpasang:

![[lazyvim-img.png]]

> Baca FAQ ini sebelum lanjut, akan ada beberapa sesi FAQ yang penting untuk dibaca oke!

---
<br/>

## 3.2 | Instalasi ripgrep

Nah, ketika baru masuk, dan coba tekan key `f` pada keyboard untuk melakukan pencarian file, maka beberapa orang akan mengalami error, mungkin error pada notifikasi neovim yang kurang lebih seperti ini:

```bash
Command failed: 
- cmd: `find . -type f -not -path */.git/* -not -path */.*`
```

Untuk mengatasi hal ini, kita cukup install `ripgrep`. Apa itu  ripgrep?

**`ripgrep`** (alias `rg`) adalah tool pencarian **super cepat** di command line, untuk mencari teks dalam file—mirip `grep`, tapi jauh lebih cepat dan modern.

Cara installnya juga cukup mudah, yaitu masukan perintah berikut melalui terminal, tentu kita menggunakan scoop lagi:

```bash
scoop install ripgrep
```

Jika berhasil, maka tampilan berikut akan muncul:

![[README-1.png]]

Ripgrep sangat penting di neovim, karena dalam Neovim, terutama saat pakai plugin seperti:

- 🔭 **Telescope**
    
- 🔍 **fzf-lua**
    
- 📁 **file-search, live grep, grep string**
    

...`ripgrep` dipakai untuk mencari file, folder, atau isi file **dengan performa tinggi**, karena:

- Cepat banget (pakai regex engine Rust yang efisien)
    
- Bisa nge-skip `.gitignore` secara otomatis
    
- Bisa diintegrasikan ke plugin Neovim dengan mudah

### 🔥 Perbandingan Singkat:

|Tool|Fungsi|Cepat?|Bisa skip `.gitignore`?|
|---|---|---|---|
|`grep`|Cari teks dalam file|❌|❌|
|`find`|Cari file di folder|❌|❌|
|`ripgrep`|Cari teks/file **secara rekursif**|✅|✅|
|`fd`|Cari file (lebih cepat dari `find`)|✅|✅|

### 🧠 Contoh Pakai Manual di Terminal:

```bash
rg "keyword" .
```

Itu akan mencari **"keyword" di semua file dalam direktori saat ini dan subfolder**.

Jadi bisa dibilang:

> 🔥 **`ripgrep` adalah jantung pencarian modern di banyak editor, termasuk Neovim + LazyVim.**

---
<br/>

## 3.3 | Instalasi Nerd Font

Setelah kamu install LazyVim, terkadang ada beberapa font yang masih kotak-kotak, yang mana harusnya adalah icons-icons lucu. Hal ini karena kita masih menggunakan font biasa pada terminal. Untuk mengatasi ini, maka kita perlu menginstall font tertentu, yaitu font yang bisa membuat icons-iconst ini muncul, yaitu **Nerd Font**.

Nerd Font adalah font yang cukup unik, karena font ini menyimpan lebih dari 10.390 icons yang berbeda. Oleh karena itu, kita perlu mengganti font terminal yang kita pakai, menjadi font ini.

Font ini bisa diinstall dari situs resminya, yaitu [Nerd Font](https://www.nerdfonts.com/).

![[README-2.png]]

Setelah diinstal, ganti font terminal yang dipakai (misal powershell) dengan font ini, maka ketika kita membuka neovim kembali, icon-iconsnya akan muncul.

---
<br/>

## 3.4 | Instalasi curl

`curl` (kepanjangan dari _Client URL_) adalah command-line tool untuk mengirim dan menerima data dari/ke internet. Biasanya digunakan untuk mengakses URL dan mengunduh data dari web (misal: file, JSON, API response, dll).

Untuk menginstallnya melalui scoop, cukup ketik syntax berikut di terminal:

```bash
scoop install curl
```

Maka beberapa proses akan keluar, dan instalasi berhasil jika dibaris terakhir muncul baris seperti ini:

```bash
'curl' (8.15.0_2) was installed successfully!
```

curl lumayan penting, karena memiliki fungsi sebagai berikut:

|Fungsi|Contoh|
|---|---|
|Download file|`curl -O https://example.com/file.zip`|
|Kirim request ke API|`curl https://api.github.com/users/username`|
|Submit data ke server (POST)|`curl -X POST -d "username=abc&password=xyz" https://example.com/login`|
|Ikuti redirect|`curl -L https://short.url`|
Contoh penggunaanya, adalah semisal saat kita menginstall scoop:

```powershell
Invoke-RestMethod -Uri https://get.scoop.sh | Invoke-Expression
```

Itu di balik layar akan pakai `curl` (atau `Invoke-RestMethod`) untuk **mengambil skrip instalasi dari web**.

Lalu contoh kedua adalah ketika kita menginstall LazyVim:

```sh
git clone https://github.com/LazyVim/starter ~/.config/nvim
```

Sebelumnya kamu mungkin **lihat skrip setup pakai `curl`** juga untuk unduh auto-installer plugin manager.

### 📦 Apakah `curl` perlu diinstall manual?

- 🔹 **Di Windows 10+**, `curl` biasanya **sudah ada secara default**.
    
- 🔹 Di Linux dan macOS juga biasanya sudah pre-installed.
    
- 🔹 Tapi kalau hilang, bisa install lewat package manager seperti:
    
    - `sudo apt install curl` (Ubuntu/Debian)
        
    - `brew install curl` (macOS)
        
    - `scoop install curl` (Windows dengan Scoop)
### 💡 Singkatnya:

> 🔽 **`curl` = alat sakti buat download & ngobrol sama internet dari terminal.**  
> 🔧 Digunakan saat install plugin, fetch config, testing API, atau automation.


---
<br/>

## 3.5 | Instalasi Lazygit

`Lazygit` adalah UI berbasis terminal (TUI = Terminal User Interface) untuk mengelola Git dengan cara yang cepat, ringan, dan interaktif — tanpa perlu ketik semua command Git satu per satu.

Lazygit berasal dari repository [LazyGit](https://github.com/jesseduffield/lazygit), yang mana jika mengacu cara installnya dari dokumentasi README, maka kita cukup ketikan perintah berikut di terminal:

```bash
# Add the extras bucket
scoop bucket add extras

# Install lazygit
scoop install lazygit
```

> **Kenapa pakai extras?**
> 
> Bucket `extras` dalam Scoop adalah kumpulan perangkat lunak tambahan yang tidak termasuk dalam bucket utama (`main`). Bucket ini berisi berbagai alat bantu dan aplikasi yang lebih bersifat opsional atau ditujukan untuk kebutuhan khusus, seperti pengembangan perangkat lunak, desain grafis, atau utilitas tambahan. Contohnya termasuk `make`, `vscode`, `gimp`, dan banyak tool lain yang tidak secara langsung dibutuhkan oleh semua pengguna.
> 
> Alasan kenapa beberapa aplikasi—termasuk `make`—tidak tersedia di bucket `main` adalah untuk menjaga agar daftar default Scoop tetap ringan dan relevan untuk sebagian besar pengguna. Dengan memisahkan aplikasi-aplikasi tersebut ke dalam bucket `extras`, Scoop memberi fleksibilitas bagi pengguna untuk hanya menambahkan kategori perangkat lunak yang benar-benar mereka perlukan. Maka dari itu, sebelum bisa menginstal `make`, pengguna perlu menambahkan bucket `extras` terlebih dahulu menggunakan perintah `scoop bucket add extras`. Setelah itu, aplikasi-aplikasi yang termasuk di dalamnya akan tersedia untuk diinstal seperti biasa.
> 
> Dengan pendekatan ini, Scoop tetap modular dan terorganisir, sambil tetap memberi akses mudah ke berbagai tool pengembangan tambahan melalui bucket seperti `extras`.

Maka, ketika sudah selesai, ketik saja `lazygit` di terminal, dan tampilanya akan seperti ini:

![[README-3.png]]


🤔 Jadi, kenapa pakai Lazygit? Biasanya kalau pakai Git manual:

```bash
git add .
git commit -m "pesan"
git push origin main
git status
git diff
```

Itu semua **harus diketik**. T

Tapi dengan `lazygit`, kamu bisa:

- Navigasi file yang berubah
    
- Stage/unstage file (tekan spasi)
    
- Lihat `diff` per file
    
- Commit dengan pesan
    
- Push/pull langsung
    
- Lihat log branch
    
- Checkout branch
    
- Dan lainnya
    

🎥 **Tampilannya seperti ini di terminal:**

```
FILES          │ BRANCHES     │ COMMIT LOG
M main.cpp     │ * main       │ * feat: add new func
A test.cpp     │              │ * fix: small bug
 D utils.cpp   │              │ ...
```

> Dan semua pakai tombol navigasi keyboard (`↑ ↓ ← →`, `s`, `c`, `p`, dll.)

### 🧠 Cocok buat siapa?

- Kamu yang **belum hafal banyak perintah Git**
    
- Kamu yang **ingin kelola Git dengan cepat**
    
- Kamu yang **kerja di terminal (Neovim, WSL, Powershell, dll)**

Kalau kamu mau, Lazygit juga bisa **diintegrasikan langsung ke dalam Neovim** (pakai plugin `kdheepak/lazygit.nvim`). Jadi tinggal pencet tombol, langsung muncul UI-nya di dalam Neovim.

---
<br/>

## 3.6 | Instalasi fd

`fd` adalah pengganti `find` yang:

- Lebih cepat
- Lebih simpel sintaksnya
- Digunakan oleh banyak plugin di Neovim seperti `telescope.nvim`, `project.nvim`, dll.

Cara Install `fd` di Windows via Scoop (rekomendasi karena kamu sudah pakai):

```powershell
scoop install fd
```

> Jika error: `fd` mungkin dinamai `fdfind` di beberapa distribusi Linux (tapi scoop tetap pakai nama `fd`).

### 📦 Alternatif (tanpa Scoop):

1. Kunjungi: [https://github.com/sharkdp/fd/releases](https://github.com/sharkdp/fd/releases)
2. Download file `.zip` yang sesuai dengan Windows
3. Ekstrak dan tambahkan folder-nya ke `PATH` Environment Variable


Setelah itu, buka ulang Neovim dan coba lagi tekan `<leader>fp` (biasanya tombol shortcut untuk Projects). Harusnya sudah jalan.

---
<br/>

## 3.7 | Instalasi fzf

`fzf` adalah singkatan dari [Fuzzy Finder](https://github.com/junegunn/fzf), yaitu sebuah **tool command line** untuk mencari file, direktori, buffer, dll dengan **pencarian kabur (fuzzy search)**. Artinya, kamu nggak perlu ngetik nama file secara lengkap — cukup ketik sebagian atau huruf-huruf yang mirip, dia tetap bisa menemukan hasil yang relevan.

Contoh:

Kamu punya file bernama `app/controllers/user_controller.py`, lalu kamu ketik `usrctr` — `fzf` bisa tetap menemukannya!  

Itu karena `fzf` tidak mencocokkan karakter secara berurutan, tapi berdasarkan **kemiripan pola huruf**.

Fungsi `fzf` dalam Neovim

- Plugin seperti [`fzf.vim`](https://github.com/junegunn/fzf.vim) atau [`telescope.nvim`](https://github.com/nvim-telescope/telescope.nvim) bisa menggunakan `fzf` sebagai **backend pencarian**.
    
- Dipakai untuk:
    
    - Mencari file (`Files`)
        
    - Mencari isi file (`Live Grep`)
        
    - Switch buffer
        
    - Buka recent file
        
    - dll
        

Cara Install di Windows (kalau kamu pakai Scoop):

```powershell
scoop install fzf
```

Kalau kamu pakai terminal biasa atau shell PowerShell, `fzf` juga bisa digunakan di luar Neovim untuk cari file, command history, Git branch, dll.

### Perbandingan dengan `fd` dan `ripgrep`

|Tool|Fungsi utama|Peran dalam Neovim|
|---|---|---|
|`fd`|Cari file (lebih cepat dari `find`)|Backend untuk pencarian file|
|`ripgrep` (`rg`)|Cari isi file (text search)|Backend untuk `Live Grep`|
|`fzf`|UI untuk fuzzy search|Tampilan & navigasi interaktif|

---
<br/>

## 3.8 | Instalasi make
`make` adalah alat bantu build — biasanya dipakai untuk meng-compile atau membangun program dari source code, terutama program yang butuh disiapkan dulu sebelum bisa dijalankan.

Fungsi utama `make`:

- Menjalankan perintah tertentu dari **Makefile**.
- Makefile adalah file yang berisi langkah-langkah build otomatis.
- Biasanya digunakan di proyek C/C++, Rust, dan plugin Neovim tertentu seperti `fzf-native`.
### 📦 Contoh kasus di Neovim:

Misalnya kamu install plugin ini:

```lua
{
  "nvim-telescope/telescope-fzf-native.nvim",
  build = "make", -- ← bagian ini butuh perintah `make`
}
```

Artinya:

- Setelah plugin di-download, Neovim akan menjalankan `make`.
    
- `make` akan membangun (compile) kode C++ agar plugin bisa dipakai dengan performa tinggi.
    

Kalau kamu **nggak punya `make`**, maka plugin seperti `fzf-native` tidak akan berfungsi dengan maksimal (atau gagal dipasang).

Cara install `make` di Windows:  Via Scoop:

```powershell
scoop install make
```

Atau install **MinGW / Git for Windows** (karena mereka menyertakan make).

Cek apakah `make` sudah ada, dengan mengetik di terminal:

```sh
make --version
```

Kalau muncul versi, berarti udah siap! ✅

---
<br/>

# Instalasi Plugins Neovim untuk Workflow
Nah, sekarang, yang perlu kita lakukan adalah menambahkan beberapa plugins penting untuk kemudahan kita menggunakan neovim. Tapi sebelum itu, pahami struktur folder dari folder config neovim yang disarankan dari perancang neovim:

File-file yang berada di dalam folder `config` akan dimuat secara otomatis pada waktu yang sesuai, jadi kamu tidak perlu memanggil file-file tersebut secara manual. LazyVim sudah dilengkapi dengan sekumpulan file konfigurasi bawaan yang akan dimuat sebelum konfigurasi milikmu sendiri. Lihat penjelasannya di [sini](https://github.com/LazyVim/LazyVim/tree/main/lua/lazyvim/config). 

Kamu bisa menambahkan spesifikasi plugin kustommu di dalam folder `lua/plugins/`. Semua file di folder tersebut akan otomatis dimuat oleh [lazy.nvim](https://github.com/folke/lazy.nvim).

```
~/.config/nvim
├── lua
│   ├── config
│   │   ├── autocmds.lua      ← autocommand pribadi
│   │   ├── keymaps.lua       ← keybinding pribadi
│   │   ├── lazy.lua          ← konfigurasi lazy.nvim
│   │   └── options.lua       ← opsi/editor settings
│   └── plugins
│       ├── spec1.lua         ← plugin plugin-mu
│       ├── **                ← boleh tambah file lainnya
│       └── spec2.lua
└── init.lua                  ← titik masuk utama (entry point)
```

---
<br/>

## 4.1 | Plugins Bawaan
LazyVim adalah konfigurasi Neovim yang sudah siap pakai dan dilengkapi dengan banyak plugin yang telah dikonfigurasi sebelumnya untuk memberikan pengalaman IDE yang kaya. Jadi, ketika kamu menginstal LazyVim, kamu tidak hanya mendapatkan Neovim dasar, tetapi juga sekumpulan besar plugin yang berfungsi bersama.

Jika kamu ingin tahu plugins bawaan LazyVim, kamu bisa cek sendiri di folder konfigurasi nvim-mu, dan cari file bernama `lazy-lock.json`, disitulah plugins dasar LazyVim berada, jadi kita tidak perlu konfigurasi dari 0:

![[README-19.png]]

Untuk plugins diatas, sebenarnya tugas kita adalah mengaktifkan saja. Setelah aktif plugins tersebut bisa kita pakai.

> Plugin di Neovim umumnya sudah punya konfigurasi default dari pembuatnya, atau dari distribusi seperti LazyVim. Kita tidak perlu memulai dari nol—cukup menyesuaikan konfigurasi jika perlu. Folder `C:\Users\ASUS\AppData\Local\nvim-data` menyimpan data runtime dan plugin terinstal, bukan setting default secara eksplisit, tapi yang penting: kita bebas mengkustomisasi Neovim sesuai selera!
> 
> Di folder konfigurasi pemakai, yaitu di `C:\Users\ASUS\AppData\Local\nvim`, Neovim memberikan kebebasan penuh kepada kita melalui folder konfigurasi ini, agar bisa "merekayasa" pengalaman menggunakan editor sesuai kebutuhan dan selera pribadi. Mulai dari tampilan, keymap, hingga bagaimana LSP, formatter, dan plugin lainnya bekerja—semua bisa kita kontrol dari folder ini.



Berikut adalah daftar nama-nama plugin inti yang secara default disertakan dalam **LazyVim**, dikategorikan berdasarkan fungsinya:
### UI & UX

- **`LazyVim/LazyVim.nvim`**: Ini adalah inti dari LazyVim itu sendiri, menyediakan kerangka kerja.
    
- **`nvim-lualine/lualine.nvim`**: Baris status yang sangat dapat disesuaikan di bagian bawah Neovim.
    
- **`nvim-tree/nvim-tree.lua`**: File explorer yang terintegrasi langsung di Neovim (sering digantikan oleh Neo-tree di LazyVim versi baru).
    
- **`nvim-neo-tree/neo-tree.nvim`**: File explorer yang modern dan cepat, sering menjadi pengganti `nvim-tree`.
    
- **`akinsho/bufferline.nvim`**: Menampilkan tab buffer yang terbuka di bagian atas.
    
- **`lukas-reineke/indent-blankline.nvim`**: Menampilkan garis panduan indentasi untuk visualisasi struktur kode.
    
- **`rcarriga/nvim-dap-ui`**: Antarmuka pengguna untuk debugging.
    
- **`nvim-telescope/telescope.nvim`**: Fuzzy finder yang kuat untuk file, buffer, riwayat, dan lainnya.
    
- **`romgrk/barbar.nvim`**: Alternatif untuk `bufferline.nvim` untuk manajemen buffer.
    
- **`folke/which-key.nvim`**: Menampilkan daftar keymap yang tersedia saat kamu menekan prefix.
    
- **`nvim-web-devicons`**: Menyediakan ikon file untuk berbagai jenis file.
    
- **`catppuccin/nvim`** atau **`folke/tokyonight.nvim`**: Contoh colorscheme default.
    

---

### Pemrograman & Produktivitas

- **`neovim/nvim-lspconfig`**: Konfigurasi umum untuk berbagai Language Server Protocol (LSP).
    
- **`williamboman/mason.nvim`**: Manajer paket untuk LSP, _linters_, _formatters_, dan _debuggers_.
    
- **`williamboman/mason-lspconfig.nvim`**: Integrasi Mason dengan `nvim-lspconfig`.
    
- **`hrsh7th/nvim-cmp`**: Mesin _autocompletion_ yang canggih.
    
- **`hrsh7th/cmp-nvim-lsp`**: Sumber completion untuk LSP di `nvim-cmp`.
    
- **`saadparwaiz1/cmp_luasnip`**: Sumber completion untuk _snippets_ di `nvim-cmp`.
    
- **`L3MON4D3/LuaSnip`**: Mesin _snippets_.
    
- **`nvim-treesitter/nvim-treesitter`**: Parser sintaksis yang lebih canggih untuk _highlighting_ dan navigasi.
    
- **`nvim-treesitter/nvim-treesitter-textobjects`**: Menambahkan _text objects_ berdasarkan pohon sintaksis Treesitter.
    
- **`tpope/vim-fugitive`**: Integrasi Git yang komprehensif.
    
- **`lewis6991/gitsigns.nvim`**: Menampilkan indikator perubahan Git di gutter.
    
- **`folke/flash.nvim`**: Plugin untuk navigasi cepat dan pencarian visual.
    
- **`folke/trouble.nvim`**: Menampilkan daftar diagnostik, hasil pencarian, dan lokasi lainnya.
    
- **`stevearc/conform.nvim`**: Manajer untuk _code formatters_.
    
- **`mfussenegger/nvim-lint`**: Manajer untuk _code linters_.
    
- **`rcarriga/nvim-dap`**: Debug Adapter Protocol (DAP) client untuk debugging.
    
- **`theprimeagen/harpoon`**: Plugin untuk navigasi cepat ke file-file penting.
    

---

### Utilitas

- **`folke/noice.nvim`**: Pengganti UI untuk pesan dan _cmdline_.
    
- **`folke/toggleterm.nvim`**: Terminal terintegrasi yang dapat di-toggle.
    
- **`echasnovski/mini.nvim`**: Kumpulan modul utilitas kecil (LazyVim mungkin menggunakan beberapa modul dari `mini.nvim` seperti `mini.pairs` untuk auto-closing braces).

---

Perlu diingat bahwa daftar ini bisa sedikit bervariasi tergantung pada versi LazyVim yang kamu gunakan dan bagaimana tim pengembang memutuskan untuk mengemas fitur-fitur baru. Namun, ini adalah inti dari apa yang akan kamu dapatkan secara _default_ saat menginstal LazyVim.

> Catatan: Beberapa plugins bawaan tidak otomatis aktif (*enabled*) saat kita pasang LazyVim, jadi masih harus dikonfigurasi lebih lanjut. Ikuti saja panduanya sampai akhir!

---
<br/>

## 4.2 | Plugins untuk C++
Karena tujuan menggunakan neovim kali ini adalah untuk bisa menggunakan C++, maka kita juga perlu menginstall beberapa plugins untuk C++. Kamu ketik `:Mason` pada cmd LazyVim, dan kamu akan dimasukan kedalam tampilan daftar plugins. Untuk menyaringnya berdasarkan bahasa, tekan *Ctrl+f*, dan lalu pilih bahasa C++. Setelah itu, akan muncul tampilan seperti ini:

![[Screenshot 2025-07-25 104850.png]]

Nah, beberapa plugin yang perlu kita pasang adalah:

- `clangd` - LSP utama untuk C++: Memiliki fungsi untuk Autocomplete, goto definiton, hover, docs, dll.
- `clang-format` - Formatter untuk C++: Berguna untuk merapikan kode otomatis (misal saat save file).
- `cpplint` - Linter untuk C++: Berguna untuk memberi warna warning pada penulisan C++, bukan error compiler tentunya.
- `codelldb` - Debugger untuk C++: Debugginig dengan UI seperti DAP (Breakpoint, step over, dsb).

Cara pasangnya cukup mudah, bisa arahkan mouse ke daftar plugins diatas, lalu tekan `i` untuk install. Atau, kita bisa membuatnya otomatis terinstall, dengan membuat file baru didalam folder `plugins`, misal `mason.lua`, dan menulis kode seperti ini:

```lua
return{ 
  {
    "williamboman/mason.nvim",
    opts = function(_, opts)
      -- tambahkan tools ke daftar ensure_installed
      opts.ensure_installed = opts.ensure_installed or {}
      vim.list_extend(opts.ensure_installed, {
        "stylua",
        "shellcheck",
        "shfmt",
        "flake8",
        "clang-format",
        "clangd",
        "codelldb",
        "cpplint",
      })
    end,
  }, 
  {
      "mason-org/mason.nvim",
      opts = {
          ui = {
              icons = {
                  package_installed = "✓",
                  package_pending = "➜",
                  package_uninstalled = "✗"
              }
          }
      }
  }
}
```

Untuk C++, 4 baris ini harus ada:

```bash
"clang-format",
"clangd",
"codelldb",
"cpplint",
```

Maka, saat kita masuk lagi ke neovim, dan mengetikan `:Mason`, proses install akan berjalan. Ini akan membuat semisal kode kita dipindahkan ke perangkat lain, di perangkat tersebut plugins diatas akan otomatis terinstall jika belum terpasang, membuatnya lebih efisien.

---
Untuk antisipasi error, jika gagal terpasang, maka ada kemungkinan masalahnya adalah ada plugins tertentu yang belum terpasang. Kemungkinan adalah `unzip`, `wget`, `gzip`, dan `pwsh` tidak tersedia.

Mason sangat mengandalkan tools seperti `unzip`, `wget`, dan `gzip` untuk mendownload dan mengekstrak file tools yang ingin di-install.

Kalau mereka tidak ada, maka Mason gagal install tool seperti `clangd`, `codelldb`, dll.

Jadi, kita perlu menginstall keempat-empatnya dengan scoop, sebagai berikut:

```bash
scoop install unzip wget gzip pwsh
```

Tunggu hingga proses selesai. Setelah itu restart neovim.

Untuk mengetahui apakah ada yang error atau tidak, kita cek di `:checkhealth mason`, lalu cari apakah masih ada warning yang perlu diatasi. 

![[README-12.png]]

Tampilan diatas menjelaskan bahwa plugin yang dibutuhkan sudah berhasil kita pasang, LSP untuk beberapa bahasa tidak kita pasang, karena kita hanya memasang C++. Dan Mason kita juga perlu diupdate.

Update: `:Lazy update` -> `Lazy clean` -> `:Lazy sync`

Sekarang, masuk ke dahsboard neovim, lalu masuk ke mode command atau cmd dengan cara menekan *shift + :* , lalu ketik `Mason`, maka akan tampil tampilan plugins mason yang bisa kita pasang. Tekan *Ctrl + f* untuk memfilter, ke C++. Jika plugins sebelumnya berhasil terpasang, maka akan muncul tampilan seperti ini:

![[README-13.png]]

Jika `clang-format`, `clangd`, `codelldb`, dan `cpplint` tertera ditampilan, maka artinya plugins berhasil terpasang.

Jika ingin install manual, juga bisa. Masuk ke neovim, dan lalu masukan perintah berikut di mode command:

```bash
:MasonInstall codelldb cpplint clang-format clangd
```

---
<br/>

## 4.3 | Install plugins via Scoop
Kita sudah menginstall nya di neovim, tapi kadang plugins neovim butuh koneksi langsung ke software yang terpasang di komputer kita, jadi kita perlu menginstall semuanya di scoop juga.

Untuk `clang-format` dan `clangd`, karena kita sudah menginstall LLVM, maka otomatis mereka juga sudah ikut, jadi bisa kita skip.

Untuk `cpplint`, kita harus mengisntallnya lagi dengan menggunakan scoop. Sayangnya, Scoop belum punya `cpplint` langsung di bucket utamanya. Tapi kita bisa install manual lewat `pip`, lalu integrasikan dengan Scoop path.

```bash
scoop install python
pip install cpplint
```

Cek versi `cpplint` dengan mengetikan perintah berikut. Jika versinya muncul seperti output dibawah, maka artinya pemasangan `cpplint` berhasil:

```bash
PS C:\Users\ASUS> cpplint --version
Cpplint fork (https://github.com/cpplint/cpplint)
cpplint 2.0.2
Python 3.13.5 (tags/v3.13.5:6cb20a2, Jun 11 2025, 16:15:46) [MSC v.1943 64 bit (AMD64)]
```

> `cpplint` sebenarnya opsional, karena saat kita menginstall LLVM, terdapat `clang-tidy` yang memiliki fungsi yang sama, namun lebih modern dan powerfull daripada `cpplint`! Konfigurasi dari plugins linter ini akan dibahas di bagian setting dan konfigurasi.

Untuk `codelldb`, jika sebelumnya belum terinstall, maka masukan perintah berikut di neovim command:

```bash
:MasonInstall codelldb
```

Jika difolder berikut sudah ada `codelldb.exe`, maka artinya kita sudah berhasil menginstallnya:

```bash
C:\Users\ASUS\AppData\Local\nvim-data\mason\packages\codelldb\extension\adapter
```

Atau jika sudah muncul tampilan seperti ini, artinya kita sudah berhasil menginstal semuanya:

![[Screenshot 2025-07-25 182917.png]]


## 4.4 | Pemasangan Makefile
Makefile adalah sebuah file teks yang berisi aturan dan instruksi untuk _mengotomatisasi proses build_ dalam sebuah proyek—terutama pada proyek pemrograman seperti C, C++, dan lainnya. File ini digunakan oleh tool bernama `make`.

Tujuan utamanya adalah untuk:

- Menyederhanakan proses kompilasi program.
- Menghindari kompilasi ulang yang tidak perlu.
- Mengelola dependensi antar file (misalnya antara header `.h` dan source `.cpp`).
- Menjalankan perintah build tertentu dengan cepat (seperti `make run`, `make clean`, dll).

Kalau kamu sedang mengerjakan proyek C++ misalnya, Makefile sangat berguna untuk menghindari compile manual berkali-kali. 

### Instalasi Makefile
Untuk bisa menginstal Makefile, caranya cukup mudah. Karena mencari situs resminya cukup membingungnkan, jadi kita langsung saja menggunakan scoop, dengan cara memasukan perintah berikut:

```bash
scoop install make
```

Tunggu hingga proses selesai. Setelah itu coba masukan perintah berikut:

```bash
make --version
```

Jika muncul output seperti berikut, artinya pemasangan kita berhasil:

```bash
GNU Make 4.4.1
Built for Windows32
Copyright (C) 1988-2023 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
```


---
<br/>

# Setting Plugins Untuk C++ Workflow
Setelah plugins untuk C++ di neovim terpasang, saatnya kita setting plugin dasar ini, sebelum setting customs plugin-plugin ini, ada informasi lagi yang perlu kamu tahu:

Pada saat pertama kali pasang LazyVim, didalam folder plugins, terdapat file yang bernama `example.lua`. Ini adalah contoh bagaimana memanggil dan mengkonfigurasi plugins yang kita pasang. Tapi, agar lebih modular dan lebih rapi, kita akan membuatnya terpisah-pisah antar file, tidak menumpuk disatu file. Lagipula `example.lua` hanyalah contoh, kita bisa membuat penataan file kita sendiri. Untuk itu, file masing-masing plugins akan dibuat terpisah-pisah, asalkan tetap didalam folder `plugins`.

---
<br/>

## 5.1 | Setting clang-format

> `clang-format` adalah alat untuk memformat kode sumber C, C++, Objective-C, Java, JavaScript, dan beberapa bahasa lain sesuai dengan gaya tertentu secara otomatis. Alat ini juga berasal dari proyek LLVM dan digunakan untuk menjaga konsistensi penulisan kode, baik dalam proyek kecil maupun besar. 
> 
> Kamu bisa mengatur gaya format menggunakan file `.clang-format` di root folder proyek, atau menggunakan gaya bawaan seperti `LLVM`, `Google`, `Mozilla`, `WebKit`, `Microsoft`, dan lainnya. Setelah dikonfigurasi, `clang-format` akan menata ulang spasi, indentasi, penempatan tanda kurung, dan elemen sintaksis lainnya agar sesuai dengan gaya tersebut.

Bersihkan semua konfigurasi dari file `example.lua`, yang membahas `"stevearc/conform.nvim"`. Supaya pemisahan antar file berjalan lancar.


Lalu, buat file baru didalam folder `plugins`, misal `stevearc-conform.lua` , lalu pasang kode berikut:

```lua
-- lua/plugins/stevearc-conform.lua
return {
  {
    "stevearc/conform.nvim",
    opts = {
      formatters_by_ft = {
        lua = { "stylua" },
        python = { "isort", "black" },
        rust = { "rustfmt" },
        javascript = { "prettierd", "prettier" },
        cpp = { "clang-format" },
        c = { "clang-format" },
        h = { "clang-format" },
      },
    },
    enabled = true,
  }
}
```

Nah, disini hanya ada 3 penambahan saja, yaitu:

```lua
cpp = { "clang-format" },
c = { "clang-format" },
h = { "clang-format" },
```

Selain 3 baris diatas, sudah disetting dari  `example.lua`, sehingga tidak terlalu banyak perubahan yang dilakukan disini.

Jika sudah, save, dan restart kembali neovim. Lalu buka file C++ manapun, lalu masuk ke mode command, dan ketik `:ConformInfo`, maka akan muncul tampilan seperti ini:

![[README-14.png]]

Hal yang perlu kita perhatikan adalah pada bagian `Formatter for this buffer`, artinya adalah format yang aktif pada file yang sedang kita buka saat ini. Karena file yang sedang kita buka saat ini adalah file C++, maka akan ada keterangan seperti ini:

```bash
Formatters for this buffer:
LSP: clangd
clang-format ready (h, cpp, c) C:\Users\ASUS\AppData\Local\nvim-data\mason\bin\clang-format.CMD
```

Jika ada tulisan `ready`, artinya formatter kita berhasil terpasang. Selain itu juga terlihat bahwa LSP kita yaitu clangd juga tampak aktif disini 😊.

Sekarang, untuk lebih memastikanya lagi, cobalah untuk menulis kode program C++ secara acak, tidak beraturan, tetapi tidak error. Misal seperti ini:

![[README-15.png]]

Dann..., ketika kita simpan, misal dengan command `:w` atau *Ctrl + s*, maka formatter akan bekerja dengan cara merapikan kode yang kita buat menjadi seperti ini:

![[README-16.png]]

Nahh, jika tidak ada pesan error, maka formatter kita sudah berhasil terpasang dengan baik 😊.

### Mengganti Style Formatter

Ohh ya, apakah konfigurasi dari formatter ini bisa kita ubah? Misal dengan menggunakan gaya yang lain? Jawabanya adalah bisa ✅! Formatter sebelumnya sebenarnya bekerja dengan menggunakan settingan default.

Untuk clang-format sendiri, ada dokumentasi resmi dan lengkap bagiamana cara mensetting sendiri format penulisan kita mau seperti apa, bisa dikunjungi di [Clang-Format Style Options](https://clang.llvm.org/docs/ClangFormatStyleOptions.html). 

![[README-17.png]]

Lalu bagaimana cara settingnya? Caranya adalah membuat file bernama `.clang-format`, yang diletakan di *root folder* kita. Penulisan nama file ini harus sama!

Lalu setelah itu, kita bisa isi dengan konfigurasi yang kita mau, misal seperti ini: 

```yaml
# Based on Google style, but can be customized further
BasedOnStyle: Google

# Example of some common customizations you might want to add (optional):
TabWidth: 4
IndentWidth: 3
ColumnLimit: 120
AlwaysBreakBeforeMultilineStrings: true
BreakBeforeBraces: Attach
AllowShortIfStatementsOnASingleLine: false
PointerAlignment: Left
```

Lalu bagaimana jika kita tidak membuat konfigurasi seperti diatas? Formatter akan tetap bekerja, namun dengan menggunakan format default, yaitu format `llvm`.

Gaya formatting sendiri sebenarnya ada banyak, jika melihat contoh konfigurasi diatas, kita menggunakan `BasedOnStyle: Google`, artinya kita menggunakan formatter dengan gaya Google. Jika ingin menggunakan gaya yang lain, kita bisa memilih gaya-gaya berikut:

|Style Name|Deskripsi|
|---|---|
|`LLVM`|Default. Gaya standar LLVM (indent 2 spasi, max line 80).|
|`Google`|Gaya coding standar Google (indent 2 spasi, sangat rapi).|
|`Chromium`|Gaya standar untuk proyek Chromium (indent 2 spasi, mirip Google).|
|`Mozilla`|Gaya proyek Mozilla (indent 2 spasi, agak lebih longgar).|
|`WebKit`|Gaya WebKit (indent 4 spasi, mirip style Apple).|
|`Microsoft`|Gaya Microsoft (indent 4 spasi, mirip Visual Studio C++).|
|`GNU`|Gaya GNU (indent 2 spasi, bracket di bawah, mirip gaya lama).|
|`InheritParentConfig`|Gunakan file `.clang-format` di parent folder jika ada.|
|`File`|Baca langsung dari file `.clang-format` atau `_clang-format`.|


Kita juga bisa mengatur gaya formatter dengan menggunakan konfigurasi neovim kita, misal dengan menambahkan syntax ini di file `stevearc-conform.lua` yang sebelumnya kita buat:

```lua
formatters = {
  clang_format = {
    prepend_args = { "--style=Google" },
  },
}
```

Kedua cara diatas bisa digunakan. Namun, jika kita mengaktifkan kedua cara diatas, formatter yang akan bekerja adalah yang berasal dari `.clang-format`, karena lebih diprioritaskan pada sistem. 

### Formatter untuk bahasa lain
Semisal kamu ingin menggunakan bahasa lain, dan membutuhkan formatter yang berbeda, maka kamu bisa mengecek daftar formatter yang tersedia di repository yang menyediakan plugins conform, yaitu [stevearc/conform.nvim](https://github.com/stevearc/conform.nvim/tree/master/lua/conform/formatters). 

![[README-18.png]]

Contoh formatter untuk bahasa lain:

| Bahasa   | Formatter                            | Catatan                                |
| -------- | ------------------------------------ | -------------------------------------- |
| PHP      | `php_cs_fixer`                       | Perlu `php-cs-fixer` diinstal          |
| Go       | `gofmt`, `goimports`                 | Gunakan salah satu atau gabungkan      |
| Java     | `google-java-format`, `clang-format` | Instal manual, bukan via Mason         |
| JSON     | `prettier`, `jq`                     | `jq` cepat, `prettier` lebih fleksibel |
| YAML     | `prettier`                           | Perlu `prettier` terinstal             |
| Markdown | `prettier`                           | Umum dipakai di proyek JS              |
⚠️ Yang penting:

- Pastikan formatter-nya **sudah terinstal** (baik lewat Mason atau sistem langsung).
- Gunakan `:Mason` → cari formatter, atau instal manual jika tidak tersedia.
- Gunakan `:ConformInfo` untuk melihat formatter yang aktif untuk file saat ini.

---
<br/>

## 5.2 | Setting clangd
> `clangd` adalah Language Server Protocol (LSP) untuk bahasa pemrograman C, C++, dan Objective-C yang disediakan oleh proyek LLVM. Ia memberikan fitur seperti auto-completion, go to definition, linting, hover info, dan refactoring secara real-time saat menulis kode. 
> 
> `clangd` bekerja dengan membaca dan menganalisis kode melalui database kompilasi (`compile_commands.json`) yang dihasilkan dari sistem build seperti CMake. Ini membuat `clangd` sangat efisien dan akurat dalam memahami struktur kode C/C++ yang kompleks. Biasanya digunakan di editor seperti Neovim atau VSCode untuk pengalaman pengembangan yang lebih cerdas dan produktif.

Clangd membutuhkan LSP untuk berjalan, dan LSP bisa didapat jika kita memasang plugins tertentu, yang untungya sudah tersedia langsung ketika kita memasang LazyVim.

LSP (Language Server Protocol) di LazyVim didapat dari plugin bawaan bernama: `neovim/nvim-lspconfig`

Plugin ini adalah komponen inti dalam LazyVim untuk mengatur dan menjalankan LSP.  
Namun, LazyVim juga menyertakan beberapa plugin tambahan yang melengkapi pengalaman LSP, di antaranya:

|Plugin|Fungsi|
|---|---|
|`neovim/nvim-lspconfig`|Mengatur dan mengaktifkan LSP secara manual atau otomatis. Ini yang utama.|
|`williamboman/mason.nvim`|UI installer untuk LSP, DAP, formatter, linter, dsb.|
|`williamboman/mason-lspconfig.nvim`|Menjembatani antara Mason dan nvim-lspconfig agar integrasi otomatis.|
|`hrsh7th/nvim-cmp`|Auto-completion framework, sering dipakai bersama LSP.|
|`hrsh7th/cmp-nvim-lsp`|Menghubungkan LSP dengan `nvim-cmp` agar bisa menampilkan saran dari LSP.|
Jadi Kesimpulannya:

LSP di LazyVim terutama disediakan oleh `nvim-lspconfig`, diinstal otomatis oleh LazyVim Starter, dan dikonfigurasi di file:

```bash
~/.config/nvim/lua/plugins/lsp.lua
```

Jadi kita tidak perlu tambah sendiri, cukup aktifkan Mason dan pasang server yang dibutuhkan (seperti `clangd`, `pyright`, dll), maka semuanya siap jalan.

### Pengaktifan clangd
Untuk mengaktifkan LSP agar bekerja dengan clangd, kita buat file baru di folder `plugins`, mungkin bernama `lsp-configuration.lua`, lalu kita isi dengan kode berikut:

```lua
return {
  {
    "neovim/nvim-lspconfig",
    opts = {
      servers = {
        clangd = {
          filetypes = { "c", "cpp", "objc", "objcpp" },
          -- kamu bisa tambahkan opsi lain di sini
        },
      },
    },
  },
}
```

Save, lalu restart neovim kita. Lalu masuk ke file C++, lalu semisal kita menulis program yang salah, seperti ini:

![[README-20.png]]

Kode diatas memiliki banyak kesalaha, terutama ketika menggunakan variabel pada perulangan for-each. Ketika kita save, dengan `:w` atau *Ctrl + s*, maka akan muncul peringatan kesalahan, seperti berikut:

![[README-21.png]]

Nahh, ini artinya konfigurasi clangd kita berhasil terpasang dengan baik 😁.

---
<br/>

## 5.3 | Setting Auto-LSP
> `auto-lsp.nvim` adalah plugin Neovim yang dirancang untuk menyederhanakan setup Language Server Protocol (LSP). Dengan plugin ini, pengguna tidak perlu lagi menulis konfigurasi manual untuk setiap bahasa pemrograman. 
> 
> Saat kamu membuka file dengan bahasa tertentu, seperti C++ atau Python, `auto-lsp` akan secara otomatis mendeteksi bahasa tersebut, menginstall server LSP yang sesuai menggunakan `mason.nvim` (jika belum ada), lalu mengaktifkannya melalui `nvim-lspconfig`. 
> 
> Hal ini membuat fitur seperti diagnostic, go to definition, hover, dan lainnya langsung siap digunakan tanpa konfigurasi tambahan. Plugin ini sangat cocok untuk pengguna yang sering berpindah-pindah bahasa atau ingin setup LSP yang praktis dan cepat, termasuk untuk kebutuhan seperti competitive programming.

Kalau kita perhatikan dengan seksama, clangd hanya bekerja ketika kita melakukan save. Jadi saat kita menulis program yang salah, dan belum kita save karena terlalu sibuk menulis hingga kebawah, maka kode yang salah tersebut baru akan ketahuan ketika kita baru save. 

Jika ingin pesan kesahan muncul langsung ketika kita membuat kesalahan, maka kita perlu melakukan konfigurasi lagi.

Kita perlu plugins dari `auto-lsp.nvim`, yang berasal dari repository [WieeRd/auto-lsp.nvim](https://github.com/WieeRd/auto-lsp.nvim). Buat file baru di folder plugins, beri nama misal `WieeRd-auto-lsp.lua`, lalu masukan kode berikut:

```lua
return {
  {
    "WieeRd/auto-lsp.nvim",
    dependencies = { "neovim/nvim-lspconfig" },
    event = "VeryLazy",
    opts = {},
    config = function()
      -- Aktifkan update diagnostic saat mengetik
      vim.diagnostic.config({
        update_in_insert = true,
        virtual_text = true,
        signs = true,
        underline = true,
      })
    end,
  },
}
```

Save, restart neovim. 

Sekarang cobalah mengetik sambil melakukan kesalahan ketika menulis kode. Jika konfigurasi berhasil, maka hasilnya adalah seperti ini:

![[20250725-1050-07.2863843.mp4]]Bisa kamu lihat, ketika aku melakukan kesahalah sintaksis, maka clangd akan langsung keluar, tanpa kita harus save file terlebih dahulu 😀. Jika hasilmu juga seperti ini, artinya konfigurasi auto-lsp mu berhasil!

---
<br/>

## 5.4 | Setting cpplint / clangtidy

Clang-Tidy dan cpplint adalah dua alat yang digunakan untuk analisis statis kode C dan C++ guna meningkatkan kualitas, konsistensi, dan keamanan kode. Meskipun keduanya memiliki tujuan serupa, pendekatan dan fitur yang ditawarkan berbeda secara signifikan.

Clang-Tidy adalah bagian dari ekosistem LLVM dan berfungsi sebagai _linter_ serta tool refactoring modern untuk kode C++. Alat ini dibangun di atas `libclang` dan mendukung parsing lengkap terhadap kode, memungkinkan analisis yang lebih dalam serta akurat. Clang-Tidy menawarkan berbagai pemeriksaan, termasuk:

- Pengecekan gaya penulisan kode (style checks)
    
- Identifikasi bug potensial dan _undefined behavior_
    
- Optimalisasi performa dan deteksi kode yang tidak efisien
    
- Refactoring otomatis (misalnya: mengganti idiom lama dengan yang lebih modern)
    
- Integrasi dengan standar coding populer seperti Google, LLVM, dan Mozilla
    

Clang-Tidy sangat fleksibel dan dapat dikonfigurasi melalui file `.clang-tidy`, yang memungkinkan pengembang untuk mengaktifkan atau menonaktifkan aturan tertentu, serta menyetel parameter khusus sesuai kebutuhan proyek.

Sementara itu, cpplint adalah alat linting yang dikembangkan oleh Google untuk memastikan kepatuhan terhadap pedoman gaya penulisan kode C++ Google. Alat ini ditulis dalam Python dan berfokus hampir sepenuhnya pada pemeriksaan gaya dan konvensi kode, seperti:

- Penempatan dan penamaan file
    
- Format penulisan komentar
    
- Penggunaan spasi, indentasi, dan panjang baris
    
- Struktur header dan include guards
    

cpplint lebih ringan dan mudah digunakan, namun kemampuannya terbatas dibandingkan Clang-Tidy karena tidak melakukan parsing penuh terhadap kode, sehingga tidak mampu menangkap bug logis atau _undefined behavior_.

### Mana yang lebih baik?
Secara umum, Clang-Tidy lebih unggul dalam hal cakupan fitur, akurasi analisis, dan skalabilitas terhadap proyek C++ modern. Namun, cpplint tetap berguna untuk memastikan konsistensi gaya penulisan pada proyek yang mengikuti panduan Google Style.

Kesimpulan:

- Gunakan Clang-Tidy jika fokus pada kualitas kode secara menyeluruh, refactoring, dan analisis yang lebih dalam.
    
- Gunakan cpplint jika hanya ingin menjaga konsistensi gaya penulisan, terutama sesuai standar Google.
    
- Dalam praktik terbaik, keduanya dapat digunakan secara bersamaan: cpplint untuk gaya penulisan, dan Clang-Tidy untuk analisis teknis kode.

Untuk kebutuhan _competitive programming_, **Clang-Tidy** adalah pilihan yang lebih tepat dibandingkan cpplint. Berikut alasannya secara profesional:

1. **Fokus pada Kualitas dan Potensi Bug**  
    Dalam kompetisi pemrograman, kecepatan debugging dan keakuratan solusi sangat penting. Clang-Tidy dapat membantu mengidentifikasi:
    
    - Bug tersembunyi seperti _uninitialized variables_, _undefined behavior_, dan penggunaan yang tidak efisien.
        
    - Potensi kesalahan logika yang tidak akan terdeteksi oleh cpplint.
        
2. **Efisiensi dan Modernisasi Kode**  
    Clang-Tidy mendorong penggunaan fitur-fitur modern C++ (misalnya `auto`, `range-based for`, `smart pointers`, dsb), yang bisa mempercepat penulisan kode dan mengurangi kemungkinan kesalahan.
    
3. **Tidak Fokus pada Gaya Penulisan yang Ketat**  
    Dalam kompetisi, gaya penulisan bukan prioritas. cpplint justru terlalu ketat soal format, seperti panjang baris, indentasi, dan nama variabel. Ini bisa mengganggu alur kerja saat berpacu dengan waktu.
    
4. **Lebih Relevan dengan Compiler Modern**  
    Karena Clang-Tidy dibangun di atas _compiler engine_ Clang, ia memberi peringatan dan analisis yang relevan dengan compiler modern—mendekati apa yang akan terjadi saat _compile and run_, sehingga lebih kontekstual untuk lingkungan kompetitif.
    

**Kesimpulan:**  
Untuk _competitive programming_, gunakan **Clang-Tidy** karena ia memberikan manfaat langsung terhadap kecepatan debugging dan stabilitas kode. cpplint tidak diperlukan, karena tidak memberikan nilai tambah yang signifikan dalam konteks kompetisi.

### Pemilihan
Karena tujuan kita adalah membuat setup untuk competitive programming, maka kita akan memilih menggunakan clang-tidy daripada cpplint 😀.

### Pemasangan dan aktivasi Clang-tidy
Sebelum mulai mengaktifkan salah satu dari konfigurasi ini, cek lagi apakah mereka sudah terpasang dengan benar pada komputer kita. Untuk cpplint, maka pastikan, ketika kita memasukan perintah berikut di terminal:

```bash
cpplint --version
```

Outputnya adalah sebagai berikut:

```bash
Cpplint fork (https://github.com/cpplint/cpplint)
cpplint 2.0.2
Python 3.13.5 (tags/v3.13.5:6cb20a2, Jun 11 2025, 16:15:46) [MSC v.1943 64 bit (AMD64)]
```

Tapi jika kita menggunakan Clang-tidy, yang cocok untuk penggunaan kasus kita, maka pastikan  ketika kita memasukan perintah berikut pada terminal:

```bash
clang-tidy --version
```

Hasilnya adalah seperti ini:

```bash
LLVM (http://llvm.org/):
  LLVM version 18.1.7
  Optimized build.
```

Jika yang keluar sesuai dengan yang diatas, maka kita bisa lanjut kebawah.

Untuk mengaktifkan Clang-tidy, kita bisa merubah konfigurasi dari file `nvim-lspconfig.lua`, dengan melakukan perubahan berikut:

Sebelumnya:

```lua
return {
  {
    "neovim/nvim-lspconfig",
    opts = {
      servers = {
        clangd = {
          filetypes = { "c", "cpp", "objc", "objcpp" },
        },
      },
    },
  },
}
```

Kita tambahkan satu perintah lagi, menjad seperti ini:

```lua
return {
  {
    "neovim/nvim-lspconfig",
    opts = {
      servers = {
        clangd = {
          cmd = {"clangd", "--clang-tidy"},   -- tambhakan ini!
          filetypes = { "c", "cpp", "objc", "objcpp" },
        },
      },
    },
  },
}
```

Properti `cmd` pada konfigurasi LSP (`clangd` dalam hal ini) di Neovim digunakan untuk **menentukan perintah dan argumen yang dijalankan saat Language Server dijalankan**. Ini memberi kontrol penuh kepada pengguna atas bagaimana server LSP diinisialisasi oleh Neovim.

Secara spesifik:

```lua
cmd = {"clangd", "--clang-tidy"}
```

berarti Neovim akan menjalankan perintah berikut saat membuka file C/C++:

```
clangd --clang-tidy
```

**Penjelasan fungsional:**

- `"clangd"` adalah nama executable dari _Language Server_ untuk C/C++.
    
- `"--clang-tidy"` adalah argumen opsional yang mengaktifkan integrasi dengan _Clang-Tidy_ selama proses linting dan analisis kode.
    

Dengan kata lain, properti `cmd` menentukan **apa yang dieksekusi saat LSP aktif**, bukan hanya nama binary-nya, tetapi juga _flags_ atau konfigurasi tambahan yang dibutuhkan. Jika properti `cmd` tidak disetel, maka Neovim akan menggunakan perintah default (biasanya hanya `"clangd"` tanpa argumen).

**Penting untuk dokumentasi:**  
Penggunaan `cmd = {"clangd", "--clang-tidy"}` akan mengaktifkan fitur _linting dan analisis statis lanjutan_ dari Clang-Tidy secara otomatis saat pengguna sedang menulis kode di Neovim. Tanpa baris ini, `clangd` tidak akan menjalankan pemeriksaan Clang-Tidy secara default.

> Jika ingin melihat dokumentasi yang lebih resmi, gunakan panduan dari situs [LazyVim/extras/lang/Clangd](https://www.lazyvim.org/extras/lang/clangd), yang sudah lengkap membahas semua konfigurasi. 
> 
> Intinya, jika ada yang bingung, langsung saja masuk ke dokumentasi ini, semuanya sudah ada! 
> 
> Terakhir. ***JANGAN SETUP DENGAN AI !***
> 
> Konfigurasi yang perlu dilakukan tidak terlalu rumit. Justru AI akan membuatnya tampak rumit, atau bahkan terlalu rumit (entah kenapa), sehingga membuat neovim kamu akan banyak mengalami error yang sulit diperbaiki kedepanya. 
> 
> Lebih baik setup perlahan dengan panduan dokumentasi! Ini akan menghemat puluhan jam waktumu dari memperbaiki bug yang tidak berkesudahan 😭 (pengalaman sendiri).

### Konfigurasi file `.clang-tidy`

Nah, setelah kita mengedit file diatas, kita juga perlu membuat file baru. File baru ini kita letakan di *root folder*, dan beri nama dengan `.clang-tidy`, penulisan nama file harus sesuai!

File `.clang-tidy` ini bekerja sebagaimana file `.clang-format` bekerja. Dia akan menyimpan konfigurasi yang dibutuhkan user ketika menggunakan `.clang-tidy`. Untuk bisa mengkonfigurasi file ini, kita bisa menggunakan panduan dari [Clang-Tidy-documentation](https://clang.llvm.org/extra/clang-tidy/):

![[README-22.png]]

Jika file `.clang-format` tidak ada, maka hal itu masih aman karena terdapat default setting yang akan aktif. Formatter akan tetap bekerja dengan menggunakan gaya LLVM, sehingga pembuatan file `.clang-format` bersifat opsional, walaupun akan lebih baik jika kita membuatnya.

Namun, jika tidak ada file `.clang-tidy`, maka kita akan secara otomatis menggunakan default settingnya. Clang-Tidy akan tetap berjalan, tetapi hanya menjalankan pemeriksaan _default_ tertentu, yang *jumlahnya sangat terbatas.*

Ini adalah akibat dari tidak adanya file `.clang-tidy`:

- Banyak pemeriksaan penting tidak akan aktif, karena sebagian besar pemeriksaan (seperti `modernize-*`, `performance-*`, `bugprone-*`) hanya aktif jika **dinyatakan eksplisit** dalam file konfigurasi.

- Tidak ada pengaturan khusus seperti pengecualian file, konfigurasi header, atau pengecualian warning yang bisa ditentukan tanpa file `.clang-tidy`.

Tanpa file `.clang-tidy`, pemasangan clang-tidy seperti tidak ada dampaknya, sehingga sangat penting untuk membuat dan mengkonfigurasi file ini.

Ini adalah konfigurasi minimal yang bisa ditaruh didalam file `.clang-tidy`:

```yaml
Checks: '-*,bugprone-*,performance-*,modernize-*'
WarningsAsErrors: ''
HeaderFilterRegex: '.*'
FormatStyle: file
```

Atau, jika tidak ingin terlalu berisik, maka bisa dibuat seperti ini:

```yaml
Checks: 'clang-analyzer-*,modernize-*,performance-*'
WarningsAsErrors: '*'
```

Ini adalah konfigurasi yang aku gunakan, penjelasanya adalah seperti ini:

#### Konfigurasi Pertama
Baris pertama, yaitu `Checks: 'clang-analyzer-*,modernize-*,performance-*'`, akan mengaktifkan tiga grup pemeriksaan besar:

- **`clang-analyzer-*`**: Pemeriksaan dari _Clang Static Analyzer_, mendeteksi bug seperti null pointer dereference, memory leak, dan undefined behavior.
    
- **`modernize-*`**: Mendorong penggunaan fitur C++ modern, seperti `auto`, `nullptr`, `override`, `range-based for`, dll.
    
- **`performance-*`**: Mendeteksi pola kode yang bisa dioptimalkan dari sisi performa, misalnya penggunaan `std::move`, penghindaran salinan mahal, dll.
    

→ Ini sudah mencakup aspek _keamanan, gaya modern, dan performa_, sangat cocok untuk praktik pemrograman kompetitif maupun pengembangan profesional.

#### Konfigurasi Kedua
Baris kedua, yaitu `WarningsAsErrors: '*'`, akan:

Artinya **semua peringatan dianggap sebagai error**, sehingga kode yang tidak lolos pemeriksaan tidak akan "diabaikan".

→ Ini membuat standar lebih ketat dan memaksa perbaikan segera terhadap setiap potensi masalah.

#### Perbandingan dengan konfigurasi lain

Jika kamu punya konfigurasi seperti:

```yaml
Checks: '-*,bugprone-*'
```

atau

```yaml
Checks: '*'
```

Maka:

- `'-*,bugprone-*'` hanya mengaktifkan satu grup.
    
- `'*'` memang terdengar lengkap, tetapi bisa sangat **berisik** dan berpotensi menghasilkan false positive karena mencakup semua checker, termasuk yang sangat ketat atau tidak relevan.

#### Kesimpulan
Dari beberapa konfigurasi diatas, maka diambil pilihan yang ini saja:

```yaml
Checks: 'clang-analyzer-*,modernize-*,performance-*'
WarningsAsErrors: '*'
```

Yang mana konfigurasi diatas adalah pilihan yang kuat, seimbang, dan lengkap, tanpa terlalu berisik. Ini adalah konfigurasi yang sangat direkomendasikan untuk memastikan kode bersih, efisien, dan modern.

### Testing
Nah setelah mengikuti pemasangan diatas, jika semisal kita belum mengkonfigurasi Clang-tidy kita, maka program berikut ini terkesan baik, dan tanpa error:

![[README-23.png]]

Namun, ketika kita memasang Clang-tidy, dan mengkonfigurasi file `.clang-tidy`, maka nampak jelas, apa saja yang kurang dari kode yang kita anggap sudah benar:

![[README-24.png]]

Ternyata, ada banyak sekali penulisan program kita yang masih kurang dari sempurna. Gambar diatas menunjukan bahwa kita tidak seharusnya menggunakan `endl;` untuk pindah baris, melainkan seharusnya menggunakan `'\n'`.

Nah, jika programmu sudah menampilkan hal seperti diatas, maka selamat! Kamu berhasil mengaktifkan Clang-tidy 😁!

### Code action pada Clang-tidy
Apakah kita memasang Clang-tidy hanya untuk melihat pesan perbaikan yang menyebalkan saja? Seperti diatas?

Jawabanya adalah tidak, dengan penambahan beberapa konfigurasi, kita bisa membuat Clang-tidy kita menjadi lebih powerfull. Dimana setiap ada kode yang bisa ditingkatkan, Clang-tidy tidak hanya akan memberikan saran perbaikan, melainkan akan melakukan pekerjaan perbaikan tersebut untuk kita 😀.

Hal ini sangat disarankan, karena dengan mengikut peningkatan dari Clang-tidy, kode kita menjadi lebih bersih, aman, dan efektif. Yang paling utama tentu membuat kode kita lebih efisien dan lebih optimal.

Semisal kita memliki kode seperti ini, yang mana terdapat pesan dari Clang-tidy, bahwa ada dua penulisan kode program yang bisa diperbaiki:

![[README-25.png]]

Nah, kode diatas masih bisa ditingkatkan berdasarkan saran dari Clang-tidy. Supaya peningkatkan tersebut dikerkan oleh Clang-tidy, sehingga kita tidak perlu repot-repot melakukanya manual, kita bisa mengedit lagi konfigurasi file `nvim-lspconfig.lua`, dengan menambahkan value pada `cmd`, yaitu `--enable-config`, dan `--header-insertion=never`. Sehingga isi dari `nvim-lspconfig.lua` kita akan menjadi seperti ini:

```lua
return {
  {
    "neovim/nvim-lspconfig",
    opts = {
      servers = {
        clangd = {
          cmd = {
            "clangd", 
            "--clang-tidy",
            "--enable-config", -- baca file .clang-tidy
            "--header-insertion=never", -- masukan ini juga
          },
          filetypes = { "c", "cpp", "objc", "objcpp" },
        },
      },
    },
  },
}
```

Nah, dengan cara ini, maka Clang-tidy kita bisa melakukan auto correct untuk program kita secara langsung. 

Caranya adalah dengan berada dibaris yang terdapat pesan peringatan dari Clang-tidy, lalu tekan `<leader>ca`, atau jika belum paham istilah keymaps di neovim 😂, maksudnya adalah tombol utama (*defaultnya spasi*) + *c* + *a*. Demonya seperti ini:

![[20250725-1452-18.6399733.mp4]]

Lihat, sekarang Clang-tidy juga ikut bekerja membantu pekerjaan kita, tidak hanya memberikan peringatan dan saran saja 😁. 

---
<br/>

## 5.5 Setting codelldb
Nah, ini adalah bagian yang akan sangat panjang untuk diikuti, yaitu memasang debugger untuk C++ kita di neovim. Untuk bisa memasang debugger untuk neovim kita, terutama untuk lingkungan bahasa C++, prosesnya lumayan panjang, karena dari LazyVim sendiri, fitur debugger tidak secara default disediakan.

### Plugins yang perlu disiapkan

Ada 3 plugins utama yang perlu kita siapkan untuk bisa memasang debugger di neovim.

Berikut adalah deskripsi dan kegunaan dari **tiga plugin utama** yang kamu butuhkan untuk debugging di Neovim dengan bahasa C++.

#### 1 | `mfussenegger/nvim-dap` – Core Debug Adapter Protocol

Plugins ini berasal dari repo github [mfussenegger/nvim-dap](https://github.com/mfussenegger/nvim-dap):

![[README-26.png]]

Plugin ini adalah inti dari sistem debugging di Neovim yang mendukung _Debug Adapter Protocol_ (DAP). DAP merupakan standar komunikasi antara editor dan debugger eksternal, seperti LLDB, GDB, atau lainnya. `nvim-dap` tidak bergantung pada bahasa tertentu, sehingga bisa digunakan untuk berbagai bahasa seperti C++, Go, Python, Rust, dsb.

**Kegunaan utama:**

- Menyediakan fungsi dasar debugging seperti:
    
    - Menjalankan atau melanjutkan eksekusi program (`continue`)
        
    - Memasang dan menghapus _breakpoint_
        
    - Melakukan _step into_, _step over_, dan _step out_
        
    - Melampirkan ke proses yang sedang berjalan (_attach to process_)
        
- Mendukung integrasi dengan UI eksternal atau virtual text.
    

Plugin ini menjadi pondasi bagi semua fitur debugging lain yang akan digunakan.

---

#### 2 | `rcarriga/nvim-dap-ui` – Antarmuka Visual untuk Debugging

Plugins ini berasal dari repo github [rcarriga/nvim-dap-ui](https://github.com/rcarriga/nvim-dap-ui):

![[README-27.png]]

Plugin ini adalah antarmuka pengguna berbasis Neovim yang dirancang untuk bekerja di atas `nvim-dap`. Tujuannya adalah membuat proses debugging menjadi lebih visual dan mudah dinavigasi.

**Kegunaan utama:**

- Menampilkan:
    
    - Breakpoint
        
    - Nilai variabel saat ini (scopes)
        
    - Stack trace
        
    - Call frames
        
    - Log debug dan output REPL
        
- Otomatis membuka dan menutup jendela UI saat debugging dimulai atau selesai.
    
- Terintegrasi erat dengan keymaps dan pengalaman interaktif Neovim.
    

Dengan `dap-ui`, kamu tidak perlu mengetik perintah secara manual untuk melihat informasi runtime.

---

#### 3 | `nvim-neotest/nvim-nio` – Backend Asinkron untuk UI DAP

Plugins ini berasal dari repo github [nvim-neotest/nvim-nio](https://github.com/nvim-neotest/nvim-nio):

![[README-28.png]]

Plugin ini merupakan dependensi teknis yang wajib ketika menggunakan `nvim-dap-ui`. Fungsinya adalah menyediakan fitur asinkron (non-blocking IO) berbasis coroutine dan event loop, yang dibutuhkan agar `dap-ui` dapat bekerja secara mulus tanpa membekukan editor saat memproses data debugger.

**Kegunaan utama:**

- Menyediakan _async task scheduler_ untuk komunikasi antara DAP server dan `dap-ui`
    
- Digunakan secara internal oleh `nvim-dap-ui`, **tidak memiliki tampilan atau fungsi terpisah** bagi pengguna akhir
    

Walaupun tidak langsung terlihat kegunaannya, `nvim-nio` sangat penting agar interaksi UI dan event debugger dapat dijalankan dengan lancar dan responsif.

---

#### 🔚 Penutup

Ketiga plugin ini membentuk satu ekosistem debugging yang saling melengkapi:

- `nvim-dap`: fondasi dan mesin eksekusi debugging
    
- `nvim-dap-ui`: antarmuka yang mempermudah navigasi dan observasi status runtime
    
- `nvim-nio`: penghubung teknis yang memastikan performa UI tetap lancar
    

Kombinasi ketiganya memberikan pengalaman debugging kelas IDE langsung dari dalam Neovim.

### Setup Plugins
Untuk melakukan setup plugins, buat file baru didalam folder `plugins`, misal kita beri nama dengan `dap-codelldb.lua`, lalu kita masukan konfigurasi berikut:

```lua
-- daftar repo yang dibutuhkan:

-- /--------------------------------------------
    -- repo nvim-dap
    -- https://github.com/mfussenegger/nvim-dap

    -- repo UI debuggernya
    -- https://github.com/rcarriga/nvim-dap-ui

    -- repo bantuan untuk nvim-dap-ui
    -- https://github.com/nvim-neotest/nvim-nio
-- \--------------------------------------------

return {
  {
    "mfussenegger/nvim-dap",
    dependencies = {
      "rcarriga/nvim-dap-ui",
      "nvim-neotest/nvim-nio", -- WAJIB untuk dap-ui
    },
    config = function()
      local dap = require("dap")
      local dapui = require("dapui")

      -- Setup dap-ui
      dapui.setup()

      -- Auto open/close dapui
      dap.listeners.before.attach.dapui_config = function() dapui.open() end
      dap.listeners.before.launch.dapui_config = function() dapui.open() end
      dap.listeners.before.event_terminated.dapui_config = function() dapui.close() end
      dap.listeners.before.event_exited.dapui_config = function() dapui.close() end

      -- DAP keymaps
      vim.keymap.set("n", "<leader>dc", function() dap.continue() end, { desc = "Start/Continue Debugging" })
      vim.keymap.set("n", "<leader>db", function() dap.toggle_breakpoint() end, { desc = "Toggle Breakpoint" })
      vim.keymap.set("n", "<leader>dB", function()
        vim.ui.input({ prompt = "Breakpoint condition: " }, function(cond)
          if cond then dap.set_breakpoint(cond) end
        end)
      end, { desc = "Set Conditional Breakpoint" })
      vim.keymap.set("n", "<leader>di", function() dap.step_into() end, { desc = "Step Into" })
      vim.keymap.set("n", "<leader>do", function() dap.step_over() end, { desc = "Step Over" })
      vim.keymap.set("n", "<leader>dO", function() dap.step_out() end, { desc = "Step Out" })
      vim.keymap.set("n", "<leader>dr", function() dap.restart() end, { desc = "Restart Debug Session" })
      vim.keymap.set("n", "<leader>dx", function() dap.terminate() end, { desc = "Stop Debug Session" })
      vim.keymap.set("n", "<leader>du", function() dapui.toggle() end, { desc = "Toggle DAP UI" })

      -- === Setup DAP Adapter codelldb ===
      local mason_path = vim.fn.stdpath("data")
      local codelldb_path = mason_path .. "/mason/packages/codelldb/extension/adapter/codelldb"

      dap.adapters.codelldb = {
        type = "server",
        port = "${port}",
        executable = {
          command = codelldb_path,
          args = { "--port", "${port}" },
        },
      }

      -- Konfigurasi untuk C/C++
      local c_config = {
        {
          name = "Launch file",
          type = "codelldb",
          request = "launch",
          program = function()
            return vim.fn.input("Path to executable: ", vim.fn.getcwd() .. "/", "file")
          end,
          cwd = "${workspaceFolder}",
          stopOnEntry = false,
        },
        {
          name = "Attach to process",
          type = "codelldb",
          request = "attach",
          pid = require("dap.utils").pick_process,
          cwd = "${workspaceFolder}",
        },
      }

      dap.configurations.c = c_config
      dap.configurations.cpp = c_config
    end,
  }
}
```


Berikut penjelasan dokumentatif dari konfigurasi tersebut, dibagi berdasarkan asal plugin serta penjelasan masing-masing bagian kode. 

Penjelasan Konfigurasi Debugger Neovim:
### 📦 Plugin yang Digunakan

- [`mfussenegger/nvim-dap`](https://github.com/mfussenegger/nvim-dap): Plugin utama untuk debugging berbasis DAP (Debug Adapter Protocol).
    
- [`rcarriga/nvim-dap-ui`](https://github.com/rcarriga/nvim-dap-ui): Antarmuka pengguna untuk menampilkan informasi runtime saat debugging.
    
- [`nvim-neotest/nvim-nio`](https://github.com/nvim-neotest/nvim-nio): Plugin pendukung untuk dap-ui, menyediakan mekanisme async yang stabil.
    

### 🔍 1 | Konfigurasi dari Plugin `nvim-dap`

Plugin `nvim-dap` adalah inti dari sistem debugging, dan bagian-bagian berikut ini berasal dari fungsionalitas yang disediakan oleh plugin tersebut:

```lua
local dap = require("dap")
```

#### 📌 Keymaps Debugging (dari `nvim-dap`)

```lua
vim.keymap.set("n", "<leader>dc", function() dap.continue() end)
vim.keymap.set("n", "<leader>db", function() dap.toggle_breakpoint() end)
vim.keymap.set("n", "<leader>dB", function()
  vim.ui.input({ prompt = "Breakpoint condition: " }, function(cond)
    if cond then dap.set_breakpoint(cond) end
  end)
end)
vim.keymap.set("n", "<leader>di", function() dap.step_into() end)
vim.keymap.set("n", "<leader>do", function() dap.step_over() end)
vim.keymap.set("n", "<leader>dO", function() dap.step_out() end)
vim.keymap.set("n", "<leader>dr", function() dap.restart() end)
vim.keymap.set("n", "<leader>dx", function() dap.terminate() end)
```

> Ini adalah keymaps untuk berbagai aksi debugging seperti menjalankan, melangkah masuk/keluar, serta mengatur breakpoint.

#### 🧩 Setup Adapter `codelldb` (dari `nvim-dap`)

```lua
dap.adapters.codelldb = {
  type = "server",
  port = "${port}",
  executable = {
    command = codelldb_path,
    args = { "--port", "${port}" },
  },
}
```

> Mengatur adaptor LLDB khusus untuk bahasa C/C++ yang diinstal melalui `mason`.

#### 🧾 Konfigurasi Language (C/C++)

```lua
local c_config = {
  {
    name = "Launch file",
    type = "codelldb",
    request = "launch",
    program = function()
      return vim.fn.input("Path to executable: ", vim.fn.getcwd() .. "/", "file")
    end,
    cwd = "${workspaceFolder}",
    stopOnEntry = false,
  },
  {
    name = "Attach to process",
    type = "codelldb",
    request = "attach",
    pid = require("dap.utils").pick_process,
    cwd = "${workspaceFolder}",
  },
}

dap.configurations.c = c_config
dap.configurations.cpp = c_config
```

> Ini adalah konfigurasi debugging yang akan digunakan oleh file `.c` dan `.cpp`, baik untuk menjalankan program maupun menempel ke proses yang berjalan.

---

### 🎛️ 2 | Konfigurasi dari Plugin `nvim-dap-ui**`**

Plugin ini digunakan untuk menampilkan UI interaktif selama debugging:

```lua
local dapui = require("dapui")
dapui.setup()
```

#### 🔁 Integrasi UI Otomatis dengan Event `dap`

```lua
dap.listeners.before.attach.dapui_config = function() dapui.open() end
dap.listeners.before.launch.dapui_config = function() dapui.open() end
dap.listeners.before.event_terminated.dapui_config = function() dapui.close() end
dap.listeners.before.event_exited.dapui_config = function() dapui.close() end
```

> Fungsi-fungsi ini memastikan bahwa saat debugging dimulai, UI akan otomatis terbuka, dan saat selesai, UI ditutup secara otomatis.

#### 🔀 Keymap Toggle UI

```lua
vim.keymap.set("n", "<leader>du", function() dapui.toggle() end, { desc = "Toggle DAP UI" })
```

> Untuk membuka atau menutup panel UI debugger secara manual.

---

### 🔌 3. Peran `nvim-nio**`**

Plugin ini **tidak memiliki konfigurasi eksplisit dalam kode**, karena ia bekerja di balik layar. Fungsinya adalah untuk mendukung `dap-ui` dalam mengelola IO asinkron agar tidak membekukan editor saat mengambil data debugger (misalnya data variable, stack, dll).

> Meski tidak terlihat di dalam `config`, plugin ini wajib dipasang agar `nvim-dap-ui` bisa berfungsi.

---

### 🧷 Struktur Akhir Setup Debugging

- Plugin utama: `nvim-dap`
    
- UI debugger: `nvim-dap-ui`
    
- Support IO async: `nvim-nio`
    
- Debugger backend: CodeLLDB (melalui Mason)
    

Semua plugin diatur dalam satu blok konfigurasi `return { ... }`, dengan dependensi otomatis di-handle oleh LazyVim (atau Lazy.nvim).  

Konfigurasi ini memungkinkan debugging C/C++ berjalan lengkap dengan antarmuka visual, breakpoint, kontrol eksekusi, dan manajemen proses.

## 5.6 | Setting Makefile

Baiklah, sebelum setting lebih jauh, pastikan Makefile berhasil terpasang dengan baik, dengan cara mengecek perintah berikut pada terminal:

```bash
make --version
```

Jika keluar output yang menjelaskan tentang versi, baiklah, artinya kita bisa lanjut.

> ⚠️ **Penting!**
> 
> Konfigurasi Makefile ini akan dibuat dengan membuat compile yang memiliki flag *-g*, atau bertujuan untuk debug dan membantu setup codelldb. Untuk compilasi dan run biasa, akan dipisah di konfigurasi tersendiri!. 

Makefile sebenarnya adalah file, yang diberi nama `Makefile`, yang terdapat konfigurasi didalamnya. Penjelasan dibawah ini akan menjelasakan beberapa hal yang bisa diterapkan didalam konfigurasi Makefile:

### 🧱 Struktur File

```makefile
CXX = g++
CXXFLAGS = -g -Wall

SRC = main.cpp
TARGET = app

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	del $(TARGET).exe
```

#### 1. Variabel Compiler

```makefile
CXX = g++
CXXFLAGS = -g -Wall
```

- `CXX` mendefinisikan compiler yang digunakan. Dalam hal ini `g++`.
    
- `CXXFLAGS` adalah flag tambahan:
    
    - `-g` untuk debugging.
        
    - `-Wall` untuk mengaktifkan semua peringatan.
        

#### 2. Variabel Sumber dan Target

```makefile
SRC = main.cpp
TARGET = app
```

- `SRC` adalah file sumber utama.
    
- `TARGET` adalah nama file output (hasil kompilasi).
    

#### 3. Target .PHONY

```makefile
.PHONY: all run clean
```

- Memberi tahu `make` bahwa target `all`, `run`, dan `clean` **bukan nama file**, melainkan perintah logis.
    
- Ini penting agar `make run` tetap dijalankan walaupun ada file bernama `run`.
    

#### 4. Target `all`

```makefile
all: $(TARGET)
```

- Target default saat hanya mengetik `make`.
    
- Akan memicu pembuatan `app` jika belum ada atau `main.cpp` berubah.
    

#### 5. Target Build

```makefile
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $< -o $@
```

- Membuat executable dari file sumber.
    
- `$<` merepresentasikan file sumber (`main.cpp`).
    
- `$@` merepresentasikan nama target (`app`).
    

#### 6. Target `run`

```makefile
run: $(TARGET)
	./$(TARGET)
```

- Menjalankan program setelah build.
    
- Berguna untuk menguji program secara langsung.
    

#### 7. Target `clean`

```makefile
clean:
	del $(TARGET).exe
```

- Menghapus file hasil kompilasi agar bisa build ulang dari awal.
    

### Konfigurasi Makefile kita
Nah, pertama-tama, buat file dengan nama file yaitu `Makefile`, pastikan nama filenya sama! Lalu tempatkan didalam *root folder* kita. Setelah itu, masukan konfigurasi seperti berikut:

```makefile
CXX       = clang++
CXXFLAGS  = -g

SRC    = code.cpp
TARGET = code.exe

.PHONY: all run clean

all: $(TARGET)

# Compile code.cpp → code.exe (named 'code')
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $< -o $@

# Jalankan executable
run: $(TARGET)
	@echo [*] Checking if $(TARGET) is running...
	-tasklist | findstr /I $(TARGET) >nul && taskkill /f /im $(TARGET) >nul 2>&1 || echo [Zz] No running process.
	@echo [>]  Running $(TARGET)...
	./$(TARGET)

# Bersihkan hasil build
clean:
	-taskkill /f /im $(TARGET) >nul 2>&1
	if exist $(TARGET) del /q $(TARGET)
	if exist code.pdb del /q code.pdb
	if exist code.ilk del /q code.ilk
	if exist code del /q code
```

> File Makefile ini dibuat untuk mengelola proses kompilasi, eksekusi, dan pembersihan (_clean up_) program C++ dengan nama file sumber `code.cpp`. Makefile ini juga dilengkapi fitur untuk **mendeteksi dan menghentikan proses `code.exe` yang sedang berjalan** sebelum dijalankan ulang.

### 🔧 Isi Makefile

```makefile
CXX       = clang++
CXXFLAGS  = -g

SRC       = code.cpp
TARGET    = code.exe

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $< -o $@

run: $(TARGET)
	@echo [*] Checking if $(TARGET) is running...
	-tasklist | findstr /I $(TARGET) >nul && taskkill /f /im $(TARGET) >nul 2>&1 || echo [Zz] No running process.
	@echo [>]  Running $(TARGET)...
	./$(TARGET)

clean:
	-taskkill /f /im $(TARGET) >nul 2>&1
	if exist $(TARGET) del /q $(TARGET)
	if exist code.pdb del /q code.pdb
	if exist code.ilk del /q code.ilk
	if exist code del /q code
```

#### 🔹 Compiler dan Flag

```makefile
CXX = clang++
CXXFLAGS = -g
```

- `CXX` adalah compiler yang digunakan, yaitu `clang++`.
    
- `CXXFLAGS = -g` berarti program dikompilasi dengan **informasi debugging**, agar bisa digunakan dengan debugger seperti `lldb`.


#### 🔹 Variabel File

```makefile
SRC = code.cpp
TARGET = code.exe
```

- `SRC` adalah nama file sumber.
    
- `TARGET` adalah nama output dari hasil kompilasi.


#### 🔹 `.PHONY`

```makefile
.PHONY: all run clean
```

- Menyatakan bahwa `all`, `run`, dan `clean` adalah **target logis**, bukan nama file. Ini mencegah Make berhenti kalau ada file bernama `clean` atau `run`.


#### 🔹 Target `all`

```makefile
all: $(TARGET)
```

- Target default, jika user hanya menjalankan `make`.
    
- Akan membangun file `code.exe` dari `code.cpp`.


#### 🔹 Target Build

```makefile
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $< -o $@
```

- Memerintahkan compiler (`clang++`) untuk meng-compile `code.cpp` menjadi `code.exe`.
    
- `$<` → file sumber (`code.cpp`)
    
- `$@` → target (`code.exe`)


#### 🔹 Target `run` — Jalankan Program Otomatis

```makefile
run: $(TARGET)
	@echo [*] Checking if $(TARGET) is running...
	-tasklist | findstr /I $(TARGET) >nul && taskkill /f /im $(TARGET) >nul 2>&1 || echo [Zz] No running process.
	@echo [>]  Running $(TARGET)...
	./$(TARGET)
```

Fitur penting:

- Mengecek apakah `code.exe` sedang berjalan menggunakan `tasklist | findstr`.
    
- Jika iya → dihentikan pakai `taskkill /f /im code.exe`.
    
- Kalau tidak jalan → muncul pesan `[Zz] No running process.`
    
- Setelah itu, program langsung dijalankan (`./code.exe`).
    

**Note:** Tanda `@` mencegah baris `echo` dan `taskkill` ditampilkan di konsol sebelum dijalankan.

#### 🔹 Target `clean` — Bersihkan File Sisa

```makefile
clean:
	-taskkill /f /im $(TARGET) >nul 2>&1
	if exist $(TARGET) del /q $(TARGET)
	if exist code.pdb del /q code.pdb
	if exist code.ilk del /q code.ilk
	if exist code del /q code
```

- Menghapus file `code.exe` jika ada.
    
- Menghapus file tambahan `.pdb` (debug info), `.ilk` (link info), dan file `code` (jika tersisa).
    
- Juga mematikan proses `code.exe` yang masih jalan.
    

#### 🚀 Contoh Penggunaan

| Perintah     | Fungsi                                                      |
| ------------ | ----------------------------------------------------------- |
| `make`       | Compile `code.cpp` → `code.exe`                             |
| `make run`   | Auto-kill `code.exe` kalau sedang jalan, lalu jalankan lagi |
| `make clean` | Hapus `code.exe` dan file sampah build lainnya              |

### 📎 Catatan

- File ini dibuat untuk dijalankan di **Windows**, karena menggunakan perintah seperti `tasklist`, `taskkill`, dan `del`.
    
- Pastikan compiler `clang++` sudah tersedia di sistem (`scoop install llvm`).
    
- Bisa diadaptasi ke Linux/Mac dengan mengubah bagian `run` dan `clean`.
    
### Cara menggunakan

> Konfigurasi Makefile kita masih statis, sehingga Makefile ini hanya bekerja untuk file C++ dengan nama file `code.cpp`!

Untuk bisa menggunakan makefile, buka file C++ bernama `code.cpp` dengan neovim, pastikan bahwa file ini memiliki file Makefile yang telah kita buat, yang terletak di root foldernya. Lalu buka terminal. 

Nah, diterminal, kita bisa mengaktifkan Makefile, dengan memasukan perintah `make`, tapi karena file Makefile kita ada beberapa perintah yang kita buat, kita bisa menambahkan flag dibelakangya, sesuai perintah Makefile apa yang ingin kita jalankan.

Misal, jika kita memasukan perintah:

```bash
make
```

Maka kita akan mengcompilasi file C++ dengan flag *-g* yang artinya bisa didebug.

> Kompilasi tanpa -g artinya file tersebut tidak bisa didebug!

Jika semisal kita memasukan perintah berikut:

```bash
make run
```

Maka akan Auto-kill `code.exe` kalau sedang jalan, lalu jalankan lagi.

Dan jika kita menjalankan ini:

```bash
make clean
```

Maka kita akan hapus `code.exe` dan file sampah build lainnya.

Contohnya seperti ini:

![[20250726-0441-23.4704168.mp4]]

---
<br/>

# Setting Run, Compile, dan Debugger
Nah setelah semuanya sudah disiapkan, sekarang kita bisa menyiapakan cara untuk membuat file C++ kita bisa dicompile, run, dan debug dengan mudah, bahkan dengna menggunakan keymaps saja.

## 6.1 Run, Compile, dan lewat Input Output file

Kode berikut menyediakan keymaps, dan juga mekanime langsung untuk proses compile dan run. Kombinasi keymaps ini digunakan untuk:

| Tombol | Aksi                                                                                                                                                                                                                                |
| ------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| F3     | Menjalankan file C++ yang aktif, dan melakukan run dengan mengambil input dari `input.txt`, dan mengoutputkanya ke `output.txt`. Berguna untuk pengujian test case cepat.                                                           |
| F4     | Compile + Run dari file C++ yang aktif, dengan mengambil input dari `input.txt`, dan mengoutputkan hasilnya di `output.txt`. Berguna jika ingin melakukan aksi seperti F3, tepat setelah mengedit file, sehingga perubahan terekam. |
| F5     | Compile dan run, dengan menggunakan terminal didalam Neovim                                                                                                                                                                         |
| F6     | Hanya run, langsung muncul di terminal                                                                                                                                                                                              |
| F7     | Compile saja, berjalan di latar belakang                                                                                                                                                                                            |
Ada juga penambahan keymaps yang ditambahkan, untuk menampilkan file `input.txt` dan `output.txt` tepat dibilah kanan layar, sehingga lebih interaktif.


| Command   | Aksi                                                                                                                                                             |
| --------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| CppIOView | Menampilkan file `input.txt` dan juga file `output.txt` pada bilah kanan layar, sehingga bisa melakukan input dan output langsung lewat pembagian jendela layar. |

Untuk kode lengkapnya, semuanya dijadikan satu paket, yaitu sebagai berikut:

```lua
-- lua/cpp.lua

vim.api.nvim_create_autocmd("FileType", {
	pattern = "cpp",
	callback = function()
		local is_windows = vim.loop.os_uname().version:match("Windows")
		local exe_ext = is_windows and ".exe" or ""
		local run_cmd = is_windows and "%<" or "./%<"

		-- tombol F3 untuk run saja dari input.txt dan output.txt:
		vim.keymap.set("n", "<F3>", function()
			local filename = vim.fn.expand("%:t:r")
			local current_dir = vim.fn.expand("%:p:h")
			local exe_file = filename .. ".exe"
			local exe_path = current_dir .. "/" .. exe_file
			local input_path = current_dir .. "/input.txt"

			-- Cek apakah file executable sudah ada
			if vim.fn.filereadable(exe_path) == 0 then
				vim.notify("❌ File executable belum ada! Tekan <F4> dulu untuk kompilasi.", vim.log.levels.ERROR)
				return
			end

			-- Cek apakah input.txt tersedia
			if vim.fn.filereadable(input_path) == 0 then
				vim.notify("⚠️ input.txt tidak ditemukan!", vim.log.levels.WARN)
				return
			end

			-- Jalankan executable dengan input/output redirection
			local cmd = string.format('cd /D "%s" && "%s" < input.txt > output.txt', current_dir, exe_file)

			vim.fn.jobstart({ "cmd.exe", "/C", cmd }, {
				stdout_buffered = true,
				stderr_buffered = true,
				on_exit = function(job_id, code, _)
					if code ~= 0 then
						vim.notify("❌ Gagal Menjalankan File!", vim.log.levels.ERROR, { title = "Run Error" })
						return
					end

					vim.notify("🚀 Program berhasil dijalankan (tanpa compile ulang).", vim.log.levels.INFO)

					-- Refresh output.txt kalau sedang dibuka
					for _, buf in ipairs(vim.api.nvim_list_bufs()) do
						local name = vim.api.nvim_buf_get_name(buf)
						if name:match("output%.txt$") then
							vim.api.nvim_buf_call(buf, function()
								vim.cmd("checktime")
							end)
						end
					end
				end,
			})
		end, { buffer = true, noremap = true, silent = true })

		--  tombol F4 untuk compile + run dari input.txt dan output.txt
		vim.keymap.set("n", "<F4>", function()
			vim.cmd("w") -- simpan file dulu

			local filename = vim.fn.expand("%:t:r")
			local filepath = vim.fn.expand("%:p")
			local exe_file = filename .. ".exe"

			-- Pastikan input.txt dan output.txt berada di direktori yang sama dengan file sumber
			-- Ini penting agar cmd.exe bisa menemukannya dengan path relatif
			local current_dir = vim.fn.fnamemodify(filepath, ":h")

			-- Gabungkan compile dan run dalam satu perintah cmd.exe
			-- Perintah akan dijalankan dari direktori file saat ini
			local cmd = string.format(
				'cd /D "%s" && g++ "%s" -o "%s" && "%s" < input.txt > output.txt',
				current_dir,
				filepath,
				exe_file,
				exe_file
			)

			vim.fn.jobstart({ "cmd.exe", "/C", cmd }, {
				stdout_buffered = true,
				stderr_buffered = true,
				on_exit = function(job_id, code, event)
					if code ~= 0 then
						-- Jika ada error, ambil dan tampilkan output stderr
						local stderr_output = vim.fn.jobget(job_id, "stderr")
						local error_message = "❌ Compile atau Run gagal!\n"
						if #stderr_output > 0 then
							error_message = error_message .. table.concat(stderr_output, "\n")
						else
							error_message = error_message .. "Tidak ada detail error yang tersedia."
						end
						vim.notify(error_message, vim.log.levels.ERROR, { title = "Build Error" })
						return
					end

					-- Jika berhasil, notifikasi sukses
					vim.notify("✅ Kompilasi dan Eksekusi Berhasil!", vim.log.levels.INFO)

					-- Refresh output.txt kalau sedang dibuka
					for _, buf in ipairs(vim.api.nvim_list_bufs()) do
						local name = vim.api.nvim_buf_get_name(buf)
						if name:match("output%.txt$") then
							vim.api.nvim_buf_call(buf, function()
								vim.cmd("checktime")
							end)
						end
					end
				end,
			})
		end, { buffer = true, noremap = true, silent = true })

		-- vim.api.nvim_create_autocmd("BufEnter", {
		--   pattern = "output.txt",
		--   command = "checktime"
		-- })

		-- F5: Compile + Run
		vim.keymap.set("n", "<F5>", function()
			vim.cmd("w")
			local is_windows = vim.loop.os_uname().version:match("Windows")
			local exe_ext = is_windows and ".exe" or ""
			local run_cmd = (is_windows and ".\\" or "./") .. vim.fn.expand("%:t:r") .. exe_ext
			vim.cmd("belowright split | terminal g++ % -o %<" .. exe_ext .. " && " .. run_cmd)
		end, { buffer = true, noremap = true, silent = true })

		-- F6: Run only
		vim.keymap.set("n", "<F6>", function()
			local is_windows = vim.loop.os_uname().version:match("Windows")
			local exe_ext = is_windows and ".exe" or ""
			local run_cmd = (is_windows and ".\\" or "./") .. vim.fn.expand("%:t:r") .. exe_ext
			vim.cmd("belowright split | terminal " .. run_cmd)
		end, { buffer = true, noremap = true, silent = true })

		-- F7: Hanya Compile
		vim.keymap.set("n", "<F7>", function()
			vim.cmd("w")
			vim.cmd("belowright split | terminal g++ % -o %<" .. exe_ext)
		end, { buffer = true, noremap = true, silent = true })

		--/*------------------------------------------*\
		-- CMD untuk IO cepat, jendela terpisah
		--\*------------------------------------------*/
		vim.api.nvim_create_user_command("CppIOView", function()
			local current = vim.api.nvim_buf_get_name(0)

			-- Pastikan file aktif adalah C++
			if not current:match("%.cpp$") then
				print("Bukan file C++")
				return
			end

			-- Helper: cek apakah buffer sudah dibuka
			local function buf_opened(name)
				for _, buf in ipairs(vim.api.nvim_list_bufs()) do
					if vim.api.nvim_buf_get_name(buf):match(name) then
						return true
					end
				end
				return false
			end

			-- Split vertikal untuk input/output
			vim.cmd("vsplit")
			vim.cmd("wincmd l") -- ke kolom kanan

			if not buf_opened("input%.txt$") then
				vim.cmd("edit input.txt")
			else
				vim.cmd("b input.txt")
			end

			vim.cmd("split")
			if not buf_opened("output%.txt$") then
				vim.cmd("edit output.txt")
			else
				vim.cmd("b output.txt")
			end

			vim.cmd("wincmd h") -- kembali ke file utama
		end, {})
		-- end comand IO Cepat
	end,
})
```

---
<br/>

## 6.2 | Debugger
Untuk menjalakan debug, ada beberapa tahapan, perhatikan dengan seksama:

Untuk bisa melakukan proses debugging, pastikan kamu sedang berada di dalam file `code.cpp`, karena itu file utama yang digunakan saat kita mengkonfigurasi makefile. Mungkin kedepanya akan dibuat bisa menangani nama file secara dinamis.

Setelah membuka file `code.cpp`, buka terminal pada bagian bawah, dengan memasukan perintah ini di terminal:

```bash
sp | terminal
```

Maka akan terbuka terminal di bagian bawah.

Setelah itu, jalankan perintah ini pada terminal:

```bash
make
```

Ini akan megcompile program dengan flag `-g`, sehingga program kompilasi bisa kita debug, tanpa flag ini, maka tidak akan bisa. 

> Kompilasi dengan flag `-g` akan membuat kompilasi berjalan lambat, karena memang tujuan kompilasi dengan flag `-g` adalah untuk membuat program kompilasi bisa didebug. Untuk program compile, run, dan input output file diatas, kita melakukan kompilasi tanpa flag ini, sehingga kompilasi berjalan lebih cepat!

Pastikan compile berhasil dengan ditandai adanya file tamabhan yang muncul seperti:
- code.exe
- code.ilk
- code.pdb

Jika ketiga file ini muncul, artinya compile berhasil, dan kita bisa lanjut ke tahap selanjutnya.

> ⚠️ **Peringatan!**
> 
> Pastikan kamu tidak mengcompile file yang sama jika file compilasi atau sisa build masih ada! Ini akan membuat `code.exe` tidak bisa dijalankan, karena ada masalah aplikasi yang berjalan di latar belakang! Masalah yang ditimbulkan cukup sulit diatasi setelahnya, dimana sisa build baru akan terhapus jika kita merestart perangkat!
> 
> Jika ingin mengcompile file yang sama dengan Makefile setelah kamu melakukan pengeditan kode, lakukan `make clean` terlebih dahulu untuk membersihkan sisa build sebelumnya, baru jalankan `make` lagi!

Sebelum debug dilakukan, beri breakpoint atau titik pause pada file kita, dengan cara `<leader>db` atau *Spasi + d + b*, tempatkan pada beberapa baris. Penempatan breakpoint ini penting, karena jika tidak, debugger akan berlalu begitu saja.

Tekan `<leader>dc`, atau *Spasi + d + c* untuk menjalankan debugger. 

Jika ingin menambahkan beberapa keymaps cepat, bisa tambahkan ini didalam file `dap-codelldb.lua`. Dimana terdapat penambahan keymap sehingga kita tidak perlu menulis diterminal secara manual:

| Keymaps      | Command dikeluarkan |
| ------------ | ------------------- |
| `<leader>dm` | `make`              |
| `<leader>ds` | `make clean`        |
Kode yang perlu ditambahkan adalah seperti ini:

```lua
    -- === Keymap untuk debug file yang sedang aktif ===
      vim.keymap.set("n", "<leader>dm", function()
        print("🔨 Compiling with make...")
        local output = vim.fn.system("make")
        if vim.v.shell_error ~= 0 then
          print("❌ Compile error:\n" .. output)
        else
          print("✅ Compile success")
        end
      end, { desc = "Compile (make)" })

      -- === keymap untuk clean program sebelum lagi === 
      vim.keymap.set("n", "<leader>ds", function()
        print("🧹 Clear all build files...")
        local output = vim.fn.system("make clean")
        if vim.v.shell_error ~= 0 then
          print("❌ Cleaning error:\n" .. output)
        else
          print("✅ Cleaning succes")
        end
      end, { desc = "Clean (make clean)" })
```

Jika kamu ingin mebambahkan keymaps lagi, silahkan saja tambahkan 😁. Tempatkan tepat dibawah kumpulan konfigurasi keymaps yang lainya, tepat diatas setup DAP adapter codelldb.

# Demo Hasil Akhir
## 7.1 | Compile, run, dan input output file

![[20250726-0541-10.5652142.mp4]]
## 7.2 | Debugger

![[20250726-0547-21.6696660.mp4]]
Saat melakukan proses debugger, pastikan jangan menggunakan opsi `step-over` hingga menyentuh `reutrn 0;`. Karena jika kamu melakukan `step-over` pada saat sudah berada di baris `return 0;`, maka kamu akan terlempat ke kumpulan kode assembly 😂.