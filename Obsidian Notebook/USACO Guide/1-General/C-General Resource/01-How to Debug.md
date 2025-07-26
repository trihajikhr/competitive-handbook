---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: How to Debug
sumber:
  - USACO guide
date_learned: 2025-07-19T16:16:00
tags:
  - general-usaco
  - debug
---
Link Sumber: 


```cardlink
url: https://usaco.guide/general/debugging-checklist?lang=cpp
title: "How to Debug"
description: "What to do when your solution doesn't work."
host: usaco.guide
favicon: https://usaco.guide/favicon-32x32.png?v=486b7e9b938c7be5463018a5e8da37f8
image: https://usaco.guide/static/2863837723a7041cb58da9f7856ce0fb/0ff54/social-media-image.jpg
```


---
# How to Debug

*What to do when your solution doesn't work.*

> [!NOTE] Resource
> - [ ]  KACTL: [Troubleshooting](https://github.com/kth-competitive-programming/kactl/blob/master/content/contest/troubleshoot.txt)  -> things to try in an ICPC contest
> - [ ]  Errichto: [Asking for help FAQ](https://codeforces.com/blog/entry/64993)

Modul ini didasarkan pada sumber-sumber yang disebutkan sebelumnya. Saya hanya menyertakan konten yang paling relevan untuk USACO.

> [!NOTE] Potongan Kode (Code Snippets)
> Modul ini tidak berisi kode apa pun. Silakan lihat modul [Basic Debugging](https://usaco.guide/general/basic-debugging) dan [Debugging C++](https://usaco.guide/general/debugging-cpp) untuk informasi lebih lanjut.

## Pre-Submit

Pastikan bahwa kodenya mudah dibaca (setidaknya oleh dirimu sendiri).  
- Mengikuti tips penulisan kode dari modul [Adding Solutions](https://usaco.guide/general/adding-solution#code-conventions) bisa sangat membantu dalam hal ini.
## Wrong Answer (or Runtime Error)

- Apakah format output-mu sudah benar?
	- Apakah kamu sudah menghapus output debug sebelum mengumpulkan?


<br/>

- Apakah kamu menangani semua edge cases (seperti $N = 1$) atau kasus khusus?


<br/>

- Untuk soal dengan beberapa test case yang terpisah (seperti [yang satu ini](http://www.usaco.org/index.php?page=viewproblem2&cpid=1141)), apakah kamu sudah menghapus semua struktur data di antara setiap test case?
	- Ingat, solusi kamu mungkin hanya salah ketika satu test case diikuti oleh test case yang lebih kecil.

<br/>

- Apakah kamu sudah memahami soal dengan benar? Baca lagi seluruh pernyataan soal.
<br/>

- Baca lagi kodenya.  
	- Apakah kamu tertukar antara $N$ dan $M$, $i$ dan $j$, dan sejenisnya?

<br/>

- Apakah ada variabel [Shadowed](https://en.wikipedia.org/wiki/Variable_shadowing#C++) / yang tertimpa, tidak digunakan, atau belum diinisialisasi?  
	- (C++) Kompilasi dengan opsi [peringatan](https://usaco.guide/general/debugging-cpp#gcc-warning-options) seperti `-Wall -Wshadow` bisa mendeteksi hal ini.

<br/>

- Apakah ada perilaku yang tidak terdefinisi? Ini bisa membuat hasil di laptop berbeda dengan saat submit ke USACO. Coba jalankan kodenya di beberapa tempat (misalnya [USACO Guide IDE](https://ide.usaco.guide/, Codeforces Custom Test), [Codeforces Custom Test](https://codeforces.com/problemset/customtest) dan lihat apakah hasilnya selalu sama. Contoh perilaku tidak terdefinisi:
	- (C++) Variabel belum diinisialisasi
	- (C++) Tidak mengembalikan apa pun dari fungsi non-void
	- (C++) Akses array di luar batas  (Gunakan `.at()` jika perlu, dibahas [disini](https://usaco.guide/general/debugging-cpp/#checking-for-out-of-bounds))
	- (C++ / Java) [Signed Integer Overflow](https://stackoverflow.com/questions/4240748/allowing-signed-integer-overflows-in-c-c): pada integer bertanda  (USACO biasanya memberi catatan jika butuh `long long`)
	- (C++) Melakukan bit shift pada integer 32-bit sebanyak ≥ 32 bit
	> Perhatikan bahwa besarnya bilangan dalam soal ini mungkin mengharuskan kamu untuk menggunakan tipe data integer 64-bit (contohnya `long long` di C/C++).
	- (C++) Melakukan shift pada integer 32-bit sebanyak $≥ 32$ bit
	Di C++, kompilasi dengan opsi [instrumentasi](https://usaco.guide/general/debugging-cpp#gcc-debug-options) seperti `-fsanitize=address,undefined` bisa membantu mendeteksi kesalahan seperti ini.

<br/>

- Tambahkan [assertion](https://usaco.guide/general/basic-debugging#assertions--warnings), lalu submit ulang.

<br/>

- Bilangan pecahan (floating point)
	- Apakah ada nilai NaNs (contohnya akar dari bilangan negatif)?  
	- Cobalah menggunakan tipe data dengan presisi lebih tinggi (contoh: `long double` daripada `double` di C++).  
	- Apakah kamu mencetak output dengan jumlah digit presisi yang tepat?

<br/>

- Apakah kamu yakin algoritmamu benar?  
	- Coba jalankan algoritma untuk kasus yang sederhana / buat beberapa test case untuk diuji.  
	- Tulis program pembuat test case, lalu bandingkan hasil solusi kamu dengan solusi yang lebih lambat atau solusi model jika tersedia.
		- Lihat juga bagian [stress testing](https://usaco.guide/general/basic-debugging#stress-testing) untuk informasi lebih lanjut.

## Runtime Error

- Apakah ada perilaku tak terdefinisi (undefined behavior)? (lihat bagian sebelumnya)

- Apakah ada assertion yang mungkin gagal?

- Apakah ada kemungkinan pembagian dengan 0? (misalnya `mod 0`)

- Apakah ada kemungkinan rekursi tanpa akhir (infinite recursion)?

- Apakah ada pointer atau iterator yang tidak valid?

- Apakah kamu menggunakan terlalu banyak memori?

## Time Limit Exceeded
- Apakah ada kemungkinan loop tanpa henti (infinite loop)?

- Apa kompleksitas algoritma kamu?

- Apakah kamu sudah menghapus output debug sebelum submit? (contohnya: mencetak terlalu banyak informasi ke _standard error_)

- Apakah ada penyalinan data yang tidak perlu? C++ – Pertimbangkan untuk mengirim variabel sebagai referensi (`&`) daripada salinan.

- C++ – Coba ganti `vector` dengan `array` jika memungkinkan.

## Last Resort
- Tulis ulang solusi kamu dari awal. 
	- Pastikan untuk menyimpan salinan solusi yang lama, karena selalu ada kemungkinan kamu justru menambahkan bug baru di solusi yang baru.

## Before Posting on the [USACO Guide Forum](https://forum.usaco.guide/)

- Jika kamu telah menemukan test case kecil di mana programmu gagal dan kamu tahu kenapa output yang benar seperti itu, kamu seharusnya bisa mencari tahu sendiri kenapa programmu salah.
	- Tambahkan perintah `print` di kodenya dan bandingkan outputnya dengan hasil yang kamu dapat saat menyimulasikan programnya secara manual.
	- Periksa apakah ada perilaku tak terdefinisi seperti yang sudah dijelaskan sebelumnya.

<br/>

- Jika kamu belum menemukan test case kecil di mana solusi kamu gagal:
	- Coba unduh data uji resmi dan lihat apakah programmu gagal pada test case kecil.
	- Jika itu juga tidak berhasil, coba buat sendiri test case kecil yang bisa menyebabkan solusi kamu gagal, seperti yang sudah dijelaskan sebelumnya.