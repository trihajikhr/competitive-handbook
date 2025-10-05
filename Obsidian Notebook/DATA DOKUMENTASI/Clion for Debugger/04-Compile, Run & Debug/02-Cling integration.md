---
obsidianUIMode: preview
note_type: Dokumentasi
judul_dokumentasi: Cling integration
date_add: 2025-10-02T14:55:00
status_dokumentasi: ✅Finish
tags:
  - dokumentasi
  - clion
  - IDE
---
---
# 1 | Cling integration

Sumber: [Cling integration - Documentation](https://www.jetbrains.com/help/clion/2022.2/cling-integration.html)

CLion terintegrasi dengan [Cling](https://cdn.rawgit.com/root-project/cling/master/www/index.html), sebuah _interpreter_ C++ interaktif yang dibangun di atas **Clang** dan **LLVM**. **Cling** memungkinkan Anda menjalankan _code_ tanpa harus melakukan _building_ project, yang dapat sangat berguna untuk **prototyping** dan mempelajari C++. Lihat video singkat [Cling basics](https://www.youtube.com/watch?v=Lbi7MLS03Yc).

## 1.1 | Instalasi Cling

1. [Download](https://root.cern.ch/download/cling/) executable Cling untuk OS Anda atau instal menggunakan dependency manager. Di macOS, gunakan perintah [brew](https://brew.sh/) berikut: `brew install cling`.

2. Di CLion, buka **Settings | Languages & Frameworks | C/C++ | Cling**.
   
   Jika **Cling** sudah tersedia di **PATH** sistem, CLion akan mendeteksinya secara otomatis. Jika tidak, berikan _path_ di kolom yang tersedia.
   
   ![[02-Cling integration-1.png]]

## 1.2 | Menggunakan Cling untuk Menginterpretasi Kode

- Anda bisa memanggil aksi-aksi yang terkait dengan **Cling** dari menu utama **Tools | Cling** atau melalui **Help | Find Action** (Ctrl+Shift+A).
  
  ![[02-Cling integration-2.png]]

- Untuk mengirim satu baris atau _selection_ ke sesi **Cling**, klik ikon bola lampu (atau tekan **Alt+Enter**) pada potongan _code_ yang diinginkan:
  
  ![[02-Cling integration-3.png]]


- Opsi lain adalah mengetik _code_ secara langsung di [Cling terminal](https://www.jetbrains.com/help/clion/2025.3/cling-integration.html#cling-terminal).

> Sesi **Cling** dimulai dengan _flags_ yang dikumpulkan untuk _file_ yang sedang terbuka. Ini berlaku baik untuk **language standards** maupun **include paths**.


## 1.3 | Working Directory untuk Sesi Cling

- Jika ada _file_ yang sedang terbuka di _editor_, _directory_ dari _file_ tersebut akan digunakan sebagai **working directory** untuk **Cling**. _Include paths_ terkait dari _file_ ini juga akan berfungsi ketika dikirim ke sesi yang sama.

- Jika tidak ada _file_ yang terbuka, CLion menggunakan _root_ **project**.

- Jika tidak ada **project**, _home directory_ yang akan digunakan.

## 1.4 |  Cling Terminal

Setelah menjalankan salah satu aksi **Cling**, CLion akan membuka _window_ **terminal** khusus.

Anda bisa mengetik _code_ di _window_ ini, serta _load file_ yang sedang dibuka atau _reset_/_close_ sesi menggunakan tombol-tombol yang ada di **toolbar**.

![[02-Cling integration-4.png]]


## 1.5 | Isu dan Keterbatasan Saat Ini

- Penambahan argumen ekstra ke **Cling executable** dari dalam CLion saat ini tidak tersedia.

- Sesi **Cling** dimulai di dalam _directory_ **project** atau di dalam _home directory_ jika tidak ada **project** yang sedang terbuka. _Relative paths_ mungkin tidak ditangani dengan benar saat mengirim baris saat ini ke **Cling** dari _file_ yang tidak berada di _root project_.

- **Cling** tidak didukung di [CLion Nova](https://www.jetbrains.com/help/clion/2025.3/clion-nova-introduction.html).

<br/>

---

# 2 | Rangkuman

Cling adalah **C++ interpreter** yang dikembangkan di atas _compiler infrastructure_ LLVM dan Clang. Tidak seperti eksekusi C++ konvensional yang mengharuskan proses kompilasi terlebih dahulu, cling memungkinkan kode C++ dijalankan secara **interaktif** dalam lingkungan mirip _REPL_ (_Read–Eval–Print Loop_), sehingga setiap perintah atau potongan kode dapat dievaluasi segera setelah dituliskan.

Dalam konteks **CLion**, cling dapat diintegrasikan melalui plugin khusus. Integrasi ini menyediakan manfaat berikut:

1. **Eksperimen Cepat** – Pengguna dapat mengeksekusi potongan kode C++ tanpa perlu membuat fungsi `main()` atau melalui proses kompilasi lengkap.
    
2. **Prototyping dan Pembelajaran** – Memfasilitasi uji coba konsep, algoritme, atau sintaks baru secara instan, yang sangat membantu untuk keperluan pendidikan maupun penelitian.
    
3. **Konsistensi dengan Ekosistem LLVM/Clang** – Karena cling berbasis pada Clang, interpretasi kode tetap konsisten dengan standar kompilasi modern.
    

Dengan demikian, cling berfungsi sebagai alat yang menjembatani antara sifat C++ yang _compiled language_ dengan fleksibilitas bahasa yang bersifat _interpreted_.

```ad-summary
Cling adalah **interpreter C++ berbasis LLVM/Clang** yang memungkinkan kode C++ dijalankan secara interaktif, tanpa melalui tahapan kompilasi penuh sebagaimana biasanya diperlukan dalam bahasa C++. Dalam CLion, cling dapat digunakan melalui plugin khusus sehingga IDE tidak hanya berfungsi sebagai lingkungan pengembangan berbasis kompilasi, tetapi juga sebagai **REPL (Read–Eval–Print Loop)** untuk C++.

Secara analogi, cling dapat dibandingkan dengan **laboratorium percobaan**:

- Jika menggunakan metode kompilasi biasa, prosesnya seperti **memasak makanan dengan resep lengkap**. Anda harus menyiapkan seluruh bahan, mengikuti langkah demi langkah, baru kemudian mendapatkan hasil akhir.
    
- Dengan cling, prosesnya lebih mirip seperti **dapur percobaan cepat**. Anda bisa mencoba mencampurkan sedikit bahan, langsung mencicipi, lalu memutuskan apakah ingin melanjutkan atau mengubah racikan. Tidak perlu selalu menyiapkan masakan utuh dari awal.
    

Dalam CLion, integrasi cling memungkinkan:

1. **Eksperimen kode singkat** tanpa membuat proyek penuh.
    
2. **Prototyping algoritme** dengan cara mencoba blok kode kecil secara langsung.
    
3. **Pembelajaran interaktif**, di mana pemula dapat memahami konsep C++ secara bertahap, layaknya mencoba eksperimen kecil dalam laboratorium.
    

Dengan demikian, cling menghadirkan keseimbangan: formalitas dan kekuatan bahasa C++ tetap dipertahankan, namun dengan fleksibilitas yang biasanya hanya ditemui pada bahasa _interpreted_.

```

<br/>

---
# 3 | Menggunakan Cling di Windows

```ad-tip
Untuk menggunakan Cling, maka didalam device atau operating system kita sudah harus terpasang Cling, baru bisa mengintegrasikanya dengan Clion. Jadi, jika belum, untuk pengguna Linux dan MacOS, hal ini mudah saja, karena bisa langsung mencari installernya disini: [Index of /download/cling](https://root.cern/download/cling/)

Tapi jika kamu pengguna Windows, maka baca panduan dibawah ini:
```

Tapi, ada beberapa hal yang harus kamu tahu, bahwa Cling lebih sulit digunakan untuk windows! 

Kenapa? Berikut alasanya:

Secara tradisional, **Cling** lebih cocok dengan sistem operasi berbasis **Unix** (seperti Linux dan macOS) karena dibangun di atas **Clang** dan **LLVM** yang memang awalnya lebih fokus di sana.

Namun, situasinya saat ini adalah:

## 3.1 | Cling _Standalone_ di Windows: Memungkinkan, tapi Rumit

Untuk waktu yang lama, Cling tidak memiliki _installer_ resmi atau _binary_ siap pakai untuk Windows. Meskipun begitu:

- **Bisa Dibangun (_Build_) dari _Source_:** Beberapa pengguna berhasil melakukan _compile_ **Cling** di Windows menggunakan _tool_ seperti **MSVC** atau **Mingw/Cygwin**, tetapi ini adalah proses yang rumit dan tidak disarankan untuk pemula.
    
- **Ada Proyek _Community_:** Ada repositori GitHub yang menyediakan _executable_ Cling yang sudah di-_build_ untuk Windows, namun ini bukan solusi resmi.
    

##  3.2 | Solusi Terbaik untuk Pengguna Windows: WSL

Saat ini, cara terbaik dan paling stabil untuk menggunakan **Cling** di Windows adalah melalui **WSL (Windows Subsystem for Linux)**.

- **Mengapa WSL?** WSL memungkinkan Anda menjalankan lingkungan Linux (seperti Ubuntu) secara _native_ di Windows. Karena Cling sangat cocok dengan Linux, Anda bisa menginstalnya dengan mudah di dalam WSL (misalnya, menggunakan `brew install cling` jika Anda menginstal _brew_ di WSL, atau menggunakan _package manager_ Linux lainnya).
    
- **Integrasi dengan CLion:** CLion sangat baik dalam bekerja dengan _toolchain_ yang diinstal di WSL, jadi integrasi Cling Anda akan berjalan lancar di dalam IDE.
    

## 3.3 | Kesimpulan

- **Cling _as-is_ (Installer langsung di Windows) :** Sulit ditemukan yang resmi dan stabil.
    
- **Cling via WSL (Windows Subsystem for Linux) :** **Ini adalah cara yang disarankan** untuk pengguna Windows agar dapat menggunakan Cling dengan mudah.
    

Jadi, meskipun secara teknis ada cara untuk menginstalnya langsung, menggunakan **WSL** adalah jalur yang jauh lebih mudah dan diakui untuk integrasi dengan _tool_ berbasis Unix seperti Cling.

<br/>

---
# 4 | Mengkoneksikan Clion dengan WSL


Meskipun Cling sendiri lebih "betah" di lingkungan **Unix/Linux**, CLion, sebagai IDE yang cerdas, punya cara untuk menghubungkannya bahkan ketika Anda bekerja di Windows.

Anda **bisa** menyambungkan CLion yang berjalan di Windows ke Cling, tetapi caranya adalah melalui **WSL (Windows Subsystem for Linux)**.

Berikut adalah cara kerjanya agar Anda bisa tetap menggunakan CLion di Windows sambil memanfaatkan Cling:

## 4.1 | Cara Menghubungkan CLion (Windows) ke Cling (WSL)

### 4.1.1 | Instalasi Cling di WSL

Pertama, Anda harus menginstal **Cling** di _distro_ Linux yang sudah Anda siapkan di **WSL** (misalnya, Ubuntu di WSL). CLion menganggap WSL ini sebagai lingkungan pengembangan Linux jarak jauh (meskipun ada di komputer yang sama).

- **Langkah:** Buka terminal WSL Anda dan instal Cling di sana (misalnya, menggunakan _package manager_ seperti `apt` atau `brew` jika Anda menginstalnya).
    

### 4.1.2 | Konfigurasi Toolchain di CLion

Di CLion versi Windows, Anda perlu memberi tahu IDE bahwa Anda ingin menggunakan _toolchain_ (kompilator dan _debugger_) yang ada di dalam WSL.

- **Langkah:**
    
    1. Buka **Settings | Build, Execution, Deployment | Toolchains** di CLion.
        
    2. Tambahkan **Toolchain** baru dan pilih tipe **WSL**.
        
    3. CLion akan otomatis mendeteksi dan menggunakan **CMake**, **Compiler**, dan **Debugger** yang terinstal di dalam WSL Anda.
        

### 4.1.3 | Konfigurasi Cling di CLion

Setelah _toolchain_ WSL terdeteksi, Anda bisa menunjuk Cling yang sudah terinstal di WSL.

- **Langkah:**
    
    1. Buka **Settings | Languages & Frameworks | C/C++ | Cling**.
        
    2. Di kolom _Path to Cling executable_, masukkan jalur _executable_ **Cling** yang ada di dalam lingkungan WSL Anda.
        

## 4.2 | Hasilnya

Dengan cara ini, ketika Anda menggunakan fitur **Cling** di CLion (seperti menekan **Alt+Enter** pada sebuah _line_ kode), CLion akan mengirimkan perintah tersebut ke _executable_ **Cling** yang berjalan di dalam WSL. Hasilnya akan ditampilkan kembali di **Cling terminal** di dalam _window_ CLion Anda, seolah-olah semuanya berjalan _native_ di Windows.

Intinya, CLion bertindak sebagai jembatan yang sangat efektif!
