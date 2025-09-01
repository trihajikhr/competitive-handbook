---
obsidianUIMode: preview
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

Untuk aplikasi yang bisa digunakan, ada banyak. Namun, kali ini kita akan menggunakan aplikasi atau software *autoHotkey*, yang bisa didapat dengan memasukan kata kunci tersebut ke pencarian, yang kemudian akan dibawa ke situs [autohotkey](https://www.autohotkey.com/):

![[Custom Escape dengan Auto Hot Key-1.png]]

Unduh versi terbaru (yang bukan deprecated) yang disediakan situs tersebut, dan lakukan penginstalan seperti biasa:

```ad-warning
Untuk versi terbaru per tanggal 1 September 2025 adalah versi v2.0. Kunjungi situsnya langsung untuk mendapat versi terbaru yang disediakan!
```


![[Custom Escape dengan Auto Hot Key-2.png]]

Pilih lokasi penginstalan, namun kita bisa biarkan saja ke lokasi defaultnya, lagipula ukuran instalasi ini cukup kecil. Tetapkan AutoHotkey untuk bisa digunakan oleh semua user dengan memilih `All user`, lalu klik `Install`, dan klik yes jika ada notifikasi administration. Maka program pun berhasil terinstall jika menampilkan jendela baru seperti ini:

![[Custom Escape dengan Auto Hot Key-3.png]]

## 2.2 | Konfigurasi
Setelah masuk ke mode terakhir, kita bisa membuat custom keymaps dengan cara memilih menu `New script`, sehingga kita akan dibawa ke tampilan seperti ini:

![[Custom Escape dengan Auto Hot Key-4.png]]

Buat nama file yang sesuai, misalnya saja `caps_escape`. Pilih lokasi dimana file ini akan disimpan. Nah lokasi penyimpanan file ini harus cukup strategis, supaya kita bisa melakukan pengeditan dan penambahan konfigurasi script dengan mudah, tanpa perlu masuk ke banyak subfolder yang menyulitkan. Jadi, taruh saja misal di dalam drive D, supaya mudah ditemukan. 

Tekan saja icon folder untuk mengatur lokasi filenya secara manual ke folder strategis, dan jangan menerima lokasi default yang diberikan:
  
  ![[Custom Escape dengan Auto Hot Key-6.png]]

```ad-info
Sebenarnya tidak harus diatur foldernya untuk sekarang, karena nanti kita bisa memindahkanya lagi secara manual. Tapi untuk menghindari faktor lupa, lebih baik diatur sekarang saja!
```


Setelah diatur lokasi strategisnya, kita pilih `Empty`, artinya kita akan membuat file `.ahk` yang isinya masih kosong. Maka, di folder tempat kita membuat file, akan muncul file baru yaitu `caps_escape.ahk` seperti ini:

![[Custom Escape dengan Auto Hot Key-5.png]]

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
    
- `SetCapsLockState(!state)` → ubah ke kebalikannya (toggle). Kalau CapsLock nyala → dimatiin, kalau mati → dinyalain.
### Jadi intinya:

- **CapsLock** = jadi **Escape**.
    
- **Shift + CapsLock** = toggle CapsLock seperti normal.

<br/>

---

# 3 | Settingan Lanjutan
## 3.1 | Mengaktifkan Manual

Jika semisal kita hanya menggunakan custom keymaps di waktu-waktu tertentu saja, dan ingin menggunakan konfigurasi AutoHotkey yang lebih simple seperti cara diatas, maka kita bisa set agar AutoHotkey hanya aktif ketika kita aktifkan saja.

Cara ini adalah cara yang paling mudah, karena kita cukup double klik pada file `caps_escape.ahk` yang sebelumnya kita buat, dan otomatis custom keymaps aktif. Ketika script akfit, maka akan muncul icon hijau H pada system tray (pojok kanan bawah):

![[Custom Escape dengan Auto Hot Key-7.png]]


Untuk mematikanya, caranya cukup mudah. Pada Tray Icon, klik kanan AutoHotkey, lalu pilih `Exit` untuk mematikan script.

## 3.2 | Toggle On Off & Auto Detect

Cara yang kedua ini jauh lebih fleksibel, karena kita tidak perlu mencari file `caps_escape.ahk` yang baru saja kita buat untuk mengaktifkanya dengan double klik. Melainkan cukup dengan menggunakan kombinasi tombol atau keymaps yang kita konfigurasikan, atau mentriggernya dengan membuka file executable tertentu yang kita tentukan di konfigurasi script. Kita bisa membuat tambahan konfigurasi pada `caps_escape.ahk`. Semisal sebagai berikut:

```ahk
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

```ad-info
Penggunana konfigurasi `#HotIf` harus dilakukan dengan benar! Kita harus mengetahui nama file executable apa yang akan mengaktifkan hotkeys. Caranya, masuk ke Tray icon, lalu pilih icons AutoHotkeys, 

![[Custom Escape dengan Auto Hot Key-7.png|500]]

... lalu klik kanan dan pilih `Windows spy`:

![[Custom Escape dengan Auto Hot Key-8.png|500]]

Maka otomatis kita akan terbawa pada tampilan seperti ini:

![[Custom Escape dengan Auto Hot Key-9.png|500]]

Lalu, untuk setiap jendela aplikasi atau file executable yang ingin kita gunakan sebagai trigger dari AutoHotkey, lihat saja pada bagian **Program Manager**, yaitu nilai dari `ahk_exe`, yang menunjukan nama aplikasi. Nah nama aplikasi inilah yang perlu kita tulis di bagian `HotIf`. Misalnya seperti contoh berikut, ketika aplikasi yang berbeda, akan menunjukan nama file executable pada `ahk_exe` yang berbeda juga:

![[20250901-0957-26.0811059.mp4]]

Tampak jelas bahwa nama dari software yang dibuka adalah seperti:
- windowsTerminal.exe
- alacritty.exe
```
### Ringkasan Fungsi

1. **Ctrl+Alt+P** → toggle seluruh hotkeys aktif/nonaktif, dengan notifikasi tooltip.
2. **Ctrl+Alt+Q** → keluar sepenuhnya dari script.
3. Saat berada di **Windows Terminal**, **Alacritty**, atau **Neovim-Qt**:

   * **CapsLock** berfungsi sebagai **Escape**.
   * **Shift + CapsLock** tetap berfungsi untuk toggle CapsLock.

## 3.3 | Aktif Ketika Startup

Untuk cara ketiga, bisa dilakukan jika semisal kita ingin semua konfigurasi AutoHotkey kita tidak terbatas pada aplikasi atau kondisi apapun. Ketika menyalakan komputer, script AutoHotkey langsung aktif secara otomatis. Caranya adalah dengan menaruh script di **Startup Folder**

1. Simpan script kamu, misalnya `caps_escape.ahk`.
2. Tekan `Win + R` → ketik: `shell:startup` → Enter. Ini akan membuka folder **Startup**.
3. Copy file `caps_escape.ahk` (atau shortcut-nya) ke folder itu.  

Setiap kali Windows menyala, script otomatis dijalankan.

Tampilan folder startup adalah seperti ini:

![[Custom Escape dengan Auto Hot Key-10.png]]