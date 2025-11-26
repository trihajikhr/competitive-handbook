---
obsidianUIMode: preview
note_type: Dokumentasi
judul_dokumentasi: Setup Terminal Untuk Neovim
date_add: 2025-07-26T14:22:00
status_dokumentasi: ✅Finish
tags:
  - neovim
  - vim
  - lazyvim
---
---

# 1 | Setup Terminal Untuk Neovim
Setelah sebelumnya kita melakukan pemasangan dan konfigurasi awal untuk Neovim dengan environtment C++, selanjutnya kita masih bisa melakukan beberapa setup tambahan untuk terminal kita, agar tampilanya menjadi lebih menarik.

Jika kamu melihat ke internet, ada banyak sekali setup-setup Neovim dari pengguna lain yang tampak sangat cantik dan menarik 😊, seperti ini contohnya:

![[02-Setup Terminal Untuk Neovim-1.png]]

![[02-Setup Terminal Untuk Neovim-2.png]]

![[02-Setup Terminal Untuk Neovim-3.png]]
![[02-Setup Terminal Untuk Neovim-4.png]]


![[02-Setup Terminal Untuk Neovim-5.png]]

![[02-Setup Terminal Untuk Neovim-6.png]]

![[02-Setup Terminal Untuk Neovim-7.png]]


![[02-Setup Terminal Untuk Neovim-8.png]]

![[02-Setup Terminal Untuk Neovim-9.png]]


![[02-Setup Terminal Untuk Neovim-10.png]]


![[02-Setup Terminal Untuk Neovim-11.png]]


![[02-Setup Terminal Untuk Neovim-12.png]]


Nah, disini kita akan melakukan beberapa tambahan setup dan konfigurasi, agar tampilan Neovim kita menjadi cantik, menarik, memanjakan mata 😀, dan membuat siapapun yang melihatnya akan berpikir bahwa kita bukan sembarang programmer hahah..

Tapi serius, jika kita memang menggunakan Neovim dan bisa melakukan banyak setup yang membuat tampilan Neovim kita menjadi terlihat menarik, kita sudah bukan lagi programmer biasa, yang hanya install code-editor atau IDE yang sudah lengkap dengan paket-paketnya. Karena di Neovim, kita harus setup semuanya secara manual. Walaupun sulit diawal, namun jika ditekuni dengan komitmen, maka kita pasti akan bisa mensetup dan mampu mengkonfigurasi Neovim kita, tidak lagi sekedar copy-paste konfigurasi dari orang lain 😎.

Nah, untuk bisa melakukan banyak setup seperti gambar-gambar diatas, sebelum kita menyentuh konfigurasi plugins, kita perlu setup terminal kita terlebih dahulu. 


---
<br/>

## 1.1 | Memilih Terminal Yang Tepat

Jika kita menggunakan windows, maka akan ada dua pilihan bagi kita, yaitu memilih antara Windows Powershell, Command Prompt, atau terminal eksternal lain yang kita pasang, misalnya seperti Alacrity, Kitty terminal, dan lain-lain.

Supaya kita bisa memilih terminal yang tepat, kita perhatikan perbandingan berikut, karena pemilihan terminal punya pengaruh besar ke pengalaman kita ketika memakai Neovim, khususnya untuk:

- Transparansi / efek estetika
- Rendering font (nerd font, ligatures)
- Dukungan true color & mouse
- Kompabilitas dengan plugin-plugin Neovim, seperti floating window, telescope, dsb.


Berikut penjelasan dari masing-masing terminal di Windows buat keperluan _setup tampilan Neovim_:

### 1 | PowerShell / Cmd (via `cmd.exe` atau `powershell.exe`)

![[02-Setup Terminal Untuk Neovim-13.png]]


- **Kelebihan**:
    
    - Pre-installed.
    - Bisa langsung dipakai tanpa install tambahan.
        
- **Kekurangan**:
    
    - Buruk untuk tampilan Neovim:
        
        - Tidak support true color dengan baik.
            
        - Tidak support transparansi.
            
        - Tidak nyaman untuk nerd fonts dan ligatures.
            
        - Kadang rendering UI Neovim tidak rapi (misal garis `│`, `─`).
            

🔻 **Verdict:** **Kurang ideal**, sebaiknya dihindari untuk Neovim.

### 2 | Windows Terminal / Windows Powershell 

![[02-Setup Terminal Untuk Neovim-14.png]]

> Ini terminal modern dari Microsoft. Bisa membuka tab/tab split untuk PowerShell, CMD, WSL, dll.

- **Kelebihan**:
    
    - True color & transparansi 
        
    - Sangat bagus untuk tampilan plugin-plugin Neovim (misal: `telescope`, `lualine`, dsb).
        
    - Support ligature, nerd font, emoji 
        
    - Customizable banget (via `settings.json`):
        
        - Warna, font, padding, efek blur.
            
- ⚠️ **Catatan**:
    
    - Pastikan `settings.json` diatur agar pakai font seperti `FiraCode Nerd Font`, `JetBrainsMono Nerd Font`, dll.
        

🔷 **Verdict:** **Rekomendasi kuat!** Cocok untuk pengguna Windows yang ingin tampilan Neovim bagus.

### 3 | Alacritty

![[02-Setup Terminal Untuk Neovim-15.png]]


> Terminal cross-platform berbasis GPU. Ringan dan cepat.

- **Kelebihan**:
    
    - Super ringan & cepat (GPU accelerated).
        
    - True color, transparansi, nerd font, ligatures.
        
    - UI-nya minimalis dan tajam.
        
- **Kekurangan**:
    
    - Tidak punya GUI settings → semua config harus lewat file `alacritty.yml`.
        
    - Tidak built-in tab/multi-pane (harus pakai tmux kalau mau split/tab).
        

🔷 **Verdict:** Pilihan terbaik untuk **kamu yang suka terminal minimalis dan cepat**.


###  4 | WSL Terminal (Windows Subsystem for Linux)

![[02-Setup Terminal Untuk Neovim-16.png]]


> WSL sendiri bukan terminal, tapi shell Linux yang bisa dibuka di berbagai terminal (Windows Terminal, Alacritty, dll).


- **Kelebihan**:
    
    - Menjalankan Neovim di lingkungan Linux asli, sehingga lebih kompatibel dengan tools Unix-like (ripgrep, fd, make, gcc, clang, dsb).
        
    - Bisa langsung install semua CLI tool pakai `apt`, `pacman`, dll.
        
    - Kompatibel penuh dengan plugin-plugin Neovim modern.
        
    - Tersedia berbagai distro (Ubuntu, Debian, Arch, Alpine).
        
- **Kekurangan**:
    
    - Perlu install tambahan (`wsl --install` untuk Windows 11, atau manual setup untuk Windows 10).
        
    - Sedikit lebih berat karena berjalan di virtual layer (meski ringan di WSL 2).
        
    - Akses file sistem Windows (`/mnt/c/Users/...`) lebih lambat daripada file Linux native (`/home/user/...`).
        

🔷 **Verdict:** **Pilihan paling kompatibel** untuk Neovim power user di Windows.

### 5 | Kitty Terminal

![[02-Setup Terminal Untuk Neovim-17.png]]

> Terminal GPU-accelerated mirip Alacritty, tapi dengan lebih banyak fitur built-in.


- **Kelebihan**:
    
    - GPU-accelerated (cepat dan smooth).
        
    - Native support untuk ligatures, nerd font, image preview, hingga remote sync.
        
    - Bisa dikustomisasi dengan config file `kitty.conf`.
        
    - Support tab, window management, scripting (lebih lengkap dari Alacritty).
        
- **Kekurangan**:
    
    - Tidak built-in ke Windows — butuh Cygwin/MSYS/WSL/X11 untuk dijalankan di Windows (tidak native).
        
    - Setup agak rumit di Windows.
        

🔻 **Verdict:** Cocok untuk pengguna **Linux/Mac**. Di Windows, tidak praktis kecuali via WSL/X.


### 6 | Git Bash

![[02-Setup Terminal Untuk Neovim-18.png]]

> Shell berbasis `bash` dari Git for Windows, dengan tampilan terminal sendiri.


- **Kelebihan**:
    
    - Sudah include saat install Git for Windows.
        
    - Familiar untuk pengguna bash/Linux.
        
    - Mendukung beberapa utilitas Unix-like seperti `ls`, `grep`, `make`.
        
- **Kekurangan**:
    
    - Tidak mendukung true color dengan baik.
        
    - Nerd font dan ligatures kadang bermasalah.
        
    - Performanya lebih lambat dari WSL atau terminal native.
        
    - Tidak cocok untuk UI plugin Neovim seperti `telescope`.
        

🔻 **Verdict:** Cocok untuk penggunaan ringan, **tidak ideal untuk tampilan Neovim yang kompleks**.

---
<br/>

## 1.2 | Update Tabel Perbandingan

|Terminal|True Color|Transparan|Nerd Font|Ligature|Customisasi|Berat|Komentar|
|---|---|---|---|---|---|---|---|
|CMD / PowerShell|❌|❌|❌|❌|❌|Ringan|Hindari untuk Neovim|
|Windows Terminal|✅|✅|✅|✅|GUI / JSON|Sedang|Modern, mendukung banyak shell|
|Alacritty|✅|✅|✅|✅|YAML|Super ringan|Minimalis, cepat, perlu tmux|
|WSL (Ubuntu, etc)|✅|✅|✅|✅|Shell Linux|Agak berat|Ideal untuk developer & plugin|
|Kitty|✅|✅|✅|✅|kitty.conf|Sedang|Powerful tapi kurang native di Win|
|Git Bash|⚠️|⚠️|⚠️|❌|Minimal|Ringan|Untuk keperluan Git, bukan Neovim|

---
<br/>

## 1.3 | Kesimpulan Tambahan

- Kalau kamu ingin **kompatibilitas tertinggi + plugin Neovim jalan optimal** → **WSL atau Alacritty + WSL shell**
    
- Kalau kamu ingin **termudah + tampil keren tanpa ribet** → **Windows Terminal dengan PowerShell atau WSL shell**
    
- Kalau kamu pengguna Linux/Mac → **Kitty atau Alacritty sangat cocok**
    
- Hindari Git Bash, CMD, PowerShell klasik kalau kamu mau UI Neovim modern


Nah, disini jelas bahwa pilihan kita adalah 2, yaitu Alacrity, atau Windows terminal. Windows terminal memang jauh lebih mudah untuk disetup, tapi Alacrity jauh lebih ringan untuk digunakan, dan dengan sedikit setup, kita bisa membuat setup atau konfigurasi dari Alacrity menjadi menarik.

Tapi, kekurangan dari Alacrity lumayan berpengaruh disini, dimana alacrity tidak bisa memiliki banyak tab seperti Windows terminal. Padahal kita membutuhkan terminal yang bisa memiliki banyak tab agar bisa membuka banyak Neovim sekaligus.

Jadi, kita ambil saja Windows Powershell / Windows Terminal 😀.

> Kedepanya kita mungkin akan berpindah terminal, sehingga akan ada dokumentasi sejenis! Untuk kali ini, kita akan mendokumentasikan penyiapan setup Neovim dengan Windows Poweshell!
> 
> Lagipula, diluar sana ternyata ada jauh lebih banyak terminal yang belum sempat disebut disini, ada yang lebih cepat, lebih powerfull, dan ada juga yang memiliki beberapa fungionalitas unik tertentu. Jadi, bukan tidak mungkin terminal untuk Neovim kali ini dialihkan ke terminal yang lain kedepanya.


---
<br/>

# 2 | Setup Windows Powershell
Baiklah, sekarang kita memilih Windows Powershell sebagai terminal neovim kita kali ini. Ikuti panduan ini untuk membuat Windows Powershell kita menjadi lebih menarik dan sesuai.

---
<br/>

## 2.1 | Menemukan Opsi Appearence
Untuk bisa mengatur banyak konfigurasi dari Windows Powershell, kita perlu tahu cara masuk ke settingan Appearence. Bagian settingan ini berkontribusi terhadap benyak tampilan Windows Powershell kita, sehingga kita mungkin akan sering bolak-balik ke settingan ini ketika ingin merubah konfigurasi tampilan terminal kita yang satu ini 😀. Baiklah, pertama-tama, masuk ke settingan terlebih dahulu:

![[02-Setup Terminal Untuk Neovim-19.png]]

Masuk ke menu `Settings`, maka kita akan mendapati tampilan dan menu seperti ini:

![[02-Setup Terminal Untuk Neovim-20.png]]

Pada bagian atas kanan, yaitu bagian `Default profile`, kita pilih Windows Powershell, supaya pas kita mengetikan terminal pada windows, maka powershell lah yang akan dibuka, karena dia disetting sebagai default.

Pada bagian kiri bawah, tepatnya di bagian *profiles*, kita pilih `Windows Powershell`, karena kita akan melakukan konfigurasi pada Windows Powershell:

![[02-Setup Terminal Untuk Neovim-21.png]]

Pada bagian ini, gulir kebawah hingga menemukan 3 menu, lalu kita pilih `Appearence`:

![[02-Setup Terminal Untuk Neovim-22.png]]

Nahh, ketika kita masuk ke pilihan `Appearence`, maka tampilan kita akan menjadi seperti ini:

![[02-Setup Terminal Untuk Neovim-23.png]]

Inilah bagian menu `Appearence`, ingat baik-baik menu ini oke 😂.

---
<br/>

## 2.2 | Menginstall Font 
Untuk bisa menampilkan icons-icons pada terminal, kita tidak bisa menggunakan font biasa. Kita perlu menggunakan font khusus, yaitu *Nerd-Font*. Oleh karena itu, kita perlu menginstall font [Nerd Font](https://www.nerdfonts.com/) dari situs officialnya:

![[02-Setup Terminal Untuk Neovim-24.png]]

Dibagian `Download`, kamu akan menemukan banyak sekali jenis paket Nerd-Font yang bisa dipilih. Berikut adalah beberapa daftar paket Nerd-Font yang disediakan:

- 0xProto Nerd Font
	
- FiraCode Nerd Font
    
- JetBrainsMono Nerd Font
    
- Hack Nerd Font
    
- MesloLGS Nerd Font
    
- SourceCodePro Nerd Font
    
- UbuntuMono Nerd Font
    
- DejaVuSansMono Nerd Font
    
- RobotoMono Nerd Font
    
- Iosevka Nerd Font
    
- VictorMono Nerd Font
    
- CascadiaCode Nerd Font
    
- DroidSansMono Nerd Font
    
- Mononoki Nerd Font
    
- Inconsolata Nerd Font
    
- LiberationMono Nerd Font
    
- AnonymousPro Nerd Font
    
- CaskaydiaCove Nerd Font
    
- FantasqueSansMono Nerd Font
    
- SpaceMono Nerd Font
    
- Terminus Nerd Font
    
- NotoMono Nerd Font
    
- ProFont Nerd Font
    
- IBM Plex Mono Nerd Font
    
- BigBlueTerm437 Nerd Font
    
- Agave Nerd Font

Katakanlah kita mengambil `0xProto Nerd Font`. Setelah kita install, maka kita akan mendapatkan file ZIP. Ekstrak file ZIP, dan kita akan mendapati lagi bahwa didalamnya juga terdapat banyak jenis font `0xProto Nerd Font` yang bisa dipilih:


- 0xProtoNerdFontPropo-Bold.ttf
    
- 0xProtoNerdFontPropo-Italic.ttf
    
- 0xProtoNerdFontPropo-Regular.ttf
    
- 0xProtoNerdFontMono-Bold.ttf
	
-  0xProtoNerdFont Propo.ttf
    
- 0xProtoNerdFontMono-Italic.ttf
    
- 0xProtoNerdFontMono-Regular.ttf
    
- 0xProtoNerdFont-Bold.ttf
    
- 0xProtoNerdFont-Italic.ttf
    
- 0xProtoNerdFont-Regular.ttf

Pilih jenis font yang kita mau, bisa kita cek terlebih dahulu dengan cara membukanya seperti ini:

![[02-Setup Terminal Untuk Neovim-37.png]]

Jika ingin menginstallnya, klik tombol `install`, maka proses install akan langsung dilakukan saat itu juga, dan font tersebut akan bisa kita gunakan. 

Akan lebih baik jika kamu menginstal semua varian font dari paket Nerd Font yang kamu download, sehingga jika semisal suatu saat kita bosan terhadap tampilan font tertentu, kita bisa dengan mudah menggantinya di settngan font terminal.

> Untuk cara melakukanya, akan dijelaskan dibagian bawah!

---
<br/>

## 2.3 | Konfigurasi Text
- Pada bagian **Color scheme**, pilih settingan warna yang menurut kamu menarik, ada opsi seperti *Tango Ligth*, *Solarized Dark*, *Ottoson*, dan banyak lagi.
  
  ![[02-Setup Terminal Untuk Neovim-38.png]]
  
<br/>

- Pada bagian **Font face**, pilih font yang berasal dari Nerd Font. Masalah jenis paket, dan variasi paketnya, sesuai selera kamu. Yang penting Nerd Font. Karena sebelumnya kita sudah menginstall Nerd Font, maka seharusnya pemilihan font ini sudah ada. Aktifkan `Show all font` jika opsi Nerd Font tidak muncul.
  
  ![[02-Setup Terminal Untuk Neovim-39.png]]
  
<br/>

- Bagian **Font size**, **Line Height**, **Font weight**, **Variable font axes**, dan **Font features**, bisa kita skip saja langsung.
  
  ![[02-Setup Terminal Untuk Neovim-40.png]]
  
<br/>

- **Builtin Glyphs** adalah ikon-ikon khusus (seperti simbol folder, branch git, panah, dll) yang ditampilkan di terminal menggunakan font khusus bernama Nerd Font. Glyph ini tidak berasal dari PowerShell secara langsung, tapi muncul jika terminal (seperti Windows Terminal) menggunakan font yang sudah menyatu (build-in) dengan glyph tersebut. Jadi kita aktifkan saja, **ON**.
  
  ![[02-Setup Terminal Untuk Neovim-41.png]]
  
<br/>

- **Full-color Emoji** kita nyalan saja, **ON**.
<br/>

- **Retro terminal effects** adalah fitur visual di Windows Terminal yang membuat tampilannya menyerupai terminal komputer jadul, lengkap dengan efek seperti glow dan scanlines. Efek ini memberi nuansa retro klasik seperti monitor CRT era 80-an. Sesuai selera saja, bisa di ON atau OFF kan.
  
  ![[02-Setup Terminal Untuk Neovim-42.png]]
  
<br/>

- **Automatically adjust the lightness of indistinguishable text** adalah fitur di **Windows Terminal** yang secara otomatis mencerahkan teks yang warnanya terlalu mirip dengan latar belakang, agar tetap bisa terbaca. Tujuannya: supaya teks yang semula samar atau nyaris tidak terlihat jadi lebih kontras dan terbaca. Jadi, kita **Always** kan.
  
  ![[02-Setup Terminal Untuk Neovim-43.png]]

---
<br/>

## 2.4 | Konfigurasi Cursor
Konfigurasi cursor terdia beberapa pilihan, kamu ambil saja yang sesuai dengan seleramu:

![[02-Setup Terminal Untuk Neovim-25.png]]

Jika semisal kita memilih opsi **vintage**, maka kita bisa mengatur ketinggian blok cursour atau **Cursour height** yang kita gunakan, semisal seperti ini:

![[02-Setup Terminal Untuk Neovim-26.png]]

```
Teks biasa:     Hello, World!

Cursor 100%:    █ello, World!   ← Blok penuh (menutupi huruf H)

Cursor 50%:     ▂ello, World!   ← Setengah tinggi

Cursor 25%:     ˍello, World!   ← Hanya garis kecil di bawah
```

Selain opsi itu, maka tidak ada konfigurasi lain, jadi bebas kamu pilih.

---
<br/>

## 2.5 | Background Image 

Opsi ini memungkinkan kita untuk memberi background pada terminal kita, sehingga terminal kita tidak polosan hitam saja. Misal seperti ini:

![[02-Setup Terminal Untuk Neovim-27.png]]

Kita memiliki dua opsi disini, yaitu memilih background yang sama dengan wallpaper utama dekstop kita, atau memilih gambar yang tersedia di desktop kita:

![[02-Setup Terminal Untuk Neovim-28.png]]

---
<br/>

## 2.6 | Text Formatting
Pada bagian **Text Formatting** terdapat satu opsi saja yaitu **Intense text style**. **Intense text style** adalah pengaturan di Windows Terminal untuk menentukan gaya tampilan teks "intens" atau berwarna terang (bright text), biasanya dipakai untuk menyorot bagian penting seperti output atau error.

Kamu bisa pilih tampilannya jadi:

- **Bold** → teks tebal
    
- **Bright** → warna lebih cerah
    
- **Bold & Bright** → kombinasi keduanya
    

Tujuannya: bikin teks tertentu jadi lebih mencolok dan mudah dibedakan dari teks biasa.

![[02-Setup Terminal Untuk Neovim-29.png]]

Pilih sesuai selera saja.

---
<br/>

## 2.7 | Transparency

![[02-Setup Terminal Untuk Neovim-30.png]]

Nah, pada bagian ini, bagian **Background opacity** akan mengatur seberapa transparan terminal kita. Semakin rendah, maka semakin transparan.

Sedangkan bagian **Enable acrylic material**, akan memberikan efek blur/glossy/acrylic pada efek transparan yang dibuat. Berikut perbandinganya:

Transparan tanpa Acrylic:

![[02-Setup Terminal Untuk Neovim-31.png]]

Transparan dengan acrylic:

![[02-Setup Terminal Untuk Neovim-32.png]]

Pilih sesuai keinginan, mana yang cocok sesuai seleramu 😀.

---
<br/>

## 2.8 | Window

![[02-Setup Terminal Untuk Neovim-33.png]]

Bagian **Padding** berguna untuk memberikan padding pada teks yang ada di terminal, misal kalau kita atur paddingnya menjadi 100% maka tampilanya akan menjadi seperti ini:

![[02-Setup Terminal Untuk Neovim-34.png]]

Nah, karena tampilanya jelek, kita atur saja ukuran paddingnya ke ukuran default, yaitu 8%. 

> Jangan khawatir jika kamu secara tidak sengaja mengacaukan konfigurasi dari Windows Powershell. Tekan saja tombol panah balik berukuran kecil yang ada pada setiap pengaturan. Itu akan mengembalikan settingan pengaturan tersebut ke settingan defaultnya!

Lalu bagian **Scrollbar visibility**, berguna untuk menyembunyikan scrollbar. Jika teksnya ada banyak hingga kebawah, memang scrollbar akan berguna untuk membantu scroll dengan cepat. Scrollbar ini juga akan secara tidak langsung menunjukan banyaknya baris pada kode, dan dibagian kode mana kita berada, apakah itu diatas, tengah, atau bawah. Namun, kita juga bisa mengandalkan key *Page Down* dan *Page Up* untuk masalah scroll ini. Kita juga bisa menggunakan scrollbar dari mouse, Jadi, untuk opsi ini pilih saja sesuai selera.

![[02-Setup Terminal Untuk Neovim-35.png]]

Jika Scrollbar dimunculkan dengan opsi `Always`:

![[02-Setup Terminal Untuk Neovim-44.png|500]]

Jika scrollbar disembunyikan dengan opsi `Hidden`:

![[02-Setup Terminal Untuk Neovim-45.png]]



---
<br/>

# 3 | Setting Global Appearence


![[02-Setup Terminal Untuk Neovim-36.png]]

Global Appearence akan mengatur tampilan diluar settingan sebelumnya. Ada banyak konfigurasi tambahan yang bisa kita lakukan untuk memaksimalkan setup kita.

---
<br/>

## 3.1 | Deskripsi dari Opsi yang Tersedia
### 1. Application Theme

Mengatur tampilan warna utama Windows Terminal.

- **Dark (Legacy)**: Tema gelap klasik.
    
- **Light**: Warna terang.
    
- **System**: Mengikuti tema Windows.
    
- Ini mengubah warna UI (tab, background luar, dll), **bukan warna teks atau shell-nya**.


### 2. Position of newly created tabs

Menentukan **di mana tab baru akan muncul**:

- **After the last tab**: Selalu di paling kanan.
    
- **After the selected tab**: Di samping tab yang sedang aktif.
    
- Cocok kalau kamu kerja dengan banyak tab dan ingin urutan rapi.


### 3. Hide the title bar (requires relaunch)

- Menghilangkan title bar Windows (bagian atas yang ada `X`, minimize, maximize).
    
- Efek: Tampilan jadi lebih minimal, tetapi kamu tetap bisa pindah-pindah tab pakai bar tab di bawahnya.
    
- Harus restart terminal setelah ubah ini.


### 4. Always show tabs

- Kalau ini **aktif**, bar tab akan selalu tampil meskipun hanya satu tab.
    
- Kalau **nonaktif**, tab bar hanya muncul saat ada lebih dari 1 tab.
    
- Tapi: **Tidak bisa dimatikan jika "Hide the title bar" aktif**, karena tab jadi satu-satunya navigasi.
    

### 5. Use acrylic material in the tab row

- Memberi efek transparan blur (acrylic) di bagian tab.
    
- Estetika lebih modern, mirip efek kaca Windows 11.
    
- Bisa bikin tampilan lebih keren, tapi makan sedikit performa (sangat ringan sih).

### 6. Use active terminal title as application title

- Kalau diaktifkan:
    
    - Judul window akan menampilkan judul tab aktif, misalnya: `zsh - MyProject`.
        
- Kalau dimatikan:
    
    - Judulnya cuma “Terminal”.
        
- Berguna untuk membedakan banyak jendela terminal berdasarkan kontennya.
    


### 7. Always on top

- Jika diaktifkan, jendela Terminal akan **selalu di atas** semua jendela lain.
    
- Cocok untuk monitor kecil atau kerja multitasking tanpa harus terus buka terminal lagi.
    

### 8. Tab width mode

- Mengatur lebar tab:
    
    - **Equal**: Semua tab lebar sama, rapi.
        
    - **Title length**: Lebar tab mengikuti panjang nama tab.
        
    - **Compact**: Tab yang tidak aktif menyusut hanya jadi ikon.
        
- Pilih sesuai preferensi visual & jumlah tab yang biasa kamu pakai.

### 9. Pane animations

- Kalau kamu split terminal (horizontal atau vertikal), ini mengaktifkan animasi transisinya.
    
- Bisa dimatikan kalau mau respons langsung tanpa efek animasi.


### 10. Always display an icon in the notification area

- Kalau aktif, Terminal muncul di system tray (pojok kanan bawah Windows).
    
- Cocok untuk akses cepat, mirip kayak app background.

### 11. Hide Terminal in the notification area when it is minimized

- Kalau **aktif**, saat kamu _minimize_ terminal:
    
    - Jendela **nggak kelihatan di taskbar**, tapi pindah ke **system tray** (pojok kanan bawah, dekat jam).
        
- Cocok buat yang ingin terminal tetap jalan tapi tidak mengganggu taskbar.
    
- Mirip cara kerja Discord, Telegram, dsb.

### 12. Automatically hide window

- Kalau **aktif**, terminal akan **langsung disembunyikan** saat kamu fokus ke jendela lain.
    
- Artinya: begitu kamu alt-tab atau klik app lain → terminal langsung hilang dari layar.
    
- Cocok buat power user yang ingin terminal tampil hanya saat dibutuhkan (misalnya untuk _Quake mode_ atau kerja cepat).
    

---
<br/>

## 3.2 | Opsi yang Diambil

Disini, kita bisa memutuskan opsi yang bisa diambil, saya merasa opsi berikut layak dipilih karena membuat tampilan terminal kita menjadi lebih keren:

1. Application Theme: **Dark Legacy**
2. Position of newly created tabs: **After the current tab**, supaya tidak terlalu jauh pada saat membuka tab baru, jika sudah membuka banyak tab.
3. Hide the title bar (requires relaunch): kita buat **OFF**. Ketika hanya ada satu tab terminal, maka tab tersebut akan ter hide, sehingga tampilanya lebih minimalis. Lebih keren 😀.
4.  Always show tabs: konfigurasi ini kita buat **OFF** juga, supaya minimalisnya maksimal, membantu konfigurasi sebelumnya.
5. Use acrylic material in the tab row: **ON**, ini yang bikin keren 😎.
6. Use active terminal title as application title: **ON**, untuk kemudahan navigasi.
7. Always on top: tergantung kebutuhan, kita ambil **ON** saja, supaya tidak tertutup langsung ketika mengerjakan window aplikasi lain.
8. Tab width mode: **Equal**, biar simetris.
9. Pane animations: **ON**, biar ada efek smooth.
10. Always display an icon in the notification area: bebas.
11. Hide Terminal in the notification area when it is minimized: bebas.
12. Automatically hide window: **OFF**, supaya tidak ketutup pas kita baca probem soal buat competitive-programming.

Nah, sekarang tampilan terminal kita akan seperti ini:

![[02-Setup Terminal Untuk Neovim-46.png]]

Gelap, dark, elegan, dan minimalis bukan 😎.

---
<br/>

## 3.3 | Usefull Keybiding

Nah, karena kita membuatnya tampil elegan dan seminimalis mungkin. Maka kita tidak bisa mendapati GUI untuk menambah tab baru, switch tab, dan juga masuk ke pengaturan, jadi ingat key berikut, supaya tidak kesusahan pakai setup ini:

- *Ctrl + Shift + t* -> Berguna untuk membuat tab baru disamping tab yang sedang aktif saat ini. Ketika ada lebih dari satu tab, tombol ke menu pengaturan juga akan dimunculan, beserta daftar tab yang kita buka. Untuk kembali ke tampilan minimalis, aktifkan saja satu tab, dan close yang lain jika sudah tidak diperlukan.

<br/>

- *Ctrl + Shift + w* -> Close tab terminal yang sedang aktif. Bisa menggunakan syntax `exit`.

<br/>

- *Ctrl + tab* -> Berguna untuk switch antar tab terminal.

<br/>

- *Alt + Enter* / *F11* -> Masuk ke mode Fullscreen. Tekan kombinasi tombol yang sama untuk keluar.

<br/>

- *Win + backtick* -> Masuk ke mode Quack. Terminal muncul dari atas, dan siap untuk menerimpa perintah. Tapi harus ada satu terminal aktif untuk bisa menjalankan mode ini.


Masih ada banyak keybinding untuk Terminal Windows ini, untuk lengkapnya bisa dicek di bagian **Actions**:

![[02-Setup Terminal Untuk Neovim-47.png]]

Untuk yang lumayan penting, untuk navigasi cepat, split pane, dan semacamya, bisa kita pelajari juga, berikut daftarnya:
### Split pane

Bagi terminal jadi beberapa bagian **(horizontal/vertikal)**.

|Aksi|Keybinding|
|---|---|
|Split Horizontal|`Alt + Shift + -`|
|Split Vertikal|`Alt + Shift + +`|
|Fokus ke pane sebelah|`Alt + panah (←↑→↓)`|
|Tutup pane aktif|`Ctrl + Shift + W`|

### Multi tab Navigation
Navigasi antar tab di terminal:

| Aksi                     | Keybinding           |
| ------------------------ | -------------------- |
| Tab baru                 | `Ctrl + Shift + T`   |
| Pindah tab berikutnya    | `Ctrl + Tab`         |
| Pindah tab sebelumnya    | `Ctrl + Shift + Tab` |
| Tutup tab                | `Ctrl + Shift + W`   |
| Pindah ke tab nomor N    | `Ctrl + Alt + [1-9]` |
| Pindah ke window sebelah | Alt + ← → ↑ ↓        |

Jadi kamu bisa cepat banget switch antar sesi kerja.

### Resize Pane

Resize pane cepat dengan key biding:

| Aksi                | Keybinding            |
| ------------------- | --------------------- |
| Resize pane (panah) | `Alt + Shift + panah` |