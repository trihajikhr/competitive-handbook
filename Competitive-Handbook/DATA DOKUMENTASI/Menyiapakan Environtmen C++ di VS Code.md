---
obsidianUIMode: preview
note_type: Dokumentasi
judul_dokumentasi: environtment c++ di vscode
date_add: 2025-05-08T10:42:00
status_dokumentasi: ❌Not-Finish
tags:
  - compiler
---
---

Hal yang perlu dilakukan untuk menyiapkan compiler di C++ agar kita bisa menjalankan kode C++ di Visual Studio Code adalah sebagai berikut:

# 1 | Menginstal VS Code
Hal pertama dan wajib, jelas dengan menginstal Visual Studio Code terlebih dahulu. Untuk mengunduh VS Code, bisa kunjungi situs resmi [VS Code](https://code.visualstudio.com/download), dan pilih sesuai dengan sistem operasi yang digunakan.

Setelah berhasil diunduh, lakukan instalasi selayakanya menginstal aplikasi pada umumnya.

# 2 | Menginstal Extension
## 2.1 | C/C++ by Microsoft (WAJIB)
Ekstensi **C/C++ by Microsoft** adalah ekstensi resmi dari Microsoft untuk mendukung pengembangan bahasa C dan C++ di Visual Studio Code. Ekstensi ini menyediakan fitur-fitur penting seperti IntelliSense, debugging, dan navigasi kode yang membuat pengalaman ngoding C++ jadi lebih produktif.

Berikut fitur penting yang disediakan:
#### IntelliSense

- Memberikan saran otomatis (auto-completion) saat kamu mengetik kode.
- Mendukung fitur seperti:
    - **Function signature help** (parameter apa yang harus dimasukkan)
    - **Code navigation**: bisa klik kanan dan "Go to Definition", "Peek Definition", dll.
    - **Highlight identifier**: menyorot semua variabel/fungsi dengan nama sama.
#### Linting dan Error Checking

- Menampilkan error & warning langsung di editor saat kamu mengetik.
- Mengandalkan compiler (`g++`/`clang++`) dan IntelliSense untuk mendeteksi masalah.

#### Debugging

- Mendukung debugging langsung di VS Code:
    - Breakpoint
    - Step over / Step into
    - Variable inspection
    - Call stack view
- Bekerja dengan **GDB / LLDB / MSVC Debugger**.

#### Konfigurasi Build / IntelliSense

- Mendukung file `c_cpp_properties.json` untuk mengatur:
    - Path header file (`includePath`)
    - Compiler yang digunakan (`compilerPath`)
    - Standar bahasa C/C++ (`cppStandard` / `cStandard`)
    - Mode IntelliSense (`intelliSenseMode`)

#### Multi-Platform Support

- Bisa digunakan di Windows, macOS, dan Linux.
- Cocok untuk berbagai toolchain: GCC, Clang, MSVC.

### Exstension lain
Exstension ini juga biasanya terikat dengan exstension Microsoft yang lain, seperti:
#### 🎨 C/C++ Themes

Memberi warna khusus untuk syntax C dan C++ agar lebih nyaman dibaca. 

Catatan sederhana:

- Tidak wajib.
- Hanya memengaruhi tampilan editor.
- Cocok jika kamu ingin suasana coding yang lebih jelas/estetik.
#### 📦 C/C++ Extension Pack

Bundel ekstensi yang direkomendasikan untuk ngoding C/C++ di VS Code.

Berisi seperti exstension:

- C/C++ (by Microsoft)
- CMake Tools
- CodeLLDB atau debugger lainnya
- Include Autocomplete
- Themes dan tools tambahan
## 2.2 | Code Runner (Disarankan)
**Code Runner** adalah ekstensi serbaguna yang memungkinkan kamu untuk mengeksekusi potongan kode dari berbagai bahasa pemrograman (termasuk C++) langsung dari dalam VS Code, tanpa perlu menulis atau mengatur `tasks.json` atau `launch.json`.


> [!NOTE] PENTING!
> Mengeksekusi kode dengan menggunakan `tasks.json` atau `launch.json` sifatnya lebih fleksibel. Kita bisa mengatur kerapian folder dengan mengatur agar file `.exe` berada pada folder yang sama. Hal ini membuat struktur folder menjadi rapi.
> 
> Penulis lebih memilih menggunakan `tasks.json` atau `launch.json` karena sturktur folder menjadi mudah ditata. Kita akan setitng 2 file ini nanti. Untuk sekarang, anggap saja exstension ini ditujukan untuk mereka para pemula.

Berikut fitur penting yang disediakan:

#### Jalankan Kode dengan Cepat

- Tekan `Ctrl+Alt+N` atau klik ikon ▶ di kanan atas editor untuk langsung menjalankan file aktif.
- Tidak perlu membuat file build manual (tapi hanya cocok untuk program kecil).

#### Mendukung Banyak Bahasa

- Mendukung lebih dari 40 bahasa pemrograman seperti Python, Java, C, C++, JavaScript, Go, dll.
- Otomatis mendeteksi bahasa dari ekstensi file.

#### Custom Output & Args

- Bisa mengatur bagaimana program dijalankan, termasuk:
    - Output terminal (integrated vs output window)
    - Argumen CLI (command-line arguments)
    - Compiler options (`-std=c++20`, dll)
#### Konfigurasi Mudah

- Semuanya bisa dikontrol dari file `settings.json`.
### Konfigurasi untuk C++

Agar Code Runner bisa menjalankan file C++ dengan benar, kamu bisa tambahkan konfigurasi ini ke `settings.json`:

```json
"code-runner.executorMap": {
    "cpp": "cd $dir && g++ -std=c++20 $fileName -o $fileNameWithoutExt && $dir/$fileNameWithoutExt"
},
"code-runner.runInTerminal": true,
"code-runner.saveFileBeforeRun": true
```

Penjelasan:

- `cd $dir`: pindah ke direktori tempat file berada
- `g++ -std=c++20`: compile file dengan standar C++20
- `-o $fileNameWithoutExt`: outputkan ke file dengan nama yang sama (tanpa `.cpp`)
- `runInTerminal`: agar bisa menerima input saat program dijalankan

> ❗ **Catatan**: Pastikan `g++` sudah tersedia di terminal VS Code (`where g++` berhasil).

---
### 📝 Kapan Sebaiknya Digunakan?

- Untuk skrip C++ singkat atau latihan algoritma kompetitif.
- Tidak cocok untuk proyek besar dengan dependency dan struktur build yang kompleks.
- Berguna sebagai alat **eksperimen cepat**.

## 2.3 | CMake Tools (Disarankan)

Ekstensi ini mempermudah kamu menjalankan dan membangun proyek C++ berbasis **CMake** langsung dari VS Code, tanpa terminal manual.


> [!NOTE] Catatan
> Pada saat awal-awal mengatur struktur folder dan file C++ di VS Code, aku menggunakan sedikit bantuan dari Exstension ini. Namun setelahnya, tidak terlalu signifikan pengaruhnya, setelah setting struktur folder dan file di lakukan dengan `tasks.json` atau `launch.json`. Sebagai pengingat, berikut isi dari dari file `Makefile`:
> 
> 
> 
> 
> 
> 
> 
> 

```Makefile
# Compiler dan flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Cari semua file .cpp di direktori saat ini
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
TARGET = program

# Aturan default untuk kompilasi
all: $(TARGET)

# Aturan untuk membuat target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Aturan untuk membuat file objek
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Aturan untuk menjalankan program
test: $(TARGET)
	./$(TARGET)

# Aturan untuk membersihkan file objek dan target
clean:
	rm -f $(OBJS) $(TARGET)

# Aturan phony untuk menghindari konflik dengan file bernama sama
.PHONY: all clean test
```

---

Berikut fitur penting yang disediakan:

- Deteksi otomatis `CMakeLists.txt`
- Pilih compiler/toolchain (kit)
- Build & run target dari status bar
- Integrasi debugging & unit test (opsional)

### Kapan dipakai:

✔ Proyek besar, multi-file, atau pakai library eksternal  
❌ Tidak wajib untuk latihan kompetitif/satu file

### Contoh `CMakeLists.txt` sederhana:

```cmake
cmake_minimum_required(VERSION 3.15)
project(MyApp)
set(CMAKE_CXX_STANDARD 20)
add_executable(MyApp main.cpp)
```

## 4 | Exstension Pelengkap


## Semnetaraa
MSYS2
```bash
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
```

```bash
pacman -S mingw-w64-x86_64-gcc
```

```bash
ls /mingw64/bin/g++.exe
```