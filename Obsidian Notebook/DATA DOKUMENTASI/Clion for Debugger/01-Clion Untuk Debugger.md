---
obsidianUIMode: preview
note_type: Dokumentasi
judul_dokumentasi: Clion Untuk Debugger
date_add: 2025-09-25T22:45:00
status_dokumentasi: ✅Finish ❌Not-Finish
tags:
  - debugger
---
---
# 1 | Clion Untuk Debugger

## 1.1 | Pendahuluan

Competitive programming bukan hanya mengetik dan menyelesaikan problem dengan cepat, karena yang paling penting adalah kemampuan menyelesaikan masalah secara tepat dengan algoritma tertentu.

Terkadang, kita harus mempelajari suatu algoritma tertentu agar bisa berkembang di dunia competitive programming. Ada banyak sekali algoritma, mulai dari algoritma yang sederhana, hingga yang sangat kompleks. 

Untuk menguasai algoritma-algoritma yang lebih kompleks dan semakin sulit, dibutuhkan tools bantu, dan aku yakin, itu adalah debugger.

Debugger, biasanya digunakan orang-orang untuk mengecek alur berjalanya program, dan mengetahui perubahan variabel atau struktur data selama berjalanya program, atau mungkin mengecek apakah ada kesalahan logika yang membuat output tidak sesuai.

Tapi, menurutku, debugger juga bisa menjadi alat yang bagus untuk digunakan sebagai alat  mempelajari algoritma-algoritma dalam pemrograman.

Semisal, katakanlah kita ingin mempelajari algoritma graph, three, dan sebagainya, dengan menggunakan debugger, kita bisa menjadi tahu alur logika dan alur program, sehingga pemahaman kita menjadi jauh lebih baik dan cepat.

Ada banyak sekali debugger yang bisa digunakan, salah satunya adalah debugger yang ada secara bawaan di VS code. Karena aku saat ini menggunakan neovim, aku juga sudah menyetel debugger disana, tetapi aku menghadapi masalah yang sangat rumit.

Ketika menjalankan debugger pada kode yang memiliki struktur data vector, element didalam vector tidak bisa ditampilkan dengan baik, karena memang vector mengalokasikan penyimpanan di heap, bukan di stack seperti deklarasi array biasa. Hal ini  karena vector merupakan array dinamis.

Selain itu, aku juga cukup dipusingkan dengan banyaknya setting yang harus dilakukan, hanya untuk memperbaiki masalah ini.

Jika menggunakan VS code, aku kadang mengalami masalah atau crash ketika menjalankan debugger disana, agak aneh intinya. Kadang berhasil, kadang error, kadang keluar sendiri, dan banyak lainya. Ditambah di vscode, kita harus menulis command launch json secara manual, harus lihat banyak editorial atau panduan supaya debuggernya mau berjalan dengan pas.

Oleh karena itu, aku memutuskan untuk memiliih Clion, sebagai tools bantu debugger utamaku. Kenapa, karena banyak orang yang mengatakan demikian, bahwa Clion cukup bagus, dan sangat nyaman dan lengkap untuk dijadikan alat untuk debuging.

## 1.2 | Kenapa Clion

Mengapa Clion merupakan pilihan terbaik untuk debugging di C++?

![[Clion Untuk Debugger-10.png]]

![[Clion Untuk Debugger-11.png]]

### 1.2.1 | Integrasi yang Mendalam dengan CMake

CLion memiliki integrasi bawaan dengan **CMake**, yang saat ini menjadi standar de facto untuk manajemen build pada proyek C++. Dengan demikian, konfigurasi target build untuk proses debugging dapat dilakukan secara otomatis tanpa perlu pengaturan manual yang kompleks. Hal ini memberikan efisiensi yang signifikan dibandingkan dengan editor seperti Visual Studio Code yang mengharuskan penulisan konfigurasi terpisah (misalnya melalui *launch.json*).

### 1.2.2 | Antarmuka Debugger yang Lengkap dan Intuitif

Meskipun CLion menggunakan **GDB** atau **LLDB** sebagai mesin utama, antarmuka pengguna yang disediakan jauh lebih ramah dan komprehensif. Fitur-fitur penting yang tersedia antara lain:

* **Breakpoint** dengan berbagai variasi (baris, fungsi, bersyarat, dan log).
* Navigasi eksekusi (*step over, step into, step out*) dengan mudah.
* Tampilan **call stack** dan **threads** yang terorganisasi dengan baik.
* **Variable inspector** untuk memeriksa isi variabel, termasuk struktur bersarang dan pointer.
* Akses ke **memory view**, **register**, bahkan tampilan **assembly** bila diperlukan.

### 1.2.3 | Fasilitas Evaluasi Ekspresi

CLion menyediakan fitur **Evaluate Expression**, yang memungkinkan pengguna mengeksekusi ekspresi tertentu saat program berhenti di sebuah breakpoint. Dengan cara ini, pengguna dapat memeriksa hasil ekspresi kompleks tanpa harus menambahkan pernyataan *print* ke dalam kode sumber.

### 1.2.4 | Sistem Watch dan Tampilan Data yang Kaya

Pengguna dapat menetapkan **watch** pada variabel atau ekspresi tertentu untuk dimonitor secara berkelanjutan. Selain itu, struktur data seperti array atau kontainer standar C++ dapat diperluas secara visual untuk menampilkan elemen-elemennya. Hal ini sangat membantu ketika mendiagnosis kesalahan terkait struktur data berskala besar.

### 1.2.6 | Konsistensi Lintas Platform

CLion tersedia pada **Linux, macOS, dan Windows**, dengan pengalaman pengguna yang relatif konsisten. Hal ini penting bagi pengembang yang bekerja di berbagai lingkungan pengembangan.

### 1.2.7 | Integrasi dengan Pengujian dan Profiling

Selain debugging, CLion memiliki integrasi dengan kerangka pengujian (misalnya **Google Test** dan **Catch2**) serta dukungan *profiling* untuk analisis kinerja CPU maupun penggunaan memori. Fasilitas ini memperluas cakupan kegiatan debugging menjadi pemeliharaan dan peningkatan performa program.

### 1.2.8 | Dukungan Refactoring dan *Code Insight*

Selama proses debugging, sering kali diperlukan modifikasi kode secara cepat. CLion menyediakan alat refactoring yang canggih, navigasi kode yang efisien, serta fitur *code completion* yang cerdas. Dengan demikian, siklus *debug–perbaikan–eksekusi ulang* dapat berlangsung lebih lancar dan efisien.

## 1.3 | Perbandingan dengan Alternatif

* **Visual Studio Code**: fleksibel dan gratis, tetapi memerlukan konfigurasi manual yang relatif kompleks serta menawarkan pengalaman debugging yang lebih terbatas.

<br/>

* **Visual Studio (Windows)**: debugger sangat kuat, tetapi hanya optimal pada sistem operasi Windows dan cukup berat dijalankan.
<br/>

* **Neovim dengan nvim-dap**: sangat ringan dan dapat disesuaikan, tetapi kurang mendukung inspeksi variabel yang kaya dan visual.

## 1.4 | Kesimpulan

CLion dianggap sebagai salah satu pilihan terbaik untuk debugging C++ karena kemampuannya dalam **mengintegrasikan mesin debugger (GDB/LLDB) dengan antarmuka modern, dukungan CMake, serta fitur-fitur tambahan** seperti evaluasi ekspresi, sistem watch, integrasi pengujian, dan *profiling*. Kombinasi ini menjadikan CLion sebagai lingkungan yang tidak hanya memudahkan proses debugging, tetapi juga meningkatkan produktivitas secara keseluruhan.

<br/>

---
# 2 | Pemasangan Clion

## 2.1 | Pemilihan Versi Unduhan

Pemasangan Clion cukup mudah, cukup masuk ke pencarian Google, atau browser apapun, lalu masukan keywoard *install Clion*, maka akan muncul situs downloadnya. Situs download nya yaitu [Download Clion](https://www.jetbrains.com/clion/download/?section=windows):

![[Clion Untuk Debugger-1.png]]
Karena aku menggunakan Windows, maka aku akan pasang yang sesuai dengan sistem operasiku, yaitu Windows. DI pilihan ini, sesuaikan saja versi Clion dengan Operating System yang kita gunakan. 

Lalu pada bagian unduhan ini, juga ada pilihan (Windows) yaitu `.exe`, `.zip`, dan `.exe (ARM64)`. Lalu, apa bedanya? Pilih yang mana?

1. **Installer `.exe` (Windows, x64)**
    
    - Ini adalah **installer standar** untuk Windows dengan arsitektur prosesor **64-bit (x86_64/AMD64)**.
        
    - Saat dijalankan, installer akan menambahkan CLion ke dalam sistem dengan integrasi penuh: shortcut di Start Menu, opsi uninstall, serta integrasi dengan Windows Registry.
        
    - Direkomendasikan untuk **pengguna umum Windows modern**.
        
2. **Paket `.zip` (Windows, x64)**
    
    - Berisi file CLion dalam bentuk arsip yang sudah siap dipakai, **tanpa proses instalasi**.
        
    - Anda cukup mengekstraknya, kemudian menjalankan file `clion.bat` atau `clion64.exe`.
        
    - Cocok untuk:
        
        - Pengguna yang tidak ingin menambahkan CLion ke sistem (portable).
            
        - Pengguna yang ingin menyimpan beberapa versi CLion berdampingan.
            
        - Lingkungan kerja terbatas di mana instalasi program tidak diizinkan.
            
3. **Installer `.exe (ARM64)` (Windows on ARM)**
    
    - Ditujukan untuk perangkat dengan **prosesor ARM64** (misalnya Microsoft Surface Pro X atau laptop berbasis Snapdragon).
        
    - Versi ini dioptimalkan agar berjalan native di Windows ARM, tanpa perlu emulasi.
        
    - Tidak diperlukan untuk PC/laptop biasa dengan prosesor Intel atau AMD.
        


Pilihan yang sebaiknya diambil adalah:

- **Mayoritas pengguna (PC/laptop Intel/AMD 64-bit, Windows 10/11)** → pilih **`.exe` (x64)**.
    
- **Jika menginginkan versi portable** (tidak meninggalkan jejak instalasi) → pilih **`.zip`**.
    
- **Jika menggunakan perangkat Windows berbasis ARM** (contoh: Surface Pro X) → pilih **`.exe (ARM64)`**.

Nah setelah memilih versi yang sesuai, klik download, dan tunggu hingga proses pengunduhan selesai. Proses ini mungkin memakan waktu yang tidak sebentar, karena ukuran dari Clion yang cukup besar, yaitu 1,6 Gb.

## 2.2 | Pemasangan

Sekarang, kita akan memasang Clion kedalam sistem komputer kita. Karena kita menginstal versi `.exe`, maka tinggal klik 2 kali aplikasi yang terinstall tersebut, hingga muncul tampilan seperti ini:

![[Clion Untuk Debugger-2.png]]

Setelah itu tekan `next`, dan pada jendela dibawah ini, kita langsung `next` lagi jika ingin lokasi instalasi berada di folder default. Jika tidak, bisa dirubah ingin diinstal di folder lain, semisal di drive D, untuk menghindari drive C menjadi terlalu penuh. Tapi disini kita akan memasangnya di dalam drive C, supaya path nya lebih rapi:

![[Clion Untuk Debugger-3.png]]

Setalh itu, kita akan dibawa ke tampilan jendela selanjutnya. Di jendela Installation Options, akan ada beberapa menu:

1. **Create Desktop Shortcut**

   * Membuat ikon CLion di desktop.
   * *Opsional* → pilih jika ingin akses cepat dari desktop.

2. **Create Associations**

   * Mengaitkan ekstensi file tertentu dengan CLion.
   * Misalnya `.cpp`, `.h`, `.c`, `.hpp`.
   * Jika dicentang, file dengan ekstensi tersebut otomatis terbuka dengan CLion saat di-*double-click*.
   * Pilih jika Anda memang ingin CLion menjadi editor utama C++.

3. **Add "Open Folder as Project" action to context menu**

   * Menambahkan opsi pada menu klik kanan Windows Explorer untuk membuka folder langsung di CLion.
   * Cukup berguna, jadi **disarankan dicentang**.

4. **Update PATH variable (restart required)**

   * Menambahkan shortcut ke **command line launcher**.
   * Artinya Anda bisa mengetik `clion` di Command Prompt/PowerShell untuk menjalankan CLion.
   * Praktis bila Anda sering bekerja dari terminal.
   * **Disarankan dicentang**.


Maka, hasilnya akan menjadi seperti ini, setelah itu `next` lagi:

![[Clion Untuk Debugger-4.png]]


Lalu, pada jendela Choose Start Menu Folder, akan ada beberapa pilihan.

- Di tahap ini, installer menanyakan di **folder Start Menu** mana shortcut untuk CLion akan ditempatkan.
    
- Shortcut ini yang nantinya muncul di menu **Start** (Windows → tombol Start → daftar aplikasi).

Pilihan yang muncul antara lain:

1. **JetBrains → CLion** (default)
    
    - Akan membuat folder bernama _JetBrains_ di Start Menu, lalu di dalamnya ada ikon CLion.
        
    - Rapi dan sesuai standar JetBrains.
        
2. **Custom Folder Name**
    
    - Anda bisa mengubah nama folder, misalnya hanya "CLion" tanpa folder JetBrains.
        
3. **Do not create shortcuts**
    
    - Tidak membuat shortcut sama sekali di Start Menu.
        
    - CLion hanya bisa dijalankan dari desktop shortcut atau langsung dari folder instalasi.
        

Supaya lebih mudah, kita pilih saja Jetbrains -> Clion (default), main aman saja.

![[Clion Untuk Debugger-5.png]]

Setelah itu, kita klik `Install`:

![[Clion Untuk Debugger-6.png]]

Proses installasi memakan waktu cukup lama disini, jadi kita tunggu saja hingga prosesnya selesai.

Nah, jika instalasinya sudah selesai, maka akan muncul jendela seperti ini:

![[Clion Untuk Debugger-7.png]]

Disini, alangkah baiknya kita restart computer kita, karena di proses sebelumnya, kita telah mencentang `Update path Variable`.

Sekarang coba buka Clion setelah restart, dan coba buka juga dari terminal dengan mengetikan `clion`. Jika Clion terbuka, artinya konfigurasi kita berhasil.

<br/>

---
# 3 | Konfigurasi Clion & Aktivasi Lisensi

Pada saat membuka Clion untuk pertama kali, akan ada jendela seperti ini:

![[Clion Untuk Debugger-8.png]]

Klik `Allow` saja.

Oke, dibagian konfigurasi awal ini, kita akan belajar pilihan-pilihan dibagian awal. Tapi sebelum kita mempelajari banyak opsi yang tersedia, ada hal yang harus diketahui disini.

Clion dan produk dari Jetbrains, mayoritas berbayar. Kita bisa memasang dan menjalankan Clion sekarrang, karena terdapat fase trial selama 30 hari, yang bisa kita lihat di opsi Project, lalu lihat dibagian paling kanan bawah:

![[Clion Untuk Debugger-12.png]]

Jetbrains sebenarnya menyediakan versi gratis dari Clion, jika kita memiliki akun pelajar atau pengajar, semisal kita adalah mahasiswa atau pengajar di sebuah universitas. Dengan menggunakan akun pelajar atau pengajar, kita bisa mengaktifkan penggunaan Clion secara gratis selama 1 tahun, dengan login menggunakan akun pelajar dan mengikuti beberapa syarat yang diberikan di situs Jetbrains, tepatnya di situs [Jetbrains Student Pack](https://www.jetbrains.com/academy/student-pack/).

![[Clion Untuk Debugger-14.png]]

Penggunaan Clion ini juga bisa diperpanjang selama beberapa tahun seterusnya, jadi harus diaktifkan lagi secara berkala.

Namun, kabar baiknya adalah, pada tanggal 7 Mei 2025, melalui postingan dari situs [CLion Is Now Free for Non-Commercial Use \| The CLion Blog](https://blog.jetbrains.com/clion/2025/05/clion-is-now-free-for-non-commercial-use/), diumumkan bahwa Clion bisa digunakan secara gratis, untuk penggunaan non-komersial:

![[Clion Untuk Debugger-13.png]]

Nah, postingan dari situs ini menyediakan panduan tentang bagaimana caranya menjadikan Clion yang kita punya bisa digunakan secara gratis, gulir saja kebagian bawah, dan akan terdapat panduan singkat yang bisa diikuti. 

Tapi, tenang saja, karena dokumentasi ini akan menjelaskanya juga.

Pertama, jalankan Clion yang sudah terinstall, lalu masuk ke bagian project:

![[Clion Untuk Debugger-15.png]]

Pilih project atau folder apapun, yang penting bisa masuk ke tampilan project terlebih dahulu. Setelah itu, pasti dibagian kanan bawah, terdapat tulisan trial, seperti ini:

![[Clion Untuk Debugger-12.png]]

Klik tulisan trial tersebut, lalu klik bagian `Activate Another License`:

![[Clion Untuk Debugger-16.png]]

Dan lalu pilih opsi penggunaan gratis, untuk penggunaan non-komersil:

![[Clion Untuk Debugger-17.png]]

Dan pilih login:

![[Clion Untuk Debugger-18.png]]

Ketika ini diklik, maka akan dibawa ke situs Jetbrains untuk login, atau membuat akun:

![[Clion Untuk Debugger-19.png]]

Jika belum memiliki akun, maka klik opsi buat akun `Create an account`. Tapi jika ingin langsung terkoneksi ke akun gmail, github, atau semacamnya yang sudah disediakan, maka gunakan saja salah satu. Disini aku menggunakan opsi `Continue with Google`, karena Google Chrome ku sudah terpasang akun google ku, sehingga dengan sekali klik, otomatis terbuat akun Jetbrains yang informasinya sama dengan akun Gmailku. Paling hanya diminta untuk memasukan First name dan Last name saja, dan sudah sesimple itu.

Jika berhasil, maka akan ada pemberitahuan bahwa authorization succesfull, 

![[Clion Untuk Debugger-20.png]]

dan jika kembali ke tampilan Clion kita sebelumnya, maka akan menjadi seperti ini:

![[Clion Untuk Debugger-21.png]]

Nama akun kita akan muncul dibagian bawah, dan tersedia checklist untuk kita centang, yang mana bisa langsung kita check saja untuk mengaktifkan Clion mode gratis ini 😎:

![[Clion Untuk Debugger-22.png]]

Klik `Start Non-Commercial Use`, dan...

![[Clion Untuk Debugger-23.png]]

Sekarang, Clion bisa digunakan dengan gratis, tanpa trial, dan tanpa perlu membayar 😀. Worth it kan? Worth it  lah 😜.

![[Clion Untuk Debugger-24.png]]

<br/>

---
# 4 | Tutorial Menu

Pada bagian ini, kita akan belajar fitur-fitur yang disediakan oleh Clion, mulai dari yang paling gampang hingga ke yang lebih kompleks.

## 4.1 | Learn

Menu pilihan Learn ada pada bagian paling kiri bawah:

![[Clion Untuk Debugger-25.png]]

Terdapat 2 pilihan disini, yaitu:

1. Learn IDE Features
	- Fokus: **belajar cara menggunakan CLion itu sendiri**.
	- Isinya berupa tutorial interaktif tentang fitur-fitur IDE, misalnya:
	    - Navigasi kode (jump to definition, search symbol, dll.).
	    - Refactoring (rename, extract method, dsb.).
	    - Debugging dengan breakpoint dan variable inspector.
	    - Menggunakan shortcut keyboard.
	- Intinya: mengajarkan **skill memakai CLion** agar kerja lebih efisien.

2. Learn to Program
	- Fokus: **belajar dasar-dasar pemrograman**.
	- Biasanya berupa kursus interaktif bawaan JetBrains Academy (Hyperskill).
	- Materinya lebih ke **logika pemrograman & bahasa tertentu**, bukan IDE.
	    - Misalnya belajar Python, Java, Kotlin, atau konsep algoritmik dasar.
	- Intinya: untuk pemula yang benar-benar ingin belajar "ngoding dari nol", bukan sekadar belajar pakai IDE.

Perbedaan utama:

- **Learn IDE Features** → belajar **cara pakai CLion**.
- **Learn to Program** → belajar **cara ngoding** (materi programming).

Selain itu, juga terdapat pilihan Help & Resources, yang mana menyediakan link, dengan tujuan untuk:

1. Help
	- Mengarahkan kita ke situs [dokumentasi Clion](https://www.jetbrains.com/help/clion/2025.2/installation-guide.html?top&keymap=Windows). Berisi banyak panduan berguna jika semisal ingin mengetahui lebih banyak tentang Clion, atau menemui masalah ketika menggunakan Clion.

2. Getting Started
	- Berisi panduan untuk pemula, yaitu [step-by-step tutorial](https://www.jetbrains.com/clion/learn/) bagi pemula maupun ahli, untuk memulai menggunakan Clion, dan memaksimalkan penggunaanya.

3. Clion on Youtube
	- Mengarahkan kita ke panduan Clion dalam format video, bagi yang lebih suka dengan penjelasan video. Masuk ke situs youtube dengan [playlist Clion](https://www.youtube.com/playlist?list=PLQ176FUIyIUZtuh8zmT0lmcjsImnrDSmG), terdapat sekitar 31 video panduan ketika dokumentasi ini dibuat.

4. Keyboard Shortcut PDF
	- File PDF untuk setiap shortcut yang ada pada Clion yang bisa digunakan untuk mempercepat produktivitas. File PDF ada di [[Clion Shortcuts PDF.pdf]].

5. Tip of the Day
	- Berisi Tips Trick menggunakan Clion, setiap kita mengklik link ini, akan muncul tips berbeda-beda, sangat membantu jika ingin belajar sedikit demi sedikit, tanpa terlalu terbebani banyaknya fitur.

Nah, untuk benar-benar mampu mengeluarkan semua kekuatan dari Clion, aku sangat merekomendasikan untuk memulai belajar menggunakan Clion dari panduan yang disediakan oleh opsi `Help` dan `Learn IDE Features`:

![[Clion Untuk Debugger-26.png]]

Ketika memilih opsi Help, maka kita akan dibawa ke [dokumentasi resmi Clion](https://www.jetbrains.com/help/clion/2025.2/installation-guide.html?top&keymap=Windows), tempat inilah kita bisa belajar menggunakan fitur-fitur Clion secara maksimal:

![[Clion Untuk Debugger-27.png]]

Nah, untuk opsi `Learn IDE Features`, bagus jika kita sudah membaca panduan dokumentasi sebelumnya, dan ingin belajar dengan praktek. Maka panduan Learn IDE Features akan sangat membantu, karena panduan ini akan memberikan kita simulasi singkat tentang bagaimana menggunakan fitur-fitur yang ada di Clion dengan lebih jelas. Klik saja `Start Learning`, dan selamat mengikuti tutorial singkat yang disediakan:

![[Clion Untuk Debugger-28.png]]

Dari gambar diatas, aku sudah menyelesaikan semua tutorial yang diberikan. Terkadang ada beberapa tutorial yang stuck, atau ada sedikit bug sehingga tidak bisa menyelesaikan tutorial tertentu hingga complet. Tapi yang penting, baca saja step-by step tutorial yang diberikan hingga paham. 

Info saja, tutorial ini sebenarnya berasal dari plugin **IDE Features Trainer**, bisa dilihat di panduan selanjutnya yang membahas **Plugin**.

<br/>

Nah, dibagian selanjutnya, kita akan mencoba fitur dari `Learn to Program`, klik `Enable Access`, dan tunggu loading sebentar:

![[Clion Untuk Debugger-29.png]]

Maka kamu akan dibawa ke tampilan seperti ini:

![[Clion Untuk Debugger-30.png]]

Disini, kita bisa memilih tutorial yang kita inginkan, cari saja yang dirasa perlu, jika memang ingin belajar dari basic. Tapi beberapa materi membutuhkan login ulang, entahlah, mungkin tutorial ini terhubung ke tutorial course pihak ketiga. Jadi, ikuti saja arahan dari tutorial atau course yang diberikan.

## 4.2 | Plugins

Pada bagian plugins, biasanya akan ada beberapa plugins awal yang terpasang secara default ketika pertama kali memasang Clion, bahkan tutorial sebelumnya yang kita ikuti, juga berasal dari plugin juga.

Karena beberapa plugins tidak ada hubungna dengan C++, seperti plugins python, HTML, CSS, Javascript, Node JS, dan sejenisnya, maka kita bisa disable plugin-plugin tersebut. Ini berguna supaya Clion kita menjadi lebih ringan.

Masuk saja pada jendela `installed`, dan disable beberapa plugin yang tidak akan digunakan:

![[Clion Untuk Debugger-31.png]]


Sebagai gantinya, kita bisa memasang beberapa plugin lain yang lebih berguna, dengan masuk ke pilihan `Marketplace`, lalu pilih plugin seperti:
- Rainbow Brackets
- Onedark Theme
- dll.

Oh ya, setiap perubahan pada settingan plugin, baik itu menambahkan, menghapus, mengaktifkan atau menonaktifkan, butuh restart IDE. Jadi, setelah melakukan beberapa pengeditan di plugins, restart terlebih dahulu Clion untuk menerapkan perubahanya.

## 4.3 | Customize

Pada menu customize, ada beberapa opsi yang tersedia.

Opsi `theme`, bisa terang atau gelap, atau sesuaikan dengan theme dari operating system kita. Karena aku suka coding dimalam hari, maka aku lebih suka theme **Dark**.

Pada bagian `Editor Color Scheme`, kita bisa mengedit color scheme dari editor kita. Ini berbeda dengan theme IDE secara keseluruhan, karena ini adalah style pada warna font dari kode program yang kita tulis. Secara default, opsi ini tidak bisa dipilih, melainkan kita harus mengimport file color scheme secara manual.

Pada CLion, menu Editor → Color Scheme digunakan untuk mengatur skema warna (syntax highlighting) yang tampil di dalam editor kode. Pengaturan ini tidak memengaruhi tema keseluruhan tampilan IDE, melainkan hanya pewarnaan elemen-elemen kode di editor.

Beberapa contoh elemen yang dikendalikan oleh _color scheme_ antara lain:

- **Keyword**: misalnya `if`, `while`, `return`
- **Identifier**: seperti nama kelas, fungsi, dan variabel
- **Komentar**: teks komentar dalam kode
- **Literal**: seperti string atau angka
- **Error dan Warning**: garis bawah atau warna khusus untuk menandai kesalahan

Jadi, bagian ini kita biarkan saja. 

Jika semisal ingin mencari theme yang ingin kita pasang, masuk saja ke bagian plugins, dan cari theme yang sesuai, seperti tampilan dibawah ini:

![[Clion Untuk Debugger-32.png]]

Setelah install beberapa theme, restart dulu IDE nya untuk menerapkan perubahan. Jika sudah, oke lanjut... 😀

Pada menu Language and Region, `Language` kita pilih saja **English**, lagipula bahasa Indonesia juga tidak tersedia disini. Dan `Region`, kita pilih saja **Asia (Except China Mainland)**.

Pada bagian Accessibillity, kita bisa mengatur `IDE font`, atau ukuran dari font di IDE. Jika ukuran default sudah nyaman, yaitu ukuran 13, maka tidak perlu dirubah. Jika kurang nyaman, silahkan dirubah, sesuai kenyamanan dan selera.

Lalu ada juga opsi `Adjust Colors for Red-Green Vision Deficiency`.

Fitur ini digunakan untuk menyesuaikan skema warna sehingga lebih ramah bagi pengguna dengan **buta warna merah-hijau (red-green color blindness)**. Kondisi ini adalah bentuk umum dari _color vision deficiency_ yang membuat penderitanya sulit membedakan warna merah dan hijau.

Ketika opsi ini diaktifkan, CLion akan:

- Menyesuaikan warna dalam skema agar tetap memiliki **kontras tinggi** dan **mudah dibedakan**, meskipun spektrum merah-hijau sulit dikenali.
    
- Menghindari penggunaan kombinasi warna merah dan hijau sebagai indikator utama (misalnya untuk error vs success).
    
- Memastikan informasi penting tetap dapat dibedakan dengan **perbedaan bentuk, garis bawah, atau intensitas warna**.

Tapi, karena aku tidak buta warna, maka tidak perlu dichecklist, biarkan saja 😀.

Terakhir, opsi `Keymap`, kita pilih Windows saja, ini tidak perlu dirubah-rubah lagi. 

Jadi, opsi di customize kita, sekarang adalah seperti ini:

![[Clion Untuk Debugger-33.png]]

## 4.4 | Remote Development

![[Clion Untuk Debugger-34.png]]


**Remote Development** adalah fitur di CLion yang memungkinkan proses pengembangan perangkat lunak dilakukan pada **lingkungan jarak jauh (remote environment)**, sementara antarmuka IDE tetap berjalan secara lokal di komputer pengguna.

Dengan fitur ini, pengguna dapat:

1. **Menggunakan mesin jarak jauh** (misalnya server Linux atau mesin virtual) untuk melakukan kompilasi, debugging, dan eksekusi kode.
    
2. **Menghemat sumber daya lokal**, karena proses yang berat (kompilasi proyek besar, build toolchain, dsb.) dijalankan di remote server.
    
3. **Memanfaatkan lingkungan pengembangan khusus**, misalnya ketika proyek membutuhkan dependensi, library, atau sistem operasi tertentu yang berbeda dari mesin lokal.


CLion menyediakan beberapa mode utama:

- **Full Remote Mode**: IDE dijalankan sepenuhnya pada server, dan pengguna mengaksesnya melalui _thin client_ atau JetBrains Gateway.
    
- **Remote Toolchains**: hanya toolchain (compiler, debugger, CMake, dsb.) yang berada di mesin jarak jauh, sementara editor tetap berjalan lokal.
    
- **WSL (Windows Subsystem for Linux)**: khusus pengguna Windows, memungkinkan CLion memanfaatkan Linux environment yang tersedia melalui WSL.
    
- **Docker / Remote Containers**: CLion dapat menggunakan container sebagai lingkungan build dan debugging.
    

Kegunaan dari opsi ini adalah:

- Mendukung pengembangan pada **proyek berskala besar** yang tidak efisien dijalankan di mesin lokal.
    
- Memungkinkan **kolaborasi** dengan lingkungan build standar di server tim atau perusahaan.
    
- Meningkatkan fleksibilitas, karena developer dapat menggunakan perangkat keras lokal yang ringan, tetapi tetap bekerja dengan environment yang kompleks di sisi remote.
    

Tapi, karena kita tidak sedang bekerja dengan remote development, maka tidak perlu kita utak-atik bagian ini. KIta tidak sedang berurusan dengan pekerjaan remote development kan 😀.

## 4.5 | Project

![[Clion Untuk Debugger-35.png]]

Nah, pada bagian ini, sepertinya aku harus membuat panduan yang terpisah, karena dibandingkan yang lain, menu inilah yang paling penting, sekaligus yang paling kompleks diantara menu pembukaan sebelumnya. 

Jadi, pelajari menu ini di dokumentasi terpisah!


