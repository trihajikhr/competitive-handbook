---
obsidianUIMode: preview
note_type: Dokumentasi
judul_dokumentasi: Setup Terminal Untuk Neovim
date_add: 2025-07-26T14:22:00
status_dokumentasi: ✅Finish ❌Not-Finish
tags:
  - neovim
  - vim
  - lazyvim
---
---

# Setup Terminal Untuk Neovim
Setelah sebelumnya kita melakukan pemasangan dan konfigurasi awal untuk neovim dengan environtment C++, selanjutnya kita masih bisa melakukan beberapa setup tambahan untuk terminal kita, agar tampilanya menjadi lebih menarik.

Jika kamu melihat ke internet, ada banyak sekali setup-setup neovim dari pengguna lain yang tampak sangat cantik dan menarik 😊, seperti ini contohnya:

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


Nah, disini kita akan melakukan beberapa tambahan setup dan konfigurasi, agar tampilan neovim kita menjadi cantik, menarik, memanjakan mata 😀, dan membuat siapapun yang melihatnya akan berpikir bahwa kita bukan sembarang programmer hahah..

Tapi serius, jika kita memang menggunakan neovim dan bisa melakukan banyak setup yang membuat tampilan neovim kita menjadi terlihat menarik, kita sudah bukan lagi programmer biasa, yang hanya install code-editor atau IDE yang sudah lengkap dengan paket-paketnya. Karena di neovim, kita harus setup semuanya secara manual. Walaupun sulit diawal, namun jika ditekuni dengan komitmen, maka kita pasti akan bisa mensetup dan mampu mengkonfigurasi neovim kita, tidak lagi sekedar copy-paste konfigurasi dari orang lain 😎.

Nah, untuk bisa melakukan banyak setup seperti gambar-gambar diatas, sebelum kita menyentuh konfigurasi plugins, kita perlu setup terminal kita terlebih dahulu. 


---
<br/>

## Pemilihan Terminal
Jika kita menggunakan windows, maka akan ada dua pilihan bagi kita, yaitu memilih antara Windows Powershell, Command Prompt, atau terminal esternal yang kita pasang, misalnya seperti Alacrity.

Supaya kita bisa memilih terminal yang tepat, kita perhatikan perbandingan berikut, karena pemilihan terminal punya pengaruh besar ke pengalaman pakai Neovim, khususnya untuk:

- Transparansi / efek estetika
- Rendering font (nerd font, ligatures)
- Dukungan true color & mouse
- Kompabilitas dengan plugin-plugin Neovim, seperti floating window, telescope, dsb.


Berikut penjelasan dari masing-masing terminal di Windows buat keperluan _setup tampilan Neovim_:

### 💠 1 | PowerShell / Cmd (via `cmd.exe` atau `powershell.exe`)

![[02-Setup Terminal Untuk Neovim-13.png]]


- ❌ **Kelebihan**:
    
    - Pre-installed.
    - Bisa langsung dipakai tanpa install tambahan.
        
- ❌ **Kekurangan**:
    
    - Buruk untuk tampilan Neovim:
        
        - Tidak support true color dengan baik.
            
        - Tidak support transparansi.
            
        - Tidak nyaman untuk nerd fonts dan ligatures.
            
        - Kadang rendering UI Neovim tidak rapi (misal garis `│`, `─`).
            

🔻 **Verdict:** **Kurang ideal**, sebaiknya dihindari untuk Neovim.

### 🪟 2 | Windows Terminal / Windows Powershell 

![[02-Setup Terminal Untuk Neovim-14.png]]

> Ini terminal modern dari Microsoft. Bisa membuka tab/tab split untuk PowerShell, CMD, WSL, dll.

- ✅ **Kelebihan**:
    
    - True color & transparansi ✅
        
    - Sangat bagus untuk tampilan plugin-plugin Neovim (misal: `telescope`, `lualine`, dsb).
        
    - Support ligature, nerd font, emoji 👍
        
    - Customizable banget (via `settings.json`):
        
        - Warna, font, padding, efek blur.
            
- ⚠️ **Catatan**:
    
    - Pastikan `settings.json` diatur agar pakai font seperti `FiraCode Nerd Font`, `JetBrainsMono Nerd Font`, dll.
        

🔷 **Verdict:** **Rekomendasi kuat!** Cocok untuk pengguna Windows yang ingin tampilan Neovim bagus.

### 🚀 3 | Alacritty

![[02-Setup Terminal Untuk Neovim-15.png]]


> Terminal cross-platform berbasis GPU. Ringan dan cepat.

- ✅ **Kelebihan**:
    
    - Super ringan & cepat (GPU accelerated).
        
    - True color, transparansi, nerd font, ligatures = ✅
        
    - UI-nya minimalis dan tajam.
        
- ⚠️ **Kekurangan**:
    
    - Tidak punya GUI settings → semua config harus lewat file `alacritty.yml`.
        
    - Tidak built-in tab/multi-pane (harus pakai tmux kalau mau split/tab).
        

🔷 **Verdict:** Pilihan terbaik untuk **kamu yang suka terminal minimalis dan cepat**.


### 🐧 4 | WSL Terminal (Windows Subsystem for Linux)

![[02-Setup Terminal Untuk Neovim-16.png]]


> WSL sendiri bukan terminal, tapi shell Linux yang bisa dibuka di berbagai terminal (Windows Terminal, Alacritty, dll).


- ✅ **Kelebihan**:
    
    - Menjalankan Neovim di lingkungan Linux asli, sehingga lebih kompatibel dengan tools Unix-like (ripgrep, fd, make, gcc, clang, dsb).
        
    - Bisa langsung install semua CLI tool pakai `apt`, `pacman`, dll.
        
    - Kompatibel penuh dengan plugin-plugin Neovim modern.
        
    - Tersedia berbagai distro (Ubuntu, Debian, Arch, Alpine).
        
- ⚠️ **Kekurangan**:
    
    - Perlu install tambahan (`wsl --install` untuk Windows 11, atau manual setup untuk Windows 10).
        
    - Sedikit lebih berat karena berjalan di virtual layer (meski ringan di WSL 2).
        
    - Akses file sistem Windows (`/mnt/c/Users/...`) lebih lambat daripada file Linux native (`/home/user/...`).
        

🔷 **Verdict:** **Pilihan paling kompatibel** untuk Neovim power user di Windows.

### 🧪 5 | Kitty Terminal

![[02-Setup Terminal Untuk Neovim-17.png]]

> Terminal GPU-accelerated mirip Alacritty, tapi dengan lebih banyak fitur built-in.


- ✅ **Kelebihan**:
    
    - GPU-accelerated (cepat dan smooth).
        
    - Native support untuk ligatures, nerd font, image preview, hingga remote sync.
        
    - Bisa dikustomisasi dengan config file `kitty.conf`.
        
    - Support tab, window management, scripting (lebih lengkap dari Alacritty).
        
- ⚠️ **Kekurangan**:
    
    - Tidak built-in ke Windows — butuh Cygwin/MSYS/WSL/X11 untuk dijalankan di Windows (tidak native).
        
    - Setup agak rumit di Windows.
        

🔻 **Verdict:** Cocok untuk pengguna **Linux/Mac**. Di Windows, tidak praktis kecuali via WSL/X.

---

### 🐚 6 | Git Bash

![[02-Setup Terminal Untuk Neovim-18.png]]

> Shell berbasis `bash` dari Git for Windows, dengan tampilan terminal sendiri.


- ✅ **Kelebihan**:
    
    - Sudah include saat install Git for Windows.
        
    - Familiar untuk pengguna bash/Linux.
        
    - Mendukung beberapa utilitas Unix-like seperti `ls`, `grep`, `make`.
        
- ⚠️ **Kekurangan**:
    
    - Tidak mendukung true color dengan baik.
        
    - Nerd font dan ligatures kadang bermasalah.
        
    - Performanya lebih lambat dari WSL atau terminal native.
        
    - Tidak cocok untuk UI plugin Neovim seperti `telescope`.
        

🔻 **Verdict:** Cocok untuk penggunaan ringan, **tidak ideal untuk tampilan Neovim yang kompleks**.

---

### 📊 Update Tabel Perbandingan

|Terminal|True Color|Transparan|Nerd Font|Ligature|Customisasi|Berat|Komentar|
|---|---|---|---|---|---|---|---|
|CMD / PowerShell|❌|❌|❌|❌|❌|Ringan|Hindari untuk Neovim|
|Windows Terminal|✅|✅|✅|✅|GUI / JSON|Sedang|Modern, mendukung banyak shell|
|Alacritty|✅|✅|✅|✅|YAML|Super ringan|Minimalis, cepat, perlu tmux|
|WSL (Ubuntu, etc)|✅|✅|✅|✅|Shell Linux|Agak berat|Ideal untuk developer & plugin|
|Kitty|✅|✅|✅|✅|kitty.conf|Sedang|Powerful tapi kurang native di Win|
|Git Bash|⚠️|⚠️|⚠️|❌|Minimal|Ringan|Untuk keperluan Git, bukan Neovim|

---

### ✅ Kesimpulan Tambahan

- Kalau kamu ingin **kompatibilitas tertinggi + plugin Neovim jalan optimal** → **WSL atau Alacritty + WSL shell**
    
- Kalau kamu ingin **termudah + tampil keren tanpa ribet** → **Windows Terminal dengan PowerShell atau WSL shell**
    
- Kalau kamu pengguna Linux/Mac → **Kitty atau Alacritty sangat cocok**
    
- Hindari Git Bash, CMD, PowerShell klasik kalau kamu mau UI Neovim modern


Nah, disini jelas bahwa pilihan kita adalah 2, yaitu Alacrity, atau Windows terminal. Windows terminal memang jauh lebih mudah untuk disetup, tapi Alacrity jauh lebih ringan untuk digunakan, dan dengan sedikit setup, kita bisa membuat setup atau konfigurasi dari Alacrity menjadi menarik.

Tapi, kekurangan dari Alacrity lumayan berpengaruh disini, dimana alacrity tidak bisa memiliki banyak tab seperti Windows terminal. Padahal kita membutuhkan terminal yang bisa memiliki banyak tab agar bisa membuka banyak neovim sekaligus.

Jadi, kita ambil saja Windows Powershell 😀.

> Kedepanya kita mungkin akan berpindah terminal, sehingga akan ada dokumentasi sejenis! Untuk kali ini, kita akan mendokumentasikan penyiapan setup neovim dengan Windows Poweshell!
> 
> Lagipula, diluar sana ternyata ada jauh lebih banyak terminal yang belum sempat disebut disini, ada yang lebih cepat, lebih powerfull, dan ada juga yang memiliki beberapa fungionalitas unik tertentu. Jadi, bukan tidak mungkin terminal untuk neovim kali ini dialihkan ke terminal yang lain kedepanya.


---
<br/>

# Setup Windows Powershell
Baiklah, sekarang kita memilih Windows Powershell sebagai terminal neovim kita kali ini. Ikuti panduan ini untuk membuat Windows Powershell kita menjadi lebih menarik dan sesuai.

## 1 | Menemukan Opsi Appearence
Untuk bisa mengatur banyak konfigurasi dari Windows Powershell, kita perlu masuk ke settingan Appearence. Pertama-tama, masuk ke settingan terlebih dahulu:

![[02-Setup Terminal Untuk Neovim-19.png]]

Masuk ke menu `Settings`, maka kita akan mendapti tampilan dan menu seperti ini:

![[02-Setup Terminal Untuk Neovim-20.png]]

Pada bagian atas kanan, yaitu bagian `Default profile`, kita pilih Windows Powershell, supaya pas kita mengetikan terminal pada windows, maka powershell lah yang akan dibuka, karena dia disetting sebagai default.

Pada bagian kiri bawah, tepatnya di bagian *profiles*, kita pilih Windows Powershell, karena kita akan melakukan konfigurasi pada Windows Powershell:

![[02-Setup Terminal Untuk Neovim-21.png]]

Pada bagian ini, gulir kebawah hingga menemukan 3 menu, lalu kita pilih `Appearence`:

![[02-Setup Terminal Untuk Neovim-22.png]]

Nahh, ketika kita masuk ke pilihan `Appearence`, maka tampilan kita akan menjadi seperti ini:

![[02-Setup Terminal Untuk Neovim-23.png]]


---
<br/>

## 2 | Menginstall Font 
Untuk bisa menampilkan icons-icons pada terminal, kita tidak bisa menggunakan font biasa. Kita perlu menggunakan font khusus, yaitu Nerd-Font. Oleh karena itu, kita perlu menginstall font [Nerd Font](https://www.nerdfonts.com/) dari situs officialnya:

![[02-Setup Terminal Untuk Neovim-24.png]]

Dibagian `Download`, kamu akan menemukan banyak sekali jenis paket Nerd-Font yang bisa dipilih. Berikut adalah daftar jenis paket Nerd-Font yang disediakan:

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

---
<br/>

## 3 | Konfigurasi Text
- Pada bagian **Color scheme**, pilih settingan warna yang menurut kamu menarik, ada opsi seperti *Tango Ligth*, *Solarized Dark*, *Ottoson*, dan banyak lagi.
<br/>

- Pada bagian **Font face**, pilih font yang berasal dari Nerd Font. Masalah jenis paket, dan variasi paketnya, sesuai selera kamu. Yang penting Nerd Font.
<br/>

- Bagian **Font size**, **Line Height**, **Font weight**, **Variable font axes**, dan **Font features**, bisa kita skip saja langsung.
<br/>

- **Builtin Glyphs** adalah ikon-ikon khusus (seperti simbol folder, branch git, panah, dll) yang ditampilkan di terminal menggunakan font khusus bernama Nerd Font. Glyph ini tidak berasal dari PowerShell secara langsung, tapi muncul jika terminal (seperti Windows Terminal) menggunakan font yang sudah menyatu (build-in) dengan glyph tersebut. Jadi kita aktifkan saja, **ON**.
<br/>

- **Full-color Emoji** kita nyalan saja, **ON**.
<br/>

- **Retro terminal effects** adalah fitur visual di Windows Terminal yang membuat tampilannya menyerupai terminal komputer jadul, lengkap dengan efek seperti glow dan scanlines. Efek ini memberi nuansa retro klasik seperti monitor CRT era 80-an. Sesuai selera saja, bisa di ON atau OFF kan.
<br/>

- **Automatically adjust the lightness of indistinguishable text** adalah fitur di **Windows Terminal** yang secara otomatis mencerahkan teks yang warnanya terlalu mirip dengan latar belakang, agar tetap bisa terbaca. Tujuannya: supaya teks yang semula samar atau nyaris tidak terlihat jadi lebih kontras dan terbaca. Jadi, kita **Always** kan.

---
<br/>

## 4 | Konfigurasi Cursor
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

## 5 | Background Image 

Opsi ini memungkinkan kita untuk memberi background pada terminal kita, sehingga terminal kita tidak polosan hitam saja. Misal seperti ini:

![[02-Setup Terminal Untuk Neovim-27.png]]

Kita memiliki dua opsi disini, yaitu memilih background yang sama dengan wallpaper utama dekstop kita, atau memilih gambar yang berbeda:

![[02-Setup Terminal Untuk Neovim-28.png]]

---
<br/>

## 6 | Text Formatting
Pada bagian **Text Formatting** terdapat satu opsi saja yaitu **Intense text style**. **Intense text style** adalah pengaturan di Windows Terminal untuk menentukan **gaya tampilan teks "intens" atau berwarna terang** (bright text), biasanya dipakai untuk menyorot bagian penting seperti output atau error.

Kamu bisa pilih tampilannya jadi:

- **Bold** → teks tebal
    
- **Bright** → warna lebih cerah
    
- **Bold & Bright** → kombinasi keduanya
    

Tujuannya: bikin teks tertentu jadi lebih mencolok dan mudah dibedakan dari teks biasa.

![[02-Setup Terminal Untuk Neovim-29.png]]

Pilih sesuai selera saja.

---
<br/>

## 7 | Transparency

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

## 8 | Window

![[02-Setup Terminal Untuk Neovim-33.png]]

Bagian **Padding** berguna untuk memberikan padding pada teks yang ada di terminal, misal kalau kita atur paddingnya menjadi 100% maka tampilanya akan menjadi seperti ini:

![[02-Setup Terminal Untuk Neovim-34.png]]

Nah, karena tampilanya jelek, kita atur saja ukuran paddingnya ke ukuran default, yaitu 8%. 

> Jangan khawatir jika kamu secara tidak sengaja mengacaukan konfigurasi dari Windows Powershell. Tekan saja tombol panah balik berukuran kecil yang ada pada setiap pengaturan. Itu akan mengambilan settingan pengaturan tersebut ke settingan defaultnya!

Lalu bagian **Scrollbar cisibility**, berguna untuk menyembunyikan scrollbar. Jika teksnya ada banyak hingga kebawah, maka scrollbar akan berguna untuk membantu scroll dengan cepat. Namun, kita juga bisa mengandalkan key *Page Down* dan *Page Up* untuk masalah scroll ini. Untuk opsi ini pilih saja sesuai selera.

![[02-Setup Terminal Untuk Neovim-35.png]]

---
<br/>

## 9 | Setting Global


![[02-Setup Terminal Untuk Neovim-36.png]]