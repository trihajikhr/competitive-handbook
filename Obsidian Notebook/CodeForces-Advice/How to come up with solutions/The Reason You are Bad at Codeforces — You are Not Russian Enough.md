---
obsidianUIMode: preview
note_type: Advice
judul_materi: The Reason You are Bad at Codeforces — You are Not Russian Enough
sumber: codeforces
date_learned: 2025-06-08T19:21:00
tags:
  - advice
  - problem-solving
---
Link Sumber: [The Reason You are Bad at Codeforces — You are Not Russian Enough - Codeforces](https://codeforces.com/blog/entry/126310)

---
# The Reason You are Bad at Codeforces — You are Not Russian Enough

Jika Kamu Terpicu oleh Judul Blog Clickbait Ini...

...maka kemungkinan besar kamu memang ingin **meningkatkan kemampuanmu di Codeforces**.

Sekarang, saya akan membagikan sudut pandang saya mengenai **perbedaan antara kontes Codeforces dan ICPC**, serta **bagaimana, menurut saya, kamu bisa memaksimalkan peningkatan rating di Codeforces**.

### Tiga Pilar Utama Competitive Programming

Saya meyakini bahwa hampir semua soal kompetitif bisa diklasifikasikan berdasarkan tiga keterampilan utama:

1. **Observasi** — kemampuan untuk memahami soal dan menemukan sifat-sifat non-trivial (tidak langsung terlihat).
    
2. **Teknik** — kemampuan menerapkan algoritma atau struktur data yang sudah dikenal ke dalam masalah tersebut.
    
3. **Implementasi** — kemampuan menulis kode dengan cepat dan melakukan debug dengan efisien.
    

Secara informal, saya menyebut ketiga aspek ini sebagai:

- **Rusia-ness (ke-Rusia-an)** untuk Observasi,
    
- **China-ness (ke-Tiongkok-an)** untuk Teknik,
    
- **America-ness (ke-Amerika-an)** untuk Implementasi.
    

Nanti kamu akan tahu kenapa.

---

## Observasi (Ke-Rusia-an)

Observasi artinya kamu bisa menatap suatu soal cukup lama, lalu menyederhanakannya menjadi versi yang lebih mudah. Salah satu contoh soal yang menarik menurut saya adalah [1889D](https://codeforces.com/contest/1889/problem/D). Meskipun ratingnya 3000, soal itu bisa diselesaikan hanya dengan 30 baris kode yang sangat sederhana. Tentu saja, ada juga soal yang tidak bagus (misalnya [1916D](https://codeforces.com/contest/1916/problem/D) dan [1916H1](https://codeforces.com/contest/1916/problem/H1)), tapi intinya: **soal seperti ini membutuhkan pemikiran matematis yang kuat, dan hanya itu.**

Saya mengaitkan jenis kesulitan ini dengan “ke-Rusia-an” karena soal semacam ini sering muncul di kontes bergaya ICPC Rusia, khususnya **OpenCup** dan **ICPC Camp**. Selain itu, gaya soal ini juga sangat populer di **Codeforces** dan **AtCoder**.

Menariknya, karena keterampilan observasi ini sangat berkorelasi dengan kemampuan matematika murni (bukan keterampilan pemrograman), kamu sebenarnya [bisa latihan soal Olimpiade Matematika (IMO)](https://www.imo-official.org/problems/IMO2022SL.pdf) sebagai alternatif dari soal Codeforces. Sebagai contoh, **cobalah lihat soal kombinatorika dari IMO 2022**—kamu akan lihat bahwa banyak di antaranya sangat mirip dengan soal Div. 1 Codeforces.

> Ada pepatah yang bilang bahwa mahasiswa jurusan matematika punya keunggulan dibanding mahasiswa ilmu komputer di Codeforces — dan saya rasa itu memang benar, sampai batas tertentu.

---
## Teknik (Chinese-ness)  

**Teknik** adalah hal yang lebih umum kamu pelajari di hampir semua kursus competitive programming, seperti *binary exponentiation*, *segment tree*, dan sebagainya. Jelas, membedakan teknik dengan pengamatan murni itu tidak sepenuhnya mungkin, tapi aku membuat garis batas berdasarkan apakah sesuatu itu bisa dibuatkan kode referensi-nya. Jadi, *dynamic programming* dan *greedy* itu lebih ke gaya Russian, sementara *Fenwick tree* dan *segment tree* itu lebih ke gaya Chinese.

Sekarang aku menyebut masalah-masalah ini sebagai Chinese karena di kompetisi OI dan ICPC di China, cenderung muncul masalah yang cuma bisa diselesaikan dengan struktur data tingkat lanjut yang cuma bisa kamu kerjakan kalau kamu sudah punya kode referensi. Contohnya, soal [104857C](https://codeforces.com/gym/104857/problem/C) cuma bisa diselesaikan dengan *palindrome tree*, dan [104857A](https://codeforces.com/gym/104857/problem/A) cuma bisa kalau kamu sudah ikut semacam kursus pascasarjana.

Aku rasa ini bagian yang paling mudah dipelajari dari semuanya, dan yang paling banyak dikerjakan oleh para pembelajar competitive programming. Nah, sekarang kita dapat sedikit gambaran kenapa sangat susah bagi kita untuk naik level di Codeforces: kamu berusaha mati-matian jadi “Chinese” padahal yang sebenarnya perlu kamu kuasai adalah jadi “Russian”!

---
## Implementasi (American-ness)  
Implementasi biasanya merujuk pada masalah-masalah yang butuh banyak waktu untuk diimplementasikan, seperti soal geometri yang sangat populer di kontes-kontes AS, contohnya [104757C](https://codeforces.com/gym/104757/problem/C) dari ECNA terbaru. Aku biasanya membagi kesulitan implementasi menjadi dua tipe. Pertama, kode yang panjang tapi sebenarnya tidak terlalu rumit, seperti [Rubik’s cube](https://www.acmicpc.net/problem/6063) yang terkenal itu; kedua, kode yang terdiri dari banyak kasus dan susah untuk dibuat benar, seperti soal [104869I](https://codeforces.com/gym/104869/problem/I).

Sekarang aku menyebut masalah-masalah ini sebagai American karena soal geometri biasanya butuh kode referensi dan memang cukup populer di regional Amerika.

---
## Ringkasan  
Sekarang, di mana posisi Codeforces dalam semua ini? Saya akan membuat satu klaim berani: untuk Codeforces saat ini, Anda hanya perlu menguasai soal Leetcode level medium dan kontes matematika tingkat sekolah menengah untuk mencapai peringkat biru. Saya akan mencoba menjelaskan ini melalui dua klaim berikut.

***Klaim 1:*** *Anda hanya perlu menyelesaikan Div. 2 A, B, dan C dalam waktu satu jam untuk mencapai peringkat biru.*

Hal ini sangat jelas jika melihat kontes-kontes sebelumnya.

***Klaim 2:*** *Div. 2 A, B, dan C hanya membutuhkan keterampilan pemrograman dasar dan kemampuan matematika yang baik.*

Ini mungkin bisa diperdebatkan, tetapi saya percaya tidak ada satu pun soal di sana yang membutuhkan teknik khusus selain analisis matematika. Oleh karena itu, kemampuan matematika tingkat menengah dan sekolah menengah sudah cukup.

Sekarang kita dapat menjawab pertanyaan emas sepanjang masa:

> **Bagaimana cara meningkatkan kemampuan di Codeforces (untuk sekarang)?**

Banyak orang di Codeforces Catalog hanya akan menyarankan Anda untuk mengerjakan lebih banyak soal. Itu jelas benar, tapi saya jadi teringat lelucon menarik ini:

_“Mengapa belajar berenang? Langsung saja lompat ke sungai. Itu berhasil untuk semua orang yang bertahan hidup setelahnya!”_

Menurut saya, pada akhirnya, cara berpikir seperti ini justru membuat banyak orang keluar dari dunia competitive programming karena merasa tidak cukup pintar. Saya berharap tulisan ini meyakinkan Anda bahwa untuk orang di bawah Divisi 1, Codeforces tidak berhubungan dengan pemrograman, melainkan semuanya tentang matematika. Oleh karena itu, untuk belajar Codeforces, Anda sebaiknya tidak fokus pada pemrograman, melainkan belajar soal-soal matematika kontes!

> **Mengapa saya belum menjadi lebih baik di Codeforces setelah membaca cp-algorithms?**

Karena Codeforces untuk yang di bawah Divisi 1 sebenarnya tidak berhubungan dengan algoritma competitive programming. Lebih baik pelajari soal-soal matematika!

> **Apakah Codeforces seharusnya sangat 'Russian'?**

Tentu saja, saya bukan siapa-siapa untuk mencoba memahami desain luar biasa dari para grandmaster Rusia seperti 74TrAkToR. Namun, saya kira, secara umum, ketika ada soal dengan tingkat kesulitan “Chinese” yang tinggi, tanggapannya biasanya:

_“Soal ini terlalu standar (artinya: tidak cukup Russian). Ini soal yang bagus untuk educational round, tapi tidak untuk kontes reguler.”_

Sedangkan untuk gaya American, yah...

*Kapan terakhir kali Anda melihat soal geometri di kontes Codeforces?*

Bercanda, tentu saja. Saya sendiri tidak bisa memutuskan mana yang lebih penting dalam kontes competitive programming, tapi saya pikir komunitas perlu merenungkan perbedaan menarik antara Codeforces dan ICPC ini.

Baiklah, sebelum saya “diserang” oleh tiga negara terbesar di dunia, dibatalkan oleh para grandmaster terbaik di Codeforces, dan mendapatkan downvote tak berujung, saya rasa sudah saatnya saya mengakhiri. Saya akan menutup dengan kalimat ini:

_“Semoga ‘Russian-ness’ selalu menyertai Anda.”_
