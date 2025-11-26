---
obsidianUIMode: preview
sumber: duniailkom
level: pemula
bahasa: C++
tanggal_study: 2024-10-01T23:07:00
total_study: 3
tags:
  - Cpp
id: DIB2
---


# Tutorial Belajar C++ Part 4: Cara Menjalankan Kode C++ (Proses Compile)

18 Oct 20 

Dalam tutorial sebelumnya kita sudah selesai [Menginstall aplikasi Code::Block](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-cara-menginstall-codeblock/ "Tutorial Belajar C++ Part 3: Cara Menginstall Code::Block"). Kali ini akan dilanjutkan dengan cara menjalankan kode program bahasa C++ menggunakan Code::Block, atau biasa juga disebut dengan **cara men-compile kode program C++**.

---

### Membuat File C++

Silahkan buka aplikasi **Code::Block**. Berikut tampilan awal aplikasi tersebut:

[![Tampilan Code Block 20](https://www.duniailkom.com/wp-content/uploads/2020/10/Tampilan-Code-Block-20.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Tampilan-Code-Block-20.png)

Tampilan **Code::Blocks** memang cukup rumit, tapi kita tidak perlu paham semua menu yang ada. Yang akan dipakai untuk menjalankan kode C++ hanya sebagian kecil saja.

Untuk membuat file baru, klik menu **File -> New -> Empty File**, atau bisa juga dengan menekan kombinasi tombol **CTRL+ SHIFT+ N**.

[![](https://www.duniailkom.com/wp-content/uploads/2020/10/Cara-membuat-file-baru-di-Code-Block.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Cara-membuat-file-baru-di-Code-Block.png)

Di bagian tengah **Code::Blocks** akan tampil sebuah file teks kosong. Disinilah nantinya kita menulis kode program bahasa C++.

[![](https://www.duniailkom.com/wp-content/uploads/2020/10/Tempat-Menulis-Kode-program-di-Code-Block.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Tempat-Menulis-Kode-program-di-Code-Block.png)

Agar bisa langsung praktek menulis sebuah file bahasa C++, silahkan ketik kode program berikut ke dalam **Code::Blocks**:

```Cpp
#include <iostream>
 
int main()
{
  std::cout << "Hello World!";
  return 0;
}
```

Untuk sementara maksud kode diatas bisa diabaikan karena akan kita bahas dalam tutorial selanjutnya. Inti dari kode ini cuma menampilkan sebuah teks **"Hello World!"**.

Pastikan anda mengetik kode program yang **sama persis**. Jika ada salah satu huruf atau satu karakter saja yang kurang, kode program C++ akan error. Untuk amannya silahkan copy paste kode tersebut ke dalam editor **Code::Block**.

---

### Menyimpan File Kode Program C++

Selanjutnya siapkan folder tempat file kode program C++ akan disimpan. Supaya lebih rapi, saya sudah membuat folder **"belajar_cpp"** di Drive **D**. Anda bisa pakai folder yang sama atau buat folder lain sesuai keinginan.

Kembali ke **Code::Blocks**, save file yang sudah kita tulis tadi dengan cara menekan kombinasi tombol **CTRL+ S** atau klik menu **File-> Save file**.

Sesaat kemudian akan tampil jendela **Save file**. Simpan file ke dalam folder **D:\belajar_cpp** yang sudah disiapkan sebelumnya.

[![](https://www.duniailkom.com/wp-content/uploads/2020/10/Simpan-file-C-dengan-extension-cpp.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Simpan-file-C-dengan-extension-cpp.png)

Save file sebagai **hello_world.cpp.** Untuk **bahasa pemrograman C++**, nama file harus disimpan dengan akhiran ***.cpp**. Anda juga boleh menggunakan nama lain sepanjang berakhiran ***.cpp** seperti **duniailkom.cpp**, **andi.cpp**, atau **punyaku.cpp**

Ketika file sudah di save, tampilan akan kembali ke editor **Code::Blocks** dan kode program yang sudah kita tulis sebelumnya akan berwarna. Inilah fitur _syntax highlighting_ dari **Code::Blocks**.

IDE **Code::Blocks** memberi warna berbeda untuk setiap kode program C++. Dengan demikian jika kita salah ketik atau salah tulis kode program, warna teks yang dihasilkan juga akan berbeda.

Untuk memastikan file sudah tersimpan, buka Windows Explorer dan cari apakah file **hello_world.cpp** sudah ada di folder **D:\belajar_cpp**

[![](https://www.duniailkom.com/wp-content/uploads/2020/10/Folder-yang-berisi-file-cpp.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Folder-yang-berisi-file-cpp.png)

---

### Menjalankan File Kode C++

File kode program C++ sudah jadi. Sekarang saatnya kita jalankan kode tersebut. Untuk bahasa pemrograman dengan teknik compiler seperti C++, ada 2 proses yang harus di lakukan: **compile** dan **run**.

Proses **compile** dipakai untuk mengolah file bahasa C++ menjadi _object file_ dan juga file _.exe_. Sedangkan proses **run** akan menjalankan file .exe yang dihasilkan tadi. Bagi pemula kadang kedua proses ini sering dianggap satu kesatuan.

> Penjelasan lebih lanjut mengenai proses **compile** dan apa itu **object file** saya bahas di [Tutorial Belajar C: Pengertian Compiler, Linker dan IDE.](https://www.duniailkom.com/tutorial-belajar-c-pengertian-compiler-linker-dan-ide/) Meskipun itu proses dalam bahasa C, tapi pada dasarnya tidak berbeda dengan bahasa C++.

Untuk meng-compile file kode program C++ di Code::Block, pilih menu **Build -> Compile current File** atau bisa juga dengan menekan tombol **CTRL + SHIFT + F9**.

Di dalam Code::Block juga terdapat proses build yang pada dasarnya nyaris sama dengan proses compile. Ini pun juga bisa di jalankan dengan cara men-klik icon gear berikut:

[![](https://www.duniailkom.com/wp-content/uploads/2020/10/Proses-Build-file-kode-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Proses-Build-file-kode-C.png)

Proses compile akan berlangsung beberapa saat (mungkin hanya 1 detik untuk kode sederhana seperti ini). Log atau catatan mengenai proses compile juga bisa dilihat pada tab "**Build messages**" di bagian bawah:

![[compile result.png]]

Jika tampil teks berikut:

```
=== Build file: "no target" in "no project" (compiler: unknown) ===
=== Build finished: 0 error(s), 0 warning(s) (0 minute(s), 1 second(s)) ===

```

Artinya proses compile berhasil dan kode program kita tidak memiliki error.

Untuk lebih memastikan, silahkan buka kembali folder **D:\belajar_cpp**. Sebelumnya hanya terdapat 1 file, yakni **hello_world.cpp**, sekarang akan ada 2 file tambahan: **hello_world.o** dan **hello_world.exe**.

[![Tambahan file object dan exe C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Tambahan-file-object-dan-exe-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Tambahan-file-object-dan-exe-C.png)

File **hello_world.o** merupakan _object file_ hasil proses compile. Object file ini digunakan secara internal oleh compiler bahasa C++ dan tidak perlu kita utak-atik.

Sedangkan file **hello_world.exe** adalah file akhir hasil compiler + linker, dimana object file sudah diproses lebih lanjut untuk menjadi program akhir.

Untuk melihat hasil kode program, kembali lagi ke Code::Block. Sekarang kita jalankan proses **Run**. Caranya, buka menu **Build -> Run**, atau tekan tombol **Ctrl + F10**, atau bisa juga klik icon panah warna hijau di sebelah icon build:

[![](https://www.duniailkom.com/wp-content/uploads/2020/10/Run-kode-program-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Run-kode-program-C.png)

Dan berikut hasil dari run file **hello_world.cpp**:

[![](https://www.duniailkom.com/wp-content/uploads/2020/10/Menjalankan-Hello-World-di-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Menjalankan-Hello-World-di-C.png)

**Done**! Jika dalam jendela cmd tampil teks "Hello World!" di baris pertama, artinya kita sudah berhasil men-compile dan menjalankan kode program yang ditulis dalam bahasa C++.

Untuk menutup jendela ini, tekan tombol sembarang di dalam cmd atau bisa juga klik icon silang di sudut kanan atas (seperti menutup aplikasi pada umumnya). Selama jendela hasil ini tidak ditutup, maka kita tidak akan bisa melakukan proses compile atau run file lain dari Code::Block.

Code::Block juga menyediakan tombol untuk proses build dan run sekaligus, yakni dengan men-klik icon "**Build and Run**" atau menekan tombol **F9**:

[![](https://www.duniailkom.com/wp-content/uploads/2020/10/Tombol-Build-dan-run-di-code-block.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Tombol-Build-dan-run-di-code-block.png)

Dengan menekan tombol "**Build and Run**" atau tombol **F9**, kode C++ yang ada langsung di compile dan dijalankan sekaligus. Ini sangat praktis karena hasilnya bisa langsung terlihat.

---

Dalam tutorial ini kita sudah membahas Cara Menjalankan Kode C++ menggunakan aplikasi Code::Block. Berikutnya akan masuk ke [Struktur Dasar Kode Program C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-struktur-dasar-kode-program-c-plus-plus/ "Tutorial Belajar C++ Part 5: Struktur Dasar Kode Program C++").