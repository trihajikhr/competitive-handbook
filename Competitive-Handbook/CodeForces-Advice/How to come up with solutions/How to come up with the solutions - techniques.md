---
obsidianUIMode: preview
note_type: Advice
judul_materi: How to come up with the solutions - techniques
sumber: codeforces
date_learned: 2025-06-08T20:05:00
tags:
  - advice
  - problem-solving
---
Link Sumber: [How to come up with the solutions: techniques - Codeforces](https://codeforces.com/blog/entry/20548)

---
# How to come up with the solutions - techniques

Saat saya bekerja dengan para siswa, saya sering menghadapi situasi di mana jika sebuah soal tidak langsung tampak jelas bagi seorang siswa, maka hal itu membuat mereka tidak mampu menyelesaikannya. Memang, Anda sering mendengar tentang metode dan teknik tertentu. Namun, Anda jarang mendengar tentang bagaimana cara berpikir agar dapat menerapkannya. Dalam catatan ini, saya akan mencoba merangkum pengalaman saya dalam menyelesaikan soal-soal lomba pemrograman. Namun, beberapa saran juga bisa diterapkan untuk olimpiade matematika dan langkah awal Anda dalam penelitian akademik.

Jadi, Anda telah membaca sebuah soal dan Anda tidak tahu bagaimana cara menyelesaikannya. Cobalah teknik-teknik berikut ini, beberapa di antaranya sering kali sangat berguna.

## Teknik 1: "Total Recall"  
Cobalah mengingat beberapa soal serupa yang pernah Anda selesaikan. Cukup banyak soal yang tidak mengandung ide yang benar-benar baru. Jadi, kemungkinan besar, Anda bisa menggunakan pengalaman Anda dalam menyelesaikan soal serupa untuk menyelesaikan soal ini.

## Teknik 2: "Dari Spesifik ke Umum"  
Misalnya Anda telah menemukan solusi untuk soal tersebut (hore!). Mari kita pertimbangkan beberapa kasus khusus dari soal itu. Tentu saja, Anda bisa menerapkan algoritma/solusi terhadapnya. Oleh karena itu, untuk menyelesaikan soal secara umum, Anda perlu menyelesaikan semua kasus spesifiknya. Cobalah menyelesaikan beberapa (atau banyak) kasus spesifik, lalu cobalah untuk menggeneralisasikannya menjadi solusi dari soal utama. Kasus-kasus spesifik tersebut bisa dianggap sebagai penyederhanaan dari soal, yaitu kita dapat beralasan dengan prinsip berikut: "jika saya tidak tahu cara menyelesaikan soal yang kompleks, saya akan menyederhanakannya dan mencari solusi dari versi yang telah disederhanakan".

**Contoh populer dari penyederhanaan (kasus spesifik):**

- Anda mendapatkan soal tentang pohon (tree). Pertimbangkan variannya di mana pohon tersebut merosot menjadi sebuah lintasan (path);
    
- Soalnya melibatkan bobot (weights)? Pertimbangkan varian di mana semua bobotnya sama, baik satu atau sebuah bilangan tertentu, atau hanya ada dua bobot yang berbeda (dan seterusnya).
    

Perlu dicatat bahwa solusi dari suatu kasus spesifik hampir selalu tidak lebih mudah daripada solusi untuk kasus umumnya, jadi Anda perlu mencoba mencari solusi yang semudah dan seefektif mungkin.


## Teknik 3: “Hipotesis Berani”  
Jangan ragu untuk membuat hipotesis yang berani, selama menurutmu itu masuk akal. Kamu tidak harus membuktikan solusi secara formal saat kontes berlangsung — percayalah pada intuisi dalam dirimu. Setelah kamu punya hipotesis, coba buktikan. Bisa saja berhasil, atau justru memberimu ide bagaimana cara membantahnya. Ujilah hipotesismu pada berbagai jenis test case, karena sangat disayangkan jika kamu sudah menghabiskan waktu mengimplementasikan solusi berdasarkan hipotesis, dan baru setelah itu menyadari bahwa hipotesis tersebut salah.

**Contoh:**

- Solusi _selalu_ ada.
    
- Jumlah state-nya tidak terlalu banyak.
    


## Teknik 4: “Untuk menyelesaikan sebuah soal, kamu harus berpikir seperti soal itu sendiri”  
Saya serius. Posisikan dirimu sebagai karakter di dalam soal, bayangkan bahwa kamu yang harus menangani input-input tersebut. Pikirkan bagaimana kamu akan bertindak dalam situasi itu. Cobalah memproses beberapa contoh kecil secara manual. Kalau soalnya tentang permainan, mainkanlah. Kadang saya mencoba memvisualisasikan suatu proses atau membuat model untuk memahaminya lebih baik. Ini seperti bagaimana film-film menampilkan cara berpikir seorang ilmuwan. Cobalah berpikir dalam bentuk gambar, bayangkan solusi, lihat prosesnya terurai dalam pikiranmu.


## Teknik 5: “Pikirkan Bersama”  
Teknik ini hanya berlaku untuk kontes beregu. Dalam kelompok dua atau tiga orang, mulailah mengucapkan fakta-fakta sederhana tentang soal tersebut. Misalnya: _“Jika n genap, maka jawabannya selalu 0”_, atau _“Kalau n adalah bilangan prima, maka solusinya seharusnya begini”_, dan seterusnya. Kadang-kadang teman timmu akan menangkap ide itu dan mengembangkannya lebih jauh, dan strategi ini bisa membawa kalian menuju penyelesaian.


## Teknik 6: “Pilih Sebuah Metode”  
Cobalah untuk menelusuri kembali algoritma atau metode populer yang _mungkin_ dapat diterapkan pada soal tersebut. Melihat batasan (limit) dari soal bisa sangat membantu. Setelah memilih sebuah metode, cobalah berpikir seolah-olah soal tersebut memang akan diselesaikan dengan metode itu. Pola berpikirmu seharusnya kurang lebih seperti ini:  
_“Mari kita anggap soal ini diselesaikan dengan divide and conquer. Maka kita bisa menyelesaikannya secara rekursif untuk bagian kiri dan kanan. Sekarang yang tersisa adalah mencari cara untuk menggabungkan kedua solusi tersebut. Hmm... bagaimana cara kita melakukannya, ya?”_



## Teknik 7: “Cetak dan Perhatikan”  
Cukup sering (terutama untuk soal dengan input kecil: satu atau dua angka), ada pola tertentu dalam pembentukan jawabannya. Untuk melihat pola tersebut, kadang kamu perlu menuliskan solusi naif, lalu menghasilkan jawaban untuk sejumlah besar test case pada batas input yang tinggi, dan kemudian merenungkan jawabannya beberapa saat.

Agar komputer tidak terlalu sibuk, strategi yang baik adalah mencetak (print out) hasil yang sudah diperoleh dan merenungkannya lewat hasil cetakan itu.

Kadang-kadang, akan lebih berguna jika kamu tidak hanya mencetak jawabannya saja, tetapi juga informasi tambahan, seperti bagaimana jawaban tersebut diperoleh.



## Teknik 8: “Google”  
Teknik ini hanya bisa digunakan jika aturan kontes memperbolehkannya. Jika soalnya berkaitan dengan barisan (sequence), kamu bisa mencari pola jawabannya (lihat teknik 7) di situs seperti [https://oeis.org/](https://oeis.org/). Situs ini sangat membantu untuk memahami model formal dari soal dan menemukan istilah matematika yang tepat untuk dicari di Google.

