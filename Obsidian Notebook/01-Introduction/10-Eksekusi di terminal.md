---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Eksekusi di terminal
sumber: Google.com, AI
tags:
  - general
---
---
# Eksekusi di terminal
Berikut langkah‐langkah dasar untuk mengompilasi dan menjalankan (eksekusi) file C++ (.cpp) di terminal (Linux/macOS atau Windows dengan WSL/Git Bash):

---

## 1. Pastikan Compiler Terinstal

Biasanya yang paling umum dipakai adalah **g++** (bagian dari paket GNU Compiler Collection).  
Cek dengan perintah:

```bash
g++ --version
```

Kalau muncul versi, berarti g++ sudah terpasang. Jika belum, instal dulu:

- **Ubuntu/Debian (Linux)**:
    
    ```bash
    sudo apt update
    sudo apt install build-essential
    ```
    
- **Fedora/CentOS (Linux)**:
    
    ```bash
    sudo dnf install gcc-c++
    ```
    
- **macOS** (dengan Homebrew):
    
    ```bash
    brew install gcc
    ```
    
- **Windows** (WSL/MinGW/Git Bash):  
    Pasang WSL kemudian `sudo apt install build-essential`, atau pasang MinGW-w64.
    

---

## 2. Menyusun (Compile) File .cpp

Misalkan kamu punya file bernama `program.cpp`. Buka terminal di folder tempat file tersebut berada, lalu ketik:

```bash
g++ program.cpp -o program
```

Keterangan:

- `g++` → pemanggil compiler C++.
    
- `program.cpp` → nama file sumber C++ kamu.
    
- `-o program` → beri nama **output executable** menjadi `program` (bebas, bisa `main`, `a.out`, atau nama lain).
    

Jika kamu ingin menggunakan standar C++ tertentu (misalnya C++17), tambahkan opsi `-std`:

```bash
g++ -std=c++17 program.cpp -o program
```

Atau jika ingin mengaktifkan semua peringatan (warnings) untuk debugging:

```bash
g++ -std=c++17 -Wall -Wextra program.cpp -o program
```

Contoh lengkap:

```bash
g++ -std=c++17 -Wall program.cpp -o program
```

- `-Wall` → menyalakan hampir semua peringatan umum agar kamu bisa memeriksa potensi bug.
    

---

## 3. Menjalankan (Run) Executable

Setelah berhasil dikompilasi tanpa error, di direktori yang sama akan muncul file bernama `program` (atau nama lain sesuai opsi `-o`). Jalankan dengan:

```bash
./program
```

- `./` berarti “jalankan berkas di direktori saat ini.”
    

Jika kamu tidak memberi opsi `-o <nama>`, compiler akan menghasilkan `a.out` secara default. Maka perintahnya:

```bash
g++ program.cpp
./a.out
```

---

## 4. Contoh Satu Langkah (Compile + Run Sekaligus)

Di beberapa kasus (contoh latihan cepat), kamu bisa ketik:

```bash
g++ program.cpp -o program && ./program
```

Artinya:

1. Jalankan `g++ program.cpp -o program`.
    
2. Jika compile berhasil (exit code 0), langsung jalankan `./program`.
    

Atau:

```bash
g++ -std=c++17 program.cpp && ./a.out
```

(Tanpa `-o` akan muncul `a.out`.)

---

## 5. Ringkasan Sintaks Utama

1. **Kompilasi tanpa opsi khusus**
    
    ```bash
    g++ file.cpp -o nama_executable
    ```
    
2. **Kompilasi dengan standar C++ tertentu (misal C++17)**
    
    ```bash
    g++ -std=c++17 file.cpp -o nama_executable
    ```
    
3. **Menjalankan (eksekusi)**
    
    ```bash
    ./nama_executable
    ```
    
4. **Compile + Run sekaligus**
    
    ```bash
    g++ file.cpp -o nama_executable && ./nama_executable
    ```
    
