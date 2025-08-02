---
obsidianUIMode: preview
note_type: Dokumentasi
judul_dokumentasi: Setup Terminal Alacritty
date_add: 2025-08-02T14:22:00
status_dokumentasi: ✅Finish
tags:
  - neovim
  - vim
  - lazyvim
---
---
# 1 | Apa itu Alacritty?

## 1.1 | Apa Itu Terminal Alacritty?

Alacritty adalah terminal emulator modern yang dibangun dengan Rust. Tujuannya sederhana: menghadirkan pengalaman terminal secepat mungkin dengan memanfaatkan GPU untuk rendering teks. Alih-alih menambahkan fitur bawaan seperti tab atau split, Alacritty memilih berfokus pada:

- **Kecepatan**: Menangani ribuan baris output tanpa lag.
    
- **Kesederhanaan**: Konfigurasi hanya melalui satu file TOML.
    
- **Portabilitas**: Satu kode untuk Windows, macOS, dan Linux.
    

Pengembangnya mengadopsi prinsip “*do one thing and do it well*,” sehingga Alacritty sering menjadi pilihan utama pengguna Neovim atau tmux yang menginginkan terminal minimalis namun bertenaga.

<br/>

---
## 1.2 | Mengapa Memilih Alacritty

1. **Performa GPU-Accelerated**  
    Banyak terminal mengerjakan rendering di CPU—Alacritty memindahkannya ke GPU sehingga frame rate stabil dan input terasa responsif.
<br/>

2. **Konfigurasi Terpusat**  
    Semua opsi (font, warna, key binding) disimpan di `alacritty.toml`. Tidak ada GUI yang memecah-pecah; cukup satu berkas teks.
<br/>

3. **Ringan & Konsisten**  
    Tanpa ekstensi bawaan, Alacritty hampir tidak pernah menimbulkan overhead memori. Hasilnya konsistensi perilaku di berbagai platform.
<br/>

4. **Integrasi Ekosistem**  
    Dirancang untuk bersinergi dengan tmux, Neovim, dan tools CLI lain—tanpa “fitur ganda” yang justru mempersulit.

<br/>

---

## 1.3 | Perbandingan Dengan Terminal Lain

|Aspek|Alacritty|Windows Terminal|iTerm2 (macOS)|GNOME Terminal|
|---|---|---|---|---|
|**GPU Rendering**|Ya|Ya (terbatas)|Ya|Tidak|
|**Konfigurasi**|File TOML (manual)|JSON + GUI|GUI + plist|GUI|
|**Tab / Split Bawaan**|❌ (gunakan tmux)|✅|✅|✅|
|**Performa**|Sangat cepat, frame-rate|Cepat|Cepat|Cukup|
|**Cross-Platform**|Windows, Linux, macOS|Windows|macOS|Linux|
|**Ekstensi / Plugin**|❌|Terbatas (settings)|Banyak (scriptable)|Terbatas|

> **Catatan:** Alacritty tidak menyediakan UI tab/split agar tidak berkompetisi dengan terminal multiplexer seperti tmux atau screen.

<br/>

---
## 1.4 | Kenapa Alacritty untuk Neovim?

Alacritty menjadi pilihan ideal untuk pengguna Neovim berkat kombinasi kinerja tinggi dan integrasi seamless:

- **Kecepatan dan Responsivitas**: Rendering GPU memastikan distribusi output Neovim (misal pada penggunaan :terminal, plugin, atau pencetakan log) tetap halus bahkan dalam buffer besar.
<br/>

- **Konfigurasi Singkat**: File `alacritty.toml` memungkinkan penyesuaian key binding (seperti mapping `Ctrl+Shift+T` untuk membuka tab Neovim) tanpa tumpang tindih konfigurasi Neovim.
<br/>

- **Dukungan True Color**: Menjamin tema dan skema warna Neovim (gruvbox, onedark, dsb.) tampil akurat.
<br/>

- **Tidak Ada Fitur Redundan**: Alacritty menyerahkan manajemen jendela (splits, tabs) ke Neovim atau tmux—menghindari konflik keyboard shortcut.
<br/>

- **Kompatibilitas dengan Plugin Neovim**: Banyak plugin (seperti nvim-toggleterm atau neoterm) berfungsi mulus dalam terminal yang konsisten.
<br/>

---
<br/>

# 2 | Setup Alacritty

## 2.1 | Install Alacritty

Sebelum melakukan konfigurasi terhadap Alacritty, tentu saja kita harus install dan pasang Alacrity terlebih dahulu. Ada beberapa cara untuk memasang alacritty.

### Web resmi

Cara pertama, adalah kita mengunjungi situs aslinya, yaitu [Alacritty.org](https://alacritty.org/), lalu pilih varian Alacritty yang sesuai dengan device kita, seperti Mac Os, Linux, atau Windows. 

![[Setup Terminal Alacritty-1.png]]

Jika kamu menggunakan windows, akan ada 2 pilihan lagi, yaitu menggunakan `installer.msi` atau `portable.exe`. Jika ingin langsung pasang dengan mudah, misal dengan installer dan langsung next-next saja, ambil `installer.msi`. Tapi kalau semisal ingin menggunakan Alacritty yang bisa disimpan di flash disk, dan menjadikanya portable bisa dibuka di banyak sesama device windows, bisa unduh `portable.exe`. 

Oke, kita ambil installer.msi karena kita ingin memasangnya untuk device kita sendiri. Ukuran Alacritty cukup kecil, jadi proses pengunduhan tidak akan memakan waktu lama.

Setelah itu, pasang Alacritty dengan menjalakan installer.msi, dan lakukan pemasangan seperti pada umumnya (next-next aja 😅), maka Alacritty pun berhasil terpasang.


### Melalui scoop

Untuk menginstal **Alacritty** dengan **Scoop** di Windows, ikuti langkah-langkah berikut:

1. Pastikan Scoop sudah terinstal
   Buka PowerShell dan jalankan:

	```powershell
	Set-ExecutionPolicy RemoteSigned -scope CurrentUser
	irm get.scoop.sh | iex
	```

2. Tambahkan bucket `extras`

	Alacritty berada di bucket `extras`, jadi tambahkan dulu:

	```powershell
	scoop bucket add extras
	```

3. Instal Alacritty

	Setelah bucket `extras` ditambahkan:

	```powershell
	scoop install alacritty
	```
	
	Setelah selesai, kamu bisa jalankan `alacritty` dari terminal manapun.

<br/>

---
## 2.2 | Persiapan Setup Alacritty

Setelah Alacritty berhasil terpasang, coba buka terminal tersebut, dengan cara melakukan pencarian pada pencarian aplikasi, misal tekan key Windows, lalu cari "Alacritty". Jika terinstall dengan benar, maka akan tampil sepeti ini:

![[Setup Terminal Alacritty-2.png]]

Jika dibuka, maka tampilanya seperti ini:

![[Setup Terminal Alacritty-3.png]]

Ini artinya alacritty kita sudah berhasil terpasang dengan benar. Sekarang kita bisa lanjut.

Jika pada terminal Windows Powershell, kita bisa merubah font, mengatur opacity, dan banyak macam settingan lain, maka di Alacritty pun juga demikian. Perbedaanya adalah, jika di windows terminal menyediakan settingan berbasis GUI, pada Alacritty, untuk bisa memberi konfigurasi setup yang kita inginkan di terminal Alacritty, kita harus melakukanya manual dengan membuat dan mengkonfigurasi file via `alacritty.toml`.

Sebelum bergerak lebih jauh, mungkin penting untuk tetap up to date dengan pembaruan dari Alacritty, dan macam-maca cara mengkonfigurasi Alacritty yang kita pasang. Oleh karena itu, kunjungi repository Github dari [Alacritty Github](https://github.com/alacritty/alacritty):

![[Setup Terminal Alacritty-4.png]]

Nah, disebutkan sebelumnya bahwa untuk melakukan setup pada terminal Alacritty, kita perlu mengkonfigurasi file `alacritty.toml`. Jadi, dimana lokasinya?

Lokasi dari file `alacritty.toml`, jika di windows berada di path directory berikut:

```bash
C:\Users\ASUS\AppData\Roaming\alacritty
```

Namun, ada beberapa kasus dimana folder tersebut tidak terbuat secara otomatis, sehingga kitalah yang perlu membuatnya secara manual. Cukup masuk ke alamat:

```
C:\Users\ASUS\AppData\Roaming\
```

, lalu buat folder `alacritty`, dan buat file toml didalamnya dengan nama `alacritty.toml`. Pastikan penamaan nama folder dan nama file sesuai disini.

Setelah file `alacritty.toml` berhasil terbuat, maka kita bisa memulai setup konfigurasi pada terminal Alacritty via `alacritty.toml`.

> [!NOTE] Apakah Alacritty bisa langsung membaca konfigurasi kita secara otomatis?
> Alacritty **secara otomatis membacanya** saat dijalankan. Tidak perlu konfigurasi tambahan atau pemanggilan lewat flag/opsi tertentu di terminal. Selama filenya valid dan di path yang benar, Alacritty langsung menerapkannya saat startup.

<br/>

---
## 2.3 | Konfigurasi Alacritty

Nah, untuk bisa melakukan konfigurasi dengan benar, kita butuh sumber terpercaya sebagai panduan. Siapa lagi kalau bukan dokumentasi resmi dari Alacritty 😅. Kunjunig [config-alacritty](https://alacritty.org/config-alacritty.html) sebagai panduan untuk melakukan setup dan konfigurasi alacritty kita:

![[Setup Terminal Alacritty-5.png]]

Baiklah, dengan panduan diatas, seharusnya kamu bisa menentukan setup Alacritty sesuai yang kamu inginkan. Membaca dokumentasi itu penting kan 😜.

Untuk konfigurasi yang sudah cukup bagus dan siap digunakan, terutama jika tujuan kamu meenggunakan Alacritty adalah untuk hasil dan tampilan maksimal saat menggunakan Neovim, cukup sederhana. Berikut konfigurasinya:

```toml
[window]
title = "Alacritty"
dynamic_title = false
decorations = "full"
opacity = 0.70
blur = true
startup_mode = "Windowed"  # "Maximized" atau "Fullscreen"

[font]
#normal = { family = "FiraCode Nerd Font Mono", style = "Medium" }
normal = { family = "JetBrainsMonoNL NFM", style = "Bold" }
size = 10.0
builtin_box_drawing = true

[colors.primary]
background = "#000000"
foreground = "#ffffff"

[colors.cursor]
text = "CellBackground"
cursor = "#ffffff"

[env]
TERM = "xterm-256color"

[terminal]
shell = "pwsh"
```


Berikut adalah penjelasan lengkap dan deskriptif untuk setiap blok konfigurasi dalam file `alacritty.toml`. Konfigurasi ini mencerminkan personalisasi terminal Alacritty yang ringan namun fungsional.

### [window]

```toml
title = "Alacritty"
dynamic_title = false
decorations = "full"
opacity = 0.70
blur = true
startup_mode = "Windowed"
```

- `title`: Menentukan judul jendela. Tulisan "Alacritty" akan selalu tampil di title bar. Oh ya, jika kita tidak melakukan pemberian title, maka yang ditampilkan adalah path folder dari lokasi Alacritty di device kita. Itu menjadikan tampilan title bar menjadi kurang elegan, sehingga harus kita setting manual disini.
<br/>

- `dynamic_title`: Jika `false`, judul tidak berubah meskipun direktori atau proses di dalam terminal berubah. Ini membuat tulisan di title bar tetap sama.
<br/>

- `decorations`: Menentukan gaya jendela. "full" berarti ada border, tombol minimize, maximize, dan close.
<br/>

- `opacity`: Mengatur tingkat transparansi jendela terminal. Nilai `0.70` membuat jendela 70% solid dan 30% transparan. Jika diatur ke 1, maka solid penuh, jika diatur ke 0, maka transparan penuh.
<br/>

- `blur`: Jika `true`, area di belakang jendela yang transparan akan tampak buram (blur). Bergantung pada dukungan compositor di OS.
<br/>

- `startup_mode`: Mengatur mode awal saat terminal dibuka. "Windowed" berarti jendela terbuka dengan ukuran default (tidak fullscreen atau maximized).

---
### [font]

```toml
normal = { family = "JetBrainsMonoNL NFM", style = "Bold" }
size = 10.0
builtin_box_drawing = true
```

- `normal.family`: Menentukan jenis font utama. Di sini digunakan "JetBrainsMonoNL NFM" (Nerd Font Mono) untuk kompatibilitas simbol dan ikon.
  
  > [!NOTE] ⚠️
  > Ada sedikit masalah yang cukup sulit diselesaikan saat mengatur font, akan dijelaskan dibagian akhir!


- `normal.style`: Mengatur gaya font. "Bold" digunakan agar teks terlihat lebih tegas.
<br/>

- `size`: Ukuran font, dalam satuan poin. `10.0` adalah ukuran standar yang nyaman.
<br/>

- `builtin_box_drawing`: Jika `true`, Alacritty menggunakan box drawing characters internal untuk tampilan tabel atau UI CLI yang presisi.
    

---

### [colors.primary]

```toml
background = "#000000"
foreground = "#ffffff"
```

- `background`: Warna latar belakang terminal. `#000000` berarti hitam pekat.
    
- `foreground`: Warna teks default. `#ffffff` berarti putih terang.
    

---

### [colors.cursor]

```toml
text = "CellBackground"
cursor = "#ffffff"
```

- `text`: Warna teks saat berada di bawah kursor. Dengan `CellBackground`, teks tersebut menggunakan warna latar sel.
    
- `cursor`: Warna kursor terminal, dalam hal ini putih (`#ffffff`).
    

---

### [env]

```toml
TERM = "xterm-256color"
```

- `TERM`: Variabel lingkungan yang memberi tahu aplikasi jenis terminal yang digunakan. `xterm-256color` berarti dukungan warna penuh (256 warna), penting untuk banyak aplikasi CLI seperti `vim`, `htop`, dan lainnya.
    

---

### [terminal]

```toml
shell = "pwsh"
```

- `shell`: Menentukan shell default saat membuka terminal di dalam Alacritty. `pwsh` berarti menggunakan PowerShell versi terbaru (bukan PowerShell klasik). Pastikan `pwsh` sudah terinstal dan dikenali di PATH.
  
  > [!NOTE] ⚠️
  > Jika belum pasang pwsh, Alacritty akan menggunakan terminal default saat berjalan. Migrasi dari terminal default ke pwsh di Alacritty terkadang terjadi sedikit error. Oleh karena itu, akan dijelaskan cara install pwsh dibagian akhir!

<br/>

---

## 2.4 | Demo Tampilan Alacritty

Berikut hasil akhir dari tampilan Alacritty kita setelah di setup:

![[Alacritty Demonstration - Made with Clipchamp.mp4]]

Nah, bagaimana? Keren kan 😎

Hasil setup tampilan Alacritty kita sekarang sudah tampil menarik, cantik, dan gahar. Siapapun yang melihatnya, pasti akan jatuh cinta pada tampilanya yang elegan.

Alacritty juga membuat navigasi kita lebih cepat, smooth, dan presisi, sangat pas dipadupadankan dengan setup neovim kita. Code editornya saja setup, masa terminalnya tidak disetup 😎.

<br/>

---
# 3 | Kondisi Penting lainya

## 3.1 | Pemilihan Font

Pada saat sesi pemasangan Neovim, aku sudah mengatakan beberapa kali bahwa kita wajib hukumnya memasang font Nerd Font, karena dengan font ini, icon-icon bisa muncul di tampilan terminal.

Mudah memasang dan menggunakan font ini jika kita menggunakan terminal Windows Poweshell, karena tampilan GUI nya mudah dipahami. KIta tinggal masuk ke opsi pengaturan, pilih pengaturan font, dan pilih font Nerd Font yang sudah kita pasang atau install, maka perubahan akan terjadi.

Tapi saat kita menggunakan Alacritty, pemilihan dan konfigurasi font harus dilakukan secara manual, yaitu menulisnya langsung didalam file `alacritty.toml`.

Sebelum memasang dan mengkonfigurasi font, mungkin aku akan memberikan catatan tentang daftar font Nerd Font yang pas untuk penulisan kode, ini hanyalah contoh, karena pada akhirnya, selera ada ditangan masing-masing pengguna.

Berikut daftar font _Nerd Font_ yang bagus dan populer untuk ngoding:

1. **JetBrains Mono Nerd Font**
    
    - Desain modern, spasi nyaman, cocok untuk readability tinggi.
        
2. **FiraCode Nerd Font**
    
    - Populer karena ligatur (simbol gabungan), enak untuk tampilkan operator kompleks.
        
3. **Hack Nerd Font**
    
    - Minimalis, jelas, sangat tajam di ukuran kecil.
        
4. **Iosevka Nerd Font**
    
    - Ramping, rapi, sangat efisien di ruang sempit (cocok untuk terminal split).
        
5. **Cascadia Code Nerd Font**
    
    - Buatan Microsoft, nyaman dibaca, punya ligatur juga.
        
6. **Source Code Pro Nerd Font**
    
    - Stabil, klasik, enak untuk sesi coding panjang.
        
7. **MesloLGS Nerd Font**
    
    - Defaultnya Oh-My-Zsh, bagus untuk terminal dan prompt.
        

Semua tersedia di [https://www.nerdfonts.com/](https://www.nerdfonts.com/). Coba satu per satu sesuai selera dan monitor-mu.

![[Setup Terminal Alacritty-7.png]]

Disini, aku akan memilih JetBrains Nerd Font 😀, karena menurutku, font ini lebih ramping dan cocok dimataku. Terserah kalian mau memilih font yang mana, sesuaikan saja dengan selera kalian. Tapi, untuk membuat panduan ini lebih jelas, aku akan mencontohkan ketika memasang font dari bundle JetBrains Nerd Font.

Masuk ke menu [download](https://www.nerdfonts.com/font-downloads), dan pilih font yang sesuai. Gunakan `Ctrl + f` untuk membuka fitur pencarian text di halaman browser, dan ketik nama font yang ingin dicari. Ini adalah tampilan ketika aku ingin mengunduh JetBrains Nerd Font:

![[Setup Terminal Alacritty-10.png]]

Seperti biasa, download font kesukaan dari situs Nerd Font. Setelah terunduh, ekstrak file ZIP-nya, dan kita akan mendapati ada banyak sekali varian dari font tersebut. Sebagai contoh, ini adalah daftar variasi yang ada dari bundle JetBrains Nerd Font::

![[Setup Terminal Alacritty-11.png]]

Agar bisa melihat jenis-jenis font yang sesuai melalui iconnya, seperti gambar diatas, buat tampilan file di folder menjadi `Large icons`, atau `Extra large icons`! Bisa disetting di pengaturan `view`. Ini berguna supaya kita tidak perlu mengecek satu-satu file installer font, karena dengan cara ini kita jadi tahu gambaran besar seperti apa fontnya. 

Tapi, untuk melihat lebih detail style font-nya seperti apa, kita tetap harus memeriksanya langsung, dengan membuka file installer font tersebut, seperti ini:

![[Setup Terminal Alacritty-12.png]]

Nah, semisal kita membuka file installernya, maka akan muncul gambaran yang lebih detail, style font dari variasi font yang kita pilih. Jika kita merasa cocok dengan style tersebut, tekan saja tombol `install` yang ada di kiri atas.

⚠️ Sebelum menginstall, ada hal yang perlu diperhatikan disini!

Lihat gambar berikut:

![[Screenshot 2025-08-01 221707.png]]

Itu adalah tampilan Alacritty, dengan beberapa baris text yang berantakan. Ketika aku sedang menulis kode dan berganti baris, atau ketika autocomplete box muncul selama sesi menulis kode, maka akan terjadi sedikit kekacauan pada beberapa baris text lain, seperti diatas. 

Text yang mengacak ini sebenarnya hanya sementara, karena saat aku save atau meletakan tick bar di lokasi text yang teracak, textnya akan jadi rapi kembali dengan sendirinya. Namun aku merasa bahwa ini mengganggu pengalaman aku selama sesi coding, dan terkesan aneh dann jelek tampilanya.

Setelah aku cari tahu, ternyata kekacauan ini berasal dari font yang aku pilih. Font yang aku gunakan saat itu adalah `0xProto Nerd Font Propo`. 

Kenapa font ini bisa membuat tampilan Alacritty ku berantakan? Berikut penjelasanya:

---
### Pentingnya Memilih Font yang Sesuai untuk Terminal dan Neovim

Pemilihan font bukan sekadar soal estetika—dalam lingkungan terminal dan editor seperti Neovim, font berperan penting dalam **tata letak teks**, **tampilan plugin**, dan **kenyamanan membaca kode**.

#### 1. Gunakan Font Monospaced

Font **monospaced** berarti setiap karakter memiliki lebar yang sama. Ini penting karena:

- Terminal dan editor menyusun teks dalam grid.
    
- Box drawing (tabel, garis, UI plugin seperti `nvim-tree`) bergantung pada keselarasan karakter.
    
- Fungsi seperti indentasi, highlight baris, dan struktur kode hanya tampil rapi bila jarak antar karakter konsisten.
    

Contoh font monospaced bagus:

- `JetBrainsMono Nerd Font`
    
- `FiraCode Nerd Font Mono`
    
- `Iosevka Nerd Font Mono`

Ciri-ciri font Monospaced adalah adanya kata `Mono` pada nama fontnya. Ini jadi petunjuk bahwa font jenis ini bagus untuk kita pakai sebagai font Alacritty kita 😁. Dimana ketika aku memilih font `JetBrainsMono Nerf Font`, masalah text berantakan diatas akhirnya hilang. 

#### 2. Hindari Font Proporsional

Font **proporsional** memiliki lebar karakter berbeda (misalnya `i` lebih sempit dari `m`), yang menyebabkan:

- Tampilan baris jadi tidak sejajar.
    
- Garis batas tabel tampak putus atau tidak lurus.
    
- Plugin UI berbasis teks jadi kacau.
    

Contoh: `0xProto Nerd Font Propo` adalah font proporsional yang bisa menyebabkan masalah ini. 

Beberapa font yang memiliki kata `Propo` pada penamaan fontnya,  menjadi petunjuk bahwa font tersebut menggunakan gaya Proporsional. Beberapa terminal tidak bisa menampilkan hasil maksimal jika menggunakan font-font jenis proporsional atau `Propo`, sehingga harus lebih berhati-hati ketika menggunakanya.

#### 3. Cek Konfigurasi Terminal

Pastikan juga terminal (misalnya Alacritty) diatur menggunakan font yang **monospaced dan sudah dipatch dengan Nerd Font**. Contoh konfigurasi:

```toml
[font]
normal = { family = "JetBrainsMonoNL NFM", style = "Bold" }
builtin_box_drawing = true
```

<br/>

---

## 3.2 | Pemasangan Font

Setelah memilih font yang ingin kita gunakan, selanjutnya adalah mengaktifkan konfigurainya di `alacritty.toml`. Masuk ke file tersebut, dan tambahkan bagian atau blok ini didalamnya:

```toml
[font]

```

Ini artinya blok yang ada dibawahnya akan menjadi tempat konfigurasi font kita. Setelah itu siapkan baris berikut dibawahnya:

```toml
[font]
normal = { family = "", style = "" }
size = 
builtin_box_drawing = 
```

### Penjelasan konfigurasi toml

`[font]` — Pengaturan Font di Alacritty

Bagian ini menentukan tampilan teks pada terminal. Pemilihan font yang tepat sangat penting untuk kenyamanan membaca dan kejelasan tampilan simbol, terutama saat digunakan untuk coding dan development.

`normal = { family = "", style = "" }`

- **`family`**: Nama font utama yang digunakan. Ini sebaiknya diisi dengan font monospaced (lebar karakter tetap) agar tampilan rapi. Contoh: `"JetBrainsMono Nerd Font"`, `"FiraCode Nerd Font Mono"`, dll.
    
- **`style`**: Gaya font yang digunakan, seperti `"Regular"`, `"Bold"`, `"Medium"`. Pastikan gaya tersebut tersedia pada font yang dipilih.
    

**Contoh penggunaan**:

```toml
normal = { family = "JetBrainsMono Nerd Font", style = "Bold" }
```

---

`size =`

- Ukuran font dalam satuan poin. Umumnya berkisar antara 9.0 hingga 14.0 tergantung ukuran layar dan preferensi visual pengguna.
    

**Contoh**:

```toml
size = 10.5
```

---

`builtin_box_drawing =`

- Bila `true`, Alacritty menggunakan rendering internal untuk karakter box-drawing (seperti garis pada tabel/terminal) daripada mengandalkan glyph dari font.
    
- Ini sangat membantu ketika font yang digunakan memiliki rendering buruk untuk karakter garis atau kotak.
    

**Saran**: Aktifkan (`true`) jika sering melihat garis tabel yang rusak atau tidak rata.

**Contoh**:

```toml
builtin_box_drawing = true
```

---

Catatan Tambahan

- Gunakan font **Nerd Font** yang bersifat **monospaced**, bukan **proportional**, agar simbol seperti panah, box, atau indentasi tampil sejajar dan tidak berantakan.
    
- Jika memakai font "proporsional", seperti `0xProto`, karakter akan memiliki lebar berbeda dan bisa menyebabkan kerusakan tampilan, terutama di coding environment seperti Neovim.
    

### Mengetahui nama font

Nah, ini adalah bagian yang penting, untuk bisa memberikan nilai font yang sesuai, kita harus mengetahui `family` dari font, dan `style` dari font yang tersedia. Ada beberapa cara yang bisa dilakukan disini.

Pertama cek terlebih dahulu apakah font yang kita pasang, sudah benar-benar terpasang, caranya dengan masuk ke directoy `C:\Windows\Fonts`. Maka tampilanya kurang lebih seperti ini:

![[Setup Terminal Alacritty-13.png]]

Cari font yang kita pilih apakah sudah terinstall atau belum.

Atau, gunakan `Windows + r`, lalu masukan `control fonts`, maka kita akan dibawa masuk ke settingan, yang mana masuk ke:

Setting -> personalization -> Fonts

![[Setup Terminal Alacritty-14.png]]

Cari font yang kita sebelumnya pasang, apakah sudah benar-benar terpasang? 

Jika sudah terpasang, maka tugas selanjutnya adalah dengan memberikan nama yang tepat pada variabel `family` dan `style` pada file toml. Caranya adalah dengan masuk ke settingan font yang sudah kita pasang. Jika posisimu ada di pengaturan diatas, klik font yang ingin digunakan sehingga kita akan dibawa pada tampilan seperti ini:

![[Setup Terminal Alacritty-15.png]]

Nah, penamaan yang tepat ada dibagian ini:

![[Setup Terminal Alacritty-16.png]]

Atau, bisa dibuka langsung di file installer font yang sudah kita pasang, dimana terletak di bawah kiri atas, seperti ini:

![[Setup Terminal Alacritty-17.png]]


Satu kata terakhir dari nama font, biasanya digunakan untuk memberikan petunjuk style dari font. Sehingga, didapat bahwa nama dan style dari font ini, adalah sebagai berikut:

```toml
normal = { family = "JetBrainsMonoNL NFM", style = "Bold" }
```

Sehingga konfigurasi font kita, fullnya menjadi seperti ini:

```toml
normal = { family = "JetBrainsMonoNL NFM", style = "Bold" }
size = 10.0
builtin_box_drawing = true
```

Restart Alacritty, dan taraaa, font sudah berubah menjadi lebih bagus 😀.

<br/>

---

## 3.3 | Memasang pwsh

Apa itu pwsh?

`pwsh` adalah **PowerShell versi terbaru**, yaitu **Powershell 7** yang merupakan **shell command-line dan bahasa scripting** buatan Microsoft. Versi ini berasal dari **PowerShell Core** (mulai dari versi 6 ke atas), dan berbeda dari PowerShell lama bawaan Windows (`powershell.exe`), karena:

|Keterangan|PowerShell Lama (`powershell.exe`)|PowerShell Baru (`pwsh`)|
|---|---|---|
|Platform|Windows saja|Cross-platform (Windows, Linux, macOS)|
|Binary|`powershell.exe`|`pwsh.exe`|
|Kecepatan dan fitur|Lebih berat, fitur lama|Lebih ringan, fitur modern|
|Dukungan|Maintenance|Aktif dikembangkan|

Kenapa `pwsh` penting?

- Bisa digunakan lintas sistem (misal: di server Linux).
- Cocok untuk pengaturan `shell` di terminal modern seperti Alacritty, WezTerm, dll.
- Mendukung skrip dan otomatisasi modern.

Nah, karena alasan inilah, kita perlu memasang pwsh 😀, untuk memaksimalkan pengalaman kita menggunakan terminal Alacritty.

Ingat lagi, bahwa Alacritty adalah terminal emulator, bukan terminal sendiri.

Alacritty adalah **aplikasi grafis** yang menampilkan antarmuka terminal. Ia hanya menjalankan shell yang kamu pilih di dalamnya, seperti:

- `cmd` (Command Prompt)
- `powershell.exe`
- `pwsh` (PowerShell Core)
- `bash`, `zsh`, `fish` (di Linux/Mac)

 Analogi singkat:
- **Alacritty** = Jendela terminal (panggungnya)
- **Shell (seperti `pwsh`)** = Aktor yang tampil di panggung itu

Jadi kalau tampilan terminalmu pakai `pwsh`, itu karena Alacritty menjalankan shell tersebut di dalam dirinya.

### pwsh tidak sama dengan powershell
Walaupun powershell dan pwsh tampak mirip, sebenarnya mereka berdua berbeda. Jika kamu mendapatkan pesan seperti ini di windows powershell / terminal:

```bash
Windows PowerShell
Copyright (C) Microsoft Corporation. All rights reserved.

Install the latest PowerShell for new features and improvements! https://aka.ms/PSWindows

PS C:\Users\ASUS>
```

Itu artinya kita sedang membuka powershell biasa. Bahkan tampak ada tulisan yang meminta kita untuk masuk link tertentu, yang mana jika kamu belum tahu, link tersebut sebenarnya mengarahkan kita ke laman pengunduhan **pwsh** 😅, karena memang versi itu lebih bagus, dan kita disarankan untuk memasangnya. 

![[Setup Terminal Alacritty-19.png]]

Nah, lalu bagaimana tampilan kalau terminal yang kita buka adalah pwsh? Nanti akan ditunjukan dibawah 😀.
### Memasang pwsh

Ada beberapa cara memasang pwsh. Cara pertama adalah dengan masuk ke situs aslinya. Yaitu laman web pengunduhan pwsh, yang tampilanya seperti gambar sebelumnya, ketika kamu mengklik link yang muncul di Windows Powershell.

Tekan tombol `Download PowerShell`, dan kamu akan dibawa ke halaman repository asli [Github pwsh](https://github.com/PowerShell/PowerShell/releases/tag/v7.5.2) berikut:

![[Setup Terminal Alacritty-20.png]]

Gulir kebawah hingga ke bagian `assets`, dan pilih installer yang sesuai dengan operating system yang kamu pakai, tampilanya kurang lebih seperti ini:

![[Setup Terminal Alacritty-21.png]]

Jika kamu menggunakan Windows, pilih saja installer untuk Windows, yang ada kata `win` didalam nama assets nya. 

![[Setup Terminal Alacritty-22.png]]

Pilih installer msi kalau pengin cepet, atau file ZIP jika mau ektrak manual, terserah kamu.

Nah, jika cara diatas terlalu ribet, ada cara kedua...

Cara memasang kedua ini lebih mudah, kita cukup masuk ke Microsoft Store, dan cari di pencarian key berupa "pwsh ". Pilih powershell, dan sekarang kita akan dibawa pada tampilan seperti ini:

![[Setup Terminal Alacritty-18.png]]

Jika belum terpasang, install atau `Get` terlebih dahulu. Tunggu hingga proses pengunduhan selesai. 


Jika sudah selesai, kita periksa apakah pwsh sudah berhasil terpasang, dengan cara melakukan pencarian aplikasi "pwsh" di pencarian aplikasi:

![[Setup Terminal Alacritty-23.png]]

Atau dengan mengetikan "pwsh" pada terminal:

![[Setup Terminal Alacritty-24.png]]

Jika berhasil terpasang, maka akan muncul versi pwsh-nya.

Oke, sekarang kita berhasil memasang terminal terbaru, yaitu pwsh 😀.

<br/>

---
## 3.4 | Konfigurasi pwsh ke Alacritty

Di file konfigurasi `alacritty.toml`, tambahkan kode ini:

```toml
[terminal]
shell = "pwsh"
```

Kita menset agar Alacritty menggunakan pwsh sebagai terminal utamanya. 

Setelah perubahan, restart Alacritty. 

Jika ada pesan kesalahan, yang meminta kita untuk mengetikan `alacritty migrate`, lakukan saja. Ini berguna untuk secara otomatis memperbarui konfigurasi ke versi terbaru. Caranya restart Alacritty, lalu di terminal Alacrity langsung ketik perintah berikut, lalu enter:

```bash
alacritty migrate
```

Setelah itu restart lagi Alacritty kita. 

Konfigurasi berhasil, jika tampilan Alacritty kita adalah seperti ini:

![[Setup Terminal Alacritty-25.png]]

Pada tampilan diatas, ada tulisan yang menunjukan bahwa kita membuka powershell versi 7, yang tidak lain adalah pwsh. Ini artinya konfigurasi kita berhasil 😀.
