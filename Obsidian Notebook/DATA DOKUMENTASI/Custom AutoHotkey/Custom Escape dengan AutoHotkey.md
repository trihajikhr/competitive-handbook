---
obsidianUIMode:
note_type: Dokumentasi
judul_dokumentasi: Custom Escape dengan Auto Hot Key
date_add: 2025-09-01T17:22:00
status_dokumentasi: ✅Finish
tags:
  - neovim
---
---
# 1 | Custom Escape dengan AutoHotkey
Ketika kamu menggunakan neovim, kamu akan sering beralih mode antara mode insert, dan mode biasa. Dari mode biasa ke mode insert, kita bisa menggunakan keymap `i`, sedangkan untuk keluar dari mode insert, kita bisa menggunakan keymap `Esc`, atau Escape. 

Tapi, karena keymap Escape ada di pojok kiri keyboard, banyak pengguna neovim yang melakukan custom keymaps, dengan menjadikan tombol Caps lock menjadi pengganti tombol Escape. Ini karena tombol Escape sendiri terlalu jauh dari home row keyboard, sehingga beralih mode di neovim bisa menjadi lebih sulit dan lama. Sedangkan, jika diperhatikan dengan seksama, tombol Caps lock lumayan strategis, dan juga tidak terlalu sering dipakai.

Oleh karena itu, untuk memudahkan proses coding menggunakan neovim, alangkah baiknya menggunakan custom keymaps ini, supaya bisa beralih mode dengan cepat saat menggunakan neovim. 

Custom keymaps yang kita lakukan adalah dengan menjadikan tombol Caps lock berfungsi seperti tombol Escape. Tombol Escape tetap berfungsi, hanya saja bisa digantikan peranya oleh tombol Caps lock. Dan supaya tombol Caps lock tidak benar-benar kehilangan peranya, kita atur agar mode Caps lock bisa diaktifkan, tapi dengan menggunakan kombinasi tombol Shift + Caps lock.

Dengan cara ini, kita bisa menggunakan fungsionalitas tombol Escape dengan menekan tombol Caps lock, tapi dengan tidak kehilangan fungsi tombol Escape, dan juga tidak mengorbakan fungsionalitas tombol Caps lock, karena bisa kita akfitkan lagi dengan kombinasi Shift + Caps lock.

<br/>

---

# 2 | Aplikasi dan Konfigurasi
## 2.1 | Aplikasi

Untuk aplikasi yang bisa digunakan, ada banyak. Namun, kali ini kita akan menggunakan aplikasi atau software *AutoHotkey*, yang bisa didapat dengan memasukan kata kunci tersebut ke pencarian, yang kemudian akan membawa kita ke situs [autohotkey](https://www.autohotkey.com/):

![[DATA DOKUMENTASI/Custom AutoHotkey/src/Custom Escape dengan AutoHotkey-1.png]]

Unduh versi terbaru (yang bukan deprecated) yang disediakan situs tersebut, dan lakukan penginstalan seperti biasa:

```ad-warning
Untuk versi terbaru per tanggal 1 September 2025 adalah versi v2.0. Kunjungi situsnya langsung untuk mendapat versi terbaru yang disediakan!
```


![[DATA DOKUMENTASI/Custom AutoHotkey/src/Custom Escape dengan AutoHotkey-2.png]]

Pilih lokasi penginstalan, namun kita bisa biarkan saja ke lokasi defaultnya, lagipula ukuran instalasi ini cukup kecil. Tetapkan AutoHotkey untuk bisa digunakan oleh semua user dengan memilih `All user`, lalu klik `Install`, dan klik yes jika ada notifikasi administration. Maka program pun berhasil terinstall jika menampilkan jendela baru seperti ini:

![[DATA DOKUMENTASI/Custom AutoHotkey/src/Custom Escape dengan AutoHotkey-3.png]]

## 2.2 | Konfigurasi
Setelah masuk ke mode terakhir, kita bisa membuat custom keymaps dengan cara memilih menu `New script`, sehingga kita akan dibawa ke tampilan seperti ini:

![[DATA DOKUMENTASI/Custom AutoHotkey/src/Custom Escape dengan AutoHotkey-4.png]]

Buat nama file yang sesuai, misalnya saja `caps_escape`. Pilih lokasi dimana file ini akan disimpan. Nah lokasi penyimpanan file ini harus cukup strategis, supaya kita bisa melakukan pengeditan dan penambahan konfigurasi script dengan mudah, tanpa perlu masuk ke banyak subfolder yang menyulitkan. Jadi, taruh saja misal di dalam drive D, supaya mudah ditemukan. 

Tekan saja icon folder untuk mengatur lokasi filenya secara manual ke folder strategis, dan jangan menerima lokasi default yang diberikan:
  
![[DATA DOKUMENTASI/Custom AutoHotkey/src/Custom Escape dengan AutoHotkey-5.png]]

```ad-info
Sebenarnya tidak harus diatur foldernya untuk sekarang, karena nanti kita bisa memindahkanya lagi secara manual. Tapi untuk menghindari faktor lupa, lebih baik diatur sekarang saja!
```


Setelah diatur lokasi strategisnya, kita pilih `Empty`, artinya kita akan membuat file `.ahk` yang isinya masih kosong. Maka, di folder tempat kita membuat file, akan muncul file baru yaitu `caps_escape.ahk` seperti ini:

![[DATA DOKUMENTASI/Custom AutoHotkey/src/Custom Escape dengan AutoHotkey-6.png]]

Nah, untuk bisa mengedit konfigurasi yang ada dialamnya, klik kanan file tersebut, dan buka dengan notepad, atau klik kanan pada file lalu pilih `Edit in Notepad`. Maka kita akan membuka file notepad kosong, dan disinilah konfigurasi dilakukan.

Masukan konfigurasi berikut, lalu simpan:

```ahk
; Versi AHK v2

CapsLock::Send "{Escape}"

+CapsLock::{
    state := GetKeyState("CapsLock", "T")
    SetCapsLockState(!state)
}
```

Ayo kita perjelas arti dari tiap baris konfigurasi diatas:

```ahk
; Versi AHK v2
```

Baris ini hanyalah komentar, menunjukan bahwa script ini ditulis untuk AutoHotkey versi 2.

```ahk
CapsLock::Send "{Escape}"
```

Ketika tombol CapsLock ditekan biasa, script akan mengirim Escape. Jadi fungsi CapsLock berubah jadi Escape.

```ahk
+CapsLock::{
    state := GetKeyState("CapsLock", "T")
    SetCapsLockState(!state)
}
```

Bagian ini memakai `+CapsLock`, artinya **Shift + CapsLock**.

- `state := GetKeyState("CapsLock", "T")` → cek apakah CapsLock sekarang aktif (`1`) atau mati (`0`).
    
- `SetCapsLockState(!state)` → ubah ke kebalikannya (toggle). Jika CapsLock aktif → maka dimatikan, Jika mati → maka diaktifkan.
### Jadi intinya:

- **CapsLock** = jadi **Escape**.
    
- **Shift + CapsLock** = toggle CapsLock seperti normal.

### Dokumentasi resmi:

Jika ingin mengetahui dokumentasi resmi dari AutoHotkey, bisa masuk saja ke situs [AutoHotkey Docs v2.0](https://www.autohotkey.com/docs/v2/):

![[DATA DOKUMENTASI/Custom AutoHotkey/src/Custom Escape dengan AutoHotkey-7.png]]

Atau, klik kanan pada icon AutoHotkey pada ssytem tray (jika sedang aktif), lalu klik `Help`, maka akan dibawa ke laman dokumentasi yang mirip:

![[DATA DOKUMENTASI/Custom AutoHotkey/src/Custom Escape dengan AutoHotkey-8.png]]

<br/>

---

# 3 | Settingan Lanjutan
## 3.1 | Mengaktifkan Manual

Jika semisal kita hanya menggunakan custom keymaps di waktu-waktu tertentu saja, dan ingin menggunakan konfigurasi AutoHotkey yang lebih simple seperti cara diatas, maka kita bisa set agar AutoHotkey hanya aktif ketika kita aktifkan saja.

Cara ini adalah cara yang paling mudah, karena kita cukup double klik pada file `caps_escape.ahk` yang sebelumnya kita buat, dan otomatis custom keymaps aktif. Ketika script akfit, maka akan muncul icon hijau H pada system tray (pojok kanan bawah):

![[DATA DOKUMENTASI/Custom AutoHotkey/src/Custom Escape dengan AutoHotkey-9.png]]


Untuk mematikanya, caranya cukup mudah. Pada tray icon, klik kanan AutoHotkey, lalu pilih `Exit` untuk mematikan script.

## 3.2 | Toggle On Off & Auto Detect

Cara yang kedua ini jauh lebih fleksibel, walaupun masih harus diaktifkan secara manual. Ini karena ketika script diaktifkan, dia hanya akan menjalankan custom keymaps ketika aplikasi yang ditentukan dibuka atau dijalankan. Jadi ketika semisal kita menseting Neovim sebagai salah satu aplikasi yang ditargetkan, maka custom keymaps akan bekerja ketika sedang membuka Neovim, tapi tidak ketika kita menjalankan aplikasi selain target, misal MS Words.

Script dibawah bertujuan untuk membuat konfigurasi AutoHotkey lebih fleksibel, dan hanya aktif disaat membuka aplikasi tertentu saja. Ini cocok jika semisal ingin menggunakan custom keymaps di Neovim, tapi ketika beralih ke MS Words, tombol Caps lock berfungsi seperti fungsi aslinya. Selain itu, kita juga bisa melakukan toggle on/off ketika menggunakan aplikasi yang ditargetkan, sehingga membuatnya jauh lebih fleksibel. Misal ketika menggunakan Neovim, kita bisa mematikan script untuk sementara, dan kemudian menyalakanya lagi. Hal ini bisa dilakukan dengan mudah, karena hanya menggunakan shortcut custom yang kita buat.


```ahk
MsgBox "Script AutoHotkey berhasil dijalankan!"

#Requires AutoHotkey v2.0
#SingleInstance Force

; ===== Toggle ON/OFF semua hotkeys =====
#SuspendExempt
^!p::{                            ; Ctrl+Alt+P
    Suspend(-1)                   ; toggle suspend
    ToolTip "AHK keymaps: " (A_IsSuspended ? "OFF" : "ON"), 10, 10
    SetTimer (() => ToolTip()), -800
}
#SuspendExempt False

; (opsional) Kill switch kalau perlu keluar total
^!q::ExitApp

; ===== Hotkeys kamu (contoh, context Neovim/terminal) =====
#HotIf WinActive("ahk_exe WindowsTerminal.exe") 
    or WinActive("ahk_exe alacritty.exe") 
    or WinActive("ahk_exe nvim-qt.exe")

CapsLock::Send "{Escape}"
+CapsLock::{
    state := GetKeyState("CapsLock", "T")
    SetCapsLockState(!state)
}
#HotIf
```

Berikut penjelasan dari konfigurasi diatas:

```ahk
MsgBox "Script AutoHotkey berhasil dijalankan!"
```

Ketika diaktifkan, akan menampilkan pesan *Script AutoHotkey berhasil dijalankan!*

```ahk
#Requires AutoHotkey v2.0
#SingleInstance Force
```

* **`#Requires AutoHotkey v2.0`**: memastikan script hanya dijalankan dengan AutoHotkey versi 2.
* **`#SingleInstance Force`**: mencegah lebih dari satu instance script berjalan. Jika sudah ada instance aktif, script baru akan otomatis menggantikannya.


```ahk
; ===== Toggle ON/OFF semua hotkeys =====
#SuspendExempt
^!p::{                            ; Ctrl+Alt+P
    Suspend(-1)                   ; toggle suspend
    ToolTip "AHK keymaps: " (A_IsSuspended ? "OFF" : "ON"), 10, 10
    SetTimer (() => ToolTip()), -800
}
#SuspendExempt False
```

* **`#SuspendExempt`**: instruksi agar hotkey berikutnya tidak terpengaruh oleh status *suspend*.
* **`^!p::`**: mendefinisikan hotkey `Ctrl+Alt+P`.
* **`Suspend(-1)`**: melakukan toggle suspend (mengaktifkan/menonaktifkan seluruh hotkeys lain dalam script).
* **`ToolTip`**: menampilkan notifikasi singkat mengenai status saat ini, yaitu `ON` (aktif) atau `OFF` (suspended).
* **`SetTimer`**: menghapus tooltip setelah 800 milidetik.
* **`#SuspendExempt False`**: mengembalikan perilaku default, yaitu hotkeys berikutnya akan dipengaruhi oleh suspend.

Fungsionalitas ini memungkinkan pengguna untuk mengaktifkan atau menonaktifkan seluruh custom keymaps hanya dengan menekan **Ctrl + Alt + P**.

```ahk
; (opsional) Kill switch kalau perlu keluar total
^!q::ExitApp
```

* **`^!q::ExitApp`**: mendefinisikan hotkey `Ctrl+Alt+Q` untuk menutup seluruh script secara permanen (*kill switch*).

```ahk
; ===== Hotkeys kamu (contoh, context Neovim/terminal) =====
#HotIf WinActive("ahk_exe WindowsTerminal.exe") 
    or WinActive("ahk_exe alacritty.exe") 
    or WinActive("ahk_exe nvim-qt.exe")

CapsLock::Send "{Escape}"
+CapsLock::{
    state := GetKeyState("CapsLock", "T")
    SetCapsLockState(!state)
}
#HotIf
```

* **`#HotIf`**: membatasi hotkeys agar hanya aktif jika kondisi tertentu terpenuhi, dalam hal ini saat jendela aktif adalah:

  * `WindowsTerminal.exe`
  * `alacritty.exe`
  * `nvim-qt.exe`

* **`CapsLock::Send "{Escape}"`**: menukar fungsi tombol **CapsLock** menjadi **Escape**.

* **`+CapsLock`**: mendefinisikan kombinasi **Shift + CapsLock**.

  * `GetKeyState("CapsLock", "T")` → memeriksa status CapsLock (aktif/nonaktif).
  * `SetCapsLockState(!state)` → membalikkan status CapsLock (toggle).

* **`#HotIf` (tanpa kondisi)**: mengakhiri blok kondisi, sehingga hotkeys selanjutnya tidak lagi terbatas pada aplikasi tersebut.


Penggunana konfigurasi `#HotIf` harus dilakukan dengan benar! Kita harus mengetahui nama file executable apa yang akan mengaktifkan hotkeys. Caranya, masuk ke system tray, lalu pilih icons AutoHotkeys, 

![[DATA DOKUMENTASI/Custom AutoHotkey/src/Custom Escape dengan AutoHotkey-9.png]]

... lalu klik kanan dan pilih `Window spy`:

![[DATA DOKUMENTASI/Custom AutoHotkey/src/Custom Escape dengan AutoHotkey-10.png]]

Maka otomatis kita akan terbawa pada tampilan seperti ini:

![[DATA DOKUMENTASI/Custom AutoHotkey/src/Custom Escape dengan AutoHotkey-11.png]]

Lalu, untuk setiap jendela aplikasi atau file executable yang ingin kita set untuk menggunakan custom keymaps dari AutoHotkey, lihat saja pada bagian **Program Manager**, yaitu nilai dari `ahk_exe`, yang menunjukan nama aplikasi. Nah nama aplikasi inilah yang perlu kita tulis di bagian `HotIf`. Misalnya seperti contoh berikut, ketika aplikasi yang berbeda, akan menunjukan nama file executable pada `ahk_exe` yang berbeda juga:

![[DATA DOKUMENTASI/Custom AutoHotkey/src/demo perubahan ahk_exe.mp4]]

Tampak jelas bahwa nama dari software yang kita buka adalah seperti:
- **windowsTerminal.exe**
- **alacritty.exe**

### Ringkasan Fungsi

1. **Ctrl + Alt + P** → toggle seluruh hotkeys aktif/nonaktif, dengan notifikasi tooltip.
2. **Ctrl + Alt + Q** → keluar sepenuhnya dari script.
3. Saat berada di **Windows Terminal**, **Alacritty**, atau **Neovim-Qt**:

   * **CapsLock** berfungsi sebagai **Escape**.
   * **Shift + CapsLock** tetap berfungsi untuk toggle CapsLock.

## 3.3 | Aktif Ketika Startup

Untuk cara ketiga, kita bisa membuat AutoHotkey langsung aktif ketika kita pertama kali menyalakan komputer, tanpa kita perlu menyalakanya secara manual. Ketika menyalakan komputer, script AutoHotkey langsung aktif secara otomatis. Caranya adalah dengan sedikit mengutak-atik `Task Scheduler`:

Tekan tombol `windows`, atau klik `Windows`, lalu ketikan kata kunci `Task Scheduler`

![[DATA DOKUMENTASI/Custom AutoHotkey/src/Custom Escape dengan AutoHotkey-12.png]]

Pada bagian jendela kanan, atau jendela `Actions`, pilih menu `Create Task...`:

![[DATA DOKUMENTASI/Custom AutoHotkey/src/Custom Escape dengan AutoHotkey-13.png]]

### 3.3.1 | General

Jendela pertama adalah jendela `General`. Disini, beri nama task misal `Neovim AutoHotkey`. Untuk deksripsi bebas, terserah ingin diisi apa, asalkan jelas dan deskriptif, menjelaskan apa maksud dari task yang kita buat. Misal:

*Task untuk custom keymaps Neovim dengan AutoHotkey ketika start up*

Centang juga pada bagian **Run only when user is logged on**. Ini menadai bahwa ketika user sedang masuk ke perangkat, maka task akan berjalan.

Jangan lupa centang **Run with highest privileges**. Opsi **Run with highest privileges** pada Task Scheduler berfungsi untuk menjalankan tugas dengan hak administrator. Pengaturan ini diperlukan apabila aplikasi yang akan dikendalikan melalui AutoHotkey dijalankan dalam mode administrator, karena tanpa hak yang setara, AutoHotkey tidak akan dapat mengirim perintah atau hotkey ke aplikasi tersebut. Namun, apabila seluruh aplikasi yang digunakan berjalan dalam mode standar (non-administrator), opsi ini tidak wajib diaktifkan.

Lalu pada bagian `Configure for:` isi sesuai spesifikasi Windows yang digunakan.

### 3.3.2 | Triggers

Masuk ke jendela kedua, yaitu `Triggers`. Klik `New...`, lalu pada bagian `Begin the task:` pilih saja `At log on`. Ini artinya kita akan menjalankan script auto hotkey, ketika pengguna login ke perangkat, biasanya tepat setelah menyalakan komputer. Setelah selesai klik `Ok`

![[DATA DOKUMENTASI/Custom AutoHotkey/src/Custom Escape dengan AutoHotkey-14.png]]

### 3.3.3 | Actions

Sekarang beralih ke jendela ketiga, yaitu `Actions`. Klik `New...`, dan pada bagian `Action:`, pilih `Start a program`, artinya mengeksekusi program yang akan kita pilih pada task ini. Dan bagian paling penting, adalah pada bagian settings, yaitu pada bagian `Program/script:`, kita browse lokasi `caps_escape.ahk`, karena pada bagian ini kita memberi tahu bahwa yang akan dieksekusi adalah program AutoHotkey kita. Lalu klik `Ok`.

![[DATA DOKUMENTASI/Custom AutoHotkey/src/Custom Escape dengan AutoHotkey-15.png]]

### 3.3.4 | Conditions

Lalu, masuk ke jendela keempat yaitu `Conditions`. Pada jendela ini, kita uncheck semua pilihan yang ada. Karena kondisi ini mengatur bahwa task hanya akan dijalankan jika pilihan yang dicheck terpenuhi atau bernilai true. AutoHotkey tidak perlu mulai berjalan ketika komputer idle (tidak digunakan selama beberapa waktu), tidak perlu ketika laptop sedang dicharge atau menggunakan AC power, dan tidak perlu terhubung ke jaringan tertentu. Jadi, uncheck semua pilihan.

![[DATA DOKUMENTASI/Custom AutoHotkey/src/Custom Escape dengan AutoHotkey-16.png]]

### 3.3.5 | Settings

Lalu, jendela terakhir, adalah pada bagian `Settings`. Pada bagian ini, kita mengspesifikan task yang kita buat. Cukup pilih 2 pilihan pertama saja, yaitu:

- **Allow task to be run on demand** → ✔️ (boleh jalan manual kalau mau test)
- **Run task as soon as possible after a scheduled start is missed** → ✔️


Lalu matikan opsi-opsi berikut:
- **If the task fails, restart every…** → matikan dulu (kalau script AHK crash, lebih baik jalankan ulang manual)
- **Stop the task if it runs longer than…** → jangan dipakai, karena AHK memang harus jalan terus
- **If the running task does not end when requested, force it to stop** → matikan
- **If the task is not scheduled to run again, delete it after…** → matikan

Lalu, pada bagian **If the task is already running, then the following rule applies:** kita pilih saja **Do not start a new instance**

Kenapa?  

Karena script AHK biasanya cuma perlu **1 instance** saja yang jalan di background. Kalau pilih yang lain (misalnya _Run a new instance in parallel_), bisa bikin dobel-dobel script jalan dan malah bentrok.

![[DATA DOKUMENTASI/Custom AutoHotkey/src/Custom Escape dengan AutoHotkey-17.png]]

Setelah semua konfigurasi dilakukan, klik `Ok`. Nah jika sudah berhasil terpasang, maka pada bagian `Task Scheduler Library`, akan muncul task yang baru saja kita buat.

![[DATA DOKUMENTASI/Custom AutoHotkey/src/Custom Escape dengan AutoHotkey-18.png]]

Silahkan restart komputer, dan jika notifikasi ini muncul ketika pertama kali startup, artinya konfigurasi kita berhasil:

![[DATA DOKUMENTASI/Custom AutoHotkey/src/Custom Escape dengan AutoHotkey-19.png]]